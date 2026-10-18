// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug2.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A060; symbol: __ZN5SoundC1Ev
void __cdecl Sound::Sound(Sound *const this)
{
  int v1; // ecx

  *(_DWORD *)(v1 + 32) = 0;
  *(_DWORD *)(v1 + 36) = &unk_42878C;
  *(_DWORD *)(v1 + 40) = "Lose";
  *(_DWORD *)(v1 + 44) = "Error";
  *(_DWORD *)(v1 + 48) = "Left";
  *(_DWORD *)(v1 + 52) = "Right";
  *(_DWORD *)(v1 + 56) = "Flag";
  *(_DWORD *)(v1 + 60) = "New";
  *(_DWORD *)(v1 + 64) = "Solve";
  *(_DWORD *)(v1 + 68) = 0;
  *(_DWORD *)(v1 + 72) = 1;
  *(_DWORD *)(v1 + 76) = 2;
  *(_DWORD *)(v1 + 80) = 3;
  *(_DWORD *)(v1 + 84) = 4;
  *(_DWORD *)(v1 + 88) = 5;
  *(_DWORD *)(v1 + 92) = 6;
  *(_DWORD *)(v1 + 96) = 7;
  *(_DWORD *)(v1 + 100) = 0;
  *(_BYTE *)(v1 + 104) = 1;
  *(_BYTE *)(v1 + 105) = 1;
  *(_DWORD *)(v1 + 108) = -256;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// Address: 0x0040A138; symbol: __ZN5Sound9initsoundEv
void __cdecl Sound::initsound(Sound *const this)
{
  Sound *const v1; // ST00_4
  Sound *const v2; // ST00_4
  Sound *v3; // [esp+0h] [ebp-18h]

  Sound::loadsound(v3);
  Sound::loadmusic(v1);
  Sound::playmusic(v2);
  painttitles = 0;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A16C; symbol: __ZN5Sound9loadsoundEv
void __cdecl Sound::loadsound(Sound *const this)
{
  Sound *v1; // ecx
  unsigned int v2; // ecx
  Sound *thisa; // [esp+1Ch] [ebp-11Ch]
  char sPath[260]; // [esp+28h] [ebp-110h]
  int id; // [esp+12Ch] [ebp-Ch]

  thisa = v1;
  if ( (unsigned __int8)IsWin() )
  {
    for ( id = 0; id <= 7; ++id )
    {
      sprintf(sPath, "./data/wav/%s.wav", thisa->sSounds[id]);
      v2 = LoadAudio(sPath, &s2);
      thisa->sSound[id] = v2;
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 Windows MCI 音频/音乐接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A1E8; symbol: __ZN5Sound9loadmusicEv
void __cdecl Sound::loadmusic(Sound *const this)
{
  Sound *v1; // ecx
  unsigned int *v2; // ebx
  Sound *thisa; // [esp+1Ch] [ebp-11Ch]
  char sPath[260]; // [esp+20h] [ebp-118h]
  unsigned int *sMusic_; // [esp+124h] [ebp-14h]
  MCIERROR ret; // [esp+128h] [ebp-10h]
  int k; // [esp+12Ch] [ebp-Ch]

  thisa = v1;
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
      v2 = &thisa->sMusic[thisa->nummusic];
      *v2 = LoadAudio(sPath, " type sequencer");
      ++thisa->nummusic;
    }
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A358; symbol: __ZN5Sound9playsoundEl
void __userpurge Sound::playsound(Sound *a1@<ecx>, Sound *const this, int id)
{
  bool v3; // al
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = a1;
  v3 = (unsigned __int8)IsWin() && thisa->soundb;
  if ( v3 )
    SetAudioPos(thisa->sSound[(_DWORD)this], 0, 0);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A3AC; symbol: __ZN5Sound11switchsoundEv
void __cdecl Sound::switchsound(Sound *const this)
{
  Sound *v1; // ecx
  bool v2; // al
  int v3; // [esp+4h] [ebp-24h]
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  v1->soundb ^= 1u;
  v2 = (unsigned __int8)IsWin() && thisa->soundb;
  if ( v2 )
    Sound::playsound(thisa, (Sound *const )thisa->sLeft, v3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A404; symbol: __ZN5Sound9playmusicEv
void __cdecl Sound::playmusic(Sound *const this)
{
  Sound *v1; // ecx
  bool v2; // al
  Sound *thisa; // [esp+1Ch] [ebp-1Ch]
  int musici_; // [esp+2Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->musicb )
  {
    v2 = (unsigned __int8)IsWin() && thisa->nummusic > 0;
    if ( v2 )
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



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A4E4; symbol: __ZN5Sound10checkmusicEv
void __cdecl Sound::checkmusic(Sound *const this)
{
  Sound *v1; // ecx
  unsigned int v2; // ebx
  Sound *v3; // [esp+0h] [ebp-28h]
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  if ( v1->musicb && v1->musici >= 0 && v1->musici < v1->nummusic && GetTimeR() > v1->musictime )
  {
    v2 = GetAudioPos(thisa->sMusic[thisa->musici]);
    if ( v2 < GetAudioLen(thisa->sMusic[thisa->musici]) )
      thisa->musictime = thisa->musictime + 10.0;
    else
      Sound::playmusic(v3);
  }
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0040A59C; symbol: __ZN5Sound11switchmusicEv
void __cdecl Sound::switchmusic(Sound *const this)
{
  Sound *v1; // ecx
  Sound *v2; // [esp+0h] [ebp-28h]
  int v3; // [esp+4h] [ebp-24h]
  Sound *thisa; // [esp+1Ch] [ebp-Ch]

  thisa = v1;
  v1->musicb ^= 1u;
  if ( v1->musicb )
  {
    Sound::playmusic(v2);
  }
  else if ( v1->musici >= 0 && v1->musici < v1->nummusic )
  {
    StopAudio(v1->sMusic[v1->musici]);
  }
  if ( thisa->soundb )
    Sound::playsound(thisa, (Sound *const )thisa->sLeft, v3);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 Windows MCI 音频/音乐接口。
// Address: 0x004231FC; symbol: _mciSendStringA@16
MCIERROR __stdcall mciSendStringA(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback)
{
  return mciSendStringA(lpstrCommand, lpstrReturnString, uReturnLength, hwndCallback);
}


