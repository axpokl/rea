
// Address: 0x00401000; symbol: TopLevelExceptionFilter
LONG __stdcall TopLevelExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
  DWORD v1; // eax
  void (__cdecl *v2)(int); // eax
  LONG result; // eax
  void (__cdecl *v4)(int); // eax
  void (__cdecl *v5)(int); // eax

  v1 = ExceptionInfo->ExceptionRecord->ExceptionCode;
  if ( v1 > 0xC0000091 )
  {
    if ( v1 == -1073741676 )
    {
      v4 = signal(8, 0);
      if ( v4 == (void (__cdecl *)(int))1 )
      {
        signal(8, (void (__cdecl *)(int))1);
        return -1;
      }
LABEL_12:
      if ( !v4 )
        return 0;
      v4(8);
      return -1;
    }
    if ( v1 == -1073741674 )
    {
LABEL_17:
      v5 = signal(4, 0);
      if ( v5 == (void (__cdecl *)(int))1 )
      {
        signal(4, (void (__cdecl *)(int))1);
        result = -1;
      }
      else
      {
        if ( !v5 )
          return 0;
        v5(4);
        result = -1;
      }
      return result;
    }
    if ( v1 != -1073741677 )
      return 0;
LABEL_11:
    v4 = signal(8, 0);
    if ( v4 == (void (__cdecl *)(int))1 )
    {
      signal(8, (void (__cdecl *)(int))1);
      fesetenv(0);
      return -1;
    }
    goto LABEL_12;
  }
  if ( v1 >= 0xC000008D )
    goto LABEL_11;
  if ( v1 != -1073741819 )
  {
    if ( v1 != -1073741795 )
      return 0;
    goto LABEL_17;
  }
  v2 = signal(11, 0);
  if ( v2 == (void (__cdecl *)(int))1 )
  {
    signal(11, (void (__cdecl *)(int))1);
    result = -1;
  }
  else
  {
    if ( !v2 )
      return 0;
    v2(11);
    result = -1;
  }
  return result;
}


// Address: 0x004011B0; symbol: sub_4011B0
void __noreturn sub_4011B0()
{
  int v0; // ST08_4
  int v1; // ebx

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
  v0 = *(_DWORD *)__p__environ();
  v1 = main_0(_argc);
  _cexit();
  ExitProcess(v1);
}


// Address: 0x004012A0; symbol: __mingw32_init_mainargs
int _mingw32_init_mainargs()
{
  char v1; // [esp+28h] [ebp-14h]
  int v2; // [esp+2Ch] [ebp-10h]

  v2 = 0;
  return __getmainargs((int)&_argc, (int)&_argv, (int)&v1, _CRT_glob & 1, (int)&v2);
}


// Address: 0x004012E0; symbol: _mainCRTStartup
void __noreturn mainCRTStartup()
{
  ___set_app_type(1);
  sub_4011B0();
}


// Address: 0x00401300; symbol: _WinMainCRTStartup
void __noreturn WinMainCRTStartup()
{
  ___set_app_type(2);
  sub_4011B0();
}


// Address: 0x00401320; symbol: _atexit
int __cdecl atexit(void (__cdecl *a1)())
{
  return _atexit(a1);
}


// Address: 0x00401330; symbol: __onexit
_onexit_t __cdecl _onexit(_onexit_t a1)
{
  return __onexit(a1);
}


// Address: 0x00401340; symbol: ___gcc_register_frame
int __gcc_register_frame()
{
  HMODULE v0; // eax
  HINSTANCE__ *v1; // ebx
  FARPROC v2; // esi
  HINSTANCE__ *v3; // eax
  FARPROC v4; // edx

  v0 = GetModuleHandleA("libgcc_s_dw2-1.dll");
  if ( v0 )
  {
    v1 = v0;
    hmod_libgcc = LoadLibraryA("libgcc_s_dw2-1.dll");
    v2 = GetProcAddress(v1, "__register_frame_info");
    _data_start__ = (int (__cdecl *)(_DWORD))GetProcAddress(v1, "__deregister_frame_info");
  }
  else
  {
    _data_start__ = 0;
    v2 = 0;
  }
  if ( v2 )
    ((void (__cdecl *)(void *, void *))v2)(&__EH_FRAME_BEGIN__, &obj);
  if ( __JCR_END__ )
  {
    v3 = GetModuleHandleA("libgcj-16.dll");
    v4 = 0;
    if ( v3 )
      v4 = GetProcAddress(v3, "_Jv_RegisterClasses");
    if ( v4 )
      ((void (__cdecl *)(int *))v4)(&__JCR_END__);
  }
  return atexit(__gcc_deregister_frame);
}


// Address: 0x00401430; symbol: ___gcc_deregister_frame
void __cdecl __gcc_deregister_frame()
{
  if ( _data_start__ )
    _data_start__(&__EH_FRAME_BEGIN__);
  if ( hmod_libgcc )
    FreeLibrary(hmod_libgcc);
}


// Address: 0x00401460; symbol: __ZN5BlockC1Ev
void __thiscall Block::Block(Block *const this)
{
  Block *v1; // ST1C_4

  v1 = this;
  this->w = 0;
  this->h = 0;
  this->n = 0;
  this->sit = 0;
  this->pauseb = 0;
  this->maskj = 0;
  this->maski = 0;
  this->flag = (bool (*)[128])calloc(0x80u, 0x80u);
  v1->qstn = (bool (*)[128])calloc(0x80u, 0x80u);
  v1->mine = (bool (*)[128])calloc(0x80u, 0x80u);
  v1->blck = (bool (*)[128])calloc(0x80u, 0x80u);
  v1->mask = (bool (*)[128])calloc(0x80u, 0x80u);
  v1->leftrule = (bool (*)[128])calloc(0x80u, 0x80u);
  v1->rightrule = (bool (*)[128])calloc(0x80u, 0x80u);
  v1->numb = (int (*)[128])calloc(0x80u, 0x200u);
  Block::initbl(v1);
}


// Address: 0x0040159C; symbol: __ZN5Block6initblEv
void __thiscall Block::initbl(Block *const this)
{
  int j; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]

  this->w = 3;
  this->h = 5;
  for ( i = 0; this->w > i; ++i )
  {
    for ( j = 0; this->h > j; ++j )
    {
      this->mine[i][j] = 0;
      this->flag[i][j] = 0;
      this->qstn[i][j] = 0;
      this->blck[i][j] = 0;
      this->mask[i][j] = 0;
      this->numb[i][j] = 0;
    }
  }
  *(_BYTE *)this->mine = 1;
  (*this->mine)[1] = 1;
  (*this->mine)[129] = 1;
  (*this->mine)[4] = 1;
  (*this->mine)[132] = 1;
  (*this->blck)[256] = 1;
  (*this->blck)[257] = 1;
  (*this->blck)[130] = 1;
  (*this->blck)[258] = 1;
  (*this->blck)[131] = 1;
  (*this->blck)[259] = 1;
  Block::calcnumb(this);
}


// Address: 0x00401714; symbol: __ZN5Block8calcnumbEv
void __thiscall Block::calcnumb(Block *const this)
{
  Block *thisa; // [esp+2Ch] [ebp-1Ch]
  signed int k; // [esp+34h] [ebp-14h]
  int j; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]

  thisa = this;
  for ( i = 0; thisa->w > i; ++i )
  {
    for ( j = 0; thisa->h > j; ++j )
    {
      thisa->numb[i][j] = 0;
      for ( k = 0; k <= 7; ++k )
      {
        if ( Block::isok(thisa, k, i, j, &thisa->tx, &thisa->ty) )
        {
          if ( thisa->mine[thisa->tx][thisa->ty] )
            ++thisa->numb[i][j];
        }
      }
    }
  }
}


// Address: 0x00401800; symbol: __ZN5Block4isokElllRlS0_
bool __thiscall Block::isok(Block *const this, int k, int x, int y, int *const tx, int *const ty)
{
  bool result; // al

  switch ( k )
  {
    case 0:
      *tx = x - 1;
      *ty = y;
      result = x > 0;
      break;
    case 1:
      *tx = x + 1;
      *ty = y;
      result = this->w - 1 > x;
      break;
    case 2:
      *tx = x;
      *ty = y - 1;
      result = y > 0;
      break;
    case 3:
      *tx = x;
      *ty = y + 1;
      result = this->h - 1 > y;
      break;
    case 4:
      *tx = x - 1;
      *ty = y - 1;
      result = x > 0 && y > 0;
      break;
    case 5:
      *tx = x - 1;
      *ty = y + 1;
      result = x > 0 && this->h - 1 > y;
      break;
    case 6:
      *tx = x + 1;
      *ty = y - 1;
      result = this->w - 1 > x && y > 0;
      break;
    case 7:
      *tx = x + 1;
      *ty = y + 1;
      result = this->w - 1 > x && this->h - 1 > y;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// Address: 0x004019A0; symbol: __ZN5BoardC1Ev
void __thiscall Board::Board(Board *const this)
{
  Board *v1; // ST1C_4
  time_t v2; // ebx
  clock_t v3; // eax

  v1 = this;
  Block::Block(&this->0);
  Steam::Steam(&v1->st);
  Sound::Sound(&v1->sd);
  v1->mode = 0;
  v1->mode_ = 0;
  v1->rightb = 0;
  v1->aliveb = 0;
  v1->delayb = 1;
  v1->delayb__ = 0;
  v1->mdb_ = 0;
  v1->tutb = 1;
  v1->tutx[0] = 5;
  v1->tutx[1] = 5;
  v1->tutx[2] = 4;
  v1->tutx[3] = 9;
  v1->tutx[4] = 8;
  v1->tutx[5] = 8;
  v1->tutx[6] = 9;
  v1->tutx[7] = 10;
  v1->tutx[8] = 2;
  v1->tutx[9] = 2;
  v1->tutx[10] = 3;
  v1->tutx[11] = 3;
  v1->tutx[12] = 2;
  v1->tuty[0] = 16;
  v1->tuty[1] = 17;
  v1->tuty[2] = 17;
  v1->tuty[3] = 17;
  v1->tuty[4] = 17;
  v1->tuty[5] = 18;
  v1->tuty[6] = 18;
  v1->tuty[7] = 18;
  v1->tuty[8] = 17;
  v1->tuty[9] = 16;
  v1->tuty[10] = 17;
  v1->tuty[11] = 19;
  v1->tuty[12] = 19;
  v1->tutm[0] = 1;
  v1->tutm[1] = 1;
  v1->tutm[2] = 3;
  v1->tutm[3] = 2;
  v1->tutm[4] = 3;
  v1->tutm[5] = 3;
  v1->tutm[6] = 3;
  v1->tutm[7] = 3;
  v1->tutm[8] = 1;
  v1->tutm[9] = 2;
  v1->tutm[10] = 3;
  v1->tutm[11] = 3;
  v1->tutm[12] = 3;
  v1->relaxb = 0;
  v1->rulemain = 0;
  v1->blckrule = 0;
  v1->rulemain = (Board::rule *)calloc(0x4000u, 0x50u);
  v1->blckrule = (int (*)[128])calloc(0x80u, 0x200u);
  v2 = time(0);
  v3 = clock();
  srand(v2 + v3);
}


// Address: 0x00401CB6; symbol: __ZN5Board6initbdEv
void __thiscall Board::initbd(Board *const this)
{
  signed int v1; // edx
  signed int v2; // eax
  signed int v3; // edx
  signed int v4; // eax
  int v5; // eax
  int v6; // eax
  Board *thisa; // [esp+1Ch] [ebp-2Ch]
  int mode__[4]; // [esp+28h] [ebp-20h]
  int j; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]

  thisa = this;
  Steam::setlead(&this->st, this->mode);
  thisa->sit = 0;
  thisa->line = 0;
  thisa->level = 0;
  thisa->tetrisi = 0;
  thisa->missi = 0;
  thisa->missline = 0;
  thisa->sum = 0;
  if ( thisa->maxbdw > 128 )
    v1 = 128;
  else
    v1 = thisa->maxbdw;
  v2 = thisa->w;
  if ( thisa->w < 12 )
    v2 = 12;
  if ( v1 > v2 )
    v1 = v2;
  thisa->w = v1;
  if ( thisa->maxbdh > 128 )
    v3 = 128;
  else
    v3 = thisa->maxbdh;
  v4 = thisa->h;
  if ( v4 < 8 )
    v4 = 8;
  if ( v3 > v4 )
    v3 = v4;
  thisa->h = v3;
  v5 = thisa->w - 1;
  if ( v5 > thisa->n )
    v5 = thisa->n;
  if ( v5 <= 0 )
    v5 = 1;
  thisa->n = v5;
  v6 = thisa->maskj0;
  if ( v6 > thisa->h - 4 )
    v6 = thisa->h - 4;
  thisa->maskj = v6;
  if ( thisa->relaxb )
    thisa->maskj = 1;
  thisa->maski = 0;
  thisa->maskjb = 0;
  for ( i = 0; thisa->w > i; ++i )
  {
    for ( j = 0; thisa->h > j; ++j )
    {
      thisa->mine[i][j] = thisa->n > i;
      thisa->flag[i][j] = 0;
      thisa->leftrule[i][j] = 0;
      thisa->rightrule[i][j] = 0;
      thisa->qstn[i][j] = 0;
      thisa->blck[i][j] = 0;
      thisa->mask[i][j] = thisa->maskj > j;
      thisa->numb[i][j] = 0;
    }
  }
  Sound::playsound(&thisa->sd, thisa->sd.sNew);
  mode__[0] = 0;
  mode__[1] = 1;
  mode__[2] = 2;
  mode__[3] = 4;
  thisa->mode_ |= mode__[thisa->mode];
  if ( !thisa->mode )
    Steam::addach(&thisa->st, thisa->st.achgencustom);
  if ( thisa->mode_ == 7 )
    Steam::addach(&thisa->st, thisa->st.achgenmode);
  thisa->rightb = 0;
  thisa->tuti = 0;
  thisa->tutb = 0;
  thisa->checkr = 0;
  thisa->pauseb = 0;
  thisa->mx = -1;
  thisa->my = -1;
  thisa->bouns = 0;
  thisa->solven = 0;
}


// Address: 0x00402048; symbol: __ZN5Board6initbdEllll
void __thiscall Board::initbd(Board *const this, int w_, int h_, int maskj_, int n_)
{
  this->w = w_;
  this->h = h_;
  this->n = n_;
  this->maskj0 = maskj_;
  Board::initbd(this);
}


// Address: 0x00402086; symbol: __ZN5Board6initbdEll
void __thiscall Board::initbd(Board *const this, int mode_, int md_)
{
  int v3; // eax
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  Steam::setlead(&this->st, this->mode);
  thisa->mode = mode_;
  v3 = thisa->mode;
  switch ( v3 )
  {
    case 2:
      Board::initbd(thisa, 16, 24, 8, 3);
      break;
    case 3:
      Board::initbd(thisa, 32, 32, 8, 6);
      break;
    case 1:
      Board::initbd(thisa, 12, 20, 8, 2);
      break;
  }
  thisa->mdb = md_ <= 1;
}


// Address: 0x00402174; symbol: __ZN5Board8randmineEll
void __thiscall Board::randmine(Board *const this, int x, int y)
{
  bool mb; // ST17_1
  bool mb_0; // ST16_1
  Board *thisa; // [esp+Ch] [ebp-2Ch]
  int i_1; // [esp+18h] [ebp-20h]
  int i_0; // [esp+1Ch] [ebp-1Ch]
  int j_0; // [esp+20h] [ebp-18h]
  int k; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  int j; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  for ( j = 0; thisa->h > j; ++j )
  {
    for ( i = 0; thisa->w > i; ++i )
    {
      thisa->rx = rand() % thisa->w;
      thisa->ry = j;
      mb = thisa->mine[thisa->rx][thisa->ry];
      thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i][j];
      thisa->mine[i][j] = mb;
    }
  }
  for ( k = 0; thisa->n > k; ++k )
  {
    for ( j_0 = y - 1; y + 1 >= j_0; ++j_0 )
    {
      for ( i_0 = x - 1; x + 1 >= i_0; ++i_0 )
      {
        if ( j_0 >= 0 && i_0 >= 0 && thisa->h > j_0 && thisa->w > i_0 && thisa->mine[i_0][j_0] )
        {
          thisa->rx = rand() % thisa->w;
          thisa->ry = j_0;
          mb_0 = thisa->mine[thisa->rx][thisa->ry];
          thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i_0][j_0];
          thisa->mine[i_0][j_0] = mb_0;
        }
      }
    }
  }
  thisa->rx = x;
  thisa->ry = y;
  if ( thisa->mine[x][y] )
  {
    for ( i_1 = 0; thisa->w > i_1; ++i_1 )
    {
      if ( thisa->mine[i_1][y] != 1 )
      {
        thisa->rx = i_1;
        thisa->ry = y;
      }
    }
    thisa->mine[thisa->rx][thisa->ry] = 1;
    thisa->mine[x][y] = 0;
  }
}


// Address: 0x00402468; symbol: __ZN5Board7tutmineEv
void __thiscall Board::tutmine(Board *const this)
{
  Board *thisa; // [esp+Ch] [ebp-4Ch]
  int rx1_[5]; // [esp+18h] [ebp-40h]
  int rx0_[5]; // [esp+2Ch] [ebp-2Ch]
  bool mb_0; // [esp+42h] [ebp-16h]
  bool mb; // [esp+43h] [ebp-15h]
  int i; // [esp+44h] [ebp-14h]
  int i_0; // [esp+48h] [ebp-10h]
  int j; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  rx0_[0] = 8;
  rx0_[1] = 10;
  rx0_[2] = 1;
  rx0_[3] = 0;
  rx0_[4] = 0;
  rx1_[0] = 5;
  rx1_[1] = 3;
  rx1_[2] = 9;
  rx1_[3] = 2;
  rx1_[4] = 9;
  for ( j = 0; thisa->h > j; ++j )
  {
    if ( thisa->h - 5 > j )
    {
      for ( i_0 = 0; thisa->w > i_0; ++i_0 )
      {
        thisa->rx = rand() % thisa->w;
        thisa->ry = j;
        mb_0 = thisa->mine[thisa->rx][thisa->ry];
        thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i_0][j];
        thisa->mine[i_0][j] = mb_0;
      }
    }
    else
    {
      i = 1;
      thisa->rx = rx1_[j - thisa->h + 5];
      thisa->ry = j;
      mb = thisa->mine[thisa->rx][thisa->ry];
      thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i][j];
      thisa->mine[i][j] = mb;
      i = 0;
      thisa->rx = rx0_[j - thisa->h + 5];
      thisa->ry = j;
      mb = thisa->mine[thisa->rx][thisa->ry];
      thisa->mine[thisa->rx][thisa->ry] = thisa->mine[i][j];
      thisa->mine[i][j] = mb;
    }
  }
}


// Address: 0x004026F6; symbol: __ZN5Board7resetbdEll
void __thiscall Board::resetbd(Board *const this, int x, int y)
{
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  if ( this->tutb == 1 )
    Board::tutmine(this);
  else
    Board::randmine(this, x, y);
  Block::calcnumb(&thisa->0);
  thisa->time = GetTimeR();
  thisa->time_ = thisa->time;
  thisa->sit = 1;
  Steam::addach(&thisa->st, thisa->st.achgenstart);
}


// Address: 0x00402788; symbol: __ZN5Board10solveblankEv
void __thiscall Board::solveblank(Board *const this)
{
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j_0; // [esp+20h] [ebp-18h]
  int i_0; // [esp+24h] [ebp-14h]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  this->solvebb = 0;
  if ( this->sit > 0 && this->sit <= 3 && !this->pauseb )
  {
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = 2; thisa->h > j; ++j )
      {
        if ( thisa->mask[i][j] != 1 && thisa->mine[i][j] != 1 && !thisa->numb[i][j] )
          Board::clickleft(thisa, i, j, 0);
      }
    }
    for ( i_0 = thisa->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = thisa->h - 1; j_0 > 1; --j_0 )
      {
        if ( thisa->mask[i_0][j_0] != 1 && thisa->mine[i_0][j_0] != 1 && !thisa->numb[i_0][j_0] )
          Board::clickleft(thisa, i_0, j_0, 0);
      }
    }
  }
}


// Address: 0x00402920; symbol: __ZN5Board11solveblank_Ev
void __thiscall Board::solveblank_(Board *const this)
{
  Board *thisa; // [esp+Ch] [ebp-Ch]

  thisa = this;
  this->solvebb = 1;
  while ( thisa->solvebb )
    Board::solveblank(thisa);
}


// Address: 0x00402950; symbol: __ZN5Board6solve0Ev
void __thiscall Board::solve0(Board *const this)
{
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j_0; // [esp+20h] [ebp-18h]
  int i_0; // [esp+24h] [ebp-14h]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  this->solveb0 = 0;
  if ( this->sit <= 3 && !this->pauseb )
  {
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = 2; thisa->h > j; ++j )
      {
        if ( thisa->blck[i][j] )
        {
          if ( !thisa->numb[i][j] )
            Board::clicknumb(thisa, i, j, 0);
        }
      }
    }
    for ( i_0 = thisa->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = thisa->h - 1; j_0 > 1; --j_0 )
      {
        if ( thisa->blck[i_0][j_0] && !thisa->numb[i_0][j_0] )
          Board::clicknumb(thisa, i_0, j_0, 0);
      }
    }
  }
}


// Address: 0x00402A8A; symbol: __ZN5Board7solve0_Ev
void __thiscall Board::solve0_(Board *const this)
{
  Board *thisa; // [esp+Ch] [ebp-Ch]

  thisa = this;
  this->solveb0 = 1;
  while ( thisa->solveb0 )
    Board::solve0(thisa);
}


// Address: 0x00402ABA; symbol: __ZN5Board6solve1Ev
void __thiscall Board::solve1(Board *const this)
{
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j_0; // [esp+20h] [ebp-18h]
  int i_0; // [esp+24h] [ebp-14h]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  this->solveb1 = 0;
  if ( this->sit <= 3 && !this->pauseb )
  {
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = 2; thisa->h > j; ++j )
      {
        if ( thisa->blck[i][j] )
        {
          if ( thisa->numb[i][j] >= 0 )
            Board::clicknumb(thisa, i, j, 0);
        }
      }
    }
    for ( i_0 = thisa->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = thisa->h - 1; j_0 > 1; --j_0 )
      {
        if ( thisa->blck[i_0][j_0] && thisa->numb[i_0][j_0] >= 0 )
          Board::clicknumb(thisa, i_0, j_0, 0);
      }
    }
    Sound::playsound(&thisa->sd, thisa->sd.sSolve);
  }
}


// Address: 0x00402C12; symbol: __ZN5Board7solve1_Ev
void __thiscall Board::solve1_(Board *const this)
{
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  this->solveb1 = 1;
  while ( thisa->solveb1 )
  {
    Board::checkline(thisa, 0);
    Board::solve1(thisa);
  }
}


// Address: 0x00402C56; symbol: __ZN5Board10createruleEv
void __thiscall Board::createrule(Board *const this)
{
  Board *thisa; // [esp+2Ch] [ebp-2Ch]
  signed int k; // [esp+34h] [ebp-24h]
  int j; // [esp+38h] [ebp-20h]
  int i; // [esp+3Ch] [ebp-1Ch]

  thisa = this;
  for ( i = 0; thisa->w > i; ++i )
  {
    for ( j = 0; thisa->h > j; ++j )
    {
      thisa->blckrule[i][j] = -1;
      if ( thisa->blck[i][j] )
      {
        thisa->ruletemp.x = i;
        thisa->ruletemp.y = j;
        thisa->ruletemp.numbc = thisa->numb[i][j];
        thisa->ruletemp.blckc = 0;
        for ( k = 0; k <= 7; ++k )
        {
          if ( Block::isok(&thisa->0, k, i, j, &thisa->tx, &thisa->ty) )
          {
            if ( thisa->flag[thisa->tx][thisa->ty] || thisa->rightrule[thisa->tx][thisa->ty] )
            {
              --thisa->ruletemp.numbc;
            }
            else if ( thisa->blck[thisa->tx][thisa->ty] != 1 )
            {
              *(&thisa->n + thisa->ruletemp.blckc + 612) = thisa->tx;
              *(&thisa->n + thisa->ruletemp.blckc++ + 620) = thisa->ty;
            }
          }
        }
        thisa->blckrule[i][j] = thisa->rulemainc;
        qmemcpy(&thisa->rulemain[thisa->rulemainc++], &thisa->ruletemp, sizeof(thisa->rulemain[thisa->rulemainc++]));
      }
    }
  }
}


// Address: 0x00402EAC; symbol: __ZN5Board11compareruleEll
void __thiscall Board::comparerule(Board *const this, int rule1c, int rule2c)
{
  Board::rule rule2; // [esp+4h] [ebp-BCh]
  Board::rule rule1; // [esp+54h] [ebp-6Ch]
  int rule2k_0; // [esp+A4h] [ebp-1Ch]
  int rule1k_0; // [esp+A8h] [ebp-18h]
  int rule2k; // [esp+ACh] [ebp-14h]
  int rule1k; // [esp+B0h] [ebp-10h]

  qmemcpy(&rule1, &this->rulemain[rule1c], sizeof(rule1));
  qmemcpy(&rule2, &this->rulemain[rule2c], sizeof(rule2));
  for ( rule1k = 0; this->rulemain[rule1c].blckc > rule1k; ++rule1k )
  {
    for ( rule2k = 0; this->rulemain[rule2c].blckc > rule2k; ++rule2k )
    {
      if ( *(&rule1.x + rule1k + 4) >= 0
        && *(&rule1.x + rule1k + 12) >= 0
        && *(&rule2.x + rule2k + 4) >= 0
        && *(&rule2.x + rule2k + 12) >= 0
        && *(&rule1.x + rule1k + 4) == *(&rule2.x + rule2k + 4)
        && *(&rule1.x + rule1k + 12) == *(&rule2.x + rule2k + 12) )
      {
        *(&rule1.x + rule1k + 4) = -1;
        *(&rule1.x + rule1k + 12) = -1;
        --rule1.blckc;
        *(&rule2.x + rule2k + 4) = -1;
        *(&rule2.x + rule2k + 12) = -1;
        --rule2.blckc;
      }
    }
  }
  if ( rule1.blckc == rule1.numbc - rule2.numbc )
  {
    for ( rule1k_0 = 0; this->rulemain[rule1c].blckc > rule1k_0; ++rule1k_0 )
    {
      if ( *(&rule1.x + rule1k_0 + 4) >= 0
        && *(&rule1.x + rule1k_0 + 12) >= 0
        && this->mask[*(&rule1.x + rule1k_0 + 4)][*(&rule1.x + rule1k_0 + 12)] != 1 )
      {
        this->rightrule[*(&rule1.x + rule1k_0 + 4)][*(&rule1.x + rule1k_0 + 12)] = 1;
      }
    }
    for ( rule2k_0 = 0; this->rulemain[rule2c].blckc > rule2k_0; ++rule2k_0 )
    {
      if ( *(&rule2.x + rule2k_0 + 4) >= 0
        && *(&rule2.x + rule2k_0 + 12) >= 0
        && this->mask[*(&rule2.x + rule2k_0 + 4)][*(&rule2.x + rule2k_0 + 12)] != 1 )
      {
        this->leftrule[*(&rule2.x + rule2k_0 + 4)][*(&rule2.x + rule2k_0 + 12)] = 1;
      }
    }
  }
}


// Address: 0x004031E6; symbol: __ZN5Board11compareruleEv
void __thiscall Board::comparerule(Board *const this)
{
  Board *thisa; // [esp+2Ch] [ebp-1Ch]
  int y; // [esp+30h] [ebp-18h]
  int x; // [esp+34h] [ebp-14h]
  signed int k; // [esp+38h] [ebp-10h]
  int rulemaini; // [esp+3Ch] [ebp-Ch]

  thisa = this;
  for ( rulemaini = 0; thisa->rulemainc > rulemaini; ++rulemaini )
  {
    x = thisa->rulemain[rulemaini].x;
    y = thisa->rulemain[rulemaini].y;
    for ( k = 0; k <= 7; ++k )
    {
      if ( Block::isok(&thisa->0, k, x, y, &thisa->tx, &thisa->ty) && thisa->blckrule[thisa->tx][thisa->ty] >= 0 )
        Board::comparerule(thisa, rulemaini, thisa->blckrule[thisa->tx][thisa->ty]);
    }
  }
}


// Address: 0x00403306; symbol: __ZN5Board9applyruleEb
void __thiscall Board::applyrule(Board *const this, bool applyb)
{
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  for ( i = 0; thisa->w > i; ++i )
  {
    for ( j = 2; thisa->h > j; ++j )
    {
      if ( thisa->leftrule[i][j] )
      {
        if ( thisa->blck[i][j] != 1 && thisa->mask[i][j] != 1 )
        {
          thisa->solvebb = 1;
          thisa->solveb0 = 1;
          thisa->solveb1 = 1;
          thisa->solveb2 = 1;
          thisa->solveb3 = 1;
          ++thisa->solven;
          if ( applyb )
            Board::clickleft(thisa, i, j, 0);
        }
      }
      if ( thisa->rightrule[i][j]
        && thisa->blck[i][j] != 1
        && thisa->qstn[i][j] != 1
        && thisa->flag[i][j] != 1
        && thisa->mask[i][j] != 1 )
      {
        thisa->solvebb = 1;
        thisa->solveb0 = 1;
        thisa->solveb1 = 1;
        thisa->solveb2 = 1;
        thisa->solveb3 = 1;
        ++thisa->solven;
        if ( applyb )
          Board::clickright(thisa, i, j, 0);
      }
    }
  }
}


// Address: 0x00403530; symbol: __ZN5Board6solve2Eb
void __thiscall Board::solve2(Board *const this, bool applyb)
{
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  this->solveb2 = 0;
  this->rulemainc = 0;
  this->solven = 0;
  if ( this->sit <= 3 && !this->pauseb )
  {
    Board::createrule(this);
    Board::comparerule(thisa);
    Board::applyrule(thisa, applyb);
    if ( applyb )
      Sound::playsound(&thisa->sd, thisa->sd.sSolve);
  }
}


// Address: 0x004035CA; symbol: __ZN5Board6solve2Ev
void __thiscall Board::solve2(Board *const this)
{
  Board::solve2(this, 1);
}


// Address: 0x004035EA; symbol: __ZN5Board7solve2_Eb
void __thiscall Board::solve2_(Board *const this, bool applyb)
{
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int solven_; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  this->solveb2 = 1;
  solven_ = -1;
  while ( thisa->solveb2 == 1 && (thisa->solven > solven_ || applyb == 1) )
  {
    solven_ = thisa->solven;
    if ( applyb )
      Board::checkline(thisa, 0);
    Board::solve2(thisa, applyb);
  }
}


// Address: 0x00403676; symbol: __ZN5Board7solve2_Ev
void __thiscall Board::solve2_(Board *const this)
{
  Board::solve2_(this, 1);
}


// Address: 0x00403696; symbol: __ZN5Board7solve3_Ev
void __thiscall Board::solve3_(Board *const this)
{
  bool v1; // dl
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  this->solveb3 = 1;
  while ( thisa->solveb3 )
  {
    Board::checkline(thisa, 0);
    Board::solve1(thisa);
    Board::checkline(thisa, 0);
    Board::solve2(thisa);
    v1 = thisa->solveb1 || thisa->solveb2;
    thisa->solveb3 = v1;
  }
}


// Address: 0x0040372A; symbol: __ZN5Board10checkerrorEll
bool __thiscall Board::checkerror(Board *const this, int i, int j)
{
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  char result; // [esp+2Fh] [ebp-9h]

  thisa = this;
  result = 0;
  if ( this->blck[i][j] && this->mine[i][j] && this->sit != 2 && this->sit <= 3 )
  {
    this->dieb = 1;
    this->diex = i;
    this->diey = j;
    this->blck[i][j] = 0;
    this->flag[i][j] = 1;
    this->qstn[i][j] = 0;
    this->sit = 2;
    if ( this->solven > 0 || this->tutb > 0 )
    {
      Board::addline(this);
      Board::addline(thisa);
      Steam::compscr(&thisa->st, thisa->line - thisa->missline, thisa->mode, thisa->st.scrindexnomiss);
      thisa->missline = thisa->line;
      Steam::compscr(&thisa->st, ++thisa->missi, thisa->mode, thisa->st.scrindexmiss);
      Board::checkline(thisa, 1);
      Board::checkdie(thisa);
    }
    if ( thisa->sit == 2 )
      thisa->sit = 1;
    Steam::addscr(&thisa->st, thisa->st.scrdead, 1, thisa->mode);
    Sound::playsound(&thisa->sd, thisa->sd.sError);
    thisa->sb = 0;
    result = 1;
    thisa->checkr = 1;
  }
  return result;
}


// Address: 0x00403976; symbol: __ZN5Board10checkerrorEv
bool __thiscall Board::checkerror(Board *const this)
{
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  bool result; // [esp+2Fh] [ebp-9h]

  thisa = this;
  result = 0;
  if ( this->sit != 2 && this->sit <= 3 )
  {
    this->dieb = 0;
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = 0; thisa->h > j; ++j )
        result = Board::checkerror(thisa, i, j);
    }
  }
  return result;
}


// Address: 0x004039F6; symbol: __ZN5Board9checklineEb
void __thiscall Board::checkline(Board *const this, bool delayb_)
{
  int dl_0; // ST4C_4
  Board *thisa; // [esp+3Ch] [ebp-3Ch]
  int maskj_; // [esp+50h] [ebp-28h]
  int k; // [esp+54h] [ebp-24h]
  int i; // [esp+58h] [ebp-20h]
  int j_; // [esp+5Ch] [ebp-1Ch]
  int flagc; // [esp+60h] [ebp-18h]
  int blckc; // [esp+64h] [ebp-14h]
  bool delb; // [esp+6Bh] [ebp-Dh]
  int j; // [esp+6Ch] [ebp-Ch]

  thisa = this;
  if ( this->sit > 0 && this->sit <= 3 && !this->pauseb )
  {
    Board::solve0_(this);
    delb = 0;
    j = thisa->h - 1;
    j_ = 0;
    maskj_ = thisa->maskj & ~(thisa->maskj >> 31);
    while ( j >= maskj_ )
    {
      blckc = 0;
      flagc = 0;
      for ( i = 0; thisa->w > i; ++i )
      {
        if ( thisa->blck[i][j] != 1 )
          ++blckc;
        if ( thisa->flag[i][j] )
          ++flagc;
      }
      if ( thisa->n != blckc && thisa->n != flagc )
      {
        --j;
      }
      else
      {
        delb = 1;
        Board::delline(thisa, j);
        if ( thisa->delayb && delayb_ || thisa->tutb == 1 )
        {
          for ( k = 0; thisa->mult > (long double)k; ++k )
            Line(
              0,
              (signed int)((long double)(16 * (j - j_ + 3) + 8) * thisa->mult
                         + (long double)k
                         - (thisa->mult - 1.0) / 2.0),
              (signed int)((long double)thisa->w_ * thisa->mult),
              0,
              thisa->cred);
        }
        ++j_;
      }
    }
    if ( delb )
    {
      if ( (Sound::playsound(&thisa->sd, thisa->sd.sSolve), thisa->delayb) && delayb_ || thisa->tutb == 1 )
      {
        FreshWin();
        dl_0 = (signed int)(1000.0 / ((long double)thisa->level / 5.0 + 1.0));
        thisa->time = thisa->time + (long double)dl_0 / 1000.0;
        Delay(dl_0);
        thisa->delayb__ = 1;
      }
    }
    Board::solve0_(thisa);
    Board::solve2_(thisa, 0);
  }
}


// Address: 0x00403CE8; symbol: __ZN5Board7addlineEb
void __thiscall Board::addline(Board *const this, bool misslineb)
{
  Board *thisa; // [esp+2Ch] [ebp-2Ch]
  int j; // [esp+3Ch] [ebp-1Ch]
  signed int k; // [esp+40h] [ebp-18h]
  int j_0; // [esp+44h] [ebp-14h]
  int i_0; // [esp+48h] [ebp-10h]
  int i; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  if ( this->sit > 0 && this->sit <= 3 && !this->pauseb )
  {
    --this->bouns;
    --this->maskj;
    if ( this->relaxb && this->maskj <= 0 )
    {
      --this->line;
      --this->sum;
      this->line &= ~(this->line >> 31);
      if ( misslineb )
      {
        --this->missline;
        this->missline &= ~(this->missline >> 31);
      }
      this->sum &= ~(this->sum >> 31);
      ++this->maskj;
    }
    j = this->maskj;
    if ( this->maskj >= 0 )
    {
      for ( i = 0; this->w > i; ++i )
        this->mask[i][j] = 0;
      for ( i_0 = 0; thisa->w > i_0; ++i_0 )
      {
        for ( j_0 = thisa->maskj + 1; thisa->maskj <= j_0; --j_0 )
        {
          thisa->numb[i_0][j_0] = 0;
          for ( k = 0; k <= 7; ++k )
          {
            if ( Block::isok(&thisa->0, k, i_0, j_0, &thisa->tx, &thisa->ty) )
            {
              if ( thisa->mine[thisa->tx][thisa->ty] )
                ++thisa->numb[i_0][j_0];
            }
          }
        }
      }
    }
    else
    {
      this->maskjb = 1;
    }
  }
}


// Address: 0x00403F44; symbol: __ZN5Board7addlineEv
void __thiscall Board::addline(Board *const this)
{
  Board::addline(this, 1);
}


// Address: 0x00403F64; symbol: __ZN5Board7addmaskEv
bool __thiscall Board::addmask(Board *const this)
{
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  if ( this->sit <= 0 || this->sit > 3 || this->pauseb )
  {
    this->time = GetTimeR() - this->pausetime;
    return 0;
  }
  if ( this->tutb || GetTimeR() <= this->time + 5.0 / ((long double)this->level + 5.0) )
    return 0;
  while ( GetTimeR() > thisa->time + 5.0 / ((long double)thisa->level + 5.0) )
  {
    thisa->time = thisa->time + 5.0 / ((long double)thisa->level + 5.0);
    if ( ++thisa->maski == thisa->w )
    {
      thisa->maski = 0;
      Board::addline(thisa);
      Board::checkline(thisa, 1);
    }
  }
  Board::checkdie(thisa);
  return 1;
}


// Address: 0x004040E2; symbol: __ZN5Board8checkdieEv
void __thiscall Board::checkdie(Board *const this)
{
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  if ( (!this->maskj && this->maski > 0 || this->maskj < 0) && this->sit <= 3 && !this->relaxb )
  {
    Steam::compscr(&this->st, this->line - this->missline, this->mode, this->st.scrindexnomiss);
    thisa->missline = thisa->line;
    thisa->aliveb = 0;
    thisa->sit = 4;
    if ( thisa->dieb )
      thisa->blck[thisa->diex][thisa->diey] = 1;
    Sound::playsound(&thisa->sd, thisa->sd.sLose);
    if ( !thisa->rightb )
      Steam::addach(&thisa->st, thisa->st.achhidright);
    Steam::setlead(&thisa->st, thisa->mode);
  }
  if ( thisa->maskj || thisa->maski || thisa->sit > 3 )
  {
    if ( thisa->aliveb )
      Steam::addach(&thisa->st, thisa->st.achhidalive);
  }
  else
  {
    thisa->aliveb = 1;
  }
}


// Address: 0x00404286; symbol: __ZN5Board7dellineEl
// local variable allocation has failed, the output may be wrong!
void __thiscall Board::delline(Board *const this, int l)
{
  signed int v2; // eax
  bool v3; // dl
  int v4; // eax
  signed int v5; // eax
  signed int v6; // eax
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

  thisa = this;
  if ( this->sit > 0 && this->sit <= 3 && !this->pauseb )
  {
    this->checkr = 0;
    if ( this->relaxb )
    {
      ++this->line;
      ++this->sum;
      v2 = this->line;
      if ( v2 > 999999 )
        v2 = 999999;
      this->line = v2;
      Board::addline(this, 0);
    }
    else
    {
      ++this->maskj;
    }
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = l; j >= 0; --j )
      {
        if ( j )
        {
          thisa->mine[i][j] = thisa->mine[i][j - 1];
          v3 = thisa->mask[i][j - 1] && thisa->relaxb != 1;
          thisa->mask[i][j] = v3;
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
      v4 = thisa->h - 1;
      if ( v4 > l + 1 )
        v4 = l + 1;
      for ( j_1 = v4; j_1 >= l; --j_1 )
      {
        thisa->numb[i_1][j_1] = 0;
        for ( k = 0; k <= 7; ++k )
        {
          if ( Block::isok(&thisa->0, k, i_1, j_1, &thisa->tx, &thisa->ty) && thisa->mine[thisa->tx][thisa->ty] )
            ++thisa->numb[i_1][j_1];
        }
      }
    }
    ++thisa->line;
    ++thisa->sum;
    v5 = thisa->line;
    if ( v5 > 999999 )
      v5 = 999999;
    thisa->line = v5;
    if ( thisa->sum == thisa->line + thisa->tetrisi )
    {
      Steam::compscr(&thisa->st, thisa->line, thisa->mode, thisa->st.scrindexline);
      if ( thisa->mdb == 1 )
        Steam::compscr(&thisa->st, thisa->line, thisa->mode, thisa->st.scrindexmdb);
      Steam::compscr(&thisa->st, thisa->line - thisa->missline, thisa->mode, thisa->st.scrindexnomiss);
      scrtotal_[0] = 0;
      scrtotal_[1] = 2;
      scrtotal_[2] = 3;
      scrtotal_[3] = 6;
      Steam::addscr(&thisa->st, thisa->st.scrtotal, scrtotal_[thisa->mode], thisa->mode);
      if ( thisa->line > 9999 )
        Steam::addach(&thisa->st, thisa->st.achhidedge);
    }
    if ( thisa->maskj > thisa->h - 4 )
    {
      ++thisa->tetrisi;
      ++thisa->sum;
      Steam::compscr(&thisa->st, thisa->tetrisi, thisa->mode, thisa->st.scrindextetris);
      thisa->line += 4 + (thisa->bouns & ~(thisa->bouns >> 31));
      thisa->sum += 4 + (thisa->bouns & ~(thisa->bouns >> 31));
      v6 = thisa->line;
      if ( v6 > 999999 )
        v6 = 999999;
      thisa->line = v6;
      if ( thisa->sum == thisa->line + thisa->tetrisi )
      {
        Steam::compscr(&thisa->st, thisa->line, thisa->mode, thisa->st.scrindexline);
        if ( thisa->mdb == 1 )
          Steam::compscr(&thisa->st, thisa->line, thisa->mode, thisa->st.scrindexmdb);
        Steam::compscr(&thisa->st, thisa->line - thisa->missline, thisa->mode, thisa->st.scrindexnomiss);
      }
      for ( k_0 = 0; k_0 <= 3; ++k_0 )
        Board::addline(thisa);
      Board::checkline(thisa, 0);
      thisa->sit = 3;
      thisa->bouns = 4;
      Sound::playsound(&thisa->sd, thisa->sd.sNew);
      Steam::addscr(&thisa->st, thisa->st.scrfour, 1, thisa->mode);
    }
    while ( (thisa->level + 1) * (thisa->level + 1) <= thisa->line )
    {
      ++thisa->level;
      Sound::playsound(&thisa->sd, thisa->sd.sWin);
    }
  }
}


// Address: 0x00404BF2; symbol: __ZN5Board7setqstnEllb
void __thiscall Board::setqstn(Board *const this, int x, int y, bool sb_)
{
  this->qstn[x][y] ^= 1u;
  if ( sb_ )
    Sound::playsound(&this->sd, this->sd.sFlag);
}


// Address: 0x00404C5C; symbol: __ZN5Board7setqstnEll
void __thiscall Board::setqstn(Board *const this, int x, int y)
{
  Board::setqstn(this, x, y, 1);
}


// Address: 0x00404C8C; symbol: __ZN5Board7setflagEll
void __thiscall Board::setflag(Board *const this, int x, int y)
{
  Board *thisa; // [esp+2Ch] [ebp-1Ch]
  signed int k_0; // [esp+30h] [ebp-18h]
  signed int k; // [esp+34h] [ebp-14h]
  bool sc; // [esp+3Bh] [ebp-Dh]
  int qc; // [esp+3Ch] [ebp-Ch]

  thisa = this;
  if ( this->sit > 0 && this->sit <= 3 && !this->pauseb )
  {
    qc = 0;
    sc = 0;
    for ( k = 0; k <= 7; ++k )
    {
      if ( Block::isok(&thisa->0, k, x, y, &thisa->tx, &thisa->ty) && thisa->blck[thisa->tx][thisa->ty] != 1 )
        ++qc;
    }
    if ( thisa->numb[x][y] == qc )
    {
      for ( k_0 = 0; k_0 <= 7; ++k_0 )
      {
        if ( Block::isok(&thisa->0, k_0, x, y, &thisa->tx, &thisa->ty)
          && thisa->blck[thisa->tx][thisa->ty] != 1
          && thisa->flag[thisa->tx][thisa->ty] != 1
          && thisa->mask[thisa->tx][thisa->ty] != 1 )
        {
          thisa->flag[thisa->tx][thisa->ty] = 1;
          thisa->qstn[thisa->tx][thisa->ty] = 0;
          sc = 1;
        }
      }
      if ( thisa->sb && sc )
      {
        Sound::playsound(&thisa->sd, thisa->sd.sFlag);
        thisa->sb = 0;
      }
    }
  }
}


// Address: 0x00404E94; symbol: __ZN5Board8setblockEll
void __thiscall Board::setblock(Board *const this, int x, int y)
{
  Board *thisa; // [esp+2Ch] [ebp-2Ch]
  signed int k_0; // [esp+3Ch] [ebp-1Ch]
  signed int k; // [esp+40h] [ebp-18h]
  bool sr; // [esp+47h] [ebp-11h]
  int qq; // [esp+48h] [ebp-10h]
  int qn; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  if ( this->sit > 0 && this->sit <= 3 && !this->pauseb )
  {
    qn = 0;
    qq = 0;
    sr = 0;
    for ( k = 0; k <= 7; ++k )
    {
      if ( Block::isok(&thisa->0, k, x, y, &thisa->tx, &thisa->ty) )
      {
        if ( thisa->flag[thisa->tx][thisa->ty] )
          ++qn;
        if ( thisa->qstn[thisa->tx][thisa->ty] )
          ++qq;
      }
    }
    if ( thisa->numb[x][y] == qn || qn + qq == thisa->numb[x][y] )
    {
      for ( k_0 = 0; k_0 <= 7; ++k_0 )
      {
        if ( Block::isok(&thisa->0, k_0, x, y, &thisa->tx, &thisa->ty)
          && thisa->blck[thisa->tx][thisa->ty] != 1
          && thisa->flag[thisa->tx][thisa->ty] != 1
          && thisa->mask[thisa->tx][thisa->ty] != 1 )
        {
          if ( thisa->qstn[thisa->tx][thisa->ty] == 1 )
          {
            if ( !thisa->mdb_ || thisa->tutb == 1 )
              thisa->qstn[thisa->tx][thisa->ty] = 0;
          }
          else
          {
            thisa->blck[thisa->tx][thisa->ty] = 1;
            thisa->qstn[thisa->tx][thisa->ty] = 0;
            sr = 1;
            thisa->solvebb = 1;
            thisa->solveb0 = 1;
            thisa->solveb1 = 1;
            thisa->solveb2 = 1;
            thisa->solveb3 = 1;
            Board::checkerror(thisa, thisa->tx, thisa->ty);
          }
        }
      }
      if ( thisa->sb && sr )
      {
        Sound::playsound(&thisa->sd, thisa->sd.sRight);
        thisa->sb = 0;
      }
    }
    if ( thisa->sb )
      Board::checkerror(thisa);
  }
}


// Address: 0x004051BE; symbol: __ZN5Board9clicknumbEllb
void __thiscall Board::clicknumb(Board *const this, int x, int y, bool sb_)
{
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  this->sb = sb_;
  if ( this->sb )
    this->rightb = 1;
  Board::setblock(this, x, y);
  if ( !thisa->mdb_ || thisa->tutb == 1 )
  {
    Board::setblock(thisa, x, y);
    Board::setflag(thisa, x, y);
  }
}


// Address: 0x00405264; symbol: __ZN5Board9clickleftEllb
void __thiscall Board::clickleft(Board *const this, int x, int y, bool sb_)
{
  Board::clickleft(this, x, y, sb_, 3);
}


// Address: 0x004052A2; symbol: __ZN5Board10clickrightEllb
void __thiscall Board::clickright(Board *const this, int x, int y, bool sb_)
{
  Board::clickright(this, x, y, sb_, 3);
}


// Address: 0x004052E0; symbol: __ZN5Board9clickleftEllbl
void __thiscall Board::clickleft(Board *const this, int x, int y, bool sb_, int md_)
{
  bool v5; // al
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  if ( this->mask[x][y] != 1 && this->flag[x][y] != 1 )
  {
    if ( this->blck[x][y] == 1 )
    {
      if ( sb_ )
      {
        this->mdb_ = md_ == 5;
        Board::clicknumb(this, x, y, sb_);
        thisa->mdb_ = 0;
      }
    }
    else if ( md_ > 2 )
    {
      this->blck[x][y] = 1;
      this->qstn[x][y] = 0;
      if ( this->sit == 2 )
        this->sit = 1;
      if ( this->sit == 3 )
        this->sit = 1;
      v5 = !Board::checkerror(this) && sb_;
      if ( v5 )
        Sound::playsound(&thisa->sd, thisa->sd.sLeft);
    }
  }
}


// Address: 0x00405448; symbol: __ZN5Board10clickrightEllbl
void __thiscall Board::clickright(Board *const this, int x, int y, bool sb_, int md_)
{
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  bool qstnb; // [esp+2Fh] [ebp-9h]

  thisa = this;
  if ( this->mask[x][y] != 1 && this->flag[x][y] != 1 )
  {
    if ( this->blck[x][y] == 1 )
    {
      if ( sb_ && md_ != 5 )
        Board::clicknumb(this, x, y, sb_);
    }
    else if ( md_ > 2 )
    {
      Board::setqstn(this, x, y, sb_);
    }
  }
  if ( !thisa->sit )
  {
    qstnb = 1;
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = thisa->maskj; thisa->h > j; ++j )
      {
        if ( thisa->qstn[i][j] != 1 )
          qstnb = 0;
      }
    }
    if ( qstnb )
      Steam::addach(&thisa->st, thisa->st.achhidmark);
  }
}


// Address: 0x00405592; symbol: __ZN5Board5pauseEv
void __thiscall Board::pause(Board *const this)
{
  Board *thisa; // [esp+Ch] [ebp-Ch]

  thisa = this;
  if ( !this->pauseb )
    this->pausetime = GetTimeR() - this->time;
  thisa->pauseb = thisa->pauseb == 0;
}


// Address: 0x004055D8; symbol: __Z11CombinePathPcPKcS1_
void __cdecl CombinePath(char *dest, const char *path1, const char *path2)
{
  lstrcpyA(dest, path1);
  lstrcatA(dest, "/");
  lstrcatA(dest, path2);
}


// Address: 0x00405621; symbol: __Z18CabExtractCallbackPvjjj@16
UINT __stdcall CabExtractCallback(PVOID context, UINT notification, uintptr_t param1, uintptr_t param2)
{
  if ( notification != 17 )
    return 0;
  CombinePath((char *)(param1 + 18), (const char *)context, *(const char **)param1);
  return 1;
}


// Address: 0x00405667; symbol: __Z15RemoveExtensionPc
void __cdecl RemoveExtension(char *filePath)
{
  char *lastDot; // [esp+1Ch] [ebp-Ch]

  lastDot = strrchr(filePath, 46);
  if ( lastDot )
    *lastDot = 0;
}


// Address: 0x00405692; symbol: __Z14ProcessCabFilePKc
BOOL __cdecl ProcessCabFile(const char *cabFilePath)
{
  BOOL result; // eax
  char nestedCabPath[260]; // [esp+18h] [ebp-4C0h]
  WIN32_FIND_DATAA findData; // [esp+180h] [ebp-358h]
  char searchPath[260]; // [esp+2C0h] [ebp-218h]
  char destFolder[260]; // [esp+3C4h] [ebp-114h]
  HANDLE hFind; // [esp+4C8h] [ebp-10h]
  DWORD errorCode; // [esp+4CCh] [ebp-Ch]

  lstrcpyA(destFolder, cabFilePath);
  RemoveExtension(destFolder);
  CreateDirectoryA(destFolder, 0);
  if ( SetupIterateCabinetA(cabFilePath, 0, CabExtractCallback, destFolder) == 0 )
  {
    errorCode = GetLastError();
    wsprintfA(nestedCabPath, "Failed to extract CAB file: %s. Error code: %lu", cabFilePath, errorCode);
    MessageBoxA(0, nestedCabPath, "Error", 0x10u);
    result = 0;
  }
  else
  {
    if ( !strstr(cabFilePath, "data.cab") )
      DeleteFileA(cabFilePath);
    CombinePath(searchPath, destFolder, "*.cab");
    hFind = FindFirstFileA(searchPath, &findData);
    if ( hFind != (HANDLE)-1 )
    {
      do
      {
        CombinePath(nestedCabPath, destFolder, findData.cFileName);
        ProcessCabFile(nestedCabPath);
      }
      while ( FindNextFileA(hFind, &findData) != 0 );
      FindClose(hFind);
    }
    result = 1;
  }
  return result;
}


// Address: 0x00405840; symbol: __Z23DeleteFolderRecursivelyPKc
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


// Address: 0x00405973; symbol: __Z22CheckAndProcessCabFilev
void CheckAndProcessCabFile()
{
  char versionFilePath[260]; // [esp+28h] [ebp-110h]
  HANDLE hMarker; // [esp+12Ch] [ebp-Ch]

  CombinePath(versionFilePath, "./data", version);
  if ( GetFileAttributesA(versionFilePath) == -1 )
  {
    DeleteFolderRecursively("./data");
    if ( GetFileAttributesA("./data.cab") != -1 && ProcessCabFile("./data.cab") != 0 )
    {
      hMarker = CreateFileA(versionFilePath, 0x40000000u, 0, 0, 2u, 0x80u, 0);
      if ( hMarker != (HANDLE)-1 )
        CloseHandle(hMarker);
    }
  }
}


// Address: 0x00405A50; symbol: __Z13WinCreateMainv
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


// Address: 0x00405DD2; symbol: __Z15MonitorenumprocP10HMONITOR__P5HDC__P7tagRECTl@16
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


// Address: 0x00405E78; symbol: __Z11WinRegisterv
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


// Address: 0x00405EEA; symbol: __Z9WinCreatev
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


// Address: 0x00405FEA; symbol: __Z7WinInitv
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


// Address: 0x004060DC; symbol: __Z8FreshFPSv
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


// Address: 0x00406167; symbol: __Z6AddFPSv
void AddFPS()
{
  ++_mscnti;
  FreshFPS();
}


// Address: 0x00406182; symbol: __Z9CreateWinllmmmmmPKc
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
  while ( (unsigned __int8)IsWin() ^ 1 )
    Sleep(1u);
  SetBkMode(_dc, 1);
  Clear();
}


// Address: 0x00406287; symbol: __Z9CreateWinmmmmmPKc
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


// Address: 0x004062ED; symbol: __Z9CreateWinmmmmm
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int style)
{
  CreateWin(w, h, cfg, cbg, style, DEFAULTCLASS);
}


// Address: 0x00406326; symbol: __Z9CreateWinmmmm
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  CreateWin(w, h, cfg, cbg, 0);
}


// Address: 0x00406357; symbol: __Z9CreateWinmmm
void __cdecl CreateWin(unsigned int w, unsigned int h, unsigned int c)
{
  CreateWin(w, h, 0, c);
}


// Address: 0x00406381; symbol: __Z9CreateWinmm
void __cdecl CreateWin(unsigned int w, unsigned int h)
{
  CreateWin(w, h, 0);
}


// Address: 0x004063A4; symbol: __Z9CreateWinm
void __cdecl CreateWin(unsigned int cbg)
{
  int v1; // ebx
  int v2; // edx

  v1 = GetScrHeight() / 2;
  v2 = GetScrWidth() / 2;
  CreateWin(v2, v1, cbg);
}


// Address: 0x004063E5; symbol: __Z9CreateWinv
void CreateWin()
{
  int v0; // ebx
  int v1; // eax

  v0 = GetScrHeight() / 2;
  v1 = GetScrWidth();
  CreateWin(v1 / 2, v0);
}


// Address: 0x0040641D; symbol: __Z8FreshWinv
void FreshWin()
{
  DrawBMP(_pmain, _pmscr);
  AddFPS();
}


// Address: 0x00406442; symbol: __Z8CloseWinv
void CloseWin()
{
  SendMessageA(_hw, 0x10u, 0, 0);
}


// Address: 0x00406473; symbol: __Z5IsWinv
BOOL IsWin()
{
  return _winb;
}


// Address: 0x0040647F; symbol: __Z8GetTimeRv
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


// Address: 0x0040651B; symbol: __Z7GetTimev
signed __int64 GetTime()
{
  return (signed __int64)(GetTimeR() * 1000.0);
}


// Address: 0x0040654C; symbol: __Z8SetTitlePKc
void __cdecl SetTitle(const char *s)
{
  SetWindowTextA(_hw, s);
}


// Address: 0x0040656C; symbol: __Z9SetTitleWPKs
void __cdecl SetTitleW(const __int16 *s)
{
  SetWindowTextW(_hw, (LPCWSTR)s);
}


// Address: 0x0040658C; symbol: __Z8GetTitlev
char *GetTitle()
{
  GetWindowTextA(_hw, GetTitle(void)::c, 127);
  return GetTitle(void)::c;
}


// Address: 0x004065B9; symbol: __Z9GetTitleWv
WCHAR *GetTitleW()
{
  GetWindowTextW(_hw, &GetTitleW(void)::c, 127);
  return &GetTitleW(void)::c;
}


// Address: 0x004065E6; symbol: __Z7SetSizellmm
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


// Address: 0x00406674; symbol: __Z7SetSizemm
void __cdecl SetSize(unsigned int w, unsigned int h)
{
  int v2; // ebx
  int v3; // edx

  v2 = GetPosY();
  v3 = GetPosX();
  SetSize(v3, v2, w, h);
}


// Address: 0x004066AA; symbol: __Z8GetWidthv
unsigned int GetWidth()
{
  return _w;
}


// Address: 0x004066B4; symbol: __Z9GetHeightv
unsigned int GetHeight()
{
  return _h;
}


// Address: 0x004066BE; symbol: __Z7GetSizev
unsigned int GetSize()
{
  unsigned int v0; // ebx

  v0 = GetWidth() << 16;
  return v0 + GetHeight();
}


// Address: 0x004066D6; symbol: __Z11GetScrWidthv
int GetScrWidth()
{
  return GetSystemMetrics(0);
}


// Address: 0x004066ED; symbol: __Z12GetScrHeightv
int GetScrHeight()
{
  return GetSystemMetrics(1);
}


// Address: 0x00406704; symbol: __Z10GetScrSizev
int GetScrSize()
{
  int v0; // ebx

  v0 = GetScrWidth() << 16;
  return v0 + GetScrHeight();
}


// Address: 0x00406722; symbol: __Z11GetScrCapsXv
long double GetScrCapsX()
{
  HWND__ *v0; // eax
  HDC__ *v1; // eax

  v0 = GetDesktopWindow();
  v1 = GetDC(v0);
  return 144.0 / (long double)GetDeviceCaps(v1, 88);
}


// Address: 0x0040675B; symbol: __Z11GetScrCapsYv
long double GetScrCapsY()
{
  HWND__ *v0; // eax
  HDC__ *v1; // eax

  v0 = GetDesktopWindow();
  v1 = GetDC(v0);
  return 144.0 / (long double)GetDeviceCaps(v1, 90);
}


// Address: 0x00406794; symbol: __Z14GetBorderTitlev
int GetBorderTitle()
{
  return GetSystemMetrics(4);
}


// Address: 0x004067AB; symbol: __Z14GetBorderWidthv
int GetBorderWidth()
{
  int result; // eax

  if ( _style & 0x40000 )
    result = GetSystemMetrics(32);
  else
    result = GetSystemMetrics(7);
  return result;
}


// Address: 0x004067E1; symbol: __Z15GetBorderHeightv
int GetBorderHeight()
{
  int result; // eax

  if ( _style & 0x40000 )
    result = GetSystemMetrics(33);
  else
    result = GetSystemMetrics(8);
  return result;
}


// Address: 0x00406817; symbol: __Z13GetBorderSizev
int GetBorderSize()
{
  int v0; // ebx

  v0 = GetBorderWidth() << 16;
  return v0 + GetBorderHeight();
}


// Address: 0x00406835; symbol: __Z6SetPosll
void __cdecl SetPos(int x, int y)
{
  SetSize(x, y, _w, _h);
}


// Address: 0x00406864; symbol: __Z7GetPosXv
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


// Address: 0x004068A2; symbol: __Z7GetPosYv
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


// Address: 0x004068E0; symbol: __Z6GetPosv
int GetPos()
{
  LONG v0; // ebx

  v0 = GetPosX() << 16;
  return v0 + GetPosY();
}


// Address: 0x004068FE; symbol: __Z6GetWinv
pbitmap GetWin()
{
  return _pmain;
}


// Address: 0x00406908; symbol: __Z6GetScrv
pbitmap GetScr()
{
  return _pmscr;
}


// Address: 0x00406912; symbol: __Z7GetHwndP6bitmap
HGDIOBJ __cdecl GetHwnd(pbitmap b)
{
  return b->Handle;
}


// Address: 0x0040691C; symbol: __Z7GetHwndv
HWND GetHwnd()
{
  return _hw;
}


// Address: 0x00406926; symbol: __Z7GetDrawP6bitmap
HDC __cdecl GetDraw(pbitmap b)
{
  return b->DC;
}


// Address: 0x00406931; symbol: __Z7GetDrawv
HDC GetDraw()
{
  return _dc;
}


// Address: 0x0040693B; symbol: __Z10GetBGColorv
COLORREF GetBGColor()
{
  return _cbg;
}


// Address: 0x00406945; symbol: __Z10SetBGColorm
void __cdecl SetBGColor(unsigned int c)
{
  _cbg = c;
}


// Address: 0x00406953; symbol: __Z10GetFGColorv
unsigned int GetFGColor()
{
  return _cfg;
}


// Address: 0x0040695D; symbol: __Z10SetFGColorm
void __cdecl SetFGColor(unsigned int c)
{
  _cfg = c;
}


// Address: 0x0040696B; symbol: __Z11SetPenWidthm
void __cdecl SetPenWidth(unsigned int pew)
{
  _pew = pew;
}


// Address: 0x00406979; symbol: __Z11SetPenColorP6bitmapm
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


// Address: 0x004069FC; symbol: __Z13SetBrushColorP6bitmapm
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


// Address: 0x00406A6C; symbol: __Z11SetPenColorm
void __cdecl SetPenColor(unsigned int c)
{
  SetPenColor(_pmain, c);
}


// Address: 0x00406A89; symbol: __Z13SetBrushColorm
void __cdecl SetBrushColor(unsigned int c)
{
  SetBrushColor(_pmain, c);
}


// Address: 0x00406AA6; symbol: __Z6GetRedm
unsigned __int8 __cdecl GetRed(unsigned int c)
{
  return c;
}


// Address: 0x00406AAE; symbol: __Z8GetGreenm
unsigned __int8 __cdecl GetGreen(unsigned int c)
{
  return c >> 8;
}


// Address: 0x00406AB9; symbol: __Z7GetBluem
unsigned __int8 __cdecl GetBlue(unsigned int c)
{
  return c >> 16;
}


// Address: 0x00406AC4; symbol: __Z8GetAlpham
unsigned __int8 __cdecl GetAlpha(unsigned int c)
{
  return c >> 24;
}


// Address: 0x00406ACF; symbol: __Z7GetRGBAhhhh
unsigned int __cdecl GetRGBA(unsigned __int8 r, unsigned __int8 g, unsigned __int8 b, unsigned __int8 a)
{
  return (g << 8) | (b << 16) | (a << 24) | r;
}


// Address: 0x00406B15; symbol: __Z6GetRGBhhh
unsigned int __cdecl GetRGB(unsigned __int8 r, unsigned __int8 g, unsigned __int8 b)
{
  return GetRGBA(r, g, b, 0);
}


// Address: 0x00406B53; symbol: __Z7SetFontP6bitmap
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


// Address: 0x00406C4A; symbol: __Z7SetFontv
void SetFont()
{
  SetFont(_pmain);
}


// Address: 0x00406C60; symbol: __Z12SetFontWidthm
void __cdecl SetFontWidth(unsigned int w)
{
  _fw = w;
  SetFont();
}


// Address: 0x00406C76; symbol: __Z13SetFontHeightm
void __cdecl SetFontHeight(unsigned int h)
{
  _fh = h;
  SetFont();
}


// Address: 0x00406C8C; symbol: __Z11SetFontSizemm
void __cdecl SetFontSize(unsigned int w, unsigned int h)
{
  _fh = h;
  _fw = w;
  SetFont();
}


// Address: 0x00406CAA; symbol: __Z13SetFontWeightm
void __cdecl SetFontWeight(unsigned int wg)
{
  _fwg = wg;
  SetFont();
}


// Address: 0x00406CC0; symbol: __Z13SetFontLtalicm
void __cdecl SetFontLtalic(unsigned int lt)
{
  _flt = lt;
  SetFont();
}


// Address: 0x00406CD6; symbol: __Z16SetFontUnderLinem
void __cdecl SetFontUnderLine(unsigned int ud)
{
  _fud = ud;
  SetFont();
}


// Address: 0x00406CEC; symbol: __Z16SetFontStrikeOutm
void __cdecl SetFontStrikeOut(unsigned int sk)
{
  _fsk = sk;
  SetFont();
}


// Address: 0x00406D02; symbol: __Z14SetFontCharSetm
void __cdecl SetFontCharSet(unsigned int cs_0)
{
  _fcs = cs_0;
  SetFont();
}


// Address: 0x00406D18; symbol: __Z11SetFontNamePKc
void __cdecl SetFontName(const char *s)
{
  strcpy(_ffn, s);
  SetFont();
}


// Address: 0x00406D39; symbol: __Z13GetStringSizePKc
void __cdecl GetStringSize(const char *s)
{
  int v1; // eax

  v1 = strlen(s);
  GetTextExtentPoint32A(_dc, s, v1, &_strz);
}


// Address: 0x00406D72; symbol: __Z14GetStringWidthPKc
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


// Address: 0x00406DB3; symbol: __Z15GetStringHeightPKc
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


// Address: 0x00406DF4; symbol: __Z10InitTextXYPP6bitmapPPKsPmS5_
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


// Address: 0x00406EB2; symbol: __Z10InitTextXYPP6bitmapPPKcPmS5_
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


// Address: 0x00406F6F; symbol: __Z10DrawTextXYP6bitmapPKsllmmmmm
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


// Address: 0x0040700A; symbol: __Z10DrawTextXYP6bitmapPKsllmmmm
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


// Address: 0x004070A6; symbol: __Z10DrawTextXYP6bitmapPKcllmmmm
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


// Address: 0x00407142; symbol: __Z10DrawTextXYP6bitmapPKcllmm
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


// Address: 0x004071C1; symbol: __Z10DrawTextXYP6bitmapPKcllm
void __cdecl DrawTextXY(pbitmap b, const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXY(b, s, x, y, cfg, 0);
}


// Address: 0x004071F9; symbol: __Z10DrawTextXYPKcllmm
void __cdecl DrawTextXY(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(0, s, x, y, cfg, cbg);
}


// Address: 0x00407231; symbol: __Z10DrawTextXYPKcllm
void __cdecl DrawTextXY(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXY(0, s, x, y, cfg);
}


// Address: 0x00407262; symbol: __Z10DrawTextXYPKclm
void __cdecl DrawTextXY(const char *s, int x, unsigned int y)
{
  DrawTextXY(s, x, y, 0);
}


// Address: 0x0040728C; symbol: __Z9DrawTextAPKcmm
void __cdecl DrawTextA(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(s, _fx, _fy, cfg, cbg);
}


// Address: 0x004072C1; symbol: __Z9DrawTextAPKcm
void __cdecl DrawTextA(const char *s, unsigned int cfg)
{
  DrawTextA(s, cfg, 0);
}


// Address: 0x004072E4; symbol: __Z9DrawTextAPKc
void __cdecl DrawTextA(const char *s)
{
  DrawTextA(s, 0);
}


// Address: 0x00407300; symbol: __Z12DrawTextlnXYPKcllmm
void __cdecl DrawTextlnXY(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(s, x, y, cfg, cbg);
  _fx = x;
  _fy = GetStringHeight(s) + y;
}


// Address: 0x0040734F; symbol: __Z12DrawTextlnXYPKcllm
void __cdecl DrawTextlnXY(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextlnXY(s, x, y, cfg, 0);
}


// Address: 0x00407380; symbol: __Z12DrawTextlnXYPKclm
void __cdecl DrawTextlnXY(const char *s, int x, unsigned int y)
{
  DrawTextlnXY(s, x, y, 0);
}


// Address: 0x004073AA; symbol: __Z10DrawTextlnPKcmm
void __cdecl DrawTextln(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextlnXY(s, _fx, _fy, cfg, cbg);
}


// Address: 0x004073DF; symbol: __Z10DrawTextlnPKcm
void __cdecl DrawTextln(const char *s, unsigned int cfg)
{
  DrawTextln(s, cfg, 0);
}


// Address: 0x00407402; symbol: __Z10DrawTextlnPKc
void __cdecl DrawTextln(const char *s)
{
  DrawTextln(s, 0);
}


// Address: 0x0040741E; symbol: __Z10DrawTextlnv
void DrawTextln()
{
  DrawTextln(s);
}


// Address: 0x00407433; symbol: __Z11DrawTextXYwP6bitmapPKcllmm
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


// Address: 0x004074C9; symbol: __Z11DrawTextXYwP6bitmapPKcllm
void __cdecl DrawTextXYw(pbitmap b, const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXYw(b, s, x, y, cfg, 0);
}


// Address: 0x00407501; symbol: __Z11DrawTextXYwPKcllmm
void __cdecl DrawTextXYw(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(0, s, x, y, cfg, cbg);
}


// Address: 0x00407539; symbol: __Z11DrawTextXYwPKcllm
void __cdecl DrawTextXYw(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextXYw(0, s, x, y, cfg);
}


// Address: 0x0040756A; symbol: __Z11DrawTextXYwPKclm
void __cdecl DrawTextXYw(const char *s, int x, unsigned int y)
{
  DrawTextXYw(s, x, y, 0);
}


// Address: 0x00407594; symbol: __Z9DrawTextwPKcmm
void __cdecl DrawTextw(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(s, _fx, _fy, cfg, cbg);
}


// Address: 0x004075C9; symbol: __Z9DrawTextwPKcm
void __cdecl DrawTextw(const char *s, unsigned int cfg)
{
  DrawTextw(s, cfg, 0);
}


// Address: 0x004075EC; symbol: __Z9DrawTextwPKc
void __cdecl DrawTextw(const char *s)
{
  DrawTextw(s, 0);
}


// Address: 0x00407608; symbol: __Z13DrawTextlnXYwPKcllmm
void __cdecl DrawTextlnXYw(const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXYw(s, x, y, cfg, cbg);
  _fx = x;
  _fy = y + _fh;
}


// Address: 0x0040764F; symbol: __Z13DrawTextlnXYwPKcllm
void __cdecl DrawTextlnXYw(const char *s, int x, int y, unsigned int cfg)
{
  DrawTextlnXYw(s, x, y, cfg, 0);
}


// Address: 0x00407680; symbol: __Z13DrawTextlnXYwPKclm
void __cdecl DrawTextlnXYw(const char *s, int x, unsigned int y)
{
  DrawTextlnXYw(s, x, y, 0);
}


// Address: 0x004076AA; symbol: __Z11DrawTextlnwPKcmm
void __cdecl DrawTextlnw(const char *s, unsigned int cfg, unsigned int cbg)
{
  DrawTextlnXYw(s, _fx, _fy, cfg, cbg);
}


// Address: 0x004076DF; symbol: __Z11DrawTextlnwPKcm
void __cdecl DrawTextlnw(const char *s, unsigned int cfg)
{
  DrawTextlnw(s, cfg, 0);
}


// Address: 0x00407702; symbol: __Z11DrawTextlnwPKc
void __cdecl DrawTextlnw(const char *s)
{
  DrawTextlnw(s, 0);
}


// Address: 0x0040771E; symbol: __Z8GetPixelP6bitmapmm
unsigned int __cdecl GetPixel(pbitmap b, unsigned int x, unsigned int y)
{
  if ( !b )
    b = _pmain;
  return GetPixel(b->DC, x, y);
}


// Address: 0x00407753; symbol: __Z8GetPixelmm
unsigned int __cdecl GetPixel(unsigned int x, unsigned int y)
{
  return GetPixel(0, x, y);
}


// Address: 0x00407775; symbol: __Z8SetPixelP6bitmapmmm
void __cdecl SetPixel(pbitmap b, unsigned int x, unsigned int y, unsigned int c)
{
  if ( !b )
    b = _pmain;
  if ( !c )
    c = _cfg;
  SetPixel(b->DC, x, y, c);
}


// Address: 0x004077C4; symbol: __Z8SetPixelmmm
void __cdecl SetPixel(unsigned int x, unsigned int y, unsigned int c)
{
  SetPixel(0, x, y, c);
}


// Address: 0x004077EE; symbol: __Z8SetPixelmm
void __cdecl SetPixel(unsigned int x, unsigned int y)
{
  SetPixel(x, y, 0);
}


// Address: 0x00407811; symbol: __Z4LineP6bitmapllllm
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


// Address: 0x00407899; symbol: __Z4Linellllm
void __cdecl Line(int x, int y, int w, int h, unsigned int c)
{
  Line(0, x, y, w, h, c);
}


// Address: 0x004078D1; symbol: __Z3BarP6bitmapllllmm
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


// Address: 0x004079AB; symbol: __Z3BarP6bitmapllllm
void __cdecl Bar(pbitmap b, int x, int y, int w, int h, unsigned int c)
{
  Bar(b, x, y, w, h, 0, c);
}


// Address: 0x004079EA; symbol: __Z3Barllllmm
void __cdecl Bar(int x, int y, int w, int h, unsigned int cfg, unsigned int cbg)
{
  Bar(0, x, y, w, h, cfg, cbg);
}


// Address: 0x00407A29; symbol: __Z3Barllllm
void __cdecl Bar(int x, int y, int w, int h, unsigned int c)
{
  Bar(x, y, w, h, 0, c);
}


// Address: 0x00407A61; symbol: __Z3Barllll
void __cdecl Bar(int x, int y, int w, int h)
{
  Bar(x, y, w, h, 0);
}


// Address: 0x00407A92; symbol: __Z5ClearP6bitmapm
void __cdecl Clear(pbitmap b, unsigned int c)
{
  if ( !b )
    b = _pmain;
  if ( !c )
    c = _cbg;
  Bar(b, 0, 0, b->Width, b->Height, 0, c);
}


// Address: 0x00407AF9; symbol: __Z5ClearP6bitmap
void __cdecl Clear(pbitmap b)
{
  Clear(b, 0);
}


// Address: 0x00407B15; symbol: __Z5Clearm
void __cdecl Clear(unsigned int c)
{
  Clear(0, c);
}


// Address: 0x00407B31; symbol: __Z5Clearv
void Clear()
{
  Clear(0);
}


// Address: 0x00407B46; symbol: __Z9CreateBMPP6bitmapmmm
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


// Address: 0x00407C48; symbol: __Z9CreateBMPP6bitmap
pbitmap __cdecl CreateBMP(pbitmap b)
{
  return CreateBMP(b, 0, 0, 0);
}


// Address: 0x00407C73; symbol: __Z9CreateBMPmmm
pbitmap __cdecl CreateBMP(unsigned int w, unsigned int h, unsigned int c)
{
  return CreateBMP(0, w, h, c);
}


// Address: 0x00407C9C; symbol: __Z9CreateBMPmm
pbitmap __cdecl CreateBMP(unsigned int w, unsigned int h)
{
  return CreateBMP(w, h, 0);
}


// Address: 0x00407CBE; symbol: __Z9CreateBMPv
pbitmap CreateBMP()
{
  return CreateBMP(0, 0);
}


// Address: 0x00407CDA; symbol: __Z10ReleaseBMPP6bitmap
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


// Address: 0x00407D65; symbol: __Z10ReleaseBMPv
void ReleaseBMP()
{
  bitmap *v0; // eax
  bitmap *v1; // eax

  v0 = GetScr();
  ReleaseBMP(v0);
  v1 = GetWin();
  ReleaseBMP(v1);
}


// Address: 0x00407D88; symbol: __Z7LoadBMPPKcm
pbitmap __cdecl LoadBMP(const char *s, unsigned int c)
{
  float v2; // ST2C_4
  long double v3; // fst7
  int v4; // ST2C_4
  int v5; // ST14_4
  UINT bh_0; // [esp+34h] [ebp-14h]
  UINT bw; // [esp+38h] [ebp-10h]
  pbitmap bmp; // [esp+3Ch] [ebp-Ch]

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


// Address: 0x00407EFC; symbol: __Z7LoadBMPPKc
pbitmap __cdecl LoadBMP(const char *s)
{
  return LoadBMP(s, 0);
}


// Address: 0x00407F17; symbol: __Z7SaveBMPP6bitmapPKc
void __cdecl SaveBMP(pbitmap b, const char *s)
{
  MultiByteToWideChar(0, 0, s, -1, _GdiWideChar, 127);
  GdiplusStartup((int)&_GdiToken, (int)&_GdiStart, 0);
  GdipCreateBitmapFromHBITMAP((int)b->Handle, 0, (int)&_GdiBitmap);
  GdipSaveImageToFile((int)_GdiBitmap, (int)_GdiWideChar, (int)&GDIImageFormatPNG, 0);
  GdipDisposeImage((int)_GdiBitmap);
  GdiplusShutdown(_GdiToken);
}


// Address: 0x00407FDD; symbol: __Z7DrawBMPP6bitmapS0_mmmmmmmmm
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


// Address: 0x0040826C; symbol: __Z7DrawBMPP6bitmapS0_mmmmmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, bd, xs, ys, ws, hs, xd, yd, wd, hd, 0);
}


// Address: 0x004082C7; symbol: __Z7DrawBMPP6bitmapS0_mmmmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(bs, bd, xs, ys, w, h, xd, yd, w, h, c);
}


// Address: 0x00408321; symbol: __Z7DrawBMPP6bitmapS0_mmmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(bs, bd, xs, ys, xd, yd, w, h, 0);
}


// Address: 0x0040836E; symbol: __Z7DrawBMPP6bitmapS0_mmmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, bd, 0, 0, 0, 0, xd, yd, wd, hd, c);
}


// Address: 0x004083CC; symbol: __Z7DrawBMPP6bitmapS0_mmmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, bd, xd, yd, wd, hd, 0);
}


// Address: 0x0040840B; symbol: __Z7DrawBMPP6bitmapS0_mmm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(bs, bd, xd, yd, 0, 0, c);
}


// Address: 0x0040844B; symbol: __Z7DrawBMPP6bitmapS0_mm
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int xd, unsigned int yd)
{
  DrawBMP(bs, bd, xd, yd, 0);
}


// Address: 0x0040847C; symbol: __Z7DrawBMPP6bitmapS0_m
void __cdecl DrawBMP(pbitmap bs, pbitmap bd, unsigned int c)
{
  DrawBMP(bs, bd, 0, 0, c);
}


// Address: 0x004084AE; symbol: __Z7DrawBMPP6bitmapS0_
void __cdecl DrawBMP(pbitmap bs, pbitmap bd)
{
  DrawBMP(bs, bd, 0);
}


// Address: 0x004084D1; symbol: __Z7DrawBMPP6bitmapmmmmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, 0, xs, ys, ws, hs, xd, yd, wd, hd, c);
}


// Address: 0x0040852C; symbol: __Z7DrawBMPP6bitmapmmmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, xs, ys, ws, hs, xd, yd, wd, hd, 0);
}


// Address: 0x00408580; symbol: __Z7DrawBMPP6bitmapmmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(bs, xs, ys, w, h, xd, yd, w, h, c);
}


// Address: 0x004085D3; symbol: __Z7DrawBMPP6bitmapmmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(bs, xs, ys, xd, yd, w, h, 0);
}


// Address: 0x00408619; symbol: __Z7DrawBMPP6bitmapmmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(bs, 0, 0, 0, 0, xd, yd, wd, hd, c);
}


// Address: 0x00408670; symbol: __Z7DrawBMPP6bitmapmmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(bs, xd, yd, wd, hd, 0);
}


// Address: 0x004086A8; symbol: __Z7DrawBMPP6bitmapmmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(bs, xd, yd, 0, 0, c);
}


// Address: 0x004086E1; symbol: __Z7DrawBMPP6bitmapmm
void __cdecl DrawBMP(pbitmap bs, unsigned int xd, unsigned int yd)
{
  DrawBMP(bs, xd, yd, 0);
}


// Address: 0x0040870B; symbol: __Z7DrawBMPP6bitmapm
void __cdecl DrawBMP(pbitmap bs, unsigned int c)
{
  DrawBMP(bs, 0, 0, c);
}


// Address: 0x00408736; symbol: __Z7DrawBMPP6bitmap
void __cdecl DrawBMP(pbitmap bs)
{
  DrawBMP(bs, 0);
}


// Address: 0x00408752; symbol: __Z7DrawBMPmmmmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(0, xs, ys, ws, hs, xd, yd, wd, hd, c);
}


// Address: 0x004087A6; symbol: __Z7DrawBMPmmmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int ws, unsigned int hs, unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(0, xs, ys, ws, hs, xd, yd, wd, hd);
}


// Address: 0x004087F3; symbol: __Z7DrawBMPmmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h, unsigned int c)
{
  DrawBMP(0, xs, ys, xd, yd, w, h, c);
}


// Address: 0x00408839; symbol: __Z7DrawBMPmmmmmm
void __cdecl DrawBMP(unsigned int xs, unsigned int ys, unsigned int xd, unsigned int yd, unsigned int w, unsigned int h)
{
  DrawBMP(0, xs, ys, xd, yd, w, h);
}


// Address: 0x00408878; symbol: __Z7DrawBMPmmmmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd, unsigned int c)
{
  DrawBMP(0, xd, yd, wd, hd, c);
}


// Address: 0x004088B0; symbol: __Z7DrawBMPmmmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int wd, unsigned int hd)
{
  DrawBMP(0, xd, yd, wd, hd);
}


// Address: 0x004088E1; symbol: __Z7DrawBMPmmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd, unsigned int c)
{
  DrawBMP(0, xd, yd, c);
}


// Address: 0x0040890B; symbol: __Z7DrawBMPmm
void __cdecl DrawBMP(unsigned int xd, unsigned int yd)
{
  DrawBMP(0, xd, yd);
}


// Address: 0x0040892E; symbol: __Z7DrawBMPm
void __cdecl DrawBMP(unsigned int c)
{
  DrawBMP(0, c);
}


// Address: 0x0040894A; symbol: __Z7DrawBMPv
void DrawBMP()
{
  DrawBMP(0);
}


// Address: 0x0040895F; symbol: __Z2HIy
unsigned int __cdecl HI(uint64_t val)
{
  return HIDWORD(val);
}


// Address: 0x0040897D; symbol: __Z2LOy
unsigned int __cdecl LO(uint64_t val)
{
  return val;
}


// Address: 0x00408994; symbol: __Z7SendMsgv
void SendMsg()
{
  TranslateMessage(&_mst);
  DispatchMessageA(&_mst);
}


// Address: 0x004089BB; symbol: __Z9CustomMsgv
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


// Address: 0x00408A68; symbol: __Z9IsNextMsgv
BOOL IsNextMsg()
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


// Address: 0x00408B62; symbol: __Z10GetNextMsgv
UINT GetNextMsg()
{
  return _ms.message;
}


// Address: 0x00408B6C; symbol: __Z11WaitNextMsgv
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


// Address: 0x00408BBB; symbol: __Z5IsMsgPKmm
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


// Address: 0x00408BFF; symbol: __Z6GetMsgPKmm
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


// Address: 0x00408C5F; symbol: __Z7WaitMsgPKmm
uint64_t __cdecl WaitMsg(const unsigned int *uM, unsigned int length)
{
  do
    WaitNextMsg();
  while ( !IsMsg(uM, length) );
  return GetMsg(uM, length);
}


// Address: 0x00408C99; symbol: __Z5IsMsgm
bool __cdecl IsMsg(unsigned int uM)
{
  unsigned int ums[1]; // [esp+14h] [ebp-4h]

  ums[0] = uM;
  return IsMsg(ums, 1u);
}


// Address: 0x00408CBA; symbol: __Z6GetMsgm
uint64_t __cdecl GetMsg(unsigned int uM)
{
  unsigned int ums[1]; // [esp+14h] [ebp-4h]

  ums[0] = uM;
  return GetMsg(ums, 1u);
}


// Address: 0x00408CDB; symbol: __Z7WaitMsgm
uint64_t __cdecl WaitMsg(unsigned int uM)
{
  unsigned int ums[1]; // [esp+1Ch] [ebp-Ch]

  ums[0] = uM;
  return WaitMsg(ums, 1u);
}


// Address: 0x00408CFC; symbol: __Z5IsKeym
bool __cdecl IsKey(unsigned int k)
{
  return IsMsg(0x100u) && (!k || GetKey() == k);
}


// Address: 0x00408D30; symbol: __Z5IsKeyv
bool IsKey()
{
  return IsKey(0);
}


// Address: 0x00408D44; symbol: __Z6GetKeyv
unsigned int GetKey()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x100u);
  return HI(v0);
}


// Address: 0x00408D64; symbol: __Z7WaitKeym
unsigned int __cdecl WaitKey(unsigned int k)
{
  while ( !IsKey() )
    WaitNextMsg();
  return GetKey();
}


// Address: 0x00408D84; symbol: __Z7WaitKeyv
unsigned int WaitKey()
{
  return WaitKey(0);
}


// Address: 0x00408D98; symbol: __Z7IsMousem
bool __cdecl IsMouse(unsigned int m)
{
  return IsMsg(_bdn, 3u) && (!m || GetMouse() == m);
}


// Address: 0x00408DD4; symbol: __Z7IsMousev
bool IsMouse()
{
  return IsMouse(0);
}


// Address: 0x00408DE8; symbol: __Z8GetMousev
unsigned int GetMouse()
{
  uint64_t v0; // rax

  v0 = GetMsg(_bdn, 3u);
  return HI(v0);
}


// Address: 0x00408E10; symbol: __Z9WaitMousem
unsigned int __cdecl WaitMouse(unsigned int m)
{
  while ( !IsMouse() )
    WaitNextMsg();
  return GetMouse();
}


// Address: 0x00408E30; symbol: __Z9WaitMousev
unsigned int WaitMouse()
{
  return WaitMouse(0);
}


// Address: 0x00408E44; symbol: __Z11IsMouseLeftv
bool IsMouseLeft()
{
  return IsMsg(0x201u);
}


// Address: 0x00408E58; symbol: __Z13WaitMouseLeftv
void WaitMouseLeft()
{
  WaitMsg(0x201u);
}


// Address: 0x00408E6D; symbol: __Z13IsMouseMiddlev
bool IsMouseMiddle()
{
  return IsMsg(0x207u);
}


// Address: 0x00408E81; symbol: __Z15WaitMouseMiddlev
void WaitMouseMiddle()
{
  WaitMsg(0x207u);
}


// Address: 0x00408E96; symbol: __Z12IsMouseRightv
bool IsMouseRight()
{
  return IsMsg(0x204u);
}


// Address: 0x00408EAA; symbol: __Z14WaitMouseRightv
void WaitMouseRight()
{
  WaitMsg(0x204u);
}


// Address: 0x00408EBF; symbol: __Z12IsMouseWheelv
bool IsMouseWheel()
{
  return IsMsg(0x20Au);
}


// Address: 0x00408ED3; symbol: __Z13GetMouseWheelv
unsigned int GetMouseWheel()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x20Au);
  return HI(v0) >> 16;
}


// Address: 0x00408EF9; symbol: __Z14WaitMouseWheelv
void WaitMouseWheel()
{
  WaitMsg(0x20Au);
}


// Address: 0x00408F0E; symbol: __Z11IsMouseMovev
bool IsMouseMove()
{
  return IsMsg(0x200u);
}


// Address: 0x00408F22; symbol: __Z12GetMouseMovev
unsigned int GetMouseMove()
{
  uint64_t v0; // rax

  v0 = GetMsg(0x200u);
  return LO(v0);
}


// Address: 0x00408F42; symbol: __Z13WaitMouseMovev
unsigned int WaitMouseMove()
{
  uint64_t v0; // rax

  v0 = WaitMsg(0x200u);
  return LO(v0);
}


// Address: 0x00408F62; symbol: __Z10IsDropFilev
bool IsDropFile()
{
  return IsMsg(0x233u);
}


// Address: 0x00408F76; symbol: __Z12GetMouseAbsXv
LONG GetMouseAbsX()
{
  POINT p; // [esp+18h] [ebp-10h]

  GetCursorPos(&p);
  return p.x;
}


// Address: 0x00408F8F; symbol: __Z12GetMouseAbsYv
LONG GetMouseAbsY()
{
  POINT p; // [esp+18h] [ebp-10h]

  GetCursorPos(&p);
  return p.y;
}


// Address: 0x00408FA8; symbol: __Z12GetMouseWinXv
int GetMouseWinX()
{
  LONG v0; // ebx

  v0 = GetMouseAbsX();
  return v0 - GetPosX();
}


// Address: 0x00408FC5; symbol: __Z12GetMouseWinYv
int GetMouseWinY()
{
  LONG v0; // ebx

  v0 = GetMouseAbsY();
  return v0 - GetPosY();
}


// Address: 0x00408FE2; symbol: __Z12GetMousePosXv
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


// Address: 0x0040900F; symbol: __Z12GetMousePosYv
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


// Address: 0x00409041; symbol: __Z7MsgBoxWPKsS0_m
unsigned int __cdecl MsgBoxW(const __int16 *s, const __int16 *title, unsigned int i)
{
  return MessageBoxW(0, (LPCWSTR)s, (LPCWSTR)title, i);
}


// Address: 0x0040906D; symbol: __Z6MsgBoxPKcS0_m
unsigned int __cdecl MsgBox(const char *s, const char *title, unsigned int i)
{
  return MessageBoxA(0, s, title, i);
}


// Address: 0x00409099; symbol: __Z7MsgBoxWPKsS0_
void __cdecl MsgBoxW(const __int16 *s, const __int16 *title)
{
  MsgBoxW(s, title, 0);
}


// Address: 0x004090BC; symbol: __Z6MsgBoxPKcS0_
void __cdecl MsgBox(const char *s, const char *title)
{
  MsgBox(s, title, 0);
}


// Address: 0x004090DF; symbol: __Z7MsgBoxWPKs
void __cdecl MsgBoxW(const __int16 *s)
{
  MsgBoxW(s, &title);
}


// Address: 0x004090FB; symbol: __Z6MsgBoxPKc
void __cdecl MsgBox(const char *s)
{
  MsgBox(s, ::s);
}


// Address: 0x00409117; symbol: __Z5Delaym
void __cdecl Delay(unsigned int t)
{
  Sleep(t);
}


// Address: 0x0040912E; symbol: __Z5Delayv
void Delay()
{
  Delay(1u);
}


// Address: 0x00409143; symbol: __Z10SendStringv
unsigned int SendString()
{
  mciSendStringA(command_in, command_out, 0x7Fu, 0);
  return strtoul(command_out, 0, 10);
}


// Address: 0x0040918E; symbol: __Z9LoadAudioPKcS0_
unsigned int __cdecl LoadAudio(const char *s1, const char *s2)
{
  sprintf(command_in, "open \"%s\"%s alias s%lu", s1, s2, ++_cid);
  SendString();
  return _cid;
}


// Address: 0x004091D8; symbol: __Z9LoadAudioPKc
unsigned int __cdecl LoadAudio(const char *s)
{
  return LoadAudio(s, ::s);
}


// Address: 0x004091F3; symbol: __Z9PlayAudiomPKcb
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


// Address: 0x00409237; symbol: __Z9StopAudiom
void __cdecl StopAudio(unsigned int id)
{
  SetAudioPos(id, 0, 0);
  sprintf(command_in, "stop s%lu", id);
  SendString();
}


// Address: 0x0040927B; symbol: __Z10PauseAudiom
void __cdecl PauseAudio(unsigned int id)
{
  sprintf(command_in, "pause s%lu", id);
  SendString();
}


// Address: 0x004092A4; symbol: __Z11ResumeAudiom
void __cdecl ResumeAudio(unsigned int id)
{
  sprintf(command_in, "resume s%lu", id);
  SendString();
}


// Address: 0x004092CD; symbol: __Z12ReleaseAudiom
void __cdecl ReleaseAudio(unsigned int id)
{
  sprintf(command_in, "close s%lu", id);
  SendString();
}


// Address: 0x004092F6; symbol: __Z11GetAudioPosm
unsigned int __cdecl GetAudioPos(unsigned int id)
{
  sprintf(command_in, "status s%lu position", id);
  return SendString();
}


// Address: 0x0040931E; symbol: __Z11SetAudioPosmmb
void __cdecl SetAudioPos(unsigned int id, unsigned int pos, bool b)
{
  sprintf(command_in, "seek s%lu to %lu", id, pos);
  SendString();
  PlayAudio(id, s, b);
}


// Address: 0x0040936F; symbol: __Z11GetAudioLenm
unsigned int __cdecl GetAudioLen(unsigned int id)
{
  sprintf(command_in, "status s%lu length", id);
  return SendString();
}


// Address: 0x00409397; symbol: __Z6IsFilePKc
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


// Address: 0x004093DF; symbol: __Z13UTF8ToUnicodePhPj
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


// Address: 0x00409554; symbol: __Z14UnicodeToUTF16jPt
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


// Address: 0x004095BD; symbol: __Z41__static_initialization_and_destruction_0ii
void __cdecl __static_initialization_and_destruction_0(int __initialize_p, int __priority)
{
  BOOL v2; // [esp+Ch] [ebp-Ch]

  if ( __initialize_p == 1 && __priority == 0xFFFF )
    weak___ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii___ZN7Gdiplus11GdiplusBasedlEPv(
      &_GdiStart,
      0,
      0,
      0,
      v2);
}


// Address: 0x004095F9; symbol: __GLOBAL__sub_I_version
void _GLOBAL__sub_I_version()
{
  __static_initialization_and_destruction_0(1, 0xFFFF);
}


// Address: 0x00409618; symbol: __ZN3LanC1Ev
void __thiscall Lan::Lan(Lan *const this)
{
  Lan *v1; // ST1C_4
  const char *v2; // eax

  v1 = this;
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
  v1->LAN_SET = v1->LAN_HELP + 20;
  v1->LAN_TUT_ = v1->LAN_SET + 23;
  v1->LAN_TUT = v1->LAN_TUT_ + 1;
  v1->LAN_MODE = v1->LAN_TUT + 15;
  v1->LAN_TUT_QUIT = v1->LAN_MODE + 5;
  v1->LAN_HELP_MENU = v1->LAN_TUT_QUIT + 3;
  v1->LAN_HELP_TITLE = v1->LAN_HELP_MENU + 20;
  this->data = (__int16 *)calloc(0x2710u, 2u);
  v1->landata = (__int16 *)calloc(0x2710u, 2u);
  v1->landatap = (__int16 **)calloc(0x3E8u, 4u);
  v2 = Lan::getsyslan(v1);
  Lan::initlan(v1, v2);
}


// Address: 0x00409860; symbol: __ZN3Lan9getsyslanEv
const char *__thiscall Lan::getsyslan(Lan *const this)
{
  Lan *thisa; // [esp+Ch] [ebp-1Ch]
  int lansysid; // [esp+14h] [ebp-14h]
  int k; // [esp+18h] [ebp-10h]
  const char *lansys; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  lansys = this->lanshort[6];
  lansysid = (unsigned __int16)GetUserDefaultUILanguage();
  for ( k = 0; k <= 29; ++k )
  {
    if ( thisa->lanshortid[k] == lansysid )
      lansys = thisa->lanshort[k];
  }
  return lansys;
}


// Address: 0x004098B4; symbol: __ZN3Lan7initlanEPKc
void __thiscall Lan::initlan(Lan *const this, const char *lan)
{
  char *v2; // eax
  bool v3; // al
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

  thisa = this;
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


// Address: 0x00409DAE; symbol: __ZN3Lan6getlanEl
__int16 *__thiscall Lan::getlan(Lan *const this, int id)
{
  return this->landatap[id];
}


// Address: 0x00409DD0; symbol: __ZN3RegC1Ev
void __thiscall Reg::Reg(Reg *const this)
{
  Reg::openreg(this);
}


// Address: 0x00409DE6; symbol: __ZN3RegD1Ev
void __thiscall Reg::~Reg(Reg *const this)
{
  Reg::closereg(this);
}


// Address: 0x00409DFC; symbol: __ZN3Reg7openregEv
void __thiscall Reg::openreg(Reg *const this)
{
  Reg *v1; // ST3C_4

  v1 = this;
  RegCreateKeyExA(HKEY_CURRENT_USER, "SoftWare\\MineSweeperRush\\20250412", 0, 0, 0, 0xF003Fu, 0, &this->regkey, 0);
  RegCreateKeyExA(
    HKEY_CURRENT_USER,
    "SoftWare\\MineSweeperRush\\20250412\\board",
    0,
    0,
    0,
    0xF003Fu,
    0,
    &v1->regkey_,
    0);
}


// Address: 0x00409EA8; symbol: __ZN3Reg8closeregEv
void __thiscall Reg::closereg(Reg *const this)
{
  Reg *v1; // ST1C_4

  v1 = this;
  RegCloseKey(this->regkey);
  RegCloseKey(v1->regkey_);
}


// Address: 0x00409ED6; symbol: __ZN3Reg6setregEP6HKEY__PKcl
void __thiscall Reg::setreg(Reg *const this, HKEY key, const char *name, int value)
{
  RegSetValueExA(key, name, 0, 4u, (const BYTE *)&value, 4u);
}


// Address: 0x00409F18; symbol: __ZN3Reg6getregEP6HKEY__PKcPl
void __thiscall Reg::getreg(Reg *const this, HKEY key, const char *name, int *value)
{
  int temp; // [esp+3Ch] [ebp-Ch]

  this->cb = 4;
  if ( RegQueryValueExA(key, name, 0, &this->tp, (LPBYTE)&temp, &this->cb) == 0 )
    *value = temp;
}


// Address: 0x00409F7A; symbol: __ZN3Reg7setreg_EP6HKEY__PKcPc
void __thiscall Reg::setreg_(Reg *const this, HKEY key, const char *name, char *value)
{
  RegSetValueExA(key, name, 0, 3u, (const BYTE *)value, 0x4000u);
}


// Address: 0x00409FBC; symbol: __ZN3Reg7getreg_EP6HKEY__PKcPc
void __thiscall Reg::getreg_(Reg *const this, HKEY key, const char *name, char *value)
{
  int v4; // eax
  void *v5; // esp
  DWORD cbData; // [esp+3Ch] [ebp-400Ch]
  BYTE Data; // [esp+40h] [ebp-4008h]

  v5 = alloca(v4);
  cbData = 0x4000;
  if ( RegQueryValueExA(key, name, 0, &this->tp, &Data, &cbData) == 0 )
    memcpy(value, &Data, 0x4000u);
}


// Address: 0x0040A048; symbol: __ZN5SoundC1Ev
void __thiscall Sound::Sound(Sound *const this)
{
  this->sMusic = 0;
  this->sSounds[0] = (const char *)&unk_42878C;
  this->sSounds[1] = "Lose";
  this->sSounds[2] = "Error";
  this->sSounds[3] = "Left";
  this->sSounds[4] = "Right";
  this->sSounds[5] = "Flag";
  this->sSounds[6] = "New";
  this->sSounds[7] = "Solve";
  this->sWin = 0;
  this->sLose = 1;
  this->sError = 2;
  this->sLeft = 3;
  this->sRight = 4;
  this->sFlag = 5;
  this->sNew = 6;
  this->sSolve = 7;
  this->nummusic = 0;
  this->soundb = 1;
  this->musicb = 1;
  this->musici = -256;
}


// Address: 0x0040A120; symbol: __ZN5Sound9initsoundEv
void __thiscall Sound::initsound(Sound *const this)
{
  Sound *v1; // ST0C_4

  v1 = this;
  Sound::loadsound(this);
  Sound::loadmusic(v1);
  Sound::playmusic(v1);
  painttitles = 0;
}


// Address: 0x0040A154; symbol: __ZN5Sound9loadsoundEv
void __thiscall Sound::loadsound(Sound *const this)
{
  unsigned int v1; // ecx
  Sound *thisa; // [esp+1Ch] [ebp-11Ch]
  char sPath[260]; // [esp+28h] [ebp-110h]
  int id; // [esp+12Ch] [ebp-Ch]

  thisa = this;
  if ( (unsigned __int8)IsWin() )
  {
    for ( id = 0; id <= 7; ++id )
    {
      sprintf(sPath, "./data/wav/%s.wav", thisa->sSounds[id]);
      v1 = LoadAudio(sPath, &s2);
      thisa->sSound[id] = v1;
    }
  }
}


// Address: 0x0040A1D0; symbol: __ZN5Sound9loadmusicEv
void __thiscall Sound::loadmusic(Sound *const this)
{
  unsigned int *v1; // ebx
  Sound *thisa; // [esp+1Ch] [ebp-11Ch]
  char sPath[260]; // [esp+20h] [ebp-118h]
  unsigned int *sMusic_; // [esp+124h] [ebp-14h]
  MCIERROR ret; // [esp+128h] [ebp-10h]
  int k; // [esp+12Ch] [ebp-Ch]

  thisa = this;
  ret = mciSendStringA("open new type sequencer alias miditest", 0, 0, 0);
  mciSendStringA("close miditest", 0, 0, 0);
  if ( ret )
  {
    thisa->nummusic = 0;
    for ( k = 0; (unsigned __int8)IsWin(); ++k )
    {
      sprintf(sPath, "./data/mid/music%ld.mid", k + 1);
      if ( !IsFile(sPath) )
        break;
      sMusic_ = (unsigned int *)realloc(thisa->sMusic, 4 * (thisa->nummusic + 1));
      if ( !sMusic_ )
        break;
      thisa->sMusic = sMusic_;
      painttitles = (pbitmap)sPath;
      painttitleb = 2;
      v1 = &thisa->sMusic[thisa->nummusic];
      *v1 = LoadAudio(sPath, " type sequencer");
      ++thisa->nummusic;
    }
  }
}


// Address: 0x0040A340; symbol: __ZN5Sound9playsoundEl
void __thiscall Sound::playsound(Sound *const this, int id)
{
  bool v2; // al
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  v2 = (unsigned __int8)IsWin() && thisa->soundb;
  if ( v2 )
    SetAudioPos(thisa->sSound[id], 0, 0);
}


// Address: 0x0040A394; symbol: __ZN5Sound11switchsoundEv
void __thiscall Sound::switchsound(Sound *const this)
{
  bool v1; // al
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  this->soundb ^= 1u;
  v1 = (unsigned __int8)IsWin() && thisa->soundb;
  if ( v1 )
    Sound::playsound(thisa, thisa->sLeft);
}


// Address: 0x0040A3EC; symbol: __ZN5Sound9playmusicEv
void __thiscall Sound::playmusic(Sound *const this)
{
  bool v1; // al
  Sound *thisa; // [esp+1Ch] [ebp-1Ch]
  int musici_; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  if ( this->musicb )
  {
    v1 = (unsigned __int8)IsWin() && thisa->nummusic > 0;
    if ( v1 )
    {
      if ( thisa->musici != -256 && thisa->nummusic != 1 )
      {
        musici_ = rand() % (thisa->nummusic - 1);
        if ( thisa->musici <= musici_ )
          ++musici_;
        thisa->musici = musici_;
      }
      else
      {
        thisa->musici = 0;
      }
      thisa->musictime = GetTimeR();
      SetAudioPos(thisa->sMusic[thisa->musici], 0, 0);
    }
    else
    {
      thisa->musici = -256;
      thisa->musictime = 0.0;
    }
  }
}


// Address: 0x0040A4CC; symbol: __ZN5Sound10checkmusicEv
void __thiscall Sound::checkmusic(Sound *const this)
{
  unsigned int v1; // ebx
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  if ( this->musicb && this->musici >= 0 && this->musici < this->nummusic && GetTimeR() > this->musictime )
  {
    v1 = GetAudioPos(thisa->sMusic[thisa->musici]);
    if ( v1 < GetAudioLen(thisa->sMusic[thisa->musici]) )
      thisa->musictime = thisa->musictime + 10.0;
    else
      Sound::playmusic(thisa);
  }
}


// Address: 0x0040A584; symbol: __ZN5Sound11switchmusicEv
void __thiscall Sound::switchmusic(Sound *const this)
{
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  this->musicb ^= 1u;
  if ( this->musicb )
  {
    Sound::playmusic(this);
  }
  else if ( this->musici >= 0 && this->musici < this->nummusic )
  {
    StopAudio(this->sMusic[this->musici]);
  }
  if ( thisa->soundb )
    Sound::playsound(thisa, thisa->sLeft);
}


// Address: 0x0040A610; symbol: __ZN5SteamC1Ev
void __thiscall Steam::Steam(Steam *const this)
{
  Steam *v1; // ST1C_4

  v1 = this;
  Lan::Lan(&this->lan);
  v1->appid = 3665840;
  v1->cheatb = 0;
  v1->achgenstart = 0;
  v1->achgencustom = 1;
  v1->achgenmode = 2;
  v1->achgenpause = 3;
  v1->achgenhelp = 4;
  v1->achhidcheat = 5;
  v1->achhidedge = 6;
  v1->achhidmark = 7;
  v1->achhidright = 8;
  v1->achhidalive = 9;
  v1->achcumdead1 = 10;
  v1->achcumdead10 = 11;
  v1->achcumdead100 = 12;
  v1->achcumdead1000 = 13;
  v1->achcumfour1 = 14;
  v1->achcumfour10 = 15;
  v1->achcumfour100 = 16;
  v1->achcumfour1000 = 17;
  v1->achcumline100 = 18;
  v1->achcumline300 = 19;
  v1->achcumline600 = 20;
  v1->achcumline1000 = 21;
  v1->achcumtotal10 = 22;
  v1->achcumtotal100 = 23;
  v1->achcumtotal1000 = 24;
  v1->achcumtotal10000 = 25;
  qmemcpy(v1->achs, off_427140, sizeof(v1->achs));
  v1->scrdead = 0;
  v1->scrfour = 1;
  v1->scrtotal = 2;
  v1->scrline = 3;
  v1->scrline1 = 4;
  v1->scrline2 = 5;
  v1->scrline3 = 6;
  v1->scrindexline = 0;
  v1->scrindexmdb = 3;
  v1->scrindexnomiss = 6;
  v1->scrindextetris = 9;
  v1->scrindexmiss = 12;
  qmemcpy(v1->scrs, off_4271C0, sizeof(v1->scrs));
  v1->newrecord = 0;
  v1->leads[0] = "1_TOP";
  v1->leads[1] = "2_TOP";
  v1->leads[2] = "3_TOP";
  v1->leads[3] = "1_TOP_N";
  v1->leads[4] = "2_TOP_N";
  v1->leads[5] = "3_TOP_N";
  v1->leads[6] = "1_TOP_D";
  v1->leads[7] = "2_TOP_D";
  v1->leads[8] = "3_TOP_D";
  v1->leads[9] = "1_TOP_T";
  v1->leads[10] = "2_TOP_T";
  v1->leads[11] = "3_TOP_T";
  v1->leads[12] = "1_TOP_M";
  v1->leads[13] = "2_TOP_M";
  v1->leads[14] = "3_TOP_M";
  v1->leadk_[0] = 20;
  v1->leadk_[1] = 15;
  v1->leadk_[2] = 1;
  v1->leadfailed = 1;
  v1->leadsn = 0;
  v1->waittime = 5.0;
  memset(v1->lead, 0, 0x78u);
  memset(v1->lead_, 0, 0x168u);
  memset(&v1->leadr, 0, 0x10u);
  memset(&v1->leadu, 0, 0x20u);
  memset(&v1->leadd, 0, 0x18u);
  memset(v1->leadb, 0, 0x78u);
  memset(v1->leaden, 0, 0x168u);
  v1->leadsn = (LeaderboardEntry_t (*)[15][20])calloc(3u, 0x2580u);
  Steam::initsteam(v1);
  Steam::loadlan(v1);
}


// Address: 0x0040AA96; symbol: __ZN5SteamD1Ev
void __thiscall Steam::~Steam(Steam *const this)
{
  Steam::exitsteam(this);
}


// Address: 0x0040AAAC; symbol: __ZN5Steam9initsteamEv
void __thiscall Steam::initsteam(Steam *const this)
{
  __int16 *v1; // ebx
  __int16 *v2; // eax
  __int16 *v3; // ebx
  __int16 *v4; // eax
  ISteamUtils *v5; // eax
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  if ( (unsigned __int8)_SteamAPI_RestartAppIfNecessary(this->appid) )
  {
    v1 = Lan::getlan(&thisa->lan, thisa->lan.LAN_TITLE);
    v2 = Lan::getlan(&thisa->lan, thisa->lan.LAN_STEAM_LAUNCH);
    MsgBoxW(v2, v1, 0x40u);
  }
  thisa->steamb = _SteamAPI_Init();
  if ( thisa->steamb != 1 )
  {
    v3 = Lan::getlan(&thisa->lan, thisa->lan.LAN_TITLE);
    v4 = Lan::getlan(&thisa->lan, thisa->lan.LAN_STEAM_FAIL);
    MsgBoxW(v4, v3, 0x30u);
  }
  if ( thisa->steamb )
  {
    v5 = SteamUtils();
    if ( (*(int (__fastcall **)(ISteamUtils *))(*(_DWORD *)v5 + 36))(v5) != thisa->appid )
      MsgBox(
        "The old game MineSweeper Tetris is retired, please download the new MineSweeper Rush from Steam Store! \n"
        "https://store.steampowered.com/app/3665840",
        "MineSweeper Rush",
        0x40u);
  }
}


// Address: 0x0040ABD4; symbol: __ZN5Steam7loadlanEv
void __thiscall Steam::loadlan(Steam *const this)
{
  ISteamUtils *v1; // eax
  ISteamApps *v2; // eax
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  const char *langame; // [esp+28h] [ebp-10h]
  const char *lanui; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  if ( this->steamb )
  {
    v1 = SteamUtils();
    lanui = (const char *)(*(int (__fastcall **)(ISteamUtils *))(*(_DWORD *)v1 + 92))(v1);
    v2 = SteamApps();
    langame = (const char *)(*(int (__fastcall **)(ISteamApps *))(*(_DWORD *)v2 + 16))(v2);
    if ( !strcmp(langame, thisa->lan.lanshort[23]) )
      Lan::initlan(&thisa->lan, lanui);
    else
      Lan::initlan(&thisa->lan, langame);
  }
}


// Address: 0x0040AC56; symbol: __ZN5Steam9exitsteamEv
void __thiscall Steam::exitsteam(Steam *const this)
{
  ISteamUserStats *v1; // eax

  if ( this->steamb )
  {
    v1 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *))(*(_DWORD *)v1 + 40))(v1);
    _SteamAPI_Shutdown();
  }
}


// Address: 0x0040AC88; symbol: __ZN5Steam9loadsteamEv
void __thiscall Steam::loadsteam(Steam *const this)
{
  ISteamUserStats *v1; // eax
  __int16 *v2; // ebx
  __int16 *v3; // eax
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  if ( this->steamb )
  {
    v1 = SteamUserStats();
    if ( (**(unsigned __int8 (__fastcall ***)(ISteamUserStats *))v1)(v1) ^ 1 )
    {
      v2 = Lan::getlan(&thisa->lan, thisa->lan.LAN_TITLE);
      v3 = Lan::getlan(&thisa->lan, thisa->lan.LAN_STEAM_Status);
      MsgBoxW(v3, v2, 0x30u);
    }
    else
    {
      Steam::loadach(thisa);
      Steam::loadscr(thisa);
      Steam::loadlead(thisa);
      painttitles = 0;
    }
  }
}


// Address: 0x0040AD30; symbol: __ZN5Steam8resetachEv
void __thiscall Steam::resetach(Steam *const this)
{
  ISteamUserStats *v1; // eax

  if ( this->steamb )
  {
    v1 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *, _DWORD))(*(_DWORD *)v1 + 84))(v1, *(_DWORD *)(*(_DWORD *)v1 + 84));
  }
}


// Address: 0x0040AD64; symbol: __ZN5Steam7loadachEv
void __thiscall Steam::loadach(Steam *const this)
{
  ISteamUserStats *v1; // eax
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  int achid; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  if ( this->steamb )
  {
    painttitles = (pbitmap)"Load Achievement";
    painttitleb = 2;
    for ( achid = 0; achid <= 25; ++achid )
    {
      v1 = SteamUserStats();
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v1 + 24))(
        v1,
        thisa->lan.lanshort[achid + 112 + 2],
        thisa->lan.lanshort[achid + 112 + 2]);
    }
  }
}


// Address: 0x0040ADE2; symbol: __ZN5Steam6addachEl
void __thiscall Steam::addach(Steam *const this, int achid)
{
  ISteamUserStats *v2; // eax
  const char *v3; // ST04_4
  ISteamUserStats *v4; // eax
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  if ( this->steamb && this->achb[achid] != 1 && (this->cheatb != 1 || this->achhidcheat == achid) )
  {
    v2 = SteamUserStats();
    v3 = thisa->lan.lanshort[achid + 112 + 2];
    (*(void (__fastcall **)(ISteamUserStats *))(*(_DWORD *)v2 + 28))(v2);
    v4 = SteamUserStats();
    (*(void (__fastcall **)(ISteamUserStats *, _DWORD))(*(_DWORD *)v4 + 40))(v4, *(_DWORD *)(*(_DWORD *)v4 + 40));
    thisa->achb[achid] = 1;
  }
}


// Address: 0x0040AE7C; symbol: __ZN5Steam8checkachElllllllll
void __thiscall Steam::checkach(Steam *const this, int scrid, int d, int c, int b, int a, int a_d, int a_c, int a_b, int a_a)
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
            Steam::addach(this, a_a);
        }
        else
        {
          Steam::addach(this, a_b);
        }
      }
      else
      {
        Steam::addach(this, a_c);
      }
    }
    else
    {
      Steam::addach(this, a_d);
    }
  }
}


// Address: 0x0040AF42; symbol: __ZN5Steam7loadscrEv
void __thiscall Steam::loadscr(Steam *const this)
{
  ISteamUserStats *v1; // eax
  ISteamUserStats *v2; // eax
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  int scrid; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  if ( this->steamb )
  {
    painttitles = (pbitmap)"Load Status";
    painttitleb = 2;
    for ( scrid = 0; scrid <= 18; ++scrid )
    {
      thisa->lan.lanshort[scrid + 176 + 2] = (const char *)-1;
      v1 = SteamUserStats();
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v1 + 8))(
        v1,
        thisa->lan.lanshort[scrid + 156 + 3],
        thisa->lan.lanshort[scrid + 156 + 3]);
      if ( (_DWORD)thisa->lan.lanshort[scrid + 176 + 2] < 0 )
      {
        v2 = SteamUserStats();
        (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v2 + 8))(
          v2,
          thisa->lan.lanshort[scrid + 156 + 3],
          thisa->lan.lanshort[scrid + 156 + 3]);
      }
      if ( (_DWORD)thisa->lan.lanshort[scrid + 176 + 2] < 0 )
      {
        thisa->lan.lanshort[scrid + 176 + 2] = 0;
        thisa->steamb = 0;
      }
    }
    Steam::setlead(thisa);
  }
}


// Address: 0x0040B07E; symbol: __ZN5Steam6setscrEl
void __thiscall Steam::setscr(Steam *const this, int scrid)
{
  ISteamUserStats *v2; // eax
  long double v3; // fst7
  Steam *thisa; // [esp+3Ch] [ebp-1Ch]

  thisa = this;
  if ( this->steamb )
  {
    if ( (_DWORD)this->lan.lanshort[scrid + 176 + 2] > 0 )
    {
      v2 = SteamUserStats();
      v3 = *(float *)&thisa->lan.lanshort[scrid + 176 + 2];
      (*(void (__fastcall **)(ISteamUserStats *, const char *, const char *))(*(_DWORD *)v2 + 16))(
        v2,
        thisa->lan.lanshort[scrid + 156 + 3],
        thisa->lan.lanshort[scrid + 156 + 3]);
    }
    if ( thisa->scrdead == scrid )
    {
      Steam::checkach(
        thisa,
        thisa->scrdead,
        1000,
        100,
        10,
        1,
        thisa->achcumdead1000,
        thisa->achcumdead100,
        thisa->achcumdead10,
        thisa->achcumdead1);
    }
    else if ( thisa->scrfour == scrid )
    {
      Steam::checkach(
        thisa,
        thisa->scrfour,
        1000,
        100,
        10,
        1,
        thisa->achcumfour1000,
        thisa->achcumfour100,
        thisa->achcumfour10,
        thisa->achcumfour1);
    }
    else if ( thisa->scrtotal == scrid )
    {
      Steam::checkach(
        thisa,
        thisa->scrtotal,
        10000,
        1000,
        100,
        10,
        thisa->achcumtotal10000,
        thisa->achcumtotal1000,
        thisa->achcumtotal100,
        thisa->achcumtotal10);
    }
    else if ( thisa->scrline == scrid )
    {
      Steam::checkach(
        thisa,
        thisa->scrline,
        1000,
        600,
        300,
        100,
        thisa->achcumline1000,
        thisa->achcumline600,
        thisa->achcumline300,
        thisa->achcumline100);
    }
  }
}


// Address: 0x0040B2F8; symbol: __ZN5Steam6addscrElll
void __thiscall Steam::addscr(Steam *const this, int scrid, int val, int mode)
{
  if ( this->steamb && this->cheatb != 1 && mode > 0 )
  {
    this->lan.lanshort[scrid + 176 + 2] += val;
    Steam::setscr(this, scrid);
  }
}


// Address: 0x0040B364; symbol: __ZN5Steam6maxscrEll
void __thiscall Steam::maxscr(Steam *const this, int val, int scrline__)
{
  const char *v3; // eax
  Steam *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  if ( this->steamb && (_DWORD)this->lan.lanshort[scrline__ + 176 + 2] < val )
  {
    this->lan.lanshort[scrline__ + 176 + 2] = (const char *)val;
    Steam::setscr(this, scrline__);
    if ( scrline__ <= 6 )
    {
      if ( (_DWORD)thisa->lan.lanshort[thisa->scrline + 176 + 2] <= (_DWORD)thisa->lan.lanshort[scrline__ + 176 + 2] )
        v3 = thisa->lan.lanshort[scrline__ + 176 + 2];
      else
        v3 = thisa->lan.lanshort[thisa->scrline + 176 + 2];
      thisa->lan.lanshort[thisa->scrline + 176 + 2] = v3;
      Steam::setscr(thisa, thisa->scrline);
    }
    thisa->newrecord = 1;
  }
}


// Address: 0x0040B45C; symbol: __ZN5Steam7compscrElll
void __thiscall Steam::compscr(Steam *const this, int val, int mode, int index)
{
  signed int scrline_; // [esp+2Ch] [ebp-Ch]

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
      Steam::maxscr(this, val, index + scrline_);
  }
}


// Address: 0x0040B4F6; symbol: __ZN5Steam8resetscrEv
void __thiscall Steam::resetscr(Steam *const this)
{
  int scrid; // [esp+10h] [ebp-4h]

  if ( this->steamb )
  {
    for ( scrid = 0; scrid <= 18; ++scrid )
      this->lan.lanshort[scrid + 176 + 2] = 0;
  }
}


// Address: 0x0040B538; symbol: __ZN5Steam8loadleadEv
void __thiscall Steam::loadlead(Steam *const this)
{
  ISteamUserStats *v1; // eax
  int v2; // ebx
  const char *v3; // edx
  ISteamUtils *v4; // eax
  const char *v5; // edx
  int v6; // ebx
  Steam *thisa; // [esp+2Ch] [ebp-2Ch]
  int leadid_0; // [esp+38h] [ebp-20h]
  int leadid; // [esp+3Ch] [ebp-1Ch]

  thisa = this;
  if ( this->steamb )
  {
    painttitles = (pbitmap)"Load Leaderboard";
    painttitleb = 2;
    for ( leadid = 0; leadid <= 14; ++leadid )
    {
      v1 = SteamUserStats();
      v2 = leadid + 108;
      thisa->lan.lanshort[2 * v2] = (const char *)(*(int (__fastcall **)(ISteamUserStats *, const char *))(*(_DWORD *)v1 + 92))(
                                                    v1,
                                                    thisa->lan.lanshort[leadid + 196 + 2]);
      thisa->lan.lanshort[2 * v2 + 1] = v3;
    }
    if ( Steam::waitlead(thisa) )
    {
      for ( leadid_0 = 0; leadid_0 <= 14; ++leadid_0 )
      {
        v4 = SteamUtils();
        (*(void (__stdcall **)(const char *, const char *, LeaderboardFindResult_t *, signed int, signed int, bool *))(*(_DWORD *)v4 + 52))(
          thisa->lan.lanshort[2 * (leadid_0 + 108)],
          thisa->lan.lanshort[2 * (leadid_0 + 108) + 1],
          &thisa->leadr,
          16,
          1104,
          &thisa->leadfailed);
        v5 = (const char *)HIDWORD(thisa->leadr.m_hSteamLeaderboard);
        v6 = leadid_0 + 176;
        thisa->lan.lanshort[2 * v6 + 2] = (const char *)thisa->leadr.m_hSteamLeaderboard;
        thisa->lan.lanshort[2 * v6 + 3] = v5;
      }
    }
  }
}


// Address: 0x0040B660; symbol: __ZN5Steam7getleadEv
void __thiscall Steam::getlead(Steam *const this)
{
  int v1; // edx
  ISteamUserStats *v2; // eax
  int v3; // ebx
  const char *v4; // edx
  ISteamUserStats *v5; // eax
  int v6; // ebx
  const char *v7; // edx
  ISteamUserStats *v8; // eax
  int v9; // ebx
  const char *v10; // edx
  ISteamUtils *v11; // eax
  const char *v12; // edx
  int v13; // ebx
  const char *v14; // edx
  int v15; // ecx
  ISteamUserStats *v16; // eax
  Steam *thisa; // [esp+3Ch] [ebp-2Ch]
  int k; // [esp+40h] [ebp-28h]
  int leadid_0; // [esp+44h] [ebp-24h]
  int n; // [esp+48h] [ebp-20h]
  int leadid; // [esp+4Ch] [ebp-1Ch]

  thisa = this;
  if ( this->steamb )
  {
    v1 = HIDWORD(this->leadb[0]);
    if ( !this->leadb[0] || !this->leadb[1] || !this->leadb[2] )
      Steam::loadlead(this);
    for ( leadid = 0; leadid <= 14; ++leadid )
    {
      if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
      {
        v2 = SteamUserStats();
        v3 = leadid + 122;
        thisa->lan.lanshort[2 * v3 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, _DWORD, signed int, signed int))(*(_DWORD *)v2 + 112))(
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 2],
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 3],
                                                          0,
                                                          1,
                                                          20);
        thisa->lan.lanshort[2 * v3 + 3] = v4;
        v5 = SteamUserStats();
        v6 = leadid + 137;
        thisa->lan.lanshort[2 * v6 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, signed int, signed int))(*(_DWORD *)v5 + 112))(
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 2],
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 3],
                                                          1,
                                                          -5,
                                                          4);
        thisa->lan.lanshort[2 * v6 + 3] = v7;
        v8 = SteamUserStats();
        v9 = leadid + 152;
        thisa->lan.lanshort[2 * v9 + 2] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, _DWORD, _DWORD))(*(_DWORD *)v8 + 112))(
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 2],
                                                          thisa->lan.lanshort[2 * (leadid + 176) + 3],
                                                          1,
                                                          0,
                                                          0);
        thisa->lan.lanshort[2 * v9 + 3] = v10;
      }
    }
    if ( Steam::waitlead_(thisa) )
    {
      for ( n = 0; n <= 2; ++n )
      {
        for ( leadid_0 = 0; leadid_0 <= 14; ++leadid_0 )
        {
          v11 = SteamUtils();
          (*(void (__fastcall **)(ISteamUtils *, const char *, const char *, const char *, LeaderboardScoresDownloaded_t *, signed int, signed int))(*(_DWORD *)v11 + 52))(
            v11,
            thisa->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 3],
            thisa->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 2],
            thisa->lan.lanshort[2 * (15 * n + leadid_0 + 122) + 3],
            &thisa->leadd,
            24,
            1105);
          v12 = (const char *)HIDWORD(thisa->leadd.m_hSteamLeaderboard);
          v13 = leadid_0 + 176;
          thisa->lan.lanshort[2 * v13 + 2] = (const char *)thisa->leadd.m_hSteamLeaderboard;
          thisa->lan.lanshort[2 * v13 + 3] = v12;
          v14 = (const char *)HIDWORD(thisa->leadd.m_hSteamLeaderboardEntries);
          v15 = leadid_0 + 15 * n + 192;
          thisa->lan.lanshort[2 * v15] = (const char *)thisa->leadd.m_hSteamLeaderboardEntries;
          thisa->lan.lanshort[2 * v15 + 1] = v14;
          for ( k = 0; (_DWORD)thisa->lan.lanshort[n + 212 + 1] > k; ++k )
          {
            v16 = SteamUserStats();
            (*(void (__stdcall **)(const char *, const char *, int, char *, _DWORD, _DWORD))(*(_DWORD *)v16 + 120))(
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


// Address: 0x0040BA22; symbol: __ZN5Steam7setleadEv
void __thiscall Steam::setlead(Steam *const this)
{
  const char *v1; // edi
  ISteamUserStats *v2; // eax
  const char *v3; // ST04_4
  int v4; // eax
  const char *v5; // edx
  const char *v6; // ecx
  const char *v7; // edx
  int v8; // eax
  ISteamUtils *v9; // eax
  const char **v10; // edx
  const char *v11; // edx
  int v12; // ebx
  Steam *thisa; // [esp+3Ch] [ebp-2Ch]
  int k_0; // [esp+44h] [ebp-24h]
  int k; // [esp+48h] [ebp-20h]
  int leadid; // [esp+4Ch] [ebp-1Ch]
  int leadida; // [esp+4Ch] [ebp-1Ch]

  thisa = this;
  if ( this->steamb )
  {
    Steam::checkcheat(this);
    for ( leadid = 0; leadid <= 2; ++leadid )
    {
      v1 = thisa->lan.lanshort[2 * (leadid + 176) + 3];
      if ( !*(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
        Steam::loadlead(thisa);
      if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
      {
        for ( k = 0; k <= 4; ++k )
        {
          v2 = SteamUserStats();
          v3 = thisa->lan.lanshort[2 * (3 * k + leadid + 176) + 3];
          v4 = (*(int (__fastcall **)(ISteamUserStats *, const char *, const char *, const char *, signed int, const char *, _DWORD))(*(_DWORD *)v2 + 124))(
                 v2,
                 v3,
                 thisa->lan.lanshort[2 * (3 * k + leadid + 176) + 2],
                 v3,
                 1,
                 thisa->lan.lanshort[3 * k + leadid + 180 + 2],
                 0);
          v6 = v5;
          v7 = (const char *)v4;
          v8 = 3 * k + leadid + 108;
          thisa->lan.lanshort[2 * v8] = v7;
          thisa->lan.lanshort[2 * v8 + 1] = v6;
        }
      }
    }
    if ( Steam::waitlead(thisa) )
    {
      for ( leadida = 0; leadida <= 2; ++leadida )
      {
        if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadida + 176) + 2] )
        {
          for ( k_0 = 0; k_0 <= 4; ++k_0 )
          {
            v9 = SteamUtils();
            v10 = &thisa->lan.lanshort[2 * (3 * k_0 + leadida + 108)];
            (*(void (__fastcall **)(ISteamUtils *, const char *, const char *, const char *, LeaderboardScoreUploaded_t *, signed int, signed int))(*(_DWORD *)v9 + 52))(
              v9,
              v10[1],
              *v10,
              v10[1],
              &thisa->leadu,
              32,
              1106);
            v11 = (const char *)HIDWORD(thisa->leadu.m_hSteamLeaderboard);
            v12 = 3 * k_0 + leadida + 176;
            thisa->lan.lanshort[2 * v12 + 2] = (const char *)thisa->leadu.m_hSteamLeaderboard;
            thisa->lan.lanshort[2 * v12 + 3] = v11;
          }
        }
      }
    }
  }
}


// Address: 0x0040BC9C; symbol: __ZN5Steam7setleadEl
void __thiscall Steam::setlead(Steam *const this, int mode)
{
  ISteamUserStats *v2; // eax
  int v3; // ebx
  const char *v4; // edx
  ISteamUtils *v5; // eax
  const char **v6; // edx
  const char *v7; // edx
  int v8; // ebx
  Steam *thisa; // [esp+2Ch] [ebp-2Ch]
  int leadid; // [esp+38h] [ebp-20h]
  int k; // [esp+3Ch] [ebp-1Ch]

  thisa = this;
  if ( this->steamb )
  {
    Steam::checkcheat(this);
    if ( mode > 0 )
    {
      if ( thisa->newrecord )
      {
        thisa->newrecord = 0;
        leadid = mode - 1;
        if ( !*(_QWORD *)&thisa->lan.lanshort[2 * (mode - 1 + 176) + 2] )
          Steam::loadlead(thisa);
        if ( *(_QWORD *)&thisa->lan.lanshort[2 * (leadid + 176) + 2] )
        {
          for ( k = 0; k <= 4; ++k )
          {
            v2 = SteamUserStats();
            v3 = 3 * k + leadid + 108;
            thisa->lan.lanshort[2 * v3] = (const char *)(*(int (__stdcall **)(const char *, const char *, signed int, const char *, _DWORD, _DWORD))(*(_DWORD *)v2 + 124))(
                                                          thisa->lan.lanshort[2 * (leadid + 3 * k + 176) + 2],
                                                          thisa->lan.lanshort[2 * (leadid + 3 * k + 176) + 3],
                                                          1,
                                                          thisa->lan.lanshort[3 * k + leadid + 180 + 2],
                                                          0,
                                                          0);
            thisa->lan.lanshort[2 * v3 + 1] = v4;
            if ( Steam::waitlead(thisa) )
            {
              v5 = SteamUtils();
              v6 = &thisa->lan.lanshort[2 * (leadid + 3 * k + 108)];
              (*(void (__stdcall **)(const char *, const char *, LeaderboardScoreUploaded_t *, signed int, signed int, bool *))(*(_DWORD *)v5 + 52))(
                *v6,
                v6[1],
                &thisa->leadu,
                32,
                1106,
                &thisa->leadfailed);
              v7 = (const char *)HIDWORD(thisa->leadu.m_hSteamLeaderboard);
              v8 = 3 * k + leadid + 176;
              thisa->lan.lanshort[2 * v8 + 2] = (const char *)thisa->leadu.m_hSteamLeaderboard;
              thisa->lan.lanshort[2 * v8 + 3] = v7;
            }
          }
        }
      }
    }
  }
}


// Address: 0x0040BEB6; symbol: __ZN5Steam8waitleadEv
bool __thiscall Steam::waitlead(Steam *const this)
{
  ISteamUtils *v1; // eax
  bool v2; // al
  ISteamUtils *v3; // eax
  bool v4; // al
  Steam *thisa; // [esp+1Ch] [ebp-1Ch]
  int time; // [esp+24h] [ebp-14h]
  int leadid; // [esp+28h] [ebp-10h]
  char waitb; // [esp+2Fh] [ebp-9h]

  thisa = this;
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
               thisa->lan.lanshort[2 * (leadid + 108)],
               thisa->lan.lanshort[2 * (leadid + 108) + 1],
               &thisa->leadfailed) ^ 1 )
        {
          if ( (long double)time + thisa->waittime > GetTimeR() )
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
             thisa->lan.lanshort[2 * (leadid + 108)],
             thisa->lan.lanshort[2 * (leadid + 108) + 1],
             &thisa->leadfailed) )
      {
        v4 = 1;
      }
    }
    waitb = v4;
  }
  return waitb;
}


// Address: 0x0040BFF0; symbol: __ZN5Steam9waitlead_Ev
bool __thiscall Steam::waitlead_(Steam *const this)
{
  ISteamUtils *v1; // eax
  bool v2; // al
  ISteamUtils *v3; // eax
  bool v4; // al
  Steam *thisa; // [esp+1Ch] [ebp-2Ch]
  int time; // [esp+20h] [ebp-28h]
  int leadid; // [esp+24h] [ebp-24h]
  int n; // [esp+28h] [ebp-20h]
  char waitb; // [esp+2Fh] [ebp-19h]

  thisa = this;
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
                 thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 2],
                 thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 3],
                 &thisa->leadfailed) ^ 1 )
          {
            if ( (long double)time + thisa->waittime > GetTimeR() )
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
               thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 2],
               thisa->lan.lanshort[2 * (leadid + 15 * n + 122) + 3],
               &thisa->leadfailed) )
        {
          v4 = 1;
        }
      }
      waitb = v4;
    }
  }
  return waitb;
}


// Address: 0x0040C160; symbol: __ZN5Steam7savescrEPc
void __thiscall Steam::savescr(Steam *const this, char *scrpath)
{
  ISteamScreenshots *v2; // ebx
  void (__fastcall *v3)(ISteamScreenshots *, int, char *, _DWORD, unsigned int); // esi
  unsigned int v4; // ST0C_4
  unsigned int v5; // ST08_4
  int v6; // edx

  if ( this->steamb )
  {
    v2 = SteamScreenshots();
    v3 = *(void (__fastcall **)(ISteamScreenshots *, int, char *, _DWORD, unsigned int))(*(_DWORD *)v2 + 4);
    v4 = GetWin()->Height;
    v5 = GetWin()->Width;
    v3(v2, v6, scrpath, 0, v5);
  }
}


// Address: 0x0040C1C2; symbol: __ZN5Steam7ischeatEll
bool __thiscall Steam::ischeat(Steam *const this, int line, int tetris)
{
  if ( line > 9998 )
    return 1;
  if ( line <= 3000 || tetris > 98 && tetris <= 998 )
    return 0;
  return 1;
}


// Address: 0x0040C204; symbol: __ZN5Steam7ischeatEv
bool __thiscall Steam::ischeat(Steam *const this)
{
  return Steam::ischeat(this, this->scr[4], this->scr[13]);
}


// Address: 0x0040C236; symbol: __ZN5Steam10checkcheatEv
void __thiscall Steam::checkcheat(Steam *const this)
{
  Steam *thisa; // [esp+Ch] [ebp-Ch]

  thisa = this;
  if ( Steam::ischeat(this) )
  {
    Steam::resetscr(thisa);
    Steam::resetach(thisa);
  }
}


// Address: 0x0040C264; symbol: __ZL18loadallpaintstaticPv@4
DWORD __stdcall loadallpaintstatic(LPVOID lpParam)
{
  Window::loadallpaint((Window *const )lpParam);
  return 0;
}


// Address: 0x0040C283; symbol: __ZL7getleadPv@4
DWORD __stdcall getlead(LPVOID p)
{
  if ( !*((_BYTE *)p + 3382) )
  {
    *((_BYTE *)p + 3382) = 1;
    Window::paintevent((Window *const )p);
    Steam::getlead((Steam *const )((char *)p + 840));
    Window::paintevent((Window *const )p);
    *((_BYTE *)p + 3382) = 0;
  }
  return 0;
}


// Address: 0x0040C2E4; symbol: __ZN6WindowC1Ev
void __thiscall Window::Window(Window *const this)
{
  Window *v1; // ST1C_4

  v1 = this;
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
  v1->okh_ = this->abouth - (v1->fontth + 4 * v1->fonth);
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
  Board::Board(&v1->bd);
  Block::Block(&v1->bl);
  v1->maxhelp = 6;
  v1->helpi = 0;
  v1->helpb = 1;
  v1->cheatb = 0;
  v1->waitb = 0;
  v1->pwin = 0;
  v1->pwint = 0;
  v1->minh = 600;
  v1->minw = 800;
  v1->mult_ = 0;
  v1->mult = 1.0;
  v1->showmax = 0;
  v1->showmax_ = 0;
  v1->w_ = 0;
  v1->h_ = 0;
  v1->x_ = 0;
  v1->y_ = 0;
  v1->xscr = 0;
  v1->yscr = 0;
  v1->wscr = 0;
  v1->hscr = 0;
  v1->barb = 1;
  v1->md = 0;
  v1->ml = 0;
  v1->mr = 0;
  v1->mx = -1;
  v1->my = -1;
  v1->mi = 0;
  v1->lead_5 = 0;
  v1->singleb = 0;
  v1->boardb = 0;
  v1->timerefresh = 0.0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&v1->cs);
  Window::initwindow(v1);
}


// Address: 0x0040CA6C; symbol: __ZN6WindowD1Ev
void __thiscall Window::~Window(Window *const this)
{
  Window *v1; // ST1C_4

  v1 = this;
  Window::releasewindow(this);
  DeleteCriticalSection((LPCRITICAL_SECTION)&v1->cs);
  Board::~Board(&v1->bd);
  Reg::~Reg(&v1->reg);
}


// Address: 0x0040CAB4; symbol: __ZN6Window16loadsettingcloudEv
void __thiscall Window::loadsettingcloud(Window *const this)
{
  ISteamRemoteStorage *v1; // eax
  ISteamRemoteStorage *v2; // eax
  ISteamRemoteStorage *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  Window *thisa; // [esp+1Ch] [ebp-3Ch]
  int buf[9]; // [esp+28h] [ebp-30h]
  int pos; // [esp+4Ch] [ebp-Ch]

  thisa = this;
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
        thisa->helpb = buf[0] != 0;
        v4 = pos++;
        thisa->colori = buf[v4];
        v5 = pos++;
        thisa->md = buf[v5];
        v6 = pos++;
        thisa->bd.sd.soundb = buf[v6] != 0;
        v7 = pos++;
        thisa->bd.sd.musicb = buf[v7] != 0;
        v8 = pos++;
        thisa->mult_ = buf[v8];
        v9 = pos++;
        thisa->bd.delayb = buf[v9];
        v10 = pos++;
        thisa->barb = buf[v10] != 0;
        v11 = pos++;
        thisa->singleb = buf[v11] != 0;
      }
    }
  }
}


// Address: 0x0040CC4E; symbol: __ZN6Window16savesettingcloudEv
void __thiscall Window::savesettingcloud(Window *const this)
{
  ISteamRemoteStorage *v1; // eax
  Window *thisa; // [esp+1Ch] [ebp-3Ch]
  int buf[9]; // [esp+28h] [ebp-30h]
  int pos; // [esp+4Ch] [ebp-Ch]

  thisa = this;
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
    v1 = SteamRemoteStorage();
    (**(void (__fastcall ***)(ISteamRemoteStorage *, int *, const char *, int *))v1)(v1, buf, "reg.dat", buf);
  }
}


// Address: 0x0040CD7A; symbol: __ZN6Window11loadsettingEv
void __thiscall Window::loadsetting(Window *const this)
{
  Window *v1; // ST1C_4

  v1 = this;
  Reg::getreg(&this->reg, this->reg.regkey, (const char *)&key, (int *)&this->helpb);
  Reg::getreg(&v1->reg, v1->reg.regkey, (const char *)&stru_428FF2, &v1->colori);
  Reg::getreg(&v1->reg, v1->reg.regkey, (const char *)&unk_428FF9, &v1->md);
  Reg::getreg(&v1->reg, v1->reg.regkey, (const char *)&stru_428FFC, (int *)&v1->bd.sd.soundb);
  Reg::getreg(&v1->reg, v1->reg.regkey, (const char *)&stru_429003, (int *)&v1->bd.sd.musicb);
  Reg::getreg(&v1->reg, v1->reg.regkey, (const char *)&stru_42900A, &v1->mult_);
  Reg::getreg(&v1->reg, v1->reg.regkey, (const char *)&stru_42900F, &v1->bd.delayb);
  Reg::getreg(&v1->reg, v1->reg.regkey, (const char *)&stru_429016, (int *)&v1->barb);
  Reg::getreg(&v1->reg, v1->reg.regkey, (const char *)&stru_42901B, (int *)&v1->singleb);
  Window::loadsettingcloud(v1);
}


// Address: 0x0040CF64; symbol: __ZN6Window11savesettingEv
void __thiscall Window::savesetting(Window *const this)
{
  Window *v1; // ST1C_4

  v1 = this;
  Reg::setreg(&this->reg, this->reg.regkey, (const char *)&key, this->helpb);
  Reg::setreg(&v1->reg, v1->reg.regkey, (const char *)&stru_428FF2, v1->colori);
  Reg::setreg(&v1->reg, v1->reg.regkey, (const char *)&unk_428FF9, v1->md);
  Reg::setreg(&v1->reg, v1->reg.regkey, (const char *)&stru_428FFC, v1->bd.sd.soundb);
  Reg::setreg(&v1->reg, v1->reg.regkey, (const char *)&stru_429003, v1->bd.sd.musicb);
  Reg::setreg(&v1->reg, v1->reg.regkey, (const char *)&stru_42900A, v1->mult_);
  Reg::setreg(&v1->reg, v1->reg.regkey, (const char *)&stru_42900F, v1->bd.delayb);
  Reg::setreg(&v1->reg, v1->reg.regkey, (const char *)&stru_429016, v1->barb);
  Reg::setreg(&v1->reg, v1->reg.regkey, (const char *)&stru_42901B, v1->singleb);
  Window::savesettingcloud(v1);
}


// Address: 0x0040D150; symbol: __ZN6Window14loadboardcloudEv
void __thiscall Window::loadboardcloud(Window *const this)
{
  int v1; // eax
  void *v2; // esp
  ISteamRemoteStorage *v3; // eax
  ISteamRemoteStorage *v4; // eax
  ISteamRemoteStorage *v5; // eax
  int v6; // eax
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
  Window *v29; // [esp+1Ch] [ebp-1407Ch]
  int v30[25]; // [esp+28h] [ebp-14070h]
  char v31; // [esp+8Ch] [ebp-1400Ch]
  char v32; // [esp+408Ch] [ebp-1000Ch]
  char v33; // [esp+808Ch] [ebp-C00Ch]
  char v34; // [esp+C08Ch] [ebp-800Ch]
  char v35; // [esp+1008Ch] [ebp-400Ch]
  int v36; // [esp+1408Ch] [ebp-Ch]

  v2 = alloca(v1);
  v29 = this;
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
        v29->bd.mode = v30[0];
        v6 = v36++;
        v29->bd.w = v30[v6];
        v7 = v36++;
        v29->bd.h = v30[v7];
        v8 = v36++;
        v29->bd.n = v30[v8];
        v9 = v36++;
        v29->bd.maskj0 = v30[v9];
        v10 = v36++;
        v29->bd.sit = v30[v10];
        v11 = v36++;
        v29->bd.line = v30[v11];
        v12 = v36++;
        v29->bd.level = v30[v12];
        v13 = v36++;
        v29->bd.tetrisi = v30[v13];
        v14 = v36++;
        v29->bd.missi = v30[v14];
        v15 = v36++;
        v29->bd.missline = v30[v15];
        v16 = v36++;
        v29->bd.sum = v30[v16];
        v17 = v36++;
        v29->bd.maskj = v30[v17];
        v18 = v36++;
        v29->bd.maski = v30[v18];
        v19 = v36++;
        v29->bd.rightb = v30[v19];
        v20 = v36++;
        v29->bd.tuti = v30[v20];
        v21 = v36++;
        v29->bd.tutb = v30[v21];
        v22 = v36++;
        v29->bd.checkr = v30[v22];
        v23 = v36++;
        v29->bd.pauseb = v30[v23];
        v24 = v36++;
        v29->bd.mx = v30[v24];
        v25 = v36++;
        v29->bd.my = v30[v25];
        v26 = v36++;
        v29->bd.bouns = v30[v26];
        v27 = v36++;
        v29->bd.mdb = v30[v27];
        v28 = v36++;
        v29->bd.solven = v30[v28];
        memcpy(v29->bd.flag, &v31, 0x4000u);
        memcpy(v29->bd.qstn, &v32, 0x4000u);
        memcpy(v29->bd.mine, &v33, 0x4000u);
        memcpy(v29->bd.blck, &v34, 0x4000u);
        memcpy(v29->bd.mask, &v35, 0x4000u);
        Block::calcnumb(&v29->bd.0);
      }
    }
  }
}


// Address: 0x0040D588; symbol: __ZN6Window14saveboardcloudEv
void __thiscall Window::saveboardcloud(Window *const this)
{
  int v1; // eax
  void *v2; // esp
  ISteamRemoteStorage *v3; // eax
  Window *v4; // [esp+1Ch] [ebp-1407Ch]
  int v5; // [esp+28h] [ebp-14070h]
  int v6; // [esp+2Ch] [ebp-1406Ch]
  int v7; // [esp+30h] [ebp-14068h]
  int v8; // [esp+34h] [ebp-14064h]
  int v9; // [esp+38h] [ebp-14060h]
  int v10; // [esp+3Ch] [ebp-1405Ch]
  int v11; // [esp+40h] [ebp-14058h]
  int v12; // [esp+44h] [ebp-14054h]
  int v13; // [esp+48h] [ebp-14050h]
  int v14; // [esp+4Ch] [ebp-1404Ch]
  int v15; // [esp+50h] [ebp-14048h]
  int v16; // [esp+54h] [ebp-14044h]
  int v17; // [esp+58h] [ebp-14040h]
  int v18; // [esp+5Ch] [ebp-1403Ch]
  int v19; // [esp+60h] [ebp-14038h]
  int v20; // [esp+64h] [ebp-14034h]
  int v21; // [esp+68h] [ebp-14030h]
  int v22; // [esp+6Ch] [ebp-1402Ch]
  int v23; // [esp+70h] [ebp-14028h]
  int v24; // [esp+74h] [ebp-14024h]
  int v25; // [esp+78h] [ebp-14020h]
  int v26; // [esp+7Ch] [ebp-1401Ch]
  int v27; // [esp+80h] [ebp-14018h]
  int v28; // [esp+84h] [ebp-14014h]
  char v29; // [esp+8Ch] [ebp-1400Ch]
  char v30; // [esp+408Ch] [ebp-1000Ch]
  char v31; // [esp+808Ch] [ebp-C00Ch]
  char v32; // [esp+C08Ch] [ebp-800Ch]
  char v33; // [esp+1008Ch] [ebp-400Ch]
  int v34; // [esp+1408Ch] [ebp-Ch]

  v2 = alloca(v1);
  v4 = this;
  if ( SteamRemoteStorage() != 0 )
  {
    v34 = 1;
    v5 = v4->bd.mode;
    v34 = 2;
    v6 = v4->bd.w;
    v34 = 3;
    v7 = v4->bd.h;
    v34 = 4;
    v8 = v4->bd.n;
    v34 = 5;
    v9 = v4->bd.maskj0;
    v34 = 6;
    v10 = v4->bd.sit;
    v34 = 7;
    v11 = v4->bd.line;
    v34 = 8;
    v12 = v4->bd.level;
    v34 = 9;
    v13 = v4->bd.tetrisi;
    v34 = 10;
    v14 = v4->bd.missi;
    v34 = 11;
    v15 = v4->bd.missline;
    v34 = 12;
    v16 = v4->bd.sum;
    v34 = 13;
    v17 = v4->bd.maskj;
    v34 = 14;
    v18 = v4->bd.maski;
    v34 = 15;
    v19 = v4->bd.rightb;
    v34 = 16;
    v20 = v4->bd.tuti;
    v34 = 17;
    v21 = v4->bd.tutb;
    v34 = 18;
    v22 = v4->bd.checkr;
    v34 = 19;
    v23 = v4->bd.pauseb;
    v34 = 20;
    v24 = v4->bd.mx;
    v34 = 21;
    v25 = v4->bd.my;
    v34 = 22;
    v26 = v4->bd.bouns;
    v34 = 23;
    v27 = v4->bd.mdb;
    v34 = 24;
    v28 = v4->bd.solven;
    memcpy(&v29, v4->bd.flag, 0x4000u);
    memcpy(&v30, v4->bd.qstn, 0x4000u);
    memcpy(&v31, v4->bd.mine, 0x4000u);
    memcpy(&v32, v4->bd.blck, 0x4000u);
    memcpy(&v33, v4->bd.mask, 0x4000u);
    v3 = SteamRemoteStorage();
    (**(void (__fastcall ***)(ISteamRemoteStorage *, int *, const char *, int *))v3)(v3, &v5, "board.dat", &v5);
  }
}


// Address: 0x0040D94C; symbol: __ZN6Window9loadboardEv
void __thiscall Window::loadboard(Window *const this)
{
  Window *v1; // ST1C_4

  v1 = this;
  Reg::getreg(&this->reg, this->reg.regkey_, (const char *)&stru_42902D, &this->bd.mode);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&unk_429032, &v1->bd.w);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&unk_429034, &v1->bd.h);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&unk_429036, &v1->bd.n);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429038, &v1->bd.maskj0);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42903F, &v1->bd.sit);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429043, &v1->bd.line);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429048, &v1->bd.level);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42904E, &v1->bd.tetrisi);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429056, &v1->bd.missi);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42905C, &v1->bd.missline);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429065, &v1->bd.sum);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429069, &v1->bd.maskj);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42906F, &v1->bd.maski);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429075, &v1->bd.rightb);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42907C, &v1->bd.tuti);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429081, &v1->bd.tutb);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429086, &v1->bd.checkr);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42908D, &v1->bd.pauseb);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&unk_429094, &v1->bd.mx);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&unk_429097, &v1->bd.my);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42909A, &v1->bd.bouns);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290A0, &v1->bd.mdb);
  Reg::getreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290A4, &v1->bd.solven);
  Reg::getreg_(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290AB, (char *)v1->bd.flag);
  Reg::getreg_(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290B0, (char *)v1->bd.qstn);
  Reg::getreg_(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290B5, (char *)v1->bd.mine);
  Reg::getreg_(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290BA, (char *)v1->bd.blck);
  Reg::getreg_(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290BF, (char *)v1->bd.mask);
  Window::loadboardcloud(v1);
  Block::calcnumb(&v1->bd.0);
}


// Address: 0x0040DF60; symbol: __ZN6Window9saveboardEv
void __thiscall Window::saveboard(Window *const this)
{
  Window *v1; // ST1C_4

  v1 = this;
  Reg::setreg(&this->reg, this->reg.regkey_, (const char *)&stru_42902D, this->bd.mode);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&unk_429032, v1->bd.w);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&unk_429034, v1->bd.h);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&unk_429036, v1->bd.n);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429038, v1->bd.maskj0);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42903F, v1->bd.sit);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429043, v1->bd.line);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429048, v1->bd.level);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42904E, v1->bd.tetrisi);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429056, v1->bd.missi);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42905C, v1->bd.missline);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429065, v1->bd.sum);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429069, v1->bd.maskj);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42906F, v1->bd.maski);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429075, v1->bd.rightb);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42907C, v1->bd.tuti);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429081, v1->bd.tutb);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_429086, v1->bd.checkr);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42908D, v1->bd.pauseb);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&unk_429094, v1->bd.mx);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&unk_429097, v1->bd.my);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_42909A, v1->bd.bouns);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290A0, v1->bd.mdb);
  Reg::setreg(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290A4, v1->bd.solven);
  Reg::setreg_(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290AB, (char *)v1->bd.flag);
  Reg::setreg_(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290B0, (char *)v1->bd.qstn);
  Reg::setreg_(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290B5, (char *)v1->bd.mine);
  Reg::setreg_(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290BA, (char *)v1->bd.blck);
  Reg::setreg_(&v1->reg, v1->reg.regkey_, (const char *)&stru_4290BF, (char *)v1->bd.mask);
  Window::saveboardcloud(v1);
}


// Address: 0x0040E534; symbol: __ZN6Window12loadallpaintEv
void __thiscall Window::loadallpaint(Window *const this)
{
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  while ( painttitleb > 0 )
  {
    if ( painttitleb == 2 )
    {
      painttitleb = 1;
      Window::painttitle(thisa, (int)painttitlec);
    }
    Sleep(1u);
  }
  painttitles = 0;
}


// Address: 0x0040E58E; symbol: __ZN6Window7loadallEv
void __thiscall Window::loadall(Window *const this)
{
  HWND__ *v1; // eax
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  painttitleb = 1;
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)loadallpaintstatic, this, 0, 0);
  if ( (unsigned __int8)IsWin() )
    Window::loadsetting(thisa);
  Window::painttitle(thisa, thisa->bd.st.lan.LAN_LOAD_STEAM);
  if ( (unsigned __int8)IsWin() )
    Steam::loadsteam(&thisa->bd.st);
  Window::painttitle(thisa, thisa->bd.st.lan.LAN_LOAD_AUDIO);
  if ( (unsigned __int8)IsWin() )
    Sound::initsound(&thisa->bd.sd);
  Window::painttitle(thisa, thisa->bd.st.lan.LAN_LOAD_BOARD);
  if ( (unsigned __int8)IsWin() )
  {
    Board::initbd(&thisa->bd, 1, thisa->md);
    Reg::getreg(&thisa->reg, thisa->reg.regkey, (const char *)&stru_4290C4, &thisa->boardb);
    thisa->bd.tutb = thisa->helpb;
    if ( thisa->boardb == 1 )
    {
      Window::loadboard(thisa);
      thisa->boardb = 0;
      Reg::setreg(&thisa->reg, thisa->reg.regkey, (const char *)&stru_4290C4, thisa->boardb);
    }
  }
  Window::painttitle(thisa, thisa->bd.st.lan.LAN_LOAD_GRAPH);
  if ( (unsigned __int8)IsWin() )
    Window::initbmp(thisa);
  Window::painttitle(thisa, thisa->bd.st.lan.LAN_LOAD_WINDOW);
  if ( (unsigned __int8)IsWin() )
  {
    v1 = GetHwnd();
    SetWindowLongA(v1, -16, 281739264);
    Window::sethelp(thisa, 0);
  }
  painttitleb = 0;
}


// Address: 0x0040E7CA; symbol: __ZN6Window8initmultEv
void __thiscall Window::initmult(Window *const this)
{
  int v1; // ebx
  long double v2; // fst7
  int v3; // ebx
  int v4; // ebx
  long double v5; // fst7
  int v6; // ebx
  long double v7; // fst7
  long double v8; // fst7
  int v9; // ebx
  int v10; // ebx
  long double v11; // fst7
  long double v12; // fst7
  int v13; // ebx
  long double v14; // fst7
  int v15; // ebx
  int v16; // ebx
  long double v17; // fst7
  int v18; // ebx
  long double v19; // fst7
  int v20; // ebx
  int v21; // ebx
  long double v22; // fst7
  int v23; // ebx
  double v24; // ST08_8
  int v25; // ebx
  int v26; // ebx
  int v27; // ebx
  long double v28; // fst7
  int v29; // ebx
  int v30; // ebx
  long double v31; // fst7
  int v32; // ebx
  double v33; // ST08_8
  int v34; // ebx
  int v35; // ebx
  int v36; // ebx
  int v37; // ebx
  int v38; // ebx
  signed int v39; // eax
  int v40; // ebx
  double v41; // ST08_8
  int v42; // ebx
  int v43; // ebx
  int v44; // ebx
  long double v45; // fst7
  int v46; // ebx
  int v47; // ebx
  long double v48; // fst7
  int v49; // ebx
  double v50; // ST08_8
  int v51; // ebx
  int v52; // ebx
  int v53; // ebx
  int v54; // ebx
  int v55; // ebx
  long double v56; // fst7
  signed int v57; // [esp+8h] [ebp-20h]
  double v58; // [esp+8h] [ebp-20h]
  signed int v59; // [esp+8h] [ebp-20h]
  signed int v60; // [esp+8h] [ebp-20h]
  signed int v61; // [esp+8h] [ebp-20h]
  double v62; // [esp+8h] [ebp-20h]
  signed int v63; // [esp+8h] [ebp-20h]
  signed int v64; // [esp+8h] [ebp-20h]
  signed int v65; // [esp+10h] [ebp-18h]
  signed int v66; // [esp+10h] [ebp-18h]
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  if ( this->mult_ )
  {
    if ( this->mult_ == 1 )
    {
      v23 = this->wscr;
      v24 = (long double)(v23 - 2 * GetBorderWidth()) / (long double)this->w_;
      v25 = thisa->hscr;
      v26 = v25 - 2 * GetBorderHeight();
      if ( (long double)(v26 - GetBorderTitle()) / (long double)thisa->h_ <= v24 )
      {
        v29 = thisa->hscr;
        v30 = v29 - 2 * GetBorderHeight();
        v28 = (long double)(v30 - GetBorderTitle()) / (long double)thisa->h_;
      }
      else
      {
        v27 = thisa->wscr;
        v28 = (long double)(v27 - 2 * GetBorderWidth()) / (long double)thisa->w_;
      }
      if ( v28 >= 1.0 )
      {
        v32 = thisa->wscr;
        v33 = (long double)(v32 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        v34 = thisa->hscr;
        v35 = v34 - 2 * GetBorderHeight();
        if ( (long double)(v35 - GetBorderTitle()) / (long double)thisa->h_ <= v33 )
        {
          v37 = thisa->hscr;
          v38 = v37 - 2 * GetBorderHeight();
          v31 = (long double)(v38 - GetBorderTitle()) / (long double)thisa->h_;
        }
        else
        {
          v36 = thisa->wscr;
          v31 = (long double)(v36 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        }
      }
      else
      {
        v31 = 1.0;
      }
      thisa->mult = v31;
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
      v42 = thisa->hscr;
      v43 = v42 - 2 * GetBorderHeight();
      if ( (long double)(v43 - GetBorderTitle()) / (long double)thisa->h_ <= v41 )
      {
        v46 = thisa->hscr;
        v47 = v46 - 2 * GetBorderHeight();
        v45 = (long double)(v47 - GetBorderTitle()) / (long double)thisa->h_;
      }
      else
      {
        v44 = thisa->wscr;
        v45 = (long double)(v44 - 2 * GetBorderWidth()) / (long double)thisa->w_;
      }
      if ( v45 >= 1.0 )
      {
        v49 = thisa->wscr;
        v50 = (long double)(v49 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        v51 = thisa->hscr;
        v52 = v51 - 2 * GetBorderHeight();
        if ( (long double)(v52 - GetBorderTitle()) / (long double)thisa->h_ <= v50 )
        {
          v54 = thisa->hscr;
          v55 = v54 - 2 * GetBorderHeight();
          v48 = (long double)(v55 - GetBorderTitle()) / (long double)thisa->h_;
        }
        else
        {
          v53 = thisa->wscr;
          v48 = (long double)(v53 - 2 * GetBorderWidth()) / (long double)thisa->w_;
        }
      }
      else
      {
        v48 = 1.0;
      }
      thisa->mult = v48;
      if ( (long double)thisa->mult_ / 2.0 <= thisa->mult )
        v56 = (long double)thisa->mult_ / 2.0;
      else
        v56 = thisa->mult;
      thisa->mult = v56;
    }
  }
  else
  {
    v1 = this->wscr;
    v2 = (long double)(v1 - 2 * GetBorderWidth());
    if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
      v57 = thisa->w_;
    else
      v57 = thisa->minw;
    v58 = v2 / (long double)v57;
    v3 = thisa->hscr;
    v4 = v3 - 2 * GetBorderHeight();
    v5 = (long double)(v4 - GetBorderTitle());
    if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
      v65 = thisa->h_;
    else
      v65 = thisa->minh;
    if ( v5 / (long double)v65 <= v58 )
    {
      v9 = thisa->hscr;
      v10 = v9 - 2 * GetBorderHeight();
      v11 = (long double)(v10 - GetBorderTitle());
      if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
        v60 = thisa->h_;
      else
        v60 = thisa->minh;
      v8 = v11 / (long double)v60;
    }
    else
    {
      v6 = thisa->wscr;
      v7 = (long double)(v6 - 2 * GetBorderWidth());
      if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
        v59 = thisa->w_;
      else
        v59 = thisa->minw;
      v8 = v7 / (long double)v59;
    }
    if ( v8 >= 1.0 )
    {
      v13 = thisa->wscr;
      v14 = (long double)(v13 - 2 * GetBorderWidth());
      if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
        v61 = thisa->w_;
      else
        v61 = thisa->minw;
      v62 = v14 / (long double)v61;
      v15 = thisa->hscr;
      v16 = v15 - 2 * GetBorderHeight();
      v17 = (long double)(v16 - GetBorderTitle());
      if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
        v66 = thisa->h_;
      else
        v66 = thisa->minh;
      if ( v17 / (long double)v66 <= v62 )
      {
        v20 = thisa->hscr;
        v21 = v20 - 2 * GetBorderHeight();
        v22 = (long double)(v21 - GetBorderTitle());
        if ( (long double)(signed int)thisa->minh <= (long double)thisa->h_ )
          v64 = thisa->h_;
        else
          v64 = thisa->minh;
        v12 = v22 / (long double)v64;
      }
      else
      {
        v18 = thisa->wscr;
        v19 = (long double)(v18 - 2 * GetBorderWidth());
        if ( (long double)(signed int)thisa->minw <= (long double)thisa->w_ )
          v63 = thisa->w_;
        else
          v63 = thisa->minw;
        v12 = v19 / (long double)v63;
      }
    }
    else
    {
      v12 = 1.0;
    }
    thisa->mult = v12;
    thisa->mult = (long double)(signed int)(thisa->mult + thisa->mult) / 2.0;
  }
  thisa->bd.w_ = thisa->w_;
  thisa->bd.h_ = thisa->h_;
  thisa->bd.mult = thisa->mult;
}


// Address: 0x0040EFC4; symbol: __ZN6Window8loadiconEv
void __thiscall Window::loadicon(Window *const this)
{
  HICON__ *v1; // edx
  LPARAM v2; // ebx
  HWND__ *v3; // eax
  LPARAM v4; // ebx
  HWND__ *v5; // eax
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  this->hicon_res = (HICON)LoadImageA(MainInstance, "MINESWEEPERRUSH_ICON", 1u, 0, 0, 0);
  thisa->hicon_file = (HICON)LoadImageA(0, "./data/MineSweeperRush.ico", 1u, 0, 0, 0x8050u);
  if ( thisa->hicon_res )
    v1 = thisa->hicon_res;
  else
    v1 = thisa->hicon_file;
  thisa->hicon = v1;
  v2 = (LPARAM)thisa->hicon;
  v3 = GetHwnd();
  SendMessageA(v3, 0x80u, 1u, v2);
  Delay(0xAu);
  v4 = (LPARAM)thisa->hicon;
  v5 = GetHwnd();
  SendMessageA(v5, 0x80u, 0, v4);
  Delay(0xAu);
}


// Address: 0x0040F102; symbol: __ZN6Window10initwindowEv
void __thiscall Window::initwindow(Window *const this)
{
  double v1; // ST28_8
  long double v2; // fst7
  double v3; // ST28_8
  double v4; // ST28_8
  double v5; // ST28_8
  long double v6; // fst7
  double v7; // ST28_8
  double v8; // ST28_8
  __int16 *v9; // eax
  int v10; // ebx
  int v11; // ebx
  int v12; // ebx
  double v13; // [esp+30h] [ebp-78h]
  double v14; // [esp+30h] [ebp-78h]
  Window *thisa; // [esp+4Ch] [ebp-5Ch]
  LOGFONT lf; // [esp+54h] [ebp-54h]

  thisa = this;
  Window::initcolor(this);
  SystemParametersInfoA(0x30u, 0, &thisa->rect, 0);
  thisa->wscr = thisa->rect.right - thisa->rect.left;
  thisa->hscr = thisa->rect.bottom - thisa->rect.top;
  thisa->w_ = thisa->launchw;
  thisa->h_ = thisa->launchh;
  Reg::getreg(&thisa->reg, thisa->reg.regkey, (const char *)&stru_42900A, &thisa->mult_);
  Window::initmult(thisa);
  v13 = (long double)thisa->rect.left;
  v1 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
  if ( (v1 - (long double)(2 * GetBorderWidth())) / 2.0 >= 0.0 )
  {
    v3 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
    v2 = (v3 - (long double)(2 * GetBorderWidth())) / 2.0;
  }
  else
  {
    v2 = 0.0;
  }
  thisa->x_ = (signed int)(v2 + v13);
  v14 = (long double)thisa->rect.top;
  v4 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
  v5 = v4 - (long double)(2 * GetBorderHeight());
  if ( (v5 - (long double)GetBorderTitle()) / 2.0 >= 0.0 )
  {
    v7 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
    v8 = v7 - (long double)(2 * GetBorderHeight());
    v6 = (v8 - (long double)GetBorderTitle()) / 2.0;
  }
  else
  {
    v6 = 0.0;
  }
  thisa->y_ = (signed int)(v6 + v14);
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
  Window::loadicon(thisa);
  v9 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_TITLE);
  SetTitleW(v9);
  SystemParametersInfoA(0x1Fu, 0x3Cu, &lf, 0);
  Window::setfontname_(thisa, lf.lfFaceName);
  Window::painttitle(thisa, -1);
  v10 = thisa->wscr;
  thisa->bd.maxbdw = (v10 - 2 * GetBorderWidth()) / 16 - 1;
  v11 = thisa->hscr - thisa->menuh - thisa->faceh;
  v12 = v11 - 2 * GetBorderHeight();
  thisa->bd.maxbdh = (v12 - GetBorderTitle()) / 16 - 1;
}


// Address: 0x0040F5F8; symbol: __ZN6Window13releasewindowEv
void __thiscall Window::releasewindow(Window *const this)
{
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  Window::savesetting(this);
  if ( thisa->cheatb != 1 && thisa->bd.relaxb != 1 && thisa->bd.sit > 0 && thisa->bd.sit <= 3 )
  {
    if ( !thisa->bd.tutb )
      thisa->bd.pauseb = 1;
    Window::saveboard(thisa);
    thisa->boardb = 1;
    Reg::setreg(&thisa->reg, thisa->reg.regkey, (const char *)&stru_4290C4, thisa->boardb);
  }
}


// Address: 0x0040F6B2; symbol: __ZN6Window10initwindowEb
void __thiscall Window::initwindow(Window *const this, bool b)
{
  int v2; // eax
  double v3; // ST18_8
  long double v4; // fst7
  double v5; // ST18_8
  double v6; // ST18_8
  double v7; // ST18_8
  long double v8; // fst7
  double v9; // ST18_8
  double v10; // ST18_8
  double v11; // [esp+20h] [ebp-38h]
  double v12; // [esp+20h] [ebp-38h]
  Window *thisa; // [esp+3Ch] [ebp-1Ch]
  RECT rect; // [esp+40h] [ebp-18h]

  thisa = this;
  if ( (unsigned __int8)IsWin() )
  {
    v2 = thisa->helpi;
    if ( v2 == -1 )
    {
      thisa->w_ = thisa->aboutw;
      thisa->h_ = thisa->menuh + thisa->abouth;
    }
    else if ( v2 )
    {
      thisa->w_ = thisa->helpw;
      thisa->h_ = thisa->menuh + thisa->helph;
    }
    else
    {
      if ( b )
      {
        thisa->bd.mode = 0;
        Board::initbd(&thisa->bd);
      }
      thisa->w_ = thisa->iconw * thisa->bd.w;
      thisa->h_ = thisa->menuh + thisa->faceh + thisa->iconh * thisa->bd.h;
    }
    Window::initmult(thisa);
    v11 = (long double)thisa->rect.left;
    v3 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
    if ( (v3 - (long double)(2 * GetBorderWidth())) / 2.0 >= 0.0 )
    {
      v5 = (long double)thisa->wscr - (long double)thisa->w_ * thisa->mult;
      v4 = (v5 - (long double)(2 * GetBorderWidth())) / 2.0;
    }
    else
    {
      v4 = 0.0;
    }
    thisa->x_ = (signed int)(v4 + v11);
    v12 = (long double)thisa->rect.top;
    v6 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
    v7 = v6 - (long double)(2 * GetBorderHeight());
    if ( (v7 - (long double)GetBorderTitle()) / 2.0 >= 0.0 )
    {
      v9 = (long double)thisa->hscr - (long double)thisa->h_ * thisa->mult;
      v10 = v9 - (long double)(2 * GetBorderHeight());
      v8 = (v10 - (long double)GetBorderTitle()) / 2.0;
    }
    else
    {
      v8 = 0.0;
    }
    thisa->y_ = (signed int)(v8 + v12);
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
    Window::paintevent(thisa, 0);
    FreshWin();
  }
}


// Address: 0x0040FB94; symbol: __ZN6Window9initcolorEv
void __thiscall Window::initcolor(Window *const this)
{
  Window *v1; // ST00_4

  v1 = this;
  this->cfg = this->color[0];
  v1->cbg = v1->color[1];
  v1->ctfg = v1->color[2];
  v1->ctbg = v1->color[3];
  v1->cred = v1->color[4];
  v1->cblue = v1->color[5];
  v1->cgreen = v1->color[6];
  v1->cline = v1->color[7];
  v1->cmine = v1->color[8];
  v1->bd.cred = v1->cred;
  v1->transparent_ = v1->cbg;
}


// Address: 0x0040FC66; symbol: __ZN6Window7initbmpEv
void __thiscall Window::initbmp(Window *const this)
{
  unsigned int v1; // ecx
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

  thisa = this;
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
      v1 = GetPixel(thisa->pbg_, 0, k_1);
      *((_DWORD *)&thisa->titleh + k_1 + 160) = v1;
    }
    Window::initcolor(thisa);
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


// Address: 0x00412776; symbol: __ZN6Window9paintmenuEv
void __thiscall Window::paintmenu(Window *const this)
{
  Window *v1; // ST2C_4

  v1 = this;
  DrawBMP(*((pbitmap *)&v1->launchh + (v1->helpi == -1) + 48), this->w_ - this->menuw, 0, this->menuw, this->menuh);
  DrawBMP(*((pbitmap *)&v1->titleh + (v1->helpi > 0) + 44), v1->w_ - 2 * v1->menuw, 0, v1->menuw, v1->menuh);
  DrawBMP(*((pbitmap *)&v1->launchh + (v1->helpi == -3) + 56), v1->w_ - 3 * v1->menuw, 0, v1->menuw, v1->menuh);
  DrawBMP(*((pbitmap *)&v1->titleh + (v1->helpi == -2) + 52), v1->w_ - 4 * v1->menuw, 0, v1->menuw, v1->menuh);
  DrawBMP(v1->pface[6], v1->w_ - 5 * v1->menuw, 0, v1->menuw, v1->menuh);
  DrawBMP(*((pbitmap *)&v1->launchh + (v1->bd.mode == 1) + 40), 0, 0, v1->menuw, v1->menuh);
  DrawBMP(*((pbitmap *)&v1->titleh + (v1->bd.mode == 2) + 40), v1->menuw, 0, v1->menuw, v1->menuh);
  DrawBMP(*((pbitmap *)&v1->launchh + (v1->bd.mode == 3) + 44), 2 * v1->menuw, 0, v1->menuw, v1->menuh);
}


// Address: 0x00412A48; symbol: __ZN6Window9paintfaceEv
void __thiscall Window::paintface(Window *const this)
{
  int face__[6]; // [esp+34h] [ebp-34h]
  int facei; // [esp+4Ch] [ebp-1Ch]

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


// Address: 0x00412B1E; symbol: __ZN6Window11paintnumberElllllll
void __thiscall Window::paintnumber(Window *const this, int n, int l, int x, int y, int w, int h, int b)
{
  int v8; // eax
  int v9; // eax
  Window *thisa; // [esp+2Ch] [ebp-5Ch]
  int dl_0; // [esp+38h] [ebp-50h]
  int digt[10]; // [esp+3Ch] [ebp-4Ch]
  bool minb; // [esp+67h] [ebp-21h]
  int di_0; // [esp+68h] [ebp-20h]
  int dlm; // [esp+6Ch] [ebp-1Ch]

  thisa = this;
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
        DrawBMP(*((pbitmap *)&thisa->titleh + b + 136), w * (dlm - di_0 - 1) + x, y, w, h);
      else
        DrawBMP(*((pbitmap *)&thisa->titlew + b + 140), w * (dlm - di_0 - 1) + x, y, w, h);
    }
    else
    {
      DrawBMP(*((pbitmap *)&thisa->launchh + b + 3 * digt[di_0] + 108), w * (dlm - di_0 - 1) + x, y, w, h);
    }
  }
}


// Address: 0x00412CF2; symbol: __ZN6Window11paintnumberElllll
void __thiscall Window::paintnumber(Window *const this, int n, int l, int x, int y, int b)
{
  Window::paintnumber(this, n, l, x, y, *((_DWORD *)&this->titlew + b + 8), *((_DWORD *)&this->launchh + b + 12), b);
}


// Address: 0x00412D56; symbol: __ZN6Window11paintnumberEllll
void __thiscall Window::paintnumber(Window *const this, int n, int l, int x, int y)
{
  Window::paintnumber(this, n, l, x, y, 0);
}


// Address: 0x00412D94; symbol: __ZN6Window10paintlevelEv
void __thiscall Window::paintlevel(Window *const this)
{
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  signed int score2; // [esp+38h] [ebp-10h]
  int score; // [esp+3Ch] [ebp-Ch]

  thisa = this;
  score = this->bd.line;
  if ( this->singleb )
    score = this->bd.line - this->bd.missline;
  if ( score > 9999 )
  {
    if ( score > 99999 )
      Window::paintnumber(this, score, 6, 0, this->digth[0], 2 * this->singleb);
    else
      Window::paintnumber(this, score, 5, 0, this->digth[0], 2 * this->singleb);
  }
  else
  {
    Window::paintnumber(this, score, 4, 0, this->digth[0], 2 * this->singleb);
  }
  score2 = thisa->bd.level;
  if ( thisa->singleb )
    score2 = thisa->bd.solven;
  if ( score2 > 99 )
  {
    if ( score2 > 999 )
    {
      if ( score2 > 9999 )
        Window::paintnumber(thisa, score2, 5, thisa->w_ - 5 * thisa->digtw[0], thisa->digth[0], 2 * thisa->singleb);
      else
        Window::paintnumber(thisa, score2, 4, thisa->w_ - 4 * thisa->digtw[0], thisa->digth[0], 2 * thisa->singleb);
    }
    else
    {
      Window::paintnumber(thisa, score2, 3, -3 * thisa->digtw[0] + thisa->w_, thisa->digth[0], 2 * thisa->singleb);
    }
  }
  else
  {
    Window::paintnumber(thisa, score2, 2, thisa->w_ - 2 * thisa->digtw[0], thisa->digth[0], 2 * thisa->singleb);
  }
}


// Address: 0x00413050; symbol: __ZN6Window10paintblockER5Blockllllll
void __thiscall Window::paintblock(Window *const this, Block *const b, int i, int j, int x, int y, int w, int h)
{
  Window *thisa; // [esp+2Ch] [ebp-1Ch]

  thisa = this;
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
    Bar(x, y, w - 1, h - 1, thisa->cbg);
  }
  else
  {
    DrawBMP(this->picone, x, y, w, h);
  }
  if ( thisa->cheatb )
  {
    if ( thisa->bd.leftrule[i][j] && thisa->bd.blck[i][j] != 1 && thisa->bd.mask[i][j] != 1 )
      Bar(x, y, thisa->iconw - 1, thisa->iconh - 1, thisa->cblue, thisa->transparent);
    if ( thisa->bd.rightrule[i][j]
      && thisa->bd.blck[i][j] != 1
      && thisa->bd.qstn[i][j] != 1
      && thisa->bd.flag[i][j] != 1
      && thisa->bd.mask[i][j] != 1 )
    {
      Bar(x, y, thisa->iconw - 1, thisa->iconh - 1, thisa->cred, thisa->transparent);
    }
  }
}


// Address: 0x00413534; symbol: __ZN6Window10paintboardER5Blockll
void __thiscall Window::paintboard(Window *const this, Block *const b, int x, int y)
{
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  int j; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]

  thisa = this;
  for ( i = 0; b->w > i; ++i )
  {
    for ( j = 0; b->h > j; ++j )
      Window::paintblock(
        thisa,
        b,
        i,
        j,
        x + i * thisa->iconw,
        thisa->menuh + j * thisa->iconh + y,
        thisa->iconw,
        thisa->iconh);
  }
}


// Address: 0x004135E8; symbol: __ZN6Window10paintboardER5Blockllll
void __thiscall Window::paintboard(Window *const this, Block *const b, int x, int y, int cx_0, int cy)
{
  Window *v6; // ST2C_4

  v6 = this;
  Window::paintboard(this, b, x, y);
  DrawBMP(
    v6->pcursor,
    x + cx_0 * v6->iconw + v6->iconw / 2,
    y + v6->menuh + cy * v6->iconh + v6->iconh / 2,
    v6->cursorw,
    v6->cursorh,
    0xC0C0C0u);
}


// Address: 0x004136B0; symbol: __ZN6Window10paintboardEv
void __thiscall Window::paintboard(Window *const this)
{
  Window *thisa; // [esp+2Ch] [ebp-1Ch]

  thisa = this;
  Window::paintboard(this, &this->bd.0, 0, this->faceh);
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


// Address: 0x0041379C; symbol: __ZN6Window9paintlineEP6bitmaplll
void __thiscall Window::paintline(Window *const this, pbitmap p, int n, int x, int y)
{
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  int k; // [esp+3Ch] [ebp-Ch]

  thisa = this;
  for ( k = 0; k < n; ++k )
    DrawBMP(p, k * thisa->iconw + x, y, thisa->iconw, thisa->iconh);
}


// Address: 0x00413806; symbol: __ZN6Window9paintlineEP6bitmapS1_llll
void __thiscall Window::paintline(Window *const this, pbitmap pa, pbitmap pb, int a, int b, int x, int y)
{
  Window *v7; // ST1C_4

  v7 = this;
  Window::paintline(this, pa, a, x, y);
  Window::paintline(v7, pb, b, a * v7->iconw + x, y);
}


// Address: 0x00413874; symbol: __ZN6Window9paintlineEP6bitmapS1_S1_lllll
void __thiscall Window::paintline(Window *const this, pbitmap pa, pbitmap pb, pbitmap pc, int a, int b, int c, int x, int y)
{
  Window *v9; // ST2C_4

  v9 = this;
  Window::paintline(this, pa, pb, a, b, x, y);
  Window::paintline(v9, pc, c, v9->iconw * (a + b) + x, y);
}


// Address: 0x004138F4; symbol: __ZN6Window9paintlineEP6bitmapS1_S1_S1_llllll
void __thiscall Window::paintline(Window *const this, pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, int a, int b, int c, int d, int x, int y)
{
  Window *v11; // ST2C_4

  v11 = this;
  Window::paintline(this, pa, pb, pc, a, b, c, x, y);
  Window::paintline(v11, pd, d, v11->iconw * (b + a + c) + x, y);
}


// Address: 0x00413988; symbol: __ZN6Window9paintlineEP6bitmapS1_S1_S1_S1_lllllll
void __thiscall Window::paintline(Window *const this, pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, pbitmap pe, int a, int b, int c, int d, int e, int x, int y)
{
  Window *v13; // ST3C_4

  v13 = this;
  Window::paintline(this, pa, pb, pc, pd, a, b, c, d, x, y);
  Window::paintline(v13, pe, e, v13->iconw * (c + b + a + d) + x, y);
}


// Address: 0x00413A2E; symbol: __ZN6Window9painthelpEv
void __thiscall Window::painthelp(Window *const this)
{
  unsigned int v1; // ebx
  unsigned int v2; // edi
  unsigned int v3; // esi
  int v4; // ST34_4
  __int16 *v5; // eax
  unsigned int v6; // esi
  int v7; // ST34_4
  unsigned int v8; // ST30_4
  unsigned int v9; // edi
  int v10; // ebx
  __int16 *v11; // eax
  unsigned int v12; // esi
  int v13; // ST34_4
  unsigned int v14; // ST30_4
  unsigned int v15; // edi
  int v16; // ebx
  __int16 *v17; // eax
  unsigned int v18; // esi
  int v19; // ST34_4
  unsigned int v20; // ST30_4
  unsigned int v21; // edi
  int v22; // ebx
  __int16 *v23; // eax
  unsigned int v24; // esi
  int v25; // ST34_4
  unsigned int v26; // ST30_4
  unsigned int v27; // edi
  int v28; // ebx
  __int16 *v29; // eax
  unsigned int v30; // ebx
  unsigned int v31; // edi
  unsigned int v32; // esi
  int v33; // ST34_4
  __int16 *v34; // eax
  int v35; // ecx
  int v36; // eax
  int *v37; // eax
  bool v38; // al
  ISteamFriends *v39; // eax
  int v40; // ST34_4
  unsigned int v41; // ST30_4
  unsigned int v42; // ST40_4
  int v43; // ebx
  unsigned int v44; // edi
  int v45; // esi
  int v46; // ebx
  unsigned int v47; // eax
  int v48; // ST34_4
  unsigned int v49; // ST30_4
  int v50; // ST40_4
  unsigned int v51; // edi
  bitmap *v52; // eax
  unsigned int v53; // edi
  int v54; // ST34_4
  unsigned int v55; // ST30_4
  int v56; // ST40_4
  int v57; // ebx
  int v58; // esi
  __int16 *v59; // eax
  unsigned int v60; // ebx
  unsigned int v61; // edi
  unsigned int v62; // esi
  int v63; // ST34_4
  __int16 *v64; // eax
  unsigned int v65; // esi
  unsigned int v66; // edi
  int v67; // ST34_4
  int v68; // ST30_4
  int v69; // ST40_4
  int v70; // ebx
  __int16 *v71; // eax
  unsigned int v72; // esi
  unsigned int v73; // edi
  int v74; // ebx
  signed int v75; // eax
  __int16 *v76; // eax
  unsigned int v77; // esi
  unsigned int v78; // edi
  int v79; // ST34_4
  int v80; // ST30_4
  int v81; // ST40_4
  int v82; // ebx
  __int16 *v83; // eax
  unsigned int v84; // ebx
  unsigned int v85; // edi
  unsigned int v86; // esi
  int v87; // ST34_4
  __int16 *v88; // eax
  unsigned int v89; // esi
  int v90; // ST34_4
  int v91; // ST30_4
  int v92; // ST40_4
  int v93; // ebx
  int v94; // edi
  __int16 *v95; // eax
  unsigned int v96; // esi
  unsigned int v97; // edi
  int v98; // ST34_4
  int v99; // ST30_4
  int v100; // ST40_4
  int v101; // ebx
  __int16 *v102; // eax
  unsigned int v103; // edi
  unsigned int v104; // esi
  int v105; // ebx
  int v106; // ST34_4
  unsigned int v107; // eax
  unsigned int v108; // edi
  unsigned int v109; // esi
  int v110; // ebx
  int v111; // ST34_4
  unsigned int v112; // eax
  unsigned int v113; // ebx
  unsigned int v114; // edi
  unsigned int v115; // esi
  int v116; // ST34_4
  __int16 *v117; // eax
  signed int v118; // eax
  unsigned int v119; // edi
  int v120; // ST34_4
  int v121; // ST30_4
  int v122; // ST40_4
  int v123; // ebx
  int v124; // esi
  __int16 *v125; // eax
  unsigned int v126; // ebx
  unsigned int v127; // edi
  unsigned int v128; // esi
  int v129; // ST34_4
  __int16 *v130; // eax
  unsigned int v131; // edi
  int v132; // ST34_4
  int v133; // ST30_4
  int v134; // ST40_4
  int v135; // ebx
  int v136; // esi
  __int16 *v137; // eax
  unsigned int v138; // esi
  int v139; // ST34_4
  int v140; // ST30_4
  unsigned int v141; // edi
  int v142; // ebx
  __int16 *v143; // eax
  unsigned int v144; // ebx
  unsigned int v145; // edi
  unsigned int v146; // esi
  int v147; // ST34_4
  __int16 *v148; // eax
  unsigned int v149; // esi
  int v150; // ST34_4
  int v151; // ST30_4
  unsigned int v152; // edi
  int v153; // ebx
  __int16 *v154; // eax
  unsigned int v155; // esi
  int v156; // ST34_4
  int v157; // ST30_4
  unsigned int v158; // edi
  int v159; // ebx
  __int16 *v160; // eax
  unsigned int v161; // esi
  int v162; // ST34_4
  int v163; // ST30_4
  unsigned int v164; // edi
  int v165; // ebx
  __int16 *v166; // eax
  unsigned int v167; // ebx
  unsigned int v168; // edi
  unsigned int v169; // esi
  int v170; // ST34_4
  __int16 *v171; // eax
  unsigned int v172; // esi
  int v173; // ST34_4
  int v174; // ST30_4
  unsigned int v175; // edi
  int v176; // ebx
  __int16 *v177; // eax
  unsigned int v178; // esi
  int v179; // ST34_4
  int v180; // ST30_4
  unsigned int v181; // edi
  int v182; // ebx
  __int16 *v183; // eax
  unsigned int v184; // esi
  int v185; // ST34_4
  int v186; // ST30_4
  unsigned int v187; // edi
  int v188; // ebx
  __int16 *v189; // eax
  unsigned int v190; // esi
  int v191; // ST34_4
  int v192; // ST30_4
  unsigned int v193; // edi
  int v194; // ebx
  __int16 *v195; // eax
  unsigned int v196; // ebx
  unsigned int v197; // edi
  unsigned int v198; // esi
  int v199; // ST34_4
  __int16 *v200; // eax
  signed int v201; // edx
  signed int v202; // eax
  unsigned int v203; // edi
  int v204; // ST34_4
  unsigned int v205; // ST30_4
  int v206; // ST40_4
  int v207; // esi
  int v208; // ebx
  __int16 *v209; // eax
  unsigned int v210; // edi
  int v211; // ST34_4
  unsigned int v212; // ST30_4
  int v213; // ST40_4
  int v214; // esi
  int v215; // ebx
  __int16 *v216; // eax
  unsigned int v217; // edi
  int v218; // ST34_4
  unsigned int v219; // ST30_4
  int v220; // ST40_4
  int v221; // esi
  int v222; // ebx
  __int16 *v223; // eax
  int v224; // ST34_4
  unsigned int v225; // edi
  unsigned int v226; // esi
  int v227; // ebx
  bitmap *v228; // eax
  unsigned int v229; // edi
  int v230; // ST34_4
  unsigned int v231; // ST30_4
  unsigned int v232; // ST40_4
  int v233; // ebx
  int v234; // esi
  __int16 *v235; // eax
  int v236; // ST34_4
  unsigned int v237; // edi
  unsigned int v238; // esi
  int v239; // ebx
  bitmap *v240; // eax
  unsigned int v241; // edi
  int v242; // ST34_4
  unsigned int v243; // ST30_4
  unsigned int v244; // ST40_4
  int v245; // ebx
  int v246; // esi
  __int16 *v247; // eax
  int v248; // ST34_4
  unsigned int v249; // edi
  unsigned int v250; // esi
  unsigned int v251; // ebx
  bitmap *v252; // eax
  int v253; // ST34_4
  unsigned int v254; // edi
  unsigned int v255; // esi
  unsigned int v256; // ebx
  bitmap *v257; // eax
  int v258; // ST34_4
  unsigned int v259; // edi
  unsigned int v260; // esi
  unsigned int v261; // ebx
  bitmap *v262; // eax
  unsigned int v263; // edi
  int v264; // ST34_4
  unsigned int v265; // ST30_4
  unsigned int v266; // ST40_4
  int v267; // esi
  int v268; // ebx
  __int16 *v269; // eax
  int w; // [esp+30h] [ebp-518h]
  int y; // [esp+34h] [ebp-514h]
  int yd; // [esp+40h] [ebp-508h]
  Window *thisa; // [esp+4Ch] [ebp-4FCh]
  const char *cheatn[9]; // [esp+50h] [ebp-4F8h]
  int v275; // [esp+74h] [ebp-4D4h]
  const char *cheats[9]; // [esp+78h] [ebp-4D0h]
  int v277; // [esp+9Ch] [ebp-4ACh]
  int cheatc[9]; // [esp+A0h] [ebp-4A8h]
  int v279; // [esp+C4h] [ebp-484h]
  int k__[3][3]; // [esp+C8h] [ebp-480h]
  pbitmap v281; // [esp+ECh] [ebp-45Ch]
  pbitmap v282; // [esp+F0h] [ebp-458h]
  pbitmap v283; // [esp+F4h] [ebp-454h]
  int v284; // [esp+F8h] [ebp-450h]
  int v285; // [esp+FCh] [ebp-44Ch]
  pbitmap v286; // [esp+100h] [ebp-448h]
  pbitmap v287; // [esp+104h] [ebp-444h]
  pbitmap v288; // [esp+108h] [ebp-440h]
  BOOL v289; // [esp+10Ch] [ebp-43Ch]
  BOOL v290; // [esp+110h] [ebp-438h]
  BOOL v291; // [esp+114h] [ebp-434h]
  BOOL v292; // [esp+118h] [ebp-430h]
  BOOL v293; // [esp+11Ch] [ebp-42Ch]
  BOOL v294; // [esp+120h] [ebp-428h]
  BOOL v295; // [esp+128h] [ebp-420h]
  BOOL v296; // [esp+12Ch] [ebp-41Ch]
  BOOL v297; // [esp+134h] [ebp-414h]
  BOOL v298; // [esp+138h] [ebp-410h]
  pbitmap picon__[3][3][5]; // [esp+1CCh] [ebp-37Ch]
  pbitmap v300; // [esp+280h] [ebp-2C8h]
  pbitmap v301; // [esp+284h] [ebp-2C4h]
  pbitmap v302; // [esp+288h] [ebp-2C0h]
  pbitmap v303; // [esp+28Ch] [ebp-2BCh]
  pbitmap v304; // [esp+290h] [ebp-2B8h]
  pbitmap v305; // [esp+294h] [ebp-2B4h]
  pbitmap v306; // [esp+298h] [ebp-2B0h]
  pbitmap v307; // [esp+29Ch] [ebp-2ACh]
  pbitmap v308; // [esp+2A0h] [ebp-2A8h]
  pbitmap v309; // [esp+2A4h] [ebp-2A4h]
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

  thisa = this;
  switch ( this->helpi )
  {
    case (int)0xFFFFFFFD:
      goto LABEL_42;
    case (int)0xFFFFFFFE:
      Window::setfontheight_(this, this->faceh);
      v30 = thisa->cbg;
      v31 = thisa->ctfg;
      v32 = thisa->faceh;
      v33 = thisa->helpw;
      v34 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP + 9);
      Window::drawtextxy_(thisa, thisa->pwint, v34, 0, 0, v33, v32, v31, v30);
      Window::setfontheight_(thisa, thisa->fontfh);
      if ( thisa->bd.st.steamb )
      {
        Window::setfontheight_(thisa, thisa->fontsh - 1);
        pmenu__[0] = thisa->pmenu1[0];
        pmenu__[1] = thisa->pmenu2[0];
        pmenu__[2] = thisa->pmenu3[0];
        LeaderboardEntry_t::LeaderboardEntry_t((LeaderboardEntry_t *const )cheatc);
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
              v35 = (int)(*thisa->bd.st.leadsn)[15];
              v36 = 32 * (k - 10 + 20 * (leadid + 3 * thisa->lead_5));
            }
            else
            {
              v35 = (int)thisa->bd.st.leadsn;
              v36 = 32 * (rank_ + k + 20 * (leadid + 3 * thisa->lead_5));
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
            v38 = (*thisa->bd.st.leadsn)[3 * thisa->lead_5 + 30][20 * leadid].m_nGlobalRank == cheatc[2]
               && (signed int)CSteamID::GetEAccountType((const CSteamID *const )cheatc) > 0;
            if ( v38 )
              Window::setfontweight_(thisa, 0x2BCu);
            if ( (signed int)CSteamID::GetEAccountType((const CSteamID *const )cheatc) > 0 )
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
              Window::drawtextxy_(
                thisa,
                thisa->pwint,
                (const char *)k__,
                leadid * thisa->helpw / 3,
                thisa->faceh + k * thisa->fontsh + thisa->menuh + 1,
                thisa->ctfg,
                thisa->cbg);
              v40 = thisa->cbg;
              v41 = thisa->ctfg;
              v42 = thisa->fontsh;
              v43 = thisa->helpw / 3;
              v44 = v43
                  - Window::getstringwidth_(thisa, "00000")
                  - 4 * (thisa->digtw[1] * thisa->fontsh / thisa->digth[1]);
              v45 = thisa->faceh + k * thisa->fontsh + thisa->menuh + 1;
              v46 = leadid * thisa->helpw / 3;
              v47 = Window::getstringwidth_(thisa, "00000");
              Window::drawtextxy_(
                thisa,
                thisa->pwint,
                (const __int16 *)&picon__[0][0][2],
                v46 + v47,
                v45,
                v44,
                v42,
                v41,
                v40,
                0);
              Window::paintnumber(
                thisa,
                cheatc[3],
                4,
                (leadid + 1) * thisa->helpw / 3 - 4 * (thisa->digtw[1] * thisa->fontsh / thisa->digth[1]),
                thisa->faceh + k * thisa->fontsh + thisa->menuh,
                thisa->digtw[1] * thisa->fontsh / thisa->digth[1],
                thisa->fontsh,
                1);
            }
            Window::setfontweight_(thisa, 0);
          }
        }
        Window::setfontheight_(thisa, thisa->fonth);
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
            score,
            n__[k_0] + 4 + (*((_DWORD *)&thisa->menuw + scr__[k_0] + 384) > 9999) * (k_0 <= 1),
            (2 * k_0 + 1) * thisa->helpw / 6 - 2 * thisa->digtw[0] + thisa->facew - thisa->digtw[0] * n__[k_0],
            thisa->menuh + (thisa->helph + 20 * thisa->fontsh - thisa->okh_) / 2 + 1,
            2 * thisa->singleb * (k_0 <= 1));
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
          v48 = thisa->faceh;
          v49 = thisa->facew;
          v50 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
          v51 = thisa->facew * k_1
              + ((thisa->helpw + thisa->okw) / 2 + thisa->helpw) / 2
              + ((signed int)(((unsigned int)(-5 * thisa->facew) >> 31) - 5 * thisa->facew) >> 1);
          v52 = GetWin();
          DrawBMP(*((pbitmap *)&thisa->launchh + (thisa->lead_5 == k_1) + 2 * k_[k_1] + 60), v52, v51, v50, v49, v48);
        }
        Window::setfontheight_(thisa, thisa->faceh);
        v53 = thisa->cbg;
        v54 = thisa->ctfg;
        v55 = thisa->faceh;
        v56 = thisa->helpw + (thisa->helpw + thisa->okw) / -2;
        v57 = thisa->menuh + thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->faceh;
        v58 = (thisa->helpw + thisa->okw) / 2;
        v59 = Lan::getlan(&thisa->bd.st.lan, thisa->lead_5 + thisa->bd.st.lan.LAN_MODE);
        Window::drawtextxy_(thisa, thisa->pwint, v59, v58, v57, v56, v55, v54, v53);
        Window::setfontheight_(thisa, thisa->fonth);
      }
      else
      {
LABEL_42:
        Window::setfontheight_(thisa, thisa->faceh);
        v60 = thisa->cbg;
        v61 = thisa->ctfg;
        v62 = thisa->faceh;
        v63 = thisa->helpw;
        v64 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP + 8);
        Window::drawtextxy_(thisa, thisa->pwint, v64, 0, 0, v63, v62, v61, v60);
        Window::setfontheight_(thisa, thisa->fonth);
        memset(cheatn, 0, 0x28u);
        cheatn[0] = *((const char **)&thisa->titleh + thisa->bd.sd.soundb + 48);
        cheatn[1] = *((const char **)&thisa->launchh + thisa->bd.sd.musicb + 52);
        cheatn[2] = *((const char **)&thisa->launchh + 2 * (thisa->md + 30));
        cheatn[4] = (const char *)thisa->pface[8];
        cheatn[5] = (const char *)thisa->pface[7];
        cheatn[7] = (const char *)thisa->picon[0];
        cheatn[8] = (const char *)thisa->picon[0];
        v275 = *((_DWORD *)&thisa->titleh + thisa->singleb + 56);
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
        k__[0][0] = thisa->bd.sd.soundb;
        k__[0][1] = !thisa->bd.sd.soundb;
        k__[1][0] = thisa->bd.sd.musicb;
        k__[1][1] = !thisa->bd.sd.musicb;
        k__[2][0] = thisa->md == 0;
        k__[2][1] = thisa->md == 1;
        v281 = (pbitmap)(thisa->md == 2);
        v282 = (pbitmap)(thisa->md == 3);
        v284 = thisa->mult_ == 0;
        v285 = thisa->mult_ == 1;
        v286 = (pbitmap)(thisa->mult_ > 1);
        v287 = (pbitmap)(thisa->colori == 0);
        v288 = (pbitmap)(thisa->colori == 1);
        v289 = thisa->colori == 2;
        v290 = thisa->colori == 3;
        v291 = thisa->colori == 4;
        v292 = thisa->colori == 5;
        v293 = thisa->bd.delayb == 1;
        v294 = thisa->bd.delayb == 0;
        v295 = thisa->barb;
        v296 = !thisa->barb;
        v297 = !thisa->singleb;
        v298 = thisa->singleb;
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
            v65 = thisa->cbg;
            v66 = thisa->ctfg;
            v67 = thisa->faceh;
            v68 = thisa->helpw / 4 - thisa->facew - 2 * thisa->iconw;
            v69 = (signed int)((long double)k_2 * helph__
                             + (long double)(signed int)thisa->menuh
                             + (long double)(signed int)thisa->iconh);
            v70 = helpw__ + thisa->facew + thisa->iconw;
            v71 = Lan::getlan(&thisa->bd.st.lan, (int)&cheats[k_2][thisa->bd.st.lan.LAN_HELP]);
            Window::drawtextxy_(thisa, thisa->pwint, v71, v70, v69, v68, v67, v66, v65, 0);
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
              v77 = thisa->cbg;
              v78 = thisa->ctfg;
              v79 = thisa->faceh;
              v80 = thisa->helpw / 4 - thisa->facew - 2 * thisa->iconw;
              v81 = (signed int)((long double)k_2 * helph__
                               + (long double)(signed int)thisa->menuh
                               + (long double)(signed int)thisa->iconh);
              v82 = thisa->facew + (j + 1) * (thisa->helpw / 4) + thisa->iconw;
              v83 = Lan::getlan(&thisa->bd.st.lan, (int)picon__[0][0][3 * k_2 + j] + thisa->bd.st.lan.LAN_SET);
              Window::drawtextxy_(thisa, thisa->pwint, v83, v82, v81, v80, v79, v78, v77, 0);
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
              v72 = thisa->cbg;
              v73 = thisa->ctfg;
              y = thisa->faceh;
              w = thisa->helpw / 4 - thisa->facew - 2 * thisa->iconw;
              yd = (signed int)((long double)k_2 * helph__
                              + (long double)(signed int)thisa->menuh
                              + (long double)(signed int)thisa->iconh);
              v74 = (j + 1) * (thisa->helpw / 4) + 3 * thisa->facew + thisa->iconw;
              v75 = thisa->mult_;
              if ( v75 < 2 )
                v75 = 2;
              v76 = Lan::getlan(&thisa->bd.st.lan, (int)picon__[0][0][3 * k_2 + j] + thisa->bd.st.lan.LAN_SET + v75 - 2);
              Window::drawtextxy_(thisa, thisa->pwint, v76, v74, yd, w, y, v73, v72, 0);
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
    case (int)0xFFFFFFFF:
      Window::setfontheight_(this, this->faceh);
      v1 = thisa->cbg;
      v2 = thisa->ctfg;
      v3 = thisa->faceh;
      v4 = thisa->aboutw;
      v5 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP + 7);
      Window::drawtextxy_(thisa, thisa->pwint, v5, 0, 0, v4, v3, v2, v1);
      Window::setfontheight_(thisa, thisa->fontfh);
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
      Window::setfontheight_(thisa, thisa->fonth);
      v6 = thisa->cbg;
      v7 = thisa->ctfg;
      v8 = thisa->fonth;
      v9 = thisa->aboutw;
      v10 = thisa->menuh + thisa->fontth;
      v11 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_ABOUT_NAME);
      Window::drawtextxy_(thisa, thisa->pwint, v11, 0, v10, v9, v8, v7, v6);
      v12 = thisa->cbg;
      v13 = thisa->ctfg;
      v14 = thisa->fonth;
      v15 = thisa->aboutw;
      v16 = thisa->fontth + thisa->menuh + thisa->fonth;
      v17 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_ABOUT_VERSION);
      Window::drawtextxy_(thisa, thisa->pwint, v17, 0, v16, v15, v14, v13, v12);
      v18 = thisa->cbg;
      v19 = thisa->ctfg;
      v20 = thisa->fonth;
      v21 = thisa->aboutw;
      v22 = thisa->fontth + thisa->menuh + 2 * thisa->fonth;
      v23 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_ABOUT_AUTHOR);
      Window::drawtextxy_(thisa, thisa->pwint, v23, 0, v22, v21, v20, v19, v18);
      v24 = thisa->cbg;
      v25 = thisa->ctfg;
      v26 = thisa->fonth;
      v27 = thisa->aboutw;
      v28 = thisa->menuh + thisa->fontth + 3 * thisa->fonth;
      v29 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_ABOUT_LICENSE);
      Window::drawtextxy_(thisa, thisa->pwint, v29, 0, v28, v27, v26, v25, v24);
      break;
    case 1:
      Window::setfontheight_(this, this->faceh);
      v84 = thisa->cbg;
      v85 = thisa->ctfg;
      v86 = thisa->faceh;
      v87 = thisa->helpw;
      v88 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP + 6);
      Window::drawtextxy_(thisa, thisa->pwint, v88, 0, 0, v87, v86, v85, v84);
      v89 = thisa->cbg;
      v90 = thisa->ctfg;
      v91 = (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2;
      v92 = thisa->helpw / 2;
      v93 = thisa->menuh;
      v94 = thisa->helpw / 2;
      v95 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_TITLE);
      Window::drawtextxy_(thisa, thisa->pwint, v95, v94, v93, v92, v91, v90, v89);
      Window::setfontheight_(thisa, thisa->fonth);
      k__[0][0] = (int)thisa->pmenu1[0];
      k__[0][1] = (int)thisa->pmenu2[0];
      k__[0][2] = (int)thisa->pmenu3[0];
      k__[1][0] = (int)thisa->pface[4];
      k__[1][1] = (int)thisa->pface[0];
      k__[1][2] = (int)thisa->picone;
      k__[2][0] = (int)thisa->pmenuq[0];
      k__[2][1] = (int)thisa->pmenua[0];
      k__[2][2] = (int)thisa->pmenud[0];
      v281 = thisa->pmenut[0];
      v282 = thisa->pmenus[0];
      v283 = thisa->pmenum[0];
      v284 = *((_DWORD *)&thisa->launchh + 2 * (thisa->md + 30));
      v285 = *((_DWORD *)&thisa->titleh + thisa->singleb + 56);
      v286 = thisa->pface[7];
      v287 = thisa->pface[6];
      v288 = thisa->pface[5];
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
          thisa,
          thisa->pwint,
          (const char *)picon__[0][0][k_3],
          helpw___0 + thisa->facew + thisa->iconw,
          (signed int)((long double)k_3 * helph___0
                     + (long double)(signed int)thisa->menuh
                     + (long double)(thisa->iconh / 2)),
          thisa->ctfg,
          thisa->cbg);
      }
      if ( thisa->cheatb == 1 )
      {
        for ( k_5 = 0; k_5 <= 8; ++k_5 )
        {
          Window::drawtextxy_(
            thisa,
            thisa->pwint,
            cheatn[k_5],
            thisa->helpw / 4,
            (signed int)((long double)k_5 * helph___0
                       + (long double)(signed int)thisa->menuh
                       + (long double)(thisa->iconh / 2)),
            cheatc[k_5],
            thisa->cbg);
          Window::drawtextxy_(
            thisa,
            thisa->pwint,
            cheats[k_5],
            thisa->helpw / 4 + thisa->facew,
            (signed int)((long double)k_5 * helph___0
                       + (long double)(signed int)thisa->menuh
                       + (long double)(thisa->iconh / 2)),
            cheatc[k_5],
            thisa->cbg);
        }
      }
      else
      {
        for ( k_4 = 0; k_4 <= 16; ++k_4 )
        {
          v96 = thisa->cbg;
          v97 = thisa->ctfg;
          v98 = thisa->faceh;
          v99 = thisa->helpw / 4;
          v100 = (signed int)((long double)k_4 * helph___0
                            + (long double)(signed int)thisa->menuh
                            + (long double)(thisa->iconh / 2));
          v101 = thisa->helpw / 4;
          v102 = Lan::getlan(&thisa->bd.st.lan, k_4 + thisa->bd.st.lan.LAN_HELP);
          Window::drawtextxy_(thisa, thisa->pwint, v102, v101, v100, v99, v98, v97, v96, 0);
        }
      }
      Line(thisa->helpw / 2, thisa->menuh, 0, thisa->helph - thisa->okh_, thisa->cline);
      for ( k_6 = 0; k_6 <= 11; ++k_6 )
        Window::paintline(
          thisa,
          thisa->piconn,
          thisa->piconc,
          2,
          10,
          (3 * thisa->helpw / 2 - 12 * thisa->iconw) / 2,
          (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + thisa->menuh + (k_6 + 8) * thisa->iconh);
      v103 = thisa->cbg;
      v104 = thisa->cred;
      v105 = 8 * thisa->iconh + thisa->menuh + (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 - thisa->faceh;
      v106 = 3 * thisa->helpw / 2;
      v107 = Window::getstringwidth_(thisa, "PgUp");
      Window::drawtextxy_(thisa, thisa->pwint, "PgUp", (v106 - v107) >> 1, v105, v104, v103);
      v108 = thisa->cfg;
      v109 = thisa->cblue;
      v110 = thisa->menuh + (thisa->helph - thisa->okh_ - 20 * thisa->iconh) / 2 + 8 * thisa->iconh;
      v111 = 3 * thisa->helpw / 2;
      v112 = Window::getstringwidth_(thisa, "PgDn");
      Window::drawtextxy_(thisa, thisa->pwint, "PgDn", (v111 - v112) >> 1, v110, v109, v108);
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
      Window::setfontheight_(this, this->faceh);
      v113 = thisa->cbg;
      v114 = thisa->ctfg;
      v115 = thisa->faceh;
      v116 = thisa->helpw;
      v117 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_TITLE + 1);
      Window::drawtextxy_(thisa, thisa->pwint, v117, 0, 0, v116, v115, v114, v113);
      Window::setfontheight_(thisa, thisa->fontmh);
      for ( j_0 = 0; j_0 <= 2; ++j_0 )
      {
        for ( i = 0; i <= 3; ++i )
        {
          Block::initbl(&thisa->bl);
          v118 = j_0;
          if ( j_0 > 0 )
            v118 = 1;
          j_ = v118;
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
            &thisa->bl,
            (2 * i + 1) * thisa->helpw / 8 + thisa->bl.w * thisa->iconw / -2,
            (2 * j_0 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->bl.h * thisa->iconh / -2,
            1,
            j_);
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
            v119 = thisa->cbg;
            v120 = thisa->ctfg;
            v121 = 2 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 - thisa->clickh;
            v122 = thisa->helpw / 2;
            v123 = thisa->menuh
                 + thisa->clickh
                 + -3 * thisa->iconh
                 + (2 * j_1 + 1) * (thisa->helph - thisa->okh_) / 6
                 + thisa->iconh;
            v124 = i_0 / 2 * thisa->helpw / 2;
            v125 = Lan::getlan(&thisa->bd.st.lan, 2 * j_1 + thisa->bd.st.lan.LAN_HELP_MENU + i_0 / 2);
            Window::drawtextxy_(thisa, thisa->pwint, v125, v124, v123, v122, v121, v120, v119);
          }
        }
      }
      Line(thisa->helpw / 2, thisa->menuh, 0, thisa->helph - thisa->okh_, thisa->cline);
      for ( k_8 = 1; k_8 <= 2; ++k_8 )
        Line(0, thisa->menuh + k_8 * (thisa->helph - thisa->okh_) / 3, thisa->helpw, 0, thisa->cline);
      Window::setfontheight_(thisa, thisa->fonth);
      break;
    case 3:
      Window::setfontheight_(this, this->faceh);
      v126 = thisa->cbg;
      v127 = thisa->ctfg;
      v128 = thisa->faceh;
      v129 = thisa->helpw;
      v130 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_TITLE + 2);
      Window::drawtextxy_(thisa, thisa->pwint, v130, 0, 0, v129, v128, v127, v126);
      Window::setfontheight_(thisa, thisa->fontmh);
      for ( j_2 = 0; j_2 <= 2; ++j_2 )
      {
        for ( i_1 = 0; i_1 <= 3; ++i_1 )
        {
          Block::initbl(&thisa->bl);
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
              &thisa->bl,
              (2 * i_1 + 1 + (j_2 != 0)) * thisa->helpw / 8 + thisa->bl.w * thisa->iconw / -2,
              (2 * j_2 + 1) * (thisa->helph - thisa->okh_) / 6 + thisa->bl.h * thisa->iconh / -2,
              1,
              j__0);
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
          v300 = thisa->piconf;
          v301 = thisa->piconu;
          v302 = thisa->picon[2];
          v303 = thisa->piconp;
          v304 = thisa->piconp;
          v305 = thisa->piconp;
          v306 = thisa->piconp;
          v307 = thisa->piconp;
          v308 = thisa->piconp;
          v309 = thisa->piconp;
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
            v131 = thisa->cbg;
            v132 = thisa->ctfg;
            v133 = 2 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 - thisa->clickh;
            v134 = thisa->helpw / 2;
            v135 = thisa->menuh + thisa->clickh + -3 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 + thisa->iconh;
            v136 = i_2 / 2 * thisa->helpw / 2;
            v137 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + i_2 / 2 + 6);
            Window::drawtextxy_(thisa, thisa->pwint, v137, v136, v135, v134, v133, v132, v131);
          }
          if ( !i_2 && j_3 > 0 )
          {
            v138 = thisa->cbg;
            v139 = thisa->ctfg;
            v140 = 2 * thisa->iconh + (thisa->helph - thisa->okh_) / 6 - thisa->clickh;
            v141 = thisa->helpw;
            v142 = thisa->menuh
                 + thisa->clickh
                 + -3 * thisa->iconh
                 + (2 * j_3 + 1) * (thisa->helph - thisa->okh_) / 6
                 + thisa->iconh;
            v143 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + j_3 + 7);
            Window::drawtextxy_(thisa, thisa->pwint, v143, 0, v142, v141, v140, v139, v138);
          }
        }
      }
      Line(thisa->helpw / 2, thisa->menuh, 0, (thisa->helph - thisa->okh_) / 3, thisa->cline);
      for ( k_10 = 1; k_10 <= 2; ++k_10 )
        Line(0, thisa->menuh + k_10 * (thisa->helph - thisa->okh_) / 3, thisa->helpw, 0, thisa->cline);
      break;
    case 4:
      Window::setfontheight_(this, this->faceh);
      v144 = thisa->cbg;
      v145 = thisa->ctfg;
      v146 = thisa->faceh;
      v147 = thisa->helpw;
      v148 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_TITLE + 3);
      Window::drawtextxy_(thisa, thisa->pwint, v148, 0, 0, v147, v146, v145, v144);
      Window::setfontheight_(thisa, thisa->fontmh);
      iconwl = 5;
      iconwm = 18;
      iconwr = 20;
      iconwn = 34;
      iconh1 = 2;
      iconh2 = 10;
      iconh3 = 21;
      Window::paintline(thisa, thisa->picone, 2, 20 * thisa->iconw, 2 * thisa->iconh + thisa->menuh);
      Window::paintline(thisa, thisa->piconc, 12, 20 * thisa->iconw, 3 * thisa->iconh + thisa->menuh);
      Window::paintline(thisa, thisa->piconc, 12, 20 * thisa->iconw, 4 * thisa->iconh + thisa->menuh);
      Window::paintline(thisa, thisa->picone, 2, 5 * thisa->iconw, 4 * thisa->iconh + thisa->menuh);
      Window::paintline(
        thisa,
        thisa->piconc,
        thisa->piconm,
        thisa->picon[1],
        thisa->piconp,
        5,
        1,
        1,
        5,
        5 * thisa->iconw,
        5 * thisa->iconh + thisa->menuh);
      Window::paintline(
        thisa,
        thisa->piconc,
        thisa->piconf,
        thisa->picon[1],
        thisa->piconp,
        5,
        1,
        1,
        5,
        20 * thisa->iconw,
        5 * thisa->iconh + thisa->menuh);
      DrawBMP(thisa->picona, 18 * thisa->iconw, 5 * thisa->iconh + thisa->menuh, thisa->cfg);
      DrawBMP(
        thisa->pface[3],
        18 * thisa->iconw + (thisa->facew - thisa->iconw) / -2,
        thisa->menuh + 5 * thisa->iconh - thisa->iconh + thisa->faceh / -2,
        thisa->cfg);
      v149 = thisa->cbg;
      v150 = thisa->ctfg;
      v151 = 2 * thisa->iconh;
      v152 = thisa->helpw;
      v153 = 6 * thisa->iconh + thisa->menuh;
      v154 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + 10);
      Window::drawtextxy_(thisa, thisa->pwint, v154, 0, v153, v152, v151, v150, v149);
      for ( k_11 = 0; k_11 <= 2; ++k_11 )
      {
        Window::paintline(
          thisa,
          thisa->picone,
          2,
          iconwl * thisa->iconw,
          (3 * k_11 + iconh2) * thisa->iconh + thisa->menuh);
        Window::paintline(
          thisa,
          thisa->picone,
          k_11 + 3,
          iconwr * thisa->iconw,
          (3 * k_11 + iconh2) * thisa->iconh + thisa->menuh);
        Window::paintline(
          thisa,
          thisa->piconc,
          12,
          iconwl * thisa->iconw,
          (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->menuh);
        Window::paintline(
          thisa,
          thisa->piconc,
          12,
          iconwr * thisa->iconw,
          (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->menuh);
        Window::paintnumber(
          thisa,
          5 * k_11,
          2,
          iconwn * thisa->iconw,
          thisa->menuh + (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->digth[0] / -2);
        DrawBMP(thisa->picona, iconwm * thisa->iconw, (3 * k_11 + iconh2 + 1) * thisa->iconh + thisa->menuh, thisa->cfg);
      }
      v155 = thisa->cbg;
      v156 = thisa->ctfg;
      v157 = (iconh3 - iconh2 - 10) * thisa->iconh + thisa->iconh / 2;
      v158 = thisa->helpw;
      v159 = thisa->iconh * (iconh2 + 8) + thisa->menuh;
      v160 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + 11);
      Window::drawtextxy_(thisa, thisa->pwint, v160, 0, v159, v158, v157, v156, v155);
      Window::paintline(thisa, thisa->picone, 12, iconwl * thisa->iconw, iconh3 * thisa->iconh + thisa->menuh);
      Window::paintline(thisa, thisa->piconc, 12, iconwr * thisa->iconw, iconh3 * thisa->iconh + thisa->menuh);
      Window::paintline(thisa, thisa->piconc, 12, iconwl * thisa->iconw, thisa->iconh * (iconh3 + 1) + thisa->menuh);
      Window::paintline(thisa, thisa->piconc, 12, iconwr * thisa->iconw, thisa->iconh * (iconh3 + 1) + thisa->menuh);
      DrawBMP(thisa->picona, iconwm * thisa->iconw, thisa->iconh * (iconh3 + 1) + thisa->menuh, thisa->cfg);
      v161 = thisa->cbg;
      v162 = thisa->ctfg;
      v163 = thisa->helph - thisa->okh_ - (iconh3 + 2) * thisa->iconh;
      v164 = thisa->helpw;
      v165 = thisa->iconh * (iconh3 + 2) + thisa->menuh;
      v166 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + 12);
      Window::drawtextxy_(thisa, thisa->pwint, v166, 0, v165, v164, v163, v162, v161);
      Line(0, thisa->menuh + (iconh2 - 2) * thisa->iconh, thisa->helpw, 0, thisa->cline);
      Line(0, (iconh3 - 2) * thisa->iconh + thisa->menuh + thisa->iconh / 2, thisa->helpw, 0, thisa->cline);
      Window::setfontheight_(thisa, thisa->fonth);
      break;
    case 5:
      Window::setfontheight_(this, this->faceh);
      v167 = thisa->cbg;
      v168 = thisa->ctfg;
      v169 = thisa->faceh;
      v170 = thisa->helpw;
      v171 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_TITLE + 4);
      Window::drawtextxy_(thisa, thisa->pwint, v171, 0, 0, v170, v169, v168, v167);
      Window::setfontheight_(thisa, thisa->fontmh);
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
        thisa->piconc,
        thisa->picon[2],
        thisa->piconp,
        4,
        1,
        7,
        3 * thisa->iconw,
        thisa->iconh / -2 + 2 * thisa->iconh + thisa->menuh);
      Window::paintline(
        thisa,
        thisa->piconc,
        thisa->piconf,
        thisa->picon[2],
        thisa->piconp,
        2,
        2,
        1,
        7,
        3 * thisa->iconw,
        thisa->iconh / -2 + 3 * thisa->iconh + thisa->menuh);
      Window::paintline(
        thisa,
        thisa->piconc,
        thisa->piconf,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        2,
        1,
        1,
        1,
        7,
        3 * thisa->iconw,
        thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh);
      Window::paintline(
        thisa,
        thisa->piconc,
        thisa->picon[1],
        thisa->piconp,
        4,
        1,
        7,
        20 * thisa->iconw,
        thisa->iconh / -2 + 3 * thisa->iconh + thisa->menuh);
      Window::paintline(
        thisa,
        thisa->piconc,
        thisa->piconf,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        2,
        1,
        1,
        1,
        7,
        20 * thisa->iconw,
        thisa->iconh / -2 + 4 * thisa->iconh + thisa->menuh);
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
        1,
        4,
        34 * thisa->iconw,
        thisa->menuh + thisa->iconh / -2 + 4 * thisa->iconh + thisa->digth[0] / -2);
      v172 = thisa->cbg;
      v173 = thisa->ctfg;
      v174 = 3 * thisa->iconh / 2;
      v175 = thisa->helpw;
      v176 = thisa->iconh / -2 + 5 * thisa->iconh + thisa->menuh;
      v177 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + 13);
      Window::drawtextxy_(thisa, thisa->pwint, v177, 0, v176, v175, v174, v173, v172);
      Window::paintline(
        thisa,
        thisa->piconc,
        thisa->picon[2],
        thisa->piconp,
        4,
        1,
        7,
        3 * thisa->iconw,
        6 * thisa->iconh + thisa->menuh);
      Window::paintline(
        thisa,
        thisa->picon[1],
        thisa->picon[4],
        thisa->piconc,
        thisa->picon[2],
        thisa->piconp,
        1,
        1,
        2,
        1,
        7,
        3 * thisa->iconw,
        7 * thisa->iconh + thisa->menuh);
      Window::paintline(
        thisa,
        thisa->piconc,
        thisa->piconc,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        2,
        1,
        1,
        1,
        7,
        3 * thisa->iconw,
        8 * thisa->iconh + thisa->menuh);
      Window::paintline(
        thisa,
        thisa->piconc,
        thisa->picon[1],
        thisa->piconp,
        4,
        1,
        7,
        20 * thisa->iconw,
        7 * thisa->iconh + thisa->menuh);
      Window::paintline(
        thisa,
        thisa->piconc,
        thisa->picon[3],
        thisa->picon[1],
        thisa->piconp,
        3,
        1,
        1,
        7,
        20 * thisa->iconw,
        8 * thisa->iconh + thisa->menuh);
      Line(3 * thisa->iconw, thisa->menuh + thisa->iconh / 2 + 7 * thisa->iconh, 12 * thisa->iconw, 0, thisa->cred);
      DrawBMP(thisa->piconc, 16 * thisa->iconw, 8 * thisa->iconh + thisa->menuh, thisa->cbg);
      DrawBMP(thisa->piconu, 17 * thisa->iconw, 8 * thisa->iconh + thisa->menuh, thisa->cfg);
      DrawBMP(thisa->piconn, 18 * thisa->iconw, 8 * thisa->iconh + thisa->menuh, thisa->cbg);
      DrawBMP(
        thisa->pface[4],
        17 * thisa->iconw + (thisa->facew - thisa->iconw) / -2,
        thisa->menuh + 8 * thisa->iconh - thisa->iconh + thisa->faceh / -2,
        thisa->cbg);
      Window::paintnumber(thisa, 1, 4, 34 * thisa->iconw, thisa->menuh + 8 * thisa->iconh + thisa->digth[0] / -2);
      v178 = thisa->cbg;
      v179 = thisa->ctfg;
      v180 = 3 * thisa->iconh / 2;
      v181 = thisa->helpw;
      v182 = 9 * thisa->iconh + thisa->menuh;
      v183 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + 14);
      Window::drawtextxy_(thisa, thisa->pwint, v183, 0, v182, v181, v180, v179, v178);
      Window::paintline(
        thisa,
        thisa->piconp,
        12,
        3 * thisa->iconw,
        thisa->iconh / -2 + 15 * thisa->iconh + thisa->menuh);
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
            thisa->piconc,
            12,
            iconwl_0 * thisa->iconw,
            thisa->iconh / -2 + thisa->iconh * (iconh3_0 + k_12) + thisa->menuh);
        if ( k_12 > 0 )
          Window::paintline(
            thisa,
            thisa->piconc,
            12,
            iconwr_0 * thisa->iconw,
            thisa->iconh / -2 + thisa->iconh * (iconh3_0 + k_12) + thisa->menuh);
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
        5,
        4,
        iconwn_0 * thisa->iconw,
        thisa->menuh + thisa->iconh / -2 + thisa->iconh * (iconh3_0 + 7) + thisa->digth[0] / -2);
      v184 = thisa->cbg;
      v185 = thisa->ctfg;
      v186 = 3 * thisa->iconh / 2;
      v187 = thisa->helpw;
      v188 = thisa->iconh / -2 + thisa->iconh * (iconh3_0 + 8) + thisa->menuh;
      v189 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + 15);
      Window::drawtextxy_(thisa, thisa->pwint, v189, 0, v188, v187, v186, v185, v184);
      for ( k_13 = 0; k_13 <= 2; ++k_13 )
      {
        Window::paintnumber(
          thisa,
          (k_13 + 2) * (k_13 + 2),
          4,
          (2 * k_13 + 1) * thisa->helpw / 6 - 4 * thisa->digtw[0] + thisa->iconw / -2,
          thisa->menuh + iconh4 * thisa->iconh + thisa->digth[0] / -2);
        Window::paintnumber(
          thisa,
          k_13 + 2,
          2,
          2 * thisa->digtw[0] + (2 * k_13 + 1) * thisa->helpw / 6 + thisa->iconw / 2,
          thisa->menuh + iconh4 * thisa->iconh + thisa->digth[0] / -2);
        DrawBMP(
          thisa->picona,
          thisa->digtw[0] + (2 * k_13 + 1) * thisa->helpw / 6 + thisa->iconw / -2,
          thisa->menuh + iconh4 * thisa->iconh + thisa->iconh / -2,
          thisa->cfg);
      }
      v190 = thisa->cbg;
      v191 = thisa->ctfg;
      v192 = thisa->helph - thisa->okh_ - (iconh4 * thisa->iconh + thisa->digth[0] / 2);
      v193 = thisa->helpw;
      v194 = thisa->digth[0] / 2 + iconh4 * thisa->iconh + thisa->menuh;
      v195 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + 16);
      Window::drawtextxy_(thisa, thisa->pwint, v195, 0, v194, v193, v192, v191, v190);
      Line(0, thisa->menuh + thisa->iconh * (iconh3_0 - 1) + thisa->iconh / 2, thisa->helpw, 0, thisa->cline);
      Line(0, thisa->iconh * (iconh4 - 2) + thisa->menuh, thisa->helpw, 0, thisa->cline);
      Window::setfontheight_(thisa, thisa->fonth);
      break;
    case 6:
      Window::setfontheight_(this, this->faceh);
      v196 = thisa->cbg;
      v197 = thisa->ctfg;
      v198 = thisa->faceh;
      v199 = thisa->helpw;
      v200 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_TITLE + 5);
      Window::drawtextxy_(thisa, thisa->pwint, v200, 0, 0, v199, v198, v197, v196);
      Window::setfontheight_(thisa, thisa->fontmh);
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
          v201 = 2;
        else
          v201 = 3;
        if ( j_5 <= 15 )
          v202 = 0;
        else
          v202 = 3;
        Window::paintline(
          thisa,
          thisa->piconn,
          v201 + v202,
          5 * thisa->iconw,
          thisa->iconh / 2 + thisa->menuh + (j_5 + 1) * thisa->iconh - thisa->iconh);
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
      v203 = thisa->cfg;
      v204 = thisa->ctfg;
      v205 = thisa->fontmh;
      v206 = 15 * thisa->iconw - thisa->menuw;
      v207 = thisa->iconh / 2 + thisa->menuh + 12 * thisa->iconh - thisa->fontmh - 1;
      v208 = 5 * thisa->iconw;
      v209 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + 17);
      Window::drawtextxy_(thisa, thisa->pwint, v209, v208, v207, v206, v205, v204, v203, 0);
      v210 = thisa->cfg;
      v211 = thisa->ctfg;
      v212 = thisa->fontmh;
      v213 = 15 * thisa->iconw - thisa->menuw;
      v214 = 16 * thisa->iconh + thisa->menuh + thisa->iconh / 2 - thisa->fontmh - 1;
      v215 = 5 * thisa->iconw;
      v216 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + 18);
      Window::drawtextxy_(thisa, thisa->pwint, v216, v215, v214, v213, v212, v211, v210, 0);
      v217 = thisa->cfg;
      v218 = thisa->ctfg;
      v219 = thisa->fontmh;
      v220 = 15 * thisa->iconw - thisa->menuw;
      v221 = thisa->iconh / 2 + thisa->menuh + 24 * thisa->iconh - thisa->fontmh - 1;
      v222 = 5 * thisa->iconw;
      v223 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_HELP_MENU + 19);
      Window::drawtextxy_(thisa, thisa->pwint, v223, v222, v221, v220, v219, v218, v217, 0);
      Window::setfontheight_(thisa, thisa->fonth);
      break;
    default:
      break;
  }
  if ( thisa->helpi == -1 )
  {
    Window::setfontheight_(thisa, thisa->fonth);
    v224 = thisa->okh;
    v225 = thisa->okw;
    v226 = (thisa->okh_ + thisa->okh) / -2 + thisa->abouth + thisa->menuh;
    v227 = (thisa->aboutw - thisa->okw) / 2;
    v228 = GetWin();
    DrawBMP(thisa->pok, v228, v227, v226, v225, v224);
    v229 = thisa->ctbg;
    v230 = thisa->ctfg;
    v231 = thisa->okh;
    v232 = thisa->okw;
    v233 = thisa->abouth + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh;
    v234 = (thisa->aboutw - thisa->okw) / 2;
    v235 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_ABOUT_OK);
    Window::drawtextxy_(thisa, thisa->pwint, v235, v234, v233, v232, v231, v230, v229);
  }
  else if ( thisa->helpi )
  {
    Window::setfontheight_(thisa, thisa->fonth);
    v236 = thisa->okh;
    v237 = thisa->okw;
    v238 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
    v239 = (thisa->helpw - thisa->okw) / 2;
    v240 = GetWin();
    DrawBMP(thisa->pok, v240, v239, v238, v237, v236);
    v241 = thisa->ctbg;
    v242 = thisa->ctfg;
    v243 = thisa->okh;
    v244 = thisa->okw;
    v245 = thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh;
    v246 = (thisa->helpw - thisa->okw) / 2;
    v247 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_ABOUT_OK);
    Window::drawtextxy_(thisa, thisa->pwint, v247, v246, v245, v244, v243, v242, v241);
    if ( thisa->helpi > 1 && thisa->helpi <= thisa->maxhelp )
    {
      v248 = thisa->btnh;
      v249 = thisa->btnw;
      v250 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
      v251 = (thisa->helpw - thisa->okw) / 2 - 2 * thisa->btnw;
      v252 = GetWin();
      DrawBMP(thisa->pbtn, v252, v251, v250, v249, v248);
      Window::drawtextxy_(
        thisa,
        thisa->pwint,
        "<",
        (thisa->helpw - thisa->okw) / 2 - 2 * thisa->btnw,
        thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh,
        thisa->btnw,
        thisa->btnh,
        thisa->ctfg,
        thisa->ctbg);
    }
    if ( thisa->helpi > 0 && thisa->helpi < thisa->maxhelp )
    {
      v253 = thisa->btnh;
      v254 = thisa->btnw;
      v255 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
      v256 = (thisa->helpw + thisa->okw) / 2 + thisa->btnw;
      v257 = GetWin();
      DrawBMP(thisa->pbtn, v257, v256, v255, v254, v253);
      Window::drawtextxy_(
        thisa,
        thisa->pwint,
        (const char *)&stru_4292A8,
        (thisa->helpw + thisa->okw) / 2 + thisa->btnw,
        thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh,
        thisa->btnw,
        thisa->btnh,
        thisa->ctfg,
        thisa->ctbg);
    }
    v258 = thisa->tuth;
    v259 = thisa->tutw;
    v260 = (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh;
    v261 = -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw;
    v262 = GetWin();
    DrawBMP(thisa->pok, v262, v261, v260, v259, v258);
    v263 = thisa->ctbg;
    v264 = thisa->ctfg;
    v265 = thisa->tuth;
    v266 = thisa->tutw;
    v267 = thisa->helph + (thisa->okh_ + thisa->okh) / -2 + thisa->menuh;
    v268 = (thisa->helpw - thisa->okw) / 2 - 3 * thisa->btnw - thisa->tutw;
    v269 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_TUT_);
    Window::drawtextxy_(thisa, thisa->pwint, v269, v268, v267, v266, v265, v264, v263);
    Line(0, thisa->menuh, thisa->helpw, 0, thisa->cline);
    Line(0, thisa->helph + thisa->menuh - thisa->okh_, thisa->helpw, 0, thisa->cline);
  }
}


// Address: 0x0041D9A2; symbol: __ZN6Window8painttutEv
void __thiscall Window::painttut(Window *const this)
{
  int i; // ST4C_4
  int j; // ST48_4
  unsigned int cbg; // ST38_4
  unsigned int v4; // edi
  unsigned int v5; // esi
  int v6; // ebx
  bitmap *v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ST38_4
  unsigned int w; // ST34_4
  int y; // ST30_4
  int v12; // ebx
  int v13; // esi
  __int16 *v14; // eax
  unsigned int v15; // ST38_4
  unsigned int v16; // edi
  unsigned int v17; // esi
  int v18; // ebx
  bitmap *v19; // eax
  unsigned int v20; // edi
  unsigned int v21; // ST38_4
  unsigned int v22; // ST34_4
  int v23; // ST30_4
  int v24; // ebx
  int v25; // esi
  __int16 *v26; // eax
  unsigned int v27; // esi
  unsigned int v28; // ST38_4
  int v29; // ST34_4
  unsigned int v30; // edi
  int v31; // ebx
  __int16 *v32; // eax
  unsigned int v33; // esi
  unsigned int v34; // ST38_4
  int v35; // ST34_4
  unsigned int v36; // edi
  int v37; // ebx
  __int16 *v38; // eax
  unsigned int v39; // edi
  unsigned int v40; // esi
  unsigned int v41; // ebx
  bitmap *v42; // eax
  unsigned int v43; // ST38_4
  unsigned int v44; // edi
  unsigned int v45; // esi
  unsigned int v46; // ebx
  bitmap *v47; // eax
  unsigned int v48; // esi
  unsigned int v49; // ST38_4
  unsigned int v50; // ST34_4
  unsigned int v51; // edi
  int v52; // ebx
  __int16 *v53; // eax
  unsigned int v54; // edi
  unsigned int v55; // ST38_4
  unsigned int v56; // ST34_4
  int v57; // ST30_4
  int v58; // ebx
  int v59; // esi
  __int16 *v60; // eax
  Window *thisa; // [esp+3Ch] [ebp-2Ch]

  thisa = this;
  Window::setfontheight_(this, this->fonth);
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
        v4 = thisa->okw;
        v5 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v6 = (12 * thisa->iconw - thisa->okw) / 2;
        v7 = GetWin();
        DrawBMP(thisa->pok, v7, v6, v5, v4, cbg);
        v8 = thisa->ctbg;
        v9 = thisa->ctfg;
        w = thisa->okh;
        y = thisa->okw;
        v12 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v13 = (12 * thisa->iconw - thisa->okw) / 2;
        v14 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_ABOUT_OK);
        Window::drawtextxy_(thisa, thisa->pwint, v14, v13, v12, y, w, v9, v8);
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
        v15 = thisa->okh;
        v16 = thisa->okw;
        v17 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v18 = (12 * thisa->iconw - thisa->okw) / 2;
        v19 = GetWin();
        DrawBMP(thisa->pok, v19, v18, v17, v16, v15);
        v20 = thisa->ctbg;
        v21 = thisa->ctfg;
        v22 = thisa->okh;
        v23 = thisa->okw;
        v24 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
        v25 = (12 * thisa->iconw - thisa->okw) / 2;
        v26 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_ABOUT_OK);
        Window::drawtextxy_(thisa, thisa->pwint, v26, v25, v24, v23, v22, v21, v20);
      }
      break;
    default:
      break;
  }
  Window::setfontheight_(thisa, thisa->fontsh);
  v27 = thisa->cbg;
  v28 = thisa->ctfg;
  v29 = 8 * thisa->fontsh;
  v30 = 12 * thisa->iconw;
  v31 = thisa->menuh + thisa->faceh;
  v32 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.tuti + thisa->bd.st.lan.LAN_TUT);
  Window::drawtextxy_(thisa, thisa->pwint, v32, 0, v31, v30, v29, v28, v27, 0x10u);
  Window::setfontheight_(thisa, thisa->fonth);
  if ( thisa->bd.tutb == 2 )
  {
    v33 = thisa->cbg;
    v34 = thisa->ctfg;
    v35 = 8 * thisa->fontsh;
    v36 = 12 * thisa->iconw;
    v37 = thisa->menuh + thisa->faceh;
    v38 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_TUT_QUIT);
    Window::drawtextxy_(thisa, thisa->pwint, v38, 0, v37, v36, v35, v34, v33);
    v39 = thisa->okh;
    v40 = 6 * thisa->iconw - 1;
    v41 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v42 = GetWin();
    DrawBMP(thisa->pok, v42, 0, v41, v40, v39);
    v43 = thisa->okh;
    v44 = 6 * thisa->iconw - 1;
    v45 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v46 = 6 * thisa->iconw;
    v47 = GetWin();
    DrawBMP(thisa->pok, v47, v46, v45, v44, v43);
    v48 = thisa->ctbg;
    v49 = thisa->ctfg;
    v50 = thisa->okh;
    v51 = 6 * thisa->iconw - 1;
    v52 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v53 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_TUT_QUIT + 1);
    Window::drawtextxy_(thisa, thisa->pwint, v53, 0, v52, v51, v50, v49, v48);
    v54 = thisa->ctbg;
    v55 = thisa->ctfg;
    v56 = thisa->okh;
    v57 = 6 * thisa->iconw - 1;
    v58 = thisa->menuh + 10 * thisa->iconh + thisa->faceh;
    v59 = 6 * thisa->iconw;
    v60 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_TUT_QUIT + 2);
    Window::drawtextxy_(thisa, thisa->pwint, v60, v59, v58, v57, v56, v55, v54);
  }
}


// Address: 0x0041F3A8; symbol: __ZN6Window10painttitleEl
void __thiscall Window::painttitle(Window *const this, int load)
{
  unsigned int c; // ST3C_4
  unsigned int hd; // ST38_4
  unsigned int v4; // edi
  unsigned int v5; // esi
  int v6; // ebx
  bitmap *v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // ST3C_4
  unsigned int v10; // ST38_4
  unsigned int v11; // edi
  int v12; // ebx
  __int16 *v13; // eax
  unsigned int v14; // esi
  unsigned int v15; // ST3C_4
  unsigned int v16; // ST38_4
  unsigned int v17; // edi
  int v18; // ebx
  __int16 *v19; // eax
  unsigned int v20; // ST3C_4
  unsigned int v21; // ST38_4
  unsigned int v22; // edi
  unsigned int v23; // esi
  bitmap *v24; // ebx
  bitmap *v25; // eax
  unsigned int v26; // esi
  unsigned int v27; // ebx
  bitmap *v28; // eax
  unsigned int v29; // edi
  unsigned int v30; // esi
  unsigned int v31; // ebx
  bitmap *v32; // eax
  Window *thisa; // [esp+4Ch] [ebp-1Ch]

  thisa = this;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->cs);
  painttitlec = (Window *)load;
  Clear(thisa->cbg);
  Clear(thisa->pwint, thisa->transparent_);
  if ( load < 0 )
    thisa->ptitle_ = LoadBMP("./data/png/title.png");
  c = thisa->cfg;
  hd = thisa->titleh;
  v4 = thisa->titlew;
  v5 = thisa->fontth;
  v6 = (thisa->launchw - thisa->titlew) / 2;
  v7 = GetWin();
  DrawBMP(thisa->ptitle_, v7, v6, v5, v4, hd, c);
  Window::setfontheight_(thisa, thisa->fontfh);
  v8 = thisa->cbg;
  v9 = thisa->ctfg;
  v10 = thisa->fontfh;
  v11 = thisa->launchw;
  v12 = thisa->fontth - thisa->fontfh;
  v13 = Lan::getlan(&thisa->bd.st.lan, thisa->bd.st.lan.LAN_TITLE);
  Window::drawtextxy_(thisa, thisa->pwint, v13, 0, v12, v11, v10, v9, v8);
  if ( load >= 0 )
  {
    Window::setfontheight_(thisa, thisa->fontfh);
    v14 = thisa->cbg;
    v15 = thisa->ctfg;
    v16 = thisa->fontfh;
    v17 = thisa->launchw;
    v18 = thisa->titleh + thisa->fontth + thisa->fontfh / -2;
    v19 = Lan::getlan(&thisa->bd.st.lan, load);
    Window::drawtextxy_(thisa, thisa->pwint, v19, 0, v18, v17, v16, v15, v14);
    Window::setfontheight_(thisa, thisa->fonth);
    if ( painttitles )
      Window::drawtextxy_(
        thisa,
        thisa->pwint,
        (const char *)painttitles,
        0,
        thisa->titleh + thisa->fontth + thisa->fontfh / 2,
        thisa->launchw,
        thisa->fontfh,
        thisa->ctfg,
        thisa->cbg);
  }
  Window::setfontheight_(thisa, thisa->fonth);
  if ( thisa->mult > 1.0 )
  {
    v20 = thisa->h_;
    v21 = thisa->w_;
    v22 = thisa->h_;
    v23 = thisa->w_;
    v24 = thisa->pwin;
    v25 = GetWin();
    DrawBMP(v25, v24, 0, 0, v23, v22, 0, 0, v21, v20);
    v26 = (signed __int64)((long double)thisa->h_ * thisa->mult);
    v27 = (signed __int64)((long double)thisa->w_ * thisa->mult);
    v28 = GetWin();
    DrawBMP(thisa->pwin, v28, 0, 0, v27, v26);
  }
  v29 = thisa->transparent_;
  v30 = (signed __int64)((long double)thisa->h_ * thisa->mult);
  v31 = (signed __int64)((long double)thisa->w_ * thisa->mult);
  v32 = GetWin();
  DrawBMP(thisa->pwint, v32, 0, 0, v31, v30, v29);
  FreshWin();
  LeaveCriticalSection((LPCRITICAL_SECTION)&thisa->cs);
}


// Address: 0x0041F8C4; symbol: __ZN6Window10painteventEb
void __thiscall Window::paintevent(Window *const this, bool freshb)
{
  unsigned int hd; // ST34_4
  unsigned int wd; // ST30_4
  unsigned int v4; // edi
  unsigned int v5; // esi
  bitmap *v6; // ebx
  bitmap *v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // ebx
  bitmap *v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // esi
  unsigned int v13; // ebx
  bitmap *v14; // eax
  Window *thisa; // [esp+4Ch] [ebp-1Ch]

  thisa = this;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->cs);
  Clear(thisa->cbg);
  Clear(thisa->pwint, thisa->transparent_);
  Window::paintmenu(thisa);
  if ( thisa->helpi )
  {
    Window::painthelp(thisa);
  }
  else
  {
    Window::paintface(thisa);
    Window::paintlevel(thisa);
    Window::paintboard(thisa);
    if ( thisa->bd.tutb > 0 && !thisa->bd.pauseb )
      Window::painttut(thisa);
  }
  if ( thisa->mult > 1.0 )
  {
    hd = thisa->h_;
    wd = thisa->w_;
    v4 = thisa->h_;
    v5 = thisa->w_;
    v6 = thisa->pwin;
    v7 = GetWin();
    DrawBMP(v7, v6, 0, 0, v5, v4, 0, 0, wd, hd);
    v8 = (signed __int64)((long double)thisa->h_ * thisa->mult);
    v9 = (signed __int64)((long double)thisa->w_ * thisa->mult);
    v10 = GetWin();
    DrawBMP(thisa->pwin, v10, 0, 0, v9, v8);
  }
  v11 = thisa->transparent_;
  v12 = (signed __int64)((long double)thisa->h_ * thisa->mult);
  v13 = (signed __int64)((long double)thisa->w_ * thisa->mult);
  v14 = GetWin();
  DrawBMP(thisa->pwint, v14, 0, 0, v13, v12, v11);
  if ( freshb )
    FreshWin();
  LeaveCriticalSection((LPCRITICAL_SECTION)&thisa->cs);
}


// Address: 0x0041FB7C; symbol: __ZN6Window10painteventEv
void __thiscall Window::paintevent(Window *const this)
{
  Window::paintevent(this, 1);
}


// Address: 0x0041FB9C; symbol: __ZN6Window12paintrefreshEv
void __thiscall Window::paintrefresh(Window *const this)
{
  HWND__ *v1; // eax
  HWND__ *v2; // eax
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  if ( GetTimeR() > this->timerefresh + 0.1 )
  {
    v1 = GetHwnd();
    InvalidateRect(v1, 0, 0);
    v2 = GetHwnd();
    UpdateWindow(v2);
    thisa->timerefresh = GetTimeR();
  }
}


// Address: 0x0041FC0A; symbol: __ZN6Window4isinEllllll
bool __thiscall Window::isin(Window *const this, int ex, int ey, int x, int y, int w, int h)
{
  return ex > x && ey > y && x + w > ex && y + h > ey;
}


// Address: 0x0041FC4E; symbol: __ZN6Window7sethelpEl
void __thiscall Window::sethelp(Window *const this, int helpi_)
{
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  this->mi = 0;
  if ( this->helpi != helpi_ || this->helpi )
    Sound::playsound(&this->bd.sd, this->bd.sd.sLeft);
  if ( thisa->helpi > 0 && helpi_ > 0 )
    helpi_ = thisa->helpi;
  if ( thisa->helpi != helpi_ && helpi_ )
  {
    if ( !thisa->helpi && thisa->bd.sit > 0 && !thisa->bd.pauseb && thisa->bd.sit <= 3 )
    {
      Board::pause(&thisa->bd);
      thisa->bd.pauseb = 2;
    }
    thisa->helpi = helpi_;
  }
  else
  {
    if ( thisa->bd.pauseb == 2 && thisa->bd.sit > 0 && thisa->bd.sit <= 3 )
      Board::pause(&thisa->bd);
    thisa->helpi = 0;
  }
  Window::initwindow(thisa, 0);
  if ( thisa->helpi == -2 && thisa->waitb != 1 )
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)getlead, thisa, 0, 0);
}


// Address: 0x0041FDE0; symbol: __ZN6Window7savescrEv
void __thiscall Window::savescr(Window *const this)
{
  Window *v1; // ST2C_4
  char *v2; // eax
  char *v3; // eax
  bitmap *v4; // eax
  char times[260]; // [esp+30h] [ebp-228h]
  time_t rawtime; // [esp+134h] [ebp-124h]
  char scrpath[260]; // [esp+138h] [ebp-120h]
  tm *timed; // [esp+23Ch] [ebp-1Ch]

  v1 = this;
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
  Steam::savescr(&v1->bd.st, scrpath);
  Sound::playsound(&v1->bd.sd, v1->bd.sd.sSolve);
}


// Address: 0x0041FF6A; symbol: __ZN6Window10switchskinEv
void __thiscall Window::switchskin(Window *const this)
{
  Window::switchskin(this, (this->colori + 1) % 6);
}


// Address: 0x0041FFAE; symbol: __ZN6Window10switchskinEl
void __thiscall Window::switchskin(Window *const this, int colori_)
{
  Window *v2; // ST1C_4

  v2 = this;
  this->colori = colori_;
  Window::initbmp(this);
  Window::paintevent(v2);
  Sound::playsound(&v2->bd.sd, v2->bd.sd.sRight);
}


// Address: 0x0041FFFC; symbol: __ZN6Window8switchmdEv
void __thiscall Window::switchmd(Window *const this)
{
  unsigned int v1; // eax

  v1 = (unsigned int)((this->md + 1) >> 31) >> 30;
  Window::switchmd(this, (((_BYTE)v1 + LOBYTE(this->md) + 1) & 3) - v1);
}


// Address: 0x00420038; symbol: __ZN6Window8switchmdEl
void __thiscall Window::switchmd(Window *const this, int md_)
{
  this->md = md_;
  if ( this->md > 1 )
    this->bd.mdb = 0;
  Sound::playsound(&this->bd.sd, this->bd.sd.sLeft);
}


// Address: 0x0042008C; symbol: __ZN6Window8tuteventEllb
void __thiscall Window::tutevent(Window *const this, int ex, int ey, bool tutkb)
{
  Window *thisa; // [esp+2Ch] [ebp-1Ch]
  bool tutmb_n; // [esp+3Dh] [ebp-Bh]
  bool tutmb_y; // [esp+3Eh] [ebp-Ah]
  bool tutmb; // [esp+3Fh] [ebp-9h]

  thisa = this;
  tutmb = Window::isin(
            thisa,
            ex,
            ey,
            (12 * thisa->iconw - thisa->okw) / 2,
            thisa->menuh + 10 * thisa->iconh + thisa->faceh,
            this->okw,
            this->okh);
  if ( thisa->bd.tutb == 1 && (tutmb || tutkb) )
  {
    if ( thisa->bd.tuti == 13 )
    {
      ++thisa->bd.maski;
      ++thisa->bd.tuti;
      Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
    }
    else if ( thisa->bd.tuti == 14 )
    {
      thisa->bd.tutb = 0;
      thisa->bd.time = GetTimeR();
      thisa->helpb = 0;
      Window::sethelp(thisa, 1);
    }
  }
  tutmb_y = Window::isin(
              thisa,
              ex,
              ey,
              0,
              thisa->faceh + thisa->menuh + 10 * thisa->iconh,
              6 * thisa->iconw - 1,
              thisa->okh);
  tutmb_n = Window::isin(
              thisa,
              ex,
              ey,
              6 * thisa->iconw,
              thisa->menuh + 10 * thisa->iconh + thisa->faceh,
              6 * thisa->iconw - 1,
              thisa->okh);
  if ( thisa->bd.tutb == 2 && (tutmb_y || tutmb_n || tutkb) )
  {
    if ( tutmb_y || tutkb )
    {
      thisa->bd.tutb = 0;
      thisa->bd.time = GetTimeR();
      thisa->helpb = 0;
      Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
    }
    if ( tutmb_n )
    {
      thisa->bd.tutb = 1;
      Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
    }
  }
}


// Address: 0x00420374; symbol: __ZN6Window16mouseeventboard_Ellll
void __thiscall Window::mouseeventboard_(Window *const this, int x, int y, int eb_, int md_)
{
  bool v5; // al
  Window *thisa; // [esp+1Ch] [ebp-1Ch]

  thisa = this;
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
        Board::resetbd(&this->bd, x, y);
      Board::clickleft(&thisa->bd, x, y, 1, md_);
    }
    else if ( eb_ == 2 )
    {
      Board::clickright(&this->bd, x, y, 1, md_);
    }
    Window::paintevent(thisa);
    Board::checkline(&thisa->bd, 1);
    thisa->mx = x;
    thisa->my = y;
    if ( thisa->bd.tutb > 0 )
      ++thisa->bd.tuti;
    Window::paintevent(thisa);
  }
}


// Address: 0x00420566; symbol: __ZN6Window15mouseeventboardEllll
void __thiscall Window::mouseeventboard(Window *const this, int ex_, int ey_, int eb_, int md_)
{
  Window *thisa; // [esp+1Ch] [ebp-1Ch]
  int y; // [esp+20h] [ebp-18h]
  int x; // [esp+24h] [ebp-14h]
  signed int ey; // [esp+28h] [ebp-10h]
  signed int ex; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  ex = (signed int)((long double)ex_ / this->mult);
  ey = (signed int)((long double)ey_ / this->mult);
  if ( ex >= 0 && ey - this->menuh >= this->faceh && !this->helpi && this->bd.sit <= 3 && !this->bd.pauseb )
  {
    x = ex / this->iconw;
    y = (ey - this->faceh - this->menuh) / this->iconh;
    if ( x >= 0 && this->bd.w > x && y >= 0 && this->bd.h > y )
      Window::mouseeventboard_(this, x, y, eb_, md_);
    Window::tutevent(thisa, ex, ey, 0);
  }
}


// Address: 0x004206AE; symbol: __ZN6Window10mouseeventElll
void __thiscall Window::mouseevent(Window *const this, int ex_, int ey_, int eb_)
{
  int v4; // eax
  int v5; // eax
  Window *thisa; // [esp+2Ch] [ebp-3Ch]
  double helph__; // [esp+38h] [ebp-30h]
  int ey; // [esp+40h] [ebp-28h]
  int ex; // [esp+44h] [ebp-24h]
  signed int j; // [esp+48h] [ebp-20h]
  int k; // [esp+4Ch] [ebp-1Ch]

  thisa = this;
  ex = (signed int)((long double)ex_ / this->mult);
  ey = (signed int)((long double)ey_ / this->mult);
  if ( this->menuh <= ey )
  {
    if ( this->helpi )
    {
      if ( this->helpi == -1 )
      {
        if ( Window::isin(
               this,
               ex,
               ey,
               (this->aboutw - this->okw) / 2,
               this->menuh + (this->okh_ + this->okh) / -2 + this->abouth,
               this->okw,
               this->okh) )
        {
          Window::sethelp(thisa, 0);
        }
        if ( Window::isin(
               thisa,
               ex,
               ey,
               (thisa->aboutw - thisa->fontfh) / 2 + thisa->fontfh / -2,
               (thisa->fontth - thisa->fontfh) / 2 + thisa->menuh,
               thisa->fontfh,
               thisa->fontfh)
          && thisa->cheatb != 1 )
        {
          Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sSolve);
          thisa->cheatb = 1;
          thisa->bd.st.cheatb = 1;
          Steam::addach(&thisa->bd.st, thisa->bd.st.achhidcheat);
        }
        if ( Window::isin(
               thisa,
               ex,
               ey,
               (thisa->aboutw - thisa->fontfh) / 2 + thisa->fontfh / 2,
               (thisa->fontth - thisa->fontfh) / 2 + thisa->menuh,
               thisa->fontfh,
               thisa->fontfh)
          && thisa->bd.relaxb != 1 )
        {
          Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sSolve);
          thisa->bd.relaxb = 1;
          thisa->bd.st.cheatb = 1;
          Steam::addach(&thisa->bd.st, thisa->bd.st.achhidcheat);
        }
      }
      else if ( this->helpi )
      {
        if ( Window::isin(
               this,
               ex,
               ey,
               (this->helpw - this->okw) / 2,
               this->menuh + (this->okh_ + this->okh) / -2 + this->helph,
               this->okw,
               this->okh) )
        {
          Window::sethelp(thisa, 0);
        }
        if ( Window::isin(
               thisa,
               ex,
               ey,
               -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw,
               (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
               thisa->tutw,
               thisa->tuth) )
        {
          Window::sethelp(thisa, 0);
          Board::initbd(&thisa->bd, 1, thisa->md);
          Window::initwindow(thisa, 0);
          thisa->bd.tutb = 1;
        }
        if ( thisa->helpi > 1
          && Window::isin(
               thisa,
               ex,
               ey,
               (thisa->helpw - thisa->okw) / 2 - 2 * thisa->btnw,
               (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
               thisa->btnw,
               thisa->btnh) )
        {
          --thisa->helpi;
          Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
        }
        if ( thisa->helpi > 0
          && thisa->helpi < thisa->maxhelp
          && Window::isin(
               thisa,
               ex,
               ey,
               thisa->btnw + (thisa->helpw + thisa->okw) / 2,
               (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
               thisa->btnw,
               thisa->btnh) )
        {
          ++thisa->helpi;
          Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
          if ( thisa->helpi == thisa->maxhelp )
            Steam::addach(&thisa->bd.st, thisa->bd.st.achgenhelp);
        }
        if ( thisa->helpi == -2 )
        {
          if ( Window::isin(
                 thisa,
                 ex,
                 ey,
                 ((thisa->helpw + thisa->okw) / 2 + thisa->helpw) / 2
               + ((signed int)(((unsigned int)(-5 * thisa->facew) >> 31) - 5 * thisa->facew) >> 1),
                 (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                 5 * thisa->facew,
                 thisa->faceh) )
          {
            thisa->lead_5 = (ex
                           - (((thisa->helpw + thisa->okw) / 2 + thisa->helpw) / 2
                            + ((signed int)(((unsigned int)(-5 * thisa->facew) >> 31) - 5 * thisa->facew) >> 1)))
                          / thisa->facew;
            Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
          }
          if ( Window::isin(
                 thisa,
                 ex,
                 ey,
                 -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw,
                 (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                 thisa->tutw,
                 thisa->tuth) )
          {
            Window::sethelp(thisa, 0);
            Board::initbd(&thisa->bd, 1, thisa->md);
            Window::initwindow(thisa, 0);
            thisa->bd.tutb = 1;
          }
        }
        if ( thisa->helpi == -3 )
        {
          if ( Window::isin(
                 thisa,
                 ex,
                 ey,
                 -3 * thisa->btnw + (thisa->helpw - thisa->okw) / 2 - thisa->tutw,
                 (thisa->okh_ + thisa->okh) / -2 + thisa->helph + thisa->menuh,
                 thisa->tutw,
                 thisa->tuth) )
          {
            Window::sethelp(thisa, 0);
            Board::initbd(&thisa->bd, 1, thisa->md);
            Window::initwindow(thisa, 0);
            thisa->bd.tutb = 1;
          }
          helph__ = (long double)(thisa->helph - thisa->okh_ - 2 * thisa->iconh - thisa->faceh) / 9.0;
          for ( k = 0; k <= 9; ++k )
          {
            if ( Window::isin(
                   thisa,
                   ex,
                   ey,
                   thisa->iconw,
                   (signed int)((long double)k * helph__
                              + (long double)(signed int)thisa->menuh
                              + (long double)(signed int)thisa->iconh),
                   thisa->facew,
                   thisa->faceh) )
            {
              switch ( k )
              {
                case 0:
                  Sound::switchsound(&thisa->bd.sd);
                  break;
                case 1:
                  Sound::switchmusic(&thisa->bd.sd);
                  break;
                case 2:
                  Window::switchmd(thisa);
                  break;
                case 4:
                  if ( thisa->mult_ )
                    thisa->mult_ = 0;
                  else
                    thisa->mult_ = 1;
                  Window::initwindow(thisa, 0);
                  Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sRight);
                  break;
                case 5:
                  Window::switchskin(thisa);
                  break;
                case 7:
                  thisa->bd.delayb = thisa->bd.delayb == 0;
                  Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
                  break;
                case 8:
                  thisa->barb ^= 1u;
                  Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
                  break;
                case 9:
                  thisa->singleb ^= 1u;
                  Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
                  break;
                default:
                  break;
              }
            }
            for ( j = 0; j <= 2; ++j )
            {
              if ( Window::isin(
                     thisa,
                     ex,
                     ey,
                     (j + 1) * (thisa->helpw / 4),
                     (signed int)((long double)k * helph__
                                + (long double)(signed int)thisa->menuh
                                + (long double)(signed int)thisa->iconh),
                     thisa->facew,
                     thisa->faceh) )
              {
                switch ( k )
                {
                  case 0:
                    if ( j <= 1 && thisa->bd.sd.soundb == j )
                      Sound::switchsound(&thisa->bd.sd);
                    break;
                  case 1:
                    if ( j <= 1 && thisa->bd.sd.musicb == j )
                      Sound::switchmusic(&thisa->bd.sd);
                    break;
                  case 2:
                    if ( j <= 2 && thisa->md != j )
                      Window::switchmd(thisa, j);
                    break;
                  case 3:
                    if ( j <= 2 && thisa->md != j + 2 )
                      Window::switchmd(thisa, j + 2);
                    break;
                  case 4:
                    if ( thisa->mult_ != j )
                    {
                      thisa->mult_ = j;
                      Window::initwindow(thisa, 0);
                      Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sRight);
                    }
                    break;
                  case 5:
                    if ( j <= 2 && thisa->colori != j )
                      Window::switchskin(thisa, j);
                    break;
                  case 6:
                    if ( j <= 2 && thisa->colori != j + 3 )
                      Window::switchskin(thisa, j + 3);
                    break;
                  case 7:
                    if ( j <= 1 && thisa->bd.delayb == j )
                    {
                      thisa->bd.delayb = thisa->bd.delayb == 0;
                      Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
                    }
                    break;
                  case 8:
                    if ( j <= 1 && thisa->barb == j )
                    {
                      thisa->barb ^= 1u;
                      Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
                    }
                    break;
                  case 9:
                    if ( j <= 1 && thisa->singleb != j )
                    {
                      thisa->singleb ^= 1u;
                      Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
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
            if ( Window::isin(
                   thisa,
                   ex,
                   ey,
                   thisa->facew + 3 * (thisa->helpw / 4),
                   (signed int)(helph__ * 4.0
                              + (long double)(signed int)thisa->menuh
                              + (long double)(signed int)thisa->iconh),
                   thisa->facew,
                   thisa->faceh) )
            {
              v4 = thisa->mult_ - 1;
              if ( v4 < 2 )
                v4 = 2;
              thisa->mult_ = v4;
              Window::initwindow(thisa, 0);
              Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sRight);
            }
            if ( Window::isin(
                   thisa,
                   ex,
                   ey,
                   2 * thisa->facew + 3 * (thisa->helpw / 4),
                   (signed int)(helph__ * 4.0
                              + (long double)(signed int)thisa->menuh
                              + (long double)(signed int)thisa->iconh),
                   thisa->facew,
                   thisa->faceh) )
            {
              v5 = thisa->mult_ + 1;
              if ( v5 > 8 )
                v5 = 8;
              thisa->mult_ = v5;
              Window::initwindow(thisa, 0);
              Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sRight);
            }
          }
        }
      }
    }
    else if ( ey - this->menuh >= this->faceh )
    {
      if ( this->bd.sit <= 3 && !this->bd.pauseb )
        Window::mouseeventboard(this, ex_, ey_, eb_, this->md + 4);
    }
    else if ( (this->w_ - this->facew) / 2 < ex && (this->w_ + this->facew) / 2 > ex )
    {
      if ( eb_ == 1 )
      {
        if ( this->bd.tutb <= 0 )
        {
          Board::initbd(&this->bd);
        }
        else
        {
          this->bd.tutb = 2;
          Sound::playsound(&this->bd.sd, this->bd.sd.sRight);
        }
      }
      else if ( eb_ == 2 && this->bd.sit > 0 && this->bd.sit <= 3 )
      {
        Board::pause(&this->bd);
        Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sSolve);
        Steam::addach(&thisa->bd.st, thisa->bd.st.achgenpause);
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
          Window::savescr(this);
          break;
        case 1:
          Window::sethelp(this, -2);
          break;
        case 2:
          Window::sethelp(this, -3);
          break;
        case 3:
          Window::sethelp(this, 1);
          break;
        case 4:
          Window::sethelp(this, -1);
          break;
        default:
          break;
      }
    }
  }
  else if ( this->bd.tutb <= 0 )
  {
    this->helpi = 0;
    Board::initbd(&this->bd, ex / this->menuw + 1, this->md);
    Window::initwindow(thisa, 0);
  }
  else
  {
    this->bd.tutb = 2;
    Sound::playsound(&this->bd.sd, this->bd.sd.sRight);
  }
  Window::paintevent(thisa);
}


// Address: 0x00421B48; symbol: __ZN6Window8keyeventEl
void __thiscall Window::keyevent(Window *const this, int key)
{
  int v2; // eax
  signed int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  Window *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = this;
  switch ( key )
  {
    case 49:
      if ( this->bd.tutb <= 0 )
      {
        this->helpi = 0;
        Board::initbd(&this->bd, 1, this->md);
        Window::initwindow(thisa, 0);
      }
      else
      {
        this->bd.tutb = 2;
        Sound::playsound(&this->bd.sd, this->bd.sd.sRight);
      }
      break;
    case 50:
      if ( this->bd.tutb <= 0 )
      {
        this->helpi = 0;
        Board::initbd(&this->bd, 2, this->md);
        Window::initwindow(thisa, 0);
      }
      else
      {
        this->bd.tutb = 2;
        Sound::playsound(&this->bd.sd, this->bd.sd.sRight);
      }
      break;
    case 51:
      if ( this->bd.tutb <= 0 )
      {
        this->helpi = 0;
        Board::initbd(&this->bd, 3, this->md);
        Window::initwindow(thisa, 0);
      }
      else
      {
        this->bd.tutb = 2;
        Sound::playsound(&this->bd.sd, this->bd.sd.sRight);
      }
      break;
    case 66:
      Window::sethelp(this, -1);
      break;
    case 69:
      Window::sethelp(this, -3);
      break;
    case 71:
      Window::switchmd(this);
      break;
    case 72:
      Window::sethelp(this, 1);
      break;
    case 75:
      Window::switchskin(this);
      break;
    case 77:
      Sound::switchmusic(&this->bd.sd);
      break;
    case 78:
      if ( this->bd.tutb <= 0 )
      {
        this->helpi = 0;
        Board::initbd(&this->bd);
        Window::initwindow(thisa, 0);
      }
      else
      {
        this->bd.tutb = 2;
        Sound::playsound(&this->bd.sd, this->bd.sd.sRight);
      }
      break;
    case 80:
      Window::savescr(this);
      break;
    case 82:
      this->singleb ^= 1u;
      Sound::playsound(&this->bd.sd, this->bd.sd.sLeft);
      break;
    case 83:
      Sound::switchsound(&this->bd.sd);
      break;
    case 84:
      Window::sethelp(this, -2);
      break;
    case 112:
      Window::sethelp(this, 1);
      break;
    case 113:
      Window::sethelp(this, -1);
      break;
    case 114:
      Window::sethelp(this, -3);
      break;
    case 115:
      Window::sethelp(this, -2);
      break;
    case 116:
      Sound::switchsound(&this->bd.sd);
      break;
    case 117:
      Sound::switchmusic(&this->bd.sd);
      break;
    case 118:
      Window::switchmd(this);
      break;
    case 119:
      this->singleb ^= 1u;
      Sound::playsound(&this->bd.sd, this->bd.sd.sLeft);
      break;
    case 122:
      Window::switchskin(this);
      break;
    case 123:
      Window::savescr(this);
      break;
    default:
      break;
  }
  if ( thisa->cheatb && key == 67 )
    Steam::resetach(&thisa->bd.st);
  if ( thisa->helpi == -2 && key == 9 )
  {
    thisa->lead_5 = (thisa->lead_5 + 1) % 5;
    Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
  }
  if ( thisa->helpi )
  {
    if ( key == 13 || key == 32 || key == 27 || key == 81 )
      Window::sethelp(thisa, 0);
    if ( thisa->helpi > 0 )
    {
      if ( key == 37 && thisa->helpi > 1 )
      {
        --thisa->helpi;
        Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
      }
      if ( key == 39 && thisa->helpi < thisa->maxhelp )
      {
        ++thisa->helpi;
        Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
        if ( thisa->helpi == thisa->maxhelp )
          Steam::addach(&thisa->bd.st, thisa->bd.st.achgenhelp);
      }
    }
  }
  else
  {
    if ( thisa->bd.mx == -1
      && thisa->bd.my == -1
      && (key == 65 || key == 68 || key == 87 || key == 83 || key == 188 || key == 190) )
    {
      thisa->bd.mx = thisa->bd.w / 2;
      thisa->bd.my = thisa->bd.h - 3;
    }
    switch ( key )
    {
      case 27:
        CloseWin();
        break;
      case 32:
        if ( thisa->bd.sit > 0 && thisa->bd.sit <= 3 )
        {
          Board::pause(&thisa->bd);
          Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sSolve);
          Steam::addach(&thisa->bd.st, thisa->bd.st.achgenpause);
        }
        break;
      case 33:
        v2 = thisa->bd.maskj0;
        if ( v2 > thisa->bd.h - 4 )
          v2 = thisa->bd.h - 4;
        thisa->bd.maskj0 = v2;
        v3 = --thisa->bd.maskj0;
        if ( v3 <= 0 )
          v3 = 1;
        thisa->bd.maskj0 = v3;
        Window::initwindow(thisa, 1);
        break;
      case 34:
        v4 = ++thisa->bd.maskj0;
        if ( v4 > thisa->bd.h - 4 )
          v4 = thisa->bd.h - 4;
        thisa->bd.maskj0 = v4;
        Window::initwindow(thisa, 1);
        break;
      case 37:
        --thisa->bd.w;
        Window::initwindow(thisa, 1);
        break;
      case 38:
        --thisa->bd.h;
        Window::initwindow(thisa, 1);
        break;
      case 39:
        ++thisa->bd.w;
        Window::initwindow(thisa, 1);
        break;
      case 40:
        ++thisa->bd.h;
        Window::initwindow(thisa, 1);
        break;
      case 65:
        --thisa->bd.mx;
        thisa->bd.mx &= ~(thisa->bd.mx >> 31);
        break;
      case 68:
        v5 = ++thisa->bd.mx;
        if ( v5 > thisa->bd.w - 1 )
          v5 = thisa->bd.w - 1;
        thisa->bd.mx = v5;
        break;
      case 81:
        CloseWin();
        break;
      case 83:
        v6 = ++thisa->bd.my;
        if ( v6 > thisa->bd.h - 1 )
          v6 = thisa->bd.h - 1;
        thisa->bd.my = v6;
        break;
      case 85:
        if ( !thisa->bd.tutb )
        {
          Board::addline(&thisa->bd);
          Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sLeft);
          Window::paintevent(thisa);
          Board::checkline(&thisa->bd, 1);
          Board::checkdie(&thisa->bd);
        }
        break;
      case 87:
        --thisa->bd.my;
        thisa->bd.my &= ~(thisa->bd.my >> 31);
        break;
      case 107:
        ++thisa->bd.n;
        Window::initwindow(thisa, 1);
        break;
      case 109:
        --thisa->bd.n;
        Window::initwindow(thisa, 1);
        break;
      case 187:
        ++thisa->bd.n;
        Window::initwindow(thisa, 1);
        break;
      case 188:
        thisa->mx = -1;
        thisa->my = -1;
        Window::tutevent(thisa, 0, 0, 1);
        Window::mouseeventboard_(thisa, thisa->bd.mx, thisa->bd.my, 1, thisa->md + 4);
        break;
      case 189:
        --thisa->bd.n;
        Window::initwindow(thisa, 1);
        break;
      case 190:
        thisa->mx = -1;
        thisa->my = -1;
        Window::tutevent(thisa, 0, 0, 1);
        Window::mouseeventboard_(thisa, thisa->bd.mx, thisa->bd.my, 2, thisa->md + 4);
        break;
      default:
        break;
    }
    if ( thisa->cheatb )
    {
      switch ( key )
      {
        case 48:
          Board::delline(&thisa->bd, thisa->bd.h - 1);
          break;
        case 52:
          Board::solve1(&thisa->bd);
          break;
        case 53:
          Board::solve2(&thisa->bd);
          break;
        case 54:
          Board::solve1_(&thisa->bd);
          break;
        case 55:
          Board::solve2_(&thisa->bd);
          break;
        case 56:
          Board::solve3_(&thisa->bd);
          break;
        case 57:
          Board::solveblank_(&thisa->bd);
          break;
        case 86:
          ++thisa->bd.level;
          break;
        default:
          break;
      }
      if ( key > 51 || key <= 48 )
      {
        Window::paintevent(thisa);
        Board::checkline(&thisa->bd, 1);
      }
    }
  }
  Window::paintevent(thisa);
}


// Address: 0x004227C6; symbol: __ZN6Window8doactionEv
void __thiscall Window::doaction(Window *const this)
{
  int v1; // ebx
  int v2; // eax
  int v3; // ebx
  int v4; // eax
  bool v5; // al
  int v6; // ebx
  int v7; // esi
  int v8; // eax
  int v9; // ebx
  int v10; // esi
  int v11; // eax
  int v12; // eax
  bool v13; // al
  HWND__ *v14; // eax
  HWND__ *v15; // eax
  bool v16; // al
  HWND__ *v17; // eax
  Window *thisa; // [esp+2Ch] [ebp-Ch]

  thisa = this;
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
        v1 = GetMousePosY();
        v2 = GetMousePosX();
        Window::mouseevent(thisa, v2, v1, 1);
      }
      if ( IsMouseRight() )
      {
        thisa->mi = 1;
        thisa->mx = -1;
        thisa->my = -1;
        v3 = GetMousePosY();
        v4 = GetMousePosX();
        Window::mouseevent(thisa, v4, v3, 2);
      }
      v5 = IsMouseMove() && thisa->md > 1 && !thisa->bd.tutb && thisa->mi;
      if ( v5 )
      {
        if ( thisa->ml )
        {
          v6 = thisa->md;
          v7 = GetMousePosY();
          v8 = GetMousePosX();
          Window::mouseeventboard(thisa, v8, v7, 1, v6);
        }
        if ( thisa->mr )
        {
          v9 = thisa->md;
          v10 = GetMousePosY();
          v11 = GetMousePosX();
          Window::mouseeventboard(thisa, v11, v10, 2, v9);
        }
      }
      if ( IsKey() )
      {
        v12 = GetKey();
        Window::keyevent(thisa, v12);
      }
      v13 = IsMsg(0xFu) || IsMsg(0xA1u) || IsMsg(0x112u);
      if ( v13 )
      {
        v14 = GetHwnd();
        thisa->showmax = IsZoomed(v14) != 0;
        v15 = GetHwnd();
        v16 = !IsIconic(v15)
           && (thisa->showmax != thisa->showmax_
            || (fabs((double)((long double)thisa->w_ * thisa->mult) - (double)GetWidth()) > 1.0
             || fabs((double)((long double)thisa->h_ * thisa->mult) - (double)GetHeight()) > 1.0)
            && IsMsg(0xA1u));
        if ( v16 )
        {
          v17 = GetHwnd();
          ShowWindow(v17, 9);
          thisa->mult_ = thisa->showmax;
          Window::initwindow(thisa, 0);
          Sound::playsound(&thisa->bd.sd, thisa->bd.sd.sRight);
          thisa->showmax = 0;
          thisa->showmax_ = thisa->showmax;
        }
        Window::paintevent(thisa);
      }
    }
  }
  thisa->bd.delayb__ = 0;
}


// Address: 0x00422BA8; symbol: __ZN6Window12setfontname_EPKc
void __thiscall Window::setfontname_(Window *const this, const char *s)
{
  Window *v2; // ST1C_4

  v2 = this;
  SetFontName(s);
  SetFont(v2->pwint);
}


// Address: 0x00422BD2; symbol: __ZN6Window14setfontheight_Em
void __thiscall Window::setfontheight_(Window *const this, unsigned int h)
{
  Window *v2; // ST2C_4

  v2 = this;
  SetFontHeight((signed __int64)((double)h * this->mult));
  SetFont(v2->pwint);
}


// Address: 0x00422C38; symbol: __ZN6Window14setfontweight_Em
void __thiscall Window::setfontweight_(Window *const this, unsigned int wg)
{
  Window *v2; // ST1C_4

  v2 = this;
  SetFontWeight(wg);
  SetFont(v2->pwint);
}


// Address: 0x00422C62; symbol: __ZN6Window11drawtextxy_EP6bitmapPKsllmmmmm
void __thiscall Window::drawtextxy_(Window *const this, pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int format)
{
  signed __int64 v10; // ST10_8

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


// Address: 0x00422D56; symbol: __ZN6Window11drawtextxy_EP6bitmapPKsllmmmm
void __thiscall Window::drawtextxy_(Window *const this, pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  signed __int64 v9; // ST10_8

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


// Address: 0x00422E42; symbol: __ZN6Window11drawtextxy_EP6bitmapPKcllmmmm
void __thiscall Window::drawtextxy_(Window *const this, pbitmap b, const char *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg)
{
  signed __int64 v9; // ST10_8

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


// Address: 0x00422F2E; symbol: __ZN6Window11drawtextxy_EP6bitmapPKcllmm
void __thiscall Window::drawtextxy_(Window *const this, pbitmap b, const char *s, int x, int y, unsigned int cfg, unsigned int cbg)
{
  DrawTextXY(b, s, (signed int)((long double)x * this->mult), (signed int)((long double)y * this->mult), cfg, cbg);
}


// Address: 0x00422FA6; symbol: __ZN6Window15getstringwidth_EPKc
unsigned int __thiscall Window::getstringwidth_(Window *const this, const char *s)
{
  return (signed __int64)((double)GetStringWidth(s) / this->mult);
}


// Address: 0x00422FF8; symbol: _WinMain@16
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  bool v4; // al
  __int16 *v5; // ebx
  __int16 *v6; // eax
  Lan lan_0; // [esp+10h] [ebp-F68h]
  Window w; // [esp+168h] [ebp-E10h]
  HANDLE hMutex; // [esp+F6Ch] [ebp-Ch]

  MainInstance = hInstance;
  hMutex = CreateMutexA(0, 1, "MineSweeperRushMutex");
  v4 = GetLastError() == 183 || FindWindowA("MineSweeperRushClass", 0);
  if ( v4 )
  {
    Lan::Lan((Lan *const )&w);
    v5 = Lan::getlan((Lan *const )&w, (int)w.pmenug[1][0]);
    v6 = Lan::getlan((Lan *const )&w, (int)w.pmenug[1][1]);
    MsgBoxW(v6, v5, 0x40u);
  }
  else
  {
    CheckAndProcessCabFile();
    Lan::Lan(&lan_0);
    Window::Window(&w);
    Window::loadall(&w);
    while ( (unsigned __int8)IsWin() )
    {
      Window::doaction(&w);
      if ( Board::addmask(&w.bd) )
      {
        Window::paintevent(&w);
        Window::paintrefresh(&w);
      }
      Sound::checkmusic(&w.bd.sd);
      Delay(1u);
    }
    ReleaseMutex(hMutex);
    Window::~Window(&w);
  }
  CloseHandle(hMutex);
  return 0;
}


// Address: 0x00423184; symbol: _timeEndPeriod@4
MMRESULT __stdcall timeEndPeriod(UINT uPeriod)
{
  return timeEndPeriod(uPeriod);
}


// Address: 0x0042318C; symbol: _timeBeginPeriod@4
MMRESULT __stdcall timeBeginPeriod(UINT uPeriod)
{
  return timeBeginPeriod(uPeriod);
}


// Address: 0x00423194; symbol: _mciSendStringA@16
MCIERROR __stdcall mciSendStringA(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback)
{
  return mciSendStringA(lpstrCommand, lpstrReturnString, uReturnLength, hwndCallback);
}


// Address: 0x0042319C; symbol: _GdiplusStartup@12
int __stdcall GdiplusStartup(int a1, int a2, int a3)
{
  return GdiplusStartup(a1, a2, a3);
}


// Address: 0x004231A4; symbol: _GdiplusShutdown@4
int __stdcall GdiplusShutdown(int a1)
{
  return GdiplusShutdown(a1);
}


// Address: 0x004231AC; symbol: _GdipSaveImageToFile@16
int __stdcall GdipSaveImageToFile(int a1, int a2, int a3, int a4)
{
  return GdipSaveImageToFile(a1, a2, a3, a4);
}


// Address: 0x004231B4; symbol: _GdipLoadImageFromFile@8
int __stdcall GdipLoadImageFromFile(int a1, int a2)
{
  return GdipLoadImageFromFile(a1, a2);
}


// Address: 0x004231BC; symbol: _GdipGetImageWidth@8
int __stdcall GdipGetImageWidth(int a1, int a2)
{
  return GdipGetImageWidth(a1, a2);
}


// Address: 0x004231C4; symbol: _GdipGetImageHeight@8
int __stdcall GdipGetImageHeight(int a1, int a2)
{
  return GdipGetImageHeight(a1, a2);
}


// Address: 0x004231CC; symbol: _GdipFree@4
int __stdcall GdipFree(int a1)
{
  return GdipFree(a1);
}


// Address: 0x004231D4; symbol: _GdipDrawImageRect@24
int __stdcall GdipDrawImageRect(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return GdipDrawImageRect(a1, a2, a3, a4, a5, a6);
}


// Address: 0x004231DC; symbol: _GdipDisposeImage@4
int __stdcall GdipDisposeImage(int a1)
{
  return GdipDisposeImage(a1);
}


// Address: 0x004231E4; symbol: _GdipDeletePrivateFontCollection@4
int __stdcall GdipDeletePrivateFontCollection(int a1)
{
  return GdipDeletePrivateFontCollection(a1);
}


// Address: 0x004231EC; symbol: _GdipDeleteGraphics@4
int __stdcall GdipDeleteGraphics(int a1)
{
  return GdipDeleteGraphics(a1);
}


// Address: 0x004231F4; symbol: _GdipDeleteCustomLineCap@4
int __stdcall GdipDeleteCustomLineCap(int a1)
{
  return GdipDeleteCustomLineCap(a1);
}


// Address: 0x004231FC; symbol: _GdipDeleteCachedBitmap@4
int __stdcall GdipDeleteCachedBitmap(int a1)
{
  return GdipDeleteCachedBitmap(a1);
}


// Address: 0x00423204; symbol: _GdipCreateFromHDC@8
int __stdcall GdipCreateFromHDC(int a1, int a2)
{
  return GdipCreateFromHDC(a1, a2);
}


// Address: 0x0042320C; symbol: _GdipCreateBitmapFromHBITMAP@12
int __stdcall GdipCreateBitmapFromHBITMAP(int a1, int a2, int a3)
{
  return GdipCreateBitmapFromHBITMAP(a1, a2, a3);
}


// Address: 0x00423214; symbol: _GdipCloneImage@8
int __stdcall GdipCloneImage(int a1, int a2)
{
  return GdipCloneImage(a1, a2);
}


// Address: 0x0042321C; symbol: _GdipAlloc@4
int __stdcall GdipAlloc(int a1)
{
  return GdipAlloc(a1);
}


// Address: 0x00423224; symbol: _TextOutA@20
BOOL __stdcall TextOutA(HDC a1, int a2, int a3, LPCSTR a4, int a5)
{
  return TextOutA(a1, a2, a3, a4, a5);
}


// Address: 0x0042322C; symbol: _StretchBlt@44
BOOL __stdcall StretchBlt(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, DWORD a11)
{
  return StretchBlt(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}


// Address: 0x00423234; symbol: _SetTextColor@8
COLORREF __stdcall SetTextColor(HDC a1, COLORREF a2)
{
  return SetTextColor(a1, a2);
}


// Address: 0x0042323C; symbol: _SetPixel@16
COLORREF __stdcall SetPixel(HDC a1, int a2, int a3, COLORREF a4)
{
  return SetPixel(a1, a2, a3, a4);
}


// Address: 0x00423244; symbol: _SetBkMode@8
int __stdcall SetBkMode(HDC a1, int a2)
{
  return SetBkMode(a1, a2);
}


// Address: 0x0042324C; symbol: _SetBkColor@8
COLORREF __stdcall SetBkColor(HDC a1, COLORREF a2)
{
  return SetBkColor(a1, a2);
}


// Address: 0x00423254; symbol: _SelectObject@8
HGDIOBJ __stdcall SelectObject(HDC a1, HGDIOBJ a2)
{
  return SelectObject(a1, a2);
}


// Address: 0x0042325C; symbol: _MoveToEx@16
BOOL __stdcall MoveToEx(HDC a1, int a2, int a3, LPPOINT a4)
{
  return MoveToEx(a1, a2, a3, a4);
}


// Address: 0x00423264; symbol: _LineTo@12
BOOL __stdcall LineTo(HDC a1, int a2, int a3)
{
  return LineTo(a1, a2, a3);
}


// Address: 0x0042326C; symbol: _GetTextMetricsA@8
BOOL __stdcall GetTextMetricsA(HDC a1, LPTEXTMETRICA a2)
{
  return GetTextMetricsA(a1, a2);
}


// Address: 0x00423274; symbol: _GetTextExtentPoint32A@16
BOOL __stdcall GetTextExtentPoint32A(HDC a1, LPCSTR a2, int a3, LPSIZE a4)
{
  return GetTextExtentPoint32A(a1, a2, a3, a4);
}


// Address: 0x0042327C; symbol: _GetStockObject@4
HGDIOBJ __stdcall GetStockObject(int a1)
{
  return GetStockObject(a1);
}


// Address: 0x00423284; symbol: _GetPixel@12
COLORREF __stdcall GetPixel(HDC a1, int a2, int a3)
{
  return GetPixel(a1, a2, a3);
}


// Address: 0x0042328C; symbol: _GetDeviceCaps@8
int __stdcall GetDeviceCaps(HDC a1, int a2)
{
  return GetDeviceCaps(a1, a2);
}


// Address: 0x00423294; symbol: _DeleteObject@4
BOOL __stdcall DeleteObject(HGDIOBJ a1)
{
  return DeleteObject(a1);
}


// Address: 0x0042329C; symbol: _DeleteDC@4
BOOL __stdcall DeleteDC(HDC a1)
{
  return DeleteDC(a1);
}


// Address: 0x004232A4; symbol: _CreateSolidBrush@4
HBRUSH __stdcall CreateSolidBrush(COLORREF a1)
{
  return CreateSolidBrush(a1);
}


// Address: 0x004232AC; symbol: _CreatePen@12
HPEN __stdcall CreatePen(int a1, int a2, COLORREF a3)
{
  return CreatePen(a1, a2, a3);
}


// Address: 0x004232B4; symbol: _CreateFontA@56
HFONT __stdcall CreateFontA(int a1, int a2, int a3, int a4, int a5, DWORD a6, DWORD a7, DWORD a8, DWORD a9, DWORD a10, DWORD a11, DWORD a12, DWORD a13, LPCSTR a14)
{
  return CreateFontA(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
}


// Address: 0x004232BC; symbol: _CreateCompatibleDC@4
HDC __stdcall CreateCompatibleDC(HDC a1)
{
  return CreateCompatibleDC(a1);
}


// Address: 0x004232C4; symbol: _CreateCompatibleBitmap@12
HBITMAP __stdcall CreateCompatibleBitmap(HDC a1, int a2, int a3)
{
  return CreateCompatibleBitmap(a1, a2, a3);
}


// Address: 0x004232CC; symbol: _TransparentBlt@44
BOOL __stdcall TransparentBlt(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, UINT a11)
{
  return TransparentBlt(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}


// Address: 0x004232D4; symbol: _AlphaBlend@44
BOOL __stdcall AlphaBlend(HDC a1, int a2, int a3, int a4, int a5, HDC a6, int a7, int a8, int a9, int a10, BLENDFUNCTION a11)
{
  return AlphaBlend(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}


// Address: 0x004232E0; symbol: __setargv
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


// Address: 0x00423680; symbol: ___cpu_features_init
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


// Address: 0x00423760; symbol: ___do_global_dtors
void __cdecl __do_global_dtors()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))(*off_42730C)[0];
  if ( (*off_42730C)[0] )
  {
    do
    {
      v0();
      v0 = (void (*)(void))(*off_42730C)[1];
      off_42730C = (int (*)[51])((char *)off_42730C + 4);
    }
    while ( v0 );
  }
}


// Address: 0x00423790; symbol: ___do_global_ctors
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


// Address: 0x004237E0; symbol: ___main
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


// Address: 0x00423800; symbol: TlsCallback_1
signed int __stdcall TlsCallback_1(int a1, int a2, int a3)
{
  if ( a2 != 3 && a2 )
    return 1;
  __mingw_TLScallback(a1, a2);
  return 1;
}


// Address: 0x00423850; symbol: ___dyn_tls_init@12
signed int __stdcall __dyn_tls_init(int a1, int a2, int a3)
{
  if ( _CRT_MT != 2 )
    _CRT_MT = 2;
  if ( a2 != 2 && a2 == 1 )
    __mingw_TLScallback(a1, 1u);
  return 1;
}


// Address: 0x004238E0; symbol: ___tlregdtor
int __tlregdtor()
{
  return 0;
}


// Address: 0x004238F0; symbol: sub_4238F0
void sub_4238F0()
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


// Address: 0x00423950; symbol: ____w64_mingwthr_add_key_dtor
signed int __cdecl ___w64_mingwthr_add_key_dtor(int a1, int a2)
{
  int v2; // esi
  _DWORD *v4; // eax
  int v5; // ebx
  int v6; // eax

  v2 = 0;
  if ( !dword_470948 )
    return v2;
  v4 = calloc(1u, 0xCu);
  v5 = (int)v4;
  if ( !v4 )
    return -1;
  *v4 = a1;
  v4[1] = a2;
  EnterCriticalSection(&CriticalSection);
  v6 = dword_470944;
  dword_470944 = v5;
  *(_DWORD *)(v5 + 8) = v6;
  LeaveCriticalSection(&CriticalSection);
  return 0;
}


// Address: 0x004239E0; symbol: ____w64_mingwthr_remove_key_dtor
int __cdecl ___w64_mingwthr_remove_key_dtor(int a1)
{
  int v2; // edx
  _DWORD *v3; // eax

  if ( !dword_470948 )
    return 0;
  EnterCriticalSection(&CriticalSection);
  v2 = dword_470944;
  if ( dword_470944 )
  {
    if ( a1 == *(_DWORD *)dword_470944 )
    {
      dword_470944 = *(_DWORD *)(dword_470944 + 8);
      v3 = (_DWORD *)v2;
LABEL_12:
      free(v3);
      LeaveCriticalSection(&CriticalSection);
      return 0;
    }
    while ( 1 )
    {
      v3 = *(_DWORD **)(v2 + 8);
      if ( !v3 )
        break;
      if ( *v3 == a1 )
      {
        *(_DWORD *)(v2 + 8) = v3[2];
        goto LABEL_12;
      }
      v2 = *(_DWORD *)(v2 + 8);
    }
  }
  LeaveCriticalSection(&CriticalSection);
  return 0;
}


// Address: 0x00423A80; symbol: ___mingw_TLScallback
signed int __cdecl __mingw_TLScallback(int a1, unsigned int a2)
{
  signed int result; // eax

  if ( a2 == 1 )
  {
    if ( !dword_470948 )
      InitializeCriticalSection(&CriticalSection);
    dword_470948 = 1;
    result = 1;
  }
  else
  {
    if ( a2 < 1 )
    {
      if ( dword_470948 )
        sub_4238F0();
      if ( dword_470948 == 1 )
      {
        dword_470948 = 0;
        DeleteCriticalSection(&CriticalSection);
      }
    }
    else if ( a2 == 3 )
    {
      if ( dword_470948 )
        sub_4238F0();
    }
    result = 1;
  }
  return result;
}


// Address: 0x00423B20; symbol: sub_423B20
void __noreturn sub_423B20(char *a1, ...)
{
  va_list va; // [esp+24h] [ebp+8h]

  va_start(va, a1);
  fwrite("Mingw runtime failure:\n", 1u, 0x17u, &__iob[2]);
  vfprintf(&__iob[2], a1, va);
  abort();
}


// Address: 0x00423B70; symbol: sub_423B70
void *__usercall sub_423B70@<eax>(size_t a1@<ecx>, void *a2@<edx>, void *lpAddress@<eax>)
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
    sub_423B20("  VirtualQuery failed for %d bytes at address %p", 28, v4);
  if ( Buffer.Protect == 64 || Buffer.Protect == 4 )
    return memcpy(v4, v5, v3);
  VirtualProtect(Buffer.BaseAddress, Buffer.RegionSize, 0x40u, &flOldProtect);
  v7 = Buffer.Protect;
  result = memcpy(v4, v5, v3);
  if ( v7 != 64 && v7 != 4 )
    result = (void *)VirtualProtect(Buffer.BaseAddress, Buffer.RegionSize, flOldProtect, &flOldProtect);
  return result;
}


// Address: 0x00423C60; symbol: __pei386_runtime_relocator
int _pei386_runtime_relocator()
{
  int result; // eax

  result = dword_470964;
  if ( !dword_470964 )
  {
    dword_470964 = 1;
    result = 0;
  }
  return result;
}


// Address: 0x00423E30; symbol: ___chkstk_ms
void __usercall __chkstk_ms(unsigned int a1@<eax>, int a2@<ecx>, char a3)
{
  char *v3; // ecx
  unsigned int v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v5 = a2;
  v4 = a1;
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


// Address: 0x00423E60; symbol: _fesetenv
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


// Address: 0x00423ED0; symbol: sub_423ED0
signed int __usercall sub_423ED0@<eax>(char *a1@<eax>, unsigned int a2@<edx>)
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


// Address: 0x00423F70; symbol: sub_423F70
signed int __usercall sub_423F70@<eax>(int a1@<eax>)
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


// Address: 0x00423FE0; symbol: sub_423FE0
char *__usercall sub_423FE0@<eax>(char *a1@<eax>, int a2@<edx>, __int16 a3@<cx>)
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
        return v3 + 1;
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
                return v14 + 1;
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
            return v3 + 1;
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
      return v14 + 1;
    while ( v15 == 127 )
    {
      if ( !(v22 & 0x20) )
      {
        v15 = (v14++)[1];
        break;
      }
      v15 = *++v14;
      if ( *v14 == 93 )
        return v14 + 1;
    }
    ++v14;
    if ( !v15 )
      return 0;
  }
}


// Address: 0x004242A0; symbol: sub_4242A0
int __usercall sub_4242A0@<eax>(char *a1@<eax>, _BYTE *a2@<edx>, unsigned int a3@<ecx>)
{
  char *v3; // ebp
  char v4; // cl
  _BYTE *v5; // edi
  int v6; // edx
  _BYTE *v7; // esi
  char *v8; // eax
  int v9; // ebx
  int v10; // ST1C_4
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int result; // eax
  char v15; // dl
  char *v16; // ebx
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
  v5 = a2 + 1;
LABEL_3:
  v6 = v4;
  v7 = v5 - 1;
  v8 = v3 + 1;
  switch ( v4 )
  {
    case 0:
      return -(char)*v7;
    case 63:
      if ( *(v5 - 1) )
      {
        ++v3;
        goto LABEL_27;
      }
      return 63;
    case 91:
      v17 = (char)*(v5 - 1);
      if ( !*(v5 - 1) )
        return 91;
      if ( v3[1] != 33 )
      {
        v3 = sub_423FE0(v8, v17, v20);
        goto LABEL_26;
      }
      v18 = v3 + 2;
      if ( sub_423FE0(v3 + 2, v17, v20) )
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
          result = sub_4242A0(v16, v7, v20 | 0x10000);
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
      v9 = (char)*(v5 - 1);
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


// Address: 0x004244C0; symbol: sub_4244C0
signed int __usercall sub_4244C0@<eax>(int a1@<eax>, int a2@<edx>)
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


// Address: 0x00424520; symbol: sub_424520
void __usercall sub_424520(_DWORD *a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  _DWORD *v3; // ebx
  int v4; // esi
  _DWORD *v5; // eax
  int v6; // eax
  _DWORD *v7; // eax

  v3 = a1;
  v4 = a2;
  v5 = (_DWORD *)*a1;
  if ( v5 )
    sub_424520(v5, a2, a3);
  v6 = v3[2];
  if ( v6 && v4 )
    sub_4244C0(v6, v4);
  v7 = (_DWORD *)v3[1];
  if ( v7 )
    sub_424520(v7, v4, a3);
  free(v3);
}


// Address: 0x00424570; symbol: sub_424570
char *__usercall sub_424570@<eax>(const char *a1@<eax>, unsigned int a2@<edx>, int a3@<ecx>, int a4)
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
  BOOL v27; // esi
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
            return (char *)1;
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
              return (char *)1;
            }
            return (char *)1;
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
        v68 = sub_424570(v106, v108, (int)v105, a4);
        v108 = v67;
        if ( v68 == 1 )
          return (char *)1;
        if ( *v55 != 44 )
          return (char *)v68;
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
  v109 = __mingw_dirname(v10);
  v11 = v109;
  v112 = 0;
  v107 = (char *)sub_423F70((int)&v110);
  if ( !v107 )
  {
    v12 = v108;
    if ( sub_423ED0(v11, v108) )
    {
      v13 = v12;
      BYTE1(v13) |= 0x80u;
      v107 = (char *)sub_424570(v11, v13, (int)v105, (int)&v110);
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
        return (char *)1;
      v107 = (char *)sub_4244C0((int)v75, (int)&v110);
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
          v107 = (char *)sub_423ED0(v4, v108);
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
              sub_4244C0((int)v90, a4);
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
            v27 = __mingw_readdir((int)v26);
            if ( !v27 )
            {
              __mingw_closedir(v26);
              if ( v102 )
                sub_424520(v102, a4, v76);
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
            if ( v109 && *(_DWORD *)(v27 + 8) != 16 || sub_4242A0(v106, (_BYTE *)(v27 + 12), v108) )
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
                sub_4244C0((int)v39, a4);
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
          v42 = stricoll((int)v92, (int)v93);
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
      return v107;
    }
  }
  return v107;
}


// Address: 0x00424E00; symbol: ___mingw_glob
char *__cdecl __mingw_glob(char *a1, int a2, int a3, int a4)
{
  char *v4; // ebx
  char *v5; // ecx
  int v7; // eax
  void *v8; // esp
  int v9; // ecx
  void *v10; // esp
  char *v11; // edx
  char v12; // al
  char v13; // al
  char *v14; // eax
  int v15; // [esp+0h] [ebp-38h]
  char v16; // [esp+4h] [ebp-34h]
  char *v17; // [esp+18h] [ebp-20h]
  char *v18; // [esp+1Ch] [ebp-1Ch]

  v4 = a1;
  if ( a4 && !(a2 & 2) )
    *(_DWORD *)(a4 + 12) = 0;
  if ( *(char **)a4 != "glob-1.0-mingw32" )
  {
    sub_423F70(a4);
    *(_DWORD *)a4 = "glob-1.0-mingw32";
  }
  v5 = sub_424570(a1, a2, a3, a4);
  if ( v5 == (char *)2 && a2 & 0x10 )
  {
    v17 = (char *)2;
    v18 = (char *)&v15;
    v7 = 16 * ((strlen(a1) + 16) >> 4);
    v8 = alloca(v7);
    v9 = (int)v17;
    v10 = alloca(v7);
    v11 = &v16;
    do
    {
      while ( 1 )
      {
        v12 = *v4;
        if ( *v4 == 127 )
          break;
        ++v11;
        ++v4;
        *(v11 - 1) = v12;
        if ( !v12 )
          goto LABEL_13;
      }
      v13 = v4[1];
      ++v11;
      v4 += 2;
      *(v11 - 1) = v13;
    }
    while ( v13 );
LABEL_13:
    v17 = (char *)v9;
    v14 = strdup(&v16);
    v5 = v17;
    if ( v14 )
    {
      v18 = v17;
      sub_4244C0((int)v14, a4);
      v5 = v18;
    }
  }
  return v5;
}


// Address: 0x00424EF0; symbol: ___mingw_globfree
void __cdecl __mingw_globfree(void *a1)
{
  int v1; // eax
  int v2; // edi
  int v3; // ebx
  void *v4; // eax

  if ( *(char **)a1 == "glob-1.0-mingw32" )
  {
    v1 = *((_DWORD *)a1 + 1);
    v2 = v1 - 1;
    v3 = 4 * *((_DWORD *)a1 + 3);
    if ( v1 > 0 )
    {
      do
      {
        --v2;
        v4 = *(void **)(*((_DWORD *)a1 + 2) + v3);
        v3 += 4;
        free(v4);
      }
      while ( v2 != -1 );
    }
    free(*((void **)a1 + 2));
  }
}


// Address: 0x00424F50; symbol: ___mingw_dirname
char *__cdecl __mingw_dirname(char *a1)
{
  char *v1; // eax
  char *v2; // ebx
  size_t v3; // esi
  size_t v5; // eax
  size_t v6; // edx
  int v7; // eax
  void *v8; // esp
  void *v9; // esp
  bool v10; // cf
  bool v11; // zf
  _WORD *v12; // ecx
  __int16 v13; // dx
  _WORD *v14; // esi
  __int16 v15; // dx
  _WORD *i; // eax
  size_t v17; // eax
  _WORD *v18; // eax
  char *v19; // esi
  int v20; // eax
  __int16 v21; // dx
  wchar_t *v22; // ecx
  wchar_t v23; // dx
  wchar_t *v24; // eax
  size_t v25; // eax
  size_t v26; // eax
  __int16 v27; // dx
  int v28; // [esp+0h] [ebp-38h]
  wchar_t v29; // [esp+Ch] [ebp-2Ch]
  __int16 v30; // [esp+Eh] [ebp-2Ah]
  size_t v31; // [esp+10h] [ebp-28h]
  int *v32; // [esp+14h] [ebp-24h]
  __int16 v33; // [esp+1Ah] [ebp-1Eh]
  size_t v34; // [esp+1Ch] [ebp-1Ch]

  v1 = setlocale(2, 0);
  v2 = v1;
  if ( v1 )
    v2 = strdup(v1);
  setlocale(2, byte_429B44);
  if ( !a1 || !*a1 )
    goto LABEL_66;
  v32 = &v28;
  v5 = mbstowcs(0, a1, 0);
  v6 = v5;
  v7 = 16 * ((2 * v5 + 18) >> 4);
  v8 = alloca(v7);
  v9 = alloca(v7);
  v31 = mbstowcs(&v29, a1, v6);
  v10 = v31 < 1;
  v11 = v31 == 1;
  *(&v29 + v31) = 0;
  v34 = (size_t)&v29;
  v33 = v29;
  if ( !v10 && !v11 )
  {
    if ( v29 == 47 || v29 == 92 )
    {
      if ( v33 == v30 && !(_WORD)v31 )
      {
        setlocale(2, v2);
        free(v2);
        return a1;
      }
    }
    else if ( v30 == 58 )
    {
      v34 = (size_t)&v31;
      v33 = v31;
    }
  }
  if ( !v33 )
  {
LABEL_66:
    v3 = wcstombs(0, &word_429B46, 0) + 1;
    dword_470970 = realloc(dword_470970, v3);
    wcstombs((char *)dword_470970, &word_429B46, v3);
    setlocale(2, v2);
    free(v2);
    return (char *)dword_470970;
  }
  v12 = (_WORD *)v34;
  v13 = v33;
  v14 = (_WORD *)v34;
  do
  {
    while ( v13 != 47 && v13 != 92 )
    {
      v13 = v12[1];
      ++v12;
      if ( !v13 )
        goto LABEL_21;
    }
    v15 = *v12;
    for ( i = v12; *i == 47; v15 = *i )
LABEL_17:
      ++i;
    if ( v15 == 92 )
      goto LABEL_17;
    if ( !v15 )
      break;
    v13 = i[1];
    v14 = i;
    v12 = i + 1;
  }
  while ( v13 );
LABEL_21:
  if ( v34 < (unsigned int)v14 )
  {
    while ( 1 )
    {
      v20 = (int)(v14 - 1);
      if ( v34 >= (unsigned int)(v14 - 1) )
        break;
      v21 = *(v14 - 1);
      --v14;
      if ( v21 != 47 && v21 != 92 )
        goto LABEL_30;
    }
    if ( (_WORD *)v34 == v14 - 1 && (v33 == 47 || v33 == 92) && *v14 == v33 )
    {
      v27 = *(_WORD *)(v20 + 4);
      if ( v27 != 47 && v27 != 92 )
        v20 = (int)v14;
    }
LABEL_30:
    v22 = &v29;
    *(_WORD *)(v20 + 2) = 0;
    v23 = v29;
    if ( v29 == 47 || v29 == 92 )
    {
      do
      {
        do
          ++v22;
        while ( *v22 == 47 );
      }
      while ( *v22 == 92 );
      if ( (char *)v22 - (char *)&v29 > 5 )
        goto LABEL_67;
    }
    if ( v30 != v29 )
LABEL_67:
      v22 = &v29;
    else
      v23 = *v22;
    v24 = v22;
    while ( v23 )
    {
      while ( 1 )
      {
        ++v22;
        *(v22 - 1) = v23;
        if ( v23 == 47 )
          break;
        if ( *v24 == 92 )
        {
          ++v24;
          break;
        }
        v23 = v24[1];
        ++v24;
        if ( !v23 )
          goto LABEL_41;
      }
      v23 = *v24;
      if ( *v24 == 92 || v23 == 47 )
      {
        do
        {
          do
          {
            ++v24;
            v23 = *v24;
          }
          while ( *v24 == 47 );
        }
        while ( v23 == 92 );
      }
    }
LABEL_41:
    v25 = v31;
    *v22 = 0;
    v26 = wcstombs(a1, &v29, v25);
    v19 = a1;
    if ( v26 != -1 )
      a1[v26] = 0;
  }
  else
  {
    if ( v33 == 47 || v33 == 92 )
    {
      v18 = (_WORD *)(v34 + 2);
    }
    else
    {
      v17 = v34;
      *(_WORD *)v34 = 46;
      v18 = (_WORD *)(v17 + 2);
    }
    *v18 = 0;
    v34 = wcstombs(0, &v29, 0) + 1;
    dword_470970 = realloc(dword_470970, v34);
    v19 = (char *)dword_470970;
    wcstombs((char *)dword_470970, &v29, v34);
  }
  setlocale(2, v2);
  free(v2);
  return v19;
}


// Address: 0x00425350; symbol: sub_425350
HANDLE __usercall sub_425350@<eax>(const CHAR *lpFileName@<eax>, int a2@<edx>)
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


// Address: 0x00425420; symbol: sub_425420
BOOL __usercall sub_425420@<eax>(void *hFindFile@<eax>, int a2@<edx>)
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


// Address: 0x004254D0; symbol: ___mingw_opendir
int __cdecl __mingw_opendir(char *a1)
{
  char *v1; // eax
  int v2; // ecx
  unsigned int v3; // edx
  int v4; // eax
  char v5; // dl
  int v6; // ecx
  unsigned int v7; // edx
  char *v8; // kr00_4
  char *v9; // eax
  int v10; // esi
  const CHAR *v11; // ebp
  HANDLE v12; // eax
  void *v14; // ST00_4
  char v15; // [esp+1Bh] [ebp-121h]
  char v16[288]; // [esp+1Ch] [ebp-120h]

  if ( a1 )
  {
    if ( *a1 )
    {
      _fullpath(v16, a1, 0x104u);
      v1 = v16;
      if ( v16[0] )
      {
        do
        {
          v2 = *(_DWORD *)v1;
          v1 += 4;
          v3 = ~v2 & (v2 - 16843009) & 0x80808080;
        }
        while ( !v3 );
        if ( !(~v2 & (v2 - 16843009) & 0x8080) )
        {
          v3 >>= 16;
          v1 += 2;
        }
        v4 = &v1[-__CFADD__((_BYTE)v3, (_BYTE)v3) - 3] - v16;
        v5 = *(&v15 + v4);
        if ( v5 != 47 && v5 != 92 )
          *(_WORD *)&v16[v4++] = 92;
      }
      else
      {
        do
        {
          v6 = *(_DWORD *)v1;
          v1 += 4;
          v7 = ~v6 & (v6 - 16843009) & 0x80808080;
        }
        while ( !v7 );
        if ( !(~v6 & (v6 - 16843009) & 0x8080) )
        {
          v7 >>= 16;
          v1 += 2;
        }
        v4 = &v1[-__CFADD__((_BYTE)v7, (_BYTE)v7) - 3] - v16;
      }
      *(_WORD *)&v16[v4] = 42;
      v8 = &v16[strlen(v16)];
      v9 = (char *)malloc(v8 - v16 + 284);
      v10 = (int)v9;
      if ( v9 )
      {
        v11 = v9 + 280;
        memcpy(v9 + 280, v16, v8 - v16 + 1);
        v12 = sub_425350(v11, v10);
        *(_DWORD *)(v10 + 272) = v12;
        if ( v12 == (HANDLE)-1 )
        {
          v14 = (void *)v10;
          v10 = 0;
          free(v14);
        }
        else
        {
          *(_DWORD *)(v10 + 276) = 0;
          *(_DWORD *)v10 = 0;
          *(_WORD *)(v10 + 4) = 272;
        }
      }
      else
      {
        *(_DWORD *)_errno() = 12;
      }
    }
    else
    {
      v10 = 0;
      *(_DWORD *)_errno() = 2;
    }
  }
  else
  {
    v10 = 0;
    *(_DWORD *)_errno() = 22;
  }
  return v10;
}


// Address: 0x00425690; symbol: ___mingw_readdir
BOOL __cdecl __mingw_readdir(int a1)
{
  int v1; // eax
  BOOL result; // eax

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 276);
    *(_DWORD *)(a1 + 276) = v1 + 1;
    if ( v1 <= 0 || (result = sub_425420(*(void **)(a1 + 272), a1)) != 0 )
      result = a1;
  }
  else
  {
    *(_DWORD *)_errno() = 9;
    result = 0;
  }
  return result;
}


// Address: 0x004256E0; symbol: ___mingw_closedir
int __cdecl __mingw_closedir(void *a1)
{
  int result; // eax

  if ( a1 && FindClose(*((HANDLE *)a1 + 68)) )
  {
    free(a1);
    result = 0;
  }
  else
  {
    *(_DWORD *)_errno() = 9;
    result = -1;
  }
  return result;
}


// Address: 0x00425730; symbol: ___mingw_rewinddir
_DWORD *__cdecl __mingw_rewinddir(int a1)
{
  _DWORD *result; // eax

  if ( a1 && FindClose(*(HANDLE *)(a1 + 272)) )
  {
    result = sub_425350((const CHAR *)(a1 + 280), a1);
    *(_DWORD *)(a1 + 272) = result;
    if ( result != (_DWORD *)-1 )
      *(_DWORD *)(a1 + 276) = 0;
  }
  else
  {
    result = (_DWORD *)_errno();
    *result = 9;
  }
  return result;
}


// Address: 0x00425790; symbol: ___mingw_telldir
signed int __cdecl __mingw_telldir(int a1)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 276);
  *(_DWORD *)_errno() = 9;
  return -1;
}


// Address: 0x004257C0; symbol: ___mingw_seekdir
_DWORD *__cdecl __mingw_seekdir(int a1, signed int a2)
{
  _DWORD *result; // eax

  if ( a2 < 0 )
  {
    result = (_DWORD *)_errno();
    *result = 22;
  }
  else
  {
    result = __mingw_rewinddir(a1);
    if ( a2 && *(_DWORD *)(a1 + 272) != -1 )
    {
      do
      {
        result = (_DWORD *)(*(_DWORD *)(a1 + 276) + 1);
        *(_DWORD *)(a1 + 276) = result;
        if ( a2 <= (signed int)result )
          break;
        result = (_DWORD *)sub_425420(*(void **)(a1 + 272), a1);
      }
      while ( result );
    }
  }
  return result;
}


// Address: 0x00425840; symbol: _wcstombs
size_t __cdecl wcstombs(char *a1, const wchar_t *a2, size_t a3)
{
  return _wcstombs(a1, a2, a3);
}


// Address: 0x00425848; symbol: _wcslen
size_t __cdecl wcslen(const wchar_t *a1)
{
  return _wcslen(a1);
}


// Address: 0x00425850; symbol: _vfprintf
int __cdecl vfprintf(FILE *a1, const char *a2, va_list a3)
{
  return _vfprintf(a1, a2, a3);
}


// Address: 0x00425858; symbol: _tolower
int __cdecl tolower(int a1)
{
  return _tolower(a1);
}


// Address: 0x00425860; symbol: _time
time_t __cdecl time(time_t *a1)
{
  return _time(a1);
}


// Address: 0x00425868; symbol: _strtoul
unsigned int __cdecl strtoul(const char *a1, char **a2, int a3)
{
  return _strtoul(a1, a2, a3);
}


// Address: 0x00425870; symbol: _strstr
char *__cdecl strstr(const char *a1, const char *a2)
{
  return _strstr(a1, a2);
}


// Address: 0x00425878; symbol: _strrchr
char *__cdecl strrchr(const char *a1, int a2)
{
  return _strrchr(a1, a2);
}


// Address: 0x00425880; symbol: _strlen
size_t __cdecl strlen(const char *a1)
{
  return _strlen(a1);
}


// Address: 0x00425888; symbol: _strcpy
char *__cdecl strcpy(char *a1, const char *a2)
{
  return _strcpy(a1, a2);
}


// Address: 0x00425890; symbol: _strcoll
int __cdecl strcoll(const char *a1, const char *a2)
{
  return _strcoll(a1, a2);
}


// Address: 0x00425898; symbol: _strcmp
int __cdecl strcmp(const char *a1, const char *a2)
{
  return _strcmp(a1, a2);
}


// Address: 0x004258A0; symbol: _strcat
char *__cdecl strcat(char *a1, const char *a2)
{
  return _strcat(a1, a2);
}


// Address: 0x004258A8; symbol: _srand
void __cdecl srand(unsigned int a1)
{
  _srand(a1);
}


// Address: 0x004258B8; symbol: _signal
void (__cdecl *__cdecl signal(int a1, void (__cdecl *a2)(int)))(int)
{
  return _signal(a1, a2);
}


// Address: 0x004258C0; symbol: _setlocale
char *__cdecl setlocale(int a1, const char *a2)
{
  return _setlocale(a1, a2);
}


// Address: 0x004258C8; symbol: _realloc
void *__cdecl realloc(void *a1, size_t a2)
{
  return _realloc(a1, a2);
}


// Address: 0x004258D0; symbol: _rand
int __cdecl rand()
{
  return _rand();
}


// Address: 0x004258D8; symbol: _memset
void *__cdecl memset(void *a1, int a2, size_t a3)
{
  return _memset(a1, a2, a3);
}


// Address: 0x004258E0; symbol: _memcpy
void *__cdecl memcpy(void *a1, const void *a2, size_t a3)
{
  return _memcpy(a1, a2, a3);
}


// Address: 0x004258E8; symbol: _mbstowcs
size_t __cdecl mbstowcs(wchar_t *a1, const char *a2, size_t a3)
{
  return _mbstowcs(a1, a2, a3);
}


// Address: 0x004258F0; symbol: _malloc
void *__cdecl malloc(size_t a1)
{
  return _malloc(a1);
}


// Address: 0x004258F8; symbol: _localtime
struct tm *__cdecl localtime(const time_t *a1)
{
  return _localtime(a1);
}


// Address: 0x00425900; symbol: _fwrite
size_t __cdecl fwrite(const void *a1, size_t a2, size_t a3, FILE *a4)
{
  return _fwrite(a1, a2, a3, a4);
}


// Address: 0x00425908; symbol: _free
void __cdecl free(void *a1)
{
  _free(a1);
}


// Address: 0x00425910; symbol: _clock
clock_t __cdecl clock()
{
  return _clock();
}


// Address: 0x00425918; symbol: _calloc
void *__cdecl calloc(size_t a1, size_t a2)
{
  return _calloc(a1, a2);
}


// Address: 0x00425920; symbol: _abort
void __cdecl __noreturn abort()
{
  _abort();
}


// Address: 0x00425928; symbol: __setmode
int __cdecl _setmode(int a1, int a2)
{
  return __setmode(a1, a2);
}


// Address: 0x00425930; symbol: __isctype
int __cdecl _isctype(int a1, int a2)
{
  return __isctype(a1, a2);
}


// Address: 0x00425938; symbol: __fullpath
char *__cdecl _fullpath(char *a1, const char *a2, size_t a3)
{
  return __fullpath(a1, a2, a3);
}


// Address: 0x00425940; symbol: __errno
int _errno(void)
{
  return __errno();
}


// Address: 0x00425948; symbol: __cexit
void __cdecl _cexit()
{
  __cexit();
}


// Address: 0x00425950; symbol: ___p__fmode
int __p__fmode(void)
{
  return ___p__fmode();
}


// Address: 0x00425958; symbol: ___p__environ
int __p__environ(void)
{
  return ___p__environ();
}


// Address: 0x00425960; symbol: ___getmainargs
int __cdecl __getmainargs(int a1, int a2, int a3, int a4, int a5)
{
  return ___getmainargs(a1, a2, a3, a4, a5);
}


// Address: 0x00425968; symbol: _RegSetValueExA@24
LONG __stdcall RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData)
{
  return RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData);
}


// Address: 0x00425970; symbol: _RegQueryValueExA@24
LONG __stdcall RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
  return RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
}


// Address: 0x00425978; symbol: _RegCreateKeyExA@36
LONG __stdcall RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition)
{
  return RegCreateKeyExA(
           hKey,
           lpSubKey,
           Reserved,
           lpClass,
           dwOptions,
           samDesired,
           lpSecurityAttributes,
           phkResult,
           lpdwDisposition);
}


// Address: 0x00425980; symbol: _RegCloseKey@4
LONG __stdcall RegCloseKey(HKEY hKey)
{
  return _IAT_start__(hKey);
}


// Address: 0x00425990; symbol: _UpdateWindow@4
BOOL __stdcall UpdateWindow(HWND hWnd)
{
  return UpdateWindow(hWnd);
}


// Address: 0x00425998; symbol: _TranslateMessage@4
BOOL __stdcall TranslateMessage(const MSG *lpMsg)
{
  return TranslateMessage(lpMsg);
}


// Address: 0x004259A0; symbol: _SystemParametersInfoA@16
BOOL __stdcall SystemParametersInfoA(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni)
{
  return SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni);
}


// Address: 0x004259A8; symbol: _ShowWindow@8
BOOL __stdcall ShowWindow(HWND hWnd, int nCmdShow)
{
  return ShowWindow(hWnd, nCmdShow);
}


// Address: 0x004259B0; symbol: _SetWindowTextW@8
BOOL __stdcall SetWindowTextW(HWND hWnd, LPCWSTR lpString)
{
  return SetWindowTextW(hWnd, lpString);
}


// Address: 0x004259B8; symbol: _SetWindowTextA@8
BOOL __stdcall SetWindowTextA(HWND hWnd, LPCSTR lpString)
{
  return SetWindowTextA(hWnd, lpString);
}


// Address: 0x004259C0; symbol: _SetWindowLongA@12
LONG __stdcall SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong)
{
  return SetWindowLongA(hWnd, nIndex, dwNewLong);
}


// Address: 0x004259C8; symbol: _SetForegroundWindow@4
BOOL __stdcall SetForegroundWindow(HWND hWnd)
{
  return SetForegroundWindow(hWnd);
}


// Address: 0x004259D0; symbol: _SetCursor@4
HCURSOR __stdcall SetCursor(HCURSOR hCursor)
{
  return SetCursor(hCursor);
}


// Address: 0x004259D8; symbol: _SendMessageA@16
LRESULT __stdcall SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return SendMessageA(hWnd, Msg, wParam, lParam);
}


// Address: 0x004259E0; symbol: _ReleaseDC@8
int __stdcall ReleaseDC(HWND hWnd, HDC hDC)
{
  return ReleaseDC(hWnd, hDC);
}


// Address: 0x004259E8; symbol: _RegisterClassW@4
ATOM __stdcall RegisterClassW(const WNDCLASSW *lpWndClass)
{
  return RegisterClassW(lpWndClass);
}


// Address: 0x004259F0; symbol: _MoveWindow@24
BOOL __stdcall MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint)
{
  return MoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint);
}


// Address: 0x004259F8; symbol: _MessageBoxW@16
int __stdcall MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
  return MessageBoxW(hWnd, lpText, lpCaption, uType);
}


// Address: 0x00425A00; symbol: _MessageBoxA@16
int __stdcall MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
  return MessageBoxA(hWnd, lpText, lpCaption, uType);
}


// Address: 0x00425A08; symbol: _LoadImageA@24
HANDLE __stdcall LoadImageA(HINSTANCE a1, LPCSTR a2, UINT a3, int a4, int a5, UINT a6)
{
  return LoadImageA(a1, a2, a3, a4, a5, a6);
}


// Address: 0x00425A10; symbol: _LoadCursorA@8
HCURSOR __stdcall LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName)
{
  return LoadCursorA(hInstance, lpCursorName);
}


// Address: 0x00425A18; symbol: _IsZoomed@4
BOOL __stdcall IsZoomed(HWND hWnd)
{
  return IsZoomed(hWnd);
}


// Address: 0x00425A20; symbol: _IsIconic@4
BOOL __stdcall IsIconic(HWND hWnd)
{
  return IsIconic(hWnd);
}


// Address: 0x00425A28; symbol: _InvalidateRect@12
BOOL __stdcall InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase)
{
  return InvalidateRect(hWnd, lpRect, bErase);
}


// Address: 0x00425A30; symbol: _GetWindowTextW@12
int __stdcall GetWindowTextW(HWND hWnd, LPWSTR lpString, int nMaxCount)
{
  return GetWindowTextW(hWnd, lpString, nMaxCount);
}


// Address: 0x00425A38; symbol: _GetWindowTextA@12
int __stdcall GetWindowTextA(HWND hWnd, LPSTR lpString, int nMaxCount)
{
  return GetWindowTextA(hWnd, lpString, nMaxCount);
}


// Address: 0x00425A40; symbol: _GetWindowRect@8
BOOL __stdcall GetWindowRect(HWND hWnd, LPRECT lpRect)
{
  return GetWindowRect(hWnd, lpRect);
}


// Address: 0x00425A48; symbol: _GetSystemMetrics@4
int __stdcall GetSystemMetrics(int nIndex)
{
  return GetSystemMetrics(nIndex);
}


// Address: 0x00425A50; symbol: _GetMonitorInfoA@8
BOOL __stdcall GetMonitorInfoA(HMONITOR hMonitor, LPMONITORINFO lpmi)
{
  return GetMonitorInfoA(hMonitor, lpmi);
}


// Address: 0x00425A58; symbol: _GetMessageA@16
BOOL __stdcall GetMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
  return GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
}


// Address: 0x00425A60; symbol: _GetDesktopWindow@0
HWND __stdcall GetDesktopWindow()
{
  return GetDesktopWindow();
}


// Address: 0x00425A68; symbol: _GetDC@4
HDC __stdcall GetDC(HWND hWnd)
{
  return GetDC(hWnd);
}


// Address: 0x00425A70; symbol: _GetCursorPos@4
BOOL __stdcall GetCursorPos(LPPOINT lpPoint)
{
  return GetCursorPos(lpPoint);
}


// Address: 0x00425A78; symbol: _GetAsyncKeyState@4
SHORT __stdcall GetAsyncKeyState(int vKey)
{
  return GetAsyncKeyState(vKey);
}


// Address: 0x00425A80; symbol: _FrameRect@12
int __stdcall FrameRect(HDC hDC, const RECT *lprc, HBRUSH hbr)
{
  return FrameRect(hDC, lprc, hbr);
}


// Address: 0x00425A88; symbol: _FindWindowA@8
HWND __stdcall FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName)
{
  return FindWindowA(lpClassName, lpWindowName);
}


// Address: 0x00425A90; symbol: _FillRect@12
int __stdcall FillRect(HDC hDC, const RECT *lprc, HBRUSH hbr)
{
  return FillRect(hDC, lprc, hbr);
}


// Address: 0x00425A98; symbol: _EnumDisplayMonitors@16
BOOL __stdcall EnumDisplayMonitors(HDC hdc, LPCRECT lprcClip, MONITORENUMPROC lpfnEnum, LPARAM dwData)
{
  return EnumDisplayMonitors(hdc, lprcClip, lpfnEnum, dwData);
}


// Address: 0x00425AA0; symbol: _DrawTextW@20
int __stdcall DrawTextW(HDC hDC, LPCWSTR lpString, int nCount, LPRECT lpRect, UINT uFormat)
{
  return DrawTextW(hDC, lpString, nCount, lpRect, uFormat);
}


// Address: 0x00425AA8; symbol: _DrawTextA@20
int __stdcall DrawTextA(HDC hDC, LPCSTR lpString, int nCount, LPRECT lpRect, UINT uFormat)
{
  return DrawTextA(hDC, lpString, nCount, lpRect, uFormat);
}


// Address: 0x00425AB0; symbol: _DispatchMessageA@4
LONG __stdcall DispatchMessageA(const MSG *lpMsg)
{
  return DispatchMessageA(lpMsg);
}


// Address: 0x00425AB8; symbol: _DestroyWindow@4
BOOL __stdcall DestroyWindow(HWND hWnd)
{
  return DestroyWindow(hWnd);
}


// Address: 0x00425AC0; symbol: _DefWindowProcW@16
LRESULT __stdcall DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcW(hWnd, Msg, wParam, lParam);
}


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


// Address: 0x00425AD0; symbol: _AdjustWindowRect@12
BOOL __stdcall AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu)
{
  return AdjustWindowRect(lpRect, dwStyle, bMenu);
}


// Address: 0x00425AD8; symbol: _lstrcpyA@8
LPSTR __stdcall lstrcpyA(LPSTR lpString1, LPCSTR lpString2)
{
  return lstrcpyA(lpString1, lpString2);
}


// Address: 0x00425AE0; symbol: _lstrcmpA@8
int __stdcall lstrcmpA(LPCSTR lpString1, LPCSTR lpString2)
{
  return lstrcmpA(lpString1, lpString2);
}


// Address: 0x00425AE8; symbol: _lstrcatA@8
LPSTR __stdcall lstrcatA(LPSTR lpString1, LPCSTR lpString2)
{
  return lstrcatA(lpString1, lpString2);
}


// Address: 0x00425AF0; symbol: _VirtualQuery@12
DWORD __stdcall VirtualQuery(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, DWORD dwLength)
{
  return VirtualQuery(lpAddress, lpBuffer, dwLength);
}


// Address: 0x00425AF8; symbol: _VirtualProtect@16
BOOL __stdcall VirtualProtect(LPVOID lpAddress, DWORD dwSize, DWORD flNewProtect, PDWORD lpflOldProtect)
{
  return VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect);
}


// Address: 0x00425B00; symbol: _TlsGetValue@4
LPVOID __stdcall TlsGetValue(DWORD dwTlsIndex)
{
  return TlsGetValue(dwTlsIndex);
}


// Address: 0x00425B08; symbol: _Sleep@4
void __stdcall Sleep(DWORD dwMilliseconds)
{
  Sleep(dwMilliseconds);
}


// Address: 0x00425B10; symbol: _SetUnhandledExceptionFilter@4
LPTOP_LEVEL_EXCEPTION_FILTER __stdcall SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)
{
  return SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
}


// Address: 0x00425B18; symbol: _RemoveDirectoryA@4
BOOL __stdcall RemoveDirectoryA(LPCSTR lpPathName)
{
  return RemoveDirectoryA(lpPathName);
}


// Address: 0x00425B20; symbol: _ReleaseMutex@4
BOOL __stdcall ReleaseMutex(HANDLE hMutex)
{
  return ReleaseMutex(hMutex);
}


// Address: 0x00425B28; symbol: _ReadFile@20
BOOL __stdcall ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped)
{
  return ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
}


// Address: 0x00425B30; symbol: _QueryPerformanceFrequency@4
BOOL __stdcall QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency)
{
  return QueryPerformanceFrequency(lpFrequency);
}


// Address: 0x00425B38; symbol: _QueryPerformanceCounter@4
BOOL __stdcall QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount)
{
  return QueryPerformanceCounter(lpPerformanceCount);
}


// Address: 0x00425B40; symbol: _MultiByteToWideChar@24
int __stdcall MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cchMultiByte, LPWSTR lpWideCharStr, int cchWideChar)
{
  return MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cchMultiByte, lpWideCharStr, cchWideChar);
}


// Address: 0x00425B48; symbol: _LoadLibraryA@4
HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName)
{
  return LoadLibraryA(lpLibFileName);
}


// Address: 0x00425B50; symbol: _LeaveCriticalSection@4
void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}


// Address: 0x00425B58; symbol: _InitializeCriticalSection@4
void __stdcall InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  InitializeCriticalSection(lpCriticalSection);
}


// Address: 0x00425B60; symbol: _GetUserDefaultUILanguage@0
int __stdcall GetUserDefaultUILanguage()
{
  return GetUserDefaultUILanguage();
}


// Address: 0x00425B68; symbol: _GetTickCount@0
DWORD __stdcall GetTickCount()
{
  return GetTickCount();
}


// Address: 0x00425B70; symbol: _GetTempPathA@8
DWORD __stdcall GetTempPathA(DWORD nBufferLength, LPSTR lpBuffer)
{
  return GetTempPathA(nBufferLength, lpBuffer);
}


// Address: 0x00425B78; symbol: _GetStartupInfoA@4
void __stdcall GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo)
{
  GetStartupInfoA(lpStartupInfo);
}


// Address: 0x00425B80; symbol: _GetProcAddress@8
FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
  return GetProcAddress(hModule, lpProcName);
}


// Address: 0x00425B88; symbol: _GetModuleHandleA@4
HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName)
{
  return GetModuleHandleA(lpModuleName);
}


// Address: 0x00425B90; symbol: _GetLastError@0
DWORD __stdcall GetLastError()
{
  return GetLastError();
}


// Address: 0x00425B98; symbol: _GetFileAttributesA@4
DWORD __stdcall GetFileAttributesA(LPCSTR lpFileName)
{
  return GetFileAttributesA(lpFileName);
}


// Address: 0x00425BA0; symbol: _GetCommandLineA@0
LPSTR __stdcall GetCommandLineA()
{
  return GetCommandLineA();
}


// Address: 0x00425BA8; symbol: _FreeLibrary@4
BOOL __stdcall FreeLibrary(HMODULE hLibModule)
{
  return FreeLibrary(hLibModule);
}


// Address: 0x00425BB0; symbol: _FindNextFileA@8
BOOL __stdcall FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData)
{
  return FindNextFileA(hFindFile, lpFindFileData);
}


// Address: 0x00425BB8; symbol: _FindFirstFileA@8
HANDLE __stdcall FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData)
{
  return FindFirstFileA(lpFileName, lpFindFileData);
}


// Address: 0x00425BC0; symbol: _FindClose@4
BOOL __stdcall FindClose(HANDLE hFindFile)
{
  return FindClose(hFindFile);
}


// Address: 0x00425BC8; symbol: _ExitThread@4
void __stdcall __noreturn ExitThread(DWORD dwExitCode)
{
  ExitThread(dwExitCode);
}


// Address: 0x00425BD0; symbol: _ExitProcess@4
void __stdcall __noreturn ExitProcess(UINT uExitCode)
{
  ExitProcess(uExitCode);
}


// Address: 0x00425BD8; symbol: _EnterCriticalSection@4
void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}


// Address: 0x00425BE0; symbol: _DeleteFileA@4
BOOL __stdcall DeleteFileA(LPCSTR lpFileName)
{
  return DeleteFileA(lpFileName);
}


// Address: 0x00425BE8; symbol: _DeleteCriticalSection@4
void __stdcall DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}


// Address: 0x00425BF0; symbol: _CreateThread@24
HANDLE __stdcall CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, DWORD dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId)
{
  return CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
}


// Address: 0x00425BF8; symbol: _CreateMutexA@12
HANDLE __stdcall CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
  return CreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
}


// Address: 0x00425C00; symbol: _CreateFileA@28
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


// Address: 0x00425C08; symbol: _CreateDirectoryA@8
BOOL __stdcall CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
  return CreateDirectoryA(lpPathName, lpSecurityAttributes);
}


// Address: 0x00425C10; symbol: _CloseHandle@4
BOOL __stdcall CloseHandle(HANDLE hObject)
{
  return CloseHandle(hObject);
}


// Address: 0x00425C18; symbol: _stricoll
int __cdecl stricoll(int a1, int a2)
{
  return _stricoll(a1, a2);
}


// Address: 0x00425C20; symbol: _strdup
char *__cdecl strdup(const char *a1)
{
  return _strdup(a1);
}


// Address: 0x00425C28; symbol: __Z10SteamUtilsv
ISteamUtils *SteamUtils()
{
  return *(ISteamUtils **)_SteamInternal_ContextInit(SteamUtils(void)::s_CallbackCounterAndContext);
}


// Address: 0x00425C40; symbol: __Z12SteamFriendsv
ISteamFriends *SteamFriends()
{
  return *(ISteamFriends **)_SteamInternal_ContextInit(SteamFriends(void)::s_CallbackCounterAndContext);
}


// Address: 0x00425C58; symbol: __Z14SteamUserStatsv
ISteamUserStats *SteamUserStats()
{
  return *(ISteamUserStats **)_SteamInternal_ContextInit(SteamUserStats(void)::s_CallbackCounterAndContext);
}


// Address: 0x00425C70; symbol: __Z16SteamScreenshotsv
ISteamScreenshots *SteamScreenshots()
{
  return *(ISteamScreenshots **)_SteamInternal_ContextInit(SteamScreenshots(void)::s_CallbackCounterAndContext);
}


// Address: 0x00425C88; symbol: __Z18SteamRemoteStoragev
ISteamRemoteStorage *SteamRemoteStorage()
{
  return *(ISteamRemoteStorage **)_SteamInternal_ContextInit(SteamRemoteStorage(void)::s_CallbackCounterAndContext);
}


// Address: 0x00425CA0; symbol: __Z28SteamInternal_Init_SteamAppsPP10ISteamApps
void __cdecl SteamInternal_Init_SteamApps(ISteamApps **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamApps *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMAPPS_INTERFACE_VERSION008");
}


// Address: 0x00425CCC; symbol: __Z29SteamInternal_Init_SteamUtilsPP11ISteamUtils
void __cdecl SteamInternal_Init_SteamUtils(ISteamUtils **p)
{
  *p = (ISteamUtils *)_SteamInternal_FindOrCreateUserInterface(0, "SteamUtils010");
}


// Address: 0x00425CF4; symbol: __Z31SteamInternal_Init_SteamFriendsPP13ISteamFriends
void __cdecl SteamInternal_Init_SteamFriends(ISteamFriends **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamFriends *)_SteamInternal_FindOrCreateUserInterface(v1, "SteamFriends017");
}


// Address: 0x00425D20; symbol: __Z33SteamInternal_Init_SteamUserStatsPP15ISteamUserStats
void __cdecl SteamInternal_Init_SteamUserStats(ISteamUserStats **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamUserStats *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMUSERSTATS_INTERFACE_VERSION012");
}


// Address: 0x00425D4C; symbol: __Z35SteamInternal_Init_SteamScreenshotsPP17ISteamScreenshots
void __cdecl SteamInternal_Init_SteamScreenshots(ISteamScreenshots **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamScreenshots *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMSCREENSHOTS_INTERFACE_VERSION003");
}


// Address: 0x00425D78; symbol: __Z37SteamInternal_Init_SteamRemoteStoragePP19ISteamRemoteStorage
void __cdecl SteamInternal_Init_SteamRemoteStorage(ISteamRemoteStorage **p)
{
  int v1; // eax

  v1 = _SteamAPI_GetHSteamUser();
  *p = (ISteamRemoteStorage *)_SteamInternal_FindOrCreateUserInterface(v1, "STEAMREMOTESTORAGE_INTERFACE_VERSION016");
}


// Address: 0x00425DA4; symbol: __Z9SteamAppsv
ISteamApps *SteamApps()
{
  return *(ISteamApps **)_SteamInternal_ContextInit(SteamApps(void)::s_CallbackCounterAndContext);
}


// Address: 0x00425DC0; symbol: __ZN10__cxxabiv117__class_type_infoD0Ev
_DWORD __thiscall __cxxabiv1::__class_type_info::~__class_type_info(__cxxabiv1::__class_type_info *this)
{
  __cxxabiv1::__class_type_info *v1; // ebx
  int result; // eax

  v1 = this;
  *(_DWORD *)this = &off_429D6C;
  std::type_info::~type_info(this);
  operator delete((void *)v1);
  return result;
}


// Address: 0x00425DF0; symbol: __ZN10__cxxabiv117__class_type_infoD1Ev
_DWORD __thiscall __cxxabiv1::__class_type_info::~__class_type_info(__cxxabiv1::__class_type_info *this)
{
  *(_DWORD *)this = &off_429D6C;
  return std::type_info::~type_info(this);
}


// Address: 0x00425E00; symbol: __ZN10__cxxabiv120__si_class_type_infoD0Ev
_DWORD __thiscall __cxxabiv1::__si_class_type_info::~__si_class_type_info(__cxxabiv1::__si_class_type_info *this)
{
  __cxxabiv1::__si_class_type_info *v1; // ebx
  int result; // eax

  v1 = this;
  *(_DWORD *)this = &off_429D98;
  __cxxabiv1::__class_type_info::~__class_type_info(this);
  operator delete((void *)v1);
  return result;
}


// Address: 0x00425E30; symbol: __ZN10__cxxabiv120__si_class_type_infoD1Ev
_DWORD __thiscall __cxxabiv1::__si_class_type_info::~__si_class_type_info(__cxxabiv1::__si_class_type_info *this)
{
  *(_DWORD *)this = &off_429D98;
  return __cxxabiv1::__class_type_info::~__class_type_info(this);
}


// Address: 0x00425E40; symbol: __ZN18LeaderboardEntry_tC1Ev
void __thiscall LeaderboardEntry_t::LeaderboardEntry_t(LeaderboardEntry_t *const this)
{
  CSteamID::CSteamID(&this->m_steamIDUser);
}


// Address: 0x00425E58; symbol: __ZN5BoardD1Ev
void __thiscall Board::~Board(Board *const this)
{
  Steam::~Steam(&this->st);
}


// Address: 0x00425E74; symbol: __ZN7Gdiplus11GdiplusBaseC2Ev
void __thiscall Gdiplus::GdiplusBase::GdiplusBase(Gdiplus::GdiplusBase *const this)
{
  ;
}


// Address: 0x00425E80; symbol: __ZN7Gdiplus11GdiplusBasedlEPv
void __cdecl Gdiplus::GdiplusBase::operator delete(void *in_pVoid)
{
  GdipFree((int)in_pVoid);
}


// Address: 0x00425E98; symbol: __ZN7Gdiplus11GdiplusBasenwEj
void *__cdecl Gdiplus::GdiplusBase::operator new(size_t in_size)
{
  return (void *)GdipAlloc(in_size);
}


// Address: 0x00425EB0; symbol: __ZN7Gdiplus12CachedBitmapD0Ev
void __thiscall Gdiplus::CachedBitmap::~CachedBitmap(Gdiplus::CachedBitmap *const this)
{
  Gdiplus::CachedBitmap *v1; // ST1C_4

  v1 = this;
  Gdiplus::CachedBitmap::~CachedBitmap(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// Address: 0x00425ED0; symbol: __ZN7Gdiplus12CachedBitmapD1Ev
void __thiscall Gdiplus::CachedBitmap::~CachedBitmap(Gdiplus::CachedBitmap *const this)
{
  this->_vptr_CachedBitmap = (int (**)(...))off_429DC4;
  GdipDeleteCachedBitmap((int)this->nativeCachedBitmap);
}


// Address: 0x00425EF8; symbol: __ZN7Gdiplus13CustomLineCapD0Ev
void __thiscall Gdiplus::CustomLineCap::~CustomLineCap(Gdiplus::CustomLineCap *const this)
{
  Gdiplus::CustomLineCap *v1; // ST1C_4

  v1 = this;
  Gdiplus::CustomLineCap::~CustomLineCap(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// Address: 0x00425F18; symbol: __ZN7Gdiplus13CustomLineCapD1Ev
void __thiscall Gdiplus::CustomLineCap::~CustomLineCap(Gdiplus::CustomLineCap *const this)
{
  this->_vptr_CustomLineCap = (int (**)(...))off_429DD4;
  GdipDeleteCustomLineCap((int)this->nativeCap->gap0);
}


// Address: 0x00425F40; symbol: __ZN7Gdiplus14FontCollectionD0Ev
void __thiscall Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  Gdiplus::FontCollection *v1; // ST1C_4

  v1 = this;
  Gdiplus::FontCollection::~FontCollection(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// Address: 0x00425F60; symbol: __ZN7Gdiplus14FontCollectionD1Ev
void __thiscall Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  this->_vptr_FontCollection = (int (**)(...))off_429DE4;
}


// Address: 0x00425F78; symbol: __ZN7Gdiplus14FontCollectionD2Ev
void __thiscall Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  this->_vptr_FontCollection = (int (**)(...))off_429DE4;
}


// Address: 0x00425F90; symbol: .weak.__ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii.__ZN7Gdiplus11GdiplusBasedlEPv
void __userpurge weak___ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii___ZN7Gdiplus11GdiplusBasedlEPv(_DWORD *a1@<ecx>, Gdiplus::GdiplusStartupInput *const this, Gdiplus::DebugEventProc debugEventCallback, BOOL suppressBackgroundThread, BOOL suppressExternalCodecs)
{
  *a1 = 1;
  a1[1] = this;
  a1[2] = debugEventCallback;
  a1[3] = suppressBackgroundThread;
}


// Address: 0x00425FC4; symbol: __ZN7Gdiplus21PrivateFontCollectionD0Ev
void __thiscall Gdiplus::PrivateFontCollection::~PrivateFontCollection(Gdiplus::PrivateFontCollection *const this)
{
  Gdiplus::PrivateFontCollection *v1; // ST1C_4

  v1 = this;
  Gdiplus::PrivateFontCollection::~PrivateFontCollection(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// Address: 0x00425FE4; symbol: __ZN7Gdiplus21PrivateFontCollectionD1Ev
void __thiscall Gdiplus::PrivateFontCollection::~PrivateFontCollection(Gdiplus::PrivateFontCollection *const this)
{
  Gdiplus::PrivateFontCollection *v1; // ST1C_4

  v1 = this;
  this->_vptr_FontCollection = (int (**)(...))off_429DF4;
  GdipDeletePrivateFontCollection((int)&this->nativeFontCollection);
  Gdiplus::FontCollection::~FontCollection(&v1->0);
}


// Address: 0x00426018; symbol: __ZN7Gdiplus23InstalledFontCollectionD0Ev
void __thiscall Gdiplus::InstalledFontCollection::~InstalledFontCollection(Gdiplus::InstalledFontCollection *const this)
{
  Gdiplus::InstalledFontCollection *v1; // ST1C_4

  v1 = this;
  Gdiplus::InstalledFontCollection::~InstalledFontCollection(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// Address: 0x00426038; symbol: __ZN7Gdiplus23InstalledFontCollectionD1Ev
void __thiscall Gdiplus::InstalledFontCollection::~InstalledFontCollection(Gdiplus::InstalledFontCollection *const this)
{
  this->_vptr_FontCollection = (int (**)(...))off_429E04;
  Gdiplus::FontCollection::~FontCollection(&this->0);
}


// Address: 0x00426058; symbol: __ZN7Gdiplus5Image14SetNativeImageEPNS_7GpImageE
void __thiscall Gdiplus::Image::SetNativeImage(Gdiplus::Image *const this, Gdiplus::GpImage *nativeImage)
{
  this->nativeImage = nativeImage;
}


// Address: 0x00426070; symbol: __ZN7Gdiplus5Image5CloneEv
Gdiplus::Image *__thiscall Gdiplus::Image::Clone(Gdiplus::Image *const this)
{
  Gdiplus::Image *v1; // ST1C_4
  int v2; // eax
  Gdiplus::Image *v3; // ebx
  Gdiplus::GpImage *cloneimage; // [esp+2Ch] [ebp-Ch]

  v1 = this;
  cloneimage = 0;
  v2 = GdipCloneImage((int)this->nativeImage->gap0, (int)&cloneimage);
  Gdiplus::Image::SetStatus(v1, (Gdiplus::Status)v2);
  v3 = (Gdiplus::Image *)Gdiplus::GdiplusBase::operator new(0x10u);
  Gdiplus::Image::Image(v3, cloneimage, v1->lastResult);
  return v3;
}


// Address: 0x004260DC; symbol: __ZN7Gdiplus5ImageC1EPNS_7GpImageENS_6StatusE
void __thiscall Gdiplus::Image::Image(Gdiplus::Image *const this, Gdiplus::GpImage *nativeImage, Gdiplus::Status status)
{
  Gdiplus::Image *v3; // ST1C_4

  v3 = this;
  Gdiplus::GdiplusBase::GdiplusBase((Gdiplus::GdiplusBase *const )this);
  v3->_vptr_Image = (int (**)(...))off_429E14;
  Gdiplus::Image::SetNativeImage(v3, nativeImage);
  v3->lastResult = status;
}


// Address: 0x0042611C; symbol: __ZN7Gdiplus5ImageD0Ev
void __thiscall Gdiplus::Image::~Image(Gdiplus::Image *const this)
{
  Gdiplus::Image *v1; // ST1C_4

  v1 = this;
  Gdiplus::Image::~Image(this);
  Gdiplus::GdiplusBase::operator delete(v1);
}


// Address: 0x0042613C; symbol: __ZN7Gdiplus5ImageD1Ev
void __thiscall Gdiplus::Image::~Image(Gdiplus::Image *const this)
{
  this->_vptr_Image = (int (**)(...))off_429E14;
  GdipDisposeImage((int)this->nativeImage->gap0);
}


// Address: 0x00426164; symbol: __ZN8CSteamIDC1Ev
void __thiscall CSteamID::CSteamID(CSteamID *const this)
{
  char v1; // t1
  char v2; // t1

  this->m_steamid.m_comp = 0;
  HIWORD(this->m_steamid.m_unAll64Bits) = BYTE6(this->m_steamid.m_unAll64Bits) & 0xF;
  v1 = BYTE4(this->m_steamid.m_unAll64Bits);
  BYTE4(this->m_steamid.m_unAll64Bits) = 0;
  v2 = BYTE5(this->m_steamid.m_unAll64Bits);
  BYTE5(this->m_steamid.m_unAll64Bits) = 0;
  BYTE6(this->m_steamid.m_unAll64Bits) &= 0xF0u;
}


// Address: 0x004261B0; symbol: __ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj
_DWORD __thiscall __cxxabiv1::__class_type_info::__do_catch(__cxxabiv1::__class_type_info *this, const std::type_info *thisa, void **a3, unsigned int a4)
{
  int v4; // edx
  __cxxabiv1::__class_type_info *v5; // esi
  int result; // eax

  v5 = this;
  LOBYTE(result) = std::type_info::operator==((int)this, v4, (int)thisa);
  if ( !(_BYTE)result && a4 <= 3 )
    result = (*(int (__fastcall **)(const std::type_info *, void **, __cxxabiv1::__class_type_info *))(*(_DWORD *)thisa + 20))(
               thisa,
               a3,
               v5);
  return result;
}


// Address: 0x00426200; symbol: __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE
bool __fastcall __cxxabiv1::__class_type_info::__do_upcast(int ecx0, int edx0, int a1, int a2, _DWORD *a3)
{
  bool result; // al

  result = std::type_info::operator==(ecx0, edx0, a1);
  if ( result )
  {
    a3[3] = 8;
    a3[1] = 6;
    *a3 = a2;
  }
  return result;
}


// Address: 0x00426240; symbol: __ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv
signed int __userpurge __cxxabiv1::__class_type_info::__do_upcast@<eax>(int *a1@<ecx>, __cxxabiv1::__class_type_info *this, const __cxxabiv1::__class_type_info *a3, void **a4)
{
  int v4; // eax
  signed int result; // eax
  int v6; // [esp+10h] [ebp-1Ch]
  int v7; // [esp+14h] [ebp-18h]
  int v8; // [esp+18h] [ebp-14h]
  int v9; // [esp+1Ch] [ebp-10h]

  v4 = *a1;
  v6 = 0;
  v7 = 0;
  v8 = 16;
  v9 = 0;
  (*(void (__stdcall **)(__cxxabiv1::__class_type_info *, _DWORD, int *))(v4 + 24))(this, *(_DWORD *)a3, &v6);
  result = 0;
  if ( (v7 & 6) == 6 )
  {
    *(_DWORD *)a3 = v6;
    result = 1;
  }
  return result;
}


// Address: 0x004262B0; symbol: __ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE
int __fastcall __cxxabiv1::__class_type_info::__do_dyncast(int ecx0, int edx0, int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v9; // edi
  int result; // eax

  v9 = ecx0;
  if ( a4 == a6 && std::type_info::operator==(ecx0, edx0, a5) )
  {
    a7[2] = a2;
    result = 0;
  }
  else
  {
    if ( std::type_info::operator==(v9, edx0, a3) )
    {
      *a7 = a4;
      a7[3] = 1;
      a7[1] = a2;
    }
    result = 0;
  }
  return result;
}


// Address: 0x00426330; symbol: __ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_
int __userpurge __cxxabiv1::__class_type_info::__do_find_public_src@<eax>(__cxxabiv1::__class_type_info *this, const __cxxabiv1::__class_type_info *a2, const void *a3, const __cxxabiv1::__class_type_info *a4, const void *a5)
{
  return 5 * (a4 == a2) + 1;
}


// Address: 0x00426350; symbol: __ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE
char __fastcall __cxxabiv1::__si_class_type_info::__do_upcast(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // ebp
  char result; // al

  v5 = a1;
  result = __cxxabiv1::__class_type_info::__do_upcast(a1, a2, a3, a4, a5);
  if ( !result )
    result = (*(int (__stdcall **)(int, int, _DWORD *))(**(_DWORD **)(v5 + 8) + 24))(a3, a4, a5);
  return result;
}


// Address: 0x004263B0; symbol: __ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE
int __fastcall __cxxabiv1::__si_class_type_info::__do_dyncast(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _DWORD *a9)
{
  bool v9; // al
  int v10; // edx
  int result; // eax
  bool v12; // al
  int v13; // [esp+18h] [ebp-24h]

  v13 = a1;
  v9 = std::type_info::operator==(a1, a5, a5);
  v10 = a5;
  if ( v9 )
  {
    *a9 = a6;
    a9[1] = a4;
    if ( a3 < 0 )
    {
      if ( a3 == -2 )
        a9[3] = 1;
    }
    else
    {
      a9[3] = 5 * (a8 == a6 + a3) + 1;
    }
    result = 0;
  }
  else if ( a6 == a8 && (v12 = std::type_info::operator==(v13, a5, a7), v10 = a5, v12) )
  {
    a9[2] = a4;
    result = 0;
  }
  else
  {
    result = (*(int (__stdcall **)(int, int, int, int, int, int, _DWORD *))(**(_DWORD **)(v13 + 8) + 28))(
               a3,
               a4,
               v10,
               a6,
               a7,
               a8,
               a9);
  }
  return result;
}


// Address: 0x004264A0; symbol: __ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_
_DWORD __thiscall __cxxabiv1::__si_class_type_info::__do_find_public_src(__cxxabiv1::__si_class_type_info *this, int thisa, const void *a3, const __cxxabiv1::__class_type_info *a4, const void *a5)
{
  __cxxabiv1::__si_class_type_info *v5; // edx
  int result; // eax
  __cxxabiv1::__si_class_type_info *v7; // ST1C_4
  bool v8; // al

  v5 = this;
  if ( a5 == a3 && (v7 = this, v8 = std::type_info::operator==((int)this, (int)this, (int)a4), v5 = v7, v8) )
    result = 6;
  else
    result = (*(int (__stdcall **)(int, const void *, const __cxxabiv1::__class_type_info *, const void *))(**((_DWORD **)v5 + 2) + 32))(
               thisa,
               a3,
               a4,
               a5);
  return result;
}


// Address: 0x00426510; symbol: __ZNK7Gdiplus5Image9SetStatusENS_6StatusE
Gdiplus::Status __thiscall Gdiplus::Image::SetStatus(const Gdiplus::Image *const this, Gdiplus::Status status)
{
  if ( status == Ok )
    return 0;
  this->lastResult = status;
  return this->lastResult;
}


// Address: 0x00426538; symbol: __ZNK8CSteamID15GetEAccountTypeEv
EAccountType __thiscall CSteamID::GetEAccountType(const CSteamID *const this)
{
  return (unsigned __int8)(BYTE6(this->m_steamid.m_unAll64Bits) >> 4);
}


// Address: 0x00426550; symbol: __ZNKSt9type_info10__do_catchEPKS_PPvj
_DWORD __thiscall std::type_info::__do_catch(std::type_info *this, const std::type_info *thisa, void **a3, unsigned int a4)
{
  int v4; // edx
  int result; // eax

  LOBYTE(result) = std::type_info::operator==((int)this, v4, (int)thisa);
  return result;
}


// Address: 0x00426570; symbol: __ZNKSt9type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv
int __userpurge std::type_info::__do_upcast@<eax>(std::type_info *this, const __cxxabiv1::__class_type_info *a2, void **a3)
{
  return 0;
}


// Address: 0x00426580; symbol: __ZNKSt9type_info14__is_pointer_pEv
_DWORD __thiscall std::type_info::__is_pointer_p(std::type_info *this)
{
  return 0;
}


// Address: 0x00426590; symbol: __ZNKSt9type_infoeqERKS_
bool __fastcall std::type_info::operator==(int a1, int a2, int a3)
{
  if ( a3 == a1 )
    return 1;
  if ( **(_BYTE **)(a1 + 4) == 42 )
    return 0;
  return strcmp(*(const char **)(a1 + 4), (const char *)((**(_BYTE **)(a3 + 4) == 42) + *(_DWORD *)(a3 + 4))) == 0;
}


// Address: 0x004265F0; symbol: __ZNSt9type_infoD0Ev
_DWORD __thiscall std::type_info::~type_info(std::type_info *this)
{
  int result; // eax

  operator delete((void *)this);
  return result;
}


// Address: 0x00426610; symbol: __ZNSt9type_infoD1Ev
_DWORD __thiscall std::type_info::~type_info(std::type_info *this)
{
  ;
}


// Address: 0x00426620; symbol: __ZdlPv
void __cdecl operator delete(void *a1)
{
  free(a1);
}


// Address: 0x00426630; symbol: __ZdlPvj
void __cdecl operator delete(void *a1)
{
  operator delete(a1);
}


// Address: 0x00426640; symbol: _main_0
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


// Address: 0x00426710; symbol: _register_frame_ctor
int register_frame_ctor()
{
  return __gcc_register_frame();
}

