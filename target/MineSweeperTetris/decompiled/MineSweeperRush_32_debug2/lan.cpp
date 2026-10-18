// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug2.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00409630; symbol: __ZN3LanC1Ev
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
// Address: 0x00409878; symbol: __ZN3Lan9getsyslanEv
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
// Address: 0x004098CC; symbol: __ZN3Lan7initlanEPKc
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
// Address: 0x00409DC6; symbol: __ZN3Lan6getlanEl
__int16 *__userpurge Lan::getlan@<eax>(int a1@<ecx>, Lan *const this, int id)
{
  return *(__int16 **)(4 * (_DWORD)this + *(_DWORD *)(a1 + 248));
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BF0; symbol: _GetUserDefaultUILanguage@0
int __stdcall GetUserDefaultUILanguage()
{
  return GetUserDefaultUILanguage();
}


