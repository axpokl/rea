unsigned int DWORD
;

int WINBOOL
;

WINBOOL BOOL
;

unsigned __int8 BYTE
;

unsigned __int16 WORD
;

BYTE *LPBYTE
;

int INT
;

unsigned int UINT
;

unsigned int size_t
;

char CHAR
;

int LONG
;

unsigned int ULONG
;

wchar_t WCHAR
;

unsigned __int16 wchar_t
;

void *HANDLE
;

WORD LANGID
;

__int16 INT16
;

unsigned __int16 UINT16
;

unsigned int UINT32
;

unsigned int UINT_PTR
;

struct
{
  unsigned int Data1;
  unsigned __int16 Data2;
  unsigned __int16 Data3;
  unsigned __int8 Data4[8];
} _GUID
;

unsigned int sizetype
;

_GUID GUID
;

struct
{
  int i;
} HBITMAP__
;

HBITMAP__ *HBITMAP
;

struct
{
  int i;
} HDC__
;

HDC__ *HDC
;

struct
{
  int i;
} HENHMETAFILE__
;

HENHMETAFILE__ *HENHMETAFILE
;

struct
{
  int i;
} HFONT__
;

HFONT__ *HFONT
;

struct
{
  int i;
} HICON__
;

HICON__ *HICON
;

struct
{
  int i;
} HMETAFILE__
;

HMETAFILE__ *HMETAFILE
;

struct
{
  int i;
} HINSTANCE__
;

HINSTANCE__ *HINSTANCE
;

struct
{
  int i;
} HPALETTE__
;

HPALETTE__ *HPALETTE
;

struct
{
  int i;
} HRGN__
;

HRGN__ *HRGN
;

struct
{
  int i;
} HWND__
;

HWND__ *HWND
;

DWORD COLORREF
;

struct
{
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
} tagRECTL
;

tagRECTL RECTL
;

struct
{
  LONG cx;
  LONG cy;
} tagSIZE
;

tagSIZE SIZEL
;

struct
{
  DWORD biSize;
  LONG biWidth;
  LONG biHeight;
  WORD biPlanes;
  WORD biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG biXPelsPerMeter;
  LONG biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
} tagBITMAPINFOHEADE
;

tagBITMAPINFOHEADE BITMAPINFOHEADER
;

struct
{
  BYTE rgbBlue;
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbReserved;
} tagRGBQUAD
;

tagRGBQUAD RGBQUAD
;

struct
{
  BITMAPINFOHEADER bmiHeader;
  RGBQUAD bmiColors[1];
} tagBITMAPINFO
;

tagBITMAPINFO BITMAPINFO
;

struct
{
  LONG lfHeight;
  LONG lfWidth;
  LONG lfEscapement;
  LONG lfOrientation;
  LONG lfWeight;
  BYTE lfItalic;
  BYTE lfUnderline;
  BYTE lfStrikeOut;
  BYTE lfCharSet;
  BYTE lfOutPrecision;
  BYTE lfClipPrecision;
  BYTE lfQuality;
  BYTE lfPitchAndFamily;
  CHAR lfFaceName[32];
} tagLOGFONTA
;

tagLOGFONTA LOGFONTA
;

struct
{
  LONG lfHeight;
  LONG lfWidth;
  LONG lfEscapement;
  LONG lfOrientation;
  LONG lfWeight;
  BYTE lfItalic;
  BYTE lfUnderline;
  BYTE lfStrikeOut;
  BYTE lfCharSet;
  BYTE lfOutPrecision;
  BYTE lfClipPrecision;
  BYTE lfQuality;
  BYTE lfPitchAndFamily;
  WCHAR lfFaceName[32];
} tagLOGFONTW
;

tagLOGFONTW LOGFONTW
;

struct __attribute__((packed)) __attribute__((aligned(2)))
{
  WORD mtType;
  WORD mtHeaderSize;
  WORD mtVersion;
  DWORD mtSize;
  WORD mtNoObjects;
  DWORD mtMaxRecord;
  WORD mtNoParameters;
} tagMETAHEADER
;

tagMETAHEADER METAHEADER
;

GUID IID
;

GUID CLSID
;

GUID FMTID
;

unsigned int PROPID
;

struct IStream
;

unsigned __int8 byte
;

struct
{
  __int8 gap0[1];
} std::__is_integer<long double>
;

enum : __int32
{
  __value = 0x0,
} std::__is_integer<long double>::$E9E4E0B672DC39ADC453A7552D944776
;

struct
{
  __int8 gap0[1];
} std::__is_integer<double>
;

enum : __int32
{
  __value_0 = 0x0,
} std::__is_integer<double>::$ABCDC5D0E007CF209679673CC98BF3A3
;

struct
{
  __int8 gap0[1];
} std::__is_integer<float>
;

enum : __int32
{
  __value_1 = 0x0,
} std::__is_integer<float>::$D7919DCDE9D39007A6E78FB013056F54
;

struct
{
  int quot;
  int rem;
} div_t
;

struct
{
  int quot;
  int rem;
} ldiv_t
;

struct
{
  __int64 quot;
  __int64 rem;
} lldiv_t
;

long double float_t
;

long double double_t
;

struct
{
  __int8 gap0[1];
} Gdiplus::GdiplusBase
;

enum : __int32
{
  FillModeAlternate = 0x0,
  FillModeWinding = 0x1,
} Gdiplus::FillMode
;

enum : __int32
{
  CompositingModeSourceOver = 0x0,
  CompositingModeSourceCopy = 0x1,
} Gdiplus::CompositingMode
;

enum : __int32
{
  CompositingQualityInvalid = 0xFFFFFFFF,
  CompositingQualityDefault = 0x0,
  CompositingQualityHighSpeed = 0x1,
  CompositingQualityHighQuality = 0x2,
  CompositingQualityGammaCorrected = 0x3,
  CompositingQualityAssumeLinear = 0x4,
} Gdiplus::CompositingQuality
;

enum : __int32
{
  UnitWorld = 0x0,
  UnitDisplay = 0x1,
  UnitPixel = 0x2,
  UnitPoint = 0x3,
  UnitInch = 0x4,
  UnitDocument = 0x5,
  UnitMillimeter = 0x6,
} Gdiplus::Unit
;

enum : __int32
{
  MetafileFrameUnitPixel = 0x2,
  MetafileFrameUnitPoint = 0x3,
  MetafileFrameUnitInch = 0x4,
  MetafileFrameUnitDocument = 0x5,
  MetafileFrameUnitMillimeter = 0x6,
  MetafileFrameUnitGdi = 0x7,
} Gdiplus::MetafileFrameUnit
;

enum : __int32
{
  CoordinateSpaceWorld = 0x0,
  CoordinateSpacePage = 0x1,
  CoordinateSpaceDevice = 0x2,
} Gdiplus::CoordinateSpace
;

enum : __int32
{
  WrapModeTile = 0x0,
  WrapModeTileFlipX = 0x1,
  WrapModeTileFlipY = 0x2,
  WrapModeTileFlipXY = 0x3,
  WrapModeClamp = 0x4,
} Gdiplus::WrapMode
;

enum : __int32
{
  DashStyleSolid = 0x0,
  DashStyleDash = 0x1,
  DashStyleDot = 0x2,
  DashStyleDashDot = 0x3,
  DashStyleDashDotDot = 0x4,
  DashStyleCustom = 0x5,
} Gdiplus::DashStyle
;

enum : __int32
{
  DashCapFlat = 0x0,
  DashCapRound = 0x2,
  DashCapTriangle = 0x3,
} Gdiplus::DashCap
;

enum : __int32
{
  LineCapFlat = 0x0,
  LineCapSquare = 0x1,
  LineCapRound = 0x2,
  LineCapTriangle = 0x3,
  LineCapNoAnchor = 0x10,
  LineCapSquareAnchor = 0x11,
  LineCapRoundAnchor = 0x12,
  LineCapDiamondAnchor = 0x13,
  LineCapArrowAnchor = 0x14,
  LineCapCustom = 0xFF,
  LineCapAnchorMask = 0xF0,
} Gdiplus::LineCap
;

enum : __int32
{
  LineJoinMiter = 0x0,
  LineJoinBevel = 0x1,
  LineJoinRound = 0x2,
  LineJoinMiterClipped = 0x3,
} Gdiplus::LineJoin
;

enum : __int32
{
  WarpModePerspective = 0x0,
  WarpModeBilinear = 0x1,
} Gdiplus::WarpMode
;

enum : __int32
{
  CombineModeReplace = 0x0,
  CombineModeIntersect = 0x1,
  CombineModeUnion = 0x2,
  CombineModeXor = 0x3,
  CombineModeExclude = 0x4,
  CombineModeComplement = 0x5,
} Gdiplus::CombineMode
;

enum : __int32
{
  ImageTypeUnknown = 0x0,
  ImageTypeBitmap = 0x1,
  ImageTypeMetafile = 0x2,
} Gdiplus::ImageType
;

enum : __int32
{
  InterpolationModeInvalid = 0xFFFFFFFF,
  InterpolationModeDefault = 0x0,
  InterpolationModeLowQuality = 0x1,
  InterpolationModeHighQuality = 0x2,
  InterpolationModeBilinear = 0x3,
  InterpolationModeBicubic = 0x4,
  InterpolationModeNearestNeighbor = 0x5,
  InterpolationModeHighQualityBilinear = 0x6,
  InterpolationModeHighQualityBicubic = 0x7,
} Gdiplus::InterpolationMode
;

enum : __int32
{
  PenAlignmentCenter = 0x0,
  PenAlignmentInset = 0x1,
  PenAlignmentOutset = 0x2,
  PenAlignmentLeft = 0x3,
  PenAlignmentRight = 0x4,
} Gdiplus::PenAlignment
;

enum : __int32
{
  BrushTypeSolidColor = 0x0,
  BrushTypeHatchFill = 0x1,
  BrushTypeTextureFill = 0x2,
  BrushTypePathGradient = 0x3,
  BrushTypeLinearGradient = 0x4,
} Gdiplus::BrushType
;

enum : __int32
{
  PenTypeSolidColor = 0x0,
  PenTypeHatchFill = 0x1,
  PenTypeTextureFill = 0x2,
  PenTypePathGradient = 0x3,
  PenTypeLinearGradient = 0x4,
  PenTypeUnknown = 0xFFFFFFFF,
} Gdiplus::PenType
;

enum : __int32
{
  MatrixOrderPrepend = 0x0,
  MatrixOrderAppend = 0x1,
} Gdiplus::MatrixOrder
;

enum : __int32
{
  FontStyleRegular = 0x0,
  FontStyleBold = 0x1,
  FontStyleItalic = 0x2,
  FontStyleBoldItalic = 0x3,
  FontStyleUnderline = 0x4,
  FontStyleStrikeout = 0x8,
} Gdiplus::FontStyle
;

enum : __int32
{
  SmoothingModeInvalid = 0xFFFFFFFF,
  SmoothingModeDefault = 0x0,
  SmoothingModeHighSpeed = 0x1,
  SmoothingModeHighQuality = 0x2,
  SmoothingModeNone = 0x3,
  SmoothingModeAntiAlias = 0x4,
} Gdiplus::SmoothingMode
;

enum : __int32
{
  PixelOffsetModeInvalid = 0xFFFFFFFF,
  PixelOffsetModeDefault = 0x0,
  PixelOffsetModeHighSpeed = 0x1,
  PixelOffsetModeHighQuality = 0x2,
  PixelOffsetModeNone = 0x3,
  PixelOffsetModeHalf = 0x4,
} Gdiplus::PixelOffsetMode
;

enum : __int32
{
  TextRenderingHintSystemDefault = 0x0,
  TextRenderingHintSingleBitPerPixelGridFit = 0x1,
  TextRenderingHintSingleBitPerPixel = 0x2,
  TextRenderingHintAntiAliasGridFit = 0x3,
  TextRenderingHintAntiAlias = 0x4,
  TextRenderingHintClearTypeGridFit = 0x5,
} Gdiplus::TextRenderingHint
;

enum : __int32
{
  MetafileTypeInvalid = 0x0,
  MetafileTypeWmf = 0x1,
  MetafileTypeWmfAldus = 0x2,
  MetafileTypeEmf = 0x3,
  MetafileTypeEmfPlusOnly = 0x4,
  MetafileTypeEmfPlusDual = 0x5,
} Gdiplus::MetafileType
;

enum : __int32
{
  EmfTypeEmfOnly = 0x3,
  EmfTypeEmfPlusOnly = 0x4,
  EmfTypeEmfPlusDual = 0x5,
} Gdiplus::EmfType
;

enum : __int32
{
  EmfRecordTypeHeader = 0x1,
  EmfRecordTypePolyBezier = 0x2,
  EmfRecordTypePolygon = 0x3,
  EmfRecordTypePolyline = 0x4,
  EmfRecordTypePolyBezierTo = 0x5,
  EmfRecordTypePolyLineTo = 0x6,
  EmfRecordTypePolyPolyline = 0x7,
  EmfRecordTypePolyPolygon = 0x8,
  EmfRecordTypeSetWindowExtEx = 0x9,
  EmfRecordTypeSetWindowOrgEx = 0xA,
  EmfRecordTypeSetViewportExtEx = 0xB,
  EmfRecordTypeSetViewportOrgEx = 0xC,
  EmfRecordTypeSetBrushOrgEx = 0xD,
  EmfRecordTypeEOF = 0xE,
  EmfRecordTypeSetPixelV = 0xF,
  EmfRecordTypeSetMapperFlags = 0x10,
  EmfRecordTypeSetMapMode = 0x11,
  EmfRecordTypeSetBkMode = 0x12,
  EmfRecordTypeSetPolyFillMode = 0x13,
  EmfRecordTypeSetROP2 = 0x14,
  EmfRecordTypeSetStretchBltMode = 0x15,
  EmfRecordTypeSetTextAlign = 0x16,
  EmfRecordTypeSetColorAdjustment = 0x17,
  EmfRecordTypeSetTextColor = 0x18,
  EmfRecordTypeSetBkColor = 0x19,
  EmfRecordTypeOffsetClipRgn = 0x1A,
  EmfRecordTypeMoveToEx = 0x1B,
  EmfRecordTypeSetMetaRgn = 0x1C,
  EmfRecordTypeExcludeClipRect = 0x1D,
  EmfRecordTypeIntersectClipRect = 0x1E,
  EmfRecordTypeScaleViewportExtEx = 0x1F,
  EmfRecordTypeScaleWindowExtEx = 0x20,
  EmfRecordTypeSaveDC = 0x21,
  EmfRecordTypeRestoreDC = 0x22,
  EmfRecordTypeSetWorldTransform = 0x23,
  EmfRecordTypeModifyWorldTransform = 0x24,
  EmfRecordTypeSelectObject = 0x25,
  EmfRecordTypeCreatePen = 0x26,
  EmfRecordTypeCreateBrushIndirect = 0x27,
  EmfRecordTypeDeleteObject = 0x28,
  EmfRecordTypeAngleArc = 0x29,
  EmfRecordTypeEllipse = 0x2A,
  EmfRecordTypeRectangle = 0x2B,
  EmfRecordTypeRoundRect = 0x2C,
  EmfRecordTypeArc = 0x2D,
  EmfRecordTypeChord = 0x2E,
  EmfRecordTypePie = 0x2F,
  EmfRecordTypeSelectPalette = 0x30,
  EmfRecordTypeCreatePalette = 0x31,
  EmfRecordTypeSetPaletteEntries = 0x32,
  EmfRecordTypeResizePalette = 0x33,
  EmfRecordTypeRealizePalette = 0x34,
  EmfRecordTypeExtFloodFill = 0x35,
  EmfRecordTypeLineTo = 0x36,
  EmfRecordTypeArcTo = 0x37,
  EmfRecordTypePolyDraw = 0x38,
  EmfRecordTypeSetArcDirection = 0x39,
  EmfRecordTypeSetMiterLimit = 0x3A,
  EmfRecordTypeBeginPath = 0x3B,
  EmfRecordTypeEndPath = 0x3C,
  EmfRecordTypeCloseFigure = 0x3D,
  EmfRecordTypeFillPath = 0x3E,
  EmfRecordTypeStrokeAndFillPath = 0x3F,
  EmfRecordTypeStrokePath = 0x40,
  EmfRecordTypeFlattenPath = 0x41,
  EmfRecordTypeWidenPath = 0x42,
  EmfRecordTypeSelectClipPath = 0x43,
  EmfRecordTypeAbortPath = 0x44,
  EmfRecordTypeReserved_069 = 0x45,
  EmfRecordTypeGdiComment = 0x46,
  EmfRecordTypeFillRgn = 0x47,
  EmfRecordTypeFrameRgn = 0x48,
  EmfRecordTypeInvertRgn = 0x49,
  EmfRecordTypePaintRgn = 0x4A,
  EmfRecordTypeExtSelectClipRgn = 0x4B,
  EmfRecordTypeBitBlt = 0x4C,
  EmfRecordTypeStretchBlt = 0x4D,
  EmfRecordTypeMaskBlt = 0x4E,
  EmfRecordTypePlgBlt = 0x4F,
  EmfRecordTypeSetDIBitsToDevice = 0x50,
  EmfRecordTypeStretchDIBits = 0x51,
  EmfRecordTypeExtCreateFontIndirect = 0x52,
  EmfRecordTypeExtTextOutA = 0x53,
  EmfRecordTypeExtTextOutW = 0x54,
  EmfRecordTypePolyBezier16 = 0x55,
  EmfRecordTypePolygon16 = 0x56,
  EmfRecordTypePolyline16 = 0x57,
  EmfRecordTypePolyBezierTo16 = 0x58,
  EmfRecordTypePolylineTo16 = 0x59,
  EmfRecordTypePolyPolyline16 = 0x5A,
  EmfRecordTypePolyPolygon16 = 0x5B,
  EmfRecordTypePolyDraw16 = 0x5C,
  EmfRecordTypeCreateMonoBrush = 0x5D,
  EmfRecordTypeCreateDIBPatternBrushPt = 0x5E,
  EmfRecordTypeExtCreatePen = 0x5F,
  EmfRecordTypePolyTextOutA = 0x60,
  EmfRecordTypePolyTextOutW = 0x61,
  EmfRecordTypeSetICMMode = 0x62,
  EmfRecordTypeCreateColorSpace = 0x63,
  EmfRecordTypeSetColorSpace = 0x64,
  EmfRecordTypeDeleteColorSpace = 0x65,
  EmfRecordTypeGLSRecord = 0x66,
  EmfRecordTypeGLSBoundedRecord = 0x67,
  EmfRecordTypePixelFormat = 0x68,
  EmfRecordTypeDrawEscape = 0x69,
  EmfRecordTypeExtEscape = 0x6A,
  EmfRecordTypeStartDoc = 0x6B,
  EmfRecordTypeSmallTextOut = 0x6C,
  EmfRecordTypeForceUFIMapping = 0x6D,
  EmfRecordTypeNamedEscape = 0x6E,
  EmfRecordTypeColorCorrectPalette = 0x6F,
  EmfRecordTypeSetICMProfileA = 0x70,
  EmfRecordTypeSetICMProfileW = 0x71,
  EmfRecordTypeAlphaBlend = 0x72,
  EmfRecordTypeSetLayout = 0x73,
  EmfRecordTypeTransparentBlt = 0x74,
  EmfRecordTypeReserved_117 = 0x75,
  EmfRecordTypeGradientFill = 0x76,
  EmfRecordTypeSetLinkedUFIs = 0x77,
  EmfRecordTypeSetTextJustification = 0x78,
  EmfRecordTypeColorMatchToTargetW = 0x79,
  EmfRecordTypeCreateColorSpaceW = 0x7A,
  EmfRecordTypeMax = 0x7A,
  EmfRecordTypeMin = 0x1,
  EmfPlusRecordTypeInvalid = 0x4000,
  EmfPlusRecordTypeHeader = 0x4001,
  EmfPlusRecordTypeEndOfFile = 0x4002,
  EmfPlusRecordTypeComment = 0x4003,
  EmfPlusRecordTypeGetDC = 0x4004,
  EmfPlusRecordTypeMultiFormatStart = 0x4005,
  EmfPlusRecordTypeMultiFormatSection = 0x4006,
  EmfPlusRecordTypeMultiFormatEnd = 0x4007,
  EmfPlusRecordTypeObject = 0x4008,
  EmfPlusRecordTypeClear = 0x4009,
  EmfPlusRecordTypeFillRects = 0x400A,
  EmfPlusRecordTypeDrawRects = 0x400B,
  EmfPlusRecordTypeFillPolygon = 0x400C,
  EmfPlusRecordTypeDrawLines = 0x400D,
  EmfPlusRecordTypeFillEllipse = 0x400E,
  EmfPlusRecordTypeDrawEllipse = 0x400F,
  EmfPlusRecordTypeFillPie = 0x4010,
  EmfPlusRecordTypeDrawPie = 0x4011,
  EmfPlusRecordTypeDrawArc = 0x4012,
  EmfPlusRecordTypeFillRegion = 0x4013,
  EmfPlusRecordTypeFillPath = 0x4014,
  EmfPlusRecordTypeDrawPath = 0x4015,
  EmfPlusRecordTypeFillClosedCurve = 0x4016,
  EmfPlusRecordTypeDrawClosedCurve = 0x4017,
  EmfPlusRecordTypeDrawCurve = 0x4018,
  EmfPlusRecordTypeDrawBeziers = 0x4019,
  EmfPlusRecordTypeDrawImage = 0x401A,
  EmfPlusRecordTypeDrawImagePoints = 0x401B,
  EmfPlusRecordTypeDrawString = 0x401C,
  EmfPlusRecordTypeSetRenderingOrigin = 0x401D,
  EmfPlusRecordTypeSetAntiAliasMode = 0x401E,
  EmfPlusRecordTypeSetTextRenderingHint = 0x401F,
  EmfPlusRecordTypeSetTextContrast = 0x4020,
  EmfPlusRecordTypeSetInterpolationMode = 0x4021,
  EmfPlusRecordTypeSetPixelOffsetMode = 0x4022,
  EmfPlusRecordTypeSetCompositingMode = 0x4023,
  EmfPlusRecordTypeSetCompositingQuality = 0x4024,
  EmfPlusRecordTypeSave = 0x4025,
  EmfPlusRecordTypeRestore = 0x4026,
  EmfPlusRecordTypeBeginContainer = 0x4027,
  EmfPlusRecordTypeBeginContainerNoParams = 0x4028,
  EmfPlusRecordTypeEndContainer = 0x4029,
  EmfPlusRecordTypeSetWorldTransform = 0x402A,
  EmfPlusRecordTypeResetWorldTransform = 0x402B,
  EmfPlusRecordTypeMultiplyWorldTransform = 0x402C,
  EmfPlusRecordTypeTranslateWorldTransform = 0x402D,
  EmfPlusRecordTypeScaleWorldTransform = 0x402E,
  EmfPlusRecordTypeRotateWorldTransform = 0x402F,
  EmfPlusRecordTypeSetPageTransform = 0x4030,
  EmfPlusRecordTypeResetClip = 0x4031,
  EmfPlusRecordTypeSetClipRect = 0x4032,
  EmfPlusRecordTypeSetClipPath = 0x4033,
  EmfPlusRecordTypeSetClipRegion = 0x4034,
  EmfPlusRecordTypeOffsetClip = 0x4035,
  EmfPlusRecordTypeDrawDriverString = 0x4036,
  EmfPlusRecordTotal = 0x4037,
  EmfPlusRecordTypeMax = 0x4036,
  EmfPlusRecordTypeMin = 0x4001,
} Gdiplus::EmfPlusRecordType
;

enum : __int32
{
  StringTrimmingNone = 0x0,
  StringTrimmingCharacter = 0x1,
  StringTrimmingWord = 0x2,
  StringTrimmingEllipsisCharacter = 0x3,
  StringTrimmingEllipsisWord = 0x4,
  StringTrimmingEllipsisPath = 0x5,
} Gdiplus::StringTrimming
;

enum : __int32
{
  StringDigitSubstituteUser = 0x0,
  StringDigitSubstituteNone = 0x1,
  StringDigitSubstituteNational = 0x2,
  StringDigitSubstituteTraditional = 0x3,
} Gdiplus::StringDigitSubstitute
;

enum : __int32
{
  HotkeyPrefixNone = 0x0,
  HotkeyPrefixShow = 0x1,
  HotkeyPrefixHide = 0x2,
} Gdiplus::HotkeyPrefix
;

enum : __int32
{
  StringAlignmentNear = 0x0,
  StringAlignmentCenter = 0x1,
  StringAlignmentFar = 0x2,
} Gdiplus::StringAlignment
;

enum : __int32
{
  FlushIntentionFlush = 0x0,
  FlushIntentionSync = 0x1,
} Gdiplus::FlushIntention
;

enum : __int32
{
  GraphicsLayoutNormal = 0x0,
  GraphicsLayoutMirrored = 0x1,
  GraphicsLayoutMirroredIgnoreImages = 0x2,
  GraphicsLayoutMirroredForceImages = 0x3,
} Gdiplus::GraphicsLayout
;

enum : __int32
{
  ImageLayoutNormal = 0x0,
  ImageLayoutIgnoreMirrored = 0x1,
} Gdiplus::ImageLayout
;

enum : __int32
{
  EmfToWmfBitsFlagsDefault = 0x0,
  EmfToWmfBitsFlagsEmbedEmf = 0x1,
  EmfToWmfBitsFlagsIncludeAPM = 0x2,
  EmfToWmfBitsFlagsNoXORClip = 0x4,
} Gdiplus::EmfToWmfBitsFlags
;

enum : __int32
{
  Ok = 0x0,
  GenericError = 0x1,
  InvalidParameter = 0x2,
  OutOfMemory = 0x3,
  ObjectBusy = 0x4,
  InsufficientBuffer = 0x5,
  NotImplemented = 0x6,
  Win32Error = 0x7,
  WrongState = 0x8,
  Aborted = 0x9,
  FileNotFound = 0xA,
  ValueOverflow = 0xB,
  AccessDenied = 0xC,
  UnknownImageFormat = 0xD,
  FontFamilyNotFound = 0xE,
  FontStyleNotFound = 0xF,
  NotTrueTypeFont = 0x10,
  UnsupportedGdiplusVersion = 0x11,
  GdiplusNotInitialized = 0x12,
} Gdiplus::Status
;

struct
{
  Gdiplus::REAL Width;
  Gdiplus::REAL Height;
} Gdiplus::SizeF
;

float Gdiplus::REAL
;

struct
{
  INT Width;
  INT Height;
} Gdiplus::Size
;

struct
{
  Gdiplus::REAL X;
  Gdiplus::REAL Y;
} Gdiplus::PointF
;

struct
{
  INT X;
  INT Y;
} Gdiplus::Point
;

struct
{
  Gdiplus::REAL X;
  Gdiplus::REAL Y;
  Gdiplus::REAL Width;
  Gdiplus::REAL Height;
} Gdiplus::RectF
;

struct
{
  INT X;
  INT Y;
  INT Width;
  INT Height;
} Gdiplus::Rect
;

struct
{
  INT Count;
  Gdiplus::PointF *Points;
  BYTE *Types;
} Gdiplus::PathData
;

struct
{
  INT First;
  INT Length;
} Gdiplus::CharacterRange
;

struct
{
  UINT Flags;
  UINT Count;
  Gdiplus::ARGB Entries[1];
} Gdiplus::ColorPalette
;

DWORD Gdiplus::ARGB
;

enum : __int32
{
  ColorChannelFlagsC = 0x0,
  ColorChannelFlagsM = 0x1,
  ColorChannelFlagsY = 0x2,
  ColorChannelFlagsK = 0x3,
  ColorChannelFlagsLast = 0x4,
} Gdiplus::ColorChannelFlags
;

struct
{
  Gdiplus::ARGB Argb;
} Gdiplus::Color
;

struct
{
  DWORD iType;
  DWORD nSize;
  RECTL rclBounds;
  RECTL rclFrame;
  DWORD dSignature;
  DWORD nVersion;
  DWORD nBytes;
  DWORD nRecords;
  WORD nHandles;
  WORD sReserved;
  DWORD nDescription;
  DWORD offDescription;
  DWORD nPalEntries;
  SIZEL szlDevice;
  SIZEL szlMillimeters;
} Gdiplus::ENHMETAHEADER3
;

struct
{
  INT16 Left;
  INT16 Top;
  INT16 Right;
  INT16 Bottom;
} Gdiplus::APMRect16
;

struct __attribute__((packed)) __attribute__((aligned(2)))
{
  UINT32 Key;
  INT16 Hmf;
  Gdiplus::APMRect16 BoundingBox;
  INT16 Inch;
  UINT32 Reserved;
  INT16 Checksum;
} Gdiplus::$285B5F03A6CB1C4C14E1415646179DE8
;

struct
{
  Gdiplus::MetafileType Type;
  UINT Size;
  UINT Version;
  UINT EmfPlusFlags;
  Gdiplus::REAL DpiX;
  Gdiplus::REAL DpiY;
  INT X;
  INT Y;
  INT Width;
  INT Height;
  Gdiplus::MetafileHeader::$E637D5081B57E0AEB4DBFDBF5AF3EDF9 _anon_0;
  INT EmfPlusHeaderSize;
  INT LogicalDpiX;
  INT LogicalDpiY;
} Gdiplus::MetafileHeader
;

union
{
  METAHEADER WmfHeader;
  Gdiplus::ENHMETAHEADER3 EmfHeader;
} Gdiplus::MetafileHeader::$E637D5081B57E0AEB4DBFDBF5AF3EDF9
;

struct
{
  UINT Width;
  UINT Height;
  INT Stride;
  Gdiplus::PixelFormat PixelFormat;
  void *Scan0;
  UINT_PTR Reserved;
} Gdiplus::BitmapData
;

INT Gdiplus::PixelFormat
;

enum : __int32
{
  RotateNoneFlipNone = 0x0,
  Rotate90FlipNone = 0x1,
  Rotate180FlipNone = 0x2,
  Rotate270FlipNone = 0x3,
  RotateNoneFlipX = 0x4,
  Rotate90FlipX = 0x5,
  Rotate180FlipX = 0x6,
  Rotate270FlipX = 0x7,
  RotateNoneFlipY = 0x6,
  Rotate90FlipY = 0x7,
  Rotate180FlipY = 0x4,
  Rotate270FlipY = 0x5,
  RotateNoneFlipXY = 0x2,
  Rotate90FlipXY = 0x3,
  Rotate180FlipXY = 0x0,
  Rotate270FlipXY = 0x1,
} Gdiplus::RotateFlipType
;

struct
{
  GUID Guid;
  ULONG NumberOfValues;
  ULONG Type;
  void *Value;
} Gdiplus::EncoderParameter
;

struct
{
  UINT Count;
  Gdiplus::EncoderParameter Parameter[1];
} Gdiplus::EncoderParameters
;

struct
{
  PROPID id;
  ULONG length;
  WORD type;
  void *value;
} Gdiplus::PropertyItem
;

struct
{
  Gdiplus::REAL m[5][5];
} Gdiplus::ColorMatrix
;

enum : __int32
{
  ColorMatrixFlagsDefault = 0x0,
  ColorMatrixFlagsSkipGrays = 0x1,
  ColorMatrixFlagsAltGray = 0x2,
} Gdiplus::ColorMatrixFlags
;

enum : __int32
{
  ColorAdjustTypeDefault = 0x0,
  ColorAdjustTypeBitmap = 0x1,
  ColorAdjustTypeBrush = 0x2,
  ColorAdjustTypePen = 0x3,
  ColorAdjustTypeText = 0x4,
  ColorAdjustTypeCount = 0x5,
  ColorAdjustTypeAny = 0x6,
} Gdiplus::ColorAdjustType
;

struct
{
  Gdiplus::Color oldColor;
  Gdiplus::Color newColor;
} Gdiplus::ColorMap
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpGraphics
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpBrush
;

struct __cppobj : Gdiplus::GpBrush
{
} Gdiplus::GpTexture
;

struct __cppobj : Gdiplus::GpBrush
{
} Gdiplus::GpSolidFill
;

struct __cppobj : Gdiplus::GpBrush
{
} Gdiplus::GpLineGradient
;

struct __cppobj : Gdiplus::GpBrush
{
} Gdiplus::GpPathGradient
;

struct __cppobj : Gdiplus::GpBrush
{
} Gdiplus::GpHatch
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpPen
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpCustomLineCap
;

struct __cppobj : Gdiplus::GpCustomLineCap
{
} Gdiplus::GpAdjustableArrowCap
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpImage
;

struct __cppobj : Gdiplus::GpImage
{
} Gdiplus::GpBitmap
;

struct __cppobj : Gdiplus::GpImage
{
} Gdiplus::GpMetafile
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpImageAttributes
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpPath
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpRegion
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpFontFamily
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpFont
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpStringFormat
;

struct
{
  __int8 gap0[1];
} Gdiplus::GpFontCollection
;

struct
{
  Gdiplus::GpRegion *nativeRegion;
  Gdiplus::Status lastResult;
} Gdiplus::Region
;

struct
{
  Gdiplus::GpPath *nativePath;
  Gdiplus::Status lastResult;
} Gdiplus::GraphicsPath
;

struct
{
  Gdiplus::GpMatrix *nativeMatrix;
  Gdiplus::Status lastResult;
} Gdiplus::Matrix
;

Gdiplus::Matrix Gdiplus::GpMatrix
;

struct
{
  Gdiplus::GpGraphics *nativeGraphics;
  Gdiplus::Status lastResult;
} Gdiplus::Graphics
;

struct
{
  Gdiplus::GpFontFamily *nativeFamily;
  Gdiplus::Status lastResult;
} Gdiplus::FontFamily
;

struct
{
  int (**_vptr_FontCollection)(...);
  Gdiplus::GpFontCollection *nativeFontCollection;
  Gdiplus::Status lastResult;
} Gdiplus::FontCollection
;

struct
{
  Gdiplus::GpFont *nativeFont;
  Gdiplus::Status lastResult;
} Gdiplus::Font
;

struct
{
  Gdiplus::GpImageAttributes *nativeImageAttr;
  Gdiplus::Status lastResult;
} Gdiplus::ImageAttributes
;

struct
{
  Gdiplus::GpPen *nativePen;
  Gdiplus::Status lastResult;
} Gdiplus::Pen
;

struct
{
  int (**_vptr_Brush)(...);
  Gdiplus::GpBrush *nativeBrush;
  Gdiplus::Status lastResult;
} Gdiplus::Brush
;

struct
{
  int (**_vptr_CustomLineCap)(...);
  Gdiplus::GpCustomLineCap *nativeCap;
  Gdiplus::Status lastResult;
} Gdiplus::CustomLineCap
;

struct
{
  Gdiplus::GpStringFormat *nativeFormat;
  Gdiplus::Status lastError;
} Gdiplus::StringFormat
;

Gdiplus::Status Gdiplus::GpStatus
;

struct
{
  int (**_vptr_Image)(...);
  Gdiplus::GpImage *nativeImage;
  Gdiplus::Status lastResult;
  Gdiplus::Status loadStatus;
} Gdiplus::Image
;

struct
{
  int (**_vptr_CachedBitmap)(...);
  Gdiplus::GpCachedBitmap *nativeCachedBitmap;
  Gdiplus::Status lastResult;
} Gdiplus::CachedBitmap
;

struct Gdiplus::GpCachedBitmap
;

Gdiplus::ImageAbort Gdiplus::DrawImageAbort
;

BOOL (*Gdiplus::ImageAbort)(void *)
;

struct __cppobj : Gdiplus::Image
{
} Gdiplus::Metafile
;

BOOL (*Gdiplus::EnumerateMetafileProc)(Gdiplus::EmfPlusRecordType, UINT, UINT, const BYTE *, void *)
;

UINT Gdiplus::GraphicsState
;

UINT Gdiplus::GraphicsContainer
;

Gdiplus::ImageAbort Gdiplus::GetThumbnailImageAbort
;

struct __cppobj : Gdiplus::FontCollection
{
} Gdiplus::PrivateFontCollection
;

struct __cppobj : Gdiplus::FontCollection
{
} Gdiplus::InstalledFontCollection
;

struct __cppobj : Gdiplus::Image
{
} Gdiplus::Bitmap
;

struct
{
  char *_ptr;
  int _cnt;
  char *_base;
  int _flag;
  int _file;
  int _charbuf;
  int _bufsiz;
  char *_tmpfname;
} _iobuf
;

_iobuf FILE
;

struct
{
  int w;
  int h;
  int n;
  int sit;
  int pauseb;
  int maskj;
  int maski;
  int tx;
  int ty;
  bool (*flag)[128];
  bool (*qstn)[128];
  bool (*mine)[128];
  bool (*blck)[128];
  bool (*mask)[128];
  int (*numb)[128];
  bool (*leftrule)[128];
  bool (*rightrule)[128];
} Block
;

struct IDirectDrawSurface7
;

unsigned __int8 uint8
;

__int16 int16
;

unsigned __int16 uint16
;

int int32
;

unsigned int uint32
;

unsigned __int64 uint64
;

uint32 AppId_t
;

uint32 DepotId_t
;

uint64 SteamAPICall_t
;

uint32 AccountID_t
;

uint64 PartyBeaconID_t
;

enum : __int32
{
  k_EUniverseInvalid = 0x0,
  k_EUniversePublic = 0x1,
  k_EUniverseBeta = 0x2,
  k_EUniverseInternal = 0x3,
  k_EUniverseDev = 0x4,
  k_EUniverseMax = 0x5,
} EUniverse
;

uint32 HAuthTicket
;

enum : __int32
{
  k_EAccountTypeInvalid = 0x0,
  k_EAccountTypeIndividual = 0x1,
  k_EAccountTypeMultiseat = 0x2,
  k_EAccountTypeGameServer = 0x3,
  k_EAccountTypeAnonGameServer = 0x4,
  k_EAccountTypePending = 0x5,
  k_EAccountTypeContentServer = 0x6,
  k_EAccountTypeClan = 0x7,
  k_EAccountTypeChat = 0x8,
  k_EAccountTypeConsoleUser = 0x9,
  k_EAccountTypeAnonUser = 0xA,
  k_EAccountTypeMax = 0xB,
} EAccountType
;

struct
{
  CSteamID::SteamID_t m_steamid;
} CSteamID
;

union
{
  CSteamID::SteamID_t::SteamIDComponent_t m_comp;
  uint64 m_unAll64Bits;
} CSteamID::SteamID_t
;

struct
{
  unsigned __int32 m_unAccountID : 32;
  unsigned __int32 m_unAccountInstance : 20;
  unsigned __int32 m_EAccountType : 4;
  __int32 m_EUniverse : 8;
} CSteamID::SteamID_t::SteamIDComponent_t
;

enum : __int32
{
  k_iSteamUserCallbacks = 0x64,
} $CDD6A5183505116B35FC206920E63627
;

enum : __int32
{
  k_iSteamMatchmakingCallbacks = 0x1F4,
} $A4173BE86B52B0F505DB1B60B4606BC0
;

enum : __int32
{
  k_iSteamUtilsCallbacks = 0x2BC,
} $0C8FDD38DED581DC5B3F30AEAED0B670
;

enum : __int32
{
  k_iSteamUserStatsCallbacks = 0x44C,
} $3E871D75ADD7139950BE5FE80C2BA256
;

enum : __int32
{
  k_iSteamNetworkingCallbacks = 0x4B0,
} $C72C972B8B1A290F8A44CD486DAC64EE
;

enum : __int32
{
  k_iSteamAppListCallbacks = 0xF3C,
} $DECF4E93A97E6B95CE3DE9EC4E53D1CA
;

enum : __int32
{
  k_iSteamHTMLSurfaceCallbacks = 0x1194,
} $BE125DBB4D58B10D0AF53655530063AC
;

enum : __int32
{
  k_iSteamGameSearchCallbacks = 0x1450,
} $33AF24DBC4DB5BAF2DC7B4E5B7EDCFE0
;

enum : __int32
{
  k_iSteamPartiesCallbacks = 0x14B4,
} $1D897299FAC6B49A58F9A313EDB2C67B
;

enum : __int32
{
  k_iSteamRemotePlayCallbacks = 0x1644,
} $9589855BCEF70FBA3AE8C4956284019D
;

int16 FriendsGroupID_t
;

uint64 UGCHandle_t
;

uint64 PublishedFileUpdateHandle_t
;

uint64 PublishedFileId_t
;

uint64 UGCFileWriteStreamHandle_t
;

enum : __int32
{
  k_cchStatNameMax = 0x80,
} $C62D1519FB2A6CD61FC1F0129284EE42
;

uint64 SteamLeaderboard_t
;

uint64 SteamLeaderboardEntries_t
;

struct
{
  CSteamID m_steamIDUser;
  int32 m_nGlobalRank;
  int32 m_nScore;
  int32 m_cDetails;
  __attribute__((aligned(8))) UGCHandle_t m_hUGC;
} LeaderboardEntry_t
;

struct __attribute__((aligned(8)))
{
  SteamLeaderboard_t m_hSteamLeaderboard;
  uint8 m_bLeaderboardFound;
} LeaderboardFindResult_t
;

struct __attribute__((aligned(8)))
{
  SteamLeaderboard_t m_hSteamLeaderboard;
  SteamLeaderboardEntries_t m_hSteamLeaderboardEntries;
  int m_cEntryCount;
} LeaderboardScoresDownloaded_t
;

struct
{
  uint8 m_bSuccess;
  __attribute__((aligned(8))) SteamLeaderboard_t m_hSteamLeaderboard;
  int32 m_nScore;
  uint8 m_bScoreChanged;
  int m_nGlobalRankNew;
  int m_nGlobalRankPrevious;
} LeaderboardScoreUploaded_t
;

uint64 UGCQueryHandle_t
;

uint64 UGCUpdateHandle_t
;

uint64 SteamItemInstanceID_t
;

int32 SteamInventoryResult_t
;

uint64 SteamInventoryUpdateHandle_t
;

uint32 HSteamNetConnection
;

uint32 HSteamListenSocket
;

uint32 HSteamNetPollGroup
;

uint32 SteamNetworkingPOPID
;

enum : __int32
{
  k_ESteamNetworkingIdentityType_Invalid = 0x0,
  k_ESteamNetworkingIdentityType_SteamID = 0x10,
  k_ESteamNetworkingIdentityType_XboxPairwiseID = 0x11,
  k_ESteamNetworkingIdentityType_SonyPSN = 0x12,
  k_ESteamNetworkingIdentityType_GoogleStadia = 0x13,
  k_ESteamNetworkingIdentityType_IPAddress = 0x1,
  k_ESteamNetworkingIdentityType_GenericString = 0x2,
  k_ESteamNetworkingIdentityType_GenericBytes = 0x3,
  k_ESteamNetworkingIdentityType_UnknownType = 0x4,
  k_ESteamNetworkingIdentityType__Force32bit = 0x7FFFFFFF,
} ESteamNetworkingIdentityType
;

enum : __int32
{
  k_ESteamNetworkingFakeIPType_Invalid = 0x0,
  k_ESteamNetworkingFakeIPType_NotFake = 0x1,
  k_ESteamNetworkingFakeIPType_GlobalIPv4 = 0x2,
  k_ESteamNetworkingFakeIPType_LocalIPv4 = 0x3,
  k_ESteamNetworkingFakeIPType__Force32Bit = 0x7FFFFFFF,
} ESteamNetworkingFakeIPType
;

struct __attribute__((packed)) __attribute__((aligned(2)))
{
  SteamNetworkingIPAddr::$58EEB30D49142433343D730C1242F561 _anon_0;
  uint16 m_port;
} SteamNetworkingIPAddr
;

union
{
  uint8 m_ipv6[16];
  SteamNetworkingIPAddr::IPv4MappedAddress m_ipv4;
} SteamNetworkingIPAddr::$58EEB30D49142433343D730C1242F561
;

struct
{
  uint64 m_8zeros;
  uint16 m_0000;
  uint16 m_ffff;
  uint8 m_ip[4];
} SteamNetworkingIPAddr::IPv4MappedAddress
;

struct
{
  ESteamNetworkingIdentityType m_eType;
  int m_cbSize;
  SteamNetworkingIdentity::$DC7EEFA8BCC6434861BCD8B0D437EB00 _anon_0;
} SteamNetworkingIdentity
;

union
{
  uint64 m_steamID64;
  uint64 m_PSNID;
  uint64 m_stadiaID;
  char m_szGenericString[32];
  char m_szXboxPairwiseID[33];
  uint8 m_genericBytes[32];
  char m_szUnknownRawString[128];
  SteamNetworkingIPAddr m_ip;
  uint32 m_reserved[32];
} SteamNetworkingIdentity::$DC7EEFA8BCC6434861BCD8B0D437EB00
;

enum : __int32
{
  k_cchMaxString = 0x80,
  k_cchMaxGenericString = 0x20,
  k_cchMaxXboxPairwiseID = 0x21,
  k_cbMaxGenericBytes = 0x20,
} SteamNetworkingIdentity::$1B1B514BE4FF5488A44137A8AF8A1EB7
;

enum : __int32
{
  k_ESteamNetConnectionEnd_Invalid = 0x0,
  k_ESteamNetConnectionEnd_App_Min = 0x3E8,
  k_ESteamNetConnectionEnd_App_Generic = 0x3E8,
  k_ESteamNetConnectionEnd_App_Max = 0x7CF,
  k_ESteamNetConnectionEnd_AppException_Min = 0x7D0,
  k_ESteamNetConnectionEnd_AppException_Generic = 0x7D0,
  k_ESteamNetConnectionEnd_AppException_Max = 0xBB7,
  k_ESteamNetConnectionEnd_Local_Min = 0xBB8,
  k_ESteamNetConnectionEnd_Local_OfflineMode = 0xBB9,
  k_ESteamNetConnectionEnd_Local_ManyRelayConnectivity = 0xBBA,
  k_ESteamNetConnectionEnd_Local_HostedServerPrimaryRelay = 0xBBB,
  k_ESteamNetConnectionEnd_Local_NetworkConfig = 0xBBC,
  k_ESteamNetConnectionEnd_Local_Rights = 0xBBD,
  k_ESteamNetConnectionEnd_Local_P2P_ICE_NoPublicAddresses = 0xBBE,
  k_ESteamNetConnectionEnd_Local_Max = 0xF9F,
  k_ESteamNetConnectionEnd_Remote_Min = 0xFA0,
  k_ESteamNetConnectionEnd_Remote_Timeout = 0xFA1,
  k_ESteamNetConnectionEnd_Remote_BadCrypt = 0xFA2,
  k_ESteamNetConnectionEnd_Remote_BadCert = 0xFA3,
  k_ESteamNetConnectionEnd_Remote_BadProtocolVersion = 0xFA6,
  k_ESteamNetConnectionEnd_Remote_P2P_ICE_NoPublicAddresses = 0xFA7,
  k_ESteamNetConnectionEnd_Remote_Max = 0x1387,
  k_ESteamNetConnectionEnd_Misc_Min = 0x1388,
  k_ESteamNetConnectionEnd_Misc_Generic = 0x1389,
  k_ESteamNetConnectionEnd_Misc_InternalError = 0x138A,
  k_ESteamNetConnectionEnd_Misc_Timeout = 0x138B,
  k_ESteamNetConnectionEnd_Misc_SteamConnectivity = 0x138D,
  k_ESteamNetConnectionEnd_Misc_NoRelaySessionsToClient = 0x138E,
  k_ESteamNetConnectionEnd_Misc_P2P_Rendezvous = 0x1390,
  k_ESteamNetConnectionEnd_Misc_P2P_NAT_Firewall = 0x1391,
  k_ESteamNetConnectionEnd_Misc_PeerSentNoConnection = 0x1392,
  k_ESteamNetConnectionEnd_Misc_Max = 0x176F,
  k_ESteamNetConnectionEnd__Force32Bit = 0x7FFFFFFF,
} ESteamNetConnectionEnd
;

struct
{
  const char *lanshort[30];
  const int lanshortid[30];
  __int16 *data;
  __int16 *landata;
  __int16 **landatap;
  int LAN_TITLE;
  int LAN_RUNNING;
  int LAN_STEAM_LAUNCH;
  int LAN_STEAM_FAIL;
  int LAN_STEAM_Status;
  int LAN_ABOUT_NAME;
  int LAN_ABOUT_VERSION;
  int LAN_ABOUT_AUTHOR;
  int LAN_ABOUT_LICENSE;
  int LAN_ABOUT_OK;
  int LAN_LOAD_STEAM;
  int LAN_LOAD_AUDIO;
  int LAN_LOAD_BOARD;
  int LAN_LOAD_GRAPH;
  int LAN_LOAD_WINDOW;
  int LAN_HELP;
  int LAN_SET;
  int LAN_TUT_;
  int LAN_TUT;
  int LAN_MODE;
  int LAN_TUT_QUIT;
  int LAN_HELP_MENU;
  int LAN_HELP_TITLE;
} Lan
;

struct
{
  Lan lan;
  const unsigned int appid;
  bool steamb;
  bool cheatb;
  int achgenstart;
  int achgencustom;
  int achgenmode;
  int achgenpause;
  int achgenhelp;
  int achhidcheat;
  int achhidedge;
  int achhidmark;
  int achhidright;
  int achhidalive;
  int achcumdead1;
  int achcumdead10;
  int achcumdead100;
  int achcumdead1000;
  int achcumfour1;
  int achcumfour10;
  int achcumfour100;
  int achcumfour1000;
  int achcumline100;
  int achcumline300;
  int achcumline600;
  int achcumline1000;
  int achcumtotal10;
  int achcumtotal100;
  int achcumtotal1000;
  int achcumtotal10000;
  const char *achs[26];
  bool achb[26];
  int scrdead;
  int scrfour;
  int scrtotal;
  int scrline;
  int scrline1;
  int scrline2;
  int scrline3;
  int scrindexline;
  int scrindexmdb;
  int scrindexnomiss;
  int scrindextetris;
  int scrindexmiss;
  const char *scrs[19];
  int scr[19];
  bool newrecord;
  const char *leads[15];
  int leadk_[3];
  SteamAPICall_t lead[15];
  SteamAPICall_t lead_[3][15];
  LeaderboardFindResult_t leadr;
  LeaderboardScoreUploaded_t leadu;
  LeaderboardScoresDownloaded_t leadd;
  SteamLeaderboard_t leadb[15];
  SteamLeaderboardEntries_t leaden[3][15];
  bool leadfailed;
  LeaderboardEntry_t (*leadsn)[15][20];
  double waittime;
} Steam
;

struct
{
  unsigned int sSound[8];
  unsigned int *sMusic;
  const char *sSounds[8];
  int sWin;
  int sLose;
  int sError;
  int sLeft;
  int sRight;
  int sFlag;
  int sNew;
  int sSolve;
  int nummusic;
  bool soundb;
  bool musicb;
  int musici;
  double musictime;
} Sound
;

struct __cppobj : Block
{
  Steam st;
  Sound sd;
  double time;
  double time_;
  double pausetime;
  int mode;
  int mode_;
  bool sb;
  int rightb;
  bool aliveb;
  int maskj0;
  bool maskjb;
  int line;
  int level;
  bool solvebb;
  bool solveb0;
  bool solveb1;
  bool solveb2;
  bool solveb3;
  int checkr;
  bool dieb;
  int diex;
  int diey;
  int tetrisi;
  int missi;
  int missline;
  int bouns;
  int sum;
  int rx;
  int ry;
  int maxbdw;
  int maxbdh;
  int w_;
  int h_;
  int cred;
  __attribute__((aligned(8))) double mult;
  int delayb;
  int delayb__;
  int mdb;
  int mdb_;
  int mx;
  int my;
  int tutb;
  int tuti;
  int tutx[13];
  int tuty[13];
  int tutm[13];
  bool relaxb;
  Board::rule ruletemp;
  Board::rule *rulemain;
  int rulemainc;
  int (*blckrule)[128];
  int solven;
} Board
;

struct
{
  int x;
  int y;
  int numbc;
  int blckc;
  int blckx[8];
  int blcky[8];
} Board::rule
;

void *PVOID
;

const CHAR *PCSTR
;

struct
{
  DWORD dwLowDateTime;
  DWORD dwHighDateTime;
} _FILETIME
;

_FILETIME FILETIME
;

struct __attribute__((aligned(4)))
{
  DWORD dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD nFileSizeHigh;
  DWORD nFileSizeLow;
  DWORD dwReserved0;
  DWORD dwReserved1;
  CHAR cFileName[260];
  CHAR cAlternateFileName[14];
} _WIN32_FIND_DATAA
;

_WIN32_FIND_DATAA WIN32_FIND_DATAA
;

unsigned int __uintptr_t
;

__uintptr_t uintptr_t
;

struct __attribute__((packed)) __attribute__((aligned(2)))
{
  PCSTR NameInCabinet;
  DWORD FileSize;
  DWORD Win32Error;
  WORD DosDate;
  WORD DosTime;
  WORD DosAttribs;
  CHAR FullTargetName[260];
} _FILE_IN_CABINET_INFO_A
;

_FILE_IN_CABINET_INFO_A FILE_IN_CABINET_INFO_A
;

void *LPVOID
;

WCHAR *LPWSTR
;

const WCHAR *LPCWSTR
;

CHAR *LPSTR
;

__int64 LONGLONG
;

int LONG_PTR
;

unsigned int ULONG_PTR
;

union
{
  _LARGE_INTEGER::$F50D1B4661C66265C46503353F437A80 u;
  _LARGE_INTEGER::$F50D1B4661C66265C46503353F437A80 _anon_0;
  LONGLONG QuadPart;
} _LARGE_INTEGER
;

struct
{
  DWORD LowPart;
  LONG HighPart;
} _LARGE_INTEGER::$F50D1B4661C66265C46503353F437A80
;

_LARGE_INTEGER LARGE_INTEGER
;

UINT_PTR WPARAM
;

LONG_PTR LPARAM
;

LONG_PTR LRESULT
;

WORD ATOM
;

void *HGDIOBJ
;

struct
{
  int i;
} HBRUSH__
;

HBRUSH__ *HBRUSH
;

struct
{
  int i;
} HMONITOR__
;

HMONITOR__ *HMONITOR
;

struct
{
  int i;
} HPEN__
;

HPEN__ *HPEN
;

HICON HCURSOR
;

struct
{
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
} tagRECT
;

tagRECT RECT
;

tagRECT *LPRECT
;

struct
{
  LONG x;
  LONG y;
} tagPOINT
;

tagPOINT POINT
;

tagSIZE SIZE
;

DWORD (*LPTHREAD_START_ROUTINE)(LPVOID)
;

WIN32_FIND_DATAA WIN32_FIND_DATA
;

struct __attribute__((aligned(4)))
{
  LONG tmHeight;
  LONG tmAscent;
  LONG tmDescent;
  LONG tmInternalLeading;
  LONG tmExternalLeading;
  LONG tmAveCharWidth;
  LONG tmMaxCharWidth;
  LONG tmWeight;
  LONG tmOverhang;
  LONG tmDigitizedAspectX;
  LONG tmDigitizedAspectY;
  BYTE tmFirstChar;
  BYTE tmLastChar;
  BYTE tmDefaultChar;
  BYTE tmBreakChar;
  BYTE tmItalic;
  BYTE tmUnderlined;
  BYTE tmStruckOut;
  BYTE tmPitchAndFamily;
  BYTE tmCharSet;
} tagTEXTMETRICA
;

tagTEXTMETRICA TEXTMETRICA
;

TEXTMETRICA TEXTMETRIC
;

struct
{
  BYTE BlendOp;
  BYTE BlendFlags;
  BYTE SourceConstantAlpha;
  BYTE AlphaFormat;
} _BLENDFUNCTION
;

_BLENDFUNCTION BLENDFUNCTION
;

LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM)
;

struct
{
  HWND hwnd;
  UINT message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD time;
  POINT pt;
} tagMSG
;

tagMSG MSG
;

struct
{
  UINT style;
  WNDPROC lpfnWndProc;
  int cbClsExtra;
  int cbWndExtra;
  HINSTANCE hInstance;
  HICON hIcon;
  HCURSOR hCursor;
  HBRUSH hbrBackground;
  LPCWSTR lpszMenuName;
  LPCWSTR lpszClassName;
} _WNDCLASSW
;

_WNDCLASSW WNDCLASSW
;

struct
{
  DWORD cbSize;
  RECT rcMonitor;
  RECT rcWork;
  DWORD dwFlags;
} tagMONITORINFO
;

struct __cppobj : tagMONITORINFO
{
  CHAR szDevice[32];
} tagMONITORINFOEXA
;

tagMONITORINFOEXA MONITORINFOEXA
;

MONITORINFOEXA MONITORINFOEX
;

enum : __int32
{
  DebugEventLevelFatal = 0x0,
  DebugEventLevelWarning = 0x1,
} Gdiplus::DebugEventLevel
;

struct
{
  UINT32 GdiplusVersion;
  Gdiplus::DebugEventProc DebugEventCallback;
  BOOL SuppressBackgroundThread;
  BOOL SuppressExternalCodecs;
} Gdiplus::GdiplusStartupInput
;

void (*Gdiplus::DebugEventProc)(Gdiplus::DebugEventLevel, CHAR *)
;

unsigned __int8 uint8_t
;

unsigned __int16 uint16_t
;

unsigned int uint32_t
;

unsigned __int64 uint64_t
;

struct
{
  HGDIOBJ Handle;
  HDC DC;
  unsigned int Width;
  unsigned int Height;
  unsigned int Color;
} bitmap
;

bitmap *pbitmap
;

struct
{
  int i;
} HKEY__
;

HKEY__ *HKEY
;

struct
{
  HKEY regkey;
  HKEY regkey_;
  DWORD tp;
  DWORD cb;
} Reg
;

DWORD MCIERROR
;

struct ISteamUtils
;

struct ISteamUserStats
;

struct ISteamApps
;

struct ISteamScreenshots
;

enum : __int32
{
  k_ELeaderboardDataRequestGlobal = 0x0,
  k_ELeaderboardDataRequestGlobalAroundUser = 0x1,
  k_ELeaderboardDataRequestFriends = 0x2,
  k_ELeaderboardDataRequestUsers = 0x3,
} ELeaderboardDataRequest
;

enum : __int32
{
  k_ELeaderboardUploadScoreMethodNone = 0x0,
  k_ELeaderboardUploadScoreMethodKeepBest = 0x1,
  k_ELeaderboardUploadScoreMethodForceUpdate = 0x2,
} ELeaderboardUploadScoreMethod
;

enum : __int32
{
  k_iCallback = 0x450,
} LeaderboardFindResult_t::$AA49D4492348A3652E71D178FD63F88F
;

enum : __int32
{
  k_iCallback_0 = 0x451,
} LeaderboardScoresDownloaded_t::$623235E806E9F94CEBD51DF257DE8812
;

enum : __int32
{
  k_iCallback_1 = 0x452,
} LeaderboardScoreUploaded_t::$118FF6102C7A10A86A1B55C5C2347B22
;

struct
{
  _LIST_ENTRY *Flink;
  _LIST_ENTRY *Blink;
} _LIST_ENTRY
;

_LIST_ENTRY LIST_ENTRY
;

struct
{
  WORD Type;
  WORD CreatorBackTraceIndex;
  _CRITICAL_SECTION *CriticalSection;
  LIST_ENTRY ProcessLocksList;
  DWORD EntryCount;
  DWORD ContentionCount;
  DWORD Spare[2];
} _CRITICAL_SECTION_DEBUG
;

struct
{
  PCRITICAL_SECTION_DEBUG DebugInfo;
  LONG LockCount;
  LONG RecursionCount;
  HANDLE OwningThread;
  HANDLE LockSemaphore;
  DWORD SpinCount;
} _CRITICAL_SECTION
;

_CRITICAL_SECTION_DEBUG *PCRITICAL_SECTION_DEBUG
;

_CRITICAL_SECTION CRITICAL_SECTION
;

LOGFONTA LOGFONT
;

struct
{
  UINT length;
  UINT flags;
  UINT showCmd;
  POINT ptMinPosition;
  POINT ptMaxPosition;
  RECT rcNormalPosition;
} _WINDOWPLACEMENT
;

_WINDOWPLACEMENT WINDOWPLACEMENT
;

int __time32_t
;

__time32_t time_t
;

struct
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
} tm
;

struct ISteamFriends
;

struct ISteamRemoteStorage
;

struct
{
  const int launchw;
  const int launchh;
  const int titlew;
  const int titleh;
  const int menuw;
  const int menuh;
  const int facew;
  const int faceh;
  const int iconw;
  const int iconh;
  const int digtw[3];
  const int digth[3];
  const int okw;
  const int okh;
  const int btnw;
  const int btnh;
  const int tutw;
  const int tuth;
  const int aboutw;
  const int abouth;
  const int helpw;
  const int helph;
  const int fontth;
  const int fontfh;
  const int fonth;
  const int fontsh;
  const int fontmh;
  const int okh_;
  const int cursorw;
  const int cursorh;
  const int clickw;
  const int clickh;
  const int arroww;
  const int arrowh;
  pbitmap ptitle_;
  pbitmap pbg_;
  pbitmap pmenu_;
  pbitmap pmenu1[2];
  pbitmap pmenu2[2];
  pbitmap pmenu3[2];
  pbitmap pmenuq[2];
  pbitmap pmenua[2];
  pbitmap pmenus[2];
  pbitmap pmenum[2];
  pbitmap pmenut[2];
  pbitmap pmenud[2];
  pbitmap pmenun[2];
  pbitmap pmenug[7][2];
  pbitmap pface_;
  pbitmap pface[9];
  pbitmap picon_;
  pbitmap picon[11];
  pbitmap piconc;
  pbitmap piconq;
  pbitmap piconf;
  pbitmap piconm;
  pbitmap picone;
  pbitmap piconn;
  pbitmap piconp;
  pbitmap picona;
  pbitmap piconu;
  pbitmap pdigt_[3];
  pbitmap pdigt[10][3];
  pbitmap pdigtmin[3];
  pbitmap pdigtnul[3];
  pbitmap pok_;
  pbitmap pok;
  pbitmap pbtn;
  pbitmap pcursor_;
  pbitmap pcursor;
  pbitmap pclick_;
  pbitmap pclickl;
  pbitmap pclickr;
  pbitmap pclickn;
  pbitmap pclicka;
  pbitmap parrow_;
  pbitmap parrowl;
  pbitmap parrowr;
  pbitmap parrowu;
  pbitmap parrowd;
  pbitmap parrowm;
  pbitmap parrowp;
  const int transparent;
  int color[9];
  int colori;
  int cfg;
  int cbg;
  int ctfg;
  int ctbg;
  int cred;
  int cblue;
  int cgreen;
  int cline;
  int cmine;
  int transparent_;
  bool isbmp;
  Reg reg;
  HICON hicon_res;
  HICON hicon_file;
  HICON hicon;
  Board bd;
  Block bl;
  const int maxhelp;
  int helpi;
  bool helpb;
  bool cheatb;
  bool waitb;
  pbitmap pwin;
  pbitmap pwint;
  const int minh;
  const int minw;
  int mult_;
  __attribute__((aligned(8))) double mult;
  WINDOWPLACEMENT wn;
  bool showmax;
  bool showmax_;
  int w_;
  int h_;
  int x_;
  int y_;
  RECT rect;
  int xscr;
  int yscr;
  int wscr;
  int hscr;
  bool barb;
  int md;
  bool ml;
  bool mr;
  int mx;
  int my;
  bool mi;
  int lead_5;
  bool singleb;
  int boardb;
  __attribute__((aligned(8))) double timerefresh;
  CRITICAL_SECTION cs;
} Window
;

struct
{
  int val[25];
  char flag[16384];
  char qstn[16384];
  char mine[16384];
  char blck[16384];
  char mask[16384];
} Window::saveboardcloud::$37121DBF79074B1A503FB94F3890690D
;

struct
{
  int val[25];
  char flag[16384];
  char qstn[16384];
  char mine[16384];
  char blck[16384];
  char mask[16384];
} Window::loadboardcloud::$37121DBF79074B1A503FB94F3890690D
;

unsigned int hashval_t
;

hashval_t (*htab_hash)(const void *)
;

int (*htab_eq)(const void *, const void *)
;

enum : __int32
{
  no_stringop = 0x0,
  libcall = 0x1,
  rep_prefix_1_byte = 0x2,
  rep_prefix_4_byte = 0x3,
  rep_prefix_8_byte = 0x4,
  loop_1_byte = 0x5,
  loop = 0x6,
  unrolled_loop = 0x7,
  vector_loop = 0x8,
  last_alg = 0x9,
} stringop_alg
;

struct
{
  const int max;
  const stringop_alg alg;
  int noalign;
} stringop_strategy
;

struct
{
  const stringop_alg unknown_size;
  const stringop_strategy size[4];
} stringop_algs
;

struct
{
  const int add;
  const int lea;
  const int shift_var;
  const int shift_const;
  const int mult_init[5];
  const int mult_bit;
  const int divide[5];
  int movsx;
  int movzx;
  const int large_insn;
  const int move_ratio;
  const int movzbl_load;
  const int int_load[3];
  const int int_store[3];
  const int fp_move;
  const int fp_load[3];
  const int fp_store[3];
  const int mmx_move;
  const int mmx_load[2];
  const int mmx_store[2];
  const int sse_move;
  const int sse_load[3];
  const int sse_store[3];
  const int mmxsse_to_integer;
  const int l1_cache_size;
  const int l2_cache_size;
  const int prefetch_block;
  const int simultaneous_prefetches;
  const int branch_cost;
  const int fadd;
  const int fmul;
  const int fdiv;
  const int fabs;
  const int fchs;
  const int fsqrt;
  stringop_algs *memcpy;
  stringop_algs *memset;
  const int scalar_stmt_cost;
  const int scalar_load_cost;
  const int scalar_store_cost;
  const int vec_stmt_cost;
  const int vec_to_scalar_cost;
  const int scalar_to_vec_cost;
  const int vec_align_load_cost;
  const int vec_unalign_load_cost;
  const int vec_store_cost;
  const int cond_taken_branch_cost;
  const int cond_not_taken_branch_cost;
} processor_costs
;

enum : __int32
{
  X86_TUNE_SCHEDULE = 0x0,
  X86_TUNE_PARTIAL_REG_DEPENDENCY = 0x1,
  X86_TUNE_SSE_PARTIAL_REG_DEPENDENCY = 0x2,
  X86_TUNE_SSE_SPLIT_REGS = 0x3,
  X86_TUNE_PARTIAL_FLAG_REG_STALL = 0x4,
  X86_TUNE_MOVX = 0x5,
  X86_TUNE_MEMORY_MISMATCH_STALL = 0x6,
  X86_TUNE_FUSE_CMP_AND_BRANCH_32 = 0x7,
  X86_TUNE_FUSE_CMP_AND_BRANCH_64 = 0x8,
  X86_TUNE_FUSE_CMP_AND_BRANCH_SOFLAGS = 0x9,
  X86_TUNE_FUSE_ALU_AND_BRANCH = 0xA,
  X86_TUNE_REASSOC_INT_TO_PARALLEL = 0xB,
  X86_TUNE_REASSOC_FP_TO_PARALLEL = 0xC,
  X86_TUNE_ACCUMULATE_OUTGOING_ARGS = 0xD,
  X86_TUNE_PROLOGUE_USING_MOVE = 0xE,
  X86_TUNE_EPILOGUE_USING_MOVE = 0xF,
  X86_TUNE_USE_LEAVE = 0x10,
  X86_TUNE_PUSH_MEMORY = 0x11,
  X86_TUNE_SINGLE_PUSH = 0x12,
  X86_TUNE_DOUBLE_PUSH = 0x13,
  X86_TUNE_SINGLE_POP = 0x14,
  X86_TUNE_DOUBLE_POP = 0x15,
  X86_TUNE_PAD_SHORT_FUNCTION = 0x16,
  X86_TUNE_PAD_RETURNS = 0x17,
  X86_TUNE_FOUR_JUMP_LIMIT = 0x18,
  X86_TUNE_SOFTWARE_PREFETCHING_BENEFICIAL = 0x19,
  X86_TUNE_LCP_STALL = 0x1A,
  X86_TUNE_READ_MODIFY = 0x1B,
  X86_TUNE_USE_INCDEC = 0x1C,
  X86_TUNE_INTEGER_DFMODE_MOVES = 0x1D,
  X86_TUNE_OPT_AGU = 0x1E,
  X86_TUNE_AVOID_LEA_FOR_ADDR = 0x1F,
  X86_TUNE_SLOW_IMUL_IMM32_MEM = 0x20,
  X86_TUNE_SLOW_IMUL_IMM8 = 0x21,
  X86_TUNE_AVOID_MEM_OPND_FOR_CMOVE = 0x22,
  X86_TUNE_SINGLE_STRINGOP = 0x23,
  X86_TUNE_MISALIGNED_MOVE_STRING_PRO_EPILOGUES = 0x24,
  X86_TUNE_USE_SAHF = 0x25,
  X86_TUNE_USE_CLTD = 0x26,
  X86_TUNE_USE_BT = 0x27,
  X86_TUNE_USE_HIMODE_FIOP = 0x28,
  X86_TUNE_USE_SIMODE_FIOP = 0x29,
  X86_TUNE_USE_FFREEP = 0x2A,
  X86_TUNE_EXT_80387_CONSTANTS = 0x2B,
  X86_TUNE_VECTORIZE_DOUBLE = 0x2C,
  X86_TUNE_GENERAL_REGS_SSE_SPILL = 0x2D,
  X86_TUNE_SSE_UNALIGNED_LOAD_OPTIMAL = 0x2E,
  X86_TUNE_SSE_UNALIGNED_STORE_OPTIMAL = 0x2F,
  X86_TUNE_SSE_PACKED_SINGLE_INSN_OPTIMAL = 0x30,
  X86_TUNE_SSE_TYPELESS_STORES = 0x31,
  X86_TUNE_SSE_LOAD0_BY_PXOR = 0x32,
  X86_TUNE_INTER_UNIT_MOVES_TO_VEC = 0x33,
  X86_TUNE_INTER_UNIT_MOVES_FROM_VEC = 0x34,
  X86_TUNE_INTER_UNIT_CONVERSIONS = 0x35,
  X86_TUNE_SPLIT_MEM_OPND_FOR_FP_CONVERTS = 0x36,
  X86_TUNE_USE_VECTOR_FP_CONVERTS = 0x37,
  X86_TUNE_USE_VECTOR_CONVERTS = 0x38,
  X86_TUNE_SLOW_PSHUFB = 0x39,
  X86_TUNE_VECTOR_PARALLEL_EXECUTION = 0x3A,
  X86_TUNE_AVOID_4BYTE_PREFIXES = 0x3B,
  X86_TUNE_AVX256_UNALIGNED_LOAD_OPTIMAL = 0x3C,
  X86_TUNE_AVX256_UNALIGNED_STORE_OPTIMAL = 0x3D,
  X86_TUNE_AVX128_OPTIMAL = 0x3E,
  X86_TUNE_DOUBLE_WITH_ADD = 0x3F,
  X86_TUNE_ALWAYS_FANCY_MATH_387 = 0x40,
  X86_TUNE_UNROLL_STRLEN = 0x41,
  X86_TUNE_SHIFT1 = 0x42,
  X86_TUNE_ZERO_EXTEND_WITH_AND = 0x43,
  X86_TUNE_PROMOTE_HIMODE_IMUL = 0x44,
  X86_TUNE_FAST_PREFIX = 0x45,
  X86_TUNE_READ_MODIFY_WRITE = 0x46,
  X86_TUNE_MOVE_M1_VIA_OR = 0x47,
  X86_TUNE_NOT_UNPAIRABLE = 0x48,
  X86_TUNE_PARTIAL_REG_STALL = 0x49,
  X86_TUNE_PROMOTE_QIMODE = 0x4A,
  X86_TUNE_PROMOTE_HI_REGS = 0x4B,
  X86_TUNE_HIMODE_MATH = 0x4C,
  X86_TUNE_SPLIT_LONG_MOVES = 0x4D,
  X86_TUNE_USE_XCHGB = 0x4E,
  X86_TUNE_USE_MOV0 = 0x4F,
  X86_TUNE_NOT_VECTORMODE = 0x50,
  X86_TUNE_AVOID_VECTOR_DECODE = 0x51,
  X86_TUNE_AVOID_FALSE_DEP_FOR_BMI = 0x52,
  X86_TUNE_BRANCH_PREDICTION_HINTS = 0x53,
  X86_TUNE_QIMODE_MATH = 0x54,
  X86_TUNE_PROMOTE_QI_REGS = 0x55,
  X86_TUNE_ADJUST_UNROLL = 0x56,
  X86_TUNE_ONE_IF_CONV_INSN = 0x57,
  X86_TUNE_LAST = 0x58,
} ix86_tune_indices
;

enum : __int32
{
  X86_ARCH_CMOV = 0x0,
  X86_ARCH_CMPXCHG = 0x1,
  X86_ARCH_CMPXCHG8B = 0x2,
  X86_ARCH_XADD = 0x3,
  X86_ARCH_BSWAP = 0x4,
  X86_ARCH_LAST = 0x5,
} ix86_arch_indices
;

union _dont_use_tree_here_
;

enum : __int32
{
  NO_REGS = 0x0,
  AREG = 0x1,
  DREG = 0x2,
  CREG = 0x3,
  BREG = 0x4,
  SIREG = 0x5,
  DIREG = 0x6,
  AD_REGS = 0x7,
  CLOBBERED_REGS = 0x8,
  Q_REGS = 0x9,
  NON_Q_REGS = 0xA,
  INDEX_REGS = 0xB,
  LEGACY_REGS = 0xC,
  GENERAL_REGS = 0xD,
  FP_TOP_REG = 0xE,
  FP_SECOND_REG = 0xF,
  FLOAT_REGS = 0x10,
  SSE_FIRST_REG = 0x11,
  NO_REX_SSE_REGS = 0x12,
  SSE_REGS = 0x13,
  EVEX_SSE_REGS = 0x14,
  BND_REGS = 0x15,
  ALL_SSE_REGS = 0x16,
  MMX_REGS = 0x17,
  FP_TOP_SSE_REGS = 0x18,
  FP_SECOND_SSE_REGS = 0x19,
  FLOAT_SSE_REGS = 0x1A,
  FLOAT_INT_REGS = 0x1B,
  INT_SSE_REGS = 0x1C,
  FLOAT_INT_SSE_REGS = 0x1D,
  MASK_EVEX_REGS = 0x1E,
  MASK_REGS = 0x1F,
  ALL_REGS = 0x20,
  LIM_REG_CLASSES = 0x21,
} reg_class
;

enum : __int32
{
  PROCESSOR_GENERIC = 0x0,
  PROCESSOR_I386 = 0x1,
  PROCESSOR_I486 = 0x2,
  PROCESSOR_PENTIUM = 0x3,
  PROCESSOR_LAKEMONT = 0x4,
  PROCESSOR_PENTIUMPRO = 0x5,
  PROCESSOR_PENTIUM4 = 0x6,
  PROCESSOR_NOCONA = 0x7,
  PROCESSOR_CORE2 = 0x8,
  PROCESSOR_NEHALEM = 0x9,
  PROCESSOR_SANDYBRIDGE = 0xA,
  PROCESSOR_HASWELL = 0xB,
  PROCESSOR_BONNELL = 0xC,
  PROCESSOR_SILVERMONT = 0xD,
  PROCESSOR_KNL = 0xE,
  PROCESSOR_SKYLAKE_AVX512 = 0xF,
  PROCESSOR_INTEL = 0x10,
  PROCESSOR_GEODE = 0x11,
  PROCESSOR_K6 = 0x12,
  PROCESSOR_ATHLON = 0x13,
  PROCESSOR_K8 = 0x14,
  PROCESSOR_AMDFAM10 = 0x15,
  PROCESSOR_BDVER1 = 0x16,
  PROCESSOR_BDVER2 = 0x17,
  PROCESSOR_BDVER3 = 0x18,
  PROCESSOR_BDVER4 = 0x19,
  PROCESSOR_BTVER1 = 0x1A,
  PROCESSOR_BTVER2 = 0x1B,
  PROCESSOR_ZNVER1 = 0x1C,
  PROCESSOR_max = 0x1D,
} processor_type
;

unsigned __int8 UQItype
;

struct
{
  float real;
  float imag;
} complex_float
;

struct
{
  double real;
  double imag;
} complex_double
;

struct
{
  long double real;
  long double imag;
} complex_long_double
;

long double __float128
;

struct
{
  long double real;
  __attribute__((aligned(8))) long double imag;
} $3ED12439BC76F86861D3C63DAB91FFAC
;

void (*func_ptr)(void)
;

struct
{
  PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
  LONG LockCount;
  LONG RecursionCount;
  HANDLE OwningThread;
  HANDLE LockSemaphore;
  DWORD SpinCount;
} _RTL_CRITICAL_SECTION
;

_RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG
;

struct
{
  WORD Type;
  WORD CreatorBackTraceIndex;
  _RTL_CRITICAL_SECTION *CriticalSection;
  LIST_ENTRY ProcessLocksList;
  DWORD EntryCount;
  DWORD ContentionCount;
  DWORD Spare[2];
} _RTL_CRITICAL_SECTION_DEBUG
;

struct
{
  PVOID BaseAddress;
  PVOID AllocationBase;
  DWORD AllocationProtect;
  SIZE_T RegionSize;
  DWORD State;
  DWORD Protect;
  DWORD Type;
} _MEMORY_BASIC_INFORMATION
;

UINT_PTR SIZE_T
;

struct
{
  DWORD cb;
  LPSTR lpReserved;
  LPSTR lpDesktop;
  LPSTR lpTitle;
  DWORD dwX;
  DWORD dwY;
  DWORD dwXSize;
  DWORD dwYSize;
  DWORD dwXCountChars;
  DWORD dwYCountChars;
  DWORD dwFillAttribute;
  DWORD dwFlags;
  WORD wShowWindow;
  WORD cbReserved2;
  LPBYTE lpReserved2;
  HANDLE hStdInput;
  HANDLE hStdOutput;
  HANDLE hStdError;
} _STARTUPINFOA
;

