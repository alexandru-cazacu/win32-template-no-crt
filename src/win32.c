#define _WIN32_WINNT 0x0601 // Targets Windows 7 or later
#include <sdkddkver.h>

// Disables unused Windows functions and makes build times faster.
// Commented out the functions we actually need.

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef WIN32_EXTRA_LEAN
#define WIN32_EXTRA_LEAN // TODO(alex): Check if it really does something in Windows.h
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN // Only for MFC, but who knows.
#endif

#define NOGDICAPMASKS
#define NOSYSMETRICS
#define NOMENUS
//#define NOICONS
#define NOSYSCOMMANDS
#define NORASTEROPS
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
//#define NOCTLMGR
#define NODRAWTEXT
#define NOKERNEL
#define NONLS
#define NOMEMMGR
#define NOMETAFILE
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX
#define NORPC
#define NOPROXYSTUB
#define NOIMAGE
#define NOTAPE
#define NOMINMAX
#define STRICT

#include <windows.h>
#include <windowsx.h>
#include <dwmapi.h>