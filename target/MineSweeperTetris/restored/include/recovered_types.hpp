#pragma once
// 依据 DWARF 恢复的数据布局和方法声明。Windows x86 ABI：long/int/指针均为 4 字节。
// 外部 Steam/GDI+ 类型仍需相应 SDK；本文件用于阅读，未作为完整编译环境验证。
#include <windows.h>
#include <cstdint>

struct Sound;
struct Window;
struct Reg;
struct Lan;
struct Board;
struct Block;
struct Steam;

// DWARF：block.h；对象大小 68 字节。
struct Block {
    static const long int maxw = 128; // 静态成员，不占用对象布局；原行 9
    static const long int maxh = 128; // 静态成员，不占用对象布局；原行 10
    long int w; // 对象内偏移 0；原头文件行 12
    long int h; // 对象内偏移 4；原头文件行 13
    long int n; // 对象内偏移 8；原头文件行 14
    long int sit; // 对象内偏移 12；原头文件行 16
    long int pauseb; // 对象内偏移 16；原头文件行 17
    long int maskj; // 对象内偏移 20；原头文件行 18
    long int maski; // 对象内偏移 24；原头文件行 19
    long int tx; // 对象内偏移 28；原头文件行 21
    long int ty; // 对象内偏移 32；原头文件行 22
    bool (*flag)[128]; // 对象内偏移 36；原头文件行 24
    bool (*qstn)[128]; // 对象内偏移 40；原头文件行 25
    bool (*mine)[128]; // 对象内偏移 44；原头文件行 26
    bool (*blck)[128]; // 对象内偏移 48；原头文件行 27
    bool (*mask)[128]; // 对象内偏移 52；原头文件行 28
    long int (*numb)[128]; // 对象内偏移 56；原头文件行 29
    bool (*leftrule)[128]; // 对象内偏移 60；原头文件行 30
    bool (*rightrule)[128]; // 对象内偏移 64；原头文件行 31
    Block();
    void initbl();
    void calcnumb();
    bool isok(long int k, long int x, long int y, long int &tx, long int &ty);
};

// DWARF：lan.h；对象大小 344 字节。
struct Lan {
    static const int maxcap = 10000; // 静态成员，不占用对象布局；原行 9
    static const int maxcapp = 1000; // 静态成员，不占用对象布局；原行 10
    const char *lanshort[30]; // 对象内偏移 0；原头文件行 12
    const long int lanshortid[30]; // 对象内偏移 120；原头文件行 13
    short int *data; // 对象内偏移 240；原头文件行 15
    short int *landata; // 对象内偏移 244；原头文件行 16
    short int **landatap; // 对象内偏移 248；原头文件行 17
    long int LAN_TITLE; // 对象内偏移 252；原头文件行 19
    long int LAN_RUNNING; // 对象内偏移 256；原头文件行 20
    long int LAN_STEAM_LAUNCH; // 对象内偏移 260；原头文件行 21
    long int LAN_STEAM_FAIL; // 对象内偏移 264；原头文件行 22
    long int LAN_STEAM_Status; // 对象内偏移 268；原头文件行 23
    long int LAN_ABOUT_NAME; // 对象内偏移 272；原头文件行 24
    long int LAN_ABOUT_VERSION; // 对象内偏移 276；原头文件行 25
    long int LAN_ABOUT_AUTHOR; // 对象内偏移 280；原头文件行 26
    long int LAN_ABOUT_LICENSE; // 对象内偏移 284；原头文件行 27
    long int LAN_ABOUT_OK; // 对象内偏移 288；原头文件行 28
    long int LAN_LOAD_STEAM; // 对象内偏移 292；原头文件行 29
    long int LAN_LOAD_AUDIO; // 对象内偏移 296；原头文件行 30
    long int LAN_LOAD_BOARD; // 对象内偏移 300；原头文件行 31
    long int LAN_LOAD_GRAPH; // 对象内偏移 304；原头文件行 32
    long int LAN_LOAD_WINDOW; // 对象内偏移 308；原头文件行 33
    long int LAN_HELP; // 对象内偏移 312；原头文件行 34
    long int LAN_SET; // 对象内偏移 316；原头文件行 35
    long int LAN_TUT_; // 对象内偏移 320；原头文件行 36
    long int LAN_TUT; // 对象内偏移 324；原头文件行 37
    long int LAN_MODE; // 对象内偏移 328；原头文件行 38
    long int LAN_TUT_QUIT; // 对象内偏移 332；原头文件行 39
    long int LAN_HELP_MENU; // 对象内偏移 336；原头文件行 40
    long int LAN_HELP_TITLE; // 对象内偏移 340；原头文件行 41
    Lan();
    const char *getsyslan();
    void initlan(const char *lan);
    __int16 *getlan(int id);
};

// DWARF：reg.h；对象大小 16 字节。
struct Reg {
    static const long int maxbuf = 16384; // 静态成员，不占用对象布局；原行 9
    HKEY regkey; // 对象内偏移 0；原头文件行 11
    HKEY regkey_; // 对象内偏移 4；原头文件行 12
    DWORD tp; // 对象内偏移 8；原头文件行 13
    DWORD cb; // 对象内偏移 12；原头文件行 14
    Reg();
    ~Reg();
    void openreg();
    void closereg();
    void setreg(HKEY key, const char *name, int value);
    void getreg(HKEY key, const char *name, int *value);
    void setreg_(HKEY key, const char *name, char *value);
    void getreg_(HKEY key, const char *name, char *value);
};

// DWARF：sound.h；对象大小 120 字节。
struct Sound {
    static const long int musici0 = -256; // 静态成员，不占用对象布局；原行 9
    static const long int maxsound = 8; // 静态成员，不占用对象布局；原行 10
    long unsigned int sSound[8]; // 对象内偏移 0；原头文件行 11
    long unsigned int *sMusic; // 对象内偏移 32；原头文件行 12
    const char *sSounds[8]; // 对象内偏移 36；原头文件行 14
    long int sWin; // 对象内偏移 68；原头文件行 16
    long int sLose; // 对象内偏移 72；原头文件行 17
    long int sError; // 对象内偏移 76；原头文件行 18
    long int sLeft; // 对象内偏移 80；原头文件行 19
    long int sRight; // 对象内偏移 84；原头文件行 20
    long int sFlag; // 对象内偏移 88；原头文件行 21
    long int sNew; // 对象内偏移 92；原头文件行 22
    long int sSolve; // 对象内偏移 96；原头文件行 23
    long int nummusic; // 对象内偏移 100；原头文件行 25
    bool soundb; // 对象内偏移 104；原头文件行 26
    bool musicb; // 对象内偏移 105；原头文件行 27
    long int musici; // 对象内偏移 108；原头文件行 28
    double musictime; // 对象内偏移 112；原头文件行 29
    Sound();
    void initsound();
    void loadsound();
    void loadmusic();
    void playsound(int id);
    void switchsound();
    void playmusic();
    void checkmusic();
    void switchmusic();
};

// DWARF：steam.h；对象大小 1912 字节。
struct Steam {
    Lan lan; // 对象内偏移 0；原头文件行 11
    const long unsigned int appid; // 对象内偏移 344；原头文件行 13
    bool steamb; // 对象内偏移 348；原头文件行 14
    bool cheatb; // 对象内偏移 349；原头文件行 15
    static const long int achn = 26; // 静态成员，不占用对象布局；原行 17
    long int achgenstart; // 对象内偏移 352；原头文件行 18
    long int achgencustom; // 对象内偏移 356；原头文件行 19
    long int achgenmode; // 对象内偏移 360；原头文件行 20
    long int achgenpause; // 对象内偏移 364；原头文件行 21
    long int achgenhelp; // 对象内偏移 368；原头文件行 22
    long int achhidcheat; // 对象内偏移 372；原头文件行 23
    long int achhidedge; // 对象内偏移 376；原头文件行 24
    long int achhidmark; // 对象内偏移 380；原头文件行 25
    long int achhidright; // 对象内偏移 384；原头文件行 26
    long int achhidalive; // 对象内偏移 388；原头文件行 27
    long int achcumdead1; // 对象内偏移 392；原头文件行 28
    long int achcumdead10; // 对象内偏移 396；原头文件行 29
    long int achcumdead100; // 对象内偏移 400；原头文件行 30
    long int achcumdead1000; // 对象内偏移 404；原头文件行 31
    long int achcumfour1; // 对象内偏移 408；原头文件行 32
    long int achcumfour10; // 对象内偏移 412；原头文件行 33
    long int achcumfour100; // 对象内偏移 416；原头文件行 34
    long int achcumfour1000; // 对象内偏移 420；原头文件行 35
    long int achcumline100; // 对象内偏移 424；原头文件行 36
    long int achcumline300; // 对象内偏移 428；原头文件行 37
    long int achcumline600; // 对象内偏移 432；原头文件行 38
    long int achcumline1000; // 对象内偏移 436；原头文件行 39
    long int achcumtotal10; // 对象内偏移 440；原头文件行 40
    long int achcumtotal100; // 对象内偏移 444；原头文件行 41
    long int achcumtotal1000; // 对象内偏移 448；原头文件行 42
    long int achcumtotal10000; // 对象内偏移 452；原头文件行 43
    const char *achs[26]; // 对象内偏移 456；原头文件行 52
    bool achb[26]; // 对象内偏移 560；原头文件行 53
    static const long int scrn = 19; // 静态成员，不占用对象布局；原行 55
    long int scrdead; // 对象内偏移 588；原头文件行 56
    long int scrfour; // 对象内偏移 592；原头文件行 57
    long int scrtotal; // 对象内偏移 596；原头文件行 58
    long int scrline; // 对象内偏移 600；原头文件行 59
    long int scrline1; // 对象内偏移 604；原头文件行 60
    long int scrline2; // 对象内偏移 608；原头文件行 61
    long int scrline3; // 对象内偏移 612；原头文件行 62
    long int scrindexline; // 对象内偏移 616；原头文件行 63
    long int scrindexmdb; // 对象内偏移 620；原头文件行 64
    long int scrindexnomiss; // 对象内偏移 624；原头文件行 65
    long int scrindextetris; // 对象内偏移 628；原头文件行 66
    long int scrindexmiss; // 对象内偏移 632；原头文件行 67
    const char *scrs[19]; // 对象内偏移 636；原头文件行 76
    long int scr[19]; // 对象内偏移 712；原头文件行 77
    bool newrecord; // 对象内偏移 788；原头文件行 78
    static const long int leadn = 15; // 静态成员，不占用对象布局；原行 80
    const char *leads[15]; // 对象内偏移 792；原头文件行 88
    long int leadk_[3]; // 对象内偏移 852；原头文件行 89
    SteamAPICall_t lead[15]; // 对象内偏移 864；原头文件行 90
    SteamAPICall_t lead_[3][15]; // 对象内偏移 984；原头文件行 91
    LeaderboardFindResult_t leadr; // 对象内偏移 1344；原头文件行 92
    LeaderboardScoreUploaded_t leadu; // 对象内偏移 1360；原头文件行 93
    LeaderboardScoresDownloaded_t leadd; // 对象内偏移 1392；原头文件行 94
    SteamLeaderboard_t leadb[15]; // 对象内偏移 1416；原头文件行 95
    SteamLeaderboardEntries_t leaden[3][15]; // 对象内偏移 1536；原头文件行 96
    bool leadfailed; // 对象内偏移 1896；原头文件行 97
    LeaderboardEntry_t (*leadsn)[15][20]; // 对象内偏移 1900；原头文件行 99
    double waittime; // 对象内偏移 1904；原头文件行 100
    Steam();
    ~Steam();
    void initsteam();
    void loadlan();
    void exitsteam();
    void loadsteam();
    void resetach();
    void loadach();
    void addach(int achid);
    void checkach(int scrid, int d, int c, int b, int a, int a_d, int a_c, int a_b, int a_a);
    void loadscr();
    void setscr(int scrid);
    void addscr(int scrid, int val, int mode);
    void maxscr(int val, int scrline__);
    void compscr(int val, int mode, int index);
    void resetscr();
    void loadlead();
    void getlead();
    void setlead();
    void setlead(int mode);
    bool waitlead();
    bool waitlead_();
    void savescr(char *scrpath);
    bool ischeat(int line, int tetris);
    bool ischeat();
    void checkcheat();
};

// DWARF：board.h；对象大小 2536 字节。
struct Board : public Block {
    // DWARF：board.h；对象大小 80 字节。
    struct rule {
        long int x; // 对象内偏移 0；原头文件行 70
        long int y; // 对象内偏移 4；原头文件行 71
        long int numbc; // 对象内偏移 8；原头文件行 72
        long int blckc; // 对象内偏移 12；原头文件行 73
        long int blckx[8]; // 对象内偏移 16；原头文件行 74
        long int blcky[8]; // 对象内偏移 48；原头文件行 75
    };
    Steam st; // 对象内偏移 72；原头文件行 11
    Sound sd; // 对象内偏移 1984；原头文件行 12
    double time; // 对象内偏移 2104；原头文件行 14
    double time_; // 对象内偏移 2112；原头文件行 15
    double pausetime; // 对象内偏移 2120；原头文件行 16
    long int mode; // 对象内偏移 2128；原头文件行 17
    long int mode_; // 对象内偏移 2132；原头文件行 18
    bool sb; // 对象内偏移 2136；原头文件行 19
    long int rightb; // 对象内偏移 2140；原头文件行 20
    bool aliveb; // 对象内偏移 2144；原头文件行 21
    long int maskj0; // 对象内偏移 2148；原头文件行 23
    bool maskjb; // 对象内偏移 2152；原头文件行 24
    long int line; // 对象内偏移 2156；原头文件行 25
    long int level; // 对象内偏移 2160；原头文件行 26
    bool solvebb; // 对象内偏移 2164；原头文件行 27
    bool solveb0; // 对象内偏移 2165；原头文件行 28
    bool solveb1; // 对象内偏移 2166；原头文件行 29
    bool solveb2; // 对象内偏移 2167；原头文件行 30
    bool solveb3; // 对象内偏移 2168；原头文件行 31
    long int checkr; // 对象内偏移 2172；原头文件行 32
    bool dieb; // 对象内偏移 2176；原头文件行 33
    long int diex; // 对象内偏移 2180；原头文件行 34
    long int diey; // 对象内偏移 2184；原头文件行 35
    long int tetrisi; // 对象内偏移 2188；原头文件行 36
    long int missi; // 对象内偏移 2192；原头文件行 37
    long int missline; // 对象内偏移 2196；原头文件行 38
    long int bouns; // 对象内偏移 2200；原头文件行 39
    long int sum; // 对象内偏移 2204；原头文件行 40
    long int rx; // 对象内偏移 2208；原头文件行 42
    long int ry; // 对象内偏移 2212；原头文件行 43
    long int maxbdw; // 对象内偏移 2216；原头文件行 45
    long int maxbdh; // 对象内偏移 2220；原头文件行 46
    long int w_; // 对象内偏移 2224；原头文件行 48
    long int h_; // 对象内偏移 2228；原头文件行 49
    long int cred; // 对象内偏移 2232；原头文件行 50
    double mult; // 对象内偏移 2240；原头文件行 51
    long int delayb; // 对象内偏移 2248；原头文件行 52
    long int delayb__; // 对象内偏移 2252；原头文件行 53
    long int mdb; // 对象内偏移 2256；原头文件行 54
    long int mdb_; // 对象内偏移 2260；原头文件行 55
    long int mx; // 对象内偏移 2264；原头文件行 57
    long int my; // 对象内偏移 2268；原头文件行 58
    long int tutb; // 对象内偏移 2272；原头文件行 60
    long int tuti; // 对象内偏移 2276；原头文件行 61
    long int tutx[13]; // 对象内偏移 2280；原头文件行 62
    long int tuty[13]; // 对象内偏移 2332；原头文件行 63
    long int tutm[13]; // 对象内偏移 2384；原头文件行 64
    bool relaxb; // 对象内偏移 2436；原头文件行 66
    rule ruletemp; // 对象内偏移 2440；原头文件行 77
    rule *rulemain; // 对象内偏移 2520；原头文件行 78
    long int rulemainc; // 对象内偏移 2524；原头文件行 79
    long int (*blckrule)[128]; // 对象内偏移 2528；原头文件行 80
    long int solven; // 对象内偏移 2532；原头文件行 81
    Board();
    void initbd();
    void initbd(int w_, int h_, int maskj_, int n_);
    void initbd(int mode_, int md_);
    void randmine(int x, int y);
    void tutmine();
    void resetbd(int x, int y);
    void solveblank();
    void solveblank_();
    void solve0();
    void solve0_();
    void solve1();
    void solve1_();
    void createrule();
    void comparerule(int rule1c, int rule2c);
    void comparerule();
    void applyrule(bool applyb);
    void solve2(bool applyb);
    void solve2();
    void solve2_(bool applyb);
    void solve2_();
    void solve3_();
    bool checkerror(int i, int j);
    bool checkerror();
    void checkline(bool delayb_);
    void addline(bool misslineb);
    void addline();
    bool addmask();
    void checkdie();
    void delline(int l);
    void setqstn(int x, int y, bool sb_);
    void setqstn(int x, int y);
    void setflag(int x, int y);
    void setblock(int x, int y);
    void clicknumb(int x, int y, bool sb_);
    void clickleft(int x, int y, bool sb_);
    void clickright(int x, int y, bool sb_);
    void clickleft(int x, int y, bool sb_, int md_);
    void clickright(int x, int y, bool sb_, int md_);
    void pause();
};

// DWARF：window.h；对象大小 3584 字节。
struct Window {
    const long int launchw; // 对象内偏移 0；原头文件行 12
    const long int launchh; // 对象内偏移 4；原头文件行 13
    const long int titlew; // 对象内偏移 8；原头文件行 14
    const long int titleh; // 对象内偏移 12；原头文件行 15
    const long int menuw; // 对象内偏移 16；原头文件行 16
    const long int menuh; // 对象内偏移 20；原头文件行 17
    const long int facew; // 对象内偏移 24；原头文件行 18
    const long int faceh; // 对象内偏移 28；原头文件行 19
    const long int iconw; // 对象内偏移 32；原头文件行 20
    const long int iconh; // 对象内偏移 36；原头文件行 21
    const long int digtw[3]; // 对象内偏移 40；原头文件行 22
    const long int digth[3]; // 对象内偏移 52；原头文件行 23
    const long int okw; // 对象内偏移 64；原头文件行 24
    const long int okh; // 对象内偏移 68；原头文件行 25
    const long int btnw; // 对象内偏移 72；原头文件行 26
    const long int btnh; // 对象内偏移 76；原头文件行 27
    const long int tutw; // 对象内偏移 80；原头文件行 28
    const long int tuth; // 对象内偏移 84；原头文件行 29
    const long int aboutw; // 对象内偏移 88；原头文件行 30
    const long int abouth; // 对象内偏移 92；原头文件行 31
    const long int helpw; // 对象内偏移 96；原头文件行 32
    const long int helph; // 对象内偏移 100；原头文件行 33
    const long int fontth; // 对象内偏移 104；原头文件行 34
    const long int fontfh; // 对象内偏移 108；原头文件行 35
    const long int fonth; // 对象内偏移 112；原头文件行 36
    const long int fontsh; // 对象内偏移 116；原头文件行 37
    const long int fontmh; // 对象内偏移 120；原头文件行 38
    const long int okh_; // 对象内偏移 124；原头文件行 39
    const long int cursorw; // 对象内偏移 128；原头文件行 40
    const long int cursorh; // 对象内偏移 132；原头文件行 41
    const long int clickw; // 对象内偏移 136；原头文件行 42
    const long int clickh; // 对象内偏移 140；原头文件行 43
    const long int arroww; // 对象内偏移 144；原头文件行 44
    const long int arrowh; // 对象内偏移 148；原头文件行 45
    pbitmap ptitle_; // 对象内偏移 152；原头文件行 47
    pbitmap pbg_; // 对象内偏移 156；原头文件行 48
    pbitmap pmenu_; // 对象内偏移 160；原头文件行 49
    pbitmap pmenu1[2]; // 对象内偏移 164；原头文件行 50
    pbitmap pmenu2[2]; // 对象内偏移 172；原头文件行 51
    pbitmap pmenu3[2]; // 对象内偏移 180；原头文件行 52
    pbitmap pmenuq[2]; // 对象内偏移 188；原头文件行 53
    pbitmap pmenua[2]; // 对象内偏移 196；原头文件行 54
    pbitmap pmenus[2]; // 对象内偏移 204；原头文件行 55
    pbitmap pmenum[2]; // 对象内偏移 212；原头文件行 56
    pbitmap pmenut[2]; // 对象内偏移 220；原头文件行 57
    pbitmap pmenud[2]; // 对象内偏移 228；原头文件行 58
    pbitmap pmenun[2]; // 对象内偏移 236；原头文件行 59
    pbitmap pmenug[7][2]; // 对象内偏移 244；原头文件行 60
    pbitmap pface_; // 对象内偏移 300；原头文件行 61
    pbitmap pface[9]; // 对象内偏移 304；原头文件行 62
    pbitmap picon_; // 对象内偏移 340；原头文件行 63
    pbitmap picon[11]; // 对象内偏移 344；原头文件行 64
    pbitmap piconc; // 对象内偏移 388；原头文件行 65
    pbitmap piconq; // 对象内偏移 392；原头文件行 66
    pbitmap piconf; // 对象内偏移 396；原头文件行 67
    pbitmap piconm; // 对象内偏移 400；原头文件行 68
    pbitmap picone; // 对象内偏移 404；原头文件行 69
    pbitmap piconn; // 对象内偏移 408；原头文件行 70
    pbitmap piconp; // 对象内偏移 412；原头文件行 71
    pbitmap picona; // 对象内偏移 416；原头文件行 72
    pbitmap piconu; // 对象内偏移 420；原头文件行 73
    pbitmap pdigt_[3]; // 对象内偏移 424；原头文件行 74
    pbitmap pdigt[10][3]; // 对象内偏移 436；原头文件行 75
    pbitmap pdigtmin[3]; // 对象内偏移 556；原头文件行 76
    pbitmap pdigtnul[3]; // 对象内偏移 568；原头文件行 77
    pbitmap pok_; // 对象内偏移 580；原头文件行 78
    pbitmap pok; // 对象内偏移 584；原头文件行 79
    pbitmap pbtn; // 对象内偏移 588；原头文件行 80
    pbitmap pcursor_; // 对象内偏移 592；原头文件行 81
    pbitmap pcursor; // 对象内偏移 596；原头文件行 82
    pbitmap pclick_; // 对象内偏移 600；原头文件行 83
    pbitmap pclickl; // 对象内偏移 604；原头文件行 84
    pbitmap pclickr; // 对象内偏移 608；原头文件行 85
    pbitmap pclickn; // 对象内偏移 612；原头文件行 86
    pbitmap pclicka; // 对象内偏移 616；原头文件行 87
    pbitmap parrow_; // 对象内偏移 620；原头文件行 88
    pbitmap parrowl; // 对象内偏移 624；原头文件行 89
    pbitmap parrowr; // 对象内偏移 628；原头文件行 90
    pbitmap parrowu; // 对象内偏移 632；原头文件行 91
    pbitmap parrowd; // 对象内偏移 636；原头文件行 92
    pbitmap parrowm; // 对象内偏移 640；原头文件行 93
    pbitmap parrowp; // 对象内偏移 644；原头文件行 94
    const long int transparent; // 对象内偏移 648；原头文件行 96
    long int color[9]; // 对象内偏移 652；原头文件行 98
    long int colori; // 对象内偏移 688；原头文件行 99
    long int cfg; // 对象内偏移 692；原头文件行 100
    long int cbg; // 对象内偏移 696；原头文件行 101
    long int ctfg; // 对象内偏移 700；原头文件行 102
    long int ctbg; // 对象内偏移 704；原头文件行 103
    long int cred; // 对象内偏移 708；原头文件行 104
    long int cblue; // 对象内偏移 712；原头文件行 105
    long int cgreen; // 对象内偏移 716；原头文件行 106
    long int cline; // 对象内偏移 720；原头文件行 107
    long int cmine; // 对象内偏移 724；原头文件行 108
    long int transparent_; // 对象内偏移 728；原头文件行 109
    bool isbmp; // 对象内偏移 732；原头文件行 111
    Reg reg; // 对象内偏移 736；原头文件行 113
    HICON hicon_res; // 对象内偏移 752；原头文件行 114
    HICON hicon_file; // 对象内偏移 756；原头文件行 115
    HICON hicon; // 对象内偏移 760；原头文件行 116
    Board bd; // 对象内偏移 768；原头文件行 117
    Block bl; // 对象内偏移 3304；原头文件行 118
    const long int maxhelp; // 对象内偏移 3372；原头文件行 119
    long int helpi; // 对象内偏移 3376；原头文件行 120
    bool helpb; // 对象内偏移 3380；原头文件行 121
    bool cheatb; // 对象内偏移 3381；原头文件行 122
    bool waitb; // 对象内偏移 3382；原头文件行 123
    pbitmap pwin; // 对象内偏移 3384；原头文件行 124
    pbitmap pwint; // 对象内偏移 3388；原头文件行 125
    const long int minh; // 对象内偏移 3392；原头文件行 126
    const long int minw; // 对象内偏移 3396；原头文件行 127
    long int mult_; // 对象内偏移 3400；原头文件行 128
    double mult; // 对象内偏移 3408；原头文件行 129
    WINDOWPLACEMENT wn; // 对象内偏移 3416；原头文件行 130
    bool showmax; // 对象内偏移 3460；原头文件行 131
    bool showmax_; // 对象内偏移 3461；原头文件行 132
    long int w_; // 对象内偏移 3464；原头文件行 133
    long int h_; // 对象内偏移 3468；原头文件行 134
    long int x_; // 对象内偏移 3472；原头文件行 135
    long int y_; // 对象内偏移 3476；原头文件行 136
    RECT rect; // 对象内偏移 3480；原头文件行 137
    long int xscr; // 对象内偏移 3496；原头文件行 138
    long int yscr; // 对象内偏移 3500；原头文件行 139
    long int wscr; // 对象内偏移 3504；原头文件行 140
    long int hscr; // 对象内偏移 3508；原头文件行 141
    bool barb; // 对象内偏移 3512；原头文件行 142
    long int md; // 对象内偏移 3516；原头文件行 143
    bool ml; // 对象内偏移 3520；原头文件行 144
    bool mr; // 对象内偏移 3521；原头文件行 145
    long int mx; // 对象内偏移 3524；原头文件行 146
    long int my; // 对象内偏移 3528；原头文件行 147
    bool mi; // 对象内偏移 3532；原头文件行 148
    long int lead_5; // 对象内偏移 3536；原头文件行 149
    bool singleb; // 对象内偏移 3540；原头文件行 150
    long int boardb; // 对象内偏移 3544；原头文件行 151
    double timerefresh; // 对象内偏移 3552；原头文件行 152
    CRITICAL_SECTION cs; // 对象内偏移 3560；原头文件行 154
    Window();
    ~Window();
    void loadsettingcloud();
    void savesettingcloud();
    void loadsetting();
    void savesetting();
    void loadboardcloud();
    void saveboardcloud();
    void loadboard();
    void saveboard();
    void loadallpaint();
    void loadall();
    void initmult();
    void loadicon();
    void initwindow();
    void releasewindow();
    void initwindow(bool b);
    void initcolor();
    void initbmp();
    void paintmenu();
    void paintface();
    void paintnumber(int n, int l, int x, int y, int w, int h, int b);
    void paintnumber(int n, int l, int x, int y, int b);
    void paintnumber(int n, int l, int x, int y);
    void paintlevel();
    void paintblock(Block *const b, int i, int j, int x, int y, int w, int h);
    void paintboard(Block *const b, int x, int y);
    void paintboard(Block *const b, int x, int y, int cx_0, int cy);
    void paintboard();
    void paintline(pbitmap p, int n, int x, int y);
    void paintline(pbitmap pa, pbitmap pb, int a, int b, int x, int y);
    void paintline(pbitmap pa, pbitmap pb, pbitmap pc, int a, int b, int c, int x, int y);
    void paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, int a, int b, int c, int d, int x, int y);
    void paintline(pbitmap pa, pbitmap pb, pbitmap pc, pbitmap pd, pbitmap pe, int a, int b, int c, int d, int e, int x, int y);
    void painthelp();
    void painttut();
    void painttitle(int load);
    void paintevent(bool freshb);
    void paintevent();
    void paintrefresh();
    bool isin(int ex, int ey, int x, int y, int w, int h);
    void sethelp(int helpi_);
    void savescr();
    void switchskin();
    void switchskin(int colori_);
    void switchmd();
    void switchmd(int md_);
    void tutevent(int ex, int ey, bool tutkb);
    void mouseeventboard_(int x, int y, int eb_, int md_);
    void mouseeventboard(int ex_, int ey_, int eb_, int md_);
    void mouseevent(int ex_, int ey_, int eb_);
    void keyevent(int key);
    void doaction();
    void setfontname_(const char *s);
    void setfontheight_(unsigned int h);
    void setfontweight_(unsigned int wg);
    void drawtextxy_(pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg, unsigned int format);
    void drawtextxy_(pbitmap b, const __int16 *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg);
    void drawtextxy_(pbitmap b, const char *s, int x, int y, unsigned int w, unsigned int h, unsigned int cfg, unsigned int cbg);
    void drawtextxy_(pbitmap b, const char *s, int x, int y, unsigned int cfg, unsigned int cbg);
    unsigned int getstringwidth_(const char *s);
};