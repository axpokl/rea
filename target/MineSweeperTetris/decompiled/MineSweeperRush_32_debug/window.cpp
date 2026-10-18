// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00401300; symbol: _WinMainCRTStartup
void __noreturn WinMainCRTStartup()
{
  ___set_app_type(2);
  sub_4011B0();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00405B2A; symbol: __Z7WndProcP6HWND__jjl@16
LRESULT __stdcall WndProc(HWND hW, UINT uM, WPARAM wP, LPARAM lP)
{
  bool v4; // al
  bool v5; // al
  HICON__ *v6; // eax

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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040C2E4; symbol: __ZN6WindowC1Ev
void __cdecl Window::Window(Window *const this)
{
  Window *v1; // ecx
  Window *v2; // ST1C_4
  Board *const v3; // ST00_4
  Block *const v4; // ST00_4
  Window *const v5; // ST00_4
  Reg *v6; // [esp+0h] [ebp-28h]

  v2 = v1;
  v1->launchw = 320;
  v1->launchh = 368;
  v1->titlew = 256;
  v1->titleh = 256;
  v1->menuw = 24;
  v1->menuh = 24;
  v1->facew = 24;
  v1->faceh = 24;
  v1->iconw = 16;
  v1->iconh = 16;
  v1->digtw[0] = 13;
  v1->digtw[1] = 9;
  v1->digtw[2] = 13;
  v1->digth[0] = 24;
  v1->digth[1] = 17;
  v1->digth[2] = 24;
  v1->okw = 144;
  v1->okh = 36;
  v1->btnw = 36;
  v1->btnh = 36;
  v1->tutw = 120;
  v1->tuth = 36;
  v1->aboutw = 360;
  v1->abouth = 240;
  v1->helpw = 640;
  v1->helph = 480;
  v1->fontth = 64;
  v1->fontfh = 32;
  v1->fonth = 24;
  v1->fontsh = 17;
  v1->fontmh = 13;
  v2->okh_ = v1->abouth - (v2->fontth + 4 * v2->fonth);
  v1->cursorw = 12;
  v1->cursorh = 19;
  v1->clickw = 48;
  v1->clickh = 72;
  v1->arroww = 24;
  v1->arrowh = 24;
  v1->ptitle_ = 0;
  v1->pbg_ = 0;
  v1->pmenu_ = 0;
  v1->pmenu1[0] = 0;
  v1->pmenu1[1] = 0;
  v1->pmenu2[0] = 0;
  v1->pmenu2[1] = 0;
  v1->pmenu3[0] = 0;
  v1->pmenu3[1] = 0;
  v1->pmenuq[0] = 0;
  v1->pmenuq[1] = 0;
  v1->pmenua[0] = 0;
  v1->pmenua[1] = 0;
  v1->pmenus[0] = 0;
  v1->pmenus[1] = 0;
  v1->pmenum[0] = 0;
  v1->pmenum[1] = 0;
  v1->pmenut[0] = 0;
  v1->pmenut[1] = 0;
  v1->pmenud[0] = 0;
  v1->pmenud[1] = 0;
  v1->pmenun[0] = 0;
  v1->pmenun[1] = 0;
  memset(v1->pmenug, 0, sizeof(v1->pmenug));
  v1->pface_ = 0;
  memset(v1->pface, 0, sizeof(v1->pface));
  v1->picon_ = 0;
  memset(v1->picon, 0, sizeof(v1->picon));
  v1->piconc = 0;
  v1->piconq = 0;
  v1->piconf = 0;
  v1->piconm = 0;
  v1->picone = 0;
  v1->piconn = 0;
  v1->piconp = 0;
  v1->picona = 0;
  v1->piconu = 0;
  v1->pdigt_[0] = 0;
  v1->pdigt_[1] = 0;
  v1->pdigt_[2] = 0;
  memset(v1->pdigt, 0, sizeof(v1->pdigt));
  v1->pdigtmin[0] = 0;
  v1->pdigtmin[1] = 0;
  v1->pdigtmin[2] = 0;
  v1->pdigtnul[0] = 0;
  v1->pdigtnul[1] = 0;
  v1->pdigtnul[2] = 0;
  v1->pok_ = 0;
  v1->pok = 0;
  v1->pbtn = 0;
  v1->pcursor_ = 0;
  v1->pcursor = 0;
  v1->pclick_ = 0;
  v1->pclickl = 0;
  v1->pclickr = 0;
  v1->pclickn = 0;
  v1->pclicka = 0;
  v1->parrow_ = 0;
  v1->parrowl = 0;
  v1->parrowr = 0;
  v1->parrowu = 0;
  v1->parrowd = 0;
  v1->parrowm = 0;
  v1->parrowp = 0;
  v1->transparent = 1;
  v1->color[0] = 12632256;
  v1->color[1] = 11513775;
  v1->color[2] = 65793;
  v1->color[3] = 12632256;
  v1->color[4] = 255;
  v1->color[5] = 16711680;
  v1->color[6] = 0x8000;
  v1->color[7] = 8421504;
  v1->color[8] = 12632256;
  v1->colori = 0;
  v1->transparent_ = 11513775;
  v1->isbmp = 0;
  Reg::Reg(v6);
  Board::Board(v3);
  Block::Block(v4);
  v2->maxhelp = 6;
  v2->helpi = 0;
  v2->helpb = 1;
  v2->cheatb = 0;
  v2->waitb = 0;
  v2->pwin = 0;
  v2->pwint = 0;
  v2->minh = 600;
  v2->minw = 800;
  v2->mult_ = 0;
  v2->mult = 1.0;
  v2->showmax = 0;
  v2->showmax_ = 0;
  v2->w_ = 0;
  v2->h_ = 0;
  v2->x_ = 0;
  v2->y_ = 0;
  v2->xscr = 0;
  v2->yscr = 0;
  v2->wscr = 0;
  v2->hscr = 0;
  v2->barb = 1;
  v2->md = 0;
  v2->ml = 0;
  v2->mr = 0;
  v2->mx = -1;
  v2->my = -1;
  v2->mi = 0;
  v2->lead_5 = 0;
  v2->singleb = 0;
  v2->boardb = 0;
  v2->timerefresh = 0.0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&v2->cs);
  Window::initwindow(v5);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040CA6C; symbol: __ZN6WindowD1Ev
void __cdecl Window::~Window(Window *const this)
{
  Window *v1; // ecx
  Window *v2; // ST1C_4
  Board *const v3; // ST00_4
  Reg *const v4; // ST00_4
  Window *v5; // [esp+0h] [ebp-28h]

  v2 = v1;
  Window::releasewindow(v5);
  DeleteCriticalSection((LPCRITICAL_SECTION)&v2->cs);
  Board::~Board(v3);
  Reg::~Reg(v4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040CAB4; symbol: __ZN6Window16loadsettingcloudEv
void __cdecl Window::loadsettingcloud(Window *const this)
{
  Window *v1; // ecx
  ISteamRemoteStorage *v2; // eax
  ISteamRemoteStorage *v3; // eax
  ISteamRemoteStorage *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  Window *thisa; // [esp+1Ch] [ebp-3Ch]
  int buf[9]; // [esp+28h] [ebp-30h]
  int pos; // [esp+4Ch] [ebp-Ch]

  thisa = v1;
  if ( SteamRemoteStorage() != 0 )
  {
    v2 = SteamRemoteStorage();
    if ( !((*(unsigned __int8 (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v2 + 52))(
             v2,
             *(_DWORD *)(*(_DWORD *)v2 + 52)) ^ 1) )
    {
      memset(buf, 0, sizeof(buf));
      v3 = SteamRemoteStorage();
      if ( (*(int (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v3 + 60))(
             v3,
             *(_DWORD *)(*(_DWORD *)v3 + 60)) == 36 )
      {
        v4 = SteamRemoteStorage();
        (*(void (__fastcall **)(ISteamRemoteStorage *, int *, const char *, int *))(*(_DWORD *)v4 + 4))(
          v4,
          buf,
          "reg.dat",
          buf);
        pos = 1;
        thisa->helpb = buf[0] != 0;
        v5 = pos++;
        thisa->colori = buf[v5];
        v6 = pos++;
        thisa->md = buf[v6];
        v7 = pos++;
        thisa->bd.sd.soundb = buf[v7] != 0;
        v8 = pos++;
        thisa->bd.sd.musicb = buf[v8] != 0;
        v9 = pos++;
        thisa->mult_ = buf[v9];
        v10 = pos++;
        thisa->bd.delayb = buf[v10];
        v11 = pos++;
        thisa->barb = buf[v11] != 0;
        v12 = pos++;
        thisa->singleb = buf[v12] != 0;
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040CC4E; symbol: __ZN6Window16savesettingcloudEv
void __cdecl Window::savesettingcloud(Window *const this)
{
  Window *v1; // ecx
  ISteamRemoteStorage *v2; // eax
  Window *thisa; // [esp+1Ch] [ebp-3Ch]
  int buf[9]; // [esp+28h] [ebp-30h]
  int pos; // [esp+4Ch] [ebp-Ch]

  thisa = v1;
  if ( SteamRemoteStorage() != 0 )
  {
    pos = 1;
    buf[0] = thisa->helpb;
    pos = 2;
    buf[1] = thisa->colori;
    pos = 3;
    buf[2] = thisa->md;
    pos = 4;
    buf[3] = thisa->bd.sd.soundb;
    pos = 5;
    buf[4] = thisa->bd.sd.musicb;
    pos = 6;
    buf[5] = thisa->mult_;
    pos = 7;
    buf[6] = thisa->bd.delayb;
    pos = 8;
    buf[7] = thisa->barb;
    pos = 9;
    buf[8] = thisa->singleb;
    v2 = SteamRemoteStorage();
    (**(void (__fastcall ***)(ISteamRemoteStorage *, int *, const char *, int *))v2)(v2, buf, "reg.dat", buf);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040CD7A; symbol: __ZN6Window11loadsettingEv
void __cdecl Window::loadsetting(Window *const this)
{
  int v1; // ecx
  Window *v2; // ST1C_4
  int *v3; // ST0C_4
  int *v4; // ST0C_4
  int *v5; // ST0C_4
  int *v6; // ST0C_4
  int *v7; // ST0C_4
  int *v8; // ST0C_4
  int *v9; // ST0C_4
  int *v10; // ST0C_4
  Window *const v11; // ST00_4
  int *v12; // [esp+Ch] [ebp-1Ch]

  v2 = (Window *)v1;
  Reg::getreg(v1 + 736, *(Reg *const *)(v1 + 736), &key, (const char *)(v1 + 3380), v12);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_428FF2, (const char *)&v2->colori, v3);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &unk_428FF9, (const char *)&v2->md, v4);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_428FFC, (const char *)&v2->bd.sd.soundb, v5);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_429003, (const char *)&v2->bd.sd.musicb, v6);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_42900A, (const char *)&v2->mult_, v7);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_42900F, (const char *)&v2->bd.delayb, v8);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_429016, (const char *)&v2->barb, v9);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey, &stru_42901B, (const char *)&v2->singleb, v10);
  Window::loadsettingcloud(v11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040CF64; symbol: __ZN6Window11savesettingEv
void __cdecl Window::savesetting(Window *const this)
{
  int v1; // ecx
  Window *v2; // ST1C_4
  int v3; // ST0C_4
  int v4; // ST0C_4
  int v5; // ST0C_4
  int v6; // ST0C_4
  int v7; // ST0C_4
  int v8; // ST0C_4
  int v9; // ST0C_4
  int v10; // ST0C_4
  Window *const v11; // ST00_4
  int v12; // [esp+Ch] [ebp-1Ch]

  v2 = (Window *)v1;
  Reg::setreg(*(Reg *const *)(v1 + 736), &key, (const char *)*(unsigned __int8 *)(v1 + 3380), v12);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_428FF2, (const char *)v2->colori, v3);
  Reg::setreg((Reg *const )v2->reg.regkey, &unk_428FF9, (const char *)v2->md, v4);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_428FFC, (const char *)v2->bd.sd.soundb, v5);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_429003, (const char *)v2->bd.sd.musicb, v6);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_42900A, (const char *)v2->mult_, v7);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_42900F, (const char *)v2->bd.delayb, v8);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_429016, (const char *)v2->barb, v9);
  Reg::setreg((Reg *const )v2->reg.regkey, &stru_42901B, (const char *)v2->singleb, v10);
  Window::savesettingcloud(v11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040D150; symbol: __ZN6Window14loadboardcloudEv
void __cdecl Window::loadboardcloud(Window *const this)
{
  int v1; // eax
  int v2; // ecx
  void *v3; // esp
  ISteamRemoteStorage *v4; // eax
  ISteamRemoteStorage *v5; // eax
  ISteamRemoteStorage *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  Block *const v30; // ST00_4
  int v31; // [esp+1Ch] [ebp-1407Ch]
  int v32[25]; // [esp+28h] [ebp-14070h]
  char v33; // [esp+8Ch] [ebp-1400Ch]
  char v34; // [esp+408Ch] [ebp-1000Ch]
  char v35; // [esp+808Ch] [ebp-C00Ch]
  char v36; // [esp+C08Ch] [ebp-800Ch]
  char v37; // [esp+1008Ch] [ebp-400Ch]
  int v38; // [esp+1408Ch] [ebp-Ch]

  v3 = alloca(v1);
  v31 = v2;
  if ( SteamRemoteStorage() != 0 )
  {
    v4 = SteamRemoteStorage();
    if ( !((*(unsigned __int8 (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v4 + 52))(
             v4,
             *(_DWORD *)(*(_DWORD *)v4 + 52)) ^ 1) )
    {
      v5 = SteamRemoteStorage();
      if ( (*(int (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v5 + 60))(
             v5,
             *(_DWORD *)(*(_DWORD *)v5 + 60)) == 82020 )
      {
        v6 = SteamRemoteStorage();
        (*(void (__fastcall **)(ISteamRemoteStorage *, int *, const char *, int *))(*(_DWORD *)v6 + 4))(
          v6,
          v32,
          "board.dat",
          v32);
        v38 = 1;
        *(_DWORD *)(v31 + 2896) = v32[0];
        v7 = v38++;
        *(_DWORD *)(v31 + 768) = v32[v7];
        v8 = v38++;
        *(_DWORD *)(v31 + 772) = v32[v8];
        v9 = v38++;
        *(_DWORD *)(v31 + 776) = v32[v9];
        v10 = v38++;
        *(_DWORD *)(v31 + 2916) = v32[v10];
        v11 = v38++;
        *(_DWORD *)(v31 + 780) = v32[v11];
        v12 = v38++;
        *(_DWORD *)(v31 + 2924) = v32[v12];
        v13 = v38++;
        *(_DWORD *)(v31 + 2928) = v32[v13];
        v14 = v38++;
        *(_DWORD *)(v31 + 2956) = v32[v14];
        v15 = v38++;
        *(_DWORD *)(v31 + 2960) = v32[v15];
        v16 = v38++;
        *(_DWORD *)(v31 + 2964) = v32[v16];
        v17 = v38++;
        *(_DWORD *)(v31 + 2972) = v32[v17];
        v18 = v38++;
        *(_DWORD *)(v31 + 788) = v32[v18];
        v19 = v38++;
        *(_DWORD *)(v31 + 792) = v32[v19];
        v20 = v38++;
        *(_DWORD *)(v31 + 2908) = v32[v20];
        v21 = v38++;
        *(_DWORD *)(v31 + 3044) = v32[v21];
        v22 = v38++;
        *(_DWORD *)(v31 + 3040) = v32[v22];
        v23 = v38++;
        *(_DWORD *)(v31 + 2940) = v32[v23];
        v24 = v38++;
        *(_DWORD *)(v31 + 784) = v32[v24];
        v25 = v38++;
        *(_DWORD *)(v31 + 3032) = v32[v25];
        v26 = v38++;
        *(_DWORD *)(v31 + 3036) = v32[v26];
        v27 = v38++;
        *(_DWORD *)(v31 + 2968) = v32[v27];
        v28 = v38++;
        *(_DWORD *)(v31 + 3024) = v32[v28];
        v29 = v38++;
        *(_DWORD *)(v31 + 3300) = v32[v29];
        memcpy(*(void **)(v31 + 804), &v33, 0x4000u);
        memcpy(*(void **)(v31 + 808), &v34, 0x4000u);
        memcpy(*(void **)(v31 + 812), &v35, 0x4000u);
        memcpy(*(void **)(v31 + 816), &v36, 0x4000u);
        memcpy(*(void **)(v31 + 820), &v37, 0x4000u);
        Block::calcnumb(v30);
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040D588; symbol: __ZN6Window14saveboardcloudEv
void __cdecl Window::saveboardcloud(Window *const this)
{
  int v1; // eax
  int v2; // ecx
  void *v3; // esp
  ISteamRemoteStorage *v4; // eax
  int v5; // [esp+1Ch] [ebp-1407Ch]
  int v6; // [esp+28h] [ebp-14070h]
  int v7; // [esp+2Ch] [ebp-1406Ch]
  int v8; // [esp+30h] [ebp-14068h]
  int v9; // [esp+34h] [ebp-14064h]
  int v10; // [esp+38h] [ebp-14060h]
  int v11; // [esp+3Ch] [ebp-1405Ch]
  int v12; // [esp+40h] [ebp-14058h]
  int v13; // [esp+44h] [ebp-14054h]
  int v14; // [esp+48h] [ebp-14050h]
  int v15; // [esp+4Ch] [ebp-1404Ch]
  int v16; // [esp+50h] [ebp-14048h]
  int v17; // [esp+54h] [ebp-14044h]
  int v18; // [esp+58h] [ebp-14040h]
  int v19; // [esp+5Ch] [ebp-1403Ch]
  int v20; // [esp+60h] [ebp-14038h]
  int v21; // [esp+64h] [ebp-14034h]
  int v22; // [esp+68h] [ebp-14030h]
  int v23; // [esp+6Ch] [ebp-1402Ch]
  int v24; // [esp+70h] [ebp-14028h]
  int v25; // [esp+74h] [ebp-14024h]
  int v26; // [esp+78h] [ebp-14020h]
  int v27; // [esp+7Ch] [ebp-1401Ch]
  int v28; // [esp+80h] [ebp-14018h]
  int v29; // [esp+84h] [ebp-14014h]
  char v30; // [esp+8Ch] [ebp-1400Ch]
  char v31; // [esp+408Ch] [ebp-1000Ch]
  char v32; // [esp+808Ch] [ebp-C00Ch]
  char v33; // [esp+C08Ch] [ebp-800Ch]
  char v34; // [esp+1008Ch] [ebp-400Ch]
  int v35; // [esp+1408Ch] [ebp-Ch]

  v3 = alloca(v1);
  v5 = v2;
  if ( SteamRemoteStorage() != 0 )
  {
    v35 = 1;
    v6 = *(_DWORD *)(v5 + 2896);
    v35 = 2;
    v7 = *(_DWORD *)(v5 + 768);
    v35 = 3;
    v8 = *(_DWORD *)(v5 + 772);
    v35 = 4;
    v9 = *(_DWORD *)(v5 + 776);
    v35 = 5;
    v10 = *(_DWORD *)(v5 + 2916);
    v35 = 6;
    v11 = *(_DWORD *)(v5 + 780);
    v35 = 7;
    v12 = *(_DWORD *)(v5 + 2924);
    v35 = 8;
    v13 = *(_DWORD *)(v5 + 2928);
    v35 = 9;
    v14 = *(_DWORD *)(v5 + 2956);
    v35 = 10;
    v15 = *(_DWORD *)(v5 + 2960);
    v35 = 11;
    v16 = *(_DWORD *)(v5 + 2964);
    v35 = 12;
    v17 = *(_DWORD *)(v5 + 2972);
    v35 = 13;
    v18 = *(_DWORD *)(v5 + 788);
    v35 = 14;
    v19 = *(_DWORD *)(v5 + 792);
    v35 = 15;
    v20 = *(_DWORD *)(v5 + 2908);
    v35 = 16;
    v21 = *(_DWORD *)(v5 + 3044);
    v35 = 17;
    v22 = *(_DWORD *)(v5 + 3040);
    v35 = 18;
    v23 = *(_DWORD *)(v5 + 2940);
    v35 = 19;
    v24 = *(_DWORD *)(v5 + 784);
    v35 = 20;
    v25 = *(_DWORD *)(v5 + 3032);
    v35 = 21;
    v26 = *(_DWORD *)(v5 + 3036);
    v35 = 22;
    v27 = *(_DWORD *)(v5 + 2968);
    v35 = 23;
    v28 = *(_DWORD *)(v5 + 3024);
    v35 = 24;
    v29 = *(_DWORD *)(v5 + 3300);
    memcpy(&v30, *(const void **)(v5 + 804), 0x4000u);
    memcpy(&v31, *(const void **)(v5 + 808), 0x4000u);
    memcpy(&v32, *(const void **)(v5 + 812), 0x4000u);
    memcpy(&v33, *(const void **)(v5 + 816), 0x4000u);
    memcpy(&v34, *(const void **)(v5 + 820), 0x4000u);
    v4 = SteamRemoteStorage();
    (**(void (__fastcall ***)(ISteamRemoteStorage *, int *, const char *, int *))v4)(v4, &v6, "board.dat", &v6);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040D94C; symbol: __ZN6Window9loadboardEv
void __cdecl Window::loadboard(Window *const this)
{
  int v1; // ecx
  Window *v2; // ST1C_4
  int *v3; // ST0C_4
  int *v4; // ST0C_4
  int *v5; // ST0C_4
  int *v6; // ST0C_4
  int *v7; // ST0C_4
  int *v8; // ST0C_4
  int *v9; // ST0C_4
  int *v10; // ST0C_4
  int *v11; // ST0C_4
  int *v12; // ST0C_4
  int *v13; // ST0C_4
  int *v14; // ST0C_4
  int *v15; // ST0C_4
  int *v16; // ST0C_4
  int *v17; // ST0C_4
  int *v18; // ST0C_4
  int *v19; // ST0C_4
  int *v20; // ST0C_4
  int *v21; // ST0C_4
  int *v22; // ST0C_4
  int *v23; // ST0C_4
  int *v24; // ST0C_4
  int *v25; // ST0C_4
  char *v26; // ST0C_4
  char *v27; // ST0C_4
  char *v28; // ST0C_4
  char *v29; // ST0C_4
  char *v30; // ST0C_4
  Window *const v31; // ST00_4
  Block *const v32; // ST00_4
  int *v33; // [esp+Ch] [ebp-1Ch]

  v2 = (Window *)v1;
  Reg::getreg(v1 + 736, *(Reg *const *)(v1 + 740), &stru_42902D, (const char *)(v1 + 2896), v33);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &unk_429032, (const char *)&v2->bd, v3);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &unk_429034, (const char *)&v2->bd.h, v4);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &unk_429036, (const char *)&v2->bd.n, v5);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429038, (const char *)&v2->bd.maskj0, v6);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42903F, (const char *)&v2->bd.sit, v7);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429043, (const char *)&v2->bd.line, v8);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429048, (const char *)&v2->bd.level, v9);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42904E, (const char *)&v2->bd.tetrisi, v10);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429056, (const char *)&v2->bd.missi, v11);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42905C, (const char *)&v2->bd.missline, v12);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429065, (const char *)&v2->bd.sum, v13);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429069, (const char *)&v2->bd.maskj, v14);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42906F, (const char *)&v2->bd.maski, v15);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429075, (const char *)&v2->bd.rightb, v16);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42907C, (const char *)&v2->bd.tuti, v17);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429081, (const char *)&v2->bd.tutb, v18);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_429086, (const char *)&v2->bd.checkr, v19);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42908D, (const char *)&v2->bd.pauseb, v20);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &unk_429094, (const char *)&v2->bd.mx, v21);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &unk_429097, (const char *)&v2->bd.my, v22);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_42909A, (const char *)&v2->bd.bouns, v23);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_4290A0, (const char *)&v2->bd.mdb, v24);
  Reg::getreg((int)&v2->reg, (Reg *const )v2->reg.regkey_, &stru_4290A4, (const char *)&v2->bd.solven, v25);
  Reg::getreg_(
    (int)v2->reg.regkey_,
    (int)&v2->reg,
    (Reg *const )v2->reg.regkey_,
    &stru_4290AB,
    (const char *)v2->bd.flag,
    v26);
  Reg::getreg_(
    (int)v2->reg.regkey_,
    (int)&v2->reg,
    (Reg *const )v2->reg.regkey_,
    &stru_4290B0,
    (const char *)v2->bd.qstn,
    v27);
  Reg::getreg_(
    (int)v2->reg.regkey_,
    (int)&v2->reg,
    (Reg *const )v2->reg.regkey_,
    &stru_4290B5,
    (const char *)v2->bd.mine,
    v28);
  Reg::getreg_(
    (int)v2->reg.regkey_,
    (int)&v2->reg,
    (Reg *const )v2->reg.regkey_,
    &stru_4290BA,
    (const char *)v2->bd.blck,
    v29);
  Reg::getreg_(
    (int)v2->reg.regkey_,
    (int)&v2->reg,
    (Reg *const )v2->reg.regkey_,
    &stru_4290BF,
    (const char *)v2->bd.mask,
    v30);
  Window::loadboardcloud(v31);
  Block::calcnumb(v32);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040DF60; symbol: __ZN6Window9saveboardEv
void __cdecl Window::saveboard(Window *const this)
{
  int v1; // ecx
  Window *v2; // ST1C_4
  int v3; // ST0C_4
  int v4; // ST0C_4
  int v5; // ST0C_4
  int v6; // ST0C_4
  int v7; // ST0C_4
  int v8; // ST0C_4
  int v9; // ST0C_4
  int v10; // ST0C_4
  int v11; // ST0C_4
  int v12; // ST0C_4
  int v13; // ST0C_4
  int v14; // ST0C_4
  int v15; // ST0C_4
  int v16; // ST0C_4
  int v17; // ST0C_4
  int v18; // ST0C_4
  int v19; // ST0C_4
  int v20; // ST0C_4
  int v21; // ST0C_4
  int v22; // ST0C_4
  int v23; // ST0C_4
  int v24; // ST0C_4
  int v25; // ST0C_4
  char *v26; // ST0C_4
  char *v27; // ST0C_4
  char *v28; // ST0C_4
  char *v29; // ST0C_4
  char *v30; // ST0C_4
  Window *const v31; // ST00_4
  int v32; // [esp+Ch] [ebp-1Ch]

  v2 = (Window *)v1;
  Reg::setreg(*(Reg *const *)(v1 + 740), &stru_42902D, *(const char **)(v1 + 2896), v32);
  Reg::setreg((Reg *const )v2->reg.regkey_, &unk_429032, (const char *)v2->bd.w, v3);
  Reg::setreg((Reg *const )v2->reg.regkey_, &unk_429034, (const char *)v2->bd.h, v4);
  Reg::setreg((Reg *const )v2->reg.regkey_, &unk_429036, (const char *)v2->bd.n, v5);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429038, (const char *)v2->bd.maskj0, v6);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42903F, (const char *)v2->bd.sit, v7);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429043, (const char *)v2->bd.line, v8);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429048, (const char *)v2->bd.level, v9);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42904E, (const char *)v2->bd.tetrisi, v10);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429056, (const char *)v2->bd.missi, v11);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42905C, (const char *)v2->bd.missline, v12);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429065, (const char *)v2->bd.sum, v13);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429069, (const char *)v2->bd.maskj, v14);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42906F, (const char *)v2->bd.maski, v15);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429075, (const char *)v2->bd.rightb, v16);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42907C, (const char *)v2->bd.tuti, v17);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429081, (const char *)v2->bd.tutb, v18);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_429086, (const char *)v2->bd.checkr, v19);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42908D, (const char *)v2->bd.pauseb, v20);
  Reg::setreg((Reg *const )v2->reg.regkey_, &unk_429094, (const char *)v2->bd.mx, v21);
  Reg::setreg((Reg *const )v2->reg.regkey_, &unk_429097, (const char *)v2->bd.my, v22);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_42909A, (const char *)v2->bd.bouns, v23);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_4290A0, (const char *)v2->bd.mdb, v24);
  Reg::setreg((Reg *const )v2->reg.regkey_, &stru_4290A4, (const char *)v2->bd.solven, v25);
  Reg::setreg_((Reg *const )v2->reg.regkey_, &stru_4290AB, (const char *)v2->bd.flag, v26);
  Reg::setreg_((Reg *const )v2->reg.regkey_, &stru_4290B0, (const char *)v2->bd.qstn, v27);
  Reg::setreg_((Reg *const )v2->reg.regkey_, &stru_4290B5, (const char *)v2->bd.mine, v28);
  Reg::setreg_((Reg *const )v2->reg.regkey_, &stru_4290BA, (const char *)v2->bd.blck, v29);
  Reg::setreg_((Reg *const )v2->reg.regkey_, &stru_4290BF, (const char *)v2->bd.mask, v30);
  Window::saveboardcloud(v31);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040E534; symbol: __ZN6Window12loadallpaintEv
void __cdecl Window::loadallpaint(Window *const this)
{
  int v1; // [esp+4h] [ebp-24h]

  while ( painttitleb > 0 )
  {
    if ( painttitleb == 2 )
    {
      painttitleb = 1;
      Window::painttitle(painttitlec, v1);
    }
    Sleep(1u);
  }
  painttitles = 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040E58E; symbol: __ZN6Window7loadallEv
void __cdecl Window::loadall(Window *const this)
{
  Window *v1; // ecx
  HWND__ *v2; // eax
  int v3; // ST04_4
  Window *v4; // [esp+0h] [ebp-38h]
  Steam *v5; // [esp+0h] [ebp-38h]
  Sound *v6; // [esp+0h] [ebp-38h]
  Window *v7; // [esp+0h] [ebp-38h]
  Window *v8; // [esp+0h] [ebp-38h]
  int v9; // [esp+4h] [ebp-34h]
  int v10; // [esp+4h] [ebp-34h]
  int v11; // [esp+4h] [ebp-34h]
  int v12; // [esp+4h] [ebp-34h]
  int v13; // [esp+4h] [ebp-34h]
  int v14; // [esp+8h] [ebp-30h]
  int *v15; // [esp+Ch] [ebp-2Ch]
  int v16; // [esp+Ch] [ebp-2Ch]
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  painttitleb = 1;
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)loadallpaintstatic, v1, 0, 0);
  if ( (unsigned __int8)IsWin() )
    Window::loadsetting(v4);
  Window::painttitle((Window *const )thisa->bd.st.lan.LAN_LOAD_STEAM, v9);
  if ( (unsigned __int8)IsWin() )
    Steam::loadsteam(v5);
  Window::painttitle((Window *const )thisa->bd.st.lan.LAN_LOAD_AUDIO, v10);
  if ( (unsigned __int8)IsWin() )
    Sound::initsound(v6);
  Window::painttitle((Window *const )thisa->bd.st.lan.LAN_LOAD_BOARD, v11);
  if ( (unsigned __int8)IsWin() )
  {
    Board::initbd((int)&thisa->bd, (Board *const )1, thisa->md, v14);
    Reg::getreg((int)&thisa->reg, (Reg *const )thisa->reg.regkey, &stru_4290C4, (const char *)&thisa->boardb, v15);
    thisa->bd.tutb = thisa->helpb;
    if ( thisa->boardb == 1 )
    {
      Window::loadboard(v7);
      thisa->boardb = 0;
      Reg::setreg((Reg *const )thisa->reg.regkey, &stru_4290C4, (const char *)thisa->boardb, v16);
    }
  }
  Window::painttitle((Window *const )thisa->bd.st.lan.LAN_LOAD_GRAPH, v12);
  if ( (unsigned __int8)IsWin() )
    Window::initbmp(v8);
  Window::painttitle((Window *const )thisa->bd.st.lan.LAN_LOAD_WINDOW, v13);
  if ( (unsigned __int8)IsWin() )
  {
    v2 = GetHwnd();
    SetWindowLongA(v2, -16, 281739264);
    Window::sethelp(0, v3);
  }
  painttitleb = 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040E7CA; symbol: __ZN6Window8initmultEv
void __cdecl Window::initmult(Window *const this)
{
  Window *v1; // ecx
  int v2; // ebx
  long double v3; // fst7
  int v4; // ebx
  int v5; // ebx
  long double v6; // fst7
  int v7; // ebx
  long double v8; // fst7
  long double v9; // fst7
  int v10; // ebx
  int v11; // ebx
  long double v12; // fst7
  long double v13; // fst7
  int v14; // ebx
  long double v15; // fst7
  int v16; // ebx
  int v17; // ebx
  long double v18; // fst7
  int v19; // ebx
  long double v20; // fst7
  int v21; // ebx
  int v22; // ebx
  long double v23; // fst7
  int v24; // ebx
  double v25; // ST08_8
  int v26; // ebx
  int v27; // ebx
  int v28; // ebx
  long double v29; // fst7
  int v30; // ebx
  int v31; // ebx
  long double v32; // fst7
  int v33; // ebx
  double v34; // ST08_8
  int v35; // ebx
  int v36; // ebx
  int v37; // ebx
  int v38; // ebx
  int v39; // ebx
  signed int v40; // eax
  int v41; // ebx
  double v42; // ST08_8
  int v43; // ebx
  int v44; // ebx
  int v45; // ebx
  long double v46; // fst7
  int v47; // ebx
  int v48; // ebx
  long double v49; // fst7
  int v50; // ebx
  double v51; // ST08_8
  int v52; // ebx
  int v53; // ebx
  int v54; // ebx
  int v55; // ebx
  int v56; // ebx
  long double v57; // fst7
  signed int v58; // [esp+8h] [ebp-20h]
  double v59; // [esp+8h] [ebp-20h]
  signed int v60; // [esp+8h] [ebp-20h]
  signed int v61; // [esp+8h] [ebp-20h]
  signed int v62; // [esp+8h] [ebp-20h]
  double v63; // [esp+8h] [ebp-20h]
  signed int v64; // [esp+8h] [ebp-20h]
  signed int v65; // [esp+8h] [ebp-20h]
  signed int v66; // [esp+10h] [ebp-18h]
  signed int v67; // [esp+10h] [ebp-18h]
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->mult_ )
  {
    if ( v1->mult_ == 1 )
    {
      v24 = v1->wscr;
      v25 = (long double)(v24 - 2 * GetBorderWidth()) / (long double)v1->w_;
      v26 = thisa->hscr;
      v27 = v26 - 2 * GetBorderHeight();
      if ( (long double)(v27 - GetBorderTitle()) / (long double)thisa->h_ <= v25 )
      {
        v30 = thisa->hscr;
        v31 = v30 - 2 * GetBorderHeight();
        v29 = (long double)(v31 - GetBorderTitle()) / (long double)thisa->h_;
      }
      else
      {
        v28 = thisa->wscr;
        v29 = (long double)(v28 - 2 * GetBorderWidth()) / (long double)thisa->w_;
      }
      if ( v29 >= 1.0 )
      {
        v33 = thisa->wscr;
        v34 = (long double)(v33 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        v35 = thisa->hscr;
        v36 = v35 - 2 * GetBorderHeight();
        if ( (long double)(v36 - GetBorderTitle()) / (long double)thisa->h_ <= v34 )
        {
          v38 = thisa->hscr;
          v39 = v38 - 2 * GetBorderHeight();
          v32 = (long double)(v39 - GetBorderTitle()) / (long double)thisa->h_;
        }
        else
        {
          v37 = thisa->wscr;
          v32 = (long double)(v37 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        }
      }
      else
      {
        v32 = 1.0;
      }
      thisa->mult = v32;
    }
    else
    {
      if ( v1->mult_ > 7 )
      {
        v40 = 8;
      }
      else
      {
        v40 = v1->mult_;
        if ( v40 < 2 )
          v40 = 2;
      }
      v1->mult_ = v40;
      v41 = v1->wscr;
      v42 = (long double)(v41 - 2 * GetBorderWidth()) / (long double)v1->w_;
      v43 = thisa->hscr;
      v44 = v43 - 2 * GetBorderHeight();
      if ( (long double)(v44 - GetBorderTitle()) / (long double)thisa->h_ <= v42 )
      {
        v47 = thisa->hscr;
        v48 = v47 - 2 * GetBorderHeight();
        v46 = (long double)(v48 - GetBorderTitle()) / (long double)thisa->h_;
      }
      else
      {
        v45 = thisa->wscr;
        v46 = (long double)(v45 - 2 * GetBorderWidth()) / (long double)thisa->w_;
      }
      if ( v46 >= 1.0 )
      {
        v50 = thisa->wscr;
        v51 = (long double)(v50 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        v52 = thisa->hscr;
        v53 = v52 - 2 * GetBorderHeight();
        if ( (long double)(v53 - GetBorderTitle()) / (long double)thisa->h_ <= v51 )
        {
          v55 = thisa->hscr;
          v56 = v55 - 2 * GetBorderHeight();
          v49 = (long double)(v56 - GetBorderTitle()) / (long double)thisa->h_;
        }
        else
        {
          v54 = thisa->wscr;
          v49 = (long double)(v54 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        }
      }
      else
      {
        v49 = 1.0;
      }
      thisa->mult = v49;
      if ( (long double)thisa->mult_ / 2.0 <= thisa->mult )
        v57 = (long double)thisa->mult_ / 2.0;
      else
        v57 = thisa->mult;
      thisa->mult = v57;
    }
  }
  else
  {
    v2 = v1->wscr;
    v3 = (long double)(v2 - 2 * GetBorderWidth());
    if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
      v58 = thisa->w_;
    else
      v58 = thisa->minw;
    v59 = v3 / (long double)v58;
    v4 = thisa->hscr;
    v5 = v4 - 2 * GetBorderHeight();
    v6 = (long double)(v5 - GetBorderTitle());
    if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
      v66 = thisa->h_;
    else
      v66 = thisa->minh;
    if ( v6 / (long double)v66 <= v59 )
    {
      v10 = thisa->hscr;
      v11 = v10 - 2 * GetBorderHeight();
      v12 = (long double)(v11 - GetBorderTitle());
      if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
        v61 = thisa->h_;
      else
        v61 = thisa->minh;
      v9 = v12 / (long double)v61;
    }
    else
    {
      v7 = thisa->wscr;
      v8 = (long double)(v7 - 2 * GetBorderWidth());
      if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
        v60 = thisa->w_;
      else
        v60 = thisa->minw;
      v9 = v8 / (long double)v60;
    }
    if ( v9 >= 1.0 )
    {
      v14 = thisa->wscr;
      v15 = (long double)(v14 - 2 * GetBorderWidth());
      if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
        v62 = thisa->w_;
      else
        v62 = thisa->minw;
      v63 = v15 / (long double)v62;
      v16 = thisa->hscr;
      v17 = v16 - 2 * GetBorderHeight();
      v18 = (long double)(v17 - GetBorderTitle());
      if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
        v67 = thisa->h_;
      else
        v67 = thisa->minh;
      if ( v18 / (long double)v67 <= v63 )
      {
        v21 = thisa->hscr;
        v22 = v21 - 2 * GetBorderHeight();
        v23 = (long double)(v22 - GetBorderTitle());
        if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
          v65 = thisa->h_;
        else
          v65 = thisa->minh;
        v13 = v23 / (long double)v65;
      }
      else
      {
        v19 = thisa->wscr;
        v20 = (long double)(v19 - 2 * GetBorderWidth());
        if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
          v64 = thisa->w_;
        else
          v64 = thisa->minw;
        v13 = v20 / (long double)v64;
      }
    }
    else
    {
      v13 = 1.0;
    }
    thisa->mult = v13;
    thisa->mult = (long double)(signed int)(thisa->mult + thisa->mult) / 2.0;
  }
  thisa->bd.w_ = thisa->w_;
  thisa->bd.h_ = thisa->h_;
  thisa->bd.mult = thisa->mult;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040EFC4; symbol: __ZN6Window8loadiconEv
void __cdecl Window::loadicon(Window *const this)
{
  Window *v1; // ecx
  HICON__ *v2; // edx
  LPARAM v3; // ebx
  HWND__ *v4; // eax
  LPARAM v5; // ebx
  HWND__ *v6; // eax
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  v1->hicon_res = (HICON)LoadImageA(MainInstance, "MINESWEEPERRUSH_ICON", 1u, 0, 0, 0);
  thisa->hicon_file = (HICON)LoadImageA(0, "./data/MineSweeperRush.ico", 1u, 0, 0, 0x8050u);
  if ( thisa->hicon_res )
    v2 = thisa->hicon_res;
  else
    v2 = thisa->hicon_file;
  thisa->hicon = v2;
  v3 = (LPARAM)thisa->hicon;
  v4 = GetHwnd();
  SendMessageA(v4, 0x80u, 1u, v3);
  Delay(0xAu);
  v5 = (LPARAM)thisa->hicon;
  v6 = GetHwnd();
  SendMessageA(v6, 0x80u, 0, v5);
  Delay(0xAu);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040F102; symbol: __ZN6Window10initwindowEv
void __cdecl Window::initwindow(Window *const this)
{
  Window *v1; // ecx
  int *v2; // ST0C_4
  Window *const v3; // ST00_4
  double v4; // ST28_8
  long double v5; // fst7
  double v6; // ST28_8
  double v7; // ST28_8
  double v8; // ST28_8
  long double v9; // fst7
  double v10; // ST28_8
  double v11; // ST28_8
  Window *const v12; // ST00_4
  int v13; // ST04_4
  __int16 *v14; // eax
  const char *v15; // ST04_4
  int v16; // ST04_4
  int v17; // ebx
  int v18; // ebx
  int v19; // ebx
  Window *v20; // [esp+0h] [ebp-A8h]
  double v21; // [esp+30h] [ebp-78h]
  double v22; // [esp+30h] [ebp-78h]
  Window *thisa; // [esp+4Ch] [ebp-5Ch]
  LOGFONT lf; // [esp+54h] [ebp-54h]

  thisa = v1;
  Window::initcolor(v20);
  SystemParametersInfoA(0x30u, 0, &thisa->rect, 0);
  thisa->wscr = thisa->rect.right - thisa->rect.left;
  thisa->hscr = thisa->rect.bottom - thisa->rect.top;
  thisa->w_ = thisa->launchw;
  thisa->h_ = thisa->launchh;
  Reg::getreg((int)&thisa->reg, (Reg *const )thisa->reg.regkey, &stru_42900A, (const char *)&thisa->mult_, v2);
  Window::initmult(v3);
  v21 = (long double)thisa->rect.left;
  v4 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
  if ( (v4 - (long double)(2 * GetBorderWidth())) / 2.0 >= 0.0 )
  {
    v6 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
    v5 = (v6 - (long double)(2 * GetBorderWidth())) / 2.0;
  }
  else
  {
    v5 = 0.0;
  }
  thisa->x_ = (signed int)(v5 + v21);
  v22 = (long double)thisa->rect.top;
  v7 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
  v8 = v7 - (long double)(2 * GetBorderHeight());
  if ( (v8 - (long double)GetBorderTitle()) / 2.0 >= 0.0 )
  {
    v10 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
    v11 = v10 - (long double)(2 * GetBorderHeight());
    v9 = (v11 - (long double)GetBorderTitle()) / 2.0;
  }
  else
  {
    v9 = 0.0;
  }
  thisa->y_ = (signed int)(v9 + v22);
  CreateWin(
    thisa->x_,
    thisa->y_,
    (signed __int64)((long double)thisa->w_ * thisa->mult),
    (signed __int64)((long double)thisa->h_ * thisa->mult),
    thisa->cbg,
    thisa->cbg,
    0x10C80000u,
    "MineSweeperRushClass");
  thisa->pwin = CreateBMP(thisa->w_, thisa->h_);
  thisa->pwint = CreateBMP(
                   (signed __int64)((long double)thisa->w_ * thisa->mult),
                   (signed __int64)((long double)thisa->h_ * thisa->mult),
                   thisa->transparent_);
  Window::loadicon(v12);
  v14 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_TITLE, v13);
  SetTitleW(v14);
  SystemParametersInfoA(0x1Fu, 0x3Cu, &lf, 0);
  Window::setfontname_((Window *const )lf.lfFaceName, v15);
  Window::painttitle((Window *const )0xFFFFFFFF, v16);
  v17 = thisa->wscr;
  thisa->bd.maxbdw = (v17 - 2 * GetBorderWidth()) / 16 - 1;
  v18 = thisa->hscr - thisa->menuh - thisa->faceh;
  v19 = v18 - 2 * GetBorderHeight();
  thisa->bd.maxbdh = (v19 - GetBorderTitle()) / 16 - 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040F5F8; symbol: __ZN6Window13releasewindowEv
void __cdecl Window::releasewindow(Window *const this)
{
  Window *v1; // ecx
  Window *v2; // [esp+0h] [ebp-28h]
  Window *v3; // [esp+0h] [ebp-28h]
  int v4; // [esp+Ch] [ebp-1Ch]
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  Window::savesetting(v2);
  if ( thisa->cheatb != 1 && thisa->bd.relaxb != 1 && thisa->bd.sit > 0 && thisa->bd.sit <= 3 )
  {
    if ( !thisa->bd.tutb )
      thisa->bd.pauseb = 1;
    Window::saveboard(v3);
    thisa->boardb = 1;
    Reg::setreg((Reg *const )thisa->reg.regkey, &stru_4290C4, (const char *)thisa->boardb, v4);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040F6B2; symbol: __ZN6Window10initwindowEb
void __userpurge Window::initwindow(Window *a1@<ecx>, Window *const this, bool b)
{
  int v3; // eax
  double v4; // ST18_8
  long double v5; // fst7
  double v6; // ST18_8
  double v7; // ST18_8
  double v8; // ST18_8
  long double v9; // fst7
  double v10; // ST18_8
  double v11; // ST18_8
  bool v12; // ST04_1
  Board *v13; // [esp+0h] [ebp-58h]
  double v14; // [esp+20h] [ebp-38h]
  double v15; // [esp+20h] [ebp-38h]
  Window *thisa; // [esp+3Ch] [ebp-1Ch]
  RECT rect; // [esp+40h] [ebp-18h]

  thisa = a1;
  if ( (unsigned __int8)IsWin() )
  {
    v3 = thisa->helpi;
    if ( v3 == -1 )
    {
      thisa->w_ = thisa->aboutw;
      thisa->h_ = thisa->menuh + thisa->abouth;
    }
    else if ( v3 )
    {
      thisa->w_ = thisa->helpw;
      thisa->h_ = thisa->menuh + thisa->helph;
    }
    else
    {
      if ( (_BYTE)this )
      {
        thisa->bd.mode = 0;
        Board::initbd(v13);
      }
      thisa->w_ = thisa->iconw * thisa->bd.w;
      thisa->h_ = thisa->menuh + thisa->faceh + thisa->iconh * thisa->bd.h;
    }
    Window::initmult((Window *const )v13);
    v14 = (long double)thisa->rect.left;
    v4 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
    if ( (v4 - (long double)(2 * GetBorderWidth())) / 2.0 >= 0.0 )
    {
      v6 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
      v5 = (v6 - (long double)(2 * GetBorderWidth())) / 2.0;
    }
    else
    {
      v5 = 0.0;
    }
    thisa->x_ = (signed int)(v5 + v14);
    v15 = (long double)thisa->rect.top;
    v7 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
    v8 = v7 - (long double)(2 * GetBorderHeight());
    if ( (v8 - (long double)GetBorderTitle()) / 2.0 >= 0.0 )
    {
      v10 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
      v11 = v10 - (long double)(2 * GetBorderHeight());
      v9 = (v11 - (long double)GetBorderTitle()) / 2.0;
    }
    else
    {
      v9 = 0.0;
    }
    thisa->y_ = (signed int)(v9 + v15);
    ReleaseBMP(thisa->pwin);
    ReleaseBMP(thisa->pwint);
    thisa->pwin = CreateBMP(thisa->w_, thisa->h_);
    thisa->pwint = CreateBMP(
                     (signed __int64)((long double)thisa->w_ * thisa->mult),
                     (signed __int64)((long double)thisa->h_ * thisa->mult),
                     thisa->transparent_);
    rect.left = 0;
    rect.top = 0;
    rect.right = 0;
    rect.bottom = 0;
    if ( EnumDisplayMonitors(0, 0, Monitorenumproc, (LPARAM)&rect) == 0 )
    {
      thisa->xscr = rect.left;
      thisa->yscr = rect.top;
      thisa->wscr = rect.right - rect.left;
      thisa->hscr = rect.bottom - rect.top;
    }
    SetSize(
      thisa->x_ + thisa->xscr,
      thisa->yscr + thisa->y_,
      (signed __int64)((long double)thisa->w_ * thisa->mult),
      (signed __int64)((long double)thisa->h_ * thisa->mult));
    Window::paintevent(0, v12);
    FreshWin();
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040FB94; symbol: __ZN6Window9initcolorEv
void __cdecl Window::initcolor(Window *const this)
{
  Window *v1; // ecx
  Window *v2; // ST00_4

  v2 = v1;
  v1->cfg = v1->color[0];
  v2->cbg = v2->color[1];
  v2->ctfg = v2->color[2];
  v2->ctbg = v2->color[3];
  v2->cred = v2->color[4];
  v2->cblue = v2->color[5];
  v2->cgreen = v2->color[6];
  v2->cline = v2->color[7];
  v2->cmine = v2->color[8];
  v2->bd.cred = v2->cred;
  v2->transparent_ = v2->cbg;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040FC66; symbol: __ZN6Window7initbmpEv
void __cdecl Window::initbmp(Window *const this)
{
  Window *v1; // ecx
  unsigned int v2; // ecx
  Window *v3; // [esp+0h] [ebp-198h]
  Window *thisa; // [esp+3Ch] [ebp-15Ch]
  char pngPath[260]; // [esp+4Ch] [ebp-14Ch]
  int i_6; // [esp+150h] [ebp-48h]
  int k_2; // [esp+154h] [ebp-44h]
  int i_5; // [esp+158h] [ebp-40h]
  int i_4; // [esp+15Ch] [ebp-3Ch]
  int i_3; // [esp+160h] [ebp-38h]
  int k_1; // [esp+164h] [ebp-34h]
  int k_0; // [esp+168h] [ebp-30h]
  int i_2; // [esp+16Ch] [ebp-2Ch]
  int k; // [esp+170h] [ebp-28h]
  int i_1; // [esp+174h] [ebp-24h]
  int i_0; // [esp+178h] [ebp-20h]
  int i; // [esp+17Ch] [ebp-1Ch]

  thisa = v1;
  if ( (unsigned __int8)IsWin() )
  {
    if ( thisa->isbmp == 1 )
    {
      ReleaseBMP(thisa->pbg_);
      ReleaseBMP(thisa->pmenu_);
      ReleaseBMP(thisa->pface_);
      ReleaseBMP(thisa->picon_);
      for ( k_0 = 0; k_0 <= 2; ++k_0 )
        ReleaseBMP(*((pbitmap *)&thisa->titlew + k_0 + 104));
      ReleaseBMP(thisa->pok_);
      ReleaseBMP(thisa->pcursor_);
      ReleaseBMP(thisa->pclick_);
      ReleaseBMP(thisa->parrow_);
    }
    else
    {
      for ( i = 0; i <= 1; ++i )
      {
        *((_DWORD *)&thisa->launchh + i + 40) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->titleh + i + 40) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 44) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->titleh + i + 44) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 48) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->titleh + i + 48) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 52) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->titleh + i + 52) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 56) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->titleh + i + 56) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 60) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 62) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 64) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 66) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 68) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 70) = CreateBMP(thisa->menuw, thisa->menuh);
        *((_DWORD *)&thisa->launchh + i + 72) = CreateBMP(thisa->menuw, thisa->menuh);
      }
      for ( i_0 = 0; i_0 <= 8; ++i_0 )
        *((_DWORD *)&thisa->launchw + i_0 + 76) = CreateBMP(thisa->facew, thisa->faceh);
      thisa->piconc = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconf = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconq = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconm = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->picone = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconn = CreateBMP(thisa->iconw, thisa->iconh);
      for ( i_1 = 0; i_1 <= 10; ++i_1 )
        *((_DWORD *)&thisa->titlew + i_1 + 84) = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconp = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->picona = CreateBMP(thisa->iconw, thisa->iconh);
      thisa->piconu = CreateBMP(thisa->iconw, thisa->iconh);
      for ( k = 0; k <= 2; ++k )
      {
        for ( i_2 = 0; i_2 <= 9; ++i_2 )
          *((_DWORD *)&thisa->launchh + k + 3 * i_2 + 108) = CreateBMP(
                                                               *((_DWORD *)&thisa->titlew + k + 8),
                                                               *((_DWORD *)&thisa->launchh + k + 12));
        *((_DWORD *)&thisa->titleh + k + 136) = CreateBMP(
                                                  *((_DWORD *)&thisa->titlew + k + 8),
                                                  *((_DWORD *)&thisa->launchh + k + 12));
        *((_DWORD *)&thisa->titlew + k + 140) = CreateBMP(
                                                  *((_DWORD *)&thisa->titlew + k + 8),
                                                  *((_DWORD *)&thisa->launchh + k + 12));
      }
      thisa->pok = CreateBMP(thisa->okw, thisa->okh);
      thisa->pbtn = CreateBMP(thisa->btnw, thisa->btnh);
      thisa->pcursor = CreateBMP(thisa->cursorw, thisa->cursorh);
      thisa->pclickl = CreateBMP(thisa->clickw, thisa->clickh);
      thisa->pclickr = CreateBMP(thisa->clickw, thisa->clickh);
      thisa->pclickn = CreateBMP(thisa->clickw, thisa->clickh);
      thisa->pclicka = CreateBMP(thisa->clickw, thisa->clickh);
      thisa->parrowl = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->parrowr = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->parrowu = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->parrowd = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->parrowm = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->parrowp = CreateBMP(thisa->arroww, thisa->arrowh);
      thisa->isbmp = 1;
    }
    sprintf(pngPath, "./data/png/%ld/bg.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    thisa->pbg_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/menu.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pmenu_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/face.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pface_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/icon.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->picon_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/digt.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pdigt_[0] = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/digt2.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pdigt_[1] = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/digt_.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pdigt_[2] = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/ok.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pok_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/cursor.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pcursor_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/click.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->pclick_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/arrow.png", thisa->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    thisa->parrow_ = LoadBMP(pngPath);
    for ( k_1 = 0; k_1 <= 8; ++k_1 )
    {
      v2 = GetPixel(thisa->pbg_, 0, k_1);
      *((_DWORD *)&thisa->titleh + k_1 + 160) = v2;
    }
    Window::initcolor(v3);
    for ( i_3 = 0; i_3 <= 1; ++i_3 )
    {
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 40),
        i_3 * thisa->menuw,
        0,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->titleh + i_3 + 40),
        i_3 * thisa->menuw,
        thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 44),
        i_3 * thisa->menuw,
        2 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->titleh + i_3 + 44),
        i_3 * thisa->menuw,
        3 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 48),
        i_3 * thisa->menuw,
        4 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->titleh + i_3 + 48),
        i_3 * thisa->menuw,
        5 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 52),
        i_3 * thisa->menuw,
        6 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->titleh + i_3 + 52),
        i_3 * thisa->menuw,
        7 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 56),
        i_3 * thisa->menuw,
        8 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->titleh + i_3 + 56),
        i_3 * thisa->menuw,
        9 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 60),
        i_3 * thisa->menuw,
        10 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 62),
        i_3 * thisa->menuw,
        11 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 64),
        i_3 * thisa->menuw,
        12 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 66),
        i_3 * thisa->menuw,
        13 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 68),
        i_3 * thisa->menuw,
        14 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 70),
        i_3 * thisa->menuw,
        15 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
      DrawBMP(
        thisa->pmenu_,
        *((pbitmap *)&thisa->launchh + i_3 + 72),
        i_3 * thisa->menuw,
        16 * thisa->menuh,
        thisa->menuw,
        thisa->menuh,
        0,
        0,
        thisa->menuw,
        thisa->menuh);
    }
    for ( i_4 = 0; i_4 <= 8; ++i_4 )
      DrawBMP(
        thisa->pface_,
        *((pbitmap *)&thisa->launchw + i_4 + 76),
        0,
        i_4 * thisa->faceh,
        thisa->facew,
        thisa->faceh,
        0,
        0,
        thisa->facew,
        thisa->faceh);
    DrawBMP(thisa->picon_, thisa->piconc, 0, 0, thisa->iconw, thisa->iconh, 0, 0, thisa->iconw, thisa->iconh);
    DrawBMP(thisa->picon_, thisa->piconf, 0, thisa->iconh, thisa->iconw, thisa->iconh, 0, 0, thisa->iconw, thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->piconq,
      0,
      2 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->piconm,
      0,
      3 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->picone,
      0,
      4 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->piconn,
      0,
      5 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    for ( i_5 = 0; i_5 <= 10; ++i_5 )
      DrawBMP(
        thisa->picon_,
        *((pbitmap *)&thisa->titlew + i_5 + 84),
        0,
        (16 - i_5) * thisa->iconh,
        thisa->iconw,
        thisa->iconh,
        0,
        0,
        thisa->iconw,
        thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->piconp,
      0,
      16 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->picona,
      0,
      17 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    DrawBMP(
      thisa->picon_,
      thisa->piconu,
      0,
      18 * thisa->iconh,
      thisa->iconw,
      thisa->iconh,
      0,
      0,
      thisa->iconw,
      thisa->iconh);
    for ( k_2 = 0; k_2 <= 2; ++k_2 )
    {
      for ( i_6 = 0; i_6 <= 9; ++i_6 )
        DrawBMP(
          *((pbitmap *)&thisa->titlew + k_2 + 104),
          *((pbitmap *)&thisa->launchh + 3 * i_6 + k_2 + 108),
          0,
          (11 - i_6) * *((_DWORD *)&thisa->launchh + k_2 + 12),
          *((_DWORD *)&thisa->titlew + k_2 + 8),
          *((_DWORD *)&thisa->launchh + k_2 + 12),
          0,
          0,
          *((_DWORD *)&thisa->titlew + k_2 + 8),
          *((_DWORD *)&thisa->launchh + k_2 + 12));
      DrawBMP(
        *((pbitmap *)&thisa->titlew + k_2 + 104),
        *((pbitmap *)&thisa->titleh + k_2 + 136),
        0,
        0,
        *((_DWORD *)&thisa->titlew + k_2 + 8),
        *((_DWORD *)&thisa->launchh + k_2 + 12),
        0,
        0,
        *((_DWORD *)&thisa->titlew + k_2 + 8),
        *((_DWORD *)&thisa->launchh + k_2 + 12));
      DrawBMP(
        *((pbitmap *)&thisa->titlew + k_2 + 104),
        *((pbitmap *)&thisa->titlew + k_2 + 140),
        0,
        *((_DWORD *)&thisa->launchh + k_2 + 12),
        *((_DWORD *)&thisa->titlew + k_2 + 8),
        *((_DWORD *)&thisa->launchh + k_2 + 12),
        0,
        0,
        *((_DWORD *)&thisa->titlew + k_2 + 8),
        *((_DWORD *)&thisa->launchh + k_2 + 12));
    }
    DrawBMP(thisa->pok_, thisa->pok, 0, 0, thisa->okw, thisa->okh, 0, 0, thisa->okw, thisa->okh);
    DrawBMP(thisa->pok_, thisa->pbtn, thisa->okw, 0, thisa->btnw, thisa->btnh, 0, 0, thisa->btnw, thisa->btnh);
    DrawBMP(thisa->pcursor_, thisa->pcursor, 0, 0, thisa->cursorw, thisa->cursorh, 0, 0, thisa->cursorw, thisa->cursorh);
    DrawBMP(thisa->pclick_, thisa->pclickl, 0, 0, thisa->clickw, thisa->clickh, 0, 0, thisa->clickw, thisa->clickh);
    DrawBMP(
      thisa->pclick_,
      thisa->pclickr,
      0,
      thisa->clickh,
      thisa->clickw,
      thisa->clickh,
      0,
      0,
      thisa->clickw,
      thisa->clickh);
    DrawBMP(
      thisa->pclick_,
      thisa->pclickn,
      0,
      2 * thisa->clickh,
      thisa->clickw,
      thisa->clickh,
      0,
      0,
      thisa->clickw,
      thisa->clickh);
    DrawBMP(
      thisa->pclick_,
      thisa->pclicka,
      0,
      3 * thisa->clickh,
      thisa->clickw,
      thisa->clickh,
      0,
      0,
      thisa->clickw,
      thisa->clickh);
    DrawBMP(thisa->parrow_, thisa->parrowl, 0, 0, thisa->arroww, thisa->arrowh, 0, 0, thisa->arroww, thisa->arrowh);
    DrawBMP(
      thisa->parrow_,
      thisa->parrowr,
      0,
      thisa->arrowh,
      thisa->arroww,
      thisa->arrowh,
      0,
      0,
      thisa->arroww,
      thisa->arrowh);
    DrawBMP(
      thisa->parrow_,
      thisa->parrowu,
      0,
      2 * thisa->arrowh,
      thisa->arroww,
      thisa->arrowh,
      0,
      0,
      thisa->arroww,
      thisa->arrowh);
    DrawBMP(
      thisa->parrow_,
      thisa->parrowd,
      0,
      3 * thisa->arrowh,
      thisa->arroww,
      thisa->arrowh,
      0,
      0,
      thisa->arroww,
      thisa->arrowh);
    DrawBMP(
      thisa->parrow_,
      thisa->parrowm,
      0,
      4 * thisa->arrowh,
      thisa->arroww,
      thisa->arrowh,
      0,
      0,
      thisa->arroww,
      thisa->arrowh);
    DrawBMP(
      thisa->parrow_,
      thisa->parrowp,
      0,
      5 * thisa->arrowh,
      thisa->arroww,
      thisa->arrowh,
      0,
      0,
      thisa->arroww,
      thisa->arrowh);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412776; symbol: __ZN6Window9paintmenuEv
void __cdecl Window::paintmenu(Window *const this)
{
  unsigned int *v1; // ecx
  Window *v2; // ST2C_4

  v2 = (Window *)v1;
  DrawBMP(*((pbitmap *)&v2->launchh + (v2->helpi == -1) + 48), v1[866] - v1[4], 0, v1[4], v1[5]);
  DrawBMP(*((pbitmap *)&v2->titleh + (v2->helpi > 0) + 44), v2->w_ - 2 * v2->menuw, 0, v2->menuw, v2->menuh);
  DrawBMP(*((pbitmap *)&v2->launchh + (v2->helpi == -3) + 56), v2->w_ - 3 * v2->menuw, 0, v2->menuw, v2->menuh);
  DrawBMP(*((pbitmap *)&v2->titleh + (v2->helpi == -2) + 52), v2->w_ - 4 * v2->menuw, 0, v2->menuw, v2->menuh);
  DrawBMP(v2->pface[6], v2->w_ - 5 * v2->menuw, 0, v2->menuw, v2->menuh);
  DrawBMP(*((pbitmap *)&v2->launchh + (v2->bd.mode == 1) + 40), 0, 0, v2->menuw, v2->menuh);
  DrawBMP(*((pbitmap *)&v2->titleh + (v2->bd.mode == 2) + 40), v2->menuw, 0, v2->menuw, v2->menuh);
  DrawBMP(*((pbitmap *)&v2->launchh + (v2->bd.mode == 3) + 44), 2 * v2->menuw, 0, v2->menuw, v2->menuh);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412A48; symbol: __ZN6Window9paintfaceEv
void __cdecl Window::paintface(Window *const this)
{
  _DWORD *v1; // ecx
  int face__[6]; // [esp+34h] [ebp-34h]
  int facei; // [esp+4Ch] [ebp-1Ch]

  face__[0] = 4;
  face__[1] = 4;
  face__[2] = 3;
  face__[3] = 1;
  face__[4] = 2;
  face__[5] = 0;
  facei = v1[195];
  if ( facei == 1 && v1[735] == 1 )
    ++facei;
  if ( v1[196] > 0 )
    facei = 5;
  DrawBMP((pbitmap)v1[face__[facei] + 76], (v1[866] - v1[6]) / 2, v1[5], v1[6], v1[7]);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412B1E; symbol: __ZN6Window11paintnumberElllllll
void __userpurge Window::paintnumber(Window *a1@<ecx>, Window *const this, int n, int l, int x, int y, int w, int h, int b)
{
  int v9; // eax
  int v10; // eax
  Window *thisa; // [esp+2Ch] [ebp-5Ch]
  int dl_0; // [esp+38h] [ebp-50h]
  int digt[10]; // [esp+3Ch] [ebp-4Ch]
  bool minb; // [esp+67h] [ebp-21h]
  int di_0; // [esp+68h] [ebp-20h]
  int dlm; // [esp+6Ch] [ebp-1Ch]

  thisa = a1;
  dl_0 = 0;
  minb = (signed int)this < 0;
  if ( (signed int)this < 0 )
    this = (Window *const )-(signed int)this;
  do
  {
    digt[dl_0] = (signed int)this % 10;
    this = (Window *const )((signed int)this / 10);
    ++dl_0;
  }
  while ( this );
  if ( minb )
  {
    v9 = dl_0 + 1;
    if ( dl_0 + 1 < n )
      v9 = n;
    dlm = v9;
  }
  else
  {
    if ( dl_0 <= n )
      v10 = n;
    else
      v10 = dl_0;
    dlm = v10;
  }
  for ( di_0 = 0; di_0 < dlm; ++di_0 )
  {
    if ( di_0 >= dl_0 )
    {
      if ( di_0 == dl_0 && minb )
        DrawBMP(*((pbitmap *)&thisa->titleh + h + 136), y * (dlm - di_0 - 1) + l, x, y, w);
      else
        DrawBMP(*((pbitmap *)&thisa->titlew + h + 140), y * (dlm - di_0 - 1) + l, x, y, w);
    }
    else
    {
      DrawBMP(*((pbitmap *)&thisa->launchh + h + 3 * digt[di_0] + 108), y * (dlm - di_0 - 1) + l, x, y, w);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412CF2; symbol: __ZN6Window11paintnumberElllll
void __userpurge Window::paintnumber(Window *a1@<ecx>, Window *const this, int n, int l, int x, int y, int b)
{
  int v7; // [esp+1Ch] [ebp-1Ch]

  Window::paintnumber(a1, this, n, l, x, *((_DWORD *)&a1->titlew + y + 8), *((_DWORD *)&a1->launchh + y + 12), y, v7);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412D56; symbol: __ZN6Window11paintnumberEllll
void __userpurge Window::paintnumber(Window *a1@<ecx>, Window *const this, int n, int l, int x, int y)
{
  int v6; // [esp+14h] [ebp-24h]

  Window::paintnumber(a1, this, n, l, x, 0, v6);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00412D94; symbol: __ZN6Window10paintlevelEv
void __cdecl Window::paintlevel(Window *const this)
{
  Window *v1; // ecx
  int v2; // [esp+14h] [ebp-34h]
  int v3; // [esp+14h] [ebp-34h]
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  Window *score2; // [esp+38h] [ebp-10h]
  Window *score; // [esp+3Ch] [ebp-Ch]

  thisa = v1;
  score = (Window *)v1->bd.line;
  if ( v1->singleb )
    score = (Window *)(v1->bd.line - v1->bd.missline);
  if ( (signed int)score > 9999 )
  {
    if ( (signed int)score > 99999 )
      Window::paintnumber(v1, score, 6, 0, v1->digth[0], 2 * v1->singleb, v2);
    else
      Window::paintnumber(v1, score, 5, 0, v1->digth[0], 2 * v1->singleb, v2);
  }
  else
  {
    Window::paintnumber(v1, score, 4, 0, v1->digth[0], 2 * v1->singleb, v2);
  }
  score2 = (Window *)thisa->bd.level;
  if ( thisa->singleb )
    score2 = (Window *)thisa->bd.solven;
  if ( (signed int)score2 > 99 )
  {
    if ( (signed int)score2 > 999 )
    {
      if ( (signed int)score2 > 9999 )
        Window::paintnumber(thisa, score2, 5, thisa->w_ - 5 * thisa->digtw[0], thisa->digth[0], 2 * thisa->singleb, v3);
      else
        Window::paintnumber(thisa, score2, 4, thisa->w_ - 4 * thisa->digtw[0], thisa->digth[0], 2 * thisa->singleb, v3);
    }
    else
    {
      Window::paintnumber(thisa, score2, 3, -3 * thisa->digtw[0] + thisa->w_, thisa->digth[0], 2 * thisa->singleb, v3);
    }
  }
  else
  {
    Window::paintnumber(thisa, score2, 2, thisa->w_ - 2 * thisa->digtw[0], thisa->digth[0], 2 * thisa->singleb, v3);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413050; symbol: __ZN6Window10paintblockER5Blockllllll
void __userpurge Window::paintblock(Window *a1@<ecx>, Window *const this, Block *const b, int i, int j, int x, int y, int w, int h)
{
  Window *thisa; // [esp+2Ch] [ebp-1Ch]

  thisa = a1;
  if ( *(_BYTE *)(this->digth[0] + ((_DWORD)b << 7) + i) )
  {
    if ( this->facew > (signed int)b && this->menuh - 1 <= i )
      DrawBMP(a1->picone, j, x, y, w);
  }
  else if ( this->menuw <= 0 )
  {
    if ( *(_BYTE *)(this->digtw[2] + ((_DWORD)b << 7) + i) )
    {
      if ( *(_BYTE *)(this->digtw[1] + ((_DWORD)b << 7) + i) )
        DrawBMP(a1->piconm, j, x, y, w);
      else
        DrawBMP(*((pbitmap *)&a1->titlew + *(_DWORD *)(this->digth[1] + ((_DWORD)b << 9) + 4 * i) + 84), j, x, y, w);
    }
    else if ( *(_BYTE *)(this->iconh + ((_DWORD)b << 7) + i) )
    {
      DrawBMP(a1->piconf, j, x, y, w);
    }
    else if ( *(_BYTE *)(this->digtw[0] + ((_DWORD)b << 7) + i) )
    {
      DrawBMP(a1->piconq, j, x, y, w);
    }
    else if ( this->titleh != 4 && (this->titleh || a1->bd.mode)
           || !*(_BYTE *)(this->digtw[1] + ((_DWORD)b << 7) + i)
           || a1->helpi )
    {
      DrawBMP(a1->piconc, j, x, y, w);
    }
    else
    {
      DrawBMP(a1->piconn, j, x, y, w);
    }
  }
  else if ( *(_BYTE *)(this->digtw[2] + ((_DWORD)b << 7) + i) )
  {
    DrawBMP(a1->piconp, j, x, y, w);
    Bar(j, x, y - 1, w - 1, thisa->cbg);
  }
  else
  {
    DrawBMP(a1->picone, j, x, y, w);
  }
  if ( thisa->cheatb )
  {
    if ( thisa->bd.leftrule[(_DWORD)b][i] && thisa->bd.blck[(_DWORD)b][i] != 1 && thisa->bd.mask[(_DWORD)b][i] != 1 )
      Bar(j, x, thisa->iconw - 1, thisa->iconh - 1, thisa->cblue, thisa->transparent);
    if ( thisa->bd.rightrule[(_DWORD)b][i]
      && thisa->bd.blck[(_DWORD)b][i] != 1
      && thisa->bd.qstn[(_DWORD)b][i] != 1
      && thisa->bd.flag[(_DWORD)b][i] != 1
      && thisa->bd.mask[(_DWORD)b][i] != 1 )
    {
      Bar(j, x, thisa->iconw - 1, thisa->iconh - 1, thisa->cred, thisa->transparent);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413534; symbol: __ZN6Window10paintboardER5Blockll
void __userpurge Window::paintboard(Window *a1@<ecx>, Window *const this, Block *const b, int x, int y)
{
  int v5; // [esp+1Ch] [ebp-2Ch]
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  int j; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]

  thisa = a1;
  for ( i = 0; this->launchw > i; ++i )
  {
    for ( j = 0; this->launchh > j; ++j )
      Window::paintblock(
        thisa,
        this,
        (Block *const )i,
        j,
        (int)b + i * thisa->iconw,
        thisa->menuh + j * thisa->iconh + x,
        thisa->iconw,
        thisa->iconh,
        v5);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004135E8; symbol: __ZN6Window10paintboardER5Blockllll
void __userpurge Window::paintboard(Window *a1@<ecx>, Window *const this, Block *const b, int x, int y, int cx_0, int cy)
{
  Window *v7; // ST2C_4
  int v8; // [esp+Ch] [ebp-3Ch]

  v7 = a1;
  Window::paintboard(a1, this, b, x, v8);
  DrawBMP(
    v7->pcursor,
    (unsigned int)b + y * v7->iconw + v7->iconw / 2,
    x + v7->menuh + cx_0 * v7->iconh + v7->iconh / 2,
    v7->cursorw,
    v7->cursorh,
    0xC0C0C0u);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004136B0; symbol: __ZN6Window10paintboardEv
void __cdecl Window::paintboard(Window *const this)
{
  int v1; // ecx
  int v2; // [esp+Ch] [ebp-3Ch]
  Window *thisa; // [esp+2Ch] [ebp-1Ch]

  thisa = (Window *)v1;
  Window::paintboard((Window *)v1, (Window *const )(v1 + 768), 0, *(_DWORD *)(v1 + 28), v2);
  if ( thisa->bd.mx >= 0 && thisa->bd.my >= 0 )
  {
    if ( thisa->barb )
      Bar(
        thisa->bd.mx * thisa->iconw,
        thisa->faceh + thisa->menuh + thisa->iconh * thisa->bd.my,
        thisa->iconw - 1,
        thisa->iconh - 1,
        thisa->ctfg,
        thisa->transparent);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041379C; symbol: __ZN6Window9paintlineEP6bitmaplll
void __userpurge Window::paintline(Window *a1@<ecx>, Window *const this, pbitmap p, int n, int x, int y)
{
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  int k; // [esp+3Ch] [ebp-Ch]

  thisa = a1;
  for ( k = 0; k < (signed int)p; ++k )
    DrawBMP((pbitmap)this, k * thisa->iconw + n, x, thisa->iconw, thisa->iconh);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413806; symbol: __ZN6Window9paintlineEP6bitmapS1_llll
void __userpurge Window::paintline(Window *a1@<ecx>, Window *const this, pbitmap pa, pbitmap pb, int a, int b, int x, int y)
{
  Window *v8; // ST1C_4
  int v9; // ST10_4
  int v10; // [esp+10h] [ebp-18h]

  v8 = a1;
  Window::paintline(a1, this, pb, b, x, v10);
  Window::paintline(v8, (Window *const )pa, (pbitmap)a, (_DWORD)pb * v8->iconw + b, x, v9);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413874; symbol: __ZN6Window9paintlineEP6bitmapS1_S1_lllll
void __userpurge Window::paintline(Window *a1@<ecx>, Window *const this, pbitmap pa, pbitmap pb, pbitmap pc, int a, int b, int c, int x, int y)
{
  Window *v10; // ST2C_4
  int v11; // ST10_4
  int v12; // [esp+18h] [ebp-20h]

  v10 = a1;
  Window::paintline(a1, this, pa, pc, a, c, x, v12);
  Window::paintline(v10, (Window *const )pb, (pbitmap)b, v10->iconw * ((_DWORD)pc + a) + c, x, v11);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004138F4; symbol: __ZN6Window9paintlineEP6bitmapS1_S1_S1_llllll
void __userpurge Window::paintline(Window *a1@<ecx>, Window *const this, pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, int a, int b, int c, int d, int x, int y)
{
  Window *v12; // ST2C_4
  int v13; // ST10_4
  int v14; // [esp+20h] [ebp-18h]

  v12 = a1;
  Window::paintline(a1, this, pa, pb, pd, a, b, d, x, v14);
  Window::paintline(v12, (Window *const )pc, (pbitmap)c, v12->iconw * ((_DWORD)pd + a + b) + d, x, v13);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413988; symbol: __ZN6Window9paintlineEP6bitmapS1_S1_S1_S1_lllllll
void __userpurge Window::paintline(Window *a1@<ecx>, Window *const this, pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, pbitmap pe, int a, int b, int c, int d, int e, int x, int y)
{
  Window *v14; // ST3C_4
  int v15; // ST10_4
  int v16; // [esp+28h] [ebp-20h]

  v14 = a1;
  Window::paintline(a1, this, pa, pb, pc, pe, a, b, c, e, x, v16);
  Window::paintline(v14, (Window *const )pd, (pbitmap)d, v14->iconw * ((_DWORD)pe + a + b + c) + e, x, v15);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00413A2E; symbol: __ZN6Window9painthelpEv
void __cdecl Window::painthelp(Window *const this)
{
  int v1; // ecx
  unsigned int v2; // ebx
  unsigned int v3; // edi
  unsigned int v4; // esi
  int v5; // ST34_4
  int v6; // ST04_4
  __int16 *v7; // eax
  unsigned int v8; // ST04_4
  unsigned int v9; // ST04_4
  unsigned int v10; // esi
  int v11; // ST34_4
  unsigned int v12; // ST30_4
  int v13; // edi
  int v14; // ebx
  int v15; // ST04_4
  __int16 *v16; // eax
  unsigned int v17; // ST20_4
  unsigned int v18; // esi
  int v19; // ST34_4
  unsigned int v20; // ST30_4
  int v21; // edi
  int v22; // ebx
  int v23; // ST04_4
  __int16 *v24; // eax
  unsigned int v25; // ST20_4
  unsigned int v26; // esi
  int v27; // ST34_4
  unsigned int v28; // ST30_4
  int v29; // edi
  int v30; // ebx
  int v31; // ST04_4
  __int16 *v32; // eax
  unsigned int v33; // ST20_4
  unsigned int v34; // esi
  int v35; // ST34_4
  unsigned int v36; // ST30_4
  int v37; // edi
  int v38; // ebx
  int v39; // ST04_4
  __int16 *v40; // eax
  unsigned int v41; // ST20_4
  unsigned int v42; // ebx
  unsigned int v43; // edi
  unsigned int v44; // esi
  int v45; // ST34_4
  int v46; // ST04_4
  __int16 *v47; // eax
  unsigned int v48; // ST04_4
  LeaderboardEntry_t *const v49; // ST00_4
  int v50; // ecx
  int v51; // eax
  int *v52; // eax
  bool v53; // al
  ISteamFriends *v54; // eax
  int v55; // ST34_4
  unsigned int v56; // ST30_4
  unsigned int v57; // ST40_4
  int v58; // ebx
  const char *v59; // ST04_4
  int v60; // edi
  int v61; // esi
  int v62; // ebx
  const char *v63; // ST04_4
  unsigned int v64; // eax
  int v65; // ST1C_4
  int v66; // ST14_4
  int v67; // ST34_4
  unsigned int v68; // ST30_4
  int v69; // ST40_4
  unsigned int v70; // edi
  bitmap *v71; // eax
  unsigned int v72; // edi
  int v73; // ST34_4
  unsigned int v74; // ST30_4
  int v75; // ST40_4
  int v76; // ebx
  int v77; // esi
  int v78; // ST04_4
  __int16 *v79; // eax
  unsigned int v80; // ST04_4
  unsigned int v81; // ebx
  unsigned int v82; // edi
  unsigned int v83; // esi
  int v84; // ST34_4
  int v85; // ST04_4
  __int16 *v86; // eax
  unsigned int v87; // ST04_4
  unsigned int v88; // esi
  unsigned int v89; // edi
  int v90; // ST34_4
  int v91; // ST30_4
  int v92; // ST40_4
  const __int16 *v93; // ebx
  __int16 *v94; // eax
  unsigned int v95; // esi
  unsigned int v96; // edi
  const __int16 *v97; // ebx
  signed int v98; // eax
  __int16 *v99; // eax
  unsigned int v100; // esi
  unsigned int v101; // edi
  int v102; // ST34_4
  int v103; // ST30_4
  int v104; // ST40_4
  const __int16 *v105; // ebx
  __int16 *v106; // eax
  unsigned int v107; // ebx
  unsigned int v108; // edi
  unsigned int v109; // esi
  int v110; // ST34_4
  int v111; // ST04_4
  __int16 *v112; // eax
  unsigned int v113; // esi
  int v114; // ST34_4
  int v115; // ST30_4
  unsigned int v116; // ST40_4
  int v117; // ebx
  int v118; // edi
  int v119; // ST04_4
  __int16 *v120; // eax
  unsigned int v121; // ST20_4
  unsigned int v122; // ST04_4
  unsigned int v123; // esi
  unsigned int v124; // edi
  int v125; // ST34_4
  unsigned int v126; // ST30_4
  int v127; // ST40_4
  int v128; // ebx
  __int16 *v129; // eax
  unsigned int v130; // ST18_4
  unsigned int v131; // edi
  int v132; // esi
  int v133; // ebx
  int v134; // ST34_4
  unsigned int v135; // eax
  unsigned int v136; // edi
  int v137; // esi
  int v138; // ebx
  int v139; // ST34_4
  const char *v140; // ST04_4
  unsigned int v141; // eax
  unsigned int v142; // ST18_4
  unsigned int v143; // ebx
  unsigned int v144; // edi
  unsigned int v145; // esi
  int v146; // ST34_4
  int v147; // ST04_4
  __int16 *v148; // eax
  unsigned int v149; // ST04_4
  signed int v150; // eax
  unsigned int v151; // edi
  int v152; // ST34_4
  int v153; // ST30_4
  unsigned int v154; // ST40_4
  int v155; // ebx
  int v156; // esi
  __int16 *v157; // eax
  unsigned int v158; // ebx
  unsigned int v159; // edi
  unsigned int v160; // esi
  int v161; // ST34_4
  int v162; // ST04_4
  __int16 *v163; // eax
  unsigned int v164; // ST04_4
  unsigned int v165; // edi
  int v166; // ST34_4
  int v167; // ST30_4
  unsigned int v168; // ST40_4
  int v169; // ebx
  int v170; // esi
  __int16 *v171; // eax
  unsigned int v172; // esi
  int v173; // ST34_4
  int v174; // ST30_4
  int v175; // edi
  int v176; // ebx
  __int16 *v177; // eax
  unsigned int v178; // ebx
  unsigned int v179; // edi
  unsigned int v180; // esi
  int v181; // ST34_4
  int v182; // ST04_4
  __int16 *v183; // eax
  unsigned int v184; // ST04_4
  int v185; // ST10_4
  int v186; // ST10_4
  int v187; // ST10_4
  int v188; // ST10_4
  int v189; // ST28_4
  unsigned int v190; // esi
  int v191; // ST34_4
  int v192; // ST30_4
  int v193; // edi
  int v194; // ebx
  int v195; // ST04_4
  __int16 *v196; // eax
  unsigned int v197; // ST20_4
  int v198; // ST10_4
  int v199; // ST10_4
  int v200; // ST10_4
  int v201; // ST10_4
  unsigned int v202; // esi
  int v203; // ST34_4
  int v204; // ST30_4
  int v205; // edi
  int v206; // ebx
  __int16 *v207; // eax
  int v208; // ST10_4
  int v209; // ST10_4
  int v210; // ST10_4
  int v211; // ST10_4
  unsigned int v212; // esi
  int v213; // ST34_4
  int v214; // ST30_4
  int v215; // edi
  int v216; // ebx
  int v217; // ST04_4
  __int16 *v218; // eax
  unsigned int v219; // ST20_4
  unsigned int v220; // ST04_4
  unsigned int v221; // ebx
  unsigned int v222; // edi
  unsigned int v223; // esi
  int v224; // ST34_4
  int v225; // ST04_4
  __int16 *v226; // eax
  unsigned int v227; // ST04_4
  int v228; // ST20_4
  int v229; // ST20_4
  int v230; // ST10_4
  unsigned int v231; // esi
  int v232; // ST34_4
  int v233; // ST30_4
  int v234; // edi
  int v235; // ebx
  int v236; // ST04_4
  __int16 *v237; // eax
  unsigned int v238; // ST20_4
  int v239; // ST20_4
  int v240; // ST20_4
  int v241; // ST28_4
  int v242; // ST10_4
  unsigned int v243; // esi
  int v244; // ST34_4
  int v245; // ST30_4
  int v246; // edi
  int v247; // ebx
  int v248; // ST04_4
  __int16 *v249; // eax
  unsigned int v250; // ST20_4
  int v251; // ST10_4
  unsigned int v252; // esi
  int v253; // ST34_4
  int v254; // ST30_4
  int v255; // edi
  int v256; // ebx
  int v257; // ST04_4
  __int16 *v258; // eax
  int v259; // ST10_4
  unsigned int v260; // esi
  int v261; // ST34_4
  int v262; // ST30_4
  int v263; // edi
  int v264; // ebx
  __int16 *v265; // eax
  unsigned int v266; // ST04_4
  unsigned int v267; // ebx
  unsigned int v268; // edi
  unsigned int v269; // esi
  int v270; // ST34_4
  int v271; // ST04_4
  __int16 *v272; // eax
  unsigned int v273; // ST04_4
  signed int v274; // edx
  signed int v275; // eax
  unsigned int v276; // edi
  int v277; // ST34_4
  unsigned int v278; // ST30_4
  int v279; // ST40_4
  int v280; // esi
  const __int16 *v281; // ebx
  int v282; // ST04_4
  __int16 *v283; // eax
  unsigned int v284; // edi
  int v285; // ST34_4
  unsigned int v286; // ST30_4
  int v287; // ST40_4
  int v288; // esi
  const __int16 *v289; // ebx
  int v290; // ST04_4
  __int16 *v291; // eax
  unsigned int v292; // ST24_4
  unsigned int v293; // edi
  int v294; // ST34_4
  unsigned int v295; // ST30_4
  int v296; // ST40_4
  int v297; // esi
  const __int16 *v298; // ebx
  int v299; // ST04_4
  __int16 *v300; // eax
  unsigned int v301; // ST24_4
  unsigned int v302; // ST04_4
  int v303; // ST34_4
  unsigned int v304; // edi
  unsigned int v305; // esi
  int v306; // ebx
  bitmap *v307; // eax
  unsigned int v308; // edi
  int v309; // ST34_4
  unsigned int v310; // ST30_4
  int v311; // ST40_4
  int v312; // ebx
  int v313; // esi
  int v314; // ST04_4
  __int16 *v315; // eax
  int v316; // ST34_4
  unsigned int v317; // edi
  unsigned int v318; // esi
  int v319; // ebx
  bitmap *v320; // eax
  unsigned int v321; // edi
  int v322; // ST34_4
  unsigned int v323; // ST30_4
  int v324; // ST40_4
  int v325; // ebx
  int v326; // esi
  int v327; // ST04_4
  __int16 *v328; // eax
  int v329; // ST34_4
  unsigned int v330; // edi
  unsigned int v331; // esi
  unsigned int v332; // ebx
  bitmap *v333; // eax
  int v334; // ST34_4
  unsigned int v335; // edi
  unsigned int v336; // esi
  unsigned int v337; // ebx
  bitmap *v338; // eax
  int v339; // ST34_4
  unsigned int v340; // edi
  unsigned int v341; // esi
  unsigned int v342; // ebx
  bitmap *v343; // eax
  unsigned int v344; // edi
  int v345; // ST34_4
  unsigned int v346; // ST30_4
  int v347; // ST40_4
  int v348; // esi
  const __int16 *v349; // ebx
  int v350; // ST04_4
  __int16 *v351; // eax
  const CSteamID *v352; // [esp+0h] [ebp-548h]
  Block *v353; // [esp+0h] [ebp-548h]
  Block *v354; // [esp+0h] [ebp-548h]
  unsigned int v355; // [esp+4h] [ebp-544h]
  unsigned int v356; // [esp+4h] [ebp-544h]
  unsigned int v357; // [esp+4h] [ebp-544h]
  int v358; // [esp+4h] [ebp-544h]
  int v359; // [esp+4h] [ebp-544h]
  int v360; // [esp+4h] [ebp-544h]
  const char *v361; // [esp+4h] [ebp-544h]
  int v362; // [esp+4h] [ebp-544h]
  unsigned int v363; // [esp+4h] [ebp-544h]
  int v364; // [esp+4h] [ebp-544h]
  int v365; // [esp+4h] [ebp-544h]
  int v366; // [esp+4h] [ebp-544h]
  int v367; // [esp+10h] [ebp-538h]
  int v368; // [esp+10h] [ebp-538h]
  int v369; // [esp+10h] [ebp-538h]
  int v370; // [esp+10h] [ebp-538h]
  int v371; // [esp+14h] [ebp-534h]
  int v372; // [esp+14h] [ebp-534h]
  unsigned int v373; // [esp+18h] [ebp-530h]
  unsigned int v374; // [esp+18h] [ebp-530h]
  unsigned int v375; // [esp+20h] [ebp-528h]
  unsigned int v376; // [esp+20h] [ebp-528h]
  unsigned int v377; // [esp+20h] [ebp-528h]
  unsigned int v378; // [esp+20h] [ebp-528h]
  unsigned int v379; // [esp+20h] [ebp-528h]
  unsigned int v380; // [esp+24h] [ebp-524h]
  int v381; // [esp+28h] [ebp-520h]
  int w; // [esp+30h] [ebp-518h]
  int y; // [esp+34h] [ebp-514h]
  int yd; // [esp+40h] [ebp-508h]
  Window *thisa; // [esp+4Ch] [ebp-4FCh]
  const char *cheatn[9]; // [esp+50h] [ebp-4F8h]
  int v387; // [esp+74h] [ebp-4D4h]
  const char *cheats[9]; // [esp+78h] [ebp-4D0h]
  int v389; // [esp+9Ch] [ebp-4ACh]
  int cheatc[9]; // [esp+A0h] [ebp-4A8h]
  int v391; // [esp+C4h] [ebp-484h]
  int k__[3][3]; // [esp+C8h] [ebp-480h]
  pbitmap v393; // [esp+ECh] [ebp-45Ch]
  pbitmap v394; // [esp+F0h] [ebp-458h]
  pbitmap v395; // [esp+F4h] [ebp-454h]
  int v396; // [esp+F8h] [ebp-450h]
  int v397; // [esp+FCh] [ebp-44Ch]
  pbitmap v398; // [esp+100h] [ebp-448h]
  pbitmap v399; // [esp+104h] [ebp-444h]
  pbitmap v400; // [esp+108h] [ebp-440h]
  BOOL v401; // [esp+10Ch] [ebp-43Ch]
  BOOL v402; // [esp+110h] [ebp-438h]
  BOOL v403; // [esp+114h] [ebp-434h]
  BOOL v404; // [esp+118h] [ebp-430h]
  BOOL v405; // [esp+11Ch] [ebp-42Ch]
  BOOL v406; // [esp+120h] [ebp-428h]
  BOOL v407; // [esp+128h] [ebp-420h]
  BOOL v408; // [esp+12Ch] [ebp-41Ch]
  BOOL v409; // [esp+134h] [ebp-414h]
  BOOL v410; // [esp+138h] [ebp-410h]
  pbitmap picon__[3][3][5]; // [esp+1CCh] [ebp-37Ch]
  pbitmap v412; // [esp+280h] [ebp-2C8h]
  pbitmap v413; // [esp+284h] [ebp-2C4h]
  pbitmap v414; // [esp+288h] [ebp-2C0h]
  pbitmap v415; // [esp+28Ch] [ebp-2BCh]
  pbitmap v416; // [esp+290h] [ebp-2B8h]
  pbitmap v417; // [esp+294h] [ebp-2B4h]
  pbitmap v418; // [esp+298h] [ebp-2B0h]
  pbitmap v419; // [esp+29Ch] [ebp-2ACh]
  pbitmap v420; // [esp+2A0h] [ebp-2A8h]
  pbitmap v421; // [esp+2A4h] [ebp-2A4h]
  int j_0; // [esp+3D4h] [ebp-174h]
  pbitmap psettingicon[2]; // [esp+3D8h] [ebp-170h]
  int k_1; // [esp+3E0h] [ebp-168h]
  uint16_t utf16[2]; // [esp+3E4h] [ebp-164h]
  uint32_t buffer; // [esp+3E8h] [ebp-160h]
  int k_[5]; // [esp+3ECh] [ebp-15Ch]
  int n__[3]; // [esp+400h] [ebp-148h]
  int scr__[3]; // [esp+40Ch] [ebp-13Ch]
  pbitmap pface__[3]; // [esp+418h] [ebp-130h]
  pbitmap pmenu__[3]; // [esp+424h] [ebp-124h]
  pbitmap prelax__[2]; // [esp+430h] [ebp-118h]
  pbitmap pcheat__[2]; // [esp+438h] [ebp-110h]
  int iconh4; // [esp+440h] [ebp-108h]
  int iconh3_0; // [esp+444h] [ebp-104h]
  int iconh2_0; // [esp+448h] [ebp-100h]
  int iconh1_0; // [esp+44Ch] [ebp-FCh]
  int iconwn_0; // [esp+450h] [ebp-F8h]
  int iconwr_0; // [esp+454h] [ebp-F4h]
  int iconwm_0; // [esp+458h] [ebp-F0h]
  int iconwl_0; // [esp+45Ch] [ebp-ECh]
  int iconh3; // [esp+460h] [ebp-E8h]
  int iconh2; // [esp+464h] [ebp-E4h]
  int iconh1; // [esp+468h] [ebp-E0h]
  int iconwn; // [esp+46Ch] [ebp-DCh]
  int iconwr; // [esp+470h] [ebp-D8h]
  int iconwm; // [esp+474h] [ebp-D4h]
  int iconwl; // [esp+478h] [ebp-D0h]
  int j_; // [esp+47Ch] [ebp-CCh]
  double helph___0; // [esp+480h] [ebp-C8h]
  int helpw___0; // [esp+48Ch] [ebp-BCh]
  double helph__; // [esp+490h] [ebp-B8h]
  int helpw__; // [esp+49Ch] [ebp-ACh]
  int lens; // [esp+4A0h] [ebp-A8h]
  int lenc; // [esp+4A4h] [ebp-A4h]
  const char *usernamec; // [esp+4A8h] [ebp-A0h]
  int i_4; // [esp+4ACh] [ebp-9Ch]
  int j_6; // [esp+4B0h] [ebp-98h]
  int j_5; // [esp+4B4h] [ebp-94h]
  int j_4; // [esp+4B8h] [ebp-90h]
  int i_3; // [esp+4BCh] [ebp-8Ch]
  int k_13; // [esp+4C0h] [ebp-88h]
  int k_12; // [esp+4C4h] [ebp-84h]
  int k_11; // [esp+4C8h] [ebp-80h]
  int k_10; // [esp+4CCh] [ebp-7Ch]
  int k_9; // [esp+4D0h] [ebp-78h]
  int j_3; // [esp+4D4h] [ebp-74h]
  int i_2; // [esp+4D8h] [ebp-70h]
  int j__0; // [esp+4DCh] [ebp-6Ch]
  int i_1; // [esp+4E0h] [ebp-68h]
  int j_2; // [esp+4E4h] [ebp-64h]
  int k_8; // [esp+4E8h] [ebp-60h]
  int k_7; // [esp+4ECh] [ebp-5Ch]
  int j_1; // [esp+4F0h] [ebp-58h]
  int i_0; // [esp+4F4h] [ebp-54h]
  int i; // [esp+4F8h] [ebp-50h]
  int k_6; // [esp+4FCh] [ebp-4Ch]
  int k_5; // [esp+500h] [ebp-48h]
  int k_4; // [esp+504h] [ebp-44h]
  int k_3; // [esp+508h] [ebp-40h]
  int j; // [esp+50Ch] [ebp-3Ch]
  int k_2; // [esp+510h] [ebp-38h]
  int score; // [esp+514h] [ebp-34h]
  int k_0; // [esp+518h] [ebp-30h]
  int poss; // [esp+51Ch] [ebp-2Ch]
  int posc; // [esp+520h] [ebp-28h]
  int k; // [esp+524h] [ebp-24h]
  int rank_; // [esp+528h] [ebp-20h]
  int leadid; // [esp+52Ch] [ebp-1Ch]

  thisa = (Window *)v1;
  switch ( *(_DWORD *)(v1 + 3376) )
  {
    case 0xFFFFFFFD:
      goto LABEL_42;
    case 0xFFFFFFFE:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v42 = thisa->cbg;
      v43 = thisa->ctfg;
      v44 = thisa->faceh;
      v45 = thisa->helpw;
      v47 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP + 9), v46);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v47, 0, 0, v45, v44, v43, v42, v375);
      Window::setfontheight_((Window *const )thisa->fontfh, v48);
      if ( thisa->bd.st.steamb )
      {
        Window::setfontheight_((Window *const )(thisa->fontsh - 1), v355);
        pmenu__[0] = thisa->pmenu1[0];
        pmenu__[1] = thisa->pmenu2[0];
        pmenu__[2] = thisa->pmenu3[0];
        LeaderboardEntry_t::LeaderboardEntry_t(v49);
        for ( leadid = 0; leadid <= 2; ++leadid )
        {
          DrawBMP(
            pmenu__[leadid],
            (2 * leadid + 1) * thisa->helpw / 6 + thisa->facew / -2,
            thisa->menuh,
            thisa->facew,
            thisa->faceh,
            thisa->cfg);
          for ( rank_ = 0; (*thisa->bd.st.leadsn)[0][rank_ + 20 * (leadid + 3 * thisa->lead_5)].m_nScore > 9997; ++rank_ )
            ;
          for ( k = 0; k <= 19; ++k )
          {
            if ( k > 9 )
            {
              v50 = (int)(*thisa->bd.st.leadsn)[15];
              v51 = 32 * (k - 10 + 20 * (leadid + 3 * thisa->lead_5));
            }
            else
            {
              v50 = (int)thisa->bd.st.leadsn;
              v51 = 32 * (rank_ + k + 20 * (leadid + 3 * thisa->lead_5));
            }
            v52 = (int *)(v50 + v51);
            cheatc[0] = *v52;
            cheatc[1] = v52[1];
            cheatc[2] = v52[2];
            cheatc[3] = v52[3];
            cheatc[4] = v52[4];
            cheatc[5] = v52[5];
            cheatc[6] = v52[6];
            cheatc[7] = v52[7];
            v53 = (*thisa->bd.st.leadsn)[3 * thisa->lead_5 + 30][20 * leadid].m_nGlobalRank == cheatc[2]
               && (signed int)CSteamID::GetEAccountType(v352) > 0;
            if ( v53 )
              Window::setfontweight_((Window *const )0x2BC, v356);
            if ( (signed int)CSteamID::GetEAccountType(v352) > 0 )
            {
              v54 = SteamFriends();
              usernamec = (const char *)(*(int (__stdcall **)(int, int))(*(_DWORD *)v54 + 28))(cheatc[0], cheatc[1]);
              *(_DWORD *)utf16 = 0;
              posc = 0;
              lenc = 0;
              poss = 0;
              lens = 0;
              while ( usernamec[posc] )
              {
                lenc = UTF8ToUnicode((uint8_t *)&usernamec[posc], &buffer);
                posc += lenc;
                lens = UnicodeToUTF16(buffer, utf16);
                if ( lens > 0 )
                  *((_WORD *)picon__[0][0] + poss++ + 4) = utf16[0];
                if ( lens > 1 )
                  *((_WORD *)picon__[0][0] + poss++ + 4) = utf16[1];
              }
              picon__[0][0][0] = (pbitmap)-1;
              picon__[0][0][1] = (pbitmap)(unsigned __int16)poss;
              *((_WORD *)picon__[0][0] + poss + 4) = 0;
              sprintf((char *)k__, "%ld", cheatc[2] - rank_);
              Window::drawtextxy_(
                (Window *const )thisa->pwint,
                (pbitmap)k__,
                (const char *)(leadid * thisa->helpw / 3),
                thisa->faceh + k * thisa->fontsh + thisa->menuh + 1,
                thisa->ctfg,
                thisa->cbg,
                v373);
              v55 = thisa->cbg;
              v56 = thisa->ctfg;
              v57 = thisa->fontsh;
              v58 = thisa->helpw / 3;
              v60 = v58
                  - Window::getstringwidth_((Window *const )"00000", v59)
                  - 4 * (thisa->digtw[1] * thisa->fontsh / thisa->digth[1]);
              v61 = thisa->faceh + k * thisa->fontsh + thisa->menuh + 1;
              v62 = leadid * thisa->helpw / 3;
              v64 = Window::getstringwidth_((Window *const )"00000", v63);
              Window::drawtextxy_(
                (Window *const )thisa->pwint,
                (pbitmap)&picon__[0][0][2],
                (const __int16 *)(v62 + v64),
                v61,
                v60,
                v57,
                v56,
                v55,
                0,
                v380);
              Window::paintnumber(
                thisa,
                (Window *const )cheatc[3],
                4,
                (leadid + 1) * thisa->helpw / 3 - 4 * (thisa->digtw[1] * thisa->fontsh / thisa->digth[1]),
                thisa->faceh + k * thisa->fontsh + thisa->menuh,
                thisa->digtw[1] * thisa->fontsh / thisa->digth[1],
                thisa->fontsh,
                1,
                v65);
            }
            Window::setfontweight_(0, v356);
          }
        }
        Window::setfontheight_((Window *const )thisa->fonth, v356);
        pface__[0] = thisa->pface[1];
        pface__[1] = thisa->pface[3];
        pface__[2] = thisa->piconf;
        scr__[0] = thisa->bd.st.scrfour;
        scr__[1] = thisa->bd.st.scrdead;
        scr__[2] = thisa->bd.st.scrtotal;
        n__[0] = 0;
        n__[1] = 0;
        n__[2] = 1;
        for ( k_0 = 0; k_0 <= 2; ++k_0 )
        {
          score = *((_DWORD *)&thisa->menuw + scr__[k_0] + 384);
          if ( thisa->singleb )
          {
            if ( !k_0 )
              score = thisa->bd.tetrisi;
            if ( k_0 == 1 )
              score = thisa->bd.missi;
          }
          DrawBMP(
            pface__[k_0],
            (2 * k_0 + 1) * thisa->helpw / 6 - 2 * thisa->digtw[0] - thisa->facew - thisa->digtw[0] * n__[k_0],
            thisa->menuh + (thisa->helph + 20 * thisa->fontsh - thisa->okh_) / 2 + 1,
            thisa->facew,
            thisa->faceh,
            thisa->cfg);
          Window::paintnumber(
            thisa,
            (Window *const )score,
            n__[k_0] + 4 + (*((_DWORD *)&thisa->menuw + scr__[k_0] + 384) > 9999) * (k_0 <= 1),
            (2 * k_0 + 1) * thisa->helpw / 6 - 2 * thisa->digtw[0] + thisa->facew - thisa->digtw[0] * n__[k_0],
            thisa->menuh + (thisa->helph + 20 * thisa->fontsh - thisa->okh_) / 2 + 1,
            2 * thisa->singleb * (k_0 <= 1),
            v66);
        }
        Line(thisa->helpw / 3, thisa->menuh, 0, thisa->helph - thisa->okh_, thisa->cline);
        Line(2 * (thisa->helpw / 3), thisa->menuh, 0, thisa->helph - thisa->okh_, thisa->cline);
        Line(0, thisa->menuh, thisa->helpw, 0, thisa->cline);
        Line(0, thisa->menuh + thisa->faceh, thisa->helpw, 0, thisa->cline);
        Line(0, thisa->menuh + thisa->faceh + 10 * thisa->fontsh, thisa->helpw, 0, thisa->cline);
        Line(0, thisa->menuh + thisa->faceh + 20 * thisa->fontsh, thisa->helpw, 0, thisa->cline);
        k_[0] = 3;
        k_[1] = 0;
        k_[2] = 5;
        k_[3] = 4;
        k_[4] = 6;
        for ( k_1 = 0; k_1 <= 4; ++k_1 )
        {
          v67 = thisa->faceh;
          v68 = thisa->facew;
          v69 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
          v70 = thisa->facew * k_1
              + ((thisa->helpw + thisa->okw) / 2 + thisa->helpw) / 2
              + ((signed int)(((unsigned int)(-5 * thisa->facew) >> 31) - 5 * thisa->facew) >> 1);
          v71 = GetWin();
          DrawBMP(*((pbitmap *)&thisa->launchh + (thisa->lead_5 == k_1) + 2 * k_[k_1] + 60), v71, v70, v69, v68, v67);
        }
        Window::setfontheight_((Window *const )thisa->faceh, v357);
        v72 = thisa->cbg;
        v73 = thisa->ctfg;
        v74 = thisa->faceh;
        v75 = thisa->helpw + (thisa->helpw + thisa->okw) / -2;
        v76 = thisa->menuh + thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->faceh;
        v77 = (thisa->helpw + thisa->okw) / 2;
        v79 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->lead_5 + thisa->bd.st.lan.LAN_MODE), v78);
        Window::drawtextxy_(
          (Window *const )thisa->pwint,
          (pbitmap)v79,
          (const __int16 *)v77,
          v76,
          v75,
          v74,
          v73,
          v72,
          v375);
        Window::setfontheight_((Window *const )thisa->fonth, v80);
      }
      else
      {
LABEL_42:
        Window::setfontheight_((Window *const )thisa->faceh, v355);
        v81 = thisa->cbg;
        v82 = thisa->ctfg;
        v83 = thisa->faceh;
        v84 = thisa->helpw;
        v86 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP + 8), v85);
        Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v86, 0, 0, v84, v83, v82, v81, v375);
        Window::setfontheight_((Window *const )thisa->fonth, v87);
        memset(cheatn, 0, 0x28u);
        cheatn[0] = *((const char **)&thisa->titleh + thisa->bd.sd.soundb + 48);
        cheatn[1] = *((const char **)&thisa->launchh + thisa->bd.sd.musicb + 52);
        cheatn[2] = *((const char **)&thisa->launchh + 2 * (thisa->md + 30));
        cheatn[4] = (const char *)thisa->pface[8];
        cheatn[5] = (const char *)thisa->pface[7];
        cheatn[7] = (const char *)thisa->picon[0];
        cheatn[8] = (const char *)thisa->picon[0];
        v387 = *((_DWORD *)&thisa->titleh + thisa->singleb + 56);
        cheats[0] = (const char *)10;
        cheats[1] = (const char *)11;
        cheats[2] = (const char *)12;
        cheats[3] = 0;
        cheats[4] = (const char *)17;
        cheats[5] = (const char *)14;
        cheats[6] = 0;
        cheats[7] = (const char *)18;
        cheats[8] = (const char *)19;
        v389 = 13;
        cheatc[0] = 2;
        cheatc[1] = 2;
        cheatc[2] = 2;
        cheatc[3] = 2;
        cheatc[4] = 3;
        cheatc[5] = 3;
        cheatc[6] = 3;
        cheatc[7] = 2;
        cheatc[8] = 2;
        v391 = 2;
        memset(k__, 0, 0x78u);
        k__[0][0] = thisa->bd.sd.soundb;
        k__[0][1] = !thisa->bd.sd.soundb;
        k__[1][0] = thisa->bd.sd.musicb;
        k__[1][1] = !thisa->bd.sd.musicb;
        k__[2][0] = thisa->md == 0;
        k__[2][1] = thisa->md == 1;
        v393 = (pbitmap)(thisa->md == 2);
        v394 = (pbitmap)(thisa->md == 3);
        v396 = thisa->mult_ == 0;
        v397 = thisa->mult_ == 1;
        v398 = (pbitmap)(thisa->mult_ > 1);
        v399 = (pbitmap)(thisa->colori == 0);
        v400 = (pbitmap)(thisa->colori == 1);
        v401 = thisa->colori == 2;
        v402 = thisa->colori == 3;
        v403 = thisa->colori == 4;
        v404 = thisa->colori == 5;
        v405 = thisa->bd.delayb == 1;
        v406 = thisa->bd.delayb == 0;
        v407 = thisa->barb;
        v408 = !thisa->barb;
        v409 = !thisa->singleb;
        v410 = thisa->singleb;
        psettingicon[0] = thisa->piconc;
        psettingicon[1] = thisa->piconf;
        qmemcpy(picon__, &unk_427220, 0x78u);
        helpw__ = thisa->iconw;
        helph__ = (long double)(thisa->helph - thisa->okh_ - 2 * thisa->iconh - thisa->faceh) / 9.0;
        for ( k_2 = 0; k_2 <= 9; ++k_2 )
        {
          if ( cheatn[k_2] )
            DrawBMP(
              (pbitmap)cheatn[k_2],
              helpw__,
              (signed __int64)((long double)k_2 * helph__
                             + (long double)(signed int)thisa->menuh
                             + (long double)(signed int)thisa->iconh),
              thisa->facew,
              thisa->faceh,
              thisa->cfg);
          if ( k_2 != 3 && k_2 != 6 )
          {
            v88 = thisa->cbg;
            v89 = thisa->ctfg;
            v90 = thisa->faceh;
            v91 = thisa->helpw / 4 - thisa->facew - 2 * thisa->iconw;
            v92 = (signed int)((long double)k_2 * helph__
                             + (long double)(signed int)thisa->menuh
                             + (long double)(signed int)thisa->iconh);
            v93 = (const __int16 *)(helpw__ + thisa->facew + thisa->iconw);
            v94 = Lan::getlan((int)&thisa->bd.st, (Lan *const )&cheats[k_2][thisa->bd.st.lan.LAN_HELP], v355);
            Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v94, v93, v92, v91, v90, v89, v88, 0, v380);
          }
          for ( j = 0; cheatc[k_2] > j; ++j )
          {
            DrawBMP(
              psettingicon[k__[0][j + 3 * k_2]],
              thisa->helpw / 4 * (j + 1),
              (signed __int64)((long double)k_2 * helph__
                             + (long double)(signed int)thisa->menuh
                             + (long double)(signed int)thisa->iconh),
              thisa->facew,
              thisa->faceh,
              thisa->cfg);
            if ( k_2 != 4 || j != 2 )
            {
              v100 = thisa->cbg;
              v101 = thisa->ctfg;
              v102 = thisa->faceh;
              v103 = thisa->helpw / 4 - thisa->facew - 2 * thisa->iconw;
              v104 = (signed int)((long double)k_2 * helph__
                                + (long double)(signed int)thisa->menuh
                                + (long double)(signed int)thisa->iconh);
              v105 = (const __int16 *)(thisa->facew + (j + 1) * (thisa->helpw / 4) + thisa->iconw);
              v106 = Lan::getlan(
                       (int)&thisa->bd.st,
                       (Lan *const )((char *)picon__[0][0][3 * k_2 + j] + thisa->bd.st.lan.LAN_SET),
                       v358);
              Window::drawtextxy_(
                (Window *const )thisa->pwint,
                (pbitmap)v106,
                v105,
                v104,
                v103,
                v102,
                v101,
                v100,
                0,
                v380);
            }
            else
            {
              DrawBMP(
                thisa->parrowm,
                3 * (thisa->helpw / 4) + thisa->facew,
                (signed __int64)((long double)k_2 * helph__
                               + (long double)(signed int)thisa->menuh
                               + (long double)(signed int)thisa->iconh),
                thisa->facew,
                thisa->faceh,
                thisa->cfg);
              DrawBMP(
                thisa->parrowp,
                (j + 1) * (thisa->helpw / 4) + 2 * thisa->facew,
                (signed __int64)((long double)k_2 * helph__
                               + (long double)(signed int)thisa->menuh
                               + (long double)(signed int)thisa->iconh),
                thisa->facew,
                thisa->faceh,
                thisa->cfg);
              v95 = thisa->cbg;
              v96 = thisa->ctfg;
              y = thisa->faceh;
              w = thisa->helpw / 4 - thisa->facew - 2 * thisa->iconw;
              yd = (signed int)((long double)k_2 * helph__
                              + (long double)(signed int)thisa->menuh
                              + (long double)(signed int)thisa->iconh);
              v97 = (const __int16 *)((j + 1) * (thisa->helpw / 4) + 3 * thisa->facew + thisa->iconw);
              v98 = thisa->mult_;
              if ( v98 < 2 )
                v98 = 2;
              v99 = Lan::getlan(
                      (int)&thisa->bd.st,
                      (Lan *const )((char *)picon__[0][0][3 * k_2 + j] + thisa->bd.st.lan.LAN_SET + v98 - 2),
                      v359);
              Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v99, v97, yd, w, y, v96, v95, 0, v380);
            }
          }
        }
        if ( thisa->bd.delayb == 1 )
          Line(
            helpw__,
            (signed int)(helph__ * 7.0
                       + (long double)(signed int)thisa->menuh
                       + (long double)(signed int)thisa->iconh
                       + (long double)(thisa->faceh / 2)),
            thisa->facew,
            0,
            thisa->cred);
        if ( thisa->barb )
          Bar(
            helpw__,
            (signed int)(helph__ * 8.0 + (long double)(signed int)thisa->menuh + (long double)(signed int)thisa->iconh),
            thisa->facew - 1,
            thisa->faceh - 1,
            thisa->ctfg,
            thisa->transparent);
      }
      break;
    case 0xFFFFFFFF:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v2 = thisa->cbg;
      v3 = thisa->ctfg;
      v4 = thisa->faceh;
      v5 = thisa->aboutw;
      v7 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP + 7), v6);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v7, 0, 0, v5, v4, v3, v2, v375);
      Window::setfontheight_((Window *const )thisa->fontfh, v8);
      pcheat__[0] = thisa->piconn;
      pcheat__[1] = thisa->piconm;
      prelax__[0] = thisa->pface[5];
      prelax__[1] = thisa->picone;
      DrawBMP(
        pcheat__[(unsigned __int8)thisa->cheatb],
        (thisa->aboutw - thisa->fontfh) / 2 + thisa->fontfh / -2,
        (thisa->fontth - thisa->fontfh) / 2 + thisa->menuh,
        thisa->fontfh,
        thisa->fontfh,
        thisa->cbg);
      DrawBMP(
        prelax__[(unsigned __int8)thisa->bd.relaxb],
        (thisa->aboutw - thisa->fontfh) / 2 + thisa->fontfh / 2,
        (thisa->fontth - thisa->fontfh) / 2 + thisa->menuh,
        thisa->fontfh,
        thisa->fontfh,
        thisa->cbg);
      Window::setfontheight_((Window *const )thisa->fonth, v9);
      v10 = thisa->cbg;
      v11 = thisa->ctfg;
      v12 = thisa->fonth;
      v13 = thisa->aboutw;
      v14 = thisa->menuh + thisa->fontth;
      v16 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_NAME, v15);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v16, 0, v14, v13, v12, v11, v10, v17);
      v18 = thisa->cbg;
      v19 = thisa->ctfg;
      v20 = thisa->fonth;
      v21 = thisa->aboutw;
      v22 = thisa->fontth + thisa->menuh + thisa->fonth;
      v24 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_VERSION, v23);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v24, 0, v22, v21, v20, v19, v18, v25);
      v26 = thisa->cbg;
      v27 = thisa->ctfg;
      v28 = thisa->fonth;
      v29 = thisa->aboutw;
      v30 = thisa->fontth + thisa->menuh + 2 * thisa->fonth;
      v32 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_AUTHOR, v31);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v32, 0, v30, v29, v28, v27, v26, v33);
      v34 = thisa->cbg;
      v35 = thisa->ctfg;
      v36 = thisa->fonth;
      v37 = thisa->aboutw;
      v38 = thisa->menuh + thisa->fontth + 3 * thisa->fonth;
      v40 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_LICENSE, v39);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v40, 0, v38, v37, v36, v35, v34, v41);
      break;
    case 1:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v107 = thisa->cbg;
      v108 = thisa->ctfg;
      v109 = thisa->faceh;
      v110 = thisa->helpw;
      v112 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP + 6), v111);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v112, 0, 0, v110, v109, v108, v107, v375);
      v113 = thisa->cbg;
      v114 = thisa->ctfg;
      v115 = (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2;
      v116 = thisa->helpw / 2;
      v117 = thisa->menuh;
      v118 = thisa->helpw / 2;
      v120 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_HELP_TITLE, v119);
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        (pbitmap)v120,
        (const __int16 *)v118,
        v117,
        v116,
        v115,
        v114,
        v113,
        v121);
      Window::setfontheight_((Window *const )thisa->fonth, v122);
      k__[0][0] = (int)thisa->pmenu1[0];
      k__[0][1] = (int)thisa->pmenu2[0];
      k__[0][2] = (int)thisa->pmenu3[0];
      k__[1][0] = (int)thisa->pface[4];
      k__[1][1] = (int)thisa->pface[0];
      k__[1][2] = (int)thisa->picone;
      k__[2][0] = (int)thisa->pmenuq[0];
      k__[2][1] = (int)thisa->pmenua[0];
      k__[2][2] = (int)thisa->pmenud[0];
      v393 = thisa->pmenut[0];
      v394 = thisa->pmenus[0];
      v395 = thisa->pmenum[0];
      v396 = *((_DWORD *)&thisa->launchh + 2 * (thisa->md + 30));
      v397 = *((_DWORD *)&thisa->titleh + thisa->singleb + 56);
      v398 = thisa->pface[7];
      v399 = thisa->pface[6];
      v400 = thisa->pface[5];
      qmemcpy(picon__, &off_4272A0, 0x44u);
      cheatn[0] = (const char *)a4567890vc;
      cheatn[1] = (_BYTE *)(a4567890vc + 2);
      cheatn[2] = (_BYTE *)(a4567890vc + 4);
      cheatn[3] = (_BYTE *)(a4567890vc + 6);
      cheatn[4] = (_BYTE *)(a4567890vc + 8);
      cheatn[5] = (_BYTE *)(a4567890vc + 10);
      cheatn[6] = (_BYTE *)(a4567890vc + 12);
      cheatn[7] = (_BYTE *)(a4567890vc + 14);
      cheatn[8] = (_BYTE *)(a4567890vc + 16);
      cheats[0] = "Auto Number";
      cheats[1] = "Auto Solve";
      cheats[2] = "Repeat Number";
      cheats[3] = "Repeat Solve";
      cheats[4] = "Repeat All";
      cheats[5] = "Auto Blank";
      cheats[6] = "Del Line";
      cheats[7] = "Up Level";
      cheats[8] = "Reset Steam";
      cheatc[0] = thisa->cblue;
      cheatc[1] = thisa->cblue;
      cheatc[2] = thisa->cblue;
      cheatc[3] = thisa->cblue;
      cheatc[4] = thisa->cblue;
      cheatc[5] = thisa->cblue;
      cheatc[6] = thisa->cblue;
      cheatc[7] = thisa->cred;
      cheatc[8] = thisa->cred;
      helpw___0 = thisa->iconw;
      helph___0 = (long double)(thisa->helph - thisa->okh_ - thisa->iconh - thisa->faceh) / 16.0;
      for ( k_3 = 0; k_3 <= 16; ++k_3 )
      {
        DrawBMP(
          (pbitmap)k__[0][k_3],
          helpw___0,
          (signed __int64)((long double)k_3 * helph___0
                         + (long double)(signed int)thisa->menuh
                         + (long double)(thisa->iconh / 2)),
          thisa->facew,
          thisa->faceh,
          thisa->cfg);
        Window::drawtextxy_(
          (Window *const )thisa->pwint,
          picon__[0][0][k_3],
          (const char *)(helpw___0 + thisa->facew + thisa->iconw),
          (signed int)((long double)k_3 * helph___0
                     + (long double)(signed int)thisa->menuh
                     + (long double)(thisa->iconh / 2)),
          thisa->ctfg,
          thisa->cbg,
          v374);
      }
      if ( thisa->cheatb == 1 )
      {
        for ( k_5 = 0; k_5 <= 8; ++k_5 )
        {
          Window::drawtextxy_(
            (Window *const )thisa->pwint,
            (pbitmap)cheatn[k_5],
            (const char *)(thisa->helpw / 4),
            (signed int)((long double)k_5 * helph___0
                       + (long double)(signed int)thisa->menuh
                       + (long double)(thisa->iconh / 2)),
            cheatc[k_5],
            thisa->cbg,
            v374);
          Window::drawtextxy_(
            (Window *const )thisa->pwint,
            (pbitmap)cheats[k_5],
            (const char *)(thisa->helpw / 4 + thisa->facew),
            (signed int)((long double)k_5 * helph___0
                       + (long double)(signed int)thisa->menuh
                       + (long double)(thisa->iconh / 2)),
            cheatc[k_5],
            thisa->cbg,
            v130);
        }
      }
      else
      {
        for ( k_4 = 0; k_4 <= 16; ++k_4 )
        {
          v123 = thisa->cbg;
          v124 = thisa->ctfg;
          v125 = thisa->faceh;
          v126 = thisa->helpw / 4;
          v127 = (signed int)((long double)k_4 * helph___0
                            + (long double)(signed int)thisa->menuh
                            + (long double)(thisa->iconh / 2));
          v128 = thisa->helpw / 4;
          v129 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(k_4 + thisa->bd.st.lan.LAN_HELP), v360);
          Window::drawtextxy_(
            (Window *const )thisa->pwint,
            (pbitmap)v129,
            (const __int16 *)v128,
            v127,
            v126,
            v125,
            v124,
            v123,
            0,
            v380);
        }
      }
      Line(thisa->helpw / 2, thisa->menuh, 0, thisa->helph - thisa->okh_, thisa->cline);
      for ( k_6 = 0; k_6 <= 11; ++k_6 )
        Window::paintline(
          thisa,
          (Window *const )thisa->piconn,
          thisa->piconc,
          (pbitmap)2,
          10,
          (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2,
          (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + (k_6 + 8) * thisa->iconh,
          v374);
      v131 = thisa->cbg;
      v132 = thisa->cred;
      v133 = 8 * thisa->iconh + thisa->menuh + (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 - thisa->faceh;
      v134 = 3 * thisa->helpw / 2;
      v135 = Window::getstringwidth_((Window *const )"PgUp", v361);
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        (pbitmap)"PgUp",
        (const char *)((v134 - v135) >> 1),
        v133,
        v132,
        v131,
        v374);
      v136 = thisa->cfg;
      v137 = thisa->cblue;
      v138 = thisa->menuh + (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + 8 * thisa->iconh;
      v139 = 3 * thisa->helpw / 2;
      v141 = Window::getstringwidth_((Window *const )"PgDn", v140);
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        (pbitmap)"PgDn",
        (const char *)((v139 - v141) >> 1),
        v138,
        v137,
        v136,
        v142);
      Bar(
        2 * thisa->iconw + (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 - thisa->arroww,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cmine);
      Bar(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 2 * thisa->iconw,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      Bar(
        (3 * thisa->helpw / 2 - thisa->arroww) / 2,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 20 * thisa->iconh - thisa->arrowh,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      Bar(
        (3 * thisa->helpw / 2 - thisa->arroww) / 2,
        20 * thisa->iconh + (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh,
        thisa->arroww,
        thisa->arrowh,
        thisa->cbg);
      Bar(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 12 * thisa->iconw - thisa->arroww,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      Bar(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 12 * thisa->iconw,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cbg);
      DrawBMP(
        thisa->parrowm,
        2 * thisa->iconw + (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 - thisa->arroww,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      DrawBMP(
        thisa->parrowp,
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 2 * thisa->iconw,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      DrawBMP(
        thisa->parrowu,
        (3 * thisa->helpw / 2 - thisa->arroww) / 2,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 20 * thisa->iconh - thisa->arrowh,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      DrawBMP(
        thisa->parrowd,
        (3 * thisa->helpw / 2 - thisa->arroww) / 2,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 20 * thisa->iconh,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      DrawBMP(
        thisa->parrowl,
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 12 * thisa->iconw - thisa->arroww,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      DrawBMP(
        thisa->parrowr,
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 12 * thisa->iconw,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 15 * thisa->iconh + thisa->arrowh / -2,
        thisa->arroww,
        thisa->arrowh,
        thisa->cfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh - 1,
        12 * thisa->iconw,
        0,
        thisa->ctfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2,
        thisa->menuh + (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + 8 * thisa->iconh - 1,
        12 * thisa->iconw,
        0,
        thisa->ctfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + 20 * thisa->iconh - 1,
        12 * thisa->iconw,
        0,
        thisa->ctfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 - 1,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh,
        0,
        20 * thisa->iconh,
        thisa->ctfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 2 * thisa->iconw - 1,
        (thisa->helph - thisa->okh_ - 4 * thisa->iconh) / 2 + thisa->menuh,
        0,
        12 * thisa->iconh,
        thisa->ctfg);
      Line(
        (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2 + 12 * thisa->iconw - 1,
        (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh,
        0,
        20 * thisa->iconh,
        thisa->ctfg);
      break;
    case 2:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v143 = thisa->cbg;
      v144 = thisa->ctfg;
      v145 = thisa->faceh;
      v146 = thisa->helpw;
      v148 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_TITLE + 1), v147);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v148, 0, 0, v146, v145, v144, v143, v375);
      Window::setfontheight_((Window *const )thisa->fontmh, v149);
      for ( j_0 = 0; j_0 <= 2; ++j_0 )
      {
        for ( i = 0; i <= 3; ++i )
        {
          Block::initbl(v353);
          v150 = j_0;
          if ( j_0 > 0 )
            v150 = 1;
          j_ = v150;
          if ( j_0 == 1 )
          {
            if ( i == 1 || i == 3 )
              (*thisa->bl.flag)[j_ + 128] = 1;
          }
          else if ( j_0 == 2 )
          {
            if ( i == 1 )
              (*thisa->bl.qstn)[j_ + 128] = 1;
          }
          else if ( !j_0 && (i == 1 || i == 3) )
          {
            (*thisa->bl.blck)[j_ + 128] = 1;
          }
          if ( i == 2 )
            (*thisa->bl.qstn)[j_ + 128] = 1;
          Window::paintboard(
            thisa,
            (Window *)((char *)thisa + 3304),
            (Block *const )((2 * i + 1) * thisa->helpw / 8 + thisa->bl.w * thisa->iconw / -2),
            (2 * j_0 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->bl.h * thisa->iconh / -2,
            1,
            j_,
            v371);
        }
      }
      for ( i_0 = 0; i_0 <= 2; ++i_0 )
      {
        for ( j_1 = 0; j_1 <= 2; ++j_1 )
        {
          picon__[0][0][0] = thisa->piconc;
          picon__[0][0][1] = thisa->picona;
          picon__[0][0][2] = thisa->picon[3];
          picon__[0][0][3] = thisa->piconp;
          picon__[0][0][4] = thisa->piconp;
          picon__[0][1][0] = thisa->piconp;
          picon__[0][1][1] = thisa->piconp;
          picon__[0][1][2] = thisa->piconp;
          picon__[0][1][3] = thisa->piconp;
          picon__[0][1][4] = thisa->piconp;
          picon__[0][2][0] = thisa->piconq;
          picon__[0][2][1] = thisa->picona;
          picon__[0][2][2] = thisa->picon[3];
          picon__[0][2][3] = thisa->piconp;
          picon__[0][2][4] = thisa->piconp;
          picon__[1][0][0] = thisa->piconc;
          picon__[1][0][1] = thisa->picona;
          picon__[1][0][2] = thisa->piconm;
          picon__[1][0][3] = thisa->picona;
          picon__[1][0][4] = thisa->piconf;
          picon__[1][1][0] = thisa->piconp;
          picon__[1][1][1] = thisa->piconp;
          picon__[1][1][2] = thisa->piconp;
          picon__[1][1][3] = thisa->piconp;
          picon__[1][1][4] = thisa->piconp;
          picon__[1][2][0] = thisa->piconq;
          picon__[1][2][1] = thisa->picona;
          picon__[1][2][2] = thisa->piconm;
          picon__[1][2][3] = thisa->picona;
          picon__[1][2][4] = thisa->piconf;
          picon__[2][0][0] = thisa->piconc;
          picon__[2][0][1] = thisa->picona;
          picon__[2][0][2] = thisa->piconq;
          picon__[2][0][3] = thisa->piconp;
          picon__[2][0][4] = thisa->piconp;
          picon__[2][1][0] = thisa->piconp;
          picon__[2][1][1] = thisa->piconp;
          picon__[2][1][2] = thisa->piconp;
          picon__[2][1][3] = thisa->piconp;
          picon__[2][1][4] = thisa->piconp;
          picon__[2][2][0] = thisa->piconq;
          picon__[2][2][1] = thisa->picona;
          picon__[2][2][2] = thisa->piconc;
          picon__[2][2][3] = thisa->piconp;
          picon__[2][2][4] = thisa->piconp;
          *(_QWORD *)&k__[0][0] = 3LL;
          k__[0][2] = 3;
          *(_QWORD *)&k__[1][0] = 5LL;
          k__[1][2] = 5;
          *(_QWORD *)&k__[2][0] = 3LL;
          k__[2][2] = 3;
          if ( i_0 && i_0 != 2 || j_1 == 2 )
          {
            if ( (!i_0 || i_0 == 2) && j_1 == 2 )
              DrawBMP(
                thisa->pclickr,
                2 * (i_0 + 1) * thisa->helpw / 8 + thisa->clickw / -2,
                -3 * thisa->iconh + 5 * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cfg);
          }
          else
          {
            DrawBMP(
              thisa->pclickl,
              2 * (i_0 + 1) * thisa->helpw / 8 + thisa->clickw / -2,
              -3 * thisa->iconh + (2 * j_1 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
              thisa->cfg);
          }
          for ( k_7 = 0; k__[0][i_0 + 3 * j_1] > k_7; ++k_7 )
          {
            if ( picon__[0][0][5 * i_0 + 15 * j_1 + k_7] == thisa->picona )
              DrawBMP(
                picon__[0][0][5 * i_0 + 15 * j_1 + k_7],
                2 * (i_0 + 1) * thisa->helpw / 8 + thisa->iconw * (2 * k_7 - k__[0][i_0 + 3 * j_1]) / 2,
                thisa->clickh + -3 * thisa->iconh + (2 * j_1 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cfg);
            else
              DrawBMP(
                picon__[0][0][5 * i_0 + 15 * j_1 + k_7],
                2 * (i_0 + 1) * thisa->helpw / 8 + thisa->iconw * (2 * k_7 - k__[0][i_0 + 3 * j_1]) / 2,
                thisa->clickh + -3 * thisa->iconh + (2 * j_1 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cbg);
          }
          if ( !i_0 || i_0 == 2 )
          {
            v151 = thisa->cbg;
            v152 = thisa->ctfg;
            v153 = 2 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 - thisa->clickh;
            v154 = thisa->helpw / 2;
            v155 = thisa->menuh
                 + thisa->clickh
                 + -3 * thisa->iconh
                 + (2 * j_1 + 1) * (thisa->helph - thisa->okh_) / 6
                 + thisa->iconh;
            v156 = i_0 / 2 * thisa->helpw / 2;
            v157 = Lan::getlan(
                     (int)&thisa->bd.st,
                     (Lan *const )(2 * j_1 + thisa->bd.st.lan.LAN_HELP_MENU + i_0 / 2),
                     v362);
            Window::drawtextxy_(
              (Window *const )thisa->pwint,
              (pbitmap)v157,
              (const __int16 *)v156,
              v155,
              v154,
              v153,
              v152,
              v151,
              v375);
          }
        }
      }
      Line(thisa->helpw / 2, thisa->menuh, 0, thisa->helph - thisa->okh_, thisa->cline);
      for ( k_8 = 1; k_8 <= 2; ++k_8 )
        Line(0, thisa->menuh + k_8 * (thisa->helph - thisa->okh_) / 3, thisa->helpw, 0, thisa->cline);
      Window::setfontheight_((Window *const )thisa->fonth, v363);
      break;
    case 3:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v158 = thisa->cbg;
      v159 = thisa->ctfg;
      v160 = thisa->faceh;
      v161 = thisa->helpw;
      v163 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_TITLE + 2), v162);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v163, 0, 0, v161, v160, v159, v158, v375);
      Window::setfontheight_((Window *const )thisa->fontmh, v164);
      for ( j_2 = 0; j_2 <= 2; ++j_2 )
      {
        for ( i_1 = 0; i_1 <= 3; ++i_1 )
        {
          Block::initbl(v354);
          (*thisa->bl.blck)[128] = 1;
          (*thisa->bl.flag)[129] = 1;
          j__0 = 2;
          switch ( j_2 )
          {
            case 1:
              (*thisa->bl.flag)[129] = 1;
              if ( !i_1 )
                (*thisa->bl.qstn)[1] = 1;
              if ( i_1 > 0 )
              {
                (*thisa->bl.blck)[2] = 1;
                (*thisa->bl.blck)[3] = 1;
              }
              if ( i_1 == 2 )
                (*thisa->bl.flag)[1] = 1;
              break;
            case 2:
              (*thisa->bl.flag)[129] = 1;
              if ( !i_1 )
                (*thisa->bl.qstn)[3] = 1;
              if ( i_1 > 0 )
              {
                (*thisa->bl.blck)[2] = 1;
                (*thisa->bl.flag)[1] = 1;
              }
              if ( i_1 == 2 )
                (*thisa->bl.blck)[3] = 1;
              break;
            case 0:
              if ( i_1 <= 1 )
                j__0 = 0;
              if ( !i_1 )
                (*thisa->bl.qstn)[1] = 1;
              if ( i_1 > 0 )
              {
                *(_BYTE *)thisa->bl.flag = 1;
                (*thisa->bl.flag)[1] = 1;
              }
              if ( i_1 == 3 )
              {
                (*thisa->bl.blck)[2] = 1;
                (*thisa->bl.blck)[3] = 1;
              }
              break;
          }
          if ( !j_2 || i_1 <= 2 )
            Window::paintboard(
              thisa,
              (Window *)((char *)thisa + 3304),
              (Block *const )((2 * i_1 + 1 + (j_2 != 0)) * thisa->helpw / 8 + thisa->bl.w * thisa->iconw / -2),
              (2 * j_2 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->bl.h * thisa->iconh / -2,
              1,
              j__0,
              v372);
        }
      }
      for ( i_2 = 0; i_2 <= 2; ++i_2 )
      {
        for ( j_3 = 0; j_3 <= 2; ++j_3 )
        {
          memset(picon__, 0, 0xF0u);
          *(_QWORD *)&picon__[0][0][0] = *(_QWORD *)&thisa->piconc;
          picon__[0][0][2] = thisa->piconf;
          picon__[0][0][3] = thisa->piconu;
          picon__[0][0][4] = thisa->picon[3];
          picon__[0][1][0] = thisa->piconp;
          picon__[0][1][1] = thisa->piconp;
          picon__[0][1][2] = thisa->piconp;
          picon__[0][1][3] = thisa->piconp;
          picon__[0][1][4] = thisa->piconp;
          picon__[0][2][0] = thisa->piconf;
          picon__[0][2][1] = thisa->piconu;
          picon__[0][2][2] = thisa->picon[2];
          picon__[0][2][3] = thisa->piconp;
          picon__[0][2][4] = thisa->piconp;
          *(_QWORD *)&picon__[1][1][0] = *(_QWORD *)&thisa->piconq;
          picon__[1][1][2] = thisa->piconu;
          picon__[1][1][3] = thisa->picon[2];
          picon__[1][1][4] = thisa->piconp;
          *(_QWORD *)&picon__[1][2][0] = *(_QWORD *)&thisa->piconc;
          picon__[1][2][2] = thisa->piconf;
          picon__[1][2][3] = thisa->piconu;
          picon__[1][2][4] = thisa->picon[2];
          picon__[2][0][0] = thisa->piconp;
          picon__[2][0][1] = thisa->piconp;
          picon__[2][0][2] = thisa->piconp;
          picon__[2][0][3] = thisa->piconp;
          picon__[2][0][4] = thisa->piconp;
          *(_QWORD *)&picon__[2][2][0] = *(_QWORD *)&thisa->piconq;
          picon__[2][2][2] = thisa->piconu;
          picon__[2][2][3] = thisa->picon[2];
          picon__[2][2][4] = thisa->piconp;
          v412 = thisa->piconf;
          v413 = thisa->piconu;
          v414 = thisa->picon[2];
          v415 = thisa->piconp;
          v416 = thisa->piconp;
          v417 = thisa->piconp;
          v418 = thisa->piconp;
          v419 = thisa->piconp;
          v420 = thisa->piconp;
          v421 = thisa->piconp;
          *(_QWORD *)&k__[0][0] = 5LL;
          k__[0][2] = 3;
          *(_QWORD *)&k__[1][0] = 21474836484LL;
          k__[1][2] = 0;
          *(_QWORD *)&k__[2][0] = 12884901892LL;
          k__[2][2] = 0;
          if ( i_2 && (i_2 != 2 || j_3) )
          {
            if ( i_2 == 1 && j_3 )
              DrawBMP(
                thisa->pclickn,
                (2 * (i_2 + 1) + (j_3 != 0)) * thisa->helpw / 8 + thisa->clickw / -2,
                -3 * thisa->iconh + (2 * j_3 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cfg);
          }
          else
          {
            DrawBMP(
              thisa->pclicka,
              (2 * (i_2 + 1) + (j_3 != 0)) * thisa->helpw / 8 + thisa->clickw / -2,
              -3 * thisa->iconh + (2 * j_3 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
              thisa->cfg);
          }
          for ( k_9 = 0; k__[0][i_2 + 3 * j_3] > k_9; ++k_9 )
          {
            if ( picon__[0][0][20 * j_3 + 5 * i_2 + k_9] == thisa->piconu )
              DrawBMP(
                picon__[0][0][20 * j_3 + 5 * i_2 + k_9],
                (2 * (i_2 + 1) + (j_3 != 0)) * thisa->helpw / 8 + thisa->iconw * (2 * k_9 - k__[0][i_2 + 3 * j_3]) / 2,
                thisa->clickh + -3 * thisa->iconh + (2 * j_3 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cfg);
            else
              DrawBMP(
                picon__[0][0][20 * j_3 + 5 * i_2 + k_9],
                (2 * (i_2 + 1) + (j_3 != 0)) * thisa->helpw / 8 + thisa->iconw * (2 * k_9 - k__[0][i_2 + 3 * j_3]) / 2,
                thisa->clickh + -3 * thisa->iconh + (2 * j_3 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->menuh,
                thisa->cbg);
          }
          if ( (!i_2 || i_2 == 2) && !j_3 )
          {
            v165 = thisa->cbg;
            v166 = thisa->ctfg;
            v167 = 2 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 - thisa->clickh;
            v168 = thisa->helpw / 2;
            v169 = thisa->menuh + thisa->clickh + -3 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 + thisa->iconh;
            v170 = i_2 / 2 * thisa->helpw / 2;
            v171 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + i_2 / 2 + 6), v364);
            Window::drawtextxy_(
              (Window *const )thisa->pwint,
              (pbitmap)v171,
              (const __int16 *)v170,
              v169,
              v168,
              v167,
              v166,
              v165,
              v375);
          }
          if ( !i_2 && j_3 > 0 )
          {
            v172 = thisa->cbg;
            v173 = thisa->ctfg;
            v174 = 2 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 - thisa->clickh;
            v175 = thisa->helpw;
            v176 = thisa->menuh
                 + thisa->clickh
                 + -3 * thisa->iconh
                 + (2 * j_3 + 1) * (thisa->helph - thisa->okh_) / 6
                 + thisa->iconh;
            v177 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + j_3 + 7), v364);
            Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v177, 0, v176, v175, v174, v173, v172, v375);
          }
        }
      }
      Line(thisa->helpw / 2, thisa->menuh, 0, (thisa->helph - thisa->okh_) / 3, thisa->cline);
      for ( k_10 = 1; k_10 <= 2; ++k_10 )
        Line(0, thisa->menuh + k_10 * (thisa->helph - thisa->okh_) / 3, thisa->helpw, 0, thisa->cline);
      break;
    case 4:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v178 = thisa->cbg;
      v179 = thisa->ctfg;
      v180 = thisa->faceh;
      v181 = thisa->helpw;
      v183 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_TITLE + 3), v182);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v183, 0, 0, v181, v180, v179, v178, v375);
      Window::setfontheight_((Window *const )thisa->fontmh, v184);
      iconwl = 5;
      iconwm = 18;
      iconwr = 20;
      iconwn = 34;
      iconh1 = 2;
      iconh2 = 10;
      iconh3 = 21;
      Window::paintline(
        thisa,
        (Window *const )thisa->picone,
        (pbitmap)2,
        20 * thisa->iconw,
        2 * thisa->iconh + thisa->menuh,
        v185);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        (pbitmap)0xC,
        20 * thisa->iconw,
        3 * thisa->iconh + thisa->menuh,
        v186);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        (pbitmap)0xC,
        20 * thisa->iconw,
        4 * thisa->iconh + thisa->menuh,
        v187);
      Window::paintline(
        thisa,
        (Window *const )thisa->picone,
        (pbitmap)2,
        5 * thisa->iconw,
        4 * thisa->iconh + thisa->menuh,
        v188);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconm,
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)5,
        1,
        1,
        5,
        5 * thisa->iconw,
        5 * thisa->iconh + thisa->menuh,
        v381);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconf,
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)5,
        1,
        1,
        5,
        20 * thisa->iconw,
        5 * thisa->iconh + thisa->menuh,
        v189);
      DrawBMP(thisa->picona, 18 * thisa->iconw, 5 * thisa->iconh + thisa->menuh, thisa->cfg);
      DrawBMP(
        thisa->pface[3],
        18 * thisa->iconw + (thisa->facew - thisa->iconw) / -2,
        thisa->menuh + 5 * thisa->iconh - thisa->iconh + thisa->faceh / -2,
        thisa->cfg);
      v190 = thisa->cbg;
      v191 = thisa->ctfg;
      v192 = 2 * thisa->iconh;
      v193 = thisa->helpw;
      v194 = 6 * thisa->iconh + thisa->menuh;
      v196 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 10), v195);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v196, 0, v194, v193, v192, v191, v190, v197);
      for ( k_11 = 0; k_11 <= 2; ++k_11 )
      {
        Window::paintline(
          thisa,
          (Window *const )thisa->picone,
          (pbitmap)2,
          iconwl * thisa->iconw,
          (3 * k_11 + iconh2) * thisa->iconh + thisa->menuh,
          v367);
        Window::paintline(
          thisa,
          (Window *const )thisa->picone,
          (pbitmap)(k_11 + 3),
          iconwr * thisa->iconw,
          (3 * k_11 + iconh2) * thisa->iconh + thisa->menuh,
          v198);
        Window::paintline(
          thisa,
          (Window *const )thisa->piconc,
          (pbitmap)0xC,
          iconwl * thisa->iconw,
          (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->menuh,
          v199);
        Window::paintline(
          thisa,
          (Window *const )thisa->piconc,
          (pbitmap)0xC,
          iconwr * thisa->iconw,
          (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->menuh,
          v200);
        Window::paintnumber(
          thisa,
          (Window *const )(5 * k_11),
          2,
          iconwn * thisa->iconw,
          thisa->menuh + (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->digth[0] / -2,
          v201);
        DrawBMP(thisa->picona, iconwm * thisa->iconw, (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->menuh, thisa->cfg);
      }
      v202 = thisa->cbg;
      v203 = thisa->ctfg;
      v204 = (iconh3 - iconh2 - 10) * thisa->iconh + thisa->iconh / 2;
      v205 = thisa->helpw;
      v206 = thisa->iconh * (iconh2 + 8) + thisa->menuh;
      v207 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 11), v365);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v207, 0, v206, v205, v204, v203, v202, v376);
      Window::paintline(
        thisa,
        (Window *const )thisa->picone,
        (pbitmap)0xC,
        iconwl * thisa->iconw,
        iconh3 * thisa->iconh + thisa->menuh,
        v208);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        (pbitmap)0xC,
        iconwr * thisa->iconw,
        iconh3 * thisa->iconh + thisa->menuh,
        v209);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        (pbitmap)0xC,
        iconwl * thisa->iconw,
        thisa->iconh * (iconh3 + 1) + thisa->menuh,
        v210);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        (pbitmap)0xC,
        iconwr * thisa->iconw,
        thisa->iconh * (iconh3 + 1) + thisa->menuh,
        v211);
      DrawBMP(thisa->picona, iconwm * thisa->iconw, thisa->iconh * (iconh3 + 1) + thisa->menuh, thisa->cfg);
      v212 = thisa->cbg;
      v213 = thisa->ctfg;
      v214 = thisa->helph - thisa->okh_ - (iconh3 + 2) * thisa->iconh;
      v215 = thisa->helpw;
      v216 = thisa->iconh * (iconh3 + 2) + thisa->menuh;
      v218 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 12), v217);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v218, 0, v216, v215, v214, v213, v212, v219);
      Line(0, thisa->menuh + (iconh2 - 2) * thisa->iconh, thisa->helpw, 0, thisa->cline);
      Line(0, (iconh3 - 2) * thisa->iconh + thisa->menuh + thisa->iconh / 2, thisa->helpw, 0, thisa->cline);
      Window::setfontheight_((Window *const )thisa->fonth, v220);
      break;
    case 5:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v221 = thisa->cbg;
      v222 = thisa->ctfg;
      v223 = thisa->faceh;
      v224 = thisa->helpw;
      v226 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_TITLE + 4), v225);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v226, 0, 0, v224, v223, v222, v221, v375);
      Window::setfontheight_((Window *const )thisa->fontmh, v227);
      iconwl_0 = 3;
      iconwm_0 = 16;
      iconwr_0 = 20;
      iconwn_0 = 34;
      iconh1_0 = 2;
      iconh2_0 = 6;
      iconh3_0 = 11;
      iconh4 = 22;
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->picon[2],
        thisa->piconp,
        (pbitmap)4,
        1,
        7,
        3 * thisa->iconw,
        thisa->iconh / -2 + 2 * thisa->iconh + thisa->menuh,
        v228);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconf,
        thisa->picon[2],
        thisa->piconp,
        (pbitmap)2,
        2,
        1,
        7,
        3 * thisa->iconw,
        thisa->iconh / -2 + 3 * thisa->iconh + thisa->menuh,
        v381);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconf,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)2,
        1,
        1,
        1,
        7,
        3 * thisa->iconw,
        thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh,
        (int)thisa->piconp);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)4,
        1,
        7,
        20 * thisa->iconw,
        thisa->iconh / -2 + 3 * thisa->iconh + thisa->menuh,
        v229);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconf,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)2,
        1,
        1,
        1,
        7,
        20 * thisa->iconw,
        thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh,
        (int)thisa->piconp);
      Line(
        3 * thisa->iconw,
        thisa->menuh + thisa->iconh / 2 + thisa->iconh / -2 + 3 * thisa->iconh,
        12 * thisa->iconw,
        0,
        thisa->cred);
      DrawBMP(thisa->piconf, 16 * thisa->iconw, thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh, thisa->cbg);
      DrawBMP(thisa->piconu, 17 * thisa->iconw, thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh, thisa->cfg);
      DrawBMP(thisa->piconn, 18 * thisa->iconw, thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh, thisa->cbg);
      DrawBMP(
        thisa->pface[4],
        17 * thisa->iconw + (thisa->facew - thisa->iconw) / -2,
        thisa->menuh + thisa->iconh / -2 + 4 * thisa->iconh - thisa->iconh + thisa->faceh / -2,
        thisa->cbg);
      Window::paintnumber(
        thisa,
        (Window *const )1,
        4,
        34 * thisa->iconw,
        thisa->menuh + thisa->iconh / -2 + 4 * thisa->iconh + thisa->digth[0] / -2,
        v230);
      v231 = thisa->cbg;
      v232 = thisa->ctfg;
      v233 = 3 * thisa->iconh / 2;
      v234 = thisa->helpw;
      v235 = thisa->iconh / -2 + 5 * thisa->iconh + thisa->menuh;
      v237 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 13), v236);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v237, 0, v235, v234, v233, v232, v231, v238);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->picon[2],
        thisa->piconp,
        (pbitmap)4,
        1,
        7,
        3 * thisa->iconw,
        6 * thisa->iconh + thisa->menuh,
        v239);
      Window::paintline(
        thisa,
        (Window *const )thisa->picon[1],
        thisa->picon[4],
        thisa->piconc,
        thisa->picon[2],
        thisa->piconp,
        (pbitmap)1,
        1,
        2,
        1,
        7,
        3 * thisa->iconw,
        7 * thisa->iconh + thisa->menuh,
        (int)thisa->piconp);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->piconc,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)2,
        1,
        1,
        1,
        7,
        3 * thisa->iconw,
        8 * thisa->iconh + thisa->menuh,
        (int)thisa->piconp);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)4,
        1,
        7,
        20 * thisa->iconw,
        7 * thisa->iconh + thisa->menuh,
        v240);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconc,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        (pbitmap)3,
        1,
        1,
        7,
        20 * thisa->iconw,
        8 * thisa->iconh + thisa->menuh,
        v241);
      Line(3 * thisa->iconw, thisa->menuh + thisa->iconh / 2 + 7 * thisa->iconh, 12 * thisa->iconw, 0, thisa->cred);
      DrawBMP(thisa->piconc, 16 * thisa->iconw, 8 * thisa->iconh + thisa->menuh, thisa->cbg);
      DrawBMP(thisa->piconu, 17 * thisa->iconw, 8 * thisa->iconh + thisa->menuh, thisa->cfg);
      DrawBMP(thisa->piconn, 18 * thisa->iconw, 8 * thisa->iconh + thisa->menuh, thisa->cbg);
      DrawBMP(
        thisa->pface[4],
        17 * thisa->iconw + (thisa->facew - thisa->iconw) / -2,
        thisa->menuh + 8 * thisa->iconh - thisa->iconh + thisa->faceh / -2,
        thisa->cbg);
      Window::paintnumber(
        thisa,
        (Window *const )1,
        4,
        34 * thisa->iconw,
        thisa->menuh + 8 * thisa->iconh + thisa->digth[0] / -2,
        v242);
      v243 = thisa->cbg;
      v244 = thisa->ctfg;
      v245 = 3 * thisa->iconh / 2;
      v246 = thisa->helpw;
      v247 = 9 * thisa->iconh + thisa->menuh;
      v249 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 14), v248);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v249, 0, v247, v246, v245, v244, v243, v250);
      Window::paintline(
        thisa,
        (Window *const )thisa->piconp,
        (pbitmap)0xC,
        3 * thisa->iconw,
        thisa->iconh / -2 + 15 * thisa->iconh + thisa->menuh,
        v251);
      Line(
        3 * thisa->iconw,
        thisa->menuh + thisa->iconh / 2 + thisa->iconh / -2 + 15 * thisa->iconh,
        12 * thisa->iconw,
        0,
        thisa->cred);
      for ( k_12 = 0; k_12 <= 7; ++k_12 )
      {
        if ( k_12 > 4 )
          Window::paintline(
            thisa,
            (Window *const )thisa->piconc,
            (pbitmap)0xC,
            iconwl_0 * thisa->iconw,
            thisa->iconh / -2 + thisa->iconh * (iconh3_0 + k_12) + thisa->menuh,
            v368);
        if ( k_12 > 0 )
          Window::paintline(
            thisa,
            (Window *const )thisa->piconc,
            (pbitmap)0xC,
            iconwr_0 * thisa->iconw,
            thisa->iconh / -2 + thisa->iconh * (iconh3_0 + k_12) + thisa->menuh,
            v368);
      }
      DrawBMP(
        thisa->picona,
        (iconwm_0 + 1) * thisa->iconw,
        thisa->iconh / -2 + thisa->iconh * (iconh3_0 + 7) + thisa->menuh,
        thisa->cfg);
      DrawBMP(
        thisa->pface[1],
        thisa->iconw * (iconwm_0 + 1) + (thisa->facew - thisa->iconw) / -2,
        thisa->menuh + thisa->iconh / -2 + thisa->iconh * (iconh3_0 + 7) - thisa->iconh + thisa->faceh / -2,
        thisa->cfg);
      Window::paintnumber(
        thisa,
        (Window *const )5,
        4,
        iconwn_0 * thisa->iconw,
        thisa->menuh + thisa->iconh / -2 + thisa->iconh * (iconh3_0 + 7) + thisa->digth[0] / -2,
        v368);
      v252 = thisa->cbg;
      v253 = thisa->ctfg;
      v254 = 3 * thisa->iconh / 2;
      v255 = thisa->helpw;
      v256 = thisa->iconh / -2 + thisa->iconh * (iconh3_0 + 8) + thisa->menuh;
      v258 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 15), v257);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v258, 0, v256, v255, v254, v253, v252, v377);
      for ( k_13 = 0; k_13 <= 2; ++k_13 )
      {
        Window::paintnumber(
          thisa,
          (Window *const )((k_13 + 2) * (k_13 + 2)),
          4,
          (2 * k_13 + 1) * thisa->helpw / 6 - 4 * thisa->digtw[0] + thisa->iconw / -2,
          thisa->menuh + iconh4 * thisa->iconh + thisa->digth[0] / -2,
          v369);
        Window::paintnumber(
          thisa,
          (Window *const )(k_13 + 2),
          2,
          2 * thisa->digtw[0] + (2 * k_13 + 1) * thisa->helpw / 6 + thisa->iconw / 2,
          thisa->menuh + iconh4 * thisa->iconh + thisa->digth[0] / -2,
          v259);
        DrawBMP(
          thisa->picona,
          thisa->digtw[0] + (2 * k_13 + 1) * thisa->helpw / 6 + thisa->iconw / -2,
          thisa->menuh + iconh4 * thisa->iconh + thisa->iconh / -2,
          thisa->cfg);
      }
      v260 = thisa->cbg;
      v261 = thisa->ctfg;
      v262 = thisa->helph - thisa->okh_ - (iconh4 * thisa->iconh + thisa->digth[0] / 2);
      v263 = thisa->helpw;
      v264 = thisa->digth[0] / 2 + iconh4 * thisa->iconh + thisa->menuh;
      v265 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 16), v366);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v265, 0, v264, v263, v262, v261, v260, v378);
      Line(0, thisa->menuh + thisa->iconh * (iconh3_0 - 1) + thisa->iconh / 2, thisa->helpw, 0, thisa->cline);
      Line(0, thisa->iconh * (iconh4 - 2) + thisa->menuh, thisa->helpw, 0, thisa->cline);
      Window::setfontheight_((Window *const )thisa->fonth, v266);
      break;
    case 6:
      Window::setfontheight_(*(Window *const *)(v1 + 28), v355);
      v267 = thisa->cbg;
      v268 = thisa->ctfg;
      v269 = thisa->faceh;
      v270 = thisa->helpw;
      v272 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_TITLE + 5), v271);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v272, 0, 0, v270, v269, v268, v267, v375);
      Window::setfontheight_((Window *const )thisa->fontmh, v273);
      for ( i_3 = 0; i_3 <= 31; ++i_3 )
      {
        for ( j_4 = 0; j_4 <= 23; ++j_4 )
          DrawBMP(
            thisa->piconp,
            (i_3 + 4) * thisa->iconw,
            thisa->menuh + thisa->iconh / 2 + j_4 * thisa->iconh,
            thisa->cfg);
      }
      for ( j_5 = 0; j_5 <= 23; ++j_5 )
      {
        if ( j_5 <= 11 )
          v274 = 2;
        else
          v274 = 3;
        if ( j_5 <= 15 )
          v275 = 0;
        else
          v275 = 3;
        Window::paintline(
          thisa,
          (Window *const )thisa->piconn,
          (pbitmap)(v274 + v275),
          5 * thisa->iconw,
          thisa->iconh / 2 + thisa->menuh + (j_5 + 1) * thisa->iconh - thisa->iconh,
          v370);
      }
      for ( j_6 = 0; j_6 <= 23; ++j_6 )
        DrawBMP(
          *((pbitmap *)&thisa->titlew + j_6 % 10 + 85),
          4 * thisa->iconw,
          j_6 * thisa->iconh + thisa->iconh / 2 + thisa->menuh,
          thisa->cbg);
      for ( i_4 = 0; i_4 <= 31; ++i_4 )
        DrawBMP(
          *((pbitmap *)&thisa->titlew + i_4 % 10 + 85),
          (i_4 + 4) * thisa->iconw,
          thisa->iconh / 2 + thisa->menuh,
          thisa->cbg);
      DrawBMP(
        thisa->pmenu1[0],
        16 * thisa->iconw - thisa->menuw,
        thisa->iconh / 2 + thisa->menuh + 12 * thisa->iconh - thisa->menuh,
        thisa->cbg);
      DrawBMP(
        thisa->pmenu2[0],
        20 * thisa->iconw - thisa->menuw,
        16 * thisa->iconh + thisa->menuh + thisa->iconh / 2 - thisa->menuh,
        thisa->cbg);
      DrawBMP(
        thisa->pmenu3[0],
        36 * thisa->iconw - thisa->menuw,
        thisa->iconh / 2 + thisa->menuh + 24 * thisa->iconh - thisa->menuh,
        thisa->cbg);
      Line(4 * thisa->iconw, thisa->iconh / 2 + thisa->menuh + 12 * thisa->iconh - 1, 12 * thisa->iconw, 0, thisa->ctfg);
      Line(4 * thisa->iconw, thisa->menuh + thisa->iconh / 2 + 16 * thisa->iconh - 1, 16 * thisa->iconw, 0, thisa->ctfg);
      Line(4 * thisa->iconw, thisa->iconh / 2 + thisa->menuh + 24 * thisa->iconh - 1, 32 * thisa->iconw, 0, thisa->ctfg);
      Line(4 * thisa->iconw, thisa->iconh / 2 + thisa->menuh - 1, 32 * thisa->iconw, 0, thisa->ctfg);
      Line(16 * thisa->iconw - 1, thisa->menuh + thisa->iconh / 2, 0, 12 * thisa->iconh, thisa->ctfg);
      Line(20 * thisa->iconw - 1, thisa->iconh / 2 + thisa->menuh, 0, 16 * thisa->iconh, thisa->ctfg);
      Line(36 * thisa->iconw - 1, thisa->iconh / 2 + thisa->menuh, 0, 24 * thisa->iconh, thisa->ctfg);
      Line(4 * thisa->iconw - 1, thisa->menuh + thisa->iconh / 2, 0, 24 * thisa->iconh, thisa->ctfg);
      v276 = thisa->cfg;
      v277 = thisa->ctfg;
      v278 = thisa->fontmh;
      v279 = 15 * thisa->iconw - thisa->menuw;
      v280 = thisa->iconh / 2 + thisa->menuh + 12 * thisa->iconh - thisa->fontmh - 1;
      v281 = (const __int16 *)(5 * thisa->iconw);
      v283 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 17), v282);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v283, v281, v280, v279, v278, v277, v276, 0, v380);
      v284 = thisa->cfg;
      v285 = thisa->ctfg;
      v286 = thisa->fontmh;
      v287 = 15 * thisa->iconw - thisa->menuw;
      v288 = 16 * thisa->iconh + thisa->menuh + thisa->iconh / 2 - thisa->fontmh - 1;
      v289 = (const __int16 *)(5 * thisa->iconw);
      v291 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 18), v290);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v291, v289, v288, v287, v286, v285, v284, 0, v292);
      v293 = thisa->cfg;
      v294 = thisa->ctfg;
      v295 = thisa->fontmh;
      v296 = 15 * thisa->iconw - thisa->menuw;
      v297 = thisa->iconh / 2 + thisa->menuh + 24 * thisa->iconh - thisa->fontmh - 1;
      v298 = (const __int16 *)(5 * thisa->iconw);
      v300 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_HELP_MENU + 19), v299);
      Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v300, v298, v297, v296, v295, v294, v293, 0, v301);
      Window::setfontheight_((Window *const )thisa->fonth, v302);
      break;
    default:
      break;
  }
  if ( thisa->helpi == -1 )
  {
    Window::setfontheight_((Window *const )thisa->fonth, v355);
    v303 = thisa->okh;
    v304 = thisa->okw;
    v305 = (thisa->okh_ + thisa->okh) / -2 + thisa->abouth + thisa->menuh;
    v306 = (thisa->aboutw - thisa->okw) / 2;
    v307 = GetWin();
    DrawBMP(thisa->pok, v307, v306, v305, v304, v303);
    v308 = thisa->ctbg;
    v309 = thisa->ctfg;
    v310 = thisa->okh;
    v311 = thisa->okw;
    v312 = thisa->abouth + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh;
    v313 = (thisa->aboutw - thisa->okw) / 2;
    v315 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_OK, v314);
    Window::drawtextxy_(
      (Window *const )thisa->pwint,
      (pbitmap)v315,
      (const __int16 *)v313,
      v312,
      v311,
      v310,
      v309,
      v308,
      v375);
  }
  else if ( thisa->helpi )
  {
    Window::setfontheight_((Window *const )thisa->fonth, v355);
    v316 = thisa->okh;
    v317 = thisa->okw;
    v318 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
    v319 = (thisa->helpw - thisa->okw) / 2;
    v320 = GetWin();
    DrawBMP(thisa->pok, v320, v319, v318, v317, v316);
    v321 = thisa->ctbg;
    v322 = thisa->ctfg;
    v323 = thisa->okh;
    v324 = thisa->okw;
    v325 = thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh;
    v326 = (thisa->helpw - thisa->okw) / 2;
    v328 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_OK, v327);
    Window::drawtextxy_(
      (Window *const )thisa->pwint,
      (pbitmap)v328,
      (const __int16 *)v326,
      v325,
      v324,
      v323,
      v322,
      v321,
      v375);
    if ( thisa->helpi > 1 && thisa->helpi <= thisa->maxhelp )
    {
      v329 = thisa->btnh;
      v330 = thisa->btnw;
      v331 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
      v332 = (thisa->helpw - thisa->okw) / 2 - 2 * thisa->btnw;
      v333 = GetWin();
      DrawBMP(thisa->pbtn, v333, v332, v331, v330, v329);
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        (pbitmap)"<",
        (const char *)((thisa->helpw - thisa->okw) / 2 - 2 * thisa->btnw),
        thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh,
        thisa->btnw,
        thisa->btnh,
        thisa->ctfg,
        thisa->ctbg,
        v379);
    }
    if ( thisa->helpi > 0 && thisa->helpi < thisa->maxhelp )
    {
      v334 = thisa->btnh;
      v335 = thisa->btnw;
      v336 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
      v337 = (thisa->helpw + thisa->okw) / 2 + thisa->btnw;
      v338 = GetWin();
      DrawBMP(thisa->pbtn, v338, v337, v336, v335, v334);
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        &stru_4292A8,
        (const char *)((thisa->helpw + thisa->okw) / 2 + thisa->btnw),
        thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh,
        thisa->btnw,
        thisa->btnh,
        thisa->ctfg,
        thisa->ctbg,
        v379);
    }
    v339 = thisa->tuth;
    v340 = thisa->tutw;
    v341 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
    v342 = -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw;
    v343 = GetWin();
    DrawBMP(thisa->pok, v343, v342, v341, v340, v339);
    v344 = thisa->ctbg;
    v345 = thisa->ctfg;
    v346 = thisa->tuth;
    v347 = thisa->tutw;
    v348 = thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh;
    v349 = (const __int16 *)((thisa->helpw - thisa->okw) / 2 - 3 * thisa->btnw - thisa->tutw);
    v351 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_TUT_, v350);
    Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v351, v349, v348, v347, v346, v345, v344, v379);
    Line(0, thisa->menuh, thisa->helpw, 0, thisa->cline);
    Line(0, thisa->helph + thisa->menuh - thisa->okh_, thisa->helpw, 0, thisa->cline);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041D9A2; symbol: __ZN6Window8painttutEv
void __cdecl Window::painttut(Window *const this)
{
  int v1; // ecx
  int i; // ST4C_4
  int j; // ST48_4
  unsigned int cbg; // ST38_4
  unsigned int v5; // edi
  unsigned int v6; // esi
  int v7; // ebx
  bitmap *v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // ST38_4
  unsigned int w; // ST34_4
  int y; // ST30_4
  int v13; // ebx
  int v14; // esi
  int v15; // ST04_4
  __int16 *v16; // eax
  unsigned int v17; // ST38_4
  unsigned int v18; // edi
  unsigned int v19; // esi
  int v20; // ebx
  bitmap *v21; // eax
  unsigned int v22; // edi
  unsigned int v23; // ST38_4
  unsigned int v24; // ST34_4
  int v25; // ST30_4
  int v26; // ebx
  int v27; // esi
  int v28; // ST04_4
  __int16 *v29; // eax
  unsigned int v30; // esi
  unsigned int v31; // ST38_4
  int v32; // ST34_4
  int v33; // edi
  int v34; // ebx
  int v35; // ST04_4
  __int16 *v36; // eax
  unsigned int v37; // ST04_4
  unsigned int v38; // esi
  unsigned int v39; // ST38_4
  int v40; // ST34_4
  int v41; // edi
  int v42; // ebx
  __int16 *v43; // eax
  unsigned int v44; // edi
  unsigned int v45; // esi
  unsigned int v46; // ebx
  bitmap *v47; // eax
  unsigned int v48; // ST38_4
  unsigned int v49; // edi
  unsigned int v50; // esi
  unsigned int v51; // ebx
  bitmap *v52; // eax
  unsigned int v53; // esi
  unsigned int v54; // ST38_4
  unsigned int v55; // ST34_4
  int v56; // edi
  int v57; // ebx
  int v58; // ST04_4
  __int16 *v59; // eax
  unsigned int v60; // ST20_4
  unsigned int v61; // edi
  unsigned int v62; // ST38_4
  unsigned int v63; // ST34_4
  int v64; // ST30_4
  int v65; // ebx
  const __int16 *v66; // esi
  int v67; // ST04_4
  __int16 *v68; // eax
  unsigned int v69; // ST20_4
  unsigned int v70; // [esp+4h] [ebp-64h]
  unsigned int v71; // [esp+4h] [ebp-64h]
  int v72; // [esp+4h] [ebp-64h]
  unsigned int v73; // [esp+20h] [ebp-48h]
  unsigned int v74; // [esp+20h] [ebp-48h]
  unsigned int v75; // [esp+24h] [ebp-44h]
  Window *thisa; // [esp+3Ch] [ebp-2Ch]

  thisa = (Window *)v1;
  Window::setfontheight_(*(Window *const *)(v1 + 112), v70);
  if ( thisa->bd.tuti <= 12 )
  {
    i = *((_DWORD *)&thisa->titlew + thisa->bd.tuti + 760);
    j = *((_DWORD *)&thisa->titleh + thisa->bd.tuti + 772);
    Bar(
      i * thisa->iconw,
      thisa->faceh + thisa->menuh + j * thisa->iconh,
      thisa->iconw - 1,
      thisa->iconh - 1,
      thisa->cred,
      thisa->transparent);
    Bar(
      i * thisa->iconw + 1,
      thisa->menuh + j * thisa->iconh + thisa->faceh + 1,
      thisa->iconw - 3,
      thisa->iconh - 3,
      thisa->cred,
      thisa->transparent);
  }
  switch ( thisa->bd.tuti )
  {
    case 1:
      Bar(
        4 * thisa->iconw - 1,
        thisa->menuh + 15 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        4 * thisa->iconw - 2,
        thisa->menuh + 15 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        3 * (thisa->iconh + 1),
        thisa->cblue,
        thisa->transparent);
      break;
    case 2:
      Bar(
        3 * thisa->iconw - 1,
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 1,
        thisa->iconw + 1,
        thisa->iconh + 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        3 * thisa->iconw - 2,
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 2,
        thisa->iconw + 3,
        thisa->iconh + 3,
        thisa->cblue,
        thisa->transparent);
      break;
    case 3:
      Bar(
        9 * thisa->iconw,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh,
        thisa->iconw - 1,
        2 * thisa->iconh - 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        9 * thisa->iconw + 1,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh + 1,
        thisa->iconw - 3,
        2 * thisa->iconh - 3,
        thisa->cblue,
        thisa->transparent);
      Bar(
        9 * thisa->iconw - 1,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 1,
        thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        9 * thisa->iconw - 2,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 2,
        thisa->iconw + 3,
        3 * (thisa->iconh + 1),
        thisa->cgreen,
        thisa->transparent);
      break;
    case 4:
      Bar(
        7 * thisa->iconw - 1,
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        7 * thisa->iconw - 2,
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        3 * (thisa->iconh + 1),
        thisa->cblue,
        thisa->transparent);
      break;
    case 5:
      Bar(
        9 * thisa->iconw - 1,
        thisa->menuh + 19 * thisa->iconh + thisa->faceh - 1,
        thisa->iconw + 1,
        thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        9 * thisa->iconw - 2,
        thisa->menuh + 19 * thisa->iconh + thisa->faceh - 2,
        thisa->iconw + 3,
        thisa->iconh + 3,
        thisa->cgreen,
        thisa->transparent);
      break;
    case 6:
      Bar(
        8 * thisa->iconw - 1,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        8 * thisa->iconw - 2,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        3 * (thisa->iconh + 1),
        thisa->cgreen,
        thisa->transparent);
      break;
    case 7:
      Bar(
        9 * thisa->iconw - 1,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        9 * thisa->iconw - 2,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        3 * (thisa->iconh + 1),
        thisa->cgreen,
        thisa->transparent);
      break;
    case 8:
      Bar(
        2 * thisa->iconw,
        thisa->faceh + thisa->menuh + 18 * thisa->iconh,
        thisa->iconw - 1,
        2 * thisa->iconh - 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        2 * thisa->iconw + 1,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh + 1,
        thisa->iconw - 3,
        2 * thisa->iconh - 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        2 * thisa->iconw - 1,
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 1,
        thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        2 * (thisa->iconw - 1),
        thisa->menuh + 17 * thisa->iconh + thisa->faceh - 2,
        thisa->iconw + 3,
        3 * (thisa->iconh + 1),
        thisa->cgreen,
        thisa->transparent);
      break;
    case 0xA:
      Bar(
        2 * thisa->iconw - 1,
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        3 * thisa->iconh + 1,
        thisa->cgreen,
        thisa->transparent);
      Bar(
        2 * (thisa->iconw - 1),
        thisa->menuh + 16 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        3 * (thisa->iconh + 1),
        thisa->cgreen,
        thisa->transparent);
      break;
    case 0xB:
      Bar(
        2 * thisa->iconw - 1,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        2 * thisa->iconh + 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        2 * (thisa->iconw - 1),
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        2 * thisa->iconh + 3,
        thisa->cblue,
        thisa->transparent);
      Bar(
        -1,
        thisa->menuh + 6 * thisa->iconh + thisa->faceh - 1,
        12 * thisa->iconw + 1,
        2 * thisa->iconh + 1,
        thisa->cred,
        thisa->transparent);
      Bar(
        -2,
        thisa->menuh + 6 * thisa->iconh + thisa->faceh - 2,
        12 * thisa->iconw + 3,
        2 * thisa->iconh + 3,
        thisa->cred,
        thisa->transparent);
      break;
    case 0xC:
      Bar(
        thisa->iconw - 1,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 1,
        3 * thisa->iconw + 1,
        2 * thisa->iconh + 1,
        thisa->cblue,
        thisa->transparent);
      Bar(
        thisa->iconw - 2,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 2,
        3 * (thisa->iconw + 1),
        2 * thisa->iconh + 3,
        thisa->cblue,
        thisa->transparent);
      break;
    case 0xD:
      Bar(
        -1,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 1,
        12 * thisa->iconw + 1,
        2 * thisa->iconh + 1,
        thisa->cred,
        thisa->transparent);
      Bar(
        -2,
        thisa->menuh + 18 * thisa->iconh + thisa->faceh - 2,
        12 * thisa->iconw + 3,
        2 * thisa->iconh + 3,
        thisa->cred,
        thisa->transparent);
      Bar(0, thisa->menuh, 4 * thisa->digtw[0], thisa->digth[0], thisa->cred, thisa->transparent);
      Bar(1, thisa->menuh + 1, 4 * thisa->digtw[0] - 2, thisa->digth[0] - 2, thisa->cred, thisa->transparent);
      Bar(
        thisa->w_ - 2 * thisa->digtw[0],
        thisa->menuh,
        2 * thisa->digtw[0],
        thisa->digth[0],
        thisa->cred,
        thisa->transparent);
      Bar(
        thisa->w_ - 2 * thisa->digtw[0] + 1,
        thisa->menuh + 1,
        2 * (thisa->digtw[0] - 1),
        thisa->digth[0] - 2,
        thisa->cred,
        thisa->transparent);
      if ( thisa->bd.tutb <= 1 )
      {
        cbg = thisa->okh;
        v5 = thisa->okw;
        v6 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v7 = (12 * thisa->iconw - thisa->okw) / 2;
        v8 = GetWin();
        DrawBMP(thisa->pok, v8, v7, v6, v5, cbg);
        v9 = thisa->ctbg;
        v10 = thisa->ctfg;
        w = thisa->okh;
        y = thisa->okw;
        v13 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v14 = (12 * thisa->iconw - thisa->okw) / 2;
        v16 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_OK, v15);
        Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v16, (const __int16 *)v14, v13, y, w, v10, v9, v73);
      }
      break;
    case 0xE:
      Bar(
        thisa->w_ - 2 * thisa->digtw[0],
        thisa->menuh,
        2 * thisa->digtw[0],
        thisa->digth[0],
        thisa->cred,
        thisa->transparent);
      Bar(
        thisa->w_ - 2 * thisa->digtw[0] + 1,
        thisa->menuh + 1,
        2 * (thisa->digtw[0] - 1),
        thisa->digth[0] - 2,
        thisa->cred,
        thisa->transparent);
      Bar(
        -1,
        thisa->menuh + 7 * thisa->iconh + thisa->faceh - 1,
        12 * thisa->iconw + 1,
        thisa->iconh + 1,
        thisa->cred,
        thisa->transparent);
      Bar(
        -2,
        thisa->menuh + 7 * thisa->iconh + thisa->faceh - 2,
        12 * thisa->iconw + 3,
        thisa->iconh + 3,
        thisa->cred,
        thisa->transparent);
      if ( thisa->bd.tutb <= 1 )
      {
        v17 = thisa->okh;
        v18 = thisa->okw;
        v19 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v20 = (12 * thisa->iconw - thisa->okw) / 2;
        v21 = GetWin();
        DrawBMP(thisa->pok, v21, v20, v19, v18, v17);
        v22 = thisa->ctbg;
        v23 = thisa->ctfg;
        v24 = thisa->okh;
        v25 = thisa->okw;
        v26 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v27 = (12 * thisa->iconw - thisa->okw) / 2;
        v29 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_ABOUT_OK, v28);
        Window::drawtextxy_(
          (Window *const )thisa->pwint,
          (pbitmap)v29,
          (const __int16 *)v27,
          v26,
          v25,
          v24,
          v23,
          v22,
          v73);
      }
      break;
    default:
      break;
  }
  Window::setfontheight_((Window *const )thisa->fontsh, v71);
  v30 = thisa->cbg;
  v31 = thisa->ctfg;
  v32 = 8 * thisa->fontsh;
  v33 = 12 * thisa->iconw;
  v34 = thisa->menuh + thisa->faceh;
  v36 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.tuti + thisa->bd.st.lan.LAN_TUT), v35);
  Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v36, 0, v34, v33, v32, v31, v30, 0x10u, v75);
  Window::setfontheight_((Window *const )thisa->fonth, v37);
  if ( thisa->bd.tutb == 2 )
  {
    v38 = thisa->cbg;
    v39 = thisa->ctfg;
    v40 = 8 * thisa->fontsh;
    v41 = 12 * thisa->iconw;
    v42 = thisa->menuh + thisa->faceh;
    v43 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_TUT_QUIT, v72);
    Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v43, 0, v42, v41, v40, v39, v38, v74);
    v44 = thisa->okh;
    v45 = 6 * thisa->iconw - 1;
    v46 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v47 = GetWin();
    DrawBMP(thisa->pok, v47, 0, v46, v45, v44);
    v48 = thisa->okh;
    v49 = 6 * thisa->iconw - 1;
    v50 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v51 = 6 * thisa->iconw;
    v52 = GetWin();
    DrawBMP(thisa->pok, v52, v51, v50, v49, v48);
    v53 = thisa->ctbg;
    v54 = thisa->ctfg;
    v55 = thisa->okh;
    v56 = 6 * thisa->iconw - 1;
    v57 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v59 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_TUT_QUIT + 1), v58);
    Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v59, 0, v57, v56, v55, v54, v53, v60);
    v61 = thisa->ctbg;
    v62 = thisa->ctfg;
    v63 = thisa->okh;
    v64 = 6 * thisa->iconw - 1;
    v65 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v66 = (const __int16 *)(6 * thisa->iconw);
    v68 = Lan::getlan((int)&thisa->bd.st, (Lan *const )(thisa->bd.st.lan.LAN_TUT_QUIT + 2), v67);
    Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v68, v66, v65, v64, v63, v62, v61, v69);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041F3A8; symbol: __ZN6Window10painttitleEl
void __userpurge Window::painttitle(int a1@<ecx>, Window *const this, int load)
{
  unsigned int c; // ST3C_4
  unsigned int hd; // ST38_4
  unsigned int v5; // edi
  unsigned int v6; // esi
  int v7; // ebx
  bitmap *v8; // eax
  unsigned int v9; // ST04_4
  unsigned int v10; // esi
  unsigned int v11; // ST3C_4
  unsigned int v12; // ST38_4
  int v13; // edi
  int v14; // ebx
  int v15; // ST04_4
  __int16 *v16; // eax
  unsigned int v17; // esi
  unsigned int v18; // ST3C_4
  unsigned int v19; // ST38_4
  int v20; // edi
  int v21; // ebx
  int v22; // ST04_4
  __int16 *v23; // eax
  unsigned int v24; // ST04_4
  unsigned int v25; // ST3C_4
  unsigned int v26; // ST38_4
  unsigned int v27; // edi
  unsigned int v28; // esi
  bitmap *v29; // ebx
  bitmap *v30; // eax
  unsigned int v31; // esi
  unsigned int v32; // ebx
  bitmap *v33; // eax
  unsigned int v34; // edi
  unsigned int v35; // esi
  unsigned int v36; // ebx
  bitmap *v37; // eax
  unsigned int v38; // [esp+4h] [ebp-64h]
  unsigned int v39; // [esp+20h] [ebp-48h]
  unsigned int v40; // [esp+20h] [ebp-48h]
  unsigned int v41; // [esp+20h] [ebp-48h]
  Window *thisa; // [esp+4Ch] [ebp-1Ch]

  thisa = (Window *)a1;
  EnterCriticalSection((LPCRITICAL_SECTION)(a1 + 3560));
  painttitlec = this;
  Clear(thisa->cbg);
  Clear(thisa->pwint, thisa->transparent_);
  if ( (signed int)this < 0 )
    thisa->ptitle_ = LoadBMP("./data/png/title.png");
  c = thisa->cfg;
  hd = thisa->titleh;
  v5 = thisa->titlew;
  v6 = thisa->fontth;
  v7 = (thisa->launchw - thisa->titlew) / 2;
  v8 = GetWin();
  DrawBMP(thisa->ptitle_, v8, v7, v6, v5, hd, c);
  Window::setfontheight_((Window *const )thisa->fontfh, v9);
  v10 = thisa->cbg;
  v11 = thisa->ctfg;
  v12 = thisa->fontfh;
  v13 = thisa->launchw;
  v14 = thisa->fontth - thisa->fontfh;
  v16 = Lan::getlan((int)&thisa->bd.st, (Lan *const )thisa->bd.st.lan.LAN_TITLE, v15);
  Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v16, 0, v14, v13, v12, v11, v10, v39);
  if ( (signed int)this >= 0 )
  {
    Window::setfontheight_((Window *const )thisa->fontfh, v38);
    v17 = thisa->cbg;
    v18 = thisa->ctfg;
    v19 = thisa->fontfh;
    v20 = thisa->launchw;
    v21 = thisa->titleh + thisa->fontth + thisa->fontfh / -2;
    v23 = Lan::getlan((int)&thisa->bd.st, (Lan *const )this, v22);
    Window::drawtextxy_((Window *const )thisa->pwint, (pbitmap)v23, 0, v21, v20, v19, v18, v17, v40);
    Window::setfontheight_((Window *const )thisa->fonth, v24);
    if ( painttitles )
      Window::drawtextxy_(
        (Window *const )thisa->pwint,
        painttitles,
        0,
        thisa->titleh + thisa->fontth + thisa->fontfh / 2,
        thisa->launchw,
        thisa->fontfh,
        thisa->ctfg,
        thisa->cbg,
        v41);
  }
  Window::setfontheight_((Window *const )thisa->fonth, v38);
  if ( thisa->mult > 1.0 )
  {
    v25 = thisa->h_;
    v26 = thisa->w_;
    v27 = thisa->h_;
    v28 = thisa->w_;
    v29 = thisa->pwin;
    v30 = GetWin();
    DrawBMP(v30, v29, 0, 0, v28, v27, 0, 0, v26, v25);
    v31 = (signed __int64)((long double)thisa->h_ * thisa->mult);
    v32 = (signed __int64)((long double)thisa->w_ * thisa->mult);
    v33 = GetWin();
    DrawBMP(thisa->pwin, v33, 0, 0, v32, v31);
  }
  v34 = thisa->transparent_;
  v35 = (signed __int64)((long double)thisa->h_ * thisa->mult);
  v36 = (signed __int64)((long double)thisa->w_ * thisa->mult);
  v37 = GetWin();
  DrawBMP(thisa->pwint, v37, 0, 0, v36, v35, v34);
  FreshWin();
  LeaveCriticalSection((LPCRITICAL_SECTION)&thisa->cs);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041F8C4; symbol: __ZN6Window10painteventEb
void __userpurge Window::paintevent(int a1@<ecx>, Window *const this, bool freshb)
{
  Window *const v3; // ST00_4
  Window *const v4; // ST00_4
  Window *const v5; // ST00_4
  unsigned int hd; // ST34_4
  unsigned int wd; // ST30_4
  unsigned int v8; // edi
  unsigned int v9; // esi
  bitmap *v10; // ebx
  bitmap *v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // ebx
  bitmap *v14; // eax
  unsigned int v15; // edi
  unsigned int v16; // esi
  unsigned int v17; // ebx
  bitmap *v18; // eax
  Window *v19; // [esp+0h] [ebp-68h]
  Window *v20; // [esp+0h] [ebp-68h]
  Window *thisa; // [esp+4Ch] [ebp-1Ch]

  thisa = (Window *)a1;
  EnterCriticalSection((LPCRITICAL_SECTION)(a1 + 3560));
  Clear(thisa->cbg);
  Clear(thisa->pwint, thisa->transparent_);
  Window::paintmenu(v3);
  if ( thisa->helpi )
  {
    Window::painthelp(v19);
  }
  else
  {
    Window::paintface(v19);
    Window::paintlevel(v4);
    Window::paintboard(v5);
    if ( thisa->bd.tutb > 0 && !thisa->bd.pauseb )
      Window::painttut(v20);
  }
  if ( thisa->mult > 1.0 )
  {
    hd = thisa->h_;
    wd = thisa->w_;
    v8 = thisa->h_;
    v9 = thisa->w_;
    v10 = thisa->pwin;
    v11 = GetWin();
    DrawBMP(v11, v10, 0, 0, v9, v8, 0, 0, wd, hd);
    v12 = (signed __int64)((long double)thisa->h_ * thisa->mult);
    v13 = (signed __int64)((long double)thisa->w_ * thisa->mult);
    v14 = GetWin();
    DrawBMP(thisa->pwin, v14, 0, 0, v13, v12);
  }
  v15 = thisa->transparent_;
  v16 = (signed __int64)((long double)thisa->h_ * thisa->mult);
  v17 = (signed __int64)((long double)thisa->w_ * thisa->mult);
  v18 = GetWin();
  DrawBMP(thisa->pwint, v18, 0, 0, v17, v16, v15);
  if ( (_BYTE)this )
    FreshWin();
  LeaveCriticalSection((LPCRITICAL_SECTION)&thisa->cs);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FB7C; symbol: __ZN6Window10painteventEv
void __cdecl Window::paintevent(Window *const this)
{
  int v1; // ecx
  bool v2; // [esp+4h] [ebp-24h]

  Window::paintevent(v1, (Window *const )1, v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FB9C; symbol: __ZN6Window12paintrefreshEv
void __cdecl Window::paintrefresh(Window *const this)
{
  Window *v1; // ecx
  HWND__ *v2; // eax
  HWND__ *v3; // eax
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( GetTimeR() > v1->timerefresh + 0.1 )
  {
    v2 = GetHwnd();
    InvalidateRect(v2, 0, 0);
    v3 = GetHwnd();
    UpdateWindow(v3);
    thisa->timerefresh = GetTimeR();
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FC0A; symbol: __ZN6Window4isinEllllll
BOOL __userpurge Window::isin@<eax>(Window *const this, int ex, int ey, int x, int y, int w, int h)
{
  return (signed int)this > ey && ex > x && ey + y > (signed int)this && x + w > ex;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FC4E; symbol: __ZN6Window7sethelpEl
void __userpurge Window::sethelp(int a1@<ecx>, Window *const this, int helpi_)
{
  Board *v3; // [esp+0h] [ebp-38h]
  int v4; // [esp+4h] [ebp-34h]
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = (Window *)a1;
  *(_BYTE *)(a1 + 3532) = 0;
  if ( *(Window *const *)(a1 + 3376) != this || *(_DWORD *)(a1 + 3376) )
    Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2832), v4);
  if ( thisa->helpi > 0 && (signed int)this > 0 )
    this = (Window *const )thisa->helpi;
  if ( (Window *const )thisa->helpi != this && this )
  {
    if ( !thisa->helpi && thisa->bd.sit > 0 && !thisa->bd.pauseb && thisa->bd.sit <= 3 )
    {
      Board::pause(v3);
      thisa->bd.pauseb = 2;
    }
    thisa->helpi = (int)this;
  }
  else
  {
    if ( thisa->bd.pauseb == 2 && thisa->bd.sit > 0 && thisa->bd.sit <= 3 )
      Board::pause(v3);
    thisa->helpi = 0;
  }
  Window::initwindow(thisa, 0, v4);
  if ( thisa->helpi == -2 && thisa->waitb != 1 )
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)getlead, thisa, 0, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FDE0; symbol: __ZN6Window7savescrEv
void __cdecl Window::savescr(Window *const this)
{
  Window *v1; // ecx
  Window *v2; // ST2C_4
  char *v3; // eax
  char *v4; // eax
  bitmap *v5; // eax
  char *v6; // ST04_4
  int v7; // ST04_4
  char times[260]; // [esp+30h] [ebp-228h]
  time_t rawtime; // [esp+134h] [ebp-124h]
  char scrpath[260]; // [esp+138h] [ebp-120h]
  tm *timed; // [esp+23Ch] [ebp-1Ch]

  v2 = v1;
  GetTempPathA(0x104u, scrpath);
  v3 = &scrpath[strlen(scrpath)];
  *(_DWORD *)v3 = 1701995379;
  *((_DWORD *)v3 + 1) = 1752395365;
  *((_DWORD *)v3 + 2) = 6255727;
  time(&rawtime);
  timed = localtime(&rawtime);
  sprintf(
    times,
    "%d%d%d%d%d%d",
    timed->tm_mday,
    timed->tm_mon + 1,
    timed->tm_year + 1900,
    timed->tm_hour,
    timed->tm_min,
    timed->tm_sec);
  strcat(scrpath, times);
  v4 = &scrpath[strlen(scrpath)];
  *(_DWORD *)v4 = 1735290926;
  v4[4] = 0;
  v5 = GetWin();
  SaveBMP(v5, scrpath);
  Steam::savescr((int)&v2->bd.st, (Steam *const )scrpath, v6);
  Sound::playsound(&v2->bd.sd, (Sound *const )v2->bd.sd.sSolve, v7);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FF6A; symbol: __ZN6Window10switchskinEv
void __cdecl Window::switchskin(Window *const this)
{
  int v1; // ecx
  int v2; // [esp+4h] [ebp-24h]

  Window::switchskin((Window *const )((*(_DWORD *)(v1 + 688) + 1) % 6), v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FFAE; symbol: __ZN6Window10switchskinEl
void __userpurge Window::switchskin(Window *a1@<ecx>, Window *const this, int colori_)
{
  Window *v3; // ST1C_4
  Window *const v4; // ST00_4
  Window *v5; // [esp+0h] [ebp-28h]
  int v6; // [esp+4h] [ebp-24h]

  v3 = a1;
  a1->colori = (int)this;
  Window::initbmp(v5);
  Window::paintevent(v4);
  Sound::playsound(&v3->bd.sd, (Sound *const )v3->bd.sd.sRight, v6);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0041FFFC; symbol: __ZN6Window8switchmdEv
void __cdecl Window::switchmd(Window *const this)
{
  int v1; // ecx
  unsigned int v2; // eax
  int v3; // [esp+4h] [ebp-24h]

  v2 = (unsigned int)((*(_DWORD *)(v1 + 3516) + 1) >> 31) >> 30;
  Window::switchmd((Window *const )((((_BYTE)v2 + *(_BYTE *)(v1 + 3516) + 1) & 3) - v2), v3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00420038; symbol: __ZN6Window8switchmdEl
void __userpurge Window::switchmd(int a1@<ecx>, Window *const this, int md_)
{
  int v3; // [esp+4h] [ebp-24h]

  *(_DWORD *)(a1 + 3516) = this;
  if ( *(_DWORD *)(a1 + 3516) > 1 )
    *(_DWORD *)(a1 + 3024) = 0;
  Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2832), v3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0042008C; symbol: __ZN6Window8tuteventEllb
void __userpurge Window::tutevent(Window *a1@<ecx>, Window *const this, int ex, int ey, bool tutkb)
{
  int v5; // ST18_4
  int v6; // [esp+4h] [ebp-44h]
  int v7; // [esp+4h] [ebp-44h]
  int v8; // [esp+18h] [ebp-30h]
  int v9; // [esp+18h] [ebp-30h]
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  char tutmb_n; // [esp+3Dh] [ebp-Bh]
  char tutmb_y; // [esp+3Eh] [ebp-Ah]
  char tutmb; // [esp+3Fh] [ebp-9h]

  thisa = a1;
  tutmb = Window::isin(
            this,
            ex,
            (12 * thisa->iconw - thisa->okw) / 2,
            thisa->menuh + 10 * thisa->iconh + thisa->faceh,
            a1->okw,
            a1->okh,
            v8);
  if ( thisa->bd.tutb == 1 && (tutmb || (_BYTE)ey) )
  {
    if ( thisa->bd.tuti == 13 )
    {
      ++thisa->bd.maski;
      ++thisa->bd.tuti;
      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v6);
    }
    else if ( thisa->bd.tuti == 14 )
    {
      thisa->bd.tutb = 0;
      thisa->bd.time = GetTimeR();
      thisa->helpb = 0;
      Window::sethelp((int)thisa, (Window *const )1, v6);
    }
  }
  tutmb_y = Window::isin(
              this,
              ex,
              0,
              thisa->faceh + thisa->menuh + 10 * thisa->iconh,
              6 * thisa->iconw - 1,
              thisa->okh,
              v9);
  tutmb_n = Window::isin(
              this,
              ex,
              6 * thisa->iconw,
              thisa->menuh + 10 * thisa->iconh + thisa->faceh,
              6 * thisa->iconw - 1,
              thisa->okh,
              v5);
  if ( thisa->bd.tutb == 2 && (tutmb_y || tutmb_n || (_BYTE)ey) )
  {
    if ( tutmb_y || (_BYTE)ey )
    {
      thisa->bd.tutb = 0;
      thisa->bd.time = GetTimeR();
      thisa->helpb = 0;
      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v7);
    }
    if ( tutmb_n )
    {
      thisa->bd.tutb = 1;
      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v7);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00420374; symbol: __ZN6Window16mouseeventboard_Ellll
void __userpurge Window::mouseeventboard_(int a1@<ecx>, Window *const this, int x, int y, int eb_, int md_)
{
  bool v6; // al
  Window *v7; // [esp+0h] [ebp-38h]
  Window *v8; // [esp+0h] [ebp-38h]
  bool v9; // [esp+4h] [ebp-34h]
  int v10; // [esp+8h] [ebp-30h]
  int v11; // [esp+10h] [ebp-28h]
  Window *thisa; // [esp+1Ch] [ebp-1Ch]

  thisa = (Window *)a1;
  v6 = !*(_DWORD *)(a1 + 3040)
    || *(_DWORD *)(a1 + 3044) <= 12
    && *(Window *const *)(a1 + 4 * (*(_DWORD *)(a1 + 3044) + 760) + 8) == this
    && *(_DWORD *)(a1 + 4 * (*(_DWORD *)(a1 + 3044) + 772) + 12) == x
    && (y & *(_DWORD *)(a1 + 4 * (*(_DWORD *)(a1 + 3044) + 788))) > 0;
  if ( (*(Window *const *)(a1 + 3524) != this || *(_DWORD *)(a1 + 3528) != x) && v6 && *(_DWORD *)(a1 + 3040) <= 1 )
  {
    *(_DWORD *)(a1 + 3032) = this;
    *(_DWORD *)(a1 + 3036) = x;
    if ( y == 1 )
    {
      if ( !*(_DWORD *)(a1 + 780) && *(_DWORD *)(a1 + 788) <= x && eb_ > 2 )
        Board::resetbd((Board *)(a1 + 768), (Board *const )this, x, v10);
      Board::clickleft(&thisa->bd, (Board *const )this, x, 1, eb_, v11);
    }
    else if ( y == 2 )
    {
      Board::clickright((Board *)(a1 + 768), (Board *const )this, x, 1, eb_, v11);
    }
    Window::paintevent(v7);
    Board::checkline(&thisa->bd, (Board *const )1, v9);
    thisa->mx = (int)this;
    thisa->my = x;
    if ( thisa->bd.tutb > 0 )
      ++thisa->bd.tuti;
    Window::paintevent(v8);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00420566; symbol: __ZN6Window15mouseeventboardEllll
void __userpurge Window::mouseeventboard(int a1@<ecx>, Window *const this, int ex_, int ey_, int eb_, int md_)
{
  bool v6; // [esp+Ch] [ebp-2Ch]
  int v7; // [esp+10h] [ebp-28h]
  Window *thisa; // [esp+1Ch] [ebp-1Ch]
  int y; // [esp+20h] [ebp-18h]
  int x; // [esp+24h] [ebp-14h]
  signed int ey; // [esp+28h] [ebp-10h]
  int ex; // [esp+2Ch] [ebp-Ch]

  thisa = (Window *)a1;
  ex = (signed int)((long double)(signed int)this / *(double *)(a1 + 3408));
  ey = (signed int)((long double)ex_ / *(double *)(a1 + 3408));
  if ( ex >= 0
    && ey - *(_DWORD *)(a1 + 20) >= *(_DWORD *)(a1 + 28)
    && !*(_DWORD *)(a1 + 3376)
    && *(_DWORD *)(a1 + 780) <= 3
    && !*(_DWORD *)(a1 + 784) )
  {
    x = ex / *(_DWORD *)(a1 + 32);
    y = (ey - *(_DWORD *)(a1 + 28) - *(_DWORD *)(a1 + 20)) / *(_DWORD *)(a1 + 36);
    if ( x >= 0 && *(_DWORD *)(a1 + 768) > x && y >= 0 && *(_DWORD *)(a1 + 772) > y )
      Window::mouseeventboard_(a1, (Window *const )x, y, ey_, eb_, v7);
    Window::tutevent(thisa, (Window *const )ex, ey, 0, v6);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004206AE; symbol: __ZN6Window10mouseeventElll
void __userpurge Window::mouseevent(int a1@<ecx>, Window *const this, int ex_, int ey_, int eb_)
{
  bool v5; // ST04_1
  int v6; // ST04_4
  int v7; // ST04_4
  int v8; // ST04_4
  bool v9; // ST04_1
  bool v10; // ST04_1
  bool v11; // ST04_1
  int v12; // ST04_4
  int v13; // ST04_4
  int v14; // eax
  int v15; // ST04_4
  int v16; // eax
  int v17; // ST04_4
  Sound *v18; // [esp+0h] [ebp-68h]
  int v19; // [esp+4h] [ebp-64h]
  int v20; // [esp+4h] [ebp-64h]
  int v21; // [esp+4h] [ebp-64h]
  int v22; // [esp+4h] [ebp-64h]
  int v23; // [esp+4h] [ebp-64h]
  int v24; // [esp+4h] [ebp-64h]
  int v25; // [esp+4h] [ebp-64h]
  int v26; // [esp+4h] [ebp-64h]
  int v27; // [esp+4h] [ebp-64h]
  int v28; // [esp+4h] [ebp-64h]
  int v29; // [esp+4h] [ebp-64h]
  int v30; // [esp+4h] [ebp-64h]
  int v31; // [esp+4h] [ebp-64h]
  int v32; // [esp+4h] [ebp-64h]
  bool v33; // [esp+4h] [ebp-64h]
  bool v34; // [esp+4h] [ebp-64h]
  int v35; // [esp+8h] [ebp-60h]
  int v36; // [esp+8h] [ebp-60h]
  int v37; // [esp+8h] [ebp-60h]
  int v38; // [esp+8h] [ebp-60h]
  int v39; // [esp+10h] [ebp-58h]
  int v40; // [esp+18h] [ebp-50h]
  int v41; // [esp+18h] [ebp-50h]
  int v42; // [esp+18h] [ebp-50h]
  int v43; // [esp+18h] [ebp-50h]
  int v44; // [esp+18h] [ebp-50h]
  int v45; // [esp+18h] [ebp-50h]
  int v46; // [esp+18h] [ebp-50h]
  int v47; // [esp+18h] [ebp-50h]
  Window *thisa; // [esp+2Ch] [ebp-3Ch]
  double helph__; // [esp+38h] [ebp-30h]
  signed int ey; // [esp+40h] [ebp-28h]
  int ex; // [esp+44h] [ebp-24h]
  int j; // [esp+48h] [ebp-20h]
  int k; // [esp+4Ch] [ebp-1Ch]

  thisa = (Window *)a1;
  ex = (signed int)((long double)(signed int)this / *(double *)(a1 + 3408));
  ey = (signed int)((long double)ex_ / *(double *)(a1 + 3408));
  if ( *(_DWORD *)(a1 + 20) <= ey )
  {
    if ( *(_DWORD *)(a1 + 3376) )
    {
      if ( *(_DWORD *)(a1 + 3376) == -1 )
      {
        if ( (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                (*(_DWORD *)(a1 + 88) - *(_DWORD *)(a1 + 64)) / 2,
                                *(_DWORD *)(a1 + 20)
                              + (*(_DWORD *)(a1 + 124) + *(_DWORD *)(a1 + 68)) / -2
                              + *(_DWORD *)(a1 + 92),
                                *(_DWORD *)(a1 + 64),
                                *(_DWORD *)(a1 + 68),
                                v40) )
          Window::sethelp((int)thisa, 0, v20);
        if ( (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                (thisa->aboutw - thisa->fontfh) / 2 + thisa->fontfh / -2,
                                (thisa->fontth - thisa->fontfh) / 2 + thisa->menuh,
                                thisa->fontfh,
                                thisa->fontfh,
                                v41)
          && thisa->cheatb != 1 )
        {
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sSolve, v21);
          thisa->cheatb = 1;
          thisa->bd.st.cheatb = 1;
          Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achhidcheat, v7);
        }
        if ( (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                (thisa->aboutw - thisa->fontfh) / 2 + thisa->fontfh / 2,
                                (thisa->fontth - thisa->fontfh) / 2 + thisa->menuh,
                                thisa->fontfh,
                                thisa->fontfh,
                                v42)
          && thisa->bd.relaxb != 1 )
        {
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sSolve, v22);
          thisa->bd.relaxb = 1;
          thisa->bd.st.cheatb = 1;
          Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achhidcheat, v8);
        }
      }
      else if ( *(_DWORD *)(a1 + 3376) )
      {
        if ( (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                (*(_DWORD *)(a1 + 96) - *(_DWORD *)(a1 + 64)) / 2,
                                *(_DWORD *)(a1 + 20)
                              + (*(_DWORD *)(a1 + 124) + *(_DWORD *)(a1 + 68)) / -2
                              + *(_DWORD *)(a1 + 100),
                                *(_DWORD *)(a1 + 64),
                                *(_DWORD *)(a1 + 68),
                                v40) )
          Window::sethelp((int)thisa, 0, v23);
        if ( (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw,
                                (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                thisa->tutw,
                                thisa->tuth,
                                v43) )
        {
          Window::sethelp((int)thisa, 0, v24);
          Board::initbd((int)&thisa->bd, (Board *const )1, thisa->md, v36);
          Window::initwindow(thisa, 0, v9);
          thisa->bd.tutb = 1;
        }
        if ( thisa->helpi > 1
          && (unsigned __int8)Window::isin(
                                (Window *const )ex,
                                ey,
                                (thisa->helpw - thisa->okw) / 2 - 2 * thisa->btnw,
                                (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                thisa->btnw,
                                thisa->btnh,
                                v44) )
        {
          --thisa->helpi;
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v25);
        }
        if ( thisa->helpi > 0 && thisa->helpi < thisa->maxhelp )
        {
          if ( (unsigned __int8)Window::isin(
                                  (Window *const )ex,
                                  ey,
                                  thisa->btnw + (thisa->helpw + thisa->okw) / 2,
                                  (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                  thisa->btnw,
                                  thisa->btnh,
                                  v44) )
          {
            ++thisa->helpi;
            Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v26);
            if ( thisa->helpi == thisa->maxhelp )
              Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achgenhelp, v27);
          }
        }
        if ( thisa->helpi == -2 )
        {
          if ( (unsigned __int8)Window::isin(
                                  (Window *const )ex,
                                  ey,
                                  ((thisa->helpw + thisa->okw) / 2 + thisa->helpw) / 2
                                + ((signed int)(((unsigned int)(-5 * thisa->facew) >> 31) - 5 * thisa->facew) >> 1),
                                  (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                  5 * thisa->facew,
                                  thisa->faceh,
                                  v44) )
          {
            thisa->lead_5 = (ex
                           - (((thisa->helpw + thisa->okw) / 2 + thisa->helpw) / 2
                            + ((signed int)(((unsigned int)(-5 * thisa->facew) >> 31) - 5 * thisa->facew) >> 1)))
                          / thisa->facew;
            Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v28);
          }
          if ( (unsigned __int8)Window::isin(
                                  (Window *const )ex,
                                  ey,
                                  -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw,
                                  (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                  thisa->tutw,
                                  thisa->tuth,
                                  v45) )
          {
            Window::sethelp((int)thisa, 0, v29);
            Board::initbd((int)&thisa->bd, (Board *const )1, thisa->md, v37);
            Window::initwindow(thisa, 0, v10);
            thisa->bd.tutb = 1;
          }
        }
        if ( thisa->helpi == -3 )
        {
          if ( (unsigned __int8)Window::isin(
                                  (Window *const )ex,
                                  ey,
                                  -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw,
                                  (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                                  thisa->tutw,
                                  thisa->tuth,
                                  v44) )
          {
            Window::sethelp((int)thisa, 0, v30);
            Board::initbd((int)&thisa->bd, (Board *const )1, thisa->md, v38);
            Window::initwindow(thisa, 0, v11);
            thisa->bd.tutb = 1;
          }
          helph__ = (long double)(thisa->helph - thisa->okh_ - 2 * thisa->iconh - thisa->faceh) / 9.0;
          for ( k = 0; k <= 9; ++k )
          {
            if ( (unsigned __int8)Window::isin(
                                    (Window *const )ex,
                                    ey,
                                    thisa->iconw,
                                    (signed int)((long double)k * helph__
                                               + (long double)(signed int)thisa->menuh
                                               + (long double)(signed int)thisa->iconh),
                                    thisa->facew,
                                    thisa->faceh,
                                    v46) )
            {
              switch ( k )
              {
                case 0:
                  Sound::switchsound(v18);
                  break;
                case 1:
                  Sound::switchmusic(v18);
                  break;
                case 2:
                  Window::switchmd((Window *const )v18);
                  break;
                case 4:
                  if ( thisa->mult_ )
                    thisa->mult_ = 0;
                  else
                    thisa->mult_ = 1;
                  Window::initwindow(thisa, 0, v31);
                  Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sRight, v12);
                  break;
                case 5:
                  Window::switchskin((Window *const )v18);
                  break;
                case 7:
                  thisa->bd.delayb = thisa->bd.delayb == 0;
                  Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v31);
                  break;
                case 8:
                  thisa->barb ^= 1u;
                  Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v31);
                  break;
                case 9:
                  thisa->singleb ^= 1u;
                  Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v31);
                  break;
                default:
                  break;
              }
            }
            for ( j = 0; j <= 2; ++j )
            {
              if ( (unsigned __int8)Window::isin(
                                      (Window *const )ex,
                                      ey,
                                      (j + 1) * (thisa->helpw / 4),
                                      (signed int)((long double)k * helph__
                                                 + (long double)(signed int)thisa->menuh
                                                 + (long double)(signed int)thisa->iconh),
                                      thisa->facew,
                                      thisa->faceh,
                                      v46) )
              {
                switch ( k )
                {
                  case 0:
                    if ( j <= 1 && thisa->bd.sd.soundb == j )
                      Sound::switchsound(v18);
                    break;
                  case 1:
                    if ( j <= 1 && thisa->bd.sd.musicb == j )
                      Sound::switchmusic(v18);
                    break;
                  case 2:
                    if ( j <= 2 && thisa->md != j )
                      Window::switchmd((int)thisa, (Window *const )j, v32);
                    break;
                  case 3:
                    if ( j <= 2 && thisa->md != j + 2 )
                      Window::switchmd((int)thisa, (Window *const )(j + 2), v32);
                    break;
                  case 4:
                    if ( thisa->mult_ != j )
                    {
                      thisa->mult_ = j;
                      Window::initwindow(thisa, 0, v32);
                      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sRight, v13);
                    }
                    break;
                  case 5:
                    if ( j <= 2 && thisa->colori != j )
                      Window::switchskin(thisa, (Window *const )j, v32);
                    break;
                  case 6:
                    if ( j <= 2 && thisa->colori != j + 3 )
                      Window::switchskin(thisa, (Window *const )(j + 3), v32);
                    break;
                  case 7:
                    if ( j <= 1 && thisa->bd.delayb == j )
                    {
                      thisa->bd.delayb = thisa->bd.delayb == 0;
                      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v32);
                    }
                    break;
                  case 8:
                    if ( j <= 1 && thisa->barb == j )
                    {
                      thisa->barb ^= 1u;
                      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v32);
                    }
                    break;
                  case 9:
                    if ( j <= 1 && thisa->singleb != j )
                    {
                      thisa->singleb ^= 1u;
                      Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v32);
                    }
                    break;
                  default:
                    continue;
                }
              }
            }
          }
          if ( thisa->mult_ > 1 )
          {
            if ( (unsigned __int8)Window::isin(
                                    (Window *const )ex,
                                    ey,
                                    thisa->facew + 3 * (thisa->helpw / 4),
                                    (signed int)(helph__ * 4.0
                                               + (long double)(signed int)thisa->menuh
                                               + (long double)(signed int)thisa->iconh),
                                    thisa->facew,
                                    thisa->faceh,
                                    v46) )
            {
              v14 = thisa->mult_ - 1;
              if ( v14 < 2 )
                v14 = 2;
              thisa->mult_ = v14;
              Window::initwindow(thisa, 0, v33);
              Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sRight, v15);
            }
            if ( (unsigned __int8)Window::isin(
                                    (Window *const )ex,
                                    ey,
                                    2 * thisa->facew + 3 * (thisa->helpw / 4),
                                    (signed int)(helph__ * 4.0
                                               + (long double)(signed int)thisa->menuh
                                               + (long double)(signed int)thisa->iconh),
                                    thisa->facew,
                                    thisa->faceh,
                                    v47) )
            {
              v16 = thisa->mult_ + 1;
              if ( v16 > 8 )
                v16 = 8;
              thisa->mult_ = v16;
              Window::initwindow(thisa, 0, v34);
              Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sRight, v17);
            }
          }
        }
      }
    }
    else if ( ey - *(_DWORD *)(a1 + 20) >= *(_DWORD *)(a1 + 28) )
    {
      if ( *(_DWORD *)(a1 + 780) <= 3 && !*(_DWORD *)(a1 + 784) )
        Window::mouseeventboard(a1, this, ex_, ey_, *(_DWORD *)(a1 + 3516) + 4, v39);
    }
    else if ( (*(_DWORD *)(a1 + 3464) - *(_DWORD *)(a1 + 24)) / 2 < ex
           && (*(_DWORD *)(a1 + 3464) + *(_DWORD *)(a1 + 24)) / 2 > ex )
    {
      if ( ey_ == 1 )
      {
        if ( *(_DWORD *)(a1 + 3040) <= 0 )
        {
          Board::initbd((Board *const )v18);
        }
        else
        {
          *(_DWORD *)(a1 + 3040) = 2;
          Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v19);
        }
      }
      else if ( ey_ == 2 && *(_DWORD *)(a1 + 780) > 0 && *(_DWORD *)(a1 + 780) <= 3 )
      {
        Board::pause((Board *const )v18);
        Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sSolve, v19);
        Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achgenpause, v6);
      }
    }
  }
  else if ( 3 * *(_DWORD *)(a1 + 16) <= ex )
  {
    if ( *(_DWORD *)(a1 + 3464) - 5 * *(_DWORD *)(a1 + 16) < ex )
    {
      switch ( (ex - (*(_DWORD *)(a1 + 3464) - 5 * *(_DWORD *)(a1 + 16))) / *(_DWORD *)(a1 + 16) )
      {
        case 0:
          Window::savescr((Window *const )v18);
          break;
        case 1:
          Window::sethelp(a1, (Window *const )0xFFFFFFFE, v19);
          break;
        case 2:
          Window::sethelp(a1, (Window *const )0xFFFFFFFD, v19);
          break;
        case 3:
          Window::sethelp(a1, (Window *const )1, v19);
          break;
        case 4:
          Window::sethelp(a1, (Window *const )0xFFFFFFFF, v19);
          break;
        default:
          break;
      }
    }
  }
  else if ( *(_DWORD *)(a1 + 3040) <= 0 )
  {
    *(_DWORD *)(a1 + 3376) = 0;
    Board::initbd(a1 + 768, (Board *const )(ex / *(_DWORD *)(a1 + 16) + 1), *(_DWORD *)(a1 + 3516), v35);
    Window::initwindow(thisa, 0, v5);
  }
  else
  {
    *(_DWORD *)(a1 + 3040) = 2;
    Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v19);
  }
  Window::paintevent((Window *const )v18);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00421B48; symbol: __ZN6Window8keyeventEl
void __userpurge Window::keyevent(int a1@<ecx>, Window *const this, int key)
{
  bool v3; // ST04_1
  bool v4; // ST04_1
  bool v5; // ST04_1
  int v6; // ST04_4
  int v7; // eax
  signed int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  Window *const v12; // ST00_4
  bool v13; // ST04_1
  Board *const v14; // ST00_4
  Window *v15; // [esp+0h] [ebp-28h]
  int v16; // [esp+4h] [ebp-24h]
  int v17; // [esp+4h] [ebp-24h]
  int v18; // [esp+8h] [ebp-20h]
  bool v19; // [esp+Ch] [ebp-1Ch]
  int v20; // [esp+10h] [ebp-18h]
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = (Window *)a1;
  switch ( (unsigned int)this )
  {
    case 0x31u:
      if ( *(_DWORD *)(a1 + 3040) <= 0 )
      {
        *(_DWORD *)(a1 + 3376) = 0;
        Board::initbd(a1 + 768, (Board *const )1, *(_DWORD *)(a1 + 3516), v18);
        Window::initwindow(thisa, 0, v3);
      }
      else
      {
        *(_DWORD *)(a1 + 3040) = 2;
        Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v16);
      }
      break;
    case 0x32u:
      if ( *(_DWORD *)(a1 + 3040) <= 0 )
      {
        *(_DWORD *)(a1 + 3376) = 0;
        Board::initbd(a1 + 768, (Board *const )2, *(_DWORD *)(a1 + 3516), v18);
        Window::initwindow(thisa, 0, v4);
      }
      else
      {
        *(_DWORD *)(a1 + 3040) = 2;
        Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v16);
      }
      break;
    case 0x33u:
      if ( *(_DWORD *)(a1 + 3040) <= 0 )
      {
        *(_DWORD *)(a1 + 3376) = 0;
        Board::initbd(a1 + 768, (Board *const )3, *(_DWORD *)(a1 + 3516), v18);
        Window::initwindow(thisa, 0, v5);
      }
      else
      {
        *(_DWORD *)(a1 + 3040) = 2;
        Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v16);
      }
      break;
    case 0x42u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFF, v16);
      break;
    case 0x45u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFD, v16);
      break;
    case 0x47u:
      Window::switchmd(v15);
      break;
    case 0x48u:
      Window::sethelp(a1, (Window *const )1, v16);
      break;
    case 0x4Bu:
      Window::switchskin(v15);
      break;
    case 0x4Du:
      Sound::switchmusic((Sound *const )v15);
      break;
    case 0x4Eu:
      if ( *(_DWORD *)(a1 + 3040) <= 0 )
      {
        *(_DWORD *)(a1 + 3376) = 0;
        Board::initbd((Board *const )v15);
        Window::initwindow(thisa, 0, v16);
      }
      else
      {
        *(_DWORD *)(a1 + 3040) = 2;
        Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2836), v16);
      }
      break;
    case 0x50u:
      Window::savescr(v15);
      break;
    case 0x52u:
      *(_BYTE *)(a1 + 3540) ^= 1u;
      Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2832), v16);
      break;
    case 0x53u:
      Sound::switchsound((Sound *const )v15);
      break;
    case 0x54u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFE, v16);
      break;
    case 0x70u:
      Window::sethelp(a1, (Window *const )1, v16);
      break;
    case 0x71u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFF, v16);
      break;
    case 0x72u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFD, v16);
      break;
    case 0x73u:
      Window::sethelp(a1, (Window *const )0xFFFFFFFE, v16);
      break;
    case 0x74u:
      Sound::switchsound((Sound *const )v15);
      break;
    case 0x75u:
      Sound::switchmusic((Sound *const )v15);
      break;
    case 0x76u:
      Window::switchmd(v15);
      break;
    case 0x77u:
      *(_BYTE *)(a1 + 3540) ^= 1u;
      Sound::playsound((Sound *)(a1 + 2752), *(Sound *const *)(a1 + 2832), v16);
      break;
    case 0x7Au:
      Window::switchskin(v15);
      break;
    case 0x7Bu:
      Window::savescr(v15);
      break;
    default:
      break;
  }
  if ( thisa->cheatb && this == (Window *const )67 )
    Steam::resetach((Steam *const )v15);
  if ( thisa->helpi == -2 && this == (Window *const )9 )
  {
    thisa->lead_5 = (thisa->lead_5 + 1) % 5;
    Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v16);
  }
  if ( thisa->helpi )
  {
    if ( this == (Window *const )13
      || this == (Window *const )32
      || this == (Window *const )27
      || this == (Window *const )81 )
    {
      Window::sethelp((int)thisa, 0, v16);
    }
    if ( thisa->helpi > 0 )
    {
      if ( this == (Window *const )37 && thisa->helpi > 1 )
      {
        --thisa->helpi;
        Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v16);
      }
      if ( this == (Window *const )39 && thisa->helpi < thisa->maxhelp )
      {
        ++thisa->helpi;
        Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v16);
        if ( thisa->helpi == thisa->maxhelp )
          Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achgenhelp, v17);
      }
    }
  }
  else
  {
    if ( thisa->bd.mx == -1
      && thisa->bd.my == -1
      && (this == (Window *const )65
       || this == (Window *const )68
       || this == (Window *const )87
       || this == (Window *const )83
       || this == (Window *const )188
       || this == (Window *const )190) )
    {
      thisa->bd.mx = thisa->bd.w / 2;
      thisa->bd.my = thisa->bd.h - 3;
    }
    switch ( (unsigned int)this )
    {
      case 0x1Bu:
        CloseWin();
        break;
      case 0x20u:
        if ( thisa->bd.sit > 0 && thisa->bd.sit <= 3 )
        {
          Board::pause((Board *const )v15);
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sSolve, v16);
          Steam::addach((int)&thisa->bd.st, (Steam *const )thisa->bd.st.achgenpause, v6);
        }
        break;
      case 0x21u:
        v7 = thisa->bd.maskj0;
        if ( v7 > thisa->bd.h - 4 )
          v7 = thisa->bd.h - 4;
        thisa->bd.maskj0 = v7;
        v8 = --thisa->bd.maskj0;
        if ( v8 <= 0 )
          v8 = 1;
        thisa->bd.maskj0 = v8;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x22u:
        v9 = ++thisa->bd.maskj0;
        if ( v9 > thisa->bd.h - 4 )
          v9 = thisa->bd.h - 4;
        thisa->bd.maskj0 = v9;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x25u:
        --thisa->bd.w;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x26u:
        --thisa->bd.h;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x27u:
        ++thisa->bd.w;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x28u:
        ++thisa->bd.h;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x41u:
        --thisa->bd.mx;
        thisa->bd.mx &= ~(thisa->bd.mx >> 31);
        break;
      case 0x44u:
        v10 = ++thisa->bd.mx;
        if ( v10 > thisa->bd.w - 1 )
          v10 = thisa->bd.w - 1;
        thisa->bd.mx = v10;
        break;
      case 0x51u:
        CloseWin();
        break;
      case 0x53u:
        v11 = ++thisa->bd.my;
        if ( v11 > thisa->bd.h - 1 )
          v11 = thisa->bd.h - 1;
        thisa->bd.my = v11;
        break;
      case 0x55u:
        if ( !thisa->bd.tutb )
        {
          Board::addline((Board *const )v15);
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sLeft, v16);
          Window::paintevent(v12);
          Board::checkline(&thisa->bd, (Board *const )1, v13);
          Board::checkdie(v14);
        }
        break;
      case 0x57u:
        --thisa->bd.my;
        thisa->bd.my &= ~(thisa->bd.my >> 31);
        break;
      case 0x6Bu:
        ++thisa->bd.n;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0x6Du:
        --thisa->bd.n;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0xBBu:
        ++thisa->bd.n;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0xBCu:
        thisa->mx = -1;
        thisa->my = -1;
        Window::tutevent(thisa, 0, 0, 1, v19);
        Window::mouseeventboard_((int)thisa, (Window *const )thisa->bd.mx, thisa->bd.my, 1, thisa->md + 4, v20);
        break;
      case 0xBDu:
        --thisa->bd.n;
        Window::initwindow(thisa, (Window *const )1, v16);
        break;
      case 0xBEu:
        thisa->mx = -1;
        thisa->my = -1;
        Window::tutevent(thisa, 0, 0, 1, v19);
        Window::mouseeventboard_((int)thisa, (Window *const )thisa->bd.mx, thisa->bd.my, 2, thisa->md + 4, v20);
        break;
      default:
        break;
    }
    if ( thisa->cheatb )
    {
      switch ( (unsigned int)this )
      {
        case 0x30u:
          Board::delline(&thisa->bd, (Board *const )(thisa->bd.h - 1), v16);
          break;
        case 0x34u:
          Board::solve1((Board *const )v15);
          break;
        case 0x35u:
          Board::solve2((Board *const )v15);
          break;
        case 0x36u:
          Board::solve1_((Board *const )v15);
          break;
        case 0x37u:
          Board::solve2_((Board *const )v15);
          break;
        case 0x38u:
          Board::solve3_((Board *const )v15);
          break;
        case 0x39u:
          Board::solveblank_((Board *const )v15);
          break;
        case 0x56u:
          ++thisa->bd.level;
          break;
        default:
          break;
      }
      if ( (signed int)this > 51 || (signed int)this <= 48 )
      {
        Window::paintevent(v15);
        Board::checkline(&thisa->bd, (Board *const )1, v16);
      }
    }
  }
  Window::paintevent(v15);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004227C6; symbol: __ZN6Window8doactionEv
void __cdecl Window::doaction(Window *const this)
{
  Window *v1; // ecx
  int v2; // ebx
  Window *v3; // eax
  int v4; // ebx
  Window *v5; // eax
  bool v6; // al
  int v7; // ebx
  int v8; // esi
  Window *v9; // eax
  int v10; // ebx
  int v11; // esi
  Window *v12; // eax
  Window *v13; // eax
  bool v14; // al
  HWND__ *v15; // eax
  HWND__ *v16; // eax
  double v17; // ST18_8
  double v18; // ST18_8
  bool v19; // al
  HWND__ *v20; // eax
  bool v21; // ST04_1
  int v22; // ST04_4
  Window *v23; // [esp+0h] [ebp-38h]
  int v24; // [esp+4h] [ebp-34h]
  int v25; // [esp+Ch] [ebp-2Ch]
  signed __int64 v26; // [esp+10h] [ebp-28h]
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  while ( (unsigned __int8)IsNextMsg() )
  {
    if ( !thisa->bd.delayb__ )
    {
      thisa->ml = GetAsyncKeyState(1) != 0;
      thisa->mr = GetAsyncKeyState(2) != 0;
      if ( IsMouseLeft() )
      {
        thisa->mi = 1;
        thisa->mx = -1;
        thisa->my = -1;
        v2 = GetMousePosY();
        v3 = (Window *)GetMousePosX();
        Window::mouseevent((int)thisa, v3, v2, 1, v25);
      }
      if ( IsMouseRight() )
      {
        thisa->mi = 1;
        thisa->mx = -1;
        thisa->my = -1;
        v4 = GetMousePosY();
        v5 = (Window *)GetMousePosX();
        Window::mouseevent((int)thisa, v5, v4, 2, v25);
      }
      v6 = IsMouseMove() && thisa->md > 1 && !thisa->bd.tutb && thisa->mi;
      if ( v6 )
      {
        if ( thisa->ml )
        {
          v7 = thisa->md;
          v8 = GetMousePosY();
          v9 = (Window *)GetMousePosX();
          Window::mouseeventboard((int)thisa, v9, v8, 1, v7, v26);
        }
        if ( thisa->mr )
        {
          v10 = thisa->md;
          v11 = GetMousePosY();
          v12 = (Window *)GetMousePosX();
          Window::mouseeventboard((int)thisa, v12, v11, 2, v10, v26);
        }
      }
      if ( IsKey() )
      {
        v13 = (Window *)GetKey();
        Window::keyevent((int)thisa, v13, v24);
      }
      v14 = IsMsg(0xFu) || IsMsg(0xA1u) || IsMsg(0x112u);
      if ( v14 )
      {
        v15 = GetHwnd();
        thisa->showmax = IsZoomed(v15) != 0;
        v16 = GetHwnd();
        v19 = 0;
        if ( !IsIconic(v16) )
        {
          if ( thisa->showmax != thisa->showmax_
            || ((v17 = (long double)thisa->w_ * thisa->mult, v26 = GetWidth(), fabs(v17 - (double)v26) > 1.0)
             || (v18 = (long double)thisa->h_ * thisa->mult, v26 = GetHeight(), fabs(v18 - (double)v26) > 1.0))
            && IsMsg(0xA1u) )
          {
            v19 = 1;
          }
        }
        if ( v19 )
        {
          v20 = GetHwnd();
          ShowWindow(v20, 9);
          thisa->mult_ = thisa->showmax;
          Window::initwindow(thisa, 0, v21);
          Sound::playsound(&thisa->bd.sd, (Sound *const )thisa->bd.sd.sRight, v22);
          thisa->showmax = 0;
          thisa->showmax_ = thisa->showmax;
        }
        Window::paintevent(v23);
      }
    }
  }
  thisa->bd.delayb__ = 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422BA8; symbol: __ZN6Window12setfontname_EPKc
void __userpurge Window::setfontname_(Window *a1@<ecx>, Window *const this, const char *s)
{
  Window *v3; // ST1C_4

  v3 = a1;
  SetFontName((const char *)this);
  SetFont(v3->pwint);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422BD2; symbol: __ZN6Window14setfontheight_Em
void __userpurge Window::setfontheight_(Window *a1@<ecx>, Window *const this, unsigned int h)
{
  Window *v3; // ST2C_4

  v3 = a1;
  SetFontHeight((signed __int64)((double)(unsigned int)this * a1->mult));
  SetFont(v3->pwint);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422C38; symbol: __ZN6Window14setfontweight_Em
void __userpurge Window::setfontweight_(Window *a1@<ecx>, Window *const this, unsigned int wg)
{
  Window *v3; // ST1C_4

  v3 = a1;
  SetFontWeight((unsigned int)this);
  SetFont(v3->pwint);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422C62; symbol: __ZN6Window11drawtextxy_EP6bitmapPKsllmmmmm
void __userpurge Window::drawtextxy_(int a1@<ecx>, Window *const this, pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int format)
{
  signed __int64 v11; // ST10_8

  v11 = __PAIR__(
          (signed __int64)((double)w * *(double *)(a1 + 3408)),
          (unsigned int)(signed __int64)((double)(unsigned int)y * *(double *)(a1 + 3408)));
  DrawTextXY(
    (pbitmap)this,
    (const __int16 *)b,
    (signed int)((long double)(signed int)s * *(double *)(a1 + 3408)),
    (signed int)((long double)x * *(double *)(a1 + 3408)),
    v11,
    HIDWORD(v11),
    h,
    cfg,
    cbg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422D56; symbol: __ZN6Window11drawtextxy_EP6bitmapPKsllmmmm
void __userpurge Window::drawtextxy_(int a1@<ecx>, Window *const this, pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  signed __int64 v10; // ST10_8

  v10 = __PAIR__(
          (signed __int64)((double)w * *(double *)(a1 + 3408)),
          (unsigned int)(signed __int64)((double)(unsigned int)y * *(double *)(a1 + 3408)));
  DrawTextXY(
    (pbitmap)this,
    (const __int16 *)b,
    (signed int)((long double)(signed int)s * *(double *)(a1 + 3408)),
    (signed int)((long double)x * *(double *)(a1 + 3408)),
    v10,
    HIDWORD(v10),
    h,
    cfg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422E42; symbol: __ZN6Window11drawtextxy_EP6bitmapPKcllmmmm
void __userpurge Window::drawtextxy_(int a1@<ecx>, Window *const this, pbitmap b, const char *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  signed __int64 v10; // ST10_8

  v10 = __PAIR__(
          (signed __int64)((double)w * *(double *)(a1 + 3408)),
          (unsigned int)(signed __int64)((double)(unsigned int)y * *(double *)(a1 + 3408)));
  DrawTextXY(
    (pbitmap)this,
    (const char *)b,
    (signed int)((long double)(signed int)s * *(double *)(a1 + 3408)),
    (signed int)((long double)x * *(double *)(a1 + 3408)),
    v10,
    HIDWORD(v10),
    h,
    cfg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422F2E; symbol: __ZN6Window11drawtextxy_EP6bitmapPKcllmm
void __userpurge Window::drawtextxy_(int a1@<ecx>, Window *const this, pbitmap b, const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(
    (pbitmap)this,
    (const char *)b,
    (signed int)((long double)(signed int)s * *(double *)(a1 + 3408)),
    (signed int)((long double)x * *(double *)(a1 + 3408)),
    y,
    cfg);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00422FA6; symbol: __ZN6Window15getstringwidth_EPKc
signed __int64 __userpurge Window::getstringwidth_@<edx:eax>(int a1@<ecx>, Window *const this, const char *s)
{
  return (signed __int64)((double)GetStringWidth((const char *)this) / *(double *)(a1 + 3408));
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00422FF8; symbol: _WinMain@16
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  bool v4; // al
  __int16 *v5; // ebx
  int v6; // ST04_4
  __int16 *v7; // eax
  Window *const v8; // ST00_4
  Window *const v9; // ST00_4
  Board *const v10; // ST00_4
  Window *const v11; // ST00_4
  Window *const v12; // ST00_4
  Lan *v14; // [esp+0h] [ebp-F78h]
  Window *v15; // [esp+0h] [ebp-F78h]
  Window *v16; // [esp+0h] [ebp-F78h]
  int v17; // [esp+4h] [ebp-F74h]
  Window w; // [esp+168h] [ebp-E10h]
  HANDLE hMutex; // [esp+F6Ch] [ebp-Ch]

  MainInstance = hInstance;
  hMutex = CreateMutexA(0, 1, "MineSweeperRushMutex");
  v4 = GetLastError() == 183 || FindWindowA("MineSweeperRushClass", 0);
  if ( v4 )
  {
    Lan::Lan(v14);
    v5 = Lan::getlan((int)&w, (Lan *const )w.pmenug[1][0], v17);
    v7 = Lan::getlan((int)&w, (Lan *const )w.pmenug[1][1], v6);
    MsgBoxW(v7, v5, 0x40u);
  }
  else
  {
    CheckAndProcessCabFile();
    Lan::Lan(v14);
    Window::Window(v8);
    Window::loadall(v9);
    while ( (unsigned __int8)IsWin() )
    {
      Window::doaction(v15);
      if ( Board::addmask(v10) )
      {
        Window::paintevent(v16);
        Window::paintrefresh(v11);
      }
      Sound::checkmusic((Sound *const )v16);
      Delay(1u);
    }
    ReleaseMutex(hMutex);
    Window::~Window(v12);
  }
  CloseHandle(hMutex);
  return 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425990; symbol: _UpdateWindow@4
BOOL __stdcall UpdateWindow(HWND hWnd)
{
  return UpdateWindow(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259A8; symbol: _ShowWindow@8
BOOL __stdcall ShowWindow(HWND hWnd, int nCmdShow)
{
  return ShowWindow(hWnd, nCmdShow);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259B0; symbol: _SetWindowTextW@8
BOOL __stdcall SetWindowTextW(HWND hWnd, LPCWSTR lpString)
{
  return SetWindowTextW(hWnd, lpString);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259B8; symbol: _SetWindowTextA@8
BOOL __stdcall SetWindowTextA(HWND hWnd, LPCSTR lpString)
{
  return SetWindowTextA(hWnd, lpString);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259C0; symbol: _SetWindowLongA@12
LONG __stdcall SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong)
{
  return SetWindowLongA(hWnd, nIndex, dwNewLong);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x004259F0; symbol: _MoveWindow@24
BOOL __stdcall MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint)
{
  return MoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A30; symbol: _GetWindowTextW@12
int __stdcall GetWindowTextW(HWND hWnd, LPWSTR lpString, int nMaxCount)
{
  return GetWindowTextW(hWnd, lpString, nMaxCount);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A38; symbol: _GetWindowTextA@12
int __stdcall GetWindowTextA(HWND hWnd, LPSTR lpString, int nMaxCount)
{
  return GetWindowTextA(hWnd, lpString, nMaxCount);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A40; symbol: _GetWindowRect@8
BOOL __stdcall GetWindowRect(HWND hWnd, LPRECT lpRect)
{
  return GetWindowRect(hWnd, lpRect);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A60; symbol: _GetDesktopWindow@0
HWND __stdcall GetDesktopWindow()
{
  return GetDesktopWindow();
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425A88; symbol: _FindWindowA@8
HWND __stdcall FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName)
{
  return FindWindowA(lpClassName, lpWindowName);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AB8; symbol: _DestroyWindow@4
BOOL __stdcall DestroyWindow(HWND hWnd)
{
  return DestroyWindow(hWnd);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AC0; symbol: _DefWindowProcW@16
LRESULT __stdcall DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcW(hWnd, Msg, wParam, lParam);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：创建窗口。
// Address: 0x00425AC8; symbol: _CreateWindowExW@48
HWND __stdcall CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
  return CreateWindowExW(
           dwExStyle,
           lpClassName,
           lpWindowName,
           dwStyle,
           X,
           Y,
           nWidth,
           nHeight,
           hWndParent,
           hMenu,
           hInstance,
           lpParam);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x00425AD0; symbol: _AdjustWindowRect@12
BOOL __stdcall AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu)
{
  return AdjustWindowRect(lpRect, dwStyle, bMenu);
}


