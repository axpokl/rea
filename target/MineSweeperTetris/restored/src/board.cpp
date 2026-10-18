// 棋盘规则、布雷、求解、标记、加行和消行
// 基于所选 Debug EXE 的静态反编译，按 DWARF 源文件归属恢复。
// 这是供阅读的源码式伪代码；并非已验证可编译的源码。
#include "../include/recovered_types.hpp"

// 原始位置：board.cpp:3；地址：0x004019A0
// 调试记录声明：void Board()
// 功能说明：构造函数：初始化成员及所拥有的子对象。
// 可见操作：使用伪随机数。
Board::Board()
{

  time_t v2;
  clock_t v3;

  Block::Block(static_cast<Block *>(this));
  Steam::Steam(&this->st);
  Sound::Sound(&this->sd);
  this->mode = 0;
  this->mode_ = 0;
  this->rightb = 0;
  this->aliveb = 0;
  this->delayb = 1;
  this->delayb__ = 0;
  this->mdb_ = 0;
  this->tutb = 1;
  this->tutx[0] = 5;
  this->tutx[1] = 5;
  this->tutx[2] = 4;
  this->tutx[3] = 9;
  this->tutx[4] = 8;
  this->tutx[5] = 8;
  this->tutx[6] = 9;
  this->tutx[7] = 10;
  this->tutx[8] = 2;
  this->tutx[9] = 2;
  this->tutx[10] = 3;
  this->tutx[11] = 3;
  this->tutx[12] = 2;
  this->tuty[0] = 16;
  this->tuty[1] = 17;
  this->tuty[2] = 17;
  this->tuty[3] = 17;
  this->tuty[4] = 17;
  this->tuty[5] = 18;
  this->tuty[6] = 18;
  this->tuty[7] = 18;
  this->tuty[8] = 17;
  this->tuty[9] = 16;
  this->tuty[10] = 17;
  this->tuty[11] = 19;
  this->tuty[12] = 19;
  this->tutm[0] = 1;
  this->tutm[1] = 1;
  this->tutm[2] = 3;
  this->tutm[3] = 2;
  this->tutm[4] = 3;
  this->tutm[5] = 3;
  this->tutm[6] = 3;
  this->tutm[7] = 3;
  this->tutm[8] = 1;
  this->tutm[9] = 2;
  this->tutm[10] = 3;
  this->tutm[11] = 3;
  this->tutm[12] = 3;
  this->relaxb = 0;
  this->rulemain = 0;
  this->blckrule = 0;
  this->rulemain = (Board::rule *)calloc(0x4000u, 0x50u);
  this->blckrule = (int (*)[128])calloc(0x80u, 0x200u);
  v2 = time(0);
  v3 = clock();
  srand(v2 + v3);
}


// 原始位置：board.cpp:10；地址：0x00401CB6
// 调试记录声明：void initbd()
// 功能说明：初始化或切换棋盘配置。此函数有多个重载，具体参数见声明。
// 原始局部变量：long int mode__[4]；long int i；long int j。
void Board::initbd()
{
  signed int v1;
  signed int v2;
  signed int v3;
  signed int v4;
  int v5;
  int v6;

  int mode__[4];
  int j;
  int i;

  this->st.setlead(this->mode);
  this->sit = 0;
  this->line = 0;
  this->level = 0;
  this->tetrisi = 0;
  this->missi = 0;
  this->missline = 0;
  this->sum = 0;
  if ( this->maxbdw > 128 )
    v1 = 128;
  else
    v1 = this->maxbdw;
  v2 = this->w;
  if ( this->w < 12 )
    v2 = 12;
  if ( v1 > v2 )
    v1 = v2;
  this->w = v1;
  if ( this->maxbdh > 128 )
    v3 = 128;
  else
    v3 = this->maxbdh;
  v4 = this->h;
  if ( v4 < 8 )
    v4 = 8;
  if ( v3 > v4 )
    v3 = v4;
  this->h = v3;
  v5 = this->w - 1;
  if ( v5 > this->n )
    v5 = this->n;
  if ( v5 <= 0 )
    v5 = 1;
  this->n = v5;
  v6 = this->maskj0;
  if ( v6 > this->h - 4 )
    v6 = this->h - 4;
  this->maskj = v6;
  if ( this->relaxb )
    this->maskj = 1;
  this->maski = 0;
  this->maskjb = 0;
  for ( i = 0; i < this->w; ++i )
  {
    for ( j = 0; j < this->h; ++j )
    {
      this->mine[i][j] = this->n > i;
      this->flag[i][j] = 0;
      this->leftrule[i][j] = 0;
      this->rightrule[i][j] = 0;
      this->qstn[i][j] = 0;
      this->blck[i][j] = 0;
      this->mask[i][j] = this->maskj > j;
      this->numb[i][j] = 0;
    }
  }
  this->sd.playsound(this->sd.sNew);
  mode__[0] = 0;
  mode__[1] = 1;
  mode__[2] = 2;
  mode__[3] = 4;
  this->mode_ |= mode__[this->mode];
  if ( !this->mode )
    this->st.addach(this->st.achgencustom);
  if ( this->mode_ == 7 )
    this->st.addach(this->st.achgenmode);
  this->rightb = 0;
  this->tuti = 0;
  this->tutb = 0;
  this->checkr = 0;
  this->pauseb = 0;
  this->mx = -1;
  this->my = -1;
  this->bouns = 0;
  this->solven = 0;
}


// 原始位置：board.cpp:63；地址：0x00402048
// 调试记录声明：void initbd(long int w_, long int h_, long int maskj_, long int n_)
// 功能说明：初始化或切换棋盘配置。此函数有多个重载，具体参数见声明。
void Board::initbd(int w_, int h_, int maskj_, int n_)
{
  this->w = w_;
  this->h = h_;
  this->n = n_;
  this->maskj0 = maskj_;
  this->initbd();
}


// 原始位置：board.cpp:72；地址：0x00402086
// 调试记录声明：void initbd(long int mode_, long int md_)
// 功能说明：初始化或切换棋盘配置。此函数有多个重载，具体参数见声明。
void Board::initbd(int mode_, int md_)
{
  int v3;

  this->st.setlead(this->mode);
  this->mode = mode_;
  v3 = this->mode;
  switch ( v3 )
  {
    case 2:
      this->initbd(16, 24, 8, 3);
      break;
    case 3:
      this->initbd(32, 32, 8, 6);
      break;
    case 1:
      this->initbd(12, 20, 8, 2);
      break;
  }
  this->mdb = md_ <= 1;
}


// 原始位置：board.cpp:91；地址：0x00402174
// 调试记录声明：void randmine(long int x, long int y)
// 功能说明：根据随机数生成雷分布；保留首次点击位置和边界相关判断。
// 可见操作：使用伪随机数。
// 原始局部变量：long int j；long int i；bool mb；long int k；long int j；long int i；bool mb；long int i；long int j。
void Board::randmine(int x, int y)
{
  bool mb;
  bool mb_0;

  int i_1;
  int i_0;
  int j_0;
  int k;
  int i;
  int j;

  for ( j = 0; j < this->h; ++j )
  {
    for ( i = 0; i < this->w; ++i )
    {
      this->rx = rand() % this->w;
      this->ry = j;
      mb = this->mine[this->rx][this->ry];
      this->mine[this->rx][this->ry] = this->mine[i][j];
      this->mine[i][j] = mb;
    }
  }
  for ( k = 0; this->n > k; ++k )
  {
    for ( j_0 = y - 1; y + 1 >= j_0; ++j_0 )
    {
      for ( i_0 = x - 1; x + 1 >= i_0; ++i_0 )
      {
        if ( j_0 >= 0 && i_0 >= 0 && j_0 < this->h && i_0 < this->w && this->mine[i_0][j_0] )
        {
          this->rx = rand() % this->w;
          this->ry = j_0;
          mb_0 = this->mine[this->rx][this->ry];
          this->mine[this->rx][this->ry] = this->mine[i_0][j_0];
          this->mine[i_0][j_0] = mb_0;
        }
      }
    }
  }
  this->rx = x;
  this->ry = y;
  if ( this->mine[x][y] )
  {
    for ( i_1 = 0; i_1 < this->w; ++i_1 )
    {
      if ( this->mine[i_1][y] != 1 )
      {
        this->rx = i_1;
        this->ry = y;
      }
    }
    this->mine[this->rx][this->ry] = 1;
    this->mine[x][y] = 0;
  }
}


// 原始位置：board.cpp:142；地址：0x00402468
// 调试记录声明：void tutmine()
// 功能说明：设置教程用雷分布；坐标与状态写入可在下方查看。
// 可见操作：使用伪随机数。
// 原始局部变量：long int rx0_[5]；long int rx1_[5]；long int i；bool mb；long int j；long int i；bool mb。
void Board::tutmine()
{

  int rx1_[5];
  int rx0_[5];
  bool mb_0;
  bool mb;
  int i;
  int i_0;
  int j;

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
  for ( j = 0; j < this->h; ++j )
  {
    if ( this->h - 5 > j )
    {
      for ( i_0 = 0; i_0 < this->w; ++i_0 )
      {
        this->rx = rand() % this->w;
        this->ry = j;
        mb_0 = this->mine[this->rx][this->ry];
        this->mine[this->rx][this->ry] = this->mine[i_0][j];
        this->mine[i_0][j] = mb_0;
      }
    }
    else
    {
      i = 1;
      this->rx = rx1_[j - this->h + 5];
      this->ry = j;
      mb = this->mine[this->rx][this->ry];
      this->mine[this->rx][this->ry] = this->mine[i][j];
      this->mine[i][j] = mb;
      i = 0;
      this->rx = rx0_[j - this->h + 5];
      this->ry = j;
      mb = this->mine[this->rx][this->ry];
      this->mine[this->rx][this->ry] = this->mine[i][j];
      this->mine[i][j] = mb;
    }
  }
}


// 原始位置：board.cpp:179；地址：0x004026F6
// 调试记录声明：void resetbd(long int x, long int y)
// 功能说明：按点击坐标重建/重置棋盘状态，重新计算邻雷数并重置计时。
void Board::resetbd(int x, int y)
{

  if ( this->tutb == 1 )
    this->tutmine();
  else
    this->randmine(x, y);
  (static_cast<Block *>(this))->calcnumb();
  this->time = GetTimeR();
  this->time_ = this->time;
  this->sit = 1;
  this->st.addach(this->st.achgenstart);
}


// 原始位置：board.cpp:196；地址：0x00402788
// 调试记录声明：void solveblank()
// 功能说明：清除本轮求解标记，正反两次扫描 y>=2 的行，尝试点击未遮罩、非雷且数字为零的格。
// 原始局部变量：long int i；long int j；long int i；long int j。
void Board::solveblank()
{

  int j_0;
  int i_0;
  signed int j;
  int i;

  this->solvebb = 0;
  if ( this->sit > 0 && this->sit <= 3 && !this->pauseb )
  {
    for ( i = 0; i < this->w; ++i )
    {
      for ( j = 2; j < this->h; ++j )
      {
        if ( this->mask[i][j] != 1 && this->mine[i][j] != 1 && !this->numb[i][j] )
          this->clickleft(i, j, 0);
      }
    }
    for ( i_0 = this->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = this->h - 1; j_0 > 1; --j_0 )
      {
        if ( this->mask[i_0][j_0] != 1 && this->mine[i_0][j_0] != 1 && !this->numb[i_0][j_0] )
          this->clickleft(i_0, j_0, 0);
      }
    }
  }
}


// 原始位置：board.cpp:224；地址：0x00402920
// 调试记录声明：void solveblank_()
// 功能说明：在 solvebb 为真时重复展开零数字格，直到状态不再要求继续。
void Board::solveblank_()
{

  this->solvebb = 1;
  while ( this->solvebb )
    this->solveblank();
}


// 原始位置：board.cpp:233；地址：0x00402950
// 调试记录声明：void solve0()
// 功能说明：正反扫描已揭开的零数字格，通过 clicknumb 扩展周边；保留原始 sit<=3 条件。
// 原始局部变量：long int i；long int j；long int i；long int j。
void Board::solve0()
{

  int j_0;
  int i_0;
  signed int j;
  int i;

  this->solveb0 = 0;
  if ( this->sit <= 3 && !this->pauseb )
  {
    for ( i = 0; i < this->w; ++i )
    {
      for ( j = 2; j < this->h; ++j )
      {
        if ( this->blck[i][j] )
        {
          if ( !this->numb[i][j] )
            this->clicknumb(i, j, 0);
        }
      }
    }
    for ( i_0 = this->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = this->h - 1; j_0 > 1; --j_0 )
      {
        if ( this->blck[i_0][j_0] && !this->numb[i_0][j_0] )
          this->clicknumb(i_0, j_0, 0);
      }
    }
  }
}


// 原始位置：board.cpp:261；地址：0x00402A8A
// 调试记录声明：void solve0_()
// 功能说明：按 solveb0 控制重复执行 solve0，是否结束取决于内部点击更新的状态。
void Board::solve0_()
{

  this->solveb0 = 1;
  while ( this->solveb0 )
    this->solve0();
}


// 原始位置：board.cpp:270；地址：0x00402ABA
// 调试记录声明：void solve1()
// 功能说明：正反扫描已揭开且数字非负的格，调用 clicknumb，最后播放求解音效。
// 原始局部变量：long int i；long int j；long int i；long int j。
void Board::solve1()
{

  int j_0;
  int i_0;
  signed int j;
  int i;

  this->solveb1 = 0;
  if ( this->sit <= 3 && !this->pauseb )
  {
    for ( i = 0; i < this->w; ++i )
    {
      for ( j = 2; j < this->h; ++j )
      {
        if ( this->blck[i][j] )
        {
          if ( this->numb[i][j] >= 0 )
            this->clicknumb(i, j, 0);
        }
      }
    }
    for ( i_0 = this->w - 1; i_0 >= 0; --i_0 )
    {
      for ( j_0 = this->h - 1; j_0 > 1; --j_0 )
      {
        if ( this->blck[i_0][j_0] && this->numb[i_0][j_0] >= 0 )
          this->clicknumb(i_0, j_0, 0);
      }
    }
    this->sd.playsound(this->sd.sSolve);
  }
}


// 原始位置：board.cpp:299；地址：0x00402C12
// 调试记录声明：void solve1_()
// 功能说明：按 solveb1 控制重复执行一级求解；具体进展标记由点击逻辑更新。
void Board::solve1_()
{

  this->solveb1 = 1;
  while ( this->solveb1 )
  {
    this->checkline(0);
    this->solve1();
  }
}


// 原始位置：board.cpp:309；地址：0x00402C56
// 调试记录声明：void createrule()
// 功能说明：将数字格周围的未知格整理为约束，扣减已标旗或已推断雷的数量，保存坐标与剩余雷数。
// 原始局部变量：long int i；long int j；long int k。
void Board::createrule()
{

  signed int k;
  int j;
  int i;

  for ( i = 0; i < this->w; ++i )
  {
    for ( j = 0; j < this->h; ++j )
    {
      this->blckrule[i][j] = -1;
      if ( this->blck[i][j] )
      {
        this->ruletemp.x = i;
        this->ruletemp.y = j;
        this->ruletemp.numbc = this->numb[i][j];
        this->ruletemp.blckc = 0;
        for ( k = 0; k <= 7; ++k )
        {
          if ( (static_cast<Block *>(this))->isok(k, i, j, this->tx, this->ty) )
          {
            if ( this->flag[this->tx][this->ty] || this->rightrule[this->tx][this->ty] )
            {
              --this->ruletemp.numbc;
            }
            else if ( this->blck[this->tx][this->ty] != 1 )
            {
              this->ruletemp.blckx[this->ruletemp.blckc] = this->tx;
              this->ruletemp.blcky[this->ruletemp.blckc++] = this->ty;
            }
          }
        }
        this->blckrule[i][j] = this->rulemainc;
        this->rulemain[this->rulemainc++] = this->ruletemp;
      }
    }
  }
}


// 原始位置：board.cpp:346；地址：0x00402EAC
// 调试记录声明：void comparerule(long int rule1c, long int rule2c)
// 功能说明：比较两个约束或遍历比较所有约束；用共有/独有邻格关系更新推断结果。
// 原始局部变量：rule rule1；rule rule2；long int rule1k；long int rule2k；long int rule1k；long int rule2k。
void Board::comparerule(int rule1c, int rule2c)
{
  Board::rule rule2;
  Board::rule rule1;
  int rule2k_0;
  int rule1k_0;
  int rule2k;
  int rule1k;

  rule1 = this->rulemain[rule1c];
  rule2 = this->rulemain[rule2c];
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


// 原始位置：board.cpp:393；地址：0x004031E6
// 调试记录声明：void comparerule()
// 功能说明：比较两个约束或遍历比较所有约束；用共有/独有邻格关系更新推断结果。
// 原始局部变量：long int x；long int y；long int rulemaini；long int k。
void Board::comparerule()
{

  int y;
  int x;
  signed int k;
  int rulemaini;

  for ( rulemaini = 0; this->rulemainc > rulemaini; ++rulemaini )
  {
    x = this->rulemain[rulemaini].x;
    y = this->rulemain[rulemaini].y;
    for ( k = 0; k <= 7; ++k )
    {
      if ( (static_cast<Block *>(this))->isok(k, x, y, this->tx, this->ty) && this->blckrule[this->tx][this->ty] >= 0 )
        this->comparerule(rulemaini, this->blckrule[this->tx][this->ty]);
    }
  }
}


// 原始位置：board.cpp:414；地址：0x00403306
// 调试记录声明：void applyrule(bool applyb)
// 功能说明：将 leftrule/rightrule 转换为可点击/可标记的位置，更新各级求解标记与 solven；applyb 决定是否执行点击。
// 原始局部变量：long int i；long int j。
void Board::applyrule(bool applyb)
{

  signed int j;
  int i;

  for ( i = 0; i < this->w; ++i )
  {
    for ( j = 2; j < this->h; ++j )
    {
      if ( this->leftrule[i][j] )
      {
        if ( this->blck[i][j] != 1 && this->mask[i][j] != 1 )
        {
          this->solvebb = 1;
          this->solveb0 = 1;
          this->solveb1 = 1;
          this->solveb2 = 1;
          this->solveb3 = 1;
          ++this->solven;
          if ( applyb )
            this->clickleft(i, j, 0);
        }
      }
      if ( this->rightrule[i][j]
        && this->blck[i][j] != 1
        && this->qstn[i][j] != 1
        && this->flag[i][j] != 1
        && this->mask[i][j] != 1 )
      {
        this->solvebb = 1;
        this->solveb0 = 1;
        this->solveb1 = 1;
        this->solveb2 = 1;
        this->solveb3 = 1;
        ++this->solven;
        if ( applyb )
          this->clickright(i, j, 0);
      }
    }
  }
}


// 原始位置：board.cpp:450；地址：0x00403530
// 调试记录声明：void solve2(bool applyb)
// 功能说明：组合约束的建立、比较和应用；bool 参数版本与无参数包装分别保留。
void Board::solve2(bool applyb)
{

  this->solveb2 = 0;
  this->rulemainc = 0;
  this->solven = 0;
  if ( this->sit <= 3 && !this->pauseb )
  {
    this->createrule();
    this->comparerule();
    this->applyrule(applyb);
    if ( applyb )
      this->sd.playsound(this->sd.sSolve);
  }
}


// 原始位置：board.cpp:467；地址：0x004035CA
// 调试记录声明：void solve2()
// 功能说明：组合约束的建立、比较和应用；bool 参数版本与无参数包装分别保留。
void Board::solve2()
{
  this->solve2(1);
}


// 原始位置：board.cpp:472；地址：0x004035EA
// 调试记录声明：void solve2_(bool applyb)
// 功能说明：按求解进展反复处理约束；保留参数区分是否实际应用。
// 原始局部变量：long int solven_。
void Board::solve2_(bool applyb)
{

  int solven_;

  this->solveb2 = 1;
  solven_ = -1;
  while ( this->solveb2 == 1 && (this->solven > solven_ || applyb == 1) )
  {
    solven_ = this->solven;
    if ( applyb )
      this->checkline(0);
    this->solve2(applyb);
  }
}


// 原始位置：board.cpp:487；地址：0x00403676
// 调试记录声明：void solve2_()
// 功能说明：按求解进展反复处理约束；保留参数区分是否实际应用。
void Board::solve2_()
{
  this->solve2_(1);
}


// 原始位置：board.cpp:492；地址：0x00403696
// 调试记录声明：void solve3_()
// 功能说明：更高层求解控制入口；具体与其他级别的顺序关系见函数体。
void Board::solve3_()
{
  bool v1;

  this->solveb3 = 1;
  while ( this->solveb3 )
  {
    this->checkline(0);
    this->solve1();
    this->checkline(0);
    this->solve2();
    v1 = this->solveb1 || this->solveb2;
    this->solveb3 = v1;
  }
}


// 原始位置：board.cpp:505；地址：0x0040372A
// 调试记录声明：bool checkerror(long int i, long int j)
// 功能说明：检查单格或全盘的标记/规则一致性。
// 原始局部变量：bool result。
bool Board::checkerror(int i, int j)
{

  char result;

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
      this->addline();
      this->addline();
      this->st.compscr(this->line - this->missline, this->mode, this->st.scrindexnomiss);
      this->missline = this->line;
      this->st.compscr(++this->missi, this->mode, this->st.scrindexmiss);
      this->checkline(1);
      this->checkdie();
    }
    if ( this->sit == 2 )
      this->sit = 1;
    this->st.addscr(this->st.scrdead, 1, this->mode);
    this->sd.playsound(this->sd.sError);
    this->sb = 0;
    result = 1;
    this->checkr = 1;
  }
  return result;
}


// 原始位置：board.cpp:541；地址：0x00403976
// 调试记录声明：bool checkerror()
// 功能说明：检查单格或全盘的标记/规则一致性。
// 原始局部变量：bool result；long int i；long int j。
bool Board::checkerror()
{

  int j;
  int i;
  bool result;

  result = 0;
  if ( this->sit != 2 && this->sit <= 3 )
  {
    this->dieb = 0;
    for ( i = 0; i < this->w; ++i )
    {
      for ( j = 0; j < this->h; ++j )
        result = this->checkerror(i, j);
    }
  }
  return result;
}


// 原始位置：board.cpp:558；地址：0x004039F6
// 调试记录声明：void checkline(bool delayb_)
// 功能说明：从底行向上计数未揭开格与旗子，满足 n 时消行；可绘制消行动画并延时，再调用求解。
// 原始局部变量：long int j；bool delb；long int blckc；long int flagc；long int j_；long int maskj_；long int i；long int k；long int dl。
void Board::checkline(bool delayb_)
{
  int dl_0;

  int maskj_;
  int k;
  int i;
  int j_;
  int flagc;
  int blckc;
  bool delb;
  int j;

  if ( this->sit > 0 && this->sit <= 3 && !this->pauseb )
  {
    this->solve0_();
    delb = 0;
    j = this->h - 1;
    j_ = 0;
    maskj_ = this->maskj & ~(this->maskj >> 31);
    while ( j >= maskj_ )
    {
      blckc = 0;
      flagc = 0;
      for ( i = 0; i < this->w; ++i )
      {
        if ( this->blck[i][j] != 1 )
          ++blckc;
        if ( this->flag[i][j] )
          ++flagc;
      }
      if ( this->n != blckc && this->n != flagc )
      {
        --j;
      }
      else
      {
        delb = 1;
        this->delline(j);
        if ( this->delayb && delayb_ || this->tutb == 1 )
        {
          for ( k = 0; this->mult > (long double)k; ++k )
            Line(
              0,
              (signed int)((long double)(16 * (j - j_ + 3) + 8) * this->mult
                         + (long double)k
                         - (this->mult - 1.0) / 2.0),
              (signed int)((long double)this->w_ * this->mult),
              0,
              this->cred);
        }
        ++j_;
      }
    }
    if ( delb )
    {
      if ( (this->sd.playsound(this->sd.sSolve), this->delayb) && delayb_ || this->tutb == 1 )
      {
        FreshWin();
        dl_0 = (signed int)(1000.0 / ((long double)this->level / 5.0 + 1.0));
        this->time = this->time + (long double)dl_0 / 1000.0;
        Delay(dl_0);
        this->delayb__ = 1;
      }
    }
    this->solve0_();
    this->solve2_(0);
  }
}


// 原始位置：board.cpp:620；地址：0x00403CE8
// 调试记录声明：void addline(bool misslineb)
// 功能说明：新增棋盘行，带 bool 参数与无参数的包装分别保留。
// 原始局部变量：long int j；long int i；long int i；long int j；long int k。
void Board::addline(bool misslineb)
{

  int j;
  signed int k;
  int j_0;
  int i_0;
  int i;

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
      for ( i = 0; i < this->w; ++i )
        this->mask[i][j] = 0;
      for ( i_0 = 0; i_0 < this->w; ++i_0 )
      {
        for ( j_0 = this->maskj + 1; this->maskj <= j_0; --j_0 )
        {
          this->numb[i_0][j_0] = 0;
          for ( k = 0; k <= 7; ++k )
          {
            if ( (static_cast<Block *>(this))->isok(k, i_0, j_0, this->tx, this->ty) )
            {
              if ( this->mine[this->tx][this->ty] )
                ++this->numb[i_0][j_0];
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


// 原始位置：board.cpp:675；地址：0x00403F44
// 调试记录声明：void addline()
// 功能说明：新增棋盘行，带 bool 参数与无参数的包装分别保留。
void Board::addline()
{
  this->addline(1);
}


// 原始位置：board.cpp:681；地址：0x00403F64
// 调试记录声明：bool addmask()
// 功能说明：修改遮罩相关状态和棋盘处理范围。
bool Board::addmask()
{

  if ( this->sit <= 0 || this->sit > 3 || this->pauseb )
  {
    this->time = GetTimeR() - this->pausetime;
    return 0;
  }
  if ( this->tutb || GetTimeR() <= this->time + 5.0 / ((long double)this->level + 5.0) )
    return 0;
  while ( GetTimeR() > this->time + 5.0 / ((long double)this->level + 5.0) )
  {
    this->time = this->time + 5.0 / ((long double)this->level + 5.0);
    if ( ++this->maski == this->w )
    {
      this->maski = 0;
      this->addline();
      this->checkline(1);
    }
  }
  this->checkdie();
  return 1;
}


// 原始位置：board.cpp:712；地址：0x004040E2
// 调试记录声明：void checkdie()
// 功能说明：检查棋盘失败条件；具体 sit 数值的含义仍以实际赋值和调用为准。
void Board::checkdie()
{

  if ( (!this->maskj && this->maski > 0 || this->maskj < 0) && this->sit <= 3 && !this->relaxb )
  {
    this->st.compscr(this->line - this->missline, this->mode, this->st.scrindexnomiss);
    this->missline = this->line;
    this->aliveb = 0;
    this->sit = 4;
    if ( this->dieb )
      this->blck[this->diex][this->diey] = 1;
    this->sd.playsound(this->sd.sLose);
    if ( !this->rightb )
      this->st.addach(this->st.achhidright);
    this->st.setlead(this->mode);
  }
  if ( this->maskj || this->maski || this->sit > 3 )
  {
    if ( this->aliveb )
      this->st.addach(this->st.achhidalive);
  }
  else
  {
    this->aliveb = 1;
  }
}


// 原始位置：board.cpp:744；地址：0x00404286
// 调试记录声明：void delline(long int l)
// 功能说明：将被删行上方的雷、遮罩、旗子、规则和数字向下搬移，生成顶行并更新分数、Steam 记录和等级。
// 可见操作：使用伪随机数。
// 原始局部变量：long int i；long int j；long int i；long int j；bool mb；long int i；long int j；long int k；long int scrtotal_[4]；long int k。
// 反编译器警告：// local variable allocation has failed, the output may be wrong!
// 待核对：局部变量分配/重叠警告。
void Board::delline(int l)
{
  signed int v2;
  bool v3;
  int v4;
  signed int v5;
  signed int v6;

  int scrtotal_[4];
  bool mb; // 已按 DWARF 与字节访存汇编修复原导出的错误 int 类型。
  int j_0;
  int k_0;
  int k;
  int j_1;
  int i_1;
  int i_0;
  int j;
  int i;

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
      this->addline(0);
    }
    else
    {
      ++this->maskj;
    }
    for ( i = 0; i < this->w; ++i )
    {
      for ( j = l; j >= 0; --j )
      {
        if ( j )
        {
          this->mine[i][j] = this->mine[i][j - 1];
          v3 = this->mask[i][j - 1] && this->relaxb != 1;
          this->mask[i][j] = v3;
          this->flag[i][j] = this->flag[i][j - 1];
          this->leftrule[i][j] = this->leftrule[i][j - 1];
          this->rightrule[i][j] = this->rightrule[i][j - 1];
          this->qstn[i][j] = this->qstn[i][j - 1];
          this->blck[i][j] = this->blck[i][j - 1];
          this->numb[i][j] = this->numb[i][j - 1];
        }
        else
        {
          this->mine[i][0] = this->n > i;
          this->mask[i][j] = !this->maskjb;
          this->flag[i][j] = 0;
          this->leftrule[i][j] = 0;
          this->rightrule[i][j] = 0;
          this->qstn[i][j] = 0;
          this->blck[i][j] = 0;
        }
      }
    }
    this->maskjb = 0;
    for ( i_0 = 0; i_0 < this->w; ++i_0 )
    {
      this->rx = rand() % this->w;
      this->ry = 0;
      j_0 = 0;
      mb = this->mine[this->rx][this->ry];
      this->mine[this->rx][this->ry] = this->mine[i_0][j_0];
      this->mine[i_0][j_0] = mb;
    }
    for ( i_1 = 0; i_1 < this->w; ++i_1 )
    {
      v4 = this->h - 1;
      if ( v4 > l + 1 )
        v4 = l + 1;
      for ( j_1 = v4; j_1 >= l; --j_1 )
      {
        this->numb[i_1][j_1] = 0;
        for ( k = 0; k <= 7; ++k )
        {
          if ( (static_cast<Block *>(this))->isok(k, i_1, j_1, this->tx, this->ty) && this->mine[this->tx][this->ty] )
            ++this->numb[i_1][j_1];
        }
      }
    }
    ++this->line;
    ++this->sum;
    v5 = this->line;
    if ( v5 > 999999 )
      v5 = 999999;
    this->line = v5;
    if ( this->sum == this->line + this->tetrisi )
    {
      this->st.compscr(this->line, this->mode, this->st.scrindexline);
      if ( this->mdb == 1 )
        this->st.compscr(this->line, this->mode, this->st.scrindexmdb);
      this->st.compscr(this->line - this->missline, this->mode, this->st.scrindexnomiss);
      scrtotal_[0] = 0;
      scrtotal_[1] = 2;
      scrtotal_[2] = 3;
      scrtotal_[3] = 6;
      this->st.addscr(this->st.scrtotal, scrtotal_[this->mode], this->mode);
      if ( this->line > 9999 )
        this->st.addach(this->st.achhidedge);
    }
    if ( this->maskj > this->h - 4 )
    {
      ++this->tetrisi;
      ++this->sum;
      this->st.compscr(this->tetrisi, this->mode, this->st.scrindextetris);
      this->line += 4 + (this->bouns & ~(this->bouns >> 31));
      this->sum += 4 + (this->bouns & ~(this->bouns >> 31));
      v6 = this->line;
      if ( v6 > 999999 )
        v6 = 999999;
      this->line = v6;
      if ( this->sum == this->line + this->tetrisi )
      {
        this->st.compscr(this->line, this->mode, this->st.scrindexline);
        if ( this->mdb == 1 )
          this->st.compscr(this->line, this->mode, this->st.scrindexmdb);
        this->st.compscr(this->line - this->missline, this->mode, this->st.scrindexnomiss);
      }
      for ( k_0 = 0; k_0 <= 3; ++k_0 )
        this->addline();
      this->checkline(0);
      this->sit = 3;
      this->bouns = 4;
      this->sd.playsound(this->sd.sNew);
      this->st.addscr(this->st.scrfour, 1, this->mode);
    }
    while ( (this->level + 1) * (this->level + 1) <= this->line )
    {
      ++this->level;
      this->sd.playsound(this->sd.sWin);
    }
  }
}


// 原始位置：board.cpp:867；地址：0x00404BF2
// 调试记录声明：void setqstn(long int x, long int y, bool sb_)
// 功能说明：修改问号标记，含带坐标与不带坐标的重载。
void Board::setqstn(int x, int y, bool sb_)
{
  this->qstn[x][y] ^= 1u;
  if ( sb_ )
    this->sd.playsound(this->sd.sFlag);
}


// 原始位置：board.cpp:876；地址：0x00404C5C
// 调试记录声明：void setqstn(long int x, long int y)
// 功能说明：修改问号标记，含带坐标与不带坐标的重载。
void Board::setqstn(int x, int y)
{
  this->setqstn(x, y, 1);
}


// 原始位置：board.cpp:881；地址：0x00404C8C
// 调试记录声明：void setflag(long int x, long int y)
// 功能说明：修改旗子状态及相关统计；具体置位/撤销条件见分支。
// 原始局部变量：long int qc；bool sc；long int k；long int k。
void Board::setflag(int x, int y)
{

  signed int k_0;
  signed int k;
  bool sc;
  int qc;

  if ( this->sit > 0 && this->sit <= 3 && !this->pauseb )
  {
    qc = 0;
    sc = 0;
    for ( k = 0; k <= 7; ++k )
    {
      if ( (static_cast<Block *>(this))->isok(k, x, y, this->tx, this->ty) && this->blck[this->tx][this->ty] != 1 )
        ++qc;
    }
    if ( this->numb[x][y] == qc )
    {
      for ( k_0 = 0; k_0 <= 7; ++k_0 )
      {
        if ( (static_cast<Block *>(this))->isok(k_0, x, y, this->tx, this->ty)
          && this->blck[this->tx][this->ty] != 1
          && this->flag[this->tx][this->ty] != 1
          && this->mask[this->tx][this->ty] != 1 )
        {
          this->flag[this->tx][this->ty] = 1;
          this->qstn[this->tx][this->ty] = 0;
          sc = 1;
        }
      }
      if ( this->sb && sc )
      {
        this->sd.playsound(this->sd.sFlag);
        this->sb = 0;
      }
    }
  }
}


// 原始位置：board.cpp:920；地址：0x00404E94
// 调试记录声明：void setblock(long int x, long int y)
// 功能说明：更新格子的揭开/处理状态，并维护游戏状态和相关计数。
// 原始局部变量：long int qn；long int qq；bool sr；long int k；long int k。
void Board::setblock(int x, int y)
{

  signed int k_0;
  signed int k;
  bool sr;
  int qq;
  int qn;

  if ( this->sit > 0 && this->sit <= 3 && !this->pauseb )
  {
    qn = 0;
    qq = 0;
    sr = 0;
    for ( k = 0; k <= 7; ++k )
    {
      if ( (static_cast<Block *>(this))->isok(k, x, y, this->tx, this->ty) )
      {
        if ( this->flag[this->tx][this->ty] )
          ++qn;
        if ( this->qstn[this->tx][this->ty] )
          ++qq;
      }
    }
    if ( this->numb[x][y] == qn || qn + qq == this->numb[x][y] )
    {
      for ( k_0 = 0; k_0 <= 7; ++k_0 )
      {
        if ( (static_cast<Block *>(this))->isok(k_0, x, y, this->tx, this->ty)
          && this->blck[this->tx][this->ty] != 1
          && this->flag[this->tx][this->ty] != 1
          && this->mask[this->tx][this->ty] != 1 )
        {
          if ( this->qstn[this->tx][this->ty] == 1 )
          {
            if ( !this->mdb_ || this->tutb == 1 )
              this->qstn[this->tx][this->ty] = 0;
          }
          else
          {
            this->blck[this->tx][this->ty] = 1;
            this->qstn[this->tx][this->ty] = 0;
            sr = 1;
            this->solvebb = 1;
            this->solveb0 = 1;
            this->solveb1 = 1;
            this->solveb2 = 1;
            this->solveb3 = 1;
            this->checkerror(this->tx, this->ty);
          }
        }
      }
      if ( this->sb && sr )
      {
        this->sd.playsound(this->sd.sRight);
        this->sb = 0;
      }
    }
    if ( this->sb )
      this->checkerror();
  }
}


// 原始位置：board.cpp:981；地址：0x004051BE
// 调试记录声明：void clicknumb(long int x, long int y, bool sb_)
// 功能说明：处理数字格邻域的点击/标记规则，是各级求解器调用的基础操作。
void Board::clicknumb(int x, int y, bool sb_)
{

  this->sb = sb_;
  if ( this->sb )
    this->rightb = 1;
  this->setblock(x, y);
  if ( !this->mdb_ || this->tutb == 1 )
  {
    this->setblock(x, y);
    this->setflag(x, y);
  }
}


// 原始位置：board.cpp:996；地址：0x00405264
// 调试记录声明：void clickleft(long int x, long int y, bool sb_)
// 功能说明：处理左键操作；包含状态、坐标、标记和展开逻辑。
void Board::clickleft(int x, int y, bool sb_)
{
  this->clickleft(x, y, sb_, 3);
}


// 原始位置：board.cpp:1001；地址：0x004052A2
// 调试记录声明：void clickright(long int x, long int y, bool sb_)
// 功能说明：处理右键操作；与旗子/问号以及状态更新相关。
void Board::clickright(int x, int y, bool sb_)
{
  this->clickright(x, y, sb_, 3);
}


// 原始位置：board.cpp:1006；地址：0x004052E0
// 调试记录声明：void clickleft(long int x, long int y, bool sb_, long int md_)
// 功能说明：处理左键操作；包含状态、坐标、标记和展开逻辑。
void Board::clickleft(int x, int y, bool sb_, int md_)
{
  bool v5;

  if ( this->mask[x][y] != 1 && this->flag[x][y] != 1 )
  {
    if ( this->blck[x][y] == 1 )
    {
      if ( sb_ )
      {
        this->mdb_ = md_ == 5;
        this->clicknumb(x, y, sb_);
        this->mdb_ = 0;
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
      v5 = !this->checkerror() && sb_;
      if ( v5 )
        this->sd.playsound(this->sd.sLeft);
    }
  }
}


// 原始位置：board.cpp:1042；地址：0x00405448
// 调试记录声明：void clickright(long int x, long int y, bool sb_, long int md_)
// 功能说明：处理右键操作；与旗子/问号以及状态更新相关。
// 原始局部变量：bool qstnb；long int i；long int j。
void Board::clickright(int x, int y, bool sb_, int md_)
{

  int j;
  int i;
  bool qstnb;

  if ( this->mask[x][y] != 1 && this->flag[x][y] != 1 )
  {
    if ( this->blck[x][y] == 1 )
    {
      if ( sb_ && md_ != 5 )
        this->clicknumb(x, y, sb_);
    }
    else if ( md_ > 2 )
    {
      this->setqstn(x, y, sb_);
    }
  }
  if ( !this->sit )
  {
    qstnb = 1;
    for ( i = 0; i < this->w; ++i )
    {
      for ( j = this->maskj; j < this->h; ++j )
      {
        if ( this->qstn[i][j] != 1 )
          qstnb = 0;
      }
    }
    if ( qstnb )
      this->st.addach(this->st.achhidmark);
  }
}


// 原始位置：board.cpp:1081；地址：0x00405592
// 调试记录声明：void pause()
// 功能说明：切换暂停状态，并调整计时与界面相关状态。
void Board::pause()
{

  if ( !this->pauseb )
    this->pausetime = GetTimeR() - this->time;
  this->pauseb = this->pauseb == 0;
}

