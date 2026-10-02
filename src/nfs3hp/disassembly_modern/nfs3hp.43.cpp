#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4f7ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7ce1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7ce2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7ce3  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7ce6  833de077560000         +cmp dword ptr [0x5677e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666784) /* 0x5677e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7ced  7410                   -je 0x4f7cff
    if (cpu.flags.zf)
    {
        goto L_0x004f7cff;
    }
    // 004f7cef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f7cf1  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7cf7  ff15e0775600           -call dword ptr [0x5677e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666784) /* 0x5677e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7cfd  eb60                   -jmp 0x4f7d5f
    goto L_0x004f7d5f;
L_0x004f7cff:
    // 004f7cff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7d01  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d07  e81cda0100             -call 0x515728
    cpu.esp -= 4;
    sub_515728(app, cpu);
    if (cpu.terminate) return;
    // 004f7d0c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004f7d0e:
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 004f7d0e  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f7d12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d13  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7d15  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7d19  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d1a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7d1b  2eff15a0455300         -call dword ptr cs:[0x5345a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457312) /* 0x5345a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d22  837c241400             +cmp dword ptr [esp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7d27  7421                   -je 0x4f7d4a
    if (cpu.flags.zf)
    {
        goto L_0x004f7d4a;
    }
    // 004f7d29  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f7d2b  e860d90100             -call 0x515690
    cpu.esp -= 4;
    sub_515690(app, cpu);
    if (cpu.terminate) return;
    // 004f7d30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7d32  7516                   -jne 0x4f7d4a
    if (!cpu.flags.zf)
    {
        goto L_0x004f7d4a;
    }
    // 004f7d34  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f7d38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d39  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7d3b  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7d3f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7d41  2eff15ac455300         -call dword ptr cs:[0x5345ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457324) /* 0x5345ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d48  ebc4                   -jmp 0x4f7d0e
    goto L_0x004f7d0e;
L_0x004f7d4a:
    // 004f7d4a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7d4c  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d52  837c241400             +cmp dword ptr [esp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7d57  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f7d5a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004f7d5f:
    // 004f7d5f  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7d62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7d63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7d64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7d65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7d70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7d72  0f85e8a90000           -jne 0x502760
    if (!cpu.flags.zf)
    {
        return sub_502760(app, cpu);
    }
    // 004f7d78  e8d3da0100             -call 0x515850
    cpu.esp -= 4;
    sub_515850(app, cpu);
    if (cpu.terminate) return;
    // 004f7d7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7d7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7d80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7d81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7d82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7d83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7d84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7d85  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7d87  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f7d89  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004f7d8c  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d92  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f7d95  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7d99  7507                   -jne 0x4f7da2
    if (!cpu.flags.zf)
    {
        goto L_0x004f7da2;
    }
    // 004f7d9b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f7d9d  e81eac0000             -call 0x5029c0
    cpu.esp -= 4;
    sub_5029c0(app, cpu);
    if (cpu.terminate) return;
L_0x004f7da2:
    // 004f7da2  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004f7da5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f7da7  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004f7daa  7415                   -je 0x4f7dc1
    if (cpu.flags.zf)
    {
        goto L_0x004f7dc1;
    }
    // 004f7dac  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004f7dae  80e2f9                 -and dl, 0xf9
    cpu.dl &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004f7db1  88510d                 -mov byte ptr [ecx + 0xd], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.dl;
    // 004f7db4  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004f7db6  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004f7db9  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f7dbe  88710d                 -mov byte ptr [ecx + 0xd], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.dh;
L_0x004f7dc1:
    // 004f7dc1  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f7dc3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f7dc5:
    // 004f7dc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7dc7  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004f7dc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7dcb  740f                   -je 0x4f7ddc
    if (cpu.flags.zf)
    {
        goto L_0x004f7ddc;
    }
    // 004f7dcd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f7dcf  43                     -inc ebx
    (cpu.ebx)++;
    // 004f7dd0  e8db190100             -call 0x5097b0
    cpu.esp -= 4;
    sub_5097b0(app, cpu);
    if (cpu.terminate) return;
    // 004f7dd5  83f8ff                 +cmp eax, -1
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
    // 004f7dd8  75eb                   -jne 0x4f7dc5
    if (!cpu.flags.zf)
    {
        goto L_0x004f7dc5;
    }
    // 004f7dda  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004f7ddc:
    // 004f7ddc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f7dde  741d                   -je 0x4f7dfd
    if (cpu.flags.zf)
    {
        goto L_0x004f7dfd;
    }
    // 004f7de0  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004f7de3  24f9                   -and al, 0xf9
    cpu.al &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004f7de5  88410d                 -mov byte ptr [ecx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004f7de8  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004f7dea  80cc04                 -or ah, 4
    cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004f7ded  88610d                 -mov byte ptr [ecx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004f7df0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7df2  7509                   -jne 0x4f7dfd
    if (!cpu.flags.zf)
    {
        goto L_0x004f7dfd;
    }
    // 004f7df4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f7df6  e865a90000             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
    // 004f7dfb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004f7dfd:
    // 004f7dfd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7dff  7504                   -jne 0x4f7e05
    if (!cpu.flags.zf)
    {
        goto L_0x004f7e05;
    }
    // 004f7e01  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004f7e03  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004f7e05:
    // 004f7e05  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004f7e08  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7e0e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f7e10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7e20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7e21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7e22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7e23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7e24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7e25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7e26  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7e29  8b35b8389f00           -mov esi, dword ptr [0x9f38b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */);
    // 004f7e2f  8b3db4389f00           -mov edi, dword ptr [0x9f38b4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */);
    // 004f7e35  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7e37  a168715600             -mov eax, dword ptr [0x567168]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */);
    // 004f7e3c  83f801                 +cmp eax, 1
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
    // 004f7e3f  7244                   -jb 0x4f7e85
    if (cpu.flags.cf)
    {
        goto L_0x004f7e85;
    }
    // 004f7e41  7607                   -jbe 0x4f7e4a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f7e4a;
    }
    // 004f7e43  83f802                 +cmp eax, 2
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
    // 004f7e46  7424                   -je 0x4f7e6c
    if (cpu.flags.zf)
    {
        goto L_0x004f7e6c;
    }
    // 004f7e48  eb3b                   -jmp 0x4f7e85
    goto L_0x004f7e85;
L_0x004f7e4a:
    // 004f7e4a  4e                     -dec esi
    (cpu.esi)--;
    // 004f7e4b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f7e4d  740c                   -je 0x4f7e5b
    if (cpu.flags.zf)
    {
        goto L_0x004f7e5b;
    }
    // 004f7e4f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7e51  7512                   -jne 0x4f7e65
    if (!cpu.flags.zf)
    {
        goto L_0x004f7e65;
    }
    // 004f7e53  893568715600           -mov dword ptr [0x567168], esi
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = cpu.esi;
    // 004f7e59  eb0a                   -jmp 0x4f7e65
    goto L_0x004f7e65;
L_0x004f7e5b:
    // 004f7e5b  c7056871560002000000   -mov dword ptr [0x567168], 2
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = 2 /*0x2*/;
L_0x004f7e65:
    // 004f7e65  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f7e67  e9a2000000             -jmp 0x4f7f0e
    goto L_0x004f7f0e;
L_0x004f7e6c:
    // 004f7e6c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7e6e  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f7e71  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004f7e76  a368715600             -mov dword ptr [0x567168], eax
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = cpu.eax;
    // 004f7e7b  a1b0389f00             -mov eax, dword ptr [0x9f38b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434736) /* 0x9f38b0 */);
    // 004f7e80  e989000000             -jmp 0x4f7f0e
    goto L_0x004f7f0e;
L_0x004f7e85:
    // 004f7e85  8935b8389f00           -mov dword ptr [0x9f38b8], esi
    app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */) = cpu.esi;
    // 004f7e8b  893db4389f00           -mov dword ptr [0x9f38b4], edi
    app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */) = cpu.edi;
L_0x004f7e91:
    // 004f7e91  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f7e95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7e96  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7e98  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7e9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7e9d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7e9e  2eff15ac455300         -call dword ptr cs:[0x5345ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457324) /* 0x5345ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7ea5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7ea7  7454                   -je 0x4f7efd
    if (cpu.flags.zf)
    {
        goto L_0x004f7efd;
    }
    // 004f7ea9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f7eab  e8e0d70100             -call 0x515690
    cpu.esp -= 4;
    sub_515690(app, cpu);
    if (cpu.terminate) return;
    // 004f7eb0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7eb2  74dd                   -je 0x4f7e91
    if (cpu.flags.zf)
    {
        goto L_0x004f7e91;
    }
    // 004f7eb4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7eb6  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7ebb  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004f7ebe  8a642411               -mov ah, byte ptr [esp + 0x11]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 004f7ec2  0fb67c240e             -movzx edi, byte ptr [esp + 0xe]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(14) /* 0xe */));
    // 004f7ec7  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004f7eca  7504                   -jne 0x4f7ed0
    if (!cpu.flags.zf)
    {
        goto L_0x004f7ed0;
    }
    // 004f7ecc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f7ece  751b                   -jne 0x4f7eeb
    if (!cpu.flags.zf)
    {
        goto L_0x004f7eeb;
    }
L_0x004f7ed0:
    // 004f7ed0  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 004f7ed5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7ed7  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004f7ed9  668b44240c             -mov ax, word ptr [esp + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f7ede  892d68715600           -mov dword ptr [0x567168], ebp
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = cpu.ebp;
    // 004f7ee4  a3b0389f00             -mov dword ptr [0x9f38b0], eax
    app->getMemory<x86::reg32>(x86::reg32(10434736) /* 0x9f38b0 */) = cpu.eax;
    // 004f7ee9  eb0e                   -jmp 0x4f7ef9
    goto L_0x004f7ef9;
L_0x004f7eeb:
    // 004f7eeb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7eed  740a                   -je 0x4f7ef9
    if (cpu.flags.zf)
    {
        goto L_0x004f7ef9;
    }
    // 004f7eef  c7056871560001000000   -mov dword ptr [0x567168], 1
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = 1 /*0x1*/;
L_0x004f7ef9:
    // 004f7ef9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f7efb  eb11                   -jmp 0x4f7f0e
    goto L_0x004f7f0e;
L_0x004f7efd:
    // 004f7efd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f7f02  8b3db4389f00           -mov edi, dword ptr [0x9f38b4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */);
    // 004f7f08  8b35b8389f00           -mov esi, dword ptr [0x9f38b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */);
L_0x004f7f0e:
    // 004f7f0e  893db4389f00           -mov dword ptr [0x9f38b4], edi
    app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */) = cpu.edi;
    // 004f7f14  8935b8389f00           -mov dword ptr [0x9f38b8], esi
    app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */) = cpu.esi;
    // 004f7f1a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7f1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f22  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7f24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7f24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7f26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7f27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7f28  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7f2b  a128785600             -mov eax, dword ptr [0x567828]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5666856) /* 0x567828 */);
    // 004f7f30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7f32  740a                   -je 0x4f7f3e
    if (cpu.flags.zf)
    {
        goto L_0x004f7f3e;
    }
    // 004f7f34  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004f7f36  893528785600           -mov dword ptr [0x567828], esi
    app->getMemory<x86::reg32>(x86::reg32(5666856) /* 0x567828 */) = cpu.esi;
    // 004f7f3c  eb5a                   -jmp 0x4f7f98
    goto L_0x004f7f98;
L_0x004f7f3e:
    // 004f7f3e  833de477560000         +cmp dword ptr [0x5677e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666788) /* 0x5677e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7f45  7410                   -je 0x4f7f57
    if (cpu.flags.zf)
    {
        goto L_0x004f7f57;
    }
    // 004f7f47  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f4d  ff15e4775600           -call dword ptr [0x5677e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666788) /* 0x5677e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f53  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7f55  eb3f                   -jmp 0x4f7f96
    goto L_0x004f7f96;
L_0x004f7f57:
    // 004f7f57  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f5d  e8c6d70100             -call 0x515728
    cpu.esp -= 4;
    sub_515728(app, cpu);
    if (cpu.terminate) return;
    // 004f7f62  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7f64  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f7f66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7f67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f68  2eff15fc445300         -call dword ptr cs:[0x5344fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457148) /* 0x5344fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f6f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f7f71  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f72  2eff15d0455300         -call dword ptr cs:[0x5345d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457360) /* 0x5345d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f79  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f7f7b  e8a0feffff             -call 0x4f7e20
    cpu.esp -= 4;
    sub_4f7e20(app, cpu);
    if (cpu.terminate) return;
    // 004f7f80  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f7f83  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7f84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f85  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7f87  2eff15d0455300         -call dword ptr cs:[0x5345d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457360) /* 0x5345d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7f90  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f7f96:
    // 004f7f96  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004f7f98:
    // 004f7f98  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7f9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7fa0  e9fbd80100             -jmp 0x5158a0
    return sub_5158a0(app, cpu);
}

/* align: skip  */
/* data blob: 03104000574154434f4d20432f432b2b33322052756e2d54696d652073797374656d2e2028632920436f7079726967687420627920574154434f4d20496e7465726e6174696f6e616c20436f72702e20313938382d313939352e20416c6c207269676874732072657365727665642e000000000000000000000000 */
void Application::sub_4f8020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8021  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f8022  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f8024  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004f8026:
    // 004f8026  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004f8028  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f802a  740d                   -je 0x4f8039
    if (cpu.flags.zf)
    {
        goto L_0x004f8039;
    }
    // 004f802c  2c61                   -sub al, 0x61
    (cpu.al) -= x86::reg8(x86::sreg8(97 /*0x61*/));
    // 004f802e  3c19                   +cmp al, 0x19
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(25 /*0x19*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8030  7704                   -ja 0x4f8036
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f8036;
    }
    // 004f8032  0441                   +add al, 0x41
    {
        x86::reg8& tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(65 /*0x41*/));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f8034  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
L_0x004f8036:
    // 004f8036  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f8037  ebed                   -jmp 0x4f8026
    goto L_0x004f8026;
L_0x004f8039:
    // 004f8039  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f803b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f803c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f803d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f8040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8042  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8043  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8044  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f8046  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f8048  e8dfdb0100             -call 0x515c2c
    cpu.esp -= 4;
    sub_515c2c(app, cpu);
    if (cpu.terminate) return;
    // 004f804d  b8df630000             -mov eax, 0x63df
    cpu.eax = 25567 /*0x63df*/;
    // 004f8052  8b1d948b5600           -mov ebx, dword ptr [0x568b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5671828) /* 0x568b94 */);
    // 004f8058  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004f805a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f805c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f805e  e83ddf0100             -call 0x515fa0
    cpu.esp -= 4;
    sub_515fa0(app, cpu);
    if (cpu.terminate) return;
    // 004f8063  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f8065  e806e20100             -call 0x516270
    cpu.esp -= 4;
    sub_516270(app, cpu);
    if (cpu.terminate) return;
    // 004f806a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f806c  741c                   -je 0x4f808a
    if (cpu.flags.zf)
    {
        goto L_0x004f808a;
    }
    // 004f806e  b8df630000             -mov eax, 0x63df
    cpu.eax = 25567 /*0x63df*/;
    // 004f8073  8b1d948b5600           -mov ebx, dword ptr [0x568b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5671828) /* 0x568b94 */);
    // 004f8079  8b159c8b5600           -mov edx, dword ptr [0x568b9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */);
    // 004f807f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004f8081  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f8083  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f8085  e816df0100             -call 0x515fa0
    cpu.esp -= 4;
    sub_515fa0(app, cpu);
    if (cpu.terminate) return;
L_0x004f808a:
    // 004f808a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f808c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f808d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f808e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f808f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8090  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f8094(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8094  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8095  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f8096  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f8098  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f809e  8d5014                 -lea edx, [eax + 0x14]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004f80a1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f80a3  e898ffffff             -call 0x4f8040
    cpu.esp -= 4;
    sub_4f8040(app, cpu);
    if (cpu.terminate) return;
    // 004f80a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f80a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f80aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f80ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f80ac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f80ad  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f80af  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f80b2  eb31                   -jmp 0x4f80e5
    return sub_4f80e5(app, cpu);
}

/* align: skip  */
void Application::sub_4f80b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f80b4  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
    // 004f80b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f80b7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f80b9  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f80bc  dc156c715600           +fcom qword ptr [0x56716c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5665132) /* 0x56716c */)));
    // 004f80c2  9b                     -wait 
    /*nothing*/;
    // 004f80c3  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80c6  9b                     -wait 
    /*nothing*/;
    // 004f80c7  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80ca  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80cb  7618                   -jbe 0x4f80e5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f80e5;
    }
    // 004f80cd  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f80cf  740e                   -je 0x4f80df
    if (cpu.flags.zf)
    {
        goto L_0x004f80df;
    }
    // 004f80d1  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f80d4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004f80d7  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004f80da  e87de40100             -call 0x51655c
    cpu.esp -= 4;
    sub_51655c(app, cpu);
    if (cpu.terminate) return;
L_0x004f80df:
    // 004f80df  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004f80e1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f80e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f80e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f80e5:
    // 004f80e5  dc1574715600           +fcom qword ptr [0x567174]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5665140) /* 0x567174 */)));
    // 004f80eb  9b                     -wait 
    /*nothing*/;
    // 004f80ec  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80ef  9b                     -wait 
    /*nothing*/;
    // 004f80f0  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80f3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80f4  7704                   -ja 0x4f80fa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f80fa;
    }
    // 004f80f6  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004f80f8  eb14                   -jmp 0x4f810e
    goto L_0x004f810e;
L_0x004f80fa:
    // 004f80fa  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 004f80fc  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f80fe  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004f8100  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 004f8102  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004f8104  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 004f8106  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 004f8108  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004f810a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f810c  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x004f810e:
    // 004f810e  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f8110  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004f8112  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f8114  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8115  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f80e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f80e5;
    // 004f80b4  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
    // 004f80b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f80b7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f80b9  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f80bc  dc156c715600           +fcom qword ptr [0x56716c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5665132) /* 0x56716c */)));
    // 004f80c2  9b                     -wait 
    /*nothing*/;
    // 004f80c3  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80c6  9b                     -wait 
    /*nothing*/;
    // 004f80c7  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80ca  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80cb  7618                   -jbe 0x4f80e5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f80e5;
    }
    // 004f80cd  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f80cf  740e                   -je 0x4f80df
    if (cpu.flags.zf)
    {
        goto L_0x004f80df;
    }
    // 004f80d1  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f80d4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004f80d7  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004f80da  e87de40100             -call 0x51655c
    cpu.esp -= 4;
    sub_51655c(app, cpu);
    if (cpu.terminate) return;
L_0x004f80df:
    // 004f80df  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004f80e1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f80e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f80e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f80e5:
L_entry_0x004f80e5:
    // 004f80e5  dc1574715600           +fcom qword ptr [0x567174]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5665140) /* 0x567174 */)));
    // 004f80eb  9b                     -wait 
    /*nothing*/;
    // 004f80ec  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80ef  9b                     -wait 
    /*nothing*/;
    // 004f80f0  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80f3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80f4  7704                   -ja 0x4f80fa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f80fa;
    }
    // 004f80f6  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004f80f8  eb14                   -jmp 0x4f810e
    goto L_0x004f810e;
L_0x004f80fa:
    // 004f80fa  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 004f80fc  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f80fe  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004f8100  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 004f8102  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004f8104  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 004f8106  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 004f8108  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004f810a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f810c  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x004f810e:
    // 004f810e  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f8110  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004f8112  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f8114  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8115  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f80b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f80b6;
    // 004f80b4  b004                   -mov al, 4
    cpu.al = 4 /*0x4*/;
L_entry_0x004f80b6:
    // 004f80b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f80b7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f80b9  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f80bc  dc156c715600           +fcom qword ptr [0x56716c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5665132) /* 0x56716c */)));
    // 004f80c2  9b                     -wait 
    /*nothing*/;
    // 004f80c3  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80c6  9b                     -wait 
    /*nothing*/;
    // 004f80c7  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80ca  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80cb  7618                   -jbe 0x4f80e5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f80e5;
    }
    // 004f80cd  3c07                   +cmp al, 7
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f80cf  740e                   -je 0x4f80df
    if (cpu.flags.zf)
    {
        goto L_0x004f80df;
    }
    // 004f80d1  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f80d4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004f80d7  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004f80da  e87de40100             -call 0x51655c
    cpu.esp -= 4;
    sub_51655c(app, cpu);
    if (cpu.terminate) return;
L_0x004f80df:
    // 004f80df  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004f80e1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f80e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f80e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f80e5:
    // 004f80e5  dc1574715600           +fcom qword ptr [0x567174]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5665140) /* 0x567174 */)));
    // 004f80eb  9b                     -wait 
    /*nothing*/;
    // 004f80ec  dd7df0                 -fnstsw word ptr [ebp - 0x10]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.fpu.status.word;
    // 004f80ef  9b                     -wait 
    /*nothing*/;
    // 004f80f0  8a65f1                 -mov ah, byte ptr [ebp - 0xf]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 004f80f3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f80f4  7704                   -ja 0x4f80fa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f80fa;
    }
    // 004f80f6  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004f80f8  eb14                   -jmp 0x4f810e
    goto L_0x004f810e;
L_0x004f80fa:
    // 004f80fa  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 004f80fc  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f80fe  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004f8100  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 004f8102  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004f8104  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 004f8106  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 004f8108  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004f810a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004f810c  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
L_0x004f810e:
    // 004f810e  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f8110  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004f8112  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f8114  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8115  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f8116(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8116  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004f811a  e895ffffff             -call 0x4f80b4
    cpu.esp -= 4;
    sub_4f80b4(app, cpu);
    if (cpu.terminate) return;
    // 004f811f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4f8122(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8122  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8123  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f8125  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8126  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8127  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8128  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004f812b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f812d  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 004f8130  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x004f8133:
    // 004f8133  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004f8135  80fa20                 +cmp dl, 0x20
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8138  740a                   -je 0x4f8144
    if (cpu.flags.zf)
    {
        goto L_0x004f8144;
    }
    // 004f813a  80fa09                 +cmp dl, 9
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f813d  7208                   -jb 0x4f8147
    if (cpu.flags.cf)
    {
        goto L_0x004f8147;
    }
    // 004f813f  80fa0d                 +cmp dl, 0xd
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8142  7703                   -ja 0x4f8147
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f8147;
    }
L_0x004f8144:
    // 004f8144  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f8145  ebec                   -jmp 0x4f8133
    goto L_0x004f8133;
L_0x004f8147:
    // 004f8147  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004f814a  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004f814c  80fa2b                 +cmp dl, 0x2b
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f814f  7407                   -je 0x4f8158
    if (cpu.flags.zf)
    {
        goto L_0x004f8158;
    }
    // 004f8151  80fa2d                 +cmp dl, 0x2d
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8154  7504                   -jne 0x4f815a
    if (!cpu.flags.zf)
    {
        goto L_0x004f815a;
    }
    // 004f8156  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004f8158:
    // 004f8158  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004f815a:
    // 004f815a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f815c  b630                   -mov dh, 0x30
    cpu.dh = 48 /*0x30*/;
    // 004f815e  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
L_0x004f8161:
    // 004f8161  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004f8163  40                     -inc eax
    (cpu.eax)++;
    // 004f8164  80fa2e                 +cmp dl, 0x2e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8167  750a                   -jne 0x4f8173
    if (!cpu.flags.zf)
    {
        goto L_0x004f8173;
    }
    // 004f8169  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004f816c  752d                   -jne 0x4f819b
    if (!cpu.flags.zf)
    {
        goto L_0x004f819b;
    }
    // 004f816e  80c908                 +or cl, 8
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004f8171  ebee                   -jmp 0x4f8161
    goto L_0x004f8161;
L_0x004f8173:
    // 004f8173  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8176  7223                   -jb 0x4f819b
    if (cpu.flags.cf)
    {
        goto L_0x004f819b;
    }
    // 004f8178  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f817b  771e                   -ja 0x4f819b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f819b;
    }
    // 004f817d  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 004f8180  7403                   -je 0x4f8185
    if (cpu.flags.zf)
    {
        goto L_0x004f8185;
    }
    // 004f8182  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
L_0x004f8185:
    // 004f8185  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 004f8187  80fe30                 +cmp dh, 0x30
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f818a  740a                   -je 0x4f8196
    if (cpu.flags.zf)
    {
        goto L_0x004f8196;
    }
    // 004f818c  83fb13                 +cmp ebx, 0x13
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f818f  7d04                   -jge 0x4f8195
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f8195;
    }
    // 004f8191  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
L_0x004f8195:
    // 004f8195  43                     -inc ebx
    (cpu.ebx)++;
L_0x004f8196:
    // 004f8196  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004f8199  ebc6                   -jmp 0x4f8161
    goto L_0x004f8161;
L_0x004f819b:
    // 004f819b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f819d  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004f81a0  0f8465000000           -je 0x4f820b
    if (cpu.flags.zf)
    {
        goto L_0x004f820b;
    }
    // 004f81a6  80fa65                 +cmp dl, 0x65
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(101 /*0x65*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81a9  7405                   -je 0x4f81b0
    if (cpu.flags.zf)
    {
        goto L_0x004f81b0;
    }
    // 004f81ab  80fa45                 +cmp dl, 0x45
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81ae  7557                   -jne 0x4f8207
    if (!cpu.flags.zf)
    {
        goto L_0x004f8207;
    }
L_0x004f81b0:
    // 004f81b0  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004f81b3  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 004f81b5  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004f81b8  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004f81bb  80fd2b                 +cmp ch, 0x2b
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81be  7408                   -je 0x4f81c8
    if (cpu.flags.zf)
    {
        goto L_0x004f81c8;
    }
    // 004f81c0  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81c3  7505                   -jne 0x4f81ca
    if (!cpu.flags.zf)
    {
        goto L_0x004f81ca;
    }
    // 004f81c5  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004f81c8:
    // 004f81c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004f81ca:
    // 004f81ca  80e1fb                 -and cl, 0xfb
    cpu.cl &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x004f81cd:
    // 004f81cd  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004f81cf  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81d2  7222                   -jb 0x4f81f6
    if (cpu.flags.cf)
    {
        goto L_0x004f81f6;
    }
    // 004f81d4  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f81d7  771d                   -ja 0x4f81f6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f81f6;
    }
    // 004f81d9  81fee8030000           +cmp esi, 0x3e8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f81df  7d0f                   -jge 0x4f81f0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f81f0;
    }
    // 004f81e1  6bf60a                 -imul esi, esi, 0xa
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004f81e4  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
    // 004f81e7  0fb6f2                 -movzx esi, dl
    cpu.esi = x86::reg32(cpu.dl);
    // 004f81ea  0375ec                 -add esi, dword ptr [ebp - 0x14]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004f81ed  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x004f81f0:
    // 004f81f0  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004f81f3  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f81f4  ebd7                   -jmp 0x4f81cd
    goto L_0x004f81cd;
L_0x004f81f6:
    // 004f81f6  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004f81f9  7402                   -je 0x4f81fd
    if (cpu.flags.zf)
    {
        goto L_0x004f81fd;
    }
    // 004f81fb  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
L_0x004f81fd:
    // 004f81fd  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004f8200  7506                   -jne 0x4f8208
    if (!cpu.flags.zf)
    {
        goto L_0x004f8208;
    }
    // 004f8202  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004f8205  eb01                   -jmp 0x4f8208
    goto L_0x004f8208;
L_0x004f8207:
    // 004f8207  48                     -dec eax
    (cpu.eax)--;
L_0x004f8208:
    // 004f8208  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x004f820b:
    // 004f820b  837de800               +cmp dword ptr [ebp - 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f820f  7408                   -je 0x4f8219
    if (cpu.flags.zf)
    {
        goto L_0x004f8219;
    }
    // 004f8211  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f8214  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004f8217  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004f8219:
    // 004f8219  2b75e4                 -sub esi, dword ptr [ebp - 0x1c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 004f821c  83fb13                 +cmp ebx, 0x13
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f821f  7e0a                   -jle 0x4f822b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f822b;
    }
    // 004f8221  83eb13                 -sub ebx, 0x13
    (cpu.ebx) -= x86::reg32(x86::sreg32(19 /*0x13*/));
    // 004f8224  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f8226  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
L_0x004f822b:
    // 004f822b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f822d  7e0b                   -jle 0x4f823a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f823a;
    }
    // 004f822f  807c2bbf30             +cmp byte ptr [ebx + ebp - 0x41], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-65) /* -0x41 */ + cpu.ebp * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8234  7504                   -jne 0x4f823a
    if (!cpu.flags.zf)
    {
        goto L_0x004f823a;
    }
    // 004f8236  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f8237  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f8238  ebf1                   -jmp 0x4f822b
    goto L_0x004f822b;
L_0x004f823a:
    // 004f823a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f823c  7511                   -jne 0x4f824f
    if (!cpu.flags.zf)
    {
        goto L_0x004f824f;
    }
    // 004f823e  66c747080000           -mov word ptr [edi + 8], 0
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f8244  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004f8247  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8249  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 004f824b  31f8                   +xor eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004f824d  eb5f                   -jmp 0x4f82ae
    goto L_0x004f82ae;
L_0x004f824f:
    // 004f824f  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004f8251  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004f8254  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
    // 004f8258  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f825b  e878e30100             -call 0x5165d8
    cpu.esp -= 4;
    sub_5165d8(app, cpu);
    if (cpu.terminate) return;
    // 004f8260  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f8262  740a                   -je 0x4f826e
    if (cpu.flags.zf)
    {
        goto L_0x004f826e;
    }
    // 004f8264  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f8267  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f8269  e8ebe40100             -call 0x516759
    cpu.esp -= 4;
    sub_516759(app, cpu);
    if (cpu.terminate) return;
L_0x004f826e:
    // 004f826e  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 004f8271  7404                   -je 0x4f8277
    if (cpu.flags.zf)
    {
        goto L_0x004f8277;
    }
    // 004f8273  804ddd80               -or byte ptr [ebp - 0x23], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004f8277:
    // 004f8277  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004f827a  66894708               -mov word ptr [edi + 8], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004f827e  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004f8281  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f8284  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f8287  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004f8289  8d441eff               -lea eax, [esi + ebx - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */ + cpu.ebx * 1);
    // 004f828d  3d34010000             +cmp eax, 0x134
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(308 /*0x134*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8292  7e07                   -jle 0x4f829b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f829b;
    }
    // 004f8294  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004f8299  eb13                   -jmp 0x4f82ae
    goto L_0x004f82ae;
L_0x004f829b:
    // 004f829b  3dccfeffff             +cmp eax, 0xfffffecc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966988 /*0xfffffecc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f82a0  7d07                   -jge 0x4f82a9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f82a9;
    }
    // 004f82a2  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004f82a7  eb05                   -jmp 0x4f82ae
    goto L_0x004f82ae;
L_0x004f82a9:
    // 004f82a9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f82ae:
    // 004f82ae  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004f82b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f82b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f82b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f82b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f82b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f82b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f82b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f82b7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f82b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f82ba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f82bb  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f82be  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f82c0  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f82c3  e85afeffff             -call 0x4f8122
    cpu.esp -= 4;
    sub_4f8122(app, cpu);
    if (cpu.terminate) return;
    // 004f82c8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f82ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f82cc  750b                   -jne 0x4f82d9
    if (!cpu.flags.zf)
    {
        goto L_0x004f82d9;
    }
    // 004f82ce  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004f82d1:
    // 004f82d1  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004f82d4  e9ad000000             -jmp 0x4f8386
    goto L_0x004f8386;
L_0x004f82d9:
    // 004f82d9  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004f82dc  80e47f                 -and ah, 0x7f
    cpu.ah &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004f82df  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f82e4  3dff430000             +cmp eax, 0x43ff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17407 /*0x43ff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f82e9  7c2a                   -jl 0x4f8315
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f8315;
    }
    // 004f82eb  e8b4a50000             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 004f82f0  f645dd80               +test byte ptr [ebp - 0x23], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) & 128 /*0x80*/));
    // 004f82f4  7410                   -je 0x4f8306
    if (cpu.flags.zf)
    {
        goto L_0x004f8306;
    }
    // 004f82f6  dd057c215500           +fld qword ptr [0x55217c]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5579132) /* 0x55217c */)));
    // 004f82fc  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004f82fe  dd5de8                 +fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f8301  e980000000             -jmp 0x4f8386
    goto L_0x004f8386;
L_0x004f8306:
    // 004f8306  a17c215500             -mov eax, dword ptr [0x55217c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5579132) /* 0x55217c */);
    // 004f830b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004f830e  a180215500             -mov eax, dword ptr [0x552180]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5579136) /* 0x552180 */);
    // 004f8313  ebbc                   -jmp 0x4f82d1
    goto L_0x004f82d1;
L_0x004f8315:
    // 004f8315  3dcd3b0000             +cmp eax, 0x3bcd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15309 /*0x3bcd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f831a  7d42                   -jge 0x4f835e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f835e;
    }
    // 004f831c  83f8cc                 +cmp eax, -0x34
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-52 /*-0x34*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f831f  7d0f                   -jge 0x4f8330
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f8330;
    }
    // 004f8321  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004f8323  e87ca50000             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 004f8328  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 004f832b  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 004f832e  eb56                   -jmp 0x4f8386
    goto L_0x004f8386;
L_0x004f8330:
    // 004f8330  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f8333  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f8336  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004f8338  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f833a  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f833d  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004f8340  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004f8343  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f8346  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004f8349  a9ffffff7f             +test eax, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483647 /*0x7fffffff*/));
    // 004f834e  7504                   -jne 0x4f8354
    if (!cpu.flags.zf)
    {
        goto L_0x004f8354;
    }
    // 004f8350  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f8352  742d                   -je 0x4f8381
    if (cpu.flags.zf)
    {
        goto L_0x004f8381;
    }
L_0x004f8354:
    // 004f8354  66f745f6f07f           +test word ptr [ebp - 0xa], 0x7ff0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */) & 32752 /*0x7ff0*/));
    // 004f835a  752a                   -jne 0x4f8386
    if (!cpu.flags.zf)
    {
        goto L_0x004f8386;
    }
    // 004f835c  eb23                   -jmp 0x4f8381
    goto L_0x004f8381;
L_0x004f835e:
    // 004f835e  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f8361  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004f8364  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004f8366  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f8368  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f836b  7414                   -je 0x4f8381
    if (cpu.flags.zf)
    {
        goto L_0x004f8381;
    }
    // 004f836d  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004f8370  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004f8373  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004f8376  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004f8379  66f745e6f07f           +test word ptr [ebp - 0x1a], 0x7ff0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */) & 32752 /*0x7ff0*/));
    // 004f837f  7505                   -jne 0x4f8386
    if (!cpu.flags.zf)
    {
        goto L_0x004f8386;
    }
L_0x004f8381:
    // 004f8381  e81ea50000             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
L_0x004f8386:
    // 004f8386  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 004f8389  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004f838c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f838d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f838e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f838f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
/* data blob: a4d3540080f99e00b4d3540070f99e00ccd354002cf99e00dcd3540028f99e00f0d354000cf99e0008d4540008f99e0020d4540010f99e0050d4540000f99e0034d4540004f99e006cd454004cf99e0080d4540030f99e0098d4540074f99e00acd4540060f99e00c4d4540024f99e00dcd454001cf99e00f4d4540050f99e000cd554003cf99e001cd5540078f99e002cd5540084f99e003cd5540054f99e0054d5540040f99e0068d5540020f99e007cd554007cf99e0090d5540044f99e00a8d554006cf99e00bcd5540034f99e00d4d5540058f99e00ecd5540048f99e00fcd5540068f99e0010d6540018f99e0024d6540064f99e0038d654005cf99e0050d6540038f99e0064d6540014f99e000000000000000000 */
void Application::sub_4f84a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f84a8  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004f84a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f84aa  ff158c455300           -call dword ptr [0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f84b0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f84b2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f84b4  7457                   -je 0x4f850d
    if (cpu.flags.zf)
    {
        goto L_0x004f850d;
    }
    // 004f84b6  891d6c4a5600           -mov dword ptr [0x564a6c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */) = cpu.ebx;
    // 004f84bc  be90834f00             -mov esi, 0x4f8390
    cpu.esi = 5211024 /*0x4f8390*/;
L_0x004f84c1:
    // 004f84c1  ad                     -lodsd eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 4;
    }
    else
    {
        cpu.esi += 4;
    }
    // 004f84c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f84c4  7413                   -je 0x4f84d9
    if (cpu.flags.zf)
    {
        goto L_0x004f84d9;
    }
    // 004f84c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f84c7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f84c8  ff1558455300           -call dword ptr [0x534558]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f84ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f84d0  7434                   -je 0x4f8506
    if (cpu.flags.zf)
    {
        goto L_0x004f8506;
    }
    // 004f84d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f84d4  ad                     -lodsd eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 4;
    }
    else
    {
        cpu.esi += 4;
    }
    // 004f84d5  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004f84d7  ebe8                   -jmp 0x4f84c1
    goto L_0x004f84c1;
L_0x004f84d9:
    // 004f84d9  6a68                   -push 0x68
    app->getMemory<x86::reg32>(cpu.esp-4) = 104 /*0x68*/;
    cpu.esp -= 4;
    // 004f84db  6a1f                   -push 0x1f
    app->getMemory<x86::reg32>(cpu.esp-4) = 31 /*0x1f*/;
    cpu.esp -= 4;
    // 004f84dd  ff156cf99e00           -call dword ptr [0x9ef96c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f84e3  ff1580f99e00           -call dword ptr [0x9ef980]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418560) /* 0x9ef980 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f84e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f84eb  7419                   -je 0x4f8506
    if (cpu.flags.zf)
    {
        goto L_0x004f8506;
    }
    // 004f84ed  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f84f0  83fa68                 +cmp edx, 0x68
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(104 /*0x68*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f84f3  7511                   -jne 0x4f8506
    if (!cpu.flags.zf)
    {
        goto L_0x004f8506;
    }
    // 004f84f5  a35c3a7a00             -mov dword ptr [0x7a3a5c], eax
    app->getMemory<x86::reg32>(x86::reg32(8010332) /* 0x7a3a5c */) = cpu.eax;
    // 004f84fa  b814854f00             -mov eax, 0x4f8514
    cpu.eax = 5211412 /*0x4f8514*/;
    // 004f84ff  e81cf7ffff             -call 0x4f7c20
    cpu.esp -= 4;
    sub_4f7c20(app, cpu);
    if (cpu.terminate) return;
    // 004f8504  eb07                   -jmp 0x4f850d
    goto L_0x004f850d;
L_0x004f8506:
    // 004f8506  e809000000             -call 0x4f8514
    cpu.esp -= 4;
    sub_4f8514(app, cpu);
    if (cpu.terminate) return;
    // 004f850b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f850d:
    // 004f850d  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004f8511  61                     -popal 
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
    // 004f8512  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f8514(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8514  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004f8515  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f8517  87056c4a5600           -xchg dword ptr [0x564a6c], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */);
        app->getMemory<x86::reg32>(x86::reg32(5655148) /* 0x564a6c */) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004f851d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f851f  7418                   -je 0x4f8539
    if (cpu.flags.zf)
    {
        goto L_0x004f8539;
    }
    // 004f8521  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f8522  ff15dc445300           -call dword ptr [0x5344dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457116) /* 0x5344dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8528  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f852a  be90834f00             -mov esi, 0x4f8390
    cpu.esi = 5211024 /*0x4f8390*/;
L_0x004f852f:
    // 004f852f  ad                     -lodsd eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 4;
    }
    else
    {
        cpu.esi += 4;
    }
    // 004f8530  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8532  7405                   -je 0x4f8539
    if (cpu.flags.zf)
    {
        goto L_0x004f8539;
    }
    // 004f8534  ad                     -lodsd eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 4;
    }
    else
    {
        cpu.esi += 4;
    }
    // 004f8535  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004f8537  ebf6                   -jmp 0x4f852f
    goto L_0x004f852f;
L_0x004f8539:
    // 004f8539  61                     -popal 
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
    // 004f853a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f853c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f853c  ff1580f99e00           -call dword ptr [0x9ef980]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418560) /* 0x9ef980 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8542  a35c3a7a00             -mov dword ptr [0x7a3a5c], eax
    app->getMemory<x86::reg32>(x86::reg32(8010332) /* 0x7a3a5c */) = cpu.eax;
    // 004f8547  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f8548(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8548  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004f8549  bb308c5600             -mov ebx, 0x568c30
    cpu.ebx = 5671984 /*0x568c30*/;
    // 004f854e  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004f8553  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f8555  e8f6b80000             -call 0x503e50
    cpu.esp -= 4;
    sub_503e50(app, cpu);
    if (cpu.terminate) return;
    // 004f855a  e8d1f50100             -call 0x517b30
    cpu.esp -= 4;
    sub_517b30(app, cpu);
    if (cpu.terminate) return;
    // 004f855f  b8e4625600             -mov eax, 0x5662e4
    cpu.eax = 5661412 /*0x5662e4*/;
    // 004f8564  e8b76fffff             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 004f8569  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 004f856e  e8ed71ffff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004f8573  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8575  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f857a  e8e171ffff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004f857f  e8ac72ffff             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 004f8584  e8970d0000             -call 0x4f9320
    cpu.esp -= 4;
    sub_4f9320(app, cpu);
    if (cpu.terminate) return;
    // 004f8589  833d6843560000         +cmp dword ptr [0x564368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653352) /* 0x564368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8590  7505                   -jne 0x4f8597
    if (!cpu.flags.zf)
    {
        goto L_0x004f8597;
    }
    // 004f8592  e8392e0000             -call 0x4fb3d0
    cpu.esp -= 4;
    sub_4fb3d0(app, cpu);
    if (cpu.terminate) return;
L_0x004f8597:
    // 004f8597  e8547cffff             -call 0x4f01f0
    cpu.esp -= 4;
    sub_4f01f0(app, cpu);
    if (cpu.terminate) return;
    // 004f859c  e8fff50100             -call 0x517ba0
    cpu.esp -= 4;
    sub_517ba0(app, cpu);
    if (cpu.terminate) return;
    // 004f85a1  c70504445600607d5100   -mov dword ptr [0x564404], 0x517d60
    app->getMemory<x86::reg32>(x86::reg32(5653508) /* 0x564404 */) = 5340512 /*0x517d60*/;
    // 004f85ab  e830f80100             -call 0x517de0
    cpu.esp -= 4;
    sub_517de0(app, cpu);
    if (cpu.terminate) return;
    // 004f85b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f85b2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f85b4  e8973c0000             -call 0x4fc250
    cpu.esp -= 4;
    sub_4fc250(app, cpu);
    if (cpu.terminate) return;
    // 004f85b9  e882fa0100             -call 0x518040
    cpu.esp -= 4;
    sub_518040(app, cpu);
    if (cpu.terminate) return;
    // 004f85be  61                     -popal 
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
    // 004f85bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f85c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f85c0  90                     -nop 
    ;
    // 004f85c1  90                     -nop 
    ;
    // 004f85c2  90                     -nop 
    ;
    // 004f85c3  90                     -nop 
    ;
    // 004f85c4  90                     -nop 
    ;
    // 004f85c5  90                     -nop 
    ;
    // 004f85c6  90                     -nop 
    ;
    // 004f85c7  90                     -nop 
    ;
    // 004f85c8  90                     -nop 
    ;
    // 004f85c9  90                     -nop 
    ;
    // 004f85ca  90                     -nop 
    ;
    // 004f85cb  90                     -nop 
    ;
    // 004f85cc  90                     -nop 
    ;
    // 004f85cd  90                     -nop 
    ;
    // 004f85ce  90                     -nop 
    ;
    // 004f85cf  90                     -nop 
    ;
    // 004f85d0  90                     -nop 
    ;
    // 004f85d1  90                     -nop 
    ;
    // 004f85d2  90                     -nop 
    ;
    // 004f85d3  90                     -nop 
    ;
    // 004f85d4  90                     -nop 
    ;
    // 004f85d5  90                     -nop 
    ;
    // 004f85d6  90                     -nop 
    ;
    // 004f85d7  90                     -nop 
    ;
    // 004f85d8  90                     -nop 
    ;
    // 004f85d9  90                     -nop 
    ;
    // 004f85da  90                     -nop 
    ;
    // 004f85db  90                     -nop 
    ;
    // 004f85dc  90                     -nop 
    ;
    // 004f85dd  90                     -nop 
    ;
    // 004f85de  90                     -nop 
    ;
    // 004f85df  90                     -nop 
    ;
    // 004f85e0  90                     -nop 
    ;
    // 004f85e1  90                     -nop 
    ;
    // 004f85e2  90                     -nop 
    ;
    // 004f85e3  90                     -nop 
    ;
    // 004f85e4  90                     -nop 
    ;
    // 004f85e5  90                     -nop 
    ;
    // 004f85e6  90                     -nop 
    ;
    // 004f85e7  90                     -nop 
    ;
    // 004f85e8  90                     -nop 
    ;
    // 004f85e9  90                     -nop 
    ;
    // 004f85ea  90                     -nop 
    ;
    // 004f85eb  90                     -nop 
    ;
    // 004f85ec  90                     -nop 
    ;
    // 004f85ed  90                     -nop 
    ;
    // 004f85ee  90                     -nop 
    ;
    // 004f85ef  90                     -nop 
    ;
    // 004f85f0  90                     -nop 
    ;
    // 004f85f1  90                     -nop 
    ;
    // 004f85f2  90                     -nop 
    ;
    // 004f85f3  90                     -nop 
    ;
    // 004f85f4  90                     -nop 
    ;
    // 004f85f5  90                     -nop 
    ;
    // 004f85f6  90                     -nop 
    ;
    // 004f85f7  90                     -nop 
    ;
    // 004f85f8  90                     -nop 
    ;
    // 004f85f9  90                     -nop 
    ;
    // 004f85fa  90                     -nop 
    ;
    // 004f85fb  90                     -nop 
    ;
    // 004f85fc  90                     -nop 
    ;
    // 004f85fd  90                     -nop 
    ;
    // 004f85fe  90                     -nop 
    ;
    // 004f85ff  90                     -nop 
    ;
    // 004f8600  90                     -nop 
    ;
    // 004f8601  90                     -nop 
    ;
    // 004f8602  90                     -nop 
    ;
    // 004f8603  90                     -nop 
    ;
    // 004f8604  90                     -nop 
    ;
    // 004f8605  90                     -nop 
    ;
    // 004f8606  90                     -nop 
    ;
    // 004f8607  90                     -nop 
    ;
    // 004f8608  90                     -nop 
    ;
    // 004f8609  90                     -nop 
    ;
    // 004f860a  90                     -nop 
    ;
    // 004f860b  90                     -nop 
    ;
    // 004f860c  90                     -nop 
    ;
    // 004f860d  90                     -nop 
    ;
    // 004f860e  90                     -nop 
    ;
    // 004f860f  90                     -nop 
    ;
    // 004f8610  90                     -nop 
    ;
    // 004f8611  90                     -nop 
    ;
    // 004f8612  90                     -nop 
    ;
    // 004f8613  90                     -nop 
    ;
    // 004f8614  90                     -nop 
    ;
    // 004f8615  90                     -nop 
    ;
    // 004f8616  90                     -nop 
    ;
    // 004f8617  90                     -nop 
    ;
    // 004f8618  90                     -nop 
    ;
    // 004f8619  90                     -nop 
    ;
    // 004f861a  90                     -nop 
    ;
    // 004f861b  90                     -nop 
    ;
    // 004f861c  90                     -nop 
    ;
    // 004f861d  90                     -nop 
    ;
    // 004f861e  90                     -nop 
    ;
    // 004f861f  90                     -nop 
    ;
    // 004f8620  90                     -nop 
    ;
    // 004f8621  90                     -nop 
    ;
    // 004f8622  90                     -nop 
    ;
    // 004f8623  90                     -nop 
    ;
    // 004f8624  90                     -nop 
    ;
    // 004f8625  90                     -nop 
    ;
    // 004f8626  90                     -nop 
    ;
    // 004f8627  90                     -nop 
    ;
    // 004f8628  90                     -nop 
    ;
    // 004f8629  90                     -nop 
    ;
    // 004f862a  90                     -nop 
    ;
    // 004f862b  90                     -nop 
    ;
    // 004f862c  90                     -nop 
    ;
    // 004f862d  90                     -nop 
    ;
    // 004f862e  90                     -nop 
    ;
    // 004f862f  90                     -nop 
    ;
    // 004f8630  90                     -nop 
    ;
    // 004f8631  90                     -nop 
    ;
    // 004f8632  90                     -nop 
    ;
    // 004f8633  90                     -nop 
    ;
    // 004f8634  90                     -nop 
    ;
    // 004f8635  90                     -nop 
    ;
    // 004f8636  90                     -nop 
    ;
    // 004f8637  90                     -nop 
    ;
    // 004f8638  90                     -nop 
    ;
    // 004f8639  90                     -nop 
    ;
    // 004f863a  90                     -nop 
    ;
    // 004f863b  90                     -nop 
    ;
    // 004f863c  90                     -nop 
    ;
    // 004f863d  90                     -nop 
    ;
    // 004f863e  90                     -nop 
    ;
    // 004f863f  90                     -nop 
    ;
    // 004f8640  90                     -nop 
    ;
    // 004f8641  90                     -nop 
    ;
    // 004f8642  90                     -nop 
    ;
    // 004f8643  90                     -nop 
    ;
    // 004f8644  90                     -nop 
    ;
    // 004f8645  90                     -nop 
    ;
    // 004f8646  90                     -nop 
    ;
    // 004f8647  90                     -nop 
    ;
    // 004f8648  90                     -nop 
    ;
    // 004f8649  90                     -nop 
    ;
    // 004f864a  90                     -nop 
    ;
    // 004f864b  90                     -nop 
    ;
    // 004f864c  90                     -nop 
    ;
    // 004f864d  90                     -nop 
    ;
    // 004f864e  90                     -nop 
    ;
    // 004f864f  90                     -nop 
    ;
    // 004f8650  90                     -nop 
    ;
    // 004f8651  90                     -nop 
    ;
    // 004f8652  90                     -nop 
    ;
    // 004f8653  90                     -nop 
    ;
    // 004f8654  90                     -nop 
    ;
    // 004f8655  90                     -nop 
    ;
    // 004f8656  90                     -nop 
    ;
    // 004f8657  90                     -nop 
    ;
    // 004f8658  90                     -nop 
    ;
    // 004f8659  90                     -nop 
    ;
    // 004f865a  90                     -nop 
    ;
    // 004f865b  90                     -nop 
    ;
    // 004f865c  90                     -nop 
    ;
    // 004f865d  90                     -nop 
    ;
    // 004f865e  90                     -nop 
    ;
    // 004f865f  90                     -nop 
    ;
    // 004f8660  90                     -nop 
    ;
    // 004f8661  90                     -nop 
    ;
    // 004f8662  90                     -nop 
    ;
    // 004f8663  90                     -nop 
    ;
    // 004f8664  90                     -nop 
    ;
    // 004f8665  90                     -nop 
    ;
    // 004f8666  90                     -nop 
    ;
    // 004f8667  90                     -nop 
    ;
    // 004f8668  90                     -nop 
    ;
    // 004f8669  90                     -nop 
    ;
    // 004f866a  90                     -nop 
    ;
    // 004f866b  90                     -nop 
    ;
    // 004f866c  90                     -nop 
    ;
    // 004f866d  90                     -nop 
    ;
    // 004f866e  90                     -nop 
    ;
    // 004f866f  90                     -nop 
    ;
    // 004f8670  90                     -nop 
    ;
    // 004f8671  90                     -nop 
    ;
    // 004f8672  90                     -nop 
    ;
    // 004f8673  90                     -nop 
    ;
    // 004f8674  90                     -nop 
    ;
    // 004f8675  90                     -nop 
    ;
    // 004f8676  90                     -nop 
    ;
    // 004f8677  90                     -nop 
    ;
    // 004f8678  90                     -nop 
    ;
    // 004f8679  90                     -nop 
    ;
    // 004f867a  90                     -nop 
    ;
    // 004f867b  90                     -nop 
    ;
    // 004f867c  90                     -nop 
    ;
    // 004f867d  90                     -nop 
    ;
    // 004f867e  90                     -nop 
    ;
    // 004f867f  90                     -nop 
    ;
    // 004f8680  90                     -nop 
    ;
    // 004f8681  90                     -nop 
    ;
    // 004f8682  90                     -nop 
    ;
    // 004f8683  90                     -nop 
    ;
    // 004f8684  90                     -nop 
    ;
    // 004f8685  90                     -nop 
    ;
    // 004f8686  90                     -nop 
    ;
    // 004f8687  90                     -nop 
    ;
    // 004f8688  90                     -nop 
    ;
    // 004f8689  90                     -nop 
    ;
    // 004f868a  90                     -nop 
    ;
    // 004f868b  90                     -nop 
    ;
    // 004f868c  90                     -nop 
    ;
    // 004f868d  90                     -nop 
    ;
    // 004f868e  90                     -nop 
    ;
    // 004f868f  90                     -nop 
    ;
    // 004f8690  90                     -nop 
    ;
    // 004f8691  90                     -nop 
    ;
    // 004f8692  90                     -nop 
    ;
    // 004f8693  90                     -nop 
    ;
    // 004f8694  90                     -nop 
    ;
    // 004f8695  90                     -nop 
    ;
    // 004f8696  90                     -nop 
    ;
    // 004f8697  90                     -nop 
    ;
    // 004f8698  90                     -nop 
    ;
    // 004f8699  90                     -nop 
    ;
    // 004f869a  90                     -nop 
    ;
    // 004f869b  90                     -nop 
    ;
    // 004f869c  90                     -nop 
    ;
    // 004f869d  90                     -nop 
    ;
    // 004f869e  90                     -nop 
    ;
    // 004f869f  90                     -nop 
    ;
    // 004f86a0  90                     -nop 
    ;
    // 004f86a1  90                     -nop 
    ;
    // 004f86a2  90                     -nop 
    ;
    // 004f86a3  90                     -nop 
    ;
    // 004f86a4  90                     -nop 
    ;
    // 004f86a5  90                     -nop 
    ;
    // 004f86a6  90                     -nop 
    ;
    // 004f86a7  90                     -nop 
    ;
    // 004f86a8  90                     -nop 
    ;
    // 004f86a9  90                     -nop 
    ;
    // 004f86aa  90                     -nop 
    ;
    // 004f86ab  90                     -nop 
    ;
    // 004f86ac  90                     -nop 
    ;
    // 004f86ad  90                     -nop 
    ;
    // 004f86ae  90                     -nop 
    ;
    // 004f86af  90                     -nop 
    ;
    // 004f86b0  90                     -nop 
    ;
    // 004f86b1  90                     -nop 
    ;
    // 004f86b2  90                     -nop 
    ;
    // 004f86b3  90                     -nop 
    ;
    // 004f86b4  90                     -nop 
    ;
    // 004f86b5  90                     -nop 
    ;
    // 004f86b6  90                     -nop 
    ;
    // 004f86b7  90                     -nop 
    ;
    // 004f86b8  90                     -nop 
    ;
    // 004f86b9  90                     -nop 
    ;
    // 004f86ba  90                     -nop 
    ;
    // 004f86bb  90                     -nop 
    ;
    // 004f86bc  90                     -nop 
    ;
    // 004f86bd  90                     -nop 
    ;
    // 004f86be  90                     -nop 
    ;
    // 004f86bf  90                     -nop 
    ;
    // 004f86c0  90                     -nop 
    ;
    // 004f86c1  90                     -nop 
    ;
    // 004f86c2  90                     -nop 
    ;
    // 004f86c3  90                     -nop 
    ;
    // 004f86c4  90                     -nop 
    ;
    // 004f86c5  90                     -nop 
    ;
    // 004f86c6  90                     -nop 
    ;
    // 004f86c7  90                     -nop 
    ;
    // 004f86c8  90                     -nop 
    ;
    // 004f86c9  90                     -nop 
    ;
    // 004f86ca  90                     -nop 
    ;
    // 004f86cb  90                     -nop 
    ;
    // 004f86cc  90                     -nop 
    ;
    // 004f86cd  90                     -nop 
    ;
    // 004f86ce  90                     -nop 
    ;
    // 004f86cf  90                     -nop 
    ;
    // 004f86d0  90                     -nop 
    ;
    // 004f86d1  90                     -nop 
    ;
    // 004f86d2  90                     -nop 
    ;
    // 004f86d3  90                     -nop 
    ;
    // 004f86d4  90                     -nop 
    ;
    // 004f86d5  90                     -nop 
    ;
    // 004f86d6  90                     -nop 
    ;
    // 004f86d7  90                     -nop 
    ;
    // 004f86d8  90                     -nop 
    ;
    // 004f86d9  90                     -nop 
    ;
    // 004f86da  90                     -nop 
    ;
    // 004f86db  90                     -nop 
    ;
    // 004f86dc  90                     -nop 
    ;
    // 004f86dd  90                     -nop 
    ;
    // 004f86de  90                     -nop 
    ;
    // 004f86df  90                     -nop 
    ;
    // 004f86e0  90                     -nop 
    ;
    // 004f86e1  90                     -nop 
    ;
    // 004f86e2  90                     -nop 
    ;
    // 004f86e3  90                     -nop 
    ;
    // 004f86e4  90                     -nop 
    ;
    // 004f86e5  90                     -nop 
    ;
    // 004f86e6  90                     -nop 
    ;
    // 004f86e7  90                     -nop 
    ;
    // 004f86e8  90                     -nop 
    ;
    // 004f86e9  90                     -nop 
    ;
    // 004f86ea  90                     -nop 
    ;
    // 004f86eb  90                     -nop 
    ;
    // 004f86ec  90                     -nop 
    ;
    // 004f86ed  90                     -nop 
    ;
    // 004f86ee  90                     -nop 
    ;
    // 004f86ef  90                     -nop 
    ;
    // 004f86f0  90                     -nop 
    ;
    // 004f86f1  90                     -nop 
    ;
    // 004f86f2  90                     -nop 
    ;
    // 004f86f3  90                     -nop 
    ;
    // 004f86f4  90                     -nop 
    ;
    // 004f86f5  90                     -nop 
    ;
    // 004f86f6  90                     -nop 
    ;
    // 004f86f7  90                     -nop 
    ;
    // 004f86f8  90                     -nop 
    ;
    // 004f86f9  90                     -nop 
    ;
    // 004f86fa  90                     -nop 
    ;
    // 004f86fb  90                     -nop 
    ;
    // 004f86fc  90                     -nop 
    ;
    // 004f86fd  90                     -nop 
    ;
    // 004f86fe  90                     -nop 
    ;
    // 004f86ff  90                     -nop 
    ;
    // 004f8700  90                     -nop 
    ;
    // 004f8701  90                     -nop 
    ;
    // 004f8702  90                     -nop 
    ;
    // 004f8703  90                     -nop 
    ;
    // 004f8704  90                     -nop 
    ;
    // 004f8705  90                     -nop 
    ;
    // 004f8706  90                     -nop 
    ;
    // 004f8707  90                     -nop 
    ;
    // 004f8708  90                     -nop 
    ;
    // 004f8709  90                     -nop 
    ;
    // 004f870a  90                     -nop 
    ;
    // 004f870b  90                     -nop 
    ;
    // 004f870c  90                     -nop 
    ;
    // 004f870d  90                     -nop 
    ;
    // 004f870e  90                     -nop 
    ;
    // 004f870f  90                     -nop 
    ;
    // 004f8710  90                     -nop 
    ;
    // 004f8711  90                     -nop 
    ;
    // 004f8712  90                     -nop 
    ;
    // 004f8713  90                     -nop 
    ;
    // 004f8714  90                     -nop 
    ;
    // 004f8715  90                     -nop 
    ;
    // 004f8716  90                     -nop 
    ;
    // 004f8717  90                     -nop 
    ;
    // 004f8718  90                     -nop 
    ;
    // 004f8719  90                     -nop 
    ;
    // 004f871a  90                     -nop 
    ;
    // 004f871b  90                     -nop 
    ;
    // 004f871c  90                     -nop 
    ;
    // 004f871d  90                     -nop 
    ;
    // 004f871e  90                     -nop 
    ;
    // 004f871f  90                     -nop 
    ;
    // 004f8720  90                     -nop 
    ;
    // 004f8721  90                     -nop 
    ;
    // 004f8722  90                     -nop 
    ;
    // 004f8723  90                     -nop 
    ;
    // 004f8724  90                     -nop 
    ;
    // 004f8725  90                     -nop 
    ;
    // 004f8726  90                     -nop 
    ;
    // 004f8727  90                     -nop 
    ;
    // 004f8728  90                     -nop 
    ;
    // 004f8729  90                     -nop 
    ;
    // 004f872a  90                     -nop 
    ;
    // 004f872b  90                     -nop 
    ;
    // 004f872c  90                     -nop 
    ;
    // 004f872d  90                     -nop 
    ;
    // 004f872e  90                     -nop 
    ;
    // 004f872f  90                     -nop 
    ;
    // 004f8730  90                     -nop 
    ;
    // 004f8731  90                     -nop 
    ;
    // 004f8732  90                     -nop 
    ;
    // 004f8733  90                     -nop 
    ;
    // 004f8734  90                     -nop 
    ;
    // 004f8735  90                     -nop 
    ;
    // 004f8736  90                     -nop 
    ;
    // 004f8737  90                     -nop 
    ;
    // 004f8738  90                     -nop 
    ;
    // 004f8739  90                     -nop 
    ;
    // 004f873a  90                     -nop 
    ;
    // 004f873b  90                     -nop 
    ;
    // 004f873c  90                     -nop 
    ;
    // 004f873d  90                     -nop 
    ;
    // 004f873e  90                     -nop 
    ;
    // 004f873f  90                     -nop 
    ;
    // 004f8740  90                     -nop 
    ;
    // 004f8741  90                     -nop 
    ;
    // 004f8742  90                     -nop 
    ;
    // 004f8743  90                     -nop 
    ;
    // 004f8744  90                     -nop 
    ;
    // 004f8745  90                     -nop 
    ;
    // 004f8746  90                     -nop 
    ;
    // 004f8747  90                     -nop 
    ;
    // 004f8748  90                     -nop 
    ;
    // 004f8749  90                     -nop 
    ;
    // 004f874a  90                     -nop 
    ;
    // 004f874b  90                     -nop 
    ;
    // 004f874c  90                     -nop 
    ;
    // 004f874d  90                     -nop 
    ;
    // 004f874e  90                     -nop 
    ;
    // 004f874f  90                     -nop 
    ;
    // 004f8750  90                     -nop 
    ;
    // 004f8751  90                     -nop 
    ;
    // 004f8752  90                     -nop 
    ;
    // 004f8753  90                     -nop 
    ;
    // 004f8754  90                     -nop 
    ;
    // 004f8755  90                     -nop 
    ;
    // 004f8756  90                     -nop 
    ;
    // 004f8757  90                     -nop 
    ;
    // 004f8758  90                     -nop 
    ;
    // 004f8759  90                     -nop 
    ;
    // 004f875a  90                     -nop 
    ;
    // 004f875b  90                     -nop 
    ;
    // 004f875c  90                     -nop 
    ;
    // 004f875d  90                     -nop 
    ;
    // 004f875e  90                     -nop 
    ;
    // 004f875f  90                     -nop 
    ;
    // 004f8760  90                     -nop 
    ;
    // 004f8761  90                     -nop 
    ;
    // 004f8762  90                     -nop 
    ;
    // 004f8763  90                     -nop 
    ;
    // 004f8764  90                     -nop 
    ;
    // 004f8765  90                     -nop 
    ;
    // 004f8766  90                     -nop 
    ;
    // 004f8767  90                     -nop 
    ;
    // 004f8768  90                     -nop 
    ;
    // 004f8769  90                     -nop 
    ;
    // 004f876a  90                     -nop 
    ;
    // 004f876b  90                     -nop 
    ;
    // 004f876c  90                     -nop 
    ;
    // 004f876d  90                     -nop 
    ;
    // 004f876e  90                     -nop 
    ;
    // 004f876f  90                     -nop 
    ;
    // 004f8770  90                     -nop 
    ;
    // 004f8771  90                     -nop 
    ;
    // 004f8772  90                     -nop 
    ;
    // 004f8773  90                     -nop 
    ;
    // 004f8774  90                     -nop 
    ;
    // 004f8775  90                     -nop 
    ;
    // 004f8776  90                     -nop 
    ;
    // 004f8777  90                     -nop 
    ;
    // 004f8778  90                     -nop 
    ;
    // 004f8779  90                     -nop 
    ;
    // 004f877a  90                     -nop 
    ;
    // 004f877b  90                     -nop 
    ;
    // 004f877c  90                     -nop 
    ;
    // 004f877d  90                     -nop 
    ;
    // 004f877e  90                     -nop 
    ;
    // 004f877f  90                     -nop 
    ;
    // 004f8780  90                     -nop 
    ;
    // 004f8781  90                     -nop 
    ;
    // 004f8782  90                     -nop 
    ;
    // 004f8783  90                     -nop 
    ;
    // 004f8784  90                     -nop 
    ;
    // 004f8785  90                     -nop 
    ;
    // 004f8786  90                     -nop 
    ;
    // 004f8787  90                     -nop 
    ;
    // 004f8788  90                     -nop 
    ;
    // 004f8789  90                     -nop 
    ;
    // 004f878a  90                     -nop 
    ;
    // 004f878b  90                     -nop 
    ;
    // 004f878c  90                     -nop 
    ;
    // 004f878d  90                     -nop 
    ;
    // 004f878e  90                     -nop 
    ;
    // 004f878f  90                     -nop 
    ;
    // 004f8790  90                     -nop 
    ;
    // 004f8791  90                     -nop 
    ;
    // 004f8792  90                     -nop 
    ;
    // 004f8793  90                     -nop 
    ;
    // 004f8794  90                     -nop 
    ;
    // 004f8795  90                     -nop 
    ;
    // 004f8796  90                     -nop 
    ;
    // 004f8797  90                     -nop 
    ;
    // 004f8798  90                     -nop 
    ;
    // 004f8799  90                     -nop 
    ;
    // 004f879a  90                     -nop 
    ;
    // 004f879b  90                     -nop 
    ;
    // 004f879c  90                     -nop 
    ;
    // 004f879d  90                     -nop 
    ;
    // 004f879e  90                     -nop 
    ;
    // 004f879f  90                     -nop 
    ;
    // 004f87a0  90                     -nop 
    ;
    // 004f87a1  90                     -nop 
    ;
    // 004f87a2  90                     -nop 
    ;
    // 004f87a3  90                     -nop 
    ;
    // 004f87a4  90                     -nop 
    ;
    // 004f87a5  90                     -nop 
    ;
    // 004f87a6  90                     -nop 
    ;
    // 004f87a7  90                     -nop 
    ;
    // 004f87a8  90                     -nop 
    ;
    // 004f87a9  90                     -nop 
    ;
    // 004f87aa  90                     -nop 
    ;
    // 004f87ab  90                     -nop 
    ;
    // 004f87ac  90                     -nop 
    ;
    // 004f87ad  90                     -nop 
    ;
    // 004f87ae  90                     -nop 
    ;
    // 004f87af  90                     -nop 
    ;
    // 004f87b0  90                     -nop 
    ;
    // 004f87b1  90                     -nop 
    ;
    // 004f87b2  90                     -nop 
    ;
    // 004f87b3  90                     -nop 
    ;
    // 004f87b4  90                     -nop 
    ;
    // 004f87b5  90                     -nop 
    ;
    // 004f87b6  90                     -nop 
    ;
    // 004f87b7  90                     -nop 
    ;
    // 004f87b8  90                     -nop 
    ;
    // 004f87b9  90                     -nop 
    ;
    // 004f87ba  90                     -nop 
    ;
    // 004f87bb  90                     -nop 
    ;
    // 004f87bc  90                     -nop 
    ;
    // 004f87bd  90                     -nop 
    ;
    // 004f87be  90                     -nop 
    ;
    // 004f87bf  90                     -nop 
    ;
    // 004f87c0  90                     -nop 
    ;
    // 004f87c1  90                     -nop 
    ;
    // 004f87c2  90                     -nop 
    ;
    // 004f87c3  90                     -nop 
    ;
    // 004f87c4  90                     -nop 
    ;
    // 004f87c5  90                     -nop 
    ;
    // 004f87c6  90                     -nop 
    ;
    // 004f87c7  90                     -nop 
    ;
    // 004f87c8  90                     -nop 
    ;
    // 004f87c9  90                     -nop 
    ;
    // 004f87ca  90                     -nop 
    ;
    // 004f87cb  90                     -nop 
    ;
    // 004f87cc  90                     -nop 
    ;
    // 004f87cd  90                     -nop 
    ;
    // 004f87ce  90                     -nop 
    ;
    // 004f87cf  90                     -nop 
    ;
    // 004f87d0  90                     -nop 
    ;
    // 004f87d1  90                     -nop 
    ;
    // 004f87d2  90                     -nop 
    ;
    // 004f87d3  90                     -nop 
    ;
    // 004f87d4  90                     -nop 
    ;
    // 004f87d5  90                     -nop 
    ;
    // 004f87d6  90                     -nop 
    ;
    // 004f87d7  90                     -nop 
    ;
    // 004f87d8  90                     -nop 
    ;
    // 004f87d9  90                     -nop 
    ;
    // 004f87da  90                     -nop 
    ;
    // 004f87db  90                     -nop 
    ;
    // 004f87dc  90                     -nop 
    ;
    // 004f87dd  90                     -nop 
    ;
    // 004f87de  90                     -nop 
    ;
    // 004f87df  90                     -nop 
    ;
    // 004f87e0  90                     -nop 
    ;
    // 004f87e1  90                     -nop 
    ;
    // 004f87e2  90                     -nop 
    ;
    // 004f87e3  90                     -nop 
    ;
    // 004f87e4  90                     -nop 
    ;
    // 004f87e5  90                     -nop 
    ;
    // 004f87e6  90                     -nop 
    ;
    // 004f87e7  90                     -nop 
    ;
    // 004f87e8  90                     -nop 
    ;
    // 004f87e9  90                     -nop 
    ;
    // 004f87ea  90                     -nop 
    ;
    // 004f87eb  90                     -nop 
    ;
    // 004f87ec  90                     -nop 
    ;
    // 004f87ed  90                     -nop 
    ;
    // 004f87ee  90                     -nop 
    ;
    // 004f87ef  90                     -nop 
    ;
    // 004f87f0  90                     -nop 
    ;
    // 004f87f1  90                     -nop 
    ;
    // 004f87f2  90                     -nop 
    ;
    // 004f87f3  90                     -nop 
    ;
    // 004f87f4  90                     -nop 
    ;
    // 004f87f5  90                     -nop 
    ;
    // 004f87f6  90                     -nop 
    ;
    // 004f87f7  90                     -nop 
    ;
    // 004f87f8  90                     -nop 
    ;
    // 004f87f9  90                     -nop 
    ;
    // 004f87fa  90                     -nop 
    ;
    // 004f87fb  90                     -nop 
    ;
    // 004f87fc  90                     -nop 
    ;
    // 004f87fd  90                     -nop 
    ;
    // 004f87fe  90                     -nop 
    ;
    // 004f87ff  90                     -nop 
    ;
    // 004f8800  90                     -nop 
    ;
    // 004f8801  90                     -nop 
    ;
    // 004f8802  90                     -nop 
    ;
    // 004f8803  90                     -nop 
    ;
    // 004f8804  90                     -nop 
    ;
    // 004f8805  90                     -nop 
    ;
    // 004f8806  90                     -nop 
    ;
    // 004f8807  90                     -nop 
    ;
    // 004f8808  90                     -nop 
    ;
    // 004f8809  90                     -nop 
    ;
    // 004f880a  90                     -nop 
    ;
    // 004f880b  90                     -nop 
    ;
    // 004f880c  90                     -nop 
    ;
    // 004f880d  90                     -nop 
    ;
    // 004f880e  90                     -nop 
    ;
    // 004f880f  90                     -nop 
    ;
    // 004f8810  90                     -nop 
    ;
    // 004f8811  90                     -nop 
    ;
    // 004f8812  90                     -nop 
    ;
    // 004f8813  90                     -nop 
    ;
    // 004f8814  90                     -nop 
    ;
    // 004f8815  90                     -nop 
    ;
    // 004f8816  90                     -nop 
    ;
    // 004f8817  90                     -nop 
    ;
    // 004f8818  90                     -nop 
    ;
    // 004f8819  90                     -nop 
    ;
    // 004f881a  90                     -nop 
    ;
    // 004f881b  90                     -nop 
    ;
    // 004f881c  90                     -nop 
    ;
    // 004f881d  90                     -nop 
    ;
    // 004f881e  90                     -nop 
    ;
    // 004f881f  90                     -nop 
    ;
    // 004f8820  90                     -nop 
    ;
    // 004f8821  90                     -nop 
    ;
    // 004f8822  90                     -nop 
    ;
    // 004f8823  90                     -nop 
    ;
    // 004f8824  90                     -nop 
    ;
    // 004f8825  90                     -nop 
    ;
    // 004f8826  90                     -nop 
    ;
    // 004f8827  90                     -nop 
    ;
    // 004f8828  90                     -nop 
    ;
    // 004f8829  90                     -nop 
    ;
    // 004f882a  90                     -nop 
    ;
    // 004f882b  90                     -nop 
    ;
    // 004f882c  90                     -nop 
    ;
    // 004f882d  90                     -nop 
    ;
    // 004f882e  90                     -nop 
    ;
    // 004f882f  90                     -nop 
    ;
    // 004f8830  90                     -nop 
    ;
    // 004f8831  90                     -nop 
    ;
    // 004f8832  90                     -nop 
    ;
    // 004f8833  90                     -nop 
    ;
    // 004f8834  90                     -nop 
    ;
    // 004f8835  90                     -nop 
    ;
    // 004f8836  90                     -nop 
    ;
    // 004f8837  90                     -nop 
    ;
    // 004f8838  90                     -nop 
    ;
    // 004f8839  90                     -nop 
    ;
    // 004f883a  90                     -nop 
    ;
    // 004f883b  90                     -nop 
    ;
    // 004f883c  90                     -nop 
    ;
    // 004f883d  90                     -nop 
    ;
    // 004f883e  90                     -nop 
    ;
    // 004f883f  90                     -nop 
    ;
    // 004f8840  90                     -nop 
    ;
    // 004f8841  90                     -nop 
    ;
    // 004f8842  90                     -nop 
    ;
    // 004f8843  90                     -nop 
    ;
    // 004f8844  90                     -nop 
    ;
    // 004f8845  90                     -nop 
    ;
    // 004f8846  90                     -nop 
    ;
    // 004f8847  90                     -nop 
    ;
    // 004f8848  90                     -nop 
    ;
    // 004f8849  90                     -nop 
    ;
    // 004f884a  90                     -nop 
    ;
    // 004f884b  90                     -nop 
    ;
    // 004f884c  90                     -nop 
    ;
    // 004f884d  90                     -nop 
    ;
    // 004f884e  90                     -nop 
    ;
    // 004f884f  90                     -nop 
    ;
    // 004f8850  90                     -nop 
    ;
    // 004f8851  90                     -nop 
    ;
    // 004f8852  90                     -nop 
    ;
    // 004f8853  90                     -nop 
    ;
    // 004f8854  90                     -nop 
    ;
    // 004f8855  90                     -nop 
    ;
    // 004f8856  90                     -nop 
    ;
    // 004f8857  90                     -nop 
    ;
    // 004f8858  90                     -nop 
    ;
    // 004f8859  90                     -nop 
    ;
    // 004f885a  90                     -nop 
    ;
    // 004f885b  90                     -nop 
    ;
    // 004f885c  90                     -nop 
    ;
    // 004f885d  90                     -nop 
    ;
    // 004f885e  90                     -nop 
    ;
    // 004f885f  90                     -nop 
    ;
    // 004f8860  90                     -nop 
    ;
    // 004f8861  90                     -nop 
    ;
    // 004f8862  90                     -nop 
    ;
    // 004f8863  90                     -nop 
    ;
    // 004f8864  90                     -nop 
    ;
    // 004f8865  90                     -nop 
    ;
    // 004f8866  90                     -nop 
    ;
    // 004f8867  90                     -nop 
    ;
    // 004f8868  90                     -nop 
    ;
    // 004f8869  90                     -nop 
    ;
    // 004f886a  90                     -nop 
    ;
    // 004f886b  90                     -nop 
    ;
    // 004f886c  90                     -nop 
    ;
    // 004f886d  90                     -nop 
    ;
    // 004f886e  90                     -nop 
    ;
    // 004f886f  90                     -nop 
    ;
    // 004f8870  90                     -nop 
    ;
    // 004f8871  90                     -nop 
    ;
    // 004f8872  90                     -nop 
    ;
    // 004f8873  90                     -nop 
    ;
    // 004f8874  90                     -nop 
    ;
    // 004f8875  90                     -nop 
    ;
    // 004f8876  90                     -nop 
    ;
    // 004f8877  90                     -nop 
    ;
    // 004f8878  90                     -nop 
    ;
    // 004f8879  90                     -nop 
    ;
    // 004f887a  90                     -nop 
    ;
    // 004f887b  90                     -nop 
    ;
    // 004f887c  90                     -nop 
    ;
    // 004f887d  90                     -nop 
    ;
    // 004f887e  90                     -nop 
    ;
    // 004f887f  90                     -nop 
    ;
    // 004f8880  90                     -nop 
    ;
    // 004f8881  90                     -nop 
    ;
    // 004f8882  90                     -nop 
    ;
    // 004f8883  90                     -nop 
    ;
    // 004f8884  90                     -nop 
    ;
    // 004f8885  90                     -nop 
    ;
    // 004f8886  90                     -nop 
    ;
    // 004f8887  90                     -nop 
    ;
    // 004f8888  90                     -nop 
    ;
    // 004f8889  90                     -nop 
    ;
    // 004f888a  90                     -nop 
    ;
    // 004f888b  90                     -nop 
    ;
    // 004f888c  90                     -nop 
    ;
    // 004f888d  90                     -nop 
    ;
    // 004f888e  90                     -nop 
    ;
    // 004f888f  90                     -nop 
    ;
    // 004f8890  90                     -nop 
    ;
    // 004f8891  90                     -nop 
    ;
    // 004f8892  90                     -nop 
    ;
    // 004f8893  90                     -nop 
    ;
    // 004f8894  90                     -nop 
    ;
    // 004f8895  90                     -nop 
    ;
    // 004f8896  90                     -nop 
    ;
    // 004f8897  90                     -nop 
    ;
    // 004f8898  90                     -nop 
    ;
    // 004f8899  90                     -nop 
    ;
    // 004f889a  90                     -nop 
    ;
    // 004f889b  90                     -nop 
    ;
    // 004f889c  90                     -nop 
    ;
    // 004f889d  90                     -nop 
    ;
    // 004f889e  90                     -nop 
    ;
    // 004f889f  90                     -nop 
    ;
    // 004f88a0  90                     -nop 
    ;
    // 004f88a1  90                     -nop 
    ;
    // 004f88a2  90                     -nop 
    ;
    // 004f88a3  90                     -nop 
    ;
    // 004f88a4  90                     -nop 
    ;
    // 004f88a5  90                     -nop 
    ;
    // 004f88a6  90                     -nop 
    ;
    // 004f88a7  90                     -nop 
    ;
    // 004f88a8  90                     -nop 
    ;
    // 004f88a9  90                     -nop 
    ;
    // 004f88aa  90                     -nop 
    ;
    // 004f88ab  90                     -nop 
    ;
    // 004f88ac  90                     -nop 
    ;
    // 004f88ad  90                     -nop 
    ;
    // 004f88ae  90                     -nop 
    ;
    // 004f88af  90                     -nop 
    ;
    // 004f88b0  90                     -nop 
    ;
    // 004f88b1  90                     -nop 
    ;
    // 004f88b2  90                     -nop 
    ;
    // 004f88b3  90                     -nop 
    ;
    // 004f88b4  90                     -nop 
    ;
    // 004f88b5  90                     -nop 
    ;
    // 004f88b6  90                     -nop 
    ;
    // 004f88b7  90                     -nop 
    ;
    // 004f88b8  90                     -nop 
    ;
    // 004f88b9  90                     -nop 
    ;
    // 004f88ba  90                     -nop 
    ;
    // 004f88bb  90                     -nop 
    ;
    // 004f88bc  90                     -nop 
    ;
    // 004f88bd  90                     -nop 
    ;
    // 004f88be  90                     -nop 
    ;
    // 004f88bf  90                     -nop 
    ;
    // 004f88c0  90                     -nop 
    ;
    // 004f88c1  90                     -nop 
    ;
    // 004f88c2  90                     -nop 
    ;
    // 004f88c3  90                     -nop 
    ;
    // 004f88c4  90                     -nop 
    ;
    // 004f88c5  90                     -nop 
    ;
    // 004f88c6  90                     -nop 
    ;
    // 004f88c7  90                     -nop 
    ;
    // 004f88c8  90                     -nop 
    ;
    // 004f88c9  90                     -nop 
    ;
    // 004f88ca  90                     -nop 
    ;
    // 004f88cb  90                     -nop 
    ;
    // 004f88cc  90                     -nop 
    ;
    // 004f88cd  90                     -nop 
    ;
    // 004f88ce  90                     -nop 
    ;
    // 004f88cf  90                     -nop 
    ;
    // 004f88d0  90                     -nop 
    ;
    // 004f88d1  90                     -nop 
    ;
    // 004f88d2  90                     -nop 
    ;
    // 004f88d3  90                     -nop 
    ;
    // 004f88d4  90                     -nop 
    ;
    // 004f88d5  90                     -nop 
    ;
    // 004f88d6  90                     -nop 
    ;
    // 004f88d7  90                     -nop 
    ;
    // 004f88d8  90                     -nop 
    ;
    // 004f88d9  90                     -nop 
    ;
    // 004f88da  90                     -nop 
    ;
    // 004f88db  90                     -nop 
    ;
    // 004f88dc  90                     -nop 
    ;
    // 004f88dd  90                     -nop 
    ;
    // 004f88de  90                     -nop 
    ;
    // 004f88df  90                     -nop 
    ;
    // 004f88e0  90                     -nop 
    ;
    // 004f88e1  90                     -nop 
    ;
    // 004f88e2  90                     -nop 
    ;
    // 004f88e3  90                     -nop 
    ;
    // 004f88e4  90                     -nop 
    ;
    // 004f88e5  90                     -nop 
    ;
    // 004f88e6  90                     -nop 
    ;
    // 004f88e7  90                     -nop 
    ;
    // 004f88e8  90                     -nop 
    ;
    // 004f88e9  90                     -nop 
    ;
    // 004f88ea  90                     -nop 
    ;
    // 004f88eb  90                     -nop 
    ;
    // 004f88ec  90                     -nop 
    ;
    // 004f88ed  90                     -nop 
    ;
    // 004f88ee  90                     -nop 
    ;
    // 004f88ef  90                     -nop 
    ;
    // 004f88f0  90                     -nop 
    ;
    // 004f88f1  90                     -nop 
    ;
    // 004f88f2  90                     -nop 
    ;
    // 004f88f3  90                     -nop 
    ;
    // 004f88f4  90                     -nop 
    ;
    // 004f88f5  90                     -nop 
    ;
    // 004f88f6  90                     -nop 
    ;
    // 004f88f7  90                     -nop 
    ;
    // 004f88f8  90                     -nop 
    ;
    // 004f88f9  90                     -nop 
    ;
    // 004f88fa  90                     -nop 
    ;
    // 004f88fb  90                     -nop 
    ;
    // 004f88fc  90                     -nop 
    ;
    // 004f88fd  90                     -nop 
    ;
    // 004f88fe  90                     -nop 
    ;
    // 004f88ff  90                     -nop 
    ;
    // 004f8900  90                     -nop 
    ;
    // 004f8901  90                     -nop 
    ;
    // 004f8902  90                     -nop 
    ;
    // 004f8903  90                     -nop 
    ;
    // 004f8904  90                     -nop 
    ;
    // 004f8905  90                     -nop 
    ;
    // 004f8906  90                     -nop 
    ;
    // 004f8907  90                     -nop 
    ;
    // 004f8908  90                     -nop 
    ;
    // 004f8909  90                     -nop 
    ;
    // 004f890a  90                     -nop 
    ;
    // 004f890b  90                     -nop 
    ;
    // 004f890c  90                     -nop 
    ;
    // 004f890d  90                     -nop 
    ;
    // 004f890e  90                     -nop 
    ;
    // 004f890f  90                     -nop 
    ;
    // 004f8910  90                     -nop 
    ;
    // 004f8911  90                     -nop 
    ;
    // 004f8912  90                     -nop 
    ;
    // 004f8913  90                     -nop 
    ;
    // 004f8914  90                     -nop 
    ;
    // 004f8915  90                     -nop 
    ;
    // 004f8916  90                     -nop 
    ;
    // 004f8917  90                     -nop 
    ;
    // 004f8918  90                     -nop 
    ;
    // 004f8919  90                     -nop 
    ;
    // 004f891a  90                     -nop 
    ;
    // 004f891b  90                     -nop 
    ;
    // 004f891c  90                     -nop 
    ;
    // 004f891d  90                     -nop 
    ;
    // 004f891e  90                     -nop 
    ;
    // 004f891f  90                     -nop 
    ;
    // 004f8920  90                     -nop 
    ;
    // 004f8921  90                     -nop 
    ;
    // 004f8922  90                     -nop 
    ;
    // 004f8923  90                     -nop 
    ;
    // 004f8924  90                     -nop 
    ;
    // 004f8925  90                     -nop 
    ;
    // 004f8926  90                     -nop 
    ;
    // 004f8927  90                     -nop 
    ;
    // 004f8928  90                     -nop 
    ;
    // 004f8929  90                     -nop 
    ;
    // 004f892a  90                     -nop 
    ;
    // 004f892b  90                     -nop 
    ;
    // 004f892c  90                     -nop 
    ;
    // 004f892d  90                     -nop 
    ;
    // 004f892e  90                     -nop 
    ;
    // 004f892f  90                     -nop 
    ;
    // 004f8930  90                     -nop 
    ;
    // 004f8931  90                     -nop 
    ;
    // 004f8932  90                     -nop 
    ;
    // 004f8933  90                     -nop 
    ;
    // 004f8934  90                     -nop 
    ;
    // 004f8935  90                     -nop 
    ;
    // 004f8936  90                     -nop 
    ;
    // 004f8937  90                     -nop 
    ;
    // 004f8938  90                     -nop 
    ;
    // 004f8939  90                     -nop 
    ;
    // 004f893a  90                     -nop 
    ;
    // 004f893b  90                     -nop 
    ;
    // 004f893c  90                     -nop 
    ;
    // 004f893d  90                     -nop 
    ;
    // 004f893e  90                     -nop 
    ;
    // 004f893f  90                     -nop 
    ;
    // 004f8940  90                     -nop 
    ;
    // 004f8941  90                     -nop 
    ;
    // 004f8942  90                     -nop 
    ;
    // 004f8943  90                     -nop 
    ;
    // 004f8944  90                     -nop 
    ;
    // 004f8945  90                     -nop 
    ;
    // 004f8946  90                     -nop 
    ;
    // 004f8947  90                     -nop 
    ;
    // 004f8948  90                     -nop 
    ;
    // 004f8949  90                     -nop 
    ;
    // 004f894a  90                     -nop 
    ;
    // 004f894b  90                     -nop 
    ;
    // 004f894c  90                     -nop 
    ;
    // 004f894d  90                     -nop 
    ;
    // 004f894e  90                     -nop 
    ;
    // 004f894f  90                     -nop 
    ;
    // 004f8950  90                     -nop 
    ;
    // 004f8951  90                     -nop 
    ;
    // 004f8952  90                     -nop 
    ;
    // 004f8953  90                     -nop 
    ;
    // 004f8954  90                     -nop 
    ;
    // 004f8955  90                     -nop 
    ;
    // 004f8956  90                     -nop 
    ;
    // 004f8957  90                     -nop 
    ;
    // 004f8958  90                     -nop 
    ;
    // 004f8959  90                     -nop 
    ;
    // 004f895a  90                     -nop 
    ;
    // 004f895b  90                     -nop 
    ;
    // 004f895c  90                     -nop 
    ;
    // 004f895d  90                     -nop 
    ;
    // 004f895e  90                     -nop 
    ;
    // 004f895f  90                     -nop 
    ;
    // 004f8960  90                     -nop 
    ;
    // 004f8961  90                     -nop 
    ;
    // 004f8962  90                     -nop 
    ;
    // 004f8963  90                     -nop 
    ;
    // 004f8964  90                     -nop 
    ;
    // 004f8965  90                     -nop 
    ;
    // 004f8966  90                     -nop 
    ;
    // 004f8967  90                     -nop 
    ;
    // 004f8968  90                     -nop 
    ;
    // 004f8969  90                     -nop 
    ;
    // 004f896a  90                     -nop 
    ;
    // 004f896b  90                     -nop 
    ;
    // 004f896c  90                     -nop 
    ;
    // 004f896d  90                     -nop 
    ;
    // 004f896e  90                     -nop 
    ;
    // 004f896f  90                     -nop 
    ;
    // 004f8970  90                     -nop 
    ;
    // 004f8971  90                     -nop 
    ;
    // 004f8972  90                     -nop 
    ;
    // 004f8973  90                     -nop 
    ;
    // 004f8974  90                     -nop 
    ;
    // 004f8975  90                     -nop 
    ;
    // 004f8976  90                     -nop 
    ;
    // 004f8977  90                     -nop 
    ;
    // 004f8978  90                     -nop 
    ;
    // 004f8979  90                     -nop 
    ;
    // 004f897a  90                     -nop 
    ;
    // 004f897b  90                     -nop 
    ;
    // 004f897c  90                     -nop 
    ;
    // 004f897d  90                     -nop 
    ;
    // 004f897e  90                     -nop 
    ;
    // 004f897f  90                     -nop 
    ;
    // 004f8980  90                     -nop 
    ;
    // 004f8981  90                     -nop 
    ;
    // 004f8982  90                     -nop 
    ;
    // 004f8983  90                     -nop 
    ;
    // 004f8984  90                     -nop 
    ;
    // 004f8985  90                     -nop 
    ;
    // 004f8986  90                     -nop 
    ;
    // 004f8987  90                     -nop 
    ;
    // 004f8988  90                     -nop 
    ;
    // 004f8989  90                     -nop 
    ;
    // 004f898a  90                     -nop 
    ;
    // 004f898b  90                     -nop 
    ;
    // 004f898c  90                     -nop 
    ;
    // 004f898d  90                     -nop 
    ;
    // 004f898e  90                     -nop 
    ;
    // 004f898f  90                     -nop 
    ;
    // 004f8990  90                     -nop 
    ;
    // 004f8991  90                     -nop 
    ;
    // 004f8992  90                     -nop 
    ;
    // 004f8993  90                     -nop 
    ;
    // 004f8994  90                     -nop 
    ;
    // 004f8995  90                     -nop 
    ;
    // 004f8996  90                     -nop 
    ;
    // 004f8997  90                     -nop 
    ;
    // 004f8998  90                     -nop 
    ;
    // 004f8999  90                     -nop 
    ;
    // 004f899a  90                     -nop 
    ;
    // 004f899b  90                     -nop 
    ;
    // 004f899c  90                     -nop 
    ;
    // 004f899d  90                     -nop 
    ;
    // 004f899e  90                     -nop 
    ;
    // 004f899f  90                     -nop 
    ;
    // 004f89a0  90                     -nop 
    ;
    // 004f89a1  90                     -nop 
    ;
    // 004f89a2  90                     -nop 
    ;
    // 004f89a3  90                     -nop 
    ;
    // 004f89a4  90                     -nop 
    ;
    // 004f89a5  90                     -nop 
    ;
    // 004f89a6  90                     -nop 
    ;
    // 004f89a7  90                     -nop 
    ;
    // 004f89a8  90                     -nop 
    ;
    // 004f89a9  90                     -nop 
    ;
    // 004f89aa  90                     -nop 
    ;
    // 004f89ab  90                     -nop 
    ;
    // 004f89ac  90                     -nop 
    ;
    // 004f89ad  90                     -nop 
    ;
    // 004f89ae  90                     -nop 
    ;
    // 004f89af  90                     -nop 
    ;
    // 004f89b0  90                     -nop 
    ;
    // 004f89b1  90                     -nop 
    ;
    // 004f89b2  90                     -nop 
    ;
    // 004f89b3  90                     -nop 
    ;
    // 004f89b4  90                     -nop 
    ;
    // 004f89b5  90                     -nop 
    ;
    // 004f89b6  90                     -nop 
    ;
    // 004f89b7  90                     -nop 
    ;
    // 004f89b8  90                     -nop 
    ;
    // 004f89b9  90                     -nop 
    ;
    // 004f89ba  90                     -nop 
    ;
    // 004f89bb  90                     -nop 
    ;
    // 004f89bc  90                     -nop 
    ;
    // 004f89bd  90                     -nop 
    ;
    // 004f89be  90                     -nop 
    ;
    // 004f89bf  90                     -nop 
    ;
    // 004f89c0  90                     -nop 
    ;
    // 004f89c1  90                     -nop 
    ;
    // 004f89c2  90                     -nop 
    ;
    // 004f89c3  90                     -nop 
    ;
    // 004f89c4  90                     -nop 
    ;
    // 004f89c5  90                     -nop 
    ;
    // 004f89c6  90                     -nop 
    ;
    // 004f89c7  90                     -nop 
    ;
    // 004f89c8  90                     -nop 
    ;
    // 004f89c9  90                     -nop 
    ;
    // 004f89ca  90                     -nop 
    ;
    // 004f89cb  90                     -nop 
    ;
    // 004f89cc  90                     -nop 
    ;
    // 004f89cd  90                     -nop 
    ;
    // 004f89ce  90                     -nop 
    ;
    // 004f89cf  90                     -nop 
    ;
    // 004f89d0  90                     -nop 
    ;
    // 004f89d1  90                     -nop 
    ;
    // 004f89d2  90                     -nop 
    ;
    // 004f89d3  90                     -nop 
    ;
    // 004f89d4  90                     -nop 
    ;
    // 004f89d5  90                     -nop 
    ;
    // 004f89d6  90                     -nop 
    ;
    // 004f89d7  90                     -nop 
    ;
    // 004f89d8  90                     -nop 
    ;
    // 004f89d9  90                     -nop 
    ;
    // 004f89da  90                     -nop 
    ;
    // 004f89db  90                     -nop 
    ;
    // 004f89dc  90                     -nop 
    ;
    // 004f89dd  90                     -nop 
    ;
    // 004f89de  90                     -nop 
    ;
    // 004f89df  90                     -nop 
    ;
    // 004f89e0  90                     -nop 
    ;
    // 004f89e1  90                     -nop 
    ;
    // 004f89e2  90                     -nop 
    ;
    // 004f89e3  90                     -nop 
    ;
    // 004f89e4  90                     -nop 
    ;
    // 004f89e5  90                     -nop 
    ;
    // 004f89e6  90                     -nop 
    ;
    // 004f89e7  90                     -nop 
    ;
    // 004f89e8  90                     -nop 
    ;
    // 004f89e9  90                     -nop 
    ;
    // 004f89ea  90                     -nop 
    ;
    // 004f89eb  90                     -nop 
    ;
    // 004f89ec  90                     -nop 
    ;
    // 004f89ed  90                     -nop 
    ;
    // 004f89ee  90                     -nop 
    ;
    // 004f89ef  90                     -nop 
    ;
    // 004f89f0  90                     -nop 
    ;
    // 004f89f1  90                     -nop 
    ;
    // 004f89f2  90                     -nop 
    ;
    // 004f89f3  90                     -nop 
    ;
    // 004f89f4  90                     -nop 
    ;
    // 004f89f5  90                     -nop 
    ;
    // 004f89f6  90                     -nop 
    ;
    // 004f89f7  90                     -nop 
    ;
    // 004f89f8  90                     -nop 
    ;
    // 004f89f9  90                     -nop 
    ;
    // 004f89fa  90                     -nop 
    ;
    // 004f89fb  90                     -nop 
    ;
    // 004f89fc  90                     -nop 
    ;
    // 004f89fd  90                     -nop 
    ;
    // 004f89fe  90                     -nop 
    ;
    // 004f89ff  90                     -nop 
    ;
    // 004f8a00  90                     -nop 
    ;
    // 004f8a01  90                     -nop 
    ;
    // 004f8a02  90                     -nop 
    ;
    // 004f8a03  90                     -nop 
    ;
    // 004f8a04  90                     -nop 
    ;
    // 004f8a05  90                     -nop 
    ;
    // 004f8a06  90                     -nop 
    ;
    // 004f8a07  90                     -nop 
    ;
    // 004f8a08  90                     -nop 
    ;
    // 004f8a09  90                     -nop 
    ;
    // 004f8a0a  90                     -nop 
    ;
    // 004f8a0b  90                     -nop 
    ;
    // 004f8a0c  90                     -nop 
    ;
    // 004f8a0d  90                     -nop 
    ;
    // 004f8a0e  90                     -nop 
    ;
    // 004f8a0f  90                     -nop 
    ;
    // 004f8a10  90                     -nop 
    ;
    // 004f8a11  90                     -nop 
    ;
    // 004f8a12  90                     -nop 
    ;
    // 004f8a13  90                     -nop 
    ;
    // 004f8a14  90                     -nop 
    ;
    // 004f8a15  90                     -nop 
    ;
    // 004f8a16  90                     -nop 
    ;
    // 004f8a17  90                     -nop 
    ;
    // 004f8a18  90                     -nop 
    ;
    // 004f8a19  90                     -nop 
    ;
    // 004f8a1a  90                     -nop 
    ;
    // 004f8a1b  90                     -nop 
    ;
    // 004f8a1c  90                     -nop 
    ;
    // 004f8a1d  90                     -nop 
    ;
    // 004f8a1e  90                     -nop 
    ;
    // 004f8a1f  90                     -nop 
    ;
    // 004f8a20  90                     -nop 
    ;
    // 004f8a21  90                     -nop 
    ;
    // 004f8a22  90                     -nop 
    ;
    // 004f8a23  90                     -nop 
    ;
    // 004f8a24  90                     -nop 
    ;
    // 004f8a25  90                     -nop 
    ;
    // 004f8a26  90                     -nop 
    ;
    // 004f8a27  90                     -nop 
    ;
    // 004f8a28  90                     -nop 
    ;
    // 004f8a29  90                     -nop 
    ;
    // 004f8a2a  90                     -nop 
    ;
    // 004f8a2b  90                     -nop 
    ;
    // 004f8a2c  90                     -nop 
    ;
    // 004f8a2d  90                     -nop 
    ;
    // 004f8a2e  90                     -nop 
    ;
    // 004f8a2f  90                     -nop 
    ;
    // 004f8a30  90                     -nop 
    ;
    // 004f8a31  90                     -nop 
    ;
    // 004f8a32  90                     -nop 
    ;
    // 004f8a33  90                     -nop 
    ;
    // 004f8a34  90                     -nop 
    ;
    // 004f8a35  90                     -nop 
    ;
    // 004f8a36  90                     -nop 
    ;
    // 004f8a37  90                     -nop 
    ;
    // 004f8a38  90                     -nop 
    ;
    // 004f8a39  90                     -nop 
    ;
    // 004f8a3a  90                     -nop 
    ;
    // 004f8a3b  90                     -nop 
    ;
    // 004f8a3c  90                     -nop 
    ;
    // 004f8a3d  90                     -nop 
    ;
    // 004f8a3e  90                     -nop 
    ;
    // 004f8a3f  90                     -nop 
    ;
    // 004f8a40  90                     -nop 
    ;
    // 004f8a41  90                     -nop 
    ;
    // 004f8a42  90                     -nop 
    ;
    // 004f8a43  90                     -nop 
    ;
    // 004f8a44  90                     -nop 
    ;
    // 004f8a45  90                     -nop 
    ;
    // 004f8a46  90                     -nop 
    ;
    // 004f8a47  90                     -nop 
    ;
    // 004f8a48  90                     -nop 
    ;
    // 004f8a49  90                     -nop 
    ;
    // 004f8a4a  90                     -nop 
    ;
    // 004f8a4b  90                     -nop 
    ;
    // 004f8a4c  90                     -nop 
    ;
    // 004f8a4d  90                     -nop 
    ;
    // 004f8a4e  90                     -nop 
    ;
    // 004f8a4f  90                     -nop 
    ;
    // 004f8a50  90                     -nop 
    ;
    // 004f8a51  90                     -nop 
    ;
    // 004f8a52  90                     -nop 
    ;
    // 004f8a53  90                     -nop 
    ;
    // 004f8a54  90                     -nop 
    ;
    // 004f8a55  90                     -nop 
    ;
    // 004f8a56  90                     -nop 
    ;
    // 004f8a57  90                     -nop 
    ;
    // 004f8a58  90                     -nop 
    ;
    // 004f8a59  90                     -nop 
    ;
    // 004f8a5a  90                     -nop 
    ;
    // 004f8a5b  90                     -nop 
    ;
    // 004f8a5c  90                     -nop 
    ;
    // 004f8a5d  90                     -nop 
    ;
    // 004f8a5e  90                     -nop 
    ;
    // 004f8a5f  90                     -nop 
    ;
    // 004f8a60  90                     -nop 
    ;
    // 004f8a61  90                     -nop 
    ;
    // 004f8a62  90                     -nop 
    ;
    // 004f8a63  90                     -nop 
    ;
    // 004f8a64  90                     -nop 
    ;
    // 004f8a65  90                     -nop 
    ;
    // 004f8a66  90                     -nop 
    ;
    // 004f8a67  90                     -nop 
    ;
    // 004f8a68  90                     -nop 
    ;
    // 004f8a69  90                     -nop 
    ;
    // 004f8a6a  90                     -nop 
    ;
    // 004f8a6b  90                     -nop 
    ;
    // 004f8a6c  90                     -nop 
    ;
    // 004f8a6d  90                     -nop 
    ;
    // 004f8a6e  90                     -nop 
    ;
    // 004f8a6f  90                     -nop 
    ;
    // 004f8a70  90                     -nop 
    ;
    // 004f8a71  90                     -nop 
    ;
    // 004f8a72  90                     -nop 
    ;
    // 004f8a73  90                     -nop 
    ;
    // 004f8a74  90                     -nop 
    ;
    // 004f8a75  90                     -nop 
    ;
    // 004f8a76  90                     -nop 
    ;
    // 004f8a77  90                     -nop 
    ;
    // 004f8a78  90                     -nop 
    ;
    // 004f8a79  90                     -nop 
    ;
    // 004f8a7a  90                     -nop 
    ;
    // 004f8a7b  90                     -nop 
    ;
    // 004f8a7c  90                     -nop 
    ;
    // 004f8a7d  90                     -nop 
    ;
    // 004f8a7e  90                     -nop 
    ;
    // 004f8a7f  90                     -nop 
    ;
    // 004f8a80  90                     -nop 
    ;
    // 004f8a81  90                     -nop 
    ;
    // 004f8a82  90                     -nop 
    ;
    // 004f8a83  90                     -nop 
    ;
    // 004f8a84  90                     -nop 
    ;
    // 004f8a85  90                     -nop 
    ;
    // 004f8a86  90                     -nop 
    ;
    // 004f8a87  90                     -nop 
    ;
    // 004f8a88  90                     -nop 
    ;
    // 004f8a89  90                     -nop 
    ;
    // 004f8a8a  90                     -nop 
    ;
    // 004f8a8b  90                     -nop 
    ;
    // 004f8a8c  90                     -nop 
    ;
    // 004f8a8d  90                     -nop 
    ;
    // 004f8a8e  90                     -nop 
    ;
    // 004f8a8f  90                     -nop 
    ;
    // 004f8a90  90                     -nop 
    ;
    // 004f8a91  90                     -nop 
    ;
    // 004f8a92  90                     -nop 
    ;
    // 004f8a93  90                     -nop 
    ;
    // 004f8a94  90                     -nop 
    ;
    // 004f8a95  90                     -nop 
    ;
    // 004f8a96  90                     -nop 
    ;
    // 004f8a97  90                     -nop 
    ;
    // 004f8a98  90                     -nop 
    ;
    // 004f8a99  90                     -nop 
    ;
    // 004f8a9a  90                     -nop 
    ;
    // 004f8a9b  90                     -nop 
    ;
    // 004f8a9c  90                     -nop 
    ;
    // 004f8a9d  90                     -nop 
    ;
    // 004f8a9e  90                     -nop 
    ;
    // 004f8a9f  90                     -nop 
    ;
    // 004f8aa0  90                     -nop 
    ;
    // 004f8aa1  90                     -nop 
    ;
    // 004f8aa2  90                     -nop 
    ;
    // 004f8aa3  90                     -nop 
    ;
    // 004f8aa4  90                     -nop 
    ;
    // 004f8aa5  90                     -nop 
    ;
    // 004f8aa6  90                     -nop 
    ;
    // 004f8aa7  90                     -nop 
    ;
    // 004f8aa8  90                     -nop 
    ;
    // 004f8aa9  90                     -nop 
    ;
    // 004f8aaa  90                     -nop 
    ;
    // 004f8aab  90                     -nop 
    ;
    // 004f8aac  90                     -nop 
    ;
    // 004f8aad  90                     -nop 
    ;
    // 004f8aae  90                     -nop 
    ;
    // 004f8aaf  90                     -nop 
    ;
    // 004f8ab0  90                     -nop 
    ;
    // 004f8ab1  90                     -nop 
    ;
    // 004f8ab2  90                     -nop 
    ;
    // 004f8ab3  90                     -nop 
    ;
    // 004f8ab4  90                     -nop 
    ;
    // 004f8ab5  90                     -nop 
    ;
    // 004f8ab6  90                     -nop 
    ;
    // 004f8ab7  90                     -nop 
    ;
    // 004f8ab8  90                     -nop 
    ;
    // 004f8ab9  90                     -nop 
    ;
    // 004f8aba  90                     -nop 
    ;
    // 004f8abb  90                     -nop 
    ;
    // 004f8abc  90                     -nop 
    ;
    // 004f8abd  90                     -nop 
    ;
    // 004f8abe  90                     -nop 
    ;
    // 004f8abf  90                     -nop 
    ;
    // 004f8ac0  90                     -nop 
    ;
    // 004f8ac1  90                     -nop 
    ;
    // 004f8ac2  90                     -nop 
    ;
    // 004f8ac3  90                     -nop 
    ;
    // 004f8ac4  90                     -nop 
    ;
    // 004f8ac5  90                     -nop 
    ;
    // 004f8ac6  90                     -nop 
    ;
    // 004f8ac7  90                     -nop 
    ;
    // 004f8ac8  90                     -nop 
    ;
    // 004f8ac9  90                     -nop 
    ;
    // 004f8aca  90                     -nop 
    ;
    // 004f8acb  90                     -nop 
    ;
    // 004f8acc  90                     -nop 
    ;
    // 004f8acd  90                     -nop 
    ;
    // 004f8ace  90                     -nop 
    ;
    // 004f8acf  90                     -nop 
    ;
    // 004f8ad0  90                     -nop 
    ;
    // 004f8ad1  90                     -nop 
    ;
    // 004f8ad2  90                     -nop 
    ;
    // 004f8ad3  90                     -nop 
    ;
    // 004f8ad4  90                     -nop 
    ;
    // 004f8ad5  90                     -nop 
    ;
    // 004f8ad6  90                     -nop 
    ;
    // 004f8ad7  90                     -nop 
    ;
    // 004f8ad8  90                     -nop 
    ;
    // 004f8ad9  90                     -nop 
    ;
    // 004f8ada  90                     -nop 
    ;
    // 004f8adb  90                     -nop 
    ;
    // 004f8adc  90                     -nop 
    ;
    // 004f8add  90                     -nop 
    ;
    // 004f8ade  90                     -nop 
    ;
    // 004f8adf  90                     -nop 
    ;
    // 004f8ae0  90                     -nop 
    ;
    // 004f8ae1  90                     -nop 
    ;
    // 004f8ae2  90                     -nop 
    ;
    // 004f8ae3  90                     -nop 
    ;
    // 004f8ae4  90                     -nop 
    ;
    // 004f8ae5  90                     -nop 
    ;
    // 004f8ae6  90                     -nop 
    ;
    // 004f8ae7  90                     -nop 
    ;
    // 004f8ae8  90                     -nop 
    ;
    // 004f8ae9  90                     -nop 
    ;
    // 004f8aea  90                     -nop 
    ;
    // 004f8aeb  90                     -nop 
    ;
    // 004f8aec  90                     -nop 
    ;
    // 004f8aed  90                     -nop 
    ;
    // 004f8aee  90                     -nop 
    ;
    // 004f8aef  90                     -nop 
    ;
    // 004f8af0  90                     -nop 
    ;
    // 004f8af1  90                     -nop 
    ;
    // 004f8af2  90                     -nop 
    ;
    // 004f8af3  90                     -nop 
    ;
    // 004f8af4  90                     -nop 
    ;
    // 004f8af5  90                     -nop 
    ;
    // 004f8af6  90                     -nop 
    ;
    // 004f8af7  90                     -nop 
    ;
    // 004f8af8  90                     -nop 
    ;
    // 004f8af9  90                     -nop 
    ;
    // 004f8afa  90                     -nop 
    ;
    // 004f8afb  90                     -nop 
    ;
    // 004f8afc  90                     -nop 
    ;
    // 004f8afd  90                     -nop 
    ;
    // 004f8afe  90                     -nop 
    ;
    // 004f8aff  90                     -nop 
    ;
    // 004f8b00  90                     -nop 
    ;
    // 004f8b01  90                     -nop 
    ;
    // 004f8b02  90                     -nop 
    ;
    // 004f8b03  90                     -nop 
    ;
    // 004f8b04  90                     -nop 
    ;
    // 004f8b05  90                     -nop 
    ;
    // 004f8b06  90                     -nop 
    ;
    // 004f8b07  90                     -nop 
    ;
    // 004f8b08  90                     -nop 
    ;
    // 004f8b09  90                     -nop 
    ;
    // 004f8b0a  90                     -nop 
    ;
    // 004f8b0b  90                     -nop 
    ;
    // 004f8b0c  90                     -nop 
    ;
    // 004f8b0d  90                     -nop 
    ;
    // 004f8b0e  90                     -nop 
    ;
    // 004f8b0f  90                     -nop 
    ;
    // 004f8b10  90                     -nop 
    ;
    // 004f8b11  90                     -nop 
    ;
    // 004f8b12  90                     -nop 
    ;
    // 004f8b13  90                     -nop 
    ;
    // 004f8b14  90                     -nop 
    ;
    // 004f8b15  90                     -nop 
    ;
    // 004f8b16  90                     -nop 
    ;
    // 004f8b17  90                     -nop 
    ;
    // 004f8b18  90                     -nop 
    ;
    // 004f8b19  90                     -nop 
    ;
    // 004f8b1a  90                     -nop 
    ;
    // 004f8b1b  90                     -nop 
    ;
    // 004f8b1c  90                     -nop 
    ;
    // 004f8b1d  90                     -nop 
    ;
    // 004f8b1e  90                     -nop 
    ;
    // 004f8b1f  90                     -nop 
    ;
    // 004f8b20  90                     -nop 
    ;
    // 004f8b21  90                     -nop 
    ;
    // 004f8b22  90                     -nop 
    ;
    // 004f8b23  90                     -nop 
    ;
    // 004f8b24  90                     -nop 
    ;
    // 004f8b25  90                     -nop 
    ;
    // 004f8b26  90                     -nop 
    ;
    // 004f8b27  90                     -nop 
    ;
    // 004f8b28  90                     -nop 
    ;
    // 004f8b29  90                     -nop 
    ;
    // 004f8b2a  90                     -nop 
    ;
    // 004f8b2b  90                     -nop 
    ;
    // 004f8b2c  90                     -nop 
    ;
    // 004f8b2d  90                     -nop 
    ;
    // 004f8b2e  90                     -nop 
    ;
    // 004f8b2f  90                     -nop 
    ;
    // 004f8b30  90                     -nop 
    ;
    // 004f8b31  90                     -nop 
    ;
    // 004f8b32  90                     -nop 
    ;
    // 004f8b33  90                     -nop 
    ;
    // 004f8b34  90                     -nop 
    ;
    // 004f8b35  90                     -nop 
    ;
    // 004f8b36  90                     -nop 
    ;
    // 004f8b37  90                     -nop 
    ;
    // 004f8b38  90                     -nop 
    ;
    // 004f8b39  90                     -nop 
    ;
    // 004f8b3a  90                     -nop 
    ;
    // 004f8b3b  90                     -nop 
    ;
    // 004f8b3c  90                     -nop 
    ;
    // 004f8b3d  90                     -nop 
    ;
    // 004f8b3e  90                     -nop 
    ;
    // 004f8b3f  90                     -nop 
    ;
    // 004f8b40  90                     -nop 
    ;
    // 004f8b41  90                     -nop 
    ;
    // 004f8b42  90                     -nop 
    ;
    // 004f8b43  90                     -nop 
    ;
    // 004f8b44  90                     -nop 
    ;
    // 004f8b45  90                     -nop 
    ;
    // 004f8b46  90                     -nop 
    ;
    // 004f8b47  90                     -nop 
    ;
    // 004f8b48  90                     -nop 
    ;
    // 004f8b49  90                     -nop 
    ;
    // 004f8b4a  90                     -nop 
    ;
    // 004f8b4b  90                     -nop 
    ;
    // 004f8b4c  90                     -nop 
    ;
    // 004f8b4d  90                     -nop 
    ;
    // 004f8b4e  90                     -nop 
    ;
    // 004f8b4f  90                     -nop 
    ;
    // 004f8b50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8b51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8b52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8b53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8b54  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8b57  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f8b59  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f8b5b  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004f8b5f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004f8b64  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f8b69  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f8b6d  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004f8b70  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f8b72  7419                   -je 0x4f8b8d
    if (cpu.flags.zf)
    {
        goto L_0x004f8b8d;
    }
    // 004f8b74  803e00                 +cmp byte ptr [esi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8b77  7514                   -jne 0x4f8b8d
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b8d;
    }
    // 004f8b79  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8b7e  750b                   -jne 0x4f8b8b
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b8b;
    }
    // 004f8b80  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8b82  e8495f0100             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 004f8b87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8b89  7502                   -jne 0x4f8b8d
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b8d;
    }
L_0x004f8b8b:
    // 004f8b8b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f8b8d:
    // 004f8b8d  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8b92  750b                   -jne 0x4f8b9f
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b9f;
    }
    // 004f8b94  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8b96  e8355f0100             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 004f8b9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8b9d  7517                   -jne 0x4f8bb6
    if (!cpu.flags.zf)
    {
        goto L_0x004f8bb6;
    }
L_0x004f8b9f:
    // 004f8b9f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8ba0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8ba1  2eff15dc455300         -call dword ptr cs:[0x5345dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457372) /* 0x5345dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8ba8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8baa  750a                   -jne 0x4f8bb6
    if (!cpu.flags.zf)
    {
        goto L_0x004f8bb6;
    }
    // 004f8bac  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8bb1  e927010000             -jmp 0x4f8cdd
    goto L_0x004f8cdd;
L_0x004f8bb6:
    // 004f8bb6  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8bba  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f8bbc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8bbe  e825010000             -call 0x4f8ce8
    cpu.esp -= 4;
    sub_4f8ce8(app, cpu);
    if (cpu.terminate) return;
    // 004f8bc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8bc5  740d                   -je 0x4f8bd4
    if (cpu.flags.zf)
    {
        goto L_0x004f8bd4;
    }
    // 004f8bc7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8bcc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8bcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8bd4:
    // 004f8bd4  a158b1a000             -mov eax, dword ptr [0xa0b158]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 004f8bd9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8bdb  0f84fc000000           -je 0x4f8cdd
    if (cpu.flags.zf)
    {
        goto L_0x004f8cdd;
    }
    // 004f8be1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8be3  e868f40100             -call 0x518050
    cpu.esp -= 4;
    sub_518050(app, cpu);
    if (cpu.terminate) return;
    // 004f8be8  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004f8beb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8bef  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004f8bf2  e809edffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f8bf7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8bf9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f8bfb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8bfd  7517                   -jne 0x4f8c16
    if (!cpu.flags.zf)
    {
        goto L_0x004f8c16;
    }
    // 004f8bff  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004f8c04  e883830000             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 004f8c09  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8c0e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8c11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c15  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8c16:
    // 004f8c16  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f8c18  743c                   -je 0x4f8c56
    if (cpu.flags.zf)
    {
        goto L_0x004f8c56;
    }
    // 004f8c1a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f8c1c  e82ff40100             -call 0x518050
    cpu.esp -= 4;
    sub_518050(app, cpu);
    if (cpu.terminate) return;
    // 004f8c21  40                     -inc eax
    (cpu.eax)++;
    // 004f8c22  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8c26  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f8c2a  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004f8c2d  e8ceecffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f8c32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f8c34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8c36  7520                   -jne 0x4f8c58
    if (!cpu.flags.zf)
    {
        goto L_0x004f8c58;
    }
    // 004f8c38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f8c3a  e8b1edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8c3f  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004f8c44  e843830000             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 004f8c49  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8c4e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8c51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c55  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8c56:
    // 004f8c56  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f8c58:
    // 004f8c58  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004f8c5c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f8c5e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8c60  e81bf40100             -call 0x518080
    cpu.esp -= 4;
    sub_518080(app, cpu);
    if (cpu.terminate) return;
    // 004f8c65  83f8ff                 +cmp eax, -1
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
    // 004f8c68  751b                   -jne 0x4f8c85
    if (!cpu.flags.zf)
    {
        goto L_0x004f8c85;
    }
    // 004f8c6a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8c6c  e87fedffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8c71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8c73  e878edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8c78  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8c7d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8c80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8c85:
    // 004f8c85  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f8c87  7431                   -je 0x4f8cba
    if (cpu.flags.zf)
    {
        goto L_0x004f8cba;
    }
    // 004f8c89  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8c8d  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004f8c91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8c93  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f8c95  e8e6f30100             -call 0x518080
    cpu.esp -= 4;
    sub_518080(app, cpu);
    if (cpu.terminate) return;
    // 004f8c9a  83f8ff                 +cmp eax, -1
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
    // 004f8c9d  751b                   -jne 0x4f8cba
    if (!cpu.flags.zf)
    {
        goto L_0x004f8cba;
    }
    // 004f8c9f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8ca1  e84aedffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8ca6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8ca8  e843edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8cad  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8cb2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8cb5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8cba:
    // 004f8cba  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8cbe  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f8cc0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8cc2  e8c9f50100             -call 0x518290
    cpu.esp -= 4;
    sub_518290(app, cpu);
    if (cpu.terminate) return;
    // 004f8cc7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8cc9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8ccb  e820edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8cd0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f8cd2  7407                   -je 0x4f8cdb
    if (cpu.flags.zf)
    {
        goto L_0x004f8cdb;
    }
    // 004f8cd4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8cd6  e815edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x004f8cdb:
    // 004f8cdb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004f8cdd:
    // 004f8cdd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8ce0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f8b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f8b50;
    // 004f85c0  90                     -nop 
    ;
    // 004f85c1  90                     -nop 
    ;
    // 004f85c2  90                     -nop 
    ;
    // 004f85c3  90                     -nop 
    ;
    // 004f85c4  90                     -nop 
    ;
    // 004f85c5  90                     -nop 
    ;
    // 004f85c6  90                     -nop 
    ;
    // 004f85c7  90                     -nop 
    ;
    // 004f85c8  90                     -nop 
    ;
    // 004f85c9  90                     -nop 
    ;
    // 004f85ca  90                     -nop 
    ;
    // 004f85cb  90                     -nop 
    ;
    // 004f85cc  90                     -nop 
    ;
    // 004f85cd  90                     -nop 
    ;
    // 004f85ce  90                     -nop 
    ;
    // 004f85cf  90                     -nop 
    ;
    // 004f85d0  90                     -nop 
    ;
    // 004f85d1  90                     -nop 
    ;
    // 004f85d2  90                     -nop 
    ;
    // 004f85d3  90                     -nop 
    ;
    // 004f85d4  90                     -nop 
    ;
    // 004f85d5  90                     -nop 
    ;
    // 004f85d6  90                     -nop 
    ;
    // 004f85d7  90                     -nop 
    ;
    // 004f85d8  90                     -nop 
    ;
    // 004f85d9  90                     -nop 
    ;
    // 004f85da  90                     -nop 
    ;
    // 004f85db  90                     -nop 
    ;
    // 004f85dc  90                     -nop 
    ;
    // 004f85dd  90                     -nop 
    ;
    // 004f85de  90                     -nop 
    ;
    // 004f85df  90                     -nop 
    ;
    // 004f85e0  90                     -nop 
    ;
    // 004f85e1  90                     -nop 
    ;
    // 004f85e2  90                     -nop 
    ;
    // 004f85e3  90                     -nop 
    ;
    // 004f85e4  90                     -nop 
    ;
    // 004f85e5  90                     -nop 
    ;
    // 004f85e6  90                     -nop 
    ;
    // 004f85e7  90                     -nop 
    ;
    // 004f85e8  90                     -nop 
    ;
    // 004f85e9  90                     -nop 
    ;
    // 004f85ea  90                     -nop 
    ;
    // 004f85eb  90                     -nop 
    ;
    // 004f85ec  90                     -nop 
    ;
    // 004f85ed  90                     -nop 
    ;
    // 004f85ee  90                     -nop 
    ;
    // 004f85ef  90                     -nop 
    ;
    // 004f85f0  90                     -nop 
    ;
    // 004f85f1  90                     -nop 
    ;
    // 004f85f2  90                     -nop 
    ;
    // 004f85f3  90                     -nop 
    ;
    // 004f85f4  90                     -nop 
    ;
    // 004f85f5  90                     -nop 
    ;
    // 004f85f6  90                     -nop 
    ;
    // 004f85f7  90                     -nop 
    ;
    // 004f85f8  90                     -nop 
    ;
    // 004f85f9  90                     -nop 
    ;
    // 004f85fa  90                     -nop 
    ;
    // 004f85fb  90                     -nop 
    ;
    // 004f85fc  90                     -nop 
    ;
    // 004f85fd  90                     -nop 
    ;
    // 004f85fe  90                     -nop 
    ;
    // 004f85ff  90                     -nop 
    ;
    // 004f8600  90                     -nop 
    ;
    // 004f8601  90                     -nop 
    ;
    // 004f8602  90                     -nop 
    ;
    // 004f8603  90                     -nop 
    ;
    // 004f8604  90                     -nop 
    ;
    // 004f8605  90                     -nop 
    ;
    // 004f8606  90                     -nop 
    ;
    // 004f8607  90                     -nop 
    ;
    // 004f8608  90                     -nop 
    ;
    // 004f8609  90                     -nop 
    ;
    // 004f860a  90                     -nop 
    ;
    // 004f860b  90                     -nop 
    ;
    // 004f860c  90                     -nop 
    ;
    // 004f860d  90                     -nop 
    ;
    // 004f860e  90                     -nop 
    ;
    // 004f860f  90                     -nop 
    ;
    // 004f8610  90                     -nop 
    ;
    // 004f8611  90                     -nop 
    ;
    // 004f8612  90                     -nop 
    ;
    // 004f8613  90                     -nop 
    ;
    // 004f8614  90                     -nop 
    ;
    // 004f8615  90                     -nop 
    ;
    // 004f8616  90                     -nop 
    ;
    // 004f8617  90                     -nop 
    ;
    // 004f8618  90                     -nop 
    ;
    // 004f8619  90                     -nop 
    ;
    // 004f861a  90                     -nop 
    ;
    // 004f861b  90                     -nop 
    ;
    // 004f861c  90                     -nop 
    ;
    // 004f861d  90                     -nop 
    ;
    // 004f861e  90                     -nop 
    ;
    // 004f861f  90                     -nop 
    ;
    // 004f8620  90                     -nop 
    ;
    // 004f8621  90                     -nop 
    ;
    // 004f8622  90                     -nop 
    ;
    // 004f8623  90                     -nop 
    ;
    // 004f8624  90                     -nop 
    ;
    // 004f8625  90                     -nop 
    ;
    // 004f8626  90                     -nop 
    ;
    // 004f8627  90                     -nop 
    ;
    // 004f8628  90                     -nop 
    ;
    // 004f8629  90                     -nop 
    ;
    // 004f862a  90                     -nop 
    ;
    // 004f862b  90                     -nop 
    ;
    // 004f862c  90                     -nop 
    ;
    // 004f862d  90                     -nop 
    ;
    // 004f862e  90                     -nop 
    ;
    // 004f862f  90                     -nop 
    ;
    // 004f8630  90                     -nop 
    ;
    // 004f8631  90                     -nop 
    ;
    // 004f8632  90                     -nop 
    ;
    // 004f8633  90                     -nop 
    ;
    // 004f8634  90                     -nop 
    ;
    // 004f8635  90                     -nop 
    ;
    // 004f8636  90                     -nop 
    ;
    // 004f8637  90                     -nop 
    ;
    // 004f8638  90                     -nop 
    ;
    // 004f8639  90                     -nop 
    ;
    // 004f863a  90                     -nop 
    ;
    // 004f863b  90                     -nop 
    ;
    // 004f863c  90                     -nop 
    ;
    // 004f863d  90                     -nop 
    ;
    // 004f863e  90                     -nop 
    ;
    // 004f863f  90                     -nop 
    ;
    // 004f8640  90                     -nop 
    ;
    // 004f8641  90                     -nop 
    ;
    // 004f8642  90                     -nop 
    ;
    // 004f8643  90                     -nop 
    ;
    // 004f8644  90                     -nop 
    ;
    // 004f8645  90                     -nop 
    ;
    // 004f8646  90                     -nop 
    ;
    // 004f8647  90                     -nop 
    ;
    // 004f8648  90                     -nop 
    ;
    // 004f8649  90                     -nop 
    ;
    // 004f864a  90                     -nop 
    ;
    // 004f864b  90                     -nop 
    ;
    // 004f864c  90                     -nop 
    ;
    // 004f864d  90                     -nop 
    ;
    // 004f864e  90                     -nop 
    ;
    // 004f864f  90                     -nop 
    ;
    // 004f8650  90                     -nop 
    ;
    // 004f8651  90                     -nop 
    ;
    // 004f8652  90                     -nop 
    ;
    // 004f8653  90                     -nop 
    ;
    // 004f8654  90                     -nop 
    ;
    // 004f8655  90                     -nop 
    ;
    // 004f8656  90                     -nop 
    ;
    // 004f8657  90                     -nop 
    ;
    // 004f8658  90                     -nop 
    ;
    // 004f8659  90                     -nop 
    ;
    // 004f865a  90                     -nop 
    ;
    // 004f865b  90                     -nop 
    ;
    // 004f865c  90                     -nop 
    ;
    // 004f865d  90                     -nop 
    ;
    // 004f865e  90                     -nop 
    ;
    // 004f865f  90                     -nop 
    ;
    // 004f8660  90                     -nop 
    ;
    // 004f8661  90                     -nop 
    ;
    // 004f8662  90                     -nop 
    ;
    // 004f8663  90                     -nop 
    ;
    // 004f8664  90                     -nop 
    ;
    // 004f8665  90                     -nop 
    ;
    // 004f8666  90                     -nop 
    ;
    // 004f8667  90                     -nop 
    ;
    // 004f8668  90                     -nop 
    ;
    // 004f8669  90                     -nop 
    ;
    // 004f866a  90                     -nop 
    ;
    // 004f866b  90                     -nop 
    ;
    // 004f866c  90                     -nop 
    ;
    // 004f866d  90                     -nop 
    ;
    // 004f866e  90                     -nop 
    ;
    // 004f866f  90                     -nop 
    ;
    // 004f8670  90                     -nop 
    ;
    // 004f8671  90                     -nop 
    ;
    // 004f8672  90                     -nop 
    ;
    // 004f8673  90                     -nop 
    ;
    // 004f8674  90                     -nop 
    ;
    // 004f8675  90                     -nop 
    ;
    // 004f8676  90                     -nop 
    ;
    // 004f8677  90                     -nop 
    ;
    // 004f8678  90                     -nop 
    ;
    // 004f8679  90                     -nop 
    ;
    // 004f867a  90                     -nop 
    ;
    // 004f867b  90                     -nop 
    ;
    // 004f867c  90                     -nop 
    ;
    // 004f867d  90                     -nop 
    ;
    // 004f867e  90                     -nop 
    ;
    // 004f867f  90                     -nop 
    ;
    // 004f8680  90                     -nop 
    ;
    // 004f8681  90                     -nop 
    ;
    // 004f8682  90                     -nop 
    ;
    // 004f8683  90                     -nop 
    ;
    // 004f8684  90                     -nop 
    ;
    // 004f8685  90                     -nop 
    ;
    // 004f8686  90                     -nop 
    ;
    // 004f8687  90                     -nop 
    ;
    // 004f8688  90                     -nop 
    ;
    // 004f8689  90                     -nop 
    ;
    // 004f868a  90                     -nop 
    ;
    // 004f868b  90                     -nop 
    ;
    // 004f868c  90                     -nop 
    ;
    // 004f868d  90                     -nop 
    ;
    // 004f868e  90                     -nop 
    ;
    // 004f868f  90                     -nop 
    ;
    // 004f8690  90                     -nop 
    ;
    // 004f8691  90                     -nop 
    ;
    // 004f8692  90                     -nop 
    ;
    // 004f8693  90                     -nop 
    ;
    // 004f8694  90                     -nop 
    ;
    // 004f8695  90                     -nop 
    ;
    // 004f8696  90                     -nop 
    ;
    // 004f8697  90                     -nop 
    ;
    // 004f8698  90                     -nop 
    ;
    // 004f8699  90                     -nop 
    ;
    // 004f869a  90                     -nop 
    ;
    // 004f869b  90                     -nop 
    ;
    // 004f869c  90                     -nop 
    ;
    // 004f869d  90                     -nop 
    ;
    // 004f869e  90                     -nop 
    ;
    // 004f869f  90                     -nop 
    ;
    // 004f86a0  90                     -nop 
    ;
    // 004f86a1  90                     -nop 
    ;
    // 004f86a2  90                     -nop 
    ;
    // 004f86a3  90                     -nop 
    ;
    // 004f86a4  90                     -nop 
    ;
    // 004f86a5  90                     -nop 
    ;
    // 004f86a6  90                     -nop 
    ;
    // 004f86a7  90                     -nop 
    ;
    // 004f86a8  90                     -nop 
    ;
    // 004f86a9  90                     -nop 
    ;
    // 004f86aa  90                     -nop 
    ;
    // 004f86ab  90                     -nop 
    ;
    // 004f86ac  90                     -nop 
    ;
    // 004f86ad  90                     -nop 
    ;
    // 004f86ae  90                     -nop 
    ;
    // 004f86af  90                     -nop 
    ;
    // 004f86b0  90                     -nop 
    ;
    // 004f86b1  90                     -nop 
    ;
    // 004f86b2  90                     -nop 
    ;
    // 004f86b3  90                     -nop 
    ;
    // 004f86b4  90                     -nop 
    ;
    // 004f86b5  90                     -nop 
    ;
    // 004f86b6  90                     -nop 
    ;
    // 004f86b7  90                     -nop 
    ;
    // 004f86b8  90                     -nop 
    ;
    // 004f86b9  90                     -nop 
    ;
    // 004f86ba  90                     -nop 
    ;
    // 004f86bb  90                     -nop 
    ;
    // 004f86bc  90                     -nop 
    ;
    // 004f86bd  90                     -nop 
    ;
    // 004f86be  90                     -nop 
    ;
    // 004f86bf  90                     -nop 
    ;
    // 004f86c0  90                     -nop 
    ;
    // 004f86c1  90                     -nop 
    ;
    // 004f86c2  90                     -nop 
    ;
    // 004f86c3  90                     -nop 
    ;
    // 004f86c4  90                     -nop 
    ;
    // 004f86c5  90                     -nop 
    ;
    // 004f86c6  90                     -nop 
    ;
    // 004f86c7  90                     -nop 
    ;
    // 004f86c8  90                     -nop 
    ;
    // 004f86c9  90                     -nop 
    ;
    // 004f86ca  90                     -nop 
    ;
    // 004f86cb  90                     -nop 
    ;
    // 004f86cc  90                     -nop 
    ;
    // 004f86cd  90                     -nop 
    ;
    // 004f86ce  90                     -nop 
    ;
    // 004f86cf  90                     -nop 
    ;
    // 004f86d0  90                     -nop 
    ;
    // 004f86d1  90                     -nop 
    ;
    // 004f86d2  90                     -nop 
    ;
    // 004f86d3  90                     -nop 
    ;
    // 004f86d4  90                     -nop 
    ;
    // 004f86d5  90                     -nop 
    ;
    // 004f86d6  90                     -nop 
    ;
    // 004f86d7  90                     -nop 
    ;
    // 004f86d8  90                     -nop 
    ;
    // 004f86d9  90                     -nop 
    ;
    // 004f86da  90                     -nop 
    ;
    // 004f86db  90                     -nop 
    ;
    // 004f86dc  90                     -nop 
    ;
    // 004f86dd  90                     -nop 
    ;
    // 004f86de  90                     -nop 
    ;
    // 004f86df  90                     -nop 
    ;
    // 004f86e0  90                     -nop 
    ;
    // 004f86e1  90                     -nop 
    ;
    // 004f86e2  90                     -nop 
    ;
    // 004f86e3  90                     -nop 
    ;
    // 004f86e4  90                     -nop 
    ;
    // 004f86e5  90                     -nop 
    ;
    // 004f86e6  90                     -nop 
    ;
    // 004f86e7  90                     -nop 
    ;
    // 004f86e8  90                     -nop 
    ;
    // 004f86e9  90                     -nop 
    ;
    // 004f86ea  90                     -nop 
    ;
    // 004f86eb  90                     -nop 
    ;
    // 004f86ec  90                     -nop 
    ;
    // 004f86ed  90                     -nop 
    ;
    // 004f86ee  90                     -nop 
    ;
    // 004f86ef  90                     -nop 
    ;
    // 004f86f0  90                     -nop 
    ;
    // 004f86f1  90                     -nop 
    ;
    // 004f86f2  90                     -nop 
    ;
    // 004f86f3  90                     -nop 
    ;
    // 004f86f4  90                     -nop 
    ;
    // 004f86f5  90                     -nop 
    ;
    // 004f86f6  90                     -nop 
    ;
    // 004f86f7  90                     -nop 
    ;
    // 004f86f8  90                     -nop 
    ;
    // 004f86f9  90                     -nop 
    ;
    // 004f86fa  90                     -nop 
    ;
    // 004f86fb  90                     -nop 
    ;
    // 004f86fc  90                     -nop 
    ;
    // 004f86fd  90                     -nop 
    ;
    // 004f86fe  90                     -nop 
    ;
    // 004f86ff  90                     -nop 
    ;
    // 004f8700  90                     -nop 
    ;
    // 004f8701  90                     -nop 
    ;
    // 004f8702  90                     -nop 
    ;
    // 004f8703  90                     -nop 
    ;
    // 004f8704  90                     -nop 
    ;
    // 004f8705  90                     -nop 
    ;
    // 004f8706  90                     -nop 
    ;
    // 004f8707  90                     -nop 
    ;
    // 004f8708  90                     -nop 
    ;
    // 004f8709  90                     -nop 
    ;
    // 004f870a  90                     -nop 
    ;
    // 004f870b  90                     -nop 
    ;
    // 004f870c  90                     -nop 
    ;
    // 004f870d  90                     -nop 
    ;
    // 004f870e  90                     -nop 
    ;
    // 004f870f  90                     -nop 
    ;
    // 004f8710  90                     -nop 
    ;
    // 004f8711  90                     -nop 
    ;
    // 004f8712  90                     -nop 
    ;
    // 004f8713  90                     -nop 
    ;
    // 004f8714  90                     -nop 
    ;
    // 004f8715  90                     -nop 
    ;
    // 004f8716  90                     -nop 
    ;
    // 004f8717  90                     -nop 
    ;
    // 004f8718  90                     -nop 
    ;
    // 004f8719  90                     -nop 
    ;
    // 004f871a  90                     -nop 
    ;
    // 004f871b  90                     -nop 
    ;
    // 004f871c  90                     -nop 
    ;
    // 004f871d  90                     -nop 
    ;
    // 004f871e  90                     -nop 
    ;
    // 004f871f  90                     -nop 
    ;
    // 004f8720  90                     -nop 
    ;
    // 004f8721  90                     -nop 
    ;
    // 004f8722  90                     -nop 
    ;
    // 004f8723  90                     -nop 
    ;
    // 004f8724  90                     -nop 
    ;
    // 004f8725  90                     -nop 
    ;
    // 004f8726  90                     -nop 
    ;
    // 004f8727  90                     -nop 
    ;
    // 004f8728  90                     -nop 
    ;
    // 004f8729  90                     -nop 
    ;
    // 004f872a  90                     -nop 
    ;
    // 004f872b  90                     -nop 
    ;
    // 004f872c  90                     -nop 
    ;
    // 004f872d  90                     -nop 
    ;
    // 004f872e  90                     -nop 
    ;
    // 004f872f  90                     -nop 
    ;
    // 004f8730  90                     -nop 
    ;
    // 004f8731  90                     -nop 
    ;
    // 004f8732  90                     -nop 
    ;
    // 004f8733  90                     -nop 
    ;
    // 004f8734  90                     -nop 
    ;
    // 004f8735  90                     -nop 
    ;
    // 004f8736  90                     -nop 
    ;
    // 004f8737  90                     -nop 
    ;
    // 004f8738  90                     -nop 
    ;
    // 004f8739  90                     -nop 
    ;
    // 004f873a  90                     -nop 
    ;
    // 004f873b  90                     -nop 
    ;
    // 004f873c  90                     -nop 
    ;
    // 004f873d  90                     -nop 
    ;
    // 004f873e  90                     -nop 
    ;
    // 004f873f  90                     -nop 
    ;
    // 004f8740  90                     -nop 
    ;
    // 004f8741  90                     -nop 
    ;
    // 004f8742  90                     -nop 
    ;
    // 004f8743  90                     -nop 
    ;
    // 004f8744  90                     -nop 
    ;
    // 004f8745  90                     -nop 
    ;
    // 004f8746  90                     -nop 
    ;
    // 004f8747  90                     -nop 
    ;
    // 004f8748  90                     -nop 
    ;
    // 004f8749  90                     -nop 
    ;
    // 004f874a  90                     -nop 
    ;
    // 004f874b  90                     -nop 
    ;
    // 004f874c  90                     -nop 
    ;
    // 004f874d  90                     -nop 
    ;
    // 004f874e  90                     -nop 
    ;
    // 004f874f  90                     -nop 
    ;
    // 004f8750  90                     -nop 
    ;
    // 004f8751  90                     -nop 
    ;
    // 004f8752  90                     -nop 
    ;
    // 004f8753  90                     -nop 
    ;
    // 004f8754  90                     -nop 
    ;
    // 004f8755  90                     -nop 
    ;
    // 004f8756  90                     -nop 
    ;
    // 004f8757  90                     -nop 
    ;
    // 004f8758  90                     -nop 
    ;
    // 004f8759  90                     -nop 
    ;
    // 004f875a  90                     -nop 
    ;
    // 004f875b  90                     -nop 
    ;
    // 004f875c  90                     -nop 
    ;
    // 004f875d  90                     -nop 
    ;
    // 004f875e  90                     -nop 
    ;
    // 004f875f  90                     -nop 
    ;
    // 004f8760  90                     -nop 
    ;
    // 004f8761  90                     -nop 
    ;
    // 004f8762  90                     -nop 
    ;
    // 004f8763  90                     -nop 
    ;
    // 004f8764  90                     -nop 
    ;
    // 004f8765  90                     -nop 
    ;
    // 004f8766  90                     -nop 
    ;
    // 004f8767  90                     -nop 
    ;
    // 004f8768  90                     -nop 
    ;
    // 004f8769  90                     -nop 
    ;
    // 004f876a  90                     -nop 
    ;
    // 004f876b  90                     -nop 
    ;
    // 004f876c  90                     -nop 
    ;
    // 004f876d  90                     -nop 
    ;
    // 004f876e  90                     -nop 
    ;
    // 004f876f  90                     -nop 
    ;
    // 004f8770  90                     -nop 
    ;
    // 004f8771  90                     -nop 
    ;
    // 004f8772  90                     -nop 
    ;
    // 004f8773  90                     -nop 
    ;
    // 004f8774  90                     -nop 
    ;
    // 004f8775  90                     -nop 
    ;
    // 004f8776  90                     -nop 
    ;
    // 004f8777  90                     -nop 
    ;
    // 004f8778  90                     -nop 
    ;
    // 004f8779  90                     -nop 
    ;
    // 004f877a  90                     -nop 
    ;
    // 004f877b  90                     -nop 
    ;
    // 004f877c  90                     -nop 
    ;
    // 004f877d  90                     -nop 
    ;
    // 004f877e  90                     -nop 
    ;
    // 004f877f  90                     -nop 
    ;
    // 004f8780  90                     -nop 
    ;
    // 004f8781  90                     -nop 
    ;
    // 004f8782  90                     -nop 
    ;
    // 004f8783  90                     -nop 
    ;
    // 004f8784  90                     -nop 
    ;
    // 004f8785  90                     -nop 
    ;
    // 004f8786  90                     -nop 
    ;
    // 004f8787  90                     -nop 
    ;
    // 004f8788  90                     -nop 
    ;
    // 004f8789  90                     -nop 
    ;
    // 004f878a  90                     -nop 
    ;
    // 004f878b  90                     -nop 
    ;
    // 004f878c  90                     -nop 
    ;
    // 004f878d  90                     -nop 
    ;
    // 004f878e  90                     -nop 
    ;
    // 004f878f  90                     -nop 
    ;
    // 004f8790  90                     -nop 
    ;
    // 004f8791  90                     -nop 
    ;
    // 004f8792  90                     -nop 
    ;
    // 004f8793  90                     -nop 
    ;
    // 004f8794  90                     -nop 
    ;
    // 004f8795  90                     -nop 
    ;
    // 004f8796  90                     -nop 
    ;
    // 004f8797  90                     -nop 
    ;
    // 004f8798  90                     -nop 
    ;
    // 004f8799  90                     -nop 
    ;
    // 004f879a  90                     -nop 
    ;
    // 004f879b  90                     -nop 
    ;
    // 004f879c  90                     -nop 
    ;
    // 004f879d  90                     -nop 
    ;
    // 004f879e  90                     -nop 
    ;
    // 004f879f  90                     -nop 
    ;
    // 004f87a0  90                     -nop 
    ;
    // 004f87a1  90                     -nop 
    ;
    // 004f87a2  90                     -nop 
    ;
    // 004f87a3  90                     -nop 
    ;
    // 004f87a4  90                     -nop 
    ;
    // 004f87a5  90                     -nop 
    ;
    // 004f87a6  90                     -nop 
    ;
    // 004f87a7  90                     -nop 
    ;
    // 004f87a8  90                     -nop 
    ;
    // 004f87a9  90                     -nop 
    ;
    // 004f87aa  90                     -nop 
    ;
    // 004f87ab  90                     -nop 
    ;
    // 004f87ac  90                     -nop 
    ;
    // 004f87ad  90                     -nop 
    ;
    // 004f87ae  90                     -nop 
    ;
    // 004f87af  90                     -nop 
    ;
    // 004f87b0  90                     -nop 
    ;
    // 004f87b1  90                     -nop 
    ;
    // 004f87b2  90                     -nop 
    ;
    // 004f87b3  90                     -nop 
    ;
    // 004f87b4  90                     -nop 
    ;
    // 004f87b5  90                     -nop 
    ;
    // 004f87b6  90                     -nop 
    ;
    // 004f87b7  90                     -nop 
    ;
    // 004f87b8  90                     -nop 
    ;
    // 004f87b9  90                     -nop 
    ;
    // 004f87ba  90                     -nop 
    ;
    // 004f87bb  90                     -nop 
    ;
    // 004f87bc  90                     -nop 
    ;
    // 004f87bd  90                     -nop 
    ;
    // 004f87be  90                     -nop 
    ;
    // 004f87bf  90                     -nop 
    ;
    // 004f87c0  90                     -nop 
    ;
    // 004f87c1  90                     -nop 
    ;
    // 004f87c2  90                     -nop 
    ;
    // 004f87c3  90                     -nop 
    ;
    // 004f87c4  90                     -nop 
    ;
    // 004f87c5  90                     -nop 
    ;
    // 004f87c6  90                     -nop 
    ;
    // 004f87c7  90                     -nop 
    ;
    // 004f87c8  90                     -nop 
    ;
    // 004f87c9  90                     -nop 
    ;
    // 004f87ca  90                     -nop 
    ;
    // 004f87cb  90                     -nop 
    ;
    // 004f87cc  90                     -nop 
    ;
    // 004f87cd  90                     -nop 
    ;
    // 004f87ce  90                     -nop 
    ;
    // 004f87cf  90                     -nop 
    ;
    // 004f87d0  90                     -nop 
    ;
    // 004f87d1  90                     -nop 
    ;
    // 004f87d2  90                     -nop 
    ;
    // 004f87d3  90                     -nop 
    ;
    // 004f87d4  90                     -nop 
    ;
    // 004f87d5  90                     -nop 
    ;
    // 004f87d6  90                     -nop 
    ;
    // 004f87d7  90                     -nop 
    ;
    // 004f87d8  90                     -nop 
    ;
    // 004f87d9  90                     -nop 
    ;
    // 004f87da  90                     -nop 
    ;
    // 004f87db  90                     -nop 
    ;
    // 004f87dc  90                     -nop 
    ;
    // 004f87dd  90                     -nop 
    ;
    // 004f87de  90                     -nop 
    ;
    // 004f87df  90                     -nop 
    ;
    // 004f87e0  90                     -nop 
    ;
    // 004f87e1  90                     -nop 
    ;
    // 004f87e2  90                     -nop 
    ;
    // 004f87e3  90                     -nop 
    ;
    // 004f87e4  90                     -nop 
    ;
    // 004f87e5  90                     -nop 
    ;
    // 004f87e6  90                     -nop 
    ;
    // 004f87e7  90                     -nop 
    ;
    // 004f87e8  90                     -nop 
    ;
    // 004f87e9  90                     -nop 
    ;
    // 004f87ea  90                     -nop 
    ;
    // 004f87eb  90                     -nop 
    ;
    // 004f87ec  90                     -nop 
    ;
    // 004f87ed  90                     -nop 
    ;
    // 004f87ee  90                     -nop 
    ;
    // 004f87ef  90                     -nop 
    ;
    // 004f87f0  90                     -nop 
    ;
    // 004f87f1  90                     -nop 
    ;
    // 004f87f2  90                     -nop 
    ;
    // 004f87f3  90                     -nop 
    ;
    // 004f87f4  90                     -nop 
    ;
    // 004f87f5  90                     -nop 
    ;
    // 004f87f6  90                     -nop 
    ;
    // 004f87f7  90                     -nop 
    ;
    // 004f87f8  90                     -nop 
    ;
    // 004f87f9  90                     -nop 
    ;
    // 004f87fa  90                     -nop 
    ;
    // 004f87fb  90                     -nop 
    ;
    // 004f87fc  90                     -nop 
    ;
    // 004f87fd  90                     -nop 
    ;
    // 004f87fe  90                     -nop 
    ;
    // 004f87ff  90                     -nop 
    ;
    // 004f8800  90                     -nop 
    ;
    // 004f8801  90                     -nop 
    ;
    // 004f8802  90                     -nop 
    ;
    // 004f8803  90                     -nop 
    ;
    // 004f8804  90                     -nop 
    ;
    // 004f8805  90                     -nop 
    ;
    // 004f8806  90                     -nop 
    ;
    // 004f8807  90                     -nop 
    ;
    // 004f8808  90                     -nop 
    ;
    // 004f8809  90                     -nop 
    ;
    // 004f880a  90                     -nop 
    ;
    // 004f880b  90                     -nop 
    ;
    // 004f880c  90                     -nop 
    ;
    // 004f880d  90                     -nop 
    ;
    // 004f880e  90                     -nop 
    ;
    // 004f880f  90                     -nop 
    ;
    // 004f8810  90                     -nop 
    ;
    // 004f8811  90                     -nop 
    ;
    // 004f8812  90                     -nop 
    ;
    // 004f8813  90                     -nop 
    ;
    // 004f8814  90                     -nop 
    ;
    // 004f8815  90                     -nop 
    ;
    // 004f8816  90                     -nop 
    ;
    // 004f8817  90                     -nop 
    ;
    // 004f8818  90                     -nop 
    ;
    // 004f8819  90                     -nop 
    ;
    // 004f881a  90                     -nop 
    ;
    // 004f881b  90                     -nop 
    ;
    // 004f881c  90                     -nop 
    ;
    // 004f881d  90                     -nop 
    ;
    // 004f881e  90                     -nop 
    ;
    // 004f881f  90                     -nop 
    ;
    // 004f8820  90                     -nop 
    ;
    // 004f8821  90                     -nop 
    ;
    // 004f8822  90                     -nop 
    ;
    // 004f8823  90                     -nop 
    ;
    // 004f8824  90                     -nop 
    ;
    // 004f8825  90                     -nop 
    ;
    // 004f8826  90                     -nop 
    ;
    // 004f8827  90                     -nop 
    ;
    // 004f8828  90                     -nop 
    ;
    // 004f8829  90                     -nop 
    ;
    // 004f882a  90                     -nop 
    ;
    // 004f882b  90                     -nop 
    ;
    // 004f882c  90                     -nop 
    ;
    // 004f882d  90                     -nop 
    ;
    // 004f882e  90                     -nop 
    ;
    // 004f882f  90                     -nop 
    ;
    // 004f8830  90                     -nop 
    ;
    // 004f8831  90                     -nop 
    ;
    // 004f8832  90                     -nop 
    ;
    // 004f8833  90                     -nop 
    ;
    // 004f8834  90                     -nop 
    ;
    // 004f8835  90                     -nop 
    ;
    // 004f8836  90                     -nop 
    ;
    // 004f8837  90                     -nop 
    ;
    // 004f8838  90                     -nop 
    ;
    // 004f8839  90                     -nop 
    ;
    // 004f883a  90                     -nop 
    ;
    // 004f883b  90                     -nop 
    ;
    // 004f883c  90                     -nop 
    ;
    // 004f883d  90                     -nop 
    ;
    // 004f883e  90                     -nop 
    ;
    // 004f883f  90                     -nop 
    ;
    // 004f8840  90                     -nop 
    ;
    // 004f8841  90                     -nop 
    ;
    // 004f8842  90                     -nop 
    ;
    // 004f8843  90                     -nop 
    ;
    // 004f8844  90                     -nop 
    ;
    // 004f8845  90                     -nop 
    ;
    // 004f8846  90                     -nop 
    ;
    // 004f8847  90                     -nop 
    ;
    // 004f8848  90                     -nop 
    ;
    // 004f8849  90                     -nop 
    ;
    // 004f884a  90                     -nop 
    ;
    // 004f884b  90                     -nop 
    ;
    // 004f884c  90                     -nop 
    ;
    // 004f884d  90                     -nop 
    ;
    // 004f884e  90                     -nop 
    ;
    // 004f884f  90                     -nop 
    ;
    // 004f8850  90                     -nop 
    ;
    // 004f8851  90                     -nop 
    ;
    // 004f8852  90                     -nop 
    ;
    // 004f8853  90                     -nop 
    ;
    // 004f8854  90                     -nop 
    ;
    // 004f8855  90                     -nop 
    ;
    // 004f8856  90                     -nop 
    ;
    // 004f8857  90                     -nop 
    ;
    // 004f8858  90                     -nop 
    ;
    // 004f8859  90                     -nop 
    ;
    // 004f885a  90                     -nop 
    ;
    // 004f885b  90                     -nop 
    ;
    // 004f885c  90                     -nop 
    ;
    // 004f885d  90                     -nop 
    ;
    // 004f885e  90                     -nop 
    ;
    // 004f885f  90                     -nop 
    ;
    // 004f8860  90                     -nop 
    ;
    // 004f8861  90                     -nop 
    ;
    // 004f8862  90                     -nop 
    ;
    // 004f8863  90                     -nop 
    ;
    // 004f8864  90                     -nop 
    ;
    // 004f8865  90                     -nop 
    ;
    // 004f8866  90                     -nop 
    ;
    // 004f8867  90                     -nop 
    ;
    // 004f8868  90                     -nop 
    ;
    // 004f8869  90                     -nop 
    ;
    // 004f886a  90                     -nop 
    ;
    // 004f886b  90                     -nop 
    ;
    // 004f886c  90                     -nop 
    ;
    // 004f886d  90                     -nop 
    ;
    // 004f886e  90                     -nop 
    ;
    // 004f886f  90                     -nop 
    ;
    // 004f8870  90                     -nop 
    ;
    // 004f8871  90                     -nop 
    ;
    // 004f8872  90                     -nop 
    ;
    // 004f8873  90                     -nop 
    ;
    // 004f8874  90                     -nop 
    ;
    // 004f8875  90                     -nop 
    ;
    // 004f8876  90                     -nop 
    ;
    // 004f8877  90                     -nop 
    ;
    // 004f8878  90                     -nop 
    ;
    // 004f8879  90                     -nop 
    ;
    // 004f887a  90                     -nop 
    ;
    // 004f887b  90                     -nop 
    ;
    // 004f887c  90                     -nop 
    ;
    // 004f887d  90                     -nop 
    ;
    // 004f887e  90                     -nop 
    ;
    // 004f887f  90                     -nop 
    ;
    // 004f8880  90                     -nop 
    ;
    // 004f8881  90                     -nop 
    ;
    // 004f8882  90                     -nop 
    ;
    // 004f8883  90                     -nop 
    ;
    // 004f8884  90                     -nop 
    ;
    // 004f8885  90                     -nop 
    ;
    // 004f8886  90                     -nop 
    ;
    // 004f8887  90                     -nop 
    ;
    // 004f8888  90                     -nop 
    ;
    // 004f8889  90                     -nop 
    ;
    // 004f888a  90                     -nop 
    ;
    // 004f888b  90                     -nop 
    ;
    // 004f888c  90                     -nop 
    ;
    // 004f888d  90                     -nop 
    ;
    // 004f888e  90                     -nop 
    ;
    // 004f888f  90                     -nop 
    ;
    // 004f8890  90                     -nop 
    ;
    // 004f8891  90                     -nop 
    ;
    // 004f8892  90                     -nop 
    ;
    // 004f8893  90                     -nop 
    ;
    // 004f8894  90                     -nop 
    ;
    // 004f8895  90                     -nop 
    ;
    // 004f8896  90                     -nop 
    ;
    // 004f8897  90                     -nop 
    ;
    // 004f8898  90                     -nop 
    ;
    // 004f8899  90                     -nop 
    ;
    // 004f889a  90                     -nop 
    ;
    // 004f889b  90                     -nop 
    ;
    // 004f889c  90                     -nop 
    ;
    // 004f889d  90                     -nop 
    ;
    // 004f889e  90                     -nop 
    ;
    // 004f889f  90                     -nop 
    ;
    // 004f88a0  90                     -nop 
    ;
    // 004f88a1  90                     -nop 
    ;
    // 004f88a2  90                     -nop 
    ;
    // 004f88a3  90                     -nop 
    ;
    // 004f88a4  90                     -nop 
    ;
    // 004f88a5  90                     -nop 
    ;
    // 004f88a6  90                     -nop 
    ;
    // 004f88a7  90                     -nop 
    ;
    // 004f88a8  90                     -nop 
    ;
    // 004f88a9  90                     -nop 
    ;
    // 004f88aa  90                     -nop 
    ;
    // 004f88ab  90                     -nop 
    ;
    // 004f88ac  90                     -nop 
    ;
    // 004f88ad  90                     -nop 
    ;
    // 004f88ae  90                     -nop 
    ;
    // 004f88af  90                     -nop 
    ;
    // 004f88b0  90                     -nop 
    ;
    // 004f88b1  90                     -nop 
    ;
    // 004f88b2  90                     -nop 
    ;
    // 004f88b3  90                     -nop 
    ;
    // 004f88b4  90                     -nop 
    ;
    // 004f88b5  90                     -nop 
    ;
    // 004f88b6  90                     -nop 
    ;
    // 004f88b7  90                     -nop 
    ;
    // 004f88b8  90                     -nop 
    ;
    // 004f88b9  90                     -nop 
    ;
    // 004f88ba  90                     -nop 
    ;
    // 004f88bb  90                     -nop 
    ;
    // 004f88bc  90                     -nop 
    ;
    // 004f88bd  90                     -nop 
    ;
    // 004f88be  90                     -nop 
    ;
    // 004f88bf  90                     -nop 
    ;
    // 004f88c0  90                     -nop 
    ;
    // 004f88c1  90                     -nop 
    ;
    // 004f88c2  90                     -nop 
    ;
    // 004f88c3  90                     -nop 
    ;
    // 004f88c4  90                     -nop 
    ;
    // 004f88c5  90                     -nop 
    ;
    // 004f88c6  90                     -nop 
    ;
    // 004f88c7  90                     -nop 
    ;
    // 004f88c8  90                     -nop 
    ;
    // 004f88c9  90                     -nop 
    ;
    // 004f88ca  90                     -nop 
    ;
    // 004f88cb  90                     -nop 
    ;
    // 004f88cc  90                     -nop 
    ;
    // 004f88cd  90                     -nop 
    ;
    // 004f88ce  90                     -nop 
    ;
    // 004f88cf  90                     -nop 
    ;
    // 004f88d0  90                     -nop 
    ;
    // 004f88d1  90                     -nop 
    ;
    // 004f88d2  90                     -nop 
    ;
    // 004f88d3  90                     -nop 
    ;
    // 004f88d4  90                     -nop 
    ;
    // 004f88d5  90                     -nop 
    ;
    // 004f88d6  90                     -nop 
    ;
    // 004f88d7  90                     -nop 
    ;
    // 004f88d8  90                     -nop 
    ;
    // 004f88d9  90                     -nop 
    ;
    // 004f88da  90                     -nop 
    ;
    // 004f88db  90                     -nop 
    ;
    // 004f88dc  90                     -nop 
    ;
    // 004f88dd  90                     -nop 
    ;
    // 004f88de  90                     -nop 
    ;
    // 004f88df  90                     -nop 
    ;
    // 004f88e0  90                     -nop 
    ;
    // 004f88e1  90                     -nop 
    ;
    // 004f88e2  90                     -nop 
    ;
    // 004f88e3  90                     -nop 
    ;
    // 004f88e4  90                     -nop 
    ;
    // 004f88e5  90                     -nop 
    ;
    // 004f88e6  90                     -nop 
    ;
    // 004f88e7  90                     -nop 
    ;
    // 004f88e8  90                     -nop 
    ;
    // 004f88e9  90                     -nop 
    ;
    // 004f88ea  90                     -nop 
    ;
    // 004f88eb  90                     -nop 
    ;
    // 004f88ec  90                     -nop 
    ;
    // 004f88ed  90                     -nop 
    ;
    // 004f88ee  90                     -nop 
    ;
    // 004f88ef  90                     -nop 
    ;
    // 004f88f0  90                     -nop 
    ;
    // 004f88f1  90                     -nop 
    ;
    // 004f88f2  90                     -nop 
    ;
    // 004f88f3  90                     -nop 
    ;
    // 004f88f4  90                     -nop 
    ;
    // 004f88f5  90                     -nop 
    ;
    // 004f88f6  90                     -nop 
    ;
    // 004f88f7  90                     -nop 
    ;
    // 004f88f8  90                     -nop 
    ;
    // 004f88f9  90                     -nop 
    ;
    // 004f88fa  90                     -nop 
    ;
    // 004f88fb  90                     -nop 
    ;
    // 004f88fc  90                     -nop 
    ;
    // 004f88fd  90                     -nop 
    ;
    // 004f88fe  90                     -nop 
    ;
    // 004f88ff  90                     -nop 
    ;
    // 004f8900  90                     -nop 
    ;
    // 004f8901  90                     -nop 
    ;
    // 004f8902  90                     -nop 
    ;
    // 004f8903  90                     -nop 
    ;
    // 004f8904  90                     -nop 
    ;
    // 004f8905  90                     -nop 
    ;
    // 004f8906  90                     -nop 
    ;
    // 004f8907  90                     -nop 
    ;
    // 004f8908  90                     -nop 
    ;
    // 004f8909  90                     -nop 
    ;
    // 004f890a  90                     -nop 
    ;
    // 004f890b  90                     -nop 
    ;
    // 004f890c  90                     -nop 
    ;
    // 004f890d  90                     -nop 
    ;
    // 004f890e  90                     -nop 
    ;
    // 004f890f  90                     -nop 
    ;
    // 004f8910  90                     -nop 
    ;
    // 004f8911  90                     -nop 
    ;
    // 004f8912  90                     -nop 
    ;
    // 004f8913  90                     -nop 
    ;
    // 004f8914  90                     -nop 
    ;
    // 004f8915  90                     -nop 
    ;
    // 004f8916  90                     -nop 
    ;
    // 004f8917  90                     -nop 
    ;
    // 004f8918  90                     -nop 
    ;
    // 004f8919  90                     -nop 
    ;
    // 004f891a  90                     -nop 
    ;
    // 004f891b  90                     -nop 
    ;
    // 004f891c  90                     -nop 
    ;
    // 004f891d  90                     -nop 
    ;
    // 004f891e  90                     -nop 
    ;
    // 004f891f  90                     -nop 
    ;
    // 004f8920  90                     -nop 
    ;
    // 004f8921  90                     -nop 
    ;
    // 004f8922  90                     -nop 
    ;
    // 004f8923  90                     -nop 
    ;
    // 004f8924  90                     -nop 
    ;
    // 004f8925  90                     -nop 
    ;
    // 004f8926  90                     -nop 
    ;
    // 004f8927  90                     -nop 
    ;
    // 004f8928  90                     -nop 
    ;
    // 004f8929  90                     -nop 
    ;
    // 004f892a  90                     -nop 
    ;
    // 004f892b  90                     -nop 
    ;
    // 004f892c  90                     -nop 
    ;
    // 004f892d  90                     -nop 
    ;
    // 004f892e  90                     -nop 
    ;
    // 004f892f  90                     -nop 
    ;
    // 004f8930  90                     -nop 
    ;
    // 004f8931  90                     -nop 
    ;
    // 004f8932  90                     -nop 
    ;
    // 004f8933  90                     -nop 
    ;
    // 004f8934  90                     -nop 
    ;
    // 004f8935  90                     -nop 
    ;
    // 004f8936  90                     -nop 
    ;
    // 004f8937  90                     -nop 
    ;
    // 004f8938  90                     -nop 
    ;
    // 004f8939  90                     -nop 
    ;
    // 004f893a  90                     -nop 
    ;
    // 004f893b  90                     -nop 
    ;
    // 004f893c  90                     -nop 
    ;
    // 004f893d  90                     -nop 
    ;
    // 004f893e  90                     -nop 
    ;
    // 004f893f  90                     -nop 
    ;
    // 004f8940  90                     -nop 
    ;
    // 004f8941  90                     -nop 
    ;
    // 004f8942  90                     -nop 
    ;
    // 004f8943  90                     -nop 
    ;
    // 004f8944  90                     -nop 
    ;
    // 004f8945  90                     -nop 
    ;
    // 004f8946  90                     -nop 
    ;
    // 004f8947  90                     -nop 
    ;
    // 004f8948  90                     -nop 
    ;
    // 004f8949  90                     -nop 
    ;
    // 004f894a  90                     -nop 
    ;
    // 004f894b  90                     -nop 
    ;
    // 004f894c  90                     -nop 
    ;
    // 004f894d  90                     -nop 
    ;
    // 004f894e  90                     -nop 
    ;
    // 004f894f  90                     -nop 
    ;
    // 004f8950  90                     -nop 
    ;
    // 004f8951  90                     -nop 
    ;
    // 004f8952  90                     -nop 
    ;
    // 004f8953  90                     -nop 
    ;
    // 004f8954  90                     -nop 
    ;
    // 004f8955  90                     -nop 
    ;
    // 004f8956  90                     -nop 
    ;
    // 004f8957  90                     -nop 
    ;
    // 004f8958  90                     -nop 
    ;
    // 004f8959  90                     -nop 
    ;
    // 004f895a  90                     -nop 
    ;
    // 004f895b  90                     -nop 
    ;
    // 004f895c  90                     -nop 
    ;
    // 004f895d  90                     -nop 
    ;
    // 004f895e  90                     -nop 
    ;
    // 004f895f  90                     -nop 
    ;
    // 004f8960  90                     -nop 
    ;
    // 004f8961  90                     -nop 
    ;
    // 004f8962  90                     -nop 
    ;
    // 004f8963  90                     -nop 
    ;
    // 004f8964  90                     -nop 
    ;
    // 004f8965  90                     -nop 
    ;
    // 004f8966  90                     -nop 
    ;
    // 004f8967  90                     -nop 
    ;
    // 004f8968  90                     -nop 
    ;
    // 004f8969  90                     -nop 
    ;
    // 004f896a  90                     -nop 
    ;
    // 004f896b  90                     -nop 
    ;
    // 004f896c  90                     -nop 
    ;
    // 004f896d  90                     -nop 
    ;
    // 004f896e  90                     -nop 
    ;
    // 004f896f  90                     -nop 
    ;
    // 004f8970  90                     -nop 
    ;
    // 004f8971  90                     -nop 
    ;
    // 004f8972  90                     -nop 
    ;
    // 004f8973  90                     -nop 
    ;
    // 004f8974  90                     -nop 
    ;
    // 004f8975  90                     -nop 
    ;
    // 004f8976  90                     -nop 
    ;
    // 004f8977  90                     -nop 
    ;
    // 004f8978  90                     -nop 
    ;
    // 004f8979  90                     -nop 
    ;
    // 004f897a  90                     -nop 
    ;
    // 004f897b  90                     -nop 
    ;
    // 004f897c  90                     -nop 
    ;
    // 004f897d  90                     -nop 
    ;
    // 004f897e  90                     -nop 
    ;
    // 004f897f  90                     -nop 
    ;
    // 004f8980  90                     -nop 
    ;
    // 004f8981  90                     -nop 
    ;
    // 004f8982  90                     -nop 
    ;
    // 004f8983  90                     -nop 
    ;
    // 004f8984  90                     -nop 
    ;
    // 004f8985  90                     -nop 
    ;
    // 004f8986  90                     -nop 
    ;
    // 004f8987  90                     -nop 
    ;
    // 004f8988  90                     -nop 
    ;
    // 004f8989  90                     -nop 
    ;
    // 004f898a  90                     -nop 
    ;
    // 004f898b  90                     -nop 
    ;
    // 004f898c  90                     -nop 
    ;
    // 004f898d  90                     -nop 
    ;
    // 004f898e  90                     -nop 
    ;
    // 004f898f  90                     -nop 
    ;
    // 004f8990  90                     -nop 
    ;
    // 004f8991  90                     -nop 
    ;
    // 004f8992  90                     -nop 
    ;
    // 004f8993  90                     -nop 
    ;
    // 004f8994  90                     -nop 
    ;
    // 004f8995  90                     -nop 
    ;
    // 004f8996  90                     -nop 
    ;
    // 004f8997  90                     -nop 
    ;
    // 004f8998  90                     -nop 
    ;
    // 004f8999  90                     -nop 
    ;
    // 004f899a  90                     -nop 
    ;
    // 004f899b  90                     -nop 
    ;
    // 004f899c  90                     -nop 
    ;
    // 004f899d  90                     -nop 
    ;
    // 004f899e  90                     -nop 
    ;
    // 004f899f  90                     -nop 
    ;
    // 004f89a0  90                     -nop 
    ;
    // 004f89a1  90                     -nop 
    ;
    // 004f89a2  90                     -nop 
    ;
    // 004f89a3  90                     -nop 
    ;
    // 004f89a4  90                     -nop 
    ;
    // 004f89a5  90                     -nop 
    ;
    // 004f89a6  90                     -nop 
    ;
    // 004f89a7  90                     -nop 
    ;
    // 004f89a8  90                     -nop 
    ;
    // 004f89a9  90                     -nop 
    ;
    // 004f89aa  90                     -nop 
    ;
    // 004f89ab  90                     -nop 
    ;
    // 004f89ac  90                     -nop 
    ;
    // 004f89ad  90                     -nop 
    ;
    // 004f89ae  90                     -nop 
    ;
    // 004f89af  90                     -nop 
    ;
    // 004f89b0  90                     -nop 
    ;
    // 004f89b1  90                     -nop 
    ;
    // 004f89b2  90                     -nop 
    ;
    // 004f89b3  90                     -nop 
    ;
    // 004f89b4  90                     -nop 
    ;
    // 004f89b5  90                     -nop 
    ;
    // 004f89b6  90                     -nop 
    ;
    // 004f89b7  90                     -nop 
    ;
    // 004f89b8  90                     -nop 
    ;
    // 004f89b9  90                     -nop 
    ;
    // 004f89ba  90                     -nop 
    ;
    // 004f89bb  90                     -nop 
    ;
    // 004f89bc  90                     -nop 
    ;
    // 004f89bd  90                     -nop 
    ;
    // 004f89be  90                     -nop 
    ;
    // 004f89bf  90                     -nop 
    ;
    // 004f89c0  90                     -nop 
    ;
    // 004f89c1  90                     -nop 
    ;
    // 004f89c2  90                     -nop 
    ;
    // 004f89c3  90                     -nop 
    ;
    // 004f89c4  90                     -nop 
    ;
    // 004f89c5  90                     -nop 
    ;
    // 004f89c6  90                     -nop 
    ;
    // 004f89c7  90                     -nop 
    ;
    // 004f89c8  90                     -nop 
    ;
    // 004f89c9  90                     -nop 
    ;
    // 004f89ca  90                     -nop 
    ;
    // 004f89cb  90                     -nop 
    ;
    // 004f89cc  90                     -nop 
    ;
    // 004f89cd  90                     -nop 
    ;
    // 004f89ce  90                     -nop 
    ;
    // 004f89cf  90                     -nop 
    ;
    // 004f89d0  90                     -nop 
    ;
    // 004f89d1  90                     -nop 
    ;
    // 004f89d2  90                     -nop 
    ;
    // 004f89d3  90                     -nop 
    ;
    // 004f89d4  90                     -nop 
    ;
    // 004f89d5  90                     -nop 
    ;
    // 004f89d6  90                     -nop 
    ;
    // 004f89d7  90                     -nop 
    ;
    // 004f89d8  90                     -nop 
    ;
    // 004f89d9  90                     -nop 
    ;
    // 004f89da  90                     -nop 
    ;
    // 004f89db  90                     -nop 
    ;
    // 004f89dc  90                     -nop 
    ;
    // 004f89dd  90                     -nop 
    ;
    // 004f89de  90                     -nop 
    ;
    // 004f89df  90                     -nop 
    ;
    // 004f89e0  90                     -nop 
    ;
    // 004f89e1  90                     -nop 
    ;
    // 004f89e2  90                     -nop 
    ;
    // 004f89e3  90                     -nop 
    ;
    // 004f89e4  90                     -nop 
    ;
    // 004f89e5  90                     -nop 
    ;
    // 004f89e6  90                     -nop 
    ;
    // 004f89e7  90                     -nop 
    ;
    // 004f89e8  90                     -nop 
    ;
    // 004f89e9  90                     -nop 
    ;
    // 004f89ea  90                     -nop 
    ;
    // 004f89eb  90                     -nop 
    ;
    // 004f89ec  90                     -nop 
    ;
    // 004f89ed  90                     -nop 
    ;
    // 004f89ee  90                     -nop 
    ;
    // 004f89ef  90                     -nop 
    ;
    // 004f89f0  90                     -nop 
    ;
    // 004f89f1  90                     -nop 
    ;
    // 004f89f2  90                     -nop 
    ;
    // 004f89f3  90                     -nop 
    ;
    // 004f89f4  90                     -nop 
    ;
    // 004f89f5  90                     -nop 
    ;
    // 004f89f6  90                     -nop 
    ;
    // 004f89f7  90                     -nop 
    ;
    // 004f89f8  90                     -nop 
    ;
    // 004f89f9  90                     -nop 
    ;
    // 004f89fa  90                     -nop 
    ;
    // 004f89fb  90                     -nop 
    ;
    // 004f89fc  90                     -nop 
    ;
    // 004f89fd  90                     -nop 
    ;
    // 004f89fe  90                     -nop 
    ;
    // 004f89ff  90                     -nop 
    ;
    // 004f8a00  90                     -nop 
    ;
    // 004f8a01  90                     -nop 
    ;
    // 004f8a02  90                     -nop 
    ;
    // 004f8a03  90                     -nop 
    ;
    // 004f8a04  90                     -nop 
    ;
    // 004f8a05  90                     -nop 
    ;
    // 004f8a06  90                     -nop 
    ;
    // 004f8a07  90                     -nop 
    ;
    // 004f8a08  90                     -nop 
    ;
    // 004f8a09  90                     -nop 
    ;
    // 004f8a0a  90                     -nop 
    ;
    // 004f8a0b  90                     -nop 
    ;
    // 004f8a0c  90                     -nop 
    ;
    // 004f8a0d  90                     -nop 
    ;
    // 004f8a0e  90                     -nop 
    ;
    // 004f8a0f  90                     -nop 
    ;
    // 004f8a10  90                     -nop 
    ;
    // 004f8a11  90                     -nop 
    ;
    // 004f8a12  90                     -nop 
    ;
    // 004f8a13  90                     -nop 
    ;
    // 004f8a14  90                     -nop 
    ;
    // 004f8a15  90                     -nop 
    ;
    // 004f8a16  90                     -nop 
    ;
    // 004f8a17  90                     -nop 
    ;
    // 004f8a18  90                     -nop 
    ;
    // 004f8a19  90                     -nop 
    ;
    // 004f8a1a  90                     -nop 
    ;
    // 004f8a1b  90                     -nop 
    ;
    // 004f8a1c  90                     -nop 
    ;
    // 004f8a1d  90                     -nop 
    ;
    // 004f8a1e  90                     -nop 
    ;
    // 004f8a1f  90                     -nop 
    ;
    // 004f8a20  90                     -nop 
    ;
    // 004f8a21  90                     -nop 
    ;
    // 004f8a22  90                     -nop 
    ;
    // 004f8a23  90                     -nop 
    ;
    // 004f8a24  90                     -nop 
    ;
    // 004f8a25  90                     -nop 
    ;
    // 004f8a26  90                     -nop 
    ;
    // 004f8a27  90                     -nop 
    ;
    // 004f8a28  90                     -nop 
    ;
    // 004f8a29  90                     -nop 
    ;
    // 004f8a2a  90                     -nop 
    ;
    // 004f8a2b  90                     -nop 
    ;
    // 004f8a2c  90                     -nop 
    ;
    // 004f8a2d  90                     -nop 
    ;
    // 004f8a2e  90                     -nop 
    ;
    // 004f8a2f  90                     -nop 
    ;
    // 004f8a30  90                     -nop 
    ;
    // 004f8a31  90                     -nop 
    ;
    // 004f8a32  90                     -nop 
    ;
    // 004f8a33  90                     -nop 
    ;
    // 004f8a34  90                     -nop 
    ;
    // 004f8a35  90                     -nop 
    ;
    // 004f8a36  90                     -nop 
    ;
    // 004f8a37  90                     -nop 
    ;
    // 004f8a38  90                     -nop 
    ;
    // 004f8a39  90                     -nop 
    ;
    // 004f8a3a  90                     -nop 
    ;
    // 004f8a3b  90                     -nop 
    ;
    // 004f8a3c  90                     -nop 
    ;
    // 004f8a3d  90                     -nop 
    ;
    // 004f8a3e  90                     -nop 
    ;
    // 004f8a3f  90                     -nop 
    ;
    // 004f8a40  90                     -nop 
    ;
    // 004f8a41  90                     -nop 
    ;
    // 004f8a42  90                     -nop 
    ;
    // 004f8a43  90                     -nop 
    ;
    // 004f8a44  90                     -nop 
    ;
    // 004f8a45  90                     -nop 
    ;
    // 004f8a46  90                     -nop 
    ;
    // 004f8a47  90                     -nop 
    ;
    // 004f8a48  90                     -nop 
    ;
    // 004f8a49  90                     -nop 
    ;
    // 004f8a4a  90                     -nop 
    ;
    // 004f8a4b  90                     -nop 
    ;
    // 004f8a4c  90                     -nop 
    ;
    // 004f8a4d  90                     -nop 
    ;
    // 004f8a4e  90                     -nop 
    ;
    // 004f8a4f  90                     -nop 
    ;
    // 004f8a50  90                     -nop 
    ;
    // 004f8a51  90                     -nop 
    ;
    // 004f8a52  90                     -nop 
    ;
    // 004f8a53  90                     -nop 
    ;
    // 004f8a54  90                     -nop 
    ;
    // 004f8a55  90                     -nop 
    ;
    // 004f8a56  90                     -nop 
    ;
    // 004f8a57  90                     -nop 
    ;
    // 004f8a58  90                     -nop 
    ;
    // 004f8a59  90                     -nop 
    ;
    // 004f8a5a  90                     -nop 
    ;
    // 004f8a5b  90                     -nop 
    ;
    // 004f8a5c  90                     -nop 
    ;
    // 004f8a5d  90                     -nop 
    ;
    // 004f8a5e  90                     -nop 
    ;
    // 004f8a5f  90                     -nop 
    ;
    // 004f8a60  90                     -nop 
    ;
    // 004f8a61  90                     -nop 
    ;
    // 004f8a62  90                     -nop 
    ;
    // 004f8a63  90                     -nop 
    ;
    // 004f8a64  90                     -nop 
    ;
    // 004f8a65  90                     -nop 
    ;
    // 004f8a66  90                     -nop 
    ;
    // 004f8a67  90                     -nop 
    ;
    // 004f8a68  90                     -nop 
    ;
    // 004f8a69  90                     -nop 
    ;
    // 004f8a6a  90                     -nop 
    ;
    // 004f8a6b  90                     -nop 
    ;
    // 004f8a6c  90                     -nop 
    ;
    // 004f8a6d  90                     -nop 
    ;
    // 004f8a6e  90                     -nop 
    ;
    // 004f8a6f  90                     -nop 
    ;
    // 004f8a70  90                     -nop 
    ;
    // 004f8a71  90                     -nop 
    ;
    // 004f8a72  90                     -nop 
    ;
    // 004f8a73  90                     -nop 
    ;
    // 004f8a74  90                     -nop 
    ;
    // 004f8a75  90                     -nop 
    ;
    // 004f8a76  90                     -nop 
    ;
    // 004f8a77  90                     -nop 
    ;
    // 004f8a78  90                     -nop 
    ;
    // 004f8a79  90                     -nop 
    ;
    // 004f8a7a  90                     -nop 
    ;
    // 004f8a7b  90                     -nop 
    ;
    // 004f8a7c  90                     -nop 
    ;
    // 004f8a7d  90                     -nop 
    ;
    // 004f8a7e  90                     -nop 
    ;
    // 004f8a7f  90                     -nop 
    ;
    // 004f8a80  90                     -nop 
    ;
    // 004f8a81  90                     -nop 
    ;
    // 004f8a82  90                     -nop 
    ;
    // 004f8a83  90                     -nop 
    ;
    // 004f8a84  90                     -nop 
    ;
    // 004f8a85  90                     -nop 
    ;
    // 004f8a86  90                     -nop 
    ;
    // 004f8a87  90                     -nop 
    ;
    // 004f8a88  90                     -nop 
    ;
    // 004f8a89  90                     -nop 
    ;
    // 004f8a8a  90                     -nop 
    ;
    // 004f8a8b  90                     -nop 
    ;
    // 004f8a8c  90                     -nop 
    ;
    // 004f8a8d  90                     -nop 
    ;
    // 004f8a8e  90                     -nop 
    ;
    // 004f8a8f  90                     -nop 
    ;
    // 004f8a90  90                     -nop 
    ;
    // 004f8a91  90                     -nop 
    ;
    // 004f8a92  90                     -nop 
    ;
    // 004f8a93  90                     -nop 
    ;
    // 004f8a94  90                     -nop 
    ;
    // 004f8a95  90                     -nop 
    ;
    // 004f8a96  90                     -nop 
    ;
    // 004f8a97  90                     -nop 
    ;
    // 004f8a98  90                     -nop 
    ;
    // 004f8a99  90                     -nop 
    ;
    // 004f8a9a  90                     -nop 
    ;
    // 004f8a9b  90                     -nop 
    ;
    // 004f8a9c  90                     -nop 
    ;
    // 004f8a9d  90                     -nop 
    ;
    // 004f8a9e  90                     -nop 
    ;
    // 004f8a9f  90                     -nop 
    ;
    // 004f8aa0  90                     -nop 
    ;
    // 004f8aa1  90                     -nop 
    ;
    // 004f8aa2  90                     -nop 
    ;
    // 004f8aa3  90                     -nop 
    ;
    // 004f8aa4  90                     -nop 
    ;
    // 004f8aa5  90                     -nop 
    ;
    // 004f8aa6  90                     -nop 
    ;
    // 004f8aa7  90                     -nop 
    ;
    // 004f8aa8  90                     -nop 
    ;
    // 004f8aa9  90                     -nop 
    ;
    // 004f8aaa  90                     -nop 
    ;
    // 004f8aab  90                     -nop 
    ;
    // 004f8aac  90                     -nop 
    ;
    // 004f8aad  90                     -nop 
    ;
    // 004f8aae  90                     -nop 
    ;
    // 004f8aaf  90                     -nop 
    ;
    // 004f8ab0  90                     -nop 
    ;
    // 004f8ab1  90                     -nop 
    ;
    // 004f8ab2  90                     -nop 
    ;
    // 004f8ab3  90                     -nop 
    ;
    // 004f8ab4  90                     -nop 
    ;
    // 004f8ab5  90                     -nop 
    ;
    // 004f8ab6  90                     -nop 
    ;
    // 004f8ab7  90                     -nop 
    ;
    // 004f8ab8  90                     -nop 
    ;
    // 004f8ab9  90                     -nop 
    ;
    // 004f8aba  90                     -nop 
    ;
    // 004f8abb  90                     -nop 
    ;
    // 004f8abc  90                     -nop 
    ;
    // 004f8abd  90                     -nop 
    ;
    // 004f8abe  90                     -nop 
    ;
    // 004f8abf  90                     -nop 
    ;
    // 004f8ac0  90                     -nop 
    ;
    // 004f8ac1  90                     -nop 
    ;
    // 004f8ac2  90                     -nop 
    ;
    // 004f8ac3  90                     -nop 
    ;
    // 004f8ac4  90                     -nop 
    ;
    // 004f8ac5  90                     -nop 
    ;
    // 004f8ac6  90                     -nop 
    ;
    // 004f8ac7  90                     -nop 
    ;
    // 004f8ac8  90                     -nop 
    ;
    // 004f8ac9  90                     -nop 
    ;
    // 004f8aca  90                     -nop 
    ;
    // 004f8acb  90                     -nop 
    ;
    // 004f8acc  90                     -nop 
    ;
    // 004f8acd  90                     -nop 
    ;
    // 004f8ace  90                     -nop 
    ;
    // 004f8acf  90                     -nop 
    ;
    // 004f8ad0  90                     -nop 
    ;
    // 004f8ad1  90                     -nop 
    ;
    // 004f8ad2  90                     -nop 
    ;
    // 004f8ad3  90                     -nop 
    ;
    // 004f8ad4  90                     -nop 
    ;
    // 004f8ad5  90                     -nop 
    ;
    // 004f8ad6  90                     -nop 
    ;
    // 004f8ad7  90                     -nop 
    ;
    // 004f8ad8  90                     -nop 
    ;
    // 004f8ad9  90                     -nop 
    ;
    // 004f8ada  90                     -nop 
    ;
    // 004f8adb  90                     -nop 
    ;
    // 004f8adc  90                     -nop 
    ;
    // 004f8add  90                     -nop 
    ;
    // 004f8ade  90                     -nop 
    ;
    // 004f8adf  90                     -nop 
    ;
    // 004f8ae0  90                     -nop 
    ;
    // 004f8ae1  90                     -nop 
    ;
    // 004f8ae2  90                     -nop 
    ;
    // 004f8ae3  90                     -nop 
    ;
    // 004f8ae4  90                     -nop 
    ;
    // 004f8ae5  90                     -nop 
    ;
    // 004f8ae6  90                     -nop 
    ;
    // 004f8ae7  90                     -nop 
    ;
    // 004f8ae8  90                     -nop 
    ;
    // 004f8ae9  90                     -nop 
    ;
    // 004f8aea  90                     -nop 
    ;
    // 004f8aeb  90                     -nop 
    ;
    // 004f8aec  90                     -nop 
    ;
    // 004f8aed  90                     -nop 
    ;
    // 004f8aee  90                     -nop 
    ;
    // 004f8aef  90                     -nop 
    ;
    // 004f8af0  90                     -nop 
    ;
    // 004f8af1  90                     -nop 
    ;
    // 004f8af2  90                     -nop 
    ;
    // 004f8af3  90                     -nop 
    ;
    // 004f8af4  90                     -nop 
    ;
    // 004f8af5  90                     -nop 
    ;
    // 004f8af6  90                     -nop 
    ;
    // 004f8af7  90                     -nop 
    ;
    // 004f8af8  90                     -nop 
    ;
    // 004f8af9  90                     -nop 
    ;
    // 004f8afa  90                     -nop 
    ;
    // 004f8afb  90                     -nop 
    ;
    // 004f8afc  90                     -nop 
    ;
    // 004f8afd  90                     -nop 
    ;
    // 004f8afe  90                     -nop 
    ;
    // 004f8aff  90                     -nop 
    ;
    // 004f8b00  90                     -nop 
    ;
    // 004f8b01  90                     -nop 
    ;
    // 004f8b02  90                     -nop 
    ;
    // 004f8b03  90                     -nop 
    ;
    // 004f8b04  90                     -nop 
    ;
    // 004f8b05  90                     -nop 
    ;
    // 004f8b06  90                     -nop 
    ;
    // 004f8b07  90                     -nop 
    ;
    // 004f8b08  90                     -nop 
    ;
    // 004f8b09  90                     -nop 
    ;
    // 004f8b0a  90                     -nop 
    ;
    // 004f8b0b  90                     -nop 
    ;
    // 004f8b0c  90                     -nop 
    ;
    // 004f8b0d  90                     -nop 
    ;
    // 004f8b0e  90                     -nop 
    ;
    // 004f8b0f  90                     -nop 
    ;
    // 004f8b10  90                     -nop 
    ;
    // 004f8b11  90                     -nop 
    ;
    // 004f8b12  90                     -nop 
    ;
    // 004f8b13  90                     -nop 
    ;
    // 004f8b14  90                     -nop 
    ;
    // 004f8b15  90                     -nop 
    ;
    // 004f8b16  90                     -nop 
    ;
    // 004f8b17  90                     -nop 
    ;
    // 004f8b18  90                     -nop 
    ;
    // 004f8b19  90                     -nop 
    ;
    // 004f8b1a  90                     -nop 
    ;
    // 004f8b1b  90                     -nop 
    ;
    // 004f8b1c  90                     -nop 
    ;
    // 004f8b1d  90                     -nop 
    ;
    // 004f8b1e  90                     -nop 
    ;
    // 004f8b1f  90                     -nop 
    ;
    // 004f8b20  90                     -nop 
    ;
    // 004f8b21  90                     -nop 
    ;
    // 004f8b22  90                     -nop 
    ;
    // 004f8b23  90                     -nop 
    ;
    // 004f8b24  90                     -nop 
    ;
    // 004f8b25  90                     -nop 
    ;
    // 004f8b26  90                     -nop 
    ;
    // 004f8b27  90                     -nop 
    ;
    // 004f8b28  90                     -nop 
    ;
    // 004f8b29  90                     -nop 
    ;
    // 004f8b2a  90                     -nop 
    ;
    // 004f8b2b  90                     -nop 
    ;
    // 004f8b2c  90                     -nop 
    ;
    // 004f8b2d  90                     -nop 
    ;
    // 004f8b2e  90                     -nop 
    ;
    // 004f8b2f  90                     -nop 
    ;
    // 004f8b30  90                     -nop 
    ;
    // 004f8b31  90                     -nop 
    ;
    // 004f8b32  90                     -nop 
    ;
    // 004f8b33  90                     -nop 
    ;
    // 004f8b34  90                     -nop 
    ;
    // 004f8b35  90                     -nop 
    ;
    // 004f8b36  90                     -nop 
    ;
    // 004f8b37  90                     -nop 
    ;
    // 004f8b38  90                     -nop 
    ;
    // 004f8b39  90                     -nop 
    ;
    // 004f8b3a  90                     -nop 
    ;
    // 004f8b3b  90                     -nop 
    ;
    // 004f8b3c  90                     -nop 
    ;
    // 004f8b3d  90                     -nop 
    ;
    // 004f8b3e  90                     -nop 
    ;
    // 004f8b3f  90                     -nop 
    ;
    // 004f8b40  90                     -nop 
    ;
    // 004f8b41  90                     -nop 
    ;
    // 004f8b42  90                     -nop 
    ;
    // 004f8b43  90                     -nop 
    ;
    // 004f8b44  90                     -nop 
    ;
    // 004f8b45  90                     -nop 
    ;
    // 004f8b46  90                     -nop 
    ;
    // 004f8b47  90                     -nop 
    ;
    // 004f8b48  90                     -nop 
    ;
    // 004f8b49  90                     -nop 
    ;
    // 004f8b4a  90                     -nop 
    ;
    // 004f8b4b  90                     -nop 
    ;
    // 004f8b4c  90                     -nop 
    ;
    // 004f8b4d  90                     -nop 
    ;
    // 004f8b4e  90                     -nop 
    ;
    // 004f8b4f  90                     -nop 
    ;
L_entry_0x004f8b50:
    // 004f8b50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8b51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8b52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8b53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8b54  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8b57  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f8b59  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f8b5b  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004f8b5f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004f8b64  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f8b69  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f8b6d  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004f8b70  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f8b72  7419                   -je 0x4f8b8d
    if (cpu.flags.zf)
    {
        goto L_0x004f8b8d;
    }
    // 004f8b74  803e00                 +cmp byte ptr [esi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8b77  7514                   -jne 0x4f8b8d
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b8d;
    }
    // 004f8b79  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8b7e  750b                   -jne 0x4f8b8b
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b8b;
    }
    // 004f8b80  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8b82  e8495f0100             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 004f8b87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8b89  7502                   -jne 0x4f8b8d
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b8d;
    }
L_0x004f8b8b:
    // 004f8b8b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f8b8d:
    // 004f8b8d  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f8b92  750b                   -jne 0x4f8b9f
    if (!cpu.flags.zf)
    {
        goto L_0x004f8b9f;
    }
    // 004f8b94  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8b96  e8355f0100             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 004f8b9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8b9d  7517                   -jne 0x4f8bb6
    if (!cpu.flags.zf)
    {
        goto L_0x004f8bb6;
    }
L_0x004f8b9f:
    // 004f8b9f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8ba0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8ba1  2eff15dc455300         -call dword ptr cs:[0x5345dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457372) /* 0x5345dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f8ba8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8baa  750a                   -jne 0x4f8bb6
    if (!cpu.flags.zf)
    {
        goto L_0x004f8bb6;
    }
    // 004f8bac  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8bb1  e927010000             -jmp 0x4f8cdd
    goto L_0x004f8cdd;
L_0x004f8bb6:
    // 004f8bb6  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8bba  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f8bbc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8bbe  e825010000             -call 0x4f8ce8
    cpu.esp -= 4;
    sub_4f8ce8(app, cpu);
    if (cpu.terminate) return;
    // 004f8bc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8bc5  740d                   -je 0x4f8bd4
    if (cpu.flags.zf)
    {
        goto L_0x004f8bd4;
    }
    // 004f8bc7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8bcc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8bcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8bd3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8bd4:
    // 004f8bd4  a158b1a000             -mov eax, dword ptr [0xa0b158]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 004f8bd9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8bdb  0f84fc000000           -je 0x4f8cdd
    if (cpu.flags.zf)
    {
        goto L_0x004f8cdd;
    }
    // 004f8be1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8be3  e868f40100             -call 0x518050
    cpu.esp -= 4;
    sub_518050(app, cpu);
    if (cpu.terminate) return;
    // 004f8be8  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004f8beb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8bef  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004f8bf2  e809edffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f8bf7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8bf9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f8bfb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8bfd  7517                   -jne 0x4f8c16
    if (!cpu.flags.zf)
    {
        goto L_0x004f8c16;
    }
    // 004f8bff  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004f8c04  e883830000             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 004f8c09  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8c0e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8c11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c15  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8c16:
    // 004f8c16  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f8c18  743c                   -je 0x4f8c56
    if (cpu.flags.zf)
    {
        goto L_0x004f8c56;
    }
    // 004f8c1a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f8c1c  e82ff40100             -call 0x518050
    cpu.esp -= 4;
    sub_518050(app, cpu);
    if (cpu.terminate) return;
    // 004f8c21  40                     -inc eax
    (cpu.eax)++;
    // 004f8c22  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8c26  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f8c2a  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004f8c2d  e8ceecffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f8c32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f8c34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8c36  7520                   -jne 0x4f8c58
    if (!cpu.flags.zf)
    {
        goto L_0x004f8c58;
    }
    // 004f8c38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f8c3a  e8b1edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8c3f  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004f8c44  e843830000             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 004f8c49  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8c4e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8c51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c55  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8c56:
    // 004f8c56  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f8c58:
    // 004f8c58  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004f8c5c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f8c5e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8c60  e81bf40100             -call 0x518080
    cpu.esp -= 4;
    sub_518080(app, cpu);
    if (cpu.terminate) return;
    // 004f8c65  83f8ff                 +cmp eax, -1
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
    // 004f8c68  751b                   -jne 0x4f8c85
    if (!cpu.flags.zf)
    {
        goto L_0x004f8c85;
    }
    // 004f8c6a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8c6c  e87fedffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8c71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8c73  e878edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8c78  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8c7d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8c80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8c84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8c85:
    // 004f8c85  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f8c87  7431                   -je 0x4f8cba
    if (cpu.flags.zf)
    {
        goto L_0x004f8cba;
    }
    // 004f8c89  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8c8d  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004f8c91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8c93  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f8c95  e8e6f30100             -call 0x518080
    cpu.esp -= 4;
    sub_518080(app, cpu);
    if (cpu.terminate) return;
    // 004f8c9a  83f8ff                 +cmp eax, -1
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
    // 004f8c9d  751b                   -jne 0x4f8cba
    if (!cpu.flags.zf)
    {
        goto L_0x004f8cba;
    }
    // 004f8c9f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8ca1  e84aedffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8ca6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8ca8  e843edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8cad  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8cb2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8cb5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8cb9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8cba:
    // 004f8cba  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8cbe  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f8cc0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8cc2  e8c9f50100             -call 0x518290
    cpu.esp -= 4;
    sub_518290(app, cpu);
    if (cpu.terminate) return;
    // 004f8cc7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8cc9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f8ccb  e820edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f8cd0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f8cd2  7407                   -je 0x4f8cdb
    if (cpu.flags.zf)
    {
        goto L_0x004f8cdb;
    }
    // 004f8cd4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8cd6  e815edffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x004f8cdb:
    // 004f8cdb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004f8cdd:
    // 004f8cdd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8ce0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ce4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f8ce8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8ce8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8ce9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8cea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8ceb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8cec  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8cef  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f8cf3  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f8cf7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8cf9  750a                   -jne 0x4f8d05
    if (!cpu.flags.zf)
    {
        goto L_0x004f8d05;
    }
    // 004f8cfb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8d00  e928020000             -jmp 0x4f8f2d
    goto L_0x004f8f2d;
L_0x004f8d05:
    // 004f8d05  803800                 +cmp byte ptr [eax], 0
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
    // 004f8d08  750d                   -jne 0x4f8d17
    if (!cpu.flags.zf)
    {
        goto L_0x004f8d17;
    }
    // 004f8d0a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8d0f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8d12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8d17:
    // 004f8d17  a154b1a000             -mov eax, dword ptr [0xa0b154]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 004f8d1c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f8d20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8d22  754b                   -jne 0x4f8d6f
    if (!cpu.flags.zf)
    {
        goto L_0x004f8d6f;
    }
    // 004f8d24  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004f8d29  0f84fe010000           -je 0x4f8f2d
    if (cpu.flags.zf)
    {
        goto L_0x004f8f2d;
    }
    // 004f8d2f  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004f8d34  e8c7ebffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f8d39  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f8d3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8d3f  750d                   -jne 0x4f8d4e
    if (!cpu.flags.zf)
    {
        goto L_0x004f8d4e;
    }
    // 004f8d41  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8d46  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8d49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8d4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8d4e:
    // 004f8d4e  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004f8d54  a354b1a000             -mov dword ptr [0xa0b154], eax
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.eax;
    // 004f8d59  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004f8d60  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f8d63  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004f8d65  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 004f8d6a  e9f7000000             -jmp 0x4f8e66
    goto L_0x004f8e66;
L_0x004f8d6f:
    // 004f8d6f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8d73  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8d77  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8d7b  e8b8010000             -call 0x4f8f38
    cpu.esp -= 4;
    sub_4f8f38(app, cpu);
    if (cpu.terminate) return;
    // 004f8d80  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f8d82  0f84a3010000           -je 0x4f8f2b
    if (cpu.flags.zf)
    {
        goto L_0x004f8f2b;
    }
    // 004f8d88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8d8a  0f8fcb000000           -jg 0x4f8e5b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f8e5b;
    }
    // 004f8d90  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004f8d92  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f8d94  8b3d50b1a000           -mov edi, dword ptr [0xa0b150]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8d9a  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 004f8da1  40                     -inc eax
    (cpu.eax)++;
    // 004f8da2  8d5908                 -lea ebx, [ecx + 8]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004f8da5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f8da8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f8daa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f8dac  7550                   -jne 0x4f8dfe
    if (!cpu.flags.zf)
    {
        goto L_0x004f8dfe;
    }
    // 004f8dae  e84debffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f8db3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8db5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f8db9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8dbb  750d                   -jne 0x4f8dca
    if (!cpu.flags.zf)
    {
        goto L_0x004f8dca;
    }
    // 004f8dbd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8dc2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8dc5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8dc6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8dc7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8dc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8dc9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8dca:
    // 004f8dca  8b3554b1a000           -mov esi, dword ptr [0xa0b154]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 004f8dd0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f8dd2  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f8dd3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004f8dd5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004f8dd7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8dd8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8dda  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004f8ddd  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f8ddf  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004f8de1  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004f8de4  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004f8de6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8de7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f8de8  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f8dea  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f8ded  891550b1a000           -mov dword ptr [0xa0b150], edx
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.edx;
    // 004f8df3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f8df5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f8df7  e84478feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f8dfc  eb38                   -jmp 0x4f8e36
    goto L_0x004f8e36;
L_0x004f8dfe:
    // 004f8dfe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8e00  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8e04  e8b7f70100             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 004f8e09  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f8e0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8e0f  750d                   -jne 0x4f8e1e
    if (!cpu.flags.zf)
    {
        goto L_0x004f8e1e;
    }
    // 004f8e11  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8e16  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8e19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8e1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8e1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8e1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8e1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8e1e:
    // 004f8e1e  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8e24  8d0c18                 -lea ecx, [eax + ebx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004f8e27  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004f8e29  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8e2b  e810f80100             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 004f8e30  890d50b1a000           -mov dword ptr [0xa0b150], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.ecx;
L_0x004f8e36:
    // 004f8e36  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8e3a  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 004f8e41  01d0                   +add eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f8e43  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004f8e4a  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8e4f  891554b1a000           -mov dword ptr [0xa0b154], edx
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.edx;
    // 004f8e55  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
    // 004f8e59  eb0b                   -jmp 0x4f8e66
    goto L_0x004f8e66;
L_0x004f8e5b:
    // 004f8e5b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f8e5d  0f84c8000000           -je 0x4f8f2b
    if (cpu.flags.zf)
    {
        goto L_0x004f8f2b;
    }
    // 004f8e63  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004f8e66:
    // 004f8e66  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8e6a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f8e6b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004f8e6d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004f8e6f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f8e71  49                     -dec ecx
    (cpu.ecx)--;
    // 004f8e72  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f8e74  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f8e76  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f8e78  49                     -dec ecx
    (cpu.ecx)--;
    // 004f8e79  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f8e7a  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8e7f  8a3428                 -mov dh, byte ptr [eax + ebp]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1);
    // 004f8e82  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f8e84  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 004f8e86  7411                   -je 0x4f8e99
    if (cpu.flags.zf)
    {
        goto L_0x004f8e99;
    }
    // 004f8e88  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8e8c  8d34ad00000000         -lea esi, [ebp*4]
    cpu.esi = x86::reg32(cpu.ebp * 4);
    // 004f8e93  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f8e95  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004f8e97  eb02                   -jmp 0x4f8e9b
    goto L_0x004f8e9b;
L_0x004f8e99:
    // 004f8e99  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f8e9b:
    // 004f8e9b  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8e9f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f8ea0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004f8ea2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004f8ea4  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f8ea6  49                     -dec ecx
    (cpu.ecx)--;
    // 004f8ea7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f8ea9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f8eab  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f8ead  49                     -dec ecx
    (cpu.ecx)--;
    // 004f8eae  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f8eaf  8d140b                 -lea edx, [ebx + ecx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ecx * 1);
    // 004f8eb2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f8eb4  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f8eb7  e804f70100             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 004f8ebc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f8ebe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8ec0  750d                   -jne 0x4f8ecf
    if (!cpu.flags.zf)
    {
        goto L_0x004f8ecf;
    }
    // 004f8ec2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f8ec7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8eca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ecb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ecc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ecd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8ece  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f8ecf:
    // 004f8ecf  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8ed3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f8ed5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f8ed7  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f8ed8  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004f8eda  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004f8edc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8edd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8edf  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004f8ee2  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f8ee4  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004f8ee6  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004f8ee9  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004f8eeb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8eec  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f8eed  c6041a3d               -mov byte ptr [edx + ebx], 0x3d
    app->getMemory<x86::reg8>(cpu.edx + cpu.ebx * 1) = 61 /*0x3d*/;
    // 004f8ef1  43                     -inc ebx
    (cpu.ebx)++;
    // 004f8ef2  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8ef6  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004f8ef9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004f8efa:
    // 004f8efa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f8efc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f8efe  3c00                   +cmp al, 0
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
    // 004f8f00  7410                   -je 0x4f8f12
    if (cpu.flags.zf)
    {
        goto L_0x004f8f12;
    }
    // 004f8f02  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f8f05  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f8f08  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f8f0b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f8f0e  3c00                   +cmp al, 0
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
    // 004f8f10  75e8                   -jne 0x4f8efa
    if (!cpu.flags.zf)
    {
        goto L_0x004f8efa;
    }
L_0x004f8f12:
    // 004f8f12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8f13  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8f17  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 004f8f1e  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004f8f20  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004f8f22  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8f27  c6042801               -mov byte ptr [eax + ebp], 1
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 1 /*0x1*/;
L_0x004f8f2b:
    // 004f8f2b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f8f2d:
    // 004f8f2d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f8f30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8f31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8f32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8f33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f8f34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f8f38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f8f38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f8f39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f8f3a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f8f3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f8f3c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f8f3d  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f8f40  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f8f43  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f8f47  a154b1a000             -mov eax, dword ptr [0xa0b154]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 004f8f4c  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f8f50  e9da000000             -jmp 0x4f902f
    goto L_0x004f902f;
L_0x004f8f55:
    // 004f8f55  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
L_0x004f8f58:
    // 004f8f58  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8f5c  80383d                 +cmp byte ptr [eax], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8f5f  0f8593000000           -jne 0x4f8ff8
    if (!cpu.flags.zf)
    {
        goto L_0x004f8ff8;
    }
    // 004f8f65  807d0000               +cmp byte ptr [ebp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8f69  0f8589000000           -jne 0x4f8ff8
    if (!cpu.flags.zf)
    {
        goto L_0x004f8ff8;
    }
    // 004f8f6f  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8f73  2b3554b1a000           -sub esi, dword ptr [0xa0b154]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */)));
    // 004f8f79  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f8f7d  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 004f8f80  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f8f82  0f856b000000           -jne 0x4f8ff3
    if (!cpu.flags.zf)
    {
        goto L_0x004f8ff3;
    }
    // 004f8f88  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8f8c  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004f8f8e  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f8f92  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f8f94  740f                   -je 0x4f8fa5
    if (cpu.flags.zf)
    {
        goto L_0x004f8fa5;
    }
L_0x004f8f96:
    // 004f8f96  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f8f99  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004f8f9b  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f8f9e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f8fa1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f8fa3  75f1                   -jne 0x4f8f96
    if (!cpu.flags.zf)
    {
        goto L_0x004f8f96;
    }
L_0x004f8fa5:
    // 004f8fa5  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8fab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f8fad  7449                   -je 0x4f8ff8
    if (cpu.flags.zf)
    {
        goto L_0x004f8ff8;
    }
    // 004f8faf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f8fb1  803c0600               +cmp byte ptr [esi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f8fb5  7407                   -je 0x4f8fbe
    if (cpu.flags.zf)
    {
        goto L_0x004f8fbe;
    }
    // 004f8fb7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f8fb9  e832eaffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x004f8fbe:
    // 004f8fbe  8b1d54b1a000           -mov ebx, dword ptr [0xa0b154]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 004f8fc4  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004f8fc6  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f8fc8  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 004f8fce  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 004f8fd1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f8fd3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f8fd5  e866f60100             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 004f8fda  890d50b1a000           -mov dword ptr [0xa0b150], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.ecx;
    // 004f8fe0  39fe                   +cmp esi, edi
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
    // 004f8fe2  7d14                   -jge 0x4f8ff8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f8ff8;
    }
    // 004f8fe4  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004f8fe6:
    // 004f8fe6  41                     -inc ecx
    (cpu.ecx)++;
    // 004f8fe7  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004f8fe9  46                     -inc esi
    (cpu.esi)++;
    // 004f8fea  8841ff                 -mov byte ptr [ecx - 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004f8fed  39fe                   +cmp esi, edi
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
    // 004f8fef  7d07                   -jge 0x4f8ff8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f8ff8;
    }
    // 004f8ff1  ebf3                   -jmp 0x4f8fe6
    goto L_0x004f8fe6;
L_0x004f8ff3:
    // 004f8ff3  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f8ff6  eb57                   -jmp 0x4f904f
    goto L_0x004f904f;
L_0x004f8ff8:
    // 004f8ff8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f8ffc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f8ffe  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004f9000  e8db5dffff             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 004f9005  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9007  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9009  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004f900c  e8cf5dffff             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 004f9011  39c2                   +cmp edx, eax
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
    // 004f9013  7515                   -jne 0x4f902a
    if (!cpu.flags.zf)
    {
        goto L_0x004f902a;
    }
    // 004f9015  807d0000               +cmp byte ptr [ebp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f9019  740f                   -je 0x4f902a
    if (cpu.flags.zf)
    {
        goto L_0x004f902a;
    }
    // 004f901b  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f901f  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f9020  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f9021  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004f9025  e92effffff             -jmp 0x4f8f58
    goto L_0x004f8f58;
L_0x004f902a:
    // 004f902a  8344240404             -add dword ptr [esp + 4], 4
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004f902f:
    // 004f902f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9033  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f9035  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f9039  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f903b  0f8514ffffff           -jne 0x4f8f55
    if (!cpu.flags.zf)
    {
        goto L_0x004f8f55;
    }
    // 004f9041  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9045  a154b1a000             -mov eax, dword ptr [0xa0b154]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 004f904a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f904c  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x004f904f:
    // 004f904f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9052  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9053  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9054  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9055  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9056  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9057  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f9060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9060  ff057c715600           -inc dword ptr [0x56717c]
    (app->getMemory<x86::reg32>(x86::reg32(5665148) /* 0x56717c */))++;
    // 004f9066  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f9070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9070  833d0c3d9f0000         +cmp dword ptr [0x9f3d0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435852) /* 0x9f3d0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9077  7509                   -jne 0x4f9082
    if (!cpu.flags.zf)
    {
        goto L_0x004f9082;
    }
    // 004f9079  833d8071560000         +cmp dword ptr [0x567180], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665152) /* 0x567180 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9080  7406                   -je 0x4f9088
    if (cpu.flags.zf)
    {
        goto L_0x004f9088;
    }
L_0x004f9082:
    // 004f9082  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9087  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9088:
    // 004f9088  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f908a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9088(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f9088;
    // 004f9070  833d0c3d9f0000         +cmp dword ptr [0x9f3d0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435852) /* 0x9f3d0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9077  7509                   -jne 0x4f9082
    if (!cpu.flags.zf)
    {
        goto L_0x004f9082;
    }
    // 004f9079  833d8071560000         +cmp dword ptr [0x567180], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665152) /* 0x567180 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9080  7406                   -je 0x4f9088
    if (cpu.flags.zf)
    {
        goto L_0x004f9088;
    }
L_0x004f9082:
    // 004f9082  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9087  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9088:
L_entry_0x004f9088:
    // 004f9088  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f908a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f9090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9090  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9092  a02f3d9f00             -mov al, byte ptr [0x9f3d2f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435887) /* 0x9f3d2f */);
    // 004f9097  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f90a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f90a0  803d303d9f0000         +cmp byte ptr [0x9f3d30], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435888) /* 0x9f3d30 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f90a7  74df                   -je 0x4f9088
    if (cpu.flags.zf)
    {
        return sub_4f9088(app, cpu);
    }
    // 004f90a9  803d053d9f0000         +cmp byte ptr [0x9f3d05], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435845) /* 0x9f3d05 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f90b0  75d6                   -jne 0x4f9088
    if (!cpu.flags.zf)
    {
        return sub_4f9088(app, cpu);
    }
    // 004f90b2  803d043d9f0000         +cmp byte ptr [0x9f3d04], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435844) /* 0x9f3d04 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f90b9  75cd                   -jne 0x4f9088
    if (!cpu.flags.zf)
    {
        return sub_4f9088(app, cpu);
    }
    // 004f90bb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f90c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f90d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f90d0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f90d2  a0323d9f00             -mov al, byte ptr [0x9f3d32]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435890) /* 0x9f3d32 */);
    // 004f90d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f90e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f90e0  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f90e3  833d2850560000         +cmp dword ptr [0x565028], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5656616) /* 0x565028 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f90ea  741c                   -je 0x4f9108
    if (cpu.flags.zf)
    {
        goto L_0x004f9108;
    }
    // 004f90ec  833dcc7d560000         +cmp dword ptr [0x567dcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668300) /* 0x567dcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f90f3  741c                   -je 0x4f9111
    if (cpu.flags.zf)
    {
        goto L_0x004f9111;
    }
    // 004f90f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f90f7  e8d4b5ffff             -call 0x4f46d0
    cpu.esp -= 4;
    sub_4f46d0(app, cpu);
    if (cpu.terminate) return;
    // 004f90fc  e88f1cffff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 004f9101  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f9103  e8f8b5ffff             -call 0x4f4700
    cpu.esp -= 4;
    sub_4f4700(app, cpu);
    if (cpu.terminate) return;
L_0x004f9108:
    // 004f9108  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f910d  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f9110  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9111:
    // 004f9111  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004f9116  e81542ffff             -call 0x4ed330
    cpu.esp -= 4;
    sub_4ed330(app, cpu);
    if (cpu.terminate) return;
    // 004f911b  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f911e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f9120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9120  833d4c3d9f0000         +cmp dword ptr [0x9f3d4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435916) /* 0x9f3d4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9127  0f845bffffff           -je 0x4f9088
    if (cpu.flags.zf)
    {
        return sub_4f9088(app, cpu);
    }
    // 004f912d  833d243d9f0000         +cmp dword ptr [0x9f3d24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9134  0f844effffff           -je 0x4f9088
    if (cpu.flags.zf)
    {
        return sub_4f9088(app, cpu);
    }
    // 004f913a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f913f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9141  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9142  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9143  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9145  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9147  ff1550475300           -call dword ptr [0x534750]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f914d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004f914f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9151  ff1550475300           -call dword ptr [0x534750]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9157  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f915a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f915b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f915c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f915d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f915e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f915e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f915f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9160  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9161  ff1520455300           -call dword ptr [0x534520]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457184) /* 0x534520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9167  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9168  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9169  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f916a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f916a  90                     -nop 
    ;
    // 004f916b  90                     -nop 
    ;
    // 004f916c  e8edffffff             -call 0x4f915e
    cpu.esp -= 4;
    sub_4f915e(app, cpu);
    if (cpu.terminate) return;
    // 004f9171  83f8ff                 +cmp eax, -1
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
    // 004f9174  740b                   -je 0x4f9181
    if (cpu.flags.zf)
    {
        goto L_0x004f9181;
    }
    // 004f9176  a910000000             +test eax, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16 /*0x10*/));
    // 004f917b  7404                   -je 0x4f9181
    if (cpu.flags.zf)
    {
        goto L_0x004f9181;
    }
    // 004f917d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f917f  40                     -inc eax
    (cpu.eax)++;
    // 004f9180  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9181:
    // 004f9181  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9183  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f916c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f916c;
    // 004f916a  90                     -nop 
    ;
    // 004f916b  90                     -nop 
    ;
L_entry_0x004f916c:
    // 004f916c  e8edffffff             -call 0x4f915e
    cpu.esp -= 4;
    sub_4f915e(app, cpu);
    if (cpu.terminate) return;
    // 004f9171  83f8ff                 +cmp eax, -1
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
    // 004f9174  740b                   -je 0x4f9181
    if (cpu.flags.zf)
    {
        goto L_0x004f9181;
    }
    // 004f9176  a910000000             +test eax, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16 /*0x10*/));
    // 004f917b  7404                   -je 0x4f9181
    if (cpu.flags.zf)
    {
        goto L_0x004f9181;
    }
    // 004f917d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f917f  40                     -inc eax
    (cpu.eax)++;
    // 004f9180  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9181:
    // 004f9181  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9183  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9184(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9184  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004f9185  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f9187  81ec44020000           -sub esp, 0x244
    (cpu.esp) -= x86::reg32(x86::sreg32(580 /*0x244*/));
    // 004f918d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f918f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f9191  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f9193  e820020000             -call 0x4f93b8
    cpu.esp -= 4;
    sub_4f93b8(app, cpu);
    if (cpu.terminate) return;
    // 004f9198  66c7072a00             -mov word ptr [edi], 0x2a
    app->getMemory<x86::reg16>(cpu.edi) = 42 /*0x2a*/;
    // 004f919d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004f919f  8dbc2404010000         -lea edi, [esp + 0x104]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f91a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f91a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f91a8  ff15cc445300           -call dword ptr [0x5344cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457100) /* 0x5344cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f91ae  83f8ff                 +cmp eax, -1
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
    // 004f91b1  742e                   -je 0x4f91e1
    if (cpu.flags.zf)
    {
        goto L_0x004f91e1;
    }
    // 004f91b3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004f91b5:
    // 004f91b5  8d472c                 -lea eax, [edi + 0x2c]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(44) /* 0x2c */);
    // 004f91b8  6683382e               +cmp word ptr [eax], 0x2e
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(46 /*0x2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f91bc  740d                   -je 0x4f91cb
    if (cpu.flags.zf)
    {
        goto L_0x004f91cb;
    }
    // 004f91be  6681382e2e             +cmp word ptr [eax], 0x2e2e
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(11822 /*0x2e2e*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f91c3  7514                   -jne 0x4f91d9
    if (!cpu.flags.zf)
    {
        goto L_0x004f91d9;
    }
    // 004f91c5  80780200               +cmp byte ptr [eax + 2], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f91c9  750e                   -jne 0x4f91d9
    if (!cpu.flags.zf)
    {
        goto L_0x004f91d9;
    }
L_0x004f91cb:
    // 004f91cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f91cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f91cd  ff15d0445300           -call dword ptr [0x5344d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457104) /* 0x5344d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f91d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f91d5  75de                   -jne 0x4f91b5
    if (!cpu.flags.zf)
    {
        goto L_0x004f91b5;
    }
    // 004f91d7  eb01                   -jmp 0x4f91da
    goto L_0x004f91da;
L_0x004f91d9:
    // 004f91d9  43                     -inc ebx
    (cpu.ebx)++;
L_0x004f91da:
    // 004f91da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f91db  ff15c8445300           -call dword ptr [0x5344c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f91e1:
    // 004f91e1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004f91e3  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004f91e7  61                     -popal 
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
    // 004f91e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f91ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f91ea  90                     -nop 
    ;
    // 004f91eb  90                     -nop 
    ;
    // 004f91ec  e86dffffff             -call 0x4f915e
    cpu.esp -= 4;
    sub_4f915e(app, cpu);
    if (cpu.terminate) return;
    // 004f91f1  83f8ff                 +cmp eax, -1
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
    // 004f91f4  740b                   -je 0x4f9201
    if (cpu.flags.zf)
    {
        goto L_0x004f9201;
    }
    // 004f91f6  a910000000             +test eax, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16 /*0x10*/));
    // 004f91fb  7504                   -jne 0x4f9201
    if (!cpu.flags.zf)
    {
        goto L_0x004f9201;
    }
    // 004f91fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f91ff  40                     -inc eax
    (cpu.eax)++;
    // 004f9200  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9201:
    // 004f9201  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9203  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f91ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f91ec;
    // 004f91ea  90                     -nop 
    ;
    // 004f91eb  90                     -nop 
    ;
L_entry_0x004f91ec:
    // 004f91ec  e86dffffff             -call 0x4f915e
    cpu.esp -= 4;
    sub_4f915e(app, cpu);
    if (cpu.terminate) return;
    // 004f91f1  83f8ff                 +cmp eax, -1
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
    // 004f91f4  740b                   -je 0x4f9201
    if (cpu.flags.zf)
    {
        goto L_0x004f9201;
    }
    // 004f91f6  a910000000             +test eax, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16 /*0x10*/));
    // 004f91fb  7504                   -jne 0x4f9201
    if (!cpu.flags.zf)
    {
        goto L_0x004f9201;
    }
    // 004f91fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f91ff  40                     -inc eax
    (cpu.eax)++;
    // 004f9200  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9201:
    // 004f9201  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9203  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9204(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9204  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9205  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9206  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9208  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9209  ff1590445300           -call dword ptr [0x534490]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457040) /* 0x534490 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f920f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9210  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9211  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9212(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9212  90                     -nop 
    ;
    // 004f9213  90                     -nop 
    ;
    // 004f9214  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9215  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9217  e850ffffff             -call 0x4f916c
    cpu.esp -= 4;
    sub_4f916c(app, cpu);
    if (cpu.terminate) return;
    // 004f921c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f921e  7507                   -jne 0x4f9227
    if (!cpu.flags.zf)
    {
        goto L_0x004f9227;
    }
    // 004f9220  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f9222  e8ddffffff             -call 0x4f9204
    cpu.esp -= 4;
    sub_4f9204(app, cpu);
    if (cpu.terminate) return;
L_0x004f9227:
    // 004f9227  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9228  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9214(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f9214;
    // 004f9212  90                     -nop 
    ;
    // 004f9213  90                     -nop 
    ;
L_entry_0x004f9214:
    // 004f9214  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9215  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9217  e850ffffff             -call 0x4f916c
    cpu.esp -= 4;
    sub_4f916c(app, cpu);
    if (cpu.terminate) return;
    // 004f921c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f921e  7507                   -jne 0x4f9227
    if (!cpu.flags.zf)
    {
        goto L_0x004f9227;
    }
    // 004f9220  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f9222  e8ddffffff             -call 0x4f9204
    cpu.esp -= 4;
    sub_4f9204(app, cpu);
    if (cpu.terminate) return;
L_0x004f9227:
    // 004f9227  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9228  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f922a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f922a  90                     -nop 
    ;
    // 004f922b  90                     -nop 
    ;
    // 004f922c  90                     -nop 
    ;
    // 004f922d  90                     -nop 
    ;
    // 004f922e  90                     -nop 
    ;
    // 004f922f  90                     -nop 
    ;
    // 004f9230  90                     -nop 
    ;
    // 004f9231  90                     -nop 
    ;
    // 004f9232  90                     -nop 
    ;
    // 004f9233  90                     -nop 
    ;
    // 004f9234  90                     -nop 
    ;
    // 004f9235  90                     -nop 
    ;
    // 004f9236  90                     -nop 
    ;
    // 004f9237  90                     -nop 
    ;
    // 004f9238  90                     -nop 
    ;
    // 004f9239  90                     -nop 
    ;
    // 004f923a  90                     -nop 
    ;
    // 004f923b  90                     -nop 
    ;
    // 004f923c  90                     -nop 
    ;
    // 004f923d  90                     -nop 
    ;
    // 004f923e  90                     -nop 
    ;
    // 004f923f  90                     -nop 
    ;
    // 004f9240  90                     -nop 
    ;
    // 004f9241  90                     -nop 
    ;
    // 004f9242  90                     -nop 
    ;
    // 004f9243  90                     -nop 
    ;
    // 004f9244  90                     -nop 
    ;
    // 004f9245  90                     -nop 
    ;
    // 004f9246  90                     -nop 
    ;
    // 004f9247  90                     -nop 
    ;
    // 004f9248  90                     -nop 
    ;
    // 004f9249  90                     -nop 
    ;
    // 004f924a  90                     -nop 
    ;
    // 004f924b  90                     -nop 
    ;
    // 004f924c  90                     -nop 
    ;
    // 004f924d  90                     -nop 
    ;
    // 004f924e  90                     -nop 
    ;
    // 004f924f  90                     -nop 
    ;
    // 004f9250  90                     -nop 
    ;
    // 004f9251  90                     -nop 
    ;
    // 004f9252  90                     -nop 
    ;
    // 004f9253  90                     -nop 
    ;
    // 004f9254  90                     -nop 
    ;
    // 004f9255  90                     -nop 
    ;
    // 004f9256  90                     -nop 
    ;
    // 004f9257  90                     -nop 
    ;
    // 004f9258  90                     -nop 
    ;
    // 004f9259  90                     -nop 
    ;
    // 004f925a  90                     -nop 
    ;
    // 004f925b  90                     -nop 
    ;
    // 004f925c  90                     -nop 
    ;
    // 004f925d  90                     -nop 
    ;
    // 004f925e  90                     -nop 
    ;
    // 004f925f  90                     -nop 
    ;
    // 004f9260  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9262  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f9260;
    // 004f922a  90                     -nop 
    ;
    // 004f922b  90                     -nop 
    ;
    // 004f922c  90                     -nop 
    ;
    // 004f922d  90                     -nop 
    ;
    // 004f922e  90                     -nop 
    ;
    // 004f922f  90                     -nop 
    ;
    // 004f9230  90                     -nop 
    ;
    // 004f9231  90                     -nop 
    ;
    // 004f9232  90                     -nop 
    ;
    // 004f9233  90                     -nop 
    ;
    // 004f9234  90                     -nop 
    ;
    // 004f9235  90                     -nop 
    ;
    // 004f9236  90                     -nop 
    ;
    // 004f9237  90                     -nop 
    ;
    // 004f9238  90                     -nop 
    ;
    // 004f9239  90                     -nop 
    ;
    // 004f923a  90                     -nop 
    ;
    // 004f923b  90                     -nop 
    ;
    // 004f923c  90                     -nop 
    ;
    // 004f923d  90                     -nop 
    ;
    // 004f923e  90                     -nop 
    ;
    // 004f923f  90                     -nop 
    ;
    // 004f9240  90                     -nop 
    ;
    // 004f9241  90                     -nop 
    ;
    // 004f9242  90                     -nop 
    ;
    // 004f9243  90                     -nop 
    ;
    // 004f9244  90                     -nop 
    ;
    // 004f9245  90                     -nop 
    ;
    // 004f9246  90                     -nop 
    ;
    // 004f9247  90                     -nop 
    ;
    // 004f9248  90                     -nop 
    ;
    // 004f9249  90                     -nop 
    ;
    // 004f924a  90                     -nop 
    ;
    // 004f924b  90                     -nop 
    ;
    // 004f924c  90                     -nop 
    ;
    // 004f924d  90                     -nop 
    ;
    // 004f924e  90                     -nop 
    ;
    // 004f924f  90                     -nop 
    ;
    // 004f9250  90                     -nop 
    ;
    // 004f9251  90                     -nop 
    ;
    // 004f9252  90                     -nop 
    ;
    // 004f9253  90                     -nop 
    ;
    // 004f9254  90                     -nop 
    ;
    // 004f9255  90                     -nop 
    ;
    // 004f9256  90                     -nop 
    ;
    // 004f9257  90                     -nop 
    ;
    // 004f9258  90                     -nop 
    ;
    // 004f9259  90                     -nop 
    ;
    // 004f925a  90                     -nop 
    ;
    // 004f925b  90                     -nop 
    ;
    // 004f925c  90                     -nop 
    ;
    // 004f925d  90                     -nop 
    ;
    // 004f925e  90                     -nop 
    ;
    // 004f925f  90                     -nop 
    ;
L_entry_0x004f9260:
    // 004f9260  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9262  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f9270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9271  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9272  6860924f00             -push 0x4f9260
    app->getMemory<x86::reg32>(cpu.esp-4) = 5214816 /*0x4f9260*/;
    cpu.esp -= 4;
    // 004f9277  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9279  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f927b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f927d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f927f  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004f9281  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004f9283  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f9285  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9287  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004f9289  ba68045400             -mov edx, 0x540468
    cpu.edx = 5506152 /*0x540468*/;
    // 004f928e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9290  e89b7ffeff             -call 0x4e1230
    cpu.esp -= 4;
    sub_4e1230(app, cpu);
    if (cpu.terminate) return;
    // 004f9295  8b15c0f59e00           -mov edx, dword ptr [0x9ef5c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */);
    // 004f929b  8915c4f59e00           -mov dword ptr [0x9ef5c4], edx
    app->getMemory<x86::reg32>(x86::reg32(10417604) /* 0x9ef5c4 */) = cpu.edx;
    // 004f92a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f92b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f92b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f92b3  e848e6ffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f92b8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f92ba  a3fc445600             -mov dword ptr [0x5644fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653756) /* 0x5644fc */) = cpu.eax;
    // 004f92bf  e8acffffff             -call 0x4f9270
    cpu.esp -= 4;
    sub_4f9270(app, cpu);
    if (cpu.terminate) return;
    // 004f92c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f92d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f92d1  a160277a00             -mov eax, dword ptr [0x7a2760]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8005472) /* 0x7a2760 */);
    // 004f92d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f92d8  e8d3ffffff             -call 0x4f92b0
    cpu.esp -= 4;
    sub_4f92b0(app, cpu);
    if (cpu.terminate) return;
    // 004f92dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f92e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f92e1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f92e3  e8c8ffffff             -call 0x4f92b0
    cpu.esp -= 4;
    sub_4f92b0(app, cpu);
    if (cpu.terminate) return;
    // 004f92e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f92f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f92f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f92f1  8b15fc445600           -mov edx, dword ptr [0x5644fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653756) /* 0x5644fc */);
    // 004f92f7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f92f9  7502                   -jne 0x4f92fd
    if (!cpu.flags.zf)
    {
        goto L_0x004f92fd;
    }
    // 004f92fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f92fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f92fd:
    // 004f92fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f92fe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f9300  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f9302  e8e9e6ffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004f9307  890dfc445600           -mov dword ptr [0x5644fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653756) /* 0x5644fc */) = cpu.ecx;
    // 004f930d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f930e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f930f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9310  a38c715600             -mov dword ptr [0x56718c], eax
    app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */) = cpu.eax;
    // 004f9315  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f9320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9320  833d9471560000         +cmp dword ptr [0x567194], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9327  7401                   -je 0x4f932a
    if (cpu.flags.zf)
    {
        goto L_0x004f932a;
    }
    // 004f9329  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f932a:
    // 004f932a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f932b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f932d  e89efc0100             -call 0x518fd0
    cpu.esp -= 4;
    sub_518fd0(app, cpu);
    if (cpu.terminate) return;
    // 004f9332  b864905600             -mov eax, 0x569064
    cpu.eax = 5673060 /*0x569064*/;
    // 004f9337  e8d40b0200             -call 0x519f10
    cpu.esp -= 4;
    sub_519f10(app, cpu);
    if (cpu.terminate) return;
    // 004f933c  a390715600             -mov dword ptr [0x567190], eax
    app->getMemory<x86::reg32>(x86::reg32(5665168) /* 0x567190 */) = cpu.eax;
    // 004f9341  b860934f00             -mov eax, 0x4f9360
    cpu.eax = 5215072 /*0x4f9360*/;
    // 004f9346  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f934b  e82897ffff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 004f9350  890d94715600           -mov dword ptr [0x567194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */) = cpu.ecx;
    // 004f9356  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9357  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9360  833d9471560000         +cmp dword ptr [0x567194], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9367  7501                   -jne 0x4f936a
    if (!cpu.flags.zf)
    {
        goto L_0x004f936a;
    }
    // 004f9369  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f936a:
    // 004f936a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f936b  a190715600             -mov eax, dword ptr [0x567190]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665168) /* 0x567190 */);
    // 004f9370  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f9372  e8f90d0200             -call 0x51a170
    cpu.esp -= 4;
    sub_51a170(app, cpu);
    if (cpu.terminate) return;
    // 004f9377  890d90715600           -mov dword ptr [0x567190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665168) /* 0x567190 */) = cpu.ecx;
    // 004f937d  e8befd0100             -call 0x519140
    cpu.esp -= 4;
    sub_519140(app, cpu);
    if (cpu.terminate) return;
    // 004f9382  890d94715600           -mov dword ptr [0x567194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665172) /* 0x567194 */) = cpu.ecx;
    // 004f9388  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9389  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f9390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9390  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9391  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004f9394  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f9397  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9398  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f939a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f939a  90                     -nop 
    ;
    // 004f939b  90                     -nop 
    ;
    // 004f939c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f939d  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004f93a0  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004f93a3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f939c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f939c;
    // 004f939a  90                     -nop 
    ;
    // 004f939b  90                     -nop 
    ;
L_entry_0x004f939c:
    // 004f939c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f939d  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004f93a0  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004f93a3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f93a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93a6  90                     -nop 
    ;
    // 004f93a7  90                     -nop 
    ;
    // 004f93a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f93a9  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004f93ae  e8394d0200             -call 0x51e0ec
    cpu.esp -= 4;
    sub_51e0ec(app, cpu);
    if (cpu.terminate) return;
    // 004f93b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f93a8;
    // 004f93a6  90                     -nop 
    ;
    // 004f93a7  90                     -nop 
    ;
L_entry_0x004f93a8:
    // 004f93a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f93a9  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004f93ae  e8394d0200             -call 0x51e0ec
    cpu.esp -= 4;
    sub_51e0ec(app, cpu);
    if (cpu.terminate) return;
    // 004f93b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f93b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93b6  90                     -nop 
    ;
    // 004f93b7  90                     -nop 
    ;
    // 004f93b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93bb:
    // 004f93bb  ac                     -lodsb al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 1;
    }
    else
    {
        cpu.esi += 1;
    }
    // 004f93bc  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93bd  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93bf  75fa                   -jne 0x4f93bb
    if (!cpu.flags.zf)
    {
        goto L_0x004f93bb;
    }
    // 004f93c1  4e                     -dec esi
    (cpu.esi)--;
    // 004f93c2  4f                     -dec edi
    (cpu.edi)--;
    // 004f93c3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f93b8;
    // 004f93b6  90                     -nop 
    ;
    // 004f93b7  90                     -nop 
    ;
L_entry_0x004f93b8:
    // 004f93b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93bb:
    // 004f93bb  ac                     -lodsb al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 1;
    }
    else
    {
        cpu.esi += 1;
    }
    // 004f93bc  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93bd  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93bf  75fa                   -jne 0x4f93bb
    if (!cpu.flags.zf)
    {
        goto L_0x004f93bb;
    }
    // 004f93c1  4e                     -dec esi
    (cpu.esi)--;
    // 004f93c2  4f                     -dec edi
    (cpu.edi)--;
    // 004f93c3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f93c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93c6  90                     -nop 
    ;
    // 004f93c7  90                     -nop 
    ;
    // 004f93c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93cb:
    // 004f93cb  ac                     -lodsb al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 1;
    }
    else
    {
        cpu.esi += 1;
    }
    // 004f93cc  e80f77ffff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 004f93d1  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93d2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93d4  75f5                   -jne 0x4f93cb
    if (!cpu.flags.zf)
    {
        goto L_0x004f93cb;
    }
    // 004f93d6  4e                     -dec esi
    (cpu.esi)--;
    // 004f93d7  4f                     -dec edi
    (cpu.edi)--;
    // 004f93d8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f93c8;
    // 004f93c6  90                     -nop 
    ;
    // 004f93c7  90                     -nop 
    ;
L_entry_0x004f93c8:
    // 004f93c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93cb:
    // 004f93cb  ac                     -lodsb al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 1;
    }
    else
    {
        cpu.esi += 1;
    }
    // 004f93cc  e80f77ffff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 004f93d1  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93d2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93d4  75f5                   -jne 0x4f93cb
    if (!cpu.flags.zf)
    {
        goto L_0x004f93cb;
    }
    // 004f93d6  4e                     -dec esi
    (cpu.esi)--;
    // 004f93d7  4f                     -dec edi
    (cpu.edi)--;
    // 004f93d8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93da  90                     -nop 
    ;
    // 004f93db  90                     -nop 
    ;
    // 004f93dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f93dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f93de  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f93e0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f93e2  e8e1ffffff             -call 0x4f93c8
    cpu.esp -= 4;
    sub_4f93c8(app, cpu);
    if (cpu.terminate) return;
    // 004f93e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f93dc;
    // 004f93da  90                     -nop 
    ;
    // 004f93db  90                     -nop 
    ;
L_entry_0x004f93dc:
    // 004f93dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f93dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f93de  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f93e0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f93e2  e8e1ffffff             -call 0x4f93c8
    cpu.esp -= 4;
    sub_4f93c8(app, cpu);
    if (cpu.terminate) return;
    // 004f93e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93ea  90                     -nop 
    ;
    // 004f93eb  90                     -nop 
    ;
    // 004f93ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93ef:
    // 004f93ef  e30b                   -jecxz 0x4f93fc
    if (cpu.ecx == 0)
    {
        goto L_0x004f93fc;
    }
    // 004f93f1  ac                     -lodsb al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 1;
    }
    else
    {
        cpu.esi += 1;
    }
    // 004f93f2  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93f3  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93f5  7403                   -je 0x4f93fa
    if (cpu.flags.zf)
    {
        goto L_0x004f93fa;
    }
    // 004f93f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f93f8  ebf5                   -jmp 0x4f93ef
    goto L_0x004f93ef;
L_0x004f93fa:
    // 004f93fa  4e                     -dec esi
    (cpu.esi)--;
    // 004f93fb  4f                     -dec edi
    (cpu.edi)--;
L_0x004f93fc:
    // 004f93fc  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f93ec;
    // 004f93ea  90                     -nop 
    ;
    // 004f93eb  90                     -nop 
    ;
L_entry_0x004f93ec:
    // 004f93ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f93ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f93ef:
    // 004f93ef  e30b                   -jecxz 0x4f93fc
    if (cpu.ecx == 0)
    {
        goto L_0x004f93fc;
    }
    // 004f93f1  ac                     -lodsb al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 1;
    }
    else
    {
        cpu.esi += 1;
    }
    // 004f93f2  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f93f3  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f93f5  7403                   -je 0x4f93fa
    if (cpu.flags.zf)
    {
        goto L_0x004f93fa;
    }
    // 004f93f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f93f8  ebf5                   -jmp 0x4f93ef
    goto L_0x004f93ef;
L_0x004f93fa:
    // 004f93fa  4e                     -dec esi
    (cpu.esi)--;
    // 004f93fb  4f                     -dec edi
    (cpu.edi)--;
L_0x004f93fc:
    // 004f93fc  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f93fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f93fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f93fe  90                     -nop 
    ;
    // 004f93ff  90                     -nop 
    ;
    // 004f9400  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9401  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f9403:
    // 004f9403  e310                   -jecxz 0x4f9415
    if (cpu.ecx == 0)
    {
        goto L_0x004f9415;
    }
    // 004f9405  ac                     -lodsb al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 1;
    }
    else
    {
        cpu.esi += 1;
    }
    // 004f9406  e8d576ffff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 004f940b  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f940c  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f940e  7403                   -je 0x4f9413
    if (cpu.flags.zf)
    {
        goto L_0x004f9413;
    }
    // 004f9410  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f9411  ebf0                   -jmp 0x4f9403
    goto L_0x004f9403;
L_0x004f9413:
    // 004f9413  4e                     -dec esi
    (cpu.esi)--;
    // 004f9414  4f                     -dec edi
    (cpu.edi)--;
L_0x004f9415:
    // 004f9415  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9416  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f9400;
    // 004f93fe  90                     -nop 
    ;
    // 004f93ff  90                     -nop 
    ;
L_entry_0x004f9400:
    // 004f9400  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9401  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f9403:
    // 004f9403  e310                   -jecxz 0x4f9415
    if (cpu.ecx == 0)
    {
        goto L_0x004f9415;
    }
    // 004f9405  ac                     -lodsb al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 1;
    }
    else
    {
        cpu.esi += 1;
    }
    // 004f9406  e8d576ffff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 004f940b  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f940c  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f940e  7403                   -je 0x4f9413
    if (cpu.flags.zf)
    {
        goto L_0x004f9413;
    }
    // 004f9410  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f9411  ebf0                   -jmp 0x4f9403
    goto L_0x004f9403;
L_0x004f9413:
    // 004f9413  4e                     -dec esi
    (cpu.esi)--;
    // 004f9414  4f                     -dec edi
    (cpu.edi)--;
L_0x004f9415:
    // 004f9415  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9416  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f9418(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9418  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9419  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f941a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f941b  e8e0ffffff             -call 0x4f9400
    cpu.esp -= 4;
    sub_4f9400(app, cpu);
    if (cpu.terminate) return;
    // 004f9420  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9421  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9422  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9423  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9424(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9424  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9425  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f9427:
    // 004f9427  e310                   -jecxz 0x4f9439
    if (cpu.ecx == 0)
    {
        goto L_0x004f9439;
    }
    // 004f9429  ac                     -lodsb al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 1;
    }
    else
    {
        cpu.esi += 1;
    }
    // 004f942a  e8b159ffff             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 004f942f  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004f9430  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004f9432  7403                   -je 0x4f9437
    if (cpu.flags.zf)
    {
        goto L_0x004f9437;
    }
    // 004f9434  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f9435  ebf0                   -jmp 0x4f9427
    goto L_0x004f9427;
L_0x004f9437:
    // 004f9437  4e                     -dec esi
    (cpu.esi)--;
    // 004f9438  4f                     -dec edi
    (cpu.edi)--;
L_0x004f9439:
    // 004f9439  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f943a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f943c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f943c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f943d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f943e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f943f  e8e0ffffff             -call 0x4f9424
    cpu.esp -= 4;
    sub_4f9424(app, cpu);
    if (cpu.terminate) return;
    // 004f9444  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9445  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9446  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9447  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9448(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004f9448:
    // 004f9448  803f00                 +cmp byte ptr [edi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f944b  7403                   -je 0x4f9450
    if (cpu.flags.zf)
    {
        goto L_0x004f9450;
    }
    // 004f944d  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f944e  ebf8                   -jmp 0x4f9448
    goto L_0x004f9448;
L_0x004f9450:
    // 004f9450  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f9452(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9452  90                     -nop 
    ;
    // 004f9453  90                     -nop 
    ;
    // 004f9454  90                     -nop 
    ;
    // 004f9455  90                     -nop 
    ;
    // 004f9456  90                     -nop 
    ;
    // 004f9457  90                     -nop 
    ;
    // 004f9458  90                     -nop 
    ;
    // 004f9459  90                     -nop 
    ;
    // 004f945a  90                     -nop 
    ;
    // 004f945b  90                     -nop 
    ;
    // 004f945c  90                     -nop 
    ;
    // 004f945d  90                     -nop 
    ;
    // 004f945e  90                     -nop 
    ;
    // 004f945f  90                     -nop 
    ;
    // 004f9460  90                     -nop 
    ;
    // 004f9461  90                     -nop 
    ;
    // 004f9462  90                     -nop 
    ;
    // 004f9463  90                     -nop 
    ;
    // 004f9464  90                     -nop 
    ;
    // 004f9465  90                     -nop 
    ;
    // 004f9466  90                     -nop 
    ;
    // 004f9467  90                     -nop 
    ;
    // 004f9468  90                     -nop 
    ;
    // 004f9469  90                     -nop 
    ;
    // 004f946a  90                     -nop 
    ;
    // 004f946b  90                     -nop 
    ;
    // 004f946c  90                     -nop 
    ;
    // 004f946d  90                     -nop 
    ;
    // 004f946e  90                     -nop 
    ;
    // 004f946f  90                     -nop 
    ;
    // 004f9470  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9472  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004f9478  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004f947e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004f9480  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f9470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f9470;
    // 004f9452  90                     -nop 
    ;
    // 004f9453  90                     -nop 
    ;
    // 004f9454  90                     -nop 
    ;
    // 004f9455  90                     -nop 
    ;
    // 004f9456  90                     -nop 
    ;
    // 004f9457  90                     -nop 
    ;
    // 004f9458  90                     -nop 
    ;
    // 004f9459  90                     -nop 
    ;
    // 004f945a  90                     -nop 
    ;
    // 004f945b  90                     -nop 
    ;
    // 004f945c  90                     -nop 
    ;
    // 004f945d  90                     -nop 
    ;
    // 004f945e  90                     -nop 
    ;
    // 004f945f  90                     -nop 
    ;
    // 004f9460  90                     -nop 
    ;
    // 004f9461  90                     -nop 
    ;
    // 004f9462  90                     -nop 
    ;
    // 004f9463  90                     -nop 
    ;
    // 004f9464  90                     -nop 
    ;
    // 004f9465  90                     -nop 
    ;
    // 004f9466  90                     -nop 
    ;
    // 004f9467  90                     -nop 
    ;
    // 004f9468  90                     -nop 
    ;
    // 004f9469  90                     -nop 
    ;
    // 004f946a  90                     -nop 
    ;
    // 004f946b  90                     -nop 
    ;
    // 004f946c  90                     -nop 
    ;
    // 004f946d  90                     -nop 
    ;
    // 004f946e  90                     -nop 
    ;
    // 004f946f  90                     -nop 
    ;
L_entry_0x004f9470:
    // 004f9470  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9472  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004f9478  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004f947e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004f9480  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f9482(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9482  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 004f9484  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004f9486  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 004f9488  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004f948a  dee1                   +fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004f948c  d9e4                   +ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 004f948e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004f9490  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f9491  750f                   -jne 0x4f94a2
    if (!cpu.flags.zf)
    {
        goto L_0x004f94a2;
    }
    // 004f9493  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004f9495  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004f9497  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f9498  7704                   -ja 0x4f949e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f949e;
    }
    // 004f949a  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004f949c  eb02                   -jmp 0x4f94a0
    goto L_0x004f94a0;
L_0x004f949e:
    // 004f949e  d9eb                   +fldpi 
    cpu.fpu.push(3.1415926535897932);
L_0x004f94a0:
    // 004f94a0  eb1a                   -jmp 0x4f94bc
    goto L_0x004f94bc;
L_0x004f94a2:
    // 004f94a2  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004f94a4  e8110d0200             -call 0x51a1ba
    cpu.esp -= 4;
    sub_51a1ba(app, cpu);
    if (cpu.terminate) return;
    // 004f94a9  3c00                   +cmp al, 0
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
    // 004f94ab  750f                   -jne 0x4f94bc
    if (!cpu.flags.zf)
    {
        goto L_0x004f94bc;
    }
    // 004f94ad  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004f94af  e82572feff             -call 0x4e06d9
    cpu.esp -= 4;
    sub_4e06d9(app, cpu);
    if (cpu.terminate) return;
    // 004f94b4  db2d9c715600           -fld xword ptr [0x56719c]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5665180) /* 0x56719c */)));
    // 004f94ba  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
L_0x004f94bc:
    // 004f94bc  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f94be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f94bf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f94bf  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004f94c3  e8baffffff             -call 0x4f9482
    cpu.esp -= 4;
    sub_4f9482(app, cpu);
    if (cpu.terminate) return;
    // 004f94c8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f9500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004f9500  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9501  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9503  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9506  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004f950a  8b5c2468               -mov ebx, dword ptr [esp + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004f950e  8b74246c               -mov esi, dword ptr [esp + 0x6c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004f9512  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004f9516  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004f9519  83fa0b                 +cmp edx, 0xb
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
    // 004f951c  0f8762020000           -ja 0x4f9784
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f9784;
    }
    // 004f9522  ff2495d0944f00         -jmp dword ptr [edx*4 + 0x4f94d0]
    cpu.ip = app->getMemory<x86::reg32>(5215440 + cpu.edx * 4); goto dynamic_jump;
  case 0x004f9529:
    // 004f9529  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f952a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f952b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f952c  b898d95400             -mov eax, 0x54d998
    cpu.eax = 5560728 /*0x54d998*/;
    // 004f9531  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9532  b8ac4d9f00             -mov eax, 0x9f4dac
    cpu.eax = 10440108 /*0x9f4dac*/;
    // 004f9537  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9538  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f953f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f9542  beac4d9f00             -mov esi, 0x9f4dac
    cpu.esi = 10440108 /*0x9f4dac*/;
    // 004f9547  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9548  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f954a  b854445600             -mov eax, 0x564454
    cpu.eax = 5653588 /*0x564454*/;
    // 004f954f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9550  8935b4ab5600           -mov dword ptr [0x56abb4], esi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.esi;
    // 004f9556  e8f57a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f955b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f955e:
    // 004f955e  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9561  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9562  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9563  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9564  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f9567:
    // 004f9567  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9568  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9569  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f956a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f956b  6834d95400             -push 0x54d934
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560628 /*0x54d934*/;
    cpu.esp -= 4;
    // 004f9570  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f9575  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f957c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f957f  bfac4d9f00             -mov edi, 0x9f4dac
    cpu.edi = 10440108 /*0x9f4dac*/;
    // 004f9584  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9585  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9587  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f958c  893db4ab5600           -mov dword ptr [0x56abb4], edi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edi;
    // 004f9592  e8b97a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9597  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f959a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f959e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f959f  8b2da04d9f00           -mov ebp, dword ptr [0x9f4da0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f95a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f95a6  e8a2750300             -call 0x530b4d
    cpu.esp -= 4;
    sub_530b4d(app, cpu);
    if (cpu.terminate) return;
    // 004f95ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95ac  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f95af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f95b2  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f95b5:
    // 004f95b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f95b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f95b7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f95b8  6868d95400             -push 0x54d968
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560680 /*0x54d968*/;
    cpu.esp -= 4;
    // 004f95bd  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f95c2  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f95c9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f95cc  b9ac4d9f00             -mov ecx, 0x9f4dac
    cpu.ecx = 10440108 /*0x9f4dac*/;
    // 004f95d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f95d2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f95d4  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f95d9  890db4ab5600           -mov dword ptr [0x56abb4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.ecx;
    // 004f95df  e86c7a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f95e4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f95e7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f95e9  0f846fffffff           -je 0x4f955e
    if (cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f95ef  c7059c4d9f000f000000   -mov dword ptr [0x9f4d9c], 0xf
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 15 /*0xf*/;
    // 004f95f9  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f9603  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9606  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9607  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9608  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9609  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f960c:
    // 004f960c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f960d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f960e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f960f  68ccd95400             -push 0x54d9cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560780 /*0x54d9cc*/;
    cpu.esp -= 4;
    // 004f9614  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f9619  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9620  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f9623  b8ac4d9f00             -mov eax, 0x9f4dac
    cpu.eax = 10440108 /*0x9f4dac*/;
    // 004f9628  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9629  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f962b  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9630  a3b4ab5600             -mov dword ptr [0x56abb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.eax;
    // 004f9635  e8167a0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f963a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f963d  83fb10                 +cmp ebx, 0x10
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9640  732d                   -jae 0x4f966f
    if (!cpu.flags.cf)
    {
        goto L_0x004f966f;
    }
    // 004f9642  83fb02                 +cmp ebx, 2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9645  0f83a4000000           -jae 0x4f96ef
    if (!cpu.flags.cf)
    {
        goto L_0x004f96ef;
    }
    // 004f964b  83fb01                 +cmp ebx, 1
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
    // 004f964e  0f850affffff           -jne 0x4f955e
    if (!cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f9654  8b0da44d9f00           -mov ecx, dword ptr [0x9f4da4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004f965a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f965b  e809630300             -call 0x52f969
    cpu.esp -= 4;
    sub_52f969(app, cpu);
    if (cpu.terminate) return;
    // 004f9660  891d984d9f00           -mov dword ptr [0x9f4d98], ebx
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = cpu.ebx;
    // 004f9666  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f9669  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f966a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f966b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f966c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f966f:
    // 004f966f  0f86e9feffff           -jbe 0x4f955e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f9675  81fb80000000           +cmp ebx, 0x80
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f967b  7326                   -jae 0x4f96a3
    if (!cpu.flags.cf)
    {
        goto L_0x004f96a3;
    }
    // 004f967d  83fb40                 +cmp ebx, 0x40
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9680  0f85d8feffff           -jne 0x4f955e
    if (!cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
L_0x004f9686:
    // 004f9686  c7059c4d9f000c000000   -mov dword ptr [0x9f4d9c], 0xc
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 12 /*0xc*/;
    // 004f9690  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f969a  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f969d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f969e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f969f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96a0  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f96a3:
    // 004f96a3  0f86b5feffff           -jbe 0x4f955e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f96a9  81fb00010000           +cmp ebx, 0x100
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f96af  0f82a9feffff           -jb 0x4f955e
    if (cpu.flags.cf)
    {
        goto L_0x004f955e;
    }
    // 004f96b5  765e                   -jbe 0x4f9715
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9715;
    }
    // 004f96b7  81fb00400000           +cmp ebx, 0x4000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f96bd  0f859bfeffff           -jne 0x4f955e
    if (!cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f96c3  83fe08                 +cmp esi, 8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f96c6  7370                   -jae 0x4f9738
    if (!cpu.flags.cf)
    {
        goto L_0x004f9738;
    }
    // 004f96c8  83fe01                 +cmp esi, 1
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
    // 004f96cb  7205                   -jb 0x4f96d2
    if (cpu.flags.cf)
    {
        goto L_0x004f96d2;
    }
    // 004f96cd  7603                   -jbe 0x4f96d2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f96d2;
    }
    // 004f96cf  83fe02                 -cmp esi, 2
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
L_0x004f96d2:
    // 004f96d2  c7059c4d9f000b000000   -mov dword ptr [0x9f4d9c], 0xb
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 11 /*0xb*/;
    // 004f96dc  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f96e6  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f96e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f96ec  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f96ef:
    // 004f96ef  0f8769feffff           -ja 0x4f955e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f955e;
    }
    // 004f96f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f96f7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f96f9  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004f96fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f96fe  e8325e0300             -call 0x52f535
    cpu.esp -= 4;
    sub_52f535(app, cpu);
    if (cpu.terminate) return;
    // 004f9703  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004f9707  a3a44d9f00             -mov dword ptr [0x9f4da4], eax
    app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */) = cpu.eax;
    // 004f970c  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f970f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9710  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9711  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9712  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f9715:
    // 004f9715  be09000000             -mov esi, 9
    cpu.esi = 9 /*0x9*/;
    // 004f971a  e8d1090000             -call 0x4fa0f0
    cpu.esp -= 4;
    sub_4fa0f0(app, cpu);
    if (cpu.terminate) return;
    // 004f971f  89359c4d9f00           -mov dword ptr [0x9f4d9c], esi
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.esi;
    // 004f9725  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f972f  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f9732  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9733  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9734  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9735  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f9738:
    // 004f9738  762d                   -jbe 0x4f9767
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9767;
    }
    // 004f973a  83fe20                 +cmp esi, 0x20
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f973d  7293                   -jb 0x4f96d2
    if (cpu.flags.cf)
    {
        goto L_0x004f96d2;
    }
    // 004f973f  0f8641ffffff           -jbe 0x4f9686
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9686;
    }
    // 004f9745  83fe40                 +cmp esi, 0x40
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9748  7588                   -jne 0x4f96d2
    if (!cpu.flags.zf)
    {
        goto L_0x004f96d2;
    }
    // 004f974a  c7059c4d9f000d000000   -mov dword ptr [0x9f4d9c], 0xd
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 13 /*0xd*/;
    // 004f9754  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f975e  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f9761  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9762  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9763  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9764  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004f9767:
    // 004f9767  c7059c4d9f000e000000   -mov dword ptr [0x9f4d9c], 0xe
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 14 /*0xe*/;
    // 004f9771  c705984d9f0001000000   -mov dword ptr [0x9f4d98], 1
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = 1 /*0x1*/;
    // 004f977b  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f977e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f977f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9780  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9781  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004f9784:
L_0x004f9784:
    // 004f9784  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9785  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9786  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9787  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9788  6800da5400             -push 0x54da00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560832 /*0x54da00*/;
    cpu.esp -= 4;
    // 004f978d  68ac4d9f00             -push 0x9f4dac
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440108 /*0x9f4dac*/;
    cpu.esp -= 4;
    // 004f9792  2eff15b0475300         -call dword ptr cs:[0x5347b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457840) /* 0x5347b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9799  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f979c  baac4d9f00             -mov edx, 0x9f4dac
    cpu.edx = 10440108 /*0x9f4dac*/;
    // 004f97a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f97a2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f97a4  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f97a9  8915b4ab5600           -mov dword ptr [0x56abb4], edx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edx;
    // 004f97af  e89c780000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f97b4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f97b7  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f97ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f97bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f97bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f97bd  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip  */
void Application::sub_4f97c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f97c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f97c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f97c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f97c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f97c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f97c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f97c6  b8e8030000             -mov eax, 0x3e8
    cpu.eax = 1000 /*0x3e8*/;
    // 004f97cb  e81061feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f97d0  8b15a44d9f00           -mov edx, dword ptr [0x9f4da4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004f97d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f97d8  0f85d5000000           -jne 0x4f98b3
    if (!cpu.flags.zf)
    {
        goto L_0x004f98b3;
    }
L_0x004f97de:
    // 004f97de  8b1da04d9f00           -mov ebx, dword ptr [0x9f4da0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f97e4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f97e6  7425                   -je 0x4f980d
    if (cpu.flags.zf)
    {
        goto L_0x004f980d;
    }
    // 004f97e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f97e9  e8735e0300             -call 0x52f661
    cpu.esp -= 4;
    sub_52f661(app, cpu);
    if (cpu.terminate) return;
    // 004f97ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f97f0  741b                   -je 0x4f980d
    if (cpu.flags.zf)
    {
        goto L_0x004f980d;
    }
    // 004f97f2  bf3cda5400             -mov edi, 0x54da3c
    cpu.edi = 5560892 /*0x54da3c*/;
    // 004f97f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f97f8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f97fa  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f97ff  893db4ab5600           -mov dword ptr [0x56abb4], edi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edi;
    // 004f9805  e846780000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f980a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f980d:
    // 004f980d  8b2d844d9f00           -mov ebp, dword ptr [0x9f4d84]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004f9813  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f9815  0f84a3000000           -je 0x4f98be
    if (cpu.flags.zf)
    {
        goto L_0x004f98be;
    }
    // 004f981b  8b5538                 -mov edx, dword ptr [ebp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(56) /* 0x38 */);
    // 004f981e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f9820  83faff                 +cmp edx, -1
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
    // 004f9823  0f8495000000           -je 0x4f98be
    if (cpu.flags.zf)
    {
        goto L_0x004f98be;
    }
    // 004f9829  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f982b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f982d  e8ce190200             -call 0x51b200
    cpu.esp -= 4;
    sub_51b200(app, cpu);
    if (cpu.terminate) return;
    // 004f9832  893d844d9f00           -mov dword ptr [0x9f4d84], edi
    app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */) = cpu.edi;
L_0x004f9838:
    // 004f9838  8b2d884d9f00           -mov ebp, dword ptr [0x9f4d88]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f983e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f9840  740e                   -je 0x4f9850
    if (cpu.flags.zf)
    {
        goto L_0x004f9850;
    }
    // 004f9842  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f9844  e84780feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9849  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f984b  a3884d9f00             -mov dword ptr [0x9f4d88], eax
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.eax;
L_0x004f9850:
    // 004f9850  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9857  7443                   -je 0x4f989c
    if (cpu.flags.zf)
    {
        goto L_0x004f989c;
    }
    // 004f9859  8b0d804d9f00           -mov ecx, dword ptr [0x9f4d80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f985f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9861  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f9863  7e25                   -jle 0x4f988a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f988a;
    }
    // 004f9865  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f9867:
    // 004f9867  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f986c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f986e  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9871  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f9873  7407                   -je 0x4f987c
    if (cpu.flags.zf)
    {
        goto L_0x004f987c;
    }
    // 004f9875  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f9877  e81480feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f987c:
    // 004f987c  8b1d804d9f00           -mov ebx, dword ptr [0x9f4d80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9882  42                     -inc edx
    (cpu.edx)++;
    // 004f9883  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f9886  39da                   +cmp edx, ebx
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
    // 004f9888  7cdd                   -jl 0x4f9867
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f9867;
    }
L_0x004f988a:
    // 004f988a  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f988f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f9891  e8fa7ffeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9896  8935944d9f00           -mov dword ptr [0x9f4d94], esi
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.esi;
L_0x004f989c:
    // 004f989c  8b2d744d9f00           -mov ebp, dword ptr [0x9f4d74]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f98a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f98a3  e82a8c0300             -call 0x5324d2
    cpu.esp -= 4;
    sub_5324d2(app, cpu);
    if (cpu.terminate) return;
    // 004f98a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f98aa  7550                   -jne 0x4f98fc
    if (!cpu.flags.zf)
    {
        goto L_0x004f98fc;
    }
    // 004f98ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f98b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f98b3:
    // 004f98b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f98b4  e8b0600300             -call 0x52f969
    cpu.esp -= 4;
    sub_52f969(app, cpu);
    if (cpu.terminate) return;
    // 004f98b9  e920ffffff             -jmp 0x4f97de
    goto L_0x004f97de;
L_0x004f98be:
    // 004f98be  8b0da84d9f00           -mov ecx, dword ptr [0x9f4da8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */);
    // 004f98c4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f98c6  0f846cffffff           -je 0x4f9838
    if (cpu.flags.zf)
    {
        goto L_0x004f9838;
    }
    // 004f98cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f98cd  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f98d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f98d6  0f855cffffff           -jne 0x4f9838
    if (!cpu.flags.zf)
    {
        goto L_0x004f9838;
    }
    // 004f98dc  be50da5400             -mov esi, 0x54da50
    cpu.esi = 5560912 /*0x54da50*/;
    // 004f98e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f98e2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f98e4  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f98e9  8935b4ab5600           -mov dword ptr [0x56abb4], esi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.esi;
    // 004f98ef  e85c770000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f98f4  83c40c                 +add esp, 0xc
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
    // 004f98f7  e93cffffff             -jmp 0x4f9838
    goto L_0x004f9838;
L_0x004f98fc:
    // 004f98fc  b870da5400             -mov eax, 0x54da70
    cpu.eax = 5560944 /*0x54da70*/;
    // 004f9901  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9902  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9904  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9909  a3b4ab5600             -mov dword ptr [0x56abb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.eax;
    // 004f990e  e83d770000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9913  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f9916  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9917  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9918  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9919  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f991a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f991b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f991c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f9920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9921  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9922  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9923  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f9925  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9927  89159c4d9f00           -mov dword ptr [0x9f4d9c], edx
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.edx;
    // 004f992d  833da8715600ff         +cmp dword ptr [0x5671a8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9934  7463                   -je 0x4f9999
    if (cpu.flags.zf)
    {
        goto L_0x004f9999;
    }
    // 004f9936  6afa                   -push -6
    app->getMemory<x86::reg32>(cpu.esp-4) = -6 /*-0x6*/;
    cpu.esp -= 4;
    // 004f9938  e83321ffff             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 004f993d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f993e  2eff1558475300         -call dword ptr cs:[0x534758]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457752) /* 0x534758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9945  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f994a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f994c  e89f000000             -call 0x4f99f0
    cpu.esp -= 4;
    sub_4f99f0(app, cpu);
    if (cpu.terminate) return;
    // 004f9951  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9953  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9955  0f8579000000           -jne 0x4f99d4
    if (!cpu.flags.zf)
    {
        goto L_0x004f99d4;
    }
    // 004f995b  e8c0030000             -call 0x4f9d20
    cpu.esp -= 4;
    sub_4f9d20(app, cpu);
    if (cpu.terminate) return;
    // 004f9960  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9962  0f8477000000           -je 0x4f99df
    if (cpu.flags.zf)
    {
        goto L_0x004f99df;
    }
    // 004f9968  e883040000             -call 0x4f9df0
    cpu.esp -= 4;
    sub_4f9df0(app, cpu);
    if (cpu.terminate) return;
    // 004f996d  e84efeffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
    // 004f9972  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004f9977  e8645ffeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f997c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f997e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f9980  e86b000000             -call 0x4f99f0
    cpu.esp -= 4;
    sub_4f99f0(app, cpu);
    if (cpu.terminate) return;
    // 004f9985  83f80a                 +cmp eax, 0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9988  7455                   -je 0x4f99df
    if (cpu.flags.zf)
    {
        goto L_0x004f99df;
    }
    // 004f998a  e891030000             -call 0x4f9d20
    cpu.esp -= 4;
    sub_4f9d20(app, cpu);
    if (cpu.terminate) return;
    // 004f998f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9991  7451                   -je 0x4f99e4
    if (cpu.flags.zf)
    {
        goto L_0x004f99e4;
    }
    // 004f9993  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9995  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9996  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9997  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9998  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9999:
    // 004f9999  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f999a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f999b  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004f99a0  be98da5400             -mov esi, 0x54da98
    cpu.esi = 5560984 /*0x54da98*/;
    // 004f99a5  bf23010000             -mov edi, 0x123
    cpu.edi = 291 /*0x123*/;
    // 004f99aa  68a4da5400             -push 0x54daa4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560996 /*0x54daa4*/;
    cpu.esp -= 4;
    // 004f99af  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f99b5  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f99bb  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f99c1  e84a76f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f99c6  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004f99cb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f99ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f99d4:
    // 004f99d4  e8e7fdffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
    // 004f99d9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f99db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f99df:
    // 004f99df  e8dcfdffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
L_0x004f99e4:
    // 004f99e4  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004f99e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f99ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f99f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f99f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f99f1  68904d9f00             -push 0x9f4d90
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440080 /*0x9f4d90*/;
    cpu.esp -= 4;
    // 004f99f6  89157c4d9f00           -mov dword ptr [0x9f4d7c], edx
    app->getMemory<x86::reg32>(x86::reg32(10440060) /* 0x9f4d7c */) = cpu.edx;
    // 004f99fc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f99fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f99ff  6800954f00             -push 0x4f9500
    app->getMemory<x86::reg32>(cpu.esp-4) = 5215488 /*0x4f9500*/;
    cpu.esp -= 4;
    // 004f9a04  8915884d9f00           -mov dword ptr [0x9f4d88], edx
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.edx;
    // 004f9a0a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9a0b  8915a84d9f00           -mov dword ptr [0x9f4da8], edx
    app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */) = cpu.edx;
    // 004f9a11  8915a44d9f00           -mov dword ptr [0x9f4da4], edx
    app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */) = cpu.edx;
    // 004f9a17  68744d9f00             -push 0x9f4d74
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440052 /*0x9f4d74*/;
    cpu.esp -= 4;
    // 004f9a1c  8915a04d9f00           -mov dword ptr [0x9f4da0], edx
    app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */) = cpu.edx;
    // 004f9a22  8915944d9f00           -mov dword ptr [0x9f4d94], edx
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.edx;
    // 004f9a28  e891760300             -call 0x5310be
    cpu.esp -= 4;
    sub_5310be(app, cpu);
    if (cpu.terminate) return;
    // 004f9a2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9a2f  7510                   -jne 0x4f9a41
    if (!cpu.flags.zf)
    {
        goto L_0x004f9a41;
    }
    // 004f9a31  833d904d9f0000         +cmp dword ptr [0x9f4d90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9a38  7505                   -jne 0x4f9a3f
    if (!cpu.flags.zf)
    {
        goto L_0x004f9a3f;
    }
    // 004f9a3a  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
L_0x004f9a3f:
    // 004f9a3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9a41:
    // 004f9a41  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004f9a46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9a50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9a51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9a52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9a54  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9a5b  741d                   -je 0x4f9a7a
    if (cpu.flags.zf)
    {
        goto L_0x004f9a7a;
    }
L_0x004f9a5d:
    // 004f9a5d  3b15804d9f00           +cmp edx, dword ptr [0x9f4d80]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9a63  7d1c                   -jge 0x4f9a81
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f9a81;
    }
    // 004f9a65  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9a6a  8b04d0                 -mov eax, dword ptr [eax + edx*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 8);
    // 004f9a6d  a3a8715600             -mov dword ptr [0x5671a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */) = cpu.eax;
    // 004f9a72  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9a77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9a79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9a7a:
    // 004f9a7a  e841000000             -call 0x4f9ac0
    cpu.esp -= 4;
    sub_4f9ac0(app, cpu);
    if (cpu.terminate) return;
    // 004f9a7f  ebdc                   -jmp 0x4f9a5d
    goto L_0x004f9a5d;
L_0x004f9a81:
    // 004f9a81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9a82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9a83  be88da5400             -mov esi, 0x54da88
    cpu.esi = 5560968 /*0x54da88*/;
    // 004f9a88  bfecda5400             -mov edi, 0x54daec
    cpu.edi = 5561068 /*0x54daec*/;
    // 004f9a8d  bd76010000             -mov ebp, 0x176
    cpu.ebp = 374 /*0x176*/;
    // 004f9a92  68fcda5400             -push 0x54dafc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561084 /*0x54dafc*/;
    cpu.esp -= 4;
    // 004f9a97  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004f9a9d  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f9aa3  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f9aa9  e86275f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f9aae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f9ab1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9ab3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ab7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9ac0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9ac1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9ac2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9ac3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9ac4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9ac5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9ac8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9aca  6afa                   -push -6
    app->getMemory<x86::reg32>(cpu.esp-4) = -6 /*-0x6*/;
    cpu.esp -= 4;
    // 004f9acc  8915804d9f00           -mov dword ptr [0x9f4d80], edx
    app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */) = cpu.edx;
    // 004f9ad2  e8991fffff             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 004f9ad7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9ad8  2eff1558475300         -call dword ptr cs:[0x534758]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457752) /* 0x534758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9adf  68904d9f00             -push 0x9f4d90
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440080 /*0x9f4d90*/;
    cpu.esp -= 4;
    // 004f9ae4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9ae6  6800954f00             -push 0x4f9500
    app->getMemory<x86::reg32>(cpu.esp-4) = 5215488 /*0x4f9500*/;
    cpu.esp -= 4;
    // 004f9aeb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9aec  68744d9f00             -push 0x9f4d74
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440052 /*0x9f4d74*/;
    cpu.esp -= 4;
    // 004f9af1  e8c8750300             -call 0x5310be
    cpu.esp -= 4;
    sub_5310be(app, cpu);
    if (cpu.terminate) return;
    // 004f9af6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9af8  0f8529010000           -jne 0x4f9c27
    if (!cpu.flags.zf)
    {
        goto L_0x004f9c27;
    }
    // 004f9afe  833d904d9f0000         +cmp dword ptr [0x9f4d90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b05  0f8427010000           -je 0x4f9c32
    if (cpu.flags.zf)
    {
        goto L_0x004f9c32;
    }
    // 004f9b0b  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b12  7433                   -je 0x4f9b47
    if (cpu.flags.zf)
    {
        goto L_0x004f9b47;
    }
    // 004f9b14  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f9b16:
    // 004f9b16  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9b1b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004f9b1d  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9b20  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f9b22  7407                   -je 0x4f9b2b
    if (cpu.flags.zf)
    {
        goto L_0x004f9b2b;
    }
    // 004f9b24  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f9b26  e8657dfeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f9b2b:
    // 004f9b2b  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f9b2e  81fea0000000           +cmp esi, 0xa0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b34  75e0                   -jne 0x4f9b16
    if (!cpu.flags.zf)
    {
        goto L_0x004f9b16;
    }
    // 004f9b36  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9b3b  e8507dfeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9b40  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9b42  a3944d9f00             -mov dword ptr [0x9f4d94], eax
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.eax;
L_0x004f9b47:
    // 004f9b47  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9b48  ba88da5400             -mov edx, 0x54da88
    cpu.edx = 5560968 /*0x54da88*/;
    // 004f9b4d  b914db5400             -mov ecx, 0x54db14
    cpu.ecx = 5561108 /*0x54db14*/;
    // 004f9b52  bba9010000             -mov ebx, 0x1a9
    cpu.ebx = 425 /*0x1a9*/;
    // 004f9b57  b828db5400             -mov eax, 0x54db28
    cpu.eax = 5561128 /*0x54db28*/;
    // 004f9b5c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f9b5e  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f9b64  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f9b6a  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 004f9b6f  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9b75  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f9b7b  e8a07afeff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9b80  a3944d9f00             -mov dword ptr [0x9f4d94], eax
    app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */) = cpu.eax;
    // 004f9b85  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f9b87:
    // 004f9b87  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9b8c  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f9b8f  895406fc               -mov dword ptr [esi + eax - 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.edx;
    // 004f9b93  895406f8               -mov dword ptr [esi + eax - 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.edx;
    // 004f9b97  81fea0000000           +cmp esi, 0xa0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9b9d  75e8                   -jne 0x4f9b87
    if (!cpu.flags.zf)
    {
        goto L_0x004f9b87;
    }
    // 004f9b9f  8b3d904d9f00           -mov edi, dword ptr [0x9f4d90]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
    // 004f9ba5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f9ba7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f9ba9  7639                   -jbe 0x4f9be4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9be4;
    }
    // 004f9bab  bf14db5400             -mov edi, 0x54db14
    cpu.edi = 5561108 /*0x54db14*/;
L_0x004f9bb0:
    // 004f9bb0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9bb4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9bb5  688c4d9f00             -push 0x9f4d8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440076 /*0x9f4d8c*/;
    cpu.esp -= 4;
    // 004f9bba  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9bbf  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9bc4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9bc5  8b0d744d9f00           -mov ecx, dword ptr [0x9f4d74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9bcb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9bcc  e8be770300             -call 0x53138f
    cpu.esp -= 4;
    sub_53138f(app, cpu);
    if (cpu.terminate) return;
    // 004f9bd1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9bd3  0f8499000000           -je 0x4f9c72
    if (cpu.flags.zf)
    {
        goto L_0x004f9c72;
    }
L_0x004f9bd9:
    // 004f9bd9  8b2d904d9f00           -mov ebp, dword ptr [0x9f4d90]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440080) /* 0x9f4d90 */);
    // 004f9bdf  46                     -inc esi
    (cpu.esi)++;
    // 004f9be0  39ee                   +cmp esi, ebp
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
    // 004f9be2  72cc                   -jb 0x4f9bb0
    if (cpu.flags.cf)
    {
        goto L_0x004f9bb0;
    }
L_0x004f9be4:
    // 004f9be4  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004f9be9  e8f25cfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f9bee  a1744d9f00             -mov eax, dword ptr [0x9f4d74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9bf3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9bf4  e8d9880300             -call 0x5324d2
    cpu.esp -= 4;
    sub_5324d2(app, cpu);
    if (cpu.terminate) return;
    // 004f9bf9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9bfb  741b                   -je 0x4f9c18
    if (cpu.flags.zf)
    {
        goto L_0x004f9c18;
    }
    // 004f9bfd  ba70da5400             -mov edx, 0x54da70
    cpu.edx = 5560944 /*0x54da70*/;
    // 004f9c02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9c03  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9c05  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9c0a  8915b4ab5600           -mov dword ptr [0x56abb4], edx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edx;
    // 004f9c10  e83b740000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9c15  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f9c18:
    // 004f9c18  a1804d9f00             -mov eax, dword ptr [0x9f4d80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9c1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c1e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9c21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9c27:
    // 004f9c27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9c29  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9c2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9c32:
    // 004f9c32  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004f9c37  e8a45cfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f9c3c  8b35744d9f00           -mov esi, dword ptr [0x9f4d74]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9c42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9c43  e88a880300             -call 0x5324d2
    cpu.esp -= 4;
    sub_5324d2(app, cpu);
    if (cpu.terminate) return;
    // 004f9c48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9c4a  741b                   -je 0x4f9c67
    if (cpu.flags.zf)
    {
        goto L_0x004f9c67;
    }
    // 004f9c4c  bf70da5400             -mov edi, 0x54da70
    cpu.edi = 5560944 /*0x54da70*/;
    // 004f9c51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9c52  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9c54  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004f9c59  893db4ab5600           -mov dword ptr [0x56abb4], edi
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.edi;
    // 004f9c5f  e8ec730000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004f9c64  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004f9c67:
    // 004f9c67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9c69  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9c6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c6f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9c71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9c72:
    // 004f9c72  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f9c74  e8b7020000             -call 0x4f9f30
    cpu.esp -= 4;
    sub_4f9f30(app, cpu);
    if (cpu.terminate) return;
    // 004f9c79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9c7b  0f8558ffffff           -jne 0x4f9bd9
    if (!cpu.flags.zf)
    {
        goto L_0x004f9bd9;
    }
    // 004f9c81  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9c86  f6403c10               +test byte ptr [eax + 0x3c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) & 16 /*0x10*/));
    // 004f9c8a  0f8449ffffff           -je 0x4f9bd9
    if (cpu.flags.zf)
    {
        goto L_0x004f9bd9;
    }
    // 004f9c90  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004f9c95  bdc1010000             -mov ebp, 0x1c1
    cpu.ebp = 449 /*0x1c1*/;
    // 004f9c9a  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f9ca0  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f9ca3  b834db5400             -mov eax, 0x54db34
    cpu.eax = 5561140 /*0x54db34*/;
    // 004f9ca8  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f9cae  42                     -inc edx
    (cpu.edx)++;
    // 004f9caf  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9cb5  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f9cbb  e86079feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9cc0  8b0d804d9f00           -mov ecx, dword ptr [0x9f4d80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9cc6  8b15944d9f00           -mov edx, dword ptr [0x9f4d94]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9ccc  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004f9ccf  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f9cd1  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f9cd4  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9cd9  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004f9cdc  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f9cdf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f9ce1  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f9ce4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f9ce6  e84571feff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f9ceb  8b15804d9f00           -mov edx, dword ptr [0x9f4d80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
    // 004f9cf1  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004f9cf6  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004f9cf9  01d0                   +add eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f9cfb  8b15884d9f00           -mov edx, dword ptr [0x9f4d88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9d01  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9d04  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004f9d07  c6041100               -mov byte ptr [ecx + edx], 0
    app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1) = 0 /*0x0*/;
    // 004f9d0b  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004f9d0d  ff05804d9f00           +inc dword ptr [0x9f4d80]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f9d13  e9c1feffff             -jmp 0x4f9bd9
    goto L_0x004f9bd9;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f9d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9d21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9d22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9d23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9d24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9d25  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9d28  8b15a8715600           -mov edx, dword ptr [0x5671a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9d2e  83faff                 +cmp edx, -1
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
    // 004f9d31  750b                   -jne 0x4f9d3e
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d3e;
    }
L_0x004f9d33:
    // 004f9d33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9d35  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f9d38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9d3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9d3e:
    // 004f9d3e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f9d40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9d41  688c4d9f00             -push 0x9f4d8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440076 /*0x9f4d8c*/;
    cpu.esp -= 4;
    // 004f9d46  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9d4b  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 004f9d50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9d51  8b1d744d9f00           -mov ebx, dword ptr [0x9f4d74]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9d57  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9d58  e832760300             -call 0x53138f
    cpu.esp -= 4;
    sub_53138f(app, cpu);
    if (cpu.terminate) return;
    // 004f9d5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9d5f  75d2                   -jne 0x4f9d33
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d33;
    }
    // 004f9d61  a1a8715600             -mov eax, dword ptr [0x5671a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9d66  e8c5010000             -call 0x4f9f30
    cpu.esp -= 4;
    sub_4f9f30(app, cpu);
    if (cpu.terminate) return;
    // 004f9d6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9d6d  75c4                   -jne 0x4f9d33
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d33;
    }
    // 004f9d6f  833d7c4d9f0000         +cmp dword ptr [0x9f4d7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440060) /* 0x9f4d7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9d76  746b                   -je 0x4f9de3
    if (cpu.flags.zf)
    {
        goto L_0x004f9de3;
    }
    // 004f9d78  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x004f9d7d:
    // 004f9d7d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9d7f  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004f9d81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9d82  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9d84  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9d86  8b3d8c4d9f00           -mov edi, dword ptr [0x9f4d8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440076) /* 0x9f4d8c */);
    // 004f9d8c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9d8d  68a04d9f00             -push 0x9f4da0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440096 /*0x9f4da0*/;
    cpu.esp -= 4;
    // 004f9d92  8b2da8715600           -mov ebp, dword ptr [0x5671a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9d98  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9d99  a1744d9f00             -mov eax, dword ptr [0x9f4d74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9d9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9d9f  e895760300             -call 0x531439
    cpu.esp -= 4;
    sub_531439(app, cpu);
    if (cpu.terminate) return;
    // 004f9da4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9da6  758b                   -jne 0x4f9d33
    if (!cpu.flags.zf)
    {
        goto L_0x004f9d33;
    }
    // 004f9da8  833d784d9f0000         +cmp dword ptr [0x9f4d78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440056) /* 0x9f4d78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9daf  7424                   -je 0x4f9dd5
    if (cpu.flags.zf)
    {
        goto L_0x004f9dd5;
    }
    // 004f9db1  a1a04d9f00             -mov eax, dword ptr [0x9f4da0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f9db6  e8e5000000             -call 0x4f9ea0
    cpu.esp -= 4;
    sub_4f9ea0(app, cpu);
    if (cpu.terminate) return;
    // 004f9dbb  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9dc0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9dc2  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004f9dc8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9dc9  8b1da04d9f00           -mov ebx, dword ptr [0x9f4da0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f9dcf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9dd0  e88d830300             -call 0x532162
    cpu.esp -= 4;
    sub_532162(app, cpu);
    if (cpu.terminate) return;
L_0x004f9dd5:
    // 004f9dd5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9dda  83c410                 +add esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f9ddd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9dde  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ddf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9de0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9de1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9de2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9de3:
    // 004f9de3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9de8  eb93                   -jmp 0x4f9d7d
    goto L_0x004f9d7d;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f9df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9df1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9df2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9df3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9df4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9df5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9df6  81ec401f0000           -sub esp, 0x1f40
    (cpu.esp) -= x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9dfc  bb401f0000             -mov ebx, 0x1f40
    cpu.ebx = 8000 /*0x1f40*/;
    // 004f9e01  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f9e03  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9e05  e83668feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f9e0a  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004f9e0f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9e13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9e14  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f9e16  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9e18  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9e1a  8b0da04d9f00           -mov ecx, dword ptr [0x9f4da0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004f9e20  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 004f9e25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9e26  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004f9e2a  e81f6c0300             -call 0x530a4e
    cpu.esp -= 4;
    sub_530a4e(app, cpu);
    if (cpu.terminate) return;
    // 004f9e2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9e31  740f                   -je 0x4f9e42
    if (cpu.flags.zf)
    {
        goto L_0x004f9e42;
    }
L_0x004f9e33:
    // 004f9e33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9e35  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9e3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9e42:
    // 004f9e42  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f9e44  035c2414               -add ebx, dword ptr [esp + 0x14]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004f9e48  ba00100000             -mov edx, 0x1000
    cpu.edx = 4096 /*0x1000*/;
    // 004f9e4d  68603d9f00             -push 0x9f3d60
    app->getMemory<x86::reg32>(cpu.esp-4) = 10435936 /*0x9f3d60*/;
    cpu.esp -= 4;
    // 004f9e52  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f9e54  bf2ef53ce7             -mov edi, 0xe73cf52e
    cpu.edi = 3879531822 /*0xe73cf52e*/;
    // 004f9e59  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9e5a  668915603d9f00         -mov word ptr [0x9f3d60], dx
    app->getMemory<x86::reg16>(x86::reg32(10435936) /* 0x9f3d60 */) = cpu.dx;
    // 004f9e61  893d943d9f00           -mov dword ptr [0x9f3d94], edi
    app->getMemory<x86::reg32>(x86::reg32(10435988) /* 0x9f3d94 */) = cpu.edi;
    // 004f9e67  2eff15ec445300         -call dword ptr cs:[0x5344ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457132) /* 0x5344ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9e6e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f9e70  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f9e72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9e73  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f9e7a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f9e7c  74b5                   -je 0x4f9e33
    if (cpu.flags.zf)
    {
        goto L_0x004f9e33;
    }
    // 004f9e7e  b8603d9f00             -mov eax, 0x9f3d60
    cpu.eax = 10435936 /*0x9f3d60*/;
    // 004f9e83  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004f9e86  a3784d9f00             -mov dword ptr [0x9f4d78], eax
    app->getMemory<x86::reg32>(x86::reg32(10440056) /* 0x9f4d78 */) = cpu.eax;
    // 004f9e8b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f9e90  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9e96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9e9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f9ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9ea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9ea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9ea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9ea3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9ea4  81ec401f0000           -sub esp, 0x1f40
    (cpu.esp) -= x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9eaa  bb401f0000             -mov ebx, 0x1f40
    cpu.ebx = 8000 /*0x1f40*/;
    // 004f9eaf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f9eb1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f9eb3  e88867feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f9eb8  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004f9ebd  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9ec1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9ec2  8b0da8715600           -mov ecx, dword ptr [0x5671a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9ec8  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 004f9ecd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9ece  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004f9ed2  e866690300             -call 0x53083d
    cpu.esp -= 4;
    sub_53083d(app, cpu);
    if (cpu.terminate) return;
    // 004f9ed7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9ed9  7509                   -jne 0x4f9ee4
    if (!cpu.flags.zf)
    {
        goto L_0x004f9ee4;
    }
    // 004f9edb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9edf  3b0424                 +cmp eax, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9ee2  760d                   -jbe 0x4f9ef1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f9ef1;
    }
L_0x004f9ee4:
    // 004f9ee4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f9ee6  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9eec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9eed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9eee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9eef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9ef0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f9ef1:
    // 004f9ef1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9ef2  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f9ef6  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004f9efa  8d503c                 -lea edx, [eax + 0x3c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004f9efd  806220f8               -and byte ptr [edx + 0x20], 0xf8
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(32) /* 0x20 */) &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004f9f01  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004f9f06  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f9f0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9f0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9f0c  8b2da8715600           -mov ebp, dword ptr [0x5671a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5665192) /* 0x5671a8 */);
    // 004f9f12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9f13  e819800300             -call 0x531f31
    cpu.esp -= 4;
    sub_531f31(app, cpu);
    if (cpu.terminate) return;
    // 004f9f18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9f1a  7405                   -je 0x4f9f21
    if (cpu.flags.zf)
    {
        goto L_0x004f9f21;
    }
    // 004f9f1c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f9f21:
    // 004f9f21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f22  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004f9f28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f9f2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f9f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f9f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f9f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9f32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9f33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9f34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f9f35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f9f36  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f9f38  8b15884d9f00           -mov edx, dword ptr [0x9f4d88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9f3e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f9f40  0f85af000000           -jne 0x4f9ff5
    if (!cpu.flags.zf)
    {
        goto L_0x004f9ff5;
    }
L_0x004f9f46:
    // 004f9f46  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004f9f4b  bf50db5400             -mov edi, 0x54db50
    cpu.edi = 5561168 /*0x54db50*/;
    // 004f9f50  bd5a020000             -mov ebp, 0x25a
    cpu.ebp = 602 /*0x25a*/;
    // 004f9f55  baf0000000             -mov edx, 0xf0
    cpu.edx = 240 /*0xf0*/;
    // 004f9f5a  b860db5400             -mov eax, 0x54db60
    cpu.eax = 5561184 /*0x54db60*/;
    // 004f9f5f  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f9f65  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f9f6b  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f9f71  bf88da5400             -mov edi, 0x54da88
    cpu.edi = 5560968 /*0x54da88*/;
    // 004f9f76  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9f7c  bd50db5400             -mov ebp, 0x54db50
    cpu.ebp = 5561168 /*0x54db50*/;
    // 004f9f81  e89a76feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9f86  a3884d9f00             -mov dword ptr [0x9f4d88], eax
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.eax;
    // 004f9f8b  c700f0000000           -mov dword ptr [eax], 0xf0
    app->getMemory<x86::reg32>(cpu.eax) = 240 /*0xf0*/;
L_0x004f9f91:
    // 004f9f91  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9f96  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f9f97  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f9f99  8b158c4d9f00           -mov edx, dword ptr [0x9f4d8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440076) /* 0x9f4d8c */);
    // 004f9f9f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f9fa0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f9fa1  8b0d744d9f00           -mov ecx, dword ptr [0x9f4d74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440052) /* 0x9f4d74 */);
    // 004f9fa7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f9fa8  e89a670300             -call 0x530747
    cpu.esp -= 4;
    sub_530747(app, cpu);
    if (cpu.terminate) return;
    // 004f9fad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f9faf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f9fb1  7556                   -jne 0x4fa009
    if (!cpu.flags.zf)
    {
        goto L_0x004fa009;
    }
    // 004f9fb3  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004f9fb8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f9fbb  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f9fbd  765c                   -jbe 0x4fa01b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fa01b;
    }
    // 004f9fbf  e8cc78feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9fc4  b86f020000             -mov eax, 0x26f
    cpu.eax = 623 /*0x26f*/;
    // 004f9fc9  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f9fcf  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004f9fd5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f9fd7  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f9fdc  b860db5400             -mov eax, 0x54db60
    cpu.eax = 5561184 /*0x54db60*/;
    // 004f9fe1  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004f9fe7  e83476feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f9fec  a3884d9f00             -mov dword ptr [0x9f4d88], eax
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.eax;
    // 004f9ff1  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004f9ff3  eb9c                   -jmp 0x4f9f91
    goto L_0x004f9f91;
L_0x004f9ff5:
    // 004f9ff5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f9ff7  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004f9ff9  e89278feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f9ffe  890d884d9f00           -mov dword ptr [0x9f4d88], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.ecx;
    // 004fa004  e93dffffff             -jmp 0x4f9f46
    goto L_0x004f9f46;
L_0x004fa009:
    // 004fa009  a1884d9f00             -mov eax, dword ptr [0x9f4d88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */);
    // 004fa00e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fa010  e87b78feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa015  890d884d9f00           -mov dword ptr [0x9f4d88], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440072) /* 0x9f4d88 */) = cpu.ecx;
L_0x004fa01b:
    // 004fa01b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa01d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa01e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa01f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa020  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa021  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa022  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa023  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4fa030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa033  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa034  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa035  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa036  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa038  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa03a  740b                   -je 0x4fa047
    if (cpu.flags.zf)
    {
        goto L_0x004fa047;
    }
    // 004fa03c  833da04d9f0000         +cmp dword ptr [0x9f4da0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa043  7509                   -jne 0x4fa04e
    if (!cpu.flags.zf)
    {
        goto L_0x004fa04e;
    }
    // 004fa045  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fa047:
    // 004fa047  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa048  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa049  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa04d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa04e:
    // 004fa04e  bb88da5400             -mov ebx, 0x54da88
    cpu.ebx = 5560968 /*0x54da88*/;
    // 004fa053  be70db5400             -mov esi, 0x54db70
    cpu.esi = 5561200 /*0x54db70*/;
    // 004fa058  bf87020000             -mov edi, 0x287
    cpu.edi = 647 /*0x287*/;
    // 004fa05d  ba70000000             -mov edx, 0x70
    cpu.edx = 112 /*0x70*/;
    // 004fa062  b880db5400             -mov eax, 0x54db80
    cpu.eax = 5561216 /*0x54db80*/;
    // 004fa067  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004fa06d  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004fa073  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fa079  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004fa07f  e89c75feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fa084  bb70000000             -mov ebx, 0x70
    cpu.ebx = 112 /*0x70*/;
    // 004fa089  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa08b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa08d  e8ae65feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004fa092  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa093  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa095  c70670000000           -mov dword ptr [esi], 0x70
    app->getMemory<x86::reg32>(cpu.esi) = 112 /*0x70*/;
    // 004fa09b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa09c  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004fa0a3  68a44d9f00             -push 0x9f4da4
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440100 /*0x9f4da4*/;
    cpu.esp -= 4;
    // 004fa0a8  8b2da04d9f00           -mov ebp, dword ptr [0x9f4da0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440096) /* 0x9f4da0 */);
    // 004fa0ae  c7461010000000         -mov dword ptr [esi + 0x10], 0x10
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 16 /*0x10*/;
    // 004fa0b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa0b6  c7462cb80b0000         -mov dword ptr [esi + 0x2c], 0xbb8
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 3000 /*0xbb8*/;
    // 004fa0bd  e8fe700300             -call 0x5311c0
    cpu.esp -= 4;
    sub_5311c0(app, cpu);
    if (cpu.terminate) return;
    // 004fa0c2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa0c4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa0c6  e8c577feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa0cb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fa0cd  7c0c                   -jl 0x4fa0db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa0db;
    }
    // 004fa0cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa0d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa0db:
    // 004fa0db  c7059c4d9f000f000000   -mov dword ptr [0x9f4d9c], 0xf
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 15 /*0xf*/;
    // 004fa0e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa0e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa0ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4fa0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa0f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa0f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa0f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa0f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa0f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa0f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa0f6  ba88da5400             -mov edx, 0x54da88
    cpu.edx = 5560968 /*0x54da88*/;
    // 004fa0fb  b994db5400             -mov ecx, 0x54db94
    cpu.ecx = 5561236 /*0x54db94*/;
    // 004fa100  bbaa020000             -mov ebx, 0x2aa
    cpu.ebx = 682 /*0x2aa*/;
    // 004fa105  b8a8db5400             -mov eax, 0x54dba8
    cpu.eax = 5561256 /*0x54dba8*/;
    // 004fa10a  bd88da5400             -mov ebp, 0x54da88
    cpu.ebp = 5560968 /*0x54da88*/;
    // 004fa10f  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004fa115  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004fa11b  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004fa120  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fa126  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004fa12c  e8ef74feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fa131  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa133  c70018000000           -mov dword ptr [eax], 0x18
    app->getMemory<x86::reg32>(cpu.eax) = 24 /*0x18*/;
L_0x004fa139:
    // 004fa139  6840db5400             -push 0x54db40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561152 /*0x54db40*/;
    cpu.esp -= 4;
    // 004fa13e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa13f  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004fa141  8b35a44d9f00           -mov esi, dword ptr [0x9f4da4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004fa147  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa148  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa14a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa14c  e8fd680300             -call 0x530a4e
    cpu.esp -= 4;
    sub_530a4e(app, cpu);
    if (cpu.terminate) return;
    // 004fa151  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa153  7541                   -jne 0x4fa196
    if (!cpu.flags.zf)
    {
        goto L_0x004fa196;
    }
    // 004fa155  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004fa158  3b3b                   +cmp edi, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa15a  764d                   -jbe 0x4fa1a9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fa1a9;
    }
    // 004fa15c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa15e  babd020000             -mov edx, 0x2bd
    cpu.edx = 701 /*0x2bd*/;
    // 004fa163  e82877feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa168  b894db5400             -mov eax, 0x54db94
    cpu.eax = 5561236 /*0x54db94*/;
    // 004fa16d  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004fa173  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004fa179  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004fa17e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa180  b8a8db5400             -mov eax, 0x54dba8
    cpu.eax = 5561256 /*0x54dba8*/;
    // 004fa185  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004fa18b  e89074feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004fa190  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa192  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 004fa194  eba3                   -jmp 0x4fa139
    goto L_0x004fa139;
L_0x004fa196:
    // 004fa196  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa198  e8f376feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa19d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004fa1a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa1a9:
    // 004fa1a9  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004fa1ac  8b0403                 -mov eax, dword ptr [ebx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 004fa1af  a3a84d9f00             -mov dword ptr [0x9f4da8], eax
    app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */) = cpu.eax;
    // 004fa1b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa1b6  e8d576feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004fa1bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa1bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4fa1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa1d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa1d1  8b15a44d9f00           -mov edx, dword ptr [0x9f4da4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440100) /* 0x9f4da4 */);
    // 004fa1d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fa1d9  7502                   -jne 0x4fa1dd
    if (!cpu.flags.zf)
    {
        goto L_0x004fa1dd;
    }
    // 004fa1db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa1dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa1dd:
    // 004fa1dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa1de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa1df  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa1e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa1e3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa1e4  bbb8db5400             -mov ebx, 0x54dbb8
    cpu.ebx = 5561272 /*0x54dbb8*/;
    // 004fa1e9  e840590300             -call 0x52fb2e
    cpu.esp -= 4;
    sub_52fb2e(app, cpu);
    if (cpu.terminate) return;
    // 004fa1ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa1ef  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004fa1f1  6854445600             -push 0x564454
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653588 /*0x564454*/;
    cpu.esp -= 4;
    // 004fa1f6  891db4ab5600           -mov dword ptr [0x56abb4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5680052) /* 0x56abb4 */) = cpu.ebx;
    // 004fa1fc  e84f6e0000             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004fa201  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004fa204  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa205  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa206  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa207  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa210  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa211  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004fa214  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa219  8b403c                 -mov eax, dword ptr [eax + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004fa21c  e82ff8ffff             -call 0x4f9a50
    cpu.esp -= 4;
    sub_4f9a50(app, cpu);
    if (cpu.terminate) return;
    // 004fa221  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa223  0f84c4000000           -je 0x4fa2ed
    if (cpu.flags.zf)
    {
        goto L_0x004fa2ed;
    }
    // 004fa229  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa22e  83786800               +cmp dword ptr [eax + 0x68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa232  0f8583000000           -jne 0x4fa2bb
    if (!cpu.flags.zf)
    {
        goto L_0x004fa2bb;
    }
    // 004fa238  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004fa23d:
    // 004fa23d  e8def6ffff             -call 0x4f9920
    cpu.esp -= 4;
    sub_4f9920(app, cpu);
    if (cpu.terminate) return;
    // 004fa242  a39c4d9f00             -mov dword ptr [0x9f4d9c], eax
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.eax;
    // 004fa247  833d9c4d9f0000         +cmp dword ptr [0x9f4d9c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa24e  0f858f000000           -jne 0x4fa2e3
    if (!cpu.flags.zf)
    {
        goto L_0x004fa2e3;
    }
    // 004fa254  c7059c4d9f0002000000   -mov dword ptr [0x9f4d9c], 2
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 2 /*0x2*/;
    // 004fa25e  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa263  8b6868                 -mov ebp, dword ptr [eax + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 004fa266  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004fa268  7558                   -jne 0x4fa2c2
    if (!cpu.flags.zf)
    {
        goto L_0x004fa2c2;
    }
L_0x004fa26a:
    // 004fa26a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004fa26f:
    // 004fa26f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa270  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa271  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa272  8b15844d9f00           -mov edx, dword ptr [0x9f4d84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa278  894234                 -mov dword ptr [edx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004fa27b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa27d  a3984d9f00             -mov dword ptr [0x9f4d98], eax
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = cpu.eax;
    // 004fa282  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004fa284:
    // 004fa284  a1844d9f00             -mov eax, dword ptr [0x9f4d84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */);
    // 004fa289  3b5834                 +cmp ebx, dword ptr [eax + 0x34]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa28c  744d                   -je 0x4fa2db
    if (cpu.flags.zf)
    {
        goto L_0x004fa2db;
    }
    // 004fa28e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa28f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa290  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa291  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004fa295  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fa296  2eff154c475300         -call dword ptr cs:[0x53474c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457740) /* 0x53474c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa29d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa29f  742e                   -je 0x4fa2cf
    if (cpu.flags.zf)
    {
        goto L_0x004fa2cf;
    }
    // 004fa2a1  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa2a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fa2a6  2eff15a4475300         -call dword ptr cs:[0x5347a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457828) /* 0x5347a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa2ad  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fa2b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004fa2b2  2eff152c475300         -call dword ptr cs:[0x53472c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457708) /* 0x53472c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa2b9  ebc9                   -jmp 0x4fa284
    goto L_0x004fa284;
L_0x004fa2bb:
    // 004fa2bb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fa2bd  e97bffffff             -jmp 0x4fa23d
    goto L_0x004fa23d;
L_0x004fa2c2:
    // 004fa2c2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa2c4  e867fdffff             -call 0x4fa030
    cpu.esp -= 4;
    sub_4fa030(app, cpu);
    if (cpu.terminate) return;
    // 004fa2c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa2cb  759d                   -jne 0x4fa26a
    if (!cpu.flags.zf)
    {
        goto L_0x004fa26a;
    }
    // 004fa2cd  eba0                   -jmp 0x4fa26f
    goto L_0x004fa26f;
L_0x004fa2cf:
    // 004fa2cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa2d4  e80756feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa2d9  eba9                   -jmp 0x4fa284
    goto L_0x004fa284;
L_0x004fa2db:
    // 004fa2db  e8f0feffff             -call 0x4fa1d0
    cpu.esp -= 4;
    sub_4fa1d0(app, cpu);
    if (cpu.terminate) return;
    // 004fa2e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa2e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa2e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004fa2e3:
    // 004fa2e3  e8d8f4ffff             -call 0x4f97c0
    cpu.esp -= 4;
    sub_4f97c0(app, cpu);
    if (cpu.terminate) return;
    // 004fa2e8  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004fa2eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa2ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa2ed:
    // 004fa2ed  c7059c4d9f0002000080   -mov dword ptr [0x9f4d9c], 0x80000002
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 2147483650 /*0x80000002*/;
    // 004fa2f7  a3844d9f00             -mov dword ptr [0x9f4d84], eax
    app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */) = cpu.eax;
    // 004fa2fc  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004fa2ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa300  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4fa310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa312  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa313  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa314  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa315  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa317  a3844d9f00             -mov dword ptr [0x9f4d84], eax
    app->getMemory<x86::reg32>(x86::reg32(10440068) /* 0x9f4d84 */) = cpu.eax;
    // 004fa31c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fa31e  8915ac715600           -mov dword ptr [0x5671ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5665196) /* 0x5671ac */) = cpu.edx;
    // 004fa324  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa326  89159c4d9f00           -mov dword ptr [0x9f4d9c], edx
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = cpu.edx;
    // 004fa32c  c74038ffffffff         -mov dword ptr [eax + 0x38], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 4294967295 /*0xffffffff*/;
    // 004fa333  68604d9f00             -push 0x9f4d60
    app->getMemory<x86::reg32>(cpu.esp-4) = 10440032 /*0x9f4d60*/;
    cpu.esp -= 4;
    // 004fa338  895034                 -mov dword ptr [eax + 0x34], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 004fa33b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004fa340  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004fa345  b810a24f00             -mov eax, 0x4fa210
    cpu.eax = 5218832 /*0x4fa210*/;
    // 004fa34a  890d984d9f00           -mov dword ptr [0x9f4d98], ecx
    app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */) = cpu.ecx;
    // 004fa350  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004fa355  e84654feff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004fa35a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa35c  0f84c7000000           -je 0x4fa429
    if (cpu.flags.zf)
    {
        goto L_0x004fa429;
    }
    // 004fa362  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
L_0x004fa367:
    // 004fa367  833d984d9f0000         +cmp dword ptr [0x9f4d98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa36e  7416                   -je 0x4fa386
    if (cpu.flags.zf)
    {
        goto L_0x004fa386;
    }
    // 004fa370  8b1dd8435600           -mov ebx, dword ptr [0x5643d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa376  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fa378  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa37a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa37d  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fa37f  e85c55feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa384  ebe1                   -jmp 0x4fa367
    goto L_0x004fa367;
L_0x004fa386:
    // 004fa386  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004fa38b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004fa38d:
    // 004fa38d  8b2d984d9f00           -mov ebp, dword ptr [0x9f4d98]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */);
    // 004fa393  39e9                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa395  753e                   -jne 0x4fa3d5
    if (!cpu.flags.zf)
    {
        goto L_0x004fa3d5;
    }
    // 004fa397  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa399  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa39c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa39e  7535                   -jne 0x4fa3d5
    if (!cpu.flags.zf)
    {
        goto L_0x004fa3d5;
    }
    // 004fa3a0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa3a2  e88955feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004fa3a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa3a9  7421                   -je 0x4fa3cc
    if (cpu.flags.zf)
    {
        goto L_0x004fa3cc;
    }
    // 004fa3ab  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa3ad  e87ed2feff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004fa3b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa3b4  7c1f                   -jl 0x4fa3d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa3d5;
    }
L_0x004fa3b6:
    // 004fa3b6  8b2dd8435600           -mov ebp, dword ptr [0x5643d8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa3bc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fa3be  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa3c0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa3c3  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fa3c5  e81655feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa3ca  ebc1                   -jmp 0x4fa38d
    goto L_0x004fa38d;
L_0x004fa3cc:
    // 004fa3cc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fa3ce  e80d55feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa3d3  ebe1                   -jmp 0x4fa3b6
    goto L_0x004fa3b6;
L_0x004fa3d5:
    // 004fa3d5  833d984d9f0000         +cmp dword ptr [0x9f4d98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440088) /* 0x9f4d98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa3dc  7540                   -jne 0x4fa41e
    if (!cpu.flags.zf)
    {
        goto L_0x004fa41e;
    }
L_0x004fa3de:
    // 004fa3de  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa3e0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa3e2  c7473400000000         -mov dword ptr [edi + 0x34], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa3e9  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 004fa3ee  8b0d704d9f00           -mov ecx, dword ptr [0x9f4d70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440048) /* 0x9f4d70 */);
    // 004fa3f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa3f5  2eff1570475300         -call dword ptr cs:[0x534770]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457776) /* 0x534770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004fa3fc:
    // 004fa3fc  837f3400               +cmp dword ptr [edi + 0x34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa400  7413                   -je 0x4fa415
    if (cpu.flags.zf)
    {
        goto L_0x004fa415;
    }
    // 004fa402  833d9c4d9f0009         +cmp dword ptr [0x9f4d9c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa409  750a                   -jne 0x4fa415
    if (!cpu.flags.zf)
    {
        goto L_0x004fa415;
    }
    // 004fa40b  8b0da84d9f00           -mov ecx, dword ptr [0x9f4da8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10440104) /* 0x9f4da8 */);
    // 004fa411  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fa413  7520                   -jne 0x4fa435
    if (!cpu.flags.zf)
    {
        goto L_0x004fa435;
    }
L_0x004fa415:
    // 004fa415  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa418  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa419  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa41d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa41e:
    // 004fa41e  833d9c4d9f0009         +cmp dword ptr [0x9f4d9c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa425  75b7                   -jne 0x4fa3de
    if (!cpu.flags.zf)
    {
        goto L_0x004fa3de;
    }
    // 004fa427  ebd3                   -jmp 0x4fa3fc
    goto L_0x004fa3fc;
L_0x004fa429:
    // 004fa429  c7059c4d9f0001000000   -mov dword ptr [0x9f4d9c], 1
    app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */) = 1 /*0x1*/;
    // 004fa433  ebc7                   -jmp 0x4fa3fc
    goto L_0x004fa3fc;
L_0x004fa435:
    // 004fa435  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004fa43a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fa43c  e8af0e0200             -call 0x51b2f0
    cpu.esp -= 4;
    sub_51b2f0(app, cpu);
    if (cpu.terminate) return;
    // 004fa441  894738                 -mov dword ptr [edi + 0x38], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004fa444  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa447  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa448  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa449  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa44a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa44b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa44c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4fa450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa450  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa451  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa452  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa454  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa456  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 004fa45b  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa462  8b15704d9f00           -mov edx, dword ptr [0x9f4d70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10440048) /* 0x9f4d70 */);
    // 004fa468  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa469  2eff1570475300         -call dword ptr cs:[0x534770]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457776) /* 0x534770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa470  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa475  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa476  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa477  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa481  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa482  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa484  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa486  833d9c4d9f0009         +cmp dword ptr [0x9f4d9c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440092) /* 0x9f4d9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa48d  750f                   -jne 0x4fa49e
    if (!cpu.flags.zf)
    {
        goto L_0x004fa49e;
    }
    // 004fa48f  833dac71560000         +cmp dword ptr [0x5671ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665196) /* 0x5671ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa496  752a                   -jne 0x4fa4c2
    if (!cpu.flags.zf)
    {
        goto L_0x004fa4c2;
    }
L_0x004fa498:
    // 004fa498  8b4334                 -mov eax, dword ptr [ebx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 004fa49b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa49c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa49d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa49e:
    // 004fa49e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa49f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa4a0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa4a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004fa4a4  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 004fa4a9  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa4b0  8b3d704d9f00           -mov edi, dword ptr [0x9f4d70]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440048) /* 0x9f4d70 */);
    // 004fa4b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa4b7  2eff1570475300         -call dword ptr cs:[0x534770]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457776) /* 0x534770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa4be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4c0  ebd6                   -jmp 0x4fa498
    goto L_0x004fa498;
L_0x004fa4c2:
    // 004fa4c2  e829000000             -call 0x4fa4f0
    cpu.esp -= 4;
    sub_4fa4f0(app, cpu);
    if (cpu.terminate) return;
    // 004fa4c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa4c9  74cd                   -je 0x4fa498
    if (cpu.flags.zf)
    {
        goto L_0x004fa498;
    }
    // 004fa4cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa4cd  ff15ac715600           -call dword ptr [0x5671ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5665196) /* 0x5671ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fa4d3  8b4334                 -mov eax, dword ptr [ebx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 004fa4d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa4d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fa4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa4e0  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa4e3  e918140200             -jmp 0x51b900
    return sub_51b900(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa4f0  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa4f3  e9a8130200             -jmp 0x51b8a0
    return sub_51b8a0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4fa500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa501  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa503  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fa505  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004fa507  8b4938                 -mov ecx, dword ptr [ecx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004fa50a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa50c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa50e  e83d150200             -call 0x51ba50
    cpu.esp -= 4;
    sub_51ba50(app, cpu);
    if (cpu.terminate) return;
    // 004fa513  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa515  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa517  7c04                   -jl 0x4fa51d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa51d;
    }
    // 004fa519  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa51b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa51c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa51d:
    // 004fa51d  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004fa51f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa521  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa522  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4fa530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa530  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa531  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fa533  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fa535  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fa537  8b4938                 -mov ecx, dword ptr [ecx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004fa53a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fa53c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fa53e  e8ed0f0200             -call 0x51b530
    cpu.esp -= 4;
    sub_51b530(app, cpu);
    if (cpu.terminate) return;
    // 004fa543  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa544  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fa550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa550  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa551  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa552  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa553  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fa554  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa55a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa55c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fa55e  83fbff                 +cmp ebx, -1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa561  0f857d000000           -jne 0x4fa5e4
    if (!cpu.flags.zf)
    {
        goto L_0x004fa5e4;
    }
    // 004fa567  bd10ac5600             -mov ebp, 0x56ac10
    cpu.ebp = 5680144 /*0x56ac10*/;
L_0x004fa56c:
    // 004fa56c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004fa56e  7454                   -je 0x4fa5c4
    if (cpu.flags.zf)
    {
        goto L_0x004fa5c4;
    }
    // 004fa570  66837e2a00             +cmp word ptr [esi + 0x2a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004fa575  7513                   -jne 0x4fa58a
    if (!cpu.flags.zf)
    {
        goto L_0x004fa58a;
    }
    // 004fa577  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa579  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa57b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa57e  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004fa581  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004fa583  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004fa586  6689462a               -mov word ptr [esi + 0x2a], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */) = cpu.ax;
L_0x004fa58a:
    // 004fa58a  66837e2c00             +cmp word ptr [esi + 0x2c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004fa58f  7513                   -jne 0x4fa5a4
    if (!cpu.flags.zf)
    {
        goto L_0x004fa5a4;
    }
    // 004fa591  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa593  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa595  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa598  c1e202                 +shl edx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004fa59b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004fa59d  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004fa5a0  6689462c               -mov word ptr [esi + 0x2c], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ax;
L_0x004fa5a4:
    // 004fa5a4  66837e2e00             +cmp word ptr [esi + 0x2e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004fa5a9  7513                   -jne 0x4fa5be
    if (!cpu.flags.zf)
    {
        goto L_0x004fa5be;
    }
    // 004fa5ab  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fa5ad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fa5af  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fa5b2  c1e202                 +shl edx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004fa5b5  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004fa5b7  c1f802                 +sar eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004fa5ba  6689462e               -mov word ptr [esi + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */) = cpu.ax;
L_0x004fa5be:
    // 004fa5be  66c746280600           -mov word ptr [esi + 0x28], 6
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = 6 /*0x6*/;
L_0x004fa5c4:
    // 004fa5c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa5c5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fa5c7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fa5c9  bbb0715600             -mov ebx, 0x5671b0
    cpu.ebx = 5665200 /*0x5671b0*/;
    // 004fa5ce  893dd8435600           -mov dword ptr [0x5643d8], edi
    app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */) = cpu.edi;
    // 004fa5d4  e857abffff             -call 0x4f5130
    cpu.esp -= 4;
    sub_4f5130(app, cpu);
    if (cpu.terminate) return;
    // 004fa5d9  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004fa5df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa5e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa5e4:
    // 004fa5e4  bd28ac5600             -mov ebp, 0x56ac28
    cpu.ebp = 5680168 /*0x56ac28*/;
    // 004fa5e9  eb81                   -jmp 0x4fa56c
    goto L_0x004fa56c;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4fa5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa5f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa5f1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fa5f3  833d944d9f0000         +cmp dword ptr [0x9f4d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa5fa  7417                   -je 0x4fa613
    if (cpu.flags.zf)
    {
        goto L_0x004fa613;
    }
L_0x004fa5fc:
    // 004fa5fc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fa5fe  7c1a                   -jl 0x4fa61a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa61a;
    }
    // 004fa600  3b15804d9f00           +cmp edx, dword ptr [0x9f4d80]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10440064) /* 0x9f4d80 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa606  7312                   -jae 0x4fa61a
    if (!cpu.flags.cf)
    {
        goto L_0x004fa61a;
    }
    // 004fa608  a1944d9f00             -mov eax, dword ptr [0x9f4d94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440084) /* 0x9f4d94 */);
    // 004fa60d  8b44d004               -mov eax, dword ptr [eax + edx*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edx * 8);
    // 004fa611  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa612  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa613:
    // 004fa613  e8a8f4ffff             -call 0x4f9ac0
    cpu.esp -= 4;
    sub_4f9ac0(app, cpu);
    if (cpu.terminate) return;
    // 004fa618  ebe2                   -jmp 0x4fa5fc
    goto L_0x004fa5fc;
L_0x004fa61a:
    // 004fa61a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa61c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa61d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4fa620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fa622  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fa623  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fa624  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fa626  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fa628  8915ac4e9f00           -mov dword ptr [0x9f4eac], edx
    app->getMemory<x86::reg32>(x86::reg32(10440364) /* 0x9f4eac */) = cpu.edx;
    // 004fa62e  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa635  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fa637  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004fa63a  891558445600           -mov dword ptr [0x564458], edx
    app->getMemory<x86::reg32>(x86::reg32(5653592) /* 0x564458 */) = cpu.edx;
    // 004fa640  e83b0e0200             -call 0x51b480
    cpu.esp -= 4;
    sub_51b480(app, cpu);
    if (cpu.terminate) return;
    // 004fa645  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa648  e8e3090200             -call 0x51b030
    cpu.esp -= 4;
    sub_51b030(app, cpu);
    if (cpu.terminate) return;
    // 004fa64d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa64f  7525                   -jne 0x4fa676
    if (!cpu.flags.zf)
    {
        goto L_0x004fa676;
    }
    // 004fa651  833dec6d560001         +cmp dword ptr [0x566dec], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fa658  7c14                   -jl 0x4fa66e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fa66e;
    }
    // 004fa65a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fa65b  b8d8db5400             -mov eax, 0x54dbd8
    cpu.eax = 5561304 /*0x54dbd8*/;
    // 004fa660  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fa662  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004fa664  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fa666  8d5638                 -lea edx, [esi + 0x38]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa669  e8127b0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004fa66e:
    // 004fa66e  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa671  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa672  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa673  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa674  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa675  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa676:
    // 004fa676  8b5e4c                 -mov ebx, dword ptr [esi + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 004fa679  8b4e48                 -mov ecx, dword ptr [esi + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004fa67c  8b5640                 -mov edx, dword ptr [esi + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 004fa67f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fa680  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa683  8b5e44                 -mov ebx, dword ptr [esi + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004fa686  e885100200             -call 0x51b710
    cpu.esp -= 4;
    sub_51b710(app, cpu);
    if (cpu.terminate) return;
    // 004fa68b  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa68e  e82d0b0200             -call 0x51b1c0
    cpu.esp -= 4;
    sub_51b1c0(app, cpu);
    if (cpu.terminate) return;
    // 004fa693  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa696  e8450b0200             -call 0x51b1e0
    cpu.esp -= 4;
    sub_51b1e0(app, cpu);
    if (cpu.terminate) return;
    // 004fa69b  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa69e  e88d020200             -call 0x51a930
    cpu.esp -= 4;
    sub_51a930(app, cpu);
    if (cpu.terminate) return;
    // 004fa6a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fa6a5  750f                   -jne 0x4fa6b6
    if (!cpu.flags.zf)
    {
        goto L_0x004fa6b6;
    }
    // 004fa6a7  c7463401000000         -mov dword ptr [esi + 0x34], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = 1 /*0x1*/;
    // 004fa6ae  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004fa6b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fa6b6:
    // 004fa6b6  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004fa6b9  e8420b0200             -call 0x51b200
    cpu.esp -= 4;
    sub_51b200(app, cpu);
    if (cpu.terminate) return;
    // 004fa6be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fa6c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fa6c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4fa6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fa6d0  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fa6d7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004fa6dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
