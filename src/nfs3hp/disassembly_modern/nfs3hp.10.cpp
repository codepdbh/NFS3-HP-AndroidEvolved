#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x90 */
void Application::sub_439620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439620  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439621  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439622  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439624  6683780400             +cmp word ptr [eax + 4], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00439629  7524                   -jne 0x43964f
    if (!cpu.flags.zf)
    {
        goto L_0x0043964f;
    }
    // 0043962b  6683780600             +cmp word ptr [eax + 6], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00439630  751d                   -jne 0x43964f
    if (!cpu.flags.zf)
    {
        goto L_0x0043964f;
    }
    // 00439632  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00439635  833a00                 +cmp dword ptr [edx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439638  7515                   -jne 0x43964f
    if (!cpu.flags.zf)
    {
        goto L_0x0043964f;
    }
    // 0043963a  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0043963d  833a00                 +cmp dword ptr [edx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439640  750d                   -jne 0x43964f
    if (!cpu.flags.zf)
    {
        goto L_0x0043964f;
    }
    // 00439642  833832                 +cmp dword ptr [eax], 0x32
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439645  7308                   -jae 0x43964f
    if (!cpu.flags.cf)
    {
        goto L_0x0043964f;
    }
    // 00439647  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043964c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043964d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043964e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043964f:
    // 0043964f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439651  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439652  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439653  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_439660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439660  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439661  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439662  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439664  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00439666  e8b5ffffff             -call 0x439620
    cpu.esp -= 4;
    sub_439620(app, cpu);
    if (cpu.terminate) return;
    // 0043966b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043966d  7508                   -jne 0x439677
    if (!cpu.flags.zf)
    {
        goto L_0x00439677;
    }
    // 0043966f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00439674  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439675  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439676  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439677:
    // 00439677  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00439679  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043967a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043967b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_439680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439680  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439681  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439683  e8c8030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439688  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 0043968e  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00439691  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439692  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4396a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004396a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004396a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004396a3  e8e8020000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 004396a8  e8d3ffffff             -call 0x439680
    cpu.esp -= 4;
    sub_439680(app, cpu);
    if (cpu.terminate) return;
    // 004396ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004396ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4396b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004396b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004396b1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004396b3  e898030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004396b8  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 004396be  83e010                 -and eax, 0x10
    cpu.eax &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004396c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004396c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4396d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004396d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004396d1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004396d3  e8b8020000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 004396d8  e8d3ffffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 004396dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004396de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4396e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004396e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004396e1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004396e3  e868030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004396e8  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 004396ee  83e020                 -and eax, 0x20
    cpu.eax &= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004396f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004396f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439700  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439701  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439703  e888020000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439708  e8d3ffffff             -call 0x4396e0
    cpu.esp -= 4;
    sub_4396e0(app, cpu);
    if (cpu.terminate) return;
    // 0043970d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043970e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439710  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439711  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439713  e838030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439718  8a80a0030000           -mov al, byte ptr [eax + 0x3a0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(928) /* 0x3a0 */);
    // 0043971e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00439723  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439724  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_439730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439730  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439731  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439733  e818030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439738  8b8088030000           -mov eax, dword ptr [eax + 0x388]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(904) /* 0x388 */);
    // 0043973e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043973f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_439740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439740  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439741  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439743  e808030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439748  8b8084030000           -mov eax, dword ptr [eax + 0x384]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(900) /* 0x384 */);
    // 0043974e  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00439751  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439752  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439760  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439761  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439763  e8e8020000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439768  8b8034030000           -mov eax, dword ptr [eax + 0x334]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(820) /* 0x334 */);
    // 0043976e  40                     -inc eax
    (cpu.eax)++;
    // 0043976f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439770  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_439780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439780  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439781  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439783  e8d8ffffff             -call 0x439760
    cpu.esp -= 4;
    sub_439760(app, cpu);
    if (cpu.terminate) return;
    // 00439788  48                     -dec eax
    (cpu.eax)--;
    // 00439789  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043978a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_439790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439790  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439791  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439793  e8b8020000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439798  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043979a  7405                   -je 0x4397a1
    if (cpu.flags.zf)
    {
        goto L_0x004397a1;
    }
    // 0043979c  83fa01                 +cmp edx, 1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043979f  7509                   -jne 0x4397aa
    if (!cpu.flags.zf)
    {
        goto L_0x004397aa;
    }
L_0x004397a1:
    // 004397a1  8b84902c030000         -mov eax, dword ptr [eax + edx*4 + 0x32c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(812) /* 0x32c */ + cpu.edx * 4);
    // 004397a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004397a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004397aa:
    // 004397aa  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004397af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004397b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4397c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004397c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004397c1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004397c3  83c21e                 -add edx, 0x1e
    (cpu.edx) += x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 004397c6  e8e5020000             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 004397cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004397cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4397d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004397d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004397d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004397d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004397d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004397d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004397d7  e874020000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004397dc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004397de  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004397e0  7405                   -je 0x4397e7
    if (cpu.flags.zf)
    {
        goto L_0x004397e7;
    }
    // 004397e2  83fa01                 +cmp edx, 1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004397e5  751f                   -jne 0x439806
    if (!cpu.flags.zf)
    {
        goto L_0x00439806;
    }
L_0x004397e7:
    // 004397e7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004397e9  899c962c030000         -mov dword ptr [esi + edx*4 + 0x32c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(812) /* 0x32c */ + cpu.edx * 4) = cpu.ebx;
    // 004397f0  e8fb1f0000             -call 0x43b7f0
    cpu.esp -= 4;
    sub_43b7f0(app, cpu);
    if (cpu.terminate) return;
    // 004397f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004397f7  e8648b0300             -call 0x472360
    cpu.esp -= 4;
    sub_472360(app, cpu);
    if (cpu.terminate) return;
    // 004397fc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004397fe  7506                   -jne 0x439806
    if (!cpu.flags.zf)
    {
        goto L_0x00439806;
    }
    // 00439800  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439802  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439803  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439804  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439805  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439806:
    // 00439806  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0043980b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043980c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043980d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043980e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439810  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439811  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439812  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439813  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439815  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00439817  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00439819  e832020000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043981e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00439820  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00439822  e839ffffff             -call 0x439760
    cpu.esp -= 4;
    sub_439760(app, cpu);
    if (cpu.terminate) return;
    // 00439827  39c2                   +cmp edx, eax
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
    // 00439829  7e0a                   -jle 0x439835
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00439835;
    }
    // 0043982b  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00439830  e979000000             -jmp 0x4398ae
    goto L_0x004398ae;
L_0x00439835:
    // 00439835  48                     -dec eax
    (cpu.eax)--;
    // 00439836  39c2                   +cmp edx, eax
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
    // 00439838  7543                   -jne 0x43987d
    if (!cpu.flags.zf)
    {
        goto L_0x0043987d;
    }
    // 0043983a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043983c  7c05                   -jl 0x439843
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00439843;
    }
    // 0043983e  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439841  7e0d                   -jle 0x439850
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00439850;
    }
L_0x00439843:
    // 00439843  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00439848  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043984a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043984b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043984c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043984d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00439850:
    // 00439850  8a849978030000         -mov al, byte ptr [ecx + ebx*4 + 0x378]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(888) /* 0x378 */ + cpu.ebx * 4);
    // 00439857  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439859  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0043985c  8a849979030000         -mov al, byte ptr [ecx + ebx*4 + 0x379]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(889) /* 0x379 */ + cpu.ebx * 4);
    // 00439863  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00439865  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00439868  8a84997a030000         -mov al, byte ptr [ecx + ebx*4 + 0x37a]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(890) /* 0x37a */ + cpu.ebx * 4);
    // 0043986f  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00439871  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00439874  8a84997b030000         -mov al, byte ptr [ecx + ebx*4 + 0x37b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(891) /* 0x37b */ + cpu.ebx * 4);
    // 0043987b  eb2d                   -jmp 0x4398aa
    goto L_0x004398aa;
L_0x0043987d:
    // 0043987d  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00439880  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 00439883  8a8338030000           -mov al, byte ptr [ebx + 0x338]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(824) /* 0x338 */);
    // 00439889  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043988b  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0043988e  8a8339030000           -mov al, byte ptr [ebx + 0x339]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(825) /* 0x339 */);
    // 00439894  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00439896  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00439899  8a833a030000           -mov al, byte ptr [ebx + 0x33a]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(826) /* 0x33a */);
    // 0043989f  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004398a1  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004398a4  8a833b030000           -mov al, byte ptr [ebx + 0x33b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(827) /* 0x33b */);
L_0x004398aa:
    // 004398aa  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004398ac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004398ae:
    // 004398ae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004398b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004398b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004398b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004398b3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4398c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004398c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004398c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004398c2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004398c4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004398c6  e885010000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004398cb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004398cd  7c05                   -jl 0x4398d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004398d4;
    }
    // 004398cf  83fa01                 +cmp edx, 1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004398d2  7e0a                   -jle 0x4398de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004398de;
    }
L_0x004398d4:
    // 004398d4  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004398d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004398da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004398db  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004398de:
    // 004398de  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004398e1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004398e3  889878030000           -mov byte ptr [eax + 0x378], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(888) /* 0x378 */) = cpu.bl;
    // 004398e9  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004398ec  888879030000           -mov byte ptr [eax + 0x379], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(889) /* 0x379 */) = cpu.cl;
    // 004398f2  88907a030000           -mov byte ptr [eax + 0x37a], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(890) /* 0x37a */) = cpu.dl;
    // 004398f8  8a5510                 -mov dl, byte ptr [ebp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004398fb  88907b030000           -mov byte ptr [eax + 0x37b], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(891) /* 0x37b */) = cpu.dl;
    // 00439901  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00439903  e8e81e0000             -call 0x43b7f0
    cpu.esp -= 4;
    sub_43b7f0(app, cpu);
    if (cpu.terminate) return;
    // 00439908  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043990a  740a                   -je 0x439916
    if (cpu.flags.zf)
    {
        goto L_0x00439916;
    }
    // 0043990c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00439911  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439912  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439913  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00439916:
    // 00439916  e8458a0300             -call 0x472360
    cpu.esp -= 4;
    sub_472360(app, cpu);
    if (cpu.terminate) return;
    // 0043991b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043991d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043991e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043991f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_439930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439930  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439931  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439933  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439935  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439936  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439940  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439941  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439943  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439945  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439946  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439950  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439951  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439953  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439955  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439956  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439960  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439961  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439963  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439965  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439966  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439970  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439971  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439973  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439975  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439976  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439980  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439981  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439983  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439985  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439986  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439990  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439991  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439992  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439993  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439994  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439995  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439996  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439998  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043999b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043999d  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004399a0  e8dbf0ffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
    // 004399a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004399a7:
    // 004399a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004399a9  742b                   -je 0x4399d6
    if (cpu.flags.zf)
    {
        goto L_0x004399d6;
    }
    // 004399ab  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004399b0  8db81c030000           -lea edi, [eax + 0x31c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(796) /* 0x31c */);
    // 004399b6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004399b8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004399ba  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
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
        if (!cpu.flags.zf)
            break;
    }
    // 004399bc  7405                   -je 0x4399c3
    if (cpu.flags.zf)
    {
        goto L_0x004399c3;
    }
    // 004399be  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004399c0  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004399c3:
    // 004399c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004399c5  7504                   -jne 0x4399cb
    if (!cpu.flags.zf)
    {
        goto L_0x004399cb;
    }
    // 004399c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004399c9  eb10                   -jmp 0x4399db
    goto L_0x004399db;
L_0x004399cb:
    // 004399cb  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004399ce  e8cdf0ffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 004399d3  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004399d4  ebd1                   -jmp 0x4399a7
    goto L_0x004399a7;
L_0x004399d6:
    // 004399d6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004399db:
    // 004399db  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004399dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4399f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004399f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004399f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004399f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004399f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004399f5  bbc8000000             -mov ebx, 0xc8
    cpu.ebx = 200 /*0xc8*/;
    // 004399fa  b8003c5f00             -mov eax, 0x5f3c00
    cpu.eax = 6241280 /*0x5f3c00*/;
    // 004399ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00439a01  e83a6c0a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00439a06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a08  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_439a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439a10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439a11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439a12  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439a14  8b1485844f5500         -mov edx, dword ptr [eax*4 + 0x554f84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590916) /* 0x554f84 */ + cpu.eax * 4);
    // 00439a1b  b8c0d26f00             -mov eax, 0x6fd2c0
    cpu.eax = 7328448 /*0x6fd2c0*/;
    // 00439a20  e8abf0ffff             -call 0x438ad0
    cpu.esp -= 4;
    sub_438ad0(app, cpu);
    if (cpu.terminate) return;
    // 00439a25  b8c0d26f00             -mov eax, 0x6fd2c0
    cpu.eax = 7328448 /*0x6fd2c0*/;
    // 00439a2a  e861ffffff             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439a2f  a3bcd26f00             -mov dword ptr [0x6fd2bc], eax
    app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */) = cpu.eax;
    // 00439a34  e8f7fcffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 00439a39  a3d0d26f00             -mov dword ptr [0x6fd2d0], eax
    app->getMemory<x86::reg32>(x86::reg32(7328464) /* 0x6fd2d0 */) = cpu.eax;
    // 00439a3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_439a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439a50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439a51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439a52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439a53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439a54  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439a56  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00439a59  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00439a5b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00439a5d  83f831                 +cmp eax, 0x31
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49 /*0x31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439a60  7e04                   -jle 0x439a66
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00439a66;
    }
    // 00439a62  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00439a64  eb38                   -jmp 0x439a9e
    goto L_0x00439a9e;
L_0x00439a66:
    // 00439a66  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00439a69  8b98003c5f00           -mov ebx, dword ptr [eax + 0x5f3c00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6241280) /* 0x5f3c00 */);
    // 00439a6f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00439a71  7409                   -je 0x439a7c
    if (cpu.flags.zf)
    {
        goto L_0x00439a7c;
    }
    // 00439a73  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00439a75  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439a77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439a7c:
    // 00439a7c  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00439a7f  e8fcefffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
L_0x00439a84:
    // 00439a84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439a86  740f                   -je 0x439a97
    if (cpu.flags.zf)
    {
        goto L_0x00439a97;
    }
    // 00439a88  39d1                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439a8a  740b                   -je 0x439a97
    if (cpu.flags.zf)
    {
        goto L_0x00439a97;
    }
    // 00439a8c  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00439a8f  e80cf0ffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 00439a94  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439a95  ebed                   -jmp 0x439a84
    goto L_0x00439a84;
L_0x00439a97:
    // 00439a97  890495003c5f00         -mov dword ptr [edx*4 + 0x5f3c00], eax
    app->getMemory<x86::reg32>(x86::reg32(6241280) /* 0x5f3c00 */ + cpu.edx * 4) = cpu.eax;
L_0x00439a9e:
    // 00439a9e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439aa0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439aa1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439aa2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439aa3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439aa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_439ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439ab0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439ab1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439ab2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439ab4  e897ffffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439ab9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439abb  7508                   -jne 0x439ac5
    if (!cpu.flags.zf)
    {
        goto L_0x00439ac5;
    }
    // 00439abd  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 00439ac2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ac3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ac4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439ac5:
    // 00439ac5  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00439ac8  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00439acb  49                     -dec ecx
    (cpu.ecx)--;
    // 00439acc  39ca                   +cmp edx, ecx
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
    // 00439ace  7e08                   -jle 0x439ad8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00439ad8;
    }
    // 00439ad0  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 00439ad5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ad6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ad7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439ad8:
    // 00439ad8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00439adb  e810000000             -call 0x439af0
    cpu.esp -= 4;
    sub_439af0(app, cpu);
    if (cpu.terminate) return;
    // 00439ae0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ae1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ae2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439af0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439af1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439af2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439af4  0fbf08                 -movsx ecx, word ptr [eax]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 00439af7  49                     -dec ecx
    (cpu.ecx)--;
    // 00439af8  39ca                   +cmp edx, ecx
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
    // 00439afa  7e05                   -jle 0x439b01
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00439b01;
    }
    // 00439afc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439afe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439aff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439b01:
    // 00439b01  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 00439b08  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00439b0b  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00439b0e  030411                 -add eax, dword ptr [ecx + edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1)));
    // 00439b11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b13  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_439b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439b20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439b21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439b22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439b23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439b24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439b25  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439b27  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00439b2a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00439b2c  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00439b2f  e84cefffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
    // 00439b34  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00439b36:
    // 00439b36  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00439b38  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439b3a  7419                   -je 0x439b55
    if (cpu.flags.zf)
    {
        goto L_0x00439b55;
    }
    // 00439b3c  8d5110                 -lea edx, [ecx + 0x10]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00439b3f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00439b41  e8ca470b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00439b46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439b48  740b                   -je 0x439b55
    if (cpu.flags.zf)
    {
        goto L_0x00439b55;
    }
    // 00439b4a  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00439b4d  e84eefffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 00439b52  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439b53  ebe1                   -jmp 0x439b36
    goto L_0x00439b36;
L_0x00439b55:
    // 00439b55  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439b57  7404                   -je 0x439b5d
    if (cpu.flags.zf)
    {
        goto L_0x00439b5d;
    }
    // 00439b59  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00439b5b  eb05                   -jmp 0x439b62
    goto L_0x00439b62;
L_0x00439b5d:
    // 00439b5d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00439b62:
    // 00439b62  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439b64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_439b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439b70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439b71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439b72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
L_0x00439b74:
    // 00439b74  8b15704f5500           -mov edx, dword ptr [0x554f70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00439b7a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00439b7c  7427                   -je 0x439ba5
    if (cpu.flags.zf)
    {
        goto L_0x00439ba5;
    }
    // 00439b7e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00439b80  a3704f5500             -mov dword ptr [0x554f70], eax
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.eax;
    // 00439b85  f6828003000008         +test byte ptr [edx + 0x380], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(896) /* 0x380 */) & 8 /*0x8*/));
    // 00439b8c  7407                   -je 0x439b95
    if (cpu.flags.zf)
    {
        goto L_0x00439b95;
    }
    // 00439b8e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439b90  e80b170000             -call 0x43b2a0
    cpu.esp -= 4;
    sub_43b2a0(app, cpu);
    if (cpu.terminate) return;
L_0x00439b95:
    // 00439b95  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439b97  e814000000             -call 0x439bb0
    cpu.esp -= 4;
    sub_439bb0(app, cpu);
    if (cpu.terminate) return;
    // 00439b9c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439b9e  e8ed7c0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00439ba3  ebcf                   -jmp 0x439b74
    goto L_0x00439b74;
L_0x00439ba5:
    // 00439ba5  8915704f5500           -mov dword ptr [0x554f70], edx
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.edx;
    // 00439bab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439bad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439bae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439baf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_439bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439bb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439bb1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439bb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439bb5  7507                   -jne 0x439bbe
    if (!cpu.flags.zf)
    {
        goto L_0x00439bbe;
    }
    // 00439bb7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00439bbc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439bbd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439bbe:
    // 00439bbe  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00439bc1  e82a000000             -call 0x439bf0
    cpu.esp -= 4;
    sub_439bf0(app, cpu);
    if (cpu.terminate) return;
    // 00439bc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439bc8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439bc9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_439bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439bd0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439bd1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439bd3  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00439bd6  668b522d               -mov dx, word ptr [edx + 0x2d]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(45) /* 0x2d */);
    // 00439bda  66895004               -mov word ptr [eax + 4], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 00439bde  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00439be1  83c22f                 -add edx, 0x2f
    (cpu.edx) += x86::reg32(x86::sreg32(47 /*0x2f*/));
    // 00439be4  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00439be7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00439bec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439bed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_439bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439bf0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439bf1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439bf2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439bf4  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00439bf7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00439bf9  7407                   -je 0x439c02
    if (cpu.flags.zf)
    {
        goto L_0x00439c02;
    }
    // 00439bfb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439bfd  e88e7c0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00439c02:
    // 00439c02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439c04  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439c10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439c11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439c12  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439c14  f6808003000001         +test byte ptr [eax + 0x380], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) & 1 /*0x1*/));
    // 00439c1b  7505                   -jne 0x439c22
    if (!cpu.flags.zf)
    {
        goto L_0x00439c22;
    }
    // 00439c1d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439c1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439c22:
    // 00439c22  8d901c030000           -lea edx, [eax + 0x31c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(796) /* 0x31c */);
    // 00439c28  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439c2a  e8f1f9ffff             -call 0x439620
    cpu.esp -= 4;
    sub_439620(app, cpu);
    if (cpu.terminate) return;
    // 00439c2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439c31  7503                   -jne 0x439c36
    if (!cpu.flags.zf)
    {
        goto L_0x00439c36;
    }
    // 00439c33  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c34  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439c36:
    // 00439c36  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439c38  e823faffff             -call 0x439660
    cpu.esp -= 4;
    sub_439660(app, cpu);
    if (cpu.terminate) return;
    // 00439c3d  833da8d26f0000         +cmp dword ptr [0x6fd2a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328424) /* 0x6fd2a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439c44  0f846d000000           -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439c4a  83f824                 +cmp eax, 0x24
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439c4d  7214                   -jb 0x439c63
    if (cpu.flags.cf)
    {
        goto L_0x00439c63;
    }
    // 00439c4f  764a                   -jbe 0x439c9b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00439c9b;
    }
    // 00439c51  83f827                 +cmp eax, 0x27
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(39 /*0x27*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439c54  0f825d000000           -jb 0x439cb7
    if (cpu.flags.cf)
    {
        goto L_0x00439cb7;
    }
    // 00439c5a  7615                   -jbe 0x439c71
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00439c71;
    }
    // 00439c5c  83f831                 +cmp eax, 0x31
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49 /*0x31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439c5f  7448                   -je 0x439ca9
    if (cpu.flags.zf)
    {
        goto L_0x00439ca9;
    }
    // 00439c61  eb54                   -jmp 0x439cb7
    goto L_0x00439cb7;
L_0x00439c63:
    // 00439c63  83f811                 +cmp eax, 0x11
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439c66  724f                   -jb 0x439cb7
    if (cpu.flags.cf)
    {
        goto L_0x00439cb7;
    }
    // 00439c68  7623                   -jbe 0x439c8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00439c8d;
    }
    // 00439c6a  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439c6d  7410                   -je 0x439c7f
    if (cpu.flags.zf)
    {
        goto L_0x00439c7f;
    }
    // 00439c6f  eb46                   -jmp 0x439cb7
    goto L_0x00439cb7;
L_0x00439c71:
    // 00439c71  f605a8d26f0001         +test byte ptr [0x6fd2a8], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 1 /*0x1*/));
    // 00439c78  743d                   -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439c7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439c7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439c7f:
    // 00439c7f  f605a8d26f0002         +test byte ptr [0x6fd2a8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 2 /*0x2*/));
    // 00439c86  742f                   -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439c88  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439c8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c8b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439c8d:
    // 00439c8d  f605a8d26f0004         +test byte ptr [0x6fd2a8], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 4 /*0x4*/));
    // 00439c94  7421                   -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439c96  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439c98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439c9b:
    // 00439c9b  f605a8d26f0008         +test byte ptr [0x6fd2a8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 8 /*0x8*/));
    // 00439ca2  7413                   -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439ca4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439ca6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ca7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ca8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439ca9:
    // 00439ca9  f605a8d26f0010         +test byte ptr [0x6fd2a8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 16 /*0x10*/));
    // 00439cb0  7405                   -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439cb2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439cb4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cb5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439cb7:
    // 00439cb7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00439cbc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cbe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439cc0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439cc1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439cc3  e888fdffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439cc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439cca  7405                   -je 0x439cd1
    if (cpu.flags.zf)
    {
        goto L_0x00439cd1;
    }
    // 00439ccc  e83fffffff             -call 0x439c10
    cpu.esp -= 4;
    sub_439c10(app, cpu);
    if (cpu.terminate) return;
L_0x00439cd1:
    // 00439cd1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cd2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439cd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439cd4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439cd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439cd6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439cd8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00439cdb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00439cdd  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00439ce0  e8ebedffff             -call 0x438ad0
    cpu.esp -= 4;
    sub_438ad0(app, cpu);
    if (cpu.terminate) return;
    // 00439ce5  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00439ce8  e8a3fcffff             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439ced  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439cf0  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 00439cf5  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00439cf8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439cfa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cfb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439cfe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439cfe  90                     -nop 
    ;
    // 00439cff  90                     -nop 
    ;
    // 00439d00  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 00439d05  e8caffffff             -call 0x439cd4
    cpu.esp -= 4;
    sub_439cd4(app, cpu);
    if (cpu.terminate) return;
    // 00439d0a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439d0c  740a                   -je 0x439d18
    if (cpu.flags.zf)
    {
        goto L_0x00439d18;
    }
    // 00439d0e  b826000000             -mov eax, 0x26
    cpu.eax = 38 /*0x26*/;
    // 00439d13  e8bcffffff             -call 0x439cd4
    cpu.esp -= 4;
    sub_439cd4(app, cpu);
    if (cpu.terminate) return;
L_0x00439d18:
    // 00439d18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_439d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00439d00;
    // 00439cfe  90                     -nop 
    ;
    // 00439cff  90                     -nop 
    ;
L_entry_0x00439d00:
    // 00439d00  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 00439d05  e8caffffff             -call 0x439cd4
    cpu.esp -= 4;
    sub_439cd4(app, cpu);
    if (cpu.terminate) return;
    // 00439d0a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439d0c  740a                   -je 0x439d18
    if (cpu.flags.zf)
    {
        goto L_0x00439d18;
    }
    // 00439d0e  b826000000             -mov eax, 0x26
    cpu.eax = 38 /*0x26*/;
    // 00439d13  e8bcffffff             -call 0x439cd4
    cpu.esp -= 4;
    sub_439cd4(app, cpu);
    if (cpu.terminate) return;
L_0x00439d18:
    // 00439d18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439d1a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439d1a  90                     -nop 
    ;
    // 00439d1b  90                     -nop 
    ;
    // 00439d1c  90                     -nop 
    ;
    // 00439d1d  90                     -nop 
    ;
    // 00439d1e  90                     -nop 
    ;
    // 00439d1f  90                     -nop 
    ;
    // 00439d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439d21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439d22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439d23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439d24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439d25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439d26  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439d28  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00439d2b  e8a0eeffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 00439d30  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00439d33  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00439d35:
    // 00439d35  3b55fc                 +cmp edx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439d38  7d45                   -jge 0x439d7f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00439d7f;
    }
    // 00439d3a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439d3c  e8dff7ffff             -call 0x439520
    cpu.esp -= 4;
    sub_439520(app, cpu);
    if (cpu.terminate) return;
    // 00439d41  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00439d44  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
L_0x00439d47:
    // 00439d47  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439d4a  7d30                   -jge 0x439d7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00439d7c;
    }
    // 00439d4c  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00439d51  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00439d53  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00439d56  e8c5f7ffff             -call 0x439520
    cpu.esp -= 4;
    sub_439520(app, cpu);
    if (cpu.terminate) return;
    // 00439d5b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00439d5d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00439d5f  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
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
        if (!cpu.flags.zf)
            break;
    }
    // 00439d61  7405                   -je 0x439d68
    if (cpu.flags.zf)
    {
        goto L_0x00439d68;
    }
    // 00439d63  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00439d65  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x00439d68:
    // 00439d68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439d6a  750d                   -jne 0x439d79
    if (!cpu.flags.zf)
    {
        goto L_0x00439d79;
    }
    // 00439d6c  68a4765300             -push 0x5376a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469860 /*0x5376a4*/;
    cpu.esp -= 4;
    // 00439d71  e89a72fcff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00439d76  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00439d79:
    // 00439d79  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439d7a  ebcb                   -jmp 0x439d47
    goto L_0x00439d47;
L_0x00439d7c:
    // 00439d7c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439d7d  ebb6                   -jmp 0x439d35
    goto L_0x00439d35;
L_0x00439d7f:
    // 00439d7f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439d81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_439d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00439d20;
    // 00439d1a  90                     -nop 
    ;
    // 00439d1b  90                     -nop 
    ;
    // 00439d1c  90                     -nop 
    ;
    // 00439d1d  90                     -nop 
    ;
    // 00439d1e  90                     -nop 
    ;
    // 00439d1f  90                     -nop 
    ;
L_entry_0x00439d20:
    // 00439d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439d21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439d22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439d23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439d24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439d25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439d26  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439d28  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00439d2b  e8a0eeffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 00439d30  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00439d33  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00439d35:
    // 00439d35  3b55fc                 +cmp edx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439d38  7d45                   -jge 0x439d7f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00439d7f;
    }
    // 00439d3a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439d3c  e8dff7ffff             -call 0x439520
    cpu.esp -= 4;
    sub_439520(app, cpu);
    if (cpu.terminate) return;
    // 00439d41  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00439d44  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
L_0x00439d47:
    // 00439d47  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439d4a  7d30                   -jge 0x439d7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00439d7c;
    }
    // 00439d4c  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00439d51  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00439d53  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00439d56  e8c5f7ffff             -call 0x439520
    cpu.esp -= 4;
    sub_439520(app, cpu);
    if (cpu.terminate) return;
    // 00439d5b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00439d5d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00439d5f  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
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
        if (!cpu.flags.zf)
            break;
    }
    // 00439d61  7405                   -je 0x439d68
    if (cpu.flags.zf)
    {
        goto L_0x00439d68;
    }
    // 00439d63  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00439d65  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x00439d68:
    // 00439d68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439d6a  750d                   -jne 0x439d79
    if (!cpu.flags.zf)
    {
        goto L_0x00439d79;
    }
    // 00439d6c  68a4765300             -push 0x5376a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469860 /*0x5376a4*/;
    cpu.esp -= 4;
    // 00439d71  e89a72fcff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00439d76  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00439d79:
    // 00439d79  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439d7a  ebcb                   -jmp 0x439d47
    goto L_0x00439d47;
L_0x00439d7c:
    // 00439d7c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439d7d  ebb6                   -jmp 0x439d35
    goto L_0x00439d35;
L_0x00439d7f:
    // 00439d7f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439d81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_439d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439d90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439d91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439d92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439d93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439d94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439d95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439d96  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439d98  81ec78020000           -sub esp, 0x278
    (cpu.esp) -= x86::reg32(x86::sreg32(632 /*0x278*/));
    // 00439d9e  e84dfcffff             -call 0x4399f0
    cpu.esp -= 4;
    sub_4399f0(app, cpu);
    if (cpu.terminate) return;
    // 00439da3  e838eeffff             -call 0x438be0
    cpu.esp -= 4;
    sub_438be0(app, cpu);
    if (cpu.terminate) return;
    // 00439da8  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00439dab  b8b4287a00             -mov eax, 0x7a28b4
    cpu.eax = 8005812 /*0x7a28b4*/;
    // 00439db0  e8fbe8ffff             -call 0x4386b0
    cpu.esp -= 4;
    sub_4386b0(app, cpu);
    if (cpu.terminate) return;
L_0x00439db5:
    // 00439db5  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00439db8  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439dbc  0f8483050000           -je 0x43a345
    if (cpu.flags.zf)
    {
        goto L_0x0043a345;
    }
    // 00439dc2  bad0765300             -mov edx, 0x5376d0
    cpu.edx = 5469904 /*0x5376d0*/;
    // 00439dc7  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00439dca  e8f1000b00             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 00439dcf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00439dd1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439dd3  0f8462050000           -je 0x43a33b
    if (cpu.flags.zf)
    {
        goto L_0x0043a33b;
    }
    // 00439dd9  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00439ddc  e89fecffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
L_0x00439de1:
    // 00439de1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439de3  7422                   -je 0x439e07
    if (cpu.flags.zf)
    {
        goto L_0x00439e07;
    }
    // 00439de5  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00439de8  0510010000             -add eax, 0x110
    (cpu.eax) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 00439ded  e81e450b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00439df2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439df4  7507                   -jne 0x439dfd
    if (!cpu.flags.zf)
    {
        goto L_0x00439dfd;
    }
    // 00439df6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00439dfb  eb0a                   -jmp 0x439e07
    goto L_0x00439e07;
L_0x00439dfd:
    // 00439dfd  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00439e00  e89becffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 00439e05  ebda                   -jmp 0x439de1
    goto L_0x00439de1;
L_0x00439e07:
    // 00439e07  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439e09  0f852c050000           -jne 0x43a33b
    if (!cpu.flags.zf)
    {
        goto L_0x0043a33b;
    }
    // 00439e0f  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 00439e14  8dbdb4feffff           -lea edi, [ebp - 0x14c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439e1a  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00439e1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00439e1e:
    // 00439e1e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00439e20  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439e22  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00439e24  7410                   -je 0x439e36
    if (cpu.flags.zf)
    {
        goto L_0x00439e36;
    }
    // 00439e26  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439e29  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439e2c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00439e2f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439e32  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00439e34  75e8                   -jne 0x439e1e
    if (!cpu.flags.zf)
    {
        goto L_0x00439e1e;
    }
L_0x00439e36:
    // 00439e36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439e37  8d85b4feffff           -lea eax, [ebp - 0x14c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439e3d  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00439e40  8dbdb4feffff           -lea edi, [ebp - 0x14c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439e46  41                     -inc ecx
    (cpu.ecx)++;
    // 00439e47  e8f4e4ffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00439e4c  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00439e4f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439e50  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00439e52  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00439e53  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00439e55  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00439e57  4f                     -dec edi
    (cpu.edi)--;
L_0x00439e58:
    // 00439e58  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00439e5a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439e5c  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00439e5e  7410                   -je 0x439e70
    if (cpu.flags.zf)
    {
        goto L_0x00439e70;
    }
    // 00439e60  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439e63  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439e66  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00439e69  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439e6c  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00439e6e  75e8                   -jne 0x439e58
    if (!cpu.flags.zf)
    {
        goto L_0x00439e58;
    }
L_0x00439e70:
    // 00439e70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439e71  a1503a7a00             -mov eax, dword ptr [0x7a3a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8010320) /* 0x7a3a50 */);
    // 00439e76  e835e40300             -call 0x4782b0
    cpu.esp -= 4;
    sub_4782b0(app, cpu);
    if (cpu.terminate) return;
    // 00439e7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00439e7c  68d8765300             -push 0x5376d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469912 /*0x5376d8*/;
    cpu.esp -= 4;
    // 00439e81  8dbdb4feffff           -lea edi, [ebp - 0x14c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439e87  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00439e89  49                     -dec ecx
    (cpu.ecx)--;
    // 00439e8a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00439e8c  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00439e8e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00439e90  49                     -dec ecx
    (cpu.ecx)--;
    // 00439e91  8d85b4feffff           -lea eax, [ebp - 0x14c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439e97  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00439e99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00439e9a  e8f1570a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00439e9f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00439ea2  bae4765300             -mov edx, 0x5376e4
    cpu.edx = 5469924 /*0x5376e4*/;
    // 00439ea7  8d85b4feffff           -lea eax, [ebp - 0x14c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439ead  e836410b00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 00439eb2  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00439eb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439eb7  7421                   -je 0x439eda
    if (cpu.flags.zf)
    {
        goto L_0x00439eda;
    }
    // 00439eb9  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00439ebe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00439ec0  e8c3f10a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 00439ec5  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439ec8  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00439eca  e851450b00             -call 0x4ee420
    cpu.esp -= 4;
    sub_4ee420(app, cpu);
    if (cpu.terminate) return;
    // 00439ecf  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00439ed2  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00439ed5  e983000000             -jmp 0x439f5d
    goto L_0x00439f5d;
L_0x00439eda:
    // 00439eda  8db5b4feffff           -lea esi, [ebp - 0x14c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439ee0  8dbd88fdffff           -lea edi, [ebp - 0x278]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-632) /* -0x278 */);
    // 00439ee6  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
    // 00439eeb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00439eec:
    // 00439eec  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00439eee  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439ef0  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00439ef2  7410                   -je 0x439f04
    if (cpu.flags.zf)
    {
        goto L_0x00439f04;
    }
    // 00439ef4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439ef7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439efa  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00439efd  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439f00  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00439f02  75e8                   -jne 0x439eec
    if (!cpu.flags.zf)
    {
        goto L_0x00439eec;
    }
L_0x00439f04:
    // 00439f04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439f05  8d8588fdffff           -lea eax, [ebp - 0x278]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-632) /* -0x278 */);
    // 00439f0b  e8e0430b00             -call 0x4ee2f0
    cpu.esp -= 4;
    sub_4ee2f0(app, cpu);
    if (cpu.terminate) return;
    // 00439f10  68e8765300             -push 0x5376e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469928 /*0x5376e8*/;
    cpu.esp -= 4;
    // 00439f15  40                     -inc eax
    (cpu.eax)++;
    // 00439f16  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00439f17  e874570a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00439f1c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00439f1f  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439f22  8d8588fdffff           -lea eax, [ebp - 0x278]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-632) /* -0x278 */);
    // 00439f28  e803190000             -call 0x43b830
    cpu.esp -= 4;
    sub_43b830(app, cpu);
    if (cpu.terminate) return;
    // 00439f2d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00439f2f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00439f31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439f33  7508                   -jne 0x439f3d
    if (!cpu.flags.zf)
    {
        goto L_0x00439f3d;
    }
    // 00439f35  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00439f38  e9fe030000             -jmp 0x43a33b
    goto L_0x0043a33b;
L_0x00439f3d:
    // 00439f3d  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
    // 00439f42  8d85b4feffff           -lea eax, [ebp - 0x14c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439f48  8d4de0                 -lea ecx, [ebp - 0x20]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00439f4b  e8a0430b00             -call 0x4ee2f0
    cpu.esp -= 4;
    sub_4ee2f0(app, cpu);
    if (cpu.terminate) return;
    // 00439f50  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00439f53  8d5de4                 -lea ebx, [ebp - 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00439f56  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00439f58  e8731a0000             -call 0x43b9d0
    cpu.esp -= 4;
    sub_43b9d0(app, cpu);
    if (cpu.terminate) return;
L_0x00439f5d:
    // 00439f5d  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439f61  7525                   -jne 0x439f88
    if (!cpu.flags.zf)
    {
        goto L_0x00439f88;
    }
    // 00439f63  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00439f65  740c                   -je 0x439f73
    if (cpu.flags.zf)
    {
        goto L_0x00439f73;
    }
    // 00439f67  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439f6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00439f6c  e83f1a0000             -call 0x43b9b0
    cpu.esp -= 4;
    sub_43b9b0(app, cpu);
    if (cpu.terminate) return;
    // 00439f71  eb08                   -jmp 0x439f7b
    goto L_0x00439f7b;
L_0x00439f73:
    // 00439f73  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439f76  e885410b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x00439f7b:
    // 00439f7b  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00439f7e  e85de8ffff             -call 0x4387e0
    cpu.esp -= 4;
    sub_4387e0(app, cpu);
    if (cpu.terminate) return;
    // 00439f83  e92dfeffff             -jmp 0x439db5
    goto L_0x00439db5;
L_0x00439f88:
    // 00439f88  baa4030000             -mov edx, 0x3a4
    cpu.edx = 932 /*0x3a4*/;
    // 00439f8d  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 00439f92  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00439f94  e887760a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00439f99  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00439f9c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00439f9e  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00439fa1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00439fa3  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 00439fa8  42                     -inc edx
    (cpu.edx)++;
    // 00439fa9  e872760a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00439fae  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00439fb0  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00439fb3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439fb5  7404                   -je 0x439fbb
    if (cpu.flags.zf)
    {
        goto L_0x00439fbb;
    }
    // 00439fb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439fb9  753e                   -jne 0x439ff9
    if (!cpu.flags.zf)
    {
        goto L_0x00439ff9;
    }
L_0x00439fbb:
    // 00439fbb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00439fbd  740c                   -je 0x439fcb
    if (cpu.flags.zf)
    {
        goto L_0x00439fcb;
    }
    // 00439fbf  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439fc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00439fc4  e8e7190000             -call 0x43b9b0
    cpu.esp -= 4;
    sub_43b9b0(app, cpu);
    if (cpu.terminate) return;
    // 00439fc9  eb08                   -jmp 0x439fd3
    goto L_0x00439fd3;
L_0x00439fcb:
    // 00439fcb  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439fce  e82d410b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x00439fd3:
    // 00439fd3  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00439fd6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00439fd8  7407                   -je 0x439fe1
    if (cpu.flags.zf)
    {
        goto L_0x00439fe1;
    }
    // 00439fda  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439fdc  e8af780a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00439fe1:
    // 00439fe1  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00439fe4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439fe6  7407                   -je 0x439fef
    if (cpu.flags.zf)
    {
        goto L_0x00439fef;
    }
    // 00439fe8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00439fea  e8a1780a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00439fef:
    // 00439fef  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00439ff4  e9c0040000             -jmp 0x43a4b9
    goto L_0x0043a4b9;
L_0x00439ff9:
    // 00439ff9  bba4030000             -mov ebx, 0x3a4
    cpu.ebx = 932 /*0x3a4*/;
    // 00439ffe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043a000  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043a002  e839660a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043a007  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0043a00a  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043a00d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043a00f  e874f00a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0043a014  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043a017  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043a01c  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0043a01f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043a021  e8daf10a00             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0043a026  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043a028  740c                   -je 0x43a036
    if (cpu.flags.zf)
    {
        goto L_0x0043a036;
    }
    // 0043a02a  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043a02d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043a02f  e87c190000             -call 0x43b9b0
    cpu.esp -= 4;
    sub_43b9b0(app, cpu);
    if (cpu.terminate) return;
    // 0043a034  eb08                   -jmp 0x43a03e
    goto L_0x0043a03e;
L_0x0043a036:
    // 0043a036  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043a039  e8c2400b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x0043a03e:
    // 0043a03e  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a041  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0043a044  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a047  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043a04a  88828e030000           -mov byte ptr [edx + 0x38e], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(910) /* 0x38e */) = cpu.al;
    // 0043a050  83f809                 +cmp eax, 9
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a053  741c                   -je 0x43a071
    if (cpu.flags.zf)
    {
        goto L_0x0043a071;
    }
    // 0043a055  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a057  e834780a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a05c  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a05f  e82c780a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a064  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043a067  e874e7ffff             -call 0x4387e0
    cpu.esp -= 4;
    sub_4387e0(app, cpu);
    if (cpu.terminate) return;
    // 0043a06c  e944fdffff             -jmp 0x439db5
    goto L_0x00439db5;
L_0x0043a071:
    // 0043a071  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a074  8a9a84030000           -mov bl, byte ptr [edx + 0x384]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(900) /* 0x384 */);
    // 0043a07a  8b400a                 -mov eax, dword ptr [eax + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0043a07d  80e3f0                 -and bl, 0xf0
    cpu.bl &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0043a080  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043a083  889a84030000           -mov byte ptr [edx + 0x384], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(900) /* 0x384 */) = cpu.bl;
    // 0043a089  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0043a08c  8bb284030000           -mov esi, dword ptr [edx + 0x384]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(900) /* 0x384 */);
    // 0043a092  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043a094  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0043a099  89b284030000           -mov dword ptr [edx + 0x384], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(900) /* 0x384 */) = cpu.esi;
    // 0043a09f  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a0a2  8dba1c030000           -lea edi, [edx + 0x31c]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(796) /* 0x31c */);
    // 0043a0a8  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0043a0ab  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 0043a0b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043a0b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043a0b3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0043a0b6  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043a0b8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0043a0ba  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0043a0bd  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0043a0bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a0c0  8dba15030000           -lea edi, [edx + 0x315]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(789) /* 0x315 */);
    // 0043a0c6  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0043a0cb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043a0cd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043a0cf  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a0d2  e869650a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043a0d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043a0d8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043a0da  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0043a0dd  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043a0df  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0043a0e1  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0043a0e4  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0043a0e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a0e7  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a0ea  6683780600             +cmp word ptr [eax + 6], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043a0ef  740a                   -je 0x43a0fb
    if (cpu.flags.zf)
    {
        goto L_0x0043a0fb;
    }
    // 0043a0f1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a0f4  80888003000001         -or byte ptr [eax + 0x380], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0043a0fb:
    // 0043a0fb  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a0fe  6683780800             +cmp word ptr [eax + 8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043a103  740a                   -je 0x43a10f
    if (cpu.flags.zf)
    {
        goto L_0x0043a10f;
    }
    // 0043a105  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a108  80888003000002         -or byte ptr [eax + 0x380], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0043a10f:
    // 0043a10f  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a112  6683780e00             +cmp word ptr [eax + 0xe], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043a117  740a                   -je 0x43a123
    if (cpu.flags.zf)
    {
        goto L_0x0043a123;
    }
    // 0043a119  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a11c  80888003000004         -or byte ptr [eax + 0x380], 4
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0043a123:
    // 0043a123  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a126  6683781000             +cmp word ptr [eax + 0x10], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043a12b  740a                   -je 0x43a137
    if (cpu.flags.zf)
    {
        goto L_0x0043a137;
    }
    // 0043a12d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a130  80888003000010         -or byte ptr [eax + 0x380], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0043a137:
    // 0043a137  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a13a  6683781400             +cmp word ptr [eax + 0x14], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043a13f  740a                   -je 0x43a14b
    if (cpu.flags.zf)
    {
        goto L_0x0043a14b;
    }
    // 0043a141  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a144  80888003000040         -or byte ptr [eax + 0x380], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x0043a14b:
    // 0043a14b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a14e  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a151  8a4012                 -mov al, byte ptr [eax + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0043a154  8882a0030000           -mov byte ptr [edx + 0x3a0], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(928) /* 0x3a0 */) = cpu.al;
    // 0043a15a  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a15d  668b4016               -mov ax, word ptr [eax + 0x16]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0043a161  6689828c030000         -mov word ptr [edx + 0x38c], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(908) /* 0x38c */) = cpu.ax;
    // 0043a168  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a16b  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0043a16e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043a171  898288030000           -mov dword ptr [edx + 0x388], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(904) /* 0x388 */) = cpu.eax;
    // 0043a177  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a17a  8a4028                 -mov al, byte ptr [eax + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0043a17d  88828f030000           -mov byte ptr [edx + 0x38f], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(911) /* 0x38f */) = cpu.al;
    // 0043a183  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a186  8a4029                 -mov al, byte ptr [eax + 0x29]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */);
    // 0043a189  888290030000           -mov byte ptr [edx + 0x390], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(912) /* 0x390 */) = cpu.al;
    // 0043a18f  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a192  8a402a                 -mov al, byte ptr [eax + 0x2a]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(42) /* 0x2a */);
    // 0043a195  888291030000           -mov byte ptr [edx + 0x391], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(913) /* 0x391 */) = cpu.al;
    // 0043a19b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a19e  8a402b                 -mov al, byte ptr [eax + 0x2b]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(43) /* 0x2b */);
    // 0043a1a1  888292030000           -mov byte ptr [edx + 0x392], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(914) /* 0x392 */) = cpu.al;
    // 0043a1a7  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a1aa  8a402c                 -mov al, byte ptr [eax + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0043a1ad  8a1d2eeb5500           -mov bl, byte ptr [0x55eb2e]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */);
    // 0043a1b3  888293030000           -mov byte ptr [edx + 0x393], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(915) /* 0x393 */) = cpu.al;
    // 0043a1b9  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 0043a1bc  7505                   -jne 0x43a1c3
    if (!cpu.flags.zf)
    {
        goto L_0x0043a1c3;
    }
    // 0043a1be  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 0043a1c1  743e                   -je 0x43a201
    if (cpu.flags.zf)
    {
        goto L_0x0043a201;
    }
L_0x0043a1c3:
    // 0043a1c3  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a1c6  81c21c030000           -add edx, 0x31c
    (cpu.edx) += x86::reg32(x86::sreg32(796 /*0x31c*/));
    // 0043a1cc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a1ce  e88df4ffff             -call 0x439660
    cpu.esp -= 4;
    sub_439660(app, cpu);
    if (cpu.terminate) return;
    // 0043a1d3  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a1d6  7429                   -je 0x43a201
    if (cpu.flags.zf)
    {
        goto L_0x0043a201;
    }
    // 0043a1d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a1da  e881f4ffff             -call 0x439660
    cpu.esp -= 4;
    sub_439660(app, cpu);
    if (cpu.terminate) return;
    // 0043a1df  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a1e2  741d                   -je 0x43a201
    if (cpu.flags.zf)
    {
        goto L_0x0043a201;
    }
    // 0043a1e4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a1e7  e8a4760a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a1ec  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a1ef  e89c760a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a1f4  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043a1f7  e8e4e5ffff             -call 0x4387e0
    cpu.esp -= 4;
    sub_4387e0(app, cpu);
    if (cpu.terminate) return;
    // 0043a1fc  e9b4fbffff             -jmp 0x439db5
    goto L_0x00439db5;
L_0x0043a201:
    // 0043a201  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a204  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a207  e8c4f9ffff             -call 0x439bd0
    cpu.esp -= 4;
    sub_439bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043a20c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043a20e  eb4c                   -jmp 0x43a25c
    goto L_0x0043a25c;
    // 0043a210  90                     -nop 
    ;
    // 0043a211  90                     -nop 
    ;
    // 0043a212  90                     -nop 
    ;
    // 0043a213  90                     -nop 
    ;
    // 0043a214  90                     -nop 
    ;
    // 0043a215  90                     -nop 
    ;
    // 0043a216  90                     -nop 
    ;
    // 0043a217  90                     -nop 
    ;
    // 0043a218  90                     -nop 
    ;
    // 0043a219  90                     -nop 
    ;
    // 0043a21a  90                     -nop 
    ;
    // 0043a21b  90                     -nop 
    ;
    // 0043a21c  90                     -nop 
    ;
    // 0043a21d  90                     -nop 
    ;
    // 0043a21e  90                     -nop 
    ;
    // 0043a21f  90                     -nop 
    ;
    // 0043a220  90                     -nop 
    ;
    // 0043a221  90                     -nop 
    ;
    // 0043a222  90                     -nop 
    ;
    // 0043a223  90                     -nop 
    ;
    // 0043a224  90                     -nop 
    ;
    // 0043a225  90                     -nop 
    ;
    // 0043a226  90                     -nop 
    ;
    // 0043a227  90                     -nop 
    ;
    // 0043a228  90                     -nop 
    ;
    // 0043a229  90                     -nop 
    ;
    // 0043a22a  90                     -nop 
    ;
    // 0043a22b  90                     -nop 
    ;
    // 0043a22c  90                     -nop 
    ;
    // 0043a22d  90                     -nop 
    ;
    // 0043a22e  90                     -nop 
    ;
    // 0043a22f  90                     -nop 
    ;
    // 0043a230  90                     -nop 
    ;
    // 0043a231  90                     -nop 
    ;
    // 0043a232  90                     -nop 
    ;
    // 0043a233  90                     -nop 
    ;
    // 0043a234  90                     -nop 
    ;
    // 0043a235  90                     -nop 
    ;
    // 0043a236  90                     -nop 
    ;
    // 0043a237  90                     -nop 
    ;
    // 0043a238  90                     -nop 
    ;
    // 0043a239  90                     -nop 
    ;
    // 0043a23a  90                     -nop 
    ;
    // 0043a23b  90                     -nop 
    ;
    // 0043a23c  90                     -nop 
    ;
    // 0043a23d  90                     -nop 
    ;
    // 0043a23e  90                     -nop 
    ;
    // 0043a23f  90                     -nop 
    ;
    // 0043a240  90                     -nop 
    ;
    // 0043a241  90                     -nop 
    ;
    // 0043a242  90                     -nop 
    ;
    // 0043a243  90                     -nop 
    ;
    // 0043a244  90                     -nop 
    ;
    // 0043a245  90                     -nop 
    ;
    // 0043a246  90                     -nop 
    ;
    // 0043a247  90                     -nop 
    ;
    // 0043a248  90                     -nop 
    ;
    // 0043a249  90                     -nop 
    ;
    // 0043a24a  90                     -nop 
    ;
    // 0043a24b  90                     -nop 
    ;
    // 0043a24c  90                     -nop 
    ;
    // 0043a24d  90                     -nop 
    ;
    // 0043a24e  90                     -nop 
    ;
    // 0043a24f  90                     -nop 
    ;
    // 0043a250  90                     -nop 
    ;
    // 0043a251  90                     -nop 
    ;
    // 0043a252  90                     -nop 
    ;
    // 0043a253  90                     -nop 
    ;
    // 0043a254  90                     -nop 
    ;
    // 0043a255  90                     -nop 
    ;
    // 0043a256  90                     -nop 
    ;
    // 0043a257  90                     -nop 
    ;
    // 0043a258  90                     -nop 
    ;
    // 0043a259  90                     -nop 
    ;
    // 0043a25a  90                     -nop 
    ;
    // 0043a25b  90                     -nop 
    ;
L_0x0043a25c:
    // 0043a25c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043a25e  751e                   -jne 0x43a27e
    if (!cpu.flags.zf)
    {
        goto L_0x0043a27e;
    }
    // 0043a260  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a263  e828760a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a268  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a26b  e820760a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a270  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0043a275  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043a277  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a278  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a279  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a27a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a27b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a27c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a27d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043a27e:
    // 0043a27e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a281  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0043a286  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043a289  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a28c  e85ff8ffff             -call 0x439af0
    cpu.esp -= 4;
    sub_439af0(app, cpu);
    if (cpu.terminate) return;
    // 0043a291  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043a294  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043a296  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043a297:
    // 0043a297  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043a299  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043a29b  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043a29d  7410                   -je 0x43a2af
    if (cpu.flags.zf)
    {
        goto L_0x0043a2af;
    }
    // 0043a29f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043a2a2  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2a5  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043a2a8  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2ab  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043a2ad  75e8                   -jne 0x43a297
    if (!cpu.flags.zf)
    {
        goto L_0x0043a297;
    }
L_0x0043a2af:
    // 0043a2af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a2b0  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a2b3  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043a2b6  81c710010000           -add edi, 0x110
    (cpu.edi) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0043a2bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043a2bd:
    // 0043a2bd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043a2bf  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043a2c1  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043a2c3  7410                   -je 0x43a2d5
    if (cpu.flags.zf)
    {
        goto L_0x0043a2d5;
    }
    // 0043a2c5  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043a2c8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2cb  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043a2ce  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2d1  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043a2d3  75e8                   -jne 0x43a2bd
    if (!cpu.flags.zf)
    {
        goto L_0x0043a2bd;
    }
L_0x0043a2d5:
    // 0043a2d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a2d6  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a2d9  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043a2dc  81c710020000           -add edi, 0x210
    (cpu.edi) += x86::reg32(x86::sreg32(528 /*0x210*/));
    // 0043a2e2  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0043a2e7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043a2e8:
    // 0043a2e8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043a2ea  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043a2ec  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043a2ee  7410                   -je 0x43a300
    if (cpu.flags.zf)
    {
        goto L_0x0043a300;
    }
    // 0043a2f0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043a2f3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2f6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043a2f9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2fc  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043a2fe  75e8                   -jne 0x43a2e8
    if (!cpu.flags.zf)
    {
        goto L_0x0043a2e8;
    }
L_0x0043a300:
    // 0043a300  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a301  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a304  ba94765300             -mov edx, 0x537694
    cpu.edx = 5469844 /*0x537694*/;
    // 0043a309  0510030000             +add eax, 0x310
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(784 /*0x310*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043a30e  e81d6b0a00             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0043a313  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a316  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043a319  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0043a31f  e86ce8ffff             -call 0x438b90
    cpu.esp -= 4;
    sub_438b90(app, cpu);
    if (cpu.terminate) return;
    // 0043a324  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a327  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043a328  a3744f5500             -mov dword ptr [0x554f74], eax
    app->getMemory<x86::reg32>(x86::reg32(5590900) /* 0x554f74 */) = cpu.eax;
    // 0043a32d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a32f  e8bc100000             -call 0x43b3f0
    cpu.esp -= 4;
    sub_43b3f0(app, cpu);
    if (cpu.terminate) return;
    // 0043a334  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a336  e805140000             -call 0x43b740
    cpu.esp -= 4;
    sub_43b740(app, cpu);
    if (cpu.terminate) return;
L_0x0043a33b:
    // 0043a33b  e8a0e4ffff             -call 0x4387e0
    cpu.esp -= 4;
    sub_4387e0(app, cpu);
    if (cpu.terminate) return;
    // 0043a340  e970faffff             -jmp 0x439db5
    goto L_0x00439db5;
L_0x0043a345:
    // 0043a345  e896e8ffff             -call 0x438be0
    cpu.esp -= 4;
    sub_438be0(app, cpu);
    if (cpu.terminate) return;
    // 0043a34a  e861ebffff             -call 0x438eb0
    cpu.esp -= 4;
    sub_438eb0(app, cpu);
    if (cpu.terminate) return;
    // 0043a34f  b8c1000000             -mov eax, 0xc1
    cpu.eax = 193 /*0xc1*/;
    // 0043a354  babe000000             -mov edx, 0xbe
    cpu.edx = 190 /*0xbe*/;
    // 0043a359  bbbf000000             -mov ebx, 0xbf
    cpu.ebx = 191 /*0xbf*/;
    // 0043a35e  b9c0000000             -mov ecx, 0xc0
    cpu.ecx = 192 /*0xc0*/;
    // 0043a363  66a330515500           -mov word ptr [0x555130], ax
    app->getMemory<x86::reg16>(x86::reg32(5591344) /* 0x555130 */) = cpu.ax;
    // 0043a369  66891532515500         -mov word ptr [0x555132], dx
    app->getMemory<x86::reg16>(x86::reg32(5591346) /* 0x555132 */) = cpu.dx;
    // 0043a370  66891d34515500         -mov word ptr [0x555134], bx
    app->getMemory<x86::reg16>(x86::reg32(5591348) /* 0x555134 */) = cpu.bx;
    // 0043a377  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
    // 0043a37c  66890d36515500         -mov word ptr [0x555136], cx
    app->getMemory<x86::reg16>(x86::reg32(5591350) /* 0x555136 */) = cpu.cx;
    // 0043a383  a304525500             -mov dword ptr [0x555204], eax
    app->getMemory<x86::reg32>(x86::reg32(5591556) /* 0x555204 */) = cpu.eax;
    // 0043a388  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043a38a  a308525500             -mov dword ptr [0x555208], eax
    app->getMemory<x86::reg32>(x86::reg32(5591560) /* 0x555208 */) = cpu.eax;
    // 0043a38f  a30c525500             -mov dword ptr [0x55520c], eax
    app->getMemory<x86::reg32>(x86::reg32(5591564) /* 0x55520c */) = cpu.eax;
    // 0043a394  a310525500             -mov dword ptr [0x555210], eax
    app->getMemory<x86::reg32>(x86::reg32(5591568) /* 0x555210 */) = cpu.eax;
    // 0043a399  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043a39b:
    // 0043a39b  e830e8ffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043a3a0  39c2                   +cmp edx, eax
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
    // 0043a3a2  7d63                   -jge 0x43a407
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a407;
    }
    // 0043a3a4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a3a6  e8a5f6ffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043a3ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043a3ad  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a3af  e8fcf2ffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0043a3b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a3b6  754f                   -jne 0x43a407
    if (!cpu.flags.zf)
    {
        goto L_0x0043a407;
    }
    // 0043a3b8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a3ba  8d0c12                 -lea ecx, [edx + edx]
    cpu.ecx = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0043a3bd  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0043a3c2  05bd070000             -add eax, 0x7bd
    (cpu.eax) += x86::reg32(x86::sreg32(1981 /*0x7bd*/));
    // 0043a3c7  6689b9a2515500         -mov word ptr [ecx + 0x5551a2], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5591458) /* 0x5551a2 */) = cpu.di;
    // 0043a3ce  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 0043a3d5  66898138515500         -mov word ptr [ecx + 0x555138], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5591352) /* 0x555138 */) = cpu.ax;
    // 0043a3dc  c78714525500fd9d64ff   -mov dword ptr [edi + 0x555214], 0xff649dfd
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5591572) /* 0x555214 */) = 4284784125 /*0xff649dfd*/;
    // 0043a3e6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043a3e8  e823f8ffff             -call 0x439c10
    cpu.esp -= 4;
    sub_439c10(app, cpu);
    if (cpu.terminate) return;
    // 0043a3ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a3ef  7413                   -je 0x43a404
    if (cpu.flags.zf)
    {
        goto L_0x0043a404;
    }
    // 0043a3f1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043a3f3  668981a2515500         -mov word ptr [ecx + 0x5551a2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5591458) /* 0x5551a2 */) = cpu.ax;
    // 0043a3fa  c7871452550080809000   -mov dword ptr [edi + 0x555214], 0x908080
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5591572) /* 0x555214 */) = 9470080 /*0x908080*/;
L_0x0043a404:
    // 0043a404  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a405  eb94                   -jmp 0x43a39b
    goto L_0x0043a39b;
L_0x0043a407:
    // 0043a407  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043a409  66891c5538515500       -mov word ptr [edx*2 + 0x555138], bx
    app->getMemory<x86::reg16>(x86::reg32(5591352) /* 0x555138 */ + cpu.edx * 2) = cpu.bx;
    // 0043a411  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a413:
    // 0043a413  e8b8e7ffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043a418  39c2                   +cmp edx, eax
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
    // 0043a41a  0f8d72000000           -jge 0x43a492
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a492;
    }
    // 0043a420  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a422  e829f6ffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043a427  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043a429  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a42b  e8f0f0ffff             -call 0x439520
    cpu.esp -= 4;
    sub_439520(app, cpu);
    if (cpu.terminate) return;
    // 0043a430  e82bf2ffff             -call 0x439660
    cpu.esp -= 4;
    sub_439660(app, cpu);
    if (cpu.terminate) return;
    // 0043a435  83f821                 +cmp eax, 0x21
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a438  7508                   -jne 0x43a442
    if (!cpu.flags.zf)
    {
        goto L_0x0043a442;
    }
    // 0043a43a  891530dc6f00           -mov dword ptr [0x6fdc30], edx
    app->getMemory<x86::reg32>(x86::reg32(7330864) /* 0x6fdc30 */) = cpu.edx;
    // 0043a440  eb50                   -jmp 0x43a492
    goto L_0x0043a492;
L_0x0043a442:
    // 0043a442  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0043a447  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a449  8d3412                 -lea esi, [edx + edx]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0043a44c  bbfd9d64ff             -mov ebx, 0xff649dfd
    cpu.ebx = 4284784125 /*0xff649dfd*/;
    // 0043a451  05bd070000             -add eax, 0x7bd
    (cpu.eax) += x86::reg32(x86::sreg32(1981 /*0x7bd*/));
    // 0043a456  6689be0a505500         -mov word ptr [esi + 0x55500a], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(5591050) /* 0x55500a */) = cpu.di;
    // 0043a45d  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 0043a464  668986a84f5500         -mov word ptr [esi + 0x554fa8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(5590952) /* 0x554fa8 */) = cpu.ax;
    // 0043a46b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043a46d  899f6c505500           -mov dword ptr [edi + 0x55506c], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5591148) /* 0x55506c */) = cpu.ebx;
    // 0043a473  e898f7ffff             -call 0x439c10
    cpu.esp -= 4;
    sub_439c10(app, cpu);
    if (cpu.terminate) return;
    // 0043a478  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a47a  7413                   -je 0x43a48f
    if (cpu.flags.zf)
    {
        goto L_0x0043a48f;
    }
    // 0043a47c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043a47e  6689860a505500         -mov word ptr [esi + 0x55500a], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(5591050) /* 0x55500a */) = cpu.ax;
    // 0043a485  c7876c50550080809000   -mov dword ptr [edi + 0x55506c], 0x908080
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5591148) /* 0x55506c */) = 9470080 /*0x908080*/;
L_0x0043a48f:
    // 0043a48f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a490  eb81                   -jmp 0x43a413
    goto L_0x0043a413;
L_0x0043a492:
    // 0043a492  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043a494  66891c55a84f5500       -mov word ptr [edx*2 + 0x554fa8], bx
    app->getMemory<x86::reg16>(x86::reg32(5590952) /* 0x554fa8 */ + cpu.edx * 2) = cpu.bx;
    // 0043a49c  e8df000000             -call 0x43a580
    cpu.esp -= 4;
    sub_43a580(app, cpu);
    if (cpu.terminate) return;
    // 0043a4a1  e87af8ffff             -call 0x439d20
    cpu.esp -= 4;
    sub_439d20(app, cpu);
    if (cpu.terminate) return;
    // 0043a4a6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043a4a8  e893240a00             -call 0x4dc940
    cpu.esp -= 4;
    sub_4dc940(app, cpu);
    if (cpu.terminate) return;
    // 0043a4ad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043a4b2  e889240a00             -call 0x4dc940
    cpu.esp -= 4;
    sub_4dc940(app, cpu);
    if (cpu.terminate) return;
    // 0043a4b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043a4b9:
    // 0043a4b9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043a4bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_43a4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043a4d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043a4d1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043a4d3  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0043a4d5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0043a4d7  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043a4da  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043a4dd  e82e3e0b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0043a4e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_43a4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043a4f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043a4f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043a4f2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043a4f4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043a4f6  833db8d36f0003         +cmp dword ptr [0x6fd3b8], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a4fd  7509                   -jne 0x43a508
    if (!cpu.flags.zf)
    {
        goto L_0x0043a508;
    }
    // 0043a4ff  e8dcf1ffff             -call 0x4396e0
    cpu.esp -= 4;
    sub_4396e0(app, cpu);
    if (cpu.terminate) return;
    // 0043a504  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a506  750b                   -jne 0x43a513
    if (!cpu.flags.zf)
    {
        goto L_0x0043a513;
    }
L_0x0043a508:
    // 0043a508  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a50a  e8a1f1ffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0043a50f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a511  7405                   -je 0x43a518
    if (cpu.flags.zf)
    {
        goto L_0x0043a518;
    }
L_0x0043a513:
    // 0043a513  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043a515  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a516  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a517  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043a518:
    // 0043a518  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a51a  e8a1f0ffff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 0043a51f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a521  7521                   -jne 0x43a544
    if (!cpu.flags.zf)
    {
        goto L_0x0043a544;
    }
    // 0043a523  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a525  e8e6f0ffff             -call 0x439610
    cpu.esp -= 4;
    sub_439610(app, cpu);
    if (cpu.terminate) return;
    // 0043a52a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a52c  7416                   -je 0x43a544
    if (cpu.flags.zf)
    {
        goto L_0x0043a544;
    }
    // 0043a52e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a530  e84bf1ffff             -call 0x439680
    cpu.esp -= 4;
    sub_439680(app, cpu);
    if (cpu.terminate) return;
    // 0043a535  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a537  750b                   -jne 0x43a544
    if (!cpu.flags.zf)
    {
        goto L_0x0043a544;
    }
    // 0043a539  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a53b  e830f0ffff             -call 0x439570
    cpu.esp -= 4;
    sub_439570(app, cpu);
    if (cpu.terminate) return;
    // 0043a540  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a542  752d                   -jne 0x43a571
    if (!cpu.flags.zf)
    {
        goto L_0x0043a571;
    }
L_0x0043a544:
    // 0043a544  a1b0d36f00             -mov eax, dword ptr [0x6fd3b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043a549  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a54b  760a                   -jbe 0x43a557
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043a557;
    }
    // 0043a54d  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a550  740f                   -je 0x43a561
    if (cpu.flags.zf)
    {
        goto L_0x0043a561;
    }
    // 0043a552  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043a554  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a555  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a556  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043a557:
    // 0043a557  3b15bcd26f00           +cmp edx, dword ptr [0x6fd2bc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a55d  75b4                   -jne 0x43a513
    if (!cpu.flags.zf)
    {
        goto L_0x0043a513;
    }
    // 0043a55f  eb10                   -jmp 0x43a571
    goto L_0x0043a571;
L_0x0043a561:
    // 0043a561  3b15bcd26f00           +cmp edx, dword ptr [0x6fd2bc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a567  7408                   -je 0x43a571
    if (cpu.flags.zf)
    {
        goto L_0x0043a571;
    }
    // 0043a569  3b1528d36f00           +cmp edx, dword ptr [0x6fd328]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a56f  75a2                   -jne 0x43a513
    if (!cpu.flags.zf)
    {
        goto L_0x0043a513;
    }
L_0x0043a571:
    // 0043a571  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043a576  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a577  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a578  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_43a580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043a580  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043a581  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043a582  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043a583  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043a584  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043a585  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043a587  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043a58a  e841e6ffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043a58f  2b05504f5500           -sub eax, dword ptr [0x554f50]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590864) /* 0x554f50 */)));
    // 0043a595  ba20030000             -mov edx, 0x320
    cpu.edx = 800 /*0x320*/;
    // 0043a59a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043a59d  b8d8525500             -mov eax, 0x5552d8
    cpu.eax = 5591768 /*0x5552d8*/;
    // 0043a5a2  e865610a00             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 0043a5a7  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0043a5ac  b8f8555500             -mov eax, 0x5555f8
    cpu.eax = 5592568 /*0x5555f8*/;
    // 0043a5b1  e856610a00             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 0043a5b6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a5b8:
    // 0043a5b8  3b55fc                 +cmp edx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a5bb  7d71                   -jge 0x43a62e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a62e;
    }
    // 0043a5bd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a5bf  e82cffffff             -call 0x43a4f0
    cpu.esp -= 4;
    sub_43a4f0(app, cpu);
    if (cpu.terminate) return;
    // 0043a5c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a5c6  7463                   -je 0x43a62b
    if (cpu.flags.zf)
    {
        goto L_0x0043a62b;
    }
    // 0043a5c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a5ca  e861f1ffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043a5cf  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0043a5d2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a5d4  e877f4ffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043a5d9  8b1c8df8555500         -mov ebx, dword ptr [ecx*4 + 0x5555f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5592568) /* 0x5555f8 */ + cpu.ecx * 4);
    // 0043a5e0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043a5e2  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0043a5e9  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043a5ec  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0043a5f3  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043a5f5  43                     -inc ebx
    (cpu.ebx)++;
    // 0043a5f6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043a5f9  891c8df8555500         -mov dword ptr [ecx*4 + 0x5555f8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5592568) /* 0x5555f8 */ + cpu.ecx * 4) = cpu.ebx;
    // 0043a600  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043a602  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a605  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043a608  01d8                   +add eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043a60a  89b8d8525500           -mov dword ptr [eax + 0x5552d8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5591768) /* 0x5552d8 */) = cpu.edi;
    // 0043a610  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a612  e839f4ffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043a617  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043a619  a1f8555500             -mov eax, dword ptr [0x5555f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592568) /* 0x5555f8 */);
    // 0043a61e  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a61f  890c85d4525500         -mov dword ptr [eax*4 + 0x5552d4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5591764) /* 0x5552d4 */ + cpu.eax * 4) = cpu.ecx;
    // 0043a626  a3f8555500             -mov dword ptr [0x5555f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5592568) /* 0x5555f8 */) = cpu.eax;
L_0x0043a62b:
    // 0043a62b  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a62c  eb8a                   -jmp 0x43a5b8
    goto L_0x0043a5b8;
L_0x0043a62e:
    // 0043a62e  b9d0a44300             -mov ecx, 0x43a4d0
    cpu.ecx = 4433104 /*0x43a4d0*/;
    // 0043a633  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0043a638  b8d8525500             -mov eax, 0x5552d8
    cpu.eax = 5591768 /*0x5552d8*/;
    // 0043a63d  8b15f8555500           -mov edx, dword ptr [0x5555f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592568) /* 0x5555f8 */);
    // 0043a643  e8b03e0b00             -call 0x4ee4f8
    cpu.esp -= 4;
    sub_4ee4f8(app, cpu);
    if (cpu.terminate) return;
    // 0043a648  b9d0a44300             -mov ecx, 0x43a4d0
    cpu.ecx = 4433104 /*0x43a4d0*/;
    // 0043a64d  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0043a652  b8a0535500             -mov eax, 0x5553a0
    cpu.eax = 5591968 /*0x5553a0*/;
    // 0043a657  8b15fc555500           -mov edx, dword ptr [0x5555fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592572) /* 0x5555fc */);
    // 0043a65d  e8963e0b00             -call 0x4ee4f8
    cpu.esp -= 4;
    sub_4ee4f8(app, cpu);
    if (cpu.terminate) return;
    // 0043a662  b9d0a44300             -mov ecx, 0x43a4d0
    cpu.ecx = 4433104 /*0x43a4d0*/;
    // 0043a667  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0043a66c  b868545500             -mov eax, 0x555468
    cpu.eax = 5592168 /*0x555468*/;
    // 0043a671  8b1500565500           -mov edx, dword ptr [0x555600]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592576) /* 0x555600 */);
    // 0043a677  e87c3e0b00             -call 0x4ee4f8
    cpu.esp -= 4;
    sub_4ee4f8(app, cpu);
    if (cpu.terminate) return;
    // 0043a67c  b9d0a44300             -mov ecx, 0x43a4d0
    cpu.ecx = 4433104 /*0x43a4d0*/;
    // 0043a681  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0043a686  b830555500             -mov eax, 0x555530
    cpu.eax = 5592368 /*0x555530*/;
    // 0043a68b  8b1504565500           -mov edx, dword ptr [0x555604]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592580) /* 0x555604 */);
    // 0043a691  e8623e0b00             -call 0x4ee4f8
    cpu.esp -= 4;
    sub_4ee4f8(app, cpu);
    if (cpu.terminate) return;
    // 0043a696  a1f8555500             -mov eax, dword ptr [0x5555f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592568) /* 0x5555f8 */);
    // 0043a69b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043a69d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a69e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a69f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a6a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a6a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a6a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_43a6b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043a6b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043a6b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043a6b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043a6b4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043a6b6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0043a6bd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043a6bf  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043a6c2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043a6c4  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0043a6c7  8b848ad8525500         -mov eax, dword ptr [edx + ecx*4 + 0x5552d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5591768) /* 0x5552d8 */ + cpu.ecx * 4);
    // 0043a6ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a6d0  740a                   -je 0x43a6dc
    if (cpu.flags.zf)
    {
        goto L_0x0043a6dc;
    }
    // 0043a6d2  051c030000             -add eax, 0x31c
    (cpu.eax) += x86::reg32(x86::sreg32(796 /*0x31c*/));
    // 0043a6d7  e8b4f2ffff             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
L_0x0043a6dc:
    // 0043a6dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a6dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a6de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43a6e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043a6e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043a6e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043a6e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043a6e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043a6e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043a6e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043a6e7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043a6e9  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043a6eb  e8e0e4ffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043a6f0  8b15504f5500           -mov edx, dword ptr [0x554f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590864) /* 0x554f50 */);
    // 0043a6f6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043a6f8  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043a6fa  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0043a6fd  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043a700  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0043a703  7436                   -je 0x43a73b
    if (cpu.flags.zf)
    {
        goto L_0x0043a73b;
    }
    // 0043a705  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043a708  7411                   -je 0x43a71b
    if (cpu.flags.zf)
    {
        goto L_0x0043a71b;
    }
    // 0043a70a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043a70f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043a711  b89a515500             -mov eax, 0x55519a
    cpu.eax = 5591450 /*0x55519a*/;
    // 0043a716  e8255f0a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0043a71b:
    // 0043a71b  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043a71e  0f849f050000           -je 0x43acc3
    if (cpu.flags.zf)
    {
        goto L_0x0043acc3;
    }
    // 0043a724  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043a729  b80a505500             -mov eax, 0x55500a
    cpu.eax = 5591050 /*0x55500a*/;
    // 0043a72e  8d1c36                 -lea ebx, [esi + esi]
    cpu.ebx = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0043a731  e80a5f0a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043a736  e988050000             -jmp 0x43acc3
    goto L_0x0043acc3;
L_0x0043a73b:
    // 0043a73b  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0043a73e  0f846f000000           -je 0x43a7b3
    if (cpu.flags.zf)
    {
        goto L_0x0043a7b3;
    }
    // 0043a744  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043a747  7411                   -je 0x43a75a
    if (cpu.flags.zf)
    {
        goto L_0x0043a75a;
    }
    // 0043a749  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043a74e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043a750  b89a515500             -mov eax, 0x55519a
    cpu.eax = 5591450 /*0x55519a*/;
    // 0043a755  e8e65e0a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0043a75a:
    // 0043a75a  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043a75d  7412                   -je 0x43a771
    if (cpu.flags.zf)
    {
        goto L_0x0043a771;
    }
    // 0043a75f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043a764  b80a505500             -mov eax, 0x55500a
    cpu.eax = 5591050 /*0x55500a*/;
    // 0043a769  8d1c36                 -lea ebx, [esi + esi]
    cpu.ebx = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0043a76c  e8cf5e0a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0043a771:
    // 0043a771  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a773:
    // 0043a773  39f2                   +cmp edx, esi
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
    // 0043a775  0f8d48050000           -jge 0x43acc3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043acc3;
    }
    // 0043a77b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a77d  e8cef2ffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043a782  e889f4ffff             -call 0x439c10
    cpu.esp -= 4;
    sub_439c10(app, cpu);
    if (cpu.terminate) return;
    // 0043a787  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a789  7425                   -je 0x43a7b0
    if (cpu.flags.zf)
    {
        goto L_0x0043a7b0;
    }
    // 0043a78b  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0043a78d  b980809000             -mov ecx, 0x908080
    cpu.ecx = 9470080 /*0x908080*/;
    // 0043a792  66891c550a505500       -mov word ptr [edx*2 + 0x55500a], bx
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.bx;
    // 0043a79a  890c956c505500         -mov dword ptr [edx*4 + 0x55506c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5591148) /* 0x55506c */ + cpu.edx * 4) = cpu.ecx;
    // 0043a7a1  66891c55a2515500       -mov word ptr [edx*2 + 0x5551a2], bx
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.bx;
    // 0043a7a9  890c9514525500         -mov dword ptr [edx*4 + 0x555214], ecx
    app->getMemory<x86::reg32>(x86::reg32(5591572) /* 0x555214 */ + cpu.edx * 4) = cpu.ecx;
L_0x0043a7b0:
    // 0043a7b0  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a7b1  ebc0                   -jmp 0x43a773
    goto L_0x0043a773;
L_0x0043a7b3:
    // 0043a7b3  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 0043a7b6  7451                   -je 0x43a809
    if (cpu.flags.zf)
    {
        goto L_0x0043a809;
    }
    // 0043a7b8  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043a7bb  741e                   -je 0x43a7db
    if (cpu.flags.zf)
    {
        goto L_0x0043a7db;
    }
    // 0043a7bd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a7bf:
    // 0043a7bf  39f2                   +cmp edx, esi
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
    // 0043a7c1  7d18                   -jge 0x43a7db
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a7db;
    }
    // 0043a7c3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a7c5  e866efffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043a7ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a7cc  750a                   -jne 0x43a7d8
    if (!cpu.flags.zf)
    {
        goto L_0x0043a7d8;
    }
    // 0043a7ce  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043a7d0  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043a7d8:
    // 0043a7d8  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a7d9  ebe4                   -jmp 0x43a7bf
    goto L_0x0043a7bf;
L_0x0043a7db:
    // 0043a7db  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043a7de  7429                   -je 0x43a809
    if (cpu.flags.zf)
    {
        goto L_0x0043a809;
    }
    // 0043a7e0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a7e2:
    // 0043a7e2  39f2                   +cmp edx, esi
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
    // 0043a7e4  7d23                   -jge 0x43a809
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a809;
    }
    // 0043a7e6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a7e8  e843efffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043a7ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a7ef  7515                   -jne 0x43a806
    if (!cpu.flags.zf)
    {
        goto L_0x0043a806;
    }
    // 0043a7f1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a7f3  e8b8eeffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0043a7f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a7fa  750a                   -jne 0x43a806
    if (!cpu.flags.zf)
    {
        goto L_0x0043a806;
    }
    // 0043a7fc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043a7fe  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043a806:
    // 0043a806  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a807  ebd9                   -jmp 0x43a7e2
    goto L_0x0043a7e2;
L_0x0043a809:
    // 0043a809  f6c120                 +test cl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 32 /*0x20*/));
    // 0043a80c  7453                   -je 0x43a861
    if (cpu.flags.zf)
    {
        goto L_0x0043a861;
    }
    // 0043a80e  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043a811  741f                   -je 0x43a832
    if (cpu.flags.zf)
    {
        goto L_0x0043a832;
    }
    // 0043a813  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a815:
    // 0043a815  39f2                   +cmp edx, esi
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
    // 0043a817  7d19                   -jge 0x43a832
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a832;
    }
    // 0043a819  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a81b  e810efffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043a820  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a823  750a                   -jne 0x43a82f
    if (!cpu.flags.zf)
    {
        goto L_0x0043a82f;
    }
    // 0043a825  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043a827  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043a82f:
    // 0043a82f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a830  ebe3                   -jmp 0x43a815
    goto L_0x0043a815;
L_0x0043a832:
    // 0043a832  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043a835  742a                   -je 0x43a861
    if (cpu.flags.zf)
    {
        goto L_0x0043a861;
    }
    // 0043a837  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a839:
    // 0043a839  39f2                   +cmp edx, esi
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
    // 0043a83b  7d24                   -jge 0x43a861
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a861;
    }
    // 0043a83d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a83f  e8eceeffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043a844  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a847  7515                   -jne 0x43a85e
    if (!cpu.flags.zf)
    {
        goto L_0x0043a85e;
    }
    // 0043a849  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a84b  e860eeffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0043a850  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a852  750a                   -jne 0x43a85e
    if (!cpu.flags.zf)
    {
        goto L_0x0043a85e;
    }
    // 0043a854  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043a856  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043a85e:
    // 0043a85e  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a85f  ebd8                   -jmp 0x43a839
    goto L_0x0043a839;
L_0x0043a861:
    // 0043a861  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 0043a864  7453                   -je 0x43a8b9
    if (cpu.flags.zf)
    {
        goto L_0x0043a8b9;
    }
    // 0043a866  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043a869  741f                   -je 0x43a88a
    if (cpu.flags.zf)
    {
        goto L_0x0043a88a;
    }
    // 0043a86b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a86d:
    // 0043a86d  39f2                   +cmp edx, esi
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
    // 0043a86f  7d19                   -jge 0x43a88a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a88a;
    }
    // 0043a871  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a873  e8b8eeffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043a878  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a87b  750a                   -jne 0x43a887
    if (!cpu.flags.zf)
    {
        goto L_0x0043a887;
    }
    // 0043a87d  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043a87f  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043a887:
    // 0043a887  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a888  ebe3                   -jmp 0x43a86d
    goto L_0x0043a86d;
L_0x0043a88a:
    // 0043a88a  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043a88d  742a                   -je 0x43a8b9
    if (cpu.flags.zf)
    {
        goto L_0x0043a8b9;
    }
    // 0043a88f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a891:
    // 0043a891  39f2                   +cmp edx, esi
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
    // 0043a893  7d24                   -jge 0x43a8b9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a8b9;
    }
    // 0043a895  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a897  e894eeffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043a89c  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a89f  7515                   -jne 0x43a8b6
    if (!cpu.flags.zf)
    {
        goto L_0x0043a8b6;
    }
    // 0043a8a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a8a3  e808eeffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0043a8a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a8aa  750a                   -jne 0x43a8b6
    if (!cpu.flags.zf)
    {
        goto L_0x0043a8b6;
    }
    // 0043a8ac  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043a8ae  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043a8b6:
    // 0043a8b6  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a8b7  ebd8                   -jmp 0x43a891
    goto L_0x0043a891;
L_0x0043a8b9:
    // 0043a8b9  f7c100000400           +test ecx, 0x40000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 262144 /*0x40000*/));
    // 0043a8bf  0f845c000000           -je 0x43a921
    if (cpu.flags.zf)
    {
        goto L_0x0043a921;
    }
    // 0043a8c5  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043a8c8  7429                   -je 0x43a8f3
    if (cpu.flags.zf)
    {
        goto L_0x0043a8f3;
    }
    // 0043a8ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a8cc:
    // 0043a8cc  39f2                   +cmp edx, esi
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
    // 0043a8ce  7d23                   -jge 0x43a8f3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a8f3;
    }
    // 0043a8d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a8d2  e8e9ecffff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 0043a8d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a8d9  750b                   -jne 0x43a8e6
    if (!cpu.flags.zf)
    {
        goto L_0x0043a8e6;
    }
    // 0043a8db  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a8dd  e82eedffff             -call 0x439610
    cpu.esp -= 4;
    sub_439610(app, cpu);
    if (cpu.terminate) return;
    // 0043a8e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a8e4  750a                   -jne 0x43a8f0
    if (!cpu.flags.zf)
    {
        goto L_0x0043a8f0;
    }
L_0x0043a8e6:
    // 0043a8e6  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043a8e8  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043a8f0:
    // 0043a8f0  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a8f1  ebd9                   -jmp 0x43a8cc
    goto L_0x0043a8cc;
L_0x0043a8f3:
    // 0043a8f3  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043a8f6  7429                   -je 0x43a921
    if (cpu.flags.zf)
    {
        goto L_0x0043a921;
    }
    // 0043a8f8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a8fa:
    // 0043a8fa  39f2                   +cmp edx, esi
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
    // 0043a8fc  7d23                   -jge 0x43a921
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a921;
    }
    // 0043a8fe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a900  e8bbecffff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 0043a905  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a907  750b                   -jne 0x43a914
    if (!cpu.flags.zf)
    {
        goto L_0x0043a914;
    }
    // 0043a909  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a90b  e800edffff             -call 0x439610
    cpu.esp -= 4;
    sub_439610(app, cpu);
    if (cpu.terminate) return;
    // 0043a910  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a912  750a                   -jne 0x43a91e
    if (!cpu.flags.zf)
    {
        goto L_0x0043a91e;
    }
L_0x0043a914:
    // 0043a914  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043a916  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043a91e:
    // 0043a91e  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a91f  ebd9                   -jmp 0x43a8fa
    goto L_0x0043a8fa;
L_0x0043a921:
    // 0043a921  f7c100000800           +test ecx, 0x80000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 524288 /*0x80000*/));
    // 0043a927  7446                   -je 0x43a96f
    if (cpu.flags.zf)
    {
        goto L_0x0043a96f;
    }
    // 0043a929  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043a92c  741e                   -je 0x43a94c
    if (cpu.flags.zf)
    {
        goto L_0x0043a94c;
    }
    // 0043a92e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a930:
    // 0043a930  39f2                   +cmp edx, esi
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
    // 0043a932  7d18                   -jge 0x43a94c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a94c;
    }
    // 0043a934  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a936  e885870100             -call 0x4530c0
    cpu.esp -= 4;
    sub_4530c0(app, cpu);
    if (cpu.terminate) return;
    // 0043a93b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a93d  750a                   -jne 0x43a949
    if (!cpu.flags.zf)
    {
        goto L_0x0043a949;
    }
    // 0043a93f  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043a941  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043a949:
    // 0043a949  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a94a  ebe4                   -jmp 0x43a930
    goto L_0x0043a930;
L_0x0043a94c:
    // 0043a94c  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043a94f  741e                   -je 0x43a96f
    if (cpu.flags.zf)
    {
        goto L_0x0043a96f;
    }
    // 0043a951  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a953:
    // 0043a953  39f2                   +cmp edx, esi
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
    // 0043a955  7d18                   -jge 0x43a96f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a96f;
    }
    // 0043a957  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a959  e862870100             -call 0x4530c0
    cpu.esp -= 4;
    sub_4530c0(app, cpu);
    if (cpu.terminate) return;
    // 0043a95e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a960  750a                   -jne 0x43a96c
    if (!cpu.flags.zf)
    {
        goto L_0x0043a96c;
    }
    // 0043a962  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043a964  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043a96c:
    // 0043a96c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a96d  ebe4                   -jmp 0x43a953
    goto L_0x0043a953;
L_0x0043a96f:
    // 0043a96f  f7c100001000           +test ecx, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 1048576 /*0x100000*/));
    // 0043a975  7446                   -je 0x43a9bd
    if (cpu.flags.zf)
    {
        goto L_0x0043a9bd;
    }
    // 0043a977  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043a97a  741e                   -je 0x43a99a
    if (cpu.flags.zf)
    {
        goto L_0x0043a99a;
    }
    // 0043a97c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a97e:
    // 0043a97e  39f2                   +cmp edx, esi
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
    // 0043a980  7d18                   -jge 0x43a99a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a99a;
    }
    // 0043a982  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a984  e877880100             -call 0x453200
    cpu.esp -= 4;
    sub_453200(app, cpu);
    if (cpu.terminate) return;
    // 0043a989  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a98b  750a                   -jne 0x43a997
    if (!cpu.flags.zf)
    {
        goto L_0x0043a997;
    }
    // 0043a98d  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043a98f  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043a997:
    // 0043a997  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a998  ebe4                   -jmp 0x43a97e
    goto L_0x0043a97e;
L_0x0043a99a:
    // 0043a99a  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043a99d  741e                   -je 0x43a9bd
    if (cpu.flags.zf)
    {
        goto L_0x0043a9bd;
    }
    // 0043a99f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a9a1:
    // 0043a9a1  39f2                   +cmp edx, esi
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
    // 0043a9a3  7d18                   -jge 0x43a9bd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a9bd;
    }
    // 0043a9a5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a9a7  e854880100             -call 0x453200
    cpu.esp -= 4;
    sub_453200(app, cpu);
    if (cpu.terminate) return;
    // 0043a9ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a9ae  750a                   -jne 0x43a9ba
    if (!cpu.flags.zf)
    {
        goto L_0x0043a9ba;
    }
    // 0043a9b0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043a9b2  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043a9ba:
    // 0043a9ba  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a9bb  ebe4                   -jmp 0x43a9a1
    goto L_0x0043a9a1;
L_0x0043a9bd:
    // 0043a9bd  f7c100002000           +test ecx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 2097152 /*0x200000*/));
    // 0043a9c3  7446                   -je 0x43aa0b
    if (cpu.flags.zf)
    {
        goto L_0x0043aa0b;
    }
    // 0043a9c5  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043a9c8  741e                   -je 0x43a9e8
    if (cpu.flags.zf)
    {
        goto L_0x0043a9e8;
    }
    // 0043a9ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a9cc:
    // 0043a9cc  39f2                   +cmp edx, esi
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
    // 0043a9ce  7d18                   -jge 0x43a9e8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a9e8;
    }
    // 0043a9d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a9d2  e8b9880100             -call 0x453290
    cpu.esp -= 4;
    sub_453290(app, cpu);
    if (cpu.terminate) return;
    // 0043a9d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a9d9  750a                   -jne 0x43a9e5
    if (!cpu.flags.zf)
    {
        goto L_0x0043a9e5;
    }
    // 0043a9db  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043a9dd  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043a9e5:
    // 0043a9e5  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a9e6  ebe4                   -jmp 0x43a9cc
    goto L_0x0043a9cc;
L_0x0043a9e8:
    // 0043a9e8  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043a9eb  741e                   -je 0x43aa0b
    if (cpu.flags.zf)
    {
        goto L_0x0043aa0b;
    }
    // 0043a9ed  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a9ef:
    // 0043a9ef  39f2                   +cmp edx, esi
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
    // 0043a9f1  7d18                   -jge 0x43aa0b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043aa0b;
    }
    // 0043a9f3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a9f5  e896880100             -call 0x453290
    cpu.esp -= 4;
    sub_453290(app, cpu);
    if (cpu.terminate) return;
    // 0043a9fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a9fc  750a                   -jne 0x43aa08
    if (!cpu.flags.zf)
    {
        goto L_0x0043aa08;
    }
    // 0043a9fe  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043aa00  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043aa08:
    // 0043aa08  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043aa09  ebe4                   -jmp 0x43a9ef
    goto L_0x0043a9ef;
L_0x0043aa0b:
    // 0043aa0b  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 0043aa0e  7446                   -je 0x43aa56
    if (cpu.flags.zf)
    {
        goto L_0x0043aa56;
    }
    // 0043aa10  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043aa13  741e                   -je 0x43aa33
    if (cpu.flags.zf)
    {
        goto L_0x0043aa33;
    }
    // 0043aa15  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043aa17:
    // 0043aa17  39f2                   +cmp edx, esi
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
    // 0043aa19  7d18                   -jge 0x43aa33
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043aa33;
    }
    // 0043aa1b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043aa1d  e85eecffff             -call 0x439680
    cpu.esp -= 4;
    sub_439680(app, cpu);
    if (cpu.terminate) return;
    // 0043aa22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043aa24  740a                   -je 0x43aa30
    if (cpu.flags.zf)
    {
        goto L_0x0043aa30;
    }
    // 0043aa26  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043aa28  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043aa30:
    // 0043aa30  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043aa31  ebe4                   -jmp 0x43aa17
    goto L_0x0043aa17;
L_0x0043aa33:
    // 0043aa33  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043aa36  741e                   -je 0x43aa56
    if (cpu.flags.zf)
    {
        goto L_0x0043aa56;
    }
    // 0043aa38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043aa3a:
    // 0043aa3a  39f2                   +cmp edx, esi
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
    // 0043aa3c  7d18                   -jge 0x43aa56
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043aa56;
    }
    // 0043aa3e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043aa40  e83becffff             -call 0x439680
    cpu.esp -= 4;
    sub_439680(app, cpu);
    if (cpu.terminate) return;
    // 0043aa45  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043aa47  740a                   -je 0x43aa53
    if (cpu.flags.zf)
    {
        goto L_0x0043aa53;
    }
    // 0043aa49  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043aa4b  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043aa53:
    // 0043aa53  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043aa54  ebe4                   -jmp 0x43aa3a
    goto L_0x0043aa3a;
L_0x0043aa56:
    // 0043aa56  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 0043aa59  7446                   -je 0x43aaa1
    if (cpu.flags.zf)
    {
        goto L_0x0043aaa1;
    }
    // 0043aa5b  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043aa5e  741e                   -je 0x43aa7e
    if (cpu.flags.zf)
    {
        goto L_0x0043aa7e;
    }
    // 0043aa60  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043aa62:
    // 0043aa62  39f2                   +cmp edx, esi
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
    // 0043aa64  7d18                   -jge 0x43aa7e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043aa7e;
    }
    // 0043aa66  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043aa68  e873ecffff             -call 0x4396e0
    cpu.esp -= 4;
    sub_4396e0(app, cpu);
    if (cpu.terminate) return;
    // 0043aa6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043aa6f  740a                   -je 0x43aa7b
    if (cpu.flags.zf)
    {
        goto L_0x0043aa7b;
    }
    // 0043aa71  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043aa73  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043aa7b:
    // 0043aa7b  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043aa7c  ebe4                   -jmp 0x43aa62
    goto L_0x0043aa62;
L_0x0043aa7e:
    // 0043aa7e  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043aa81  741e                   -je 0x43aaa1
    if (cpu.flags.zf)
    {
        goto L_0x0043aaa1;
    }
    // 0043aa83  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043aa85:
    // 0043aa85  39f2                   +cmp edx, esi
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
    // 0043aa87  7d18                   -jge 0x43aaa1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043aaa1;
    }
    // 0043aa89  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043aa8b  e850ecffff             -call 0x4396e0
    cpu.esp -= 4;
    sub_4396e0(app, cpu);
    if (cpu.terminate) return;
    // 0043aa90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043aa92  740a                   -je 0x43aa9e
    if (cpu.flags.zf)
    {
        goto L_0x0043aa9e;
    }
    // 0043aa94  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043aa96  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043aa9e:
    // 0043aa9e  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043aa9f  ebe4                   -jmp 0x43aa85
    goto L_0x0043aa85;
L_0x0043aaa1:
    // 0043aaa1  f6c540                 +test ch, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 64 /*0x40*/));
    // 0043aaa4  7446                   -je 0x43aaec
    if (cpu.flags.zf)
    {
        goto L_0x0043aaec;
    }
    // 0043aaa6  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043aaa9  741e                   -je 0x43aac9
    if (cpu.flags.zf)
    {
        goto L_0x0043aac9;
    }
    // 0043aaab  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043aaad:
    // 0043aaad  39f2                   +cmp edx, esi
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
    // 0043aaaf  7d18                   -jge 0x43aac9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043aac9;
    }
    // 0043aab1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043aab3  e8f8ebffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0043aab8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043aaba  740a                   -je 0x43aac6
    if (cpu.flags.zf)
    {
        goto L_0x0043aac6;
    }
    // 0043aabc  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043aabe  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043aac6:
    // 0043aac6  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043aac7  ebe4                   -jmp 0x43aaad
    goto L_0x0043aaad;
L_0x0043aac9:
    // 0043aac9  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043aacc  741e                   -je 0x43aaec
    if (cpu.flags.zf)
    {
        goto L_0x0043aaec;
    }
    // 0043aace  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043aad0:
    // 0043aad0  39f2                   +cmp edx, esi
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
    // 0043aad2  7d18                   -jge 0x43aaec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043aaec;
    }
    // 0043aad4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043aad6  e8d5ebffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0043aadb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043aadd  740a                   -je 0x43aae9
    if (cpu.flags.zf)
    {
        goto L_0x0043aae9;
    }
    // 0043aadf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043aae1  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043aae9:
    // 0043aae9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043aaea  ebe4                   -jmp 0x43aad0
    goto L_0x0043aad0;
L_0x0043aaec:
    // 0043aaec  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 0043aaef  7446                   -je 0x43ab37
    if (cpu.flags.zf)
    {
        goto L_0x0043ab37;
    }
    // 0043aaf1  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043aaf4  741e                   -je 0x43ab14
    if (cpu.flags.zf)
    {
        goto L_0x0043ab14;
    }
    // 0043aaf6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043aaf8:
    // 0043aaf8  39f2                   +cmp edx, esi
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
    // 0043aafa  7d18                   -jge 0x43ab14
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ab14;
    }
    // 0043aafc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043aafe  e8adebffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0043ab03  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ab05  750a                   -jne 0x43ab11
    if (!cpu.flags.zf)
    {
        goto L_0x0043ab11;
    }
    // 0043ab07  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043ab09  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043ab11:
    // 0043ab11  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043ab12  ebe4                   -jmp 0x43aaf8
    goto L_0x0043aaf8;
L_0x0043ab14:
    // 0043ab14  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043ab17  741e                   -je 0x43ab37
    if (cpu.flags.zf)
    {
        goto L_0x0043ab37;
    }
    // 0043ab19  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043ab1b:
    // 0043ab1b  39f2                   +cmp edx, esi
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
    // 0043ab1d  7d18                   -jge 0x43ab37
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ab37;
    }
    // 0043ab1f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043ab21  e88aebffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0043ab26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ab28  750a                   -jne 0x43ab34
    if (!cpu.flags.zf)
    {
        goto L_0x0043ab34;
    }
    // 0043ab2a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043ab2c  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043ab34:
    // 0043ab34  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043ab35  ebe4                   -jmp 0x43ab1b
    goto L_0x0043ab1b;
L_0x0043ab37:
    // 0043ab37  f7c100000100           +test ecx, 0x10000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 65536 /*0x10000*/));
    // 0043ab3d  7446                   -je 0x43ab85
    if (cpu.flags.zf)
    {
        goto L_0x0043ab85;
    }
    // 0043ab3f  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043ab42  741e                   -je 0x43ab62
    if (cpu.flags.zf)
    {
        goto L_0x0043ab62;
    }
    // 0043ab44  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043ab46:
    // 0043ab46  39f2                   +cmp edx, esi
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
    // 0043ab48  7d18                   -jge 0x43ab62
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ab62;
    }
    // 0043ab4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043ab4c  e8bfeaffff             -call 0x439610
    cpu.esp -= 4;
    sub_439610(app, cpu);
    if (cpu.terminate) return;
    // 0043ab51  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ab53  750a                   -jne 0x43ab5f
    if (!cpu.flags.zf)
    {
        goto L_0x0043ab5f;
    }
    // 0043ab55  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043ab57  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043ab5f:
    // 0043ab5f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043ab60  ebe4                   -jmp 0x43ab46
    goto L_0x0043ab46;
L_0x0043ab62:
    // 0043ab62  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043ab65  741e                   -je 0x43ab85
    if (cpu.flags.zf)
    {
        goto L_0x0043ab85;
    }
    // 0043ab67  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043ab69:
    // 0043ab69  39f2                   +cmp edx, esi
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
    // 0043ab6b  7d18                   -jge 0x43ab85
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ab85;
    }
    // 0043ab6d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043ab6f  e89ceaffff             -call 0x439610
    cpu.esp -= 4;
    sub_439610(app, cpu);
    if (cpu.terminate) return;
    // 0043ab74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ab76  750a                   -jne 0x43ab82
    if (!cpu.flags.zf)
    {
        goto L_0x0043ab82;
    }
    // 0043ab78  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043ab7a  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043ab82:
    // 0043ab82  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043ab83  ebe4                   -jmp 0x43ab69
    goto L_0x0043ab69;
L_0x0043ab85:
    // 0043ab85  f7c100000200           +test ecx, 0x20000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 131072 /*0x20000*/));
    // 0043ab8b  7446                   -je 0x43abd3
    if (cpu.flags.zf)
    {
        goto L_0x0043abd3;
    }
    // 0043ab8d  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043ab90  741e                   -je 0x43abb0
    if (cpu.flags.zf)
    {
        goto L_0x0043abb0;
    }
    // 0043ab92  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043ab94:
    // 0043ab94  39f2                   +cmp edx, esi
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
    // 0043ab96  7d18                   -jge 0x43abb0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043abb0;
    }
    // 0043ab98  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043ab9a  e841eaffff             -call 0x4395e0
    cpu.esp -= 4;
    sub_4395e0(app, cpu);
    if (cpu.terminate) return;
    // 0043ab9f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043aba1  750a                   -jne 0x43abad
    if (!cpu.flags.zf)
    {
        goto L_0x0043abad;
    }
    // 0043aba3  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0043aba5  66893c55a2515500       -mov word ptr [edx*2 + 0x5551a2], di
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.di;
L_0x0043abad:
    // 0043abad  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043abae  ebe4                   -jmp 0x43ab94
    goto L_0x0043ab94;
L_0x0043abb0:
    // 0043abb0  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043abb3  741e                   -je 0x43abd3
    if (cpu.flags.zf)
    {
        goto L_0x0043abd3;
    }
    // 0043abb5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043abb7:
    // 0043abb7  39f2                   +cmp edx, esi
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
    // 0043abb9  7d18                   -jge 0x43abd3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043abd3;
    }
    // 0043abbb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043abbd  e81eeaffff             -call 0x4395e0
    cpu.esp -= 4;
    sub_4395e0(app, cpu);
    if (cpu.terminate) return;
    // 0043abc2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043abc4  750a                   -jne 0x43abd0
    if (!cpu.flags.zf)
    {
        goto L_0x0043abd0;
    }
    // 0043abc6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043abc8  668904550a505500       -mov word ptr [edx*2 + 0x55500a], ax
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.ax;
L_0x0043abd0:
    // 0043abd0  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043abd1  ebe4                   -jmp 0x43abb7
    goto L_0x0043abb7;
L_0x0043abd3:
    // 0043abd3  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 0043abd6  7409                   -je 0x43abe1
    if (cpu.flags.zf)
    {
        goto L_0x0043abe1;
    }
    // 0043abd8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043abda  6689159a515500         -mov word ptr [0x55519a], dx
    app->getMemory<x86::reg16>(x86::reg32(5591450) /* 0x55519a */) = cpu.dx;
L_0x0043abe1:
    // 0043abe1  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 0043abe4  7409                   -je 0x43abef
    if (cpu.flags.zf)
    {
        goto L_0x0043abef;
    }
    // 0043abe6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0043abe8  66893d9c515500         -mov word ptr [0x55519c], di
    app->getMemory<x86::reg16>(x86::reg32(5591452) /* 0x55519c */) = cpu.di;
L_0x0043abef:
    // 0043abef  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 0043abf2  7408                   -je 0x43abfc
    if (cpu.flags.zf)
    {
        goto L_0x0043abfc;
    }
    // 0043abf4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043abf6  66a39e515500           -mov word ptr [0x55519e], ax
    app->getMemory<x86::reg16>(x86::reg32(5591454) /* 0x55519e */) = cpu.ax;
L_0x0043abfc:
    // 0043abfc  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 0043abff  7409                   -je 0x43ac0a
    if (cpu.flags.zf)
    {
        goto L_0x0043ac0a;
    }
    // 0043ac01  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043ac03  668915a0515500         -mov word ptr [0x5551a0], dx
    app->getMemory<x86::reg16>(x86::reg32(5591456) /* 0x5551a0 */) = cpu.dx;
L_0x0043ac0a:
    // 0043ac0a  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 0043ac0d  7413                   -je 0x43ac22
    if (cpu.flags.zf)
    {
        goto L_0x0043ac22;
    }
    // 0043ac0f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043ac11:
    // 0043ac11  39f2                   +cmp edx, esi
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
    // 0043ac13  7d0d                   -jge 0x43ac22
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ac22;
    }
    // 0043ac15  42                     -inc edx
    (cpu.edx)++;
    // 0043ac16  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0043ac18  66890c55a0515500       -mov word ptr [edx*2 + 0x5551a0], cx
    app->getMemory<x86::reg16>(x86::reg32(5591456) /* 0x5551a0 */ + cpu.edx * 2) = cpu.cx;
    // 0043ac20  ebef                   -jmp 0x43ac11
    goto L_0x0043ac11;
L_0x0043ac22:
    // 0043ac22  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043ac24  7506                   -jne 0x43ac2c
    if (!cpu.flags.zf)
    {
        goto L_0x0043ac2c;
    }
    // 0043ac26  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ac27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ac28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ac29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ac2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ac2b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043ac2c:
    // 0043ac2c  8b0dd4d46f00           -mov ecx, dword ptr [0x6fd4d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
L_0x0043ac32:
    // 0043ac32  a1d4d46f00             -mov eax, dword ptr [0x6fd4d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 0043ac37  66833c459a51550000     +cmp word ptr [eax*2 + 0x55519a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5591450) /* 0x55519a */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ac40  751f                   -jne 0x43ac61
    if (!cpu.flags.zf)
    {
        goto L_0x0043ac61;
    }
    // 0043ac42  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0043ac45  8d5e04                 -lea ebx, [esi + 4]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043ac48  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043ac4a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043ac4c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043ac4f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043ac51  893dd4d46f00           -mov dword ptr [0x6fd4d4], edi
    app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */) = cpu.edi;
    // 0043ac57  8915d4d46f00           -mov dword ptr [0x6fd4d4], edx
    app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */) = cpu.edx;
    // 0043ac5d  39d1                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ac5f  75d1                   -jne 0x43ac32
    if (!cpu.flags.zf)
    {
        goto L_0x0043ac32;
    }
L_0x0043ac61:
    // 0043ac61  8b0dbcd26f00           -mov ecx, dword ptr [0x6fd2bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
L_0x0043ac67:
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 0043ac67  a1bcd26f00             -mov eax, dword ptr [0x6fd2bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 0043ac6c  66833c450a50550000     +cmp word ptr [eax*2 + 0x55500a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ac75  751a                   -jne 0x43ac91
    if (!cpu.flags.zf)
    {
        goto L_0x0043ac91;
    }
    // 0043ac77  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0043ac7a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043ac7c  8915bcd26f00           -mov dword ptr [0x6fd2bc], edx
    app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */) = cpu.edx;
    // 0043ac82  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043ac85  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043ac87  8915bcd26f00           -mov dword ptr [0x6fd2bc], edx
    app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */) = cpu.edx;
    // 0043ac8d  39d1                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ac8f  75d6                   -jne 0x43ac67
    if (!cpu.flags.zf)
    {
        goto L_0x0043ac67;
    }
L_0x0043ac91:
    // 0043ac91  8b0d28d36f00           -mov ecx, dword ptr [0x6fd328]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */);
L_0x0043ac97:
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 0043ac97  a128d36f00             -mov eax, dword ptr [0x6fd328]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */);
    // 0043ac9c  66833c450a50550000     +cmp word ptr [eax*2 + 0x55500a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043aca5  751c                   -jne 0x43acc3
    if (!cpu.flags.zf)
    {
        goto L_0x0043acc3;
    }
    // 0043aca7  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0043acaa  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043acac  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043acae  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043acb1  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043acb3  893d28d36f00           -mov dword ptr [0x6fd328], edi
    app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */) = cpu.edi;
    // 0043acb9  891528d36f00           -mov dword ptr [0x6fd328], edx
    app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */) = cpu.edx;
    // 0043acbf  39d1                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043acc1  75d4                   -jne 0x43ac97
    if (!cpu.flags.zf)
    {
        goto L_0x0043ac97;
    }
L_0x0043acc3:
    // 0043acc3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043acc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043acc5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043acc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043acc7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043acc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_43ace0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0043ace0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043ace1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ace2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043ace3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043ace4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ace5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ace7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043ace9  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043acec  7e2d                   -jle 0x43ad1b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ad1b;
    }
    // 0043acee  bb62000000             -mov ebx, 0x62
    cpu.ebx = 98 /*0x62*/;
    // 0043acf3  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0043acf8  b80a505500             -mov eax, 0x55500a
    cpu.eax = 5591050 /*0x55500a*/;
    // 0043acfd  e83e590a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043ad02  bb6a000000             -mov ebx, 0x6a
    cpu.ebx = 106 /*0x6a*/;
    // 0043ad07  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0043ad0c  b89a515500             -mov eax, 0x55519a
    cpu.eax = 5591450 /*0x55519a*/;
    // 0043ad11  e82a590a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043ad16  e938010000             -jmp 0x43ae53
    goto L_0x0043ae53;
L_0x0043ad1b:
    // 0043ad1b  bb62000000             -mov ebx, 0x62
    cpu.ebx = 98 /*0x62*/;
    // 0043ad20  b80a505500             -mov eax, 0x55500a
    cpu.eax = 5591050 /*0x55500a*/;
    // 0043ad25  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043ad27  e814590a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043ad2c  bb6a000000             -mov ebx, 0x6a
    cpu.ebx = 106 /*0x6a*/;
    // 0043ad31  b89a515500             -mov eax, 0x55519a
    cpu.eax = 5591450 /*0x55519a*/;
    // 0043ad36  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043ad38  e803590a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043ad3d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043ad42  6689159a515500         -mov word ptr [0x55519a], dx
    app->getMemory<x86::reg16>(x86::reg32(5591450) /* 0x55519a */) = cpu.dx;
    // 0043ad49  6689144d9c515500       -mov word ptr [ecx*2 + 0x55519c], dx
    app->getMemory<x86::reg16>(x86::reg32(5591452) /* 0x55519c */ + cpu.ecx * 2) = cpu.dx;
    // 0043ad51  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043ad53:
    // 0043ad53  e878deffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043ad58  39c2                   +cmp edx, eax
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
    // 0043ad5a  7d23                   -jge 0x43ad7f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ad7f;
    }
    // 0043ad5c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043ad5e  e8cde9ffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043ad63  39c8                   +cmp eax, ecx
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
    // 0043ad65  7515                   -jne 0x43ad7c
    if (!cpu.flags.zf)
    {
        goto L_0x0043ad7c;
    }
    // 0043ad67  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0043ad6c  668934550a505500       -mov word ptr [edx*2 + 0x55500a], si
    app->getMemory<x86::reg16>(x86::reg32(5591050) /* 0x55500a */ + cpu.edx * 2) = cpu.si;
    // 0043ad74  66893455a2515500       -mov word ptr [edx*2 + 0x5551a2], si
    app->getMemory<x86::reg16>(x86::reg32(5591458) /* 0x5551a2 */ + cpu.edx * 2) = cpu.si;
L_0x0043ad7c:
    // 0043ad7c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043ad7d  ebd4                   -jmp 0x43ad53
    goto L_0x0043ad53;
L_0x0043ad7f:
    // 0043ad7f  a1bcd26f00             -mov eax, dword ptr [0x6fd2bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 0043ad84  e8a7e9ffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043ad89  39c8                   +cmp eax, ecx
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
    // 0043ad8b  7421                   -je 0x43adae
    if (cpu.flags.zf)
    {
        goto L_0x0043adae;
    }
    // 0043ad8d  ff05bcd26f00           -inc dword ptr [0x6fd2bc]
    (app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */))++;
    // 0043ad93  e838deffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043ad98  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ad9a  a1bcd26f00             -mov eax, dword ptr [0x6fd2bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 0043ad9f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043ada1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043ada4  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043ada6  8915bcd26f00           -mov dword ptr [0x6fd2bc], edx
    app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */) = cpu.edx;
    // 0043adac  ebd1                   -jmp 0x43ad7f
    goto L_0x0043ad7f;
L_0x0043adae:
    // 0043adae  a128d36f00             -mov eax, dword ptr [0x6fd328]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */);
    // 0043adb3  e878e9ffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043adb8  39c8                   +cmp eax, ecx
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
    // 0043adba  7421                   -je 0x43addd
    if (cpu.flags.zf)
    {
        goto L_0x0043addd;
    }
    // 0043adbc  ff0528d36f00           -inc dword ptr [0x6fd328]
    (app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */))++;
    // 0043adc2  e809deffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043adc7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043adc9  a128d36f00             -mov eax, dword ptr [0x6fd328]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */);
    // 0043adce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043add0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043add3  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043add5  891528d36f00           -mov dword ptr [0x6fd328], edx
    app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */) = cpu.edx;
    // 0043addb  ebd1                   -jmp 0x43adae
    goto L_0x0043adae;
L_0x0043addd:
    // 0043addd  a1d4d46f00             -mov eax, dword ptr [0x6fd4d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 0043ade2  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ade5  771e                   -ja 0x43ae05
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0043ae05;
    }
    // 0043ade7  ff2485ccac4300         -jmp dword ptr [eax*4 + 0x43accc]
    cpu.ip = app->getMemory<x86::reg32>(4435148 + cpu.eax * 4); goto dynamic_jump;
  case 0x0043adee:
    // 0043adee  a1d4d46f00             -mov eax, dword ptr [0x6fd4d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 0043adf3  48                     -dec eax
    (cpu.eax)--;
    // 0043adf4  39c1                   +cmp ecx, eax
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043adf6  745b                   -je 0x43ae53
    if (cpu.flags.zf)
    {
        goto L_0x0043ae53;
    }
    // 0043adf8  41                     -inc ecx
    (cpu.ecx)++;
    // 0043adf9  890dd4d46f00           -mov dword ptr [0x6fd4d4], ecx
    app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */) = cpu.ecx;
    // 0043adff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ae00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ae01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ae02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ae03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ae04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043ae05:
    // 0043ae05  a1d4d46f00             -mov eax, dword ptr [0x6fd4d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 0043ae0a  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043ae0d  e81ee9ffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043ae12  39c1                   +cmp ecx, eax
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ae14  743d                   -je 0x43ae53
    if (cpu.flags.zf)
    {
        goto L_0x0043ae53;
    }
    // 0043ae16  c705d4d46f0004000000   -mov dword ptr [0x6fd4d4], 4
    app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */) = 4 /*0x4*/;
L_0x0043ae20:
    // 0043ae20  a1d4d46f00             -mov eax, dword ptr [0x6fd4d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 0043ae25  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043ae28  e803e9ffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043ae2d  39c8                   +cmp eax, ecx
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
    // 0043ae2f  7422                   -je 0x43ae53
    if (cpu.flags.zf)
    {
        goto L_0x0043ae53;
    }
    // 0043ae31  ff05d4d46f00           -inc dword ptr [0x6fd4d4]
    (app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */))++;
    // 0043ae37  e894ddffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043ae3c  8d5804                 -lea ebx, [eax + 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0043ae3f  a1d4d46f00             -mov eax, dword ptr [0x6fd4d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 0043ae44  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043ae46  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043ae49  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043ae4b  8915d4d46f00           -mov dword ptr [0x6fd4d4], edx
    app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */) = cpu.edx;
    // 0043ae51  ebcd                   -jmp 0x43ae20
    goto L_0x0043ae20;
  case 0x0043ae53:
L_0x0043ae53:
    // 0043ae53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ae54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ae55  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ae56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ae57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ae58  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_43ae60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ae60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043ae61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ae62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043ae63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043ae64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ae65  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ae67  81ec04060000           -sub esp, 0x604
    (cpu.esp) -= x86::reg32(x86::sreg32(1540 /*0x604*/));
    // 0043ae6d  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043ae70  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043ae72  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 0043ae77  8dbdfcf9ffff           -lea edi, [ebp - 0x604]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1540) /* -0x604 */);
    // 0043ae7d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043ae7e:
    // 0043ae7e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043ae80  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043ae82  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043ae84  7410                   -je 0x43ae96
    if (cpu.flags.zf)
    {
        goto L_0x0043ae96;
    }
    // 0043ae86  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043ae89  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043ae8c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043ae8f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043ae92  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043ae94  75e8                   -jne 0x43ae7e
    if (!cpu.flags.zf)
    {
        goto L_0x0043ae7e;
    }
L_0x0043ae96:
    // 0043ae96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ae97  8d85fcf9ffff           -lea eax, [ebp - 0x604]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1540) /* -0x604 */);
    // 0043ae9d  8db5fcf9ffff           -lea esi, [ebp - 0x604]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-1540) /* -0x604 */);
    // 0043aea3  8dbd54fcffff           -lea edi, [ebp - 0x3ac]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-940) /* -0x3ac */);
    // 0043aea9  e892d4ffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 0043aeae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043aeaf:
    // 0043aeaf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043aeb1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043aeb3  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043aeb5  7410                   -je 0x43aec7
    if (cpu.flags.zf)
    {
        goto L_0x0043aec7;
    }
    // 0043aeb7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043aeba  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043aebd  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043aec0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043aec3  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043aec5  75e8                   -jne 0x43aeaf
    if (!cpu.flags.zf)
    {
        goto L_0x0043aeaf;
    }
L_0x0043aec7:
    // 0043aec7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043aec8  8dbd54fcffff           -lea edi, [ebp - 0x3ac]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-940) /* -0x3ac */);
    // 0043aece  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043aed0  49                     -dec ecx
    (cpu.ecx)--;
    // 0043aed1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043aed3  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043aed5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0043aed7  49                     -dec ecx
    (cpu.ecx)--;
    // 0043aed8  8d8554fcffff           -lea eax, [ebp - 0x3ac]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-940) /* -0x3ac */);
    // 0043aede  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0043aee1  8d85fcf9ffff           -lea eax, [ebp - 0x604]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1540) /* -0x604 */);
    // 0043aee7  e804d5ffff             -call 0x4383f0
    cpu.esp -= 4;
    sub_4383f0(app, cpu);
    if (cpu.terminate) return;
    // 0043aeec  8d8554fcffff           -lea eax, [ebp - 0x3ac]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-940) /* -0x3ac */);
    // 0043aef2  e8d9020b00             -call 0x4eb1d0
    cpu.esp -= 4;
    sub_4eb1d0(app, cpu);
    if (cpu.terminate) return;
    // 0043aef7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043aef9  0f8594030000           -jne 0x43b293
    if (!cpu.flags.zf)
    {
        goto L_0x0043b293;
    }
    // 0043aeff  8db5fcf9ffff           -lea esi, [ebp - 0x604]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-1540) /* -0x604 */);
    // 0043af05  8dbd28fbffff           -lea edi, [ebp - 0x4d8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1240) /* -0x4d8 */);
    // 0043af0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043af0c:
    // 0043af0c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043af0e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043af10  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043af12  7410                   -je 0x43af24
    if (cpu.flags.zf)
    {
        goto L_0x0043af24;
    }
    // 0043af14  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043af17  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043af1a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043af1d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043af20  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043af22  75e8                   -jne 0x43af0c
    if (!cpu.flags.zf)
    {
        goto L_0x0043af0c;
    }
L_0x0043af24:
    // 0043af24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043af25  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043af27  8dbd28fbffff           -lea edi, [ebp - 0x4d8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1240) /* -0x4d8 */);
    // 0043af2d  e87ee3ffff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 0043af32  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043af34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043af35  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043af37  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043af38  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043af3a  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043af3c  4f                     -dec edi
    (cpu.edi)--;
L_0x0043af3d:
    // 0043af3d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043af3f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043af41  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043af43  7410                   -je 0x43af55
    if (cpu.flags.zf)
    {
        goto L_0x0043af55;
    }
    // 0043af45  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043af48  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043af4b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043af4e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043af51  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043af53  75e8                   -jne 0x43af3d
    if (!cpu.flags.zf)
    {
        goto L_0x0043af3d;
    }
L_0x0043af55:
    // 0043af55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043af56  8db528fbffff           -lea esi, [ebp - 0x4d8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-1240) /* -0x4d8 */);
    // 0043af5c  8dbd80fdffff           -lea edi, [ebp - 0x280]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-640) /* -0x280 */);
    // 0043af62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043af63:
    // 0043af63  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043af65  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043af67  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043af69  7410                   -je 0x43af7b
    if (cpu.flags.zf)
    {
        goto L_0x0043af7b;
    }
    // 0043af6b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043af6e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043af71  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043af74  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043af77  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043af79  75e8                   -jne 0x43af63
    if (!cpu.flags.zf)
    {
        goto L_0x0043af63;
    }
L_0x0043af7b:
    // 0043af7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043af7c  8d8580fdffff           -lea eax, [ebp - 0x280]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-640) /* -0x280 */);
    // 0043af82  be04775300             -mov esi, 0x537704
    cpu.esi = 5469956 /*0x537704*/;
    // 0043af87  8dbd80fdffff           -lea edi, [ebp - 0x280]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-640) /* -0x280 */);
    // 0043af8d  e8aed3ffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 0043af92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043af93  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043af95  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043af96  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043af98  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043af9a  4f                     -dec edi
    (cpu.edi)--;
L_0x0043af9b:
    // 0043af9b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043af9d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043af9f  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043afa1  7410                   -je 0x43afb3
    if (cpu.flags.zf)
    {
        goto L_0x0043afb3;
    }
    // 0043afa3  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043afa6  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043afa9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043afac  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043afaf  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043afb1  75e8                   -jne 0x43af9b
    if (!cpu.flags.zf)
    {
        goto L_0x0043af9b;
    }
L_0x0043afb3:
    // 0043afb3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043afb4  8db554fcffff           -lea esi, [ebp - 0x3ac]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-940) /* -0x3ac */);
    // 0043afba  8dbdacfeffff           -lea edi, [ebp - 0x154]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043afc0  8d9580fdffff           -lea edx, [ebp - 0x280]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-640) /* -0x280 */);
    // 0043afc6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043afc7:
    // 0043afc7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043afc9  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043afcb  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043afcd  7410                   -je 0x43afdf
    if (cpu.flags.zf)
    {
        goto L_0x0043afdf;
    }
    // 0043afcf  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043afd2  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043afd5  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043afd8  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043afdb  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043afdd  75e8                   -jne 0x43afc7
    if (!cpu.flags.zf)
    {
        goto L_0x0043afc7;
    }
L_0x0043afdf:
    // 0043afdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043afe0  8d85acfeffff           -lea eax, [ebp - 0x154]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043afe6  be04775300             -mov esi, 0x537704
    cpu.esi = 5469956 /*0x537704*/;
    // 0043afeb  8dbdacfeffff           -lea edi, [ebp - 0x154]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043aff1  e84ad3ffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 0043aff6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043aff7  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043aff9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043affa  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043affc  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043affe  4f                     -dec edi
    (cpu.edi)--;
L_0x0043afff:
    // 0043afff  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b001  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b003  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b005  7410                   -je 0x43b017
    if (cpu.flags.zf)
    {
        goto L_0x0043b017;
    }
    // 0043b007  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b00a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b00d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b010  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b013  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b015  75e8                   -jne 0x43afff
    if (!cpu.flags.zf)
    {
        goto L_0x0043afff;
    }
L_0x0043b017:
    // 0043b017  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b018  8d85acfeffff           -lea eax, [ebp - 0x154]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b01e  8db554fcffff           -lea esi, [ebp - 0x3ac]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-940) /* -0x3ac */);
    // 0043b024  8dbdacfeffff           -lea edi, [ebp - 0x154]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b02a  e8d1790100             -call 0x452a00
    cpu.esp -= 4;
    sub_452a00(app, cpu);
    if (cpu.terminate) return;
    // 0043b02f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043b030:
    // 0043b030  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b032  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b034  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b036  7410                   -je 0x43b048
    if (cpu.flags.zf)
    {
        goto L_0x0043b048;
    }
    // 0043b038  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b03b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b03e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b041  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b044  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b046  75e8                   -jne 0x43b030
    if (!cpu.flags.zf)
    {
        goto L_0x0043b030;
    }
L_0x0043b048:
    // 0043b048  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b049  8d85acfeffff           -lea eax, [ebp - 0x154]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b04f  be04775300             -mov esi, 0x537704
    cpu.esi = 5469956 /*0x537704*/;
    // 0043b054  8dbdacfeffff           -lea edi, [ebp - 0x154]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b05a  e8e1d2ffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 0043b05f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b060  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043b062  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043b063  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043b065  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043b067  4f                     -dec edi
    (cpu.edi)--;
L_0x0043b068:
    // 0043b068  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b06a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b06c  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b06e  7410                   -je 0x43b080
    if (cpu.flags.zf)
    {
        goto L_0x0043b080;
    }
    // 0043b070  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b073  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b076  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b079  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b07c  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b07e  75e8                   -jne 0x43b068
    if (!cpu.flags.zf)
    {
        goto L_0x0043b068;
    }
L_0x0043b080:
    // 0043b080  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b081  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0043b086  8d85acfeffff           -lea eax, [ebp - 0x154]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b08c  e84f5f0a00             -call 0x4e0fe0
    cpu.esp -= 4;
    sub_4e0fe0(app, cpu);
    if (cpu.terminate) return;
    // 0043b091  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043b093  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b095  7408                   -je 0x43b09f
    if (cpu.flags.zf)
    {
        goto L_0x0043b09f;
    }
    // 0043b097  e854e5fdff             -call 0x4195f0
    cpu.esp -= 4;
    sub_4195f0(app, cpu);
    if (cpu.terminate) return;
    // 0043b09c  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x0043b09f:
    // 0043b09f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043b0a1  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043b0a4  e8e7670a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043b0a9  85d2                   -test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043b0ab  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0043b0ad  e9e0000000             -jmp 0x43b192
    goto L_0x0043b192;
L_0x0043b0b2:
    // 0043b0b2  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043b0b5  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b0b8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043b0ba  49                     -dec ecx
    (cpu.ecx)--;
    // 0043b0bb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043b0bd  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043b0bf  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0043b0c1  49                     -dec ecx
    (cpu.ecx)--;
    // 0043b0c2  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0043b0c5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043b0c7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043b0c9  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 0043b0ce  42                     -inc edx
    (cpu.edx)++;
    // 0043b0cf  e84c650a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0043b0d4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043b0d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b0d8  0f84ae000000           -je 0x43b18c
    if (cpu.flags.zf)
    {
        goto L_0x0043b18c;
    }
    // 0043b0de  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b0e1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0043b0e3  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0043b0e6  8b7024                 -mov esi, dword ptr [eax + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0043b0e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b0ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043b0ec  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0043b0ef  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043b0f1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0043b0f3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0043b0f6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0043b0f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b0f9  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043b0fc  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043b0fe  49                     -dec ecx
    (cpu.ecx)--;
    // 0043b0ff  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043b101  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043b103  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0043b105  49                     -dec ecx
    (cpu.ecx)--;
    // 0043b106  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b109  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043b10c  8b7820                 -mov edi, dword ptr [eax + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0043b10f  41                     -inc ecx
    (cpu.ecx)++;
    // 0043b110  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043b112  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b113  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043b115  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0043b118  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043b11a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0043b11c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0043b11f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0043b121  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b122  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b125  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0043b128  894237                 -mov dword ptr [edx + 0x37], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(55) /* 0x37 */) = cpu.eax;
    // 0043b12b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b12e  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0043b131  e85a670a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043b136  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b139  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043b13c  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0043b13f  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b142  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043b144  49                     -dec ecx
    (cpu.ecx)--;
    // 0043b145  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043b147  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043b149  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0043b14b  49                     -dec ecx
    (cpu.ecx)--;
    // 0043b14c  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0043b14f  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0043b152  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043b154  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0043b157  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043b158  895a20                 -mov dword ptr [edx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0043b15b  2eff1578445300         -call dword ptr cs:[0x534478]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457016) /* 0x534478 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0043b162  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b164  0f851e010000           -jne 0x43b288
    if (!cpu.flags.zf)
    {
        goto L_0x0043b288;
    }
    // 0043b16a  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0043b16c  eb05                   -jmp 0x43b173
    goto L_0x0043b173;
L_0x0043b16e:
    // 0043b16e  83fe04                 +cmp esi, 4
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043b171  7319                   -jae 0x43b18c
    if (!cpu.flags.cf)
    {
        goto L_0x0043b18c;
    }
L_0x0043b173:
    // 0043b173  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043b176  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0043b17d  8b5224                 -mov edx, dword ptr [edx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 0043b180  01c2                   +add edx, eax
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
    // 0043b182  8b4428d8               -mov eax, dword ptr [eax + ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-40) /* -0x28 */ + cpu.ebp * 1);
    // 0043b186  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043b187  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0043b18a  ebe2                   -jmp 0x43b16e
    goto L_0x0043b16e;
L_0x0043b18c:
    // 0043b18c  46                     -inc esi
    (cpu.esi)++;
    // 0043b18d  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043b190  7d38                   -jge 0x43b1ca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043b1ca;
    }
L_0x0043b192:
    // 0043b192  e8f9d00300             -call 0x478290
    cpu.esp -= 4;
    sub_478290(app, cpu);
    if (cpu.terminate) return;
    // 0043b197  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043b198  680c775300             -push 0x53770c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469964 /*0x53770c*/;
    cpu.esp -= 4;
    // 0043b19d  8d85acfeffff           -lea eax, [ebp - 0x154]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b1a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043b1a4  e8e7440a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043b1a9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043b1ac  8d95acfeffff           -lea edx, [ebp - 0x154]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b1b2  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043b1b5  e826defdff             -call 0x418fe0
    cpu.esp -= 4;
    sub_418fe0(app, cpu);
    if (cpu.terminate) return;
    // 0043b1ba  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043b1bd  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0043b1c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b1c2  0f85eafeffff           -jne 0x43b0b2
    if (!cpu.flags.zf)
    {
        goto L_0x0043b0b2;
    }
    // 0043b1c8  ebc2                   -jmp 0x43b18c
    goto L_0x0043b18c;
L_0x0043b1ca:
    // 0043b1ca  8db554fcffff           -lea esi, [ebp - 0x3ac]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-940) /* -0x3ac */);
    // 0043b1d0  8dbdacfeffff           -lea edi, [ebp - 0x154]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b1d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043b1d7:
    // 0043b1d7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b1d9  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b1db  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b1dd  7410                   -je 0x43b1ef
    if (cpu.flags.zf)
    {
        goto L_0x0043b1ef;
    }
    // 0043b1df  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b1e2  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b1e5  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b1e8  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b1eb  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b1ed  75e8                   -jne 0x43b1d7
    if (!cpu.flags.zf)
    {
        goto L_0x0043b1d7;
    }
L_0x0043b1ef:
    // 0043b1ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b1f0  8d85acfeffff           -lea eax, [ebp - 0x154]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b1f6  be04775300             -mov esi, 0x537704
    cpu.esi = 5469956 /*0x537704*/;
    // 0043b1fb  8dbdacfeffff           -lea edi, [ebp - 0x154]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b201  e83ad1ffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 0043b206  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b207  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043b209  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043b20a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043b20c  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043b20e  4f                     -dec edi
    (cpu.edi)--;
L_0x0043b20f:
    // 0043b20f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b211  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b213  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b215  7410                   -je 0x43b227
    if (cpu.flags.zf)
    {
        goto L_0x0043b227;
    }
    // 0043b217  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b21a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b21d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b220  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b223  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b225  75e8                   -jne 0x43b20f
    if (!cpu.flags.zf)
    {
        goto L_0x0043b20f;
    }
L_0x0043b227:
    // 0043b227  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b228  8d85acfeffff           -lea eax, [ebp - 0x154]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b22e  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043b231  e8aa300b00             -call 0x4ee2e0
    cpu.esp -= 4;
    sub_4ee2e0(app, cpu);
    if (cpu.terminate) return;
    // 0043b236  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043b239  e822e2fdff             -call 0x419460
    cpu.esp -= 4;
    sub_419460(app, cpu);
    if (cpu.terminate) return;
    // 0043b23e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043b240  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043b242  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b244  7417                   -je 0x43b25d
    if (cpu.flags.zf)
    {
        goto L_0x0043b25d;
    }
    // 0043b246  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043b249  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043b24b  7410                   -je 0x43b25d
    if (cpu.flags.zf)
    {
        goto L_0x0043b25d;
    }
    // 0043b24d  8d85acfeffff           -lea eax, [ebp - 0x154]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0043b253  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0043b255  e856390b00             -call 0x4eebb0
    cpu.esp -= 4;
    sub_4eebb0(app, cpu);
    if (cpu.terminate) return;
    // 0043b25a  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
L_0x0043b25d:
    // 0043b25d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043b25f  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043b262  e829660a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043b267  85ff                   -test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0043b269  e822ebffff             -call 0x439d90
    cpu.esp -= 4;
    sub_439d90(app, cpu);
    if (cpu.terminate) return;
    // 0043b26e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b270  7516                   -jne 0x43b288
    if (!cpu.flags.zf)
    {
        goto L_0x0043b288;
    }
    // 0043b272  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043b275  e8a6e8ffff             -call 0x439b20
    cpu.esp -= 4;
    sub_439b20(app, cpu);
    if (cpu.terminate) return;
    // 0043b27a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043b27c  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043b27f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043b281  e8cae7ffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043b286  eb0d                   -jmp 0x43b295
    goto L_0x0043b295;
L_0x0043b288:
    // 0043b288  8d8554fcffff           -lea eax, [ebp - 0x3ac]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-940) /* -0x3ac */);
    // 0043b28e  e83dd7ffff             -call 0x4389d0
    cpu.esp -= 4;
    sub_4389d0(app, cpu);
    if (cpu.terminate) return;
L_0x0043b293:
    // 0043b293  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043b295:
    // 0043b295  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043b297  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b298  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b299  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b29a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b29b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b29c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_43b2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b2a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043b2a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043b2a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043b2a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b2a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b2a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b2a7  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0043b2ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043b2af  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 0043b2b4  8dbdd4feffff           -lea edi, [ebp - 0x12c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 0043b2ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043b2bb:
    // 0043b2bb  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b2bd  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b2bf  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b2c1  7410                   -je 0x43b2d3
    if (cpu.flags.zf)
    {
        goto L_0x0043b2d3;
    }
    // 0043b2c3  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b2c6  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b2c9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b2cc  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b2cf  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b2d1  75e8                   -jne 0x43b2bb
    if (!cpu.flags.zf)
    {
        goto L_0x0043b2bb;
    }
L_0x0043b2d3:
    // 0043b2d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b2d4  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 0043b2da  8dbdd4feffff           -lea edi, [ebp - 0x12c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 0043b2e0  8db210010000           -lea esi, [edx + 0x110]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(272) /* 0x110 */);
    // 0043b2e6  e855d0ffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 0043b2eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b2ec  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043b2ee  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043b2ef  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043b2f1  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043b2f3  4f                     -dec edi
    (cpu.edi)--;
L_0x0043b2f4:
    // 0043b2f4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b2f6  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b2f8  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b2fa  7410                   -je 0x43b30c
    if (cpu.flags.zf)
    {
        goto L_0x0043b30c;
    }
    // 0043b2fc  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b2ff  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b302  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b305  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b308  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b30a  75e8                   -jne 0x43b2f4
    if (!cpu.flags.zf)
    {
        goto L_0x0043b2f4;
    }
L_0x0043b30c:
    // 0043b30c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b30d  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 0043b313  e8b8d6ffff             -call 0x4389d0
    cpu.esp -= 4;
    sub_4389d0(app, cpu);
    if (cpu.terminate) return;
    // 0043b318  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b31a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043b31c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b31d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b31e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b31f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b320  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b321  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_43b330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b330  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043b331  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043b332  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b333  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b335  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043b337  e804d8ffff             -call 0x438b40
    cpu.esp -= 4;
    sub_438b40(app, cpu);
    if (cpu.terminate) return;
    // 0043b33c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043b33e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043b340  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b342  7509                   -jne 0x43b34d
    if (!cpu.flags.zf)
    {
        goto L_0x0043b34d;
    }
    // 0043b344  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0043b349  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b34a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b34b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b34c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043b34d:
    // 0043b34d  e81ed8ffff             -call 0x438b70
    cpu.esp -= 4;
    sub_438b70(app, cpu);
    if (cpu.terminate) return;
    // 0043b352  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b354  7406                   -je 0x43b35c
    if (cpu.flags.zf)
    {
        goto L_0x0043b35c;
    }
    // 0043b356  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0043b358  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0043b35a  eb07                   -jmp 0x43b363
    goto L_0x0043b363;
L_0x0043b35c:
    // 0043b35c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0043b35e  a3704f5500             -mov dword ptr [0x554f70], eax
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.eax;
L_0x0043b363:
    // 0043b363  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043b365  7407                   -je 0x43b36e
    if (cpu.flags.zf)
    {
        goto L_0x0043b36e;
    }
    // 0043b367  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043b369  e832ffffff             -call 0x43b2a0
    cpu.esp -= 4;
    sub_43b2a0(app, cpu);
    if (cpu.terminate) return;
L_0x0043b36e:
    // 0043b36e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043b370  e83be8ffff             -call 0x439bb0
    cpu.esp -= 4;
    sub_439bb0(app, cpu);
    if (cpu.terminate) return;
    // 0043b375  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043b377  e814650a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043b37c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b37e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b37f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b380  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b381  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_43b390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b390  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043b391  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043b392  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b393  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b395  e856d7ffff             -call 0x438af0
    cpu.esp -= 4;
    sub_438af0(app, cpu);
    if (cpu.terminate) return;
L_0x0043b39a:
    // 0043b39a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043b39c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043b39e  743d                   -je 0x43b3dd
    if (cpu.flags.zf)
    {
        goto L_0x0043b3dd;
    }
    // 0043b3a0  f6828003000008         +test byte ptr [edx + 0x380], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(896) /* 0x380 */) & 8 /*0x8*/));
    // 0043b3a7  742d                   -je 0x43b3d6
    if (cpu.flags.zf)
    {
        goto L_0x0043b3d6;
    }
    // 0043b3a9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043b3ab  e8c0d7ffff             -call 0x438b70
    cpu.esp -= 4;
    sub_438b70(app, cpu);
    if (cpu.terminate) return;
    // 0043b3b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b3b2  7406                   -je 0x43b3ba
    if (cpu.flags.zf)
    {
        goto L_0x0043b3ba;
    }
    // 0043b3b4  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0043b3b6  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0043b3b8  eb07                   -jmp 0x43b3c1
    goto L_0x0043b3c1;
L_0x0043b3ba:
    // 0043b3ba  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0043b3bc  a3704f5500             -mov dword ptr [0x554f70], eax
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.eax;
L_0x0043b3c1:
    // 0043b3c1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043b3c3  e8e8e7ffff             -call 0x439bb0
    cpu.esp -= 4;
    sub_439bb0(app, cpu);
    if (cpu.terminate) return;
    // 0043b3c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043b3ca  e8c1640a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043b3cf  e81cd7ffff             -call 0x438af0
    cpu.esp -= 4;
    sub_438af0(app, cpu);
    if (cpu.terminate) return;
    // 0043b3d4  ebc4                   -jmp 0x43b39a
    goto L_0x0043b39a;
L_0x0043b3d6:
    // 0043b3d6  e835d7ffff             -call 0x438b10
    cpu.esp -= 4;
    sub_438b10(app, cpu);
    if (cpu.terminate) return;
    // 0043b3db  ebbd                   -jmp 0x43b39a
    goto L_0x0043b39a;
L_0x0043b3dd:
    // 0043b3dd  e80e090000             -call 0x43bcf0
    cpu.esp -= 4;
    sub_43bcf0(app, cpu);
    if (cpu.terminate) return;
    // 0043b3e2  e8a9e9ffff             -call 0x439d90
    cpu.esp -= 4;
    sub_439d90(app, cpu);
    if (cpu.terminate) return;
    // 0043b3e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b3e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b3ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b3eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b3ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_43b3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b3f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043b3f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043b3f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043b3f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043b3f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b3f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b3f6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b3f8  81ec34010000           -sub esp, 0x134
    (cpu.esp) -= x86::reg32(x86::sreg32(308 /*0x134*/));
    // 0043b3fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043b400  e84be6ffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043b405  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 0043b40a  8dbdccfeffff           -lea edi, [ebp - 0x134]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043b410  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043b413  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043b414:
    // 0043b414  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b416  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b418  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b41a  7410                   -je 0x43b42c
    if (cpu.flags.zf)
    {
        goto L_0x0043b42c;
    }
    // 0043b41c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b41f  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b422  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b425  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b428  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b42a  75e8                   -jne 0x43b414
    if (!cpu.flags.zf)
    {
        goto L_0x0043b414;
    }
L_0x0043b42c:
    // 0043b42c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b42d  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043b433  e808cfffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 0043b438  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043b43a  8dbdccfeffff           -lea edi, [ebp - 0x134]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043b440  e86bdeffff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 0043b445  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043b447  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b448  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043b44a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043b44b  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043b44d  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043b44f  4f                     -dec edi
    (cpu.edi)--;
L_0x0043b450:
    // 0043b450  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b452  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b454  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b456  7410                   -je 0x43b468
    if (cpu.flags.zf)
    {
        goto L_0x0043b468;
    }
    // 0043b458  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b45b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b45e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b461  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b464  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b466  75e8                   -jne 0x43b450
    if (!cpu.flags.zf)
    {
        goto L_0x0043b450;
    }
L_0x0043b468:
    // 0043b468  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b469  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043b46f  e8ccceffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 0043b474  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043b476  8dbdccfeffff           -lea edi, [ebp - 0x134]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043b47c  e87fdeffff             -call 0x439300
    cpu.esp -= 4;
    sub_439300(app, cpu);
    if (cpu.terminate) return;
    // 0043b481  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043b483  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0043b488  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b489  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043b48b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043b48c  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043b48e  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043b490  4f                     -dec edi
    (cpu.edi)--;
L_0x0043b491:
    // 0043b491  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b493  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b495  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b497  7410                   -je 0x43b4a9
    if (cpu.flags.zf)
    {
        goto L_0x0043b4a9;
    }
    // 0043b499  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b49c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b49f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b4a2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b4a5  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b4a7  75e8                   -jne 0x43b491
    if (!cpu.flags.zf)
    {
        goto L_0x0043b491;
    }
L_0x0043b4a9:
    // 0043b4a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b4aa  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b4ad  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b4b0  0594030000             -add eax, 0x394
    (cpu.eax) += x86::reg32(x86::sreg32(916 /*0x394*/));
    // 0043b4b5  8d4df8                 -lea ecx, [ebp - 8]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043b4b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043b4b9  81c238030000           -add edx, 0x338
    (cpu.edx) += x86::reg32(x86::sreg32(824 /*0x338*/));
    // 0043b4bf  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043b4c5  e836120600             -call 0x49c700
    cpu.esp -= 4;
    sub_49c700(app, cpu);
    if (cpu.terminate) return;
    // 0043b4ca  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b4cd  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043b4d0  898234030000           -mov dword ptr [edx + 0x334], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(820) /* 0x334 */) = cpu.eax;
    // 0043b4d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b4d8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043b4da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b4db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b4dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b4dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b4de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b4df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b4e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_43b4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b4f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043b4f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043b4f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043b4f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b4f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b4f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b4f7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043b4fa  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0043b4fc  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0043b503  ba64765300             -mov edx, 0x537664
    cpu.edx = 5469796 /*0x537664*/;
    // 0043b508  e8db2a0b00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 0043b50d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043b50f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b511  7507                   -jne 0x43b51a
    if (!cpu.flags.zf)
    {
        goto L_0x0043b51a;
    }
    // 0043b513  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043b518  eb4b                   -jmp 0x43b565
    goto L_0x0043b565;
L_0x0043b51a:
    // 0043b51a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043b51f  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0043b524  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043b526  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b529  e8a2360b00             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
    // 0043b52e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043b533  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0043b538  8d872c030000           -lea eax, [edi + 0x32c]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(812) /* 0x32c */);
    // 0043b53e  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0043b540  e88b360b00             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
    // 0043b545  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043b54a  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0043b54f  8d8778030000           -lea eax, [edi + 0x378]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(888) /* 0x378 */);
    // 0043b555  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0043b557  e874360b00             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
    // 0043b55c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043b55e  e89d2b0b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 0043b563  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043b565:
    // 0043b565  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043b567  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043b569  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b56a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b56b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b56c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b56d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b56e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43b570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043b571  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043b572  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043b573  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b574  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b575  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b577  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0043b57a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043b57c  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0043b57f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043b581  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043b583  e800db0a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0043b588  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0043b58a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043b58f  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0043b594  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043b597  e864dc0a00             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0043b59c  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043b59f  7407                   -je 0x43b5a8
    if (cpu.flags.zf)
    {
        goto L_0x0043b5a8;
    }
    // 0043b5a1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043b5a6  eb78                   -jmp 0x43b620
    goto L_0x0043b620;
L_0x0043b5a8:
    // 0043b5a8  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0043b5ad  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0043b5af  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043b5b1  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043b5b4  e847dc0a00             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0043b5b9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043b5be  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0043b5c3  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043b5c6  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0043b5c8  e833dc0a00             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0043b5cd  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b5d0  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043b5d3  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0043b5d8  89822c030000           -mov dword ptr [edx + 0x32c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(812) /* 0x32c */) = cpu.eax;
    // 0043b5de  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043b5e1  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043b5e4  8dba78030000           -lea edi, [edx + 0x378]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(888) /* 0x378 */);
    // 0043b5ea  898230030000           -mov dword ptr [edx + 0x330], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(816) /* 0x330 */) = cpu.eax;
    // 0043b5f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b5f1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043b5f3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0043b5f6  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043b5f8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0043b5fa  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0043b5fd  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0043b5ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b600  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0043b605  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043b608  8dba7c030000           -lea edi, [edx + 0x37c]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(892) /* 0x37c */);
    // 0043b60e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b60f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043b611  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0043b614  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043b616  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0043b618  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0043b61b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0043b61d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b61e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043b620:
    // 0043b620  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043b622  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b623  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b624  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b625  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b626  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b627  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_43b630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b630  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043b631  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043b632  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043b633  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b634  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b635  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b637  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043b63a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043b63c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0043b63e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043b640  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043b642  e841da0a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0043b647  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0043b649  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043b64e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0043b653  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b656  e8a5db0a00             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0043b65b  837dfc01               +cmp dword ptr [ebp - 4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043b65f  750d                   -jne 0x43b66e
    if (!cpu.flags.zf)
    {
        goto L_0x0043b66e;
    }
    // 0043b661  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043b663  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043b665  e806ffffff             -call 0x43b570
    cpu.esp -= 4;
    sub_43b570(app, cpu);
    if (cpu.terminate) return;
    // 0043b66a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b66c  7405                   -je 0x43b673
    if (cpu.flags.zf)
    {
        goto L_0x0043b673;
    }
L_0x0043b66e:
    // 0043b66e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0043b673:
    // 0043b673  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043b675  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b676  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b677  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b678  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b679  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b67a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_43b680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b680  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043b681  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043b682  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043b683  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b684  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b685  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b687  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043b689  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 0043b68e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0043b690  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043b691:
    // 0043b691  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b693  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b695  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b697  7410                   -je 0x43b6a9
    if (cpu.flags.zf)
    {
        goto L_0x0043b6a9;
    }
    // 0043b699  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b69c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b69f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b6a2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b6a5  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b6a7  75e8                   -jne 0x43b691
    if (!cpu.flags.zf)
    {
        goto L_0x0043b691;
    }
L_0x0043b6a9:
    // 0043b6a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b6aa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043b6ac  e88fccffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 0043b6b1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043b6b3  e8f8dbffff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 0043b6b8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043b6ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b6bb  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043b6bd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043b6be  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043b6c0  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043b6c2  4f                     -dec edi
    (cpu.edi)--;
L_0x0043b6c3:
    // 0043b6c3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b6c5  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b6c7  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b6c9  7410                   -je 0x43b6db
    if (cpu.flags.zf)
    {
        goto L_0x0043b6db;
    }
    // 0043b6cb  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b6ce  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b6d1  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b6d4  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b6d7  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b6d9  75e8                   -jne 0x43b6c3
    if (!cpu.flags.zf)
    {
        goto L_0x0043b6c3;
    }
L_0x0043b6db:
    // 0043b6db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b6dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043b6de  e85dccffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 0043b6e3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043b6e5  e816dcffff             -call 0x439300
    cpu.esp -= 4;
    sub_439300(app, cpu);
    if (cpu.terminate) return;
    // 0043b6ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043b6ec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b6ed  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043b6ef  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043b6f0  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043b6f2  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043b6f4  4f                     -dec edi
    (cpu.edi)--;
L_0x0043b6f5:
    // 0043b6f5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b6f7  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b6f9  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b6fb  7410                   -je 0x43b70d
    if (cpu.flags.zf)
    {
        goto L_0x0043b70d;
    }
    // 0043b6fd  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b700  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b703  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b706  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b709  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b70b  75e8                   -jne 0x43b6f5
    if (!cpu.flags.zf)
    {
        goto L_0x0043b6f5;
    }
L_0x0043b70d:
    // 0043b70d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b70e  be18775300             -mov esi, 0x537718
    cpu.esi = 5469976 /*0x537718*/;
    // 0043b713  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b714  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043b716  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043b717  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043b719  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043b71b  4f                     -dec edi
    (cpu.edi)--;
L_0x0043b71c:
    // 0043b71c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043b71e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043b720  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b722  7410                   -je 0x43b734
    if (cpu.flags.zf)
    {
        goto L_0x0043b734;
    }
    // 0043b724  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043b727  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b72a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043b72d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043b730  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043b732  75e8                   -jne 0x43b71c
    if (!cpu.flags.zf)
    {
        goto L_0x0043b71c;
    }
L_0x0043b734:
    // 0043b734  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b735  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b736  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b737  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b738  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b739  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b73a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_43b740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b740  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043b741  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043b742  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043b743  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043b744  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b745  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b746  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b748  81ec30010000           -sub esp, 0x130
    (cpu.esp) -= x86::reg32(x86::sreg32(304 /*0x130*/));
    // 0043b74e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043b750  e8fbe2ffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043b755  8d95d0feffff           -lea edx, [ebp - 0x130]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-304) /* -0x130 */);
    // 0043b75b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043b75d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043b75f  e81cffffff             -call 0x43b680
    cpu.esp -= 4;
    sub_43b680(app, cpu);
    if (cpu.terminate) return;
    // 0043b764  bae4765300             -mov edx, 0x5376e4
    cpu.edx = 5469924 /*0x5376e4*/;
    // 0043b769  8d85d0feffff           -lea eax, [ebp - 0x130]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-304) /* -0x130 */);
    // 0043b76f  e874280b00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 0043b774  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043b776  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b778  745e                   -je 0x43b7d8
    if (cpu.flags.zf)
    {
        goto L_0x0043b7d8;
    }
    // 0043b77a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043b77f  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0043b784  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043b786  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b789  e872da0a00             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0043b78e  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b791  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043b793  83fa01                 +cmp edx, 1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043b796  7405                   -je 0x43b79d
    if (cpu.flags.zf)
    {
        goto L_0x0043b79d;
    }
    // 0043b798  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0043b79d:
    // 0043b79d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043b79f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043b7a1  e88afeffff             -call 0x43b630
    cpu.esp -= 4;
    sub_43b630(app, cpu);
    if (cpu.terminate) return;
    // 0043b7a6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043b7a8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043b7aa  e851290b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 0043b7af  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043b7b1  7407                   -je 0x43b7ba
    if (cpu.flags.zf)
    {
        goto L_0x0043b7ba;
    }
    // 0043b7b3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0043b7b8  eb1e                   -jmp 0x43b7d8
    goto L_0x0043b7d8;
L_0x0043b7ba:
    // 0043b7ba  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043b7bc  7418                   -je 0x43b7d6
    if (cpu.flags.zf)
    {
        goto L_0x0043b7d6;
    }
    // 0043b7be  8d85d0feffff           -lea eax, [ebp - 0x130]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-304) /* -0x130 */);
    // 0043b7c4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043b7c6  e825fdffff             -call 0x43b4f0
    cpu.esp -= 4;
    sub_43b4f0(app, cpu);
    if (cpu.terminate) return;
    // 0043b7cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b7cd  7407                   -je 0x43b7d6
    if (cpu.flags.zf)
    {
        goto L_0x0043b7d6;
    }
    // 0043b7cf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0043b7d4  eb02                   -jmp 0x43b7d8
    goto L_0x0043b7d8;
L_0x0043b7d6:
    // 0043b7d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043b7d8:
    // 0043b7d8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043b7da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b7db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b7dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b7dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b7de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b7df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b7e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_43b7f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b7f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043b7f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043b7f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043b7f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b7f4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b7f6  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0043b7fc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043b7fe  e84de2ffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043b803  8d95d4feffff           -lea edx, [ebp - 0x12c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 0043b809  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043b80b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043b80d  e86efeffff             -call 0x43b680
    cpu.esp -= 4;
    sub_43b680(app, cpu);
    if (cpu.terminate) return;
    // 0043b812  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 0043b818  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043b81a  e8d1fcffff             -call 0x43b4f0
    cpu.esp -= 4;
    sub_43b4f0(app, cpu);
    if (cpu.terminate) return;
    // 0043b81f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b821  7405                   -je 0x43b828
    if (cpu.flags.zf)
    {
        goto L_0x0043b828;
    }
    // 0043b823  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0043b828:
    // 0043b828  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043b82a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b82b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b82c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b82d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b82e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43b830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043b831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043b832  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043b833  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b834  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b835  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b837  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043b83a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0043b83c  bae4765300             -mov edx, 0x5376e4
    cpu.edx = 5469924 /*0x5376e4*/;
    // 0043b841  e8a2270b00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 0043b846  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0043b848  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b84a  0f844a010000           -je 0x43b99a
    if (cpu.flags.zf)
    {
        goto L_0x0043b99a;
    }
    // 0043b850  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0043b855  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043b857  e82cd80a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0043b85c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043b861  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0043b866  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b869  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0043b86b  e890d90a00             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0043b870  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b873  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b876  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043b87b  81e200ff0000           -and edx, 0xff00
    cpu.edx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0043b881  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0043b884  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0043b887  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b889  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b88c  250000ff00             -and eax, 0xff0000
    cpu.eax &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 0043b891  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0043b894  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b896  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b899  25000000ff             -and eax, 0xff000000
    cpu.eax &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0043b89e  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0043b8a1  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0043b8a6  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b8a8  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 0043b8ad  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0043b8b0  83c230                 -add edx, 0x30
    (cpu.edx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0043b8b3  e8685d0a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0043b8b8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043b8ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b8bc  7510                   -jne 0x43b8ce
    if (!cpu.flags.zf)
    {
        goto L_0x0043b8ce;
    }
    // 0043b8be  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0043b8c0  e83b280b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 0043b8c5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043b8c7  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 0043b8c9  e9cc000000             -jmp 0x43b99a
    goto L_0x0043b99a;
L_0x0043b8ce:
    // 0043b8ce  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b8d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043b8d3  83c330                 -add ebx, 0x30
    (cpu.ebx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0043b8d6  e8654d0a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043b8db  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0043b8dd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043b8df  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043b8e1  e8a2d70a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0043b8e6  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043b8e9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043b8ee  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043b8f0  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0043b8f2  83c230                 -add edx, 0x30
    (cpu.edx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0043b8f5  e806d90a00             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0043b8fa  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0043b8fc  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0043b8fe  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043b904  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0043b909  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0043b90c  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0043b90f  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b911  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0043b913  250000ff00             -and eax, 0xff0000
    cpu.eax &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 0043b918  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0043b91b  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0043b91d  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0043b91f  81e2000000ff           -and edx, 0xff000000
    cpu.edx &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0043b925  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 0043b928  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0043b92a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0043b92c  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043b92f  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043b932  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043b938  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0043b93d  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0043b940  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0043b943  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b945  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043b948  250000ff00             -and eax, 0xff0000
    cpu.eax &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 0043b94d  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0043b950  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b952  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043b955  25000000ff             -and eax, 0xff000000
    cpu.eax &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0043b95a  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0043b95d  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b95f  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0043b962  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0043b965  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0043b968  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043b96d  81e200ff0000           -and edx, 0xff00
    cpu.edx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0043b973  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0043b976  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0043b979  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b97b  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0043b97e  250000ff00             -and eax, 0xff0000
    cpu.eax &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 0043b983  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0043b986  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b988  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0043b98b  25000000ff             -and eax, 0xff000000
    cpu.eax &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0043b990  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0043b993  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043b995  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043b997  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x0043b99a:
    // 0043b99a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043b99c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b99d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b99e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b99f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b9a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b9a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_43b9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b9b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b9b1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b9b3  e8d85e0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043b9b8  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0043b9ba  e841270b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 0043b9bf  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0043b9c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043b9c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_43b9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043b9d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043b9d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043b9d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043b9d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043b9d5  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0043b9d8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043b9da  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0043b9dc  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0043b9df  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
    // 0043b9e4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043b9e6  e805290b00             -call 0x4ee2f0
    cpu.esp -= 4;
    sub_4ee2f0(app, cpu);
    if (cpu.terminate) return;
    // 0043b9eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043b9ed  7405                   -je 0x43b9f4
    if (cpu.flags.zf)
    {
        goto L_0x0043b9f4;
    }
    // 0043b9ef  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0043b9f2  eb02                   -jmp 0x43b9f6
    goto L_0x0043b9f6;
L_0x0043b9f4:
    // 0043b9f4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0043b9f6:
    // 0043b9f6  bb1d000000             -mov ebx, 0x1d
    cpu.ebx = 29 /*0x1d*/;
    // 0043b9fb  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0043b9fe  e82d540a00             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0043ba03  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043ba06  8d55dc                 -lea edx, [ebp - 0x24]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0043ba09  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043ba0b  e8e0bf0200             -call 0x4679f0
    cpu.esp -= 4;
    sub_4679f0(app, cpu);
    if (cpu.terminate) return;
    // 0043ba10  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043ba12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_43ba20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ba20  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ba21  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ba23  b8342c7a00             -mov eax, 0x7a2c34
    cpu.eax = 8006708 /*0x7a2c34*/;
    // 0043ba28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_43ba30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ba30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043ba31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ba32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043ba33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043ba34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ba35  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ba37  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043ba3a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043ba3c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043ba3e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043ba40  eb05                   -jmp 0x43ba47
    goto L_0x0043ba47;
L_0x0043ba42:
    // 0043ba42  83f804                 +cmp eax, 4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ba45  7d13                   -jge 0x43ba5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ba5a;
    }
L_0x0043ba47:
    // 0043ba47  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 0043ba4c  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0043ba4f  29c6                   +sub esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043ba51  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0043ba53  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043ba54  885c2efc               -mov byte ptr [esi + ebp - 4], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ebp * 1) = cpu.bl;
    // 0043ba58  ebe8                   -jmp 0x43ba42
    goto L_0x0043ba42;
L_0x0043ba5a:
    // 0043ba5a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043ba5d  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0043ba5f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043ba61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_43ba70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ba70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043ba71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ba72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ba73  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ba75  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043ba78  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043ba7a  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0043ba7d  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043ba80  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043ba85  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0043ba8a  e8a1ffffff             -call 0x43ba30
    cpu.esp -= 4;
    sub_43ba30(app, cpu);
    if (cpu.terminate) return;
    // 0043ba8f  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043ba92  e839310b00             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
    // 0043ba97  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043ba99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ba9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_43baa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043baa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043baa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043baa2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043baa3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043baa4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043baa5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043baa6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043baa8  81ec0c030000           -sub esp, 0x30c
    (cpu.esp) -= x86::reg32(x86::sreg32(780 /*0x30c*/));
    // 0043baae  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043bab0  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0043bab6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043bab8  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
    // 0043babd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043babe:
    // 0043babe  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043bac0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043bac2  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043bac4  7410                   -je 0x43bad6
    if (cpu.flags.zf)
    {
        goto L_0x0043bad6;
    }
    // 0043bac6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043bac9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043bacc  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043bacf  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043bad2  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043bad4  75e8                   -jne 0x43babe
    if (!cpu.flags.zf)
    {
        goto L_0x0043babe;
    }
L_0x0043bad6:
    // 0043bad6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bad7  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0043badd  be38775300             -mov esi, 0x537738
    cpu.esi = 5470008 /*0x537738*/;
    // 0043bae2  e809280b00             -call 0x4ee2f0
    cpu.esp -= 4;
    sub_4ee2f0(app, cpu);
    if (cpu.terminate) return;
    // 0043bae7  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0043baea  ba44775300             -mov edx, 0x537744
    cpu.edx = 5470020 /*0x537744*/;
    // 0043baef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043baf0:
    // 0043baf0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043baf2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043baf4  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043baf6  7410                   -je 0x43bb08
    if (cpu.flags.zf)
    {
        goto L_0x0043bb08;
    }
    // 0043baf8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043bafb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043bafe  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043bb01  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043bb04  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043bb06  75e8                   -jne 0x43baf0
    if (!cpu.flags.zf)
    {
        goto L_0x0043baf0;
    }
L_0x0043bb08:
    // 0043bb08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bb09  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043bb0b  e8d8240b00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 0043bb10  bae4765300             -mov edx, 0x5376e4
    cpu.edx = 5469924 /*0x5376e4*/;
    // 0043bb15  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043bb17  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043bb19  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0043bb1f  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0043bb24  e8bf240b00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 0043bb29  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043bb2b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043bb2e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043bb30  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043bb32  e851d50a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0043bb37  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043bb39  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0043bb3e  e8dd280b00             -call 0x4ee420
    cpu.esp -= 4;
    sub_4ee420(app, cpu);
    if (cpu.terminate) return;
    // 0043bb43  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043bb45  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043bb48  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043bb4a  e839d50a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0043bb4f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043bb51  e8ca280b00             -call 0x4ee420
    cpu.esp -= 4;
    sub_4ee420(app, cpu);
    if (cpu.terminate) return;
    // 0043bb56  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043bb58  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043bb5a  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0043bb5d  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043bb5f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043bb61  e822d50a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
L_0x0043bb66:
    // 0043bb66  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043bb69  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 0043bb6e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043bb73  8d85f4fcffff           -lea eax, [ebp - 0x30c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-780) /* -0x30c */);
    // 0043bb79  e882d60a00             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0043bb7e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043bb80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043bb82  741c                   -je 0x43bba0
    if (cpu.flags.zf)
    {
        goto L_0x0043bba0;
    }
    // 0043bb84  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043bb89  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0043bb8b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043bb8d  8d85f4fcffff           -lea eax, [ebp - 0x30c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-780) /* -0x30c */);
    // 0043bb93  e838300b00             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
    // 0043bb98  81ff00020000           +cmp edi, 0x200
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043bb9e  74c6                   -je 0x43bb66
    if (cpu.flags.zf)
    {
        goto L_0x0043bb66;
    }
L_0x0043bba0:
    // 0043bba0  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043bba3  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0043bba8  e853250b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 0043bbad  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043bbaf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043bbb1  e8d2d40a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0043bbb6  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043bbb9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043bbbb  e8b0feffff             -call 0x43ba70
    cpu.esp -= 4;
    sub_43ba70(app, cpu);
    if (cpu.terminate) return;
    // 0043bbc0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043bbc2  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0043bbc7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043bbc9  e8bad40a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0043bbce  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043bbd1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043bbd3  e898feffff             -call 0x43ba70
    cpu.esp -= 4;
    sub_43ba70(app, cpu);
    if (cpu.terminate) return;
    // 0043bbd8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043bbda  e821250b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 0043bbdf  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043bbe1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bbe2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bbe3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bbe4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bbe5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bbe6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bbe7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_43bbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043bbf0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043bbf1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043bbf3  a1744f5500             -mov eax, dword ptr [0x554f74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590900) /* 0x554f74 */);
    // 0043bbf8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bbf9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_43bc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043bc00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043bc01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043bc02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043bc03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043bc04  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043bc06  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043bc08  e8e3ffffff             -call 0x43bbf0
    cpu.esp -= 4;
    sub_43bbf0(app, cpu);
    if (cpu.terminate) return;
    // 0043bc0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043bc0f  741b                   -je 0x43bc2c
    if (cpu.flags.zf)
    {
        goto L_0x0043bc2c;
    }
    // 0043bc11  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0043bc16  8db81c030000           -lea edi, [eax + 0x31c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(796) /* 0x31c */);
    // 0043bc1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043bc1d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043bc1f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0043bc22  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043bc24  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0043bc26  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0043bc29  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0043bc2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0043bc2c:
    // 0043bc2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bc2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bc2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bc2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bc30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_43bc40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043bc40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043bc41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043bc42  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043bc44  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043bc46  e8a5ffffff             -call 0x43bbf0
    cpu.esp -= 4;
    sub_43bbf0(app, cpu);
    if (cpu.terminate) return;
    // 0043bc4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043bc4d  7412                   -je 0x43bc61
    if (cpu.flags.zf)
    {
        goto L_0x0043bc61;
    }
    // 0043bc4f  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0043bc54  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043bc55  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043bc58  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043bc59  e8323a0a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043bc5e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0043bc61:
    // 0043bc61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bc62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bc63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_43bc70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043bc70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043bc71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043bc72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043bc74  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043bc76  e875ffffff             -call 0x43bbf0
    cpu.esp -= 4;
    sub_43bbf0(app, cpu);
    if (cpu.terminate) return;
    // 0043bc7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043bc7d  7406                   -je 0x43bc85
    if (cpu.flags.zf)
    {
        goto L_0x0043bc85;
    }
    // 0043bc7f  899080030000           -mov dword ptr [eax + 0x380], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */) = cpu.edx;
L_0x0043bc85:
    // 0043bc85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bc86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bc87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_43bc90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043bc90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043bc91  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043bc93  e858ffffff             -call 0x43bbf0
    cpu.esp -= 4;
    sub_43bbf0(app, cpu);
    if (cpu.terminate) return;
    // 0043bc98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043bc9a  7407                   -je 0x43bca3
    if (cpu.flags.zf)
    {
        goto L_0x0043bca3;
    }
    // 0043bc9c  80888003000008         -or byte ptr [eax + 0x380], 8
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0043bca3:
    // 0043bca3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bca4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_43bcb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043bcb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043bcb1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043bcb3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043bcb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bcb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_43bcc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043bcc0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043bcc1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043bcc3  e888ddffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043bcc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043bcca  7507                   -jne 0x43bcd3
    if (!cpu.flags.zf)
    {
        goto L_0x0043bcd3;
    }
    // 0043bccc  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 0043bcd1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bcd2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043bcd3:
    // 0043bcd3  668b808c030000         -mov ax, word ptr [eax + 0x38c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(908) /* 0x38c */);
    // 0043bcda  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0043bcdf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bce0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_43bcf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043bcf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043bcf1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043bcf2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043bcf3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043bcf4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043bcf5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043bcf7  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0043bcfd  b8b4287a00             -mov eax, 0x7a28b4
    cpu.eax = 8005812 /*0x7a28b4*/;
    // 0043bd02  e8a9c9ffff             -call 0x4386b0
    cpu.esp -= 4;
    sub_4386b0(app, cpu);
    if (cpu.terminate) return;
L_0x0043bd07:
    // 0043bd07  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043bd09  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043bd0b  0f84b9000000           -je 0x43bdca
    if (cpu.flags.zf)
    {
        goto L_0x0043bdca;
    }
    // 0043bd11  803a50                 +cmp byte ptr [edx], 0x50
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043bd14  0f85a6000000           -jne 0x43bdc0
    if (!cpu.flags.zf)
    {
        goto L_0x0043bdc0;
    }
    // 0043bd1a  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0043bd1d  fec0                   -inc al
    (cpu.al)++;
    // 0043bd1f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043bd24  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0043bd2b  0f848f000000           -je 0x43bdc0
    if (cpu.flags.zf)
    {
        goto L_0x0043bdc0;
    }
    // 0043bd31  8a4202                 -mov al, byte ptr [edx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0043bd34  fec0                   -inc al
    (cpu.al)++;
    // 0043bd36  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043bd3b  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0043bd42  0f8478000000           -je 0x43bdc0
    if (cpu.flags.zf)
    {
        goto L_0x0043bdc0;
    }
    // 0043bd48  8a4203                 -mov al, byte ptr [edx + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0043bd4b  fec0                   -inc al
    (cpu.al)++;
    // 0043bd4d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043bd52  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0043bd59  7465                   -je 0x43bdc0
    if (cpu.flags.zf)
    {
        goto L_0x0043bdc0;
    }
    // 0043bd5b  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 0043bd60  8dbdd4feffff           -lea edi, [ebp - 0x12c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 0043bd66  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043bd67:
    // 0043bd67  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043bd69  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043bd6b  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043bd6d  7410                   -je 0x43bd7f
    if (cpu.flags.zf)
    {
        goto L_0x0043bd7f;
    }
    // 0043bd6f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043bd72  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043bd75  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043bd78  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043bd7b  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043bd7d  75e8                   -jne 0x43bd67
    if (!cpu.flags.zf)
    {
        goto L_0x0043bd67;
    }
L_0x0043bd7f:
    // 0043bd7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bd80  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 0043bd86  8dbdd4feffff           -lea edi, [ebp - 0x12c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 0043bd8c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0043bd8e  e8adc5ffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 0043bd93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043bd94  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043bd96  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043bd97  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043bd99  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0043bd9b  4f                     -dec edi
    (cpu.edi)--;
L_0x0043bd9c:
    // 0043bd9c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043bd9e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043bda0  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043bda2  7410                   -je 0x43bdb4
    if (cpu.flags.zf)
    {
        goto L_0x0043bdb4;
    }
    // 0043bda4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043bda7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043bdaa  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043bdad  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043bdb0  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043bdb2  75e8                   -jne 0x43bd9c
    if (!cpu.flags.zf)
    {
        goto L_0x0043bd9c;
    }
L_0x0043bdb4:
    // 0043bdb4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bdb5  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 0043bdbb  e810ccffff             -call 0x4389d0
    cpu.esp -= 4;
    sub_4389d0(app, cpu);
    if (cpu.terminate) return;
L_0x0043bdc0:
    // 0043bdc0  e81bcaffff             -call 0x4387e0
    cpu.esp -= 4;
    sub_4387e0(app, cpu);
    if (cpu.terminate) return;
    // 0043bdc5  e93dffffff             -jmp 0x43bd07
    goto L_0x0043bd07;
L_0x0043bdca:
    // 0043bdca  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043bdcc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bdcd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bdce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bdcf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bdd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bdd1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43bde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043bde0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043bde1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043bde2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043bde4  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043bdeb  7520                   -jne 0x43be0d
    if (!cpu.flags.zf)
    {
        goto L_0x0043be0d;
    }
    // 0043bded  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043bdef  eb06                   -jmp 0x43bdf7
    goto L_0x0043bdf7;
L_0x0043bdf1:
    // 0043bdf1  40                     -inc eax
    (cpu.eax)++;
    // 0043bdf2  83f81a                 +cmp eax, 0x1a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043bdf5  7d36                   -jge 0x43be2d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043be2d;
    }
L_0x0043bdf7:
    // 0043bdf7  8b148540d26f00         -mov edx, dword ptr [eax*4 + 0x6fd240]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328320) /* 0x6fd240 */ + cpu.eax * 4);
    // 0043bdfe  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0043be01  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0043be04  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043be06  75e9                   -jne 0x43bdf1
    if (!cpu.flags.zf)
    {
        goto L_0x0043bdf1;
    }
    // 0043be08  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043be0a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043be0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043be0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043be0d:
    // 0043be0d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043be0f  eb06                   -jmp 0x43be17
    goto L_0x0043be17;
L_0x0043be11:
    // 0043be11  40                     -inc eax
    (cpu.eax)++;
    // 0043be12  83f80d                 +cmp eax, 0xd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043be15  7d16                   -jge 0x43be2d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043be2d;
    }
L_0x0043be17:
    // 0043be17  8b14850cd26f00         -mov edx, dword ptr [eax*4 + 0x6fd20c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328268) /* 0x6fd20c */ + cpu.eax * 4);
    // 0043be1e  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0043be21  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0043be24  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043be26  75e9                   -jne 0x43be11
    if (!cpu.flags.zf)
    {
        goto L_0x0043be11;
    }
    // 0043be28  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043be2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043be2b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043be2c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043be2d:
    // 0043be2d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043be32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043be33  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043be34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_43be40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043be40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043be41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043be42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043be43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043be44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043be45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043be46  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043be48  81ec98000000           -sub esp, 0x98
    (cpu.esp) -= x86::reg32(x86::sreg32(152 /*0x98*/));
    // 0043be4e  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 0043be54  bf70c96f00             -mov edi, 0x6fc970
    cpu.edi = 7326064 /*0x6fc970*/;
    // 0043be59  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043be5b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0043be5d:
    // 0043be5d  3b1d04d26f00           +cmp ebx, dword ptr [0x6fd204]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328260) /* 0x6fd204 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043be63  0f8d7e010000           -jge 0x43bfe7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043bfe7;
    }
    // 0043be69  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043be6b  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0043be6e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0043be71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043be73  0f856e010000           -jne 0x43bfe7
    if (!cpu.flags.zf)
    {
        goto L_0x0043bfe7;
    }
    // 0043be79  8d55ea                 -lea edx, [ebp - 0x16]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-22) /* -0x16 */);
    // 0043be7c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043be7e  e86d9affff             -call 0x4358f0
    cpu.esp -= 4;
    sub_4358f0(app, cpu);
    if (cpu.terminate) return;
    // 0043be83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043be85  0f8456010000           -je 0x43bfe1
    if (cpu.flags.zf)
    {
        goto L_0x0043bfe1;
    }
    // 0043be8b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043be8d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043be90  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043be92  833cc700               +cmp dword ptr [edi + eax*8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043be96  0f8445010000           -je 0x43bfe1
    if (cpu.flags.zf)
    {
        goto L_0x0043bfe1;
    }
    // 0043be9c  837d5a00               +cmp dword ptr [ebp + 0x5a], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043bea0  7439                   -je 0x43bedb
    if (cpu.flags.zf)
    {
        goto L_0x0043bedb;
    }
    // 0043bea2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043bea4  eb06                   -jmp 0x43beac
    goto L_0x0043beac;
L_0x0043bea6:
    // 0043bea6  40                     -inc eax
    (cpu.eax)++;
    // 0043bea7  83f820                 +cmp eax, 0x20
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043beaa  7d14                   -jge 0x43bec0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043bec0;
    }
L_0x0043beac:
    // 0043beac  807c281a00             +cmp byte ptr [eax + ebp + 0x1a], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(26) /* 0x1a */ + cpu.ebp * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043beb1  74f3                   -je 0x43bea6
    if (cpu.flags.zf)
    {
        goto L_0x0043bea6;
    }
    // 0043beb3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043beb5  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0043beb8  c1e21c                 -shl edx, 0x1c
    cpu.edx <<= 28 /*0x1c*/ % 32;
    // 0043bebb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043bebd  8d7002                 -lea esi, [eax + 2]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x0043bec0:
    // 0043bec0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043bec2  8d55ea                 -lea edx, [ebp - 0x16]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-22) /* -0x16 */);
    // 0043bec5  e866b70a00             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 0043beca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043becc  e81f9affff             -call 0x4358f0
    cpu.esp -= 4;
    sub_4358f0(app, cpu);
    if (cpu.terminate) return;
    // 0043bed1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043bed3  7406                   -je 0x43bedb
    if (cpu.flags.zf)
    {
        goto L_0x0043bedb;
    }
    // 0043bed5  837d5a00               +cmp dword ptr [ebp + 0x5a], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043bed9  75e5                   -jne 0x43bec0
    if (!cpu.flags.zf)
    {
        goto L_0x0043bec0;
    }
L_0x0043bedb:
    // 0043bedb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043bedd  eb29                   -jmp 0x43bf08
    goto L_0x0043bf08;
L_0x0043bedf:
    // 0043bedf  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0043bee6  8b4c2a5e               -mov ecx, dword ptr [edx + ebp + 0x5e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(94) /* 0x5e */ + cpu.ebp * 1);
    // 0043beea  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043beec  7414                   -je 0x43bf02
    if (cpu.flags.zf)
    {
        goto L_0x0043bf02;
    }
    // 0043beee  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043bef0  c1e014                 -shl eax, 0x14
    cpu.eax <<= 20 /*0x14*/ % 32;
    // 0043bef3  c1e21c                 -shl edx, 0x1c
    cpu.edx <<= 28 /*0x1c*/ % 32;
    // 0043bef6  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0043bef9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043befb  01c8                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043befd  8d7003                 -lea esi, [eax + 3]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0043bf00  eb12                   -jmp 0x43bf14
    goto L_0x0043bf14;
L_0x0043bf02:
    // 0043bf02  40                     -inc eax
    (cpu.eax)++;
    // 0043bf03  83f804                 +cmp eax, 4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043bf06  7d0c                   -jge 0x43bf14
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043bf14;
    }
L_0x0043bf08:
    // 0043bf08  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043bf0a  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0043bf0d  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0043bf10  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043bf12  74cb                   -je 0x43bedf
    if (cpu.flags.zf)
    {
        goto L_0x0043bedf;
    }
L_0x0043bf14:
    // 0043bf14  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043bf16  e9b6000000             -jmp 0x43bfd1
    goto L_0x0043bfd1;
L_0x0043bf1b:
    // 0043bf1b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043bf1d  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0043bf20  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043bf22  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0043bf25  8d0c17                 -lea ecx, [edi + edx]
    cpu.ecx = x86::reg32(cpu.edi + cpu.edx * 1);
    // 0043bf28  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043bf2d  894d6e                 -mov dword ptr [ebp + 0x6e], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */) = cpu.ecx;
    // 0043bf30  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0043bf32  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0043bf34  895572                 -mov dword ptr [ebp + 0x72], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */) = cpu.edx;
    // 0043bf37  8b556e                 -mov edx, dword ptr [ebp + 0x6e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */);
    // 0043bf3a  8b4d72                 -mov ecx, dword ptr [ebp + 0x72]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 0043bf3d  8b5240                 -mov edx, dword ptr [edx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 0043bf40  85ca                   +test edx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.ecx));
    // 0043bf42  0f8483000000           -je 0x43bfcb
    if (cpu.flags.zf)
    {
        goto L_0x0043bfcb;
    }
    // 0043bf48  8b54853a               -mov edx, dword ptr [ebp + eax*4 + 0x3a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(58) /* 0x3a */ + cpu.eax * 4);
    // 0043bf4c  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0043bf4f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043bf51  7d02                   -jge 0x43bf55
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043bf55;
    }
    // 0043bf53  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043bf55:
    // 0043bf55  89557e                 -mov dword ptr [ebp + 0x7e], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edx;
    // 0043bf58  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0043bf5a  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0043bf61  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0043bf64  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043bf66  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0043bf69  2b91503d5f00           -sub edx, dword ptr [ecx + 0x5f3d50]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6241616) /* 0x5f3d50 */)));
    // 0043bf6f  89557a                 -mov dword ptr [ebp + 0x7a], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */) = cpu.edx;
    // 0043bf72  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043bf74  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0043bf77  895576                 -mov dword ptr [ebp + 0x76], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.edx;
    // 0043bf7a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043bf7c  c1e21c                 -shl edx, 0x1c
    cpu.edx <<= 28 /*0x1c*/ % 32;
    // 0043bf7f  035576                 -add edx, dword ptr [ebp + 0x76]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */)));
    // 0043bf82  837d7a40               +cmp dword ptr [ebp + 0x7a], 0x40
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043bf86  7e19                   -jle 0x43bfa1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043bfa1;
    }
    // 0043bf88  83b9503d5f0040         +cmp dword ptr [ecx + 0x5f3d50], 0x40
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6241616) /* 0x5f3d50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043bf8f  7d08                   -jge 0x43bf99
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043bf99;
    }
    // 0043bf91  8db201ff0000           -lea esi, [edx + 0xff01]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(65281) /* 0xff01 */);
    // 0043bf97  eb48                   -jmp 0x43bfe1
    goto L_0x0043bfe1;
L_0x0043bf99:
    // 0043bf99  8db201ff8000           -lea esi, [edx + 0x80ff01]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(8453889) /* 0x80ff01 */);
    // 0043bf9f  eb40                   -jmp 0x43bfe1
    goto L_0x0043bfe1;
L_0x0043bfa1:
    // 0043bfa1  837d7ac0               +cmp dword ptr [ebp + 0x7a], -0x40
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-64 /*-0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043bfa5  7d24                   -jge 0x43bfcb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043bfcb;
    }
    // 0043bfa7  81b9503d5f00c0000000   +cmp dword ptr [ecx + 0x5f3d50], 0xc0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6241616) /* 0x5f3d50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043bfb1  7e0c                   -jle 0x43bfbf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043bfbf;
    }
    // 0043bfb3  8db20100ff00           -lea esi, [edx + 0xff0001]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(16711681) /* 0xff0001 */);
    // 0043bfb9  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043bfba  e99efeffff             -jmp 0x43be5d
    goto L_0x0043be5d;
L_0x0043bfbf:
    // 0043bfbf  8db201007f00           -lea esi, [edx + 0x7f0001]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(8323073) /* 0x7f0001 */);
    // 0043bfc5  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043bfc6  e992feffff             -jmp 0x43be5d
    goto L_0x0043be5d;
L_0x0043bfcb:
    // 0043bfcb  40                     -inc eax
    (cpu.eax)++;
    // 0043bfcc  83f808                 +cmp eax, 8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043bfcf  7d10                   -jge 0x43bfe1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043bfe1;
    }
L_0x0043bfd1:
    // 0043bfd1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043bfd3  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0043bfd6  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0043bfd9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043bfdb  0f843affffff           -je 0x43bf1b
    if (cpu.flags.zf)
    {
        goto L_0x0043bf1b;
    }
L_0x0043bfe1:
    // 0043bfe1  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043bfe2  e976feffff             -jmp 0x43be5d
    goto L_0x0043be5d;
L_0x0043bfe7:
    // 0043bfe7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043bfe9  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 0043bfef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bff0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bff1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bff2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bff3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bff4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043bff5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_43c000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043c000  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c001  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043c002  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043c004  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043c006  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0043c009  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0043c00c  83fa01                 +cmp edx, 1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c00f  7408                   -je 0x43c019
    if (cpu.flags.zf)
    {
        goto L_0x0043c019;
    }
    // 0043c011  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043c016  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c017  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c018  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043c019:
    // 0043c019  c1e81c                 -shr eax, 0x1c
    cpu.eax >>= 28 /*0x1c*/ % 32;
    // 0043c01c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043c01e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043c021  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043c023  f604c570c96f0004       +test byte ptr [eax*8 + 0x6fc970], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7326064) /* 0x6fc970 */ + cpu.eax * 8) & 4 /*0x4*/));
    // 0043c02b  7408                   -je 0x43c035
    if (cpu.flags.zf)
    {
        goto L_0x0043c035;
    }
    // 0043c02d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043c032  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c033  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c034  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043c035:
    // 0043c035  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043c037  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c038  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c039  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_43c040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043c040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043c042  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c043  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043c044  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043c046  a1b0d36f00             -mov eax, dword ptr [0x6fd3b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043c04b  e880440500             -call 0x4904d0
    cpu.esp -= 4;
    sub_4904d0(app, cpu);
    if (cpu.terminate) return;
    // 0043c050  8b1db0d36f00           -mov ebx, dword ptr [0x6fd3b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043c056  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043c058  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043c05a  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c05d  7527                   -jne 0x43c086
    if (!cpu.flags.zf)
    {
        goto L_0x0043c086;
    }
    // 0043c05f  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 0043c062  e899ffffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043c067  a348d36f00             -mov dword ptr [0x6fd348], eax
    app->getMemory<x86::reg32>(x86::reg32(7328584) /* 0x6fd348 */) = cpu.eax;
    // 0043c06c  8b423c                 -mov eax, dword ptr [edx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 0043c06f  e88cffffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043c074  a34cd36f00             -mov dword ptr [0x6fd34c], eax
    app->getMemory<x86::reg32>(x86::reg32(7328588) /* 0x6fd34c */) = cpu.eax;
    // 0043c079  8b4240                 -mov eax, dword ptr [edx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 0043c07c  e87fffffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043c081  a350d36f00             -mov dword ptr [0x6fd350], eax
    app->getMemory<x86::reg32>(x86::reg32(7328592) /* 0x6fd350 */) = cpu.eax;
L_0x0043c086:
    // 0043c086  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0043c089  e872ffffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043c08e  a3dcd26f00             -mov dword ptr [0x6fd2dc], eax
    app->getMemory<x86::reg32>(x86::reg32(7328476) /* 0x6fd2dc */) = cpu.eax;
    // 0043c093  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0043c096  e865ffffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043c09b  a3e0d26f00             -mov dword ptr [0x6fd2e0], eax
    app->getMemory<x86::reg32>(x86::reg32(7328480) /* 0x6fd2e0 */) = cpu.eax;
    // 0043c0a0  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0043c0a3  e858ffffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043c0a8  a3e4d26f00             -mov dword ptr [0x6fd2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(7328484) /* 0x6fd2e4 */) = cpu.eax;
    // 0043c0ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c0ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c0af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c0b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c0b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_43c110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0043c110  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043c111  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043c112  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043c113  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043c115  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 0043c118  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0043c11b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0043c11d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0043c11f  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 0043c124  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0043c127  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0043c12a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043c12c  7409                   -je 0x43c137
    if (cpu.flags.zf)
    {
        goto L_0x0043c137;
    }
    // 0043c12e  c745f440e4ff00         -mov dword ptr [ebp - 0xc], 0xffe440
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 16770112 /*0xffe440*/;
    // 0043c135  eb07                   -jmp 0x43c13e
    goto L_0x0043c13e;
L_0x0043c137:
    // 0043c137  c745f4fd9d64ff         -mov dword ptr [ebp - 0xc], 0xff649dfd
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 4284784125 /*0xff649dfd*/;
L_0x0043c13e:
    // 0043c13e  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c141  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0043c144  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0043c147  8b159c3d5f00           -mov edx, dword ptr [0x5f3d9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */);
    // 0043c14d  48                     -dec eax
    (cpu.eax)--;
    // 0043c14e  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043c150  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c153  0f874b070000           -ja 0x43c8a4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0043c8a4;
    }
    // 0043c159  ff2485b4c04300         -jmp dword ptr [eax*4 + 0x43c0b4]
    cpu.ip = app->getMemory<x86::reg32>(4440244 + cpu.eax * 4); goto dynamic_jump;
  case 0x0043c160:
    // 0043c160  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c163  c1e81c                 -shr eax, 0x1c
    cpu.eax >>= 28 /*0x1c*/ % 32;
    // 0043c166  40                     -inc eax
    (cpu.eax)++;
    // 0043c167  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c168  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 0043c16d  e8de560900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043c172  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c173  6848775300             -push 0x537748
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470024 /*0x537748*/;
    cpu.esp -= 4;
    // 0043c178  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c17b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c17c  e80f350a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043c181  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043c184  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043c187  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043c188  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043c18a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043c18c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043c18e  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c191  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043c194  e8f75f0100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043c199  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c19c  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c19f  8b1d983d5f00           -mov ebx, dword ptr [0x5f3d98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */);
    // 0043c1a5  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0043c1a8  250000ff00             -and eax, 0xff0000
    cpu.eax &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 0043c1ad  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043c1af  c1ea1c                 -shr edx, 0x1c
    cpu.edx >>= 28 /*0x1c*/ % 32;
    // 0043c1b2  3d00008000             +cmp eax, 0x800000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388608 /*0x800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c1b7  7537                   -jne 0x43c1f0
    if (!cpu.flags.zf)
    {
        goto L_0x0043c1f0;
    }
    // 0043c1b9  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c1bc  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0043c1c1  3d00ff0000             +cmp eax, 0xff00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65280 /*0xff00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c1c6  7528                   -jne 0x43c1f0
    if (!cpu.flags.zf)
    {
        goto L_0x0043c1f0;
    }
    // 0043c1c8  83fa06                 +cmp edx, 6
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c1cb  7209                   -jb 0x43c1d6
    if (cpu.flags.cf)
    {
        goto L_0x0043c1d6;
    }
    // 0043c1cd  760b                   -jbe 0x43c1da
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043c1da;
    }
    // 0043c1cf  83fa07                 +cmp edx, 7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c1d2  7410                   -je 0x43c1e4
    if (cpu.flags.zf)
    {
        goto L_0x0043c1e4;
    }
    // 0043c1d4  eb0e                   -jmp 0x43c1e4
    goto L_0x0043c1e4;
L_0x0043c1d6:
    // 0043c1d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043c1d8  750a                   -jne 0x43c1e4
    if (!cpu.flags.zf)
    {
        goto L_0x0043c1e4;
    }
L_0x0043c1da:
    // 0043c1da  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043c1dc  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043c1df  e9b9000000             -jmp 0x43c29d
    goto L_0x0043c29d;
L_0x0043c1e4:
    // 0043c1e4  c745fc06000000         -mov dword ptr [ebp - 4], 6
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 6 /*0x6*/;
    // 0043c1eb  e9ad000000             -jmp 0x43c29d
    goto L_0x0043c29d;
L_0x0043c1f0:
    // 0043c1f0  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c1f3  250000ff00             -and eax, 0xff0000
    cpu.eax &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 0043c1f8  3d00007f00             +cmp eax, 0x7f0000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c1fd  752c                   -jne 0x43c22b
    if (!cpu.flags.zf)
    {
        goto L_0x0043c22b;
    }
    // 0043c1ff  f645f9ff               +test byte ptr [ebp - 7], 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */) & 255 /*0xff*/));
    // 0043c203  7526                   -jne 0x43c22b
    if (!cpu.flags.zf)
    {
        goto L_0x0043c22b;
    }
    // 0043c205  83fa06                 +cmp edx, 6
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c208  720d                   -jb 0x43c217
    if (cpu.flags.cf)
    {
        goto L_0x0043c217;
    }
    // 0043c20a  0f8686000000           -jbe 0x43c296
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043c296;
    }
    // 0043c210  83fa07                 +cmp edx, 7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c213  740a                   -je 0x43c21f
    if (cpu.flags.zf)
    {
        goto L_0x0043c21f;
    }
    // 0043c215  eb08                   -jmp 0x43c21f
    goto L_0x0043c21f;
L_0x0043c217:
    // 0043c217  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043c219  0f8477000000           -je 0x43c296
    if (cpu.flags.zf)
    {
        goto L_0x0043c296;
    }
L_0x0043c21f:
    // 0043c21f  c745fc07000000         -mov dword ptr [ebp - 4], 7
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 7 /*0x7*/;
    // 0043c226  e972000000             -jmp 0x43c29d
    goto L_0x0043c29d;
L_0x0043c22b:
    // 0043c22b  f645faff               +test byte ptr [ebp - 6], 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */) & 255 /*0xff*/));
    // 0043c22f  7524                   -jne 0x43c255
    if (!cpu.flags.zf)
    {
        goto L_0x0043c255;
    }
    // 0043c231  83fa06                 +cmp edx, 6
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c234  7209                   -jb 0x43c23f
    if (cpu.flags.cf)
    {
        goto L_0x0043c23f;
    }
    // 0043c236  760b                   -jbe 0x43c243
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043c243;
    }
    // 0043c238  83fa07                 +cmp edx, 7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c23b  740f                   -je 0x43c24c
    if (cpu.flags.zf)
    {
        goto L_0x0043c24c;
    }
    // 0043c23d  eb0d                   -jmp 0x43c24c
    goto L_0x0043c24c;
L_0x0043c23f:
    // 0043c23f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043c241  7509                   -jne 0x43c24c
    if (!cpu.flags.zf)
    {
        goto L_0x0043c24c;
    }
L_0x0043c243:
    // 0043c243  c745fc02000000         -mov dword ptr [ebp - 4], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 2 /*0x2*/;
    // 0043c24a  eb51                   -jmp 0x43c29d
    goto L_0x0043c29d;
L_0x0043c24c:
    // 0043c24c  c745fc04000000         -mov dword ptr [ebp - 4], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 4 /*0x4*/;
    // 0043c253  eb48                   -jmp 0x43c29d
    goto L_0x0043c29d;
L_0x0043c255:
    // 0043c255  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c258  250000ff00             -and eax, 0xff0000
    cpu.eax &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 0043c25d  3d0000ff00             +cmp eax, 0xff0000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c262  7524                   -jne 0x43c288
    if (!cpu.flags.zf)
    {
        goto L_0x0043c288;
    }
    // 0043c264  83fa06                 +cmp edx, 6
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c267  7209                   -jb 0x43c272
    if (cpu.flags.cf)
    {
        goto L_0x0043c272;
    }
    // 0043c269  760b                   -jbe 0x43c276
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043c276;
    }
    // 0043c26b  83fa07                 +cmp edx, 7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c26e  740f                   -je 0x43c27f
    if (cpu.flags.zf)
    {
        goto L_0x0043c27f;
    }
    // 0043c270  eb0d                   -jmp 0x43c27f
    goto L_0x0043c27f;
L_0x0043c272:
    // 0043c272  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043c274  7509                   -jne 0x43c27f
    if (!cpu.flags.zf)
    {
        goto L_0x0043c27f;
    }
L_0x0043c276:
    // 0043c276  c745fc03000000         -mov dword ptr [ebp - 4], 3
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 3 /*0x3*/;
    // 0043c27d  eb1e                   -jmp 0x43c29d
    goto L_0x0043c29d;
L_0x0043c27f:
    // 0043c27f  c745fc05000000         -mov dword ptr [ebp - 4], 5
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 5 /*0x5*/;
    // 0043c286  eb15                   -jmp 0x43c29d
    goto L_0x0043c29d;
L_0x0043c288:
    // 0043c288  3d00008000             +cmp eax, 0x800000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388608 /*0x800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c28d  7507                   -jne 0x43c296
    if (!cpu.flags.zf)
    {
        goto L_0x0043c296;
    }
    // 0043c28f  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0043c291  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0043c294  eb07                   -jmp 0x43c29d
    goto L_0x0043c29d;
L_0x0043c296:
    // 0043c296  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
L_0x0043c29d:
    // 0043c29d  83fa03                 +cmp edx, 3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c2a0  7c38                   -jl 0x43c2da
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043c2da;
    }
    // 0043c2a2  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c2a5  7f33                   -jg 0x43c2da
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043c2da;
    }
    // 0043c2a7  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043c2aa  83f903                 +cmp ecx, 3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c2ad  772b                   -ja 0x43c2da
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0043c2da;
    }
    // 0043c2af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043c2b1  ff2485c4c04300         -jmp dword ptr [eax*4 + 0x43c0c4]
    cpu.ip = app->getMemory<x86::reg32>(4440260 + cpu.eax * 4); goto dynamic_jump;
  case 0x0043c2b8:
    // 0043c2b8  c745fc09000000         -mov dword ptr [ebp - 4], 9
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 9 /*0x9*/;
    // 0043c2bf  eb19                   -jmp 0x43c2da
    goto L_0x0043c2da;
  case 0x0043c2c1:
    // 0043c2c1  c745fc08000000         -mov dword ptr [ebp - 4], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 8 /*0x8*/;
    // 0043c2c8  eb10                   -jmp 0x43c2da
    goto L_0x0043c2da;
  case 0x0043c2ca:
    // 0043c2ca  c745fc0a000000         -mov dword ptr [ebp - 4], 0xa
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 10 /*0xa*/;
    // 0043c2d1  eb07                   -jmp 0x43c2da
    goto L_0x0043c2da;
  case 0x0043c2d3:
    // 0043c2d3  c745fc0b000000         -mov dword ptr [ebp - 4], 0xb
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 11 /*0xb*/;
L_0x0043c2da:
    // 0043c2da  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0043c2df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043c2e1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043c2e4  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043c2e6  8d4258                 -lea eax, [edx + 0x58]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(88) /* 0x58 */);
    // 0043c2e9  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 0043c2ef  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043c2f1  0f8464030000           -je 0x43c65b
    if (cpu.flags.zf)
    {
        goto L_0x0043c65b;
    }
    // 0043c2f7  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043c2fa  83f90b                 +cmp ecx, 0xb
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c2fd  0f87bd050000           -ja 0x43c8c0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0043c8c0;
    }
    // 0043c303  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043c305  ff2485d4c04300         -jmp dword ptr [eax*4 + 0x43c0d4]
    cpu.ip = app->getMemory<x86::reg32>(4440276 + cpu.eax * 4); goto dynamic_jump;
  case 0x0043c30c:
    // 0043c30c  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c30e  8b15389a7400           -mov edx, dword ptr [0x749a38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c314  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c315  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c31a  6800002c3f             -push 0x3f2c0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059848192 /*0x3f2c0000*/;
    cpu.esp -= 4;
    // 0043c31f  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c324  680000383f             -push 0x3f380000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060634624 /*0x3f380000*/;
    cpu.esp -= 4;
    // 0043c329  6800002e3f             -push 0x3f2e0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059979264 /*0x3f2e0000*/;
    cpu.esp -= 4;
    // 0043c32e  680000383f             -push 0x3f380000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060634624 /*0x3f380000*/;
    cpu.esp -= 4;
    // 0043c333  6800002e3f             -push 0x3f2e0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059979264 /*0x3f2e0000*/;
    cpu.esp -= 4;
    // 0043c338  8d4709                 -lea eax, [edi + 9]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(9) /* 0x9 */);
    // 0043c33b  6800002c3f             -push 0x3f2c0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059848192 /*0x3f2c0000*/;
    cpu.esp -= 4;
    // 0043c340  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c341  8d5e0c                 -lea ebx, [esi + 0xc]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043c344  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043c345  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c346  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0043c348  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c349  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043c34b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043c34d  e8aeec0900             -call 0x4db000
    cpu.esp -= 4;
    sub_4db000(app, cpu);
    if (cpu.terminate) return;
    // 0043c352  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c354  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c355  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c356  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c357  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0043c35a:
    // 0043c35a  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c35c  8b0d389a7400           -mov ecx, dword ptr [0x749a38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c362  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043c363  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c368  680000393f             -push 0x3f390000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060700160 /*0x3f390000*/;
    cpu.esp -= 4;
    // 0043c36d  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c372  680000453f             -push 0x3f450000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061486592 /*0x3f450000*/;
    cpu.esp -= 4;
    // 0043c377  6800002e3f             -push 0x3f2e0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059979264 /*0x3f2e0000*/;
    cpu.esp -= 4;
    // 0043c37c  680000453f             -push 0x3f450000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061486592 /*0x3f450000*/;
    cpu.esp -= 4;
    // 0043c381  6800002e3f             -push 0x3f2e0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059979264 /*0x3f2e0000*/;
    cpu.esp -= 4;
    // 0043c386  8d4709                 -lea eax, [edi + 9]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(9) /* 0x9 */);
    // 0043c389  680000393f             -push 0x3f390000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060700160 /*0x3f390000*/;
    cpu.esp -= 4;
    // 0043c38e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c38f  8d5e0c                 -lea ebx, [esi + 0xc]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043c392  e9ae020000             -jmp 0x43c645
    goto L_0x0043c645;
  case 0x0043c397:
    // 0043c397  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c399  8b15389a7400           -mov edx, dword ptr [0x749a38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c39f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c3a0  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c3a5  680000593f             -push 0x3f590000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062797312 /*0x3f590000*/;
    cpu.esp -= 4;
    // 0043c3aa  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c3af  6800006b3f             -push 0x3f6b0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1063976960 /*0x3f6b0000*/;
    cpu.esp -= 4;
    // 0043c3b4  6800002e3f             -push 0x3f2e0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059979264 /*0x3f2e0000*/;
    cpu.esp -= 4;
    // 0043c3b9  6800006b3f             -push 0x3f6b0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1063976960 /*0x3f6b0000*/;
    cpu.esp -= 4;
    // 0043c3be  6800002e3f             -push 0x3f2e0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059979264 /*0x3f2e0000*/;
    cpu.esp -= 4;
    // 0043c3c3  8d4709                 -lea eax, [edi + 9]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(9) /* 0x9 */);
    // 0043c3c6  680000593f             -push 0x3f590000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062797312 /*0x3f590000*/;
    cpu.esp -= 4;
    // 0043c3cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c3cc  8d5e12                 -lea ebx, [esi + 0x12]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0043c3cf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043c3d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c3d1  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0043c3d3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c3d4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043c3d6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043c3d8  e823ec0900             -call 0x4db000
    cpu.esp -= 4;
    sub_4db000(app, cpu);
    if (cpu.terminate) return;
    // 0043c3dd  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c3df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c3e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c3e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c3e2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0043c3e5:
    // 0043c3e5  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c3e7  8b0d389a7400           -mov ecx, dword ptr [0x749a38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c3ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043c3ee  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c3f3  680000463f             -push 0x3f460000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061552128 /*0x3f460000*/;
    cpu.esp -= 4;
    // 0043c3f8  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c3fd  680000583f             -push 0x3f580000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062731776 /*0x3f580000*/;
    cpu.esp -= 4;
    // 0043c402  6800002e3f             -push 0x3f2e0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059979264 /*0x3f2e0000*/;
    cpu.esp -= 4;
    // 0043c407  680000583f             -push 0x3f580000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062731776 /*0x3f580000*/;
    cpu.esp -= 4;
    // 0043c40c  6800002e3f             -push 0x3f2e0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059979264 /*0x3f2e0000*/;
    cpu.esp -= 4;
    // 0043c411  8d4709                 -lea eax, [edi + 9]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(9) /* 0x9 */);
    // 0043c414  680000463f             -push 0x3f460000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061552128 /*0x3f460000*/;
    cpu.esp -= 4;
    // 0043c419  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c41a  8d5e12                 -lea ebx, [esi + 0x12]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0043c41d  e923020000             -jmp 0x43c645
    goto L_0x0043c645;
  case 0x0043c422:
    // 0043c422  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c424  8b15389a7400           -mov edx, dword ptr [0x749a38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c42a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c42b  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c430  680000763f             -push 0x3f760000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064697856 /*0x3f760000*/;
    cpu.esp -= 4;
    // 0043c435  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c43a  6800007f3f             -push 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065287680 /*0x3f7f0000*/;
    cpu.esp -= 4;
    // 0043c43f  680000253f             -push 0x3f250000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059389440 /*0x3f250000*/;
    cpu.esp -= 4;
    // 0043c444  6800007f3f             -push 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065287680 /*0x3f7f0000*/;
    cpu.esp -= 4;
    // 0043c449  680000253f             -push 0x3f250000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059389440 /*0x3f250000*/;
    cpu.esp -= 4;
    // 0043c44e  8d4712                 -lea eax, [edi + 0x12]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(18) /* 0x12 */);
    // 0043c451  680000763f             -push 0x3f760000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064697856 /*0x3f760000*/;
    cpu.esp -= 4;
    // 0043c456  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c457  8d5e09                 -lea ebx, [esi + 9]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0043c45a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043c45b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c45c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0043c45e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c45f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043c461  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043c463  e898eb0900             -call 0x4db000
    cpu.esp -= 4;
    sub_4db000(app, cpu);
    if (cpu.terminate) return;
    // 0043c468  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c46a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c46b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c46c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c46d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0043c470:
    // 0043c470  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c472  8b0d389a7400           -mov ecx, dword ptr [0x749a38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c478  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043c479  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c47e  6800006c3f             -push 0x3f6c0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064042496 /*0x3f6c0000*/;
    cpu.esp -= 4;
    // 0043c483  680000373f             -push 0x3f370000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060569088 /*0x3f370000*/;
    cpu.esp -= 4;
    // 0043c488  680000753f             -push 0x3f750000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064632320 /*0x3f750000*/;
    cpu.esp -= 4;
    // 0043c48d  680000253f             -push 0x3f250000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059389440 /*0x3f250000*/;
    cpu.esp -= 4;
    // 0043c492  680000753f             -push 0x3f750000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064632320 /*0x3f750000*/;
    cpu.esp -= 4;
    // 0043c497  680000253f             -push 0x3f250000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059389440 /*0x3f250000*/;
    cpu.esp -= 4;
    // 0043c49c  8d4712                 -lea eax, [edi + 0x12]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(18) /* 0x12 */);
    // 0043c49f  6800006c3f             -push 0x3f6c0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064042496 /*0x3f6c0000*/;
    cpu.esp -= 4;
    // 0043c4a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c4a5  8d5e09                 -lea ebx, [esi + 9]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0043c4a8  e998010000             -jmp 0x43c645
    goto L_0x0043c645;
  case 0x0043c4ad:
    // 0043c4ad  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c4af  8b15389a7400           -mov edx, dword ptr [0x749a38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c4b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c4b6  680000243f             -push 0x3f240000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059323904 /*0x3f240000*/;
    cpu.esp -= 4;
    // 0043c4bb  6800006c3f             -push 0x3f6c0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064042496 /*0x3f6c0000*/;
    cpu.esp -= 4;
    // 0043c4c0  680000243f             -push 0x3f240000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059323904 /*0x3f240000*/;
    cpu.esp -= 4;
    // 0043c4c5  680000753f             -push 0x3f750000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064632320 /*0x3f750000*/;
    cpu.esp -= 4;
    // 0043c4ca  680000183f             -push 0x3f180000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058537472 /*0x3f180000*/;
    cpu.esp -= 4;
    // 0043c4cf  680000753f             -push 0x3f750000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064632320 /*0x3f750000*/;
    cpu.esp -= 4;
    // 0043c4d4  680000183f             -push 0x3f180000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058537472 /*0x3f180000*/;
    cpu.esp -= 4;
    // 0043c4d9  8d470c                 -lea eax, [edi + 0xc]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0043c4dc  6800006c3f             -push 0x3f6c0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064042496 /*0x3f6c0000*/;
    cpu.esp -= 4;
    // 0043c4e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c4e2  8d5e09                 -lea ebx, [esi + 9]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0043c4e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043c4e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c4e7  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0043c4e9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c4ea  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043c4ec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043c4ee  e80deb0900             -call 0x4db000
    cpu.esp -= 4;
    sub_4db000(app, cpu);
    if (cpu.terminate) return;
    // 0043c4f3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c4f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c4f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c4f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c4f8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0043c4fb:
    // 0043c4fb  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c4fd  8b0d389a7400           -mov ecx, dword ptr [0x749a38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c503  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043c504  680000243f             -push 0x3f240000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059323904 /*0x3f240000*/;
    cpu.esp -= 4;
    // 0043c509  680000763f             -push 0x3f760000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064697856 /*0x3f760000*/;
    cpu.esp -= 4;
    // 0043c50e  680000243f             -push 0x3f240000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059323904 /*0x3f240000*/;
    cpu.esp -= 4;
    // 0043c513  6800007f3f             -push 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065287680 /*0x3f7f0000*/;
    cpu.esp -= 4;
    // 0043c518  680000183f             -push 0x3f180000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058537472 /*0x3f180000*/;
    cpu.esp -= 4;
    // 0043c51d  6800007f3f             -push 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065287680 /*0x3f7f0000*/;
    cpu.esp -= 4;
    // 0043c522  680000183f             -push 0x3f180000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058537472 /*0x3f180000*/;
    cpu.esp -= 4;
    // 0043c527  8d470c                 -lea eax, [edi + 0xc]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0043c52a  680000763f             -push 0x3f760000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064697856 /*0x3f760000*/;
    cpu.esp -= 4;
    // 0043c52f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c530  8d5e09                 -lea ebx, [esi + 9]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0043c533  e90d010000             -jmp 0x43c645
    goto L_0x0043c645;
  case 0x0043c538:
    // 0043c538  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c53a  8b15389a7400           -mov edx, dword ptr [0x749a38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c540  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c541  6800002d3f             -push 0x3f2d0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059913728 /*0x3f2d0000*/;
    cpu.esp -= 4;
    // 0043c546  680000303f             -push 0x3f300000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060110336 /*0x3f300000*/;
    cpu.esp -= 4;
    // 0043c54b  6800002d3f             -push 0x3f2d0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059913728 /*0x3f2d0000*/;
    cpu.esp -= 4;
    // 0043c550  680000433f             -push 0x3f430000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061355520 /*0x3f430000*/;
    cpu.esp -= 4;
    // 0043c555  680000173f             -push 0x3f170000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058471936 /*0x3f170000*/;
    cpu.esp -= 4;
    // 0043c55a  680000433f             -push 0x3f430000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061355520 /*0x3f430000*/;
    cpu.esp -= 4;
    // 0043c55f  680000173f             -push 0x3f170000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058471936 /*0x3f170000*/;
    cpu.esp -= 4;
    // 0043c564  8d4716                 -lea eax, [edi + 0x16]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 0043c567  680000303f             -push 0x3f300000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1060110336 /*0x3f300000*/;
    cpu.esp -= 4;
    // 0043c56c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c56d  8d5e13                 -lea ebx, [esi + 0x13]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(19) /* 0x13 */);
    // 0043c570  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043c571  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c572  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0043c574  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c575  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043c577  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043c579  e882ea0900             -call 0x4db000
    cpu.esp -= 4;
    sub_4db000(app, cpu);
    if (cpu.terminate) return;
    // 0043c57e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c580  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c581  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c582  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c583  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0043c586:
    // 0043c586  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c588  8b0d389a7400           -mov ecx, dword ptr [0x749a38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c58e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043c58f  6800002d3f             -push 0x3f2d0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059913728 /*0x3f2d0000*/;
    cpu.esp -= 4;
    // 0043c594  680000443f             -push 0x3f440000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061421056 /*0x3f440000*/;
    cpu.esp -= 4;
    // 0043c599  6800002d3f             -push 0x3f2d0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059913728 /*0x3f2d0000*/;
    cpu.esp -= 4;
    // 0043c59e  680000573f             -push 0x3f570000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062666240 /*0x3f570000*/;
    cpu.esp -= 4;
    // 0043c5a3  680000173f             -push 0x3f170000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058471936 /*0x3f170000*/;
    cpu.esp -= 4;
    // 0043c5a8  680000573f             -push 0x3f570000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062666240 /*0x3f570000*/;
    cpu.esp -= 4;
    // 0043c5ad  680000173f             -push 0x3f170000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058471936 /*0x3f170000*/;
    cpu.esp -= 4;
    // 0043c5b2  8d4716                 -lea eax, [edi + 0x16]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 0043c5b5  680000443f             -push 0x3f440000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061421056 /*0x3f440000*/;
    cpu.esp -= 4;
    // 0043c5ba  e982000000             -jmp 0x43c641
    goto L_0x0043c641;
  case 0x0043c5bf:
    // 0043c5bf  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c5c1  8b15389a7400           -mov edx, dword ptr [0x749a38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c5c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c5c8  6800002d3f             -push 0x3f2d0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059913728 /*0x3f2d0000*/;
    cpu.esp -= 4;
    // 0043c5cd  680000583f             -push 0x3f580000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062731776 /*0x3f580000*/;
    cpu.esp -= 4;
    // 0043c5d2  6800002d3f             -push 0x3f2d0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1059913728 /*0x3f2d0000*/;
    cpu.esp -= 4;
    // 0043c5d7  6800006b3f             -push 0x3f6b0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1063976960 /*0x3f6b0000*/;
    cpu.esp -= 4;
    // 0043c5dc  680000173f             -push 0x3f170000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058471936 /*0x3f170000*/;
    cpu.esp -= 4;
    // 0043c5e1  6800006b3f             -push 0x3f6b0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1063976960 /*0x3f6b0000*/;
    cpu.esp -= 4;
    // 0043c5e6  680000173f             -push 0x3f170000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058471936 /*0x3f170000*/;
    cpu.esp -= 4;
    // 0043c5eb  8d4716                 -lea eax, [edi + 0x16]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 0043c5ee  680000583f             -push 0x3f580000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062731776 /*0x3f580000*/;
    cpu.esp -= 4;
    // 0043c5f3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c5f4  8d5e13                 -lea ebx, [esi + 0x13]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(19) /* 0x13 */);
    // 0043c5f7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043c5f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c5f9  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0043c5fb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c5fc  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043c5fe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043c600  e8fbe90900             -call 0x4db000
    cpu.esp -= 4;
    sub_4db000(app, cpu);
    if (cpu.terminate) return;
    // 0043c605  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c607  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c608  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c609  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c60a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0043c60d:
    // 0043c60d  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043c60f  8b0d389a7400           -mov ecx, dword ptr [0x749a38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7641656) /* 0x749a38 */);
    // 0043c615  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043c616  680000173f             -push 0x3f170000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058471936 /*0x3f170000*/;
    cpu.esp -= 4;
    // 0043c61b  6800006c3f             -push 0x3f6c0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064042496 /*0x3f6c0000*/;
    cpu.esp -= 4;
    // 0043c620  680000173f             -push 0x3f170000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058471936 /*0x3f170000*/;
    cpu.esp -= 4;
    // 0043c625  6800007f3f             -push 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065287680 /*0x3f7f0000*/;
    cpu.esp -= 4;
    // 0043c62a  680000013f             -push 0x3f010000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1057030144 /*0x3f010000*/;
    cpu.esp -= 4;
    // 0043c62f  6800007f3f             -push 0x3f7f0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065287680 /*0x3f7f0000*/;
    cpu.esp -= 4;
    // 0043c634  680000013f             -push 0x3f010000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1057030144 /*0x3f010000*/;
    cpu.esp -= 4;
    // 0043c639  8d4716                 -lea eax, [edi + 0x16]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 0043c63c  6800006c3f             -push 0x3f6c0000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064042496 /*0x3f6c0000*/;
    cpu.esp -= 4;
L_0x0043c641:
    // 0043c641  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c642  8d5e13                 -lea ebx, [esi + 0x13]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(19) /* 0x13 */);
L_0x0043c645:
    // 0043c645  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043c646  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c647  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043c649  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c64a  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0043c64c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043c64e  e8ade90900             -call 0x4db000
    cpu.esp -= 4;
    sub_4db000(app, cpu);
    if (cpu.terminate) return;
    // 0043c653  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c655  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c656  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c657  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c658  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0043c65b:
    // 0043c65b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c65c  b857000000             -mov eax, 0x57
    cpu.eax = 87 /*0x57*/;
    // 0043c661  e8ea510900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043c666  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c667  6850775300             -push 0x537750
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470032 /*0x537750*/;
    cpu.esp -= 4;
    // 0043c66c  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c66f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c670  e81b300a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043c675  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043c678  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043c67b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c67c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043c67f  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c682  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c683  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043c685  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043c687  e8045b0100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043c68c  a1983d5f00             -mov eax, dword ptr [0x5f3d98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */);
    // 0043c691  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0043c694  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043c697  8b0445363d5f00         -mov eax, dword ptr [eax*2 + 0x5f3d36]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241590) /* 0x5f3d36 */ + cpu.eax * 2);
    // 0043c69e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043c6a0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043c6a3  e8e8b20900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 0043c6a8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c6aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c6ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c6ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c6ad  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0043c6b0:
    // 0043c6b0  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c6b3  c1e81c                 -shr eax, 0x1c
    cpu.eax >>= 28 /*0x1c*/ % 32;
    // 0043c6b6  40                     -inc eax
    (cpu.eax)++;
    // 0043c6b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c6b8  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 0043c6bd  e88e510900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043c6c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c6c3  6848775300             -push 0x537748
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470024 /*0x537748*/;
    cpu.esp -= 4;
    // 0043c6c8  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c6cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c6cc  e8bf2f0a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043c6d1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043c6d4  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043c6d7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c6d8  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043c6db  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043c6dd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043c6df  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c6e2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043c6e4  e8a75a0100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043c6e9  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c6ec  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043c6ef  c1e80c                 -shr eax, 0xc
    cpu.eax >>= 12 /*0xc*/ % 32;
    // 0043c6f2  83c041                 -add eax, 0x41
    (cpu.eax) += x86::reg32(x86::sreg32(65 /*0x41*/));
    // 0043c6f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c6f6  b855000000             -mov eax, 0x55
    cpu.eax = 85 /*0x55*/;
    // 0043c6fb  8b0d983d5f00           -mov ecx, dword ptr [0x5f3d98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */);
    // 0043c701  e84a510900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043c706  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c707  6850775300             -push 0x537750
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470032 /*0x537750*/;
    cpu.esp -= 4;
    // 0043c70c  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c70f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c710  e87b2f0a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043c715  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043c718  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043c71b  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043c71d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c71e  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043c721  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043c723  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043c725  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c728  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043c72a  e8615a0100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043c72f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c731  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c732  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c733  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c734  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0043c737:
    // 0043c737  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c73a  c1e81c                 -shr eax, 0x1c
    cpu.eax >>= 28 /*0x1c*/ % 32;
    // 0043c73d  40                     -inc eax
    (cpu.eax)++;
    // 0043c73e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c73f  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 0043c744  e807510900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043c749  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c74a  6848775300             -push 0x537748
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470024 /*0x537748*/;
    cpu.esp -= 4;
    // 0043c74f  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c752  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c753  e8382f0a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043c758  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043c75b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043c75e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c75f  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043c762  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043c764  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043c766  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043c768  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c76b  e8205a0100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043c770  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c773  c1e00c                 -shl eax, 0xc
    cpu.eax <<= 12 /*0xc*/ % 32;
    // 0043c776  c1e814                 -shr eax, 0x14
    cpu.eax >>= 20 /*0x14*/ % 32;
    // 0043c779  8b15983d5f00           -mov edx, dword ptr [0x5f3d98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */);
    // 0043c77f  48                     -dec eax
    (cpu.eax)--;
    // 0043c780  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043c782  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0043c789  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043c78b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043c78d  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0043c790  29c2                   +sub edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043c792  7405                   -je 0x43c799
    if (cpu.flags.zf)
    {
        goto L_0x0043c799;
    }
    // 0043c794  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 0043c797  eb07                   -jmp 0x43c7a0
    goto L_0x0043c7a0;
L_0x0043c799:
    // 0043c799  c745ec68010000         -mov dword ptr [ebp - 0x14], 0x168
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 360 /*0x168*/;
L_0x0043c7a0:
    // 0043c7a0  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c7a3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043c7a6  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0043c7a9  8b1d34925500           -mov ebx, dword ptr [0x559234]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 0043c7af  83c031                 -add eax, 0x31
    (cpu.eax) += x86::reg32(x86::sreg32(49 /*0x31*/));
    // 0043c7b2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043c7b4  7443                   -je 0x43c7f9
    if (cpu.flags.zf)
    {
        goto L_0x0043c7f9;
    }
    // 0043c7b6  6858775300             -push 0x537758
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470040 /*0x537758*/;
    cpu.esp -= 4;
    // 0043c7bb  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043c7be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c7bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c7c0  b856000000             -mov eax, 0x56
    cpu.eax = 86 /*0x56*/;
    // 0043c7c5  e886500900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043c7ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c7cb  685c775300             -push 0x53775c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470044 /*0x53775c*/;
    cpu.esp -= 4;
    // 0043c7d0  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c7d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c7d4  e8b72e0a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043c7d9  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0043c7dc  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043c7df  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043c7e0  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043c7e2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043c7e4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043c7e6  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c7e9  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043c7ec  e89f590100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043c7f1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c7f3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c7f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c7f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c7f6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0043c7f9:
    // 0043c7f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c7fa  b856000000             -mov eax, 0x56
    cpu.eax = 86 /*0x56*/;
    // 0043c7ff  e84c500900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043c804  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c805  6850775300             -push 0x537750
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470032 /*0x537750*/;
    cpu.esp -= 4;
    // 0043c80a  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c80d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c80e  e87d2e0a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043c813  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043c816  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043c819  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c81a  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043c81d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043c81f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043c821  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c824  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043c826  e865590100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043c82b  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0043c830  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043c833  a1983d5f00             -mov eax, dword ptr [0x5f3d98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */);
    // 0043c838  8d5f0c                 -lea ebx, [edi + 0xc]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0043c83b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043c83d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c83e  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043c840  a1443d5f00             -mov eax, dword ptr [0x5f3d44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241604) /* 0x5f3d44 */);
    // 0043c845  8d560c                 -lea edx, [esi + 0xc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043c848  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043c84b  e8e09e0900             -call 0x4d6730
    cpu.esp -= 4;
    sub_4d6730(app, cpu);
    if (cpu.terminate) return;
    // 0043c850  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c852  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c853  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c854  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c855  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0043c858:
    // 0043c858  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043c85b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043c85c  b853000000             -mov eax, 0x53
    cpu.eax = 83 /*0x53*/;
    // 0043c861  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043c863  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043c865  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043c867  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043c86a  e8e14f0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043c86f  e81c590100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043c874  8d559c                 -lea edx, [ebp - 0x64]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c877  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043c87a  8b1d983d5f00           -mov ebx, dword ptr [0x5f3d98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */);
    // 0043c880  e86b0f0000             -call 0x43d7f0
    cpu.esp -= 4;
    sub_43d7f0(app, cpu);
    if (cpu.terminate) return;
    // 0043c885  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043c888  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043c88b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043c88c  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043c88e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043c890  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043c892  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043c894  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 0043c897  e8f4580100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043c89c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c89e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c89f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c8a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c8a1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0043c8a4:
    // 0043c8a4  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043c8a7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043c8a8  b852000000             -mov eax, 0x52
    cpu.eax = 82 /*0x52*/;
    // 0043c8ad  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043c8b0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043c8b2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043c8b4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043c8b6  e8954f0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043c8bb  e8d0580100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x0043c8c0:
    // 0043c8c0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043c8c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c8c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c8c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043c8c5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_43c900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0043c900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043c901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043c902  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043c903  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043c904  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043c905  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043c907  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0043c90a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043c90c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043c90e  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0043c913  e848dd0000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043c918  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043c91a  0f846a040000           -je 0x43cd8a
    if (cpu.flags.zf)
    {
        goto L_0x0043cd8a;
    }
    // 0043c920  8b4106                 -mov eax, dword ptr [ecx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0043c923  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043c926  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0043c928  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043c92b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043c92d  0f840f010000           -je 0x43ca42
    if (cpu.flags.zf)
    {
        goto L_0x0043ca42;
    }
    // 0043c933  833d4056550000         +cmp dword ptr [0x555640], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5592640) /* 0x555640 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c93a  0f85f6000000           -jne 0x43ca36
    if (!cpu.flags.zf)
    {
        goto L_0x0043ca36;
    }
    // 0043c940  8b0d4c466600           -mov ecx, dword ptr [0x66464c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6702668) /* 0x66464c */);
    // 0043c946  81f900480000           +cmp ecx, 0x4800
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18432 /*0x4800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c94c  7408                   -je 0x43c956
    if (cpu.flags.zf)
    {
        goto L_0x0043c956;
    }
    // 0043c94e  81f9004b0000           +cmp ecx, 0x4b00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19200 /*0x4b00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c954  7574                   -jne 0x43c9ca
    if (!cpu.flags.zf)
    {
        goto L_0x0043c9ca;
    }
L_0x0043c956:
    // 0043c956  8b1508565500           -mov edx, dword ptr [0x555608]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043c95c  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 0043c963  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043c965  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043c967  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043c96a  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043c96c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043c96e  8b15b0d36f00           -mov edx, dword ptr [0x6fd3b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043c974  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0043c977  83fa01                 +cmp edx, 1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c97a  7527                   -jne 0x43c9a3
    if (!cpu.flags.zf)
    {
        goto L_0x0043c9a3;
    }
    // 0043c97c  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043c97f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043c982  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043c984  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0043c987  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043c98a  8b0d9c3d5f00           -mov ecx, dword ptr [0x5f3d9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */);
    // 0043c990  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043c993  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043c995  0305983d5f00           -add eax, dword ptr [0x5f3d98]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */)));
    // 0043c99b  0305a03d5f00           +add eax, dword ptr [0x5f3da0]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6241696) /* 0x5f3da0 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043c9a1  eb1f                   -jmp 0x43c9c2
    goto L_0x0043c9c2;
L_0x0043c9a3:
    // 0043c9a3  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043c9a6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043c9a9  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043c9ab  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0043c9ae  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043c9b1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043c9b4  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 0043c9b7  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0043c9ba  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043c9bd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043c9c0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0043c9c2:
    // 0043c9c2  83e80a                 -sub eax, 0xa
    (cpu.eax) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043c9c5  e8f6f50500             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
L_0x0043c9ca:
    // 0043c9ca  a14c466600             -mov eax, dword ptr [0x66464c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702668) /* 0x66464c */);
    // 0043c9cf  3d00500000             +cmp eax, 0x5000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20480 /*0x5000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c9d4  7407                   -je 0x43c9dd
    if (cpu.flags.zf)
    {
        goto L_0x0043c9dd;
    }
    // 0043c9d6  3d004d0000             +cmp eax, 0x4d00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19712 /*0x4d00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c9db  7559                   -jne 0x43ca36
    if (!cpu.flags.zf)
    {
        goto L_0x0043ca36;
    }
L_0x0043c9dd:
    // 0043c9dd  a108565500             -mov eax, dword ptr [0x555608]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043c9e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043c9e4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043c9e7  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043c9e9  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043c9eb  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043c9f2  751e                   -jne 0x43ca12
    if (!cpu.flags.zf)
    {
        goto L_0x0043ca12;
    }
    // 0043c9f4  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043c9f7  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043c9fa  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043c9fc  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043c9ff  8b0d9c3d5f00           -mov ecx, dword ptr [0x5f3d9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */);
    // 0043ca05  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043ca08  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043ca0a  0305983d5f00           +add eax, dword ptr [0x5f3d98]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043ca10  eb1c                   -jmp 0x43ca2e
    goto L_0x0043ca2e;
L_0x0043ca12:
    // 0043ca12  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043ca15  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043ca18  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ca1a  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043ca1d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043ca20  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 0043ca23  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0043ca26  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043ca29  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043ca2c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0043ca2e:
    // 0043ca2e  83e80a                 +sub eax, 0xa
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043ca31  e88af50500             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
L_0x0043ca36:
    // 0043ca36  c7054056550001000000   -mov dword ptr [0x555640], 1
    app->getMemory<x86::reg32>(x86::reg32(5592640) /* 0x555640 */) = 1 /*0x1*/;
    // 0043ca40  eb08                   -jmp 0x43ca4a
    goto L_0x0043ca4a;
L_0x0043ca42:
    // 0043ca42  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043ca44  891540565500           -mov dword ptr [0x555640], edx
    app->getMemory<x86::reg32>(x86::reg32(5592640) /* 0x555640 */) = cpu.edx;
L_0x0043ca4a:
    // 0043ca4a  66837e3cff             +cmp word ptr [esi + 0x3c], -1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(60) /* 0x3c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(-1 /*-0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ca4f  0f8485000000           -je 0x43cada
    if (cpu.flags.zf)
    {
        goto L_0x0043cada;
    }
    // 0043ca55  a1943d5f00             -mov eax, dword ptr [0x5f3d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241684) /* 0x5f3d94 */);
    // 0043ca5a  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0043ca5d  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0043ca60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ca62  7525                   -jne 0x43ca89
    if (!cpu.flags.zf)
    {
        goto L_0x0043ca89;
    }
    // 0043ca64  e8d7f3ffff             -call 0x43be40
    cpu.esp -= 4;
    sub_43be40(app, cpu);
    if (cpu.terminate) return;
    // 0043ca69  a3943d5f00             -mov dword ptr [0x5f3d94], eax
    app->getMemory<x86::reg32>(x86::reg32(6241684) /* 0x5f3d94 */) = cpu.eax;
    // 0043ca6e  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0043ca71  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0043ca74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ca76  7411                   -je 0x43ca89
    if (cpu.flags.zf)
    {
        goto L_0x0043ca89;
    }
    // 0043ca78  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 0043ca7d  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0043ca82  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043ca84  e857fe0800             -call 0x4cc8e0
    cpu.esp -= 4;
    sub_4cc8e0(app, cpu);
    if (cpu.terminate) return;
L_0x0043ca89:
    // 0043ca89  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ca90  7418                   -je 0x43caaa
    if (cpu.flags.zf)
    {
        goto L_0x0043caaa;
    }
    // 0043ca92  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 0043ca97  b845000000             -mov eax, 0x45
    cpu.eax = 69 /*0x45*/;
    // 0043ca9c  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0043caa1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0043caa3  bb41000000             -mov ebx, 0x41
    cpu.ebx = 65 /*0x41*/;
    // 0043caa8  eb16                   -jmp 0x43cac0
    goto L_0x0043cac0;
L_0x0043caaa:
    // 0043caaa  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 0043caaf  b845000000             -mov eax, 0x45
    cpu.eax = 69 /*0x45*/;
    // 0043cab4  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0043cab9  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0043cabb  bb55000000             -mov ebx, 0x55
    cpu.ebx = 85 /*0x55*/;
L_0x0043cac0:
    // 0043cac0  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 0043cac5  e8864d0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043caca  e8c1560100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043cacf  8b463a                 -mov eax, dword ptr [esi + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(58) /* 0x3a */);
    // 0043cad2  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0043cad5  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0043cad8  eb55                   -jmp 0x43cb2f
    goto L_0x0043cb2f;
L_0x0043cada:
    // 0043cada  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043cadc  744a                   -je 0x43cb28
    if (cpu.flags.zf)
    {
        goto L_0x0043cb28;
    }
    // 0043cade  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0043cae1  8b1508565500           -mov edx, dword ptr [0x555608]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043cae7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043caea  e8d1f60500             -call 0x49c1c0
    cpu.esp -= 4;
    sub_49c1c0(app, cpu);
    if (cpu.terminate) return;
    // 0043caef  8b1db0d36f00           -mov ebx, dword ptr [0x6fd3b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043caf5  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0043caf8  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cafb  7532                   -jne 0x43cb2f
    if (!cpu.flags.zf)
    {
        goto L_0x0043cb2f;
    }
    // 0043cafd  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043cb00  8b0d9c3d5f00           -mov ecx, dword ptr [0x5f3d9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */);
    // 0043cb06  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043cb09  8b1d983d5f00           -mov ebx, dword ptr [0x5f3d98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */);
    // 0043cb0f  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043cb11  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043cb13  8b0de4e55500           -mov ecx, dword ptr [0x55e5e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 0043cb19  83c228                 -add edx, 0x28
    (cpu.edx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0043cb1c  39ca                   +cmp edx, ecx
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
    // 0043cb1e  7d0f                   -jge 0x43cb2f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043cb2f;
    }
    // 0043cb20  83c00d                 +add eax, 0xd
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043cb23  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0043cb26  eb07                   -jmp 0x43cb2f
    goto L_0x0043cb2f;
L_0x0043cb28:
    // 0043cb28  c745f4ffffffff         -mov dword ptr [ebp - 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 4294967295 /*0xffffffff*/;
L_0x0043cb2f:
    // 0043cb2f  a1b0d36f00             -mov eax, dword ptr [0x6fd3b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043cb34  e897390500             -call 0x4904d0
    cpu.esp -= 4;
    sub_4904d0(app, cpu);
    if (cpu.terminate) return;
    // 0043cb39  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0043cb3c  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 0043cb41  e80a4d0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043cb46  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043cb47  686c775300             -push 0x53776c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470060 /*0x53776c*/;
    cpu.esp -= 4;
    // 0043cb4c  8d45b4                 -lea eax, [ebp - 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0043cb4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043cb50  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0043cb55  e8362b0a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043cb5a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043cb5d  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043cb60  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043cb63  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043cb66  68fd9d64ff             -push 0xff649dfd
    app->getMemory<x86::reg32>(cpu.esp-4) = 4284784125 /*0xff649dfd*/;
    cpu.esp -= 4;
    // 0043cb6b  8d58e2                 -lea ebx, [eax - 0x1e]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-30) /* -0x1e */);
    // 0043cb6e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043cb71  a19c3d5f00             -mov eax, dword ptr [0x5f3d9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */);
    // 0043cb76  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043cb78  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043cb7a  8d45b4                 -lea eax, [ebp - 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0043cb7d  e80e560100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043cb82  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cb89  754f                   -jne 0x43cbda
    if (!cpu.flags.zf)
    {
        goto L_0x0043cbda;
    }
    // 0043cb8b  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 0043cb90  e8bb4c0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043cb95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043cb96  6874775300             -push 0x537774
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470068 /*0x537774*/;
    cpu.esp -= 4;
    // 0043cb9b  8d45b4                 -lea eax, [ebp - 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0043cb9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043cb9f  e8ec2a0a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043cba4  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043cba7  8b0da03d5f00           -mov ecx, dword ptr [0x5f3da0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241696) /* 0x5f3da0 */);
    // 0043cbad  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043cbb0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043cbb3  8d58e2                 -lea ebx, [eax - 0x1e]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-30) /* -0x1e */);
    // 0043cbb6  8b159c3d5f00           -mov edx, dword ptr [0x5f3d9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */);
    // 0043cbbc  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043cbbf  68fd9d64ff             -push 0xff649dfd
    app->getMemory<x86::reg32>(cpu.esp-4) = 4284784125 /*0xff649dfd*/;
    cpu.esp -= 4;
    // 0043cbc4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043cbc7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043cbc9  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043cbcb  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0043cbd0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043cbd2  8d45b4                 -lea eax, [ebp - 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0043cbd5  e8b6550100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x0043cbda:
    // 0043cbda  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0043cbdc  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0043cbdf  e991010000             -jmp 0x43cd75
    goto L_0x0043cd75;
  case 0x0043cbe4:
    // 0043cbe4  bf46000000             -mov edi, 0x46
    cpu.edi = 70 /*0x46*/;
    // 0043cbe9  eb52                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cbeb:
    // 0043cbeb  bf47000000             -mov edi, 0x47
    cpu.edi = 71 /*0x47*/;
    // 0043cbf0  eb4b                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cbf2:
    // 0043cbf2  bf48000000             -mov edi, 0x48
    cpu.edi = 72 /*0x48*/;
    // 0043cbf7  eb44                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cbf9:
    // 0043cbf9  bf49000000             -mov edi, 0x49
    cpu.edi = 73 /*0x49*/;
    // 0043cbfe  eb3d                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cc00:
    // 0043cc00  bf4e000000             -mov edi, 0x4e
    cpu.edi = 78 /*0x4e*/;
    // 0043cc05  eb36                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cc07:
    // 0043cc07  bf4d000000             -mov edi, 0x4d
    cpu.edi = 77 /*0x4d*/;
    // 0043cc0c  eb2f                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cc0e:
    // 0043cc0e  bf4a000000             -mov edi, 0x4a
    cpu.edi = 74 /*0x4a*/;
    // 0043cc13  eb28                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cc15:
    // 0043cc15  bf4f000000             -mov edi, 0x4f
    cpu.edi = 79 /*0x4f*/;
    // 0043cc1a  eb21                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cc1c:
    // 0043cc1c  bf4b000000             -mov edi, 0x4b
    cpu.edi = 75 /*0x4b*/;
    // 0043cc21  eb1a                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cc23:
    // 0043cc23  bf4c000000             -mov edi, 0x4c
    cpu.edi = 76 /*0x4c*/;
    // 0043cc28  eb13                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cc2a:
    // 0043cc2a  bf50000000             -mov edi, 0x50
    cpu.edi = 80 /*0x50*/;
    // 0043cc2f  eb0c                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cc31:
    // 0043cc31  bf51000000             -mov edi, 0x51
    cpu.edi = 81 /*0x51*/;
    // 0043cc36  eb05                   -jmp 0x43cc3d
    goto L_0x0043cc3d;
  case 0x0043cc38:
    // 0043cc38  bfbc010000             -mov edi, 0x1bc
    cpu.edi = 444 /*0x1bc*/;
L_0x0043cc3d:
    // 0043cc3d  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cc44  7562                   -jne 0x43cca8
    if (!cpu.flags.zf)
    {
        goto L_0x0043cca8;
    }
    // 0043cc46  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043cc49  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043cc4c  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043cc4f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043cc52  8b0c850c565500         -mov ecx, dword ptr [eax*4 + 0x55560c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5592588) /* 0x55560c */ + cpu.eax * 4);
    // 0043cc59  a1a83d5f00             -mov eax, dword ptr [0x5f3da8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241704) /* 0x5f3da8 */);
    // 0043cc5e  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043cc60  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043cc63  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0043cc65  e826ad0900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 0043cc6a  8b463a                 -mov eax, dword ptr [esi + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(58) /* 0x3a */);
    // 0043cc6d  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043cc70  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043cc73  39d8                   +cmp eax, ebx
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
    // 0043cc75  7531                   -jne 0x43cca8
    if (!cpu.flags.zf)
    {
        goto L_0x0043cca8;
    }
    // 0043cc77  a144565500             -mov eax, dword ptr [0x555644]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592644) /* 0x555644 */);
    // 0043cc7c  40                     -inc eax
    (cpu.eax)++;
    // 0043cc7d  a344565500             -mov dword ptr [0x555644], eax
    app->getMemory<x86::reg32>(x86::reg32(5592644) /* 0x555644 */) = cpu.eax;
    // 0043cc82  83f81e                 +cmp eax, 0x1e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cc85  7e0a                   -jle 0x43cc91
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043cc91;
    }
    // 0043cc87  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0043cc89  890d44565500           -mov dword ptr [0x555644], ecx
    app->getMemory<x86::reg32>(x86::reg32(5592644) /* 0x555644 */) = cpu.ecx;
    // 0043cc8f  eb17                   -jmp 0x43cca8
    goto L_0x0043cca8;
L_0x0043cc91:
    // 0043cc91  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cc94  7e12                   -jle 0x43cca8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043cca8;
    }
    // 0043cc96  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043cc99  a1a63d5f00             -mov eax, dword ptr [0x5f3da6]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241702) /* 0x5f3da6 */);
    // 0043cc9e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0043cca0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043cca3  e8e8ac0900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x0043cca8:
    // 0043cca8  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043ccab  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043ccae  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043ccb1  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0043ccb4  3b55f4                 +cmp edx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ccb7  7507                   -jne 0x43ccc0
    if (!cpu.flags.zf)
    {
        goto L_0x0043ccc0;
    }
    // 0043ccb9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043ccbe  eb02                   -jmp 0x43ccc2
    goto L_0x0043ccc2;
L_0x0043ccc0:
    // 0043ccc0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043ccc2:
    // 0043ccc2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043ccc3  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043ccc6  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043ccc9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043cccc  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043ccce  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043ccd1  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043ccd4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0043ccd6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043ccd8  e833f4ffff             -call 0x43c110
    cpu.esp -= 4;
    sub_43c110(app, cpu);
    if (cpu.terminate) return;
    // 0043ccdd  8b1db0d36f00           -mov ebx, dword ptr [0x6fd3b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043cce3  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cce6  7537                   -jne 0x43cd1f
    if (!cpu.flags.zf)
    {
        goto L_0x0043cd1f;
    }
    // 0043cce8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043cceb  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043ccee  83c00d                 -add eax, 0xd
    (cpu.eax) += x86::reg32(x86::sreg32(13 /*0xd*/));
    // 0043ccf1  39d0                   +cmp eax, edx
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
    // 0043ccf3  7504                   -jne 0x43ccf9
    if (!cpu.flags.zf)
    {
        goto L_0x0043ccf9;
    }
    // 0043ccf5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043ccf7  eb02                   -jmp 0x43ccfb
    goto L_0x0043ccfb;
L_0x0043ccf9:
    // 0043ccf9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043ccfb:
    // 0043ccfb  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043ccfe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043ccff  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043cd02  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043cd05  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043cd08  8b0da03d5f00           -mov ecx, dword ptr [0x5f3da0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241696) /* 0x5f3da0 */);
    // 0043cd0e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043cd10  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043cd12  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043cd15  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0043cd18  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043cd1a  e8f1f3ffff             -call 0x43c110
    cpu.esp -= 4;
    sub_43c110(app, cpu);
    if (cpu.terminate) return;
L_0x0043cd1f:
    // 0043cd1f  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cd26  7515                   -jne 0x43cd3d
    if (!cpu.flags.zf)
    {
        goto L_0x0043cd3d;
    }
    // 0043cd28  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043cd2b  8b04850c565500         -mov eax, dword ptr [eax*4 + 0x55560c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592588) /* 0x55560c */ + cpu.eax * 4);
    // 0043cd32  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043cd35  83c00e                 -add eax, 0xe
    (cpu.eax) += x86::reg32(x86::sreg32(14 /*0xe*/));
    // 0043cd38  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043cd3a  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
L_0x0043cd3d:
    // 0043cd3d  68fd9d64ff             -push 0xff649dfd
    app->getMemory<x86::reg32>(cpu.esp-4) = 4284784125 /*0xff649dfd*/;
    cpu.esp -= 4;
    // 0043cd42  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0043cd47  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043cd4a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043cd4c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043cd4e  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043cd51  e8fa4a0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043cd56  e835540100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043cd5b  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043cd5e  a108565500             -mov eax, dword ptr [0x555608]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043cd63  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043cd66  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043cd68  41                     -inc ecx
    (cpu.ecx)++;
    // 0043cd69  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0043cd6c  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0043cd6f  837dfc0d               +cmp dword ptr [ebp - 4], 0xd
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cd73  7d15                   -jge 0x43cd8a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043cd8a;
    }
L_0x0043cd75:
    // 0043cd75  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043cd78  83fa0c                 +cmp edx, 0xc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cd7b  0f87bcfeffff           -ja 0x43cc3d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0043cc3d;
    }
    // 0043cd81  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043cd83  ff2485c8c84300         -jmp dword ptr [eax*4 + 0x43c8c8]
    cpu.ip = app->getMemory<x86::reg32>(4442312 + cpu.eax * 4); goto dynamic_jump;
L_0x0043cd8a:
    // 0043cd8a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043cd8c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043cd8e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043cd90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cd91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cd92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cd93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cd94  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cd95  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_43cda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043cda0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043cda1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043cda2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043cda3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043cda4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043cda6  8b155c466600           -mov edx, dword ptr [0x66465c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6702684) /* 0x66465c */);
    // 0043cdac  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043cdae  83fa4a                 +cmp edx, 0x4a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(74 /*0x4a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cdb1  0f8466000000           -je 0x43ce1d
    if (cpu.flags.zf)
    {
        goto L_0x0043ce1d;
    }
    // 0043cdb7  83fa4e                 +cmp edx, 0x4e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(78 /*0x4e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cdba  0f845d000000           -je 0x43ce1d
    if (cpu.flags.zf)
    {
        goto L_0x0043ce1d;
    }
    // 0043cdc0  83fa37                 +cmp edx, 0x37
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(55 /*0x37*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cdc3  0f8454000000           -je 0x43ce1d
    if (cpu.flags.zf)
    {
        goto L_0x0043ce1d;
    }
    // 0043cdc9  83fa35                 +cmp edx, 0x35
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(53 /*0x35*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cdcc  744f                   -je 0x43ce1d
    if (cpu.flags.zf)
    {
        goto L_0x0043ce1d;
    }
    // 0043cdce  83fa02                 +cmp edx, 2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cdd1  7c05                   -jl 0x43cdd8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043cdd8;
    }
    // 0043cdd3  83fa0b                 +cmp edx, 0xb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cdd6  7e45                   -jle 0x43ce1d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ce1d;
    }
L_0x0043cdd8:
    // 0043cdd8  8b1d5c466600           -mov ebx, dword ptr [0x66465c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6702684) /* 0x66465c */);
    // 0043cdde  83fb3b                 +cmp ebx, 0x3b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(59 /*0x3b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cde1  7c05                   -jl 0x43cde8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043cde8;
    }
    // 0043cde3  83fb44                 +cmp ebx, 0x44
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cde6  7e35                   -jle 0x43ce1d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ce1d;
    }
L_0x0043cde8:
    // 0043cde8  833d5c466600ff         +cmp dword ptr [0x66465c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6702684) /* 0x66465c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cdef  742c                   -je 0x43ce1d
    if (cpu.flags.zf)
    {
        goto L_0x0043ce1d;
    }
    // 0043cdf1  83f820                 +cmp eax, 0x20
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cdf4  7c27                   -jl 0x43ce1d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043ce1d;
    }
    // 0043cdf6  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 0043cdf8  fec3                   -inc bl
    (cpu.bl)++;
    // 0043cdfa  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043ce00  f683f04e560020         +test byte ptr [ebx + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0043ce07  7514                   -jne 0x43ce1d
    if (!cpu.flags.zf)
    {
        goto L_0x0043ce1d;
    }
    // 0043ce09  e8d21f0b00             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 0043ce0e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043ce10  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043ce12  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 0043ce15  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0043ce18  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043ce1a  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0043ce1d:
    // 0043ce1d  a1943d5f00             -mov eax, dword ptr [0x5f3d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241684) /* 0x5f3d94 */);
    // 0043ce22  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0043ce25  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0043ce28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ce2a  740d                   -je 0x43ce39
    if (cpu.flags.zf)
    {
        goto L_0x0043ce39;
    }
    // 0043ce2c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043ce2e  8b0d943d5f00           -mov ecx, dword ptr [0x5f3d94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241684) /* 0x5f3d94 */);
    // 0043ce34  a3943d5f00             -mov dword ptr [0x5f3d94], eax
    app->getMemory<x86::reg32>(x86::reg32(6241684) /* 0x5f3d94 */) = cpu.eax;
L_0x0043ce39:
    // 0043ce39  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ce3b  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0043ce3e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0043ce41  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ce43  7416                   -je 0x43ce5b
    if (cpu.flags.zf)
    {
        goto L_0x0043ce5b;
    }
    // 0043ce45  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0043ce4a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043ce4f  e87cb3fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ce54  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ce56  e845080000             -call 0x43d6a0
    cpu.esp -= 4;
    sub_43d6a0(app, cpu);
    if (cpu.terminate) return;
L_0x0043ce5b:
    // 0043ce5b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ce5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ce5e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ce5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ce60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ce61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_43ce80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0043ce80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043ce81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ce82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ce83  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ce85  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043ce87  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043ce89  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ce90  0f84dd000000           -je 0x43cf73
    if (cpu.flags.zf)
    {
        goto L_0x0043cf73;
    }
    // 0043ce96  83f90d                 +cmp ecx, 0xd
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ce99  7d04                   -jge 0x43ce9f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ce9f;
    }
    // 0043ce9b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0043ce9d  eb03                   -jmp 0x43cea2
    goto L_0x0043cea2;
L_0x0043ce9f:
    // 0043ce9f  8d51f3                 -lea edx, [ecx - 0xd]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-13) /* -0xd */);
L_0x0043cea2:
    // 0043cea2  83fa03                 +cmp edx, 3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cea5  0f87c8000000           -ja 0x43cf73
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0043cf73;
    }
    // 0043ceab  ff249564ce4300         -jmp dword ptr [edx*4 + 0x43ce64]
    cpu.ip = app->getMemory<x86::reg32>(4443748 + cpu.edx * 4); goto dynamic_jump;
  case 0x0043ceb2:
    // 0043ceb2  83f90d                 +cmp ecx, 0xd
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ceb5  7d15                   -jge 0x43cecc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043cecc;
    }
    // 0043ceb7  e844f1ffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043cebc  3b05dcd26f00           +cmp eax, dword ptr [0x6fd2dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328476) /* 0x6fd2dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cec2  0f8563000000           -jne 0x43cf2b
    if (!cpu.flags.zf)
    {
        goto L_0x0043cf2b;
    }
    // 0043cec8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cec9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ceca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cecb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043cecc:
    // 0043cecc  e82ff1ffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043ced1  3b0548d36f00           +cmp eax, dword ptr [0x6fd348]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328584) /* 0x6fd348 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ced7  7552                   -jne 0x43cf2b
    if (!cpu.flags.zf)
    {
        goto L_0x0043cf2b;
    }
    // 0043ced9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ceda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cedb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cedc  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0043cedd:
    // 0043cedd  83f90d                 +cmp ecx, 0xd
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cee0  7d11                   -jge 0x43cef3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043cef3;
    }
    // 0043cee2  e819f1ffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043cee7  3b05e0d26f00           +cmp eax, dword ptr [0x6fd2e0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328480) /* 0x6fd2e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ceed  753c                   -jne 0x43cf2b
    if (!cpu.flags.zf)
    {
        goto L_0x0043cf2b;
    }
    // 0043ceef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cef0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cef1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cef2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043cef3:
    // 0043cef3  e808f1ffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043cef8  3b054cd36f00           +cmp eax, dword ptr [0x6fd34c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328588) /* 0x6fd34c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cefe  752b                   -jne 0x43cf2b
    if (!cpu.flags.zf)
    {
        goto L_0x0043cf2b;
    }
    // 0043cf00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf03  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0043cf04:
    // 0043cf04  83f90d                 +cmp ecx, 0xd
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cf07  7d11                   -jge 0x43cf1a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043cf1a;
    }
    // 0043cf09  e8f2f0ffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043cf0e  3b05e4d26f00           +cmp eax, dword ptr [0x6fd2e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328484) /* 0x6fd2e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cf14  7515                   -jne 0x43cf2b
    if (!cpu.flags.zf)
    {
        goto L_0x0043cf2b;
    }
    // 0043cf16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043cf1a:
    // 0043cf1a  e8e1f0ffff             -call 0x43c000
    cpu.esp -= 4;
    sub_43c000(app, cpu);
    if (cpu.terminate) return;
    // 0043cf1f  3b0550d36f00           +cmp eax, dword ptr [0x6fd350]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328592) /* 0x6fd350 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cf25  7504                   -jne 0x43cf2b
    if (!cpu.flags.zf)
    {
        goto L_0x0043cf2b;
    }
    // 0043cf27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043cf2b:
    // 0043cf2b  b8f0010000             -mov eax, 0x1f0
    cpu.eax = 496 /*0x1f0*/;
    // 0043cf30  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0043cf35  e816490900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043cf3a  a3ac3d5f00             -mov dword ptr [0x5f3dac], eax
    app->getMemory<x86::reg32>(x86::reg32(6241708) /* 0x5f3dac */) = cpu.eax;
    // 0043cf3f  b8f1010000             -mov eax, 0x1f1
    cpu.eax = 497 /*0x1f1*/;
    // 0043cf44  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 0043cf49  e802490900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043cf4e  a3b03d5f00             -mov dword ptr [0x5f3db0], eax
    app->getMemory<x86::reg32>(x86::reg32(6241712) /* 0x5f3db0 */) = cpu.eax;
    // 0043cf53  b8f2010000             -mov eax, 0x1f2
    cpu.eax = 498 /*0x1f2*/;
    // 0043cf58  baac3d5f00             -mov edx, 0x5f3dac
    cpu.edx = 6241708 /*0x5f3dac*/;
    // 0043cf5d  e8ee480900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043cf62  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043cf64  a3b43d5f00             -mov dword ptr [0x5f3db4], eax
    app->getMemory<x86::reg32>(x86::reg32(6241716) /* 0x5f3db4 */) = cpu.eax;
    // 0043cf69  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0043cf6e  e80d7b0000             -call 0x444a80
    cpu.esp -= 4;
    sub_444a80(app, cpu);
    if (cpu.terminate) return;
L_0x0043cf73:
    // 0043cf73  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf76  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_43cf80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043cf80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043cf81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043cf82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043cf83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043cf84  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043cf86  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043cf89  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043cf8b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0043cf8d  a1b0d36f00             -mov eax, dword ptr [0x6fd3b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043cf92  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043cf94  e837350500             -call 0x4904d0
    cpu.esp -= 4;
    sub_4904d0(app, cpu);
    if (cpu.terminate) return;
    // 0043cf99  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0043cf9c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043cf9e  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043cfa1  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0043cfa6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043cfa8  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0043cfaa  e8b1d60000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043cfaf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043cfb1  0f84e4020000           -je 0x43d29b
    if (cpu.flags.zf)
    {
        goto L_0x0043d29b;
    }
    // 0043cfb7  6683793cff             +cmp word ptr [ecx + 0x3c], -1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(60) /* 0x3c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(-1 /*-0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043cfbc  0f857b020000           -jne 0x43d23d
    if (!cpu.flags.zf)
    {
        goto L_0x0043d23d;
    }
    // 0043cfc2  806105fb               -and byte ptr [ecx + 5], 0xfb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0043cfc6  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0043cfc9  8b1508565500           -mov edx, dword ptr [0x555608]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043cfcf  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043cfd2  e8e9f10500             -call 0x49c1c0
    cpu.esp -= 4;
    sub_49c1c0(app, cpu);
    if (cpu.terminate) return;
    // 0043cfd7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043cfd9  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cfe0  0f8535010000           -jne 0x43d11b
    if (!cpu.flags.zf)
    {
        goto L_0x0043d11b;
    }
    // 0043cfe6  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0043cfe9  8b15a03d5f00           -mov edx, dword ptr [0x5f3da0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6241696) /* 0x5f3da0 */);
    // 0043cfef  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043cff2  8b0d9c3d5f00           -mov ecx, dword ptr [0x5f3d9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */);
    // 0043cff8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043cffa  8b15e4e55500           -mov edx, dword ptr [0x55e5e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 0043d000  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d002  39d0                   +cmp eax, edx
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
    // 0043d004  7d03                   -jge 0x43d009
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d009;
    }
    // 0043d006  83c30d                 -add ebx, 0xd
    (cpu.ebx) += x86::reg32(x86::sreg32(13 /*0xd*/));
L_0x0043d009:
    // 0043d009  6681fe004b             +cmp si, 0x4b00
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043d00e  751c                   -jne 0x43d02c
    if (!cpu.flags.zf)
    {
        goto L_0x0043d02c;
    }
    // 0043d010  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d013  7c17                   -jl 0x43d02c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d02c;
    }
    // 0043d015  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0043d01a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d01c  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043d021  e8aab1fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043d026  83eb0d                 -sub ebx, 0xd
    (cpu.ebx) -= x86::reg32(x86::sreg32(13 /*0xd*/));
    // 0043d029  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x0043d02c:
    // 0043d02c  6681fe004d             +cmp si, 0x4d00
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043d031  751c                   -jne 0x43d04f
    if (!cpu.flags.zf)
    {
        goto L_0x0043d04f;
    }
    // 0043d033  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d036  7d17                   -jge 0x43d04f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d04f;
    }
    // 0043d038  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0043d03d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d03f  e88cb1fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043d044  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0043d049  83c30d                 -add ebx, 0xd
    (cpu.ebx) += x86::reg32(x86::sreg32(13 /*0xd*/));
    // 0043d04c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x0043d04f:
    // 0043d04f  6681fe0050             +cmp si, 0x5000
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20480 /*0x5000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043d054  7519                   -jne 0x43d06f
    if (!cpu.flags.zf)
    {
        goto L_0x0043d06f;
    }
    // 0043d056  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0043d05b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d05d  43                     -inc ebx
    (cpu.ebx)++;
    // 0043d05e  e86db1fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043d063  83fb1a                 +cmp ebx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d066  7d07                   -jge 0x43d06f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d06f;
    }
    // 0043d068  c745fc02000000         -mov dword ptr [ebp - 4], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 2 /*0x2*/;
L_0x0043d06f:
    // 0043d06f  6681fe0048             +cmp si, 0x4800
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18432 /*0x4800*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043d074  7519                   -jne 0x43d08f
    if (!cpu.flags.zf)
    {
        goto L_0x0043d08f;
    }
    // 0043d076  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0043d07b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d07d  e84eb1fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043d082  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043d084  7409                   -je 0x43d08f
    if (cpu.flags.zf)
    {
        goto L_0x0043d08f;
    }
    // 0043d086  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043d08b  4b                     -dec ebx
    (cpu.ebx)--;
    // 0043d08c  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x0043d08f:
    // 0043d08f  837dfc02               +cmp dword ptr [ebp - 4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d093  0f853e010000           -jne 0x43d1d7
    if (!cpu.flags.zf)
    {
        goto L_0x0043d1d7;
    }
    // 0043d099  a108565500             -mov eax, dword ptr [0x555608]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043d09e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d0a0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043d0a3  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d0a5  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043d0a7  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d0aa  7d30                   -jge 0x43d0dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d0dc;
    }
    // 0043d0ac  8b5706                 -mov edx, dword ptr [edi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0043d0af  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043d0b2  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0043d0b5  8b1508565500           -mov edx, dword ptr [0x555608]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043d0bb  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0043d0be  0355f4                 -add edx, dword ptr [ebp - 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0043d0c1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043d0c3  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0043d0c6  8b0d9c3d5f00           -mov ecx, dword ptr [0x5f3d9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */);
    // 0043d0cc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043d0cf  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d0d1  0305983d5f00           -add eax, dword ptr [0x5f3d98]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */)));
    // 0043d0d7  83e80a                 +sub eax, 0xa
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043d0da  eb35                   -jmp 0x43d111
    goto L_0x0043d111;
L_0x0043d0dc:
    // 0043d0dc  8b0d08565500           -mov ecx, dword ptr [0x555608]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043d0e2  8d53f3                 -lea edx, [ebx - 0xd]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-13) /* -0xd */);
    // 0043d0e5  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0043d0e8  8b4f06                 -mov ecx, dword ptr [edi + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0043d0eb  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0043d0ee  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d0f0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043d0f2  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0043d0f5  8b0d9c3d5f00           -mov ecx, dword ptr [0x5f3d9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */);
    // 0043d0fb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043d0fe  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d100  0305983d5f00           -add eax, dword ptr [0x5f3d98]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */)));
    // 0043d106  8b0da03d5f00           -mov ecx, dword ptr [0x5f3da0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241696) /* 0x5f3da0 */);
    // 0043d10c  83e80a                 -sub eax, 0xa
    (cpu.eax) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043d10f  01c8                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0043d111:
    // 0043d111  e8aaee0500             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
    // 0043d116  e9bc000000             -jmp 0x43d1d7
    goto L_0x0043d1d7;
L_0x0043d11b:
    // 0043d11b  6681fe0050             +cmp si, 0x5000
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20480 /*0x5000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043d120  7556                   -jne 0x43d178
    if (!cpu.flags.zf)
    {
        goto L_0x0043d178;
    }
    // 0043d122  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0043d127  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d129  43                     -inc ebx
    (cpu.ebx)++;
    // 0043d12a  e8a1b0fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043d12f  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d132  7d44                   -jge 0x43d178
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d178;
    }
    // 0043d134  8b1508565500           -mov edx, dword ptr [0x555608]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043d13a  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0043d13d  c745fc02000000         -mov dword ptr [ebp - 4], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 2 /*0x2*/;
    // 0043d144  8b4106                 -mov eax, dword ptr [ecx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0043d147  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043d14a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043d14c  a108565500             -mov eax, dword ptr [0x555608]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043d151  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0043d154  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d156  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043d159  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d15b  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043d15d  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043d160  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043d162  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0043d165  8b491c                 -mov ecx, dword ptr [ecx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0043d168  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043d16b  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0043d16e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043d170  8d41f6                 -lea eax, [ecx - 0xa]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-10) /* -0xa */);
    // 0043d173  e848ee0500             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
L_0x0043d178:
    // 0043d178  6681fe0048             +cmp si, 0x4800
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18432 /*0x4800*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043d17d  7558                   -jne 0x43d1d7
    if (!cpu.flags.zf)
    {
        goto L_0x0043d1d7;
    }
    // 0043d17f  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0043d184  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d186  e845b0fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043d18b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043d18d  7448                   -je 0x43d1d7
    if (cpu.flags.zf)
    {
        goto L_0x0043d1d7;
    }
    // 0043d18f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0043d194  4b                     -dec ebx
    (cpu.ebx)--;
    // 0043d195  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0043d198  8b1508565500           -mov edx, dword ptr [0x555608]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043d19e  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0043d1a1  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0043d1a4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043d1a7  8d0c10                 -lea ecx, [eax + edx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0043d1aa  a108565500             -mov eax, dword ptr [0x555608]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */);
    // 0043d1af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d1b1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043d1b4  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d1b6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043d1b8  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0043d1bb  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0043d1be  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043d1c1  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0043d1c4  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0043d1c7  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043d1ca  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043d1cd  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d1cf  83e80a                 -sub eax, 0xa
    (cpu.eax) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043d1d2  e8e9ed0500             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
L_0x0043d1d7:
    // 0043d1d7  6683fe0d               +cmp si, 0xd
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043d1db  0f85b7000000           -jne 0x43d298
    if (!cpu.flags.zf)
    {
        goto L_0x0043d298;
    }
    // 0043d1e1  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0043d1e6  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043d1e9  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 0043d1f0  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0043d1f3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043d1f5  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d1f8  7c16                   -jl 0x43d210
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d210;
    }
    // 0043d1fa  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d201  0f8591000000           -jne 0x43d298
    if (!cpu.flags.zf)
    {
        goto L_0x0043d298;
    }
    // 0043d207  83fb1a                 +cmp ebx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d20a  0f8d88000000           -jge 0x43d298
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d298;
    }
L_0x0043d210:
    // 0043d210  e80b070000             -call 0x43d920
    cpu.esp -= 4;
    sub_43d920(app, cpu);
    if (cpu.terminate) return;
    // 0043d215  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0043d217  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0043d219  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0043d21b  a3903d5f00             -mov dword ptr [0x5f3d90], eax
    app->getMemory<x86::reg32>(x86::reg32(6241680) /* 0x5f3d90 */) = cpu.eax;
    // 0043d220  8a5705                 -mov dl, byte ptr [edi + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 0043d223  66895f3c               -mov word ptr [edi + 0x3c], bx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(60) /* 0x3c */) = cpu.bx;
    // 0043d227  80ca04                 -or dl, 4
    cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0043d22a  8935943d5f00           -mov dword ptr [0x5f3d94], esi
    app->getMemory<x86::reg32>(x86::reg32(6241684) /* 0x5f3d94 */) = cpu.esi;
    // 0043d230  885705                 -mov byte ptr [edi + 5], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0043d233  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043d236  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043d238  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d239  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d23a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d23b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d23c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d23d:
    // 0043d23d  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 0043d242  8b413a                 -mov eax, dword ptr [ecx + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(58) /* 0x3a */);
    // 0043d245  8a7105                 -mov dh, byte ptr [ecx + 5]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0043d248  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043d24b  80ce04                 -or dh, 4
    cpu.dh |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0043d24e  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0043d251  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043d254  887105                 -mov byte ptr [ecx + 5], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.dh;
    // 0043d257  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0043d25a  6683fe1b               +cmp si, 0x1b
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043d25e  7511                   -jne 0x43d271
    if (!cpu.flags.zf)
    {
        goto L_0x0043d271;
    }
    // 0043d260  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 0043d262  80e3fb                 +and bl, 0xfb
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(251 /*0xfb*/))));
    // 0043d265  a1903d5f00             -mov eax, dword ptr [0x5f3d90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241680) /* 0x5f3d90 */);
    // 0043d26a  885905                 -mov byte ptr [ecx + 5], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.bl;
    // 0043d26d  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0043d26f  eb21                   -jmp 0x43d292
    goto L_0x0043d292;
L_0x0043d271:
    // 0043d271  0fbfc6                 -movsx eax, si
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 0043d274  e827fbffff             -call 0x43cda0
    cpu.esp -= 4;
    sub_43cda0(app, cpu);
    if (cpu.terminate) return;
    // 0043d279  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043d27b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d27d  7419                   -je 0x43d298
    if (cpu.flags.zf)
    {
        goto L_0x0043d298;
    }
    // 0043d27f  8b413a                 -mov eax, dword ptr [ecx + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(58) /* 0x3a */);
    // 0043d282  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043d284  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043d287  e8f4fbffff             -call 0x43ce80
    cpu.esp -= 4;
    sub_43ce80(app, cpu);
    if (cpu.terminate) return;
    // 0043d28c  806105fb               -and byte ptr [ecx + 5], 0xfb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0043d290  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
L_0x0043d292:
    // 0043d292  66c7413cffff           -mov word ptr [ecx + 0x3c], 0xffff
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(60) /* 0x3c */) = 65535 /*0xffff*/;
L_0x0043d298:
    // 0043d298  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x0043d29b:
    // 0043d29b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043d29d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d29e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d29f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d2a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d2a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_43d2b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d2b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d2b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d2b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d2b3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d2b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043d2b7  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0043d2bc  e89fd30000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043d2c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d2c3  7445                   -je 0x43d30a
    if (cpu.flags.zf)
    {
        goto L_0x0043d30a;
    }
    // 0043d2c5  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0043d2c9  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 0043d2cd  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0043d2d1  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 0043d2d5  66a108565500           -mov ax, word ptr [0x555608]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5592584) /* 0x555608 */);
    // 0043d2db  6bc00d                 -imul eax, eax, 0xd
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(13 /*0xd*/)));
    // 0043d2de  668b15983d5f00         -mov dx, word ptr [0x5f3d98]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(6241688) /* 0x5f3d98 */);
    // 0043d2e5  66894120               -mov word ptr [ecx + 0x20], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ax;
    // 0043d2e9  66a19c3d5f00           -mov ax, word ptr [0x5f3d9c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6241692) /* 0x5f3d9c */);
    // 0043d2ef  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043d2f1  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d2f8  7507                   -jne 0x43d301
    if (!cpu.flags.zf)
    {
        goto L_0x0043d301;
    }
    // 0043d2fa  05fa000000             +add eax, 0xfa
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(250 /*0xfa*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043d2ff  eb05                   -jmp 0x43d306
    goto L_0x0043d306;
L_0x0043d301:
    // 0043d301  0528000000             -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0043d306:
    // 0043d306  6689411e               -mov word ptr [ecx + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.ax;
L_0x0043d30a:
    // 0043d30a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d30b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d30c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d30d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_43d310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d312  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d313  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043d314  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043d315  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d316  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d318  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043d31a  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0043d31f  e83cd30000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043d324  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d326  0f84b0000000           -je 0x43d3dc
    if (cpu.flags.zf)
    {
        goto L_0x0043d3dc;
    }
    // 0043d32c  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d333  7451                   -je 0x43d386
    if (cpu.flags.zf)
    {
        goto L_0x0043d386;
    }
    // 0043d335  bbc8000000             -mov ebx, 0xc8
    cpu.ebx = 200 /*0xc8*/;
    // 0043d33a  8b35b0d36f00           -mov esi, dword ptr [0x6fd3b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043d340  891da03d5f00           -mov dword ptr [0x5f3da0], ebx
    app->getMemory<x86::reg32>(x86::reg32(6241696) /* 0x5f3da0 */) = cpu.ebx;
    // 0043d346  83fe01                 +cmp esi, 1
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
    // 0043d349  7513                   -jne 0x43d35e
    if (!cpu.flags.zf)
    {
        goto L_0x0043d35e;
    }
    // 0043d34b  bf6e000000             -mov edi, 0x6e
    cpu.edi = 110 /*0x6e*/;
    // 0043d350  66c741063c00           -mov word ptr [ecx + 6], 0x3c
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = 60 /*0x3c*/;
    // 0043d356  893d9c3d5f00           -mov dword ptr [0x5f3d9c], edi
    app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */) = cpu.edi;
    // 0043d35c  eb10                   -jmp 0x43d36e
    goto L_0x0043d36e;
L_0x0043d35e:
    // 0043d35e  b896000000             -mov eax, 0x96
    cpu.eax = 150 /*0x96*/;
    // 0043d363  66c741069600           -mov word ptr [ecx + 6], 0x96
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = 150 /*0x96*/;
    // 0043d369  a39c3d5f00             -mov dword ptr [0x5f3d9c], eax
    app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */) = cpu.eax;
L_0x0043d36e:
    // 0043d36e  bb16000000             -mov ebx, 0x16
    cpu.ebx = 22 /*0x16*/;
    // 0043d373  ba7d000000             -mov edx, 0x7d
    cpu.edx = 125 /*0x7d*/;
    // 0043d378  891d08565500           -mov dword ptr [0x555608], ebx
    app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */) = cpu.ebx;
    // 0043d37e  8915983d5f00           -mov dword ptr [0x5f3d98], edx
    app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */) = cpu.edx;
    // 0043d384  eb4b                   -jmp 0x43d3d1
    goto L_0x0043d3d1;
L_0x0043d386:
    // 0043d386  bea5000000             -mov esi, 0xa5
    cpu.esi = 165 /*0xa5*/;
    // 0043d38b  bf6e000000             -mov edi, 0x6e
    cpu.edi = 110 /*0x6e*/;
    // 0043d390  b846000000             -mov eax, 0x46
    cpu.eax = 70 /*0x46*/;
    // 0043d395  ba19000000             -mov edx, 0x19
    cpu.edx = 25 /*0x19*/;
    // 0043d39a  8935a03d5f00           -mov dword ptr [0x5f3da0], esi
    app->getMemory<x86::reg32>(x86::reg32(6241696) /* 0x5f3da0 */) = cpu.esi;
    // 0043d3a0  893d9c3d5f00           -mov dword ptr [0x5f3d9c], edi
    app->getMemory<x86::reg32>(x86::reg32(6241692) /* 0x5f3d9c */) = cpu.edi;
    // 0043d3a6  a3983d5f00             -mov dword ptr [0x5f3d98], eax
    app->getMemory<x86::reg32>(x86::reg32(6241688) /* 0x5f3d98 */) = cpu.eax;
    // 0043d3ab  b87c775300             -mov eax, 0x53777c
    cpu.eax = 5470076 /*0x53777c*/;
    // 0043d3b0  891508565500           -mov dword ptr [0x555608], edx
    app->getMemory<x86::reg32>(x86::reg32(5592584) /* 0x555608 */) = cpu.edx;
    // 0043d3b6  e8f5890900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0043d3bb  66a3aa3d5f00           -mov word ptr [0x5f3daa], ax
    app->getMemory<x86::reg16>(x86::reg32(6241706) /* 0x5f3daa */) = cpu.ax;
    // 0043d3c1  b884775300             -mov eax, 0x537784
    cpu.eax = 5470084 /*0x537784*/;
    // 0043d3c6  e8e5890900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0043d3cb  66a3a83d5f00           -mov word ptr [0x5f3da8], ax
    app->getMemory<x86::reg16>(x86::reg32(6241704) /* 0x5f3da8 */) = cpu.ax;
L_0x0043d3d1:
    // 0043d3d1  66c7413cffff           -mov word ptr [ecx + 0x3c], 0xffff
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(60) /* 0x3c */) = 65535 /*0xffff*/;
    // 0043d3d7  e874020000             -call 0x43d650
    cpu.esp -= 4;
    sub_43d650(app, cpu);
    if (cpu.terminate) return;
L_0x0043d3dc:
    // 0043d3dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d3dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d3de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d3df  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d3e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d3e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d3e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_43d3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d3f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d3f1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d3f3  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043d3f7  750a                   -jne 0x43d403
    if (!cpu.flags.zf)
    {
        goto L_0x0043d403;
    }
    // 0043d3f9  c705a43d5f0001000000   -mov dword ptr [0x5f3da4], 1
    app->getMemory<x86::reg32>(x86::reg32(6241700) /* 0x5f3da4 */) = 1 /*0x1*/;
L_0x0043d403:
    // 0043d403  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0043d406  e8653e0200             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 0043d40b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d40c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_43d410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d411  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d412  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d413  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d415  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043d41a  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043d41d  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d420  7233                   -jb 0x43d455
    if (cpu.flags.cf)
    {
        goto L_0x0043d455;
    }
    // 0043d422  7607                   -jbe 0x43d42b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043d42b;
    }
    // 0043d424  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d427  7429                   -je 0x43d452
    if (cpu.flags.zf)
    {
        goto L_0x0043d452;
    }
    // 0043d429  eb2a                   -jmp 0x43d455
    goto L_0x0043d455;
L_0x0043d42b:
    // 0043d42b  e890720000             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0043d430  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d432  7514                   -jne 0x43d448
    if (!cpu.flags.zf)
    {
        goto L_0x0043d448;
    }
    // 0043d434  8b1db0d36f00           -mov ebx, dword ptr [0x6fd3b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043d43a  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d43d  7502                   -jne 0x43d441
    if (!cpu.flags.zf)
    {
        goto L_0x0043d441;
    }
    // 0043d43f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0043d441:
    // 0043d441  e8aa300500             -call 0x4904f0
    cpu.esp -= 4;
    sub_4904f0(app, cpu);
    if (cpu.terminate) return;
    // 0043d446  eb05                   -jmp 0x43d44d
    goto L_0x0043d44d;
L_0x0043d448:
    // 0043d448  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d44b  7508                   -jne 0x43d455
    if (!cpu.flags.zf)
    {
        goto L_0x0043d455;
    }
L_0x0043d44d:
    // 0043d44d  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043d450  eb03                   -jmp 0x43d455
    goto L_0x0043d455;
L_0x0043d452:
    // 0043d452  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0043d455:
    // 0043d455  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043d457  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d458  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d459  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d45a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_43d460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d460  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d461  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d462  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d463  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d464  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d466  b8ab010000             -mov eax, 0x1ab
    cpu.eax = 427 /*0x1ab*/;
    // 0043d46b  e8e0430900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043d470  a3b83d5f00             -mov dword ptr [0x5f3db8], eax
    app->getMemory<x86::reg32>(x86::reg32(6241720) /* 0x5f3db8 */) = cpu.eax;
    // 0043d475  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 0043d47a  e8d1430900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043d47f  a3bc3d5f00             -mov dword ptr [0x5f3dbc], eax
    app->getMemory<x86::reg32>(x86::reg32(6241724) /* 0x5f3dbc */) = cpu.eax;
    // 0043d484  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 0043d489  e8c2430900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043d48e  6810d44300             -push 0x43d410
    app->getMemory<x86::reg32>(cpu.esp-4) = 4445200 /*0x43d410*/;
    cpu.esp -= 4;
    // 0043d493  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043d495  b9bc3d5f00             -mov ecx, 0x5f3dbc
    cpu.ecx = 6241724 /*0x5f3dbc*/;
    // 0043d49a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043d49c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0043d4a1  bab83d5f00             -mov edx, 0x5f3db8
    cpu.edx = 6241720 /*0x5f3db8*/;
    // 0043d4a6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043d4a8  a3c03d5f00             -mov dword ptr [0x5f3dc0], eax
    app->getMemory<x86::reg32>(x86::reg32(6241728) /* 0x5f3dc0 */) = cpu.eax;
    // 0043d4ad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043d4b2  e819720000             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0043d4b7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0043d4bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d4bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d4be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d4bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d4c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_43d4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d4d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d4d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d4d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d4d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043d4d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d4d5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d4d7  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0043d4da  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043d4dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d4de  0f8401010000           -je 0x43d5e5
    if (cpu.flags.zf)
    {
        goto L_0x0043d5e5;
    }
    // 0043d4e4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d4e6  8915a43d5f00           -mov dword ptr [0x5f3da4], edx
    app->getMemory<x86::reg32>(x86::reg32(6241700) /* 0x5f3da4 */) = cpu.edx;
    // 0043d4ec  ba8c775300             -mov edx, 0x53778c
    cpu.edx = 5470092 /*0x53778c*/;
    // 0043d4f1  e84a550000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0043d4f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d4f8  7407                   -je 0x43d501
    if (cpu.flags.zf)
    {
        goto L_0x0043d501;
    }
    // 0043d4fa  c74030f0d34300         -mov dword ptr [eax + 0x30], 0x43d3f0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4445168 /*0x43d3f0*/;
L_0x0043d501:
    // 0043d501  bb68000000             -mov ebx, 0x68
    cpu.ebx = 104 /*0x68*/;
    // 0043d506  a1b0d36f00             -mov eax, dword ptr [0x6fd3b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043d50b  bad03c5f00             -mov edx, 0x5f3cd0
    cpu.edx = 6241488 /*0x5f3cd0*/;
    // 0043d510  e8bb2f0500             -call 0x4904d0
    cpu.esp -= 4;
    sub_4904d0(app, cpu);
    if (cpu.terminate) return;
    // 0043d515  e8d6cf0a00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0043d51a  6894775300             -push 0x537794
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470100 /*0x537794*/;
    cpu.esp -= 4;
    // 0043d51f  68b42d7a00             -push 0x7a2db4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007092 /*0x7a2db4*/;
    cpu.esp -= 4;
    // 0043d524  68a0775300             -push 0x5377a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470112 /*0x5377a0*/;
    cpu.esp -= 4;
    // 0043d529  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0043d52c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043d52d  8b3528925500           -mov esi, dword ptr [0x559228]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5607976) /* 0x559228 */);
    // 0043d533  e858210a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043d538  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043d53b  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0043d53e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043d540  e84bd70000             -call 0x44ac90
    cpu.esp -= 4;
    sub_44ac90(app, cpu);
    if (cpu.terminate) return;
    // 0043d545  a328925500             -mov dword ptr [0x559228], eax
    app->getMemory<x86::reg32>(x86::reg32(5607976) /* 0x559228 */) = cpu.eax;
    // 0043d54a  eb05                   -jmp 0x43d551
    goto L_0x0043d551;
L_0x0043d54c:
    // 0043d54c  83fa0c                 +cmp edx, 0xc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d54f  7d34                   -jge 0x43d585
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d585;
    }
L_0x0043d551:
    // 0043d551  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0043d554  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043d555  68a8775300             -push 0x5377a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470120 /*0x5377a8*/;
    cpu.esp -= 4;
    // 0043d55a  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0043d55d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043d55e  e82d210a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043d563  8a65b2                 -mov ah, byte ptr [ebp - 0x4e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-78) /* -0x4e */);
    // 0043d566  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043d569  80fc20                 +cmp ah, 0x20
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043d56c  7504                   -jne 0x43d572
    if (!cpu.flags.zf)
    {
        goto L_0x0043d572;
    }
    // 0043d56e  c645b230               -mov byte ptr [ebp - 0x4e], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-78) /* -0x4e */) = 48 /*0x30*/;
L_0x0043d572:
    // 0043d572  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0043d575  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043d576  e835880900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0043d57b  66890455363d5f00       -mov word ptr [edx*2 + 0x5f3d36], ax
    app->getMemory<x86::reg16>(x86::reg32(6241590) /* 0x5f3d36 */ + cpu.edx * 2) = cpu.ax;
    // 0043d583  ebc7                   -jmp 0x43d54c
    goto L_0x0043d54c;
L_0x0043d585:
    // 0043d585  bab0775300             -mov edx, 0x5377b0
    cpu.edx = 5470128 /*0x5377b0*/;
    // 0043d58a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043d58c  893528925500           -mov dword ptr [0x559228], esi
    app->getMemory<x86::reg32>(x86::reg32(5607976) /* 0x559228 */) = cpu.esi;
    // 0043d592  e8a9540000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0043d597  f60570c96f0008         +test byte ptr [0x6fc970], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7326064) /* 0x6fc970 */) & 8 /*0x8*/));
    // 0043d59e  7508                   -jne 0x43d5a8
    if (!cpu.flags.zf)
    {
        goto L_0x0043d5a8;
    }
    // 0043d5a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d5a2  7404                   -je 0x43d5a8
    if (cpu.flags.zf)
    {
        goto L_0x0043d5a8;
    }
    // 0043d5a4  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0043d5a8:
    // 0043d5a8  bac0775300             -mov edx, 0x5377c0
    cpu.edx = 5470144 /*0x5377c0*/;
    // 0043d5ad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043d5af  e88c540000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0043d5b4  833d70c96f0000         +cmp dword ptr [0x6fc970], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7326064) /* 0x6fc970 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d5bb  7508                   -jne 0x43d5c5
    if (!cpu.flags.zf)
    {
        goto L_0x0043d5c5;
    }
    // 0043d5bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d5bf  7404                   -je 0x43d5c5
    if (cpu.flags.zf)
    {
        goto L_0x0043d5c5;
    }
    // 0043d5c1  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0043d5c5:
    // 0043d5c5  bad0775300             -mov edx, 0x5377d0
    cpu.edx = 5470160 /*0x5377d0*/;
    // 0043d5ca  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043d5cc  e86f540000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0043d5d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d5d3  7407                   -je 0x43d5dc
    if (cpu.flags.zf)
    {
        goto L_0x0043d5dc;
    }
    // 0043d5d5  c7406460d44300         -mov dword ptr [eax + 0x64], 0x43d460
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4445280 /*0x43d460*/;
L_0x0043d5dc:
    // 0043d5dc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043d5de  e831a0ffff             -call 0x437614
    cpu.esp -= 4;
    sub_437614(app, cpu);
    if (cpu.terminate) return;
    // 0043d5e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043d5e5:
    // 0043d5e5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043d5e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d5e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d5e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d5ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d5eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d5ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43d5ee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d5ee  90                     -nop 
    ;
    // 0043d5ef  90                     -nop 
    ;
    // 0043d5f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d5f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d5f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d5f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d5f4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d5f6  a1b0d36f00             -mov eax, dword ptr [0x6fd3b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043d5fb  e8d02e0500             -call 0x4904d0
    cpu.esp -= 4;
    sub_4904d0(app, cpu);
    if (cpu.terminate) return;
    // 0043d600  833da43d5f0000         +cmp dword ptr [0x5f3da4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6241700) /* 0x5f3da4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d607  7423                   -je 0x43d62c
    if (cpu.flags.zf)
    {
        goto L_0x0043d62c;
    }
    // 0043d609  bb68000000             -mov ebx, 0x68
    cpu.ebx = 104 /*0x68*/;
    // 0043d60e  8b0db0d36f00           -mov ecx, dword ptr [0x6fd3b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043d614  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d617  7405                   -je 0x43d61e
    if (cpu.flags.zf)
    {
        goto L_0x0043d61e;
    }
    // 0043d619  bb34000000             -mov ebx, 0x34
    cpu.ebx = 52 /*0x34*/;
L_0x0043d61e:
    // 0043d61e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d620  b8d03c5f00             -mov eax, 0x5f3cd0
    cpu.eax = 6241488 /*0x5f3cd0*/;
    // 0043d625  e8c6ce0a00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0043d62a  eb0e                   -jmp 0x43d63a
    goto L_0x0043d63a;
L_0x0043d62c:
    // 0043d62c  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d633  7505                   -jne 0x43d63a
    if (!cpu.flags.zf)
    {
        goto L_0x0043d63a;
    }
    // 0043d635  e806eaffff             -call 0x43c040
    cpu.esp -= 4;
    sub_43c040(app, cpu);
    if (cpu.terminate) return;
L_0x0043d63a:
    // 0043d63a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d63c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d63d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d63e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d63f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d640  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_43d650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d650  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d651  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d652  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d653  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d654  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d656  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
L_0x0043d65c:
    // 0043d65c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043d65e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0043d660:
    // 0043d660  3b1d04d26f00           +cmp ebx, dword ptr [0x6fd204]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328260) /* 0x6fd204 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d666  7d1f                   -jge 0x43d687
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d687;
    }
    // 0043d668  8d957cffffff           -lea edx, [ebp - 0x84]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-132) /* -0x84 */);
    // 0043d66e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043d670  e87b82ffff             -call 0x4358f0
    cpu.esp -= 4;
    sub_4358f0(app, cpu);
    if (cpu.terminate) return;
    // 0043d675  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d677  740b                   -je 0x43d684
    if (cpu.flags.zf)
    {
        goto L_0x0043d684;
    }
    // 0043d679  837dec00               +cmp dword ptr [ebp - 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d67d  7405                   -je 0x43d684
    if (cpu.flags.zf)
    {
        goto L_0x0043d684;
    }
    // 0043d67f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0043d684:
    // 0043d684  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043d685  ebd9                   -jmp 0x43d660
    goto L_0x0043d660;
L_0x0043d687:
    // 0043d687  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d689  e8a29f0a00             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 0043d68e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043d690  75ca                   -jne 0x43d65c
    if (!cpu.flags.zf)
    {
        goto L_0x0043d65c;
    }
    // 0043d692  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043d694  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d695  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d696  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d697  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d698  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_43d6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d6a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d6a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d6a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d6a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043d6a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043d6a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d6a6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d6a8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0043d6ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d6ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d6af  0f8424010000           -je 0x43d7d9
    if (cpu.flags.zf)
    {
        goto L_0x0043d7d9;
    }
    // 0043d6b5  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d6bc  7507                   -jne 0x43d6c5
    if (!cpu.flags.zf)
    {
        goto L_0x0043d6c5;
    }
    // 0043d6be  be1a000000             -mov esi, 0x1a
    cpu.esi = 26 /*0x1a*/;
    // 0043d6c3  eb05                   -jmp 0x43d6ca
    goto L_0x0043d6ca;
L_0x0043d6c5:
    // 0043d6c5  be0d000000             -mov esi, 0xd
    cpu.esi = 13 /*0xd*/;
L_0x0043d6ca:
    // 0043d6ca  a1b0d36f00             -mov eax, dword ptr [0x6fd3b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 0043d6cf  e8fc2d0500             -call 0x4904d0
    cpu.esp -= 4;
    sub_4904d0(app, cpu);
    if (cpu.terminate) return;
    // 0043d6d4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043d6d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d6d9  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0043d6dc  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0043d6df  83f804                 +cmp eax, 4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d6e2  7539                   -jne 0x43d71d
    if (!cpu.flags.zf)
    {
        goto L_0x0043d71d;
    }
    // 0043d6e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043d6e6:
    // 0043d6e6  39f0                   +cmp eax, esi
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
    // 0043d6e8  0f8deb000000           -jge 0x43d7d9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d7d9;
    }
    // 0043d6ee  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043d6f1  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0043d6f8  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043d6fa  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0043d6fc  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0043d6ff  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 0043d702  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0043d705  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043d707  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0043d70a  8b7dec                 -mov edi, dword ptr [ebp - 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043d70d  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 0043d710  39fb                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d712  7506                   -jne 0x43d71a
    if (!cpu.flags.zf)
    {
        goto L_0x0043d71a;
    }
    // 0043d714  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x0043d71a:
    // 0043d71a  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043d71b  ebc9                   -jmp 0x43d6e6
    goto L_0x0043d6e6;
L_0x0043d71d:
    // 0043d71d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0043d71f:
    // 0043d71f  39f1                   +cmp ecx, esi
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
    // 0043d721  0f8db2000000           -jge 0x43d7d9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d7d9;
    }
    // 0043d727  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043d72a  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0043d731  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043d733  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0043d735  39fa                   +cmp edx, edi
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
    // 0043d737  0f8490000000           -je 0x43d7cd
    if (cpu.flags.zf)
    {
        goto L_0x0043d7cd;
    }
    // 0043d73d  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043d73f  c1e318                 -shl ebx, 0x18
    cpu.ebx <<= 24 /*0x18*/ % 32;
    // 0043d742  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0043d745  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d748  0f8585000000           -jne 0x43d7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0043d7d3;
    }
    // 0043d74e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043d750  c1e318                 -shl ebx, 0x18
    cpu.ebx <<= 24 /*0x18*/ % 32;
    // 0043d753  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0043d756  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d759  0f8574000000           -jne 0x43d7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0043d7d3;
    }
    // 0043d75f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043d761  c1ef1c                 -shr edi, 0x1c
    cpu.edi >>= 28 /*0x1c*/ % 32;
    // 0043d764  897dec                 -mov dword ptr [ebp - 0x14], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edi;
    // 0043d767  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0043d769  c1ef1c                 -shr edi, 0x1c
    cpu.edi >>= 28 /*0x1c*/ % 32;
    // 0043d76c  3b7dec                 +cmp edi, dword ptr [ebp - 0x14]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d76f  0f855e000000           -jne 0x43d7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0043d7d3;
    }
    // 0043d775  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0043d777  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0043d77a  c1ef1c                 -shr edi, 0x1c
    cpu.edi >>= 28 /*0x1c*/ % 32;
    // 0043d77d  897dec                 -mov dword ptr [ebp - 0x14], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edi;
    // 0043d780  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0043d782  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0043d785  c1ef1c                 -shr edi, 0x1c
    cpu.edi >>= 28 /*0x1c*/ % 32;
    // 0043d788  3b7dec                 +cmp edi, dword ptr [ebp - 0x14]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d78b  7546                   -jne 0x43d7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0043d7d3;
    }
    // 0043d78d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0043d78f  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 0043d792  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 0043d795  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0043d798  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0043d79a  c1e708                 -shl edi, 8
    cpu.edi <<= 8 /*0x8*/ % 32;
    // 0043d79d  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 0043d7a0  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 0043d7a3  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043d7a6  3b7df0                 +cmp edi, dword ptr [ebp - 0x10]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d7a9  7422                   -je 0x43d7cd
    if (cpu.flags.zf)
    {
        goto L_0x0043d7cd;
    }
    // 0043d7ab  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0043d7ae  c1eb18                 -shr ebx, 0x18
    cpu.ebx >>= 24 /*0x18*/ % 32;
    // 0043d7b1  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0043d7b4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043d7b6  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0043d7b9  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043d7bc  c1eb18                 -shr ebx, 0x18
    cpu.ebx >>= 24 /*0x18*/ % 32;
    // 0043d7bf  39fb                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d7c1  740a                   -je 0x43d7cd
    if (cpu.flags.zf)
    {
        goto L_0x0043d7cd;
    }
    // 0043d7c3  3b7df0                 +cmp edi, dword ptr [ebp - 0x10]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d7c6  7405                   -je 0x43d7cd
    if (cpu.flags.zf)
    {
        goto L_0x0043d7cd;
    }
    // 0043d7c8  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d7cb  7506                   -jne 0x43d7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0043d7d3;
    }
L_0x0043d7cd:
    // 0043d7cd  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
L_0x0043d7d3:
    // 0043d7d3  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043d7d4  e946ffffff             -jmp 0x43d71f
    goto L_0x0043d71f;
L_0x0043d7d9:
    // 0043d7d9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043d7db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d7dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d7dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d7de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d7df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d7e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d7e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_43d7f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d7f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043d7f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043d7f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d7f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d7f5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043d7f7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0043d7f9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043d7fb  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0043d7fe  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0043d801  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d803  83fa39                 +cmp edx, 0x39
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(57 /*0x39*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d806  750a                   -jne 0x43d812
    if (!cpu.flags.zf)
    {
        goto L_0x0043d812;
    }
    // 0043d808  b858000000             -mov eax, 0x58
    cpu.eax = 88 /*0x58*/;
    // 0043d80d  e9bf000000             -jmp 0x43d8d1
    goto L_0x0043d8d1;
L_0x0043d812:
    // 0043d812  83fa1c                 +cmp edx, 0x1c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d815  750a                   -jne 0x43d821
    if (!cpu.flags.zf)
    {
        goto L_0x0043d821;
    }
    // 0043d817  b859000000             -mov eax, 0x59
    cpu.eax = 89 /*0x59*/;
    // 0043d81c  e9ac000000             -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d821:
    // 0043d821  83fa52                 +cmp edx, 0x52
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(82 /*0x52*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d824  750a                   -jne 0x43d830
    if (!cpu.flags.zf)
    {
        goto L_0x0043d830;
    }
    // 0043d826  b85a000000             -mov eax, 0x5a
    cpu.eax = 90 /*0x5a*/;
    // 0043d82b  e99d000000             -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d830:
    // 0043d830  83fa53                 +cmp edx, 0x53
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(83 /*0x53*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d833  750a                   -jne 0x43d83f
    if (!cpu.flags.zf)
    {
        goto L_0x0043d83f;
    }
    // 0043d835  b85b000000             -mov eax, 0x5b
    cpu.eax = 91 /*0x5b*/;
    // 0043d83a  e98e000000             -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d83f:
    // 0043d83f  83fa47                 +cmp edx, 0x47
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d842  750a                   -jne 0x43d84e
    if (!cpu.flags.zf)
    {
        goto L_0x0043d84e;
    }
    // 0043d844  b85c000000             -mov eax, 0x5c
    cpu.eax = 92 /*0x5c*/;
    // 0043d849  e97f000000             -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d84e:
    // 0043d84e  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d851  750a                   -jne 0x43d85d
    if (!cpu.flags.zf)
    {
        goto L_0x0043d85d;
    }
    // 0043d853  b85d000000             -mov eax, 0x5d
    cpu.eax = 93 /*0x5d*/;
    // 0043d858  e970000000             -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d85d:
    // 0043d85d  83fa49                 +cmp edx, 0x49
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(73 /*0x49*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d860  750a                   -jne 0x43d86c
    if (!cpu.flags.zf)
    {
        goto L_0x0043d86c;
    }
    // 0043d862  b85e000000             -mov eax, 0x5e
    cpu.eax = 94 /*0x5e*/;
    // 0043d867  e961000000             -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d86c:
    // 0043d86c  83fa51                 +cmp edx, 0x51
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(81 /*0x51*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d86f  750a                   -jne 0x43d87b
    if (!cpu.flags.zf)
    {
        goto L_0x0043d87b;
    }
    // 0043d871  b85f000000             -mov eax, 0x5f
    cpu.eax = 95 /*0x5f*/;
    // 0043d876  e952000000             -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d87b:
    // 0043d87b  83fa48                 +cmp edx, 0x48
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d87e  7507                   -jne 0x43d887
    if (!cpu.flags.zf)
    {
        goto L_0x0043d887;
    }
    // 0043d880  b860000000             -mov eax, 0x60
    cpu.eax = 96 /*0x60*/;
    // 0043d885  eb46                   -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d887:
    // 0043d887  83fa50                 +cmp edx, 0x50
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d88a  7507                   -jne 0x43d893
    if (!cpu.flags.zf)
    {
        goto L_0x0043d893;
    }
    // 0043d88c  b861000000             -mov eax, 0x61
    cpu.eax = 97 /*0x61*/;
    // 0043d891  eb3a                   -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d893:
    // 0043d893  83fa4b                 +cmp edx, 0x4b
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(75 /*0x4b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d896  7507                   -jne 0x43d89f
    if (!cpu.flags.zf)
    {
        goto L_0x0043d89f;
    }
    // 0043d898  b862000000             -mov eax, 0x62
    cpu.eax = 98 /*0x62*/;
    // 0043d89d  eb2e                   -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d89f:
    // 0043d89f  83fa4d                 +cmp edx, 0x4d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(77 /*0x4d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d8a2  7507                   -jne 0x43d8ab
    if (!cpu.flags.zf)
    {
        goto L_0x0043d8ab;
    }
    // 0043d8a4  b863000000             -mov eax, 0x63
    cpu.eax = 99 /*0x63*/;
    // 0043d8a9  eb22                   -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d8ab:
    // 0043d8ab  83fa0e                 +cmp edx, 0xe
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d8ae  7507                   -jne 0x43d8b7
    if (!cpu.flags.zf)
    {
        goto L_0x0043d8b7;
    }
    // 0043d8b0  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 0043d8b5  eb16                   -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d8b7:
    // 0043d8b7  83fa0f                 +cmp edx, 0xf
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d8ba  7507                   -jne 0x43d8c3
    if (!cpu.flags.zf)
    {
        goto L_0x0043d8c3;
    }
    // 0043d8bc  b865000000             -mov eax, 0x65
    cpu.eax = 101 /*0x65*/;
    // 0043d8c1  eb0a                   -jmp 0x43d8cd
    goto L_0x0043d8cd;
L_0x0043d8c3:
    // 0043d8c3  83fa4c                 +cmp edx, 0x4c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d8c6  7505                   -jne 0x43d8cd
    if (!cpu.flags.zf)
    {
        goto L_0x0043d8cd;
    }
    // 0043d8c8  b844000000             -mov eax, 0x44
    cpu.eax = 68 /*0x44*/;
L_0x0043d8cd:
    // 0043d8cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d8cf  7425                   -je 0x43d8f6
    if (cpu.flags.zf)
    {
        goto L_0x0043d8f6;
    }
L_0x0043d8d1:
    // 0043d8d1  e87a3f0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043d8d6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043d8d8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043d8d9:
    // 0043d8d9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043d8db  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043d8dd  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043d8df  7410                   -je 0x43d8f1
    if (cpu.flags.zf)
    {
        goto L_0x0043d8f1;
    }
    // 0043d8e1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043d8e4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043d8e7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043d8ea  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043d8ed  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043d8ef  75e8                   -jne 0x43d8d9
    if (!cpu.flags.zf)
    {
        goto L_0x0043d8d9;
    }
L_0x0043d8f1:
    // 0043d8f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d8f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d8f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d8f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d8f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d8f6:
    // 0043d8f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043d8f8  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0043d8fb  e8e0140b00             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 0043d900  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043d901  68d8775300             -push 0x5377d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470168 /*0x5377d8*/;
    cpu.esp -= 4;
    // 0043d906  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043d907  e8841d0a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043d90c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043d90f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d910  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d911  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d912  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_43d920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d921  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d922  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d923  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043d924  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d925  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d927  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0043d92d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0043d92f:
    // 0043d92f  3b1d04d26f00           +cmp ebx, dword ptr [0x6fd204]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328260) /* 0x6fd204 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d935  7d5f                   -jge 0x43d996
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d996;
    }
    // 0043d937  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043d939  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043d93c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043d93e  833cc570c96f0000       +cmp dword ptr [eax*8 + 0x6fc970], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7326064) /* 0x6fc970 */ + cpu.eax * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d946  744b                   -je 0x43d993
    if (cpu.flags.zf)
    {
        goto L_0x0043d993;
    }
    // 0043d948  8d957cffffff           -lea edx, [ebp - 0x84]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-132) /* -0x84 */);
    // 0043d94e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043d950  e89b7fffff             -call 0x4358f0
    cpu.esp -= 4;
    sub_4358f0(app, cpu);
    if (cpu.terminate) return;
    // 0043d955  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d957  743a                   -je 0x43d993
    if (cpu.flags.zf)
    {
        goto L_0x0043d993;
    }
    // 0043d959  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043d95b  eb05                   -jmp 0x43d962
    goto L_0x0043d962;
L_0x0043d95d:
    // 0043d95d  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d960  7d31                   -jge 0x43d993
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d993;
    }
L_0x0043d962:
    // 0043d962  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0043d964  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0043d967  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043d96c  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043d96e  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0043d970  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0043d973  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0043d975  8586b0c96f00           -test dword ptr [esi + 0x6fc9b0], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(7326128) /* 0x6fc9b0 */) & cpu.eax));
    // 0043d97b  7413                   -je 0x43d990
    if (cpu.flags.zf)
    {
        goto L_0x0043d990;
    }
    // 0043d97d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0043d97f  8b7495cc               -mov esi, dword ptr [ebp + edx*4 - 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */ + cpu.edx * 4);
    // 0043d983  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0043d986  c1fe08                 +sar esi, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0043d989  89b491503d5f00         -mov dword ptr [ecx + edx*4 + 0x5f3d50], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6241616) /* 0x5f3d50 */ + cpu.edx * 4) = cpu.esi;
L_0x0043d990:
    // 0043d990  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043d991  ebca                   -jmp 0x43d95d
    goto L_0x0043d95d;
L_0x0043d993:
    // 0043d993  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043d994  eb99                   -jmp 0x43d92f
    goto L_0x0043d92f;
L_0x0043d996:
    // 0043d996  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043d998  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d999  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d99a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d99b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d99c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d99d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_43d9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d9a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d9a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d9a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d9a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d9a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d9a6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043d9a8  eb0f                   -jmp 0x43d9b9
    goto L_0x0043d9b9;
L_0x0043d9aa:
    // 0043d9aa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d9ac  66898a68565500         -mov word ptr [edx + 0x555668], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5592680) /* 0x555668 */) = cpu.cx;
L_0x0043d9b3:
    // 0043d9b3  40                     -inc eax
    (cpu.eax)++;
    // 0043d9b4  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d9b7  7d32                   -jge 0x43d9eb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d9eb;
    }
L_0x0043d9b9:
    // 0043d9b9  8b0d04d26f00           -mov ecx, dword ptr [0x6fd204]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328260) /* 0x6fd204 */);
    // 0043d9bf  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 0043d9c2  39c8                   +cmp eax, ecx
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
    // 0043d9c4  7de4                   -jge 0x43d9aa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d9aa;
    }
    // 0043d9c6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043d9c8  81c355080000           +add ebx, 0x855
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2133 /*0x855*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043d9ce  66899a48565500         -mov word ptr [edx + 0x555648], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5592648) /* 0x555648 */) = cpu.bx;
    // 0043d9d5  66c782685655000100     -mov word ptr [edx + 0x555668], 1
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5592680) /* 0x555668 */) = 1 /*0x1*/;
    // 0043d9de  c7048588565500fd9d64ff -mov dword ptr [eax*4 + 0x555688], 0xff649dfd
    app->getMemory<x86::reg32>(x86::reg32(5592712) /* 0x555688 */ + cpu.eax * 4) = 4284784125 /*0xff649dfd*/;
    // 0043d9e9  ebc8                   -jmp 0x43d9b3
    goto L_0x0043d9b3;
L_0x0043d9eb:
    // 0043d9eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d9ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d9ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d9ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d9ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43d9f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d9f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d9f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d9f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d9f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043d9f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d9f7  3b0504d26f00           +cmp eax, dword ptr [0x6fd204]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328260) /* 0x6fd204 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d9fd  7d3e                   -jge 0x43da3d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043da3d;
    }
    // 0043d9ff  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043da02  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043da04  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043da07  80b874c96f0000         +cmp byte ptr [eax + 0x6fc974], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7326068) /* 0x6fc974 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043da0e  740a                   -je 0x43da1a
    if (cpu.flags.zf)
    {
        goto L_0x0043da1a;
    }
    // 0043da10  0570c96f00             -add eax, 0x6fc970
    (cpu.eax) += x86::reg32(x86::sreg32(7326064 /*0x6fc970*/));
    // 0043da15  83c004                 +add eax, 4
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
    // 0043da18  eb0a                   -jmp 0x43da24
    goto L_0x0043da24;
L_0x0043da1a:
    // 0043da1a  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 0043da1f  e82c3e0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
L_0x0043da24:
    // 0043da24  66c70455685655000100   -mov word ptr [edx*2 + 0x555668], 1
    app->getMemory<x86::reg16>(x86::reg32(5592680) /* 0x555668 */ + cpu.edx * 2) = 1 /*0x1*/;
    // 0043da2e  c7049588565500fd9d64ff -mov dword ptr [edx*4 + 0x555688], 0xff649dfd
    app->getMemory<x86::reg32>(x86::reg32(5592712) /* 0x555688 */ + cpu.edx * 4) = 4284784125 /*0xff649dfd*/;
    // 0043da39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043da3d:
    // 0043da3d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043da3f  66890c4568565500       -mov word ptr [eax*2 + 0x555668], cx
    app->getMemory<x86::reg16>(x86::reg32(5592680) /* 0x555668 */ + cpu.eax * 2) = cpu.cx;
    // 0043da47  b827000000             -mov eax, 0x27
    cpu.eax = 39 /*0x27*/;
    // 0043da4c  e8ff3d0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043da51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da52  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da53  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_43da60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043da60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043da61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043da62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043da63  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043da65  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043da68  c645f009               -mov byte ptr [ebp - 0x10], 9
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 9 /*0x9*/;
    // 0043da6c  a0f4d46f00             -mov al, byte ptr [0x6fd4f4]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 0043da71  8845f1                 -mov byte ptr [ebp - 0xf], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) = cpu.al;
    // 0043da74  a1dcd26f00             -mov eax, dword ptr [0x6fd2dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328476) /* 0x6fd2dc */);
    // 0043da79  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0043da7c  a1e0d26f00             -mov eax, dword ptr [0x6fd2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328480) /* 0x6fd2e0 */);
    // 0043da81  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0043da86  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043da89  a1e4d26f00             -mov eax, dword ptr [0x6fd2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328484) /* 0x6fd2e4 */);
    // 0043da8e  8d55f0                 -lea edx, [ebp - 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043da91  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043da94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043da96  e845860600             -call 0x4a60e0
    cpu.esp -= 4;
    sub_4a60e0(app, cpu);
    if (cpu.terminate) return;
    // 0043da9b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043da9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043daa0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_43dab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043dab0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043dab1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043dab3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043dab5  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0043dab8  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0043dabf  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043dac1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043dac4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043dac6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043dac9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043dacb  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0043dace  899850d56f00           -mov dword ptr [eax + 0x6fd550], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7329104) /* 0x6fd550 */) = cpu.ebx;
    // 0043dad4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043dad6  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0043dad9  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0043dae0  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043dae2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043dae5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043dae7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043daea  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043daec  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0043daef  898354d56f00           -mov dword ptr [ebx + 0x6fd554], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(7329108) /* 0x6fd554 */) = cpu.eax;
    // 0043daf5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043daf7  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0043dafa  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0043db01  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043db03  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043db06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043db08  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043db0b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043db0d  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0043db10  898358d56f00           -mov dword ptr [ebx + 0x6fd558], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(7329112) /* 0x6fd558 */) = cpu.eax;
    // 0043db16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43db20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043db20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043db21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043db22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043db23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043db24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043db25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043db26  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043db28  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0043db2b  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0043db30  ba14000400             -mov edx, 0x40014
    cpu.edx = 262164 /*0x40014*/;
    // 0043db35  b8dc775300             -mov eax, 0x5377dc
    cpu.eax = 5470172 /*0x5377dc*/;
    // 0043db3a  e8e13a0a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0043db3f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043db41  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 0043db44  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043db46  66c740040001           -mov word ptr [eax + 4], 0x100
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 256 /*0x100*/;
    // 0043db4c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043db4e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0043db50  66c740060001           -mov word ptr [eax + 6], 0x100
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 256 /*0x100*/;
    // 0043db56  80ca7d                 +or dl, 0x7d
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(125 /*0x7d*/))));
    // 0043db59  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0043db5c  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0043db5e  eb22                   -jmp 0x43db82
    goto L_0x0043db82;
L_0x0043db60:
    // 0043db60  81fa00010000           +cmp edx, 0x100
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043db66  7d11                   -jge 0x43db79
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043db79;
    }
    // 0043db68  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043db6b  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043db6e  0d000000ff             +or eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/))));
    // 0043db73  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043db74  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043db77  ebe7                   -jmp 0x43db60
    goto L_0x0043db60;
L_0x0043db79:
    // 0043db79  41                     -inc ecx
    (cpu.ecx)++;
    // 0043db7a  81f900010000           +cmp ecx, 0x100
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043db80  7d2f                   -jge 0x43dbb1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043dbb1;
    }
L_0x0043db82:
    // 0043db82  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0043db87  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043db8a  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0043db8d  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0043db90  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0043db93  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043db96  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 0043db99  e882020000             -call 0x43de20
    cpu.esp -= 4;
    sub_43de20(app, cpu);
    if (cpu.terminate) return;
    // 0043db9e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043dba0  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043dba3  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043dba6  0d000000ff             +or eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/))));
    // 0043dbab  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043dbac  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043dbaf  ebaf                   -jmp 0x43db60
    goto L_0x0043db60;
L_0x0043dbb1:
    // 0043dbb1  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0043dbb6  b8d03d5f00             -mov eax, 0x5f3dd0
    cpu.eax = 6241744 /*0x5f3dd0*/;
    // 0043dbbb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043dbbd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043dbbf  e8ac840900             -call 0x4d6070
    cpu.esp -= 4;
    sub_4d6070(app, cpu);
    if (cpu.terminate) return;
    // 0043dbc4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043dbc6  e8c53c0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043dbcb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043dbcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbd2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
