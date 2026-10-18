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


