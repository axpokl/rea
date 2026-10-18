// Steam 初始化、成就、统计和排行榜
// 基于所选 Debug EXE 的静态反编译，按 DWARF 源文件归属恢复。
// 这是供阅读的源码式伪代码；并非已验证可编译的源码。
#include "../include/recovered_types.hpp"

// 原始位置：steam.cpp:3；地址：0x0040A610
// 调试记录声明：void Steam()
// 功能说明：构造函数：初始化成员及所拥有的子对象。
Steam::Steam()
{

  Lan::Lan(&this->lan);
  this->appid = 3665840;
  this->cheatb = 0;
  this->achgenstart = 0;
  this->achgencustom = 1;
  this->achgenmode = 2;
  this->achgenpause = 3;
  this->achgenhelp = 4;
  this->achhidcheat = 5;
  this->achhidedge = 6;
  this->achhidmark = 7;
  this->achhidright = 8;
  this->achhidalive = 9;
  this->achcumdead1 = 10;
  this->achcumdead10 = 11;
  this->achcumdead100 = 12;
  this->achcumdead1000 = 13;
  this->achcumfour1 = 14;
  this->achcumfour10 = 15;
  this->achcumfour100 = 16;
  this->achcumfour1000 = 17;
  this->achcumline100 = 18;
  this->achcumline300 = 19;
  this->achcumline600 = 20;
  this->achcumline1000 = 21;
  this->achcumtotal10 = 22;
  this->achcumtotal100 = 23;
  this->achcumtotal1000 = 24;
  this->achcumtotal10000 = 25;
  qmemcpy(this->achs, off_427140, sizeof(this->achs));
  this->scrdead = 0;
  this->scrfour = 1;
  this->scrtotal = 2;
  this->scrline = 3;
  this->scrline1 = 4;
  this->scrline2 = 5;
  this->scrline3 = 6;
  this->scrindexline = 0;
  this->scrindexmdb = 3;
  this->scrindexnomiss = 6;
  this->scrindextetris = 9;
  this->scrindexmiss = 12;
  qmemcpy(this->scrs, off_4271C0, sizeof(this->scrs));
  this->newrecord = 0;
  this->leads[0] = "1_TOP";
  this->leads[1] = "2_TOP";
  this->leads[2] = "3_TOP";
  this->leads[3] = "1_TOP_N";
  this->leads[4] = "2_TOP_N";
  this->leads[5] = "3_TOP_N";
  this->leads[6] = "1_TOP_D";
  this->leads[7] = "2_TOP_D";
  this->leads[8] = "3_TOP_D";
  this->leads[9] = "1_TOP_T";
  this->leads[10] = "2_TOP_T";
  this->leads[11] = "3_TOP_T";
  this->leads[12] = "1_TOP_M";
  this->leads[13] = "2_TOP_M";
  this->leads[14] = "3_TOP_M";
  this->leadk_[0] = 20;
  this->leadk_[1] = 15;
  this->leadk_[2] = 1;
  this->leadfailed = 1;
  this->leadsn = 0;
  this->waittime = 5.0;
  memset(this->lead, 0, 0x78u);
  memset(this->lead_, 0, 0x168u);
  memset(&this->leadr, 0, 0x10u);
  memset(&this->leadu, 0, 0x20u);
  memset(&this->leadd, 0, 0x18u);
  memset(this->leadb, 0, 0x78u);
  memset(this->leaden, 0, 0x168u);
  this->leadsn = (LeaderboardEntry_t (*)[15][20])calloc(3u, 0x2580u);
  this->initsteam();
  this->loadlan();
}


// 原始位置：steam.cpp:17；地址：0x0040AA96
// 调试记录声明：void ~Steam()
// 功能说明：析构函数：释放该对象拥有的资源。
Steam::~Steam()
{
  this->exitsteam();
}


// 原始位置：steam.cpp:22；地址：0x0040AAAC
// 调试记录声明：void initsteam()
// 功能说明：初始化 Steam 状态；调用顺序和失败条件保留。
void Steam::initsteam()
{
  __int16 *v1;
  __int16 *v2;
  __int16 *v3;
  __int16 *v4;
  ISteamUtils *v5;

  if ( (unsigned __int8)_SteamAPI_RestartAppIfNecessary(this->appid) )
  {
    v1 = this->lan.getlan(this->lan.LAN_TITLE);
    v2 = this->lan.getlan(this->lan.LAN_STEAM_LAUNCH);
    MsgBoxW(v2, v1, 0x40u);
  }
  this->steamb = _SteamAPI_Init();
  if ( this->steamb != 1 )
  {
    v3 = this->lan.getlan(this->lan.LAN_TITLE);
    v4 = this->lan.getlan(this->lan.LAN_STEAM_FAIL);
    MsgBoxW(v4, v3, 0x30u);
  }
  if ( this->steamb )
  {
    v5 = SteamUtils();
    if ( (*(int (__fastcall **)(ISteamUtils *))(*(_DWORD *)v5 + 36))(v5) != this->appid )
      MsgBox(
        "The old game MineSweeper Tetris is retired, please download the new MineSweeper Rush from Steam Store! \n"
        "https://store.steampowered.com/app/3665840",
        "MineSweeper Rush",
        0x40u);
  }
}


// 原始位置：steam.cpp:42；地址：0x0040ABD4
// 调试记录声明：void loadlan()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：const char *lanui；const char *langame。
void Steam::loadlan()
{
  ISteamUtils *v1;
  ISteamApps *v2;

  const char *langame;
  const char *lanui;

  if ( this->steamb )
  {
    v1 = SteamUtils();
    lanui = (const char *)(*(int (__fastcall **)(ISteamUtils *))(*(_DWORD *)v1 + 92))(v1);
    v2 = SteamApps();
    langame = (const char *)(*(int (__fastcall **)(ISteamApps *))(*(_DWORD *)v2 + 16))(v2);
    if ( !strcmp(langame, this->lan.lanshort[23]) )
      this->lan.initlan(lanui);
    else
      this->lan.initlan(langame);
  }
}


// 原始位置：steam.cpp:59；地址：0x0040AC56
// 调试记录声明：void exitsteam()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Steam::exitsteam()
{
  ISteamUserStats *v1;

  if ( this->steamb )
  {
    v1 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *))(*(_DWORD *)v1 + 40))(v1);
    _SteamAPI_Shutdown();
  }
}


// 原始位置：steam.cpp:68；地址：0x0040AC88
// 调试记录声明：void loadsteam()
// 功能说明：加载或刷新 Steam 相关数据。
void Steam::loadsteam()
{
  ISteamUserStats *v1;
  __int16 *v2;
  __int16 *v3;

  if ( this->steamb )
  {
    v1 = SteamUserStats();
    if ( (**(unsigned __int8 (__fastcall ***)(ISteamUserStats *))v1)(v1) ^ 1 )
    {
      v2 = this->lan.getlan(this->lan.LAN_TITLE);
      v3 = this->lan.getlan(this->lan.LAN_STEAM_Status);
      MsgBoxW(v3, v2, 0x30u);
    }
    else
    {
      this->loadach();
      this->loadscr();
      this->loadlead();
      painttitles = 0;
    }
  }
}


// 原始位置：steam.cpp:86；地址：0x0040AD30
// 调试记录声明：void resetach()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Steam::resetach()
{
  ISteamUserStats *v1;

  if ( this->steamb )
  {
    v1 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *, _DWORD))(*(_DWORD *)v1 + 84))(v1, *(_DWORD *)(*(_DWORD *)v1 + 84));
  }
}


// 原始位置：steam.cpp:94；地址：0x0040AD64
// 调试记录声明：void loadach()
// 功能说明：读取成就信息。
// 原始局部变量：long int achid。
void Steam::loadach()
{
  ISteamUserStats *v1;

  int achid;

  if ( this->steamb )
  {
    painttitles = (pbitmap)"Load Achievement";
    painttitleb = 2;
    for ( achid = 0; achid <= 25; ++achid )
    {
      v1 = SteamUserStats();
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v1 + 24))(
        v1,
        this->lan.lanshort[achid + 112 + 2],
        this->lan.lanshort[achid + 112 + 2]);
    }
  }
}


// 原始位置：steam.cpp:107；地址：0x0040ADE2
// 调试记录声明：void addach(long int achid)
// 功能说明：提交/更新成就。
void Steam::addach(int achid)
{
  ISteamUserStats *v2;
  const char *v3;
  ISteamUserStats *v4;

  if ( this->steamb && this->achb[achid] != 1 && (this->cheatb != 1 || this->achhidcheat == achid) )
  {
    v2 = SteamUserStats();
    v3 = this->lan.lanshort[achid + 112 + 2];
    (*(void (__fastcall **)(ISteamUserStats *))(*(_DWORD *)v2 + 28))(v2);
    v4 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *, _DWORD))(*(_DWORD *)v4 + 40))(v4, *(_DWORD *)(*(_DWORD *)v4 + 40));
    this->achb[achid] = 1;
  }
}


// 原始位置：steam.cpp:120；地址：0x0040AE7C
// 调试记录声明：void checkach(long int scrid, long int d, long int c, long int b, long int a, long int a_d, long int a_c, long int a_b, long int a_a)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Steam::checkach(int scrid, int d, int c, int b, int a, int a_d, int a_c, int a_b, int a_a)
{
  if ( this->steamb )
  {
    if ( (_DWORD)this->lan.lanshort[scrid + 176 + 2] < d )
    {
      if ( (_DWORD)this->lan.lanshort[scrid + 176 + 2] < c )
      {
        if ( (_DWORD)this->lan.lanshort[scrid + 176 + 2] < b )
        {
          if ( (_DWORD)this->lan.lanshort[scrid + 176 + 2] >= a )
            this->addach(a_a);
        }
        else
        {
          this->addach(a_b);
        }
      }
      else
      {
        this->addach(a_c);
      }
    }
    else
    {
      this->addach(a_d);
    }
  }
}


// 原始位置：steam.cpp:143；地址：0x0040AF42
// 调试记录声明：void loadscr()
// 功能说明：读取 Steam 统计值。
// 原始局部变量：long int scrid。
void Steam::loadscr()
{
  ISteamUserStats *v1;
  ISteamUserStats *v2;

  int scrid;

  if ( this->steamb )
  {
    painttitles = (pbitmap)"Load Status";
    painttitleb = 2;
    for ( scrid = 0; scrid <= 18; ++scrid )
    {
      this->lan.lanshort[scrid + 176 + 2] = (const char *)-1;
      v1 = SteamUserStats();
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v1 + 8))(
        v1,
        this->lan.lanshort[scrid + 156 + 3],
        this->lan.lanshort[scrid + 156 + 3]);
      if ( (_DWORD)this->lan.lanshort[scrid + 176 + 2] < 0 )
      {
        v2 = SteamUserStats();
        (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v2 + 8))(
          v2,
          this->lan.lanshort[scrid + 156 + 3],
          this->lan.lanshort[scrid + 156 + 3]);
      }
      if ( (_DWORD)this->lan.lanshort[scrid + 176 + 2] < 0 )
      {
        this->lan.lanshort[scrid + 176 + 2] = 0;
        this->steamb = 0;
      }
    }
    this->setlead();
  }
}


// 原始位置：steam.cpp:168；地址：0x0040B07E
// 调试记录声明：void setscr(long int scrid)
// 功能说明：设置统计值。
void Steam::setscr(int scrid)
{
  ISteamUserStats *v2;
  long double v3; // fst7

  if ( this->steamb )
  {
    if ( (_DWORD)this->lan.lanshort[scrid + 176 + 2] > 0 )
    {
      v2 = SteamUserStats();
      v3 = *(float *)&this->lan.lanshort[scrid + 176 + 2];
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v2 + 16))(
        v2,
        this->lan.lanshort[scrid + 156 + 3],
        this->lan.lanshort[scrid + 156 + 3]);
    }
    if ( this->scrdead == scrid )
    {
      this->checkach(this->scrdead, 1000, 100, 10, 1, this->achcumdead1000, this->achcumdead100, this->achcumdead10, this->achcumdead1);
    }
    else if ( this->scrfour == scrid )
    {
      this->checkach(this->scrfour, 1000, 100, 10, 1, this->achcumfour1000, this->achcumfour100, this->achcumfour10, this->achcumfour1);
    }
    else if ( this->scrtotal == scrid )
    {
      this->checkach(this->scrtotal, 10000, 1000, 100, 10, this->achcumtotal10000, this->achcumtotal1000, this->achcumtotal100, this->achcumtotal10);
    }
    else if ( this->scrline == scrid )
    {
      this->checkach(this->scrline, 1000, 600, 300, 100, this->achcumline1000, this->achcumline600, this->achcumline300, this->achcumline100);
    }
  }
}


// 原始位置：steam.cpp:196；地址：0x0040B2F8
// 调试记录声明：void addscr(long int scrid, long int val, long int mode)
// 功能说明：累加 Steam 统计值。
void Steam::addscr(int scrid, int val, int mode)
{
  if ( this->steamb && this->cheatb != 1 && mode > 0 )
  {
    this->lan.lanshort[scrid + 176 + 2] += val;
    this->setscr(scrid);
  }
}


// 原始位置：steam.cpp:208；地址：0x0040B364
// 调试记录声明：void maxscr(long int val, long int scrline__)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Steam::maxscr(int val, int scrline__)
{
  const char *v3;

  if ( this->steamb && (_DWORD)this->lan.lanshort[scrline__ + 176 + 2] < val )
  {
    this->lan.lanshort[scrline__ + 176 + 2] = (const char *)val;
    this->setscr(scrline__);
    if ( scrline__ <= 6 )
    {
      if ( (_DWORD)this->lan.lanshort[this->scrline + 176 + 2] <= (_DWORD)this->lan.lanshort[scrline__ + 176 + 2] )
        v3 = this->lan.lanshort[scrline__ + 176 + 2];
      else
        v3 = this->lan.lanshort[this->scrline + 176 + 2];
      this->lan.lanshort[this->scrline + 176 + 2] = v3;
      this->setscr(this->scrline);
    }
    this->newrecord = 1;
  }
}


// 原始位置：steam.cpp:226；地址：0x0040B45C
// 调试记录声明：void compscr(long int val, long int mode, long int index)
// 功能说明：比较当前数值与已有记录，按条件更新统计。
// 原始局部变量：long int scrline_。
void Steam::compscr(int val, int mode, int index)
{
  signed int scrline_;

  if ( this->steamb && this->cheatb != 1 && mode > 0 )
  {
    scrline_ = -1;
    switch ( mode )
    {
      case 2:
        scrline_ = this->scrline2;
        break;
      case 3:
        scrline_ = this->scrline3;
        break;
      case 1:
        scrline_ = this->scrline1;
        break;
    }
    if ( scrline_ > 0 )
      this->maxscr(val, index + scrline_);
  }
}


// 原始位置：steam.cpp:253；地址：0x0040B4F6
// 调试记录声明：void resetscr()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：long int scrid。
void Steam::resetscr()
{
  int scrid;

  if ( this->steamb )
  {
    for ( scrid = 0; scrid <= 18; ++scrid )
      this->lan.lanshort[scrid + 176 + 2] = 0;
  }
}


// 原始位置：steam.cpp:264；地址：0x0040B538
// 调试记录声明：void loadlead()
// 功能说明：读取排行榜状态。
// 原始局部变量：long int leadid；long int leadid。
void Steam::loadlead()
{
  ISteamUserStats *v1;
  int v2;
  const char *v3;
  ISteamUtils *v4;
  const char *v5;
  int v6;

  int leadid_0;
  int leadid;

  if ( this->steamb )
  {
    painttitles = (pbitmap)"Load Leaderboard";
    painttitleb = 2;
    for ( leadid = 0; leadid <= 14; ++leadid )
    {
      v1 = SteamUserStats();
      v2 = leadid + 108;
      this->lan.lanshort[2 * v2] = (const char *)(*(int (__fastcall **)(ISteamUserStats *, const char *))(*(_DWORD *)v1 + 92))(
                                                    v1,
                                                    this->lan.lanshort[leadid + 196 + 2]);
      this->lan.lanshort[2 * v2 + 1] = v3;
    }
    if ( this->waitlead() )
    {
      for ( leadid_0 = 0; leadid_0 <= 14; ++leadid_0 )
      {
        v4 = SteamUtils();
        (*(void (__stdcall **)(const char *, const char *, LeaderboardFindResult_t *, signed int, signed int, bool *))(*(_DWORD *)v4 + 52))(
          this->lan.lanshort[2 * (leadid_0 + 108)],
          this->lan.lanshort[2 * (leadid_0 + 108) + 1],
          &this->leadr,
          16,
          1104,
          &this->leadfailed);
        v5 = (const char *)HIDWORD(this->leadr.m_hSteamLeaderboard);
        v6 = leadid_0 + 176;
        this->lan.lanshort[2 * v6 + 2] = (const char *)this->leadr.m_hSteamLeaderboard;
        this->lan.lanshort[2 * v6 + 3] = v5;
      }
    }
  }
}


// 原始位置：steam.cpp:285；地址：0x0040B660
// 调试记录声明：void getlead()
// 功能说明：获取排行榜数据或处理回调。
// 原始局部变量：long int leadid；long int n；long int leadid；long int k。
void Steam::getlead()
{
  int v1;
  ISteamUserStats *v2;
  int v3;
  const char *v4;
  ISteamUserStats *v5;
  int v6;
  const char *v7;
  ISteamUserStats *v8;
  int v9;
  const char *v10;
  ISteamUtils *v11;
  const char *v12;
  int v13;
  const char *v14;
  int v15;
  ISteamUserStats *v16;

  int k;
  int leadid_0;
  int n;
  int leadid;

  if ( this->steamb )
  {
    v1 = HIDWORD(this->leadb[0]);
    if ( !this->leadb[0] || !this->leadb[1] || !this->leadb[2] )
      this->loadlead();
    for ( leadid = 0; leadid <= 14; ++leadid )
    {
      if ( *(_QWORD *)&this->lan.lanshort[2 * (leadid + 176) + 2] )
      {
        v2 = SteamUserStats();
        v3 = leadid + 122;
        this->lan.lanshort[2 * v3 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, _DWORD, signed int, signed int))(*(_DWORD *)v2 + 112))(
                                                          this->lan.lanshort[2 * (leadid + 176) + 2],
                                                          this->lan.lanshort[2 * (leadid + 176) + 3],
                                                          0,
                                                          1,
                                                          20);
        this->lan.lanshort[2 * v3 + 3] = v4;
        v5 = SteamUserStats();
        v6 = leadid + 137;
        this->lan.lanshort[2 * v6 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, signed int, signed int))(*(_DWORD *)v5 + 112))(
                                                          this->lan.lanshort[2 * (leadid + 176) + 2],
                                                          this->lan.lanshort[2 * (leadid + 176) + 3],
                                                          1,
                                                          -5,
                                                          4);
        this->lan.lanshort[2 * v6 + 3] = v7;
        v8 = SteamUserStats();
        v9 = leadid + 152;
        this->lan.lanshort[2 * v9 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, _DWORD, _DWORD))(*(_DWORD *)v8 + 112))(
                                                          this->lan.lanshort[2 * (leadid + 176) + 2],
                                                          this->lan.lanshort[2 * (leadid + 176) + 3],
                                                          1,
                                                          0,
                                                          0);
        this->lan.lanshort[2 * v9 + 3] = v10;
      }
    }
    if ( this->waitlead_() )
    {
      for ( n = 0; n <= 2; ++n )
      {
        for ( leadid_0 = 0; leadid_0 <= 14; ++leadid_0 )
        {
          v11 = SteamUtils();
          (*(void (__fastcall **)(ISteamUtils *, const char *, const char *, const char *, LeaderboardScoresDownloaded_t *, signed int, signed int))(*(_DWORD *)v11 + 52))(
            v11,
            this->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 3],
            this->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 2],
            this->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 3],
            &this->leadd,
            24,
            1105);
          v12 = (const char *)HIDWORD(this->leadd.m_hSteamLeaderboard);
          v13 = leadid_0 + 176;
          this->lan.lanshort[2 * v13 + 2] = (const char *)this->leadd.m_hSteamLeaderboard;
          this->lan.lanshort[2 * v13 + 3] = v12;
          v14 = (const char *)HIDWORD(this->leadd.m_hSteamLeaderboardEntries);
          v15 = leadid_0 + 15 * n + 192;
          this->lan.lanshort[2 * v15] = (const char *)this->leadd.m_hSteamLeaderboardEntries;
          this->lan.lanshort[2 * v15 + 1] = v14;
          for ( k = 0; (_DWORD)this->lan.lanshort[n + 212 + 1] > k; ++k )
          {
            v16 = SteamUserStats();
            (*(void (__stdcall **)(const char *, const char *, int, char *, _DWORD, _DWORD))(*(_DWORD *)v16 + 120))(
              this->lan.lanshort[2 * (leadid_0 + 15 * n + 192)],
              this->lan.lanshort[2 * (leadid_0 + 15 * n + 192) + 1],
              k,
              (char *)this->leadsn[n] + 32 * (k + 20 * leadid_0),
              0,
              0);
          }
        }
      }
    }
  }
}


// 原始位置：steam.cpp:321；地址：0x0040BA22
// 调试记录声明：void setlead()
// 功能说明：设置/提交排行榜相关数据。
// 原始局部变量：long int leadid；long int k；long int k。
void Steam::setlead()
{
  const char *v1;
  ISteamUserStats *v2;
  const char *v3;
  int v4;
  const char *v5;
  const char *v6;
  const char *v7;
  int v8;
  ISteamUtils *v9;
  const char **v10;
  const char *v11;
  int v12;

  int k_0;
  int k;
  int leadid;
  int leadida;

  if ( this->steamb )
  {
    this->checkcheat();
    for ( leadid = 0; leadid <= 2; ++leadid )
    {
      v1 = this->lan.lanshort[2 * (leadid + 176) + 3];
      if ( !*(_QWORD *)&this->lan.lanshort[2 * (leadid + 176) + 2] )
        this->loadlead();
      if ( *(_QWORD *)&this->lan.lanshort[2 * (leadid + 176) + 2] )
      {
        for ( k = 0; k <= 4; ++k )
        {
          v2 = SteamUserStats();
          v3 = this->lan.lanshort[2 * (3 * k + leadid + 176) + 3];
          v4 = (*(int (__fastcall **)(ISteamUserStats *, const char *, const char *, const char *, signed int, const char *, _DWORD))(*(_DWORD *)v2 + 124))(
                 v2,
                 v3,
                 this->lan.lanshort[2 * (3 * k + leadid + 176) + 2],
                 v3,
                 1,
                 this->lan.lanshort[3 * k + leadid + 180 + 2],
                 0);
          v6 = v5;
          v7 = (const char *)v4;
          v8 = 3 * k + leadid + 108;
          this->lan.lanshort[2 * v8] = v7;
          this->lan.lanshort[2 * v8 + 1] = v6;
        }
      }
    }
    if ( this->waitlead() )
    {
      for ( leadida = 0; leadida <= 2; ++leadida )
      {
        if ( *(_QWORD *)&this->lan.lanshort[2 * (leadida + 176) + 2] )
        {
          for ( k_0 = 0; k_0 <= 4; ++k_0 )
          {
            v9 = SteamUtils();
            v10 = &this->lan.lanshort[2 * (3 * k_0 + leadida + 108)];
            (*(void (__fastcall **)(ISteamUtils *, const char *, const char *, const char *, LeaderboardScoreUploaded_t *, signed int, signed int))(*(_DWORD *)v9 + 52))(
              v9,
              v10[1],
              *v10,
              v10[1],
              &this->leadu,
              32,
              1106);
            v11 = (const char *)HIDWORD(this->leadu.m_hSteamLeaderboard);
            v12 = 3 * k_0 + leadida + 176;
            this->lan.lanshort[2 * v12 + 2] = (const char *)this->leadu.m_hSteamLeaderboard;
            this->lan.lanshort[2 * v12 + 3] = v11;
          }
        }
      }
    }
  }
}


// 原始位置：steam.cpp:358；地址：0x0040BC9C
// 调试记录声明：void setlead(long int mode)
// 功能说明：设置/提交排行榜相关数据。
// 原始局部变量：long int leadid；long int k。
void Steam::setlead(int mode)
{
  ISteamUserStats *v2;
  int v3;
  const char *v4;
  ISteamUtils *v5;
  const char **v6;
  const char *v7;
  int v8;

  int leadid;
  int k;

  if ( this->steamb )
  {
    this->checkcheat();
    if ( mode > 0 )
    {
      if ( this->newrecord )
      {
        this->newrecord = 0;
        leadid = mode - 1;
        if ( !*(_QWORD *)&this->lan.lanshort[2 * (mode - 1 + 176) + 2] )
          this->loadlead();
        if ( *(_QWORD *)&this->lan.lanshort[2 * (leadid + 176) + 2] )
        {
          for ( k = 0; k <= 4; ++k )
          {
            v2 = SteamUserStats();
            v3 = 3 * k + leadid + 108;
            this->lan.lanshort[2 * v3] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, const char *, _DWORD, _DWORD))(*(_DWORD *)v2 + 124))(
                                                          this->lan.lanshort[2 * (leadid + 3 * k + 176) + 2],
                                                          this->lan.lanshort[2 * (leadid + 3 * k + 176) + 3],
                                                          1,
                                                          this->lan.lanshort[3 * k + leadid + 180 + 2],
                                                          0,
                                                          0);
            this->lan.lanshort[2 * v3 + 1] = v4;
            if ( this->waitlead() )
            {
              v5 = SteamUtils();
              v6 = &this->lan.lanshort[2 * (leadid + 3 * k + 108)];
              (*(void (__stdcall **)(const char *, const char *, LeaderboardScoreUploaded_t *, signed int, signed int, bool *))(*(_DWORD *)v5 + 52))(
                *v6,
                v6[1],
                &this->leadu,
                32,
                1106,
                &this->leadfailed);
              v7 = (const char *)HIDWORD(this->leadu.m_hSteamLeaderboard);
              v8 = 3 * k + leadid + 176;
              this->lan.lanshort[2 * v8 + 2] = (const char *)this->leadu.m_hSteamLeaderboard;
              this->lan.lanshort[2 * v8 + 3] = v7;
            }
          }
        }
      }
    }
  }
}


// 原始位置：steam.cpp:387；地址：0x0040BEB6
// 调试记录声明：bool waitlead()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：bool waitb；long int time；long int leadid。
bool Steam::waitlead()
{
  ISteamUtils *v1;
  bool v2;
  ISteamUtils *v3;
  bool v4;

  int time;
  int leadid;
  char waitb;

  if ( !this->steamb )
    return 0;
  waitb = 1;
  time = (signed int)GetTimeR();
  for ( leadid = 0; leadid <= 14; ++leadid )
  {
    while ( 1 )
    {
      v2 = 0;
      if ( (unsigned __int8)IsWin() )
      {
        v1 = SteamUtils();
        if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v1 + 44))(
               this->lan.lanshort[2 * (leadid + 108)],
               this->lan.lanshort[2 * (leadid + 108) + 1],
               &this->leadfailed) ^ 1 )
        {
          if ( (long double)time + this->waittime > GetTimeR() )
            v2 = 1;
        }
      }
      if ( !v2 )
        break;
      Delay(1u);
    }
    v4 = 0;
    if ( waitb )
    {
      v3 = SteamUtils();
      if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v3 + 44))(
             this->lan.lanshort[2 * (leadid + 108)],
             this->lan.lanshort[2 * (leadid + 108) + 1],
             &this->leadfailed) )
      {
        v4 = 1;
      }
    }
    waitb = v4;
  }
  return waitb;
}


// 原始位置：steam.cpp:406；地址：0x0040BFF0
// 调试记录声明：bool waitlead_()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：bool waitb；long int time；long int n；long int leadid。
bool Steam::waitlead_()
{
  ISteamUtils *v1;
  bool v2;
  ISteamUtils *v3;
  bool v4;

  int time;
  int leadid;
  int n;
  char waitb;

  if ( !this->steamb )
    return 0;
  waitb = 1;
  time = (signed int)GetTimeR();
  for ( n = 0; n <= 2; ++n )
  {
    for ( leadid = 0; leadid <= 14; ++leadid )
    {
      while ( 1 )
      {
        v2 = 0;
        if ( (unsigned __int8)IsWin() )
        {
          v1 = SteamUtils();
          if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v1 + 44))(
                 this->lan.lanshort[2 * (leadid + 15 * n + 122) + 2],
                 this->lan.lanshort[2 * (leadid + 15 * n + 122) + 3],
                 &this->leadfailed) ^ 1 )
          {
            if ( (long double)time + this->waittime > GetTimeR() )
              v2 = 1;
          }
        }
        if ( !v2 )
          break;
        Delay(1u);
      }
      v4 = 0;
      if ( waitb )
      {
        v3 = SteamUtils();
        if ( (*(unsigned __int8 (__stdcall **)(const char *, const char *, bool *))(*(_DWORD *)v3 + 44))(
               this->lan.lanshort[2 * (leadid + 15 * n + 122) + 2],
               this->lan.lanshort[2 * (leadid + 15 * n + 122) + 3],
               &this->leadfailed) )
        {
          v4 = 1;
        }
      }
      waitb = v4;
    }
  }
  return waitb;
}


// 原始位置：steam.cpp:428；地址：0x0040C160
// 调试记录声明：void savescr(char *scrpath)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Steam::savescr(char *scrpath)
{
  ISteamScreenshots *v2;
  void (__fastcall *v3)(ISteamScreenshots *, int, char *, _DWORD, unsigned int);
  unsigned int v4;
  unsigned int v5;
  int v6;

  if ( this->steamb )
  {
    v2 = SteamScreenshots();
    v3 = *(void (__fastcall **)(ISteamScreenshots *, int, char *, _DWORD, unsigned int))(*(_DWORD *)v2 + 4);
    v4 = GetWin()->Height;
    v5 = GetWin()->Width;
    v3(v2, v6, scrpath, 0, v5);
  }
}


// 原始位置：steam.cpp:436；地址：0x0040C1C2
// 调试记录声明：bool ischeat(long int line, long int tetris)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool Steam::ischeat(int line, int tetris)
{
  if ( line > 9998 )
    return 1;
  if ( line <= 3000 || tetris > 98 && tetris <= 998 )
    return 0;
  return 1;
}


// 原始位置：steam.cpp:449；地址：0x0040C204
// 调试记录声明：bool ischeat()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool Steam::ischeat()
{
  return this->ischeat(this->scr[4], this->scr[13]);
}


// 原始位置：steam.cpp:454；地址：0x0040C236
// 调试记录声明：void checkcheat()
// 功能说明：更新作弊相关状态；不推断具体触发条件之外的行为。
void Steam::checkcheat()
{

  if ( this->ischeat() )
  {
    this->resetscr();
    this->resetach();
  }
}

