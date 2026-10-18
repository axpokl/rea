// Win32/GDI+ 绘图、窗口、音频与编码辅助
// 基于所选 Debug EXE 的静态反编译，按 DWARF 源文件归属恢复。
// 这是供阅读的源码式伪代码；并非已验证可编译的源码。
#include "../include/recovered_types.hpp"

// 原始位置：disp.cpp:104；地址：0x00405A50
// 调试记录声明：void WinCreateMain()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void WinCreateMain()
{
  if ( _hw )
  {
    ReleaseBMP(_pmscr);
    ReleaseBMP(_pmain);
    _dc = GetDC(_hw);
    _mscr.Handle = _hw;
    _mscr.DC = _dc;
    _mscr.Width = _w;
    _mscr.Height = _h;
    _pmscr = &_mscr;
    _pmain = CreateBMP(&_mscr);
    _pmain->Color = 1;
    _main.Handle = _pmain->Handle;
    _main.DC = _pmain->DC;
    _main.Width = _pmain->Width;
    _main.Height = _pmain->Height;
    _main.Color = _pmain->Color;
    SetFont();
    if ( _draw )
      _draw();
  }
}


// 原始位置：disp.cpp:124；地址：0x00405B2A
// 调试记录声明：LRESULT WndProc(HWND hW, UINT uM, WPARAM wP, LPARAM lP)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：LRESULT result。
LRESULT __stdcall WndProc(HWND hW, UINT uM, WPARAM wP, LPARAM lP)
{
  bool v4;
  bool v5;
  HICON__ *v6;

  if ( uM == 15 )
  {
    if ( _draw )
      _draw();
  }
  else if ( uM > 0xF )
  {
    if ( uM == 32 )
    {
      v5 = GetMousePosX() >= 0
        && GetMousePosY() >= 0
        && GetMousePosX() <= (signed int)_w
        && GetMousePosY() <= (signed int)_h;
      if ( v5 )
      {
        v6 = LoadCursorA(0, (LPCSTR)0x7F00);
        SetCursor(v6);
      }
    }
    else if ( uM > 0x20 )
    {
      if ( uM == 134 )
      {
        v4 = wP & 0xB && IsIconic(hW);
        if ( v4 )
        {
          ShowWindow(hW, 5);
          SetForegroundWindow(hW);
        }
      }
      else if ( uM == 1024 )
      {
        _msusr[_msusri].message = 1024;
        _msusr[_msusri].wParam = wP;
        _msusr[_msusri++].lParam = lP;
        if ( _msusri > 0x1000 )
          _msusri = 1;
      }
    }
    else if ( uM == 16 )
    {
      DestroyWindow(hW);
    }
  }
  else
  {
    if ( uM == 2 )
    {
      timeEndPeriod(1u);
      _hw = 0;
      _dc = 0;
      _winb = 0;
      ExitThread(0);
    }
    if ( uM > 2 )
    {
      if ( uM == 3 )
      {
        if ( _draw )
          _draw();
      }
      else if ( uM == 5 )
      {
        _w = (unsigned __int16)(((unsigned __int64)lP >> 48) + lP) - ((unsigned int)(lP >> 31) >> 16);
        _h = lP / 0x10000;
        WinCreateMain();
        if ( _draw )
          _draw();
      }
    }
    else if ( uM == 1 )
    {
      timeBeginPeriod(1u);
    }
  }
  return DefWindowProcW(hW, uM, wP, lP);
}


// 原始位置：disp.cpp:176；地址：0x00405DD2
// 调试记录声明：BOOL Monitorenumproc(HMONITOR hmon, HDC hdc, LPRECT lprect, LPARAM pdata)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：RECT *r；MONITORINFOEX info；long int posX；long int posY；RECT work。
BOOL __stdcall Monitorenumproc(HMONITOR hmon, HDC hdc, LPRECT lprect, LPARAM pdata)
{
  RECT *v4;
  LONG work_4;
  LONG work_8;
  LONG work_12;
  MONITORINFOEX info;
  int posY;
  int posX;
  RECT *r;

  r = (RECT *)pdata;
  info.cbSize = 72;
  posX = GetPosX();
  posY = GetPosY();
  if ( GetMonitorInfoA(hmon, &info.0) == 0 )
    return 1;
  work_4 = info.rcWork.top;
  work_8 = info.rcWork.right;
  work_12 = info.rcWork.bottom;
  if ( info.rcWork.left > posX || info.rcWork.right < posX || info.rcWork.top > posY || info.rcWork.bottom < posY )
    return 1;
  v4 = r;
  r->left = info.rcWork.left;
  v4->top = work_4;
  v4->right = work_8;
  v4->bottom = work_12;
  return 0;
}


// 原始位置：disp.cpp:195；地址：0x00405E78
// 调试记录声明：ATOM WinRegister()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
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


// 原始位置：disp.cpp:208；地址：0x00405EEA
// 调试记录声明：void WinCreate()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 可见操作：创建窗口。
// 原始局部变量：RECT rect。
void WinCreate()
{
  RECT rect;

  rect.left = _x;
  rect.top = _y;
  rect.right = _x + _w;
  rect.bottom = _y + _h;
  AdjustWindowRect(&rect, _style, 0);
  _w = rect.right - rect.left;
  _h = rect.bottom - rect.top;
  _hw = CreateWindowExW(
          0,
          _class,
          0,
          _style,
          _x,
          _y,
          rect.right - rect.left,
          rect.bottom - rect.top,
          0,
          0,
          MainInstance,
          0);
}


// 原始位置：disp.cpp:217；地址：0x00405FEA
// 调试记录声明：void WinInit()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 可见操作：消息循环。
void WinInit()
{
  if ( !_wca )
    _wca = WinRegister();
  WinCreate();
  WinCreateMain();
  _winb = 1;
  GetTimeR();
  _tbegin = _tcount;
  while ( (unsigned __int8)IsWin() )
  {
    GetMessageA(&_mst, 0, 0, 0);
    if ( _mst.message )
    {
      SendMsg();
      _mswini = ((_WORD)_mswini + 1) & 0xFFF;
      _mswin[_mswini] = _mst;
    }
  }
}


// 原始位置：disp.cpp:237；地址：0x004060DC
// 调试记录声明：void FreshFPS()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void FreshFPS()
{
  unsigned int v0;

  while ( _mscnti > 0xFFF )
    _mscnti -= 4096;
  v0 = _mscnti;
  _mscnt[v0] = GetTimeR();
  while ( _mscnt[_mscnti] - 1.0 >= _mscnt[_mscntj] )
  {
    ++_mscntj;
    while ( _mscntj > 0xFFF )
      _mscntj -= 4096;
  }
}


// 原始位置：disp.cpp:247；地址：0x00406167
// 调试记录声明：void AddFPS()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void AddFPS()
{
  ++_mscnti;
  FreshFPS();
}


// 原始位置：disp.cpp:253；地址：0x00406182
// 调试记录声明：void CreateWin(long int x, long int y, long unsigned int w, long unsigned int h, long unsigned int cfg, long unsigned int cbg, long unsigned int style, const char *winclass)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：wchar_t wstr[127]。
void __cdecl CreateWin(int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int style, const char *winclass)
{
  wchar_t wstr[127];

  MultiByteToWideChar(0xFDE9u, 0, winclass, -1, wstr, 127);
  _class = wstr;
  if ( !style )
    style = 282001408;
  _w = w;
  _h = h;
  _x = x;
  _y = y;
  _cbg = cbg;
  _cfg = cfg;
  _style = style;
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)WinInit, 0, 0, 0);
  while ( (unsigned __int8)IsWin() ^ 1 )
    Sleep(1u);
  SetBkMode(_dc, 1);
  Clear();
}


// 原始位置：disp.cpp:271；地址：0x00406287
// 调试记录声明：void CreateWin(long unsigned int w, long unsigned int h, long unsigned int cfg, long unsigned int cbg, long unsigned int style, const char *winclass)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int style, const char *winclass)
{
  int v6;
  int v7;

  GetScrHeight();
  v6 = (GetScrHeight() - h) >> 1;
  GetScrWidth();
  v7 = (GetScrWidth() - w) >> 1;
  CreateWin(v7, v6, w, h, cfg, cbg, style, winclass);
}


// 原始位置：disp.cpp:275；地址：0x004062ED
// 调试记录声明：void CreateWin(long unsigned int w, long unsigned int h, long unsigned int cfg, long unsigned int cbg, long unsigned int style)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int style)
{
  CreateWin(w, h, cfg, cbg, style, DEFAULTCLASS);
}


// 原始位置：disp.cpp:279；地址：0x00406326
// 调试记录声明：void CreateWin(long unsigned int w, long unsigned int h, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  CreateWin(w, h, cfg, cbg, 0);
}


// 原始位置：disp.cpp:283；地址：0x00406357
// 调试记录声明：void CreateWin(long unsigned int w, long unsigned int h, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int c)
{
  CreateWin(w, h, 0, c);
}


// 原始位置：disp.cpp:287；地址：0x00406381
// 调试记录声明：void CreateWin(long unsigned int w, long unsigned int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl CreateWin(unsigned int w, unsigned int h)
{
  CreateWin(w, h, 0);
}


// 原始位置：disp.cpp:291；地址：0x004063A4
// 调试记录声明：void CreateWin(long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl CreateWin(unsigned int cbg)
{
  int v1;
  int v2;

  v1 = GetScrHeight() / 2;
  v2 = GetScrWidth() / 2;
  CreateWin(v2, v1, cbg);
}


// 原始位置：disp.cpp:295；地址：0x004063E5
// 调试记录声明：void CreateWin()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void CreateWin()
{
  int v0;
  int v1;

  v0 = GetScrHeight() / 2;
  v1 = GetScrWidth();
  CreateWin(v1 / 2, v0);
}


// 原始位置：disp.cpp:300；地址：0x0040641D
// 调试记录声明：void FreshWin()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void FreshWin()
{
  DrawBMP(_pmain, _pmscr);
  AddFPS();
}


// 原始位置：disp.cpp:305；地址：0x00406442
// 调试记录声明：void CloseWin()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void CloseWin()
{
  SendMessageA(_hw, 0x10u, 0, 0);
}


// 原始位置：disp.cpp:309；地址：0x00406473
// 调试记录声明：bool IsWin()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
BOOL IsWin()
{
  return _winb;
}


// 原始位置：disp.cpp:315；地址：0x0040647F
// 调试记录声明：double GetTimeR()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：LARGE_INTEGER tfreq；LARGE_INTEGER tcount。
long double GetTimeR()
{
  LARGE_INTEGER tcount;
  LARGE_INTEGER tfreq;

  if ( QueryPerformanceFrequency(&tfreq) != 0 )
    _tfreq = tfreq;
  if ( QueryPerformanceCounter(&tcount) != 0 )
    _tcount = tcount;
  return (double)(tcount.QuadPart - _tbegin.QuadPart) / (double)_tfreq.QuadPart;
}


// 原始位置：disp.cpp:322；地址：0x0040651B
// 调试记录声明：long unsigned int GetTime()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
signed __int64 GetTime()
{
  return (signed __int64)(GetTimeR() * 1000.0);
}


// 原始位置：disp.cpp:327；地址：0x0040654C
// 调试记录声明：void SetTitle(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetTitle(const char *s)
{
  SetWindowTextA(_hw, s);
}


// 原始位置：disp.cpp:331；地址：0x0040656C
// 调试记录声明：void SetTitleW(const short int *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetTitleW(const __int16 *s)
{
  SetWindowTextW(_hw, (LPCWSTR)s);
}


// 原始位置：disp.cpp:335；地址：0x0040658C
// 调试记录声明：char * GetTitle()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：char c[127]。
char *GetTitle()
{
  GetWindowTextA(_hw, GetTitle(void)::c, 127);
  return GetTitle(void)::c;
}


// 原始位置：disp.cpp:341；地址：0x004065B9
// 调试记录声明：short int * GetTitleW()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：short int c[127]。
WCHAR *GetTitleW()
{
  GetWindowTextW(_hw, &GetTitleW(void)::c, 127);
  return &GetTitleW(void)::c;
}


// 原始位置：disp.cpp:347；地址：0x004065E6
// 调试记录声明：void SetSize(long int x, long int y, long unsigned int w, long unsigned int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：RECT rect。
void __cdecl SetSize(int x, int y, unsigned int w, unsigned int h)
{
  RECT rect;

  rect.left = x;
  rect.top = y;
  rect.right = x + w;
  rect.bottom = y + h;
  AdjustWindowRect(&rect, _style, 0);
  MoveWindow(_hw, x, y, rect.right - rect.left, rect.bottom - rect.top, 1);
}


// 原始位置：disp.cpp:357；地址：0x00406674
// 调试记录声明：void SetSize(long unsigned int w, long unsigned int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetSize(unsigned int w, unsigned int h)
{
  int v2;
  int v3;

  v2 = GetPosY();
  v3 = GetPosX();
  SetSize(v3, v2, w, h);
}


// 原始位置：disp.cpp:361；地址：0x004066AA
// 调试记录声明：long unsigned int GetWidth()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int GetWidth()
{
  return _w;
}


// 原始位置：disp.cpp:365；地址：0x004066B4
// 调试记录声明：long unsigned int GetHeight()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int GetHeight()
{
  return _h;
}


// 原始位置：disp.cpp:369；地址：0x004066BE
// 调试记录声明：long unsigned int GetSize()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int GetSize()
{
  unsigned int v0;

  v0 = GetWidth() << 16;
  return v0 + GetHeight();
}


// 原始位置：disp.cpp:373；地址：0x004066D6
// 调试记录声明：long int GetScrWidth()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetScrWidth()
{
  return GetSystemMetrics(0);
}


// 原始位置：disp.cpp:377；地址：0x004066ED
// 调试记录声明：long int GetScrHeight()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetScrHeight()
{
  return GetSystemMetrics(1);
}


// 原始位置：disp.cpp:381；地址：0x00406704
// 调试记录声明：long unsigned int GetScrSize()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetScrSize()
{
  int v0;

  v0 = GetScrWidth() << 16;
  return v0 + GetScrHeight();
}


// 原始位置：disp.cpp:385；地址：0x00406722
// 调试记录声明：double GetScrCapsX()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
long double GetScrCapsX()
{
  HWND__ *v0;
  HDC__ *v1;

  v0 = GetDesktopWindow();
  v1 = GetDC(v0);
  return 144.0 / (long double)GetDeviceCaps(v1, 88);
}


// 原始位置：disp.cpp:389；地址：0x0040675B
// 调试记录声明：double GetScrCapsY()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
long double GetScrCapsY()
{
  HWND__ *v0;
  HDC__ *v1;

  v0 = GetDesktopWindow();
  v1 = GetDC(v0);
  return 144.0 / (long double)GetDeviceCaps(v1, 90);
}


// 原始位置：disp.cpp:393；地址：0x00406794
// 调试记录声明：long int GetBorderTitle()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetBorderTitle()
{
  return GetSystemMetrics(4);
}


// 原始位置：disp.cpp:397；地址：0x004067AB
// 调试记录声明：long int GetBorderWidth()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetBorderWidth()
{
  int result;

  if ( _style & 0x40000 )
    result = GetSystemMetrics(32);
  else
    result = GetSystemMetrics(7);
  return result;
}


// 原始位置：disp.cpp:401；地址：0x004067E1
// 调试记录声明：long int GetBorderHeight()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetBorderHeight()
{
  int result;

  if ( _style & 0x40000 )
    result = GetSystemMetrics(33);
  else
    result = GetSystemMetrics(8);
  return result;
}


// 原始位置：disp.cpp:405；地址：0x00406817
// 调试记录声明：long unsigned int GetBorderSize()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetBorderSize()
{
  int v0;

  v0 = GetBorderWidth() << 16;
  return v0 + GetBorderHeight();
}


// 原始位置：disp.cpp:409；地址：0x00406835
// 调试记录声明：void SetPos(long int x, long int y)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetPos(int x, int y)
{
  SetSize(x, y, _w, _h);
}


// 原始位置：disp.cpp:413；地址：0x00406864
// 调试记录声明：long int GetPosX()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：RECT rt。
LONG GetPosX()
{
  RECT rt;

  rt.left = 0;
  rt.top = 0;
  rt.right = 0;
  rt.bottom = 0;
  GetWindowRect(_hw, &rt);
  return rt.left;
}


// 原始位置：disp.cpp:419；地址：0x004068A2
// 调试记录声明：long int GetPosY()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：RECT rt。
LONG GetPosY()
{
  RECT rt;

  rt.left = 0;
  rt.top = 0;
  rt.right = 0;
  rt.bottom = 0;
  GetWindowRect(_hw, &rt);
  return rt.top;
}


// 原始位置：disp.cpp:425；地址：0x004068E0
// 调试记录声明：long unsigned int GetPos()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetPos()
{
  LONG v0;

  v0 = GetPosX() << 16;
  return v0 + GetPosY();
}


// 原始位置：disp.cpp:429；地址：0x004068FE
// 调试记录声明：pbitmap GetWin()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
pbitmap GetWin()
{
  return _pmain;
}


// 原始位置：disp.cpp:433；地址：0x00406908
// 调试记录声明：pbitmap GetScr()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
pbitmap GetScr()
{
  return _pmscr;
}


// 原始位置：disp.cpp:437；地址：0x00406912
// 调试记录声明：HGDIOBJ GetHwnd(pbitmap b)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
HGDIOBJ __cdecl GetHwnd(pbitmap b)
{
  return b->Handle;
}


// 原始位置：disp.cpp:441；地址：0x0040691C
// 调试记录声明：HWND GetHwnd()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
HWND GetHwnd()
{
  return _hw;
}


// 原始位置：disp.cpp:445；地址：0x00406926
// 调试记录声明：HDC GetDraw(pbitmap b)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
HDC __cdecl GetDraw(pbitmap b)
{
  return b->DC;
}


// 原始位置：disp.cpp:449；地址：0x00406931
// 调试记录声明：HDC GetDraw()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
HDC GetDraw()
{
  return _dc;
}


// 原始位置：disp.cpp:454；地址：0x0040693B
// 调试记录声明：long unsigned int GetBGColor()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
COLORREF GetBGColor()
{
  return _cbg;
}


// 原始位置：disp.cpp:458；地址：0x00406945
// 调试记录声明：void SetBGColor(long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetBGColor(unsigned int c)
{
  _cbg = c;
}


// 原始位置：disp.cpp:462；地址：0x00406953
// 调试记录声明：long unsigned int GetFGColor()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int GetFGColor()
{
  return _cfg;
}


// 原始位置：disp.cpp:466；地址：0x0040695D
// 调试记录声明：void SetFGColor(long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetFGColor(unsigned int c)
{
  _cfg = c;
}


// 原始位置：disp.cpp:470；地址：0x0040696B
// 调试记录声明：void SetPenWidth(long unsigned int pew)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetPenWidth(unsigned int pew)
{
  _pew = pew;
}


// 原始位置：disp.cpp:474；地址：0x00406979
// 调试记录声明：void SetPenColor(pbitmap b, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetPenColor(pbitmap b, unsigned int c)
{
  HPEN__ *v2;

  if ( c != _pec )
  {
    _pec = c;
    DeleteObject(_pe);
    if ( c == 1 )
      v2 = (HPEN__ *)GetStockObject(8);
    else
      v2 = CreatePen(0, _pew, c);
    _pe = v2;
    SelectObject(b->DC, v2);
  }
}


// 原始位置：disp.cpp:484；地址：0x004069FC
// 调试记录声明：void SetBrushColor(pbitmap b, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetBrushColor(pbitmap b, unsigned int c)
{
  HBRUSH__ *v2;

  if ( c != _brc )
  {
    _brc = c;
    DeleteObject(_br);
    if ( c == 1 )
      v2 = (HBRUSH__ *)GetStockObject(5);
    else
      v2 = CreateSolidBrush(c);
    _br = v2;
    SelectObject(b->DC, v2);
  }
}


// 原始位置：disp.cpp:494；地址：0x00406A6C
// 调试记录声明：void SetPenColor(long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetPenColor(unsigned int c)
{
  SetPenColor(_pmain, c);
}


// 原始位置：disp.cpp:498；地址：0x00406A89
// 调试记录声明：void SetBrushColor(long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetBrushColor(unsigned int c)
{
  SetBrushColor(_pmain, c);
}


// 原始位置：disp.cpp:502；地址：0x00406AA6
// 调试记录声明：unsigned char GetRed(long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned __int8 __cdecl GetRed(unsigned int c)
{
  return c;
}


// 原始位置：disp.cpp:506；地址：0x00406AAE
// 调试记录声明：unsigned char GetGreen(long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned __int8 __cdecl GetGreen(unsigned int c)
{
  return c >> 8;
}


// 原始位置：disp.cpp:510；地址：0x00406AB9
// 调试记录声明：unsigned char GetBlue(long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned __int8 __cdecl GetBlue(unsigned int c)
{
  return c >> 16;
}


// 原始位置：disp.cpp:514；地址：0x00406AC4
// 调试记录声明：unsigned char GetAlpha(long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned __int8 __cdecl GetAlpha(unsigned int c)
{
  return c >> 24;
}


// 原始位置：disp.cpp:518；地址：0x00406ACF
// 调试记录声明：long unsigned int GetRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl GetRGBA(unsigned __int8 r, unsigned __int8 g, unsigned __int8 b, unsigned __int8 a)
{
  return (g << 8) | (b << 16) | (a << 24) | r;
}


// 原始位置：disp.cpp:522；地址：0x00406B15
// 调试记录声明：long unsigned int GetRGB(unsigned char r, unsigned char g, unsigned char b)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl GetRGB(unsigned __int8 r, unsigned __int8 g, unsigned __int8 b)
{
  return GetRGBA(r, g, b, 0);
}


// 原始位置：disp.cpp:527；地址：0x00406B53
// 调试记录声明：void SetFont(pbitmap b)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetFont(pbitmap b)
{
  DeleteObject(_fns);
  _fns = CreateFontA(_fh, _fw, 0, 0, _fwg, _flt, _fud, _fsk, _fcs, 0, 0, 0, 0, _ffn);
  SelectObject(b->DC, _fns);
  if ( !_fh )
  {
    GetTextMetricsA(_dc, &_tm);
    _fh = _tm.tmHeight;
  }
}


// 原始位置：disp.cpp:546；地址：0x00406C4A
// 调试记录声明：void SetFont()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void SetFont()
{
  SetFont(_pmain);
}


// 原始位置：disp.cpp:550；地址：0x00406C60
// 调试记录声明：void SetFontWidth(long unsigned int w)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetFontWidth(unsigned int w)
{
  _fw = w;
  SetFont();
}


// 原始位置：disp.cpp:555；地址：0x00406C76
// 调试记录声明：void SetFontHeight(long unsigned int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetFontHeight(unsigned int h)
{
  _fh = h;
  SetFont();
}


// 原始位置：disp.cpp:560；地址：0x00406C8C
// 调试记录声明：void SetFontSize(long unsigned int w, long unsigned int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetFontSize(unsigned int w, unsigned int h)
{
  _fh = h;
  _fw = w;
  SetFont();
}


// 原始位置：disp.cpp:566；地址：0x00406CAA
// 调试记录声明：void SetFontWeight(long unsigned int wg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetFontWeight(unsigned int wg)
{
  _fwg = wg;
  SetFont();
}


// 原始位置：disp.cpp:571；地址：0x00406CC0
// 调试记录声明：void SetFontLtalic(long unsigned int lt)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetFontLtalic(unsigned int lt)
{
  _flt = lt;
  SetFont();
}


// 原始位置：disp.cpp:576；地址：0x00406CD6
// 调试记录声明：void SetFontUnderLine(long unsigned int ud)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetFontUnderLine(unsigned int ud)
{
  _fud = ud;
  SetFont();
}


// 原始位置：disp.cpp:581；地址：0x00406CEC
// 调试记录声明：void SetFontStrikeOut(long unsigned int sk)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetFontStrikeOut(unsigned int sk)
{
  _fsk = sk;
  SetFont();
}


// 原始位置：disp.cpp:586；地址：0x00406D02
// 调试记录声明：void SetFontCharSet(long unsigned int cs)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetFontCharSet(unsigned int cs_0)
{
  _fcs = cs_0;
  SetFont();
}


// 原始位置：disp.cpp:591；地址：0x00406D18
// 调试记录声明：void SetFontName(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetFontName(const char *s)
{
  strcpy(_ffn, s);
  SetFont();
}


// 原始位置：disp.cpp:596；地址：0x00406D39
// 调试记录声明：void GetStringSize(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl GetStringSize(const char *s)
{
  int v1;

  v1 = strlen(s);
  GetTextExtentPoint32A(_dc, s, v1, &_strz);
}


// 原始位置：disp.cpp:600；地址：0x00406D72
// 调试记录声明：long unsigned int GetStringWidth(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl GetStringWidth(const char *s)
{
  unsigned int result;

  GetStringSize(s);
  if ( _strz.cy <= 0 )
    result = 0;
  else
    result = _strz.cx * _fh / _strz.cy;
  return result;
}


// 原始位置：disp.cpp:605；地址：0x00406DB3
// 调试记录声明：long unsigned int GetStringHeight(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl GetStringHeight(const char *s)
{
  unsigned int result;

  GetStringSize(s);
  if ( _strz.cy <= 0 )
    result = 0;
  else
    result = _strz.cy * _fh / _strz.cy;
  return result;
}


// 原始位置：disp.cpp:611；地址：0x00406DF4
// 调试记录声明：void InitTextXY(pbitmap *b, const short int **s, long unsigned int *cfg, long unsigned int *cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl InitTextXY(pbitmap *b, const __int16 **s, unsigned int *cfg, unsigned int *cbg)
{
  if ( !*b )
    *b = _pmain;
  if ( !**s )
    *s = (const __int16 *)" ";
  if ( !*cfg )
    *cfg = 0xFFFFFF;
  SetTextColor((*b)->DC, *cfg);
  if ( *cbg )
  {
    SetBkColor((*b)->DC, *cbg);
    SetBkMode((*b)->DC, 2);
  }
  else
  {
    SetBkMode((*b)->DC, 1);
  }
}


// 原始位置：disp.cpp:624；地址：0x00406EB2
// 调试记录声明：void InitTextXY(pbitmap *b, const char **s, long unsigned int *cfg, long unsigned int *cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl InitTextXY(pbitmap *b, const char **s, unsigned int *cfg, unsigned int *cbg)
{
  if ( !*b )
    *b = _pmain;
  if ( !**s )
    *s = " ";
  if ( !*cfg )
    *cfg = 0xFFFFFF;
  SetTextColor((*b)->DC, *cfg);
  if ( *cbg )
  {
    SetBkColor((*b)->DC, *cbg);
    SetBkMode((*b)->DC, 2);
  }
  else
  {
    SetBkMode((*b)->DC, 1);
  }
}


// 原始位置：disp.cpp:637；地址：0x00406F6F
// 调试记录声明：void DrawTextXY(pbitmap b, const short int *s, long int x, long int y, long unsigned int w, long unsigned int h, long unsigned int cfg, long unsigned int cbg, long unsigned int format)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：RECT lpRect。
void __cdecl DrawTextXY(pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int format)
{
  int v9;
  RECT lpRect;

  InitTextXY(&b, &s, &cfg, &cbg);
  lpRect.left = x;
  lpRect.top = y;
  lpRect.right = x + w;
  lpRect.bottom = y + h;
  v9 = wcslen((const wchar_t *)s);
  DrawTextW(b->DC, (LPCWSTR)s, v9, &lpRect, format);
  _fx = x + w;
  _fy = y;
}


// 原始位置：disp.cpp:649；地址：0x0040700A
// 调试记录声明：void DrawTextXY(pbitmap b, const short int *s, long int x, long int y, long unsigned int w, long unsigned int h, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：RECT lpRect。
void __cdecl DrawTextXY(pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  int v8;
  RECT lpRect;

  InitTextXY(&b, &s, &cfg, &cbg);
  lpRect.left = x;
  lpRect.top = y;
  lpRect.right = x + w;
  lpRect.bottom = y + h;
  v8 = wcslen((const wchar_t *)s);
  DrawTextW(b->DC, (LPCWSTR)s, v8, &lpRect, 0x25u);
  _fx = x + w;
  _fy = y;
}


// 原始位置：disp.cpp:661；地址：0x004070A6
// 调试记录声明：void DrawTextXY(pbitmap b, const char *s, long int x, long int y, long unsigned int w, long unsigned int h, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：RECT lpRect。
void __cdecl DrawTextXY(pbitmap b, const char *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  int v8;
  RECT lpRect;

  InitTextXY(&b, &s, &cfg, &cbg);
  lpRect.left = x;
  lpRect.top = y;
  lpRect.right = x + w;
  lpRect.bottom = y + h;
  v8 = strlen(s);
  DrawTextA(b->DC, s, v8, &lpRect, 0x25u);
  _fx = x + w;
  _fy = y;
}


// 原始位置：disp.cpp:673；地址：0x00407142
// 调试记录声明：void DrawTextXY(pbitmap b, const char *s, long int x, long int y, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextXY(pbitmap b, const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  int v6;
  unsigned int v7;

  InitTextXY(&b, &s, &cfg, &cbg);
  v6 = strlen(s);
  TextOutA(b->DC, x, y, s, v6);
  v7 = GetStringWidth(s);
  _fx = v7 + x;
  _fy = y;
}


// 原始位置：disp.cpp:680；地址：0x004071C1
// 调试记录声明：void DrawTextXY(pbitmap b, const char *s, long int x, long int y, long unsigned int cfg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextXY(pbitmap b, const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXY(b, s, x, y, cfg, 0);
}


// 原始位置：disp.cpp:684；地址：0x004071F9
// 调试记录声明：void DrawTextXY(const char *s, long int x, long int y, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextXY(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(0, s, x, y, cfg, cbg);
}


// 原始位置：disp.cpp:688；地址：0x00407231
// 调试记录声明：void DrawTextXY(const char *s, long int x, long int y, long unsigned int cfg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextXY(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXY(0, s, x, y, cfg);
}


// 原始位置：disp.cpp:692；地址：0x00407262
// 调试记录声明：void DrawTextXY(const char *s, long int x, long unsigned int y)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextXY(const char *s, int x, unsigned int y)
{
  DrawTextXY(s, x, y, 0);
}


// 原始位置：disp.cpp:696；地址：0x0040728C
// 调试记录声明：void DrawTextA(const char *s, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextA(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(s, _fx, _fy, cfg, cbg);
}


// 原始位置：disp.cpp:700；地址：0x004072C1
// 调试记录声明：void DrawTextA(const char *s, long unsigned int cfg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextA(const char *s, unsigned int cfg)
{
  DrawTextA(s, cfg, 0);
}


// 原始位置：disp.cpp:704；地址：0x004072E4
// 调试记录声明：void DrawTextA(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextA(const char *s)
{
  DrawTextA(s, 0);
}


// 原始位置：disp.cpp:708；地址：0x00407300
// 调试记录声明：void DrawTextlnXY(const char *s, long int x, long int y, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextlnXY(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(s, x, y, cfg, cbg);
  _fx = x;
  _fy = GetStringHeight(s) + y;
}


// 原始位置：disp.cpp:714；地址：0x0040734F
// 调试记录声明：void DrawTextlnXY(const char *s, long int x, long int y, long unsigned int cfg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextlnXY(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextlnXY(s, x, y, cfg, 0);
}


// 原始位置：disp.cpp:718；地址：0x00407380
// 调试记录声明：void DrawTextlnXY(const char *s, long int x, long unsigned int y)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextlnXY(const char *s, int x, unsigned int y)
{
  DrawTextlnXY(s, x, y, 0);
}


// 原始位置：disp.cpp:722；地址：0x004073AA
// 调试记录声明：void DrawTextln(const char *s, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextln(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextlnXY(s, _fx, _fy, cfg, cbg);
}


// 原始位置：disp.cpp:726；地址：0x004073DF
// 调试记录声明：void DrawTextln(const char *s, long unsigned int cfg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextln(const char *s, unsigned int cfg)
{
  DrawTextln(s, cfg, 0);
}


// 原始位置：disp.cpp:730；地址：0x00407402
// 调试记录声明：void DrawTextln(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextln(const char *s)
{
  DrawTextln(s, 0);
}


// 原始位置：disp.cpp:734；地址：0x0040741E
// 调试记录声明：void DrawTextln()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void DrawTextln()
{
  DrawTextln(s);
}


// 原始位置：disp.cpp:738；地址：0x00407433
// 调试记录声明：void DrawTextXYw(pbitmap b, const char *s, long int x, long int y, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：long unsigned int fi。
void __cdecl DrawTextXYw(pbitmap b, const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  unsigned int fi;

  InitTextXY(&b, &s, &cfg, &cbg);
  for ( fi = 0; strlen(s) > fi; ++fi )
  {
    TextOutA(b->DC, x, y, &s[fi], 1);
    x += _fw;
  }
  _fx = x;
  _fy = y;
}


// 原始位置：disp.cpp:750；地址：0x004074C9
// 调试记录声明：void DrawTextXYw(pbitmap b, const char *s, long int x, long int y, long unsigned int cfg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextXYw(pbitmap b, const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXYw(b, s, x, y, cfg, 0);
}


// 原始位置：disp.cpp:754；地址：0x00407501
// 调试记录声明：void DrawTextXYw(const char *s, long int x, long int y, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextXYw(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(0, s, x, y, cfg, cbg);
}


// 原始位置：disp.cpp:758；地址：0x00407539
// 调试记录声明：void DrawTextXYw(const char *s, long int x, long int y, long unsigned int cfg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextXYw(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXYw(0, s, x, y, cfg);
}


// 原始位置：disp.cpp:762；地址：0x0040756A
// 调试记录声明：void DrawTextXYw(const char *s, long int x, long unsigned int y)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextXYw(const char *s, int x, unsigned int y)
{
  DrawTextXYw(s, x, y, 0);
}


// 原始位置：disp.cpp:766；地址：0x00407594
// 调试记录声明：void DrawTextw(const char *s, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextw(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(s, _fx, _fy, cfg, cbg);
}


// 原始位置：disp.cpp:770；地址：0x004075C9
// 调试记录声明：void DrawTextw(const char *s, long unsigned int cfg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextw(const char *s, unsigned int cfg)
{
  DrawTextw(s, cfg, 0);
}


// 原始位置：disp.cpp:774；地址：0x004075EC
// 调试记录声明：void DrawTextw(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextw(const char *s)
{
  DrawTextw(s, 0);
}


// 原始位置：disp.cpp:778；地址：0x00407608
// 调试记录声明：void DrawTextlnXYw(const char *s, long int x, long int y, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextlnXYw(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(s, x, y, cfg, cbg);
  _fx = x;
  _fy = y + _fh;
}


// 原始位置：disp.cpp:784；地址：0x0040764F
// 调试记录声明：void DrawTextlnXYw(const char *s, long int x, long int y, long unsigned int cfg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextlnXYw(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextlnXYw(s, x, y, cfg, 0);
}


// 原始位置：disp.cpp:788；地址：0x00407680
// 调试记录声明：void DrawTextlnXYw(const char *s, long int x, long unsigned int y)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextlnXYw(const char *s, int x, unsigned int y)
{
  DrawTextlnXYw(s, x, y, 0);
}


// 原始位置：disp.cpp:792；地址：0x004076AA
// 调试记录声明：void DrawTextlnw(const char *s, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextlnw(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextlnXYw(s, _fx, _fy, cfg, cbg);
}


// 原始位置：disp.cpp:796；地址：0x004076DF
// 调试记录声明：void DrawTextlnw(const char *s, long unsigned int cfg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextlnw(const char *s, unsigned int cfg)
{
  DrawTextlnw(s, cfg, 0);
}


// 原始位置：disp.cpp:800；地址：0x00407702
// 调试记录声明：void DrawTextlnw(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawTextlnw(const char *s)
{
  DrawTextlnw(s, 0);
}


// 原始位置：disp.cpp:807；地址：0x0040771E
// 调试记录声明：long unsigned int GetPixel(pbitmap b, long unsigned int x, long unsigned int y)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl GetPixel(pbitmap b, unsigned int x, unsigned int y)
{
  if ( !b )
    b = _pmain;
  return GetPixel(b->DC, x, y);
}


// 原始位置：disp.cpp:812；地址：0x00407753
// 调试记录声明：long unsigned int GetPixel(long unsigned int x, long unsigned int y)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl GetPixel(unsigned int x, unsigned int y)
{
  return GetPixel(0, x, y);
}


// 原始位置：disp.cpp:816；地址：0x00407775
// 调试记录声明：void SetPixel(pbitmap b, long unsigned int x, long unsigned int y, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetPixel(pbitmap b, unsigned int x, unsigned int y, unsigned int c)
{
  if ( !b )
    b = _pmain;
  if ( !c )
    c = _cfg;
  SetPixel(b->DC, x, y, c);
}


// 原始位置：disp.cpp:822；地址：0x004077C4
// 调试记录声明：void SetPixel(long unsigned int x, long unsigned int y, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetPixel(unsigned int x, unsigned int y, unsigned int c)
{
  SetPixel(0, x, y, c);
}


// 原始位置：disp.cpp:826；地址：0x004077EE
// 调试记录声明：void SetPixel(long unsigned int x, long unsigned int y)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetPixel(unsigned int x, unsigned int y)
{
  SetPixel(x, y, 0);
}


// 原始位置：disp.cpp:830；地址：0x00407811
// 调试记录声明：void Line(pbitmap b, long int x, long int y, long int w, long int h, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl Line(pbitmap b, int x, int y, int w, int h, unsigned int c)
{
  if ( !b )
    b = _pmain;
  if ( !c )
    c = _cfg;
  SetPenColor(b, c);
  MoveToEx(b->DC, x, y, 0);
  LineTo(b->DC, w + x, y + h);
}


// 原始位置：disp.cpp:838；地址：0x00407899
// 调试记录声明：void Line(long int x, long int y, long int w, long int h, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl Line(int x, int y, int w, int h, unsigned int c)
{
  Line(0, x, y, w, h, c);
}


// 原始位置：disp.cpp:842；地址：0x004078D1
// 调试记录声明：void Bar(pbitmap b, long int x, long int y, long int w, long int h, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：RECT lpRect。
void __cdecl Bar(pbitmap b, int x, int y, int w, int h, unsigned int cfg, unsigned int cbg)
{
  RECT lpRect;

  if ( !b )
    b = _pmain;
  if ( !cfg )
    cfg = 1;
  if ( !cbg )
    cbg = _cfg;
  lpRect.left = x;
  lpRect.top = y;
  lpRect.right = x + w;
  lpRect.bottom = y + h;
  if ( cbg != 1 )
  {
    SetBrushColor(b, cbg);
    FillRect(b->DC, &lpRect, _br);
  }
  if ( cfg != 1 )
  {
    SetBrushColor(b, cfg);
    SetPenColor(b, cfg);
    FrameRect(b->DC, &lpRect, (HBRUSH)_pe);
  }
}


// 原始位置：disp.cpp:864；地址：0x004079AB
// 调试记录声明：void Bar(pbitmap b, long int x, long int y, long int w, long int h, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl Bar(pbitmap b, int x, int y, int w, int h, unsigned int c)
{
  Bar(b, x, y, w, h, 0, c);
}


// 原始位置：disp.cpp:868；地址：0x004079EA
// 调试记录声明：void Bar(long int x, long int y, long int w, long int h, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl Bar(int x, int y, int w, int h, unsigned int cfg, unsigned int cbg)
{
  Bar(0, x, y, w, h, cfg, cbg);
}


// 原始位置：disp.cpp:872；地址：0x00407A29
// 调试记录声明：void Bar(long int x, long int y, long int w, long int h, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl Bar(int x, int y, int w, int h, unsigned int c)
{
  Bar(x, y, w, h, 0, c);
}


// 原始位置：disp.cpp:876；地址：0x00407A61
// 调试记录声明：void Bar(long int x, long int y, long int w, long int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl Bar(int x, int y, int w, int h)
{
  Bar(x, y, w, h, 0);
}


// 原始位置：disp.cpp:880；地址：0x00407A92
// 调试记录声明：void Clear(pbitmap b, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl Clear(pbitmap b, unsigned int c)
{
  if ( !b )
    b = _pmain;
  if ( !c )
    c = _cbg;
  Bar(b, 0, 0, b->Width, b->Height, 0, c);
}


// 原始位置：disp.cpp:886；地址：0x00407AF9
// 调试记录声明：void Clear(pbitmap b)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl Clear(pbitmap b)
{
  Clear(b, 0);
}


// 原始位置：disp.cpp:890；地址：0x00407B15
// 调试记录声明：void Clear(long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl Clear(unsigned int c)
{
  Clear(0, c);
}


// 原始位置：disp.cpp:894；地址：0x00407B31
// 调试记录声明：void Clear()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Clear()
{
  Clear(0);
}


// 原始位置：disp.cpp:899；地址：0x00407B46
// 调试记录声明：pbitmap CreateBMP(pbitmap b, long unsigned int w, long unsigned int h, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：pbitmap bmp。
pbitmap __cdecl CreateBMP(pbitmap b, unsigned int w, unsigned int h, unsigned int c)
{
  pbitmap bmp;

  if ( !b )
    b = GetWin();
  if ( !w )
    w = b->Width;
  if ( !h )
    h = b->Height;
  if ( !c )
    c = b->Color;
  bmp = (pbitmap)calloc(1u, 0x14u);
  bmp->Width = w;
  bmp->Height = h;
  bmp->Color = c;
  while ( !bmp->DC )
    bmp->DC = CreateCompatibleDC(_dc);
  while ( !bmp->Handle )
    bmp->Handle = CreateCompatibleBitmap(_dc, bmp->Width, bmp->Height);
  SelectObject(bmp->DC, bmp->Handle);
  Clear(bmp, c);
  return bmp;
}


// 原始位置：disp.cpp:915；地址：0x00407C48
// 调试记录声明：pbitmap CreateBMP(pbitmap b)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
pbitmap __cdecl CreateBMP(pbitmap b)
{
  return CreateBMP(b, 0, 0, 0);
}


// 原始位置：disp.cpp:919；地址：0x00407C73
// 调试记录声明：pbitmap CreateBMP(long unsigned int w, long unsigned int h, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
pbitmap __cdecl CreateBMP(unsigned int w, unsigned int h, unsigned int c)
{
  return CreateBMP(0, w, h, c);
}


// 原始位置：disp.cpp:923；地址：0x00407C9C
// 调试记录声明：pbitmap CreateBMP(long unsigned int w, long unsigned int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
pbitmap __cdecl CreateBMP(unsigned int w, unsigned int h)
{
  return CreateBMP(w, h, 0);
}


// 原始位置：disp.cpp:927；地址：0x00407CBE
// 调试记录声明：pbitmap CreateBMP()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
pbitmap CreateBMP()
{
  return CreateBMP(0, 0);
}


// 原始位置：disp.cpp:931；地址：0x00407CDA
// 调试记录声明：void ReleaseBMP(pbitmap b)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl ReleaseBMP(pbitmap b)
{
  if ( b )
  {
    if ( b->DC == _dc )
      ReleaseDC(_hw, b->DC);
    if ( b->DC != _dc )
      DeleteDC(b->DC);
    if ( b->Handle != _hw )
      DeleteObject(b->Handle);
    if ( b != _pmscr )
      free(b);
  }
}


// 原始位置：disp.cpp:953；地址：0x00407D65
// 调试记录声明：void ReleaseBMP()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void ReleaseBMP()
{
  bitmap *v0;
  bitmap *v1;

  v0 = GetScr();
  ReleaseBMP(v0);
  v1 = GetWin();
  ReleaseBMP(v1);
}


// 原始位置：disp.cpp:958；地址：0x00407D88
// 调试记录声明：pbitmap LoadBMP(const char *s, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 可见操作：GDI+ 绘图。
// 原始局部变量：UINT bw；UINT bh；pbitmap bmp。
pbitmap __cdecl LoadBMP(const char *s, unsigned int c)
{
  float v2;
  long double v3; // fst7
  int v4;
  int v5;
  UINT bh_0;
  UINT bw;
  pbitmap bmp;

  if ( !c )
    c = GetBGColor();
  MultiByteToWideChar(0, 0, s, -1, _GdiWideChar, 127);
  GdiplusStartup((int)&_GdiToken, (int)&_GdiStart, 0);
  GdipLoadImageFromFile((int)_GdiWideChar, (int)&_GdiImage);
  GdipGetImageWidth((int)_GdiImage, (int)&bw);
  GdipGetImageHeight((int)_GdiImage, (int)&bh_0);
  bmp = CreateBMP(bw, bh_0, c);
  GdipCreateFromHDC((int)bmp->DC, (int)&_GdiGraph);
  v2 = (long double)bh_0;
  v3 = v2;
  *(float *)&v4 = (long double)bw;
  *(float *)&v5 = v3;
  GdipDrawImageRect((int)_GdiGraph, (int)_GdiImage, COERCE_INT(0.0), COERCE_INT(0.0), v4, v5);
  GdipDisposeImage((int)_GdiImage);
  GdipDeleteGraphics((int)_GdiGraph);
  GdiplusShutdown(_GdiToken);
  return bmp;
}


// 原始位置：disp.cpp:975；地址：0x00407EFC
// 调试记录声明：pbitmap LoadBMP(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
pbitmap __cdecl LoadBMP(const char *s)
{
  return LoadBMP(s, 0);
}


// 原始位置：disp.cpp:979；地址：0x00407F17
// 调试记录声明：void SaveBMP(pbitmap b, const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 可见操作：GDI+ 绘图。
void __cdecl SaveBMP(pbitmap b, const char *s)
{
  MultiByteToWideChar(0, 0, s, -1, _GdiWideChar, 127);
  GdiplusStartup((int)&_GdiToken, (int)&_GdiStart, 0);
  GdipCreateBitmapFromHBITMAP((int)b->Handle, 0, (int)&_GdiBitmap);
  GdipSaveImageToFile((int)_GdiBitmap, (int)_GdiWideChar, (int)&GDIImageFormatPNG, 0);
  GdipDisposeImage((int)_GdiBitmap);
  GdiplusShutdown(_GdiToken);
}


// 原始位置：disp.cpp:988；地址：0x00407FDD
// 调试记录声明：void DrawBMP(pbitmap bs, pbitmap bd, long unsigned int xs, long unsigned int ys, long unsigned int ws, long unsigned int hs, long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：long unsigned int alpha；pbitmap bm；BLENDFUNCTION ftn。
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  pbitmap bm;
  BLENDFUNCTION ST54_4_17;
  unsigned __int8 alpha;
  unsigned int ca;

  if ( !bs )
    bs = GetWin();
  if ( !bd )
    bd = GetWin();
  if ( !ws )
    ws = bs->Width;
  if ( !hs )
    hs = bs->Height;
  if ( !wd )
    wd = bs->Width;
  if ( !hd )
    hd = bs->Height;
  if ( !c )
    c = bs->Color;
  alpha = GetAlpha(c);
  ca = c & 0xFFFFFF;
  if ( alpha )
  {
    bm = CreateBMP(wd, hd, ca);
    StretchBlt(bm->DC, 0, 0, wd, hd, bd->DC, xd, yd, wd, hd, 0xCC0020u);
    TransparentBlt(bm->DC, 0, 0, wd, hd, bs->DC, xs, ys, ws, hs, ca);
    *(_WORD *)&ST54_4_17.BlendOp = 0;
    *(_WORD *)&ST54_4_17.SourceConstantAlpha = (unsigned __int8)~alpha;
    AlphaBlend(bd->DC, xd, yd, wd, hd, bm->DC, 0, 0, wd, hd, ST54_4_17);
    ReleaseBMP(bm);
  }
  else
  {
    TransparentBlt(bd->DC, xd, yd, wd, hd, bs->DC, xs, ys, ws, hs, ca);
  }
}


// 原始位置：disp.cpp:1013；地址：0x0040826C
// 调试记录声明：void DrawBMP(pbitmap bs, pbitmap bd, long unsigned int xs, long unsigned int ys, long unsigned int ws, long unsigned int hs, long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, bd, xs, ys, ws, hs, xd, yd, wd, hd, 0);
}


// 原始位置：disp.cpp:1017；地址：0x004082C7
// 调试记录声明：void DrawBMP(pbitmap bs, pbitmap bd, long unsigned int xs, long unsigned int ys, long unsigned int xd, long unsigned int yd, long unsigned int w, long unsigned int h, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(bs, bd, xs, ys, w, h, xd, yd, w, h, c);
}


// 原始位置：disp.cpp:1021；地址：0x00408321
// 调试记录声明：void DrawBMP(pbitmap bs, pbitmap bd, long unsigned int xs, long unsigned int ys, long unsigned int xd, long unsigned int yd, long unsigned int w, long unsigned int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(bs, bd, xs, ys, xd, yd, w, h, 0);
}


// 原始位置：disp.cpp:1025；地址：0x0040836E
// 调试记录声明：void DrawBMP(pbitmap bs, pbitmap bd, long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, bd, 0, 0, 0, 0, xd, yd, wd, hd, c);
}


// 原始位置：disp.cpp:1029；地址：0x004083CC
// 调试记录声明：void DrawBMP(pbitmap bs, pbitmap bd, long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, bd, xd, yd, wd, hd, 0);
}


// 原始位置：disp.cpp:1033；地址：0x0040840B
// 调试记录声明：void DrawBMP(pbitmap bs, pbitmap bd, long unsigned int xd, long unsigned int yd, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(bs, bd, xd, yd, 0, 0, c);
}


// 原始位置：disp.cpp:1037；地址：0x0040844B
// 调试记录声明：void DrawBMP(pbitmap bs, pbitmap bd, long unsigned int xd, long unsigned int yd)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd)
{
  DrawBMP(bs, bd, xd, yd, 0);
}


// 原始位置：disp.cpp:1041；地址：0x0040847C
// 调试记录声明：void DrawBMP(pbitmap bs, pbitmap bd, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int c)
{
  DrawBMP(bs, bd, 0, 0, c);
}


// 原始位置：disp.cpp:1045；地址：0x004084AE
// 调试记录声明：void DrawBMP(pbitmap bs, pbitmap bd)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, pbitmap bd)
{
  DrawBMP(bs, bd, 0);
}


// 原始位置：disp.cpp:1049；地址：0x004084D1
// 调试记录声明：void DrawBMP(pbitmap bs, long unsigned int xs, long unsigned int ys, long unsigned int ws, long unsigned int hs, long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, 0, xs, ys, ws, hs, xd, yd, wd, hd, c);
}


// 原始位置：disp.cpp:1053；地址：0x0040852C
// 调试记录声明：void DrawBMP(pbitmap bs, long unsigned int xs, long unsigned int ys, long unsigned int ws, long unsigned int hs, long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, xs, ys, ws, hs, xd, yd, wd, hd, 0);
}


// 原始位置：disp.cpp:1057；地址：0x00408580
// 调试记录声明：void DrawBMP(pbitmap bs, long unsigned int xs, long unsigned int ys, long unsigned int xd, long unsigned int yd, long unsigned int w, long unsigned int h, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(bs, xs, ys, w, h, xd, yd, w, h, c);
}


// 原始位置：disp.cpp:1061；地址：0x004085D3
// 调试记录声明：void DrawBMP(pbitmap bs, long unsigned int xs, long unsigned int ys, long unsigned int xd, long unsigned int yd, long unsigned int w, long unsigned int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(bs, xs, ys, xd, yd, w, h, 0);
}


// 原始位置：disp.cpp:1065；地址：0x00408619
// 调试记录声明：void DrawBMP(pbitmap bs, long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, 0, 0, 0, 0, xd, yd, wd, hd, c);
}


// 原始位置：disp.cpp:1069；地址：0x00408670
// 调试记录声明：void DrawBMP(pbitmap bs, long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, xd, yd, wd, hd, 0);
}


// 原始位置：disp.cpp:1073；地址：0x004086A8
// 调试记录声明：void DrawBMP(pbitmap bs, long unsigned int xd, long unsigned int yd, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(bs, xd, yd, 0, 0, c);
}


// 原始位置：disp.cpp:1077；地址：0x004086E1
// 调试记录声明：void DrawBMP(pbitmap bs, long unsigned int xd, long unsigned int yd)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd)
{
  DrawBMP(bs, xd, yd, 0);
}


// 原始位置：disp.cpp:1081；地址：0x0040870B
// 调试记录声明：void DrawBMP(pbitmap bs, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs, unsigned int c)
{
  DrawBMP(bs, 0, 0, c);
}


// 原始位置：disp.cpp:1085；地址：0x00408736
// 调试记录声明：void DrawBMP(pbitmap bs)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(pbitmap bs)
{
  DrawBMP(bs, 0);
}


// 原始位置：disp.cpp:1089；地址：0x00408752
// 调试记录声明：void DrawBMP(long unsigned int xs, long unsigned int ys, long unsigned int ws, long unsigned int hs, long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(0, xs, ys, ws, hs, xd, yd, wd, hd, c);
}


// 原始位置：disp.cpp:1093；地址：0x004087A6
// 调试记录声明：void DrawBMP(long unsigned int xs, long unsigned int ys, long unsigned int ws, long unsigned int hs, long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(0, xs, ys, ws, hs, xd, yd, wd, hd);
}


// 原始位置：disp.cpp:1097；地址：0x004087F3
// 调试记录声明：void DrawBMP(long unsigned int xs, long unsigned int ys, long unsigned int xd, long unsigned int yd, long unsigned int w, long unsigned int h, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(0, xs, ys, xd, yd, w, h, c);
}


// 原始位置：disp.cpp:1101；地址：0x00408839
// 调试记录声明：void DrawBMP(long unsigned int xs, long unsigned int ys, long unsigned int xd, long unsigned int yd, long unsigned int w, long unsigned int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(0, xs, ys, xd, yd, w, h);
}


// 原始位置：disp.cpp:1105；地址：0x00408878
// 调试记录声明：void DrawBMP(long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(0, xd, yd, wd, hd, c);
}


// 原始位置：disp.cpp:1109；地址：0x004088B0
// 调试记录声明：void DrawBMP(long unsigned int xd, long unsigned int yd, long unsigned int wd, long unsigned int hd)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(0, xd, yd, wd, hd);
}


// 原始位置：disp.cpp:1113；地址：0x004088E1
// 调试记录声明：void DrawBMP(long unsigned int xd, long unsigned int yd, long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(0, xd, yd, c);
}


// 原始位置：disp.cpp:1117；地址：0x0040890B
// 调试记录声明：void DrawBMP(long unsigned int xd, long unsigned int yd)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(unsigned int xd, unsigned int yd)
{
  DrawBMP(0, xd, yd);
}


// 原始位置：disp.cpp:1121；地址：0x0040892E
// 调试记录声明：void DrawBMP(long unsigned int c)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl DrawBMP(unsigned int c)
{
  DrawBMP(0, c);
}


// 原始位置：disp.cpp:1125；地址：0x0040894A
// 调试记录声明：void DrawBMP()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void DrawBMP()
{
  DrawBMP(0);
}


// 原始位置：disp.cpp:1130；地址：0x0040895F
// 调试记录声明：long unsigned int HI(uint64_t val)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl HI(uint64_t val)
{
  return HIDWORD(val);
}


// 原始位置：disp.cpp:1134；地址：0x0040897D
// 调试记录声明：long unsigned int LO(uint64_t val)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl LO(uint64_t val)
{
  return val;
}


// 原始位置：disp.cpp:1138；地址：0x00408994
// 调试记录声明：void SendMsg()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void SendMsg()
{
  TranslateMessage(&_mst);
  DispatchMessageA(&_mst);
}


// 原始位置：disp.cpp:1143；地址：0x004089BB
// 调试记录声明：bool CustomMsg()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：bool result。
BOOL CustomMsg()
{
  MSG *v0;
  bool result;

  result = _msusr[_msi].message != 0;
  if ( result )
  {
    v0 = &_msusr[_msi];
    _ms.hwnd = v0->hwnd;
    _ms.message = v0->message;
    _ms.wParam = v0->wParam;
    _ms.lParam = v0->lParam;
    _ms.time = v0->time;
    _ms.pt.x = v0->pt.x;
    _ms.pt.y = v0->pt.y;
    _msusr[_msi++].message = 0;
    if ( _msi > 0x1000 )
      _msi = 1;
  }
  return result;
}


// 原始位置：disp.cpp:1155；地址：0x00408A68
// 调试记录声明：bool IsNextMsg()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：bool result。
BOOL IsNextMsg()
{
  MSG *v0;
  MSG *v1;
  bool result;

  if ( !((unsigned __int8)CustomMsg() ^ 1) )
    return 1;
  result = _mswini != _mswinj;
  if ( _mswini != _mswinj )
  {
    _mswinj = ((_WORD)_mswinj + 1) & 0xFFF;
    v0 = &_mswin[_mswinj];
    _ms.hwnd = v0->hwnd;
    _ms.message = v0->message;
    _ms.wParam = v0->wParam;
    _ms.lParam = v0->lParam;
    _ms.time = v0->time;
    _ms.pt.x = v0->pt.x;
    _ms.pt.y = v0->pt.y;
    while ( !_ms.message )
    {
      v1 = &_mswin[_mswinj];
      _ms.hwnd = v1->hwnd;
      _ms.message = v1->message;
      _ms.wParam = v1->wParam;
      _ms.lParam = v1->lParam;
      _ms.time = v1->time;
      _ms.pt.x = v1->pt.x;
      _ms.pt.y = v1->pt.y;
    }
  }
  return result;
}


// 原始位置：disp.cpp:1170；地址：0x00408B62
// 调试记录声明：long unsigned int GetNextMsg()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
UINT GetNextMsg()
{
  return _ms.message;
}


// 原始位置：disp.cpp:1174；地址：0x00408B6C
// 调试记录声明：long unsigned int WaitNextMsg()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
UINT WaitNextMsg()
{
  char v0;

  if ( (unsigned __int8)CustomMsg() ^ 1 )
  {
    while ( 1 )
    {
      v0 = (unsigned __int8)IsNextMsg() ^ 1 && (unsigned __int8)IsWin() ? 1 : 0;
      if ( !v0 )
        break;
      Sleep(1u);
    }
  }
  return GetNextMsg();
}


// 原始位置：disp.cpp:1182；地址：0x00408BBB
// 调试记录声明：bool IsMsg(const long unsigned int *uM, long unsigned int length)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：long unsigned int mi。
bool __cdecl IsMsg(const unsigned int *uM, unsigned int length)
{
  unsigned int mi;

  for ( mi = 0; mi < length; ++mi )
  {
    if ( _ms.message == uM[mi] )
      return 1;
  }
  return 0;
}


// 原始位置：disp.cpp:1187；地址：0x00408BFF
// 调试记录声明：uint64_t GetMsg(const long unsigned int *uM, long unsigned int length)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
uint64_t __cdecl GetMsg(const unsigned int *uM, unsigned int length)
{
  LPARAM v2;
  WPARAM v3;

  if ( IsMsg(uM, length) )
  {
    v2 = _ms.lParam;
    v3 = (_ms.lParam >> 31) | _ms.wParam;
  }
  else
  {
    v2 = 0;
    v3 = 0;
  }
  return __PAIR__(v3, v2);
}


// 原始位置：disp.cpp:1191；地址：0x00408C5F
// 调试记录声明：uint64_t WaitMsg(const long unsigned int *uM, long unsigned int length)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
uint64_t __cdecl WaitMsg(const unsigned int *uM, unsigned int length)
{
  do
    WaitNextMsg();
  while ( !IsMsg(uM, length) );
  return GetMsg(uM, length);
}


// 原始位置：disp.cpp:1200；地址：0x00408C99
// 调试记录声明：bool IsMsg(long unsigned int uM)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：long unsigned int ums[1]。
bool __cdecl IsMsg(unsigned int uM)
{
  unsigned int ums[1];

  ums[0] = uM;
  return IsMsg(ums, 1u);
}


// 原始位置：disp.cpp:1205；地址：0x00408CBA
// 调试记录声明：uint64_t GetMsg(long unsigned int uM)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：long unsigned int ums[1]。
uint64_t __cdecl GetMsg(unsigned int uM)
{
  unsigned int ums[1];

  ums[0] = uM;
  return GetMsg(ums, 1u);
}


// 原始位置：disp.cpp:1210；地址：0x00408CDB
// 调试记录声明：uint64_t WaitMsg(long unsigned int uM)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：long unsigned int ums[1]。
uint64_t __cdecl WaitMsg(unsigned int uM)
{
  unsigned int ums[1];

  ums[0] = uM;
  return WaitMsg(ums, 1u);
}


// 原始位置：disp.cpp:1215；地址：0x00408CFC
// 调试记录声明：bool IsKey(long unsigned int k)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool __cdecl IsKey(unsigned int k)
{
  return IsMsg(0x100u) && (!k || GetKey() == k);
}


// 原始位置：disp.cpp:1219；地址：0x00408D30
// 调试记录声明：bool IsKey()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool IsKey()
{
  return IsKey(0);
}


// 原始位置：disp.cpp:1223；地址：0x00408D44
// 调试记录声明：long unsigned int GetKey()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int GetKey()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x100u);
  return HI(v0);
}


// 原始位置：disp.cpp:1227；地址：0x00408D64
// 调试记录声明：long unsigned int WaitKey(long unsigned int k)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl WaitKey(unsigned int k)
{
  while ( !IsKey() )
    WaitNextMsg();
  return GetKey();
}


// 原始位置：disp.cpp:1232；地址：0x00408D84
// 调试记录声明：long unsigned int WaitKey()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int WaitKey()
{
  return WaitKey(0);
}


// 原始位置：disp.cpp:1236；地址：0x00408D98
// 调试记录声明：bool IsMouse(long unsigned int m)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool __cdecl IsMouse(unsigned int m)
{
  return IsMsg(_bdn, 3u) && (!m || GetMouse() == m);
}


// 原始位置：disp.cpp:1240；地址：0x00408DD4
// 调试记录声明：bool IsMouse()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool IsMouse()
{
  return IsMouse(0);
}


// 原始位置：disp.cpp:1244；地址：0x00408DE8
// 调试记录声明：long unsigned int GetMouse()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int GetMouse()
{
  uint64_t v0; // rax

  v0 = GetMsg(_bdn, 3u);
  return HI(v0);
}


// 原始位置：disp.cpp:1248；地址：0x00408E10
// 调试记录声明：long unsigned int WaitMouse(long unsigned int m)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl WaitMouse(unsigned int m)
{
  while ( !IsMouse() )
    WaitNextMsg();
  return GetMouse();
}


// 原始位置：disp.cpp:1253；地址：0x00408E30
// 调试记录声明：long unsigned int WaitMouse()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int WaitMouse()
{
  return WaitMouse(0);
}


// 原始位置：disp.cpp:1257；地址：0x00408E44
// 调试记录声明：bool IsMouseLeft()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool IsMouseLeft()
{
  return IsMsg(0x201u);
}


// 原始位置：disp.cpp:1261；地址：0x00408E58
// 调试记录声明：void WaitMouseLeft()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void WaitMouseLeft()
{
  WaitMsg(0x201u);
}


// 原始位置：disp.cpp:1265；地址：0x00408E6D
// 调试记录声明：bool IsMouseMiddle()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool IsMouseMiddle()
{
  return IsMsg(0x207u);
}


// 原始位置：disp.cpp:1269；地址：0x00408E81
// 调试记录声明：void WaitMouseMiddle()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void WaitMouseMiddle()
{
  WaitMsg(0x207u);
}


// 原始位置：disp.cpp:1273；地址：0x00408E96
// 调试记录声明：bool IsMouseRight()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool IsMouseRight()
{
  return IsMsg(0x204u);
}


// 原始位置：disp.cpp:1277；地址：0x00408EAA
// 调试记录声明：void WaitMouseRight()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void WaitMouseRight()
{
  WaitMsg(0x204u);
}


// 原始位置：disp.cpp:1281；地址：0x00408EBF
// 调试记录声明：bool IsMouseWheel()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool IsMouseWheel()
{
  return IsMsg(0x20Au);
}


// 原始位置：disp.cpp:1285；地址：0x00408ED3
// 调试记录声明：long int GetMouseWheel()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int GetMouseWheel()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x20Au);
  return HI(v0) >> 16;
}


// 原始位置：disp.cpp:1289；地址：0x00408EF9
// 调试记录声明：void WaitMouseWheel()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void WaitMouseWheel()
{
  WaitMsg(0x20Au);
}


// 原始位置：disp.cpp:1293；地址：0x00408F0E
// 调试记录声明：bool IsMouseMove()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool IsMouseMove()
{
  return IsMsg(0x200u);
}


// 原始位置：disp.cpp:1297；地址：0x00408F22
// 调试记录声明：long unsigned int GetMouseMove()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int GetMouseMove()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x200u);
  return LO(v0);
}


// 原始位置：disp.cpp:1301；地址：0x00408F42
// 调试记录声明：long unsigned int WaitMouseMove()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int WaitMouseMove()
{
  uint64_t v0; // rax

  v0 = WaitMsg(0x200u);
  return LO(v0);
}


// 原始位置：disp.cpp:1305；地址：0x00408F62
// 调试记录声明：bool IsDropFile()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool IsDropFile()
{
  return IsMsg(0x233u);
}


// 原始位置：disp.cpp:1309；地址：0x00408F76
// 调试记录声明：long int GetMouseAbsX()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：POINT p。
LONG GetMouseAbsX()
{
  POINT p;

  GetCursorPos(&p);
  return p.x;
}


// 原始位置：disp.cpp:1315；地址：0x00408F8F
// 调试记录声明：long int GetMouseAbsY()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：POINT p。
LONG GetMouseAbsY()
{
  POINT p;

  GetCursorPos(&p);
  return p.y;
}


// 原始位置：disp.cpp:1321；地址：0x00408FA8
// 调试记录声明：long int GetMouseWinX()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetMouseWinX()
{
  LONG v0;

  v0 = GetMouseAbsX();
  return v0 - GetPosX();
}


// 原始位置：disp.cpp:1325；地址：0x00408FC5
// 调试记录声明：long int GetMouseWinY()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetMouseWinY()
{
  LONG v0;

  v0 = GetMouseAbsY();
  return v0 - GetPosY();
}


// 原始位置：disp.cpp:1329；地址：0x00408FE2
// 调试记录声明：long int GetMousePosX()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetMousePosX()
{
  int v0;
  int v1;

  v0 = GetMouseWinX();
  if ( (_style & 0x80000000) != 0 )
    v1 = 0;
  else
    v1 = GetBorderWidth();
  return v0 - v1;
}


// 原始位置：disp.cpp:1333；地址：0x0040900F
// 调试记录声明：long int GetMousePosY()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
int GetMousePosY()
{
  int v0;
  int v1;
  int v2;

  v0 = GetMouseWinY();
  if ( (_style & 0x80000000) != 0 )
  {
    v2 = 0;
  }
  else
  {
    v1 = GetBorderHeight();
    v2 = v1 + GetBorderTitle();
  }
  return v0 - v2;
}


// 原始位置：disp.cpp:1338；地址：0x00409041
// 调试记录声明：long unsigned int MsgBoxW(const short int *s, const short int *title, long unsigned int i)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl MsgBoxW(const __int16 *s, const __int16 *title, unsigned int i)
{
  return MessageBoxW(0, (LPCWSTR)s, (LPCWSTR)title, i);
}


// 原始位置：disp.cpp:1342；地址：0x0040906D
// 调试记录声明：long unsigned int MsgBox(const char *s, const char *title, long unsigned int i)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl MsgBox(const char *s, const char *title, unsigned int i)
{
  return MessageBoxA(0, s, title, i);
}


// 原始位置：disp.cpp:1346；地址：0x00409099
// 调试记录声明：void MsgBoxW(const short int *s, const short int *title)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl MsgBoxW(const __int16 *s, const __int16 *title)
{
  MsgBoxW(s, title, 0);
}


// 原始位置：disp.cpp:1350；地址：0x004090BC
// 调试记录声明：void MsgBox(const char *s, const char *title)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl MsgBox(const char *s, const char *title)
{
  MsgBox(s, title, 0);
}


// 原始位置：disp.cpp:1354；地址：0x004090DF
// 调试记录声明：void MsgBoxW(const short int *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl MsgBoxW(const __int16 *s)
{
  MsgBoxW(s, &title);
}


// 原始位置：disp.cpp:1358；地址：0x004090FB
// 调试记录声明：void MsgBox(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl MsgBox(const char *s)
{
  MsgBox(s, ::s);
}


// 原始位置：disp.cpp:1362；地址：0x00409117
// 调试记录声明：void Delay(long unsigned int t)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl Delay(unsigned int t)
{
  Sleep(t);
}


// 原始位置：disp.cpp:1366；地址：0x0040912E
// 调试记录声明：void Delay()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Delay()
{
  Delay(1u);
}


// 原始位置：disp.cpp:1371；地址：0x00409143
// 调试记录声明：long unsigned int SendString()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 可见操作：调用 MCI 音频接口。
unsigned int SendString()
{
  mciSendStringA(command_in, command_out, 0x7Fu, 0);
  return strtoul(command_out, 0, 10);
}


// 原始位置：disp.cpp:1376；地址：0x0040918E
// 调试记录声明：long unsigned int LoadAudio(const char *s1, const char *s2)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl LoadAudio(const char *s1, const char *s2)
{
  sprintf(command_in, "open \"%s\"%s alias s%lu", s1, s2, ++_cid);
  SendString();
  return _cid;
}


// 原始位置：disp.cpp:1383；地址：0x004091D8
// 调试记录声明：long unsigned int LoadAudio(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl LoadAudio(const char *s)
{
  return LoadAudio(s, ::s);
}


// 原始位置：disp.cpp:1387；地址：0x004091F3
// 调试记录声明：void PlayAudio(long unsigned int id, const char *s, bool b)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl PlayAudio(unsigned int id, const char *s, bool b)
{
  const char *v3;

  if ( b )
    v3 = "play s%lu%s wait repeat";
  else
    v3 = "play s%lu%s";
  sprintf(command_in, v3, id, s);
  SendString();
}


// 原始位置：disp.cpp:1392；地址：0x00409237
// 调试记录声明：void StopAudio(long unsigned int id)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl StopAudio(unsigned int id)
{
  SetAudioPos(id, 0, 0);
  sprintf(command_in, "stop s%lu", id);
  SendString();
}


// 原始位置：disp.cpp:1398；地址：0x0040927B
// 调试记录声明：void PauseAudio(long unsigned int id)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl PauseAudio(unsigned int id)
{
  sprintf(command_in, "pause s%lu", id);
  SendString();
}


// 原始位置：disp.cpp:1403；地址：0x004092A4
// 调试记录声明：void ResumeAudio(long unsigned int id)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl ResumeAudio(unsigned int id)
{
  sprintf(command_in, "resume s%lu", id);
  SendString();
}


// 原始位置：disp.cpp:1408；地址：0x004092CD
// 调试记录声明：void ReleaseAudio(long unsigned int id)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl ReleaseAudio(unsigned int id)
{
  sprintf(command_in, "close s%lu", id);
  SendString();
}


// 原始位置：disp.cpp:1413；地址：0x004092F6
// 调试记录声明：long unsigned int GetAudioPos(long unsigned int id)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl GetAudioPos(unsigned int id)
{
  sprintf(command_in, "status s%lu position", id);
  return SendString();
}


// 原始位置：disp.cpp:1418；地址：0x0040931E
// 调试记录声明：void SetAudioPos(long unsigned int id, long unsigned int pos, bool b)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void __cdecl SetAudioPos(unsigned int id, unsigned int pos, bool b)
{
  sprintf(command_in, "seek s%lu to %lu", id, pos);
  SendString();
  PlayAudio(id, s, b);
}


// 原始位置：disp.cpp:1424；地址：0x0040936F
// 调试记录声明：long unsigned int GetAudioLen(long unsigned int id)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int __cdecl GetAudioLen(unsigned int id)
{
  sprintf(command_in, "status s%lu length", id);
  return SendString();
}


// 原始位置：disp.cpp:1430；地址：0x00409397
// 调试记录声明：bool IsFile(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：WIN32_FIND_DATA fd；HANDLE fh；bool result。
bool __cdecl IsFile(const char *s)
{
  WIN32_FIND_DATA fd;
  bool result;
  HANDLE fh;

  fh = FindFirstFileA(s, &fd);
  result = (char *)fh + 1 != 0;
  if ( result )
    FindClose(fh);
  return result;
}


// 原始位置：disp.cpp:1442；地址：0x004093DF
// 调试记录声明：uint8_t UTF8ToUnicode(uint8_t *utf8, uint32_t *unicode)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：const uint8_t lut_size；const const uint8_t length_lut[3]；const const uint8_t range_lut[3]；const const uint8_t mask_lut[3]；uint8_t length；byte b；uint32_t i。
uint8_t __cdecl UTF8ToUnicode(uint8_t *utf8, uint32_t *unicode)
{
  uint8_t result;
  const uint8_t mask_lut[3];
  const uint8_t range_lut[3];
  const uint8_t length_lut[3];
  byte b;
  const uint8_t lut_size;
  uint32_t i;
  uint8_t length;

  lut_size = 3;
  length_lut[0] = 2;
  length_lut[1] = 3;
  length_lut[2] = 4;
  range_lut[0] = -32;
  range_lut[1] = -16;
  range_lut[2] = -8;
  mask_lut[0] = 31;
  mask_lut[1] = 15;
  mask_lut[2] = 7;
  length = 0;
  b = *utf8;
  i = 0;
  if ( utf8 )
  {
    if ( (signed int)b > 127 )
    {
      if ( (signed int)b > 191 && (signed int)b <= 253 )
      {
        for ( i = 0; i <= 2; ++i )
        {
          if ( b < (signed int)range_lut[i] )
          {
            *unicode = (unsigned __int8)(b & mask_lut[i]);
            length = length_lut[i];
            break;
          }
        }
        if ( length )
        {
          for ( i = 1; length > i; ++i )
          {
            b = utf8[i];
            if ( (signed int)b <= 127 || (signed int)b > 191 )
              break;
            *unicode <<= 6;
            *unicode |= b & 0x3F;
          }
          if ( length > i )
            result = 1;
          else
            result = length;
        }
        else
        {
          *unicode = 0;
          result = 1;
        }
      }
      else
      {
        *unicode = 0;
        result = 1;
      }
    }
    else
    {
      *unicode = b;
      result = 1;
    }
  }
  else
  {
    *unicode = 0;
    result = 1;
  }
  return result;
}


// 原始位置：disp.cpp:1493；地址：0x00409554
// 调试记录声明：uint8_t UnicodeToUTF16(uint32_t unicode, uint16_t *utf16)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
uint8_t __cdecl UnicodeToUTF16(uint32_t unicode, uint16_t *utf16)
{
  uint8_t result;

  if ( unicode > 0xFFFF )
  {
    if ( unicode > 0xEFFFF )
    {
      result = 0;
    }
    else
    {
      if ( utf16 )
      {
        *utf16 = (unicode >> 10) - 10304;
        utf16[1] = (unicode & 0x3FF) - 9216;
      }
      result = 2;
    }
  }
  else
  {
    if ( utf16 )
      *utf16 = unicode;
    result = 1;
  }
  return result;
}


// 原始位置：disp.cpp:?；地址：0x004095BD
// 调试记录声明：void __static_initialization_and_destruction_0(int __initialize_p, int __priority)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 可见操作：GDI+ 绘图。
void __cdecl __static_initialization_and_destruction_0(int __initialize_p, int __priority)
{
  BOOL v2;

  if ( __initialize_p == 1 && __priority == 0xFFFF )
    weak___ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii___ZN7Gdiplus11GdiplusBasedlEPv(
      &_GdiStart,
      0,
      0,
      0,
      v2);
}


// 原始位置：disp.cpp:?；地址：0x004095F9
// 调试记录声明：void _GLOBAL__sub_I_version()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void _GLOBAL__sub_I_version()
{
  __static_initialization_and_destruction_0(1, 0xFFFF);
}

