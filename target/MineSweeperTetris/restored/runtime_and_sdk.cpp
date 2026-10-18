// 编译器运行库、SDK 内联函数及无源文件归属的导出。
// 0x00401000 TopLevelExceptionFilter
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


// 0x004011B0 sub_4011B0
void __noreturn sub_4011B0()
{
  int v0; // ST08_4
  int v1; // ebx

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
  v0 = *(_DWORD *)__p__environ();
  v1 = main_0(_argc);
  _cexit();
  ExitProcess(v1);
}


// 0x004012A0 __mingw32_init_mainargs
int _mingw32_init_mainargs()
{
  char v1; // [esp+28h] [ebp-14h]
  int v2; // [esp+2Ch] [ebp-10h]

  v2 = 0;
  return __getmainargs((int)&_argc, (int)&_argv, (int)&v1, _CRT_glob & 1, (int)&v2);
}


// 0x004012E0 _mainCRTStartup
void __noreturn mainCRTStartup()
{
  ___set_app_type(1);
  sub_4011B0();
}


// 0x00401300 _WinMainCRTStartup
void __noreturn WinMainCRTStartup()
{
  ___set_app_type(2);
  sub_4011B0();
}


// 0x00401320 _atexit
int __cdecl atexit(void (__cdecl *a1)())
{
  return _atexit(a1);
}


// 0x00401330 __onexit
_onexit_t __cdecl _onexit(_onexit_t a1)
{
  return __onexit(a1);
}


// 0x00401340 ___gcc_register_frame
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
    _data_start__ = (int (__cdecl *)(_DWORD))GetProcAddress(v1, "__deregister_frame_info");
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


// 0x00401430 ___gcc_deregister_frame
void __cdecl __gcc_deregister_frame()
{
  if ( _data_start__ )
    _data_start__(&__EH_FRAME_BEGIN__);
  if ( hmod_libgcc )
    FreeLibrary(hmod_libgcc);
}


// 0x00423184 _timeEndPeriod@4
MMRESULT __stdcall timeEndPeriod(UINT uPeriod)
{
  return timeEndPeriod(uPeriod);
}


// 0x0042318C _timeBeginPeriod@4
MMRESULT __stdcall timeBeginPeriod(UINT uPeriod)
{
  return timeBeginPeriod(uPeriod);
}


// 0x00423194 _mciSendStringA@16
MCIERROR __stdcall mciSendStringA(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback)
{
  return mciSendStringA(lpstrCommand, lpstrReturnString, uReturnLength, hwndCallback);
}


// 0x0042319C _GdiplusStartup@12
int __stdcall GdiplusStartup(int a1, int a2, int a3)
{
  return GdiplusStartup(a1, a2, a3);
}


// 0x004231A4 _GdiplusShutdown@4
int __stdcall GdiplusShutdown(int a1)
{
  return GdiplusShutdown(a1);
}


// 0x004231AC _GdipSaveImageToFile@16
int __stdcall GdipSaveImageToFile(int a1, int a2, int a3, int a4)
{
  return GdipSaveImageToFile(a1, a2, a3, a4);
}


// 0x004231B4 _GdipLoadImageFromFile@8
int __stdcall GdipLoadImageFromFile(int a1, int a2)
{
  return GdipLoadImageFromFile(a1, a2);
}


// 0x004231BC _GdipGetImageWidth@8
int __stdcall GdipGetImageWidth(int a1, int a2)
{
  return GdipGetImageWidth(a1, a2);
}


// 0x004231C4 _GdipGetImageHeight@8
int __stdcall GdipGetImageHeight(int a1, int a2)
{
  return GdipGetImageHeight(a1, a2);
}


// 0x004231CC _GdipFree@4
int __stdcall GdipFree(int a1)
{
  return GdipFree(a1);
}


// 0x004231D4 _GdipDrawImageRect@24
int __stdcall GdipDrawImageRect(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return GdipDrawImageRect(a1, a2, a3, a4, a5, a6);
}


// 0x004231DC _GdipDisposeImage@4
int __stdcall GdipDisposeImage(int a1)
{
  return GdipDisposeImage(a1);
}


// 0x004231E4 _GdipDeletePrivateFontCollection@4
int __stdcall GdipDeletePrivateFontCollection(int a1)
{
  return GdipDeletePrivateFontCollection(a1);
}


// 0x004231EC _GdipDeleteGraphics@4
int __stdcall GdipDeleteGraphics(int a1)
{
  return GdipDeleteGraphics(a1);
}


// 0x004231F4 _GdipDeleteCustomLineCap@4
int __stdcall GdipDeleteCustomLineCap(int a1)
{
  return GdipDeleteCustomLineCap(a1);
}


// 0x004231FC _GdipDeleteCachedBitmap@4
int __stdcall GdipDeleteCachedBitmap(int a1)
{
  return GdipDeleteCachedBitmap(a1);
}


// 0x00423204 _GdipCreateFromHDC@8
int __stdcall GdipCreateFromHDC(int a1, int a2)
{
  return GdipCreateFromHDC(a1, a2);
}


// 0x0042320C _GdipCreateBitmapFromHBITMAP@12
int __stdcall GdipCreateBitmapFromHBITMAP(int a1, int a2, int a3)
{
  return GdipCreateBitmapFromHBITMAP(a1, a2, a3);
}


// 0x00423214 _GdipCloneImage@8
int __stdcall GdipCloneImage(int a1, int a2)
{
  return GdipCloneImage(a1, a2);
}


// 0x0042321C _GdipAlloc@4
int __stdcall GdipAlloc(int a1)
{
  return GdipAlloc(a1);
}


// 0x00423224 _TextOutA@20
BOOL __stdcall TextOutA(HDC a1, int a2, int a3, LPCSTR a4, int a5)
{
  return TextOutA(a1, a2, a3, a4, a5);
}


// 0x0042322C _StretchBlt@44
BOOL __stdcall StretchBlt(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, DWORD a11)
{
  return StretchBlt(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}


// 0x00423234 _SetTextColor@8
COLORREF __stdcall SetTextColor(HDC a1, COLORREF a2)
{
  return SetTextColor(a1, a2);
}


// 0x0042323C _SetPixel@16
COLORREF __stdcall SetPixel(HDC a1, int a2, int a3, COLORREF a4)
{
  return SetPixel(a1, a2, a3, a4);
}


// 0x00423244 _SetBkMode@8
int __stdcall SetBkMode(HDC a1, int a2)
{
  return SetBkMode(a1, a2);
}


// 0x0042324C _SetBkColor@8
COLORREF __stdcall SetBkColor(HDC a1, COLORREF a2)
{
  return SetBkColor(a1, a2);
}


// 0x00423254 _SelectObject@8
HGDIOBJ __stdcall SelectObject(HDC a1, HGDIOBJ a2)
{
  return SelectObject(a1, a2);
}


// 0x0042325C _MoveToEx@16
BOOL __stdcall MoveToEx(HDC a1, int a2, int a3, LPPOINT a4)
{
  return MoveToEx(a1, a2, a3, a4);
}


// 0x00423264 _LineTo@12
BOOL __stdcall LineTo(HDC a1, int a2, int a3)
{
  return LineTo(a1, a2, a3);
}


// 0x0042326C _GetTextMetricsA@8
BOOL __stdcall GetTextMetricsA(HDC a1, LPTEXTMETRICA a2)
{
  return GetTextMetricsA(a1, a2);
}


// 0x00423274 _GetTextExtentPoint32A@16
BOOL __stdcall GetTextExtentPoint32A(HDC a1, LPCSTR a2, int a3, LPSIZE a4)
{
  return GetTextExtentPoint32A(a1, a2, a3, a4);
}


// 0x0042327C _GetStockObject@4
HGDIOBJ __stdcall GetStockObject(int a1)
{
  return GetStockObject(a1);
}


// 0x00423284 _GetPixel@12
COLORREF __stdcall GetPixel(HDC a1, int a2, int a3)
{
  return GetPixel(a1, a2, a3);
}


// 0x0042328C _GetDeviceCaps@8
int __stdcall GetDeviceCaps(HDC a1, int a2)
{
  return GetDeviceCaps(a1, a2);
}


// 0x00423294 _DeleteObject@4
BOOL __stdcall DeleteObject(HGDIOBJ a1)
{
  return DeleteObject(a1);
}


// 0x0042329C _DeleteDC@4
BOOL __stdcall DeleteDC(HDC a1)
{
  return DeleteDC(a1);
}


// 0x004232A4 _CreateSolidBrush@4
HBRUSH __stdcall CreateSolidBrush(COLORREF a1)
{
  return CreateSolidBrush(a1);
}


// 0x004232AC _CreatePen@12
HPEN __stdcall CreatePen(int a1, int a2, COLORREF a3)
{
  return CreatePen(a1, a2, a3);
}


// 0x004232B4 _CreateFontA@56
HFONT __stdcall CreateFontA(int a1, int a2, int a3, int a4, int a5, DWORD a6, DWORD a7, DWORD a8, DWORD a9, DWORD a10, DWORD a11, DWORD a12, DWORD a13, LPCSTR a14)
{
  return CreateFontA(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
}


// 0x004232BC _CreateCompatibleDC@4
HDC __stdcall CreateCompatibleDC(HDC a1)
{
  return CreateCompatibleDC(a1);
}


// 0x004232C4 _CreateCompatibleBitmap@12
HBITMAP __stdcall CreateCompatibleBitmap(HDC a1, int a2, int a3)
{
  return CreateCompatibleBitmap(a1, a2, a3);
}


// 0x004232CC _TransparentBlt@44
BOOL __stdcall TransparentBlt(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, UINT a11)
{
  return TransparentBlt(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}


// 0x004232D4 _AlphaBlend@44
BOOL __stdcall AlphaBlend(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, BLENDFUNCTION a11)
{
  return AlphaBlend(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}


// 0x004232E0 __setargv
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


// 0x00423680 ___cpu_features_init
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


// 0x00423760 ___do_global_dtors
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


// 0x00423790 ___do_global_ctors
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


// 0x004237E0 ___main
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


// 0x00423800 TlsCallback_1
signed int __stdcall TlsCallback_1(int a1, int a2, int a3)
{
  if ( a2 != 3 && a2 )
    return 1;
  __mingw_TLScallback(a1, a2);
  return 1;
}


// 0x00423850 ___dyn_tls_init@12
signed int __stdcall __dyn_tls_init(int a1, int a2, int a3)
{
  if ( _CRT_MT != 2 )
    _CRT_MT = 2;
  if ( a2 != 2 && a2 == 1 )
    __mingw_TLScallback(a1, 1u);
  return 1;
}


// 0x004238E0 ___tlregdtor
int __tlregdtor()
{
  return 0;
}


// 0x004238F0 sub_4238F0
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


// 0x00423950 ____w64_mingwthr_add_key_dtor
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


// 0x004239E0 ____w64_mingwthr_remove_key_dtor
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


// 0x00423A80 ___mingw_TLScallback
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


// 0x00423B20 sub_423B20
void __noreturn sub_423B20(char *a1, ...)
{
  va_list va; // [esp+24h] [ebp+8h]

  va_start(va, a1);
  fwrite("Mingw runtime failure:\n", 1u, 0x17u, &__iob[2]);
  vfprintf(&__iob[2], a1, va);
  abort();
}


// 0x00423B70 sub_423B70
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


// 0x00423C60 __pei386_runtime_relocator
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


// 0x00423E30 ___chkstk_ms
void __usercall __chkstk_ms(unsigned int a1@<eax>, int a2@<ecx>, char a3)
{
  char *v3; // ecx
  unsigned int v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v5 = a2;
  v4 = a1;
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


// 0x00423E60 _fesetenv
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


// 0x00423ED0 sub_423ED0
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


// 0x00423F70 sub_423F70
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


// 0x00423FE0 sub_423FE0
char *__usercall sub_423FE0@<eax>(char *a1@<eax>, int a2@<edx>, __int16 a3@<cx>)
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
        return v3 + 1;
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
                return v14 + 1;
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
            return v3 + 1;
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
      return v14 + 1;
    while ( v15 == 127 )
    {
      if ( !(v22 & 0x20) )
      {
        v15 = (v14++)[1];
        break;
      }
      v15 = *++v14;
      if ( *v14 == 93 )
        return v14 + 1;
    }
    ++v14;
    if ( !v15 )
      return 0;
  }
}


// 0x004242A0 sub_4242A0
int __usercall sub_4242A0@<eax>(char *a1@<eax>, _BYTE *a2@<edx>, unsigned int a3@<ecx>)
{
  char *v3; // ebp
  char v4; // cl
  _BYTE *v5; // edi
  int v6; // edx
  _BYTE *v7; // esi
  char *v8; // eax
  int v9; // ebx
  int v10; // ST1C_4
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int result; // eax
  char v15; // dl
  char *v16; // ebx
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
  v5 = a2 + 1;
LABEL_3:
  v6 = v4;
  v7 = v5 - 1;
  v8 = v3 + 1;
  switch ( v4 )
  {
    case 0:
      return -(char)*v7;
    case 63:
      if ( *(v5 - 1) )
      {
        ++v3;
        goto LABEL_27;
      }
      return 63;
    case 91:
      v17 = (char)*(v5 - 1);
      if ( !*(v5 - 1) )
        return 91;
      if ( v3[1] != 33 )
      {
        v3 = sub_423FE0(v8, v17, v20);
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
          result = sub_4242A0(v16, v7, v20 | 0x10000);
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
      v9 = (char)*(v5 - 1);
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


// 0x004244C0 sub_4244C0
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


// 0x00424520 sub_424520
void __usercall sub_424520(_DWORD *a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  _DWORD *v3; // ebx
  int v4; // esi
  _DWORD *v5; // eax
  int v6; // eax
  _DWORD *v7; // eax

  v3 = a1;
  v4 = a2;
  v5 = (_DWORD *)*a1;
  if ( v5 )
    sub_424520(v5, a2, a3);
  v6 = v3[2];
  if ( v6 && v4 )
    sub_4244C0(v6, v4);
  v7 = (_DWORD *)v3[1];
  if ( v7 )
    sub_424520(v7, v4, a3);
  free(v3);
}


// 0x00424570 sub_424570
char *__usercall sub_424570@<eax>(const char *a1@<eax>, unsigned int a2@<edx>, int a3@<ecx>, int a4)
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
  BOOL v27; // esi
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
            return (char *)1;
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
              return (char *)1;
            }
            return (char *)1;
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
        v68 = sub_424570(v106, v108, (int)v105, a4);
        v108 = v67;
        if ( v68 == 1 )
          return (char *)1;
        if ( *v55 != 44 )
          return (char *)v68;
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
  v109 = __mingw_dirname(v10);
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
      v107 = (char *)sub_424570(v11, v13, (int)v105, (int)&v110);
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
        return (char *)1;
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
            v27 = __mingw_readdir((int)v26);
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
          v42 = stricoll((int)v92, (int)v93);
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
      return v107;
    }
  }
  return v107;
}


// 0x00424E00 ___mingw_glob
char *__cdecl __mingw_glob(char *a1, int a2, int a3, int a4)
{
  char *v4; // ebx
  char *v5; // ecx
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
  char *v17; // [esp+18h] [ebp-20h]
  char *v18; // [esp+1Ch] [ebp-1Ch]

  v4 = a1;
  if ( a4 && !(a2 & 2) )
    *(_DWORD *)(a4 + 12) = 0;
  if ( *(char **)a4 != "glob-1.0-mingw32" )
  {
    sub_423F70(a4);
    *(_DWORD *)a4 = "glob-1.0-mingw32";
  }
  v5 = sub_424570(a1, a2, a3, a4);
  if ( v5 == (char *)2 && a2 & 0x10 )
  {
    v17 = (char *)2;
    v18 = (char *)&v15;
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
    v17 = (char *)v9;
    v14 = strdup(&v16);
    v5 = v17;
    if ( v14 )
    {
      v18 = v17;
      sub_4244C0((int)v14, a4);
      v5 = v18;
    }
  }
  return v5;
}


// 0x00424EF0 ___mingw_globfree
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


// 0x00424F50 ___mingw_dirname
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


// 0x00425350 sub_425350
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


// 0x00425420 sub_425420
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


// 0x004254D0 ___mingw_opendir
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


// 0x00425690 ___mingw_readdir
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


// 0x004256E0 ___mingw_closedir
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


// 0x00425730 ___mingw_rewinddir
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


// 0x00425790 ___mingw_telldir
signed int __cdecl __mingw_telldir(int a1)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 276);
  *(_DWORD *)_errno() = 9;
  return -1;
}


// 0x004257C0 ___mingw_seekdir
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


// 0x00425840 _wcstombs
size_t __cdecl wcstombs(char *a1, const wchar_t *a2, size_t a3)
{
  return _wcstombs(a1, a2, a3);
}


// 0x00425848 _wcslen
size_t __cdecl wcslen(const wchar_t *a1)
{
  return _wcslen(a1);
}


// 0x00425850 _vfprintf
int __cdecl vfprintf(FILE *a1, const char *a2, va_list a3)
{
  return _vfprintf(a1, a2, a3);
}


// 0x00425858 _tolower
int __cdecl tolower(int a1)
{
  return _tolower(a1);
}


// 0x00425860 _time
time_t __cdecl time(time_t *a1)
{
  return _time(a1);
}


// 0x00425868 _strtoul
unsigned int __cdecl strtoul(const char *a1, char **a2, int a3)
{
  return _strtoul(a1, a2, a3);
}


// 0x00425870 _strstr
char *__cdecl strstr(const char *a1, const char *a2)
{
  return _strstr(a1, a2);
}


// 0x00425878 _strrchr
char *__cdecl strrchr(const char *a1, int a2)
{
  return _strrchr(a1, a2);
}


// 0x00425880 _strlen
size_t __cdecl strlen(const char *a1)
{
  return _strlen(a1);
}


// 0x00425888 _strcpy
char *__cdecl strcpy(char *a1, const char *a2)
{
  return _strcpy(a1, a2);
}


// 0x00425890 _strcoll
int __cdecl strcoll(const char *a1, const char *a2)
{
  return _strcoll(a1, a2);
}


// 0x00425898 _strcmp
int __cdecl strcmp(const char *a1, const char *a2)
{
  return _strcmp(a1, a2);
}


// 0x004258A0 _strcat
char *__cdecl strcat(char *a1, const char *a2)
{
  return _strcat(a1, a2);
}


// 0x004258A8 _srand
void __cdecl srand(unsigned int a1)
{
  _srand(a1);
}


// 0x004258B8 _signal
void (__cdecl *__cdecl signal(int a1, void (__cdecl *a2)(int)))(int)
{
  return _signal(a1, a2);
}


// 0x004258C0 _setlocale
char *__cdecl setlocale(int a1, const char *a2)
{
  return _setlocale(a1, a2);
}


// 0x004258C8 _realloc
void *__cdecl realloc(void *a1, size_t a2)
{
  return _realloc(a1, a2);
}


// 0x004258D0 _rand
int __cdecl rand()
{
  return _rand();
}


// 0x004258D8 _memset
void *__cdecl memset(void *a1, int a2, size_t a3)
{
  return _memset(a1, a2, a3);
}


// 0x004258E0 _memcpy
void *__cdecl memcpy(void *a1, const void *a2, size_t a3)
{
  return _memcpy(a1, a2, a3);
}


// 0x004258E8 _mbstowcs
size_t __cdecl mbstowcs(wchar_t *a1, const char *a2, size_t a3)
{
  return _mbstowcs(a1, a2, a3);
}


// 0x004258F0 _malloc
void *__cdecl malloc(size_t a1)
{
  return _malloc(a1);
}


// 0x004258F8 _localtime
struct tm *__cdecl localtime(const time_t *a1)
{
  return _localtime(a1);
}


// 0x00425900 _fwrite
size_t __cdecl fwrite(const void *a1, size_t a2, size_t a3, FILE *a4)
{
  return _fwrite(a1, a2, a3, a4);
}


// 0x00425908 _free
void __cdecl free(void *a1)
{
  _free(a1);
}


// 0x00425910 _clock
clock_t __cdecl clock()
{
  return _clock();
}


// 0x00425918 _calloc
void *__cdecl calloc(size_t a1, size_t a2)
{
  return _calloc(a1, a2);
}


// 0x00425920 _abort
void __cdecl __noreturn abort()
{
  _abort();
}


// 0x00425928 __setmode
int __cdecl _setmode(int a1, int a2)
{
  return __setmode(a1, a2);
}


// 0x00425930 __isctype
int __cdecl _isctype(int a1, int a2)
{
  return __isctype(a1, a2);
}


// 0x00425938 __fullpath
char *__cdecl _fullpath(char *a1, const char *a2, size_t a3)
{
  return __fullpath(a1, a2, a3);
}


// 0x00425940 __errno
int _errno(void)
{
  return __errno();
}


// 0x00425948 __cexit
void __cdecl _cexit()
{
  __cexit();
}


// 0x00425950 ___p__fmode
int __p__fmode(void)
{
  return ___p__fmode();
}


// 0x00425958 ___p__environ
int __p__environ(void)
{
  return ___p__environ();
}


// 0x00425960 ___getmainargs
int __cdecl __getmainargs(int a1, int a2, int a3, int a4, int a5)
{
  return ___getmainargs(a1, a2, a3, a4, a5);
}


// 0x00425968 _RegSetValueExA@24
LONG __stdcall RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData)
{
  return RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData);
}


// 0x00425970 _RegQueryValueExA@24
LONG __stdcall RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
  return RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
}


// 0x00425978 _RegCreateKeyExA@36
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


// 0x00425980 _RegCloseKey@4
LONG __stdcall RegCloseKey(HKEY hKey)
{
  return _IAT_start__(hKey);
}


// 0x00425990 _UpdateWindow@4
BOOL __stdcall UpdateWindow(HWND hWnd)
{
  return UpdateWindow(hWnd);
}


// 0x00425998 _TranslateMessage@4
BOOL __stdcall TranslateMessage(const MSG *lpMsg)
{
  return TranslateMessage(lpMsg);
}


// 0x004259A0 _SystemParametersInfoA@16
BOOL __stdcall SystemParametersInfoA(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni)
{
  return SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni);
}


// 0x004259A8 _ShowWindow@8
BOOL __stdcall ShowWindow(HWND hWnd, int nCmdShow)
{
  return ShowWindow(hWnd, nCmdShow);
}


// 0x004259B0 _SetWindowTextW@8
BOOL __stdcall SetWindowTextW(HWND hWnd, LPCWSTR lpString)
{
  return SetWindowTextW(hWnd, lpString);
}


// 0x004259B8 _SetWindowTextA@8
BOOL __stdcall SetWindowTextA(HWND hWnd, LPCSTR lpString)
{
  return SetWindowTextA(hWnd, lpString);
}


// 0x004259C0 _SetWindowLongA@12
LONG __stdcall SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong)
{
  return SetWindowLongA(hWnd, nIndex, dwNewLong);
}


// 0x004259C8 _SetForegroundWindow@4
BOOL __stdcall SetForegroundWindow(HWND hWnd)
{
  return SetForegroundWindow(hWnd);
}


// 0x004259D0 _SetCursor@4
HCURSOR __stdcall SetCursor(HCURSOR hCursor)
{
  return SetCursor(hCursor);
}


// 0x004259D8 _SendMessageA@16
LRESULT __stdcall SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return SendMessageA(hWnd, Msg, wParam, lParam);
}


// 0x004259E0 _ReleaseDC@8
int __stdcall ReleaseDC(HWND hWnd, HDC hDC)
{
  return ReleaseDC(hWnd, hDC);
}


// 0x004259E8 _RegisterClassW@4
ATOM __stdcall RegisterClassW(const WNDCLASSW *lpWndClass)
{
  return RegisterClassW(lpWndClass);
}


// 0x004259F0 _MoveWindow@24
BOOL __stdcall MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint)
{
  return MoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint);
}


// 0x004259F8 _MessageBoxW@16
int __stdcall MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
  return MessageBoxW(hWnd, lpText, lpCaption, uType);
}


// 0x00425A00 _MessageBoxA@16
int __stdcall MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
  return MessageBoxA(hWnd, lpText, lpCaption, uType);
}


// 0x00425A08 _LoadImageA@24
HANDLE __stdcall LoadImageA(HINSTANCE a1, LPCSTR a2, UINT a3, int a4, int a5, UINT a6)
{
  return LoadImageA(a1, a2, a3, a4, a5, a6);
}


// 0x00425A10 _LoadCursorA@8
HCURSOR __stdcall LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName)
{
  return LoadCursorA(hInstance, lpCursorName);
}


// 0x00425A18 _IsZoomed@4
BOOL __stdcall IsZoomed(HWND hWnd)
{
  return IsZoomed(hWnd);
}


// 0x00425A20 _IsIconic@4
BOOL __stdcall IsIconic(HWND hWnd)
{
  return IsIconic(hWnd);
}


// 0x00425A28 _InvalidateRect@12
BOOL __stdcall InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase)
{
  return InvalidateRect(hWnd, lpRect, bErase);
}


// 0x00425A30 _GetWindowTextW@12
int __stdcall GetWindowTextW(HWND hWnd, LPWSTR lpString, int nMaxCount)
{
  return GetWindowTextW(hWnd, lpString, nMaxCount);
}


// 0x00425A38 _GetWindowTextA@12
int __stdcall GetWindowTextA(HWND hWnd, LPSTR lpString, int nMaxCount)
{
  return GetWindowTextA(hWnd, lpString, nMaxCount);
}


// 0x00425A40 _GetWindowRect@8
BOOL __stdcall GetWindowRect(HWND hWnd, LPRECT lpRect)
{
  return GetWindowRect(hWnd, lpRect);
}


// 0x00425A48 _GetSystemMetrics@4
int __stdcall GetSystemMetrics(int nIndex)
{
  return GetSystemMetrics(nIndex);
}


// 0x00425A50 _GetMonitorInfoA@8
BOOL __stdcall GetMonitorInfoA(HMONITOR hMonitor, LPMONITORINFO lpmi)
{
  return GetMonitorInfoA(hMonitor, lpmi);
}


// 0x00425A58 _GetMessageA@16
BOOL __stdcall GetMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
  return GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
}


// 0x00425A60 _GetDesktopWindow@0
HWND __stdcall GetDesktopWindow()
{
  return GetDesktopWindow();
}


// 0x00425A68 _GetDC@4
HDC __stdcall GetDC(HWND hWnd)
{
  return GetDC(hWnd);
}


// 0x00425A70 _GetCursorPos@4
BOOL __stdcall GetCursorPos(LPPOINT lpPoint)
{
  return GetCursorPos(lpPoint);
}


// 0x00425A78 _GetAsyncKeyState@4
SHORT __stdcall GetAsyncKeyState(int vKey)
{
  return GetAsyncKeyState(vKey);
}


// 0x00425A80 _FrameRect@12
int __stdcall FrameRect(HDC hDC, const RECT *lprc, HBRUSH hbr)
{
  return FrameRect(hDC, lprc, hbr);
}


// 0x00425A88 _FindWindowA@8
HWND __stdcall FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName)
{
  return FindWindowA(lpClassName, lpWindowName);
}


// 0x00425A90 _FillRect@12
int __stdcall FillRect(HDC hDC, const RECT *lprc, HBRUSH hbr)
{
  return FillRect(hDC, lprc, hbr);
}


// 0x00425A98 _EnumDisplayMonitors@16
BOOL __stdcall EnumDisplayMonitors(HDC hdc, LPCRECT lprcClip, MONITORENUMPROC lpfnEnum, LPARAM dwData)
{
  return EnumDisplayMonitors(hdc, lprcClip, lpfnEnum, dwData);
}


// 0x00425AA0 _DrawTextW@20
int __stdcall DrawTextW(HDC hDC, LPCWSTR lpString, int nCount, LPRECT lpRect, UINT uFormat)
{
  return DrawTextW(hDC, lpString, nCount, lpRect, uFormat);
}


// 0x00425AA8 _DrawTextA@20
int __stdcall DrawTextA(HDC hDC, LPCSTR lpString, int nCount, LPRECT lpRect, UINT uFormat)
{
  return DrawTextA(hDC, lpString, nCount, lpRect, uFormat);
}


// 0x00425AB0 _DispatchMessageA@4
LONG __stdcall DispatchMessageA(const MSG *lpMsg)
{
  return DispatchMessageA(lpMsg);
}


// 0x00425AB8 _DestroyWindow@4
BOOL __stdcall DestroyWindow(HWND hWnd)
{
  return DestroyWindow(hWnd);
}


// 0x00425AC0 _DefWindowProcW@16
LRESULT __stdcall DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcW(hWnd, Msg, wParam, lParam);
}


// 0x00425AC8 _CreateWindowExW@48
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


// 0x00425AD0 _AdjustWindowRect@12
BOOL __stdcall AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu)
{
  return AdjustWindowRect(lpRect, dwStyle, bMenu);
}


// 0x00425AD8 _lstrcpyA@8
LPSTR __stdcall lstrcpyA(LPSTR lpString1, LPCSTR lpString2)
{
  return lstrcpyA(lpString1, lpString2);
}


// 0x00425AE0 _lstrcmpA@8
int __stdcall lstrcmpA(LPCSTR lpString1, LPCSTR lpString2)
{
  return lstrcmpA(lpString1, lpString2);
}


// 0x00425AE8 _lstrcatA@8
LPSTR __stdcall lstrcatA(LPSTR lpString1, LPCSTR lpString2)
{
  return lstrcatA(lpString1, lpString2);
}


// 0x00425AF0 _VirtualQuery@12
DWORD __stdcall VirtualQuery(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, DWORD dwLength)
{
  return VirtualQuery(lpAddress, lpBuffer, dwLength);
}


// 0x00425AF8 _VirtualProtect@16
BOOL __stdcall VirtualProtect(LPVOID lpAddress, DWORD dwSize, DWORD flNewProtect, PDWORD lpflOldProtect)
{
  return VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect);
}


// 0x00425B00 _TlsGetValue@4
LPVOID __stdcall TlsGetValue(DWORD dwTlsIndex)
{
  return TlsGetValue(dwTlsIndex);
}


// 0x00425B08 _Sleep@4
void __stdcall Sleep(DWORD dwMilliseconds)
{
  Sleep(dwMilliseconds);
}


// 0x00425B10 _SetUnhandledExceptionFilter@4
LPTOP_LEVEL_EXCEPTION_FILTER __stdcall SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)
{
  return SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
}


// 0x00425B18 _RemoveDirectoryA@4
BOOL __stdcall RemoveDirectoryA(LPCSTR lpPathName)
{
  return RemoveDirectoryA(lpPathName);
}


// 0x00425B20 _ReleaseMutex@4
BOOL __stdcall ReleaseMutex(HANDLE hMutex)
{
  return ReleaseMutex(hMutex);
}


// 0x00425B28 _ReadFile@20
BOOL __stdcall ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped)
{
  return ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
}


// 0x00425B30 _QueryPerformanceFrequency@4
BOOL __stdcall QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency)
{
  return QueryPerformanceFrequency(lpFrequency);
}


// 0x00425B38 _QueryPerformanceCounter@4
BOOL __stdcall QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount)
{
  return QueryPerformanceCounter(lpPerformanceCount);
}


// 0x00425B40 _MultiByteToWideChar@24
int __stdcall MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cchMultiByte, LPWSTR lpWideCharStr, int cchWideChar)
{
  return MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cchMultiByte, lpWideCharStr, cchWideChar);
}


// 0x00425B48 _LoadLibraryA@4
HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName)
{
  return LoadLibraryA(lpLibFileName);
}


// 0x00425B50 _LeaveCriticalSection@4
void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}


// 0x00425B58 _InitializeCriticalSection@4
void __stdcall InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  InitializeCriticalSection(lpCriticalSection);
}


// 0x00425B60 _GetUserDefaultUILanguage@0
int __stdcall GetUserDefaultUILanguage()
{
  return GetUserDefaultUILanguage();
}


// 0x00425B68 _GetTickCount@0
DWORD __stdcall GetTickCount()
{
  return GetTickCount();
}


// 0x00425B70 _GetTempPathA@8
DWORD __stdcall GetTempPathA(DWORD nBufferLength, LPSTR lpBuffer)
{
  return GetTempPathA(nBufferLength, lpBuffer);
}


// 0x00425B78 _GetStartupInfoA@4
void __stdcall GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo)
{
  GetStartupInfoA(lpStartupInfo);
}


// 0x00425B80 _GetProcAddress@8
FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
  return GetProcAddress(hModule, lpProcName);
}


// 0x00425B88 _GetModuleHandleA@4
HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName)
{
  return GetModuleHandleA(lpModuleName);
}


// 0x00425B90 _GetLastError@0
DWORD __stdcall GetLastError()
{
  return GetLastError();
}


// 0x00425B98 _GetFileAttributesA@4
DWORD __stdcall GetFileAttributesA(LPCSTR lpFileName)
{
  return GetFileAttributesA(lpFileName);
}


// 0x00425BA0 _GetCommandLineA@0
LPSTR __stdcall GetCommandLineA()
{
  return GetCommandLineA();
}


// 0x00425BA8 _FreeLibrary@4
BOOL __stdcall FreeLibrary(HMODULE hLibModule)
{
  return FreeLibrary(hLibModule);
}


// 0x00425BB0 _FindNextFileA@8
BOOL __stdcall FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData)
{
  return FindNextFileA(hFindFile, lpFindFileData);
}


// 0x00425BB8 _FindFirstFileA@8
HANDLE __stdcall FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData)
{
  return FindFirstFileA(lpFileName, lpFindFileData);
}


// 0x00425BC0 _FindClose@4
BOOL __stdcall FindClose(HANDLE hFindFile)
{
  return FindClose(hFindFile);
}


// 0x00425BC8 _ExitThread@4
void __stdcall __noreturn ExitThread(DWORD dwExitCode)
{
  ExitThread(dwExitCode);
}


// 0x00425BD0 _ExitProcess@4
void __stdcall __noreturn ExitProcess(UINT uExitCode)
{
  ExitProcess(uExitCode);
}


// 0x00425BD8 _EnterCriticalSection@4
void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}


// 0x00425BE0 _DeleteFileA@4
BOOL __stdcall DeleteFileA(LPCSTR lpFileName)
{
  return DeleteFileA(lpFileName);
}


// 0x00425BE8 _DeleteCriticalSection@4
void __stdcall DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}


// 0x00425BF0 _CreateThread@24
HANDLE __stdcall CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, DWORD dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId)
{
  return CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
}


// 0x00425BF8 _CreateMutexA@12
HANDLE __stdcall CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
  return CreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
}


// 0x00425C00 _CreateFileA@28
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


// 0x00425C08 _CreateDirectoryA@8
BOOL __stdcall CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
  return CreateDirectoryA(lpPathName, lpSecurityAttributes);
}


// 0x00425C10 _CloseHandle@4
BOOL __stdcall CloseHandle(HANDLE hObject)
{
  return CloseHandle(hObject);
}


// 0x00425C18 _stricoll
int __cdecl stricoll(int a1, int a2)
{
  return _stricoll(a1, a2);
}


// 0x00425C20 _strdup
char *__cdecl strdup(const char *a1)
{
  return _strdup(a1);
}


// 0x00425C28 __Z10SteamUtilsv
ISteamUtils *SteamUtils()
{
  return *(ISteamUtils **)_SteamInternal_ContextInit(SteamUtils(void)::s_CallbackCounterAndContext);
}


// 0x00425C40 __Z12SteamFriendsv
ISteamFriends *SteamFriends()
{
  return *(ISteamFriends **)_SteamInternal_ContextInit(SteamFriends(void)::s_CallbackCounterAndContext);
}


// 0x00425C58 __Z14SteamUserStatsv
ISteamUserStats *SteamUserStats()
{
  return *(ISteamUserStats **)_SteamInternal_ContextInit(SteamUserStats(void)::s_CallbackCounterAndContext);
}


// 0x00425C70 __Z16SteamScreenshotsv
ISteamScreenshots *SteamScreenshots()
{
  return *(ISteamScreenshots **)_SteamInternal_ContextInit(SteamScreenshots(void)::s_CallbackCounterAndContext);
}


// 0x00425C88 __Z18SteamRemoteStoragev
ISteamRemoteStorage *SteamRemoteStorage()
{
  return *(ISteamRemoteStorage **)_SteamInternal_ContextInit(SteamRemoteStorage(void)::s_CallbackCounterAndContext);
}


// 0x00425CA0 __Z28SteamInternal_Init_SteamAppsPP10ISteamApps
void __cdecl SteamInternal_Init_SteamApps(ISteamApps **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamApps *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMAPPS_INTERFACE_VERSION008");
}


// 0x00425CCC __Z29SteamInternal_Init_SteamUtilsPP11ISteamUtils
void __cdecl SteamInternal_Init_SteamUtils(ISteamUtils **p)
{
  *p = (ISteamUtils *)_SteamInternal_FindOrCreateUserInterface(0, "SteamUtils010");
}


// 0x00425CF4 __Z31SteamInternal_Init_SteamFriendsPP13ISteamFriends
void __cdecl SteamInternal_Init_SteamFriends(ISteamFriends **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamFriends *)_SteamInternal_FindOrCreateUserInterface(v1, "SteamFriends017");
}


// 0x00425D20 __Z33SteamInternal_Init_SteamUserStatsPP15ISteamUserStats
void __cdecl SteamInternal_Init_SteamUserStats(ISteamUserStats **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamUserStats *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMUSERSTATS_INTERFACE_VERSION012");
}


// 0x00425D4C __Z35SteamInternal_Init_SteamScreenshotsPP17ISteamScreenshots
void __cdecl SteamInternal_Init_SteamScreenshots(ISteamScreenshots **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamScreenshots *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMSCREENSHOTS_INTERFACE_VERSION003");
}


// 0x00425D78 __Z37SteamInternal_Init_SteamRemoteStoragePP19ISteamRemoteStorage
void __cdecl SteamInternal_Init_SteamRemoteStorage(ISteamRemoteStorage **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamRemoteStorage *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMREMOTESTORAGE_INTERFACE_VERSION016");
}


// 0x00425DA4 __Z9SteamAppsv
ISteamApps *SteamApps()
{
  return *(ISteamApps **)_SteamInternal_ContextInit(SteamApps(void)::s_CallbackCounterAndContext);
}


// 0x00425DC0 __ZN10__cxxabiv117__class_type_infoD0Ev
_DWORD __thiscall __cxxabiv1::__class_type_info::~__class_type_info(__cxxabiv1::__class_type_info *this)
{
  __cxxabiv1::__class_type_info *v1; // ebx
  int result; // eax

  v1 = this;
  *(_DWORD *)this = &off_429D6C;
  std::type_info::~type_info(this);
  operator delete((void *)v1);
  return result;
}


// 0x00425DF0 __ZN10__cxxabiv117__class_type_infoD1Ev
_DWORD __thiscall __cxxabiv1::__class_type_info::~__class_type_info(__cxxabiv1::__class_type_info *this)
{
  *(_DWORD *)this = &off_429D6C;
  return std::type_info::~type_info(this);
}


// 0x00425E00 __ZN10__cxxabiv120__si_class_type_infoD0Ev
_DWORD __thiscall __cxxabiv1::__si_class_type_info::~__si_class_type_info(__cxxabiv1::__si_class_type_info *this)
{
  __cxxabiv1::__si_class_type_info *v1; // ebx
  int result; // eax

  v1 = this;
  *(_DWORD *)this = &off_429D98;
  __cxxabiv1::__class_type_info::~__class_type_info(this);
  operator delete((void *)v1);
  return result;
}


// 0x00425E30 __ZN10__cxxabiv120__si_class_type_infoD1Ev
_DWORD __thiscall __cxxabiv1::__si_class_type_info::~__si_class_type_info(__cxxabiv1::__si_class_type_info *this)
{
  *(_DWORD *)this = &off_429D98;
  return __cxxabiv1::__class_type_info::~__class_type_info(this);
}


// 0x00425E40 __ZN18LeaderboardEntry_tC1Ev
void __thiscall LeaderboardEntry_t::LeaderboardEntry_t(LeaderboardEntry_t *const this)
{
  CSteamID::CSteamID(&this->m_steamIDUser);
}


// 0x00425E58 __ZN5BoardD1Ev
void __thiscall Board::~Board(Board *const this)
{
  Steam::~Steam(&this->st);
}


// 0x00425E74 __ZN7Gdiplus11GdiplusBaseC2Ev
void __thiscall Gdiplus::GdiplusBase::GdiplusBase(Gdiplus::GdiplusBase *const this)
{
  ;
}


// 0x00425E80 __ZN7Gdiplus11GdiplusBasedlEPv
void __cdecl Gdiplus::GdiplusBase::operator delete(void *in_pVoid)
{
  GdipFree((int)in_pVoid);
}


// 0x00425E98 __ZN7Gdiplus11GdiplusBasenwEj
void *__cdecl Gdiplus::GdiplusBase::operator new(size_t in_size)
{
  return (void *)GdipAlloc(in_size);
}


// 0x00425EB0 __ZN7Gdiplus12CachedBitmapD0Ev
void __thiscall Gdiplus::CachedBitmap::~CachedBitmap(Gdiplus::CachedBitmap *const this)
{
  Gdiplus::CachedBitmap *v1; // ST1C_4

  v1 = this;
  Gdiplus::CachedBitmap::~CachedBitmap(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// 0x00425ED0 __ZN7Gdiplus12CachedBitmapD1Ev
void __thiscall Gdiplus::CachedBitmap::~CachedBitmap(Gdiplus::CachedBitmap *const this)
{
  this->_vptr_CachedBitmap = (int (**)(...))off_429DC4;
  GdipDeleteCachedBitmap((int)this->nativeCachedBitmap);
}


// 0x00425EF8 __ZN7Gdiplus13CustomLineCapD0Ev
void __thiscall Gdiplus::CustomLineCap::~CustomLineCap(Gdiplus::CustomLineCap *const this)
{
  Gdiplus::CustomLineCap *v1; // ST1C_4

  v1 = this;
  Gdiplus::CustomLineCap::~CustomLineCap(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// 0x00425F18 __ZN7Gdiplus13CustomLineCapD1Ev
void __thiscall Gdiplus::CustomLineCap::~CustomLineCap(Gdiplus::CustomLineCap *const this)
{
  this->_vptr_CustomLineCap = (int (**)(...))off_429DD4;
  GdipDeleteCustomLineCap((int)this->nativeCap->gap0);
}


// 0x00425F40 __ZN7Gdiplus14FontCollectionD0Ev
void __thiscall Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  Gdiplus::FontCollection *v1; // ST1C_4

  v1 = this;
  Gdiplus::FontCollection::~FontCollection(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// 0x00425F60 __ZN7Gdiplus14FontCollectionD1Ev
void __thiscall Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  this->_vptr_FontCollection = (int (**)(...))off_429DE4;
}


// 0x00425F78 __ZN7Gdiplus14FontCollectionD2Ev
void __thiscall Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  this->_vptr_FontCollection = (int (**)(...))off_429DE4;
}


// 0x00425F90 .weak.__ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii.__ZN7Gdiplus11GdiplusBasedlEPv
void __userpurge weak___ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii___ZN7Gdiplus11GdiplusBasedlEPv(_DWORD *a1@<ecx>, Gdiplus::GdiplusStartupInput *const this, Gdiplus::DebugEventProc debugEventCallback, BOOL suppressBackgroundThread, BOOL suppressExternalCodecs)
{
  *a1 = 1;
  a1[1] = this;
  a1[2] = debugEventCallback;
  a1[3] = suppressBackgroundThread;
}


// 0x00425FC4 __ZN7Gdiplus21PrivateFontCollectionD0Ev
void __thiscall Gdiplus::PrivateFontCollection::~PrivateFontCollection(Gdiplus::PrivateFontCollection *const this)
{
  Gdiplus::PrivateFontCollection *v1; // ST1C_4

  v1 = this;
  Gdiplus::PrivateFontCollection::~PrivateFontCollection(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// 0x00425FE4 __ZN7Gdiplus21PrivateFontCollectionD1Ev
void __thiscall Gdiplus::PrivateFontCollection::~PrivateFontCollection(Gdiplus::PrivateFontCollection *const this)
{
  Gdiplus::PrivateFontCollection *v1; // ST1C_4

  v1 = this;
  this->_vptr_FontCollection = (int (**)(...))off_429DF4;
  GdipDeletePrivateFontCollection((int)&this->nativeFontCollection);
  Gdiplus::FontCollection::~FontCollection(&v1->0);
}


// 0x00426018 __ZN7Gdiplus23InstalledFontCollectionD0Ev
void __thiscall Gdiplus::InstalledFontCollection::~InstalledFontCollection(Gdiplus::InstalledFontCollection *const this)
{
  Gdiplus::InstalledFontCollection *v1; // ST1C_4

  v1 = this;
  Gdiplus::InstalledFontCollection::~InstalledFontCollection(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// 0x00426038 __ZN7Gdiplus23InstalledFontCollectionD1Ev
void __thiscall Gdiplus::InstalledFontCollection::~InstalledFontCollection(Gdiplus::InstalledFontCollection *const this)
{
  this->_vptr_FontCollection = (int (**)(...))off_429E04;
  Gdiplus::FontCollection::~FontCollection(&this->0);
}


// 0x00426058 __ZN7Gdiplus5Image14SetNativeImageEPNS_7GpImageE
void __thiscall Gdiplus::Image::SetNativeImage(Gdiplus::Image *const this, Gdiplus::GpImage *nativeImage)
{
  this->nativeImage = nativeImage;
}


// 0x00426070 __ZN7Gdiplus5Image5CloneEv
Gdiplus::Image *__thiscall Gdiplus::Image::Clone(Gdiplus::Image *const this)
{
  Gdiplus::Image *v1; // ST1C_4
  int v2; // eax
  Gdiplus::Image *v3; // ebx
  Gdiplus::GpImage *cloneimage; // [esp+2Ch] [ebp-Ch]

  v1 = this;
  cloneimage = 0;
  v2 = GdipCloneImage((int)this->nativeImage->gap0, (int)&cloneimage);
  Gdiplus::Image::SetStatus(v1, (Gdiplus::Status)v2);
  v3 = (Gdiplus::Image *)Gdiplus::GdiplusBase::operator new(0x10u);
  Gdiplus::Image::Image(v3, cloneimage, v1->lastResult);
  return v3;
}


// 0x004260DC __ZN7Gdiplus5ImageC1EPNS_7GpImageENS_6StatusE
void __thiscall Gdiplus::Image::Image(Gdiplus::Image *const this, Gdiplus::GpImage *nativeImage, Gdiplus::Status status)
{
  Gdiplus::Image *v3; // ST1C_4

  v3 = this;
  Gdiplus::GdiplusBase::GdiplusBase((Gdiplus::GdiplusBase *const )this);
  v3->_vptr_Image = (int (**)(...))off_429E14;
  Gdiplus::Image::SetNativeImage(v3, nativeImage);
  v3->lastResult = status;
}


// 0x0042611C __ZN7Gdiplus5ImageD0Ev
void __thiscall Gdiplus::Image::~Image(Gdiplus::Image *const this)
{
  Gdiplus::Image *v1; // ST1C_4

  v1 = this;
  Gdiplus::Image::~Image(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// 0x0042613C __ZN7Gdiplus5ImageD1Ev
void __thiscall Gdiplus::Image::~Image(Gdiplus::Image *const this)
{
  this->_vptr_Image = (int (**)(...))off_429E14;
  GdipDisposeImage((int)this->nativeImage->gap0);
}


// 0x00426164 __ZN8CSteamIDC1Ev
void __thiscall CSteamID::CSteamID(CSteamID *const this)
{
  char v1; // t1
  char v2; // t1

  this->m_steamid.m_comp = 0;
  HIWORD(this->m_steamid.m_unAll64Bits) = BYTE6(this->m_steamid.m_unAll64Bits) & 0xF;
  v1 = BYTE4(this->m_steamid.m_unAll64Bits);
  BYTE4(this->m_steamid.m_unAll64Bits) = 0;
  v2 = BYTE5(this->m_steamid.m_unAll64Bits);
  BYTE5(this->m_steamid.m_unAll64Bits) = 0;
  BYTE6(this->m_steamid.m_unAll64Bits) &= 0xF0u;
}


// 0x004261B0 __ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj
_DWORD __thiscall __cxxabiv1::__class_type_info::__do_catch(__cxxabiv1::__class_type_info *this, const std::type_info *thisa, void **a3, unsigned int a4)
{
  int v4; // edx
  __cxxabiv1::__class_type_info *v5; // esi
  int result; // eax

  v5 = this;
  LOBYTE(result) = std::type_info::operator==((int)this, v4, (int)thisa);
  if ( !(_BYTE)result && a4 <= 3 )
    result = (*(int (__fastcall **)(const std::type_info *, void **, __cxxabiv1::__class_type_info *))(*(_DWORD *)thisa + 20))(
               thisa,
               a3,
               v5);
  return result;
}


// 0x00426200 __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE
bool __fastcall __cxxabiv1::__class_type_info::__do_upcast(int ecx0, int edx0, int a1, int a2, _DWORD *a3)
{
  bool result; // al

  result = std::type_info::operator==(ecx0, edx0, a1);
  if ( result )
  {
    a3[3] = 8;
    a3[1] = 6;
    *a3 = a2;
  }
  return result;
}


// 0x00426240 __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv
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


// 0x004262B0 __ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE
int __fastcall __cxxabiv1::__class_type_info::__do_dyncast(int ecx0, int edx0, int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v9; // edi
  int result; // eax

  v9 = ecx0;
  if ( a4 == a6 && std::type_info::operator==(ecx0, edx0, a5) )
  {
    a7[2] = a2;
    result = 0;
  }
  else
  {
    if ( std::type_info::operator==(v9, edx0, a3) )
    {
      *a7 = a4;
      a7[3] = 1;
      a7[1] = a2;
    }
    result = 0;
  }
  return result;
}


// 0x00426330 __ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_
int __userpurge __cxxabiv1::__class_type_info::__do_find_public_src@<eax>(__cxxabiv1::__class_type_info *this, const __cxxabiv1::__class_type_info *a2, const void *a3, const __cxxabiv1::__class_type_info *a4, const void *a5)
{
  return 5 * (a4 == a2) + 1;
}


// 0x00426350 __ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE
char __fastcall __cxxabiv1::__si_class_type_info::__do_upcast(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // ebp
  char result; // al

  v5 = a1;
  result = __cxxabiv1::__class_type_info::__do_upcast(a1, a2, a3, a4, a5);
  if ( !result )
    result = (*(int (__stdcall **)(int, int, _DWORD *))(**(_DWORD **)(v5 + 8) + 24))(a3, a4, a5);
  return result;
}


// 0x004263B0 __ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE
int __fastcall __cxxabiv1::__si_class_type_info::__do_dyncast(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _DWORD *a9)
{
  bool v9; // al
  int v10; // edx
  int result; // eax
  bool v12; // al
  int v13; // [esp+18h] [ebp-24h]

  v13 = a1;
  v9 = std::type_info::operator==(a1, a5, a5);
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
  else if ( a6 == a8 && (v12 = std::type_info::operator==(v13, a5, a7), v10 = a5, v12) )
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


// 0x004264A0 __ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_
_DWORD __thiscall __cxxabiv1::__si_class_type_info::__do_find_public_src(__cxxabiv1::__si_class_type_info *this, int thisa, const void *a3, const __cxxabiv1::__class_type_info *a4, const void *a5)
{
  __cxxabiv1::__si_class_type_info *v5; // edx
  int result; // eax
  __cxxabiv1::__si_class_type_info *v7; // ST1C_4
  bool v8; // al

  v5 = this;
  if ( a5 == a3 && (v7 = this, v8 = std::type_info::operator==((int)this, (int)this, (int)a4), v5 = v7, v8) )
    result = 6;
  else
    result = (*(int (__stdcall **)(int, const void *, const __cxxabiv1::__class_type_info *, const void *))(**((_DWORD **)v5 + 2) + 32))(
               thisa,
               a3,
               a4,
               a5);
  return result;
}


// 0x00426510 __ZNK7Gdiplus5Image9SetStatusENS_6StatusE
Gdiplus::Status __thiscall Gdiplus::Image::SetStatus(const Gdiplus::Image *const this, Gdiplus::Status status)
{
  if ( status == Ok )
    return 0;
  this->lastResult = status;
  return this->lastResult;
}


// 0x00426538 __ZNK8CSteamID15GetEAccountTypeEv
EAccountType __thiscall CSteamID::GetEAccountType(const CSteamID *const this)
{
  return (unsigned __int8)(BYTE6(this->m_steamid.m_unAll64Bits) >> 4);
}


// 0x00426550 __ZNKSt9type_info10__do_catchEPKS_PPvj
_DWORD __thiscall std::type_info::__do_catch(std::type_info *this, const std::type_info *thisa, void **a3, unsigned int a4)
{
  int v4; // edx
  int result; // eax

  LOBYTE(result) = std::type_info::operator==((int)this, v4, (int)thisa);
  return result;
}


// 0x00426570 __ZNKSt9type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv
int __userpurge std::type_info::__do_upcast@<eax>(std::type_info *this, const __cxxabiv1::__class_type_info *a2, void **a3)
{
  return 0;
}


// 0x00426580 __ZNKSt9type_info14__is_pointer_pEv
_DWORD __thiscall std::type_info::__is_pointer_p(std::type_info *this)
{
  return 0;
}


// 0x00426590 __ZNKSt9type_infoeqERKS_
bool __fastcall std::type_info::operator==(int a1, int a2, int a3)
{
  if ( a3 == a1 )
    return 1;
  if ( **(_BYTE **)(a1 + 4) == 42 )
    return 0;
  return strcmp(*(const char **)(a1 + 4), (const char *)((**(_BYTE **)(a3 + 4) == 42) + *(_DWORD *)(a3 + 4))) == 0;
}


// 0x004265F0 __ZNSt9type_infoD0Ev
_DWORD __thiscall std::type_info::~type_info(std::type_info *this)
{
  int result; // eax

  operator delete((void *)this);
  return result;
}


// 0x00426610 __ZNSt9type_infoD1Ev
_DWORD __thiscall std::type_info::~type_info(std::type_info *this)
{
  ;
}


// 0x00426620 __ZdlPv
void __cdecl operator delete(void *a1)
{
  free(a1);
}


// 0x00426630 __ZdlPvj
void __cdecl operator delete(void *a1)
{
  operator delete(a1);
}


// 0x00426640 _main_0
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


// 0x00426710 _register_frame_ctor
int register_frame_ctor()
{
  return __gcc_register_frame();
}

