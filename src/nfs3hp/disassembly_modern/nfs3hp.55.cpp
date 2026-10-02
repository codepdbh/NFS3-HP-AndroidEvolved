#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x00 0x00 0x00 */
void Application::sub_527520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527520  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527524  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527528  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0052752e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00527533  e880570000             -call 0x52ccb8
    cpu.esp -= 4;
    sub_52ccb8(app, cpu);
    if (cpu.terminate) return;
    // 00527538  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527540  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527541  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527543  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527545  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527547  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052754b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052754c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527550  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527551  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00527556  e845540000             -call 0x52c9a0
    cpu.esp -= 4;
    sub_52c9a0(app, cpu);
    if (cpu.terminate) return;
    // 0052755b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052755c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_527560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527560  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527561  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527565  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527567  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527569  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052756d  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527571  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00527577  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052757b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052757c  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0052757e  e8c5540000             -call 0x52ca48
    cpu.esp -= 4;
    sub_52ca48(app, cpu);
    if (cpu.terminate) return;
    // 00527583  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527584  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527590  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527594  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527596  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052759a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 005275a0  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 005275a5  e8ca550000             -call 0x52cb74
    cpu.esp -= 4;
    sub_52cb74(app, cpu);
    if (cpu.terminate) return;
    // 005275aa  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_5275b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005275b0  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005275b4  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005275b8  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 005275be  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 005275c3  e8f0560000             -call 0x52ccb8
    cpu.esp -= 4;
    sub_52ccb8(app, cpu);
    if (cpu.terminate) return;
    // 005275c8  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5275d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005275d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005275d1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005275d3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005275d5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005275d7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005275db  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005275dc  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005275e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005275e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005275e3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005275e5  e8ea570000             -call 0x52cdd4
    cpu.esp -= 4;
    sub_52cdd4(app, cpu);
    if (cpu.terminate) return;
    // 005275ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005275eb  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_5275f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005275f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005275f1  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005275f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005275f7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005275f9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005275fd  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527601  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00527607  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052760b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052760c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052760e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00527610  e89b580000             -call 0x52ceb0
    cpu.esp -= 4;
    sub_52ceb0(app, cpu);
    if (cpu.terminate) return;
    // 00527615  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527616  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527620  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527624  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527626  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052762a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052762c  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00527632  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00527634  e89f590000             -call 0x52cfd8
    cpu.esp -= 4;
    sub_52cfd8(app, cpu);
    if (cpu.terminate) return;
    // 00527639  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_527640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527640  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527644  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0052764a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052764e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052764f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00527651  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527653  e8b85a0000             -call 0x52d110
    cpu.esp -= 4;
    sub_52d110(app, cpu);
    if (cpu.terminate) return;
    // 00527658  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527660  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527661  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527663  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527665  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527667  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052766b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052766c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527670  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527671  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00527673  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527675  e85a570000             -call 0x52cdd4
    cpu.esp -= 4;
    sub_52cdd4(app, cpu);
    if (cpu.terminate) return;
    // 0052767a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052767b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_527680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527680  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527681  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527685  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527687  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527689  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052768d  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527691  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00527697  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052769b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052769c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0052769e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005276a0  e80b580000             -call 0x52ceb0
    cpu.esp -= 4;
    sub_52ceb0(app, cpu);
    if (cpu.terminate) return;
    // 005276a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005276a6  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5276b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005276b0  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005276b4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005276b6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005276ba  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005276bf  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 005276c5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005276c7  e80c590000             -call 0x52cfd8
    cpu.esp -= 4;
    sub_52cfd8(app, cpu);
    if (cpu.terminate) return;
    // 005276cc  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_5276d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005276d0  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005276d4  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 005276da  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005276de  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005276df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005276e1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 005276e6  e8255a0000             -call 0x52d110
    cpu.esp -= 4;
    sub_52d110(app, cpu);
    if (cpu.terminate) return;
    // 005276eb  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_5276f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005276f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005276f1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005276f3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005276f5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005276f7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005276fb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005276fc  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527700  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527701  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00527706  e895520000             -call 0x52c9a0
    cpu.esp -= 4;
    sub_52c9a0(app, cpu);
    if (cpu.terminate) return;
    // 0052770b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052770c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_527710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527710  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527711  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527715  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527717  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527719  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052771d  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527721  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00527727  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052772b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052772c  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0052772e  e815530000             -call 0x52ca48
    cpu.esp -= 4;
    sub_52ca48(app, cpu);
    if (cpu.terminate) return;
    // 00527733  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527734  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527740  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527744  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527746  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052774a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00527750  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00527755  e81a540000             -call 0x52cb74
    cpu.esp -= 4;
    sub_52cb74(app, cpu);
    if (cpu.terminate) return;
    // 0052775a  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_527760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527760  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527764  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527768  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0052776e  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00527773  e840550000             -call 0x52ccb8
    cpu.esp -= 4;
    sub_52ccb8(app, cpu);
    if (cpu.terminate) return;
    // 00527778  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527780  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527781  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527783  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527785  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527787  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052778b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052778c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527790  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527791  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00527796  e805520000             -call 0x52c9a0
    cpu.esp -= 4;
    sub_52c9a0(app, cpu);
    if (cpu.terminate) return;
    // 0052779b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052779c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_5277a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005277a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005277a1  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005277a5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005277a7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005277a9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005277ad  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005277b1  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 005277b7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005277bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005277bc  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 005277be  e885520000             -call 0x52ca48
    cpu.esp -= 4;
    sub_52ca48(app, cpu);
    if (cpu.terminate) return;
    // 005277c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005277c4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5277d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005277d0  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005277d4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005277d6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005277da  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 005277e0  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 005277e5  e88a530000             -call 0x52cb74
    cpu.esp -= 4;
    sub_52cb74(app, cpu);
    if (cpu.terminate) return;
    // 005277ea  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_5277f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005277f0  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005277f4  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005277f8  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 005277fe  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00527803  e8b0540000             -call 0x52ccb8
    cpu.esp -= 4;
    sub_52ccb8(app, cpu);
    if (cpu.terminate) return;
    // 00527808  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527810  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527811  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527813  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527815  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527817  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052781b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052781c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527820  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527821  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00527823  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00527828  e8a7550000             -call 0x52cdd4
    cpu.esp -= 4;
    sub_52cdd4(app, cpu);
    if (cpu.terminate) return;
    // 0052782d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052782e  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527840  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527841  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527845  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527847  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527849  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052784d  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527851  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00527857  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052785b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052785c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052785e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00527860  e84b560000             -call 0x52ceb0
    cpu.esp -= 4;
    sub_52ceb0(app, cpu);
    if (cpu.terminate) return;
    // 00527865  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527866  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527870  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527874  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527876  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052787a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052787c  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00527882  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00527887  e84c570000             -call 0x52cfd8
    cpu.esp -= 4;
    sub_52cfd8(app, cpu);
    if (cpu.terminate) return;
    // 0052788c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_527890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527890  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527894  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0052789a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052789e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052789f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005278a4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005278a6  e865580000             -call 0x52d110
    cpu.esp -= 4;
    sub_52d110(app, cpu);
    if (cpu.terminate) return;
    // 005278ab  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_5278b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005278b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005278b1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005278b3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005278b5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005278b7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005278bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005278bc  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005278c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005278c1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005278c3  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 005278c8  e807550000             -call 0x52cdd4
    cpu.esp -= 4;
    sub_52cdd4(app, cpu);
    if (cpu.terminate) return;
    // 005278cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005278ce  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5278e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005278e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005278e1  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005278e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005278e7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005278e9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005278ed  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005278f1  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 005278f7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005278fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005278fc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005278fe  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00527900  e8ab550000             -call 0x52ceb0
    cpu.esp -= 4;
    sub_52ceb0(app, cpu);
    if (cpu.terminate) return;
    // 00527905  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527906  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527910  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527914  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527916  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052791a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052791f  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00527925  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527927  e8ac560000             -call 0x52cfd8
    cpu.esp -= 4;
    sub_52cfd8(app, cpu);
    if (cpu.terminate) return;
    // 0052792c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_527930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527930  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527934  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0052793a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052793e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052793f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00527944  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527946  e8c5570000             -call 0x52d110
    cpu.esp -= 4;
    sub_52d110(app, cpu);
    if (cpu.terminate) return;
    // 0052794b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_527950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527950  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00527953  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_527954(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527954  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00527955  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527956  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00527957  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527958  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052795a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052795c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052795e  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00527961  8b7918                 -mov edi, dword ptr [ecx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00527964  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527966  39fa                   +cmp edx, edi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527968  7d67                   -jge 0x5279d1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005279d1;
    }
    // 0052796a  8b6920                 -mov ebp, dword ptr [ecx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0052796d  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00527970  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527972  7f67                   -jg 0x5279db
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005279db;
    }
    // 00527974  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00527976  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00527978  7e1e                   -jle 0x527998
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527998;
    }
    // 0052797a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0052797c:
    // 0052797c  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0052797f  8b7a24                 -mov edi, dword ptr [edx + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 00527982  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 00527984  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00527987  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052798a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052798d  40                     -inc eax
    (cpu.eax)++;
    // 0052798e  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00527991  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527993  7ce7                   -jl 0x52797c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052797c;
    }
    // 00527995  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00527998:
    // 00527998  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0052799b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052799d  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052799f  7d23                   -jge 0x5279c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005279c4;
    }
    // 005279a1  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 005279a8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005279aa  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x005279ac:
    // 005279ac  d94624                 -fld dword ptr [esi + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(36) /* 0x24 */)));
    // 005279af  41                     -inc ecx
    (cpu.ecx)++;
    // 005279b0  40                     -inc eax
    (cpu.eax)++;
    // 005279b1  d95a24                 -fstp dword ptr [edx + 0x24]
    app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005279b4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005279b7  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 005279ba  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005279bd  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005279bf  7ceb                   -jl 0x5279ac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005279ac;
    }
    // 005279c1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x005279c4:
    // 005279c4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005279c9  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005279cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005279d1:
    // 005279d1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005279d6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005279db:
    // 005279db  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005279dd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005279df  7e1f                   -jle 0x527a00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527a00;
    }
    // 005279e1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x005279e3:
    // 005279e3  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 005279e6  d94024                 -fld dword ptr [eax + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */)));
    // 005279e9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005279ec  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005279ee  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 005279f1  42                     -inc edx
    (cpu.edx)++;
    // 005279f2  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005279f5  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 005279f8  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005279fb  39fa                   +cmp edx, edi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005279fd  7ce4                   -jl 0x5279e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005279e3;
    }
    // 005279ff  90                     -nop 
    ;
L_0x00527a00:
    // 00527a00  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00527a03  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00527a06  8b6b20                 -mov ebp, dword ptr [ebx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 00527a09  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527a0b  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00527a0d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527a0f  0f8c81000000           -jl 0x527a96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527a96;
    }
L_0x00527a15:
    // 00527a15  39fe                   +cmp esi, edi
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527a17  0f8d80000000           -jge 0x527a9d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527a9d;
    }
    // 00527a1d  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x00527a1f:
    // 00527a1f  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00527a22  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00527a29  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00527a2b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527a2d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00527a30  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00527a32  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527a34  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527a39  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527a3c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527a3e  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00527a41  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 00527a43  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527a45  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00527a46  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00527a49  e84291fdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00527a4e  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00527a51  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00527a53  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00527a55  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00527a57  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00527a5a  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527a5c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527a5f  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00527a62  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527a64  753e                   -jne 0x527aa4
    if (!cpu.flags.zf)
    {
        goto L_0x00527aa4;
    }
    // 00527a66  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00527a68  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00527a6b  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00527a6d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00527a6f  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527a71  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00527a73  7e17                   -jle 0x527a8c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527a8c;
    }
L_0x00527a75:
    // 00527a75  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00527a78  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00527a7e  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00527a81  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527a84  4e                     -dec esi
    (cpu.esi)--;
    // 00527a85  896b10                 -mov dword ptr [ebx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00527a88  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00527a8a  7fe9                   -jg 0x527a75
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527a75;
    }
L_0x00527a8c:
    // 00527a8c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527a91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527a92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527a93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527a94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527a95  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00527a96:
    // 00527a96  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00527a98  e978ffffff             -jmp 0x527a15
    goto L_0x00527a15;
L_0x00527a9d:
    // 00527a9d  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00527a9f  e97bffffff             -jmp 0x527a1f
    goto L_0x00527a1f;
L_0x00527aa4:
    // 00527aa4  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00527aa6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527aa8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00527aaa  7c0d                   -jl 0x527ab9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527ab9;
    }
    // 00527aac  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00527aaf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527ab4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ab5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ab6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ab7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ab8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00527ab9:
    // 00527ab9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527abb  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
L_0x00527ac2:
    // 00527ac2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527ac5  46                     -inc esi
    (cpu.esi)++;
    // 00527ac6  8b7b10                 -mov edi, dword ptr [ebx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00527ac9  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527acc  41                     -inc ecx
    (cpu.ecx)++;
    // 00527acd  8b6c07fc               -mov ebp, dword ptr [edi + eax - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00527ad1  896a20                 -mov dword ptr [edx + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00527ad4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00527ad6  7cea                   -jl 0x527ac2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527ac2;
    }
    // 00527ad8  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00527adb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527ae0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ae1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ae2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ae3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ae4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_527ae8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527ae8  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00527aef  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00527af6  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00527afd  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00527b04  895a14                 -mov dword ptr [edx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00527b07  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00527b0a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527b0e  c70254795200           -mov dword ptr [edx], 0x527954
    app->getMemory<x86::reg32>(cpu.edx) = 5405012 /*0x527954*/;
    // 00527b14  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527b18  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 00527b1d  c70250795200           -mov dword ptr [edx], 0x527950
    app->getMemory<x86::reg32>(cpu.edx) = 5405008 /*0x527950*/;
    // 00527b23  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527b30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527b31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00527b32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527b33  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b36  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00527b38  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00527b3b  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00527b3d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00527b3f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00527b41  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527b43  7d02                   -jge 0x527b47
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527b47;
    }
    // 00527b45  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00527b47:
    // 00527b47  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00527b49  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00527b4b  7e13                   -jle 0x527b60
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527b60;
    }
    // 00527b4d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x00527b50:
    // 00527b50  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 00527b52  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b55  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b58  40                     -inc eax
    (cpu.eax)++;
    // 00527b59  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527b5c  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527b5e  7cf0                   -jl 0x527b50
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527b50;
    }
L_0x00527b60:
    // 00527b60  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527b62  7d1c                   -jge 0x527b80
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527b80;
    }
    // 00527b64  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00527b67  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00527b6e  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00527b70:
    // 00527b70  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 00527b72  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b75  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b78  40                     -inc eax
    (cpu.eax)++;
    // 00527b79  d95bfc                 -fstp dword ptr [ebx - 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527b7c  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527b7e  7cf0                   -jl 0x527b70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527b70;
    }
L_0x00527b80:
    // 00527b80  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00527b82  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 00527b85  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b88  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527b89  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527b8a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527b8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_527b8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527b8c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00527b8d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527b8e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00527b8f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527b90  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00527b93  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00527b95  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00527b97  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00527b9a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00527b9c  7e55                   -jle 0x527bf3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527bf3;
    }
    // 00527b9e  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00527ba1  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00527ba5  8d682c                 -lea ebp, [eax + 0x2c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
L_0x00527ba8:
    // 00527ba8  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527bab  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00527bad  7566                   -jne 0x527c15
    if (!cpu.flags.zf)
    {
        goto L_0x00527c15;
    }
    // 00527baf  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527bb2  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00527bb5  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00527bb8  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527bba  7d74                   -jge 0x527c30
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527c30;
    }
    // 00527bbc  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00527bc0  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527bc5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527bc7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527bca  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527bcc  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00527bcf  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00527bd5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527bd7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527bd8  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00527bdb  e8b08ffdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00527be0  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527be3  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00527be6  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00527be9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527bec  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00527bef:
    // 00527bef  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527bf1  7fb5                   -jg 0x527ba8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527ba8;
    }
L_0x00527bf3:
    // 00527bf3  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00527bfa  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527bfd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00527c00:
    // 00527c00  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527c02  0f8c27010000           -jl 0x527d2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527d2f;
    }
    // 00527c08  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527c0d  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00527c10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527c11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527c12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527c13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527c14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00527c15:
    // 00527c15  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00527c17  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00527c19  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00527c1b  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00527c1f  e80cffffff             -call 0x527b30
    cpu.esp -= 4;
    sub_527b30(app, cpu);
    if (cpu.terminate) return;
    // 00527c24  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527c27  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527c29  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00527c2b  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00527c2e  ebbf                   -jmp 0x527bef
    goto L_0x00527bef;
L_0x00527c30:
    // 00527c30  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527c33  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 00527c37  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00527c3b  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527c40  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527c42  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527c45  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527c47  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00527c4d  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00527c50  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00527c53  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527c55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527c56  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00527c59  e8328ffdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00527c5e  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527c61  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00527c64  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00527c67  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527c69  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00527c6c  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 00527c71  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527c73  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527c75  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527c78  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00527c7b  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00527c7e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527c80  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527c85  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527c88  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527c8a  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00527c8d  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00527c90  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527c93  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527c95  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527c98  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527c9a  d98608010000           -fld dword ptr [esi + 0x108]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(264) /* 0x108 */)));
    // 00527ca0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527ca3  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527ca6  8b860c010000           -mov eax, dword ptr [esi + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 00527cac  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00527caf  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00527cb2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00527cb4  746d                   -je 0x527d23
    if (cpu.flags.zf)
    {
        goto L_0x00527d23;
    }
    // 00527cb6  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527cb9  6bd00f                 -imul edx, eax, 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00527cbc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527cbe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527cc1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527cc3  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00527cc6  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00527cc8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527cca  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00527ccc  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00527ccf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527cd0  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00527cd3  e8b88efdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00527cd8  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527cdb  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00527cde  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527ce1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527ce3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527ce6  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527ce8  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00527cec  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 00527cf1  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00527cf5  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00527cf8  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00527cfa  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00527cfc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00527cff  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527d01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00527d03  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00527d05  7e1c                   -jle 0x527d23
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527d23;
    }
    // 00527d07  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
L_0x00527d0b:
    // 00527d0b  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527d0e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00527d10  d95c8e2c               -fstp dword ptr [esi + ecx*4 + 0x2c]
    app->getMemory<float>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527d14  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527d17  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527d1a  41                     -inc ecx
    (cpu.ecx)++;
    // 00527d1b  40                     -inc eax
    (cpu.eax)++;
    // 00527d1c  894e28                 -mov dword ptr [esi + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00527d1f  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527d21  7ce8                   -jl 0x527d0b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527d0b;
    }
L_0x00527d23:
    // 00527d23  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00527d27  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00527d2a  e9c0feffff             -jmp 0x527bef
    goto L_0x00527bef;
L_0x00527d2f:
    // 00527d2f  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527d32  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527d35  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00527d37  894c862c               -mov dword ptr [esi + eax*4 + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.eax * 4) = cpu.ecx;
    // 00527d3b  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527d3e  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527d41  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00527d44  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00527d45  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00527d48  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00527d49  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00527d4c  e9affeffff             -jmp 0x527c00
    goto L_0x00527c00;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_527d54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527d54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00527d55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527d56  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00527d57  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527d58  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00527d5b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00527d5d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00527d61  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00527d63  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00527d66  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527d68  3b4128                 +cmp eax, dword ptr [ecx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527d6b  7f67                   -jg 0x527dd4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527dd4;
    }
    // 00527d6d  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00527d71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00527d73  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527d75  7e21                   -jle 0x527d98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527d98;
    }
    // 00527d77  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00527d7b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x00527d7d:
    // 00527d7d  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527d80  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 00527d83  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00527d85  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527d88  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527d8b  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527d8e  40                     -inc eax
    (cpu.eax)++;
    // 00527d8f  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00527d92  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527d94  7ce7                   -jl 0x527d7d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527d7d;
    }
    // 00527d96  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00527d98:
    // 00527d98  8b6e28                 -mov ebp, dword ptr [esi + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527d9b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00527d9d  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527d9f  7d23                   -jge 0x527dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527dc4;
    }
    // 00527da1  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00527da8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00527daa  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00527dac:
    // 00527dac  d9412c                 -fld dword ptr [ecx + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */)));
    // 00527daf  43                     -inc ebx
    (cpu.ebx)++;
    // 00527db0  40                     -inc eax
    (cpu.eax)++;
    // 00527db1  d95a2c                 -fstp dword ptr [edx + 0x2c]
    app->getMemory<float>(cpu.edx + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527db4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527db7  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527dba  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527dbd  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527dbf  7ceb                   -jl 0x527dac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527dac;
    }
    // 00527dc1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00527dc4:
    // 00527dc4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527dc9  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00527dcc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00527dcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527dd0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527dd1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527dd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527dd3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00527dd4:
    // 00527dd4  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00527dd7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00527dd9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00527ddb  7e1f                   -jle 0x527dfc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527dfc;
    }
    // 00527ddd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00527ddf:
    // 00527ddf  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527de2  d9402c                 -fld dword ptr [eax + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */)));
    // 00527de5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527de8  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527dea  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527ded  42                     -inc edx
    (cpu.edx)++;
    // 00527dee  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527df1  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527df4  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00527df7  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527df9  7ce4                   -jl 0x527ddf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527ddf;
    }
    // 00527dfb  90                     -nop 
    ;
L_0x00527dfc:
    // 00527dfc  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00527e00  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527e03  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527e06  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527e08  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527e0b  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00527e0d  83e81b                 -sub eax, 0x1b
    (cpu.eax) -= x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00527e10  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00527e14  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527e16  0f8eca000000           -jle 0x527ee6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527ee6;
    }
    // 00527e1c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
L_0x00527e1f:
    // 00527e1f  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527e23  0f8cc5000000           -jl 0x527eee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527eee;
    }
L_0x00527e29:
    // 00527e29  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00527e2c  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527e2f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00527e31  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00527e38  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00527e3a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527e3c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00527e3f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00527e41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527e43  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527e48  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527e4b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527e4d  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00527e50  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527e52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527e53  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00527e56  e8358dfdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00527e5b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527e5e  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527e61  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00527e64  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527e66  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527e68  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00527e6a  894e1c                 -mov dword ptr [esi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00527e6d  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527e6f  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00527e72  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00527e74  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00527e76  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 00527e7d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527e7f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00527e81  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527e83  90                     -nop 
    ;
L_0x00527e84:
    // 00527e84  7c72                   -jl 0x527ef8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527ef8;
    }
    // 00527e86  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00527e89  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00527e8d  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527e90  894e28                 -mov dword ptr [esi + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00527e93  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00527e95  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527e97  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527e9a  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527e9d  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00527ea1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00527ea3  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00527ea6  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527ea9  7d2e                   -jge 0x527ed9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527ed9;
    }
    // 00527eab  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00527eae  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 00527eb4  d99e08010000           -fstp dword ptr [esi + 0x108]
    app->getMemory<float>(cpu.esi + x86::reg32(264) /* 0x108 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527eba  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00527ebd  89960c010000           -mov dword ptr [esi + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 00527ec3  c7008c7b5200           -mov dword ptr [eax], 0x527b8c
    app->getMemory<x86::reg32>(cpu.eax) = 5405580 /*0x527b8c*/;
    // 00527ec9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00527ecb  7e0c                   -jle 0x527ed9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527ed9;
    }
    // 00527ecd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00527ecf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00527ed1  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527ed4  e8b3fcffff             -call 0x527b8c
    cpu.esp -= 4;
    sub_527b8c(app, cpu);
    if (cpu.terminate) return;
L_0x00527ed9:
    // 00527ed9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527ede  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00527ee1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ee2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ee3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ee4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ee5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00527ee6:
    // 00527ee6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00527ee9  e931ffffff             -jmp 0x527e1f
    goto L_0x00527e1f;
L_0x00527eee:
    // 00527eee  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00527ef0  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00527ef3  e931ffffff             -jmp 0x527e29
    goto L_0x00527e29;
L_0x00527ef8:
    // 00527ef8  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527efb  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527efd  43                     -inc ebx
    (cpu.ebx)++;
    // 00527efe  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00527f02  41                     -inc ecx
    (cpu.ecx)++;
    // 00527f03  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00527f07  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527f0a  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00527f0d  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 00527f10  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527f13  d95f2c                 -fstp dword ptr [edi + 0x2c]
    app->getMemory<float>(cpu.edi + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527f16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00527f18  e967ffffff             -jmp 0x527e84
    goto L_0x00527e84;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_527f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527f20  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00527f27  c7422800000000         -mov dword ptr [edx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00527f2e  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00527f35  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00527f3c  895a14                 -mov dword ptr [edx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00527f3f  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00527f42  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00527f46  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00527f49  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00527f4d  894a24                 -mov dword ptr [edx + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00527f50  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527f54  898a10010000           -mov dword ptr [edx + 0x110], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(272) /* 0x110 */) = cpu.ecx;
    // 00527f5a  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527f5e  c701547d5200           -mov dword ptr [ecx], 0x527d54
    app->getMemory<x86::reg32>(cpu.ecx) = 5406036 /*0x527d54*/;
    // 00527f64  b814010000             -mov eax, 0x114
    cpu.eax = 276 /*0x114*/;
    // 00527f69  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00527f6f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527f80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527f81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00527f82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527f83  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00527f86  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00527f88  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00527f8b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00527f8d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00527f8f  0f84b8000000           -je 0x52804d
    if (cpu.flags.zf)
    {
        goto L_0x0052804d;
    }
    // 00527f95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00527f96  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00527f99  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527f9b  0f8e8a000000           -jle 0x52802b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052802b;
    }
    // 00527fa1  8d6810                 -lea ebp, [eax + 0x10]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00527fa4  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00527fa7  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00527fab  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00527fae  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00527fb1  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00527fb5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00527fb9:
    // 00527fb9  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527fbc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00527fbe  0f8595000000           -jne 0x528059
    if (!cpu.flags.zf)
    {
        goto L_0x00528059;
    }
    // 00527fc4  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527fc7  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00527fca  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00527fcd  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527fcf  0f8d9f000000           -jge 0x528074
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528074;
    }
    // 00527fd5  2b561c                 -sub edx, dword ptr [esi + 0x1c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 00527fd8  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527fdd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527fdf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527fe2  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527fe4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00527fe6  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00527fe9  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527feb  7d0d                   -jge 0x527ffa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527ffa;
    }
    // 00527fed  8d571b                 -lea edx, [edi + 0x1b]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(27) /* 0x1b */);
    // 00527ff0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527ff2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527ff5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527ff7  6bd81c                 -imul ebx, eax, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
L_0x00527ffa:
    // 00527ffa  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00527ffe  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528003  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528005  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528008  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052800a  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052800d  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 0052800f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528011  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528012  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00528015  e8768bfdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 0052801a  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052801d  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052801f  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00528021  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528024  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
L_0x00528027:
    // 00528027  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528029  7f8e                   -jg 0x527fb9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527fb9;
    }
L_0x0052802b:
    // 0052802b  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00528032  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528035  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00528038:
    // 00528038  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052803a  0f8cda000000           -jl 0x52811a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052811a;
    }
    // 00528040  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528045  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528046  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00528049  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052804a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052804b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052804c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052804d:
    // 0052804d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00528052  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00528055  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528056  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528057  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528058  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528059:
    // 00528059  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052805d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052805f  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00528061  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00528063  e8c8faffff             -call 0x527b30
    cpu.esp -= 4;
    sub_527b30(app, cpu);
    if (cpu.terminate) return;
    // 00528068  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052806b  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052806d  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052806f  894e20                 -mov dword ptr [esi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00528072  ebb3                   -jmp 0x528027
    goto L_0x00528027;
L_0x00528074:
    // 00528074  837e1401               +cmp dword ptr [esi + 0x14], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528078  744e                   -je 0x5280c8
    if (cpu.flags.zf)
    {
        goto L_0x005280c8;
    }
    // 0052807a  3b561c                 +cmp edx, dword ptr [esi + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052807d  7e49                   -jle 0x5280c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005280c8;
    }
    // 0052807f  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00528083  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528088  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052808a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052808d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052808f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00528092  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00528098  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052809a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052809b  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052809e  e8ed8afdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 005280a3  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005280a6  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 005280ab  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005280ae  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005280b1  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 005280b4  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 005280b6  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005280b9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005280bb  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 005280be  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005280c1  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005280c3  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005280c5  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
L_0x005280c8:
    // 005280c8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005280cc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005280d0  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005280d6  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 005280d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005280db  751d                   -jne 0x5280fa
    if (!cpu.flags.zf)
    {
        goto L_0x005280fa;
    }
L_0x005280dd:
    // 005280dd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005280df  0f8e42ffffff           -jle 0x528027
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528027;
    }
    // 005280e5  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005280e8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 005280ee  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005280f1  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005280f4  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005280f5  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005280f8  ebe3                   -jmp 0x5280dd
    goto L_0x005280dd;
L_0x005280fa:
    // 005280fa  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax))));
    // 005280fc  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 005280ff  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528102  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 00528105  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052810c  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052810f  d95e08                 +fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528112  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528115  e90dffffff             -jmp 0x528027
    goto L_0x00528027;
L_0x0052811a:
    // 0052811a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052811d  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00528120  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00528122  894c8624               -mov dword ptr [esi + eax*4 + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 4) = cpu.ecx;
    // 00528126  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00528129  8b6e20                 -mov ebp, dword ptr [esi + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052812c  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052812f  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00528130  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00528133  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00528134  896e20                 -mov dword ptr [esi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00528137  e9fcfeffff             -jmp 0x528038
    goto L_0x00528038;
}

/* align: skip  */
void Application::sub_52813c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052813c  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00528143  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052814a  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00528151  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00528158  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052815f  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00528162  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00528166  c702807f5200           -mov dword ptr [edx], 0x527f80
    app->getMemory<x86::reg32>(cpu.edx) = 5406592 /*0x527f80*/;
    // 0052816c  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00528170  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 00528175  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052817b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_528180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528180  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528181  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528182  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528183  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528184  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528187  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00528189  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052818d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052818f  8b5028                 -mov edx, dword ptr [eax + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00528192  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00528195  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00528197  754a                   -jne 0x5281e3
    if (!cpu.flags.zf)
    {
        goto L_0x005281e3;
    }
L_0x00528199:
    // 00528199  8d7510                 -lea esi, [ebp + 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052819c  8d452c                 -lea eax, [ebp + 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 0052819f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005281a2  8d7d18                 -lea edi, [ebp + 0x18]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
L_0x005281a5:
    // 005281a5  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005281aa  0f8e85010000           -jle 0x528335
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528335;
    }
    // 005281b0  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 005281b3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005281b5  743d                   -je 0x5281f4
    if (cpu.flags.zf)
    {
        goto L_0x005281f4;
    }
    // 005281b7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 005281ba  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005281bc  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 005281be  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005281c2  e869f9ffff             -call 0x527b30
    cpu.esp -= 4;
    sub_527b30(app, cpu);
    if (cpu.terminate) return;
    // 005281c7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005281cb  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 005281ce  8b4d28                 -mov ecx, dword ptr [ebp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 005281d1  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005281d3  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005281d5  01c1                   +add ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005281d7  895d20                 -mov dword ptr [ebp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 005281da  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005281de  894d28                 -mov dword ptr [ebp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 005281e1  ebc2                   -jmp 0x5281a5
    goto L_0x005281a5;
L_0x005281e3:
    // 005281e3  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 005281e6  e8ad97feff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 005281eb  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 005281f2  eba5                   -jmp 0x528199
    goto L_0x00528199;
L_0x005281f4:
    // 005281f4  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 005281f7  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005281fa  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 005281fd  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005281ff  7d6e                   -jge 0x52826f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052826f;
    }
    // 00528201  2b551c                 -sub edx, dword ptr [ebp + 0x1c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 00528204  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528209  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052820b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052820e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528210  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00528212  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00528215  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528219  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052821b  7f43                   -jg 0x528260
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00528260;
    }
L_0x0052821d:
    // 0052821d  6b551c0f               -imul edx, dword ptr [ebp + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00528221  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528226  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528228  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052822b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052822d  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00528230  895d00                 -mov dword ptr [ebp], ebx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
    // 00528233  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528235  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528236  89550c                 -mov dword ptr [ebp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00528239  e85289fdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 0052823e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528241  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00528244  8b4d28                 -mov ecx, dword ptr [ebp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528247  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052824b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052824d  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052824f  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00528252  29da                   +sub edx, ebx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528254  894d28                 -mov dword ptr [ebp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00528257  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052825b  e945ffffff             -jmp 0x5281a5
    goto L_0x005281a5;
L_0x00528260:
    // 00528260  8d501b                 -lea edx, [eax + 0x1b]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(27) /* 0x1b */);
    // 00528263  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528265  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528268  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052826a  6bd81c                 +imul ebx, eax, 0x1c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(28 /*0x1c*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 0052826d  ebae                   -jmp 0x52821d
    goto L_0x0052821d;
L_0x0052826f:
    // 0052826f  3b551c                 +cmp edx, dword ptr [ebp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528272  7e5c                   -jle 0x5282d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005282d0;
    }
    // 00528274  6b551c0f               -imul edx, dword ptr [ebp + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00528278  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052827d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052827f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528282  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528284  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00528287  c745001c000000         -mov dword ptr [ebp], 0x1c
    app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 0052828e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528290  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528291  89550c                 -mov dword ptr [ebp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00528294  e8f788fdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00528299  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0052829c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052829f  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005282a2  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005282a5  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 005282a8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005282aa  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 005282ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005282af  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 005282b4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005282b8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005282ba  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 005282bd  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005282bf  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005282c1  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 005282c4  895d10                 -mov dword ptr [ebp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 005282c7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005282c9  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 005282cd  895528                 -mov dword ptr [ebp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edx;
L_0x005282d0:
    // 005282d0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 005282d2  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 005282d5  e82296feff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 005282da  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 005282dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005282df  7420                   -je 0x528301
    if (cpu.flags.zf)
    {
        goto L_0x00528301;
    }
    // 005282e1  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax))));
    // 005282e3  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005282e6  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 005282e9  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005282ec  c7451c00000000         -mov dword ptr [ebp + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 005282f3  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005282f6  d95d08                 +fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005282f9  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 005282fc  e9a4feffff             -jmp 0x5281a5
    goto L_0x005281a5;
L_0x00528301:
    // 00528301  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528305  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00528307  0f8e98feffff           -jle 0x5281a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005281a5;
    }
    // 0052830d  837d2800               +cmp dword ptr [ebp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528311  740d                   -je 0x528320
    if (cpu.flags.zf)
    {
        goto L_0x00528320;
    }
    // 00528313  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00528316  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00528319  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052831b  e82083fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x00528320:
    // 00528320  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528324  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00528327  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052832a  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052832c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052832e  897d10                 -mov dword ptr [ebp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00528331  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00528335:
    // 00528335  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528339  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052833c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052833f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528341  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528345  895510                 -mov dword ptr [ebp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00528348  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052834a  7c0b                   -jl 0x528357
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528357;
    }
    // 0052834c  8b4528                 -mov eax, dword ptr [ebp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052834f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528352  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528353  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528354  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528355  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528356  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528357:
    // 00528357  6bc1ff                 -imul eax, ecx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 0052835a  8b7d20                 -mov edi, dword ptr [ebp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052835d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00528361  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00528368  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0052836b  8d452c                 -lea eax, [ebp + 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 0052836e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00528370  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528372  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528373  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00528375  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00528378  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 0052837a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052837c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052837f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00528381  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528382  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528386  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00528389  8b7d28                 -mov edi, dword ptr [ebp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052838c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052838e  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528390  897520                 -mov dword ptr [ebp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00528393  897d28                 -mov dword ptr [ebp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 00528396  8b4528                 -mov eax, dword ptr [ebp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528399  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052839c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052839d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052839e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052839f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005283a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5283a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005283a4  e8b74d0000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 005283a9  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 005283b0  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 005283b7  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 005283be  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 005283c5  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 005283cc  c7422800000000         -mov dword ptr [edx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 005283d3  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 005283d6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005283da  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 005283dd  c70080815200           -mov dword ptr [eax], 0x528180
    app->getMemory<x86::reg32>(cpu.eax) = 5407104 /*0x528180*/;
    // 005283e3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005283e7  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 005283ed  b898000000             -mov eax, 0x98
    cpu.eax = 152 /*0x98*/;
    // 005283f2  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_528400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528400  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00528403  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_528404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528404  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528405  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528406  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528407  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528408  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052840a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052840c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052840e  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00528411  8b7920                 -mov edi, dword ptr [ecx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00528414  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00528416  39fa                   +cmp edx, edi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528418  0f8d6b000000           -jge 0x528489
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528489;
    }
    // 0052841e  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00528421  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00528424  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00528426  39c6                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528428  7f69                   -jg 0x528493
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00528493;
    }
    // 0052842a  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052842c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052842e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00528430  7e1e                   -jle 0x528450
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528450;
    }
    // 00528432  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00528434:
    // 00528434  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00528437  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0052843a  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 0052843c  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0052843f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528442  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528445  42                     -inc edx
    (cpu.edx)++;
    // 00528446  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00528449  39f2                   +cmp edx, esi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052844b  7ce7                   -jl 0x528434
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528434;
    }
    // 0052844d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00528450:
    // 00528450  8b7328                 -mov esi, dword ptr [ebx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00528453  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00528455  39f2                   +cmp edx, esi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528457  7d23                   -jge 0x52847c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052847c;
    }
    // 00528459  8d349500000000         -lea esi, [edx*4]
    cpu.esi = x86::reg32(cpu.edx * 4);
    // 00528460  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528462  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00528464:
    // 00528464  d9462c                 -fld dword ptr [esi + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(44) /* 0x2c */)));
    // 00528467  41                     -inc ecx
    (cpu.ecx)++;
    // 00528468  42                     -inc edx
    (cpu.edx)++;
    // 00528469  d9582c                 -fstp dword ptr [eax + 0x2c]
    app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052846c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052846f  8b7b28                 -mov edi, dword ptr [ebx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00528472  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528475  39fa                   +cmp edx, edi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528477  7ceb                   -jl 0x528464
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528464;
    }
    // 00528479  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0052847c:
    // 0052847c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528481  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00528484  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528485  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528486  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528487  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528488  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528489:
    // 00528489  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052848e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052848f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528490  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528491  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528492  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528493:
    // 00528493  8b6928                 -mov ebp, dword ptr [ecx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00528496  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00528498  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052849a  7e20                   -jle 0x5284bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005284bc;
    }
    // 0052849c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0052849e:
    // 0052849e  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 005284a1  d9422c                 -fld dword ptr [edx + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(44) /* 0x2c */)));
    // 005284a4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005284a7  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005284a9  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 005284ac  40                     -inc eax
    (cpu.eax)++;
    // 005284ad  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005284b0  8b7b28                 -mov edi, dword ptr [ebx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 005284b3  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 005284b6  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005284b8  7ce4                   -jl 0x52849e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052849e;
    }
    // 005284ba  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x005284bc:
    // 005284bc  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 005284bf  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 005284c1  8b6b20                 -mov ebp, dword ptr [ebx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 005284c4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005284c6  2b6b24                 -sub ebp, dword ptr [ebx + 0x24]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */)));
    // 005284c9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005284cb  0f8c7d000000           -jl 0x52854e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052854e;
    }
L_0x005284d1:
    // 005284d1  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005284d3  0f8d7c000000           -jge 0x528555
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528555;
    }
    // 005284d9  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x005284db:
    // 005284db  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 005284de  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005284e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005284e2  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 005284e5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005284e7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005284e9  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005284ee  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005284f1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005284f3  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 005284f6  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 005284f8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005284fa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005284fb  895314                 -mov dword ptr [ebx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005284fe  e88d84fdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528503  8b5324                 -mov edx, dword ptr [ebx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 00528506  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00528508  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052850a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052850c  895324                 -mov dword ptr [ebx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0052850f  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528511  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528514  894b24                 -mov dword ptr [ebx + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00528517  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528519  753e                   -jne 0x528559
    if (!cpu.flags.zf)
    {
        goto L_0x00528559;
    }
    // 0052851b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052851d  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052851f  2b4320                 -sub eax, dword ptr [ebx + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    // 00528522  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528524  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00528526  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00528528  7e1a                   -jle 0x528544
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528544;
    }
L_0x0052852a:
    // 0052852a  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0052852d  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00528533  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00528536  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528539  4e                     -dec esi
    (cpu.esi)--;
    // 0052853a  896b18                 -mov dword ptr [ebx + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0052853d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052853f  7fe9                   -jg 0x52852a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052852a;
    }
    // 00528541  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00528544:
    // 00528544  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528549  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052854a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052854b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052854c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052854d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052854e:
    // 0052854e  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00528550  e97cffffff             -jmp 0x5284d1
    goto L_0x005284d1;
L_0x00528555:
    // 00528555  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00528557  eb82                   -jmp 0x5284db
    goto L_0x005284db;
L_0x00528559:
    // 00528559  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052855e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00528560  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00528562  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528565  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528567  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00528569  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052856b  6bf6ff                 -imul esi, esi, -1
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 0052856e  83fee4                 +cmp esi, -0x1c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-28 /*-0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528571  7502                   -jne 0x528575
    if (!cpu.flags.zf)
    {
        goto L_0x00528575;
    }
    // 00528573  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00528575:
    // 00528575  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00528577  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00528579  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052857b  7c0d                   -jl 0x52858a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052858a;
    }
    // 0052857d  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00528580  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528585  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528586  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528587  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528588  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528589  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052858a:
    // 0052858a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052858c  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
L_0x00528593:
    // 00528593  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528596  46                     -inc esi
    (cpu.esi)++;
    // 00528597  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0052859a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052859d  41                     -inc ecx
    (cpu.ecx)++;
    // 0052859e  8b6c3afc               -mov ebp, dword ptr [edx + edi - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 005285a2  896828                 -mov dword ptr [eax + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 005285a5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005285a7  7cea                   -jl 0x528593
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528593;
    }
    // 005285a9  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 005285ac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005285b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005285b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005285b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005285b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005285b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5285b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005285b8  c7422400000000         -mov dword ptr [edx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 005285bf  c7422800000000         -mov dword ptr [edx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 005285c6  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 005285cd  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 005285d4  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 005285db  c7421000000000         -mov dword ptr [edx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 005285e2  895a1c                 -mov dword ptr [edx + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 005285e5  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005285e8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005285ec  c70204845200           -mov dword ptr [edx], 0x528404
    app->getMemory<x86::reg32>(cpu.edx) = 5407748 /*0x528404*/;
    // 005285f2  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005285f6  b804010000             -mov eax, 0x104
    cpu.eax = 260 /*0x104*/;
    // 005285fb  c70200845200           -mov dword ptr [edx], 0x528400
    app->getMemory<x86::reg32>(cpu.edx) = 5407744 /*0x528400*/;
    // 00528601  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_528610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528610  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528611  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528612  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528613  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528616  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00528618  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052861b  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0052861d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052861f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00528621  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528623  7d02                   -jge 0x528627
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528627;
    }
    // 00528625  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00528627:
    // 00528627  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00528629  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052862b  7e1f                   -jle 0x52864c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052864c;
    }
    // 0052862d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x00528630:
    // 00528630  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 00528632  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528635  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528638  40                     -inc eax
    (cpu.eax)++;
    // 00528639  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052863c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052863f  8b59fc                 -mov ebx, dword ptr [ecx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00528642  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00528645  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528647  7ce7                   -jl 0x528630
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528630;
    }
    // 00528649  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0052864c:
    // 0052864c  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052864e  7d24                   -jge 0x528674
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528674;
    }
    // 00528650  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00528653  8d1cc500000000         -lea ebx, [eax*8]
    cpu.ebx = x86::reg32(cpu.eax * 8);
    // 0052865a  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0052865c:
    // 0052865c  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0052865e  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528661  40                     -inc eax
    (cpu.eax)++;
    // 00528662  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528664  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528667  d943fc                 -fld dword ptr [ebx - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */)));
    // 0052866a  d959fc                 -fstp dword ptr [ecx - 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052866d  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052866f  7ceb                   -jl 0x52865c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052865c;
    }
    // 00528671  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00528674:
    // 00528674  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00528676  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 00528679  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052867c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052867d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052867e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052867f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_528680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528680  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528681  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528682  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528683  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528684  81ecec000000           -sub esp, 0xec
    (cpu.esp) -= x86::reg32(x86::sreg32(236 /*0xec*/));
    // 0052868a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052868c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052868e  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00528691  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00528693  7e5c                   -jle 0x5286f1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005286f1;
    }
    // 00528695  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00528698  899424e4000000         -mov dword ptr [esp + 0xe4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */) = cpu.edx;
    // 0052869f  8d6834                 -lea ebp, [eax + 0x34]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(52) /* 0x34 */);
L_0x005286a2:
    // 005286a2  66837e3000             +cmp word ptr [esi + 0x30], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005286a7  756b                   -jne 0x528714
    if (!cpu.flags.zf)
    {
        goto L_0x00528714;
    }
    // 005286a9  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 005286ac  8b4e2c                 -mov ecx, dword ptr [esi + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 005286af  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 005286b2  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005286b4  0f8d7e000000           -jge 0x528738
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528738;
    }
    // 005286ba  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 005286be  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005286c3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005286c5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005286c8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005286ca  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005286cd  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 005286d3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005286d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005286d6  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005286d9  e8b282fdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 005286de  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 005286e1  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005286e4  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005286e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005286ea  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x005286ed:
    // 005286ed  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005286ef  7fb1                   -jg 0x5286a2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005286a2;
    }
L_0x005286f1:
    // 005286f1  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 005286f8  014618                 -add dword ptr [esi + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 005286fb  90                     -nop 
    ;
L_0x005286fc:
    // 005286fc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005286fe  0f8c73010000           -jl 0x528877
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528877;
    }
    // 00528704  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528709  81c4ec000000           -add esp, 0xec
    (cpu.esp) += x86::reg32(x86::sreg32(236 /*0xec*/));
    // 0052870f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528710  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528711  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528712  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528713  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528714:
    // 00528714  8b8c24e4000000         -mov ecx, dword ptr [esp + 0xe4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 0052871b  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052871d  8b462e                 -mov eax, dword ptr [esi + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 00528720  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00528722  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00528725  e8e6feffff             -call 0x528610
    cpu.esp -= 4;
    sub_528610(app, cpu);
    if (cpu.terminate) return;
    // 0052872a  668b5e30               -mov bx, word ptr [esi + 0x30]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0052872e  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528730  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528732  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 00528736  ebb5                   -jmp 0x5286ed
    goto L_0x005286ed;
L_0x00528738:
    // 00528738  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 0052873c  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052873f  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528744  898424e0000000         -mov dword ptr [esp + 0xe0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */) = cpu.eax;
    // 0052874b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052874d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528750  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528752  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00528758  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052875b  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0052875e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528760  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528761  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528764  e82782fdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528769  8346241c               -add dword ptr [esi + 0x24], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052876d  668b5e2c               -mov bx, word ptr [esi + 0x2c]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00528771  668b4624               -mov ax, word ptr [esi + 0x24]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528775  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 0052877a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052877c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052877e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00528780  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528783  66895630               -mov word ptr [esi + 0x30], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.dx;
    // 00528787  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00528789  41                     -inc ecx
    (cpu.ecx)++;
    // 0052878a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052878d  66894e30               -mov word ptr [esi + 0x30], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.cx;
    // 00528791  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528796  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528798  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0052879b  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0052879e  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 005287a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005287a3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005287a6  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005287a8  d986ec010000           -fld dword ptr [esi + 0x1ec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(492) /* 0x1ec */)));
    // 005287ae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005287b1  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005287b4  8b86f0010000           -mov eax, dword ptr [esi + 0x1f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */);
    // 005287ba  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005287bd  8b86f4010000           -mov eax, dword ptr [esi + 0x1f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(500) /* 0x1f4 */);
    // 005287c3  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005287c6  8b86f8010000           -mov eax, dword ptr [esi + 0x1f8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(504) /* 0x1f8 */);
    // 005287cc  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005287cf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005287d1  0f8491000000           -je 0x528868
    if (cpu.flags.zf)
    {
        goto L_0x00528868;
    }
    // 005287d7  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 005287d9  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 005287dd  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005287e2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005287e4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005287e7  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005287e9  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005287ec  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005287ee  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005287f0  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005287f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005287f4  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 005287f7  e89481fdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 005287fc  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 005287ff  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528802  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528805  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528807  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052880a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052880c  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 00528811  898424e8000000         -mov dword ptr [esp + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 00528818  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052881a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052881c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00528823  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00528826  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00528828  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 0052882f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00528831  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00528833  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00528835  7e31                   -jle 0x528868
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528868;
    }
L_0x00528837:
    // 00528837  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 0052883a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0052883d  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052883f  895cce34               -mov dword ptr [esi + ecx*8 + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */ + cpu.ecx * 8) = cpu.ebx;
    // 00528843  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 00528846  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528849  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0052884c  8b58fc                 -mov ebx, dword ptr [eax - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0052884f  895cce38               -mov dword ptr [esi + ecx*8 + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */ + cpu.ecx * 8) = cpu.ebx;
    // 00528853  668b5e30               -mov bx, word ptr [esi + 0x30]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00528857  42                     -inc edx
    (cpu.edx)++;
    // 00528858  43                     -inc ebx
    (cpu.ebx)++;
    // 00528859  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 00528860  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 00528864  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528866  7ccf                   -jl 0x528837
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528837;
    }
L_0x00528868:
    // 00528868  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0052886f  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00528872  e976feffff             -jmp 0x5286ed
    goto L_0x005286ed;
L_0x00528877:
    // 00528877  8b562e                 -mov edx, dword ptr [esi + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 0052887a  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052887d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00528880  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00528882  894cd634               -mov dword ptr [esi + edx*8 + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */ + cpu.edx * 8) = cpu.ecx;
    // 00528886  8b462e                 -mov eax, dword ptr [esi + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 00528889  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052888c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052888f  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00528892  894cc638               -mov dword ptr [esi + eax*8 + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */ + cpu.eax * 8) = cpu.ecx;
    // 00528896  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528899  668b4e30               -mov cx, word ptr [esi + 0x30]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0052889d  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005288a0  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005288a1  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005288a4  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005288a5  66894e30               -mov word ptr [esi + 0x30], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.cx;
    // 005288a9  e94efeffff             -jmp 0x5286fc
    goto L_0x005286fc;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5288b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005288b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005288b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005288b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005288b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005288b4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005288b7  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 005288ba  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 005288bd  8b502e                 -mov edx, dword ptr [eax + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 005288c0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005288c2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 005288c5  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 005288c8  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005288ca  7d34                   -jge 0x528900
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528900;
    }
    // 005288cc  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 005288d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x005288d3:
    // 005288d3  8b562e                 -mov edx, dword ptr [esi + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 005288d6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 005288d9  39d3                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005288db  0f8d8b000000           -jge 0x52896c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052896c;
    }
    // 005288e1  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005288e4  8b4834                 -mov ecx, dword ptr [eax + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 005288e7  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 005288e9  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005288ec  8b4838                 -mov ecx, dword ptr [eax + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 005288ef  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 005288f2  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005288f5  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005288f8  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005288fa  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005288fb  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 005288fe  ebd3                   -jmp 0x5288d3
    goto L_0x005288d3;
L_0x00528900:
    // 00528900  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00528902  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00528904  7e26                   -jle 0x52892c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052892c;
    }
    // 00528906  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
L_0x00528909:
    // 00528909  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052890c  8b4834                 -mov ecx, dword ptr [eax + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0052890f  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00528911  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528914  8b4838                 -mov ecx, dword ptr [eax + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 00528917  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052891a  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052891d  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528920  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528923  43                     -inc ebx
    (cpu.ebx)++;
    // 00528924  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00528927  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528929  7cde                   -jl 0x528909
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528909;
    }
    // 0052892b  90                     -nop 
    ;
L_0x0052892c:
    // 0052892c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052892e  8d14dd00000000         -lea edx, [ebx*8]
    cpu.edx = x86::reg32(cpu.ebx * 8);
    // 00528935  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00528937  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00528939:
    // 00528939  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 0052893c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0052893f  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528941  7d16                   -jge 0x528959
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528959;
    }
    // 00528943  d94234                 -fld dword ptr [edx + 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(52) /* 0x34 */)));
    // 00528946  47                     -inc edi
    (cpu.edi)++;
    // 00528947  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052894a  43                     -inc ebx
    (cpu.ebx)++;
    // 0052894b  d95834                 -fstp dword ptr [eax + 0x34]
    app->getMemory<float>(cpu.eax + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052894e  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528951  8b4a30                 -mov ecx, dword ptr [edx + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 00528954  894830                 -mov dword ptr [eax + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 00528957  ebe0                   -jmp 0x528939
    goto L_0x00528939;
L_0x00528959:
    // 00528959  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052895e  66897e30               -mov word ptr [esi + 0x30], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.di;
    // 00528962  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528964  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00528967  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528968  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528969  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052896a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052896b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052896c:
    // 0052896c  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0052896f  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528972  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00528975  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528977  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528979  83ef1b                 -sub edi, 0x1b
    (cpu.edi) -= x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 0052897c  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0052897f  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528981  7e02                   -jle 0x528985
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528985;
    }
    // 00528983  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x00528985:
    // 00528985  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528987  0f8ccc000000           -jl 0x528a59
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528a59;
    }
L_0x0052898d:
    // 0052898d  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528990  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528992  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00528994  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00528997  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528999  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052899b  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005289a0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005289a3  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005289a5  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005289a8  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 005289aa  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005289ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005289ad  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005289b0  e8db7ffdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 005289b5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005289b8  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 005289bb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 005289bd  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 005289bf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005289c1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005289c3  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 005289c6  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005289c8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 005289ca  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 005289cd  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005289d1  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 005289d8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005289da  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005289dc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005289de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x005289e0:
    // 005289e0  0f8c7a000000           -jl 0x528a60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528a60;
    }
    // 005289e6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005289e9  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005289ec  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005289ee  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005289f0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005289f3  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 005289f6  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 005289f9  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 005289fd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005289ff  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00528a02  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528a05  7d43                   -jge 0x528a4a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528a4a;
    }
    // 00528a07  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00528a0a  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00528a0d  8b86fc010000           -mov eax, dword ptr [esi + 0x1fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(508) /* 0x1fc */);
    // 00528a13  d99eec010000           -fstp dword ptr [esi + 0x1ec]
    app->getMemory<float>(cpu.esi + x86::reg32(492) /* 0x1ec */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528a19  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00528a1c  8996f0010000           -mov dword ptr [esi + 0x1f0], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */) = cpu.edx;
    // 00528a22  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00528a25  8996f4010000           -mov dword ptr [esi + 0x1f4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(500) /* 0x1f4 */) = cpu.edx;
    // 00528a2b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00528a2e  8996f8010000           -mov dword ptr [esi + 0x1f8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(504) /* 0x1f8 */) = cpu.edx;
    // 00528a34  c70080865200           -mov dword ptr [eax], 0x528680
    app->getMemory<x86::reg32>(cpu.eax) = 5408384 /*0x528680*/;
    // 00528a3a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00528a3c  7e0c                   -jle 0x528a4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528a4a;
    }
    // 00528a3e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00528a40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00528a42  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528a45  e836fcffff             -call 0x528680
    cpu.esp -= 4;
    sub_528680(app, cpu);
    if (cpu.terminate) return;
L_0x00528a4a:
    // 00528a4a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00528a4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528a51  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00528a54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528a55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528a56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528a57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528a58  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528a59:
    // 00528a59  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00528a5b  e92dffffff             -jmp 0x52898d
    goto L_0x0052898d;
L_0x00528a60:
    // 00528a60  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528a63  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528a65  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00528a69  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00528a6d  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00528a70  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 00528a73  d95934                 -fstp dword ptr [ecx + 0x34]
    app->getMemory<float>(cpu.ecx + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528a76  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528a79  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528a7b  43                     -inc ebx
    (cpu.ebx)++;
    // 00528a7c  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528a7f  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 00528a82  d95938                 -fstp dword ptr [ecx + 0x38]
    app->getMemory<float>(cpu.ecx + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528a85  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528a89  41                     -inc ecx
    (cpu.ecx)++;
    // 00528a8a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528a8d  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00528a91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00528a93  e948ffffff             -jmp 0x5289e0
    goto L_0x005289e0;
}

/* align: skip  */
void Application::sub_528a98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528a98  c7422400000000         -mov dword ptr [edx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00528a9f  66c742300000           -mov word ptr [edx + 0x30], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00528aa5  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00528aac  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00528ab3  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00528aba  c7421000000000         -mov dword ptr [edx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00528ac1  895a1c                 -mov dword ptr [edx + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00528ac4  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00528ac7  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528acb  894a28                 -mov dword ptr [edx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00528ace  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00528ad2  894a2c                 -mov dword ptr [edx + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 00528ad5  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00528ad9  898afc010000           -mov dword ptr [edx + 0x1fc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(508) /* 0x1fc */) = cpu.ecx;
    // 00528adf  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00528ae3  c701b0885200           -mov dword ptr [ecx], 0x5288b0
    app->getMemory<x86::reg32>(cpu.ecx) = 5408944 /*0x5288b0*/;
    // 00528ae9  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 00528aee  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00528af4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_528b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528b00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528b01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528b02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528b03  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00528b06  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00528b08  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00528b0b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00528b0d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00528b0f  0f8490000000           -je 0x528ba5
    if (cpu.flags.zf)
    {
        goto L_0x00528ba5;
    }
    // 00528b15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528b16  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00528b19  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528b1b  7e67                   -jle 0x528b84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528b84;
    }
    // 00528b1d  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00528b20  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00528b24  8d502c                 -lea edx, [eax + 0x2c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00528b27  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00528b2b  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00528b2e  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00528b32  8d681c                 -lea ebp, [eax + 0x1c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
L_0x00528b35:
    // 00528b35  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528b38  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00528b3a  7570                   -jne 0x528bac
    if (!cpu.flags.zf)
    {
        goto L_0x00528bac;
    }
    // 00528b3c  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528b3f  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00528b42  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00528b45  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528b47  0f8d7c000000           -jge 0x528bc9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528bc9;
    }
    // 00528b4d  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00528b51  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 00528b56  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528b58  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528b5b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528b5d  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00528b60  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00528b66  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528b68  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528b69  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528b6c  e81f7efdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528b71  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528b74  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528b77  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528b7a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528b7d  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
L_0x00528b80:
    // 00528b80  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528b82  7fb1                   -jg 0x528b35
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00528b35;
    }
L_0x00528b84:
    // 00528b84  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 00528b8b  014618                 -add dword ptr [esi + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528b8e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00528b90:
    // 00528b90  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528b92  0f8ce3000000           -jl 0x528c7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528c7b;
    }
    // 00528b98  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528b9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00528b9e:
    // 00528b9e  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528ba1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ba2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ba3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ba4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528ba5:
    // 00528ba5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00528baa  ebf2                   -jmp 0x528b9e
    goto L_0x00528b9e;
L_0x00528bac:
    // 00528bac  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00528bb0  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00528bb4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528bb6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00528bb8  e853faffff             -call 0x528610
    cpu.esp -= 4;
    sub_528610(app, cpu);
    if (cpu.terminate) return;
    // 00528bbd  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528bc0  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528bc2  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528bc4  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00528bc7  ebb7                   -jmp 0x528b80
    goto L_0x00528b80;
L_0x00528bc9:
    // 00528bc9  837e1c01               +cmp dword ptr [esi + 0x1c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528bcd  7445                   -je 0x528c14
    if (cpu.flags.zf)
    {
        goto L_0x00528c14;
    }
    // 00528bcf  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00528bd3  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 00528bd8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528bda  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528bdd  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528bdf  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00528be2  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00528be8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528bea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528beb  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528bee  e89d7dfdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528bf3  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528bf6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00528bf8  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00528bfb  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00528bfe  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528c00  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00528c02  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c05  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528c07  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00528c0a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528c0d  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528c0f  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528c11  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x00528c14:
    // 00528c14  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528c18  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00528c1a  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00528c20  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00528c23  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00528c25  742e                   -je 0x528c55
    if (cpu.flags.zf)
    {
        goto L_0x00528c55;
    }
    // 00528c27  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528c29  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax))));
    // 00528c2b  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528c2e  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 00528c31  d95e08                 -fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528c34  df4004                 -fild word ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 00528c37  d95e0c                 -fstp dword ptr [esi + 0xc]
    app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528c3a  df4006                 -fild word ptr [eax + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */))));
    // 00528c3d  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00528c40  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00528c47  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528c4a  d95e10                 +fstp dword ptr [esi + 0x10]
    app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528c4d  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00528c50  e92bffffff             -jmp 0x528b80
    goto L_0x00528b80;
L_0x00528c55:
    // 00528c55  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00528c57  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528c59  0f8e21ffffff           -jle 0x528b80
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528b80;
    }
L_0x00528c5f:
    // 00528c5f  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c62  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00528c68  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c6b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528c6e  4f                     -dec edi
    (cpu.edi)--;
    // 00528c6f  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00528c72  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528c74  7fe9                   -jg 0x528c5f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00528c5f;
    }
    // 00528c76  e905ffffff             -jmp 0x528b80
    goto L_0x00528b80;
L_0x00528c7b:
    // 00528c7b  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c7e  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528c81  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00528c83  894cc62c               -mov dword ptr [esi + eax*8 + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.eax * 8) = cpu.ecx;
    // 00528c87  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c8a  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528c8d  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00528c90  894cc630               -mov dword ptr [esi + eax*8 + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */ + cpu.eax * 8) = cpu.ecx;
    // 00528c94  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c97  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528c9a  83c108                 +add ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528c9d  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00528c9e  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00528ca1  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00528ca2  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00528ca5  e9e6feffff             -jmp 0x528b90
    goto L_0x00528b90;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_528cac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528cac  c7421c01000000         -mov dword ptr [edx + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 00528cb3  c7422400000000         -mov dword ptr [edx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00528cba  c7422800000000         -mov dword ptr [edx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00528cc1  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00528cc8  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00528ccf  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00528cd6  c7421000000000         -mov dword ptr [edx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00528cdd  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00528ce0  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00528ce4  c702008b5200           -mov dword ptr [edx], 0x528b00
    app->getMemory<x86::reg32>(cpu.edx) = 5409536 /*0x528b00*/;
    // 00528cea  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00528cee  b804010000             -mov eax, 0x104
    cpu.eax = 260 /*0x104*/;
    // 00528cf3  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00528cf9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_528d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528d00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528d01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528d02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528d03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528d04  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528d07  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00528d09  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00528d0d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00528d0f  8b5030                 -mov edx, dword ptr [eax + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00528d12  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00528d15  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00528d17  754a                   -jne 0x528d63
    if (!cpu.flags.zf)
    {
        goto L_0x00528d63;
    }
L_0x00528d19:
    // 00528d19  8d4518                 -lea eax, [ebp + 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00528d1c  8d7d34                 -lea edi, [ebp + 0x34]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 00528d1f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00528d22  8d7520                 -lea esi, [ebp + 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
L_0x00528d25:
    // 00528d25  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528d2a  0f8e70010000           -jle 0x528ea0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528ea0;
    }
    // 00528d30  8b5d28                 -mov ebx, dword ptr [ebp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528d33  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00528d35  743d                   -je 0x528d74
    if (cpu.flags.zf)
    {
        goto L_0x00528d74;
    }
    // 00528d37  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00528d3a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528d3c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00528d3e  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528d42  e8c9f8ffff             -call 0x528610
    cpu.esp -= 4;
    sub_528610(app, cpu);
    if (cpu.terminate) return;
    // 00528d47  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528d4b  8b4d28                 -mov ecx, dword ptr [ebp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528d4e  8b5530                 -mov edx, dword ptr [ebp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528d51  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528d53  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528d55  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528d57  894d28                 -mov dword ptr [ebp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00528d5a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00528d5e  895530                 -mov dword ptr [ebp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00528d61  ebc2                   -jmp 0x528d25
    goto L_0x00528d25;
L_0x00528d63:
    // 00528d63  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00528d66  e82d8cfeff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 00528d6b  c7463000000000         -mov dword ptr [esi + 0x30], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00528d72  eba5                   -jmp 0x528d19
    goto L_0x00528d19;
L_0x00528d74:
    // 00528d74  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00528d77  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00528d7a  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00528d7d  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528d7f  7d4a                   -jge 0x528dcb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528dcb;
    }
    // 00528d81  6b55241e               -imul edx, dword ptr [ebp + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00528d85  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528d8a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528d8c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528d8f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528d91  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00528d94  c745001c000000         -mov dword ptr [ebp], 0x1c
    app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 00528d9b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528d9d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528d9e  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528da1  e8ea7bfdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528da6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528da9  8b5d24                 -mov ebx, dword ptr [ebp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00528dac  8b5530                 -mov edx, dword ptr [ebp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528daf  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528db3  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528db6  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528db9  895d24                 -mov dword ptr [ebp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00528dbc  83e81c                 +sub eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528dbf  895530                 -mov dword ptr [ebp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00528dc2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00528dc6  e95affffff             -jmp 0x528d25
    goto L_0x00528d25;
L_0x00528dcb:
    // 00528dcb  837d1c00               +cmp dword ptr [ebp + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528dcf  745a                   -je 0x528e2b
    if (cpu.flags.zf)
    {
        goto L_0x00528e2b;
    }
    // 00528dd1  6b55241e               -imul edx, dword ptr [ebp + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00528dd5  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528dda  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528ddc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528ddf  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528de1  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00528de4  c745001c000000         -mov dword ptr [ebp], 0x1c
    app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 00528deb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528ded  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528dee  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528df1  e89a7bfdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528df6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528df9  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00528dfc  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00528dff  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528e02  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00528e05  894524                 -mov dword ptr [ebp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00528e08  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528e0a  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 00528e0f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528e13  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528e15  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00528e18  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528e1a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528e1c  8b4530                 -mov eax, dword ptr [ebp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528e1f  895d18                 -mov dword ptr [ebp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00528e22  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00528e24  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00528e28  894530                 -mov dword ptr [ebp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */) = cpu.eax;
L_0x00528e2b:
    // 00528e2b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00528e2d  8b452c                 -mov eax, dword ptr [ebp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 00528e30  e8c78afeff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 00528e35  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00528e38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00528e3a  742c                   -je 0x528e68
    if (cpu.flags.zf)
    {
        goto L_0x00528e68;
    }
    // 00528e3c  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax))));
    // 00528e3e  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528e41  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 00528e44  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528e47  df4004                 -fild word ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 00528e4a  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528e4d  df4006                 -fild word ptr [eax + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */))));
    // 00528e50  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00528e53  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00528e5a  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528e5d  d95d10                 +fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528e60  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00528e63  e9bdfeffff             -jmp 0x528d25
    goto L_0x00528d25;
L_0x00528e68:
    // 00528e68  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528e6c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00528e6e  0f8eb1feffff           -jle 0x528d25
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528d25;
    }
    // 00528e74  837d3000               +cmp dword ptr [ebp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528e78  7411                   -je 0x528e8b
    if (cpu.flags.zf)
    {
        goto L_0x00528e8b;
    }
    // 00528e7a  8d1ccd00000000         -lea ebx, [ecx*8]
    cpu.ebx = x86::reg32(cpu.ecx * 8);
    // 00528e81  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00528e84  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00528e86  e8b577fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x00528e8b:
    // 00528e8b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528e8f  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00528e92  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00528e95  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00528e97  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528e99  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00528e9d  897518                 -mov dword ptr [ebp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.esi;
L_0x00528ea0:
    // 00528ea0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528ea4  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00528ea7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00528eaa  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528eac  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528eb0  895518                 -mov dword ptr [ebp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00528eb3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00528eb5  7c0b                   -jl 0x528ec2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528ec2;
    }
    // 00528eb7  8b4530                 -mov eax, dword ptr [ebp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528eba  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528ebd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ebe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ebf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ec0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ec1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528ec2:
    // 00528ec2  6bc1ff                 -imul eax, ecx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 00528ec5  8b7d28                 -mov edi, dword ptr [ebp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528ec8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00528ecc  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 00528ed3  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 00528ed6  8d4534                 -lea eax, [ebp + 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 00528ed9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00528edb  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528edd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528ede  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00528ee0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00528ee3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 00528ee5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00528ee7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00528eea  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00528eec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528eed  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528ef1  8b7528                 -mov esi, dword ptr [ebp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528ef4  8b7d30                 -mov edi, dword ptr [ebp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528ef7  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528ef9  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528efb  897528                 -mov dword ptr [ebp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00528efe  897d30                 -mov dword ptr [ebp + 0x30], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */) = cpu.edi;
    // 00528f01  8b4530                 -mov eax, dword ptr [ebp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528f04  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528f07  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528f08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528f09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528f0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528f0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_528f0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528f0c  e84f420000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 00528f11  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00528f18  c7422400000000         -mov dword ptr [edx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00528f1f  c7422800000000         -mov dword ptr [edx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00528f26  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00528f2d  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00528f34  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00528f3b  c7421000000000         -mov dword ptr [edx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00528f42  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00528f49  89422c                 -mov dword ptr [edx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00528f4c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00528f50  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00528f53  c700008d5200           -mov dword ptr [eax], 0x528d00
    app->getMemory<x86::reg32>(cpu.eax) = 5410048 /*0x528d00*/;
    // 00528f59  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00528f5d  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00528f63  b80c010000             -mov eax, 0x10c
    cpu.eax = 268 /*0x10c*/;
    // 00528f68  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_528f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528f70  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00528f73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_528f74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528f74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528f75  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528f76  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528f77  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528f78  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00528f7a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00528f7c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528f7e  8b5718                 -mov edx, dword ptr [edi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00528f81  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00528f84  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00528f86  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528f88  7d3c                   -jge 0x528fc6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528fc6;
    }
    // 00528f8a  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00528f8d  8b471a                 -mov eax, dword ptr [edi + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(26) /* 0x1a */);
    // 00528f90  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00528f93  39c6                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528f95  7e39                   -jle 0x528fd0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528fd0;
    }
    // 00528f97  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00528f9c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00528f9e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00528fa0:
    // 00528fa0  8b7b1a                 -mov edi, dword ptr [ebx + 0x1a]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(26) /* 0x1a */);
    // 00528fa3  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 00528fa6  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528fa8  0f8d79000000           -jge 0x529027
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529027;
    }
    // 00528fae  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00528fb1  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00528fb5  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 00528fb8  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00528fbb  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00528fbe  01ef                   +add edi, ebp
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528fc0  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00528fc1  897b0c                 -mov dword ptr [ebx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00528fc4  ebda                   -jmp 0x528fa0
    goto L_0x00528fa0;
L_0x00528fc6:
    // 00528fc6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00528fcb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528fcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528fcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528fce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528fcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528fd0:
    // 00528fd0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00528fd2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00528fd4  7e1e                   -jle 0x528ff4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528ff4;
    }
    // 00528fd6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x00528fd8:
    // 00528fd8  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00528fdb  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00528fdf  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 00528fe2  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00528fe5  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00528fe8  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00528feb  40                     -inc eax
    (cpu.eax)++;
    // 00528fec  894b0c                 -mov dword ptr [ebx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00528fef  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528ff1  7ce5                   -jl 0x528fd8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528fd8;
    }
    // 00528ff3  90                     -nop 
    ;
L_0x00528ff4:
    // 00528ff4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00528ff6  8d3400                 -lea esi, [eax + eax]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00528ff9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00528ffb  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00528ffd:
    // 00528ffd  8b6b1a                 -mov ebp, dword ptr [ebx + 0x1a]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(26) /* 0x1a */);
    // 00529000  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 00529003  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529005  7d12                   -jge 0x529019
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529019;
    }
    // 00529007  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052900a  47                     -inc edi
    (cpu.edi)++;
    // 0052900b  668b4e1e               -mov cx, word ptr [esi + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(30) /* 0x1e */);
    // 0052900f  83c602                 +add esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529012  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529013  66894a1c               -mov word ptr [edx + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 00529017  ebe4                   -jmp 0x528ffd
    goto L_0x00528ffd;
L_0x00529019:
    // 00529019  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052901e  66897b1c               -mov word ptr [ebx + 0x1c], di
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.di;
    // 00529022  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529023  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529024  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529025  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529026  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529027:
    // 00529027  8b6b14                 -mov ebp, dword ptr [ebx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0052902a  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052902c  2b6b18                 -sub ebp, dword ptr [ebx + 0x18]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 0052902f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00529031  0f8c7f000000           -jl 0x5290b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005290b6;
    }
L_0x00529037:
    // 00529037  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529039  0f8d7e000000           -jge 0x5290bd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005290bd;
    }
    // 0052903f  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x00529041:
    // 00529041  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00529044  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0052904b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052904d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052904f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00529052  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529054  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529056  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052905b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052905e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529060  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529063  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00529065  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529067  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00529068  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052906b  e830410000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 00529070  017b18                 -add dword ptr [ebx + 0x18], edi
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edi));
    // 00529073  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00529075  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00529078  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052907a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052907d  895318                 -mov dword ptr [ebx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00529080  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529082  753d                   -jne 0x5290c1
    if (!cpu.flags.zf)
    {
        goto L_0x005290c1;
    }
    // 00529084  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529086  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00529089  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052908b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052908d  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052908f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00529091  7e19                   -jle 0x5290ac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005290ac;
    }
    // 00529093  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00529095:
    // 00529095  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00529098  668910                 -mov word ptr [eax], dx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
    // 0052909b  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0052909e  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005290a1  4e                     -dec esi
    (cpu.esi)--;
    // 005290a2  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 005290a5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005290a7  7fec                   -jg 0x529095
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00529095;
    }
    // 005290a9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x005290ac:
    // 005290ac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005290b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005290b6:
    // 005290b6  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 005290b8  e97affffff             -jmp 0x529037
    goto L_0x00529037;
L_0x005290bd:
    // 005290bd  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 005290bf  eb80                   -jmp 0x529041
    goto L_0x00529041;
L_0x005290c1:
    // 005290c1  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 005290c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005290c5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005290c7  7c0e                   -jl 0x5290d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005290d7;
    }
    // 005290c9  6689431c               -mov word ptr [ebx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 005290cd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005290d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005290d7:
    // 005290d7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005290d9  8d343f                 -lea esi, [edi + edi]
    cpu.esi = x86::reg32(cpu.edi + cpu.edi * 1);
L_0x005290dc:
    // 005290dc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005290df  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 005290e2  47                     -inc edi
    (cpu.edi)++;
    // 005290e3  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005290e6  668b4c2efe             -mov cx, word ptr [esi + ebp - 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ebp * 1);
    // 005290eb  40                     -inc eax
    (cpu.eax)++;
    // 005290ec  66894a1c               -mov word ptr [edx + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 005290f0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005290f2  7ce8                   -jl 0x5290dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005290dc;
    }
    // 005290f4  6689431c               -mov word ptr [ebx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 005290f8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005290fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529100  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529101  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_529104(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529104  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0052910b  66c7421c0000           -mov word ptr [edx + 0x1c], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00529111  66c742060000           -mov word ptr [edx + 6], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00529117  66c742040000           -mov word ptr [edx + 4], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052911d  895a10                 -mov dword ptr [edx + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00529120  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00529123  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00529127  c702748f5200           -mov dword ptr [edx], 0x528f74
    app->getMemory<x86::reg32>(cpu.edx) = 5410676 /*0x528f74*/;
    // 0052912d  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00529131  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 00529136  c702708f5200           -mov dword ptr [edx], 0x528f70
    app->getMemory<x86::reg32>(cpu.edx) = 5410672 /*0x528f70*/;
    // 0052913c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_529140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529140  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529141  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529142  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529143  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00529146  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00529148  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052914c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0052914f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00529151  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00529153  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529155  7d02                   -jge 0x529159
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529159;
    }
    // 00529157  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00529159:
    // 00529159  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052915b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052915d  7e19                   -jle 0x529178
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529178;
    }
    // 0052915f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x00529163:
    // 00529163  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529166  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 00529169  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052916c  40                     -inc eax
    (cpu.eax)++;
    // 0052916d  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00529171  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529173  7cee                   -jl 0x529163
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529163;
    }
    // 00529175  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00529178:
    // 00529178  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052917a  7d1c                   -jge 0x529198
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529198;
    }
    // 0052917c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529180  8d1c00                 -lea ebx, [eax + eax]
    cpu.ebx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00529183  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00529185:
    // 00529185  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529188  668b33                 -mov si, word ptr [ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx);
    // 0052918b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052918e  40                     -inc eax
    (cpu.eax)++;
    // 0052918f  668971fe               -mov word ptr [ecx - 2], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.si;
    // 00529193  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529195  7cee                   -jl 0x529185
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529185;
    }
    // 00529197  90                     -nop 
    ;
L_0x00529198:
    // 00529198  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052919b  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052919d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052919f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005291a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005291a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005291a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005291a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5291a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005291a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005291a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005291aa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005291ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005291ac  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 005291af  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005291b1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005291b3  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 005291b6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005291b8  7e55                   -jle 0x52920f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052920f;
    }
    // 005291ba  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 005291bd  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 005291c1  8d6826                 -lea ebp, [eax + 0x26]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(38) /* 0x26 */);
L_0x005291c4:
    // 005291c4  66837e2400             +cmp word ptr [esi + 0x24], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005291c9  7562                   -jne 0x52922d
    if (!cpu.flags.zf)
    {
        goto L_0x0052922d;
    }
    // 005291cb  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005291ce  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 005291d1  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 005291d4  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005291d6  7d76                   -jge 0x52924e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052924e;
    }
    // 005291d8  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 005291dc  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005291e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005291e3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005291e6  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005291e8  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005291eb  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 005291f1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005291f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005291f4  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005291f7  e8a43f0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 005291fc  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005291ff  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529202  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529205  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529208  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x0052920b:
    // 0052920b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052920d  7fb5                   -jg 0x5291c4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005291c4;
    }
L_0x0052920f:
    // 0052920f  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 00529212  01460c                 -add dword ptr [esi + 0xc], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529215  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00529218:
    // 00529218  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052921a  0f8c3e010000           -jl 0x52935e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052935e;
    }
    // 00529220  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529225  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00529228  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529229  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052922a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052922b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052922c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052922d:
    // 0052922d  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00529231  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00529233  8b4622                 -mov eax, dword ptr [esi + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00529236  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00529238  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052923b  e800ffffff             -call 0x529140
    cpu.esp -= 4;
    sub_529140(app, cpu);
    if (cpu.terminate) return;
    // 00529240  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529244  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529246  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529248  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 0052924c  ebbd                   -jmp 0x52920b
    goto L_0x0052920b;
L_0x0052924e:
    // 0052924e  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00529252  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529255  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052925a  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0052925e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529260  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529263  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529265  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 0052926b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052926e  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00529271  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529273  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529274  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00529277  e8243f0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 0052927c  8346181c               -add dword ptr [esi + 0x18], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529280  668b5e20               -mov bx, word ptr [esi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00529284  668b4618               -mov ax, word ptr [esi + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00529288  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 0052928d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052928f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529291  668b8694000000         -mov ax, word ptr [esi + 0x94]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 00529298  66895624               -mov word ptr [esi + 0x24], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.dx;
    // 0052929c  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 005292a0  668b8696000000         -mov ax, word ptr [esi + 0x96]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(150) /* 0x96 */);
    // 005292a7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005292a9  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 005292ad  41                     -inc ecx
    (cpu.ecx)++;
    // 005292ae  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005292b1  66894e24               -mov word ptr [esi + 0x24], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 005292b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005292b7  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005292bc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005292bf  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005292c1  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 005292c4  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 005292c7  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005292ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005292cc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005292cf  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005292d1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005292d4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005292d6  0f8476000000           -je 0x529352
    if (cpu.flags.zf)
    {
        goto L_0x00529352;
    }
    // 005292dc  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 005292de  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 005292e2  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005292e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005292e9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005292ec  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005292ee  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005292f1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005292f3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005292f5  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005292f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005292f9  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005292fc  e89f3e0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 00529301  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00529304  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529307  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052930a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052930c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052930f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529311  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00529315  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 0052931a  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0052931e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00529320  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00529322  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529324  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00529327  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00529329  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052932b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052932d  7e23                   -jle 0x529352
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529352;
    }
L_0x0052932f:
    // 0052932f  8b4e22                 -mov ecx, dword ptr [esi + 0x22]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00529332  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529335  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 00529338  66895c4e26             -mov word ptr [esi + ecx*2 + 0x26], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(38) /* 0x26 */ + cpu.ecx * 2) = cpu.bx;
    // 0052933d  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529341  43                     -inc ebx
    (cpu.ebx)++;
    // 00529342  42                     -inc edx
    (cpu.edx)++;
    // 00529343  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 00529347  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0052934b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052934e  39da                   +cmp edx, ebx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529350  7cdd                   -jl 0x52932f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052932f;
    }
L_0x00529352:
    // 00529352  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00529356  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00529359  e9adfeffff             -jmp 0x52920b
    goto L_0x0052920b;
L_0x0052935e:
    // 0052935e  8b4622                 -mov eax, dword ptr [esi + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00529361  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529364  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00529367  668b12                 -mov dx, word ptr [edx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx);
    // 0052936a  6689544626             -mov word ptr [esi + eax*2 + 0x26], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(38) /* 0x26 */ + cpu.eax * 2) = cpu.dx;
    // 0052936f  83460c02               +add dword ptr [esi + 0xc], 2
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529373  668b4e24               -mov cx, word ptr [esi + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529377  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529378  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529379  66894e24               -mov word ptr [esi + 0x24], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 0052937d  e996feffff             -jmp 0x529218
    goto L_0x00529218;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_529384(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529384  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00529385  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529386  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529387  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529388  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052938b  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052938e  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00529391  8b5022                 -mov edx, dword ptr [eax + 0x22]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(34) /* 0x22 */);
    // 00529394  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00529396  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00529399  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052939c  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052939e  7d2d                   -jge 0x5293cd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005293cd;
    }
    // 005293a0  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 005293a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x005293a7:
    // 005293a7  8b5622                 -mov edx, dword ptr [esi + 0x22]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 005293aa  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 005293ad  39d3                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005293af  0f8d75000000           -jge 0x52942a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052942a;
    }
    // 005293b5  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005293b8  668b4826               -mov cx, word ptr [eax + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 005293bc  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 005293bf  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005293c2  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005293c5  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005293c7  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005293c8  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 005293cb  ebda                   -jmp 0x5293a7
    goto L_0x005293a7;
L_0x005293cd:
    // 005293cd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005293cf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005293d1  7e21                   -jle 0x5293f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005293f4;
    }
    // 005293d3  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
L_0x005293d6:
    // 005293d6  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005293d9  668b4826               -mov cx, word ptr [eax + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 005293dd  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 005293e0  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005293e3  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005293e6  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005293e9  43                     -inc ebx
    (cpu.ebx)++;
    // 005293ea  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 005293ed  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005293ef  7ce5                   -jl 0x5293d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005293d6;
    }
    // 005293f1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x005293f4:
    // 005293f4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005293f6  8d141b                 -lea edx, [ebx + ebx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 005293f9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 005293fb  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x005293fd:
    // 005293fd  8b6e22                 -mov ebp, dword ptr [esi + 0x22]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00529400  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 00529403  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529405  7d12                   -jge 0x529419
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529419;
    }
    // 00529407  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052940a  47                     -inc edi
    (cpu.edi)++;
    // 0052940b  668b4a26               -mov cx, word ptr [edx + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(38) /* 0x26 */);
    // 0052940f  83c202                 +add edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529412  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529413  66894824               -mov word ptr [eax + 0x24], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 00529417  ebe4                   -jmp 0x5293fd
    goto L_0x005293fd;
L_0x00529419:
    // 00529419  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052941e  66897e24               -mov word ptr [esi + 0x24], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.di;
    // 00529422  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00529425  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529426  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529427  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529428  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529429  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052942a:
    // 0052942a  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052942d  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00529430  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00529433  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529435  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529437  83ef1b                 -sub edi, 0x1b
    (cpu.edi) -= x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 0052943a  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0052943d  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052943f  7e02                   -jle 0x529443
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529443;
    }
    // 00529441  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x00529443:
    // 00529443  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00529445  0f8cba000000           -jl 0x529505
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529505;
    }
L_0x0052944b:
    // 0052944b  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052944e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00529455  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00529457  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529459  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052945c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052945e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529460  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529465  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529468  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052946a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052946d  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0052946f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529471  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529472  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00529475  e8263d0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 0052947a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052947d  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00529480  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00529482  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00529484  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00529486  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00529488  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0052948b  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052948d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0052948f  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00529492  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00529496  8d0c00                 -lea ecx, [eax + eax]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00529499  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052949b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052949d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052949f  90                     -nop 
    ;
L_0x005294a0:
    // 005294a0  7c6a                   -jl 0x52950c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052950c;
    }
    // 005294a2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005294a5  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005294a8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005294aa  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005294ac  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005294af  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005294b2  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005294b5  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 005294b9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005294bb  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 005294be  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005294c1  7d35                   -jge 0x5294f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005294f8;
    }
    // 005294c3  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 005294c7  66898694000000         -mov word ptr [esi + 0x94], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(148) /* 0x94 */) = cpu.ax;
    // 005294ce  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 005294d2  66898696000000         -mov word ptr [esi + 0x96], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(150) /* 0x96 */) = cpu.ax;
    // 005294d9  8b8698000000           -mov eax, dword ptr [esi + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 005294df  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 005294e2  c700a8915200           -mov dword ptr [eax], 0x5291a8
    app->getMemory<x86::reg32>(cpu.eax) = 5411240 /*0x5291a8*/;
    // 005294e8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005294ea  7e0c                   -jle 0x5294f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005294f8;
    }
    // 005294ec  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005294ee  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005294f0  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005294f3  e8b0fcffff             -call 0x5291a8
    cpu.esp -= 4;
    sub_5291a8(app, cpu);
    if (cpu.terminate) return;
L_0x005294f8:
    // 005294f8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005294fd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00529500  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529501  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529502  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529503  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529504  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529505:
    // 00529505  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00529507  e93fffffff             -jmp 0x52944b
    goto L_0x0052944b;
L_0x0052950c:
    // 0052950c  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052950f  8d2c16                 -lea ebp, [esi + edx]
    cpu.ebp = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00529512  668b0c01               -mov cx, word ptr [ecx + eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 1);
    // 00529516  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529519  66894d26               -mov word ptr [ebp + 0x26], cx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(38) /* 0x26 */) = cpu.cx;
    // 0052951d  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529521  43                     -inc ebx
    (cpu.ebx)++;
    // 00529522  41                     -inc ecx
    (cpu.ecx)++;
    // 00529523  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529526  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052952a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052952c  e96fffffff             -jmp 0x5294a0
    goto L_0x005294a0;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_529534(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529534  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0052953b  66c742240000           -mov word ptr [edx + 0x24], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00529541  66c742060000           -mov word ptr [edx + 6], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00529547  66c742040000           -mov word ptr [edx + 4], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052954d  895a10                 -mov dword ptr [edx + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00529550  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00529553  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529557  894a1c                 -mov dword ptr [edx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0052955a  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052955e  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00529561  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00529565  898a98000000           -mov dword ptr [edx + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0052956b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052956f  c70184935200           -mov dword ptr [ecx], 0x529384
    app->getMemory<x86::reg32>(cpu.ecx) = 5411716 /*0x529384*/;
    // 00529575  b89c000000             -mov eax, 0x9c
    cpu.eax = 156 /*0x9c*/;
    // 0052957a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00529580  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_529590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529590  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529591  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529592  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529593  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00529596  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00529598  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0052959b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052959d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052959f  0f84cc000000           -je 0x529671
    if (cpu.flags.zf)
    {
        goto L_0x00529671;
    }
    // 005295a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005295a6  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 005295a9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005295ab  0f8ea2000000           -jle 0x529653
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529653;
    }
    // 005295b1  8d680c                 -lea ebp, [eax + 0xc]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 005295b4  8d501e                 -lea edx, [eax + 0x1e]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 005295b7  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005295bb  8d5014                 -lea edx, [eax + 0x14]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 005295be  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005295c1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005295c5  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x005295c9:
    // 005295c9  66837e1c00             +cmp word ptr [esi + 0x1c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005295ce  0f85a9000000           -jne 0x52967d
    if (!cpu.flags.zf)
    {
        goto L_0x0052967d;
    }
    // 005295d4  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005295d7  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 005295da  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 005295dd  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005295df  0f8dbf000000           -jge 0x5296a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005296a4;
    }
    // 005295e5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005295e7  2b5618                 -sub edx, dword ptr [esi + 0x18]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
    // 005295ea  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 005295ef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005295f1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005295f4  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005295f6  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005295fa  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 005295fd  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00529601  39c7                   +cmp edi, eax
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529603  7d11                   -jge 0x529616
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529616;
    }
    // 00529605  8d571b                 -lea edx, [edi + 0x1b]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(27) /* 0x1b */);
    // 00529608  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052960a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052960d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052960f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00529612  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x00529616:
    // 00529616  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 0052961a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052961e  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00529620  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 00529625  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529627  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052962a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052962c  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052962f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529631  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529632  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00529635  e8663b0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 0052963a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052963d  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00529640  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00529644  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529646  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529648  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x0052964b:
    // 0052964b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052964d  0f8f76ffffff           -jg 0x5295c9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005295c9;
    }
L_0x00529653:
    // 00529653  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 00529656  01460c                 -add dword ptr [esi + 0xc], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529659  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0052965c:
    // 0052965c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052965e  0f8ceb000000           -jl 0x52974f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052974f;
    }
    // 00529664  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529669  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052966a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052966d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052966e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052966f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529670  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529671:
    // 00529671  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00529676  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00529679  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052967a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052967b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052967c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052967d:
    // 0052967d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00529681  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00529683  8b461a                 -mov eax, dword ptr [esi + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00529686  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00529688  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052968b  e8b0faffff             -call 0x529140
    cpu.esp -= 4;
    sub_529140(app, cpu);
    if (cpu.terminate) return;
    // 00529690  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00529694  668b5e1c               -mov bx, word ptr [esi + 0x1c]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529698  2b5c2410               -sub ebx, dword ptr [esp + 0x10]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052969c  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052969e  66895e1c               -mov word ptr [esi + 0x1c], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.bx;
    // 005296a2  eba7                   -jmp 0x52964b
    goto L_0x0052964b;
L_0x005296a4:
    // 005296a4  837e1001               +cmp dword ptr [esi + 0x10], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005296a8  744f                   -je 0x5296f9
    if (cpu.flags.zf)
    {
        goto L_0x005296f9;
    }
    // 005296aa  3b4e18                 +cmp ecx, dword ptr [esi + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005296ad  7e4a                   -jle 0x5296f9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005296f9;
    }
    // 005296af  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 005296b3  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 005296b8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005296ba  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005296bd  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005296bf  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005296c2  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 005296c8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005296ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005296cb  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005296ce  e8cd3a0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 005296d3  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005296d6  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005296d9  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 005296dc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005296de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005296e1  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005296e3  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 005296e8  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005296eb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005296ed  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 005296ef  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 005296f2  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005296f4  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005296f6  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x005296f9:
    // 005296f9  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005296fd  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529701  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00529707  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052970a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052970c  7424                   -je 0x529732
    if (cpu.flags.zf)
    {
        goto L_0x00529732;
    }
    // 0052970e  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 00529711  66895606               -mov word ptr [esi + 6], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 00529715  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00529719  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0052971d  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529720  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00529727  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052972a  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052972d  e919ffffff             -jmp 0x52964b
    goto L_0x0052964b;
L_0x00529732:
    // 00529732  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529735  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00529737  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00529739  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052973b  e8006ffbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00529740  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529743  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00529745  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00529747  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052974a  e904ffffff             -jmp 0x529653
    goto L_0x00529653;
L_0x0052974f:
    // 0052974f  8b461a                 -mov eax, dword ptr [esi + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00529752  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529755  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00529758  668b12                 -mov dx, word ptr [edx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx);
    // 0052975b  668954461e             -mov word ptr [esi + eax*2 + 0x1e], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(30) /* 0x1e */ + cpu.eax * 2) = cpu.dx;
    // 00529760  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529763  668b4e1c               -mov cx, word ptr [esi + 0x1c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529767  83c302                 +add ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052976a  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052976b  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052976e  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052976f  66894e1c               -mov word ptr [esi + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 00529773  e9e4feffff             -jmp 0x52965c
    goto L_0x0052965c;
}

/* align: skip  */
void Application::sub_529778(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529778  c7421001000000         -mov dword ptr [edx + 0x10], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 0052977f  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00529786  66c7421c0000           -mov word ptr [edx + 0x1c], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052978c  66c742060000           -mov word ptr [edx + 6], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00529792  66c742040000           -mov word ptr [edx + 4], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00529798  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0052979b  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052979f  c70290955200           -mov dword ptr [edx], 0x529590
    app->getMemory<x86::reg32>(cpu.edx) = 5412240 /*0x529590*/;
    // 005297a5  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005297a9  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 005297ae  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 005297b4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5297c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005297c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005297c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005297c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005297c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005297c4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005297c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005297c9  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005297cd  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005297cf  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 005297d2  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 005297d5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005297d7  7556                   -jne 0x52982f
    if (!cpu.flags.zf)
    {
        goto L_0x0052982f;
    }
L_0x005297d9:
    // 005297d9  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005297dc  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005297df  8d4526                 -lea eax, [ebp + 0x26]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(38) /* 0x26 */);
    // 005297e2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005297e6  8d7d14                 -lea edi, [ebp + 0x14]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(20) /* 0x14 */);
L_0x005297e9:
    // 005297e9  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005297ee  0f8e91010000           -jle 0x529985
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529985;
    }
    // 005297f4  66837d2400             +cmp word ptr [ebp + 0x24], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(36) /* 0x24 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005297f9  7445                   -je 0x529840
    if (cpu.flags.zf)
    {
        goto L_0x00529840;
    }
    // 005297fb  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 005297fe  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529802  8b4522                 -mov eax, dword ptr [ebp + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(34) /* 0x22 */);
    // 00529805  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529809  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052980c  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529810  e82bf9ffff             -call 0x529140
    cpu.esp -= 4;
    sub_529140(app, cpu);
    if (cpu.terminate) return;
    // 00529815  668b4d24               -mov cx, word ptr [ebp + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00529819  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052981c  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052981e  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529820  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529822  66894d24               -mov word ptr [ebp + 0x24], cx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 00529826  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0052982a  895520                 -mov dword ptr [ebp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0052982d  ebba                   -jmp 0x5297e9
    goto L_0x005297e9;
L_0x0052982f:
    // 0052982f  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00529832  e86181feff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 00529837  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0052983e  eb99                   -jmp 0x5297d9
    goto L_0x005297d9;
L_0x00529840:
    // 00529840  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00529843  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00529846  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00529849  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052984b  7d70                   -jge 0x5298bd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005298bd;
    }
    // 0052984d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052984f  2b5518                 -sub edx, dword ptr [ebp + 0x18]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 00529852  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529857  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529859  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052985c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052985e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00529860  0faff1                 -imul esi, ecx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00529863  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529867  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529869  7f43                   -jg 0x5298ae
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005298ae;
    }
L_0x0052986b:
    // 0052986b  6b55180f               -imul edx, dword ptr [ebp + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 0052986f  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529874  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529876  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529879  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052987b  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052987e  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 00529881  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529883  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529884  895508                 -mov dword ptr [ebp + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00529887  e814390000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 0052988c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052988f  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00529892  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00529895  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529899  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052989b  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052989d  895518                 -mov dword ptr [ebp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005298a0  29f1                   +sub ecx, esi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005298a2  895d20                 -mov dword ptr [ebp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 005298a5  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 005298a9  e93bffffff             -jmp 0x5297e9
    goto L_0x005297e9;
L_0x005298ae:
    // 005298ae  8d531b                 -lea edx, [ebx + 0x1b]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(27) /* 0x1b */);
    // 005298b1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005298b3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005298b6  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005298b8  6bf01c                 +imul esi, eax, 0x1c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(28 /*0x1c*/));
        cpu.esi = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.esi)));
    }
    // 005298bb  ebae                   -jmp 0x52986b
    goto L_0x0052986b;
L_0x005298bd:
    // 005298bd  3b5d18                 +cmp ebx, dword ptr [ebp + 0x18]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005298c0  7e5b                   -jle 0x52991d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052991d;
    }
    // 005298c2  6b55180f               -imul edx, dword ptr [ebp + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 005298c6  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005298cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005298cd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005298d0  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005298d2  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 005298d5  c745001c000000         -mov dword ptr [ebp], 0x1c
    app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 005298dc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005298de  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005298df  895508                 -mov dword ptr [ebp + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005298e2  e8b9380000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 005298e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005298ea  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005298ed  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005298f0  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005298f3  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005298f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005298f8  895518                 -mov dword ptr [ebp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005298fb  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 00529900  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00529902  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529906  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529908  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052990a  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052990c  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052990e  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00529911  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00529914  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00529916  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052991a  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0052991d:
    // 0052991d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052991f  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00529922  e8d57ffeff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 00529927  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052992a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052992c  7424                   -je 0x529952
    if (cpu.flags.zf)
    {
        goto L_0x00529952;
    }
    // 0052992e  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 00529931  66895506               -mov word ptr [ebp + 6], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 00529935  668b4002               -mov ax, word ptr [eax + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00529939  66894504               -mov word ptr [ebp + 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0052993d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00529940  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00529947  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052994a  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052994d  e997feffff             -jmp 0x5297e9
    goto L_0x005297e9;
L_0x00529952:
    // 00529952  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529956  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00529958  0f8e8bfeffff           -jle 0x5297e9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005297e9;
    }
    // 0052995e  837d2000               +cmp dword ptr [ebp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529962  740d                   -je 0x529971
    if (cpu.flags.zf)
    {
        goto L_0x00529971;
    }
    // 00529964  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00529967  8d1c09                 -lea ebx, [ecx + ecx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 0052996a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052996c  e8cf6cfbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x00529971:
    // 00529971  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529975  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00529978  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052997a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0052997c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052997e  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00529982  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x00529985:
    // 00529985  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529989  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052998c  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052998e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529990  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529994  89550c                 -mov dword ptr [ebp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00529997  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00529999  7c0b                   -jl 0x5299a6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005299a6;
    }
    // 0052999b  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052999e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005299a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005299a6:
    // 005299a6  6bc1ff                 -imul eax, ecx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 005299a9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005299ad  8d0c00                 -lea ecx, [eax + eax]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 005299b0  8b4522                 -mov eax, dword ptr [ebp + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(34) /* 0x22 */);
    // 005299b3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 005299b6  8d7d26                 -lea edi, [ebp + 0x26]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(38) /* 0x26 */);
    // 005299b9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005299bb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005299bd  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 005299bf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005299c0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005299c2  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 005299c5  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 005299c7  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 005299c9  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 005299cc  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 005299ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299cf  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005299d3  668b5d24               -mov bx, word ptr [ebp + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 005299d7  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 005299da  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005299dc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005299e0  66895d24               -mov word ptr [ebp + 0x24], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 005299e4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005299e6  897520                 -mov dword ptr [ebp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 005299e9  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 005299ec  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005299ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5299f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005299f4  e867370000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 005299f9  c7421000000000         -mov dword ptr [edx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00529a00  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00529a07  66c742240000           -mov word ptr [edx + 0x24], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00529a0d  66c742060000           -mov word ptr [edx + 6], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00529a13  66c742040000           -mov word ptr [edx + 4], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00529a19  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00529a20  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00529a23  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00529a27  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00529a2a  c700c0975200           -mov dword ptr [eax], 0x5297c0
    app->getMemory<x86::reg32>(cpu.eax) = 5412800 /*0x5297c0*/;
    // 00529a30  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00529a34  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00529a3a  b85c000000             -mov eax, 0x5c
    cpu.eax = 92 /*0x5c*/;
    // 00529a3f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_529a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529a50  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00529a53  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_529a54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529a54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00529a55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529a56  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529a57  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529a58  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529a5b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00529a5d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00529a5f  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00529a62  8b7818                 -mov edi, dword ptr [eax + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00529a65  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00529a67  39f9                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529a69  7d3c                   -jge 0x529aa7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529aa7;
    }
    // 00529a6b  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00529a6e  8b501e                 -mov edx, dword ptr [eax + 0x1e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 00529a71  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00529a74  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00529a76  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529a78  7e3a                   -jle 0x529ab4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529ab4;
    }
    // 00529a7a  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00529a7f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00529a81:
    // 00529a81  8b4b1e                 -mov ecx, dword ptr [ebx + 0x1e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00529a84  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529a87  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529a89  0f8d8b000000           -jge 0x529b1a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529b1a;
    }
    // 00529a8f  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529a92  668b7824               -mov di, word ptr [eax + 0x24]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00529a96  668939                 -mov word ptr [ecx], di
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.di;
    // 00529a99  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529a9c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529a9f  01e9                   +add ecx, ebp
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529aa1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529aa2  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00529aa5  ebda                   -jmp 0x529a81
    goto L_0x00529a81;
L_0x00529aa7:
    // 00529aa7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00529aac  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529aaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ab0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ab1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ab2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ab3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529ab4:
    // 00529ab4  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00529ab6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00529ab8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00529aba  7e1c                   -jle 0x529ad8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529ad8;
    }
L_0x00529abc:
    // 00529abc  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529abf  668b7824               -mov di, word ptr [eax + 0x24]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00529ac3  668939                 -mov word ptr [ecx], di
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.di;
    // 00529ac6  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529ac9  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529acc  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529acf  42                     -inc edx
    (cpu.edx)++;
    // 00529ad0  896b10                 -mov dword ptr [ebx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00529ad3  39f2                   +cmp edx, esi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529ad5  7ce5                   -jl 0x529abc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529abc;
    }
    // 00529ad7  90                     -nop 
    ;
L_0x00529ad8:
    // 00529ad8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00529ada  8d3412                 -lea esi, [edx + edx]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00529add  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00529ae0  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00529ae2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00529ae4:
    // 00529ae4  8b4b1e                 -mov ecx, dword ptr [ebx + 0x1e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00529ae7  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529aea  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529aec  7d18                   -jge 0x529b06
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529b06;
    }
    // 00529aee  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529af1  668b4e24               -mov cx, word ptr [esi + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529af5  66894822               -mov word ptr [eax + 0x22], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(34) /* 0x22 */) = cpu.cx;
    // 00529af9  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00529afc  83c602                 +add esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529aff  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529b00  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529b01  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00529b04  ebde                   -jmp 0x529ae4
    goto L_0x00529ae4;
L_0x00529b06:
    // 00529b06  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00529b09  66894320               -mov word ptr [ebx + 0x20], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ax;
    // 00529b0d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529b12  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529b15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529b16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529b17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529b18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529b19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529b1a:
    // 00529b1a  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00529b1d  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00529b20  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00529b22  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529b24  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00529b26  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00529b28  0f8c8b000000           -jl 0x529bb9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529bb9;
    }
L_0x00529b2e:
    // 00529b2e  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529b30  0f8d8a000000           -jge 0x529bc0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529bc0;
    }
    // 00529b36  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x00529b39:
    // 00529b39  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00529b3c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00529b3e  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00529b41  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529b43  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529b45  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00529b48  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529b4a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529b4c  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529b51  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529b54  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529b56  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00529b59  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529b5b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00529b5c  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00529b5f  e8ec360000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 00529b64  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529b67  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00529b6a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00529b6d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529b6f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00529b71  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00529b73  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00529b76  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529b78  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00529b7b  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00529b7e  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529b80  7546                   -jne 0x529bc8
    if (!cpu.flags.zf)
    {
        goto L_0x00529bc8;
    }
    // 00529b82  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00529b84  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00529b87  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00529b89  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529b8b  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529b8d  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00529b8f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00529b91  7e19                   -jle 0x529bac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529bac;
    }
    // 00529b93  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00529b95:
    // 00529b95  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529b98  668910                 -mov word ptr [eax], dx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
    // 00529b9b  8b7b10                 -mov edi, dword ptr [ebx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529b9e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529ba1  4e                     -dec esi
    (cpu.esi)--;
    // 00529ba2  897b10                 -mov dword ptr [ebx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00529ba5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00529ba7  7fec                   -jg 0x529b95
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00529b95;
    }
    // 00529ba9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00529bac:
    // 00529bac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529bb1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529bb4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529bb9:
    // 00529bb9  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00529bbb  e96effffff             -jmp 0x529b2e
    goto L_0x00529b2e;
L_0x00529bc0:
    // 00529bc0  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00529bc3  e971ffffff             -jmp 0x529b39
    goto L_0x00529b39;
L_0x00529bc8:
    // 00529bc8  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529bcd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00529bcf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00529bd1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529bd4  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529bd6  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00529bd8  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529bda  6bf6ff                 -imul esi, esi, -1
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 00529bdd  83fee4                 +cmp esi, -0x1c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-28 /*-0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529be0  7502                   -jne 0x529be4
    if (!cpu.flags.zf)
    {
        goto L_0x00529be4;
    }
    // 00529be2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00529be4:
    // 00529be4  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00529be6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00529be8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00529bea  7c11                   -jl 0x529bfd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529bfd;
    }
    // 00529bec  66895320               -mov word ptr [ebx + 0x20], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 00529bf0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529bf5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529bf8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bf9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bfa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bfb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bfc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529bfd:
    // 00529bfd  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00529bff  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
L_0x00529c02:
    // 00529c02  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529c05  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529c08  46                     -inc esi
    (cpu.esi)++;
    // 00529c09  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529c0c  668b7c28fe             -mov di, word ptr [eax + ebp - 2]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-2) /* -0x2 */ + cpu.ebp * 1);
    // 00529c11  42                     -inc edx
    (cpu.edx)++;
    // 00529c12  66897922               -mov word ptr [ecx + 0x22], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(34) /* 0x22 */) = cpu.di;
    // 00529c16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00529c18  7ce8                   -jl 0x529c02
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529c02;
    }
    // 00529c1a  66895320               -mov word ptr [ebx + 0x20], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 00529c1e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529c23  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529c26  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529c27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529c28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529c29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529c2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_529c2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529c2c  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00529c33  66c742200000           -mov word ptr [edx + 0x20], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00529c39  66c742060000           -mov word ptr [edx + 6], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00529c3f  66c742040000           -mov word ptr [edx + 4], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00529c45  66c7420a0000           -mov word ptr [edx + 0xa], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 00529c4b  66c742080000           -mov word ptr [edx + 8], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00529c51  895a14                 -mov dword ptr [edx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00529c54  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00529c57  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00529c5b  c702549a5200           -mov dword ptr [edx], 0x529a54
    app->getMemory<x86::reg32>(cpu.edx) = 5413460 /*0x529a54*/;
    // 00529c61  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00529c65  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 00529c6a  c702509a5200           -mov dword ptr [edx], 0x529a50
    app->getMemory<x86::reg32>(cpu.edx) = 5413456 /*0x529a50*/;
    // 00529c70  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_529c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529c80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529c81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529c82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529c83  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00529c86  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00529c88  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00529c8c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00529c8f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00529c91  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00529c93  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529c95  7d02                   -jge 0x529c99
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529c99;
    }
    // 00529c97  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00529c99:
    // 00529c99  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00529c9b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00529c9d  7e21                   -jle 0x529cc0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529cc0;
    }
    // 00529c9f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x00529ca3:
    // 00529ca3  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529ca6  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 00529ca9  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529cac  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00529cb0  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529cb3  668b59fe               -mov bx, word ptr [ecx - 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 00529cb7  40                     -inc eax
    (cpu.eax)++;
    // 00529cb8  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00529cbc  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529cbe  7ce3                   -jl 0x529ca3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529ca3;
    }
L_0x00529cc0:
    // 00529cc0  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529cc2  7d28                   -jge 0x529cec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529cec;
    }
    // 00529cc4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529cc8  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00529ccf  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00529cd1:
    // 00529cd1  668b33                 -mov si, word ptr [ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx);
    // 00529cd4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529cd7  668931                 -mov word ptr [ecx], si
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.si;
    // 00529cda  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529cdd  668b73fe               -mov si, word ptr [ebx - 2]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */);
    // 00529ce1  40                     -inc eax
    (cpu.eax)++;
    // 00529ce2  668971fe               -mov word ptr [ecx - 2], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.si;
    // 00529ce6  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529ce8  7ce7                   -jl 0x529cd1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529cd1;
    }
    // 00529cea  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00529cec:
    // 00529cec  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00529cef  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00529cf1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00529cf3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00529cf6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529cf7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529cf8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529cf9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_529cfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529cfc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00529cfd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529cfe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529cff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529d00  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00529d03  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00529d05  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00529d07  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00529d0a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00529d0c  7e59                   -jle 0x529d67
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529d67;
    }
    // 00529d0e  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00529d11  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00529d15  8d682c                 -lea ebp, [eax + 0x2c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
L_0x00529d18:
    // 00529d18  66837e2800             +cmp word ptr [esi + 0x28], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00529d1d  756a                   -jne 0x529d89
    if (!cpu.flags.zf)
    {
        goto L_0x00529d89;
    }
    // 00529d1f  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529d22  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529d25  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00529d28  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529d2a  0f8d7a000000           -jge 0x529daa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529daa;
    }
    // 00529d30  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00529d34  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529d39  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529d3b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529d3e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529d40  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00529d43  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00529d49  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529d4b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529d4c  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00529d4f  e8fc340000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 00529d54  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529d57  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529d5a  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529d5d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529d60  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00529d63:
    // 00529d63  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00529d65  7fb1                   -jg 0x529d18
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00529d18;
    }
L_0x00529d67:
    // 00529d67  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00529d6e  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529d71  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00529d74:
    // 00529d74  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00529d76  0f8c66010000           -jl 0x529ee2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529ee2;
    }
    // 00529d7c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529d81  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00529d84  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529d85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529d86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529d87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529d88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529d89:
    // 00529d89  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00529d8d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00529d8f  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529d92  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00529d94  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00529d97  e8e4feffff             -call 0x529c80
    cpu.esp -= 4;
    sub_529c80(app, cpu);
    if (cpu.terminate) return;
    // 00529d9c  668b5e28               -mov bx, word ptr [esi + 0x28]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00529da0  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529da2  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529da4  66895e28               -mov word ptr [esi + 0x28], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 00529da8  ebb9                   -jmp 0x529d63
    goto L_0x00529d63;
L_0x00529daa:
    // 00529daa  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00529dae  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529db1  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529db6  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 00529dba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529dbc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529dbf  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529dc1  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00529dc7  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00529dca  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00529dcd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529dcf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529dd0  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00529dd3  e878340000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 00529dd8  83461c1c               -add dword ptr [esi + 0x1c], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529ddc  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529de0  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529de4  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 00529de9  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00529deb  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529ded  668b8608010000         -mov ax, word ptr [esi + 0x108]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(264) /* 0x108 */);
    // 00529df4  66895628               -mov word ptr [esi + 0x28], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.dx;
    // 00529df8  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 00529dfc  668b860a010000         -mov ax, word ptr [esi + 0x10a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(266) /* 0x10a */);
    // 00529e03  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 00529e07  668b860c010000         -mov ax, word ptr [esi + 0x10c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 00529e0e  6689460a               -mov word ptr [esi + 0xa], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 00529e12  668b860e010000         -mov ax, word ptr [esi + 0x10e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(270) /* 0x10e */);
    // 00529e19  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00529e1b  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00529e1f  41                     -inc ecx
    (cpu.ecx)++;
    // 00529e20  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00529e23  66894e28               -mov word ptr [esi + 0x28], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 00529e27  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529e29  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529e2e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529e31  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529e33  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00529e36  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00529e39  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00529e3c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529e3e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529e41  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529e43  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529e46  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00529e48  0f8488000000           -je 0x529ed6
    if (cpu.flags.zf)
    {
        goto L_0x00529ed6;
    }
    // 00529e4e  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00529e50  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00529e54  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529e59  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529e5b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529e5e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529e60  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00529e63  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529e65  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00529e67  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00529e6a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529e6b  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00529e6e  e8dd330000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 00529e73  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529e76  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529e79  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00529e7c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00529e7e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529e81  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529e83  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 00529e88  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00529e8c  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529e8e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529e90  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00529e93  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00529e96  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00529e98  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00529e9c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00529e9e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00529ea0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00529ea2  7e32                   -jle 0x529ed6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529ed6;
    }
L_0x00529ea4:
    // 00529ea4  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529ea7  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529eaa  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 00529ead  66895c8e2c             -mov word ptr [esi + ecx*4 + 0x2c], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = cpu.bx;
    // 00529eb2  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529eb5  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529eb8  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00529ebc  66895c8e2e             -mov word ptr [esi + ecx*4 + 0x2e], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */ + cpu.ecx * 4) = cpu.bx;
    // 00529ec1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529ec4  668b5e28               -mov bx, word ptr [esi + 0x28]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00529ec8  42                     -inc edx
    (cpu.edx)++;
    // 00529ec9  43                     -inc ebx
    (cpu.ebx)++;
    // 00529eca  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00529ece  66895e28               -mov word ptr [esi + 0x28], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 00529ed2  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529ed4  7cce                   -jl 0x529ea4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529ea4;
    }
L_0x00529ed6:
    // 00529ed6  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00529eda  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00529edd  e981feffff             -jmp 0x529d63
    goto L_0x00529d63;
L_0x00529ee2:
    // 00529ee2  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529ee5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00529ee8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00529eeb  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529eee  8d0c06                 -lea ecx, [esi + eax]
    cpu.ecx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00529ef1  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 00529ef4  6689412c               -mov word ptr [ecx + 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.ax;
    // 00529ef8  8b5626                 -mov edx, dword ptr [esi + 0x26]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529efb  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529efe  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00529f01  668b4002               -mov ax, word ptr [eax + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00529f05  668944962e             -mov word ptr [esi + edx*4 + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */ + cpu.edx * 4) = cpu.ax;
    // 00529f0a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f0d  668b4e28               -mov cx, word ptr [esi + 0x28]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00529f11  83c204                 +add edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529f14  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529f15  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00529f18  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529f19  66894e28               -mov word ptr [esi + 0x28], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 00529f1d  e952feffff             -jmp 0x529d74
    goto L_0x00529d74;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_529f24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529f24  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00529f25  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529f26  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529f27  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529f28  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00529f2b  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00529f2e  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00529f31  8b5026                 -mov edx, dword ptr [eax + 0x26]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 00529f34  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00529f36  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00529f39  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00529f3c  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529f3e  7d38                   -jge 0x529f78
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529f78;
    }
    // 00529f40  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 00529f45  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00529f47:
    // 00529f47  8b5626                 -mov edx, dword ptr [esi + 0x26]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529f4a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00529f4d  39d3                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529f4f  0f8da7000000           -jge 0x529ffc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529ffc;
    }
    // 00529f55  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f58  668b502c               -mov dx, word ptr [eax + 0x2c]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00529f5c  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 00529f5f  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f62  668b482e               -mov cx, word ptr [eax + 0x2e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 00529f66  66894a02               -mov word ptr [edx + 2], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cx;
    // 00529f6a  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f6d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529f70  01e9                   +add ecx, ebp
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529f72  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529f73  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00529f76  ebcf                   -jmp 0x529f47
    goto L_0x00529f47;
L_0x00529f78:
    // 00529f78  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00529f7a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00529f7c  7e2a                   -jle 0x529fa8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529fa8;
    }
    // 00529f7e  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
L_0x00529f81:
    // 00529f81  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f84  668b482c               -mov cx, word ptr [eax + 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00529f88  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 00529f8b  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f8e  668b502e               -mov dx, word ptr [eax + 0x2e]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 00529f92  66895102               -mov word ptr [ecx + 2], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00529f96  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f99  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529f9c  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529f9f  43                     -inc ebx
    (cpu.ebx)++;
    // 00529fa0  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00529fa3  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529fa5  7cda                   -jl 0x529f81
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529f81;
    }
    // 00529fa7  90                     -nop 
    ;
L_0x00529fa8:
    // 00529fa8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00529faa  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 00529fb1  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00529fb5  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00529fb7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00529fb9:
    // 00529fb9  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529fbc  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529fbf  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529fc1  7d22                   -jge 0x529fe5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529fe5;
    }
    // 00529fc3  668b4a2c               -mov cx, word ptr [edx + 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 00529fc7  6689482c               -mov word ptr [eax + 0x2c], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.cx;
    // 00529fcb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529fce  668b4a2e               -mov cx, word ptr [edx + 0x2e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(46) /* 0x2e */);
    // 00529fd2  6689482a               -mov word ptr [eax + 0x2a], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(42) /* 0x2a */) = cpu.cx;
    // 00529fd6  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529fda  83c204                 +add edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529fdd  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529fde  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529fdf  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00529fe3  ebd4                   -jmp 0x529fb9
    goto L_0x00529fb9;
L_0x00529fe5:
    // 00529fe5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529fe9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00529fee  66894628               -mov word ptr [esi + 0x28], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ax;
    // 00529ff2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529ff4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00529ff7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ff8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ff9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ffa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ffb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529ffc:
    // 00529ffc  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00529fff  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a002  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a004  2b461c                 -sub eax, dword ptr [esi + 0x1c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 0052a007  83e81b                 -sub eax, 0x1b
    (cpu.eax) -= x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 0052a00a  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0052a00d  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a00f  0f8ee7000000           -jle 0x52a0fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a0fc;
    }
    // 0052a015  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x0052a019:
    // 0052a019  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a01e  0f8ce1000000           -jl 0x52a105
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052a105;
    }
L_0x0052a024:
    // 0052a024  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a028  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0052a02a  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a02d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a02f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052a031  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0052a034  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a036  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052a038  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052a03d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052a040  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052a042  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052a045  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a047  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a048  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a04b  e800320000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 0052a050  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a053  8b6e1c                 -mov ebp, dword ptr [esi + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a056  036c2408               -add ebp, dword ptr [esp + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052a05a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052a05c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052a05e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0052a060  896e1c                 -mov dword ptr [esi + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0052a063  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a065  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0052a067  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0052a06a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052a06e  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0052a075  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a077  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052a079  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052a07b  90                     -nop 
    ;
L_0x0052a07c:
    // 0052a07c  0f8c8e000000           -jl 0x52a110
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052a110;
    }
    // 0052a082  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a086  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a089  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a08c  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a08e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052a091  66895e28               -mov word ptr [esi + 0x28], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 0052a095  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a097  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a09a  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0052a09d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052a09f  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052a0a2  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a0a5  7d46                   -jge 0x52a0ed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a0ed;
    }
    // 0052a0a7  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0052a0ab  66898608010000         -mov word ptr [esi + 0x108], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(264) /* 0x108 */) = cpu.ax;
    // 0052a0b2  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052a0b6  6689860a010000         -mov word ptr [esi + 0x10a], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(266) /* 0x10a */) = cpu.ax;
    // 0052a0bd  668b460a               -mov ax, word ptr [esi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0052a0c1  6689860c010000         -mov word ptr [esi + 0x10c], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.ax;
    // 0052a0c8  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052a0cc  6689860e010000         -mov word ptr [esi + 0x10e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(270) /* 0x10e */) = cpu.ax;
    // 0052a0d3  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 0052a0d9  c700fc9c5200           -mov dword ptr [eax], 0x529cfc
    app->getMemory<x86::reg32>(cpu.eax) = 5414140 /*0x529cfc*/;
    // 0052a0df  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052a0e1  7e0a                   -jle 0x52a0ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a0ed;
    }
    // 0052a0e3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052a0e5  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a0e8  e80ffcffff             -call 0x529cfc
    cpu.esp -= 4;
    sub_529cfc(app, cpu);
    if (cpu.terminate) return;
L_0x0052a0ed:
    // 0052a0ed  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052a0f2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a0f4  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a0f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a0f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a0f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a0fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a0fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a0fc:
    // 0052a0fc  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052a100  e914ffffff             -jmp 0x52a019
    goto L_0x0052a019;
L_0x0052a105:
    // 0052a105  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0052a107  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0052a10b  e914ffffff             -jmp 0x52a024
    goto L_0x0052a024;
L_0x0052a110:
    // 0052a110  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a113  8d2c01                 -lea ebp, [ecx + eax]
    cpu.ebp = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0052a116  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 0052a119  668b7d00               -mov di, word ptr [ebp]
    cpu.di = app->getMemory<x86::reg16>(cpu.ebp);
    // 0052a11d  6689792c               -mov word ptr [ecx + 0x2c], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.di;
    // 0052a121  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a124  668b7c2802             -mov di, word ptr [eax + ebp + 2]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1);
    // 0052a129  43                     -inc ebx
    (cpu.ebx)++;
    // 0052a12a  6689792e               -mov word ptr [ecx + 0x2e], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(46) /* 0x2e */) = cpu.di;
    // 0052a12e  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a132  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a135  47                     -inc edi
    (cpu.edi)++;
    // 0052a136  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a139  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0052a13d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052a13f  e938ffffff             -jmp 0x52a07c
    goto L_0x0052a07c;
}

/* align: skip  */
void Application::sub_52a144(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a144  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052a14b  66c742280000           -mov word ptr [edx + 0x28], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0052a151  66c742060000           -mov word ptr [edx + 6], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0052a157  66c742040000           -mov word ptr [edx + 4], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052a15d  66c7420a0000           -mov word ptr [edx + 0xa], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 0052a163  66c742080000           -mov word ptr [edx + 8], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052a169  895a14                 -mov dword ptr [edx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0052a16c  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0052a16f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a173  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0052a176  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a17a  894a24                 -mov dword ptr [edx + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0052a17d  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052a181  898a10010000           -mov dword ptr [edx + 0x110], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(272) /* 0x110 */) = cpu.ecx;
    // 0052a187  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052a18b  c701249f5200           -mov dword ptr [ecx], 0x529f24
    app->getMemory<x86::reg32>(cpu.ecx) = 5414692 /*0x529f24*/;
    // 0052a191  b814010000             -mov eax, 0x114
    cpu.eax = 276 /*0x114*/;
    // 0052a196  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052a19c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_52a1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a1a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a1a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a1a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a1a3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a1a6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052a1a8  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0052a1ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052a1ad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052a1af  0f8490000000           -je 0x52a245
    if (cpu.flags.zf)
    {
        goto L_0x0052a245;
    }
    // 0052a1b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a1b6  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0052a1b9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a1bb  7e67                   -jle 0x52a224
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a224;
    }
    // 0052a1bd  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0052a1c0  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052a1c4  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0052a1c7  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a1cb  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052a1ce  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052a1d2  8d6814                 -lea ebp, [eax + 0x14]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
L_0x0052a1d5:
    // 0052a1d5  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a1d8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a1da  7570                   -jne 0x52a24c
    if (!cpu.flags.zf)
    {
        goto L_0x0052a24c;
    }
    // 0052a1dc  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a1df  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052a1e2  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 0052a1e5  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a1e7  0f8d7c000000           -jge 0x52a269
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a269;
    }
    // 0052a1ed  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 0052a1f1  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 0052a1f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a1f8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052a1fb  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052a1fd  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052a200  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 0052a206  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a208  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a209  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a20c  e83f300000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 0052a211  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a214  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052a217  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052a21a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a21d  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
L_0x0052a220:
    // 0052a220  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a222  7fb1                   -jg 0x52a1d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052a1d5;
    }
L_0x0052a224:
    // 0052a224  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 0052a22b  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a22e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0052a230:
    // 0052a230  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a232  0f8ce8000000           -jl 0x52a320
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052a320;
    }
    // 0052a238  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052a23d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052a23e:
    // 0052a23e  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a241  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a242  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a243  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a244  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a245:
    // 0052a245  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052a24a  ebf2                   -jmp 0x52a23e
    goto L_0x0052a23e;
L_0x0052a24c:
    // 0052a24c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a250  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052a254  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052a256  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052a258  e823faffff             -call 0x529c80
    cpu.esp -= 4;
    sub_529c80(app, cpu);
    if (cpu.terminate) return;
    // 0052a25d  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a260  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a262  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a264  895620                 -mov dword ptr [esi + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0052a267  ebb7                   -jmp 0x52a220
    goto L_0x0052a220;
L_0x0052a269:
    // 0052a269  837e1401               +cmp dword ptr [esi + 0x14], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a26d  7445                   -je 0x52a2b4
    if (cpu.flags.zf)
    {
        goto L_0x0052a2b4;
    }
    // 0052a26f  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 0052a273  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 0052a278  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a27a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052a27d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052a27f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052a282  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 0052a288  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a28a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a28b  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a28e  e8bd2f0000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 0052a293  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a296  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052a298  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052a29b  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0052a29e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a2a0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052a2a2  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a2a5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a2a7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a2aa  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a2ad  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a2af  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a2b1  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x0052a2b4:
    // 0052a2b4  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a2b8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052a2ba  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052a2c0  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052a2c3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a2c5  7434                   -je 0x52a2fb
    if (cpu.flags.zf)
    {
        goto L_0x0052a2fb;
    }
    // 0052a2c7  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 0052a2ca  66895606               -mov word ptr [esi + 6], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 0052a2ce  668b5302               -mov dx, word ptr [ebx + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0052a2d2  66895604               -mov word ptr [esi + 4], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0052a2d6  668b5304               -mov dx, word ptr [ebx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052a2da  6689560a               -mov word ptr [esi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 0052a2de  668b4306               -mov ax, word ptr [ebx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0052a2e2  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0052a2e6  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052a2e9  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052a2f0  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a2f3  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0052a2f6  e925ffffff             -jmp 0x52a220
    goto L_0x0052a220;
L_0x0052a2fb:
    // 0052a2fb  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052a2fd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a2ff  0f8e1bffffff           -jle 0x52a220
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a220;
    }
L_0x0052a305:
    // 0052a305  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a308  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 0052a30d  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a310  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052a313  4f                     -dec edi
    (cpu.edi)--;
    // 0052a314  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052a317  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a319  7fea                   -jg 0x52a305
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052a305;
    }
    // 0052a31b  e900ffffff             -jmp 0x52a220
    goto L_0x0052a220;
L_0x0052a320:
    // 0052a320  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a323  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a326  668b00                 -mov ax, word ptr [eax]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax);
    // 0052a329  6689449624             -mov word ptr [esi + edx*4 + 0x24], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.edx * 4) = cpu.ax;
    // 0052a32e  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a331  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a334  668b4002               -mov ax, word ptr [eax + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0052a338  6689449626             -mov word ptr [esi + edx*4 + 0x26], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(38) /* 0x26 */ + cpu.edx * 4) = cpu.ax;
    // 0052a33d  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a340  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a343  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a346  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052a347  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0052a34a  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052a34b  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0052a34e  e9ddfeffff             -jmp 0x52a230
    goto L_0x0052a230;
}

/* align: skip 0x90 */
void Application::sub_52a354(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a354  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 0052a35b  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052a362  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0052a369  66c742060000           -mov word ptr [edx + 6], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0052a36f  66c742040000           -mov word ptr [edx + 4], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052a375  66c7420a0000           -mov word ptr [edx + 0xa], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 0052a37b  66c742080000           -mov word ptr [edx + 8], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052a381  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0052a384  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052a388  c702a0a15200           -mov dword ptr [edx], 0x52a1a0
    app->getMemory<x86::reg32>(cpu.edx) = 5415328 /*0x52a1a0*/;
    // 0052a38e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052a392  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 0052a397  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052a39d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52a3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a3a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a3a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a3a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a3a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a3a4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052a3a7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052a3a9  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052a3ad  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052a3af  8b5028                 -mov edx, dword ptr [eax + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0052a3b2  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0052a3b5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052a3b7  754a                   -jne 0x52a403
    if (!cpu.flags.zf)
    {
        goto L_0x0052a403;
    }
L_0x0052a3b9:
    // 0052a3b9  8d7d10                 -lea edi, [ebp + 0x10]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052a3bc  8d452c                 -lea eax, [ebp + 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 0052a3bf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052a3c2  8d7518                 -lea esi, [ebp + 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
L_0x0052a3c5:
    // 0052a3c5  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a3ca  0f8e78010000           -jle 0x52a548
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a548;
    }
    // 0052a3d0  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052a3d3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a3d5  743d                   -je 0x52a414
    if (cpu.flags.zf)
    {
        goto L_0x0052a414;
    }
    // 0052a3d7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052a3da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052a3dc  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0052a3de  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a3e2  e899f8ffff             -call 0x529c80
    cpu.esp -= 4;
    sub_529c80(app, cpu);
    if (cpu.terminate) return;
    // 0052a3e7  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a3eb  8b4d20                 -mov ecx, dword ptr [ebp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052a3ee  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a3f1  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a3f3  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a3f5  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a3f7  894d20                 -mov dword ptr [ebp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0052a3fa  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052a3fe  895528                 -mov dword ptr [ebp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0052a401  ebc2                   -jmp 0x52a3c5
    goto L_0x0052a3c5;
L_0x0052a403:
    // 0052a403  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0052a406  e88d75feff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 0052a40b  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0052a412  eba5                   -jmp 0x52a3b9
    goto L_0x0052a3b9;
L_0x0052a414:
    // 0052a414  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0052a417  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0052a41a  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 0052a41d  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a41f  7d4a                   -jge 0x52a46b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a46b;
    }
    // 0052a421  6b551c1e               -imul edx, dword ptr [ebp + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 0052a425  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052a42a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a42c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052a42f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052a431  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0052a434  c745001c000000         -mov dword ptr [ebp], 0x1c
    app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 0052a43b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a43d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a43e  89550c                 -mov dword ptr [ebp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a441  e80a2e0000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 0052a446  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a449  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0052a44c  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a44f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a453  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052a456  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052a459  895d1c                 -mov dword ptr [ebp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0052a45c  83e81c                 +sub eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a45f  895528                 -mov dword ptr [ebp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0052a462  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052a466  e95affffff             -jmp 0x52a3c5
    goto L_0x0052a3c5;
L_0x0052a46b:
    // 0052a46b  837d1400               +cmp dword ptr [ebp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a46f  745c                   -je 0x52a4cd
    if (cpu.flags.zf)
    {
        goto L_0x0052a4cd;
    }
    // 0052a471  6b551c1e               -imul edx, dword ptr [ebp + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 0052a475  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052a47a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a47c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052a47f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052a481  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0052a484  c745001c000000         -mov dword ptr [ebp], 0x1c
    app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 0052a48b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a48d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a48e  89550c                 -mov dword ptr [ebp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a491  e8ba2d0000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 0052a496  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0052a499  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a49c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052a49f  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0052a4a2  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0052a4a5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a4a7  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052a4aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052a4ac  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 0052a4b1  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a4b5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a4b7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0052a4ba  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a4bc  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a4be  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a4c1  895d10                 -mov dword ptr [ebp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0052a4c4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a4c6  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052a4ca  895528                 -mov dword ptr [ebp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edx;
L_0x0052a4cd:
    // 0052a4cd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0052a4cf  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0052a4d2  e82574feff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 0052a4d7  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0052a4da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052a4dc  7436                   -je 0x52a514
    if (cpu.flags.zf)
    {
        goto L_0x0052a514;
    }
    // 0052a4de  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052a4e0  668b00                 -mov ax, word ptr [eax]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax);
    // 0052a4e3  66894506               -mov word ptr [ebp + 6], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 0052a4e7  668b4202               -mov ax, word ptr [edx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0052a4eb  66894504               -mov word ptr [ebp + 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0052a4ef  668b4204               -mov ax, word ptr [edx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0052a4f3  6689450a               -mov word ptr [ebp + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 0052a4f7  668b4206               -mov ax, word ptr [edx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0052a4fb  66894508               -mov word ptr [ebp + 8], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0052a4ff  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0052a502  c7451c00000000         -mov dword ptr [ebp + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052a509  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a50c  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0052a50f  e9b1feffff             -jmp 0x52a3c5
    goto L_0x0052a3c5;
L_0x0052a514:
    // 0052a514  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a518  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a51a  0f8ea5feffff           -jle 0x52a3c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a3c5;
    }
    // 0052a520  837d2800               +cmp dword ptr [ebp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a524  740d                   -je 0x52a533
    if (cpu.flags.zf)
    {
        goto L_0x0052a533;
    }
    // 0052a526  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0052a529  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052a52c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a52e  e80d61fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0052a533:
    // 0052a533  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a537  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052a53a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a53d  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a53f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a541  897d10                 -mov dword ptr [ebp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0052a544  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052a548:
    // 0052a548  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a54c  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052a54f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a552  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a554  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a558  895510                 -mov dword ptr [ebp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052a55b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052a55d  7c0b                   -jl 0x52a56a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052a56a;
    }
    // 0052a55f  8b4528                 -mov eax, dword ptr [ebp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a562  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052a565  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a566  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a567  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a568  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a569  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a56a:
    // 0052a56a  6bc1ff                 -imul eax, ecx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 0052a56d  8b7d20                 -mov edi, dword ptr [ebp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052a570  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052a574  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0052a57b  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0052a57e  8d452c                 -lea eax, [ebp + 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 0052a581  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052a583  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a585  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a586  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052a588  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052a58b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 0052a58d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052a58f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052a592  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0052a594  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a595  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a599  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052a59c  8b7d28                 -mov edi, dword ptr [ebp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a59f  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a5a1  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a5a3  897520                 -mov dword ptr [ebp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0052a5a6  897d28                 -mov dword ptr [ebp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0052a5a9  8b4528                 -mov eax, dword ptr [ebp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a5ac  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052a5af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a5b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a5b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a5b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a5b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52a5b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a5b4  e8a72b0000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 0052a5b9  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0052a5c0  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052a5c7  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0052a5ce  66c742060000           -mov word ptr [edx + 6], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0052a5d4  66c742040000           -mov word ptr [edx + 4], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052a5da  66c7420a0000           -mov word ptr [edx + 0xa], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 0052a5e0  66c742080000           -mov word ptr [edx + 8], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052a5e6  c7422800000000         -mov dword ptr [edx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0052a5ed  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0052a5f0  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052a5f4  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0052a5f7  c700a0a35200           -mov dword ptr [eax], 0x52a3a0
    app->getMemory<x86::reg32>(cpu.eax) = 5415840 /*0x52a3a0*/;
    // 0052a5fd  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052a601  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0052a607  b898000000             -mov eax, 0x98
    cpu.eax = 152 /*0x98*/;
    // 0052a60c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_52a610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a610  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052a616  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52a618(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a618  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a619  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a61a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a61b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052a61d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052a61f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a621  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052a623  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a625  7e34                   -jle 0x52a65b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a65b;
    }
    // 0052a627  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052a629  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0052a62b:
    // 0052a62b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0052a62d  25ffff0100             -and eax, 0x1ffff
    cpu.eax &= x86::reg32(x86::sreg32(131071 /*0x1ffff*/));
    // 0052a632  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a637  7613                   -jbe 0x52a64c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052a64c;
    }
    // 0052a639  3d00800100             +cmp eax, 0x18000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(98304 /*0x18000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a63e  730c                   -jae 0x52a64c
    if (!cpu.flags.cf)
    {
        goto L_0x0052a64c;
    }
    // 0052a640  3d00000100             +cmp eax, 0x10000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a645  7318                   -jae 0x52a65f
    if (!cpu.flags.cf)
    {
        goto L_0x0052a65f;
    }
    // 0052a647  b8ff7f0000             -mov eax, 0x7fff
    cpu.eax = 32767 /*0x7fff*/;
L_0x0052a64c:
    // 0052a64c  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052a64f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a652  41                     -inc ecx
    (cpu.ecx)++;
    // 0052a653  668943fe               -mov word ptr [ebx - 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 0052a657  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a659  7cd0                   -jl 0x52a62b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052a62b;
    }
L_0x0052a65b:
    // 0052a65b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a65c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a65d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a65e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a65f:
    // 0052a65f  b800800000             -mov eax, 0x8000
    cpu.eax = 32768 /*0x8000*/;
    // 0052a664  ebe6                   -jmp 0x52a64c
    goto L_0x0052a64c;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52a668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a668  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a669  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a66a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a66b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a66c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a66f  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052a671  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052a673  8bb04c0d0000           -mov esi, dword ptr [eax + 0xd4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052a679  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052a67f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052a681  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a683  0f83e1000000           -jae 0x52a76a
    if (!cpu.flags.cf)
    {
        goto L_0x0052a76a;
    }
    // 0052a689  8d1c2e                 -lea ebx, [esi + ebp]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0052a68c  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052a692  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052a694  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a696  89984c0d0000           -mov dword ptr [eax + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 0052a69c  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0052a69f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052a6a1  0f8ed0000000           -jle 0x52a777
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a777;
    }
    // 0052a6a7  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052a6a9:
    // 0052a6a9  8bb7480d0000           -mov esi, dword ptr [edi + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052a6af  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a6b1  7d02                   -jge 0x52a6b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a6b5;
    }
    // 0052a6b3  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x0052a6b5:
    // 0052a6b5  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 0052a6ba  8b97480d0000           -mov edx, dword ptr [edi + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052a6c0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052a6c2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a6c4  8d9784060000           -lea edx, [edi + 0x684]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1668) /* 0x684 */);
    // 0052a6ca  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a6cd  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052a6d1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052a6d3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052a6d5  e83effffff             -call 0x52a618
    cpu.esp -= 4;
    sub_52a618(app, cpu);
    if (cpu.terminate) return;
    // 0052a6da  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0052a6dd  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a6df  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052a6e5  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a6e7  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a6e9  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 0052a6ef  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052a6f1  7e5f                   -jle 0x52a752
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a752;
    }
    // 0052a6f3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a6f7  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0052a6fb:
    // 0052a6fb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052a700  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052a702  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 0052a707  e874380000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052a70c  c787480d0000b0010000   -mov dword ptr [edi + 0xd48], 0x1b0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = 432 /*0x1b0*/;
    // 0052a716  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a718  7d02                   -jge 0x52a71c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a71c;
    }
    // 0052a71a  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x0052a71c:
    // 0052a71c  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 0052a721  2b87480d0000           -sub eax, dword ptr [edi + 0xd48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */)));
    // 0052a727  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a72b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a72e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052a730  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052a732  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052a734  e8dffeffff             -call 0x52a618
    cpu.esp -= 4;
    sub_52a618(app, cpu);
    if (cpu.terminate) return;
    // 0052a739  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0052a73c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a73e  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052a744  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a746  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a748  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 0052a74e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052a750  7fa9                   -jg 0x52a6fb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052a6fb;
    }
L_0x0052a752:
    // 0052a752  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052a754:
    // 0052a754  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052a757  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a759  7d26                   -jge 0x52a781
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a781;
    }
    // 0052a75b  83c102                 +add ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a75e  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0052a761  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 0052a765  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0052a768  ebea                   -jmp 0x52a754
    goto L_0x0052a754;
L_0x0052a76a:
    // 0052a76a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052a76f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a772  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a773  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a774  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a775  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a776  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a777:
    // 0052a777  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052a779  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052a77c  e928ffffff             -jmp 0x52a6a9
    goto L_0x0052a6a9;
L_0x0052a781:
    // 0052a781  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052a786  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a789  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a78a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a78b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a78c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a78d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52a790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a790  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a791  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052a793  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052a795  e8fa360000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052a79a  c786480d000000000000   -mov dword ptr [esi + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052a7a4  c7864c0d000000000000   -mov dword ptr [esi + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052a7ae  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052a7b2  898e440d0000           -mov dword ptr [esi + 0xd44], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3396) /* 0xd44 */) = cpu.ecx;
    // 0052a7b8  c70068a65200           -mov dword ptr [eax], 0x52a668
    app->getMemory<x86::reg32>(cpu.eax) = 5416552 /*0x52a668*/;
    // 0052a7be  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052a7c2  c70010a65200           -mov dword ptr [eax], 0x52a610
    app->getMemory<x86::reg32>(cpu.eax) = 5416464 /*0x52a610*/;
    // 0052a7c8  b8500d0000             -mov eax, 0xd50
    cpu.eax = 3408 /*0xd50*/;
    // 0052a7cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a7ce  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52a7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a7e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a7e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a7e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a7e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a7e4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a7e7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052a7e9  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052a7ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052a7f1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052a7f3  0f84b8000000           -je 0x52a8b1
    if (cpu.flags.zf)
    {
        goto L_0x0052a8b1;
    }
    // 0052a7f9  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052a7fb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a7fd  0f8ea1000000           -jle 0x52a8a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a8a4;
    }
    // 0052a803  8d9884060000           -lea ebx, [eax + 0x684]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1668) /* 0x684 */);
    // 0052a809  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052a80d  8d98480d0000           -lea ebx, [eax + 0xd48]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(3400) /* 0xd48 */);
    // 0052a813  05440d0000             -add eax, 0xd44
    (cpu.eax) += x86::reg32(x86::sreg32(3396 /*0xd44*/));
    // 0052a818  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052a81c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0052a81f:
    // 0052a81f  8b814c0d0000           -mov eax, dword ptr [ecx + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 0052a825  3b81480d0000           +cmp eax, dword ptr [ecx + 0xd48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a82b  0f8d8d000000           -jge 0x52a8be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a8be;
    }
L_0x0052a831:
    // 0052a831  83b9500d000000         +cmp dword ptr [ecx + 0xd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a838  0f8e15010000           -jle 0x52a953
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a953;
    }
L_0x0052a83e:
    // 0052a83e  8bb1480d0000           -mov esi, dword ptr [ecx + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */);
    // 0052a844  2bb14c0d0000           -sub esi, dword ptr [ecx + 0xd4c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */)));
    // 0052a84a  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a84c  7d02                   -jge 0x52a850
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a850;
    }
    // 0052a84e  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0052a850:
    // 0052a850  8b91500d0000           -mov edx, dword ptr [ecx + 0xd50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 0052a856  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a858  7e02                   -jle 0x52a85c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a85c;
    }
    // 0052a85a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x0052a85c:
    // 0052a85c  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 0052a861  2b81500d0000           -sub eax, dword ptr [ecx + 0xd50]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */)));
    // 0052a867  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a86b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a86e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052a870  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052a872  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052a874  e89ffdffff             -call 0x52a618
    cpu.esp -= 4;
    sub_52a618(app, cpu);
    if (cpu.terminate) return;
    // 0052a879  8b994c0d0000           -mov ebx, dword ptr [ecx + 0xd4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 0052a87f  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052a881  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0052a884  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a886  8b81500d0000           -mov eax, dword ptr [ecx + 0xd50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 0052a88c  89994c0d0000           -mov dword ptr [ecx + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 0052a892  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a894  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a896  8981500d0000           -mov dword ptr [ecx + 0xd50], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = cpu.eax;
    // 0052a89c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a89e  0f8f7bffffff           -jg 0x52a81f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052a81f;
    }
L_0x0052a8a4:
    // 0052a8a4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052a8a9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a8ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a8b1:
    // 0052a8b1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052a8b6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a8b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a8be:
    // 0052a8be  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a8c2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052a8c5  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052a8cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052a8cd  752b                   -jne 0x52a8fa
    if (!cpu.flags.zf)
    {
        goto L_0x0052a8fa;
    }
    // 0052a8cf  8b99440d0000           -mov ebx, dword ptr [ecx + 0xd44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 0052a8d5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a8d7  7421                   -je 0x52a8fa
    if (cpu.flags.zf)
    {
        goto L_0x0052a8fa;
    }
    // 0052a8d9  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0052a8db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052a8dd  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0052a8df  7446                   -je 0x52a927
    if (cpu.flags.zf)
    {
        goto L_0x0052a927;
    }
    // 0052a8e1  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0052a8e4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052a8e6  e8a9350000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052a8eb  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052a8f5  e937ffffff             -jmp 0x52a831
    goto L_0x0052a831;
L_0x0052a8fa:
    // 0052a8fa  8d1c3f                 -lea ebx, [edi + edi]
    cpu.ebx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 0052a8fd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052a8ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a901  e83a5dfbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052a906  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052a910  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052a915  c781480d000000000000   -mov dword ptr [ecx + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052a91f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a922  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a923  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a924  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a925  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a926  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a927:
    // 0052a927  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0052a92a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052a92f  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052a932  8b81440d0000           -mov eax, dword ptr [ecx + 0xd44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 0052a938  c7410808000000         -mov dword ptr [ecx + 8], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 0052a93f  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a942  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0052a944  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052a94e  e9defeffff             -jmp 0x52a831
    goto L_0x0052a831;
L_0x0052a953:
    // 0052a953  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052a958  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052a95a  e821360000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052a95f  c781500d0000b0010000   -mov dword ptr [ecx + 0xd50], 0x1b0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = 432 /*0x1b0*/;
    // 0052a969  e9d0feffff             -jmp 0x52a83e
    goto L_0x0052a83e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52a970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a970  c782440d000001000000   -mov dword ptr [edx + 0xd44], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3396) /* 0xd44 */) = 1 /*0x1*/;
    // 0052a97a  c782480d000000000000   -mov dword ptr [edx + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052a984  c7824c0d000000000000   -mov dword ptr [edx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052a98e  c782500d000000000000   -mov dword ptr [edx + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052a998  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052a99c  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052a9a2  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052a9a6  b8540d0000             -mov eax, 0xd54
    cpu.eax = 3412 /*0xd54*/;
    // 0052a9ab  c702e0a75200           -mov dword ptr [edx], 0x52a7e0
    app->getMemory<x86::reg32>(cpu.edx) = 5416928 /*0x52a7e0*/;
    // 0052a9b1  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52a9c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a9c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a9c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a9c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a9c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a9c4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052a9c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052a9c9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052a9cb  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052a9cd  8b90500d0000           -mov edx, dword ptr [eax + 0xd50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3408) /* 0xd50 */);
    // 0052a9d3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052a9d5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052a9d7  0f85c0000000           -jne 0x52aa9d
    if (!cpu.flags.zf)
    {
        goto L_0x0052aa9d;
    }
L_0x0052a9dd:
    // 0052a9dd  8d8184060000           -lea eax, [ecx + 0x684]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1668) /* 0x684 */);
    // 0052a9e3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052a9e6  8d81480d0000           -lea eax, [ecx + 0xd48]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(3400) /* 0xd48 */);
    // 0052a9ec  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052a9f0:
    // 0052a9f0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a9f2  0f8e00010000           -jle 0x52aaf8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052aaf8;
    }
    // 0052a9f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a9fa  8b99480d0000           -mov ebx, dword ptr [ecx + 0xd48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */);
    // 0052aa00  668b81540d0000         -mov ax, word ptr [ecx + 0xd54]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */);
    // 0052aa07  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052aa09  0f8da8000000           -jge 0x52aab7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052aab7;
    }
L_0x0052aa0f:
    // 0052aa0f  6683b9560d000000       +cmp word ptr [ecx + 0xd56], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3414) /* 0xd56 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052aa17  0f8e2f010000           -jle 0x52ab4c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ab4c;
    }
L_0x0052aa1d:
    // 0052aa1d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0052aa1f  8b81480d0000           -mov eax, dword ptr [ecx + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */);
    // 0052aa25  668bb1540d0000         -mov si, word ptr [ecx + 0xd54]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */);
    // 0052aa2c  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052aa2e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052aa30  39c7                   +cmp edi, eax
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052aa32  7d02                   -jge 0x52aa36
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052aa36;
    }
    // 0052aa34  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0052aa36:
    // 0052aa36  8b81540d0000           -mov eax, dword ptr [ecx + 0xd54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3412) /* 0xd54 */);
    // 0052aa3c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052aa3f  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052aa41  0f8c1f010000           -jl 0x52ab66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052ab66;
    }
L_0x0052aa47:
    // 0052aa47  8b81540d0000           -mov eax, dword ptr [ecx + 0xd54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3412) /* 0xd54 */);
    // 0052aa4d  bab0010000             -mov edx, 0x1b0
    cpu.edx = 432 /*0x1b0*/;
    // 0052aa52  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052aa55  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052aa57  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0052aa5e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052aa61  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052aa63  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052aa65  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052aa67  e8acfbffff             -call 0x52a618
    cpu.esp -= 4;
    sub_52a618(app, cpu);
    if (cpu.terminate) return;
    // 0052aa6c  6601b1540d0000         -add word ptr [ecx + 0xd54], si
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */)) += x86::reg16(x86::sreg16(cpu.si));
    // 0052aa73  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0052aa76  8b99500d0000           -mov ebx, dword ptr [ecx + 0xd50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 0052aa7c  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052aa7e  668b81560d0000         -mov ax, word ptr [ecx + 0xd56]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3414) /* 0xd56 */);
    // 0052aa85  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052aa87  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052aa89  8999500d0000           -mov dword ptr [ecx + 0xd50], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = cpu.ebx;
    // 0052aa8f  29f7                   +sub edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052aa91  668981560d0000         -mov word ptr [ecx + 0xd56], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3414) /* 0xd56 */) = cpu.ax;
    // 0052aa98  e953ffffff             -jmp 0x52a9f0
    goto L_0x0052a9f0;
L_0x0052aa9d:
    // 0052aa9d  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052aaa3  e8f06efeff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 0052aaa8  c786500d000000000000   -mov dword ptr [esi + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052aab2  e926ffffff             -jmp 0x52a9dd
    goto L_0x0052a9dd;
L_0x0052aab7:
    // 0052aab7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052aabb  8b814c0d0000           -mov eax, dword ptr [ecx + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 0052aac1  e8366efeff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 0052aac6  8981440d0000           -mov dword ptr [ecx + 0xd44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */) = cpu.eax;
    // 0052aacc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052aace  7536                   -jne 0x52ab06
    if (!cpu.flags.zf)
    {
        goto L_0x0052ab06;
    }
    // 0052aad0  83b9500d000000         +cmp dword ptr [ecx + 0xd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052aad7  740c                   -je 0x52aae5
    if (cpu.flags.zf)
    {
        goto L_0x0052aae5;
    }
    // 0052aad9  8d1c3f                 -lea ebx, [edi + edi]
    cpu.ebx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 0052aadc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052aade  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052aae0  e85b5bfbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0052aae5:
    // 0052aae5  66c781540d00000000     -mov word ptr [ecx + 0xd54], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052aaee  c781480d000000000000   -mov dword ptr [ecx + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
L_0x0052aaf8:
    // 0052aaf8  8b81500d0000           -mov eax, dword ptr [ecx + 0xd50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 0052aafe  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052ab01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ab02  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ab03  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ab04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ab05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ab06:
    // 0052ab06  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052ab09  7416                   -je 0x52ab21
    if (cpu.flags.zf)
    {
        goto L_0x0052ab21;
    }
    // 0052ab0b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052ab0c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052ab0e  e881330000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052ab13  66c781540d00000000     -mov word ptr [ecx + 0xd54], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052ab1c  e9eefeffff             -jmp 0x52aa0f
    goto L_0x0052aa0f;
L_0x0052ab21:
    // 0052ab21  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052ab24  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ab29  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052ab2c  8b81440d0000           -mov eax, dword ptr [ecx + 0xd44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 0052ab32  c7410808000000         -mov dword ptr [ecx + 8], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 0052ab39  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052ab3c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0052ab3e  66c781540d00000000     -mov word ptr [ecx + 0xd54], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052ab47  e9c3feffff             -jmp 0x52aa0f
    goto L_0x0052aa0f;
L_0x0052ab4c:
    // 0052ab4c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052ab51  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ab53  e828340000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052ab58  66c781560d0000b001     -mov word ptr [ecx + 0xd56], 0x1b0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3414) /* 0xd56 */) = 432 /*0x1b0*/;
    // 0052ab61  e9b7feffff             -jmp 0x52aa1d
    goto L_0x0052aa1d;
L_0x0052ab66:
    // 0052ab66  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052ab68  e9dafeffff             -jmp 0x52aa47
    goto L_0x0052aa47;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52ab70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ab70  e8eb250000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 0052ab75  c782440d000000000000   -mov dword ptr [edx + 0xd44], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3396) /* 0xd44 */) = 0 /*0x0*/;
    // 0052ab7f  c782480d000000000000   -mov dword ptr [edx + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052ab89  66c782540d00000000     -mov word ptr [edx + 0xd54], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052ab92  66c782560d00000000     -mov word ptr [edx + 0xd56], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(3414) /* 0xd56 */) = 0 /*0x0*/;
    // 0052ab9b  89824c0d0000           -mov dword ptr [edx + 0xd4c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3404) /* 0xd4c */) = cpu.eax;
    // 0052aba1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052aba5  c782500d000000000000   -mov dword ptr [edx + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052abaf  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0052abb5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052abb9  c700c0a95200           -mov dword ptr [eax], 0x52a9c0
    app->getMemory<x86::reg32>(cpu.eax) = 5417408 /*0x52a9c0*/;
    // 0052abbf  b8580d0000             -mov eax, 0xd58
    cpu.eax = 3416 /*0xd58*/;
    // 0052abc4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52abd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052abd0  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052abd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52abd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052abd8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052abd9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052abdb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052abdd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052abdf  7e13                   -jle 0x52abf4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052abf4;
    }
L_0x0052abe1:
    // 0052abe1  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0052abe3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052abe6  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052abe9  40                     -inc eax
    (cpu.eax)++;
    // 0052abea  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052abed  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052abef  7cf0                   -jl 0x52abe1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052abe1;
    }
    // 0052abf1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0052abf4:
    // 0052abf4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052abf5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52abf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052abf8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052abf9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052abfa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052abfb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052abfc  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052abff  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052ac01  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052ac03  8bb04c0d0000           -mov esi, dword ptr [eax + 0xd4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052ac09  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052ac0f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052ac11  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ac13  0f83e7000000           -jae 0x52ad00
    if (!cpu.flags.cf)
    {
        goto L_0x0052ad00;
    }
    // 0052ac19  8d1c2e                 -lea ebx, [esi + ebp]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0052ac1c  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052ac22  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052ac24  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ac26  89984c0d0000           -mov dword ptr [eax + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 0052ac2c  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0052ac30  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052ac32  0f8ed5000000           -jle 0x52ad0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ad0d;
    }
    // 0052ac38  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052ac3a:
    // 0052ac3a  8bb7480d0000           -mov esi, dword ptr [edi + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052ac40  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ac42  7d02                   -jge 0x52ac46
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052ac46;
    }
    // 0052ac44  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x0052ac46:
    // 0052ac46  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 0052ac4b  8b97480d0000           -mov edx, dword ptr [edi + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052ac51  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052ac53  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ac55  8d9784060000           -lea edx, [edi + 0x684]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1668) /* 0x684 */);
    // 0052ac5b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052ac5e  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052ac61  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052ac63  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052ac65  e86effffff             -call 0x52abd8
    cpu.esp -= 4;
    sub_52abd8(app, cpu);
    if (cpu.terminate) return;
    // 0052ac6a  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0052ac71  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052ac73  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052ac79  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052ac7b  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052ac7d  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 0052ac83  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052ac85  7e5f                   -jle 0x52ace6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ace6;
    }
    // 0052ac87  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052ac8a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052ac8e:
    // 0052ac8e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052ac90  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ac92  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 0052ac97  e8e4320000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052ac9c  c787480d0000b0010000   -mov dword ptr [edi + 0xd48], 0x1b0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = 432 /*0x1b0*/;
    // 0052aca6  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052aca8  7d02                   -jge 0x52acac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052acac;
    }
    // 0052acaa  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x0052acac:
    // 0052acac  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 0052acb1  2b87480d0000           -sub eax, dword ptr [edi + 0xd48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */)));
    // 0052acb7  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052acbb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052acbe  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052acc0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052acc2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052acc4  e80fffffff             -call 0x52abd8
    cpu.esp -= 4;
    sub_52abd8(app, cpu);
    if (cpu.terminate) return;
    // 0052acc9  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0052acd0  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052acd2  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052acd8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052acda  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052acdc  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 0052ace2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052ace4  7fa8                   -jg 0x52ac8e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052ac8e;
    }
L_0x0052ace6:
    // 0052ace6  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052acea  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052acec  7e2a                   -jle 0x52ad18
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ad18;
    }
    // 0052acee  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0052acf1  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0052acf7  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052acfa  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052acfe  ebe6                   -jmp 0x52ace6
    goto L_0x0052ace6;
L_0x0052ad00:
    // 0052ad00  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052ad05  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052ad08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ad0d:
    // 0052ad0d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052ad0f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052ad13  e922ffffff             -jmp 0x52ac3a
    goto L_0x0052ac3a;
L_0x0052ad18:
    // 0052ad18  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ad1d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052ad20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52ad28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ad28  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ad29  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052ad2b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ad2d  e862310000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052ad32  c786480d000000000000   -mov dword ptr [esi + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052ad3c  c7864c0d000000000000   -mov dword ptr [esi + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052ad46  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052ad4a  898e440d0000           -mov dword ptr [esi + 0xd44], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3396) /* 0xd44 */) = cpu.ecx;
    // 0052ad50  c700f8ab5200           -mov dword ptr [eax], 0x52abf8
    app->getMemory<x86::reg32>(cpu.eax) = 5417976 /*0x52abf8*/;
    // 0052ad56  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052ad5a  c700d0ab5200           -mov dword ptr [eax], 0x52abd0
    app->getMemory<x86::reg32>(cpu.eax) = 5417936 /*0x52abd0*/;
    // 0052ad60  b8500d0000             -mov eax, 0xd50
    cpu.eax = 3408 /*0xd50*/;
    // 0052ad65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad66  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ad70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ad70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ad71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ad72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ad73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ad74  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052ad77  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052ad79  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052ad7d  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052ad83  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052ad85  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052ad87  0f84e2000000           -je 0x52ae6f
    if (cpu.flags.zf)
    {
        goto L_0x0052ae6f;
    }
    // 0052ad8d  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052ad91  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0052ad94  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052ad96  0f8ec6000000           -jle 0x52ae62
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ae62;
    }
    // 0052ad9c  0584060000             -add eax, 0x684
    (cpu.eax) += x86::reg32(x86::sreg32(1668 /*0x684*/));
    // 0052ada1  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052ada5  8d86480d0000           -lea eax, [esi + 0xd48]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3400) /* 0xd48 */);
    // 0052adab  81c6440d0000           -add esi, 0xd44
    (cpu.esi) += x86::reg32(x86::sreg32(3396 /*0xd44*/));
    // 0052adb1  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052adb5  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x0052adb9:
    // 0052adb9  8b854c0d0000           -mov eax, dword ptr [ebp + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 0052adbf  3b85480d0000           +cmp eax, dword ptr [ebp + 0xd48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052adc5  0f8db1000000           -jge 0x52ae7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052ae7c;
    }
L_0x0052adcb:
    // 0052adcb  83bd500d000000         +cmp dword ptr [ebp + 0xd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052add2  0f8e40010000           -jle 0x52af18
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052af18;
    }
L_0x0052add8:
    // 0052add8  8b95480d0000           -mov edx, dword ptr [ebp + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */);
    // 0052adde  8bbd4c0d0000           -mov edi, dword ptr [ebp + 0xd4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 0052ade4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052ade8  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052adea  39c2                   +cmp edx, eax
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052adec  7e02                   -jle 0x52adf0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052adf0;
    }
    // 0052adee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0052adf0:
    // 0052adf0  8b8d500d0000           -mov ecx, dword ptr [ebp + 0xd50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 0052adf6  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052adf8  7e02                   -jle 0x52adfc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052adfc;
    }
    // 0052adfa  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0052adfc:
    // 0052adfc  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 0052ae01  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052ae05  8bbd500d0000           -mov edi, dword ptr [ebp + 0xd50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 0052ae0b  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 0052ae12  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052ae14  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052ae16  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0052ae19  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0052ae1c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052ae1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ae1f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ae21  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052ae24  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 0052ae26  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052ae28  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052ae2b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0052ae2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae2e  8b8d4c0d0000           -mov ecx, dword ptr [ebp + 0xd4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 0052ae34  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 0052ae37  8b85500d0000           -mov eax, dword ptr [ebp + 0xd50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 0052ae3d  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052ae41  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0052ae44  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052ae46  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ae48  898d4c0d0000           -mov dword ptr [ebp + 0xd4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = cpu.ecx;
    // 0052ae4e  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ae50  8985500d0000           -mov dword ptr [ebp + 0xd50], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = cpu.eax;
    // 0052ae56  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0052ae5a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052ae5c  0f8f57ffffff           -jg 0x52adb9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052adb9;
    }
L_0x0052ae62:
    // 0052ae62  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ae67  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052ae6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ae6f:
    // 0052ae6f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052ae74  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052ae77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ae7c:
    // 0052ae7c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052ae80  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052ae84  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ae8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ae8c  752b                   -jne 0x52aeb9
    if (!cpu.flags.zf)
    {
        goto L_0x0052aeb9;
    }
    // 0052ae8e  8b9d440d0000           -mov ebx, dword ptr [ebp + 0xd44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 0052ae94  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052ae96  7421                   -je 0x52aeb9
    if (cpu.flags.zf)
    {
        goto L_0x0052aeb9;
    }
    // 0052ae98  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0052ae9a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ae9c  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0052ae9e  744b                   -je 0x52aeeb
    if (cpu.flags.zf)
    {
        goto L_0x0052aeeb;
    }
    // 0052aea0  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0052aea3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052aea5  e8ea2f0000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052aeaa  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052aeb4  e912ffffff             -jmp 0x52adcb
    goto L_0x0052adcb;
L_0x0052aeb9:
    // 0052aeb9  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052aebd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052aec0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052aec2  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0052aec5  e87657fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052aeca  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052aed4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052aed9  c785480d000000000000   -mov dword ptr [ebp + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052aee3  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052aee6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052aee7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052aee8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052aee9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052aeea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052aeeb:
    // 0052aeeb  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0052aeee  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052aef3  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052aef6  8b85440d0000           -mov eax, dword ptr [ebp + 0xd44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 0052aefc  c7450808000000         -mov dword ptr [ebp + 8], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 0052af03  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052af06  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0052af09  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052af13  e9b3feffff             -jmp 0x52adcb
    goto L_0x0052adcb;
L_0x0052af18:
    // 0052af18  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052af1a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052af1c  e85f300000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052af21  c785500d0000b0010000   -mov dword ptr [ebp + 0xd50], 0x1b0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = 432 /*0x1b0*/;
    // 0052af2b  e9a8feffff             -jmp 0x52add8
    goto L_0x0052add8;
}

/* align: skip  */
void Application::sub_52af30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052af30  c782440d000001000000   -mov dword ptr [edx + 0xd44], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3396) /* 0xd44 */) = 1 /*0x1*/;
    // 0052af3a  c782480d000000000000   -mov dword ptr [edx + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052af44  c7824c0d000000000000   -mov dword ptr [edx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052af4e  c782500d000000000000   -mov dword ptr [edx + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052af58  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052af5c  c70270ad5200           -mov dword ptr [edx], 0x52ad70
    app->getMemory<x86::reg32>(cpu.edx) = 5418352 /*0x52ad70*/;
    // 0052af62  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052af66  b8540d0000             -mov eax, 0xd54
    cpu.eax = 3412 /*0xd54*/;
    // 0052af6b  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052af71  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52af80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052af80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052af81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052af82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052af83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052af84  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052af87  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052af89  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052af8d  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052af91  8b90500d0000           -mov edx, dword ptr [eax + 0xd50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3408) /* 0xd50 */);
    // 0052af97  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052af99  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052af9b  0f85eb000000           -jne 0x52b08c
    if (!cpu.flags.zf)
    {
        goto L_0x0052b08c;
    }
L_0x0052afa1:
    // 0052afa1  8d8584060000           -lea eax, [ebp + 0x684]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1668) /* 0x684 */);
    // 0052afa7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052afaa  8d85480d0000           -lea eax, [ebp + 0xd48]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(3400) /* 0xd48 */);
    // 0052afb0  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052afb4:
    // 0052afb4  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052afb8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052afba  0f8e2d010000           -jle 0x52b0ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b0ed;
    }
    // 0052afc0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052afc2  8b9d480d0000           -mov ebx, dword ptr [ebp + 0xd48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */);
    // 0052afc8  668b85540d0000         -mov ax, word ptr [ebp + 0xd54]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */);
    // 0052afcf  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052afd1  0f8dcf000000           -jge 0x52b0a6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052b0a6;
    }
L_0x0052afd7:
    // 0052afd7  6683bd560d000000       +cmp word ptr [ebp + 0xd56], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052afdf  0f865d010000           -jbe 0x52b142
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052b142;
    }
L_0x0052afe5:
    // 0052afe5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052afe7  8b85480d0000           -mov eax, dword ptr [ebp + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */);
    // 0052afed  668b95540d0000         -mov dx, word ptr [ebp + 0xd54]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */);
    // 0052aff4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052aff6  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052affa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052affc  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052affe  7e02                   -jle 0x52b002
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b002;
    }
    // 0052b000  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x0052b002:
    // 0052b002  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052b004  668b85560d0000         -mov ax, word ptr [ebp + 0xd56]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */);
    // 0052b00b  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b00d  0f8c46010000           -jl 0x52b159
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b159;
    }
L_0x0052b013:
    // 0052b013  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 0052b018  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052b01a  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052b01e  668b85560d0000         -mov ax, word ptr [ebp + 0xd56]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */);
    // 0052b025  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 0052b02c  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052b02e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052b031  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0052b034  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052b036  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052b038  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b039  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b03b  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052b03e  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 0052b040  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052b042  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052b045  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0052b047  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b048  668b8d540d0000         -mov cx, word ptr [ebp + 0xd54]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */);
    // 0052b04f  668bb5560d0000         -mov si, word ptr [ebp + 0xd56]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */);
    // 0052b056  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052b058  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b05a  66898d540d0000         -mov word ptr [ebp + 0xd54], cx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */) = cpu.cx;
    // 0052b061  6689b5560d0000         -mov word ptr [ebp + 0xd56], si
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */) = cpu.si;
    // 0052b068  8bb5500d0000           -mov esi, dword ptr [ebp + 0xd50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 0052b06e  8d0c1f                 -lea ecx, [edi + ebx]
    cpu.ecx = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 0052b071  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052b075  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0052b079  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052b07b  29d3                   +sub ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b07d  89b5500d0000           -mov dword ptr [ebp + 0xd50], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = cpu.esi;
    // 0052b083  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052b087  e928ffffff             -jmp 0x52afb4
    goto L_0x0052afb4;
L_0x0052b08c:
    // 0052b08c  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052b092  e80169feff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 0052b097  c786500d000000000000   -mov dword ptr [esi + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052b0a1  e9fbfeffff             -jmp 0x52afa1
    goto L_0x0052afa1;
L_0x0052b0a6:
    // 0052b0a6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b0aa  8b854c0d0000           -mov eax, dword ptr [ebp + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 0052b0b0  e84768feff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 0052b0b5  8985440d0000           -mov dword ptr [ebp + 0xd44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */) = cpu.eax;
    // 0052b0bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052b0bd  753c                   -jne 0x52b0fb
    if (!cpu.flags.zf)
    {
        goto L_0x0052b0fb;
    }
    // 0052b0bf  83bd500d000000         +cmp dword ptr [ebp + 0xd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b0c6  7412                   -je 0x52b0da
    if (cpu.flags.zf)
    {
        goto L_0x0052b0da;
    }
    // 0052b0c8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052b0cc  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0052b0d3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b0d5  e86655fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0052b0da:
    // 0052b0da  66c785540d00000000     -mov word ptr [ebp + 0xd54], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052b0e3  c785480d000000000000   -mov dword ptr [ebp + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
L_0x0052b0ed:
    // 0052b0ed  8b85500d0000           -mov eax, dword ptr [ebp + 0xd50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 0052b0f3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052b0f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b0f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b0f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b0f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b0fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052b0fb:
    // 0052b0fb  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052b0fe  7416                   -je 0x52b116
    if (cpu.flags.zf)
    {
        goto L_0x0052b116;
    }
    // 0052b100  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052b101  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052b103  e88c2d0000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052b108  66c785540d00000000     -mov word ptr [ebp + 0xd54], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052b111  e9c1feffff             -jmp 0x52afd7
    goto L_0x0052afd7;
L_0x0052b116:
    // 0052b116  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052b119  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052b11e  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052b121  8b85440d0000           -mov eax, dword ptr [ebp + 0xd44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 0052b127  c7450808000000         -mov dword ptr [ebp + 8], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 0052b12e  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b131  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0052b134  66c785540d00000000     -mov word ptr [ebp + 0xd54], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052b13d  e995feffff             -jmp 0x52afd7
    goto L_0x0052afd7;
L_0x0052b142:
    // 0052b142  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052b144  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052b146  e8352e0000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052b14b  66c785560d0000b001     -mov word ptr [ebp + 0xd56], 0x1b0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */) = 432 /*0x1b0*/;
    // 0052b154  e98cfeffff             -jmp 0x52afe5
    goto L_0x0052afe5;
L_0x0052b159:
    // 0052b159  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b15b  e9b3feffff             -jmp 0x52b013
    goto L_0x0052b013;
}

/* align: skip  */
void Application::sub_52b160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b160  e8fb1f0000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 0052b165  c782440d000000000000   -mov dword ptr [edx + 0xd44], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3396) /* 0xd44 */) = 0 /*0x0*/;
    // 0052b16f  c782480d000000000000   -mov dword ptr [edx + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052b179  66c782540d00000000     -mov word ptr [edx + 0xd54], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052b182  66c782560d00000000     -mov word ptr [edx + 0xd56], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(3414) /* 0xd56 */) = 0 /*0x0*/;
    // 0052b18b  89824c0d0000           -mov dword ptr [edx + 0xd4c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3404) /* 0xd4c */) = cpu.eax;
    // 0052b191  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052b195  c782500d000000000000   -mov dword ptr [edx + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052b19f  c70080af5200           -mov dword ptr [eax], 0x52af80
    app->getMemory<x86::reg32>(cpu.eax) = 5418880 /*0x52af80*/;
    // 0052b1a5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052b1a9  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0052b1af  b8580d0000             -mov eax, 0xd58
    cpu.eax = 3416 /*0xd58*/;
    // 0052b1b4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b1c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b1c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b1c2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052b1c4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0052b1c6  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0052b1c9  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 0052b1cc  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0052b1ce  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b1d0  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0052b1d2  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052b1d4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052b1d9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052b1db  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 0052b1e2  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b1e4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b1e6  b900000100             -mov ecx, 0x10000
    cpu.ecx = 65536 /*0x10000*/;
    // 0052b1eb  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052b1ed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b1ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b1f1  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0052b1f4  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0052b1f7  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0052b1f9  83f87f                 +cmp eax, 0x7f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b1fc  7f16                   -jg 0x52b214
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b214;
    }
L_0x0052b1fe:
    // 0052b1fe  81c200000100           -add edx, 0x10000
    (cpu.edx) += x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 0052b204  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0052b207  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 0052b20a  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0052b20c  83ff7f                 +cmp edi, 0x7f
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b20f  7f0b                   -jg 0x52b21c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b21c;
    }
    // 0052b211  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b212  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b213  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052b214:
    // 0052b214  c7037f000000           -mov dword ptr [ebx], 0x7f
    app->getMemory<x86::reg32>(cpu.ebx) = 127 /*0x7f*/;
    // 0052b21a  ebe2                   -jmp 0x52b1fe
    goto L_0x0052b1fe;
L_0x0052b21c:
    // 0052b21c  c7067f000000           -mov dword ptr [esi], 0x7f
    app->getMemory<x86::reg32>(cpu.esi) = 127 /*0x7f*/;
    // 0052b222  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b223  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b224  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b231  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b232  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b233  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052b235  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0052b237:
    // 0052b237  4a                     -dec edx
    (cpu.edx)--;
    // 0052b238  83faff                 +cmp edx, -1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b23b  740c                   -je 0x52b249
    if (cpu.flags.zf)
    {
        goto L_0x0052b249;
    }
    // 0052b23d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052b23f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0052b242  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052b244  40                     -inc eax
    (cpu.eax)++;
    // 0052b245  01d9                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b247  ebee                   -jmp 0x52b237
    goto L_0x0052b237;
L_0x0052b249:
    // 0052b249  83fe01                 +cmp esi, 1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b24c  7505                   -jne 0x52b253
    if (!cpu.flags.zf)
    {
        goto L_0x0052b253;
    }
    // 0052b24e  83f97f                 +cmp ecx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b251  7f26                   -jg 0x52b279
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b279;
    }
L_0x0052b253:
    // 0052b253  83fe02                 +cmp esi, 2
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b256  7508                   -jne 0x52b260
    if (!cpu.flags.zf)
    {
        goto L_0x0052b260;
    }
    // 0052b258  81f9ff7f0000           +cmp ecx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b25e  7f21                   -jg 0x52b281
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b281;
    }
L_0x0052b260:
    // 0052b260  83fe03                 +cmp esi, 3
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b263  750e                   -jne 0x52b273
    if (!cpu.flags.zf)
    {
        goto L_0x0052b273;
    }
    // 0052b265  81f9ffff7f00           +cmp ecx, 0x7fffff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388607 /*0x7fffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b26b  7e06                   -jle 0x52b273
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b273;
    }
    // 0052b26d  81e900000001           -sub ecx, 0x1000000
    (cpu.ecx) -= x86::reg32(x86::sreg32(16777216 /*0x1000000*/));
L_0x0052b273:
    // 0052b273  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b275  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b276  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b277  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b278  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052b279:
    // 0052b279  81e900010000           +sub ecx, 0x100
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b27f  ebf2                   -jmp 0x52b273
    goto L_0x0052b273;
L_0x0052b281:
    // 0052b281  81e900000100           -sub ecx, 0x10000
    (cpu.ecx) -= x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 0052b287  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b289  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b28a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b28b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b28c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_52b290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b290  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b291  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b292  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b293  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b296  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052b298  8b15ec775600           -mov edx, dword ptr [0x5677ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666796) /* 0x5677ec */);
    // 0052b29e  885c2404               -mov byte ptr [esp + 4], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 0052b2a2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052b2a4  7415                   -je 0x52b2bb
    if (cpu.flags.zf)
    {
        goto L_0x0052b2bb;
    }
    // 0052b2a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052b2ab  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b2ad  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052b2b3  ff15ec775600           -call dword ptr [0x5677ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666796) /* 0x5677ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052b2b9  eb30                   -jmp 0x52b2eb
    goto L_0x0052b2eb;
L_0x0052b2bb:
    // 0052b2bb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052b2c0  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052b2c6  e869a4feff             -call 0x515734
    cpu.esp -= 4;
    sub_515734(app, cpu);
    if (cpu.terminate) return;
    // 0052b2cb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b2cc  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b2d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b2d1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0052b2d3  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052b2d7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b2d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052b2d9  2eff153c465300         -call dword ptr cs:[0x53463c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457468) /* 0x53463c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052b2e0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052b2e5  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052b2eb:
    // 0052b2eb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052b2ed  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b2f0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b2f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b2f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b2f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b300  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052b301  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052b303  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0052b304  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052b307  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052b30a  8b15f481a100           -mov edx, dword ptr [0xa181f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10584564) /* 0xa181f4 */);
    // 0052b310  a1a4d2a000             -mov eax, dword ptr [0xa0d2a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10539684) /* 0xa0d2a4 */);
    // 0052b315  8b1db481a100           -mov ebx, dword ptr [0xa181b4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10584500) /* 0xa181b4 */);
    // 0052b31b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b31e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0052b321:
    // 0052b321  3bc2                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b323  7c05                   -jl 0x52b32a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b32a;
    }
    // 0052b325  a1c481a100             -mov eax, dword ptr [0xa181c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584516) /* 0xa181c4 */);
L_0x0052b32a:
    // 0052b32a  3bda                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b32c  7c06                   -jl 0x52b334
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b334;
    }
    // 0052b32e  8b1dc481a100           -mov ebx, dword ptr [0xa181c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10584516) /* 0xa181c4 */);
L_0x0052b334:
    // 0052b334  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 0052b336  d805e481a100           -fadd dword ptr [0xa181e4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(10584548) /* 0xa181e4 */));
    // 0052b33c  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0052b33e  a3a4d2a000             -mov dword ptr [0xa0d2a4], eax
    app->getMemory<x86::reg32>(x86::reg32(10539684) /* 0xa0d2a4 */) = cpu.eax;
    // 0052b343  891db481a100           -mov dword ptr [0xa181b4], ebx
    app->getMemory<x86::reg32>(x86::reg32(10584500) /* 0xa181b4 */) = cpu.ebx;
    // 0052b349  d80d50ae5600           -fmul dword ptr [0x56ae50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680720) /* 0x56ae50 */));
    // 0052b34f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b351  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 0052b353  d80d50ae5600           -fmul dword ptr [0x56ae50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680720) /* 0x56ae50 */));
    // 0052b359  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b35b  d91de481a100           -fstp dword ptr [0xa181e4]
    app->getMemory<float>(x86::reg32(10584548) /* 0xa181e4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b361  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 0052b363  8b15f881a100           -mov edx, dword ptr [0xa181f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10584568) /* 0xa181f8 */);
    // 0052b369  a1a8d2a000             -mov eax, dword ptr [0xa0d2a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10539688) /* 0xa0d2a8 */);
    // 0052b36e  8b1db881a100           -mov ebx, dword ptr [0xa181b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10584504) /* 0xa181b8 */);
    // 0052b374  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b377  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b37a  3bc2                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b37c  7c05                   -jl 0x52b383
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b383;
    }
    // 0052b37e  a1c881a100             -mov eax, dword ptr [0xa181c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584520) /* 0xa181c8 */);
L_0x0052b383:
    // 0052b383  3bda                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b385  7c06                   -jl 0x52b38d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b38d;
    }
    // 0052b387  8b1dc881a100           -mov ebx, dword ptr [0xa181c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10584520) /* 0xa181c8 */);
L_0x0052b38d:
    // 0052b38d  d805e881a100           -fadd dword ptr [0xa181e8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(10584552) /* 0xa181e8 */));
    // 0052b393  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0052b395  a3a8d2a000             -mov dword ptr [0xa0d2a8], eax
    app->getMemory<x86::reg32>(x86::reg32(10539688) /* 0xa0d2a8 */) = cpu.eax;
    // 0052b39a  891db881a100           -mov dword ptr [0xa181b8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10584504) /* 0xa181b8 */) = cpu.ebx;
    // 0052b3a0  d80d54ae5600           -fmul dword ptr [0x56ae54]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680724) /* 0x56ae54 */));
    // 0052b3a6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b3a8  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 0052b3aa  d80d54ae5600           -fmul dword ptr [0x56ae54]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680724) /* 0x56ae54 */));
    // 0052b3b0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b3b2  d91de881a100           -fstp dword ptr [0xa181e8]
    app->getMemory<float>(x86::reg32(10584552) /* 0xa181e8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b3b8  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 0052b3ba  d90524ae5600           -fld dword ptr [0x56ae24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5680676) /* 0x56ae24 */)));
    // 0052b3c0  d80d34ae5600           -fmul dword ptr [0x56ae34]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680692) /* 0x56ae34 */));
    // 0052b3c6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b3c8  d80d44ae5600           -fmul dword ptr [0x56ae44]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680708) /* 0x56ae44 */));
    // 0052b3ce  a1acd2a000             -mov eax, dword ptr [0xa0d2ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10539692) /* 0xa0d2ac */);
    // 0052b3d3  8b1dbc81a100           -mov ebx, dword ptr [0xa181bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10584508) /* 0xa181bc */);
    // 0052b3d9  8b15fc81a100           -mov edx, dword ptr [0xa181fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10584572) /* 0xa181fc */);
    // 0052b3df  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052b3e1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b3e4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b3e7  3bc2                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b3e9  7c05                   -jl 0x52b3f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b3f0;
    }
    // 0052b3eb  a1cc81a100             -mov eax, dword ptr [0xa181cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584524) /* 0xa181cc */);
L_0x0052b3f0:
    // 0052b3f0  3bda                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b3f2  7c06                   -jl 0x52b3fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b3fa;
    }
    // 0052b3f4  8b1dcc81a100           -mov ebx, dword ptr [0xa181cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10584524) /* 0xa181cc */);
L_0x0052b3fa:
    // 0052b3fa  d91524ae5600           -fst dword ptr [0x56ae24]
    app->getMemory<float>(x86::reg32(5680676) /* 0x56ae24 */) = float(cpu.fpu.st(0));
    // 0052b400  d805ec81a100           -fadd dword ptr [0xa181ec]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(10584556) /* 0xa181ec */));
    // 0052b406  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0052b408  a3acd2a000             -mov dword ptr [0xa0d2ac], eax
    app->getMemory<x86::reg32>(x86::reg32(10539692) /* 0xa0d2ac */) = cpu.eax;
    // 0052b40d  891dbc81a100           -mov dword ptr [0xa181bc], ebx
    app->getMemory<x86::reg32>(x86::reg32(10584508) /* 0xa181bc */) = cpu.ebx;
    // 0052b413  d80d58ae5600           -fmul dword ptr [0x56ae58]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680728) /* 0x56ae58 */));
    // 0052b419  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b41b  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 0052b41d  d80d58ae5600           -fmul dword ptr [0x56ae58]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680728) /* 0x56ae58 */));
    // 0052b423  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b425  d91dec81a100           -fstp dword ptr [0xa181ec]
    app->getMemory<float>(x86::reg32(10584556) /* 0xa181ec */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b42b  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 0052b42d  8b150082a100           -mov edx, dword ptr [0xa18200]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10584576) /* 0xa18200 */);
    // 0052b433  a1b0d2a000             -mov eax, dword ptr [0xa0d2b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10539696) /* 0xa0d2b0 */);
    // 0052b438  8b1dc081a100           -mov ebx, dword ptr [0xa181c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10584512) /* 0xa181c0 */);
    // 0052b43e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b441  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b444  3bc2                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b446  7c05                   -jl 0x52b44d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b44d;
    }
    // 0052b448  a1d081a100             -mov eax, dword ptr [0xa181d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584528) /* 0xa181d0 */);
L_0x0052b44d:
    // 0052b44d  3bda                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b44f  7c06                   -jl 0x52b457
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b457;
    }
    // 0052b451  8b1dd081a100           -mov ebx, dword ptr [0xa181d0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10584528) /* 0xa181d0 */);
L_0x0052b457:
    // 0052b457  d805f081a100           -fadd dword ptr [0xa181f0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(10584560) /* 0xa181f0 */));
    // 0052b45d  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 0052b45f  a3b0d2a000             -mov dword ptr [0xa0d2b0], eax
    app->getMemory<x86::reg32>(x86::reg32(10539696) /* 0xa0d2b0 */) = cpu.eax;
    // 0052b464  891dc081a100           -mov dword ptr [0xa181c0], ebx
    app->getMemory<x86::reg32>(x86::reg32(10584512) /* 0xa181c0 */) = cpu.ebx;
    // 0052b46a  d80d5cae5600           -fmul dword ptr [0x56ae5c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680732) /* 0x56ae5c */));
    // 0052b470  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b472  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 0052b474  d80d5cae5600           -fmul dword ptr [0x56ae5c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680732) /* 0x56ae5c */));
    // 0052b47a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b47c  d91df081a100           -fstp dword ptr [0xa181f0]
    app->getMemory<float>(x86::reg32(10584560) /* 0xa181f0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b482  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 0052b484  d9052cae5600           -fld dword ptr [0x56ae2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5680684) /* 0x56ae2c */)));
    // 0052b48a  d80d3cae5600           -fmul dword ptr [0x56ae3c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680700) /* 0x56ae3c */));
    // 0052b490  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b492  d80d4cae5600           -fmul dword ptr [0x56ae4c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680716) /* 0x56ae4c */));
    // 0052b498  8b15f481a100           -mov edx, dword ptr [0xa181f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10584564) /* 0xa181f4 */);
    // 0052b49e  a1a4d2a000             -mov eax, dword ptr [0xa0d2a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10539684) /* 0xa0d2a4 */);
    // 0052b4a3  8b1db481a100           -mov ebx, dword ptr [0xa181b4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10584500) /* 0xa181b4 */);
    // 0052b4a9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052b4ab  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b4ae  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b4b1  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b4b4  d9152cae5600           -fst dword ptr [0x56ae2c]
    app->getMemory<float>(x86::reg32(5680684) /* 0x56ae2c */) = float(cpu.fpu.st(0));
    // 0052b4ba  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b4bd  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b4c0  0f8f5bfeffff           -jg 0x52b321
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b321;
    }
    // 0052b4c6  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 0052b4c7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b4c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b4d0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052b4d4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052b4d8  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b4dc  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0052b4df  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052b4e1  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b4e3  7313                   -jae 0x52b4f8
    if (!cpu.flags.cf)
    {
        goto L_0x0052b4f8;
    }
L_0x0052b4e5:
    // 0052b4e5  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0052b4e7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b4ea  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0052b4ed  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b4f0  d958fc                 -fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b4f3  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b4f5  72ee                   -jb 0x52b4e5
    if (cpu.flags.cf)
    {
        goto L_0x0052b4e5;
    }
    // 0052b4f7  90                     -nop 
    ;
L_0x0052b4f8:
    // 0052b4f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b501  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052b503  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052b506  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b508  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0052b50b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b50d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b50f  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0052b512  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b514  05b4bc9f00             -add eax, 0x9fbcb4
    (cpu.eax) += x86::reg32(x86::sreg32(10468532 /*0x9fbcb4*/));
    // 0052b519  884803                 -mov byte ptr [eax + 3], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 0052b51c  e83351fdff             -call 0x500654
    cpu.esp -= 4;
    sub_500654(app, cpu);
    if (cpu.terminate) return;
    // 0052b521  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b522  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b523(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b523  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052b524  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052b526  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052b527  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b528  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b529  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b52a  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b52d  8a6518                 -mov ah, byte ptr [ebp + 0x18]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0052b530  80fc01                 +cmp ah, 1
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052b533  772f                   -ja 0x52b564
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052b564;
    }
    // 0052b535  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0052b537  7524                   -jne 0x52b55d
    if (!cpu.flags.zf)
    {
        goto L_0x0052b55d;
    }
    // 0052b539  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0052b53b  dc5d10                 +fcomp qword ptr [ebp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 0052b53e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052b540  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052b541  730a                   -jae 0x52b54d
    if (!cpu.flags.cf)
    {
        goto L_0x0052b54d;
    }
    // 0052b543  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0052b545  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 0052b548  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 0052b54b  eb4f                   -jmp 0x52b59c
    goto L_0x0052b59c;
L_0x0052b54d:
    // 0052b54d  7607                   -jbe 0x52b556
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052b556;
    }
    // 0052b54f  b847800000             -mov eax, 0x8047
    cpu.eax = 32839 /*0x8047*/;
    // 0052b554  eb38                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b556:
    // 0052b556  b847400000             -mov eax, 0x4047
    cpu.eax = 16455 /*0x4047*/;
    // 0052b55b  eb31                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b55d:
    // 0052b55d  b847200000             -mov eax, 0x2047
    cpu.eax = 8263 /*0x2047*/;
    // 0052b562  eb2a                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b564:
    // 0052b564  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0052b566  dc5d10                 +fcomp qword ptr [ebp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 0052b569  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052b56b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052b56c  720a                   -jb 0x52b578
    if (cpu.flags.cf)
    {
        goto L_0x0052b578;
    }
    // 0052b56e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052b570  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 0052b573  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 0052b576  eb24                   -jmp 0x52b59c
    goto L_0x0052b59c;
L_0x0052b578:
    // 0052b578  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0052b57a  dc5d08                 +fcomp qword ptr [ebp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 0052b57d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052b57f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052b580  7307                   -jae 0x52b589
    if (!cpu.flags.cf)
    {
        goto L_0x0052b589;
    }
    // 0052b582  b807810000             -mov eax, 0x8107
    cpu.eax = 33031 /*0x8107*/;
    // 0052b587  eb05                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b589:
    // 0052b589  b807110000             -mov eax, 0x1107
    cpu.eax = 4359 /*0x1107*/;
L_0x0052b58e:
    // 0052b58e  8d5d10                 -lea ebx, [ebp + 0x10]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052b591  8d5508                 -lea edx, [ebp + 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052b594  e8188effff             -call 0x5243b1
    cpu.esp -= 4;
    sub_5243b1(app, cpu);
    if (cpu.terminate) return;
    // 0052b599  dd5de8                 -fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0052b59c:
    // 0052b59c  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0052b59f  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0052b5a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a5  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a7  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b5b0  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b5b7  741c                   -je 0x52b5d5
    if (cpu.flags.zf)
    {
        goto L_0x0052b5d5;
    }
    // 0052b5b9  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0052b5bb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052b5c0  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052b5c6  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052b5c8  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052b5cd  7406                   -je 0x52b5d5
    if (cpu.flags.zf)
    {
        goto L_0x0052b5d5;
    }
    // 0052b5cf  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0052b5d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052b5d5:
    // 0052b5d5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052b5da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b5e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b5e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b5e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b5e2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b5e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052b5e7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052b5e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b5eb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b5ed  e81e2d0000             -call 0x52e310
    cpu.esp -= 4;
    sub_52e310(app, cpu);
    if (cpu.terminate) return;
    // 0052b5f2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052b5f4  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0052b5f6  e8b5ffffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052b5fb  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 0052b5fe  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b602  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052b604  e8072d0000             -call 0x52e310
    cpu.esp -= 4;
    sub_52e310(app, cpu);
    if (cpu.terminate) return;
    // 0052b609  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b60b  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0052b60d  e89effffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052b612  88740404               -mov byte ptr [esp + eax + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 0052b616  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b618  e8332d0000             -call 0x52e350
    cpu.esp -= 4;
    sub_52e350(app, cpu);
    if (cpu.terminate) return;
    // 0052b61d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b621  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b625  e8262d0000             -call 0x52e350
    cpu.esp -= 4;
    sub_52e350(app, cpu);
    if (cpu.terminate) return;
    // 0052b62a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b62c  e86f2d0000             -call 0x52e3a0
    cpu.esp -= 4;
    sub_52e3a0(app, cpu);
    if (cpu.terminate) return;
    // 0052b631  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b634  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b635  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b636  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b640  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b641(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b641  a36cb15600             -mov dword ptr [0x56b16c], eax
    app->getMemory<x86::reg32>(x86::reg32(5681516) /* 0x56b16c */) = cpu.eax;
    // 0052b646  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
