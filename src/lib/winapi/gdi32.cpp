#include <winapi/gdi32.h>
#include <x86.h>
#include <SDL_video.h>

namespace win32 { namespace gdi32
{

int GetDeviceCaps(WinApplication* app, x86::CPU& cpu, HDC hdc, int index)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hdc);
    SDL_DisplayMode mode{};
    SDL_GetDesktopDisplayMode(0, &mode);
    switch (index)
    {
    case 8:   return mode.w;                    // HORZRES
    case 10:  return mode.h;                    // VERTRES
    case 12:  return 32;                        // BITSPIXEL
    case 14:  return 1;                         // PLANES
    case 88:
    case 90:  return 96;                        // LOGPIXELSX / LOGPIXELSY
    case 116: return mode.refresh_rate ? mode.refresh_rate : 60;  // VREFRESH
    default:  return 0;
    }
}

HGDIOBJ GetStockObject(WinApplication* app, x86::CPU& cpu, int i)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(i);
    return 0xffffffff;
}

}}
