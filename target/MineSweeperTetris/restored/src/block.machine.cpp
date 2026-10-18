// 基础棋盘矩阵、八邻域与邻雷统计
// 基于所选 Debug EXE 的静态反编译，按 DWARF 源文件归属恢复。
// 这是供阅读的源码式伪代码；并非已验证可编译的源码。
#include "../include/recovered_types.hpp"

// 原始位置：block.cpp:3；地址：0x00401460
// 调试记录声明：void Block()
// 功能说明：构造函数：初始化成员及所拥有的子对象。
Block::Block()
{

  this->w = 0;
  this->h = 0;
  this->n = 0;
  this->sit = 0;
  this->pauseb = 0;
  this->maskj = 0;
  this->maski = 0;
  this->flag = (bool (*)[128])calloc(0x80u, 0x80u);
  this->qstn = (bool (*)[128])calloc(0x80u, 0x80u);
  this->mine = (bool (*)[128])calloc(0x80u, 0x80u);
  this->blck = (bool (*)[128])calloc(0x80u, 0x80u);
  this->mask = (bool (*)[128])calloc(0x80u, 0x80u);
  this->leftrule = (bool (*)[128])calloc(0x80u, 0x80u);
  this->rightrule = (bool (*)[128])calloc(0x80u, 0x80u);
  this->numb = (int (*)[128])calloc(0x80u, 0x200u);
  this->initbl();
}


// 原始位置：block.cpp:16；地址：0x0040159C
// 调试记录声明：void initbl()
// 功能说明：初始化基础棋盘成员和各矩阵缓冲区。数组每列容量由恢复类型确定为 128。
// 原始局部变量：long int i；long int j。
void Block::initbl()
{
  int j;
  int i;

  this->w = 3;
  this->h = 5;
  for ( i = 0; i < this->w; ++i )
  {
    for ( j = 0; j < this->h; ++j )
    {
      this->mine[i][j] = 0;
      this->flag[i][j] = 0;
      this->qstn[i][j] = 0;
      this->blck[i][j] = 0;
      this->mask[i][j] = 0;
      this->numb[i][j] = 0;
    }
  }
  this->mine[0][0] = 1;
  this->mine[0][1] = 1;
  this->mine[1][1] = 1;
  this->mine[0][4] = 1;
  this->mine[1][4] = 1;
  this->blck[2][0] = 1;
  this->blck[2][1] = 1;
  this->blck[1][2] = 1;
  this->blck[2][2] = 1;
  this->blck[1][3] = 1;
  this->blck[2][3] = 1;
  this->calcnumb();
}


// 原始位置：block.cpp:46；地址：0x00401714
// 调试记录声明：void calcnumb()
// 功能说明：逐格清零 numb，并按 8 个相邻方向统计雷数。i/j 是列/行，k 是方向。
// 原始局部变量：long int i；long int j；long int k。
void Block::calcnumb()
{

  signed int k;
  int j;
  int i;

  for ( i = 0; i < this->w; ++i )
  {
    for ( j = 0; j < this->h; ++j )
    {
      this->numb[i][j] = 0;
      for ( k = 0; k <= 7; ++k )
      {
        if ( this->isok(k, i, j, this->tx, this->ty) )
        {
          if ( this->mine[this->tx][this->ty] )
            ++this->numb[i][j];
        }
      }
    }
  }
}


// 原始位置：block.cpp:67；地址：0x00401800
// 调试记录声明：bool isok(long int k, long int x, long int y, long int &tx, long int &ty)
// 功能说明：按方向 k 输出相邻坐标；根据 w/h 检查是否越界。返回值表示该邻格有效。
bool Block::isok(long int k, long int x, long int y, long int &tx, long int &ty)
{
  bool result;

  switch ( k )
  {
    case 0:
      tx = x - 1;
      ty = y;
      result = x > 0;
      break;
    case 1:
      tx = x + 1;
      ty = y;
      result = this->w - 1 > x;
      break;
    case 2:
      tx = x;
      ty = y - 1;
      result = y > 0;
      break;
    case 3:
      tx = x;
      ty = y + 1;
      result = this->h - 1 > y;
      break;
    case 4:
      tx = x - 1;
      ty = y - 1;
      result = x > 0 && y > 0;
      break;
    case 5:
      tx = x - 1;
      ty = y + 1;
      result = x > 0 && this->h - 1 > y;
      break;
    case 6:
      tx = x + 1;
      ty = y - 1;
      result = this->w - 1 > x && y > 0;
      break;
    case 7:
      tx = x + 1;
      ty = y + 1;
      result = this->w - 1 > x && this->h - 1 > y;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

