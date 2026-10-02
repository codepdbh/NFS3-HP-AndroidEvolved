#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8b 0xc0 */
void Application::sub_521f7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00521f7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00521f7d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00521f7e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00521f7f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00521f80  bd40000000             -mov ebp, 0x40
    cpu.ebp = 64 /*0x40*/;
    // 00521f85  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00521f87:
    // 00521f87  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00521f89  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00521f8b  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00521f8d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00521f8f  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x00521f92:
    // 00521f92  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00521f94  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00521f97  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 00521f99  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00521f9c  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 00521f9f  81c200000010           -add edx, 0x10000000
    (cpu.edx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 00521fa5  89b09cbea000           -mov dword ptr [eax + 0xa0be9c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10534556) /* 0xa0be9c */) = cpu.esi;
    // 00521fab  39f8                   +cmp eax, edi
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
    // 00521fad  75e3                   -jne 0x521f92
    if (!cpu.flags.zf)
    {
        goto L_0x00521f92;
    }
    // 00521faf  43                     -inc ebx
    (cpu.ebx)++;
    // 00521fb0  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00521fb3  83fb0d                 +cmp ebx, 0xd
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
    // 00521fb6  7ccf                   -jl 0x521f87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00521f87;
    }
    // 00521fb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00521fb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00521fba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00521fbb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00521fbc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_521fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00521fc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00521fc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00521fc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00521fc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00521fc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00521fc5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00521fc6  e865ffffff             -call 0x521f30
    cpu.esp -= 4;
    sub_521f30(app, cpu);
    if (cpu.terminate) return;
    // 00521fcb  833db443560000         +cmp dword ptr [0x5643b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00521fd2  7560                   -jne 0x522034
    if (!cpu.flags.zf)
    {
        goto L_0x00522034;
    }
    // 00521fd4  b9e87a5200             -mov ecx, 0x527ae8
    cpu.ecx = 5405416 /*0x527ae8*/;
    // 00521fd9  bb207f5200             -mov ebx, 0x527f20
    cpu.ebx = 5406496 /*0x527f20*/;
    // 00521fde  be3c815200             -mov esi, 0x52813c
    cpu.esi = 5407036 /*0x52813c*/;
    // 00521fe3  bfa4835200             -mov edi, 0x5283a4
    cpu.edi = 5407652 /*0x5283a4*/;
    // 00521fe8  bdb8855200             -mov ebp, 0x5285b8
    cpu.ebp = 5408184 /*0x5285b8*/;
    // 00521fed  b8988a5200             -mov eax, 0x528a98
    cpu.eax = 5409432 /*0x528a98*/;
    // 00521ff2  baac8c5200             -mov edx, 0x528cac
    cpu.edx = 5409964 /*0x528cac*/;
    // 00521ff7  890dac6a9f00           -mov dword ptr [0x9f6aac], ecx
    app->getMemory<x86::reg32>(x86::reg32(10447532) /* 0x9f6aac */) = cpu.ecx;
    // 00521ffd  891db06a9f00           -mov dword ptr [0x9f6ab0], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447536) /* 0x9f6ab0 */) = cpu.ebx;
    // 00522003  8935b46a9f00           -mov dword ptr [0x9f6ab4], esi
    app->getMemory<x86::reg32>(x86::reg32(10447540) /* 0x9f6ab4 */) = cpu.esi;
    // 00522009  893db86a9f00           -mov dword ptr [0x9f6ab8], edi
    app->getMemory<x86::reg32>(x86::reg32(10447544) /* 0x9f6ab8 */) = cpu.edi;
    // 0052200f  892dbc6a9f00           -mov dword ptr [0x9f6abc], ebp
    app->getMemory<x86::reg32>(x86::reg32(10447548) /* 0x9f6abc */) = cpu.ebp;
    // 00522015  a3c06a9f00             -mov dword ptr [0x9f6ac0], eax
    app->getMemory<x86::reg32>(x86::reg32(10447552) /* 0x9f6ac0 */) = cpu.eax;
    // 0052201a  b90c8f5200             -mov ecx, 0x528f0c
    cpu.ecx = 5410572 /*0x528f0c*/;
    // 0052201f  8915c46a9f00           -mov dword ptr [0x9f6ac4], edx
    app->getMemory<x86::reg32>(x86::reg32(10447556) /* 0x9f6ac4 */) = cpu.edx;
    // 00522025  890dc86a9f00           -mov dword ptr [0x9f6ac8], ecx
    app->getMemory<x86::reg32>(x86::reg32(10447560) /* 0x9f6ac8 */) = cpu.ecx;
    // 0052202b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052202d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052202e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052202f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522030  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522031  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522032  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522033  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00522034:
    // 00522034  e843ffffff             -call 0x521f7c
    cpu.esp -= 4;
    sub_521f7c(app, cpu);
    if (cpu.terminate) return;
    // 00522039  bb04915200             -mov ebx, 0x529104
    cpu.ebx = 5411076 /*0x529104*/;
    // 0052203e  be34955200             -mov esi, 0x529534
    cpu.esi = 5412148 /*0x529534*/;
    // 00522043  bf78975200             -mov edi, 0x529778
    cpu.edi = 5412728 /*0x529778*/;
    // 00522048  bdf4995200             -mov ebp, 0x5299f4
    cpu.ebp = 5413364 /*0x5299f4*/;
    // 0052204d  b82c9c5200             -mov eax, 0x529c2c
    cpu.eax = 5413932 /*0x529c2c*/;
    // 00522052  ba44a15200             -mov edx, 0x52a144
    cpu.edx = 5415236 /*0x52a144*/;
    // 00522057  b954a35200             -mov ecx, 0x52a354
    cpu.ecx = 5415764 /*0x52a354*/;
    // 0052205c  891dac6a9f00           -mov dword ptr [0x9f6aac], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447532) /* 0x9f6aac */) = cpu.ebx;
    // 00522062  8935b06a9f00           -mov dword ptr [0x9f6ab0], esi
    app->getMemory<x86::reg32>(x86::reg32(10447536) /* 0x9f6ab0 */) = cpu.esi;
    // 00522068  893db46a9f00           -mov dword ptr [0x9f6ab4], edi
    app->getMemory<x86::reg32>(x86::reg32(10447540) /* 0x9f6ab4 */) = cpu.edi;
    // 0052206e  892db86a9f00           -mov dword ptr [0x9f6ab8], ebp
    app->getMemory<x86::reg32>(x86::reg32(10447544) /* 0x9f6ab8 */) = cpu.ebp;
    // 00522074  a3bc6a9f00             -mov dword ptr [0x9f6abc], eax
    app->getMemory<x86::reg32>(x86::reg32(10447548) /* 0x9f6abc */) = cpu.eax;
    // 00522079  8915c06a9f00           -mov dword ptr [0x9f6ac0], edx
    app->getMemory<x86::reg32>(x86::reg32(10447552) /* 0x9f6ac0 */) = cpu.edx;
    // 0052207f  bbb4a55200             -mov ebx, 0x52a5b4
    cpu.ebx = 5416372 /*0x52a5b4*/;
    // 00522084  890dc46a9f00           -mov dword ptr [0x9f6ac4], ecx
    app->getMemory<x86::reg32>(x86::reg32(10447556) /* 0x9f6ac4 */) = cpu.ecx;
    // 0052208a  891dc86a9f00           -mov dword ptr [0x9f6ac8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447560) /* 0x9f6ac8 */) = cpu.ebx;
    // 00522090  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00522092  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522093  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522094  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522095  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522096  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522097  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522098  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5220a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005220a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005220a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005220a2  833db443560000         +cmp dword ptr [0x5643b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005220a9  7425                   -je 0x5220d0
    if (cpu.flags.zf)
    {
        goto L_0x005220d0;
    }
    // 005220ab  bf90a75200             -mov edi, 0x52a790
    cpu.edi = 5416848 /*0x52a790*/;
    // 005220b0  bd70a95200             -mov ebp, 0x52a970
    cpu.ebp = 5417328 /*0x52a970*/;
    // 005220b5  b870ab5200             -mov eax, 0x52ab70
    cpu.eax = 5417840 /*0x52ab70*/;
    // 005220ba  893dcc6a9f00           -mov dword ptr [0x9f6acc], edi
    app->getMemory<x86::reg32>(x86::reg32(10447564) /* 0x9f6acc */) = cpu.edi;
    // 005220c0  892dd46a9f00           -mov dword ptr [0x9f6ad4], ebp
    app->getMemory<x86::reg32>(x86::reg32(10447572) /* 0x9f6ad4 */) = cpu.ebp;
    // 005220c6  a3d86a9f00             -mov dword ptr [0x9f6ad8], eax
    app->getMemory<x86::reg32>(x86::reg32(10447576) /* 0x9f6ad8 */) = cpu.eax;
    // 005220cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005220cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005220ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005220cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005220d0:
    // 005220d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005220d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005220d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005220d3  b928ad5200             -mov ecx, 0x52ad28
    cpu.ecx = 5418280 /*0x52ad28*/;
    // 005220d8  bb30af5200             -mov ebx, 0x52af30
    cpu.ebx = 5418800 /*0x52af30*/;
    // 005220dd  be60b15200             -mov esi, 0x52b160
    cpu.esi = 5419360 /*0x52b160*/;
    // 005220e2  890dcc6a9f00           -mov dword ptr [0x9f6acc], ecx
    app->getMemory<x86::reg32>(x86::reg32(10447564) /* 0x9f6acc */) = cpu.ecx;
    // 005220e8  891dd46a9f00           -mov dword ptr [0x9f6ad4], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447572) /* 0x9f6ad4 */) = cpu.ebx;
    // 005220ee  8935d86a9f00           -mov dword ptr [0x9f6ad8], esi
    app->getMemory<x86::reg32>(x86::reg32(10447576) /* 0x9f6ad8 */) = cpu.esi;
    // 005220f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005220f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005220f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005220f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005220f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005220fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005220fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_522100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522100  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00522103  b880ffffff             -mov eax, 0xffffff80
    cpu.eax = 4294967168 /*0xffffff80*/;
    // 00522108  dd0594185500           -fld qword ptr [0x551894]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5576852) /* 0x551894 */)));
L_0x0052210e:
    // 0052210e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00522111  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00522113  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00522116  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00522118  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0052211a  40                     -inc eax
    (cpu.eax)++;
    // 0052211b  d91c95a0c2a000         -fstp dword ptr [edx*4 + 0xa0c2a0]
    app->getMemory<float>(x86::reg32(10535584) /* 0xa0c2a0 */ + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00522122  83f87f                 +cmp eax, 0x7f
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
    // 00522125  7ee7                   -jle 0x52210e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052210e;
    }
    // 00522127  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00522129  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052212c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_522130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522130  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522131  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00522132  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00522133  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00522136  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00522138  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0052213d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052213e  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00522142  2eff1580455300         -call dword ptr cs:[0x534580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457280) /* 0x534580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522149  833d90ad560000         +cmp dword ptr [0x56ad90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680528) /* 0x56ad90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522150  750b                   -jne 0x52215d
    if (!cpu.flags.zf)
    {
        goto L_0x0052215d;
    }
    // 00522152  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00522156  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00522159  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052215a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052215b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052215c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052215d:
    // 0052215d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052215e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052215f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00522160  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00522164  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00522165  689c185500             -push 0x55189c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5576860 /*0x55189c*/;
    cpu.esp -= 4;
    // 0052216a  e881e7fbff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 0052216f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00522172  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00522176  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522177  68b0185500             -push 0x5518b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5576880 /*0x5518b0*/;
    cpu.esp -= 4;
    // 0052217c  e86fe7fbff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 00522181  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00522184  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00522188  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00522189  68c4185500             -push 0x5518c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5576900 /*0x5518c4*/;
    cpu.esp -= 4;
    // 0052218e  e85de7fbff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 00522193  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00522196  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052219a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052219b  68d8185500             -push 0x5518d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5576920 /*0x5518d8*/;
    cpu.esp -= 4;
    // 005221a0  e84be7fbff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 005221a5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005221a8  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 005221ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005221ad  68ec185500             -push 0x5518ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5576940 /*0x5518ec*/;
    cpu.esp -= 4;
    // 005221b2  e839e7fbff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 005221b7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005221ba  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 005221be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005221bf  6800195500             -push 0x551900
    app->getMemory<x86::reg32>(cpu.esp-4) = 5576960 /*0x551900*/;
    cpu.esp -= 4;
    // 005221c4  e827e7fbff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 005221c9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005221cc  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 005221d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005221d1  6814195500             -push 0x551914
    app->getMemory<x86::reg32>(cpu.esp-4) = 5576980 /*0x551914*/;
    cpu.esp -= 4;
    // 005221d6  e815e7fbff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 005221db  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005221de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005221df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005221e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005221e1  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005221e5  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005221e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005221e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005221ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005221eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_5221f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005221f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005221f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005221f2  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005221f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005221f7  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 005221fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005221fd  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00522201  2eff1580455300         -call dword ptr cs:[0x534580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457280) /* 0x534580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522208  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052220c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0052220f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522210  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522211  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_522220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522220  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522221  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00522222  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00522225  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00522227  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0052222c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052222d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00522231  2eff1580455300         -call dword ptr cs:[0x534580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457280) /* 0x534580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522238  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052223c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0052223f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522240  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522241  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_522250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522250  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522251  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00522252  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00522255  ba00006000             -mov edx, 0x600000
    cpu.edx = 6291456 /*0x600000*/;
    // 0052225a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052225c  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 00522261  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00522262  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00522266  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052226a  2eff1580455300         -call dword ptr cs:[0x534580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457280) /* 0x534580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522271  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00522275  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00522276  683f000f00             -push 0xf003f
    app->getMemory<x86::reg32>(cpu.esp-4) = 983103 /*0xf003f*/;
    cpu.esp -= 4;
    // 0052227b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052227d  6828195500             -push 0x551928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577000 /*0x551928*/;
    cpu.esp -= 4;
    // 00522282  6806000080             -push 0x80000006
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483654 /*0x80000006*/;
    cpu.esp -= 4;
    // 00522287  2eff156c445300         -call dword ptr cs:[0x53446c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457004) /* 0x53446c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052228e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00522290  740e                   -je 0x5222a0
    if (cpu.flags.zf)
    {
        goto L_0x005222a0;
    }
    // 00522292  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522296  2b442420               -sub eax, dword ptr [esp + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052229a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0052229d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052229e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052229f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005222a0:
    // 005222a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005222a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005222a2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005222a3  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 005222a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005222a8  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 005222ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005222ad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005222af  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005222b1  683c195500             -push 0x55193c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577020 /*0x55193c*/;
    cpu.esp -= 4;
    // 005222b6  8b742444               -mov esi, dword ptr [esp + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 005222ba  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 005222bf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005222c0  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 005222c4  2eff1570445300         -call dword ptr cs:[0x534470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457008) /* 0x534470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005222cb  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 005222cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005222d0  2eff1564445300         -call dword ptr cs:[0x534464]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5456996) /* 0x534464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005222d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005222d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005222d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005222da  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005222de  2b442420               -sub eax, dword ptr [esp + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 005222e2  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 005222e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005222e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005222e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5222f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005222f0  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 005222f2  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 005222f4  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005222f7  740a                   -je 0x522303
    if (cpu.flags.zf)
    {
        goto L_0x00522303;
    }
    // 005222f9  7d09                   -jge 0x522304
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00522304;
    }
    // 005222fb  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 005222fe  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 00522301  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00522303:
    // 00522303  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00522304:
    // 00522304  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 00522309  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052230b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052230d  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00522310  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 00522313  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00522315  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_522320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522320  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522321  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00522322  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00522323  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00522326  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0052232a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052232d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052232f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00522331  e88a8e0000             -call 0x52b1c0
    cpu.esp -= 4;
    sub_52b1c0(app, cpu);
    if (cpu.terminate) return;
    // 00522336  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052233a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052233c  0f8c93000000           -jl 0x5223d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005223d5;
    }
L_0x00522342:
    // 00522342  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00522346  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00522348  0f8ca1000000           -jl 0x5223ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005223ef;
    }
    // 0052234e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00522350  0f8c99000000           -jl 0x5223ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005223ef;
    }
    // 00522356  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522358  0f8e87000000           -jle 0x5223e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005223e5;
    }
L_0x0052235e:
    // 0052235e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00522363:
    // 00522363  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00522366  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00522368  81f900400000           +cmp ecx, 0x4000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052236e  0f8cc5000000           -jl 0x522439
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00522439;
    }
    // 00522374  81f900c00000           +cmp ecx, 0xc000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49152 /*0xc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052237a  0f8db9000000           -jge 0x522439
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00522439;
    }
    // 00522380  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00522382  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522384  0f8da5000000           -jge 0x52242f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052242f;
    }
    // 0052238a  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
L_0x0052238f:
    // 0052238f  83f802                 +cmp eax, 2
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
    // 00522392  7f13                   -jg 0x5223a7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005223a7;
    }
    // 00522394  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00522399  83f903                 +cmp ecx, 3
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
    // 0052239c  7509                   -jne 0x5223a7
    if (!cpu.flags.zf)
    {
        goto L_0x005223a7;
    }
    // 0052239e  39d0                   +cmp eax, edx
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
L_0x005223a0:
    // 005223a0  7505                   -jne 0x5223a7
    if (!cpu.flags.zf)
    {
        goto L_0x005223a7;
    }
    // 005223a2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x005223a7:
    // 005223a7  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 005223ac  0f8cb7000000           -jl 0x522469
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00522469;
    }
L_0x005223b2:
    // 005223b2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005223b4  0f8cbb000000           -jl 0x522475
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00522475;
    }
L_0x005223ba:
    // 005223ba  83fa01                 +cmp edx, 1
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
    // 005223bd  0f84be000000           -je 0x522481
    if (cpu.flags.zf)
    {
        goto L_0x00522481;
    }
    // 005223c3  83fa02                 +cmp edx, 2
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
    // 005223c6  0f84c5000000           -je 0x522491
    if (cpu.flags.zf)
    {
        goto L_0x00522491;
    }
    // 005223cc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005223cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005223d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005223d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005223d2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x005223d5:
    // 005223d5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005223d7  0f8d65ffffff           -jge 0x522342
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00522342;
    }
    // 005223dd  39d5                   +cmp ebp, edx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005223df  0f8e79ffffff           -jle 0x52235e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052235e;
    }
L_0x005223e5:
    // 005223e5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005223ea  e974ffffff             -jmp 0x522363
    goto L_0x00522363;
L_0x005223ef:
    // 005223ef  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005223f3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005223f5  7e16                   -jle 0x52240d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052240d;
    }
    // 005223f7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x005223f9:
    // 005223f9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005223fb  7e16                   -jle 0x522413
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00522413;
    }
    // 005223fd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 005223ff  39d0                   +cmp eax, edx
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
    // 00522401  7e22                   -jle 0x522425
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00522425;
    }
    // 00522403  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00522408  e956ffffff             -jmp 0x522363
    goto L_0x00522363;
L_0x0052240d:
    // 0052240d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052240f  f7d8                   +neg eax
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.eax;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00522411  ebe6                   -jmp 0x5223f9
    goto L_0x005223f9;
L_0x00522413:
    // 00522413  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00522415  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00522417  39d0                   +cmp eax, edx
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
    // 00522419  7e0a                   -jle 0x522425
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00522425;
    }
    // 0052241b  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00522420  e93effffff             -jmp 0x522363
    goto L_0x00522363;
L_0x00522425:
    // 00522425  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0052242a  e934ffffff             -jmp 0x522363
    goto L_0x00522363;
L_0x0052242f:
    // 0052242f  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00522434  e956ffffff             -jmp 0x52238f
    goto L_0x0052238f;
L_0x00522439:
    // 00522439  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0052243b  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052243d  7d23                   -jge 0x522462
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00522462;
    }
    // 0052243f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x00522444:
    // 00522444  83f803                 +cmp eax, 3
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
    // 00522447  0f8c5affffff           -jl 0x5223a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005223a7;
    }
    // 0052244d  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00522452  39d1                   +cmp ecx, edx
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
    // 00522454  0f854dffffff           -jne 0x5223a7
    if (!cpu.flags.zf)
    {
        goto L_0x005223a7;
    }
    // 0052245a  83f803                 +cmp eax, 3
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
    // 0052245d  e93effffff             -jmp 0x5223a0
    goto L_0x005223a0;
L_0x00522462:
    // 00522462  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00522467  ebdb                   -jmp 0x522444
    goto L_0x00522444;
L_0x00522469:
    // 00522469  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0052246b  6bc1ff                 +imul eax, ecx, -1
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0052246e  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00522470  e93dffffff             -jmp 0x5223b2
    goto L_0x005223b2;
L_0x00522475:
    // 00522475  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00522477  6bc3ff                 +imul eax, ebx, -1
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0052247a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0052247c  e939ffffff             -jmp 0x5223ba
    goto L_0x005223ba;
L_0x00522481:
    // 00522481  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 00522483  6bc5ff                 -imul eax, ebp, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 00522486  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00522488  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052248b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052248c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052248d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052248e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00522491:
    // 00522491  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00522493  6bc7ff                 -imul eax, edi, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 00522496  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00522498  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052249b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052249c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052249d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052249e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5224b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005224b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005224b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005224b2  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 005224b4  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 005224b6  e8058d0000             -call 0x52b1c0
    cpu.esp -= 4;
    sub_52b1c0(app, cpu);
    if (cpu.terminate) return;
    // 005224bb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 005224bd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005224bf  7c09                   -jl 0x5224ca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005224ca;
    }
    // 005224c1  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 005224c3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005224c5  7c11                   -jl 0x5224d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005224d8;
    }
    // 005224c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005224c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005224c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005224ca:
    // 005224ca  6bc2ff                 -imul eax, edx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 005224cd  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 005224cf  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 005224d1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005224d3  7c03                   -jl 0x5224d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005224d8;
    }
    // 005224d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005224d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005224d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005224d8:
    // 005224d8  6bc3ff                 -imul eax, ebx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 005224db  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 005224dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005224de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005224df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5224e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005224e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005224e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005224e3  3d00000100             +cmp eax, 0x10000
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
    // 005224e8  7f1b                   -jg 0x522505
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00522505;
    }
    // 005224ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005224ec  7c1e                   -jl 0x52250c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052250c;
    }
L_0x005224ee:
    // 005224ee  e895e8fbff             -call 0x4e0d88
    cpu.esp -= 4;
    sub_4e0d88(app, cpu);
    if (cpu.terminate) return;
    // 005224f3  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
    // 005224f8  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 005224fd  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00522500  c1f80e                 +sar eax, 0xe
    {
        x86::reg8 tmp = 14 /*0xe*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00522503  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522504  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00522505:
    // 00522505  ba00000100             -mov edx, 0x10000
    cpu.edx = 65536 /*0x10000*/;
    // 0052250a  ebe2                   -jmp 0x5224ee
    goto L_0x005224ee;
L_0x0052250c:
    // 0052250c  31c2                   +xor edx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052250e  ebde                   -jmp 0x5224ee
    goto L_0x005224ee;
}

/* align: skip  */
void Application::sub_522510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522510  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522511  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00522512  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00522513  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 00522516  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052251a  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0052251e  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00522522  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00522526  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0052252b  be22560000             -mov esi, 0x5622
    cpu.esi = 22050 /*0x5622*/;
    // 00522530  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00522535  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00522537  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00522539  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0052253d  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00522541  89542444               -mov dword ptr [esp + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 00522545  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00522547  8974243c               -mov dword ptr [esp + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 0052254b  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0052254f  894c2440               -mov dword ptr [esp + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 00522553  894c2450               -mov dword ptr [esp + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 00522557  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0052255c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052255e  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00522562  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00522565  ba58f69e00             -mov edx, 0x9ef658
    cpu.edx = 10417752 /*0x9ef658*/;
    // 0052256a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0052256c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052256e  8a842480000000         -mov al, byte ptr [esp + 0x80]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00522575  89742430               -mov dword ptr [esp + 0x30], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.esi;
    // 00522579  884206                 -mov byte ptr [edx + 6], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 0052257c  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00522580  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00522584  6689420a               -mov word ptr [edx + 0xa], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = cpu.ax;
L_0x00522588:
    // 00522588  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052258c  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00522590  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00522594  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522598  e833040000             -call 0x5229d0
    cpu.esp -= 4;
    sub_5229d0(app, cpu);
    if (cpu.terminate) return;
    // 0052259d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052259f  0f84e5000000           -je 0x52268a
    if (cpu.flags.zf)
    {
        goto L_0x0052268a;
    }
    // 005225a5  8b4c2458               -mov ecx, dword ptr [esp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 005225a9  81f98a000000           +cmp ecx, 0x8a
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(138 /*0x8a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005225af  750a                   -jne 0x5225bb
    if (!cpu.flags.zf)
    {
        goto L_0x005225bb;
    }
    // 005225b1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005225b5  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 005225b9  ebcd                   -jmp 0x522588
    goto L_0x00522588;
L_0x005225bb:
    // 005225bb  81f993000000           +cmp ecx, 0x93
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(147 /*0x93*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005225c1  750a                   -jne 0x5225cd
    if (!cpu.flags.zf)
    {
        goto L_0x005225cd;
    }
    // 005225c3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005225c7  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 005225cb  ebbb                   -jmp 0x522588
    goto L_0x00522588;
L_0x005225cd:
    // 005225cd  81f985000000           +cmp ecx, 0x85
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(133 /*0x85*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005225d3  750a                   -jne 0x5225df
    if (!cpu.flags.zf)
    {
        goto L_0x005225df;
    }
    // 005225d5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005225d9  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 005225dd  eba9                   -jmp 0x522588
    goto L_0x00522588;
L_0x005225df:
    // 005225df  81f981000000           +cmp ecx, 0x81
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(129 /*0x81*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005225e5  750a                   -jne 0x5225f1
    if (!cpu.flags.zf)
    {
        goto L_0x005225f1;
    }
    // 005225e7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005225eb  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 005225ef  eb97                   -jmp 0x522588
    goto L_0x00522588;
L_0x005225f1:
    // 005225f1  81f982000000           +cmp ecx, 0x82
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(130 /*0x82*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005225f7  750a                   -jne 0x522603
    if (!cpu.flags.zf)
    {
        goto L_0x00522603;
    }
    // 005225f9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005225fd  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00522601  eb85                   -jmp 0x522588
    goto L_0x00522588;
L_0x00522603:
    // 00522603  81f984000000           +cmp ecx, 0x84
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522609  750d                   -jne 0x522618
    if (!cpu.flags.zf)
    {
        goto L_0x00522618;
    }
    // 0052260b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052260f  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 00522613  e970ffffff             -jmp 0x522588
    goto L_0x00522588;
L_0x00522618:
    // 00522618  81f983000000           +cmp ecx, 0x83
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052261e  750d                   -jne 0x52262d
    if (!cpu.flags.zf)
    {
        goto L_0x0052262d;
    }
    // 00522620  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00522624  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00522628  e95bffffff             -jmp 0x522588
    goto L_0x00522588;
L_0x0052262d:
    // 0052262d  81f986000000           +cmp ecx, 0x86
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(134 /*0x86*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522633  7509                   -jne 0x52263e
    if (!cpu.flags.zf)
    {
        goto L_0x0052263e;
    }
    // 00522635  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00522639  e94affffff             -jmp 0x522588
    goto L_0x00522588;
L_0x0052263e:
    // 0052263e  81f987000000           +cmp ecx, 0x87
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(135 /*0x87*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522644  7512                   -jne 0x522658
    if (!cpu.flags.zf)
    {
        goto L_0x00522658;
    }
    // 00522646  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052264b  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052264f  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00522653  e930ffffff             -jmp 0x522588
    goto L_0x00522588;
L_0x00522658:
    // 00522658  81f991000000           +cmp ecx, 0x91
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(145 /*0x91*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052265e  7509                   -jne 0x522669
    if (!cpu.flags.zf)
    {
        goto L_0x00522669;
    }
    // 00522660  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00522664  e91fffffff             -jmp 0x522588
    goto L_0x00522588;
L_0x00522669:
    // 00522669  81f992000000           +cmp ecx, 0x92
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(146 /*0x92*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052266f  750d                   -jne 0x52267e
    if (!cpu.flags.zf)
    {
        goto L_0x0052267e;
    }
    // 00522671  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00522675  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00522679  e90affffff             -jmp 0x522588
    goto L_0x00522588;
L_0x0052267e:
    // 0052267e  81f9fe000000           +cmp ecx, 0xfe
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522684  0f85fefeffff           -jne 0x522588
    if (!cpu.flags.zf)
    {
        goto L_0x00522588;
    }
L_0x0052268a:
    // 0052268a  837c242002             +cmp dword ptr [esp + 0x20], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052268f  0f85f9000000           -jne 0x52278e
    if (!cpu.flags.zf)
    {
        goto L_0x0052278e;
    }
    // 00522695  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00522697  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0052269c  895c2444               -mov dword ptr [esp + 0x44], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ebx;
    // 005226a0  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x005226a2:
    // 005226a2  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 005226a6  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 005226aa  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 005226ad  8a442448               -mov al, byte ptr [esp + 0x48]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 005226b1  884202                 -mov byte ptr [edx + 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 005226b4  8a44244c               -mov al, byte ptr [esp + 0x4c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 005226b8  884203                 -mov byte ptr [edx + 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 005226bb  8a442440               -mov al, byte ptr [esp + 0x40]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 005226bf  884204                 -mov byte ptr [edx + 4], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 005226c2  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 005226c6  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005226c9  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 005226cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005226cf  0f85d6000000           -jne 0x5227ab
    if (!cpu.flags.zf)
    {
        goto L_0x005227ab;
    }
L_0x005226d5:
    // 005226d5  83bc248000000000       +cmp dword ptr [esp + 0x80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005226dd  0f846e010000           -je 0x522851
    if (cpu.flags.zf)
    {
        goto L_0x00522851;
    }
    // 005226e3  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005226e7  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005226eb  8b54246c               -mov edx, dword ptr [esp + 0x6c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 005226ef  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005226f3  e8f8fbffff             -call 0x5222f0
    cpu.esp -= 4;
    sub_5222f0(app, cpu);
    if (cpu.terminate) return;
L_0x005226f8:
    // 005226f8  837c244810             +cmp dword ptr [esp + 0x48], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005226fd  0f853a020000           -jne 0x52293d
    if (!cpu.flags.zf)
    {
        goto L_0x0052293d;
    }
    // 00522703  837c244c01             +cmp dword ptr [esp + 0x4c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522708  0f852f020000           -jne 0x52293d
    if (!cpu.flags.zf)
    {
        goto L_0x0052293d;
    }
    // 0052270e  c744242804000000       -mov dword ptr [esp + 0x28], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 4 /*0x4*/;
L_0x00522716:
    // 00522716  8b5c2470               -mov ebx, dword ptr [esp + 0x70]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0052271a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052271c  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00522720  668b1514f69e00         -mov dx, word ptr [0x9ef614]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10417684) /* 0x9ef614 */);
    // 00522727  e8e4070000             -call 0x522f10
    cpu.esp -= 4;
    sub_522f10(app, cpu);
    if (cpu.terminate) return;
    // 0052272c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052272e  a114f69e00             -mov eax, dword ptr [0x9ef614]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417684) /* 0x9ef614 */);
    // 00522733  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00522736  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00522738  83fe64                 +cmp esi, 0x64
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052273b  0f8e7b020000           -jle 0x5229bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005229bc;
    }
    // 00522741  be64000000             -mov esi, 0x64
    cpu.esi = 100 /*0x64*/;
L_0x00522746:
    // 00522746  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0052274a  8a442450               -mov al, byte ptr [esp + 0x50]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0052274e  884105                 -mov byte ptr [ecx + 5], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.al;
    // 00522751  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00522755  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522756  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522757  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00522758  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0052275c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052275d  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00522761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522762  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00522763  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00522767  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00522768  8b7c2460               -mov edi, dword ptr [esp + 0x60]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0052276c  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00522770  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00522771  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 00522773  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00522777  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00522778  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0052277c  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00522780  e833d9fdff             -call 0x5000b8
    cpu.esp -= 4;
    sub_5000b8(app, cpu);
    if (cpu.terminate) return;
    // 00522785  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 00522788  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522789  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052278a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052278b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0052278e:
    // 0052278e  83fdff                 +cmp ebp, -1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522791  7d05                   -jge 0x522798
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00522798;
    }
    // 00522793  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
L_0x00522798:
    // 00522798  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052279b  0f8d01ffffff           -jge 0x5226a2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005226a2;
    }
    // 005227a1  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 005227a6  e9f7feffff             -jmp 0x5226a2
    goto L_0x005226a2;
L_0x005227ab:
    // 005227ab  83f802                 +cmp eax, 2
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
    // 005227ae  0f8421ffffff           -je 0x5226d5
    if (cpu.flags.zf)
    {
        goto L_0x005226d5;
    }
    // 005227b4  83f801                 +cmp eax, 1
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
    // 005227b7  0f85ae000000           -jne 0x52286b
    if (!cpu.flags.zf)
    {
        goto L_0x0052286b;
    }
    // 005227bd  3b44244c               +cmp eax, dword ptr [esp + 0x4c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005227c1  742d                   -je 0x5227f0
    if (cpu.flags.zf)
    {
        goto L_0x005227f0;
    }
    // 005227c3  b84c195500             -mov eax, 0x55194c
    cpu.eax = 5577036 /*0x55194c*/;
    // 005227c8  ba5c195500             -mov edx, 0x55195c
    cpu.edx = 5577052 /*0x55195c*/;
    // 005227cd  b97c000000             -mov ecx, 0x7c
    cpu.ecx = 124 /*0x7c*/;
    // 005227d2  6870195500             -push 0x551970
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577072 /*0x551970*/;
    cpu.esp -= 4;
    // 005227d7  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 005227dc  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 005227e2  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 005227e8  e823e8edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005227ed  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005227f0:
    // 005227f0  83bc248000000000       +cmp dword ptr [esp + 0x80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005227f8  7412                   -je 0x52280c
    if (cpu.flags.zf)
    {
        goto L_0x0052280c;
    }
    // 005227fa  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005227fe  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00522801  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00522805  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00522808  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
L_0x0052280c:
    // 0052280c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00522810  8b4006                 -mov eax, dword ptr [eax + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00522813  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00522816  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00522817  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0052281b  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0052281e  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00522822  c1f818                 +sar eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00522825  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00522829  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052282a  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0052282e  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00522835  e8e6faffff             -call 0x522320
    cpu.esp -= 4;
    sub_522320(app, cpu);
    if (cpu.terminate) return;
    // 0052283a  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0052283e  8a442414               -mov al, byte ptr [esp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00522842  884208                 -mov byte ptr [edx + 8], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 00522845  8a44241c               -mov al, byte ptr [esp + 0x1c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00522849  884209                 -mov byte ptr [edx + 9], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 0052284c  e9a7feffff             -jmp 0x5226f8
    goto L_0x005226f8;
L_0x00522851:
    // 00522851  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00522855  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00522859  8b54246c               -mov edx, dword ptr [esp + 0x6c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0052285d  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00522861  e84afcffff             -call 0x5224b0
    cpu.esp -= 4;
    sub_5224b0(app, cpu);
    if (cpu.terminate) return;
    // 00522866  e98dfeffff             -jmp 0x5226f8
    goto L_0x005226f8;
L_0x0052286b:
    // 0052286b  83f803                 +cmp eax, 3
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
    // 0052286e  0f8597000000           -jne 0x52290b
    if (!cpu.flags.zf)
    {
        goto L_0x0052290b;
    }
    // 00522874  83bc248000000000       +cmp dword ptr [esp + 0x80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052287c  7418                   -je 0x522896
    if (cpu.flags.zf)
    {
        goto L_0x00522896;
    }
    // 0052287e  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00522882  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00522885  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00522887  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0052288b  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0052288e  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 00522892  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
L_0x00522896:
    // 00522896  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0052289a  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0052289e  8b4c247c               -mov ecx, dword ptr [esp + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 005228a2  e8e9050000             -call 0x522e90
    cpu.esp -= 4;
    sub_522e90(app, cpu);
    if (cpu.terminate) return;
    // 005228a7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005228a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005228aa  8b5c247c               -mov ebx, dword ptr [esp + 0x7c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 005228ae  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 005228b1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005228b2  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 005228b6  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 005228ba  db44245c               -fild dword ptr [esp + 0x5c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */))));
    // 005228be  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005228c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005228c1  e890d4fbff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 005228c6  df7c240c               -fistp qword ptr [esp + 0xc]
    app->getMemory<x86::reg64>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005228ca  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005228ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005228cf  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 005228d3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005228d4  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 005228d8  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 005228dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005228dd  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005228df  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005228e0  ff1540f69e00           -call dword ptr [0x9ef640]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417728) /* 0x9ef640 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005228e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005228e8  7c16                   -jl 0x522900
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00522900;
    }
    // 005228ea  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 005228ee  8a442450               -mov al, byte ptr [esp + 0x50]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 005228f2  884205                 -mov byte ptr [edx + 5], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5) /* 0x5 */) = cpu.al;
    // 005228f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005228f7  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 005228fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005228fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005228fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005228fd  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00522900:
    // 00522900  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00522902  894c2450               -mov dword ptr [esp + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 00522906  e9cafdffff             -jmp 0x5226d5
    goto L_0x005226d5;
L_0x0052290b:
    // 0052290b  b84c195500             -mov eax, 0x55194c
    cpu.eax = 5577036 /*0x55194c*/;
    // 00522910  ba5c195500             -mov edx, 0x55195c
    cpu.edx = 5577052 /*0x55195c*/;
    // 00522915  b9ad000000             -mov ecx, 0xad
    cpu.ecx = 173 /*0xad*/;
    // 0052291a  68ac195500             -push 0x5519ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577132 /*0x5519ac*/;
    cpu.esp -= 4;
    // 0052291f  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 00522924  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 0052292a  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 00522930  e8dbe6edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00522935  83c404                 +add esp, 4
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
    // 00522938  e9bbfdffff             -jmp 0x5226f8
    goto L_0x005226f8;
L_0x0052293d:
    // 0052293d  837c244810             +cmp dword ptr [esp + 0x48], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522942  7514                   -jne 0x522958
    if (!cpu.flags.zf)
    {
        goto L_0x00522958;
    }
    // 00522944  837c244c02             +cmp dword ptr [esp + 0x4c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522949  750d                   -jne 0x522958
    if (!cpu.flags.zf)
    {
        goto L_0x00522958;
    }
    // 0052294b  c744242808000000       -mov dword ptr [esp + 0x28], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 8 /*0x8*/;
    // 00522953  e9befdffff             -jmp 0x522716
    goto L_0x00522716;
L_0x00522958:
    // 00522958  837c244808             +cmp dword ptr [esp + 0x48], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052295d  7512                   -jne 0x522971
    if (!cpu.flags.zf)
    {
        goto L_0x00522971;
    }
    // 0052295f  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00522963  83fb01                 +cmp ebx, 1
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
    // 00522966  7509                   -jne 0x522971
    if (!cpu.flags.zf)
    {
        goto L_0x00522971;
    }
    // 00522968  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0052296c  e9a5fdffff             -jmp 0x522716
    goto L_0x00522716;
L_0x00522971:
    // 00522971  837c244808             +cmp dword ptr [esp + 0x48], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522976  7512                   -jne 0x52298a
    if (!cpu.flags.zf)
    {
        goto L_0x0052298a;
    }
    // 00522978  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0052297c  83fa02                 +cmp edx, 2
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
    // 0052297f  7509                   -jne 0x52298a
    if (!cpu.flags.zf)
    {
        goto L_0x0052298a;
    }
    // 00522981  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00522985  e98cfdffff             -jmp 0x522716
    goto L_0x00522716;
L_0x0052298a:
    // 0052298a  b94c195500             -mov ecx, 0x55194c
    cpu.ecx = 5577036 /*0x55194c*/;
    // 0052298f  bb5c195500             -mov ebx, 0x55195c
    cpu.ebx = 5577052 /*0x55195c*/;
    // 00522994  b8be000000             -mov eax, 0xbe
    cpu.eax = 190 /*0xbe*/;
    // 00522999  68e0195500             -push 0x5519e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577184 /*0x5519e0*/;
    cpu.esp -= 4;
    // 0052299e  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 005229a4  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 005229aa  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 005229af  e85ce6edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005229b4  83c404                 +add esp, 4
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
    // 005229b7  e95afdffff             -jmp 0x522716
    goto L_0x00522716;
L_0x005229bc:
    // 005229bc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005229be  0f8d82fdffff           -jge 0x522746
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00522746;
    }
    // 005229c4  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 005229c6  e97bfdffff             -jmp 0x522746
    goto L_0x00522746;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5229d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005229d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005229d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005229d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005229d3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005229d5  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x005229d7:
    // 005229d7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 005229d9  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 005229db  80f9fc                 +cmp cl, 0xfc
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005229de  0f847a000000           -je 0x522a5e
    if (cpu.flags.zf)
    {
        goto L_0x00522a5e;
    }
    // 005229e4  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 005229e6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005229eb  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 005229ed  3dff000000             +cmp eax, 0xff
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
    // 005229f2  0f846e000000           -je 0x522a66
    if (cpu.flags.zf)
    {
        goto L_0x00522a66;
    }
    // 005229f8  8b2e                   -mov ebp, dword ptr [esi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi);
    // 005229fa  45                     -inc ebp
    (cpu.ebp)++;
    // 005229fb  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 005229fd  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 005229ff  3dfd000000             +cmp eax, 0xfd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522a04  7466                   -je 0x522a6c
    if (cpu.flags.zf)
    {
        goto L_0x00522a6c;
    }
    // 00522a06  3dfe000000             +cmp eax, 0xfe
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522a0b  745f                   -je 0x522a6c
    if (cpu.flags.zf)
    {
        goto L_0x00522a6c;
    }
    // 00522a0d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00522a0f  8a4d00                 -mov cl, byte ptr [ebp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00522a12  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00522a14  81f9ff000000           +cmp ecx, 0xff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522a1a  7518                   -jne 0x522a34
    if (!cpu.flags.zf)
    {
        goto L_0x00522a34;
    }
    // 00522a1c  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00522a1f  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00522a24  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00522a26  e805880000             -call 0x52b230
    cpu.esp -= 4;
    sub_52b230(app, cpu);
    if (cpu.terminate) return;
    // 00522a2b  8b2e                   -mov ebp, dword ptr [esi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi);
    // 00522a2d  83c503                 -add ebp, 3
    (cpu.ebp) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00522a30  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00522a32  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
L_0x00522a34:
    // 00522a34  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00522a36  40                     -inc eax
    (cpu.eax)++;
    // 00522a37  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00522a39  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00522a3b  7c12                   -jl 0x522a4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00522a4f;
    }
    // 00522a3d  83f904                 +cmp ecx, 4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522a40  7f0d                   -jg 0x522a4f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00522a4f;
    }
    // 00522a42  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00522a44  e8e7870000             -call 0x52b230
    cpu.esp -= 4;
    sub_52b230(app, cpu);
    if (cpu.terminate) return;
    // 00522a49  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00522a4b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00522a4d  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x00522a4f:
    // 00522a4f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00522a51  01ca                   +add edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00522a53  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00522a58  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00522a5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522a5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522a5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522a5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00522a5e:
    // 00522a5e  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00522a5f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00522a61  e971ffffff             -jmp 0x5229d7
    goto L_0x005229d7;
L_0x00522a66:
    // 00522a66  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00522a68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522a69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522a6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522a6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00522a6c:
    // 00522a6c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00522a71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522a72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522a73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522a74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_522a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522a80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522a81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522a82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00522a83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00522a84  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00522a87  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00522a8a  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00522a8e  bd22560000             -mov ebp, 0x5622
    cpu.ebp = 22050 /*0x5622*/;
    // 00522a93  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00522a98  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00522a9a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00522a9c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00522a9e  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00522aa2  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 00522aa6  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00522aaa  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00522aae  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00522ab2  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00522ab6  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00522abb  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 00522ac0  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00522ac4  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
L_0x00522ac8:
    // 00522ac8  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00522acc  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522ad0  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00522ad4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00522ad6  e8f5feffff             -call 0x5229d0
    cpu.esp -= 4;
    sub_5229d0(app, cpu);
    if (cpu.terminate) return;
    // 00522adb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00522add  0f84e4000000           -je 0x522bc7
    if (cpu.flags.zf)
    {
        goto L_0x00522bc7;
    }
    // 00522ae3  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00522ae7  81fb88000000           +cmp ebx, 0x88
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522aed  750a                   -jne 0x522af9
    if (!cpu.flags.zf)
    {
        goto L_0x00522af9;
    }
    // 00522aef  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522af3  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00522af7  ebcf                   -jmp 0x522ac8
    goto L_0x00522ac8;
L_0x00522af9:
    // 00522af9  81fb8a000000           +cmp ebx, 0x8a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(138 /*0x8a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522aff  750a                   -jne 0x522b0b
    if (!cpu.flags.zf)
    {
        goto L_0x00522b0b;
    }
    // 00522b01  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00522b05  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00522b09  ebbd                   -jmp 0x522ac8
    goto L_0x00522ac8;
L_0x00522b0b:
    // 00522b0b  81fb93000000           +cmp ebx, 0x93
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(147 /*0x93*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522b11  7506                   -jne 0x522b19
    if (!cpu.flags.zf)
    {
        goto L_0x00522b19;
    }
    // 00522b13  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00522b17  ebaf                   -jmp 0x522ac8
    goto L_0x00522ac8;
L_0x00522b19:
    // 00522b19  81fb85000000           +cmp ebx, 0x85
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(133 /*0x85*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522b1f  750a                   -jne 0x522b2b
    if (!cpu.flags.zf)
    {
        goto L_0x00522b2b;
    }
    // 00522b21  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522b25  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00522b29  eb9d                   -jmp 0x522ac8
    goto L_0x00522ac8;
L_0x00522b2b:
    // 00522b2b  81fb81000000           +cmp ebx, 0x81
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(129 /*0x81*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522b31  7506                   -jne 0x522b39
    if (!cpu.flags.zf)
    {
        goto L_0x00522b39;
    }
    // 00522b33  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522b37  eb8f                   -jmp 0x522ac8
    goto L_0x00522ac8;
L_0x00522b39:
    // 00522b39  81fb82000000           +cmp ebx, 0x82
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(130 /*0x82*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522b3f  750d                   -jne 0x522b4e
    if (!cpu.flags.zf)
    {
        goto L_0x00522b4e;
    }
    // 00522b41  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522b45  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00522b49  e97affffff             -jmp 0x522ac8
    goto L_0x00522ac8;
L_0x00522b4e:
    // 00522b4e  81fb84000000           +cmp ebx, 0x84
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522b54  750d                   -jne 0x522b63
    if (!cpu.flags.zf)
    {
        goto L_0x00522b63;
    }
    // 00522b56  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522b5a  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00522b5e  e965ffffff             -jmp 0x522ac8
    goto L_0x00522ac8;
L_0x00522b63:
    // 00522b63  81fb83000000           +cmp ebx, 0x83
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522b69  7509                   -jne 0x522b74
    if (!cpu.flags.zf)
    {
        goto L_0x00522b74;
    }
    // 00522b6b  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522b6f  e954ffffff             -jmp 0x522ac8
    goto L_0x00522ac8;
L_0x00522b74:
    // 00522b74  81fb86000000           +cmp ebx, 0x86
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(134 /*0x86*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522b7a  750d                   -jne 0x522b89
    if (!cpu.flags.zf)
    {
        goto L_0x00522b89;
    }
    // 00522b7c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522b80  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00522b84  e93fffffff             -jmp 0x522ac8
    goto L_0x00522ac8;
L_0x00522b89:
    // 00522b89  81fb87000000           +cmp ebx, 0x87
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(135 /*0x87*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522b8f  750d                   -jne 0x522b9e
    if (!cpu.flags.zf)
    {
        goto L_0x00522b9e;
    }
    // 00522b91  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522b95  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00522b99  e92affffff             -jmp 0x522ac8
    goto L_0x00522ac8;
L_0x00522b9e:
    // 00522b9e  81fb92000000           +cmp ebx, 0x92
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(146 /*0x92*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522ba4  7515                   -jne 0x522bbb
    if (!cpu.flags.zf)
    {
        goto L_0x00522bbb;
    }
    // 00522ba6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522baa  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00522bae  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00522bb2  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00522bb6  e90dffffff             -jmp 0x522ac8
    goto L_0x00522ac8;
L_0x00522bbb:
    // 00522bbb  81fbfe000000           +cmp ebx, 0xfe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522bc1  0f8501ffffff           -jne 0x522ac8
    if (!cpu.flags.zf)
    {
        goto L_0x00522ac8;
    }
L_0x00522bc7:
    // 00522bc7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00522bcb  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00522bcf  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00522bd3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00522bd5  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00522bd7  837c242402             +cmp dword ptr [esp + 0x24], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522bdc  754d                   -jne 0x522c2b
    if (!cpu.flags.zf)
    {
        goto L_0x00522c2b;
    }
    // 00522bde  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00522be0  7456                   -je 0x522c38
    if (cpu.flags.zf)
    {
        goto L_0x00522c38;
    }
L_0x00522be2:
    // 00522be2  83fe07                 +cmp esi, 7
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
    // 00522be5  0f8580000000           -jne 0x522c6b
    if (!cpu.flags.zf)
    {
        goto L_0x00522c6b;
    }
    // 00522beb  c744241403000000       -mov dword ptr [esp + 0x14], 3
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 3 /*0x3*/;
L_0x00522bf3:
    // 00522bf3  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00522bf7  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00522bf9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00522bfa  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00522bfe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522bff  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00522c03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00522c04  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00522c08  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00522c09  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00522c0d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00522c0e  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00522c12  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522c13  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00522c17  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00522c18  ff1538f69e00           -call dword ptr [0x9ef638]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417720) /* 0x9ef638 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522c1e  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00522c20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00522c22  7407                   -je 0x522c2b
    if (cpu.flags.zf)
    {
        goto L_0x00522c2b;
    }
    // 00522c24  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00522c28  c60003                 -mov byte ptr [eax], 3
    app->getMemory<x86::reg8>(cpu.eax) = 3 /*0x3*/;
L_0x00522c2b:
    // 00522c2b  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00522c30  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00522c33  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522c34  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522c35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522c36  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522c37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00522c38:
    // 00522c38  ba101a5500             -mov edx, 0x551a10
    cpu.edx = 5577232 /*0x551a10*/;
    // 00522c3d  b9201a5500             -mov ecx, 0x551a20
    cpu.ecx = 5577248 /*0x551a20*/;
    // 00522c42  bb4e000000             -mov ebx, 0x4e
    cpu.ebx = 78 /*0x4e*/;
    // 00522c47  68341a5500             -push 0x551a34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577268 /*0x551a34*/;
    cpu.esp -= 4;
    // 00522c4c  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00522c52  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00522c58  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00522c5e  e8ade3edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00522c63  83c404                 +add esp, 4
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
    // 00522c66  e977ffffff             -jmp 0x522be2
    goto L_0x00522be2;
L_0x00522c6b:
    // 00522c6b  83fe09                 +cmp esi, 9
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522c6e  750d                   -jne 0x522c7d
    if (!cpu.flags.zf)
    {
        goto L_0x00522c7d;
    }
    // 00522c70  c744241404000000       -mov dword ptr [esp + 0x14], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 4 /*0x4*/;
    // 00522c78  e976ffffff             -jmp 0x522bf3
    goto L_0x00522bf3;
L_0x00522c7d:
    // 00522c7d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00522c7f  7554                   -jne 0x522cd5
    if (!cpu.flags.zf)
    {
        goto L_0x00522cd5;
    }
    // 00522c81  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522c84  7412                   -je 0x522c98
    if (cpu.flags.zf)
    {
        goto L_0x00522c98;
    }
    // 00522c86  83fd08                 +cmp ebp, 8
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522c89  7516                   -jne 0x522ca1
    if (!cpu.flags.zf)
    {
        goto L_0x00522ca1;
    }
    // 00522c8b  c744241402000000       -mov dword ptr [esp + 0x14], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 2 /*0x2*/;
    // 00522c93  e95bffffff             -jmp 0x522bf3
    goto L_0x00522bf3;
L_0x00522c98:
    // 00522c98  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00522c9c  e952ffffff             -jmp 0x522bf3
    goto L_0x00522bf3;
L_0x00522ca1:
    // 00522ca1  b9101a5500             -mov ecx, 0x551a10
    cpu.ecx = 5577232 /*0x551a10*/;
    // 00522ca6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00522ca7  bb201a5500             -mov ebx, 0x551a20
    cpu.ebx = 5577248 /*0x551a20*/;
    // 00522cac  be65000000             -mov esi, 0x65
    cpu.esi = 101 /*0x65*/;
    // 00522cb1  68901a5500             -push 0x551a90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577360 /*0x551a90*/;
    cpu.esp -= 4;
    // 00522cb6  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00522cbc  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00522cc2  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 00522cc8  e843e3edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00522ccd  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00522cd0  e91effffff             -jmp 0x522bf3
    goto L_0x00522bf3;
L_0x00522cd5:
    // 00522cd5  bd101a5500             -mov ebp, 0x551a10
    cpu.ebp = 5577232 /*0x551a10*/;
    // 00522cda  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522cdb  b8201a5500             -mov eax, 0x551a20
    cpu.eax = 5577248 /*0x551a20*/;
    // 00522ce0  ba6d000000             -mov edx, 0x6d
    cpu.edx = 109 /*0x6d*/;
    // 00522ce5  68c41a5500             -push 0x551ac4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577412 /*0x551ac4*/;
    cpu.esp -= 4;
    // 00522cea  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 00522cf0  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 00522cf5  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 00522cfb  e810e3edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00522d00  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00522d03  e9ebfeffff             -jmp 0x522bf3
    goto L_0x00522bf3;
}

/* align: skip  */
void Application::sub_522d08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522d08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00522d09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522d0a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522d0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00522d0c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00522d0d  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00522d10  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00522d13  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00522d15  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00522d17:
    // 00522d17  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00522d1b  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522d1f  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00522d23  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00522d25  e8a6fcffff             -call 0x5229d0
    cpu.esp -= 4;
    sub_5229d0(app, cpu);
    if (cpu.terminate) return;
    // 00522d2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00522d2c  742b                   -je 0x522d59
    if (cpu.flags.zf)
    {
        goto L_0x00522d59;
    }
    // 00522d2e  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00522d32  81fa93000000           +cmp edx, 0x93
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(147 /*0x93*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522d38  7506                   -jne 0x522d40
    if (!cpu.flags.zf)
    {
        goto L_0x00522d40;
    }
    // 00522d3a  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00522d3e  ebd7                   -jmp 0x522d17
    goto L_0x00522d17;
L_0x00522d40:
    // 00522d40  81fa92000000           +cmp edx, 0x92
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(146 /*0x92*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522d46  7509                   -jne 0x522d51
    if (!cpu.flags.zf)
    {
        goto L_0x00522d51;
    }
    // 00522d48  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00522d4c  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00522d4f  ebc6                   -jmp 0x522d17
    goto L_0x00522d17;
L_0x00522d51:
    // 00522d51  81fafe000000           +cmp edx, 0xfe
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522d57  75be                   -jne 0x522d17
    if (!cpu.flags.zf)
    {
        goto L_0x00522d17;
    }
L_0x00522d59:
    // 00522d59  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522d5c  740b                   -je 0x522d69
    if (cpu.flags.zf)
    {
        goto L_0x00522d69;
    }
    // 00522d5e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00522d60  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00522d63  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522d64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522d65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522d66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522d67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522d68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00522d69:
    // 00522d69  c6450002               -mov byte ptr [ebp], 2
    app->getMemory<x86::reg8>(cpu.ebp) = 2 /*0x2*/;
    // 00522d6d  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00522d6f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00522d70  ff153cf69e00           -call dword ptr [0x9ef63c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417724) /* 0x9ef63c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522d76  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00522d79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522d7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522d7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522d7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522d7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522d7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_522d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522d80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00522d81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522d82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00522d83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522d84  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00522d86  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00522d88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00522d8a  7c08                   -jl 0x522d94
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00522d94;
    }
    // 00522d8c  3b0594ad5600           +cmp eax, dword ptr [0x56ad94]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5680532) /* 0x56ad94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522d92  7614                   -jbe 0x522da8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00522da8;
    }
L_0x00522d94:
    // 00522d94  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00522d99  e8e2fafdff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00522d9e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00522da3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522da4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522da5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522da6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522da7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00522da8:
    // 00522da8  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522dae  a1bcac5600             -mov eax, dword ptr [0x56acbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 00522db3  8b0498                 -mov eax, dword ptr [eax + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00522db6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00522db7  2eff15d4445300         -call dword ptr cs:[0x5344d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457108) /* 0x5344d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522dbe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00522dc0  750a                   -jne 0x522dcc
    if (!cpu.flags.zf)
    {
        goto L_0x00522dcc;
    }
    // 00522dc2  e82de2fdff             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 00522dc7  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
L_0x00522dcc:
    // 00522dcc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00522dce  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522dd4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00522dd6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522dd7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522dd8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522dd9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522dda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_522de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522de0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00522de1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522de2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00522de3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00522de5  3b0594ad5600           +cmp eax, dword ptr [0x56ad94]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5680532) /* 0x56ad94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522deb  7206                   -jb 0x522df3
    if (cpu.flags.cf)
    {
        goto L_0x00522df3;
    }
    // 00522ded  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00522def  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522df0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522df1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522df2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00522df3:
    // 00522df3  83f803                 +cmp eax, 3
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
    // 00522df6  7d33                   -jge 0x522e2b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00522e2b;
    }
    // 00522df8  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00522dff  a1e8ad5600             -mov eax, dword ptr [0x56ade8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680616) /* 0x56ade8 */);
    // 00522e04  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00522e06  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00522e09  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 00522e0c  751d                   -jne 0x522e2b
    if (!cpu.flags.zf)
    {
        goto L_0x00522e2b;
    }
    // 00522e0e  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00522e10  80cd40                 -or ch, 0x40
    cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00522e13  886801                 -mov byte ptr [eax + 1], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.ch;
    // 00522e16  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00522e18  e843070000             -call 0x523560
    cpu.esp -= 4;
    sub_523560(app, cpu);
    if (cpu.terminate) return;
    // 00522e1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00522e1f  740a                   -je 0x522e2b
    if (cpu.flags.zf)
    {
        goto L_0x00522e2b;
    }
    // 00522e21  a1e8ad5600             -mov eax, dword ptr [0x56ade8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680616) /* 0x56ade8 */);
    // 00522e26  804c030120             -or byte ptr [ebx + eax + 1], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00522e2b:
    // 00522e2b  a1e8ad5600             -mov eax, dword ptr [0x56ade8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680616) /* 0x56ade8 */);
    // 00522e30  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00522e33  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522e34  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522e35  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522e36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_522e38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522e38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00522e39  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00522e3c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00522e3e  740e                   -je 0x522e4e
    if (cpu.flags.zf)
    {
        goto L_0x00522e4e;
    }
    // 00522e40  8b1de8ad5600           -mov ebx, dword ptr [0x56ade8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5680616) /* 0x56ade8 */);
    // 00522e46  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00522e49  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00522e4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522e4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00522e4e:
    // 00522e4e  8b1de8ad5600           -mov ebx, dword ptr [0x56ade8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5680616) /* 0x56ade8 */);
    // 00522e54  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00522e57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522e58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_522e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00522e61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00522e62  8b1d28785600           -mov ebx, dword ptr [0x567828]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5666856) /* 0x567828 */);
    // 00522e68  e8b750fdff             -call 0x4f7f24
    cpu.esp -= 4;
    sub_4f7f24(app, cpu);
    if (cpu.terminate) return;
    // 00522e6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00522e6f  83f8ff                 +cmp eax, -1
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
    // 00522e72  7409                   -je 0x522e7d
    if (cpu.flags.zf)
    {
        goto L_0x00522e7d;
    }
    // 00522e74  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00522e76  7505                   -jne 0x522e7d
    if (!cpu.flags.zf)
    {
        goto L_0x00522e7d;
    }
    // 00522e78  e813840000             -call 0x52b290
    cpu.esp -= 4;
    sub_52b290(app, cpu);
    if (cpu.terminate) return;
L_0x00522e7d:
    // 00522e7d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00522e7f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522e80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522e81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_522e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522e90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522e91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00522e92  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00522e95  c704240000803f         -mov dword ptr [esp], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp) = 1065353216 /*0x3f800000*/;
    // 00522e9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00522e9e  7e2f                   -jle 0x522ecf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00522ecf;
    }
    // 00522ea0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00522ea5  39d0                   +cmp eax, edx
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
    // 00522ea7  7c0f                   -jl 0x522eb8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00522eb8;
    }
    // 00522ea9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00522eab:
    // 00522eab  85c2                   +test edx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.eax));
    // 00522ead  7512                   -jne 0x522ec1
    if (!cpu.flags.zf)
    {
        goto L_0x00522ec1;
    }
L_0x00522eaf:
    // 00522eaf  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00522eb1  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00522eb4  39c2                   +cmp edx, eax
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
    // 00522eb6  7ef3                   -jle 0x522eab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00522eab;
    }
L_0x00522eb8:
    // 00522eb8  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00522ebb  83c404                 +add esp, 4
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
    // 00522ebe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522ebf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522ec0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00522ec1:
    // 00522ec1  d90424                 +fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00522ec4  d889ecad5600           +fmul dword ptr [ecx + 0x56adec]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(5680620) /* 0x56adec */));
    // 00522eca  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00522ecd  ebe0                   -jmp 0x522eaf
    goto L_0x00522eaf;
L_0x00522ecf:
    // 00522ecf  6bc0ff                 -imul eax, eax, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 00522ed2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00522ed7  39d0                   +cmp eax, edx
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
    // 00522ed9  7cdd                   -jl 0x522eb8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00522eb8;
    }
    // 00522edb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00522edd:
    // 00522edd  85c2                   +test edx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.eax));
    // 00522edf  750b                   -jne 0x522eec
    if (!cpu.flags.zf)
    {
        goto L_0x00522eec;
    }
    // 00522ee1  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00522ee3  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00522ee6  39c2                   +cmp edx, eax
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
    // 00522ee8  7fce                   -jg 0x522eb8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00522eb8;
    }
    // 00522eea  ebf1                   -jmp 0x522edd
    goto L_0x00522edd;
L_0x00522eec:
    // 00522eec  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00522eef  d8b1ecad5600           -fdiv dword ptr [ecx + 0x56adec]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(5680620) /* 0x56adec */));
    // 00522ef5  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00522ef8  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00522efa  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00522efd  39c2                   +cmp edx, eax
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
    // 00522eff  7fb7                   -jg 0x522eb8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00522eb8;
    }
    // 00522f01  ebda                   -jmp 0x522edd
    goto L_0x00522edd;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_522f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522f10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522f11  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00522f14  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00522f16  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00522f18  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00522f1c  e86fffffff             -call 0x522e90
    cpu.esp -= 4;
    sub_522e90(app, cpu);
    if (cpu.terminate) return;
    // 00522f21  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00522f25  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00522f27  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00522f2b  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00522f2f  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00522f31  d80df41a5500           -fmul dword ptr [0x551af4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5577460) /* 0x551af4 */));
    // 00522f37  e81acefbff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00522f3c  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00522f3f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00522f42  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00522f45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522f46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_522f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522f50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522f51  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00522f53  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00522f56  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00522f58  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00522f5b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00522f5d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00522f5f  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00522f62  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00522f64  05b4bc9f00             -add eax, 0x9fbcb4
    (cpu.eax) += x86::reg32(x86::sreg32(10468532 /*0x9fbcb4*/));
    // 00522f69  81f900000800           +cmp ecx, 0x80000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522f6f  7605                   -jbe 0x522f76
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00522f76;
    }
    // 00522f71  b900000800             -mov ecx, 0x80000
    cpu.ecx = 524288 /*0x80000*/;
L_0x00522f76:
    // 00522f76  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522f77  8d90640d0000           -lea edx, [eax + 0xd64]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3428) /* 0xd64 */);
    // 00522f7d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00522f7e  ff90b00d0000           -call dword ptr [eax + 0xdb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3504) /* 0xdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522f84  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00522f87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522f88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_522f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522f90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522f91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522f92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00522f93  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00522f96  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00522f98  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00522f9a  ff15246b9f00           -call dword ptr [0x9f6b24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447652) /* 0x9f6b24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522fa0  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 00522fa7  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00522fa9  39cb                   +cmp ebx, ecx
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
    // 00522fab  731f                   -jae 0x522fcc
    if (!cpu.flags.cf)
    {
        goto L_0x00522fcc;
    }
L_0x00522fad:
    // 00522fad  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00522faf  0fbf06                 -movsx eax, word ptr [esi]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi)));
    // 00522fb2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00522fb5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00522fb7  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00522fba  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00522fbd  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00522fc0  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00522fc3  d95bfc                 -fstp dword ptr [ebx - 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00522fc6  39cb                   +cmp ebx, ecx
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
    // 00522fc8  72e3                   -jb 0x522fad
    if (cpu.flags.cf)
    {
        goto L_0x00522fad;
    }
    // 00522fca  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00522fcc:
    // 00522fcc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00522fcf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522fd0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522fd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00522fd2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_522fd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00522fd4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00522fd5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00522fd6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00522fd7  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00522fda  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00522fdc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00522fde  ff15246b9f00           -call dword ptr [0x9f6b24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447652) /* 0x9f6b24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00522fe4  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 00522feb  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00522fed  39ce                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00522fef  0f8390000000           -jae 0x523085
    if (!cpu.flags.cf)
    {
        goto L_0x00523085;
    }
L_0x00522ff5:
    // 00522ff5  df03                   -fild word ptr [ebx]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebx))));
    // 00522ff7  d806                   -fadd dword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi));
    // 00522ff9  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00522ffd  df4302                 -fild word ptr [ebx + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */))));
    // 00523000  d806                   -fadd dword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi));
    // 00523002  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00523006  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052300a  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0052300c  dd05f81a5500           -fld qword ptr [0x551af8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5577464) /* 0x551af8 */)));
    // 00523012  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00523014  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00523016  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523019  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052301b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052301d  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00523021  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00523025  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 00523027  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052302b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052302d  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052302f  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00523033  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00523037  25ffff0f00             -and eax, 0xfffff
    cpu.eax &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 0052303c  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00523042  3dff7f0000             +cmp eax, 0x7fff
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
    // 00523047  764a                   -jbe 0x523093
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523093;
    }
    // 00523049  3d00800f00             +cmp eax, 0xf8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052304e  7343                   -jae 0x523093
    if (!cpu.flags.cf)
    {
        goto L_0x00523093;
    }
    // 00523050  3d00000800             +cmp eax, 0x80000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523055  7335                   -jae 0x52308c
    if (!cpu.flags.cf)
    {
        goto L_0x0052308c;
    }
    // 00523057  66c703ff7f             -mov word ptr [ebx], 0x7fff
    app->getMemory<x86::reg16>(cpu.ebx) = 32767 /*0x7fff*/;
L_0x0052305c:
    // 0052305c  81faff7f0000           +cmp edx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523062  763c                   -jbe 0x5230a0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005230a0;
    }
    // 00523064  81fa00800f00           +cmp edx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052306a  7334                   -jae 0x5230a0
    if (!cpu.flags.cf)
    {
        goto L_0x005230a0;
    }
    // 0052306c  81fa00000800           +cmp edx, 0x80000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523072  7324                   -jae 0x523098
    if (!cpu.flags.cf)
    {
        goto L_0x00523098;
    }
    // 00523074  66c74302ff7f           -mov word ptr [ebx + 2], 0x7fff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32767 /*0x7fff*/;
L_0x0052307a:
    // 0052307a  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052307d  39ce                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052307f  0f8270ffffff           -jb 0x522ff5
    if (cpu.flags.cf)
    {
        goto L_0x00522ff5;
    }
L_0x00523085:
    // 00523085  83c410                 +add esp, 0x10
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
    // 00523088  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523089  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052308a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052308b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052308c:
    // 0052308c  66c7030080             -mov word ptr [ebx], 0x8000
    app->getMemory<x86::reg16>(cpu.ebx) = 32768 /*0x8000*/;
    // 00523091  ebc9                   -jmp 0x52305c
    goto L_0x0052305c;
L_0x00523093:
    // 00523093  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 00523096  ebc4                   -jmp 0x52305c
    goto L_0x0052305c;
L_0x00523098:
    // 00523098  66c743020080           -mov word ptr [ebx + 2], 0x8000
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32768 /*0x8000*/;
    // 0052309e  ebda                   -jmp 0x52307a
    goto L_0x0052307a;
L_0x005230a0:
    // 005230a0  66895302               -mov word ptr [ebx + 2], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 005230a4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005230a7  39ce                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005230a9  0f8246ffffff           -jb 0x522ff5
    if (cpu.flags.cf)
    {
        goto L_0x00522ff5;
    }
    // 005230af  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005230b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005230b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005230b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005230b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5230b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005230b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005230b9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005230ba  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 005230bf  baf4010000             -mov edx, 0x1f4
    cpu.edx = 500 /*0x1f4*/;
    // 005230c4  68a0caa000             -push 0xa0caa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10537632 /*0xa0caa0*/;
    cpu.esp -= 4;
    // 005230c9  8915a0d2a000           -mov dword ptr [0xa0d2a0], edx
    app->getMemory<x86::reg32>(x86::reg32(10539680) /* 0xa0d2a0 */) = cpu.edx;
    // 005230cf  ff155c6a9f00           -call dword ptr [0x9f6a5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447452) /* 0x9f6a5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005230d5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005230d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005230d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005230da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5230dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005230dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005230dd  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 005230df  80780800               +cmp byte ptr [eax + 8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005230e3  7502                   -jne 0x5230e7
    if (!cpu.flags.zf)
    {
        goto L_0x005230e7;
    }
    // 005230e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005230e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005230e7:
    // 005230e7  8b0d576a9f00           -mov ecx, dword ptr [0x9f6a57]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10447447) /* 0x9f6a57 */);
    // 005230ed  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 005230f0  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 005230f2  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 005230f5  81c6a0caa000           -add esi, 0xa0caa0
    (cpu.esi) += x86::reg32(x86::sreg32(10537632 /*0xa0caa0*/));
    // 005230fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005230fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005230fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005230fe  8d90c40d0000           -lea edx, [eax + 0xdc4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3524) /* 0xdc4 */);
    // 00523104  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523105  ff90e00d0000           -call dword ptr [eax + 0xde0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3552) /* 0xde0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052310b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052310d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00523110  8915a0d2a000           -mov dword ptr [0xa0d2a0], edx
    app->getMemory<x86::reg32>(x86::reg32(10539680) /* 0xa0d2a0 */) = cpu.edx;
    // 00523116  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523117  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_523118(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523118  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523119  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052311a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052311b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052311c  83ec48                 -sub esp, 0x48
    (cpu.esp) -= x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0052311f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00523121  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00523123  8b15a0d2a000           -mov edx, dword ptr [0xa0d2a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10539680) /* 0xa0d2a0 */);
    // 00523129  42                     -inc edx
    (cpu.edx)++;
    // 0052312a  8915a0d2a000           -mov dword ptr [0xa0d2a0], edx
    app->getMemory<x86::reg32>(x86::reg32(10539680) /* 0xa0d2a0 */) = cpu.edx;
    // 00523130  81faf4010000           +cmp edx, 0x1f4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523136  7d4a                   -jge 0x523182
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00523182;
    }
    // 00523138  8d2c00                 -lea ebp, [eax + eax]
    cpu.ebp = x86::reg32(cpu.eax + cpu.eax * 1);
    // 0052313b  803d5b6a9f0000         +cmp byte ptr [0x9f6a5b], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10447451) /* 0x9f6a5b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523142  7446                   -je 0x52318a
    if (cpu.flags.zf)
    {
        goto L_0x0052318a;
    }
    // 00523144  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523145  bba0c6a000             -mov ebx, 0xa0c6a0
    cpu.ebx = 10536608 /*0xa0c6a0*/;
    // 0052314a  baa0caa000             -mov edx, 0xa0caa0
    cpu.edx = 10537632 /*0xa0caa0*/;
    // 0052314f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00523151  e83afeffff             -call 0x522f90
    cpu.esp -= 4;
    sub_522f90(app, cpu);
    if (cpu.terminate) return;
    // 00523156  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523157  68a0caa000             -push 0xa0caa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10537632 /*0xa0caa0*/;
    cpu.esp -= 4;
    // 0052315c  ff155c6a9f00           -call dword ptr [0x9f6a5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447452) /* 0x9f6a5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00523162  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00523165  68a0c6a000             -push 0xa0c6a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10536608 /*0xa0c6a0*/;
    cpu.esp -= 4;
    // 0052316a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052316b  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052316d  e88e810000             -call 0x52b300
    cpu.esp -= 4;
    sub_52b300(app, cpu);
    if (cpu.terminate) return;
    // 00523172  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00523175  baa0c6a000             -mov edx, 0xa0c6a0
    cpu.edx = 10536608 /*0xa0c6a0*/;
    // 0052317a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052317c  e853feffff             -call 0x522fd4
    cpu.esp -= 4;
    sub_522fd4(app, cpu);
    if (cpu.terminate) return;
    // 00523181  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00523182:
    // 00523182  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00523185  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523186  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523187  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523188  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523189  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052318a:
    // 0052318a  68a0c6a000             -push 0xa0c6a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10536608 /*0xa0c6a0*/;
    cpu.esp -= 4;
    // 0052318f  68a0caa000             -push 0xa0caa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10537632 /*0xa0caa0*/;
    cpu.esp -= 4;
    // 00523194  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523195  e836830000             -call 0x52b4d0
    cpu.esp -= 4;
    sub_52b4d0(app, cpu);
    if (cpu.terminate) return;
    // 0052319a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052319d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052319e  68a0caa000             -push 0xa0caa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10537632 /*0xa0caa0*/;
    cpu.esp -= 4;
    // 005231a3  ff155c6a9f00           -call dword ptr [0x9f6a5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447452) /* 0x9f6a5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005231a9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005231ac  68a0c6a000             -push 0xa0c6a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10536608 /*0xa0c6a0*/;
    cpu.esp -= 4;
    // 005231b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005231b2  e849810000             -call 0x52b300
    cpu.esp -= 4;
    sub_52b300(app, cpu);
    if (cpu.terminate) return;
    // 005231b7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005231ba  8d6c2440               -lea ebp, [esp + 0x40]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 005231be  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005231bf  8d6c2448               -lea ebp, [esp + 0x48]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 005231c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005231c4  8d6c2408               -lea ebp, [esp + 8]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005231c8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005231c9  e872d8ffff             -call 0x520a40
    cpu.esp -= 4;
    sub_520a40(app, cpu);
    if (cpu.terminate) return;
    // 005231ce  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005231d1  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 005231d3  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 005231d5  8d6c2408               -lea ebp, [esp + 8]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005231d9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005231da  ff54244c               -call dword ptr [esp + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005231de  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005231e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005231e2  68a0c6a000             -push 0xa0c6a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10536608 /*0xa0c6a0*/;
    cpu.esp -= 4;
    // 005231e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005231e8  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005231ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005231ed  ff542454               -call dword ptr [esp + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005231f1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005231f4  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 005231f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005231f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005231f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005231fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005231fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_523200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523200  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523201  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523202  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523203  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523204  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523205  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00523208  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052320c  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00523210  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00523214  e83dcbfbff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00523219  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
L_0x0052321c:
    // 0052321c  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00523221  3b0c24                 +cmp ecx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523224  7f11                   -jg 0x523237
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00523237;
    }
    // 00523226  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
L_0x00523229:
    // 00523229  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052322c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052322e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00523231  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00523233  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00523235  750f                   -jne 0x523246
    if (!cpu.flags.zf)
    {
        goto L_0x00523246;
    }
L_0x00523237:
    // 00523237  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0052323a  39f9                   +cmp ecx, edi
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
    // 0052323c  740f                   -je 0x52324d
    if (cpu.flags.zf)
    {
        goto L_0x0052324d;
    }
    // 0052323e  8d6f01                 -lea ebp, [edi + 1]
    cpu.ebp = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00523241  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00523244  ebd6                   -jmp 0x52321c
    goto L_0x0052321c;
L_0x00523246:
    // 00523246  41                     -inc ecx
    (cpu.ecx)++;
    // 00523247  39f1                   +cmp ecx, esi
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
    // 00523249  7ede                   -jle 0x523229
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00523229;
    }
    // 0052324b  ebea                   -jmp 0x523237
    goto L_0x00523237;
L_0x0052324d:
    // 0052324d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052324f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00523252  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523253  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523254  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523255  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523256  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523257  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52325c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052325c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052325d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052325e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052325f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523260  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00523263  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00523265  c7442408cdcccc3d       -mov dword ptr [esp + 8], 0x3dcccccd
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1036831949 /*0x3dcccccd*/;
    // 0052326d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052326f:
    // 0052326f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523272  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00523274  898ab0d2a000           -mov dword ptr [edx + 0xa0d2b0], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10539696) /* 0xa0d2b0 */) = cpu.ecx;
    // 0052327a  81fa00af0000           +cmp edx, 0xaf00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44800 /*0xaf00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523280  75ed                   -jne 0x52326f
    if (!cpu.flags.zf)
    {
        goto L_0x0052326f;
    }
    // 00523282  b9b4d2a000             -mov ecx, 0xa0d2b4
    cpu.ecx = 10539700 /*0xa0d2b4*/;
    // 00523287  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00523289:
    // 00523289  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052328c  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00523290  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00523292  898ad081a100           -mov dword ptr [edx + 0xa181d0], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10584528) /* 0xa181d0 */) = cpu.ecx;
    // 00523298  e863ffffff             -call 0x523200
    cpu.esp -= 4;
    sub_523200(app, cpu);
    if (cpu.terminate) return;
    // 0052329d  d9822cae5600           -fld dword ptr [edx + 0x56ae2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(5680684) /* 0x56ae2c */)));
    // 005232a3  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 005232a5  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 005232a7  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 005232ae  d99a3cae5600           -fstp dword ptr [edx + 0x56ae3c]
    app->getMemory<float>(cpu.edx + x86::reg32(5680700) /* 0x56ae3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005232b4  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 005232b8  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 005232ba  dc0d001b5500           -fmul qword ptr [0x551b00]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5577472) /* 0x551b00 */));
    // 005232c0  8b82d081a100           -mov eax, dword ptr [edx + 0xa181d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10584528) /* 0xa181d0 */);
    // 005232c6  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 005232c8  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005232cb  8982b081a100           -mov dword ptr [edx + 0xa181b0], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10584496) /* 0xa181b0 */) = cpu.eax;
    // 005232d1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005232d3  8982c081a100           -mov dword ptr [edx + 0xa181c0], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10584512) /* 0xa181c0 */) = cpu.eax;
    // 005232d9  899af081a100           -mov dword ptr [edx + 0xa181f0], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10584560) /* 0xa181f0 */) = cpu.ebx;
    // 005232df  899aa0d2a000           -mov dword ptr [edx + 0xa0d2a0], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10539680) /* 0xa0d2a0 */) = cpu.ebx;
    // 005232e5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005232e7  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005232e9  899ae081a100           -mov dword ptr [edx + 0xa181e0], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10584544) /* 0xa181e0 */) = cpu.ebx;
    // 005232ef  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005232f3  83fa10                 +cmp edx, 0x10
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005232f6  7591                   -jne 0x523289
    if (!cpu.flags.zf)
    {
        goto L_0x00523289;
    }
    // 005232f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005232fa  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005232fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005232fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005232ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523300  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523301  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523310  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523311  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00523313  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00523315  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00523318  81c158f69e00           -add ecx, 0x9ef658
    (cpu.ecx) += x86::reg32(x86::sreg32(10417752 /*0x9ef658*/));
    // 0052331e  80790503               +cmp byte ptr [ecx + 5], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523322  7504                   -jne 0x523328
    if (!cpu.flags.zf)
    {
        goto L_0x00523328;
    }
    // 00523324  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523326  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523327  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523328:
    // 00523328  e8d3810000             -call 0x52b500
    cpu.esp -= 4;
    sub_52b500(app, cpu);
    if (cpu.terminate) return;
    // 0052332d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052332f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523330  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_523332(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523332  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523333  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00523335  d9e4                   -ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 00523337  83ec18                 +sub esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052333a  9b                     -wait 
    /*nothing*/;
    // 0052333b  dd7df8                 -fnstsw word ptr [ebp - 8]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.fpu.status.word;
    // 0052333e  dd55e8                 +fst qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    // 00523341  8a65f9                 -mov ah, byte ptr [ebp - 7]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 00523344  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00523345  751a                   -jne 0x523361
    if (!cpu.flags.zf)
    {
        goto L_0x00523361;
    }
    // 00523347  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
L_0x00523349:
    // 00523349  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052334b  dd5df0                 -fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052334e  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00523351  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00523354  e8ca810000             -call 0x52b523
    cpu.esp -= 4;
    sub_52b523(app, cpu);
    if (cpu.terminate) return;
    // 00523359  83ec08                 +sub esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052335c  e9f9000000             -jmp 0x52345a
    goto L_0x0052345a;
L_0x00523361:
    // 00523361  d9c1                   +fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 00523363  d9fc                   +frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00523365  d8da                   +fcomp st(2)
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(cpu.fpu.st(2)));
    cpu.fpu.pop();
    // 00523367  9b                     -wait 
    /*nothing*/;
    // 00523368  dd7dfa                 -fnstsw word ptr [ebp - 6]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = cpu.fpu.status.word;
    // 0052336b  9b                     -wait 
    /*nothing*/;
    // 0052336c  8a65fb                 -mov ah, byte ptr [ebp - 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 0052336f  733b                   -jae 0x5233ac
    if (!cpu.flags.cf)
    {
        goto L_0x005233ac;
    }
    // 00523371  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00523373  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00523374  75d3                   -jne 0x523349
    if (!cpu.flags.zf)
    {
        goto L_0x00523349;
    }
    // 00523376  66b80200               -mov ax, 2
    cpu.ax = 2 /*0x2*/;
    // 0052337a  668945fc               -mov word ptr [ebp - 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ax;
    // 0052337e  df45fc                 +fild word ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00523381  d9c2                   +fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 00523383  d9f8                   +fprem 
    cpu.fpu.st(0) = cpu.fpu.rem(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00523385  9b                     -wait 
    /*nothing*/;
    // 00523386  dd7dfc                 -fnstsw word ptr [ebp - 4]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.fpu.status.word;
    // 00523389  9b                     -wait 
    /*nothing*/;
    // 0052338a  8a65fd                 -mov ah, byte ptr [ebp - 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */);
    // 0052338d  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052338e  b400                   -mov ah, 0
    cpu.ah = 0 /*0x0*/;
    // 00523390  7a11                   -jp 0x5233a3
    if (cpu.flags.pf)
    {
        goto L_0x005233a3;
    }
    // 00523392  d9e4                   +ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 00523394  9b                     -wait 
    /*nothing*/;
    // 00523395  dd7dfc                 -fnstsw word ptr [ebp - 4]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.fpu.status.word;
    // 00523398  9b                     -wait 
    /*nothing*/;
    // 00523399  8a65fd                 -mov ah, byte ptr [ebp - 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */);
    // 0052339c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052339d  b400                   -mov ah, 0
    cpu.ah = 0 /*0x0*/;
    // 0052339f  7402                   -je 0x5233a3
    if (cpu.flags.zf)
    {
        goto L_0x005233a3;
    }
    // 005233a1  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
L_0x005233a3:
    // 005233a3  8865f9                 -mov byte ptr [ebp - 7], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */) = cpu.ah;
    // 005233a6  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005233a8  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005233aa  eb08                   -jmp 0x5233b4
    goto L_0x005233b4;
L_0x005233ac:
    // 005233ac  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005233ad  7405                   -je 0x5233b4
    if (cpu.flags.zf)
    {
        goto L_0x005233b4;
    }
    // 005233af  e987000000             -jmp 0x52343b
    goto L_0x0052343b;
L_0x005233b4:
    // 005233b4  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 005233b6  dd5df0                 -fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005233b9  9b                     -wait 
    /*nothing*/;
    // 005233ba  668b45f6               -mov ax, word ptr [ebp - 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 005233be  6625f07f               -and ax, 0x7ff0
    cpu.ax &= x86::reg16(x86::sreg16(32752 /*0x7ff0*/));
    // 005233c2  662df03f               -sub ax, 0x3ff0
    (cpu.ax) -= x86::reg16(x86::sreg16(16368 /*0x3ff0*/));
    // 005233c6  663d0001               +cmp ax, 0x100
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(256 /*0x100*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005233ca  736f                   -jae 0x52343b
    if (!cpu.flags.cf)
    {
        goto L_0x0052343b;
    }
    // 005233cc  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 005233ce  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005233d1  9b                     -wait 
    /*nothing*/;
    // 005233d2  668b45fe               -mov ax, word ptr [ebp - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 005233d6  6609c0                 +or ax, ax
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(cpu.ax))));
    // 005233d9  750b                   -jne 0x5233e6
    if (!cpu.flags.zf)
    {
        goto L_0x005233e6;
    }
    // 005233db  668b45fc               -mov ax, word ptr [ebp - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 005233df  e881000000             -call 0x523465
    cpu.esp -= 4;
    sub_523465(app, cpu);
    if (cpu.terminate) return;
    // 005233e4  eb2b                   -jmp 0x523411
    goto L_0x00523411;
L_0x005233e6:
    // 005233e6  6640                   +inc ax
    {
        x86::reg16& tmp = cpu.ax;
        cpu.flags.of = ~(1 & (tmp >> 15));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 15);
        cpu.set_szp(tmp);
    }
    // 005233e8  7551                   -jne 0x52343b
    if (!cpu.flags.zf)
    {
        goto L_0x0052343b;
    }
    // 005233ea  660b45fc               +or ax, word ptr [ebp - 4]
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */)))));
    // 005233ee  744b                   -je 0x52343b
    if (cpu.flags.zf)
    {
        goto L_0x0052343b;
    }
    // 005233f0  66f7d8                 -neg ax
    cpu.ax = ~cpu.ax + 1;
    // 005233f3  e86d000000             -call 0x523465
    cpu.esp -= 4;
    sub_523465(app, cpu);
    if (cpu.terminate) return;
    // 005233f8  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 005233fa  f6055878560001         +test byte ptr [0x567858], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5666904) /* 0x567858 */) & 1 /*0x1*/));
    // 00523401  7504                   -jne 0x523407
    if (!cpu.flags.zf)
    {
        goto L_0x00523407;
    }
    // 00523403  def1                   +fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00523405  eb0a                   -jmp 0x523411
    goto L_0x00523411;
L_0x00523407:
    // 00523407  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 0052340c  e8da360000             -call 0x526aeb
    cpu.esp -= 4;
    sub_526aeb(app, cpu);
    if (cpu.terminate) return;
L_0x00523411:
    // 00523411  dd55f8                 -fst qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    // 00523414  9b                     -wait 
    /*nothing*/;
    // 00523415  668b45f8               -mov ax, word ptr [ebp - 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00523419  660b45fa               -or ax, word ptr [ebp - 6]
    cpu.ax |= x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */)));
    // 0052341d  660b45fc               +or ax, word ptr [ebp - 4]
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */)))));
    // 00523421  7514                   -jne 0x523437
    if (!cpu.flags.zf)
    {
        goto L_0x00523437;
    }
    // 00523423  668b45fe               -mov ax, word ptr [ebp - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00523427  66d1e0                 -shl ax, 1
    cpu.ax <<= 1 /*0x1*/ % 32;
    // 0052342a  663de0ff               +cmp ax, 0xffe0
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65504 /*0xffe0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052342e  7507                   -jne 0x523437
    if (!cpu.flags.zf)
    {
        goto L_0x00523437;
    }
L_0x00523430:
    // 00523430  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 00523432  e912ffffff             -jmp 0x523349
    goto L_0x00523349;
L_0x00523437:
    // 00523437  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00523439  eb1f                   -jmp 0x52345a
    goto L_0x0052345a;
L_0x0052343b:
    // 0052343b  d9ed                   -fldln2 
    cpu.fpu.push(0.6931471805599453);
    // 0052343d  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 0052343f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00523441  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 00523443  d9f1                   -fyl2x 
    cpu.fpu.st(1) = cpu.fpu.log2(cpu.fpu.st(0)) * cpu.fpu.st(1);
    cpu.fpu.pop();
    // 00523445  b007                   -mov al, 7
    cpu.al = 7 /*0x7*/;
    // 00523447  e86a4cfdff             -call 0x4f80b6
    cpu.esp -= 4;
    sub_4f80b6(app, cpu);
    if (cpu.terminate) return;
    // 0052344c  3c00                   +cmp al, 0
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
    // 0052344e  75e0                   -jne 0x523430
    if (!cpu.flags.zf)
    {
        goto L_0x00523430;
    }
    // 00523450  8a65f9                 -mov ah, byte ptr [ebp - 7]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 00523453  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00523454  7302                   -jae 0x523458
    if (!cpu.flags.cf)
    {
        goto L_0x00523458;
    }
    // 00523456  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00523458:
    // 00523458  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0052345a:
    // 0052345a  dd5df8                 -fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052345d  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00523460  9b                     -wait 
    /*nothing*/;
    // 00523461  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00523463  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523464  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_523465(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00523465:
    // 00523465  66d1e8                 +shr ax, 1
    {
        x86::reg16 tmp = 1 /*0x1*/ % 32;
        x86::reg16& op = cpu.ax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (16 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00523468  7604                   -jbe 0x52346e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052346e;
    }
    // 0052346a  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0052346c  ebf7                   -jmp 0x523465
    goto L_0x00523465;
L_0x0052346e:
    // 0052346e  7313                   -jae 0x523483
    if (!cpu.flags.cf)
    {
        goto L_0x00523483;
    }
    // 00523470  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
L_0x00523472:
    // 00523472  740b                   -je 0x52347f
    if (cpu.flags.zf)
    {
        goto L_0x0052347f;
    }
    // 00523474  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 00523476  66d1e8                 +shr ax, 1
    {
        x86::reg16 tmp = 1 /*0x1*/ % 32;
        x86::reg16& op = cpu.ax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (16 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00523479  7302                   -jae 0x52347d
    if (!cpu.flags.cf)
    {
        goto L_0x0052347d;
    }
    // 0052347b  dcc9                   +fmul st(1), st(0)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
L_0x0052347d:
    // 0052347d  ebf3                   -jmp 0x523472
    goto L_0x00523472;
L_0x0052347f:
    // 0052347f  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00523481  eb04                   -jmp 0x523487
    goto L_0x00523487;
L_0x00523483:
    // 00523483  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00523485  d9e8                   -fld1 
    cpu.fpu.push(1.0);
L_0x00523487:
    // 00523487  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_523488(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523488  dd44240c               -fld qword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052348c  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00523490  e89dfeffff             -call 0x523332
    cpu.esp -= 4;
    sub_523332(app, cpu);
    if (cpu.terminate) return;
    // 00523495  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5234a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005234a0  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 005234a2  740e                   -je 0x5234b2
    if (cpu.flags.zf)
    {
        goto L_0x005234b2;
    }
    // 005234a4  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 005234aa  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 005234b0  eb0c                   -jmp 0x5234be
    goto L_0x005234be;
L_0x005234b2:
    // 005234b2  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 005234b8  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
L_0x005234be:
    // 005234be  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 005234c0  7403                   -je 0x5234c5
    if (cpu.flags.zf)
    {
        goto L_0x005234c5;
    }
    // 005234c2  800b02                 -or byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x005234c5:
    // 005234c5  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 005234c7  7403                   -je 0x5234cc
    if (cpu.flags.zf)
    {
        goto L_0x005234cc;
    }
    // 005234c9  800b04                 -or byte ptr [ebx], 4
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x005234cc:
    // 005234cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5234d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005234d0  83f802                 +cmp eax, 2
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
    // 005234d3  750d                   -jne 0x5234e2
    if (!cpu.flags.zf)
    {
        goto L_0x005234e2;
    }
    // 005234d5  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 005234db  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 005234e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005234e2:
    // 005234e2  83f801                 +cmp eax, 1
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
    // 005234e5  750d                   -jne 0x5234f4
    if (!cpu.flags.zf)
    {
        goto L_0x005234f4;
    }
    // 005234e7  c70200000040           -mov dword ptr [edx], 0x40000000
    app->getMemory<x86::reg32>(cpu.edx) = 1073741824 /*0x40000000*/;
    // 005234ed  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 005234f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005234f4:
    // 005234f4  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 005234fa  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 00523500  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_523504(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523504  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523505  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00523507  83e070                 -and eax, 0x70
    cpu.eax &= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0052350a  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0052350d  83f820                 +cmp eax, 0x20
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
    // 00523510  7210                   -jb 0x523522
    if (cpu.flags.cf)
    {
        goto L_0x00523522;
    }
    // 00523512  7638                   -jbe 0x52354c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052354c;
    }
    // 00523514  83f830                 +cmp eax, 0x30
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523517  7241                   -jb 0x52355a
    if (cpu.flags.cf)
    {
        goto L_0x0052355a;
    }
    // 00523519  7629                   -jbe 0x523544
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523544;
    }
    // 0052351b  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052351e  7434                   -je 0x523554
    if (cpu.flags.zf)
    {
        goto L_0x00523554;
    }
    // 00523520  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523521  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523522:
    // 00523522  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523524  7607                   -jbe 0x52352d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052352d;
    }
    // 00523526  83f810                 +cmp eax, 0x10
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
    // 00523529  7411                   -je 0x52353c
    if (cpu.flags.zf)
    {
        goto L_0x0052353c;
    }
    // 0052352b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052352c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052352d:
    // 0052352d  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 00523533  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00523535  7523                   -jne 0x52355a
    if (!cpu.flags.zf)
    {
        goto L_0x0052355a;
    }
    // 00523537  800a02                 -or byte ptr [edx], 2
    app->getMemory<x86::reg8>(cpu.edx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0052353a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052353b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052353c:
    // 0052353c  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00523542  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523543  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523544:
    // 00523544  c70202000000           -mov dword ptr [edx], 2
    app->getMemory<x86::reg32>(cpu.edx) = 2 /*0x2*/;
    // 0052354a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052354b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052354c:
    // 0052354c  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 00523552  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523553  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523554:
    // 00523554  c70203000000           -mov dword ptr [edx], 3
    app->getMemory<x86::reg32>(cpu.edx) = 3 /*0x3*/;
L_0x0052355a:
    // 0052355a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052355b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_523560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523562  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523563  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00523565  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052356b  833db077560000         +cmp dword ptr [0x5677b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523572  741d                   -je 0x523591
    if (cpu.flags.zf)
    {
        goto L_0x00523591;
    }
    // 00523574  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00523576  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052357c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052357e  7411                   -je 0x523591
    if (cpu.flags.zf)
    {
        goto L_0x00523591;
    }
    // 00523580  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00523582  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00523588  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052358d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052358e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052358f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523590  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523591:
    // 00523591  a1bcac5600             -mov eax, dword ptr [0x56acbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 00523596  8b0498                 -mov eax, dword ptr [eax + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00523599  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052359a  2eff152c455300         -call dword ptr cs:[0x53452c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457196) /* 0x53452c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235a1  83f802                 +cmp eax, 2
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
    // 005235a4  7511                   -jne 0x5235b7
    if (!cpu.flags.zf)
    {
        goto L_0x005235b7;
    }
    // 005235a6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005235a8  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235ae  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005235b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005235b7:
    // 005235b7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005235b9  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005235c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5235d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005235d0  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235d6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005235d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5235dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005235dc  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235e2  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005235e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5235f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005235f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005235f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005235f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005235f3  2eff1594455300         -call dword ptr cs:[0x534594]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457300) /* 0x534594 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005235fc  7507                   -jne 0x523605
    if (!cpu.flags.zf)
    {
        goto L_0x00523605;
    }
    // 005235fe  e8f1d9fdff             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 00523603  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523604  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523605:
    // 00523605  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523607  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523608  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523610  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523611  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523612  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523613  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523616  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00523618  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052361a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052361c  7525                   -jne 0x523643
    if (!cpu.flags.zf)
    {
        goto L_0x00523643;
    }
    // 0052361e  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 00523623  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00523625  e8d642fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052362a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052362c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052362e  7511                   -jne 0x523641
    if (!cpu.flags.zf)
    {
        goto L_0x00523641;
    }
    // 00523630  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00523635  e846f2fdff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 0052363a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052363c  e974000000             -jmp 0x5236b5
    goto L_0x005236b5;
L_0x00523641:
    // 00523641  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00523643:
    // 00523643  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00523645  7405                   -je 0x52364c
    if (cpu.flags.zf)
    {
        goto L_0x0052364c;
    }
    // 00523647  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052364a  7510                   -jne 0x52365c
    if (!cpu.flags.zf)
    {
        goto L_0x0052365c;
    }
L_0x0052364c:
    // 0052364c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052364e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00523650  e8dbd0fcff             -call 0x4f0730
    cpu.esp -= 4;
    sub_4f0730(app, cpu);
    if (cpu.terminate) return;
    // 00523655  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523658  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523659  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052365a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052365b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052365c:
    // 0052365c  ba081b5500             -mov edx, 0x551b08
    cpu.edx = 5577480 /*0x551b08*/;
    // 00523661  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523663  e85868fcff             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 00523668  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052366a  7528                   -jne 0x523694
    if (!cpu.flags.zf)
    {
        goto L_0x00523694;
    }
    // 0052366c  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052366f  731a                   -jae 0x52368b
    if (!cpu.flags.cf)
    {
        goto L_0x0052368b;
    }
    // 00523671  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00523673  e87843fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00523678  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0052367d  e8fef1fdff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00523682  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523684  83c404                 +add esp, 4
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
    // 00523687  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523688  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523689  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052368a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052368b:
    // 0052368b  a1081b5500             -mov eax, dword ptr [0x551b08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5577480) /* 0x551b08 */);
    // 00523690  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00523692  eb1f                   -jmp 0x5236b3
    goto L_0x005236b3;
L_0x00523694:
    // 00523694  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00523696  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523697  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523698  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523699  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052369a  2eff1530455300         -call dword ptr cs:[0x534530]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457200) /* 0x534530 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005236a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005236a3  750e                   -jne 0x5236b3
    if (!cpu.flags.zf)
    {
        goto L_0x005236b3;
    }
    // 005236a5  e84ad9fdff             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 005236aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005236ac  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005236af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005236b3:
    // 005236b3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x005236b5:
    // 005236b5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005236b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_5236c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005236c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005236c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005236c3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005236c5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005236ca  83f87b                 +cmp eax, 0x7b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005236cd  743f                   -je 0x52370e
    if (cpu.flags.zf)
    {
        goto L_0x0052370e;
    }
    // 005236cf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005236d0  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 005236d2  7542                   -jne 0x523716
    if (!cpu.flags.zf)
    {
        goto L_0x00523716;
    }
L_0x005236d4:
    // 005236d4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005236d6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005236d8  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 005236db  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 005236e1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005236e3  83f80f                 +cmp eax, 0xf
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
    // 005236e6  7505                   -jne 0x5236ed
    if (!cpu.flags.zf)
    {
        goto L_0x005236ed;
    }
    // 005236e8  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x005236ed:
    // 005236ed  8b4202                 -mov eax, dword ptr [edx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 005236f0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 005236f3  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 005236f6  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005236f8  81e2f0000000           -and edx, 0xf0
    cpu.edx &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 005236fe  83fa40                 +cmp edx, 0x40
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523701  7548                   -jne 0x52374b
    if (!cpu.flags.zf)
    {
        goto L_0x0052374b;
    }
    // 00523703  83c00f                 -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00523706  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00523708  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0052370b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052370c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052370d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052370e:
    // 0052370e  8b4202                 -mov eax, dword ptr [edx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00523711  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00523714  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523715  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523716:
    // 00523716  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523717  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523718  b90c1b5500             -mov ecx, 0x551b0c
    cpu.ecx = 5577484 /*0x551b0c*/;
    // 0052371d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052371e  bb1c1b5500             -mov ebx, 0x551b1c
    cpu.ebx = 5577500 /*0x551b1c*/;
    // 00523723  be35000000             -mov esi, 0x35
    cpu.esi = 53 /*0x35*/;
    // 00523728  682c1b5500             -push 0x551b2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577516 /*0x551b2c*/;
    cpu.esp -= 4;
    // 0052372d  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00523733  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00523739  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0052373f  e8ccd8edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00523744  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523747  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523748  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523749  eb89                   -jmp 0x5236d4
    goto L_0x005236d4;
L_0x0052374b:
    // 0052374b  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0052374e  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00523750  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00523753  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523754  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523755  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523762  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523763  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523764  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00523767  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00523769  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052376b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052376d  3b0500505600           +cmp eax, dword ptr [0x565000]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523773  7c49                   -jl 0x5237be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005237be;
    }
    // 00523775  3b0508505600           +cmp eax, dword ptr [0x565008]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052377b  7d41                   -jge 0x5237be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005237be;
    }
    // 0052377d  3b3504505600           +cmp esi, dword ptr [0x565004]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523783  7c39                   -jl 0x5237be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005237be;
    }
    // 00523785  3b350c505600           +cmp esi, dword ptr [0x56500c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052378b  7d31                   -jge 0x5237be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005237be;
    }
    // 0052378d  803d1050560010         +cmp byte ptr [0x565010], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523794  7509                   -jne 0x52379f
    if (!cpu.flags.zf)
    {
        goto L_0x0052379f;
    }
    // 00523796  803d1250560000         +cmp byte ptr [0x565012], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5656594) /* 0x565012 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052379d  7427                   -je 0x5237c6
    if (cpu.flags.zf)
    {
        goto L_0x005237c6;
    }
L_0x0052379f:
    // 0052379f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005237a1  c1eb18                 -shr ebx, 0x18
    cpu.ebx >>= 24 /*0x18*/ % 32;
    // 005237a4  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005237aa  81fbff000000           +cmp ebx, 0xff
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
    // 005237b0  0f84ae000000           -je 0x523864
    if (cpu.flags.zf)
    {
        goto L_0x00523864;
    }
    // 005237b6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005237b8  0f85c0000000           -jne 0x52387e
    if (!cpu.flags.zf)
    {
        goto L_0x0052387e;
    }
L_0x005237be:
    // 005237be  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 005237c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005237c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005237c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005237c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005237c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005237c6:
    // 005237c6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005237c8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005237ca  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 005237d0  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 005237d3  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 005237d9  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 005237dc  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 005237e2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005237e4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005237e6  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005237ec  726b                   -jb 0x523859
    if (cpu.flags.cf)
    {
        goto L_0x00523859;
    }
    // 005237ee  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005237f4  7340                   -jae 0x523836
    if (!cpu.flags.cf)
    {
        goto L_0x00523836;
    }
    // 005237f6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 005237f9  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005237fb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005237fd  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00523800  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00523803  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00523805  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0052380b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0052380e  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00523813  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00523816  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00523818  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0052381a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0052381d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052381f  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00523822  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00523824  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00523827  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052382d  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00523832  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00523834  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00523836:
    // 00523836  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00523838  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0052383e  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00523841  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00523843  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00523846  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0052384c  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0052384f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00523852  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00523854  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00523856  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00523859:
    // 00523859  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0052385c  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0052385f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523860  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523861  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523862  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523863  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523864:
    // 00523864  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523866  e8f5befcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0052386b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0052386d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052386f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00523871  e88a020000             -call 0x523b00
    cpu.esp -= 4;
    sub_523b00(app, cpu);
    if (cpu.terminate) return;
    // 00523876  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00523879  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052387a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052387b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052387c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052387d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052387e:
    // 0052387e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523880  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00523883  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00523888  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052388b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052388d  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 00523890  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00523896  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052389b  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052389f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005238a3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005238a5  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 005238aa  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 005238ad  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 005238af  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005238b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005238b3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005238b5  e80603feff             -call 0x503bc0
    cpu.esp -= 4;
    sub_503bc0(app, cpu);
    if (cpu.terminate) return;
    // 005238ba  e8e18afeff             -call 0x50c3a0
    cpu.esp -= 4;
    sub_50c3a0(app, cpu);
    if (cpu.terminate) return;
    // 005238bf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005238c1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 005238c4  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005238ca  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005238ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005238d0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005238d2  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 005238d5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005238da  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005238e0  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005238e4  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 005238e8  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 005238ed  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 005238f2  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 005238f4  2b442414               -sub eax, dword ptr [esp + 0x14]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 005238f8  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 005238fb  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 00523900  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00523902  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00523905  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00523907  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00523909  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 0052390c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052390e  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00523914  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00523918  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052391a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052391c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0052391e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00523921  c1e810                 +shr eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00523924  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00523926  030424                 -add eax, dword ptr [esp]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00523929  39d8                   +cmp eax, ebx
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
    // 0052392b  0f8e77000000           -jle 0x5239a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005239a8;
    }
    // 00523931  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00523933:
    // 00523933  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00523935  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00523937  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052393b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052393f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00523941  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00523944  c1e810                 +shr eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00523947  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00523949  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0052394b  3dff000000             +cmp eax, 0xff
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
    // 00523950  7e6e                   -jle 0x5239c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005239c0;
    }
    // 00523952  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x00523957:
    // 00523957  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00523959  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052395b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052395f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00523961  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00523964  c1e810                 +shr eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00523967  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00523969  03442404               -add eax, dword ptr [esp + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052396d  3dff000000             +cmp eax, 0xff
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
    // 00523972  7e60                   -jle 0x5239d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005239d4;
    }
    // 00523974  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x00523979:
    // 00523979  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052397d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052397f  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00523982  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00523985  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00523987  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00523989  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0052398c  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052398e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00523990  e8cbbdfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00523995  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00523997  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00523999  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052399b  e860010000             -call 0x523b00
    cpu.esp -= 4;
    sub_523b00(app, cpu);
    if (cpu.terminate) return;
    // 005239a0  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 005239a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005239a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005239a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005239a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005239a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005239a8:
    // 005239a8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005239aa  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005239ac  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 005239af  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 005239b1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 005239b4  c1e810                 +shr eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005239b7  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 005239b9  01d8                   +add eax, ebx
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
    // 005239bb  e973ffffff             -jmp 0x523933
    goto L_0x00523933;
L_0x005239c0:
    // 005239c0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005239c4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005239c6  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 005239c8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 005239cb  c1e810                 +shr eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005239ce  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 005239d0  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005239d2  eb83                   -jmp 0x523957
    goto L_0x00523957;
L_0x005239d4:
    // 005239d4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005239d8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005239da  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005239de  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 005239e0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 005239e3  c1e810                 +shr eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005239e6  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 005239e8  01c8                   +add eax, ecx
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
    // 005239ea  eb8d                   -jmp 0x523979
    goto L_0x00523979;
}

/* align: skip  */
void Application::sub_5239ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005239ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005239ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005239ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005239ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005239f0  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005239f5  0f8efb000000           -jle 0x523af6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00523af6;
    }
    // 005239fb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005239fd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005239ff  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00523a03  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00523a07  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00523a0b  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00523a0f  83f901                 +cmp ecx, 1
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
    // 00523a12  0f8cde000000           -jl 0x523af6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00523af6;
    }
    // 00523a18  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00523a1a  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00523a1e  7259                   -jb 0x523a79
    if (cpu.flags.cf)
    {
        goto L_0x00523a79;
    }
L_0x00523a20:
    // 00523a20  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x00523a24:
    // 00523a24  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00523a27  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00523a2a  8a5f02                 -mov bl, byte ptr [edi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00523a2d  8a5703                 -mov dl, byte ptr [edi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 00523a30  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 00523a33  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523a36  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 00523a3a  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 00523a3e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00523a41  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 00523a43  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 00523a45  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00523a47  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00523a4a  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 00523a4d  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523a50  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 00523a54  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 00523a58  83e901                 +sub ecx, 1
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
    // 00523a5b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00523a5d  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00523a60  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00523a63  7fbf                   -jg 0x523a24
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00523a24;
    }
    // 00523a65  03742428               -add esi, dword ptr [esp + 0x28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 00523a69  037c242c               -add edi, dword ptr [esp + 0x2c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 00523a6d  836c242401             +sub dword ptr [esp + 0x24], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523a72  75ac                   -jne 0x523a20
    if (!cpu.flags.zf)
    {
        goto L_0x00523a20;
    }
    // 00523a74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523a75  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523a76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523a77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523a78  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523a79:
    // 00523a79  8344242801             -add dword ptr [esp + 0x28], 1
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00523a7e  8344242c02             -add dword ptr [esp + 0x2c], 2
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00523a83:
    // 00523a83  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00523a87  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523a8a  7441                   -je 0x523acd
    if (cpu.flags.zf)
    {
        goto L_0x00523acd;
    }
L_0x00523a8c:
    // 00523a8c  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00523a8f  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00523a92  8a5f02                 -mov bl, byte ptr [edi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00523a95  8a5703                 -mov dl, byte ptr [edi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 00523a98  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 00523a9b  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523a9e  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 00523aa2  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 00523aa6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00523aa9  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 00523aab  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 00523aad  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00523aaf  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00523ab2  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 00523ab5  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523ab8  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 00523abc  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 00523ac0  83e901                 +sub ecx, 1
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
    // 00523ac3  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00523ac5  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00523ac8  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00523acb  7fbf                   -jg 0x523a8c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00523a8c;
    }
L_0x00523acd:
    // 00523acd  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 00523acf  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00523ad1  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00523ad4  88fe                   -mov dh, bh
    cpu.dh = cpu.bh;
    // 00523ad6  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 00523ad9  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523adc  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 00523ae0  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 00523ae4  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 00523ae7  03742428               -add esi, dword ptr [esp + 0x28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 00523aeb  037c242c               -add edi, dword ptr [esp + 0x2c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 00523aef  836c242401             +sub dword ptr [esp + 0x24], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523af4  758d                   -jne 0x523a83
    if (!cpu.flags.zf)
    {
        goto L_0x00523a83;
    }
L_0x00523af6:
    // 00523af6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523af7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523af8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523af9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523afa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523b00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523b01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523b02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523b03  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00523b05  3b0500505600           +cmp eax, dword ptr [0x565000]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523b0b  0f8c9c000000           -jl 0x523bad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00523bad;
    }
    // 00523b11  3b0508505600           +cmp eax, dword ptr [0x565008]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523b17  0f8d90000000           -jge 0x523bad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00523bad;
    }
    // 00523b1d  3b1504505600           +cmp edx, dword ptr [0x565004]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523b23  0f8c84000000           -jl 0x523bad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00523bad;
    }
    // 00523b29  3b150c505600           +cmp edx, dword ptr [0x56500c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523b2f  0f8d78000000           -jge 0x523bad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00523bad;
    }
    // 00523b35  a120505600             -mov eax, dword ptr [0x565020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 00523b3a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00523b3d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00523b3f  a124505600             -mov eax, dword ptr [0x565024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 00523b44  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00523b46  8b3488                 -mov esi, dword ptr [eax + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00523b49  a114505600             -mov eax, dword ptr [0x565014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */);
    // 00523b4e  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00523b50  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00523b52  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 00523b57  3c0f                   +cmp al, 0xf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523b59  7356                   -jae 0x523bb1
    if (!cpu.flags.cf)
    {
        goto L_0x00523bb1;
    }
    // 00523b5b  3c04                   +cmp al, 4
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523b5d  0f836b000000           -jae 0x523bce
    if (!cpu.flags.cf)
    {
        goto L_0x00523bce;
    }
L_0x00523b63:
    // 00523b63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523b64  c7059821550053000000   -mov dword ptr [0x552198], 0x53
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = 83 /*0x53*/;
    // 00523b6e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523b70  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 00523b75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523b76  bf681b5500             -mov edi, 0x551b68
    cpu.edi = 5577576 /*0x551b68*/;
    // 00523b7b  bd781b5500             -mov ebp, 0x551b78
    cpu.ebp = 5577592 /*0x551b78*/;
    // 00523b80  68841b5500             -push 0x551b84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577604 /*0x551b84*/;
    cpu.esp -= 4;
    // 00523b85  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 00523b8b  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 00523b91  e87ad4edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00523b96  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00523b99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00523b9a:
    // 00523b9a  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00523b9d  743b                   -je 0x523bda
    if (cpu.flags.zf)
    {
        goto L_0x00523bda;
    }
    // 00523b9f  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 00523ba1  80e70f                 -and bh, 0xf
    cpu.bh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523ba4  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00523ba6  c0e004                 -shl al, 4
    cpu.al <<= 4 /*0x4*/ % 32;
    // 00523ba9  08c7                   +or bh, al
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(cpu.al))));
    // 00523bab  883a                   -mov byte ptr [edx], bh
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bh;
L_0x00523bad:
    // 00523bad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523baf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bb0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523bb1:
    // 00523bb1  7608                   -jbe 0x523bbb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523bbb;
    }
    // 00523bb3  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523bb5  730b                   -jae 0x523bc2
    if (!cpu.flags.cf)
    {
        goto L_0x00523bc2;
    }
    // 00523bb7  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523bb9  75a8                   -jne 0x523b63
    if (!cpu.flags.zf)
    {
        goto L_0x00523b63;
    }
L_0x00523bbb:
    // 00523bbb  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 00523bbe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bc0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bc1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523bc2:
    // 00523bc2  7622                   -jbe 0x523be6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523be6;
    }
    // 00523bc4  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523bc6  759b                   -jne 0x523b63
    if (!cpu.flags.zf)
    {
        goto L_0x00523b63;
    }
    // 00523bc8  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00523bca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bcd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523bce:
    // 00523bce  76ca                   -jbe 0x523b9a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523b9a;
    }
    // 00523bd0  3c08                   +cmp al, 8
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523bd2  758f                   -jne 0x523b63
    if (!cpu.flags.zf)
    {
        goto L_0x00523b63;
    }
    // 00523bd4  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00523bd6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bd7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bd8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bd9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523bda:
    // 00523bda  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00523bdc  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00523bde  08d8                   -or al, bl
    cpu.al |= x86::reg8(x86::sreg8(cpu.bl));
    // 00523be0  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00523be2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523be3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523be4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523be5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523be6:
    // 00523be6  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 00523be9  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 00523bec  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00523bef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bf0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bf1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bf2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523c00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523c01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523c02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523c03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523c04  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00523c06  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523c09  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00523c0b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00523c0d  7507                   -jne 0x523c16
    if (!cpu.flags.zf)
    {
        goto L_0x00523c16;
    }
    // 00523c0f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00523c11  e983000000             -jmp 0x523c99
    goto L_0x00523c99;
L_0x00523c16:
    // 00523c16  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00523c18  0f8676000000           -jbe 0x523c94
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523c94;
    }
    // 00523c1e  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523c21  7512                   -jne 0x523c35
    if (!cpu.flags.zf)
    {
        goto L_0x00523c35;
    }
    // 00523c23  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00523c25  7405                   -je 0x523c2c
    if (cpu.flags.zf)
    {
        goto L_0x00523c2c;
    }
    // 00523c27  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
L_0x00523c2c:
    // 00523c2c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523c2e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00523c30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523c35:
    // 00523c35  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 00523c3c  7419                   -je 0x523c57
    if (cpu.flags.zf)
    {
        goto L_0x00523c57;
    }
    // 00523c3e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523c40  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00523c42  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 00523c48  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00523c4a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00523c4f  7406                   -je 0x523c57
    if (cpu.flags.zf)
    {
        goto L_0x00523c57;
    }
    // 00523c51  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523c55  743d                   -je 0x523c94
    if (cpu.flags.zf)
    {
        goto L_0x00523c94;
    }
L_0x00523c57:
    // 00523c57  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00523c59  e852790000             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 00523c5e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00523c60  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00523c63  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00523c65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523c66  39c3                   +cmp ebx, eax
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
    // 00523c68  7302                   -jae 0x523c6c
    if (!cpu.flags.cf)
    {
        goto L_0x00523c6c;
    }
    // 00523c6a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00523c6c:
    // 00523c6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523c6d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523c6e  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00523c70  a1b8b05600             -mov eax, dword ptr [0x56b0b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681336) /* 0x56b0b8 */);
    // 00523c75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523c76  2eff1598455300         -call dword ptr cs:[0x534598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457304) /* 0x534598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00523c7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523c7f  7413                   -je 0x523c94
    if (cpu.flags.zf)
    {
        goto L_0x00523c94;
    }
    // 00523c81  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00523c83  7406                   -je 0x523c8b
    if (cpu.flags.zf)
    {
        goto L_0x00523c8b;
    }
    // 00523c85  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00523c88  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x00523c8b:
    // 00523c8b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00523c8d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00523c8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c93  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523c94:
    // 00523c94  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00523c99:
    // 00523c99  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00523c9b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_523ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523ca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523ca1  f7c20000f07f           +test edx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2146435072 /*0x7ff00000*/));
    // 00523ca7  743f                   -je 0x523ce8
    if (cpu.flags.zf)
    {
        goto L_0x00523ce8;
    }
    // 00523ca9  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00523cab  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523cad  11d2                   +adc edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523caf  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 00523cb1  0500000020             +add eax, 0x20000000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(536870912 /*0x20000000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523cb6  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523cb9  7424                   -je 0x523cdf
    if (cpu.flags.zf)
    {
        goto L_0x00523cdf;
    }
    // 00523cbb  81fa0000e08f           +cmp edx, 0x8fe00000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2413821952 /*0x8fe00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523cc1  731c                   -jae 0x523cdf
    if (!cpu.flags.cf)
    {
        goto L_0x00523cdf;
    }
    // 00523cc3  81fa00002070           +cmp edx, 0x70200000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1881145344 /*0x70200000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523cc9  721d                   -jb 0x523ce8
    if (cpu.flags.cf)
    {
        goto L_0x00523ce8;
    }
    // 00523ccb  81ea00000070           -sub edx, 0x70000000
    (cpu.edx) -= x86::reg32(x86::sreg32(1879048192 /*0x70000000*/));
    // 00523cd1  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523cd3  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00523cd5  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523cd7  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00523cd9  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00523cdb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00523cdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523cde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523cdf:
    // 00523cdf  b80000807f             -mov eax, 0x7f800000
    cpu.eax = 2139095040 /*0x7f800000*/;
    // 00523ce4  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00523ce6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523ce7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523ce8:
    // 00523ce8  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00523cea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523ceb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_523cec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523cec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00523cee  7507                   -jne 0x523cf7
    if (!cpu.flags.zf)
    {
        goto L_0x00523cf7;
    }
    // 00523cf0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00523cf2  7503                   -jne 0x523cf7
    if (!cpu.flags.zf)
    {
        goto L_0x00523cf7;
    }
    // 00523cf4  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00523cf6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523cf7:
    // 00523cf7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523cf8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523cf9  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00523cfb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00523cfd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523cfe  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00523d00  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00523d02  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523d03  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00523d05  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00523d07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523d10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523d11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523d12  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00523d14  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00523d16  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00523d18  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00523d1a  763c                   -jbe 0x523d58
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523d58;
    }
L_0x00523d1c:
    // 00523d1c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523d1e  e89d130000             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 00523d23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523d25  7531                   -jne 0x523d58
    if (!cpu.flags.zf)
    {
        goto L_0x00523d58;
    }
    // 00523d27  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00523d29  e892130000             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 00523d2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523d30  7526                   -jne 0x523d58
    if (!cpu.flags.zf)
    {
        goto L_0x00523d58;
    }
    // 00523d32  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00523d34  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523d36  e8a5780000             -call 0x52b5e0
    cpu.esp -= 4;
    sub_52b5e0(app, cpu);
    if (cpu.terminate) return;
    // 00523d3b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00523d3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523d3f  753d                   -jne 0x523d7e
    if (!cpu.flags.zf)
    {
        goto L_0x00523d7e;
    }
    // 00523d41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523d43  e8b8130000             -call 0x525100
    cpu.esp -= 4;
    sub_525100(app, cpu);
    if (cpu.terminate) return;
    // 00523d48  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00523d4a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00523d4c  4b                     -dec ebx
    (cpu.ebx)--;
    // 00523d4d  e8ae130000             -call 0x525100
    cpu.esp -= 4;
    sub_525100(app, cpu);
    if (cpu.terminate) return;
    // 00523d52  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00523d54  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00523d56  77c4                   -ja 0x523d1c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00523d1c;
    }
L_0x00523d58:
    // 00523d58  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00523d5a  7620                   -jbe 0x523d7c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523d7c;
    }
    // 00523d5c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523d5e  e85d130000             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 00523d63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523d65  750b                   -jne 0x523d72
    if (!cpu.flags.zf)
    {
        goto L_0x00523d72;
    }
    // 00523d67  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00523d69  e852130000             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 00523d6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523d70  740a                   -je 0x523d7c
    if (cpu.flags.zf)
    {
        goto L_0x00523d7c;
    }
L_0x00523d72:
    // 00523d72  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00523d74  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523d76  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00523d78  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00523d7a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00523d7c:
    // 00523d7c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00523d7e:
    // 00523d7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523d7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523d80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523d90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523d92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_523d94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523d94  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523d95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523d96  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523d97  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00523d9a  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00523d9e  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00523da2  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00523da4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00523da6  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00523daa  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00523dae  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00523db1  81c658f69e00           -add esi, 0x9ef658
    (cpu.esi) += x86::reg32(x86::sreg32(10417752 /*0x9ef658*/));
    // 00523db7  c6460601               -mov byte ptr [esi + 6], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = 1 /*0x1*/;
    // 00523dbb  66c7460a0000           -mov word ptr [esi + 0xa], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 00523dc1  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00523dc8  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00523dcb  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 00523dce  668b4102               -mov ax, word ptr [ecx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00523dd2  2403                   -and al, 3
    cpu.al &= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00523dd4  884603                 -mov byte ptr [esi + 3], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00523dd7  668b4102               -mov ax, word ptr [ecx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00523ddb  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00523ddd  663d0c00               +cmp ax, 0xc
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(12 /*0xc*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00523de1  0f84a1000000           -je 0x523e88
    if (cpu.flags.zf)
    {
        goto L_0x00523e88;
    }
    // 00523de7  663d1000               +cmp ax, 0x10
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00523deb  0f85a4000000           -jne 0x523e95
    if (!cpu.flags.zf)
    {
        goto L_0x00523e95;
    }
    // 00523df1  c6460210               -mov byte ptr [esi + 2], 0x10
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = 16 /*0x10*/;
    // 00523df5  c6460409               -mov byte ptr [esi + 4], 9
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 9 /*0x9*/;
L_0x00523df9:
    // 00523df9  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00523dfd  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00523dff  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00523e01  e8eae4ffff             -call 0x5222f0
    cpu.esp -= 4;
    sub_5222f0(app, cpu);
    if (cpu.terminate) return;
    // 00523e06  807e0210               +cmp byte ptr [esi + 2], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523e0a  0f85e9000000           -jne 0x523ef9
    if (!cpu.flags.zf)
    {
        goto L_0x00523ef9;
    }
    // 00523e10  807e0301               +cmp byte ptr [esi + 3], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523e14  0f85df000000           -jne 0x523ef9
    if (!cpu.flags.zf)
    {
        goto L_0x00523ef9;
    }
    // 00523e1a  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
L_0x00523e1f:
    // 00523e1f  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00523e23  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00523e25  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523e27  668b1514f69e00         -mov dx, word ptr [0x9ef614]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10417684) /* 0x9ef614 */);
    // 00523e2e  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00523e31  e8daf0ffff             -call 0x522f10
    cpu.esp -= 4;
    sub_522f10(app, cpu);
    if (cpu.terminate) return;
    // 00523e36  8b1514f69e00           -mov edx, dword ptr [0x9ef614]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10417684) /* 0x9ef614 */);
    // 00523e3c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00523e3f  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00523e41  83ff64                 +cmp edi, 0x64
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523e44  0f8e2d010000           -jle 0x523f77
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00523f77;
    }
    // 00523e4a  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
L_0x00523e4f:
    // 00523e4f  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00523e53  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523e54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523e55  c6460500               -mov byte ptr [esi + 5], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = 0 /*0x0*/;
    // 00523e59  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523e5a  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00523e5e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523e5f  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00523e63  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523e64  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00523e66  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00523e68  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00523e6a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00523e6e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00523e70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00523e72  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00523e75  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00523e77  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00523e7a  e839c2fdff             -call 0x5000b8
    cpu.esp -= 4;
    sub_5000b8(app, cpu);
    if (cpu.terminate) return;
    // 00523e7f  83c40c                 +add esp, 0xc
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
    // 00523e82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523e83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523e84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523e85  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00523e88:
    // 00523e88  c6460210               -mov byte ptr [esi + 2], 0x10
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = 16 /*0x10*/;
    // 00523e8c  c6460407               -mov byte ptr [esi + 4], 7
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 7 /*0x7*/;
    // 00523e90  e964ffffff             -jmp 0x523df9
    goto L_0x00523df9;
L_0x00523e95:
    // 00523e95  663d0800               +cmp ax, 8
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00523e99  750d                   -jne 0x523ea8
    if (!cpu.flags.zf)
    {
        goto L_0x00523ea8;
    }
    // 00523e9b  c6460208               -mov byte ptr [esi + 2], 8
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = 8 /*0x8*/;
    // 00523e9f  c6460400               -mov byte ptr [esi + 4], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00523ea3  e951ffffff             -jmp 0x523df9
    goto L_0x00523df9;
L_0x00523ea8:
    // 00523ea8  66f74102fcff           +test word ptr [ecx + 2], 0xfffc
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) & 65532 /*0xfffc*/));
    // 00523eae  750d                   -jne 0x523ebd
    if (!cpu.flags.zf)
    {
        goto L_0x00523ebd;
    }
    // 00523eb0  c6460210               -mov byte ptr [esi + 2], 0x10
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = 16 /*0x10*/;
    // 00523eb4  c6460400               -mov byte ptr [esi + 4], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00523eb8  e93cffffff             -jmp 0x523df9
    goto L_0x00523df9;
L_0x00523ebd:
    // 00523ebd  bab01b5500             -mov edx, 0x551bb0
    cpu.edx = 5577648 /*0x551bb0*/;
    // 00523ec2  b9c01b5500             -mov ecx, 0x551bc0
    cpu.ecx = 5577664 /*0x551bc0*/;
    // 00523ec7  bb44000000             -mov ebx, 0x44
    cpu.ebx = 68 /*0x44*/;
    // 00523ecc  68d81b5500             -push 0x551bd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577688 /*0x551bd8*/;
    cpu.esp -= 4;
    // 00523ed1  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00523ed7  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00523edd  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00523ee3  e828d1edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00523ee8  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
    // 00523eed  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523ef0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00523ef3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523ef4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523ef5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523ef6  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00523ef9:
    // 00523ef9  807e0210               +cmp byte ptr [esi + 2], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523efd  7510                   -jne 0x523f0f
    if (!cpu.flags.zf)
    {
        goto L_0x00523f0f;
    }
    // 00523eff  807e0302               +cmp byte ptr [esi + 3], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f03  750a                   -jne 0x523f0f
    if (!cpu.flags.zf)
    {
        goto L_0x00523f0f;
    }
    // 00523f05  bd08000000             -mov ebp, 8
    cpu.ebp = 8 /*0x8*/;
    // 00523f0a  e910ffffff             -jmp 0x523e1f
    goto L_0x00523e1f;
L_0x00523f0f:
    // 00523f0f  807e0208               +cmp byte ptr [esi + 2], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f13  7510                   -jne 0x523f25
    if (!cpu.flags.zf)
    {
        goto L_0x00523f25;
    }
    // 00523f15  807e0301               +cmp byte ptr [esi + 3], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f19  750a                   -jne 0x523f25
    if (!cpu.flags.zf)
    {
        goto L_0x00523f25;
    }
    // 00523f1b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00523f20  e9fafeffff             -jmp 0x523e1f
    goto L_0x00523e1f;
L_0x00523f25:
    // 00523f25  807e0208               +cmp byte ptr [esi + 2], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f29  7510                   -jne 0x523f3b
    if (!cpu.flags.zf)
    {
        goto L_0x00523f3b;
    }
    // 00523f2b  807e0302               +cmp byte ptr [esi + 3], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f2f  750a                   -jne 0x523f3b
    if (!cpu.flags.zf)
    {
        goto L_0x00523f3b;
    }
    // 00523f31  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00523f36  e9e4feffff             -jmp 0x523e1f
    goto L_0x00523e1f;
L_0x00523f3b:
    // 00523f3b  beb01b5500             -mov esi, 0x551bb0
    cpu.esi = 5577648 /*0x551bb0*/;
    // 00523f40  bfc01b5500             -mov edi, 0x551bc0
    cpu.edi = 5577664 /*0x551bc0*/;
    // 00523f45  bd59000000             -mov ebp, 0x59
    cpu.ebp = 89 /*0x59*/;
    // 00523f4a  68181c5500             -push 0x551c18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577752 /*0x551c18*/;
    cpu.esp -= 4;
    // 00523f4f  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 00523f55  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00523f5b  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00523f61  e8aad0edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00523f66  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00523f6b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523f6e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00523f71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523f72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523f73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523f74  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00523f77:
    // 00523f77  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00523f79  0f8dd0feffff           -jge 0x523e4f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00523e4f;
    }
    // 00523f7f  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00523f81  e9c9feffff             -jmp 0x523e4f
    goto L_0x00523e4f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523f90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523f91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523f92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523f93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523f94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523f95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523f96  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00523f98  80780500               +cmp byte ptr [eax + 5], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f9c  7c3f                   -jl 0x523fdd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00523fdd;
    }
L_0x00523f9e:
    // 00523f9e  807a0600               +cmp byte ptr [edx + 6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fa2  7c70                   -jl 0x524014
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00524014;
    }
L_0x00523fa4:
    // 00523fa4  807a0800               +cmp byte ptr [edx + 8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fa8  0f8c9f000000           -jl 0x52404d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052404d;
    }
L_0x00523fae:
    // 00523fae  807a0900               +cmp byte ptr [edx + 9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fb2  0f8ccf000000           -jl 0x524087
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00524087;
    }
L_0x00523fb8:
    // 00523fb8  807a0a00               +cmp byte ptr [edx + 0xa], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fbc  0f8cfe000000           -jl 0x5240c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005240c0;
    }
L_0x00523fc2:
    // 00523fc2  807a0b00               +cmp byte ptr [edx + 0xb], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11) /* 0xb */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fc6  0f856a010000           -jne 0x524136
    if (!cpu.flags.zf)
    {
        goto L_0x00524136;
    }
    // 00523fcc  807a0700               +cmp byte ptr [edx + 7], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fd0  0f8c24010000           -jl 0x5240fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005240fa;
    }
L_0x00523fd6:
    // 00523fd6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fd9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fdb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fdc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523fdd:
    // 00523fdd  8b4202                 -mov eax, dword ptr [edx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00523fe0  b9501c5500             -mov ecx, 0x551c50
    cpu.ecx = 5577808 /*0x551c50*/;
    // 00523fe5  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00523fe8  bb601c5500             -mov ebx, 0x551c60
    cpu.ebx = 5577824 /*0x551c60*/;
    // 00523fed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523fee  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 00523ff3  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00523ff9  68741c5500             -push 0x551c74
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577844 /*0x551c74*/;
    cpu.esp -= 4;
    // 00523ffe  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00524004  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0052400a  e801d0edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0052400f  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00524012  eb8a                   -jmp 0x523f9e
    goto L_0x00523f9e;
L_0x00524014:
    // 00524014  c705982155000d000000   -mov dword ptr [0x552198], 0xd
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = 13 /*0xd*/;
    // 0052401e  8b4203                 -mov eax, dword ptr [edx + 3]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 00524021  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00524024  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524025  bf501c5500             -mov edi, 0x551c50
    cpu.edi = 5577808 /*0x551c50*/;
    // 0052402a  bd601c5500             -mov ebp, 0x551c60
    cpu.ebp = 5577824 /*0x551c60*/;
    // 0052402f  68ac1c5500             -push 0x551cac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577900 /*0x551cac*/;
    cpu.esp -= 4;
    // 00524034  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0052403a  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 00524040  e8cbcfedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00524045  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00524048  e957ffffff             -jmp 0x523fa4
    goto L_0x00523fa4;
L_0x0052404d:
    // 0052404d  8b4205                 -mov eax, dword ptr [edx + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 00524050  b9501c5500             -mov ecx, 0x551c50
    cpu.ecx = 5577808 /*0x551c50*/;
    // 00524055  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00524058  bb601c5500             -mov ebx, 0x551c60
    cpu.ebx = 5577824 /*0x551c60*/;
    // 0052405d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052405e  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00524063  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00524069  68e81c5500             -push 0x551ce8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577960 /*0x551ce8*/;
    cpu.esp -= 4;
    // 0052406e  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00524074  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0052407a  e891cfedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0052407f  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00524082  e927ffffff             -jmp 0x523fae
    goto L_0x00523fae;
L_0x00524087:
    // 00524087  c7059821550013000000   -mov dword ptr [0x552198], 0x13
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = 19 /*0x13*/;
    // 00524091  8b4206                 -mov eax, dword ptr [edx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 00524094  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00524097  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524098  bf501c5500             -mov edi, 0x551c50
    cpu.edi = 5577808 /*0x551c50*/;
    // 0052409d  bd601c5500             -mov ebp, 0x551c60
    cpu.ebp = 5577824 /*0x551c60*/;
    // 005240a2  681c1d5500             -push 0x551d1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578012 /*0x551d1c*/;
    cpu.esp -= 4;
    // 005240a7  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 005240ad  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 005240b3  e858cfedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005240b8  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005240bb  e9f8feffff             -jmp 0x523fb8
    goto L_0x00523fb8;
L_0x005240c0:
    // 005240c0  8b4207                 -mov eax, dword ptr [edx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 005240c3  b9501c5500             -mov ecx, 0x551c50
    cpu.ecx = 5577808 /*0x551c50*/;
    // 005240c8  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 005240cb  bb601c5500             -mov ebx, 0x551c60
    cpu.ebx = 5577824 /*0x551c60*/;
    // 005240d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005240d1  be16000000             -mov esi, 0x16
    cpu.esi = 22 /*0x16*/;
    // 005240d6  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 005240dc  68541d5500             -push 0x551d54
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578068 /*0x551d54*/;
    cpu.esp -= 4;
    // 005240e1  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 005240e7  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 005240ed  e81ecfedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005240f2  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005240f5  e9c8feffff             -jmp 0x523fc2
    goto L_0x00523fc2;
L_0x005240fa:
    // 005240fa  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 005240fd  b9501c5500             -mov ecx, 0x551c50
    cpu.ecx = 5577808 /*0x551c50*/;
    // 00524102  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00524105  bb601c5500             -mov ebx, 0x551c60
    cpu.ebx = 5577824 /*0x551c60*/;
    // 0052410a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052410b  be1b000000             -mov esi, 0x1b
    cpu.esi = 27 /*0x1b*/;
    // 00524110  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00524116  68901d5500             -push 0x551d90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578128 /*0x551d90*/;
    cpu.esp -= 4;
    // 0052411b  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00524121  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 00524127  e8e4ceedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0052412c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052412f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524130  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524131  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524132  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524133  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524134  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524135  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00524136:
    // 00524136  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00524139  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052413c  3d00c0ffff             +cmp eax, 0xffffc000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294950912 /*0xffffc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524141  7c0c                   -jl 0x52414f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052414f;
    }
    // 00524143  66817a0eff3f           +cmp word ptr [edx + 0xe], 0x3fff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16383 /*0x3fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00524149  0f8e87feffff           -jle 0x523fd6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00523fd6;
    }
L_0x0052414f:
    // 0052414f  c7059821550020000000   -mov dword ptr [0x552198], 0x20
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = 32 /*0x20*/;
    // 00524159  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0052415c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052415f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524160  bf501c5500             -mov edi, 0x551c50
    cpu.edi = 5577808 /*0x551c50*/;
    // 00524165  bd601c5500             -mov ebp, 0x551c60
    cpu.ebp = 5577824 /*0x551c60*/;
    // 0052416a  68c41d5500             -push 0x551dc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578180 /*0x551dc4*/;
    cpu.esp -= 4;
    // 0052416f  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 00524175  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0052417b  e890ceedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00524180  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00524183  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524184  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524185  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524186  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524187  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524188  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524189  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_524190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524190  803d64af560000         +cmp byte ptr [0x56af64], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5680996) /* 0x56af64 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00524197  741a                   -je 0x5241b3
    if (cpu.flags.zf)
    {
        goto L_0x005241b3;
    }
    // 00524199  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0052419f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005241a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005241a1  cc                     -int3 
    NFS2_ASSERT(false);
    // 005241a2  eb06                   -jmp 0x5241aa
    goto L_0x005241aa;
    // 005241a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005241a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005241a6  49                     -dec ecx
    (cpu.ecx)--;
    // 005241a7  44                     -inc esp
    (cpu.esp)++;
    // 005241a8  45                     -inc ebp
    (cpu.ebp)++;
    // 005241a9  4f                     -dec edi
    (cpu.edi)--;
L_0x005241aa:
    // 005241aa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005241af  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005241b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005241b3:
    // 005241b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005241b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5241c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005241c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005241c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005241c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005241c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005241c4  ff1580775600           -call dword ptr [0x567780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666688) /* 0x567780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005241ca  a14c6f5600             -mov eax, dword ptr [0x566f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */);
    // 005241cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005241d1  741c                   -je 0x5241ef
    if (cpu.flags.zf)
    {
        goto L_0x005241ef;
    }
L_0x005241d3:
    // 005241d3  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 005241d5  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 005241d8  83eb2c                 -sub ebx, 0x2c
    (cpu.ebx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 005241db  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 005241dd  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 005241e0  39f3                   +cmp ebx, esi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005241e2  7505                   -jne 0x5241e9
    if (!cpu.flags.zf)
    {
        goto L_0x005241e9;
    }
    // 005241e4  e873000000             -call 0x52425c
    cpu.esp -= 4;
    sub_52425c(app, cpu);
    if (cpu.terminate) return;
L_0x005241e9:
    // 005241e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005241eb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005241ed  75e4                   -jne 0x5241d3
    if (!cpu.flags.zf)
    {
        goto L_0x005241d3;
    }
L_0x005241ef:
    // 005241ef  ff1588775600           -call dword ptr [0x567788]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666696) /* 0x567788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005241f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005241f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005241f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005241f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005241fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005241fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5241fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005241fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005241fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005241fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005241ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524200  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524201  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00524203  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00524208  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052420a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052420b  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052420e  2eff1528465300         -call dword ptr cs:[0x534628]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457448) /* 0x534628 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524215  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524217  7507                   -jne 0x524220
    if (!cpu.flags.zf)
    {
        goto L_0x00524220;
    }
    // 00524219  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052421e  eb36                   -jmp 0x524256
    goto L_0x00524256;
L_0x00524220:
    // 00524220  3b1d506f5600           +cmp ebx, dword ptr [0x566f50]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524226  751c                   -jne 0x524244
    if (!cpu.flags.zf)
    {
        goto L_0x00524244;
    }
    // 00524228  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052422a  7408                   -je 0x524234
    if (cpu.flags.zf)
    {
        goto L_0x00524234;
    }
    // 0052422c  8935506f5600           -mov dword ptr [0x566f50], esi
    app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */) = cpu.esi;
    // 00524232  eb10                   -jmp 0x524244
    goto L_0x00524244;
L_0x00524234:
    // 00524234  a14c6f5600             -mov eax, dword ptr [0x566f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */);
    // 00524239  8935546f5600           -mov dword ptr [0x566f54], esi
    app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */) = cpu.esi;
    // 0052423f  a3506f5600             -mov dword ptr [0x566f50], eax
    app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */) = cpu.eax;
L_0x00524244:
    // 00524244  3b1d00389f00           +cmp ebx, dword ptr [0x9f3800]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10434560) /* 0x9f3800 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052424a  7508                   -jne 0x524254
    if (!cpu.flags.zf)
    {
        goto L_0x00524254;
    }
    // 0052424c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0052424e  893d00389f00           -mov dword ptr [0x9f3800], edi
    app->getMemory<x86::reg32>(x86::reg32(10434560) /* 0x9f3800 */) = cpu.edi;
L_0x00524254:
    // 00524254  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00524256:
    // 00524256  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524257  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524258  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524259  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052425a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052425b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52425c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052425c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052425d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052425e  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00524261  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00524264  e893ffffff             -call 0x5241fc
    cpu.esp -= 4;
    sub_5241fc(app, cpu);
    if (cpu.terminate) return;
    // 00524269  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052426b  7516                   -jne 0x524283
    if (!cpu.flags.zf)
    {
        goto L_0x00524283;
    }
    // 0052426d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052426f  7508                   -jne 0x524279
    if (!cpu.flags.zf)
    {
        goto L_0x00524279;
    }
    // 00524271  89154c6f5600           -mov dword ptr [0x566f4c], edx
    app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */) = cpu.edx;
    // 00524277  eb03                   -jmp 0x52427c
    goto L_0x0052427c;
L_0x00524279:
    // 00524279  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x0052427c:
    // 0052427c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052427e  7403                   -je 0x524283
    if (cpu.flags.zf)
    {
        goto L_0x00524283;
    }
    // 00524280  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00524283:
    // 00524283  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524284  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524285  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_524290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524290  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524291  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00524292  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00524294  8b1520785600           -mov edx, dword ptr [0x567820]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666848) /* 0x567820 */);
    // 0052429a  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0052429d  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 005242a0  e81b03fdff             -call 0x4f45c0
    cpu.esp -= 4;
    sub_4f45c0(app, cpu);
    if (cpu.terminate) return;
    // 005242a5  39c2                   +cmp edx, eax
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
    // 005242a7  7316                   -jae 0x5242bf
    if (!cpu.flags.cf)
    {
        goto L_0x005242bf;
    }
    // 005242a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005242aa  e86103fdff             -call 0x4f4610
    cpu.esp -= 4;
    sub_4f4610(app, cpu);
    if (cpu.terminate) return;
    // 005242af  a120785600             -mov eax, dword ptr [0x567820]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5666848) /* 0x567820 */);
    // 005242b4  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005242b7  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 005242b9  29c4                   +sub esp, eax
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005242bb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005242bd  eb02                   -jmp 0x5242c1
    goto L_0x005242c1;
L_0x005242bf:
    // 005242bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x005242c1:
    // 005242c1  8b1520785600           -mov edx, dword ptr [0x567820]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666848) /* 0x567820 */);
    // 005242c7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005242c9  a324785600             -mov dword ptr [0x567824], eax
    app->getMemory<x86::reg32>(x86::reg32(5666852) /* 0x567824 */) = cpu.eax;
    // 005242ce  e86d730000             -call 0x52b640
    cpu.esp -= 4;
    sub_52b640(app, cpu);
    if (cpu.terminate) return;
    // 005242d3  8b151482a100           -mov edx, dword ptr [0xa18214]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10584596) /* 0xa18214 */);
    // 005242d9  a11082a100             -mov eax, dword ptr [0xa18210]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584592) /* 0xa18210 */);
    // 005242de  e8cdfaf7ff             -call 0x4a3db0
    cpu.esp -= 4;
    sub_4a3db0(app, cpu);
    if (cpu.terminate) return;
    // 005242e3  e81cbafbff             -call 0x4dfd04
    cpu.esp -= 4;
    sub_4dfd04(app, cpu);
    if (cpu.terminate) return;
    // 005242e8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005242ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005242eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005242ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_5242f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005242f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005242f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005242f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005242f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005242f4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005242f7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005242fb  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 005242fd  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00524300  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00524302  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524304  0f8471000000           -je 0x52437b
    if (cpu.flags.zf)
    {
        goto L_0x0052437b;
    }
L_0x0052430a:
    // 0052430a  833c2400               +cmp dword ptr [esp], 0
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
    // 0052430e  0f8689000000           -jbe 0x52439d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052439d;
    }
    // 00524314  668b4d00               -mov cx, word ptr [ebp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp);
    // 00524318  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0052431b  7420                   -je 0x52433d
    if (cpu.flags.zf)
    {
        goto L_0x0052433d;
    }
    // 0052431d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052431f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524323  6689ca                 -mov dx, cx
    cpu.dx = cpu.cx;
    // 00524326  e8359dffff             -call 0x51e060
    cpu.esp -= 4;
    sub_51e060(app, cpu);
    if (cpu.terminate) return;
    // 0052432b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052432d  83f8ff                 +cmp eax, -1
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
    // 00524330  0f8469000000           -je 0x52439f
    if (cpu.flags.zf)
    {
        goto L_0x0052439f;
    }
    // 00524336  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00524339  7762                   -ja 0x52439d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052439d;
    }
    // 0052433b  eb09                   -jmp 0x524346
    goto L_0x00524346;
L_0x0052433d:
    // 0052433d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00524341  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00524344  eb57                   -jmp 0x52439d
    goto L_0x0052439d;
L_0x00524346:
    // 00524346  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052434a  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052434e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00524350  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00524351  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00524353  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00524355  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524356  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00524358  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052435b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052435d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052435f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00524362  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00524364  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524365  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00524366  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00524369  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052436b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052436e  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00524370  29d0                   +sub eax, edx
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
    // 00524372  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00524376  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00524379  eb8f                   -jmp 0x52430a
    goto L_0x0052430a;
L_0x0052437b:
    // 0052437b  66837d0000             +cmp word ptr [ebp], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00524380  741b                   -je 0x52439d
    if (cpu.flags.zf)
    {
        goto L_0x0052439d;
    }
    // 00524382  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524384  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524388  668b5500               -mov dx, word ptr [ebp]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp);
    // 0052438c  e8cf9cffff             -call 0x51e060
    cpu.esp -= 4;
    sub_51e060(app, cpu);
    if (cpu.terminate) return;
    // 00524391  83f8ff                 +cmp eax, -1
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
    // 00524394  7409                   -je 0x52439f
    if (cpu.flags.zf)
    {
        goto L_0x0052439f;
    }
    // 00524396  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00524399  01c3                   +add ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052439b  ebde                   -jmp 0x52437b
    goto L_0x0052437b;
L_0x0052439d:
    // 0052439d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0052439f:
    // 0052439f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005243a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005243a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005243a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005243a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005243a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5243a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005243a7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005243a8  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 005243aa  e802000000             -call 0x5243b1
    cpu.esp -= 4;
    sub_5243b1(app, cpu);
    if (cpu.terminate) return;
    // 005243af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005243b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5243b1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005243b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005243b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005243b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005243b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005243b6  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005243b9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005243bb  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 005243bd  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 005243c0  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 005243c3  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 005243c6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 005243c8  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 005243cb  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005243ce  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 005243d1  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 005243d4  7407                   -je 0x5243dd
    if (cpu.flags.zf)
    {
        goto L_0x005243dd;
    }
    // 005243d6  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 005243db  eb3a                   -jmp 0x524417
    goto L_0x00524417;
L_0x005243dd:
    // 005243dd  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 005243e0  7407                   -je 0x5243e9
    if (cpu.flags.zf)
    {
        goto L_0x005243e9;
    }
    // 005243e2  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 005243e7  eb2e                   -jmp 0x524417
    goto L_0x00524417;
L_0x005243e9:
    // 005243e9  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 005243ec  7407                   -je 0x5243f5
    if (cpu.flags.zf)
    {
        goto L_0x005243f5;
    }
    // 005243ee  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 005243f3  eb22                   -jmp 0x524417
    goto L_0x00524417;
L_0x005243f5:
    // 005243f5  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 005243f8  7407                   -je 0x524401
    if (cpu.flags.zf)
    {
        goto L_0x00524401;
    }
    // 005243fa  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 005243ff  eb16                   -jmp 0x524417
    goto L_0x00524417;
L_0x00524401:
    // 00524401  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 00524404  7407                   -je 0x52440d
    if (cpu.flags.zf)
    {
        goto L_0x0052440d;
    }
    // 00524406  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 0052440b  eb0a                   -jmp 0x524417
    goto L_0x00524417;
L_0x0052440d:
    // 0052440d  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 00524410  7405                   -je 0x524417
    if (cpu.flags.zf)
    {
        goto L_0x00524417;
    }
    // 00524412  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
L_0x00524417:
    // 00524417  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00524419  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0052441c  8b048570af5600         -mov eax, dword ptr [eax*4 + 0x56af70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */ + cpu.eax * 4);
    // 00524423  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 00524426  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00524429  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 0052442c  740d                   -je 0x52443b
    if (cpu.flags.zf)
    {
        goto L_0x0052443b;
    }
    // 0052442e  dd057c215500           +fld qword ptr [0x55217c]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5579132) /* 0x55217c */)));
    // 00524434  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00524436  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00524439  eb42                   -jmp 0x52447d
    goto L_0x0052447d;
L_0x0052443b:
    // 0052443b  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 0052443e  740a                   -je 0x52444a
    if (cpu.flags.zf)
    {
        goto L_0x0052444a;
    }
    // 00524440  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00524442  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 00524445  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00524448  eb33                   -jmp 0x52447d
    goto L_0x0052447d;
L_0x0052444a:
    // 0052444a  f6c540                 +test ch, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 64 /*0x40*/));
    // 0052444d  740f                   -je 0x52445e
    if (cpu.flags.zf)
    {
        goto L_0x0052445e;
    }
    // 0052444f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00524451  bb0000f03f             -mov ebx, 0x3ff00000
    cpu.ebx = 1072693248 /*0x3ff00000*/;
    // 00524456  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00524459  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0052445c  eb1f                   -jmp 0x52447d
    goto L_0x0052447d;
L_0x0052445e:
    // 0052445e  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 00524461  740f                   -je 0x524472
    if (cpu.flags.zf)
    {
        goto L_0x00524472;
    }
    // 00524463  a17c215500             -mov eax, dword ptr [0x55217c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5579132) /* 0x55217c */);
    // 00524468  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0052446b  a180215500             -mov eax, dword ptr [0x552180]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5579136) /* 0x552180 */);
    // 00524470  eb08                   -jmp 0x52447a
    goto L_0x0052447a;
L_0x00524472:
    // 00524472  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00524474  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00524477  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
L_0x0052447a:
    // 0052447a  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x0052447d:
    // 0052447d  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00524480  e80a720000             -call 0x52b68f
    cpu.esp -= 4;
    sub_52b68f(app, cpu);
    if (cpu.terminate) return;
    // 00524485  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00524488  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524489  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052448a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052448b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52448c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052448c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052448d  668b5008               -mov dx, word ptr [eax + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00524491  80e67f                 -and dh, 0x7f
    cpu.dh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00524494  6681faff7f             +cmp dx, 0x7fff
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32767 /*0x7fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00524499  751c                   -jne 0x5244b7
    if (!cpu.flags.zf)
    {
        goto L_0x005244b7;
    }
    // 0052449b  81780400000080         +cmp dword ptr [eax + 4], 0x80000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005244a2  750c                   -jne 0x5244b0
    if (!cpu.flags.zf)
    {
        goto L_0x005244b0;
    }
    // 005244a4  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005244a7  7507                   -jne 0x5244b0
    if (!cpu.flags.zf)
    {
        goto L_0x005244b0;
    }
    // 005244a9  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 005244ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005244b0:
    // 005244b0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 005244b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005244b7:
    // 005244b7  66f74008ff7f           +test word ptr [eax + 8], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) & 32767 /*0x7fff*/));
    // 005244bd  7516                   -jne 0x5244d5
    if (!cpu.flags.zf)
    {
        goto L_0x005244d5;
    }
    // 005244bf  83780400               +cmp dword ptr [eax + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005244c3  7509                   -jne 0x5244ce
    if (!cpu.flags.zf)
    {
        goto L_0x005244ce;
    }
    // 005244c5  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005244c8  7504                   -jne 0x5244ce
    if (!cpu.flags.zf)
    {
        goto L_0x005244ce;
    }
    // 005244ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005244cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005244ce:
    // 005244ce  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 005244d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005244d5:
    // 005244d5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005244da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_5244e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005244e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005244e1  ff153cf99e00           -call dword ptr [0x9ef93c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418492) /* 0x9ef93c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005244e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005244e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_5244f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005244f0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005244f2  e93931fcff             -jmp 0x4e7630
    return sub_4e7630(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_524500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524500  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00524504  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00524506  741f                   -je 0x524527
    if (cpu.flags.zf)
    {
        goto L_0x00524527;
    }
    // 00524508  68d0389f00             -push 0x9f38d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10434768 /*0x9f38d0*/;
    cpu.esp -= 4;
    // 0052450d  6828b95600             -push 0x56b928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683496 /*0x56b928*/;
    cpu.esp -= 4;
    // 00524512  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00524514  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524515  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524517  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524519  7403                   -je 0x52451e
    if (cpu.flags.zf)
    {
        goto L_0x0052451e;
    }
    // 0052451b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0052451e:
    // 0052451e  ff053c3d9f00           -inc dword ptr [0x9f3d3c]
    (app->getMemory<x86::reg32>(x86::reg32(10435900) /* 0x9f3d3c */))++;
    // 00524524  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00524527:
    // 00524527  a1d0389f00             -mov eax, dword ptr [0x9f38d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434768) /* 0x9f38d0 */);
    // 0052452c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052452d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052452f  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524532  8b0d3c3d9f00           -mov ecx, dword ptr [0x9f3d3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10435900) /* 0x9f3d3c */);
    // 00524538  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052453a  41                     -inc ecx
    (cpu.ecx)++;
    // 0052453b  8915d0389f00           -mov dword ptr [0x9f38d0], edx
    app->getMemory<x86::reg32>(x86::reg32(10434768) /* 0x9f38d0 */) = cpu.edx;
    // 00524541  890d3c3d9f00           -mov dword ptr [0x9f3d3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10435900) /* 0x9f3d3c */) = cpu.ecx;
    // 00524547  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_524550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524550  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00524555  741b                   -je 0x524572
    if (cpu.flags.zf)
    {
        goto L_0x00524572;
    }
    // 00524557  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524558  8b1d80445600           -mov ebx, dword ptr [0x564480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 0052455e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052455f  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524565  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524566  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052456a  a380715600             -mov dword ptr [0x567180], eax
    app->getMemory<x86::reg32>(x86::reg32(5665152) /* 0x567180 */) = cpu.eax;
    // 0052456f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00524572:
    // 00524572  8b0d80445600           -mov ecx, dword ptr [0x564480]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00524578  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524579  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052457f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00524583  a380715600             -mov dword ptr [0x567180], eax
    app->getMemory<x86::reg32>(x86::reg32(5665152) /* 0x567180 */) = cpu.eax;
    // 00524588  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_5245a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 005245a0  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005245a4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005245a8  83fa03                 +cmp edx, 3
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
    // 005245ab  7710                   -ja 0x5245bd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x005245bd;
    }
    // 005245ad  ff24958c455200         -jmp dword ptr [edx*4 + 0x52458c]
    cpu.ip = app->getMemory<x86::reg32>(5391756 + cpu.edx * 4); goto dynamic_jump;
  case 0x005245b4:
    // 005245b4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005245b5  e856caedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005245ba  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005245bd:
    // 005245bd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x005245c0:
    // 005245c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005245c1  e82ac3fbff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 005245c6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005245c9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x005245cc:
    // 005245cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005245cd  e8eeb0fbff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 005245d2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005245d5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x005245d8:
    // 005245d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005245d9  2eff159c455300         -call dword ptr cs:[0x53459c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457308) /* 0x53459c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005245e0  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_5245f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005245f0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005245f4  83f801                 +cmp eax, 1
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
    // 005245f7  7210                   -jb 0x524609
    if (cpu.flags.cf)
    {
        goto L_0x00524609;
    }
    // 005245f9  760e                   -jbe 0x524609
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00524609;
    }
    // 005245fb  83f802                 +cmp eax, 2
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
    // 005245fe  7509                   -jne 0x524609
    if (!cpu.flags.zf)
    {
        goto L_0x00524609;
    }
    // 00524600  833d8471560000         +cmp dword ptr [0x567184], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665156) /* 0x567184 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524607  7503                   -jne 0x52460c
    if (!cpu.flags.zf)
    {
        goto L_0x0052460c;
    }
L_0x00524609:
    // 00524609  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0052460c:
    // 0052460c  ff1584715600           -call dword ptr [0x567184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5665156) /* 0x567184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524612  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_524620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524620  90                     -nop 
    ;
    // 00524621  90                     -nop 
    ;
    // 00524622  90                     -nop 
    ;
    // 00524623  90                     -nop 
    ;
    // 00524624  90                     -nop 
    ;
    // 00524625  90                     -nop 
    ;
    // 00524626  90                     -nop 
    ;
    // 00524627  90                     -nop 
    ;
    // 00524628  90                     -nop 
    ;
    // 00524629  90                     -nop 
    ;
    // 0052462a  90                     -nop 
    ;
    // 0052462b  90                     -nop 
    ;
    // 0052462c  90                     -nop 
    ;
    // 0052462d  90                     -nop 
    ;
    // 0052462e  90                     -nop 
    ;
    // 0052462f  90                     -nop 
    ;
    // 00524630  90                     -nop 
    ;
    // 00524631  90                     -nop 
    ;
    // 00524632  90                     -nop 
    ;
    // 00524633  90                     -nop 
    ;
    // 00524634  90                     -nop 
    ;
    // 00524635  90                     -nop 
    ;
    // 00524636  90                     -nop 
    ;
    // 00524637  90                     -nop 
    ;
    // 00524638  90                     -nop 
    ;
    // 00524639  90                     -nop 
    ;
    // 0052463a  90                     -nop 
    ;
    // 0052463b  90                     -nop 
    ;
    // 0052463c  90                     -nop 
    ;
    // 0052463d  90                     -nop 
    ;
    // 0052463e  90                     -nop 
    ;
    // 0052463f  90                     -nop 
    ;
    // 00524640  90                     -nop 
    ;
    // 00524641  90                     -nop 
    ;
    // 00524642  90                     -nop 
    ;
    // 00524643  90                     -nop 
    ;
    // 00524644  90                     -nop 
    ;
    // 00524645  90                     -nop 
    ;
    // 00524646  90                     -nop 
    ;
    // 00524647  90                     -nop 
    ;
    // 00524648  90                     -nop 
    ;
    // 00524649  90                     -nop 
    ;
    // 0052464a  90                     -nop 
    ;
    // 0052464b  90                     -nop 
    ;
    // 0052464c  90                     -nop 
    ;
    // 0052464d  90                     -nop 
    ;
    // 0052464e  90                     -nop 
    ;
    // 0052464f  90                     -nop 
    ;
    // 00524650  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524651  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00524653  8a25f0af5600           -mov ah, byte ptr [0x56aff0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
    // 00524659  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0052465b  7432                   -je 0x52468f
    if (cpu.flags.zf)
    {
        goto L_0x0052468f;
    }
    // 0052465d  90                     -nop 
    ;
    // 0052465e  90                     -nop 
    ;
    // 0052465f  90                     -nop 
    ;
    // 00524660  90                     -nop 
    ;
    // 00524661  833d3cf99e0000         +cmp dword ptr [0x9ef93c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10418492) /* 0x9ef93c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524668  740a                   -je 0x524674
    if (cpu.flags.zf)
    {
        goto L_0x00524674;
    }
    // 0052466a  b8e0445200             -mov eax, 0x5244e0
    cpu.eax = 5391584 /*0x5244e0*/;
    // 0052466f  e86c2ffcff             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
L_0x00524674:
    // 00524674  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524675  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524676  ff157cf99e00           -call dword ptr [0x9ef97c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418556) /* 0x9ef97c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052467c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052467e  7405                   -je 0x524685
    if (cpu.flags.zf)
    {
        goto L_0x00524685;
    }
    // 00524680  e81b94faff             -call 0x4cdaa0
    cpu.esp -= 4;
    sub_4cdaa0(app, cpu);
    if (cpu.terminate) return;
L_0x00524685:
    // 00524685  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00524687  8835f0af5600           -mov byte ptr [0x56aff0], dh
    app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */) = cpu.dh;
    // 0052468d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052468e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052468f:
    // 0052468f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00524691  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524692  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_524650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00524650;
    // 00524620  90                     -nop 
    ;
    // 00524621  90                     -nop 
    ;
    // 00524622  90                     -nop 
    ;
    // 00524623  90                     -nop 
    ;
    // 00524624  90                     -nop 
    ;
    // 00524625  90                     -nop 
    ;
    // 00524626  90                     -nop 
    ;
    // 00524627  90                     -nop 
    ;
    // 00524628  90                     -nop 
    ;
    // 00524629  90                     -nop 
    ;
    // 0052462a  90                     -nop 
    ;
    // 0052462b  90                     -nop 
    ;
    // 0052462c  90                     -nop 
    ;
    // 0052462d  90                     -nop 
    ;
    // 0052462e  90                     -nop 
    ;
    // 0052462f  90                     -nop 
    ;
    // 00524630  90                     -nop 
    ;
    // 00524631  90                     -nop 
    ;
    // 00524632  90                     -nop 
    ;
    // 00524633  90                     -nop 
    ;
    // 00524634  90                     -nop 
    ;
    // 00524635  90                     -nop 
    ;
    // 00524636  90                     -nop 
    ;
    // 00524637  90                     -nop 
    ;
    // 00524638  90                     -nop 
    ;
    // 00524639  90                     -nop 
    ;
    // 0052463a  90                     -nop 
    ;
    // 0052463b  90                     -nop 
    ;
    // 0052463c  90                     -nop 
    ;
    // 0052463d  90                     -nop 
    ;
    // 0052463e  90                     -nop 
    ;
    // 0052463f  90                     -nop 
    ;
    // 00524640  90                     -nop 
    ;
    // 00524641  90                     -nop 
    ;
    // 00524642  90                     -nop 
    ;
    // 00524643  90                     -nop 
    ;
    // 00524644  90                     -nop 
    ;
    // 00524645  90                     -nop 
    ;
    // 00524646  90                     -nop 
    ;
    // 00524647  90                     -nop 
    ;
    // 00524648  90                     -nop 
    ;
    // 00524649  90                     -nop 
    ;
    // 0052464a  90                     -nop 
    ;
    // 0052464b  90                     -nop 
    ;
    // 0052464c  90                     -nop 
    ;
    // 0052464d  90                     -nop 
    ;
    // 0052464e  90                     -nop 
    ;
    // 0052464f  90                     -nop 
    ;
L_entry_0x00524650:
    // 00524650  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524651  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00524653  8a25f0af5600           -mov ah, byte ptr [0x56aff0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
    // 00524659  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0052465b  7432                   -je 0x52468f
    if (cpu.flags.zf)
    {
        goto L_0x0052468f;
    }
    // 0052465d  90                     -nop 
    ;
    // 0052465e  90                     -nop 
    ;
    // 0052465f  90                     -nop 
    ;
    // 00524660  90                     -nop 
    ;
    // 00524661  833d3cf99e0000         +cmp dword ptr [0x9ef93c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10418492) /* 0x9ef93c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524668  740a                   -je 0x524674
    if (cpu.flags.zf)
    {
        goto L_0x00524674;
    }
    // 0052466a  b8e0445200             -mov eax, 0x5244e0
    cpu.eax = 5391584 /*0x5244e0*/;
    // 0052466f  e86c2ffcff             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
L_0x00524674:
    // 00524674  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524675  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524676  ff157cf99e00           -call dword ptr [0x9ef97c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418556) /* 0x9ef97c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052467c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052467e  7405                   -je 0x524685
    if (cpu.flags.zf)
    {
        goto L_0x00524685;
    }
    // 00524680  e81b94faff             -call 0x4cdaa0
    cpu.esp -= 4;
    sub_4cdaa0(app, cpu);
    if (cpu.terminate) return;
L_0x00524685:
    // 00524685  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00524687  8835f0af5600           -mov byte ptr [0x56aff0], dh
    app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */) = cpu.dh;
    // 0052468d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052468e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052468f:
    // 0052468f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00524691  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524692  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_5246a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005246a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005246a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005246a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005246a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005246a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005246a6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005246ab  8b0d84435600           -mov ecx, dword ptr [0x564384]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 005246b1  8b1588435600           -mov edx, dword ptr [0x564388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 005246b7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005246b9  7505                   -jne 0x5246c0
    if (!cpu.flags.zf)
    {
        goto L_0x005246c0;
    }
    // 005246bb  b980020000             -mov ecx, 0x280
    cpu.ecx = 640 /*0x280*/;
L_0x005246c0:
    // 005246c0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005246c2  7505                   -jne 0x5246c9
    if (!cpu.flags.zf)
    {
        goto L_0x005246c9;
    }
    // 005246c4  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
L_0x005246c9:
    // 005246c9  803df0af560000         +cmp byte ptr [0x56aff0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005246d0  7528                   -jne 0x5246fa
    if (!cpu.flags.zf)
    {
        goto L_0x005246fa;
    }
    // 005246d2  833d8044560000         +cmp dword ptr [0x564480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005246d9  742b                   -je 0x524706
    if (cpu.flags.zf)
    {
        goto L_0x00524706;
    }
L_0x005246db:
    // 005246db  833d243d9f0000         +cmp dword ptr [0x9f3d24], 0
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
    // 005246e2  7512                   -jne 0x5246f6
    if (!cpu.flags.zf)
    {
        goto L_0x005246f6;
    }
    // 005246e4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005246e6  752a                   -jne 0x524712
    if (!cpu.flags.zf)
    {
        goto L_0x00524712;
    }
    // 005246e8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x005246ed:
    // 005246ed  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005246ef  e8cc8ffaff             -call 0x4cd6c0
    cpu.esp -= 4;
    sub_4cd6c0(app, cpu);
    if (cpu.terminate) return;
    // 005246f4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x005246f6:
    // 005246f6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005246f8  751c                   -jne 0x524716
    if (!cpu.flags.zf)
    {
        goto L_0x00524716;
    }
L_0x005246fa:
    // 005246fa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005246fc  a0f0af5600             -mov al, byte ptr [0x56aff0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
    // 00524701  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524702  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524703  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524704  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524705  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00524706:
    // 00524706  e8d56bfcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0052470b  a380445600             -mov dword ptr [0x564480], eax
    app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */) = cpu.eax;
    // 00524710  ebc9                   -jmp 0x5246db
    goto L_0x005246db;
L_0x00524712:
    // 00524712  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00524714  ebd7                   -jmp 0x5246ed
    goto L_0x005246ed;
L_0x00524716:
    // 00524716  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524717  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 00524719  ff156cf99e00           -call dword ptr [0x9ef96c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052471f  e84c73fcff             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 00524724  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524725  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00524727  ff156cf99e00           -call dword ptr [0x9ef96c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052472d  68d0af5600             -push 0x56afd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5681104 /*0x56afd0*/;
    cpu.esp -= 4;
    // 00524732  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00524734  ff156cf99e00           -call dword ptr [0x9ef96c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052473a  ff1578f99e00           -call dword ptr [0x9ef978]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418552) /* 0x9ef978 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524740  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524742  7456                   -je 0x52479a
    if (cpu.flags.zf)
    {
        return sub_52479a(app, cpu);
    }
    // 00524744  833d3cf99e0000         +cmp dword ptr [0x9ef93c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10418492) /* 0x9ef93c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052474b  753a                   -jne 0x524787
    if (!cpu.flags.zf)
    {
        return sub_524787(app, cpu);
    }
    // 0052474d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052474f  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00524751  a2f0af5600             -mov byte ptr [0x56aff0], al
    app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */) = cpu.al;
    // 00524756  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524757  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524758  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524759  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052475a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52474d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0052474d;
    // 005246a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005246a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005246a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005246a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005246a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005246a6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005246ab  8b0d84435600           -mov ecx, dword ptr [0x564384]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 005246b1  8b1588435600           -mov edx, dword ptr [0x564388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 005246b7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005246b9  7505                   -jne 0x5246c0
    if (!cpu.flags.zf)
    {
        goto L_0x005246c0;
    }
    // 005246bb  b980020000             -mov ecx, 0x280
    cpu.ecx = 640 /*0x280*/;
L_0x005246c0:
    // 005246c0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005246c2  7505                   -jne 0x5246c9
    if (!cpu.flags.zf)
    {
        goto L_0x005246c9;
    }
    // 005246c4  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
L_0x005246c9:
    // 005246c9  803df0af560000         +cmp byte ptr [0x56aff0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005246d0  7528                   -jne 0x5246fa
    if (!cpu.flags.zf)
    {
        goto L_0x005246fa;
    }
    // 005246d2  833d8044560000         +cmp dword ptr [0x564480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005246d9  742b                   -je 0x524706
    if (cpu.flags.zf)
    {
        goto L_0x00524706;
    }
L_0x005246db:
    // 005246db  833d243d9f0000         +cmp dword ptr [0x9f3d24], 0
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
    // 005246e2  7512                   -jne 0x5246f6
    if (!cpu.flags.zf)
    {
        goto L_0x005246f6;
    }
    // 005246e4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005246e6  752a                   -jne 0x524712
    if (!cpu.flags.zf)
    {
        goto L_0x00524712;
    }
    // 005246e8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x005246ed:
    // 005246ed  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005246ef  e8cc8ffaff             -call 0x4cd6c0
    cpu.esp -= 4;
    sub_4cd6c0(app, cpu);
    if (cpu.terminate) return;
    // 005246f4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x005246f6:
    // 005246f6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005246f8  751c                   -jne 0x524716
    if (!cpu.flags.zf)
    {
        goto L_0x00524716;
    }
L_0x005246fa:
    // 005246fa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005246fc  a0f0af5600             -mov al, byte ptr [0x56aff0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
    // 00524701  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524702  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524703  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524704  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524705  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00524706:
    // 00524706  e8d56bfcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0052470b  a380445600             -mov dword ptr [0x564480], eax
    app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */) = cpu.eax;
    // 00524710  ebc9                   -jmp 0x5246db
    goto L_0x005246db;
L_0x00524712:
    // 00524712  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00524714  ebd7                   -jmp 0x5246ed
    goto L_0x005246ed;
L_0x00524716:
    // 00524716  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524717  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 00524719  ff156cf99e00           -call dword ptr [0x9ef96c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052471f  e84c73fcff             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 00524724  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524725  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00524727  ff156cf99e00           -call dword ptr [0x9ef96c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052472d  68d0af5600             -push 0x56afd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5681104 /*0x56afd0*/;
    cpu.esp -= 4;
    // 00524732  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00524734  ff156cf99e00           -call dword ptr [0x9ef96c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052473a  ff1578f99e00           -call dword ptr [0x9ef978]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418552) /* 0x9ef978 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524740  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524742  7456                   -je 0x52479a
    if (cpu.flags.zf)
    {
        return sub_52479a(app, cpu);
    }
    // 00524744  833d3cf99e0000         +cmp dword ptr [0x9ef93c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10418492) /* 0x9ef93c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052474b  753a                   -jne 0x524787
    if (!cpu.flags.zf)
    {
        return sub_524787(app, cpu);
    }
L_entry_0x0052474d:
    // 0052474d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052474f  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00524751  a2f0af5600             -mov byte ptr [0x56aff0], al
    app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */) = cpu.al;
    // 00524756  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524757  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524758  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524759  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052475a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52475c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052475c  90                     -nop 
    ;
    // 0052475d  90                     -nop 
    ;
    // 0052475e  90                     -nop 
    ;
    // 0052475f  90                     -nop 
    ;
    // 00524760  90                     -nop 
    ;
    // 00524761  90                     -nop 
    ;
    // 00524762  90                     -nop 
    ;
    // 00524763  90                     -nop 
    ;
    // 00524764  90                     -nop 
    ;
    // 00524765  90                     -nop 
    ;
    // 00524766  90                     -nop 
    ;
    // 00524767  90                     -nop 
    ;
    // 00524768  90                     -nop 
    ;
    // 00524769  90                     -nop 
    ;
    // 0052476a  90                     -nop 
    ;
    // 0052476b  90                     -nop 
    ;
    // 0052476c  90                     -nop 
    ;
    // 0052476d  90                     -nop 
    ;
    // 0052476e  90                     -nop 
    ;
    // 0052476f  90                     -nop 
    ;
    // 00524770  90                     -nop 
    ;
    // 00524771  90                     -nop 
    ;
    // 00524772  90                     -nop 
    ;
    // 00524773  90                     -nop 
    ;
    // 00524774  90                     -nop 
    ;
    // 00524775  90                     -nop 
    ;
    // 00524776  90                     -nop 
    ;
    // 00524777  90                     -nop 
    ;
    // 00524778  90                     -nop 
    ;
    // 00524779  90                     -nop 
    ;
    // 0052477a  90                     -nop 
    ;
    // 0052477b  90                     -nop 
    ;
    // 0052477c  90                     -nop 
    ;
    // 0052477d  90                     -nop 
    ;
    // 0052477e  90                     -nop 
    ;
    // 0052477f  90                     -nop 
    ;
    // 00524780  90                     -nop 
    ;
    // 00524781  90                     -nop 
    ;
    // 00524782  90                     -nop 
    ;
    // 00524783  90                     -nop 
    ;
    // 00524784  90                     -nop 
    ;
    // 00524785  90                     -nop 
    ;
    // 00524786  90                     -nop 
    ;
    // 00524787  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052478c  b8e0445200             -mov eax, 0x5244e0
    cpu.eax = 5391584 /*0x5244e0*/;
    // 00524791  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00524793  e8882dfcff             -call 0x4e7520
    cpu.esp -= 4;
    sub_4e7520(app, cpu);
    if (cpu.terminate) return;
    // 00524798  ebb3                   -jmp 0x52474d
    return sub_52474d(app, cpu);
}

/* align: skip  */
void Application::sub_524787(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00524787;
    // 0052475c  90                     -nop 
    ;
    // 0052475d  90                     -nop 
    ;
    // 0052475e  90                     -nop 
    ;
    // 0052475f  90                     -nop 
    ;
    // 00524760  90                     -nop 
    ;
    // 00524761  90                     -nop 
    ;
    // 00524762  90                     -nop 
    ;
    // 00524763  90                     -nop 
    ;
    // 00524764  90                     -nop 
    ;
    // 00524765  90                     -nop 
    ;
    // 00524766  90                     -nop 
    ;
    // 00524767  90                     -nop 
    ;
    // 00524768  90                     -nop 
    ;
    // 00524769  90                     -nop 
    ;
    // 0052476a  90                     -nop 
    ;
    // 0052476b  90                     -nop 
    ;
    // 0052476c  90                     -nop 
    ;
    // 0052476d  90                     -nop 
    ;
    // 0052476e  90                     -nop 
    ;
    // 0052476f  90                     -nop 
    ;
    // 00524770  90                     -nop 
    ;
    // 00524771  90                     -nop 
    ;
    // 00524772  90                     -nop 
    ;
    // 00524773  90                     -nop 
    ;
    // 00524774  90                     -nop 
    ;
    // 00524775  90                     -nop 
    ;
    // 00524776  90                     -nop 
    ;
    // 00524777  90                     -nop 
    ;
    // 00524778  90                     -nop 
    ;
    // 00524779  90                     -nop 
    ;
    // 0052477a  90                     -nop 
    ;
    // 0052477b  90                     -nop 
    ;
    // 0052477c  90                     -nop 
    ;
    // 0052477d  90                     -nop 
    ;
    // 0052477e  90                     -nop 
    ;
    // 0052477f  90                     -nop 
    ;
    // 00524780  90                     -nop 
    ;
    // 00524781  90                     -nop 
    ;
    // 00524782  90                     -nop 
    ;
    // 00524783  90                     -nop 
    ;
    // 00524784  90                     -nop 
    ;
    // 00524785  90                     -nop 
    ;
    // 00524786  90                     -nop 
    ;
L_entry_0x00524787:
    // 00524787  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052478c  b8e0445200             -mov eax, 0x5244e0
    cpu.eax = 5391584 /*0x5244e0*/;
    // 00524791  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00524793  e8882dfcff             -call 0x4e7520
    cpu.esp -= 4;
    sub_4e7520(app, cpu);
    if (cpu.terminate) return;
    // 00524798  ebb3                   -jmp 0x52474d
    return sub_52474d(app, cpu);
}

/* align: skip  */
void Application::sub_52479a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052479a  e80193faff             -call 0x4cdaa0
    cpu.esp -= 4;
    sub_4cdaa0(app, cpu);
    if (cpu.terminate) return;
    // 0052479f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005247a1  a0f0af5600             -mov al, byte ptr [0x56aff0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
    // 005247a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005247a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005247a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005247a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005247aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5247ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005247ac  90                     -nop 
    ;
    // 005247ad  90                     -nop 
    ;
    // 005247ae  90                     -nop 
    ;
    // 005247af  90                     -nop 
    ;
    // 005247b0  90                     -nop 
    ;
    // 005247b1  90                     -nop 
    ;
    // 005247b2  90                     -nop 
    ;
    // 005247b3  90                     -nop 
    ;
    // 005247b4  90                     -nop 
    ;
    // 005247b5  90                     -nop 
    ;
    // 005247b6  90                     -nop 
    ;
    // 005247b7  90                     -nop 
    ;
    // 005247b8  90                     -nop 
    ;
    // 005247b9  90                     -nop 
    ;
    // 005247ba  90                     -nop 
    ;
    // 005247bb  90                     -nop 
    ;
    // 005247bc  90                     -nop 
    ;
    // 005247bd  90                     -nop 
    ;
    // 005247be  90                     -nop 
    ;
    // 005247bf  90                     -nop 
    ;
    // 005247c0  90                     -nop 
    ;
    // 005247c1  90                     -nop 
    ;
    // 005247c2  90                     -nop 
    ;
    // 005247c3  90                     -nop 
    ;
    // 005247c4  90                     -nop 
    ;
    // 005247c5  90                     -nop 
    ;
    // 005247c6  90                     -nop 
    ;
    // 005247c7  90                     -nop 
    ;
    // 005247c8  90                     -nop 
    ;
    // 005247c9  90                     -nop 
    ;
    // 005247ca  90                     -nop 
    ;
    // 005247cb  90                     -nop 
    ;
    // 005247cc  90                     -nop 
    ;
    // 005247cd  90                     -nop 
    ;
    // 005247ce  90                     -nop 
    ;
    // 005247cf  90                     -nop 
    ;
    // 005247d0  90                     -nop 
    ;
    // 005247d1  90                     -nop 
    ;
    // 005247d2  90                     -nop 
    ;
    // 005247d3  90                     -nop 
    ;
    // 005247d4  90                     -nop 
    ;
    // 005247d5  90                     -nop 
    ;
    // 005247d6  90                     -nop 
    ;
    // 005247d7  90                     -nop 
    ;
    // 005247d8  90                     -nop 
    ;
    // 005247d9  90                     -nop 
    ;
    // 005247da  90                     -nop 
    ;
    // 005247db  90                     -nop 
    ;
    // 005247dc  90                     -nop 
    ;
    // 005247dd  90                     -nop 
    ;
    // 005247de  90                     -nop 
    ;
    // 005247df  90                     -nop 
    ;
    // 005247e0  90                     -nop 
    ;
    // 005247e1  90                     -nop 
    ;
    // 005247e2  90                     -nop 
    ;
    // 005247e3  90                     -nop 
    ;
    // 005247e4  90                     -nop 
    ;
    // 005247e5  90                     -nop 
    ;
    // 005247e6  90                     -nop 
    ;
    // 005247e7  90                     -nop 
    ;
    // 005247e8  90                     -nop 
    ;
    // 005247e9  90                     -nop 
    ;
    // 005247ea  90                     -nop 
    ;
    // 005247eb  90                     -nop 
    ;
    // 005247ec  90                     -nop 
    ;
    // 005247ed  90                     -nop 
    ;
    // 005247ee  90                     -nop 
    ;
    // 005247ef  90                     -nop 
    ;
    // 005247f0  90                     -nop 
    ;
    // 005247f1  90                     -nop 
    ;
    // 005247f2  90                     -nop 
    ;
    // 005247f3  90                     -nop 
    ;
    // 005247f4  90                     -nop 
    ;
    // 005247f5  90                     -nop 
    ;
    // 005247f6  90                     -nop 
    ;
    // 005247f7  90                     -nop 
    ;
    // 005247f8  90                     -nop 
    ;
    // 005247f9  90                     -nop 
    ;
    // 005247fa  90                     -nop 
    ;
    // 005247fb  90                     -nop 
    ;
    // 005247fc  90                     -nop 
    ;
    // 005247fd  90                     -nop 
    ;
    // 005247fe  90                     -nop 
    ;
    // 005247ff  90                     -nop 
    ;
    // 00524800  90                     -nop 
    ;
    // 00524801  90                     -nop 
    ;
    // 00524802  90                     -nop 
    ;
    // 00524803  90                     -nop 
    ;
    // 00524804  90                     -nop 
    ;
    // 00524805  90                     -nop 
    ;
    // 00524806  90                     -nop 
    ;
    // 00524807  90                     -nop 
    ;
    // 00524808  90                     -nop 
    ;
    // 00524809  90                     -nop 
    ;
    // 0052480a  90                     -nop 
    ;
    // 0052480b  90                     -nop 
    ;
    // 0052480c  90                     -nop 
    ;
    // 0052480d  90                     -nop 
    ;
    // 0052480e  90                     -nop 
    ;
    // 0052480f  90                     -nop 
    ;
    // 00524810  90                     -nop 
    ;
    // 00524811  90                     -nop 
    ;
    // 00524812  90                     -nop 
    ;
    // 00524813  90                     -nop 
    ;
    // 00524814  90                     -nop 
    ;
    // 00524815  90                     -nop 
    ;
    // 00524816  90                     -nop 
    ;
    // 00524817  90                     -nop 
    ;
    // 00524818  90                     -nop 
    ;
    // 00524819  90                     -nop 
    ;
    // 0052481a  90                     -nop 
    ;
    // 0052481b  90                     -nop 
    ;
    // 0052481c  90                     -nop 
    ;
    // 0052481d  90                     -nop 
    ;
    // 0052481e  90                     -nop 
    ;
    // 0052481f  90                     -nop 
    ;
    // 00524820  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524821  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524822  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524823  ff1554f99e00           -call dword ptr [0x9ef954]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418516) /* 0x9ef954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524829  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052482b  a32082a100             -mov dword ptr [0xa18220], eax
    app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */) = cpu.eax;
    // 00524830  8915f4af5600           -mov dword ptr [0x56aff4], edx
    app->getMemory<x86::reg32>(x86::reg32(5681140) /* 0x56aff4 */) = cpu.edx;
    // 00524836  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00524838  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052483b  a31c505600             -mov dword ptr [0x56501c], eax
    app->getMemory<x86::reg32>(x86::reg32(5656604) /* 0x56501c */) = cpu.eax;
    // 00524840  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524845  a3f84f5600             -mov dword ptr [0x564ff8], eax
    app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */) = cpu.eax;
    // 0052484a  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 0052484f  b9444e4957             -mov ecx, 0x57494e44
    cpu.ecx = 1464421956 /*0x57494e44*/;
    // 00524854  a3fc4f5600             -mov dword ptr [0x564ffc], eax
    app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */) = cpu.eax;
    // 00524859  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 0052485e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00524860  a308505600             -mov dword ptr [0x565008], eax
    app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */) = cpu.eax;
    // 00524865  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 0052486a  890df44f5600           -mov dword ptr [0x564ff4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5656564) /* 0x564ff4 */) = cpu.ecx;
    // 00524870  a30c505600             -mov dword ptr [0x56500c], eax
    app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */) = cpu.eax;
    // 00524875  a08c435600             -mov al, byte ptr [0x56438c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5653388) /* 0x56438c */);
    // 0052487a  891d00505600           -mov dword ptr [0x565000], ebx
    app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */) = cpu.ebx;
    // 00524880  a210505600             -mov byte ptr [0x565010], al
    app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */) = cpu.al;
    // 00524885  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 00524887  891d04505600           -mov dword ptr [0x565004], ebx
    app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */) = cpu.ebx;
    // 0052488d  882512505600           -mov byte ptr [0x565012], ah
    app->getMemory<x86::reg8>(x86::reg32(5656594) /* 0x565012 */) = cpu.ah;
    // 00524893  a18c435600             -mov eax, dword ptr [0x56438c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 00524898  891514505600           -mov dword ptr [0x565014], edx
    app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */) = cpu.edx;
    // 0052489e  e82d50feff             -call 0x5098d0
    cpu.esp -= 4;
    sub_5098d0(app, cpu);
    if (cpu.terminate) return;
    // 005248a3  8b0d88435600           -mov ecx, dword ptr [0x564388]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 005248a9  8b151c505600           -mov edx, dword ptr [0x56501c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656604) /* 0x56501c */);
    // 005248af  a211505600             -mov byte ptr [0x565011], al
    app->getMemory<x86::reg8>(x86::reg32(5656593) /* 0x565011 */) = cpu.al;
    // 005248b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005248b6  891d28505600           -mov dword ptr [0x565028], ebx
    app->getMemory<x86::reg32>(x86::reg32(5656616) /* 0x565028 */) = cpu.ebx;
    // 005248bc  e86f51feff             -call 0x509a30
    cpu.esp -= 4;
    sub_509a30(app, cpu);
    if (cpu.terminate) return;
    // 005248c1  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 005248c6  8b0d84435600           -mov ecx, dword ptr [0x564384]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 005248cc  8b158c435600           -mov edx, dword ptr [0x56438c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 005248d2  a320505600             -mov dword ptr [0x565020], eax
    app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */) = cpu.eax;
    // 005248d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005248d9  e85251feff             -call 0x509a30
    cpu.esp -= 4;
    sub_509a30(app, cpu);
    if (cpu.terminate) return;
    // 005248de  a324505600             -mov dword ptr [0x565024], eax
    app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */) = cpu.eax;
    // 005248e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005248e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005248e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005248e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_5248f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005248f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005248f1  8b152082a100           -mov edx, dword ptr [0xa18220]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */);
    // 005248f7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005248f9  7502                   -jne 0x5248fd
    if (!cpu.flags.zf)
    {
        goto L_0x005248fd;
    }
    // 005248fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005248fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005248fd:
    // 005248fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005248fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005248ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524900  ff155cf99e00           -call dword ptr [0x9ef95c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418524) /* 0x9ef95c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524906  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00524908  a120505600             -mov eax, dword ptr [0x565020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0052490d  891d2082a100           -mov dword ptr [0xa18220], ebx
    app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */) = cpu.ebx;
    // 00524913  e8f851feff             -call 0x509b10
    cpu.esp -= 4;
    sub_509b10(app, cpu);
    if (cpu.terminate) return;
    // 00524918  a124505600             -mov eax, dword ptr [0x565024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 0052491d  e8ee51feff             -call 0x509b10
    cpu.esp -= 4;
    sub_509b10(app, cpu);
    if (cpu.terminate) return;
    // 00524922  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524923  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524924  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524925  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_524930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524930  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524931  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00524933  e8e863fcff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 00524938  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0052493b  e870e3fcff             -call 0x4f2cb0
    cpu.esp -= 4;
    sub_4f2cb0(app, cpu);
    if (cpu.terminate) return;
    // 00524940  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524941  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_524950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524950  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524951  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00524953  e8c863fcff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 00524958  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0052495b  e860c0fcff             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 00524960  e82b64fcff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00524965  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524966  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_524970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524970  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524971  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524972  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00524973  81ec44010000           -sub esp, 0x144
    (cpu.esp) -= x86::reg32(x86::sreg32(324 /*0x144*/));
    // 00524979  8bbc2458010000         -mov edi, dword ptr [esp + 0x158]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(344) /* 0x158 */);
    // 00524980  89842430010000         -mov dword ptr [esp + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 00524987  89942440010000         -mov dword ptr [esp + 0x140], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */) = cpu.edx;
    // 0052498e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00524990  898c243c010000         -mov dword ptr [esp + 0x13c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */) = cpu.ecx;
    // 00524997  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052499c  e85ba6fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 005249a1  89842434010000         -mov dword ptr [esp + 0x134], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */) = cpu.eax;
    // 005249a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005249aa  8b942454010000         -mov edx, dword ptr [esp + 0x154]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(340) /* 0x154 */);
    // 005249b1  e846a6fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 005249b6  8b84243c010000         -mov eax, dword ptr [esp + 0x13c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 005249bd  8b0df4435600           -mov ecx, dword ptr [0x5643f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 005249c3  8b1d8c435600           -mov ebx, dword ptr [0x56438c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 005249c9  e8c2a7fcff             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 005249ce  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005249d0  89842438010000         -mov dword ptr [esp + 0x138], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */) = cpu.eax;
    // 005249d7  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 005249de  e8edfcfcff             -call 0x4f46d0
    cpu.esp -= 4;
    sub_4f46d0(app, cpu);
    if (cpu.terminate) return;
    // 005249e3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005249e5  e856fdfcff             -call 0x4f4740
    cpu.esp -= 4;
    sub_4f4740(app, cpu);
    if (cpu.terminate) return;
    // 005249ea  b8e4625600             -mov eax, 0x5662e4
    cpu.eax = 5661412 /*0x5662e4*/;
    // 005249ef  e82cabfcff             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 005249f4  8b842454010000         -mov eax, dword ptr [esp + 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(340) /* 0x154 */);
    // 005249fb  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 005249fd  8b8c243c010000         -mov ecx, dword ptr [esp + 0x13c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 00524a04  89842428010000         -mov dword ptr [esp + 0x128], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */) = cpu.eax;
    // 00524a0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524a0c  8b842444010000         -mov eax, dword ptr [esp + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 00524a13  8b942444010000         -mov edx, dword ptr [esp + 0x144]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 00524a1a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00524a1c  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00524a1e  89842430010000         -mov dword ptr [esp + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 00524a25  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00524a27  b82c505600             -mov eax, 0x56502c
    cpu.eax = 5656620 /*0x56502c*/;
    // 00524a2c  e88f6c0000             -call 0x52b6c0
    cpu.esp -= 4;
    sub_52b6c0(app, cpu);
    if (cpu.terminate) return;
    // 00524a31  ff1560445600           -call dword ptr [0x564460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653600) /* 0x564460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524a37  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524a39  8b942440010000         -mov edx, dword ptr [esp + 0x140]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 00524a40  e85b63fcff             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00524a45  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00524a47  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524a49  8b8c2454010000         -mov ecx, dword ptr [esp + 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(340) /* 0x154 */);
    // 00524a50  e8dbfeffff             -call 0x524930
    cpu.esp -= 4;
    sub_524930(app, cpu);
    if (cpu.terminate) return;
    // 00524a55  e8c662fcff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 00524a5a  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 00524a5f  8b9c243c010000         -mov ebx, dword ptr [esp + 0x13c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 00524a66  e8f5acfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00524a6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524a6c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00524a6e  8b842444010000         -mov eax, dword ptr [esp + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 00524a75  e8c68afdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 00524a7a  b80000aaff             -mov eax, 0xffaa0000
    cpu.eax = 4289331200 /*0xffaa0000*/;
    // 00524a7f  8b8c2428010000         -mov ecx, dword ptr [esp + 0x128]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 00524a86  8b9c242c010000         -mov ebx, dword ptr [esp + 0x12c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 00524a8d  e8ceacfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00524a92  8d5504                 -lea edx, [ebp + 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00524a95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524a96  83e904                 -sub ecx, 4
    (cpu.ecx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00524a99  8b842444010000         -mov eax, dword ptr [esp + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 00524aa0  83eb05                 -sub ebx, 5
    (cpu.ebx) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00524aa3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00524aa6  e8756c0000             -call 0x52b720
    cpu.esp -= 4;
    sub_52b720(app, cpu);
    if (cpu.terminate) return;
    // 00524aab  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00524ab0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524ab2  e8a9acfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00524ab7  e874adfcff             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00524abc  8b842430010000         -mov eax, dword ptr [esp + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 00524ac3  8d5509                 -lea edx, [ebp + 9]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(9) /* 0x9 */);
    // 00524ac6  e8956d0000             -call 0x52b860
    cpu.esp -= 4;
    sub_52b860(app, cpu);
    if (cpu.terminate) return;
    // 00524acb  ff1564445600           -call dword ptr [0x564464]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653604) /* 0x564464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524ad1  b82c505600             -mov eax, 0x56502c
    cpu.eax = 5656620 /*0x56502c*/;
    // 00524ad6  e8d56d0000             -call 0x52b8b0
    cpu.esp -= 4;
    sub_52b8b0(app, cpu);
    if (cpu.terminate) return;
    // 00524adb  e8b062fcff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
L_0x00524ae0:
    // 00524ae0  ff1568445600           -call dword ptr [0x564468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653608) /* 0x564468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524ae6  85f8                   +test eax, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edi));
    // 00524ae8  75f6                   -jne 0x524ae0
    if (!cpu.flags.zf)
    {
        goto L_0x00524ae0;
    }
L_0x00524aea:
    // 00524aea  e8e1b5fcff             -call 0x4f00d0
    cpu.esp -= 4;
    sub_4f00d0(app, cpu);
    if (cpu.terminate) return;
    // 00524aef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524af1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00524af3  ff1568445600           -call dword ptr [0x564468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653608) /* 0x564468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524af9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00524afb  21fe                   -and esi, edi
    cpu.esi &= x86::reg32(x86::sreg32(cpu.edi));
    // 00524afd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00524aff  0f8497000000           -je 0x524b9c
    if (cpu.flags.zf)
    {
        goto L_0x00524b9c;
    }
L_0x00524b05:
    // 00524b05  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00524b08  83e601                 -and esi, 1
    cpu.esi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00524b0b  83f979                 +cmp ecx, 0x79
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(121 /*0x79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524b0e  7505                   -jne 0x524b15
    if (!cpu.flags.zf)
    {
        goto L_0x00524b15;
    }
    // 00524b10  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00524b15:
    // 00524b15  8b842454010000         -mov eax, dword ptr [esp + 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(340) /* 0x154 */);
    // 00524b1c  8b8c2440010000         -mov ecx, dword ptr [esp + 0x140]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 00524b23  8b9c243c010000         -mov ebx, dword ptr [esp + 0x13c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 00524b2a  8b942440010000         -mov edx, dword ptr [esp + 0x140]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 00524b31  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00524b33  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00524b35  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524b36  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00524b38  b82c505600             -mov eax, 0x56502c
    cpu.eax = 5656620 /*0x56502c*/;
    // 00524b3d  e87e6b0000             -call 0x52b6c0
    cpu.esp -= 4;
    sub_52b6c0(app, cpu);
    if (cpu.terminate) return;
    // 00524b42  ff155c445600           -call dword ptr [0x56445c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653596) /* 0x56445c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524b48  8b942440010000         -mov edx, dword ptr [esp + 0x140]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 00524b4f  8b842438010000         -mov eax, dword ptr [esp + 0x138]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 00524b56  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00524b58  e8f3fdffff             -call 0x524950
    cpu.esp -= 4;
    sub_524950(app, cpu);
    if (cpu.terminate) return;
    // 00524b5d  ff1564445600           -call dword ptr [0x564464]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653604) /* 0x564464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524b63  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00524b65  e8f6fbfcff             -call 0x4f4760
    cpu.esp -= 4;
    sub_4f4760(app, cpu);
    if (cpu.terminate) return;
    // 00524b6a  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00524b71  e88afbfcff             -call 0x4f4700
    cpu.esp -= 4;
    sub_4f4700(app, cpu);
    if (cpu.terminate) return;
    // 00524b76  8b842438010000         -mov eax, dword ptr [esp + 0x138]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 00524b7d  e87eb3fcff             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
    // 00524b82  8b842434010000         -mov eax, dword ptr [esp + 0x134]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 00524b89  e86ea4fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 00524b8e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524b90  81c444010000           -add esp, 0x144
    (cpu.esp) += x86::reg32(x86::sreg32(324 /*0x144*/));
    // 00524b96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524b97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524b98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524b99  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00524b9c:
    // 00524b9c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00524b9e  0f8561ffffff           -jne 0x524b05
    if (!cpu.flags.zf)
    {
        goto L_0x00524b05;
    }
    // 00524ba4  e941ffffff             -jmp 0x524aea
    goto L_0x00524aea;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_524bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524bb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524bb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524bb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524bb3  833d6443560000         +cmp dword ptr [0x564364], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524bba  7410                   -je 0x524bcc
    if (cpu.flags.zf)
    {
        goto L_0x00524bcc;
    }
    // 00524bbc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00524bbe  e86dadfbff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 00524bc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524bc5  7442                   -je 0x524c09
    if (cpu.flags.zf)
    {
        goto L_0x00524c09;
    }
    // 00524bc7  e8c461fcff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
L_0x00524bcc:
    // 00524bcc  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524bd1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524bd3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00524bd6  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00524bd8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00524bda  8d58f8                 -lea ebx, [eax - 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00524bdd  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524be2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524be4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00524be7  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00524be9  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00524beb  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00524bed  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00524bef  8d50b0                 -lea edx, [eax - 0x50]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-80) /* -0x50 */);
    // 00524bf2  b9a0000000             -mov ecx, 0xa0
    cpu.ecx = 160 /*0xa0*/;
    // 00524bf7  b8741e5500             -mov eax, 0x551e74
    cpu.eax = 5578356 /*0x551e74*/;
    // 00524bfc  e86ffdffff             -call 0x524970
    cpu.esp -= 4;
    sub_524970(app, cpu);
    if (cpu.terminate) return;
    // 00524c01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524c03  7520                   -jne 0x524c25
    if (!cpu.flags.zf)
    {
        goto L_0x00524c25;
    }
    // 00524c05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00524c09:
    // 00524c09  8b0d80445600           -mov ecx, dword ptr [0x564480]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00524c0f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524c10  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524c16  8b1d80445600           -mov ebx, dword ptr [0x564480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00524c1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524c1d  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524c23  eba7                   -jmp 0x524bcc
    goto L_0x00524bcc;
L_0x00524c25:
    // 00524c25  e853defcff             -call 0x4f2a7d
    cpu.esp -= 4;
    sub_4f2a7d(app, cpu);
    if (cpu.terminate) return;
    // 00524c2a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c2d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_524c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524c32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524c33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524c34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00524c35  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 00524c3b  89842428010000         -mov dword ptr [esp + 0x128], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */) = cpu.eax;
    // 00524c42  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00524c44  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00524c49  e8aea3fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 00524c4e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00524c50  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00524c52  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 00524c57  e8a0a3fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 00524c5c  8b0df4435600           -mov ecx, dword ptr [0x5643f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 00524c62  8b1d8c435600           -mov ebx, dword ptr [0x56438c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 00524c68  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524c6d  e81ea5fcff             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 00524c72  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00524c74  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00524c7b  e850fafcff             -call 0x4f46d0
    cpu.esp -= 4;
    sub_4f46d0(app, cpu);
    if (cpu.terminate) return;
    // 00524c80  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00524c82  e8b9fafcff             -call 0x4f4740
    cpu.esp -= 4;
    sub_4f4740(app, cpu);
    if (cpu.terminate) return;
    // 00524c87  b8e4625600             -mov eax, 0x5662e4
    cpu.eax = 5661412 /*0x5662e4*/;
    // 00524c8c  e88fa8fcff             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 00524c91  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524c93  e80861fcff             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00524c98  8b1588435600           -mov edx, dword ptr [0x564388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524c9e  b82c505600             -mov eax, 0x56502c
    cpu.eax = 5656620 /*0x56502c*/;
    // 00524ca3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524ca4  8d5af6                 -lea ebx, [edx - 0xa]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-10) /* -0xa */);
    // 00524ca7  8b0d84435600           -mov ecx, dword ptr [0x564384]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524cad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524caf  e80c6a0000             -call 0x52b6c0
    cpu.esp -= 4;
    sub_52b6c0(app, cpu);
    if (cpu.terminate) return;
    // 00524cb4  ff1560445600           -call dword ptr [0x564460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653600) /* 0x564460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524cba  8b1d88435600           -mov ebx, dword ptr [0x564388]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524cc0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524cc2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524cc4  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00524cc7  e864fcffff             -call 0x524930
    cpu.esp -= 4;
    sub_524930(app, cpu);
    if (cpu.terminate) return;
    // 00524ccc  e84f60fcff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 00524cd1  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 00524cd6  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00524cdb  e880aafcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00524ce0  8b1d84435600           -mov ebx, dword ptr [0x564384]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524ce6  8b1588435600           -mov edx, dword ptr [0x564388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524cec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524ced  83ea0a                 -sub edx, 0xa
    (cpu.edx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00524cf0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00524cf2  e84988fdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 00524cf7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00524cfc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524cfe  e85daafcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00524d03  e828abfcff             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00524d08  8b1588435600           -mov edx, dword ptr [0x564388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524d0e  8b842428010000         -mov eax, dword ptr [esp + 0x128]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 00524d15  83ea09                 -sub edx, 9
    (cpu.edx) -= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00524d18  e8436b0000             -call 0x52b860
    cpu.esp -= 4;
    sub_52b860(app, cpu);
    if (cpu.terminate) return;
    // 00524d1d  ff1564445600           -call dword ptr [0x564464]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653604) /* 0x564464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524d23  e86860fcff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00524d28  e86360fcff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00524d2d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00524d2f  e8acb9fcff             -call 0x4f06e0
    cpu.esp -= 4;
    sub_4f06e0(app, cpu);
    if (cpu.terminate) return;
    // 00524d34  e8e75ffcff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 00524d39  ff155c445600           -call dword ptr [0x56445c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653596) /* 0x56445c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524d3f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524d41  8b1d88435600           -mov ebx, dword ptr [0x564388]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524d47  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524d49  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00524d4c  e8fffbffff             -call 0x524950
    cpu.esp -= 4;
    sub_524950(app, cpu);
    if (cpu.terminate) return;
    // 00524d51  ff1564445600           -call dword ptr [0x564464]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653604) /* 0x564464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524d57  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00524d59  e802fafcff             -call 0x4f4760
    cpu.esp -= 4;
    sub_4f4760(app, cpu);
    if (cpu.terminate) return;
    // 00524d5e  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00524d65  e896f9fcff             -call 0x4f4700
    cpu.esp -= 4;
    sub_4f4700(app, cpu);
    if (cpu.terminate) return;
    // 00524d6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524d6c  e88fb1fcff             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
    // 00524d71  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00524d73  e884a2fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 00524d78  81c42c010000           -add esp, 0x12c
    (cpu.esp) += x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 00524d7e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524d7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524d80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524d81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524d82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524d83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_524d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524d90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524d91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524d92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524d93  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524d98  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524d9a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00524d9d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00524d9f  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00524da1  8d58f8                 -lea ebx, [eax - 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00524da4  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524da9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524dab  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00524dae  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00524db0  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00524db2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00524db4  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00524db6  8d9070ffffff           -lea edx, [eax - 0x90]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-144) /* -0x90 */);
    // 00524dbc  b920010000             -mov ecx, 0x120
    cpu.ecx = 288 /*0x120*/;
    // 00524dc1  b8801e5500             -mov eax, 0x551e80
    cpu.eax = 5578368 /*0x551e80*/;
    // 00524dc6  e8a5fbffff             -call 0x524970
    cpu.esp -= 4;
    sub_524970(app, cpu);
    if (cpu.terminate) return;
    // 00524dcb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524dcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524dcd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524dce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_524dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524dd0  e9fb6a0000             -jmp 0x52b8d0
    return sub_52b8d0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_524de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524de0  e93b6d0000             -jmp 0x52bb20
    return sub_52bb20(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_524df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524df1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524df2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524df3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524df4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00524df5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524df8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00524dfa  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00524dfc  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524dff  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00524e01  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00524e05  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00524e09  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00524e0b  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00524e0e  8b2c85c0f59e00         -mov ebp, dword ptr [eax*4 + 0x9ef5c0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 00524e15  8b5538                 -mov edx, dword ptr [ebp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(56) /* 0x38 */);
    // 00524e18  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00524e1a  0f85f2000000           -jne 0x524f12
    if (!cpu.flags.zf)
    {
        goto L_0x00524f12;
    }
L_0x00524e20:
    // 00524e20  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524e24  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00524e27  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00524e2a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00524e2e  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 00524e31  741f                   -je 0x524e52
    if (cpu.flags.zf)
    {
        goto L_0x00524e52;
    }
    // 00524e33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524e35  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00524e37  e8a4c2fbff             -call 0x4e10e0
    cpu.esp -= 4;
    sub_4e10e0(app, cpu);
    if (cpu.terminate) return;
    // 00524e3c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524e40  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00524e43  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00524e47  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524e4b  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524e4f  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00524e52:
    // 00524e52  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00524e54  83fe08                 +cmp esi, 8
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
    // 00524e57  7d0e                   -jge 0x524e67
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00524e67;
    }
    // 00524e59  83feff                 +cmp esi, -1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524e5c  0f85bc000000           -jne 0x524f1e
    if (!cpu.flags.zf)
    {
        goto L_0x00524f1e;
    }
    // 00524e62  b900000040             -mov ecx, 0x40000000
    cpu.ecx = 1073741824 /*0x40000000*/;
L_0x00524e67:
    // 00524e67  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00524e69  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00524e6b  e870c7fbff             -call 0x4e15e0
    cpu.esp -= 4;
    sub_4e15e0(app, cpu);
    if (cpu.terminate) return;
    // 00524e70  e87bc3fbff             -call 0x4e11f0
    cpu.esp -= 4;
    sub_4e11f0(app, cpu);
    if (cpu.terminate) return;
    // 00524e75  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00524e78  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00524e7a  4a                     -dec edx
    (cpu.edx)--;
    // 00524e7b  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524e7e  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00524e80  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00524e82  21d1                   -and ecx, edx
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx));
    // 00524e84  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524e88  2b542408               -sub edx, dword ptr [esp + 8]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00524e8c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00524e8e  83ea10                 -sub edx, 0x10
    (cpu.edx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524e91  83e910                 -sub ecx, 0x10
    (cpu.ecx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524e94  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00524e98  39d1                   +cmp ecx, edx
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
    // 00524e9a  7e06                   -jle 0x524ea2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00524ea2;
    }
    // 00524e9c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00524e9e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00524ea0  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00524ea2:
    // 00524ea2  8d0437                 -lea eax, [edi + esi]
    cpu.eax = x86::reg32(cpu.edi + cpu.esi * 1);
    // 00524ea5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00524ea8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524eac  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00524eaf  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00524eb2  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00524eb4  e83756fcff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00524eb9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524ebd  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00524ec0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00524ec4  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00524ec6  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524ec9  7e35                   -jle 0x524f00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00524f00;
    }
    // 00524ecb  8d7710                 -lea esi, [edi + 0x10]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00524ece  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00524ed0  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524ed4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524ed5  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524ed9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524eda  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524edc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524ede  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00524ee0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00524ee2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00524ee4  e837c2fbff             -call 0x4e1120
    cpu.esp -= 4;
    sub_4e1120(app, cpu);
    if (cpu.terminate) return;
    // 00524ee9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00524eeb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00524eed  e88ec1fbff             -call 0x4e1080
    cpu.esp -= 4;
    sub_4e1080(app, cpu);
    if (cpu.terminate) return;
    // 00524ef2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524ef6  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00524ef9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524efd  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00524f00:
    // 00524f00  8b7538                 -mov esi, dword ptr [ebp + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(56) /* 0x38 */);
    // 00524f03  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00524f05  7565                   -jne 0x524f6c
    if (!cpu.flags.zf)
    {
        goto L_0x00524f6c;
    }
    // 00524f07  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00524f09  83c410                 +add esp, 0x10
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
    // 00524f0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00524f12:
    // 00524f12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524f13  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524f19  e902ffffff             -jmp 0x524e20
    goto L_0x00524e20;
L_0x00524f1e:
    // 00524f1e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00524f20  7c0a                   -jl 0x524f2c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00524f2c;
    }
    // 00524f22  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00524f27  e93bffffff             -jmp 0x524e67
    goto L_0x00524e67;
L_0x00524f2c:
    // 00524f2c  833d0c44560000         +cmp dword ptr [0x56440c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524f33  0f842effffff           -je 0x524e67
    if (cpu.flags.zf)
    {
        goto L_0x00524e67;
    }
    // 00524f39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524f3a  baa01e5500             -mov edx, 0x551ea0
    cpu.edx = 5578400 /*0x551ea0*/;
    // 00524f3f  b8b01e5500             -mov eax, 0x551eb0
    cpu.eax = 5578416 /*0x551eb0*/;
    // 00524f44  68c01e5500             -push 0x551ec0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578432 /*0x551ec0*/;
    cpu.esp -= 4;
    // 00524f49  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00524f4f  ba63000000             -mov edx, 0x63
    cpu.edx = 99 /*0x63*/;
    // 00524f54  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 00524f59  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 00524f5f  e8acc0edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00524f64  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00524f67  e9fbfeffff             -jmp 0x524e67
    goto L_0x00524e67;
L_0x00524f6c:
    // 00524f6c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524f6d  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524f73  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00524f75  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524f78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_524f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524f80  e97b29fdff             -jmp 0x4f7900
    return sub_4f7900(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_524f88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524f88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524f89  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524f8a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524f8b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524f8c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524f8d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00524f8e  8b3d54b1a000           -mov edi, dword ptr [0xa0b154]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 00524f94  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00524f96  0f85c1000000           -jne 0x52505d
    if (!cpu.flags.zf)
    {
        goto L_0x0052505d;
    }
    // 00524f9c  8b2d39785600           -mov ebp, dword ptr [0x567839]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5666873) /* 0x567839 */);
    // 00524fa2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00524fa4  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00524fa7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00524fa9  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00524fab  7416                   -je 0x524fc3
    if (cpu.flags.zf)
    {
        goto L_0x00524fc3;
    }
L_0x00524fad:
    // 00524fad  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00524faf  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00524fb2  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00524fb4  7404                   -je 0x524fba
    if (cpu.flags.zf)
    {
        goto L_0x00524fba;
    }
    // 00524fb6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00524fb8  ebf3                   -jmp 0x524fad
    goto L_0x00524fad;
L_0x00524fba:
    // 00524fba  41                     -inc ecx
    (cpu.ecx)++;
    // 00524fbb  8a33                   -mov dh, byte ptr [ebx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx);
    // 00524fbd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00524fbf  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00524fc1  75ea                   -jne 0x524fad
    if (!cpu.flags.zf)
    {
        goto L_0x00524fad;
    }
L_0x00524fc3:
    // 00524fc3  893d54b1a000           -mov dword ptr [0xa0b154], edi
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.edi;
    // 00524fc9  29e8                   +sub eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00524fcb  7505                   -jne 0x524fd2
    if (!cpu.flags.zf)
    {
        goto L_0x00524fd2;
    }
    // 00524fcd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00524fd2:
    // 00524fd2  e82929fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 00524fd7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524fd9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00524fdb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524fdd  0f8475000000           -je 0x525058
    if (cpu.flags.zf)
    {
        goto L_0x00525058;
    }
    // 00524fe3  a33082a100             -mov dword ptr [0xa18230], eax
    app->getMemory<x86::reg32>(x86::reg32(10584624) /* 0xa18230 */) = cpu.eax;
    // 00524fe8  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00524fef  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00524ff2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00524ff4  e80729fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 00524ff9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524ffb  7454                   -je 0x525051
    if (cpu.flags.zf)
    {
        goto L_0x00525051;
    }
    // 00524ffd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00524fff  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00525002  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00525004  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00525006  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00525008  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0052500a  741a                   -je 0x525026
    if (cpu.flags.zf)
    {
        goto L_0x00525026;
    }
L_0x0052500c:
    // 0052500c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052500e  891c11                 -mov dword ptr [ecx + edx], ebx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.ebx;
L_0x00525011:
    // 00525011  43                     -inc ebx
    (cpu.ebx)++;
    // 00525012  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00525014  40                     -inc eax
    (cpu.eax)++;
    // 00525015  8853ff                 -mov byte ptr [ebx - 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00525018  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0052501a  75f5                   -jne 0x525011
    if (!cpu.flags.zf)
    {
        goto L_0x00525011;
    }
    // 0052501c  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052501f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00525021  46                     -inc esi
    (cpu.esi)++;
    // 00525022  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00525024  75e6                   -jne 0x52500c
    if (!cpu.flags.zf)
    {
        goto L_0x0052500c;
    }
L_0x00525026:
    // 00525026  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00525028  c7040100000000         -mov dword ptr [ecx + eax], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = 0 /*0x0*/;
    // 0052502f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525032  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00525034  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00525037  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00525039  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 0052503e  893d54b1a000           -mov dword ptr [0xa0b154], edi
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.edi;
    // 00525044  e8f7b5fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00525049  8b3d54b1a000           -mov edi, dword ptr [0xa0b154]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052504f  eb07                   -jmp 0x525058
    goto L_0x00525058;
L_0x00525051:
    // 00525051  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00525053  e89829fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x00525058:
    // 00525058  e8536d0000             -call 0x52bdb0
    cpu.esp -= 4;
    sub_52bdb0(app, cpu);
    if (cpu.terminate) return;
L_0x0052505d:
    // 0052505d  8b3d54b1a000           -mov edi, dword ptr [0xa0b154]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 00525063  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525064  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525065  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525066  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525067  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525068  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525069  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52506c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052506c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052506d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052506e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052506f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525070  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00525071  e85a6e0000             -call 0x52bed0
    cpu.esp -= 4;
    sub_52bed0(app, cpu);
    if (cpu.terminate) return;
    // 00525076  8b1554b1a000           -mov edx, dword ptr [0xa0b154]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052507c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052507e  740f                   -je 0x52508f
    if (cpu.flags.zf)
    {
        goto L_0x0052508f;
    }
    // 00525080  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00525082  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00525084  e86729fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00525089  891d54b1a000           -mov dword ptr [0xa0b154], ebx
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.ebx;
L_0x0052508f:
    // 0052508f  8b0d3082a100           -mov ecx, dword ptr [0xa18230]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10584624) /* 0xa18230 */);
    // 00525095  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00525097  740f                   -je 0x5250a8
    if (cpu.flags.zf)
    {
        goto L_0x005250a8;
    }
    // 00525099  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052509b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0052509d  e84e29fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 005250a2  89353082a100           -mov dword ptr [0xa18230], esi
    app->getMemory<x86::reg32>(x86::reg32(10584624) /* 0xa18230 */) = cpu.esi;
L_0x005250a8:
    // 005250a8  8b3d39785600           -mov edi, dword ptr [0x567839]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5666873) /* 0x567839 */);
    // 005250ae  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005250b0  7408                   -je 0x5250ba
    if (cpu.flags.zf)
    {
        goto L_0x005250ba;
    }
    // 005250b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005250b3  2eff15d8445300         -call dword ptr cs:[0x5344d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457112) /* 0x5344d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005250ba:
    // 005250ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5250c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005250c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005250c1  803800                 +cmp byte ptr [eax], 0
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
    // 005250c4  7507                   -jne 0x5250cd
    if (!cpu.flags.zf)
    {
        goto L_0x005250cd;
    }
    // 005250c6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005250cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005250cd:
    // 005250cd  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 005250d4  7422                   -je 0x5250f8
    if (cpu.flags.zf)
    {
        goto L_0x005250f8;
    }
    // 005250d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005250d8  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 005250da  8a9211b2a000           -mov dl, byte ptr [edx + 0xa0b211]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10531345) /* 0xa0b211 */);
    // 005250e0  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 005250e3  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 005250e9  740d                   -je 0x5250f8
    if (cpu.flags.zf)
    {
        goto L_0x005250f8;
    }
    // 005250eb  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005250ef  7507                   -jne 0x5250f8
    if (!cpu.flags.zf)
    {
        goto L_0x005250f8;
    }
    // 005250f1  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 005250f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005250f8:
    // 005250f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005250fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_525100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525100  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525101  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 00525108  7420                   -je 0x52512a
    if (cpu.flags.zf)
    {
        goto L_0x0052512a;
    }
    // 0052510a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052510c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052510e  8a9211b2a000           -mov dl, byte ptr [edx + 0xa0b211]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10531345) /* 0xa0b211 */);
    // 00525114  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00525117  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052511d  740b                   -je 0x52512a
    if (cpu.flags.zf)
    {
        goto L_0x0052512a;
    }
    // 0052511f  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00525123  7405                   -je 0x52512a
    if (cpu.flags.zf)
    {
        goto L_0x0052512a;
    }
    // 00525125  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00525128  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525129  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052512a:
    // 0052512a  40                     -inc eax
    (cpu.eax)++;
    // 0052512b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052512c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_525130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525130  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525131  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525132  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525133  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525134  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00525135  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00525136  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525139  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052513b  833d58b1a00000         +cmp dword ptr [0xa0b158], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525142  7505                   -jne 0x525149
    if (!cpu.flags.zf)
    {
        goto L_0x00525149;
    }
    // 00525144  e857010000             -call 0x5252a0
    cpu.esp -= 4;
    sub_5252a0(app, cpu);
    if (cpu.terminate) return;
L_0x00525149:
    // 00525149  8b3558b1a000           -mov esi, dword ptr [0xa0b158]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052514f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00525151  743d                   -je 0x525190
    if (cpu.flags.zf)
    {
        goto L_0x00525190;
    }
    // 00525153  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00525155  7439                   -je 0x525190
    if (cpu.flags.zf)
    {
        goto L_0x00525190;
    }
    // 00525157  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00525159  e8a2010000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 0052515e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00525160  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00525162  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00525165  eb23                   -jmp 0x52518a
    goto L_0x0052518a;
L_0x00525167:
    // 00525167  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00525169  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052516b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052516d  e8fe6d0000             -call 0x52bf70
    cpu.esp -= 4;
    sub_52bf70(app, cpu);
    if (cpu.terminate) return;
    // 00525172  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525174  7511                   -jne 0x525187
    if (!cpu.flags.zf)
    {
        goto L_0x00525187;
    }
    // 00525176  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00525179  66833c013d             +cmp word ptr [ecx + eax], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 1);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052517e  7507                   -jne 0x525187
    if (!cpu.flags.zf)
    {
        goto L_0x00525187;
    }
    // 00525180  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00525183  01c8                   +add eax, ecx
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
    // 00525185  eb0b                   -jmp 0x525192
    goto L_0x00525192;
L_0x00525187:
    // 00525187  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0052518a:
    // 0052518a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0052518c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052518e  75d7                   -jne 0x525167
    if (!cpu.flags.zf)
    {
        goto L_0x00525167;
    }
L_0x00525190:
    // 00525190  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00525192:
    // 00525192  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525195  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525196  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525197  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525198  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525199  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052519a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052519b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_5251a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005251a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005251a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005251a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005251a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005251a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005251a5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005251a8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005251ab  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005251ad  66813d417856000080     +cmp word ptr [0x567841], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5666881) /* 0x567841 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005251b6  730e                   -jae 0x5251c6
    if (!cpu.flags.cf)
    {
        goto L_0x005251c6;
    }
    // 005251b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005251b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005251ba  2eff15e0455300         -call dword ptr cs:[0x5345e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457376) /* 0x5345e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005251c1  e9c3000000             -jmp 0x525289
    goto L_0x00525289;
L_0x005251c6:
    // 005251c6  e835010000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 005251cb  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005251cd  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 005251d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005251d2  e82927fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 005251d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005251d9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005251db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005251dd  0f84a6000000           -je 0x525289
    if (cpu.flags.zf)
    {
        goto L_0x00525289;
    }
    // 005251e3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005251e5  7504                   -jne 0x5251eb
    if (!cpu.flags.zf)
    {
        goto L_0x005251eb;
    }
    // 005251e7  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 005251e9  eb2b                   -jmp 0x525216
    goto L_0x00525216;
L_0x005251eb:
    // 005251eb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005251ed  e80e010000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 005251f2  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005251f4  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 005251f7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005251f9  e80227fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 005251fe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00525200  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525202  7512                   -jne 0x525216
    if (!cpu.flags.zf)
    {
        goto L_0x00525216;
    }
    // 00525204  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00525206  e8e527fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052520b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052520d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525210  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525211  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525212  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525213  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525214  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525215  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525216:
    // 00525216  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00525219  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0052521b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052521d  e8cef0ffff             -call 0x5242f0
    cpu.esp -= 4;
    sub_5242f0(app, cpu);
    if (cpu.terminate) return;
    // 00525222  83f8ff                 +cmp eax, -1
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
    // 00525225  751d                   -jne 0x525244
    if (!cpu.flags.zf)
    {
        goto L_0x00525244;
    }
    // 00525227  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00525229  e8c227fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052522e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00525230  7407                   -je 0x525239
    if (cpu.flags.zf)
    {
        goto L_0x00525239;
    }
    // 00525232  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00525234  e8b727fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x00525239:
    // 00525239  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052523b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052523e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052523f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525240  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525241  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525242  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525243  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525244:
    // 00525244  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00525246  7422                   -je 0x52526a
    if (cpu.flags.zf)
    {
        goto L_0x0052526a;
    }
    // 00525248  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0052524a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052524c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052524e  e89df0ffff             -call 0x5242f0
    cpu.esp -= 4;
    sub_5242f0(app, cpu);
    if (cpu.terminate) return;
    // 00525253  83f8ff                 +cmp eax, -1
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
    // 00525256  7512                   -jne 0x52526a
    if (!cpu.flags.zf)
    {
        goto L_0x0052526a;
    }
    // 00525258  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052525a  e89127fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052525f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00525261  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525264  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525265  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525266  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525267  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525268  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525269  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052526a:
    // 0052526a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052526b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052526c  2eff15dc455300         -call dword ptr cs:[0x5345dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457372) /* 0x5345dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525273  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00525275  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00525277  e87427fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052527c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052527e  7407                   -je 0x525287
    if (cpu.flags.zf)
    {
        goto L_0x00525287;
    }
    // 00525280  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00525282  e86927fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x00525287:
    // 00525287  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00525289:
    // 00525289  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052528c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052528d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052528e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052528f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525290  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525291  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5252a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005252a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005252a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005252a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005252a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005252a4  8b3554b1a000           -mov esi, dword ptr [0xa0b154]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 005252aa  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005252ac  7441                   -je 0x5252ef
    if (cpu.flags.zf)
    {
        goto L_0x005252ef;
    }
L_0x005252ae:
    // 005252ae  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 005252b0  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005252b3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005252b5  7438                   -je 0x5252ef
    if (cpu.flags.zf)
    {
        goto L_0x005252ef;
    }
    // 005252b7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005252b9  e8922dffff             -call 0x518050
    cpu.esp -= 4;
    sub_518050(app, cpu);
    if (cpu.terminate) return;
    // 005252be  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 005252c1  8d045d00000000         -lea eax, [ebx*2]
    cpu.eax = x86::reg32(cpu.ebx * 2);
    // 005252c8  e83326fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 005252cd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005252cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005252d1  74db                   -je 0x5252ae
    if (cpu.flags.zf)
    {
        goto L_0x005252ae;
    }
    // 005252d3  e8a82dffff             -call 0x518080
    cpu.esp -= 4;
    sub_518080(app, cpu);
    if (cpu.terminate) return;
    // 005252d8  83f8ff                 +cmp eax, -1
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
    // 005252db  7409                   -je 0x5252e6
    if (cpu.flags.zf)
    {
        goto L_0x005252e6;
    }
    // 005252dd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005252df  e8946e0000             -call 0x52c178
    cpu.esp -= 4;
    sub_52c178(app, cpu);
    if (cpu.terminate) return;
    // 005252e4  ebc8                   -jmp 0x5252ae
    goto L_0x005252ae;
L_0x005252e6:
    // 005252e6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005252e8  e80327fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 005252ed  ebbf                   -jmp 0x5252ae
    goto L_0x005252ae;
L_0x005252ef:
    // 005252ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005252f0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005252f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005252f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005252f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525300  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525301  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525302  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00525304  66833800               +cmp word ptr [eax], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00525308  740c                   -je 0x525316
    if (cpu.flags.zf)
    {
        goto L_0x00525316;
    }
L_0x0052530a:
    // 0052530a  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0052530e  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00525311  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00525314  75f4                   -jne 0x52530a
    if (!cpu.flags.zf)
    {
        goto L_0x0052530a;
    }
L_0x00525316:
    // 00525316  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00525318  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0052531a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052531b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052531c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_525320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525321  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525322  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00525323  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00525325  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00525327  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00525329  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0052532a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0052532c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0052532e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052532f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525331  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00525334  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00525336  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00525338  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052533b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052533d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052533e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052533f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00525341  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525342  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525343  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525344  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525351  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525352  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00525354:
    // 00525354  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00525357  668b1a                 -mov bx, word ptr [edx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx);
    // 0052535a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052535d  668958fe               -mov word ptr [eax - 2], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00525361  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 00525364  75ee                   -jne 0x525354
    if (!cpu.flags.zf)
    {
        goto L_0x00525354;
    }
    // 00525366  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525368  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525369  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052536a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525370  663d6100               +cmp ax, 0x61
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(97 /*0x61*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00525374  7209                   -jb 0x52537f
    if (cpu.flags.cf)
    {
        goto L_0x0052537f;
    }
    // 00525376  663d7a00               +cmp ax, 0x7a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(122 /*0x7a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052537a  7703                   -ja 0x52537f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052537f;
    }
    // 0052537c  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0052537f:
    // 0052537f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_525380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525380  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525383  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00525385  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00525387  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052538a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525392  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525393  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525396  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00525398  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052539a  ff1580775600           -call dword ptr [0x567780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666688) /* 0x567780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005253a0  b84c6f5600             -mov eax, 0x566f4c
    cpu.eax = 5664588 /*0x566f4c*/;
    // 005253a5  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 005253a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005253a9  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 005253ab  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 005253ae  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005253b0  e817000000             -call 0x5253cc
    cpu.esp -= 4;
    sub_5253cc(app, cpu);
    if (cpu.terminate) return;
    // 005253b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005253b7  0f85bb010000           -jne 0x525578
    if (!cpu.flags.zf)
    {
        return sub_525578(app, cpu);
    }
    // 005253bd  ff1588775600           -call dword ptr [0x567788]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666696) /* 0x567788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005253c3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005253c5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005253c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005253c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005253ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005253cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
