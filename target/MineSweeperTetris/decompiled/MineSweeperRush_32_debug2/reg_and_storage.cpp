// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug2.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

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
    _data_start__ = (int)&__deregister_frame_info;
    v2 = (FARPROC)&__register_frame_info;
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
// Address: 0x00405E90; symbol: __Z11WinRegisterv
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
// Address: 0x00407DA0; symbol: __Z7LoadBMPPKcm
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
// Address: 0x00407F14; symbol: __Z7LoadBMPPKc
pbitmap __cdecl LoadBMP(const char *s)
{
  return LoadBMP(s, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00407F2F; symbol: __Z7SaveBMPP6bitmapPKc
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
// Address: 0x004091A6; symbol: __Z9LoadAudioPKcS0_
unsigned int __cdecl LoadAudio(const char *s1, const char *s2)
{
  sprintf(command_in, "open \"%s\"%s alias s%lu", s1, s2, ++_cid);
  SendString();
  return _cid;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004091F0; symbol: __Z9LoadAudioPKc
unsigned int __cdecl LoadAudio(const char *s)
{
  return LoadAudio(s, ::s);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040C27C; symbol: __ZL18loadallpaintstaticPv@4
DWORD __stdcall loadallpaintstatic(LPVOID lpParam)
{
  Window *v2; // [esp+0h] [ebp-18h]

  Window::loadallpaint(v2);
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00423214; symbol: _GdipSaveImageToFile@16
int __stdcall GdipSaveImageToFile(int a1, int a2, int a3, int a4)
{
  return GdipSaveImageToFile(a1, a2, a3, a4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x0042321C; symbol: _GdipLoadImageFromFile@8
int __stdcall GdipLoadImageFromFile(int a1, int a2)
{
  return GdipLoadImageFromFile(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423950; symbol: ___tlregdtor
int __tlregdtor()
{
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423EA0; symbol: ___register_frame_info
int __register_frame_info()
{
  return ___register_frame_info();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423EA8; symbol: ___deregister_frame_info
int __deregister_frame_info()
{
  return ___deregister_frame_info();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：写入注册表值。
// Address: 0x004259F8; symbol: _RegSetValueExA@24
LONG __stdcall RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData)
{
  return RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：读取注册表值。
// Address: 0x00425A00; symbol: _RegQueryValueExA@24
LONG __stdcall RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
  return RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A08; symbol: _RegCreateKeyExA@36
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
// Address: 0x00425A10; symbol: _RegCloseKey@4
LONG __stdcall RegCloseKey(HKEY hKey)
{
  return _IAT_start__(hKey);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A58; symbol: _SetForegroundWindow@4
BOOL __stdcall SetForegroundWindow(HWND hWnd)
{
  return SetForegroundWindow(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A78; symbol: _RegisterClassW@4
ATOM __stdcall RegisterClassW(const WNDCLASSW *lpWndClass)
{
  return RegisterClassW(lpWndClass);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A98; symbol: _LoadImageA@24
HANDLE __stdcall LoadImageA(HINSTANCE a1, LPCSTR a2, UINT a3, int a4, int a5, UINT a6)
{
  return LoadImageA(a1, a2, a3, a4, a5, a6);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AA0; symbol: _LoadCursorA@8
HCURSOR __stdcall LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName)
{
  return LoadCursorA(hInstance, lpCursorName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BD8; symbol: _LoadLibraryA@4
HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName)
{
  return LoadLibraryA(lpLibFileName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004262F0; symbol: _register_frame_ctor
int register_frame_ctor()
{
  return __gcc_register_frame();
}

