// 多语言文本加载
// 基于所选 Debug EXE 的静态反编译，按 DWARF 源文件归属恢复。
// 这是供阅读的源码式伪代码；并非已验证可编译的源码。
#include "../include/recovered_types.hpp"

// 原始位置：lan.cpp:3；地址：0x00409618
// 调试记录声明：void Lan()
// 功能说明：构造函数：初始化成员及所拥有的子对象。
Lan::Lan()
{

  const char *v2;

  qmemcpy(this, off_427040, 0x78u);
  qmemcpy((void *)this->lanshortid, &unk_4270C0, sizeof(this->lanshortid));
  this->data = 0;
  this->landata = 0;
  this->landatap = 0;
  this->LAN_TITLE = 0;
  this->LAN_RUNNING = 1;
  this->LAN_STEAM_LAUNCH = 2;
  this->LAN_STEAM_FAIL = 3;
  this->LAN_STEAM_Status = 4;
  this->LAN_ABOUT_NAME = 5;
  this->LAN_ABOUT_VERSION = 6;
  this->LAN_ABOUT_AUTHOR = 7;
  this->LAN_ABOUT_LICENSE = 8;
  this->LAN_ABOUT_OK = 9;
  this->LAN_LOAD_STEAM = 10;
  this->LAN_LOAD_AUDIO = 11;
  this->LAN_LOAD_BOARD = 12;
  this->LAN_LOAD_GRAPH = 13;
  this->LAN_LOAD_WINDOW = 14;
  this->LAN_HELP = 15;
  this->LAN_SET = this->LAN_HELP + 20;
  this->LAN_TUT_ = this->LAN_SET + 23;
  this->LAN_TUT = this->LAN_TUT_ + 1;
  this->LAN_MODE = this->LAN_TUT + 15;
  this->LAN_TUT_QUIT = this->LAN_MODE + 5;
  this->LAN_HELP_MENU = this->LAN_TUT_QUIT + 3;
  this->LAN_HELP_TITLE = this->LAN_HELP_MENU + 20;
  this->data = (__int16 *)calloc(0x2710u, 2u);
  this->landata = (__int16 *)calloc(0x2710u, 2u);
  this->landatap = (__int16 **)calloc(0x3E8u, 4u);
  v2 = this->getsyslan();
  this->initlan(v2);
}


// 原始位置：lan.cpp:11；地址：0x00409860
// 调试记录声明：const char * getsyslan()
// 功能说明：根据系统语言选择语言标识。
// 原始局部变量：const char *lansys；long int lansysid；long int k。
const char *Lan::getsyslan()
{

  int lansysid;
  int k;
  const char *lansys;

  lansys = this->lanshort[6];
  lansysid = (unsigned __int16)GetUserDefaultUILanguage();
  for ( k = 0; k <= 29; ++k )
  {
    if ( this->lanshortid[k] == lansysid )
      lansys = this->lanshort[k];
  }
  return lansys;
}


// 原始位置：lan.cpp:25；地址：0x004098B4
// 调试记录声明：void initlan(const char *lan)
// 功能说明：初始化语言资源与文本表。
// 原始局部变量：char path[100]；DWORD startTime；HANDLE hFile；int sequenceLength；long int n；short int i；short int i_；short int j；short int j_；DWORD bytesRead；long unsigned int i；bool match；int j；int j。
void Lan::initlan(const char *lan)
{
  char *v2;
  bool v3;

  DWORD bytesRead;
  char path[100];
  int sequenceLength;
  HANDLE hFile;
  DWORD startTime;
  __int16 j_;
  __int16 j;
  __int16 i_;
  __int16 i;
  int n;
  int j_1;
  int j_0;
  bool match;
  unsigned int i_0;

  strcpy(path, "./data/lan/");
  strcat(path, lan);
  v2 = &path[strlen(path)];
  *(_DWORD *)v2 = 1954051118;
  v2[4] = 0;
  startTime = GetTickCount();
  do
  {
    hFile = CreateFileA(path, 0x80000000, 1u, 0, 3u, 0x80u, 0);
    if ( hFile == (HANDLE)-1 )
      Sleep(0x64u);
    v3 = hFile == (HANDLE)-1 && GetTickCount() - startTime <= 0xBB7;
  }
  while ( v3 );
  if ( hFile == (HANDLE)-1 )
  {
    MessageBoxA(0, "Failed to load language file", "Error", 0x10u);
    ExitProcess(1u);
  }
  ReadFile(hFile, this->data, 0x4E20u, &bytesRead, 0);
  CloseHandle(hFile);
  sequenceLength = 8;
  for ( i_0 = 0; this->data[i_0] && 10000 - sequenceLength > i_0; ++i_0 )
  {
    match = 1;
    for ( j_0 = 0; j_0 < sequenceLength; ++j_0 )
    {
      if ( this->data[j_0 + i_0] != 120 )
      {
        match = 0;
        break;
      }
    }
    if ( match )
    {
      for ( j_1 = 0; j_1 < sequenceLength; ++j_1 )
        this->data[j_1 + i_0] = version[j_1];
      i_0 = sequenceLength + i_0 - 1;
    }
  }
  n = 0;
  i = 4;
  i_ = 4;
  j = 1;
  j_ = 1;
  *this->landata = -1;
  this->landata[1] = -1;
  this->landata[2] = 0;
  this->landata[3] = 0;
  for ( j = 1; this->data[j]; ++j )
  {
    this->landata[i] = this->data[j];
    if ( this->data[j] == 13 )
    {
      this->landata[i_ + 2147483646] = j - j_;
      this->landatap[n] = &this->landata[i_];
      this->landata[i++] = 0;
      this->landata[i++] = -1;
      this->landata[i++] = -1;
      this->landata[i++] = 0;
      ++n;
    }
    if ( this->data[j] == 10 )
    {
      this->landata[i] = 0;
      i_ = i + 1;
      j_ = j + 1;
    }
    ++i;
  }
  this->landata[i_ + 2147483646] = j - j_;
  this->landatap[n] = &this->landata[i_];
  this->landata[i] = 0;
}


// 原始位置：lan.cpp:111；地址：0x00409DAE
// 调试记录声明：short int * getlan(long int id)
// 功能说明：获取界面文本或语言资源。
__int16 *Lan::getlan(int id)
{
  return this->landatap[id];
}

