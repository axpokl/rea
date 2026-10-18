from pathlib import Path
import re, json, collections, hashlib

ROOT=Path(__file__).resolve().parent
SRC=ROOT/'src'; SRC.mkdir(exist_ok=True)
INC=ROOT/'include'; INC.mkdir(exist_ok=True)
dw=json.loads((ROOT/'MineSweeperRush_32_debug.dwarf.json').read_text(encoding='utf-8'))
ida=json.loads((ROOT/'ida_analysis.json').read_text())
by_addr={f['address']:f for f in dw['functions']}
user_files={'block.cpp','board.cpp','cab.cpp','disp.cpp','lan.cpp','reg.cpp','sound.cpp','steam.cpp','window.cpp','main.cpp'}
game_headers={s.replace('.cpp','.h') for s in user_files}
classes={'Block','Board','Window','Steam','Sound','Lan','Reg'}

descriptions={
 'calcnumb':'逐格清零 numb，并按 8 个相邻方向统计雷数。i/j 是列/行，k 是方向。',
 'isok':'按方向 k 输出相邻坐标；根据 w/h 检查是否越界。返回值表示该邻格有效。',
 'solveblank':'清除本轮求解标记，正反两次扫描 y>=2 的行，尝试点击未遮罩、非雷且数字为零的格。',
 'solveblank_':'在 solvebb 为真时重复展开零数字格，直到状态不再要求继续。',
 'solve0':'正反扫描已揭开的零数字格，通过 clicknumb 扩展周边；保留原始 sit<=3 条件。',
 'solve0_':'按 solveb0 控制重复执行 solve0，是否结束取决于内部点击更新的状态。',
 'solve1':'正反扫描已揭开且数字非负的格，调用 clicknumb，最后播放求解音效。',
 'solve1_':'按 solveb1 控制重复执行一级求解；具体进展标记由点击逻辑更新。',
 'createrule':'将数字格周围的未知格整理为约束，扣减已标旗或已推断雷的数量，保存坐标与剩余雷数。',
 'comparerule':'比较两个约束或遍历比较所有约束；用共有/独有邻格关系更新推断结果。',
 'applyrule':'将 leftrule/rightrule 转换为可点击/可标记的位置，更新各级求解标记与 solven；applyb 决定是否执行点击。',
 'solve2':'组合约束的建立、比较和应用；bool 参数版本与无参数包装分别保留。',
 'solve2_':'按求解进展反复处理约束；保留参数区分是否实际应用。',
 'solve3_':'更高层求解控制入口；具体与其他级别的顺序关系见函数体。',
 'checkline':'从底行向上计数未揭开格与旗子，满足 n 时消行；可绘制消行动画并延时，再调用求解。',
 'delline':'将被删行上方的雷、遮罩、旗子、规则和数字向下搬移，生成顶行并更新分数、Steam 记录和等级。',
 'randmine':'根据随机数生成雷分布；保留首次点击位置和边界相关判断。',
 'tutmine':'设置教程用雷分布；坐标与状态写入可在下方查看。',
 'resetbd':'按点击坐标重建/重置棋盘状态，重新计算邻雷数并重置计时。',
 'initbl':'初始化基础棋盘成员和各矩阵缓冲区。数组每列容量由恢复类型确定为 128。',
 'initbd':'初始化或切换棋盘配置。此函数有多个重载，具体参数见声明。',
 'clicknumb':'处理数字格邻域的点击/标记规则，是各级求解器调用的基础操作。',
 'clickleft':'处理左键操作；包含状态、坐标、标记和展开逻辑。',
 'clickright':'处理右键操作；与旗子/问号以及状态更新相关。',
 'setflag':'修改旗子状态及相关统计；具体置位/撤销条件见分支。',
 'setqstn':'修改问号标记，含带坐标与不带坐标的重载。',
 'setblock':'更新格子的揭开/处理状态，并维护游戏状态和相关计数。',
 'checkdie':'检查棋盘失败条件；具体 sit 数值的含义仍以实际赋值和调用为准。',
 'checkerror':'检查单格或全盘的标记/规则一致性。',
 'addline':'新增棋盘行，带 bool 参数与无参数的包装分别保留。',
 'addmask':'修改遮罩相关状态和棋盘处理范围。',
 'pause':'切换暂停状态，并调整计时与界面相关状态。',
 'keyevent':'键盘事件分派；下面的 switch/条件保留原按键值。',
 'mouseevent':'鼠标事件分派；根据按钮、坐标和当前界面状态执行操作。',
 'doaction':'动作编号分派；数字动作编号没有擅自替换成未经验证的枚举。',
 'painthelp':'绘制帮助界面文本和示例；文本常量保留在代码中。',
 'saveboard':'保存本地棋盘状态；文件结构仍按原始写入顺序表达。',
 'loadboard':'读取本地棋盘状态并更新内存结构。',
 'saveboardcloud':'将棋盘状态保存至 Steam 云相关存储。',
 'loadboardcloud':'读取 Steam 云相关棋盘存储。',
 'savesetting':'写入本地配置；具体字段与字节长度见代码。',
 'loadsetting':'读取本地配置；保留原有默认值和读取失败处理。',
 'CheckAndProcessCabFile':'检查并处理资源 CAB；原代码可能提取文件或删除旧目录，当前仅静态分析，未执行此函数。',
 'DeleteFolderRecursively':'原程序的递归删除函数；这里只导出文本，没有执行删除。',
 'CabExtractCallback':'CAB 解包通知回调，根据 notification 返回成员处理结果。',
 'initsteam':'初始化 Steam 状态；调用顺序和失败条件保留。',
 'loadsteam':'加载或刷新 Steam 相关数据。',
 'loadach':'读取成就信息。', 'addach':'提交/更新成就。',
 'loadlead':'读取排行榜状态。', 'setlead':'设置/提交排行榜相关数据。',
 'getlead':'获取排行榜数据或处理回调。',
 'loadscr':'读取 Steam 统计值。', 'setscr':'设置统计值。',
 'compscr':'比较当前数值与已有记录，按条件更新统计。',
 'addscr':'累加 Steam 统计值。', 'checkcheat':'更新作弊相关状态；不推断具体触发条件之外的行为。',
 'loadsound':'加载音效资源。', 'loadmusic':'加载背景音乐资源。',
 'playsound':'播放指定音效。', 'playmusic':'播放背景音乐。',
 'switchmusic':'切换音乐开关。', 'switchsound':'切换音效开关。',
 'checkmusic':'检查音乐播放状态和切换条件。',
 'openreg':'打开 Windows 注册表键。', 'closereg':'关闭注册表句柄。',
 'setreg':'写注册表配置；具体值类型由下方调用决定。', 'getreg':'读取注册表配置。',
 'getsyslan':'根据系统语言选择语言标识。', 'initlan':'初始化语言资源与文本表。',
 'getlan':'获取界面文本或语言资源。',
}
api_notes={'RegSetValue':'写入注册表','RegQueryValue':'读取注册表','SetupIterateCabinet':'遍历 CAB 成员','mciSendString':'调用 MCI 音频接口','BitBlt':'位图复制','Gdip':'GDI+ 绘图','fopen':'打开文件','fwrite':'写文件','fread':'读文件','CreateWindow':'创建窗口','GetMessage':'消息循环','rand(':'使用伪随机数'}

def split_args(s):
    # Parenthesis/bracket nesting and string/comment handling for call arguments.
    level=0; quote=None; start=0; out=[]; i=0
    while i<len(s):
        ch=s[i]
        if quote:
            if ch=='\\': i+=2; continue
            if ch==quote: quote=None
        elif ch in '\"\'': quote=ch
        elif ch in '([{': level+=1
        elif ch in ')]}': level-=1
        elif ch==',' and level==0: out.append(s[start:i].strip());start=i+1
        i+=1
    out.append(s[start:].strip())
    return out if out!=[''] else []

def call_end(s,start):
    depth=1; quote=None; i=start
    while i<len(s):
        ch=s[i]
        if quote:
            if ch=='\\': i+=2;continue
            if ch==quote:quote=None
        elif ch in '\"\'':quote=ch
        elif ch=='(':depth+=1
        elif ch==')':
            depth-=1
            if depth==0:return i
        i+=1

member_methods=set()
for row in ida['functions']:
    code=row.get('code','')
    m=re.search(r'\b(\w+)::(\w+)\(',code.split('{')[0])
    if m and '__thiscall' in code.split('{')[0]: member_methods.add(m.groups())

def member_calls(body):
    pattern=re.compile(r'\b(\w+)::(\w+)\(')
    pos=0; changed=0
    while True:
        m=pattern.search(body,pos)
        if not m:break
        cls,method=m.groups(); end=call_end(body,m.end())
        if end is None:break
        if (cls,method) not in member_methods or cls==method:
            pos=m.end();continue
        args=split_args(body[m.end():end])
        if not args:pos=end+1;continue
        if (cls,method)==('Block','isok') and len(args)==6:
            # DWARF and Itanium name ...RlS0_ both identify long& outputs.
            args[4]=args[4].lstrip('&')
            args[5]=args[5].lstrip('&')
        obj=args[0]
        if obj.startswith('&') and re.fullmatch(r'[A-Za-z_]\w*(?:(?:->|\.)[A-Za-z_]\w*)*',obj[1:]):
            replacement=obj[1:]+'.'+method+'('+', '.join(args[1:])+')'
            body=body[:m.start()]+replacement+body[end+1:]
            pos=m.start()+len(obj)+len(method)+1;changed+=1;continue
        if obj=='this': receiver='this'
        elif re.fullmatch(r'[A-Za-z_]\w*',obj): receiver=obj
        else: receiver='('+obj+')'
        replacement=receiver+'->'+method+'('+', '.join(args[1:])+')'
        body=body[:m.start()]+replacement+body[end+1:]
        pos=m.start()+len(receiver)+2+len(method)+1; changed+=1
    return body,changed

groups=collections.defaultdict(list); declarations=collections.defaultdict(list); index=[]; residual=[]
for row in ida['functions']:
    code=row.get('code')
    if not code:continue
    meta=by_addr.get(row['address'])
    if not meta or meta['source'] not in user_files:
        residual.append('// 0x%08X %s\n%s\n'%(row['address'],row['symbol'],code));continue
    brace=code.index('{'); pre=code[:brace].strip(); body=code[brace:]
    prelines=pre.splitlines(); signature=prelines[-1]; warnings=prelines[:-1]
    match=re.search(r'\b(\w+)::(~?\w+)\(',signature)
    cls,method=match.groups() if match else (None,meta['name'])
    if cls in classes:
        signature=re.sub(r'\b__thiscall\s+','',signature)
        signature=re.sub(r'\('+cls+r'\s*\*const this\s*,\s*','(',signature)
        signature=re.sub(r'\('+cls+r'\s*\*const this\s*\)','()',signature)
        if method in (cls,'~'+cls): signature=re.sub(r'^void\s+','',signature)
    if (cls,method)==('Block','isok'):
        signature='bool Block::isok(long int k, long int x, long int y, long int &tx, long int &ty)'
        body=re.sub(r'\*\b(tx|ty)\b',r'\1',body)
    # Eliminate only the exact redundant this alias produced by Hex-Rays.
    if re.search(r'\bthisa = this;',body):
        body=re.sub(r'^\s*'+(cls or r'\w+')+r'\s*\*thisa;[^\n]*\n','\n',body,flags=re.M)
        body=re.sub(r'^\s*thisa = this;\s*\n','\n',body,flags=re.M)
        body=re.sub(r'\bthisa\b','this',body)
    if cls in classes:
        for alias in re.findall(r'\b(v\d+) = this;',body):
            if len(re.findall(r'\b'+alias+r'\s*=(?!=)',body))==1:
                body=re.sub(r'^\s*'+cls+r'\s*\*'+alias+r';[^\n]*\n','\n',body,flags=re.M)
                body=re.sub(r'^\s*'+alias+r' = this;\s*\n','\n',body,flags=re.M)
                body=re.sub(r'\b'+alias+r'\b','this',body)
    # Board inherits Block at byte zero in the recovered layout.
    base_fixes=0
    if cls=='Board':
        base_fixes=body.count('&this->0')
        body=body.replace('&this->0','static_cast<Block *>(this)')
        # n is at 8; ruletemp at 2440; blckx/blcky at 16/48 within rule.
        # Thus 8+612*4=2456 and 8+620*4=2488 are actual recovered fields.
        body=body.replace('*(&this->n + this->ruletemp.blckc + 612)','this->ruletemp.blckx[this->ruletemp.blckc]')
        body=body.replace('*(&this->n + this->ruletemp.blckc++ + 620)','this->ruletemp.blcky[this->ruletemp.blckc++]')
        body=body.replace('qmemcpy(&this->rulemain[this->rulemainc++], &this->ruletemp, sizeof(this->rulemain[this->rulemainc++]));','this->rulemain[this->rulemainc++] = this->ruletemp;')
        for rn in ('rule1','rule2'):
            body=re.sub(r'qmemcpy\(&'+rn+r', &(this->rulemain\[\w+\]), sizeof\('+rn+r'\)\);',rn+r' = \1;',body)
        if method=='delline':
            # DWARF says bool; 0x40463A stores AL and 0x404687 zero-extends a byte.
            body=re.sub(r'int mb;[^\n]*', 'bool mb; // 已按 DWARF 与字节访存汇编修复原导出的错误 int 类型。', body)
    if cls in ('Block','Board'):
        def matrix_offset(m):
            return 'this->'+m.group(1)+'['+str(int(m.group(2))//128)+']['+str(int(m.group(2))%128)+']'
        body=re.sub(r'\(\*this->(mine|blck|flag|mask|qstn|leftrule|rightrule)\)\[(\d+)\]',matrix_offset,body)
        body=re.sub(r'\*\(_BYTE \*\)this->(mine|blck|flag|mask|qstn|leftrule|rightrule)\b',r'this->\1[0][0]',body)
    body,call_changes=member_calls(body)
    body=re.sub(r'\s*// (?:\[esp[^\n]*|(?:e[abcd]x|e[sd]i|[abcd][lh]|ST\w+)(?:;[^\n]*)?)\n','\n',body)
    body=re.sub(r'\bthis->(w|h) > (\w+)\b',r'\2 < this->\1',body)
    original_args=', '.join(p['declaration'] for p in meta['parameters'] if not p['artificial'])
    comment=['// 原始位置：%s:%s；地址：0x%08X'%(meta['source'],meta['line'] or '?',row['address']),
             '// 调试记录声明：%s %s(%s)'%(meta['return_type'],meta['name'],original_args)]
    desc=descriptions.get(method)
    if not desc and method and method.startswith('paint'):desc='界面绘制函数；具体绘制对象、颜色和坐标见下方调用。'
    if not desc and cls==method:desc='构造函数：初始化成员及所拥有的子对象。'
    if not desc and method and method.startswith('~'):desc='析构函数：释放该对象拥有的资源。'
    if not desc:desc='保留恢复的函数名、分支和调用；具体逻辑见函数体。'
    comment.append('// 功能说明：'+desc)
    calls=[v for k,v in api_notes.items() if k in body]
    if calls:comment.append('// 可见操作：'+'、'.join(calls)+'。')
    if meta['locals']:
        comment.append('// 原始局部变量：'+'；'.join(x['declaration'] for x in meta['locals'])+'。')
    if warnings:comment.append('// 反编译器警告：'+' '.join(warnings))
    unresolved=[]
    if '__user' in signature or '@<' in signature:unresolved.append('非标准寄存器调用约定')
    if re.search(r'->\d',body):unresolved.append('未命名的结构子对象')
    if 'OVERLAPPED' in code or 'allocation has failed' in code:unresolved.append('局部变量分配/重叠警告')
    if unresolved:comment.append('// 待核对：'+'；'.join(unresolved)+'。')
    text='\n'.join(comment)+'\n'+signature+'\n'+body+'\n'
    groups[meta['source']].append((meta['line'] or 100000,row['address'],text))
    if cls in classes:
        declarations[cls].append(signature.replace(cls+'::','',1)+';')
    index.append({'address':row['address'],'symbol':row['symbol'],'source':meta['source'],'original_line':meta['line'],'signature':signature,'member_calls_rewritten':call_changes,'base_casts_repaired':base_fixes,'warnings':unresolved})

module_notes={'block.cpp':'基础棋盘矩阵、八邻域与邻雷统计','board.cpp':'棋盘规则、布雷、求解、标记、加行和消行','cab.cpp':'资源 CAB 文件及目录处理','disp.cpp':'Win32/GDI+ 绘图、窗口、音频与编码辅助','lan.cpp':'多语言文本加载','reg.cpp':'Windows 注册表配置','sound.cpp':'音效和音乐管理','steam.cpp':'Steam 初始化、成就、统计和排行榜','window.cpp':'游戏窗口、输入、绘制、配置和存档','main.cpp':'程序入口'}
for filename,items in groups.items():
    items.sort()
    intro='// '+module_notes[filename]+'\n// 基于所选 Debug EXE 的静态反编译，按 DWARF 源文件归属恢复。\n// 这是供阅读的源码式伪代码；并非已验证可编译的源码。\n#include "../include/recovered_types.hpp"\n\n'
    (SRC/filename).write_text(intro+'\n'.join(x[2] for x in items),encoding='utf-8-sig')
    manual=ROOT/'manual'/filename
    if manual.exists():
        (SRC/(filename.replace('.cpp','.machine.cpp'))).write_text(intro+'\n'.join(x[2] for x in items),encoding='utf-8-sig')
        (SRC/filename).write_text(manual.read_text(encoding='utf-8'),encoding='utf-8-sig')
(ROOT/'runtime_and_sdk.cpp').write_text('// 编译器运行库、SDK 内联函数及无源文件归属的导出。\n'+'\n'.join(residual),encoding='utf-8-sig')

# Rebuild data layout and a method index using only actual recovered records.
selected={}
for t in dw['types']:
    if t['source'] in game_headers and t['name']:
        selected.setdefault(t['name'],t)
def struct_text(t,nested=False):
    n=t['name'];base=' : '+', '.join('public '+b for b in t['bases']) if t['bases'] else ''
    lines=['// DWARF：%s；对象大小 %s 字节。'%(t['source'],t['size']),'struct '+n+base+' {']
    if n=='Board' and 'rule' in selected:
        lines.extend('    '+line for line in struct_text(selected['rule'],True).splitlines())
    for m in t['members']:
        offset=m['offset']
        if isinstance(offset,list):offset='位置表达式 '+str(offset)
        decl=m['declaration'].replace('const const ','const ')
        if m.get('external') and offset is None:
            decl='static '+decl
            if m.get('constant') is not None:decl+=' = '+str(m['constant'])
            lines.append('    '+decl+'; // 静态成员，不占用对象布局；原行 '+str(m['line']))
        else:
            lines.append('    '+decl+'; // 对象内偏移 '+str(offset)+'；原头文件行 '+str(m['line']))
    for decl in dict.fromkeys(declarations[n]):lines.append('    '+decl)
    lines.append('};')
    return '\n'.join(lines)
header=['#pragma once','// 依据 DWARF 恢复的数据布局和方法声明。Windows x86 ABI：long/int/指针均为 4 字节。',
        '// 外部 Steam/GDI+ 类型仍需相应 SDK；本文件用于阅读，未作为完整编译环境验证。',
        '#include <windows.h>','#include <cstdint>','']
for name in classes:header.append('struct '+name+';')
for name in ('Block','Lan','Reg','Sound','Steam','Board','Window'):
    if name in selected:header.append('\n'+struct_text(selected[name]))
(INC/'recovered_types.hpp').write_text('\n'.join(header),encoding='utf-8-sig')
glob=[];seen=set()
for g in dw['globals']:
    if g['source'] not in user_files|game_headers or not g['name']:continue
    key=(g['name'],g['declaration'])
    if key in seen:continue
    seen.add(key)
    glob.append('// %s:%s\nextern %s; // 初始化值需从二进制数据或初始化函数核对。'%(g['source'],g['line'],g['declaration']))
(INC/'globals.hpp').write_text('#pragma once\n// 全局变量身份来自 DWARF；extern 表示声明，不伪造缺失初值。\n'+'\n'.join(glob),encoding='utf-8-sig')

data_path=ROOT/'data_symbols.json'
if data_path.exists():
    data=json.loads(data_path.read_text())
    lines=['#pragma once','#include <cstdint>','// 静态数据补充：原符号名用于与伪代码交叉定位。只读的解释候选，非完整链接单元。']
    for r in data:
        lines.append('\n// 0x%08X；%s 字节；读取边界：%s。'%(r['address'],r['size'],r['span_basis']))
        if 'string_table' in r:
            lines.append('static const char *const '+r['name']+'[] = {')
            lines.extend('    '+json.dumps(s,ensure_ascii=True)+',' for s in r['string_table'])
            lines.append('};')
        elif r.get('string') and r['name'].startswith('unk_'):
            lines.append('static const char '+r['name']+'[] = '+json.dumps(r['string'],ensure_ascii=True)+';')
        else:
            b=bytes.fromhex(r['hex'])
            lines.append('alignas(4) static const std::uint8_t '+r['name']+'[] = {')
            for j in range(0,len(b),16):lines.append('    '+', '.join('0x%02X'%v for v in b[j:j+16])+',')
            lines.append('};')
    (INC/'data_symbols.hpp').write_text('\n'.join(lines),encoding='utf-8-sig')

stats={'selected':dw['stats']['exe'],'sha256':dw['stats']['sha256'],'thiscall_fixes':len(ida['calling_convention_changes']),'all_success':sum('code' in r for r in ida['functions']),'game_source_functions':len(index),'files':{k:len(v) for k,v in groups.items()},'runtime_and_sdk_functions':len(residual),'failed':ida['failed'],'data_layouts':len(selected),'globals':len(seen),'warning_functions':[r for r in index if r['warnings']]}
(ROOT/'source_index.json').write_text(json.dumps(index,ensure_ascii=False,indent=2),encoding='utf-8')
(ROOT/'restoration_summary.json').write_text(json.dumps(stats,ensure_ascii=False,indent=2),encoding='utf-8')
assert len(index)+len(residual)==stats['all_success']
assert user_files==set(groups),set(groups)
print(json.dumps(stats,ensure_ascii=False,indent=2))
