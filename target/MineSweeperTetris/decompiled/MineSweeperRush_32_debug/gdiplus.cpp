// 带中文注释的 C/C++ 风格反编译伪代码；含函数体，不保证可编译。
// 源二进制：MineSweeperRush_32_debug.exe
// 分组按恢复符号/可见调用推断，不保证对应原始文件边界。
// v1/v2 等是反编译器临时名；_DWORD 是 32 位值；BYTE 是字节。
// thisa 常为 this 的别名；__usercall/@<ecx> 表示寄存器参数。

// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00425E74; symbol: __ZN7Gdiplus11GdiplusBaseC2Ev
void __cdecl Gdiplus::GdiplusBase::GdiplusBase(Gdiplus::GdiplusBase *const this)
{
  ;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00425E80; symbol: __ZN7Gdiplus11GdiplusBasedlEPv
void __cdecl Gdiplus::GdiplusBase::operator delete(void *in_pVoid)
{
  GdipFree((int)in_pVoid);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// Address: 0x00425E98; symbol: __ZN7Gdiplus11GdiplusBasenwEj
void *__cdecl Gdiplus::GdiplusBase::operator new(size_t in_size)
{
  return (void *)GdipAlloc(in_size);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425EB0; symbol: __ZN7Gdiplus12CachedBitmapD0Ev
void __cdecl Gdiplus::CachedBitmap::~CachedBitmap(Gdiplus::CachedBitmap *const this)
{
  Gdiplus::CachedBitmap *v1; // ecx
  Gdiplus::CachedBitmap *v2; // ST1C_4
  Gdiplus::CachedBitmap *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::CachedBitmap::~CachedBitmap(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425ED0; symbol: __ZN7Gdiplus12CachedBitmapD1Ev
void __cdecl Gdiplus::CachedBitmap::~CachedBitmap(Gdiplus::CachedBitmap *const this)
{
  _DWORD *v1; // ecx

  *v1 = off_429DC4;
  GdipDeleteCachedBitmap(v1[1]);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425EF8; symbol: __ZN7Gdiplus13CustomLineCapD0Ev
void __cdecl Gdiplus::CustomLineCap::~CustomLineCap(Gdiplus::CustomLineCap *const this)
{
  Gdiplus::CustomLineCap *v1; // ecx
  Gdiplus::CustomLineCap *v2; // ST1C_4
  Gdiplus::CustomLineCap *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::CustomLineCap::~CustomLineCap(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425F18; symbol: __ZN7Gdiplus13CustomLineCapD1Ev
void __cdecl Gdiplus::CustomLineCap::~CustomLineCap(Gdiplus::CustomLineCap *const this)
{
  _DWORD *v1; // ecx

  *v1 = off_429DD4;
  GdipDeleteCustomLineCap(v1[1]);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425F40; symbol: __ZN7Gdiplus14FontCollectionD0Ev
void __cdecl Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  Gdiplus::FontCollection *v1; // ecx
  Gdiplus::FontCollection *v2; // ST1C_4
  Gdiplus::FontCollection *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::FontCollection::~FontCollection(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425F60; symbol: __ZN7Gdiplus14FontCollectionD1Ev
void __cdecl Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  _DWORD *v1; // ecx

  *v1 = off_429DE4;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425F78; symbol: __ZN7Gdiplus14FontCollectionD2Ev
void __cdecl Gdiplus::FontCollection::~FontCollection(Gdiplus::FontCollection *const this)
{
  _DWORD *v1; // ecx

  *v1 = off_429DE4;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425F90; symbol: .weak.__ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii.__ZN7Gdiplus11GdiplusBasedlEPv
void __userpurge weak___ZN7Gdiplus19GdiplusStartupInputC1EPFvNS_15DebugEventLevelEPcEii___ZN7Gdiplus11GdiplusBasedlEPv(_DWORD *a1@<ecx>, Gdiplus::GdiplusStartupInput *const this, Gdiplus::DebugEventProc debugEventCallback, BOOL suppressBackgroundThread, BOOL suppressExternalCodecs)
{
  *a1 = 1;
  a1[1] = this;
  a1[2] = debugEventCallback;
  a1[3] = suppressBackgroundThread;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425FC4; symbol: __ZN7Gdiplus21PrivateFontCollectionD0Ev
void __cdecl Gdiplus::PrivateFontCollection::~PrivateFontCollection(Gdiplus::PrivateFontCollection *const this)
{
  Gdiplus::PrivateFontCollection *v1; // ecx
  Gdiplus::PrivateFontCollection *v2; // ST1C_4
  Gdiplus::PrivateFontCollection *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::PrivateFontCollection::~PrivateFontCollection(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00425FE4; symbol: __ZN7Gdiplus21PrivateFontCollectionD1Ev
void __cdecl Gdiplus::PrivateFontCollection::~PrivateFontCollection(Gdiplus::PrivateFontCollection *const this)
{
  _DWORD *v1; // ecx
  Gdiplus::FontCollection *const v2; // ST00_4

  *v1 = off_429DF4;
  GdipDeletePrivateFontCollection((int)(v1 + 1));
  Gdiplus::FontCollection::~FontCollection(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426018; symbol: __ZN7Gdiplus23InstalledFontCollectionD0Ev
void __cdecl Gdiplus::InstalledFontCollection::~InstalledFontCollection(Gdiplus::InstalledFontCollection *const this)
{
  Gdiplus::InstalledFontCollection *v1; // ecx
  Gdiplus::InstalledFontCollection *v2; // ST1C_4
  Gdiplus::InstalledFontCollection *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::InstalledFontCollection::~InstalledFontCollection(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426038; symbol: __ZN7Gdiplus23InstalledFontCollectionD1Ev
void __cdecl Gdiplus::InstalledFontCollection::~InstalledFontCollection(Gdiplus::InstalledFontCollection *const this)
{
  _DWORD *v1; // ecx
  Gdiplus::FontCollection *v2; // [esp+0h] [ebp-18h]

  *v1 = off_429E04;
  Gdiplus::FontCollection::~FontCollection(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426058; symbol: __ZN7Gdiplus5Image14SetNativeImageEPNS_7GpImageE
void __userpurge Gdiplus::Image::SetNativeImage(int a1@<ecx>, Gdiplus::Image *const this, Gdiplus::GpImage *nativeImage)
{
  *(_DWORD *)(a1 + 4) = this;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426070; symbol: __ZN7Gdiplus5Image5CloneEv
Gdiplus::Image *__cdecl Gdiplus::Image::Clone(Gdiplus::Image *const this)
{
  int v1; // ecx
  Gdiplus::Image *v2; // ST1C_4
  const Gdiplus::Image *v3; // eax
  Gdiplus::Status v4; // ST04_4
  Gdiplus::Image *v5; // ebx
  Gdiplus::Status v7; // [esp+8h] [ebp-30h]
  Gdiplus::GpImage *cloneimage; // [esp+2Ch] [ebp-Ch]

  v2 = (Gdiplus::Image *)v1;
  cloneimage = 0;
  v3 = (const Gdiplus::Image *)GdipCloneImage(*(_DWORD *)(v1 + 4), (int)&cloneimage);
  Gdiplus::Image::SetStatus(v3, v4);
  v5 = (Gdiplus::Image *)Gdiplus::GdiplusBase::operator new(0x10u);
  Gdiplus::Image::Image((Gdiplus::Image *const )cloneimage, (Gdiplus::GpImage *)v2->lastResult, v7);
  return v5;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x004260DC; symbol: __ZN7Gdiplus5ImageC1EPNS_7GpImageENS_6StatusE
void __userpurge Gdiplus::Image::Image(Gdiplus::Image *a1@<ecx>, Gdiplus::Image *const this, Gdiplus::GpImage *nativeImage, Gdiplus::Status status)
{
  Gdiplus::Image *v4; // ST1C_4
  Gdiplus::GdiplusBase *v5; // [esp+0h] [ebp-28h]
  Gdiplus::GpImage *v6; // [esp+4h] [ebp-24h]

  v4 = a1;
  Gdiplus::GdiplusBase::GdiplusBase(v5);
  v4->_vptr_Image = (int (**)(...))off_429E14;
  Gdiplus::Image::SetNativeImage((int)v4, this, v6);
  v4->lastResult = (Gdiplus::Status)nativeImage;
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0042611C; symbol: __ZN7Gdiplus5ImageD0Ev
void __cdecl Gdiplus::Image::~Image(Gdiplus::Image *const this)
{
  Gdiplus::Image *v1; // ecx
  Gdiplus::Image *v2; // ST1C_4
  Gdiplus::Image *v3; // [esp+0h] [ebp-28h]

  v2 = v1;
  Gdiplus::Image::~Image(v3);
  Gdiplus::GdiplusBase::operator delete(v2);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x0042613C; symbol: __ZN7Gdiplus5ImageD1Ev
void __cdecl Gdiplus::Image::~Image(Gdiplus::Image *const this)
{
  _DWORD *v1; // ecx

  *v1 = off_429E14;
  GdipDisposeImage(v1[1]);
}



// 阅读说明：函数身份来自下方地址和符号；保留反编译器恢复的函数体。
// 函数体可见调用：调用 GDI+ 图形接口。
// 注意：旧版 IDA 的 this/寄存器调用约定可能误判；不能把未初始化的寄存器别名当作原始 C++。
// Address: 0x00426510; symbol: __ZNK7Gdiplus5Image9SetStatusENS_6StatusE
Gdiplus::Status __userpurge Gdiplus::Image::SetStatus@<eax>(int a1@<ecx>, const Gdiplus::Image *const this, Gdiplus::Status status)
{
  if ( !this )
    return 0;
  *(_DWORD *)(a1 + 8) = this;
  return *(_DWORD *)(a1 + 8);
}


