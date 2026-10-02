#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

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

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_43dbe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043dbe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043dbe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043dbe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043dbe3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043dbe4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043dbe5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043dbe6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043dbe8  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0043dbeb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043dbed  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043dbf2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043dbf4  e867ca0000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043dbf9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043dbfb  0f8482000000           -je 0x43dc83
    if (cpu.flags.zf)
    {
        goto L_0x0043dc83;
    }
    // 0043dc01  837f6000               +cmp dword ptr [edi + 0x60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(96) /* 0x60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dc05  7508                   -jne 0x43dc0f
    if (!cpu.flags.zf)
    {
        goto L_0x0043dc0f;
    }
    // 0043dc07  8b3dbcd26f00           -mov edi, dword ptr [0x6fd2bc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 0043dc0d  eb06                   -jmp 0x43dc15
    goto L_0x0043dc15;
L_0x0043dc0f:
    // 0043dc0f  8b3d28d36f00           -mov edi, dword ptr [0x6fd328]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */);
L_0x0043dc15:
    // 0043dc15  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043dc17  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043dc1a  e861bbffff             -call 0x439780
    cpu.esp -= 4;
    sub_439780(app, cpu);
    if (cpu.terminate) return;
    // 0043dc1f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043dc20  8d55f4                 -lea edx, [ebp - 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043dc23  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043dc26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043dc27  8d55f0                 -lea edx, [ebp - 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043dc2a  8b5e60                 -mov ebx, dword ptr [esi + 0x60]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 0043dc2d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043dc2e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043dc30  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043dc32  e8d9bbffff             -call 0x439810
    cpu.esp -= 4;
    sub_439810(app, cpu);
    if (cpu.terminate) return;
    // 0043dc37  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043dc39  8a45fc                 -mov al, byte ptr [ebp - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043dc3c  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 0043dc3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043dc41  8a45f0                 -mov al, byte ptr [ebp - 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043dc44  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 0043dc47  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043dc49  b9ff000000             -mov ecx, 0xff
    cpu.ecx = 255 /*0xff*/;
    // 0043dc4e  8a45f4                 -mov al, byte ptr [ebp - 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043dc51  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0043dc54  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0043dc57  8d45d0                 -lea eax, [ebp - 0x30]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0043dc5a  894ddc                 -mov dword ptr [ebp - 0x24], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ecx;
    // 0043dc5d  e81eec0500             -call 0x49c880
    cpu.esp -= 4;
    sub_49c880(app, cpu);
    if (cpu.terminate) return;
    // 0043dc62  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0043dc65  894640                 -mov dword ptr [esi + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0043dc68  894650                 -mov dword ptr [esi + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0043dc6b  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0043dc6e  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0043dc71  894654                 -mov dword ptr [esi + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 0043dc74  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043dc77  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0043dc7a  894658                 -mov dword ptr [esi + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 0043dc7d  894e4c                 -mov dword ptr [esi + 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.ecx;
    // 0043dc80  894e5c                 -mov dword ptr [esi + 0x5c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */) = cpu.ecx;
L_0x0043dc83:
    // 0043dc83  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043dc85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dc86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dc87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dc88  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dc89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dc8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dc8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_43dc90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043dc90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043dc91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043dc92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043dc93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043dc94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043dc95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043dc96  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043dc98  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0043dc9b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043dc9d  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043dca2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043dca4  e8b7c90000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043dca9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043dcab  0f8496000000           -je 0x43dd47
    if (cpu.flags.zf)
    {
        goto L_0x0043dd47;
    }
    // 0043dcb1  83796000               +cmp dword ptr [ecx + 0x60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dcb5  7508                   -jne 0x43dcbf
    if (!cpu.flags.zf)
    {
        goto L_0x0043dcbf;
    }
    // 0043dcb7  8b3dbcd26f00           -mov edi, dword ptr [0x6fd2bc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 0043dcbd  eb06                   -jmp 0x43dcc5
    goto L_0x0043dcc5;
L_0x0043dcbf:
    // 0043dcbf  8b3d28d36f00           -mov edi, dword ptr [0x6fd328]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */);
L_0x0043dcc5:
    // 0043dcc5  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0043dcc8  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0043dccb  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0043dcce  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0043dcd1  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0043dcd4  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 0043dcd7  8d55f0                 -lea edx, [ebp - 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043dcda  8b464c                 -mov eax, dword ptr [esi + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 0043dcdd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043dcdf  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0043dce2  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0043dce5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043dce7  e864ed0500             -call 0x49ca50
    cpu.esp -= 4;
    sub_49ca50(app, cpu);
    if (cpu.terminate) return;
    // 0043dcec  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 0043dcf1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043dcf3  8a4df4                 -mov cl, byte ptr [ebp - 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043dcf6  8a45f8                 -mov al, byte ptr [ebp - 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043dcf9  8a5df0                 -mov bl, byte ptr [ebp - 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043dcfc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043dcfd  8b5660                 -mov edx, dword ptr [esi + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 0043dd00  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043dd02  e8b9bbffff             -call 0x4398c0
    cpu.esp -= 4;
    sub_4398c0(app, cpu);
    if (cpu.terminate) return;
    // 0043dd07  837e6000               +cmp dword ptr [esi + 0x60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dd0b  751a                   -jne 0x43dd27
    if (!cpu.flags.zf)
    {
        goto L_0x0043dd27;
    }
    // 0043dd0d  bae0775300             -mov edx, 0x5377e0
    cpu.edx = 5470176 /*0x5377e0*/;
    // 0043dd12  e899d10000             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 0043dd17  e8244d0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0043dd1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043dd1e  7407                   -je 0x43dd27
    if (cpu.flags.zf)
    {
        goto L_0x0043dd27;
    }
    // 0043dd20  c680b300000001         -mov byte ptr [eax + 0xb3], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(179) /* 0xb3 */) = 1 /*0x1*/;
L_0x0043dd27:
    // 0043dd27  837e6001               +cmp dword ptr [esi + 0x60], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dd2b  751a                   -jne 0x43dd47
    if (!cpu.flags.zf)
    {
        goto L_0x0043dd47;
    }
    // 0043dd2d  baf4775300             -mov edx, 0x5377f4
    cpu.edx = 5470196 /*0x5377f4*/;
    // 0043dd32  e879d10000             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 0043dd37  e8044d0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0043dd3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043dd3e  7407                   -je 0x43dd47
    if (cpu.flags.zf)
    {
        goto L_0x0043dd47;
    }
    // 0043dd40  c680b300000001         -mov byte ptr [eax + 0xb3], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(179) /* 0xb3 */) = 1 /*0x1*/;
L_0x0043dd47:
    // 0043dd47  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043dd49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd4e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43dd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043dd50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043dd51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043dd52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043dd53  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043dd55  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043dd57  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043dd59  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043dd5e  e8fdc80000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043dd63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043dd65  7422                   -je 0x43dd89
    if (cpu.flags.zf)
    {
        goto L_0x0043dd89;
    }
    // 0043dd67  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dd69  895960                 -mov dword ptr [ecx + 0x60], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = cpu.ebx;
    // 0043dd6c  e86ffeffff             -call 0x43dbe0
    cpu.esp -= 4;
    sub_43dbe0(app, cpu);
    if (cpu.terminate) return;
    // 0043dd71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dd73  e8f8c60000             -call 0x44a470
    cpu.esp -= 4;
    sub_44a470(app, cpu);
    if (cpu.terminate) return;
    // 0043dd78  8a6105                 -mov ah, byte ptr [ecx + 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0043dd7b  80e4eb                 -and ah, 0xeb
    cpu.ah &= x86::reg8(x86::sreg8(235 /*0xeb*/));
    // 0043dd7e  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0043dd80  886105                 -mov byte ptr [ecx + 5], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.ah;
    // 0043dd83  80ca04                 -or dl, 4
    cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0043dd86  885105                 -mov byte ptr [ecx + 5], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.dl;
L_0x0043dd89:
    // 0043dd89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd8b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_43dd90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043dd90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043dd91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043dd92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043dd93  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043dd95  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043dd97  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043dd9c  e8bfc80000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043dda1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043dda3  7418                   -je 0x43ddbd
    if (cpu.flags.zf)
    {
        goto L_0x0043ddbd;
    }
    // 0043dda5  8a6105                 -mov ah, byte ptr [ecx + 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0043dda8  80cc10                 -or ah, 0x10
    cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0043ddab  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0043ddad  886105                 -mov byte ptr [ecx + 5], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.ah;
    // 0043ddb0  80e2fb                 -and dl, 0xfb
    cpu.dl &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0043ddb3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ddb5  885105                 -mov byte ptr [ecx + 5], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0043ddb8  e8d3feffff             -call 0x43dc90
    cpu.esp -= 4;
    sub_43dc90(app, cpu);
    if (cpu.terminate) return;
L_0x0043ddbd:
    // 0043ddbd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddbe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_43ddd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ddd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ddd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043ddd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ddd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ddd5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043ddd7  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043dddc  e87fc80000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043dde1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043dde3  7430                   -je 0x43de15
    if (cpu.flags.zf)
    {
        goto L_0x0043de15;
    }
    // 0043dde5  8a6105                 -mov ah, byte ptr [ecx + 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0043dde8  80cc10                 -or ah, 0x10
    cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0043ddeb  886105                 -mov byte ptr [ecx + 5], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.ah;
    // 0043ddee  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0043ddf0  8b4150                 -mov eax, dword ptr [ecx + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 0043ddf3  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0043ddf6  8b4154                 -mov eax, dword ptr [ecx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 0043ddf9  894144                 -mov dword ptr [ecx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0043ddfc  8b4158                 -mov eax, dword ptr [ecx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 0043ddff  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0043de02  8b415c                 -mov eax, dword ptr [ecx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */);
    // 0043de05  80e2fb                 -and dl, 0xfb
    cpu.dl &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0043de08  89414c                 -mov dword ptr [ecx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0043de0b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043de0d  885105                 -mov byte ptr [ecx + 5], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0043de10  e87bfeffff             -call 0x43dc90
    cpu.esp -= 4;
    sub_43dc90(app, cpu);
    if (cpu.terminate) return;
L_0x0043de15:
    // 0043de15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043de16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043de17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043de18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_43de20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043de20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043de21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043de22  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043de24  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043de27  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0043de29  8d55f0                 -lea edx, [ebp - 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043de2c  e81fec0500             -call 0x49ca50
    cpu.esp -= 4;
    sub_49ca50(app, cpu);
    if (cpu.terminate) return;
    // 0043de31  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043de34  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043de37  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043de3c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043de42  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0043de45  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0043de48  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0043de4d  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043de4f  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043de52  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043de57  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043de59  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0043de5b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043de5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043de5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043de5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43de60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043de60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043de61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043de62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043de63  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043de65  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043de68  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0043de6b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043de6d  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0043de70  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0043de73  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0043de75  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043de77  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043de7a  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043de7c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043de7e  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0043de83  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043de86  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043de88  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0043de8b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043de8d  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
    // 0043de92  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043de94  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043de97  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043de99  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0043de9c  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0043de9e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043dea0  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0043dea3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043dea5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043dea8  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043deaa  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0043deac  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043deae  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043deb0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0043deb2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043deb4  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043deb7  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043deb9  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0043debb  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0043debe  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
    // 0043dec3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043dec5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043dec8  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043deca  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043decc  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0043dece  39c3                   +cmp ebx, eax
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
    // 0043ded0  7e04                   -jle 0x43ded6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ded6;
    }
    // 0043ded2  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0043ded4  eb10                   -jmp 0x43dee6
    goto L_0x0043dee6;
L_0x0043ded6:
    // 0043ded6  39c1                   +cmp ecx, eax
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
    // 0043ded8  7d0a                   -jge 0x43dee4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043dee4;
    }
    // 0043deda  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0043dedc  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043dede  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dedf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dee0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dee1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0043dee4:
    // 0043dee4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0043dee6:
    // 0043dee6  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0043dee8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043deea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043deeb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043deec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043deed  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_43def0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043def0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043def1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043def2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043def3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043def5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043def8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043defa  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0043defc  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0043deff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043df01  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043df04  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043df06  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043df08  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0043df0b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043df0d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043df0f  7d04                   -jge 0x43df15
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043df15;
    }
    // 0043df11  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043df13  eb06                   -jmp 0x43df1b
    goto L_0x0043df1b;
L_0x0043df15:
    // 0043df15  39d7                   +cmp edi, edx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043df17  7d02                   -jge 0x43df1b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043df1b;
    }
    // 0043df19  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x0043df1b:
    // 0043df1b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043df1d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043df20  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043df22  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043df24  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043df27  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043df29  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043df2b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043df2e  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043df30  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0043df35  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043df37  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043df3a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0043df3c  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0043df3f  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
    // 0043df44  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043df46  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043df49  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043df4b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043df4d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043df4f  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043df51  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043df53  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0043df55  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0043df58  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043df5a  39f8                   +cmp eax, edi
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
    // 0043df5c  7e04                   -jle 0x43df62
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043df62;
    }
    // 0043df5e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043df60  eb12                   -jmp 0x43df74
    goto L_0x0043df74;
L_0x0043df62:
    // 0043df62  39f9                   +cmp ecx, edi
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
    // 0043df64  7d0c                   -jge 0x43df72
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043df72;
    }
    // 0043df66  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043df68  7516                   -jne 0x43df80
    if (!cpu.flags.zf)
    {
        goto L_0x0043df80;
    }
    // 0043df6a  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 0043df70  eb30                   -jmp 0x43dfa2
    goto L_0x0043dfa2;
L_0x0043df72:
    // 0043df72  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
L_0x0043df74:
    // 0043df74  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043df76  7508                   -jne 0x43df80
    if (!cpu.flags.zf)
    {
        goto L_0x0043df80;
    }
    // 0043df78  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 0043df7e  eb22                   -jmp 0x43dfa2
    goto L_0x0043dfa2;
L_0x0043df80:
    // 0043df80  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0043df82  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043df84  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043df86  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043df89  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043df8b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043df8d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043df90  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043df92  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043df94  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043df97  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043df99  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0043df9e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043dfa0  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x0043dfa2:
    // 0043dfa2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043dfa4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dfa5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dfa6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dfa7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_43dfb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043dfb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043dfb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043dfb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043dfb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043dfb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043dfb5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043dfb6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043dfb8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043dfba  8b5806                 -mov ebx, dword ptr [eax + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0043dfbd  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0043dfc0  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043dfc3  8b8092000000           -mov eax, dword ptr [eax + 0x92]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(146) /* 0x92 */);
    // 0043dfc9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043dfcc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043dfcf  e8bc990900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 0043dfd4  8b4106                 -mov eax, dword ptr [ecx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0043dfd7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043dfda  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0043dfdd  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0043dfe0  8d580c                 -lea ebx, [eax + 0xc]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0043dfe3  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0043dfe6  8b818e000000           -mov eax, dword ptr [ecx + 0x8e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(142) /* 0x8e */);
    // 0043dfec  8d57dd                 -lea edx, [edi - 0x23]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-35) /* -0x23 */);
    // 0043dfef  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043dff2  e899990900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 0043dff7  8d57e9                 -lea edx, [edi - 0x17]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-23) /* -0x17 */);
    // 0043dffa  8b8190000000           -mov eax, dword ptr [ecx + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */);
    // 0043e000  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0043e002  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e005  e886990900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 0043e00a  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0043e00d  6840e4ff00             -push 0xffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 16770112 /*0xffe440*/;
    cpu.esp -= 4;
    // 0043e012  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e015  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0043e017  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0043e01a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043e01c  8b819c000000           -mov eax, dword ptr [ecx + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 0043e022  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0043e027  e864410100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043e02c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e02d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e02e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e02f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e030  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e031  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e032  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_43e040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043e040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043e041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043e042  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043e043  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043e044  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043e045  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043e046  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043e048  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043e04b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043e04d  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e050  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0043e053  e8c8fdffff             -call 0x43de20
    cpu.esp -= 4;
    sub_43de20(app, cpu);
    if (cpu.terminate) return;
    // 0043e058  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043e05b  8b5672                 -mov edx, dword ptr [esi + 0x72]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(114) /* 0x72 */);
    // 0043e05e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e061  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e064  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e066  8d5003                 -lea edx, [eax + 3]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0043e069  68000000ff             -push 0xff000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278190080 /*0xff000000*/;
    cpu.esp -= 4;
    // 0043e06e  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e071  8b4e78                 -mov ecx, dword ptr [esi + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0043e074  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e077  8b5e76                 -mov ebx, dword ptr [esi + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(118) /* 0x76 */);
    // 0043e07a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043e07d  8b4674                 -mov eax, dword ptr [esi + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 0043e080  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043e083  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e086  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0043e089  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0043e08b  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043e08e  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0043e091  e87aa80900             -call 0x4d8910
    cpu.esp -= 4;
    sub_4d8910(app, cpu);
    if (cpu.terminate) return;
    // 0043e096  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e099  8b4e78                 -mov ecx, dword ptr [esi + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0043e09c  8b5e76                 -mov ebx, dword ptr [esi + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(118) /* 0x76 */);
    // 0043e09f  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043e0a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e0a3  8b4672                 -mov eax, dword ptr [esi + 0x72]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(114) /* 0x72 */);
    // 0043e0a6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e0a9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e0ac  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0043e0af  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e0b1  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e0b4  8b7674                 -mov esi, dword ptr [esi + 0x74]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 0043e0b7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e0ba  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0043e0bd  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043e0c0  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0043e0c2  e849a80900             -call 0x4d8910
    cpu.esp -= 4;
    sub_4d8910(app, cpu);
    if (cpu.terminate) return;
    // 0043e0c7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043e0c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e0ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e0cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e0cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e0cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e0ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e0cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43e0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043e0d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043e0d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043e0d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043e0d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043e0d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043e0d5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043e0d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043e0d9  6683b88c00000002       +cmp word ptr [eax + 0x8c], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(140) /* 0x8c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043e0e1  7530                   -jne 0x43e113
    if (!cpu.flags.zf)
    {
        goto L_0x0043e113;
    }
    // 0043e0e3  8b5806                 -mov ebx, dword ptr [eax + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0043e0e6  8b8082000000           -mov eax, dword ptr [eax + 0x82]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(130) /* 0x82 */);
    // 0043e0ec  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043e0ef  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e0f2  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e0f5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e0f7  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0043e0fd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e100  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e103  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e105  8b8694000000           -mov eax, dword ptr [esi + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 0043e10b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e10e  e87d980900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x0043e113:
    // 0043e113  6683be8c00000002       +cmp word ptr [esi + 0x8c], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(140) /* 0x8c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043e11b  7507                   -jne 0x43e124
    if (!cpu.flags.zf)
    {
        goto L_0x0043e124;
    }
    // 0043e11d  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
    // 0043e122  eb05                   -jmp 0x43e129
    goto L_0x0043e129;
L_0x0043e124:
    // 0043e124  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
L_0x0043e129:
    // 0043e129  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e12a  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043e12d  8b8682000000           -mov eax, dword ptr [esi + 0x82]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(130) /* 0x82 */);
    // 0043e133  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043e136  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e139  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e13c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e13e  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0043e144  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e147  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e14a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e14c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043e14e  8d500f                 -lea edx, [eax + 0xf]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(15) /* 0xf */);
    // 0043e151  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0043e156  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 0043e15c  e82f400100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043e161  6683be8c00000001       +cmp word ptr [esi + 0x8c], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(140) /* 0x8c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043e169  752a                   -jne 0x43e195
    if (!cpu.flags.zf)
    {
        goto L_0x0043e195;
    }
    // 0043e16b  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043e16e  8b467a                 -mov eax, dword ptr [esi + 0x7a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(122) /* 0x7a */);
    // 0043e171  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043e174  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e177  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e17a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e17c  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 0043e17f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e182  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e185  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e187  8b8696000000           -mov eax, dword ptr [esi + 0x96]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(150) /* 0x96 */);
    // 0043e18d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e190  e8fb970900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x0043e195:
    // 0043e195  6683be8c00000001       +cmp word ptr [esi + 0x8c], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(140) /* 0x8c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043e19d  7507                   -jne 0x43e1a6
    if (!cpu.flags.zf)
    {
        goto L_0x0043e1a6;
    }
    // 0043e19f  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
    // 0043e1a4  eb05                   -jmp 0x43e1ab
    goto L_0x0043e1ab;
L_0x0043e1a6:
    // 0043e1a6  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
L_0x0043e1ab:
    // 0043e1ab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e1ac  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043e1af  8b467a                 -mov eax, dword ptr [esi + 0x7a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(122) /* 0x7a */);
    // 0043e1b2  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043e1b5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e1b8  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e1bb  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e1bd  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 0043e1c0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e1c3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e1c6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e1c8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043e1ca  8d500f                 -lea edx, [eax + 0xf]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(15) /* 0xf */);
    // 0043e1cd  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0043e1d2  8b86a0000000           -mov eax, dword ptr [esi + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
    // 0043e1d8  e8b33f0100             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0043e1dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e1de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e1df  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e1e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e1e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e1e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_43e1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043e1f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043e1f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043e1f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043e1f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043e1f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043e1f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043e1f6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043e1f8  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043e1fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043e1fd  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0043e200  8b4044                 -mov eax, dword ptr [eax + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0043e203  8b5e6a                 -mov ebx, dword ptr [esi + 0x6a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(106) /* 0x6a */);
    // 0043e206  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043e209  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043e20c  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043e20f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e212  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e214  8b4670                 -mov eax, dword ptr [esi + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 0043e217  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e21a  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0043e21d  b9ff000000             -mov ecx, 0xff
    cpu.ecx = 255 /*0xff*/;
    // 0043e222  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e224  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043e227  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043e229  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043e22b  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0043e22e  8b7e48                 -mov edi, dword ptr [esi + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0043e231  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043e234  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e237  8b466c                 -mov eax, dword ptr [esi + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 0043e23a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e23d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e240  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e242  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0043e245  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0043e248  8b466e                 -mov eax, dword ptr [esi + 0x6e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(110) /* 0x6e */);
    // 0043e24b  680000007f             -push 0x7f000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2130706432 /*0x7f000000*/;
    cpu.esp -= 4;
    // 0043e250  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e253  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 0043e258  8d5806                 -lea ebx, [eax + 6]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0043e25b  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e25e  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043e261  42                     -inc edx
    (cpu.edx)++;
    // 0043e262  40                     -inc eax
    (cpu.eax)++;
    // 0043e263  e8c8a60900             -call 0x4d8930
    cpu.esp -= 4;
    sub_4d8930(app, cpu);
    if (cpu.terminate) return;
    // 0043e268  8b466e                 -mov eax, dword ptr [esi + 0x6e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(110) /* 0x6e */);
    // 0043e26b  68ff7f7fff             -push 0xff7f7fff
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286545919 /*0xff7f7fff*/;
    cpu.esp -= 4;
    // 0043e270  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e273  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 0043e278  8d5806                 -lea ebx, [eax + 6]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0043e27b  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e27e  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043e281  e8aaa60900             -call 0x4d8930
    cpu.esp -= 4;
    sub_4d8930(app, cpu);
    if (cpu.terminate) return;
    // 0043e286  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e289  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043e28c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0043e28e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e28f  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043e292  8b5668                 -mov edx, dword ptr [esi + 0x68]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */);
    // 0043e295  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e296  8b4666                 -mov eax, dword ptr [esi + 0x66]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(102) /* 0x66 */);
    // 0043e299  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e29c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e29f  e8bcfbffff             -call 0x43de60
    cpu.esp -= 4;
    sub_43de60(app, cpu);
    if (cpu.terminate) return;
    // 0043e2a4  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e2a7  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043e2aa  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e2ad  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e2af  8b5664                 -mov edx, dword ptr [esi + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 0043e2b2  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0043e2b5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e2b8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e2ba  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0043e2bd  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043e2c0  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e2c3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e2c6  8b5662                 -mov edx, dword ptr [esi + 0x62]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(98) /* 0x62 */);
    // 0043e2c9  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043e2cb  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e2ce  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0043e2d1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e2d3  680000007f             -push 0x7f000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2130706432 /*0x7f000000*/;
    cpu.esp -= 4;
    // 0043e2d8  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043e2db  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0043e2de  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 0043e2e3  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043e2e6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0043e2e8  40                     -inc eax
    (cpu.eax)++;
    // 0043e2e9  e842a60900             -call 0x4d8930
    cpu.esp -= 4;
    sub_4d8930(app, cpu);
    if (cpu.terminate) return;
    // 0043e2ee  68ff7f7fff             -push 0xff7f7fff
    app->getMemory<x86::reg32>(cpu.esp-4) = 4286545919 /*0xff7f7fff*/;
    cpu.esp -= 4;
    // 0043e2f3  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 0043e2f8  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e2fb  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043e2fe  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0043e300  e82ba60900             -call 0x4d8930
    cpu.esp -= 4;
    sub_4d8930(app, cpu);
    if (cpu.terminate) return;
    // 0043e305  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043e307  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e308  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e309  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e30a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e30b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e30c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e30d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_43e310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043e310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043e311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043e312  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043e313  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043e314  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043e315  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043e316  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043e318  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0043e31b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043e31d  8b4040                 -mov eax, dword ptr [eax + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0043e320  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0043e325  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0043e328  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 0043e32b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0043e32d  8955e0                 -mov dword ptr [ebp - 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edx;
    // 0043e330  8955e4                 -mov dword ptr [ebp - 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edx;
    // 0043e333  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043e336  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0043e339  e812e70500             -call 0x49ca50
    cpu.esp -= 4;
    sub_49ca50(app, cpu);
    if (cpu.terminate) return;
    // 0043e33e  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043e341  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043e344  68000000ff             -push 0xff000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278190080 /*0xff000000*/;
    cpu.esp -= 4;
    // 0043e349  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043e34b  21ca                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043e34d  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0043e350  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e353  8b5e62                 -mov ebx, dword ptr [esi + 0x62]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(98) /* 0x62 */);
    // 0043e356  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e358  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043e35b  8b7e66                 -mov edi, dword ptr [esi + 0x66]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(102) /* 0x66 */);
    // 0043e35e  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043e360  68000000ff             -push 0xff000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278190080 /*0xff000000*/;
    cpu.esp -= 4;
    // 0043e365  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e367  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043e36a  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043e36d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e370  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0043e373  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e375  8b4668                 -mov eax, dword ptr [esi + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */);
    // 0043e378  68000000ff             -push 0xff000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278190080 /*0xff000000*/;
    cpu.esp -= 4;
    // 0043e37d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e380  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e383  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043e385  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0043e388  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0043e38b  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0043e38e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e38f  8b4664                 -mov eax, dword ptr [esi + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 0043e392  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043e394  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e397  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043e39a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e39c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043e39e  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e3a0  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043e3a2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043e3a4  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0043e3a7  8d5303                 -lea edx, [ebx + 3]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0043e3aa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e3ab  8d0439                 -lea eax, [ecx + edi]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 0043e3ae  8d5803                 -lea ebx, [eax + 3]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0043e3b1  8d4103                 -lea eax, [ecx + 3]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 0043e3b4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0043e3b6  e805a50900             -call 0x4d88c0
    cpu.esp -= 4;
    sub_4d88c0(app, cpu);
    if (cpu.terminate) return;
    // 0043e3bb  68000000af             -push 0xaf000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2936012800 /*0xaf000000*/;
    cpu.esp -= 4;
    // 0043e3c0  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043e3c3  68ffffffaf             -push 0xafffffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 2952790015 /*0xafffffff*/;
    cpu.esp -= 4;
    // 0043e3c8  0d000000af             -or eax, 0xaf000000
    cpu.eax |= x86::reg32(x86::sreg32(2936012800 /*0xaf000000*/));
    // 0043e3cd  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043e3d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e3d1  8b4662                 -mov eax, dword ptr [esi + 0x62]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(98) /* 0x62 */);
    // 0043e3d4  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043e3d7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e3da  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e3dc  8b4668                 -mov eax, dword ptr [esi + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */);
    // 0043e3df  8b4e64                 -mov ecx, dword ptr [esi + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 0043e3e2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e3e5  8b7e66                 -mov edi, dword ptr [esi + 0x66]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(102) /* 0x66 */);
    // 0043e3e8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043e3ea  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0043e3ed  40                     -inc eax
    (cpu.eax)++;
    // 0043e3ee  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0043e3f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e3f2  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e3f5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043e3f7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e3fa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043e3fd  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e3ff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043e401  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e403  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043e405  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043e407  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0043e40a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e40b  8d0439                 -lea eax, [ecx + edi]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 0043e40e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0043e411  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0043e414  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0043e416  e8a5a40900             -call 0x4d88c0
    cpu.esp -= 4;
    sub_4d88c0(app, cpu);
    if (cpu.terminate) return;
    // 0043e41b  68000000ff             -push 0xff000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278190080 /*0xff000000*/;
    cpu.esp -= 4;
    // 0043e420  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043e423  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0043e425  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0043e42a  8b7e62                 -mov edi, dword ptr [esi + 0x62]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(98) /* 0x62 */);
    // 0043e42d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e42e  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043e431  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0043e434  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e437  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e439  8b4668                 -mov eax, dword ptr [esi + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */);
    // 0043e43c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e43f  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0043e441  8b5664                 -mov edx, dword ptr [esi + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 0043e444  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e445  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e448  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e44b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e44e  8b7666                 -mov esi, dword ptr [esi + 0x66]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(102) /* 0x66 */);
    // 0043e451  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e453  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0043e456  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043e459  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043e45b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043e45d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043e460  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e462  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043e464  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e467  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e469  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0043e46b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e46c  8d1c32                 -lea ebx, [edx + esi]
    cpu.ebx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0043e46f  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e472  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043e474  e847a40900             -call 0x4d88c0
    cpu.esp -= 4;
    sub_4d88c0(app, cpu);
    if (cpu.terminate) return;
    // 0043e479  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043e47b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e47c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e47d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e47e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e47f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e480  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e481  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_43e490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043e490  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043e491  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043e492  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043e493  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043e494  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043e495  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043e496  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043e498  81ec90000000           -sub esp, 0x90
    (cpu.esp) -= x86::reg32(x86::sreg32(144 /*0x90*/));
    // 0043e49e  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 0043e4a4  8b486c                 -mov ecx, dword ptr [eax + 0x6c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 0043e4a7  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0043e4aa  8b586e                 -mov ebx, dword ptr [eax + 0x6e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(110) /* 0x6e */);
    // 0043e4ad  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0043e4b0  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0043e4b3  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043e4b6  8d1431                 -lea edx, [ecx + esi]
    cpu.edx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 0043e4b9  8b7806                 -mov edi, dword ptr [eax + 6]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0043e4bc  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043e4be  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0043e4c1  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0043e4c3  895572                 -mov dword ptr [ebp + 0x72], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */) = cpu.edx;
    // 0043e4c6  894d76                 -mov dword ptr [ebp + 0x76], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.ecx;
    // 0043e4c9  8b706a                 -mov esi, dword ptr [eax + 0x6a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(106) /* 0x6a */);
    // 0043e4cc  8b4870                 -mov ecx, dword ptr [eax + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0043e4cf  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0043e4d2  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0043e4d5  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0043e4d8  68000000ff             -push 0xff000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4278190080 /*0xff000000*/;
    cpu.esp -= 4;
    // 0043e4dd  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0043e4e0  89557a                 -mov dword ptr [ebp + 0x7a], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */) = cpu.edx;
    // 0043e4e3  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0043e4e8  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e4ea  8b4572                 -mov eax, dword ptr [ebp + 0x72]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 0043e4ed  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0043e4f0  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0043e4f3  897d7e                 -mov dword ptr [ebp + 0x7e], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edi;
    // 0043e4f6  e815a40900             -call 0x4d8910
    cpu.esp -= 4;
    sub_4d8910(app, cpu);
    if (cpu.terminate) return;
    // 0043e4fb  a1a83a5600             -mov eax, dword ptr [0x563aa8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651112) /* 0x563aa8 */);
    // 0043e500  8d7d06                 -lea edi, [ebp + 6]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(6) /* 0x6 */);
    // 0043e503  8945fa                 -mov dword ptr [ebp - 6], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = cpu.eax;
    // 0043e506  a1ac3a5600             -mov eax, dword ptr [0x563aac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651116) /* 0x563aac */);
    // 0043e50b  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 0043e50e  8945fe                 -mov dword ptr [ebp - 2], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-2) /* -0x2 */) = cpu.eax;
    // 0043e511  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0043e514  bb0000803f             -mov ebx, 0x3f800000
    cpu.ebx = 1065353216 /*0x3f800000*/;
    // 0043e519  89451a                 -mov dword ptr [ebp + 0x1a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(26) /* 0x1a */) = cpu.eax;
    // 0043e51c  8b45fe                 -mov eax, dword ptr [ebp - 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0043e51f  897562                 -mov dword ptr [ebp + 0x62], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(98) /* 0x62 */) = cpu.esi;
    // 0043e522  89451e                 -mov dword ptr [ebp + 0x1e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(30) /* 0x1e */) = cpu.eax;
    // 0043e525  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0043e528  897502                 -mov dword ptr [ebp + 2], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(2) /* 0x2 */) = cpu.esi;
    // 0043e52b  89453a                 -mov dword ptr [ebp + 0x3a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(58) /* 0x3a */) = cpu.eax;
    // 0043e52e  8b45fe                 -mov eax, dword ptr [ebp - 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0043e531  897542                 -mov dword ptr [ebp + 0x42], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(66) /* 0x42 */) = cpu.esi;
    // 0043e534  89453e                 -mov dword ptr [ebp + 0x3e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(62) /* 0x3e */) = cpu.eax;
    // 0043e537  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0043e53a  897522                 -mov dword ptr [ebp + 0x22], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(34) /* 0x22 */) = cpu.esi;
    // 0043e53d  89455a                 -mov dword ptr [ebp + 0x5a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */) = cpu.eax;
    // 0043e540  8b45fe                 -mov eax, dword ptr [ebp - 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0043e543  d95d56                 -fstp dword ptr [ebp + 0x56]
    app->getMemory<float>(cpu.ebp + x86::reg32(86) /* 0x56 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0043e546  89455e                 -mov dword ptr [ebp + 0x5e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */) = cpu.eax;
    // 0043e549  8b4572                 -mov eax, dword ptr [ebp + 0x72]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 0043e54c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e54e  89457e                 -mov dword ptr [ebp + 0x7e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.eax;
    // 0043e551  8d75f2                 -lea esi, [ebp - 0xe]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 0043e554  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 0043e557  d95d52                 -fstp dword ptr [ebp + 0x52]
    app->getMemory<float>(cpu.ebp + x86::reg32(82) /* 0x52 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0043e55a  8b4552                 -mov eax, dword ptr [ebp + 0x52]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(82) /* 0x52 */);
    // 0043e55d  89550a                 -mov dword ptr [ebp + 0xa], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(10) /* 0xa */) = cpu.edx;
    // 0043e560  8945f2                 -mov dword ptr [ebp - 0xe], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */) = cpu.eax;
    // 0043e563  8b4576                 -mov eax, dword ptr [ebp + 0x76]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 0043e566  89550e                 -mov dword ptr [ebp + 0xe], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */) = cpu.edx;
    // 0043e569  89457e                 -mov dword ptr [ebp + 0x7e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.eax;
    // 0043e56c  895d2a                 -mov dword ptr [ebp + 0x2a], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(42) /* 0x2a */) = cpu.ebx;
    // 0043e56f  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 0043e572  d95d32                 -fstp dword ptr [ebp + 0x32]
    app->getMemory<float>(cpu.ebp + x86::reg32(50) /* 0x32 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0043e575  8b4532                 -mov eax, dword ptr [ebp + 0x32]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(50) /* 0x32 */);
    // 0043e578  89552e                 -mov dword ptr [ebp + 0x2e], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(46) /* 0x2e */) = cpu.edx;
    // 0043e57b  894512                 -mov dword ptr [ebp + 0x12], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.eax;
    // 0043e57e  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 0043e581  895d4a                 -mov dword ptr [ebp + 0x4a], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(74) /* 0x4a */) = cpu.ebx;
    // 0043e584  89457e                 -mov dword ptr [ebp + 0x7e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.eax;
    // 0043e587  895d4e                 -mov dword ptr [ebp + 0x4e], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */) = cpu.ebx;
    // 0043e58a  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 0043e58d  d95d16                 -fstp dword ptr [ebp + 0x16]
    app->getMemory<float>(cpu.ebp + x86::reg32(22) /* 0x16 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0043e590  8b4516                 -mov eax, dword ptr [ebp + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(22) /* 0x16 */);
    // 0043e593  89556a                 -mov dword ptr [ebp + 0x6a], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */) = cpu.edx;
    // 0043e596  8945f6                 -mov dword ptr [ebp - 0xa], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */) = cpu.eax;
    // 0043e599  8b4556                 -mov eax, dword ptr [ebp + 0x56]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 0043e59c  8b15d03d5f00           -mov edx, dword ptr [0x5f3dd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6241744) /* 0x5f3dd0 */);
    // 0043e5a2  894536                 -mov dword ptr [ebp + 0x36], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(54) /* 0x36 */) = cpu.eax;
    // 0043e5a5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043e5aa  895d6e                 -mov dword ptr [ebp + 0x6e], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */) = cpu.ebx;
    // 0043e5ad  e84e33ffff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
    // 0043e5b2  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043e5b5  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 0043e5bb  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e5c0  7558                   -jne 0x43e61a
    if (!cpu.flags.zf)
    {
        goto L_0x0043e61a;
    }
    // 0043e5c2  39c8                   +cmp eax, ecx
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
    // 0043e5c4  7d54                   -jge 0x43e61a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e61a;
    }
    // 0043e5c6  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e5c9  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 0043e5ce  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 0043e5d4  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 0043e5da  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e5df  750d                   -jne 0x43e5ee
    if (!cpu.flags.zf)
    {
        goto L_0x0043e5ee;
    }
    // 0043e5e1  39c8                   +cmp eax, ecx
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
    // 0043e5e3  7c09                   -jl 0x43e5ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043e5ee;
    }
    // 0043e5e5  39d0                   +cmp eax, edx
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
    // 0043e5e7  7e09                   -jle 0x43e5f2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e5f2;
    }
    // 0043e5e9  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 0043e5ec  eb04                   -jmp 0x43e5f2
    goto L_0x0043e5f2;
L_0x0043e5ee:
    // 0043e5ee  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043e5f1  90                     -nop 
    ;
L_0x0043e5f2:
    // 0043e5f2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0043e5f4  90                     -nop 
    ;
    // 0043e5f5  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 0043e5fb  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 0043e601  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e606  750d                   -jne 0x43e615
    if (!cpu.flags.zf)
    {
        goto L_0x0043e615;
    }
    // 0043e608  39c8                   +cmp eax, ecx
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
    // 0043e60a  7c09                   -jl 0x43e615
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043e615;
    }
    // 0043e60c  39d0                   +cmp eax, edx
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
    // 0043e60e  7e0f                   -jle 0x43e61f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e61f;
    }
    // 0043e610  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0043e613  eb0a                   -jmp 0x43e61f
    goto L_0x0043e61f;
L_0x0043e615:
    // 0043e615  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0043e618  eb05                   -jmp 0x43e61f
    goto L_0x0043e61f;
L_0x0043e61a:
    // 0043e61a  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x0043e61f:
    // 0043e61f  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 0043e621  8d7d26                 -lea edi, [ebp + 0x26]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(38) /* 0x26 */);
    // 0043e624  8d7512                 -lea esi, [ebp + 0x12]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(18) /* 0x12 */);
    // 0043e627  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043e62a  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 0043e630  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e635  7558                   -jne 0x43e68f
    if (!cpu.flags.zf)
    {
        goto L_0x0043e68f;
    }
    // 0043e637  39c8                   +cmp eax, ecx
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
    // 0043e639  7d54                   -jge 0x43e68f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e68f;
    }
    // 0043e63b  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e63e  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 0043e643  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 0043e649  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 0043e64f  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e654  750d                   -jne 0x43e663
    if (!cpu.flags.zf)
    {
        goto L_0x0043e663;
    }
    // 0043e656  39c8                   +cmp eax, ecx
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
    // 0043e658  7c09                   -jl 0x43e663
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043e663;
    }
    // 0043e65a  39d0                   +cmp eax, edx
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
    // 0043e65c  7e09                   -jle 0x43e667
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e667;
    }
    // 0043e65e  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 0043e661  eb04                   -jmp 0x43e667
    goto L_0x0043e667;
L_0x0043e663:
    // 0043e663  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043e666  90                     -nop 
    ;
L_0x0043e667:
    // 0043e667  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0043e669  90                     -nop 
    ;
    // 0043e66a  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 0043e670  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 0043e676  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e67b  750d                   -jne 0x43e68a
    if (!cpu.flags.zf)
    {
        goto L_0x0043e68a;
    }
    // 0043e67d  39c8                   +cmp eax, ecx
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
    // 0043e67f  7c09                   -jl 0x43e68a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043e68a;
    }
    // 0043e681  39d0                   +cmp eax, edx
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
    // 0043e683  7e0f                   -jle 0x43e694
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e694;
    }
    // 0043e685  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0043e688  eb0a                   -jmp 0x43e694
    goto L_0x0043e694;
L_0x0043e68a:
    // 0043e68a  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0043e68d  eb05                   -jmp 0x43e694
    goto L_0x0043e694;
L_0x0043e68f:
    // 0043e68f  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x0043e694:
    // 0043e694  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 0043e696  8d7d46                 -lea edi, [ebp + 0x46]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(70) /* 0x46 */);
    // 0043e699  8d7532                 -lea esi, [ebp + 0x32]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(50) /* 0x32 */);
    // 0043e69c  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043e69f  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 0043e6a5  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e6aa  7558                   -jne 0x43e704
    if (!cpu.flags.zf)
    {
        goto L_0x0043e704;
    }
    // 0043e6ac  39c8                   +cmp eax, ecx
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
    // 0043e6ae  7d54                   -jge 0x43e704
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e704;
    }
    // 0043e6b0  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e6b3  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 0043e6b8  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 0043e6be  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 0043e6c4  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e6c9  750d                   -jne 0x43e6d8
    if (!cpu.flags.zf)
    {
        goto L_0x0043e6d8;
    }
    // 0043e6cb  39c8                   +cmp eax, ecx
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
    // 0043e6cd  7c09                   -jl 0x43e6d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043e6d8;
    }
    // 0043e6cf  39d0                   +cmp eax, edx
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
    // 0043e6d1  7e09                   -jle 0x43e6dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e6dc;
    }
    // 0043e6d3  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 0043e6d6  eb04                   -jmp 0x43e6dc
    goto L_0x0043e6dc;
L_0x0043e6d8:
    // 0043e6d8  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043e6db  90                     -nop 
    ;
L_0x0043e6dc:
    // 0043e6dc  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0043e6de  90                     -nop 
    ;
    // 0043e6df  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 0043e6e5  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 0043e6eb  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e6f0  750d                   -jne 0x43e6ff
    if (!cpu.flags.zf)
    {
        goto L_0x0043e6ff;
    }
    // 0043e6f2  39c8                   +cmp eax, ecx
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
    // 0043e6f4  7c09                   -jl 0x43e6ff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043e6ff;
    }
    // 0043e6f6  39d0                   +cmp eax, edx
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
    // 0043e6f8  7e0f                   -jle 0x43e709
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e709;
    }
    // 0043e6fa  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0043e6fd  eb0a                   -jmp 0x43e709
    goto L_0x0043e709;
L_0x0043e6ff:
    // 0043e6ff  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0043e702  eb05                   -jmp 0x43e709
    goto L_0x0043e709;
L_0x0043e704:
    // 0043e704  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x0043e709:
    // 0043e709  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 0043e70b  8d7d66                 -lea edi, [ebp + 0x66]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 0043e70e  8d7552                 -lea esi, [ebp + 0x52]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(82) /* 0x52 */);
    // 0043e711  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0043e714  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 0043e71a  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e71f  7558                   -jne 0x43e779
    if (!cpu.flags.zf)
    {
        goto L_0x0043e779;
    }
    // 0043e721  39c8                   +cmp eax, ecx
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
    // 0043e723  7d54                   -jge 0x43e779
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e779;
    }
    // 0043e725  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043e728  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 0043e72d  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 0043e733  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 0043e739  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e73e  750d                   -jne 0x43e74d
    if (!cpu.flags.zf)
    {
        goto L_0x0043e74d;
    }
    // 0043e740  39c8                   +cmp eax, ecx
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
    // 0043e742  7c09                   -jl 0x43e74d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043e74d;
    }
    // 0043e744  39d0                   +cmp eax, edx
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
    // 0043e746  7e09                   -jle 0x43e751
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e751;
    }
    // 0043e748  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 0043e74b  eb04                   -jmp 0x43e751
    goto L_0x0043e751;
L_0x0043e74d:
    // 0043e74d  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043e750  90                     -nop 
    ;
L_0x0043e751:
    // 0043e751  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0043e753  90                     -nop 
    ;
    // 0043e754  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 0043e75a  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 0043e760  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0043e765  750d                   -jne 0x43e774
    if (!cpu.flags.zf)
    {
        goto L_0x0043e774;
    }
    // 0043e767  39c8                   +cmp eax, ecx
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
    // 0043e769  7c09                   -jl 0x43e774
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043e774;
    }
    // 0043e76b  39d0                   +cmp eax, edx
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
    // 0043e76d  7e0f                   -jle 0x43e77e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e77e;
    }
    // 0043e76f  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0043e772  eb0a                   -jmp 0x43e77e
    goto L_0x0043e77e;
L_0x0043e774:
    // 0043e774  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0043e777  eb05                   -jmp 0x43e77e
    goto L_0x0043e77e;
L_0x0043e779:
    // 0043e779  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x0043e77e:
    // 0043e77e  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 0043e780  8d4d52                 -lea ecx, [ebp + 0x52]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(82) /* 0x52 */);
    // 0043e783  8d5d32                 -lea ebx, [ebp + 0x32]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(50) /* 0x32 */);
    // 0043e786  8d5512                 -lea edx, [ebp + 0x12]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(18) /* 0x12 */);
    // 0043e789  8d45f2                 -lea eax, [ebp - 0xe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 0043e78c  e84f2b0800             -call 0x4c12e0
    cpu.esp -= 4;
    sub_4c12e0(app, cpu);
    if (cpu.terminate) return;
    // 0043e791  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 0043e797  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e798  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e799  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e79a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e79b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e79c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e79d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_43e7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043e7a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043e7a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043e7a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043e7a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043e7a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043e7a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043e7a6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043e7a8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043e7ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e7ad  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043e7af  8b7040                 -mov esi, dword ptr [eax + 0x40]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0043e7b2  8b4044                 -mov eax, dword ptr [eax + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0043e7b5  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0043e7b8  8b4248                 -mov eax, dword ptr [edx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0043e7bb  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043e7be  668b828e000000         -mov ax, word ptr [edx + 0x8e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(142) /* 0x8e */);
    // 0043e7c5  663d0300               +cmp ax, 3
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(3 /*0x3*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043e7c9  0f8207010000           -jb 0x43e8d6
    if (cpu.flags.cf)
    {
        goto L_0x0043e8d6;
    }
    // 0043e7cf  760b                   -jbe 0x43e7dc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043e7dc;
    }
    // 0043e7d1  663d0400               +cmp ax, 4
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(4 /*0x4*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043e7d5  745c                   -je 0x43e833
    if (cpu.flags.zf)
    {
        goto L_0x0043e833;
    }
    // 0043e7d7  e9fa000000             -jmp 0x43e8d6
    goto L_0x0043e8d6;
L_0x0043e7dc:
    // 0043e7dc  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0043e7df  8b0de4e55500           -mov ecx, dword ptr [0x55e5e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 0043e7e5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e7e8  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e7ea  8b4264                 -mov eax, dword ptr [edx + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */);
    // 0043e7ed  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e7f0  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e7f2  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 0043e7f5  8b4206                 -mov eax, dword ptr [edx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0043e7f8  8b0de8e55500           -mov ecx, dword ptr [0x55e5e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0043e7fe  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e801  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e803  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043e805  8b4a62                 -mov ecx, dword ptr [edx + 0x62]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(98) /* 0x62 */);
    // 0043e808  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0043e80b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043e80d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043e80e  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043e811  8d5df4                 -lea ebx, [ebp - 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043e814  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043e815  8b4268                 -mov eax, dword ptr [edx + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(104) /* 0x68 */);
    // 0043e818  8b5266                 -mov edx, dword ptr [edx + 0x66]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(102) /* 0x66 */);
    // 0043e81b  8d4df8                 -lea ecx, [ebp - 8]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e81e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e821  c1f810                 +sar eax, 0x10
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
    // 0043e824  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0043e827  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e829  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043e82c  e8bff6ffff             -call 0x43def0
    cpu.esp -= 4;
    sub_43def0(app, cpu);
    if (cpu.terminate) return;
    // 0043e831  eb35                   -jmp 0x43e868
    goto L_0x0043e868;
L_0x0043e833:
    // 0043e833  8b4206                 -mov eax, dword ptr [edx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0043e836  8b0de8e55500           -mov ecx, dword ptr [0x55e5e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0043e83c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e83f  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e841  8b426a                 -mov eax, dword ptr [edx + 0x6a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(106) /* 0x6a */);
    // 0043e844  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e847  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e849  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043e84b  8b4a70                 -mov ecx, dword ptr [edx + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0043e84e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e850  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043e853  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e855  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e857  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043e85a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e85c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e85e  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0043e861  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043e864  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043e866  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0043e868:
    // 0043e868  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043e86a  7d04                   -jge 0x43e870
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e870;
    }
    // 0043e86c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043e86e  eb1c                   -jmp 0x43e88c
    goto L_0x0043e88c;
L_0x0043e870:
    // 0043e870  81feff000000           +cmp esi, 0xff
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e876  7e12                   -jle 0x43e88a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e88a;
    }
    // 0043e878  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0043e87d  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043e880  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e882  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043e884  7d13                   -jge 0x43e899
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e899;
    }
    // 0043e886  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043e888  eb20                   -jmp 0x43e8aa
    goto L_0x0043e8aa;
L_0x0043e88a:
    // 0043e88a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0043e88c:
    // 0043e88c  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043e88f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e891  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043e893  7d04                   -jge 0x43e899
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e899;
    }
    // 0043e895  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043e897  eb11                   -jmp 0x43e8aa
    goto L_0x0043e8aa;
L_0x0043e899:
    // 0043e899  81fbff000000           +cmp ebx, 0xff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e89f  7e07                   -jle 0x43e8a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e8a8;
    }
    // 0043e8a1  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0043e8a6  eb02                   -jmp 0x43e8aa
    goto L_0x0043e8aa;
L_0x0043e8a8:
    // 0043e8a8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0043e8aa:
    // 0043e8aa  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0043e8ad  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e8b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e8b2  7d04                   -jge 0x43e8b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e8b8;
    }
    // 0043e8b4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043e8b6  eb0c                   -jmp 0x43e8c4
    goto L_0x0043e8c4;
L_0x0043e8b8:
    // 0043e8b8  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e8bd  7e05                   -jle 0x43e8c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e8c4;
    }
    // 0043e8bf  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0043e8c4:
    // 0043e8c4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043e8c7  895740                 -mov dword ptr [edi + 0x40], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 0043e8ca  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043e8cd  894744                 -mov dword ptr [edi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0043e8d0  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e8d3  894748                 -mov dword ptr [edi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */) = cpu.eax;
L_0x0043e8d6:
    // 0043e8d6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043e8d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e8d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e8da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e8db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e8dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e8dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e8de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43e8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043e8e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043e8e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043e8e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043e8e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043e8e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043e8e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043e8e6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043e8e8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0043e8eb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e8ed  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043e8ef  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0043e8f2  8b1de4e55500           -mov ebx, dword ptr [0x55e5e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 0043e8f8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e8fb  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e8fd  8b4206                 -mov eax, dword ptr [edx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0043e900  8b35e8e55500           -mov esi, dword ptr [0x55e5e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0043e906  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e909  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e90b  8d421a                 -lea eax, [edx + 0x1a]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(26) /* 0x1a */);
    // 0043e90e  e8ddd80500             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 0043e913  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e915  750a                   -jne 0x43e921
    if (!cpu.flags.zf)
    {
        goto L_0x0043e921;
    }
    // 0043e917  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0043e91c  e9a1010000             -jmp 0x43eac2
    goto L_0x0043eac2;
L_0x0043e921:
    // 0043e921  8b427c                 -mov eax, dword ptr [edx + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */);
    // 0043e924  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e927  39c3                   +cmp ebx, eax
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
    // 0043e929  7e33                   -jle 0x43e95e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e95e;
    }
    // 0043e92b  8b7a7e                 -mov edi, dword ptr [edx + 0x7e]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(126) /* 0x7e */);
    // 0043e92e  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0043e931  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0043e933  39c3                   +cmp ebx, eax
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
    // 0043e935  7d27                   -jge 0x43e95e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e95e;
    }
    // 0043e937  8b427a                 -mov eax, dword ptr [edx + 0x7a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(122) /* 0x7a */);
    // 0043e93a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e93d  39c6                   +cmp esi, eax
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
    // 0043e93f  7e1d                   -jle 0x43e95e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e95e;
    }
    // 0043e941  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0043e947  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e94a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e94c  39c6                   +cmp esi, eax
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
    // 0043e94e  7d0e                   -jge 0x43e95e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e95e;
    }
    // 0043e950  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043e955  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043e957  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e958  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e959  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e95a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e95b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e95c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e95d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043e95e:
    // 0043e95e  8b8184000000           -mov eax, dword ptr [ecx + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 0043e964  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e967  39c3                   +cmp ebx, eax
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
    // 0043e969  7e39                   -jle 0x43e9a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e9a4;
    }
    // 0043e96b  8b9186000000           -mov edx, dword ptr [ecx + 0x86]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(134) /* 0x86 */);
    // 0043e971  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e974  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e976  39c3                   +cmp ebx, eax
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
    // 0043e978  7d2a                   -jge 0x43e9a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e9a4;
    }
    // 0043e97a  8b8182000000           -mov eax, dword ptr [ecx + 0x82]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(130) /* 0x82 */);
    // 0043e980  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e983  39c6                   +cmp esi, eax
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
    // 0043e985  7e1d                   -jle 0x43e9a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e9a4;
    }
    // 0043e987  8b9188000000           -mov edx, dword ptr [ecx + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(136) /* 0x88 */);
    // 0043e98d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e990  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e992  39c6                   +cmp esi, eax
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
    // 0043e994  7d0e                   -jge 0x43e9a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e9a4;
    }
    // 0043e996  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0043e99b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043e99d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e99e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e99f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e9a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e9a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e9a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e9a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043e9a4:
    // 0043e9a4  8b4164                 -mov eax, dword ptr [ecx + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    // 0043e9a7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e9aa  39c3                   +cmp ebx, eax
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
    // 0043e9ac  0f8ed4000000           -jle 0x43ea86
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ea86;
    }
    // 0043e9b2  8b5166                 -mov edx, dword ptr [ecx + 0x66]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(102) /* 0x66 */);
    // 0043e9b5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043e9b8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043e9ba  39c3                   +cmp ebx, eax
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
    // 0043e9bc  0f8dc4000000           -jge 0x43ea86
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ea86;
    }
    // 0043e9c2  8b4162                 -mov eax, dword ptr [ecx + 0x62]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(98) /* 0x62 */);
    // 0043e9c5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e9c8  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0043e9cb  39c6                   +cmp esi, eax
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
    // 0043e9cd  0f8eb3000000           -jle 0x43ea86
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ea86;
    }
    // 0043e9d3  8b4168                 -mov eax, dword ptr [ecx + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */);
    // 0043e9d6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043e9d9  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0043e9dc  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e9df  0345f4                 -add eax, dword ptr [ebp - 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0043e9e2  39c6                   +cmp esi, eax
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
    // 0043e9e4  0f8d9c000000           -jge 0x43ea86
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ea86;
    }
    // 0043e9ea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e9ec  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043e9ef  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e9f1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043e9f3  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043e9f6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043e9f8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043e9fa  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e9fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e9fe  7d04                   -jge 0x43ea04
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ea04;
    }
    // 0043ea00  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043ea02  eb09                   -jmp 0x43ea0d
    goto L_0x0043ea0d;
L_0x0043ea04:
    // 0043ea04  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043ea07  39d0                   +cmp eax, edx
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
    // 0043ea09  7e02                   -jle 0x43ea0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ea0d;
    }
    // 0043ea0b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0043ea0d:
    // 0043ea0d  8b5168                 -mov edx, dword ptr [ecx + 0x68]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */);
    // 0043ea10  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043ea13  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043ea16  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043ea19  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0043ea1c  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043ea1f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043ea21  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0043ea24  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043ea27  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043ea2a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043ea2c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043ea2e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043ea31  f77df0                 -idiv dword ptr [ebp - 0x10]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043ea34  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0043ea39  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043ea3b  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0043ea3e  c745fcff000000         -mov dword ptr [ebp - 4], 0xff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 255 /*0xff*/;
    // 0043ea45  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043ea47  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043ea4a  f77dfc                 -idiv dword ptr [ebp - 4]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043ea4d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043ea4f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043ea51  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0043ea54  8b5164                 -mov edx, dword ptr [ecx + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    // 0043ea57  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043ea5a  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0043ea5d  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043ea60  0355fc                 -add edx, dword ptr [ebp - 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0043ea63  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0043ea65  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 0043ea68  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043ea6b  8b7dec                 -mov edi, dword ptr [ebp - 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043ea6e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043ea70  39fb                   +cmp ebx, edi
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
    // 0043ea72  7c12                   -jl 0x43ea86
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043ea86;
    }
    // 0043ea74  39c3                   +cmp ebx, eax
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
    // 0043ea76  7f0e                   -jg 0x43ea86
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043ea86;
    }
    // 0043ea78  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0043ea7d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043ea7f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ea80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ea81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ea82  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ea83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ea84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ea85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043ea86:
    // 0043ea86  8b416c                 -mov eax, dword ptr [ecx + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */);
    // 0043ea89  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043ea8c  39c3                   +cmp ebx, eax
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
    // 0043ea8e  7e30                   -jle 0x43eac0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043eac0;
    }
    // 0043ea90  8b516e                 -mov edx, dword ptr [ecx + 0x6e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(110) /* 0x6e */);
    // 0043ea93  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043ea96  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043ea98  39c3                   +cmp ebx, eax
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
    // 0043ea9a  7d24                   -jge 0x43eac0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043eac0;
    }
    // 0043ea9c  8b416a                 -mov eax, dword ptr [ecx + 0x6a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(106) /* 0x6a */);
    // 0043ea9f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043eaa2  39c6                   +cmp esi, eax
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
    // 0043eaa4  7e1a                   -jle 0x43eac0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043eac0;
    }
    // 0043eaa6  8b5170                 -mov edx, dword ptr [ecx + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */);
    // 0043eaa9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043eaac  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043eaae  39c6                   +cmp esi, eax
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
    // 0043eab0  7d0e                   -jge 0x43eac0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043eac0;
    }
    // 0043eab2  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0043eab7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043eab9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eaba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eabb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eabc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eabd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eabe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eabf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043eac0:
    // 0043eac0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043eac2:
    // 0043eac2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043eac4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eac5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eac6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eac7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eac8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eac9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eaca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_43ead0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ead0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043ead1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ead2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043ead3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ead4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ead6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043ead8  668b908e000000         -mov dx, word ptr [eax + 0x8e]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(142) /* 0x8e */);
    // 0043eadf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043eae1  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0043eae4  750c                   -jne 0x43eaf2
    if (!cpu.flags.zf)
    {
        goto L_0x0043eaf2;
    }
    // 0043eae6  e8f5fdffff             -call 0x43e8e0
    cpu.esp -= 4;
    sub_43e8e0(app, cpu);
    if (cpu.terminate) return;
    // 0043eaeb  6689818c000000         -mov word ptr [ecx + 0x8c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(140) /* 0x8c */) = cpu.ax;
L_0x0043eaf2:
    // 0043eaf2  6683bb8c00000000       +cmp word ptr [ebx + 0x8c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(140) /* 0x8c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043eafa  7418                   -je 0x43eb14
    if (cpu.flags.zf)
    {
        goto L_0x0043eb14;
    }
    // 0043eafc  e87fd50500             -call 0x49c080
    cpu.esp -= 4;
    sub_49c080(app, cpu);
    if (cpu.terminate) return;
    // 0043eb01  83f80d                 +cmp eax, 0xd
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
    // 0043eb04  750e                   -jne 0x43eb14
    if (!cpu.flags.zf)
    {
        goto L_0x0043eb14;
    }
    // 0043eb06  668b838c000000         -mov ax, word ptr [ebx + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(140) /* 0x8c */);
    // 0043eb0d  6689838e000000         -mov word ptr [ebx + 0x8e], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(142) /* 0x8e */) = cpu.ax;
L_0x0043eb14:
    // 0043eb14  6683bb8e00000000       +cmp word ptr [ebx + 0x8e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043eb1c  7462                   -je 0x43eb80
    if (cpu.flags.zf)
    {
        goto L_0x0043eb80;
    }
    // 0043eb1e  e85dd50500             -call 0x49c080
    cpu.esp -= 4;
    sub_49c080(app, cpu);
    if (cpu.terminate) return;
    // 0043eb23  83f80d                 +cmp eax, 0xd
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
    // 0043eb26  7509                   -jne 0x43eb31
    if (!cpu.flags.zf)
    {
        goto L_0x0043eb31;
    }
    // 0043eb28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043eb2a  e871fcffff             -call 0x43e7a0
    cpu.esp -= 4;
    sub_43e7a0(app, cpu);
    if (cpu.terminate) return;
    // 0043eb2f  eb4f                   -jmp 0x43eb80
    goto L_0x0043eb80;
L_0x0043eb31:
    // 0043eb31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043eb33  0fbf938e000000         -movsx edx, word ptr [ebx + 0x8e]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(142) /* 0x8e */)));
    // 0043eb3a  e8a1fdffff             -call 0x43e8e0
    cpu.esp -= 4;
    sub_43e8e0(app, cpu);
    if (cpu.terminate) return;
    // 0043eb3f  39d0                   +cmp eax, edx
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
    // 0043eb41  7534                   -jne 0x43eb77
    if (!cpu.flags.zf)
    {
        goto L_0x0043eb77;
    }
    // 0043eb43  668b838e000000         -mov ax, word ptr [ebx + 0x8e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(142) /* 0x8e */);
    // 0043eb4a  6683f801               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043eb4e  740e                   -je 0x43eb5e
    if (cpu.flags.zf)
    {
        goto L_0x0043eb5e;
    }
    // 0043eb50  6683f802               +cmp ax, 2
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043eb54  7411                   -je 0x43eb67
    if (cpu.flags.zf)
    {
        goto L_0x0043eb67;
    }
    // 0043eb56  6683f805               +cmp ax, 5
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(5 /*0x5*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043eb5a  7414                   -je 0x43eb70
    if (cpu.flags.zf)
    {
        goto L_0x0043eb70;
    }
    // 0043eb5c  eb19                   -jmp 0x43eb77
    goto L_0x0043eb77;
L_0x0043eb5e:
    // 0043eb5e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043eb60  e82bf2ffff             -call 0x43dd90
    cpu.esp -= 4;
    sub_43dd90(app, cpu);
    if (cpu.terminate) return;
    // 0043eb65  eb10                   -jmp 0x43eb77
    goto L_0x0043eb77;
L_0x0043eb67:
    // 0043eb67  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043eb69  e822f1ffff             -call 0x43dc90
    cpu.esp -= 4;
    sub_43dc90(app, cpu);
    if (cpu.terminate) return;
    // 0043eb6e  eb07                   -jmp 0x43eb77
    goto L_0x0043eb77;
L_0x0043eb70:
    // 0043eb70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043eb72  e859f2ffff             -call 0x43ddd0
    cpu.esp -= 4;
    sub_43ddd0(app, cpu);
    if (cpu.terminate) return;
L_0x0043eb77:
    // 0043eb77  66c7838e0000000000     -mov word ptr [ebx + 0x8e], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(142) /* 0x8e */) = 0 /*0x0*/;
L_0x0043eb80:
    // 0043eb80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eb81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eb82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eb83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eb84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43eb86(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043eb86  90                     -nop 
    ;
    // 0043eb87  90                     -nop 
    ;
    // 0043eb88  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043eb89  e8e2590000             -call 0x444570
    cpu.esp -= 4;
    sub_444570(app, cpu);
    if (cpu.terminate) return;
    // 0043eb8e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043eb90  7409                   -je 0x43eb9b
    if (cpu.flags.zf)
    {
        goto L_0x0043eb9b;
    }
    // 0043eb92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043eb93  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043eb95  e83696fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043eb9a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0043eb9b:
    // 0043eb9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eb9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43eb88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043eb88;
    // 0043eb86  90                     -nop 
    ;
    // 0043eb87  90                     -nop 
    ;
L_entry_0x0043eb88:
    // 0043eb88  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043eb89  e8e2590000             -call 0x444570
    cpu.esp -= 4;
    sub_444570(app, cpu);
    if (cpu.terminate) return;
    // 0043eb8e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043eb90  7409                   -je 0x43eb9b
    if (cpu.flags.zf)
    {
        goto L_0x0043eb9b;
    }
    // 0043eb92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043eb93  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043eb95  e83696fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043eb9a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0043eb9b:
    // 0043eb9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eb9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43eb9e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043eb9e  90                     -nop 
    ;
    // 0043eb9f  90                     -nop 
    ;
    // 0043eba0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043eba1  e8ba650000             -call 0x445160
    cpu.esp -= 4;
    sub_445160(app, cpu);
    if (cpu.terminate) return;
    // 0043eba6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043eba8  7409                   -je 0x43ebb3
    if (cpu.flags.zf)
    {
        goto L_0x0043ebb3;
    }
    // 0043ebaa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043ebab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043ebad  e81e96fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ebb2  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0043ebb3:
    // 0043ebb3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ebb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43eba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043eba0;
    // 0043eb9e  90                     -nop 
    ;
    // 0043eb9f  90                     -nop 
    ;
L_entry_0x0043eba0:
    // 0043eba0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043eba1  e8ba650000             -call 0x445160
    cpu.esp -= 4;
    sub_445160(app, cpu);
    if (cpu.terminate) return;
    // 0043eba6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043eba8  7409                   -je 0x43ebb3
    if (cpu.flags.zf)
    {
        goto L_0x0043ebb3;
    }
    // 0043ebaa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043ebab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043ebad  e81e96fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ebb2  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0043ebb3:
    // 0043ebb3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ebb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43ebb6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ebb6  90                     -nop 
    ;
    // 0043ebb7  90                     -nop 
    ;
    // 0043ebb8  90                     -nop 
    ;
    // 0043ebb9  90                     -nop 
    ;
    // 0043ebba  90                     -nop 
    ;
    // 0043ebbb  90                     -nop 
    ;
    // 0043ebbc  90                     -nop 
    ;
    // 0043ebbd  90                     -nop 
    ;
    // 0043ebbe  90                     -nop 
    ;
    // 0043ebbf  90                     -nop 
    ;
    // 0043ebc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043ebc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ebc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ebc3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ebc5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043ebc7  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043ebcc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ebce  e88dba0000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043ebd3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ebd5  7460                   -je 0x43ec37
    if (cpu.flags.zf)
    {
        goto L_0x0043ec37;
    }
    // 0043ebd7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ebd9  e8f2feffff             -call 0x43ead0
    cpu.esp -= 4;
    sub_43ead0(app, cpu);
    if (cpu.terminate) return;
    // 0043ebde  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ebe0  e8cbf3ffff             -call 0x43dfb0
    cpu.esp -= 4;
    sub_43dfb0(app, cpu);
    if (cpu.terminate) return;
    // 0043ebe5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ebe7  e854f4ffff             -call 0x43e040
    cpu.esp -= 4;
    sub_43e040(app, cpu);
    if (cpu.terminate) return;
    // 0043ebec  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 0043ebf3  740f                   -je 0x43ec04
    if (cpu.flags.zf)
    {
        goto L_0x0043ec04;
    }
    // 0043ebf5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043ebfa  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0043ebff  e8fc2cffff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x0043ec04:
    // 0043ec04  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043ec06  e805f7ffff             -call 0x43e310
    cpu.esp -= 4;
    sub_43e310(app, cpu);
    if (cpu.terminate) return;
    // 0043ec0b  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 0043ec12  740c                   -je 0x43ec20
    if (cpu.flags.zf)
    {
        goto L_0x0043ec20;
    }
    // 0043ec14  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0043ec19  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043ec1b  e8e02cffff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x0043ec20:
    // 0043ec20  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043ec22  e869f8ffff             -call 0x43e490
    cpu.esp -= 4;
    sub_43e490(app, cpu);
    if (cpu.terminate) return;
    // 0043ec27  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043ec29  e8c2f5ffff             -call 0x43e1f0
    cpu.esp -= 4;
    sub_43e1f0(app, cpu);
    if (cpu.terminate) return;
    // 0043ec2e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043ec30  e89bf4ffff             -call 0x43e0d0
    cpu.esp -= 4;
    sub_43e0d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ec35  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043ec37:
    // 0043ec37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ec38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ec39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ec3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43ebc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043ebc0;
    // 0043ebb6  90                     -nop 
    ;
    // 0043ebb7  90                     -nop 
    ;
    // 0043ebb8  90                     -nop 
    ;
    // 0043ebb9  90                     -nop 
    ;
    // 0043ebba  90                     -nop 
    ;
    // 0043ebbb  90                     -nop 
    ;
    // 0043ebbc  90                     -nop 
    ;
    // 0043ebbd  90                     -nop 
    ;
    // 0043ebbe  90                     -nop 
    ;
    // 0043ebbf  90                     -nop 
    ;
L_entry_0x0043ebc0:
    // 0043ebc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043ebc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ebc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ebc3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ebc5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043ebc7  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043ebcc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ebce  e88dba0000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043ebd3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ebd5  7460                   -je 0x43ec37
    if (cpu.flags.zf)
    {
        goto L_0x0043ec37;
    }
    // 0043ebd7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ebd9  e8f2feffff             -call 0x43ead0
    cpu.esp -= 4;
    sub_43ead0(app, cpu);
    if (cpu.terminate) return;
    // 0043ebde  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ebe0  e8cbf3ffff             -call 0x43dfb0
    cpu.esp -= 4;
    sub_43dfb0(app, cpu);
    if (cpu.terminate) return;
    // 0043ebe5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ebe7  e854f4ffff             -call 0x43e040
    cpu.esp -= 4;
    sub_43e040(app, cpu);
    if (cpu.terminate) return;
    // 0043ebec  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 0043ebf3  740f                   -je 0x43ec04
    if (cpu.flags.zf)
    {
        goto L_0x0043ec04;
    }
    // 0043ebf5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043ebfa  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0043ebff  e8fc2cffff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x0043ec04:
    // 0043ec04  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043ec06  e805f7ffff             -call 0x43e310
    cpu.esp -= 4;
    sub_43e310(app, cpu);
    if (cpu.terminate) return;
    // 0043ec0b  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 0043ec12  740c                   -je 0x43ec20
    if (cpu.flags.zf)
    {
        goto L_0x0043ec20;
    }
    // 0043ec14  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0043ec19  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043ec1b  e8e02cffff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x0043ec20:
    // 0043ec20  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043ec22  e869f8ffff             -call 0x43e490
    cpu.esp -= 4;
    sub_43e490(app, cpu);
    if (cpu.terminate) return;
    // 0043ec27  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043ec29  e8c2f5ffff             -call 0x43e1f0
    cpu.esp -= 4;
    sub_43e1f0(app, cpu);
    if (cpu.terminate) return;
    // 0043ec2e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043ec30  e89bf4ffff             -call 0x43e0d0
    cpu.esp -= 4;
    sub_43e0d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ec35  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043ec37:
    // 0043ec37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ec38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ec39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ec3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_43ec40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ec40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ec41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043ec42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043ec43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ec44  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ec46  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043ec48  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0043ec4a  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043ec4f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ec51  e80aba0000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043ec56  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043ec58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ec5a  0f841a030000           -je 0x43ef7a
    if (cpu.flags.zf)
    {
        return sub_43ef7a(app, cpu);
    }
    // 0043ec60  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043ec62  6681ff0049             +cmp di, 0x4900
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18688 /*0x4900*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ec67  7244                   -jb 0x43ecad
    if (cpu.flags.cf)
    {
        goto L_0x0043ecad;
    }
    // 0043ec69  0f864d010000           -jbe 0x43edbc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_43edbc(app, cpu);
    }
    // 0043ec6f  6681ff004d             +cmp di, 0x4d00
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ec74  7227                   -jb 0x43ec9d
    if (cpu.flags.cf)
    {
        goto L_0x0043ec9d;
    }
    // 0043ec76  0f8617010000           -jbe 0x43ed93
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_43ed93(app, cpu);
    }
    // 0043ec7c  6681ff0050             +cmp di, 0x5000
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20480 /*0x5000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ec81  0f82f1020000           -jb 0x43ef78
    if (cpu.flags.cf)
    {
        return sub_43ef78(app, cpu);
    }
    // 0043ec87  0f86b4000000           -jbe 0x43ed41
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_43ed41(app, cpu);
    }
    // 0043ec8d  6681ff0051             +cmp di, 0x5100
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20736 /*0x5100*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ec92  0f8463010000           -je 0x43edfb
    if (cpu.flags.zf)
    {
        return sub_43edfb(app, cpu);
    }
    // 0043ec98  e9db020000             -jmp 0x43ef78
    return sub_43ef78(app, cpu);
L_0x0043ec9d:
    // 0043ec9d  6681ff004b             +cmp di, 0x4b00
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043eca2  0f84c2000000           -je 0x43ed6a
    if (cpu.flags.zf)
    {
        return sub_43ed6a(app, cpu);
    }
    // 0043eca8  e9cb020000             -jmp 0x43ef78
    return sub_43ef78(app, cpu);
L_0x0043ecad:
    // 0043ecad  663d0d00               +cmp ax, 0xd
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ecb1  721f                   -jb 0x43ecd2
    if (cpu.flags.cf)
    {
        goto L_0x0043ecd2;
    }
    // 0043ecb3  0f866c020000           -jbe 0x43ef25
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_43ef25(app, cpu);
    }
    // 0043ecb9  663d1b00               +cmp ax, 0x1b
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ecbd  0f82b5020000           -jb 0x43ef78
    if (cpu.flags.cf)
    {
        return sub_43ef78(app, cpu);
    }
    // 0043ecc3  761e                   -jbe 0x43ece3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043ece3;
    }
    // 0043ecc5  663d0048               +cmp ax, 0x4800
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18432 /*0x4800*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ecc9  7437                   -je 0x43ed02
    if (cpu.flags.zf)
    {
        goto L_0x0043ed02;
    }
    // 0043eccb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043eccd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ecce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043eccf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ecd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ecd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043ecd2:
    // 0043ecd2  663d0900               +cmp ax, 9
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(9 /*0x9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ecd6  0f8448010000           -je 0x43ee24
    if (cpu.flags.zf)
    {
        return sub_43ee24(app, cpu);
    }
    // 0043ecdc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ecde  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ecdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ece0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ece1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ece2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043ece3:
    // 0043ece3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043ece5  e8e6f0ffff             -call 0x43ddd0
    cpu.esp -= 4;
    sub_43ddd0(app, cpu);
    if (cpu.terminate) return;
    // 0043ecea  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ecef  e975020000             -jmp 0x43ef69
    return sub_43ef69(app, cpu);
    // 0043ecf4  90                     -nop 
    ;
    // 0043ecf5  90                     -nop 
    ;
    // 0043ecf6  90                     -nop 
    ;
    // 0043ecf7  90                     -nop 
    ;
    // 0043ecf8  90                     -nop 
    ;
    // 0043ecf9  90                     -nop 
    ;
    // 0043ecfa  90                     -nop 
    ;
    // 0043ecfb  90                     -nop 
    ;
    // 0043ecfc  90                     -nop 
    ;
    // 0043ecfd  90                     -nop 
    ;
    // 0043ecfe  90                     -nop 
    ;
    // 0043ecff  90                     -nop 
    ;
    // 0043ed00  90                     -nop 
    ;
    // 0043ed01  90                     -nop 
    ;
L_0x0043ed02:
    // 0043ed02  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ed07  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0043ed0a  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ed0f  0f8d63020000           -jge 0x43ef78
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_43ef78(app, cpu);
    }
    // 0043ed15  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043ed18  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ed1d  7e04                   -jle 0x43ed23
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ed23;
    }
    // 0043ed1f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043ed21  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
L_0x0043ed23:
    // 0043ed23  894348                 -mov dword ptr [ebx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0043ed26  e937020000             -jmp 0x43ef62
    return sub_43ef62(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_43ed2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ed2c  90                     -nop 
    ;
    // 0043ed2d  90                     -nop 
    ;
    // 0043ed2e  90                     -nop 
    ;
    // 0043ed2f  90                     -nop 
    ;
    // 0043ed30  90                     -nop 
    ;
    // 0043ed31  90                     -nop 
    ;
    // 0043ed32  90                     -nop 
    ;
    // 0043ed33  90                     -nop 
    ;
    // 0043ed34  90                     -nop 
    ;
    // 0043ed35  90                     -nop 
    ;
    // 0043ed36  90                     -nop 
    ;
    // 0043ed37  90                     -nop 
    ;
    // 0043ed38  90                     -nop 
    ;
    // 0043ed39  90                     -nop 
    ;
    // 0043ed3a  90                     -nop 
    ;
    // 0043ed3b  90                     -nop 
    ;
    // 0043ed3c  90                     -nop 
    ;
    // 0043ed3d  90                     -nop 
    ;
    // 0043ed3e  90                     -nop 
    ;
    // 0043ed3f  90                     -nop 
    ;
    // 0043ed40  90                     -nop 
    ;
    // 0043ed41  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ed46  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0043ed49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ed4b  0f8e27020000           -jle 0x43ef78
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_43ef78(app, cpu);
    }
    // 0043ed51  83e80a                 -sub eax, 0xa
    (cpu.eax) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043ed54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ed56  7d02                   -jge 0x43ed5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ed5a;
    }
    // 0043ed58  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
L_0x0043ed5a:
    // 0043ed5a  894348                 -mov dword ptr [ebx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0043ed5d  e900020000             -jmp 0x43ef62
    return sub_43ef62(app, cpu);
}

/* align: skip  */
void Application::sub_43ed41(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043ed41;
    // 0043ed2c  90                     -nop 
    ;
    // 0043ed2d  90                     -nop 
    ;
    // 0043ed2e  90                     -nop 
    ;
    // 0043ed2f  90                     -nop 
    ;
    // 0043ed30  90                     -nop 
    ;
    // 0043ed31  90                     -nop 
    ;
    // 0043ed32  90                     -nop 
    ;
    // 0043ed33  90                     -nop 
    ;
    // 0043ed34  90                     -nop 
    ;
    // 0043ed35  90                     -nop 
    ;
    // 0043ed36  90                     -nop 
    ;
    // 0043ed37  90                     -nop 
    ;
    // 0043ed38  90                     -nop 
    ;
    // 0043ed39  90                     -nop 
    ;
    // 0043ed3a  90                     -nop 
    ;
    // 0043ed3b  90                     -nop 
    ;
    // 0043ed3c  90                     -nop 
    ;
    // 0043ed3d  90                     -nop 
    ;
    // 0043ed3e  90                     -nop 
    ;
    // 0043ed3f  90                     -nop 
    ;
    // 0043ed40  90                     -nop 
    ;
L_entry_0x0043ed41:
    // 0043ed41  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ed46  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0043ed49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ed4b  0f8e27020000           -jle 0x43ef78
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_43ef78(app, cpu);
    }
    // 0043ed51  83e80a                 -sub eax, 0xa
    (cpu.eax) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043ed54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ed56  7d02                   -jge 0x43ed5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ed5a;
    }
    // 0043ed58  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
L_0x0043ed5a:
    // 0043ed5a  894348                 -mov dword ptr [ebx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0043ed5d  e900020000             -jmp 0x43ef62
    return sub_43ef62(app, cpu);
}

/* align: skip  */
void Application::sub_43ed62(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ed62  90                     -nop 
    ;
    // 0043ed63  90                     -nop 
    ;
    // 0043ed64  90                     -nop 
    ;
    // 0043ed65  90                     -nop 
    ;
    // 0043ed66  90                     -nop 
    ;
    // 0043ed67  90                     -nop 
    ;
    // 0043ed68  90                     -nop 
    ;
    // 0043ed69  90                     -nop 
    ;
    // 0043ed6a  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ed6f  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0043ed72  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ed77  0f8dfb010000           -jge 0x43ef78
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_43ef78(app, cpu);
    }
    // 0043ed7d  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043ed80  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ed85  7e04                   -jle 0x43ed8b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ed8b;
    }
    // 0043ed87  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043ed89  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
L_0x0043ed8b:
    // 0043ed8b  894344                 -mov dword ptr [ebx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0043ed8e  e9cf010000             -jmp 0x43ef62
    return sub_43ef62(app, cpu);
}

/* align: skip  */
void Application::sub_43ed6a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043ed6a;
    // 0043ed62  90                     -nop 
    ;
    // 0043ed63  90                     -nop 
    ;
    // 0043ed64  90                     -nop 
    ;
    // 0043ed65  90                     -nop 
    ;
    // 0043ed66  90                     -nop 
    ;
    // 0043ed67  90                     -nop 
    ;
    // 0043ed68  90                     -nop 
    ;
    // 0043ed69  90                     -nop 
    ;
L_entry_0x0043ed6a:
    // 0043ed6a  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ed6f  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0043ed72  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ed77  0f8dfb010000           -jge 0x43ef78
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_43ef78(app, cpu);
    }
    // 0043ed7d  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043ed80  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ed85  7e04                   -jle 0x43ed8b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ed8b;
    }
    // 0043ed87  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043ed89  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
L_0x0043ed8b:
    // 0043ed8b  894344                 -mov dword ptr [ebx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0043ed8e  e9cf010000             -jmp 0x43ef62
    return sub_43ef62(app, cpu);
}

/* align: skip  */
void Application::sub_43ed93(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ed93  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ed98  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0043ed9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ed9d  0f8ed5010000           -jle 0x43ef78
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_43ef78(app, cpu);
    }
    // 0043eda3  83e80a                 -sub eax, 0xa
    (cpu.eax) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043eda6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043eda8  7d02                   -jge 0x43edac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043edac;
    }
    // 0043edaa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
L_0x0043edac:
    // 0043edac  894344                 -mov dword ptr [ebx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0043edaf  e9ae010000             -jmp 0x43ef62
    return sub_43ef62(app, cpu);
}

/* align: skip  */
void Application::sub_43edb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043edb4  90                     -nop 
    ;
    // 0043edb5  90                     -nop 
    ;
    // 0043edb6  90                     -nop 
    ;
    // 0043edb7  90                     -nop 
    ;
    // 0043edb8  90                     -nop 
    ;
    // 0043edb9  90                     -nop 
    ;
    // 0043edba  90                     -nop 
    ;
    // 0043edbb  90                     -nop 
    ;
    // 0043edbc  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043edc1  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0043edc4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043edc6  0f8eac010000           -jle 0x43ef78
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_43ef78(app, cpu);
    }
    // 0043edcc  83e80a                 -sub eax, 0xa
    (cpu.eax) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043edcf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043edd1  7d02                   -jge 0x43edd5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043edd5;
    }
    // 0043edd3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
L_0x0043edd5:
    // 0043edd5  894340                 -mov dword ptr [ebx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0043edd8  e985010000             -jmp 0x43ef62
    return sub_43ef62(app, cpu);
}

/* align: skip  */
void Application::sub_43edbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043edbc;
    // 0043edb4  90                     -nop 
    ;
    // 0043edb5  90                     -nop 
    ;
    // 0043edb6  90                     -nop 
    ;
    // 0043edb7  90                     -nop 
    ;
    // 0043edb8  90                     -nop 
    ;
    // 0043edb9  90                     -nop 
    ;
    // 0043edba  90                     -nop 
    ;
    // 0043edbb  90                     -nop 
    ;
L_entry_0x0043edbc:
    // 0043edbc  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043edc1  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0043edc4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043edc6  0f8eac010000           -jle 0x43ef78
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_43ef78(app, cpu);
    }
    // 0043edcc  83e80a                 -sub eax, 0xa
    (cpu.eax) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043edcf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043edd1  7d02                   -jge 0x43edd5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043edd5;
    }
    // 0043edd3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
L_0x0043edd5:
    // 0043edd5  894340                 -mov dword ptr [ebx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0043edd8  e985010000             -jmp 0x43ef62
    return sub_43ef62(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_43edde(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043edde  90                     -nop 
    ;
    // 0043eddf  90                     -nop 
    ;
    // 0043ede0  90                     -nop 
    ;
    // 0043ede1  90                     -nop 
    ;
    // 0043ede2  90                     -nop 
    ;
    // 0043ede3  90                     -nop 
    ;
    // 0043ede4  90                     -nop 
    ;
    // 0043ede5  90                     -nop 
    ;
    // 0043ede6  90                     -nop 
    ;
    // 0043ede7  90                     -nop 
    ;
    // 0043ede8  90                     -nop 
    ;
    // 0043ede9  90                     -nop 
    ;
    // 0043edea  90                     -nop 
    ;
    // 0043edeb  90                     -nop 
    ;
    // 0043edec  90                     -nop 
    ;
    // 0043eded  90                     -nop 
    ;
    // 0043edee  90                     -nop 
    ;
    // 0043edef  90                     -nop 
    ;
    // 0043edf0  90                     -nop 
    ;
    // 0043edf1  90                     -nop 
    ;
    // 0043edf2  90                     -nop 
    ;
    // 0043edf3  90                     -nop 
    ;
    // 0043edf4  90                     -nop 
    ;
    // 0043edf5  90                     -nop 
    ;
    // 0043edf6  90                     -nop 
    ;
    // 0043edf7  90                     -nop 
    ;
    // 0043edf8  90                     -nop 
    ;
    // 0043edf9  90                     -nop 
    ;
    // 0043edfa  90                     -nop 
    ;
    // 0043edfb  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ee00  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0043ee03  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ee08  0f8d6a010000           -jge 0x43ef78
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_43ef78(app, cpu);
    }
    // 0043ee0e  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043ee11  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ee16  7e04                   -jle 0x43ee1c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ee1c;
    }
    // 0043ee18  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043ee1a  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
L_0x0043ee1c:
    // 0043ee1c  894340                 -mov dword ptr [ebx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0043ee1f  e93e010000             -jmp 0x43ef62
    return sub_43ef62(app, cpu);
}

/* align: skip  */
void Application::sub_43edfb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043edfb;
    // 0043edde  90                     -nop 
    ;
    // 0043eddf  90                     -nop 
    ;
    // 0043ede0  90                     -nop 
    ;
    // 0043ede1  90                     -nop 
    ;
    // 0043ede2  90                     -nop 
    ;
    // 0043ede3  90                     -nop 
    ;
    // 0043ede4  90                     -nop 
    ;
    // 0043ede5  90                     -nop 
    ;
    // 0043ede6  90                     -nop 
    ;
    // 0043ede7  90                     -nop 
    ;
    // 0043ede8  90                     -nop 
    ;
    // 0043ede9  90                     -nop 
    ;
    // 0043edea  90                     -nop 
    ;
    // 0043edeb  90                     -nop 
    ;
    // 0043edec  90                     -nop 
    ;
    // 0043eded  90                     -nop 
    ;
    // 0043edee  90                     -nop 
    ;
    // 0043edef  90                     -nop 
    ;
    // 0043edf0  90                     -nop 
    ;
    // 0043edf1  90                     -nop 
    ;
    // 0043edf2  90                     -nop 
    ;
    // 0043edf3  90                     -nop 
    ;
    // 0043edf4  90                     -nop 
    ;
    // 0043edf5  90                     -nop 
    ;
    // 0043edf6  90                     -nop 
    ;
    // 0043edf7  90                     -nop 
    ;
    // 0043edf8  90                     -nop 
    ;
    // 0043edf9  90                     -nop 
    ;
    // 0043edfa  90                     -nop 
    ;
L_entry_0x0043edfb:
    // 0043edfb  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ee00  8b4640                 -mov eax, dword ptr [esi + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0043ee03  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ee08  0f8d6a010000           -jge 0x43ef78
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_43ef78(app, cpu);
    }
    // 0043ee0e  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0043ee11  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ee16  7e04                   -jle 0x43ee1c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ee1c;
    }
    // 0043ee18  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043ee1a  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
L_0x0043ee1c:
    // 0043ee1c  894340                 -mov dword ptr [ebx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0043ee1f  e93e010000             -jmp 0x43ef62
    return sub_43ef62(app, cpu);
}

/* align: skip  */
void Application::sub_43ee24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ee24  668b968c000000         -mov dx, word ptr [esi + 0x8c]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0043ee2b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ee30  6683fa01               +cmp dx, 1
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ee34  750b                   -jne 0x43ee41
    if (!cpu.flags.zf)
    {
        goto L_0x0043ee41;
    }
    // 0043ee36  66c7868c0000000200     -mov word ptr [esi + 0x8c], 2
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(140) /* 0x8c */) = 2 /*0x2*/;
    // 0043ee3f  eb09                   -jmp 0x43ee4a
    goto L_0x0043ee4a;
L_0x0043ee41:
    // 0043ee41  66c7868c0000000100     -mov word ptr [esi + 0x8c], 1
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(140) /* 0x8c */) = 1 /*0x1*/;
L_0x0043ee4a:
    // 0043ee4a  668b838c000000         -mov ax, word ptr [ebx + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(140) /* 0x8c */);
    // 0043ee51  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ee55  0f821d010000           -jb 0x43ef78
    if (cpu.flags.cf)
    {
        return sub_43ef78(app, cpu);
    }
    // 0043ee5b  760d                   -jbe 0x43ee6a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043ee6a;
    }
    // 0043ee5d  663d0200               +cmp ax, 2
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ee61  7444                   -je 0x43eea7
    if (cpu.flags.zf)
    {
        goto L_0x0043eea7;
    }
    // 0043ee63  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ee65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ee66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ee67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ee68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ee69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043ee6a:
    // 0043ee6a  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0043ee6d  8b437c                 -mov eax, dword ptr [ebx + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(124) /* 0x7c */);
    // 0043ee70  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043ee73  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043ee76  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0043ee79  8b537e                 -mov edx, dword ptr [ebx + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(126) /* 0x7e */);
    // 0043ee7c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043ee7f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043ee81  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043ee84  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043ee86  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043ee88  8b537a                 -mov edx, dword ptr [ebx + 0x7a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(122) /* 0x7a */);
    // 0043ee8b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ee8d  8b4306                 -mov eax, dword ptr [ebx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0043ee90  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043ee93  c1f810                 +sar eax, 0x10
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
    // 0043ee96  8935e4e55500           -mov dword ptr [0x55e5e4], esi
    app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */) = cpu.esi;
    // 0043ee9c  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0043ee9f  8b9380000000           -mov edx, dword ptr [ebx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(128) /* 0x80 */);
    // 0043eea5  eb44                   -jmp 0x43eeeb
    goto L_0x0043eeeb;
L_0x0043eea7:
    // 0043eea7  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0043eeaa  8b8384000000           -mov eax, dword ptr [ebx + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(132) /* 0x84 */);
    // 0043eeb0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043eeb3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043eeb6  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0043eeb9  8b9386000000           -mov edx, dword ptr [ebx + 0x86]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(134) /* 0x86 */);
    // 0043eebf  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043eec2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043eec4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043eec7  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043eec9  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043eecb  8b9382000000           -mov edx, dword ptr [ebx + 0x82]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(130) /* 0x82 */);
    // 0043eed1  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043eed3  8b4306                 -mov eax, dword ptr [ebx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0043eed6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043eed9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043eedc  8935e4e55500           -mov dword ptr [0x55e5e4], esi
    app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */) = cpu.esi;
    // 0043eee2  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0043eee5  8b9388000000           -mov edx, dword ptr [ebx + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(136) /* 0x88 */);
L_0x0043eeeb:
    // 0043eeeb  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043eeee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043eef0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043eef3  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043eef5  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043eef7  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0043eefc  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043eefe  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 0043ef03  8935e8e55500           -mov dword ptr [0x55e5e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */) = cpu.esi;
    // 0043ef09  e8c292fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ef0e  8b15e8e55500           -mov edx, dword ptr [0x55e5e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0043ef14  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 0043ef19  e8a2d00500             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
    // 0043ef1e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ef20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43ef25(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ef25  668b868c000000         -mov ax, word ptr [esi + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0043ef2c  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ef30  7246                   -jb 0x43ef78
    if (cpu.flags.cf)
    {
        return sub_43ef78(app, cpu);
    }
    // 0043ef32  7620                   -jbe 0x43ef54
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_43ef54(app, cpu);
    }
    // 0043ef34  663d0200               +cmp ax, 2
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043ef38  740c                   -je 0x43ef46
    if (cpu.flags.zf)
    {
        return sub_43ef46(app, cpu);
    }
    // 0043ef3a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ef3c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef3d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef3e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43ef42(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ef42  90                     -nop 
    ;
    // 0043ef43  90                     -nop 
    ;
    // 0043ef44  90                     -nop 
    ;
    // 0043ef45  90                     -nop 
    ;
    // 0043ef46  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043ef48  e843edffff             -call 0x43dc90
    cpu.esp -= 4;
    sub_43dc90(app, cpu);
    if (cpu.terminate) return;
    // 0043ef4d  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ef52  eb15                   -jmp 0x43ef69
    goto L_0x0043ef69;
    // 0043ef54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043ef56  e835eeffff             -call 0x43dd90
    cpu.esp -= 4;
    sub_43dd90(app, cpu);
    if (cpu.terminate) return;
    // 0043ef5b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ef60  eb07                   -jmp 0x43ef69
    goto L_0x0043ef69;
    // 0043ef62  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 0043ef67  eb05                   -jmp 0x43ef6e
    goto L_0x0043ef6e;
L_0x0043ef69:
    // 0043ef69  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043ef6e:
    // 0043ef6e  e85d92fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ef73  eb03                   -jmp 0x43ef78
    return sub_43ef78(app, cpu);
}

/* align: skip  */
void Application::sub_43ef69(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043ef69;
    // 0043ef42  90                     -nop 
    ;
    // 0043ef43  90                     -nop 
    ;
    // 0043ef44  90                     -nop 
    ;
    // 0043ef45  90                     -nop 
    ;
    // 0043ef46  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043ef48  e843edffff             -call 0x43dc90
    cpu.esp -= 4;
    sub_43dc90(app, cpu);
    if (cpu.terminate) return;
    // 0043ef4d  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ef52  eb15                   -jmp 0x43ef69
    goto L_0x0043ef69;
    // 0043ef54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043ef56  e835eeffff             -call 0x43dd90
    cpu.esp -= 4;
    sub_43dd90(app, cpu);
    if (cpu.terminate) return;
    // 0043ef5b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ef60  eb07                   -jmp 0x43ef69
    goto L_0x0043ef69;
    // 0043ef62  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 0043ef67  eb05                   -jmp 0x43ef6e
    goto L_0x0043ef6e;
L_0x0043ef69:
L_entry_0x0043ef69:
    // 0043ef69  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043ef6e:
    // 0043ef6e  e85d92fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ef73  eb03                   -jmp 0x43ef78
    return sub_43ef78(app, cpu);
}

/* align: skip  */
void Application::sub_43ef62(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043ef62;
    // 0043ef42  90                     -nop 
    ;
    // 0043ef43  90                     -nop 
    ;
    // 0043ef44  90                     -nop 
    ;
    // 0043ef45  90                     -nop 
    ;
    // 0043ef46  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043ef48  e843edffff             -call 0x43dc90
    cpu.esp -= 4;
    sub_43dc90(app, cpu);
    if (cpu.terminate) return;
    // 0043ef4d  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ef52  eb15                   -jmp 0x43ef69
    goto L_0x0043ef69;
    // 0043ef54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043ef56  e835eeffff             -call 0x43dd90
    cpu.esp -= 4;
    sub_43dd90(app, cpu);
    if (cpu.terminate) return;
    // 0043ef5b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ef60  eb07                   -jmp 0x43ef69
    goto L_0x0043ef69;
L_entry_0x0043ef62:
    // 0043ef62  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 0043ef67  eb05                   -jmp 0x43ef6e
    goto L_0x0043ef6e;
L_0x0043ef69:
    // 0043ef69  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043ef6e:
    // 0043ef6e  e85d92fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ef73  eb03                   -jmp 0x43ef78
    return sub_43ef78(app, cpu);
}

/* align: skip  */
void Application::sub_43ef54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043ef54;
    // 0043ef42  90                     -nop 
    ;
    // 0043ef43  90                     -nop 
    ;
    // 0043ef44  90                     -nop 
    ;
    // 0043ef45  90                     -nop 
    ;
    // 0043ef46  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043ef48  e843edffff             -call 0x43dc90
    cpu.esp -= 4;
    sub_43dc90(app, cpu);
    if (cpu.terminate) return;
    // 0043ef4d  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ef52  eb15                   -jmp 0x43ef69
    goto L_0x0043ef69;
L_entry_0x0043ef54:
    // 0043ef54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043ef56  e835eeffff             -call 0x43dd90
    cpu.esp -= 4;
    sub_43dd90(app, cpu);
    if (cpu.terminate) return;
    // 0043ef5b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ef60  eb07                   -jmp 0x43ef69
    goto L_0x0043ef69;
    // 0043ef62  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 0043ef67  eb05                   -jmp 0x43ef6e
    goto L_0x0043ef6e;
L_0x0043ef69:
    // 0043ef69  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043ef6e:
    // 0043ef6e  e85d92fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ef73  eb03                   -jmp 0x43ef78
    return sub_43ef78(app, cpu);
}

/* align: skip  */
void Application::sub_43ef46(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043ef46;
    // 0043ef42  90                     -nop 
    ;
    // 0043ef43  90                     -nop 
    ;
    // 0043ef44  90                     -nop 
    ;
    // 0043ef45  90                     -nop 
    ;
L_entry_0x0043ef46:
    // 0043ef46  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043ef48  e843edffff             -call 0x43dc90
    cpu.esp -= 4;
    sub_43dc90(app, cpu);
    if (cpu.terminate) return;
    // 0043ef4d  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ef52  eb15                   -jmp 0x43ef69
    goto L_0x0043ef69;
    // 0043ef54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043ef56  e835eeffff             -call 0x43dd90
    cpu.esp -= 4;
    sub_43dd90(app, cpu);
    if (cpu.terminate) return;
    // 0043ef5b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0043ef60  eb07                   -jmp 0x43ef69
    goto L_0x0043ef69;
    // 0043ef62  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 0043ef67  eb05                   -jmp 0x43ef6e
    goto L_0x0043ef6e;
L_0x0043ef69:
    // 0043ef69  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043ef6e:
    // 0043ef6e  e85d92fdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ef73  eb03                   -jmp 0x43ef78
    return sub_43ef78(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_43ef76(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ef76  90                     -nop 
    ;
    // 0043ef77  90                     -nop 
    ;
    // 0043ef78  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ef7a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43ef7a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043ef7a;
    // 0043ef76  90                     -nop 
    ;
    // 0043ef77  90                     -nop 
    ;
    // 0043ef78  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_entry_0x0043ef7a:
    // 0043ef7a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43ef78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043ef78;
    // 0043ef76  90                     -nop 
    ;
    // 0043ef77  90                     -nop 
    ;
L_entry_0x0043ef78:
    // 0043ef78  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043ef7a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ef7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43ef80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ef80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ef81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043ef82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043ef83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ef84  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ef86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043ef88  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043ef8d  e8ceb60000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043ef92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ef94  7450                   -je 0x43efe6
    if (cpu.flags.zf)
    {
        goto L_0x0043efe6;
    }
    // 0043ef96  668b918e000000         -mov dx, word ptr [ecx + 0x8e]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(142) /* 0x8e */);
    // 0043ef9d  6683fa04               +cmp dx, 4
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(4 /*0x4*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043efa1  750a                   -jne 0x43efad
    if (!cpu.flags.zf)
    {
        goto L_0x0043efad;
    }
    // 0043efa3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0043efa8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efa9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efaa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043efad:
    // 0043efad  6683fa03               +cmp dx, 3
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(3 /*0x3*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043efb1  750a                   -jne 0x43efbd
    if (!cpu.flags.zf)
    {
        goto L_0x0043efbd;
    }
    // 0043efb3  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0043efb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efb9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efbb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efbc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043efbd:
    // 0043efbd  668bb18c000000         -mov si, word ptr [ecx + 0x8c]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 0043efc4  6683fe04               +cmp si, 4
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(4 /*0x4*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043efc8  750a                   -jne 0x43efd4
    if (!cpu.flags.zf)
    {
        goto L_0x0043efd4;
    }
    // 0043efca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043efcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efd0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efd1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efd3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043efd4:
    // 0043efd4  6683fe03               +cmp si, 3
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(3 /*0x3*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043efd8  750a                   -jne 0x43efe4
    if (!cpu.flags.zf)
    {
        goto L_0x0043efe4;
    }
    // 0043efda  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0043efdf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efe0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efe1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efe2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efe3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043efe4:
    // 0043efe4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043efe6:
    // 0043efe6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efe7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efe8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efe9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043efea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_43eff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043eff0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043eff1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043eff2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043eff3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043eff5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043eff7  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043effc  e85fb60000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043f001  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f003  7420                   -je 0x43f025
    if (cpu.flags.zf)
    {
        goto L_0x0043f025;
    }
    // 0043f005  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0043f009  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 0043f00d  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0043f011  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 0043f015  668b413e               -mov ax, word ptr [ecx + 0x3e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 0043f019  66894120               -mov word ptr [ecx + 0x20], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ax;
    // 0043f01d  668b413c               -mov ax, word ptr [ecx + 0x3c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 0043f021  6689411e               -mov word ptr [ecx + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.ax;
L_0x0043f025:
    // 0043f025  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f026  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f027  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f028  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_43f030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f033  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f034  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f036  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043f038  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043f03d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043f03f  e81cb60000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043f044  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f046  0f8404010000           -je 0x43f150
    if (cpu.flags.zf)
    {
        goto L_0x0043f150;
    }
    // 0043f04c  66837b3e00             +cmp word ptr [ebx + 0x3e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(62) /* 0x3e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043f051  7506                   -jne 0x43f059
    if (!cpu.flags.zf)
    {
        goto L_0x0043f059;
    }
    // 0043f053  66c7433e5000           -mov word ptr [ebx + 0x3e], 0x50
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(62) /* 0x3e */) = 80 /*0x50*/;
L_0x0043f059:
    // 0043f059  6683793c00             +cmp word ptr [ecx + 0x3c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(60) /* 0x3c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043f05e  7506                   -jne 0x43f066
    if (!cpu.flags.zf)
    {
        goto L_0x0043f066;
    }
    // 0043f060  66c7413c5000           -mov word ptr [ecx + 0x3c], 0x50
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(60) /* 0x3c */) = 80 /*0x50*/;
L_0x0043f066:
    // 0043f066  c741407f000000         -mov dword ptr [ecx + 0x40], 0x7f
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 127 /*0x7f*/;
    // 0043f06d  c74144df000000         -mov dword ptr [ecx + 0x44], 0xdf
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = 223 /*0xdf*/;
    // 0043f074  c741484f000000         -mov dword ptr [ecx + 0x48], 0x4f
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = 79 /*0x4f*/;
    // 0043f07b  c7414c7f000000         -mov dword ptr [ecx + 0x4c], 0x7f
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = 127 /*0x7f*/;
    // 0043f082  b808785300             -mov eax, 0x537808
    cpu.eax = 5470216 /*0x537808*/;
    // 0043f087  c7416000000000         -mov dword ptr [ecx + 0x60], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = 0 /*0x0*/;
    // 0043f08e  e81d6d0900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0043f093  66898190000000         -mov word ptr [ecx + 0x90], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.ax;
    // 0043f09a  b810785300             -mov eax, 0x537810
    cpu.eax = 5470224 /*0x537810*/;
    // 0043f09f  e80c6d0900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0043f0a4  66898192000000         -mov word ptr [ecx + 0x92], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(146) /* 0x92 */) = cpu.ax;
    // 0043f0ab  b818785300             -mov eax, 0x537818
    cpu.eax = 5470232 /*0x537818*/;
    // 0043f0b0  e8fb6c0900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0043f0b5  66898194000000         -mov word ptr [ecx + 0x94], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.ax;
    // 0043f0bc  b820785300             -mov eax, 0x537820
    cpu.eax = 5470240 /*0x537820*/;
    // 0043f0c1  e8ea6c0900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0043f0c6  66898196000000         -mov word ptr [ecx + 0x96], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(150) /* 0x96 */) = cpu.ax;
    // 0043f0cd  b828785300             -mov eax, 0x537828
    cpu.eax = 5470248 /*0x537828*/;
    // 0043f0d2  e8d96c0900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0043f0d7  66c7818c0000000000     -mov word ptr [ecx + 0x8c], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(140) /* 0x8c */) = 0 /*0x0*/;
    // 0043f0e0  66898198000000         -mov word ptr [ecx + 0x98], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(152) /* 0x98 */) = cpu.ax;
    // 0043f0e7  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 0043f0ec  8b81a0000000           -mov eax, dword ptr [ecx + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0043f0f2  66c7818e0000000000     -mov word ptr [ecx + 0x8e], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(142) /* 0x8e */) = 0 /*0x0*/;
    // 0043f0fb  e8202f0100             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 0043f100  050f000000             -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0043f105  66898180000000         -mov word ptr [ecx + 0x80], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(128) /* 0x80 */) = cpu.ax;
    // 0043f10c  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 0043f111  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 0043f117  66c781820000001200     -mov word ptr [ecx + 0x82], 0x12
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(130) /* 0x82 */) = 18 /*0x12*/;
    // 0043f120  e8fb2e0100             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 0043f125  050f000000             -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0043f12a  66898188000000         -mov word ptr [ecx + 0x88], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(136) /* 0x88 */) = cpu.ax;
    // 0043f131  8a6105                 -mov ah, byte ptr [ecx + 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0043f134  80cc10                 -or ah, 0x10
    cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0043f137  66c7818a0000001200     -mov word ptr [ecx + 0x8a], 0x12
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(138) /* 0x8a */) = 18 /*0x12*/;
    // 0043f140  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0043f142  886105                 -mov byte ptr [ecx + 5], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.ah;
    // 0043f145  80e2fb                 -and dl, 0xfb
    cpu.dl &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0043f148  885105                 -mov byte ptr [ecx + 5], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0043f14b  e8d0e9ffff             -call 0x43db20
    cpu.esp -= 4;
    sub_43db20(app, cpu);
    if (cpu.terminate) return;
L_0x0043f150:
    // 0043f150  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f151  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f152  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f153  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f154  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_43f160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f160  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f161  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f162  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f164  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
    // 0043f169  e8f2b40000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0043f16e  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f170  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f171  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f172  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
/* data blob: 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 */
void Application::sub_43f1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f1f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f1f1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f1f3  e8289f0900             -call 0x4d9120
    cpu.esp -= 4;
    sub_4d9120(app, cpu);
    if (cpu.terminate) return;
    // 0043f1f8  e8b3bc0000             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 0043f1fd  e8eeb20000             -call 0x44a4f0
    cpu.esp -= 4;
    sub_44a4f0(app, cpu);
    if (cpu.terminate) return;
    // 0043f202  e879ce0500             -call 0x49c080
    cpu.esp -= 4;
    sub_49c080(app, cpu);
    if (cpu.terminate) return;
    // 0043f207  e884b90900             -call 0x4dab90
    cpu.esp -= 4;
    sub_4dab90(app, cpu);
    if (cpu.terminate) return;
    // 0043f20c  e82f9f0900             -call 0x4d9140
    cpu.esp -= 4;
    sub_4d9140(app, cpu);
    if (cpu.terminate) return;
    // 0043f211  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f213  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f214  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_43f220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f222  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f223  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f224  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f225  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f227  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043f229  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0043f22e  b9f0f14300             -mov ecx, 0x43f1f0
    cpu.ecx = 4452848 /*0x43f1f0*/;
    // 0043f233  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043f238  bafcd26f00             -mov edx, 0x6fd2fc
    cpu.edx = 7328508 /*0x6fd2fc*/;
    // 0043f23d  e89ece0500             -call 0x49c0e0
    cpu.esp -= 4;
    sub_49c0e0(app, cpu);
    if (cpu.terminate) return;
    // 0043f242  b880010000             -mov eax, 0x180
    cpu.eax = 384 /*0x180*/;
    // 0043f247  e884f10500             -call 0x49e3d0
    cpu.esp -= 4;
    sub_49e3d0(app, cpu);
    if (cpu.terminate) return;
    // 0043f24c  a3f03f5f00             -mov dword ptr [0x5f3ff0], eax
    app->getMemory<x86::reg32>(x86::reg32(6242288) /* 0x5f3ff0 */) = cpu.eax;
    // 0043f251  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f253  e888ce0500             -call 0x49c0e0
    cpu.esp -= 4;
    sub_49c0e0(app, cpu);
    if (cpu.terminate) return;
    // 0043f258  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0043f25d  0500050000             -add eax, 0x500
    (cpu.eax) += x86::reg32(x86::sreg32(1280 /*0x500*/));
    // 0043f262  8b5670                 -mov edx, dword ptr [esi + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 0043f265  a3ec3f5f00             -mov dword ptr [0x5f3fec], eax
    app->getMemory<x86::reg32>(x86::reg32(6242284) /* 0x5f3fec */) = cpu.eax;
    // 0043f26a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043f26c  740e                   -je 0x43f27c
    if (cpu.flags.zf)
    {
        goto L_0x0043f27c;
    }
    // 0043f26e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043f270  e81b260a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043f275  c7467000000000         -mov dword ptr [esi + 0x70], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
L_0x0043f27c:
    // 0043f27c  a1f03f5f00             -mov eax, dword ptr [0x5f3ff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242288) /* 0x5f3ff0 */);
    // 0043f281  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 0043f284  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0043f287  7448                   -je 0x43f2d1
    if (cpu.flags.zf)
    {
        goto L_0x0043f2d1;
    }
    // 0043f289  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0043f28c  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0043f28f  40                     -inc eax
    (cpu.eax)++;
    // 0043f290  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 0043f297  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043f299  b830785300             -mov eax, 0x537830
    cpu.eax = 5470256 /*0x537830*/;
    // 0043f29e  e87d230a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0043f2a3  894670                 -mov dword ptr [esi + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 0043f2a6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043f2a8:
    // 0043f2a8  8b15f03f5f00           -mov edx, dword ptr [0x5f3ff0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242288) /* 0x5f3ff0 */);
    // 0043f2ae  0fbf0a                 -movsx ecx, word ptr [edx]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx)));
    // 0043f2b1  39c8                   +cmp eax, ecx
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
    // 0043f2b3  7d53                   -jge 0x43f308
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f308;
    }
    // 0043f2b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043f2b7  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0043f2ba  c1e106                 +shl ecx, 6
    {
        x86::reg8 tmp = 6 /*0x6*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0043f2bd  8d1c0a                 -lea ebx, [edx + ecx]
    cpu.ebx = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 0043f2c0  8b4e70                 -mov ecx, dword ptr [esi + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 0043f2c3  891cc1                 -mov dword ptr [ecx + eax*8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8) = cpu.ebx;
    // 0043f2c6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043f2c7  8b4e70                 -mov ecx, dword ptr [esi + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 0043f2ca  c644c1fc00             -mov byte ptr [ecx + eax*8 - 4], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 8) = 0 /*0x0*/;
    // 0043f2cf  ebd7                   -jmp 0x43f2a8
    goto L_0x0043f2a8;
L_0x0043f2d1:
    // 0043f2d1  c7464801000000         -mov dword ptr [esi + 0x48], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = 1 /*0x1*/;
    // 0043f2d8  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0043f2db  40                     -inc eax
    (cpu.eax)++;
    // 0043f2dc  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 0043f2e3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043f2e5  b830785300             -mov eax, 0x537830
    cpu.eax = 5470256 /*0x537830*/;
    // 0043f2ea  e831230a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0043f2ef  894670                 -mov dword ptr [esi + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 0043f2f2  b8bd000000             -mov eax, 0xbd
    cpu.eax = 189 /*0xbd*/;
    // 0043f2f7  e854250900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f2fc  8b5670                 -mov edx, dword ptr [esi + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 0043f2ff  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0043f301  8b4670                 -mov eax, dword ptr [esi + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 0043f304  c6400400               -mov byte ptr [eax + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x0043f308:
    // 0043f308  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043f30a  e8c1400200             -call 0x4633d0
    cpu.esp -= 4;
    sub_4633d0(app, cpu);
    if (cpu.terminate) return;
    // 0043f30f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f310  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f311  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f312  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f313  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f314  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_43f320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f322  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f323  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f324  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043f325  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f326  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f328  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043f32a  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0043f32f  b8f4565500             -mov eax, 0x5556f4
    cpu.eax = 5592820 /*0x5556f4*/;
    // 0043f334  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f336  e805130a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043f33b  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0043f340  b808575500             -mov eax, 0x555708
    cpu.eax = 5592840 /*0x555708*/;
    // 0043f345  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f347  e8f4120a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043f34c  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0043f351  b81c575500             -mov eax, 0x55571c
    cpu.eax = 5592860 /*0x55571c*/;
    // 0043f356  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f358  e8e3120a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043f35d  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 0043f362  b824575500             -mov eax, 0x555724
    cpu.eax = 5592868 /*0x555724*/;
    // 0043f367  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f369  e8d2120a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043f36e  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 0043f373  e8d8240900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f378  a31c575500             -mov dword ptr [0x55571c], eax
    app->getMemory<x86::reg32>(x86::reg32(5592860) /* 0x55571c */) = cpu.eax;
    // 0043f37d  b81b000000             -mov eax, 0x1b
    cpu.eax = 27 /*0x1b*/;
    // 0043f382  e8c9240900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f387  a3f4565500             -mov dword ptr [0x5556f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5592820) /* 0x5556f4 */) = cpu.eax;
    // 0043f38c  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 0043f391  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f393  e8b8240900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f398  a3f8565500             -mov dword ptr [0x5556f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5592824) /* 0x5556f8 */) = cpu.eax;
    // 0043f39d  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 0043f3a2  8915fc565500           -mov dword ptr [0x5556fc], edx
    app->getMemory<x86::reg32>(x86::reg32(5592828) /* 0x5556fc */) = cpu.edx;
    // 0043f3a8  e8a3240900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f3ad  a300575500             -mov dword ptr [0x555700], eax
    app->getMemory<x86::reg32>(x86::reg32(5592832) /* 0x555700 */) = cpu.eax;
    // 0043f3b2  b81e000000             -mov eax, 0x1e
    cpu.eax = 30 /*0x1e*/;
    // 0043f3b7  e894240900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f3bc  a304575500             -mov dword ptr [0x555704], eax
    app->getMemory<x86::reg32>(x86::reg32(5592836) /* 0x555704 */) = cpu.eax;
    // 0043f3c1  b81f000000             -mov eax, 0x1f
    cpu.eax = 31 /*0x1f*/;
    // 0043f3c6  e885240900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f3cb  a308575500             -mov dword ptr [0x555708], eax
    app->getMemory<x86::reg32>(x86::reg32(5592840) /* 0x555708 */) = cpu.eax;
    // 0043f3d0  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 0043f3d5  e876240900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f3da  a30c575500             -mov dword ptr [0x55570c], eax
    app->getMemory<x86::reg32>(x86::reg32(5592844) /* 0x55570c */) = cpu.eax;
    // 0043f3df  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 0043f3e4  891510575500           -mov dword ptr [0x555710], edx
    app->getMemory<x86::reg32>(x86::reg32(5592848) /* 0x555710 */) = cpu.edx;
    // 0043f3ea  e861240900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f3ef  a314575500             -mov dword ptr [0x555714], eax
    app->getMemory<x86::reg32>(x86::reg32(5592852) /* 0x555714 */) = cpu.eax;
    // 0043f3f4  b822000000             -mov eax, 0x22
    cpu.eax = 34 /*0x22*/;
    // 0043f3f9  e852240900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f3fe  a318575500             -mov dword ptr [0x555718], eax
    app->getMemory<x86::reg32>(x86::reg32(5592856) /* 0x555718 */) = cpu.eax;
    // 0043f403  b8f9000000             -mov eax, 0xf9
    cpu.eax = 249 /*0xf9*/;
    // 0043f408  e843240900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f40d  a324575500             -mov dword ptr [0x555724], eax
    app->getMemory<x86::reg32>(x86::reg32(5592868) /* 0x555724 */) = cpu.eax;
    // 0043f412  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0043f417  e834240900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f41c  a328575500             -mov dword ptr [0x555728], eax
    app->getMemory<x86::reg32>(x86::reg32(5592872) /* 0x555728 */) = cpu.eax;
    // 0043f421  890de83f5f00           -mov dword ptr [0x5f3fe8], ecx
    app->getMemory<x86::reg32>(x86::reg32(6242280) /* 0x5f3fe8 */) = cpu.ecx;
    // 0043f427  83f901                 +cmp ecx, 1
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
    // 0043f42a  7209                   -jb 0x43f435
    if (cpu.flags.cf)
    {
        goto L_0x0043f435;
    }
    // 0043f42c  761e                   -jbe 0x43f44c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043f44c;
    }
    // 0043f42e  83f902                 +cmp ecx, 2
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f431  742b                   -je 0x43f45e
    if (cpu.flags.zf)
    {
        goto L_0x0043f45e;
    }
    // 0043f433  eb37                   -jmp 0x43f46c
    goto L_0x0043f46c;
L_0x0043f435:
    // 0043f435  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043f437  7533                   -jne 0x43f46c
    if (!cpu.flags.zf)
    {
        goto L_0x0043f46c;
    }
    // 0043f439  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0043f43e  89150cd56f00           -mov dword ptr [0x6fd50c], edx
    app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */) = cpu.edx;
    // 0043f444  8935e4227a00           -mov dword ptr [0x7a22e4], esi
    app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */) = cpu.esi;
    // 0043f44a  eb30                   -jmp 0x43f47c
    goto L_0x0043f47c;
L_0x0043f44c:
    // 0043f44c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043f451  89150cd56f00           -mov dword ptr [0x6fd50c], edx
    app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */) = cpu.edx;
    // 0043f457  a3e4227a00             -mov dword ptr [0x7a22e4], eax
    app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */) = cpu.eax;
    // 0043f45c  eb1e                   -jmp 0x43f47c
    goto L_0x0043f47c;
L_0x0043f45e:
    // 0043f45e  89150cd56f00           -mov dword ptr [0x6fd50c], edx
    app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */) = cpu.edx;
    // 0043f464  8915e4227a00           -mov dword ptr [0x7a22e4], edx
    app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */) = cpu.edx;
    // 0043f46a  eb09                   -jmp 0x43f475
    goto L_0x0043f475;
L_0x0043f46c:
    // 0043f46c  833de4227a0000         +cmp dword ptr [0x7a22e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f473  7507                   -jne 0x43f47c
    if (!cpu.flags.zf)
    {
        goto L_0x0043f47c;
    }
L_0x0043f475:
    // 0043f475  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043f47a  eb02                   -jmp 0x43f47e
    goto L_0x0043f47e;
L_0x0043f47c:
    // 0043f47c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043f47e:
    // 0043f47e  8b3d0cd56f00           -mov edi, dword ptr [0x6fd50c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */);
    // 0043f484  a3e43f5f00             -mov dword ptr [0x5f3fe4], eax
    app->getMemory<x86::reg32>(x86::reg32(6242276) /* 0x5f3fe4 */) = cpu.eax;
    // 0043f489  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0043f48b  7507                   -jne 0x43f494
    if (!cpu.flags.zf)
    {
        goto L_0x0043f494;
    }
    // 0043f48d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043f492  eb02                   -jmp 0x43f496
    goto L_0x0043f496;
L_0x0043f494:
    // 0043f494  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043f496:
    // 0043f496  68e0f74300             -push 0x43f7e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4454368 /*0x43f7e0*/;
    cpu.esp -= 4;
    // 0043f49b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043f49d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043f49f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043f4a1  6824575500             -push 0x555724
    app->getMemory<x86::reg32>(cpu.esp-4) = 5592868 /*0x555724*/;
    cpu.esp -= 4;
    // 0043f4a6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0043f4a8  b9f4565500             -mov ecx, 0x5556f4
    cpu.ecx = 5592820 /*0x5556f4*/;
    // 0043f4ad  6808575500             -push 0x555708
    app->getMemory<x86::reg32>(cpu.esp-4) = 5592840 /*0x555708*/;
    cpu.esp -= 4;
    // 0043f4b2  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0043f4b7  ba1c575500             -mov edx, 0x55571c
    cpu.edx = 5592860 /*0x55571c*/;
    // 0043f4bc  68e0565500             -push 0x5556e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5592800 /*0x5556e0*/;
    cpu.esp -= 4;
    // 0043f4c1  a3e03f5f00             -mov dword ptr [0x5f3fe0], eax
    app->getMemory<x86::reg32>(x86::reg32(6242272) /* 0x5f3fe0 */) = cpu.eax;
    // 0043f4c6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043f4cb  e880620000             -call 0x445750
    cpu.esp -= 4;
    sub_445750(app, cpu);
    if (cpu.terminate) return;
    // 0043f4d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_43f4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f4e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f4e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f4e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f4e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f4e4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f4e6  b817000000             -mov eax, 0x17
    cpu.eax = 23 /*0x17*/;
    // 0043f4eb  e860230900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f4f0  a308405f00             -mov dword ptr [0x5f4008], eax
    app->getMemory<x86::reg32>(x86::reg32(6242312) /* 0x5f4008 */) = cpu.eax;
    // 0043f4f5  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0043f4fa  e851230900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f4ff  a30c405f00             -mov dword ptr [0x5f400c], eax
    app->getMemory<x86::reg32>(x86::reg32(6242316) /* 0x5f400c */) = cpu.eax;
    // 0043f504  b8f9000000             -mov eax, 0xf9
    cpu.eax = 249 /*0xf9*/;
    // 0043f509  e842230900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f50e  a310405f00             -mov dword ptr [0x5f4010], eax
    app->getMemory<x86::reg32>(x86::reg32(6242320) /* 0x5f4010 */) = cpu.eax;
    // 0043f513  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0043f518  e833230900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f51d  6880f64300             -push 0x43f680
    app->getMemory<x86::reg32>(cpu.esp-4) = 4454016 /*0x43f680*/;
    cpu.esp -= 4;
    // 0043f522  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0043f524  6a1d                   -push 0x1d
    app->getMemory<x86::reg32>(cpu.esp-4) = 29 /*0x1d*/;
    cpu.esp -= 4;
    // 0043f526  b910405f00             -mov ecx, 0x5f4010
    cpu.ecx = 6242320 /*0x5f4010*/;
    // 0043f52b  687ebb6f00             -push 0x6fbb7e
    app->getMemory<x86::reg32>(cpu.esp-4) = 7322494 /*0x6fbb7e*/;
    cpu.esp -= 4;
    // 0043f530  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0043f535  ba08405f00             -mov edx, 0x5f4008
    cpu.edx = 6242312 /*0x5f4008*/;
    // 0043f53a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043f53c  a314405f00             -mov dword ptr [0x5f4014], eax
    app->getMemory<x86::reg32>(x86::reg32(6242324) /* 0x5f4014 */) = cpu.eax;
    // 0043f541  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043f543  e8d8560000             -call 0x444c20
    cpu.esp -= 4;
    sub_444c20(app, cpu);
    if (cpu.terminate) return;
    // 0043f548  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f549  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f54a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f54b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f54c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_43f550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f550  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f551  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f552  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f553  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f554  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043f555  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f556  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f558  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 0043f55d  bf1c405f00             -mov edi, 0x5f401c
    cpu.edi = 6242332 /*0x5f401c*/;
    // 0043f562  e8e9220900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f567  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043f569  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043f56a:
    // 0043f56a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043f56c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043f56e  3c00                   +cmp al, 0
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
    // 0043f570  7410                   -je 0x43f582
    if (cpu.flags.zf)
    {
        goto L_0x0043f582;
    }
    // 0043f572  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043f575  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043f578  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043f57b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043f57e  3c00                   +cmp al, 0
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
    // 0043f580  75e8                   -jne 0x43f56a
    if (!cpu.flags.zf)
    {
        goto L_0x0043f56a;
    }
L_0x0043f582:
    // 0043f582  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f583  be34785300             -mov esi, 0x537834
    cpu.esi = 5470260 /*0x537834*/;
    // 0043f588  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043f589  2bc9                   +sub ecx, ecx
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
    // 0043f58b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043f58c  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043f58e  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0043f590  4f                     -dec edi
    (cpu.edi)--;
L_0x0043f591:
    // 0043f591  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043f593  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043f595  3c00                   +cmp al, 0
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
    // 0043f597  7410                   -je 0x43f5a9
    if (cpu.flags.zf)
    {
        goto L_0x0043f5a9;
    }
    // 0043f599  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043f59c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043f59f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043f5a2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043f5a5  3c00                   +cmp al, 0
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
    // 0043f5a7  75e8                   -jne 0x43f591
    if (!cpu.flags.zf)
    {
        goto L_0x0043f591;
    }
L_0x0043f5a9:
    // 0043f5a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f5aa  a15cbb6f00             -mov eax, dword ptr [0x6fbb5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322460) /* 0x6fbb5c */);
    // 0043f5af  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f5b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043f5b3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043f5b6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f5b8  05f43d5f00             +add eax, 0x5f3df4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6241780 /*0x5f3df4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043f5bd  7433                   -je 0x43f5f2
    if (cpu.flags.zf)
    {
        goto L_0x0043f5f2;
    }
    // 0043f5bf  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043f5c1  49                     -dec ecx
    (cpu.ecx)--;
    // 0043f5c2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043f5c4  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0043f5c6  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0043f5c8  49                     -dec ecx
    (cpu.ecx)--;
    // 0043f5c9  b81e000000             -mov eax, 0x1e
    cpu.eax = 30 /*0x1e*/;
    // 0043f5ce  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043f5d0  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0043f5d3  a15cbb6f00             -mov eax, dword ptr [0x6fbb5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322460) /* 0x6fbb5c */);
    // 0043f5d8  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f5da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043f5dc  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043f5df  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f5e1  baf43d5f00             -mov edx, 0x5f3df4
    cpu.edx = 6241780 /*0x5f3df4*/;
    // 0043f5e6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f5e8  b81c405f00             -mov eax, 0x5f401c
    cpu.eax = 6242332 /*0x5f401c*/;
    // 0043f5ed  e8fef70a00             -call 0x4eedf0
    cpu.esp -= 4;
    sub_4eedf0(app, cpu);
    if (cpu.terminate) return;
L_0x0043f5f2:
    // 0043f5f2  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0043f5f4  882539405f00           -mov byte ptr [0x5f4039], ah
    app->getMemory<x86::reg8>(x86::reg32(6242361) /* 0x5f4039 */) = cpu.ah;
    // 0043f5fa  b81c405f00             -mov eax, 0x5f401c
    cpu.eax = 6242332 /*0x5f401c*/;
    // 0043f5ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f600  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f601  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f602  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f603  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f604  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f605  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_43f610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f610  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f611  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f613  a158bb6f00             -mov eax, dword ptr [0x6fbb58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322456) /* 0x6fbb58 */);
    // 0043f618  40                     -inc eax
    (cpu.eax)++;
    // 0043f619  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043f61a  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0043f61f  e82c220900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043f624  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043f625  6838785300             -push 0x537838
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470264 /*0x537838*/;
    cpu.esp -= 4;
    // 0043f62a  683a405f00             -push 0x5f403a
    app->getMemory<x86::reg32>(cpu.esp-4) = 6242362 /*0x5f403a*/;
    cpu.esp -= 4;
    // 0043f62f  e85c000a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043f634  b83a405f00             -mov eax, 0x5f403a
    cpu.eax = 6242362 /*0x5f403a*/;
    // 0043f639  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043f63c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f63d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_43f640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f640  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f641  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f643  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043f646  83f801                 +cmp eax, 1
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
    // 0043f649  7524                   -jne 0x43f66f
    if (!cpu.flags.zf)
    {
        goto L_0x0043f66f;
    }
    // 0043f64b  e870500000             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0043f650  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f652  7609                   -jbe 0x43f65d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043f65d;
    }
    // 0043f654  83f801                 +cmp eax, 1
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
    // 0043f657  740f                   -je 0x43f668
    if (cpu.flags.zf)
    {
        goto L_0x0043f668;
    }
    // 0043f659  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f65b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f65c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f65d:
    // 0043f65d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f65f  e8bcfcffff             -call 0x43f320
    cpu.esp -= 4;
    sub_43f320(app, cpu);
    if (cpu.terminate) return;
    // 0043f664  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f666  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f667  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f668:
    // 0043f668  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043f66b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f66d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f66e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f66f:
    // 0043f66f  83f803                 +cmp eax, 3
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
    // 0043f672  7503                   -jne 0x43f677
    if (!cpu.flags.zf)
    {
        goto L_0x0043f677;
    }
    // 0043f674  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0043f677:
    // 0043f677  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f679  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f67a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_43f680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f680  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f681  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f682  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f683  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043f684  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f685  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f687  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0043f68a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043f68c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043f68e  e87d550000             -call 0x444c10
    cpu.esp -= 4;
    sub_444c10(app, cpu);
    if (cpu.terminate) return;
    // 0043f693  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043f695  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 0043f698  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f69a  e821500000             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0043f69f  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0043f6a2  83fe01                 +cmp esi, 1
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
    // 0043f6a5  0f8595000000           -jne 0x43f740
    if (!cpu.flags.zf)
    {
        goto L_0x0043f740;
    }
    // 0043f6ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f6ad  760d                   -jbe 0x43f6bc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043f6bc;
    }
    // 0043f6af  39f0                   +cmp eax, esi
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
    // 0043f6b1  0f8474000000           -je 0x43f72b
    if (cpu.flags.zf)
    {
        goto L_0x0043f72b;
    }
    // 0043f6b7  e972000000             -jmp 0x43f72e
    goto L_0x0043f72e;
L_0x0043f6bc:
    // 0043f6bc  bf7ebb6f00             -mov edi, 0x6fbb7e
    cpu.edi = 7322494 /*0x6fbb7e*/;
    // 0043f6c1  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0043f6c3  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043f6c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043f6c7:
    // 0043f6c7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043f6c9  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043f6cb  3c00                   +cmp al, 0
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
    // 0043f6cd  7410                   -je 0x43f6df
    if (cpu.flags.zf)
    {
        goto L_0x0043f6df;
    }
    // 0043f6cf  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043f6d2  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043f6d5  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043f6d8  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043f6db  3c00                   +cmp al, 0
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
    // 0043f6dd  75e8                   -jne 0x43f6c7
    if (!cpu.flags.zf)
    {
        goto L_0x0043f6c7;
    }
L_0x0043f6df:
    // 0043f6df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6e0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043f6e2  e889f30500             -call 0x49ea70
    cpu.esp -= 4;
    sub_49ea70(app, cpu);
    if (cpu.terminate) return;
    // 0043f6e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f6e9  7443                   -je 0x43f72e
    if (cpu.flags.zf)
    {
        goto L_0x0043f72e;
    }
    // 0043f6eb  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 0043f6f0  c60301                 -mov byte ptr [ebx], 1
    app->getMemory<x86::reg8>(cpu.ebx) = 1 /*0x1*/;
    // 0043f6f3  e8a8060000             -call 0x43fda0
    cpu.esp -= 4;
    sub_43fda0(app, cpu);
    if (cpu.terminate) return;
    // 0043f6f8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043f6fa  eb05                   -jmp 0x43f701
    goto L_0x0043f701;
L_0x0043f6fc:
    // 0043f6fc  83fa0f                 +cmp edx, 0xf
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
    // 0043f6ff  7d08                   -jge 0x43f709
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f709;
    }
L_0x0043f701:
    // 0043f701  e86aba0000             -call 0x44b170
    cpu.esp -= 4;
    sub_44b170(app, cpu);
    if (cpu.terminate) return;
    // 0043f706  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043f707  ebf3                   -jmp 0x43f6fc
    goto L_0x0043f6fc;
L_0x0043f709:
    // 0043f709  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043f70c  e8eff00500             -call 0x49e800
    cpu.esp -= 4;
    sub_49e800(app, cpu);
    if (cpu.terminate) return;
    // 0043f711  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f713  7419                   -je 0x43f72e
    if (cpu.flags.zf)
    {
        goto L_0x0043f72e;
    }
    // 0043f715  e846530000             -call 0x444a60
    cpu.esp -= 4;
    sub_444a60(app, cpu);
    if (cpu.terminate) return;
    // 0043f71a  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0043f71f  e84cba0000             -call 0x44b170
    cpu.esp -= 4;
    sub_44b170(app, cpu);
    if (cpu.terminate) return;
    // 0043f724  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0043f727  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043f729  eb1f                   -jmp 0x43f74a
    goto L_0x0043f74a;
L_0x0043f72b:
    // 0043f72b  c60301                 -mov byte ptr [ebx], 1
    app->getMemory<x86::reg8>(cpu.ebx) = 1 /*0x1*/;
L_0x0043f72e:
    // 0043f72e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f730  e80b220100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
    // 0043f735  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043f738  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043f73a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f73b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f73c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f73d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f73e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f73f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f740:
    // 0043f740  83fe03                 +cmp esi, 3
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
    // 0043f743  750a                   -jne 0x43f74f
    if (!cpu.flags.zf)
    {
        goto L_0x0043f74f;
    }
    // 0043f745  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f747  c60301                 -mov byte ptr [ebx], 1
    app->getMemory<x86::reg8>(cpu.ebx) = 1 /*0x1*/;
L_0x0043f74a:
    // 0043f74a  e8f1210100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
L_0x0043f74f:
    // 0043f74f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043f752  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043f754  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f755  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f756  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f757  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f758  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f759  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_43f760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f760  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0043f761  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043f764  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043f766  83f901                 +cmp ecx, 1
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
    // 0043f769  7552                   -jne 0x43f7bd
    if (!cpu.flags.zf)
    {
        goto L_0x0043f7bd;
    }
    // 0043f76b  e8504f0000             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0043f770  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f772  7411                   -je 0x43f785
    if (cpu.flags.zf)
    {
        goto L_0x0043f785;
    }
    // 0043f774  83f801                 +cmp eax, 1
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
    // 0043f777  741c                   -je 0x43f795
    if (cpu.flags.zf)
    {
        goto L_0x0043f795;
    }
    // 0043f779  83f802                 +cmp eax, 2
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
    // 0043f77c  7427                   -je 0x43f7a5
    if (cpu.flags.zf)
    {
        goto L_0x0043f7a5;
    }
    // 0043f77e  83f803                 +cmp eax, 3
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
    // 0043f781  743f                   -je 0x43f7c2
    if (cpu.flags.zf)
    {
        goto L_0x0043f7c2;
    }
    // 0043f783  eb40                   -jmp 0x43f7c5
    goto L_0x0043f7c5;
L_0x0043f785:
    // 0043f785  e8e6050000             -call 0x43fd70
    cpu.esp -= 4;
    sub_43fd70(app, cpu);
    if (cpu.terminate) return;
    // 0043f78a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f78c  7423                   -je 0x43f7b1
    if (cpu.flags.zf)
    {
        goto L_0x0043f7b1;
    }
    // 0043f78e  e88dfbffff             -call 0x43f320
    cpu.esp -= 4;
    sub_43f320(app, cpu);
    if (cpu.terminate) return;
    // 0043f793  eb30                   -jmp 0x43f7c5
    goto L_0x0043f7c5;
L_0x0043f795:
    // 0043f795  e8d6050000             -call 0x43fd70
    cpu.esp -= 4;
    sub_43fd70(app, cpu);
    if (cpu.terminate) return;
    // 0043f79a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f79c  7413                   -je 0x43f7b1
    if (cpu.flags.zf)
    {
        goto L_0x0043f7b1;
    }
    // 0043f79e  e83dfdffff             -call 0x43f4e0
    cpu.esp -= 4;
    sub_43f4e0(app, cpu);
    if (cpu.terminate) return;
    // 0043f7a3  eb20                   -jmp 0x43f7c5
    goto L_0x0043f7c5;
L_0x0043f7a5:
    // 0043f7a5  e88e050000             -call 0x43fd38
    cpu.esp -= 4;
    sub_43fd38(app, cpu);
    if (cpu.terminate) return;
    // 0043f7aa  e895050000             -call 0x43fd44
    cpu.esp -= 4;
    sub_43fd44(app, cpu);
    if (cpu.terminate) return;
    // 0043f7af  eb14                   -jmp 0x43f7c5
    goto L_0x0043f7c5;
L_0x0043f7b1:
    // 0043f7b1  b88d070000             -mov eax, 0x78d
    cpu.eax = 1933 /*0x78d*/;
    // 0043f7b6  e825540000             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 0043f7bb  eb08                   -jmp 0x43f7c5
    goto L_0x0043f7c5;
L_0x0043f7bd:
    // 0043f7bd  83f903                 +cmp ecx, 3
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
    // 0043f7c0  7503                   -jne 0x43f7c5
    if (!cpu.flags.zf)
    {
        goto L_0x0043f7c5;
    }
L_0x0043f7c2:
    // 0043f7c2  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0043f7c5:
    // 0043f7c5  61                     -popal 
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
    // 0043f7c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f7c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
/* data blob: 909008f9430011f943002df943001bf9430025f94300 */
void Application::sub_43f7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0043f7e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f7e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f7e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f7e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043f7e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f7e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f7e7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0043f7e9  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043f7ec  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043f7ee  83f801                 +cmp eax, 1
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
    // 0043f7f1  0f8548010000           -jne 0x43f93f
    if (!cpu.flags.zf)
    {
        goto L_0x0043f93f;
    }
    // 0043f7f7  e8c44e0000             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0043f7fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f7fe  760e                   -jbe 0x43f80e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043f80e;
    }
    // 0043f800  83f801                 +cmp eax, 1
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
    // 0043f803  0f84dc000000           -je 0x43f8e5
    if (cpu.flags.zf)
    {
        goto L_0x0043f8e5;
    }
    // 0043f809  e9e9000000             -jmp 0x43f8f7
    goto L_0x0043f8f7;
L_0x0043f80e:
    // 0043f80e  a1e83f5f00             -mov eax, dword ptr [0x5f3fe8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242280) /* 0x5f3fe8 */);
    // 0043f813  83f801                 +cmp eax, 1
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
    // 0043f816  7210                   -jb 0x43f828
    if (cpu.flags.cf)
    {
        goto L_0x0043f828;
    }
    // 0043f818  765b                   -jbe 0x43f875
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043f875;
    }
    // 0043f81a  83f802                 +cmp eax, 2
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
    // 0043f81d  0f8477000000           -je 0x43f89a
    if (cpu.flags.zf)
    {
        goto L_0x0043f89a;
    }
    // 0043f823  e908010000             -jmp 0x43f930
    goto L_0x0043f930;
L_0x0043f828:
    // 0043f828  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f82a  0f8500010000           -jne 0x43f930
    if (!cpu.flags.zf)
    {
        goto L_0x0043f930;
    }
    // 0043f830  f6052eeb550010         +test byte ptr [0x55eb2e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */) & 16 /*0x10*/));
    // 0043f837  7418                   -je 0x43f851
    if (cpu.flags.zf)
    {
        goto L_0x0043f851;
    }
    // 0043f839  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0043f83e  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0043f843  c60101                 -mov byte ptr [ecx], 1
    app->getMemory<x86::reg8>(cpu.ecx) = 1 /*0x1*/;
    // 0043f846  8915b8d36f00           -mov dword ptr [0x6fd3b8], edx
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edx;
    // 0043f84c  e9ff000000             -jmp 0x43f950
    goto L_0x0043f950;
L_0x0043f851:
    // 0043f851  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043f856  e8b5530000             -call 0x444c10
    cpu.esp -= 4;
    sub_444c10(app, cpu);
    if (cpu.terminate) return;
    // 0043f85b  e890ed0500             -call 0x49e5f0
    cpu.esp -= 4;
    sub_49e5f0(app, cpu);
    if (cpu.terminate) return;
    // 0043f860  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f862  0f84c8000000           -je 0x43f930
    if (cpu.flags.zf)
    {
        goto L_0x0043f930;
    }
    // 0043f868  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0043f86d  c60101                 -mov byte ptr [ecx], 1
    app->getMemory<x86::reg8>(cpu.ecx) = 1 /*0x1*/;
    // 0043f870  e9db000000             -jmp 0x43f950
    goto L_0x0043f950;
L_0x0043f875:
    // 0043f875  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0043f87a  b840785300             -mov eax, 0x537840
    cpu.eax = 5470272 /*0x537840*/;
    // 0043f87f  e86ced0500             -call 0x49e5f0
    cpu.esp -= 4;
    sub_49e5f0(app, cpu);
    if (cpu.terminate) return;
    // 0043f884  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f886  0f84a4000000           -je 0x43f930
    if (cpu.flags.zf)
    {
        goto L_0x0043f930;
    }
    // 0043f88c  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0043f891  c60101                 -mov byte ptr [ecx], 1
    app->getMemory<x86::reg8>(cpu.ecx) = 1 /*0x1*/;
    // 0043f894  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f895  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f896  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f897  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f898  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f899  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f89a:
    // 0043f89a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043f89f  a3b0d36f00             -mov dword ptr [0x6fd3b0], eax
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.eax;
    // 0043f8a4  a15cbb6f00             -mov eax, dword ptr [0x6fbb5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322460) /* 0x6fbb5c */);
    // 0043f8a9  668915da227a00         -mov word ptr [0x7a22da], dx
    app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */) = cpu.dx;
    // 0043f8b0  e8db460800             -call 0x4c3f90
    cpu.esp -= 4;
    sub_4c3f90(app, cpu);
    if (cpu.terminate) return;
    // 0043f8b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f8b7  7417                   -je 0x43f8d0
    if (cpu.flags.zf)
    {
        goto L_0x0043f8d0;
    }
    // 0043f8b9  e8a2510000             -call 0x444a60
    cpu.esp -= 4;
    sub_444a60(app, cpu);
    if (cpu.terminate) return;
    // 0043f8be  e8adb80000             -call 0x44b170
    cpu.esp -= 4;
    sub_44b170(app, cpu);
    if (cpu.terminate) return;
    // 0043f8c3  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0043f8c8  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 0043f8ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f8d0:
    // 0043f8d0  891db0d36f00           -mov dword ptr [0x6fd3b0], ebx
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.ebx;
    // 0043f8d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f8d8  e863200100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
    // 0043f8dd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043f8df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f8e5:
    // 0043f8e5  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043f8e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f8ea  e851200100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
    // 0043f8ef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043f8f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f8f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f8f7:
    // 0043f8f7  e854580000             -call 0x445150
    cpu.esp -= 4;
    sub_445150(app, cpu);
    if (cpu.terminate) return;
    // 0043f8fc  83f804                 +cmp eax, 4
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
    // 0043f8ff  772c                   -ja 0x43f92d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0043f92d;
    }
    // 0043f901  ff2485ccf74300         -jmp dword ptr [eax*4 + 0x43f7cc]
    cpu.ip = app->getMemory<x86::reg32>(4454348 + cpu.eax * 4); goto dynamic_jump;
  case 0x0043f908:
    // 0043f908  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043f90a  a3e4227a00             -mov dword ptr [0x7a22e4], eax
    app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */) = cpu.eax;
    // 0043f90f  eb1c                   -jmp 0x43f92d
    goto L_0x0043f92d;
  case 0x0043f911:
    // 0043f911  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043f913  8915e43f5f00           -mov dword ptr [0x5f3fe4], edx
    app->getMemory<x86::reg32>(x86::reg32(6242276) /* 0x5f3fe4 */) = cpu.edx;
    // 0043f919  eb12                   -jmp 0x43f92d
    goto L_0x0043f92d;
  case 0x0043f91b:
    // 0043f91b  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0043f91d  8935e03f5f00           -mov dword ptr [0x5f3fe0], esi
    app->getMemory<x86::reg32>(x86::reg32(6242272) /* 0x5f3fe0 */) = cpu.esi;
    // 0043f923  eb08                   -jmp 0x43f92d
    goto L_0x0043f92d;
  case 0x0043f925:
    // 0043f925  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0043f927  893d0cd56f00           -mov dword ptr [0x6fd50c], edi
    app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */) = cpu.edi;
  [[fallthrough]];
  case 0x0043f92d:
L_0x0043f92d:
    // 0043f92d  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x0043f930:
    // 0043f930  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f932  e809200100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
    // 0043f937  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043f939  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f93a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f93b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f93c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f93d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f93e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f93f:
    // 0043f93f  83f803                 +cmp eax, 3
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
    // 0043f942  750a                   -jne 0x43f94e
    if (!cpu.flags.zf)
    {
        goto L_0x0043f94e;
    }
    // 0043f944  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f946  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043f949  e8f21f0100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
L_0x0043f94e:
    // 0043f94e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0043f950:
    // 0043f950  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f951  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f952  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f953  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f954  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f955  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_43f960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f961  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f962  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f963  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043f965  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043f968  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043f96a  83f801                 +cmp eax, 1
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
    // 0043f96d  0f856e000000           -jne 0x43f9e1
    if (!cpu.flags.zf)
    {
        goto L_0x0043f9e1;
    }
    // 0043f973  e8484d0000             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0043f978  83f801                 +cmp eax, 1
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
    // 0043f97b  7209                   -jb 0x43f986
    if (cpu.flags.cf)
    {
        goto L_0x0043f986;
    }
    // 0043f97d  7632                   -jbe 0x43f9b1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043f9b1;
    }
    // 0043f97f  83f802                 +cmp eax, 2
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
    // 0043f982  744d                   -je 0x43f9d1
    if (cpu.flags.zf)
    {
        goto L_0x0043f9d1;
    }
    // 0043f984  eb4e                   -jmp 0x43f9d4
    goto L_0x0043f9d4;
L_0x0043f986:
    // 0043f986  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f988  754a                   -jne 0x43f9d4
    if (!cpu.flags.zf)
    {
        goto L_0x0043f9d4;
    }
    // 0043f98a  c705b0d36f0003000000   -mov dword ptr [0x6fd3b0], 3
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = 3 /*0x3*/;
    // 0043f994  e8f7450800             -call 0x4c3f90
    cpu.esp -= 4;
    sub_4c3f90(app, cpu);
    if (cpu.terminate) return;
    // 0043f999  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f99b  7437                   -je 0x43f9d4
    if (cpu.flags.zf)
    {
        goto L_0x0043f9d4;
    }
    // 0043f99d  e8be500000             -call 0x444a60
    cpu.esp -= 4;
    sub_444a60(app, cpu);
    if (cpu.terminate) return;
    // 0043f9a2  e8c9b70000             -call 0x44b170
    cpu.esp -= 4;
    sub_44b170(app, cpu);
    if (cpu.terminate) return;
    // 0043f9a7  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0043f9ac  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043f9af  eb23                   -jmp 0x43f9d4
    goto L_0x0043f9d4;
L_0x0043f9b1:
    // 0043f9b1  8b1558bb6f00           -mov edx, dword ptr [0x6fbb58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322456) /* 0x6fbb58 */);
    // 0043f9b7  42                     -inc edx
    (cpu.edx)++;
    // 0043f9b8  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0043f9bd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043f9bf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043f9c2  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043f9c4  891558bb6f00           -mov dword ptr [0x6fbb58], edx
    app->getMemory<x86::reg32>(x86::reg32(7322456) /* 0x6fbb58 */) = cpu.edx;
    // 0043f9ca  e841fcffff             -call 0x43f610
    cpu.esp -= 4;
    sub_43f610(app, cpu);
    if (cpu.terminate) return;
    // 0043f9cf  eb03                   -jmp 0x43f9d4
    goto L_0x0043f9d4;
L_0x0043f9d1:
    // 0043f9d1  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0043f9d4:
    // 0043f9d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f9d6  e8651f0100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
    // 0043f9db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043f9dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f9de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f9df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f9e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f9e1:
    // 0043f9e1  83f803                 +cmp eax, 3
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
    // 0043f9e4  750a                   -jne 0x43f9f0
    if (!cpu.flags.zf)
    {
        goto L_0x0043f9f0;
    }
    // 0043f9e6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f9e8  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043f9eb  e8501f0100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
L_0x0043f9f0:
    // 0043f9f0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043f9f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f9f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f9f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f9f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_43fa00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fa00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fa01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043fa02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043fa03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043fa04  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043fa06  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043fa09  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0043fa0b  83f801                 +cmp eax, 1
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
    // 0043fa0e  0f85ae000000           -jne 0x43fac2
    if (!cpu.flags.zf)
    {
        goto L_0x0043fac2;
    }
    // 0043fa14  e8a74c0000             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0043fa19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fa1b  760e                   -jbe 0x43fa2b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043fa2b;
    }
    // 0043fa1d  83f801                 +cmp eax, 1
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
    // 0043fa20  0f848b000000           -je 0x43fab1
    if (cpu.flags.zf)
    {
        goto L_0x0043fab1;
    }
    // 0043fa26  e989000000             -jmp 0x43fab4
    goto L_0x0043fab4;
L_0x0043fa2b:
    // 0043fa2b  e8e0510000             -call 0x444c10
    cpu.esp -= 4;
    sub_444c10(app, cpu);
    if (cpu.terminate) return;
    // 0043fa30  bf60bb6f00             -mov edi, 0x6fbb60
    cpu.edi = 7322464 /*0x6fbb60*/;
    // 0043fa35  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043fa37  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043fa38:
    // 0043fa38  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043fa3a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043fa3c  3c00                   +cmp al, 0
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
    // 0043fa3e  7410                   -je 0x43fa50
    if (cpu.flags.zf)
    {
        goto L_0x0043fa50;
    }
    // 0043fa40  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043fa43  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043fa46  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043fa49  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043fa4c  3c00                   +cmp al, 0
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
    // 0043fa4e  75e8                   -jne 0x43fa38
    if (!cpu.flags.zf)
    {
        goto L_0x0043fa38;
    }
L_0x0043fa50:
    // 0043fa50  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fa51  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043fa53  49                     -dec ecx
    (cpu.ecx)--;
    // 0043fa54  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043fa56  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0043fa58  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0043fa5a  49                     -dec ecx
    (cpu.ecx)--;
    // 0043fa5b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043fa5d  750a                   -jne 0x43fa69
    if (!cpu.flags.zf)
    {
        goto L_0x0043fa69;
    }
    // 0043fa5f  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043fa62  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fa64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fa65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fa66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fa67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fa68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fa69:
    // 0043fa69  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043fa6c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043fa6e  668915da227a00         -mov word ptr [0x7a22da], dx
    app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */) = cpu.dx;
    // 0043fa75  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0043fa7a  a15cbb6f00             -mov eax, dword ptr [0x6fbb5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322460) /* 0x6fbb5c */);
    // 0043fa7f  8915b0d36f00           -mov dword ptr [0x6fd3b0], edx
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.edx;
    // 0043fa85  e806450800             -call 0x4c3f90
    cpu.esp -= 4;
    sub_4c3f90(app, cpu);
    if (cpu.terminate) return;
    // 0043fa8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fa8c  7413                   -je 0x43faa1
    if (cpu.flags.zf)
    {
        goto L_0x0043faa1;
    }
    // 0043fa8e  e8cd4f0000             -call 0x444a60
    cpu.esp -= 4;
    sub_444a60(app, cpu);
    if (cpu.terminate) return;
    // 0043fa93  e8d8b60000             -call 0x44b170
    cpu.esp -= 4;
    sub_44b170(app, cpu);
    if (cpu.terminate) return;
    // 0043fa98  bf05000000             -mov edi, 5
    cpu.edi = 5 /*0x5*/;
    // 0043fa9d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043fa9f  eb2b                   -jmp 0x43facc
    goto L_0x0043facc;
L_0x0043faa1:
    // 0043faa1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0043faa3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043faa5  e8961e0100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
    // 0043faaa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043faac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043faad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043faae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043faaf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fab0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fab1:
    // 0043fab1  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0043fab4:
    // 0043fab4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fab6  e8851e0100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
    // 0043fabb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043fabd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fabe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fabf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fac0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fac1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fac2:
    // 0043fac2  83f803                 +cmp eax, 3
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
    // 0043fac5  750a                   -jne 0x43fad1
    if (!cpu.flags.zf)
    {
        goto L_0x0043fad1;
    }
    // 0043fac7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fac9  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0043facc:
    // 0043facc  e86f1e0100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
L_0x0043fad1:
    // 0043fad1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043fad3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fad4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fad5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fad6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fad7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_43faf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0043faf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043faf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043faf2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043faf3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043faf4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043faf6  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043faf9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0043fafb  83f801                 +cmp eax, 1
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
    // 0043fafe  0f8505010000           -jne 0x43fc09
    if (!cpu.flags.zf)
    {
        goto L_0x0043fc09;
    }
    // 0043fb04  e8b74b0000             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0043fb09  833df03d5f0001         +cmp dword ptr [0x5f3df0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6241776) /* 0x5f3df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fb10  0f8ec7000000           -jle 0x43fbdd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fbdd;
    }
    // 0043fb16  83f803                 +cmp eax, 3
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
    // 0043fb19  0f87f9000000           -ja 0x43fc18
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0043fc18;
    }
    // 0043fb1f  ff2485d8fa4300         -jmp dword ptr [eax*4 + 0x43fad8]
    cpu.ip = app->getMemory<x86::reg32>(4455128 + cpu.eax * 4); goto dynamic_jump;
  case 0x0043fb26:
    // 0043fb26  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043fb29  8b155cbb6f00           -mov edx, dword ptr [0x6fbb5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322460) /* 0x6fbb5c */);
    // 0043fb2f  42                     -inc edx
    (cpu.edx)++;
    // 0043fb30  8b0df03d5f00           -mov ecx, dword ptr [0x5f3df0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6241776) /* 0x5f3df0 */);
    // 0043fb36  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043fb38  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043fb3b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043fb3d  89155cbb6f00           -mov dword ptr [0x6fbb5c], edx
    app->getMemory<x86::reg32>(x86::reg32(7322460) /* 0x6fbb5c */) = cpu.edx;
    // 0043fb43  e808faffff             -call 0x43f550
    cpu.esp -= 4;
    sub_43f550(app, cpu);
    if (cpu.terminate) return;
    // 0043fb48  a3e03d5f00             -mov dword ptr [0x5f3de0], eax
    app->getMemory<x86::reg32>(x86::reg32(6241760) /* 0x5f3de0 */) = cpu.eax;
    // 0043fb4d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fb4f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb53  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0043fb54:
L_0x0043fb54:
    // 0043fb54  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 0043fb59  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043fb5c  e8ef1c0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fb61  a350405f00             -mov dword ptr [0x5f4050], eax
    app->getMemory<x86::reg32>(x86::reg32(6242384) /* 0x5f4050 */) = cpu.eax;
    // 0043fb66  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 0043fb6b  e8e01c0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fb70  a354405f00             -mov dword ptr [0x5f4054], eax
    app->getMemory<x86::reg32>(x86::reg32(6242388) /* 0x5f4054 */) = cpu.eax;
    // 0043fb75  b8f9000000             -mov eax, 0xf9
    cpu.eax = 249 /*0xf9*/;
    // 0043fb7a  e8d11c0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fb7f  a358405f00             -mov dword ptr [0x5f4058], eax
    app->getMemory<x86::reg32>(x86::reg32(6242392) /* 0x5f4058 */) = cpu.eax;
    // 0043fb84  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0043fb89  e8c21c0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fb8e  6800fa4300             -push 0x43fa00
    app->getMemory<x86::reg32>(cpu.esp-4) = 4454912 /*0x43fa00*/;
    cpu.esp -= 4;
    // 0043fb93  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0043fb95  6a1d                   -push 0x1d
    app->getMemory<x86::reg32>(cpu.esp-4) = 29 /*0x1d*/;
    cpu.esp -= 4;
    // 0043fb97  b958405f00             -mov ecx, 0x5f4058
    cpu.ecx = 6242392 /*0x5f4058*/;
    // 0043fb9c  6860bb6f00             -push 0x6fbb60
    app->getMemory<x86::reg32>(cpu.esp-4) = 7322464 /*0x6fbb60*/;
    cpu.esp -= 4;
    // 0043fba1  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0043fba6  ba50405f00             -mov edx, 0x5f4050
    cpu.edx = 6242384 /*0x5f4050*/;
    // 0043fbab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043fbac  a35c405f00             -mov dword ptr [0x5f405c], eax
    app->getMemory<x86::reg32>(x86::reg32(6242396) /* 0x5f405c */) = cpu.eax;
    // 0043fbb1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043fbb3  e868500000             -call 0x444c20
    cpu.esp -= 4;
    sub_444c20(app, cpu);
    if (cpu.terminate) return;
    // 0043fbb8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fbba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbbb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbbc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbbd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbbe  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0043fbbf:
L_0x0043fbbf:
    // 0043fbbf  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0043fbc4  e857f7ffff             -call 0x43f320
    cpu.esp -= 4;
    sub_43f320(app, cpu);
    if (cpu.terminate) return;
    // 0043fbc9  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043fbcc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fbce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbd1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbd2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0043fbd3:
    // 0043fbd3  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043fbd6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fbd8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbdb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbdc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fbdd:
    // 0043fbdd  83f801                 +cmp eax, 1
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
    // 0043fbe0  720e                   -jb 0x43fbf0
    if (cpu.flags.cf)
    {
        goto L_0x0043fbf0;
    }
    // 0043fbe2  76db                   -jbe 0x43fbbf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043fbbf;
    }
    // 0043fbe4  83f802                 +cmp eax, 2
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
    // 0043fbe7  7416                   -je 0x43fbff
    if (cpu.flags.zf)
    {
        goto L_0x0043fbff;
    }
    // 0043fbe9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fbeb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fbf0:
    // 0043fbf0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fbf2  0f845cffffff           -je 0x43fb54
    if (cpu.flags.zf)
    {
        goto L_0x0043fb54;
    }
    // 0043fbf8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fbfa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbfb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbfd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbfe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fbff:
    // 0043fbff  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043fc02  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fc04  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fc09:
    // 0043fc09  83f803                 +cmp eax, 3
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
    // 0043fc0c  750a                   -jne 0x43fc18
    if (!cpu.flags.zf)
    {
        goto L_0x0043fc18;
    }
    // 0043fc0e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fc10  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043fc13  e8281d0100             -call 0x451940
    cpu.esp -= 4;
    sub_451940(app, cpu);
    if (cpu.terminate) return;
L_0x0043fc18:
    // 0043fc18  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fc1a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc1e  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x90 */
void Application::sub_43fc20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fc20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fc21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043fc22  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043fc24  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043fc26  83f801                 +cmp eax, 1
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
    // 0043fc29  7218                   -jb 0x43fc43
    if (cpu.flags.cf)
    {
        goto L_0x0043fc43;
    }
    // 0043fc2b  7605                   -jbe 0x43fc32
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043fc32;
    }
    // 0043fc2d  83f803                 +cmp eax, 3
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
    // 0043fc30  7511                   -jne 0x43fc43
    if (!cpu.flags.zf)
    {
        goto L_0x0043fc43;
    }
L_0x0043fc32:
    // 0043fc32  e8894a0000             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0043fc37  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043fc39  7403                   -je 0x43fc3e
    if (cpu.flags.zf)
    {
        goto L_0x0043fc3e;
    }
    // 0043fc3b  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0043fc3e:
    // 0043fc3e  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x0043fc43:
    // 0043fc43  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043fc45  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_43fc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fc50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fc51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043fc52  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043fc54  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043fc56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fc58  83f901                 +cmp ecx, 1
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
    // 0043fc5b  724f                   -jb 0x43fcac
    if (cpu.flags.cf)
    {
        goto L_0x0043fcac;
    }
    // 0043fc5d  7608                   -jbe 0x43fc67
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043fc67;
    }
    // 0043fc5f  83f903                 +cmp ecx, 3
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
    // 0043fc62  743c                   -je 0x43fca0
    if (cpu.flags.zf)
    {
        goto L_0x0043fca0;
    }
    // 0043fc64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fc67:
    // 0043fc67  e8544a0000             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0043fc6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fc6e  7513                   -jne 0x43fc83
    if (!cpu.flags.zf)
    {
        goto L_0x0043fc83;
    }
    // 0043fc70  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0043fc75  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0043fc7a  891594e85500           -mov dword ptr [0x55e894], edx
    app->getMemory<x86::reg32>(x86::reg32(5630100) /* 0x55e894 */) = cpu.edx;
    // 0043fc80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc82  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fc83:
    // 0043fc83  83f801                 +cmp eax, 1
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
    // 0043fc86  7509                   -jne 0x43fc91
    if (!cpu.flags.zf)
    {
        goto L_0x0043fc91;
    }
    // 0043fc88  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043fc8a  740c                   -je 0x43fc98
    if (cpu.flags.zf)
    {
        goto L_0x0043fc98;
    }
    // 0043fc8c  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043fc8f  eb07                   -jmp 0x43fc98
    goto L_0x0043fc98;
L_0x0043fc91:
    // 0043fc91  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043fc93  7403                   -je 0x43fc98
    if (cpu.flags.zf)
    {
        goto L_0x0043fc98;
    }
    // 0043fc95  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x0043fc98:
    // 0043fc98  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0043fc9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fc9f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fca0:
    // 0043fca0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043fca2  7403                   -je 0x43fca7
    if (cpu.flags.zf)
    {
        goto L_0x0043fca7;
    }
    // 0043fca4  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0043fca7:
    // 0043fca7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0043fcac:
    // 0043fcac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43fcb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fcb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fcb1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043fcb2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043fcb4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043fcb6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fcb8  83f901                 +cmp ecx, 1
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
    // 0043fcbb  724b                   -jb 0x43fd08
    if (cpu.flags.cf)
    {
        goto L_0x0043fd08;
    }
    // 0043fcbd  7608                   -jbe 0x43fcc7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043fcc7;
    }
    // 0043fcbf  83f903                 +cmp ecx, 3
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
    // 0043fcc2  7438                   -je 0x43fcfc
    if (cpu.flags.zf)
    {
        goto L_0x0043fcfc;
    }
    // 0043fcc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcc6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fcc7:
    // 0043fcc7  e8f4490000             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0043fccc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fcce  750f                   -jne 0x43fcdf
    if (!cpu.flags.zf)
    {
        goto L_0x0043fcdf;
    }
    // 0043fcd0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043fcd2  7403                   -je 0x43fcd7
    if (cpu.flags.zf)
    {
        goto L_0x0043fcd7;
    }
    // 0043fcd4  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0043fcd7:
    // 0043fcd7  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0043fcdc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcdd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fcdf:
    // 0043fcdf  83f801                 +cmp eax, 1
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
    // 0043fce2  7509                   -jne 0x43fced
    if (!cpu.flags.zf)
    {
        goto L_0x0043fced;
    }
    // 0043fce4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043fce6  740c                   -je 0x43fcf4
    if (cpu.flags.zf)
    {
        goto L_0x0043fcf4;
    }
    // 0043fce8  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 0043fceb  eb07                   -jmp 0x43fcf4
    goto L_0x0043fcf4;
L_0x0043fced:
    // 0043fced  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043fcef  7403                   -je 0x43fcf4
    if (cpu.flags.zf)
    {
        goto L_0x0043fcf4;
    }
    // 0043fcf1  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x0043fcf4:
    // 0043fcf4  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0043fcf9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcfa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcfb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fcfc:
    // 0043fcfc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043fcfe  7403                   -je 0x43fd03
    if (cpu.flags.zf)
    {
        goto L_0x0043fd03;
    }
    // 0043fd00  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0043fd03:
    // 0043fd03  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0043fd08:
    // 0043fd08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fd09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fd0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_43fd10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fd10  0fb705dcd16f00         -movzx eax, word ptr [0x6fd1dc]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(7328220) /* 0x6fd1dc */));
    // 0043fd17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fd19  7504                   -jne 0x43fd1f
    if (!cpu.flags.zf)
    {
        goto L_0x0043fd1f;
    }
    // 0043fd1b  66b84b26               -mov ax, 0x264b
    cpu.ax = 9803 /*0x264b*/;
L_0x0043fd1f:
    // 0043fd1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43fd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fd20  e8ebffffff             -call 0x43fd10
    cpu.esp -= 4;
    sub_43fd10(app, cpu);
    if (cpu.terminate) return;
    // 0043fd25  663d4b26               +cmp ax, 0x264b
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(9803 /*0x264b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043fd29  7405                   -je 0x43fd30
    if (cpu.flags.zf)
    {
        goto L_0x0043fd30;
    }
    // 0043fd2b  66b84b26               -mov ax, 0x264b
    cpu.ax = 9803 /*0x264b*/;
    // 0043fd2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fd30:
    // 0043fd30  66b80604               -mov ax, 0x406
    cpu.ax = 1030 /*0x406*/;
    // 0043fd34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43fd36(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fd36  90                     -nop 
    ;
    // 0043fd37  90                     -nop 
    ;
    // 0043fd38  e8e3ffffff             -call 0x43fd20
    cpu.esp -= 4;
    sub_43fd20(app, cpu);
    if (cpu.terminate) return;
    // 0043fd3d  a3dcd16f00             -mov dword ptr [0x6fd1dc], eax
    app->getMemory<x86::reg32>(x86::reg32(7328220) /* 0x6fd1dc */) = cpu.eax;
    // 0043fd42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43fd38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043fd38;
    // 0043fd36  90                     -nop 
    ;
    // 0043fd37  90                     -nop 
    ;
L_entry_0x0043fd38:
    // 0043fd38  e8e3ffffff             -call 0x43fd20
    cpu.esp -= 4;
    sub_43fd20(app, cpu);
    if (cpu.terminate) return;
    // 0043fd3d  a3dcd16f00             -mov dword ptr [0x6fd1dc], eax
    app->getMemory<x86::reg32>(x86::reg32(7328220) /* 0x6fd1dc */) = cpu.eax;
    // 0043fd42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43fd44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fd44  e8c7ffffff             -call 0x43fd10
    cpu.esp -= 4;
    sub_43fd10(app, cpu);
    if (cpu.terminate) return;
    // 0043fd49  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043fd4a  b88b070000             -mov eax, 0x78b
    cpu.eax = 1931 /*0x78b*/;
    // 0043fd4f  e8fc1a0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fd54  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043fd55  6838785300             -push 0x537838
    app->getMemory<x86::reg32>(cpu.esp-4) = 5470264 /*0x537838*/;
    cpu.esp -= 4;
    // 0043fd5a  683a405f00             -push 0x5f403a
    app->getMemory<x86::reg32>(cpu.esp-4) = 6242362 /*0x5f403a*/;
    cpu.esp -= 4;
    // 0043fd5f  e82cf90900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043fd64  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043fd67  b83a405f00             -mov eax, 0x5f403a
    cpu.eax = 6242362 /*0x5f403a*/;
    // 0043fd6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43fd6e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fd6e  90                     -nop 
    ;
    // 0043fd6f  90                     -nop 
    ;
    // 0043fd70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043fd71  bbfcd26f00             -mov ebx, 0x6fd2fc
    cpu.ebx = 7328508 /*0x6fd2fc*/;
    // 0043fd76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fd78  750c                   -jne 0x43fd86
    if (!cpu.flags.zf)
    {
        goto L_0x0043fd86;
    }
    // 0043fd7a  e891ffffff             -call 0x43fd10
    cpu.esp -= 4;
    sub_43fd10(app, cpu);
    if (cpu.terminate) return;
    // 0043fd7f  e84cec0500             -call 0x49e9d0
    cpu.esp -= 4;
    sub_49e9d0(app, cpu);
    if (cpu.terminate) return;
    // 0043fd84  eb18                   -jmp 0x43fd9e
    goto L_0x0043fd9e;
L_0x0043fd86:
    // 0043fd86  e885ffffff             -call 0x43fd10
    cpu.esp -= 4;
    sub_43fd10(app, cpu);
    if (cpu.terminate) return;
    // 0043fd8b  e840ec0500             -call 0x49e9d0
    cpu.esp -= 4;
    sub_49e9d0(app, cpu);
    if (cpu.terminate) return;
    // 0043fd90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fd92  750a                   -jne 0x43fd9e
    if (!cpu.flags.zf)
    {
        goto L_0x0043fd9e;
    }
    // 0043fd94  e887ffffff             -call 0x43fd20
    cpu.esp -= 4;
    sub_43fd20(app, cpu);
    if (cpu.terminate) return;
    // 0043fd99  e832ec0500             -call 0x49e9d0
    cpu.esp -= 4;
    sub_49e9d0(app, cpu);
    if (cpu.terminate) return;
L_0x0043fd9e:
    // 0043fd9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fd9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43fd70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043fd70;
    // 0043fd6e  90                     -nop 
    ;
    // 0043fd6f  90                     -nop 
    ;
L_entry_0x0043fd70:
    // 0043fd70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043fd71  bbfcd26f00             -mov ebx, 0x6fd2fc
    cpu.ebx = 7328508 /*0x6fd2fc*/;
    // 0043fd76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fd78  750c                   -jne 0x43fd86
    if (!cpu.flags.zf)
    {
        goto L_0x0043fd86;
    }
    // 0043fd7a  e891ffffff             -call 0x43fd10
    cpu.esp -= 4;
    sub_43fd10(app, cpu);
    if (cpu.terminate) return;
    // 0043fd7f  e84cec0500             -call 0x49e9d0
    cpu.esp -= 4;
    sub_49e9d0(app, cpu);
    if (cpu.terminate) return;
    // 0043fd84  eb18                   -jmp 0x43fd9e
    goto L_0x0043fd9e;
L_0x0043fd86:
    // 0043fd86  e885ffffff             -call 0x43fd10
    cpu.esp -= 4;
    sub_43fd10(app, cpu);
    if (cpu.terminate) return;
    // 0043fd8b  e840ec0500             -call 0x49e9d0
    cpu.esp -= 4;
    sub_49e9d0(app, cpu);
    if (cpu.terminate) return;
    // 0043fd90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fd92  750a                   -jne 0x43fd9e
    if (!cpu.flags.zf)
    {
        goto L_0x0043fd9e;
    }
    // 0043fd94  e887ffffff             -call 0x43fd20
    cpu.esp -= 4;
    sub_43fd20(app, cpu);
    if (cpu.terminate) return;
    // 0043fd99  e832ec0500             -call 0x49e9d0
    cpu.esp -= 4;
    sub_49e9d0(app, cpu);
    if (cpu.terminate) return;
L_0x0043fd9e:
    // 0043fd9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fd9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43fda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fda0  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0043fda1  bf90106600             -mov edi, 0x661090
    cpu.edi = 6688912 /*0x661090*/;
    // 0043fda6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043fda8  e8a31a0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fdad  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0043fdae  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 0043fdb3  e8981a0900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fdb8  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0043fdb9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fdbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043fdbc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043fdbe  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043fdc0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0043fdc5  e8b64c0000             -call 0x444a80
    cpu.esp -= 4;
    sub_444a80(app, cpu);
    if (cpu.terminate) return;
    // 0043fdca  61                     -popal 
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
    // 0043fdcb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43fdcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fdcc  90                     -nop 
    ;
    // 0043fdcd  90                     -nop 
    ;
    // 0043fdce  90                     -nop 
    ;
    // 0043fdcf  90                     -nop 
    ;
    // 0043fdd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fdd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043fdd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043fdd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043fdd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043fdd5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043fdd7  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0043fdda  a1f03f5f00             -mov eax, dword ptr [0x5f3ff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242288) /* 0x5f3ff0 */);
    // 0043fddf  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 0043fde2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043fde4  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0043fde7  7451                   -je 0x43fe3a
    if (cpu.flags.zf)
    {
        goto L_0x0043fe3a;
    }
    // 0043fde9  8b15c8565500           -mov edx, dword ptr [0x5556c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592776) /* 0x5556c8 */);
    // 0043fdef  8b524c                 -mov edx, dword ptr [edx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 0043fdf2  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0043fdf5  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0043fdf8  8d7dec                 -lea edi, [ebp - 0x14]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043fdfb  8d74022c               -lea esi, [edx + eax + 0x2c]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(44) /* 0x2c */ + cpu.eax * 1);
    // 0043fdff  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 0043fe04  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043fe05  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043fe06  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043fe07  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043fe08  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043fe09  e892ffffff             -call 0x43fda0
    cpu.esp -= 4;
    sub_43fda0(app, cpu);
    if (cpu.terminate) return;
    // 0043fe0e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043fe10  eb05                   -jmp 0x43fe17
    goto L_0x0043fe17;
L_0x0043fe12:
    // 0043fe12  83fa0f                 +cmp edx, 0xf
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
    // 0043fe15  7d08                   -jge 0x43fe1f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043fe1f;
    }
L_0x0043fe17:
    // 0043fe17  e854b30000             -call 0x44b170
    cpu.esp -= 4;
    sub_44b170(app, cpu);
    if (cpu.terminate) return;
    // 0043fe1c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043fe1d  ebf3                   -jmp 0x43fe12
    goto L_0x0043fe12;
L_0x0043fe1f:
    // 0043fe1f  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043fe22  e8d9e90500             -call 0x49e800
    cpu.esp -= 4;
    sub_49e800(app, cpu);
    if (cpu.terminate) return;
    // 0043fe27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fe29  740f                   -je 0x43fe3a
    if (cpu.flags.zf)
    {
        goto L_0x0043fe3a;
    }
    // 0043fe2b  e8304c0000             -call 0x444a60
    cpu.esp -= 4;
    sub_444a60(app, cpu);
    if (cpu.terminate) return;
    // 0043fe30  e83bb30000             -call 0x44b170
    cpu.esp -= 4;
    sub_44b170(app, cpu);
    if (cpu.terminate) return;
    // 0043fe35  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
L_0x0043fe3a:
    // 0043fe3a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043fe3c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043fe3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fe3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fe40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fe41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fe42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fe43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43fdd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043fdd0;
    // 0043fdcc  90                     -nop 
    ;
    // 0043fdcd  90                     -nop 
    ;
    // 0043fdce  90                     -nop 
    ;
    // 0043fdcf  90                     -nop 
    ;
L_entry_0x0043fdd0:
    // 0043fdd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fdd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043fdd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043fdd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043fdd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043fdd5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043fdd7  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0043fdda  a1f03f5f00             -mov eax, dword ptr [0x5f3ff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242288) /* 0x5f3ff0 */);
    // 0043fddf  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 0043fde2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043fde4  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0043fde7  7451                   -je 0x43fe3a
    if (cpu.flags.zf)
    {
        goto L_0x0043fe3a;
    }
    // 0043fde9  8b15c8565500           -mov edx, dword ptr [0x5556c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592776) /* 0x5556c8 */);
    // 0043fdef  8b524c                 -mov edx, dword ptr [edx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 0043fdf2  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0043fdf5  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0043fdf8  8d7dec                 -lea edi, [ebp - 0x14]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043fdfb  8d74022c               -lea esi, [edx + eax + 0x2c]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(44) /* 0x2c */ + cpu.eax * 1);
    // 0043fdff  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 0043fe04  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043fe05  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043fe06  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043fe07  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043fe08  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043fe09  e892ffffff             -call 0x43fda0
    cpu.esp -= 4;
    sub_43fda0(app, cpu);
    if (cpu.terminate) return;
    // 0043fe0e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043fe10  eb05                   -jmp 0x43fe17
    goto L_0x0043fe17;
L_0x0043fe12:
    // 0043fe12  83fa0f                 +cmp edx, 0xf
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
    // 0043fe15  7d08                   -jge 0x43fe1f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043fe1f;
    }
L_0x0043fe17:
    // 0043fe17  e854b30000             -call 0x44b170
    cpu.esp -= 4;
    sub_44b170(app, cpu);
    if (cpu.terminate) return;
    // 0043fe1c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043fe1d  ebf3                   -jmp 0x43fe12
    goto L_0x0043fe12;
L_0x0043fe1f:
    // 0043fe1f  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0043fe22  e8d9e90500             -call 0x49e800
    cpu.esp -= 4;
    sub_49e800(app, cpu);
    if (cpu.terminate) return;
    // 0043fe27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fe29  740f                   -je 0x43fe3a
    if (cpu.flags.zf)
    {
        goto L_0x0043fe3a;
    }
    // 0043fe2b  e8304c0000             -call 0x444a60
    cpu.esp -= 4;
    sub_444a60(app, cpu);
    if (cpu.terminate) return;
    // 0043fe30  e83bb30000             -call 0x44b170
    cpu.esp -= 4;
    sub_44b170(app, cpu);
    if (cpu.terminate) return;
    // 0043fe35  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
L_0x0043fe3a:
    // 0043fe3a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043fe3c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043fe3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fe3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fe40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fe41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fe42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fe43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_43fe50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fe50  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0043fe51  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0043fe56  e8f5190900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fe5b  a360405f00             -mov dword ptr [0x5f4060], eax
    app->getMemory<x86::reg32>(x86::reg32(6242400) /* 0x5f4060 */) = cpu.eax;
    // 0043fe60  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 0043fe65  e8e6190900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fe6a  a364405f00             -mov dword ptr [0x5f4064], eax
    app->getMemory<x86::reg32>(x86::reg32(6242404) /* 0x5f4064 */) = cpu.eax;
    // 0043fe6f  b817000000             -mov eax, 0x17
    cpu.eax = 23 /*0x17*/;
    // 0043fe74  e8d7190900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fe79  a368405f00             -mov dword ptr [0x5f4068], eax
    app->getMemory<x86::reg32>(x86::reg32(6242408) /* 0x5f4068 */) = cpu.eax;
    // 0043fe7e  e8c1feffff             -call 0x43fd44
    cpu.esp -= 4;
    sub_43fd44(app, cpu);
    if (cpu.terminate) return;
    // 0043fe83  a36c405f00             -mov dword ptr [0x5f406c], eax
    app->getMemory<x86::reg32>(x86::reg32(6242412) /* 0x5f406c */) = cpu.eax;
    // 0043fe88  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0043fe8d  e8be190900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fe92  a370405f00             -mov dword ptr [0x5f4070], eax
    app->getMemory<x86::reg32>(x86::reg32(6242416) /* 0x5f4070 */) = cpu.eax;
    // 0043fe97  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fe99  bf74405f00             -mov edi, 0x5f4074
    cpu.edi = 6242420 /*0x5f4074*/;
    // 0043fe9e  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0043fe9f  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0043fea0  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0043fea1  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0043fea2  b88c070000             -mov eax, 0x78c
    cpu.eax = 1932 /*0x78c*/;
    // 0043fea7  e8a4190900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043feac  a37c405f00             -mov dword ptr [0x5f407c], eax
    app->getMemory<x86::reg32>(x86::reg32(6242428) /* 0x5f407c */) = cpu.eax;
    // 0043feb1  6860f74300             -push 0x43f760
    app->getMemory<x86::reg32>(cpu.esp-4) = 4454240 /*0x43f760*/;
    cpu.esp -= 4;
    // 0043feb6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0043feb8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043feba  6874405f00             -push 0x5f4074
    app->getMemory<x86::reg32>(cpu.esp-4) = 6242420 /*0x5f4074*/;
    cpu.esp -= 4;
    // 0043febf  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0043fec4  b964405f00             -mov ecx, 0x5f4064
    cpu.ecx = 6242404 /*0x5f4064*/;
    // 0043fec9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043fece  ba60405f00             -mov edx, 0x5f4060
    cpu.edx = 6242400 /*0x5f4060*/;
    // 0043fed3  e8f8470000             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0043fed8  61                     -popal 
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
    // 0043fed9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fedb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43fedc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fedc  90                     -nop 
    ;
    // 0043fedd  90                     -nop 
    ;
    // 0043fede  90                     -nop 
    ;
    // 0043fedf  90                     -nop 
    ;
    // 0043fee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043fee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043fee3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043fee4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043fee6  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 0043feeb  e860190900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fef0  a384405f00             -mov dword ptr [0x5f4084], eax
    app->getMemory<x86::reg32>(x86::reg32(6242436) /* 0x5f4084 */) = cpu.eax;
    // 0043fef5  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 0043fefa  e851190900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043feff  a388405f00             -mov dword ptr [0x5f4088], eax
    app->getMemory<x86::reg32>(x86::reg32(6242440) /* 0x5f4088 */) = cpu.eax;
    // 0043ff04  e807f7ffff             -call 0x43f610
    cpu.esp -= 4;
    sub_43f610(app, cpu);
    if (cpu.terminate) return;
    // 0043ff09  a38c405f00             -mov dword ptr [0x5f408c], eax
    app->getMemory<x86::reg32>(x86::reg32(6242444) /* 0x5f408c */) = cpu.eax;
    // 0043ff0e  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0043ff13  e838190900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043ff18  6860f94300             -push 0x43f960
    app->getMemory<x86::reg32>(cpu.esp-4) = 4454752 /*0x43f960*/;
    cpu.esp -= 4;
    // 0043ff1d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0043ff1f  b988405f00             -mov ecx, 0x5f4088
    cpu.ecx = 6242440 /*0x5f4088*/;
    // 0043ff24  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043ff26  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0043ff2b  ba84405f00             -mov edx, 0x5f4084
    cpu.edx = 6242436 /*0x5f4084*/;
    // 0043ff30  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043ff32  a390405f00             -mov dword ptr [0x5f4090], eax
    app->getMemory<x86::reg32>(x86::reg32(6242448) /* 0x5f4090 */) = cpu.eax;
    // 0043ff37  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043ff3c  e88f470000             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ff41  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043ff43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ff44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ff45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ff46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ff47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43fee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0043fee0;
    // 0043fedc  90                     -nop 
    ;
    // 0043fedd  90                     -nop 
    ;
    // 0043fede  90                     -nop 
    ;
    // 0043fedf  90                     -nop 
    ;
L_entry_0x0043fee0:
    // 0043fee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043fee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043fee3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043fee4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043fee6  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 0043feeb  e860190900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fef0  a384405f00             -mov dword ptr [0x5f4084], eax
    app->getMemory<x86::reg32>(x86::reg32(6242436) /* 0x5f4084 */) = cpu.eax;
    // 0043fef5  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 0043fefa  e851190900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043feff  a388405f00             -mov dword ptr [0x5f4088], eax
    app->getMemory<x86::reg32>(x86::reg32(6242440) /* 0x5f4088 */) = cpu.eax;
    // 0043ff04  e807f7ffff             -call 0x43f610
    cpu.esp -= 4;
    sub_43f610(app, cpu);
    if (cpu.terminate) return;
    // 0043ff09  a38c405f00             -mov dword ptr [0x5f408c], eax
    app->getMemory<x86::reg32>(x86::reg32(6242444) /* 0x5f408c */) = cpu.eax;
    // 0043ff0e  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0043ff13  e838190900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043ff18  6860f94300             -push 0x43f960
    app->getMemory<x86::reg32>(cpu.esp-4) = 4454752 /*0x43f960*/;
    cpu.esp -= 4;
    // 0043ff1d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0043ff1f  b988405f00             -mov ecx, 0x5f4088
    cpu.ecx = 6242440 /*0x5f4088*/;
    // 0043ff24  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043ff26  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0043ff2b  ba84405f00             -mov edx, 0x5f4084
    cpu.edx = 6242436 /*0x5f4084*/;
    // 0043ff30  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043ff32  a390405f00             -mov dword ptr [0x5f4090], eax
    app->getMemory<x86::reg32>(x86::reg32(6242448) /* 0x5f4090 */) = cpu.eax;
    // 0043ff37  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043ff3c  e88f470000             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0043ff41  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043ff43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ff44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ff45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ff46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ff47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_43ff50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ff50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043ff51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ff52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043ff53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043ff54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ff55  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043ff57  a15cbb6f00             -mov eax, dword ptr [0x6fbb5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322460) /* 0x6fbb5c */);
    // 0043ff5c  8b15f03d5f00           -mov edx, dword ptr [0x5f3df0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6241776) /* 0x5f3df0 */);
    // 0043ff62  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0043ff64  39d0                   +cmp eax, edx
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
    // 0043ff66  7c06                   -jl 0x43ff6e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043ff6e;
    }
    // 0043ff68  89355cbb6f00           -mov dword ptr [0x6fbb5c], esi
    app->getMemory<x86::reg32>(x86::reg32(7322460) /* 0x6fbb5c */) = cpu.esi;
L_0x0043ff6e:
    // 0043ff6e  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 0043ff73  e8d8180900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043ff78  8b1df03d5f00           -mov ebx, dword ptr [0x5f3df0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6241776) /* 0x5f3df0 */);
    // 0043ff7e  a394405f00             -mov dword ptr [0x5f4094], eax
    app->getMemory<x86::reg32>(x86::reg32(6242452) /* 0x5f4094 */) = cpu.eax;
    // 0043ff83  83fb01                 +cmp ebx, 1
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
    // 0043ff86  7e53                   -jle 0x43ffdb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ffdb;
    }
    // 0043ff88  e8c3f5ffff             -call 0x43f550
    cpu.esp -= 4;
    sub_43f550(app, cpu);
    if (cpu.terminate) return;
    // 0043ff8d  a3e03d5f00             -mov dword ptr [0x5f3de0], eax
    app->getMemory<x86::reg32>(x86::reg32(6241760) /* 0x5f3de0 */) = cpu.eax;
    // 0043ff92  b819000000             -mov eax, 0x19
    cpu.eax = 25 /*0x19*/;
    // 0043ff97  e8b4180900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043ff9c  a3e43d5f00             -mov dword ptr [0x5f3de4], eax
    app->getMemory<x86::reg32>(x86::reg32(6241764) /* 0x5f3de4 */) = cpu.eax;
    // 0043ffa1  b81a000000             -mov eax, 0x1a
    cpu.eax = 26 /*0x1a*/;
    // 0043ffa6  e8a5180900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043ffab  a3e83d5f00             -mov dword ptr [0x5f3de8], eax
    app->getMemory<x86::reg32>(x86::reg32(6241768) /* 0x5f3de8 */) = cpu.eax;
    // 0043ffb0  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0043ffb5  e896180900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043ffba  68f0fa4300             -push 0x43faf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4455152 /*0x43faf0*/;
    cpu.esp -= 4;
    // 0043ffbf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0043ffc1  b9e03d5f00             -mov ecx, 0x5f3de0
    cpu.ecx = 6241760 /*0x5f3de0*/;
    // 0043ffc6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043ffc8  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0043ffcd  ba94405f00             -mov edx, 0x5f4094
    cpu.edx = 6242452 /*0x5f4094*/;
    // 0043ffd2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0043ffd4  a3ec3d5f00             -mov dword ptr [0x5f3dec], eax
    app->getMemory<x86::reg32>(x86::reg32(6241772) /* 0x5f3dec */) = cpu.eax;
    // 0043ffd9  eb47                   -jmp 0x440022
    goto L_0x00440022;
L_0x0043ffdb:
    // 0043ffdb  b819000000             -mov eax, 0x19
    cpu.eax = 25 /*0x19*/;
    // 0043ffe0  e86b180900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043ffe5  a3e03d5f00             -mov dword ptr [0x5f3de0], eax
    app->getMemory<x86::reg32>(x86::reg32(6241760) /* 0x5f3de0 */) = cpu.eax;
    // 0043ffea  b81a000000             -mov eax, 0x1a
    cpu.eax = 26 /*0x1a*/;
    // 0043ffef  e85c180900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0043fff4  a3e43d5f00             -mov dword ptr [0x5f3de4], eax
    app->getMemory<x86::reg32>(x86::reg32(6241764) /* 0x5f3de4 */) = cpu.eax;
    // 0043fff9  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 0043fffe  e84d180900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00440003  68f0fa4300             -push 0x43faf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4455152 /*0x43faf0*/;
    cpu.esp -= 4;
    // 00440008  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0044000a  b9e03d5f00             -mov ecx, 0x5f3de0
    cpu.ecx = 6241760 /*0x5f3de0*/;
    // 0044000f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00440011  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00440016  ba94405f00             -mov edx, 0x5f4094
    cpu.edx = 6242452 /*0x5f4094*/;
    // 0044001b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044001d  a3e83d5f00             -mov dword ptr [0x5f3de8], eax
    app->getMemory<x86::reg32>(x86::reg32(6241768) /* 0x5f3de8 */) = cpu.eax;
L_0x00440022:
    // 00440022  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00440027  e8a4460000             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0044002c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044002e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044002f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440030  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440031  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440032  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440033  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_440040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440042  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440043  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440044  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440046  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0044004b  e800180900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00440050  a39c405f00             -mov dword ptr [0x5f409c], eax
    app->getMemory<x86::reg32>(x86::reg32(6242460) /* 0x5f409c */) = cpu.eax;
    // 00440055  b8f9000000             -mov eax, 0xf9
    cpu.eax = 249 /*0xf9*/;
    // 0044005a  e8f1170900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044005f  a3a8405f00             -mov dword ptr [0x5f40a8], eax
    app->getMemory<x86::reg32>(x86::reg32(6242472) /* 0x5f40a8 */) = cpu.eax;
    // 00440064  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 00440069  e8e2170900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044006e  6840f64300             -push 0x43f640
    app->getMemory<x86::reg32>(cpu.esp-4) = 4453952 /*0x43f640*/;
    cpu.esp -= 4;
    // 00440073  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00440075  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00440077  b9a8405f00             -mov ecx, 0x5f40a8
    cpu.ecx = 6242472 /*0x5f40a8*/;
    // 0044007c  68fcd26f00             -push 0x6fd2fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 7328508 /*0x6fd2fc*/;
    cpu.esp -= 4;
    // 00440081  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00440086  ba9c405f00             -mov edx, 0x5f409c
    cpu.edx = 6242460 /*0x5f409c*/;
    // 0044008b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044008d  a3ac405f00             -mov dword ptr [0x5f40ac], eax
    app->getMemory<x86::reg32>(x86::reg32(6242476) /* 0x5f40ac */) = cpu.eax;
    // 00440092  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00440097  e8844b0000             -call 0x444c20
    cpu.esp -= 4;
    sub_444c20(app, cpu);
    if (cpu.terminate) return;
    // 0044009c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044009e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044009f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4400b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004400b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004400b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004400b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004400b4  8b15c8565500           -mov edx, dword ptr [0x5556c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592776) /* 0x5556c8 */);
    // 004400ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004400bc  7407                   -je 0x4400c5
    if (cpu.flags.zf)
    {
        goto L_0x004400c5;
    }
    // 004400be  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004400c0  e85bf1ffff             -call 0x43f220
    cpu.esp -= 4;
    sub_43f220(app, cpu);
    if (cpu.terminate) return;
L_0x004400c5:
    // 004400c5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004400c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4400d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004400d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004400d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004400d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004400d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004400d4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004400d6  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004400dd  750a                   -jne 0x4400e9
    if (!cpu.flags.zf)
    {
        goto L_0x004400e9;
    }
    // 004400df  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004400e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004400e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004400e9:
    // 004400e9  b801010000             -mov eax, 0x101
    cpu.eax = 257 /*0x101*/;
    // 004400ee  e85d170900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004400f3  a3b0405f00             -mov dword ptr [0x5f40b0], eax
    app->getMemory<x86::reg32>(x86::reg32(6242480) /* 0x5f40b0 */) = cpu.eax;
    // 004400f8  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 004400fd  e84e170900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00440102  a3b4405f00             -mov dword ptr [0x5f40b4], eax
    app->getMemory<x86::reg32>(x86::reg32(6242484) /* 0x5f40b4 */) = cpu.eax;
    // 00440107  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 0044010c  e83f170900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00440111  68b0fc4300             -push 0x43fcb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4455600 /*0x43fcb0*/;
    cpu.esp -= 4;
    // 00440116  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00440118  b9b4405f00             -mov ecx, 0x5f40b4
    cpu.ecx = 6242484 /*0x5f40b4*/;
    // 0044011d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044011f  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00440124  bab0405f00             -mov edx, 0x5f40b0
    cpu.edx = 6242480 /*0x5f40b0*/;
    // 00440129  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044012b  a3b8405f00             -mov dword ptr [0x5f40b8], eax
    app->getMemory<x86::reg32>(x86::reg32(6242488) /* 0x5f40b8 */) = cpu.eax;
    // 00440130  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00440135  e896450000             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 0044013a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044013c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044013d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044013e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044013f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440140  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_440160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00440160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440162  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440163  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440164  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440165  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440166  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440168  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044016a  a1d8565500             -mov eax, dword ptr [0x5556d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */);
    // 0044016f  83f805                 +cmp eax, 5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440172  0f876f000000           -ja 0x4401e7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004401e7;
    }
    // 00440178  ff248544014400         -jmp dword ptr [eax*4 + 0x440144]
    cpu.ip = app->getMemory<x86::reg32>(4456772 + cpu.eax * 4); goto dynamic_jump;
  case 0x0044017f:
    // 0044017f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00440181  8915b8d36f00           -mov dword ptr [0x6fd3b8], edx
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edx;
    // 00440187  eb5e                   -jmp 0x4401e7
    goto L_0x004401e7;
  case 0x00440189:
    // 00440189  c705b8d36f0003000000   -mov dword ptr [0x6fd3b8], 3
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = 3 /*0x3*/;
    // 00440193  eb52                   -jmp 0x4401e7
    goto L_0x004401e7;
  case 0x00440195:
    // 00440195  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00440197  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0044019c  893d70d46f00           -mov dword ptr [0x6fd470], edi
    app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */) = cpu.edi;
    // 004401a2  8935b8d36f00           -mov dword ptr [0x6fd3b8], esi
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.esi;
    // 004401a8  eb3d                   -jmp 0x4401e7
    goto L_0x004401e7;
  case 0x004401aa:
    // 004401aa  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004401af  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004401b4  891570d46f00           -mov dword ptr [0x6fd470], edx
    app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */) = cpu.edx;
    // 004401ba  a3b8d36f00             -mov dword ptr [0x6fd3b8], eax
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.eax;
    // 004401bf  eb26                   -jmp 0x4401e7
    goto L_0x004401e7;
  case 0x004401c1:
    // 004401c1  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004401c3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004401c8  893570d46f00           -mov dword ptr [0x6fd470], esi
    app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */) = cpu.esi;
    // 004401ce  891db8d36f00           -mov dword ptr [0x6fd3b8], ebx
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.ebx;
    // 004401d4  eb11                   -jmp 0x4401e7
    goto L_0x004401e7;
  case 0x004401d6:
    // 004401d6  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004401db  893d70d46f00           -mov dword ptr [0x6fd470], edi
    app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */) = cpu.edi;
    // 004401e1  893db8d36f00           -mov dword ptr [0x6fd3b8], edi
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edi;
L_0x004401e7:
    // 004401e7  ba4c785300             -mov edx, 0x53784c
    cpu.edx = 5470284 /*0x53784c*/;
    // 004401ec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004401ee  e84d280000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004401f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004401f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004401f7  7424                   -je 0x44021d
    if (cpu.flags.zf)
    {
        goto L_0x0044021d;
    }
    // 004401f9  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440201  7410                   -je 0x440213
    if (cpu.flags.zf)
    {
        goto L_0x00440213;
    }
    // 00440203  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00440209  83fb01                 +cmp ebx, 1
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
    // 0044020c  7405                   -je 0x440213
    if (cpu.flags.zf)
    {
        goto L_0x00440213;
    }
    // 0044020e  83fb02                 +cmp ebx, 2
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
    // 00440211  7506                   -jne 0x440219
    if (!cpu.flags.zf)
    {
        goto L_0x00440219;
    }
L_0x00440213:
    // 00440213  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00440217  eb04                   -jmp 0x44021d
    goto L_0x0044021d;
L_0x00440219:
    // 00440219  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x0044021d:
    // 0044021d  ba64785300             -mov edx, 0x537864
    cpu.edx = 5470308 /*0x537864*/;
    // 00440222  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440224  e817280000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440229  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044022b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044022d  7424                   -je 0x440253
    if (cpu.flags.zf)
    {
        goto L_0x00440253;
    }
    // 0044022f  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440237  7410                   -je 0x440249
    if (cpu.flags.zf)
    {
        goto L_0x00440249;
    }
    // 00440239  8b3db8d36f00           -mov edi, dword ptr [0x6fd3b8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044023f  83ff01                 +cmp edi, 1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440242  7405                   -je 0x440249
    if (cpu.flags.zf)
    {
        goto L_0x00440249;
    }
    // 00440244  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440247  7506                   -jne 0x44024f
    if (!cpu.flags.zf)
    {
        goto L_0x0044024f;
    }
L_0x00440249:
    // 00440249  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044024d  eb04                   -jmp 0x440253
    goto L_0x00440253;
L_0x0044024f:
    // 0044024f  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00440253:
    // 00440253  ba7c785300             -mov edx, 0x53787c
    cpu.edx = 5470332 /*0x53787c*/;
    // 00440258  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044025a  e8e1270000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044025f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440261  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440263  7424                   -je 0x440289
    if (cpu.flags.zf)
    {
        goto L_0x00440289;
    }
    // 00440265  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044026d  7410                   -je 0x44027f
    if (cpu.flags.zf)
    {
        goto L_0x0044027f;
    }
    // 0044026f  8b35b8d36f00           -mov esi, dword ptr [0x6fd3b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00440275  83fe01                 +cmp esi, 1
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
    // 00440278  7405                   -je 0x44027f
    if (cpu.flags.zf)
    {
        goto L_0x0044027f;
    }
    // 0044027a  83fe02                 +cmp esi, 2
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
    // 0044027d  7506                   -jne 0x440285
    if (!cpu.flags.zf)
    {
        goto L_0x00440285;
    }
L_0x0044027f:
    // 0044027f  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00440283  eb04                   -jmp 0x440289
    goto L_0x00440289;
L_0x00440285:
    // 00440285  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00440289:
    // 00440289  ba94785300             -mov edx, 0x537894
    cpu.edx = 5470356 /*0x537894*/;
    // 0044028e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440290  e8ab270000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440295  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440297  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440299  7424                   -je 0x4402bf
    if (cpu.flags.zf)
    {
        goto L_0x004402bf;
    }
    // 0044029b  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004402a3  7410                   -je 0x4402b5
    if (cpu.flags.zf)
    {
        goto L_0x004402b5;
    }
    // 004402a5  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004402ab  83fb01                 +cmp ebx, 1
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
    // 004402ae  7405                   -je 0x4402b5
    if (cpu.flags.zf)
    {
        goto L_0x004402b5;
    }
    // 004402b0  83fb02                 +cmp ebx, 2
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
    // 004402b3  7506                   -jne 0x4402bb
    if (!cpu.flags.zf)
    {
        goto L_0x004402bb;
    }
L_0x004402b5:
    // 004402b5  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004402b9  eb04                   -jmp 0x4402bf
    goto L_0x004402bf;
L_0x004402bb:
    // 004402bb  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004402bf:
    // 004402bf  baac785300             -mov edx, 0x5378ac
    cpu.edx = 5470380 /*0x5378ac*/;
    // 004402c4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004402c6  e875270000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004402cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004402cd  7413                   -je 0x4402e2
    if (cpu.flags.zf)
    {
        goto L_0x004402e2;
    }
    // 004402cf  833db8d36f0000         +cmp dword ptr [0x6fd3b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004402d6  7406                   -je 0x4402de
    if (cpu.flags.zf)
    {
        goto L_0x004402de;
    }
    // 004402d8  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004402dc  eb04                   -jmp 0x4402e2
    goto L_0x004402e2;
L_0x004402de:
    // 004402de  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004402e2:
    // 004402e2  babc785300             -mov edx, 0x5378bc
    cpu.edx = 5470396 /*0x5378bc*/;
    // 004402e7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004402e9  e852270000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004402ee  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004402f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004402f2  0f8471000000           -je 0x440369
    if (cpu.flags.zf)
    {
        goto L_0x00440369;
    }
    // 004402f8  833db8d36f0000         +cmp dword ptr [0x6fd3b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004402ff  0f854e000000           -jne 0x440353
    if (!cpu.flags.zf)
    {
        goto L_0x00440353;
    }
    // 00440305  833d74d46f0000         +cmp dword ptr [0x6fd474], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328884) /* 0x6fd474 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044030c  752d                   -jne 0x44033b
    if (!cpu.flags.zf)
    {
        goto L_0x0044033b;
    }
    // 0044030e  833d84d46f0000         +cmp dword ptr [0x6fd484], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328900) /* 0x6fd484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440315  7524                   -jne 0x44033b
    if (!cpu.flags.zf)
    {
        goto L_0x0044033b;
    }
    // 00440317  833d78d46f0000         +cmp dword ptr [0x6fd478], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328888) /* 0x6fd478 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044031e  751b                   -jne 0x44033b
    if (!cpu.flags.zf)
    {
        goto L_0x0044033b;
    }
    // 00440320  833d88d46f0000         +cmp dword ptr [0x6fd488], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328904) /* 0x6fd488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440327  7512                   -jne 0x44033b
    if (!cpu.flags.zf)
    {
        goto L_0x0044033b;
    }
    // 00440329  833d7cd46f0000         +cmp dword ptr [0x6fd47c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328892) /* 0x6fd47c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440330  7509                   -jne 0x44033b
    if (!cpu.flags.zf)
    {
        goto L_0x0044033b;
    }
    // 00440332  833d80d46f0000         +cmp dword ptr [0x6fd480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328896) /* 0x6fd480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440339  7418                   -je 0x440353
    if (cpu.flags.zf)
    {
        goto L_0x00440353;
    }
L_0x0044033b:
    // 0044033b  b896010000             -mov eax, 0x196
    cpu.eax = 406 /*0x196*/;
    // 00440340  e80b150900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00440345  8a5904                 -mov bl, byte ptr [ecx + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00440348  89413c                 -mov dword ptr [ecx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0044034b  80e3fe                 +and bl, 0xfe
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 0044034e  885904                 -mov byte ptr [ecx + 4], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 00440351  eb16                   -jmp 0x440369
    goto L_0x00440369;
L_0x00440353:
    // 00440353  b897010000             -mov eax, 0x197
    cpu.eax = 407 /*0x197*/;
    // 00440358  e8f3140900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044035d  8a7904                 -mov bh, byte ptr [ecx + 4]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00440360  89413c                 -mov dword ptr [ecx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 00440363  80cf01                 -or bh, 1
    cpu.bh |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00440366  887904                 -mov byte ptr [ecx + 4], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.bh;
L_0x00440369:
    // 00440369  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044036b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044036c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044036d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044036e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044036f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440370  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440371  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_440390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00440390  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440391  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440392  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440394  8b15d8565500           -mov edx, dword ptr [0x5556d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */);
    // 0044039a  a1b8d36f00             -mov eax, dword ptr [0x6fd3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044039f  83f803                 +cmp eax, 3
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
    // 004403a2  773e                   -ja 0x4403e2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004403e2;
    }
    // 004403a4  ff248574034400         -jmp dword ptr [eax*4 + 0x440374]
    cpu.ip = app->getMemory<x86::reg32>(4457332 + cpu.eax * 4); goto dynamic_jump;
  case 0x004403ab:
    // 004403ab  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004403ad  eb33                   -jmp 0x4403e2
    goto L_0x004403e2;
  case 0x004403af:
    // 004403af  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004403b4  eb2c                   -jmp 0x4403e2
    goto L_0x004403e2;
  case 0x004403b6:
    // 004403b6  833d70d46f0000         +cmp dword ptr [0x6fd470], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004403bd  7507                   -jne 0x4403c6
    if (!cpu.flags.zf)
    {
        goto L_0x004403c6;
    }
    // 004403bf  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004403c4  eb1c                   -jmp 0x4403e2
    goto L_0x004403e2;
L_0x004403c6:
    // 004403c6  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004403cb  eb15                   -jmp 0x4403e2
    goto L_0x004403e2;
  case 0x004403cd:
    // 004403cd  833d70d46f0000         +cmp dword ptr [0x6fd470], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004403d4  7507                   -jne 0x4403dd
    if (!cpu.flags.zf)
    {
        goto L_0x004403dd;
    }
    // 004403d6  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004403db  eb05                   -jmp 0x4403e2
    goto L_0x004403e2;
L_0x004403dd:
    // 004403dd  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
L_0x004403e2:
    // 004403e2  8915d8565500           -mov dword ptr [0x5556d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */) = cpu.edx;
    // 004403e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004403e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004403ea  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4403f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004403f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004403f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004403f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004403f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004403f4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004403f6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004403f8  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440400  7505                   -jne 0x440407
    if (!cpu.flags.zf)
    {
        goto L_0x00440407;
    }
    // 00440402  e889ffffff             -call 0x440390
    cpu.esp -= 4;
    sub_440390(app, cpu);
    if (cpu.terminate) return;
L_0x00440407:
    // 00440407  8b15d8565500           -mov edx, dword ptr [0x5556d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */);
    // 0044040d  3b15dc565500           +cmp edx, dword ptr [0x5556dc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5592796) /* 0x5556dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440413  740d                   -je 0x440422
    if (cpu.flags.zf)
    {
        goto L_0x00440422;
    }
    // 00440415  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440417  8915dc565500           -mov dword ptr [0x5556dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5592796) /* 0x5556dc */) = cpu.edx;
    // 0044041d  e83efdffff             -call 0x440160
    cpu.esp -= 4;
    sub_440160(app, cpu);
    if (cpu.terminate) return;
L_0x00440422:
    // 00440422  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00440428  83fb01                 +cmp ebx, 1
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
    // 0044042b  7405                   -je 0x440432
    if (cpu.flags.zf)
    {
        goto L_0x00440432;
    }
    // 0044042d  83fb02                 +cmp ebx, 2
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
    // 00440430  7519                   -jne 0x44044b
    if (!cpu.flags.zf)
    {
        goto L_0x0044044b;
    }
L_0x00440432:
    // 00440432  ba7c785300             -mov edx, 0x53787c
    cpu.edx = 5470332 /*0x53787c*/;
    // 00440437  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440439  e802260000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044043e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440440  7420                   -je 0x440462
    if (cpu.flags.zf)
    {
        goto L_0x00440462;
    }
    // 00440442  c740583e575500         -mov dword ptr [eax + 0x58], 0x55573e
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */) = 5592894 /*0x55573e*/;
    // 00440449  eb17                   -jmp 0x440462
    goto L_0x00440462;
L_0x0044044b:
    // 0044044b  ba7c785300             -mov edx, 0x53787c
    cpu.edx = 5470332 /*0x53787c*/;
    // 00440450  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440452  e8e9250000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440457  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440459  7407                   -je 0x440462
    if (cpu.flags.zf)
    {
        goto L_0x00440462;
    }
    // 0044045b  c7405800000000         -mov dword ptr [eax + 0x58], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
L_0x00440462:
    // 00440462  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440464  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440465  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440466  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440467  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440468  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_440470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440472  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440473  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440474  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440475  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440477  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440479  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044047b  40                     -inc eax
    (cpu.eax)++;
    // 0044047c  66c704452e5755000100   -mov word ptr [eax*2 + 0x55572e], 1
    app->getMemory<x86::reg16>(x86::reg32(5592878) /* 0x55572e */ + cpu.eax * 2) = 1 /*0x1*/;
L_0x00440486:
    // 00440486  83f807                 +cmp eax, 7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440489  730d                   -jae 0x440498
    if (!cpu.flags.cf)
    {
        goto L_0x00440498;
    }
    // 0044048b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044048c  66c704452e5755000100   -mov word ptr [eax*2 + 0x55572e], 1
    app->getMemory<x86::reg16>(x86::reg32(5592878) /* 0x55572e */ + cpu.eax * 2) = 1 /*0x1*/;
    // 00440496  ebee                   -jmp 0x440486
    goto L_0x00440486;
L_0x00440498:
    // 00440498  833d0cd56f0000         +cmp dword ptr [0x6fd50c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044049f  0f8471000000           -je 0x440516
    if (cpu.flags.zf)
    {
        goto L_0x00440516;
    }
    // 004404a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004404a7  66891d32575500         -mov word ptr [0x555732], bx
    app->getMemory<x86::reg16>(x86::reg32(5592882) /* 0x555732 */) = cpu.bx;
    // 004404ae  833db8d36f0003         +cmp dword ptr [0x6fd3b8], 3
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
    // 004404b5  750e                   -jne 0x4404c5
    if (!cpu.flags.zf)
    {
        goto L_0x004404c5;
    }
    // 004404b7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004404b9  8935d8565500           -mov dword ptr [0x5556d8], esi
    app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */) = cpu.esi;
    // 004404bf  8935b8d36f00           -mov dword ptr [0x6fd3b8], esi
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.esi;
L_0x004404c5:
    // 004404c5  833de4227a0002         +cmp dword ptr [0x7a22e4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004404cc  7548                   -jne 0x440516
    if (!cpu.flags.zf)
    {
        goto L_0x00440516;
    }
    // 004404ce  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 004404d3  b830575500             -mov eax, 0x555730
    cpu.eax = 5592880 /*0x555730*/;
    // 004404d8  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004404de  e829020a00             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004404e3  8b15b8d36f00           -mov edx, dword ptr [0x6fd3b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004404e9  83fa01                 +cmp edx, 1
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
    // 004404ec  7504                   -jne 0x4404f2
    if (!cpu.flags.zf)
    {
        goto L_0x004404f2;
    }
    // 004404ee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004404f0  eb02                   -jmp 0x4404f4
    goto L_0x004404f4;
L_0x004404f2:
    // 004404f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004404f4:
    // 004404f4  8b35b8d36f00           -mov esi, dword ptr [0x6fd3b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004404fa  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004404fc  83fe02                 +cmp esi, 2
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
    // 004404ff  7c07                   -jl 0x440508
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00440508;
    }
    // 00440501  a170d46f00             -mov eax, dword ptr [0x6fd470]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */);
    // 00440506  eb02                   -jmp 0x44050a
    goto L_0x0044050a;
L_0x00440508:
    // 00440508  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044050a:
    // 0044050a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044050c  66c7045d305755000100   -mov word ptr [ebx*2 + 0x555730], 1
    app->getMemory<x86::reg16>(x86::reg32(5592880) /* 0x555730 */ + cpu.ebx * 2) = 1 /*0x1*/;
L_0x00440516:
    // 00440516  e875feffff             -call 0x440390
    cpu.esp -= 4;
    sub_440390(app, cpu);
    if (cpu.terminate) return;
    // 0044051b  a1d8565500             -mov eax, dword ptr [0x5556d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5592792) /* 0x5556d8 */);
    // 00440520  a3dc565500             -mov dword ptr [0x5556dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5592796) /* 0x5556dc */) = cpu.eax;
    // 00440525  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440527  bac4785300             -mov edx, 0x5378c4
    cpu.edx = 5470404 /*0x5378c4*/;
    // 0044052c  e82ffcffff             -call 0x440160
    cpu.esp -= 4;
    sub_440160(app, cpu);
    if (cpu.terminate) return;
    // 00440531  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440533  e808250000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440538  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044053a  7407                   -je 0x440543
    if (cpu.flags.zf)
    {
        goto L_0x00440543;
    }
    // 0044053c  c74064f0ce4500         -mov dword ptr [eax + 0x64], 0x45cef0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4574960 /*0x45cef0*/;
L_0x00440543:
    // 00440543  bad4785300             -mov edx, 0x5378d4
    cpu.edx = 5470420 /*0x5378d4*/;
    // 00440548  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044054a  e8f1240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044054f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440551  7407                   -je 0x44055a
    if (cpu.flags.zf)
    {
        goto L_0x0044055a;
    }
    // 00440553  c7403cfcd26f00         -mov dword ptr [eax + 0x3c], 0x6fd2fc
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = 7328508 /*0x6fd2fc*/;
L_0x0044055a:
    // 0044055a  bae8785300             -mov edx, 0x5378e8
    cpu.edx = 5470440 /*0x5378e8*/;
    // 0044055f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440561  e8da240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440566  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440568  7407                   -je 0x440571
    if (cpu.flags.zf)
    {
        goto L_0x00440571;
    }
    // 0044056a  c74064d0004400         -mov dword ptr [eax + 0x64], 0x4400d0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456656 /*0x4400d0*/;
L_0x00440571:
    // 00440571  baf0785300             -mov edx, 0x5378f0
    cpu.edx = 5470448 /*0x5378f0*/;
    // 00440576  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440578  e8c3240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044057d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044057f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440581  7424                   -je 0x4405a7
    if (cpu.flags.zf)
    {
        goto L_0x004405a7;
    }
    // 00440583  b8b1050000             -mov eax, 0x5b1
    cpu.eax = 1457 /*0x5b1*/;
    // 00440588  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0044058d  e8be120900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00440592  e8891a0100             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00440597  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440599  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044059c  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044059e  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004405a0  83c076                 -add eax, 0x76
    (cpu.eax) += x86::reg32(x86::sreg32(118 /*0x76*/));
    // 004405a3  66894106               -mov word ptr [ecx + 6], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.ax;
L_0x004405a7:
    // 004405a7  c7056c277a0001000000   -mov dword ptr [0x7a276c], 1
    app->getMemory<x86::reg32>(x86::reg32(8005484) /* 0x7a276c */) = 1 /*0x1*/;
    // 004405b1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004405b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004405b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004405b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004405b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004405b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004405b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4405ba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004405ba  90                     -nop 
    ;
    // 004405bb  90                     -nop 
    ;
    // 004405bc  90                     -nop 
    ;
    // 004405bd  90                     -nop 
    ;
    // 004405be  90                     -nop 
    ;
    // 004405bf  90                     -nop 
    ;
    // 004405c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004405c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004405c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004405c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004405c4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004405c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004405c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004405ca  668915cc565500         -mov word ptr [0x5556cc], dx
    app->getMemory<x86::reg16>(x86::reg32(5592780) /* 0x5556cc */) = cpu.dx;
    // 004405d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004405d3  891508d56f00           -mov dword ptr [0x6fd508], edx
    app->getMemory<x86::reg32>(x86::reg32(7329032) /* 0x6fd508 */) = cpu.edx;
    // 004405d9  8915b8d36f00           -mov dword ptr [0x6fd3b8], edx
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edx;
    // 004405df  baf8785300             -mov edx, 0x5378f8
    cpu.edx = 5470456 /*0x5378f8*/;
    // 004405e4  e857240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004405e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004405eb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004405ed  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004405f2  e869dd0500             -call 0x49e360
    cpu.esp -= 4;
    sub_49e360(app, cpu);
    if (cpu.terminate) return;
    // 004405f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004405f9  7508                   -jne 0x440603
    if (!cpu.flags.zf)
    {
        goto L_0x00440603;
    }
    // 004405fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004405fd  7404                   -je 0x440603
    if (cpu.flags.zf)
    {
        goto L_0x00440603;
    }
    // 004405ff  804a0401               -or byte ptr [edx + 4], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440603:
    // 00440603  66833dce56550000       +cmp word ptr [0x5556ce], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5592782) /* 0x5556ce */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044060b  740a                   -je 0x440617
    if (cpu.flags.zf)
    {
        goto L_0x00440617;
    }
    // 0044060d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044060f  7406                   -je 0x440617
    if (cpu.flags.zf)
    {
        goto L_0x00440617;
    }
    // 00440611  66814b040110           -or word ptr [ebx + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x00440617:
    // 00440617  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044061c  e83fdd0500             -call 0x49e360
    cpu.esp -= 4;
    sub_49e360(app, cpu);
    if (cpu.terminate) return;
    // 00440621  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440623  7514                   -jne 0x440639
    if (!cpu.flags.zf)
    {
        goto L_0x00440639;
    }
    // 00440625  ba00795300             -mov edx, 0x537900
    cpu.edx = 5470464 /*0x537900*/;
    // 0044062a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044062c  e80f240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440631  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440633  7404                   -je 0x440639
    if (cpu.flags.zf)
    {
        goto L_0x00440639;
    }
    // 00440635  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440639:
    // 00440639  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044063e  e81ddd0500             -call 0x49e360
    cpu.esp -= 4;
    sub_49e360(app, cpu);
    if (cpu.terminate) return;
    // 00440643  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440645  7514                   -jne 0x44065b
    if (!cpu.flags.zf)
    {
        goto L_0x0044065b;
    }
    // 00440647  ba04795300             -mov edx, 0x537904
    cpu.edx = 5470468 /*0x537904*/;
    // 0044064c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044064e  e8ed230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440653  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440655  7404                   -je 0x44065b
    if (cpu.flags.zf)
    {
        goto L_0x0044065b;
    }
    // 00440657  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044065b:
    // 0044065b  b8f03d5f00             -mov eax, 0x5f3df0
    cpu.eax = 6241776 /*0x5f3df0*/;
    // 00440660  e86b3b0800             -call 0x4c41d0
    cpu.esp -= 4;
    sub_4c41d0(app, cpu);
    if (cpu.terminate) return;
    // 00440665  833df03d5f0000         +cmp dword ptr [0x5f3df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6241776) /* 0x5f3df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044066c  7514                   -jne 0x440682
    if (!cpu.flags.zf)
    {
        goto L_0x00440682;
    }
    // 0044066e  ba08795300             -mov edx, 0x537908
    cpu.edx = 5470472 /*0x537908*/;
    // 00440673  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440675  e8c6230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044067a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044067c  7404                   -je 0x440682
    if (cpu.flags.zf)
    {
        goto L_0x00440682;
    }
    // 0044067e  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440682:
    // 00440682  833d54bb6f0000         +cmp dword ptr [0x6fbb54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440689  743c                   -je 0x4406c7
    if (cpu.flags.zf)
    {
        goto L_0x004406c7;
    }
    // 0044068b  baf8785300             -mov edx, 0x5378f8
    cpu.edx = 5470456 /*0x5378f8*/;
    // 00440690  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440692  e8a9230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440697  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440699  7404                   -je 0x44069f
    if (cpu.flags.zf)
    {
        goto L_0x0044069f;
    }
    // 0044069b  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044069f:
    // 0044069f  ba08795300             -mov edx, 0x537908
    cpu.edx = 5470472 /*0x537908*/;
    // 004406a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406a6  e895230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004406ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004406ad  7404                   -je 0x4406b3
    if (cpu.flags.zf)
    {
        goto L_0x004406b3;
    }
    // 004406af  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004406b3:
    // 004406b3  ba10795300             -mov edx, 0x537910
    cpu.edx = 5470480 /*0x537910*/;
    // 004406b8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406ba  e881230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004406bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004406c1  7404                   -je 0x4406c7
    if (cpu.flags.zf)
    {
        goto L_0x004406c7;
    }
    // 004406c3  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
L_0x004406c7:
    // 004406c7  eb15                   -jmp 0x4406de
    return sub_4406de(app, cpu);
}

/* align: skip  */
void Application::sub_4405c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004405c0;
    // 004405ba  90                     -nop 
    ;
    // 004405bb  90                     -nop 
    ;
    // 004405bc  90                     -nop 
    ;
    // 004405bd  90                     -nop 
    ;
    // 004405be  90                     -nop 
    ;
    // 004405bf  90                     -nop 
    ;
L_entry_0x004405c0:
    // 004405c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004405c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004405c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004405c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004405c4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004405c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004405c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004405ca  668915cc565500         -mov word ptr [0x5556cc], dx
    app->getMemory<x86::reg16>(x86::reg32(5592780) /* 0x5556cc */) = cpu.dx;
    // 004405d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004405d3  891508d56f00           -mov dword ptr [0x6fd508], edx
    app->getMemory<x86::reg32>(x86::reg32(7329032) /* 0x6fd508 */) = cpu.edx;
    // 004405d9  8915b8d36f00           -mov dword ptr [0x6fd3b8], edx
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edx;
    // 004405df  baf8785300             -mov edx, 0x5378f8
    cpu.edx = 5470456 /*0x5378f8*/;
    // 004405e4  e857240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004405e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004405eb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004405ed  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004405f2  e869dd0500             -call 0x49e360
    cpu.esp -= 4;
    sub_49e360(app, cpu);
    if (cpu.terminate) return;
    // 004405f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004405f9  7508                   -jne 0x440603
    if (!cpu.flags.zf)
    {
        goto L_0x00440603;
    }
    // 004405fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004405fd  7404                   -je 0x440603
    if (cpu.flags.zf)
    {
        goto L_0x00440603;
    }
    // 004405ff  804a0401               -or byte ptr [edx + 4], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440603:
    // 00440603  66833dce56550000       +cmp word ptr [0x5556ce], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5592782) /* 0x5556ce */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044060b  740a                   -je 0x440617
    if (cpu.flags.zf)
    {
        goto L_0x00440617;
    }
    // 0044060d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044060f  7406                   -je 0x440617
    if (cpu.flags.zf)
    {
        goto L_0x00440617;
    }
    // 00440611  66814b040110           -or word ptr [ebx + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x00440617:
    // 00440617  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044061c  e83fdd0500             -call 0x49e360
    cpu.esp -= 4;
    sub_49e360(app, cpu);
    if (cpu.terminate) return;
    // 00440621  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440623  7514                   -jne 0x440639
    if (!cpu.flags.zf)
    {
        goto L_0x00440639;
    }
    // 00440625  ba00795300             -mov edx, 0x537900
    cpu.edx = 5470464 /*0x537900*/;
    // 0044062a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044062c  e80f240000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440631  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440633  7404                   -je 0x440639
    if (cpu.flags.zf)
    {
        goto L_0x00440639;
    }
    // 00440635  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440639:
    // 00440639  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044063e  e81ddd0500             -call 0x49e360
    cpu.esp -= 4;
    sub_49e360(app, cpu);
    if (cpu.terminate) return;
    // 00440643  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440645  7514                   -jne 0x44065b
    if (!cpu.flags.zf)
    {
        goto L_0x0044065b;
    }
    // 00440647  ba04795300             -mov edx, 0x537904
    cpu.edx = 5470468 /*0x537904*/;
    // 0044064c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044064e  e8ed230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440653  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440655  7404                   -je 0x44065b
    if (cpu.flags.zf)
    {
        goto L_0x0044065b;
    }
    // 00440657  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044065b:
    // 0044065b  b8f03d5f00             -mov eax, 0x5f3df0
    cpu.eax = 6241776 /*0x5f3df0*/;
    // 00440660  e86b3b0800             -call 0x4c41d0
    cpu.esp -= 4;
    sub_4c41d0(app, cpu);
    if (cpu.terminate) return;
    // 00440665  833df03d5f0000         +cmp dword ptr [0x5f3df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6241776) /* 0x5f3df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044066c  7514                   -jne 0x440682
    if (!cpu.flags.zf)
    {
        goto L_0x00440682;
    }
    // 0044066e  ba08795300             -mov edx, 0x537908
    cpu.edx = 5470472 /*0x537908*/;
    // 00440673  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440675  e8c6230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044067a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044067c  7404                   -je 0x440682
    if (cpu.flags.zf)
    {
        goto L_0x00440682;
    }
    // 0044067e  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440682:
    // 00440682  833d54bb6f0000         +cmp dword ptr [0x6fbb54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440689  743c                   -je 0x4406c7
    if (cpu.flags.zf)
    {
        goto L_0x004406c7;
    }
    // 0044068b  baf8785300             -mov edx, 0x5378f8
    cpu.edx = 5470456 /*0x5378f8*/;
    // 00440690  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440692  e8a9230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440697  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440699  7404                   -je 0x44069f
    if (cpu.flags.zf)
    {
        goto L_0x0044069f;
    }
    // 0044069b  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044069f:
    // 0044069f  ba08795300             -mov edx, 0x537908
    cpu.edx = 5470472 /*0x537908*/;
    // 004406a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406a6  e895230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004406ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004406ad  7404                   -je 0x4406b3
    if (cpu.flags.zf)
    {
        goto L_0x004406b3;
    }
    // 004406af  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004406b3:
    // 004406b3  ba10795300             -mov edx, 0x537910
    cpu.edx = 5470480 /*0x537910*/;
    // 004406b8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406ba  e881230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004406bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004406c1  7404                   -je 0x4406c7
    if (cpu.flags.zf)
    {
        goto L_0x004406c7;
    }
    // 004406c3  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
L_0x004406c7:
    // 004406c7  eb15                   -jmp 0x4406de
    return sub_4406de(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4406ca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004406ca  90                     -nop 
    ;
    // 004406cb  90                     -nop 
    ;
    // 004406cc  90                     -nop 
    ;
    // 004406cd  90                     -nop 
    ;
    // 004406ce  90                     -nop 
    ;
    // 004406cf  90                     -nop 
    ;
    // 004406d0  90                     -nop 
    ;
    // 004406d1  90                     -nop 
    ;
    // 004406d2  90                     -nop 
    ;
    // 004406d3  90                     -nop 
    ;
    // 004406d4  90                     -nop 
    ;
    // 004406d5  90                     -nop 
    ;
    // 004406d6  90                     -nop 
    ;
    // 004406d7  90                     -nop 
    ;
    // 004406d8  90                     -nop 
    ;
    // 004406d9  90                     -nop 
    ;
    // 004406da  90                     -nop 
    ;
    // 004406db  90                     -nop 
    ;
    // 004406dc  90                     -nop 
    ;
    // 004406dd  90                     -nop 
    ;
    // 004406de  ba04795300             -mov edx, 0x537904
    cpu.edx = 5470468 /*0x537904*/;
    // 004406e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406e5  e856230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004406ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004406ec  7407                   -je 0x4406f5
    if (cpu.flags.zf)
    {
        goto L_0x004406f5;
    }
    // 004406ee  c7406450fe4300         -mov dword ptr [eax + 0x64], 0x43fe50
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456016 /*0x43fe50*/;
L_0x004406f5:
    // 004406f5  ba08795300             -mov edx, 0x537908
    cpu.edx = 5470472 /*0x537908*/;
    // 004406fa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406fc  e83f230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440701  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440703  7407                   -je 0x44070c
    if (cpu.flags.zf)
    {
        goto L_0x0044070c;
    }
    // 00440705  c7406450ff4300         -mov dword ptr [eax + 0x64], 0x43ff50
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456272 /*0x43ff50*/;
L_0x0044070c:
    // 0044070c  ba10795300             -mov edx, 0x537910
    cpu.edx = 5470480 /*0x537910*/;
    // 00440711  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440713  e828230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440718  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044071a  7407                   -je 0x440723
    if (cpu.flags.zf)
    {
        goto L_0x00440723;
    }
    // 0044071c  c74064e0fe4300         -mov dword ptr [eax + 0x64], 0x43fee0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456160 /*0x43fee0*/;
L_0x00440723:
    // 00440723  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440725  a36c277a00             -mov dword ptr [0x7a276c], eax
    app->getMemory<x86::reg32>(x86::reg32(8005484) /* 0x7a276c */) = cpu.eax;
    // 0044072a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044072b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044072c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044072d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044072e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4406de(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004406de;
    // 004406ca  90                     -nop 
    ;
    // 004406cb  90                     -nop 
    ;
    // 004406cc  90                     -nop 
    ;
    // 004406cd  90                     -nop 
    ;
    // 004406ce  90                     -nop 
    ;
    // 004406cf  90                     -nop 
    ;
    // 004406d0  90                     -nop 
    ;
    // 004406d1  90                     -nop 
    ;
    // 004406d2  90                     -nop 
    ;
    // 004406d3  90                     -nop 
    ;
    // 004406d4  90                     -nop 
    ;
    // 004406d5  90                     -nop 
    ;
    // 004406d6  90                     -nop 
    ;
    // 004406d7  90                     -nop 
    ;
    // 004406d8  90                     -nop 
    ;
    // 004406d9  90                     -nop 
    ;
    // 004406da  90                     -nop 
    ;
    // 004406db  90                     -nop 
    ;
    // 004406dc  90                     -nop 
    ;
    // 004406dd  90                     -nop 
    ;
L_entry_0x004406de:
    // 004406de  ba04795300             -mov edx, 0x537904
    cpu.edx = 5470468 /*0x537904*/;
    // 004406e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406e5  e856230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004406ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004406ec  7407                   -je 0x4406f5
    if (cpu.flags.zf)
    {
        goto L_0x004406f5;
    }
    // 004406ee  c7406450fe4300         -mov dword ptr [eax + 0x64], 0x43fe50
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456016 /*0x43fe50*/;
L_0x004406f5:
    // 004406f5  ba08795300             -mov edx, 0x537908
    cpu.edx = 5470472 /*0x537908*/;
    // 004406fa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004406fc  e83f230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440701  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440703  7407                   -je 0x44070c
    if (cpu.flags.zf)
    {
        goto L_0x0044070c;
    }
    // 00440705  c7406450ff4300         -mov dword ptr [eax + 0x64], 0x43ff50
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456272 /*0x43ff50*/;
L_0x0044070c:
    // 0044070c  ba10795300             -mov edx, 0x537910
    cpu.edx = 5470480 /*0x537910*/;
    // 00440711  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440713  e828230000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00440718  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044071a  7407                   -je 0x440723
    if (cpu.flags.zf)
    {
        goto L_0x00440723;
    }
    // 0044071c  c74064e0fe4300         -mov dword ptr [eax + 0x64], 0x43fee0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456160 /*0x43fee0*/;
L_0x00440723:
    // 00440723  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440725  a36c277a00             -mov dword ptr [0x7a276c], eax
    app->getMemory<x86::reg32>(x86::reg32(8005484) /* 0x7a276c */) = cpu.eax;
    // 0044072a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044072b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044072c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044072d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044072e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_440730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440730  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440731  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440732  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440733  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440734  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440735  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440737  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044073a  8b4016                 -mov eax, dword ptr [eax + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044073d  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00440740  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00440743  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440745  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044074c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044074e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00440751  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440753  b9e04e6000             -mov ecx, 0x604ee0
    cpu.ecx = 6311648 /*0x604ee0*/;
    // 00440758  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044075b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044075d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044075f  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00440761  8915b0d36f00           -mov dword ptr [0x6fd3b0], edx
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.edx;
    // 00440767  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044076a  0f8591000000           -jne 0x440801
    if (!cpu.flags.zf)
    {
        goto L_0x00440801;
    }
    // 00440770  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00440773  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00440775  0f8486000000           -je 0x440801
    if (cpu.flags.zf)
    {
        goto L_0x00440801;
    }
    // 0044077b  ba08795300             -mov edx, 0x537908
    cpu.edx = 5470472 /*0x537908*/;
    // 00440780  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00440782  e839220000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 00440787  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440789  740a                   -je 0x440795
    if (cpu.flags.zf)
    {
        goto L_0x00440795;
    }
    // 0044078b  c705b0d36f0002000000   -mov dword ptr [0x6fd3b0], 2
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = 2 /*0x2*/;
L_0x00440795:
    // 00440795  ba10795300             -mov edx, 0x537910
    cpu.edx = 5470480 /*0x537910*/;
    // 0044079a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0044079d  e81e220000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004407a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004407a4  740a                   -je 0x4407b0
    if (cpu.flags.zf)
    {
        goto L_0x004407b0;
    }
    // 004407a6  c705b0d36f0003000000   -mov dword ptr [0x6fd3b0], 3
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = 3 /*0x3*/;
L_0x004407b0:
    // 004407b0  ba00795300             -mov edx, 0x537900
    cpu.edx = 5470464 /*0x537900*/;
    // 004407b5  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004407b8  e803220000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004407bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004407bf  740a                   -je 0x4407cb
    if (cpu.flags.zf)
    {
        goto L_0x004407cb;
    }
    // 004407c1  c705b0d36f0004000000   -mov dword ptr [0x6fd3b0], 4
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = 4 /*0x4*/;
L_0x004407cb:
    // 004407cb  ba04795300             -mov edx, 0x537904
    cpu.edx = 5470468 /*0x537904*/;
    // 004407d0  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004407d3  e8e8210000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004407d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004407da  740a                   -je 0x4407e6
    if (cpu.flags.zf)
    {
        goto L_0x004407e6;
    }
    // 004407dc  c705b0d36f0004000000   -mov dword ptr [0x6fd3b0], 4
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = 4 /*0x4*/;
L_0x004407e6:
    // 004407e6  baf8785300             -mov edx, 0x5378f8
    cpu.edx = 5470456 /*0x5378f8*/;
    // 004407eb  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004407ee  e8cd210000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004407f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004407f5  740a                   -je 0x440801
    if (cpu.flags.zf)
    {
        goto L_0x00440801;
    }
    // 004407f7  c705b0d36f0004000000   -mov dword ptr [0x6fd3b0], 4
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = 4 /*0x4*/;
L_0x00440801:
    // 00440801  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440803  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440804  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440805  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440806  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440807  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440808  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_440810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440810  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440811  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440812  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440813  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440814  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440815  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440816  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440818  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044081a  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0044081f  8b1dec3f5f00           -mov ebx, dword ptr [0x5f3fec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6242284) /* 0x5f3fec */);
    // 00440825  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440827  39d8                   +cmp eax, ebx
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
    // 00440829  7e26                   -jle 0x440851
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00440851;
    }
    // 0044082b  e880300000             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 00440830  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00440832  751d                   -jne 0x440851
    if (!cpu.flags.zf)
    {
        goto L_0x00440851;
    }
    // 00440834  81c200050000           -add edx, 0x500
    (cpu.edx) += x86::reg32(x86::sreg32(1280 /*0x500*/));
    // 0044083a  8b35c8565500           -mov esi, dword ptr [0x5556c8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5592776) /* 0x5556c8 */);
    // 00440840  8915ec3f5f00           -mov dword ptr [0x5f3fec], edx
    app->getMemory<x86::reg32>(x86::reg32(6242284) /* 0x5f3fec */) = cpu.edx;
    // 00440846  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00440848  7407                   -je 0x440851
    if (cpu.flags.zf)
    {
        goto L_0x00440851;
    }
    // 0044084a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044084c  e8cfe9ffff             -call 0x43f220
    cpu.esp -= 4;
    sub_43f220(app, cpu);
    if (cpu.terminate) return;
L_0x00440851:
    // 00440851  ba18795300             -mov edx, 0x537918
    cpu.edx = 5470488 /*0x537918*/;
    // 00440856  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440858  e8e3210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044085d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044085f  741a                   -je 0x44087b
    if (cpu.flags.zf)
    {
        goto L_0x0044087b;
    }
    // 00440861  8b3df03f5f00           -mov edi, dword ptr [0x5f3ff0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6242288) /* 0x5f3ff0 */);
    // 00440867  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00440869  740c                   -je 0x440877
    if (cpu.flags.zf)
    {
        goto L_0x00440877;
    }
    // 0044086b  66833f00               +cmp word ptr [edi], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edi);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044086f  7406                   -je 0x440877
    if (cpu.flags.zf)
    {
        goto L_0x00440877;
    }
    // 00440871  806004fe               +and byte ptr [eax + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 00440875  eb04                   -jmp 0x44087b
    goto L_0x0044087b;
L_0x00440877:
    // 00440877  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044087b:
    // 0044087b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044087d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044087e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044087f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440880  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440881  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440882  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440883  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_440890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440892  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440893  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440894  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440895  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440897  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00440899  ba40785300             -mov edx, 0x537840
    cpu.edx = 5470272 /*0x537840*/;
    // 0044089e  e89d210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004408a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004408a5  7411                   -je 0x4408b8
    if (cpu.flags.zf)
    {
        goto L_0x004408b8;
    }
    // 004408a7  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 004408ac  ba9dbb6f00             -mov edx, 0x6fbb9d
    cpu.edx = 7322525 /*0x6fbb9d*/;
    // 004408b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004408b3  e8987b0100             -call 0x458450
    cpu.esp -= 4;
    sub_458450(app, cpu);
    if (cpu.terminate) return;
L_0x004408b8:
    // 004408b8  ba24795300             -mov edx, 0x537924
    cpu.edx = 5470500 /*0x537924*/;
    // 004408bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004408bf  e87c210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004408c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004408c6  7407                   -je 0x4408cf
    if (cpu.flags.zf)
    {
        goto L_0x004408cf;
    }
    // 004408c8  c7406440004400         -mov dword ptr [eax + 0x64], 0x440040
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456512 /*0x440040*/;
L_0x004408cf:
    // 004408cf  ba18795300             -mov edx, 0x537918
    cpu.edx = 5470488 /*0x537918*/;
    // 004408d4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004408d6  e865210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004408db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004408dd  7421                   -je 0x440900
    if (cpu.flags.zf)
    {
        goto L_0x00440900;
    }
    // 004408df  8b15f03f5f00           -mov edx, dword ptr [0x5f3ff0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6242288) /* 0x5f3ff0 */);
    // 004408e5  c74064d0fd4300         -mov dword ptr [eax + 0x64], 0x43fdd0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4455888 /*0x43fdd0*/;
    // 004408ec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004408ee  740c                   -je 0x4408fc
    if (cpu.flags.zf)
    {
        goto L_0x004408fc;
    }
    // 004408f0  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004408f4  7406                   -je 0x4408fc
    if (cpu.flags.zf)
    {
        goto L_0x004408fc;
    }
    // 004408f6  806004fe               +and byte ptr [eax + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 004408fa  eb04                   -jmp 0x440900
    goto L_0x00440900;
L_0x004408fc:
    // 004408fc  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440900:
    // 00440900  ba30795300             -mov edx, 0x537930
    cpu.edx = 5470512 /*0x537930*/;
    // 00440905  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00440907  e834210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044090c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044090e  740f                   -je 0x44091f
    if (cpu.flags.zf)
    {
        goto L_0x0044091f;
    }
    // 00440910  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440912  c74064b0004400         -mov dword ptr [eax + 0x64], 0x4400b0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456624 /*0x4400b0*/;
    // 00440919  890dec3f5f00           -mov dword ptr [0x5f3fec], ecx
    app->getMemory<x86::reg32>(x86::reg32(6242284) /* 0x5f3fec */) = cpu.ecx;
L_0x0044091f:
    // 0044091f  bae8785300             -mov edx, 0x5378e8
    cpu.edx = 5470440 /*0x5378e8*/;
    // 00440924  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00440926  e815210000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044092b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044092d  7407                   -je 0x440936
    if (cpu.flags.zf)
    {
        goto L_0x00440936;
    }
    // 0044092f  c74064d0004400         -mov dword ptr [eax + 0x64], 0x4400d0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4456656 /*0x4400d0*/;
L_0x00440936:
    // 00440936  833d54bb6f0000         +cmp dword ptr [0x6fbb54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044093d  7414                   -je 0x440953
    if (cpu.flags.zf)
    {
        goto L_0x00440953;
    }
    // 0044093f  ba24795300             -mov edx, 0x537924
    cpu.edx = 5470500 /*0x537924*/;
    // 00440944  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00440946  e8f5200000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044094b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044094d  7404                   -je 0x440953
    if (cpu.flags.zf)
    {
        goto L_0x00440953;
    }
    // 0044094f  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00440953:
    // 00440953  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440955  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440956  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440957  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440958  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440959  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044095a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_440960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440960  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440961  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440963  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440965  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440966  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_440970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440974  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440975  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440976  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440978  ba51020000             -mov edx, 0x251
    cpu.edx = 593 /*0x251*/;
    // 0044097d  b987000000             -mov ecx, 0x87
    cpu.ecx = 135 /*0x87*/;
    // 00440982  8915cc3f5f00           -mov dword ptr [0x5f3fcc], edx
    app->getMemory<x86::reg32>(x86::reg32(6242252) /* 0x5f3fcc */) = cpu.edx;
    // 00440988  890dc83f5f00           -mov dword ptr [0x5f3fc8], ecx
    app->getMemory<x86::reg32>(x86::reg32(6242248) /* 0x5f3fc8 */) = cpu.ecx;
    // 0044098e  e86da40000             -call 0x44ae00
    cpu.esp -= 4;
    sub_44ae00(app, cpu);
    if (cpu.terminate) return;
    // 00440993  8b1d34925500           -mov ebx, dword ptr [0x559234]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00440999  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044099b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044099d  7428                   -je 0x4409c7
    if (cpu.flags.zf)
    {
        goto L_0x004409c7;
    }
    // 0044099f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004409a1  7455                   -je 0x4409f8
    if (cpu.flags.zf)
    {
        goto L_0x004409f8;
    }
    // 004409a3  ba3c795300             -mov edx, 0x53793c
    cpu.edx = 5470524 /*0x53793c*/;
    // 004409a8  e863d90a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004409ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004409af  750c                   -jne 0x4409bd
    if (!cpu.flags.zf)
    {
        goto L_0x004409bd;
    }
    // 004409b1  c7054857550001000000   -mov dword ptr [0x555748], 1
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = 1 /*0x1*/;
    // 004409bb  eb3b                   -jmp 0x4409f8
    goto L_0x004409f8;
L_0x004409bd:
    // 004409bd  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004409bf  893d48575500           -mov dword ptr [0x555748], edi
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.edi;
    // 004409c5  eb31                   -jmp 0x4409f8
    goto L_0x004409f8;
L_0x004409c7:
    // 004409c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004409c9  742d                   -je 0x4409f8
    if (cpu.flags.zf)
    {
        goto L_0x004409f8;
    }
    // 004409cb  ba44795300             -mov edx, 0x537944
    cpu.edx = 5470532 /*0x537944*/;
    // 004409d0  e83bd90a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004409d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004409d7  750a                   -jne 0x4409e3
    if (!cpu.flags.zf)
    {
        goto L_0x004409e3;
    }
    // 004409d9  c7054857550001000000   -mov dword ptr [0x555748], 1
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = 1 /*0x1*/;
L_0x004409e3:
    // 004409e3  ba50795300             -mov edx, 0x537950
    cpu.edx = 5470544 /*0x537950*/;
    // 004409e8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004409ea  e821d90a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004409ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004409f1  7505                   -jne 0x4409f8
    if (!cpu.flags.zf)
    {
        goto L_0x004409f8;
    }
    // 004409f3  a348575500             -mov dword ptr [0x555748], eax
    app->getMemory<x86::reg32>(x86::reg32(5592904) /* 0x555748 */) = cpu.eax;
L_0x004409f8:
    // 004409f8  833d3492550000         +cmp dword ptr [0x559234], 0
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
    // 004409ff  0f85a9000000           -jne 0x440aae
    if (!cpu.flags.zf)
    {
        goto L_0x00440aae;
    }
    // 00440a05  b85c795300             -mov eax, 0x53795c
    cpu.eax = 5470556 /*0x53795c*/;
    // 00440a0a  e8a1530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a0f  66a3cc565500           -mov word ptr [0x5556cc], ax
    app->getMemory<x86::reg16>(x86::reg32(5592780) /* 0x5556cc */) = cpu.ax;
    // 00440a15  b864795300             -mov eax, 0x537964
    cpu.eax = 5470564 /*0x537964*/;
    // 00440a1a  e891530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a1f  66a302405f00           -mov word ptr [0x5f4002], ax
    app->getMemory<x86::reg16>(x86::reg32(6242306) /* 0x5f4002 */) = cpu.ax;
    // 00440a25  b86c795300             -mov eax, 0x53796c
    cpu.eax = 5470572 /*0x53796c*/;
    // 00440a2a  e881530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a2f  66a3fe3f5f00           -mov word ptr [0x5f3ffe], ax
    app->getMemory<x86::reg16>(x86::reg32(6242302) /* 0x5f3ffe */) = cpu.ax;
    // 00440a35  b874795300             -mov eax, 0x537974
    cpu.eax = 5470580 /*0x537974*/;
    // 00440a3a  e871530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a3f  66a3f83f5f00           -mov word ptr [0x5f3ff8], ax
    app->getMemory<x86::reg16>(x86::reg32(6242296) /* 0x5f3ff8 */) = cpu.ax;
    // 00440a45  b87c795300             -mov eax, 0x53797c
    cpu.eax = 5470588 /*0x53797c*/;
    // 00440a4a  e861530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a4f  66a3f43f5f00           -mov word ptr [0x5f3ff4], ax
    app->getMemory<x86::reg16>(x86::reg32(6242292) /* 0x5f3ff4 */) = cpu.ax;
    // 00440a55  b884795300             -mov eax, 0x537984
    cpu.eax = 5470596 /*0x537984*/;
    // 00440a5a  e851530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a5f  66a3fc3f5f00           -mov word ptr [0x5f3ffc], ax
    app->getMemory<x86::reg16>(x86::reg32(6242300) /* 0x5f3ffc */) = cpu.ax;
    // 00440a65  b88c795300             -mov eax, 0x53798c
    cpu.eax = 5470604 /*0x53798c*/;
    // 00440a6a  e841530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a6f  66a300405f00           -mov word ptr [0x5f4000], ax
    app->getMemory<x86::reg16>(x86::reg32(6242304) /* 0x5f4000 */) = cpu.ax;
    // 00440a75  b894795300             -mov eax, 0x537994
    cpu.eax = 5470612 /*0x537994*/;
    // 00440a7a  e831530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a7f  66a3fa3f5f00           -mov word ptr [0x5f3ffa], ax
    app->getMemory<x86::reg16>(x86::reg32(6242298) /* 0x5f3ffa */) = cpu.ax;
    // 00440a85  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00440a8c  7520                   -jne 0x440aae
    if (!cpu.flags.zf)
    {
        goto L_0x00440aae;
    }
    // 00440a8e  b89c795300             -mov eax, 0x53799c
    cpu.eax = 5470620 /*0x53799c*/;
    // 00440a93  e818530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440a98  66a304405f00           -mov word ptr [0x5f4004], ax
    app->getMemory<x86::reg16>(x86::reg32(6242308) /* 0x5f4004 */) = cpu.ax;
    // 00440a9e  b8a4795300             -mov eax, 0x5379a4
    cpu.eax = 5470628 /*0x5379a4*/;
    // 00440aa3  e808530900             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00440aa8  66a3f63f5f00           -mov word ptr [0x5f3ff6], ax
    app->getMemory<x86::reg16>(x86::reg32(6242294) /* 0x5f3ff6 */) = cpu.ax;
L_0x00440aae:
    // 00440aae  8b1ddc3f5f00           -mov ebx, dword ptr [0x5f3fdc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */);
    // 00440ab4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00440ab6  7407                   -je 0x440abf
    if (cpu.flags.zf)
    {
        goto L_0x00440abf;
    }
    // 00440ab8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00440aba  e8d10d0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00440abf:
    // 00440abf  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 00440ac4  b830785300             -mov eax, 0x537830
    cpu.eax = 5470256 /*0x537830*/;
    // 00440ac9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00440acb  e8500b0a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00440ad0  a3dc3f5f00             -mov dword ptr [0x5f3fdc], eax
    app->getMemory<x86::reg32>(x86::reg32(6242268) /* 0x5f3fdc */) = cpu.eax;
    // 00440ad5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440ad7  740c                   -je 0x440ae5
    if (cpu.flags.zf)
    {
        goto L_0x00440ae5;
    }
    // 00440ad9  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 00440ade  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00440ae0  e85bfb0900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x00440ae5:
    // 00440ae5  8b35d03f5f00           -mov esi, dword ptr [0x5f3fd0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */);
    // 00440aeb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00440aed  7407                   -je 0x440af6
    if (cpu.flags.zf)
    {
        goto L_0x00440af6;
    }
    // 00440aef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00440af1  e89a0d0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00440af6:
    // 00440af6  ba84030000             -mov edx, 0x384
    cpu.edx = 900 /*0x384*/;
    // 00440afb  b830785300             -mov eax, 0x537830
    cpu.eax = 5470256 /*0x537830*/;
    // 00440b00  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00440b02  e8190b0a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00440b07  bb84030000             -mov ebx, 0x384
    cpu.ebx = 900 /*0x384*/;
    // 00440b0c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00440b0e  a3d03f5f00             -mov dword ptr [0x5f3fd0], eax
    app->getMemory<x86::reg32>(x86::reg32(6242256) /* 0x5f3fd0 */) = cpu.eax;
    // 00440b13  e828fb0900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00440b18  8b3d34925500           -mov edi, dword ptr [0x559234]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00440b1e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00440b20  7506                   -jne 0x440b28
    if (!cpu.flags.zf)
    {
        goto L_0x00440b28;
    }
    // 00440b22  893d08d56f00           -mov dword ptr [0x6fd508], edi
    app->getMemory<x86::reg32>(x86::reg32(7329032) /* 0x6fd508 */) = cpu.edi;
L_0x00440b28:
    // 00440b28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b2b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b2d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_440b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440b30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440b31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440b32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440b33  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440b35  8b0df83f5f00           -mov ecx, dword ptr [0x5f3ff8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242296) /* 0x5f3ff8 */);
    // 00440b3b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00440b3d  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00440b40  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440b42  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440b44  e8476e0900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00440b49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_440b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440b50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440b51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440b52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440b53  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00440b55  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00440b58  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00440b5b  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00440b5e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00440b60  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00440b62  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00440b67  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00440b6a  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 00440b6f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00440b71  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440b74  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440b76  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00440b79  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00440b7e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440b80  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00440b83  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440b85  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00440b87  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440b8a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440b8c  81fa00010000           +cmp edx, 0x100
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
    // 00440b92  7c09                   -jl 0x440b9d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00440b9d;
    }
    // 00440b94  b8ff010000             -mov eax, 0x1ff
    cpu.eax = 511 /*0x1ff*/;
    // 00440b99  29d0                   +sub eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00440b9b  eb02                   -jmp 0x440b9f
    goto L_0x00440b9f;
L_0x00440b9d:
    // 00440b9d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00440b9f:
    // 00440b9f  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00440ba2  05ffffff00             -add eax, 0xffffff
    (cpu.eax) += x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 00440ba7  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00440baa  8d5efb                 -lea ebx, [esi - 5]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(-5) /* -0x5 */);
    // 00440bad  8d57fa                 -lea edx, [edi - 6]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-6) /* -0x6 */);
    // 00440bb0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00440bb2  743f                   -je 0x440bf3
    if (cpu.flags.zf)
    {
        goto L_0x00440bf3;
    }
    // 00440bb4  66833d04405f0000       +cmp word ptr [0x5f4004], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242308) /* 0x5f4004 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440bbc  7416                   -je 0x440bd4
    if (cpu.flags.zf)
    {
        goto L_0x00440bd4;
    }
    // 00440bbe  8b0d02405f00           -mov ecx, dword ptr [0x5f4002]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242306) /* 0x5f4002 */);
    // 00440bc4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00440bc7  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00440bca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440bcc  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00440bcf  e88c650900             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
L_0x00440bd4:
    // 00440bd4  66833df43f5f0000       +cmp word ptr [0x5f3ff4], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242292) /* 0x5f3ff4 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440bdc  7450                   -je 0x440c2e
    if (cpu.flags.zf)
    {
        goto L_0x00440c2e;
    }
    // 00440bde  a1f23f5f00             -mov eax, dword ptr [0x5f3ff2]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242290) /* 0x5f3ff2 */);
    // 00440be3  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00440be6  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00440be9  c1f810                 +sar eax, 0x10
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
    // 00440bec  e89f6d0900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
    // 00440bf1  eb3b                   -jmp 0x440c2e
    goto L_0x00440c2e;
L_0x00440bf3:
    // 00440bf3  66833df63f5f0000       +cmp word ptr [0x5f3ff6], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242294) /* 0x5f3ff6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440bfb  7416                   -je 0x440c13
    if (cpu.flags.zf)
    {
        goto L_0x00440c13;
    }
    // 00440bfd  8b0df43f5f00           -mov ecx, dword ptr [0x5f3ff4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6242292) /* 0x5f3ff4 */);
    // 00440c03  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00440c06  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00440c09  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440c0b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00440c0e  e84d650900             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
L_0x00440c13:
    // 00440c13  66833df83f5f0000       +cmp word ptr [0x5f3ff8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(6242296) /* 0x5f3ff8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440c1b  7411                   -je 0x440c2e
    if (cpu.flags.zf)
    {
        goto L_0x00440c2e;
    }
    // 00440c1d  a1f63f5f00             -mov eax, dword ptr [0x5f3ff6]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6242294) /* 0x5f3ff6 */);
    // 00440c22  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00440c24  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00440c26  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00440c29  e8626d0900             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x00440c2e:
    // 00440c2e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00440c30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c33  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
