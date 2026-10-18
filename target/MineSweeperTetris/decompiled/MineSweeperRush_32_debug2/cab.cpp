// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug2.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405639; symbol: __Z18CabExtractCallbackPvjjj@16
UINT __stdcall CabExtractCallback(PVOID context, UINT notification, uintptr_t param1, uintptr_t param2)
{
  if ( notification != 17 )
    return 0;
  CombinePath((char *)(param1 + 18), (const char *)context, *(const char **)param1);
  return 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：遍历 CAB 压缩包成员。
// Address: 0x004056AA; symbol: __Z14ProcessCabFilePKc
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
// Address: 0x0040598B; symbol: __Z22CheckAndProcessCabFilev
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


