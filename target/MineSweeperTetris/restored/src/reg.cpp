// Windows 注册表配置
// 基于所选 Debug EXE 的静态反编译，按 DWARF 源文件归属恢复。
// 这是供阅读的源码式伪代码；并非已验证可编译的源码。
#include "../include/recovered_types.hpp"

// 原始位置：reg.cpp:3；地址：0x00409DD0
// 调试记录声明：void Reg()
// 功能说明：构造函数：初始化成员及所拥有的子对象。
Reg::Reg()
{
  this->openreg();
}


// 原始位置：reg.cpp:8；地址：0x00409DE6
// 调试记录声明：void ~Reg()
// 功能说明：析构函数：释放该对象拥有的资源。
Reg::~Reg()
{
  this->closereg();
}


// 原始位置：reg.cpp:13；地址：0x00409DFC
// 调试记录声明：void openreg()
// 功能说明：打开 Windows 注册表键。
void Reg::openreg()
{

  RegCreateKeyExA(HKEY_CURRENT_USER, "SoftWare\\MineSweeperRush\\20250412", 0, 0, 0, 0xF003Fu, 0, &this->regkey, 0);
  RegCreateKeyExA(
    HKEY_CURRENT_USER,
    "SoftWare\\MineSweeperRush\\20250412\\board",
    0,
    0,
    0,
    0xF003Fu,
    0,
    &this->regkey_,
    0);
}


// 原始位置：reg.cpp:19；地址：0x00409EA8
// 调试记录声明：void closereg()
// 功能说明：关闭注册表句柄。
void Reg::closereg()
{

  RegCloseKey(this->regkey);
  RegCloseKey(this->regkey_);
}


// 原始位置：reg.cpp:25；地址：0x00409ED6
// 调试记录声明：void setreg(HKEY key, const char *name, long int value)
// 功能说明：写注册表配置；具体值类型由下方调用决定。
// 可见操作：写入注册表。
void Reg::setreg(HKEY key, const char *name, int value)
{
  RegSetValueExA(key, name, 0, 4u, (const BYTE *)&value, 4u);
}


// 原始位置：reg.cpp:30；地址：0x00409F18
// 调试记录声明：void getreg(HKEY key, const char *name, long int *value)
// 功能说明：读取注册表配置。
// 可见操作：读取注册表。
// 原始局部变量：long int temp。
void Reg::getreg(HKEY key, const char *name, int *value)
{
  int temp;

  this->cb = 4;
  if ( RegQueryValueExA(key, name, 0, &this->tp, (LPBYTE)&temp, &this->cb) == 0 )
    *value = temp;
}


// 原始位置：reg.cpp:40；地址：0x00409F7A
// 调试记录声明：void setreg_(HKEY key, const char *name, char *value)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 可见操作：写入注册表。
void Reg::setreg_(HKEY key, const char *name, char *value)
{
  RegSetValueExA(key, name, 0, 3u, (const BYTE *)value, 0x4000u);
}


// 原始位置：reg.cpp:45；地址：0x00409FBC
// 调试记录声明：void getreg_(HKEY key, const char *name, char *value)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 可见操作：读取注册表。
// 原始局部变量：char temp[16384]；DWORD cb。
void Reg::getreg_(HKEY key, const char *name, char *value)
{
  int v4;
  void *v5; // esp
  DWORD cbData;
  BYTE Data;

  v5 = alloca(v4);
  cbData = 0x4000;
  if ( RegQueryValueExA(key, name, 0, &this->tp, &Data, &cbData) == 0 )
    memcpy(value, &Data, 0x4000u);
}

