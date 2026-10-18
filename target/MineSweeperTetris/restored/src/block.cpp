// 基础棋盘：四个方法均依据所选 Debug EXE 的函数体和类型布局人工整理。
// bool 矩阵按 [列][行] 访问，容量为 128×128；保留原分配、赋值和循环行为。
#include "../include/recovered_types.hpp"
#include <cstdlib>

// 原始 block.cpp:3 / 0x00401460。
Block::Block()
{
    w = h = n = sit = pauseb = maskj = maski = 0;
    flag      = static_cast<decltype(flag)>(std::calloc(maxw, sizeof(*flag)));
    qstn      = static_cast<decltype(qstn)>(std::calloc(maxw, sizeof(*qstn)));
    mine      = static_cast<decltype(mine)>(std::calloc(maxw, sizeof(*mine)));
    blck      = static_cast<decltype(blck)>(std::calloc(maxw, sizeof(*blck)));
    mask      = static_cast<decltype(mask)>(std::calloc(maxw, sizeof(*mask)));
    leftrule  = static_cast<decltype(leftrule)>(std::calloc(maxw, sizeof(*leftrule)));
    rightrule = static_cast<decltype(rightrule)>(std::calloc(maxw, sizeof(*rightrule)));
    numb      = static_cast<decltype(numb)>(std::calloc(maxw, sizeof(*numb)));
    // 原程序未检查分配失败，也没有在这里初始化 tx/ty；没有额外引入新的行为。
    initbl();
}

// 原始 block.cpp:16 / 0x0040159C。构造一个 3×5 的初始示例棋盘。
void Block::initbl()
{
    w = 3;
    h = 5;
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            mine[x][y] = flag[x][y] = qstn[x][y] = false;
            blck[x][y] = mask[x][y] = false;
            numb[x][y] = 0;
        }
    }
    // 从原导出的线性偏移还原为二维坐标：偏移 = x*128 + y。
    mine[0][0] = true;
    mine[0][1] = true;
    mine[1][1] = true;
    mine[0][4] = true;
    mine[1][4] = true;
    blck[2][0] = true;
    blck[2][1] = true;
    blck[1][2] = true;
    blck[2][2] = true;
    blck[1][3] = true;
    blck[2][3] = true;
    calcnumb();
}

// 原始 block.cpp:46 / 0x00401714。每格数字等于八邻域中雷的数量。
void Block::calcnumb()
{
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            numb[x][y] = 0;
            for (int direction = 0; direction < 8; ++direction) {
                if (isok(direction, x, y, tx, ty) && mine[tx][ty]) {
                    ++numb[x][y];
                }
            }
        }
    }
}

// 原始 block.cpp:67 / 0x00401800。
// long& 输出参数同时由 DWARF 与符号名 ...RlS0_ 确认；恢复引用语法。
bool Block::isok(long direction, long x, long y, long& neighborX, long& neighborY)
{
    switch (direction) {
    case 0: neighborX = x-1; neighborY = y;   return x > 0;
    case 1: neighborX = x+1; neighborY = y;   return x < w-1;
    case 2: neighborX = x;   neighborY = y-1; return y > 0;
    case 3: neighborX = x;   neighborY = y+1; return y < h-1;
    case 4: neighborX = x-1; neighborY = y-1; return x > 0 && y > 0;
    case 5: neighborX = x-1; neighborY = y+1; return x > 0 && y < h-1;
    case 6: neighborX = x+1; neighborY = y-1; return x < w-1 && y > 0;
    case 7: neighborX = x+1; neighborY = y+1; return x < w-1 && y < h-1;
    default: return false;
    }
}
