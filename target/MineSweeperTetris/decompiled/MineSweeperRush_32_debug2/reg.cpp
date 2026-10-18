// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug2.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409DE8; symbol: __ZN3RegC1Ev
void __cdecl Reg::Reg(Reg *const this)
{
  Reg *v1; // [esp+0h] [ebp-18h]

  Reg::openreg(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409DFE; symbol: __ZN3RegD1Ev
void __cdecl Reg::~Reg(Reg *const this)
{
  Reg *v1; // [esp+0h] [ebp-18h]

  Reg::closereg(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409E14; symbol: __ZN3Reg7openregEv
void __cdecl Reg::openreg(Reg *const this)
{
  HKEY *v1; // ecx
  Reg *v2; // ST3C_4

  v2 = (Reg *)v1;
  RegCreateKeyExA(HKEY_CURRENT_USER, "SoftWare\\MineSweeperRush\\20250412", 0, 0, 0, 0xF003Fu, 0, v1, 0);
  RegCreateKeyExA(
    HKEY_CURRENT_USER,
    "SoftWare\\MineSweeperRush\\20250412\\board",
    0,
    0,
    0,
    0xF003Fu,
    0,
    &v2->regkey_,
    0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409EC0; symbol: __ZN3Reg8closeregEv
void __cdecl Reg::closereg(Reg *const this)
{
  HKEY *v1; // ecx
  Reg *v2; // ST1C_4

  v2 = (Reg *)v1;
  RegCloseKey(*v1);
  RegCloseKey(v2->regkey_);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：写入注册表值。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409EEE; symbol: __ZN3Reg6setregEP6HKEY__PKcl
void __userpurge Reg::setreg(Reg *const this, HKEY key, const char *name, int value)
{
  RegSetValueExA((HKEY)this, (LPCSTR)key, 0, 4u, (const BYTE *)&name, 4u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：读取注册表值。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409F30; symbol: __ZN3Reg6getregEP6HKEY__PKcPl
void __userpurge Reg::getreg(int a1@<ecx>, Reg *const this, HKEY key, const char *name, int *value)
{
  int temp; // [esp+3Ch] [ebp-Ch]

  *(_DWORD *)(a1 + 12) = 4;
  if ( RegQueryValueExA((HKEY)this, (LPCSTR)key, 0, (LPDWORD)(a1 + 8), (LPBYTE)&temp, (LPDWORD)(a1 + 12)) == 0 )
    *(_DWORD *)name = temp;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：写入注册表值。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409F92; symbol: __ZN3Reg7setreg_EP6HKEY__PKcPc
void __userpurge Reg::setreg_(Reg *const this, HKEY key, const char *name, char *value)
{
  RegSetValueExA((HKEY)this, (LPCSTR)key, 0, 3u, (const BYTE *)name, 0x4000u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：读取注册表值。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409FD4; symbol: __ZN3Reg7getreg_EP6HKEY__PKcPc
void __userpurge Reg::getreg_(int a1@<eax>, int a2@<ecx>, Reg *const this, HKEY key, const char *name, char *value)
{
  void *v6; // esp
  DWORD cbData; // [esp+3Ch] [ebp-400Ch]
  BYTE Data; // [esp+40h] [ebp-4008h]

  v6 = alloca(a1);
  cbData = 0x4000;
  if ( RegQueryValueExA((HKEY)this, (LPCSTR)key, 0, (LPDWORD)(a2 + 8), &Data, &cbData) == 0 )
    memcpy((void *)name, &Data, 0x4000u);
}


