// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00401000; symbol: TopLevelExceptionFilter
LONG __stdcall TopLevelExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
  DWORD v1; // eax
  void (__cdecl *v2)(int); // eax
  LONG result; // eax
  void (__cdecl *v4)(int); // eax
  void (__cdecl *v5)(int); // eax

  v1 = ExceptionInfo->ExceptionRecord->ExceptionCode;
  if ( v1 > 0xC0000091 )
  {
    if ( v1 == -1073741676 )
    {
      v4 = signal(8, 0);
      if ( v4 == (void (__cdecl *)(int))1 )
      {
        signal(8, (void (__cdecl *)(int))1);
        return -1;
      }
LABEL_12:
      if ( !v4 )
        return 0;
      v4(8);
      return -1;
    }
    if ( v1 == -1073741674 )
    {
LABEL_17:
      v5 = signal(4, 0);
      if ( v5 == (void (__cdecl *)(int))1 )
      {
        signal(4, (void (__cdecl *)(int))1);
        result = -1;
      }
      else
      {
        if ( !v5 )
          return 0;
        v5(4);
        result = -1;
      }
      return result;
    }
    if ( v1 != -1073741677 )
      return 0;
LABEL_11:
    v4 = signal(8, 0);
    if ( v4 == (void (__cdecl *)(int))1 )
    {
      signal(8, (void (__cdecl *)(int))1);
      fesetenv(0);
      return -1;
    }
    goto LABEL_12;
  }
  if ( v1 >= 0xC000008D )
    goto LABEL_11;
  if ( v1 != -1073741819 )
  {
    if ( v1 != -1073741795 )
      return 0;
    goto LABEL_17;
  }
  v2 = signal(11, 0);
  if ( v2 == (void (__cdecl *)(int))1 )
  {
    signal(11, (void (__cdecl *)(int))1);
    result = -1;
  }
  else
  {
    if ( !v2 )
      return 0;
    v2(11);
    result = -1;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004012A0; symbol: __mingw32_init_mainargs
int _mingw32_init_mainargs()
{
  char v1; // [esp+28h] [ebp-14h]
  int v2; // [esp+2Ch] [ebp-10h]

  v2 = 0;
  return __getmainargs(&_argc, &_argv, &v1, _CRT_glob & 1, &v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004012E0; symbol: _mainCRTStartup
void __noreturn mainCRTStartup()
{
  ___set_app_type(1);
  sub_4011B0();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00401320; symbol: _atexit
int __cdecl atexit(void (__cdecl *a1)())
{
  return _atexit(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423950; symbol: ____w64_mingwthr_add_key_dtor
signed int __cdecl ___w64_mingwthr_add_key_dtor(int a1, int a2)
{
  int v2; // esi
  _DWORD *v4; // eax
  int v5; // ebx
  int v6; // eax

  v2 = 0;
  if ( !dword_470948 )
    return v2;
  v4 = calloc(1u, 0xCu);
  v5 = (int)v4;
  if ( !v4 )
    return -1;
  *v4 = a1;
  v4[1] = a2;
  EnterCriticalSection(&CriticalSection);
  v6 = dword_470944;
  dword_470944 = v5;
  *(_DWORD *)(v5 + 8) = v6;
  LeaveCriticalSection(&CriticalSection);
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004239E0; symbol: ____w64_mingwthr_remove_key_dtor
int __cdecl ___w64_mingwthr_remove_key_dtor(int a1)
{
  int v2; // edx
  _DWORD *v3; // eax

  if ( !dword_470948 )
    return 0;
  EnterCriticalSection(&CriticalSection);
  v2 = dword_470944;
  if ( dword_470944 )
  {
    if ( a1 == *(_DWORD *)dword_470944 )
    {
      dword_470944 = *(_DWORD *)(dword_470944 + 8);
      v3 = (_DWORD *)v2;
LABEL_12:
      free(v3);
      LeaveCriticalSection(&CriticalSection);
      return 0;
    }
    while ( 1 )
    {
      v3 = *(_DWORD **)(v2 + 8);
      if ( !v3 )
        break;
      if ( *v3 == a1 )
      {
        *(_DWORD *)(v2 + 8) = v3[2];
        goto LABEL_12;
      }
      v2 = *(_DWORD *)(v2 + 8);
    }
  }
  LeaveCriticalSection(&CriticalSection);
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423A80; symbol: ___mingw_TLScallback
signed int __cdecl __mingw_TLScallback(int a1, unsigned int a2)
{
  signed int result; // eax

  if ( a2 == 1 )
  {
    if ( !dword_470948 )
      InitializeCriticalSection(&CriticalSection);
    dword_470948 = 1;
    result = 1;
  }
  else
  {
    if ( a2 < 1 )
    {
      if ( dword_470948 )
        sub_4238F0();
      if ( dword_470948 == 1 )
      {
        dword_470948 = 0;
        DeleteCriticalSection(&CriticalSection);
      }
    }
    else if ( a2 == 3 )
    {
      if ( dword_470948 )
        sub_4238F0();
    }
    result = 1;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00424E00; symbol: ___mingw_glob
int __cdecl __mingw_glob(char *a1, int a2, int a3, int a4)
{
  char *v4; // ebx
  int v5; // ecx
  int v7; // eax
  void *v8; // esp
  int v9; // ecx
  void *v10; // esp
  char *v11; // edx
  char v12; // al
  char v13; // al
  char *v14; // eax
  int v15; // [esp+0h] [ebp-38h]
  char v16; // [esp+4h] [ebp-34h]
  int *v17; // [esp+18h] [ebp-20h]
  int *v18; // [esp+1Ch] [ebp-1Ch]

  v4 = a1;
  if ( a4 && !(a2 & 2) )
    *(_DWORD *)(a4 + 12) = 0;
  if ( *(char **)a4 != "glob-1.0-mingw32" )
  {
    sub_423F70(a4);
    *(_DWORD *)a4 = "glob-1.0-mingw32";
  }
  v5 = sub_424570(a1, a2, a3, a4);
  if ( v5 == 2 && a2 & 0x10 )
  {
    v17 = (int *)2;
    v18 = &v15;
    v7 = 16 * ((strlen(a1) + 16) >> 4);
    v8 = alloca(v7);
    v9 = (int)v17;
    v10 = alloca(v7);
    v11 = &v16;
    do
    {
      while ( 1 )
      {
        v12 = *v4;
        if ( *v4 == 127 )
          break;
        ++v11;
        ++v4;
        *(v11 - 1) = v12;
        if ( !v12 )
          goto LABEL_13;
      }
      v13 = v4[1];
      ++v11;
      v4 += 2;
      *(v11 - 1) = v13;
    }
    while ( v13 );
LABEL_13:
    v17 = (int *)v9;
    v14 = strdup(&v16);
    v5 = (int)v17;
    if ( v14 )
    {
      v18 = v17;
      sub_4244C0((int)v14, a4);
      v5 = (int)v18;
    }
  }
  return v5;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00424EF0; symbol: ___mingw_globfree
void __cdecl __mingw_globfree(void *a1)
{
  int v1; // eax
  int v2; // edi
  int v3; // ebx
  void *v4; // eax

  if ( *(char **)a1 == "glob-1.0-mingw32" )
  {
    v1 = *((_DWORD *)a1 + 1);
    v2 = v1 - 1;
    v3 = 4 * *((_DWORD *)a1 + 3);
    if ( v1 > 0 )
    {
      do
      {
        --v2;
        v4 = *(void **)(*((_DWORD *)a1 + 2) + v3);
        v3 += 4;
        free(v4);
      }
      while ( v2 != -1 );
    }
    free(*((void **)a1 + 2));
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00424F50; symbol: ___mingw_dirname
char *__cdecl __mingw_dirname(char *a1)
{
  char *v1; // eax
  char *v2; // ebx
  size_t v3; // esi
  size_t v5; // eax
  size_t v6; // edx
  int v7; // eax
  void *v8; // esp
  void *v9; // esp
  bool v10; // cf
  bool v11; // zf
  _WORD *v12; // ecx
  __int16 v13; // dx
  _WORD *v14; // esi
  __int16 v15; // dx
  _WORD *i; // eax
  size_t v17; // eax
  _WORD *v18; // eax
  char *v19; // esi
  int v20; // eax
  __int16 v21; // dx
  wchar_t *v22; // ecx
  wchar_t v23; // dx
  wchar_t *v24; // eax
  size_t v25; // eax
  size_t v26; // eax
  __int16 v27; // dx
  int v28; // [esp+0h] [ebp-38h]
  wchar_t v29; // [esp+Ch] [ebp-2Ch]
  __int16 v30; // [esp+Eh] [ebp-2Ah]
  size_t v31; // [esp+10h] [ebp-28h]
  int *v32; // [esp+14h] [ebp-24h]
  __int16 v33; // [esp+1Ah] [ebp-1Eh]
  size_t v34; // [esp+1Ch] [ebp-1Ch]

  v1 = setlocale(2, 0);
  v2 = v1;
  if ( v1 )
    v2 = strdup(v1);
  setlocale(2, byte_429B44);
  if ( !a1 || !*a1 )
    goto LABEL_66;
  v32 = &v28;
  v5 = mbstowcs(0, a1, 0);
  v6 = v5;
  v7 = 16 * ((2 * v5 + 18) >> 4);
  v8 = alloca(v7);
  v9 = alloca(v7);
  v31 = mbstowcs(&v29, a1, v6);
  v10 = v31 < 1;
  v11 = v31 == 1;
  *(&v29 + v31) = 0;
  v34 = (size_t)&v29;
  v33 = v29;
  if ( !v10 && !v11 )
  {
    if ( v29 == 47 || v29 == 92 )
    {
      if ( v33 == v30 && !(_WORD)v31 )
      {
        setlocale(2, v2);
        free(v2);
        return a1;
      }
    }
    else if ( v30 == 58 )
    {
      v34 = (size_t)&v31;
      v33 = v31;
    }
  }
  if ( !v33 )
  {
LABEL_66:
    v3 = wcstombs(0, &word_429B46, 0) + 1;
    dword_470970 = realloc(dword_470970, v3);
    wcstombs((char *)dword_470970, &word_429B46, v3);
    setlocale(2, v2);
    free(v2);
    return (char *)dword_470970;
  }
  v12 = (_WORD *)v34;
  v13 = v33;
  v14 = (_WORD *)v34;
  do
  {
    while ( v13 != 47 && v13 != 92 )
    {
      v13 = v12[1];
      ++v12;
      if ( !v13 )
        goto LABEL_21;
    }
    v15 = *v12;
    for ( i = v12; *i == 47; v15 = *i )
LABEL_17:
      ++i;
    if ( v15 == 92 )
      goto LABEL_17;
    if ( !v15 )
      break;
    v13 = i[1];
    v14 = i;
    v12 = i + 1;
  }
  while ( v13 );
LABEL_21:
  if ( v34 < (unsigned int)v14 )
  {
    while ( 1 )
    {
      v20 = (int)(v14 - 1);
      if ( v34 >= (unsigned int)(v14 - 1) )
        break;
      v21 = *(v14 - 1);
      --v14;
      if ( v21 != 47 && v21 != 92 )
        goto LABEL_30;
    }
    if ( (_WORD *)v34 == v14 - 1 && (v33 == 47 || v33 == 92) && *v14 == v33 )
    {
      v27 = *(_WORD *)(v20 + 4);
      if ( v27 != 47 && v27 != 92 )
        v20 = (int)v14;
    }
LABEL_30:
    v22 = &v29;
    *(_WORD *)(v20 + 2) = 0;
    v23 = v29;
    if ( v29 == 47 || v29 == 92 )
    {
      do
      {
        do
          ++v22;
        while ( *v22 == 47 );
      }
      while ( *v22 == 92 );
      if ( (char *)v22 - (char *)&v29 > 5 )
        goto LABEL_67;
    }
    if ( v30 != v29 )
LABEL_67:
      v22 = &v29;
    else
      v23 = *v22;
    v24 = v22;
    while ( v23 )
    {
      while ( 1 )
      {
        ++v22;
        *(v22 - 1) = v23;
        if ( v23 == 47 )
          break;
        if ( *v24 == 92 )
        {
          ++v24;
          break;
        }
        v23 = v24[1];
        ++v24;
        if ( !v23 )
          goto LABEL_41;
      }
      v23 = *v24;
      if ( *v24 == 92 || v23 == 47 )
      {
        do
        {
          do
          {
            ++v24;
            v23 = *v24;
          }
          while ( *v24 == 47 );
        }
        while ( v23 == 92 );
      }
    }
LABEL_41:
    v25 = v31;
    *v22 = 0;
    v26 = wcstombs(a1, &v29, v25);
    v19 = a1;
    if ( v26 != -1 )
      a1[v26] = 0;
  }
  else
  {
    if ( v33 == 47 || v33 == 92 )
    {
      v18 = (_WORD *)(v34 + 2);
    }
    else
    {
      v17 = v34;
      *(_WORD *)v34 = 46;
      v18 = (_WORD *)(v17 + 2);
    }
    *v18 = 0;
    v34 = wcstombs(0, &v29, 0) + 1;
    dword_470970 = realloc(dword_470970, v34);
    v19 = (char *)dword_470970;
    wcstombs((char *)dword_470970, &v29, v34);
  }
  setlocale(2, v2);
  free(v2);
  return v19;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004254D0; symbol: ___mingw_opendir
int __cdecl __mingw_opendir(char *a1)
{
  char *v1; // eax
  int v2; // ecx
  unsigned int v3; // edx
  int v4; // eax
  char v5; // dl
  int v6; // ecx
  unsigned int v7; // edx
  char *v8; // kr00_4
  char *v9; // eax
  int v10; // esi
  const CHAR *v11; // ebp
  HANDLE v12; // eax
  void *v14; // ST00_4
  char v15; // [esp+1Bh] [ebp-121h]
  char v16[288]; // [esp+1Ch] [ebp-120h]

  if ( a1 )
  {
    if ( *a1 )
    {
      _fullpath(v16, a1, 0x104u);
      v1 = v16;
      if ( v16[0] )
      {
        do
        {
          v2 = *(_DWORD *)v1;
          v1 += 4;
          v3 = ~v2 & (v2 - 16843009) & 0x80808080;
        }
        while ( !v3 );
        if ( !(~v2 & (v2 - 16843009) & 0x8080) )
        {
          v3 >>= 16;
          v1 += 2;
        }
        v4 = &v1[-__CFADD__((_BYTE)v3, (_BYTE)v3) - 3] - v16;
        v5 = *(&v15 + v4);
        if ( v5 != 47 && v5 != 92 )
          *(_WORD *)&v16[v4++] = 92;
      }
      else
      {
        do
        {
          v6 = *(_DWORD *)v1;
          v1 += 4;
          v7 = ~v6 & (v6 - 16843009) & 0x80808080;
        }
        while ( !v7 );
        if ( !(~v6 & (v6 - 16843009) & 0x8080) )
        {
          v7 >>= 16;
          v1 += 2;
        }
        v4 = &v1[-__CFADD__((_BYTE)v7, (_BYTE)v7) - 3] - v16;
      }
      *(_WORD *)&v16[v4] = 42;
      v8 = &v16[strlen(v16)];
      v9 = (char *)malloc(v8 - v16 + 284);
      v10 = (int)v9;
      if ( v9 )
      {
        v11 = v9 + 280;
        memcpy(v9 + 280, v16, v8 - v16 + 1);
        v12 = sub_425350(v11, v10);
        *(_DWORD *)(v10 + 272) = v12;
        if ( v12 == (HANDLE)-1 )
        {
          v14 = (void *)v10;
          v10 = 0;
          free(v14);
        }
        else
        {
          *(_DWORD *)(v10 + 276) = 0;
          *(_DWORD *)v10 = 0;
          *(_WORD *)(v10 + 4) = 272;
        }
      }
      else
      {
        *(_DWORD *)_errno() = 12;
      }
    }
    else
    {
      v10 = 0;
      *(_DWORD *)_errno() = 2;
    }
  }
  else
  {
    v10 = 0;
    *(_DWORD *)_errno() = 22;
  }
  return v10;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425690; symbol: ___mingw_readdir
BOOL __cdecl __mingw_readdir(int a1)
{
  int v1; // eax
  BOOL result; // eax

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 276);
    *(_DWORD *)(a1 + 276) = v1 + 1;
    if ( v1 <= 0 || (result = sub_425420(*(void **)(a1 + 272), a1)) != 0 )
      result = a1;
  }
  else
  {
    *(_DWORD *)_errno() = 9;
    result = 0;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004256E0; symbol: ___mingw_closedir
int __cdecl __mingw_closedir(void *a1)
{
  int result; // eax

  if ( a1 && FindClose(*((HANDLE *)a1 + 68)) )
  {
    free(a1);
    result = 0;
  }
  else
  {
    *(_DWORD *)_errno() = 9;
    result = -1;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425730; symbol: ___mingw_rewinddir
_DWORD *__cdecl __mingw_rewinddir(int a1)
{
  _DWORD *result; // eax

  if ( a1 && FindClose(*(HANDLE *)(a1 + 272)) )
  {
    result = sub_425350((const CHAR *)(a1 + 280), a1);
    *(_DWORD *)(a1 + 272) = result;
    if ( result != (_DWORD *)-1 )
      *(_DWORD *)(a1 + 276) = 0;
  }
  else
  {
    result = (_DWORD *)_errno();
    *result = 9;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425790; symbol: ___mingw_telldir
signed int __cdecl __mingw_telldir(int a1)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 276);
  *(_DWORD *)_errno() = 9;
  return -1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004257C0; symbol: ___mingw_seekdir
_DWORD *__cdecl __mingw_seekdir(int a1, signed int a2)
{
  _DWORD *result; // eax

  if ( a2 < 0 )
  {
    result = (_DWORD *)_errno();
    *result = 22;
  }
  else
  {
    result = __mingw_rewinddir(a1);
    if ( a2 && *(_DWORD *)(a1 + 272) != -1 )
    {
      do
      {
        result = (_DWORD *)(*(_DWORD *)(a1 + 276) + 1);
        *(_DWORD *)(a1 + 276) = result;
        if ( a2 <= (signed int)result )
          break;
        result = (_DWORD *)sub_425420(*(void **)(a1 + 272), a1);
      }
      while ( result );
    }
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B10; symbol: _SetUnhandledExceptionFilter@4
LPTOP_LEVEL_EXCEPTION_FILTER __stdcall SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)
{
  return SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004011B0; symbol: sub_4011B0
void __noreturn sub_4011B0()
{
  _DWORD *v0; // eax
  UINT v1; // ebx

  if ( __dyn_tls_init_callback )
    __dyn_tls_init_callback(0, 2, 0);
  SetUnhandledExceptionFilter(TopLevelExceptionFilter);
  __cpu_features_init();
  fesetenv(_CRT_fenv);
  _setargv();
  if ( _CRT_fmode )
  {
    _fmode = _CRT_fmode;
    _setmode(__iob[0]._file, _CRT_fmode);
    _setmode(__iob[1]._file, _CRT_fmode);
    _setmode(__iob[2]._file, _CRT_fmode);
  }
  *(_DWORD *)__p__fmode() = _fmode;
  _pei386_runtime_relocator();
  __main();
  v0 = (_DWORD *)__p__environ();
  v1 = main_0(_argc, _argv, *v0);
  _cexit();
  ExitProcess(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00401330; symbol: __onexit
_onexit_t __cdecl _onexit(_onexit_t a1)
{
  return __onexit(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00404286; symbol: __ZN5Board7dellineEl
// local variable allocation has failed, the output may be wrong!
void __userpurge Board::delline(Board *a1@<ecx>, Board *const this, int l)
{
  signed int v3; // eax
  bool v4; // dl
  char *v5; // eax
  signed int v6; // eax
  int v7; // ST0C_4
  signed int v8; // eax
  int v9; // ST04_4
  Board *v10; // [esp+0h] [ebp-78h]
  int v11; // [esp+4h] [ebp-74h]
  bool v12; // [esp+4h] [ebp-74h]
  int v13; // [esp+Ch] [ebp-6Ch]
  int v14; // [esp+Ch] [ebp-6Ch]
  int v15; // [esp+Ch] [ebp-6Ch]
  int v16; // [esp+Ch] [ebp-6Ch]
  int *v17; // [esp+14h] [ebp-64h]
  Board *thisa; // [esp+2Ch] [ebp-4Ch]
  int scrtotal_[4]; // [esp+3Ch] [ebp-3Ch]
  int mb; // [esp+4Fh] [ebp-29h] OVERLAPPED
  int j_0; // [esp+50h] [ebp-28h]
  int k_0; // [esp+54h] [ebp-24h]
  int k; // [esp+58h] [ebp-20h]
  int j_1; // [esp+5Ch] [ebp-1Ch]
  int i_1; // [esp+60h] [ebp-18h]
  int i_0; // [esp+64h] [ebp-14h]
  int j; // [esp+68h] [ebp-10h]
  int i; // [esp+6Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->sit > 0 && a1->sit <= 3 && !a1->pauseb )
  {
    a1->checkr = 0;
    if ( a1->relaxb )
    {
      ++a1->line;
      ++a1->sum;
      v3 = a1->line;
      if ( v3 > 999999 )
        v3 = 999999;
      a1->line = v3;
      Board::addline(a1, 0, v11);
    }
    else
    {
      ++a1->maskj;
    }
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = (int)this; j >= 0; --j )
      {
        if ( j )
        {
          thisa->mine[i][j] = thisa->mine[i][j - 1];
          v4 = thisa->mask[i][j - 1] && thisa->relaxb != 1;
          thisa->mask[i][j] = v4;
          thisa->flag[i][j] = thisa->flag[i][j - 1];
          thisa->leftrule[i][j] = thisa->leftrule[i][j - 1];
          thisa->rightrule[i][j] = thisa->rightrule[i][j - 1];
          thisa->qstn[i][j] = thisa->qstn[i][j - 1];
          thisa->blck[i][j] = thisa->blck[i][j - 1];
          thisa->numb[i][j] = thisa->numb[i][j - 1];
        }
        else
        {
          thisa->mine[i][0] = thisa->n > i;
          thisa->mask[i][j] = !thisa->maskjb;
          thisa->flag[i][j] = 0;
          thisa->leftrule[i][j] = 0;
          thisa->rightrule[i][j] = 0;
          thisa->qstn[i][j] = 0;
          thisa->blck[i][j] = 0;
        }
      }
    }
    thisa->maskjb = 0;
    for ( i_0 = 0; thisa->w > i_0; ++i_0 )
    {
      thisa->rx = rand() % thisa->w;
      thisa->ry = 0;
      j_0 = 0;
      mb = thisa->mine[thisa->rx][thisa->ry];
      thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i_0][j_0];
      thisa->mine[i_0][j_0] = mb;
    }
    for ( i_1 = 0; thisa->w > i_1; ++i_1 )
    {
      v5 = (char *)(thisa->h - 1);
      if ( (signed int)v5 > (signed int)&this->w + 1 )
        v5 = (char *)&this->w + 1;
      for ( j_1 = (int)v5; j_1 >= (signed int)this; --j_1 )
      {
        thisa->numb[i_1][j_1] = 0;
        for ( k = 0; k <= 7; ++k )
        {
          if ( Block::isok(thisa, (Block *const )k, i_1, j_1, (int)&thisa->tx, &thisa->ty, v17)
            && thisa->mine[thisa->tx][thisa->ty] )
          {
            ++thisa->numb[i_1][j_1];
          }
        }
      }
    }
    ++thisa->line;
    ++thisa->sum;
    v6 = thisa->line;
    if ( v6 > 999999 )
      v6 = 999999;
    thisa->line = v6;
    if ( thisa->sum == thisa->line + thisa->tetrisi )
    {
      Steam::compscr((Steam *const )thisa->line, thisa->mode, thisa->st.scrindexline, v13);
      if ( thisa->mdb == 1 )
        Steam::compscr((Steam *const )thisa->line, thisa->mode, thisa->st.scrindexmdb, v14);
      Steam::compscr((Steam *const )(thisa->line - thisa->missline), thisa->mode, thisa->st.scrindexnomiss, v14);
      scrtotal_[0] = 0;
      scrtotal_[1] = 2;
      scrtotal_[2] = 3;
      scrtotal_[3] = 6;
      Steam::addscr((Steam *const )thisa->st.scrtotal, scrtotal_[thisa->mode], thisa->mode, v7);
      if ( thisa->line > 9999 )
        Steam::addach((Steam *const )thisa->st.achhidedge, v11);
    }
    if ( thisa->maskj > thisa->h - 4 )
    {
      ++thisa->tetrisi;
      ++thisa->sum;
      Steam::compscr((Steam *const )thisa->tetrisi, thisa->mode, thisa->st.scrindextetris, v13);
      thisa->line += 4 + (thisa->bouns & ~(thisa->bouns >> 31));
      thisa->sum += 4 + (thisa->bouns & ~(thisa->bouns >> 31));
      v8 = thisa->line;
      if ( v8 > 999999 )
        v8 = 999999;
      thisa->line = v8;
      if ( thisa->sum == thisa->line + thisa->tetrisi )
      {
        Steam::compscr((Steam *const )thisa->line, thisa->mode, thisa->st.scrindexline, v15);
        if ( thisa->mdb == 1 )
          Steam::compscr((Steam *const )thisa->line, thisa->mode, thisa->st.scrindexmdb, v16);
        Steam::compscr((Steam *const )(thisa->line - thisa->missline), thisa->mode, thisa->st.scrindexnomiss, v16);
      }
      for ( k_0 = 0; k_0 <= 3; ++k_0 )
        Board::addline(v10);
      Board::checkline(thisa, 0, v12);
      thisa->sit = 3;
      thisa->bouns = 4;
      Sound::playsound((Sound *const )thisa->sd.sNew, v9);
      Steam::addscr((Steam *const )thisa->st.scrfour, 1, thisa->mode, v15);
    }
    while ( (thisa->level + 1) * (thisa->level + 1) <= thisa->line )
    {
      ++thisa->level;
      Sound::playsound((Sound *const )thisa->sd.sWin, v11);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004055D8; symbol: __Z11CombinePathPcPKcS1_
void __cdecl CombinePath(char *dest, const char *path1, const char *path2)
{
  lstrcpyA(dest, path1);
  lstrcatA(dest, "/");
  lstrcatA(dest, path2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405667; symbol: __Z15RemoveExtensionPc
void __cdecl RemoveExtension(char *filePath)
{
  char *lastDot; // [esp+1Ch] [ebp-Ch]

  lastDot = strrchr(filePath, 46);
  if ( lastDot )
    *lastDot = 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405840; symbol: __Z23DeleteFolderRecursivelyPKc
void __cdecl DeleteFolderRecursively(const char *folderPath)
{
  bool v1; // al
  WIN32_FIND_DATAA findData; // [esp+14h] [ebp-354h]
  char filePath[260]; // [esp+154h] [ebp-214h]
  char searchPath[260]; // [esp+258h] [ebp-110h]
  HANDLE hFind; // [esp+35Ch] [ebp-Ch]

  CombinePath(searchPath, folderPath, "*");
  hFind = FindFirstFileA(searchPath, &findData);
  if ( hFind != (HANDLE)-1 )
  {
    do
    {
      CombinePath(filePath, folderPath, findData.cFileName);
      if ( findData.dwFileAttributes & 0x10 )
      {
        v1 = lstrcmpA(findData.cFileName, ".") && lstrcmpA(findData.cFileName, "..");
        if ( v1 )
          DeleteFolderRecursively(filePath);
      }
      else
      {
        DeleteFileA(filePath);
      }
    }
    while ( FindNextFileA(hFind, &findData) != 0 );
    FindClose(hFind);
  }
  RemoveDirectoryA(folderPath);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405A50; symbol: __Z13WinCreateMainv
void WinCreateMain()
{
  if ( _hw )
  {
    ReleaseBMP(_pmscr);
    ReleaseBMP(_pmain);
    _dc = GetDC(_hw);
    _mscr.Handle = _hw;
    _mscr.DC = _dc;
    _mscr.Width = _w;
    _mscr.Height = _h;
    _pmscr = &_mscr;
    _pmain = CreateBMP(&_mscr);
    _pmain->Color = 1;
    _main.Handle = _pmain->Handle;
    _main.DC = _pmain->DC;
    _main.Width = _pmain->Width;
    _main.Height = _pmain->Height;
    _main.Color = _pmain->Color;
    SetFont();
    if ( _draw )
      _draw();
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405DD2; symbol: __Z15MonitorenumprocP10HMONITOR__P5HDC__P7tagRECTl@16
BOOL __stdcall Monitorenumproc(HMONITOR hmon, HDC hdc, LPRECT lprect, LPARAM pdata)
{
  RECT *v4; // eax
  LONG work_4; // [esp+20h] [ebp-68h]
  LONG work_8; // [esp+24h] [ebp-64h]
  LONG work_12; // [esp+28h] [ebp-60h]
  MONITORINFOEX info; // [esp+2Ch] [ebp-5Ch]
  int posY; // [esp+74h] [ebp-14h]
  int posX; // [esp+78h] [ebp-10h]
  RECT *r; // [esp+7Ch] [ebp-Ch]

  r = (RECT *)pdata;
  info.cbSize = 72;
  posX = GetPosX();
  posY = GetPosY();
  if ( GetMonitorInfoA(hmon, &info.0) == 0 )
    return 1;
  work_4 = info.rcWork.top;
  work_8 = info.rcWork.right;
  work_12 = info.rcWork.bottom;
  if ( info.rcWork.left > posX || info.rcWork.right < posX || info.rcWork.top > posY || info.rcWork.bottom < posY )
    return 1;
  v4 = r;
  r->left = info.rcWork.left;
  v4->top = work_4;
  v4->right = work_8;
  v4->bottom = work_12;
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：创建窗口。
// Address: 0x00405EEA; symbol: __Z9WinCreatev
void WinCreate()
{
  RECT rect; // [esp+40h] [ebp-28h]

  rect.left = _x;
  rect.top = _y;
  rect.right = _x + _w;
  rect.bottom = _y + _h;
  AdjustWindowRect(&rect, _style, 0);
  _w = rect.right - rect.left;
  _h = rect.bottom - rect.top;
  _hw = CreateWindowExW(
          0,
          _class,
          0,
          _style,
          _x,
          _y,
          rect.right - rect.left,
          rect.bottom - rect.top,
          0,
          0,
          MainInstance,
          0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：处理窗口消息循环。
// Address: 0x00405FEA; symbol: __Z7WinInitv
void WinInit()
{
  if ( !_wca )
    _wca = WinRegister();
  WinCreate();
  WinCreateMain();
  _winb = 1;
  GetTimeR();
  _tbegin = _tcount;
  while ( IsWin() )
  {
    GetMessageA(&_mst, 0, 0, 0);
    if ( _mst.message )
    {
      SendMsg();
      _mswini = ((_WORD)_mswini + 1) & 0xFFF;
      _mswin[_mswini] = _mst;
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004060DC; symbol: __Z8FreshFPSv
void FreshFPS()
{
  unsigned int v0; // ebx

  while ( _mscnti > 0xFFF )
    _mscnti -= 4096;
  v0 = _mscnti;
  _mscnt[v0] = GetTimeR();
  while ( _mscnt[_mscnti] - 1.0 >= _mscnt[_mscntj] )
  {
    ++_mscntj;
    while ( _mscntj > 0xFFF )
      _mscntj -= 4096;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406167; symbol: __Z6AddFPSv
void AddFPS()
{
  ++_mscnti;
  FreshFPS();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406182; symbol: __Z9CreateWinllmmmmmPKc
void __cdecl CreateWin(int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int style, const char *winclass)
{
  wchar_t wstr[127]; // [esp+22h] [ebp-106h]

  MultiByteToWideChar(0xFDE9u, 0, winclass, -1, wstr, 127);
  _class = wstr;
  if ( !style )
    style = 282001408;
  _w = w;
  _h = h;
  _x = x;
  _y = y;
  _cbg = cbg;
  _cfg = cfg;
  _style = style;
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)WinInit, 0, 0, 0);
  while ( !IsWin() )
    Sleep(1u);
  SetBkMode(_dc, 1);
  Clear();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406287; symbol: __Z9CreateWinmmmmmPKc
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int style, const char *winclass)
{
  int v6; // ebx
  int v7; // edx

  GetScrHeight();
  v6 = (GetScrHeight() - h) >> 1;
  GetScrWidth();
  v7 = (GetScrWidth() - w) >> 1;
  CreateWin(v7, v6, w, h, cfg, cbg, style, winclass);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004062ED; symbol: __Z9CreateWinmmmmm
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int style)
{
  CreateWin(w, h, cfg, cbg, style, DEFAULTCLASS);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406326; symbol: __Z9CreateWinmmmm
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  CreateWin(w, h, cfg, cbg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406357; symbol: __Z9CreateWinmmm
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int c)
{
  CreateWin(w, h, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406381; symbol: __Z9CreateWinmm
void __cdecl CreateWin(unsigned int w, unsigned int h)
{
  CreateWin(w, h, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004063A4; symbol: __Z9CreateWinm
void __cdecl CreateWin(unsigned int cbg)
{
  int v1; // ebx
  int v2; // edx

  v1 = GetScrHeight() / 2;
  v2 = GetScrWidth() / 2;
  CreateWin(v2, v1, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004063E5; symbol: __Z9CreateWinv
void CreateWin()
{
  int v0; // ebx
  int v1; // eax

  v0 = GetScrHeight() / 2;
  v1 = GetScrWidth();
  CreateWin(v1 / 2, v0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040641D; symbol: __Z8FreshWinv
void FreshWin()
{
  DrawBMP(_pmain, _pmscr);
  AddFPS();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406442; symbol: __Z8CloseWinv
void CloseWin()
{
  SendMessageA(_hw, 0x10u, 0, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406473; symbol: __Z5IsWinv
BOOL IsWin()
{
  return _winb;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040647F; symbol: __Z8GetTimeRv
long double GetTimeR()
{
  LARGE_INTEGER tcount; // [esp+20h] [ebp-18h]
  LARGE_INTEGER tfreq; // [esp+28h] [ebp-10h]

  if ( QueryPerformanceFrequency(&tfreq) != 0 )
    _tfreq = tfreq;
  if ( QueryPerformanceCounter(&tcount) != 0 )
    _tcount = tcount;
  return (double)(tcount.QuadPart - _tbegin.QuadPart) / (double)_tfreq.QuadPart;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040651B; symbol: __Z7GetTimev
signed __int64 GetTime()
{
  return (signed __int64)(GetTimeR() * 1000.0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040654C; symbol: __Z8SetTitlePKc
void __cdecl SetTitle(const char *s)
{
  SetWindowTextA(_hw, s);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040656C; symbol: __Z9SetTitleWPKs
void __cdecl SetTitleW(const __int16 *s)
{
  SetWindowTextW(_hw, (LPCWSTR)s);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040658C; symbol: __Z8GetTitlev
char *GetTitle()
{
  GetWindowTextA(_hw, GetTitle(void)::c, 127);
  return GetTitle(void)::c;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004065B9; symbol: __Z9GetTitleWv
WCHAR *GetTitleW()
{
  GetWindowTextW(_hw, &GetTitleW(void)::c, 127);
  return &GetTitleW(void)::c;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004065E6; symbol: __Z7SetSizellmm
void __cdecl SetSize(int x, int y, unsigned int w, unsigned int h)
{
  RECT rect; // [esp+20h] [ebp-18h]

  rect.left = x;
  rect.top = y;
  rect.right = x + w;
  rect.bottom = y + h;
  AdjustWindowRect(&rect, _style, 0);
  MoveWindow(_hw, x, y, rect.right - rect.left, rect.bottom - rect.top, 1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406674; symbol: __Z7SetSizemm
void __cdecl SetSize(unsigned int w, unsigned int h)
{
  int v2; // ebx
  int v3; // edx

  v2 = GetPosY();
  v3 = GetPosX();
  SetSize(v3, v2, w, h);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004066AA; symbol: __Z8GetWidthv
unsigned int GetWidth()
{
  return _w;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004066B4; symbol: __Z9GetHeightv
unsigned int GetHeight()
{
  return _h;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004066BE; symbol: __Z7GetSizev
unsigned int GetSize()
{
  unsigned int v0; // ebx

  v0 = GetWidth() << 16;
  return v0 + GetHeight();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004066D6; symbol: __Z11GetScrWidthv
int GetScrWidth()
{
  return GetSystemMetrics(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004066ED; symbol: __Z12GetScrHeightv
int GetScrHeight()
{
  return GetSystemMetrics(1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406704; symbol: __Z10GetScrSizev
int GetScrSize()
{
  int v0; // ebx

  v0 = GetScrWidth() << 16;
  return v0 + GetScrHeight();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406722; symbol: __Z11GetScrCapsXv
long double GetScrCapsX()
{
  HWND__ *v0; // eax
  HDC__ *v1; // eax

  v0 = GetDesktopWindow();
  v1 = GetDC(v0);
  return 144.0 / (long double)GetDeviceCaps(v1, 88);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040675B; symbol: __Z11GetScrCapsYv
long double GetScrCapsY()
{
  HWND__ *v0; // eax
  HDC__ *v1; // eax

  v0 = GetDesktopWindow();
  v1 = GetDC(v0);
  return 144.0 / (long double)GetDeviceCaps(v1, 90);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406794; symbol: __Z14GetBorderTitlev
int GetBorderTitle()
{
  return GetSystemMetrics(4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004067AB; symbol: __Z14GetBorderWidthv
int GetBorderWidth()
{
  int result; // eax

  if ( _style & 0x40000 )
    result = GetSystemMetrics(32);
  else
    result = GetSystemMetrics(7);
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004067E1; symbol: __Z15GetBorderHeightv
int GetBorderHeight()
{
  int result; // eax

  if ( _style & 0x40000 )
    result = GetSystemMetrics(33);
  else
    result = GetSystemMetrics(8);
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406817; symbol: __Z13GetBorderSizev
int GetBorderSize()
{
  int v0; // ebx

  v0 = GetBorderWidth() << 16;
  return v0 + GetBorderHeight();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406835; symbol: __Z6SetPosll
void __cdecl SetPos(int x, int y)
{
  SetSize(x, y, _w, _h);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406864; symbol: __Z7GetPosXv
LONG GetPosX()
{
  RECT rt; // [esp+10h] [ebp-18h]

  rt.left = 0;
  rt.top = 0;
  rt.right = 0;
  rt.bottom = 0;
  GetWindowRect(_hw, &rt);
  return rt.left;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004068A2; symbol: __Z7GetPosYv
LONG GetPosY()
{
  RECT rt; // [esp+10h] [ebp-18h]

  rt.left = 0;
  rt.top = 0;
  rt.right = 0;
  rt.bottom = 0;
  GetWindowRect(_hw, &rt);
  return rt.top;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004068E0; symbol: __Z6GetPosv
int GetPos()
{
  LONG v0; // ebx

  v0 = GetPosX() << 16;
  return v0 + GetPosY();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004068FE; symbol: __Z6GetWinv
pbitmap GetWin()
{
  return _pmain;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406908; symbol: __Z6GetScrv
pbitmap GetScr()
{
  return _pmscr;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406912; symbol: __Z7GetHwndP6bitmap
HGDIOBJ __cdecl GetHwnd(pbitmap b)
{
  return b->Handle;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040691C; symbol: __Z7GetHwndv
HWND GetHwnd()
{
  return _hw;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406926; symbol: __Z7GetDrawP6bitmap
HDC __cdecl GetDraw(pbitmap b)
{
  return b->DC;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406931; symbol: __Z7GetDrawv
HDC GetDraw()
{
  return _dc;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040693B; symbol: __Z10GetBGColorv
COLORREF GetBGColor()
{
  return _cbg;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406945; symbol: __Z10SetBGColorm
void __cdecl SetBGColor(unsigned int c)
{
  _cbg = c;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406953; symbol: __Z10GetFGColorv
unsigned int GetFGColor()
{
  return _cfg;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040695D; symbol: __Z10SetFGColorm
void __cdecl SetFGColor(unsigned int c)
{
  _cfg = c;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040696B; symbol: __Z11SetPenWidthm
void __cdecl SetPenWidth(unsigned int pew)
{
  _pew = pew;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406979; symbol: __Z11SetPenColorP6bitmapm
void __cdecl SetPenColor(pbitmap b, unsigned int c)
{
  HPEN__ *v2; // eax

  if ( c != _pec )
  {
    _pec = c;
    DeleteObject(_pe);
    if ( c == 1 )
      v2 = (HPEN__ *)GetStockObject(8);
    else
      v2 = CreatePen(0, _pew, c);
    _pe = v2;
    SelectObject(b->DC, v2);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004069FC; symbol: __Z13SetBrushColorP6bitmapm
void __cdecl SetBrushColor(pbitmap b, unsigned int c)
{
  HBRUSH__ *v2; // eax

  if ( c != _brc )
  {
    _brc = c;
    DeleteObject(_br);
    if ( c == 1 )
      v2 = (HBRUSH__ *)GetStockObject(5);
    else
      v2 = CreateSolidBrush(c);
    _br = v2;
    SelectObject(b->DC, v2);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406A6C; symbol: __Z11SetPenColorm
void __cdecl SetPenColor(unsigned int c)
{
  SetPenColor(_pmain, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406A89; symbol: __Z13SetBrushColorm
void __cdecl SetBrushColor(unsigned int c)
{
  SetBrushColor(_pmain, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406AA6; symbol: __Z6GetRedm
unsigned __int8 __cdecl GetRed(unsigned int c)
{
  return c;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406AAE; symbol: __Z8GetGreenm
unsigned __int8 __cdecl GetGreen(unsigned int c)
{
  return c >> 8;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406AB9; symbol: __Z7GetBluem
unsigned __int8 __cdecl GetBlue(unsigned int c)
{
  return c >> 16;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406AC4; symbol: __Z8GetAlpham
unsigned __int8 __cdecl GetAlpha(unsigned int c)
{
  return c >> 24;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406ACF; symbol: __Z7GetRGBAhhhh
unsigned int __cdecl GetRGBA(unsigned __int8 r, unsigned __int8 g, unsigned __int8 b, unsigned __int8 a)
{
  return (g << 8) | (b << 16) | (a << 24) | r;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406B15; symbol: __Z6GetRGBhhh
unsigned int __cdecl GetRGB(unsigned __int8 r, unsigned __int8 g, unsigned __int8 b)
{
  return GetRGBA(r, g, b, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406B53; symbol: __Z7SetFontP6bitmap
void __cdecl SetFont(pbitmap b)
{
  DeleteObject(_fns);
  _fns = CreateFontA(_fh, _fw, 0, 0, _fwg, _flt, _fud, _fsk, _fcs, 0, 0, 0, 0, _ffn);
  SelectObject(b->DC, _fns);
  if ( !_fh )
  {
    GetTextMetricsA(_dc, &_tm);
    _fh = _tm.tmHeight;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406C4A; symbol: __Z7SetFontv
void SetFont()
{
  SetFont(_pmain);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406C60; symbol: __Z12SetFontWidthm
void __cdecl SetFontWidth(unsigned int w)
{
  _fw = w;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406C76; symbol: __Z13SetFontHeightm
void __cdecl SetFontHeight(unsigned int h)
{
  _fh = h;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406C8C; symbol: __Z11SetFontSizemm
void __cdecl SetFontSize(unsigned int w, unsigned int h)
{
  _fh = h;
  _fw = w;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406CAA; symbol: __Z13SetFontWeightm
void __cdecl SetFontWeight(unsigned int wg)
{
  _fwg = wg;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406CC0; symbol: __Z13SetFontLtalicm
void __cdecl SetFontLtalic(unsigned int lt)
{
  _flt = lt;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406CD6; symbol: __Z16SetFontUnderLinem
void __cdecl SetFontUnderLine(unsigned int ud)
{
  _fud = ud;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406CEC; symbol: __Z16SetFontStrikeOutm
void __cdecl SetFontStrikeOut(unsigned int sk)
{
  _fsk = sk;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406D02; symbol: __Z14SetFontCharSetm
void __cdecl SetFontCharSet(unsigned int cs_0)
{
  _fcs = cs_0;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406D18; symbol: __Z11SetFontNamePKc
void __cdecl SetFontName(const char *s)
{
  strcpy(_ffn, s);
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406D39; symbol: __Z13GetStringSizePKc
void __cdecl GetStringSize(const char *s)
{
  int v1; // eax

  v1 = strlen(s);
  GetTextExtentPoint32A(_dc, s, v1, &_strz);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406D72; symbol: __Z14GetStringWidthPKc
unsigned int __cdecl GetStringWidth(const char *s)
{
  unsigned int result; // eax

  GetStringSize(s);
  if ( _strz.cy <= 0 )
    result = 0;
  else
    result = _strz.cx * _fh / _strz.cy;
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406DB3; symbol: __Z15GetStringHeightPKc
unsigned int __cdecl GetStringHeight(const char *s)
{
  unsigned int result; // eax

  GetStringSize(s);
  if ( _strz.cy <= 0 )
    result = 0;
  else
    result = _strz.cy * _fh / _strz.cy;
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406DF4; symbol: __Z10InitTextXYPP6bitmapPPKsPmS5_
void __cdecl InitTextXY(pbitmap *b, const __int16 **s, unsigned int *cfg, unsigned int *cbg)
{
  if ( !*b )
    *b = _pmain;
  if ( !**s )
    *s = (const __int16 *)" ";
  if ( !*cfg )
    *cfg = 0xFFFFFF;
  SetTextColor((*b)->DC, *cfg);
  if ( *cbg )
  {
    SetBkColor((*b)->DC, *cbg);
    SetBkMode((*b)->DC, 2);
  }
  else
  {
    SetBkMode((*b)->DC, 1);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406EB2; symbol: __Z10InitTextXYPP6bitmapPPKcPmS5_
void __cdecl InitTextXY(pbitmap *b, const char **s, unsigned int *cfg, unsigned int *cbg)
{
  if ( !*b )
    *b = _pmain;
  if ( !**s )
    *s = " ";
  if ( !*cfg )
    *cfg = 0xFFFFFF;
  SetTextColor((*b)->DC, *cfg);
  if ( *cbg )
  {
    SetBkColor((*b)->DC, *cbg);
    SetBkMode((*b)->DC, 2);
  }
  else
  {
    SetBkMode((*b)->DC, 1);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406F6F; symbol: __Z10DrawTextXYP6bitmapPKsllmmmmm
void __cdecl DrawTextXY(pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int format)
{
  int v9; // eax
  RECT lpRect; // [esp+20h] [ebp-18h]

  InitTextXY(&b, &s, &cfg, &cbg);
  lpRect.left = x;
  lpRect.top = y;
  lpRect.right = x + w;
  lpRect.bottom = y + h;
  v9 = wcslen((const wchar_t *)s);
  DrawTextW(b->DC, (LPCWSTR)s, v9, &lpRect, format);
  _fx = x + w;
  _fy = y;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040700A; symbol: __Z10DrawTextXYP6bitmapPKsllmmmm
void __cdecl DrawTextXY(pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  int v8; // eax
  RECT lpRect; // [esp+20h] [ebp-18h]

  InitTextXY(&b, &s, &cfg, &cbg);
  lpRect.left = x;
  lpRect.top = y;
  lpRect.right = x + w;
  lpRect.bottom = y + h;
  v8 = wcslen((const wchar_t *)s);
  DrawTextW(b->DC, (LPCWSTR)s, v8, &lpRect, 0x25u);
  _fx = x + w;
  _fy = y;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004070A6; symbol: __Z10DrawTextXYP6bitmapPKcllmmmm
void __cdecl DrawTextXY(pbitmap b, const char *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  int v8; // eax
  RECT lpRect; // [esp+20h] [ebp-18h]

  InitTextXY(&b, &s, &cfg, &cbg);
  lpRect.left = x;
  lpRect.top = y;
  lpRect.right = x + w;
  lpRect.bottom = y + h;
  v8 = strlen(s);
  DrawTextA(b->DC, s, v8, &lpRect, 0x25u);
  _fx = x + w;
  _fy = y;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407142; symbol: __Z10DrawTextXYP6bitmapPKcllmm
void __cdecl DrawTextXY(pbitmap b, const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  int v6; // eax
  unsigned int v7; // eax

  InitTextXY(&b, &s, &cfg, &cbg);
  v6 = strlen(s);
  TextOutA(b->DC, x, y, s, v6);
  v7 = GetStringWidth(s);
  _fx = v7 + x;
  _fy = y;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004071C1; symbol: __Z10DrawTextXYP6bitmapPKcllm
void __cdecl DrawTextXY(pbitmap b, const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXY(b, s, x, y, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004071F9; symbol: __Z10DrawTextXYPKcllmm
void __cdecl DrawTextXY(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(0, s, x, y, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407231; symbol: __Z10DrawTextXYPKcllm
void __cdecl DrawTextXY(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXY(0, s, x, y, cfg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407262; symbol: __Z10DrawTextXYPKclm
void __cdecl DrawTextXY(const char *s, int x, unsigned int y)
{
  DrawTextXY(s, x, y, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040728C; symbol: __Z9DrawTextAPKcmm
void __cdecl DrawTextA(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(s, _fx, _fy, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004072C1; symbol: __Z9DrawTextAPKcm
void __cdecl DrawTextA(const char *s, unsigned int cfg)
{
  DrawTextA(s, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004072E4; symbol: __Z9DrawTextAPKc
void __cdecl DrawTextA(const char *s)
{
  DrawTextA(s, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407300; symbol: __Z12DrawTextlnXYPKcllmm
void __cdecl DrawTextlnXY(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(s, x, y, cfg, cbg);
  _fx = x;
  _fy = GetStringHeight(s) + y;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040734F; symbol: __Z12DrawTextlnXYPKcllm
void __cdecl DrawTextlnXY(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextlnXY(s, x, y, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407380; symbol: __Z12DrawTextlnXYPKclm
void __cdecl DrawTextlnXY(const char *s, int x, unsigned int y)
{
  DrawTextlnXY(s, x, y, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004073AA; symbol: __Z10DrawTextlnPKcmm
void __cdecl DrawTextln(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextlnXY(s, _fx, _fy, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004073DF; symbol: __Z10DrawTextlnPKcm
void __cdecl DrawTextln(const char *s, unsigned int cfg)
{
  DrawTextln(s, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407402; symbol: __Z10DrawTextlnPKc
void __cdecl DrawTextln(const char *s)
{
  DrawTextln(s, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040741E; symbol: __Z10DrawTextlnv
void DrawTextln()
{
  DrawTextln(s);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407433; symbol: __Z11DrawTextXYwP6bitmapPKcllmm
void __cdecl DrawTextXYw(pbitmap b, const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  unsigned int fi; // [esp+2Ch] [ebp-Ch]

  InitTextXY(&b, &s, &cfg, &cbg);
  for ( fi = 0; strlen(s) > fi; ++fi )
  {
    TextOutA(b->DC, x, y, &s[fi], 1);
    x += _fw;
  }
  _fx = x;
  _fy = y;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004074C9; symbol: __Z11DrawTextXYwP6bitmapPKcllm
void __cdecl DrawTextXYw(pbitmap b, const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXYw(b, s, x, y, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407501; symbol: __Z11DrawTextXYwPKcllmm
void __cdecl DrawTextXYw(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(0, s, x, y, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407539; symbol: __Z11DrawTextXYwPKcllm
void __cdecl DrawTextXYw(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXYw(0, s, x, y, cfg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040756A; symbol: __Z11DrawTextXYwPKclm
void __cdecl DrawTextXYw(const char *s, int x, unsigned int y)
{
  DrawTextXYw(s, x, y, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407594; symbol: __Z9DrawTextwPKcmm
void __cdecl DrawTextw(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(s, _fx, _fy, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004075C9; symbol: __Z9DrawTextwPKcm
void __cdecl DrawTextw(const char *s, unsigned int cfg)
{
  DrawTextw(s, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004075EC; symbol: __Z9DrawTextwPKc
void __cdecl DrawTextw(const char *s)
{
  DrawTextw(s, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407608; symbol: __Z13DrawTextlnXYwPKcllmm
void __cdecl DrawTextlnXYw(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(s, x, y, cfg, cbg);
  _fx = x;
  _fy = y + _fh;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040764F; symbol: __Z13DrawTextlnXYwPKcllm
void __cdecl DrawTextlnXYw(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextlnXYw(s, x, y, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407680; symbol: __Z13DrawTextlnXYwPKclm
void __cdecl DrawTextlnXYw(const char *s, int x, unsigned int y)
{
  DrawTextlnXYw(s, x, y, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004076AA; symbol: __Z11DrawTextlnwPKcmm
void __cdecl DrawTextlnw(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextlnXYw(s, _fx, _fy, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004076DF; symbol: __Z11DrawTextlnwPKcm
void __cdecl DrawTextlnw(const char *s, unsigned int cfg)
{
  DrawTextlnw(s, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407702; symbol: __Z11DrawTextlnwPKc
void __cdecl DrawTextlnw(const char *s)
{
  DrawTextlnw(s, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040771E; symbol: __Z8GetPixelP6bitmapmm
unsigned int __cdecl GetPixel(pbitmap b, unsigned int x, unsigned int y)
{
  if ( !b )
    b = _pmain;
  return GetPixel(b->DC, x, y);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407753; symbol: __Z8GetPixelmm
unsigned int __cdecl GetPixel(unsigned int x, unsigned int y)
{
  return GetPixel(0, x, y);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407775; symbol: __Z8SetPixelP6bitmapmmm
void __cdecl SetPixel(pbitmap b, unsigned int x, unsigned int y, unsigned int c)
{
  if ( !b )
    b = _pmain;
  if ( !c )
    c = _cfg;
  SetPixel(b->DC, x, y, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004077C4; symbol: __Z8SetPixelmmm
void __cdecl SetPixel(unsigned int x, unsigned int y, unsigned int c)
{
  SetPixel(0, x, y, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004077EE; symbol: __Z8SetPixelmm
void __cdecl SetPixel(unsigned int x, unsigned int y)
{
  SetPixel(x, y, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407811; symbol: __Z4LineP6bitmapllllm
void __cdecl Line(pbitmap b, int x, int y, int w, int h, unsigned int c)
{
  if ( !b )
    b = _pmain;
  if ( !c )
    c = _cfg;
  SetPenColor(b, c);
  MoveToEx(b->DC, x, y, 0);
  LineTo(b->DC, w + x, y + h);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407899; symbol: __Z4Linellllm
void __cdecl Line(int x, int y, int w, int h, unsigned int c)
{
  Line(0, x, y, w, h, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004078D1; symbol: __Z3BarP6bitmapllllmm
void __cdecl Bar(pbitmap b, int x, int y, int w, int h, unsigned int cfg, unsigned int cbg)
{
  RECT lpRect; // [esp+10h] [ebp-18h]

  if ( !b )
    b = _pmain;
  if ( !cfg )
    cfg = 1;
  if ( !cbg )
    cbg = _cfg;
  lpRect.left = x;
  lpRect.top = y;
  lpRect.right = x + w;
  lpRect.bottom = y + h;
  if ( cbg != 1 )
  {
    SetBrushColor(b, cbg);
    FillRect(b->DC, &lpRect, _br);
  }
  if ( cfg != 1 )
  {
    SetBrushColor(b, cfg);
    SetPenColor(b, cfg);
    FrameRect(b->DC, &lpRect, (HBRUSH)_pe);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004079AB; symbol: __Z3BarP6bitmapllllm
void __cdecl Bar(pbitmap b, int x, int y, int w, int h, unsigned int c)
{
  Bar(b, x, y, w, h, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004079EA; symbol: __Z3Barllllmm
void __cdecl Bar(int x, int y, int w, int h, unsigned int cfg, unsigned int cbg)
{
  Bar(0, x, y, w, h, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407A29; symbol: __Z3Barllllm
void __cdecl Bar(int x, int y, int w, int h, unsigned int c)
{
  Bar(x, y, w, h, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407A61; symbol: __Z3Barllll
void __cdecl Bar(int x, int y, int w, int h)
{
  Bar(x, y, w, h, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407A92; symbol: __Z5ClearP6bitmapm
void __cdecl Clear(pbitmap b, unsigned int c)
{
  if ( !b )
    b = _pmain;
  if ( !c )
    c = _cbg;
  Bar(b, 0, 0, b->Width, b->Height, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407AF9; symbol: __Z5ClearP6bitmap
void __cdecl Clear(pbitmap b)
{
  Clear(b, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407B15; symbol: __Z5Clearm
void __cdecl Clear(unsigned int c)
{
  Clear(0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407B31; symbol: __Z5Clearv
void Clear()
{
  Clear(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407B46; symbol: __Z9CreateBMPP6bitmapmmm
pbitmap __cdecl CreateBMP(pbitmap b, unsigned int w, unsigned int h, unsigned int c)
{
  pbitmap bmp; // [esp+1Ch] [ebp-Ch]

  if ( !b )
    b = GetWin();
  if ( !w )
    w = b->Width;
  if ( !h )
    h = b->Height;
  if ( !c )
    c = b->Color;
  bmp = (pbitmap)calloc(1u, 0x14u);
  bmp->Width = w;
  bmp->Height = h;
  bmp->Color = c;
  while ( !bmp->DC )
    bmp->DC = CreateCompatibleDC(_dc);
  while ( !bmp->Handle )
    bmp->Handle = CreateCompatibleBitmap(_dc, bmp->Width, bmp->Height);
  SelectObject(bmp->DC, bmp->Handle);
  Clear(bmp, c);
  return bmp;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407C48; symbol: __Z9CreateBMPP6bitmap
pbitmap __cdecl CreateBMP(pbitmap b)
{
  return CreateBMP(b, 0, 0, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407C73; symbol: __Z9CreateBMPmmm
pbitmap __cdecl CreateBMP(unsigned int w, unsigned int h, unsigned int c)
{
  return CreateBMP(0, w, h, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407C9C; symbol: __Z9CreateBMPmm
pbitmap __cdecl CreateBMP(unsigned int w, unsigned int h)
{
  return CreateBMP(w, h, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407CBE; symbol: __Z9CreateBMPv
pbitmap CreateBMP()
{
  return CreateBMP(0, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407CDA; symbol: __Z10ReleaseBMPP6bitmap
void __cdecl ReleaseBMP(pbitmap b)
{
  if ( b )
  {
    if ( b->DC == _dc )
      ReleaseDC(_hw, b->DC);
    if ( b->DC != _dc )
      DeleteDC(b->DC);
    if ( b->Handle != _hw )
      DeleteObject(b->Handle);
    if ( b != _pmscr )
      free(b);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407D65; symbol: __Z10ReleaseBMPv
void ReleaseBMP()
{
  bitmap *v0; // eax
  bitmap *v1; // eax

  v0 = GetScr();
  ReleaseBMP(v0);
  v1 = GetWin();
  ReleaseBMP(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407FDD; symbol: __Z7DrawBMPP6bitmapS0_mmmmmmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  pbitmap bm; // ST58_4
  BLENDFUNCTION ST54_4_17; // ST54_4
  unsigned __int8 alpha; // [esp+5Ch] [ebp-1Ch]
  unsigned int ca; // [esp+A8h] [ebp+30h]

  if ( !bs )
    bs = GetWin();
  if ( !bd )
    bd = GetWin();
  if ( !ws )
    ws = bs->Width;
  if ( !hs )
    hs = bs->Height;
  if ( !wd )
    wd = bs->Width;
  if ( !hd )
    hd = bs->Height;
  if ( !c )
    c = bs->Color;
  alpha = GetAlpha(c);
  ca = c & 0xFFFFFF;
  if ( alpha )
  {
    bm = CreateBMP(wd, hd, ca);
    StretchBlt(bm->DC, 0, 0, wd, hd, bd->DC, xd, yd, wd, hd, 0xCC0020u);
    TransparentBlt(bm->DC, 0, 0, wd, hd, bs->DC, xs, ys, ws, hs, ca);
    *(_WORD *)&ST54_4_17.BlendOp = 0;
    *(_WORD *)&ST54_4_17.SourceConstantAlpha = (unsigned __int8)~alpha;
    AlphaBlend(bd->DC, xd, yd, wd, hd, bm->DC, 0, 0, wd, hd, ST54_4_17);
    ReleaseBMP(bm);
  }
  else
  {
    TransparentBlt(bd->DC, xd, yd, wd, hd, bs->DC, xs, ys, ws, hs, ca);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040826C; symbol: __Z7DrawBMPP6bitmapS0_mmmmmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, bd, xs, ys, ws, hs, xd, yd, wd, hd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004082C7; symbol: __Z7DrawBMPP6bitmapS0_mmmmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(bs, bd, xs, ys, w, h, xd, yd, w, h, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408321; symbol: __Z7DrawBMPP6bitmapS0_mmmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(bs, bd, xs, ys, xd, yd, w, h, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040836E; symbol: __Z7DrawBMPP6bitmapS0_mmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, bd, 0, 0, 0, 0, xd, yd, wd, hd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004083CC; symbol: __Z7DrawBMPP6bitmapS0_mmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, bd, xd, yd, wd, hd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040840B; symbol: __Z7DrawBMPP6bitmapS0_mmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(bs, bd, xd, yd, 0, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040844B; symbol: __Z7DrawBMPP6bitmapS0_mm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd)
{
  DrawBMP(bs, bd, xd, yd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040847C; symbol: __Z7DrawBMPP6bitmapS0_m
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int c)
{
  DrawBMP(bs, bd, 0, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004084AE; symbol: __Z7DrawBMPP6bitmapS0_
void __cdecl DrawBMP(pbitmap bs, pbitmap bd)
{
  DrawBMP(bs, bd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004084D1; symbol: __Z7DrawBMPP6bitmapmmmmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, 0, xs, ys, ws, hs, xd, yd, wd, hd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040852C; symbol: __Z7DrawBMPP6bitmapmmmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, xs, ys, ws, hs, xd, yd, wd, hd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408580; symbol: __Z7DrawBMPP6bitmapmmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(bs, xs, ys, w, h, xd, yd, w, h, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004085D3; symbol: __Z7DrawBMPP6bitmapmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(bs, xs, ys, xd, yd, w, h, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408619; symbol: __Z7DrawBMPP6bitmapmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, 0, 0, 0, 0, xd, yd, wd, hd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408670; symbol: __Z7DrawBMPP6bitmapmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, xd, yd, wd, hd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004086A8; symbol: __Z7DrawBMPP6bitmapmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(bs, xd, yd, 0, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004086E1; symbol: __Z7DrawBMPP6bitmapmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd)
{
  DrawBMP(bs, xd, yd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040870B; symbol: __Z7DrawBMPP6bitmapm
void __cdecl DrawBMP(pbitmap bs, unsigned int c)
{
  DrawBMP(bs, 0, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408736; symbol: __Z7DrawBMPP6bitmap
void __cdecl DrawBMP(pbitmap bs)
{
  DrawBMP(bs, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408752; symbol: __Z7DrawBMPmmmmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(0, xs, ys, ws, hs, xd, yd, wd, hd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004087A6; symbol: __Z7DrawBMPmmmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(0, xs, ys, ws, hs, xd, yd, wd, hd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004087F3; symbol: __Z7DrawBMPmmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(0, xs, ys, xd, yd, w, h, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408839; symbol: __Z7DrawBMPmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(0, xs, ys, xd, yd, w, h);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408878; symbol: __Z7DrawBMPmmmmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(0, xd, yd, wd, hd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004088B0; symbol: __Z7DrawBMPmmmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(0, xd, yd, wd, hd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004088E1; symbol: __Z7DrawBMPmmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(0, xd, yd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040890B; symbol: __Z7DrawBMPmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd)
{
  DrawBMP(0, xd, yd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040892E; symbol: __Z7DrawBMPm
void __cdecl DrawBMP(unsigned int c)
{
  DrawBMP(0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040894A; symbol: __Z7DrawBMPv
void DrawBMP()
{
  DrawBMP(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040895F; symbol: __Z2HIy
unsigned int __cdecl HI(uint64_t val)
{
  return HIDWORD(val);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040897D; symbol: __Z2LOy
unsigned int __cdecl LO(uint64_t val)
{
  return val;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408994; symbol: __Z7SendMsgv
void SendMsg()
{
  TranslateMessage(&_mst);
  DispatchMessageA(&_mst);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004089BB; symbol: __Z9CustomMsgv
BOOL CustomMsg()
{
  MSG *v0; // eax
  bool result; // [esp+Fh] [ebp-1h]

  result = _msusr[_msi].message != 0;
  if ( result )
  {
    v0 = &_msusr[_msi];
    _ms.hwnd = v0->hwnd;
    _ms.message = v0->message;
    _ms.wParam = v0->wParam;
    _ms.lParam = v0->lParam;
    _ms.time = v0->time;
    _ms.pt.x = v0->pt.x;
    _ms.pt.y = v0->pt.y;
    _msusr[_msi++].message = 0;
    if ( _msi > 0x1000 )
      _msi = 1;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408A68; symbol: __Z9IsNextMsgv
signed int IsNextMsg()
{
  MSG *v0; // eax
  MSG *v1; // eax
  bool result; // [esp+Fh] [ebp-1h]

  if ( !((unsigned __int8)CustomMsg() ^ 1) )
    return 1;
  result = _mswini != _mswinj;
  if ( _mswini != _mswinj )
  {
    _mswinj = ((_WORD)_mswinj + 1) & 0xFFF;
    v0 = &_mswin[_mswinj];
    _ms.hwnd = v0->hwnd;
    _ms.message = v0->message;
    _ms.wParam = v0->wParam;
    _ms.lParam = v0->lParam;
    _ms.time = v0->time;
    _ms.pt.x = v0->pt.x;
    _ms.pt.y = v0->pt.y;
    while ( !_ms.message )
    {
      v1 = &_mswin[_mswinj];
      _ms.hwnd = v1->hwnd;
      _ms.message = v1->message;
      _ms.wParam = v1->wParam;
      _ms.lParam = v1->lParam;
      _ms.time = v1->time;
      _ms.pt.x = v1->pt.x;
      _ms.pt.y = v1->pt.y;
    }
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408B62; symbol: __Z10GetNextMsgv
UINT GetNextMsg()
{
  return _ms.message;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408B6C; symbol: __Z11WaitNextMsgv
UINT WaitNextMsg()
{
  char v0; // al

  if ( (unsigned __int8)CustomMsg() ^ 1 )
  {
    while ( 1 )
    {
      v0 = (unsigned __int8)IsNextMsg() ^ 1 && (unsigned __int8)IsWin() ? 1 : 0;
      if ( !v0 )
        break;
      Sleep(1u);
    }
  }
  return GetNextMsg();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408BBB; symbol: __Z5IsMsgPKmm
bool __cdecl IsMsg(const unsigned int *uM, unsigned int length)
{
  unsigned int mi; // [esp+Ch] [ebp-4h]

  for ( mi = 0; mi < length; ++mi )
  {
    if ( _ms.message == uM[mi] )
      return 1;
  }
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408BFF; symbol: __Z6GetMsgPKmm
uint64_t __cdecl GetMsg(const unsigned int *uM, unsigned int length)
{
  LPARAM v2; // ebx
  WPARAM v3; // esi

  if ( IsMsg(uM, length) )
  {
    v2 = _ms.lParam;
    v3 = (_ms.lParam >> 31) | _ms.wParam;
  }
  else
  {
    v2 = 0;
    v3 = 0;
  }
  return __PAIR__(v3, v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408C5F; symbol: __Z7WaitMsgPKmm
uint64_t __cdecl WaitMsg(const unsigned int *uM, unsigned int length)
{
  do
    WaitNextMsg();
  while ( !IsMsg(uM, length) );
  return GetMsg(uM, length);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408C99; symbol: __Z5IsMsgm
bool __cdecl IsMsg(unsigned int uM)
{
  unsigned int ums[1]; // [esp+14h] [ebp-4h]

  ums[0] = uM;
  return IsMsg(ums, 1u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408CBA; symbol: __Z6GetMsgm
uint64_t __cdecl GetMsg(unsigned int uM)
{
  unsigned int ums[1]; // [esp+14h] [ebp-4h]

  ums[0] = uM;
  return GetMsg(ums, 1u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408CDB; symbol: __Z7WaitMsgm
uint64_t __cdecl WaitMsg(unsigned int uM)
{
  unsigned int ums[1]; // [esp+1Ch] [ebp-Ch]

  ums[0] = uM;
  return WaitMsg(ums, 1u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408CFC; symbol: __Z5IsKeym
bool __cdecl IsKey(unsigned int k)
{
  return IsMsg(0x100u) && (!k || GetKey() == k);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408D30; symbol: __Z5IsKeyv
bool IsKey()
{
  return IsKey(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408D44; symbol: __Z6GetKeyv
unsigned int GetKey()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x100u);
  return HI(v0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408D64; symbol: __Z7WaitKeym
unsigned int __cdecl WaitKey(unsigned int k)
{
  while ( !IsKey() )
    WaitNextMsg();
  return GetKey();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408D84; symbol: __Z7WaitKeyv
unsigned int WaitKey()
{
  return WaitKey(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408D98; symbol: __Z7IsMousem
bool __cdecl IsMouse(unsigned int m)
{
  return IsMsg(_bdn, 3u) && (!m || GetMouse() == m);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408DD4; symbol: __Z7IsMousev
bool IsMouse()
{
  return IsMouse(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408DE8; symbol: __Z8GetMousev
unsigned int GetMouse()
{
  uint64_t v0; // rax

  v0 = GetMsg(_bdn, 3u);
  return HI(v0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E10; symbol: __Z9WaitMousem
unsigned int __cdecl WaitMouse(unsigned int m)
{
  while ( !IsMouse() )
    WaitNextMsg();
  return GetMouse();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E30; symbol: __Z9WaitMousev
unsigned int WaitMouse()
{
  return WaitMouse(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E44; symbol: __Z11IsMouseLeftv
bool IsMouseLeft()
{
  return IsMsg(0x201u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E58; symbol: __Z13WaitMouseLeftv
void WaitMouseLeft()
{
  WaitMsg(0x201u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E6D; symbol: __Z13IsMouseMiddlev
bool IsMouseMiddle()
{
  return IsMsg(0x207u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E81; symbol: __Z15WaitMouseMiddlev
void WaitMouseMiddle()
{
  WaitMsg(0x207u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E96; symbol: __Z12IsMouseRightv
bool IsMouseRight()
{
  return IsMsg(0x204u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408EAA; symbol: __Z14WaitMouseRightv
void WaitMouseRight()
{
  WaitMsg(0x204u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408EBF; symbol: __Z12IsMouseWheelv
bool IsMouseWheel()
{
  return IsMsg(0x20Au);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408ED3; symbol: __Z13GetMouseWheelv
unsigned int GetMouseWheel()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x20Au);
  return HI(v0) >> 16;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408EF9; symbol: __Z14WaitMouseWheelv
void WaitMouseWheel()
{
  WaitMsg(0x20Au);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F0E; symbol: __Z11IsMouseMovev
bool IsMouseMove()
{
  return IsMsg(0x200u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F22; symbol: __Z12GetMouseMovev
unsigned int GetMouseMove()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x200u);
  return LO(v0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F42; symbol: __Z13WaitMouseMovev
unsigned int WaitMouseMove()
{
  uint64_t v0; // rax

  v0 = WaitMsg(0x200u);
  return LO(v0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F62; symbol: __Z10IsDropFilev
bool IsDropFile()
{
  return IsMsg(0x233u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F76; symbol: __Z12GetMouseAbsXv
LONG GetMouseAbsX()
{
  POINT p; // [esp+18h] [ebp-10h]

  GetCursorPos(&p);
  return p.x;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F8F; symbol: __Z12GetMouseAbsYv
LONG GetMouseAbsY()
{
  POINT p; // [esp+18h] [ebp-10h]

  GetCursorPos(&p);
  return p.y;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408FA8; symbol: __Z12GetMouseWinXv
int GetMouseWinX()
{
  LONG v0; // ebx

  v0 = GetMouseAbsX();
  return v0 - GetPosX();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408FC5; symbol: __Z12GetMouseWinYv
int GetMouseWinY()
{
  LONG v0; // ebx

  v0 = GetMouseAbsY();
  return v0 - GetPosY();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408FE2; symbol: __Z12GetMousePosXv
int GetMousePosX()
{
  int v0; // ebx
  int v1; // eax

  v0 = GetMouseWinX();
  if ( (_style & 0x80000000) != 0 )
    v1 = 0;
  else
    v1 = GetBorderWidth();
  return v0 - v1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040900F; symbol: __Z12GetMousePosYv
int GetMousePosY()
{
  int v0; // ebx
  int v1; // esi
  int v2; // eax

  v0 = GetMouseWinY();
  if ( (_style & 0x80000000) != 0 )
  {
    v2 = 0;
  }
  else
  {
    v1 = GetBorderHeight();
    v2 = v1 + GetBorderTitle();
  }
  return v0 - v2;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409041; symbol: __Z7MsgBoxWPKsS0_m
unsigned int __cdecl MsgBoxW(const __int16 *s, const __int16 *title, unsigned int i)
{
  return MessageBoxW(0, (LPCWSTR)s, (LPCWSTR)title, i);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040906D; symbol: __Z6MsgBoxPKcS0_m
unsigned int __cdecl MsgBox(const char *s, const char *title, unsigned int i)
{
  return MessageBoxA(0, s, title, i);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409099; symbol: __Z7MsgBoxWPKsS0_
void __cdecl MsgBoxW(const __int16 *s, const __int16 *title)
{
  MsgBoxW(s, title, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004090BC; symbol: __Z6MsgBoxPKcS0_
void __cdecl MsgBox(const char *s, const char *title)
{
  MsgBox(s, title, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004090DF; symbol: __Z7MsgBoxWPKs
void __cdecl MsgBoxW(const __int16 *s)
{
  MsgBoxW(s, &title);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004090FB; symbol: __Z6MsgBoxPKc
void __cdecl MsgBox(const char *s)
{
  MsgBox(s, ::s);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409117; symbol: __Z5Delaym
void __cdecl Delay(unsigned int t)
{
  Sleep(t);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040912E; symbol: __Z5Delayv
void Delay()
{
  Delay(1u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 Windows MCI 音频/音乐接口。
// Address: 0x00409143; symbol: __Z10SendStringv
unsigned int SendString()
{
  mciSendStringA(command_in, command_out, 0x7Fu, 0);
  return strtoul(command_out, 0, 10);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004091F3; symbol: __Z9PlayAudiomPKcb
void __cdecl PlayAudio(unsigned int id, const char *s, bool b)
{
  const char *v3; // edx

  if ( b )
    v3 = "play s%lu%s wait repeat";
  else
    v3 = "play s%lu%s";
  sprintf(command_in, v3, id, s);
  SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409237; symbol: __Z9StopAudiom
void __cdecl StopAudio(unsigned int id)
{
  SetAudioPos(id, 0, 0);
  sprintf(command_in, "stop s%lu", id);
  SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040927B; symbol: __Z10PauseAudiom
void __cdecl PauseAudio(unsigned int id)
{
  sprintf(command_in, "pause s%lu", id);
  SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004092A4; symbol: __Z11ResumeAudiom
void __cdecl ResumeAudio(unsigned int id)
{
  sprintf(command_in, "resume s%lu", id);
  SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004092CD; symbol: __Z12ReleaseAudiom
void __cdecl ReleaseAudio(unsigned int id)
{
  sprintf(command_in, "close s%lu", id);
  SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004092F6; symbol: __Z11GetAudioPosm
unsigned int __cdecl GetAudioPos(unsigned int id)
{
  sprintf(command_in, "status s%lu position", id);
  return SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040931E; symbol: __Z11SetAudioPosmmb
void __cdecl SetAudioPos(unsigned int id, unsigned int pos, bool b)
{
  sprintf(command_in, "seek s%lu to %lu", id, pos);
  SendString();
  PlayAudio(id, s, b);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040936F; symbol: __Z11GetAudioLenm
unsigned int __cdecl GetAudioLen(unsigned int id)
{
  sprintf(command_in, "status s%lu length", id);
  return SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409397; symbol: __Z6IsFilePKc
bool __cdecl IsFile(const char *s)
{
  WIN32_FIND_DATA fd; // [esp+18h] [ebp-150h]
  bool result; // [esp+15Bh] [ebp-Dh]
  HANDLE fh; // [esp+15Ch] [ebp-Ch]

  fh = FindFirstFileA(s, &fd);
  result = (char *)fh + 1 != 0;
  if ( result )
    FindClose(fh);
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004093DF; symbol: __Z13UTF8ToUnicodePhPj
uint8_t __cdecl UTF8ToUnicode(uint8_t *utf8, uint32_t *unicode)
{
  uint8_t result; // al
  const uint8_t mask_lut[3]; // [esp+Dh] [ebp-13h]
  const uint8_t range_lut[3]; // [esp+10h] [ebp-10h]
  const uint8_t length_lut[3]; // [esp+13h] [ebp-Dh]
  byte b; // [esp+16h] [ebp-Ah]
  const uint8_t lut_size; // [esp+17h] [ebp-9h]
  uint32_t i; // [esp+18h] [ebp-8h]
  uint8_t length; // [esp+1Fh] [ebp-1h]

  lut_size = 3;
  length_lut[0] = 2;
  length_lut[1] = 3;
  length_lut[2] = 4;
  range_lut[0] = -32;
  range_lut[1] = -16;
  range_lut[2] = -8;
  mask_lut[0] = 31;
  mask_lut[1] = 15;
  mask_lut[2] = 7;
  length = 0;
  b = *utf8;
  i = 0;
  if ( utf8 )
  {
    if ( (signed int)b > 127 )
    {
      if ( (signed int)b > 191 && (signed int)b <= 253 )
      {
        for ( i = 0; i <= 2; ++i )
        {
          if ( b < (signed int)range_lut[i] )
          {
            *unicode = (unsigned __int8)(b & mask_lut[i]);
            length = length_lut[i];
            break;
          }
        }
        if ( length )
        {
          for ( i = 1; length > i; ++i )
          {
            b = utf8[i];
            if ( (signed int)b <= 127 || (signed int)b > 191 )
              break;
            *unicode <<= 6;
            *unicode |= b & 0x3F;
          }
          if ( length > i )
            result = 1;
          else
            result = length;
        }
        else
        {
          *unicode = 0;
          result = 1;
        }
      }
      else
      {
        *unicode = 0;
        result = 1;
      }
    }
    else
    {
      *unicode = b;
      result = 1;
    }
  }
  else
  {
    *unicode = 0;
    result = 1;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409554; symbol: __Z14UnicodeToUTF16jPt
uint8_t __cdecl UnicodeToUTF16(uint32_t unicode, uint16_t *utf16)
{
  uint8_t result; // al

  if ( unicode > 0xFFFF )
  {
    if ( unicode > 0xEFFFF )
    {
      result = 0;
    }
    else
    {
      if ( utf16 )
      {
        *utf16 = (unicode >> 10) - 10304;
        utf16[1] = (unicode & 0x3FF) - 9216;
      }
      result = 2;
    }
  }
  else
  {
    if ( utf16 )
      *utf16 = unicode;
    result = 1;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004095BD; symbol: __Z41__static_initialization_and_destruction_0ii
void __cdecl __static_initialization_and_destruction_0(int __initialize_p, int __priority)
{
  BOOL v2; // [esp+Ch] [ebp-Ch]

  if ( __initialize_p == 1 && __priority == 0xFFFF )
    weak___ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii___ZN7Gdiplus11GdiplusBasedlEPv(0, 0, 0, v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004095F9; symbol: __GLOBAL__sub_I_version
void _GLOBAL__sub_I_version()
{
  __static_initialization_and_destruction_0(1, 0xFFFF);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x0040C283; symbol: __ZL7getleadPv@4
DWORD __stdcall getlead(LPVOID p)
{
  Steam *const v2; // ST00_4
  Window *const v3; // ST00_4
  Window *v4; // [esp+0h] [ebp-18h]

  if ( !*((_BYTE *)p + 3382) )
  {
    *((_BYTE *)p + 3382) = 1;
    Window::paintevent(v4);
    Steam::getlead(v2);
    Window::paintevent(v3);
    *((_BYTE *)p + 3382) = 0;
  }
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423184; symbol: _timeEndPeriod@4
MMRESULT __stdcall timeEndPeriod(UINT uPeriod)
{
  return timeEndPeriod(uPeriod);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042318C; symbol: _timeBeginPeriod@4
MMRESULT __stdcall timeBeginPeriod(UINT uPeriod)
{
  return timeBeginPeriod(uPeriod);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x0042319C; symbol: _GdiplusStartup@12
int __stdcall GdiplusStartup(int a1, int a2, int a3)
{
  return GdiplusStartup(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231A4; symbol: _GdiplusShutdown@4
int __stdcall GdiplusShutdown(int a1)
{
  return GdiplusShutdown(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231BC; symbol: _GdipGetImageWidth@8
int __stdcall GdipGetImageWidth(int a1, int a2)
{
  return GdipGetImageWidth(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231C4; symbol: _GdipGetImageHeight@8
int __stdcall GdipGetImageHeight(int a1, int a2)
{
  return GdipGetImageHeight(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231CC; symbol: _GdipFree@4
int __stdcall GdipFree(int a1)
{
  return GdipFree(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231D4; symbol: _GdipDrawImageRect@24
int __stdcall GdipDrawImageRect(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return GdipDrawImageRect(a1, a2, a3, a4, a5, a6);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231DC; symbol: _GdipDisposeImage@4
int __stdcall GdipDisposeImage(int a1)
{
  return GdipDisposeImage(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231E4; symbol: _GdipDeletePrivateFontCollection@4
int __stdcall GdipDeletePrivateFontCollection(int a1)
{
  return GdipDeletePrivateFontCollection(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231EC; symbol: _GdipDeleteGraphics@4
int __stdcall GdipDeleteGraphics(int a1)
{
  return GdipDeleteGraphics(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231F4; symbol: _GdipDeleteCustomLineCap@4
int __stdcall GdipDeleteCustomLineCap(int a1)
{
  return GdipDeleteCustomLineCap(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231FC; symbol: _GdipDeleteCachedBitmap@4
int __stdcall GdipDeleteCachedBitmap(int a1)
{
  return GdipDeleteCachedBitmap(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00423204; symbol: _GdipCreateFromHDC@8
int __stdcall GdipCreateFromHDC(int a1, int a2)
{
  return GdipCreateFromHDC(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x0042320C; symbol: _GdipCreateBitmapFromHBITMAP@12
int __stdcall GdipCreateBitmapFromHBITMAP(int a1, int a2, int a3)
{
  return GdipCreateBitmapFromHBITMAP(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00423214; symbol: _GdipCloneImage@8
int __stdcall GdipCloneImage(int a1, int a2)
{
  return GdipCloneImage(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x0042321C; symbol: _GdipAlloc@4
int __stdcall GdipAlloc(int a1)
{
  return GdipAlloc(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423224; symbol: _TextOutA@20
BOOL __stdcall TextOutA(HDC a1, int a2, int a3, LPCSTR a4, int a5)
{
  return TextOutA(a1, a2, a3, a4, a5);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042322C; symbol: _StretchBlt@44
BOOL __stdcall StretchBlt(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, DWORD a11)
{
  return StretchBlt(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423234; symbol: _SetTextColor@8
COLORREF __stdcall SetTextColor(HDC a1, COLORREF a2)
{
  return SetTextColor(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042323C; symbol: _SetPixel@16
COLORREF __stdcall SetPixel(HDC a1, int a2, int a3, COLORREF a4)
{
  return SetPixel(a1, a2, a3, a4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423244; symbol: _SetBkMode@8
int __stdcall SetBkMode(HDC a1, int a2)
{
  return SetBkMode(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042324C; symbol: _SetBkColor@8
COLORREF __stdcall SetBkColor(HDC a1, COLORREF a2)
{
  return SetBkColor(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423254; symbol: _SelectObject@8
HGDIOBJ __stdcall SelectObject(HDC a1, HGDIOBJ a2)
{
  return SelectObject(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042325C; symbol: _MoveToEx@16
BOOL __stdcall MoveToEx(HDC a1, int a2, int a3, LPPOINT a4)
{
  return MoveToEx(a1, a2, a3, a4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423264; symbol: _LineTo@12
BOOL __stdcall LineTo(HDC a1, int a2, int a3)
{
  return LineTo(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042326C; symbol: _GetTextMetricsA@8
BOOL __stdcall GetTextMetricsA(HDC a1, LPTEXTMETRICA a2)
{
  return GetTextMetricsA(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423274; symbol: _GetTextExtentPoint32A@16
BOOL __stdcall GetTextExtentPoint32A(HDC a1, LPCSTR a2, int a3, LPSIZE a4)
{
  return GetTextExtentPoint32A(a1, a2, a3, a4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042327C; symbol: _GetStockObject@4
HGDIOBJ __stdcall GetStockObject(int a1)
{
  return GetStockObject(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423284; symbol: _GetPixel@12
COLORREF __stdcall GetPixel(HDC a1, int a2, int a3)
{
  return GetPixel(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042328C; symbol: _GetDeviceCaps@8
int __stdcall GetDeviceCaps(HDC a1, int a2)
{
  return GetDeviceCaps(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423294; symbol: _DeleteObject@4
BOOL __stdcall DeleteObject(HGDIOBJ a1)
{
  return DeleteObject(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042329C; symbol: _DeleteDC@4
BOOL __stdcall DeleteDC(HDC a1)
{
  return DeleteDC(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232A4; symbol: _CreateSolidBrush@4
HBRUSH __stdcall CreateSolidBrush(COLORREF a1)
{
  return CreateSolidBrush(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232AC; symbol: _CreatePen@12
HPEN __stdcall CreatePen(int a1, int a2, COLORREF a3)
{
  return CreatePen(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232B4; symbol: _CreateFontA@56
HFONT __stdcall CreateFontA(int a1, int a2, int a3, int a4, int a5, DWORD a6, DWORD a7, DWORD a8, DWORD a9, DWORD a10, DWORD a11, DWORD a12, DWORD a13, LPCSTR a14)
{
  return CreateFontA(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232BC; symbol: _CreateCompatibleDC@4
HDC __stdcall CreateCompatibleDC(HDC a1)
{
  return CreateCompatibleDC(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232C4; symbol: _CreateCompatibleBitmap@12
HBITMAP __stdcall CreateCompatibleBitmap(HDC a1, int a2, int a3)
{
  return CreateCompatibleBitmap(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232CC; symbol: _TransparentBlt@44
BOOL __stdcall TransparentBlt(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, UINT a11)
{
  return TransparentBlt(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232D4; symbol: _AlphaBlend@44
BOOL __stdcall AlphaBlend(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, BLENDFUNCTION a11)
{
  return AlphaBlend(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232E0; symbol: __setargv
int _setargv()
{
  const char *v0; // eax
  const char *v1; // esi
  int v2; // eax
  void *v3; // esp
  void *v4; // esp
  char *v5; // edx
  int v6; // eax
  int v7; // ecx
  char v8; // bl
  char *v9; // ecx
  char *v10; // eax
  int result; // eax
  int v12; // edi
  bool v13; // cl
  int v14; // edi
  char *v15; // eax
  char *v16; // edi
  char *v17; // ecx
  int v18; // ebx
  char *v19; // edi
  int v20; // [esp+0h] [ebp-58h]
  int v21; // [esp+10h] [ebp-48h]
  int v22; // [esp+18h] [ebp-40h]
  int *v23; // [esp+1Ch] [ebp-3Ch]
  int v24; // [esp+20h] [ebp-38h]
  char *v25; // [esp+24h] [ebp-34h]
  int v26; // [esp+28h] [ebp-30h]
  int v27; // [esp+2Ch] [ebp-2Ch]
  int v28; // [esp+30h] [ebp-28h]
  int v29; // [esp+34h] [ebp-24h]
  int v30; // [esp+38h] [ebp-20h]
  int v31; // [esp+3Ch] [ebp-1Ch]

  if ( !(_CRT_glob & 2) )
    return _mingw32_init_mainargs();
  v0 = GetCommandLineA();
  v23 = &v20;
  v1 = v0;
  v2 = 16 * ((2 * strlen(v0) + 17) >> 4);
  v3 = alloca(v2);
  v4 = alloca(v2);
  v31 = 0;
  v27 = 0;
  v26 = 0;
  v5 = (char *)&v21;
  v25 = (char *)&v21;
  v24 = _CRT_glob & 0x4400 | 0x10;
  v6 = 0;
LABEL_3:
  while ( 1 )
  {
    v7 = *(++v1 - 1);
    v8 = *(v1 - 1);
    if ( !*(v1 - 1) )
      break;
    while ( 1 )
    {
      if ( v8 == 63 )
        goto LABEL_40;
      if ( v8 > 63 )
      {
        switch ( v8 )
        {
          case 92:
            if ( v27 == 39 )
              *v5++ = 92;
            else
              ++v6;
            goto LABEL_3;
          case 127:
            goto LABEL_40;
          case 91:
            if ( _CRT_glob & 0x20 )
            {
LABEL_40:
              v12 = v6 - 1;
              if ( v6 )
              {
                v13 = v27 != 0 || v7 == 127;
                goto LABEL_26;
              }
              v13 = v27 != 0 || v7 == 127;
              v15 = v5;
LABEL_28:
              if ( v13 )
              {
                v5 = v15;
                goto LABEL_31;
              }
            }
            else
            {
              v12 = v6 - 1;
              v13 = 1;
              if ( v6 )
              {
LABEL_26:
                v14 = (int)&v5[v12 + 1];
                v15 = v5;
                do
                  *(++v15 - 1) = 92;
                while ( v15 != (char *)v14 );
                goto LABEL_28;
              }
LABEL_31:
              v15 = v5 + 1;
              *v5 = 127;
            }
            v5 = v15 + 1;
            *v15 = v8;
            v6 = 0;
            goto LABEL_3;
        }
LABEL_32:
        v16 = &v5[v6];
        if ( v6 )
        {
          do
            *(++v5 - 1) = 92;
          while ( v5 != v16 );
        }
        else
        {
          v16 = v5;
        }
        if ( v27 )
        {
LABEL_39:
          v5 = v16 + 1;
          *v16 = v8;
          v6 = 0;
          goto LABEL_3;
        }
        if ( ___mb_cur_max == 1 )
        {
          if ( !(__pctype[v7] & 0x40) )
            goto LABEL_38;
        }
        else
        {
          v22 = v7;
          if ( !_isctype(v7, 64) )
          {
            v7 = v22;
LABEL_38:
            if ( v7 != 9 )
              goto LABEL_39;
          }
        }
        if ( v25 < v16 || v26 )
        {
          *v16 = 0;
          v18 = v24;
          v19 = v25;
          __mingw_glob(v25, v24, 0, (int)&v28);
          v5 = v19;
          v26 = 0;
          v24 = v18 | 1;
          v6 = 0;
        }
        else
        {
          v5 = v16;
          v6 = 0;
          v26 = 0;
        }
        goto LABEL_3;
      }
      if ( v8 == 39 )
        break;
      if ( v8 == 42 )
        goto LABEL_40;
      if ( v8 != 34 )
        goto LABEL_32;
      if ( v6 >> 1 )
      {
        v9 = &v5[v6 >> 1];
        do
          *(++v5 - 1) = 92;
        while ( v5 != v9 );
      }
      else
      {
        v9 = v5;
      }
      if ( v27 == 39 || v6 & 1 )
      {
        v5 = v9 + 1;
        *v9 = 34;
        v6 = 0;
        v26 = 1;
        goto LABEL_3;
      }
      ++v1;
      v5 = v9;
      v27 ^= 0x22u;
      v7 = *(v1 - 1);
      v6 = 0;
      v26 = 1;
      v8 = v7;
      if ( !v7 )
        goto LABEL_15;
    }
    if ( !(_CRT_glob & 0x10) )
      goto LABEL_32;
    if ( v6 >> 1 )
    {
      v17 = &v5[v6 >> 1];
      do
        *(++v5 - 1) = 92;
      while ( v5 != v17 );
    }
    else
    {
      v17 = v5;
    }
    if ( v27 == 34 || v6 & 1 )
    {
      v5 = v17 + 1;
      *v17 = 39;
      v6 = 0;
      v26 = 1;
    }
    else
    {
      v27 ^= 0x27u;
      v5 = v17;
      v6 = 0;
      v26 = 1;
    }
  }
LABEL_15:
  if ( v6 )
  {
    v10 = &v5[v6];
    do
      *(++v5 - 1) = 92;
    while ( v5 != v10 );
  }
  else
  {
    v10 = v5;
  }
  if ( v25 < v10 || v26 )
  {
    *v10 = 0;
    __mingw_glob(v25, v24, 0, (int)&v28);
  }
  _argc = v29;
  result = v30;
  _argv = v30;
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423680; symbol: ___cpu_features_init
unsigned int __cpu_features_init()
{
  unsigned int v0; // et0
  unsigned int v1; // ST04_4
  unsigned int v2; // et0
  unsigned int v3; // eax
  unsigned int v4; // et0
  unsigned int result; // eax

  v0 = __getcallerseflags();
  v1 = v0;
  v2 = __readeflags();
  v3 = v2;
  __writeeflags(v2 ^ 0x200000);
  v4 = __readeflags();
  __writeeflags(v1);
  result = v4 ^ v3;
  if ( result & 0x200000 )
  {
    _EAX = 0;
    __asm { cpuid }
    if ( result )
    {
      _EAX = 1;
      __asm { cpuid }
      if ( _EDX & 0x100 )
        __cpu_features |= 1u;
      if ( (_EDX & 0x8000) != 0 )
        __cpu_features |= 2u;
      if ( _EDX & 0x800000 )
        __cpu_features |= 4u;
      if ( _EDX & 0x1000000 )
        __cpu_features |= 8u;
      if ( _EDX & 0x2000000 )
        __cpu_features |= 0x10u;
      if ( _EDX & 0x4000000 )
        __cpu_features |= 0x20u;
      if ( _ECX & 1 )
        __cpu_features |= 0x40u;
      if ( _ECX & 0x2000 )
        __cpu_features |= 0x80u;
      _EAX = 2147483648;
      __asm { cpuid }
      if ( result > 0x80000000 )
      {
        _EAX = -2147483647;
        __asm { cpuid }
        if ( _EDX < 0 )
          __cpu_features |= 0x100u;
        if ( _EDX & 0x40000000 )
          __cpu_features |= 0x200u;
      }
    }
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423760; symbol: ___do_global_dtors
void __cdecl __do_global_dtors()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))(*off_42730C)[0];
  if ( (*off_42730C)[0] )
  {
    do
    {
      v0();
      v0 = (void (*)(void))(*off_42730C)[1];
      off_42730C = (int (*)[51])((char *)off_42730C + 4);
    }
    while ( v0 );
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423790; symbol: ___do_global_ctors
int __do_global_ctors()
{
  func_ptr i; // ebx

  i = __CTOR_LIST__[0];
  if ( __CTOR_LIST__[0] == (func_ptr)-1 )
  {
    for ( i = 0; __CTOR_LIST__[(_DWORD)i + 1]; i = (func_ptr)((char *)i + 1) )
      ;
  }
  for ( ; i; i = (func_ptr)((char *)i - 1) )
    __CTOR_LIST__[(_DWORD)i]();
  return atexit(__do_global_dtors);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004237E0; symbol: ___main
int __main()
{
  int result; // eax

  result = dword_470930;
  if ( !dword_470930 )
  {
    dword_470930 = 1;
    result = __do_global_ctors();
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423800; symbol: TlsCallback_1
signed int __stdcall TlsCallback_1(int a1, int a2, int a3)
{
  if ( a2 != 3 && a2 )
    return 1;
  __mingw_TLScallback(a1, a2);
  return 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423850; symbol: ___dyn_tls_init@12
signed int __stdcall __dyn_tls_init(int a1, int a2, int a3)
{
  if ( _CRT_MT != 2 )
    _CRT_MT = 2;
  if ( a2 != 2 && a2 == 1 )
    __mingw_TLScallback(a1, 1);
  return 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004238F0; symbol: sub_4238F0
void sub_4238F0()
{
  int i; // ebx
  LPVOID v1; // esi

  EnterCriticalSection(&CriticalSection);
  for ( i = dword_470944; i; i = *(_DWORD *)(i + 8) )
  {
    v1 = TlsGetValue(*(_DWORD *)i);
    if ( !GetLastError() && v1 )
      (*(void (__cdecl **)(LPVOID))(i + 4))(v1);
  }
  LeaveCriticalSection(&CriticalSection);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：写入文件内容。
// Address: 0x00423B20; symbol: sub_423B20
void __noreturn sub_423B20(char *a1, ...)
{
  va_list va; // [esp+24h] [ebp+8h]

  va_start(va, a1);
  fwrite("Mingw runtime failure:\n", 1u, 0x17u, &__iob[2]);
  vfprintf(&__iob[2], a1, va);
  abort();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00423B70; symbol: sub_423B70
void *__usercall sub_423B70@<eax>(size_t a1@<ecx>, void *a2@<edx>, void *lpAddress@<eax>)
{
  size_t v3; // edi
  void *v4; // ebx
  void *v5; // esi
  void *result; // eax
  DWORD v7; // [esp+1Ch] [ebp-40h]
  DWORD flOldProtect; // [esp+20h] [ebp-3Ch]
  struct _MEMORY_BASIC_INFORMATION Buffer; // [esp+24h] [ebp-38h]

  v3 = a1;
  v4 = lpAddress;
  v5 = a2;
  if ( !VirtualQuery(lpAddress, &Buffer, 0x1Cu) )
    sub_423B20("  VirtualQuery failed for %d bytes at address %p", 28, v4);
  if ( Buffer.Protect == 64 || Buffer.Protect == 4 )
    return memcpy(v4, v5, v3);
  VirtualProtect(Buffer.BaseAddress, Buffer.RegionSize, 0x40u, &flOldProtect);
  v7 = Buffer.Protect;
  result = memcpy(v4, v5, v3);
  if ( v7 != 64 && v7 != 4 )
    result = (void *)VirtualProtect(Buffer.BaseAddress, Buffer.RegionSize, flOldProtect, &flOldProtect);
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423C60; symbol: __pei386_runtime_relocator
int _pei386_runtime_relocator()
{
  int result; // eax

  result = dword_470964;
  if ( !dword_470964 )
  {
    dword_470964 = 1;
    result = 0;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00423E30; symbol: ___chkstk_ms
void __usercall __spoils<ecx> __chkstk_ms(unsigned int a1@<eax>, int a2@<ecx>, char a3)
{
  char *v3; // ecx
  int v4; // [esp-4h] [ebp-4h]

  v4 = a2;
  v3 = &a3;
  if ( a1 >= 0x1000 )
  {
    do
    {
      v3 -= 4096;
      *(_DWORD *)v3 = *(_DWORD *)v3;
      a1 -= 4096;
    }
    while ( a1 > 0x1000 );
  }
  *(_DWORD *)&v3[-a1] = *(_DWORD *)&v3[-a1];
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423E60; symbol: _fesetenv
int __cdecl fesetenv(int a1)
{
  unsigned int v3; // [esp+Ch] [ebp-10h]

  _EAX = a1;
  v3 = 8064;
  if ( a1 == -3 )
  {
    dword_427310 = -1;
    goto LABEL_12;
  }
  if ( a1 != -4 )
  {
    if ( !a1 )
      _EAX = dword_427310;
    if ( _EAX != -1 )
    {
      if ( _EAX != -2 )
      {
        __asm { fldenv  byte ptr [eax] }
        v3 = *(unsigned __int16 *)(_EAX + 28);
        goto LABEL_8;
      }
      goto LABEL_14;
    }
LABEL_12:
    __asm { fninit }
    goto LABEL_8;
  }
  dword_427310 = -2;
LABEL_14:
  __fpreset();
LABEL_8:
  if ( __cpu_features & 0x10 )
    _mm_setcsr(v3);
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00423ED0; symbol: sub_423ED0
signed int __usercall sub_423ED0@<eax>(char *a1@<eax>, unsigned int a2@<edx>)
{
  signed int v2; // ecx
  char v3; // bl
  int i; // edx
  bool v5; // zf

  if ( !a1 )
    return 0;
  v2 = 0;
  v3 = ((a2 >> 5) ^ 1) & 1;
LABEL_3:
  for ( i = *a1; *a1; v2 = v5 )
  {
    if ( v3 && i == 127 )
    {
      if ( !a1[1] )
        return 0;
      a1 += 2;
    }
    else
    {
      ++a1;
    }
    if ( v2 )
    {
      if ( v2 <= 1 || i != 93 )
      {
        v2 += i != 33;
        goto LABEL_3;
      }
      return 1;
    }
    if ( i == 42 || i == 63 )
      return 1;
    v5 = i == 91;
    i = *a1;
  }
  return i;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00423F70; symbol: sub_423F70
signed int __usercall sub_423F70@<eax>(int a1@<eax>)
{
  int v1; // esi
  int v2; // ebx
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  signed int result; // eax
  int v6; // edx

  if ( !a1 )
    return 0;
  v1 = a1;
  v2 = *(_DWORD *)(a1 + 12) + 1;
  v3 = malloc(4 * v2);
  v4 = v3;
  *(_DWORD *)(v1 + 8) = v3;
  result = 3;
  if ( v4 )
  {
    v6 = v2;
    *(_DWORD *)(v1 + 4) = 0;
    if ( v2 > 0 )
    {
      do
        v4[--v6] = 0;
      while ( v6 );
    }
    result = 0;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00423FE0; symbol: sub_423FE0
int __usercall sub_423FE0@<eax>(char *a1@<eax>, int a2@<edx>, __int16 a3@<cx>)
{
  char *v3; // edi
  int v4; // ebx
  int v5; // ebp
  char *v6; // esi
  char v7; // dl
  char v8; // ST24_1
  int v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // ebp
  int v13; // edi
  char *v14; // esi
  char v15; // al
  char v17; // al
  int v18; // edi
  int v19; // ebp
  char v20; // al
  int v21; // [esp+1Ch] [ebp-30h]
  __int16 v22; // [esp+20h] [ebp-2Ch]
  int v23; // [esp+24h] [ebp-28h]
  int v24; // [esp+28h] [ebp-24h]
  int v25; // [esp+2Ch] [ebp-20h]

  v3 = a1;
  v4 = *a1;
  v21 = a2;
  v22 = a3;
  v5 = *a1;
  if ( v4 != 93 && v4 != 45 )
    goto LABEL_3;
  if ( v4 == a2 )
  {
    v3 = a1 + 1;
    while ( 1 )
    {
      v17 = *v3;
      if ( *v3 == 93 )
        return (int)(v3 + 1);
      if ( v17 != 127 )
        goto LABEL_45;
      if ( a3 & 0x20 )
      {
        ++v3;
      }
      else
      {
        v17 = (v3++)[1];
LABEL_45:
        ++v3;
        if ( !v17 )
          return 0;
      }
    }
  }
  v4 = a1[1];
  v3 = a1 + 1;
LABEL_3:
  v24 = ~a2;
  v25 = 1 - a2;
  while ( 1 )
  {
    v6 = v3 + 1;
    if ( v4 == 93 )
      return 0;
    if ( v4 != 45 )
    {
      if ( !v4 )
        return 0;
      goto LABEL_9;
    }
    v7 = v3[1];
    if ( v7 == 93 )
    {
      v5 = 45;
      ++v3;
      goto LABEL_12;
    }
    v4 = v7;
    if ( !v7 )
      return 0;
    v6 = v3 + 2;
    if ( v5 < v7 )
      break;
    if ( v5 > v7 )
    {
      v23 = (int)(v3 + 2);
      do
      {
        v18 = v5 - 1;
        if ( v22 & 0x4000 )
        {
          if ( !(v25 + v18) )
            goto LABEL_58;
        }
        else
        {
          v19 = tolower(v5);
          if ( v19 == tolower(v21) )
          {
LABEL_58:
            v14 = (char *)v23;
            while ( 1 )
            {
              v20 = *v14;
              if ( *v14 == 93 )
                return (int)(v14 + 1);
              if ( v20 != 127 )
                goto LABEL_61;
              if ( v22 & 0x20 )
              {
                ++v14;
              }
              else
              {
                v20 = (v14++)[1];
LABEL_61:
                ++v14;
                if ( !v20 )
                  return 0;
              }
            }
          }
        }
        v5 = v18;
      }
      while ( v4 != v18 );
LABEL_37:
      v6 = (char *)v23;
    }
LABEL_9:
    if ( v4 == 47 || v4 == 92 )
      return 0;
    v7 = *v6;
    v5 = v4;
    v3 = v6;
LABEL_12:
    if ( v22 & 0x4000 )
    {
      if ( v5 == v21 )
        goto LABEL_17;
    }
    else
    {
      v8 = v7;
      v9 = tolower(v5);
      v10 = tolower(v21);
      v7 = v8;
      if ( v9 == v10 )
      {
        while ( 1 )
        {
LABEL_17:
          if ( v7 == 93 )
            return (int)(v3 + 1);
          if ( v7 == 127 )
          {
            if ( v22 & 0x20 )
            {
              ++v3;
              goto LABEL_16;
            }
            v7 = (v3++)[1];
          }
          ++v3;
          if ( !v7 )
            return 0;
LABEL_16:
          v7 = *v3;
        }
      }
    }
    v4 = v7;
  }
  v23 = (int)(v3 + 2);
  v11 = v5;
  while ( 1 )
  {
    v12 = v11 + 1;
    if ( v22 & 0x4000 )
    {
      if ( !(v24 + v12) )
        break;
      goto LABEL_26;
    }
    v13 = tolower(v11);
    if ( v13 == tolower(v21) )
      break;
LABEL_26:
    v11 = v12;
    if ( v4 == v12 )
      goto LABEL_37;
  }
  v14 = (char *)v23;
  while ( 1 )
  {
    v15 = *v14;
    if ( *v14 == 93 )
      return (int)(v14 + 1);
    while ( v15 == 127 )
    {
      if ( !(v22 & 0x20) )
      {
        v15 = (v14++)[1];
        break;
      }
      v15 = *++v14;
      if ( *v14 == 93 )
        return (int)(v14 + 1);
    }
    ++v14;
    if ( !v15 )
      return 0;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004242A0; symbol: sub_4242A0
int __usercall sub_4242A0@<eax>(char *a1@<eax>, _BYTE *a2@<edx>, unsigned int a3@<ecx>)
{
  char *v3; // ebp
  char v4; // cl
  int v5; // edi
  int v6; // edx
  char *v7; // esi
  char *v8; // eax
  int v9; // ebx
  int v10; // ST1C_4
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int result; // eax
  char v15; // dl
  _BYTE *v16; // ebx
  int v17; // edx
  char *v18; // ebx
  char v19; // al
  unsigned int v20; // [esp+14h] [ebp-28h]

  v3 = a1;
  v20 = a3;
  v4 = *a1;
  if ( *a2 == 46 && v4 != 46 )
  {
    result = v4 - 46;
    if ( !(v20 & 0x10000) )
      return result;
  }
  v5 = (int)(a2 + 1);
LABEL_3:
  v6 = v4;
  v7 = (char *)(v5 - 1);
  v8 = v3 + 1;
  switch ( v4 )
  {
    case 0:
      return -*v7;
    case 63:
      if ( *(_BYTE *)(v5 - 1) )
      {
        ++v3;
        goto LABEL_27;
      }
      return 63;
    case 91:
      v17 = *(char *)(v5 - 1);
      if ( !*(_BYTE *)(v5 - 1) )
        return 91;
      if ( v3[1] != 33 )
      {
        v3 = (char *)sub_423FE0(v8, v17, v20);
        goto LABEL_26;
      }
      v18 = v3 + 2;
      if ( sub_423FE0(v3 + 2, v17, v20) )
      {
        v3 += 2;
        goto LABEL_26;
      }
      v19 = v3[2];
      if ( v19 == 93 )
      {
        v18 = v3 + 3;
        v19 = v3[3];
      }
      while ( 1 )
      {
        if ( v19 == 93 )
        {
          v3 = v18 + 1;
LABEL_26:
          if ( !v3 )
            return 93;
LABEL_27:
          v4 = *v3;
          ++v5;
          goto LABEL_3;
        }
        if ( v19 == 127 )
        {
          if ( v20 & 0x20 )
          {
            ++v18;
            goto LABEL_43;
          }
          v19 = (v18++)[1];
        }
        ++v18;
        if ( !v19 )
          return 93;
LABEL_43:
        v19 = *v18;
      }
    case 42:
      v15 = v3[1];
      v16 = v3 + 1;
      if ( v15 == 42 )
      {
        do
          v15 = *++v16;
        while ( *v16 == 42 );
      }
      result = 0;
      if ( v15 )
      {
        do
        {
          result = sub_4242A0(v20 | 0x10000, v7);
          if ( !result )
            break;
          ++v7;
        }
        while ( *(v7 - 1) );
      }
      break;
    default:
      if ( !(((unsigned __int8)(v20 >> 5) ^ 1) & 1) || v4 != 127 || (v6 = v3[1], v3 += 2, !v6) )
        v3 = v8;
      v9 = *(char *)(v5 - 1);
      if ( (_BYTE)v9 )
      {
        if ( v20 & 0x4000 )
        {
          v13 = v6 - v9;
        }
        else
        {
          v10 = v6;
          v11 = tolower(v6);
          v12 = tolower(v9);
          v6 = v10;
          v13 = v11 - v12;
        }
        if ( !v13 )
          goto LABEL_27;
      }
      else
      {
        v9 = 0;
      }
      result = v6 - v9;
      break;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004244C0; symbol: sub_4244C0
signed int __usercall sub_4244C0@<eax>(int a1@<eax>, int a2@<edx>)
{
  int v2; // esi
  _DWORD *v3; // ebx
  _DWORD *v4; // eax
  int v5; // ecx
  int v6; // edx

  v2 = a1;
  v3 = (_DWORD *)a2;
  v4 = realloc(*(void **)(a2 + 8), 4 * (*(_DWORD *)(a2 + 4) + *(_DWORD *)(a2 + 12)) + 8);
  if ( !v4 )
    return 1;
  v5 = v3[1];
  v6 = v3[3];
  v3[2] = v4;
  v3[1] = v5 + 1;
  v4[v6 + v5] = v2;
  v4[v5 + 1 + v6] = 0;
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00424520; symbol: sub_424520
void __usercall sub_424520(_DWORD *a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  _DWORD *v3; // ebx
  int v4; // esi
  int v5; // eax

  v3 = a1;
  v4 = a2;
  if ( *a1 )
    ((void (*)(void))sub_424520)();
  v5 = v3[2];
  if ( v5 && v4 )
    sub_4244C0(v5, v4);
  if ( v3[1] )
    sub_424520(a3, v4);
  free(v3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00424570; symbol: sub_424570
int __usercall sub_424570@<eax>(const char *a1@<eax>, unsigned int a2@<edx>, int a3@<ecx>, int a4)
{
  char *v4; // ebx
  size_t v5; // eax
  size_t v6; // edx
  int v7; // eax
  void *v8; // esp
  void *v9; // esp
  char *v10; // eax
  char *v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // edx
  char v14; // al
  bool v15; // zf
  char *v16; // esi
  const char *v17; // edi
  signed int v18; // ecx
  char *v19; // eax
  char v20; // cl
  char *v21; // edx
  char v22; // al
  char *v23; // edx
  char j; // si
  char *v25; // eax
  void *v26; // edi
  int v27; // esi
  size_t v28; // edx
  int v29; // eax
  void *v30; // esp
  void *v31; // esp
  int v32; // eax
  void *v33; // esp
  void *v34; // esp
  char *v35; // eax
  char *v36; // esi
  char v37; // dl
  char v38; // dl
  char *v39; // esi
  _DWORD *v40; // ebx
  int v41; // edi
  int v42; // eax
  _DWORD *v43; // edx
  _DWORD *v44; // ecx
  const char *v45; // eax
  _DWORD *v46; // eax
  signed int v47; // edx
  int v49; // eax
  void *v50; // esp
  void *v51; // esp
  char *v52; // esi
  char *v53; // edi
  char v54; // al
  char *v55; // edi
  char *v56; // edx
  signed int v57; // ecx
  char v58; // al
  char v59; // al
  bool v60; // bl
  int v61; // eax
  signed int v62; // esi
  char v63; // bl
  int v64; // ecx
  char *v65; // ecx
  char i; // al
  int v67; // esi
  int v68; // eax
  int v69; // eax
  void *v70; // esp
  char *v71; // edx
  void *v72; // esp
  char *v73; // ecx
  char v74; // al
  char *v75; // eax
  int v76; // ecx
  void *v77; // edi
  void **v78; // ebx
  _DWORD *v79; // edi
  void **v80; // eax
  void *v81; // eax
  char v82; // al
  int (__cdecl *v83)(const char *, const char *); // edi
  void **v84; // esi
  int v85; // eax
  void *v86; // esp
  void *v87; // esp
  char *v88; // edx
  char v89; // al
  char *v90; // eax
  char v91; // bl
  const char *v92; // [esp+0h] [ebp-78h]
  const char *v93; // [esp+4h] [ebp-74h]
  char v94; // [esp+Bh] [ebp-6Dh]
  char v95[15]; // [esp+Ch] [ebp-6Ch]
  char v96; // [esp+1Bh] [ebp-5Dh]
  char *v97; // [esp+1Ch] [ebp-5Ch]
  const char **v98; // [esp+20h] [ebp-58h]
  size_t v99; // [esp+24h] [ebp-54h]
  const char **v100; // [esp+28h] [ebp-50h]
  size_t v101; // [esp+2Ch] [ebp-4Ch]
  _DWORD *v102; // [esp+30h] [ebp-48h]
  void *v103; // [esp+34h] [ebp-44h]
  size_t v104; // [esp+38h] [ebp-40h]
  int (__cdecl *v105)(const char *, const char *); // [esp+3Ch] [ebp-3Ch]
  char *v106; // [esp+40h] [ebp-38h]
  char *v107; // [esp+44h] [ebp-34h]
  unsigned int v108; // [esp+48h] [ebp-30h]
  char *v109; // [esp+4Ch] [ebp-2Ch]
  char v110; // [esp+50h] [ebp-28h]
  _DWORD *v111; // [esp+58h] [ebp-20h]
  int v112; // [esp+5Ch] [ebp-1Ch]

  v4 = (char *)a1;
  v108 = a2;
  v105 = (int (__cdecl *)(const char *, const char *))a3;
  if ( a2 & 0x400 )
  {
    v104 = (size_t)&v92;
    v49 = 16 * ((strlen(a1) + 16) >> 4);
    v50 = alloca(v49);
    v51 = alloca(v49);
    v52 = v4;
    v53 = v95;
    v106 = v95;
    v54 = *v4;
LABEL_56:
    if ( v54 != 127 )
    {
LABEL_57:
      if ( v54 == 123 )
      {
        v107 = v53;
        v55 = v52;
        goto LABEL_64;
      }
      goto LABEL_58;
    }
    while ( 1 )
    {
      v54 = v52[1];
      *v53 = 127;
      if ( v54 )
      {
        v53[1] = v54;
        v52 += 2;
        v54 = *v52;
        v53 += 2;
        goto LABEL_56;
      }
      ++v53;
      ++v52;
LABEL_58:
      *v53 = v54;
      if ( !v54 || v54 == 123 )
        break;
      v54 = v52[1];
      ++v53;
      ++v52;
      if ( v54 != 127 )
        goto LABEL_57;
    }
    if ( v54 == 123 )
    {
      v107 = v53 + 1;
      v55 = v52 + 1;
      while ( 1 )
      {
LABEL_64:
        v56 = v107;
        v57 = 1;
LABEL_65:
        v58 = v55[1];
        if ( v58 != 127 )
        {
LABEL_66:
          ++v55;
          goto LABEL_67;
        }
        while ( 1 )
        {
          v59 = v55[2];
          *v56 = 127;
          v56[1] = v59;
          if ( !v59 )
          {
            v56[2] = 0;
            return 1;
          }
          v58 = v55[3];
          v56 += 2;
          v55 += 3;
LABEL_67:
          if ( v58 != 125 && (v58 != 44 || v57 != 1) )
          {
            if ( v58 == 123 )
            {
              ++v57;
              v60 = 1;
              LOBYTE(v109) = 1;
            }
            else
            {
              LOBYTE(v109) = v58 != 0;
              v60 = v58 != 0;
            }
            *v56 = v58;
            if ( v60 )
            {
              ++v56;
              goto LABEL_65;
            }
            if ( (_BYTE)v109 )
            {
              ++v56;
              if ( v58 == 44 )
                goto LABEL_83;
LABEL_100:
              *v56 = 0;
              return 1;
            }
            return 1;
          }
          if ( !--v57 )
            break;
          *v56 = v58;
          v58 = v55[1];
          ++v56;
          if ( v58 != 127 )
            goto LABEL_66;
        }
        if ( v58 == 44 )
        {
LABEL_83:
          v61 = (int)v55;
          v62 = 1;
          do
          {
            while ( 1 )
            {
              while ( 1 )
              {
                v63 = *(_BYTE *)(v61 + 1);
                v64 = v61 + 1;
                if ( v63 == 127 )
                {
                  if ( !*(_BYTE *)(v61 + 2) )
                    goto LABEL_100;
                  while ( 1 )
                  {
                    v63 = *(_BYTE *)(v64 + 2);
                    v61 = v64 + 2;
                    if ( v63 != 127 )
                      break;
                    if ( !*(_BYTE *)(v64 + 3) )
                      goto LABEL_100;
                    v64 += 2;
                  }
                }
                else
                {
                  ++v61;
                }
                if ( v63 != 123 )
                  break;
                ++v62;
              }
              if ( v63 != 125 )
                break;
              if ( !--v62 )
                goto LABEL_93;
            }
          }
          while ( v63 );
          goto LABEL_100;
        }
        v61 = (int)v55;
LABEL_93:
        v65 = (char *)(v61 + 1);
        for ( i = *(_BYTE *)(v61 + 1); ; i = *v65 )
        {
          ++v56;
          ++v65;
          *(v56 - 1) = i;
          if ( !i )
            break;
        }
        v67 = v108 | 1;
        v68 = sub_424570(v105, v108, a4);
        v108 = v67;
        if ( v68 == 1 )
          return 1;
        if ( *v55 != 44 )
          return v68;
      }
    }
  }
  v98 = &v92;
  v5 = strlen(v4);
  v6 = v5 + 1;
  v7 = 16 * ((v5 + 16) >> 4);
  v8 = alloca(v7);
  v9 = alloca(v7);
  v10 = (char *)memcpy(v95, v4, v6);
  v109 = (char *)__mingw_dirname(v10);
  v11 = v109;
  v112 = 0;
  v107 = (char *)sub_423F70((int)&v110);
  if ( !v107 )
  {
    v12 = v108;
    if ( sub_423ED0(v11, v108) )
    {
      v13 = v12;
      BYTE1(v13) |= 0x80u;
      v107 = (char *)sub_424570(v105, v13, &v110);
    }
    else
    {
      v69 = 16 * ((strlen(v109) + 16) >> 4);
      v70 = alloca(v69);
      v71 = v109;
      v72 = alloca(v69);
      v73 = v95;
      do
      {
        v74 = *v71;
        if ( *v71 == 127 )
          v74 = (v71++)[1];
        ++v73;
        ++v71;
        *(v73 - 1) = v74;
      }
      while ( v74 );
      v75 = strdup(v95);
      if ( !v75 )
        return 1;
      v107 = (char *)sub_4244C0((int)v75, (int)&v110);
    }
    if ( !v107 )
    {
      v14 = v4[1];
      if ( v14 == 47 )
        goto LABEL_161;
      v15 = v14 == 92;
      if ( v14 == 92 )
        goto LABEL_161;
      v16 = v109;
      v17 = ".";
      v18 = 2;
      do
      {
        if ( !v18 )
          break;
        v15 = *v16++ == *v17++;
        --v18;
      }
      while ( v15 );
      if ( v15 )
      {
        if ( v108 & 0x10 )
        {
          v107 = (char *)sub_423ED0(v4, v108);
          if ( !v107 )
          {
            v85 = 16 * ((strlen(v4) + 16) >> 4);
            v86 = alloca(v85);
            v87 = alloca(v85);
            v88 = v95;
            do
            {
              v89 = *v4;
              if ( *v4 == 127 )
                v89 = (v4++)[1];
              ++v88;
              ++v4;
              *(v88 - 1) = v89;
            }
            while ( v89 );
            v90 = strdup(v95);
            if ( v90 && a4 )
            {
              sub_4244C0((int)v90, a4);
              v103 = v111;
            }
            else
            {
LABEL_136:
              v103 = v111;
            }
            goto LABEL_127;
          }
        }
        v106 = v4;
        v96 = 92;
        v97 = 0;
      }
      else
      {
LABEL_161:
        v19 = &v4[strlen(v109)];
        if ( v4 >= v19 )
        {
          v91 = *v19;
          v106 = v19;
          v96 = v91;
        }
        else
        {
          v96 = *v19;
          if ( v96 != 47 && v96 != 92 )
          {
            do
            {
              v21 = v19 - 1;
              if ( v4 == v19 - 1 )
              {
                v22 = *(v19 - 1);
                v106 = v21;
                v96 = v22;
                goto LABEL_20;
              }
              v20 = *(v19-- - 1);
            }
            while ( v20 != 47 && v20 != 92 );
            v106 = v21;
            v96 = v20;
          }
          else
          {
            v106 = v19;
          }
        }
LABEL_20:
        if ( v96 != 47 && v96 != 92 )
        {
          v96 = 92;
          v97 = v109;
        }
        else
        {
          v23 = v106;
          for ( j = v96; ; j = *v23 )
          {
            ++v23;
            if ( *v23 != 92 && *v23 != 47 )
              break;
          }
          v106 = v23;
          v96 = j;
          v97 = v109;
        }
      }
      v107 = (char *)2;
      v103 = v111;
      v25 = (char *)*v111;
      v109 = (char *)(v108 & 0x8000);
      if ( !v25 )
        goto LABEL_127;
LABEL_27:
      v26 = (void *)__mingw_opendir(v25);
      if ( v26 )
      {
        if ( v97 )
        {
          v92 = *(const char **)v103;
          v104 = strlen(v92);
        }
        else
        {
          v104 = 0;
        }
        v102 = 0;
        v99 = v104 + 2;
        while ( 1 )
        {
          while ( 1 )
          {
LABEL_31:
            v27 = __mingw_readdir(v26);
            if ( !v27 )
            {
              __mingw_closedir(v26);
              if ( v102 )
                sub_424520(v102, a4, v76);
LABEL_115:
              v77 = v103;
              v78 = (void **)((char *)v103 + 4);
              free(*(void **)v103);
              v25 = (char *)*((_DWORD *)v77 + 1);
              if ( !v25 )
                goto LABEL_136;
              if ( v107 == (char *)1 )
                goto LABEL_124;
              v103 = v78;
              goto LABEL_27;
            }
            if ( v109 && *(_DWORD *)(v27 + 8) != 16 || sub_4242A0(v106, (_BYTE *)(v27 + 12), v108) )
              continue;
            v28 = *(unsigned __int16 *)(v27 + 6);
            v100 = &v92;
            v29 = 16 * ((v28 + v99 + 15) >> 4);
            v30 = alloca(v29);
            v31 = alloca(v29);
            v101 = 0;
            if ( v104 )
            {
              v101 = v28;
              memcpy(v95, *(const void **)v103, v104);
              v28 = v101;
              v82 = *(&v94 + v104);
              if ( v82 == 47 || v82 == 92 )
              {
                v101 = v104;
              }
              else
              {
                v101 = v104 + 1;
                v95[v104] = v96;
              }
            }
            memcpy(&v95[v101], (const void *)(v27 + 12), v28 + 1);
            v32 = 16 * ((strlen(v95) + 16) >> 4);
            v33 = alloca(v32);
            v34 = alloca(v32);
            v35 = v95;
            v36 = v95;
            do
            {
              while ( 1 )
              {
                v37 = *v35;
                if ( *v35 == 127 )
                  break;
                ++v36;
                ++v35;
                *(v36 - 1) = v37;
                if ( !v37 )
                  goto LABEL_40;
              }
              v38 = v35[1];
              ++v36;
              v35 += 2;
              *(v36 - 1) = v38;
            }
            while ( v38 );
LABEL_40:
            v39 = strdup(v95);
            if ( !v39 )
            {
              v107 = (char *)3;
              continue;
            }
            v107 = (char *)(v107 == (char *)2 ? 0 : (unsigned int)v107);
            if ( v108 & 0x40 )
            {
              if ( a4 )
                sub_4244C0((int)v39, a4);
              continue;
            }
            v40 = v102;
            if ( v102 )
              break;
            v46 = malloc(0xCu);
            if ( v46 )
            {
              v46[2] = v39;
              v46[1] = 0;
              *v46 = 0;
              goto LABEL_135;
            }
          }
          v101 = (size_t)v26;
          v41 = v108 & 0x4000;
          while ( 1 )
          {
            v45 = (const char *)v40[2];
            v92 = v39;
            v93 = v45;
            if ( !v41 )
              break;
            v42 = strcoll(v92, v93);
            v43 = (_DWORD *)*v40;
            v44 = (_DWORD *)v40[1];
            if ( v42 <= 0 )
              goto LABEL_49;
LABEL_45:
            if ( !v44 )
              goto LABEL_50;
LABEL_46:
            v40 = v44;
          }
          v42 = stricoll(v92, v93);
          v43 = (_DWORD *)*v40;
          v44 = (_DWORD *)v40[1];
          if ( v42 > 0 )
            goto LABEL_45;
LABEL_49:
          v44 = v43;
          if ( v43 )
            goto LABEL_46;
LABEL_50:
          v26 = (void *)v101;
          v101 = v42;
          v46 = malloc(0xCu);
          if ( !v46 )
            goto LABEL_31;
          v47 = v101;
          v46[2] = v39;
          v46[1] = 0;
          *v46 = 0;
          if ( v47 > 0 )
          {
            v40[1] = v46;
            goto LABEL_31;
          }
          *v40 = v46;
          if ( !v102 )
LABEL_135:
            v102 = v46;
        }
      }
      if ( v108 & 4 )
      {
        v79 = v103;
        v78 = (void **)((char *)v103 + 4);
        v80 = (void **)v103;
      }
      else
      {
        v83 = v105;
        if ( !v105 )
          goto LABEL_115;
        v93 = *(const char **)_errno();
        v84 = (void **)v103;
        v92 = *(const char **)v103;
        if ( !v83(v92, v93) )
          goto LABEL_115;
        v80 = v84;
        v78 = v84 + 1;
        v79 = v84;
      }
      free(*v80);
      if ( v79[1] )
      {
LABEL_124:
        v81 = (void *)*((_DWORD *)v103 + 1);
        do
        {
          ++v78;
          free(v81);
          v81 = *v78;
        }
        while ( *v78 );
      }
      v107 = (char *)1;
      v103 = v111;
LABEL_127:
      free(v103);
      return (int)v107;
    }
  }
  return (int)v107;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425350; symbol: sub_425350
HANDLE __usercall sub_425350@<eax>(const CHAR *lpFileName@<eax>, int a2@<edx>)
{
  int v2; // ebx
  HANDLE v3; // esi
  CHAR *v4; // ecx
  unsigned __int16 i; // ax
  CHAR v6; // al
  DWORD v7; // eax
  DWORD *v9; // ebx
  DWORD v10; // eax
  struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-14Ch]

  v2 = a2;
  v3 = FindFirstFileA(lpFileName, &FindFileData);
  if ( v3 == (HANDLE)-1 )
  {
    v9 = (DWORD *)_errno();
    v10 = GetLastError();
    *v9 = v10;
    if ( v10 == 3 )
    {
      *(_DWORD *)_errno() = 2;
    }
    else if ( *(_DWORD *)_errno() == 267 )
    {
      *(_DWORD *)_errno() = 20;
    }
    else if ( *(_DWORD *)_errno() != 2 )
    {
      *(_DWORD *)_errno() = 22;
    }
    return v3;
  }
  v4 = (CHAR *)(v2 + 12);
  *(_WORD *)(v2 + 6) = 0;
  for ( i = 0; ; v4 += i < 0x104u )
  {
    v6 = FindFileData.cFileName[i];
    *v4 = v6;
    if ( !v6 )
      break;
    i = *(_WORD *)(v2 + 6) + 1;
    *(_WORD *)(v2 + 6) = i;
  }
  v7 = FindFileData.dwFileAttributes;
  LOBYTE(v7) = FindFileData.dwFileAttributes & 0x58;
  if ( v7 > 0x10 )
  {
    *(_DWORD *)(v2 + 8) = 24;
    return v3;
  }
  *(_DWORD *)(v2 + 8) = v7;
  return v3;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425420; symbol: sub_425420
BOOL __usercall sub_425420@<eax>(void *hFindFile@<eax>, int a2@<edx>)
{
  int v2; // ebx
  BOOL v3; // esi
  CHAR *v4; // ecx
  unsigned __int16 i; // ax
  CHAR v6; // al
  DWORD v7; // eax
  BOOL result; // eax
  struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-14Ch]

  v2 = a2;
  v3 = FindNextFileA(hFindFile, &FindFileData);
  if ( v3 )
  {
    v4 = (CHAR *)(v2 + 12);
    *(_WORD *)(v2 + 6) = 0;
    for ( i = 0; ; v4 += i < 0x104u )
    {
      v6 = FindFileData.cFileName[i];
      *v4 = v6;
      if ( !v6 )
        break;
      i = *(_WORD *)(v2 + 6) + 1;
      *(_WORD *)(v2 + 6) = i;
    }
    v7 = FindFileData.dwFileAttributes;
    LOBYTE(v7) = FindFileData.dwFileAttributes & 0x58;
    if ( v7 <= 0x10 )
    {
      *(_DWORD *)(v2 + 8) = v7;
      return v3;
    }
    *(_DWORD *)(v2 + 8) = 24;
    result = v3;
  }
  else
  {
    if ( GetLastError() == 18 )
      return v3;
    *(_DWORD *)_errno() = 2;
    result = 0;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425840; symbol: _wcstombs
size_t __cdecl wcstombs(char *a1, const wchar_t *a2, size_t a3)
{
  return _wcstombs(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425848; symbol: _wcslen
size_t __cdecl wcslen(const wchar_t *a1)
{
  return _wcslen(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425850; symbol: _vfprintf
int __cdecl vfprintf(FILE *a1, const char *a2, va_list a3)
{
  return _vfprintf(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425858; symbol: _tolower
int __cdecl tolower(int a1)
{
  return _tolower(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425860; symbol: _time
time_t __cdecl time(time_t *a1)
{
  return _time(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425868; symbol: _strtoul
unsigned int __cdecl strtoul(const char *a1, char **a2, int a3)
{
  return _strtoul(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425870; symbol: _strstr
char *__cdecl strstr(const char *a1, const char *a2)
{
  return _strstr(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425878; symbol: _strrchr
char *__cdecl strrchr(const char *a1, int a2)
{
  return _strrchr(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425880; symbol: _strlen
size_t __cdecl strlen(const char *a1)
{
  return _strlen(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425888; symbol: _strcpy
char *__cdecl strcpy(char *a1, const char *a2)
{
  return _strcpy(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425890; symbol: _strcoll
int __cdecl strcoll(const char *a1, const char *a2)
{
  return _strcoll(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425898; symbol: _strcmp
int __cdecl strcmp(const char *a1, const char *a2)
{
  return _strcmp(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258A0; symbol: _strcat
char *__cdecl strcat(char *a1, const char *a2)
{
  return _strcat(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258A8; symbol: _srand
void __cdecl srand(unsigned int a1)
{
  _srand(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258B8; symbol: _signal
void (__cdecl *__cdecl signal(int a1, void (__cdecl *a2)(int)))(int)
{
  return _signal(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258C0; symbol: _setlocale
char *__cdecl setlocale(int a1, const char *a2)
{
  return _setlocale(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258C8; symbol: _realloc
void *__cdecl realloc(void *a1, size_t a2)
{
  return _realloc(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258D0; symbol: _rand
int __cdecl rand()
{
  return _rand();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258D8; symbol: _memset
void *__cdecl memset(void *a1, int a2, size_t a3)
{
  return _memset(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258E0; symbol: _memcpy
void *__cdecl memcpy(void *a1, const void *a2, size_t a3)
{
  return _memcpy(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258E8; symbol: _mbstowcs
size_t __cdecl mbstowcs(wchar_t *a1, const char *a2, size_t a3)
{
  return _mbstowcs(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258F0; symbol: _malloc
void *__cdecl malloc(size_t a1)
{
  return _malloc(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258F8; symbol: _localtime
struct tm *__cdecl localtime(const time_t *a1)
{
  return _localtime(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：写入文件内容。
// Address: 0x00425900; symbol: _fwrite
size_t __cdecl fwrite(const void *a1, size_t a2, size_t a3, FILE *a4)
{
  return _fwrite(a1, a2, a3, a4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425908; symbol: _free
void __cdecl free(void *a1)
{
  _free(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425910; symbol: _clock
clock_t __cdecl clock()
{
  return _clock();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425918; symbol: _calloc
void *__cdecl calloc(size_t a1, size_t a2)
{
  return _calloc(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425920; symbol: _abort
void __cdecl __noreturn abort()
{
  _abort();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425928; symbol: __setmode
int __cdecl _setmode(int a1, int a2)
{
  return __setmode(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425930; symbol: __isctype
int __cdecl _isctype(int a1, int a2)
{
  return __isctype(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425938; symbol: __fullpath
char *__cdecl _fullpath(char *a1, const char *a2, size_t a3)
{
  return __fullpath(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425940; symbol: __errno
int _errno(void)
{
  return __errno();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425948; symbol: __cexit
void __cdecl _cexit()
{
  __cexit();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425950; symbol: ___p__fmode
int __p__fmode(void)
{
  return ___p__fmode();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425958; symbol: ___p__environ
int __p__environ(void)
{
  return ___p__environ();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425960; symbol: ___getmainargs
int __cdecl __getmainargs(int a1, int a2, int a3, int a4, int a5)
{
  return ___getmainargs(a1, a2, a3, a4, a5);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425998; symbol: _TranslateMessage@4
BOOL __stdcall TranslateMessage(const MSG *lpMsg)
{
  return TranslateMessage(lpMsg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259A0; symbol: _SystemParametersInfoA@16
BOOL __stdcall SystemParametersInfoA(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni)
{
  return SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259D0; symbol: _SetCursor@4
HCURSOR __stdcall SetCursor(HCURSOR hCursor)
{
  return SetCursor(hCursor);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259D8; symbol: _SendMessageA@16
LRESULT __stdcall SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return SendMessageA(hWnd, Msg, wParam, lParam);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259E0; symbol: _ReleaseDC@8
int __stdcall ReleaseDC(HWND hWnd, HDC hDC)
{
  return ReleaseDC(hWnd, hDC);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259F8; symbol: _MessageBoxW@16
int __stdcall MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
  return MessageBoxW(hWnd, lpText, lpCaption, uType);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A00; symbol: _MessageBoxA@16
int __stdcall MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
  return MessageBoxA(hWnd, lpText, lpCaption, uType);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A18; symbol: _IsZoomed@4
BOOL __stdcall IsZoomed(HWND hWnd)
{
  return IsZoomed(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A20; symbol: _IsIconic@4
BOOL __stdcall IsIconic(HWND hWnd)
{
  return IsIconic(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A28; symbol: _InvalidateRect@12
BOOL __stdcall InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase)
{
  return InvalidateRect(hWnd, lpRect, bErase);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A48; symbol: _GetSystemMetrics@4
int __stdcall GetSystemMetrics(int nIndex)
{
  return GetSystemMetrics(nIndex);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A50; symbol: _GetMonitorInfoA@8
BOOL __stdcall GetMonitorInfoA(HMONITOR hMonitor, LPMONITORINFO lpmi)
{
  return GetMonitorInfoA(hMonitor, lpmi);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：处理窗口消息循环。
// Address: 0x00425A58; symbol: _GetMessageA@16
BOOL __stdcall GetMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
  return GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A68; symbol: _GetDC@4
HDC __stdcall GetDC(HWND hWnd)
{
  return GetDC(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A70; symbol: _GetCursorPos@4
BOOL __stdcall GetCursorPos(LPPOINT lpPoint)
{
  return GetCursorPos(lpPoint);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A78; symbol: _GetAsyncKeyState@4
SHORT __stdcall GetAsyncKeyState(int vKey)
{
  return GetAsyncKeyState(vKey);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A80; symbol: _FrameRect@12
int __stdcall FrameRect(HDC hDC, const RECT *lprc, HBRUSH hbr)
{
  return FrameRect(hDC, lprc, hbr);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A90; symbol: _FillRect@12
int __stdcall FillRect(HDC hDC, const RECT *lprc, HBRUSH hbr)
{
  return FillRect(hDC, lprc, hbr);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A98; symbol: _EnumDisplayMonitors@16
BOOL __stdcall EnumDisplayMonitors(HDC hdc, LPCRECT lprcClip, MONITORENUMPROC lpfnEnum, LPARAM dwData)
{
  return EnumDisplayMonitors(hdc, lprcClip, lpfnEnum, dwData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AA0; symbol: _DrawTextW@20
int __stdcall DrawTextW(HDC hDC, LPCWSTR lpString, int nCount, LPRECT lpRect, UINT uFormat)
{
  return DrawTextW(hDC, lpString, nCount, lpRect, uFormat);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AA8; symbol: _DrawTextA@20
int __stdcall DrawTextA(HDC hDC, LPCSTR lpString, int nCount, LPRECT lpRect, UINT uFormat)
{
  return DrawTextA(hDC, lpString, nCount, lpRect, uFormat);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AB0; symbol: _DispatchMessageA@4
LONG __stdcall DispatchMessageA(const MSG *lpMsg)
{
  return DispatchMessageA(lpMsg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AD8; symbol: _lstrcpyA@8
LPSTR __stdcall lstrcpyA(LPSTR lpString1, LPCSTR lpString2)
{
  return lstrcpyA(lpString1, lpString2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AE0; symbol: _lstrcmpA@8
int __stdcall lstrcmpA(LPCSTR lpString1, LPCSTR lpString2)
{
  return lstrcmpA(lpString1, lpString2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AE8; symbol: _lstrcatA@8
LPSTR __stdcall lstrcatA(LPSTR lpString1, LPCSTR lpString2)
{
  return lstrcatA(lpString1, lpString2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AF0; symbol: _VirtualQuery@12
DWORD __stdcall VirtualQuery(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, DWORD dwLength)
{
  return VirtualQuery(lpAddress, lpBuffer, dwLength);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AF8; symbol: _VirtualProtect@16
BOOL __stdcall VirtualProtect(LPVOID lpAddress, DWORD dwSize, DWORD flNewProtect, PDWORD lpflOldProtect)
{
  return VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B00; symbol: _TlsGetValue@4
LPVOID __stdcall TlsGetValue(DWORD dwTlsIndex)
{
  return TlsGetValue(dwTlsIndex);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B08; symbol: _Sleep@4
void __stdcall Sleep(DWORD dwMilliseconds)
{
  Sleep(dwMilliseconds);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B18; symbol: _RemoveDirectoryA@4
BOOL __stdcall RemoveDirectoryA(LPCSTR lpPathName)
{
  return RemoveDirectoryA(lpPathName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B20; symbol: _ReleaseMutex@4
BOOL __stdcall ReleaseMutex(HANDLE hMutex)
{
  return ReleaseMutex(hMutex);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B28; symbol: _ReadFile@20
BOOL __stdcall ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped)
{
  return ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B30; symbol: _QueryPerformanceFrequency@4
BOOL __stdcall QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency)
{
  return QueryPerformanceFrequency(lpFrequency);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B38; symbol: _QueryPerformanceCounter@4
BOOL __stdcall QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount)
{
  return QueryPerformanceCounter(lpPerformanceCount);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B40; symbol: _MultiByteToWideChar@24
int __stdcall MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cchMultiByte, LPWSTR lpWideCharStr, int cchWideChar)
{
  return MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cchMultiByte, lpWideCharStr, cchWideChar);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B50; symbol: _LeaveCriticalSection@4
void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B58; symbol: _InitializeCriticalSection@4
void __stdcall InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  InitializeCriticalSection(lpCriticalSection);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B68; symbol: _GetTickCount@0
DWORD __stdcall GetTickCount()
{
  return GetTickCount();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B70; symbol: _GetTempPathA@8
DWORD __stdcall GetTempPathA(DWORD nBufferLength, LPSTR lpBuffer)
{
  return GetTempPathA(nBufferLength, lpBuffer);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B78; symbol: _GetStartupInfoA@4
void __stdcall GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo)
{
  GetStartupInfoA(lpStartupInfo);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B80; symbol: _GetProcAddress@8
FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
  return GetProcAddress(hModule, lpProcName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B88; symbol: _GetModuleHandleA@4
HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName)
{
  return GetModuleHandleA(lpModuleName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B90; symbol: _GetLastError@0
DWORD __stdcall GetLastError()
{
  return GetLastError();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B98; symbol: _GetFileAttributesA@4
DWORD __stdcall GetFileAttributesA(LPCSTR lpFileName)
{
  return GetFileAttributesA(lpFileName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BA0; symbol: _GetCommandLineA@0
LPSTR __stdcall GetCommandLineA()
{
  return GetCommandLineA();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BA8; symbol: _FreeLibrary@4
BOOL __stdcall FreeLibrary(HMODULE hLibModule)
{
  return FreeLibrary(hLibModule);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BB0; symbol: _FindNextFileA@8
BOOL __stdcall FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData)
{
  return FindNextFileA(hFindFile, lpFindFileData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BB8; symbol: _FindFirstFileA@8
HANDLE __stdcall FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData)
{
  return FindFirstFileA(lpFileName, lpFindFileData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BC0; symbol: _FindClose@4
BOOL __stdcall FindClose(HANDLE hFindFile)
{
  return FindClose(hFindFile);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BC8; symbol: _ExitThread@4
void __stdcall __noreturn ExitThread(DWORD dwExitCode)
{
  ExitThread(dwExitCode);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BD0; symbol: _ExitProcess@4
void __stdcall __noreturn ExitProcess(UINT uExitCode)
{
  ExitProcess(uExitCode);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BD8; symbol: _EnterCriticalSection@4
void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BE0; symbol: _DeleteFileA@4
BOOL __stdcall DeleteFileA(LPCSTR lpFileName)
{
  return DeleteFileA(lpFileName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BE8; symbol: _DeleteCriticalSection@4
void __stdcall DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BF0; symbol: _CreateThread@24
HANDLE __stdcall CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, DWORD dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId)
{
  return CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BF8; symbol: _CreateMutexA@12
HANDLE __stdcall CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
  return CreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C00; symbol: _CreateFileA@28
HANDLE __stdcall CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
  return CreateFileA(
           lpFileName,
           dwDesiredAccess,
           dwShareMode,
           lpSecurityAttributes,
           dwCreationDisposition,
           dwFlagsAndAttributes,
           hTemplateFile);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C08; symbol: _CreateDirectoryA@8
BOOL __stdcall CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
  return CreateDirectoryA(lpPathName, lpSecurityAttributes);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C10; symbol: _CloseHandle@4
BOOL __stdcall CloseHandle(HANDLE hObject)
{
  return CloseHandle(hObject);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C18; symbol: _stricoll
int __cdecl stricoll(int a1, int a2)
{
  return _stricoll(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C20; symbol: _strdup
char *__cdecl strdup(const char *a1)
{
  return _strdup(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00426620; symbol: __ZdlPv
void __cdecl operator delete(void *a1)
{
  free(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00426630; symbol: __ZdlPvj
void __cdecl operator delete(void *a1)
{
  operator delete(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00426640; symbol: _main_0
int __cdecl main_0(int a1)
{
  LPSTR v1; // ebx
  CHAR v2; // al
  int v3; // esi
  HINSTANCE__ *v4; // eax
  LPSTR v6; // edx
  CHAR v7; // al
  struct _STARTUPINFOA StartupInfo; // [esp+0h] [ebp-5Ch]
  int *v9; // [esp+50h] [ebp-Ch]

  v9 = &a1;
  __main();
  v1 = GetCommandLineA();
  GetStartupInfoA(&StartupInfo);
  if ( v1 )
  {
    while ( 1 )
    {
      v2 = *v1;
      if ( *v1 != 32 && v2 != 9 )
        break;
      ++v1;
    }
    if ( v2 == 34 )
    {
      do
      {
        v6 = v1++;
        v7 = *v1;
      }
      while ( *v1 != 34 && v7 );
      if ( v7 == 34 )
        v1 = v6 + 2;
    }
    else
    {
      while ( *v1 & 0xDF && *v1 != 9 )
        ++v1;
    }
    while ( *v1 == 32 || *v1 == 9 )
      ++v1;
  }
  v3 = 10;
  if ( StartupInfo.dwFlags & 1 )
    v3 = StartupInfo.wShowWindow;
  v4 = GetModuleHandleA(0);
  return WinMain(v4, 0, v1, v3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00401300; symbol: _WinMainCRTStartup
void __noreturn WinMainCRTStartup()
{
  ___set_app_type(2);
  sub_4011B0();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405B2A; symbol: __Z7WndProcP6HWND__jjl@16
LRESULT __stdcall WndProc(HWND hW, UINT uM, WPARAM wP, LPARAM lP)
{
  bool v4; // al
  bool v5; // al
  HICON__ *v6; // eax

  if ( uM == 15 )
  {
    if ( _draw )
      _draw();
  }
  else if ( uM > 0xF )
  {
    if ( uM == 32 )
    {
      v5 = GetMousePosX() >= 0
        && GetMousePosY() >= 0
        && GetMousePosX() <= (signed int)_w
        && GetMousePosY() <= (signed int)_h;
      if ( v5 )
      {
        v6 = LoadCursorA(0, (LPCSTR)0x7F00);
        SetCursor(v6);
      }
    }
    else if ( uM > 0x20 )
    {
      if ( uM == 134 )
      {
        v4 = wP & 0xB && IsIconic(hW);
        if ( v4 )
        {
          ShowWindow(hW, 5);
          SetForegroundWindow(hW);
        }
      }
      else if ( uM == 1024 )
      {
        _msusr[_msusri].message = 1024;
        _msusr[_msusri].wParam = wP;
        _msusr[_msusri++].lParam = lP;
        if ( _msusri > 0x1000 )
          _msusri = 1;
      }
    }
    else if ( uM == 16 )
    {
      DestroyWindow(hW);
    }
  }
  else
  {
    if ( uM == 2 )
    {
      timeEndPeriod(1u);
      _hw = 0;
      _dc = 0;
      _winb = 0;
      ExitThread(0);
    }
    if ( uM > 2 )
    {
      if ( uM == 3 )
      {
        if ( _draw )
          _draw();
      }
      else if ( uM == 5 )
      {
        _w = (unsigned __int16)(((unsigned __int64)lP >> 48) + lP) - ((unsigned int)(lP >> 31) >> 16);
        _h = lP / 0x10000;
        WinCreateMain();
        if ( _draw )
          _draw();
      }
    }
    else if ( uM == 1 )
    {
      timeBeginPeriod(1u);
    }
  }
  return DefWindowProcW(hW, uM, wP, lP);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040C2E4; symbol: __ZN6WindowC1Ev
void __cdecl Window::Window(Window *const this)
{
  Window *v1; // ecx
  Window *v2; // ST1C_4
  Board *const v3; // ST00_4
  Block *const v4; // ST00_4
  Window *const v5; // ST00_4
  Reg *v6; // [esp+0h] [ebp-28h]

  v2 = v1;
  v1->launchw = 320;
  v1->launchh = 368;
  v1->titlew = 256;
  v1->titleh = 256;
  v1->menuw = 24;
  v1->menuh = 24;
  v1->facew = 24;
  v1->faceh = 24;
  v1->iconw = 16;
  v1->iconh = 16;
  v1->digtw[0] = 13;
  v1->digtw[1] = 9;
  v1->digtw[2] = 13;
  v1->digth[0] = 24;
  v1->digth[1] = 17;
  v1->digth[2] = 24;
  v1->okw = 144;
  v1->okh = 36;
  v1->btnw = 36;
  v1->btnh = 36;
  v1->tutw = 120;
  v1->tuth = 36;
  v1->aboutw = 360;
  v1->abouth = 240;
  v1->helpw = 640;
  v1->helph = 480;
  v1->fontth = 64;
  v1->fontfh = 32;
  v1->fonth = 24;
  v1->fontsh = 17;
  v1->fontmh = 13;
  v2->okh_ = v1->abouth - (v2->fontth + 4 * v2->fonth);
  v1->cursorw = 12;
  v1->cursorh = 19;
  v1->clickw = 48;
  v1->clickh = 72;
  v1->arroww = 24;
  v1->arrowh = 24;
  v1->ptitle_ = 0;
  v1->pbg_ = 0;
  v1->pmenu_ = 0;
  v1->pmenu1[0] = 0;
  v1->pmenu1[1] = 0;
  v1->pmenu2[0] = 0;
  v1->pmenu2[1] = 0;
  v1->pmenu3[0] = 0;
  v1->pmenu3[1] = 0;
  v1->pmenuq[0] = 0;
  v1->pmenuq[1] = 0;
  v1->pmenua[0] = 0;
  v1->pmenua[1] = 0;
  v1->pmenus[0] = 0;
  v1->pmenus[1] = 0;
  v1->pmenum[0] = 0;
  v1->pmenum[1] = 0;
  v1->pmenut[0] = 0;
  v1->pmenut[1] = 0;
  v1->pmenud[0] = 0;
  v1->pmenud[1] = 0;
  v1->pmenun[0] = 0;
  v1->pmenun[1] = 0;
  memset(v1->pmenug, 0, sizeof(v1->pmenug));
  v1->pface_ = 0;
  memset(v1->pface, 0, sizeof(v1->pface));
  v1->picon_ = 0;
  memset(v1->picon, 0, sizeof(v1->picon));
  v1->piconc = 0;
  v1->piconq = 0;
  v1->piconf = 0;
  v1->piconm = 0;
  v1->picone = 0;
  v1->piconn = 0;
  v1->piconp = 0;
  v1->picona = 0;
  v1->piconu = 0;
  v1->pdigt_[0] = 0;
  v1->pdigt_[1] = 0;
  v1->pdigt_[2] = 0;
  memset(v1->pdigt, 0, sizeof(v1->pdigt));
  v1->pdigtmin[0] = 0;
  v1->pdigtmin[1] = 0;
  v1->pdigtmin[2] = 0;
  v1->pdigtnul[0] = 0;
  v1->pdigtnul[1] = 0;
  v1->pdigtnul[2] = 0;
  v1->pok_ = 0;
  v1->pok = 0;
  v1->pbtn = 0;
  v1->pcursor_ = 0;
  v1->pcursor = 0;
  v1->pclick_ = 0;
  v1->pclickl = 0;
  v1->pclickr = 0;
  v1->pclickn = 0;
  v1->pclicka = 0;
  v1->parrow_ = 0;
  v1->parrowl = 0;
  v1->parrowr = 0;
  v1->parrowu = 0;
  v1->parrowd = 0;
  v1->parrowm = 0;
  v1->parrowp = 0;
  v1->transparent = 1;
  v1->color[0] = 12632256;
  v1->color[1] = 11513775;
  v1->color[2] = 65793;
  v1->color[3] = 12632256;
  v1->color[4] = 255;
  v1->color[5] = 16711680;
  v1->color[6] = 0x8000;
  v1->color[7] = 8421504;
  v1->color[8] = 12632256;
  v1->colori = 0;
  v1->transparent_ = 11513775;
  v1->isbmp = 0;
  Reg::Reg(v6);
  Board::Board(v3);
  Block::Block(v4);
  v2->maxhelp = 6;
  v2->helpi = 0;
  v2->helpb = 1;
  v2->cheatb = 0;
  v2->waitb = 0;
  v2->pwin = 0;
  v2->pwint = 0;
  v2->minh = 600;
  v2->minw = 800;
  v2->mult_ = 0;
  v2->mult = 1.0;
  v2->showmax = 0;
  v2->showmax_ = 0;
  v2->w_ = 0;
  v2->h_ = 0;
  v2->x_ = 0;
  v2->y_ = 0;
  v2->xscr = 0;
  v2->yscr = 0;
  v2->wscr = 0;
  v2->hscr = 0;
  v2->barb = 1;
  v2->md = 0;
  v2->ml = 0;
  v2->mr = 0;
  v2->mx = -1;
  v2->my = -1;
  v2->mi = 0;
  v2->lead_5 = 0;
  v2->singleb = 0;
  v2->boardb = 0;
  v2->timerefresh = 0.0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&v2->cs);
  Window::initwindow(v5);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040CA6C; symbol: __ZN6WindowD1Ev
void __cdecl Window::~Window(Window *const this)
{
  Window *v1; // ecx
  Window *v2; // ST1C_4
  Board *const v3; // ST00_4
  Reg *const v4; // ST00_4
  Window *v5; // [esp+0h] [ebp-28h]

  v2 = v1;
  Window::releasewindow(v5);
  DeleteCriticalSection((LPCRITICAL_SECTION)&v2->cs);
  Board::~Board(v3);
  Reg::~Reg(v4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040CAB4; symbol: __ZN6Window16loadsettingcloudEv
void __cdecl Window::loadsettingcloud(Window *const this)
{
  Window *v1; // ecx
  ISteamRemoteStorage *v2; // eax
  ISteamRemoteStorage *v3; // eax
  ISteamRemoteStorage *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  Window *thisa; // [esp+1Ch] [ebp-3Ch]
  int buf[9]; // [esp+28h] [ebp-30h]
  int pos; // [esp+4Ch] [ebp-Ch]

  thisa = v1;
  if ( SteamRemoteStorage() != 0 )
  {
    v2 = SteamRemoteStorage();
    if ( !((*(unsigned __int8 (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v2 + 52))(
             v2,
             *(_DWORD *)(*(_DWORD *)v2 + 52)) ^ 1) )
    {
      memset(buf, 0, sizeof(buf));
      v3 = SteamRemoteStorage();
      if ( (*(int (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v3 + 60))(
             v3,
             *(_DWORD *)(*(_DWORD *)v3 + 60)) == 36 )
      {
        v4 = SteamRemoteStorage();
        (*(void (__fastcall **)(ISteamRemoteStorage *, int *, const char *, int *))(*(_DWORD *)v4 + 4))(
          v4,
          buf,
          "reg.dat",
          buf);
        pos = 1;
        thisa->helpb = buf[0] != 0;
        v5 = pos++;
        thisa->colori = buf[v5];
        v6 = pos++;
        thisa->md = buf[v6];
        v7 = pos++;
        thisa->bd.sd.soundb = buf[v7] != 0;
        v8 = pos++;
        thisa->bd.sd.musicb = buf[v8] != 0;
        v9 = pos++;
        thisa->mult_ = buf[v9];
        v10 = pos++;
        thisa->bd.delayb = buf[v10];
        v11 = pos++;
        thisa->barb = buf[v11] != 0;
        v12 = pos++;
        thisa->singleb = buf[v12] != 0;
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040CC4E; symbol: __ZN6Window16savesettingcloudEv
void __cdecl Window::savesettingcloud(Window *const this)
{
  Window *v1; // ecx
  ISteamRemoteStorage *v2; // eax
  Window *thisa; // [esp+1Ch] [ebp-3Ch]
  int buf[9]; // [esp+28h] [ebp-30h]
  int pos; // [esp+4Ch] [ebp-Ch]

  thisa = v1;
  if ( SteamRemoteStorage() != 0 )
  {
    pos = 1;
    buf[0] = thisa->helpb;
    pos = 2;
    buf[1] = thisa->colori;
    pos = 3;
    buf[2] = thisa->md;
    pos = 4;
    buf[3] = thisa->bd.sd.soundb;
    pos = 5;
    buf[4] = thisa->bd.sd.musicb;
    pos = 6;
    buf[5] = thisa->mult_;
    pos = 7;
    buf[6] = thisa->bd.delayb;
    pos = 8;
    buf[7] = thisa->barb;
    pos = 9;
    buf[8] = thisa->singleb;
    v2 = SteamRemoteStorage();
    (**(void (__fastcall ***)(ISteamRemoteStorage *, int *, const char *, int *))v2)(v2, buf, "reg.dat", buf);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040CD7A; symbol: __ZN6Window11loadsettingEv
void __cdecl Window::loadsetting(Window *const this)
{
  int v1; // ecx
  Window *v2; // ST1C_4
  int *v3; // ST0C_4
  int *v4; // ST0C_4
  int *v5; // ST0C_4
  int *v6; // ST0C_4
  int *v7; // ST0C_4
  int *v8; // ST0C_4
  int *v9; // ST0C_4
  int *v10; // ST0C_4
  Window *const v11; // ST00_4
  int *v12; // [esp+Ch] [ebp-1Ch]

  v2 = (Window *)v1;
  Reg::getreg(v1 + 736, *(Reg *const *)(v1 + 736), &key, (const char *)(v1 + 3380), v12);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_428FF2, (const char *)&v2->colori, v3);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &unk_428FF9, (const char *)&v2->md, v4);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_428FFC, (const char *)&v2->bd.sd.soundb, v5);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_429003, (const char *)&v2->bd.sd.musicb, v6);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_42900A, (const char *)&v2->mult_, v7);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_42900F, (const char *)&v2->bd.delayb, v8);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_429016, (const char *)&v2->barb, v9);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_42901B, (const char *)&v2->singleb, v10);
  Window::loadsettingcloud(v11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040CF64; symbol: __ZN6Window11savesettingEv
void __cdecl Window::savesetting(Window *const this)
{
  int v1; // ecx
  Window *v2; // ST1C_4
  int v3; // ST0C_4
  int v4; // ST0C_4
  int v5; // ST0C_4
  int v6; // ST0C_4
  int v7; // ST0C_4
  int v8; // ST0C_4
  int v9; // ST0C_4
  int v10; // ST0C_4
  Window *const v11; // ST00_4
  int v12; // [esp+Ch] [ebp-1Ch]

  v2 = (Window *)v1;
  Reg::setreg(*(Reg *const *)(v1 + 736), &key, (const char *)*(unsigned __int8 *)(v1 + 3380), v12);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_428FF2, (const char *)v2->colori, v3);
  Reg::setreg((Reg *const )v2->reg.regkey, &unk_428FF9, (const char *)v2->md, v4);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_428FFC, (const char *)v2->bd.sd.soundb, v5);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_429003, (const char *)v2->bd.sd.musicb, v6);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_42900A, (const char *)v2->mult_, v7);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_42900F, (const char *)v2->bd.delayb, v8);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_429016, (const char *)v2->barb, v9);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_42901B, (const char *)v2->singleb, v10);
  Window::savesettingcloud(v11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040D150; symbol: __ZN6Window14loadboardcloudEv
void __cdecl Window::loadboardcloud(Window *const this)
{
  int v1; // eax
  int v2; // ecx
  void *v3; // esp
  ISteamRemoteStorage *v4; // eax
  ISteamRemoteStorage *v5; // eax
  ISteamRemoteStorage *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  Block *const v30; // ST00_4
  int v31; // [esp+1Ch] [ebp-1407Ch]
  int v32[25]; // [esp+28h] [ebp-14070h]
  char v33; // [esp+8Ch] [ebp-1400Ch]
  char v34; // [esp+408Ch] [ebp-1000Ch]
  char v35; // [esp+808Ch] [ebp-C00Ch]
  char v36; // [esp+C08Ch] [ebp-800Ch]
  char v37; // [esp+1008Ch] [ebp-400Ch]
  int v38; // [esp+1408Ch] [ebp-Ch]

  v3 = alloca(v1);
  v31 = v2;
  if ( SteamRemoteStorage() != 0 )
  {
    v4 = SteamRemoteStorage();
    if ( !((*(unsigned __int8 (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v4 + 52))(
             v4,
             *(_DWORD *)(*(_DWORD *)v4 + 52)) ^ 1) )
    {
      v5 = SteamRemoteStorage();
      if ( (*(int (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v5 + 60))(
             v5,
             *(_DWORD *)(*(_DWORD *)v5 + 60)) == 82020 )
      {
        v6 = SteamRemoteStorage();
        (*(void (__fastcall **)(ISteamRemoteStorage *, int *, const char *, int *))(*(_DWORD *)v6 + 4))(
          v6,
          v32,
          "board.dat",
          v32);
        v38 = 1;
        *(_DWORD *)(v31 + 2896) = v32[0];
        v7 = v38++;
        *(_DWORD *)(v31 + 768) = v32[v7];
        v8 = v38++;
        *(_DWORD *)(v31 + 772) = v32[v8];
        v9 = v38++;
        *(_DWORD *)(v31 + 776) = v32[v9];
        v10 = v38++;
        *(_DWORD *)(v31 + 2916) = v32[v10];
        v11 = v38++;
        *(_DWORD *)(v31 + 780) = v32[v11];
        v12 = v38++;
        *(_DWORD *)(v31 + 2924) = v32[v12];
        v13 = v38++;
        *(_DWORD *)(v31 + 2928) = v32[v13];
        v14 = v38++;
        *(_DWORD *)(v31 + 2956) = v32[v14];
        v15 = v38++;
        *(_DWORD *)(v31 + 2960) = v32[v15];
        v16 = v38++;
        *(_DWORD *)(v31 + 2964) = v32[v16];
        v17 = v38++;
        *(_DWORD *)(v31 + 2972) = v32[v17];
        v18 = v38++;
        *(_DWORD *)(v31 + 788) = v32[v18];
        v19 = v38++;
        *(_DWORD *)(v31 + 792) = v32[v19];
        v20 = v38++;
        *(_DWORD *)(v31 + 2908) = v32[v20];
        v21 = v38++;
        *(_DWORD *)(v31 + 3044) = v32[v21];
        v22 = v38++;
        *(_DWORD *)(v31 + 3040) = v32[v22];
        v23 = v38++;
        *(_DWORD *)(v31 + 2940) = v32[v23];
        v24 = v38++;
        *(_DWORD *)(v31 + 784) = v32[v24];
        v25 = v38++;
        *(_DWORD *)(v31 + 3032) = v32[v25];
        v26 = v38++;
        *(_DWORD *)(v31 + 3036) = v32[v26];
        v27 = v38++;
        *(_DWORD *)(v31 + 2968) = v32[v27];
        v28 = v38++;
        *(_DWORD *)(v31 + 3024) = v32[v28];
        v29 = v38++;
        *(_DWORD *)(v31 + 3300) = v32[v29];
        memcpy(*(void **)(v31 + 804), &v33, 0x4000u);
        memcpy(*(void **)(v31 + 808), &v34, 0x4000u);
        memcpy(*(void **)(v31 + 812), &v35, 0x4000u);
        memcpy(*(void **)(v31 + 816), &v36, 0x4000u);
        memcpy(*(void **)(v31 + 820), &v37, 0x4000u);
        Block::calcnumb(v30);
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040D588; symbol: __ZN6Window14saveboardcloudEv
void __cdecl Window::saveboardcloud(Window *const this)
{
  int v1; // eax
  int v2; // ecx
  void *v3; // esp
  ISteamRemoteStorage *v4; // eax
  int v5; // [esp+1Ch] [ebp-1407Ch]
  int v6; // [esp+28h] [ebp-14070h]
  int v7; // [esp+2Ch] [ebp-1406Ch]
  int v8; // [esp+30h] [ebp-14068h]
  int v9; // [esp+34h] [ebp-14064h]
  int v10; // [esp+38h] [ebp-14060h]
  int v11; // [esp+3Ch] [ebp-1405Ch]
  int v12; // [esp+40h] [ebp-14058h]
  int v13; // [esp+44h] [ebp-14054h]
  int v14; // [esp+48h] [ebp-14050h]
  int v15; // [esp+4Ch] [ebp-1404Ch]
  int v16; // [esp+50h] [ebp-14048h]
  int v17; // [esp+54h] [ebp-14044h]
  int v18; // [esp+58h] [ebp-14040h]
  int v19; // [esp+5Ch] [ebp-1403Ch]
  int v20; // [esp+60h] [ebp-14038h]
  int v21; // [esp+64h] [ebp-14034h]
  int v22; // [esp+68h] [ebp-14030h]
  int v23; // [esp+6Ch] [ebp-1402Ch]
  int v24; // [esp+70h] [ebp-14028h]
  int v25; // [esp+74h] [ebp-14024h]
  int v26; // [esp+78h] [ebp-14020h]
  int v27; // [esp+7Ch] [ebp-1401Ch]
  int v28; // [esp+80h] [ebp-14018h]
  int v29; // [esp+84h] [ebp-14014h]
  char v30; // [esp+8Ch] [ebp-1400Ch]
  char v31; // [esp+408Ch] [ebp-1000Ch]
  char v32; // [esp+808Ch] [ebp-C00Ch]
  char v33; // [esp+C08Ch] [ebp-800Ch]
  char v34; // [esp+1008Ch] [ebp-400Ch]
  int v35; // [esp+1408Ch] [ebp-Ch]

  v3 = alloca(v1);
  v5 = v2;
  if ( SteamRemoteStorage() != 0 )
  {
    v35 = 1;
    v6 = *(_DWORD *)(v5 + 2896);
    v35 = 2;
    v7 = *(_DWORD *)(v5 + 768);
    v35 = 3;
    v8 = *(_DWORD *)(v5 + 772);
    v35 = 4;
    v9 = *(_DWORD *)(v5 + 776);
    v35 = 5;
    v10 = *(_DWORD *)(v5 + 2916);
    v35 = 6;
    v11 = *(_DWORD *)(v5 + 780);
    v35 = 7;
    v12 = *(_DWORD *)(v5 + 2924);
    v35 = 8;
    v13 = *(_DWORD *)(v5 + 2928);
    v35 = 9;
    v14 = *(_DWORD *)(v5 + 2956);
    v35 = 10;
    v15 = *(_DWORD *)(v5 + 2960);
    v35 = 11;
    v16 = *(_DWORD *)(v5 + 2964);
    v35 = 12;
    v17 = *(_DWORD *)(v5 + 2972);
    v35 = 13;
    v18 = *(_DWORD *)(v5 + 788);
    v35 = 14;
    v19 = *(_DWORD *)(v5 + 792);
    v35 = 15;
    v20 = *(_DWORD *)(v5 + 2908);
    v35 = 16;
    v21 = *(_DWORD *)(v5 + 3044);
    v35 = 17;
    v22 = *(_DWORD *)(v5 + 3040);
    v35 = 18;
    v23 = *(_DWORD *)(v5 + 2940);
    v35 = 19;
    v24 = *(_DWORD *)(v5 + 784);
    v35 = 20;
    v25 = *(_DWORD *)(v5 + 3032);
    v35 = 21;
    v26 = *(_DWORD *)(v5 + 3036);
    v35 = 22;
    v27 = *(_DWORD *)(v5 + 2968);
    v35 = 23;
    v28 = *(_DWORD *)(v5 + 3024);
    v35 = 24;
    v29 = *(_DWORD *)(v5 + 3300);
    memcpy(&v30, *(const void **)(v5 + 804), 0x4000u);
    memcpy(&v31, *(const void **)(v5 + 808), 0x4000u);
    memcpy(&v32, *(const void **)(v5 + 812), 0x4000u);
    memcpy(&v33, *(const void **)(v5 + 816), 0x4000u);
    memcpy(&v34, *(const void **)(v5 + 820), 0x4000u);
    v4 = SteamRemoteStorage();
    (**(void (__fastcall ***)(ISteamRemoteStorage *, int *, const char *, int *))v4)(v4, &v6, "board.dat", &v6);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040D94C; symbol: __ZN6Window9loadboardEv
void __cdecl Window::loadboard(Window *const this)
{
  int v1; // ecx
  Window *v2; // ST1C_4
  int *v3; // ST0C_4
  int *v4; // ST0C_4
  int *v5; // ST0C_4
  int *v6; // ST0C_4
  int *v7; // ST0C_4
  int *v8; // ST0C_4
  int *v9; // ST0C_4
  int *v10; // ST0C_4
  int *v11; // ST0C_4
  int *v12; // ST0C_4
  int *v13; // ST0C_4
  int *v14; // ST0C_4
  int *v15; // ST0C_4
  int *v16; // ST0C_4
  int *v17; // ST0C_4
  int *v18; // ST0C_4
  int *v19; // ST0C_4
  int *v20; // ST0C_4
  int *v21; // ST0C_4
  int *v22; // ST0C_4
  int *v23; // ST0C_4
  int *v24; // ST0C_4
  int *v25; // ST0C_4
  char *v26; // ST0C_4
  char *v27; // ST0C_4
  char *v28; // ST0C_4
  char *v29; // ST0C_4
  char *v30; // ST0C_4
  Window *const v31; // ST00_4
  Block *const v32; // ST00_4
  int *v33; // [esp+Ch] [ebp-1Ch]

  v2 = (Window *)v1;
  Reg::getreg(v1 + 736, *(Reg *const *)(v1 + 740), &stru_42902D, (const char *)(v1 + 2896), v33);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &unk_429032, (const char *)&v2->bd, v3);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &unk_429034, (const char *)&v2->bd.h, v4);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &unk_429036, (const char *)&v2->bd.n, v5);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429038, (const char *)&v2->bd.maskj0, v6);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42903F, (const char *)&v2->bd.sit, v7);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429043, (const char *)&v2->bd.line, v8);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429048, (const char *)&v2->bd.level, v9);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42904E, (const char *)&v2->bd.tetrisi, v10);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429056, (const char *)&v2->bd.missi, v11);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42905C, (const char *)&v2->bd.missline, v12);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429065, (const char *)&v2->bd.sum, v13);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429069, (const char *)&v2->bd.maskj, v14);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42906F, (const char *)&v2->bd.maski, v15);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429075, (const char *)&v2->bd.rightb, v16);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42907C, (const char *)&v2->bd.tuti, v17);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429081, (const char *)&v2->bd.tutb, v18);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429086, (const char *)&v2->bd.checkr, v19);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42908D, (const char *)&v2->bd.pauseb, v20);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &unk_429094, (const char *)&v2->bd.mx, v21);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &unk_429097, (const char *)&v2->bd.my, v22);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42909A, (const char *)&v2->bd.bouns, v23);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_4290A0, (const char *)&v2->bd.mdb, v24);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_4290A4, (const char *)&v2->bd.solven, v25);
  Reg::getreg_(
    (int)v2->reg.regkey_,
    (int)&v2->reg,
    (Reg *const )v2->reg.regkey_,
    &stru_4290AB,
    (const char *)v2->bd.flag,
    v26);
  Reg::getreg_(
    (int)v2->reg.regkey_,
    (int)&v2->reg,
    (Reg *const )v2->reg.regkey_,
    &stru_4290B0,
    (const char *)v2->bd.qstn,
    v27);
  Reg::getreg_(
    (int)v2->reg.regkey_,
    (int)&v2->reg,
    (Reg *const )v2->reg.regkey_,
    &stru_4290B5,
    (const char *)v2->bd.mine,
    v28);
  Reg::getreg_(
    (int)v2->reg.regkey_,
    (int)&v2->reg,
    (Reg *const )v2->reg.regkey_,
    &stru_4290BA,
    (const char *)v2->bd.blck,
    v29);
  Reg::getreg_(
    (int)v2->reg.regkey_,
    (int)&v2->reg,
    (Reg *const )v2->reg.regkey_,
    &stru_4290BF,
    (const char *)v2->bd.mask,
    v30);
  Window::loadboardcloud(v31);
  Block::calcnumb(v32);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040DF60; symbol: __ZN6Window9saveboardEv
void __cdecl Window::saveboard(Window *const this)
{
  int v1; // ecx
  Window *v2; // ST1C_4
  int v3; // ST0C_4
  int v4; // ST0C_4
  int v5; // ST0C_4
  int v6; // ST0C_4
  int v7; // ST0C_4
  int v8; // ST0C_4
  int v9; // ST0C_4
  int v10; // ST0C_4
  int v11; // ST0C_4
  int v12; // ST0C_4
  int v13; // ST0C_4
  int v14; // ST0C_4
  int v15; // ST0C_4
  int v16; // ST0C_4
  int v17; // ST0C_4
  int v18; // ST0C_4
  int v19; // ST0C_4
  int v20; // ST0C_4
  int v21; // ST0C_4
  int v22; // ST0C_4
  int v23; // ST0C_4
  int v24; // ST0C_4
  int v25; // ST0C_4
  char *v26; // ST0C_4
  char *v27; // ST0C_4
  char *v28; // ST0C_4
  char *v29; // ST0C_4
  char *v30; // ST0C_4
  Window *const v31; // ST00_4
  int v32; // [esp+Ch] [ebp-1Ch]

  v2 = (Window *)v1;
  Reg::setreg(*(Reg *const *)(v1 + 740), &stru_42902D, *(const char **)(v1 + 2896), v32);
  Reg::setreg((Reg *const )v2->reg.regkey_, &unk_429032, (const char *)v2->bd.w, v3);
  Reg::setreg((Reg *const )v2->reg.regkey_, &unk_429034, (const char *)v2->bd.h, v4);
  Reg::setreg((Reg *const )v2->reg.regkey_, &unk_429036, (const char *)v2->bd.n, v5);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429038, (const char *)v2->bd.maskj0, v6);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42903F, (const char *)v2->bd.sit, v7);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429043, (const char *)v2->bd.line, v8);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429048, (const char *)v2->bd.level, v9);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42904E, (const char *)v2->bd.tetrisi, v10);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429056, (const char *)v2->bd.missi, v11);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42905C, (const char *)v2->bd.missline, v12);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429065, (const char *)v2->bd.sum, v13);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429069, (const char *)v2->bd.maskj, v14);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42906F, (const char *)v2->bd.maski, v15);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429075, (const char *)v2->bd.rightb, v16);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42907C, (const char *)v2->bd.tuti, v17);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429081, (const char *)v2->bd.tutb, v18);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429086, (const char *)v2->bd.checkr, v19);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42908D, (const char *)v2->bd.pauseb, v20);
  Reg::setreg((Reg *const )v2->reg.regkey_, &unk_429094, (const char *)v2->bd.mx, v21);
  Reg::setreg((Reg *const )v2->reg.regkey_, &unk_429097, (const char *)v2->bd.my, v22);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42909A, (const char *)v2->bd.bouns, v23);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_4290A0, (const char *)v2->bd.mdb, v24);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_4290A4, (const char *)v2->bd.solven, v25);
  Reg::setreg_((Reg *const )v2->reg.regkey_, &stru_4290AB, (const char *)v2->bd.flag, v26);
  Reg::setreg_((Reg *const )v2->reg.regkey_, &stru_4290B0, (const char *)v2->bd.qstn, v27);
  Reg::setreg_((Reg *const )v2->reg.regkey_, &stru_4290B5, (const char *)v2->bd.mine, v28);
  Reg::setreg_((Reg *const )v2->reg.regkey_, &stru_4290BA, (const char *)v2->bd.blck, v29);
  Reg::setreg_((Reg *const )v2->reg.regkey_, &stru_4290BF, (const char *)v2->bd.mask, v30);
  Window::saveboardcloud(v31);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040E534; symbol: __ZN6Window12loadallpaintEv
void __cdecl Window::loadallpaint(Window *const this)
{
  int v1; // [esp+4h] [ebp-24h]

  while ( painttitleb > 0 )
  {
    if ( painttitleb == 2 )
    {
      painttitleb = 1;
      Window::painttitle(painttitlec, v1);
    }
    Sleep(1u);
  }
  painttitles = 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040E58E; symbol: __ZN6Window7loadallEv
void __cdecl Window::loadall(Window *const this)
{
  Window *v1; // ecx
  HWND__ *v2; // eax
  int v3; // ST04_4
  Window *v4; // [esp+0h] [ebp-38h]
  Steam *v5; // [esp+0h] [ebp-38h]
  Sound *v6; // [esp+0h] [ebp-38h]
  Window *v7; // [esp+0h] [ebp-38h]
  Window *v8; // [esp+0h] [ebp-38h]
  int v9; // [esp+4h] [ebp-34h]
  int v10; // [esp+4h] [ebp-34h]
  int v11; // [esp+4h] [ebp-34h]
  int v12; // [esp+4h] [ebp-34h]
  int v13; // [esp+4h] [ebp-34h]
  int v14; // [esp+8h] [ebp-30h]
  int *v15; // [esp+Ch] [ebp-2Ch]
  int v16; // [esp+Ch] [ebp-2Ch]
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  painttitleb = 1;
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)loadallpaintstatic, v1, 0, 0);
  if ( (unsigned __int8)IsWin() )
    Window::loadsetting(v4);
  Window::painttitle((Window *const )thisa->bd.st.lan.LAN_LOAD_STEAM, v9);
  if ( (unsigned __int8)IsWin() )
    Steam::loadsteam(v5);
  Window::painttitle((Window *const )thisa->bd.st.lan.LAN_LOAD_AUDIO, v10);
  if ( (unsigned __int8)IsWin() )
    Sound::initsound(v6);
  Window::painttitle((Window *const )thisa->bd.st.lan.LAN_LOAD_BOARD, v11);
  if ( (unsigned __int8)IsWin() )
  {
    Board::initbd((int)&thisa->bd, (Board *const )1, thisa->md, v14);
    Reg::getreg((int)&thisa->reg, (Reg *const )thisa->reg.regkey, &stru_4290C4, (const char *)&thisa->boardb, v15);
    thisa->bd.tutb = thisa->helpb;
    if ( thisa->boardb == 1 )
    {
      Window::loadboard(v7);
      thisa->boardb = 0;
      Reg::setreg((Reg *const )thisa->reg.regkey, &stru_4290C4, (const char *)thisa->boardb, v16);
    }
  }
  Window::painttitle((Window *const )thisa->bd.st.lan.LAN_LOAD_GRAPH, v12);
  if ( (unsigned __int8)IsWin() )
    Window::initbmp(v8);
  Window::painttitle((Window *const )thisa->bd.st.lan.LAN_LOAD_WINDOW, v13);
  if ( (unsigned __int8)IsWin() )
  {
    v2 = GetHwnd();
    SetWindowLongA(v2, -16, 281739264);
    Window::sethelp(0, v3);
  }
  painttitleb = 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040E7CA; symbol: __ZN6Window8initmultEv
void __cdecl Window::initmult(Window *const this)
{
  Window *v1; // ecx
  int v2; // ebx
  long double v3; // fst7
  int v4; // ebx
  int v5; // ebx
  long double v6; // fst7
  int v7; // ebx
  long double v8; // fst7
  long double v9; // fst7
  int v10; // ebx
  int v11; // ebx
  long double v12; // fst7
  long double v13; // fst7
  int v14; // ebx
  long double v15; // fst7
  int v16; // ebx
  int v17; // ebx
  long double v18; // fst7
  int v19; // ebx
  long double v20; // fst7
  int v21; // ebx
  int v22; // ebx
  long double v23; // fst7
  int v24; // ebx
  double v25; // ST08_8
  int v26; // ebx
  int v27; // ebx
  int v28; // ebx
  long double v29; // fst7
  int v30; // ebx
  int v31; // ebx
  long double v32; // fst7
  int v33; // ebx
  double v34; // ST08_8
  int v35; // ebx
  int v36; // ebx
  int v37; // ebx
  int v38; // ebx
  int v39; // ebx
  signed int v40; // eax
  int v41; // ebx
  double v42; // ST08_8
  int v43; // ebx
  int v44; // ebx
  int v45; // ebx
  long double v46; // fst7
  int v47; // ebx
  int v48; // ebx
  long double v49; // fst7
  int v50; // ebx
  double v51; // ST08_8
  int v52; // ebx
  int v53; // ebx
  int v54; // ebx
  int v55; // ebx
  int v56; // ebx
  long double v57; // fst7
  signed int v58; // [esp+8h] [ebp-20h]
  double v59; // [esp+8h] [ebp-20h]
  signed int v60; // [esp+8h] [ebp-20h]
  signed int v61; // [esp+8h] [ebp-20h]
  signed int v62; // [esp+8h] [ebp-20h]
  double v63; // [esp+8h] [ebp-20h]
  signed int v64; // [esp+8h] [ebp-20h]
  signed int v65; // [esp+8h] [ebp-20h]
  signed int v66; // [esp+10h] [ebp-18h]
  signed int v67; // [esp+10h] [ebp-18h]
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->mult_ )
  {
    if ( v1->mult_ == 1 )
    {
      v24 = v1->wscr;
      v25 = (long double)(v24 - 2 * GetBorderWidth()) / (long double)v1->w_;
      v26 = thisa->hscr;
      v27 = v26 - 2 * GetBorderHeight();
      if ( (long double)(v27 - GetBorderTitle()) / (long double)thisa->h_ <= v25 )
      {
        v30 = thisa->hscr;
        v31 = v30 - 2 * GetBorderHeight();
        v29 = (long double)(v31 - GetBorderTitle()) / (long double)thisa->h_;
      }
      else
      {
        v28 = thisa->wscr;
        v29 = (long double)(v28 - 2 * GetBorderWidth()) / (long double)thisa->w_;
      }
      if ( v29 >= 1.0 )
      {
        v33 = thisa->wscr;
        v34 = (long double)(v33 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        v35 = thisa->hscr;
        v36 = v35 - 2 * GetBorderHeight();
        if ( (long double)(v36 - GetBorderTitle()) / (long double)thisa->h_ <= v34 )
        {
          v38 = thisa->hscr;
          v39 = v38 - 2 * GetBorderHeight();
          v32 = (long double)(v39 - GetBorderTitle()) / (long double)thisa->h_;
        }
        else
        {
          v37 = thisa->wscr;
          v32 = (long double)(v37 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        }
      }
      else
      {
        v32 = 1.0;
      }
      thisa->mult = v32;
    }
    else
    {
      if ( v1->mult_ > 7 )
      {
        v40 = 8;
      }
      else
      {
        v40 = v1->mult_;
        if ( v40 < 2 )
          v40 = 2;
      }
      v1->mult_ = v40;
      v41 = v1->wscr;
      v42 = (long double)(v41 - 2 * GetBorderWidth()) / (long double)v1->w_;
      v43 = thisa->hscr;
      v44 = v43 - 2 * GetBorderHeight();
      if ( (long double)(v44 - GetBorderTitle()) / (long double)thisa->h_ <= v42 )
      {
        v47 = thisa->hscr;
        v48 = v47 - 2 * GetBorderHeight();
        v46 = (long double)(v48 - GetBorderTitle()) / (long double)thisa->h_;
      }
      else
      {
        v45 = thisa->wscr;
        v46 = (long double)(v45 - 2 * GetBorderWidth()) / (long double)thisa->w_;
      }
      if ( v46 >= 1.0 )
      {
        v50 = thisa->wscr;
        v51 = (long double)(v50 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        v52 = thisa->hscr;
        v53 = v52 - 2 * GetBorderHeight();
        if ( (long double)(v53 - GetBorderTitle()) / (long double)thisa->h_ <= v51 )
        {
          v55 = thisa->hscr;
          v56 = v55 - 2 * GetBorderHeight();
          v49 = (long double)(v56 - GetBorderTitle()) / (long double)thisa->h_;
        }
        else
        {
          v54 = thisa->wscr;
          v49 = (long double)(v54 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        }
      }
      else
      {
        v49 = 1.0;
      }
      thisa->mult = v49;
      if ( (long double)thisa->mult_ / 2.0 <= thisa->mult )
        v57 = (long double)thisa->mult_ / 2.0;
      else
        v57 = thisa->mult;
      thisa->mult = v57;
    }
  }
  else
  {
    v2 = v1->wscr;
    v3 = (long double)(v2 - 2 * GetBorderWidth());
    if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
      v58 = thisa->w_;
    else
      v58 = thisa->minw;
    v59 = v3 / (long double)v58;
    v4 = thisa->hscr;
    v5 = v4 - 2 * GetBorderHeight();
    v6 = (long double)(v5 - GetBorderTitle());
    if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
      v66 = thisa->h_;
    else
      v66 = thisa->minh;
    if ( v6 / (long double)v66 <= v59 )
    {
      v10 = thisa->hscr;
      v11 = v10 - 2 * GetBorderHeight();
      v12 = (long double)(v11 - GetBorderTitle());
      if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
        v61 = thisa->h_;
      else
        v61 = thisa->minh;
      v9 = v12 / (long double)v61;
    }
    else
    {
      v7 = thisa->wscr;
      v8 = (long double)(v7 - 2 * GetBorderWidth());
      if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
        v60 = thisa->w_;
      else
        v60 = thisa->minw;
      v9 = v8 / (long double)v60;
    }
    if ( v9 >= 1.0 )
    {
      v14 = thisa->wscr;
      v15 = (long double)(v14 - 2 * GetBorderWidth());
      if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
        v62 = thisa->w_;
      else
        v62 = thisa->minw;
      v63 = v15 / (long double)v62;
      v16 = thisa->hscr;
      v17 = v16 - 2 * GetBorderHeight();
      v18 = (long double)(v17 - GetBorderTitle());
      if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
        v67 = thisa->h_;
      else
        v67 = thisa->minh;
      if ( v18 / (long double)v67 <= v63 )
      {
        v21 = thisa->hscr;
        v22 = v21 - 2 * GetBorderHeight();
        v23 = (long double)(v22 - GetBorderTitle());
        if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
          v65 = thisa->h_;
        else
          v65 = thisa->minh;
        v13 = v23 / (long double)v65;
      }
      else
      {
        v19 = thisa->wscr;
        v20 = (long double)(v19 - 2 * GetBorderWidth());
        if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
          v64 = thisa->w_;
        else
          v64 = thisa->minw;
        v13 = v20 / (long double)v64;
      }
    }
    else
    {
      v13 = 1.0;
    }
    thisa->mult = v13;
    thisa->mult = (long double)(signed int)(thisa->mult + thisa->mult) / 2.0;
  }
  thisa->bd.w_ = thisa->w_;
  thisa->bd.h_ = thisa->h_;
  thisa->bd.mult = thisa->mult;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040EFC4; symbol: __ZN6Window8loadiconEv
void __cdecl Window::loadicon(Window *const this)
{
  Window *v1; // ecx
  HICON__ *v2; // edx
  LPARAM v3; // ebx
  HWND__ *v4; // eax
  LPARAM v5; // ebx
  HWND__ *v6; // eax
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  v1->hicon_res = (HICON)LoadImageA(MainInstance, "MINESWEEPERRUSH_ICON", 1u, 0, 0, 0);
  thisa->hicon_file = (HICON)LoadImageA(0, "./data/MineSweeperRush.ico", 1u, 0, 0, 0x8050u);
  if ( thisa->hicon_res )
    v2 = thisa->hicon_res;
  else
    v2 = thisa->hicon_file;
  thisa->hicon = v2;
  v3 = (LPARAM)thisa->hicon;
  v4 = GetHwnd();
  SendMessageA(v4, 0x80u, 1u, v3);
  Delay(0xAu);
  v5 = (LPARAM)thisa->hicon;
  v6 = GetHwnd();
  SendMessageA(v6, 0x80u, 0, v5);
  Delay(0xAu);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040F102; symbol: __ZN6Window10initwindowEv
void __cdecl Window::initwindow(Window *const this)
{
  Window *v1; // ecx
  int *v2; // ST0C_4
  Window *const v3; // ST00_4
  double v4; // ST28_8
  long double v5; // fst7
  double v6; // ST28_8
  double v7; // ST28_8
  double v8; // ST28_8
  long double v9; // fst7
  double v10; // ST28_8
  double v11; // ST28_8
  Window *const v12; // ST00_4
  int v13; // ST04_4
  __int16 *v14; // eax
  const char *v15; // ST04_4
  int v16; // ST04_4
  int v17; // ebx
  int v18; // ebx
  int v19; // ebx
  Window *v20; // [esp+0h] [ebp-A8h]
  double v21; // [esp+30h] [ebp-78h]
  double v22; // [esp+30h] [ebp-78h]
  Window *thisa; // [esp+4Ch] [ebp-5Ch]
  LOGFONT lf; // [esp+54h] [ebp-54h]

  thisa = v1;
  Window::initcolor(v20);
  SystemParametersInfoA(0x30u, 0, &thisa->rect, 0);
  thisa->wscr = thisa->rect.right - thisa->rect.left;
  thisa->hscr = thisa->rect.bottom - thisa->rect.top;
  thisa->w_ = thisa->launchw;
  thisa->h_ = thisa->launchh;
  Reg::getreg((int)&thisa->reg, (Reg *const )thisa->reg.regkey, &stru_42900A, (const char *)&thisa->mult_, v2);
  Window::initmult(v3);
  v21 = (long double)thisa->rect.left;
  v4 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
  if ( (v4 - (long double)(2 * GetBorderWidth())) / 2.0 >= 0.0 )
  {
    v6 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
    v5 = (v6 - (long double)(2 * GetBorderWidth())) / 2.0;
  }
  else
  {
    v5 = 0.0;
  }
  thisa->x_ = (signed int)(v5 + v21);
  v22 = (long double)thisa->rect.top;
  v7 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
  v8 = v7 - (long double)(2 * GetBorderHeight());
  if ( (v8 - (long double)GetBorderTitle()) / 2.0 >= 0.0 )
  {
    v10 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
    v11 = v10 - (long double)(2 * GetBorderHeight());
    v9 = (v11 - (long double)GetBorderTitle()) / 2.0;
  }
  else
  {
    v9 = 0.0;
  }
  thisa->y_ = (signed int)(v9 + v22);
  CreateWin(
    thisa->x_,
    thisa->y_,
    (signed __int64)((long double)thisa->w_ * thisa->mult),
    (signed __int64)((long double)thisa->h_ * thisa->mult),
    thisa->cbg,
    thisa->cbg,
    0x10C80000u,
    "MineSweeperRushClass");
  thisa->pwin = CreateBMP(thisa->w_, thisa->h_);
  thisa->pwint = CreateBMP(
                   (signed __int64)((long double)thisa->w_ * thisa->mult),
                   (signed __int64)((long double)thisa->h_ * thisa->mult),
                   thisa->transparent_);
  Window::loadicon(v12);
  v14 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_TITLE, v13);
  SetTitleW(v14);
  SystemParametersInfoA(0x1Fu, 0x3Cu, &lf, 0);
  Window::setfontname_((Window *const )lf.lfFaceName, v15);
  Window::painttitle((Window *const )0xFFFFFFFF, v16);
  v17 = thisa->wscr;
  thisa->bd.maxbdw = (v17 - 2 * GetBorderWidth()) / 16 - 1;
  v18 = thisa->hscr - thisa->menuh - thisa->faceh;
  v19 = v18 - 2 * GetBorderHeight();
  thisa->bd.maxbdh = (v19 - GetBorderTitle()) / 16 - 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040F5F8; symbol: __ZN6Window13releasewindowEv
void __cdecl Window::releasewindow(Window *const this)
{
  Window *v1; // ecx
  Window *v2; // [esp+0h] [ebp-28h]
  Window *v3; // [esp+0h] [ebp-28h]
  int v4; // [esp+Ch] [ebp-1Ch]
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  Window::savesetting(v2);
  if ( thisa->cheatb != 1 && thisa->bd.relaxb != 1 && thisa->bd.sit > 0 && thisa->bd.sit <= 3 )
  {
    if ( !thisa->bd.tutb )
      thisa->bd.pauseb = 1;
    Window::saveboard(v3);
    thisa->boardb = 1;
    Reg::setreg((Reg *const )thisa->reg.regkey, &stru_4290C4, (const char *)thisa->boardb, v4);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040F6B2; symbol: __ZN6Window10initwindowEb
void __userpurge Window::initwindow(Window *a1@<ecx>, Window *const this, bool b)
{
  int v3; // eax
  double v4; // ST18_8
  long double v5; // fst7
  double v6; // ST18_8
  double v7; // ST18_8
  double v8; // ST18_8
  long double v9; // fst7
  double v10; // ST18_8
  double v11; // ST18_8
  bool v12; // ST04_1
  Board *v13; // [esp+0h] [ebp-58h]
  double v14; // [esp+20h] [ebp-38h]
  double v15; // [esp+20h] [ebp-38h]
  Window *thisa; // [esp+3Ch] [ebp-1Ch]
  RECT rect; // [esp+40h] [ebp-18h]

  thisa = a1;
  if ( (unsigned __int8)IsWin() )
  {
    v3 = thisa->helpi;
    if ( v3 == -1 )
    {
      thisa->w_ = thisa->aboutw;
      thisa->h_ = thisa->menuh + thisa->abouth;
    }
    else if ( v3 )
    {
      thisa->w_ = thisa->helpw;
      thisa->h_ = thisa->menuh + thisa->helph;
    }
    else
    {
      if ( (_BYTE)this )
      {
        thisa->bd.mode = 0;
        Board::initbd(v13);
      }
      thisa->w_ = thisa->iconw * thisa->bd.w;
      thisa->h_ = thisa->menuh + thisa->faceh + thisa->iconh * thisa->bd.h;
    }
    Window::initmult((Window *const )v13);
    v14 = (long double)thisa->rect.left;
    v4 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
    if ( (v4 - (long double)(2 * GetBorderWidth())) / 2.0 >= 0.0 )
    {
      v6 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
      v5 = (v6 - (long double)(2 * GetBorderWidth())) / 2.0;
    }
    else
    {
      v5 = 0.0;
    }
    thisa->x_ = (signed int)(v5 + v14);
    v15 = (long double)thisa->rect.top;
    v7 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
    v8 = v7 - (long double)(2 * GetBorderHeight());
    if ( (v8 - (long double)GetBorderTitle()) / 2.0 >= 0.0 )
    {
      v10 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
      v11 = v10 - (long double)(2 * GetBorderHeight());
      v9 = (v11 - (long double)GetBorderTitle()) / 2.0;
    }
    else
    {
      v9 = 0.0;
    }
    thisa->y_ = (signed int)(v9 + v15);
    ReleaseBMP(thisa->pwin);
    ReleaseBMP(thisa->pwint);
    thisa->pwin = CreateBMP(thisa->w_, thisa->h_);
    thisa->pwint = CreateBMP(
                     (signed __int64)((long double)thisa->w_ * thisa->mult),
                     (signed __int64)((long double)thisa->h_ * thisa->mult),
                     thisa->transparent_);
    rect.left = 0;
    rect.top = 0;
    rect.right = 0;
    rect.bottom = 0;
    if ( EnumDisplayMonitors(0, 0, Monitorenumproc, (LPARAM)&rect) == 0 )
    {
      thisa->xscr = rect.left;
      thisa->yscr = rect.top;
      thisa->wscr = rect.right - rect.left;
      thisa->hscr = rect.bottom - rect.top;
    }
    SetSize(
      thisa->x_ + thisa->xscr,
      thisa->yscr + thisa->y_,
      (signed __int64)((long double)thisa->w_ * thisa->mult),
      (signed __int64)((long double)thisa->h_ * thisa->mult));
    Window::paintevent(0, v12);
    FreshWin();
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040FB94; symbol: __ZN6Window9initcolorEv
void __cdecl Window::initcolor(Window *const this)
{
  Window *v1; // ecx
  Window *v2; // ST00_4

  v2 = v1;
  v1->cfg = v1->color[0];
  v2->cbg = v2->color[1];
  v2->ctfg = v2->color[2];
  v2->ctbg = v2->color[3];
  v2->cred = v2->color[4];
  v2->cblue = v2->color[5];
  v2->cgreen = v2->color[6];
  v2->cline = v2->color[7];
  v2->cmine = v2->color[8];
  v2->bd.cred = v2->cred;
  v2->transparent_ = v2->cbg;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040FC66; symbol: __ZN6Window7initbmpEv
void __cdecl Window::initbmp(Window *const this)
{
  Window *v1; // ecx
  unsigned int v2; // ecx
  Window *v3; // [esp+0h] [ebp-198h]
  Window *thisa; // [esp+3Ch] [ebp-15Ch]
  char pngPath[260]; // [esp+4Ch] [ebp-14Ch]
  int i_6; // [esp+150h] [ebp-48h]
  int k_2; // [esp+154h] [ebp-44h]
  int i_5; // [esp+158h] [ebp-40h]
  int i_4; // [esp+15Ch] [ebp-3Ch]
  int i_3; // [esp+160h] [ebp-38h]
  int k_1; // [esp+164h] [ebp-34h]
  int k_0; // [esp+168h] [ebp-30h]
  int i_2; // [esp+16Ch] [ebp-2Ch]
  int k; // [esp+170h] [ebp-28h]
  int i_1; // [esp+174h] [ebp-24h]
  int i_0; // [esp+178h] [ebp-20h]
  int i; // [esp+17Ch] [ebp-1Ch]

  thisa = v1;
  if ( (unsigned __int8)IsWin() )
  {
    if ( thisa->isbmp == 1 )
    {
      ReleaseBMP(thisa->pbg_);
      ReleaseBMP(thisa->pmenu_);
      ReleaseBMP(thisa->pface_);
      ReleaseBMP(thisa->picon_);
      for ( k_0 = 0; k_0 <= 2; ++k_0 )
        ReleaseBMP(*((pbitmap *)&thisa->titlew + k_0 + 104));
      ReleaseBMP(thisa->pok_);
      ReleaseBMP(thisa->pcursor_);
      ReleaseBMP(thisa->pclick_);
      ReleaseBMP(thisa->parrow_);
    }
    else
    {
      for ( i = 0; i <= 1; ++i )
      {
        *((_DWORD *)&thisa->launchh + i + 40) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->titleh + i + 40) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 44) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->titleh + i + 44) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 48) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->titleh + i + 48) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 52) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->titleh + i + 52) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 56) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->titleh + i + 56) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 60) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 62) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 64) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 66) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 68) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 70) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 72) = CreateBMP(thisa->menuw, thisa->menuh);
      }
      for ( i_0 = 0; i_0 <= 8; ++i_0 )
        *((_DWORD *)&thisa->launchw + i_0 + 76) = CreateBMP(thisa->facew, thisa->faceh);
      thisa->piconc = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconf = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconq = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconm = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->picone = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconn = CreateBMP(thisa->iconw, thisa->iconh);
      for ( i_1 = 0; i_1 <= 10; ++i_1 )
        *((_DWORD *)&thisa->titlew + i_1 + 84) = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconp = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->picona = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconu = CreateBMP(thisa->iconw, thisa->iconh);
      for ( k = 0; k <= 2; ++k )
      {
        for ( i_2 = 0; i_2 <= 9; ++i_2 )
          *((_DWORD *)&thisa->launchh + k + 3 * i_2 + 108) = CreateBMP(
                                                               *((_DWORD *)&thisa->titlew + k + 8),
                                                               *((_DWORD *)&thisa->launchh + k + 12));
        *((_DWORD *)&thisa->titleh + k + 136) = CreateBMP(
                                                  *((_DWORD *)&thisa->titlew + k + 8),
                                                  *((_DWORD *)&thisa->launchh + k + 12));
        *((_DWORD *)&thisa->titlew + k + 140) = CreateBMP(
                                                  *((_DWORD *)&thisa->titlew + k + 8),
                                                  *((_DWORD *)&thisa->launchh + k + 12));
      }
      thisa->pok = CreateBMP(thisa->okw, thisa->okh);
      thisa->pbtn = CreateBMP(thisa->btnw, thisa->btnh);
      thisa->pcursor = CreateBMP(thisa->cursorw, thisa->cursorh);
      thisa->pclickl = CreateBMP(thisa->clickw, thisa->clickh);
      thisa->pclickr = CreateBMP(thisa->clickw, thisa->clickh);
      thisa->pclickn = CreateBMP(thisa->clickw, thisa->clickh);
      thisa->pclicka = CreateBMP(thisa->clickw, thisa->clickh);
      thisa->parrowl = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->parrowr = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->parrowu = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->parrowd = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->parrowm = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->parrowp = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->isbmp = 1;
    }
    sprintf(pngPath, "./data/png/%ld/bg.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    thisa->pbg_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/menu.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pmenu_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/face.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pface_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/icon.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->picon_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/digt.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pdigt_[0] = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/digt2.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pdigt_[1] = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/digt_.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pdigt_[2] = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/ok.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pok_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/cursor.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pcursor_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/click.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pclick_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/arrow.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->parrow_ = LoadBMP(pngPath);
    for ( k_1 = 0; k_1 <= 8; ++k_1 )
    {
      v2 = GetPixel(thisa->pbg_, 0, k_1);
      *((_DWORD *)&thisa->titleh + k_1 + 160) = v2;
    }
    Window::initcolor(v3);
    for ( i_3 = 0; i_3 <= 1; ++i_3 )
    {
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 40),
        i_3 * thisa->menuw,
        0,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->titleh + i_3 + 40),
        i_3 * thisa->menuw,
        thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 44),
        i_3 * thisa->menuw,
        2 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->titleh + i_3 + 44),
        i_3 * thisa->menuw,
        3 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 48),
        i_3 * thisa->menuw,
        4 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->titleh + i_3 + 48),
        i_3 * thisa->menuw,
        5 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 52),
        i_3 * thisa->menuw,
        6 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->titleh + i_3 + 52),
        i_3 * thisa->menuw,
        7 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 56),
        i_3 * thisa->menuw,
        8 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->titleh + i_3 + 56),
        i_3 * thisa->menuw,
        9 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 60),
        i_3 * thisa->menuw,
        10 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 62),
        i_3 * thisa->menuw,
        11 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 64),
        i_3 * thisa->menuw,
        12 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 66),
        i_3 * thisa->menuw,
        13 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 68),
        i_3 * thisa->menuw,
        14 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 70),
        i_3 * thisa->menuw,
        15 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 72),
        i_3 * thisa->menuw,
        16 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
    }
    for ( i_4 = 0; i_4 <= 8; ++i_4 )
      DrawBMP(
        thisa->pface_,
        *((pbitmap *)&thisa->launchw + i_4 + 76),
        0,
        i_4 * thisa->faceh,
        thisa->facew,
        thisa->faceh,
        0,
        0,
        thisa->facew,
        thisa->faceh);
    DrawBMP(thisa->picon_, thisa->piconc, 0, 0, thisa->iconw, thisa->iconh, 0, 0, thisa->iconw, thisa->iconh);
    DrawBMP(thisa->picon_, thisa->piconf, 0, thisa->iconh, thisa->iconw, thisa->iconh, 0, 0, thisa->iconw, thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->piconq,
      0,
      2 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->piconm,
      0,
      3 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->picone,
      0,
      4 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->piconn,
      0,
      5 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    for ( i_5 = 0; i_5 <= 10; ++i_5 )
      DrawBMP(
        thisa->picon_,
        *((pbitmap *)&thisa->titlew + i_5 + 84),
        0,
        (16 - i_5) * thisa->iconh,
        thisa->iconw,
        thisa->iconh,
        0,
        0,
        thisa->iconw,
        thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->piconp,
      0,
      16 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->picona,
      0,
      17 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->piconu,
      0,
      18 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    for ( k_2 = 0; k_2 <= 2; ++k_2 )
    {
      for ( i_6 = 0; i_6 <= 9; ++i_6 )
        DrawBMP(
          *((pbitmap *)&thisa->titlew + k_2 + 104),
          *((pbitmap *)&thisa->launchh + 3 * i_6 + k_2 + 108),
          0,
          (11 - i_6) * *((_DWORD *)&thisa->launchh + k_2 + 12),
          *((_DWORD *)&thisa->titlew + k_2 + 8),
          *((_DWORD *)&thisa->launchh + k_2 + 12),
          0,
          0,
          *((_DWORD *)&thisa->titlew + k_2 + 8),
          *((_DWORD *)&thisa->launchh + k_2 + 12));
      DrawBMP(
        *((pbitmap *)&thisa->titlew + k_2 + 104),
        *((pbitmap *)&thisa->titleh + k_2 + 136),
        0,
        0,
        *((_DWORD *)&thisa->titlew + k_2 + 8),
        *((_DWORD *)&thisa->launchh + k_2 + 12),
        0,
        0,
        *((_DWORD *)&thisa->titlew + k_2 + 8),
        *((_DWORD *)&thisa->launchh + k_2 + 12));
      DrawBMP(
        *((pbitmap *)&thisa->titlew + k_2 + 104),
        *((pbitmap *)&thisa->titlew + k_2 + 140),
        0,
        *((_DWORD *)&thisa->launchh + k_2 + 12),
        *((_DWORD *)&thisa->titlew + k_2 + 8),
        *((_DWORD *)&thisa->launchh + k_2 + 12),
        0,
        0,
        *((_DWORD *)&thisa->titlew + k_2 + 8),
        *((_DWORD *)&thisa->launchh + k_2 + 12));
    }
    DrawBMP(thisa->pok_, thisa->pok, 0, 0, thisa->okw, thisa->okh, 0, 0, thisa->okw, thisa->okh);
    DrawBMP(thisa->pok_, thisa->pbtn, thisa->okw, 0, thisa->btnw, thisa->btnh, 0, 0, thisa->btnw, thisa->btnh);
    DrawBMP(thisa->pcursor_, thisa->pcursor, 0, 0, thisa->cursorw, thisa->cursorh, 0, 0, thisa->cursorw, thisa->cursorh);
    DrawBMP(thisa->pclick_, thisa->pclickl, 0, 0, thisa->clickw, thisa->clickh, 0, 0, thisa->clickw, thisa->clickh);
    DrawBMP(
      thisa->pclick_,
      thisa->pclickr,
      0,
      thisa->clickh,
      thisa->clickw,
      thisa->clickh,
      0,
      0,
      thisa->clickw,
      thisa->clickh);
    DrawBMP(
      thisa->pclick_,
      thisa->pclickn,
      0,
      2 * thisa->clickh,
      thisa->clickw,
      thisa->clickh,
      0,
      0,
      thisa->clickw,
      thisa->clickh);
    DrawBMP(
      thisa->pclick_,
      thisa->pclicka,
      0,
      3 * thisa->clickh,
      thisa->clickw,
      thisa->clickh,
      0,
      0,
      thisa->clickw,
      thisa->clickh);
    DrawBMP(thisa->parrow_, thisa->parrowl, 0, 0, thisa->arroww, thisa->arrowh, 0, 0, thisa->arroww, thisa->arrowh);
    DrawBMP(
      thisa->parrow_,
      thisa->parrowr,
      0,
      thisa->arrowh,
      thisa->arroww,
      thisa->arrowh,
      0,
      0,
      thisa->arroww,
      thisa->arrowh);
    DrawBMP(
      thisa->parrow_,
      thisa->parrowu,
      0,
      2 * thisa->arrowh,
      thisa->arroww,
      thisa->arrowh,
      0,
      0,
      thisa->arroww,
      thisa->arrowh);
    DrawBMP(
      thisa->parrow_,
      thisa->parrowd,
      0,
      3 * thisa->arrowh,
      thisa->arroww,
      thisa->arrowh,
      0,
      0,
      thisa->arroww,
      thisa->arrowh);
    DrawBMP(
      thisa->parrow_,
      thisa->parrowm,
      0,
      4 * thisa->arrowh,
      thisa->arroww,
      thisa->arrowh,
      0,
      0,
      thisa->arroww,
      thisa->arrowh);
    DrawBMP(
      thisa->parrow_,
      thisa->parrowp,
      0,
      5 * thisa->arrowh,
      thisa->arroww,
      thisa->arrowh,
      0,
      0,
      thisa->arroww,
      thisa->arrowh);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412776; symbol: __ZN6Window9paintmenuEv
void __cdecl Window::paintmenu(Window *const this)
{
  unsigned int *v1; // ecx
  Window *v2; // ST2C_4

  v2 = (Window *)v1;
  DrawBMP(*((pbitmap *)&v2->launchh + (v2->helpi == -1) + 48), v1[866] - v1[4], 0, v1[4], v1[5]);
  DrawBMP(*((pbitmap *)&v2->titleh + (v2->helpi > 0) + 44), v2->w_ - 2 * v2->menuw, 0, v2->menuw, v2->menuh);
  DrawBMP(*((pbitmap *)&v2->launchh + (v2->helpi == -3) + 56), v2->w_ - 3 * v2->menuw, 0, v2->menuw, v2->menuh);
  DrawBMP(*((pbitmap *)&v2->titleh + (v2->helpi == -2) + 52), v2->w_ - 4 * v2->menuw, 0, v2->menuw, v2->menuh);
  DrawBMP(v2->pface[6], v2->w_ - 5 * v2->menuw, 0, v2->menuw, v2->menuh);
  DrawBMP(*((pbitmap *)&v2->launchh + (v2->bd.mode == 1) + 40), 0, 0, v2->menuw, v2->menuh);
  DrawBMP(*((pbitmap *)&v2->titleh + (v2->bd.mode == 2) + 40), v2->menuw, 0, v2->menuw, v2->menuh);
  DrawBMP(*((pbitmap *)&v2->launchh + (v2->bd.mode == 3) + 44), 2 * v2->menuw, 0, v2->menuw, v2->menuh);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412A48; symbol: __ZN6Window9paintfaceEv
void __cdecl Window::paintface(Window *const this)
{
  _DWORD *v1; // ecx
  int face__[6]; // [esp+34h] [ebp-34h]
  int facei; // [esp+4Ch] [ebp-1Ch]

  face__[0] = 4;
  face__[1] = 4;
  face__[2] = 3;
  face__[3] = 1;
  face__[4] = 2;
  face__[5] = 0;
  facei = v1[195];
  if ( facei == 1 && v1[735] == 1 )
    ++facei;
  if ( v1[196] > 0 )
    facei = 5;
  DrawBMP((pbitmap)v1[face__[facei] + 76], (v1[866] - v1[6]) / 2, v1[5], v1[6], v1[7]);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412B1E; symbol: __ZN6Window11paintnumberElllllll
void __userpurge Window::paintnumber(Window *a1@<ecx>, Window *const this, int n, int l, int x, int y, int w, int h, int b)
{
  int v9; // eax
  int v10; // eax
  Window *thisa; // [esp+2Ch] [ebp-5Ch]
  int dl_0; // [esp+38h] [ebp-50h]
  int digt[10]; // [esp+3Ch] [ebp-4Ch]
  bool minb; // [esp+67h] [ebp-21h]
  int di_0; // [esp+68h] [ebp-20h]
  int dlm; // [esp+6Ch] [ebp-1Ch]

  thisa = a1;
  dl_0 = 0;
  minb = (signed int)this < 0;
  if ( (signed int)this < 0 )
    this = (Window *const )-(signed int)this;
  do
  {
    digt[dl_0] = (signed int)this % 10;
    this = (Window *const )((signed int)this / 10);
    ++dl_0;
  }
  while ( this );
  if ( minb )
  {
    v9 = dl_0 + 1;
    if ( dl_0 + 1 < n )
      v9 = n;
    dlm = v9;
  }
  else
  {
    if ( dl_0 <= n )
      v10 = n;
    else
      v10 = dl_0;
    dlm = v10;
  }
  for ( di_0 = 0; di_0 < dlm; ++di_0 )
  {
    if ( di_0 >= dl_0 )
    {
      if ( di_0 == dl_0 && minb )
        DrawBMP(*((pbitmap *)&thisa->titleh + h + 136), y * (dlm - di_0 - 1) + l, x, y, w);
      else
        DrawBMP(*((pbitmap *)&thisa->titlew + h + 140), y * (dlm - di_0 - 1) + l, x, y, w);
    }
    else
    {
      DrawBMP(*((pbitmap *)&thisa->launchh + h + 3 * digt[di_0] + 108), y * (dlm - di_0 - 1) + l, x, y, w);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412CF2; symbol: __ZN6Window11paintnumberElllll
void __userpurge Window::paintnumber(Window *a1@<ecx>, Window *const this, int n, int l, int x, int y, int b)
{
  int v7; // [esp+1Ch] [ebp-1Ch]

  Window::paintnumber(a1, this, n, l, x, *((_DWORD *)&a1->titlew + y + 8), *((_DWORD *)&a1->launchh + y + 12), y, v7);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412D56; symbol: __ZN6Window11paintnumberEllll
void __userpurge Window::paintnumber(Window *a1@<ecx>, Window *const this, int n, int l, int x, int y)
{
  int v6; // [esp+14h] [ebp-24h]

  Window::paintnumber(a1, this, n, l, x, 0, v6);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412D94; symbol: __ZN6Window10paintlevelEv
void __cdecl Window::paintlevel(Window *const this)
{
  Window *v1; // ecx
  int v2; // [esp+14h] [ebp-34h]
  int v3; // [esp+14h] [ebp-34h]
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  Window *score2; // [esp+38h] [ebp-10h]
  Window *score; // [esp+3Ch] [ebp-Ch]

  thisa = v1;
  score = (Window *)v1->bd.line;
  if ( v1->singleb )
    score = (Window *)(v1->bd.line - v1->bd.missline);
  if ( (signed int)score > 9999 )
  {
    if ( (signed int)score > 99999 )
      Window::paintnumber(v1, score, 6, 0, v1->digth[0], 2 * v1->singleb, v2);
    else
      Window::paintnumber(v1, score, 5, 0, v1->digth[0], 2 * v1->singleb, v2);
  }
  else
  {
    Window::paintnumber(v1, score, 4, 0, v1->digth[0], 2 * v1->singleb, v2);
  }
  score2 = (Window *)thisa->bd.level;
  if ( thisa->singleb )
    score2 = (Window *)thisa->bd.solven;
  if ( (signed int)score2 > 99 )
  {
    if ( (signed int)score2 > 999 )
    {
      if ( (signed int)score2 > 9999 )
        Window::paintnumber(thisa, score2, 5, thisa->w_ - 5 * thisa->digtw[0], thisa->digth[0], 2 * thisa->singleb, v3);
      else
        Window::paintnumber(thisa, score2, 4, thisa->w_ - 4 * thisa->digtw[0], thisa->digth[0], 2 * thisa->singleb, v3);
    }
    else
    {
      Window::paintnumber(thisa, score2, 3, -3 * thisa->digtw[0] + thisa->w_, thisa->digth[0], 2 * thisa->singleb, v3);
    }
  }
  else
  {
    Window::paintnumber(thisa, score2, 2, thisa->w_ - 2 * thisa->digtw[0], thisa->digth[0], 2 * thisa->singleb, v3);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413050; symbol: __ZN6Window10paintblockER5Blockllllll
void __userpurge Window::paintblock(Window *a1@<ecx>, Window *const this, Block *const b, int i, int j, int x, int y, int w, int h)
{
  Window *thisa; // [esp+2Ch] [ebp-1Ch]

  thisa = a1;
  if ( *(_BYTE *)(this->digth[0] + ((_DWORD)b << 7) + i) )
  {
    if ( this->facew > (signed int)b && this->menuh - 1 <= i )
      DrawBMP(a1->picone, j, x, y, w);
  }
  else if ( this->menuw <= 0 )
  {
    if ( *(_BYTE *)(this->digtw[2] + ((_DWORD)b << 7) + i) )
    {
      if ( *(_BYTE *)(this->digtw[1] + ((_DWORD)b << 7) + i) )
        DrawBMP(a1->piconm, j, x, y, w);
      else
        DrawBMP(*((pbitmap *)&a1->titlew + *(_DWORD *)(this->digth[1] + ((_DWORD)b << 9) + 4 * i) + 84), j, x, y, w);
    }
    else if ( *(_BYTE *)(this->iconh + ((_DWORD)b << 7) + i) )
    {
      DrawBMP(a1->piconf, j, x, y, w);
    }
    else if ( *(_BYTE *)(this->digtw[0] + ((_DWORD)b << 7) + i) )
    {
      DrawBMP(a1->piconq, j, x, y, w);
    }
    else if ( this->titleh != 4 && (this->titleh || a1->bd.mode)
           || !*(_BYTE *)(this->digtw[1] + ((_DWORD)b << 7) + i)
           || a1->helpi )
    {
      DrawBMP(a1->piconc, j, x, y, w);
    }
    else
    {
      DrawBMP(a1->piconn, j, x, y, w);
    }
  }
  else if ( *(_BYTE *)(this->digtw[2] + ((_DWORD)b << 7) + i) )
  {
    DrawBMP(a1->piconp, j, x, y, w);
    Bar(j, x, y - 1, w - 1, thisa->cbg);
  }
  else
  {
    DrawBMP(a1->picone, j, x, y, w);
  }
  if ( thisa->cheatb )
  {
    if ( thisa->bd.leftrule[(_DWORD)b][i] && thisa->bd.blck[(_DWORD)b][i] != 1 && thisa->bd.mask[(_DWORD)b][i] != 1 )
      Bar(j, x, thisa->iconw - 1, thisa->iconh - 1, thisa->cblue, thisa->transparent);
    if ( thisa->bd.rightrule[(_DWORD)b][i]
      && thisa->bd.blck[(_DWORD)b][i] != 1
      && thisa->bd.qstn[(_DWORD)b][i] != 1
      && thisa->bd.flag[(_DWORD)b][i] != 1
      && thisa->bd.mask[(_DWORD)b][i] != 1 )
    {
      Bar(j, x, thisa->iconw - 1, thisa->iconh - 1, thisa->cred, thisa->transparent);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413534; symbol: __ZN6Window10paintboardER5Blockll
void __userpurge Window::paintboard(Window *a1@<ecx>, Window *const this, Block *const b, int x, int y)
{
  int v5; // [esp+1Ch] [ebp-2Ch]
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  int j; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]

  thisa = a1;
  for ( i = 0; this->launchw > i; ++i )
  {
    for ( j = 0; this->launchh > j; ++j )
      Window::paintblock(
        thisa,
        this,
        (Block *const )i,
        j,
        (int)b + i * thisa->iconw,
        thisa->menuh + j * thisa->iconh + x,
        thisa->iconw,
        thisa->iconh,
        v5);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004135E8; symbol: __ZN6Window10paintboardER5Blockllll
void __userpurge Window::paintboard(Window *a1@<ecx>, Window *const this, Block *const b, int x, int y, int cx_0, int cy)
{
  Window *v7; // ST2C_4
  int v8; // [esp+Ch] [ebp-3Ch]

  v7 = a1;
  Window::paintboard(a1, this, b, x, v8);
  DrawBMP(
    v7->pcursor,
    (unsigned int)b + y * v7->iconw + v7->iconw / 2,
    x + v7->menuh + cx_0 * v7->iconh + v7->iconh / 2,
    v7->cursorw,
    v7->cursorh,
    0xC0C0C0u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004136B0; symbol: __ZN6Window10paintboardEv
void __cdecl Window::paintboard(Window *const this)
{
  int v1; // ecx
  int v2; // [esp+Ch] [ebp-3Ch]
  Window *thisa; // [esp+2Ch] [ebp-1Ch]

  thisa = (Window *)v1;
  Window::paintboard((Window *)v1, (Window *const )(v1 + 768), 0, *(_DWORD *)(v1 + 28), v2);
  if ( thisa->bd.mx >= 0 && thisa->bd.my >= 0 )
  {
    if ( thisa->barb )
      Bar(
        thisa->bd.mx * thisa->iconw,
        thisa->faceh + thisa->menuh + thisa->iconh * thisa->bd.my,
        thisa->iconw - 1,
        thisa->iconh - 1,
        thisa->ctfg,
        thisa->transparent);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041379C; symbol: __ZN6Window9paintlineEP6bitmaplll
void __userpurge Window::paintline(Window *a1@<ecx>, Window *const this, pbitmap p, int n, int x, int y)
{
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  int k; // [esp+3Ch] [ebp-Ch]

  thisa = a1;
  for ( k = 0; k < (signed int)p; ++k )
    DrawBMP((pbitmap)this, k * thisa->iconw + n, x, thisa->iconw, thisa->iconh);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413806; symbol: __ZN6Window9paintlineEP6bitmapS1_llll
void __userpurge Window::paintline(Window *a1@<ecx>, Window *const this, pbitmap pa, pbitmap pb, int a, int b, int x, int y)
{
  Window *v8; // ST1C_4
  int v9; // ST10_4
  int v10; // [esp+10h] [ebp-18h]

  v8 = a1;
  Window::paintline(a1, this, pb, b, x, v10);
  Window::paintline(v8, (Window *const )pa, (pbitmap)a, (_DWORD)pb * v8->iconw + b, x, v9);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413874; symbol: __ZN6Window9paintlineEP6bitmapS1_S1_lllll
void __userpurge Window::paintline(Window *a1@<ecx>, Window *const this, pbitmap pa, pbitmap pb, pbitmap pc, int a, int b, int c, int x, int y)
{
  Window *v10; // ST2C_4
  int v11; // ST10_4
  int v12; // [esp+18h] [ebp-20h]

  v10 = a1;
  Window::paintline(a1, this, pa, pc, a, c, x, v12);
  Window::paintline(v10, (Window *const )pb, (pbitmap)b, v10->iconw * ((_DWORD)pc + a) + c, x, v11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004138F4; symbol: __ZN6Window9paintlineEP6bitmapS1_S1_S1_llllll
void __userpurge Window::paintline(Window *a1@<ecx>, Window *const this, pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, int a, int b, int c, int d, int x, int y)
{
  Window *v12; // ST2C_4
  int v13; // ST10_4
  int v14; // [esp+20h] [ebp-18h]

  v12 = a1;
  Window::paintline(a1, this, pa, pb, pd, a, b, d, x, v14);
  Window::paintline(v12, (Window *const )pc, (pbitmap)c, v12->iconw * ((_DWORD)pd + a + b) + d, x, v13);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413988; symbol: __ZN6Window9paintlineEP6bitmapS1_S1_S1_S1_lllllll
void __userpurge Window::paintline(Window *a1@<ecx>, Window *const this, pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, pbitmap pe, int a, int b, int c, int d, int e, int x, int y)
{
  Window *v14; // ST3C_4
  int v15; // ST10_4
  int v16; // [esp+28h] [ebp-20h]

  v14 = a1;
  Window::paintline(a1, this, pa, pb, pc, pe, a, b, c, e, x, v16);
  Window::paintline(v14, (Window *const )pd, (pbitmap)d, v14->iconw * ((_DWORD)pe + a + b + c) + e, x, v15);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413A2E; symbol: __ZN6Window9painthelpEv
void __cdecl Window::painthelp(Window *const this)
{
  int v1; // ecx
  unsigned int v2; // ebx
  unsigned int v3; // edi
  unsigned int v4; // esi
  int v5; // ST34_4
  int v6; // ST04_4
  __int16 *v7; // eax
  unsigned int v8; // ST04_4
  unsigned int v9; // ST04_4
  unsigned int v10; // esi
  int v11; // ST34_4
  unsigned int v12; // ST30_4
  int v13; // edi
  int v14; // ebx
  int v15; // ST04_4
  __int16 *v16; // eax
  unsigned int v17; // ST20_4
  unsigned int v18; // esi
  int v19; // ST34_4
  unsigned int v20; // ST30_4
  int v21; // edi
  int v22; // ebx
  int v23; // ST04_4
  __int16 *v24; // eax
  unsigned int v25; // ST20_4
  unsigned int v26; // esi
  int v27; // ST34_4
  unsigned int v28; // ST30_4
  int v29; // edi
  int v30; // ebx
  int v31; // ST04_4
  __int16 *v32; // eax
  unsigned int v33; // ST20_4
  unsigned int v34; // esi
  int v35; // ST34_4
  unsigned int v36; // ST30_4
  int v37; // edi
  int v38; // ebx
  int v39; // ST04_4
  __int16 *v40; // eax
  unsigned int v41; // ST20_4
  unsigned int v42; // ebx
  unsigned int v43; // edi
  unsigned int v44; // esi
  int v45; // ST34_4
  int v46; // ST04_4
  __int16 *v47; // eax
  unsigned int v48; // ST04_4
  LeaderboardEntry_t *const v49; // ST00_4
  int v50; // ecx
  int v51; // eax
  int *v52; // eax
  bool v53; // al
  ISteamFriends *v54; // eax
  int v55; // ST34_4
  unsigned int v56; // ST30_4
  unsigned int v57; // ST40_4
  int v58; // ebx
  const char *v59; // ST04_4
  int v60; // edi
  int v61; // esi
  int v62; // ebx
  const char *v63; // ST04_4
  unsigned int v64; // eax
  int v65; // ST1C_4
  int v66; // ST14_4
  int v67; // ST34_4
  unsigned int v68; // ST30_4
  int v69; // ST40_4
  unsigned int v70; // edi
  bitmap *v71; // eax
  unsigned int v72; // edi
  int v73; // ST34_4
  unsigned int v74; // ST30_4
  int v75; // ST40_4
  int v76; // ebx
  int v77; // esi
  int v78; // ST04_4
  __int16 *v79; // eax
  unsigned int v80; // ST04_4
  unsigned int v81; // ebx
  unsigned int v82; // edi
  unsigned int v83; // esi
  int v84; // ST34_4
  int v85; // ST04_4
  __int16 *v86; // eax
  unsigned int v87; // ST04_4
  unsigned int v88; // esi
  unsigned int v89; // edi
  int v90; // ST34_4
  int v91; // ST30_4
  int v92; // ST40_4
  const __int16 *v93; // ebx
  __int16 *v94; // eax
  unsigned int v95; // esi
  unsigned int v96; // edi
  const __int16 *v97; // ebx
  signed int v98; // eax
  __int16 *v99; // eax
  unsigned int v100; // esi
  unsigned int v101; // edi
  int v102; // ST34_4
  int v103; // ST30_4
  int v104; // ST40_4
  const __int16 *v105; // ebx
  __int16 *v106; // eax
  unsigned int v107; // ebx
  unsigned int v108; // edi
  unsigned int v109; // esi
  int v110; // ST34_4
  int v111; // ST04_4
  __int16 *v112; // eax
  unsigned int v113; // esi
  int v114; // ST34_4
  int v115; // ST30_4
  unsigned int v116; // ST40_4
  int v117; // ebx
  int v118; // edi
  int v119; // ST04_4
  __int16 *v120; // eax
  unsigned int v121; // ST20_4
  unsigned int v122; // ST04_4
  unsigned int v123; // esi
  unsigned int v124; // edi
  int v125; // ST34_4
  unsigned int v126; // ST30_4
  int v127; // ST40_4
  int v128; // ebx
  __int16 *v129; // eax
  unsigned int v130; // ST18_4
  unsigned int v131; // edi
  int v132; // esi
  int v133; // ebx
  int v134; // ST34_4
  unsigned int v135; // eax
  unsigned int v136; // edi
  int v137; // esi
  int v138; // ebx
  int v139; // ST34_4
  const char *v140; // ST04_4
  unsigned int v141; // eax
  unsigned int v142; // ST18_4
  unsigned int v143; // ebx
  unsigned int v144; // edi
  unsigned int v145; // esi
  int v146; // ST34_4
  int v147; // ST04_4
  __int16 *v148; // eax
  unsigned int v149; // ST04_4
  signed int v150; // eax
  unsigned int v151; // edi
  int v152; // ST34_4
  int v153; // ST30_4
  unsigned int v154; // ST40_4
  int v155; // ebx
  int v156; // esi
  __int16 *v157; // eax
  unsigned int v158; // ebx
  unsigned int v159; // edi
  unsigned int v160; // esi
  int v161; // ST34_4
  int v162; // ST04_4
  __int16 *v163; // eax
  unsigned int v164; // ST04_4
  unsigned int v165; // edi
  int v166; // ST34_4
  int v167; // ST30_4
  unsigned int v168; // ST40_4
  int v169; // ebx
  int v170; // esi
  __int16 *v171; // eax
  unsigned int v172; // esi
  int v173; // ST34_4
  int v174; // ST30_4
  int v175; // edi
  int v176; // ebx
  __int16 *v177; // eax
  unsigned int v178; // ebx
  unsigned int v179; // edi
  unsigned int v180; // esi
  int v181; // ST34_4
  int v182; // ST04_4
  __int16 *v183; // eax
  unsigned int v184; // ST04_4
  int v185; // ST10_4
  int v186; // ST10_4
  int v187; // ST10_4
  int v188; // ST10_4
  int v189; // ST28_4
  unsigned int v190; // esi
  int v191; // ST34_4
  int v192; // ST30_4
  int v193; // edi
  int v194; // ebx
  int v195; // ST04_4
  __int16 *v196; // eax
  unsigned int v197; // ST20_4
  int v198; // ST10_4
  int v199; // ST10_4
  int v200; // ST10_4
  int v201; // ST10_4
  unsigned int v202; // esi
  int v203; // ST34_4
  int v204; // ST30_4
  int v205; // edi
  int v206; // ebx
  __int16 *v207; // eax
  int v208; // ST10_4
  int v209; // ST10_4
  int v210; // ST10_4
  int v211; // ST10_4
  unsigned int v212; // esi
  int v213; // ST34_4
  int v214; // ST30_4
  int v215; // edi
  int v216; // ebx
  int v217; // ST04_4
  __int16 *v218; // eax
  unsigned int v219; // ST20_4
  unsigned int v220; // ST04_4
  unsigned int v221; // ebx
  unsigned int v222; // edi
  unsigned int v223; // esi
  int v224; // ST34_4
  int v225; // ST04_4
  __int16 *v226; // eax
  unsigned int v227; // ST04_4
  int v228; // ST20_4
  int v229; // ST20_4
  int v230; // ST10_4
  unsigned int v231; // esi
  int v232; // ST34_4
  int v233; // ST30_4
  int v234; // edi
  int v235; // ebx
  int v236; // ST04_4
  __int16 *v237; // eax
  unsigned int v238; // ST20_4
  int v239; // ST20_4
  int v240; // ST20_4
  int v241; // ST28_4
  int v242; // ST10_4
  unsigned int v243; // esi
  int v244; // ST34_4
  int v245; // ST30_4
  int v246; // edi
  int v247; // ebx
  int v248; // ST04_4
  __int16 *v249; // eax
  unsigned int v250; // ST20_4
  int v251; // ST10_4
  unsigned int v252; // esi
  int v253; // ST34_4
  int v254; // ST30_4
  int v255; // edi
  int v256; // ebx
  int v257; // ST04_4
  __int16 *v258; // eax
  int v259; // ST10_4
  unsigned int v260; // esi
  int v261; // ST34_4
  int v262; // ST30_4
  int v263; // edi
  int v264; // ebx
  __int16 *v265; // eax
  unsigned int v266; // ST04_4
  unsigned int v267; // ebx
  unsigned int v268; // edi
  unsigned int v269; // esi
  int v270; // ST34_4
  int v271; // ST04_4
  __int16 *v272; // eax
  unsigned int v273; // ST04_4
  signed int v274; // edx
  signed int v275; // eax
  unsigned int v276; // edi
  int v277; // ST34_4
  unsigned int v278; // ST30_4
  int v279; // ST40_4
  int v280; // esi
  const __int16 *v281; // ebx
  int v282; // ST04_4
  __int16 *v283; // eax
  unsigned int v284; // edi
  int v285; // ST34_4
  unsigned int v286; // ST30_4
  int v287; // ST40_4
  int v288; // esi
  const __int16 *v289; // ebx
  int v290; // ST04_4
  __int16 *v291; // eax
  unsigned int v292; // ST24_4
  unsigned int v293; // edi
  int v294; // ST34_4
  unsigned int v295; // ST30_4
  int v296; // ST40_4
  int v297; // esi
  const __int16 *v298; // ebx
  int v299; // ST04_4
  __int16 *v300; // eax
  unsigned int v301; // ST24_4
  unsigned int v302; // ST04_4
  int v303; // ST34_4
  unsigned int v304; // edi
  unsigned int v305; // esi
  int v306; // ebx
  bitmap *v307; // eax
  unsigned int v308; // edi
  int v309; // ST34_4
  unsigned int v310; // ST30_4
  int v311; // ST40_4
  int v312; // ebx
  int v313; // esi
  int v314; // ST04_4
  __int16 *v315; // eax
  int v316; // ST34_4
  unsigned int v317; // edi
  unsigned int v318; // esi
  int v319; // ebx
  bitmap *v320; // eax
  unsigned int v321; // edi
  int v322; // ST34_4
  unsigned int v323; // ST30_4
  int v324; // ST40_4
  int v325; // ebx
  int v326; // esi
  int v327; // ST04_4
  __int16 *v328; // eax
  int v329; // ST34_4
  unsigned int v330; // edi
  unsigned int v331; // esi
  unsigned int v332; // ebx
  bitmap *v333; // eax
  int v334; // ST34_4
  unsigned int v335; // edi
  unsigned int v336; // esi
  unsigned int v337; // ebx
  bitmap *v338; // eax
  int v339; // ST34_4
  unsigned int v340; // edi
  unsigned int v341; // esi
  unsigned int v342; // ebx
  bitmap *v343; // eax
  unsigned int v344; // edi
  int v345; // ST34_4
  unsigned int v346; // ST30_4
  int v347; // ST40_4
  int v348; // esi
  const __int16 *v349; // ebx
  int v350; // ST04_4
  __int16 *v351; // eax
  const CSteamID *v352; // [esp+0h] [ebp-548h]
  Block *v353; // [esp+0h] [ebp-548h]
  Block *v354; // [esp+0h] [ebp-548h]
  unsigned int v355; // [esp+4h] [ebp-544h]
  unsigned int v356; // [esp+4h] [ebp-544h]
  unsigned int v357; // [esp+4h] [ebp-544h]
  int v358; // [esp+4h] [ebp-544h]
  int v359; // [esp+4h] [ebp-544h]
  int v360; // [esp+4h] [ebp-544h]
  const char *v361; // [esp+4h] [ebp-544h]
  int v362; // [esp+4h] [ebp-544h]
  unsigned int v363; // [esp+4h] [ebp-544h]
  int v364; // [esp+4h] [ebp-544h]
  int v365; // [esp+4h] [ebp-544h]
  int v366; // [esp+4h] [ebp-544h]
  int v367; // [esp+10h] [ebp-538h]
  int v368; // [esp+10h] [ebp-538h]
  int v369; // [esp+10h] [ebp-538h]
  int v370; // [esp+10h] [ebp-538h]
  int v371; // [esp+14h] [ebp-534h]
  int v372; // [esp+14h] [ebp-534h]
  unsigned int v373; // [esp+18h] [ebp-530h]
  unsigned int v374; // [esp+18h] [ebp-530h]
  unsigned int v375; // [esp+20h] [ebp-528h]
  unsigned int v376; // [esp+20h] [ebp-528h]
  unsigned int v377; // [esp+20h] [ebp-528h]
  unsigned int v378; // [esp+20h] [ebp-528h]
  unsigned int v379; // [esp+20h] [ebp-528h]
  unsigned int v380; // [esp+24h] [ebp-524h]
  int v381; // [esp+28h] [ebp-520h]
  int w; // [esp+30h] [ebp-518h]
  int y; // [esp+34h] [ebp-514h]
  int yd; // [esp+40h] [ebp-508h]
  Window *thisa; // [esp+4Ch] [ebp-4FCh]
  const char *cheatn[9]; // [esp+50h] [ebp-4F8h]
  int v387; // [esp+74h] [ebp-4D4h]
  const char *cheats[9]; // [esp+78h] [ebp-4D0h]
  int v389; // [esp+9Ch] [ebp-4ACh]
  int cheatc[9]; // [esp+A0h] [ebp-4A8h]
  int v391; // [esp+C4h] [ebp-484h]
  int k__[3][3]; // [esp+C8h] [ebp-480h]
  pbitmap v393; // [esp+ECh] [ebp-45Ch]
  pbitmap v394; // [esp+F0h] [ebp-458h]
  pbitmap v395; // [esp+F4h] [ebp-454h]
  int v396; // [esp+F8h] [ebp-450h]
  int v397; // [esp+FCh] [ebp-44Ch]
  pbitmap v398; // [esp+100h] [ebp-448h]
  pbitmap v399; // [esp+104h] [ebp-444h]
  pbitmap v400; // [esp+108h] [ebp-440h]
  BOOL v401; // [esp+10Ch] [ebp-43Ch]
  BOOL v402; // [esp+110h] [ebp-438h]
  BOOL v403; // [esp+114h] [ebp-434h]
  BOOL v404; // [esp+118h] [ebp-430h]
  BOOL v405; // [esp+11Ch] [ebp-42Ch]
  BOOL v406; // [esp+120h] [ebp-428h]
  BOOL v407; // [esp+128h] [ebp-420h]
  BOOL v408; // [esp+12Ch] [ebp-41Ch]
  BOOL v409; // [esp+134h] [ebp-414h]
  BOOL v410; // [esp+138h] [ebp-410h]
  pbitmap picon__[3][3][5]; // [esp+1CCh] [ebp-37Ch]
  pbitmap v412; // [esp+280h] [ebp-2C8h]
  pbitmap v413; // [esp+284h] [ebp-2C4h]
  pbitmap v414; // [esp+288h] [ebp-2C0h]
  pbitmap v415; // [esp+28Ch] [ebp-2BCh]
  pbitmap v416; // [esp+290h] [ebp-2B8h]
  pbitmap v417; // [esp+294h] [ebp-2B4h]
  pbitmap v418; // [esp+298h] [ebp-2B0h]
  pbitmap v419; // [esp+29Ch] [ebp-2ACh]
  pbitmap v420; // [esp+2A0h] [ebp-2A8h]
  pbitmap v421; // [esp+2A4h] [ebp-2A4h]
  int j_0; // [esp+3D4h] [ebp-174h]
  pbitmap psettingicon[2]; // [esp+3D8h] [ebp-170h]
  int k_1; // [esp+3E0h] [ebp-168h]
  uint16_t utf16[2]; // [esp+3E4h] [ebp-164h]
  uint32_t buffer; // [esp+3E8h] [ebp-160h]
  int k_[5]; // [esp+3ECh] [ebp-15Ch]
  int n__[3]; // [esp+400h] [ebp-148h]
  int scr__[3]; // [esp+40Ch] [ebp-13Ch]
  pbitmap pface__[3]; // [esp+418h] [ebp-130h]
  pbitmap pmenu__[3]; // [esp+424h] [ebp-124h]
  pbitmap prelax__[2]; // [esp+430h] [ebp-118h]
  pbitmap pcheat__[2]; // [esp+438h] [ebp-110h]
  int iconh4; // [esp+440h] [ebp-108h]
  int iconh3_0; // [esp+444h] [ebp-104h]
  int iconh2_0; // [esp+448h] [ebp-100h]
  int iconh1_0; // [esp+44Ch] [ebp-FCh]
  int iconwn_0; // [esp+450h] [ebp-F8h]
  int iconwr_0; // [esp+454h] [ebp-F4h]
  int iconwm_0; // [esp+458h] [ebp-F0h]
  int iconwl_0; // [esp+45Ch] [ebp-ECh]
  int iconh3; // [esp+460h] [ebp-E8h]
  int iconh2; // [esp+464h] [ebp-E4h]
  int iconh1; // [esp+468h] [ebp-E0h]
  int iconwn; // [esp+46Ch] [ebp-DCh]
  int iconwr; // [esp+470h] [ebp-D8h]
  int iconwm; // [esp+474h] [ebp-D4h]
  int iconwl; // [esp+478h] [ebp-D0h]
  int j_; // [esp+47Ch] [ebp-CCh]
  double helph___0; // [esp+480h] [ebp-C8h]
  int helpw___0; // [esp+48Ch] [ebp-BCh]
  double helph__; // [esp+490h] [ebp-B8h]
  int helpw__; // [esp+49Ch] [ebp-ACh]
  int lens; // [esp+4A0h] [ebp-A8h]
  int lenc; // [esp+4A4h] [ebp-A4h]
  const char *usernamec; // [esp+4A8h] [ebp-A0h]
  int i_4; // [esp+4ACh] [ebp-9Ch]
  int j_6; // [esp+4B0h] [ebp-98h]
  int j_5; // [esp+4B4h] [ebp-94h]
  int j_4; // [esp+4B8h] [ebp-90h]
  int i_3; // [esp+4BCh] [ebp-8Ch]
  int k_13; // [esp+4C0h] [ebp-88h]
  int k_12; // [esp+4C4h] [ebp-84h]
  int k_11; // [esp+4C8h] [ebp-80h]
  int k_10; // [esp+4CCh] [ebp-7Ch]
  int k_9; // [esp+4D0h] [ebp-78h]
  int j_3; // [esp+4D4h] [ebp-74h]
  int i_2; // [esp+4D8h] [ebp-70h]
  int j__0; // [esp+4DCh] [ebp-6Ch]
  int i_1; // [esp+4E0h] [ebp-68h]
  int j_2; // [esp+4E4h] [ebp-64h]
  int k_8; // [esp+4E8h] [ebp-60h]
  int k_7; // [esp+4ECh] [ebp-5Ch]
  int j_1; // [esp+4F0h] [ebp-58h]
  int i_0; // [esp+4F4h] [ebp-54h]
  int i; // [esp+4F8h] [ebp-50h]
  int k_6; // [esp+4FCh] [ebp-4Ch]
  int k_5; // [esp+500h] [ebp-48h]
  int k_4; // [esp+504h] [ebp-44h]
  int k_3; // [esp+508h] [ebp-40h]
  int j; // [esp+50Ch] [ebp-3Ch]
  int k_2; // [esp+510h] [ebp-38h]
  int score; // [esp+514h] [ebp-34h]
  int k_0; // [esp+518h] [ebp-30h]
  int poss; // [esp+51Ch] [ebp-2Ch]
  int posc; // [esp+520h] [ebp-28h]
  int k; // [esp+524h] [ebp-24h]
  int rank_; // [esp+528h] [ebp-20h]
  int leadid; // [esp+52Ch] [ebp-1Ch]

  thisa = (Window *)v1;
  switch ( *(_DWORD *)(v1 + 3376) )
  {
    case 0xFFFFFFFD:
      goto LABEL_42;
    case 0xFFFFFFFE:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v42 = thisa->cbg;
      v43 = thisa->ctfg;
      v44 = thisa->faceh;
      v45 = thisa->helpw;
      v47 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP + 9), v46);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v47, 0, 0, v45, v44, v43, v42, v375);
      Window::setfontheight_((Window *const )thisa->fontfh, v48);
      if ( thisa->bd.st.steamb )
      {
        Window::setfontheight_((Window *const )(thisa->fontsh - 1), v355);
        pmenu__[0] = thisa->pmenu1[0];
        pmenu__[1] = thisa->pmenu2[0];
        pmenu__[2] = thisa->pmenu3[0];
        LeaderboardEntry_t::LeaderboardEntry_t(v49);
        for ( leadid = 0; leadid <= 2; ++leadid )
        {
          DrawBMP(
            pmenu__[leadid],
            (2 * leadid + 1) * thisa->helpw / 6 + thisa->facew / -2,
            thisa->menuh,
            thisa->facew,
            thisa->faceh,
            thisa->cfg);
          for ( rank_ = 0; (*thisa->bd.st.leadsn)[0][rank_ + 20 * (leadid + 3 * thisa->lead_5)].m_nScore > 9997; ++rank_ )
            ;
          for ( k = 0; k <= 19; ++k )
          {
            if ( k > 9 )
            {
              v50 = (int)(*thisa->bd.st.leadsn)[15];
              v51 = 32 * (k - 10 + 20 * (leadid + 3 * thisa->lead_5));
            }
            else
            {
              v50 = (int)thisa->bd.st.leadsn;
              v51 = 32 * (rank_ + k + 20 * (leadid + 3 * thisa->lead_5));
            }
            v52 = (int *)(v50 + v51);
            cheatc[0] = *v52;
            cheatc[1] = v52[1];
            cheatc[2] = v52[2];
            cheatc[3] = v52[3];
            cheatc[4] = v52[4];
            cheatc[5] = v52[5];
            cheatc[6] = v52[6];
            cheatc[7] = v52[7];
            v53 = (*thisa->bd.st.leadsn)[3 * thisa->lead_5 + 30][20 * leadid].m_nGlobalRank == cheatc[2]
               && (signed int)CSteamID::GetEAccountType(v352) > 0;
            if ( v53 )
              Window::setfontweight_((Window *const )0x2BC, v356);
            if ( (signed int)CSteamID::GetEAccountType(v352) > 0 )
            {
              v54 = SteamFriends();
              usernamec = (const char *)(*(int (__stdcall **)(int, int))(*(_DWORD *)v54 + 28))(cheatc[0], cheatc[1]);
              *(_DWORD *)utf16 = 0;
              posc = 0;
              lenc = 0;
              poss = 0;
              lens = 0;
              while ( usernamec[posc] )
              {
                lenc = UTF8ToUnicode((uint8_t *)&usernamec[posc], &buffer);
                posc += lenc;
                lens = UnicodeToUTF16(buffer, utf16);
                if ( lens > 0 )
                  *((_WORD *)picon__[0][0] + poss++ + 4) = utf16[0];
                if ( lens > 1 )
                  *((_WORD *)picon__[0][0] + poss++ + 4) = utf16[1];
              }
              picon__[0][0][0] = (pbitmap)-1;
              picon__[0][0][1] = (pbitmap)(unsigned __int16)poss;
              *((_WORD *)picon__[0][0] + poss + 4) = 0;
              sprintf((char *)k__, "%ld", cheatc[2] - rank_);
              Window::drawtextxy_(
                (Window *const )thisa->pwint,
                (pbitmap)k__,
                (const char *)(leadid * thisa->helpw / 3),
                thisa->faceh + k * thisa->fontsh + thisa->menuh + 1,
                thisa->ctfg,
                thisa->cbg,
                v373);
              v55 = thisa->cbg;
              v56 = thisa->ctfg;
              v57 = thisa->fontsh;
              v58 = thisa->helpw / 3;
              v60 = v58
                  - Window::getstringwidth_((Window *const )"00000", v59)
                  - 4 * (thisa->digtw[1] * thisa->fontsh / thisa->digth[1]);
              v61 = thisa->faceh + k * thisa->fontsh + thisa->menuh + 1;
              v62 = leadid * thisa->helpw / 3;
              v64 = Window::getstringwidth_((Window *const )"00000", v63);
              Window::drawtextxy_(
                (Window *const )thisa->pwint,
                (pbitmap)&picon__[0][0][2],
                (const __int16 *)(v62 + v64),
                v61,
                v60,
                v57,
                v56,
                v55,
                0,
                v380);
              Window::paintnumber(
                thisa,
                (Window *const )cheatc[3],
                4,
                (leadid + 1) * thisa->helpw / 3 - 4 * (thisa->digtw[1] * thisa->fontsh / thisa->digth[1]),
                thisa->faceh + k * thisa->fontsh + thisa->menuh,
                thisa->digtw[1] * thisa->fontsh / thisa->digth[1],
                thisa->fontsh,
                1,
                v65);
            }
            Window::setfontweight_(0, v356);
          }
        }
        Window::setfontheight_((Window *const )thisa->fonth, v356);
        pface__[0] = thisa->pface[1];
        pface__[1] = thisa->pface[3];
        pface__[2] = thisa->piconf;
        scr__[0] = thisa->bd.st.scrfour;
        scr__[1] = thisa->bd.st.scrdead;
        scr__[2] = thisa->bd.st.scrtotal;
        n__[0] = 0;
        n__[1] = 0;
        n__[2] = 1;
        for ( k_0 = 0; k_0 <= 2; ++k_0 )
        {
          score = *((_DWORD *)&thisa->menuw + scr__[k_0] + 384);
          if ( thisa->singleb )
          {
            if ( !k_0 )
              score = thisa->bd.tetrisi;
            if ( k_0 == 1 )
              score = thisa->bd.missi;
          }
          DrawBMP(
            pface__[k_0],
            (2 * k_0 + 1) * thisa->helpw / 6 - 2 * thisa->digtw[0] - thisa->facew - thisa->digtw[0] * n__[k_0],
            thisa->menuh + (thisa->helph + 20 * thisa->fontsh - thisa->okh_) / 2 + 1,
            thisa->facew,
            thisa->faceh,
            thisa->cfg);
          Window::paintnumber(
            thisa,
            (Window *const )score,
            n__[k_0] + 4 + (*((_DWORD *)&thisa->menuw + scr__[k_0] + 384) > 9999) * (k_0 <= 1),
            (2 * k_0 + 1) * thisa->helpw / 6 - 2 * thisa->digtw[0] + thisa->facew - thisa->digtw[0] * n__[k_0],
            thisa->menuh + (thisa->helph + 20 * thisa->fontsh - thisa->okh_) / 2 + 1,
            2 * thisa->singleb * (k_0 <= 1),
            v66);
        }
        Line(thisa->helpw / 3, thisa->menuh, 0, thisa->helph - thisa->okh_, thisa->cline);
        Line(2 * (thisa->helpw / 3), thisa->menuh, 0, thisa->helph - thisa->okh_, thisa->cline);
        Line(0, thisa->menuh, thisa->helpw, 0, thisa->cline);
        Line(0, thisa->menuh + thisa->faceh, thisa->helpw, 0, thisa->cline);
        Line(0, thisa->menuh + thisa->faceh + 10 * thisa->fontsh, thisa->helpw, 0, thisa->cline);
        Line(0, thisa->menuh + thisa->faceh + 20 * thisa->fontsh, thisa->helpw, 0, thisa->cline);
        k_[0] = 3;
        k_[1] = 0;
        k_[2] = 5;
        k_[3] = 4;
        k_[4] = 6;
        for ( k_1 = 0; k_1 <= 4; ++k_1 )
        {
          v67 = thisa->faceh;
          v68 = thisa->facew;
          v69 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
          v70 = thisa->facew * k_1
              + ((thisa->helpw + thisa->okw) / 2 + thisa->helpw) / 2
              + ((signed int)(((unsigned int)(-5 * thisa->facew) >> 31) - 5 * thisa->facew) >> 1);
          v71 = GetWin();
          DrawBMP(*((pbitmap *)&thisa->launchh + (thisa->lead_5 == k_1) + 2 * k_[k_1] + 60), v71, v70, v69, v68, v67);
        }
        Window::setfontheight_((Window *const )thisa->faceh, v357);
        v72 = thisa->cbg;
        v73 = thisa->ctfg;
        v74 = thisa->faceh;
        v75 = thisa->helpw + (thisa->helpw + thisa->okw) / -2;
        v76 = thisa->menuh + thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->faceh;
        v77 = (thisa->helpw + thisa->okw) / 2;
        v79 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->lead_5 + thisa->bd.st.lan.LAN_MODE), v78);
        Window::drawtextxy_(
          (Window *const )thisa->pwint,
          (pbitmap)v79,
          (const __int16 *)v77,
          v76,
          v75,
          v74,
          v73,
          v72,
          v375);
        Window::setfontheight_((Window *const )thisa->fonth, v80);
      }
      else
      {
LABEL_42:
        Window::setfontheight_((Window *const )thisa->faceh, v355);
        v81 = thisa->cbg;
        v82 = thisa->ctfg;
        v83 = thisa->faceh;
        v84 = thisa->helpw;
        v86 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP + 8), v85);
        Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v86, 0, 0, v84, v83, v82, v81, v375);
        Window::setfontheight_((Window *const )thisa->fonth, v87);
        memset(cheatn, 0, 0x28u);
        cheatn[0] = *((const char **)&thisa->titleh + thisa->bd.sd.soundb + 48);
        cheatn[1] = *((const char **)&thisa->launchh + thisa->bd.sd.musicb + 52);
        cheatn[2] = *((const char **)&thisa->launchh + 2 * (thisa->md + 30));
        cheatn[4] = (const char *)thisa->pface[8];
        cheatn[5] = (const char *)thisa->pface[7];
        cheatn[7] = (const char *)thisa->picon[0];
        cheatn[8] = (const char *)thisa->picon[0];
        v387 = *((_DWORD *)&thisa->titleh + thisa->singleb + 56);
        cheats[0] = (const char *)10;
        cheats[1] = (const char *)11;
        cheats[2] = (const char *)12;
        cheats[3] = 0;
        cheats[4] = (const char *)17;
        cheats[5] = (const char *)14;
        cheats[6] = 0;
        cheats[7] = (const char *)18;
        cheats[8] = (const char *)19;
        v389 = 13;
        cheatc[0] = 2;
        cheatc[1] = 2;
        cheatc[2] = 2;
        cheatc[3] = 2;
        cheatc[4] = 3;
        cheatc[5] = 3;
        cheatc[6] = 3;
        cheatc[7] = 2;
        cheatc[8] = 2;
        v391 = 2;
        memset(k__, 0, 0x78u);
        k__[0][0] = thisa->bd.sd.soundb;
        k__[0][1] = !thisa->bd.sd.soundb;
        k__[1][0] = thisa->bd.sd.musicb;
        k__[1][1] = !thisa->bd.sd.musicb;
        k__[2][0] = thisa->md == 0;
        k__[2][1] = thisa->md == 1;
        v393 = (pbitmap)(thisa->md == 2);
        v394 = (pbitmap)(thisa->md == 3);
        v396 = thisa->mult_ == 0;
        v397 = thisa->mult_ == 1;
        v398 = (pbitmap)(thisa->mult_ > 1);
        v399 = (pbitmap)(thisa->colori == 0);
        v400 = (pbitmap)(thisa->colori == 1);
        v401 = thisa->colori == 2;
        v402 = thisa->colori == 3;
        v403 = thisa->colori == 4;
        v404 = thisa->colori == 5;
        v405 = thisa->bd.delayb == 1;
        v406 = thisa->bd.delayb == 0;
        v407 = thisa->barb;
        v408 = !thisa->barb;
        v409 = !thisa->singleb;
        v410 = thisa->singleb;
        psettingicon[0] = thisa->piconc;
        psettingicon[1] = thisa->piconf;
        qmemcpy(picon__, &unk_427220, 0x78u);
        helpw__ = thisa->iconw;
        helph__ = (long double)(thisa->helph - thisa->okh_ - 2 * thisa->iconh - thisa->faceh) / 9.0;
        for ( k_2 = 0; k_2 <= 9; ++k_2 )
        {
          if ( cheatn[k_2] )
            DrawBMP(
              (pbitmap)cheatn[k_2],
              helpw__,
              (signed __int64)((long double)k_2 * helph__
                             + (long double)(signed int)thisa->menuh
                             + (long double)(signed int)thisa->iconh),
              thisa->facew,
              thisa->faceh,
              thisa->cfg);
          if ( k_2 != 3 && k_2 != 6 )
          {
            v88 = thisa->cbg;
            v89 = thisa->ctfg;
            v90 = thisa->faceh;
            v91 = thisa->helpw / 4 - thisa->facew - 2 * thisa->iconw;
            v92 = (signed int)((long double)k_2 * helph__
                             + (long double)(signed int)thisa->menuh
                             + (long double)(signed int)thisa->iconh);
            v93 = (const __int16 *)(helpw__ + thisa->facew + thisa->iconw);
            v94 = Lan::getlan((int)&thisa->bd.st, (Lan *const )&cheats[k_2][thisa->bd.st.lan.LAN_HELP], v355);
            Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v94, v93, v92, v91, v90, v89, v88, 0, v380);
          }
          for ( j = 0; cheatc[k_2] > j; ++j )
          {
            DrawBMP(
              psettingicon[k__[0][j + 3 * k_2]],
              thisa->helpw / 4 * (j + 1),
              (signed __int64)((long double)k_2 * helph__
                             + (long double)(signed int)thisa->menuh
                             + (long double)(signed int)thisa->iconh),
              thisa->facew,
              thisa->faceh,
              thisa->cfg);
            if ( k_2 != 4 || j != 2 )
            {
              v100 = thisa->cbg;
              v101 = thisa->ctfg;
              v102 = thisa->faceh;
              v103 = thisa->helpw / 4 - thisa->facew - 2 * thisa->iconw;
              v104 = (signed int)((long double)k_2 * helph__
                                + (long double)(signed int)thisa->menuh
                                + (long double)(signed int)thisa->iconh);
              v105 = (const __int16 *)(thisa->facew + (j + 1) * (thisa->helpw / 4) + thisa->iconw);
              v106 = Lan::getlan(
                       (int)&thisa->bd.st,
                       (Lan *const )((char *)picon__[0][0][3 * k_2 + j] + thisa->bd.st.lan.LAN_SET),
                       v358);
              Window::drawtextxy_(
                (Window *const )thisa->pwint,
                (pbitmap)v106,
                v105,
                v104,
                v103,
                v102,
                v101,
                v100,
                0,
                v380);
            }
            else
            {
              DrawBMP(
                thisa->parrowm,
                3 * (thisa->helpw / 4) + thisa->facew,
                (signed __int64)((long double)k_2 * helph__
                               + (long double)(signed int)thisa->menuh
                               + (long double)(signed int)thisa->iconh),
                thisa->facew,
                thisa->faceh,
                thisa->cfg);
              DrawBMP(
                thisa->parrowp,
                (j + 1) * (thisa->helpw / 4) + 2 * thisa->facew,
                (signed __int64)((long double)k_2 * helph__
                               + (long double)(signed int)thisa->menuh
                               + (long double)(signed int)thisa->iconh),
                thisa->facew,
                thisa->faceh,
                thisa->cfg);
              v95 = thisa->cbg;
              v96 = thisa->ctfg;
              y = thisa->faceh;
              w = thisa->helpw / 4 - thisa->facew - 2 * thisa->iconw;
              yd = (signed int)((long double)k_2 * helph__
                              + (long double)(signed int)thisa->menuh
                              + (long double)(signed int)thisa->iconh);
              v97 = (const __int16 *)((j + 1) * (thisa->helpw / 4) + 3 * thisa->facew + thisa->iconw);
              v98 = thisa->mult_;
              if ( v98 < 2 )
                v98 = 2;
              v99 = Lan::getlan(
                      (int)&thisa->bd.st,
                      (Lan *const )((char *)picon__[0][0][3 * k_2 + j] + thisa->bd.st.lan.LAN_SET + v98 - 2),
                      v359);
              Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v99, v97, yd, w, y, v96, v95, 0, v380);
            }
          }
        }
        if ( thisa->bd.delayb == 1 )
          Line(
            helpw__,
            (signed int)(helph__ * 7.0
                       + (long double)(signed int)thisa->menuh
                       + (long double)(signed int)thisa->iconh
                       + (long double)(thisa->faceh / 2)),
            thisa->facew,
            0,
            thisa->cred);
        if ( thisa->barb )
          Bar(
            helpw__,
            (signed int)(helph__ * 8.0 + (long double)(signed int)thisa->menuh + (long double)(signed int)thisa->iconh),
            thisa->facew - 1,
            thisa->faceh - 1,
            thisa->ctfg,
            thisa->transparent);
      }
      break;
    case 0xFFFFFFFF:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v2 = thisa->cbg;
      v3 = thisa->ctfg;
      v4 = thisa->faceh;
      v5 = thisa->aboutw;
      v7 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP + 7), v6);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v7, 0, 0, v5, v4, v3, v2, v375);
      Window::setfontheight_((Window *const )thisa->fontfh, v8);
      pcheat__[0] = thisa->piconn;
      pcheat__[1] = thisa->piconm;
      prelax__[0] = thisa->pface[5];
      prelax__[1] = thisa->picone;
      DrawBMP(
        pcheat__[(unsigned __int8)thisa->cheatb],
        (thisa->aboutw - thisa->fontfh) / 2 + thisa->fontfh / -2,
        (thisa->fontth - thisa->fontfh) / 2 + thisa->menuh,
        thisa->fontfh,
        thisa->fontfh,
        thisa->cbg);
      DrawBMP(
        prelax__[(unsigned __int8)thisa->bd.relaxb],
        (thisa->aboutw - thisa->fontfh) / 2 + thisa->fontfh / 2,
        (thisa->fontth - thisa->fontfh) / 2 + thisa->menuh,
        thisa->fontfh,
        thisa->fontfh,
        thisa->cbg);
      Window::setfontheight_((Window *const )thisa->fonth, v9);
      v10 = thisa->cbg;
      v11 = thisa->ctfg;
      v12 = thisa->fonth;
      v13 = thisa->aboutw;
      v14 = thisa->menuh + thisa->fontth;
      v16 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_NAME, v15);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v16, 0, v14, v13, v12, v11, v10, v17);
      v18 = thisa->cbg;
      v19 = thisa->ctfg;
      v20 = thisa->fonth;
      v21 = thisa->aboutw;
      v22 = thisa->fontth + thisa->menuh + thisa->fonth;
      v24 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_VERSION, v23);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v24, 0, v22, v21, v20, v19, v18, v25);
      v26 = thisa->cbg;
      v27 = thisa->ctfg;
      v28 = thisa->fonth;
      v29 = thisa->aboutw;
      v30 = thisa->fontth + thisa->menuh + 2 * thisa->fonth;
      v32 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_AUTHOR, v31);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v32, 0, v30, v29, v28, v27, v26, v33);
      v34 = thisa->cbg;
      v35 = thisa->ctfg;
      v36 = thisa->fonth;
      v37 = thisa->aboutw;
      v38 = thisa->menuh + thisa->fontth + 3 * thisa->fonth;
      v40 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_LICENSE, v39);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v40, 0, v38, v37, v36, v35, v34, v41);
      break;
    case 1:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v107 = thisa->cbg;
      v108 = thisa->ctfg;
      v109 = thisa->faceh;
      v110 = thisa->helpw;
      v112 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP + 6), v111);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v112, 0, 0, v110, v109, v108, v107, v375);
      v113 = thisa->cbg;
      v114 = thisa->ctfg;
      v115 = (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2;
      v116 = thisa->helpw / 2;
      v117 = thisa->menuh;
      v118 = thisa->helpw / 2;
      v120 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_HELP_TITLE, v119);
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        (pbitmap)v120,
        (const __int16 *)v118,
        v117,
        v116,
        v115,
        v114,
        v113,
        v121);
      Window::setfontheight_((Window *const )thisa->fonth, v122);
      k__[0][0] = (int)thisa->pmenu1[0];
      k__[0][1] = (int)thisa->pmenu2[0];
      k__[0][2] = (int)thisa->pmenu3[0];
      k__[1][0] = (int)thisa->pface[4];
      k__[1][1] = (int)thisa->pface[0];
      k__[1][2] = (int)thisa->picone;
      k__[2][0] = (int)thisa->pmenuq[0];
      k__[2][1] = (int)thisa->pmenua[0];
      k__[2][2] = (int)thisa->pmenud[0];
      v393 = thisa->pmenut[0];
      v394 = thisa->pmenus[0];
      v395 = thisa->pmenum[0];
      v396 = *((_DWORD *)&thisa->launchh + 2 * (thisa->md + 30));
      v397 = *((_DWORD *)&thisa->titleh + thisa->singleb + 56);
      v398 = thisa->pface[7];
      v399 = thisa->pface[6];
      v400 = thisa->pface[5];
      qmemcpy(picon__, &off_4272A0, 0x44u);
      cheatn[0] = (const char *)a4567890vc;
      cheatn[1] = (_BYTE *)(a4567890vc + 2);
      cheatn[2] = (_BYTE *)(a4567890vc + 4);
      cheatn[3] = (_BYTE *)(a4567890vc + 6);
      cheatn[4] = (_BYTE *)(a4567890vc + 8);
      cheatn[5] = (_BYTE *)(a4567890vc + 10);
      cheatn[6] = (_BYTE *)(a4567890vc + 12);
      cheatn[7] = (_BYTE *)(a4567890vc + 14);
      cheatn[8] = (_BYTE *)(a4567890vc + 16);
      cheats[0] = "Auto Number";
      cheats[1] = "Auto Solve";
      cheats[2] = "Repeat Number";
      cheats[3] = "Repeat Solve";
      cheats[4] = "Repeat All";
      cheats[5] = "Auto Blank";
      cheats[6] = "Del Line";
      cheats[7] = "Up Level";
      cheats[8] = "Reset Steam";
      cheatc[0] = thisa->cblue;
      cheatc[1] = thisa->cblue;
      cheatc[2] = thisa->cblue;
      cheatc[3] = thisa->cblue;
      cheatc[4] = thisa->cblue;
      cheatc[5] = thisa->cblue;
      cheatc[6] = thisa->cblue;
      cheatc[7] = thisa->cred;
      cheatc[8] = thisa->cred;
      helpw___0 = thisa->iconw;
      helph___0 = (long double)(thisa->helph - thisa->okh_ - thisa->iconh - thisa->faceh) / 16.0;
      for ( k_3 = 0; k_3 <= 16; ++k_3 )
      {
        DrawBMP(
          (pbitmap)k__[0][k_3],
          helpw___0,
          (signed __int64)((long double)k_3 * helph___0
                         + (long double)(signed int)thisa->menuh
                         + (long double)(thisa->iconh / 2)),
          thisa->facew,
          thisa->faceh,
          thisa->cfg);
        Window::drawtextxy_(
          (Window *const )thisa->pwint,
          picon__[0][0][k_3],
          (const char *)(helpw___0 + thisa->facew + thisa->iconw),
          (signed int)((long double)k_3 * helph___0
                     + (long double)(signed int)thisa->menuh
                     + (long double)(thisa->iconh / 2)),
          thisa->ctfg,
          thisa->cbg,
          v374);
      }
      if ( thisa->cheatb == 1 )
      {
        for ( k_5 = 0; k_5 <= 8; ++k_5 )
        {
          Window::drawtextxy_(
            (Window *const )thisa->pwint,
            (pbitmap)cheatn[k_5],
            (const char *)(thisa->helpw / 4),
            (signed int)((long double)k_5 * helph___0
                       + (long double)(signed int)thisa->menuh
                       + (long double)(thisa->iconh / 2)),
            cheatc[k_5],
            thisa->cbg,
            v374);
          Window::drawtextxy_(
            (Window *const )thisa->pwint,
            (pbitmap)cheats[k_5],
            (const char *)(thisa->helpw / 4 + thisa->facew),
            (signed int)((long double)k_5 * helph___0
                       + (long double)(signed int)thisa->menuh
                       + (long double)(thisa->iconh / 2)),
            cheatc[k_5],
            thisa->cbg,
            v130);
        }
      }
      else
      {
        for ( k_4 = 0; k_4 <= 16; ++k_4 )
        {
          v123 = thisa->cbg;
          v124 = thisa->ctfg;
          v125 = thisa->faceh;
          v126 = thisa->helpw / 4;
          v127 = (signed int)((long double)k_4 * helph___0
                            + (long double)(signed int)thisa->menuh
                            + (long double)(thisa->iconh / 2));
          v128 = thisa->helpw / 4;
          v129 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(k_4 + thisa->bd.st.lan.LAN_HELP), v360);
          Window::drawtextxy_(
            (Window *const )thisa->pwint,
            (pbitmap)v129,
            (const __int16 *)v128,
            v127,
            v126,
            v125,
            v124,
            v123,
            0,
            v380);
        }
      }
      Line(thisa->helpw / 2, thisa->menuh, 0, thisa->helph - thisa->okh_, thisa->cline);
      for ( k_6 = 0; k_6 <= 11; ++k_6 )
        Window::paintline(
          thisa,
          (Window *const )thisa->piconn,
          thisa->piconc,
          (pbitmap)2,
          10,
          (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2,
          (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + (k_6 + 8) * thisa->iconh,
          v374);
      v131 = thisa->cbg;
      v132 = thisa->cred;
      v133 = 8 * thisa->iconh + thisa->menuh + (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 - thisa->faceh;
      v134 = 3 * thisa->helpw / 2;
      v135 = Window::getstringwidth_((Window *const )"PgUp", v361);
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        (pbitmap)"PgUp",
        (const char *)((v134 - v135) >> 1),
        v133,
        v132,
        v131,
        v374);
      v136 = thisa->cfg;
      v137 = thisa->cblue;
      v138 = thisa->menuh + (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + 8 * thisa->iconh;
      v139 = 3 * thisa->helpw / 2;
      v141 = Window::getstringwidth_((Window *const )"PgDn", v140);
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        (pbitmap)"PgDn",
        (const char *)((v139 - v141) >> 1),
        v138,
        v137,
        v136,
        v142);
      Bar(
        2 * thisa->iconw + (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 - thisa->arroww,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cmine);
      Bar(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 2 * thisa->iconw,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      Bar(
        (3 * thisa->helpw / 2 - thisa->arroww) / 2,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 20 * thisa->iconh - thisa->arrowh,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      Bar(
        (3 * thisa->helpw / 2 - thisa->arroww) / 2,
        20 * thisa->iconh + (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh,
        thisa->arroww,
        thisa->arrowh,
        thisa->cbg);
      Bar(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 12 * thisa->iconw - thisa->arroww,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      Bar(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 12 * thisa->iconw,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cbg);
      DrawBMP(
        thisa->parrowm,
        2 * thisa->iconw + (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 - thisa->arroww,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      DrawBMP(
        thisa->parrowp,
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 2 * thisa->iconw,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      DrawBMP(
        thisa->parrowu,
        (3 * thisa->helpw / 2 - thisa->arroww) / 2,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 20 * thisa->iconh - thisa->arrowh,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      DrawBMP(
        thisa->parrowd,
        (3 * thisa->helpw / 2 - thisa->arroww) / 2,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 20 * thisa->iconh,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      DrawBMP(
        thisa->parrowl,
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 12 * thisa->iconw - thisa->arroww,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      DrawBMP(
        thisa->parrowr,
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 12 * thisa->iconw,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh - 1,
        12 * thisa->iconw,
        0,
        thisa->ctfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2,
        thisa->menuh + (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + 8 * thisa->iconh - 1,
        12 * thisa->iconw,
        0,
        thisa->ctfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 20 * thisa->iconh - 1,
        12 * thisa->iconw,
        0,
        thisa->ctfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 - 1,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh,
        0,
        20 * thisa->iconh,
        thisa->ctfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 2 * thisa->iconw - 1,
        (thisa->helph - thisa->okh_ - 4 * thisa->iconh) / 2 + thisa->menuh,
        0,
        12 * thisa->iconh,
        thisa->ctfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 12 * thisa->iconw - 1,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh,
        0,
        20 * thisa->iconh,
        thisa->ctfg);
      break;
    case 2:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v143 = thisa->cbg;
      v144 = thisa->ctfg;
      v145 = thisa->faceh;
      v146 = thisa->helpw;
      v148 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_TITLE + 1), v147);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v148, 0, 0, v146, v145, v144, v143, v375);
      Window::setfontheight_((Window *const )thisa->fontmh, v149);
      for ( j_0 = 0; j_0 <= 2; ++j_0 )
      {
        for ( i = 0; i <= 3; ++i )
        {
          Block::initbl(v353);
          v150 = j_0;
          if ( j_0 > 0 )
            v150 = 1;
          j_ = v150;
          if ( j_0 == 1 )
          {
            if ( i == 1 || i == 3 )
              (*thisa->bl.flag)[j_ + 128] = 1;
          }
          else if ( j_0 == 2 )
          {
            if ( i == 1 )
              (*thisa->bl.qstn)[j_ + 128] = 1;
          }
          else if ( !j_0 && (i == 1 || i == 3) )
          {
            (*thisa->bl.blck)[j_ + 128] = 1;
          }
          if ( i == 2 )
            (*thisa->bl.qstn)[j_ + 128] = 1;
          Window::paintboard(
            thisa,
            (Window *)((char *)thisa + 3304),
            (Block *const )((2 * i + 1) * thisa->helpw / 8 + thisa->bl.w * thisa->iconw / -2),
            (2 * j_0 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->bl.h * thisa->iconh / -2,
            1,
            j_,
            v371);
        }
      }
      for ( i_0 = 0; i_0 <= 2; ++i_0 )
      {
        for ( j_1 = 0; j_1 <= 2; ++j_1 )
        {
          picon__[0][0][0] = thisa->piconc;
          picon__[0][0][1] = thisa->picona;
          picon__[0][0][2] = thisa->picon[3];
          picon__[0][0][3] = thisa->piconp;
          picon__[0][0][4] = thisa->piconp;
          picon__[0][1][0] = thisa->piconp;
          picon__[0][1][1] = thisa->piconp;
          picon__[0][1][2] = thisa->piconp;
          picon__[0][1][3] = thisa->piconp;
          picon__[0][1][4] = thisa->piconp;
          picon__[0][2][0] = thisa->piconq;
          picon__[0][2][1] = thisa->picona;
          picon__[0][2][2] = thisa->picon[3];
          picon__[0][2][3] = thisa->piconp;
          picon__[0][2][4] = thisa->piconp;
          picon__[1][0][0] = thisa->piconc;
          picon__[1][0][1] = thisa->picona;
          picon__[1][0][2] = thisa->piconm;
          picon__[1][0][3] = thisa->picona;
          picon__[1][0][4] = thisa->piconf;
          picon__[1][1][0] = thisa->piconp;
          picon__[1][1][1] = thisa->piconp;
          picon__[1][1][2] = thisa->piconp;
          picon__[1][1][3] = thisa->piconp;
          picon__[1][1][4] = thisa->piconp;
          picon__[1][2][0] = thisa->piconq;
          picon__[1][2][1] = thisa->picona;
          picon__[1][2][2] = thisa->piconm;
          picon__[1][2][3] = thisa->picona;
          picon__[1][2][4] = thisa->piconf;
          picon__[2][0][0] = thisa->piconc;
          picon__[2][0][1] = thisa->picona;
          picon__[2][0][2] = thisa->piconq;
          picon__[2][0][3] = thisa->piconp;
          picon__[2][0][4] = thisa->piconp;
          picon__[2][1][0] = thisa->piconp;
          picon__[2][1][1] = thisa->piconp;
          picon__[2][1][2] = thisa->piconp;
          picon__[2][1][3] = thisa->piconp;
          picon__[2][1][4] = thisa->piconp;
          picon__[2][2][0] = thisa->piconq;
          picon__[2][2][1] = thisa->picona;
          picon__[2][2][2] = thisa->piconc;
          picon__[2][2][3] = thisa->piconp;
          picon__[2][2][4] = thisa->piconp;
          *(_QWORD *)&k__[0][0] = 3LL;
          k__[0][2] = 3;
          *(_QWORD *)&k__[1][0] = 5LL;
          k__[1][2] = 5;
          *(_QWORD *)&k__[2][0] = 3LL;
          k__[2][2] = 3;
          if ( i_0 && i_0 != 2 || j_1 == 2 )
          {
            if ( (!i_0 || i_0 == 2) && j_1 == 2 )
              DrawBMP(
                thisa->pclickr,
                2 * (i_0 + 1) * thisa->helpw / 8 + thisa->clickw / -2,
                -3 * thisa->iconh + 5 * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cfg);
          }
          else
          {
            DrawBMP(
              thisa->pclickl,
              2 * (i_0 + 1) * thisa->helpw / 8 + thisa->clickw / -2,
              -3 * thisa->iconh + (2 * j_1 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
              thisa->cfg);
          }
          for ( k_7 = 0; k__[0][i_0 + 3 * j_1] > k_7; ++k_7 )
          {
            if ( picon__[0][0][5 * i_0 + 15 * j_1 + k_7] == thisa->picona )
              DrawBMP(
                picon__[0][0][5 * i_0 + 15 * j_1 + k_7],
                2 * (i_0 + 1) * thisa->helpw / 8 + thisa->iconw * (2 * k_7 - k__[0][i_0 + 3 * j_1]) / 2,
                thisa->clickh + -3 * thisa->iconh + (2 * j_1 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cfg);
            else
              DrawBMP(
                picon__[0][0][5 * i_0 + 15 * j_1 + k_7],
                2 * (i_0 + 1) * thisa->helpw / 8 + thisa->iconw * (2 * k_7 - k__[0][i_0 + 3 * j_1]) / 2,
                thisa->clickh + -3 * thisa->iconh + (2 * j_1 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cbg);
          }
          if ( !i_0 || i_0 == 2 )
          {
            v151 = thisa->cbg;
            v152 = thisa->ctfg;
            v153 = 2 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 - thisa->clickh;
            v154 = thisa->helpw / 2;
            v155 = thisa->menuh
                 + thisa->clickh
                 + -3 * thisa->iconh
                 + (2 * j_1 + 1) * (thisa->helph - thisa->okh_) / 6
                 + thisa->iconh;
            v156 = i_0 / 2 * thisa->helpw / 2;
            v157 = Lan::getlan(
                     (int)&thisa->bd.st,
                     (Lan *const )(2 * j_1 + thisa->bd.st.lan.LAN_HELP_MENU + i_0 / 2),
                     v362);
            Window::drawtextxy_(
              (Window *const )thisa->pwint,
              (pbitmap)v157,
              (const __int16 *)v156,
              v155,
              v154,
              v153,
              v152,
              v151,
              v375);
          }
        }
      }
      Line(thisa->helpw / 2, thisa->menuh, 0, thisa->helph - thisa->okh_, thisa->cline);
      for ( k_8 = 1; k_8 <= 2; ++k_8 )
        Line(0, thisa->menuh + k_8 * (thisa->helph - thisa->okh_) / 3, thisa->helpw, 0, thisa->cline);
      Window::setfontheight_((Window *const )thisa->fonth, v363);
      break;
    case 3:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v158 = thisa->cbg;
      v159 = thisa->ctfg;
      v160 = thisa->faceh;
      v161 = thisa->helpw;
      v163 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_TITLE + 2), v162);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v163, 0, 0, v161, v160, v159, v158, v375);
      Window::setfontheight_((Window *const )thisa->fontmh, v164);
      for ( j_2 = 0; j_2 <= 2; ++j_2 )
      {
        for ( i_1 = 0; i_1 <= 3; ++i_1 )
        {
          Block::initbl(v354);
          (*thisa->bl.blck)[128] = 1;
          (*thisa->bl.flag)[129] = 1;
          j__0 = 2;
          switch ( j_2 )
          {
            case 1:
              (*thisa->bl.flag)[129] = 1;
              if ( !i_1 )
                (*thisa->bl.qstn)[1] = 1;
              if ( i_1 > 0 )
              {
                (*thisa->bl.blck)[2] = 1;
                (*thisa->bl.blck)[3] = 1;
              }
              if ( i_1 == 2 )
                (*thisa->bl.flag)[1] = 1;
              break;
            case 2:
              (*thisa->bl.flag)[129] = 1;
              if ( !i_1 )
                (*thisa->bl.qstn)[3] = 1;
              if ( i_1 > 0 )
              {
                (*thisa->bl.blck)[2] = 1;
                (*thisa->bl.flag)[1] = 1;
              }
              if ( i_1 == 2 )
                (*thisa->bl.blck)[3] = 1;
              break;
            case 0:
              if ( i_1 <= 1 )
                j__0 = 0;
              if ( !i_1 )
                (*thisa->bl.qstn)[1] = 1;
              if ( i_1 > 0 )
              {
                *(_BYTE *)thisa->bl.flag = 1;
                (*thisa->bl.flag)[1] = 1;
              }
              if ( i_1 == 3 )
              {
                (*thisa->bl.blck)[2] = 1;
                (*thisa->bl.blck)[3] = 1;
              }
              break;
          }
          if ( !j_2 || i_1 <= 2 )
            Window::paintboard(
              thisa,
              (Window *)((char *)thisa + 3304),
              (Block *const )((2 * i_1 + 1 + (j_2 != 0)) * thisa->helpw / 8 + thisa->bl.w * thisa->iconw / -2),
              (2 * j_2 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->bl.h * thisa->iconh / -2,
              1,
              j__0,
              v372);
        }
      }
      for ( i_2 = 0; i_2 <= 2; ++i_2 )
      {
        for ( j_3 = 0; j_3 <= 2; ++j_3 )
        {
          memset(picon__, 0, 0xF0u);
          *(_QWORD *)&picon__[0][0][0] = *(_QWORD *)&thisa->piconc;
          picon__[0][0][2] = thisa->piconf;
          picon__[0][0][3] = thisa->piconu;
          picon__[0][0][4] = thisa->picon[3];
          picon__[0][1][0] = thisa->piconp;
          picon__[0][1][1] = thisa->piconp;
          picon__[0][1][2] = thisa->piconp;
          picon__[0][1][3] = thisa->piconp;
          picon__[0][1][4] = thisa->piconp;
          picon__[0][2][0] = thisa->piconf;
          picon__[0][2][1] = thisa->piconu;
          picon__[0][2][2] = thisa->picon[2];
          picon__[0][2][3] = thisa->piconp;
          picon__[0][2][4] = thisa->piconp;
          *(_QWORD *)&picon__[1][1][0] = *(_QWORD *)&thisa->piconq;
          picon__[1][1][2] = thisa->piconu;
          picon__[1][1][3] = thisa->picon[2];
          picon__[1][1][4] = thisa->piconp;
          *(_QWORD *)&picon__[1][2][0] = *(_QWORD *)&thisa->piconc;
          picon__[1][2][2] = thisa->piconf;
          picon__[1][2][3] = thisa->piconu;
          picon__[1][2][4] = thisa->picon[2];
          picon__[2][0][0] = thisa->piconp;
          picon__[2][0][1] = thisa->piconp;
          picon__[2][0][2] = thisa->piconp;
          picon__[2][0][3] = thisa->piconp;
          picon__[2][0][4] = thisa->piconp;
          *(_QWORD *)&picon__[2][2][0] = *(_QWORD *)&thisa->piconq;
          picon__[2][2][2] = thisa->piconu;
          picon__[2][2][3] = thisa->picon[2];
          picon__[2][2][4] = thisa->piconp;
          v412 = thisa->piconf;
          v413 = thisa->piconu;
          v414 = thisa->picon[2];
          v415 = thisa->piconp;
          v416 = thisa->piconp;
          v417 = thisa->piconp;
          v418 = thisa->piconp;
          v419 = thisa->piconp;
          v420 = thisa->piconp;
          v421 = thisa->piconp;
          *(_QWORD *)&k__[0][0] = 5LL;
          k__[0][2] = 3;
          *(_QWORD *)&k__[1][0] = 21474836484LL;
          k__[1][2] = 0;
          *(_QWORD *)&k__[2][0] = 12884901892LL;
          k__[2][2] = 0;
          if ( i_2 && (i_2 != 2 || j_3) )
          {
            if ( i_2 == 1 && j_3 )
              DrawBMP(
                thisa->pclickn,
                (2 * (i_2 + 1) + (j_3 != 0)) * thisa->helpw / 8 + thisa->clickw / -2,
                -3 * thisa->iconh + (2 * j_3 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cfg);
          }
          else
          {
            DrawBMP(
              thisa->pclicka,
              (2 * (i_2 + 1) + (j_3 != 0)) * thisa->helpw / 8 + thisa->clickw / -2,
              -3 * thisa->iconh + (2 * j_3 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
              thisa->cfg);
          }
          for ( k_9 = 0; k__[0][i_2 + 3 * j_3] > k_9; ++k_9 )
          {
            if ( picon__[0][0][20 * j_3 + 5 * i_2 + k_9] == thisa->piconu )
              DrawBMP(
                picon__[0][0][20 * j_3 + 5 * i_2 + k_9],
                (2 * (i_2 + 1) + (j_3 != 0)) * thisa->helpw / 8 + thisa->iconw * (2 * k_9 - k__[0][i_2 + 3 * j_3]) / 2,
                thisa->clickh + -3 * thisa->iconh + (2 * j_3 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cfg);
            else
              DrawBMP(
                picon__[0][0][20 * j_3 + 5 * i_2 + k_9],
                (2 * (i_2 + 1) + (j_3 != 0)) * thisa->helpw / 8 + thisa->iconw * (2 * k_9 - k__[0][i_2 + 3 * j_3]) / 2,
                thisa->clickh + -3 * thisa->iconh + (2 * j_3 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cbg);
          }
          if ( (!i_2 || i_2 == 2) && !j_3 )
          {
            v165 = thisa->cbg;
            v166 = thisa->ctfg;
            v167 = 2 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 - thisa->clickh;
            v168 = thisa->helpw / 2;
            v169 = thisa->menuh + thisa->clickh + -3 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 + thisa->iconh;
            v170 = i_2 / 2 * thisa->helpw / 2;
            v171 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + i_2 / 2 + 6), v364);
            Window::drawtextxy_(
              (Window *const )thisa->pwint,
              (pbitmap)v171,
              (const __int16 *)v170,
              v169,
              v168,
              v167,
              v166,
              v165,
              v375);
          }
          if ( !i_2 && j_3 > 0 )
          {
            v172 = thisa->cbg;
            v173 = thisa->ctfg;
            v174 = 2 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 - thisa->clickh;
            v175 = thisa->helpw;
            v176 = thisa->menuh
                 + thisa->clickh
                 + -3 * thisa->iconh
                 + (2 * j_3 + 1) * (thisa->helph - thisa->okh_) / 6
                 + thisa->iconh;
            v177 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + j_3 + 7), v364);
            Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v177, 0, v176, v175, v174, v173, v172, v375);
          }
        }
      }
      Line(thisa->helpw / 2, thisa->menuh, 0, (thisa->helph - thisa->okh_) / 3, thisa->cline);
      for ( k_10 = 1; k_10 <= 2; ++k_10 )
        Line(0, thisa->menuh + k_10 * (thisa->helph - thisa->okh_) / 3, thisa->helpw, 0, thisa->cline);
      break;
    case 4:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v178 = thisa->cbg;
      v179 = thisa->ctfg;
      v180 = thisa->faceh;
      v181 = thisa->helpw;
      v183 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_TITLE + 3), v182);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v183, 0, 0, v181, v180, v179, v178, v375);
      Window::setfontheight_((Window *const )thisa->fontmh, v184);
      iconwl = 5;
      iconwm = 18;
      iconwr = 20;
      iconwn = 34;
      iconh1 = 2;
      iconh2 = 10;
      iconh3 = 21;
      Window::paintline(
        thisa,
        (Window *const )thisa->picone,
        (pbitmap)2,
        20 * thisa->iconw,
        2 * thisa->iconh + thisa->menuh,
        v185);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        (pbitmap)0xC,
        20 * thisa->iconw,
        3 * thisa->iconh + thisa->menuh,
        v186);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        (pbitmap)0xC,
        20 * thisa->iconw,
        4 * thisa->iconh + thisa->menuh,
        v187);
      Window::paintline(
        thisa,
        (Window *const )thisa->picone,
        (pbitmap)2,
        5 * thisa->iconw,
        4 * thisa->iconh + thisa->menuh,
        v188);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconm,
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)5,
        1,
        1,
        5,
        5 * thisa->iconw,
        5 * thisa->iconh + thisa->menuh,
        v381);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconf,
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)5,
        1,
        1,
        5,
        20 * thisa->iconw,
        5 * thisa->iconh + thisa->menuh,
        v189);
      DrawBMP(thisa->picona, 18 * thisa->iconw, 5 * thisa->iconh + thisa->menuh, thisa->cfg);
      DrawBMP(
        thisa->pface[3],
        18 * thisa->iconw + (thisa->facew - thisa->iconw) / -2,
        thisa->menuh + 5 * thisa->iconh - thisa->iconh + thisa->faceh / -2,
        thisa->cfg);
      v190 = thisa->cbg;
      v191 = thisa->ctfg;
      v192 = 2 * thisa->iconh;
      v193 = thisa->helpw;
      v194 = 6 * thisa->iconh + thisa->menuh;
      v196 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 10), v195);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v196, 0, v194, v193, v192, v191, v190, v197);
      for ( k_11 = 0; k_11 <= 2; ++k_11 )
      {
        Window::paintline(
          thisa,
          (Window *const )thisa->picone,
          (pbitmap)2,
          iconwl * thisa->iconw,
          (3 * k_11 + iconh2) * thisa->iconh + thisa->menuh,
          v367);
        Window::paintline(
          thisa,
          (Window *const )thisa->picone,
          (pbitmap)(k_11 + 3),
          iconwr * thisa->iconw,
          (3 * k_11 + iconh2) * thisa->iconh + thisa->menuh,
          v198);
        Window::paintline(
          thisa,
          (Window *const )thisa->piconc,
          (pbitmap)0xC,
          iconwl * thisa->iconw,
          (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->menuh,
          v199);
        Window::paintline(
          thisa,
          (Window *const )thisa->piconc,
          (pbitmap)0xC,
          iconwr * thisa->iconw,
          (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->menuh,
          v200);
        Window::paintnumber(
          thisa,
          (Window *const )(5 * k_11),
          2,
          iconwn * thisa->iconw,
          thisa->menuh + (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->digth[0] / -2,
          v201);
        DrawBMP(thisa->picona, iconwm * thisa->iconw, (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->menuh, thisa->cfg);
      }
      v202 = thisa->cbg;
      v203 = thisa->ctfg;
      v204 = (iconh3 - iconh2 - 10) * thisa->iconh + thisa->iconh / 2;
      v205 = thisa->helpw;
      v206 = thisa->iconh * (iconh2 + 8) + thisa->menuh;
      v207 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 11), v365);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v207, 0, v206, v205, v204, v203, v202, v376);
      Window::paintline(
        thisa,
        (Window *const )thisa->picone,
        (pbitmap)0xC,
        iconwl * thisa->iconw,
        iconh3 * thisa->iconh + thisa->menuh,
        v208);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        (pbitmap)0xC,
        iconwr * thisa->iconw,
        iconh3 * thisa->iconh + thisa->menuh,
        v209);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        (pbitmap)0xC,
        iconwl * thisa->iconw,
        thisa->iconh * (iconh3 + 1) + thisa->menuh,
        v210);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        (pbitmap)0xC,
        iconwr * thisa->iconw,
        thisa->iconh * (iconh3 + 1) + thisa->menuh,
        v211);
      DrawBMP(thisa->picona, iconwm * thisa->iconw, thisa->iconh * (iconh3 + 1) + thisa->menuh, thisa->cfg);
      v212 = thisa->cbg;
      v213 = thisa->ctfg;
      v214 = thisa->helph - thisa->okh_ - (iconh3 + 2) * thisa->iconh;
      v215 = thisa->helpw;
      v216 = thisa->iconh * (iconh3 + 2) + thisa->menuh;
      v218 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 12), v217);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v218, 0, v216, v215, v214, v213, v212, v219);
      Line(0, thisa->menuh + (iconh2 - 2) * thisa->iconh, thisa->helpw, 0, thisa->cline);
      Line(0, (iconh3 - 2) * thisa->iconh + thisa->menuh + thisa->iconh / 2, thisa->helpw, 0, thisa->cline);
      Window::setfontheight_((Window *const )thisa->fonth, v220);
      break;
    case 5:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v221 = thisa->cbg;
      v222 = thisa->ctfg;
      v223 = thisa->faceh;
      v224 = thisa->helpw;
      v226 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_TITLE + 4), v225);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v226, 0, 0, v224, v223, v222, v221, v375);
      Window::setfontheight_((Window *const )thisa->fontmh, v227);
      iconwl_0 = 3;
      iconwm_0 = 16;
      iconwr_0 = 20;
      iconwn_0 = 34;
      iconh1_0 = 2;
      iconh2_0 = 6;
      iconh3_0 = 11;
      iconh4 = 22;
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->picon[2],
        thisa->piconp,
        (pbitmap)4,
        1,
        7,
        3 * thisa->iconw,
        thisa->iconh / -2 + 2 * thisa->iconh + thisa->menuh,
        v228);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconf,
        thisa->picon[2],
        thisa->piconp,
        (pbitmap)2,
        2,
        1,
        7,
        3 * thisa->iconw,
        thisa->iconh / -2 + 3 * thisa->iconh + thisa->menuh,
        v381);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconf,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)2,
        1,
        1,
        1,
        7,
        3 * thisa->iconw,
        thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh,
        (int)thisa->piconp);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)4,
        1,
        7,
        20 * thisa->iconw,
        thisa->iconh / -2 + 3 * thisa->iconh + thisa->menuh,
        v229);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconf,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)2,
        1,
        1,
        1,
        7,
        20 * thisa->iconw,
        thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh,
        (int)thisa->piconp);
      Line(
        3 * thisa->iconw,
        thisa->menuh + thisa->iconh / 2 + thisa->iconh / -2 + 3 * thisa->iconh,
        12 * thisa->iconw,
        0,
        thisa->cred);
      DrawBMP(thisa->piconf, 16 * thisa->iconw, thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh, thisa->cbg);
      DrawBMP(thisa->piconu, 17 * thisa->iconw, thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh, thisa->cfg);
      DrawBMP(thisa->piconn, 18 * thisa->iconw, thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh, thisa->cbg);
      DrawBMP(
        thisa->pface[4],
        17 * thisa->iconw + (thisa->facew - thisa->iconw) / -2,
        thisa->menuh + thisa->iconh / -2 + 4 * thisa->iconh - thisa->iconh + thisa->faceh / -2,
        thisa->cbg);
      Window::paintnumber(
        thisa,
        (Window *const )1,
        4,
        34 * thisa->iconw,
        thisa->menuh + thisa->iconh / -2 + 4 * thisa->iconh + thisa->digth[0] / -2,
        v230);
      v231 = thisa->cbg;
      v232 = thisa->ctfg;
      v233 = 3 * thisa->iconh / 2;
      v234 = thisa->helpw;
      v235 = thisa->iconh / -2 + 5 * thisa->iconh + thisa->menuh;
      v237 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 13), v236);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v237, 0, v235, v234, v233, v232, v231, v238);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->picon[2],
        thisa->piconp,
        (pbitmap)4,
        1,
        7,
        3 * thisa->iconw,
        6 * thisa->iconh + thisa->menuh,
        v239);
      Window::paintline(
        thisa,
        (Window *const )thisa->picon[1],
        thisa->picon[4],
        thisa->piconc,
        thisa->picon[2],
        thisa->piconp,
        (pbitmap)1,
        1,
        2,
        1,
        7,
        3 * thisa->iconw,
        7 * thisa->iconh + thisa->menuh,
        (int)thisa->piconp);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconc,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)2,
        1,
        1,
        1,
        7,
        3 * thisa->iconw,
        8 * thisa->iconh + thisa->menuh,
        (int)thisa->piconp);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)4,
        1,
        7,
        20 * thisa->iconw,
        7 * thisa->iconh + thisa->menuh,
        v240);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)3,
        1,
        1,
        7,
        20 * thisa->iconw,
        8 * thisa->iconh + thisa->menuh,
        v241);
      Line(3 * thisa->iconw, thisa->menuh + thisa->iconh / 2 + 7 * thisa->iconh, 12 * thisa->iconw, 0, thisa->cred);
      DrawBMP(thisa->piconc, 16 * thisa->iconw, 8 * thisa->iconh + thisa->menuh, thisa->cbg);
      DrawBMP(thisa->piconu, 17 * thisa->iconw, 8 * thisa->iconh + thisa->menuh, thisa->cfg);
      DrawBMP(thisa->piconn, 18 * thisa->iconw, 8 * thisa->iconh + thisa->menuh, thisa->cbg);
      DrawBMP(
        thisa->pface[4],
        17 * thisa->iconw + (thisa->facew - thisa->iconw) / -2,
        thisa->menuh + 8 * thisa->iconh - thisa->iconh + thisa->faceh / -2,
        thisa->cbg);
      Window::paintnumber(
        thisa,
        (Window *const )1,
        4,
        34 * thisa->iconw,
        thisa->menuh + 8 * thisa->iconh + thisa->digth[0] / -2,
        v242);
      v243 = thisa->cbg;
      v244 = thisa->ctfg;
      v245 = 3 * thisa->iconh / 2;
      v246 = thisa->helpw;
      v247 = 9 * thisa->iconh + thisa->menuh;
      v249 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 14), v248);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v249, 0, v247, v246, v245, v244, v243, v250);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconp,
        (pbitmap)0xC,
        3 * thisa->iconw,
        thisa->iconh / -2 + 15 * thisa->iconh + thisa->menuh,
        v251);
      Line(
        3 * thisa->iconw,
        thisa->menuh + thisa->iconh / 2 + thisa->iconh / -2 + 15 * thisa->iconh,
        12 * thisa->iconw,
        0,
        thisa->cred);
      for ( k_12 = 0; k_12 <= 7; ++k_12 )
      {
        if ( k_12 > 4 )
          Window::paintline(
            thisa,
            (Window *const )thisa->piconc,
            (pbitmap)0xC,
            iconwl_0 * thisa->iconw,
            thisa->iconh / -2 + thisa->iconh * (iconh3_0 + k_12) + thisa->menuh,
            v368);
        if ( k_12 > 0 )
          Window::paintline(
            thisa,
            (Window *const )thisa->piconc,
            (pbitmap)0xC,
            iconwr_0 * thisa->iconw,
            thisa->iconh / -2 + thisa->iconh * (iconh3_0 + k_12) + thisa->menuh,
            v368);
      }
      DrawBMP(
        thisa->picona,
        (iconwm_0 + 1) * thisa->iconw,
        thisa->iconh / -2 + thisa->iconh * (iconh3_0 + 7) + thisa->menuh,
        thisa->cfg);
      DrawBMP(
        thisa->pface[1],
        thisa->iconw * (iconwm_0 + 1) + (thisa->facew - thisa->iconw) / -2,
        thisa->menuh + thisa->iconh / -2 + thisa->iconh * (iconh3_0 + 7) - thisa->iconh + thisa->faceh / -2,
        thisa->cfg);
      Window::paintnumber(
        thisa,
        (Window *const )5,
        4,
        iconwn_0 * thisa->iconw,
        thisa->menuh + thisa->iconh / -2 + thisa->iconh * (iconh3_0 + 7) + thisa->digth[0] / -2,
        v368);
      v252 = thisa->cbg;
      v253 = thisa->ctfg;
      v254 = 3 * thisa->iconh / 2;
      v255 = thisa->helpw;
      v256 = thisa->iconh / -2 + thisa->iconh * (iconh3_0 + 8) + thisa->menuh;
      v258 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 15), v257);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v258, 0, v256, v255, v254, v253, v252, v377);
      for ( k_13 = 0; k_13 <= 2; ++k_13 )
      {
        Window::paintnumber(
          thisa,
          (Window *const )((k_13 + 2) * (k_13 + 2)),
          4,
          (2 * k_13 + 1) * thisa->helpw / 6 - 4 * thisa->digtw[0] + thisa->iconw / -2,
          thisa->menuh + iconh4 * thisa->iconh + thisa->digth[0] / -2,
          v369);
        Window::paintnumber(
          thisa,
          (Window *const )(k_13 + 2),
          2,
          2 * thisa->digtw[0] + (2 * k_13 + 1) * thisa->helpw / 6 + thisa->iconw / 2,
          thisa->menuh + iconh4 * thisa->iconh + thisa->digth[0] / -2,
          v259);
        DrawBMP(
          thisa->picona,
          thisa->digtw[0] + (2 * k_13 + 1) * thisa->helpw / 6 + thisa->iconw / -2,
          thisa->menuh + iconh4 * thisa->iconh + thisa->iconh / -2,
          thisa->cfg);
      }
      v260 = thisa->cbg;
      v261 = thisa->ctfg;
      v262 = thisa->helph - thisa->okh_ - (iconh4 * thisa->iconh + thisa->digth[0] / 2);
      v263 = thisa->helpw;
      v264 = thisa->digth[0] / 2 + iconh4 * thisa->iconh + thisa->menuh;
      v265 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 16), v366);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v265, 0, v264, v263, v262, v261, v260, v378);
      Line(0, thisa->menuh + thisa->iconh * (iconh3_0 - 1) + thisa->iconh / 2, thisa->helpw, 0, thisa->cline);
      Line(0, thisa->iconh * (iconh4 - 2) + thisa->menuh, thisa->helpw, 0, thisa->cline);
      Window::setfontheight_((Window *const )thisa->fonth, v266);
      break;
    case 6:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v267 = thisa->cbg;
      v268 = thisa->ctfg;
      v269 = thisa->faceh;
      v270 = thisa->helpw;
      v272 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_TITLE + 5), v271);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v272, 0, 0, v270, v269, v268, v267, v375);
      Window::setfontheight_((Window *const )thisa->fontmh, v273);
      for ( i_3 = 0; i_3 <= 31; ++i_3 )
      {
        for ( j_4 = 0; j_4 <= 23; ++j_4 )
          DrawBMP(
            thisa->piconp,
            (i_3 + 4) * thisa->iconw,
            thisa->menuh + thisa->iconh / 2 + j_4 * thisa->iconh,
            thisa->cfg);
      }
      for ( j_5 = 0; j_5 <= 23; ++j_5 )
      {
        if ( j_5 <= 11 )
          v274 = 2;
        else
          v274 = 3;
        if ( j_5 <= 15 )
          v275 = 0;
        else
          v275 = 3;
        Window::paintline(
          thisa,
          (Window *const )thisa->piconn,
          (pbitmap)(v274 + v275),
          5 * thisa->iconw,
          thisa->iconh / 2 + thisa->menuh + (j_5 + 1) * thisa->iconh - thisa->iconh,
          v370);
      }
      for ( j_6 = 0; j_6 <= 23; ++j_6 )
        DrawBMP(
          *((pbitmap *)&thisa->titlew + j_6 % 10 + 85),
          4 * thisa->iconw,
          j_6 * thisa->iconh + thisa->iconh / 2 + thisa->menuh,
          thisa->cbg);
      for ( i_4 = 0; i_4 <= 31; ++i_4 )
        DrawBMP(
          *((pbitmap *)&thisa->titlew + i_4 % 10 + 85),
          (i_4 + 4) * thisa->iconw,
          thisa->iconh / 2 + thisa->menuh,
          thisa->cbg);
      DrawBMP(
        thisa->pmenu1[0],
        16 * thisa->iconw - thisa->menuw,
        thisa->iconh / 2 + thisa->menuh + 12 * thisa->iconh - thisa->menuh,
        thisa->cbg);
      DrawBMP(
        thisa->pmenu2[0],
        20 * thisa->iconw - thisa->menuw,
        16 * thisa->iconh + thisa->menuh + thisa->iconh / 2 - thisa->menuh,
        thisa->cbg);
      DrawBMP(
        thisa->pmenu3[0],
        36 * thisa->iconw - thisa->menuw,
        thisa->iconh / 2 + thisa->menuh + 24 * thisa->iconh - thisa->menuh,
        thisa->cbg);
      Line(4 * thisa->iconw, thisa->iconh / 2 + thisa->menuh + 12 * thisa->iconh - 1, 12 * thisa->iconw, 0, thisa->ctfg);
      Line(4 * thisa->iconw, thisa->menuh + thisa->iconh / 2 + 16 * thisa->iconh - 1, 16 * thisa->iconw, 0, thisa->ctfg);
      Line(4 * thisa->iconw, thisa->iconh / 2 + thisa->menuh + 24 * thisa->iconh - 1, 32 * thisa->iconw, 0, thisa->ctfg);
      Line(4 * thisa->iconw, thisa->iconh / 2 + thisa->menuh - 1, 32 * thisa->iconw, 0, thisa->ctfg);
      Line(16 * thisa->iconw - 1, thisa->menuh + thisa->iconh / 2, 0, 12 * thisa->iconh, thisa->ctfg);
      Line(20 * thisa->iconw - 1, thisa->iconh / 2 + thisa->menuh, 0, 16 * thisa->iconh, thisa->ctfg);
      Line(36 * thisa->iconw - 1, thisa->iconh / 2 + thisa->menuh, 0, 24 * thisa->iconh, thisa->ctfg);
      Line(4 * thisa->iconw - 1, thisa->menuh + thisa->iconh / 2, 0, 24 * thisa->iconh, thisa->ctfg);
      v276 = thisa->cfg;
      v277 = thisa->ctfg;
      v278 = thisa->fontmh;
      v279 = 15 * thisa->iconw - thisa->menuw;
      v280 = thisa->iconh / 2 + thisa->menuh + 12 * thisa->iconh - thisa->fontmh - 1;
      v281 = (const __int16 *)(5 * thisa->iconw);
      v283 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 17), v282);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v283, v281, v280, v279, v278, v277, v276, 0, v380);
      v284 = thisa->cfg;
      v285 = thisa->ctfg;
      v286 = thisa->fontmh;
      v287 = 15 * thisa->iconw - thisa->menuw;
      v288 = 16 * thisa->iconh + thisa->menuh + thisa->iconh / 2 - thisa->fontmh - 1;
      v289 = (const __int16 *)(5 * thisa->iconw);
      v291 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 18), v290);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v291, v289, v288, v287, v286, v285, v284, 0, v292);
      v293 = thisa->cfg;
      v294 = thisa->ctfg;
      v295 = thisa->fontmh;
      v296 = 15 * thisa->iconw - thisa->menuw;
      v297 = thisa->iconh / 2 + thisa->menuh + 24 * thisa->iconh - thisa->fontmh - 1;
      v298 = (const __int16 *)(5 * thisa->iconw);
      v300 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 19), v299);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v300, v298, v297, v296, v295, v294, v293, 0, v301);
      Window::setfontheight_((Window *const )thisa->fonth, v302);
      break;
    default:
      break;
  }
  if ( thisa->helpi == -1 )
  {
    Window::setfontheight_((Window *const )thisa->fonth, v355);
    v303 = thisa->okh;
    v304 = thisa->okw;
    v305 = (thisa->okh_ + thisa->okh) / -2 + thisa->abouth + thisa->menuh;
    v306 = (thisa->aboutw - thisa->okw) / 2;
    v307 = GetWin();
    DrawBMP(thisa->pok, v307, v306, v305, v304, v303);
    v308 = thisa->ctbg;
    v309 = thisa->ctfg;
    v310 = thisa->okh;
    v311 = thisa->okw;
    v312 = thisa->abouth + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh;
    v313 = (thisa->aboutw - thisa->okw) / 2;
    v315 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_OK, v314);
    Window::drawtextxy_(
      (Window *const )thisa->pwint,
      (pbitmap)v315,
      (const __int16 *)v313,
      v312,
      v311,
      v310,
      v309,
      v308,
      v375);
  }
  else if ( thisa->helpi )
  {
    Window::setfontheight_((Window *const )thisa->fonth, v355);
    v316 = thisa->okh;
    v317 = thisa->okw;
    v318 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
    v319 = (thisa->helpw - thisa->okw) / 2;
    v320 = GetWin();
    DrawBMP(thisa->pok, v320, v319, v318, v317, v316);
    v321 = thisa->ctbg;
    v322 = thisa->ctfg;
    v323 = thisa->okh;
    v324 = thisa->okw;
    v325 = thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh;
    v326 = (thisa->helpw - thisa->okw) / 2;
    v328 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_OK, v327);
    Window::drawtextxy_(
      (Window *const )thisa->pwint,
      (pbitmap)v328,
      (const __int16 *)v326,
      v325,
      v324,
      v323,
      v322,
      v321,
      v375);
    if ( thisa->helpi > 1 && thisa->helpi <= thisa->maxhelp )
    {
      v329 = thisa->btnh;
      v330 = thisa->btnw;
      v331 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
      v332 = (thisa->helpw - thisa->okw) / 2 - 2 * thisa->btnw;
      v333 = GetWin();
      DrawBMP(thisa->pbtn, v333, v332, v331, v330, v329);
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        (pbitmap)"<",
        (const char *)((thisa->helpw - thisa->okw) / 2 - 2 * thisa->btnw),
        thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh,
        thisa->btnw,
        thisa->btnh,
        thisa->ctfg,
        thisa->ctbg,
        v379);
    }
    if ( thisa->helpi > 0 && thisa->helpi < thisa->maxhelp )
    {
      v334 = thisa->btnh;
      v335 = thisa->btnw;
      v336 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
      v337 = (thisa->helpw + thisa->okw) / 2 + thisa->btnw;
      v338 = GetWin();
      DrawBMP(thisa->pbtn, v338, v337, v336, v335, v334);
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        &stru_4292A8,
        (const char *)((thisa->helpw + thisa->okw) / 2 + thisa->btnw),
        thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh,
        thisa->btnw,
        thisa->btnh,
        thisa->ctfg,
        thisa->ctbg,
        v379);
    }
    v339 = thisa->tuth;
    v340 = thisa->tutw;
    v341 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
    v342 = -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw;
    v343 = GetWin();
    DrawBMP(thisa->pok, v343, v342, v341, v340, v339);
    v344 = thisa->ctbg;
    v345 = thisa->ctfg;
    v346 = thisa->tuth;
    v347 = thisa->tutw;
    v348 = thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh;
    v349 = (const __int16 *)((thisa->helpw - thisa->okw) / 2 - 3 * thisa->btnw - thisa->tutw);
    v351 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_TUT_, v350);
    Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v351, v349, v348, v347, v346, v345, v344, v379);
    Line(0, thisa->menuh, thisa->helpw, 0, thisa->cline);
    Line(0, thisa->helph + thisa->menuh - thisa->okh_, thisa->helpw, 0, thisa->cline);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041D9A2; symbol: __ZN6Window8painttutEv
void __cdecl Window::painttut(Window *const this)
{
  int v1; // ecx
  int i; // ST4C_4
  int j; // ST48_4
  unsigned int cbg; // ST38_4
  unsigned int v5; // edi
  unsigned int v6; // esi
  int v7; // ebx
  bitmap *v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // ST38_4
  unsigned int w; // ST34_4
  int y; // ST30_4
  int v13; // ebx
  int v14; // esi
  int v15; // ST04_4
  __int16 *v16; // eax
  unsigned int v17; // ST38_4
  unsigned int v18; // edi
  unsigned int v19; // esi
  int v20; // ebx
  bitmap *v21; // eax
  unsigned int v22; // edi
  unsigned int v23; // ST38_4
  unsigned int v24; // ST34_4
  int v25; // ST30_4
  int v26; // ebx
  int v27; // esi
  int v28; // ST04_4
  __int16 *v29; // eax
  unsigned int v30; // esi
  unsigned int v31; // ST38_4
  int v32; // ST34_4
  int v33; // edi
  int v34; // ebx
  int v35; // ST04_4
  __int16 *v36; // eax
  unsigned int v37; // ST04_4
  unsigned int v38; // esi
  unsigned int v39; // ST38_4
  int v40; // ST34_4
  int v41; // edi
  int v42; // ebx
  __int16 *v43; // eax
  unsigned int v44; // edi
  unsigned int v45; // esi
  unsigned int v46; // ebx
  bitmap *v47; // eax
  unsigned int v48; // ST38_4
  unsigned int v49; // edi
  unsigned int v50; // esi
  unsigned int v51; // ebx
  bitmap *v52; // eax
  unsigned int v53; // esi
  unsigned int v54; // ST38_4
  unsigned int v55; // ST34_4
  int v56; // edi
  int v57; // ebx
  int v58; // ST04_4
  __int16 *v59; // eax
  unsigned int v60; // ST20_4
  unsigned int v61; // edi
  unsigned int v62; // ST38_4
  unsigned int v63; // ST34_4
  int v64; // ST30_4
  int v65; // ebx
  const __int16 *v66; // esi
  int v67; // ST04_4
  __int16 *v68; // eax
  unsigned int v69; // ST20_4
  unsigned int v70; // [esp+4h] [ebp-64h]
  unsigned int v71; // [esp+4h] [ebp-64h]
  int v72; // [esp+4h] [ebp-64h]
  unsigned int v73; // [esp+20h] [ebp-48h]
  unsigned int v74; // [esp+20h] [ebp-48h]
  unsigned int v75; // [esp+24h] [ebp-44h]
  Window *thisa; // [esp+3Ch] [ebp-2Ch]

  thisa = (Window *)v1;
  Window::setfontheight_(*(Window *const *)(v1 + 112), v70);
  if ( thisa->bd.tuti <= 12 )
  {
    i = *((_DWORD *)&thisa->titlew + thisa->bd.tuti + 760);
    j = *((_DWORD *)&thisa->titleh + thisa->bd.tuti + 772);
    Bar(
      i * thisa->iconw,
      thisa->faceh + thisa->menuh + j * thisa->iconh,
      thisa->iconw - 1,
      thisa->iconh - 1,
      thisa->cred,
      thisa->transparent);
    Bar(
      i * thisa->iconw + 1,
      thisa->menuh + j * thisa->iconh + thisa->faceh + 1,
      thisa->iconw - 3,
      thisa->iconh - 3,
      thisa->cred,
      thisa->transparent);
  }
  switch ( thisa->bd.tuti )
  {
    case 1:
      Bar(
        4 * thisa->iconw - 1,
        thisa->menuh + 15 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        4 * thisa->iconw - 2,
        thisa->menuh + 15 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        3 * (thisa->iconh + 1),
        thisa->cblue,
        thisa->transparent);
      break;
    case 2:
      Bar(
        3 * thisa->iconw - 1,
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 1,
        thisa->iconw + 1,
        thisa->iconh + 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        3 * thisa->iconw - 2,
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 2,
        thisa->iconw + 3,
        thisa->iconh + 3,
        thisa->cblue,
        thisa->transparent);
      break;
    case 3:
      Bar(
        9 * thisa->iconw,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh,
        thisa->iconw - 1,
        2 * thisa->iconh - 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        9 * thisa->iconw + 1,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh + 1,
        thisa->iconw - 3,
        2 * thisa->iconh - 3,
        thisa->cblue,
        thisa->transparent);
      Bar(
        9 * thisa->iconw - 1,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 1,
        thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        9 * thisa->iconw - 2,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 2,
        thisa->iconw + 3,
        3 * (thisa->iconh + 1),
        thisa->cgreen,
        thisa->transparent);
      break;
    case 4:
      Bar(
        7 * thisa->iconw - 1,
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        7 * thisa->iconw - 2,
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        3 * (thisa->iconh + 1),
        thisa->cblue,
        thisa->transparent);
      break;
    case 5:
      Bar(
        9 * thisa->iconw - 1,
        thisa->menuh + 19 * thisa->iconh + thisa->faceh - 1,
        thisa->iconw + 1,
        thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        9 * thisa->iconw - 2,
        thisa->menuh + 19 * thisa->iconh + thisa->faceh - 2,
        thisa->iconw + 3,
        thisa->iconh + 3,
        thisa->cgreen,
        thisa->transparent);
      break;
    case 6:
      Bar(
        8 * thisa->iconw - 1,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        8 * thisa->iconw - 2,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        3 * (thisa->iconh + 1),
        thisa->cgreen,
        thisa->transparent);
      break;
    case 7:
      Bar(
        9 * thisa->iconw - 1,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        9 * thisa->iconw - 2,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        3 * (thisa->iconh + 1),
        thisa->cgreen,
        thisa->transparent);
      break;
    case 8:
      Bar(
        2 * thisa->iconw,
        thisa->faceh + thisa->menuh + 18 * thisa->iconh,
        thisa->iconw - 1,
        2 * thisa->iconh - 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        2 * thisa->iconw + 1,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh + 1,
        thisa->iconw - 3,
        2 * thisa->iconh - 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        2 * thisa->iconw - 1,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 1,
        thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        2 * (thisa->iconw - 1),
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 2,
        thisa->iconw + 3,
        3 * (thisa->iconh + 1),
        thisa->cgreen,
        thisa->transparent);
      break;
    case 0xA:
      Bar(
        2 * thisa->iconw - 1,
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        2 * (thisa->iconw - 1),
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        3 * (thisa->iconh + 1),
        thisa->cgreen,
        thisa->transparent);
      break;
    case 0xB:
      Bar(
        2 * thisa->iconw - 1,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        2 * thisa->iconh + 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        2 * (thisa->iconw - 1),
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        2 * thisa->iconh + 3,
        thisa->cblue,
        thisa->transparent);
      Bar(
        -1,
        thisa->menuh + 6 * thisa->iconh + thisa->faceh - 1,
        12 * thisa->iconw + 1,
        2 * thisa->iconh + 1,
        thisa->cred,
        thisa->transparent);
      Bar(
        -2,
        thisa->menuh + 6 * thisa->iconh + thisa->faceh - 2,
        12 * thisa->iconw + 3,
        2 * thisa->iconh + 3,
        thisa->cred,
        thisa->transparent);
      break;
    case 0xC:
      Bar(
        thisa->iconw - 1,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        2 * thisa->iconh + 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        thisa->iconw - 2,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        2 * thisa->iconh + 3,
        thisa->cblue,
        thisa->transparent);
      break;
    case 0xD:
      Bar(
        -1,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 1,
        12 * thisa->iconw + 1,
        2 * thisa->iconh + 1,
        thisa->cred,
        thisa->transparent);
      Bar(
        -2,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 2,
        12 * thisa->iconw + 3,
        2 * thisa->iconh + 3,
        thisa->cred,
        thisa->transparent);
      Bar(0, thisa->menuh, 4 * thisa->digtw[0], thisa->digth[0], thisa->cred, thisa->transparent);
      Bar(1, thisa->menuh + 1, 4 * thisa->digtw[0] - 2, thisa->digth[0] - 2, thisa->cred, thisa->transparent);
      Bar(
        thisa->w_ - 2 * thisa->digtw[0],
        thisa->menuh,
        2 * thisa->digtw[0],
        thisa->digth[0],
        thisa->cred,
        thisa->transparent);
      Bar(
        thisa->w_ - 2 * thisa->digtw[0] + 1,
        thisa->menuh + 1,
        2 * (thisa->digtw[0] - 1),
        thisa->digth[0] - 2,
        thisa->cred,
        thisa->transparent);
      if ( thisa->bd.tutb <= 1 )
      {
        cbg = thisa->okh;
        v5 = thisa->okw;
        v6 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v7 = (12 * thisa->iconw - thisa->okw) / 2;
        v8 = GetWin();
        DrawBMP(thisa->pok, v8, v7, v6, v5, cbg);
        v9 = thisa->ctbg;
        v10 = thisa->ctfg;
        w = thisa->okh;
        y = thisa->okw;
        v13 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v14 = (12 * thisa->iconw - thisa->okw) / 2;
        v16 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_OK, v15);
        Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v16, (const __int16 *)v14, v13, y, w, v10, v9, v73);
      }
      break;
    case 0xE:
      Bar(
        thisa->w_ - 2 * thisa->digtw[0],
        thisa->menuh,
        2 * thisa->digtw[0],
        thisa->digth[0],
        thisa->cred,
        thisa->transparent);
      Bar(
        thisa->w_ - 2 * thisa->digtw[0] + 1,
        thisa->menuh + 1,
        2 * (thisa->digtw[0] - 1),
        thisa->digth[0] - 2,
        thisa->cred,
        thisa->transparent);
      Bar(
        -1,
        thisa->menuh + 7 * thisa->iconh + thisa->faceh - 1,
        12 * thisa->iconw + 1,
        thisa->iconh + 1,
        thisa->cred,
        thisa->transparent);
      Bar(
        -2,
        thisa->menuh + 7 * thisa->iconh + thisa->faceh - 2,
        12 * thisa->iconw + 3,
        thisa->iconh + 3,
        thisa->cred,
        thisa->transparent);
      if ( thisa->bd.tutb <= 1 )
      {
        v17 = thisa->okh;
        v18 = thisa->okw;
        v19 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v20 = (12 * thisa->iconw - thisa->okw) / 2;
        v21 = GetWin();
        DrawBMP(thisa->pok, v21, v20, v19, v18, v17);
        v22 = thisa->ctbg;
        v23 = thisa->ctfg;
        v24 = thisa->okh;
        v25 = thisa->okw;
        v26 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v27 = (12 * thisa->iconw - thisa->okw) / 2;
        v29 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_OK, v28);
        Window::drawtextxy_(
          (Window *const )thisa->pwint,
          (pbitmap)v29,
          (const __int16 *)v27,
          v26,
          v25,
          v24,
          v23,
          v22,
          v73);
      }
      break;
    default:
      break;
  }
  Window::setfontheight_((Window *const )thisa->fontsh, v71);
  v30 = thisa->cbg;
  v31 = thisa->ctfg;
  v32 = 8 * thisa->fontsh;
  v33 = 12 * thisa->iconw;
  v34 = thisa->menuh + thisa->faceh;
  v36 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.tuti + thisa->bd.st.lan.LAN_TUT), v35);
  Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v36, 0, v34, v33, v32, v31, v30, 0x10u, v75);
  Window::setfontheight_((Window *const )thisa->fonth, v37);
  if ( thisa->bd.tutb == 2 )
  {
    v38 = thisa->cbg;
    v39 = thisa->ctfg;
    v40 = 8 * thisa->fontsh;
    v41 = 12 * thisa->iconw;
    v42 = thisa->menuh + thisa->faceh;
    v43 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_TUT_QUIT, v72);
    Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v43, 0, v42, v41, v40, v39, v38, v74);
    v44 = thisa->okh;
    v45 = 6 * thisa->iconw - 1;
    v46 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v47 = GetWin();
    DrawBMP(thisa->pok, v47, 0, v46, v45, v44);
    v48 = thisa->okh;
    v49 = 6 * thisa->iconw - 1;
    v50 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v51 = 6 * thisa->iconw;
    v52 = GetWin();
    DrawBMP(thisa->pok, v52, v51, v50, v49, v48);
    v53 = thisa->ctbg;
    v54 = thisa->ctfg;
    v55 = thisa->okh;
    v56 = 6 * thisa->iconw - 1;
    v57 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v59 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_TUT_QUIT + 1), v58);
    Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v59, 0, v57, v56, v55, v54, v53, v60);
    v61 = thisa->ctbg;
    v62 = thisa->ctfg;
    v63 = thisa->okh;
    v64 = 6 * thisa->iconw - 1;
    v65 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v66 = (const __int16 *)(6 * thisa->iconw);
    v68 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_TUT_QUIT + 2), v67);
    Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v68, v66, v65, v64, v63, v62, v61, v69);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041F3A8; symbol: __ZN6Window10painttitleEl
void __userpurge Window::painttitle(int a1@<ecx>, Window *const this, int load)
{
  unsigned int c; // ST3C_4
  unsigned int hd; // ST38_4
  unsigned int v5; // edi
  unsigned int v6; // esi
  int v7; // ebx
  bitmap *v8; // eax
  unsigned int v9; // ST04_4
  unsigned int v10; // esi
  unsigned int v11; // ST3C_4
  unsigned int v12; // ST38_4
  int v13; // edi
  int v14; // ebx
  int v15; // ST04_4
  __int16 *v16; // eax
  unsigned int v17; // esi
  unsigned int v18; // ST3C_4
  unsigned int v19; // ST38_4
  int v20; // edi
  int v21; // ebx
  int v22; // ST04_4
  __int16 *v23; // eax
  unsigned int v24; // ST04_4
  unsigned int v25; // ST3C_4
  unsigned int v26; // ST38_4
  unsigned int v27; // edi
  unsigned int v28; // esi
  bitmap *v29; // ebx
  bitmap *v30; // eax
  unsigned int v31; // esi
  unsigned int v32; // ebx
  bitmap *v33; // eax
  unsigned int v34; // edi
  unsigned int v35; // esi
  unsigned int v36; // ebx
  bitmap *v37; // eax
  unsigned int v38; // [esp+4h] [ebp-64h]
  unsigned int v39; // [esp+20h] [ebp-48h]
  unsigned int v40; // [esp+20h] [ebp-48h]
  unsigned int v41; // [esp+20h] [ebp-48h]
  Window *thisa; // [esp+4Ch] [ebp-1Ch]

  thisa = (Window *)a1;
  EnterCriticalSection((LPCRITICAL_SECTION)(a1 + 3560));
  painttitlec = this;
  Clear(thisa->cbg);
  Clear(thisa->pwint, thisa->transparent_);
  if ( (signed int)this < 0 )
    thisa->ptitle_ = LoadBMP("./data/png/title.png");
  c = thisa->cfg;
  hd = thisa->titleh;
  v5 = thisa->titlew;
  v6 = thisa->fontth;
  v7 = (thisa->launchw - thisa->titlew) / 2;
  v8 = GetWin();
  DrawBMP(thisa->ptitle_, v8, v7, v6, v5, hd, c);
  Window::setfontheight_((Window *const )thisa->fontfh, v9);
  v10 = thisa->cbg;
  v11 = thisa->ctfg;
  v12 = thisa->fontfh;
  v13 = thisa->launchw;
  v14 = thisa->fontth - thisa->fontfh;
  v16 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_TITLE, v15);
  Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v16, 0, v14, v13, v12, v11, v10, v39);
  if ( (signed int)this >= 0 )
  {
    Window::setfontheight_((Window *const )thisa->fontfh, v38);
    v17 = thisa->cbg;
    v18 = thisa->ctfg;
    v19 = thisa->fontfh;
    v20 = thisa->launchw;
    v21 = thisa->titleh + thisa->fontth + thisa->fontfh / -2;
    v23 = Lan::getlan((int)&thisa->bd.st, (Lan *const )this, v22);
    Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v23, 0, v21, v20, v19, v18, v17, v40);
    Window::setfontheight_((Window *const )thisa->fonth, v24);
    if ( painttitles )
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        painttitles,
        0,
        thisa->titleh + thisa->fontth + thisa->fontfh / 2,
        thisa->launchw,
        thisa->fontfh,
        thisa->ctfg,
        thisa->cbg,
        v41);
  }
  Window::setfontheight_((Window *const )thisa->fonth, v38);
  if ( thisa->mult > 1.0 )
  {
    v25 = thisa->h_;
    v26 = thisa->w_;
    v27 = thisa->h_;
    v28 = thisa->w_;
    v29 = thisa->pwin;
    v30 = GetWin();
    DrawBMP(v30, v29, 0, 0, v28, v27, 0, 0, v26, v25);
    v31 = (signed __int64)((long double)thisa->h_ * thisa->mult);
    v32 = (signed __int64)((long double)thisa->w_ * thisa->mult);
    v33 = GetWin();
    DrawBMP(thisa->pwin, v33, 0, 0, v32, v31);
  }
  v34 = thisa->transparent_;
  v35 = (signed __int64)((long double)thisa->h_ * thisa->mult);
  v36 = (signed __int64)((long double)thisa->w_ * thisa->mult);
  v37 = GetWin();
  DrawBMP(thisa->pwint, v37, 0, 0, v36, v35, v34);
  FreshWin();
  LeaveCriticalSection((LPCRITICAL_SECTION)&thisa->cs);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041F8C4; symbol: __ZN6Window10painteventEb
void __userpurge Window::paintevent(int a1@<ecx>, Window *const this, bool freshb)
{
  Window *const v3; // ST00_4
  Window *const v4; // ST00_4
  Window *const v5; // ST00_4
  unsigned int hd; // ST34_4
  unsigned int wd; // ST30_4
  unsigned int v8; // edi
  unsigned int v9; // esi
  bitmap *v10; // ebx
  bitmap *v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // ebx
  bitmap *v14; // eax
  unsigned int v15; // edi
  unsigned int v16; // esi
  unsigned int v17; // ebx
  bitmap *v18; // eax
  Window *v19; // [esp+0h] [ebp-68h]
  Window *v20; // [esp+0h] [ebp-68h]
  Window *thisa; // [esp+4Ch] [ebp-1Ch]

  thisa = (Window *)a1;
  EnterCriticalSection((LPCRITICAL_SECTION)(a1 + 3560));
  Clear(thisa->cbg);
  Clear(thisa->pwint, thisa->transparent_);
  Window::paintmenu(v3);
  if ( thisa->helpi )
  {
    Window::painthelp(v19);
  }
  else
  {
    Window::paintface(v19);
    Window::paintlevel(v4);
    Window::paintboard(v5);
    if ( thisa->bd.tutb > 0 && !thisa->bd.pauseb )
      Window::painttut(v20);
  }
  if ( thisa->mult > 1.0 )
  {
    hd = thisa->h_;
    wd = thisa->w_;
    v8 = thisa->h_;
    v9 = thisa->w_;
    v10 = thisa->pwin;
    v11 = GetWin();
    DrawBMP(v11, v10, 0, 0, v9, v8, 0, 0, wd, hd);
    v12 = (signed __int64)((long double)thisa->h_ * thisa->mult);
    v13 = (signed __int64)((long double)thisa->w_ * thisa->mult);
    v14 = GetWin();
    DrawBMP(thisa->pwin, v14, 0, 0, v13, v12);
  }
  v15 = thisa->transparent_;
  v16 = (signed __int64)((long double)thisa->h_ * thisa->mult);
  v17 = (signed __int64)((long double)thisa->w_ * thisa->mult);
  v18 = GetWin();
  DrawBMP(thisa->pwint, v18, 0, 0, v17, v16, v15);
  if ( (_BYTE)this )
    FreshWin();
  LeaveCriticalSection((LPCRITICAL_SECTION)&thisa->cs);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FB7C; symbol: __ZN6Window10painteventEv
void __cdecl Window::paintevent(Window *const this)
{
  int v1; // ecx
  bool v2; // [esp+4h] [ebp-24h]

  Window::paintevent(v1, (Window *const )1, v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FB9C; symbol: __ZN6Window12paintrefreshEv
void __cdecl Window::paintrefresh(Window *const this)
{
  Window *v1; // ecx
  HWND__ *v2; // eax
  HWND__ *v3; // eax
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( GetTimeR() > v1->timerefresh + 0.1 )
  {
    v2 = GetHwnd();
    InvalidateRect(v2, 0, 0);
    v3 = GetHwnd();
    UpdateWindow(v3);
    thisa->timerefresh = GetTimeR();
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FC0A; symbol: __ZN6Window4isinEllllll
BOOL __userpurge Window::isin@<eax>(Window *const this, int ex, int ey, int x, int y, int w, int h)
{
  return (signed int)this > ey && ex > x && ey + y > (signed int)this && x + w > ex;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FC4E; symbol: __ZN6Window7sethelpEl
void __userpurge Window::sethelp(int a1@<ecx>, Window *const this, int helpi_)
{
  Board *v3; // [esp+0h] [ebp-38h]
  int v4; // [esp+4h] [ebp-34h]
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = (Window *)a1;
  *(_BYTE *)(a1 + 3532) = 0;
  if ( *(Window *const *)(a1 + 3376) != this || *(_DWORD *)(a1 + 3376) )
    Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2832), v4);
  if ( thisa->helpi > 0 && (signed int)this > 0 )
    this = (Window *const )thisa->helpi;
  if ( (Window *const )thisa->helpi != this && this )
  {
    if ( !thisa->helpi && thisa->bd.sit > 0 && !thisa->bd.pauseb && thisa->bd.sit <= 3 )
    {
      Board::pause(v3);
      thisa->bd.pauseb = 2;
    }
    thisa->helpi = (int)this;
  }
  else
  {
    if ( thisa->bd.pauseb == 2 && thisa->bd.sit > 0 && thisa->bd.sit <= 3 )
      Board::pause(v3);
    thisa->helpi = 0;
  }
  Window::initwindow(thisa, 0, v4);
  if ( thisa->helpi == -2 && thisa->waitb != 1 )
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)getlead, thisa, 0, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FDE0; symbol: __ZN6Window7savescrEv
void __cdecl Window::savescr(Window *const this)
{
  Window *v1; // ecx
  Window *v2; // ST2C_4
  char *v3; // eax
  char *v4; // eax
  bitmap *v5; // eax
  char *v6; // ST04_4
  int v7; // ST04_4
  char times[260]; // [esp+30h] [ebp-228h]
  time_t rawtime; // [esp+134h] [ebp-124h]
  char scrpath[260]; // [esp+138h] [ebp-120h]
  tm *timed; // [esp+23Ch] [ebp-1Ch]

  v2 = v1;
  GetTempPathA(0x104u, scrpath);
  v3 = &scrpath[strlen(scrpath)];
  *(_DWORD *)v3 = 1701995379;
  *((_DWORD *)v3 + 1) = 1752395365;
  *((_DWORD *)v3 + 2) = 6255727;
  time(&rawtime);
  timed = localtime(&rawtime);
  sprintf(
    times,
    "%d%d%d%d%d%d",
    timed->tm_mday,
    timed->tm_mon + 1,
    timed->tm_year + 1900,
    timed->tm_hour,
    timed->tm_min,
    timed->tm_sec);
  strcat(scrpath, times);
  v4 = &scrpath[strlen(scrpath)];
  *(_DWORD *)v4 = 1735290926;
  v4[4] = 0;
  v5 = GetWin();
  SaveBMP(v5, scrpath);
  Steam::savescr((int)&v2->bd.st, (Steam *const )scrpath, v6);
  Sound::playsound(&v2->bd.sd, (Sound *const )v2->bd.sd.sSolve, v7);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FF6A; symbol: __ZN6Window10switchskinEv
void __cdecl Window::switchskin(Window *const this)
{
  int v1; // ecx
  int v2; // [esp+4h] [ebp-24h]

  Window::switchskin((Window *const )((*(_DWORD *)(v1 + 688) + 1) % 6), v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FFAE; symbol: __ZN6Window10switchskinEl
void __userpurge Window::switchskin(Window *a1@<ecx>, Window *const this, int colori_)
{
  Window *v3; // ST1C_4
  Window *const v4; // ST00_4
  Window *v5; // [esp+0h] [ebp-28h]
  int v6; // [esp+4h] [ebp-24h]

  v3 = a1;
  a1->colori = (int)this;
  Window::initbmp(v5);
  Window::paintevent(v4);
  Sound::playsound(&v3->bd.sd, (Sound *const )v3->bd.sd.sRight, v6);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FFFC; symbol: __ZN6Window8switchmdEv
void __cdecl Window::switchmd(Window *const this)
{
  int v1; // ecx
  unsigned int v2; // eax
  int v3; // [esp+4h] [ebp-24h]

  v2 = (unsigned int)((*(_DWORD *)(v1 + 3516) + 1) >> 31) >> 30;
  Window::switchmd((Window *const )((((_BYTE)v2 + *(_BYTE *)(v1 + 3516) + 1) & 3) - v2), v3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00420038; symbol: __ZN6Window8switchmdEl
void __userpurge Window::switchmd(int a1@<ecx>, Window *const this, int md_)
{
  int v3; // [esp+4h] [ebp-24h]

  *(_DWORD *)(a1 + 3516) = this;
  if ( *(_DWORD *)(a1 + 3516) > 1 )
    *(_DWORD *)(a1 + 3024) = 0;
  Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2832), v3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0042008C; symbol: __ZN6Window8tuteventEllb
void __userpurge Window::tutevent(Window *a1@<ecx>, Window *const this, int ex, int ey, bool tutkb)
{
  int v5; // ST18_4
  int v6; // [esp+4h] [ebp-44h]
  int v7; // [esp+4h] [ebp-44h]
  int v8; // [esp+18h] [ebp-30h]
  int v9; // [esp+18h] [ebp-30h]
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  char tutmb_n; // [esp+3Dh] [ebp-Bh]
  char tutmb_y; // [esp+3Eh] [ebp-Ah]
  char tutmb; // [esp+3Fh] [ebp-9h]

  thisa = a1;
  tutmb = Window::isin(
            this,
            ex,
            (12 * thisa->iconw - thisa->okw) / 2,
            thisa->menuh + 10 * thisa->iconh + thisa->faceh,
            a1->okw,
            a1->okh,
            v8);
  if ( thisa->bd.tutb == 1 && (tutmb || (_BYTE)ey) )
  {
    if ( thisa->bd.tuti == 13 )
    {
      ++thisa->bd.maski;
      ++thisa->bd.tuti;
      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v6);
    }
    else if ( thisa->bd.tuti == 14 )
    {
      thisa->bd.tutb = 0;
      thisa->bd.time = GetTimeR();
      thisa->helpb = 0;
      Window::sethelp((int)thisa, (Window *const )1, v6);
    }
  }
  tutmb_y = Window::isin(
              this,
              ex,
              0,
              thisa->faceh + thisa->menuh + 10 * thisa->iconh,
              6 * thisa->iconw - 1,
              thisa->okh,
              v9);
  tutmb_n = Window::isin(
              this,
              ex,
              6 * thisa->iconw,
              thisa->menuh + 10 * thisa->iconh + thisa->faceh,
              6 * thisa->iconw - 1,
              thisa->okh,
              v5);
  if ( thisa->bd.tutb == 2 && (tutmb_y || tutmb_n || (_BYTE)ey) )
  {
    if ( tutmb_y || (_BYTE)ey )
    {
      thisa->bd.tutb = 0;
      thisa->bd.time = GetTimeR();
      thisa->helpb = 0;
      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v7);
    }
    if ( tutmb_n )
    {
      thisa->bd.tutb = 1;
      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v7);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00420374; symbol: __ZN6Window16mouseeventboard_Ellll
void __userpurge Window::mouseeventboard_(int a1@<ecx>, Window *const this, int x, int y, int eb_, int md_)
{
  bool v6; // al
  Window *v7; // [esp+0h] [ebp-38h]
  Window *v8; // [esp+0h] [ebp-38h]
  bool v9; // [esp+4h] [ebp-34h]
  int v10; // [esp+8h] [ebp-30h]
  int v11; // [esp+10h] [ebp-28h]
  Window *thisa; // [esp+1Ch] [ebp-1Ch]

  thisa = (Window *)a1;
  v6 = !*(_DWORD *)(a1 + 3040)
    || *(_DWORD *)(a1 + 3044) <= 12
    && *(Window *const *)(a1 + 4 * (*(_DWORD *)(a1 + 3044) + 760) + 8) == this
    && *(_DWORD *)(a1 + 4 * (*(_DWORD *)(a1 + 3044) + 772) + 12) == x
    && (y & *(_DWORD *)(a1 + 4 * (*(_DWORD *)(a1 + 3044) + 788))) > 0;
  if ( (*(Window *const *)(a1 + 3524) != this || *(_DWORD *)(a1 + 3528) != x) && v6 && *(_DWORD *)(a1 + 3040) <= 1 )
  {
    *(_DWORD *)(a1 + 3032) = this;
    *(_DWORD *)(a1 + 3036) = x;
    if ( y == 1 )
    {
      if ( !*(_DWORD *)(a1 + 780) && *(_DWORD *)(a1 + 788) <= x && eb_ > 2 )
        Board::resetbd((Board *)(a1 + 768), (Board *const )this, x, v10);
      Board::clickleft(&thisa->bd, (Board *const )this, x, 1, eb_, v11);
    }
    else if ( y == 2 )
    {
      Board::clickright((Board *)(a1 + 768), (Board *const )this, x, 1, eb_, v11);
    }
    Window::paintevent(v7);
    Board::checkline(&thisa->bd, (Board *const )1, v9);
    thisa->mx = (int)this;
    thisa->my = x;
    if ( thisa->bd.tutb > 0 )
      ++thisa->bd.tuti;
    Window::paintevent(v8);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00420566; symbol: __ZN6Window15mouseeventboardEllll
void __userpurge Window::mouseeventboard(int a1@<ecx>, Window *const this, int ex_, int ey_, int eb_, int md_)
{
  bool v6; // [esp+Ch] [ebp-2Ch]
  int v7; // [esp+10h] [ebp-28h]
  Window *thisa; // [esp+1Ch] [ebp-1Ch]
  int y; // [esp+20h] [ebp-18h]
  int x; // [esp+24h] [ebp-14h]
  signed int ey; // [esp+28h] [ebp-10h]
  int ex; // [esp+2Ch] [ebp-Ch]

  thisa = (Window *)a1;
  ex = (signed int)((long double)(signed int)this / *(double *)(a1 + 3408));
  ey = (signed int)((long double)ex_ / *(double *)(a1 + 3408));
  if ( ex >= 0
    && ey - *(_DWORD *)(a1 + 20) >= *(_DWORD *)(a1 + 28)
    && !*(_DWORD *)(a1 + 3376)
    && *(_DWORD *)(a1 + 780) <= 3
    && !*(_DWORD *)(a1 + 784) )
  {
    x = ex / *(_DWORD *)(a1 + 32);
    y = (ey - *(_DWORD *)(a1 + 28) - *(_DWORD *)(a1 + 20)) / *(_DWORD *)(a1 + 36);
    if ( x >= 0 && *(_DWORD *)(a1 + 768) > x && y >= 0 && *(_DWORD *)(a1 + 772) > y )
      Window::mouseeventboard_(a1, (Window *const )x, y, ey_, eb_, v7);
    Window::tutevent(thisa, (Window *const )ex, ey, 0, v6);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004206AE; symbol: __ZN6Window10mouseeventElll
void __userpurge Window::mouseevent(int a1@<ecx>, Window *const this, int ex_, int ey_, int eb_)
{
  bool v5; // ST04_1
  int v6; // ST04_4
  int v7; // ST04_4
  int v8; // ST04_4
  bool v9; // ST04_1
  bool v10; // ST04_1
  bool v11; // ST04_1
  int v12; // ST04_4
  int v13; // ST04_4
  int v14; // eax
  int v15; // ST04_4
  int v16; // eax
  int v17; // ST04_4
  Sound *v18; // [esp+0h] [ebp-68h]
  int v19; // [esp+4h] [ebp-64h]
  int v20; // [esp+4h] [ebp-64h]
  int v21; // [esp+4h] [ebp-64h]
  int v22; // [esp+4h] [ebp-64h]
  int v23; // [esp+4h] [ebp-64h]
  int v24; // [esp+4h] [ebp-64h]
  int v25; // [esp+4h] [ebp-64h]
  int v26; // [esp+4h] [ebp-64h]
  int v27; // [esp+4h] [ebp-64h]
  int v28; // [esp+4h] [ebp-64h]
  int v29; // [esp+4h] [ebp-64h]
  int v30; // [esp+4h] [ebp-64h]
  int v31; // [esp+4h] [ebp-64h]
  int v32; // [esp+4h] [ebp-64h]
  bool v33; // [esp+4h] [ebp-64h]
  bool v34; // [esp+4h] [ebp-64h]
  int v35; // [esp+8h] [ebp-60h]
  int v36; // [esp+8h] [ebp-60h]
  int v37; // [esp+8h] [ebp-60h]
  int v38; // [esp+8h] [ebp-60h]
  int v39; // [esp+10h] [ebp-58h]
  int v40; // [esp+18h] [ebp-50h]
  int v41; // [esp+18h] [ebp-50h]
  int v42; // [esp+18h] [ebp-50h]
  int v43; // [esp+18h] [ebp-50h]
  int v44; // [esp+18h] [ebp-50h]
  int v45; // [esp+18h] [ebp-50h]
  int v46; // [esp+18h] [ebp-50h]
  int v47; // [esp+18h] [ebp-50h]
  Window *thisa; // [esp+2Ch] [ebp-3Ch]
  double helph__; // [esp+38h] [ebp-30h]
  signed int ey; // [esp+40h] [ebp-28h]
  int ex; // [esp+44h] [ebp-24h]
  int j; // [esp+48h] [ebp-20h]
  int k; // [esp+4Ch] [ebp-1Ch]

  thisa = (Window *)a1;
  ex = (signed int)((long double)(signed int)this / *(double *)(a1 + 3408));
  ey = (signed int)((long double)ex_ / *(double *)(a1 + 3408));
  if ( *(_DWORD *)(a1 + 20) <= ey )
  {
    if ( *(_DWORD *)(a1 + 3376) )
    {
      if ( *(_DWORD *)(a1 + 3376) == -1 )
      {
        if ( (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                (*(_DWORD *)(a1 + 88) - *(_DWORD *)(a1 + 64)) / 2,
                                *(_DWORD *)(a1 + 20)
                              + (*(_DWORD *)(a1 + 124) + *(_DWORD *)(a1 + 68)) / -2
                              + *(_DWORD *)(a1 + 92),
                                *(_DWORD *)(a1 + 64),
                                *(_DWORD *)(a1 + 68),
                                v40) )
          Window::sethelp((int)thisa, 0, v20);
        if ( (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                (thisa->aboutw - thisa->fontfh) / 2 + thisa->fontfh / -2,
                                (thisa->fontth - thisa->fontfh) / 2 + thisa->menuh,
                                thisa->fontfh,
                                thisa->fontfh,
                                v41)
          && thisa->cheatb != 1 )
        {
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sSolve, v21);
          thisa->cheatb = 1;
          thisa->bd.st.cheatb = 1;
          Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achhidcheat, v7);
        }
        if ( (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                (thisa->aboutw - thisa->fontfh) / 2 + thisa->fontfh / 2,
                                (thisa->fontth - thisa->fontfh) / 2 + thisa->menuh,
                                thisa->fontfh,
                                thisa->fontfh,
                                v42)
          && thisa->bd.relaxb != 1 )
        {
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sSolve, v22);
          thisa->bd.relaxb = 1;
          thisa->bd.st.cheatb = 1;
          Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achhidcheat, v8);
        }
      }
      else if ( *(_DWORD *)(a1 + 3376) )
      {
        if ( (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                (*(_DWORD *)(a1 + 96) - *(_DWORD *)(a1 + 64)) / 2,
                                *(_DWORD *)(a1 + 20)
                              + (*(_DWORD *)(a1 + 124) + *(_DWORD *)(a1 + 68)) / -2
                              + *(_DWORD *)(a1 + 100),
                                *(_DWORD *)(a1 + 64),
                                *(_DWORD *)(a1 + 68),
                                v40) )
          Window::sethelp((int)thisa, 0, v23);
        if ( (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw,
                                (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                thisa->tutw,
                                thisa->tuth,
                                v43) )
        {
          Window::sethelp((int)thisa, 0, v24);
          Board::initbd((int)&thisa->bd, (Board *const )1, thisa->md, v36);
          Window::initwindow(thisa, 0, v9);
          thisa->bd.tutb = 1;
        }
        if ( thisa->helpi > 1
          && (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                (thisa->helpw - thisa->okw) / 2 - 2 * thisa->btnw,
                                (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                thisa->btnw,
                                thisa->btnh,
                                v44) )
        {
          --thisa->helpi;
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v25);
        }
        if ( thisa->helpi > 0 && thisa->helpi < thisa->maxhelp )
        {
          if ( (unsigned __int8)Window::isin(
                                  (Window *const )ex,
                                  ey,
                                  thisa->btnw + (thisa->helpw + thisa->okw) / 2,
                                  (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                  thisa->btnw,
                                  thisa->btnh,
                                  v44) )
          {
            ++thisa->helpi;
            Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v26);
            if ( thisa->helpi == thisa->maxhelp )
              Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achgenhelp, v27);
          }
        }
        if ( thisa->helpi == -2 )
        {
          if ( (unsigned __int8)Window::isin(
                                  (Window *const )ex,
                                  ey,
                                  ((thisa->helpw + thisa->okw) / 2 + thisa->helpw) / 2
                                + ((signed int)(((unsigned int)(-5 * thisa->facew) >> 31) - 5 * thisa->facew) >> 1),
                                  (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                  5 * thisa->facew,
                                  thisa->faceh,
                                  v44) )
          {
            thisa->lead_5 = (ex
                           - (((thisa->helpw + thisa->okw) / 2 + thisa->helpw) / 2
                            + ((signed int)(((unsigned int)(-5 * thisa->facew) >> 31) - 5 * thisa->facew) >> 1)))
                          / thisa->facew;
            Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v28);
          }
          if ( (unsigned __int8)Window::isin(
                                  (Window *const )ex,
                                  ey,
                                  -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw,
                                  (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                  thisa->tutw,
                                  thisa->tuth,
                                  v45) )
          {
            Window::sethelp((int)thisa, 0, v29);
            Board::initbd((int)&thisa->bd, (Board *const )1, thisa->md, v37);
            Window::initwindow(thisa, 0, v10);
            thisa->bd.tutb = 1;
          }
        }
        if ( thisa->helpi == -3 )
        {
          if ( (unsigned __int8)Window::isin(
                                  (Window *const )ex,
                                  ey,
                                  -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw,
                                  (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                  thisa->tutw,
                                  thisa->tuth,
                                  v44) )
          {
            Window::sethelp((int)thisa, 0, v30);
            Board::initbd((int)&thisa->bd, (Board *const )1, thisa->md, v38);
            Window::initwindow(thisa, 0, v11);
            thisa->bd.tutb = 1;
          }
          helph__ = (long double)(thisa->helph - thisa->okh_ - 2 * thisa->iconh - thisa->faceh) / 9.0;
          for ( k = 0; k <= 9; ++k )
          {
            if ( (unsigned __int8)Window::isin(
                                    (Window *const )ex,
                                    ey,
                                    thisa->iconw,
                                    (signed int)((long double)k * helph__
                                               + (long double)(signed int)thisa->menuh
                                               + (long double)(signed int)thisa->iconh),
                                    thisa->facew,
                                    thisa->faceh,
                                    v46) )
            {
              switch ( k )
              {
                case 0:
                  Sound::switchsound(v18);
                  break;
                case 1:
                  Sound::switchmusic(v18);
                  break;
                case 2:
                  Window::switchmd((Window *const )v18);
                  break;
                case 4:
                  if ( thisa->mult_ )
                    thisa->mult_ = 0;
                  else
                    thisa->mult_ = 1;
                  Window::initwindow(thisa, 0, v31);
                  Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sRight, v12);
                  break;
                case 5:
                  Window::switchskin((Window *const )v18);
                  break;
                case 7:
                  thisa->bd.delayb = thisa->bd.delayb == 0;
                  Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v31);
                  break;
                case 8:
                  thisa->barb ^= 1u;
                  Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v31);
                  break;
                case 9:
                  thisa->singleb ^= 1u;
                  Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v31);
                  break;
                default:
                  break;
              }
            }
            for ( j = 0; j <= 2; ++j )
            {
              if ( (unsigned __int8)Window::isin(
                                      (Window *const )ex,
                                      ey,
                                      (j + 1) * (thisa->helpw / 4),
                                      (signed int)((long double)k * helph__
                                                 + (long double)(signed int)thisa->menuh
                                                 + (long double)(signed int)thisa->iconh),
                                      thisa->facew,
                                      thisa->faceh,
                                      v46) )
              {
                switch ( k )
                {
                  case 0:
                    if ( j <= 1 && thisa->bd.sd.soundb == j )
                      Sound::switchsound(v18);
                    break;
                  case 1:
                    if ( j <= 1 && thisa->bd.sd.musicb == j )
                      Sound::switchmusic(v18);
                    break;
                  case 2:
                    if ( j <= 2 && thisa->md != j )
                      Window::switchmd((int)thisa, (Window *const )j, v32);
                    break;
                  case 3:
                    if ( j <= 2 && thisa->md != j + 2 )
                      Window::switchmd((int)thisa, (Window *const )(j + 2), v32);
                    break;
                  case 4:
                    if ( thisa->mult_ != j )
                    {
                      thisa->mult_ = j;
                      Window::initwindow(thisa, 0, v32);
                      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sRight, v13);
                    }
                    break;
                  case 5:
                    if ( j <= 2 && thisa->colori != j )
                      Window::switchskin(thisa, (Window *const )j, v32);
                    break;
                  case 6:
                    if ( j <= 2 && thisa->colori != j + 3 )
                      Window::switchskin(thisa, (Window *const )(j + 3), v32);
                    break;
                  case 7:
                    if ( j <= 1 && thisa->bd.delayb == j )
                    {
                      thisa->bd.delayb = thisa->bd.delayb == 0;
                      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v32);
                    }
                    break;
                  case 8:
                    if ( j <= 1 && thisa->barb == j )
                    {
                      thisa->barb ^= 1u;
                      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v32);
                    }
                    break;
                  case 9:
                    if ( j <= 1 && thisa->singleb != j )
                    {
                      thisa->singleb ^= 1u;
                      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v32);
                    }
                    break;
                  default:
                    continue;
                }
              }
            }
          }
          if ( thisa->mult_ > 1 )
          {
            if ( (unsigned __int8)Window::isin(
                                    (Window *const )ex,
                                    ey,
                                    thisa->facew + 3 * (thisa->helpw / 4),
                                    (signed int)(helph__ * 4.0
                                               + (long double)(signed int)thisa->menuh
                                               + (long double)(signed int)thisa->iconh),
                                    thisa->facew,
                                    thisa->faceh,
                                    v46) )
            {
              v14 = thisa->mult_ - 1;
              if ( v14 < 2 )
                v14 = 2;
              thisa->mult_ = v14;
              Window::initwindow(thisa, 0, v33);
              Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sRight, v15);
            }
            if ( (unsigned __int8)Window::isin(
                                    (Window *const )ex,
                                    ey,
                                    2 * thisa->facew + 3 * (thisa->helpw / 4),
                                    (signed int)(helph__ * 4.0
                                               + (long double)(signed int)thisa->menuh
                                               + (long double)(signed int)thisa->iconh),
                                    thisa->facew,
                                    thisa->faceh,
                                    v47) )
            {
              v16 = thisa->mult_ + 1;
              if ( v16 > 8 )
                v16 = 8;
              thisa->mult_ = v16;
              Window::initwindow(thisa, 0, v34);
              Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sRight, v17);
            }
          }
        }
      }
    }
    else if ( ey - *(_DWORD *)(a1 + 20) >= *(_DWORD *)(a1 + 28) )
    {
      if ( *(_DWORD *)(a1 + 780) <= 3 && !*(_DWORD *)(a1 + 784) )
        Window::mouseeventboard(a1, this, ex_, ey_, *(_DWORD *)(a1 + 3516) + 4, v39);
    }
    else if ( (*(_DWORD *)(a1 + 3464) - *(_DWORD *)(a1 + 24)) / 2 < ex
           && (*(_DWORD *)(a1 + 3464) + *(_DWORD *)(a1 + 24)) / 2 > ex )
    {
      if ( ey_ == 1 )
      {
        if ( *(_DWORD *)(a1 + 3040) <= 0 )
        {
          Board::initbd((Board *const )v18);
        }
        else
        {
          *(_DWORD *)(a1 + 3040) = 2;
          Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v19);
        }
      }
      else if ( ey_ == 2 && *(_DWORD *)(a1 + 780) > 0 && *(_DWORD *)(a1 + 780) <= 3 )
      {
        Board::pause((Board *const )v18);
        Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sSolve, v19);
        Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achgenpause, v6);
      }
    }
  }
  else if ( 3 * *(_DWORD *)(a1 + 16) <= ex )
  {
    if ( *(_DWORD *)(a1 + 3464) - 5 * *(_DWORD *)(a1 + 16) < ex )
    {
      switch ( (ex - (*(_DWORD *)(a1 + 3464) - 5 * *(_DWORD *)(a1 + 16))) / *(_DWORD *)(a1 + 16) )
      {
        case 0:
          Window::savescr((Window *const )v18);
          break;
        case 1:
          Window::sethelp(a1, (Window *const )0xFFFFFFFE, v19);
          break;
        case 2:
          Window::sethelp(a1, (Window *const )0xFFFFFFFD, v19);
          break;
        case 3:
          Window::sethelp(a1, (Window *const )1, v19);
          break;
        case 4:
          Window::sethelp(a1, (Window *const )0xFFFFFFFF, v19);
          break;
        default:
          break;
      }
    }
  }
  else if ( *(_DWORD *)(a1 + 3040) <= 0 )
  {
    *(_DWORD *)(a1 + 3376) = 0;
    Board::initbd(a1 + 768, (Board *const )(ex / *(_DWORD *)(a1 + 16) + 1), *(_DWORD *)(a1 + 3516), v35);
    Window::initwindow(thisa, 0, v5);
  }
  else
  {
    *(_DWORD *)(a1 + 3040) = 2;
    Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v19);
  }
  Window::paintevent((Window *const )v18);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00421B48; symbol: __ZN6Window8keyeventEl
void __userpurge Window::keyevent(int a1@<ecx>, Window *const this, int key)
{
  bool v3; // ST04_1
  bool v4; // ST04_1
  bool v5; // ST04_1
  int v6; // ST04_4
  int v7; // eax
  signed int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  Window *const v12; // ST00_4
  bool v13; // ST04_1
  Board *const v14; // ST00_4
  Window *v15; // [esp+0h] [ebp-28h]
  int v16; // [esp+4h] [ebp-24h]
  int v17; // [esp+4h] [ebp-24h]
  int v18; // [esp+8h] [ebp-20h]
  bool v19; // [esp+Ch] [ebp-1Ch]
  int v20; // [esp+10h] [ebp-18h]
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = (Window *)a1;
  switch ( (unsigned int)this )
  {
    case 0x31u:
      if ( *(_DWORD *)(a1 + 3040) <= 0 )
      {
        *(_DWORD *)(a1 + 3376) = 0;
        Board::initbd(a1 + 768, (Board *const )1, *(_DWORD *)(a1 + 3516), v18);
        Window::initwindow(thisa, 0, v3);
      }
      else
      {
        *(_DWORD *)(a1 + 3040) = 2;
        Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v16);
      }
      break;
    case 0x32u:
      if ( *(_DWORD *)(a1 + 3040) <= 0 )
      {
        *(_DWORD *)(a1 + 3376) = 0;
        Board::initbd(a1 + 768, (Board *const )2, *(_DWORD *)(a1 + 3516), v18);
        Window::initwindow(thisa, 0, v4);
      }
      else
      {
        *(_DWORD *)(a1 + 3040) = 2;
        Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v16);
      }
      break;
    case 0x33u:
      if ( *(_DWORD *)(a1 + 3040) <= 0 )
      {
        *(_DWORD *)(a1 + 3376) = 0;
        Board::initbd(a1 + 768, (Board *const )3, *(_DWORD *)(a1 + 3516), v18);
        Window::initwindow(thisa, 0, v5);
      }
      else
      {
        *(_DWORD *)(a1 + 3040) = 2;
        Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v16);
      }
      break;
    case 0x42u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFF, v16);
      break;
    case 0x45u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFD, v16);
      break;
    case 0x47u:
      Window::switchmd(v15);
      break;
    case 0x48u:
      Window::sethelp(a1, (Window *const )1, v16);
      break;
    case 0x4Bu:
      Window::switchskin(v15);
      break;
    case 0x4Du:
      Sound::switchmusic((Sound *const )v15);
      break;
    case 0x4Eu:
      if ( *(_DWORD *)(a1 + 3040) <= 0 )
      {
        *(_DWORD *)(a1 + 3376) = 0;
        Board::initbd((Board *const )v15);
        Window::initwindow(thisa, 0, v16);
      }
      else
      {
        *(_DWORD *)(a1 + 3040) = 2;
        Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v16);
      }
      break;
    case 0x50u:
      Window::savescr(v15);
      break;
    case 0x52u:
      *(_BYTE *)(a1 + 3540) ^= 1u;
      Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2832), v16);
      break;
    case 0x53u:
      Sound::switchsound((Sound *const )v15);
      break;
    case 0x54u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFE, v16);
      break;
    case 0x70u:
      Window::sethelp(a1, (Window *const )1, v16);
      break;
    case 0x71u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFF, v16);
      break;
    case 0x72u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFD, v16);
      break;
    case 0x73u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFE, v16);
      break;
    case 0x74u:
      Sound::switchsound((Sound *const )v15);
      break;
    case 0x75u:
      Sound::switchmusic((Sound *const )v15);
      break;
    case 0x76u:
      Window::switchmd(v15);
      break;
    case 0x77u:
      *(_BYTE *)(a1 + 3540) ^= 1u;
      Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2832), v16);
      break;
    case 0x7Au:
      Window::switchskin(v15);
      break;
    case 0x7Bu:
      Window::savescr(v15);
      break;
    default:
      break;
  }
  if ( thisa->cheatb && this == (Window *const )67 )
    Steam::resetach((Steam *const )v15);
  if ( thisa->helpi == -2 && this == (Window *const )9 )
  {
    thisa->lead_5 = (thisa->lead_5 + 1) % 5;
    Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v16);
  }
  if ( thisa->helpi )
  {
    if ( this == (Window *const )13
      || this == (Window *const )32
      || this == (Window *const )27
      || this == (Window *const )81 )
    {
      Window::sethelp((int)thisa, 0, v16);
    }
    if ( thisa->helpi > 0 )
    {
      if ( this == (Window *const )37 && thisa->helpi > 1 )
      {
        --thisa->helpi;
        Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v16);
      }
      if ( this == (Window *const )39 && thisa->helpi < thisa->maxhelp )
      {
        ++thisa->helpi;
        Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v16);
        if ( thisa->helpi == thisa->maxhelp )
          Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achgenhelp, v17);
      }
    }
  }
  else
  {
    if ( thisa->bd.mx == -1
      && thisa->bd.my == -1
      && (this == (Window *const )65
       || this == (Window *const )68
       || this == (Window *const )87
       || this == (Window *const )83
       || this == (Window *const )188
       || this == (Window *const )190) )
    {
      thisa->bd.mx = thisa->bd.w / 2;
      thisa->bd.my = thisa->bd.h - 3;
    }
    switch ( (unsigned int)this )
    {
      case 0x1Bu:
        CloseWin();
        break;
      case 0x20u:
        if ( thisa->bd.sit > 0 && thisa->bd.sit <= 3 )
        {
          Board::pause((Board *const )v15);
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sSolve, v16);
          Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achgenpause, v6);
        }
        break;
      case 0x21u:
        v7 = thisa->bd.maskj0;
        if ( v7 > thisa->bd.h - 4 )
          v7 = thisa->bd.h - 4;
        thisa->bd.maskj0 = v7;
        v8 = --thisa->bd.maskj0;
        if ( v8 <= 0 )
          v8 = 1;
        thisa->bd.maskj0 = v8;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x22u:
        v9 = ++thisa->bd.maskj0;
        if ( v9 > thisa->bd.h - 4 )
          v9 = thisa->bd.h - 4;
        thisa->bd.maskj0 = v9;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x25u:
        --thisa->bd.w;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x26u:
        --thisa->bd.h;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x27u:
        ++thisa->bd.w;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x28u:
        ++thisa->bd.h;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x41u:
        --thisa->bd.mx;
        thisa->bd.mx &= ~(thisa->bd.mx >> 31);
        break;
      case 0x44u:
        v10 = ++thisa->bd.mx;
        if ( v10 > thisa->bd.w - 1 )
          v10 = thisa->bd.w - 1;
        thisa->bd.mx = v10;
        break;
      case 0x51u:
        CloseWin();
        break;
      case 0x53u:
        v11 = ++thisa->bd.my;
        if ( v11 > thisa->bd.h - 1 )
          v11 = thisa->bd.h - 1;
        thisa->bd.my = v11;
        break;
      case 0x55u:
        if ( !thisa->bd.tutb )
        {
          Board::addline((Board *const )v15);
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v16);
          Window::paintevent(v12);
          Board::checkline(&thisa->bd, (Board *const )1, v13);
          Board::checkdie(v14);
        }
        break;
      case 0x57u:
        --thisa->bd.my;
        thisa->bd.my &= ~(thisa->bd.my >> 31);
        break;
      case 0x6Bu:
        ++thisa->bd.n;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x6Du:
        --thisa->bd.n;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0xBBu:
        ++thisa->bd.n;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0xBCu:
        thisa->mx = -1;
        thisa->my = -1;
        Window::tutevent(thisa, 0, 0, 1, v19);
        Window::mouseeventboard_((int)thisa, (Window *const )thisa->bd.mx, thisa->bd.my, 1, thisa->md + 4, v20);
        break;
      case 0xBDu:
        --thisa->bd.n;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0xBEu:
        thisa->mx = -1;
        thisa->my = -1;
        Window::tutevent(thisa, 0, 0, 1, v19);
        Window::mouseeventboard_((int)thisa, (Window *const )thisa->bd.mx, thisa->bd.my, 2, thisa->md + 4, v20);
        break;
      default:
        break;
    }
    if ( thisa->cheatb )
    {
      switch ( (unsigned int)this )
      {
        case 0x30u:
          Board::delline(&thisa->bd, (Board *const )(thisa->bd.h - 1), v16);
          break;
        case 0x34u:
          Board::solve1((Board *const )v15);
          break;
        case 0x35u:
          Board::solve2((Board *const )v15);
          break;
        case 0x36u:
          Board::solve1_((Board *const )v15);
          break;
        case 0x37u:
          Board::solve2_((Board *const )v15);
          break;
        case 0x38u:
          Board::solve3_((Board *const )v15);
          break;
        case 0x39u:
          Board::solveblank_((Board *const )v15);
          break;
        case 0x56u:
          ++thisa->bd.level;
          break;
        default:
          break;
      }
      if ( (signed int)this > 51 || (signed int)this <= 48 )
      {
        Window::paintevent(v15);
        Board::checkline(&thisa->bd, (Board *const )1, v16);
      }
    }
  }
  Window::paintevent(v15);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004227C6; symbol: __ZN6Window8doactionEv
void __cdecl Window::doaction(Window *const this)
{
  Window *v1; // ecx
  int v2; // ebx
  Window *v3; // eax
  int v4; // ebx
  Window *v5; // eax
  bool v6; // al
  int v7; // ebx
  int v8; // esi
  Window *v9; // eax
  int v10; // ebx
  int v11; // esi
  Window *v12; // eax
  Window *v13; // eax
  bool v14; // al
  HWND__ *v15; // eax
  HWND__ *v16; // eax
  double v17; // ST18_8
  double v18; // ST18_8
  bool v19; // al
  HWND__ *v20; // eax
  bool v21; // ST04_1
  int v22; // ST04_4
  Window *v23; // [esp+0h] [ebp-38h]
  int v24; // [esp+4h] [ebp-34h]
  int v25; // [esp+Ch] [ebp-2Ch]
  signed __int64 v26; // [esp+10h] [ebp-28h]
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  while ( (unsigned __int8)IsNextMsg() )
  {
    if ( !thisa->bd.delayb__ )
    {
      thisa->ml = GetAsyncKeyState(1) != 0;
      thisa->mr = GetAsyncKeyState(2) != 0;
      if ( IsMouseLeft() )
      {
        thisa->mi = 1;
        thisa->mx = -1;
        thisa->my = -1;
        v2 = GetMousePosY();
        v3 = (Window *)GetMousePosX();
        Window::mouseevent((int)thisa, v3, v2, 1, v25);
      }
      if ( IsMouseRight() )
      {
        thisa->mi = 1;
        thisa->mx = -1;
        thisa->my = -1;
        v4 = GetMousePosY();
        v5 = (Window *)GetMousePosX();
        Window::mouseevent((int)thisa, v5, v4, 2, v25);
      }
      v6 = IsMouseMove() && thisa->md > 1 && !thisa->bd.tutb && thisa->mi;
      if ( v6 )
      {
        if ( thisa->ml )
        {
          v7 = thisa->md;
          v8 = GetMousePosY();
          v9 = (Window *)GetMousePosX();
          Window::mouseeventboard((int)thisa, v9, v8, 1, v7, v26);
        }
        if ( thisa->mr )
        {
          v10 = thisa->md;
          v11 = GetMousePosY();
          v12 = (Window *)GetMousePosX();
          Window::mouseeventboard((int)thisa, v12, v11, 2, v10, v26);
        }
      }
      if ( IsKey() )
      {
        v13 = (Window *)GetKey();
        Window::keyevent((int)thisa, v13, v24);
      }
      v14 = IsMsg(0xFu) || IsMsg(0xA1u) || IsMsg(0x112u);
      if ( v14 )
      {
        v15 = GetHwnd();
        thisa->showmax = IsZoomed(v15) != 0;
        v16 = GetHwnd();
        v19 = 0;
        if ( !IsIconic(v16) )
        {
          if ( thisa->showmax != thisa->showmax_
            || ((v17 = (long double)thisa->w_ * thisa->mult, v26 = GetWidth(), fabs(v17 - (double)v26) > 1.0)
             || (v18 = (long double)thisa->h_ * thisa->mult, v26 = GetHeight(), fabs(v18 - (double)v26) > 1.0))
            && IsMsg(0xA1u) )
          {
            v19 = 1;
          }
        }
        if ( v19 )
        {
          v20 = GetHwnd();
          ShowWindow(v20, 9);
          thisa->mult_ = thisa->showmax;
          Window::initwindow(thisa, 0, v21);
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sRight, v22);
          thisa->showmax = 0;
          thisa->showmax_ = thisa->showmax;
        }
        Window::paintevent(v23);
      }
    }
  }
  thisa->bd.delayb__ = 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422BA8; symbol: __ZN6Window12setfontname_EPKc
void __userpurge Window::setfontname_(Window *a1@<ecx>, Window *const this, const char *s)
{
  Window *v3; // ST1C_4

  v3 = a1;
  SetFontName((const char *)this);
  SetFont(v3->pwint);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422BD2; symbol: __ZN6Window14setfontheight_Em
void __userpurge Window::setfontheight_(Window *a1@<ecx>, Window *const this, unsigned int h)
{
  Window *v3; // ST2C_4

  v3 = a1;
  SetFontHeight((signed __int64)((double)(unsigned int)this * a1->mult));
  SetFont(v3->pwint);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422C38; symbol: __ZN6Window14setfontweight_Em
void __userpurge Window::setfontweight_(Window *a1@<ecx>, Window *const this, unsigned int wg)
{
  Window *v3; // ST1C_4

  v3 = a1;
  SetFontWeight((unsigned int)this);
  SetFont(v3->pwint);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422C62; symbol: __ZN6Window11drawtextxy_EP6bitmapPKsllmmmmm
void __userpurge Window::drawtextxy_(int a1@<ecx>, Window *const this, pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int format)
{
  signed __int64 v11; // ST10_8

  v11 = __PAIR__(
          (signed __int64)((double)w * *(double *)(a1 + 3408)),
          (unsigned int)(signed __int64)((double)(unsigned int)y * *(double *)(a1 + 3408)));
  DrawTextXY(
    (pbitmap)this,
    (const __int16 *)b,
    (signed int)((long double)(signed int)s * *(double *)(a1 + 3408)),
    (signed int)((long double)x * *(double *)(a1 + 3408)),
    v11,
    HIDWORD(v11),
    h,
    cfg,
    cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422D56; symbol: __ZN6Window11drawtextxy_EP6bitmapPKsllmmmm
void __userpurge Window::drawtextxy_(int a1@<ecx>, Window *const this, pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  signed __int64 v10; // ST10_8

  v10 = __PAIR__(
          (signed __int64)((double)w * *(double *)(a1 + 3408)),
          (unsigned int)(signed __int64)((double)(unsigned int)y * *(double *)(a1 + 3408)));
  DrawTextXY(
    (pbitmap)this,
    (const __int16 *)b,
    (signed int)((long double)(signed int)s * *(double *)(a1 + 3408)),
    (signed int)((long double)x * *(double *)(a1 + 3408)),
    v10,
    HIDWORD(v10),
    h,
    cfg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422E42; symbol: __ZN6Window11drawtextxy_EP6bitmapPKcllmmmm
void __userpurge Window::drawtextxy_(int a1@<ecx>, Window *const this, pbitmap b, const char *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  signed __int64 v10; // ST10_8

  v10 = __PAIR__(
          (signed __int64)((double)w * *(double *)(a1 + 3408)),
          (unsigned int)(signed __int64)((double)(unsigned int)y * *(double *)(a1 + 3408)));
  DrawTextXY(
    (pbitmap)this,
    (const char *)b,
    (signed int)((long double)(signed int)s * *(double *)(a1 + 3408)),
    (signed int)((long double)x * *(double *)(a1 + 3408)),
    v10,
    HIDWORD(v10),
    h,
    cfg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422F2E; symbol: __ZN6Window11drawtextxy_EP6bitmapPKcllmm
void __userpurge Window::drawtextxy_(int a1@<ecx>, Window *const this, pbitmap b, const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(
    (pbitmap)this,
    (const char *)b,
    (signed int)((long double)(signed int)s * *(double *)(a1 + 3408)),
    (signed int)((long double)x * *(double *)(a1 + 3408)),
    y,
    cfg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422FA6; symbol: __ZN6Window15getstringwidth_EPKc
signed __int64 __userpurge Window::getstringwidth_@<edx:eax>(int a1@<ecx>, Window *const this, const char *s)
{
  return (signed __int64)((double)GetStringWidth((const char *)this) / *(double *)(a1 + 3408));
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00422FF8; symbol: _WinMain@16
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  bool v4; // al
  __int16 *v5; // ebx
  int v6; // ST04_4
  __int16 *v7; // eax
  Window *const v8; // ST00_4
  Window *const v9; // ST00_4
  Board *const v10; // ST00_4
  Window *const v11; // ST00_4
  Window *const v12; // ST00_4
  Lan *v14; // [esp+0h] [ebp-F78h]
  Window *v15; // [esp+0h] [ebp-F78h]
  Window *v16; // [esp+0h] [ebp-F78h]
  int v17; // [esp+4h] [ebp-F74h]
  Window w; // [esp+168h] [ebp-E10h]
  HANDLE hMutex; // [esp+F6Ch] [ebp-Ch]

  MainInstance = hInstance;
  hMutex = CreateMutexA(0, 1, "MineSweeperRushMutex");
  v4 = GetLastError() == 183 || FindWindowA("MineSweeperRushClass", 0);
  if ( v4 )
  {
    Lan::Lan(v14);
    v5 = Lan::getlan((int)&w, (Lan *const )w.pmenug[1][0], v17);
    v7 = Lan::getlan((int)&w, (Lan *const )w.pmenug[1][1], v6);
    MsgBoxW(v7, v5, 0x40u);
  }
  else
  {
    CheckAndProcessCabFile();
    Lan::Lan(v14);
    Window::Window(v8);
    Window::loadall(v9);
    while ( (unsigned __int8)IsWin() )
    {
      Window::doaction(v15);
      if ( Board::addmask(v10) )
      {
        Window::paintevent(v16);
        Window::paintrefresh(v11);
      }
      Sound::checkmusic((Sound *const )v16);
      Delay(1u);
    }
    ReleaseMutex(hMutex);
    Window::~Window(v12);
  }
  CloseHandle(hMutex);
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425990; symbol: _UpdateWindow@4
BOOL __stdcall UpdateWindow(HWND hWnd)
{
  return UpdateWindow(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259A8; symbol: _ShowWindow@8
BOOL __stdcall ShowWindow(HWND hWnd, int nCmdShow)
{
  return ShowWindow(hWnd, nCmdShow);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259B0; symbol: _SetWindowTextW@8
BOOL __stdcall SetWindowTextW(HWND hWnd, LPCWSTR lpString)
{
  return SetWindowTextW(hWnd, lpString);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259B8; symbol: _SetWindowTextA@8
BOOL __stdcall SetWindowTextA(HWND hWnd, LPCSTR lpString)
{
  return SetWindowTextA(hWnd, lpString);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259C0; symbol: _SetWindowLongA@12
LONG __stdcall SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong)
{
  return SetWindowLongA(hWnd, nIndex, dwNewLong);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259F0; symbol: _MoveWindow@24
BOOL __stdcall MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint)
{
  return MoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A30; symbol: _GetWindowTextW@12
int __stdcall GetWindowTextW(HWND hWnd, LPWSTR lpString, int nMaxCount)
{
  return GetWindowTextW(hWnd, lpString, nMaxCount);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A38; symbol: _GetWindowTextA@12
int __stdcall GetWindowTextA(HWND hWnd, LPSTR lpString, int nMaxCount)
{
  return GetWindowTextA(hWnd, lpString, nMaxCount);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A40; symbol: _GetWindowRect@8
BOOL __stdcall GetWindowRect(HWND hWnd, LPRECT lpRect)
{
  return GetWindowRect(hWnd, lpRect);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A60; symbol: _GetDesktopWindow@0
HWND __stdcall GetDesktopWindow()
{
  return GetDesktopWindow();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A88; symbol: _FindWindowA@8
HWND __stdcall FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName)
{
  return FindWindowA(lpClassName, lpWindowName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AB8; symbol: _DestroyWindow@4
BOOL __stdcall DestroyWindow(HWND hWnd)
{
  return DestroyWindow(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AC0; symbol: _DefWindowProcW@16
LRESULT __stdcall DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcW(hWnd, Msg, wParam, lParam);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：创建窗口。
// Address: 0x00425AC8; symbol: _CreateWindowExW@48
HWND __stdcall CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
  return CreateWindowExW(
           dwExStyle,
           lpClassName,
           lpWindowName,
           dwStyle,
           X,
           Y,
           nWidth,
           nHeight,
           hWndParent,
           hMenu,
           hInstance,
           lpParam);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AD0; symbol: _AdjustWindowRect@12
BOOL __stdcall AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu)
{
  return AdjustWindowRect(lpRect, dwStyle, bMenu);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00401340; symbol: ___gcc_register_frame
int __gcc_register_frame()
{
  HMODULE v0; // eax
  HINSTANCE__ *v1; // ebx
  FARPROC v2; // esi
  HINSTANCE__ *v3; // eax
  FARPROC v4; // edx

  v0 = GetModuleHandleA("libgcc_s_dw2-1.dll");
  if ( v0 )
  {
    v1 = v0;
    hmod_libgcc = LoadLibraryA("libgcc_s_dw2-1.dll");
    v2 = GetProcAddress(v1, "__register_frame_info");
    _data_start__ = (int)GetProcAddress(v1, "__deregister_frame_info");
  }
  else
  {
    _data_start__ = 0;
    v2 = 0;
  }
  if ( v2 )
    ((void (__cdecl *)(void *, void *))v2)(&__EH_FRAME_BEGIN__, &obj);
  if ( __JCR_END__ )
  {
    v3 = GetModuleHandleA("libgcj-16.dll");
    v4 = 0;
    if ( v3 )
      v4 = GetProcAddress(v3, "_Jv_RegisterClasses");
    if ( v4 )
      ((void (__cdecl *)(int *))v4)(&__JCR_END__);
  }
  return atexit(__gcc_deregister_frame);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00401430; symbol: ___gcc_deregister_frame
void __cdecl __gcc_deregister_frame()
{
  if ( _data_start__ )
    _data_start__(&__EH_FRAME_BEGIN__);
  if ( hmod_libgcc )
    FreeLibrary(hmod_libgcc);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405E78; symbol: __Z11WinRegisterv
ATOM WinRegister()
{
  _wc.style = 3;
  _wc.lpfnWndProc = (WNDPROC)WndProc;
  _wc.cbClsExtra = 0;
  _wc.cbWndExtra = 0;
  _wc.hInstance = MainInstance;
  _wc.hbrBackground = CreateSolidBrush(_cbg);
  _wc.lpszMenuName = 0;
  _wc.lpszClassName = _class;
  return RegisterClassW(&_wc);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00407D88; symbol: __Z7LoadBMPPKcm
pbitmap __cdecl LoadBMP(const char *s, unsigned int c)
{
  float v2; // ST2C_4
  long double v3; // fst7
  float v4; // ST2C_4
  float v5; // ST14_4
  UINT bh_0; // [esp+34h] [ebp-14h]
  UINT bw; // [esp+38h] [ebp-10h]
  pbitmap bmp; // [esp+3Ch] [ebp-Ch]

  if ( !c )
    c = GetBGColor();
  MultiByteToWideChar(0, 0, s, -1, _GdiWideChar, 127);
  GdiplusStartup(&_GdiToken, &_GdiStart, 0);
  GdipLoadImageFromFile(_GdiWideChar, &_GdiImage);
  GdipGetImageWidth(_GdiImage, &bw);
  GdipGetImageHeight(_GdiImage, &bh_0);
  bmp = CreateBMP(bw, bh_0, c);
  GdipCreateFromHDC(bmp->DC, &_GdiGraph);
  v2 = (long double)bh_0;
  v3 = v2;
  v4 = (long double)bw;
  v5 = v3;
  GdipDrawImageRect(_GdiGraph, _GdiImage, 0.0, 0.0, LODWORD(v4), LODWORD(v5));
  GdipDisposeImage(_GdiImage);
  GdipDeleteGraphics(_GdiGraph);
  GdiplusShutdown(_GdiToken);
  return bmp;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407EFC; symbol: __Z7LoadBMPPKc
pbitmap __cdecl LoadBMP(const char *s)
{
  return LoadBMP(s, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00407F17; symbol: __Z7SaveBMPP6bitmapPKc
void __cdecl SaveBMP(pbitmap b, const char *s)
{
  MultiByteToWideChar(0, 0, s, -1, _GdiWideChar, 127);
  GdiplusStartup(&_GdiToken, &_GdiStart, 0);
  GdipCreateBitmapFromHBITMAP(b->Handle, 0, &_GdiBitmap);
  GdipSaveImageToFile(_GdiBitmap, _GdiWideChar, &GDIImageFormatPNG, 0);
  GdipDisposeImage(_GdiBitmap);
  GdiplusShutdown(_GdiToken);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040918E; symbol: __Z9LoadAudioPKcS0_
unsigned int __cdecl LoadAudio(const char *s1, const char *s2)
{
  sprintf(command_in, "open \"%s\"%s alias s%lu", s1, s2, ++_cid);
  SendString();
  return _cid;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004091D8; symbol: __Z9LoadAudioPKc
unsigned int __cdecl LoadAudio(const char *s)
{
  return LoadAudio(s, ::s);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040C264; symbol: __ZL18loadallpaintstaticPv@4
DWORD __stdcall loadallpaintstatic(LPVOID lpParam)
{
  Window *v2; // [esp+0h] [ebp-18h]

  Window::loadallpaint(v2);
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231AC; symbol: _GdipSaveImageToFile@16
int __stdcall GdipSaveImageToFile(int a1, int a2, int a3, int a4)
{
  return GdipSaveImageToFile(a1, a2, a3, a4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004231B4; symbol: _GdipLoadImageFromFile@8
int __stdcall GdipLoadImageFromFile(int a1, int a2)
{
  return GdipLoadImageFromFile(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004238E0; symbol: ___tlregdtor
int __tlregdtor()
{
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：写入注册表值。
// Address: 0x00425968; symbol: _RegSetValueExA@24
LONG __stdcall RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData)
{
  return RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：读取注册表值。
// Address: 0x00425970; symbol: _RegQueryValueExA@24
LONG __stdcall RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
  return RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425978; symbol: _RegCreateKeyExA@36
LONG __stdcall RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition)
{
  return RegCreateKeyExA(
           hKey,
           lpSubKey,
           Reserved,
           lpClass,
           dwOptions,
           samDesired,
           lpSecurityAttributes,
           phkResult,
           lpdwDisposition);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425980; symbol: _RegCloseKey@4
LONG __stdcall RegCloseKey(HKEY hKey)
{
  return _IAT_start__(hKey);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259C8; symbol: _SetForegroundWindow@4
BOOL __stdcall SetForegroundWindow(HWND hWnd)
{
  return SetForegroundWindow(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259E8; symbol: _RegisterClassW@4
ATOM __stdcall RegisterClassW(const WNDCLASSW *lpWndClass)
{
  return RegisterClassW(lpWndClass);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A08; symbol: _LoadImageA@24
HANDLE __stdcall LoadImageA(HINSTANCE a1, LPCSTR a2, UINT a3, int a4, int a5, UINT a6)
{
  return LoadImageA(a1, a2, a3, a4, a5, a6);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A10; symbol: _LoadCursorA@8
HCURSOR __stdcall LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName)
{
  return LoadCursorA(hInstance, lpCursorName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B48; symbol: _LoadLibraryA@4
HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName)
{
  return LoadLibraryA(lpLibFileName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00426710; symbol: _register_frame_ctor
int register_frame_ctor()
{
  return __gcc_register_frame();
}


// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00401460; symbol: __ZN5BlockC1Ev
void __cdecl Block::Block(Block *const this)
{
  Block *v1; // ecx
  Block *v2; // ST1C_4
  Block *const v3; // ST00_4

  v2 = v1;
  v1->w = 0;
  v1->h = 0;
  v1->n = 0;
  v1->sit = 0;
  v1->pauseb = 0;
  v1->maskj = 0;
  v1->maski = 0;
  v1->flag = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->qstn = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->mine = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->blck = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->mask = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->leftrule = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->rightrule = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->numb = (int (*)[128])calloc(0x80u, 0x200u);
  Block::initbl(v3);
}



// 阅读说明：初始化 Block 的棋盘存储与状态；具体布局以恢复类型和函数体为准。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040159C; symbol: __ZN5Block6initblEv
void __cdecl Block::initbl(Block *const this)
{
  int *v1; // ecx
  Block *v2; // [esp+0h] [ebp-28h]
  int j; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]

  *v1 = 3;
  v1[1] = 5;
  for ( i = 0; *v1 > i; ++i )
  {
    for ( j = 0; v1[1] > j; ++j )
    {
      *(_BYTE *)(v1[11] + (i << 7) + j) = 0;
      *(_BYTE *)(v1[9] + (i << 7) + j) = 0;
      *(_BYTE *)(v1[10] + (i << 7) + j) = 0;
      *(_BYTE *)(v1[12] + (i << 7) + j) = 0;
      *(_BYTE *)(v1[13] + (i << 7) + j) = 0;
      *(_DWORD *)(v1[14] + (i << 9) + 4 * j) = 0;
    }
  }
  *(_BYTE *)v1[11] = 1;
  *(_BYTE *)(v1[11] + 1) = 1;
  *(_BYTE *)(v1[11] + 129) = 1;
  *(_BYTE *)(v1[11] + 4) = 1;
  *(_BYTE *)(v1[11] + 132) = 1;
  *(_BYTE *)(v1[12] + 256) = 1;
  *(_BYTE *)(v1[12] + 257) = 1;
  *(_BYTE *)(v1[12] + 130) = 1;
  *(_BYTE *)(v1[12] + 258) = 1;
  *(_BYTE *)(v1[12] + 131) = 1;
  *(_BYTE *)(v1[12] + 259) = 1;
  Block::calcnumb(v2);
}



// 阅读说明：遍历棋盘，清零每格的 numb，再检查 8 个相邻方向，统计 mine 为真的邻格数量。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00401714; symbol: __ZN5Block8calcnumbEv
void __cdecl Block::calcnumb(Block *const this)
{
  Block *v1; // ecx
  int *v2; // [esp+14h] [ebp-34h]
  Block *thisa; // [esp+2Ch] [ebp-1Ch]
  Block *k; // [esp+34h] [ebp-14h]
  int j; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]

  thisa = v1;
  for ( i = 0; thisa->w > i; ++i )
  {
    for ( j = 0; thisa->h > j; ++j )
    {
      thisa->numb[i][j] = 0;
      for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
      {
        if ( Block::isok(k, i, j, (int)&thisa->tx, &thisa->ty, v2) )
        {
          if ( thisa->mine[thisa->tx][thisa->ty] )
            ++thisa->numb[i][j];
        }
      }
    }
  }
}



// 阅读说明：按方向选择相邻坐标并检查边界；输出坐标通过引用或指针返回。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00401800; symbol: __ZN5Block4isokElllRlS0_
bool __userpurge Block::isok@<al>(_DWORD *a1@<ecx>, Block *const this, int k, int x, int y, int *const tx, int *const ty)
{
  bool result; // al

  switch ( (unsigned int)this )
  {
    case 0u:
      *(_DWORD *)y = k - 1;
      *tx = x;
      result = k > 0;
      break;
    case 1u:
      *(_DWORD *)y = k + 1;
      *tx = x;
      result = *a1 - 1 > k;
      break;
    case 2u:
      *(_DWORD *)y = k;
      *tx = x - 1;
      result = x > 0;
      break;
    case 3u:
      *(_DWORD *)y = k;
      *tx = x + 1;
      result = a1[1] - 1 > x;
      break;
    case 4u:
      *(_DWORD *)y = k - 1;
      *tx = x - 1;
      result = k > 0 && x > 0;
      break;
    case 5u:
      *(_DWORD *)y = k - 1;
      *tx = x + 1;
      result = k > 0 && a1[1] - 1 > x;
      break;
    case 6u:
      *(_DWORD *)y = k + 1;
      *tx = x - 1;
      result = *a1 - 1 > k && x > 0;
      break;
    case 7u:
      *(_DWORD *)y = k + 1;
      *tx = x + 1;
      result = *a1 - 1 > k && a1[1] - 1 > x;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004019A0; symbol: __ZN5BoardC1Ev
void __cdecl Board::Board(Board *const this)
{
  Board *v1; // ecx
  Board *v2; // ST1C_4
  Steam *const v3; // ST00_4
  Sound *const v4; // ST00_4
  time_t v5; // ebx
  clock_t v6; // eax
  Block *v7; // [esp+0h] [ebp-28h]

  v2 = v1;
  Block::Block(v7);
  Steam::Steam(v3);
  Sound::Sound(v4);
  v2->mode = 0;
  v2->mode_ = 0;
  v2->rightb = 0;
  v2->aliveb = 0;
  v2->delayb = 1;
  v2->delayb__ = 0;
  v2->mdb_ = 0;
  v2->tutb = 1;
  v2->tutx[0] = 5;
  v2->tutx[1] = 5;
  v2->tutx[2] = 4;
  v2->tutx[3] = 9;
  v2->tutx[4] = 8;
  v2->tutx[5] = 8;
  v2->tutx[6] = 9;
  v2->tutx[7] = 10;
  v2->tutx[8] = 2;
  v2->tutx[9] = 2;
  v2->tutx[10] = 3;
  v2->tutx[11] = 3;
  v2->tutx[12] = 2;
  v2->tuty[0] = 16;
  v2->tuty[1] = 17;
  v2->tuty[2] = 17;
  v2->tuty[3] = 17;
  v2->tuty[4] = 17;
  v2->tuty[5] = 18;
  v2->tuty[6] = 18;
  v2->tuty[7] = 18;
  v2->tuty[8] = 17;
  v2->tuty[9] = 16;
  v2->tuty[10] = 17;
  v2->tuty[11] = 19;
  v2->tuty[12] = 19;
  v2->tutm[0] = 1;
  v2->tutm[1] = 1;
  v2->tutm[2] = 3;
  v2->tutm[3] = 2;
  v2->tutm[4] = 3;
  v2->tutm[5] = 3;
  v2->tutm[6] = 3;
  v2->tutm[7] = 3;
  v2->tutm[8] = 1;
  v2->tutm[9] = 2;
  v2->tutm[10] = 3;
  v2->tutm[11] = 3;
  v2->tutm[12] = 3;
  v2->relaxb = 0;
  v2->rulemain = 0;
  v2->blckrule = 0;
  v2->rulemain = (Board::rule *)calloc(0x4000u, 0x50u);
  v2->blckrule = (int (*)[128])calloc(0x80u, 0x200u);
  v5 = time(0);
  v6 = clock();
  srand(v5 + v6);
}



// 阅读说明：初始化棋盘；存在多个重载，参数和初始化细节见下方函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00401CB6; symbol: __ZN5Board6initbdEv
void __cdecl Board::initbd(Board *const this)
{
  int v1; // ecx
  signed int v2; // edx
  signed int v3; // eax
  signed int v4; // edx
  signed int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp+4h] [ebp-44h]
  int v9; // [esp+4h] [ebp-44h]
  int v10; // [esp+4h] [ebp-44h]
  Board *thisa; // [esp+1Ch] [ebp-2Ch]
  int mode__[4]; // [esp+28h] [ebp-20h]
  int j; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]

  thisa = (Board *)v1;
  Steam::setlead(*(Steam *const *)(v1 + 2128), v8);
  thisa->sit = 0;
  thisa->line = 0;
  thisa->level = 0;
  thisa->tetrisi = 0;
  thisa->missi = 0;
  thisa->missline = 0;
  thisa->sum = 0;
  if ( thisa->maxbdw > 128 )
    v2 = 128;
  else
    v2 = thisa->maxbdw;
  v3 = thisa->w;
  if ( thisa->w < 12 )
    v3 = 12;
  if ( v2 > v3 )
    v2 = v3;
  thisa->w = v2;
  if ( thisa->maxbdh > 128 )
    v4 = 128;
  else
    v4 = thisa->maxbdh;
  v5 = thisa->h;
  if ( v5 < 8 )
    v5 = 8;
  if ( v4 > v5 )
    v4 = v5;
  thisa->h = v4;
  v6 = thisa->w - 1;
  if ( v6 > thisa->n )
    v6 = thisa->n;
  if ( v6 <= 0 )
    v6 = 1;
  thisa->n = v6;
  v7 = thisa->maskj0;
  if ( v7 > thisa->h - 4 )
    v7 = thisa->h - 4;
  thisa->maskj = v7;
  if ( thisa->relaxb )
    thisa->maskj = 1;
  thisa->maski = 0;
  thisa->maskjb = 0;
  for ( i = 0; thisa->w > i; ++i )
  {
    for ( j = 0; thisa->h > j; ++j )
    {
      thisa->mine[i][j] = thisa->n > i;
      thisa->flag[i][j] = 0;
      thisa->leftrule[i][j] = 0;
      thisa->rightrule[i][j] = 0;
      thisa->qstn[i][j] = 0;
      thisa->blck[i][j] = 0;
      thisa->mask[i][j] = thisa->maskj > j;
      thisa->numb[i][j] = 0;
    }
  }
  Sound::playsound((Sound *const )thisa->sd.sNew, v9);
  mode__[0] = 0;
  mode__[1] = 1;
  mode__[2] = 2;
  mode__[3] = 4;
  thisa->mode_ |= mode__[thisa->mode];
  if ( !thisa->mode )
    Steam::addach((Steam *const )thisa->st.achgencustom, v10);
  if ( thisa->mode_ == 7 )
    Steam::addach((Steam *const )thisa->st.achgenmode, v10);
  thisa->rightb = 0;
  thisa->tuti = 0;
  thisa->tutb = 0;
  thisa->checkr = 0;
  thisa->pauseb = 0;
  thisa->mx = -1;
  thisa->my = -1;
  thisa->bouns = 0;
  thisa->solven = 0;
}



// 阅读说明：初始化棋盘；存在多个重载，参数和初始化细节见下方函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402048; symbol: __ZN5Board6initbdEllll
void __userpurge Board::initbd(Board **a1@<ecx>, Board *const this, int w_, int h_, int maskj_, int n_)
{
  Board *v6; // [esp+0h] [ebp-18h]

  *a1 = this;
  a1[1] = (Board *)w_;
  a1[2] = (Board *)maskj_;
  a1[537] = (Board *)h_;
  Board::initbd(v6);
}



// 阅读说明：初始化棋盘；存在多个重载，参数和初始化细节见下方函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402086; symbol: __ZN5Board6initbdEll
void __userpurge Board::initbd(int a1@<ecx>, Board *const this, int mode_, int md_)
{
  int v4; // eax
  int v5; // [esp+4h] [ebp-24h]
  int v6; // [esp+10h] [ebp-18h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = (Board *)a1;
  Steam::setlead(*(Steam *const *)(a1 + 2128), v5);
  thisa->mode = (int)this;
  v4 = thisa->mode;
  switch ( v4 )
  {
    case 2:
      Board::initbd((Board **)thisa, (Board *const )0x10, 24, 8, 3, v6);
      break;
    case 3:
      Board::initbd((Board **)thisa, (Board *const )0x20, 32, 8, 6, v6);
      break;
    case 1:
      Board::initbd((Board **)thisa, (Board *const )0xC, 20, 8, 2, v6);
      break;
  }
  thisa->mdb = mode_ <= 1;
}



// 阅读说明：函数名指向随机布雷；随机调用和排除条件以函数体为准。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402174; symbol: __ZN5Board8randmineEll
void __userpurge Board::randmine(Board *a1@<ecx>, Board *const this, int x, int y)
{
  bool mb; // ST17_1
  bool mb_0; // ST16_1
  Board *thisa; // [esp+Ch] [ebp-2Ch]
  int i_1; // [esp+18h] [ebp-20h]
  int i_0; // [esp+1Ch] [ebp-1Ch]
  int j_0; // [esp+20h] [ebp-18h]
  int k; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  int j; // [esp+2Ch] [ebp-Ch]

  thisa = a1;
  for ( j = 0; thisa->h > j; ++j )
  {
    for ( i = 0; thisa->w > i; ++i )
    {
      thisa->rx = rand() % thisa->w;
      thisa->ry = j;
      mb = thisa->mine[thisa->rx][thisa->ry];
      thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i][j];
      thisa->mine[i][j] = mb;
    }
  }
  for ( k = 0; thisa->n > k; ++k )
  {
    for ( j_0 = x - 1; x + 1 >= j_0; ++j_0 )
    {
      for ( i_0 = (int)&this[-1].solven + 3; (signed int)&this->w + 1 >= i_0; ++i_0 )
      {
        if ( j_0 >= 0 && i_0 >= 0 && thisa->h > j_0 && thisa->w > i_0 && thisa->mine[i_0][j_0] )
        {
          thisa->rx = rand() % thisa->w;
          thisa->ry = j_0;
          mb_0 = thisa->mine[thisa->rx][thisa->ry];
          thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i_0][j_0];
          thisa->mine[i_0][j_0] = mb_0;
        }
      }
    }
  }
  thisa->rx = (int)this;
  thisa->ry = x;
  if ( thisa->mine[(_DWORD)this][x] )
  {
    for ( i_1 = 0; thisa->w > i_1; ++i_1 )
    {
      if ( thisa->mine[i_1][x] != 1 )
      {
        thisa->rx = i_1;
        thisa->ry = x;
      }
    }
    thisa->mine[thisa->rx][thisa->ry] = 1;
    thisa->mine[(_DWORD)this][x] = 0;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402468; symbol: __ZN5Board7tutmineEv
void __cdecl Board::tutmine(Board *const this)
{
  Board *v1; // ecx
  Board *thisa; // [esp+Ch] [ebp-4Ch]
  int rx1_[5]; // [esp+18h] [ebp-40h]
  int rx0_[5]; // [esp+2Ch] [ebp-2Ch]
  bool mb_0; // [esp+42h] [ebp-16h]
  bool mb; // [esp+43h] [ebp-15h]
  int i; // [esp+44h] [ebp-14h]
  int i_0; // [esp+48h] [ebp-10h]
  int j; // [esp+4Ch] [ebp-Ch]

  thisa = v1;
  rx0_[0] = 8;
  rx0_[1] = 10;
  rx0_[2] = 1;
  rx0_[3] = 0;
  rx0_[4] = 0;
  rx1_[0] = 5;
  rx1_[1] = 3;
  rx1_[2] = 9;
  rx1_[3] = 2;
  rx1_[4] = 9;
  for ( j = 0; thisa->h > j; ++j )
  {
    if ( thisa->h - 5 > j )
    {
      for ( i_0 = 0; thisa->w > i_0; ++i_0 )
      {
        thisa->rx = rand() % thisa->w;
        thisa->ry = j;
        mb_0 = thisa->mine[thisa->rx][thisa->ry];
        thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i_0][j];
        thisa->mine[i_0][j] = mb_0;
      }
    }
    else
    {
      i = 1;
      thisa->rx = rx1_[j - thisa->h + 5];
      thisa->ry = j;
      mb = thisa->mine[thisa->rx][thisa->ry];
      thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i][j];
      thisa->mine[i][j] = mb;
      i = 0;
      thisa->rx = rx0_[j - thisa->h + 5];
      thisa->ry = j;
      mb = thisa->mine[thisa->rx][thisa->ry];
      thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i][j];
      thisa->mine[i][j] = mb;
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004026F6; symbol: __ZN5Board7resetbdEll
void __userpurge Board::resetbd(Board *a1@<ecx>, Board *const this, int x, int y)
{
  Board *v4; // [esp+0h] [ebp-28h]
  Block *v5; // [esp+0h] [ebp-28h]
  int v6; // [esp+4h] [ebp-24h]
  int v7; // [esp+8h] [ebp-20h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->tutb == 1 )
    Board::tutmine(v4);
  else
    Board::randmine(a1, this, x, v7);
  Block::calcnumb(v5);
  thisa->time = GetTimeR();
  thisa->time_ = thisa->time;
  thisa->sit = 1;
  Steam::addach((Steam *const )thisa->st.achgenstart, v6);
}



// 阅读说明：在有效且未暂停的游戏状态中，正反两次扫描棋盘并点击未揭开的无雷零数字格；从第 2 行开始。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402788; symbol: __ZN5Board10solveblankEv
void __cdecl Board::solveblank(Board *const this)
{
  Board *v1; // ecx
  bool v2; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j_0; // [esp+20h] [ebp-18h]
  int i_0; // [esp+24h] [ebp-14h]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  v1->solvebb = 0;
  if ( v1->sit > 0 && v1->sit <= 3 && !v1->pauseb )
  {
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = 2; thisa->h > j; ++j )
      {
        if ( thisa->mask[i][j] != 1 && thisa->mine[i][j] != 1 && !thisa->numb[i][j] )
          Board::clickleft((Board *const )i, j, 0, v2);
      }
    }
    for ( i_0 = thisa->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = thisa->h - 1; j_0 > 1; --j_0 )
      {
        if ( thisa->mask[i_0][j_0] != 1 && thisa->mine[i_0][j_0] != 1 && !thisa->numb[i_0][j_0] )
          Board::clickleft((Board *const )i_0, j_0, 0, v2);
      }
    }
  }
}



// 阅读说明：反复调用空白格处理；循环条件由 solvebb 状态决定。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402920; symbol: __ZN5Board11solveblank_Ev
void __cdecl Board::solveblank_(Board *const this)
{
  Board *v1; // ecx
  Board *v2; // [esp+0h] [ebp-18h]
  Board *thisa; // [esp+Ch] [ebp-Ch]

  thisa = v1;
  v1->solvebb = 1;
  while ( thisa->solvebb )
    Board::solveblank(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402950; symbol: __ZN5Board6solve0Ev
void __cdecl Board::solve0(Board *const this)
{
  Board *v1; // ecx
  bool v2; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j_0; // [esp+20h] [ebp-18h]
  int i_0; // [esp+24h] [ebp-14h]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  v1->solveb0 = 0;
  if ( v1->sit <= 3 && !v1->pauseb )
  {
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = 2; thisa->h > j; ++j )
      {
        if ( thisa->blck[i][j] )
        {
          if ( !thisa->numb[i][j] )
            Board::clicknumb((Board *const )i, j, 0, v2);
        }
      }
    }
    for ( i_0 = thisa->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = thisa->h - 1; j_0 > 1; --j_0 )
      {
        if ( thisa->blck[i_0][j_0] && !thisa->numb[i_0][j_0] )
          Board::clicknumb((Board *const )i_0, j_0, 0, v2);
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402A8A; symbol: __ZN5Board7solve0_Ev
void __cdecl Board::solve0_(Board *const this)
{
  Board *v1; // ecx
  Board *v2; // [esp+0h] [ebp-18h]
  Board *thisa; // [esp+Ch] [ebp-Ch]

  thisa = v1;
  v1->solveb0 = 1;
  while ( thisa->solveb0 )
    Board::solve0(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402ABA; symbol: __ZN5Board6solve1Ev
void __cdecl Board::solve1(Board *const this)
{
  Board *v1; // ecx
  int v2; // [esp+4h] [ebp-34h]
  bool v3; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j_0; // [esp+20h] [ebp-18h]
  int i_0; // [esp+24h] [ebp-14h]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  v1->solveb1 = 0;
  if ( v1->sit <= 3 && !v1->pauseb )
  {
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = 2; thisa->h > j; ++j )
      {
        if ( thisa->blck[i][j] )
        {
          if ( thisa->numb[i][j] >= 0 )
            Board::clicknumb((Board *const )i, j, 0, v3);
        }
      }
    }
    for ( i_0 = thisa->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = thisa->h - 1; j_0 > 1; --j_0 )
      {
        if ( thisa->blck[i_0][j_0] && thisa->numb[i_0][j_0] >= 0 )
          Board::clicknumb((Board *const )i_0, j_0, 0, v3);
      }
    }
    Sound::playsound((Sound *const )thisa->sd.sSolve, v2);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402C12; symbol: __ZN5Board7solve1_Ev
void __cdecl Board::solve1_(Board *const this)
{
  Board *v1; // ecx
  Board *const v2; // ST00_4
  bool v3; // [esp+4h] [ebp-24h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  v1->solveb1 = 1;
  while ( thisa->solveb1 )
  {
    Board::checkline(0, v3);
    Board::solve1(v2);
  }
}



// 阅读说明：从已揭开格的周围格构造约束：数字减去已标旗/已确认雷数，记录尚未确定的相邻坐标。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402C56; symbol: __ZN5Board10createruleEv
void __cdecl Board::createrule(Board *const this)
{
  Board *v1; // ecx
  int *v2; // [esp+14h] [ebp-44h]
  Board *thisa; // [esp+2Ch] [ebp-2Ch]
  Block *k; // [esp+34h] [ebp-24h]
  int j; // [esp+38h] [ebp-20h]
  int i; // [esp+3Ch] [ebp-1Ch]

  thisa = v1;
  for ( i = 0; thisa->w > i; ++i )
  {
    for ( j = 0; thisa->h > j; ++j )
    {
      thisa->blckrule[i][j] = -1;
      if ( thisa->blck[i][j] )
      {
        thisa->ruletemp.x = i;
        thisa->ruletemp.y = j;
        thisa->ruletemp.numbc = thisa->numb[i][j];
        thisa->ruletemp.blckc = 0;
        for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
        {
          if ( Block::isok(thisa, k, i, j, (int)&thisa->tx, &thisa->ty, v2) )
          {
            if ( thisa->flag[thisa->tx][thisa->ty] || thisa->rightrule[thisa->tx][thisa->ty] )
            {
              --thisa->ruletemp.numbc;
            }
            else if ( thisa->blck[thisa->tx][thisa->ty] != 1 )
            {
              *(&thisa->n + thisa->ruletemp.blckc + 612) = thisa->tx;
              *(&thisa->n + thisa->ruletemp.blckc++ + 620) = thisa->ty;
            }
          }
        }
        thisa->blckrule[i][j] = thisa->rulemainc;
        qmemcpy(&thisa->rulemain[thisa->rulemainc++], &thisa->ruletemp, sizeof(thisa->rulemain[thisa->rulemainc++]));
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402EAC; symbol: __ZN5Board11compareruleEll
void __userpurge Board::comparerule(_DWORD *a1@<ecx>, Board *const this, int rule1c, int rule2c)
{
  Board::rule rule2; // [esp+4h] [ebp-BCh]
  Board::rule rule1; // [esp+54h] [ebp-6Ch]
  int rule2k_0; // [esp+A4h] [ebp-1Ch]
  int rule1k_0; // [esp+A8h] [ebp-18h]
  int rule2k; // [esp+ACh] [ebp-14h]
  int rule1k; // [esp+B0h] [ebp-10h]

  qmemcpy(&rule1, (const void *)(a1[630] + 80 * (_DWORD)this), sizeof(rule1));
  qmemcpy(&rule2, (const void *)(a1[630] + 80 * rule1c), sizeof(rule2));
  for ( rule1k = 0; *(_DWORD *)(a1[630] + 80 * (_DWORD)this + 12) > rule1k; ++rule1k )
  {
    for ( rule2k = 0; *(_DWORD *)(a1[630] + 80 * rule1c + 12) > rule2k; ++rule2k )
    {
      if ( *(&rule1.x + rule1k + 4) >= 0
        && *(&rule1.x + rule1k + 12) >= 0
        && *(&rule2.x + rule2k + 4) >= 0
        && *(&rule2.x + rule2k + 12) >= 0
        && *(&rule1.x + rule1k + 4) == *(&rule2.x + rule2k + 4)
        && *(&rule1.x + rule1k + 12) == *(&rule2.x + rule2k + 12) )
      {
        *(&rule1.x + rule1k + 4) = -1;
        *(&rule1.x + rule1k + 12) = -1;
        --rule1.blckc;
        *(&rule2.x + rule2k + 4) = -1;
        *(&rule2.x + rule2k + 12) = -1;
        --rule2.blckc;
      }
    }
  }
  if ( rule1.blckc == rule1.numbc - rule2.numbc )
  {
    for ( rule1k_0 = 0; *(_DWORD *)(a1[630] + 80 * (_DWORD)this + 12) > rule1k_0; ++rule1k_0 )
    {
      if ( *(&rule1.x + rule1k_0 + 4) >= 0
        && *(&rule1.x + rule1k_0 + 12) >= 0
        && *(_BYTE *)(a1[13] + (*(&rule1.x + rule1k_0 + 4) << 7) + *(&rule1.x + rule1k_0 + 12)) != 1 )
      {
        *(_BYTE *)(a1[16] + (*(&rule1.x + rule1k_0 + 4) << 7) + *(&rule1.x + rule1k_0 + 12)) = 1;
      }
    }
    for ( rule2k_0 = 0; *(_DWORD *)(a1[630] + 80 * rule1c + 12) > rule2k_0; ++rule2k_0 )
    {
      if ( *(&rule2.x + rule2k_0 + 4) >= 0
        && *(&rule2.x + rule2k_0 + 12) >= 0
        && *(_BYTE *)(a1[13] + (*(&rule2.x + rule2k_0 + 4) << 7) + *(&rule2.x + rule2k_0 + 12)) != 1 )
      {
        *(_BYTE *)(a1[15] + (*(&rule2.x + rule2k_0 + 4) << 7) + *(&rule2.x + rule2k_0 + 12)) = 1;
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004031E6; symbol: __ZN5Board11compareruleEv
void __cdecl Board::comparerule(Board *const this)
{
  Board *v1; // ecx
  int v2; // [esp+8h] [ebp-40h]
  int *v3; // [esp+14h] [ebp-34h]
  Board *thisa; // [esp+2Ch] [ebp-1Ch]
  int y; // [esp+30h] [ebp-18h]
  int x; // [esp+34h] [ebp-14h]
  Block *k; // [esp+38h] [ebp-10h]
  int rulemaini; // [esp+3Ch] [ebp-Ch]

  thisa = v1;
  for ( rulemaini = 0; thisa->rulemainc > rulemaini; ++rulemaini )
  {
    x = thisa->rulemain[rulemaini].x;
    y = thisa->rulemain[rulemaini].y;
    for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
    {
      if ( Block::isok(thisa, k, x, y, (int)&thisa->tx, &thisa->ty, v3) && thisa->blckrule[thisa->tx][thisa->ty] >= 0 )
        Board::comparerule(thisa, (Board *const )rulemaini, thisa->blckrule[thisa->tx][thisa->ty], v2);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403306; symbol: __ZN5Board9applyruleEb
void __userpurge Board::applyrule(Board *a1@<ecx>, Board *const this, bool applyb)
{
  bool v3; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = a1;
  for ( i = 0; thisa->w > i; ++i )
  {
    for ( j = 2; thisa->h > j; ++j )
    {
      if ( thisa->leftrule[i][j] )
      {
        if ( thisa->blck[i][j] != 1 && thisa->mask[i][j] != 1 )
        {
          thisa->solvebb = 1;
          thisa->solveb0 = 1;
          thisa->solveb1 = 1;
          thisa->solveb2 = 1;
          thisa->solveb3 = 1;
          ++thisa->solven;
          if ( (_BYTE)this )
            Board::clickleft((Board *const )i, j, 0, v3);
        }
      }
      if ( thisa->rightrule[i][j]
        && thisa->blck[i][j] != 1
        && thisa->qstn[i][j] != 1
        && thisa->flag[i][j] != 1
        && thisa->mask[i][j] != 1 )
      {
        thisa->solvebb = 1;
        thisa->solveb0 = 1;
        thisa->solveb1 = 1;
        thisa->solveb2 = 1;
        thisa->solveb3 = 1;
        ++thisa->solven;
        if ( (_BYTE)this )
          Board::clickright((Board *const )i, j, 0, v3);
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403530; symbol: __ZN5Board6solve2Eb
void __userpurge Board::solve2(Board *a1@<ecx>, Board *const this, bool applyb)
{
  Board *const v3; // ST00_4
  Board *v4; // [esp+0h] [ebp-28h]
  bool v5; // [esp+4h] [ebp-24h]
  int v6; // [esp+4h] [ebp-24h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  a1->solveb2 = 0;
  a1->rulemainc = 0;
  a1->solven = 0;
  if ( a1->sit <= 3 && !a1->pauseb )
  {
    Board::createrule(v4);
    Board::comparerule(v3);
    Board::applyrule(thisa, (Board *const )(unsigned __int8)this, v5);
    if ( (_BYTE)this )
      Sound::playsound((Sound *const )thisa->sd.sSolve, v6);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004035CA; symbol: __ZN5Board6solve2Ev
void __cdecl Board::solve2(Board *const this)
{
  Board *v1; // ecx
  bool v2; // [esp+4h] [ebp-24h]

  Board::solve2(v1, (Board *const )1, v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004035EA; symbol: __ZN5Board7solve2_Eb
void __userpurge Board::solve2_(Board *a1@<ecx>, Board *const this, bool applyb)
{
  bool v3; // [esp+4h] [ebp-34h]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int solven_; // [esp+2Ch] [ebp-Ch]

  thisa = a1;
  a1->solveb2 = 1;
  solven_ = -1;
  while ( thisa->solveb2 == 1 && (thisa->solven > solven_ || (_BYTE)this == 1) )
  {
    solven_ = thisa->solven;
    if ( (_BYTE)this )
      Board::checkline(0, v3);
    Board::solve2(thisa, (Board *const )(unsigned __int8)this, v3);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403676; symbol: __ZN5Board7solve2_Ev
void __cdecl Board::solve2_(Board *const this)
{
  Board *v1; // ecx
  bool v2; // [esp+4h] [ebp-24h]

  Board::solve2_(v1, (Board *const )1, v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403696; symbol: __ZN5Board7solve3_Ev
void __cdecl Board::solve3_(Board *const this)
{
  Board *v1; // ecx
  Board *const v2; // ST00_4
  bool v3; // ST04_1
  Board *const v4; // ST00_4
  bool v5; // dl
  bool v6; // [esp+4h] [ebp-24h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  v1->solveb3 = 1;
  while ( thisa->solveb3 )
  {
    Board::checkline(0, v6);
    Board::solve1(v2);
    Board::checkline(0, v3);
    Board::solve2(v4);
    v5 = thisa->solveb1 || thisa->solveb2;
    thisa->solveb3 = v5;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040372A; symbol: __ZN5Board10checkerrorEll
BOOL __userpurge Board::checkerror@<eax>(Board *a1@<ecx>, Board *const this, int i, int j)
{
  Board *const v4; // ST00_4
  int v5; // ST0C_4
  bool v6; // ST04_1
  Board *const v7; // ST00_4
  int v8; // ST04_4
  Board *v10; // [esp+0h] [ebp-38h]
  int v11; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  bool result; // [esp+2Fh] [ebp-9h]

  thisa = a1;
  result = 0;
  if ( a1->blck[(_DWORD)this][i] && a1->mine[(_DWORD)this][i] && a1->sit != 2 && a1->sit <= 3 )
  {
    a1->dieb = 1;
    a1->diex = (int)this;
    a1->diey = i;
    a1->blck[(_DWORD)this][i] = 0;
    a1->flag[(_DWORD)this][i] = 1;
    a1->qstn[(_DWORD)this][i] = 0;
    a1->sit = 2;
    if ( a1->solven > 0 || a1->tutb > 0 )
    {
      Board::addline(v10);
      Board::addline(v4);
      Steam::compscr((Steam *const )(thisa->line - thisa->missline), thisa->mode, thisa->st.scrindexnomiss, v11);
      thisa->missline = thisa->line;
      Steam::compscr((Steam *const )++thisa->missi, thisa->mode, thisa->st.scrindexmiss, v5);
      Board::checkline((Board *const )1, v6);
      Board::checkdie(v7);
    }
    if ( thisa->sit == 2 )
      thisa->sit = 1;
    Steam::addscr((Steam *const )thisa->st.scrdead, 1, thisa->mode, v11);
    Sound::playsound((Sound *const )thisa->sd.sError, v8);
    thisa->sb = 0;
    result = 1;
    thisa->checkr = 1;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403976; symbol: __ZN5Board10checkerrorEv
bool __cdecl Board::checkerror(Board *const this)
{
  Board *v1; // ecx
  int v3; // [esp+8h] [ebp-30h]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j; // [esp+24h] [ebp-14h]
  Board *i; // [esp+28h] [ebp-10h]
  char result; // [esp+2Fh] [ebp-9h]

  thisa = v1;
  result = 0;
  if ( v1->sit != 2 && v1->sit <= 3 )
  {
    v1->dieb = 0;
    for ( i = 0; thisa->w > (signed int)i; i = (Board *)((char *)i + 1) )
    {
      for ( j = 0; thisa->h > j; ++j )
        result = Board::checkerror(thisa, i, j, v3);
    }
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004039F6; symbol: __ZN5Board9checklineEb
void __userpurge Board::checkline(Board *a1@<ecx>, Board *const this, bool delayb_)
{
  int dl_0; // ST4C_4
  Board *v4; // [esp+0h] [ebp-78h]
  Board *v5; // [esp+0h] [ebp-78h]
  int v6; // [esp+4h] [ebp-74h]
  Board *thisa; // [esp+3Ch] [ebp-3Ch]
  int maskj_; // [esp+50h] [ebp-28h]
  int k; // [esp+54h] [ebp-24h]
  int i; // [esp+58h] [ebp-20h]
  int j_; // [esp+5Ch] [ebp-1Ch]
  int flagc; // [esp+60h] [ebp-18h]
  int blckc; // [esp+64h] [ebp-14h]
  bool delb; // [esp+6Bh] [ebp-Dh]
  Board *j; // [esp+6Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->sit > 0 && a1->sit <= 3 && !a1->pauseb )
  {
    Board::solve0_(v4);
    delb = 0;
    j = (Board *)(thisa->h - 1);
    j_ = 0;
    maskj_ = thisa->maskj & ~(thisa->maskj >> 31);
    while ( (signed int)j >= maskj_ )
    {
      blckc = 0;
      flagc = 0;
      for ( i = 0; thisa->w > i; ++i )
      {
        if ( *((_BYTE *)&j->w + (unsigned int)thisa->blck[i]) != 1 )
          ++blckc;
        if ( *((_BYTE *)&j->w + (unsigned int)thisa->flag[i]) )
          ++flagc;
      }
      if ( thisa->n != blckc && thisa->n != flagc )
      {
        j = (Board *)((char *)j - 1);
      }
      else
      {
        delb = 1;
        Board::delline(j, v6);
        if ( thisa->delayb && (_BYTE)this || thisa->tutb == 1 )
        {
          for ( k = 0; thisa->mult > (long double)k; ++k )
            Line(
              0,
              (signed int)((long double)(16 * (signed int)((char *)&j->w - j_ + 3) + 8) * thisa->mult
                         + (long double)k
                         - (thisa->mult - 1.0) / 2.0),
              (signed int)((long double)thisa->w_ * thisa->mult),
              0,
              thisa->cred);
        }
        ++j_;
      }
    }
    if ( delb )
    {
      if ( (Sound::playsound((Sound *const )thisa->sd.sSolve, v6), thisa->delayb) && (_BYTE)this || thisa->tutb == 1 )
      {
        FreshWin();
        dl_0 = (signed int)(1000.0 / ((long double)thisa->level / 5.0 + 1.0));
        thisa->time = thisa->time + (long double)dl_0 / 1000.0;
        Delay(dl_0);
        thisa->delayb__ = 1;
      }
    }
    Board::solve0_(v5);
    Board::solve2_(thisa, 0, v6);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403CE8; symbol: __ZN5Board7addlineEb
void __userpurge Board::addline(Board *a1@<ecx>, Board *const this, bool misslineb)
{
  int *v3; // [esp+14h] [ebp-44h]
  Board *thisa; // [esp+2Ch] [ebp-2Ch]
  int j; // [esp+3Ch] [ebp-1Ch]
  Block *k; // [esp+40h] [ebp-18h]
  int j_0; // [esp+44h] [ebp-14h]
  int i_0; // [esp+48h] [ebp-10h]
  int i; // [esp+4Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->sit > 0 && a1->sit <= 3 && !a1->pauseb )
  {
    --a1->bouns;
    --a1->maskj;
    if ( a1->relaxb && a1->maskj <= 0 )
    {
      --a1->line;
      --a1->sum;
      a1->line &= ~(a1->line >> 31);
      if ( (_BYTE)this )
      {
        --a1->missline;
        a1->missline &= ~(a1->missline >> 31);
      }
      a1->sum &= ~(a1->sum >> 31);
      ++a1->maskj;
    }
    j = a1->maskj;
    if ( a1->maskj >= 0 )
    {
      for ( i = 0; a1->w > i; ++i )
        a1->mask[i][j] = 0;
      for ( i_0 = 0; thisa->w > i_0; ++i_0 )
      {
        for ( j_0 = thisa->maskj + 1; thisa->maskj <= j_0; --j_0 )
        {
          thisa->numb[i_0][j_0] = 0;
          for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
          {
            if ( Block::isok(thisa, k, i_0, j_0, (int)&thisa->tx, &thisa->ty, v3) )
            {
              if ( thisa->mine[thisa->tx][thisa->ty] )
                ++thisa->numb[i_0][j_0];
            }
          }
        }
      }
    }
    else
    {
      a1->maskjb = 1;
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403F44; symbol: __ZN5Board7addlineEv
void __cdecl Board::addline(Board *const this)
{
  Board *v1; // ecx
  bool v2; // [esp+4h] [ebp-24h]

  Board::addline(v1, (Board *const )1, v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403F64; symbol: __ZN5Board7addmaskEv
bool __cdecl Board::addmask(Board *const this)
{
  Board *v1; // ecx
  Board *v3; // [esp+0h] [ebp-28h]
  bool v4; // [esp+4h] [ebp-24h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->sit <= 0 || v1->sit > 3 || v1->pauseb )
  {
    v1->time = GetTimeR() - v1->pausetime;
    return 0;
  }
  if ( v1->tutb || GetTimeR() <= v1->time + 5.0 / ((long double)v1->level + 5.0) )
    return 0;
  while ( GetTimeR() > thisa->time + 5.0 / ((long double)thisa->level + 5.0) )
  {
    thisa->time = thisa->time + 5.0 / ((long double)thisa->level + 5.0);
    if ( ++thisa->maski == thisa->w )
    {
      thisa->maski = 0;
      Board::addline(v3);
      Board::checkline(thisa, (Board *const )1, v4);
    }
  }
  Board::checkdie(v3);
  return 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004040E2; symbol: __ZN5Board8checkdieEv
void __cdecl Board::checkdie(Board *const this)
{
  Board *v1; // ecx
  int v2; // [esp+4h] [ebp-24h]
  int v3; // [esp+4h] [ebp-24h]
  int v4; // [esp+4h] [ebp-24h]
  int v5; // [esp+Ch] [ebp-1Ch]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( (!v1->maskj && v1->maski > 0 || v1->maskj < 0) && v1->sit <= 3 && !v1->relaxb )
  {
    Steam::compscr((Steam *const )(v1->line - v1->missline), v1->mode, v1->st.scrindexnomiss, v5);
    thisa->missline = thisa->line;
    thisa->aliveb = 0;
    thisa->sit = 4;
    if ( thisa->dieb )
      thisa->blck[thisa->diex][thisa->diey] = 1;
    Sound::playsound((Sound *const )thisa->sd.sLose, v3);
    if ( !thisa->rightb )
      Steam::addach((Steam *const )thisa->st.achhidright, v4);
    Steam::setlead((Steam *const )thisa->mode, v4);
  }
  if ( thisa->maskj || thisa->maski || thisa->sit > 3 )
  {
    if ( thisa->aliveb )
      Steam::addach((Steam *const )thisa->st.achhidalive, v2);
  }
  else
  {
    thisa->aliveb = 1;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00404BF2; symbol: __ZN5Board7setqstnEllb
void __userpurge Board::setqstn(int a1@<ecx>, Board *const this, int x, int y, bool sb_)
{
  int v5; // [esp+4h] [ebp-24h]

  *(_BYTE *)(*(_DWORD *)(a1 + 40) + ((_DWORD)this << 7) + x) ^= 1u;
  if ( (_BYTE)y )
    Sound::playsound(*(Sound *const *)(a1 + 2072), v5);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00404C5C; symbol: __ZN5Board7setqstnEll
void __userpurge Board::setqstn(int a1@<ecx>, Board *const this, int x, int y)
{
  bool v4; // [esp+Ch] [ebp-1Ch]

  Board::setqstn(a1, this, x, 1, v4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00404C8C; symbol: __ZN5Board7setflagEll
void __userpurge Board::setflag(Board *a1@<ecx>, Board *const this, int x, int y)
{
  int v4; // [esp+4h] [ebp-44h]
  int *v5; // [esp+14h] [ebp-34h]
  Board *thisa; // [esp+2Ch] [ebp-1Ch]
  Block *k_0; // [esp+30h] [ebp-18h]
  Block *k; // [esp+34h] [ebp-14h]
  bool sc; // [esp+3Bh] [ebp-Dh]
  int qc; // [esp+3Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->sit > 0 && a1->sit <= 3 && !a1->pauseb )
  {
    qc = 0;
    sc = 0;
    for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
    {
      if ( Block::isok(thisa, k, (int)this, x, (int)&thisa->tx, &thisa->ty, v5)
        && thisa->blck[thisa->tx][thisa->ty] != 1 )
      {
        ++qc;
      }
    }
    if ( thisa->numb[(_DWORD)this][x] == qc )
    {
      for ( k_0 = 0; (signed int)k_0 <= 7; k_0 = (Block *)((char *)k_0 + 1) )
      {
        if ( Block::isok(thisa, k_0, (int)this, x, (int)&thisa->tx, &thisa->ty, v5)
          && thisa->blck[thisa->tx][thisa->ty] != 1
          && thisa->flag[thisa->tx][thisa->ty] != 1
          && thisa->mask[thisa->tx][thisa->ty] != 1 )
        {
          thisa->flag[thisa->tx][thisa->ty] = 1;
          thisa->qstn[thisa->tx][thisa->ty] = 0;
          sc = 1;
        }
      }
      if ( thisa->sb && sc )
      {
        Sound::playsound((Sound *const )thisa->sd.sFlag, v4);
        thisa->sb = 0;
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00404E94; symbol: __ZN5Board8setblockEll
void __userpurge Board::setblock(Board *a1@<ecx>, Board *const this, int x, int y)
{
  Board *v4; // [esp+0h] [ebp-58h]
  int v5; // [esp+4h] [ebp-54h]
  int v6; // [esp+8h] [ebp-50h]
  int *v7; // [esp+14h] [ebp-44h]
  Board *thisa; // [esp+2Ch] [ebp-2Ch]
  Block *k_0; // [esp+3Ch] [ebp-1Ch]
  Block *k; // [esp+40h] [ebp-18h]
  bool sr; // [esp+47h] [ebp-11h]
  int qq; // [esp+48h] [ebp-10h]
  int qn; // [esp+4Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->sit > 0 && a1->sit <= 3 && !a1->pauseb )
  {
    qn = 0;
    qq = 0;
    sr = 0;
    for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
    {
      if ( Block::isok(thisa, k, (int)this, x, (int)&thisa->tx, &thisa->ty, v7) )
      {
        if ( thisa->flag[thisa->tx][thisa->ty] )
          ++qn;
        if ( thisa->qstn[thisa->tx][thisa->ty] )
          ++qq;
      }
    }
    if ( thisa->numb[(_DWORD)this][x] == qn || qn + qq == thisa->numb[(_DWORD)this][x] )
    {
      for ( k_0 = 0; (signed int)k_0 <= 7; k_0 = (Block *)((char *)k_0 + 1) )
      {
        if ( Block::isok(thisa, k_0, (int)this, x, (int)&thisa->tx, &thisa->ty, v7)
          && thisa->blck[thisa->tx][thisa->ty] != 1
          && thisa->flag[thisa->tx][thisa->ty] != 1
          && thisa->mask[thisa->tx][thisa->ty] != 1 )
        {
          if ( thisa->qstn[thisa->tx][thisa->ty] == 1 )
          {
            if ( !thisa->mdb_ || thisa->tutb == 1 )
              thisa->qstn[thisa->tx][thisa->ty] = 0;
          }
          else
          {
            thisa->blck[thisa->tx][thisa->ty] = 1;
            thisa->qstn[thisa->tx][thisa->ty] = 0;
            sr = 1;
            thisa->solvebb = 1;
            thisa->solveb0 = 1;
            thisa->solveb1 = 1;
            thisa->solveb2 = 1;
            thisa->solveb3 = 1;
            Board::checkerror(thisa, (Board *const )thisa->tx, thisa->ty, v6);
          }
        }
      }
      if ( thisa->sb && sr )
      {
        Sound::playsound((Sound *const )thisa->sd.sRight, v5);
        thisa->sb = 0;
      }
    }
    if ( thisa->sb )
      Board::checkerror(v4);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004051BE; symbol: __ZN5Board9clicknumbEllb
void __userpurge Board::clicknumb(Board *a1@<ecx>, Board *const this, int x, int y, bool sb_)
{
  int v5; // ST08_4
  int v6; // [esp+8h] [ebp-20h]
  int v7; // [esp+8h] [ebp-20h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  a1->sb = y;
  if ( a1->sb )
    a1->rightb = 1;
  Board::setblock(a1, this, x, v6);
  if ( !thisa->mdb_ || thisa->tutb == 1 )
  {
    Board::setblock(thisa, this, x, v7);
    Board::setflag(thisa, this, x, v5);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00405264; symbol: __ZN5Board9clickleftEllb
void __userpurge Board::clickleft(Board *const this, int x, int y, bool sb_)
{
  int v4; // [esp+10h] [ebp-18h]

  Board::clickleft(this, x, (unsigned __int8)y, 3, v4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004052A2; symbol: __ZN5Board10clickrightEllb
void __userpurge Board::clickright(Board *const this, int x, int y, bool sb_)
{
  int v4; // [esp+10h] [ebp-18h]

  Board::clickright(this, x, (unsigned __int8)y, 3, v4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004052E0; symbol: __ZN5Board9clickleftEllbl
void __userpurge Board::clickleft(Board *a1@<ecx>, Board *const this, int x, int y, int sb_, int md_)
{
  bool v6; // al
  Board *v7; // [esp+0h] [ebp-28h]
  int v8; // [esp+4h] [ebp-24h]
  bool v9; // [esp+Ch] [ebp-1Ch]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->mask[(_DWORD)this][x] != 1 && a1->flag[(_DWORD)this][x] != 1 )
  {
    if ( a1->blck[(_DWORD)this][x] == 1 )
    {
      if ( (_BYTE)y )
      {
        a1->mdb_ = sb_ == 5;
        Board::clicknumb(a1, this, x, (unsigned __int8)y, v9);
        thisa->mdb_ = 0;
      }
    }
    else if ( sb_ > 2 )
    {
      a1->blck[(_DWORD)this][x] = 1;
      a1->qstn[(_DWORD)this][x] = 0;
      if ( a1->sit == 2 )
        a1->sit = 1;
      if ( a1->sit == 3 )
        a1->sit = 1;
      v6 = !Board::checkerror(v7) && (_BYTE)y;
      if ( v6 )
        Sound::playsound((Sound *const )thisa->sd.sLeft, v8);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00405448; symbol: __ZN5Board10clickrightEllbl
void __userpurge Board::clickright(Board *a1@<ecx>, Board *const this, int x, int y, int sb_, int md_)
{
  int v6; // [esp+4h] [ebp-34h]
  bool v7; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  bool qstnb; // [esp+2Fh] [ebp-9h]

  thisa = a1;
  if ( a1->mask[(_DWORD)this][x] != 1 && a1->flag[(_DWORD)this][x] != 1 )
  {
    if ( a1->blck[(_DWORD)this][x] == 1 )
    {
      if ( (_BYTE)y && sb_ != 5 )
        Board::clicknumb(a1, this, x, (unsigned __int8)y, v7);
    }
    else if ( sb_ > 2 )
    {
      Board::setqstn((int)a1, this, x, (unsigned __int8)y, v7);
    }
  }
  if ( !thisa->sit )
  {
    qstnb = 1;
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = thisa->maskj; thisa->h > j; ++j )
      {
        if ( thisa->qstn[i][j] != 1 )
          qstnb = 0;
      }
    }
    if ( qstnb )
      Steam::addach((Steam *const )thisa->st.achhidmark, v6);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00405592; symbol: __ZN5Board5pauseEv
void __cdecl Board::pause(Board *const this)
{
  Board *v1; // ecx
  Board *thisa; // [esp+Ch] [ebp-Ch]

  thisa = v1;
  if ( !v1->pauseb )
    v1->pausetime = GetTimeR() - v1->time;
  thisa->pauseb = thisa->pauseb == 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425E58; symbol: __ZN5BoardD1Ev
void __cdecl Board::~Board(Board *const this)
{
  Steam *v1; // [esp+0h] [ebp-18h]

  Steam::~Steam(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405621; symbol: __Z18CabExtractCallbackPvjjj@16
UINT __stdcall CabExtractCallback(PVOID context, UINT notification, uintptr_t param1, uintptr_t param2)
{
  if ( notification != 17 )
    return 0;
  CombinePath((char *)(param1 + 18), (const char *)context, *(const char **)param1);
  return 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：遍历 CAB 压缩包成员。
// Address: 0x00405692; symbol: __Z14ProcessCabFilePKc
BOOL __cdecl ProcessCabFile(const char *cabFilePath)
{
  BOOL result; // eax
  char nestedCabPath[260]; // [esp+18h] [ebp-4C0h]
  WIN32_FIND_DATAA findData; // [esp+180h] [ebp-358h]
  char searchPath[260]; // [esp+2C0h] [ebp-218h]
  char destFolder[260]; // [esp+3C4h] [ebp-114h]
  HANDLE hFind; // [esp+4C8h] [ebp-10h]
  DWORD errorCode; // [esp+4CCh] [ebp-Ch]

  lstrcpyA(destFolder, cabFilePath);
  RemoveExtension(destFolder);
  CreateDirectoryA(destFolder, 0);
  if ( SetupIterateCabinetA(cabFilePath, 0, CabExtractCallback, destFolder) == 0 )
  {
    errorCode = GetLastError();
    wsprintfA(nestedCabPath, "Failed to extract CAB file: %s. Error code: %lu", cabFilePath, errorCode);
    MessageBoxA(0, nestedCabPath, "Error", 0x10u);
    result = 0;
  }
  else
  {
    if ( !strstr(cabFilePath, "data.cab") )
      DeleteFileA(cabFilePath);
    CombinePath(searchPath, destFolder, "*.cab");
    hFind = FindFirstFileA(searchPath, &findData);
    if ( hFind != (HANDLE)-1 )
    {
      do
      {
        CombinePath(nestedCabPath, destFolder, findData.cFileName);
        ProcessCabFile(nestedCabPath);
      }
      while ( FindNextFileA(hFind, &findData) != 0 );
      FindClose(hFind);
    }
    result = 1;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405973; symbol: __Z22CheckAndProcessCabFilev
void CheckAndProcessCabFile()
{
  char versionFilePath[260]; // [esp+28h] [ebp-110h]
  HANDLE hMarker; // [esp+12Ch] [ebp-Ch]

  CombinePath(versionFilePath, "./data", version);
  if ( GetFileAttributesA(versionFilePath) == -1 )
  {
    DeleteFolderRecursively("./data");
    if ( GetFileAttributesA("./data.cab") != -1 && ProcessCabFile("./data.cab") != 0 )
    {
      hMarker = CreateFileA(versionFilePath, 0x40000000u, 0, 0, 2u, 0x80u, 0);
      if ( hMarker != (HANDLE)-1 )
        CloseHandle(hMarker);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409618; symbol: __ZN3LanC1Ev
void __cdecl Lan::Lan(Lan *const this)
{
  Lan *v1; // ecx
  Lan *v2; // ST1C_4
  Lan *const v3; // ST00_4
  Lan *v4; // eax
  const char *v5; // ST04_4

  v2 = v1;
  qmemcpy(v1, off_427040, 0x78u);
  qmemcpy((void *)v1->lanshortid, &unk_4270C0, sizeof(v1->lanshortid));
  v1->data = 0;
  v1->landata = 0;
  v1->landatap = 0;
  v1->LAN_TITLE = 0;
  v1->LAN_RUNNING = 1;
  v1->LAN_STEAM_LAUNCH = 2;
  v1->LAN_STEAM_FAIL = 3;
  v1->LAN_STEAM_Status = 4;
  v1->LAN_ABOUT_NAME = 5;
  v1->LAN_ABOUT_VERSION = 6;
  v1->LAN_ABOUT_AUTHOR = 7;
  v1->LAN_ABOUT_LICENSE = 8;
  v1->LAN_ABOUT_OK = 9;
  v1->LAN_LOAD_STEAM = 10;
  v1->LAN_LOAD_AUDIO = 11;
  v1->LAN_LOAD_BOARD = 12;
  v1->LAN_LOAD_GRAPH = 13;
  v1->LAN_LOAD_WINDOW = 14;
  v1->LAN_HELP = 15;
  v2->LAN_SET = v2->LAN_HELP + 20;
  v2->LAN_TUT_ = v2->LAN_SET + 23;
  v2->LAN_TUT = v2->LAN_TUT_ + 1;
  v2->LAN_MODE = v2->LAN_TUT + 15;
  v2->LAN_TUT_QUIT = v2->LAN_MODE + 5;
  v2->LAN_HELP_MENU = v2->LAN_TUT_QUIT + 3;
  v2->LAN_HELP_TITLE = v2->LAN_HELP_MENU + 20;
  v1->data = (__int16 *)calloc(0x2710u, 2u);
  v2->landata = (__int16 *)calloc(0x2710u, 2u);
  v2->landatap = (__int16 **)calloc(0x3E8u, 4u);
  v4 = (Lan *)Lan::getsyslan(v3);
  Lan::initlan(v4, v5);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409860; symbol: __ZN3Lan9getsyslanEv
const char *__cdecl Lan::getsyslan(Lan *const this)
{
  Lan *v1; // ecx
  Lan *thisa; // [esp+Ch] [ebp-1Ch]
  int lansysid; // [esp+14h] [ebp-14h]
  int k; // [esp+18h] [ebp-10h]
  const char *lansys; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  lansys = v1->lanshort[6];
  lansysid = (unsigned __int16)GetUserDefaultUILanguage();
  for ( k = 0; k <= 29; ++k )
  {
    if ( thisa->lanshortid[k] == lansysid )
      lansys = thisa->lanshort[k];
  }
  return lansys;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004098B4; symbol: __ZN3Lan7initlanEPKc
void __userpurge Lan::initlan(Lan *a1@<ecx>, Lan *const this, const char *lan)
{
  char *v3; // eax
  bool v4; // al
  Lan *thisa; // [esp+2Ch] [ebp-9Ch]
  DWORD bytesRead; // [esp+30h] [ebp-98h]
  char path[100]; // [esp+34h] [ebp-94h]
  int sequenceLength; // [esp+98h] [ebp-30h]
  HANDLE hFile; // [esp+9Ch] [ebp-2Ch]
  DWORD startTime; // [esp+A0h] [ebp-28h]
  __int16 j_; // [esp+A4h] [ebp-24h]
  __int16 j; // [esp+A6h] [ebp-22h]
  __int16 i_; // [esp+A8h] [ebp-20h]
  __int16 i; // [esp+AAh] [ebp-1Eh]
  int n; // [esp+ACh] [ebp-1Ch]
  int j_1; // [esp+B0h] [ebp-18h]
  int j_0; // [esp+B4h] [ebp-14h]
  bool match; // [esp+BBh] [ebp-Dh]
  unsigned int i_0; // [esp+BCh] [ebp-Ch]

  thisa = a1;
  strcpy(path, "./data/lan/");
  strcat(path, (const char *)this);
  v3 = &path[strlen(path)];
  *(_DWORD *)v3 = 1954051118;
  v3[4] = 0;
  startTime = GetTickCount();
  do
  {
    hFile = CreateFileA(path, 0x80000000, 1u, 0, 3u, 0x80u, 0);
    if ( hFile == (HANDLE)-1 )
      Sleep(0x64u);
    v4 = hFile == (HANDLE)-1 && GetTickCount() - startTime <= 0xBB7;
  }
  while ( v4 );
  if ( hFile == (HANDLE)-1 )
  {
    MessageBoxA(0, "Failed to load language file", "Error", 0x10u);
    ExitProcess(1u);
  }
  ReadFile(hFile, thisa->data, 0x4E20u, &bytesRead, 0);
  CloseHandle(hFile);
  sequenceLength = 8;
  for ( i_0 = 0; thisa->data[i_0] && 10000 - sequenceLength > i_0; ++i_0 )
  {
    match = 1;
    for ( j_0 = 0; j_0 < sequenceLength; ++j_0 )
    {
      if ( thisa->data[j_0 + i_0] != 120 )
      {
        match = 0;
        break;
      }
    }
    if ( match )
    {
      for ( j_1 = 0; j_1 < sequenceLength; ++j_1 )
        thisa->data[j_1 + i_0] = version[j_1];
      i_0 = sequenceLength + i_0 - 1;
    }
  }
  n = 0;
  i = 4;
  i_ = 4;
  j = 1;
  j_ = 1;
  *thisa->landata = -1;
  thisa->landata[1] = -1;
  thisa->landata[2] = 0;
  thisa->landata[3] = 0;
  for ( j = 1; thisa->data[j]; ++j )
  {
    thisa->landata[i] = thisa->data[j];
    if ( thisa->data[j] == 13 )
    {
      thisa->landata[i_ + 2147483646] = j - j_;
      thisa->landatap[n] = &thisa->landata[i_];
      thisa->landata[i++] = 0;
      thisa->landata[i++] = -1;
      thisa->landata[i++] = -1;
      thisa->landata[i++] = 0;
      ++n;
    }
    if ( thisa->data[j] == 10 )
    {
      thisa->landata[i] = 0;
      i_ = i + 1;
      j_ = j + 1;
    }
    ++i;
  }
  thisa->landata[i_ + 2147483646] = j - j_;
  thisa->landatap[n] = &thisa->landata[i_];
  thisa->landata[i] = 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409DAE; symbol: __ZN3Lan6getlanEl
__int16 *__userpurge Lan::getlan@<eax>(int a1@<ecx>, Lan *const this, int id)
{
  return *(__int16 **)(4 * (_DWORD)this + *(_DWORD *)(a1 + 248));
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B60; symbol: _GetUserDefaultUILanguage@0
int __stdcall GetUserDefaultUILanguage()
{
  return GetUserDefaultUILanguage();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409DD0; symbol: __ZN3RegC1Ev
void __cdecl Reg::Reg(Reg *const this)
{
  Reg *v1; // [esp+0h] [ebp-18h]

  Reg::openreg(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409DE6; symbol: __ZN3RegD1Ev
void __cdecl Reg::~Reg(Reg *const this)
{
  Reg *v1; // [esp+0h] [ebp-18h]

  Reg::closereg(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409DFC; symbol: __ZN3Reg7openregEv
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
// Address: 0x00409EA8; symbol: __ZN3Reg8closeregEv
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
// Address: 0x00409ED6; symbol: __ZN3Reg6setregEP6HKEY__PKcl
void __userpurge Reg::setreg(Reg *const this, HKEY key, const char *name, int value)
{
  RegSetValueExA((HKEY)this, (LPCSTR)key, 0, 4u, (const BYTE *)&name, 4u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：读取注册表值。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409F18; symbol: __ZN3Reg6getregEP6HKEY__PKcPl
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
// Address: 0x00409F7A; symbol: __ZN3Reg7setreg_EP6HKEY__PKcPc
void __userpurge Reg::setreg_(Reg *const this, HKEY key, const char *name, char *value)
{
  RegSetValueExA((HKEY)this, (LPCSTR)key, 0, 3u, (const BYTE *)name, 0x4000u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：读取注册表值。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409FBC; symbol: __ZN3Reg7getreg_EP6HKEY__PKcPc
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A048; symbol: __ZN5SoundC1Ev
void __cdecl Sound::Sound(Sound *const this)
{
  int v1; // ecx

  *(_DWORD *)(v1 + 32) = 0;
  *(_DWORD *)(v1 + 36) = &unk_42878C;
  *(_DWORD *)(v1 + 40) = "Lose";
  *(_DWORD *)(v1 + 44) = "Error";
  *(_DWORD *)(v1 + 48) = "Left";
  *(_DWORD *)(v1 + 52) = "Right";
  *(_DWORD *)(v1 + 56) = "Flag";
  *(_DWORD *)(v1 + 60) = "New";
  *(_DWORD *)(v1 + 64) = "Solve";
  *(_DWORD *)(v1 + 68) = 0;
  *(_DWORD *)(v1 + 72) = 1;
  *(_DWORD *)(v1 + 76) = 2;
  *(_DWORD *)(v1 + 80) = 3;
  *(_DWORD *)(v1 + 84) = 4;
  *(_DWORD *)(v1 + 88) = 5;
  *(_DWORD *)(v1 + 92) = 6;
  *(_DWORD *)(v1 + 96) = 7;
  *(_DWORD *)(v1 + 100) = 0;
  *(_BYTE *)(v1 + 104) = 1;
  *(_BYTE *)(v1 + 105) = 1;
  *(_DWORD *)(v1 + 108) = -256;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040A120; symbol: __ZN5Sound9initsoundEv
void __cdecl Sound::initsound(Sound *const this)
{
  Sound *const v1; // ST00_4
  Sound *const v2; // ST00_4
  Sound *v3; // [esp+0h] [ebp-18h]

  Sound::loadsound(v3);
  Sound::loadmusic(v1);
  Sound::playmusic(v2);
  painttitles = 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A154; symbol: __ZN5Sound9loadsoundEv
void __cdecl Sound::loadsound(Sound *const this)
{
  Sound *v1; // ecx
  unsigned int v2; // ecx
  Sound *thisa; // [esp+1Ch] [ebp-11Ch]
  char sPath[260]; // [esp+28h] [ebp-110h]
  int id; // [esp+12Ch] [ebp-Ch]

  thisa = v1;
  if ( (unsigned __int8)IsWin() )
  {
    for ( id = 0; id <= 7; ++id )
    {
      sprintf(sPath, "./data/wav/%s.wav", thisa->sSounds[id]);
      v2 = LoadAudio(sPath, &s2);
      thisa->sSound[id] = v2;
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 Windows MCI 音频/音乐接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A1D0; symbol: __ZN5Sound9loadmusicEv
void __cdecl Sound::loadmusic(Sound *const this)
{
  Sound *v1; // ecx
  unsigned int *v2; // ebx
  Sound *thisa; // [esp+1Ch] [ebp-11Ch]
  char sPath[260]; // [esp+20h] [ebp-118h]
  unsigned int *sMusic_; // [esp+124h] [ebp-14h]
  MCIERROR ret; // [esp+128h] [ebp-10h]
  int k; // [esp+12Ch] [ebp-Ch]

  thisa = v1;
  ret = mciSendStringA("open new type sequencer alias miditest", 0, 0, 0);
  mciSendStringA("close miditest", 0, 0, 0);
  if ( ret )
  {
    thisa->nummusic = 0;
    for ( k = 0; (unsigned __int8)IsWin(); ++k )
    {
      sprintf(sPath, "./data/mid/music%ld.mid", k + 1);
      if ( !IsFile(sPath) )
        break;
      sMusic_ = (unsigned int *)realloc(thisa->sMusic, 4 * (thisa->nummusic + 1));
      if ( !sMusic_ )
        break;
      thisa->sMusic = sMusic_;
      painttitles = (pbitmap)sPath;
      painttitleb = 2;
      v2 = &thisa->sMusic[thisa->nummusic];
      *v2 = LoadAudio(sPath, " type sequencer");
      ++thisa->nummusic;
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A340; symbol: __ZN5Sound9playsoundEl
void __userpurge Sound::playsound(Sound *a1@<ecx>, Sound *const this, int id)
{
  bool v3; // al
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  v3 = (unsigned __int8)IsWin() && thisa->soundb;
  if ( v3 )
    SetAudioPos(thisa->sSound[(_DWORD)this], 0, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A394; symbol: __ZN5Sound11switchsoundEv
void __cdecl Sound::switchsound(Sound *const this)
{
  Sound *v1; // ecx
  bool v2; // al
  int v3; // [esp+4h] [ebp-24h]
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  v1->soundb ^= 1u;
  v2 = (unsigned __int8)IsWin() && thisa->soundb;
  if ( v2 )
    Sound::playsound(thisa, (Sound *const )thisa->sLeft, v3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A3EC; symbol: __ZN5Sound9playmusicEv
void __cdecl Sound::playmusic(Sound *const this)
{
  Sound *v1; // ecx
  bool v2; // al
  Sound *thisa; // [esp+1Ch] [ebp-1Ch]
  int musici_; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->musicb )
  {
    v2 = (unsigned __int8)IsWin() && thisa->nummusic > 0;
    if ( v2 )
    {
      if ( thisa->musici != -256 && thisa->nummusic != 1 )
      {
        musici_ = rand() % (thisa->nummusic - 1);
        if ( thisa->musici <= musici_ )
          ++musici_;
        thisa->musici = musici_;
      }
      else
      {
        thisa->musici = 0;
      }
      thisa->musictime = GetTimeR();
      SetAudioPos(thisa->sMusic[thisa->musici], 0, 0);
    }
    else
    {
      thisa->musici = -256;
      thisa->musictime = 0.0;
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A4CC; symbol: __ZN5Sound10checkmusicEv
void __cdecl Sound::checkmusic(Sound *const this)
{
  Sound *v1; // ecx
  unsigned int v2; // ebx
  Sound *v3; // [esp+0h] [ebp-28h]
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->musicb && v1->musici >= 0 && v1->musici < v1->nummusic && GetTimeR() > v1->musictime )
  {
    v2 = GetAudioPos(thisa->sMusic[thisa->musici]);
    if ( v2 < GetAudioLen(thisa->sMusic[thisa->musici]) )
      thisa->musictime = thisa->musictime + 10.0;
    else
      Sound::playmusic(v3);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A584; symbol: __ZN5Sound11switchmusicEv
void __cdecl Sound::switchmusic(Sound *const this)
{
  Sound *v1; // ecx
  Sound *v2; // [esp+0h] [ebp-28h]
  int v3; // [esp+4h] [ebp-24h]
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  v1->musicb ^= 1u;
  if ( v1->musicb )
  {
    Sound::playmusic(v2);
  }
  else if ( v1->musici >= 0 && v1->musici < v1->nummusic )
  {
    StopAudio(v1->sMusic[v1->musici]);
  }
  if ( thisa->soundb )
    Sound::playsound(thisa, (Sound *const )thisa->sLeft, v3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 Windows MCI 音频/音乐接口。
// Address: 0x00423194; symbol: _mciSendStringA@16
MCIERROR __stdcall mciSendStringA(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback)
{
  return mciSendStringA(lpstrCommand, lpstrReturnString, uReturnLength, hwndCallback);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A610; symbol: __ZN5SteamC1Ev
void __cdecl Steam::Steam(Steam *const this)
{
  Steam *v1; // ecx
  Steam *v2; // ST1C_4
  Steam *const v3; // ST00_4
  Steam *const v4; // ST00_4
  Lan *v5; // [esp+0h] [ebp-38h]

  v2 = v1;
  Lan::Lan(v5);
  v2->appid = 3665840;
  v2->cheatb = 0;
  v2->achgenstart = 0;
  v2->achgencustom = 1;
  v2->achgenmode = 2;
  v2->achgenpause = 3;
  v2->achgenhelp = 4;
  v2->achhidcheat = 5;
  v2->achhidedge = 6;
  v2->achhidmark = 7;
  v2->achhidright = 8;
  v2->achhidalive = 9;
  v2->achcumdead1 = 10;
  v2->achcumdead10 = 11;
  v2->achcumdead100 = 12;
  v2->achcumdead1000 = 13;
  v2->achcumfour1 = 14;
  v2->achcumfour10 = 15;
  v2->achcumfour100 = 16;
  v2->achcumfour1000 = 17;
  v2->achcumline100 = 18;
  v2->achcumline300 = 19;
  v2->achcumline600 = 20;
  v2->achcumline1000 = 21;
  v2->achcumtotal10 = 22;
  v2->achcumtotal100 = 23;
  v2->achcumtotal1000 = 24;
  v2->achcumtotal10000 = 25;
  qmemcpy(v2->achs, off_427140, sizeof(v2->achs));
  v2->scrdead = 0;
  v2->scrfour = 1;
  v2->scrtotal = 2;
  v2->scrline = 3;
  v2->scrline1 = 4;
  v2->scrline2 = 5;
  v2->scrline3 = 6;
  v2->scrindexline = 0;
  v2->scrindexmdb = 3;
  v2->scrindexnomiss = 6;
  v2->scrindextetris = 9;
  v2->scrindexmiss = 12;
  qmemcpy(v2->scrs, off_4271C0, sizeof(v2->scrs));
  v2->newrecord = 0;
  v2->leads[0] = "1_TOP";
  v2->leads[1] = "2_TOP";
  v2->leads[2] = "3_TOP";
  v2->leads[3] = "1_TOP_N";
  v2->leads[4] = "2_TOP_N";
  v2->leads[5] = "3_TOP_N";
  v2->leads[6] = "1_TOP_D";
  v2->leads[7] = "2_TOP_D";
  v2->leads[8] = "3_TOP_D";
  v2->leads[9] = "1_TOP_T";
  v2->leads[10] = "2_TOP_T";
  v2->leads[11] = "3_TOP_T";
  v2->leads[12] = "1_TOP_M";
  v2->leads[13] = "2_TOP_M";
  v2->leads[14] = "3_TOP_M";
  v2->leadk_[0] = 20;
  v2->leadk_[1] = 15;
  v2->leadk_[2] = 1;
  v2->leadfailed = 1;
  v2->leadsn = 0;
  v2->waittime = 5.0;
  memset(v2->lead, 0, 0x78u);
  memset(v2->lead_, 0, 0x168u);
  memset(&v2->leadr, 0, 0x10u);
  memset(&v2->leadu, 0, 0x20u);
  memset(&v2->leadd, 0, 0x18u);
  memset(v2->leadb, 0, 0x78u);
  memset(v2->leaden, 0, 0x168u);
  v2->leadsn = (LeaderboardEntry_t (*)[15][20])calloc(3u, 0x2580u);
  Steam::initsteam(v3);
  Steam::loadlan(v4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x0040AA96; symbol: __ZN5SteamD1Ev
void __cdecl Steam::~Steam(Steam *const this)
{
  Steam *v1; // [esp+0h] [ebp-18h]

  Steam::exitsteam(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AAAC; symbol: __ZN5Steam9initsteamEv
void __cdecl Steam::initsteam(Steam *const this)
{
  Steam *v1; // ecx
  __int16 *v2; // ebx
  int v3; // ST04_4
  __int16 *v4; // eax
  __int16 *v5; // ebx
  int v6; // ST04_4
  __int16 *v7; // eax
  ISteamUtils *v8; // eax
  int v9; // [esp+4h] [ebp-24h]
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( (unsigned __int8)_SteamAPI_RestartAppIfNecessary(v1->appid) )
  {
    v2 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_TITLE, v9);
    v4 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_STEAM_LAUNCH, v3);
    MsgBoxW(v4, v2, 0x40u);
  }
  thisa->steamb = _SteamAPI_Init();
  if ( thisa->steamb != 1 )
  {
    v5 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_TITLE, v9);
    v7 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_STEAM_FAIL, v6);
    MsgBoxW(v7, v5, 0x30u);
  }
  if ( thisa->steamb )
  {
    v8 = SteamUtils();
    if ( (*(int (__fastcall **)(ISteamUtils *))(*(_DWORD *)v8 + 36))(v8) != thisa->appid )
      MsgBox(
        "The old game MineSweeper Tetris is retired, please download the new MineSweeper Rush from Steam Store! \n"
        "https://store.steampowered.com/app/3665840",
        "MineSweeper Rush",
        0x40u);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040ABD4; symbol: __ZN5Steam7loadlanEv
void __cdecl Steam::loadlan(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUtils *v2; // eax
  ISteamApps *v3; // eax
  const char *v4; // [esp+4h] [ebp-34h]
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  Lan *langame; // [esp+28h] [ebp-10h]
  Lan *lanui; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    v2 = SteamUtils();
    lanui = (Lan *)(*(int (__fastcall **)(ISteamUtils *))(*(_DWORD *)v2 + 92))(v2);
    v3 = SteamApps();
    langame = (Lan *)(*(int (__fastcall **)(ISteamApps *))(*(_DWORD *)v3 + 16))(v3);
    if ( !strcmp((const char *)langame, thisa->lan.lanshort[23]) )
      Lan::initlan(&thisa->lan, lanui, v4);
    else
      Lan::initlan(&thisa->lan, langame, v4);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AC56; symbol: __ZN5Steam9exitsteamEv
void __cdecl Steam::exitsteam(Steam *const this)
{
  int v1; // ecx
  ISteamUserStats *v2; // eax

  if ( *(_BYTE *)(v1 + 348) )
  {
    v2 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *))(*(_DWORD *)v2 + 40))(v2);
    _SteamAPI_Shutdown();
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AC88; symbol: __ZN5Steam9loadsteamEv
void __cdecl Steam::loadsteam(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUserStats *v2; // eax
  __int16 *v3; // ebx
  int v4; // ST04_4
  __int16 *v5; // eax
  Steam *const v6; // ST00_4
  Steam *const v7; // ST00_4
  Steam *v8; // [esp+0h] [ebp-28h]
  int v9; // [esp+4h] [ebp-24h]
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    v2 = SteamUserStats();
    if ( (**(unsigned __int8 (__fastcall ***)(ISteamUserStats *))v2)(v2) ^ 1 )
    {
      v3 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_TITLE, v9);
      v5 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_STEAM_Status, v4);
      MsgBoxW(v5, v3, 0x30u);
    }
    else
    {
      Steam::loadach(v8);
      Steam::loadscr(v6);
      Steam::loadlead(v7);
      painttitles = 0;
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AD30; symbol: __ZN5Steam8resetachEv
void __cdecl Steam::resetach(Steam *const this)
{
  int v1; // ecx
  ISteamUserStats *v2; // eax

  if ( *(_BYTE *)(v1 + 348) )
  {
    v2 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *, _DWORD))(*(_DWORD *)v2 + 84))(v2, *(_DWORD *)(*(_DWORD *)v2 + 84));
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AD64; symbol: __ZN5Steam7loadachEv
void __cdecl Steam::loadach(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUserStats *v2; // eax
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  int achid; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    painttitles = (pbitmap)"Load Achievement";
    painttitleb = 2;
    for ( achid = 0; achid <= 25; ++achid )
    {
      v2 = SteamUserStats();
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v2 + 24))(
        v2,
        thisa->lan.lanshort[achid + 112 + 2],
        thisa->lan.lanshort[achid + 112 + 2]);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040ADE2; symbol: __ZN5Steam6addachEl
void __userpurge Steam::addach(int a1@<ecx>, Steam *const this, int achid)
{
  ISteamUserStats *v3; // eax
  const char *v4; // ST04_4
  ISteamUserStats *v5; // eax
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = (Steam *)a1;
  if ( *(_BYTE *)(a1 + 348) && this->achb[a1] != 1 && (*(_BYTE *)(a1 + 349) != 1 || *(Steam *const *)(a1 + 372) == this) )
  {
    v3 = SteamUserStats();
    v4 = thisa->lan.lanshort[(_DWORD)this + 112 + 2];
    (*(void (__fastcall **)(ISteamUserStats *))(*(_DWORD *)v3 + 28))(v3);
    v5 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *, _DWORD))(*(_DWORD *)v5 + 40))(v5, *(_DWORD *)(*(_DWORD *)v5 + 40));
    this->achb[(_DWORD)thisa] = 1;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AE7C; symbol: __ZN5Steam8checkachElllllllll
void __userpurge Steam::checkach(int a1@<ecx>, Steam *const this, int scrid, int d, int c, int b, int a, int a_d, int a_c, int a_b, int a_a)
{
  int v11; // [esp+4h] [ebp-24h]

  if ( *(_BYTE *)(a1 + 348) )
  {
    if ( *(_DWORD *)(a1 + 4 * ((_DWORD)this + 176) + 8) < scrid )
    {
      if ( *(_DWORD *)(a1 + 4 * ((_DWORD)this + 176) + 8) < d )
      {
        if ( *(_DWORD *)(a1 + 4 * ((_DWORD)this + 176) + 8) < c )
        {
          if ( *(_DWORD *)(a1 + 4 * ((_DWORD)this + 176) + 8) >= b )
            Steam::addach(a1, (Steam *const )a_b, v11);
        }
        else
        {
          Steam::addach(a1, (Steam *const )a_c, v11);
        }
      }
      else
      {
        Steam::addach(a1, (Steam *const )a_d, v11);
      }
    }
    else
    {
      Steam::addach(a1, (Steam *const )a, v11);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AF42; symbol: __ZN5Steam7loadscrEv
void __cdecl Steam::loadscr(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUserStats *v2; // eax
  ISteamUserStats *v3; // eax
  Steam *v4; // [esp+0h] [ebp-38h]
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  int scrid; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    painttitles = (pbitmap)"Load Status";
    painttitleb = 2;
    for ( scrid = 0; scrid <= 18; ++scrid )
    {
      thisa->lan.lanshort[scrid + 176 + 2] = (const char *)-1;
      v2 = SteamUserStats();
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v2 + 8))(
        v2,
        thisa->lan.lanshort[scrid + 156 + 3],
        thisa->lan.lanshort[scrid + 156 + 3]);
      if ( (_DWORD)thisa->lan.lanshort[scrid + 176 + 2] < 0 )
      {
        v3 = SteamUserStats();
        (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v3 + 8))(
          v3,
          thisa->lan.lanshort[scrid + 156 + 3],
          thisa->lan.lanshort[scrid + 156 + 3]);
      }
      if ( (_DWORD)thisa->lan.lanshort[scrid + 176 + 2] < 0 )
      {
        thisa->lan.lanshort[scrid + 176 + 2] = 0;
        thisa->steamb = 0;
      }
    }
    Steam::setlead(v4);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B07E; symbol: __ZN5Steam6setscrEl
void __userpurge Steam::setscr(Steam *a1@<ecx>, Steam *const this, int scrid)
{
  ISteamUserStats *v3; // eax
  long double v4; // fst7
  int v5; // [esp+24h] [ebp-34h]
  Steam *thisa; // [esp+3Ch] [ebp-1Ch]

  thisa = a1;
  if ( a1->steamb )
  {
    if ( (_DWORD)a1->lan.lanshort[(_DWORD)this + 176 + 2] > 0 )
    {
      v3 = SteamUserStats();
      v4 = *(float *)&thisa->lan.lanshort[(_DWORD)this + 176 + 2];
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v3 + 16))(
        v3,
        thisa->lan.lanshort[(_DWORD)this + 156 + 3],
        thisa->lan.lanshort[(_DWORD)this + 156 + 3]);
    }
    if ( (Steam *const )thisa->scrdead == this )
    {
      Steam::checkach(
        (int)thisa,
        (Steam *const )thisa->scrdead,
        1000,
        100,
        10,
        1,
        thisa->achcumdead1000,
        thisa->achcumdead100,
        thisa->achcumdead10,
        thisa->achcumdead1,
        v5);
    }
    else if ( (Steam *const )thisa->scrfour == this )
    {
      Steam::checkach(
        (int)thisa,
        (Steam *const )thisa->scrfour,
        1000,
        100,
        10,
        1,
        thisa->achcumfour1000,
        thisa->achcumfour100,
        thisa->achcumfour10,
        thisa->achcumfour1,
        v5);
    }
    else if ( (Steam *const )thisa->scrtotal == this )
    {
      Steam::checkach(
        (int)thisa,
        (Steam *const )thisa->scrtotal,
        10000,
        1000,
        100,
        10,
        thisa->achcumtotal10000,
        thisa->achcumtotal1000,
        thisa->achcumtotal100,
        thisa->achcumtotal10,
        v5);
    }
    else if ( (Steam *const )thisa->scrline == this )
    {
      Steam::checkach(
        (int)thisa,
        (Steam *const )thisa->scrline,
        1000,
        600,
        300,
        100,
        thisa->achcumline1000,
        thisa->achcumline600,
        thisa->achcumline300,
        thisa->achcumline100,
        v5);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B2F8; symbol: __ZN5Steam6addscrElll
void __userpurge Steam::addscr(Steam *a1@<ecx>, Steam *const this, int scrid, int val, int mode)
{
  int v5; // [esp+4h] [ebp-24h]

  if ( a1->steamb && a1->cheatb != 1 && val > 0 )
  {
    a1->lan.lanshort[(_DWORD)this + 176 + 2] += scrid;
    Steam::setscr(a1, this, v5);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B364; symbol: __ZN5Steam6maxscrEll
void __userpurge Steam::maxscr(Steam *a1@<ecx>, Steam *const this, int val, int scrline__)
{
  const char *v4; // eax
  int v5; // [esp+4h] [ebp-24h]
  int v6; // [esp+4h] [ebp-24h]
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->steamb && (_DWORD)a1->lan.lanshort[val + 176 + 2] < (signed int)this )
  {
    a1->lan.lanshort[val + 176 + 2] = (const char *)this;
    Steam::setscr(a1, (Steam *const )val, v5);
    if ( val <= 6 )
    {
      if ( (_DWORD)thisa->lan.lanshort[thisa->scrline + 176 + 2] <= (_DWORD)thisa->lan.lanshort[val + 176 + 2] )
        v4 = thisa->lan.lanshort[val + 176 + 2];
      else
        v4 = thisa->lan.lanshort[thisa->scrline + 176 + 2];
      thisa->lan.lanshort[thisa->scrline + 176 + 2] = v4;
      Steam::setscr(thisa, (Steam *const )thisa->scrline, v6);
    }
    thisa->newrecord = 1;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B45C; symbol: __ZN5Steam7compscrElll
void __userpurge Steam::compscr(Steam *a1@<ecx>, Steam *const this, int val, int mode, int index)
{
  int v5; // [esp+8h] [ebp-30h]
  int scrline_; // [esp+2Ch] [ebp-Ch]

  if ( a1->steamb && a1->cheatb != 1 && val > 0 )
  {
    scrline_ = -1;
    switch ( val )
    {
      case 2:
        scrline_ = a1->scrline2;
        break;
      case 3:
        scrline_ = a1->scrline3;
        break;
      case 1:
        scrline_ = a1->scrline1;
        break;
    }
    if ( scrline_ > 0 )
      Steam::maxscr(a1, this, mode + scrline_, v5);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B4F6; symbol: __ZN5Steam8resetscrEv
void __cdecl Steam::resetscr(Steam *const this)
{
  int v1; // ecx
  int scrid; // [esp+10h] [ebp-4h]

  if ( *(_BYTE *)(v1 + 348) )
  {
    for ( scrid = 0; scrid <= 18; ++scrid )
      *(_DWORD *)(v1 + 4 * (scrid + 176) + 8) = 0;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B538; symbol: __ZN5Steam8loadleadEv
void __cdecl Steam::loadlead(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUserStats *v2; // eax
  int v3; // ebx
  const char *v4; // edx
  ISteamUtils *v5; // eax
  const char *v6; // edx
  int v7; // ebx
  Steam *v8; // [esp+0h] [ebp-58h]
  Steam *thisa; // [esp+2Ch] [ebp-2Ch]
  int leadid_0; // [esp+38h] [ebp-20h]
  int leadid; // [esp+3Ch] [ebp-1Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    painttitles = (pbitmap)"Load Leaderboard";
    painttitleb = 2;
    for ( leadid = 0; leadid <= 14; ++leadid )
    {
      v2 = SteamUserStats();
      v8 = (Steam *)thisa->lan.lanshort[leadid + 196 + 2];
      v3 = leadid + 108;
      thisa->lan.lanshort[2 * v3] = (const char *)(*(int (__fastcall **)(ISteamUserStats *, const char *))(*(_DWORD *)v2 + 92))(
                                                    v2,
                                                    thisa->lan.lanshort[leadid + 196 + 2]);
      thisa->lan.lanshort[2 * v3 + 1] = v4;
    }
    if ( Steam::waitlead(v8) )
    {
      for ( leadid_0 = 0; leadid_0 <= 14; ++leadid_0 )
      {
        v5 = SteamUtils();
        (*(void (__stdcall **)(const char *, const char *, LeaderboardFindResult_t *, signed int, signed int, bool *))(*(_DWORD *)v5 + 52))(
          thisa->lan.lanshort[2 * (leadid_0 + 108)],
          thisa->lan.lanshort[2 * (leadid_0 + 108) + 1],
          &thisa->leadr,
          16,
          1104,
          &thisa->leadfailed);
        v6 = (const char *)HIDWORD(thisa->leadr.m_hSteamLeaderboard);
        v7 = leadid_0 + 176;
        thisa->lan.lanshort[2 * v7 + 2] = (const char *)thisa->leadr.m_hSteamLeaderboard;
        thisa->lan.lanshort[2 * v7 + 3] = v6;
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B660; symbol: __ZN5Steam7getleadEv
void __cdecl Steam::getlead(Steam *const this)
{
  int v1; // ecx
  int v2; // edx
  ISteamUserStats *v3; // eax
  int v4; // ebx
  const char *v5; // edx
  ISteamUserStats *v6; // eax
  int v7; // ebx
  const char *v8; // edx
  ISteamUserStats *v9; // eax
  int v10; // ebx
  const char *v11; // edx
  ISteamUtils *v12; // eax
  const char *v13; // edx
  int v14; // ebx
  const char *v15; // edx
  int v16; // ecx
  ISteamUserStats *v17; // eax
  Steam *v18; // [esp+0h] [ebp-68h]
  Steam *thisa; // [esp+3Ch] [ebp-2Ch]
  int k; // [esp+40h] [ebp-28h]
  int leadid_0; // [esp+44h] [ebp-24h]
  int n; // [esp+48h] [ebp-20h]
  int leadid; // [esp+4Ch] [ebp-1Ch]

  thisa = (Steam *)v1;
  if ( *(_BYTE *)(v1 + 348) )
  {
    v2 = *(_DWORD *)(v1 + 1420);
    if ( !*(_QWORD *)(v1 + 1416) || !*(_QWORD *)(v1 + 1424) || !*(_QWORD *)(v1 + 1432) )
      Steam::loadlead(v18);
    for ( leadid = 0; leadid <= 14; ++leadid )
    {
      if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
      {
        v3 = SteamUserStats();
        v4 = leadid + 122;
        thisa->lan.lanshort[2 * v4 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, _DWORD, signed int, signed int))(*(_DWORD *)v3 + 112))(
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 2],
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 3],
                                                          0,
                                                          1,
                                                          20);
        thisa->lan.lanshort[2 * v4 + 3] = v5;
        v6 = SteamUserStats();
        v7 = leadid + 137;
        thisa->lan.lanshort[2 * v7 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, signed int, signed int))(*(_DWORD *)v6 + 112))(
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 2],
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 3],
                                                          1,
                                                          -5,
                                                          4);
        thisa->lan.lanshort[2 * v7 + 3] = v8;
        v9 = SteamUserStats();
        v10 = leadid + 152;
        thisa->lan.lanshort[2 * v10 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, _DWORD, _DWORD))(*(_DWORD *)v9 + 112))(
                                                           thisa->lan.lanshort[2 * (leadid + 176) + 2],
                                                           thisa->lan.lanshort[2 * (leadid + 176) + 3],
                                                           1,
                                                           0,
                                                           0);
        thisa->lan.lanshort[2 * v10 + 3] = v11;
      }
    }
    if ( Steam::waitlead_(v18) )
    {
      for ( n = 0; n <= 2; ++n )
      {
        for ( leadid_0 = 0; leadid_0 <= 14; ++leadid_0 )
        {
          v12 = SteamUtils();
          (*(void (__fastcall **)(ISteamUtils *, const char *, const char *, const char *, LeaderboardScoresDownloaded_t *, signed int, signed int))(*(_DWORD *)v12 + 52))(
            v12,
            thisa->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 3],
            thisa->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 2],
            thisa->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 3],
            &thisa->leadd,
            24,
            1105);
          v13 = (const char *)HIDWORD(thisa->leadd.m_hSteamLeaderboard);
          v14 = leadid_0 + 176;
          thisa->lan.lanshort[2 * v14 + 2] = (const char *)thisa->leadd.m_hSteamLeaderboard;
          thisa->lan.lanshort[2 * v14 + 3] = v13;
          v15 = (const char *)HIDWORD(thisa->leadd.m_hSteamLeaderboardEntries);
          v16 = leadid_0 + 15 * n + 192;
          thisa->lan.lanshort[2 * v16] = (const char *)thisa->leadd.m_hSteamLeaderboardEntries;
          thisa->lan.lanshort[2 * v16 + 1] = v15;
          for ( k = 0; (_DWORD)thisa->lan.lanshort[n + 212 + 1] > k; ++k )
          {
            v17 = SteamUserStats();
            (*(void (__stdcall **)(const char *, const char *, int, char *, _DWORD, _DWORD))(*(_DWORD *)v17 + 120))(
              thisa->lan.lanshort[2 * (leadid_0 + 15 * n + 192)],
              thisa->lan.lanshort[2 * (leadid_0 + 15 * n + 192) + 1],
              k,
              (char *)thisa->leadsn[n] + 32 * (k + 20 * leadid_0),
              0,
              0);
          }
        }
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040BA22; symbol: __ZN5Steam7setleadEv
void __cdecl Steam::setlead(Steam *const this)
{
  Steam *v1; // ecx
  const char *v2; // edi
  ISteamUserStats *v3; // eax
  const char *v4; // ST04_4
  int v5; // eax
  const char *v6; // edx
  const char *v7; // ecx
  const char *v8; // edx
  int v9; // eax
  ISteamUtils *v10; // eax
  const char **v11; // edx
  const char *v12; // edx
  int v13; // ebx
  Steam *v14; // [esp+0h] [ebp-68h]
  Steam *v15; // [esp+0h] [ebp-68h]
  Steam *thisa; // [esp+3Ch] [ebp-2Ch]
  int k_0; // [esp+44h] [ebp-24h]
  int k; // [esp+48h] [ebp-20h]
  int leadid; // [esp+4Ch] [ebp-1Ch]
  int leadida; // [esp+4Ch] [ebp-1Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    Steam::checkcheat(v14);
    for ( leadid = 0; leadid <= 2; ++leadid )
    {
      v2 = thisa->lan.lanshort[2 * (leadid + 176) + 3];
      if ( !*(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
        Steam::loadlead(v15);
      if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
      {
        for ( k = 0; k <= 4; ++k )
        {
          v3 = SteamUserStats();
          v4 = thisa->lan.lanshort[2 * (3 * k + leadid + 176) + 3];
          v5 = (*(int (__fastcall **)(ISteamUserStats *, const char *, const char *, const char *, signed int, const char *, _DWORD))(*(_DWORD *)v3 + 124))(
                 v3,
                 v4,
                 thisa->lan.lanshort[2 * (3 * k + leadid + 176) + 2],
                 v4,
                 1,
                 thisa->lan.lanshort[3 * k + leadid + 180 + 2],
                 0);
          v7 = v6;
          v8 = (const char *)v5;
          v9 = 3 * k + leadid + 108;
          thisa->lan.lanshort[2 * v9] = v8;
          thisa->lan.lanshort[2 * v9 + 1] = v7;
        }
      }
    }
    if ( Steam::waitlead(v15) )
    {
      for ( leadida = 0; leadida <= 2; ++leadida )
      {
        if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadida + 176) + 2] )
        {
          for ( k_0 = 0; k_0 <= 4; ++k_0 )
          {
            v10 = SteamUtils();
            v11 = &thisa->lan.lanshort[2 * (3 * k_0 + leadida + 108)];
            (*(void (__fastcall **)(ISteamUtils *, const char *, const char *, const char *, LeaderboardScoreUploaded_t *, signed int, signed int))(*(_DWORD *)v10 + 52))(
              v10,
              v11[1],
              *v11,
              v11[1],
              &thisa->leadu,
              32,
              1106);
            v12 = (const char *)HIDWORD(thisa->leadu.m_hSteamLeaderboard);
            v13 = 3 * k_0 + leadida + 176;
            thisa->lan.lanshort[2 * v13 + 2] = (const char *)thisa->leadu.m_hSteamLeaderboard;
            thisa->lan.lanshort[2 * v13 + 3] = v12;
          }
        }
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040BC9C; symbol: __ZN5Steam7setleadEl
void __userpurge Steam::setlead(Steam *a1@<ecx>, Steam *const this, int mode)
{
  const char *v3; // edx
  ISteamUserStats *v4; // eax
  int v5; // ebx
  const char *v6; // edx
  Steam *const v7; // ST00_4
  ISteamUtils *v8; // eax
  const char **v9; // edx
  const char *v10; // edx
  int v11; // ebx
  Steam *v12; // [esp+0h] [ebp-58h]
  Steam *v13; // [esp+0h] [ebp-58h]
  Steam *thisa; // [esp+2Ch] [ebp-2Ch]
  int leadid; // [esp+38h] [ebp-20h]
  int k; // [esp+3Ch] [ebp-1Ch]

  thisa = a1;
  if ( a1->steamb )
  {
    Steam::checkcheat(v12);
    if ( (signed int)this > 0 )
    {
      if ( thisa->newrecord )
      {
        thisa->newrecord = 0;
        leadid = (int)&this[-1].waittime + 7;
        if ( !*(_QWORD *)&thisa->lan.lanshort[2 * ((_DWORD)this + 175) + 2] )
          Steam::loadlead(v13);
        v3 = thisa->lan.lanshort[2 * (leadid + 176) + 3];
        if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
        {
          for ( k = 0; k <= 4; ++k )
          {
            v4 = SteamUserStats();
            v5 = 3 * k + leadid + 108;
            thisa->lan.lanshort[2 * v5] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, const char *, _DWORD, _DWORD))(*(_DWORD *)v4 + 124))(
                                                          thisa->lan.lanshort[2 * (leadid + 3 * k + 176) + 2],
                                                          thisa->lan.lanshort[2 * (leadid + 3 * k + 176) + 3],
                                                          1,
                                                          thisa->lan.lanshort[3 * k + leadid + 180 + 2],
                                                          0,
                                                          0);
            thisa->lan.lanshort[2 * v5 + 1] = v6;
            if ( Steam::waitlead(v7) )
            {
              v8 = SteamUtils();
              v9 = &thisa->lan.lanshort[2 * (leadid + 3 * k + 108)];
              (*(void (__stdcall **)(const char *, const char *, LeaderboardScoreUploaded_t *, signed int, signed int, bool *))(*(_DWORD *)v8 + 52))(
                *v9,
                v9[1],
                &thisa->leadu,
                32,
                1106,
                &thisa->leadfailed);
              v10 = (const char *)HIDWORD(thisa->leadu.m_hSteamLeaderboard);
              v11 = 3 * k + leadid + 176;
              thisa->lan.lanshort[2 * v11 + 2] = (const char *)thisa->leadu.m_hSteamLeaderboard;
              thisa->lan.lanshort[2 * v11 + 3] = v10;
            }
          }
        }
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040BEB6; symbol: __ZN5Steam8waitleadEv
bool __cdecl Steam::waitlead(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUtils *v2; // eax
  bool v3; // al
  ISteamUtils *v4; // eax
  bool v5; // al
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  int time; // [esp+24h] [ebp-14h]
  int leadid; // [esp+28h] [ebp-10h]
  char waitb; // [esp+2Fh] [ebp-9h]

  thisa = v1;
  if ( !v1->steamb )
    return 0;
  waitb = 1;
  time = (signed int)GetTimeR();
  for ( leadid = 0; leadid <= 14; ++leadid )
  {
    while ( 1 )
    {
      v3 = 0;
      if ( (unsigned __int8)IsWin() )
      {
        v2 = SteamUtils();
        if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v2 + 44))(
               thisa->lan.lanshort[2 * (leadid + 108)],
               thisa->lan.lanshort[2 * (leadid + 108) + 1],
               &thisa->leadfailed) ^ 1 )
        {
          if ( (long double)time + thisa->waittime > GetTimeR() )
            v3 = 1;
        }
      }
      if ( !v3 )
        break;
      Delay(1u);
    }
    v5 = 0;
    if ( waitb )
    {
      v4 = SteamUtils();
      if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v4 + 44))(
             thisa->lan.lanshort[2 * (leadid + 108)],
             thisa->lan.lanshort[2 * (leadid + 108) + 1],
             &thisa->leadfailed) )
      {
        v5 = 1;
      }
    }
    waitb = v5;
  }
  return waitb;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040BFF0; symbol: __ZN5Steam9waitlead_Ev
bool __cdecl Steam::waitlead_(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUtils *v2; // eax
  bool v3; // al
  ISteamUtils *v4; // eax
  bool v5; // al
  Steam *thisa; // [esp+1Ch] [ebp-2Ch]
  int time; // [esp+20h] [ebp-28h]
  int leadid; // [esp+24h] [ebp-24h]
  int n; // [esp+28h] [ebp-20h]
  char waitb; // [esp+2Fh] [ebp-19h]

  thisa = v1;
  if ( !v1->steamb )
    return 0;
  waitb = 1;
  time = (signed int)GetTimeR();
  for ( n = 0; n <= 2; ++n )
  {
    for ( leadid = 0; leadid <= 14; ++leadid )
    {
      while ( 1 )
      {
        v3 = 0;
        if ( (unsigned __int8)IsWin() )
        {
          v2 = SteamUtils();
          if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v2 + 44))(
                 thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 2],
                 thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 3],
                 &thisa->leadfailed) ^ 1 )
          {
            if ( (long double)time + thisa->waittime > GetTimeR() )
              v3 = 1;
          }
        }
        if ( !v3 )
          break;
        Delay(1u);
      }
      v5 = 0;
      if ( waitb )
      {
        v4 = SteamUtils();
        if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v4 + 44))(
               thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 2],
               thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 3],
               &thisa->leadfailed) )
        {
          v5 = 1;
        }
      }
      waitb = v5;
    }
  }
  return waitb;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040C160; symbol: __ZN5Steam7savescrEPc
void __userpurge Steam::savescr(int a1@<ecx>, Steam *const this, char *scrpath)
{
  ISteamScreenshots *v3; // ebx
  void (__fastcall *v4)(ISteamScreenshots *, int, Steam *const , _DWORD, unsigned int); // esi
  unsigned int v5; // edi
  pbitmap v6; // eax
  int v7; // edx

  if ( *(_BYTE *)(a1 + 348) )
  {
    v3 = SteamScreenshots();
    v4 = *(void (__fastcall **)(ISteamScreenshots *, int, Steam *const , _DWORD, unsigned int))(*(_DWORD *)v3 + 4);
    v5 = GetWin()->Height;
    v6 = GetWin();
    v4(v3, v7, this, 0, v6->Width);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040C1C2; symbol: __ZN5Steam7ischeatEll
signed int __userpurge Steam::ischeat@<eax>(Steam *const this, int line, int tetris)
{
  if ( (signed int)this > 9998 )
    return 1;
  if ( (signed int)this <= 3000 || line > 98 && line <= 998 )
    return 0;
  return 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040C204; symbol: __ZN5Steam7ischeatEv
bool __cdecl Steam::ischeat(Steam *const this)
{
  int v1; // ecx

  return Steam::ischeat(*(Steam *const *)(v1 + 728), *(_DWORD *)(v1 + 764), v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x0040C236; symbol: __ZN5Steam10checkcheatEv
void __cdecl Steam::checkcheat(Steam *const this)
{
  Steam *const v1; // ST00_4
  Steam *v2; // [esp+0h] [ebp-18h]
  Steam *v3; // [esp+0h] [ebp-18h]

  if ( Steam::ischeat(v2) )
  {
    Steam::resetscr(v3);
    Steam::resetach(v1);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425C28; symbol: __Z10SteamUtilsv
ISteamUtils *SteamUtils()
{
  return *(ISteamUtils **)_SteamInternal_ContextInit(SteamUtils(void)::s_CallbackCounterAndContext);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425C40; symbol: __Z12SteamFriendsv
ISteamFriends *SteamFriends()
{
  return *(ISteamFriends **)_SteamInternal_ContextInit(SteamFriends(void)::s_CallbackCounterAndContext);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425C58; symbol: __Z14SteamUserStatsv
ISteamUserStats *SteamUserStats()
{
  return *(ISteamUserStats **)_SteamInternal_ContextInit(SteamUserStats(void)::s_CallbackCounterAndContext);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425C70; symbol: __Z16SteamScreenshotsv
ISteamScreenshots *SteamScreenshots()
{
  return *(ISteamScreenshots **)_SteamInternal_ContextInit(SteamScreenshots(void)::s_CallbackCounterAndContext);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425C88; symbol: __Z18SteamRemoteStoragev
ISteamRemoteStorage *SteamRemoteStorage()
{
  return *(ISteamRemoteStorage **)_SteamInternal_ContextInit(SteamRemoteStorage(void)::s_CallbackCounterAndContext);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425CA0; symbol: __Z28SteamInternal_Init_SteamAppsPP10ISteamApps
void __cdecl SteamInternal_Init_SteamApps(ISteamApps **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamApps *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMAPPS_INTERFACE_VERSION008");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425CCC; symbol: __Z29SteamInternal_Init_SteamUtilsPP11ISteamUtils
void __cdecl SteamInternal_Init_SteamUtils(ISteamUtils **p)
{
  *p = (ISteamUtils *)_SteamInternal_FindOrCreateUserInterface(0, "SteamUtils010");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425CF4; symbol: __Z31SteamInternal_Init_SteamFriendsPP13ISteamFriends
void __cdecl SteamInternal_Init_SteamFriends(ISteamFriends **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamFriends *)_SteamInternal_FindOrCreateUserInterface(v1, "SteamFriends017");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425D20; symbol: __Z33SteamInternal_Init_SteamUserStatsPP15ISteamUserStats
void __cdecl SteamInternal_Init_SteamUserStats(ISteamUserStats **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamUserStats *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMUSERSTATS_INTERFACE_VERSION012");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425D4C; symbol: __Z35SteamInternal_Init_SteamScreenshotsPP17ISteamScreenshots
void __cdecl SteamInternal_Init_SteamScreenshots(ISteamScreenshots **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamScreenshots *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMSCREENSHOTS_INTERFACE_VERSION003");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425D78; symbol: __Z37SteamInternal_Init_SteamRemoteStoragePP19ISteamRemoteStorage
void __cdecl SteamInternal_Init_SteamRemoteStorage(ISteamRemoteStorage **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamRemoteStorage *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMREMOTESTORAGE_INTERFACE_VERSION016");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425DA4; symbol: __Z9SteamAppsv
ISteamApps *SteamApps()
{
  return *(ISteamApps **)_SteamInternal_ContextInit(SteamApps(void)::s_CallbackCounterAndContext);
}



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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425E40; symbol: __ZN18LeaderboardEntry_tC1Ev
void __cdecl LeaderboardEntry_t::LeaderboardEntry_t(LeaderboardEntry_t *const this)
{
  CSteamID *v1; // [esp+0h] [ebp-18h]

  CSteamID::CSteamID(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00425E74; symbol: __ZN7Gdiplus11GdiplusBaseC2Ev
void __cdecl Gdiplus::GdiplusBase::GdiplusBase(Gdiplus::GdiplusBase *const this)
{
  ;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00425E80; symbol: __ZN7Gdiplus11GdiplusBasedlEPv
void __cdecl Gdiplus::GdiplusBase::operator delete(void *in_pVoid)
{
  GdipFree((int)in_pVoid);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00425E98; symbol: __ZN7Gdiplus11GdiplusBasenwEj
void *__cdecl Gdiplus::GdiplusBase::operator new(size_t in_size)
{
  return (void *)GdipAlloc(in_size);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425EB0; symbol: __ZN7Gdiplus12CachedBitmapD0Ev
void __cdecl Gdiplus::CachedBitmap::~CachedBitmap(Gdiplus::CachedBitmap *const this)
{
  Gdiplus::CachedBitmap *v1; // ecx
  Gdiplus::CachedBitmap *v2; // ST1C_4
  Gdiplus::CachedBitmap *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::CachedBitmap::~CachedBitmap(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425ED0; symbol: __ZN7Gdiplus12CachedBitmapD1Ev
void __cdecl Gdiplus::CachedBitmap::~CachedBitmap(Gdiplus::CachedBitmap *const this)
{
  _DWORD *v1; // ecx

  *v1 = off_429DC4;
  GdipDeleteCachedBitmap(v1[1]);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425EF8; symbol: __ZN7Gdiplus13CustomLineCapD0Ev
void __cdecl Gdiplus::CustomLineCap::~CustomLineCap(Gdiplus::CustomLineCap *const this)
{
  Gdiplus::CustomLineCap *v1; // ecx
  Gdiplus::CustomLineCap *v2; // ST1C_4
  Gdiplus::CustomLineCap *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::CustomLineCap::~CustomLineCap(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425F18; symbol: __ZN7Gdiplus13CustomLineCapD1Ev
void __cdecl Gdiplus::CustomLineCap::~CustomLineCap(Gdiplus::CustomLineCap *const this)
{
  _DWORD *v1; // ecx

  *v1 = off_429DD4;
  GdipDeleteCustomLineCap(v1[1]);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425F40; symbol: __ZN7Gdiplus14FontCollectionD0Ev
void __cdecl Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  Gdiplus::FontCollection *v1; // ecx
  Gdiplus::FontCollection *v2; // ST1C_4
  Gdiplus::FontCollection *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::FontCollection::~FontCollection(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425F60; symbol: __ZN7Gdiplus14FontCollectionD1Ev
void __cdecl Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  _DWORD *v1; // ecx

  *v1 = off_429DE4;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425F78; symbol: __ZN7Gdiplus14FontCollectionD2Ev
void __cdecl Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  _DWORD *v1; // ecx

  *v1 = off_429DE4;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425F90; symbol: .weak.__ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii.__ZN7Gdiplus11GdiplusBasedlEPv
void __userpurge weak___ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii___ZN7Gdiplus11GdiplusBasedlEPv(_DWORD *a1@<ecx>, Gdiplus::GdiplusStartupInput *const this, Gdiplus::DebugEventProc debugEventCallback, BOOL suppressBackgroundThread, BOOL suppressExternalCodecs)
{
  *a1 = 1;
  a1[1] = this;
  a1[2] = debugEventCallback;
  a1[3] = suppressBackgroundThread;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425FC4; symbol: __ZN7Gdiplus21PrivateFontCollectionD0Ev
void __cdecl Gdiplus::PrivateFontCollection::~PrivateFontCollection(Gdiplus::PrivateFontCollection *const this)
{
  Gdiplus::PrivateFontCollection *v1; // ecx
  Gdiplus::PrivateFontCollection *v2; // ST1C_4
  Gdiplus::PrivateFontCollection *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::PrivateFontCollection::~PrivateFontCollection(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425FE4; symbol: __ZN7Gdiplus21PrivateFontCollectionD1Ev
void __cdecl Gdiplus::PrivateFontCollection::~PrivateFontCollection(Gdiplus::PrivateFontCollection *const this)
{
  _DWORD *v1; // ecx
  Gdiplus::FontCollection *const v2; // ST00_4

  *v1 = off_429DF4;
  GdipDeletePrivateFontCollection((int)(v1 + 1));
  Gdiplus::FontCollection::~FontCollection(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426018; symbol: __ZN7Gdiplus23InstalledFontCollectionD0Ev
void __cdecl Gdiplus::InstalledFontCollection::~InstalledFontCollection(Gdiplus::InstalledFontCollection *const this)
{
  Gdiplus::InstalledFontCollection *v1; // ecx
  Gdiplus::InstalledFontCollection *v2; // ST1C_4
  Gdiplus::InstalledFontCollection *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::InstalledFontCollection::~InstalledFontCollection(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426038; symbol: __ZN7Gdiplus23InstalledFontCollectionD1Ev
void __cdecl Gdiplus::InstalledFontCollection::~InstalledFontCollection(Gdiplus::InstalledFontCollection *const this)
{
  _DWORD *v1; // ecx
  Gdiplus::FontCollection *v2; // [esp+0h] [ebp-18h]

  *v1 = off_429E04;
  Gdiplus::FontCollection::~FontCollection(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426058; symbol: __ZN7Gdiplus5Image14SetNativeImageEPNS_7GpImageE
void __userpurge Gdiplus::Image::SetNativeImage(int a1@<ecx>, Gdiplus::Image *const this, Gdiplus::GpImage *nativeImage)
{
  *(_DWORD *)(a1 + 4) = this;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426070; symbol: __ZN7Gdiplus5Image5CloneEv
Gdiplus::Image *__cdecl Gdiplus::Image::Clone(Gdiplus::Image *const this)
{
  int v1; // ecx
  Gdiplus::Image *v2; // ST1C_4
  const Gdiplus::Image *v3; // eax
  Gdiplus::Status v4; // ST04_4
  Gdiplus::Image *v5; // ebx
  Gdiplus::Status v7; // [esp+8h] [ebp-30h]
  Gdiplus::GpImage *cloneimage; // [esp+2Ch] [ebp-Ch]

  v2 = (Gdiplus::Image *)v1;
  cloneimage = 0;
  v3 = (const Gdiplus::Image *)GdipCloneImage(*(_DWORD *)(v1 + 4), (int)&cloneimage);
  Gdiplus::Image::SetStatus(v3, v4);
  v5 = (Gdiplus::Image *)Gdiplus::GdiplusBase::operator new(0x10u);
  Gdiplus::Image::Image((Gdiplus::Image *const )cloneimage, (Gdiplus::GpImage *)v2->lastResult, v7);
  return v5;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004260DC; symbol: __ZN7Gdiplus5ImageC1EPNS_7GpImageENS_6StatusE
void __userpurge Gdiplus::Image::Image(Gdiplus::Image *a1@<ecx>, Gdiplus::Image *const this, Gdiplus::GpImage *nativeImage, Gdiplus::Status status)
{
  Gdiplus::Image *v4; // ST1C_4
  Gdiplus::GdiplusBase *v5; // [esp+0h] [ebp-28h]
  Gdiplus::GpImage *v6; // [esp+4h] [ebp-24h]

  v4 = a1;
  Gdiplus::GdiplusBase::GdiplusBase(v5);
  v4->_vptr_Image = (int (**)(...))off_429E14;
  Gdiplus::Image::SetNativeImage((int)v4, this, v6);
  v4->lastResult = (Gdiplus::Status)nativeImage;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0042611C; symbol: __ZN7Gdiplus5ImageD0Ev
void __cdecl Gdiplus::Image::~Image(Gdiplus::Image *const this)
{
  Gdiplus::Image *v1; // ecx
  Gdiplus::Image *v2; // ST1C_4
  Gdiplus::Image *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::Image::~Image(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0042613C; symbol: __ZN7Gdiplus5ImageD1Ev
void __cdecl Gdiplus::Image::~Image(Gdiplus::Image *const this)
{
  _DWORD *v1; // ecx

  *v1 = off_429E14;
  GdipDisposeImage(v1[1]);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426510; symbol: __ZNK7Gdiplus5Image9SetStatusENS_6StatusE
Gdiplus::Status __userpurge Gdiplus::Image::SetStatus@<eax>(int a1@<ecx>, const Gdiplus::Image *const this, Gdiplus::Status status)
{
  if ( !this )
    return 0;
  *(_DWORD *)(a1 + 8) = this;
  return *(_DWORD *)(a1 + 8);
}



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


