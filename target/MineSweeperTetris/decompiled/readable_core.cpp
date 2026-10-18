// 扫雷核心逻辑的人工整理版，供阅读，不是可独立编译的完整游戏。
// 对照来源：MineSweeperRush_32_debug2.cpp 的三个函数体：
//   Block::isok      0x00401800
//   Block::calcnumb  0x00401714
//   Board::solveblank 0x004027A2
// 方法名、循环和分支来自静态反编译。把错位的 this/参数和临时名整理为
// 正常 C++ 表达式属于人工推断；尚未通过原程序执行对照验证。
// Block/Board 的字段定义可在 MineSweeperRush_32_debug2.types.h 中查阅。

// 计算一个相邻格的坐标，返回该格是否在棋盘范围内。
// 原程序使用 8 个方向编号；保留相同顺序，避免改变其他调用的意义。
bool Block::isok(int direction, int x, int y, int& neighborX, int& neighborY)
{
    switch (direction) {
    case 0: neighborX = x - 1; neighborY = y;     return x > 0;
    case 1: neighborX = x + 1; neighborY = y;     return x < w - 1;
    case 2: neighborX = x;     neighborY = y - 1; return y > 0;
    case 3: neighborX = x;     neighborY = y + 1; return y < h - 1;
    case 4: neighborX = x - 1; neighborY = y - 1; return x > 0 && y > 0;
    case 5: neighborX = x - 1; neighborY = y + 1; return x > 0 && y < h - 1;
    case 6: neighborX = x + 1; neighborY = y - 1; return x < w - 1 && y > 0;
    case 7: neighborX = x + 1; neighborY = y + 1; return x < w - 1 && y < h - 1;
    default: return false;
    }
}

// 为每格重新计算八邻域中的雷数。
// 原码用成员 tx、ty 暂存邻格坐标；这里保留这一副作用。
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

// 展开未揭开的零数字格；这段代码可直接读取 mine 数组，并非只依靠玩家可见信息。
// 两次相反方向扫描有助于处理本轮点击产生的新展开；不额外推断其收敛保证。
void Board::solveblank()
{
    solvebb = false;
    if (sit <= 0 || sit > 3 || pauseb) return;

    // 保留原程序从 y=2 开始的规则。前两行的具体游戏含义未确认。
    for (int x = 0; x < w; ++x) {
        for (int y = 2; y < h; ++y) {
            if (mask[x][y] != 1 && mine[x][y] != 1 && numb[x][y] == 0) {
                // 原导出显示参数错位；参数形式按成员方法及零常量整理。
                clickleft(x, y, false);
            }
        }
    }
    for (int x = w - 1; x >= 0; --x) {
        for (int y = h - 1; y > 1; --y) {
            if (mask[x][y] != 1 && mine[x][y] != 1 && numb[x][y] == 0) {
                clickleft(x, y, false);
            }
        }
    }
}
