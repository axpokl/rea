// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426164; symbol: __ZN8CSteamIDC1Ev
void __cdecl CSteamID::CSteamID(CSteamID *const this)
{
  int v1; // ecx
  char v2; // t1
  char v3; // t1

  *(_DWORD *)v1 = 0;
  *(_BYTE *)(v1 + 6) &= 0xFu;
  *(_BYTE *)(v1 + 7) = 0;
  v2 = *(_BYTE *)(v1 + 4);
  *(_BYTE *)(v1 + 4) = 0;
  v3 = *(_BYTE *)(v1 + 5);
  *(_BYTE *)(v1 + 5) = 0;
  *(_BYTE *)(v1 + 6) &= 0xF0u;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426538; symbol: __ZNK8CSteamID15GetEAccountTypeEv
EAccountType __cdecl CSteamID::GetEAccountType(const CSteamID *const this)
{
  int v1; // ecx

  return (unsigned __int8)(*(_BYTE *)(v1 + 6) >> 4);
}


