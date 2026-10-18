struct
{
  PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
  LONG LockCount;
  LONG RecursionCount;
  HANDLE OwningThread;
  HANDLE LockSemaphore;
  ULONG_PTR SpinCount;
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
  DWORD Flags;
  WORD CreatorBackTraceIndexHigh;
  WORD SpareWORD;
} _RTL_CRITICAL_SECTION_DEBUG
;

unsigned __int16 WORD
;

_LIST_ENTRY LIST_ENTRY
;

struct
{
  _LIST_ENTRY *Flink;
  _LIST_ENTRY *Blink;
} _LIST_ENTRY
;

unsigned int DWORD
;

int LONG
;

void *HANDLE
;

unsigned int ULONG_PTR
;

struct
{
  LONG x;
  LONG y;
} tagPOINT
;

struct
{
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
} tagRECT
;

struct
{
  DWORD cbSize;
  RECT rcMonitor;
  RECT rcWork;
  DWORD dwFlags;
} tagMONITORINFO
;

tagRECT RECT
;

tagWNDCLASSW WNDCLASSW
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
} tagWNDCLASSW
;

unsigned int UINT
;

LRESULT (__stdcall *WNDPROC)(HWND, UINT, WPARAM, LPARAM)
;

HWND__ *HWND
;

struct
{
  int unused;
} HWND__
;

UINT_PTR WPARAM
;

unsigned int UINT_PTR
;

LONG_PTR LPARAM
;

int LONG_PTR
;

LONG_PTR LRESULT
;

HINSTANCE__ *HINSTANCE
;

struct
{
  int unused;
} HINSTANCE__
;

HICON__ *HICON
;

struct
{
  int unused;
} HICON__
;

HICON HCURSOR
;

HBRUSH__ *HBRUSH
;

struct
{
  int unused;
} HBRUSH__
;

const WCHAR *LPCWSTR
;

wchar_t WCHAR
;

unsigned __int16 wchar_t
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

tagPOINT POINT
;

tagMSG MSG
;

struct
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

_FILETIME FILETIME
;

struct
{
  DWORD dwLowDateTime;
  DWORD dwHighDateTime;
} _FILETIME
;

char CHAR
;

struct
{
  LONG cx;
  LONG cy;
} tagSIZE
;

struct
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

unsigned __int8 BYTE
;

_LARGE_INTEGER LARGE_INTEGER
;

union
{
  _LARGE_INTEGER::$837407842DC9087486FDFA5FEB63B74E s;
  _LARGE_INTEGER::$837407842DC9087486FDFA5FEB63B74E u;
  LONGLONG QuadPart;
} _LARGE_INTEGER
;

struct
{
  DWORD LowPart;
  LONG HighPart;
} _LARGE_INTEGER::$837407842DC9087486FDFA5FEB63B74E
;

__int64 LONGLONG
;

_BLENDFUNCTION BLENDFUNCTION
;

struct
{
  BYTE BlendOp;
  BYTE BlendFlags;
  BYTE SourceConstantAlpha;
  BYTE AlphaFormat;
} _BLENDFUNCTION
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

void *PVOID
;

ULONG_PTR SIZE_T
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

CHAR *LPSTR
;

BYTE *LPBYTE
;

