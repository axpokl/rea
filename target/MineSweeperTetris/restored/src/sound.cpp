// 音效和音乐管理
// 基于所选 Debug EXE 的静态反编译，按 DWARF 源文件归属恢复。
// 这是供阅读的源码式伪代码；并非已验证可编译的源码。
#include "../include/recovered_types.hpp"

// 原始位置：sound.cpp:4；地址：0x0040A048
// 调试记录声明：void Sound()
// 功能说明：构造函数：初始化成员及所拥有的子对象。
Sound::Sound()
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


// 原始位置：sound.cpp:8；地址：0x0040A120
// 调试记录声明：void initsound()
// 功能说明：保留恢复的函数名、分支和调用；具体逻辑见函数体。
void Sound::initsound()
{

  this->loadsound();
  this->loadmusic();
  this->playmusic();
  painttitles = 0;
}


// 原始位置：sound.cpp:16；地址：0x0040A154
// 调试记录声明：void loadsound()
// 功能说明：加载音效资源。
// 原始局部变量：char sPath[260]；long int id。
void Sound::loadsound()
{
  unsigned int v1;

  char sPath[260];
  int id;

  if ( (unsigned __int8)IsWin() )
  {
    for ( id = 0; id <= 7; ++id )
    {
      sprintf(sPath, "./data/wav/%s.wav", this->sSounds[id]);
      v1 = LoadAudio(sPath, &s2);
      this->sSound[id] = v1;
    }
  }
}


// 原始位置：sound.cpp:29；地址：0x0040A1D0
// 调试记录声明：void loadmusic()
// 功能说明：加载背景音乐资源。
// 可见操作：调用 MCI 音频接口。
// 原始局部变量：MCIERROR ret；char sPath[260]；long int k；long unsigned int *sMusic_。
void Sound::loadmusic()
{
  unsigned int *v1;

  char sPath[260];
  unsigned int *sMusic_;
  MCIERROR ret;
  int k;

  ret = mciSendStringA("open new type sequencer alias miditest", 0, 0, 0);
  mciSendStringA("close miditest", 0, 0, 0);
  if ( ret )
  {
    this->nummusic = 0;
    for ( k = 0; (unsigned __int8)IsWin(); ++k )
    {
      sprintf(sPath, "./data/mid/music%ld.mid", k + 1);
      if ( !IsFile(sPath) )
        break;
      sMusic_ = (unsigned int *)realloc(this->sMusic, 4 * (this->nummusic + 1));
      if ( !sMusic_ )
        break;
      this->sMusic = sMusic_;
      painttitles = (pbitmap)sPath;
      painttitleb = 2;
      v1 = &this->sMusic[this->nummusic];
      *v1 = LoadAudio(sPath, " type sequencer");
      ++this->nummusic;
    }
  }
}


// 原始位置：sound.cpp:68；地址：0x0040A340
// 调试记录声明：void playsound(long int id)
// 功能说明：播放指定音效。
void Sound::playsound(int id)
{
  bool v2;

  v2 = (unsigned __int8)IsWin() && this->soundb;
  if ( v2 )
    SetAudioPos(this->sSound[id], 0, 0);
}


// 原始位置：sound.cpp:76；地址：0x0040A394
// 调试记录声明：void switchsound()
// 功能说明：切换音效开关。
void Sound::switchsound()
{
  bool v1;

  this->soundb ^= 1u;
  v1 = (unsigned __int8)IsWin() && this->soundb;
  if ( v1 )
    this->playsound(this->sLeft);
}


// 原始位置：sound.cpp:85；地址：0x0040A3EC
// 调试记录声明：void playmusic()
// 功能说明：播放背景音乐。
// 可见操作：使用伪随机数。
// 原始局部变量：long int musici_。
void Sound::playmusic()
{
  bool v1;

  int musici_;

  if ( this->musicb )
  {
    v1 = (unsigned __int8)IsWin() && this->nummusic > 0;
    if ( v1 )
    {
      if ( this->musici != -256 && this->nummusic != 1 )
      {
        musici_ = rand() % (this->nummusic - 1);
        if ( this->musici <= musici_ )
          ++musici_;
        this->musici = musici_;
      }
      else
      {
        this->musici = 0;
      }
      this->musictime = GetTimeR();
      SetAudioPos(this->sMusic[this->musici], 0, 0);
    }
    else
    {
      this->musici = -256;
      this->musictime = 0.0;
    }
  }
}


// 原始位置：sound.cpp:115；地址：0x0040A4CC
// 调试记录声明：void checkmusic()
// 功能说明：检查音乐播放状态和切换条件。
void Sound::checkmusic()
{
  unsigned int v1;

  if ( this->musicb && this->musici >= 0 && this->musici < this->nummusic && GetTimeR() > this->musictime )
  {
    v1 = GetAudioPos(this->sMusic[this->musici]);
    if ( v1 < GetAudioLen(this->sMusic[this->musici]) )
      this->musictime = this->musictime + 10.0;
    else
      this->playmusic();
  }
}


// 原始位置：sound.cpp:133；地址：0x0040A584
// 调试记录声明：void switchmusic()
// 功能说明：切换音乐开关。
void Sound::switchmusic()
{

  this->musicb ^= 1u;
  if ( this->musicb )
  {
    this->playmusic();
  }
  else if ( this->musici >= 0 && this->musici < this->nummusic )
  {
    StopAudio(this->sMusic[this->musici]);
  }
  if ( this->soundb )
    this->playsound(this->sLeft);
}

