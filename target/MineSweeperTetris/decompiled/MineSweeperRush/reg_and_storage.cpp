// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00414130; symbol: GdipSaveImageToFile
int __stdcall GdipSaveImageToFile(int a1, int a2, int a3, int a4)
{
  return GdipSaveImageToFile(a1, a2, a3, a4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00414138; symbol: GdipLoadImageFromFile
int __stdcall GdipLoadImageFromFile(int a1, int a2)
{
  return GdipLoadImageFromFile(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：写入注册表值。
// Address: 0x004168F8; symbol: RegSetValueExA
LSTATUS __stdcall RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData)
{
  return RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：读取注册表值。
// Address: 0x00416900; symbol: RegQueryValueExA
LSTATUS __stdcall RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
  return RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00416908; symbol: RegCreateKeyExA
LSTATUS __stdcall RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition)
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
// Address: 0x00416910; symbol: RegCloseKey
LSTATUS __stdcall RegCloseKey(HKEY hKey)
{
  return RegCloseKey(hKey);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00416958; symbol: SetForegroundWindow
BOOL __stdcall SetForegroundWindow(HWND hWnd)
{
  return SetForegroundWindow(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00416978; symbol: RegisterClassW
ATOM __stdcall RegisterClassW(const WNDCLASSW *lpWndClass)
{
  return RegisterClassW(lpWndClass);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00416998; symbol: LoadImageA
HANDLE __stdcall LoadImageA(HINSTANCE hInst, LPCSTR name, UINT type, int cx, int cy, UINT fuLoad)
{
  return LoadImageA(hInst, name, type, cx, cy, fuLoad);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004169A0; symbol: LoadCursorA
HCURSOR __stdcall LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName)
{
  return LoadCursorA(hInstance, lpCursorName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00416AD8; symbol: LoadLibraryA
HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName)
{
  return LoadLibraryA(lpLibFileName);
}


