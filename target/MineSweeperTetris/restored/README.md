# MineSweeper Rush：进一步恢复的可读代码

本轮选择 **MineSweeperRush_32_debug.exe**。两个 Debug 文件都具有 432 个带地址的 DWARF 函数记录和 357 个局部变量记录，第一份调试节共 5,738,009 字节，第二份为 5,737,841 字节，第一份略多。发布版没有 DWARF。比较细节保存在 `debug_comparison.json`；并非仅凭 EXE 大小选择。

## 直接看代码

`src/` 按调试信息里的原始源文件归属恢复了 10 个文件、395 个函数：

| 文件 | 内容 | 函数数 |
|---|---|---:|
| main.cpp | 入口、单实例提示、主循环 | 1 |
| block.cpp | 基础棋盘、八邻域、数字计算 | 4 |
| board.cpp | 布雷、求解、旗子/问号、加行、消行 | 40 |
| cab.cpp | 资源 CAB 和目录处理 | 6 |
| disp.cpp | Win32/GDI+、绘图、窗口、编码与音频辅助 | 234 |
| lan.cpp | 多语言 | 4 |
| reg.cpp | 注册表 | 8 |
| sound.cpp | 音效与音乐 | 9 |
| steam.cpp | 成就、统计、排行榜 | 26 |
| window.cpp | 绘制、输入、配置、存档、动作分派 | 63 |

建议阅读顺序：`main.cpp` → `block.cpp` → `board.cpp` → `window.cpp`。文件中的原始行号属于编译时源码，不是本次输出的行号。

`include/recovered_types.hpp` 恢复了 7 个主要类及 Board::rule 的成员名、数组形状、静态常量、继承关系、对象内偏移和方法声明。`globals.hpp` 提供 154 个去重后的全局声明，未知初始值不作编造。`data_symbols.hpp` 另外恢复了原始数据表，包含 30 个语言标识、26 个 Steam 成就名、19 个统计名，以及按键提示等。

## 相比上一版的实质改进

1. 汇编确认 this 位于 ECX，修正了 184 个成员函数的调用约定。旧版 DWARF 导入器会在自动分析期间覆盖修正，因此在 Hex-Rays 初始化之后统一应用类型，再导出。
2. 去掉冗余 this 别名，恢复常见的 `对象.方法()`、`指针->方法()` 调用形式，保留参数先后顺序。
3. 根据实际 DWARF 文件/行号归属拆分，不再仅凭类名或字符串猜文件。
4. 根据 Board 与 rule 的真实字段偏移，将 `*(&this->n + ... + 612)` 等表达式改回 `ruletemp.blckx/blcky`，将规则的整块复制整理为结构赋值。
5. 将初始棋盘中的线性偏移恢复为二维坐标；保留真实静态成员 maxw/maxh=128，避免将它们误当作对象成员。
6. `main.cpp` 人工纠正了 Lan/Window 互斥作用域共享栈槽导致的错误字段识别。该修正有汇编和成员偏移支撑。
7. `block.cpp` 四个方法已人工整理，并根据 DWARF 和符号名恢复 isok 的引用参数。对应机器整理版保存在 `*.machine.cpp`，便于对照。
8. `delline` 中 mb 被旧版反编译器错误推断为 int，造成变量重叠警告；DWARF 为 bool，汇编也为字节访问，已在阅读版改回 bool。原始警告仍在未改写导出中保留，不据此宣称整段代码已运行验证。

## 证据和验证

- `improved_raw.cpp`：本轮修正调用约定后的完整原始反编译输出。
- `ida_analysis.json`：逐函数地址、原始伪代码、类型、汇编，以及修正前后的调用约定。
- `MineSweeperRush_32_debug.dwarf.json`：直接从 EXE 提取的源文件、行号、参数、变量、类型和布局。没有读取编译路径指向的外部源码。
- `source_index.json`：395 个游戏函数的地址与恢复文件映射。
- `data_symbols.json`：数据地址、原始字节、读取长度依据与字符串解释。
- `verification.json`：输入 SHA-256、函数覆盖、字段偏移、初始棋盘坐标和常量表与原始 PE 的核对结果。

函数体仍由现有 IDA/Hex-Rays 生成；REA 的已有资源 Evidence 位于相邻 `decompiled/` 目录，所选 EXE 的 Evidence ID 为 `ev_` 前缀的 JSON 字段，按 SHA-256 对齐。REA 的资源 Evidence 不能证明函数语义，本轮类型和代码修复的依据是上述 DWARF/汇编。没有将直接调用 IDA 的结果冒称 REA 原生反编译 Evidence。

## 仍然存在的边界

全部 666 个被识别的函数中，664 个有函数体，另两个是 sprintf/wsprintfA 的外部导入跳板。395 个函数属于上述游戏源文件，其余 269 个运行库/SDK/未知归属函数放在 `runtime_and_sdk.cpp`，没有丢弃。

这是一份便于人阅读和继续重建的源码式伪代码，**尚未构成可直接编译的完整工程**。部分接口仍用反编译器的 int/指针形式，原始声明作为注释保留；构造/析构的显式低层调用、Windows/Steam/GDI+ SDK 类型、局部变量生命周期、浮点类型和部分匿名数据还需继续整理。`main.cpp` 和 `block.cpp` 的人工版本比机器导出更清晰，但也没有与运行中的原程序逐项比较。

没有运行目标程序，没有修改输入 EXE，没有删除旧分析文件，也没有保存或关闭用户附着的 IDA GUI 数据库；本轮只使用 `restored/working.idb` 的自有副本。
