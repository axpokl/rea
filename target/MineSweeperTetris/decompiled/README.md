# MineSweeper Rush 可读反编译代码

这里提供实际包含函数体的 C/C++ 风格伪代码，取代此前只有符号注释的重建索引。保留源 EXE；没有执行游戏。

## 从哪里开始阅读

- `readable_core.cpp`：三个核心算法的人工整理版，含中文逐段说明。参数整理属于推断，未做运行对照。
- `MineSweeperRush_32_debug2/block.cpp`：Block 的 4 个方法，包括邻格检查和数字计算。
- `MineSweeperRush_32_debug2/board.cpp`：Board 的 40 个方法，包括布雷、空白格展开、约束生成、求解、加行和消行。
- 各版本目录中的 `all_annotated.cpp`：完整的带中文说明的导出合集。
- `*.types.h`：IDA 从调试信息和类型库导出的结构布局，包含 Block、Board 等。保留 IDA 表示法，并非可直接使用的头文件。
- `functions.json`：函数地址、符号、签名和模块文件的索引。
- 顶层三个与 EXE 同名的 `.cpp`：未经人工语义修改的原始 Hex-Rays 导出，便于核查。

按类或可见调用分组不保证等于原始文件边界。Steam/GDI+/C++ 运行库等代码也在导出范围内；函数总数不是游戏功能数量。

## 三个 EXE 的结果

| 输入 | 成功导出函数体 | 无伪代码的识别函数 |
|---|---:|---:|
| MineSweeperRush.exe | 331 | 7 |
| MineSweeperRush_32_debug.exe | 664 | 2 |
| MineSweeperRush_32_debug2.exe | 648 | 2 |

Debug 两个失败项都是 `_sprintf`、`_wsprintfA` 的导入跳板；本体在外部 DLL 中，不在 EXE 中。其跳转汇编已保存在 `*.failed_functions.asm`。
发布版失败项包含较大的本地函数，不能声称发布版所有函数已恢复。保留完整函数汇编作为补充。各地址与原因列在 `*.status.json` 和 `coverage.json`。

## 工具与证据

实际代码函数体来自现有 IDA 7.0 / Hex-Rays 插件，显式加载 `hexrays.dll` 后导出。此前“没有可用插件”的结论已修正。
REA 6.4.0 CLI 已安装在 `G:\Program Files\REA\tools\rea-cli`；实际对三个 EXE 执行了 `inspect-pe-resources`，其完整 Evidence 保存为 `*.rea-resources.json`，包含 SHA-256、资源树和 Evidence ID。
这些 REA Evidence 证明的是静态资源检查，不证明伪代码语义或运行等价性。函数体的来源是上述 IDA 原始导出和函数地址。
REA `providers` 输出保存在 `rea-providers.json`。Ghidra 和 JDK 官方下载多次超时，未安装成功；没有宣称通过 REA 的 Ghidra 后端进行了反编译。

## 如何理解伪代码

- `v1/v2` 等是反编译器临时名；源程序变量名并非全部保留。
- `_DWORD` 表示 32 位值，`_BYTE` 表示字节；`qmemcpy` 是反编译器对内存复制的表达。
- `__usercall` / `@<ecx>` 是寄存器调用约定注记，不是标准 C++ 语法。
- 旧版 IDA 对部分 MinGW C++ 成员函数的 `this` 和参数发生错位，可能出现看似未初始化的 ECX 别名、错位实参。
- 已试验修正类型调用约定，但输出仍有上述问题；`*.corrected.cpp` 属于诊断试验，阅读应以原始导出、带注释模块和 `readable_core.cpp` 为准。
- 注释中对函数名的解释是静态分析；没有通过执行证明算法、存档或 Steam 行为。

没有把缺失函数编造成源码，没有验证这些文件能够直接编译，也不保证它们与原作者文本相同。现在的交付是带实际函数体和注释的反编译阅读材料。

## 验证

三份输入 SHA-256 固定在 `coverage.json`。整理脚本验证每个版本分组数量与导出成功数量一致，并验证三个 REA Evidence 文件均能解析为 JSON。
原始导出、分模块导出、失败函数汇编和恢复类型均保留在当前目录，方便后续针对一个算法逐行修正。
