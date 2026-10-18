from pathlib import Path
import json, hashlib, re, struct
root=Path(__file__).resolve().parent
dw=json.loads((root/'MineSweeperRush_32_debug.dwarf.json').read_text(encoding='utf-8'))
summary=json.loads((root/'restoration_summary.json').read_text(encoding='utf-8'))
index=json.loads((root/'source_index.json').read_text(encoding='utf-8'))
analysis=json.loads((root/'ida_analysis.json').read_text())
checks=[]
def checked(name, condition):
    assert condition,name
    checks.append(name)

b=(root.parent/dw['stats']['exe']).read_bytes()
checked('所选 EXE 的 SHA-256 未改变',hashlib.sha256(b).hexdigest()==summary['sha256'])
source_names=set(summary['files'])
game={f['address'] for f in dw['functions'] if f['source'] in source_names}
checked('395 个游戏源文件函数的地址覆盖完整',game=={f['address'] for f in index} and len(game)==395)
checked('664 个成功导出的函数均有归属',len(index)+summary['runtime_and_sdk_functions']==664)
for f in source_names:checked('源文件存在且含函数体：'+f,'{' in (root/'src'/f).read_text(encoding='utf-8-sig'))
layouts={t['name']:t for t in dw['types'] if t['source'] in {s.replace('.cpp','.h') for s in source_names} and t['name']}
board={m['name']:m for m in layouts['Board']['members']}
rule={m['name']:m for m in layouts['rule']['members']}
checked('约束坐标字段 blckx 的裸偏移换算成立',8+612*4==board['ruletemp']['offset']+rule['blckx']['offset'])
checked('约束坐标字段 blcky 的裸偏移换算成立',8+620*4==board['ruletemp']['offset']+rule['blcky']['offset'])
window={m['name']:m for m in layouts['Window']['members']}
lan={m['name']:m for m in layouts['Lan']['members']}
checked('入口函数栈槽误识别的标题字段偏移对应正确',window['pmenug']['offset']+8==lan['LAN_TITLE']['offset'])
checked('入口函数栈槽误识别的消息字段偏移对应正确',window['pmenug']['offset']+12==lan['LAN_RUNNING']['offset'])
old=next(r['code'] for r in analysis['functions'] if r['symbol']=='__ZN5Block6initblEv')
manual=(root/'src/block.cpp').read_text(encoding='utf-8-sig')
for field in ('mine','blck'):
    original={(int(v)//128,int(v)%128) for v in re.findall(r'\(\*this->'+field+r'\)\[(\d+)\] = 1;',old)}
    if '*(_BYTE *)this->'+field+' = 1;' in old:original.add((0,0))
    restored={(int(x),int(y)) for x,y in re.findall(field+r'\[(\d+)\]\[(\d+)\] = true;',manual)}
    checked('初始示例矩阵坐标与原始导出一致：'+field,original==restored)
checked('消行临时变量 mb 的 DWARF 类型为 bool',any(v['name']=='mb' and v['type']=='bool' for f in dw['functions'] if f['name']=='delline' for v in f['locals']))
raw_delline=next(r for r in analysis['functions'] if r['symbol']=='__ZN5Board7dellineEl')
checked('mb 的字节读写有汇编支撑',any(x['address']==0x40463a and x['text'].endswith(', al') for x in raw_delline['assembly']) and any(x['address']==0x404687 and 'movzx' in x['text'] for x in raw_delline['assembly']))

# Verify recovered pointer tables against the original PE, independently of IDA display strings.
pe=struct.unpack_from('<I',b,60)[0]
imagebase=struct.unpack_from('<I',b,pe+24+28)[0]
table=pe+24+struct.unpack_from('<H',b,pe+20)[0]
sections=[]
for i in range(struct.unpack_from('<H',b,pe+6)[0]):
    vs,va,size,pos=struct.unpack_from('<IIII',b,table+i*40+8)
    sections.append((va,max(vs,size),pos))
def offset(address):
    rva=address-imagebase
    for va,size,pos in sections:
        if va<=rva<va+size:return pos+rva-va
    raise AssertionError(hex(address))
for r in json.loads((root/'data_symbols.json').read_text()):
    if 'string_table' not in r:continue
    raw=bytes.fromhex(r['hex'])
    pos=offset(r['address'])
    checked('常量表原始字节一致：'+r['name'],b[pos:pos+len(raw)]==raw)
    strings=[]
    for j in range(0,len(raw),4):
        p=offset(struct.unpack_from('<I',raw,j)[0])
        strings.append(b[p:b.index(0,p)].decode('utf-8'))
    checked('常量表字符串逐项一致：'+r['name'],strings==r['string_table'])

report={'passed':len(checks),'checks':checks,'scope':'静态证据、结构与整理覆盖检查；没有执行游戏，也未验证完整源码编译或运行等价性。'}
(root/'verification.json').write_text(json.dumps(report,ensure_ascii=False,indent=2),encoding='utf-8')
print(json.dumps(report,ensure_ascii=False,indent=2))
