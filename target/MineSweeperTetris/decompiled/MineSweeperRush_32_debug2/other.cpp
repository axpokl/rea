// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug2.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004011B0; symbol: sub_4011B0
void __noreturn sub_4011B0()
{
  _DWORD *v0; // eax
  UINT v1; // ebx

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
  v0 = (_DWORD *)__p__environ();
  v1 = main_0(_argc, _argv, *v0);
  _cexit();
  ExitProcess(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00401330; symbol: __onexit
_onexit_t __cdecl _onexit(_onexit_t a1)
{
  return __onexit(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004042A0; symbol: __ZN5Board7dellineEl
// local variable allocation has failed, the output may be wrong!
void __userpurge Board::delline(Board *a1@<ecx>, Board *const this, int l)
{
  signed int v3; // eax
  bool v4; // dl
  char *v5; // eax
  signed int v6; // eax
  int v7; // ST0C_4
  signed int v8; // eax
  int v9; // ST04_4
  Board *v10; // [esp+0h] [ebp-78h]
  int v11; // [esp+4h] [ebp-74h]
  bool v12; // [esp+4h] [ebp-74h]
  int v13; // [esp+Ch] [ebp-6Ch]
  int v14; // [esp+Ch] [ebp-6Ch]
  int v15; // [esp+Ch] [ebp-6Ch]
  int v16; // [esp+Ch] [ebp-6Ch]
  int *v17; // [esp+14h] [ebp-64h]
  Board *thisa; // [esp+2Ch] [ebp-4Ch]
  int scrtotal_[4]; // [esp+3Ch] [ebp-3Ch]
  int mb; // [esp+4Fh] [ebp-29h] OVERLAPPED
  int j_0; // [esp+50h] [ebp-28h]
  int k_0; // [esp+54h] [ebp-24h]
  int k; // [esp+58h] [ebp-20h]
  int j_1; // [esp+5Ch] [ebp-1Ch]
  int i_1; // [esp+60h] [ebp-18h]
  int i_0; // [esp+64h] [ebp-14h]
  int j; // [esp+68h] [ebp-10h]
  int i; // [esp+6Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->sit > 0 && a1->sit <= 3 && !a1->pauseb )
  {
    a1->checkr = 0;
    if ( a1->relaxb )
    {
      ++a1->line;
      ++a1->sum;
      v3 = a1->line;
      if ( v3 > 999999 )
        v3 = 999999;
      a1->line = v3;
      Board::addline(a1, 0, v11);
    }
    else
    {
      ++a1->maskj;
    }
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = (int)this; j >= 0; --j )
      {
        if ( j )
        {
          thisa->mine[i][j] = thisa->mine[i][j - 1];
          v4 = thisa->mask[i][j - 1] && thisa->relaxb != 1;
          thisa->mask[i][j] = v4;
          thisa->flag[i][j] = thisa->flag[i][j - 1];
          thisa->leftrule[i][j] = thisa->leftrule[i][j - 1];
          thisa->rightrule[i][j] = thisa->rightrule[i][j - 1];
          thisa->qstn[i][j] = thisa->qstn[i][j - 1];
          thisa->blck[i][j] = thisa->blck[i][j - 1];
          thisa->numb[i][j] = thisa->numb[i][j - 1];
        }
        else
        {
          thisa->mine[i][0] = thisa->n > i;
          thisa->mask[i][j] = !thisa->maskjb;
          thisa->flag[i][j] = 0;
          thisa->leftrule[i][j] = 0;
          thisa->rightrule[i][j] = 0;
          thisa->qstn[i][j] = 0;
          thisa->blck[i][j] = 0;
        }
      }
    }
    thisa->maskjb = 0;
    for ( i_0 = 0; thisa->w > i_0; ++i_0 )
    {
      thisa->rx = rand() % thisa->w;
      thisa->ry = 0;
      j_0 = 0;
      mb = thisa->mine[thisa->rx][thisa->ry];
      thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i_0][j_0];
      thisa->mine[i_0][j_0] = mb;
    }
    for ( i_1 = 0; thisa->w > i_1; ++i_1 )
    {
      v5 = (char *)(thisa->h - 1);
      if ( (signed int)v5 > (signed int)&this->w + 1 )
        v5 = (char *)&this->w + 1;
      for ( j_1 = (int)v5; j_1 >= (signed int)this; --j_1 )
      {
        thisa->numb[i_1][j_1] = 0;
        for ( k = 0; k <= 7; ++k )
        {
          if ( Block::isok(thisa, (Block *const )k, i_1, j_1, (int)&thisa->tx, &thisa->ty, v17)
            && thisa->mine[thisa->tx][thisa->ty] )
          {
            ++thisa->numb[i_1][j_1];
          }
        }
      }
    }
    ++thisa->line;
    ++thisa->sum;
    v6 = thisa->line;
    if ( v6 > 999999 )
      v6 = 999999;
    thisa->line = v6;
    if ( thisa->sum == thisa->line + thisa->tetrisi )
    {
      Steam::compscr((Steam *const )thisa->line, thisa->mode, thisa->st.scrindexline, v13);
      if ( thisa->mdb == 1 )
        Steam::compscr((Steam *const )thisa->line, thisa->mode, thisa->st.scrindexmdb, v14);
      Steam::compscr((Steam *const )(thisa->line - thisa->missline), thisa->mode, thisa->st.scrindexnomiss, v14);
      scrtotal_[0] = 0;
      scrtotal_[1] = 2;
      scrtotal_[2] = 3;
      scrtotal_[3] = 6;
      Steam::addscr((Steam *const )thisa->st.scrtotal, scrtotal_[thisa->mode], thisa->mode, v7);
      if ( thisa->line > 9999 )
        Steam::addach((Steam *const )thisa->st.achhidedge, v11);
    }
    if ( thisa->maskj > thisa->h - 4 )
    {
      ++thisa->tetrisi;
      ++thisa->sum;
      Steam::compscr((Steam *const )thisa->tetrisi, thisa->mode, thisa->st.scrindextetris, v13);
      thisa->line += 4 + (thisa->bouns & ~(thisa->bouns >> 31));
      thisa->sum += 4 + (thisa->bouns & ~(thisa->bouns >> 31));
      v8 = thisa->line;
      if ( v8 > 999999 )
        v8 = 999999;
      thisa->line = v8;
      if ( thisa->sum == thisa->line + thisa->tetrisi )
      {
        Steam::compscr((Steam *const )thisa->line, thisa->mode, thisa->st.scrindexline, v15);
        if ( thisa->mdb == 1 )
          Steam::compscr((Steam *const )thisa->line, thisa->mode, thisa->st.scrindexmdb, v16);
        Steam::compscr((Steam *const )(thisa->line - thisa->missline), thisa->mode, thisa->st.scrindexnomiss, v16);
      }
      for ( k_0 = 0; k_0 <= 3; ++k_0 )
        Board::addline(v10);
      Board::checkline(thisa, 0, v12);
      thisa->sit = 3;
      thisa->bouns = 4;
      Sound::playsound((Sound *const )thisa->sd.sNew, v9);
      Steam::addscr((Steam *const )thisa->st.scrfour, 1, thisa->mode, v15);
    }
    while ( (thisa->level + 1) * (thisa->level + 1) <= thisa->line )
    {
      ++thisa->level;
      Sound::playsound((Sound *const )thisa->sd.sWin, v11);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004055F0; symbol: __Z11CombinePathPcPKcS1_
void __cdecl CombinePath(char *dest, const char *path1, const char *path2)
{
  lstrcpyA(dest, path1);
  lstrcatA(dest, "/");
  lstrcatA(dest, path2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040567F; symbol: __Z15RemoveExtensionPc
void __cdecl RemoveExtension(char *filePath)
{
  char *lastDot; // [esp+1Ch] [ebp-Ch]

  lastDot = strrchr(filePath, 46);
  if ( lastDot )
    *lastDot = 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405858; symbol: __Z23DeleteFolderRecursivelyPKc
void __cdecl DeleteFolderRecursively(const char *folderPath)
{
  bool v1; // al
  WIN32_FIND_DATAA findData; // [esp+14h] [ebp-354h]
  char filePath[260]; // [esp+154h] [ebp-214h]
  char searchPath[260]; // [esp+258h] [ebp-110h]
  HANDLE hFind; // [esp+35Ch] [ebp-Ch]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405A68; symbol: __Z13WinCreateMainv
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405DEA; symbol: __Z15MonitorenumprocP10HMONITOR__P5HDC__P7tagRECTl@16
BOOL __stdcall Monitorenumproc(HMONITOR hmon, HDC hdc, LPRECT lprect, LPARAM pdata)
{
  RECT *v4; // eax
  LONG work_4; // [esp+20h] [ebp-68h]
  LONG work_8; // [esp+24h] [ebp-64h]
  LONG work_12; // [esp+28h] [ebp-60h]
  MONITORINFOEX info; // [esp+2Ch] [ebp-5Ch]
  int posY; // [esp+74h] [ebp-14h]
  int posX; // [esp+78h] [ebp-10h]
  RECT *r; // [esp+7Ch] [ebp-Ch]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：创建窗口。
// Address: 0x00405F02; symbol: __Z9WinCreatev
void WinCreate()
{
  RECT rect; // [esp+40h] [ebp-28h]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：处理窗口消息循环。
// Address: 0x00406002; symbol: __Z7WinInitv
void WinInit()
{
  if ( !_wca )
    _wca = WinRegister();
  WinCreate();
  WinCreateMain();
  _winb = 1;
  GetTimeR();
  _tbegin = _tcount;
  while ( IsWin() )
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004060F4; symbol: __Z8FreshFPSv
void FreshFPS()
{
  unsigned int v0; // ebx

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040617F; symbol: __Z6AddFPSv
void AddFPS()
{
  ++_mscnti;
  FreshFPS();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040619A; symbol: __Z9CreateWinllmmmmmPKc
void __cdecl CreateWin(int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int style, const char *winclass)
{
  wchar_t wstr[127]; // [esp+22h] [ebp-106h]

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
  while ( !IsWin() )
    Sleep(1u);
  SetBkMode(_dc, 1);
  Clear();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040629F; symbol: __Z9CreateWinmmmmmPKc
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int style, const char *winclass)
{
  int v6; // ebx
  int v7; // edx

  GetScrHeight();
  v6 = (GetScrHeight() - h) >> 1;
  GetScrWidth();
  v7 = (GetScrWidth() - w) >> 1;
  CreateWin(v7, v6, w, h, cfg, cbg, style, winclass);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406305; symbol: __Z9CreateWinmmmmm
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int style)
{
  CreateWin(w, h, cfg, cbg, style, DEFAULTCLASS);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040633E; symbol: __Z9CreateWinmmmm
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  CreateWin(w, h, cfg, cbg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040636F; symbol: __Z9CreateWinmmm
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int c)
{
  CreateWin(w, h, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406399; symbol: __Z9CreateWinmm
void __cdecl CreateWin(unsigned int w, unsigned int h)
{
  CreateWin(w, h, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004063BC; symbol: __Z9CreateWinm
void __cdecl CreateWin(unsigned int cbg)
{
  int v1; // ebx
  int v2; // edx

  v1 = GetScrHeight() / 2;
  v2 = GetScrWidth() / 2;
  CreateWin(v2, v1, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004063FD; symbol: __Z9CreateWinv
void CreateWin()
{
  int v0; // ebx
  int v1; // eax

  v0 = GetScrHeight() / 2;
  v1 = GetScrWidth();
  CreateWin(v1 / 2, v0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406435; symbol: __Z8FreshWinv
void FreshWin()
{
  DrawBMP(_pmain, _pmscr);
  AddFPS();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040645A; symbol: __Z8CloseWinv
void CloseWin()
{
  SendMessageA(_hw, 0x10u, 0, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040648B; symbol: __Z5IsWinv
BOOL IsWin()
{
  return _winb;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406497; symbol: __Z8GetTimeRv
long double GetTimeR()
{
  LARGE_INTEGER tcount; // [esp+20h] [ebp-18h]
  LARGE_INTEGER tfreq; // [esp+28h] [ebp-10h]

  if ( QueryPerformanceFrequency(&tfreq) != 0 )
    _tfreq = tfreq;
  if ( QueryPerformanceCounter(&tcount) != 0 )
    _tcount = tcount;
  return (double)(tcount.QuadPart - _tbegin.QuadPart) / (double)_tfreq.QuadPart;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406533; symbol: __Z7GetTimev
signed __int64 GetTime()
{
  return (signed __int64)(GetTimeR() * 1000.0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406564; symbol: __Z8SetTitlePKc
void __cdecl SetTitle(const char *s)
{
  SetWindowTextA(_hw, s);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406584; symbol: __Z9SetTitleWPKs
void __cdecl SetTitleW(const __int16 *s)
{
  SetWindowTextW(_hw, (LPCWSTR)s);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004065A4; symbol: __Z8GetTitlev
char *GetTitle()
{
  GetWindowTextA(_hw, GetTitle(void)::c, 127);
  return GetTitle(void)::c;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004065D1; symbol: __Z9GetTitleWv
WCHAR *GetTitleW()
{
  GetWindowTextW(_hw, &GetTitleW(void)::c, 127);
  return &GetTitleW(void)::c;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004065FE; symbol: __Z7SetSizellmm
void __cdecl SetSize(int x, int y, unsigned int w, unsigned int h)
{
  RECT rect; // [esp+20h] [ebp-18h]

  rect.left = x;
  rect.top = y;
  rect.right = x + w;
  rect.bottom = y + h;
  AdjustWindowRect(&rect, _style, 0);
  MoveWindow(_hw, x, y, rect.right - rect.left, rect.bottom - rect.top, 1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040668C; symbol: __Z7SetSizemm
void __cdecl SetSize(unsigned int w, unsigned int h)
{
  int v2; // ebx
  int v3; // edx

  v2 = GetPosY();
  v3 = GetPosX();
  SetSize(v3, v2, w, h);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004066C2; symbol: __Z8GetWidthv
unsigned int GetWidth()
{
  return _w;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004066CC; symbol: __Z9GetHeightv
unsigned int GetHeight()
{
  return _h;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004066D6; symbol: __Z7GetSizev
unsigned int GetSize()
{
  unsigned int v0; // ebx

  v0 = GetWidth() << 16;
  return v0 + GetHeight();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004066EE; symbol: __Z11GetScrWidthv
int GetScrWidth()
{
  return GetSystemMetrics(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406705; symbol: __Z12GetScrHeightv
int GetScrHeight()
{
  return GetSystemMetrics(1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040671C; symbol: __Z10GetScrSizev
int GetScrSize()
{
  int v0; // ebx

  v0 = GetScrWidth() << 16;
  return v0 + GetScrHeight();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040673A; symbol: __Z11GetScrCapsXv
long double GetScrCapsX()
{
  HWND__ *v0; // eax
  HDC__ *v1; // eax

  v0 = GetDesktopWindow();
  v1 = GetDC(v0);
  return 144.0 / (long double)GetDeviceCaps(v1, 88);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406773; symbol: __Z11GetScrCapsYv
long double GetScrCapsY()
{
  HWND__ *v0; // eax
  HDC__ *v1; // eax

  v0 = GetDesktopWindow();
  v1 = GetDC(v0);
  return 144.0 / (long double)GetDeviceCaps(v1, 90);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004067AC; symbol: __Z14GetBorderTitlev
int GetBorderTitle()
{
  return GetSystemMetrics(4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004067C3; symbol: __Z14GetBorderWidthv
int GetBorderWidth()
{
  int result; // eax

  if ( _style & 0x40000 )
    result = GetSystemMetrics(32);
  else
    result = GetSystemMetrics(7);
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004067F9; symbol: __Z15GetBorderHeightv
int GetBorderHeight()
{
  int result; // eax

  if ( _style & 0x40000 )
    result = GetSystemMetrics(33);
  else
    result = GetSystemMetrics(8);
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040682F; symbol: __Z13GetBorderSizev
int GetBorderSize()
{
  int v0; // ebx

  v0 = GetBorderWidth() << 16;
  return v0 + GetBorderHeight();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040684D; symbol: __Z6SetPosll
void __cdecl SetPos(int x, int y)
{
  SetSize(x, y, _w, _h);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040687C; symbol: __Z7GetPosXv
LONG GetPosX()
{
  RECT rt; // [esp+10h] [ebp-18h]

  rt.left = 0;
  rt.top = 0;
  rt.right = 0;
  rt.bottom = 0;
  GetWindowRect(_hw, &rt);
  return rt.left;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004068BA; symbol: __Z7GetPosYv
LONG GetPosY()
{
  RECT rt; // [esp+10h] [ebp-18h]

  rt.left = 0;
  rt.top = 0;
  rt.right = 0;
  rt.bottom = 0;
  GetWindowRect(_hw, &rt);
  return rt.top;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004068F8; symbol: __Z6GetPosv
int GetPos()
{
  LONG v0; // ebx

  v0 = GetPosX() << 16;
  return v0 + GetPosY();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406916; symbol: __Z6GetWinv
pbitmap GetWin()
{
  return _pmain;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406920; symbol: __Z6GetScrv
pbitmap GetScr()
{
  return _pmscr;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040692A; symbol: __Z7GetHwndP6bitmap
HGDIOBJ __cdecl GetHwnd(pbitmap b)
{
  return b->Handle;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406934; symbol: __Z7GetHwndv
HWND GetHwnd()
{
  return _hw;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040693E; symbol: __Z7GetDrawP6bitmap
HDC __cdecl GetDraw(pbitmap b)
{
  return b->DC;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406949; symbol: __Z7GetDrawv
HDC GetDraw()
{
  return _dc;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406953; symbol: __Z10GetBGColorv
COLORREF GetBGColor()
{
  return _cbg;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040695D; symbol: __Z10SetBGColorm
void __cdecl SetBGColor(unsigned int c)
{
  _cbg = c;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040696B; symbol: __Z10GetFGColorv
unsigned int GetFGColor()
{
  return _cfg;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406975; symbol: __Z10SetFGColorm
void __cdecl SetFGColor(unsigned int c)
{
  _cfg = c;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406983; symbol: __Z11SetPenWidthm
void __cdecl SetPenWidth(unsigned int pew)
{
  _pew = pew;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406991; symbol: __Z11SetPenColorP6bitmapm
void __cdecl SetPenColor(pbitmap b, unsigned int c)
{
  HPEN__ *v2; // eax

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406A14; symbol: __Z13SetBrushColorP6bitmapm
void __cdecl SetBrushColor(pbitmap b, unsigned int c)
{
  HBRUSH__ *v2; // eax

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406A84; symbol: __Z11SetPenColorm
void __cdecl SetPenColor(unsigned int c)
{
  SetPenColor(_pmain, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406AA1; symbol: __Z13SetBrushColorm
void __cdecl SetBrushColor(unsigned int c)
{
  SetBrushColor(_pmain, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406ABE; symbol: __Z6GetRedm
unsigned __int8 __cdecl GetRed(unsigned int c)
{
  return c;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406AC6; symbol: __Z8GetGreenm
unsigned __int8 __cdecl GetGreen(unsigned int c)
{
  return c >> 8;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406AD1; symbol: __Z7GetBluem
unsigned __int8 __cdecl GetBlue(unsigned int c)
{
  return c >> 16;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406ADC; symbol: __Z8GetAlpham
unsigned __int8 __cdecl GetAlpha(unsigned int c)
{
  return c >> 24;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406AE7; symbol: __Z7GetRGBAhhhh
unsigned int __cdecl GetRGBA(unsigned __int8 r, unsigned __int8 g, unsigned __int8 b, unsigned __int8 a)
{
  return (g << 8) | (b << 16) | (a << 24) | r;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406B2D; symbol: __Z6GetRGBhhh
unsigned int __cdecl GetRGB(unsigned __int8 r, unsigned __int8 g, unsigned __int8 b)
{
  return GetRGBA(r, g, b, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406B6B; symbol: __Z7SetFontP6bitmap
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406C62; symbol: __Z7SetFontv
void SetFont()
{
  SetFont(_pmain);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406C78; symbol: __Z12SetFontWidthm
void __cdecl SetFontWidth(unsigned int w)
{
  _fw = w;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406C8E; symbol: __Z13SetFontHeightm
void __cdecl SetFontHeight(unsigned int h)
{
  _fh = h;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406CA4; symbol: __Z11SetFontSizemm
void __cdecl SetFontSize(unsigned int w, unsigned int h)
{
  _fh = h;
  _fw = w;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406CC2; symbol: __Z13SetFontWeightm
void __cdecl SetFontWeight(unsigned int wg)
{
  _fwg = wg;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406CD8; symbol: __Z13SetFontLtalicm
void __cdecl SetFontLtalic(unsigned int lt)
{
  _flt = lt;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406CEE; symbol: __Z16SetFontUnderLinem
void __cdecl SetFontUnderLine(unsigned int ud)
{
  _fud = ud;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406D04; symbol: __Z16SetFontStrikeOutm
void __cdecl SetFontStrikeOut(unsigned int sk)
{
  _fsk = sk;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406D1A; symbol: __Z14SetFontCharSetm
void __cdecl SetFontCharSet(unsigned int cs_0)
{
  _fcs = cs_0;
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406D30; symbol: __Z11SetFontNamePKc
void __cdecl SetFontName(const char *s)
{
  strcpy(_ffn, s);
  SetFont();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406D51; symbol: __Z13GetStringSizePKc
void __cdecl GetStringSize(const char *s)
{
  int v1; // eax

  v1 = strlen(s);
  GetTextExtentPoint32A(_dc, s, v1, &_strz);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406D8A; symbol: __Z14GetStringWidthPKc
unsigned int __cdecl GetStringWidth(const char *s)
{
  unsigned int result; // eax

  GetStringSize(s);
  if ( _strz.cy <= 0 )
    result = 0;
  else
    result = _strz.cx * _fh / _strz.cy;
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406DCB; symbol: __Z15GetStringHeightPKc
unsigned int __cdecl GetStringHeight(const char *s)
{
  unsigned int result; // eax

  GetStringSize(s);
  if ( _strz.cy <= 0 )
    result = 0;
  else
    result = _strz.cy * _fh / _strz.cy;
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406E0C; symbol: __Z10InitTextXYPP6bitmapPPKsPmS5_
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406ECA; symbol: __Z10InitTextXYPP6bitmapPPKcPmS5_
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00406F87; symbol: __Z10DrawTextXYP6bitmapPKsllmmmmm
void __cdecl DrawTextXY(pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int format)
{
  int v9; // eax
  RECT lpRect; // [esp+20h] [ebp-18h]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407022; symbol: __Z10DrawTextXYP6bitmapPKsllmmmm
void __cdecl DrawTextXY(pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  int v8; // eax
  RECT lpRect; // [esp+20h] [ebp-18h]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004070BE; symbol: __Z10DrawTextXYP6bitmapPKcllmmmm
void __cdecl DrawTextXY(pbitmap b, const char *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  int v8; // eax
  RECT lpRect; // [esp+20h] [ebp-18h]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040715A; symbol: __Z10DrawTextXYP6bitmapPKcllmm
void __cdecl DrawTextXY(pbitmap b, const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  int v6; // eax
  unsigned int v7; // eax

  InitTextXY(&b, &s, &cfg, &cbg);
  v6 = strlen(s);
  TextOutA(b->DC, x, y, s, v6);
  v7 = GetStringWidth(s);
  _fx = v7 + x;
  _fy = y;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004071D9; symbol: __Z10DrawTextXYP6bitmapPKcllm
void __cdecl DrawTextXY(pbitmap b, const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXY(b, s, x, y, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407211; symbol: __Z10DrawTextXYPKcllmm
void __cdecl DrawTextXY(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(0, s, x, y, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407249; symbol: __Z10DrawTextXYPKcllm
void __cdecl DrawTextXY(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXY(0, s, x, y, cfg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040727A; symbol: __Z10DrawTextXYPKclm
void __cdecl DrawTextXY(const char *s, int x, unsigned int y)
{
  DrawTextXY(s, x, y, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004072A4; symbol: __Z9DrawTextAPKcmm
void __cdecl DrawTextA(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(s, _fx, _fy, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004072D9; symbol: __Z9DrawTextAPKcm
void __cdecl DrawTextA(const char *s, unsigned int cfg)
{
  DrawTextA(s, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004072FC; symbol: __Z9DrawTextAPKc
void __cdecl DrawTextA(const char *s)
{
  DrawTextA(s, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407318; symbol: __Z12DrawTextlnXYPKcllmm
void __cdecl DrawTextlnXY(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(s, x, y, cfg, cbg);
  _fx = x;
  _fy = GetStringHeight(s) + y;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407367; symbol: __Z12DrawTextlnXYPKcllm
void __cdecl DrawTextlnXY(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextlnXY(s, x, y, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407398; symbol: __Z12DrawTextlnXYPKclm
void __cdecl DrawTextlnXY(const char *s, int x, unsigned int y)
{
  DrawTextlnXY(s, x, y, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004073C2; symbol: __Z10DrawTextlnPKcmm
void __cdecl DrawTextln(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextlnXY(s, _fx, _fy, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004073F7; symbol: __Z10DrawTextlnPKcm
void __cdecl DrawTextln(const char *s, unsigned int cfg)
{
  DrawTextln(s, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040741A; symbol: __Z10DrawTextlnPKc
void __cdecl DrawTextln(const char *s)
{
  DrawTextln(s, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407436; symbol: __Z10DrawTextlnv
void DrawTextln()
{
  DrawTextln(s);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040744B; symbol: __Z11DrawTextXYwP6bitmapPKcllmm
void __cdecl DrawTextXYw(pbitmap b, const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  unsigned int fi; // [esp+2Ch] [ebp-Ch]

  InitTextXY(&b, &s, &cfg, &cbg);
  for ( fi = 0; strlen(s) > fi; ++fi )
  {
    TextOutA(b->DC, x, y, &s[fi], 1);
    x += _fw;
  }
  _fx = x;
  _fy = y;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004074E1; symbol: __Z11DrawTextXYwP6bitmapPKcllm
void __cdecl DrawTextXYw(pbitmap b, const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXYw(b, s, x, y, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407519; symbol: __Z11DrawTextXYwPKcllmm
void __cdecl DrawTextXYw(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(0, s, x, y, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407551; symbol: __Z11DrawTextXYwPKcllm
void __cdecl DrawTextXYw(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXYw(0, s, x, y, cfg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407582; symbol: __Z11DrawTextXYwPKclm
void __cdecl DrawTextXYw(const char *s, int x, unsigned int y)
{
  DrawTextXYw(s, x, y, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004075AC; symbol: __Z9DrawTextwPKcmm
void __cdecl DrawTextw(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(s, _fx, _fy, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004075E1; symbol: __Z9DrawTextwPKcm
void __cdecl DrawTextw(const char *s, unsigned int cfg)
{
  DrawTextw(s, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407604; symbol: __Z9DrawTextwPKc
void __cdecl DrawTextw(const char *s)
{
  DrawTextw(s, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407620; symbol: __Z13DrawTextlnXYwPKcllmm
void __cdecl DrawTextlnXYw(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(s, x, y, cfg, cbg);
  _fx = x;
  _fy = y + _fh;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407667; symbol: __Z13DrawTextlnXYwPKcllm
void __cdecl DrawTextlnXYw(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextlnXYw(s, x, y, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407698; symbol: __Z13DrawTextlnXYwPKclm
void __cdecl DrawTextlnXYw(const char *s, int x, unsigned int y)
{
  DrawTextlnXYw(s, x, y, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004076C2; symbol: __Z11DrawTextlnwPKcmm
void __cdecl DrawTextlnw(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextlnXYw(s, _fx, _fy, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004076F7; symbol: __Z11DrawTextlnwPKcm
void __cdecl DrawTextlnw(const char *s, unsigned int cfg)
{
  DrawTextlnw(s, cfg, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040771A; symbol: __Z11DrawTextlnwPKc
void __cdecl DrawTextlnw(const char *s)
{
  DrawTextlnw(s, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407736; symbol: __Z8GetPixelP6bitmapmm
unsigned int __cdecl GetPixel(pbitmap b, unsigned int x, unsigned int y)
{
  if ( !b )
    b = _pmain;
  return GetPixel(b->DC, x, y);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040776B; symbol: __Z8GetPixelmm
unsigned int __cdecl GetPixel(unsigned int x, unsigned int y)
{
  return GetPixel(0, x, y);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040778D; symbol: __Z8SetPixelP6bitmapmmm
void __cdecl SetPixel(pbitmap b, unsigned int x, unsigned int y, unsigned int c)
{
  if ( !b )
    b = _pmain;
  if ( !c )
    c = _cfg;
  SetPixel(b->DC, x, y, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004077DC; symbol: __Z8SetPixelmmm
void __cdecl SetPixel(unsigned int x, unsigned int y, unsigned int c)
{
  SetPixel(0, x, y, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407806; symbol: __Z8SetPixelmm
void __cdecl SetPixel(unsigned int x, unsigned int y)
{
  SetPixel(x, y, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407829; symbol: __Z4LineP6bitmapllllm
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004078B1; symbol: __Z4Linellllm
void __cdecl Line(int x, int y, int w, int h, unsigned int c)
{
  Line(0, x, y, w, h, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004078E9; symbol: __Z3BarP6bitmapllllmm
void __cdecl Bar(pbitmap b, int x, int y, int w, int h, unsigned int cfg, unsigned int cbg)
{
  RECT lpRect; // [esp+10h] [ebp-18h]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004079C3; symbol: __Z3BarP6bitmapllllm
void __cdecl Bar(pbitmap b, int x, int y, int w, int h, unsigned int c)
{
  Bar(b, x, y, w, h, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407A02; symbol: __Z3Barllllmm
void __cdecl Bar(int x, int y, int w, int h, unsigned int cfg, unsigned int cbg)
{
  Bar(0, x, y, w, h, cfg, cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407A41; symbol: __Z3Barllllm
void __cdecl Bar(int x, int y, int w, int h, unsigned int c)
{
  Bar(x, y, w, h, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407A79; symbol: __Z3Barllll
void __cdecl Bar(int x, int y, int w, int h)
{
  Bar(x, y, w, h, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407AAA; symbol: __Z5ClearP6bitmapm
void __cdecl Clear(pbitmap b, unsigned int c)
{
  if ( !b )
    b = _pmain;
  if ( !c )
    c = _cbg;
  Bar(b, 0, 0, b->Width, b->Height, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407B11; symbol: __Z5ClearP6bitmap
void __cdecl Clear(pbitmap b)
{
  Clear(b, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407B2D; symbol: __Z5Clearm
void __cdecl Clear(unsigned int c)
{
  Clear(0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407B49; symbol: __Z5Clearv
void Clear()
{
  Clear(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407B5E; symbol: __Z9CreateBMPP6bitmapmmm
pbitmap __cdecl CreateBMP(pbitmap b, unsigned int w, unsigned int h, unsigned int c)
{
  pbitmap bmp; // [esp+1Ch] [ebp-Ch]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407C60; symbol: __Z9CreateBMPP6bitmap
pbitmap __cdecl CreateBMP(pbitmap b)
{
  return CreateBMP(b, 0, 0, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407C8B; symbol: __Z9CreateBMPmmm
pbitmap __cdecl CreateBMP(unsigned int w, unsigned int h, unsigned int c)
{
  return CreateBMP(0, w, h, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407CB4; symbol: __Z9CreateBMPmm
pbitmap __cdecl CreateBMP(unsigned int w, unsigned int h)
{
  return CreateBMP(w, h, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407CD6; symbol: __Z9CreateBMPv
pbitmap CreateBMP()
{
  return CreateBMP(0, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407CF2; symbol: __Z10ReleaseBMPP6bitmap
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407D7D; symbol: __Z10ReleaseBMPv
void ReleaseBMP()
{
  bitmap *v0; // eax
  bitmap *v1; // eax

  v0 = GetScr();
  ReleaseBMP(v0);
  v1 = GetWin();
  ReleaseBMP(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00407FF5; symbol: __Z7DrawBMPP6bitmapS0_mmmmmmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  pbitmap bm; // ST58_4
  BLENDFUNCTION ST54_4_17; // ST54_4
  unsigned __int8 alpha; // [esp+5Ch] [ebp-1Ch]
  unsigned int ca; // [esp+A8h] [ebp+30h]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408284; symbol: __Z7DrawBMPP6bitmapS0_mmmmmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, bd, xs, ys, ws, hs, xd, yd, wd, hd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004082DF; symbol: __Z7DrawBMPP6bitmapS0_mmmmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(bs, bd, xs, ys, w, h, xd, yd, w, h, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408339; symbol: __Z7DrawBMPP6bitmapS0_mmmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(bs, bd, xs, ys, xd, yd, w, h, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408386; symbol: __Z7DrawBMPP6bitmapS0_mmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, bd, 0, 0, 0, 0, xd, yd, wd, hd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004083E4; symbol: __Z7DrawBMPP6bitmapS0_mmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, bd, xd, yd, wd, hd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408423; symbol: __Z7DrawBMPP6bitmapS0_mmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(bs, bd, xd, yd, 0, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408463; symbol: __Z7DrawBMPP6bitmapS0_mm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd)
{
  DrawBMP(bs, bd, xd, yd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408494; symbol: __Z7DrawBMPP6bitmapS0_m
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int c)
{
  DrawBMP(bs, bd, 0, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004084C6; symbol: __Z7DrawBMPP6bitmapS0_
void __cdecl DrawBMP(pbitmap bs, pbitmap bd)
{
  DrawBMP(bs, bd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004084E9; symbol: __Z7DrawBMPP6bitmapmmmmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, 0, xs, ys, ws, hs, xd, yd, wd, hd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408544; symbol: __Z7DrawBMPP6bitmapmmmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, xs, ys, ws, hs, xd, yd, wd, hd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408598; symbol: __Z7DrawBMPP6bitmapmmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(bs, xs, ys, w, h, xd, yd, w, h, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004085EB; symbol: __Z7DrawBMPP6bitmapmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(bs, xs, ys, xd, yd, w, h, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408631; symbol: __Z7DrawBMPP6bitmapmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, 0, 0, 0, 0, xd, yd, wd, hd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408688; symbol: __Z7DrawBMPP6bitmapmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, xd, yd, wd, hd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004086C0; symbol: __Z7DrawBMPP6bitmapmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(bs, xd, yd, 0, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004086F9; symbol: __Z7DrawBMPP6bitmapmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd)
{
  DrawBMP(bs, xd, yd, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408723; symbol: __Z7DrawBMPP6bitmapm
void __cdecl DrawBMP(pbitmap bs, unsigned int c)
{
  DrawBMP(bs, 0, 0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040874E; symbol: __Z7DrawBMPP6bitmap
void __cdecl DrawBMP(pbitmap bs)
{
  DrawBMP(bs, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040876A; symbol: __Z7DrawBMPmmmmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(0, xs, ys, ws, hs, xd, yd, wd, hd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004087BE; symbol: __Z7DrawBMPmmmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(0, xs, ys, ws, hs, xd, yd, wd, hd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040880B; symbol: __Z7DrawBMPmmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(0, xs, ys, xd, yd, w, h, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408851; symbol: __Z7DrawBMPmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(0, xs, ys, xd, yd, w, h);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408890; symbol: __Z7DrawBMPmmmmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(0, xd, yd, wd, hd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004088C8; symbol: __Z7DrawBMPmmmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(0, xd, yd, wd, hd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004088F9; symbol: __Z7DrawBMPmmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(0, xd, yd, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408923; symbol: __Z7DrawBMPmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd)
{
  DrawBMP(0, xd, yd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408946; symbol: __Z7DrawBMPm
void __cdecl DrawBMP(unsigned int c)
{
  DrawBMP(0, c);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408962; symbol: __Z7DrawBMPv
void DrawBMP()
{
  DrawBMP(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408977; symbol: __Z2HIy
unsigned int __cdecl HI(uint64_t val)
{
  return HIDWORD(val);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408995; symbol: __Z2LOy
unsigned int __cdecl LO(uint64_t val)
{
  return val;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004089AC; symbol: __Z7SendMsgv
void SendMsg()
{
  TranslateMessage(&_mst);
  DispatchMessageA(&_mst);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004089D3; symbol: __Z9CustomMsgv
BOOL CustomMsg()
{
  MSG *v0; // eax
  bool result; // [esp+Fh] [ebp-1h]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408A80; symbol: __Z9IsNextMsgv
signed int IsNextMsg()
{
  MSG *v0; // eax
  MSG *v1; // eax
  bool result; // [esp+Fh] [ebp-1h]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408B7A; symbol: __Z10GetNextMsgv
UINT GetNextMsg()
{
  return _ms.message;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408B84; symbol: __Z11WaitNextMsgv
UINT WaitNextMsg()
{
  char v0; // al

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408BD3; symbol: __Z5IsMsgPKmm
bool __cdecl IsMsg(const unsigned int *uM, unsigned int length)
{
  unsigned int mi; // [esp+Ch] [ebp-4h]

  for ( mi = 0; mi < length; ++mi )
  {
    if ( _ms.message == uM[mi] )
      return 1;
  }
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408C17; symbol: __Z6GetMsgPKmm
uint64_t __cdecl GetMsg(const unsigned int *uM, unsigned int length)
{
  LPARAM v2; // ebx
  WPARAM v3; // esi

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408C77; symbol: __Z7WaitMsgPKmm
uint64_t __cdecl WaitMsg(const unsigned int *uM, unsigned int length)
{
  do
    WaitNextMsg();
  while ( !IsMsg(uM, length) );
  return GetMsg(uM, length);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408CB1; symbol: __Z5IsMsgm
bool __cdecl IsMsg(unsigned int uM)
{
  unsigned int ums[1]; // [esp+14h] [ebp-4h]

  ums[0] = uM;
  return IsMsg(ums, 1u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408CD2; symbol: __Z6GetMsgm
uint64_t __cdecl GetMsg(unsigned int uM)
{
  unsigned int ums[1]; // [esp+14h] [ebp-4h]

  ums[0] = uM;
  return GetMsg(ums, 1u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408CF3; symbol: __Z7WaitMsgm
uint64_t __cdecl WaitMsg(unsigned int uM)
{
  unsigned int ums[1]; // [esp+1Ch] [ebp-Ch]

  ums[0] = uM;
  return WaitMsg(ums, 1u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408D14; symbol: __Z5IsKeym
bool __cdecl IsKey(unsigned int k)
{
  return IsMsg(0x100u) && (!k || GetKey() == k);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408D48; symbol: __Z5IsKeyv
bool IsKey()
{
  return IsKey(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408D5C; symbol: __Z6GetKeyv
unsigned int GetKey()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x100u);
  return HI(v0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408D7C; symbol: __Z7WaitKeym
unsigned int __cdecl WaitKey(unsigned int k)
{
  while ( !IsKey() )
    WaitNextMsg();
  return GetKey();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408D9C; symbol: __Z7WaitKeyv
unsigned int WaitKey()
{
  return WaitKey(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408DB0; symbol: __Z7IsMousem
bool __cdecl IsMouse(unsigned int m)
{
  return IsMsg(_bdn, 3u) && (!m || GetMouse() == m);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408DEC; symbol: __Z7IsMousev
bool IsMouse()
{
  return IsMouse(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E00; symbol: __Z8GetMousev
unsigned int GetMouse()
{
  uint64_t v0; // rax

  v0 = GetMsg(_bdn, 3u);
  return HI(v0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E28; symbol: __Z9WaitMousem
unsigned int __cdecl WaitMouse(unsigned int m)
{
  while ( !IsMouse() )
    WaitNextMsg();
  return GetMouse();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E48; symbol: __Z9WaitMousev
unsigned int WaitMouse()
{
  return WaitMouse(0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E5C; symbol: __Z11IsMouseLeftv
bool IsMouseLeft()
{
  return IsMsg(0x201u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E70; symbol: __Z13WaitMouseLeftv
void WaitMouseLeft()
{
  WaitMsg(0x201u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E85; symbol: __Z13IsMouseMiddlev
bool IsMouseMiddle()
{
  return IsMsg(0x207u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408E99; symbol: __Z15WaitMouseMiddlev
void WaitMouseMiddle()
{
  WaitMsg(0x207u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408EAE; symbol: __Z12IsMouseRightv
bool IsMouseRight()
{
  return IsMsg(0x204u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408EC2; symbol: __Z14WaitMouseRightv
void WaitMouseRight()
{
  WaitMsg(0x204u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408ED7; symbol: __Z12IsMouseWheelv
bool IsMouseWheel()
{
  return IsMsg(0x20Au);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408EEB; symbol: __Z13GetMouseWheelv
unsigned int GetMouseWheel()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x20Au);
  return HI(v0) >> 16;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F11; symbol: __Z14WaitMouseWheelv
void WaitMouseWheel()
{
  WaitMsg(0x20Au);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F26; symbol: __Z11IsMouseMovev
bool IsMouseMove()
{
  return IsMsg(0x200u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F3A; symbol: __Z12GetMouseMovev
unsigned int GetMouseMove()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x200u);
  return LO(v0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F5A; symbol: __Z13WaitMouseMovev
unsigned int WaitMouseMove()
{
  uint64_t v0; // rax

  v0 = WaitMsg(0x200u);
  return LO(v0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F7A; symbol: __Z10IsDropFilev
bool IsDropFile()
{
  return IsMsg(0x233u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408F8E; symbol: __Z12GetMouseAbsXv
LONG GetMouseAbsX()
{
  POINT p; // [esp+18h] [ebp-10h]

  GetCursorPos(&p);
  return p.x;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408FA7; symbol: __Z12GetMouseAbsYv
LONG GetMouseAbsY()
{
  POINT p; // [esp+18h] [ebp-10h]

  GetCursorPos(&p);
  return p.y;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408FC0; symbol: __Z12GetMouseWinXv
int GetMouseWinX()
{
  LONG v0; // ebx

  v0 = GetMouseAbsX();
  return v0 - GetPosX();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408FDD; symbol: __Z12GetMouseWinYv
int GetMouseWinY()
{
  LONG v0; // ebx

  v0 = GetMouseAbsY();
  return v0 - GetPosY();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00408FFA; symbol: __Z12GetMousePosXv
int GetMousePosX()
{
  int v0; // ebx
  int v1; // eax

  v0 = GetMouseWinX();
  if ( (_style & 0x80000000) != 0 )
    v1 = 0;
  else
    v1 = GetBorderWidth();
  return v0 - v1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409027; symbol: __Z12GetMousePosYv
int GetMousePosY()
{
  int v0; // ebx
  int v1; // esi
  int v2; // eax

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409059; symbol: __Z7MsgBoxWPKsS0_m
unsigned int __cdecl MsgBoxW(const __int16 *s, const __int16 *title, unsigned int i)
{
  return MessageBoxW(0, (LPCWSTR)s, (LPCWSTR)title, i);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409085; symbol: __Z6MsgBoxPKcS0_m
unsigned int __cdecl MsgBox(const char *s, const char *title, unsigned int i)
{
  return MessageBoxA(0, s, title, i);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004090B1; symbol: __Z7MsgBoxWPKsS0_
void __cdecl MsgBoxW(const __int16 *s, const __int16 *title)
{
  MsgBoxW(s, title, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004090D4; symbol: __Z6MsgBoxPKcS0_
void __cdecl MsgBox(const char *s, const char *title)
{
  MsgBox(s, title, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004090F7; symbol: __Z7MsgBoxWPKs
void __cdecl MsgBoxW(const __int16 *s)
{
  MsgBoxW(s, &title);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409113; symbol: __Z6MsgBoxPKc
void __cdecl MsgBox(const char *s)
{
  MsgBox(s, ::s);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040912F; symbol: __Z5Delaym
void __cdecl Delay(unsigned int t)
{
  Sleep(t);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409146; symbol: __Z5Delayv
void Delay()
{
  Delay(1u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 Windows MCI 音频/音乐接口。
// Address: 0x0040915B; symbol: __Z10SendStringv
unsigned int SendString()
{
  mciSendStringA(command_in, command_out, 0x7Fu, 0);
  return strtoul(command_out, 0, 10);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040920B; symbol: __Z9PlayAudiomPKcb
void __cdecl PlayAudio(unsigned int id, const char *s, bool b)
{
  const char *v3; // edx

  if ( b )
    v3 = "play s%lu%s wait repeat";
  else
    v3 = "play s%lu%s";
  sprintf(command_in, v3, id, s);
  SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040924F; symbol: __Z9StopAudiom
void __cdecl StopAudio(unsigned int id)
{
  SetAudioPos(id, 0, 0);
  sprintf(command_in, "stop s%lu", id);
  SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409293; symbol: __Z10PauseAudiom
void __cdecl PauseAudio(unsigned int id)
{
  sprintf(command_in, "pause s%lu", id);
  SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004092BC; symbol: __Z11ResumeAudiom
void __cdecl ResumeAudio(unsigned int id)
{
  sprintf(command_in, "resume s%lu", id);
  SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004092E5; symbol: __Z12ReleaseAudiom
void __cdecl ReleaseAudio(unsigned int id)
{
  sprintf(command_in, "close s%lu", id);
  SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040930E; symbol: __Z11GetAudioPosm
unsigned int __cdecl GetAudioPos(unsigned int id)
{
  sprintf(command_in, "status s%lu position", id);
  return SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409336; symbol: __Z11SetAudioPosmmb
void __cdecl SetAudioPos(unsigned int id, unsigned int pos, bool b)
{
  sprintf(command_in, "seek s%lu to %lu", id, pos);
  SendString();
  PlayAudio(id, s, b);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409387; symbol: __Z11GetAudioLenm
unsigned int __cdecl GetAudioLen(unsigned int id)
{
  sprintf(command_in, "status s%lu length", id);
  return SendString();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004093AF; symbol: __Z6IsFilePKc
bool __cdecl IsFile(const char *s)
{
  WIN32_FIND_DATA fd; // [esp+18h] [ebp-150h]
  bool result; // [esp+15Bh] [ebp-Dh]
  HANDLE fh; // [esp+15Ch] [ebp-Ch]

  fh = FindFirstFileA(s, &fd);
  result = (char *)fh + 1 != 0;
  if ( result )
    FindClose(fh);
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004093F7; symbol: __Z13UTF8ToUnicodePhPj
uint8_t __cdecl UTF8ToUnicode(uint8_t *utf8, uint32_t *unicode)
{
  uint8_t result; // al
  const uint8_t mask_lut[3]; // [esp+Dh] [ebp-13h]
  const uint8_t range_lut[3]; // [esp+10h] [ebp-10h]
  const uint8_t length_lut[3]; // [esp+13h] [ebp-Dh]
  byte b; // [esp+16h] [ebp-Ah]
  const uint8_t lut_size; // [esp+17h] [ebp-9h]
  uint32_t i; // [esp+18h] [ebp-8h]
  uint8_t length; // [esp+1Fh] [ebp-1h]

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040956C; symbol: __Z14UnicodeToUTF16jPt
uint8_t __cdecl UnicodeToUTF16(uint32_t unicode, uint16_t *utf16)
{
  uint8_t result; // al

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x004095D5; symbol: __Z41__static_initialization_and_destruction_0ii
void __cdecl __static_initialization_and_destruction_0(int __initialize_p, int __priority)
{
  BOOL v2; // [esp+Ch] [ebp-Ch]

  if ( __initialize_p == 1 && __priority == 0xFFFF )
    weak___ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii___ZN7Gdiplus11GdiplusBasedlEPv(0, 0, 0, v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00409611; symbol: __GLOBAL__sub_I_version
void _GLOBAL__sub_I_version()
{
  __static_initialization_and_destruction_0(1, 0xFFFF);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x0040C29B; symbol: __ZL7getleadPv@4
DWORD __stdcall getlead(LPVOID p)
{
  Steam *const v2; // ST00_4
  Window *const v3; // ST00_4
  Window *v4; // [esp+0h] [ebp-18h]

  if ( !*((_BYTE *)p + 3382) )
  {
    *((_BYTE *)p + 3382) = 1;
    Window::paintevent(v4);
    Steam::getlead(v2);
    Window::paintevent(v3);
    *((_BYTE *)p + 3382) = 0;
  }
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004231EC; symbol: _timeEndPeriod@4
MMRESULT __stdcall timeEndPeriod(UINT uPeriod)
{
  return timeEndPeriod(uPeriod);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004231F4; symbol: _timeBeginPeriod@4
MMRESULT __stdcall timeBeginPeriod(UINT uPeriod)
{
  return timeBeginPeriod(uPeriod);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00423204; symbol: _GdiplusStartup@12
int __stdcall GdiplusStartup(int a1, int a2, int a3)
{
  return GdiplusStartup(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x0042320C; symbol: _GdiplusShutdown@4
int __stdcall GdiplusShutdown(int a1)
{
  return GdiplusShutdown(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00423224; symbol: _GdipGetImageWidth@8
int __stdcall GdipGetImageWidth(int a1, int a2)
{
  return GdipGetImageWidth(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x0042322C; symbol: _GdipGetImageHeight@8
int __stdcall GdipGetImageHeight(int a1, int a2)
{
  return GdipGetImageHeight(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00423234; symbol: _GdipFree@4
int __stdcall GdipFree(int a1)
{
  return GdipFree(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x0042323C; symbol: _GdipDrawImageRect@24
int __stdcall GdipDrawImageRect(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return GdipDrawImageRect(a1, a2, a3, a4, a5, a6);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00423244; symbol: _GdipDisposeImage@4
int __stdcall GdipDisposeImage(int a1)
{
  return GdipDisposeImage(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x0042324C; symbol: _GdipDeletePrivateFontCollection@4
int __stdcall GdipDeletePrivateFontCollection(int a1)
{
  return GdipDeletePrivateFontCollection(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00423254; symbol: _GdipDeleteGraphics@4
int __stdcall GdipDeleteGraphics(int a1)
{
  return GdipDeleteGraphics(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x0042325C; symbol: _GdipDeleteCustomLineCap@4
int __stdcall GdipDeleteCustomLineCap(int a1)
{
  return GdipDeleteCustomLineCap(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00423264; symbol: _GdipDeleteCachedBitmap@4
int __stdcall GdipDeleteCachedBitmap(int a1)
{
  return GdipDeleteCachedBitmap(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x0042326C; symbol: _GdipCreateFromHDC@8
int __stdcall GdipCreateFromHDC(int a1, int a2)
{
  return GdipCreateFromHDC(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00423274; symbol: _GdipCreateBitmapFromHBITMAP@12
int __stdcall GdipCreateBitmapFromHBITMAP(int a1, int a2, int a3)
{
  return GdipCreateBitmapFromHBITMAP(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x0042327C; symbol: _GdipCloneImage@8
int __stdcall GdipCloneImage(int a1, int a2)
{
  return GdipCloneImage(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00423284; symbol: _GdipAlloc@4
int __stdcall GdipAlloc(int a1)
{
  return GdipAlloc(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042328C; symbol: _TextOutA@20
BOOL __stdcall TextOutA(HDC a1, int a2, int a3, LPCSTR a4, int a5)
{
  return TextOutA(a1, a2, a3, a4, a5);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423294; symbol: _StretchBlt@44
BOOL __stdcall StretchBlt(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, DWORD a11)
{
  return StretchBlt(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042329C; symbol: _SetTextColor@8
COLORREF __stdcall SetTextColor(HDC a1, COLORREF a2)
{
  return SetTextColor(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232A4; symbol: _SetPixel@16
COLORREF __stdcall SetPixel(HDC a1, int a2, int a3, COLORREF a4)
{
  return SetPixel(a1, a2, a3, a4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232AC; symbol: _SetBkMode@8
int __stdcall SetBkMode(HDC a1, int a2)
{
  return SetBkMode(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232B4; symbol: _SetBkColor@8
COLORREF __stdcall SetBkColor(HDC a1, COLORREF a2)
{
  return SetBkColor(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232BC; symbol: _SelectObject@8
HGDIOBJ __stdcall SelectObject(HDC a1, HGDIOBJ a2)
{
  return SelectObject(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232C4; symbol: _MoveToEx@16
BOOL __stdcall MoveToEx(HDC a1, int a2, int a3, LPPOINT a4)
{
  return MoveToEx(a1, a2, a3, a4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232CC; symbol: _LineTo@12
BOOL __stdcall LineTo(HDC a1, int a2, int a3)
{
  return LineTo(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232D4; symbol: _GetTextMetricsA@8
BOOL __stdcall GetTextMetricsA(HDC a1, LPTEXTMETRICA a2)
{
  return GetTextMetricsA(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232DC; symbol: _GetTextExtentPoint32A@16
BOOL __stdcall GetTextExtentPoint32A(HDC a1, LPCSTR a2, int a3, LPSIZE a4)
{
  return GetTextExtentPoint32A(a1, a2, a3, a4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232E4; symbol: _GetStockObject@4
HGDIOBJ __stdcall GetStockObject(int a1)
{
  return GetStockObject(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232EC; symbol: _GetPixel@12
COLORREF __stdcall GetPixel(HDC a1, int a2, int a3)
{
  return GetPixel(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232F4; symbol: _GetDeviceCaps@8
int __stdcall GetDeviceCaps(HDC a1, int a2)
{
  return GetDeviceCaps(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004232FC; symbol: _DeleteObject@4
BOOL __stdcall DeleteObject(HGDIOBJ a1)
{
  return DeleteObject(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423304; symbol: _DeleteDC@4
BOOL __stdcall DeleteDC(HDC a1)
{
  return DeleteDC(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042330C; symbol: _CreateSolidBrush@4
HBRUSH __stdcall CreateSolidBrush(COLORREF a1)
{
  return CreateSolidBrush(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423314; symbol: _CreatePen@12
HPEN __stdcall CreatePen(int a1, int a2, COLORREF a3)
{
  return CreatePen(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042331C; symbol: _CreateFontA@56
HFONT __stdcall CreateFontA(int a1, int a2, int a3, int a4, int a5, DWORD a6, DWORD a7, DWORD a8, DWORD a9, DWORD a10, DWORD a11, DWORD a12, DWORD a13, LPCSTR a14)
{
  return CreateFontA(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423324; symbol: _CreateCompatibleDC@4
HDC __stdcall CreateCompatibleDC(HDC a1)
{
  return CreateCompatibleDC(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042332C; symbol: _CreateCompatibleBitmap@12
HBITMAP __stdcall CreateCompatibleBitmap(HDC a1, int a2, int a3)
{
  return CreateCompatibleBitmap(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423334; symbol: _TransparentBlt@44
BOOL __stdcall TransparentBlt(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, UINT a11)
{
  return TransparentBlt(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0042333C; symbol: _AlphaBlend@44
BOOL __stdcall AlphaBlend(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, BLENDFUNCTION a11)
{
  return AlphaBlend(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423344; symbol: ___gxx_personality_v0
int __gxx_personality_v0()
{
  return ___gxx_personality_v0();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423350; symbol: __setargv
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004236F0; symbol: ___cpu_features_init
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004237D0; symbol: ___do_global_dtors
void __cdecl __do_global_dtors()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))*off_42730C;
  if ( *off_42730C )
  {
    do
    {
      v0();
      v0 = (void (*)(void))off_42730C[1];
      ++off_42730C;
    }
    while ( v0 );
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423800; symbol: ___do_global_ctors
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423850; symbol: ___main
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423870; symbol: TlsCallback_1
signed int __stdcall TlsCallback_1(int a1, int a2, int a3)
{
  if ( a2 != 3 && a2 )
    return 1;
  __mingw_TLScallback(a1, a2);
  return 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004238C0; symbol: ___dyn_tls_init@12
signed int __stdcall __dyn_tls_init(int a1, int a2, int a3)
{
  if ( _CRT_MT != 2 )
    _CRT_MT = 2;
  if ( a2 != 2 && a2 == 1 )
    __mingw_TLScallback(a1, 1);
  return 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423960; symbol: sub_423960
void sub_423960()
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：写入文件内容。
// Address: 0x00423B90; symbol: sub_423B90
void __noreturn sub_423B90(char *a1, ...)
{
  va_list va; // [esp+24h] [ebp+8h]

  va_start(va, a1);
  fwrite("Mingw runtime failure:\n", 1u, 0x17u, &__iob[2]);
  vfprintf(&__iob[2], a1, va);
  abort();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00423BE0; symbol: sub_423BE0
void *__usercall sub_423BE0@<eax>(size_t a1@<ecx>, void *a2@<edx>, void *lpAddress@<eax>)
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
    sub_423B90("  VirtualQuery failed for %d bytes at address %p", 28, v4);
  if ( Buffer.Protect == 64 || Buffer.Protect == 4 )
    return memcpy(v4, v5, v3);
  VirtualProtect(Buffer.BaseAddress, Buffer.RegionSize, 0x40u, &flOldProtect);
  v7 = Buffer.Protect;
  result = memcpy(v4, v5, v3);
  if ( v7 != 64 && v7 != 4 )
    result = (void *)VirtualProtect(Buffer.BaseAddress, Buffer.RegionSize, flOldProtect, &flOldProtect);
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423CD0; symbol: __pei386_runtime_relocator
void *_pei386_runtime_relocator()
{
  void *result; // eax
  _DWORD *v1; // ebx
  int v2; // edi
  int *v3; // esi
  int v4; // ecx
  int v5; // edx
  _DWORD *v6; // eax
  int v7; // ST04_4
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // edi
  int v12; // [esp+1Ch] [ebp-10h]

  result = (void *)dword_470964;
  if ( dword_470964 )
    return result;
  dword_470964 = 1;
  result = (void *)(&_RUNTIME_PSEUDO_RELOC_LIST_END__ - &_RUNTIME_PSEUDO_RELOC_LIST__);
  if ( &_RUNTIME_PSEUDO_RELOC_LIST_END__ - &_RUNTIME_PSEUDO_RELOC_LIST__ <= 7 )
    return result;
  if ( (signed int)result <= 11 )
  {
    v1 = &_RUNTIME_PSEUDO_RELOC_LIST__;
  }
  else
  {
    if ( _RUNTIME_PSEUDO_RELOC_LIST__ || unk_42A028 )
    {
      v1 = &_RUNTIME_PSEUDO_RELOC_LIST__;
      goto LABEL_16;
    }
    v1 = &unk_42A030;
    if ( unk_42A02C )
    {
      v1 = &_RUNTIME_PSEUDO_RELOC_LIST__;
LABEL_9:
      result = (void *)v1[2];
      if ( result != (void *)1 )
        sub_423B90("  Unknown pseudo relocation protocol version %d.\n", v1[2]);
      while ( 1 )
      {
        v1 += 3;
        if ( v1 >= (_DWORD *)&_RUNTIME_PSEUDO_RELOC_LIST_END__ )
          break;
        v2 = v1[1];
        v3 = (int *)(*v1 + 0x400000);
        v4 = *v3;
        v5 = *((unsigned __int8 *)v1 + 8);
        v6 = (_DWORD *)(v2 + 0x400000);
        if ( v5 == 16 )
        {
          v10 = *(unsigned __int16 *)(v2 + 0x400000);
          if ( (v10 & 0x8000u) != 0 )
            v10 |= 0xFFFF0000;
          v12 = v10 - (_DWORD)v3 + v4;
          result = sub_423BE0(2u, &v12, v6);
        }
        else if ( v5 == 32 )
        {
          v12 = *v6 + v4 - (_DWORD)v3;
          result = sub_423BE0(4u, &v12, v6);
        }
        else
        {
          if ( v5 != 8 )
          {
            v7 = *((unsigned __int8 *)v1 + 8);
            v12 = 0;
            sub_423B90("  Unknown pseudo relocation bit size %d.\n", v7);
          }
          v11 = *(unsigned __int8 *)v6;
          if ( *(_BYTE *)v6 < 0 )
            v11 |= 0xFFFFFF00;
          v12 = v11 - (_DWORD)v3 + v4;
          result = sub_423BE0(1u, &v12, v6);
        }
      }
      return result;
    }
  }
  if ( !*v1 )
  {
    result = (void *)v1[1];
    if ( !result )
      goto LABEL_9;
  }
LABEL_16:
  while ( v1 < (_DWORD *)&_RUNTIME_PSEUDO_RELOC_LIST_END__ )
  {
    v8 = v1[1];
    v9 = *v1;
    v1 += 2;
    v12 = *(_DWORD *)(v8 + 0x400000) + v9;
    result = sub_423BE0(4u, &v12, (void *)(v8 + 0x400000));
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423EB0; symbol: __Unwind_Resume
void __noreturn _Unwind_Resume()
{
  __Unwind_Resume();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00423EB8; symbol: ___chkstk_ms
void __usercall __spoils<ecx> __chkstk_ms(unsigned int a1@<eax>, int a2@<ecx>, char a3)
{
  char *v3; // ecx
  int v4; // [esp-4h] [ebp-4h]

  v4 = a2;
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00423EF0; symbol: _fesetenv
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00423F60; symbol: sub_423F60
signed int __usercall sub_423F60@<eax>(char *a1@<eax>, unsigned int a2@<edx>)
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00424000; symbol: sub_424000
signed int __usercall sub_424000@<eax>(int a1@<eax>)
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00424070; symbol: sub_424070
int __usercall sub_424070@<eax>(char *a1@<eax>, int a2@<edx>, __int16 a3@<cx>)
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
        return (int)(v3 + 1);
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
                return (int)(v14 + 1);
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
            return (int)(v3 + 1);
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
      return (int)(v14 + 1);
    while ( v15 == 127 )
    {
      if ( !(v22 & 0x20) )
      {
        v15 = (v14++)[1];
        break;
      }
      v15 = *++v14;
      if ( *v14 == 93 )
        return (int)(v14 + 1);
    }
    ++v14;
    if ( !v15 )
      return 0;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00424330; symbol: sub_424330
int __usercall sub_424330@<eax>(char *a1@<eax>, _BYTE *a2@<edx>, unsigned int a3@<ecx>)
{
  char *v3; // ebp
  char v4; // cl
  int v5; // edi
  int v6; // edx
  char *v7; // esi
  char *v8; // eax
  int v9; // ebx
  int v10; // ST1C_4
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int result; // eax
  char v15; // dl
  _BYTE *v16; // ebx
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
  v5 = (int)(a2 + 1);
LABEL_3:
  v6 = v4;
  v7 = (char *)(v5 - 1);
  v8 = v3 + 1;
  switch ( v4 )
  {
    case 0:
      return -*v7;
    case 63:
      if ( *(_BYTE *)(v5 - 1) )
      {
        ++v3;
        goto LABEL_27;
      }
      return 63;
    case 91:
      v17 = *(char *)(v5 - 1);
      if ( !*(_BYTE *)(v5 - 1) )
        return 91;
      if ( v3[1] != 33 )
      {
        v3 = (char *)sub_424070(v8, v17, v20);
        goto LABEL_26;
      }
      v18 = v3 + 2;
      if ( sub_424070(v3 + 2, v17, v20) )
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
          result = sub_424330(v20 | 0x10000, v7);
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
      v9 = *(char *)(v5 - 1);
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00424550; symbol: sub_424550
signed int __usercall sub_424550@<eax>(int a1@<eax>, int a2@<edx>)
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004245B0; symbol: sub_4245B0
void __usercall sub_4245B0(_DWORD *a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  _DWORD *v3; // ebx
  int v4; // esi
  int v5; // eax

  v3 = a1;
  v4 = a2;
  if ( *a1 )
    ((void (*)(void))sub_4245B0)();
  v5 = v3[2];
  if ( v5 && v4 )
    sub_424550(v5, v4);
  if ( v3[1] )
    sub_4245B0(a3, v4);
  free(v3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00424600; symbol: sub_424600
int __usercall sub_424600@<eax>(const char *a1@<eax>, unsigned int a2@<edx>, int a3@<ecx>, int a4)
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
  int v27; // esi
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
            return 1;
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
              return 1;
            }
            return 1;
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
        v68 = sub_424600(v105, v108, a4);
        v108 = v67;
        if ( v68 == 1 )
          return 1;
        if ( *v55 != 44 )
          return v68;
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
  v109 = (char *)__mingw_dirname(v10);
  v11 = v109;
  v112 = 0;
  v107 = (char *)sub_424000((int)&v110);
  if ( !v107 )
  {
    v12 = v108;
    if ( sub_423F60(v11, v108) )
    {
      v13 = v12;
      BYTE1(v13) |= 0x80u;
      v107 = (char *)sub_424600(v105, v13, &v110);
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
        return 1;
      v107 = (char *)sub_424550((int)v75, (int)&v110);
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
          v107 = (char *)sub_423F60(v4, v108);
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
              sub_424550((int)v90, a4);
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
            v27 = __mingw_readdir(v26);
            if ( !v27 )
            {
              __mingw_closedir(v26);
              if ( v102 )
                sub_4245B0(v102, a4, v76);
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
            if ( v109 && *(_DWORD *)(v27 + 8) != 16 || sub_424330(v106, (_BYTE *)(v27 + 12), v108) )
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
                sub_424550((int)v39, a4);
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
          v42 = stricoll(v92, v93);
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
      return (int)v107;
    }
  }
  return (int)v107;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004253E0; symbol: sub_4253E0
HANDLE __usercall sub_4253E0@<eax>(const CHAR *lpFileName@<eax>, int a2@<edx>)
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004254B0; symbol: sub_4254B0
BOOL __usercall sub_4254B0@<eax>(void *hFindFile@<eax>, int a2@<edx>)
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258D0; symbol: _wcstombs
size_t __cdecl wcstombs(char *a1, const wchar_t *a2, size_t a3)
{
  return _wcstombs(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258D8; symbol: _wcslen
size_t __cdecl wcslen(const wchar_t *a1)
{
  return _wcslen(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258E0; symbol: _vfprintf
int __cdecl vfprintf(FILE *a1, const char *a2, va_list a3)
{
  return _vfprintf(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258E8; symbol: _tolower
int __cdecl tolower(int a1)
{
  return _tolower(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258F0; symbol: _time
time_t __cdecl time(time_t *a1)
{
  return _time(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004258F8; symbol: _strtoul
unsigned int __cdecl strtoul(const char *a1, char **a2, int a3)
{
  return _strtoul(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425900; symbol: _strstr
char *__cdecl strstr(const char *a1, const char *a2)
{
  return _strstr(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425908; symbol: _strrchr
char *__cdecl strrchr(const char *a1, int a2)
{
  return _strrchr(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425910; symbol: _strlen
size_t __cdecl strlen(const char *a1)
{
  return _strlen(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425918; symbol: _strcpy
char *__cdecl strcpy(char *a1, const char *a2)
{
  return _strcpy(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425920; symbol: _strcoll
int __cdecl strcoll(const char *a1, const char *a2)
{
  return _strcoll(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425928; symbol: _strcmp
int __cdecl strcmp(const char *a1, const char *a2)
{
  return _strcmp(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425930; symbol: _strcat
char *__cdecl strcat(char *a1, const char *a2)
{
  return _strcat(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425938; symbol: _srand
void __cdecl srand(unsigned int a1)
{
  _srand(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425948; symbol: _signal
void (__cdecl *__cdecl signal(int a1, void (__cdecl *a2)(int)))(int)
{
  return _signal(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425950; symbol: _setlocale
char *__cdecl setlocale(int a1, const char *a2)
{
  return _setlocale(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425958; symbol: _realloc
void *__cdecl realloc(void *a1, size_t a2)
{
  return _realloc(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425960; symbol: _rand
int __cdecl rand()
{
  return _rand();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425968; symbol: _memset
void *__cdecl memset(void *a1, int a2, size_t a3)
{
  return _memset(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425970; symbol: _memcpy
void *__cdecl memcpy(void *a1, const void *a2, size_t a3)
{
  return _memcpy(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425978; symbol: _mbstowcs
size_t __cdecl mbstowcs(wchar_t *a1, const char *a2, size_t a3)
{
  return _mbstowcs(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425980; symbol: _malloc
void *__cdecl malloc(size_t a1)
{
  return _malloc(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425988; symbol: _localtime
struct tm *__cdecl localtime(const time_t *a1)
{
  return _localtime(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：写入文件内容。
// Address: 0x00425990; symbol: _fwrite
size_t __cdecl fwrite(const void *a1, size_t a2, size_t a3, FILE *a4)
{
  return _fwrite(a1, a2, a3, a4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425998; symbol: _free
void __cdecl free(void *a1)
{
  _free(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259A0; symbol: _clock
clock_t __cdecl clock()
{
  return _clock();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259A8; symbol: _calloc
void *__cdecl calloc(size_t a1, size_t a2)
{
  return _calloc(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259B0; symbol: _abort
void __cdecl __noreturn abort()
{
  _abort();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259B8; symbol: __setmode
int __cdecl _setmode(int a1, int a2)
{
  return __setmode(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259C0; symbol: __isctype
int __cdecl _isctype(int a1, int a2)
{
  return __isctype(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259C8; symbol: __fullpath
char *__cdecl _fullpath(char *a1, const char *a2, size_t a3)
{
  return __fullpath(a1, a2, a3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259D0; symbol: __errno
int _errno(void)
{
  return __errno();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259D8; symbol: __cexit
void __cdecl _cexit()
{
  __cexit();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259E0; symbol: ___p__fmode
int __p__fmode(void)
{
  return ___p__fmode();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259E8; symbol: ___p__environ
int __p__environ(void)
{
  return ___p__environ();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259F0; symbol: ___getmainargs
int __cdecl __getmainargs(int a1, int a2, int a3, int a4, int a5)
{
  return ___getmainargs(a1, a2, a3, a4, a5);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A28; symbol: _TranslateMessage@4
BOOL __stdcall TranslateMessage(const MSG *lpMsg)
{
  return TranslateMessage(lpMsg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A30; symbol: _SystemParametersInfoA@16
BOOL __stdcall SystemParametersInfoA(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni)
{
  return SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A60; symbol: _SetCursor@4
HCURSOR __stdcall SetCursor(HCURSOR hCursor)
{
  return SetCursor(hCursor);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A68; symbol: _SendMessageA@16
LRESULT __stdcall SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return SendMessageA(hWnd, Msg, wParam, lParam);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A70; symbol: _ReleaseDC@8
int __stdcall ReleaseDC(HWND hWnd, HDC hDC)
{
  return ReleaseDC(hWnd, hDC);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A88; symbol: _MessageBoxW@16
int __stdcall MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
  return MessageBoxW(hWnd, lpText, lpCaption, uType);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A90; symbol: _MessageBoxA@16
int __stdcall MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
  return MessageBoxA(hWnd, lpText, lpCaption, uType);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AA8; symbol: _IsZoomed@4
BOOL __stdcall IsZoomed(HWND hWnd)
{
  return IsZoomed(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AB0; symbol: _IsIconic@4
BOOL __stdcall IsIconic(HWND hWnd)
{
  return IsIconic(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AB8; symbol: _InvalidateRect@12
BOOL __stdcall InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase)
{
  return InvalidateRect(hWnd, lpRect, bErase);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AD8; symbol: _GetSystemMetrics@4
int __stdcall GetSystemMetrics(int nIndex)
{
  return GetSystemMetrics(nIndex);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AE0; symbol: _GetMonitorInfoA@8
BOOL __stdcall GetMonitorInfoA(HMONITOR hMonitor, LPMONITORINFO lpmi)
{
  return GetMonitorInfoA(hMonitor, lpmi);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：处理窗口消息循环。
// Address: 0x00425AE8; symbol: _GetMessageA@16
BOOL __stdcall GetMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
  return GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AF8; symbol: _GetDC@4
HDC __stdcall GetDC(HWND hWnd)
{
  return GetDC(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B00; symbol: _GetCursorPos@4
BOOL __stdcall GetCursorPos(LPPOINT lpPoint)
{
  return GetCursorPos(lpPoint);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B08; symbol: _GetAsyncKeyState@4
SHORT __stdcall GetAsyncKeyState(int vKey)
{
  return GetAsyncKeyState(vKey);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B10; symbol: _FrameRect@12
int __stdcall FrameRect(HDC hDC, const RECT *lprc, HBRUSH hbr)
{
  return FrameRect(hDC, lprc, hbr);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B20; symbol: _FillRect@12
int __stdcall FillRect(HDC hDC, const RECT *lprc, HBRUSH hbr)
{
  return FillRect(hDC, lprc, hbr);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B28; symbol: _EnumDisplayMonitors@16
BOOL __stdcall EnumDisplayMonitors(HDC hdc, LPCRECT lprcClip, MONITORENUMPROC lpfnEnum, LPARAM dwData)
{
  return EnumDisplayMonitors(hdc, lprcClip, lpfnEnum, dwData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B30; symbol: _DrawTextW@20
int __stdcall DrawTextW(HDC hDC, LPCWSTR lpString, int nCount, LPRECT lpRect, UINT uFormat)
{
  return DrawTextW(hDC, lpString, nCount, lpRect, uFormat);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B38; symbol: _DrawTextA@20
int __stdcall DrawTextA(HDC hDC, LPCSTR lpString, int nCount, LPRECT lpRect, UINT uFormat)
{
  return DrawTextA(hDC, lpString, nCount, lpRect, uFormat);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B40; symbol: _DispatchMessageA@4
LONG __stdcall DispatchMessageA(const MSG *lpMsg)
{
  return DispatchMessageA(lpMsg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B68; symbol: _lstrcpyA@8
LPSTR __stdcall lstrcpyA(LPSTR lpString1, LPCSTR lpString2)
{
  return lstrcpyA(lpString1, lpString2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B70; symbol: _lstrcmpA@8
int __stdcall lstrcmpA(LPCSTR lpString1, LPCSTR lpString2)
{
  return lstrcmpA(lpString1, lpString2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B78; symbol: _lstrcatA@8
LPSTR __stdcall lstrcatA(LPSTR lpString1, LPCSTR lpString2)
{
  return lstrcatA(lpString1, lpString2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B80; symbol: _VirtualQuery@12
DWORD __stdcall VirtualQuery(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, DWORD dwLength)
{
  return VirtualQuery(lpAddress, lpBuffer, dwLength);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B88; symbol: _VirtualProtect@16
BOOL __stdcall VirtualProtect(LPVOID lpAddress, DWORD dwSize, DWORD flNewProtect, PDWORD lpflOldProtect)
{
  return VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B90; symbol: _TlsGetValue@4
LPVOID __stdcall TlsGetValue(DWORD dwTlsIndex)
{
  return TlsGetValue(dwTlsIndex);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425B98; symbol: _Sleep@4
void __stdcall Sleep(DWORD dwMilliseconds)
{
  Sleep(dwMilliseconds);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BA8; symbol: _RemoveDirectoryA@4
BOOL __stdcall RemoveDirectoryA(LPCSTR lpPathName)
{
  return RemoveDirectoryA(lpPathName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BB0; symbol: _ReleaseMutex@4
BOOL __stdcall ReleaseMutex(HANDLE hMutex)
{
  return ReleaseMutex(hMutex);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BB8; symbol: _ReadFile@20
BOOL __stdcall ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped)
{
  return ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BC0; symbol: _QueryPerformanceFrequency@4
BOOL __stdcall QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency)
{
  return QueryPerformanceFrequency(lpFrequency);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BC8; symbol: _QueryPerformanceCounter@4
BOOL __stdcall QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount)
{
  return QueryPerformanceCounter(lpPerformanceCount);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BD0; symbol: _MultiByteToWideChar@24
int __stdcall MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cchMultiByte, LPWSTR lpWideCharStr, int cchWideChar)
{
  return MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cchMultiByte, lpWideCharStr, cchWideChar);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BE0; symbol: _LeaveCriticalSection@4
void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BE8; symbol: _InitializeCriticalSection@4
void __stdcall InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  InitializeCriticalSection(lpCriticalSection);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425BF8; symbol: _GetTickCount@0
DWORD __stdcall GetTickCount()
{
  return GetTickCount();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C00; symbol: _GetTempPathA@8
DWORD __stdcall GetTempPathA(DWORD nBufferLength, LPSTR lpBuffer)
{
  return GetTempPathA(nBufferLength, lpBuffer);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C08; symbol: _GetStartupInfoA@4
void __stdcall GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo)
{
  GetStartupInfoA(lpStartupInfo);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C10; symbol: _GetProcAddress@8
FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
  return GetProcAddress(hModule, lpProcName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C18; symbol: _GetModuleHandleA@4
HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName)
{
  return GetModuleHandleA(lpModuleName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C20; symbol: _GetLastError@0
DWORD __stdcall GetLastError()
{
  return GetLastError();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C28; symbol: _GetFileAttributesA@4
DWORD __stdcall GetFileAttributesA(LPCSTR lpFileName)
{
  return GetFileAttributesA(lpFileName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C30; symbol: _GetCommandLineA@0
LPSTR __stdcall GetCommandLineA()
{
  return GetCommandLineA();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C38; symbol: _FreeLibrary@4
BOOL __stdcall FreeLibrary(HMODULE hLibModule)
{
  return FreeLibrary(hLibModule);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C40; symbol: _FindNextFileA@8
BOOL __stdcall FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData)
{
  return FindNextFileA(hFindFile, lpFindFileData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C48; symbol: _FindFirstFileA@8
HANDLE __stdcall FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData)
{
  return FindFirstFileA(lpFileName, lpFindFileData);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C50; symbol: _FindClose@4
BOOL __stdcall FindClose(HANDLE hFindFile)
{
  return FindClose(hFindFile);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C58; symbol: _ExitThread@4
void __stdcall __noreturn ExitThread(DWORD dwExitCode)
{
  ExitThread(dwExitCode);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C60; symbol: _ExitProcess@4
void __stdcall __noreturn ExitProcess(UINT uExitCode)
{
  ExitProcess(uExitCode);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C68; symbol: _EnterCriticalSection@4
void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C70; symbol: _DeleteFileA@4
BOOL __stdcall DeleteFileA(LPCSTR lpFileName)
{
  return DeleteFileA(lpFileName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C78; symbol: _DeleteCriticalSection@4
void __stdcall DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C80; symbol: _CreateThread@24
HANDLE __stdcall CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, DWORD dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId)
{
  return CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C88; symbol: _CreateMutexA@12
HANDLE __stdcall CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
  return CreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C90; symbol: _CreateFileA@28
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425C98; symbol: _CreateDirectoryA@8
BOOL __stdcall CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
  return CreateDirectoryA(lpPathName, lpSecurityAttributes);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425CA0; symbol: _CloseHandle@4
BOOL __stdcall CloseHandle(HANDLE hObject)
{
  return CloseHandle(hObject);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425CA8; symbol: _stricoll
int __cdecl stricoll(int a1, int a2)
{
  return _stricoll(a1, a2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425CB0; symbol: _strdup
char *__cdecl strdup(const char *a1)
{
  return _strdup(a1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00426220; symbol: _main_0
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


