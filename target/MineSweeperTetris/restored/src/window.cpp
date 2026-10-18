// 游戏窗口、输入、绘制、配置和存档
// 基于所选 Debug EXE 的静态反编译，按 DWARF 源文件归属恢复。
// 这是供阅读的源码式伪代码；并非已验证可编译的源码。
#include "../include/recovered_types.hpp"

// 原始位置：window.cpp:3；地址：0x0040C264
// 调试记录声明：DWORD loadallpaintstatic(LPVOID lpParam)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：Window *window。
DWORD __stdcall loadallpaintstatic(LPVOID lpParam)
{
  ((Window *const )lpParam)->loadallpaint();
  return 0;
}


// 原始位置：window.cpp:10；地址：0x0040C283
// 调试记录声明：DWORD getlead(LPVOID p)
// 功能说明：获取排行榜数据或处理回调。
// 原始局部变量：Window *win。
DWORD __stdcall getlead(LPVOID p)
{
  if ( !*((_BYTE *)p + 3382) )
  {
    *((_BYTE *)p + 3382) = 1;
    ((Window *const )p)->paintevent();
    ((Steam *const )((char *)p + 840))->getlead();
    ((Window *const )p)->paintevent();
    *((_BYTE *)p + 3382) = 0;
  }
  return 0;
}


// 原始位置：window.cpp:22；地址：0x0040C2E4
// 调试记录声明：void Window()
// 功能说明：构造函数：初始化成员及所拥有的子对象。
Window::Window()
{

  this->launchw = 320;
  this->launchh = 368;
  this->titlew = 256;
  this->titleh = 256;
  this->menuw = 24;
  this->menuh = 24;
  this->facew = 24;
  this->faceh = 24;
  this->iconw = 16;
  this->iconh = 16;
  this->digtw[0] = 13;
  this->digtw[1] = 9;
  this->digtw[2] = 13;
  this->digth[0] = 24;
  this->digth[1] = 17;
  this->digth[2] = 24;
  this->okw = 144;
  this->okh = 36;
  this->btnw = 36;
  this->btnh = 36;
  this->tutw = 120;
  this->tuth = 36;
  this->aboutw = 360;
  this->abouth = 240;
  this->helpw = 640;
  this->helph = 480;
  this->fontth = 64;
  this->fontfh = 32;
  this->fonth = 24;
  this->fontsh = 17;
  this->fontmh = 13;
  this->okh_ = this->abouth - (this->fontth + 4 * this->fonth);
  this->cursorw = 12;
  this->cursorh = 19;
  this->clickw = 48;
  this->clickh = 72;
  this->arroww = 24;
  this->arrowh = 24;
  this->ptitle_ = 0;
  this->pbg_ = 0;
  this->pmenu_ = 0;
  this->pmenu1[0] = 0;
  this->pmenu1[1] = 0;
  this->pmenu2[0] = 0;
  this->pmenu2[1] = 0;
  this->pmenu3[0] = 0;
  this->pmenu3[1] = 0;
  this->pmenuq[0] = 0;
  this->pmenuq[1] = 0;
  this->pmenua[0] = 0;
  this->pmenua[1] = 0;
  this->pmenus[0] = 0;
  this->pmenus[1] = 0;
  this->pmenum[0] = 0;
  this->pmenum[1] = 0;
  this->pmenut[0] = 0;
  this->pmenut[1] = 0;
  this->pmenud[0] = 0;
  this->pmenud[1] = 0;
  this->pmenun[0] = 0;
  this->pmenun[1] = 0;
  memset(this->pmenug, 0, sizeof(this->pmenug));
  this->pface_ = 0;
  memset(this->pface, 0, sizeof(this->pface));
  this->picon_ = 0;
  memset(this->picon, 0, sizeof(this->picon));
  this->piconc = 0;
  this->piconq = 0;
  this->piconf = 0;
  this->piconm = 0;
  this->picone = 0;
  this->piconn = 0;
  this->piconp = 0;
  this->picona = 0;
  this->piconu = 0;
  this->pdigt_[0] = 0;
  this->pdigt_[1] = 0;
  this->pdigt_[2] = 0;
  memset(this->pdigt, 0, sizeof(this->pdigt));
  this->pdigtmin[0] = 0;
  this->pdigtmin[1] = 0;
  this->pdigtmin[2] = 0;
  this->pdigtnul[0] = 0;
  this->pdigtnul[1] = 0;
  this->pdigtnul[2] = 0;
  this->pok_ = 0;
  this->pok = 0;
  this->pbtn = 0;
  this->pcursor_ = 0;
  this->pcursor = 0;
  this->pclick_ = 0;
  this->pclickl = 0;
  this->pclickr = 0;
  this->pclickn = 0;
  this->pclicka = 0;
  this->parrow_ = 0;
  this->parrowl = 0;
  this->parrowr = 0;
  this->parrowu = 0;
  this->parrowd = 0;
  this->parrowm = 0;
  this->parrowp = 0;
  this->transparent = 1;
  this->color[0] = 12632256;
  this->color[1] = 11513775;
  this->color[2] = 65793;
  this->color[3] = 12632256;
  this->color[4] = 255;
  this->color[5] = 16711680;
  this->color[6] = 0x8000;
  this->color[7] = 8421504;
  this->color[8] = 12632256;
  this->colori = 0;
  this->transparent_ = 11513775;
  this->isbmp = 0;
  Reg::Reg(&this->reg);
  Board::Board(&this->bd);
  Block::Block(&this->bl);
  this->maxhelp = 6;
  this->helpi = 0;
  this->helpb = 1;
  this->cheatb = 0;
  this->waitb = 0;
  this->pwin = 0;
  this->pwint = 0;
  this->minh = 600;
  this->minw = 800;
  this->mult_ = 0;
  this->mult = 1.0;
  this->showmax = 0;
  this->showmax_ = 0;
  this->w_ = 0;
  this->h_ = 0;
  this->x_ = 0;
  this->y_ = 0;
  this->xscr = 0;
  this->yscr = 0;
  this->wscr = 0;
  this->hscr = 0;
  this->barb = 1;
  this->md = 0;
  this->ml = 0;
  this->mr = 0;
  this->mx = -1;
  this->my = -1;
  this->mi = 0;
  this->lead_5 = 0;
  this->singleb = 0;
  this->boardb = 0;
  this->timerefresh = 0.0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&this->cs);
  this->initwindow();
}


// 原始位置：window.cpp:28；地址：0x0040CA6C
// 调试记录声明：void ~Window()
// 功能说明：析构函数：释放该对象拥有的资源。
Window::~Window()
{

  this->releasewindow();
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->cs);
  Board::~Board(&this->bd);
  Reg::~Reg(&this->reg);
}


// 原始位置：window.cpp:34；地址：0x0040CAB4
// 调试记录声明：void loadsettingcloud()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：long int buf[9]；int pos。
void Window::loadsettingcloud()
{
  ISteamRemoteStorage *v1;
  ISteamRemoteStorage *v2;
  ISteamRemoteStorage *v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  int v9;
  int v10;
  int v11;

  int buf[9];
  int pos;

  if ( SteamRemoteStorage() != 0 )
  {
    v1 = SteamRemoteStorage();
    if ( !((*(unsigned __int8 (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v1 + 52))(
             v1,
             *(_DWORD *)(*(_DWORD *)v1 + 52)) ^ 1) )
    {
      memset(buf, 0, sizeof(buf));
      v2 = SteamRemoteStorage();
      if ( (*(int (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v2 + 60))(
             v2,
             *(_DWORD *)(*(_DWORD *)v2 + 60)) == 36 )
      {
        v3 = SteamRemoteStorage();
        (*(void (__fastcall **)(ISteamRemoteStorage *, int *, const char *, int *))(*(_DWORD *)v3 + 4))(
          v3,
          buf,
          "reg.dat",
          buf);
        pos = 1;
        this->helpb = buf[0] != 0;
        v4 = pos++;
        this->colori = buf[v4];
        v5 = pos++;
        this->md = buf[v5];
        v6 = pos++;
        this->bd.sd.soundb = buf[v6] != 0;
        v7 = pos++;
        this->bd.sd.musicb = buf[v7] != 0;
        v8 = pos++;
        this->mult_ = buf[v8];
        v9 = pos++;
        this->bd.delayb = buf[v9];
        v10 = pos++;
        this->barb = buf[v10] != 0;
        v11 = pos++;
        this->singleb = buf[v11] != 0;
      }
    }
  }
}


// 原始位置：window.cpp:53；地址：0x0040CC4E
// 调试记录声明：void savesettingcloud()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：long int buf[9]；int pos。
void Window::savesettingcloud()
{
  ISteamRemoteStorage *v1;

  int buf[9];
  int pos;

  if ( SteamRemoteStorage() != 0 )
  {
    pos = 1;
    buf[0] = this->helpb;
    pos = 2;
    buf[1] = this->colori;
    pos = 3;
    buf[2] = this->md;
    pos = 4;
    buf[3] = this->bd.sd.soundb;
    pos = 5;
    buf[4] = this->bd.sd.musicb;
    pos = 6;
    buf[5] = this->mult_;
    pos = 7;
    buf[6] = this->bd.delayb;
    pos = 8;
    buf[7] = this->barb;
    pos = 9;
    buf[8] = this->singleb;
    v1 = SteamRemoteStorage();
    (**(void (__fastcall ***)(ISteamRemoteStorage *, int *, const char *, int *))v1)(v1, buf, "reg.dat", buf);
  }
}


// 原始位置：window.cpp:70；地址：0x0040CD7A
// 调试记录声明：void loadsetting()
// 功能说明：读取本地配置；保留原有默认值和读取失败处理。
void Window::loadsetting()
{

  this->reg.getreg(this->reg.regkey, (const char *)&key, (int *)&this->helpb);
  this->reg.getreg(this->reg.regkey, (const char *)&stru_428FF2, &this->colori);
  this->reg.getreg(this->reg.regkey, (const char *)&unk_428FF9, &this->md);
  this->reg.getreg(this->reg.regkey, (const char *)&stru_428FFC, (int *)&this->bd.sd.soundb);
  this->reg.getreg(this->reg.regkey, (const char *)&stru_429003, (int *)&this->bd.sd.musicb);
  this->reg.getreg(this->reg.regkey, (const char *)&stru_42900A, &this->mult_);
  this->reg.getreg(this->reg.regkey, (const char *)&stru_42900F, &this->bd.delayb);
  this->reg.getreg(this->reg.regkey, (const char *)&stru_429016, (int *)&this->barb);
  this->reg.getreg(this->reg.regkey, (const char *)&stru_42901B, (int *)&this->singleb);
  this->loadsettingcloud();
}


// 原始位置：window.cpp:84；地址：0x0040CF64
// 调试记录声明：void savesetting()
// 功能说明：写入本地配置；具体字段与字节长度见代码。
void Window::savesetting()
{

  this->reg.setreg(this->reg.regkey, (const char *)&key, this->helpb);
  this->reg.setreg(this->reg.regkey, (const char *)&stru_428FF2, this->colori);
  this->reg.setreg(this->reg.regkey, (const char *)&unk_428FF9, this->md);
  this->reg.setreg(this->reg.regkey, (const char *)&stru_428FFC, this->bd.sd.soundb);
  this->reg.setreg(this->reg.regkey, (const char *)&stru_429003, this->bd.sd.musicb);
  this->reg.setreg(this->reg.regkey, (const char *)&stru_42900A, this->mult_);
  this->reg.setreg(this->reg.regkey, (const char *)&stru_42900F, this->bd.delayb);
  this->reg.setreg(this->reg.regkey, (const char *)&stru_429016, this->barb);
  this->reg.setreg(this->reg.regkey, (const char *)&stru_42901B, this->singleb);
  this->savesettingcloud();
}


// 原始位置：window.cpp:98；地址：0x0040D150
// 调试记录声明：void loadboardcloud()
// 功能说明：读取 Steam 云相关棋盘存储。
// 原始局部变量：/*DW_TAG_structure_type*/ void buf；int pos。
void Window::loadboardcloud()
{
  int v1;
  void *v2; // esp
  ISteamRemoteStorage *v3;
  ISteamRemoteStorage *v4;
  ISteamRemoteStorage *v5;
  int v6;
  int v7;
  int v8;
  int v9;
  int v10;
  int v11;
  int v12;
  int v13;
  int v14;
  int v15;
  int v16;
  int v17;
  int v18;
  int v19;
  int v20;
  int v21;
  int v22;
  int v23;
  int v24;
  int v25;
  int v26;
  int v27;
  int v28;

  int v30[25];
  char v31;
  char v32;
  char v33;
  char v34;
  char v35;
  int v36;

  v2 = alloca(v1);

  if ( SteamRemoteStorage() != 0 )
  {
    v3 = SteamRemoteStorage();
    if ( !((*(unsigned __int8 (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v3 + 52))(
             v3,
             *(_DWORD *)(*(_DWORD *)v3 + 52)) ^ 1) )
    {
      v4 = SteamRemoteStorage();
      if ( (*(int (__fastcall **)(ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v4 + 60))(
             v4,
             *(_DWORD *)(*(_DWORD *)v4 + 60)) == 82020 )
      {
        v5 = SteamRemoteStorage();
        (*(void (__fastcall **)(ISteamRemoteStorage *, int *, const char *, int *))(*(_DWORD *)v5 + 4))(
          v5,
          v30,
          "board.dat",
          v30);
        v36 = 1;
        this->bd.mode = v30[0];
        v6 = v36++;
        this->bd.w = v30[v6];
        v7 = v36++;
        this->bd.h = v30[v7];
        v8 = v36++;
        this->bd.n = v30[v8];
        v9 = v36++;
        this->bd.maskj0 = v30[v9];
        v10 = v36++;
        this->bd.sit = v30[v10];
        v11 = v36++;
        this->bd.line = v30[v11];
        v12 = v36++;
        this->bd.level = v30[v12];
        v13 = v36++;
        this->bd.tetrisi = v30[v13];
        v14 = v36++;
        this->bd.missi = v30[v14];
        v15 = v36++;
        this->bd.missline = v30[v15];
        v16 = v36++;
        this->bd.sum = v30[v16];
        v17 = v36++;
        this->bd.maskj = v30[v17];
        v18 = v36++;
        this->bd.maski = v30[v18];
        v19 = v36++;
        this->bd.rightb = v30[v19];
        v20 = v36++;
        this->bd.tuti = v30[v20];
        v21 = v36++;
        this->bd.tutb = v30[v21];
        v22 = v36++;
        this->bd.checkr = v30[v22];
        v23 = v36++;
        this->bd.pauseb = v30[v23];
        v24 = v36++;
        this->bd.mx = v30[v24];
        v25 = v36++;
        this->bd.my = v30[v25];
        v26 = v36++;
        this->bd.bouns = v30[v26];
        v27 = v36++;
        this->bd.mdb = v30[v27];
        v28 = v36++;
        this->bd.solven = v30[v28];
        memcpy(this->bd.flag, &v31, 0x4000u);
        memcpy(this->bd.qstn, &v32, 0x4000u);
        memcpy(this->bd.mine, &v33, 0x4000u);
        memcpy(this->bd.blck, &v34, 0x4000u);
        memcpy(this->bd.mask, &v35, 0x4000u);
        (&this->bd.0)->calcnumb();
      }
    }
  }
}


// 原始位置：window.cpp:146；地址：0x0040D588
// 调试记录声明：void saveboardcloud()
// 功能说明：将棋盘状态保存至 Steam 云相关存储。
// 原始局部变量：/*DW_TAG_structure_type*/ void buf；int pos。
void Window::saveboardcloud()
{
  int v1;
  void *v2; // esp
  ISteamRemoteStorage *v3;

  int v5;
  int v6;
  int v7;
  int v8;
  int v9;
  int v10;
  int v11;
  int v12;
  int v13;
  int v14;
  int v15;
  int v16;
  int v17;
  int v18;
  int v19;
  int v20;
  int v21;
  int v22;
  int v23;
  int v24;
  int v25;
  int v26;
  int v27;
  int v28;
  char v29;
  char v30;
  char v31;
  char v32;
  char v33;
  int v34;

  v2 = alloca(v1);

  if ( SteamRemoteStorage() != 0 )
  {
    v34 = 1;
    v5 = this->bd.mode;
    v34 = 2;
    v6 = this->bd.w;
    v34 = 3;
    v7 = this->bd.h;
    v34 = 4;
    v8 = this->bd.n;
    v34 = 5;
    v9 = this->bd.maskj0;
    v34 = 6;
    v10 = this->bd.sit;
    v34 = 7;
    v11 = this->bd.line;
    v34 = 8;
    v12 = this->bd.level;
    v34 = 9;
    v13 = this->bd.tetrisi;
    v34 = 10;
    v14 = this->bd.missi;
    v34 = 11;
    v15 = this->bd.missline;
    v34 = 12;
    v16 = this->bd.sum;
    v34 = 13;
    v17 = this->bd.maskj;
    v34 = 14;
    v18 = this->bd.maski;
    v34 = 15;
    v19 = this->bd.rightb;
    v34 = 16;
    v20 = this->bd.tuti;
    v34 = 17;
    v21 = this->bd.tutb;
    v34 = 18;
    v22 = this->bd.checkr;
    v34 = 19;
    v23 = this->bd.pauseb;
    v34 = 20;
    v24 = this->bd.mx;
    v34 = 21;
    v25 = this->bd.my;
    v34 = 22;
    v26 = this->bd.bouns;
    v34 = 23;
    v27 = this->bd.mdb;
    v34 = 24;
    v28 = this->bd.solven;
    memcpy(&v29, this->bd.flag, 0x4000u);
    memcpy(&v30, this->bd.qstn, 0x4000u);
    memcpy(&v31, this->bd.mine, 0x4000u);
    memcpy(&v32, this->bd.blck, 0x4000u);
    memcpy(&v33, this->bd.mask, 0x4000u);
    v3 = SteamRemoteStorage();
    (**(void (__fastcall ***)(ISteamRemoteStorage *, int *, const char *, int *))v3)(v3, &v5, "board.dat", &v5);
  }
}


// 原始位置：window.cpp:191；地址：0x0040D94C
// 调试记录声明：void loadboard()
// 功能说明：读取本地棋盘状态并更新内存结构。
void Window::loadboard()
{

  this->reg.getreg(this->reg.regkey_, (const char *)&stru_42902D, &this->bd.mode);
  this->reg.getreg(this->reg.regkey_, (const char *)&unk_429032, &this->bd.w);
  this->reg.getreg(this->reg.regkey_, (const char *)&unk_429034, &this->bd.h);
  this->reg.getreg(this->reg.regkey_, (const char *)&unk_429036, &this->bd.n);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_429038, &this->bd.maskj0);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_42903F, &this->bd.sit);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_429043, &this->bd.line);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_429048, &this->bd.level);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_42904E, &this->bd.tetrisi);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_429056, &this->bd.missi);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_42905C, &this->bd.missline);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_429065, &this->bd.sum);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_429069, &this->bd.maskj);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_42906F, &this->bd.maski);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_429075, &this->bd.rightb);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_42907C, &this->bd.tuti);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_429081, &this->bd.tutb);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_429086, &this->bd.checkr);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_42908D, &this->bd.pauseb);
  this->reg.getreg(this->reg.regkey_, (const char *)&unk_429094, &this->bd.mx);
  this->reg.getreg(this->reg.regkey_, (const char *)&unk_429097, &this->bd.my);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_42909A, &this->bd.bouns);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_4290A0, &this->bd.mdb);
  this->reg.getreg(this->reg.regkey_, (const char *)&stru_4290A4, &this->bd.solven);
  this->reg.getreg_(this->reg.regkey_, (const char *)&stru_4290AB, (char *)this->bd.flag);
  this->reg.getreg_(this->reg.regkey_, (const char *)&stru_4290B0, (char *)this->bd.qstn);
  this->reg.getreg_(this->reg.regkey_, (const char *)&stru_4290B5, (char *)this->bd.mine);
  this->reg.getreg_(this->reg.regkey_, (const char *)&stru_4290BA, (char *)this->bd.blck);
  this->reg.getreg_(this->reg.regkey_, (const char *)&stru_4290BF, (char *)this->bd.mask);
  this->loadboardcloud();
  (&this->bd.0)->calcnumb();
}


// 原始位置：window.cpp:226；地址：0x0040DF60
// 调试记录声明：void saveboard()
// 功能说明：保存本地棋盘状态；文件结构仍按原始写入顺序表达。
void Window::saveboard()
{

  this->reg.setreg(this->reg.regkey_, (const char *)&stru_42902D, this->bd.mode);
  this->reg.setreg(this->reg.regkey_, (const char *)&unk_429032, this->bd.w);
  this->reg.setreg(this->reg.regkey_, (const char *)&unk_429034, this->bd.h);
  this->reg.setreg(this->reg.regkey_, (const char *)&unk_429036, this->bd.n);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_429038, this->bd.maskj0);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_42903F, this->bd.sit);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_429043, this->bd.line);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_429048, this->bd.level);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_42904E, this->bd.tetrisi);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_429056, this->bd.missi);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_42905C, this->bd.missline);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_429065, this->bd.sum);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_429069, this->bd.maskj);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_42906F, this->bd.maski);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_429075, this->bd.rightb);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_42907C, this->bd.tuti);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_429081, this->bd.tutb);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_429086, this->bd.checkr);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_42908D, this->bd.pauseb);
  this->reg.setreg(this->reg.regkey_, (const char *)&unk_429094, this->bd.mx);
  this->reg.setreg(this->reg.regkey_, (const char *)&unk_429097, this->bd.my);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_42909A, this->bd.bouns);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_4290A0, this->bd.mdb);
  this->reg.setreg(this->reg.regkey_, (const char *)&stru_4290A4, this->bd.solven);
  this->reg.setreg_(this->reg.regkey_, (const char *)&stru_4290AB, (char *)this->bd.flag);
  this->reg.setreg_(this->reg.regkey_, (const char *)&stru_4290B0, (char *)this->bd.qstn);
  this->reg.setreg_(this->reg.regkey_, (const char *)&stru_4290B5, (char *)this->bd.mine);
  this->reg.setreg_(this->reg.regkey_, (const char *)&stru_4290BA, (char *)this->bd.blck);
  this->reg.setreg_(this->reg.regkey_, (const char *)&stru_4290BF, (char *)this->bd.mask);
  this->saveboardcloud();
}


// 原始位置：window.cpp:260；地址：0x0040E534
// 调试记录声明：void loadallpaint()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::loadallpaint()
{

  while ( painttitleb > 0 )
  {
    if ( painttitleb == 2 )
    {
      painttitleb = 1;
      this->painttitle((int)painttitlec);
    }
    Sleep(1u);
  }
  painttitles = 0;
}


// 原始位置：window.cpp:274；地址：0x0040E58E
// 调试记录声明：void loadall()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::loadall()
{
  HWND__ *v1;

  painttitleb = 1;
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)loadallpaintstatic, this, 0, 0);
  if ( (unsigned __int8)IsWin() )
    this->loadsetting();
  this->painttitle(this->bd.st.lan.LAN_LOAD_STEAM);
  if ( (unsigned __int8)IsWin() )
    this->bd.st.loadsteam();
  this->painttitle(this->bd.st.lan.LAN_LOAD_AUDIO);
  if ( (unsigned __int8)IsWin() )
    this->bd.sd.initsound();
  this->painttitle(this->bd.st.lan.LAN_LOAD_BOARD);
  if ( (unsigned __int8)IsWin() )
  {
    this->bd.initbd(1, this->md);
    this->reg.getreg(this->reg.regkey, (const char *)&stru_4290C4, &this->boardb);
    this->bd.tutb = this->helpb;
    if ( this->boardb == 1 )
    {
      this->loadboard();
      this->boardb = 0;
      this->reg.setreg(this->reg.regkey, (const char *)&stru_4290C4, this->boardb);
    }
  }
  this->painttitle(this->bd.st.lan.LAN_LOAD_GRAPH);
  if ( (unsigned __int8)IsWin() )
    this->initbmp();
  this->painttitle(this->bd.st.lan.LAN_LOAD_WINDOW);
  if ( (unsigned __int8)IsWin() )
  {
    v1 = GetHwnd();
    SetWindowLongA(v1, -16, 281739264);
    this->sethelp(0);
  }
  painttitleb = 0;
}


// 原始位置：window.cpp:319；地址：0x0040E7CA
// 调试记录声明：void initmult()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::initmult()
{
  int v1;
  long double v2; // fst7
  int v3;
  int v4;
  long double v5; // fst7
  int v6;
  long double v7; // fst7
  long double v8; // fst7
  int v9;
  int v10;
  long double v11; // fst7
  long double v12; // fst7
  int v13;
  long double v14; // fst7
  int v15;
  int v16;
  long double v17; // fst7
  int v18;
  long double v19; // fst7
  int v20;
  int v21;
  long double v22; // fst7
  int v23;
  double v24;
  int v25;
  int v26;
  int v27;
  long double v28; // fst7
  int v29;
  int v30;
  long double v31; // fst7
  int v32;
  double v33;
  int v34;
  int v35;
  int v36;
  int v37;
  int v38;
  signed int v39;
  int v40;
  double v41;
  int v42;
  int v43;
  int v44;
  long double v45; // fst7
  int v46;
  int v47;
  long double v48; // fst7
  int v49;
  double v50;
  int v51;
  int v52;
  int v53;
  int v54;
  int v55;
  long double v56; // fst7
  signed int v57;
  double v58;
  signed int v59;
  signed int v60;
  signed int v61;
  double v62;
  signed int v63;
  signed int v64;
  signed int v65;
  signed int v66;

  if ( this->mult_ )
  {
    if ( this->mult_ == 1 )
    {
      v23 = this->wscr;
      v24 = (long double)(v23 - 2 * GetBorderWidth()) / (long double)this->w_;
      v25 = this->hscr;
      v26 = v25 - 2 * GetBorderHeight();
      if ( (long double)(v26 - GetBorderTitle()) / (long double)this->h_ <= v24 )
      {
        v29 = this->hscr;
        v30 = v29 - 2 * GetBorderHeight();
        v28 = (long double)(v30 - GetBorderTitle()) / (long double)this->h_;
      }
      else
      {
        v27 = this->wscr;
        v28 = (long double)(v27 - 2 * GetBorderWidth()) / (long double)this->w_;
      }
      if ( v28 >= 1.0 )
      {
        v32 = this->wscr;
        v33 = (long double)(v32 - 2 * GetBorderWidth()) / (long double)this->w_;
        v34 = this->hscr;
        v35 = v34 - 2 * GetBorderHeight();
        if ( (long double)(v35 - GetBorderTitle()) / (long double)this->h_ <= v33 )
        {
          v37 = this->hscr;
          v38 = v37 - 2 * GetBorderHeight();
          v31 = (long double)(v38 - GetBorderTitle()) / (long double)this->h_;
        }
        else
        {
          v36 = this->wscr;
          v31 = (long double)(v36 - 2 * GetBorderWidth()) / (long double)this->w_;
        }
      }
      else
      {
        v31 = 1.0;
      }
      this->mult = v31;
    }
    else
    {
      if ( this->mult_ > 7 )
      {
        v39 = 8;
      }
      else
      {
        v39 = this->mult_;
        if ( v39 < 2 )
          v39 = 2;
      }
      this->mult_ = v39;
      v40 = this->wscr;
      v41 = (long double)(v40 - 2 * GetBorderWidth()) / (long double)this->w_;
      v42 = this->hscr;
      v43 = v42 - 2 * GetBorderHeight();
      if ( (long double)(v43 - GetBorderTitle()) / (long double)this->h_ <= v41 )
      {
        v46 = this->hscr;
        v47 = v46 - 2 * GetBorderHeight();
        v45 = (long double)(v47 - GetBorderTitle()) / (long double)this->h_;
      }
      else
      {
        v44 = this->wscr;
        v45 = (long double)(v44 - 2 * GetBorderWidth()) / (long double)this->w_;
      }
      if ( v45 >= 1.0 )
      {
        v49 = this->wscr;
        v50 = (long double)(v49 - 2 * GetBorderWidth()) / (long double)this->w_;
        v51 = this->hscr;
        v52 = v51 - 2 * GetBorderHeight();
        if ( (long double)(v52 - GetBorderTitle()) / (long double)this->h_ <= v50 )
        {
          v54 = this->hscr;
          v55 = v54 - 2 * GetBorderHeight();
          v48 = (long double)(v55 - GetBorderTitle()) / (long double)this->h_;
        }
        else
        {
          v53 = this->wscr;
          v48 = (long double)(v53 - 2 * GetBorderWidth()) / (long double)this->w_;
        }
      }
      else
      {
        v48 = 1.0;
      }
      this->mult = v48;
      if ( (long double)this->mult_ / 2.0 <= this->mult )
        v56 = (long double)this->mult_ / 2.0;
      else
        v56 = this->mult;
      this->mult = v56;
    }
  }
  else
  {
    v1 = this->wscr;
    v2 = (long double)(v1 - 2 * GetBorderWidth());
    if ( (long double)(signed int)this->minw <= (long double)this->w_ )
      v57 = this->w_;
    else
      v57 = this->minw;
    v58 = v2 / (long double)v57;
    v3 = this->hscr;
    v4 = v3 - 2 * GetBorderHeight();
    v5 = (long double)(v4 - GetBorderTitle());
    if ( (long double)(signed int)this->minh <= (long double)this->h_ )
      v65 = this->h_;
    else
      v65 = this->minh;
    if ( v5 / (long double)v65 <= v58 )
    {
      v9 = this->hscr;
      v10 = v9 - 2 * GetBorderHeight();
      v11 = (long double)(v10 - GetBorderTitle());
      if ( (long double)(signed int)this->minh <= (long double)this->h_ )
        v60 = this->h_;
      else
        v60 = this->minh;
      v8 = v11 / (long double)v60;
    }
    else
    {
      v6 = this->wscr;
      v7 = (long double)(v6 - 2 * GetBorderWidth());
      if ( (long double)(signed int)this->minw <= (long double)this->w_ )
        v59 = this->w_;
      else
        v59 = this->minw;
      v8 = v7 / (long double)v59;
    }
    if ( v8 >= 1.0 )
    {
      v13 = this->wscr;
      v14 = (long double)(v13 - 2 * GetBorderWidth());
      if ( (long double)(signed int)this->minw <= (long double)this->w_ )
        v61 = this->w_;
      else
        v61 = this->minw;
      v62 = v14 / (long double)v61;
      v15 = this->hscr;
      v16 = v15 - 2 * GetBorderHeight();
      v17 = (long double)(v16 - GetBorderTitle());
      if ( (long double)(signed int)this->minh <= (long double)this->h_ )
        v66 = this->h_;
      else
        v66 = this->minh;
      if ( v17 / (long double)v66 <= v62 )
      {
        v20 = this->hscr;
        v21 = v20 - 2 * GetBorderHeight();
        v22 = (long double)(v21 - GetBorderTitle());
        if ( (long double)(signed int)this->minh <= (long double)this->h_ )
          v64 = this->h_;
        else
          v64 = this->minh;
        v12 = v22 / (long double)v64;
      }
      else
      {
        v18 = this->wscr;
        v19 = (long double)(v18 - 2 * GetBorderWidth());
        if ( (long double)(signed int)this->minw <= (long double)this->w_ )
          v63 = this->w_;
        else
          v63 = this->minw;
        v12 = v19 / (long double)v63;
      }
    }
    else
    {
      v12 = 1.0;
    }
    this->mult = v12;
    this->mult = (long double)(signed int)(this->mult + this->mult) / 2.0;
  }
  this->bd.w_ = this->w_;
  this->bd.h_ = this->h_;
  this->bd.mult = this->mult;
}


// 原始位置：window.cpp:341；地址：0x0040EFC4
// 调试记录声明：void loadicon()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::loadicon()
{
  HICON__ *v1;
  LPARAM v2;
  HWND__ *v3;
  LPARAM v4;
  HWND__ *v5;

  this->hicon_res = (HICON)LoadImageA(MainInstance, "MINESWEEPERRUSH_ICON", 1u, 0, 0, 0);
  this->hicon_file = (HICON)LoadImageA(0, "./data/MineSweeperRush.ico", 1u, 0, 0, 0x8050u);
  if ( this->hicon_res )
    v1 = this->hicon_res;
  else
    v1 = this->hicon_file;
  this->hicon = v1;
  v2 = (LPARAM)this->hicon;
  v3 = GetHwnd();
  SendMessageA(v3, 0x80u, 1u, v2);
  Delay(0xAu);
  v4 = (LPARAM)this->hicon;
  v5 = GetHwnd();
  SendMessageA(v5, 0x80u, 0, v4);
  Delay(0xAu);
}


// 原始位置：window.cpp:359；地址：0x0040F102
// 调试记录声明：void initwindow()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：LOGFONT lf。
void Window::initwindow()
{
  double v1;
  long double v2; // fst7
  double v3;
  double v4;
  double v5;
  long double v6; // fst7
  double v7;
  double v8;
  __int16 *v9;
  int v10;
  int v11;
  int v12;
  double v13;
  double v14;

  LOGFONT lf;

  this->initcolor();
  SystemParametersInfoA(0x30u, 0, &this->rect, 0);
  this->wscr = this->rect.right - this->rect.left;
  this->hscr = this->rect.bottom - this->rect.top;
  this->w_ = this->launchw;
  this->h_ = this->launchh;
  this->reg.getreg(this->reg.regkey, (const char *)&stru_42900A, &this->mult_);
  this->initmult();
  v13 = (long double)this->rect.left;
  v1 = (long double)this->wscr - (long double)this->w_ * this->mult;
  if ( (v1 - (long double)(2 * GetBorderWidth())) / 2.0 >= 0.0 )
  {
    v3 = (long double)this->wscr - (long double)this->w_ * this->mult;
    v2 = (v3 - (long double)(2 * GetBorderWidth())) / 2.0;
  }
  else
  {
    v2 = 0.0;
  }
  this->x_ = (signed int)(v2 + v13);
  v14 = (long double)this->rect.top;
  v4 = (long double)this->hscr - (long double)this->h_ * this->mult;
  v5 = v4 - (long double)(2 * GetBorderHeight());
  if ( (v5 - (long double)GetBorderTitle()) / 2.0 >= 0.0 )
  {
    v7 = (long double)this->hscr - (long double)this->h_ * this->mult;
    v8 = v7 - (long double)(2 * GetBorderHeight());
    v6 = (v8 - (long double)GetBorderTitle()) / 2.0;
  }
  else
  {
    v6 = 0.0;
  }
  this->y_ = (signed int)(v6 + v14);
  CreateWin(
    this->x_,
    this->y_,
    (signed __int64)((long double)this->w_ * this->mult),
    (signed __int64)((long double)this->h_ * this->mult),
    this->cbg,
    this->cbg,
    0x10C80000u,
    "MineSweeperRushClass");
  this->pwin = CreateBMP(this->w_, this->h_);
  this->pwint = CreateBMP(
                   (signed __int64)((long double)this->w_ * this->mult),
                   (signed __int64)((long double)this->h_ * this->mult),
                   this->transparent_);
  this->loadicon();
  v9 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_TITLE);
  SetTitleW(v9);
  SystemParametersInfoA(0x1Fu, 0x3Cu, &lf, 0);
  this->setfontname_(lf.lfFaceName);
  this->painttitle(-1);
  v10 = this->wscr;
  this->bd.maxbdw = (v10 - 2 * GetBorderWidth()) / 16 - 1;
  v11 = this->hscr - this->menuh - this->faceh;
  v12 = v11 - 2 * GetBorderHeight();
  this->bd.maxbdh = (v12 - GetBorderTitle()) / 16 - 1;
}


// 原始位置：window.cpp:384；地址：0x0040F5F8
// 调试记录声明：void releasewindow()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::releasewindow()
{

  this->savesetting();
  if ( this->cheatb != 1 && this->bd.relaxb != 1 && this->bd.sit > 0 && this->bd.sit <= 3 )
  {
    if ( !this->bd.tutb )
      this->bd.pauseb = 1;
    this->saveboard();
    this->boardb = 1;
    this->reg.setreg(this->reg.regkey, (const char *)&stru_4290C4, this->boardb);
  }
}


// 原始位置：window.cpp:399；地址：0x0040F6B2
// 调试记录声明：void initwindow(bool b)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：RECT rect。
void Window::initwindow(bool b)
{
  int v2;
  double v3;
  long double v4; // fst7
  double v5;
  double v6;
  double v7;
  long double v8; // fst7
  double v9;
  double v10;
  double v11;
  double v12;

  RECT rect;

  if ( (unsigned __int8)IsWin() )
  {
    v2 = this->helpi;
    if ( v2 == -1 )
    {
      this->w_ = this->aboutw;
      this->h_ = this->menuh + this->abouth;
    }
    else if ( v2 )
    {
      this->w_ = this->helpw;
      this->h_ = this->menuh + this->helph;
    }
    else
    {
      if ( b )
      {
        this->bd.mode = 0;
        this->bd.initbd();
      }
      this->w_ = this->iconw * this->bd.w;
      this->h_ = this->menuh + this->faceh + this->iconh * this->bd.h;
    }
    this->initmult();
    v11 = (long double)this->rect.left;
    v3 = (long double)this->wscr - (long double)this->w_ * this->mult;
    if ( (v3 - (long double)(2 * GetBorderWidth())) / 2.0 >= 0.0 )
    {
      v5 = (long double)this->wscr - (long double)this->w_ * this->mult;
      v4 = (v5 - (long double)(2 * GetBorderWidth())) / 2.0;
    }
    else
    {
      v4 = 0.0;
    }
    this->x_ = (signed int)(v4 + v11);
    v12 = (long double)this->rect.top;
    v6 = (long double)this->hscr - (long double)this->h_ * this->mult;
    v7 = v6 - (long double)(2 * GetBorderHeight());
    if ( (v7 - (long double)GetBorderTitle()) / 2.0 >= 0.0 )
    {
      v9 = (long double)this->hscr - (long double)this->h_ * this->mult;
      v10 = v9 - (long double)(2 * GetBorderHeight());
      v8 = (v10 - (long double)GetBorderTitle()) / 2.0;
    }
    else
    {
      v8 = 0.0;
    }
    this->y_ = (signed int)(v8 + v12);
    ReleaseBMP(this->pwin);
    ReleaseBMP(this->pwint);
    this->pwin = CreateBMP(this->w_, this->h_);
    this->pwint = CreateBMP(
                     (signed __int64)((long double)this->w_ * this->mult),
                     (signed __int64)((long double)this->h_ * this->mult),
                     this->transparent_);
    rect.left = 0;
    rect.top = 0;
    rect.right = 0;
    rect.bottom = 0;
    if ( EnumDisplayMonitors(0, 0, Monitorenumproc, (LPARAM)&rect) == 0 )
    {
      this->xscr = rect.left;
      this->yscr = rect.top;
      this->wscr = rect.right - rect.left;
      this->hscr = rect.bottom - rect.top;
    }
    SetSize(
      this->x_ + this->xscr,
      this->yscr + this->y_,
      (signed __int64)((long double)this->w_ * this->mult),
      (signed __int64)((long double)this->h_ * this->mult));
    this->paintevent(0);
    FreshWin();
  }
}


// 原始位置：window.cpp:444；地址：0x0040FB94
// 调试记录声明：void initcolor()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::initcolor()
{

  this->cfg = this->color[0];
  this->cbg = this->color[1];
  this->ctfg = this->color[2];
  this->ctbg = this->color[3];
  this->cred = this->color[4];
  this->cblue = this->color[5];
  this->cgreen = this->color[6];
  this->cline = this->color[7];
  this->cmine = this->color[8];
  this->bd.cred = this->cred;
  this->transparent_ = this->cbg;
}


// 原始位置：window.cpp:459；地址：0x0040FC66
// 调试记录声明：void initbmp()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：char pngPath[260]；long int i；long int i；long int i；long int k；long int i；long int k；long int k；long int i；long int i；long int i；long int k；long int i。
void Window::initbmp()
{
  unsigned int v1;

  char pngPath[260];
  int i_6;
  int k_2;
  int i_5;
  int i_4;
  int i_3;
  int k_1;
  int k_0;
  int i_2;
  int k;
  int i_1;
  int i_0;
  int i;

  if ( (unsigned __int8)IsWin() )
  {
    if ( this->isbmp == 1 )
    {
      ReleaseBMP(this->pbg_);
      ReleaseBMP(this->pmenu_);
      ReleaseBMP(this->pface_);
      ReleaseBMP(this->picon_);
      for ( k_0 = 0; k_0 <= 2; ++k_0 )
        ReleaseBMP(*((pbitmap *)&this->titlew + k_0 + 104));
      ReleaseBMP(this->pok_);
      ReleaseBMP(this->pcursor_);
      ReleaseBMP(this->pclick_);
      ReleaseBMP(this->parrow_);
    }
    else
    {
      for ( i = 0; i <= 1; ++i )
      {
        *((_DWORD *)&this->launchh + i + 40) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->titleh + i + 40) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->launchh + i + 44) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->titleh + i + 44) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->launchh + i + 48) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->titleh + i + 48) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->launchh + i + 52) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->titleh + i + 52) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->launchh + i + 56) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->titleh + i + 56) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->launchh + i + 60) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->launchh + i + 62) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->launchh + i + 64) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->launchh + i + 66) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->launchh + i + 68) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->launchh + i + 70) = CreateBMP(this->menuw, this->menuh);
        *((_DWORD *)&this->launchh + i + 72) = CreateBMP(this->menuw, this->menuh);
      }
      for ( i_0 = 0; i_0 <= 8; ++i_0 )
        *((_DWORD *)&this->launchw + i_0 + 76) = CreateBMP(this->facew, this->faceh);
      this->piconc = CreateBMP(this->iconw, this->iconh);
      this->piconf = CreateBMP(this->iconw, this->iconh);
      this->piconq = CreateBMP(this->iconw, this->iconh);
      this->piconm = CreateBMP(this->iconw, this->iconh);
      this->picone = CreateBMP(this->iconw, this->iconh);
      this->piconn = CreateBMP(this->iconw, this->iconh);
      for ( i_1 = 0; i_1 <= 10; ++i_1 )
        *((_DWORD *)&this->titlew + i_1 + 84) = CreateBMP(this->iconw, this->iconh);
      this->piconp = CreateBMP(this->iconw, this->iconh);
      this->picona = CreateBMP(this->iconw, this->iconh);
      this->piconu = CreateBMP(this->iconw, this->iconh);
      for ( k = 0; k <= 2; ++k )
      {
        for ( i_2 = 0; i_2 <= 9; ++i_2 )
          *((_DWORD *)&this->launchh + k + 3 * i_2 + 108) = CreateBMP(
                                                               *((_DWORD *)&this->titlew + k + 8),
                                                               *((_DWORD *)&this->launchh + k + 12));
        *((_DWORD *)&this->titleh + k + 136) = CreateBMP(
                                                  *((_DWORD *)&this->titlew + k + 8),
                                                  *((_DWORD *)&this->launchh + k + 12));
        *((_DWORD *)&this->titlew + k + 140) = CreateBMP(
                                                  *((_DWORD *)&this->titlew + k + 8),
                                                  *((_DWORD *)&this->launchh + k + 12));
      }
      this->pok = CreateBMP(this->okw, this->okh);
      this->pbtn = CreateBMP(this->btnw, this->btnh);
      this->pcursor = CreateBMP(this->cursorw, this->cursorh);
      this->pclickl = CreateBMP(this->clickw, this->clickh);
      this->pclickr = CreateBMP(this->clickw, this->clickh);
      this->pclickn = CreateBMP(this->clickw, this->clickh);
      this->pclicka = CreateBMP(this->clickw, this->clickh);
      this->parrowl = CreateBMP(this->arroww, this->arrowh);
      this->parrowr = CreateBMP(this->arroww, this->arrowh);
      this->parrowu = CreateBMP(this->arroww, this->arrowh);
      this->parrowd = CreateBMP(this->arroww, this->arrowh);
      this->parrowm = CreateBMP(this->arroww, this->arrowh);
      this->parrowp = CreateBMP(this->arroww, this->arrowh);
      this->isbmp = 1;
    }
    sprintf(pngPath, "./data/png/%ld/bg.png", this->colori);
    painttitles = (pbitmap)pngPath;
    this->pbg_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/menu.png", this->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    this->pmenu_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/face.png", this->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    this->pface_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/icon.png", this->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    this->picon_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/digt.png", this->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    this->pdigt_[0] = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/digt2.png", this->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    this->pdigt_[1] = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/digt_.png", this->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    this->pdigt_[2] = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/ok.png", this->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    this->pok_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/cursor.png", this->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    this->pcursor_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/click.png", this->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    this->pclick_ = LoadBMP(pngPath);
    sprintf(pngPath, "./data/png/%ld/arrow.png", this->colori);
    painttitles = (pbitmap)pngPath;
    painttitleb = 2;
    this->parrow_ = LoadBMP(pngPath);
    for ( k_1 = 0; k_1 <= 8; ++k_1 )
    {
      v1 = GetPixel(this->pbg_, 0, k_1);
      *((_DWORD *)&this->titleh + k_1 + 160) = v1;
    }
    this->initcolor();
    for ( i_3 = 0; i_3 <= 1; ++i_3 )
    {
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 40),
        i_3 * this->menuw,
        0,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->titleh + i_3 + 40),
        i_3 * this->menuw,
        this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 44),
        i_3 * this->menuw,
        2 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->titleh + i_3 + 44),
        i_3 * this->menuw,
        3 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 48),
        i_3 * this->menuw,
        4 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->titleh + i_3 + 48),
        i_3 * this->menuw,
        5 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 52),
        i_3 * this->menuw,
        6 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->titleh + i_3 + 52),
        i_3 * this->menuw,
        7 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 56),
        i_3 * this->menuw,
        8 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->titleh + i_3 + 56),
        i_3 * this->menuw,
        9 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 60),
        i_3 * this->menuw,
        10 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 62),
        i_3 * this->menuw,
        11 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 64),
        i_3 * this->menuw,
        12 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 66),
        i_3 * this->menuw,
        13 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 68),
        i_3 * this->menuw,
        14 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 70),
        i_3 * this->menuw,
        15 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
      DrawBMP(
        this->pmenu_,
        *((pbitmap *)&this->launchh + i_3 + 72),
        i_3 * this->menuw,
        16 * this->menuh,
        this->menuw,
        this->menuh,
        0,
        0,
        this->menuw,
        this->menuh);
    }
    for ( i_4 = 0; i_4 <= 8; ++i_4 )
      DrawBMP(
        this->pface_,
        *((pbitmap *)&this->launchw + i_4 + 76),
        0,
        i_4 * this->faceh,
        this->facew,
        this->faceh,
        0,
        0,
        this->facew,
        this->faceh);
    DrawBMP(this->picon_, this->piconc, 0, 0, this->iconw, this->iconh, 0, 0, this->iconw, this->iconh);
    DrawBMP(this->picon_, this->piconf, 0, this->iconh, this->iconw, this->iconh, 0, 0, this->iconw, this->iconh);
    DrawBMP(
      this->picon_,
      this->piconq,
      0,
      2 * this->iconh,
      this->iconw,
      this->iconh,
      0,
      0,
      this->iconw,
      this->iconh);
    DrawBMP(
      this->picon_,
      this->piconm,
      0,
      3 * this->iconh,
      this->iconw,
      this->iconh,
      0,
      0,
      this->iconw,
      this->iconh);
    DrawBMP(
      this->picon_,
      this->picone,
      0,
      4 * this->iconh,
      this->iconw,
      this->iconh,
      0,
      0,
      this->iconw,
      this->iconh);
    DrawBMP(
      this->picon_,
      this->piconn,
      0,
      5 * this->iconh,
      this->iconw,
      this->iconh,
      0,
      0,
      this->iconw,
      this->iconh);
    for ( i_5 = 0; i_5 <= 10; ++i_5 )
      DrawBMP(
        this->picon_,
        *((pbitmap *)&this->titlew + i_5 + 84),
        0,
        (16 - i_5) * this->iconh,
        this->iconw,
        this->iconh,
        0,
        0,
        this->iconw,
        this->iconh);
    DrawBMP(
      this->picon_,
      this->piconp,
      0,
      16 * this->iconh,
      this->iconw,
      this->iconh,
      0,
      0,
      this->iconw,
      this->iconh);
    DrawBMP(
      this->picon_,
      this->picona,
      0,
      17 * this->iconh,
      this->iconw,
      this->iconh,
      0,
      0,
      this->iconw,
      this->iconh);
    DrawBMP(
      this->picon_,
      this->piconu,
      0,
      18 * this->iconh,
      this->iconw,
      this->iconh,
      0,
      0,
      this->iconw,
      this->iconh);
    for ( k_2 = 0; k_2 <= 2; ++k_2 )
    {
      for ( i_6 = 0; i_6 <= 9; ++i_6 )
        DrawBMP(
          *((pbitmap *)&this->titlew + k_2 + 104),
          *((pbitmap *)&this->launchh + 3 * i_6 + k_2 + 108),
          0,
          (11 - i_6) * *((_DWORD *)&this->launchh + k_2 + 12),
          *((_DWORD *)&this->titlew + k_2 + 8),
          *((_DWORD *)&this->launchh + k_2 + 12),
          0,
          0,
          *((_DWORD *)&this->titlew + k_2 + 8),
          *((_DWORD *)&this->launchh + k_2 + 12));
      DrawBMP(
        *((pbitmap *)&this->titlew + k_2 + 104),
        *((pbitmap *)&this->titleh + k_2 + 136),
        0,
        0,
        *((_DWORD *)&this->titlew + k_2 + 8),
        *((_DWORD *)&this->launchh + k_2 + 12),
        0,
        0,
        *((_DWORD *)&this->titlew + k_2 + 8),
        *((_DWORD *)&this->launchh + k_2 + 12));
      DrawBMP(
        *((pbitmap *)&this->titlew + k_2 + 104),
        *((pbitmap *)&this->titlew + k_2 + 140),
        0,
        *((_DWORD *)&this->launchh + k_2 + 12),
        *((_DWORD *)&this->titlew + k_2 + 8),
        *((_DWORD *)&this->launchh + k_2 + 12),
        0,
        0,
        *((_DWORD *)&this->titlew + k_2 + 8),
        *((_DWORD *)&this->launchh + k_2 + 12));
    }
    DrawBMP(this->pok_, this->pok, 0, 0, this->okw, this->okh, 0, 0, this->okw, this->okh);
    DrawBMP(this->pok_, this->pbtn, this->okw, 0, this->btnw, this->btnh, 0, 0, this->btnw, this->btnh);
    DrawBMP(this->pcursor_, this->pcursor, 0, 0, this->cursorw, this->cursorh, 0, 0, this->cursorw, this->cursorh);
    DrawBMP(this->pclick_, this->pclickl, 0, 0, this->clickw, this->clickh, 0, 0, this->clickw, this->clickh);
    DrawBMP(
      this->pclick_,
      this->pclickr,
      0,
      this->clickh,
      this->clickw,
      this->clickh,
      0,
      0,
      this->clickw,
      this->clickh);
    DrawBMP(
      this->pclick_,
      this->pclickn,
      0,
      2 * this->clickh,
      this->clickw,
      this->clickh,
      0,
      0,
      this->clickw,
      this->clickh);
    DrawBMP(
      this->pclick_,
      this->pclicka,
      0,
      3 * this->clickh,
      this->clickw,
      this->clickh,
      0,
      0,
      this->clickw,
      this->clickh);
    DrawBMP(this->parrow_, this->parrowl, 0, 0, this->arroww, this->arrowh, 0, 0, this->arroww, this->arrowh);
    DrawBMP(
      this->parrow_,
      this->parrowr,
      0,
      this->arrowh,
      this->arroww,
      this->arrowh,
      0,
      0,
      this->arroww,
      this->arrowh);
    DrawBMP(
      this->parrow_,
      this->parrowu,
      0,
      2 * this->arrowh,
      this->arroww,
      this->arrowh,
      0,
      0,
      this->arroww,
      this->arrowh);
    DrawBMP(
      this->parrow_,
      this->parrowd,
      0,
      3 * this->arrowh,
      this->arroww,
      this->arrowh,
      0,
      0,
      this->arroww,
      this->arrowh);
    DrawBMP(
      this->parrow_,
      this->parrowm,
      0,
      4 * this->arrowh,
      this->arroww,
      this->arrowh,
      0,
      0,
      this->arroww,
      this->arrowh);
    DrawBMP(
      this->parrow_,
      this->parrowp,
      0,
      5 * this->arrowh,
      this->arroww,
      this->arrowh,
      0,
      0,
      this->arroww,
      this->arrowh);
  }
}


// 原始位置：window.cpp:652；地址：0x00412776
// 调试记录声明：void paintmenu()
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintmenu()
{

  DrawBMP(*((pbitmap *)&this->launchh + (this->helpi == -1) + 48), this->w_ - this->menuw, 0, this->menuw, this->menuh);
  DrawBMP(*((pbitmap *)&this->titleh + (this->helpi > 0) + 44), this->w_ - 2 * this->menuw, 0, this->menuw, this->menuh);
  DrawBMP(*((pbitmap *)&this->launchh + (this->helpi == -3) + 56), this->w_ - 3 * this->menuw, 0, this->menuw, this->menuh);
  DrawBMP(*((pbitmap *)&this->titleh + (this->helpi == -2) + 52), this->w_ - 4 * this->menuw, 0, this->menuw, this->menuh);
  DrawBMP(this->pface[6], this->w_ - 5 * this->menuw, 0, this->menuw, this->menuh);
  DrawBMP(*((pbitmap *)&this->launchh + (this->bd.mode == 1) + 40), 0, 0, this->menuw, this->menuh);
  DrawBMP(*((pbitmap *)&this->titleh + (this->bd.mode == 2) + 40), this->menuw, 0, this->menuw, this->menuh);
  DrawBMP(*((pbitmap *)&this->launchh + (this->bd.mode == 3) + 44), 2 * this->menuw, 0, this->menuw, this->menuh);
}


// 原始位置：window.cpp:664；地址：0x00412A48
// 调试记录声明：void paintface()
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
// 原始局部变量：long int face__[6]；long int facei。
void Window::paintface()
{
  int face__[6];
  int facei;

  face__[0] = 4;
  face__[1] = 4;
  face__[2] = 3;
  face__[3] = 1;
  face__[4] = 2;
  face__[5] = 0;
  facei = this->bd.sit;
  if ( facei == 1 && this->bd.checkr == 1 )
    ++facei;
  if ( this->bd.pauseb > 0 )
    facei = 5;
  DrawBMP(
    *((pbitmap *)&this->launchw + face__[facei] + 76),
    (this->w_ - this->facew) / 2,
    this->menuh,
    this->facew,
    this->faceh);
}


// 原始位置：window.cpp:682；地址：0x00412B1E
// 调试记录声明：void paintnumber(long int n, long int l, long int x, long int y, long int w, long int h, long int b)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
// 原始局部变量：long int digt[10]；long int dl；long int dlm；bool minb；long int di。
void Window::paintnumber(int n, int l, int x, int y, int w, int h, int b)
{
  int v8;
  int v9;

  int dl_0;
  int digt[10];
  bool minb;
  int di_0;
  int dlm;

  dl_0 = 0;
  minb = n < 0;
  if ( n < 0 )
    n = -n;
  do
  {
    digt[dl_0] = n % 10;
    n /= 10;
    ++dl_0;
  }
  while ( n );
  if ( minb )
  {
    v8 = dl_0 + 1;
    if ( dl_0 + 1 < l )
      v8 = l;
    dlm = v8;
  }
  else
  {
    if ( dl_0 <= l )
      v9 = l;
    else
      v9 = dl_0;
    dlm = v9;
  }
  for ( di_0 = 0; di_0 < dlm; ++di_0 )
  {
    if ( di_0 >= dl_0 )
    {
      if ( di_0 == dl_0 && minb )
        DrawBMP(*((pbitmap *)&this->titleh + b + 136), w * (dlm - di_0 - 1) + x, y, w, h);
      else
        DrawBMP(*((pbitmap *)&this->titlew + b + 140), w * (dlm - di_0 - 1) + x, y, w, h);
    }
    else
    {
      DrawBMP(*((pbitmap *)&this->launchh + b + 3 * digt[di_0] + 108), w * (dlm - di_0 - 1) + x, y, w, h);
    }
  }
}


// 原始位置：window.cpp:724；地址：0x00412CF2
// 调试记录声明：void paintnumber(long int n, long int l, long int x, long int y, long int b)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintnumber(int n, int l, int x, int y, int b)
{
  this->paintnumber(n, l, x, y, *((_DWORD *)&this->titlew + b + 8), *((_DWORD *)&this->launchh + b + 12), b);
}


// 原始位置：window.cpp:729；地址：0x00412D56
// 调试记录声明：void paintnumber(long int n, long int l, long int x, long int y)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintnumber(int n, int l, int x, int y)
{
  this->paintnumber(n, l, x, y, 0);
}


// 原始位置：window.cpp:734；地址：0x00412D94
// 调试记录声明：void paintlevel()
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
// 原始局部变量：long int score；long int score2。
void Window::paintlevel()
{

  signed int score2;
  int score;

  score = this->bd.line;
  if ( this->singleb )
    score = this->bd.line - this->bd.missline;
  if ( score > 9999 )
  {
    if ( score > 99999 )
      this->paintnumber(score, 6, 0, this->digth[0], 2 * this->singleb);
    else
      this->paintnumber(score, 5, 0, this->digth[0], 2 * this->singleb);
  }
  else
  {
    this->paintnumber(score, 4, 0, this->digth[0], 2 * this->singleb);
  }
  score2 = this->bd.level;
  if ( this->singleb )
    score2 = this->bd.solven;
  if ( score2 > 99 )
  {
    if ( score2 > 999 )
    {
      if ( score2 > 9999 )
        this->paintnumber(score2, 5, this->w_ - 5 * this->digtw[0], this->digth[0], 2 * this->singleb);
      else
        this->paintnumber(score2, 4, this->w_ - 4 * this->digtw[0], this->digth[0], 2 * this->singleb);
    }
    else
    {
      this->paintnumber(score2, 3, -3 * this->digtw[0] + this->w_, this->digth[0], 2 * this->singleb);
    }
  }
  else
  {
    this->paintnumber(score2, 2, this->w_ - 2 * this->digtw[0], this->digth[0], 2 * this->singleb);
  }
}


// 原始位置：window.cpp:776；地址：0x00413050
// 调试记录声明：void paintblock(Block &b, long int i, long int j, long int x, long int y, long int w, long int h)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintblock(Block *const b, int i, int j, int x, int y, int w, int h)
{

  if ( b->mask[i][j] )
  {
    if ( b->maski > i && b->maskj - 1 <= j )
      DrawBMP(this->picone, x, y, w, h);
  }
  else if ( b->pauseb <= 0 )
  {
    if ( b->blck[i][j] )
    {
      if ( b->mine[i][j] )
        DrawBMP(this->piconm, x, y, w, h);
      else
        DrawBMP(*((pbitmap *)&this->titlew + b->numb[i][j] + 84), x, y, w, h);
    }
    else if ( b->flag[i][j] )
    {
      DrawBMP(this->piconf, x, y, w, h);
    }
    else if ( b->qstn[i][j] )
    {
      DrawBMP(this->piconq, x, y, w, h);
    }
    else if ( b->sit != 4 && (b->sit || this->bd.mode) || !b->mine[i][j] || this->helpi )
    {
      DrawBMP(this->piconc, x, y, w, h);
    }
    else
    {
      DrawBMP(this->piconn, x, y, w, h);
    }
  }
  else if ( b->blck[i][j] )
  {
    DrawBMP(this->piconp, x, y, w, h);
    Bar(x, y, w - 1, h - 1, this->cbg);
  }
  else
  {
    DrawBMP(this->picone, x, y, w, h);
  }
  if ( this->cheatb )
  {
    if ( this->bd.leftrule[i][j] && this->bd.blck[i][j] != 1 && this->bd.mask[i][j] != 1 )
      Bar(x, y, this->iconw - 1, this->iconh - 1, this->cblue, this->transparent);
    if ( this->bd.rightrule[i][j]
      && this->bd.blck[i][j] != 1
      && this->bd.qstn[i][j] != 1
      && this->bd.flag[i][j] != 1
      && this->bd.mask[i][j] != 1 )
    {
      Bar(x, y, this->iconw - 1, this->iconh - 1, this->cred, this->transparent);
    }
  }
}


// 原始位置：window.cpp:837；地址：0x00413534
// 调试记录声明：void paintboard(Block &b, long int x, long int y)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
// 原始局部变量：long int i；long int j。
void Window::paintboard(Block *const b, int x, int y)
{

  int j;
  int i;

  for ( i = 0; b->w > i; ++i )
  {
    for ( j = 0; b->h > j; ++j )
      this->paintblock(b, i, j, x + i * this->iconw, this->menuh + j * this->iconh + y, this->iconw, this->iconh);
  }
}


// 原始位置：window.cpp:848；地址：0x004135E8
// 调试记录声明：void paintboard(Block &b, long int x, long int y, long int cx, long int cy)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintboard(Block *const b, int x, int y, int cx_0, int cy)
{

  this->paintboard(b, x, y);
  DrawBMP(
    this->pcursor,
    x + cx_0 * this->iconw + this->iconw / 2,
    y + this->menuh + cy * this->iconh + this->iconh / 2,
    this->cursorw,
    this->cursorh,
    0xC0C0C0u);
}


// 原始位置：window.cpp:855；地址：0x004136B0
// 调试记录声明：void paintboard()
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintboard()
{

  this->paintboard(&this->bd.0, 0, this->faceh);
  if ( this->bd.mx >= 0 && this->bd.my >= 0 )
  {
    if ( this->barb )
      Bar(
        this->bd.mx * this->iconw,
        this->faceh + this->menuh + this->iconh * this->bd.my,
        this->iconw - 1,
        this->iconh - 1,
        this->ctfg,
        this->transparent);
  }
}


// 原始位置：window.cpp:865；地址：0x0041379C
// 调试记录声明：void paintline(pbitmap p, long int n, long int x, long int y)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
// 原始局部变量：long int k。
void Window::paintline(pbitmap p, int n, int x, int y)
{

  int k;

  for ( k = 0; k < n; ++k )
    DrawBMP(p, k * this->iconw + x, y, this->iconw, this->iconh);
}


// 原始位置：window.cpp:874；地址：0x00413806
// 调试记录声明：void paintline(pbitmap pa, pbitmap pb, long int a, long int b, long int x, long int y)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintline(pbitmap pa, pbitmap pb, int a, int b, int x, int y)
{

  this->paintline(pa, a, x, y);
  this->paintline(pb, b, a * this->iconw + x, y);
}


// 原始位置：window.cpp:880；地址：0x00413874
// 调试记录声明：void paintline(pbitmap pa, pbitmap pb, pbitmap pc, long int a, long int b, long int c, long int x, long int y)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintline(pbitmap pa, pbitmap pb, pbitmap pc, int a, int b, int c, int x, int y)
{

  this->paintline(pa, pb, a, b, x, y);
  this->paintline(pc, c, this->iconw * (a + b) + x, y);
}


// 原始位置：window.cpp:886；地址：0x004138F4
// 调试记录声明：void paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, long int a, long int b, long int c, long int d, long int x, long int y)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, int a, int b, int c, int d, int x, int y)
{

  this->paintline(pa, pb, pc, a, b, c, x, y);
  this->paintline(pd, d, this->iconw * (b + a + c) + x, y);
}


// 原始位置：window.cpp:892；地址：0x00413988
// 调试记录声明：void paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, pbitmap pe, long int a, long int b, long int c, long int d, long int e, long int x, long int y)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, pbitmap pe, int a, int b, int c, int d, int e, int x, int y)
{

  this->paintline(pa, pb, pc, pd, a, b, c, d, x, y);
  this->paintline(pe, e, this->iconw * (c + b + a + d) + x, y);
}


// 原始位置：window.cpp:898；地址：0x00413A2E
// 调试记录声明：void painthelp()
// 功能说明：绘制帮助界面文本和示例；文本常量保留在代码中。
// 原始局部变量：pbitmap pcheat__[2]；pbitmap prelax__[2]；char rankStr[260]；pbitmap pmenu__[3]；const char *usernamec；short int usernames[260]；LeaderboardEntry_t leads；pbitmap pface__[3]；long int scr__[3]；long int n__[3]；long int k_[5]；long int leadid；long int rank_；long int k；uint32_t buffer；uint16_t utf16[2]；long int posc；long int lenc；long int poss；long int lens；long int k；long int score；long int k；pbitmap psetting__[10]；long int settinglan[10]；long int settingj[10]；long int settingb[10][3]；pbitmap psettingicon[2]；long int settinglanj[10][3]；long int helpw__；double helph__；long int k；long int j；pbitmap pmenu__[17]；const char *keys[17]；const char *cheatn[9]；const char *cheats[9]；long int cheatc[9]；long int helpw__；double helph__；long int k；long int k；long int k；long int k；long int j；long int i；long int j_；long int i；long int j；pbitmap picon__[3][3][5]；long int k__[3][3]；long int k；long int k；long int j；long int i；long int j_；long int i；long int j；pbitmap picon__[3][4][5]；long int k__[3][3]；long int k；long int k；long int iconwl；long int iconwm；long int iconwr；long int iconwn；long int iconh1；long int iconh2；long int iconh3；long int k；long int iconwl；long int iconwm；long int iconwr；long int iconwn；long int iconh1；long int iconh2；long int iconh3；long int iconh4；long int k；long int k；long int i；long int j；long int j；long int j；long int i。
void Window::painthelp()
{
  unsigned int v1;
  unsigned int v2;
  unsigned int v3;
  int v4;
  __int16 *v5;
  unsigned int v6;
  int v7;
  unsigned int v8;
  unsigned int v9;
  int v10;
  __int16 *v11;
  unsigned int v12;
  int v13;
  unsigned int v14;
  unsigned int v15;
  int v16;
  __int16 *v17;
  unsigned int v18;
  int v19;
  unsigned int v20;
  unsigned int v21;
  int v22;
  __int16 *v23;
  unsigned int v24;
  int v25;
  unsigned int v26;
  unsigned int v27;
  int v28;
  __int16 *v29;
  unsigned int v30;
  unsigned int v31;
  unsigned int v32;
  int v33;
  __int16 *v34;
  int v35;
  int v36;
  int *v37;
  bool v38;
  ISteamFriends *v39;
  int v40;
  unsigned int v41;
  unsigned int v42;
  int v43;
  unsigned int v44;
  int v45;
  int v46;
  unsigned int v47;
  int v48;
  unsigned int v49;
  int v50;
  unsigned int v51;
  bitmap *v52;
  unsigned int v53;
  int v54;
  unsigned int v55;
  int v56;
  int v57;
  int v58;
  __int16 *v59;
  unsigned int v60;
  unsigned int v61;
  unsigned int v62;
  int v63;
  __int16 *v64;
  unsigned int v65;
  unsigned int v66;
  int v67;
  int v68;
  int v69;
  int v70;
  __int16 *v71;
  unsigned int v72;
  unsigned int v73;
  int v74;
  signed int v75;
  __int16 *v76;
  unsigned int v77;
  unsigned int v78;
  int v79;
  int v80;
  int v81;
  int v82;
  __int16 *v83;
  unsigned int v84;
  unsigned int v85;
  unsigned int v86;
  int v87;
  __int16 *v88;
  unsigned int v89;
  int v90;
  int v91;
  int v92;
  int v93;
  int v94;
  __int16 *v95;
  unsigned int v96;
  unsigned int v97;
  int v98;
  int v99;
  int v100;
  int v101;
  __int16 *v102;
  unsigned int v103;
  unsigned int v104;
  int v105;
  int v106;
  unsigned int v107;
  unsigned int v108;
  unsigned int v109;
  int v110;
  int v111;
  unsigned int v112;
  unsigned int v113;
  unsigned int v114;
  unsigned int v115;
  int v116;
  __int16 *v117;
  signed int v118;
  unsigned int v119;
  int v120;
  int v121;
  int v122;
  int v123;
  int v124;
  __int16 *v125;
  unsigned int v126;
  unsigned int v127;
  unsigned int v128;
  int v129;
  __int16 *v130;
  unsigned int v131;
  int v132;
  int v133;
  int v134;
  int v135;
  int v136;
  __int16 *v137;
  unsigned int v138;
  int v139;
  int v140;
  unsigned int v141;
  int v142;
  __int16 *v143;
  unsigned int v144;
  unsigned int v145;
  unsigned int v146;
  int v147;
  __int16 *v148;
  unsigned int v149;
  int v150;
  int v151;
  unsigned int v152;
  int v153;
  __int16 *v154;
  unsigned int v155;
  int v156;
  int v157;
  unsigned int v158;
  int v159;
  __int16 *v160;
  unsigned int v161;
  int v162;
  int v163;
  unsigned int v164;
  int v165;
  __int16 *v166;
  unsigned int v167;
  unsigned int v168;
  unsigned int v169;
  int v170;
  __int16 *v171;
  unsigned int v172;
  int v173;
  int v174;
  unsigned int v175;
  int v176;
  __int16 *v177;
  unsigned int v178;
  int v179;
  int v180;
  unsigned int v181;
  int v182;
  __int16 *v183;
  unsigned int v184;
  int v185;
  int v186;
  unsigned int v187;
  int v188;
  __int16 *v189;
  unsigned int v190;
  int v191;
  int v192;
  unsigned int v193;
  int v194;
  __int16 *v195;
  unsigned int v196;
  unsigned int v197;
  unsigned int v198;
  int v199;
  __int16 *v200;
  signed int v201;
  signed int v202;
  unsigned int v203;
  int v204;
  unsigned int v205;
  int v206;
  int v207;
  int v208;
  __int16 *v209;
  unsigned int v210;
  int v211;
  unsigned int v212;
  int v213;
  int v214;
  int v215;
  __int16 *v216;
  unsigned int v217;
  int v218;
  unsigned int v219;
  int v220;
  int v221;
  int v222;
  __int16 *v223;
  int v224;
  unsigned int v225;
  unsigned int v226;
  int v227;
  bitmap *v228;
  unsigned int v229;
  int v230;
  unsigned int v231;
  unsigned int v232;
  int v233;
  int v234;
  __int16 *v235;
  int v236;
  unsigned int v237;
  unsigned int v238;
  int v239;
  bitmap *v240;
  unsigned int v241;
  int v242;
  unsigned int v243;
  unsigned int v244;
  int v245;
  int v246;
  __int16 *v247;
  int v248;
  unsigned int v249;
  unsigned int v250;
  unsigned int v251;
  bitmap *v252;
  int v253;
  unsigned int v254;
  unsigned int v255;
  unsigned int v256;
  bitmap *v257;
  int v258;
  unsigned int v259;
  unsigned int v260;
  unsigned int v261;
  bitmap *v262;
  unsigned int v263;
  int v264;
  unsigned int v265;
  unsigned int v266;
  int v267;
  int v268;
  __int16 *v269;
  int w;
  int y;
  int yd;

  const char *cheatn[9];
  int v275;
  const char *cheats[9];
  int v277;
  int cheatc[9];
  int v279;
  int k__[3][3];
  pbitmap v281;
  pbitmap v282;
  pbitmap v283;
  int v284;
  int v285;
  pbitmap v286;
  pbitmap v287;
  pbitmap v288;
  BOOL v289;
  BOOL v290;
  BOOL v291;
  BOOL v292;
  BOOL v293;
  BOOL v294;
  BOOL v295;
  BOOL v296;
  BOOL v297;
  BOOL v298;
  pbitmap picon__[3][3][5];
  pbitmap v300;
  pbitmap v301;
  pbitmap v302;
  pbitmap v303;
  pbitmap v304;
  pbitmap v305;
  pbitmap v306;
  pbitmap v307;
  pbitmap v308;
  pbitmap v309;
  int j_0;
  pbitmap psettingicon[2];
  int k_1;
  uint16_t utf16[2];
  uint32_t buffer;
  int k_[5];
  int n__[3];
  int scr__[3];
  pbitmap pface__[3];
  pbitmap pmenu__[3];
  pbitmap prelax__[2];
  pbitmap pcheat__[2];
  int iconh4;
  int iconh3_0;
  int iconh2_0;
  int iconh1_0;
  int iconwn_0;
  int iconwr_0;
  int iconwm_0;
  int iconwl_0;
  int iconh3;
  int iconh2;
  int iconh1;
  int iconwn;
  int iconwr;
  int iconwm;
  int iconwl;
  int j_;
  double helph___0;
  int helpw___0;
  double helph__;
  int helpw__;
  int lens;
  int lenc;
  const char *usernamec;
  int i_4;
  int j_6;
  int j_5;
  int j_4;
  int i_3;
  int k_13;
  int k_12;
  int k_11;
  int k_10;
  int k_9;
  int j_3;
  int i_2;
  int j__0;
  int i_1;
  int j_2;
  int k_8;
  int k_7;
  int j_1;
  int i_0;
  int i;
  int k_6;
  int k_5;
  int k_4;
  int k_3;
  int j;
  int k_2;
  int score;
  int k_0;
  int poss;
  int posc;
  int k;
  int rank_;
  int leadid;

  switch ( this->helpi )
  {
    case (int)0xFFFFFFFD:
      goto LABEL_42;
    case (int)0xFFFFFFFE:
      this->setfontheight_(this->faceh);
      v30 = this->cbg;
      v31 = this->ctfg;
      v32 = this->faceh;
      v33 = this->helpw;
      v34 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP + 9);
      this->drawtextxy_(this->pwint, v34, 0, 0, v33, v32, v31, v30);
      this->setfontheight_(this->fontfh);
      if ( this->bd.st.steamb )
      {
        this->setfontheight_(this->fontsh - 1);
        pmenu__[0] = this->pmenu1[0];
        pmenu__[1] = this->pmenu2[0];
        pmenu__[2] = this->pmenu3[0];
        LeaderboardEntry_t::LeaderboardEntry_t((LeaderboardEntry_t *const )cheatc);
        for ( leadid = 0; leadid <= 2; ++leadid )
        {
          DrawBMP(
            pmenu__[leadid],
            (2 * leadid + 1) * this->helpw / 6 + this->facew / -2,
            this->menuh,
            this->facew,
            this->faceh,
            this->cfg);
          for ( rank_ = 0; (*this->bd.st.leadsn)[0][rank_ + 20 * (leadid + 3 * this->lead_5)].m_nScore > 9997; ++rank_ )
            ;
          for ( k = 0; k <= 19; ++k )
          {
            if ( k > 9 )
            {
              v35 = (int)(*this->bd.st.leadsn)[15];
              v36 = 32 * (k - 10 + 20 * (leadid + 3 * this->lead_5));
            }
            else
            {
              v35 = (int)this->bd.st.leadsn;
              v36 = 32 * (rank_ + k + 20 * (leadid + 3 * this->lead_5));
            }
            v37 = (int *)(v35 + v36);
            cheatc[0] = *v37;
            cheatc[1] = v37[1];
            cheatc[2] = v37[2];
            cheatc[3] = v37[3];
            cheatc[4] = v37[4];
            cheatc[5] = v37[5];
            cheatc[6] = v37[6];
            cheatc[7] = v37[7];
            v38 = (*this->bd.st.leadsn)[3 * this->lead_5 + 30][20 * leadid].m_nGlobalRank == cheatc[2]
               && (signed int)((const CSteamID *const )cheatc)->GetEAccountType() > 0;
            if ( v38 )
              this->setfontweight_(0x2BCu);
            if ( (signed int)((const CSteamID *const )cheatc)->GetEAccountType() > 0 )
            {
              v39 = SteamFriends();
              usernamec = (const char *)(*(int (__stdcall **)(int, int))(*(_DWORD *)v39 + 28))(cheatc[0], cheatc[1]);
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
              this->drawtextxy_(this->pwint, (const char *)k__, leadid * this->helpw / 3, this->faceh + k * this->fontsh + this->menuh + 1, this->ctfg, this->cbg);
              v40 = this->cbg;
              v41 = this->ctfg;
              v42 = this->fontsh;
              v43 = this->helpw / 3;
              v44 = v43
                  - this->getstringwidth_("00000")
                  - 4 * (this->digtw[1] * this->fontsh / this->digth[1]);
              v45 = this->faceh + k * this->fontsh + this->menuh + 1;
              v46 = leadid * this->helpw / 3;
              v47 = this->getstringwidth_("00000");
              this->drawtextxy_(this->pwint, (const __int16 *)&picon__[0][0][2], v46 + v47, v45, v44, v42, v41, v40, 0);
              this->paintnumber(cheatc[3], 4, (leadid + 1) * this->helpw / 3 - 4 * (this->digtw[1] * this->fontsh / this->digth[1]), this->faceh + k * this->fontsh + this->menuh, this->digtw[1] * this->fontsh / this->digth[1], this->fontsh, 1);
            }
            this->setfontweight_(0);
          }
        }
        this->setfontheight_(this->fonth);
        pface__[0] = this->pface[1];
        pface__[1] = this->pface[3];
        pface__[2] = this->piconf;
        scr__[0] = this->bd.st.scrfour;
        scr__[1] = this->bd.st.scrdead;
        scr__[2] = this->bd.st.scrtotal;
        n__[0] = 0;
        n__[1] = 0;
        n__[2] = 1;
        for ( k_0 = 0; k_0 <= 2; ++k_0 )
        {
          score = *((_DWORD *)&this->menuw + scr__[k_0] + 384);
          if ( this->singleb )
          {
            if ( !k_0 )
              score = this->bd.tetrisi;
            if ( k_0 == 1 )
              score = this->bd.missi;
          }
          DrawBMP(
            pface__[k_0],
            (2 * k_0 + 1) * this->helpw / 6 - 2 * this->digtw[0] - this->facew - this->digtw[0] * n__[k_0],
            this->menuh + (this->helph + 20 * this->fontsh - this->okh_) / 2 + 1,
            this->facew,
            this->faceh,
            this->cfg);
          this->paintnumber(score, n__[k_0] + 4 + (*((_DWORD *)&this->menuw + scr__[k_0] + 384) > 9999) * (k_0 <= 1), (2 * k_0 + 1) * this->helpw / 6 - 2 * this->digtw[0] + this->facew - this->digtw[0] * n__[k_0], this->menuh + (this->helph + 20 * this->fontsh - this->okh_) / 2 + 1, 2 * this->singleb * (k_0 <= 1));
        }
        Line(this->helpw / 3, this->menuh, 0, this->helph - this->okh_, this->cline);
        Line(2 * (this->helpw / 3), this->menuh, 0, this->helph - this->okh_, this->cline);
        Line(0, this->menuh, this->helpw, 0, this->cline);
        Line(0, this->menuh + this->faceh, this->helpw, 0, this->cline);
        Line(0, this->menuh + this->faceh + 10 * this->fontsh, this->helpw, 0, this->cline);
        Line(0, this->menuh + this->faceh + 20 * this->fontsh, this->helpw, 0, this->cline);
        k_[0] = 3;
        k_[1] = 0;
        k_[2] = 5;
        k_[3] = 4;
        k_[4] = 6;
        for ( k_1 = 0; k_1 <= 4; ++k_1 )
        {
          v48 = this->faceh;
          v49 = this->facew;
          v50 = (this->okh_ + this->okh) / -2 + this->helph + this->menuh;
          v51 = this->facew * k_1
              + ((this->helpw + this->okw) / 2 + this->helpw) / 2
              + ((signed int)(((unsigned int)(-5 * this->facew) >> 31) - 5 * this->facew) >> 1);
          v52 = GetWin();
          DrawBMP(*((pbitmap *)&this->launchh + (this->lead_5 == k_1) + 2 * k_[k_1] + 60), v52, v51, v50, v49, v48);
        }
        this->setfontheight_(this->faceh);
        v53 = this->cbg;
        v54 = this->ctfg;
        v55 = this->faceh;
        v56 = this->helpw + (this->helpw + this->okw) / -2;
        v57 = this->menuh + this->helph + (this->okh_ + this->okh) / -2 + this->faceh;
        v58 = (this->helpw + this->okw) / 2;
        v59 = this->bd.st.lan.getlan(this->lead_5 + this->bd.st.lan.LAN_MODE);
        this->drawtextxy_(this->pwint, v59, v58, v57, v56, v55, v54, v53);
        this->setfontheight_(this->fonth);
      }
      else
      {
LABEL_42:
        this->setfontheight_(this->faceh);
        v60 = this->cbg;
        v61 = this->ctfg;
        v62 = this->faceh;
        v63 = this->helpw;
        v64 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP + 8);
        this->drawtextxy_(this->pwint, v64, 0, 0, v63, v62, v61, v60);
        this->setfontheight_(this->fonth);
        memset(cheatn, 0, 0x28u);
        cheatn[0] = *((const char **)&this->titleh + this->bd.sd.soundb + 48);
        cheatn[1] = *((const char **)&this->launchh + this->bd.sd.musicb + 52);
        cheatn[2] = *((const char **)&this->launchh + 2 * (this->md + 30));
        cheatn[4] = (const char *)this->pface[8];
        cheatn[5] = (const char *)this->pface[7];
        cheatn[7] = (const char *)this->picon[0];
        cheatn[8] = (const char *)this->picon[0];
        v275 = *((_DWORD *)&this->titleh + this->singleb + 56);
        cheats[0] = (const char *)10;
        cheats[1] = (const char *)11;
        cheats[2] = (const char *)12;
        cheats[3] = 0;
        cheats[4] = (const char *)17;
        cheats[5] = (const char *)14;
        cheats[6] = 0;
        cheats[7] = (const char *)18;
        cheats[8] = (const char *)19;
        v277 = 13;
        cheatc[0] = 2;
        cheatc[1] = 2;
        cheatc[2] = 2;
        cheatc[3] = 2;
        cheatc[4] = 3;
        cheatc[5] = 3;
        cheatc[6] = 3;
        cheatc[7] = 2;
        cheatc[8] = 2;
        v279 = 2;
        memset(k__, 0, 0x78u);
        k__[0][0] = this->bd.sd.soundb;
        k__[0][1] = !this->bd.sd.soundb;
        k__[1][0] = this->bd.sd.musicb;
        k__[1][1] = !this->bd.sd.musicb;
        k__[2][0] = this->md == 0;
        k__[2][1] = this->md == 1;
        v281 = (pbitmap)(this->md == 2);
        v282 = (pbitmap)(this->md == 3);
        v284 = this->mult_ == 0;
        v285 = this->mult_ == 1;
        v286 = (pbitmap)(this->mult_ > 1);
        v287 = (pbitmap)(this->colori == 0);
        v288 = (pbitmap)(this->colori == 1);
        v289 = this->colori == 2;
        v290 = this->colori == 3;
        v291 = this->colori == 4;
        v292 = this->colori == 5;
        v293 = this->bd.delayb == 1;
        v294 = this->bd.delayb == 0;
        v295 = this->barb;
        v296 = !this->barb;
        v297 = !this->singleb;
        v298 = this->singleb;
        psettingicon[0] = this->piconc;
        psettingicon[1] = this->piconf;
        qmemcpy(picon__, &unk_427220, 0x78u);
        helpw__ = this->iconw;
        helph__ = (long double)(this->helph - this->okh_ - 2 * this->iconh - this->faceh) / 9.0;
        for ( k_2 = 0; k_2 <= 9; ++k_2 )
        {
          if ( cheatn[k_2] )
            DrawBMP(
              (pbitmap)cheatn[k_2],
              helpw__,
              (signed __int64)((long double)k_2 * helph__
                             + (long double)(signed int)this->menuh
                             + (long double)(signed int)this->iconh),
              this->facew,
              this->faceh,
              this->cfg);
          if ( k_2 != 3 && k_2 != 6 )
          {
            v65 = this->cbg;
            v66 = this->ctfg;
            v67 = this->faceh;
            v68 = this->helpw / 4 - this->facew - 2 * this->iconw;
            v69 = (signed int)((long double)k_2 * helph__
                             + (long double)(signed int)this->menuh
                             + (long double)(signed int)this->iconh);
            v70 = helpw__ + this->facew + this->iconw;
            v71 = this->bd.st.lan.getlan((int)&cheats[k_2][this->bd.st.lan.LAN_HELP]);
            this->drawtextxy_(this->pwint, v71, v70, v69, v68, v67, v66, v65, 0);
          }
          for ( j = 0; cheatc[k_2] > j; ++j )
          {
            DrawBMP(
              psettingicon[k__[0][j + 3 * k_2]],
              this->helpw / 4 * (j + 1),
              (signed __int64)((long double)k_2 * helph__
                             + (long double)(signed int)this->menuh
                             + (long double)(signed int)this->iconh),
              this->facew,
              this->faceh,
              this->cfg);
            if ( k_2 != 4 || j != 2 )
            {
              v77 = this->cbg;
              v78 = this->ctfg;
              v79 = this->faceh;
              v80 = this->helpw / 4 - this->facew - 2 * this->iconw;
              v81 = (signed int)((long double)k_2 * helph__
                               + (long double)(signed int)this->menuh
                               + (long double)(signed int)this->iconh);
              v82 = this->facew + (j + 1) * (this->helpw / 4) + this->iconw;
              v83 = this->bd.st.lan.getlan((int)picon__[0][0][3 * k_2 + j] + this->bd.st.lan.LAN_SET);
              this->drawtextxy_(this->pwint, v83, v82, v81, v80, v79, v78, v77, 0);
            }
            else
            {
              DrawBMP(
                this->parrowm,
                3 * (this->helpw / 4) + this->facew,
                (signed __int64)((long double)k_2 * helph__
                               + (long double)(signed int)this->menuh
                               + (long double)(signed int)this->iconh),
                this->facew,
                this->faceh,
                this->cfg);
              DrawBMP(
                this->parrowp,
                (j + 1) * (this->helpw / 4) + 2 * this->facew,
                (signed __int64)((long double)k_2 * helph__
                               + (long double)(signed int)this->menuh
                               + (long double)(signed int)this->iconh),
                this->facew,
                this->faceh,
                this->cfg);
              v72 = this->cbg;
              v73 = this->ctfg;
              y = this->faceh;
              w = this->helpw / 4 - this->facew - 2 * this->iconw;
              yd = (signed int)((long double)k_2 * helph__
                              + (long double)(signed int)this->menuh
                              + (long double)(signed int)this->iconh);
              v74 = (j + 1) * (this->helpw / 4) + 3 * this->facew + this->iconw;
              v75 = this->mult_;
              if ( v75 < 2 )
                v75 = 2;
              v76 = this->bd.st.lan.getlan((int)picon__[0][0][3 * k_2 + j] + this->bd.st.lan.LAN_SET + v75 - 2);
              this->drawtextxy_(this->pwint, v76, v74, yd, w, y, v73, v72, 0);
            }
          }
        }
        if ( this->bd.delayb == 1 )
          Line(
            helpw__,
            (signed int)(helph__ * 7.0
                       + (long double)(signed int)this->menuh
                       + (long double)(signed int)this->iconh
                       + (long double)(this->faceh / 2)),
            this->facew,
            0,
            this->cred);
        if ( this->barb )
          Bar(
            helpw__,
            (signed int)(helph__ * 8.0 + (long double)(signed int)this->menuh + (long double)(signed int)this->iconh),
            this->facew - 1,
            this->faceh - 1,
            this->ctfg,
            this->transparent);
      }
      break;
    case (int)0xFFFFFFFF:
      this->setfontheight_(this->faceh);
      v1 = this->cbg;
      v2 = this->ctfg;
      v3 = this->faceh;
      v4 = this->aboutw;
      v5 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP + 7);
      this->drawtextxy_(this->pwint, v5, 0, 0, v4, v3, v2, v1);
      this->setfontheight_(this->fontfh);
      pcheat__[0] = this->piconn;
      pcheat__[1] = this->piconm;
      prelax__[0] = this->pface[5];
      prelax__[1] = this->picone;
      DrawBMP(
        pcheat__[(unsigned __int8)this->cheatb],
        (this->aboutw - this->fontfh) / 2 + this->fontfh / -2,
        (this->fontth - this->fontfh) / 2 + this->menuh,
        this->fontfh,
        this->fontfh,
        this->cbg);
      DrawBMP(
        prelax__[(unsigned __int8)this->bd.relaxb],
        (this->aboutw - this->fontfh) / 2 + this->fontfh / 2,
        (this->fontth - this->fontfh) / 2 + this->menuh,
        this->fontfh,
        this->fontfh,
        this->cbg);
      this->setfontheight_(this->fonth);
      v6 = this->cbg;
      v7 = this->ctfg;
      v8 = this->fonth;
      v9 = this->aboutw;
      v10 = this->menuh + this->fontth;
      v11 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_ABOUT_NAME);
      this->drawtextxy_(this->pwint, v11, 0, v10, v9, v8, v7, v6);
      v12 = this->cbg;
      v13 = this->ctfg;
      v14 = this->fonth;
      v15 = this->aboutw;
      v16 = this->fontth + this->menuh + this->fonth;
      v17 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_ABOUT_VERSION);
      this->drawtextxy_(this->pwint, v17, 0, v16, v15, v14, v13, v12);
      v18 = this->cbg;
      v19 = this->ctfg;
      v20 = this->fonth;
      v21 = this->aboutw;
      v22 = this->fontth + this->menuh + 2 * this->fonth;
      v23 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_ABOUT_AUTHOR);
      this->drawtextxy_(this->pwint, v23, 0, v22, v21, v20, v19, v18);
      v24 = this->cbg;
      v25 = this->ctfg;
      v26 = this->fonth;
      v27 = this->aboutw;
      v28 = this->menuh + this->fontth + 3 * this->fonth;
      v29 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_ABOUT_LICENSE);
      this->drawtextxy_(this->pwint, v29, 0, v28, v27, v26, v25, v24);
      break;
    case 1:
      this->setfontheight_(this->faceh);
      v84 = this->cbg;
      v85 = this->ctfg;
      v86 = this->faceh;
      v87 = this->helpw;
      v88 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP + 6);
      this->drawtextxy_(this->pwint, v88, 0, 0, v87, v86, v85, v84);
      v89 = this->cbg;
      v90 = this->ctfg;
      v91 = (this->helph - this->okh_ - 20 * this->iconh) / 2;
      v92 = this->helpw / 2;
      v93 = this->menuh;
      v94 = this->helpw / 2;
      v95 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_TITLE);
      this->drawtextxy_(this->pwint, v95, v94, v93, v92, v91, v90, v89);
      this->setfontheight_(this->fonth);
      k__[0][0] = (int)this->pmenu1[0];
      k__[0][1] = (int)this->pmenu2[0];
      k__[0][2] = (int)this->pmenu3[0];
      k__[1][0] = (int)this->pface[4];
      k__[1][1] = (int)this->pface[0];
      k__[1][2] = (int)this->picone;
      k__[2][0] = (int)this->pmenuq[0];
      k__[2][1] = (int)this->pmenua[0];
      k__[2][2] = (int)this->pmenud[0];
      v281 = this->pmenut[0];
      v282 = this->pmenus[0];
      v283 = this->pmenum[0];
      v284 = *((_DWORD *)&this->launchh + 2 * (this->md + 30));
      v285 = *((_DWORD *)&this->titleh + this->singleb + 56);
      v286 = this->pface[7];
      v287 = this->pface[6];
      v288 = this->pface[5];
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
      cheatc[0] = this->cblue;
      cheatc[1] = this->cblue;
      cheatc[2] = this->cblue;
      cheatc[3] = this->cblue;
      cheatc[4] = this->cblue;
      cheatc[5] = this->cblue;
      cheatc[6] = this->cblue;
      cheatc[7] = this->cred;
      cheatc[8] = this->cred;
      helpw___0 = this->iconw;
      helph___0 = (long double)(this->helph - this->okh_ - this->iconh - this->faceh) / 16.0;
      for ( k_3 = 0; k_3 <= 16; ++k_3 )
      {
        DrawBMP(
          (pbitmap)k__[0][k_3],
          helpw___0,
          (signed __int64)((long double)k_3 * helph___0
                         + (long double)(signed int)this->menuh
                         + (long double)(this->iconh / 2)),
          this->facew,
          this->faceh,
          this->cfg);
        this->drawtextxy_(this->pwint, (const char *)picon__[0][0][k_3], helpw___0 + this->facew + this->iconw, (signed int)((long double)k_3 * helph___0
                     + (long double)(signed int)this->menuh
                     + (long double)(this->iconh / 2)), this->ctfg, this->cbg);
      }
      if ( this->cheatb == 1 )
      {
        for ( k_5 = 0; k_5 <= 8; ++k_5 )
        {
          this->drawtextxy_(this->pwint, cheatn[k_5], this->helpw / 4, (signed int)((long double)k_5 * helph___0
                       + (long double)(signed int)this->menuh
                       + (long double)(this->iconh / 2)), cheatc[k_5], this->cbg);
          this->drawtextxy_(this->pwint, cheats[k_5], this->helpw / 4 + this->facew, (signed int)((long double)k_5 * helph___0
                       + (long double)(signed int)this->menuh
                       + (long double)(this->iconh / 2)), cheatc[k_5], this->cbg);
        }
      }
      else
      {
        for ( k_4 = 0; k_4 <= 16; ++k_4 )
        {
          v96 = this->cbg;
          v97 = this->ctfg;
          v98 = this->faceh;
          v99 = this->helpw / 4;
          v100 = (signed int)((long double)k_4 * helph___0
                            + (long double)(signed int)this->menuh
                            + (long double)(this->iconh / 2));
          v101 = this->helpw / 4;
          v102 = this->bd.st.lan.getlan(k_4 + this->bd.st.lan.LAN_HELP);
          this->drawtextxy_(this->pwint, v102, v101, v100, v99, v98, v97, v96, 0);
        }
      }
      Line(this->helpw / 2, this->menuh, 0, this->helph - this->okh_, this->cline);
      for ( k_6 = 0; k_6 <= 11; ++k_6 )
        this->paintline(this->piconn, this->piconc, 2, 10, (3 * this->helpw / 2 - 12 * this->iconw) / 2, (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + (k_6 + 8) * this->iconh);
      v103 = this->cbg;
      v104 = this->cred;
      v105 = 8 * this->iconh + this->menuh + (this->helph - this->okh_ - 20 * this->iconh) / 2 - this->faceh;
      v106 = 3 * this->helpw / 2;
      v107 = this->getstringwidth_("PgUp");
      this->drawtextxy_(this->pwint, "PgUp", (v106 - v107) >> 1, v105, v104, v103);
      v108 = this->cfg;
      v109 = this->cblue;
      v110 = this->menuh + (this->helph - this->okh_ - 20 * this->iconh) / 2 + 8 * this->iconh;
      v111 = 3 * this->helpw / 2;
      v112 = this->getstringwidth_("PgDn");
      this->drawtextxy_(this->pwint, "PgDn", (v111 - v112) >> 1, v110, v109, v108);
      Bar(
        2 * this->iconw + (3 * this->helpw / 2 - 12 * this->iconw) / 2 - this->arroww,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 15 * this->iconh + this->arrowh / -2,
        this->arroww,
        this->arrowh,
        this->cmine);
      Bar(
        (3 * this->helpw / 2 - 12 * this->iconw) / 2 + 2 * this->iconw,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 15 * this->iconh + this->arrowh / -2,
        this->arroww,
        this->arrowh,
        this->cfg);
      Bar(
        (3 * this->helpw / 2 - this->arroww) / 2,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 20 * this->iconh - this->arrowh,
        this->arroww,
        this->arrowh,
        this->cfg);
      Bar(
        (3 * this->helpw / 2 - this->arroww) / 2,
        20 * this->iconh + (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh,
        this->arroww,
        this->arrowh,
        this->cbg);
      Bar(
        (3 * this->helpw / 2 - 12 * this->iconw) / 2 + 12 * this->iconw - this->arroww,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 15 * this->iconh + this->arrowh / -2,
        this->arroww,
        this->arrowh,
        this->cfg);
      Bar(
        (3 * this->helpw / 2 - 12 * this->iconw) / 2 + 12 * this->iconw,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 15 * this->iconh + this->arrowh / -2,
        this->arroww,
        this->arrowh,
        this->cbg);
      DrawBMP(
        this->parrowm,
        2 * this->iconw + (3 * this->helpw / 2 - 12 * this->iconw) / 2 - this->arroww,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 15 * this->iconh + this->arrowh / -2,
        this->arroww,
        this->arrowh,
        this->cfg);
      DrawBMP(
        this->parrowp,
        (3 * this->helpw / 2 - 12 * this->iconw) / 2 + 2 * this->iconw,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 15 * this->iconh + this->arrowh / -2,
        this->arroww,
        this->arrowh,
        this->cfg);
      DrawBMP(
        this->parrowu,
        (3 * this->helpw / 2 - this->arroww) / 2,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 20 * this->iconh - this->arrowh,
        this->arroww,
        this->arrowh,
        this->cfg);
      DrawBMP(
        this->parrowd,
        (3 * this->helpw / 2 - this->arroww) / 2,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 20 * this->iconh,
        this->arroww,
        this->arrowh,
        this->cfg);
      DrawBMP(
        this->parrowl,
        (3 * this->helpw / 2 - 12 * this->iconw) / 2 + 12 * this->iconw - this->arroww,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 15 * this->iconh + this->arrowh / -2,
        this->arroww,
        this->arrowh,
        this->cfg);
      DrawBMP(
        this->parrowr,
        (3 * this->helpw / 2 - 12 * this->iconw) / 2 + 12 * this->iconw,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 15 * this->iconh + this->arrowh / -2,
        this->arroww,
        this->arrowh,
        this->cfg);
      Line(
        (3 * this->helpw / 2 - 12 * this->iconw) / 2,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh - 1,
        12 * this->iconw,
        0,
        this->ctfg);
      Line(
        (3 * this->helpw / 2 - 12 * this->iconw) / 2,
        this->menuh + (this->helph - this->okh_ - 20 * this->iconh) / 2 + 8 * this->iconh - 1,
        12 * this->iconw,
        0,
        this->ctfg);
      Line(
        (3 * this->helpw / 2 - 12 * this->iconw) / 2,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh + 20 * this->iconh - 1,
        12 * this->iconw,
        0,
        this->ctfg);
      Line(
        (3 * this->helpw / 2 - 12 * this->iconw) / 2 - 1,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh,
        0,
        20 * this->iconh,
        this->ctfg);
      Line(
        (3 * this->helpw / 2 - 12 * this->iconw) / 2 + 2 * this->iconw - 1,
        (this->helph - this->okh_ - 4 * this->iconh) / 2 + this->menuh,
        0,
        12 * this->iconh,
        this->ctfg);
      Line(
        (3 * this->helpw / 2 - 12 * this->iconw) / 2 + 12 * this->iconw - 1,
        (this->helph - this->okh_ - 20 * this->iconh) / 2 + this->menuh,
        0,
        20 * this->iconh,
        this->ctfg);
      break;
    case 2:
      this->setfontheight_(this->faceh);
      v113 = this->cbg;
      v114 = this->ctfg;
      v115 = this->faceh;
      v116 = this->helpw;
      v117 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_TITLE + 1);
      this->drawtextxy_(this->pwint, v117, 0, 0, v116, v115, v114, v113);
      this->setfontheight_(this->fontmh);
      for ( j_0 = 0; j_0 <= 2; ++j_0 )
      {
        for ( i = 0; i <= 3; ++i )
        {
          this->bl.initbl();
          v118 = j_0;
          if ( j_0 > 0 )
            v118 = 1;
          j_ = v118;
          if ( j_0 == 1 )
          {
            if ( i == 1 || i == 3 )
              (*this->bl.flag)[j_ + 128] = 1;
          }
          else if ( j_0 == 2 )
          {
            if ( i == 1 )
              (*this->bl.qstn)[j_ + 128] = 1;
          }
          else if ( !j_0 && (i == 1 || i == 3) )
          {
            (*this->bl.blck)[j_ + 128] = 1;
          }
          if ( i == 2 )
            (*this->bl.qstn)[j_ + 128] = 1;
          this->paintboard(&this->bl, (2 * i + 1) * this->helpw / 8 + this->bl.w * this->iconw / -2, (2 * j_0 + 1) * (this->helph - this->okh_) / 6 + this->bl.h * this->iconh / -2, 1, j_);
        }
      }
      for ( i_0 = 0; i_0 <= 2; ++i_0 )
      {
        for ( j_1 = 0; j_1 <= 2; ++j_1 )
        {
          picon__[0][0][0] = this->piconc;
          picon__[0][0][1] = this->picona;
          picon__[0][0][2] = this->picon[3];
          picon__[0][0][3] = this->piconp;
          picon__[0][0][4] = this->piconp;
          picon__[0][1][0] = this->piconp;
          picon__[0][1][1] = this->piconp;
          picon__[0][1][2] = this->piconp;
          picon__[0][1][3] = this->piconp;
          picon__[0][1][4] = this->piconp;
          picon__[0][2][0] = this->piconq;
          picon__[0][2][1] = this->picona;
          picon__[0][2][2] = this->picon[3];
          picon__[0][2][3] = this->piconp;
          picon__[0][2][4] = this->piconp;
          picon__[1][0][0] = this->piconc;
          picon__[1][0][1] = this->picona;
          picon__[1][0][2] = this->piconm;
          picon__[1][0][3] = this->picona;
          picon__[1][0][4] = this->piconf;
          picon__[1][1][0] = this->piconp;
          picon__[1][1][1] = this->piconp;
          picon__[1][1][2] = this->piconp;
          picon__[1][1][3] = this->piconp;
          picon__[1][1][4] = this->piconp;
          picon__[1][2][0] = this->piconq;
          picon__[1][2][1] = this->picona;
          picon__[1][2][2] = this->piconm;
          picon__[1][2][3] = this->picona;
          picon__[1][2][4] = this->piconf;
          picon__[2][0][0] = this->piconc;
          picon__[2][0][1] = this->picona;
          picon__[2][0][2] = this->piconq;
          picon__[2][0][3] = this->piconp;
          picon__[2][0][4] = this->piconp;
          picon__[2][1][0] = this->piconp;
          picon__[2][1][1] = this->piconp;
          picon__[2][1][2] = this->piconp;
          picon__[2][1][3] = this->piconp;
          picon__[2][1][4] = this->piconp;
          picon__[2][2][0] = this->piconq;
          picon__[2][2][1] = this->picona;
          picon__[2][2][2] = this->piconc;
          picon__[2][2][3] = this->piconp;
          picon__[2][2][4] = this->piconp;
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
                this->pclickr,
                2 * (i_0 + 1) * this->helpw / 8 + this->clickw / -2,
                -3 * this->iconh + 5 * (this->helph - this->okh_) / 6 + this->menuh,
                this->cfg);
          }
          else
          {
            DrawBMP(
              this->pclickl,
              2 * (i_0 + 1) * this->helpw / 8 + this->clickw / -2,
              -3 * this->iconh + (2 * j_1 + 1) * (this->helph - this->okh_) / 6 + this->menuh,
              this->cfg);
          }
          for ( k_7 = 0; k__[0][i_0 + 3 * j_1] > k_7; ++k_7 )
          {
            if ( picon__[0][0][5 * i_0 + 15 * j_1 + k_7] == this->picona )
              DrawBMP(
                picon__[0][0][5 * i_0 + 15 * j_1 + k_7],
                2 * (i_0 + 1) * this->helpw / 8 + this->iconw * (2 * k_7 - k__[0][i_0 + 3 * j_1]) / 2,
                this->clickh + -3 * this->iconh + (2 * j_1 + 1) * (this->helph - this->okh_) / 6 + this->menuh,
                this->cfg);
            else
              DrawBMP(
                picon__[0][0][5 * i_0 + 15 * j_1 + k_7],
                2 * (i_0 + 1) * this->helpw / 8 + this->iconw * (2 * k_7 - k__[0][i_0 + 3 * j_1]) / 2,
                this->clickh + -3 * this->iconh + (2 * j_1 + 1) * (this->helph - this->okh_) / 6 + this->menuh,
                this->cbg);
          }
          if ( !i_0 || i_0 == 2 )
          {
            v119 = this->cbg;
            v120 = this->ctfg;
            v121 = 2 * this->iconh + (this->helph - this->okh_) / 6 - this->clickh;
            v122 = this->helpw / 2;
            v123 = this->menuh
                 + this->clickh
                 + -3 * this->iconh
                 + (2 * j_1 + 1) * (this->helph - this->okh_) / 6
                 + this->iconh;
            v124 = i_0 / 2 * this->helpw / 2;
            v125 = this->bd.st.lan.getlan(2 * j_1 + this->bd.st.lan.LAN_HELP_MENU + i_0 / 2);
            this->drawtextxy_(this->pwint, v125, v124, v123, v122, v121, v120, v119);
          }
        }
      }
      Line(this->helpw / 2, this->menuh, 0, this->helph - this->okh_, this->cline);
      for ( k_8 = 1; k_8 <= 2; ++k_8 )
        Line(0, this->menuh + k_8 * (this->helph - this->okh_) / 3, this->helpw, 0, this->cline);
      this->setfontheight_(this->fonth);
      break;
    case 3:
      this->setfontheight_(this->faceh);
      v126 = this->cbg;
      v127 = this->ctfg;
      v128 = this->faceh;
      v129 = this->helpw;
      v130 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_TITLE + 2);
      this->drawtextxy_(this->pwint, v130, 0, 0, v129, v128, v127, v126);
      this->setfontheight_(this->fontmh);
      for ( j_2 = 0; j_2 <= 2; ++j_2 )
      {
        for ( i_1 = 0; i_1 <= 3; ++i_1 )
        {
          this->bl.initbl();
          (*this->bl.blck)[128] = 1;
          (*this->bl.flag)[129] = 1;
          j__0 = 2;
          switch ( j_2 )
          {
            case 1:
              (*this->bl.flag)[129] = 1;
              if ( !i_1 )
                (*this->bl.qstn)[1] = 1;
              if ( i_1 > 0 )
              {
                (*this->bl.blck)[2] = 1;
                (*this->bl.blck)[3] = 1;
              }
              if ( i_1 == 2 )
                (*this->bl.flag)[1] = 1;
              break;
            case 2:
              (*this->bl.flag)[129] = 1;
              if ( !i_1 )
                (*this->bl.qstn)[3] = 1;
              if ( i_1 > 0 )
              {
                (*this->bl.blck)[2] = 1;
                (*this->bl.flag)[1] = 1;
              }
              if ( i_1 == 2 )
                (*this->bl.blck)[3] = 1;
              break;
            case 0:
              if ( i_1 <= 1 )
                j__0 = 0;
              if ( !i_1 )
                (*this->bl.qstn)[1] = 1;
              if ( i_1 > 0 )
              {
                *(_BYTE *)this->bl.flag = 1;
                (*this->bl.flag)[1] = 1;
              }
              if ( i_1 == 3 )
              {
                (*this->bl.blck)[2] = 1;
                (*this->bl.blck)[3] = 1;
              }
              break;
          }
          if ( !j_2 || i_1 <= 2 )
            this->paintboard(&this->bl, (2 * i_1 + 1 + (j_2 != 0)) * this->helpw / 8 + this->bl.w * this->iconw / -2, (2 * j_2 + 1) * (this->helph - this->okh_) / 6 + this->bl.h * this->iconh / -2, 1, j__0);
        }
      }
      for ( i_2 = 0; i_2 <= 2; ++i_2 )
      {
        for ( j_3 = 0; j_3 <= 2; ++j_3 )
        {
          memset(picon__, 0, 0xF0u);
          *(_QWORD *)&picon__[0][0][0] = *(_QWORD *)&this->piconc;
          picon__[0][0][2] = this->piconf;
          picon__[0][0][3] = this->piconu;
          picon__[0][0][4] = this->picon[3];
          picon__[0][1][0] = this->piconp;
          picon__[0][1][1] = this->piconp;
          picon__[0][1][2] = this->piconp;
          picon__[0][1][3] = this->piconp;
          picon__[0][1][4] = this->piconp;
          picon__[0][2][0] = this->piconf;
          picon__[0][2][1] = this->piconu;
          picon__[0][2][2] = this->picon[2];
          picon__[0][2][3] = this->piconp;
          picon__[0][2][4] = this->piconp;
          *(_QWORD *)&picon__[1][1][0] = *(_QWORD *)&this->piconq;
          picon__[1][1][2] = this->piconu;
          picon__[1][1][3] = this->picon[2];
          picon__[1][1][4] = this->piconp;
          *(_QWORD *)&picon__[1][2][0] = *(_QWORD *)&this->piconc;
          picon__[1][2][2] = this->piconf;
          picon__[1][2][3] = this->piconu;
          picon__[1][2][4] = this->picon[2];
          picon__[2][0][0] = this->piconp;
          picon__[2][0][1] = this->piconp;
          picon__[2][0][2] = this->piconp;
          picon__[2][0][3] = this->piconp;
          picon__[2][0][4] = this->piconp;
          *(_QWORD *)&picon__[2][2][0] = *(_QWORD *)&this->piconq;
          picon__[2][2][2] = this->piconu;
          picon__[2][2][3] = this->picon[2];
          picon__[2][2][4] = this->piconp;
          v300 = this->piconf;
          v301 = this->piconu;
          v302 = this->picon[2];
          v303 = this->piconp;
          v304 = this->piconp;
          v305 = this->piconp;
          v306 = this->piconp;
          v307 = this->piconp;
          v308 = this->piconp;
          v309 = this->piconp;
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
                this->pclickn,
                (2 * (i_2 + 1) + (j_3 != 0)) * this->helpw / 8 + this->clickw / -2,
                -3 * this->iconh + (2 * j_3 + 1) * (this->helph - this->okh_) / 6 + this->menuh,
                this->cfg);
          }
          else
          {
            DrawBMP(
              this->pclicka,
              (2 * (i_2 + 1) + (j_3 != 0)) * this->helpw / 8 + this->clickw / -2,
              -3 * this->iconh + (2 * j_3 + 1) * (this->helph - this->okh_) / 6 + this->menuh,
              this->cfg);
          }
          for ( k_9 = 0; k__[0][i_2 + 3 * j_3] > k_9; ++k_9 )
          {
            if ( picon__[0][0][20 * j_3 + 5 * i_2 + k_9] == this->piconu )
              DrawBMP(
                picon__[0][0][20 * j_3 + 5 * i_2 + k_9],
                (2 * (i_2 + 1) + (j_3 != 0)) * this->helpw / 8 + this->iconw * (2 * k_9 - k__[0][i_2 + 3 * j_3]) / 2,
                this->clickh + -3 * this->iconh + (2 * j_3 + 1) * (this->helph - this->okh_) / 6 + this->menuh,
                this->cfg);
            else
              DrawBMP(
                picon__[0][0][20 * j_3 + 5 * i_2 + k_9],
                (2 * (i_2 + 1) + (j_3 != 0)) * this->helpw / 8 + this->iconw * (2 * k_9 - k__[0][i_2 + 3 * j_3]) / 2,
                this->clickh + -3 * this->iconh + (2 * j_3 + 1) * (this->helph - this->okh_) / 6 + this->menuh,
                this->cbg);
          }
          if ( (!i_2 || i_2 == 2) && !j_3 )
          {
            v131 = this->cbg;
            v132 = this->ctfg;
            v133 = 2 * this->iconh + (this->helph - this->okh_) / 6 - this->clickh;
            v134 = this->helpw / 2;
            v135 = this->menuh + this->clickh + -3 * this->iconh + (this->helph - this->okh_) / 6 + this->iconh;
            v136 = i_2 / 2 * this->helpw / 2;
            v137 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + i_2 / 2 + 6);
            this->drawtextxy_(this->pwint, v137, v136, v135, v134, v133, v132, v131);
          }
          if ( !i_2 && j_3 > 0 )
          {
            v138 = this->cbg;
            v139 = this->ctfg;
            v140 = 2 * this->iconh + (this->helph - this->okh_) / 6 - this->clickh;
            v141 = this->helpw;
            v142 = this->menuh
                 + this->clickh
                 + -3 * this->iconh
                 + (2 * j_3 + 1) * (this->helph - this->okh_) / 6
                 + this->iconh;
            v143 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + j_3 + 7);
            this->drawtextxy_(this->pwint, v143, 0, v142, v141, v140, v139, v138);
          }
        }
      }
      Line(this->helpw / 2, this->menuh, 0, (this->helph - this->okh_) / 3, this->cline);
      for ( k_10 = 1; k_10 <= 2; ++k_10 )
        Line(0, this->menuh + k_10 * (this->helph - this->okh_) / 3, this->helpw, 0, this->cline);
      break;
    case 4:
      this->setfontheight_(this->faceh);
      v144 = this->cbg;
      v145 = this->ctfg;
      v146 = this->faceh;
      v147 = this->helpw;
      v148 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_TITLE + 3);
      this->drawtextxy_(this->pwint, v148, 0, 0, v147, v146, v145, v144);
      this->setfontheight_(this->fontmh);
      iconwl = 5;
      iconwm = 18;
      iconwr = 20;
      iconwn = 34;
      iconh1 = 2;
      iconh2 = 10;
      iconh3 = 21;
      this->paintline(this->picone, 2, 20 * this->iconw, 2 * this->iconh + this->menuh);
      this->paintline(this->piconc, 12, 20 * this->iconw, 3 * this->iconh + this->menuh);
      this->paintline(this->piconc, 12, 20 * this->iconw, 4 * this->iconh + this->menuh);
      this->paintline(this->picone, 2, 5 * this->iconw, 4 * this->iconh + this->menuh);
      this->paintline(this->piconc, this->piconm, this->picon[1], this->piconp, 5, 1, 1, 5, 5 * this->iconw, 5 * this->iconh + this->menuh);
      this->paintline(this->piconc, this->piconf, this->picon[1], this->piconp, 5, 1, 1, 5, 20 * this->iconw, 5 * this->iconh + this->menuh);
      DrawBMP(this->picona, 18 * this->iconw, 5 * this->iconh + this->menuh, this->cfg);
      DrawBMP(
        this->pface[3],
        18 * this->iconw + (this->facew - this->iconw) / -2,
        this->menuh + 5 * this->iconh - this->iconh + this->faceh / -2,
        this->cfg);
      v149 = this->cbg;
      v150 = this->ctfg;
      v151 = 2 * this->iconh;
      v152 = this->helpw;
      v153 = 6 * this->iconh + this->menuh;
      v154 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + 10);
      this->drawtextxy_(this->pwint, v154, 0, v153, v152, v151, v150, v149);
      for ( k_11 = 0; k_11 <= 2; ++k_11 )
      {
        this->paintline(this->picone, 2, iconwl * this->iconw, (3 * k_11 + iconh2) * this->iconh + this->menuh);
        this->paintline(this->picone, k_11 + 3, iconwr * this->iconw, (3 * k_11 + iconh2) * this->iconh + this->menuh);
        this->paintline(this->piconc, 12, iconwl * this->iconw, (3 * k_11 + iconh2 + 1) * this->iconh + this->menuh);
        this->paintline(this->piconc, 12, iconwr * this->iconw, (3 * k_11 + iconh2 + 1) * this->iconh + this->menuh);
        this->paintnumber(5 * k_11, 2, iconwn * this->iconw, this->menuh + (3 * k_11 + iconh2 + 1) * this->iconh + this->digth[0] / -2);
        DrawBMP(this->picona, iconwm * this->iconw, (3 * k_11 + iconh2 + 1) * this->iconh + this->menuh, this->cfg);
      }
      v155 = this->cbg;
      v156 = this->ctfg;
      v157 = (iconh3 - iconh2 - 10) * this->iconh + this->iconh / 2;
      v158 = this->helpw;
      v159 = this->iconh * (iconh2 + 8) + this->menuh;
      v160 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + 11);
      this->drawtextxy_(this->pwint, v160, 0, v159, v158, v157, v156, v155);
      this->paintline(this->picone, 12, iconwl * this->iconw, iconh3 * this->iconh + this->menuh);
      this->paintline(this->piconc, 12, iconwr * this->iconw, iconh3 * this->iconh + this->menuh);
      this->paintline(this->piconc, 12, iconwl * this->iconw, this->iconh * (iconh3 + 1) + this->menuh);
      this->paintline(this->piconc, 12, iconwr * this->iconw, this->iconh * (iconh3 + 1) + this->menuh);
      DrawBMP(this->picona, iconwm * this->iconw, this->iconh * (iconh3 + 1) + this->menuh, this->cfg);
      v161 = this->cbg;
      v162 = this->ctfg;
      v163 = this->helph - this->okh_ - (iconh3 + 2) * this->iconh;
      v164 = this->helpw;
      v165 = this->iconh * (iconh3 + 2) + this->menuh;
      v166 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + 12);
      this->drawtextxy_(this->pwint, v166, 0, v165, v164, v163, v162, v161);
      Line(0, this->menuh + (iconh2 - 2) * this->iconh, this->helpw, 0, this->cline);
      Line(0, (iconh3 - 2) * this->iconh + this->menuh + this->iconh / 2, this->helpw, 0, this->cline);
      this->setfontheight_(this->fonth);
      break;
    case 5:
      this->setfontheight_(this->faceh);
      v167 = this->cbg;
      v168 = this->ctfg;
      v169 = this->faceh;
      v170 = this->helpw;
      v171 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_TITLE + 4);
      this->drawtextxy_(this->pwint, v171, 0, 0, v170, v169, v168, v167);
      this->setfontheight_(this->fontmh);
      iconwl_0 = 3;
      iconwm_0 = 16;
      iconwr_0 = 20;
      iconwn_0 = 34;
      iconh1_0 = 2;
      iconh2_0 = 6;
      iconh3_0 = 11;
      iconh4 = 22;
      this->paintline(this->piconc, this->picon[2], this->piconp, 4, 1, 7, 3 * this->iconw, this->iconh / -2 + 2 * this->iconh + this->menuh);
      this->paintline(this->piconc, this->piconf, this->picon[2], this->piconp, 2, 2, 1, 7, 3 * this->iconw, this->iconh / -2 + 3 * this->iconh + this->menuh);
      this->paintline(this->piconc, this->piconf, this->picon[3], this->picon[1], this->piconp, 2, 1, 1, 1, 7, 3 * this->iconw, this->iconh / -2 + 4 * this->iconh + this->menuh);
      this->paintline(this->piconc, this->picon[1], this->piconp, 4, 1, 7, 20 * this->iconw, this->iconh / -2 + 3 * this->iconh + this->menuh);
      this->paintline(this->piconc, this->piconf, this->picon[3], this->picon[1], this->piconp, 2, 1, 1, 1, 7, 20 * this->iconw, this->iconh / -2 + 4 * this->iconh + this->menuh);
      Line(
        3 * this->iconw,
        this->menuh + this->iconh / 2 + this->iconh / -2 + 3 * this->iconh,
        12 * this->iconw,
        0,
        this->cred);
      DrawBMP(this->piconf, 16 * this->iconw, this->iconh / -2 + 4 * this->iconh + this->menuh, this->cbg);
      DrawBMP(this->piconu, 17 * this->iconw, this->iconh / -2 + 4 * this->iconh + this->menuh, this->cfg);
      DrawBMP(this->piconn, 18 * this->iconw, this->iconh / -2 + 4 * this->iconh + this->menuh, this->cbg);
      DrawBMP(
        this->pface[4],
        17 * this->iconw + (this->facew - this->iconw) / -2,
        this->menuh + this->iconh / -2 + 4 * this->iconh - this->iconh + this->faceh / -2,
        this->cbg);
      this->paintnumber(1, 4, 34 * this->iconw, this->menuh + this->iconh / -2 + 4 * this->iconh + this->digth[0] / -2);
      v172 = this->cbg;
      v173 = this->ctfg;
      v174 = 3 * this->iconh / 2;
      v175 = this->helpw;
      v176 = this->iconh / -2 + 5 * this->iconh + this->menuh;
      v177 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + 13);
      this->drawtextxy_(this->pwint, v177, 0, v176, v175, v174, v173, v172);
      this->paintline(this->piconc, this->picon[2], this->piconp, 4, 1, 7, 3 * this->iconw, 6 * this->iconh + this->menuh);
      this->paintline(this->picon[1], this->picon[4], this->piconc, this->picon[2], this->piconp, 1, 1, 2, 1, 7, 3 * this->iconw, 7 * this->iconh + this->menuh);
      this->paintline(this->piconc, this->piconc, this->picon[3], this->picon[1], this->piconp, 2, 1, 1, 1, 7, 3 * this->iconw, 8 * this->iconh + this->menuh);
      this->paintline(this->piconc, this->picon[1], this->piconp, 4, 1, 7, 20 * this->iconw, 7 * this->iconh + this->menuh);
      this->paintline(this->piconc, this->picon[3], this->picon[1], this->piconp, 3, 1, 1, 7, 20 * this->iconw, 8 * this->iconh + this->menuh);
      Line(3 * this->iconw, this->menuh + this->iconh / 2 + 7 * this->iconh, 12 * this->iconw, 0, this->cred);
      DrawBMP(this->piconc, 16 * this->iconw, 8 * this->iconh + this->menuh, this->cbg);
      DrawBMP(this->piconu, 17 * this->iconw, 8 * this->iconh + this->menuh, this->cfg);
      DrawBMP(this->piconn, 18 * this->iconw, 8 * this->iconh + this->menuh, this->cbg);
      DrawBMP(
        this->pface[4],
        17 * this->iconw + (this->facew - this->iconw) / -2,
        this->menuh + 8 * this->iconh - this->iconh + this->faceh / -2,
        this->cbg);
      this->paintnumber(1, 4, 34 * this->iconw, this->menuh + 8 * this->iconh + this->digth[0] / -2);
      v178 = this->cbg;
      v179 = this->ctfg;
      v180 = 3 * this->iconh / 2;
      v181 = this->helpw;
      v182 = 9 * this->iconh + this->menuh;
      v183 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + 14);
      this->drawtextxy_(this->pwint, v183, 0, v182, v181, v180, v179, v178);
      this->paintline(this->piconp, 12, 3 * this->iconw, this->iconh / -2 + 15 * this->iconh + this->menuh);
      Line(
        3 * this->iconw,
        this->menuh + this->iconh / 2 + this->iconh / -2 + 15 * this->iconh,
        12 * this->iconw,
        0,
        this->cred);
      for ( k_12 = 0; k_12 <= 7; ++k_12 )
      {
        if ( k_12 > 4 )
          this->paintline(this->piconc, 12, iconwl_0 * this->iconw, this->iconh / -2 + this->iconh * (iconh3_0 + k_12) + this->menuh);
        if ( k_12 > 0 )
          this->paintline(this->piconc, 12, iconwr_0 * this->iconw, this->iconh / -2 + this->iconh * (iconh3_0 + k_12) + this->menuh);
      }
      DrawBMP(
        this->picona,
        (iconwm_0 + 1) * this->iconw,
        this->iconh / -2 + this->iconh * (iconh3_0 + 7) + this->menuh,
        this->cfg);
      DrawBMP(
        this->pface[1],
        this->iconw * (iconwm_0 + 1) + (this->facew - this->iconw) / -2,
        this->menuh + this->iconh / -2 + this->iconh * (iconh3_0 + 7) - this->iconh + this->faceh / -2,
        this->cfg);
      this->paintnumber(5, 4, iconwn_0 * this->iconw, this->menuh + this->iconh / -2 + this->iconh * (iconh3_0 + 7) + this->digth[0] / -2);
      v184 = this->cbg;
      v185 = this->ctfg;
      v186 = 3 * this->iconh / 2;
      v187 = this->helpw;
      v188 = this->iconh / -2 + this->iconh * (iconh3_0 + 8) + this->menuh;
      v189 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + 15);
      this->drawtextxy_(this->pwint, v189, 0, v188, v187, v186, v185, v184);
      for ( k_13 = 0; k_13 <= 2; ++k_13 )
      {
        this->paintnumber((k_13 + 2) * (k_13 + 2), 4, (2 * k_13 + 1) * this->helpw / 6 - 4 * this->digtw[0] + this->iconw / -2, this->menuh + iconh4 * this->iconh + this->digth[0] / -2);
        this->paintnumber(k_13 + 2, 2, 2 * this->digtw[0] + (2 * k_13 + 1) * this->helpw / 6 + this->iconw / 2, this->menuh + iconh4 * this->iconh + this->digth[0] / -2);
        DrawBMP(
          this->picona,
          this->digtw[0] + (2 * k_13 + 1) * this->helpw / 6 + this->iconw / -2,
          this->menuh + iconh4 * this->iconh + this->iconh / -2,
          this->cfg);
      }
      v190 = this->cbg;
      v191 = this->ctfg;
      v192 = this->helph - this->okh_ - (iconh4 * this->iconh + this->digth[0] / 2);
      v193 = this->helpw;
      v194 = this->digth[0] / 2 + iconh4 * this->iconh + this->menuh;
      v195 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + 16);
      this->drawtextxy_(this->pwint, v195, 0, v194, v193, v192, v191, v190);
      Line(0, this->menuh + this->iconh * (iconh3_0 - 1) + this->iconh / 2, this->helpw, 0, this->cline);
      Line(0, this->iconh * (iconh4 - 2) + this->menuh, this->helpw, 0, this->cline);
      this->setfontheight_(this->fonth);
      break;
    case 6:
      this->setfontheight_(this->faceh);
      v196 = this->cbg;
      v197 = this->ctfg;
      v198 = this->faceh;
      v199 = this->helpw;
      v200 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_TITLE + 5);
      this->drawtextxy_(this->pwint, v200, 0, 0, v199, v198, v197, v196);
      this->setfontheight_(this->fontmh);
      for ( i_3 = 0; i_3 <= 31; ++i_3 )
      {
        for ( j_4 = 0; j_4 <= 23; ++j_4 )
          DrawBMP(
            this->piconp,
            (i_3 + 4) * this->iconw,
            this->menuh + this->iconh / 2 + j_4 * this->iconh,
            this->cfg);
      }
      for ( j_5 = 0; j_5 <= 23; ++j_5 )
      {
        if ( j_5 <= 11 )
          v201 = 2;
        else
          v201 = 3;
        if ( j_5 <= 15 )
          v202 = 0;
        else
          v202 = 3;
        this->paintline(this->piconn, v201 + v202, 5 * this->iconw, this->iconh / 2 + this->menuh + (j_5 + 1) * this->iconh - this->iconh);
      }
      for ( j_6 = 0; j_6 <= 23; ++j_6 )
        DrawBMP(
          *((pbitmap *)&this->titlew + j_6 % 10 + 85),
          4 * this->iconw,
          j_6 * this->iconh + this->iconh / 2 + this->menuh,
          this->cbg);
      for ( i_4 = 0; i_4 <= 31; ++i_4 )
        DrawBMP(
          *((pbitmap *)&this->titlew + i_4 % 10 + 85),
          (i_4 + 4) * this->iconw,
          this->iconh / 2 + this->menuh,
          this->cbg);
      DrawBMP(
        this->pmenu1[0],
        16 * this->iconw - this->menuw,
        this->iconh / 2 + this->menuh + 12 * this->iconh - this->menuh,
        this->cbg);
      DrawBMP(
        this->pmenu2[0],
        20 * this->iconw - this->menuw,
        16 * this->iconh + this->menuh + this->iconh / 2 - this->menuh,
        this->cbg);
      DrawBMP(
        this->pmenu3[0],
        36 * this->iconw - this->menuw,
        this->iconh / 2 + this->menuh + 24 * this->iconh - this->menuh,
        this->cbg);
      Line(4 * this->iconw, this->iconh / 2 + this->menuh + 12 * this->iconh - 1, 12 * this->iconw, 0, this->ctfg);
      Line(4 * this->iconw, this->menuh + this->iconh / 2 + 16 * this->iconh - 1, 16 * this->iconw, 0, this->ctfg);
      Line(4 * this->iconw, this->iconh / 2 + this->menuh + 24 * this->iconh - 1, 32 * this->iconw, 0, this->ctfg);
      Line(4 * this->iconw, this->iconh / 2 + this->menuh - 1, 32 * this->iconw, 0, this->ctfg);
      Line(16 * this->iconw - 1, this->menuh + this->iconh / 2, 0, 12 * this->iconh, this->ctfg);
      Line(20 * this->iconw - 1, this->iconh / 2 + this->menuh, 0, 16 * this->iconh, this->ctfg);
      Line(36 * this->iconw - 1, this->iconh / 2 + this->menuh, 0, 24 * this->iconh, this->ctfg);
      Line(4 * this->iconw - 1, this->menuh + this->iconh / 2, 0, 24 * this->iconh, this->ctfg);
      v203 = this->cfg;
      v204 = this->ctfg;
      v205 = this->fontmh;
      v206 = 15 * this->iconw - this->menuw;
      v207 = this->iconh / 2 + this->menuh + 12 * this->iconh - this->fontmh - 1;
      v208 = 5 * this->iconw;
      v209 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + 17);
      this->drawtextxy_(this->pwint, v209, v208, v207, v206, v205, v204, v203, 0);
      v210 = this->cfg;
      v211 = this->ctfg;
      v212 = this->fontmh;
      v213 = 15 * this->iconw - this->menuw;
      v214 = 16 * this->iconh + this->menuh + this->iconh / 2 - this->fontmh - 1;
      v215 = 5 * this->iconw;
      v216 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + 18);
      this->drawtextxy_(this->pwint, v216, v215, v214, v213, v212, v211, v210, 0);
      v217 = this->cfg;
      v218 = this->ctfg;
      v219 = this->fontmh;
      v220 = 15 * this->iconw - this->menuw;
      v221 = this->iconh / 2 + this->menuh + 24 * this->iconh - this->fontmh - 1;
      v222 = 5 * this->iconw;
      v223 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_HELP_MENU + 19);
      this->drawtextxy_(this->pwint, v223, v222, v221, v220, v219, v218, v217, 0);
      this->setfontheight_(this->fonth);
      break;
    default:
      break;
  }
  if ( this->helpi == -1 )
  {
    this->setfontheight_(this->fonth);
    v224 = this->okh;
    v225 = this->okw;
    v226 = (this->okh_ + this->okh) / -2 + this->abouth + this->menuh;
    v227 = (this->aboutw - this->okw) / 2;
    v228 = GetWin();
    DrawBMP(this->pok, v228, v227, v226, v225, v224);
    v229 = this->ctbg;
    v230 = this->ctfg;
    v231 = this->okh;
    v232 = this->okw;
    v233 = this->abouth + (this->okh_ + this->okh) / -2 + this->menuh;
    v234 = (this->aboutw - this->okw) / 2;
    v235 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_ABOUT_OK);
    this->drawtextxy_(this->pwint, v235, v234, v233, v232, v231, v230, v229);
  }
  else if ( this->helpi )
  {
    this->setfontheight_(this->fonth);
    v236 = this->okh;
    v237 = this->okw;
    v238 = (this->okh_ + this->okh) / -2 + this->helph + this->menuh;
    v239 = (this->helpw - this->okw) / 2;
    v240 = GetWin();
    DrawBMP(this->pok, v240, v239, v238, v237, v236);
    v241 = this->ctbg;
    v242 = this->ctfg;
    v243 = this->okh;
    v244 = this->okw;
    v245 = this->helph + (this->okh_ + this->okh) / -2 + this->menuh;
    v246 = (this->helpw - this->okw) / 2;
    v247 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_ABOUT_OK);
    this->drawtextxy_(this->pwint, v247, v246, v245, v244, v243, v242, v241);
    if ( this->helpi > 1 && this->helpi <= this->maxhelp )
    {
      v248 = this->btnh;
      v249 = this->btnw;
      v250 = (this->okh_ + this->okh) / -2 + this->helph + this->menuh;
      v251 = (this->helpw - this->okw) / 2 - 2 * this->btnw;
      v252 = GetWin();
      DrawBMP(this->pbtn, v252, v251, v250, v249, v248);
      this->drawtextxy_(this->pwint, "<", (this->helpw - this->okw) / 2 - 2 * this->btnw, this->helph + (this->okh_ + this->okh) / -2 + this->menuh, this->btnw, this->btnh, this->ctfg, this->ctbg);
    }
    if ( this->helpi > 0 && this->helpi < this->maxhelp )
    {
      v253 = this->btnh;
      v254 = this->btnw;
      v255 = (this->okh_ + this->okh) / -2 + this->helph + this->menuh;
      v256 = (this->helpw + this->okw) / 2 + this->btnw;
      v257 = GetWin();
      DrawBMP(this->pbtn, v257, v256, v255, v254, v253);
      this->drawtextxy_(this->pwint, (const char *)&stru_4292A8, (this->helpw + this->okw) / 2 + this->btnw, this->helph + (this->okh_ + this->okh) / -2 + this->menuh, this->btnw, this->btnh, this->ctfg, this->ctbg);
    }
    v258 = this->tuth;
    v259 = this->tutw;
    v260 = (this->okh_ + this->okh) / -2 + this->helph + this->menuh;
    v261 = -3 * this->btnw + (this->helpw - this->okw) / 2 - this->tutw;
    v262 = GetWin();
    DrawBMP(this->pok, v262, v261, v260, v259, v258);
    v263 = this->ctbg;
    v264 = this->ctfg;
    v265 = this->tuth;
    v266 = this->tutw;
    v267 = this->helph + (this->okh_ + this->okh) / -2 + this->menuh;
    v268 = (this->helpw - this->okw) / 2 - 3 * this->btnw - this->tutw;
    v269 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_TUT_);
    this->drawtextxy_(this->pwint, v269, v268, v267, v266, v265, v264, v263);
    Line(0, this->menuh, this->helpw, 0, this->cline);
    Line(0, this->helph + this->menuh - this->okh_, this->helpw, 0, this->cline);
  }
}


// 原始位置：window.cpp:1521；地址：0x0041D9A2
// 调试记录声明：void painttut()
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
// 原始局部变量：long int i；long int j。
void Window::painttut()
{
  int i;
  int j;
  unsigned int cbg;
  unsigned int v4;
  unsigned int v5;
  int v6;
  bitmap *v7;
  unsigned int v8;
  unsigned int v9;
  unsigned int w;
  int y;
  int v12;
  int v13;
  __int16 *v14;
  unsigned int v15;
  unsigned int v16;
  unsigned int v17;
  int v18;
  bitmap *v19;
  unsigned int v20;
  unsigned int v21;
  unsigned int v22;
  int v23;
  int v24;
  int v25;
  __int16 *v26;
  unsigned int v27;
  unsigned int v28;
  int v29;
  unsigned int v30;
  int v31;
  __int16 *v32;
  unsigned int v33;
  unsigned int v34;
  int v35;
  unsigned int v36;
  int v37;
  __int16 *v38;
  unsigned int v39;
  unsigned int v40;
  unsigned int v41;
  bitmap *v42;
  unsigned int v43;
  unsigned int v44;
  unsigned int v45;
  unsigned int v46;
  bitmap *v47;
  unsigned int v48;
  unsigned int v49;
  unsigned int v50;
  unsigned int v51;
  int v52;
  __int16 *v53;
  unsigned int v54;
  unsigned int v55;
  unsigned int v56;
  int v57;
  int v58;
  int v59;
  __int16 *v60;

  this->setfontheight_(this->fonth);
  if ( this->bd.tuti <= 12 )
  {
    i = *((_DWORD *)&this->titlew + this->bd.tuti + 760);
    j = *((_DWORD *)&this->titleh + this->bd.tuti + 772);
    Bar(
      i * this->iconw,
      this->faceh + this->menuh + j * this->iconh,
      this->iconw - 1,
      this->iconh - 1,
      this->cred,
      this->transparent);
    Bar(
      i * this->iconw + 1,
      this->menuh + j * this->iconh + this->faceh + 1,
      this->iconw - 3,
      this->iconh - 3,
      this->cred,
      this->transparent);
  }
  switch ( this->bd.tuti )
  {
    case 1:
      Bar(
        4 * this->iconw - 1,
        this->menuh + 15 * this->iconh + this->faceh - 1,
        3 * this->iconw + 1,
        3 * this->iconh + 1,
        this->cblue,
        this->transparent);
      Bar(
        4 * this->iconw - 2,
        this->menuh + 15 * this->iconh + this->faceh - 2,
        3 * (this->iconw + 1),
        3 * (this->iconh + 1),
        this->cblue,
        this->transparent);
      break;
    case 2:
      Bar(
        3 * this->iconw - 1,
        this->menuh + 16 * this->iconh + this->faceh - 1,
        this->iconw + 1,
        this->iconh + 1,
        this->cblue,
        this->transparent);
      Bar(
        3 * this->iconw - 2,
        this->menuh + 16 * this->iconh + this->faceh - 2,
        this->iconw + 3,
        this->iconh + 3,
        this->cblue,
        this->transparent);
      break;
    case 3:
      Bar(
        9 * this->iconw,
        this->menuh + 18 * this->iconh + this->faceh,
        this->iconw - 1,
        2 * this->iconh - 1,
        this->cblue,
        this->transparent);
      Bar(
        9 * this->iconw + 1,
        this->menuh + 18 * this->iconh + this->faceh + 1,
        this->iconw - 3,
        2 * this->iconh - 3,
        this->cblue,
        this->transparent);
      Bar(
        9 * this->iconw - 1,
        this->menuh + 17 * this->iconh + this->faceh - 1,
        this->iconw + 1,
        3 * this->iconh + 1,
        this->cgreen,
        this->transparent);
      Bar(
        9 * this->iconw - 2,
        this->menuh + 17 * this->iconh + this->faceh - 2,
        this->iconw + 3,
        3 * (this->iconh + 1),
        this->cgreen,
        this->transparent);
      break;
    case 4:
      Bar(
        7 * this->iconw - 1,
        this->menuh + 16 * this->iconh + this->faceh - 1,
        3 * this->iconw + 1,
        3 * this->iconh + 1,
        this->cblue,
        this->transparent);
      Bar(
        7 * this->iconw - 2,
        this->menuh + 16 * this->iconh + this->faceh - 2,
        3 * (this->iconw + 1),
        3 * (this->iconh + 1),
        this->cblue,
        this->transparent);
      break;
    case 5:
      Bar(
        9 * this->iconw - 1,
        this->menuh + 19 * this->iconh + this->faceh - 1,
        this->iconw + 1,
        this->iconh + 1,
        this->cgreen,
        this->transparent);
      Bar(
        9 * this->iconw - 2,
        this->menuh + 19 * this->iconh + this->faceh - 2,
        this->iconw + 3,
        this->iconh + 3,
        this->cgreen,
        this->transparent);
      break;
    case 6:
      Bar(
        8 * this->iconw - 1,
        this->menuh + 17 * this->iconh + this->faceh - 1,
        3 * this->iconw + 1,
        3 * this->iconh + 1,
        this->cgreen,
        this->transparent);
      Bar(
        8 * this->iconw - 2,
        this->menuh + 17 * this->iconh + this->faceh - 2,
        3 * (this->iconw + 1),
        3 * (this->iconh + 1),
        this->cgreen,
        this->transparent);
      break;
    case 7:
      Bar(
        9 * this->iconw - 1,
        this->menuh + 17 * this->iconh + this->faceh - 1,
        3 * this->iconw + 1,
        3 * this->iconh + 1,
        this->cgreen,
        this->transparent);
      Bar(
        9 * this->iconw - 2,
        this->menuh + 17 * this->iconh + this->faceh - 2,
        3 * (this->iconw + 1),
        3 * (this->iconh + 1),
        this->cgreen,
        this->transparent);
      break;
    case 8:
      Bar(
        2 * this->iconw,
        this->faceh + this->menuh + 18 * this->iconh,
        this->iconw - 1,
        2 * this->iconh - 1,
        this->cblue,
        this->transparent);
      Bar(
        2 * this->iconw + 1,
        this->menuh + 18 * this->iconh + this->faceh + 1,
        this->iconw - 3,
        2 * this->iconh - 1,
        this->cblue,
        this->transparent);
      Bar(
        2 * this->iconw - 1,
        this->menuh + 17 * this->iconh + this->faceh - 1,
        this->iconw + 1,
        3 * this->iconh + 1,
        this->cgreen,
        this->transparent);
      Bar(
        2 * (this->iconw - 1),
        this->menuh + 17 * this->iconh + this->faceh - 2,
        this->iconw + 3,
        3 * (this->iconh + 1),
        this->cgreen,
        this->transparent);
      break;
    case 0xA:
      Bar(
        2 * this->iconw - 1,
        this->menuh + 16 * this->iconh + this->faceh - 1,
        3 * this->iconw + 1,
        3 * this->iconh + 1,
        this->cgreen,
        this->transparent);
      Bar(
        2 * (this->iconw - 1),
        this->menuh + 16 * this->iconh + this->faceh - 2,
        3 * (this->iconw + 1),
        3 * (this->iconh + 1),
        this->cgreen,
        this->transparent);
      break;
    case 0xB:
      Bar(
        2 * this->iconw - 1,
        this->menuh + 18 * this->iconh + this->faceh - 1,
        3 * this->iconw + 1,
        2 * this->iconh + 1,
        this->cblue,
        this->transparent);
      Bar(
        2 * (this->iconw - 1),
        this->menuh + 18 * this->iconh + this->faceh - 2,
        3 * (this->iconw + 1),
        2 * this->iconh + 3,
        this->cblue,
        this->transparent);
      Bar(
        -1,
        this->menuh + 6 * this->iconh + this->faceh - 1,
        12 * this->iconw + 1,
        2 * this->iconh + 1,
        this->cred,
        this->transparent);
      Bar(
        -2,
        this->menuh + 6 * this->iconh + this->faceh - 2,
        12 * this->iconw + 3,
        2 * this->iconh + 3,
        this->cred,
        this->transparent);
      break;
    case 0xC:
      Bar(
        this->iconw - 1,
        this->menuh + 18 * this->iconh + this->faceh - 1,
        3 * this->iconw + 1,
        2 * this->iconh + 1,
        this->cblue,
        this->transparent);
      Bar(
        this->iconw - 2,
        this->menuh + 18 * this->iconh + this->faceh - 2,
        3 * (this->iconw + 1),
        2 * this->iconh + 3,
        this->cblue,
        this->transparent);
      break;
    case 0xD:
      Bar(
        -1,
        this->menuh + 18 * this->iconh + this->faceh - 1,
        12 * this->iconw + 1,
        2 * this->iconh + 1,
        this->cred,
        this->transparent);
      Bar(
        -2,
        this->menuh + 18 * this->iconh + this->faceh - 2,
        12 * this->iconw + 3,
        2 * this->iconh + 3,
        this->cred,
        this->transparent);
      Bar(0, this->menuh, 4 * this->digtw[0], this->digth[0], this->cred, this->transparent);
      Bar(1, this->menuh + 1, 4 * this->digtw[0] - 2, this->digth[0] - 2, this->cred, this->transparent);
      Bar(
        this->w_ - 2 * this->digtw[0],
        this->menuh,
        2 * this->digtw[0],
        this->digth[0],
        this->cred,
        this->transparent);
      Bar(
        this->w_ - 2 * this->digtw[0] + 1,
        this->menuh + 1,
        2 * (this->digtw[0] - 1),
        this->digth[0] - 2,
        this->cred,
        this->transparent);
      if ( this->bd.tutb <= 1 )
      {
        cbg = this->okh;
        v4 = this->okw;
        v5 = this->menuh + 10 * this->iconh + this->faceh;
        v6 = (12 * this->iconw - this->okw) / 2;
        v7 = GetWin();
        DrawBMP(this->pok, v7, v6, v5, v4, cbg);
        v8 = this->ctbg;
        v9 = this->ctfg;
        w = this->okh;
        y = this->okw;
        v12 = this->menuh + 10 * this->iconh + this->faceh;
        v13 = (12 * this->iconw - this->okw) / 2;
        v14 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_ABOUT_OK);
        this->drawtextxy_(this->pwint, v14, v13, v12, y, w, v9, v8);
      }
      break;
    case 0xE:
      Bar(
        this->w_ - 2 * this->digtw[0],
        this->menuh,
        2 * this->digtw[0],
        this->digth[0],
        this->cred,
        this->transparent);
      Bar(
        this->w_ - 2 * this->digtw[0] + 1,
        this->menuh + 1,
        2 * (this->digtw[0] - 1),
        this->digth[0] - 2,
        this->cred,
        this->transparent);
      Bar(
        -1,
        this->menuh + 7 * this->iconh + this->faceh - 1,
        12 * this->iconw + 1,
        this->iconh + 1,
        this->cred,
        this->transparent);
      Bar(
        -2,
        this->menuh + 7 * this->iconh + this->faceh - 2,
        12 * this->iconw + 3,
        this->iconh + 3,
        this->cred,
        this->transparent);
      if ( this->bd.tutb <= 1 )
      {
        v15 = this->okh;
        v16 = this->okw;
        v17 = this->menuh + 10 * this->iconh + this->faceh;
        v18 = (12 * this->iconw - this->okw) / 2;
        v19 = GetWin();
        DrawBMP(this->pok, v19, v18, v17, v16, v15);
        v20 = this->ctbg;
        v21 = this->ctfg;
        v22 = this->okh;
        v23 = this->okw;
        v24 = this->menuh + 10 * this->iconh + this->faceh;
        v25 = (12 * this->iconw - this->okw) / 2;
        v26 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_ABOUT_OK);
        this->drawtextxy_(this->pwint, v26, v25, v24, v23, v22, v21, v20);
      }
      break;
    default:
      break;
  }
  this->setfontheight_(this->fontsh);
  v27 = this->cbg;
  v28 = this->ctfg;
  v29 = 8 * this->fontsh;
  v30 = 12 * this->iconw;
  v31 = this->menuh + this->faceh;
  v32 = this->bd.st.lan.getlan(this->bd.tuti + this->bd.st.lan.LAN_TUT);
  this->drawtextxy_(this->pwint, v32, 0, v31, v30, v29, v28, v27, 0x10u);
  this->setfontheight_(this->fonth);
  if ( this->bd.tutb == 2 )
  {
    v33 = this->cbg;
    v34 = this->ctfg;
    v35 = 8 * this->fontsh;
    v36 = 12 * this->iconw;
    v37 = this->menuh + this->faceh;
    v38 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_TUT_QUIT);
    this->drawtextxy_(this->pwint, v38, 0, v37, v36, v35, v34, v33);
    v39 = this->okh;
    v40 = 6 * this->iconw - 1;
    v41 = this->menuh + 10 * this->iconh + this->faceh;
    v42 = GetWin();
    DrawBMP(this->pok, v42, 0, v41, v40, v39);
    v43 = this->okh;
    v44 = 6 * this->iconw - 1;
    v45 = this->menuh + 10 * this->iconh + this->faceh;
    v46 = 6 * this->iconw;
    v47 = GetWin();
    DrawBMP(this->pok, v47, v46, v45, v44, v43);
    v48 = this->ctbg;
    v49 = this->ctfg;
    v50 = this->okh;
    v51 = 6 * this->iconw - 1;
    v52 = this->menuh + 10 * this->iconh + this->faceh;
    v53 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_TUT_QUIT + 1);
    this->drawtextxy_(this->pwint, v53, 0, v52, v51, v50, v49, v48);
    v54 = this->ctbg;
    v55 = this->ctfg;
    v56 = this->okh;
    v57 = 6 * this->iconw - 1;
    v58 = this->menuh + 10 * this->iconh + this->faceh;
    v59 = 6 * this->iconw;
    v60 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_TUT_QUIT + 2);
    this->drawtextxy_(this->pwint, v60, v59, v58, v57, v56, v55, v54);
  }
}


// 原始位置：window.cpp:1621；地址：0x0041F3A8
// 调试记录声明：void painttitle(long int load)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::painttitle(int load)
{
  unsigned int c;
  unsigned int hd;
  unsigned int v4;
  unsigned int v5;
  int v6;
  bitmap *v7;
  unsigned int v8;
  unsigned int v9;
  unsigned int v10;
  unsigned int v11;
  int v12;
  __int16 *v13;
  unsigned int v14;
  unsigned int v15;
  unsigned int v16;
  unsigned int v17;
  int v18;
  __int16 *v19;
  unsigned int v20;
  unsigned int v21;
  unsigned int v22;
  unsigned int v23;
  bitmap *v24;
  bitmap *v25;
  unsigned int v26;
  unsigned int v27;
  bitmap *v28;
  unsigned int v29;
  unsigned int v30;
  unsigned int v31;
  bitmap *v32;

  EnterCriticalSection((LPCRITICAL_SECTION)&this->cs);
  painttitlec = (Window *)load;
  Clear(this->cbg);
  Clear(this->pwint, this->transparent_);
  if ( load < 0 )
    this->ptitle_ = LoadBMP("./data/png/title.png");
  c = this->cfg;
  hd = this->titleh;
  v4 = this->titlew;
  v5 = this->fontth;
  v6 = (this->launchw - this->titlew) / 2;
  v7 = GetWin();
  DrawBMP(this->ptitle_, v7, v6, v5, v4, hd, c);
  this->setfontheight_(this->fontfh);
  v8 = this->cbg;
  v9 = this->ctfg;
  v10 = this->fontfh;
  v11 = this->launchw;
  v12 = this->fontth - this->fontfh;
  v13 = this->bd.st.lan.getlan(this->bd.st.lan.LAN_TITLE);
  this->drawtextxy_(this->pwint, v13, 0, v12, v11, v10, v9, v8);
  if ( load >= 0 )
  {
    this->setfontheight_(this->fontfh);
    v14 = this->cbg;
    v15 = this->ctfg;
    v16 = this->fontfh;
    v17 = this->launchw;
    v18 = this->titleh + this->fontth + this->fontfh / -2;
    v19 = this->bd.st.lan.getlan(load);
    this->drawtextxy_(this->pwint, v19, 0, v18, v17, v16, v15, v14);
    this->setfontheight_(this->fonth);
    if ( painttitles )
      this->drawtextxy_(this->pwint, (const char *)painttitles, 0, this->titleh + this->fontth + this->fontfh / 2, this->launchw, this->fontfh, this->ctfg, this->cbg);
  }
  this->setfontheight_(this->fonth);
  if ( this->mult > 1.0 )
  {
    v20 = this->h_;
    v21 = this->w_;
    v22 = this->h_;
    v23 = this->w_;
    v24 = this->pwin;
    v25 = GetWin();
    DrawBMP(v25, v24, 0, 0, v23, v22, 0, 0, v21, v20);
    v26 = (signed __int64)((long double)this->h_ * this->mult);
    v27 = (signed __int64)((long double)this->w_ * this->mult);
    v28 = GetWin();
    DrawBMP(this->pwin, v28, 0, 0, v27, v26);
  }
  v29 = this->transparent_;
  v30 = (signed __int64)((long double)this->h_ * this->mult);
  v31 = (signed __int64)((long double)this->w_ * this->mult);
  v32 = GetWin();
  DrawBMP(this->pwint, v32, 0, 0, v31, v30, v29);
  FreshWin();
  LeaveCriticalSection((LPCRITICAL_SECTION)&this->cs);
}


// 原始位置：window.cpp:1655；地址：0x0041F8C4
// 调试记录声明：void paintevent(bool freshb)
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintevent(bool freshb)
{
  unsigned int hd;
  unsigned int wd;
  unsigned int v4;
  unsigned int v5;
  bitmap *v6;
  bitmap *v7;
  unsigned int v8;
  unsigned int v9;
  bitmap *v10;
  unsigned int v11;
  unsigned int v12;
  unsigned int v13;
  bitmap *v14;

  EnterCriticalSection((LPCRITICAL_SECTION)&this->cs);
  Clear(this->cbg);
  Clear(this->pwint, this->transparent_);
  this->paintmenu();
  if ( this->helpi )
  {
    this->painthelp();
  }
  else
  {
    this->paintface();
    this->paintlevel();
    this->paintboard();
    if ( this->bd.tutb > 0 && !this->bd.pauseb )
      this->painttut();
  }
  if ( this->mult > 1.0 )
  {
    hd = this->h_;
    wd = this->w_;
    v4 = this->h_;
    v5 = this->w_;
    v6 = this->pwin;
    v7 = GetWin();
    DrawBMP(v7, v6, 0, 0, v5, v4, 0, 0, wd, hd);
    v8 = (signed __int64)((long double)this->h_ * this->mult);
    v9 = (signed __int64)((long double)this->w_ * this->mult);
    v10 = GetWin();
    DrawBMP(this->pwin, v10, 0, 0, v9, v8);
  }
  v11 = this->transparent_;
  v12 = (signed __int64)((long double)this->h_ * this->mult);
  v13 = (signed __int64)((long double)this->w_ * this->mult);
  v14 = GetWin();
  DrawBMP(this->pwint, v14, 0, 0, v13, v12, v11);
  if ( freshb )
    FreshWin();
  LeaveCriticalSection((LPCRITICAL_SECTION)&this->cs);
}


// 原始位置：window.cpp:1688；地址：0x0041FB7C
// 调试记录声明：void paintevent()
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintevent()
{
  this->paintevent(1);
}


// 原始位置：window.cpp:1693；地址：0x0041FB9C
// 调试记录声明：void paintrefresh()
// 功能说明：界面绘制函数；具体绘制对象、颜色和坐标见下方调用。
void Window::paintrefresh()
{
  HWND__ *v1;
  HWND__ *v2;

  if ( GetTimeR() > this->timerefresh + 0.1 )
  {
    v1 = GetHwnd();
    InvalidateRect(v1, 0, 0);
    v2 = GetHwnd();
    UpdateWindow(v2);
    this->timerefresh = GetTimeR();
  }
}


// 原始位置：window.cpp:1703；地址：0x0041FC0A
// 调试记录声明：bool isin(long int ex, long int ey, long int x, long int y, long int w, long int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
bool Window::isin(int ex, int ey, int x, int y, int w, int h)
{
  return ex > x && ey > y && x + w > ex && y + h > ey;
}


// 原始位置：window.cpp:1708；地址：0x0041FC4E
// 调试记录声明：void sethelp(long int helpi_)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::sethelp(int helpi_)
{

  this->mi = 0;
  if ( this->helpi != helpi_ || this->helpi )
    this->bd.sd.playsound(this->bd.sd.sLeft);
  if ( this->helpi > 0 && helpi_ > 0 )
    helpi_ = this->helpi;
  if ( this->helpi != helpi_ && helpi_ )
  {
    if ( !this->helpi && this->bd.sit > 0 && !this->bd.pauseb && this->bd.sit <= 3 )
    {
      this->bd.pause();
      this->bd.pauseb = 2;
    }
    this->helpi = helpi_;
  }
  else
  {
    if ( this->bd.pauseb == 2 && this->bd.sit > 0 && this->bd.sit <= 3 )
      this->bd.pause();
    this->helpi = 0;
  }
  this->initwindow(0);
  if ( this->helpi == -2 && this->waitb != 1 )
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)getlead, this, 0, 0);
}


// 原始位置：window.cpp:1746；地址：0x0041FDE0
// 调试记录声明：void savescr()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：char scrpath[260]；time_t rawtime；tm *timed；char times[260]。
void Window::savescr()
{

  char *v2;
  char *v3;
  bitmap *v4;
  char times[260];
  time_t rawtime;
  char scrpath[260];
  tm *timed;

  GetTempPathA(0x104u, scrpath);
  v2 = &scrpath[strlen(scrpath)];
  *(_DWORD *)v2 = 1701995379;
  *((_DWORD *)v2 + 1) = 1752395365;
  *((_DWORD *)v2 + 2) = 6255727;
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
  v3 = &scrpath[strlen(scrpath)];
  *(_DWORD *)v3 = 1735290926;
  v3[4] = 0;
  v4 = GetWin();
  SaveBMP(v4, scrpath);
  this->bd.st.savescr(scrpath);
  this->bd.sd.playsound(this->bd.sd.sSolve);
}


// 原始位置：window.cpp:1764；地址：0x0041FF6A
// 调试记录声明：void switchskin()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::switchskin()
{
  this->switchskin((this->colori + 1) % 6);
}


// 原始位置：window.cpp:1769；地址：0x0041FFAE
// 调试记录声明：void switchskin(long int colori_)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::switchskin(int colori_)
{

  this->colori = colori_;
  this->initbmp();
  this->paintevent();
  this->bd.sd.playsound(this->bd.sd.sRight);
}


// 原始位置：window.cpp:1777；地址：0x0041FFFC
// 调试记录声明：void switchmd()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::switchmd()
{
  unsigned int v1;

  v1 = (unsigned int)((this->md + 1) >> 31) >> 30;
  this->switchmd((((_BYTE)v1 + LOBYTE(this->md) + 1) & 3) - v1);
}


// 原始位置：window.cpp:1782；地址：0x00420038
// 调试记录声明：void switchmd(long int md_)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::switchmd(int md_)
{
  this->md = md_;
  if ( this->md > 1 )
    this->bd.mdb = 0;
  this->bd.sd.playsound(this->bd.sd.sLeft);
}


// 原始位置：window.cpp:1792；地址：0x0042008C
// 调试记录声明：void tutevent(long int ex, long int ey, bool tutkb)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：bool tutmb；bool tutmb_y；bool tutmb_n。
void Window::tutevent(int ex, int ey, bool tutkb)
{

  bool tutmb_n;
  bool tutmb_y;
  bool tutmb;

  tutmb = this->isin(ex, ey, (12 * this->iconw - this->okw) / 2, this->menuh + 10 * this->iconh + this->faceh, this->okw, this->okh);
  if ( this->bd.tutb == 1 && (tutmb || tutkb) )
  {
    if ( this->bd.tuti == 13 )
    {
      ++this->bd.maski;
      ++this->bd.tuti;
      this->bd.sd.playsound(this->bd.sd.sLeft);
    }
    else if ( this->bd.tuti == 14 )
    {
      this->bd.tutb = 0;
      this->bd.time = GetTimeR();
      this->helpb = 0;
      this->sethelp(1);
    }
  }
  tutmb_y = this->isin(ex, ey, 0, this->faceh + this->menuh + 10 * this->iconh, 6 * this->iconw - 1, this->okh);
  tutmb_n = this->isin(ex, ey, 6 * this->iconw, this->menuh + 10 * this->iconh + this->faceh, 6 * this->iconw - 1, this->okh);
  if ( this->bd.tutb == 2 && (tutmb_y || tutmb_n || tutkb) )
  {
    if ( tutmb_y || tutkb )
    {
      this->bd.tutb = 0;
      this->bd.time = GetTimeR();
      this->helpb = 0;
      this->bd.sd.playsound(this->bd.sd.sLeft);
    }
    if ( tutmb_n )
    {
      this->bd.tutb = 1;
      this->bd.sd.playsound(this->bd.sd.sLeft);
    }
  }
}


// 原始位置：window.cpp:1830；地址：0x00420374
// 调试记录声明：void mouseeventboard_(long int x, long int y, long int eb_, long int md_)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：bool tutmb。
void Window::mouseeventboard_(int x, int y, int eb_, int md_)
{
  bool v5;

  v5 = !this->bd.tutb
    || this->bd.tuti <= 12
    && *((_DWORD *)&this->titlew + this->bd.tuti + 760) == x
    && *((_DWORD *)&this->titleh + this->bd.tuti + 772) == y
    && (eb_ & *(&this->launchw + this->bd.tuti + 788)) > 0;
  if ( (this->mx != x || this->my != y) && v5 && this->bd.tutb <= 1 )
  {
    this->bd.mx = x;
    this->bd.my = y;
    if ( eb_ == 1 )
    {
      if ( !this->bd.sit && this->bd.maskj <= y && md_ > 2 )
        this->bd.resetbd(x, y);
      this->bd.clickleft(x, y, 1, md_);
    }
    else if ( eb_ == 2 )
    {
      this->bd.clickright(x, y, 1, md_);
    }
    this->paintevent();
    this->bd.checkline(1);
    this->mx = x;
    this->my = y;
    if ( this->bd.tutb > 0 )
      ++this->bd.tuti;
    this->paintevent();
  }
}


// 原始位置：window.cpp:1861；地址：0x00420566
// 调试记录声明：void mouseeventboard(long int ex_, long int ey_, long int eb_, long int md_)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
// 原始局部变量：long int ex；long int ey；long int x；long int y。
void Window::mouseeventboard(int ex_, int ey_, int eb_, int md_)
{

  int y;
  int x;
  signed int ey;
  signed int ex;

  ex = (signed int)((long double)ex_ / this->mult);
  ey = (signed int)((long double)ey_ / this->mult);
  if ( ex >= 0 && ey - this->menuh >= this->faceh && !this->helpi && this->bd.sit <= 3 && !this->bd.pauseb )
  {
    x = ex / this->iconw;
    y = (ey - this->faceh - this->menuh) / this->iconh;
    if ( x >= 0 && this->bd.w > x && y >= 0 && this->bd.h > y )
      this->mouseeventboard_(x, y, eb_, md_);
    this->tutevent(ex, ey, 0);
  }
}


// 原始位置：window.cpp:1877；地址：0x004206AE
// 调试记录声明：void mouseevent(long int ex_, long int ey_, long int eb_)
// 功能说明：鼠标事件分派；根据按钮、坐标和当前界面状态执行操作。
// 原始局部变量：long int ex；long int ey；double helph__；long int k；long int helpw__；long int j。
void Window::mouseevent(int ex_, int ey_, int eb_)
{
  int v4;
  int v5;

  double helph__;
  int ey;
  int ex;
  signed int j;
  int k;

  ex = (signed int)((long double)ex_ / this->mult);
  ey = (signed int)((long double)ey_ / this->mult);
  if ( this->menuh <= ey )
  {
    if ( this->helpi )
    {
      if ( this->helpi == -1 )
      {
        if ( this->isin(ex, ey, (this->aboutw - this->okw) / 2, this->menuh + (this->okh_ + this->okh) / -2 + this->abouth, this->okw, this->okh) )
        {
          this->sethelp(0);
        }
        if ( this->isin(ex, ey, (this->aboutw - this->fontfh) / 2 + this->fontfh / -2, (this->fontth - this->fontfh) / 2 + this->menuh, this->fontfh, this->fontfh)
          && this->cheatb != 1 )
        {
          this->bd.sd.playsound(this->bd.sd.sSolve);
          this->cheatb = 1;
          this->bd.st.cheatb = 1;
          this->bd.st.addach(this->bd.st.achhidcheat);
        }
        if ( this->isin(ex, ey, (this->aboutw - this->fontfh) / 2 + this->fontfh / 2, (this->fontth - this->fontfh) / 2 + this->menuh, this->fontfh, this->fontfh)
          && this->bd.relaxb != 1 )
        {
          this->bd.sd.playsound(this->bd.sd.sSolve);
          this->bd.relaxb = 1;
          this->bd.st.cheatb = 1;
          this->bd.st.addach(this->bd.st.achhidcheat);
        }
      }
      else if ( this->helpi )
      {
        if ( this->isin(ex, ey, (this->helpw - this->okw) / 2, this->menuh + (this->okh_ + this->okh) / -2 + this->helph, this->okw, this->okh) )
        {
          this->sethelp(0);
        }
        if ( this->isin(ex, ey, -3 * this->btnw + (this->helpw - this->okw) / 2 - this->tutw, (this->okh_ + this->okh) / -2 + this->helph + this->menuh, this->tutw, this->tuth) )
        {
          this->sethelp(0);
          this->bd.initbd(1, this->md);
          this->initwindow(0);
          this->bd.tutb = 1;
        }
        if ( this->helpi > 1
          && this->isin(ex, ey, (this->helpw - this->okw) / 2 - 2 * this->btnw, (this->okh_ + this->okh) / -2 + this->helph + this->menuh, this->btnw, this->btnh) )
        {
          --this->helpi;
          this->bd.sd.playsound(this->bd.sd.sLeft);
        }
        if ( this->helpi > 0
          && this->helpi < this->maxhelp
          && this->isin(ex, ey, this->btnw + (this->helpw + this->okw) / 2, (this->okh_ + this->okh) / -2 + this->helph + this->menuh, this->btnw, this->btnh) )
        {
          ++this->helpi;
          this->bd.sd.playsound(this->bd.sd.sLeft);
          if ( this->helpi == this->maxhelp )
            this->bd.st.addach(this->bd.st.achgenhelp);
        }
        if ( this->helpi == -2 )
        {
          if ( this->isin(ex, ey, ((this->helpw + this->okw) / 2 + this->helpw) / 2
               + ((signed int)(((unsigned int)(-5 * this->facew) >> 31) - 5 * this->facew) >> 1), (this->okh_ + this->okh) / -2 + this->helph + this->menuh, 5 * this->facew, this->faceh) )
          {
            this->lead_5 = (ex
                           - (((this->helpw + this->okw) / 2 + this->helpw) / 2
                            + ((signed int)(((unsigned int)(-5 * this->facew) >> 31) - 5 * this->facew) >> 1)))
                          / this->facew;
            this->bd.sd.playsound(this->bd.sd.sLeft);
          }
          if ( this->isin(ex, ey, -3 * this->btnw + (this->helpw - this->okw) / 2 - this->tutw, (this->okh_ + this->okh) / -2 + this->helph + this->menuh, this->tutw, this->tuth) )
          {
            this->sethelp(0);
            this->bd.initbd(1, this->md);
            this->initwindow(0);
            this->bd.tutb = 1;
          }
        }
        if ( this->helpi == -3 )
        {
          if ( this->isin(ex, ey, -3 * this->btnw + (this->helpw - this->okw) / 2 - this->tutw, (this->okh_ + this->okh) / -2 + this->helph + this->menuh, this->tutw, this->tuth) )
          {
            this->sethelp(0);
            this->bd.initbd(1, this->md);
            this->initwindow(0);
            this->bd.tutb = 1;
          }
          helph__ = (long double)(this->helph - this->okh_ - 2 * this->iconh - this->faceh) / 9.0;
          for ( k = 0; k <= 9; ++k )
          {
            if ( this->isin(ex, ey, this->iconw, (signed int)((long double)k * helph__
                              + (long double)(signed int)this->menuh
                              + (long double)(signed int)this->iconh), this->facew, this->faceh) )
            {
              switch ( k )
              {
                case 0:
                  this->bd.sd.switchsound();
                  break;
                case 1:
                  this->bd.sd.switchmusic();
                  break;
                case 2:
                  this->switchmd();
                  break;
                case 4:
                  if ( this->mult_ )
                    this->mult_ = 0;
                  else
                    this->mult_ = 1;
                  this->initwindow(0);
                  this->bd.sd.playsound(this->bd.sd.sRight);
                  break;
                case 5:
                  this->switchskin();
                  break;
                case 7:
                  this->bd.delayb = this->bd.delayb == 0;
                  this->bd.sd.playsound(this->bd.sd.sLeft);
                  break;
                case 8:
                  this->barb ^= 1u;
                  this->bd.sd.playsound(this->bd.sd.sLeft);
                  break;
                case 9:
                  this->singleb ^= 1u;
                  this->bd.sd.playsound(this->bd.sd.sLeft);
                  break;
                default:
                  break;
              }
            }
            for ( j = 0; j <= 2; ++j )
            {
              if ( this->isin(ex, ey, (j + 1) * (this->helpw / 4), (signed int)((long double)k * helph__
                                + (long double)(signed int)this->menuh
                                + (long double)(signed int)this->iconh), this->facew, this->faceh) )
              {
                switch ( k )
                {
                  case 0:
                    if ( j <= 1 && this->bd.sd.soundb == j )
                      this->bd.sd.switchsound();
                    break;
                  case 1:
                    if ( j <= 1 && this->bd.sd.musicb == j )
                      this->bd.sd.switchmusic();
                    break;
                  case 2:
                    if ( j <= 2 && this->md != j )
                      this->switchmd(j);
                    break;
                  case 3:
                    if ( j <= 2 && this->md != j + 2 )
                      this->switchmd(j + 2);
                    break;
                  case 4:
                    if ( this->mult_ != j )
                    {
                      this->mult_ = j;
                      this->initwindow(0);
                      this->bd.sd.playsound(this->bd.sd.sRight);
                    }
                    break;
                  case 5:
                    if ( j <= 2 && this->colori != j )
                      this->switchskin(j);
                    break;
                  case 6:
                    if ( j <= 2 && this->colori != j + 3 )
                      this->switchskin(j + 3);
                    break;
                  case 7:
                    if ( j <= 1 && this->bd.delayb == j )
                    {
                      this->bd.delayb = this->bd.delayb == 0;
                      this->bd.sd.playsound(this->bd.sd.sLeft);
                    }
                    break;
                  case 8:
                    if ( j <= 1 && this->barb == j )
                    {
                      this->barb ^= 1u;
                      this->bd.sd.playsound(this->bd.sd.sLeft);
                    }
                    break;
                  case 9:
                    if ( j <= 1 && this->singleb != j )
                    {
                      this->singleb ^= 1u;
                      this->bd.sd.playsound(this->bd.sd.sLeft);
                    }
                    break;
                  default:
                    continue;
                }
              }
            }
          }
          if ( this->mult_ > 1 )
          {
            if ( this->isin(ex, ey, this->facew + 3 * (this->helpw / 4), (signed int)(helph__ * 4.0
                              + (long double)(signed int)this->menuh
                              + (long double)(signed int)this->iconh), this->facew, this->faceh) )
            {
              v4 = this->mult_ - 1;
              if ( v4 < 2 )
                v4 = 2;
              this->mult_ = v4;
              this->initwindow(0);
              this->bd.sd.playsound(this->bd.sd.sRight);
            }
            if ( this->isin(ex, ey, 2 * this->facew + 3 * (this->helpw / 4), (signed int)(helph__ * 4.0
                              + (long double)(signed int)this->menuh
                              + (long double)(signed int)this->iconh), this->facew, this->faceh) )
            {
              v5 = this->mult_ + 1;
              if ( v5 > 8 )
                v5 = 8;
              this->mult_ = v5;
              this->initwindow(0);
              this->bd.sd.playsound(this->bd.sd.sRight);
            }
          }
        }
      }
    }
    else if ( ey - this->menuh >= this->faceh )
    {
      if ( this->bd.sit <= 3 && !this->bd.pauseb )
        this->mouseeventboard(ex_, ey_, eb_, this->md + 4);
    }
    else if ( (this->w_ - this->facew) / 2 < ex && (this->w_ + this->facew) / 2 > ex )
    {
      if ( eb_ == 1 )
      {
        if ( this->bd.tutb <= 0 )
        {
          this->bd.initbd();
        }
        else
        {
          this->bd.tutb = 2;
          this->bd.sd.playsound(this->bd.sd.sRight);
        }
      }
      else if ( eb_ == 2 && this->bd.sit > 0 && this->bd.sit <= 3 )
      {
        this->bd.pause();
        this->bd.sd.playsound(this->bd.sd.sSolve);
        this->bd.st.addach(this->bd.st.achgenpause);
      }
    }
  }
  else if ( 3 * this->menuw <= ex )
  {
    if ( this->w_ - 5 * this->menuw < ex )
    {
      switch ( (ex - (this->w_ - 5 * this->menuw)) / this->menuw )
      {
        case 0:
          this->savescr();
          break;
        case 1:
          this->sethelp(-2);
          break;
        case 2:
          this->sethelp(-3);
          break;
        case 3:
          this->sethelp(1);
          break;
        case 4:
          this->sethelp(-1);
          break;
        default:
          break;
      }
    }
  }
  else if ( this->bd.tutb <= 0 )
  {
    this->helpi = 0;
    this->bd.initbd(ex / this->menuw + 1, this->md);
    this->initwindow(0);
  }
  else
  {
    this->bd.tutb = 2;
    this->bd.sd.playsound(this->bd.sd.sRight);
  }
  this->paintevent();
}


// 原始位置：window.cpp:2182；地址：0x00421B48
// 调试记录声明：void keyevent(long int key)
// 功能说明：键盘事件分派；下面的 switch/条件保留原按键值。
void Window::keyevent(int key)
{
  int v2;
  signed int v3;
  int v4;
  int v5;
  int v6;

  switch ( key )
  {
    case 49:
      if ( this->bd.tutb <= 0 )
      {
        this->helpi = 0;
        this->bd.initbd(1, this->md);
        this->initwindow(0);
      }
      else
      {
        this->bd.tutb = 2;
        this->bd.sd.playsound(this->bd.sd.sRight);
      }
      break;
    case 50:
      if ( this->bd.tutb <= 0 )
      {
        this->helpi = 0;
        this->bd.initbd(2, this->md);
        this->initwindow(0);
      }
      else
      {
        this->bd.tutb = 2;
        this->bd.sd.playsound(this->bd.sd.sRight);
      }
      break;
    case 51:
      if ( this->bd.tutb <= 0 )
      {
        this->helpi = 0;
        this->bd.initbd(3, this->md);
        this->initwindow(0);
      }
      else
      {
        this->bd.tutb = 2;
        this->bd.sd.playsound(this->bd.sd.sRight);
      }
      break;
    case 66:
      this->sethelp(-1);
      break;
    case 69:
      this->sethelp(-3);
      break;
    case 71:
      this->switchmd();
      break;
    case 72:
      this->sethelp(1);
      break;
    case 75:
      this->switchskin();
      break;
    case 77:
      this->bd.sd.switchmusic();
      break;
    case 78:
      if ( this->bd.tutb <= 0 )
      {
        this->helpi = 0;
        this->bd.initbd();
        this->initwindow(0);
      }
      else
      {
        this->bd.tutb = 2;
        this->bd.sd.playsound(this->bd.sd.sRight);
      }
      break;
    case 80:
      this->savescr();
      break;
    case 82:
      this->singleb ^= 1u;
      this->bd.sd.playsound(this->bd.sd.sLeft);
      break;
    case 83:
      this->bd.sd.switchsound();
      break;
    case 84:
      this->sethelp(-2);
      break;
    case 112:
      this->sethelp(1);
      break;
    case 113:
      this->sethelp(-1);
      break;
    case 114:
      this->sethelp(-3);
      break;
    case 115:
      this->sethelp(-2);
      break;
    case 116:
      this->bd.sd.switchsound();
      break;
    case 117:
      this->bd.sd.switchmusic();
      break;
    case 118:
      this->switchmd();
      break;
    case 119:
      this->singleb ^= 1u;
      this->bd.sd.playsound(this->bd.sd.sLeft);
      break;
    case 122:
      this->switchskin();
      break;
    case 123:
      this->savescr();
      break;
    default:
      break;
  }
  if ( this->cheatb && key == 67 )
    this->bd.st.resetach();
  if ( this->helpi == -2 && key == 9 )
  {
    this->lead_5 = (this->lead_5 + 1) % 5;
    this->bd.sd.playsound(this->bd.sd.sLeft);
  }
  if ( this->helpi )
  {
    if ( key == 13 || key == 32 || key == 27 || key == 81 )
      this->sethelp(0);
    if ( this->helpi > 0 )
    {
      if ( key == 37 && this->helpi > 1 )
      {
        --this->helpi;
        this->bd.sd.playsound(this->bd.sd.sLeft);
      }
      if ( key == 39 && this->helpi < this->maxhelp )
      {
        ++this->helpi;
        this->bd.sd.playsound(this->bd.sd.sLeft);
        if ( this->helpi == this->maxhelp )
          this->bd.st.addach(this->bd.st.achgenhelp);
      }
    }
  }
  else
  {
    if ( this->bd.mx == -1
      && this->bd.my == -1
      && (key == 65 || key == 68 || key == 87 || key == 83 || key == 188 || key == 190) )
    {
      this->bd.mx = this->bd.w / 2;
      this->bd.my = this->bd.h - 3;
    }
    switch ( key )
    {
      case 27:
        CloseWin();
        break;
      case 32:
        if ( this->bd.sit > 0 && this->bd.sit <= 3 )
        {
          this->bd.pause();
          this->bd.sd.playsound(this->bd.sd.sSolve);
          this->bd.st.addach(this->bd.st.achgenpause);
        }
        break;
      case 33:
        v2 = this->bd.maskj0;
        if ( v2 > this->bd.h - 4 )
          v2 = this->bd.h - 4;
        this->bd.maskj0 = v2;
        v3 = --this->bd.maskj0;
        if ( v3 <= 0 )
          v3 = 1;
        this->bd.maskj0 = v3;
        this->initwindow(1);
        break;
      case 34:
        v4 = ++this->bd.maskj0;
        if ( v4 > this->bd.h - 4 )
          v4 = this->bd.h - 4;
        this->bd.maskj0 = v4;
        this->initwindow(1);
        break;
      case 37:
        --this->bd.w;
        this->initwindow(1);
        break;
      case 38:
        --this->bd.h;
        this->initwindow(1);
        break;
      case 39:
        ++this->bd.w;
        this->initwindow(1);
        break;
      case 40:
        ++this->bd.h;
        this->initwindow(1);
        break;
      case 65:
        --this->bd.mx;
        this->bd.mx &= ~(this->bd.mx >> 31);
        break;
      case 68:
        v5 = ++this->bd.mx;
        if ( v5 > this->bd.w - 1 )
          v5 = this->bd.w - 1;
        this->bd.mx = v5;
        break;
      case 81:
        CloseWin();
        break;
      case 83:
        v6 = ++this->bd.my;
        if ( v6 > this->bd.h - 1 )
          v6 = this->bd.h - 1;
        this->bd.my = v6;
        break;
      case 85:
        if ( !this->bd.tutb )
        {
          this->bd.addline();
          this->bd.sd.playsound(this->bd.sd.sLeft);
          this->paintevent();
          this->bd.checkline(1);
          this->bd.checkdie();
        }
        break;
      case 87:
        --this->bd.my;
        this->bd.my &= ~(this->bd.my >> 31);
        break;
      case 107:
        ++this->bd.n;
        this->initwindow(1);
        break;
      case 109:
        --this->bd.n;
        this->initwindow(1);
        break;
      case 187:
        ++this->bd.n;
        this->initwindow(1);
        break;
      case 188:
        this->mx = -1;
        this->my = -1;
        this->tutevent(0, 0, 1);
        this->mouseeventboard_(this->bd.mx, this->bd.my, 1, this->md + 4);
        break;
      case 189:
        --this->bd.n;
        this->initwindow(1);
        break;
      case 190:
        this->mx = -1;
        this->my = -1;
        this->tutevent(0, 0, 1);
        this->mouseeventboard_(this->bd.mx, this->bd.my, 2, this->md + 4);
        break;
      default:
        break;
    }
    if ( this->cheatb )
    {
      switch ( key )
      {
        case 48:
          this->bd.delline(this->bd.h - 1);
          break;
        case 52:
          this->bd.solve1();
          break;
        case 53:
          this->bd.solve2();
          break;
        case 54:
          this->bd.solve1_();
          break;
        case 55:
          this->bd.solve2_();
          break;
        case 56:
          this->bd.solve3_();
          break;
        case 57:
          this->bd.solveblank_();
          break;
        case 86:
          ++this->bd.level;
          break;
        default:
          break;
      }
      if ( key > 51 || key <= 48 )
      {
        this->paintevent();
        this->bd.checkline(1);
      }
    }
  }
  this->paintevent();
}


// 原始位置：window.cpp:2486；地址：0x004227C6
// 调试记录声明：void doaction()
// 功能说明：动作编号分派；数字动作编号没有擅自替换成未经验证的枚举。
void Window::doaction()
{
  int v1;
  int v2;
  int v3;
  int v4;
  bool v5;
  int v6;
  int v7;
  int v8;
  int v9;
  int v10;
  int v11;
  int v12;
  bool v13;
  HWND__ *v14;
  HWND__ *v15;
  bool v16;
  HWND__ *v17;

  while ( (unsigned __int8)IsNextMsg() )
  {
    if ( !this->bd.delayb__ )
    {
      this->ml = GetAsyncKeyState(1) != 0;
      this->mr = GetAsyncKeyState(2) != 0;
      if ( IsMouseLeft() )
      {
        this->mi = 1;
        this->mx = -1;
        this->my = -1;
        v1 = GetMousePosY();
        v2 = GetMousePosX();
        this->mouseevent(v2, v1, 1);
      }
      if ( IsMouseRight() )
      {
        this->mi = 1;
        this->mx = -1;
        this->my = -1;
        v3 = GetMousePosY();
        v4 = GetMousePosX();
        this->mouseevent(v4, v3, 2);
      }
      v5 = IsMouseMove() && this->md > 1 && !this->bd.tutb && this->mi;
      if ( v5 )
      {
        if ( this->ml )
        {
          v6 = this->md;
          v7 = GetMousePosY();
          v8 = GetMousePosX();
          this->mouseeventboard(v8, v7, 1, v6);
        }
        if ( this->mr )
        {
          v9 = this->md;
          v10 = GetMousePosY();
          v11 = GetMousePosX();
          this->mouseeventboard(v11, v10, 2, v9);
        }
      }
      if ( IsKey() )
      {
        v12 = GetKey();
        this->keyevent(v12);
      }
      v13 = IsMsg(0xFu) || IsMsg(0xA1u) || IsMsg(0x112u);
      if ( v13 )
      {
        v14 = GetHwnd();
        this->showmax = IsZoomed(v14) != 0;
        v15 = GetHwnd();
        v16 = !IsIconic(v15)
           && (this->showmax != this->showmax_
            || (fabs((double)((long double)this->w_ * this->mult) - (double)GetWidth()) > 1.0
             || fabs((double)((long double)this->h_ * this->mult) - (double)GetHeight()) > 1.0)
            && IsMsg(0xA1u));
        if ( v16 )
        {
          v17 = GetHwnd();
          ShowWindow(v17, 9);
          this->mult_ = this->showmax;
          this->initwindow(0);
          this->bd.sd.playsound(this->bd.sd.sRight);
          this->showmax = 0;
          this->showmax_ = this->showmax;
        }
        this->paintevent();
      }
    }
  }
  this->bd.delayb__ = 0;
}


// 原始位置：window.cpp:2546；地址：0x00422BA8
// 调试记录声明：void setfontname_(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::setfontname_(const char *s)
{

  SetFontName(s);
  SetFont(this->pwint);
}


// 原始位置：window.cpp:2552；地址：0x00422BD2
// 调试记录声明：void setfontheight_(long unsigned int h)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::setfontheight_(unsigned int h)
{

  SetFontHeight((signed __int64)((double)h * this->mult));
  SetFont(this->pwint);
}


// 原始位置：window.cpp:2558；地址：0x00422C38
// 调试记录声明：void setfontweight_(long unsigned int wg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::setfontweight_(unsigned int wg)
{

  SetFontWeight(wg);
  SetFont(this->pwint);
}


// 原始位置：window.cpp:2564；地址：0x00422C62
// 调试记录声明：void drawtextxy_(pbitmap b, const short int *s, long int x, long int y, long unsigned int w, long unsigned int h, long unsigned int cfg, long unsigned int cbg, long unsigned int format)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::drawtextxy_(pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int format)
{
  signed __int64 v10;

  v10 = __PAIR__((signed __int64)((double)h * this->mult), (unsigned int)(signed __int64)((double)w * this->mult));
  DrawTextXY(
    b,
    s,
    (signed int)((long double)x * this->mult),
    (signed int)((long double)y * this->mult),
    v10,
    HIDWORD(v10),
    cfg,
    cbg,
    format);
}


// 原始位置：window.cpp:2569；地址：0x00422D56
// 调试记录声明：void drawtextxy_(pbitmap b, const short int *s, long int x, long int y, long unsigned int w, long unsigned int h, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::drawtextxy_(pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  signed __int64 v9;

  v9 = __PAIR__((signed __int64)((double)h * this->mult), (unsigned int)(signed __int64)((double)w * this->mult));
  DrawTextXY(
    b,
    s,
    (signed int)((long double)x * this->mult),
    (signed int)((long double)y * this->mult),
    v9,
    HIDWORD(v9),
    cfg,
    cbg);
}


// 原始位置：window.cpp:2574；地址：0x00422E42
// 调试记录声明：void drawtextxy_(pbitmap b, const char *s, long int x, long int y, long unsigned int w, long unsigned int h, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::drawtextxy_(pbitmap b, const char *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  signed __int64 v9;

  v9 = __PAIR__((signed __int64)((double)h * this->mult), (unsigned int)(signed __int64)((double)w * this->mult));
  DrawTextXY(
    b,
    s,
    (signed int)((long double)x * this->mult),
    (signed int)((long double)y * this->mult),
    v9,
    HIDWORD(v9),
    cfg,
    cbg);
}


// 原始位置：window.cpp:2579；地址：0x00422F2E
// 调试记录声明：void drawtextxy_(pbitmap b, const char *s, long int x, long int y, long unsigned int cfg, long unsigned int cbg)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Window::drawtextxy_(pbitmap b, const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(b, s, (signed int)((long double)x * this->mult), (signed int)((long double)y * this->mult), cfg, cbg);
}


// 原始位置：window.cpp:2584；地址：0x00422FA6
// 调试记录声明：long unsigned int getstringwidth_(const char *s)
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
unsigned int Window::getstringwidth_(const char *s)
{
  return (signed __int64)((double)GetStringWidth(s) / this->mult);
}

