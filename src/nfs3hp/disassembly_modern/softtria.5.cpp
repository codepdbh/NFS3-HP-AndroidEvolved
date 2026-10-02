#include "softtria.h"
#include <lib/thread.h>

namespace softtria
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9ca40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca40  ff25f0cda900           -jmp dword ptr [0xa9cdf0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128304), cpu);
}

/* align: skip  */
void sub_a9ca46(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca46  ff25c0cda900           -jmp dword ptr [0xa9cdc0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128256), cpu);
}

/* align: skip  */
void sub_a9ca4c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca4c  ff25bccda900           -jmp dword ptr [0xa9cdbc]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128252), cpu);
}

/* align: skip  */
void sub_a9ca52(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca52  ff25e8cda900           -jmp dword ptr [0xa9cde8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128296), cpu);
}

/* align: skip  */
void sub_a9ca58(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca58  ff2504cea900           -jmp dword ptr [0xa9ce04]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128324), cpu);
}

/* align: skip  */
void sub_a9ca5e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca5e  ff25d4cda900           -jmp dword ptr [0xa9cdd4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128276), cpu);
}

/* align: skip  */
void sub_a9ca64(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca64  ff25a4cda900           -jmp dword ptr [0xa9cda4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128228), cpu);
}

/* align: skip  */
void sub_a9ca6a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca6a  ff251ccea900           -jmp dword ptr [0xa9ce1c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128348), cpu);
}

/* align: skip  */
void sub_a9ca70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca70  ff2578cda900           -jmp dword ptr [0xa9cd78]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128184), cpu);
}

/* align: skip  */
void sub_a9ca76(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca76  ff256ccda900           -jmp dword ptr [0xa9cd6c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128172), cpu);
}

/* align: skip  */
void sub_a9ca7c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca7c  ff2570cda900           -jmp dword ptr [0xa9cd70]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128176), cpu);
}

/* align: skip  */
void sub_a9ca82(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca82  ff2588cda900           -jmp dword ptr [0xa9cd88]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128200), cpu);
}

/* align: skip  */
void sub_a9ca88(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca88  ff2564cea900           -jmp dword ptr [0xa9ce64]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128420), cpu);
}

/* align: skip  */
void sub_a9ca8e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca8e  ff257ccda900           -jmp dword ptr [0xa9cd7c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128188), cpu);
}

/* align: skip  */
void sub_a9ca94(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca94  ff2580cda900           -jmp dword ptr [0xa9cd80]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128192), cpu);
}

/* align: skip  */
void sub_a9ca9a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca9a  ff258ccda900           -jmp dword ptr [0xa9cd8c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128204), cpu);
}

/* align: skip  */
void sub_a9caa0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9caa0  ff255ccea900           -jmp dword ptr [0xa9ce5c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128412), cpu);
}

/* align: skip  */
void sub_a9caa6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9caa6  ff2554cea900           -jmp dword ptr [0xa9ce54]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128404), cpu);
}

/* align: skip  */
void sub_a9caac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9caac  ff252ccea900           -jmp dword ptr [0xa9ce2c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128364), cpu);
}

/* align: skip  */
void sub_a9cab2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cab2  ff2500cea900           -jmp dword ptr [0xa9ce00]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128320), cpu);
}

/* align: skip  */
void sub_a9cab8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cab8  ff2528cea900           -jmp dword ptr [0xa9ce28]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128360), cpu);
}

/* align: skip  */
void sub_a9cabe(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cabe  ff25a8cda900           -jmp dword ptr [0xa9cda8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128232), cpu);
}

/* align: skip  */
void sub_a9cac4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cac4  ff2594cda900           -jmp dword ptr [0xa9cd94]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128212), cpu);
}

/* align: skip  */
void sub_a9caca(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9caca  ff25d0cda900           -jmp dword ptr [0xa9cdd0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128272), cpu);
}

/* align: skip  */
void sub_a9cad0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cad0  ff259ccda900           -jmp dword ptr [0xa9cd9c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128220), cpu);
}

/* align: skip  */
void sub_a9cad6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cad6  ff25c4cda900           -jmp dword ptr [0xa9cdc4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128260), cpu);
}

/* align: skip  */
void sub_a9cadc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cadc  ff25e0cda900           -jmp dword ptr [0xa9cde0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128288), cpu);
}

/* align: skip  */
void sub_a9cae2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cae2  ff2514cea900           -jmp dword ptr [0xa9ce14]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128340), cpu);
}

/* align: skip  */
void sub_a9cae8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cae8  ff25d8cda900           -jmp dword ptr [0xa9cdd8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128280), cpu);
}

/* align: skip  */
void sub_a9caee(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9caee  ff25dccda900           -jmp dword ptr [0xa9cddc]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128284), cpu);
}

/* align: skip  */
void sub_a9caf4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9caf4  ff2568cda900           -jmp dword ptr [0xa9cd68]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128168), cpu);
}

/* align: skip  */
void sub_a9cafa(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cafa  ff2524cea900           -jmp dword ptr [0xa9ce24]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128356), cpu);
}

/* align: skip  */
void sub_a9cb00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb00  ff25b8cda900           -jmp dword ptr [0xa9cdb8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128248), cpu);
}

/* align: skip  */
void sub_a9cb06(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb06  ff25f4cda900           -jmp dword ptr [0xa9cdf4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128308), cpu);
}

/* align: skip  */
void sub_a9cb0c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb0c  ff25b4cda900           -jmp dword ptr [0xa9cdb4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128244), cpu);
}

/* align: skip  */
void sub_a9cb12(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb12  ff2520cea900           -jmp dword ptr [0xa9ce20]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128352), cpu);
}

/* align: skip  */
void sub_a9cb18(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb18  ff2590cda900           -jmp dword ptr [0xa9cd90]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128208), cpu);
}

/* align: skip  */
void sub_a9cb1e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb1e  ff25c8cda900           -jmp dword ptr [0xa9cdc8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128264), cpu);
}

/* align: skip  */
void sub_a9cb24(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb24  ff2574cda900           -jmp dword ptr [0xa9cd74]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128180), cpu);
}

/* align: skip  */
void sub_a9cb2a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb2a  ff2558cea900           -jmp dword ptr [0xa9ce58]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128408), cpu);
}

/* align: skip  */
void sub_a9cb30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb30  ff2568cea900           -jmp dword ptr [0xa9ce68]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128424), cpu);
}

/* align: skip  */
void sub_a9cb36(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb36  ff253ccea900           -jmp dword ptr [0xa9ce3c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128380), cpu);
}

/* align: skip  */
void sub_a9cb3c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb3c  ff2550cea900           -jmp dword ptr [0xa9ce50]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128400), cpu);
}

/* align: skip  */
void sub_a9cb42(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb42  ff25f8cda900           -jmp dword ptr [0xa9cdf8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128312), cpu);
}

/* align: skip  */
void sub_a9cb48(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb48  ff2510cea900           -jmp dword ptr [0xa9ce10]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128336), cpu);
}

/* align: skip  */
void sub_a9cb4e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb4e  ff2560cea900           -jmp dword ptr [0xa9ce60]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128416), cpu);
}

/* align: skip  */
void sub_a9cb54(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb54  ff2518cea900           -jmp dword ptr [0xa9ce18]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128344), cpu);
}

/* align: skip  */
void sub_a9cb5a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb5a  ff25eccda900           -jmp dword ptr [0xa9cdec]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128300), cpu);
}

/* align: skip  */
void sub_a9cb60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb60  ff2544cea900           -jmp dword ptr [0xa9ce44]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128388), cpu);
}

/* align: skip  */
void sub_a9cb66(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb66  ff254ccea900           -jmp dword ptr [0xa9ce4c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128396), cpu);
}

/* align: skip  */
void sub_a9cb6c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb6c  ff2540cea900           -jmp dword ptr [0xa9ce40]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128384), cpu);
}

/* align: skip  */
void sub_a9cb72(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb72  ff2534cea900           -jmp dword ptr [0xa9ce34]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128372), cpu);
}

/* align: skip  */
void sub_a9cb78(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb78  ff2548cea900           -jmp dword ptr [0xa9ce48]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128392), cpu);
}

/* align: skip  */
void sub_a9cb7e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb7e  ff25e4cda900           -jmp dword ptr [0xa9cde4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128292), cpu);
}

/* align: skip  */
void sub_a9cb84(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb84  ff250ccea900           -jmp dword ptr [0xa9ce0c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128332), cpu);
}

/* align: skip  */
void sub_a9cb8a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb8a  ff25a0cda900           -jmp dword ptr [0xa9cda0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128224), cpu);
}

/* align: skip  */
void sub_a9cb90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb90  ff25cccda900           -jmp dword ptr [0xa9cdcc]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128268), cpu);
}

/* align: skip  */
void sub_a9cb96(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb96  ff2598cda900           -jmp dword ptr [0xa9cd98]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128216), cpu);
}

/* align: skip  */
void sub_a9cb9c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cb9c  ff2508cea900           -jmp dword ptr [0xa9ce08]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128328), cpu);
}

/* align: skip  */
void sub_a9cba2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cba2  ff25fccda900           -jmp dword ptr [0xa9cdfc]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128316), cpu);
}

/* align: skip  */
void sub_a9cba8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cba8  ff2538cea900           -jmp dword ptr [0xa9ce38]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128376), cpu);
}

/* align: skip  */
void sub_a9cbae(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cbae  ff25accda900           -jmp dword ptr [0xa9cdac]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128236), cpu);
}

/* align: skip  */
void sub_a9cbb4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cbb4  ff2530cea900           -jmp dword ptr [0xa9ce30]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128368), cpu);
}

/* align: skip  */
void sub_a9cbba(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cbba  ff256ccea900           -jmp dword ptr [0xa9ce6c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128428), cpu);
}

/* align: skip  */
void sub_a9cbc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cbc0  ff25b0cda900           -jmp dword ptr [0xa9cdb0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128240), cpu);
}

/* align: skip  */
void sub_a9cbc6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cbc6  ff2578cea900           -jmp dword ptr [0xa9ce78]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128440), cpu);
}

/* align: skip  */
void sub_a9cbcc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cbcc  ff2574cea900           -jmp dword ptr [0xa9ce74]
    return app->dynamic_call(app->getMemory<x86::reg32>(11128436), cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9cbe0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9cbe0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbe2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbe4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbe6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbe8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbf0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbf2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbf4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbf6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbf8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a9cbfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
}

}
