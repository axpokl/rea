from pathlib import Path
import re, json, hashlib, collections

root = Path(__file__).resolve().parent
names = ['MineSweeperRush', 'MineSweeperRush_32_debug', 'MineSweeperRush_32_debug2']
summaries = []
notes = {
 'calcnumb': '遍历棋盘，清零每格的 numb，再检查 8 个相邻方向，统计 mine 为真的邻格数量。',
 'isok': '按方向选择相邻坐标并检查边界；输出坐标通过引用或指针返回。',
 'solveblank': '在有效且未暂停的游戏状态中，正反两次扫描棋盘并点击未揭开的无雷零数字格；从第 2 行开始。',
 'solveblank_': '反复调用空白格处理；循环条件由 solvebb 状态决定。',
 'createrule': '从已揭开格的周围格构造约束：数字减去已标旗/已确认雷数，记录尚未确定的相邻坐标。',
 'initbl': '初始化 Block 的棋盘存储与状态；具体布局以恢复类型和函数体为准。',
 'initbd': '初始化棋盘；存在多个重载，参数和初始化细节见下方函数体。',
 'randmine': '函数名指向随机布雷；随机调用和排除条件以函数体为准。',
}
api_notes = {
 'RegOpenKey': '访问 Windows 注册表', 'RegSetValue': '写入注册表值',
 'RegQueryValue': '读取注册表值', 'SetupIterateCabinet': '遍历 CAB 压缩包成员',
 'mciSendString': '调用 Windows MCI 音频/音乐接口', 'Steam': '调用或处理 Steam 相关接口',
 'BitBlt': '复制绘图位图区域', 'Gdip': '调用 GDI+ 图形接口',
 'CreateWindow': '创建窗口', 'GetMessage': '处理窗口消息循环',
 'fopen': '打开文件', 'fread': '读取文件内容', 'fwrite': '写入文件内容',
}
for name in names:
 raw = (root / (name + '.cpp')).read_text(encoding='utf-8', errors='replace')
 parts = re.split(r'(?=^// Address:)', raw, flags=re.M)[1:]
 dest = root / name
 dest.mkdir(exist_ok=True)
 groups = collections.defaultdict(list)
 index = []
 for part in parts:
  lines = part.splitlines()
  anchor = re.match(r'// Address: (\S+); symbol: (.*)', lines[0])
  addr, symbol = anchor.groups()
  signature = lines[1]
  cls = re.search(r'\b(\w+)::(~?\w+)', signature)
  if cls:
   module = cls.group(1).lower()
   method = cls.group(2)
  else:
   method = symbol.lstrip('_')
   module = 'other'
   if re.search(r'steam|achievement', signature, re.I): module='steam'
   elif re.search(r'cab|extract', signature, re.I): module='cab'
   elif re.search(r'reg|save|load', signature, re.I): module='reg_and_storage'
   elif re.search(r'sound|music|mci', signature, re.I): module='sound'
   elif re.search(r'lang|lan\b', signature, re.I): module='lan'
   elif re.search(r'window|winmain|wndproc', signature, re.I): module='window'
   elif re.search(r'CRT|mingw|gcc|atexit|ExceptionFilter|^sub_', signature): module='runtime_and_unknown'
  comment = ['// 阅读说明：' + notes.get(method, '函数身份来自下方地址和符号；保留反编译器恢复的函数体。')]
  observed = [v for k,v in api_notes.items() if k in part]
  if observed: comment.append('// 函数体可见调用：' + '；'.join(observed) + '。')
  if '__user' in part or ('// ecx' in part and '::' in signature):
   comment.append('// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。')
  groups[module].append('\n'.join(comment) + '\n' + part)
  index.append({'address':addr, 'symbol':symbol, 'signature':signature, 'module':module+'.cpp'})
 header = '// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。\n// 源二进制：' + name + '.exe\n// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。\n// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。\n// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。\n\n'
 for module, items in groups.items():
  (dest/(module+'.cpp')).write_text(header+'\n'.join(items),encoding='utf-8-sig')
 (dest/'all_annotated.cpp').write_text(header+'\n'.join(item for items in groups.values() for item in items),encoding='utf-8-sig')
 (dest/'functions.json').write_text(json.dumps(index,ensure_ascii=False,indent=2),encoding='utf-8')
 status=json.loads((root/(name+'.status.json')).read_text())
 digest=hashlib.sha256((root.parent/(name+'.exe')).read_bytes()).hexdigest()
 summaries.append({'name':name,'sha256':digest,'functions_exported':len(parts),'failed':status['failed'],'modules':{k:len(v) for k,v in groups.items()}})
 assert len(parts)==status['decompiled']
 assert sum(len(v) for v in groups.values())==len(parts)
for n in names:
 ev=json.loads((root/(n+'.rea-resources.json')).read_text(encoding='utf-8-sig'))
 assert ev, 'REA evidence is empty'
(root/'coverage.json').write_text(json.dumps(summaries,ensure_ascii=False,indent=2),encoding='utf-8')
print(json.dumps(summaries,ensure_ascii=False,indent=2))
