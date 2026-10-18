// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425DC0; symbol: __ZN10__cxxabiv117__class_type_infoD0Ev
void __fastcall __cxxabiv1::__class_type_info::~__class_type_info(_DWORD *a1)
{
  void *v1; // ebx
  std::type_info *v2; // [esp+0h] [ebp-1Ch]

  v1 = a1;
  *a1 = &off_429D6C;
  std::type_info::~type_info(v2);
  operator delete(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425DF0; symbol: __ZN10__cxxabiv117__class_type_infoD1Ev
int __cdecl __cxxabiv1::__class_type_info::~__class_type_info(__cxxabiv1::__class_type_info *this)
{
  _DWORD *v1; // ecx

  *v1 = &off_429D6C;
  return std::type_info::~type_info(this);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425E00; symbol: __ZN10__cxxabiv120__si_class_type_infoD0Ev
void __fastcall __cxxabiv1::__si_class_type_info::~__si_class_type_info(_DWORD *a1)
{
  void *v1; // ebx
  __cxxabiv1::__class_type_info *v2; // [esp+0h] [ebp-1Ch]

  v1 = a1;
  *a1 = &off_429D98;
  __cxxabiv1::__class_type_info::~__class_type_info(v2);
  operator delete(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425E30; symbol: __ZN10__cxxabiv120__si_class_type_infoD1Ev
int __cdecl __cxxabiv1::__si_class_type_info::~__si_class_type_info(__cxxabiv1::__si_class_type_info *this)
{
  _DWORD *v1; // ecx

  *v1 = &off_429D98;
  return __cxxabiv1::__class_type_info::~__class_type_info(this);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004261B0; symbol: __ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj
int __userpurge __cxxabiv1::__class_type_info::__do_catch@<eax>(int a1@<ecx>, __cxxabiv1::__class_type_info *this, const std::type_info *a3, void **a4, unsigned int a5)
{
  int v5; // esi
  int result; // eax

  v5 = a1;
  result = std::type_info::operator==(this);
  if ( !(_BYTE)result && (unsigned int)a4 <= 3 )
    result = (*(int (__fastcall **)(__cxxabiv1::__class_type_info *, const std::type_info *, int))(*(_DWORD *)this + 20))(
               this,
               a3,
               v5);
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00426200; symbol: __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE
int __stdcall __cxxabiv1::__class_type_info::__do_upcast(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = std::type_info::operator==(a1);
  if ( (_BYTE)result )
  {
    a3[3] = 8;
    a3[1] = 6;
    *a3 = a2;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426240; symbol: __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv
signed int __userpurge __cxxabiv1::__class_type_info::__do_upcast@<eax>(int *a1@<ecx>, __cxxabiv1::__class_type_info *this, const __cxxabiv1::__class_type_info *a3, void **a4)
{
  int v4; // eax
  signed int result; // eax
  int v6; // [esp+10h] [ebp-1Ch]
  int v7; // [esp+14h] [ebp-18h]
  int v8; // [esp+18h] [ebp-14h]
  int v9; // [esp+1Ch] [ebp-10h]

  v4 = *a1;
  v6 = 0;
  v7 = 0;
  v8 = 16;
  v9 = 0;
  (*(void (__stdcall **)(__cxxabiv1::__class_type_info *, _DWORD, int *))(v4 + 24))(this, *(_DWORD *)a3, &v6);
  result = 0;
  if ( (v7 & 6) == 6 )
  {
    *(_DWORD *)a3 = v6;
    result = 1;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004262B0; symbol: __ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE
int __stdcall __cxxabiv1::__class_type_info::__do_dyncast(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int result; // eax

  if ( a4 == a6 && (unsigned __int8)std::type_info::operator==(a5) )
  {
    a7[2] = a2;
    result = 0;
  }
  else
  {
    if ( (unsigned __int8)std::type_info::operator==(a3) )
    {
      *a7 = a4;
      a7[3] = 1;
      a7[1] = a2;
    }
    result = 0;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426330; symbol: __ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_
int __userpurge __cxxabiv1::__class_type_info::__do_find_public_src@<eax>(__cxxabiv1::__class_type_info *this, const __cxxabiv1::__class_type_info *a2, const void *a3, const __cxxabiv1::__class_type_info *a4, const void *a5)
{
  return 5 * (a4 == a2) + 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00426350; symbol: __ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE
int __fastcall __cxxabiv1::__si_class_type_info::__do_upcast(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // ebp
  int result; // eax

  v5 = a1;
  result = __cxxabiv1::__class_type_info::__do_upcast(a3, a4, a5);
  if ( !(_BYTE)result )
    result = (*(int (__stdcall **)(int, int, _DWORD *))(**(_DWORD **)(v5 + 8) + 24))(a3, a4, a5);
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004263B0; symbol: __ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE
int __fastcall __cxxabiv1::__si_class_type_info::__do_dyncast(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _DWORD *a9)
{
  char v9; // al
  int v10; // edx
  int result; // eax
  char v12; // al
  int v13; // [esp+18h] [ebp-24h]

  v13 = a1;
  v9 = std::type_info::operator==(a5);
  v10 = a5;
  if ( v9 )
  {
    *a9 = a6;
    a9[1] = a4;
    if ( a3 < 0 )
    {
      if ( a3 == -2 )
        a9[3] = 1;
    }
    else
    {
      a9[3] = 5 * (a8 == a6 + a3) + 1;
    }
    result = 0;
  }
  else if ( a6 == a8 && (v12 = std::type_info::operator==(a7), v10 = a5, v12) )
  {
    a9[2] = a4;
    result = 0;
  }
  else
  {
    result = (*(int (__stdcall **)(int, int, int, int, int, int, _DWORD *))(**(_DWORD **)(v13 + 8) + 28))(
               a3,
               a4,
               v10,
               a6,
               a7,
               a8,
               a9);
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004264A0; symbol: __ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_
int __userpurge __cxxabiv1::__si_class_type_info::__do_find_public_src@<eax>(int a1@<ecx>, __cxxabiv1::__si_class_type_info *this, int a3, const void *a4, const __cxxabiv1::__class_type_info *a5, const void *a6)
{
  int v6; // edx
  int result; // eax
  int v8; // ST1C_4
  char v9; // al

  v6 = a1;
  if ( a5 == (const __cxxabiv1::__class_type_info *)a3 && (v8 = a1, v9 = std::type_info::operator==(a4), v6 = v8, v9) )
    result = 6;
  else
    result = (*(int (__stdcall **)(__cxxabiv1::__si_class_type_info *, int, const void *, const __cxxabiv1::__class_type_info *))(**(_DWORD **)(v6 + 8) + 32))(
               this,
               a3,
               a4,
               a5);
  return result;
}


