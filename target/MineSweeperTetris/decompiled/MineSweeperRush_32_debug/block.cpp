// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00401460; symbol: __ZN5BlockC1Ev
void __cdecl Block::Block(Block *const this)
{
  Block *v1; // ecx
  Block *v2; // ST1C_4
  Block *const v3; // ST00_4

  v2 = v1;
  v1->w = 0;
  v1->h = 0;
  v1->n = 0;
  v1->sit = 0;
  v1->pauseb = 0;
  v1->maskj = 0;
  v1->maski = 0;
  v1->flag = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->qstn = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->mine = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->blck = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->mask = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->leftrule = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->rightrule = (bool (*)[128])calloc(0x80u, 0x80u);
  v2->numb = (int (*)[128])calloc(0x80u, 0x200u);
  Block::initbl(v3);
}



// 阅读说明：初始化 Block 的棋盘存储与状态；具体布局以恢复类型和函数体为准。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040159C; symbol: __ZN5Block6initblEv
void __cdecl Block::initbl(Block *const this)
{
  int *v1; // ecx
  Block *v2; // [esp+0h] [ebp-28h]
  int j; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]

  *v1 = 3;
  v1[1] = 5;
  for ( i = 0; *v1 > i; ++i )
  {
    for ( j = 0; v1[1] > j; ++j )
    {
      *(_BYTE *)(v1[11] + (i << 7) + j) = 0;
      *(_BYTE *)(v1[9] + (i << 7) + j) = 0;
      *(_BYTE *)(v1[10] + (i << 7) + j) = 0;
      *(_BYTE *)(v1[12] + (i << 7) + j) = 0;
      *(_BYTE *)(v1[13] + (i << 7) + j) = 0;
      *(_DWORD *)(v1[14] + (i << 9) + 4 * j) = 0;
    }
  }
  *(_BYTE *)v1[11] = 1;
  *(_BYTE *)(v1[11] + 1) = 1;
  *(_BYTE *)(v1[11] + 129) = 1;
  *(_BYTE *)(v1[11] + 4) = 1;
  *(_BYTE *)(v1[11] + 132) = 1;
  *(_BYTE *)(v1[12] + 256) = 1;
  *(_BYTE *)(v1[12] + 257) = 1;
  *(_BYTE *)(v1[12] + 130) = 1;
  *(_BYTE *)(v1[12] + 258) = 1;
  *(_BYTE *)(v1[12] + 131) = 1;
  *(_BYTE *)(v1[12] + 259) = 1;
  Block::calcnumb(v2);
}



// 阅读说明：遍历棋盘，清零每格的 numb，再检查 8 个相邻方向，统计 mine 为真的邻格数量。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00401714; symbol: __ZN5Block8calcnumbEv
void __cdecl Block::calcnumb(Block *const this)
{
  Block *v1; // ecx
  int *v2; // [esp+14h] [ebp-34h]
  Block *thisa; // [esp+2Ch] [ebp-1Ch]
  Block *k; // [esp+34h] [ebp-14h]
  int j; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]

  thisa = v1;
  for ( i = 0; thisa->w > i; ++i )
  {
    for ( j = 0; thisa->h > j; ++j )
    {
      thisa->numb[i][j] = 0;
      for ( k = 0; (signed int)k <= 7; k = (Block *)((char *)k + 1) )
      {
        if ( Block::isok(k, i, j, (int)&thisa->tx, &thisa->ty, v2) )
        {
          if ( thisa->mine[thisa->tx][thisa->ty] )
            ++thisa->numb[i][j];
        }
      }
    }
  }
}



// 阅读说明：按方向选择相邻坐标并检查边界；输出坐标通过引用或指针返回。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00401800; symbol: __ZN5Block4isokElllRlS0_
bool __userpurge Block::isok@<al>(_DWORD *a1@<ecx>, Block *const this, int k, int x, int y, int *const tx, int *const ty)
{
  bool result; // al

  switch ( (unsigned int)this )
  {
    case 0u:
      *(_DWORD *)y = k - 1;
      *tx = x;
      result = k > 0;
      break;
    case 1u:
      *(_DWORD *)y = k + 1;
      *tx = x;
      result = *a1 - 1 > k;
      break;
    case 2u:
      *(_DWORD *)y = k;
      *tx = x - 1;
      result = x > 0;
      break;
    case 3u:
      *(_DWORD *)y = k;
      *tx = x + 1;
      result = a1[1] - 1 > x;
      break;
    case 4u:
      *(_DWORD *)y = k - 1;
      *tx = x - 1;
      result = k > 0 && x > 0;
      break;
    case 5u:
      *(_DWORD *)y = k - 1;
      *tx = x + 1;
      result = k > 0 && a1[1] - 1 > x;
      break;
    case 6u:
      *(_DWORD *)y = k + 1;
      *tx = x - 1;
      result = *a1 - 1 > k && x > 0;
      break;
    case 7u:
      *(_DWORD *)y = k + 1;
      *tx = x + 1;
      result = *a1 - 1 > k && a1[1] - 1 > x;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


