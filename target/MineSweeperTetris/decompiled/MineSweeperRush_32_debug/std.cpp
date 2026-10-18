// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00426550; symbol: __ZNKSt9type_info10__do_catchEPKS_PPvj
int __stdcall std::type_info::__do_catch(std::type_info *this, const std::type_info *a2, void **a3, unsigned int a4)
{
  return std::type_info::operator==(this);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426570; symbol: __ZNKSt9type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv
int __userpurge std::type_info::__do_upcast@<eax>(std::type_info *this, const __cxxabiv1::__class_type_info *a2, void **a3)
{
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00426580; symbol: __ZNKSt9type_info14__is_pointer_pEv
int std::type_info::__is_pointer_p()
{
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00426590; symbol: __ZNKSt9type_infoeqERKS_
bool __fastcall std::type_info::operator==(int a1, int a2, int a3)
{
  if ( a3 == a1 )
    return 1;
  if ( **(_BYTE **)(a1 + 4) == 42 )
    return 0;
  return strcmp(*(const char **)(a1 + 4), (const char *)((**(_BYTE **)(a3 + 4) == 42) + *(_DWORD *)(a3 + 4))) == 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004265F0; symbol: __ZNSt9type_infoD0Ev
void __fastcall std::type_info::~type_info(void *a1)
{
  operator delete(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00426610; symbol: __ZNSt9type_infoD1Ev
void __cdecl std::type_info::~type_info()
{
  ;
}


