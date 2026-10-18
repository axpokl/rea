// 程序入口
// 基于所选 Debug EXE 的静态反编译，按 DWARF 源文件归属恢复。
// 这是供阅读的源码式伪代码；并非已验证可编译的源码。
#include "../include/recovered_types.hpp"

// 原始位置：main.cpp:4；地址：0x00422FF8
// 调试记录声明：int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：HANDLE hMutex；Lan lan；Lan lan；Window w。
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  bool v4;
  __int16 *v5;
  __int16 *v6;
  Lan lan_0;
  Window w;
  HANDLE hMutex;

  MainInstance = hInstance;
  hMutex = CreateMutexA(0, 1, "MineSweeperRushMutex");
  v4 = GetLastError() == 183 || FindWindowA("MineSweeperRushClass", 0);
  if ( v4 )
  {
    Lan::Lan((Lan *const )&w);
    v5 = ((Lan *const )&w)->getlan((int)w.pmenug[1][0]);
    v6 = ((Lan *const )&w)->getlan((int)w.pmenug[1][1]);
    MsgBoxW(v6, v5, 0x40u);
  }
  else
  {
    CheckAndProcessCabFile();
    Lan::Lan(&lan_0);
    Window::Window(&w);
    w.loadall();
    while ( (unsigned __int8)IsWin() )
    {
      w.doaction();
      if ( w.bd.addmask() )
      {
        w.paintevent();
        w.paintrefresh();
      }
      w.bd.sd.checkmusic();
      Delay(1u);
    }
    ReleaseMutex(hMutex);
    Window::~Window(&w);
  }
  CloseHandle(hMutex);
  return 0;
}

