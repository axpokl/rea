// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A610; symbol: __ZN5SteamC1Ev
void __cdecl Steam::Steam(Steam *const this)
{
  Steam *v1; // ecx
  Steam *v2; // ST1C_4
  Steam *const v3; // ST00_4
  Steam *const v4; // ST00_4
  Lan *v5; // [esp+0h] [ebp-38h]

  v2 = v1;
  Lan::Lan(v5);
  v2->appid = 3665840;
  v2->cheatb = 0;
  v2->achgenstart = 0;
  v2->achgencustom = 1;
  v2->achgenmode = 2;
  v2->achgenpause = 3;
  v2->achgenhelp = 4;
  v2->achhidcheat = 5;
  v2->achhidedge = 6;
  v2->achhidmark = 7;
  v2->achhidright = 8;
  v2->achhidalive = 9;
  v2->achcumdead1 = 10;
  v2->achcumdead10 = 11;
  v2->achcumdead100 = 12;
  v2->achcumdead1000 = 13;
  v2->achcumfour1 = 14;
  v2->achcumfour10 = 15;
  v2->achcumfour100 = 16;
  v2->achcumfour1000 = 17;
  v2->achcumline100 = 18;
  v2->achcumline300 = 19;
  v2->achcumline600 = 20;
  v2->achcumline1000 = 21;
  v2->achcumtotal10 = 22;
  v2->achcumtotal100 = 23;
  v2->achcumtotal1000 = 24;
  v2->achcumtotal10000 = 25;
  qmemcpy(v2->achs, off_427140, sizeof(v2->achs));
  v2->scrdead = 0;
  v2->scrfour = 1;
  v2->scrtotal = 2;
  v2->scrline = 3;
  v2->scrline1 = 4;
  v2->scrline2 = 5;
  v2->scrline3 = 6;
  v2->scrindexline = 0;
  v2->scrindexmdb = 3;
  v2->scrindexnomiss = 6;
  v2->scrindextetris = 9;
  v2->scrindexmiss = 12;
  qmemcpy(v2->scrs, off_4271C0, sizeof(v2->scrs));
  v2->newrecord = 0;
  v2->leads[0] = "1_TOP";
  v2->leads[1] = "2_TOP";
  v2->leads[2] = "3_TOP";
  v2->leads[3] = "1_TOP_N";
  v2->leads[4] = "2_TOP_N";
  v2->leads[5] = "3_TOP_N";
  v2->leads[6] = "1_TOP_D";
  v2->leads[7] = "2_TOP_D";
  v2->leads[8] = "3_TOP_D";
  v2->leads[9] = "1_TOP_T";
  v2->leads[10] = "2_TOP_T";
  v2->leads[11] = "3_TOP_T";
  v2->leads[12] = "1_TOP_M";
  v2->leads[13] = "2_TOP_M";
  v2->leads[14] = "3_TOP_M";
  v2->leadk_[0] = 20;
  v2->leadk_[1] = 15;
  v2->leadk_[2] = 1;
  v2->leadfailed = 1;
  v2->leadsn = 0;
  v2->waittime = 5.0;
  memset(v2->lead, 0, 0x78u);
  memset(v2->lead_, 0, 0x168u);
  memset(&v2->leadr, 0, 0x10u);
  memset(&v2->leadu, 0, 0x20u);
  memset(&v2->leadd, 0, 0x18u);
  memset(v2->leadb, 0, 0x78u);
  memset(v2->leaden, 0, 0x168u);
  v2->leadsn = (LeaderboardEntry_t (*)[15][20])calloc(3u, 0x2580u);
  Steam::initsteam(v3);
  Steam::loadlan(v4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x0040AA96; symbol: __ZN5SteamD1Ev
void __cdecl Steam::~Steam(Steam *const this)
{
  Steam *v1; // [esp+0h] [ebp-18h]

  Steam::exitsteam(v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AAAC; symbol: __ZN5Steam9initsteamEv
void __cdecl Steam::initsteam(Steam *const this)
{
  Steam *v1; // ecx
  __int16 *v2; // ebx
  int v3; // ST04_4
  __int16 *v4; // eax
  __int16 *v5; // ebx
  int v6; // ST04_4
  __int16 *v7; // eax
  ISteamUtils *v8; // eax
  int v9; // [esp+4h] [ebp-24h]
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( (unsigned __int8)_SteamAPI_RestartAppIfNecessary(v1->appid) )
  {
    v2 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_TITLE, v9);
    v4 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_STEAM_LAUNCH, v3);
    MsgBoxW(v4, v2, 0x40u);
  }
  thisa->steamb = _SteamAPI_Init();
  if ( thisa->steamb != 1 )
  {
    v5 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_TITLE, v9);
    v7 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_STEAM_FAIL, v6);
    MsgBoxW(v7, v5, 0x30u);
  }
  if ( thisa->steamb )
  {
    v8 = SteamUtils();
    if ( (*(int (__fastcall **)(ISteamUtils *))(*(_DWORD *)v8 + 36))(v8) != thisa->appid )
      MsgBox(
        "The old game MineSweeper Tetris is retired, please download the new MineSweeper Rush from Steam Store! \n"
        "https://store.steampowered.com/app/3665840",
        "MineSweeper Rush",
        0x40u);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040ABD4; symbol: __ZN5Steam7loadlanEv
void __cdecl Steam::loadlan(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUtils *v2; // eax
  ISteamApps *v3; // eax
  const char *v4; // [esp+4h] [ebp-34h]
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  Lan *langame; // [esp+28h] [ebp-10h]
  Lan *lanui; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    v2 = SteamUtils();
    lanui = (Lan *)(*(int (__fastcall **)(ISteamUtils *))(*(_DWORD *)v2 + 92))(v2);
    v3 = SteamApps();
    langame = (Lan *)(*(int (__fastcall **)(ISteamApps *))(*(_DWORD *)v3 + 16))(v3);
    if ( !strcmp((const char *)langame, thisa->lan.lanshort[23]) )
      Lan::initlan(&thisa->lan, lanui, v4);
    else
      Lan::initlan(&thisa->lan, langame, v4);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AC56; symbol: __ZN5Steam9exitsteamEv
void __cdecl Steam::exitsteam(Steam *const this)
{
  int v1; // ecx
  ISteamUserStats *v2; // eax

  if ( *(_BYTE *)(v1 + 348) )
  {
    v2 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *))(*(_DWORD *)v2 + 40))(v2);
    _SteamAPI_Shutdown();
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AC88; symbol: __ZN5Steam9loadsteamEv
void __cdecl Steam::loadsteam(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUserStats *v2; // eax
  __int16 *v3; // ebx
  int v4; // ST04_4
  __int16 *v5; // eax
  Steam *const v6; // ST00_4
  Steam *const v7; // ST00_4
  Steam *v8; // [esp+0h] [ebp-28h]
  int v9; // [esp+4h] [ebp-24h]
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    v2 = SteamUserStats();
    if ( (**(unsigned __int8 (__fastcall ***)(ISteamUserStats *))v2)(v2) ^ 1 )
    {
      v3 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_TITLE, v9);
      v5 = Lan::getlan((int)thisa, (Lan *const )thisa->lan.LAN_STEAM_Status, v4);
      MsgBoxW(v5, v3, 0x30u);
    }
    else
    {
      Steam::loadach(v8);
      Steam::loadscr(v6);
      Steam::loadlead(v7);
      painttitles = 0;
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AD30; symbol: __ZN5Steam8resetachEv
void __cdecl Steam::resetach(Steam *const this)
{
  int v1; // ecx
  ISteamUserStats *v2; // eax

  if ( *(_BYTE *)(v1 + 348) )
  {
    v2 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *, _DWORD))(*(_DWORD *)v2 + 84))(v2, *(_DWORD *)(*(_DWORD *)v2 + 84));
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AD64; symbol: __ZN5Steam7loadachEv
void __cdecl Steam::loadach(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUserStats *v2; // eax
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  int achid; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    painttitles = (pbitmap)"Load Achievement";
    painttitleb = 2;
    for ( achid = 0; achid <= 25; ++achid )
    {
      v2 = SteamUserStats();
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v2 + 24))(
        v2,
        thisa->lan.lanshort[achid + 112 + 2],
        thisa->lan.lanshort[achid + 112 + 2]);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040ADE2; symbol: __ZN5Steam6addachEl
void __userpurge Steam::addach(int a1@<ecx>, Steam *const this, int achid)
{
  ISteamUserStats *v3; // eax
  const char *v4; // ST04_4
  ISteamUserStats *v5; // eax
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = (Steam *)a1;
  if ( *(_BYTE *)(a1 + 348) && this->achb[a1] != 1 && (*(_BYTE *)(a1 + 349) != 1 || *(Steam *const *)(a1 + 372) == this) )
  {
    v3 = SteamUserStats();
    v4 = thisa->lan.lanshort[(_DWORD)this + 112 + 2];
    (*(void (__fastcall **)(ISteamUserStats *))(*(_DWORD *)v3 + 28))(v3);
    v5 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *, _DWORD))(*(_DWORD *)v5 + 40))(v5, *(_DWORD *)(*(_DWORD *)v5 + 40));
    this->achb[(_DWORD)thisa] = 1;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AE7C; symbol: __ZN5Steam8checkachElllllllll
void __userpurge Steam::checkach(int a1@<ecx>, Steam *const this, int scrid, int d, int c, int b, int a, int a_d, int a_c, int a_b, int a_a)
{
  int v11; // [esp+4h] [ebp-24h]

  if ( *(_BYTE *)(a1 + 348) )
  {
    if ( *(_DWORD *)(a1 + 4 * ((_DWORD)this + 176) + 8) < scrid )
    {
      if ( *(_DWORD *)(a1 + 4 * ((_DWORD)this + 176) + 8) < d )
      {
        if ( *(_DWORD *)(a1 + 4 * ((_DWORD)this + 176) + 8) < c )
        {
          if ( *(_DWORD *)(a1 + 4 * ((_DWORD)this + 176) + 8) >= b )
            Steam::addach(a1, (Steam *const )a_b, v11);
        }
        else
        {
          Steam::addach(a1, (Steam *const )a_c, v11);
        }
      }
      else
      {
        Steam::addach(a1, (Steam *const )a_d, v11);
      }
    }
    else
    {
      Steam::addach(a1, (Steam *const )a, v11);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040AF42; symbol: __ZN5Steam7loadscrEv
void __cdecl Steam::loadscr(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUserStats *v2; // eax
  ISteamUserStats *v3; // eax
  Steam *v4; // [esp+0h] [ebp-38h]
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  int scrid; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    painttitles = (pbitmap)"Load Status";
    painttitleb = 2;
    for ( scrid = 0; scrid <= 18; ++scrid )
    {
      thisa->lan.lanshort[scrid + 176 + 2] = (const char *)-1;
      v2 = SteamUserStats();
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v2 + 8))(
        v2,
        thisa->lan.lanshort[scrid + 156 + 3],
        thisa->lan.lanshort[scrid + 156 + 3]);
      if ( (_DWORD)thisa->lan.lanshort[scrid + 176 + 2] < 0 )
      {
        v3 = SteamUserStats();
        (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v3 + 8))(
          v3,
          thisa->lan.lanshort[scrid + 156 + 3],
          thisa->lan.lanshort[scrid + 156 + 3]);
      }
      if ( (_DWORD)thisa->lan.lanshort[scrid + 176 + 2] < 0 )
      {
        thisa->lan.lanshort[scrid + 176 + 2] = 0;
        thisa->steamb = 0;
      }
    }
    Steam::setlead(v4);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B07E; symbol: __ZN5Steam6setscrEl
void __userpurge Steam::setscr(Steam *a1@<ecx>, Steam *const this, int scrid)
{
  ISteamUserStats *v3; // eax
  long double v4; // fst7
  int v5; // [esp+24h] [ebp-34h]
  Steam *thisa; // [esp+3Ch] [ebp-1Ch]

  thisa = a1;
  if ( a1->steamb )
  {
    if ( (_DWORD)a1->lan.lanshort[(_DWORD)this + 176 + 2] > 0 )
    {
      v3 = SteamUserStats();
      v4 = *(float *)&thisa->lan.lanshort[(_DWORD)this + 176 + 2];
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v3 + 16))(
        v3,
        thisa->lan.lanshort[(_DWORD)this + 156 + 3],
        thisa->lan.lanshort[(_DWORD)this + 156 + 3]);
    }
    if ( (Steam *const )thisa->scrdead == this )
    {
      Steam::checkach(
        (int)thisa,
        (Steam *const )thisa->scrdead,
        1000,
        100,
        10,
        1,
        thisa->achcumdead1000,
        thisa->achcumdead100,
        thisa->achcumdead10,
        thisa->achcumdead1,
        v5);
    }
    else if ( (Steam *const )thisa->scrfour == this )
    {
      Steam::checkach(
        (int)thisa,
        (Steam *const )thisa->scrfour,
        1000,
        100,
        10,
        1,
        thisa->achcumfour1000,
        thisa->achcumfour100,
        thisa->achcumfour10,
        thisa->achcumfour1,
        v5);
    }
    else if ( (Steam *const )thisa->scrtotal == this )
    {
      Steam::checkach(
        (int)thisa,
        (Steam *const )thisa->scrtotal,
        10000,
        1000,
        100,
        10,
        thisa->achcumtotal10000,
        thisa->achcumtotal1000,
        thisa->achcumtotal100,
        thisa->achcumtotal10,
        v5);
    }
    else if ( (Steam *const )thisa->scrline == this )
    {
      Steam::checkach(
        (int)thisa,
        (Steam *const )thisa->scrline,
        1000,
        600,
        300,
        100,
        thisa->achcumline1000,
        thisa->achcumline600,
        thisa->achcumline300,
        thisa->achcumline100,
        v5);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B2F8; symbol: __ZN5Steam6addscrElll
void __userpurge Steam::addscr(Steam *a1@<ecx>, Steam *const this, int scrid, int val, int mode)
{
  int v5; // [esp+4h] [ebp-24h]

  if ( a1->steamb && a1->cheatb != 1 && val > 0 )
  {
    a1->lan.lanshort[(_DWORD)this + 176 + 2] += scrid;
    Steam::setscr(a1, this, v5);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B364; symbol: __ZN5Steam6maxscrEll
void __userpurge Steam::maxscr(Steam *a1@<ecx>, Steam *const this, int val, int scrline__)
{
  const char *v4; // eax
  int v5; // [esp+4h] [ebp-24h]
  int v6; // [esp+4h] [ebp-24h]
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->steamb && (_DWORD)a1->lan.lanshort[val + 176 + 2] < (signed int)this )
  {
    a1->lan.lanshort[val + 176 + 2] = (const char *)this;
    Steam::setscr(a1, (Steam *const )val, v5);
    if ( val <= 6 )
    {
      if ( (_DWORD)thisa->lan.lanshort[thisa->scrline + 176 + 2] <= (_DWORD)thisa->lan.lanshort[val + 176 + 2] )
        v4 = thisa->lan.lanshort[val + 176 + 2];
      else
        v4 = thisa->lan.lanshort[thisa->scrline + 176 + 2];
      thisa->lan.lanshort[thisa->scrline + 176 + 2] = v4;
      Steam::setscr(thisa, (Steam *const )thisa->scrline, v6);
    }
    thisa->newrecord = 1;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B45C; symbol: __ZN5Steam7compscrElll
void __userpurge Steam::compscr(Steam *a1@<ecx>, Steam *const this, int val, int mode, int index)
{
  int v5; // [esp+8h] [ebp-30h]
  int scrline_; // [esp+2Ch] [ebp-Ch]

  if ( a1->steamb && a1->cheatb != 1 && val > 0 )
  {
    scrline_ = -1;
    switch ( val )
    {
      case 2:
        scrline_ = a1->scrline2;
        break;
      case 3:
        scrline_ = a1->scrline3;
        break;
      case 1:
        scrline_ = a1->scrline1;
        break;
    }
    if ( scrline_ > 0 )
      Steam::maxscr(a1, this, mode + scrline_, v5);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B4F6; symbol: __ZN5Steam8resetscrEv
void __cdecl Steam::resetscr(Steam *const this)
{
  int v1; // ecx
  int scrid; // [esp+10h] [ebp-4h]

  if ( *(_BYTE *)(v1 + 348) )
  {
    for ( scrid = 0; scrid <= 18; ++scrid )
      *(_DWORD *)(v1 + 4 * (scrid + 176) + 8) = 0;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B538; symbol: __ZN5Steam8loadleadEv
void __cdecl Steam::loadlead(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUserStats *v2; // eax
  int v3; // ebx
  const char *v4; // edx
  ISteamUtils *v5; // eax
  const char *v6; // edx
  int v7; // ebx
  Steam *v8; // [esp+0h] [ebp-58h]
  Steam *thisa; // [esp+2Ch] [ebp-2Ch]
  int leadid_0; // [esp+38h] [ebp-20h]
  int leadid; // [esp+3Ch] [ebp-1Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    painttitles = (pbitmap)"Load Leaderboard";
    painttitleb = 2;
    for ( leadid = 0; leadid <= 14; ++leadid )
    {
      v2 = SteamUserStats();
      v8 = (Steam *)thisa->lan.lanshort[leadid + 196 + 2];
      v3 = leadid + 108;
      thisa->lan.lanshort[2 * v3] = (const char *)(*(int (__fastcall **)(ISteamUserStats *, const char *))(*(_DWORD *)v2 + 92))(
                                                    v2,
                                                    thisa->lan.lanshort[leadid + 196 + 2]);
      thisa->lan.lanshort[2 * v3 + 1] = v4;
    }
    if ( Steam::waitlead(v8) )
    {
      for ( leadid_0 = 0; leadid_0 <= 14; ++leadid_0 )
      {
        v5 = SteamUtils();
        (*(void (__stdcall **)(const char *, const char *, LeaderboardFindResult_t *, signed int, signed int, bool *))(*(_DWORD *)v5 + 52))(
          thisa->lan.lanshort[2 * (leadid_0 + 108)],
          thisa->lan.lanshort[2 * (leadid_0 + 108) + 1],
          &thisa->leadr,
          16,
          1104,
          &thisa->leadfailed);
        v6 = (const char *)HIDWORD(thisa->leadr.m_hSteamLeaderboard);
        v7 = leadid_0 + 176;
        thisa->lan.lanshort[2 * v7 + 2] = (const char *)thisa->leadr.m_hSteamLeaderboard;
        thisa->lan.lanshort[2 * v7 + 3] = v6;
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040B660; symbol: __ZN5Steam7getleadEv
void __cdecl Steam::getlead(Steam *const this)
{
  int v1; // ecx
  int v2; // edx
  ISteamUserStats *v3; // eax
  int v4; // ebx
  const char *v5; // edx
  ISteamUserStats *v6; // eax
  int v7; // ebx
  const char *v8; // edx
  ISteamUserStats *v9; // eax
  int v10; // ebx
  const char *v11; // edx
  ISteamUtils *v12; // eax
  const char *v13; // edx
  int v14; // ebx
  const char *v15; // edx
  int v16; // ecx
  ISteamUserStats *v17; // eax
  Steam *v18; // [esp+0h] [ebp-68h]
  Steam *thisa; // [esp+3Ch] [ebp-2Ch]
  int k; // [esp+40h] [ebp-28h]
  int leadid_0; // [esp+44h] [ebp-24h]
  int n; // [esp+48h] [ebp-20h]
  int leadid; // [esp+4Ch] [ebp-1Ch]

  thisa = (Steam *)v1;
  if ( *(_BYTE *)(v1 + 348) )
  {
    v2 = *(_DWORD *)(v1 + 1420);
    if ( !*(_QWORD *)(v1 + 1416) || !*(_QWORD *)(v1 + 1424) || !*(_QWORD *)(v1 + 1432) )
      Steam::loadlead(v18);
    for ( leadid = 0; leadid <= 14; ++leadid )
    {
      if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
      {
        v3 = SteamUserStats();
        v4 = leadid + 122;
        thisa->lan.lanshort[2 * v4 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, _DWORD, signed int, signed int))(*(_DWORD *)v3 + 112))(
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 2],
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 3],
                                                          0,
                                                          1,
                                                          20);
        thisa->lan.lanshort[2 * v4 + 3] = v5;
        v6 = SteamUserStats();
        v7 = leadid + 137;
        thisa->lan.lanshort[2 * v7 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, signed int, signed int))(*(_DWORD *)v6 + 112))(
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 2],
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 3],
                                                          1,
                                                          -5,
                                                          4);
        thisa->lan.lanshort[2 * v7 + 3] = v8;
        v9 = SteamUserStats();
        v10 = leadid + 152;
        thisa->lan.lanshort[2 * v10 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, _DWORD, _DWORD))(*(_DWORD *)v9 + 112))(
                                                           thisa->lan.lanshort[2 * (leadid + 176) + 2],
                                                           thisa->lan.lanshort[2 * (leadid + 176) + 3],
                                                           1,
                                                           0,
                                                           0);
        thisa->lan.lanshort[2 * v10 + 3] = v11;
      }
    }
    if ( Steam::waitlead_(v18) )
    {
      for ( n = 0; n <= 2; ++n )
      {
        for ( leadid_0 = 0; leadid_0 <= 14; ++leadid_0 )
        {
          v12 = SteamUtils();
          (*(void (__fastcall **)(ISteamUtils *, const char *, const char *, const char *, LeaderboardScoresDownloaded_t *, signed int, signed int))(*(_DWORD *)v12 + 52))(
            v12,
            thisa->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 3],
            thisa->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 2],
            thisa->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 3],
            &thisa->leadd,
            24,
            1105);
          v13 = (const char *)HIDWORD(thisa->leadd.m_hSteamLeaderboard);
          v14 = leadid_0 + 176;
          thisa->lan.lanshort[2 * v14 + 2] = (const char *)thisa->leadd.m_hSteamLeaderboard;
          thisa->lan.lanshort[2 * v14 + 3] = v13;
          v15 = (const char *)HIDWORD(thisa->leadd.m_hSteamLeaderboardEntries);
          v16 = leadid_0 + 15 * n + 192;
          thisa->lan.lanshort[2 * v16] = (const char *)thisa->leadd.m_hSteamLeaderboardEntries;
          thisa->lan.lanshort[2 * v16 + 1] = v15;
          for ( k = 0; (_DWORD)thisa->lan.lanshort[n + 212 + 1] > k; ++k )
          {
            v17 = SteamUserStats();
            (*(void (__stdcall **)(const char *, const char *, int, char *, _DWORD, _DWORD))(*(_DWORD *)v17 + 120))(
              thisa->lan.lanshort[2 * (leadid_0 + 15 * n + 192)],
              thisa->lan.lanshort[2 * (leadid_0 + 15 * n + 192) + 1],
              k,
              (char *)thisa->leadsn[n] + 32 * (k + 20 * leadid_0),
              0,
              0);
          }
        }
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040BA22; symbol: __ZN5Steam7setleadEv
void __cdecl Steam::setlead(Steam *const this)
{
  Steam *v1; // ecx
  const char *v2; // edi
  ISteamUserStats *v3; // eax
  const char *v4; // ST04_4
  int v5; // eax
  const char *v6; // edx
  const char *v7; // ecx
  const char *v8; // edx
  int v9; // eax
  ISteamUtils *v10; // eax
  const char **v11; // edx
  const char *v12; // edx
  int v13; // ebx
  Steam *v14; // [esp+0h] [ebp-68h]
  Steam *v15; // [esp+0h] [ebp-68h]
  Steam *thisa; // [esp+3Ch] [ebp-2Ch]
  int k_0; // [esp+44h] [ebp-24h]
  int k; // [esp+48h] [ebp-20h]
  int leadid; // [esp+4Ch] [ebp-1Ch]
  int leadida; // [esp+4Ch] [ebp-1Ch]

  thisa = v1;
  if ( v1->steamb )
  {
    Steam::checkcheat(v14);
    for ( leadid = 0; leadid <= 2; ++leadid )
    {
      v2 = thisa->lan.lanshort[2 * (leadid + 176) + 3];
      if ( !*(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
        Steam::loadlead(v15);
      if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
      {
        for ( k = 0; k <= 4; ++k )
        {
          v3 = SteamUserStats();
          v4 = thisa->lan.lanshort[2 * (3 * k + leadid + 176) + 3];
          v5 = (*(int (__fastcall **)(ISteamUserStats *, const char *, const char *, const char *, signed int, const char *, _DWORD))(*(_DWORD *)v3 + 124))(
                 v3,
                 v4,
                 thisa->lan.lanshort[2 * (3 * k + leadid + 176) + 2],
                 v4,
                 1,
                 thisa->lan.lanshort[3 * k + leadid + 180 + 2],
                 0);
          v7 = v6;
          v8 = (const char *)v5;
          v9 = 3 * k + leadid + 108;
          thisa->lan.lanshort[2 * v9] = v8;
          thisa->lan.lanshort[2 * v9 + 1] = v7;
        }
      }
    }
    if ( Steam::waitlead(v15) )
    {
      for ( leadida = 0; leadida <= 2; ++leadida )
      {
        if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadida + 176) + 2] )
        {
          for ( k_0 = 0; k_0 <= 4; ++k_0 )
          {
            v10 = SteamUtils();
            v11 = &thisa->lan.lanshort[2 * (3 * k_0 + leadida + 108)];
            (*(void (__fastcall **)(ISteamUtils *, const char *, const char *, const char *, LeaderboardScoreUploaded_t *, signed int, signed int))(*(_DWORD *)v10 + 52))(
              v10,
              v11[1],
              *v11,
              v11[1],
              &thisa->leadu,
              32,
              1106);
            v12 = (const char *)HIDWORD(thisa->leadu.m_hSteamLeaderboard);
            v13 = 3 * k_0 + leadida + 176;
            thisa->lan.lanshort[2 * v13 + 2] = (const char *)thisa->leadu.m_hSteamLeaderboard;
            thisa->lan.lanshort[2 * v13 + 3] = v12;
          }
        }
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040BC9C; symbol: __ZN5Steam7setleadEl
void __userpurge Steam::setlead(Steam *a1@<ecx>, Steam *const this, int mode)
{
  const char *v3; // edx
  ISteamUserStats *v4; // eax
  int v5; // ebx
  const char *v6; // edx
  Steam *const v7; // ST00_4
  ISteamUtils *v8; // eax
  const char **v9; // edx
  const char *v10; // edx
  int v11; // ebx
  Steam *v12; // [esp+0h] [ebp-58h]
  Steam *v13; // [esp+0h] [ebp-58h]
  Steam *thisa; // [esp+2Ch] [ebp-2Ch]
  int leadid; // [esp+38h] [ebp-20h]
  int k; // [esp+3Ch] [ebp-1Ch]

  thisa = a1;
  if ( a1->steamb )
  {
    Steam::checkcheat(v12);
    if ( (signed int)this > 0 )
    {
      if ( thisa->newrecord )
      {
        thisa->newrecord = 0;
        leadid = (int)&this[-1].waittime + 7;
        if ( !*(_QWORD *)&thisa->lan.lanshort[2 * ((_DWORD)this + 175) + 2] )
          Steam::loadlead(v13);
        v3 = thisa->lan.lanshort[2 * (leadid + 176) + 3];
        if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
        {
          for ( k = 0; k <= 4; ++k )
          {
            v4 = SteamUserStats();
            v5 = 3 * k + leadid + 108;
            thisa->lan.lanshort[2 * v5] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, const char *, _DWORD, _DWORD))(*(_DWORD *)v4 + 124))(
                                                          thisa->lan.lanshort[2 * (leadid + 3 * k + 176) + 2],
                                                          thisa->lan.lanshort[2 * (leadid + 3 * k + 176) + 3],
                                                          1,
                                                          thisa->lan.lanshort[3 * k + leadid + 180 + 2],
                                                          0,
                                                          0);
            thisa->lan.lanshort[2 * v5 + 1] = v6;
            if ( Steam::waitlead(v7) )
            {
              v8 = SteamUtils();
              v9 = &thisa->lan.lanshort[2 * (leadid + 3 * k + 108)];
              (*(void (__stdcall **)(const char *, const char *, LeaderboardScoreUploaded_t *, signed int, signed int, bool *))(*(_DWORD *)v8 + 52))(
                *v9,
                v9[1],
                &thisa->leadu,
                32,
                1106,
                &thisa->leadfailed);
              v10 = (const char *)HIDWORD(thisa->leadu.m_hSteamLeaderboard);
              v11 = 3 * k + leadid + 176;
              thisa->lan.lanshort[2 * v11 + 2] = (const char *)thisa->leadu.m_hSteamLeaderboard;
              thisa->lan.lanshort[2 * v11 + 3] = v10;
            }
          }
        }
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040BEB6; symbol: __ZN5Steam8waitleadEv
bool __cdecl Steam::waitlead(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUtils *v2; // eax
  bool v3; // al
  ISteamUtils *v4; // eax
  bool v5; // al
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  int time; // [esp+24h] [ebp-14h]
  int leadid; // [esp+28h] [ebp-10h]
  char waitb; // [esp+2Fh] [ebp-9h]

  thisa = v1;
  if ( !v1->steamb )
    return 0;
  waitb = 1;
  time = (signed int)GetTimeR();
  for ( leadid = 0; leadid <= 14; ++leadid )
  {
    while ( 1 )
    {
      v3 = 0;
      if ( (unsigned __int8)IsWin() )
      {
        v2 = SteamUtils();
        if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v2 + 44))(
               thisa->lan.lanshort[2 * (leadid + 108)],
               thisa->lan.lanshort[2 * (leadid + 108) + 1],
               &thisa->leadfailed) ^ 1 )
        {
          if ( (long double)time + thisa->waittime > GetTimeR() )
            v3 = 1;
        }
      }
      if ( !v3 )
        break;
      Delay(1u);
    }
    v5 = 0;
    if ( waitb )
    {
      v4 = SteamUtils();
      if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v4 + 44))(
             thisa->lan.lanshort[2 * (leadid + 108)],
             thisa->lan.lanshort[2 * (leadid + 108) + 1],
             &thisa->leadfailed) )
      {
        v5 = 1;
      }
    }
    waitb = v5;
  }
  return waitb;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040BFF0; symbol: __ZN5Steam9waitlead_Ev
bool __cdecl Steam::waitlead_(Steam *const this)
{
  Steam *v1; // ecx
  ISteamUtils *v2; // eax
  bool v3; // al
  ISteamUtils *v4; // eax
  bool v5; // al
  Steam *thisa; // [esp+1Ch] [ebp-2Ch]
  int time; // [esp+20h] [ebp-28h]
  int leadid; // [esp+24h] [ebp-24h]
  int n; // [esp+28h] [ebp-20h]
  char waitb; // [esp+2Fh] [ebp-19h]

  thisa = v1;
  if ( !v1->steamb )
    return 0;
  waitb = 1;
  time = (signed int)GetTimeR();
  for ( n = 0; n <= 2; ++n )
  {
    for ( leadid = 0; leadid <= 14; ++leadid )
    {
      while ( 1 )
      {
        v3 = 0;
        if ( (unsigned __int8)IsWin() )
        {
          v2 = SteamUtils();
          if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v2 + 44))(
                 thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 2],
                 thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 3],
                 &thisa->leadfailed) ^ 1 )
          {
            if ( (long double)time + thisa->waittime > GetTimeR() )
              v3 = 1;
          }
        }
        if ( !v3 )
          break;
        Delay(1u);
      }
      v5 = 0;
      if ( waitb )
      {
        v4 = SteamUtils();
        if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v4 + 44))(
               thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 2],
               thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 3],
               &thisa->leadfailed) )
        {
          v5 = 1;
        }
      }
      waitb = v5;
    }
  }
  return waitb;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040C160; symbol: __ZN5Steam7savescrEPc
void __userpurge Steam::savescr(int a1@<ecx>, Steam *const this, char *scrpath)
{
  ISteamScreenshots *v3; // ebx
  void (__fastcall *v4)(ISteamScreenshots *, int, Steam *const , _DWORD, unsigned int); // esi
  unsigned int v5; // edi
  pbitmap v6; // eax
  int v7; // edx

  if ( *(_BYTE *)(a1 + 348) )
  {
    v3 = SteamScreenshots();
    v4 = *(void (__fastcall **)(ISteamScreenshots *, int, Steam *const , _DWORD, unsigned int))(*(_DWORD *)v3 + 4);
    v5 = GetWin()->Height;
    v6 = GetWin();
    v4(v3, v7, this, 0, v6->Width);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040C1C2; symbol: __ZN5Steam7ischeatEll
signed int __userpurge Steam::ischeat@<eax>(Steam *const this, int line, int tetris)
{
  if ( (signed int)this > 9998 )
    return 1;
  if ( (signed int)this <= 3000 || line > 98 && line <= 998 )
    return 0;
  return 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040C204; symbol: __ZN5Steam7ischeatEv
bool __cdecl Steam::ischeat(Steam *const this)
{
  int v1; // ecx

  return Steam::ischeat(*(Steam *const *)(v1 + 728), *(_DWORD *)(v1 + 764), v1);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x0040C236; symbol: __ZN5Steam10checkcheatEv
void __cdecl Steam::checkcheat(Steam *const this)
{
  Steam *const v1; // ST00_4
  Steam *v2; // [esp+0h] [ebp-18h]
  Steam *v3; // [esp+0h] [ebp-18h]

  if ( Steam::ischeat(v2) )
  {
    Steam::resetscr(v3);
    Steam::resetach(v1);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425C28; symbol: __Z10SteamUtilsv
ISteamUtils *SteamUtils()
{
  return *(ISteamUtils **)_SteamInternal_ContextInit(SteamUtils(void)::s_CallbackCounterAndContext);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425C40; symbol: __Z12SteamFriendsv
ISteamFriends *SteamFriends()
{
  return *(ISteamFriends **)_SteamInternal_ContextInit(SteamFriends(void)::s_CallbackCounterAndContext);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425C58; symbol: __Z14SteamUserStatsv
ISteamUserStats *SteamUserStats()
{
  return *(ISteamUserStats **)_SteamInternal_ContextInit(SteamUserStats(void)::s_CallbackCounterAndContext);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425C70; symbol: __Z16SteamScreenshotsv
ISteamScreenshots *SteamScreenshots()
{
  return *(ISteamScreenshots **)_SteamInternal_ContextInit(SteamScreenshots(void)::s_CallbackCounterAndContext);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425C88; symbol: __Z18SteamRemoteStoragev
ISteamRemoteStorage *SteamRemoteStorage()
{
  return *(ISteamRemoteStorage **)_SteamInternal_ContextInit(SteamRemoteStorage(void)::s_CallbackCounterAndContext);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425CA0; symbol: __Z28SteamInternal_Init_SteamAppsPP10ISteamApps
void __cdecl SteamInternal_Init_SteamApps(ISteamApps **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamApps *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMAPPS_INTERFACE_VERSION008");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425CCC; symbol: __Z29SteamInternal_Init_SteamUtilsPP11ISteamUtils
void __cdecl SteamInternal_Init_SteamUtils(ISteamUtils **p)
{
  *p = (ISteamUtils *)_SteamInternal_FindOrCreateUserInterface(0, "SteamUtils010");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425CF4; symbol: __Z31SteamInternal_Init_SteamFriendsPP13ISteamFriends
void __cdecl SteamInternal_Init_SteamFriends(ISteamFriends **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamFriends *)_SteamInternal_FindOrCreateUserInterface(v1, "SteamFriends017");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425D20; symbol: __Z33SteamInternal_Init_SteamUserStatsPP15ISteamUserStats
void __cdecl SteamInternal_Init_SteamUserStats(ISteamUserStats **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamUserStats *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMUSERSTATS_INTERFACE_VERSION012");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425D4C; symbol: __Z35SteamInternal_Init_SteamScreenshotsPP17ISteamScreenshots
void __cdecl SteamInternal_Init_SteamScreenshots(ISteamScreenshots **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamScreenshots *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMSCREENSHOTS_INTERFACE_VERSION003");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425D78; symbol: __Z37SteamInternal_Init_SteamRemoteStoragePP19ISteamRemoteStorage
void __cdecl SteamInternal_Init_SteamRemoteStorage(ISteamRemoteStorage **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamRemoteStorage *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMREMOTESTORAGE_INTERFACE_VERSION016");
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425DA4; symbol: __Z9SteamAppsv
ISteamApps *SteamApps()
{
  return *(ISteamApps **)_SteamInternal_ContextInit(SteamApps(void)::s_CallbackCounterAndContext);
}


