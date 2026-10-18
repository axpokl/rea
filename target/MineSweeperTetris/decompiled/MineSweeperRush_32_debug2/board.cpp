// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug2.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004019A0; symbol: __ZN5BoardC1Ev
void __cdecl Board::Board(Board *const this)
{
  Board *v1; // ecx
  Board *v2; // ST1C_4
  Steam *const v3; // ST00_4
  Sound *const v4; // ST00_4
  time_t v5; // ebx
  clock_t v6; // eax
  Block *v7; // [esp+0h] [ebp-28h]

  v2 = v1;
  Block::Block(v7);
  Steam::Steam(v3);
  Sound::Sound(v4);
  v2->mode = 0;
  v2->mode_ = 0;
  v2->rightb = 0;
  v2->aliveb = 0;
  v2->delayb = 1;
  v2->delayb__ = 0;
  v2->mdb_ = 0;
  v2->tutb = 1;
  v2->tutx[0] = 5;
  v2->tutx[1] = 5;
  v2->tutx[2] = 4;
  v2->tutx[3] = 9;
  v2->tutx[4] = 8;
  v2->tutx[5] = 8;
  v2->tutx[6] = 9;
  v2->tutx[7] = 10;
  v2->tutx[8] = 2;
  v2->tutx[9] = 2;
  v2->tutx[10] = 3;
  v2->tutx[11] = 3;
  v2->tutx[12] = 2;
  v2->tuty[0] = 16;
  v2->tuty[1] = 17;
  v2->tuty[2] = 17;
  v2->tuty[3] = 17;
  v2->tuty[4] = 17;
  v2->tuty[5] = 18;
  v2->tuty[6] = 18;
  v2->tuty[7] = 18;
  v2->tuty[8] = 17;
  v2->tuty[9] = 16;
  v2->tuty[10] = 17;
  v2->tuty[11] = 19;
  v2->tuty[12] = 19;
  v2->tutm[0] = 1;
  v2->tutm[1] = 1;
  v2->tutm[2] = 3;
  v2->tutm[3] = 2;
  v2->tutm[4] = 3;
  v2->tutm[5] = 3;
  v2->tutm[6] = 3;
  v2->tutm[7] = 3;
  v2->tutm[8] = 1;
  v2->tutm[9] = 2;
  v2->tutm[10] = 3;
  v2->tutm[11] = 3;
  v2->tutm[12] = 3;
  v2->relaxb = 0;
  v2->rulemain = 0;
  v2->blckrule = 0;
  v2->rulemain = (Board::rule *)calloc(0x4000u, 0x50u);
  v2->blckrule = (int (*)[128])calloc(0x80u, 0x200u);
  v5 = time(0);
  v6 = clock();
  srand(v5 + v6);
}



// 阅读说明：初始化棋盘；存在多个重载，参数和初始化细节见下方函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00401CD0; symbol: __ZN5Board6initbdEv
void __cdecl Board::initbd(Board *const this)
{
  int v1; // ecx
  signed int v2; // edx
  signed int v3; // eax
  signed int v4; // edx
  signed int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp+4h] [ebp-44h]
  int v9; // [esp+4h] [ebp-44h]
  int v10; // [esp+4h] [ebp-44h]
  Board *thisa; // [esp+1Ch] [ebp-2Ch]
  int mode__[4]; // [esp+28h] [ebp-20h]
  int j; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]

  thisa = (Board *)v1;
  Steam::setlead(*(Steam *const *)(v1 + 2128), v8);
  thisa->sit = 0;
  thisa->line = 0;
  thisa->level = 0;
  thisa->tetrisi = 0;
  thisa->missi = 0;
  thisa->missline = 0;
  thisa->sum = 0;
  if ( thisa->maxbdw > 128 )
    v2 = 128;
  else
    v2 = thisa->maxbdw;
  v3 = thisa->w;
  if ( thisa->w < 12 )
    v3 = 12;
  if ( v2 > v3 )
    v2 = v3;
  thisa->w = v2;
  if ( thisa->maxbdh > 128 )
    v4 = 128;
  else
    v4 = thisa->maxbdh;
  v5 = thisa->h;
  if ( v5 < 8 )
    v5 = 8;
  if ( v4 > v5 )
    v4 = v5;
  thisa->h = v4;
  v6 = thisa->w - 1;
  if ( v6 > thisa->n )
    v6 = thisa->n;
  if ( v6 <= 0 )
    v6 = 1;
  thisa->n = v6;
  v7 = thisa->maskj0;
  if ( v7 > thisa->h - 4 )
    v7 = thisa->h - 4;
  thisa->maskj = v7;
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
  Sound::playsound((Sound *const )thisa->sd.sNew, v9);
  mode__[0] = 0;
  mode__[1] = 1;
  mode__[2] = 2;
  mode__[3] = 4;
  thisa->mode_ |= mode__[thisa->mode];
  if ( !thisa->mode )
    Steam::addach((Steam *const )thisa->st.achgencustom, v10);
  if ( thisa->mode_ == 7 )
    Steam::addach((Steam *const )thisa->st.achgenmode, v10);
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



// 阅读说明：初始化棋盘；存在多个重载，参数和初始化细节见下方函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402062; symbol: __ZN5Board6initbdEllll
void __userpurge Board::initbd(Board **a1@<ecx>, Board *const this, int w_, int h_, int maskj_, int n_)
{
  Board *v6; // [esp+0h] [ebp-18h]

  *a1 = this;
  a1[1] = (Board *)w_;
  a1[2] = (Board *)maskj_;
  a1[537] = (Board *)h_;
  Board::initbd(v6);
}



// 阅读说明：初始化棋盘；存在多个重载，参数和初始化细节见下方函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004020A0; symbol: __ZN5Board6initbdEll
void __userpurge Board::initbd(int a1@<ecx>, Board *const this, int mode_, int md_)
{
  int v4; // eax
  int v5; // [esp+4h] [ebp-24h]
  int v6; // [esp+10h] [ebp-18h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = (Board *)a1;
  Steam::setlead(*(Steam *const *)(a1 + 2128), v5);
  thisa->mode = (int)this;
  v4 = thisa->mode;
  switch ( v4 )
  {
    case 2:
      Board::initbd((Board **)thisa, (Board *const )0x10, 24, 8, 3, v6);
      break;
    case 3:
      Board::initbd((Board **)thisa, (Board *const )0x20, 32, 8, 6, v6);
      break;
    case 1:
      Board::initbd((Board **)thisa, (Board *const )0xC, 20, 8, 2, v6);
      break;
  }
  thisa->mdb = mode_ <= 1;
}



// 阅读说明：函数名指向随机布雷；随机调用和排除条件以函数体为准。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040218E; symbol: __ZN5Board8randmineEll
void __userpurge Board::randmine(Board *a1@<ecx>, Board *const this, int x, int y)
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

  thisa = a1;
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
    for ( j_0 = x - 1; x + 1 >= j_0; ++j_0 )
    {
      for ( i_0 = (int)&this[-1].solven + 3; (signed int)&this->w + 1 >= i_0; ++i_0 )
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
  thisa->rx = (int)this;
  thisa->ry = x;
  if ( thisa->mine[(_DWORD)this][x] )
  {
    for ( i_1 = 0; thisa->w > i_1; ++i_1 )
    {
      if ( thisa->mine[i_1][x] != 1 )
      {
        thisa->rx = i_1;
        thisa->ry = x;
      }
    }
    thisa->mine[thisa->rx][thisa->ry] = 1;
    thisa->mine[(_DWORD)this][x] = 0;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402482; symbol: __ZN5Board7tutmineEv
void __cdecl Board::tutmine(Board *const this)
{
  Board *v1; // ecx
  Board *thisa; // [esp+Ch] [ebp-4Ch]
  int rx1_[5]; // [esp+18h] [ebp-40h]
  int rx0_[5]; // [esp+2Ch] [ebp-2Ch]
  bool mb_0; // [esp+42h] [ebp-16h]
  bool mb; // [esp+43h] [ebp-15h]
  int i; // [esp+44h] [ebp-14h]
  int i_0; // [esp+48h] [ebp-10h]
  int j; // [esp+4Ch] [ebp-Ch]

  thisa = v1;
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402710; symbol: __ZN5Board7resetbdEll
void __userpurge Board::resetbd(Board *a1@<ecx>, Board *const this, int x, int y)
{
  Board *v4; // [esp+0h] [ebp-28h]
  Block *v5; // [esp+0h] [ebp-28h]
  int v6; // [esp+4h] [ebp-24h]
  int v7; // [esp+8h] [ebp-20h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->tutb == 1 )
    Board::tutmine(v4);
  else
    Board::randmine(a1, this, x, v7);
  Block::calcnumb(v5);
  thisa->time = GetTimeR();
  thisa->time_ = thisa->time;
  thisa->sit = 1;
  Steam::addach((Steam *const )thisa->st.achgenstart, v6);
}



// 阅读说明：在有效且未暂停的游戏状态中，正反两次扫描棋盘并点击未揭开的无雷零数字格；从第 2 行开始。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004027A2; symbol: __ZN5Board10solveblankEv
void __cdecl Board::solveblank(Board *const this)
{
  Board *v1; // ecx
  bool v2; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j_0; // [esp+20h] [ebp-18h]
  int i_0; // [esp+24h] [ebp-14h]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  v1->solvebb = 0;
  if ( v1->sit > 0 && v1->sit <= 3 && !v1->pauseb )
  {
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = 2; thisa->h > j; ++j )
      {
        if ( thisa->mask[i][j] != 1 && thisa->mine[i][j] != 1 && !thisa->numb[i][j] )
          Board::clickleft((Board *const )i, j, 0, v2);
      }
    }
    for ( i_0 = thisa->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = thisa->h - 1; j_0 > 1; --j_0 )
      {
        if ( thisa->mask[i_0][j_0] != 1 && thisa->mine[i_0][j_0] != 1 && !thisa->numb[i_0][j_0] )
          Board::clickleft((Board *const )i_0, j_0, 0, v2);
      }
    }
  }
}



// 阅读说明：反复调用空白格处理；循环条件由 solvebb 状态决定。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040293A; symbol: __ZN5Board11solveblank_Ev
void __cdecl Board::solveblank_(Board *const this)
{
  Board *v1; // ecx
  Board *v2; // [esp+0h] [ebp-18h]
  Board *thisa; // [esp+Ch] [ebp-Ch]

  thisa = v1;
  v1->solvebb = 1;
  while ( thisa->solvebb )
    Board::solveblank(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040296A; symbol: __ZN5Board6solve0Ev
void __cdecl Board::solve0(Board *const this)
{
  Board *v1; // ecx
  bool v2; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j_0; // [esp+20h] [ebp-18h]
  int i_0; // [esp+24h] [ebp-14h]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  v1->solveb0 = 0;
  if ( v1->sit <= 3 && !v1->pauseb )
  {
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = 2; thisa->h > j; ++j )
      {
        if ( thisa->blck[i][j] )
        {
          if ( !thisa->numb[i][j] )
            Board::clicknumb((Board *const )i, j, 0, v2);
        }
      }
    }
    for ( i_0 = thisa->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = thisa->h - 1; j_0 > 1; --j_0 )
      {
        if ( thisa->blck[i_0][j_0] && !thisa->numb[i_0][j_0] )
          Board::clicknumb((Board *const )i_0, j_0, 0, v2);
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402AA4; symbol: __ZN5Board7solve0_Ev
void __cdecl Board::solve0_(Board *const this)
{
  Board *v1; // ecx
  Board *v2; // [esp+0h] [ebp-18h]
  Board *thisa; // [esp+Ch] [ebp-Ch]

  thisa = v1;
  v1->solveb0 = 1;
  while ( thisa->solveb0 )
    Board::solve0(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402AD4; symbol: __ZN5Board6solve1Ev
void __cdecl Board::solve1(Board *const this)
{
  Board *v1; // ecx
  int v2; // [esp+4h] [ebp-34h]
  bool v3; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j_0; // [esp+20h] [ebp-18h]
  int i_0; // [esp+24h] [ebp-14h]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  v1->solveb1 = 0;
  if ( v1->sit <= 3 && !v1->pauseb )
  {
    for ( i = 0; thisa->w > i; ++i )
    {
      for ( j = 2; thisa->h > j; ++j )
      {
        if ( thisa->blck[i][j] )
        {
          if ( thisa->numb[i][j] >= 0 )
            Board::clicknumb((Board *const )i, j, 0, v3);
        }
      }
    }
    for ( i_0 = thisa->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = thisa->h - 1; j_0 > 1; --j_0 )
      {
        if ( thisa->blck[i_0][j_0] && thisa->numb[i_0][j_0] >= 0 )
          Board::clicknumb((Board *const )i_0, j_0, 0, v3);
      }
    }
    Sound::playsound((Sound *const )thisa->sd.sSolve, v2);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402C2C; symbol: __ZN5Board7solve1_Ev
void __cdecl Board::solve1_(Board *const this)
{
  Board *v1; // ecx
  Board *const v2; // ST00_4
  bool v3; // [esp+4h] [ebp-24h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  v1->solveb1 = 1;
  while ( thisa->solveb1 )
  {
    Board::checkline(0, v3);
    Board::solve1(v2);
  }
}



// 阅读说明：从已揭开格的周围格构造约束：数字减去已标旗/已确认雷数，记录尚未确定的相邻坐标。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402C70; symbol: __ZN5Board10createruleEv
void __cdecl Board::createrule(Board *const this)
{
  Board *v1; // ecx
  int *v2; // [esp+14h] [ebp-44h]
  Board *thisa; // [esp+2Ch] [ebp-2Ch]
  Block *k; // [esp+34h] [ebp-24h]
  int j; // [esp+38h] [ebp-20h]
  int i; // [esp+3Ch] [ebp-1Ch]

  thisa = v1;
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
        for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
        {
          if ( Block::isok(thisa, k, i, j, (int)&thisa->tx, &thisa->ty, v2) )
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00402EC6; symbol: __ZN5Board11compareruleEll
void __userpurge Board::comparerule(_DWORD *a1@<ecx>, Board *const this, int rule1c, int rule2c)
{
  Board::rule rule2; // [esp+4h] [ebp-BCh]
  Board::rule rule1; // [esp+54h] [ebp-6Ch]
  int rule2k_0; // [esp+A4h] [ebp-1Ch]
  int rule1k_0; // [esp+A8h] [ebp-18h]
  int rule2k; // [esp+ACh] [ebp-14h]
  int rule1k; // [esp+B0h] [ebp-10h]

  qmemcpy(&rule1, (const void *)(a1[630] + 80 * (_DWORD)this), sizeof(rule1));
  qmemcpy(&rule2, (const void *)(a1[630] + 80 * rule1c), sizeof(rule2));
  for ( rule1k = 0; *(_DWORD *)(a1[630] + 80 * (_DWORD)this + 12) > rule1k; ++rule1k )
  {
    for ( rule2k = 0; *(_DWORD *)(a1[630] + 80 * rule1c + 12) > rule2k; ++rule2k )
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
    for ( rule1k_0 = 0; *(_DWORD *)(a1[630] + 80 * (_DWORD)this + 12) > rule1k_0; ++rule1k_0 )
    {
      if ( *(&rule1.x + rule1k_0 + 4) >= 0
        && *(&rule1.x + rule1k_0 + 12) >= 0
        && *(_BYTE *)(a1[13] + (*(&rule1.x + rule1k_0 + 4) << 7) + *(&rule1.x + rule1k_0 + 12)) != 1 )
      {
        *(_BYTE *)(a1[16] + (*(&rule1.x + rule1k_0 + 4) << 7) + *(&rule1.x + rule1k_0 + 12)) = 1;
      }
    }
    for ( rule2k_0 = 0; *(_DWORD *)(a1[630] + 80 * rule1c + 12) > rule2k_0; ++rule2k_0 )
    {
      if ( *(&rule2.x + rule2k_0 + 4) >= 0
        && *(&rule2.x + rule2k_0 + 12) >= 0
        && *(_BYTE *)(a1[13] + (*(&rule2.x + rule2k_0 + 4) << 7) + *(&rule2.x + rule2k_0 + 12)) != 1 )
      {
        *(_BYTE *)(a1[15] + (*(&rule2.x + rule2k_0 + 4) << 7) + *(&rule2.x + rule2k_0 + 12)) = 1;
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403200; symbol: __ZN5Board11compareruleEv
void __cdecl Board::comparerule(Board *const this)
{
  Board *v1; // ecx
  int v2; // [esp+8h] [ebp-40h]
  int *v3; // [esp+14h] [ebp-34h]
  Board *thisa; // [esp+2Ch] [ebp-1Ch]
  int y; // [esp+30h] [ebp-18h]
  int x; // [esp+34h] [ebp-14h]
  Block *k; // [esp+38h] [ebp-10h]
  int rulemaini; // [esp+3Ch] [ebp-Ch]

  thisa = v1;
  for ( rulemaini = 0; thisa->rulemainc > rulemaini; ++rulemaini )
  {
    x = thisa->rulemain[rulemaini].x;
    y = thisa->rulemain[rulemaini].y;
    for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
    {
      if ( Block::isok(thisa, k, x, y, (int)&thisa->tx, &thisa->ty, v3) && thisa->blckrule[thisa->tx][thisa->ty] >= 0 )
        Board::comparerule(thisa, (Board *const )rulemaini, thisa->blckrule[thisa->tx][thisa->ty], v2);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403320; symbol: __ZN5Board9applyruleEb
void __userpurge Board::applyrule(Board *a1@<ecx>, Board *const this, bool applyb)
{
  bool v3; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  signed int j; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]

  thisa = a1;
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
          if ( (_BYTE)this )
            Board::clickleft((Board *const )i, j, 0, v3);
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
        if ( (_BYTE)this )
          Board::clickright((Board *const )i, j, 0, v3);
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040354A; symbol: __ZN5Board6solve2Eb
void __userpurge Board::solve2(Board *a1@<ecx>, Board *const this, bool applyb)
{
  Board *const v3; // ST00_4
  Board *v4; // [esp+0h] [ebp-28h]
  bool v5; // [esp+4h] [ebp-24h]
  int v6; // [esp+4h] [ebp-24h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  a1->solveb2 = 0;
  a1->rulemainc = 0;
  a1->solven = 0;
  if ( a1->sit <= 3 && !a1->pauseb )
  {
    Board::createrule(v4);
    Board::comparerule(v3);
    Board::applyrule(thisa, (Board *const )(unsigned __int8)this, v5);
    if ( (_BYTE)this )
      Sound::playsound((Sound *const )thisa->sd.sSolve, v6);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004035E4; symbol: __ZN5Board6solve2Ev
void __cdecl Board::solve2(Board *const this)
{
  Board *v1; // ecx
  bool v2; // [esp+4h] [ebp-24h]

  Board::solve2(v1, (Board *const )1, v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403604; symbol: __ZN5Board7solve2_Eb
void __userpurge Board::solve2_(Board *a1@<ecx>, Board *const this, bool applyb)
{
  bool v3; // [esp+4h] [ebp-34h]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int solven_; // [esp+2Ch] [ebp-Ch]

  thisa = a1;
  a1->solveb2 = 1;
  solven_ = -1;
  while ( thisa->solveb2 == 1 && (thisa->solven > solven_ || (_BYTE)this == 1) )
  {
    solven_ = thisa->solven;
    if ( (_BYTE)this )
      Board::checkline(0, v3);
    Board::solve2(thisa, (Board *const )(unsigned __int8)this, v3);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403690; symbol: __ZN5Board7solve2_Ev
void __cdecl Board::solve2_(Board *const this)
{
  Board *v1; // ecx
  bool v2; // [esp+4h] [ebp-24h]

  Board::solve2_(v1, (Board *const )1, v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004036B0; symbol: __ZN5Board7solve3_Ev
void __cdecl Board::solve3_(Board *const this)
{
  Board *v1; // ecx
  Board *const v2; // ST00_4
  bool v3; // ST04_1
  Board *const v4; // ST00_4
  bool v5; // dl
  bool v6; // [esp+4h] [ebp-24h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  v1->solveb3 = 1;
  while ( thisa->solveb3 )
  {
    Board::checkline(0, v6);
    Board::solve1(v2);
    Board::checkline(0, v3);
    Board::solve2(v4);
    v5 = thisa->solveb1 || thisa->solveb2;
    thisa->solveb3 = v5;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403744; symbol: __ZN5Board10checkerrorEll
BOOL __userpurge Board::checkerror@<eax>(Board *a1@<ecx>, Board *const this, int i, int j)
{
  Board *const v4; // ST00_4
  int v5; // ST0C_4
  bool v6; // ST04_1
  Board *const v7; // ST00_4
  int v8; // ST04_4
  Board *v10; // [esp+0h] [ebp-38h]
  int v11; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  bool result; // [esp+2Fh] [ebp-9h]

  thisa = a1;
  result = 0;
  if ( a1->blck[(_DWORD)this][i] && a1->mine[(_DWORD)this][i] && a1->sit != 2 && a1->sit <= 3 )
  {
    a1->dieb = 1;
    a1->diex = (int)this;
    a1->diey = i;
    a1->blck[(_DWORD)this][i] = 0;
    a1->flag[(_DWORD)this][i] = 1;
    a1->qstn[(_DWORD)this][i] = 0;
    a1->sit = 2;
    if ( a1->solven > 0 || a1->tutb > 0 )
    {
      Board::addline(v10);
      Board::addline(v4);
      Steam::compscr((Steam *const )(thisa->line - thisa->missline), thisa->mode, thisa->st.scrindexnomiss, v11);
      thisa->missline = thisa->line;
      Steam::compscr((Steam *const )++thisa->missi, thisa->mode, thisa->st.scrindexmiss, v5);
      Board::checkline((Board *const )1, v6);
      Board::checkdie(v7);
    }
    if ( thisa->sit == 2 )
      thisa->sit = 1;
    Steam::addscr((Steam *const )thisa->st.scrdead, 1, thisa->mode, v11);
    Sound::playsound((Sound *const )thisa->sd.sError, v8);
    thisa->sb = 0;
    result = 1;
    thisa->checkr = 1;
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403990; symbol: __ZN5Board10checkerrorEv
bool __cdecl Board::checkerror(Board *const this)
{
  Board *v1; // ecx
  int v3; // [esp+8h] [ebp-30h]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j; // [esp+24h] [ebp-14h]
  Board *i; // [esp+28h] [ebp-10h]
  char result; // [esp+2Fh] [ebp-9h]

  thisa = v1;
  result = 0;
  if ( v1->sit != 2 && v1->sit <= 3 )
  {
    v1->dieb = 0;
    for ( i = 0; thisa->w > (signed int)i; i = (Board *)((char *)i + 1) )
    {
      for ( j = 0; thisa->h > j; ++j )
        result = Board::checkerror(thisa, i, j, v3);
    }
  }
  return result;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403A10; symbol: __ZN5Board9checklineEb
void __userpurge Board::checkline(Board *a1@<ecx>, Board *const this, bool delayb_)
{
  int dl_0; // ST4C_4
  Board *v4; // [esp+0h] [ebp-78h]
  Board *v5; // [esp+0h] [ebp-78h]
  int v6; // [esp+4h] [ebp-74h]
  Board *thisa; // [esp+3Ch] [ebp-3Ch]
  int maskj_; // [esp+50h] [ebp-28h]
  int k; // [esp+54h] [ebp-24h]
  int i; // [esp+58h] [ebp-20h]
  int j_; // [esp+5Ch] [ebp-1Ch]
  int flagc; // [esp+60h] [ebp-18h]
  int blckc; // [esp+64h] [ebp-14h]
  bool delb; // [esp+6Bh] [ebp-Dh]
  Board *j; // [esp+6Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->sit > 0 && a1->sit <= 3 && !a1->pauseb )
  {
    Board::solve0_(v4);
    delb = 0;
    j = (Board *)(thisa->h - 1);
    j_ = 0;
    maskj_ = thisa->maskj & ~(thisa->maskj >> 31);
    while ( (signed int)j >= maskj_ )
    {
      blckc = 0;
      flagc = 0;
      for ( i = 0; thisa->w > i; ++i )
      {
        if ( *((_BYTE *)&j->w + (unsigned int)thisa->blck[i]) != 1 )
          ++blckc;
        if ( *((_BYTE *)&j->w + (unsigned int)thisa->flag[i]) )
          ++flagc;
      }
      if ( thisa->n != blckc && thisa->n != flagc )
      {
        j = (Board *)((char *)j - 1);
      }
      else
      {
        delb = 1;
        Board::delline(j, v6);
        if ( thisa->delayb && (_BYTE)this || thisa->tutb == 1 )
        {
          for ( k = 0; thisa->mult > (long double)k; ++k )
            Line(
              0,
              (signed int)((long double)(16 * (signed int)((char *)&j->w - j_ + 3) + 8) * thisa->mult
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
      if ( (Sound::playsound((Sound *const )thisa->sd.sSolve, v6), thisa->delayb) && (_BYTE)this || thisa->tutb == 1 )
      {
        FreshWin();
        dl_0 = (signed int)(1000.0 / ((long double)thisa->level / 5.0 + 1.0));
        thisa->time = thisa->time + (long double)dl_0 / 1000.0;
        Delay(dl_0);
        thisa->delayb__ = 1;
      }
    }
    Board::solve0_(v5);
    Board::solve2_(thisa, 0, v6);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403D02; symbol: __ZN5Board7addlineEb
void __userpurge Board::addline(Board *a1@<ecx>, Board *const this, bool misslineb)
{
  int *v3; // [esp+14h] [ebp-44h]
  Board *thisa; // [esp+2Ch] [ebp-2Ch]
  int j; // [esp+3Ch] [ebp-1Ch]
  Block *k; // [esp+40h] [ebp-18h]
  int j_0; // [esp+44h] [ebp-14h]
  int i_0; // [esp+48h] [ebp-10h]
  int i; // [esp+4Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->sit > 0 && a1->sit <= 3 && !a1->pauseb )
  {
    --a1->bouns;
    --a1->maskj;
    if ( a1->relaxb && a1->maskj <= 0 )
    {
      --a1->line;
      --a1->sum;
      a1->line &= ~(a1->line >> 31);
      if ( (_BYTE)this )
      {
        --a1->missline;
        a1->missline &= ~(a1->missline >> 31);
      }
      a1->sum &= ~(a1->sum >> 31);
      ++a1->maskj;
    }
    j = a1->maskj;
    if ( a1->maskj >= 0 )
    {
      for ( i = 0; a1->w > i; ++i )
        a1->mask[i][j] = 0;
      for ( i_0 = 0; thisa->w > i_0; ++i_0 )
      {
        for ( j_0 = thisa->maskj + 1; thisa->maskj <= j_0; --j_0 )
        {
          thisa->numb[i_0][j_0] = 0;
          for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
          {
            if ( Block::isok(thisa, k, i_0, j_0, (int)&thisa->tx, &thisa->ty, v3) )
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
      a1->maskjb = 1;
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403F5E; symbol: __ZN5Board7addlineEv
void __cdecl Board::addline(Board *const this)
{
  Board *v1; // ecx
  bool v2; // [esp+4h] [ebp-24h]

  Board::addline(v1, (Board *const )1, v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00403F7E; symbol: __ZN5Board7addmaskEv
bool __cdecl Board::addmask(Board *const this)
{
  Board *v1; // ecx
  Board *v3; // [esp+0h] [ebp-28h]
  bool v4; // [esp+4h] [ebp-24h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->sit <= 0 || v1->sit > 3 || v1->pauseb )
  {
    v1->time = GetTimeR() - v1->pausetime;
    return 0;
  }
  if ( v1->tutb || GetTimeR() <= v1->time + 5.0 / ((long double)v1->level + 5.0) )
    return 0;
  while ( GetTimeR() > thisa->time + 5.0 / ((long double)thisa->level + 5.0) )
  {
    thisa->time = thisa->time + 5.0 / ((long double)thisa->level + 5.0);
    if ( ++thisa->maski == thisa->w )
    {
      thisa->maski = 0;
      Board::addline(v3);
      Board::checkline(thisa, (Board *const )1, v4);
    }
  }
  Board::checkdie(v3);
  return 1;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004040FC; symbol: __ZN5Board8checkdieEv
void __cdecl Board::checkdie(Board *const this)
{
  Board *v1; // ecx
  int v2; // [esp+4h] [ebp-24h]
  int v3; // [esp+4h] [ebp-24h]
  int v4; // [esp+4h] [ebp-24h]
  int v5; // [esp+Ch] [ebp-1Ch]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( (!v1->maskj && v1->maski > 0 || v1->maskj < 0) && v1->sit <= 3 && !v1->relaxb )
  {
    Steam::compscr((Steam *const )(v1->line - v1->missline), v1->mode, v1->st.scrindexnomiss, v5);
    thisa->missline = thisa->line;
    thisa->aliveb = 0;
    thisa->sit = 4;
    if ( thisa->dieb )
      thisa->blck[thisa->diex][thisa->diey] = 1;
    Sound::playsound((Sound *const )thisa->sd.sLose, v3);
    if ( !thisa->rightb )
      Steam::addach((Steam *const )thisa->st.achhidright, v4);
    Steam::setlead((Steam *const )thisa->mode, v4);
  }
  if ( thisa->maskj || thisa->maski || thisa->sit > 3 )
  {
    if ( thisa->aliveb )
      Steam::addach((Steam *const )thisa->st.achhidalive, v2);
  }
  else
  {
    thisa->aliveb = 1;
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00404C0C; symbol: __ZN5Board7setqstnEllb
void __userpurge Board::setqstn(int a1@<ecx>, Board *const this, int x, int y, bool sb_)
{
  int v5; // [esp+4h] [ebp-24h]

  *(_BYTE *)(*(_DWORD *)(a1 + 40) + ((_DWORD)this << 7) + x) ^= 1u;
  if ( (_BYTE)y )
    Sound::playsound(*(Sound *const *)(a1 + 2072), v5);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00404C76; symbol: __ZN5Board7setqstnEll
void __userpurge Board::setqstn(int a1@<ecx>, Board *const this, int x, int y)
{
  bool v4; // [esp+Ch] [ebp-1Ch]

  Board::setqstn(a1, this, x, 1, v4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00404CA6; symbol: __ZN5Board7setflagEll
void __userpurge Board::setflag(Board *a1@<ecx>, Board *const this, int x, int y)
{
  int v4; // [esp+4h] [ebp-44h]
  int *v5; // [esp+14h] [ebp-34h]
  Board *thisa; // [esp+2Ch] [ebp-1Ch]
  Block *k_0; // [esp+30h] [ebp-18h]
  Block *k; // [esp+34h] [ebp-14h]
  bool sc; // [esp+3Bh] [ebp-Dh]
  int qc; // [esp+3Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->sit > 0 && a1->sit <= 3 && !a1->pauseb )
  {
    qc = 0;
    sc = 0;
    for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
    {
      if ( Block::isok(thisa, k, (int)this, x, (int)&thisa->tx, &thisa->ty, v5)
        && thisa->blck[thisa->tx][thisa->ty] != 1 )
      {
        ++qc;
      }
    }
    if ( thisa->numb[(_DWORD)this][x] == qc )
    {
      for ( k_0 = 0; (signed int)k_0 <= 7; k_0 = (Block *)((char *)k_0 + 1) )
      {
        if ( Block::isok(thisa, k_0, (int)this, x, (int)&thisa->tx, &thisa->ty, v5)
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
        Sound::playsound((Sound *const )thisa->sd.sFlag, v4);
        thisa->sb = 0;
      }
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00404EAE; symbol: __ZN5Board8setblockEll
void __userpurge Board::setblock(Board *a1@<ecx>, Board *const this, int x, int y)
{
  Board *v4; // [esp+0h] [ebp-58h]
  int v5; // [esp+4h] [ebp-54h]
  int v6; // [esp+8h] [ebp-50h]
  int *v7; // [esp+14h] [ebp-44h]
  Board *thisa; // [esp+2Ch] [ebp-2Ch]
  Block *k_0; // [esp+3Ch] [ebp-1Ch]
  Block *k; // [esp+40h] [ebp-18h]
  bool sr; // [esp+47h] [ebp-11h]
  int qq; // [esp+48h] [ebp-10h]
  int qn; // [esp+4Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->sit > 0 && a1->sit <= 3 && !a1->pauseb )
  {
    qn = 0;
    qq = 0;
    sr = 0;
    for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
    {
      if ( Block::isok(thisa, k, (int)this, x, (int)&thisa->tx, &thisa->ty, v7) )
      {
        if ( thisa->flag[thisa->tx][thisa->ty] )
          ++qn;
        if ( thisa->qstn[thisa->tx][thisa->ty] )
          ++qq;
      }
    }
    if ( thisa->numb[(_DWORD)this][x] == qn || qn + qq == thisa->numb[(_DWORD)this][x] )
    {
      for ( k_0 = 0; (signed int)k_0 <= 7; k_0 = (Block *)((char *)k_0 + 1) )
      {
        if ( Block::isok(thisa, k_0, (int)this, x, (int)&thisa->tx, &thisa->ty, v7)
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
            Board::checkerror(thisa, (Board *const )thisa->tx, thisa->ty, v6);
          }
        }
      }
      if ( thisa->sb && sr )
      {
        Sound::playsound((Sound *const )thisa->sd.sRight, v5);
        thisa->sb = 0;
      }
    }
    if ( thisa->sb )
      Board::checkerror(v4);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004051D8; symbol: __ZN5Board9clicknumbEllb
void __userpurge Board::clicknumb(Board *a1@<ecx>, Board *const this, int x, int y, bool sb_)
{
  int v5; // ST08_4
  int v6; // [esp+8h] [ebp-20h]
  int v7; // [esp+8h] [ebp-20h]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  a1->sb = y;
  if ( a1->sb )
    a1->rightb = 1;
  Board::setblock(a1, this, x, v6);
  if ( !thisa->mdb_ || thisa->tutb == 1 )
  {
    Board::setblock(thisa, this, x, v7);
    Board::setflag(thisa, this, x, v5);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040527E; symbol: __ZN5Board9clickleftEllb
void __userpurge Board::clickleft(Board *const this, int x, int y, bool sb_)
{
  int v4; // [esp+10h] [ebp-18h]

  Board::clickleft(this, x, (unsigned __int8)y, 3, v4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004052BC; symbol: __ZN5Board10clickrightEllb
void __userpurge Board::clickright(Board *const this, int x, int y, bool sb_)
{
  int v4; // [esp+10h] [ebp-18h]

  Board::clickright(this, x, (unsigned __int8)y, 3, v4);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004052FA; symbol: __ZN5Board9clickleftEllbl
void __userpurge Board::clickleft(Board *a1@<ecx>, Board *const this, int x, int y, int sb_, int md_)
{
  bool v6; // al
  Board *v7; // [esp+0h] [ebp-28h]
  int v8; // [esp+4h] [ebp-24h]
  bool v9; // [esp+Ch] [ebp-1Ch]
  Board *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  if ( a1->mask[(_DWORD)this][x] != 1 && a1->flag[(_DWORD)this][x] != 1 )
  {
    if ( a1->blck[(_DWORD)this][x] == 1 )
    {
      if ( (_BYTE)y )
      {
        a1->mdb_ = sb_ == 5;
        Board::clicknumb(a1, this, x, (unsigned __int8)y, v9);
        thisa->mdb_ = 0;
      }
    }
    else if ( sb_ > 2 )
    {
      a1->blck[(_DWORD)this][x] = 1;
      a1->qstn[(_DWORD)this][x] = 0;
      if ( a1->sit == 2 )
        a1->sit = 1;
      if ( a1->sit == 3 )
        a1->sit = 1;
      v6 = !Board::checkerror(v7) && (_BYTE)y;
      if ( v6 )
        Sound::playsound((Sound *const )thisa->sd.sLeft, v8);
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00405462; symbol: __ZN5Board10clickrightEllbl
void __userpurge Board::clickright(Board *a1@<ecx>, Board *const this, int x, int y, int sb_, int md_)
{
  int v6; // [esp+4h] [ebp-34h]
  bool v7; // [esp+Ch] [ebp-2Ch]
  Board *thisa; // [esp+1Ch] [ebp-1Ch]
  int j; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  bool qstnb; // [esp+2Fh] [ebp-9h]

  thisa = a1;
  if ( a1->mask[(_DWORD)this][x] != 1 && a1->flag[(_DWORD)this][x] != 1 )
  {
    if ( a1->blck[(_DWORD)this][x] == 1 )
    {
      if ( (_BYTE)y && sb_ != 5 )
        Board::clicknumb(a1, this, x, (unsigned __int8)y, v7);
    }
    else if ( sb_ > 2 )
    {
      Board::setqstn((int)a1, this, x, (unsigned __int8)y, v7);
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
      Steam::addach((Steam *const )thisa->st.achhidmark, v6);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004055AC; symbol: __ZN5Board5pauseEv
void __cdecl Board::pause(Board *const this)
{
  Board *v1; // ecx
  Board *thisa; // [esp+Ch] [ebp-Ch]

  thisa = v1;
  if ( !v1->pauseb )
    v1->pausetime = GetTimeR() - v1->time;
  thisa->pauseb = thisa->pauseb == 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用或处理 Steam 相关接口。
// Address: 0x00425E64; symbol: __ZN5BoardD1Ev
void __cdecl Board::~Board(Board *const this)
{
  Steam *v1; // [esp+0h] [ebp-18h]

  Steam::~Steam(v1);
}


