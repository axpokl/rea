// 资源 CAB 文件及目录处理
// 基于所选 Debug EXE 的静态反编译，按 DWARF 源文件归属恢复。
// 这是供阅读的源码式伪代码；并非已验证可编译的源码。
#include "../include/recovered_types.hpp"

// 原始位置：cab.cpp:3；地址：0x004055D8
// 调试记录声明：void CombinePath(char *dest, const char *path1, const char *path2)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl CombinePath(char *dest, const char *path1, const char *path2)
{
  lstrcpyA(dest, path1);
  lstrcatA(dest, "/");
  lstrcatA(dest, path2);
}


// 原始位置：cab.cpp:10；地址：0x00405621
// 调试记录声明：UINT CabExtractCallback(PVOID context, UINT notification, uintptr_t param1, uintptr_t param2)
// 功能说明：CAB 解包通知回调，根据 notification 返回成员处理结果。
// 原始局部变量：FILE_IN_CABINET_INFO_A *fileInfo；char *destDir。
UINT __stdcall CabExtractCallback(PVOID context, UINT notification, uintptr_t param1, uintptr_t param2)
{
  if ( notification != 17 )
    return 0;
  CombinePath((char *)(param1 + 18), (const char *)context, *(const char **)param1);
  return 1;
}


// 原始位置：cab.cpp:22；地址：0x00405667
// 调试记录声明：void RemoveExtension(char *filePath)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：char *lastDot。
void __cdecl RemoveExtension(char *filePath)
{
  char *lastDot;

  lastDot = strrchr(filePath, 46);
  if ( lastDot )
    *lastDot = 0;
}


// 原始位置：cab.cpp:31；地址：0x00405692
// 调试记录声明：BOOL ProcessCabFile(const char *cabFilePath)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 可见操作：遍历 CAB 成员。
// 原始局部变量：char destFolder[260]；char searchPath[260]；WIN32_FIND_DATAA findData；HANDLE hFind；DWORD errorCode；char errorMessage[360]；char nestedCabPath[260]。
BOOL __cdecl ProcessCabFile(const char *cabFilePath)
{
  BOOL result;
  char nestedCabPath[260];
  WIN32_FIND_DATAA findData;
  char searchPath[260];
  char destFolder[260];
  HANDLE hFind;
  DWORD errorCode;

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


// 原始位置：cab.cpp:68；地址：0x00405840
// 调试记录声明：void DeleteFolderRecursively(const char *folderPath)
// 功能说明：原程序的递归删除函数；这里只导出文本，没有执行删除。
// 原始局部变量：char searchPath[260]；char filePath[260]；WIN32_FIND_DATAA findData；HANDLE hFind。
void __cdecl DeleteFolderRecursively(const char *folderPath)
{
  bool v1;
  WIN32_FIND_DATAA findData;
  char filePath[260];
  char searchPath[260];
  HANDLE hFind;

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


// 原始位置：cab.cpp:100；地址：0x00405973
// 调试记录声明：void CheckAndProcessCabFile()
// 功能说明：检查并处理资源 CAB；原代码可能提取文件或删除旧目录，当前仅静态分析，未执行此函数。
// 原始局部变量：char versionFilePath[260]；HANDLE hMarker。
void CheckAndProcessCabFile()
{
  char versionFilePath[260];
  HANDLE hMarker;

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

