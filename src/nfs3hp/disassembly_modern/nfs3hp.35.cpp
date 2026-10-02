#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4dcdd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dcdd0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dcdd1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dcdd3  833dccd46f0000         +cmp dword ptr [0x6fd4cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328972) /* 0x6fd4cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dcdda  7407                   -je 0x4dcde3
    if (cpu.flags.zf)
    {
        goto L_0x004dcde3;
    }
    // 004dcddc  a12ca28c00             -mov eax, dword ptr [0x8ca22c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */);
    // 004dcde1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dcde2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dcde3:
    // 004dcde3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004dcde5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dcde6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4dcdf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dcdf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dcdf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dcdf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dcdf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dcdf4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dcdf5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dcdf6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dcdf8  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004dcdfb  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
    // 004dce00  b82ca28c00             -mov eax, 0x8ca22c
    cpu.eax = 9216556 /*0x8ca22c*/;
    // 004dce05  e802390000             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004dce0a  ba004b0000             -mov edx, 0x4b00
    cpu.edx = 19200 /*0x4b00*/;
    // 004dce0f  b8e80b8c00             -mov eax, 0x8c0be8
    cpu.eax = 9178088 /*0x8c0be8*/;
    // 004dce14  e8f3380000             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004dce19  ba20030000             -mov edx, 0x320
    cpu.edx = 800 /*0x320*/;
    // 004dce1e  b8c0088c00             -mov eax, 0x8c08c0
    cpu.eax = 9177280 /*0x8c08c0*/;
    // 004dce23  e8e4380000             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004dce28  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004dce2a  891588425600           -mov dword ptr [0x564288], edx
    app->getMemory<x86::reg32>(x86::reg32(5653128) /* 0x564288 */) = cpu.edx;
    // 004dce30  89158c425600           -mov dword ptr [0x56428c], edx
    app->getMemory<x86::reg32>(x86::reg32(5653132) /* 0x56428c */) = cpu.edx;
    // 004dce36  8a15e8a18c00           -mov dl, byte ptr [0x8ca1e8]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(9216488) /* 0x8ca1e8 */);
    // 004dce3c  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004dce41  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dce43  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dce46  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dce48  89152ca28c00           -mov dword ptr [0x8ca22c], edx
    app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */) = cpu.edx;
    // 004dce4e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004dce50  0f848e030000           -je 0x4dd1e4
    if (cpu.flags.zf)
    {
        goto L_0x004dd1e4;
    }
    // 004dce56  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004dce5b  66a1eaa18c00           -mov ax, word ptr [0x8ca1ea]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(9216490) /* 0x8ca1ea */);
    // 004dce61  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 004dce68  66a33ca28c00           -mov word ptr [0x8ca23c], ax
    app->getMemory<x86::reg16>(x86::reg32(9216572) /* 0x8ca23c */) = cpu.ax;
    // 004dce6e  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004dce70  66a1eca18c00           -mov ax, word ptr [0x8ca1ec]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(9216492) /* 0x8ca1ec */);
    // 004dce76  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004dce79  66a33ea28c00           -mov word ptr [0x8ca23e], ax
    app->getMemory<x86::reg16>(x86::reg32(9216574) /* 0x8ca23e */) = cpu.ax;
    // 004dce7f  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004dce81  66a1eea18c00           -mov ax, word ptr [0x8ca1ee]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(9216494) /* 0x8ca1ee */);
    // 004dce87  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004dce8a  66a340a28c00           -mov word ptr [0x8ca240], ax
    app->getMemory<x86::reg16>(x86::reg32(9216576) /* 0x8ca240 */) = cpu.ax;
    // 004dce90  8b9198425600           -mov edx, dword ptr [ecx + 0x564298]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653144) /* 0x564298 */);
    // 004dce96  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004dce9b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004dce9e  a348a28c00             -mov dword ptr [0x8ca248], eax
    app->getMemory<x86::reg32>(x86::reg32(9216584) /* 0x8ca248 */) = cpu.eax;
    // 004dcea3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dcea5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dcea8  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dceaa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004dceac  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004dceaf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004dceb1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004dceb4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004dceb6  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004dceb9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dcebb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dcebe  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004dcec1  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004dcec3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004dcec6  8b9194425600           -mov edx, dword ptr [ecx + 0x564294]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653140) /* 0x564294 */);
    // 004dcecc  891530a28c00           -mov dword ptr [0x8ca230], edx
    app->getMemory<x86::reg32>(x86::reg32(9216560) /* 0x8ca230 */) = cpu.edx;
    // 004dced2  8bb19c425600           -mov esi, dword ptr [ecx + 0x56429c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653148) /* 0x56429c */);
    // 004dced8  a334a28c00             -mov dword ptr [0x8ca234], eax
    app->getMemory<x86::reg32>(x86::reg32(9216564) /* 0x8ca234 */) = cpu.eax;
    // 004dcedd  83fe01                 +cmp esi, 1
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
    // 004dcee0  7e04                   -jle 0x4dcee6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dcee6;
    }
    // 004dcee2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004dcee4  eb05                   -jmp 0x4dceeb
    goto L_0x004dceeb;
L_0x004dcee6:
    // 004dcee6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004dceeb:
    // 004dceeb  8b152ca28c00           -mov edx, dword ptr [0x8ca22c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */);
    // 004dcef1  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 004dcef8  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004dcefa  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004dcefd  bb68010000             -mov ebx, 0x168
    cpu.ebx = 360 /*0x168*/;
    // 004dcf02  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004dcf04  a34ca28c00             -mov dword ptr [0x8ca24c], eax
    app->getMemory<x86::reg32>(x86::reg32(9216588) /* 0x8ca24c */) = cpu.eax;
    // 004dcf09  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004dcf0c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004dcf0f  8b81a0425600           -mov eax, dword ptr [ecx + 0x5642a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653152) /* 0x5642a0 */);
    // 004dcf15  8b91a8425600           -mov edx, dword ptr [ecx + 0x5642a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653160) /* 0x5642a8 */);
    // 004dcf1b  a354a28c00             -mov dword ptr [0x8ca254], eax
    app->getMemory<x86::reg32>(x86::reg32(9216596) /* 0x8ca254 */) = cpu.eax;
    // 004dcf20  8b81a4425600           -mov eax, dword ptr [ecx + 0x5642a4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653156) /* 0x5642a4 */);
    // 004dcf26  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004dcf29  a358a28c00             -mov dword ptr [0x8ca258], eax
    app->getMemory<x86::reg32>(x86::reg32(9216600) /* 0x8ca258 */) = cpu.eax;
    // 004dcf2e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dcf30  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dcf33  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dcf35  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004dcf38  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004dcf3a  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004dcf3c  8b91ac425600           -mov edx, dword ptr [ecx + 0x5642ac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653164) /* 0x5642ac */);
    // 004dcf42  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004dcf45  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004dcf48  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 004dcf4d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dcf4f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dcf52  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dcf54  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004dcf57  dc0db4975400           -fmul qword ptr [0x5497b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5543860) /* 0x5497b4 */));
    // 004dcf5d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004dcf60  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004dcf63  dc0db4975400           -fmul qword ptr [0x5497b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5543860) /* 0x5497b4 */));
    // 004dcf69  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004dcf6b  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dcf6d  d91d50a28c00           -fstp dword ptr [0x8ca250]
    app->getMemory<float>(x86::reg32(9216592) /* 0x8ca250 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dcf73  bb74a28c00             -mov ebx, 0x8ca274
    cpu.ebx = 9216628 /*0x8ca274*/;
    // 004dcf78  d95df4                 -fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dcf7b  ba6ca28c00             -mov edx, 0x8ca26c
    cpu.edx = 9216620 /*0x8ca26c*/;
    // 004dcf80  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004dcf83  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dcf86  e8e5d90000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004dcf8b  686ca28c00             -push 0x8ca26c
    app->getMemory<x86::reg32>(cpu.esp-4) = 9216620 /*0x8ca26c*/;
    cpu.esp -= 4;
    // 004dcf90  ba6ca28c00             -mov edx, 0x8ca26c
    cpu.edx = 9216620 /*0x8ca26c*/;
    // 004dcf95  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dcf9a  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 004dcf9d  893d70a28c00           -mov dword ptr [0x8ca270], edi
    app->getMemory<x86::reg32>(x86::reg32(9216624) /* 0x8ca270 */) = cpu.edi;
    // 004dcfa3  e8a8300000             -call 0x4e0050
    cpu.esp -= 4;
    sub_4e0050(app, cpu);
    if (cpu.terminate) return;
    // 004dcfa8  8b152ca28c00           -mov edx, dword ptr [0x8ca22c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */);
    // 004dcfae  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 004dcfb5  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004dcfb7  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004dcfba  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004dcfbc  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004dcfbf  8b8190425600           -mov eax, dword ptr [ecx + 0x564290]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653136) /* 0x564290 */);
    // 004dcfc5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004dcfc7  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004dcfcc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dcfcf  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dcfd1  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004dcfd6  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004dcfd9  8b81b0425600           -mov eax, dword ptr [ecx + 0x5642b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653168) /* 0x5642b0 */);
    // 004dcfdf  8b91c0425600           -mov edx, dword ptr [ecx + 0x5642c0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653184) /* 0x5642c0 */);
    // 004dcfe5  a338a28c00             -mov dword ptr [0x8ca238], eax
    app->getMemory<x86::reg32>(x86::reg32(9216568) /* 0x8ca238 */) = cpu.eax;
    // 004dcfea  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004dcfef  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004dcff2  a3e00b8c00             -mov dword ptr [0x8c0be0], eax
    app->getMemory<x86::reg32>(x86::reg32(9178080) /* 0x8c0be0 */) = cpu.eax;
    // 004dcff7  a3e40b8c00             -mov dword ptr [0x8c0be4], eax
    app->getMemory<x86::reg32>(x86::reg32(9178084) /* 0x8c0be4 */) = cpu.eax;
    // 004dcffc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dcffe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dd001  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dd003  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004dd005  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004dd008  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004dd00a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004dd00d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dd00f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dd012  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004dd015  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004dd017  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004dd01a  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004dd01d  dc0db4975400           -fmul qword ptr [0x5497b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5543860) /* 0x5497b4 */));
    // 004dd023  db054ca28c00           -fild dword ptr [0x8ca24c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216588) /* 0x8ca24c */))));
    // 004dd029  db0554a28c00           -fild dword ptr [0x8ca254]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216596) /* 0x8ca254 */))));
    // 004dd02f  893d44a28c00           -mov dword ptr [0x8ca244], edi
    app->getMemory<x86::reg32>(x86::reg32(9216580) /* 0x8ca244 */) = cpu.edi;
    // 004dd035  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dd037  d91d5ca28c00           -fstp dword ptr [0x8ca25c]
    app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd03d  d91d64a28c00           -fstp dword ptr [0x8ca264]
    app->getMemory<float>(x86::reg32(9216612) /* 0x8ca264 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd043  a378a28c00             -mov dword ptr [0x8ca278], eax
    app->getMemory<x86::reg32>(x86::reg32(9216632) /* 0x8ca278 */) = cpu.eax;
    // 004dd048  8b81b4425600           -mov eax, dword ptr [ecx + 0x5642b4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653172) /* 0x5642b4 */);
    // 004dd04e  d90564a28c00           -fld dword ptr [0x8ca264]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(9216612) /* 0x8ca264 */)));
    // 004dd054  a37ca28c00             -mov dword ptr [0x8ca27c], eax
    app->getMemory<x86::reg32>(x86::reg32(9216636) /* 0x8ca27c */) = cpu.eax;
    // 004dd059  8b81bc425600           -mov eax, dword ptr [ecx + 0x5642bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653180) /* 0x5642bc */);
    // 004dd05f  d981b8425600           -fld dword ptr [ecx + 0x5642b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(5653176) /* 0x5642b8 */)));
    // 004dd065  a384a28c00             -mov dword ptr [0x8ca284], eax
    app->getMemory<x86::reg32>(x86::reg32(9216644) /* 0x8ca284 */) = cpu.eax;
    // 004dd06a  a158a28c00             -mov eax, dword ptr [0x8ca258]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216600) /* 0x8ca258 */);
    // 004dd06f  d91d80a28c00           -fstp dword ptr [0x8ca280]
    app->getMemory<float>(x86::reg32(9216640) /* 0x8ca280 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd075  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004dd077  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dd079  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dd07b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004dd07e  d91d70a28c00           -fstp dword ptr [0x8ca270]
    app->getMemory<float>(x86::reg32(9216624) /* 0x8ca270 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd084  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004dd087  d91d60a28c00           -fstp dword ptr [0x8ca260]
    app->getMemory<float>(x86::reg32(9216608) /* 0x8ca260 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd08d  d82560a28c00           -fsub dword ptr [0x8ca260]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216608) /* 0x8ca260 */));
    // 004dd093  8b152ca28c00           -mov edx, dword ptr [0x8ca22c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */);
    // 004dd099  d91d68a28c00           -fstp dword ptr [0x8ca268]
    app->getMemory<float>(x86::reg32(9216616) /* 0x8ca268 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd09f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004dd0a1  0f843d010000           -je 0x4dd1e4
    if (cpu.flags.zf)
    {
        goto L_0x004dd1e4;
    }
    // 004dd0a7  e82463fcff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004dd0ac  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004dd0ae  eb0c                   -jmp 0x4dd0bc
    goto L_0x004dd0bc;
L_0x004dd0b0:
    // 004dd0b0  81f920030000           +cmp ecx, 0x320
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(800 /*0x320*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd0b6  0f8dfa000000           -jge 0x4dd1b6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd1b6;
    }
L_0x004dd0bc:
    // 004dd0bc  e86fe10000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd0c1  d80d5ca28c00           -fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd0c7  d80dbc975400           -fmul dword ptr [0x5497bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543868) /* 0x5497bc */));
    // 004dd0cd  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 004dd0d4  d8255ca28c00           -fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd0da  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004dd0dc  d91c95e8568c00         -fstp dword ptr [edx*4 + 0x8c56e8]
    app->getMemory<float>(x86::reg32(9197288) /* 0x8c56e8 */ + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd0e3  e848e10000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd0e8  d80d68a28c00           -fmul dword ptr [0x8ca268]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216616) /* 0x8ca268 */));
    // 004dd0ee  d80560a28c00           -fadd dword ptr [0x8ca260]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(9216608) /* 0x8ca260 */));
    // 004dd0f4  d91c95ec568c00         -fstp dword ptr [edx*4 + 0x8c56ec]
    app->getMemory<float>(x86::reg32(9197292) /* 0x8c56ec */ + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd0fb  e830e10000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd100  d80d5ca28c00           -fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd106  d80dbc975400           -fmul dword ptr [0x5497bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543868) /* 0x5497bc */));
    // 004dd10c  d8255ca28c00           -fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd112  d91c95f0568c00         -fstp dword ptr [edx*4 + 0x8c56f0]
    app->getMemory<float>(x86::reg32(9197296) /* 0x8c56f0 */ + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd119  e812e10000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd11e  d80d5ca28c00           -fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd124  d80dbc975400           -fmul dword ptr [0x5497bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543868) /* 0x5497bc */));
    // 004dd12a  d8255ca28c00           -fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd130  d91c95687c8c00         -fstp dword ptr [edx*4 + 0x8c7c68]
    app->getMemory<float>(x86::reg32(9206888) /* 0x8c7c68 */ + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd137  e8f4e00000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd13c  d80d68a28c00           -fmul dword ptr [0x8ca268]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216616) /* 0x8ca268 */));
    // 004dd142  d80560a28c00           -fadd dword ptr [0x8ca260]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(9216608) /* 0x8ca260 */));
    // 004dd148  bb000080bf             -mov ebx, 0xbf800000
    cpu.ebx = 3212836864 /*0xbf800000*/;
    // 004dd14d  d91c956c7c8c00         -fstp dword ptr [edx*4 + 0x8c7c6c]
    app->getMemory<float>(x86::reg32(9206892) /* 0x8c7c6c */ + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd154  e8d7e00000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd159  891c95e80b8c00         -mov dword ptr [edx*4 + 0x8c0be8], ebx
    app->getMemory<x86::reg32>(x86::reg32(9178088) /* 0x8c0be8 */ + cpu.edx * 4) = cpu.ebx;
    // 004dd160  d80d5ca28c00           -fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd166  891c95ec0b8c00         -mov dword ptr [edx*4 + 0x8c0bec], ebx
    app->getMemory<x86::reg32>(x86::reg32(9178092) /* 0x8c0bec */ + cpu.edx * 4) = cpu.ebx;
    // 004dd16d  d80dbc975400           -fmul dword ptr [0x5497bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543868) /* 0x5497bc */));
    // 004dd173  891c9568318c00         -mov dword ptr [edx*4 + 0x8c3168], ebx
    app->getMemory<x86::reg32>(x86::reg32(9187688) /* 0x8c3168 */ + cpu.edx * 4) = cpu.ebx;
    // 004dd17a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004dd17c  891c956c318c00         -mov dword ptr [edx*4 + 0x8c316c], ebx
    app->getMemory<x86::reg32>(x86::reg32(9187692) /* 0x8c316c */ + cpu.edx * 4) = cpu.ebx;
    // 004dd183  30fc                   -xor ah, bh
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004dd185  30db                   +xor bl, bl
    cpu.clear_co();
    cpu.set_szp((cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl))));
    // 004dd187  882495f10b8c00         -mov byte ptr [edx*4 + 0x8c0bf1], ah
    app->getMemory<x86::reg8>(x86::reg32(9178097) /* 0x8c0bf1 */ + cpu.edx * 4) = cpu.ah;
    // 004dd18e  881c9571318c00         -mov byte ptr [edx*4 + 0x8c3171], bl
    app->getMemory<x86::reg8>(x86::reg32(9187697) /* 0x8c3171 */ + cpu.edx * 4) = cpu.bl;
    // 004dd195  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004dd196  881c95f00b8c00         -mov byte ptr [edx*4 + 0x8c0bf0], bl
    app->getMemory<x86::reg8>(x86::reg32(9178096) /* 0x8c0bf0 */ + cpu.edx * 4) = cpu.bl;
    // 004dd19d  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd1a3  881c9570318c00         -mov byte ptr [edx*4 + 0x8c3170], bl
    app->getMemory<x86::reg8>(x86::reg32(9187696) /* 0x8c3170 */ + cpu.edx * 4) = cpu.bl;
    // 004dd1aa  d91c95707c8c00         +fstp dword ptr [edx*4 + 0x8c7c70]
    app->getMemory<float>(x86::reg32(9206896) /* 0x8c7c70 */ + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd1b1  e9fafeffff             -jmp 0x4dd0b0
    goto L_0x004dd0b0;
L_0x004dd1b6:
    // 004dd1b6  e81562fcff             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004dd1bb  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004dd1bd  eb05                   -jmp 0x4dd1c4
    goto L_0x004dd1c4;
L_0x004dd1bf:
    // 004dd1bf  83fa14                 +cmp edx, 0x14
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd1c2  7d20                   -jge 0x4dd1e4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd1e4;
    }
L_0x004dd1c4:
    // 004dd1c4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004dd1c6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004dd1cd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004dd1cf  31d1                   -xor ecx, edx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004dd1d1  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004dd1d3  890c85c8088c00         -mov dword ptr [eax*4 + 0x8c08c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(9177288) /* 0x8c08c8 */ + cpu.eax * 4) = cpu.ecx;
    // 004dd1da  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004dd1db  891c85580a8c00         -mov dword ptr [eax*4 + 0x8c0a58], ebx
    app->getMemory<x86::reg32>(x86::reg32(9177688) /* 0x8c0a58 */ + cpu.eax * 4) = cpu.ebx;
    // 004dd1e2  ebdb                   -jmp 0x4dd1bf
    goto L_0x004dd1bf;
L_0x004dd1e4:
    // 004dd1e4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004dd1e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd1e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd1e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd1e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd1ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd1eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd1ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dd1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dd1f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dd1f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dd1f2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dd1f4  f60584367d0001         +test byte ptr [0x7d3684], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8205956) /* 0x7d3684 */) & 1 /*0x1*/));
    // 004dd1fb  742e                   -je 0x4dd22b
    if (cpu.flags.zf)
    {
        goto L_0x004dd22b;
    }
    // 004dd1fd  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004dd202  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004dd205  e876510100             -call 0x4f2380
    cpu.esp -= 4;
    sub_4f2380(app, cpu);
    if (cpu.terminate) return;
    // 004dd20a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004dd20c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004dd20f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004dd211  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004dd214  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004dd216  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004dd219  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dd21b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dd21e  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004dd221  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004dd223  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004dd226  a344a28c00             -mov dword ptr [0x8ca244], eax
    app->getMemory<x86::reg32>(x86::reg32(9216580) /* 0x8ca244 */) = cpu.eax;
L_0x004dd22b:
    // 004dd22b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd22c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd22d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dd230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dd230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dd231  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dd232  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dd233  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dd234  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dd235  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dd236  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dd238  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004dd23a  8b0d2ca28c00           -mov ecx, dword ptr [0x8ca22c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */);
    // 004dd240  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004dd243  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004dd245  0f84d7000000           -je 0x4dd322
    if (cpu.flags.zf)
    {
        goto L_0x004dd322;
    }
    // 004dd24b  e8103bf4ff             -call 0x420d60
    cpu.esp -= 4;
    sub_420d60(app, cpu);
    if (cpu.terminate) return;
    // 004dd250  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004dd252  0f8598000000           -jne 0x4dd2f0
    if (!cpu.flags.zf)
    {
        goto L_0x004dd2f0;
    }
    // 004dd258  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004dd25a:
    // 004dd25a  3b1d34a28c00           +cmp ebx, dword ptr [0x8ca234]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216564) /* 0x8ca234 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd260  0f8d8a000000           -jge 0x4dd2f0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd2f0;
    }
    // 004dd266  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004dd26d  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004dd26f  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004dd272  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004dd274  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 004dd277  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004dd279  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004dd280  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004dd282  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004dd285  8d0c07                 -lea ecx, [edi + eax]
    cpu.ecx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004dd288  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 004dd28a  88a1f10b8c00           -mov byte ptr [ecx + 0x8c0bf1], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9178097) /* 0x8c0bf1 */) = cpu.ah;
    // 004dd290  e89bdf0000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd295  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd29b  d80dc0975400           +fmul dword ptr [0x5497c0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543872) /* 0x5497c0 */));
    // 004dd2a1  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd2a7  d84208                 +fadd dword ptr [edx + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004dd2aa  d999e8568c00           +fstp dword ptr [ecx + 0x8c56e8]
    app->getMemory<float>(cpu.ecx + x86::reg32(9197288) /* 0x8c56e8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd2b0  e87bdf0000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd2b5  d80d68a28c00           +fmul dword ptr [0x8ca268]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216616) /* 0x8ca268 */));
    // 004dd2bb  d80560a28c00           +fadd dword ptr [0x8ca260]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(9216608) /* 0x8ca260 */));
    // 004dd2c1  d8420c                 +fadd dword ptr [edx + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004dd2c4  d999ec568c00           +fstp dword ptr [ecx + 0x8c56ec]
    app->getMemory<float>(cpu.ecx + x86::reg32(9197292) /* 0x8c56ec */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd2ca  e861df0000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd2cf  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd2d5  d80dc0975400           +fmul dword ptr [0x5497c0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543872) /* 0x5497c0 */));
    // 004dd2db  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd2e1  d84210                 +fadd dword ptr [edx + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004dd2e4  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004dd2e5  d999f0568c00           +fstp dword ptr [ecx + 0x8c56f0]
    app->getMemory<float>(cpu.ecx + x86::reg32(9197296) /* 0x8c56f0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd2eb  e96affffff             -jmp 0x4dd25a
    goto L_0x004dd25a;
L_0x004dd2f0:
    // 004dd2f0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004dd2f2:
    // 004dd2f2  3b1578a28c00           +cmp edx, dword ptr [0x8ca278]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216632) /* 0x8ca278 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd2f8  7d28                   -jge 0x4dd322
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd322;
    }
    // 004dd2fa  8d1cb500000000         -lea ebx, [esi*4]
    cpu.ebx = x86::reg32(cpu.esi * 4);
    // 004dd301  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004dd303  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004dd305  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004dd30c  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004dd30f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004dd311  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004dd313  31d1                   -xor ecx, edx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004dd315  c1e304                 +shl ebx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004dd318  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004dd319  898c83c8088c00         -mov dword ptr [ebx + eax*4 + 0x8c08c8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(9177288) /* 0x8c08c8 */ + cpu.eax * 4) = cpu.ecx;
    // 004dd320  ebd0                   -jmp 0x4dd2f2
    goto L_0x004dd2f2;
L_0x004dd322:
    // 004dd322  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd323  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd324  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd325  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd326  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd327  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd328  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4dd330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dd330  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dd331  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dd332  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dd333  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dd334  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dd335  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dd336  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dd338  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dd33b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dd33d  a1f0a18c00             -mov eax, dword ptr [0x8ca1f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216496) /* 0x8ca1f0 */);
    // 004dd342  8b1df4a18c00           -mov ebx, dword ptr [0x8ca1f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(9216500) /* 0x8ca1f4 */);
    // 004dd348  8b1548a28c00           -mov edx, dword ptr [0x8ca248]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216584) /* 0x8ca248 */);
    // 004dd34e  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004dd351  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004dd356  8b3df8a18c00           -mov edi, dword ptr [0x8ca1f8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(9216504) /* 0x8ca1f8 */);
    // 004dd35c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004dd35e  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dd361  8b35fca18c00           -mov esi, dword ptr [0x8ca1fc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(9216508) /* 0x8ca1fc */);
    // 004dd367  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004dd369  0f8453000000           -je 0x4dd3c2
    if (cpu.flags.zf)
    {
        goto L_0x004dd3c2;
    }
    // 004dd36f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004dd371  744f                   -je 0x4dd3c2
    if (cpu.flags.zf)
    {
        goto L_0x004dd3c2;
    }
    // 004dd373  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004dd375  744b                   -je 0x4dd3c2
    if (cpu.flags.zf)
    {
        goto L_0x004dd3c2;
    }
    // 004dd377  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004dd379  7447                   -je 0x4dd3c2
    if (cpu.flags.zf)
    {
        goto L_0x004dd3c2;
    }
    // 004dd37b  39d0                   +cmp eax, edx
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
    // 004dd37d  7c43                   -jl 0x4dd3c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004dd3c2;
    }
    // 004dd37f  39d8                   +cmp eax, ebx
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
    // 004dd381  7d15                   -jge 0x4dd398
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd398;
    }
    // 004dd383  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004dd385  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004dd387  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004dd38a  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dd38d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dd38f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dd392  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004dd394  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dd396  eb2c                   -jmp 0x4dd3c4
    goto L_0x004dd3c4;
L_0x004dd398:
    // 004dd398  39f8                   +cmp eax, edi
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
    // 004dd39a  7d04                   -jge 0x4dd3a0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd3a0;
    }
    // 004dd39c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004dd39e  eb24                   -jmp 0x4dd3c4
    goto L_0x004dd3c4;
L_0x004dd3a0:
    // 004dd3a0  39f0                   +cmp eax, esi
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
    // 004dd3a2  7d14                   -jge 0x4dd3b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd3b8;
    }
    // 004dd3a4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004dd3a6  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004dd3a8  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004dd3ab  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004dd3ad  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dd3af  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dd3b2  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dd3b4  29c1                   +sub ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004dd3b6  eb0a                   -jmp 0x4dd3c2
    goto L_0x004dd3c2;
L_0x004dd3b8:
    // 004dd3b8  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004dd3bd  a348a28c00             -mov dword ptr [0x8ca248], eax
    app->getMemory<x86::reg32>(x86::reg32(9216584) /* 0x8ca248 */) = cpu.eax;
L_0x004dd3c2:
    // 004dd3c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004dd3c4:
    // 004dd3c4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004dd3c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd3c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd3c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd3c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd3ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd3cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd3cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dd3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dd3d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dd3d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dd3d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dd3d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dd3d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dd3d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dd3d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dd3d8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dd3db  8b353aa28c00           -mov esi, dword ptr [0x8ca23a]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(9216570) /* 0x8ca23a */);
    // 004dd3e1  8b1544a28c00           -mov edx, dword ptr [0x8ca244]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216580) /* 0x8ca244 */);
    // 004dd3e7  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004dd3ea  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004dd3ec  8b153ca28c00           -mov edx, dword ptr [0x8ca23c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216572) /* 0x8ca23c */);
    // 004dd3f2  8b0d44a28c00           -mov ecx, dword ptr [0x8ca244]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(9216580) /* 0x8ca244 */);
    // 004dd3f8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004dd3fb  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004dd3fd  8b0d3ea28c00           -mov ecx, dword ptr [0x8ca23e]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(9216574) /* 0x8ca23e */);
    // 004dd403  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004dd406  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004dd409  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004dd40c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004dd40e  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004dd410  39d6                   +cmp esi, edx
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
    // 004dd412  7508                   -jne 0x4dd41c
    if (!cpu.flags.zf)
    {
        goto L_0x004dd41c;
    }
    // 004dd414  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004dd416  0f848d000000           -je 0x4dd4a9
    if (cpu.flags.zf)
    {
        goto L_0x004dd4a9;
    }
L_0x004dd41c:
    // 004dd41c  39d6                   +cmp esi, edx
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
    // 004dd41e  7e14                   -jle 0x4dd434
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dd434;
    }
    // 004dd420  39d0                   +cmp eax, edx
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
    // 004dd422  7d06                   -jge 0x4dd42a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd42a;
    }
    // 004dd424  030540d95d00           -add eax, dword ptr [0x5dd940]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */)));
L_0x004dd42a:
    // 004dd42a  8b3d40d95d00           -mov edi, dword ptr [0x5dd940]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 004dd430  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004dd432  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
L_0x004dd434:
    // 004dd434  39f0                   +cmp eax, esi
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
    // 004dd436  7c04                   -jl 0x4dd43c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004dd43c;
    }
    // 004dd438  39d0                   +cmp eax, edx
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
    // 004dd43a  7e07                   -jle 0x4dd443
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dd443;
    }
L_0x004dd43c:
    // 004dd43c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004dd43e  e96b000000             -jmp 0x4dd4ae
    goto L_0x004dd4ae;
L_0x004dd443:
    // 004dd443  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004dd445  7462                   -je 0x4dd4a9
    if (cpu.flags.zf)
    {
        goto L_0x004dd4a9;
    }
    // 004dd447  3b45fc                 +cmp eax, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd44a  7e04                   -jle 0x4dd450
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dd450;
    }
    // 004dd44c  39d8                   +cmp eax, ebx
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
    // 004dd44e  7c59                   -jl 0x4dd4a9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004dd4a9;
    }
L_0x004dd450:
    // 004dd450  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dd453  39f0                   +cmp eax, esi
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
    // 004dd455  7d29                   -jge 0x4dd480
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd480;
    }
    // 004dd457  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004dd459  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004dd45b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dd45d  8b1534a28c00           -mov edx, dword ptr [0x8ca234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216564) /* 0x8ca234 */);
    // 004dd463  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004dd466  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dd468  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dd46b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dd46d  8b1534a28c00           -mov edx, dword ptr [0x8ca234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216564) /* 0x8ca234 */);
    // 004dd473  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004dd475  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dd477  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004dd479  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd47a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd47b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd47c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd47d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd47e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd47f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dd480:
    // 004dd480  39d8                   +cmp eax, ebx
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
    // 004dd482  7e25                   -jle 0x4dd4a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dd4a9;
    }
    // 004dd484  8b1534a28c00           -mov edx, dword ptr [0x8ca234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216564) /* 0x8ca234 */);
    // 004dd48a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004dd48c  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004dd48f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dd491  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dd494  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dd496  8b1534a28c00           -mov edx, dword ptr [0x8ca234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216564) /* 0x8ca234 */);
    // 004dd49c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004dd49e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dd4a0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004dd4a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dd4a9:
    // 004dd4a9  a134a28c00             -mov eax, dword ptr [0x8ca234]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216564) /* 0x8ca234 */);
L_0x004dd4ae:
    // 004dd4ae  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004dd4b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4dd4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dd4c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dd4c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dd4c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dd4c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dd4c4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dd4c6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004dd4c8  833d34a28c0000         +cmp dword ptr [0x8ca234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(9216564) /* 0x8ca234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd4cf  742c                   -je 0x4dd4fd
    if (cpu.flags.zf)
    {
        goto L_0x004dd4fd;
    }
    // 004dd4d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004dd4d3  7428                   -je 0x4dd4fd
    if (cpu.flags.zf)
    {
        goto L_0x004dd4fd;
    }
    // 004dd4d5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004dd4d7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004dd4da  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004dd4dc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004dd4df  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004dd4e1  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004dd4e4  8b1d34a28c00           -mov ebx, dword ptr [0x8ca234]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(9216564) /* 0x8ca234 */);
    // 004dd4ea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dd4ec  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dd4ef  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dd4f1  89048d88425600         -mov dword ptr [ecx*4 + 0x564288], eax
    app->getMemory<x86::reg32>(x86::reg32(5653128) /* 0x564288 */ + cpu.ecx * 4) = cpu.eax;
    // 004dd4f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd4fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dd4fd:
    // 004dd4fd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004dd4ff  89348d88425600         -mov dword ptr [ecx*4 + 0x564288], esi
    app->getMemory<x86::reg32>(x86::reg32(5653128) /* 0x564288 */ + cpu.ecx * 4) = cpu.esi;
    // 004dd506  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd507  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd508  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd509  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd50a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4dd510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dd510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dd511  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dd512  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dd513  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dd514  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dd515  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dd516  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dd518  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004dd51a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004dd51d  8b88b8105e00           -mov ecx, dword ptr [eax + 0x5e10b8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6164664) /* 0x5e10b8 */);
    // 004dd523  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004dd525  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004dd527  740a                   -je 0x4dd533
    if (cpu.flags.zf)
    {
        goto L_0x004dd533;
    }
    // 004dd529  7404                   -je 0x4dd52f
    if (cpu.flags.zf)
    {
        goto L_0x004dd52f;
    }
    // 004dd52b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004dd52d  eb14                   -jmp 0x4dd543
    goto L_0x004dd543;
L_0x004dd52f:
    // 004dd52f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004dd531  eb10                   -jmp 0x4dd543
    goto L_0x004dd543;
L_0x004dd533:
    // 004dd533  8bb8b0105e00           -mov edi, dword ptr [eax + 0x5e10b0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6164656) /* 0x5e10b0 */);
    // 004dd539  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004dd53b  7404                   -je 0x4dd541
    if (cpu.flags.zf)
    {
        goto L_0x004dd541;
    }
    // 004dd53d  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004dd53f  eb02                   -jmp 0x4dd543
    goto L_0x004dd543;
L_0x004dd541:
    // 004dd541  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004dd543:
    // 004dd543  83f804                 +cmp eax, 4
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
    // 004dd546  7f3f                   -jg 0x4dd587
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004dd587;
    }
    // 004dd548  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004dd54f  8b88b8105e00           -mov ecx, dword ptr [eax + 0x5e10b8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6164664) /* 0x5e10b8 */);
    // 004dd555  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004dd557  740a                   -je 0x4dd563
    if (cpu.flags.zf)
    {
        goto L_0x004dd563;
    }
    // 004dd559  7404                   -je 0x4dd55f
    if (cpu.flags.zf)
    {
        goto L_0x004dd55f;
    }
    // 004dd55b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004dd55d  eb14                   -jmp 0x4dd573
    goto L_0x004dd573;
L_0x004dd55f:
    // 004dd55f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004dd561  eb10                   -jmp 0x4dd573
    goto L_0x004dd573;
L_0x004dd563:
    // 004dd563  8bb8b0105e00           -mov edi, dword ptr [eax + 0x5e10b0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6164656) /* 0x5e10b0 */);
    // 004dd569  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004dd56b  7404                   -je 0x4dd571
    if (cpu.flags.zf)
    {
        goto L_0x004dd571;
    }
    // 004dd56d  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004dd56f  eb02                   -jmp 0x4dd573
    goto L_0x004dd573;
L_0x004dd571:
    // 004dd571  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004dd573:
    // 004dd573  83f802                 +cmp eax, 2
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
    // 004dd576  7c0f                   -jl 0x4dd587
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004dd587;
    }
    // 004dd578  833c95a0c4790000       +cmp dword ptr [edx*4 + 0x79c4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7980192) /* 0x79c4a0 */ + cpu.edx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd580  7405                   -je 0x4dd587
    if (cpu.flags.zf)
    {
        goto L_0x004dd587;
    }
    // 004dd582  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004dd587:
    // 004dd587  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004dd58e  3bb0b4a28c00           +cmp esi, dword ptr [eax + 0x8ca2b4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(9216692) /* 0x8ca2b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd594  7509                   -jne 0x4dd59f
    if (!cpu.flags.zf)
    {
        goto L_0x004dd59f;
    }
    // 004dd596  83b8f42f550000         +cmp dword ptr [eax + 0x552ff4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5582836) /* 0x552ff4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd59d  7432                   -je 0x4dd5d1
    if (cpu.flags.zf)
    {
        goto L_0x004dd5d1;
    }
L_0x004dd59f:
    // 004dd59f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004dd5a1:
    // 004dd5a1  3b1d34a28c00           +cmp ebx, dword ptr [0x8ca234]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216564) /* 0x8ca234 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd5a7  7d28                   -jge 0x4dd5d1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd5d1;
    }
    // 004dd5a9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004dd5b0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004dd5b2  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004dd5b5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004dd5b7  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 004dd5ba  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004dd5bc  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004dd5c3  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004dd5c5  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 004dd5c7  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004dd5c8  888c87f10b8c00         -mov byte ptr [edi + eax*4 + 0x8c0bf1], cl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(9178097) /* 0x8c0bf1 */ + cpu.eax * 4) = cpu.cl;
    // 004dd5cf  ebd0                   -jmp 0x4dd5a1
    goto L_0x004dd5a1;
L_0x004dd5d1:
    // 004dd5d1  893495b4a28c00         -mov dword ptr [edx*4 + 0x8ca2b4], esi
    app->getMemory<x86::reg32>(x86::reg32(9216692) /* 0x8ca2b4 */ + cpu.edx * 4) = cpu.esi;
    // 004dd5d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd5d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd5da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd5db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd5dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd5dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd5de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4dd5e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dd5e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dd5e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dd5e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dd5e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dd5e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dd5e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dd5e7  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004dd5ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004dd5ec  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 004dd5ef  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004dd5f2  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004dd5f5  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004dd5fc  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004dd601  2b82e00b8c00           -sub eax, dword ptr [edx + 0x8c0be0]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(9178080) /* 0x8c0be0 */)));
    // 004dd607  83f801                 +cmp eax, 1
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
    // 004dd60a  0f8e16030000           -jle 0x4dd926
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dd926;
    }
    // 004dd610  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004dd612  e84937f4ff             -call 0x420d60
    cpu.esp -= 4;
    sub_420d60(app, cpu);
    if (cpu.terminate) return;
    // 004dd617  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004dd61a  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004dd61f  8982e00b8c00           -mov dword ptr [edx + 0x8c0be0], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(9178080) /* 0x8c0be0 */) = cpu.eax;
    // 004dd625  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004dd627:
    // 004dd627  3b1578a28c00           +cmp edx, dword ptr [0x8ca278]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216632) /* 0x8ca278 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd62d  7d38                   -jge 0x4dd667
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd667;
    }
    // 004dd62f  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004dd632  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 004dd639  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004dd63b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004dd642  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004dd645  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004dd647  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004dd649  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004dd64c  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004dd64f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004dd651  8bb8c8088c00           -mov edi, dword ptr [eax + 0x8c08c8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(9177288) /* 0x8c08c8 */);
    // 004dd657  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004dd659  7409                   -je 0x4dd664
    if (cpu.flags.zf)
    {
        goto L_0x004dd664;
    }
    // 004dd65b  8d4fff                 -lea ecx, [edi - 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004dd65e  8988c8088c00           -mov dword ptr [eax + 0x8c08c8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(9177288) /* 0x8c08c8 */) = cpu.ecx;
L_0x004dd664:
    // 004dd664  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004dd665  ebc0                   -jmp 0x4dd627
    goto L_0x004dd627;
L_0x004dd667:
    // 004dd667  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004dd66a  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004dd671  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004dd673  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004dd676  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004dd678  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004dd67b  bae8568c00             -mov edx, 0x8c56e8
    cpu.edx = 9197288 /*0x8c56e8*/;
    // 004dd680  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004dd682  bb6ca28c00             -mov ebx, 0x8ca26c
    cpu.ebx = 9216620 /*0x8ca26c*/;
    // 004dd687  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004dd689  a134a28c00             -mov eax, dword ptr [0x8ca234]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216564) /* 0x8ca234 */);
    // 004dd68e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004dd690  e81b290000             -call 0x4dffb0
    cpu.esp -= 4;
    sub_4dffb0(app, cpu);
    if (cpu.terminate) return;
    // 004dd695  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004dd697:
    // 004dd697  3b5de8                 +cmp ebx, dword ptr [ebp - 0x18]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd69a  0f8d86020000           -jge 0x4dd926
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dd926;
    }
    // 004dd6a0  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004dd6a3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004dd6aa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004dd6ac  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004dd6af  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004dd6b1  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 004dd6b4  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004dd6b6  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004dd6bd  b9e80b8c00             -mov ecx, 0x8c0be8
    cpu.ecx = 9178088 /*0x8c0be8*/;
    // 004dd6c2  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004dd6c4  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004dd6c6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004dd6c9  81c7e8568c00           -add edi, 0x8c56e8
    (cpu.edi) += x86::reg32(x86::sreg32(9197288 /*0x8c56e8*/));
    // 004dd6cf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004dd6d1  8d1407                 -lea edx, [edi + eax]
    cpu.edx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004dd6d4  a12ca28c00             -mov eax, dword ptr [0x8ca22c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */);
    // 004dd6d9  83f802                 +cmp eax, 2
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
    // 004dd6dc  7551                   -jne 0x4dd72f
    if (!cpu.flags.zf)
    {
        goto L_0x004dd72f;
    }
    // 004dd6de  80790800               +cmp byte ptr [ecx + 8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004dd6e2  754b                   -jne 0x4dd72f
    if (!cpu.flags.zf)
    {
        goto L_0x004dd72f;
    }
    // 004dd6e4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004dd6e6  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004dd6eb  c1e708                 -shl edi, 8
    cpu.edi <<= 8 /*0x8*/ % 32;
    // 004dd6ee  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004dd6f1  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004dd6f3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004dd6f5  e8864c0100             -call 0x4f2380
    cpu.esp -= 4;
    sub_4f2380(app, cpu);
    if (cpu.terminate) return;
    // 004dd6fa  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004dd6fd  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004dd700  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004dd703  dc0dc4975400           -fmul qword ptr [0x5497c4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5543876) /* 0x5497c4 */));
    // 004dd709  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004dd70b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dd70d  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004dd70f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004dd711  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd713  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd715  e8d64c0100             -call 0x4f23f0
    cpu.esp -= 4;
    sub_4f23f0(app, cpu);
    if (cpu.terminate) return;
    // 004dd71a  c1f804                 +sar eax, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004dd71d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004dd720  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004dd723  dc0dc4975400           +fmul qword ptr [0x5497c4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5543876) /* 0x5497c4 */));
    // 004dd729  d84208                 +fadd dword ptr [edx + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004dd72c  d95a08                 +fstp dword ptr [edx + 8]
    app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004dd72f:
    // 004dd72f  d902                   +fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004dd731  d94204                 +fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004dd734  d94208                 +fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004dd737  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dd739  d86608                 +fsub dword ptr [esi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 004dd73c  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dd73e  d8660c                 +fsub dword ptr [esi + 0xc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */));
    // 004dd741  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dd743  d86610                 +fsub dword ptr [esi + 0x10]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */));
    // 004dd746  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dd748  d95dd4                 +fstp dword ptr [ebp - 0x2c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd74b  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dd74d  d95dd8                 +fstp dword ptr [ebp - 0x28]
    app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd750  d95ddc                 +fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd753  d945d8                 +fld dword ptr [ebp - 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 004dd756  d81d60a28c00           +fcomp dword ptr [0x8ca260]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(9216608) /* 0x8ca260 */)));
    cpu.fpu.pop();
    // 004dd75c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd75e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd75f  0f8262000000           -jb 0x4dd7c7
    if (cpu.flags.cf)
    {
        goto L_0x004dd7c7;
    }
    // 004dd765  d945d8                 +fld dword ptr [ebp - 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 004dd768  d81d64a28c00           +fcomp dword ptr [0x8ca264]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(9216612) /* 0x8ca264 */)));
    cpu.fpu.pop();
    // 004dd76e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd770  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd771  7754                   -ja 0x4dd7c7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004dd7c7;
    }
    // 004dd773  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004dd775  d85dd4                 +fcomp dword ptr [ebp - 0x2c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    cpu.fpu.pop();
    // 004dd778  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd77a  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd77b  760a                   -jbe 0x4dd787
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004dd787;
    }
    // 004dd77d  d945d4                 +fld dword ptr [ebp - 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    // 004dd780  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dd782  d95df4                 +fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd785  eb06                   -jmp 0x4dd78d
    goto L_0x004dd78d;
L_0x004dd787:
    // 004dd787  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004dd78a  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x004dd78d:
    // 004dd78d  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 004dd790  d81d5ca28c00           +fcomp dword ptr [0x8ca25c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */)));
    cpu.fpu.pop();
    // 004dd796  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd798  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd799  772c                   -ja 0x4dd7c7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004dd7c7;
    }
    // 004dd79b  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004dd79d  d85ddc                 +fcomp dword ptr [ebp - 0x24]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    cpu.fpu.pop();
    // 004dd7a0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd7a2  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd7a3  760a                   -jbe 0x4dd7af
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004dd7af;
    }
    // 004dd7a5  d945dc                 +fld dword ptr [ebp - 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    // 004dd7a8  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dd7aa  d95df0                 +fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd7ad  eb06                   -jmp 0x4dd7b5
    goto L_0x004dd7b5;
L_0x004dd7af:
    // 004dd7af  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004dd7b2  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
L_0x004dd7b5:
    // 004dd7b5  d945f0                 +fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 004dd7b8  d81d5ca28c00           +fcomp dword ptr [0x8ca25c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */)));
    cpu.fpu.pop();
    // 004dd7be  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd7c0  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd7c1  0f8659010000           -jbe 0x4dd920
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004dd920;
    }
L_0x004dd7c7:
    // 004dd7c7  8a45ec                 -mov al, byte ptr [ebp - 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004dd7ca  884108                 -mov byte ptr [ecx + 8], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 004dd7cd  d945d4                 +fld dword ptr [ebp - 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    // 004dd7d0  d81d5ca28c00           +fcomp dword ptr [0x8ca25c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */)));
    cpu.fpu.pop();
    // 004dd7d6  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd7d8  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd7d9  7611                   -jbe 0x4dd7ec
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004dd7ec;
    }
    // 004dd7db  c6410900               -mov byte ptr [ecx + 9], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 0 /*0x0*/;
    // 004dd7df  d9055ca28c00           +fld dword ptr [0x8ca25c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */)));
    // 004dd7e5  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dd7e7  d95dd4                 +fstp dword ptr [ebp - 0x2c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd7ea  eb1c                   -jmp 0x4dd808
    goto L_0x004dd808;
L_0x004dd7ec:
    // 004dd7ec  d9055ca28c00           +fld dword ptr [0x8ca25c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */)));
    // 004dd7f2  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dd7f4  d85dd4                 +fcomp dword ptr [ebp - 0x2c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    cpu.fpu.pop();
    // 004dd7f7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd7f9  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd7fa  763a                   -jbe 0x4dd836
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004dd836;
    }
    // 004dd7fc  c6410900               -mov byte ptr [ecx + 9], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 0 /*0x0*/;
    // 004dd800  a15ca28c00             -mov eax, dword ptr [0x8ca25c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216604) /* 0x8ca25c */);
    // 004dd805  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
L_0x004dd808:
    // 004dd808  e823da0000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd80d  d80d68a28c00           +fmul dword ptr [0x8ca268]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216616) /* 0x8ca268 */));
    // 004dd813  d80560a28c00           +fadd dword ptr [0x8ca260]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(9216608) /* 0x8ca260 */));
    // 004dd819  d95dd8                 +fstp dword ptr [ebp - 0x28]
    app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd81c  e80fda0000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd821  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd827  d80dcc975400           +fmul dword ptr [0x5497cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543884) /* 0x5497cc */));
    // 004dd82d  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd833  d95ddc                 +fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004dd836:
    // 004dd836  d945dc                 +fld dword ptr [ebp - 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    // 004dd839  d81d5ca28c00           +fcomp dword ptr [0x8ca25c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */)));
    cpu.fpu.pop();
    // 004dd83f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd841  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd842  7611                   -jbe 0x4dd855
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004dd855;
    }
    // 004dd844  c6410900               -mov byte ptr [ecx + 9], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 0 /*0x0*/;
    // 004dd848  d9055ca28c00           +fld dword ptr [0x8ca25c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */)));
    // 004dd84e  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dd850  d95ddc                 +fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd853  eb1c                   -jmp 0x4dd871
    goto L_0x004dd871;
L_0x004dd855:
    // 004dd855  d9055ca28c00           +fld dword ptr [0x8ca25c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */)));
    // 004dd85b  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dd85d  d85ddc                 +fcomp dword ptr [ebp - 0x24]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    cpu.fpu.pop();
    // 004dd860  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd862  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd863  763a                   -jbe 0x4dd89f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004dd89f;
    }
    // 004dd865  c6410900               -mov byte ptr [ecx + 9], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 0 /*0x0*/;
    // 004dd869  a15ca28c00             -mov eax, dword ptr [0x8ca25c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216604) /* 0x8ca25c */);
    // 004dd86e  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
L_0x004dd871:
    // 004dd871  e8bad90000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd876  d80d68a28c00           +fmul dword ptr [0x8ca268]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216616) /* 0x8ca268 */));
    // 004dd87c  d80560a28c00           +fadd dword ptr [0x8ca260]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(9216608) /* 0x8ca260 */));
    // 004dd882  d95dd8                 +fstp dword ptr [ebp - 0x28]
    app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd885  e8a6d90000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd88a  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd890  d80dcc975400           +fmul dword ptr [0x5497cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543884) /* 0x5497cc */));
    // 004dd896  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd89c  d95ddc                 +fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004dd89f:
    // 004dd89f  d945d8                 +fld dword ptr [ebp - 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 004dd8a2  d81d64a28c00           +fcomp dword ptr [0x8ca264]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(9216612) /* 0x8ca264 */)));
    cpu.fpu.pop();
    // 004dd8a8  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd8aa  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd8ab  760b                   -jbe 0x4dd8b8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004dd8b8;
    }
    // 004dd8ad  c6410900               -mov byte ptr [ecx + 9], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 0 /*0x0*/;
    // 004dd8b1  a160a28c00             -mov eax, dword ptr [0x8ca260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216608) /* 0x8ca260 */);
    // 004dd8b6  eb17                   -jmp 0x4dd8cf
    goto L_0x004dd8cf;
L_0x004dd8b8:
    // 004dd8b8  d945d8                 +fld dword ptr [ebp - 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 004dd8bb  d81d60a28c00           +fcomp dword ptr [0x8ca260]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(9216608) /* 0x8ca260 */)));
    cpu.fpu.pop();
    // 004dd8c1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004dd8c3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004dd8c4  7340                   -jae 0x4dd906
    if (!cpu.flags.cf)
    {
        goto L_0x004dd906;
    }
    // 004dd8c6  c6410900               -mov byte ptr [ecx + 9], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 0 /*0x0*/;
    // 004dd8ca  a164a28c00             -mov eax, dword ptr [0x8ca264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216612) /* 0x8ca264 */);
L_0x004dd8cf:
    // 004dd8cf  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 004dd8d2  e859d90000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd8d7  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd8dd  d80dcc975400           +fmul dword ptr [0x5497cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543884) /* 0x5497cc */));
    // 004dd8e3  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd8e9  d95dd4                 +fstp dword ptr [ebp - 0x2c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd8ec  e83fd90000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dd8f1  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd8f7  d80dcc975400           +fmul dword ptr [0x5497cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543884) /* 0x5497cc */));
    // 004dd8fd  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004dd903  d95ddc                 +fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004dd906:
    // 004dd906  d94608                 +fld dword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 004dd909  d845d4                 +fadd dword ptr [ebp - 0x2c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */));
    // 004dd90c  d91a                   +fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd90e  d9460c                 +fld dword ptr [esi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 004dd911  d845d8                 +fadd dword ptr [ebp - 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */));
    // 004dd914  d95a04                 +fstp dword ptr [edx + 4]
    app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd917  d94610                 +fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004dd91a  d845dc                 +fadd dword ptr [ebp - 0x24]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */));
    // 004dd91d  d95a08                 +fstp dword ptr [edx + 8]
    app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004dd920:
    // 004dd920  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004dd921  e971fdffff             -jmp 0x4dd697
    goto L_0x004dd697;
L_0x004dd926:
    // 004dd926  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004dd928  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd929  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd92a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd92b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd92c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dd92d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dd930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dd930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dd931  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dd932  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dd933  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dd934  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dd935  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dd936  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dd938  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004dd93b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004dd93d  8b15a0367d00           -mov edx, dword ptr [0x7d36a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205984) /* 0x7d36a0 */);
    // 004dd943  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004dd946  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004dd948  0f85e2010000           -jne 0x4ddb30
    if (!cpu.flags.zf)
    {
        goto L_0x004ddb30;
    }
    // 004dd94e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004dd950:
    // 004dd950  3b0d78a28c00           +cmp ecx, dword ptr [0x8ca278]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216632) /* 0x8ca278 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd956  0f8dd4010000           -jge 0x4ddb30
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ddb30;
    }
    // 004dd95c  8d1cbd00000000         -lea ebx, [edi*4]
    cpu.ebx = x86::reg32(cpu.edi * 4);
    // 004dd963  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004dd965  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004dd968  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004dd96f  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004dd971  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004dd973  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004dd976  83bc83c8088c0000       +cmp dword ptr [ebx + eax*4 + 0x8c08c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(9177288) /* 0x8c08c8 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dd97e  0f85a6010000           -jne 0x4ddb2a
    if (!cpu.flags.zf)
    {
        goto L_0x004ddb2a;
    }
    // 004dd984  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004dd987  8d451c                 -lea eax, [ebp + 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004dd98a  8d5644                 -lea edx, [esi + 0x44]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004dd98d  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004dd98f  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004dd991  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004dd993  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004dd996  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004dd998  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004dd99b  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dd99d  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004dd9a0  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004dd9a3  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004dd9a6  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004dd9a9  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004dd9ac  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004dd9af  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dd9b1  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004dd9b3  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004dd9b5  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004dd9b7  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004dd9ba  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004dd9bd  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004dd9c0  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004dd9c3  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004dd9c6  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004dd9c9  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dd9cb  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004dd9cd  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004dd9cf  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004dd9d1  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004dd9d4  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd9d6  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd9d9  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd9dc  d945cc                 -fld dword ptr [ebp - 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */)));
    // 004dd9df  d84638                 -fadd dword ptr [esi + 0x38]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(56) /* 0x38 */));
    // 004dd9e2  d945d0                 -fld dword ptr [ebp - 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */)));
    // 004dd9e5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dd9e7  d95dcc                 -fstp dword ptr [ebp - 0x34]
    app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd9ea  d8463c                 -fadd dword ptr [esi + 0x3c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(60) /* 0x3c */));
    // 004dd9ed  d945d4                 -fld dword ptr [ebp - 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    // 004dd9f0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dd9f2  d95dd0                 -fstp dword ptr [ebp - 0x30]
    app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd9f5  d84640                 -fadd dword ptr [esi + 0x40]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(64) /* 0x40 */));
    // 004dd9f8  d95dd4                 -fstp dword ptr [ebp - 0x2c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dd9fb  8b5dd4                 -mov ebx, dword ptr [ebp - 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004dd9fe  f7c3ffffff7f           +test ebx, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & 2147483647 /*0x7fffffff*/));
    // 004dda04  740c                   -je 0x4dda12
    if (cpu.flags.zf)
    {
        goto L_0x004dda12;
    }
    // 004dda06  d945d4                 +fld dword ptr [ebp - 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    // 004dda09  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004dda0b  def1                   +fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004dda0d  dd5de0                 +fstp qword ptr [ebp - 0x20]
    app->getMemory<double>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dda10  eb0d                   -jmp 0x4dda1f
    goto L_0x004dda1f;
L_0x004dda12:
    // 004dda12  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004dda14  b8e0ffef40             -mov eax, 0x40efffe0
    cpu.eax = 1089470432 /*0x40efffe0*/;
    // 004dda19  8975e0                 -mov dword ptr [ebp - 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.esi;
    // 004dda1c  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
L_0x004dda1f:
    // 004dda1f  a17ca28c00             -mov eax, dword ptr [0x8ca27c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216636) /* 0x8ca27c */);
    // 004dda24  dd45e0                 -fld qword ptr [ebp - 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 004dda27  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004dda2a  d95df4                 -fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dda2d  83f801                 +cmp eax, 1
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
    // 004dda30  7e04                   -jle 0x4dda36
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dda36;
    }
    // 004dda32  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004dda34  eb05                   -jmp 0x4dda3b
    goto L_0x004dda3b;
L_0x004dda36:
    // 004dda36  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004dda3b:
    // 004dda3b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004dda3d  e846330000             -call 0x4e0d88
    cpu.esp -= 4;
    sub_4e0d88(app, cpu);
    if (cpu.terminate) return;
    // 004dda42  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004dda44  d945f4                 -fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 004dda47  d945cc                 -fld dword ptr [ebp - 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */)));
    // 004dda4a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004dda4c  d945d0                 -fld dword ptr [ebp - 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */)));
    // 004dda4f  8d34bd00000000         -lea esi, [edi*4]
    cpu.esi = x86::reg32(cpu.edi * 4);
    // 004dda56  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004dda58  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004dda5a  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004dda5d  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004dda5f  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004dda66  8b1d7ca28c00           -mov ebx, dword ptr [0x8ca27c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(9216636) /* 0x8ca27c */);
    // 004dda6c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004dda6e  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004dda71  29d3                   +sub ebx, edx
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
    // 004dda73  d99c86c0088c00         +fstp dword ptr [esi + eax*4 + 0x8c08c0]
    app->getMemory<float>(cpu.esi + x86::reg32(9177280) /* 0x8c08c0 */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dda7a  d99c86c4088c00         +fstp dword ptr [esi + eax*4 + 0x8c08c4]
    app->getMemory<float>(cpu.esi + x86::reg32(9177284) /* 0x8c08c4 */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dda81  899c86c8088c00         -mov dword ptr [esi + eax*4 + 0x8c08c8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9177288) /* 0x8c08c8 */ + cpu.eax * 4) = cpu.ebx;
    // 004dda88  e8a3d70000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004dda8d  d80d80a28c00           +fmul dword ptr [0x8ca280]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216640) /* 0x8ca280 */));
    // 004dda93  d90580a28c00           +fld dword ptr [0x8ca280]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(9216640) /* 0x8ca280 */)));
    // 004dda99  dc0dd4975400           +fmul qword ptr [0x5497d4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5543892) /* 0x5497d4 */));
    // 004dda9f  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddaa1  d955fc                 +fst dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    // 004ddaa4  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddaa6  dd5dd8                 +fstp qword ptr [ebp - 0x28]
    app->getMemory<double>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddaa9  dc5dd8                 +fcomp qword ptr [ebp - 0x28]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    cpu.fpu.pop();
    // 004ddaac  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004ddaae  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004ddaaf  730e                   -jae 0x4ddabf
    if (!cpu.flags.cf)
    {
        goto L_0x004ddabf;
    }
    // 004ddab1  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004ddab4  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004ddab7  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004ddaba  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004ddabd  eb21                   -jmp 0x4ddae0
    goto L_0x004ddae0;
L_0x004ddabf:
    // 004ddabf  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 004ddac2  d81d80a28c00           +fcomp dword ptr [0x8ca280]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(9216640) /* 0x8ca280 */)));
    cpu.fpu.pop();
    // 004ddac8  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004ddaca  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004ddacb  7607                   -jbe 0x4ddad4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ddad4;
    }
    // 004ddacd  a180a28c00             -mov eax, dword ptr [0x8ca280]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216640) /* 0x8ca280 */);
    // 004ddad2  eb03                   -jmp 0x4ddad7
    goto L_0x004ddad7;
L_0x004ddad4:
    // 004ddad4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x004ddad7:
    // 004ddad7  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004ddada  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004ddadd  dd5de8                 -fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004ddae0:
    // 004ddae0  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004ddae7  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ddae9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004ddaec  8d1407                 -lea edx, [edi + eax]
    cpu.edx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004ddaef  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004ddaf6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ddaf8  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004ddafb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ddafe  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 004ddb01  01c2                   +add edx, eax
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
    // 004ddb03  d95df0                 +fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddb06  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004ddb09  8982cc088c00           -mov dword ptr [edx + 0x8c08cc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(9177292) /* 0x8c08cc */) = cpu.eax;
    // 004ddb0f  e81cd70000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004ddb14  d99ad0088c00           +fstp dword ptr [edx + 0x8c08d0]
    app->getMemory<float>(cpu.edx + x86::reg32(9177296) /* 0x8c08d0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddb1a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ddb1f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ddb21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb27  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004ddb2a:
    // 004ddb2a  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ddb2b  e920feffff             -jmp 0x4dd950
    goto L_0x004dd950;
L_0x004ddb30:
    // 004ddb30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ddb32  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ddb34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb37  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb3a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ddb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ddb40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ddb41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ddb42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ddb43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ddb44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ddb45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ddb46  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ddb48  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 004ddb4b  d90538bc6f00           -fld dword ptr [0x6fbc38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7322680) /* 0x6fbc38 */)));
    // 004ddb51  dc0ddc975400           -fmul qword ptr [0x5497dc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5543900) /* 0x5497dc */));
    // 004ddb57  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ddb5a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ddb5c  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004ddb5f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ddb62  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ddb65  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ddb66  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 004ddb69  8945bc                 -mov dword ptr [ebp - 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.eax;
L_0x004ddb6c:
    // 004ddb6c  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004ddb6f  3b0578a28c00           +cmp eax, dword ptr [0x8ca278]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216632) /* 0x8ca278 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ddb75  0f8de0040000           -jge 0x4de05b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004de05b;
    }
    // 004ddb7b  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004ddb7e  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004ddb81  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004ddb84  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ddb87  8b7de8                 -mov edi, dword ptr [ebp - 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004ddb8a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ddb8c  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004ddb8f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004ddb92  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ddb94  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ddb96  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004ddb99  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004ddb9c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ddb9e  8d7da4                 -lea edi, [ebp - 0x5c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 004ddba1  8b81cc088c00           -mov eax, dword ptr [ecx + 0x8c08cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(9177292) /* 0x8c08cc */);
    // 004ddba7  8db1c0088c00           -lea esi, [ecx + 0x8c08c0]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(9177280) /* 0x8c08c0 */);
    // 004ddbad  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004ddbb0  8b81d0088c00           -mov eax, dword ptr [ecx + 0x8c08d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(9177296) /* 0x8c08d0 */);
    // 004ddbb6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004ddbb7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004ddbb8  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004ddbbb  8b81c8088c00           -mov eax, dword ptr [ecx + 0x8c08c8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(9177288) /* 0x8c08c8 */);
    // 004ddbc1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ddbc3  0f848a040000           -je 0x4de053
    if (cpu.flags.zf)
    {
        goto L_0x004de053;
    }
    // 004ddbc9  8b1584a28c00           -mov edx, dword ptr [0x8ca284]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216644) /* 0x8ca284 */);
    // 004ddbcf  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004ddbd2  8b357ca28c00           -mov esi, dword ptr [0x8ca27c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(9216636) /* 0x8ca27c */);
    // 004ddbd8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ddbda  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ddbdd  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ddbdf  8b3d2ca28c00           -mov edi, dword ptr [0x8ca22c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */);
    // 004ddbe5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ddbe7  83ff01                 +cmp edi, 1
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
    // 004ddbea  7514                   -jne 0x4ddc00
    if (!cpu.flags.zf)
    {
        goto L_0x004ddc00;
    }
    // 004ddbec  db81c8088c00           -fild dword ptr [ecx + 0x8c08c8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(9177288) /* 0x8c08c8 */))));
    // 004ddbf2  d84de4                 -fmul dword ptr [ebp - 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */));
    // 004ddbf5  db057ca28c00           -fild dword ptr [0x8ca27c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216636) /* 0x8ca27c */))));
    // 004ddbfb  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ddbfd  d95de4                 -fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004ddc00:
    // 004ddc00  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 004ddc03  e848cd0000             -call 0x4ea950
    cpu.esp -= 4;
    sub_4ea950(app, cpu);
    if (cpu.terminate) return;
    // 004ddc08  d84de4                 -fmul dword ptr [ebp - 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */));
    // 004ddc0b  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 004ddc0e  d95db4                 -fstp dword ptr [ebp - 0x4c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddc11  e81acd0000             -call 0x4ea930
    cpu.esp -= 4;
    sub_4ea930(app, cpu);
    if (cpu.terminate) return;
    // 004ddc16  d84de4                 -fmul dword ptr [ebp - 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */));
    // 004ddc19  d945a4                 -fld dword ptr [ebp - 0x5c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-92) /* -0x5c */)));
    // 004ddc1c  d945a8                 -fld dword ptr [ebp - 0x58]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-88) /* -0x58 */)));
    // 004ddc1f  d845b4                 -fadd dword ptr [ebp - 0x4c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-76) /* -0x4c */));
    // 004ddc22  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddc24  d845b4                 -fadd dword ptr [ebp - 0x4c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-76) /* -0x4c */));
    // 004ddc27  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddc29  d80da0005600           -fmul dword ptr [0x5600a0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5636256) /* 0x5600a0 */));
    // 004ddc2f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddc31  d80d9c005600           -fmul dword ptr [0x56009c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5636252) /* 0x56009c */));
    // 004ddc37  d945a4                 -fld dword ptr [ebp - 0x5c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-92) /* -0x5c */)));
    // 004ddc3a  d945a8                 -fld dword ptr [ebp - 0x58]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-88) /* -0x58 */)));
    // 004ddc3d  d865b4                 -fsub dword ptr [ebp - 0x4c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-76) /* -0x4c */));
    // 004ddc40  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddc42  d865b4                 -fsub dword ptr [ebp - 0x4c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-76) /* -0x4c */));
    // 004ddc45  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddc47  d80da0005600           -fmul dword ptr [0x5600a0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5636256) /* 0x5600a0 */));
    // 004ddc4d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddc4f  d80d9c005600           -fmul dword ptr [0x56009c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5636252) /* 0x56009c */));
    // 004ddc55  d945a4                 -fld dword ptr [ebp - 0x5c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-92) /* -0x5c */)));
    // 004ddc58  d945a8                 -fld dword ptr [ebp - 0x58]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-88) /* -0x58 */)));
    // 004ddc5b  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004ddc5d  d95dac                 -fstp dword ptr [ebp - 0x54]
    app->getMemory<float>(cpu.ebp + x86::reg32(-84) /* -0x54 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddc60  d865ac                 -fsub dword ptr [ebp - 0x54]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-84) /* -0x54 */));
    // 004ddc63  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004ddc65  d845ac                 -fadd dword ptr [ebp - 0x54]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-84) /* -0x54 */));
    // 004ddc68  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004ddc6a  d80d9c005600           -fmul dword ptr [0x56009c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5636252) /* 0x56009c */));
    // 004ddc70  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004ddc72  d80da0005600           -fmul dword ptr [0x5600a0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5636256) /* 0x5600a0 */));
    // 004ddc78  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004ddc7a  d805a8005600           -fadd dword ptr [0x5600a8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5636264) /* 0x5600a8 */));
    // 004ddc80  d945a4                 -fld dword ptr [ebp - 0x5c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-92) /* -0x5c */)));
    // 004ddc83  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddc85  d95db8                 -fstp dword ptr [ebp - 0x48]
    app->getMemory<float>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddc88  d945a8                 -fld dword ptr [ebp - 0x58]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-88) /* -0x58 */)));
    // 004ddc8b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddc8d  d845ac                 -fadd dword ptr [ebp - 0x54]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-84) /* -0x54 */));
    // 004ddc90  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddc92  d865ac                 -fsub dword ptr [ebp - 0x54]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-84) /* -0x54 */));
    // 004ddc95  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddc97  d80d9c005600           -fmul dword ptr [0x56009c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5636252) /* 0x56009c */));
    // 004ddc9d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddc9f  d80da0005600           -fmul dword ptr [0x5600a0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5636256) /* 0x5600a0 */));
    // 004ddca5  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 004ddcaa  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004ddcad  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004ddcaf  d805a4005600           -fadd dword ptr [0x5600a4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5636260) /* 0x5600a4 */));
    // 004ddcb5  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004ddcb7  d805a8005600           -fadd dword ptr [0x5600a8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5636264) /* 0x5600a8 */));
    // 004ddcbd  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004ddcbf  d805a4005600           -fadd dword ptr [0x5600a4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5636260) /* 0x5600a4 */));
    // 004ddcc5  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004ddcc7  d95dc4                 -fstp dword ptr [ebp - 0x3c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddcca  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddccc  d95dd0                 -fstp dword ptr [ebp - 0x30]
    app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddccf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddcd1  d95dd8                 -fstp dword ptr [ebp - 0x28]
    app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddcd4  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004ddcd6  d805a4005600           -fadd dword ptr [0x5600a4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5636260) /* 0x5600a4 */));
    // 004ddcdc  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004ddcde  d805a8005600           -fadd dword ptr [0x5600a8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5636264) /* 0x5600a8 */));
    // 004ddce4  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004ddce6  d805a4005600           -fadd dword ptr [0x5600a4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5636260) /* 0x5600a4 */));
    // 004ddcec  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddcee  d805a8005600           -fadd dword ptr [0x5600a8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5636264) /* 0x5600a8 */));
    // 004ddcf4  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004ddcf6  d95dc0                 -fstp dword ptr [ebp - 0x40]
    app->getMemory<float>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddcf9  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004ddcfb  d95dc8                 -fstp dword ptr [ebp - 0x38]
    app->getMemory<float>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddcfe  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ddd00  d95dcc                 -fstp dword ptr [ebp - 0x34]
    app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddd03  d95dd4                 -fstp dword ptr [ebp - 0x2c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ddd06  e875e2fdff             -call 0x4bbf80
    cpu.esp -= 4;
    sub_4bbf80(app, cpu);
    if (cpu.terminate) return;
    // 004ddd0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ddd0d  0f8448030000           -je 0x4de05b
    if (cpu.flags.zf)
    {
        goto L_0x004de05b;
    }
    // 004ddd13  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004ddd16  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004ddd19  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004ddd1c  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004ddd1f  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004ddd22  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004ddd25  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004ddd28  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004ddd2b  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004ddd2e  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004ddd31  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004ddd36  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ddd38  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004ddd3b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ddd3d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004ddd40  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004ddd43  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004ddd45  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ddd47  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004ddd4a  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ddd4c  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ddd4e  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004ddd51  8a25583a7a00           -mov ah, byte ptr [0x7a3a58]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */);
    // 004ddd57  f6c450                 +test ah, 0x50
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 80 /*0x50*/));
    // 004ddd5a  7453                   -je 0x4dddaf
    if (cpu.flags.zf)
    {
        goto L_0x004dddaf;
    }
    // 004ddd5c  d90538bc6f00           +fld dword ptr [0x6fbc38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7322680) /* 0x6fbc38 */)));
    // 004ddd62  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004ddd64  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004ddd66  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004ddd68  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004ddd69  7644                   -jbe 0x4dddaf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004dddaf;
    }
    // 004ddd6b  8b4dbc                 -mov ecx, dword ptr [ebp - 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 004ddd6e  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004ddd71  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ddd77  7c05                   -jl 0x4ddd7e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ddd7e;
    }
    // 004ddd79  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
L_0x004ddd7e:
    // 004ddd7e  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004ddd81  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ddd83  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ddd89  81e300ff00ff           -and ebx, 0xff00ff00
    cpu.ebx &= x86::reg32(x86::sreg32(4278255360 /*0xff00ff00*/));
    // 004ddd8f  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004ddd92  25ff00ff00             -and eax, 0xff00ff
    cpu.eax &= x86::reg32(x86::sreg32(16711935 /*0xff00ff*/));
    // 004ddd97  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004ddd99  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004ddd9a  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004ddd9c  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004ddd9f  2500ff00ff             -and eax, 0xff00ff00
    cpu.eax &= x86::reg32(x86::sreg32(4278255360 /*0xff00ff00*/));
    // 004ddda4  81e3ff00ff00           -and ebx, 0xff00ff
    cpu.ebx &= x86::reg32(x86::sreg32(16711935 /*0xff00ff*/));
    // 004dddaa  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004dddac  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
L_0x004dddaf:
    // 004dddaf  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004dddb2  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004dddb8  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004dddbb  66c740060100           -mov word ptr [eax + 6], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 1 /*0x1*/;
    // 004dddc1  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004dddc4  c7401888a28c00         -mov dword ptr [eax + 0x18], 0x8ca288
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 9216648 /*0x8ca288*/;
    // 004dddcb  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004dddce  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dddd1  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004dddd4  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004dddd7  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004dddda  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ddddd  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004ddde0  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004ddde3  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ddde6  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004ddde9  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004dddec  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004dddef  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dddf2  c74208cdcccc3d         -mov dword ptr [edx + 8], 0x3dcccccd
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 1036831949 /*0x3dcccccd*/;
    // 004dddf9  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004dddfc  c7420c6666663f         -mov dword ptr [edx + 0xc], 0x3f666666
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 1063675494 /*0x3f666666*/;
    // 004dde03  8d7a14                 -lea edi, [edx + 0x14]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004dde06  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004dde08  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004dde0b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004dde0d  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004dde10  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004dde13  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 004dde19  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004dde1e  7558                   -jne 0x4dde78
    if (!cpu.flags.zf)
    {
        goto L_0x004dde78;
    }
    // 004dde20  39c8                   +cmp eax, ecx
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
    // 004dde22  7d54                   -jge 0x4dde78
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dde78;
    }
    // 004dde24  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004dde27  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004dde2c  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 004dde32  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 004dde38  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004dde3d  750d                   -jne 0x4dde4c
    if (!cpu.flags.zf)
    {
        goto L_0x004dde4c;
    }
    // 004dde3f  39c8                   +cmp eax, ecx
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
    // 004dde41  7c09                   -jl 0x4dde4c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004dde4c;
    }
    // 004dde43  39d0                   +cmp eax, edx
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
    // 004dde45  7e09                   -jle 0x4dde50
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dde50;
    }
    // 004dde47  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004dde4a  eb04                   -jmp 0x4dde50
    goto L_0x004dde50;
L_0x004dde4c:
    // 004dde4c  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dde4f  90                     -nop 
    ;
L_0x004dde50:
    // 004dde50  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004dde52  90                     -nop 
    ;
    // 004dde53  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 004dde59  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 004dde5f  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004dde64  750d                   -jne 0x4dde73
    if (!cpu.flags.zf)
    {
        goto L_0x004dde73;
    }
    // 004dde66  39c8                   +cmp eax, ecx
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
    // 004dde68  7c09                   -jl 0x4dde73
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004dde73;
    }
    // 004dde6a  39d0                   +cmp eax, edx
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
    // 004dde6c  7e0f                   -jle 0x4dde7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dde7d;
    }
    // 004dde6e  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004dde71  eb0a                   -jmp 0x4dde7d
    goto L_0x004dde7d;
L_0x004dde73:
    // 004dde73  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004dde76  eb05                   -jmp 0x4dde7d
    goto L_0x004dde7d;
L_0x004dde78:
    // 004dde78  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004dde7d:
    // 004dde7d  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004dde7f  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dde82  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004dde85  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004dde88  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004dde8b  c74208cdcccc3d         -mov dword ptr [edx + 8], 0x3dcccccd
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 1036831949 /*0x3dcccccd*/;
    // 004dde92  8b45c0                 -mov eax, dword ptr [ebp - 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004dde95  c7420c6666663f         -mov dword ptr [edx + 0xc], 0x3f666666
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 1063675494 /*0x3f666666*/;
    // 004dde9c  8d7a14                 -lea edi, [edx + 0x14]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004dde9f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004ddea1  8b45b8                 -mov eax, dword ptr [ebp - 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 004ddea4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ddea6  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ddea9  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ddeac  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 004ddeb2  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004ddeb7  7558                   -jne 0x4ddf11
    if (!cpu.flags.zf)
    {
        goto L_0x004ddf11;
    }
    // 004ddeb9  39c8                   +cmp eax, ecx
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
    // 004ddebb  7d54                   -jge 0x4ddf11
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ddf11;
    }
    // 004ddebd  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ddec0  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004ddec5  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 004ddecb  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 004dded1  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004dded6  750d                   -jne 0x4ddee5
    if (!cpu.flags.zf)
    {
        goto L_0x004ddee5;
    }
    // 004dded8  39c8                   +cmp eax, ecx
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
    // 004ddeda  7c09                   -jl 0x4ddee5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ddee5;
    }
    // 004ddedc  39d0                   +cmp eax, edx
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
    // 004ddede  7e09                   -jle 0x4ddee9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ddee9;
    }
    // 004ddee0  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004ddee3  eb04                   -jmp 0x4ddee9
    goto L_0x004ddee9;
L_0x004ddee5:
    // 004ddee5  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ddee8  90                     -nop 
    ;
L_0x004ddee9:
    // 004ddee9  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ddeeb  90                     -nop 
    ;
    // 004ddeec  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 004ddef2  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 004ddef8  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004ddefd  750d                   -jne 0x4ddf0c
    if (!cpu.flags.zf)
    {
        goto L_0x004ddf0c;
    }
    // 004ddeff  39c8                   +cmp eax, ecx
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
    // 004ddf01  7c09                   -jl 0x4ddf0c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ddf0c;
    }
    // 004ddf03  39d0                   +cmp eax, edx
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
    // 004ddf05  7e0f                   -jle 0x4ddf16
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ddf16;
    }
    // 004ddf07  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004ddf0a  eb0a                   -jmp 0x4ddf16
    goto L_0x004ddf16;
L_0x004ddf0c:
    // 004ddf0c  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004ddf0f  eb05                   -jmp 0x4ddf16
    goto L_0x004ddf16;
L_0x004ddf11:
    // 004ddf11  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004ddf16:
    // 004ddf16  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004ddf18  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004ddf1b  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004ddf1e  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ddf21  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004ddf24  c74208cdcccc3d         -mov dword ptr [edx + 8], 0x3dcccccd
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 1036831949 /*0x3dcccccd*/;
    // 004ddf2b  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004ddf2e  c7420c6666663f         -mov dword ptr [edx + 0xc], 0x3f666666
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 1063675494 /*0x3f666666*/;
    // 004ddf35  8d7a14                 -lea edi, [edx + 0x14]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004ddf38  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004ddf3a  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004ddf3d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ddf3f  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ddf42  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ddf45  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 004ddf4b  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004ddf50  7558                   -jne 0x4ddfaa
    if (!cpu.flags.zf)
    {
        goto L_0x004ddfaa;
    }
    // 004ddf52  39c8                   +cmp eax, ecx
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
    // 004ddf54  7d54                   -jge 0x4ddfaa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ddfaa;
    }
    // 004ddf56  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ddf59  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004ddf5e  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 004ddf64  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 004ddf6a  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004ddf6f  750d                   -jne 0x4ddf7e
    if (!cpu.flags.zf)
    {
        goto L_0x004ddf7e;
    }
    // 004ddf71  39c8                   +cmp eax, ecx
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
    // 004ddf73  7c09                   -jl 0x4ddf7e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ddf7e;
    }
    // 004ddf75  39d0                   +cmp eax, edx
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
    // 004ddf77  7e09                   -jle 0x4ddf82
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ddf82;
    }
    // 004ddf79  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004ddf7c  eb04                   -jmp 0x4ddf82
    goto L_0x004ddf82;
L_0x004ddf7e:
    // 004ddf7e  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ddf81  90                     -nop 
    ;
L_0x004ddf82:
    // 004ddf82  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ddf84  90                     -nop 
    ;
    // 004ddf85  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 004ddf8b  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 004ddf91  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004ddf96  750d                   -jne 0x4ddfa5
    if (!cpu.flags.zf)
    {
        goto L_0x004ddfa5;
    }
    // 004ddf98  39c8                   +cmp eax, ecx
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
    // 004ddf9a  7c09                   -jl 0x4ddfa5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ddfa5;
    }
    // 004ddf9c  39d0                   +cmp eax, edx
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
    // 004ddf9e  7e0f                   -jle 0x4ddfaf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ddfaf;
    }
    // 004ddfa0  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004ddfa3  eb0a                   -jmp 0x4ddfaf
    goto L_0x004ddfaf;
L_0x004ddfa5:
    // 004ddfa5  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004ddfa8  eb05                   -jmp 0x4ddfaf
    goto L_0x004ddfaf;
L_0x004ddfaa:
    // 004ddfaa  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004ddfaf:
    // 004ddfaf  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004ddfb1  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004ddfb4  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004ddfb7  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ddfba  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004ddfbd  c74208cdcccc3d         -mov dword ptr [edx + 8], 0x3dcccccd
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 1036831949 /*0x3dcccccd*/;
    // 004ddfc4  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004ddfc7  c7420c6666663f         -mov dword ptr [edx + 0xc], 0x3f666666
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 1063675494 /*0x3f666666*/;
    // 004ddfce  8d7a14                 -lea edi, [edx + 0x14]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004ddfd1  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004ddfd3  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004ddfd6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ddfd8  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ddfdb  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ddfde  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 004ddfe4  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004ddfe9  7558                   -jne 0x4de043
    if (!cpu.flags.zf)
    {
        goto L_0x004de043;
    }
    // 004ddfeb  39c8                   +cmp eax, ecx
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
    // 004ddfed  7d54                   -jge 0x4de043
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004de043;
    }
    // 004ddfef  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ddff2  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004ddff7  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 004ddffd  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 004de003  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de008  750d                   -jne 0x4de017
    if (!cpu.flags.zf)
    {
        goto L_0x004de017;
    }
    // 004de00a  39c8                   +cmp eax, ecx
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
    // 004de00c  7c09                   -jl 0x4de017
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de017;
    }
    // 004de00e  39d0                   +cmp eax, edx
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
    // 004de010  7e09                   -jle 0x4de01b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004de01b;
    }
    // 004de012  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004de015  eb04                   -jmp 0x4de01b
    goto L_0x004de01b;
L_0x004de017:
    // 004de017  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004de01a  90                     -nop 
    ;
L_0x004de01b:
    // 004de01b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004de01d  90                     -nop 
    ;
    // 004de01e  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 004de024  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 004de02a  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de02f  750d                   -jne 0x4de03e
    if (!cpu.flags.zf)
    {
        goto L_0x004de03e;
    }
    // 004de031  39c8                   +cmp eax, ecx
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
    // 004de033  7c09                   -jl 0x4de03e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de03e;
    }
    // 004de035  39d0                   +cmp eax, edx
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
    // 004de037  7e0f                   -jle 0x4de048
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004de048;
    }
    // 004de039  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004de03c  eb0a                   -jmp 0x4de048
    goto L_0x004de048;
L_0x004de03e:
    // 004de03e  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004de041  eb05                   -jmp 0x4de048
    goto L_0x004de048;
L_0x004de043:
    // 004de043  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004de048:
    // 004de048  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004de04a  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de04d  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de050  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x004de053:
    // 004de053  ff45e8                 +inc dword ptr [ebp - 0x18]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004de056  e911fbffff             -jmp 0x4ddb6c
    goto L_0x004ddb6c;
L_0x004de05b:
    // 004de05b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004de05d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de05e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de05f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de060  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de061  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de062  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de063  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4de070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004de070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004de071  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004de072  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004de073  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004de074  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004de076  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 004de079  8975c8                 -mov dword ptr [ebp - 0x38], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.esi;
    // 004de07c  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004de07f  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004de082  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004de084  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004de087  8955d0                 -mov dword ptr [ebp - 0x30], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.edx;
    // 004de08a  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 004de08d  8b1538a28c00           -mov edx, dword ptr [0x8ca238]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216568) /* 0x8ca238 */);
    // 004de093  a138a28c00             -mov eax, dword ptr [0x8ca238]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216568) /* 0x8ca238 */);
    // 004de098  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 004de09b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004de09e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004de0a0  8b1538a28c00           -mov edx, dword ptr [0x8ca238]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216568) /* 0x8ca238 */);
    // 004de0a6  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004de0a9  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004de0ab  8b1538a28c00           -mov edx, dword ptr [0x8ca238]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216568) /* 0x8ca238 */);
    // 004de0b1  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004de0b3  8a25583a7a00           -mov ah, byte ptr [0x7a3a58]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */);
    // 004de0b9  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 004de0bc  f6c450                 +test ah, 0x50
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 80 /*0x50*/));
    // 004de0bf  7465                   -je 0x4de126
    if (cpu.flags.zf)
    {
        goto L_0x004de126;
    }
    // 004de0c1  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004de0c3  d90538bc6f00           +fld dword ptr [0x6fbc38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7322680) /* 0x6fbc38 */)));
    // 004de0c9  dd5dac                 +fstp qword ptr [ebp - 0x54]
    app->getMemory<double>(cpu.ebp + x86::reg32(-84) /* -0x54 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de0cc  dc5dac                 +fcomp qword ptr [ebp - 0x54]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-84) /* -0x54 */)));
    cpu.fpu.pop();
    // 004de0cf  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de0d1  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de0d2  7652                   -jbe 0x4de126
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004de126;
    }
    // 004de0d4  dd45ac                 -fld qword ptr [ebp - 0x54]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-84) /* -0x54 */)));
    // 004de0d7  dc0de4975400           -fmul qword ptr [0x5497e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5543908) /* 0x5497e4 */));
    // 004de0dd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004de0e0  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004de0e3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de0e4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004de0e6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004de0e8  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004de0ee  7c05                   -jl 0x4de0f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de0f5;
    }
    // 004de0f0  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
L_0x004de0f5:
    // 004de0f5  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004de0f8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004de0fa  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004de100  81e300ff00ff           -and ebx, 0xff00ff00
    cpu.ebx &= x86::reg32(x86::sreg32(4278255360 /*0xff00ff00*/));
    // 004de106  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004de109  25ff00ff00             -and eax, 0xff00ff
    cpu.eax &= x86::reg32(x86::sreg32(16711935 /*0xff00ff*/));
    // 004de10e  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004de110  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004de111  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004de113  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004de116  2500ff00ff             -and eax, 0xff00ff00
    cpu.eax &= x86::reg32(x86::sreg32(4278255360 /*0xff00ff00*/));
    // 004de11b  81e3ff00ff00           -and ebx, 0xff00ff
    cpu.ebx &= x86::reg32(x86::sreg32(16711935 /*0xff00ff*/));
    // 004de121  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004de123  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
L_0x004de126:
    // 004de126  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004de129  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004de130  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004de132  8d45c4                 -lea eax, [ebp - 0x3c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004de135  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004de138  e803ddfdff             -call 0x4bbe40
    cpu.esp -= 4;
    sub_4bbe40(app, cpu);
    if (cpu.terminate) return;
    // 004de13d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004de13f  0f849a050000           -je 0x4de6df
    if (cpu.flags.zf)
    {
        goto L_0x004de6df;
    }
    // 004de145  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004de148  68c0a48b00             -push 0x8ba4c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 9151680 /*0x8ba4c0*/;
    cpu.esp -= 4;
    // 004de14d  8b7dcc                 -mov edi, dword ptr [ebp - 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004de150  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004de153  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004de15a  8b4de4                 -mov ecx, dword ptr [ebp - 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004de15d  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004de15f  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004de162  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004de165  bae8568c00             -mov edx, 0x8c56e8
    cpu.edx = 9197288 /*0x8c56e8*/;
    // 004de16a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004de16c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004de16f  83c138                 -add ecx, 0x38
    (cpu.ecx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004de172  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004de174  83c344                 -add ebx, 0x44
    (cpu.ebx) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004de177  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004de179  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004de17c  e83f13feff             -call 0x4bf4c0
    cpu.esp -= 4;
    sub_4bf4c0(app, cpu);
    if (cpu.terminate) return;
    // 004de181  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004de183  894de0                 -mov dword ptr [ebp - 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ecx;
L_0x004de186:
    // 004de186  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004de189  3b45fc                 +cmp eax, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004de18c  0f8d0a050000           -jge 0x4de69c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004de69c;
    }
    // 004de192  8b7dcc                 -mov edi, dword ptr [ebp - 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004de195  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004de19c  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004de19e  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004de1a1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004de1a3  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004de1a6  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004de1a9  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004de1ab  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004de1b2  b9e80b8c00             -mov ecx, 0x8c0be8
    cpu.ecx = 9178088 /*0x8c0be8*/;
    // 004de1b7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004de1b9  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004de1bb  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004de1c2  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004de1c5  8a5808                 -mov bl, byte ptr [eax + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004de1c8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004de1ca  0f85c4040000           -jne 0x4de694
    if (!cpu.flags.zf)
    {
        goto L_0x004de694;
    }
    // 004de1d0  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004de1d3  b9c0a48b00             -mov ecx, 0x8ba4c0
    cpu.ecx = 9151680 /*0x8ba4c0*/;
    // 004de1d8  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004de1db  01c1                   +add ecx, eax
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
    // 004de1dd  d94108                 +fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004de1e0  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 004de1e3  dc1dec975400           +fcomp qword ptr [0x5497ec]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5543916) /* 0x5497ec */)));
    cpu.fpu.pop();
    // 004de1e9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de1eb  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de1ec  766a                   -jbe 0x4de258
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004de258;
    }
    // 004de1ee  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004de1f0  d85908                 +fcomp dword ptr [ecx + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 004de1f3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de1f5  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de1f6  7660                   -jbe 0x4de258
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004de258;
    }
    // 004de1f8  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004de1fb  d9400c                 +fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004de1fe  d80564a28c00           +fadd dword ptr [0x8ca264]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(9216612) /* 0x8ca264 */));
    // 004de204  d99c32ec568c00         +fstp dword ptr [edx + esi + 0x8c56ec]
    app->getMemory<float>(cpu.edx + x86::reg32(9197292) /* 0x8c56ec */ + cpu.esi * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de20b  e820d00000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004de210  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de216  d80df4975400           +fmul dword ptr [0x5497f4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543924) /* 0x5497f4 */));
    // 004de21c  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de222  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004de225  d84008                 +fadd dword ptr [eax + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 004de228  d99c32e8568c00         +fstp dword ptr [edx + esi + 0x8c56e8]
    app->getMemory<float>(cpu.edx + x86::reg32(9197288) /* 0x8c56e8 */ + cpu.esi * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de22f  e8fccf0000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004de234  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de23a  d80df4975400           +fmul dword ptr [0x5497f4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543924) /* 0x5497f4 */));
    // 004de240  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de246  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004de249  d84010                 +fadd dword ptr [eax + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */));
    // 004de24c  d99c32f0568c00         +fstp dword ptr [edx + esi + 0x8c56f0]
    app->getMemory<float>(cpu.edx + x86::reg32(9197296) /* 0x8c56f0 */ + cpu.esi * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de253  e93c040000             -jmp 0x4de694
    goto L_0x004de694;
L_0x004de258:
    // 004de258  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de25b  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004de25d  d85808                 +fcomp dword ptr [eax + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 004de260  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de262  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de263  0f832b040000           -jae 0x4de694
    if (!cpu.flags.cf)
    {
        goto L_0x004de694;
    }
    // 004de269  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de26c  db054ca28c00           +fild dword ptr [0x8ca24c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216588) /* 0x8ca24c */))));
    // 004de272  d85808                 +fcomp dword ptr [eax + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 004de275  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de277  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de278  7308                   -jae 0x4de282
    if (!cpu.flags.cf)
    {
        goto L_0x004de282;
    }
    // 004de27a  ff45e0                 +inc dword ptr [ebp - 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004de27d  e904ffffff             -jmp 0x4de186
    goto L_0x004de186;
L_0x004de282:
    // 004de282  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de285  80781400               +cmp byte ptr [eax + 0x14], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004de289  7408                   -je 0x4de293
    if (cpu.flags.zf)
    {
        goto L_0x004de293;
    }
    // 004de28b  ff45e0                 +inc dword ptr [ebp - 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004de28e  e9f3feffff             -jmp 0x4de186
    goto L_0x004de186;
L_0x004de293:
    // 004de293  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004de296  dc1dfc975400           +fcomp qword ptr [0x5497fc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5543932) /* 0x5497fc */)));
    cpu.fpu.pop();
    // 004de29c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de29e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de29f  0f83a8000000           -jae 0x4de34d
    if (!cpu.flags.cf)
    {
        goto L_0x004de34d;
    }
    // 004de2a5  8b7dcc                 -mov edi, dword ptr [ebp - 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004de2a8  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004de2af  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004de2b1  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004de2b4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004de2b6  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004de2b9  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004de2bc  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004de2be  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004de2c5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004de2c7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004de2ca  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004de2cc  8bbef0568c00           -mov edi, dword ptr [esi + 0x8c56f0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9197296) /* 0x8c56f0 */);
    // 004de2d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004de2d3  8b86ec568c00           -mov eax, dword ptr [esi + 0x8c56ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9197292) /* 0x8c56ec */);
    // 004de2d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004de2da  8b96e8568c00           -mov edx, dword ptr [esi + 0x8c56e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9197288) /* 0x8c56e8 */);
    // 004de2e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004de2e1  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004de2e4  e847f6ffff             -call 0x4dd930
    cpu.esp -= 4;
    sub_4dd930(app, cpu);
    if (cpu.terminate) return;
    // 004de2e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004de2eb  7460                   -je 0x4de34d
    if (cpu.flags.zf)
    {
        goto L_0x004de34d;
    }
    // 004de2ed  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004de2f0  d9400c                 +fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004de2f3  d80564a28c00           +fadd dword ptr [0x8ca264]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(9216612) /* 0x8ca264 */));
    // 004de2f9  d99eec568c00           +fstp dword ptr [esi + 0x8c56ec]
    app->getMemory<float>(cpu.esi + x86::reg32(9197292) /* 0x8c56ec */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de2ff  e82ccf0000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004de304  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de30a  d80df4975400           +fmul dword ptr [0x5497f4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543924) /* 0x5497f4 */));
    // 004de310  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de316  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004de319  d84008                 +fadd dword ptr [eax + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 004de31c  d99ee8568c00           +fstp dword ptr [esi + 0x8c56e8]
    app->getMemory<float>(cpu.esi + x86::reg32(9197288) /* 0x8c56e8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de322  e809cf0000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004de327  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de32d  d80df4975400           +fmul dword ptr [0x5497f4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543924) /* 0x5497f4 */));
    // 004de333  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de339  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004de33c  d84010                 +fadd dword ptr [eax + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */));
    // 004de33f  d99ef0568c00           +fstp dword ptr [esi + 0x8c56f0]
    app->getMemory<float>(cpu.esi + x86::reg32(9197296) /* 0x8c56f0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de345  ff45e0                 +inc dword ptr [ebp - 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004de348  e939feffff             -jmp 0x4de186
    goto L_0x004de186;
L_0x004de34d:
    // 004de34d  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de350  d90530a28c00           +fld dword ptr [0x8ca230]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(9216560) /* 0x8ca230 */)));
    // 004de356  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004de359  d8c9                   +fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004de35b  d80d50a28c00           +fmul dword ptr [0x8ca250]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216592) /* 0x8ca250 */));
    // 004de361  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004de363  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004de365  dc0d04985400           +fmul qword ptr [0x549804]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5543940) /* 0x549804 */));
    // 004de36b  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004de36d  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004de36f  ddda                   +fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de371  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004de373  d95dd4                 +fstp dword ptr [ebp - 0x2c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de376  d85dd4                 +fcomp dword ptr [ebp - 0x2c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    cpu.fpu.pop();
    // 004de379  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de37b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de37c  7609                   -jbe 0x4de387
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004de387;
    }
    // 004de37e  c745d80000803f         -mov dword ptr [ebp - 0x28], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = 1065353216 /*0x3f800000*/;
    // 004de385  eb06                   -jmp 0x4de38d
    goto L_0x004de38d;
L_0x004de387:
    // 004de387  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004de38a  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
L_0x004de38d:
    // 004de38d  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de390  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004de393  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004de396  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de399  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004de39c  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004de39f  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de3a2  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004de3a7  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004de3aa  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de3ad  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004de3b3  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de3b6  c7401800a28c00         -mov dword ptr [eax + 0x18], 0x8ca200
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 9216512 /*0x8ca200*/;
    // 004de3bd  83c620                 -add esi, 0x20
    (cpu.esi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004de3c0  66c740060100           -mov word ptr [eax + 6], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 1 /*0x1*/;
    // 004de3c6  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004de3c9  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004de3cc  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004de3cf  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de3d2  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004de3d5  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de3d8  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004de3db  8d90a0000000           -lea edx, [eax + 0xa0]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 004de3e1  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004de3e3  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de3e6  8d7e14                 -lea edi, [esi + 0x14]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004de3e9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004de3eb  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004de3ed  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004de3f0  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004de3f3  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004de3f6  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004de3f9  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004de3fc  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004de3ff  d95e0c                 -fstp dword ptr [esi + 0xc]
    app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de402  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004de405  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004de408  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 004de40e  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de413  7558                   -jne 0x4de46d
    if (!cpu.flags.zf)
    {
        goto L_0x004de46d;
    }
    // 004de415  39c8                   +cmp eax, ecx
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
    // 004de417  7d54                   -jge 0x4de46d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004de46d;
    }
    // 004de419  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004de41c  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004de421  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 004de427  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 004de42d  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de432  750d                   -jne 0x4de441
    if (!cpu.flags.zf)
    {
        goto L_0x004de441;
    }
    // 004de434  39c8                   +cmp eax, ecx
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
    // 004de436  7c09                   -jl 0x4de441
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de441;
    }
    // 004de438  39d0                   +cmp eax, edx
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
    // 004de43a  7e09                   -jle 0x4de445
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004de445;
    }
    // 004de43c  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004de43f  eb04                   -jmp 0x4de445
    goto L_0x004de445;
L_0x004de441:
    // 004de441  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004de444  90                     -nop 
    ;
L_0x004de445:
    // 004de445  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004de447  90                     -nop 
    ;
    // 004de448  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 004de44e  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 004de454  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de459  750d                   -jne 0x4de468
    if (!cpu.flags.zf)
    {
        goto L_0x004de468;
    }
    // 004de45b  39c8                   +cmp eax, ecx
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
    // 004de45d  7c09                   -jl 0x4de468
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de468;
    }
    // 004de45f  39d0                   +cmp eax, edx
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
    // 004de461  7e0f                   -jle 0x4de472
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004de472;
    }
    // 004de463  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004de466  eb0a                   -jmp 0x4de472
    goto L_0x004de472;
L_0x004de468:
    // 004de468  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004de46b  eb05                   -jmp 0x4de472
    goto L_0x004de472;
L_0x004de46d:
    // 004de46d  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004de472:
    // 004de472  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004de474  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de477  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004de479  d845d8                 -fadd dword ptr [ebp - 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */));
    // 004de47c  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004de47f  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de481  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de484  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004de487  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004de48a  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de48d  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de490  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004de493  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004de496  d95808                 -fstp dword ptr [eax + 8]
    app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de499  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de49c  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004de49f  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004de4a2  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004de4a5  8d7a14                 -lea edi, [edx + 0x14]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004de4a8  d9580c                 -fstp dword ptr [eax + 0xc]
    app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de4ab  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004de4ae  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004de4b0  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004de4b3  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004de4b6  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 004de4bc  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de4c1  7558                   -jne 0x4de51b
    if (!cpu.flags.zf)
    {
        goto L_0x004de51b;
    }
    // 004de4c3  39c8                   +cmp eax, ecx
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
    // 004de4c5  7d54                   -jge 0x4de51b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004de51b;
    }
    // 004de4c7  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004de4ca  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004de4cf  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 004de4d5  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 004de4db  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de4e0  750d                   -jne 0x4de4ef
    if (!cpu.flags.zf)
    {
        goto L_0x004de4ef;
    }
    // 004de4e2  39c8                   +cmp eax, ecx
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
    // 004de4e4  7c09                   -jl 0x4de4ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de4ef;
    }
    // 004de4e6  39d0                   +cmp eax, edx
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
    // 004de4e8  7e09                   -jle 0x4de4f3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004de4f3;
    }
    // 004de4ea  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004de4ed  eb04                   -jmp 0x4de4f3
    goto L_0x004de4f3;
L_0x004de4ef:
    // 004de4ef  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004de4f2  90                     -nop 
    ;
L_0x004de4f3:
    // 004de4f3  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004de4f5  90                     -nop 
    ;
    // 004de4f6  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 004de4fc  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 004de502  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de507  750d                   -jne 0x4de516
    if (!cpu.flags.zf)
    {
        goto L_0x004de516;
    }
    // 004de509  39c8                   +cmp eax, ecx
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
    // 004de50b  7c09                   -jl 0x4de516
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de516;
    }
    // 004de50d  39d0                   +cmp eax, edx
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
    // 004de50f  7e0f                   -jle 0x4de520
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004de520;
    }
    // 004de511  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004de514  eb0a                   -jmp 0x4de520
    goto L_0x004de520;
L_0x004de516:
    // 004de516  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004de519  eb05                   -jmp 0x4de520
    goto L_0x004de520;
L_0x004de51b:
    // 004de51b  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004de520:
    // 004de520  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004de522  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de525  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004de527  d845d8                 -fadd dword ptr [ebp - 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */));
    // 004de52a  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de52d  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de52f  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de532  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004de535  d845d8                 -fadd dword ptr [ebp - 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */));
    // 004de538  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de53b  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de53e  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de541  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004de544  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de547  d95808                 -fstp dword ptr [eax + 8]
    app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de54a  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de54d  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de550  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004de553  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de556  8d7a14                 -lea edi, [edx + 0x14]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004de559  d9580c                 -fstp dword ptr [eax + 0xc]
    app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de55c  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004de55f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004de561  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004de564  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004de567  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 004de56d  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de572  7558                   -jne 0x4de5cc
    if (!cpu.flags.zf)
    {
        goto L_0x004de5cc;
    }
    // 004de574  39c8                   +cmp eax, ecx
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
    // 004de576  7d54                   -jge 0x4de5cc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004de5cc;
    }
    // 004de578  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004de57b  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004de580  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 004de586  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 004de58c  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de591  750d                   -jne 0x4de5a0
    if (!cpu.flags.zf)
    {
        goto L_0x004de5a0;
    }
    // 004de593  39c8                   +cmp eax, ecx
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
    // 004de595  7c09                   -jl 0x4de5a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de5a0;
    }
    // 004de597  39d0                   +cmp eax, edx
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
    // 004de599  7e09                   -jle 0x4de5a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004de5a4;
    }
    // 004de59b  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004de59e  eb04                   -jmp 0x4de5a4
    goto L_0x004de5a4;
L_0x004de5a0:
    // 004de5a0  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004de5a3  90                     -nop 
    ;
L_0x004de5a4:
    // 004de5a4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004de5a6  90                     -nop 
    ;
    // 004de5a7  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 004de5ad  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 004de5b3  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de5b8  750d                   -jne 0x4de5c7
    if (!cpu.flags.zf)
    {
        goto L_0x004de5c7;
    }
    // 004de5ba  39c8                   +cmp eax, ecx
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
    // 004de5bc  7c09                   -jl 0x4de5c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de5c7;
    }
    // 004de5be  39d0                   +cmp eax, edx
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
    // 004de5c0  7e0f                   -jle 0x4de5d1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004de5d1;
    }
    // 004de5c2  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004de5c5  eb0a                   -jmp 0x4de5d1
    goto L_0x004de5d1;
L_0x004de5c7:
    // 004de5c7  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004de5ca  eb05                   -jmp 0x4de5d1
    goto L_0x004de5d1;
L_0x004de5cc:
    // 004de5cc  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004de5d1:
    // 004de5d1  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004de5d3  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de5d6  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004de5d8  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de5db  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de5dd  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de5e0  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004de5e3  d845d8                 -fadd dword ptr [ebp - 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */));
    // 004de5e6  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de5e9  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de5ec  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de5ef  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004de5f2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de5f5  d95808                 -fstp dword ptr [eax + 8]
    app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de5f8  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de5fb  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de5fe  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004de601  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de604  8d7a14                 -lea edi, [edx + 0x14]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004de607  d9580c                 -fstp dword ptr [eax + 0xc]
    app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de60a  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004de60d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004de60f  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004de612  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004de615  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 004de61b  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de620  7558                   -jne 0x4de67a
    if (!cpu.flags.zf)
    {
        goto L_0x004de67a;
    }
    // 004de622  39c8                   +cmp eax, ecx
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
    // 004de624  7d54                   -jge 0x4de67a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004de67a;
    }
    // 004de626  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004de629  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004de62e  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 004de634  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 004de63a  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de63f  750d                   -jne 0x4de64e
    if (!cpu.flags.zf)
    {
        goto L_0x004de64e;
    }
    // 004de641  39c8                   +cmp eax, ecx
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
    // 004de643  7c09                   -jl 0x4de64e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de64e;
    }
    // 004de645  39d0                   +cmp eax, edx
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
    // 004de647  7e09                   -jle 0x4de652
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004de652;
    }
    // 004de649  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004de64c  eb04                   -jmp 0x4de652
    goto L_0x004de652;
L_0x004de64e:
    // 004de64e  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004de651  90                     -nop 
    ;
L_0x004de652:
    // 004de652  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004de654  90                     -nop 
    ;
    // 004de655  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 004de65b  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 004de661  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004de666  750d                   -jne 0x4de675
    if (!cpu.flags.zf)
    {
        goto L_0x004de675;
    }
    // 004de668  39c8                   +cmp eax, ecx
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
    // 004de66a  7c09                   -jl 0x4de675
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de675;
    }
    // 004de66c  39d0                   +cmp eax, edx
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
    // 004de66e  7e0f                   -jle 0x4de67f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004de67f;
    }
    // 004de670  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004de673  eb0a                   -jmp 0x4de67f
    goto L_0x004de67f;
L_0x004de675:
    // 004de675  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004de678  eb05                   -jmp 0x4de67f
    goto L_0x004de67f;
L_0x004de67a:
    // 004de67a  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004de67f:
    // 004de67f  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004de681  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de684  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004de687  81c6a0000000           +add esi, 0xa0
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004de68d  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004de68e  8975e8                 -mov dword ptr [ebp - 0x18], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esi;
    // 004de691  895dd0                 -mov dword ptr [ebp - 0x30], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.ebx;
L_0x004de694:
    // 004de694  ff45e0                 +inc dword ptr [ebp - 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004de697  e9eafaffff             -jmp 0x4de186
    goto L_0x004de186;
L_0x004de69c:
    // 004de69c  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004de69f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004de6a1  743c                   -je 0x4de6df
    if (cpu.flags.zf)
    {
        goto L_0x004de6df;
    }
    // 004de6a3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004de6a5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004de6a8  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de6ab  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004de6ad  81eaa0000000           -sub edx, 0xa0
    (cpu.edx) -= x86::reg32(x86::sreg32(160 /*0xa0*/));
    // 004de6b3  c1e005                 +shl eax, 5
    {
        x86::reg8 tmp = 5 /*0x5*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004de6b6  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 004de6b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004de6bb  8d45c4                 -lea eax, [ebp - 0x3c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004de6be  e81dd7fdff             -call 0x4bbde0
    cpu.esp -= 4;
    sub_4bbde0(app, cpu);
    if (cpu.terminate) return;
    // 004de6c3  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004de6c6  8d7da4                 -lea edi, [ebp - 0x5c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 004de6c9  8945b4                 -mov dword ptr [ebp - 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.eax;
    // 004de6cc  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de6cf  8d75b4                 -lea esi, [ebp - 0x4c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004de6d2  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 004de6d5  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004de6db  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004de6dc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004de6dd  eb08                   -jmp 0x4de6e7
    goto L_0x004de6e7;
L_0x004de6df:
    // 004de6df  8d75a4                 -lea esi, [ebp - 0x5c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 004de6e2  e889d7fdff             -call 0x4bbe70
    cpu.esp -= 4;
    sub_4bbe70(app, cpu);
    if (cpu.terminate) return;
L_0x004de6e7:
    // 004de6e7  8b7dc8                 -mov edi, dword ptr [ebp - 0x38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004de6ea  8d75a4                 -lea esi, [ebp - 0x5c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 004de6ed  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004de6ee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004de6ef  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004de6f2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004de6f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de6f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de6f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de6f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de6f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4de700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004de700  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004de701  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004de702  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004de703  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004de705  83ec60                 -sub esp, 0x60
    (cpu.esp) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004de708  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 004de70b  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004de70e  8955e0                 -mov dword ptr [ebp - 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edx;
    // 004de711  895dd4                 -mov dword ptr [ebp - 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ebx;
    // 004de714  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004de716  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004de719  8955e4                 -mov dword ptr [ebp - 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edx;
    // 004de71c  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 004de71f  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004de722  a138a28c00             -mov eax, dword ptr [0x8ca238]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216568) /* 0x8ca238 */);
    // 004de727  8b1538a28c00           -mov edx, dword ptr [0x8ca238]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216568) /* 0x8ca238 */);
    // 004de72d  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004de730  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004de733  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004de735  a138a28c00             -mov eax, dword ptr [0x8ca238]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216568) /* 0x8ca238 */);
    // 004de73a  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004de73d  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004de73f  8b1538a28c00           -mov edx, dword ptr [0x8ca238]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216568) /* 0x8ca238 */);
    // 004de745  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004de747  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004de749  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 004de74c  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004de74f  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004de752  c1e207                 -shl edx, 7
    cpu.edx <<= 7 /*0x7*/ % 32;
    // 004de755  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 004de757  e8e4d6fdff             -call 0x4bbe40
    cpu.esp -= 4;
    sub_4bbe40(app, cpu);
    if (cpu.terminate) return;
    // 004de75c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004de75e  0f8454050000           -je 0x4decb8
    if (cpu.flags.zf)
    {
        goto L_0x004decb8;
    }
    // 004de764  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004de767  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004de76a  f605583a7a0050         +test byte ptr [0x7a3a58], 0x50
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 80 /*0x50*/));
    // 004de771  7466                   -je 0x4de7d9
    if (cpu.flags.zf)
    {
        goto L_0x004de7d9;
    }
    // 004de773  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004de775  d90538bc6f00           +fld dword ptr [0x6fbc38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7322680) /* 0x6fbc38 */)));
    // 004de77b  dd5db0                 +fstp qword ptr [ebp - 0x50]
    app->getMemory<double>(cpu.ebp + x86::reg32(-80) /* -0x50 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de77e  dc5db0                 +fcomp qword ptr [ebp - 0x50]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-80) /* -0x50 */)));
    cpu.fpu.pop();
    // 004de781  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de783  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de784  7653                   -jbe 0x4de7d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004de7d9;
    }
    // 004de786  dd45b0                 -fld qword ptr [ebp - 0x50]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-80) /* -0x50 */)));
    // 004de789  dc0d0c985400           -fmul qword ptr [0x54980c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5543948) /* 0x54980c */));
    // 004de78f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004de792  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004de795  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004de796  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004de798  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004de79b  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004de7a1  7c05                   -jl 0x4de7a8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004de7a8;
    }
    // 004de7a3  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
L_0x004de7a8:
    // 004de7a8  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004de7ab  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004de7ad  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004de7b3  81e300ff00ff           -and ebx, 0xff00ff00
    cpu.ebx &= x86::reg32(x86::sreg32(4278255360 /*0xff00ff00*/));
    // 004de7b9  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004de7bc  25ff00ff00             -and eax, 0xff00ff
    cpu.eax &= x86::reg32(x86::sreg32(16711935 /*0xff00ff*/));
    // 004de7c1  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004de7c3  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004de7c4  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004de7c6  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004de7c9  2500ff00ff             -and eax, 0xff00ff00
    cpu.eax &= x86::reg32(x86::sreg32(4278255360 /*0xff00ff00*/));
    // 004de7ce  81e3ff00ff00           -and ebx, 0xff00ff
    cpu.ebx &= x86::reg32(x86::sreg32(16711935 /*0xff00ff*/));
    // 004de7d4  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004de7d6  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
L_0x004de7d9:
    // 004de7d9  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de7dc  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 004de7e3  68c0a48b00             -push 0x8ba4c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 9151680 /*0x8ba4c0*/;
    cpu.esp -= 4;
    // 004de7e8  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004de7ea  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de7ed  c1e707                 -shl edi, 7
    cpu.edi <<= 7 /*0x7*/ % 32;
    // 004de7f0  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de7f3  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004de7f5  83c138                 -add ecx, 0x38
    (cpu.ecx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004de7f8  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004de7fb  83c344                 -add ebx, 0x44
    (cpu.ebx) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004de7fe  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004de800  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004de803  81c2e8568c00           -add edx, 0x8c56e8
    (cpu.edx) += x86::reg32(x86::sreg32(9197288 /*0x8c56e8*/));
    // 004de809  e8b20cfeff             -call 0x4bf4c0
    cpu.esp -= 4;
    sub_4bf4c0(app, cpu);
    if (cpu.terminate) return;
    // 004de80e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004de810  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
L_0x004de813:
    // 004de813  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004de816  3b45e0                 +cmp eax, dword ptr [ebp - 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004de819  0f8d58040000           -jge 0x4dec77
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dec77;
    }
    // 004de81f  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de822  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 004de829  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004de82b  c1e707                 -shl edi, 7
    cpu.edi <<= 7 /*0x7*/ % 32;
    // 004de82e  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004de830  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004de833  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004de836  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004de838  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 004de83f  bbe80b8c00             -mov ebx, 0x8c0be8
    cpu.ebx = 9178088 /*0x8c0be8*/;
    // 004de844  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004de846  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004de848  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004de84b  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004de84d  8a5308                 -mov dl, byte ptr [ebx + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004de850  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004de852  0f8517040000           -jne 0x4dec6f
    if (!cpu.flags.zf)
    {
        goto L_0x004dec6f;
    }
    // 004de858  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004de85b  42                     -inc edx
    (cpu.edx)++;
    // 004de85c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004de85f  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 004de862  bac0a48b00             -mov edx, 0x8ba4c0
    cpu.edx = 9151680 /*0x8ba4c0*/;
    // 004de867  01c2                   +add edx, eax
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
    // 004de869  d94208                 +fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004de86c  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004de86f  dc1d14985400           +fcomp qword ptr [0x549814]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5543956) /* 0x549814 */)));
    cpu.fpu.pop();
    // 004de875  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de877  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de878  766e                   -jbe 0x4de8e8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004de8e8;
    }
    // 004de87a  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004de87c  d85a08                 +fcomp dword ptr [edx + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 004de87f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de881  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de882  7664                   -jbe 0x4de8e8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004de8e8;
    }
    // 004de884  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de887  d9400c                 +fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004de88a  d80564a28c00           +fadd dword ptr [0x8ca264]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(9216612) /* 0x8ca264 */));
    // 004de890  d99c37ec568c00         +fstp dword ptr [edi + esi + 0x8c56ec]
    app->getMemory<float>(cpu.edi + x86::reg32(9197292) /* 0x8c56ec */ + cpu.esi * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de897  e894c90000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004de89c  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de8a2  d80d1c985400           +fmul dword ptr [0x54981c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543964) /* 0x54981c */));
    // 004de8a8  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de8ae  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de8b1  d84008                 +fadd dword ptr [eax + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 004de8b4  d99c37e8568c00         +fstp dword ptr [edi + esi + 0x8c56e8]
    app->getMemory<float>(cpu.edi + x86::reg32(9197288) /* 0x8c56e8 */ + cpu.esi * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de8bb  e870c90000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004de8c0  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de8c6  d80d1c985400           +fmul dword ptr [0x54981c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543964) /* 0x54981c */));
    // 004de8cc  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de8d2  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de8d5  d84010                 +fadd dword ptr [eax + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */));
    // 004de8d8  d99c37f0568c00         +fstp dword ptr [edi + esi + 0x8c56f0]
    app->getMemory<float>(cpu.edi + x86::reg32(9197296) /* 0x8c56f0 */ + cpu.esi * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de8df  c6430900               -mov byte ptr [ebx + 9], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */) = 0 /*0x0*/;
    // 004de8e3  e987030000             -jmp 0x4dec6f
    goto L_0x004dec6f;
L_0x004de8e8:
    // 004de8e8  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de8eb  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004de8ed  d85808                 +fcomp dword ptr [eax + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 004de8f0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de8f2  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de8f3  7311                   -jae 0x4de906
    if (!cpu.flags.cf)
    {
        goto L_0x004de906;
    }
    // 004de8f5  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de8f8  db054ca28c00           +fild dword ptr [0x8ca24c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216588) /* 0x8ca24c */))));
    // 004de8fe  d85808                 +fcomp dword ptr [eax + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 004de901  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de903  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de904  730c                   -jae 0x4de912
    if (!cpu.flags.cf)
    {
        goto L_0x004de912;
    }
L_0x004de906:
    // 004de906  c6430900               -mov byte ptr [ebx + 9], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */) = 0 /*0x0*/;
    // 004de90a  ff45f0                 +inc dword ptr [ebp - 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004de90d  e901ffffff             -jmp 0x4de813
    goto L_0x004de813;
L_0x004de912:
    // 004de912  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de915  80781400               +cmp byte ptr [eax + 0x14], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004de919  740c                   -je 0x4de927
    if (cpu.flags.zf)
    {
        goto L_0x004de927;
    }
    // 004de91b  c6430900               -mov byte ptr [ebx + 9], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */) = 0 /*0x0*/;
    // 004de91f  ff45f0                 +inc dword ptr [ebp - 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004de922  e9ecfeffff             -jmp 0x4de813
    goto L_0x004de813;
L_0x004de927:
    // 004de927  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004de92a  dc1d24985400           +fcomp qword ptr [0x549824]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5543972) /* 0x549824 */)));
    cpu.fpu.pop();
    // 004de930  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004de932  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004de933  0f83b9000000           -jae 0x4de9f2
    if (!cpu.flags.cf)
    {
        goto L_0x004de9f2;
    }
    // 004de939  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de93c  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 004de943  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004de945  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004de948  c1e707                 -shl edi, 7
    cpu.edi <<= 7 /*0x7*/ % 32;
    // 004de94b  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 004de952  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004de954  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004de956  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004de959  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004de95c  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004de95e  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004de960  8b8ef0568c00           -mov ecx, dword ptr [esi + 0x8c56f0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9197296) /* 0x8c56f0 */);
    // 004de966  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004de967  8bbeec568c00           -mov edi, dword ptr [esi + 0x8c56ec]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9197292) /* 0x8c56ec */);
    // 004de96d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004de96e  8b86e8568c00           -mov eax, dword ptr [esi + 0x8c56e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9197288) /* 0x8c56e8 */);
    // 004de974  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004de975  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de978  e8b3efffff             -call 0x4dd930
    cpu.esp -= 4;
    sub_4dd930(app, cpu);
    if (cpu.terminate) return;
    // 004de97d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004de97f  7471                   -je 0x4de9f2
    if (cpu.flags.zf)
    {
        goto L_0x004de9f2;
    }
    // 004de981  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004de986  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004de989  e80266f3ff             -call 0x414f90
    cpu.esp -= 4;
    sub_414f90(app, cpu);
    if (cpu.terminate) return;
    // 004de98e  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de991  d9400c                 +fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004de994  d80564a28c00           +fadd dword ptr [0x8ca264]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(9216612) /* 0x8ca264 */));
    // 004de99a  d99eec568c00           +fstp dword ptr [esi + 0x8c56ec]
    app->getMemory<float>(cpu.esi + x86::reg32(9197292) /* 0x8c56ec */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de9a0  e88bc80000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004de9a5  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de9ab  d80d1c985400           +fmul dword ptr [0x54981c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543964) /* 0x54981c */));
    // 004de9b1  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de9b7  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de9ba  d84008                 +fadd dword ptr [eax + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 004de9bd  d99ee8568c00           +fstp dword ptr [esi + 0x8c56e8]
    app->getMemory<float>(cpu.esi + x86::reg32(9197288) /* 0x8c56e8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de9c3  e868c80000             -call 0x4eb230
    cpu.esp -= 4;
    sub_4eb230(app, cpu);
    if (cpu.terminate) return;
    // 004de9c8  d80d5ca28c00           +fmul dword ptr [0x8ca25c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de9ce  d80d1c985400           +fmul dword ptr [0x54981c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5543964) /* 0x54981c */));
    // 004de9d4  d8255ca28c00           +fsub dword ptr [0x8ca25c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(9216604) /* 0x8ca25c */));
    // 004de9da  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004de9dd  d84010                 +fadd dword ptr [eax + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */));
    // 004de9e0  d99ef0568c00           +fstp dword ptr [esi + 0x8c56f0]
    app->getMemory<float>(cpu.esi + x86::reg32(9197296) /* 0x8c56f0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004de9e6  c6430900               -mov byte ptr [ebx + 9], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */) = 0 /*0x0*/;
    // 004de9ea  ff45f0                 +inc dword ptr [ebp - 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004de9ed  e921feffff             -jmp 0x4de813
    goto L_0x004de813;
L_0x004de9f2:
    // 004de9f2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de9f5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004de9f7  8945a8                 -mov dword ptr [ebp - 0x58], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-88) /* -0x58 */) = cpu.eax;
    // 004de9fa  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004de9fd  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004dea00  8a4b09                 -mov cl, byte ptr [ebx + 9]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */);
    // 004dea03  8945ac                 -mov dword ptr [ebp - 0x54], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-84) /* -0x54 */) = cpu.eax;
    // 004dea06  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004dea08  7427                   -je 0x4dea31
    if (cpu.flags.zf)
    {
        goto L_0x004dea31;
    }
    // 004dea0a  d945a8                 +fld dword ptr [ebp - 0x58]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-88) /* -0x58 */)));
    // 004dea0d  d945ac                 +fld dword ptr [ebp - 0x54]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-84) /* -0x54 */)));
    // 004dea10  d84304                 +fadd dword ptr [ebx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */));
    // 004dea13  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dea15  d803                   +fadd dword ptr [ebx]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebx));
    // 004dea17  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dea19  dd052c985400           +fld qword ptr [0x54982c]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5543980) /* 0x54982c */)));
    // 004dea1f  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dea21  d8c9                   +fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004dea23  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dea25  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004dea27  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dea29  d95dc4                 +fstp dword ptr [ebp - 0x3c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dea2c  d95dc0                 +fstp dword ptr [ebp - 0x40]
    app->getMemory<float>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dea2f  eb0f                   -jmp 0x4dea40
    goto L_0x004dea40;
L_0x004dea31:
    // 004dea31  8d7dc0                 -lea edi, [ebp - 0x40]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004dea34  8d75a8                 -lea esi, [ebp - 0x58]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004dea37  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dea38  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dea39  8d75a8                 -lea esi, [ebp - 0x58]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004dea3c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004dea3e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dea3f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004dea40:
    // 004dea40  d945a8                 -fld dword ptr [ebp - 0x58]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-88) /* -0x58 */)));
    // 004dea43  d803                   -fadd dword ptr [ebx]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebx));
    // 004dea45  dd052c985400           -fld qword ptr [0x54982c]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5543980) /* 0x54982c */)));
    // 004dea4b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dea4d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004dea4f  d945ac                 -fld dword ptr [ebp - 0x54]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-84) /* -0x54 */)));
    // 004dea52  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dea55  d84304                 -fadd dword ptr [ebx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */));
    // 004dea58  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004dea5b  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004dea5d  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 004dea60  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dea63  c6430901               -mov byte ptr [ebx + 9], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */) = 1 /*0x1*/;
    // 004dea67  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004dea6a  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dea6c  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 004dea6f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dea72  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dea75  66c740040100           -mov word ptr [eax + 4], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004dea7b  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dea7e  c7401800a28c00         -mov dword ptr [eax + 0x18], 0x8ca200
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 9216512 /*0x8ca200*/;
    // 004dea85  83c620                 -add esi, 0x20
    (cpu.esi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004dea88  66c740060100           -mov word ptr [eax + 6], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 1 /*0x1*/;
    // 004dea8e  8b55cc                 -mov edx, dword ptr [ebp - 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004dea91  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004dea94  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004dea97  8b55d0                 -mov edx, dword ptr [ebp - 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004dea9a  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004dea9d  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004deaa3  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004deaa5  8b45c0                 -mov eax, dword ptr [ebp - 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004deaa8  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004deaaa  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004deaad  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004deab0  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004deab3  8d7e14                 -lea edi, [esi + 0x14]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004deab6  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004deab9  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004deabc  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004deabf  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004deac2  d95e0c                 -fstp dword ptr [esi + 0xc]
    app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004deac5  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004deac8  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004deacb  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 004dead1  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004dead6  7558                   -jne 0x4deb30
    if (!cpu.flags.zf)
    {
        goto L_0x004deb30;
    }
    // 004dead8  39c8                   +cmp eax, ecx
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
    // 004deada  7d54                   -jge 0x4deb30
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004deb30;
    }
    // 004deadc  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004deadf  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004deae4  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 004deaea  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 004deaf0  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004deaf5  750d                   -jne 0x4deb04
    if (!cpu.flags.zf)
    {
        goto L_0x004deb04;
    }
    // 004deaf7  39c8                   +cmp eax, ecx
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
    // 004deaf9  7c09                   -jl 0x4deb04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004deb04;
    }
    // 004deafb  39d0                   +cmp eax, edx
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
    // 004deafd  7e09                   -jle 0x4deb08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004deb08;
    }
    // 004deaff  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004deb02  eb04                   -jmp 0x4deb08
    goto L_0x004deb08;
L_0x004deb04:
    // 004deb04  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004deb07  90                     -nop 
    ;
L_0x004deb08:
    // 004deb08  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004deb0a  90                     -nop 
    ;
    // 004deb0b  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 004deb11  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 004deb17  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004deb1c  750d                   -jne 0x4deb2b
    if (!cpu.flags.zf)
    {
        goto L_0x004deb2b;
    }
    // 004deb1e  39c8                   +cmp eax, ecx
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
    // 004deb20  7c09                   -jl 0x4deb2b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004deb2b;
    }
    // 004deb22  39d0                   +cmp eax, edx
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
    // 004deb24  7e0f                   -jle 0x4deb35
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004deb35;
    }
    // 004deb26  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004deb29  eb0a                   -jmp 0x4deb35
    goto L_0x004deb35;
L_0x004deb2b:
    // 004deb2b  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004deb2e  eb05                   -jmp 0x4deb35
    goto L_0x004deb35;
L_0x004deb30:
    // 004deb30  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004deb35:
    // 004deb35  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004deb37  8b55cc                 -mov edx, dword ptr [ebp - 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004deb3a  8b45a8                 -mov eax, dword ptr [ebp - 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004deb3d  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004deb3f  8b45ac                 -mov eax, dword ptr [ebp - 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 004deb42  8d7a14                 -lea edi, [edx + 0x14]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004deb45  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004deb48  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004deb4b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004deb4d  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004deb50  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004deb53  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004deb56  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004deb59  d95a0c                 -fstp dword ptr [edx + 0xc]
    app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004deb5c  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004deb5f  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004deb62  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 004deb68  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004deb6d  7558                   -jne 0x4debc7
    if (!cpu.flags.zf)
    {
        goto L_0x004debc7;
    }
    // 004deb6f  39c8                   +cmp eax, ecx
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
    // 004deb71  7d54                   -jge 0x4debc7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004debc7;
    }
    // 004deb73  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004deb76  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004deb7b  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 004deb81  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 004deb87  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004deb8c  750d                   -jne 0x4deb9b
    if (!cpu.flags.zf)
    {
        goto L_0x004deb9b;
    }
    // 004deb8e  39c8                   +cmp eax, ecx
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
    // 004deb90  7c09                   -jl 0x4deb9b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004deb9b;
    }
    // 004deb92  39d0                   +cmp eax, edx
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
    // 004deb94  7e09                   -jle 0x4deb9f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004deb9f;
    }
    // 004deb96  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004deb99  eb04                   -jmp 0x4deb9f
    goto L_0x004deb9f;
L_0x004deb9b:
    // 004deb9b  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004deb9e  90                     -nop 
    ;
L_0x004deb9f:
    // 004deb9f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004deba1  90                     -nop 
    ;
    // 004deba2  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 004deba8  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 004debae  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004debb3  750d                   -jne 0x4debc2
    if (!cpu.flags.zf)
    {
        goto L_0x004debc2;
    }
    // 004debb5  39c8                   +cmp eax, ecx
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
    // 004debb7  7c09                   -jl 0x4debc2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004debc2;
    }
    // 004debb9  39d0                   +cmp eax, edx
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
    // 004debbb  7e0f                   -jle 0x4debcc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004debcc;
    }
    // 004debbd  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004debc0  eb0a                   -jmp 0x4debcc
    goto L_0x004debcc;
L_0x004debc2:
    // 004debc2  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004debc5  eb05                   -jmp 0x4debcc
    goto L_0x004debcc;
L_0x004debc7:
    // 004debc7  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004debcc:
    // 004debcc  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004debce  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004debd3  8b7dd0                 -mov edi, dword ptr [ebp - 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004debd6  8b75cc                 -mov esi, dword ptr [ebp - 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004debd9  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004debdc  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004debde  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004debe0  8d7814                 -lea edi, [eax + 0x14]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004debe3  d8051c985400           -fadd dword ptr [0x54981c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5543964) /* 0x54981c */));
    // 004debe9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004debeb  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004debed  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004debf0  8b0df8347d00           -mov ecx, dword ptr [0x7d34f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205560) /* 0x7d34f8 */);
    // 004debf6  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004debfb  7558                   -jne 0x4dec55
    if (!cpu.flags.zf)
    {
        goto L_0x004dec55;
    }
    // 004debfd  39c8                   +cmp eax, ecx
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
    // 004debff  7d54                   -jge 0x4dec55
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004dec55;
    }
    // 004dec01  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004dec04  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 004dec09  8b0d04357d00           -mov ecx, dword ptr [0x7d3504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205572) /* 0x7d3504 */);
    // 004dec0f  8b1500357d00           -mov edx, dword ptr [0x7d3500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205568) /* 0x7d3500 */);
    // 004dec15  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004dec1a  750d                   -jne 0x4dec29
    if (!cpu.flags.zf)
    {
        goto L_0x004dec29;
    }
    // 004dec1c  39c8                   +cmp eax, ecx
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
    // 004dec1e  7c09                   -jl 0x4dec29
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004dec29;
    }
    // 004dec20  39d0                   +cmp eax, edx
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
    // 004dec22  7e09                   -jle 0x4dec2d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dec2d;
    }
    // 004dec24  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 004dec27  eb04                   -jmp 0x4dec2d
    goto L_0x004dec2d;
L_0x004dec29:
    // 004dec29  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dec2c  90                     -nop 
    ;
L_0x004dec2d:
    // 004dec2d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004dec2f  90                     -nop 
    ;
    // 004dec30  8b0dfc347d00           -mov ecx, dword ptr [0x7d34fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205564) /* 0x7d34fc */);
    // 004dec36  8b150c357d00           -mov edx, dword ptr [0x7d350c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205580) /* 0x7d350c */);
    // 004dec3c  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 004dec41  750d                   -jne 0x4dec50
    if (!cpu.flags.zf)
    {
        goto L_0x004dec50;
    }
    // 004dec43  39c8                   +cmp eax, ecx
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
    // 004dec45  7c09                   -jl 0x4dec50
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004dec50;
    }
    // 004dec47  39d0                   +cmp eax, edx
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
    // 004dec49  7e0f                   -jle 0x4dec5a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dec5a;
    }
    // 004dec4b  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 004dec4e  eb0a                   -jmp 0x4dec5a
    goto L_0x004dec5a;
L_0x004dec50:
    // 004dec50  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004dec53  eb05                   -jmp 0x4dec5a
    goto L_0x004dec5a;
L_0x004dec55:
    // 004dec55  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004dec5a:
    // 004dec5a  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004dec5c  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004dec5f  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dec62  42                     -inc edx
    (cpu.edx)++;
    // 004dec63  81c180000000           +add ecx, 0x80
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004dec69  8955e4                 -mov dword ptr [ebp - 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edx;
    // 004dec6c  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x004dec6f:
    // 004dec6f  ff45f0                 +inc dword ptr [ebp - 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004dec72  e99cfbffff             -jmp 0x4de813
    goto L_0x004de813;
L_0x004dec77:
    // 004dec77  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004dec7a  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004dec7d  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004dec80  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004dec82  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004dec84  7432                   -je 0x4decb8
    if (cpu.flags.zf)
    {
        goto L_0x004decb8;
    }
    // 004dec86  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dec89  8d45c8                 -lea eax, [ebp - 0x38]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004dec8c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004dec8e  8d75b8                 -lea esi, [ebp - 0x48]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 004dec91  c1e207                 -shl edx, 7
    cpu.edx <<= 7 /*0x7*/ % 32;
    // 004dec94  81ef80000000           +sub edi, 0x80
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004dec9a  e841d1fdff             -call 0x4bbde0
    cpu.esp -= 4;
    sub_4bbde0(app, cpu);
    if (cpu.terminate) return;
    // 004dec9f  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004deca2  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 004deca5  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 004deca8  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 004decae  8d7da0                 -lea edi, [ebp - 0x60]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-96) /* -0x60 */);
    // 004decb1  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 004decb4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004decb5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004decb6  eb08                   -jmp 0x4decc0
    goto L_0x004decc0;
L_0x004decb8:
    // 004decb8  8d75a0                 -lea esi, [ebp - 0x60]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-96) /* -0x60 */);
    // 004decbb  e8b0d1fdff             -call 0x4bbe70
    cpu.esp -= 4;
    sub_4bbe70(app, cpu);
    if (cpu.terminate) return;
L_0x004decc0:
    // 004decc0  8b7dd8                 -mov edi, dword ptr [ebp - 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004decc3  8d75a0                 -lea esi, [ebp - 0x60]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-96) /* -0x60 */);
    // 004decc6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004decc7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004decc8  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004deccb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004deccd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004decce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004deccf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004decd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4dece0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dece0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dece1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dece2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dece3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dece4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dece5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dece7  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004decea  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004decec  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004decee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004decf0  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004decf3  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004decf6  e875d1fdff             -call 0x4bbe70
    cpu.esp -= 4;
    sub_4bbe70(app, cpu);
    if (cpu.terminate) return;
    // 004decfb  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004decfe  7509                   -jne 0x4ded09
    if (!cpu.flags.zf)
    {
        goto L_0x004ded09;
    }
    // 004ded00  833d2ca28c0000         +cmp dword ptr [0x8ca22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ded07  750b                   -jne 0x4ded14
    if (!cpu.flags.zf)
    {
        goto L_0x004ded14;
    }
L_0x004ded09:
    // 004ded09  8d7dec                 -lea edi, [ebp - 0x14]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004ded0c  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004ded0f  e9c3000000             -jmp 0x4dedd7
    goto L_0x004dedd7;
L_0x004ded14:
    // 004ded14  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004ded17  833c85f42f550000       +cmp dword ptr [eax*4 + 0x552ff4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5582836) /* 0x552ff4 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ded1f  7407                   -je 0x4ded28
    if (cpu.flags.zf)
    {
        goto L_0x004ded28;
    }
    // 004ded21  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ded23  e808e5ffff             -call 0x4dd230
    cpu.esp -= 4;
    sub_4dd230(app, cpu);
    if (cpu.terminate) return;
L_0x004ded28:
    // 004ded28  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004ded2b  e8703ef4ff             -call 0x422ba0
    cpu.esp -= 4;
    sub_422ba0(app, cpu);
    if (cpu.terminate) return;
    // 004ded30  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004ded33  e898e6ffff             -call 0x4dd3d0
    cpu.esp -= 4;
    sub_4dd3d0(app, cpu);
    if (cpu.terminate) return;
    // 004ded38  e8f3e5ffff             -call 0x4dd330
    cpu.esp -= 4;
    sub_4dd330(app, cpu);
    if (cpu.terminate) return;
    // 004ded3d  8b1d30bc6f00           -mov ebx, dword ptr [0x6fbc30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322672) /* 0x6fbc30 */);
    // 004ded43  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ded45  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ded47  83fb01                 +cmp ebx, 1
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
    // 004ded4a  7509                   -jne 0x4ded55
    if (!cpu.flags.zf)
    {
        goto L_0x004ded55;
    }
    // 004ded4c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ded4f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ded51  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004ded53  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004ded55:
    // 004ded55  833d30bc6f0002         +cmp dword ptr [0x6fbc30], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322672) /* 0x6fbc30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ded5c  7511                   -jne 0x4ded6f
    if (!cpu.flags.zf)
    {
        goto L_0x004ded6f;
    }
    // 004ded5e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ded60  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ded62  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ded65  c1e202                 +shl edx, 2
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
    // 004ded68  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004ded6a  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004ded6d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004ded6f:
    // 004ded6f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ded71  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ded73  e868e8ffff             -call 0x4dd5e0
    cpu.esp -= 4;
    sub_4dd5e0(app, cpu);
    if (cpu.terminate) return;
    // 004ded78  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ded7a  e821d0ffff             -call 0x4dbda0
    cpu.esp -= 4;
    sub_4dbda0(app, cpu);
    if (cpu.terminate) return;
    // 004ded7f  a12ca28c00             -mov eax, dword ptr [0x8ca22c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */);
    // 004ded84  83f801                 +cmp eax, 1
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
    // 004ded87  7241                   -jb 0x4dedca
    if (cpu.flags.cf)
    {
        goto L_0x004dedca;
    }
    // 004ded89  7607                   -jbe 0x4ded92
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ded92;
    }
    // 004ded8b  83f802                 +cmp eax, 2
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
    // 004ded8e  742a                   -je 0x4dedba
    if (cpu.flags.zf)
    {
        goto L_0x004dedba;
    }
    // 004ded90  eb38                   -jmp 0x4dedca
    goto L_0x004dedca;
L_0x004ded92:
    // 004ded92  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004ded95  e876e7ffff             -call 0x4dd510
    cpu.esp -= 4;
    sub_4dd510(app, cpu);
    if (cpu.terminate) return;
    // 004ded9a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ded9c  740f                   -je 0x4dedad
    if (cpu.flags.zf)
    {
        goto L_0x004dedad;
    }
    // 004ded9e  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004deda1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004deda3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004deda5  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004deda8  e853f9ffff             -call 0x4de700
    cpu.esp -= 4;
    sub_4de700(app, cpu);
    if (cpu.terminate) return;
L_0x004dedad:
    // 004dedad  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004dedb0  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004dedb3  e808e7ffff             -call 0x4dd4c0
    cpu.esp -= 4;
    sub_4dd4c0(app, cpu);
    if (cpu.terminate) return;
    // 004dedb8  eb10                   -jmp 0x4dedca
    goto L_0x004dedca;
L_0x004dedba:
    // 004dedba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004dedbc  740c                   -je 0x4dedca
    if (cpu.flags.zf)
    {
        goto L_0x004dedca;
    }
    // 004dedbe  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004dedc0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004dedc2  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004dedc5  e8a6f2ffff             -call 0x4de070
    cpu.esp -= 4;
    sub_4de070(app, cpu);
    if (cpu.terminate) return;
L_0x004dedca:
    // 004dedca  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004dedcd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004dedcf  8d7dec                 -lea edi, [ebp - 0x14]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004dedd2  e809d0ffff             -call 0x4dbde0
    cpu.esp -= 4;
    sub_4dbde0(app, cpu);
    if (cpu.terminate) return;
L_0x004dedd7:
    // 004dedd7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dedd8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dedd9  8d75ec                 -lea esi, [ebp - 0x14]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004deddc  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004dedde  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004deddf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dede0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004dede2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004dede4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dede5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dede6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dede7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dede8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dede9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4dedf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dedf0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dedf1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dedf2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dedf3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dedf5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dedf8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004dedfa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004dedfc  e81fd1fdff             -call 0x4bbf20
    cpu.esp -= 4;
    sub_4bbf20(app, cpu);
    if (cpu.terminate) return;
    // 004dee01  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dee04  7509                   -jne 0x4dee0f
    if (!cpu.flags.zf)
    {
        goto L_0x004dee0f;
    }
    // 004dee06  833d2ca28c0000         +cmp dword ptr [0x8ca22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dee0d  7505                   -jne 0x4dee14
    if (!cpu.flags.zf)
    {
        goto L_0x004dee14;
    }
L_0x004dee0f:
    // 004dee0f  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004dee12  eb49                   -jmp 0x4dee5d
    goto L_0x004dee5d;
L_0x004dee14:
    // 004dee14  833d30bc6f0002         +cmp dword ptr [0x6fbc30], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322672) /* 0x6fbc30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dee1b  7517                   -jne 0x4dee34
    if (!cpu.flags.zf)
    {
        goto L_0x004dee34;
    }
    // 004dee1d  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004dee20  e89bd1fdff             -call 0x4bbfc0
    cpu.esp -= 4;
    sub_4bbfc0(app, cpu);
    if (cpu.terminate) return;
    // 004dee25  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004dee28  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004dee2a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dee2b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dee2c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dee2e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004dee30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dee31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dee32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dee33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dee34:
    // 004dee34  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004dee36  e865cfffff             -call 0x4dbda0
    cpu.esp -= 4;
    sub_4dbda0(app, cpu);
    if (cpu.terminate) return;
    // 004dee3b  a12ca28c00             -mov eax, dword ptr [0x8ca22c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216556) /* 0x8ca22c */);
    // 004dee40  83f801                 +cmp eax, 1
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
    // 004dee43  720e                   -jb 0x4dee53
    if (cpu.flags.cf)
    {
        goto L_0x004dee53;
    }
    // 004dee45  7605                   -jbe 0x4dee4c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004dee4c;
    }
    // 004dee47  83f802                 +cmp eax, 2
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
    // 004dee4a  7507                   -jne 0x4dee53
    if (!cpu.flags.zf)
    {
        goto L_0x004dee53;
    }
L_0x004dee4c:
    // 004dee4c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004dee4e  e8edecffff             -call 0x4ddb40
    cpu.esp -= 4;
    sub_4ddb40(app, cpu);
    if (cpu.terminate) return;
L_0x004dee53:
    // 004dee53  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004dee55  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004dee58  e883cfffff             -call 0x4dbde0
    cpu.esp -= 4;
    sub_4dbde0(app, cpu);
    if (cpu.terminate) return;
L_0x004dee5d:
    // 004dee5d  e85ed1fdff             -call 0x4bbfc0
    cpu.esp -= 4;
    sub_4bbfc0(app, cpu);
    if (cpu.terminate) return;
    // 004dee62  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004dee65  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004dee67  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dee68  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dee69  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dee6b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004dee6d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dee6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dee6f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dee70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4dee80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dee80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dee81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dee82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dee83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dee84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dee85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004dee86  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004dee88  81ecd0000000           -sub esp, 0xd0
    (cpu.esp) -= x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 004dee8e  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 004dee94  89457e                 -mov dword ptr [ebp + 0x7e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.eax;
    // 004dee97  e8e4cb0000             -call 0x4eba80
    cpu.esp -= 4;
    sub_4eba80(app, cpu);
    if (cpu.terminate) return;
    // 004dee9c  8b15c0a28c00           -mov edx, dword ptr [0x8ca2c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216704) /* 0x8ca2c0 */);
    // 004deea2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004deea4  39d0                   +cmp eax, edx
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
    // 004deea6  0f848c000000           -je 0x4def38
    if (cpu.flags.zf)
    {
        goto L_0x004def38;
    }
    // 004deeac  e8cfcb0000             -call 0x4eba80
    cpu.esp -= 4;
    sub_4eba80(app, cpu);
    if (cpu.terminate) return;
    // 004deeb1  b96c000000             -mov ecx, 0x6c
    cpu.ecx = 108 /*0x6c*/;
    // 004deeb6  bb07100000             -mov ebx, 0x1007
    cpu.ebx = 4103 /*0x1007*/;
    // 004deebb  a3c0a28c00             -mov dword ptr [0x8ca2c0], eax
    app->getMemory<x86::reg32>(x86::reg32(9216704) /* 0x8ca2c0 */) = cpu.eax;
    // 004deec0  e8cbcb0000             -call 0x4eba90
    cpu.esp -= 4;
    sub_4eba90(app, cpu);
    if (cpu.terminate) return;
    // 004deec5  8b35d4a28c00           -mov esi, dword ptr [0x8ca2d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */);
    // 004deecb  894db2                 -mov dword ptr [ebp - 0x4e], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-78) /* -0x4e */) = cpu.ecx;
    // 004deece  895db6                 -mov dword ptr [ebp - 0x4a], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-74) /* -0x4a */) = cpu.ebx;
    // 004deed1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004deed3  7509                   -jne 0x4deede
    if (!cpu.flags.zf)
    {
        goto L_0x004deede;
    }
    // 004deed5  c7451a40400000         -mov dword ptr [ebp + 0x1a], 0x4040
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(26) /* 0x1a */) = 16448 /*0x4040*/;
    // 004deedc  eb07                   -jmp 0x4deee5
    goto L_0x004deee5;
L_0x004deede:
    // 004deede  c7451a80400000         -mov dword ptr [ebp + 0x1a], 0x4080
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(26) /* 0x1a */) = 16512 /*0x4080*/;
L_0x004deee5:
    // 004deee5  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004deeea  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004deeef  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004deef1  be59555932             -mov esi, 0x32595559
    cpu.esi = 844715353 /*0x32595559*/;
    // 004deef6  8b15d0a28c00           -mov edx, dword ptr [0x8ca2d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216720) /* 0x8ca2d0 */);
    // 004deefc  68c8a28c00             -push 0x8ca2c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 9216712 /*0x8ca2c8*/;
    cpu.esp -= 4;
    // 004def01  8955be                 -mov dword ptr [ebp - 0x42], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-66) /* -0x42 */) = cpu.edx;
    // 004def04  894dfa                 -mov dword ptr [ebp - 6], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = cpu.ecx;
    // 004def07  8b15c4a28c00           -mov edx, dword ptr [0x8ca2c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216708) /* 0x8ca2c4 */);
    // 004def0d  895dfe                 -mov dword ptr [ebp - 2], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-2) /* -0x2 */) = cpu.ebx;
    // 004def10  8955ba                 -mov dword ptr [ebp - 0x46], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-70) /* -0x46 */) = cpu.edx;
    // 004def13  8d55b2                 -lea edx, [ebp - 0x4e]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-78) /* -0x4e */);
    // 004def16  897502                 -mov dword ptr [ebp + 2], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(2) /* 0x2 */) = cpu.esi;
    // 004def19  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004def1a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004def1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004def1d  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004def20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004def22  740f                   -je 0x4def33
    if (cpu.flags.zf)
    {
        goto L_0x004def33;
    }
L_0x004def24:
    // 004def24  c705d4a28c0002000000   -mov dword ptr [0x8ca2d4], 2
    app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */) = 2 /*0x2*/;
    // 004def2e  e9a5020000             -jmp 0x4df1d8
    goto L_0x004df1d8;
L_0x004def33:
    // 004def33  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004def38:
    // 004def38  e8e3bd0000             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 004def3d  833dd4a28c0001         +cmp dword ptr [0x8ca2d4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004def44  7561                   -jne 0x4defa7
    if (!cpu.flags.zf)
    {
        goto L_0x004defa7;
    }
    // 004def46  8b15d8a28c00           -mov edx, dword ptr [0x8ca2d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216728) /* 0x8ca2d8 */);
    // 004def4c  a17c715600             -mov eax, dword ptr [0x56717c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665148) /* 0x56717c */);
    // 004def51  39d0                   +cmp eax, edx
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
    // 004def53  7452                   -je 0x4defa7
    if (cpu.flags.zf)
    {
        goto L_0x004defa7;
    }
    // 004def55  8b0dcca28c00           -mov ecx, dword ptr [0x8ca2cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(9216716) /* 0x8ca2cc */);
    // 004def5b  a3d8a28c00             -mov dword ptr [0x8ca2d8], eax
    app->getMemory<x86::reg32>(x86::reg32(9216728) /* 0x8ca2d8 */) = cpu.eax;
    // 004def60  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004def62  7507                   -jne 0x4def6b
    if (!cpu.flags.zf)
    {
        goto L_0x004def6b;
    }
    // 004def64  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004def69  eb05                   -jmp 0x4def70
    goto L_0x004def70;
L_0x004def6b:
    // 004def6b  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004def70:
    // 004def70  8b0dc4a28c00           -mov ecx, dword ptr [0x8ca2c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(9216708) /* 0x8ca2c4 */);
    // 004def76  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004def79  0faf05d0a28c00         -imul eax, dword ptr [0x8ca2d0]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216720) /* 0x8ca2d0 */))));
    // 004def80  8b1ddca28c00           -mov ebx, dword ptr [0x8ca2dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(9216732) /* 0x8ca2dc */);
    // 004def86  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004def88  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004def8a  8b1de0a28c00           -mov ebx, dword ptr [0x8ca2e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(9216736) /* 0x8ca2e0 */);
    // 004def90  8b15dca28c00           -mov edx, dword ptr [0x8ca2dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216732) /* 0x8ca2dc */);
    // 004def96  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004def98  a1e0a28c00             -mov eax, dword ptr [0x8ca2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216736) /* 0x8ca2e0 */);
    // 004def9d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004defa2  e899e50100             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
L_0x004defa7:
    // 004defa7  e8e4bd0000             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 004defac  a1c8a28c00             -mov eax, dword ptr [0x8ca2c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216712) /* 0x8ca2c8 */);
    // 004defb1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004defb2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004defb4  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004defb7  3dc2017688             +cmp eax, 0x887601c2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435074 /*0x887601c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004defbc  752c                   -jne 0x4defea
    if (!cpu.flags.zf)
    {
        goto L_0x004defea;
    }
    // 004defbe  a1c8a28c00             -mov eax, dword ptr [0x8ca2c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216712) /* 0x8ca2c8 */);
    // 004defc3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004defc4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004defc6  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004defc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004defcb  7418                   -je 0x4defe5
    if (cpu.flags.zf)
    {
        goto L_0x004defe5;
    }
    // 004defcd  3d4b027688             +cmp eax, 0x8876024b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435211 /*0x8876024b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004defd2  0f854cffffff           -jne 0x4def24
    if (!cpu.flags.zf)
    {
        goto L_0x004def24;
    }
    // 004defd8  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 004defde  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004defdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004defe0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004defe1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004defe2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004defe3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004defe4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004defe5:
    // 004defe5  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004defea:
    // 004defea  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004defec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004defee  8d4db2                 -lea ecx, [ebp - 0x4e]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-78) /* -0x4e */);
    // 004deff1  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 004deff6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004deff7  8945b2                 -mov dword ptr [ebp - 0x4e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-78) /* -0x4e */) = cpu.eax;
    // 004deffa  a1c8a28c00             -mov eax, dword ptr [0x8ca2c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216712) /* 0x8ca2c8 */);
    // 004defff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df001  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004df003  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df004  ff5264                 -call dword ptr [edx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df007  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df009  742c                   -je 0x4df037
    if (cpu.flags.zf)
    {
        goto L_0x004df037;
    }
    // 004df00b  3dc2017688             +cmp eax, 0x887601c2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435074 /*0x887601c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df010  750d                   -jne 0x4df01f
    if (!cpu.flags.zf)
    {
        goto L_0x004df01f;
    }
    // 004df012  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 004df018  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df019  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df01a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df01b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df01c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df01d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df01e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df01f:
    // 004df01f  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df024  0f85fafeffff           -jne 0x4def24
    if (!cpu.flags.zf)
    {
        goto L_0x004def24;
    }
    // 004df02a  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 004df030  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df031  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df032  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df033  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df034  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df035  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df036  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df037:
    // 004df037  a1d0a28c00             -mov eax, dword ptr [0x8ca2d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216720) /* 0x8ca2d0 */);
    // 004df03c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df03e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004df041  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004df043  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004df045  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004df047  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004df049:
    // 004df049  3b0dc4a28c00           +cmp ecx, dword ptr [0x8ca2c4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216708) /* 0x8ca2c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df04f  7d22                   -jge 0x4df073
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004df073;
    }
    // 004df051  8b45c2                 -mov eax, dword ptr [ebp - 0x3e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-62) /* -0x3e */);
    // 004df054  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004df057  8b55d6                 -mov edx, dword ptr [ebp - 0x2a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-42) /* -0x2a */);
    // 004df05a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004df05c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004df05e  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004df061  8b5d7e                 -mov ebx, dword ptr [ebp + 0x7e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004df064  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004df067  01d8                   +add eax, ebx
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
    // 004df069  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004df06b  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004df06c  e81be90100             -call 0x4fd98c
    cpu.esp -= 4;
    sub_4fd98c(app, cpu);
    if (cpu.terminate) return;
    // 004df071  ebd6                   -jmp 0x4df049
    goto L_0x004df049;
L_0x004df073:
    // 004df073  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df075  a1c8a28c00             -mov eax, dword ptr [0x8ca2c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216712) /* 0x8ca2c8 */);
    // 004df07a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df07b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004df07d  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df083  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df085  7418                   -je 0x4df09f
    if (cpu.flags.zf)
    {
        goto L_0x004df09f;
    }
    // 004df087  3dc2017688             +cmp eax, 0x887601c2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435074 /*0x887601c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df08c  0f8592feffff           -jne 0x4def24
    if (!cpu.flags.zf)
    {
        goto L_0x004def24;
    }
    // 004df092  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 004df098  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df099  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df09a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df09b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df09c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df09d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df09e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df09f:
    // 004df09f  833dd4a28c0000         +cmp dword ptr [0x8ca2d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df0a6  7408                   -je 0x4df0b0
    if (cpu.flags.zf)
    {
        goto L_0x004df0b0;
    }
    // 004df0a8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004df0aa  0f8428010000           -je 0x4df1d8
    if (cpu.flags.zf)
    {
        goto L_0x004df1d8;
    }
L_0x004df0b0:
    // 004df0b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df0b2  89456a                 -mov dword ptr [ebp + 0x6a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */) = cpu.eax;
    // 004df0b5  894566                 -mov dword ptr [ebp + 0x66], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */) = cpu.eax;
    // 004df0b8  a1d0a28c00             -mov eax, dword ptr [0x8ca2d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216720) /* 0x8ca2d0 */);
    // 004df0bd  48                     -dec eax
    (cpu.eax)--;
    // 004df0be  89456e                 -mov dword ptr [ebp + 0x6e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */) = cpu.eax;
    // 004df0c1  a1c4a28c00             -mov eax, dword ptr [0x8ca2c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216708) /* 0x8ca2c4 */);
    // 004df0c6  48                     -dec eax
    (cpu.eax)--;
    // 004df0c7  8b0dcca28c00           -mov ecx, dword ptr [0x8ca2cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(9216716) /* 0x8ca2cc */);
    // 004df0cd  894572                 -mov dword ptr [ebp + 0x72], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */) = cpu.eax;
    // 004df0d0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004df0d2  7507                   -jne 0x4df0db
    if (!cpu.flags.zf)
    {
        goto L_0x004df0db;
    }
    // 004df0d4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004df0d9  eb05                   -jmp 0x4df0e0
    goto L_0x004df0e0;
L_0x004df0db:
    // 004df0db  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004df0e0:
    // 004df0e0  8b15e0a28c00           -mov edx, dword ptr [0x8ca2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216736) /* 0x8ca2e0 */);
    // 004df0e6  895556                 -mov dword ptr [ebp + 0x56], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */) = cpu.edx;
    // 004df0e9  8b15dca28c00           -mov edx, dword ptr [0x8ca2dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216732) /* 0x8ca2dc */);
    // 004df0ef  89555a                 -mov dword ptr [ebp + 0x5a], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */) = cpu.edx;
    // 004df0f2  8b15d0a28c00           -mov edx, dword ptr [0x8ca2d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216720) /* 0x8ca2d0 */);
    // 004df0f8  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004df0fb  0faf05c4a28c00         -imul eax, dword ptr [0x8ca2c4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216708) /* 0x8ca2c4 */))));
    // 004df102  8b4d56                 -mov ecx, dword ptr [ebp + 0x56]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 004df105  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004df107  8b555a                 -mov edx, dword ptr [ebp + 0x5a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
    // 004df10a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004df10c  894d5e                 -mov dword ptr [ebp + 0x5e], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */) = cpu.ecx;
    // 004df10f  895562                 -mov dword ptr [ebp + 0x62], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(98) /* 0x62 */) = cpu.edx;
    // 004df112  e859c90000             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 004df117  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004df119  8d4556                 -lea eax, [ebp + 0x56]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 004df11c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df11d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df11e  2eff1500475300         -call dword ptr cs:[0x534700]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457664) /* 0x534700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df125  8d455e                 -lea eax, [ebp + 0x5e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(94) /* 0x5e */);
    // 004df128  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df129  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df12a  2eff1500475300         -call dword ptr cs:[0x534700]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457664) /* 0x534700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df131  e85abd0000             -call 0x4eae90
    cpu.esp -= 4;
    sub_4eae90(app, cpu);
    if (cpu.terminate) return;
    // 004df136  8b3dd4a28c00           -mov edi, dword ptr [0x8ca2d4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */);
    // 004df13c  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004df13f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004df141  7537                   -jne 0x4df17a
    if (!cpu.flags.zf)
    {
        goto L_0x004df17a;
    }
    // 004df143  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df144  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df145  8d5566                 -lea edx, [ebp + 0x66]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 004df148  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df149  8b15c8a28c00           -mov edx, dword ptr [0x8ca2c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216712) /* 0x8ca2c8 */);
    // 004df14f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df150  8d5556                 -lea edx, [ebp + 0x56]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 004df153  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df154  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004df156  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df157  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df15a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df15c  0f8476000000           -je 0x4df1d8
    if (cpu.flags.zf)
    {
        goto L_0x004df1d8;
    }
    // 004df162  3dc2017688             +cmp eax, 0x887601c2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435074 /*0x887601c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df167  0f85b7fdffff           -jne 0x4def24
    if (!cpu.flags.zf)
    {
        goto L_0x004def24;
    }
    // 004df16d  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 004df173  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df174  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df175  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df176  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df177  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df178  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df179  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df17a:
    // 004df17a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004df17c  745a                   -je 0x4df1d8
    if (cpu.flags.zf)
    {
        goto L_0x004df1d8;
    }
    // 004df17e  8d4576                 -lea eax, [ebp + 0x76]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 004df181  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004df186  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df187  897576                 -mov dword ptr [ebp + 0x76], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.esi;
    // 004df18a  89757a                 -mov dword ptr [ebp + 0x7a], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */) = cpu.esi;
    // 004df18d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004df18f  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004df191  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df192  ff5274                 -call dword ptr [edx + 0x74]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df195  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df197  7534                   -jne 0x4df1cd
    if (!cpu.flags.zf)
    {
        goto L_0x004df1cd;
    }
    // 004df199  c7451e38000000         -mov dword ptr [ebp + 0x1e], 0x38
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(30) /* 0x1e */) = 56 /*0x38*/;
    // 004df1a0  8d551e                 -lea edx, [ebp + 0x1e]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(30) /* 0x1e */);
    // 004df1a3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df1a4  6800480800             -push 0x84800
    app->getMemory<x86::reg32>(cpu.esp-4) = 542720 /*0x84800*/;
    cpu.esp -= 4;
    // 004df1a9  8d5556                 -lea edx, [ebp + 0x56]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 004df1ac  a1c8a28c00             -mov eax, dword ptr [0x8ca2c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216712) /* 0x8ca2c8 */);
    // 004df1b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df1b2  89754e                 -mov dword ptr [ebp + 0x4e], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */) = cpu.esi;
    // 004df1b5  89753e                 -mov dword ptr [ebp + 0x3e], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(62) /* 0x3e */) = cpu.esi;
    // 004df1b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df1b9  8d5566                 -lea edx, [ebp + 0x66]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 004df1bc  897542                 -mov dword ptr [ebp + 0x42], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(66) /* 0x42 */) = cpu.esi;
    // 004df1bf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df1c0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004df1c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df1c3  ff9184000000           -call dword ptr [ecx + 0x84]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df1c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df1cb  740b                   -je 0x4df1d8
    if (cpu.flags.zf)
    {
        goto L_0x004df1d8;
    }
L_0x004df1cd:
    // 004df1cd  3dc2017688             +cmp eax, 0x887601c2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435074 /*0x887601c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df1d2  0f854cfdffff           -jne 0x4def24
    if (!cpu.flags.zf)
    {
        goto L_0x004def24;
    }
L_0x004df1d8:
    // 004df1d8  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 004df1de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df1df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df1e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df1e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df1e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df1e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df1e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4df1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df1f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df1f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df1f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df1f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df1f5  81ecd8020000           -sub esp, 0x2d8
    (cpu.esp) -= x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004df1fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004df1fd  e80e010000             -call 0x4df310
    cpu.esp -= 4;
    sub_4df310(app, cpu);
    if (cpu.terminate) return;
    // 004df202  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004df205  8935e0a28c00           -mov dword ptr [0x8ca2e0], esi
    app->getMemory<x86::reg32>(x86::reg32(9216736) /* 0x8ca2e0 */) = cpu.esi;
    // 004df20b  8915dca28c00           -mov dword ptr [0x8ca2dc], edx
    app->getMemory<x86::reg32>(x86::reg32(9216732) /* 0x8ca2dc */) = cpu.edx;
    // 004df211  891dd0a28c00           -mov dword ptr [0x8ca2d0], ebx
    app->getMemory<x86::reg32>(x86::reg32(9216720) /* 0x8ca2d0 */) = cpu.ebx;
    // 004df217  890dc4a28c00           -mov dword ptr [0x8ca2c4], ecx
    app->getMemory<x86::reg32>(x86::reg32(9216708) /* 0x8ca2c4 */) = cpu.ecx;
    // 004df21d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004df21f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004df224  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004df227  893dd8a28c00           -mov dword ptr [0x8ca2d8], edi
    app->getMemory<x86::reg32>(x86::reg32(9216728) /* 0x8ca2d8 */) = cpu.edi;
    // 004df22d  893dc0a28c00           -mov dword ptr [0x8ca2c0], edi
    app->getMemory<x86::reg32>(x86::reg32(9216704) /* 0x8ca2c0 */) = cpu.edi;
    // 004df233  a3cca28c00             -mov dword ptr [0x8ca2cc], eax
    app->getMemory<x86::reg32>(x86::reg32(9216716) /* 0x8ca2cc */) = cpu.eax;
    // 004df238  8915d4a28c00           -mov dword ptr [0x8ca2d4], edx
    app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */) = cpu.edx;
    // 004df23e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004df240  0f8561000000           -jne 0x4df2a7
    if (!cpu.flags.zf)
    {
        goto L_0x004df2a7;
    }
    // 004df246  e845c80000             -call 0x4eba90
    cpu.esp -= 4;
    sub_4eba90(app, cpu);
    if (cpu.terminate) return;
    // 004df24b  bb6c010000             -mov ebx, 0x16c
    cpu.ebx = 364 /*0x16c*/;
    // 004df250  8d9528fdffff           -lea edx, [ebp - 0x2d8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-728) /* -0x2d8 */);
    // 004df256  899d94feffff           -mov dword ptr [ebp - 0x16c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-364) /* -0x16c */) = cpu.ebx;
    // 004df25c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df25d  8d9594feffff           -lea edx, [ebp - 0x16c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-364) /* -0x16c */);
    // 004df263  899d28fdffff           -mov dword ptr [ebp - 0x2d8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-728) /* -0x2d8 */) = cpu.ebx;
    // 004df269  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df26a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004df26c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df26d  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df270  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df272  7533                   -jne 0x4df2a7
    if (!cpu.flags.zf)
    {
        goto L_0x004df2a7;
    }
    // 004df274  8aa599feffff           -mov ah, byte ptr [ebp - 0x167]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-359) /* -0x167 */);
    // 004df27a  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 004df27d  7411                   -je 0x4df290
    if (cpu.flags.zf)
    {
        goto L_0x004df290;
    }
    // 004df27f  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 004df282  740c                   -je 0x4df290
    if (cpu.flags.zf)
    {
        goto L_0x004df290;
    }
    // 004df284  c705d4a28c0001000000   -mov dword ptr [0x8ca2d4], 1
    app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */) = 1 /*0x1*/;
    // 004df28e  eb17                   -jmp 0x4df2a7
    goto L_0x004df2a7;
L_0x004df290:
    // 004df290  8ab599feffff           -mov dh, byte ptr [ebp - 0x167]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-359) /* -0x167 */);
    // 004df296  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 004df299  740c                   -je 0x4df2a7
    if (cpu.flags.zf)
    {
        goto L_0x004df2a7;
    }
    // 004df29b  f6c602                 +test dh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 2 /*0x2*/));
    // 004df29e  7407                   -je 0x4df2a7
    if (cpu.flags.zf)
    {
        goto L_0x004df2a7;
    }
    // 004df2a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df2a2  a3d4a28c00             -mov dword ptr [0x8ca2d4], eax
    app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */) = cpu.eax;
L_0x004df2a7:
    // 004df2a7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004df2a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df2aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df2ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df2ac  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4df2b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df2b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df2b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df2b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df2b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df2b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df2b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df2b6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df2b8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004df2ba  833dd4a28c0002         +cmp dword ptr [0x8ca2d4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df2c1  7405                   -je 0x4df2c8
    if (cpu.flags.zf)
    {
        goto L_0x004df2c8;
    }
    // 004df2c3  e8b8fbffff             -call 0x4dee80
    cpu.esp -= 4;
    sub_4dee80(app, cpu);
    if (cpu.terminate) return;
L_0x004df2c8:
    // 004df2c8  833dd4a28c0002         +cmp dword ptr [0x8ca2d4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df2cf  752e                   -jne 0x4df2ff
    if (!cpu.flags.zf)
    {
        goto L_0x004df2ff;
    }
    // 004df2d1  e84aba0000             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 004df2d6  8b35cca28c00           -mov esi, dword ptr [0x8ca2cc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(9216716) /* 0x8ca2cc */);
    // 004df2dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df2dd  8b3dc4a28c00           -mov edi, dword ptr [0x8ca2c4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(9216708) /* 0x8ca2c4 */);
    // 004df2e3  8b0dd0a28c00           -mov ecx, dword ptr [0x8ca2d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(9216720) /* 0x8ca2d0 */);
    // 004df2e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df2ea  8b15dca28c00           -mov edx, dword ptr [0x8ca2dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(9216732) /* 0x8ca2dc */);
    // 004df2f0  a1e0a28c00             -mov eax, dword ptr [0x8ca2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216736) /* 0x8ca2e0 */);
    // 004df2f5  e896e90100             -call 0x4fdc90
    cpu.esp -= 4;
    sub_4fdc90(app, cpu);
    if (cpu.terminate) return;
    // 004df2fa  e891ba0000             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
L_0x004df2ff:
    // 004df2ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df300  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df301  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df302  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df303  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df304  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df305  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4df310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df312  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df313  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df314  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df316  e865c70000             -call 0x4eba80
    cpu.esp -= 4;
    sub_4eba80(app, cpu);
    if (cpu.terminate) return;
    // 004df31b  3b05c0a28c00           +cmp eax, dword ptr [0x8ca2c0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(9216704) /* 0x8ca2c0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df321  7518                   -jne 0x4df33b
    if (!cpu.flags.zf)
    {
        goto L_0x004df33b;
    }
    // 004df323  8b0dc8a28c00           -mov ecx, dword ptr [0x8ca2c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(9216712) /* 0x8ca2c8 */);
    // 004df329  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004df32b  740e                   -je 0x4df33b
    if (cpu.flags.zf)
    {
        goto L_0x004df33b;
    }
    // 004df32d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df32e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004df330  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004df332  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df335  891dc8a28c00           -mov dword ptr [0x8ca2c8], ebx
    app->getMemory<x86::reg32>(x86::reg32(9216712) /* 0x8ca2c8 */) = cpu.ebx;
L_0x004df33b:
    // 004df33b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df33c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df33d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df33e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df33f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4df340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df340  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df341  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df343  a1d4a28c00             -mov eax, dword ptr [0x8ca2d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(9216724) /* 0x8ca2d4 */);
    // 004df348  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df349  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4df350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df351  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df352  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df353  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df355  8b1550435600           -mov edx, dword ptr [0x564350]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653328) /* 0x564350 */);
L_0x004df35b:
    // 004df35b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004df35d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004df35f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004df361  7412                   -je 0x4df375
    if (cpu.flags.zf)
    {
        goto L_0x004df375;
    }
    // 004df363  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004df366  81fa6ff29e00           +cmp edx, 0x9ef26f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10416751 /*0x9ef26f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df36c  76ed                   -jbe 0x4df35b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004df35b;
    }
    // 004df36e  baf0a28c00             -mov edx, 0x8ca2f0
    cpu.edx = 9216752 /*0x8ca2f0*/;
    // 004df373  ebe6                   -jmp 0x4df35b
    goto L_0x004df35b;
L_0x004df375:
    // 004df375  891550435600           -mov dword ptr [0x564350], edx
    app->getMemory<x86::reg32>(x86::reg32(5653328) /* 0x564350 */) = cpu.edx;
    // 004df37b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df37c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df37d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df37e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4df380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df380  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df381  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df383  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004df388  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df389  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4df390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df390  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df391  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df393  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df394  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4df3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df3a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df3a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df3a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df3a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df3a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df3a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df3a7  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004df3aa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004df3ac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004df3ae  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004df3b1  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004df3b4  833d4843560000         +cmp dword ptr [0x564348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653320) /* 0x564348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df3bb  7454                   -je 0x4df411
    if (cpu.flags.zf)
    {
        goto L_0x004df411;
    }
    // 004df3bd  a370f29e00             -mov dword ptr [0x9ef270], eax
    app->getMemory<x86::reg32>(x86::reg32(10416752) /* 0x9ef270 */) = cpu.eax;
    // 004df3c2  891574f29e00           -mov dword ptr [0x9ef274], edx
    app->getMemory<x86::reg32>(x86::reg32(10416756) /* 0x9ef274 */) = cpu.edx;
    // 004df3c8  e883ffffff             -call 0x4df350
    cpu.esp -= 4;
    sub_4df350(app, cpu);
    if (cpu.terminate) return;
    // 004df3cd  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004df3d0  a174f29e00             -mov eax, dword ptr [0x9ef274]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10416756) /* 0x9ef274 */);
    // 004df3d5  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df3d8  8950fc                 -mov dword ptr [eax - 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004df3db  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004df3dd  7432                   -je 0x4df411
    if (cpu.flags.zf)
    {
        goto L_0x004df411;
    }
    // 004df3df  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df3e2  8b154c435600           -mov edx, dword ptr [0x56434c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */);
    // 004df3e8  83e904                 -sub ecx, 4
    (cpu.ecx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df3eb  42                     -inc edx
    (cpu.edx)++;
    // 004df3ec  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004df3ee  89154c435600           -mov dword ptr [0x56434c], edx
    app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */) = cpu.edx;
    // 004df3f4  0f31                   -rdtsc 
    cpu.rdtsc();
    // 004df3f6  8995f4ffffff           -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004df3fc  8985f8ffffff           -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004df402  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004df405  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df408  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004df40b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004df40e  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004df411:
    // 004df411  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004df413  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df414  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df415  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df416  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df417  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df418  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4df420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df420  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df421  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df422  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df423  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df424  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df425  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df426  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df428  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004df42b  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df42e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004df430  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004df433  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 004df436  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 004df439  0f31                   -rdtsc 
    cpu.rdtsc();
    // 004df43b  8995e8ffffff           -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 004df441  8985ecffffff           -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004df447  833d4843560000         +cmp dword ptr [0x564348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653320) /* 0x564348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df44e  0f84ce000000           -je 0x4df522
    if (cpu.flags.zf)
    {
        goto L_0x004df522;
    }
    // 004df454  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004df457  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004df459  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004df45c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004df45f  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004df462  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df465  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004df468  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004df46b  8b85ecffffff           -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004df471  8b95e8ffffff           -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004df477  2b85f4ffffff           +sub eax, dword ptr [ebp - 0xc]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004df47d  1b95f0ffffff           -sbb edx, dword ptr [ebp - 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) + cpu.flags.cf);
    // 004df483  8985f4ffffff           -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004df489  8995f0ffffff           -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004df48f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df492  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004df494  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004df496  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004df498  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004df49a  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004df49c  ba78f49e00             -mov edx, 0x9ef478
    cpu.edx = 10417272 /*0x9ef478*/;
L_0x004df4a1:
    // 004df4a1  fec8                   -dec al
    (cpu.al)--;
    // 004df4a3  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004df4a5  7409                   -je 0x4df4b0
    if (cpu.flags.zf)
    {
        goto L_0x004df4b0;
    }
    // 004df4a7  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004df4a8  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 004df4aa  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004df4ab  8862ff                 -mov byte ptr [edx - 1], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 004df4ae  ebf1                   -jmp 0x4df4a1
    goto L_0x004df4a1;
L_0x004df4b0:
    // 004df4b0  b878f39e00             -mov eax, 0x9ef378
    cpu.eax = 10417016 /*0x9ef378*/;
    // 004df4b5  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004df4b8  ba34985400             -mov edx, 0x549834
    cpu.edx = 5543988 /*0x549834*/;
    // 004df4bd  e826eb0000             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 004df4c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df4c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df4c6  7444                   -je 0x4df50c
    if (cpu.flags.zf)
    {
        goto L_0x004df50c;
    }
    // 004df4c8  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
L_0x004df4ca:
    // 004df4ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df4cc  8b354c435600           -mov esi, dword ptr [0x56434c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */);
    // 004df4d2  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004df4d4  39f0                   +cmp eax, esi
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
    // 004df4d6  7d12                   -jge 0x4df4ea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004df4ea;
    }
    // 004df4d8  6838985400             -push 0x549838
    app->getMemory<x86::reg32>(cpu.esp-4) = 5543992 /*0x549838*/;
    cpu.esp -= 4;
    // 004df4dd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df4de  fec3                   -inc bl
    (cpu.bl)++;
    // 004df4e0  e89b560100             -call 0x4f4b80
    cpu.esp -= 4;
    sub_4f4b80(app, cpu);
    if (cpu.terminate) return;
    // 004df4e5  83c408                 +add esp, 8
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
    // 004df4e8  ebe0                   -jmp 0x4df4ca
    goto L_0x004df4ca;
L_0x004df4ea:
    // 004df4ea  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004df4ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df4ee  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004df4f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df4f2  6878f49e00             -push 0x9ef478
    app->getMemory<x86::reg32>(cpu.esp-4) = 10417272 /*0x9ef478*/;
    cpu.esp -= 4;
    // 004df4f7  683c985400             -push 0x54983c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5543996 /*0x54983c*/;
    cpu.esp -= 4;
    // 004df4fc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df4fd  e87e560100             -call 0x4f4b80
    cpu.esp -= 4;
    sub_4f4b80(app, cpu);
    if (cpu.terminate) return;
    // 004df502  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004df505  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004df507  e8f4eb0000             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x004df50c:
    // 004df50c  8b3d4c435600           -mov edi, dword ptr [0x56434c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */);
    // 004df512  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df515  4f                     -dec edi
    (cpu.edi)--;
    // 004df516  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004df51c  893d4c435600           -mov dword ptr [0x56434c], edi
    app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */) = cpu.edi;
L_0x004df522:
    // 004df522  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004df524  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df525  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df526  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df527  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df528  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df529  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df52a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4df530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df530  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df531  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df532  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df533  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df535  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004df537:
    // 004df537  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df538  6848985400             -push 0x549848
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544008 /*0x549848*/;
    cpu.esp -= 4;
    // 004df53d  6878f39e00             -push 0x9ef378
    app->getMemory<x86::reg32>(cpu.esp-4) = 10417016 /*0x9ef378*/;
    cpu.esp -= 4;
    // 004df542  e849010000             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004df547  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004df54a  ba54985400             -mov edx, 0x549854
    cpu.edx = 5544020 /*0x549854*/;
    // 004df54f  b878f39e00             -mov eax, 0x9ef378
    cpu.eax = 10417016 /*0x9ef378*/;
    // 004df554  e88fea0000             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 004df559  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df55b  7403                   -je 0x4df560
    if (cpu.flags.zf)
    {
        goto L_0x004df560;
    }
    // 004df55d  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004df55e  ebd7                   -jmp 0x4df537
    goto L_0x004df537;
L_0x004df560:
    // 004df560  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df561  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df562  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df563  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4df570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df571  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df572  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df573  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df574  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df575  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df576  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df578  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004df57b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004df57d  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004df580  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004df583  833d4843560000         +cmp dword ptr [0x564348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653320) /* 0x564348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df58a  7429                   -je 0x4df5b5
    if (cpu.flags.zf)
    {
        goto L_0x004df5b5;
    }
    // 004df58c  e89fffffff             -call 0x4df530
    cpu.esp -= 4;
    sub_4df530(app, cpu);
    if (cpu.terminate) return;
    // 004df591  ff054c435600           -inc dword ptr [0x56434c]
    (app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */))++;
    // 004df597  0f31                   -rdtsc 
    cpu.rdtsc();
    // 004df599  8995f8ffffff           -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004df59f  8985fcffffff           -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004df5a5  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004df5a8  a3a8f59e00             -mov dword ptr [0x9ef5a8], eax
    app->getMemory<x86::reg32>(x86::reg32(10417576) /* 0x9ef5a8 */) = cpu.eax;
    // 004df5ad  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df5b0  a3acf59e00             -mov dword ptr [0x9ef5ac], eax
    app->getMemory<x86::reg32>(x86::reg32(10417580) /* 0x9ef5ac */) = cpu.eax;
L_0x004df5b5:
    // 004df5b5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004df5b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5ba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df5bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4df5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df5c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df5c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df5c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df5c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df5c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df5c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df5c6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004df5c8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004df5cb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004df5cd  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004df5d0  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004df5d3  0f31                   -rdtsc 
    cpu.rdtsc();
    // 004df5d5  8995f0ffffff           -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004df5db  8985f4ffffff           -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004df5e1  833d4843560000         +cmp dword ptr [0x564348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653320) /* 0x564348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df5e8  746c                   -je 0x4df656
    if (cpu.flags.zf)
    {
        goto L_0x004df656;
    }
    // 004df5ea  a1a8f59e00             -mov eax, dword ptr [0x9ef5a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417576) /* 0x9ef5a8 */);
    // 004df5ef  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004df5f2  a1acf59e00             -mov eax, dword ptr [0x9ef5ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417580) /* 0x9ef5ac */);
    // 004df5f7  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004df5fa  8b85f4ffffff           -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004df600  8b95f0ffffff           -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004df606  2b85fcffffff           +sub eax, dword ptr [ebp - 4]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004df60c  1b95f8ffffff           -sbb edx, dword ptr [ebp - 8]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)) + cpu.flags.cf);
    // 004df612  8985fcffffff           -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004df618  8995f8ffffff           -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004df61e  ba34985400             -mov edx, 0x549834
    cpu.edx = 5543988 /*0x549834*/;
    // 004df623  b878f39e00             -mov eax, 0x9ef378
    cpu.eax = 10417016 /*0x9ef378*/;
    // 004df628  e8bbe90000             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 004df62d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df62f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df631  741d                   -je 0x4df650
    if (cpu.flags.zf)
    {
        goto L_0x004df650;
    }
    // 004df633  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004df636  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df637  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004df63a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df63b  6858985400             -push 0x549858
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544024 /*0x549858*/;
    cpu.esp -= 4;
    // 004df640  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df641  e83a550100             -call 0x4f4b80
    cpu.esp -= 4;
    sub_4f4b80(app, cpu);
    if (cpu.terminate) return;
    // 004df646  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004df649  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004df64b  e8b0ea0000             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x004df650:
    // 004df650  ff0d4c435600           -dec dword ptr [0x56434c]
    (app->getMemory<x86::reg32>(x86::reg32(5653324) /* 0x56434c */))--;
L_0x004df656:
    // 004df656  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004df658  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df659  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df65a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df65b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df65c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df65d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df65e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4df660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df660  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df661  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df662  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004df664  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004df666  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004df669  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004df66b  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 004df66d  ff4010                 -inc dword ptr [eax + 0x10]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
    // 004df670  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df671  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df672  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4df674(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df674  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df675  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df676  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004df678  b960f64d00             -mov ecx, 0x4df660
    cpu.ecx = 5109344 /*0x4df660*/;
    // 004df67d  e84eeb0100             -call 0x4fe1d0
    cpu.esp -= 4;
    sub_4fe1d0(app, cpu);
    if (cpu.terminate) return;
    // 004df682  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 004df686  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df687  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df688  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4df690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df690  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df691  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df692  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df695  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004df699  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004df69b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004df69f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004df6a2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004df6a6  e8c9ffffff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 004df6ab  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df6ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df6af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df6b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4df6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df6c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df6c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df6c2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df6c5  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004df6c9  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004df6cb  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004df6cf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004df6d2  b8726f5600             -mov eax, 0x566f72
    cpu.eax = 5664626 /*0x566f72*/;
    // 004df6d7  e838f90100             -call 0x4ff014
    cpu.esp -= 4;
    sub_4ff014(app, cpu);
    if (cpu.terminate) return;
    // 004df6dc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df6df  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df6e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df6e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4df6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df6f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df6f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df6f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df6f3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004df6f5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004df6f7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df6f9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df6fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df6fc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df6fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df6fe  2eff1530465300         -call dword ptr cs:[0x534630]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457456) /* 0x534630 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df705  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004df707  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df709  7c04                   -jl 0x4df70f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004df70f;
    }
    // 004df70b  39f8                   +cmp eax, edi
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
    // 004df70d  7c0c                   -jl 0x4df71b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004df71b;
    }
L_0x004df70f:
    // 004df70f  81fb02010000           -cmp ebx, 0x102
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(258 /*0x102*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df715  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df717  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df718  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df719  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df71a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df71b:
    // 004df71b  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004df71e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df71f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df720  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df721  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4df730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df730  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004df734  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df736  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df738  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4df740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df740  833db8f59e0000         +cmp dword ptr [0x9ef5b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df747  7401                   -je 0x4df74a
    if (cpu.flags.zf)
    {
        goto L_0x004df74a;
    }
    // 004df749  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df74a:
    // 004df74a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df74b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df74c  2eff150c455300         -call dword ptr cs:[0x53450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457164) /* 0x53450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df753  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004df755  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df757  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df759  68b0f59e00             -push 0x9ef5b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10417584 /*0x9ef5b0*/;
    cpu.esp -= 4;
    // 004df75e  a3b4f59e00             -mov dword ptr [0x9ef5b4], eax
    app->getMemory<x86::reg32>(x86::reg32(10417588) /* 0x9ef5b4 */) = cpu.eax;
    // 004df763  2eff1504455300         -call dword ptr cs:[0x534504]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457156) /* 0x534504 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df76a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df76b  2eff1510455300         -call dword ptr cs:[0x534510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457168) /* 0x534510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df772  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df773  2eff1504455300         -call dword ptr cs:[0x534504]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457156) /* 0x534504 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df77a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df77b  2eff15b4445300         -call dword ptr cs:[0x5344b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457076) /* 0x5344b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df782  c705b8f59e0001000000   -mov dword ptr [0x9ef5b8], 1
    app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */) = 1 /*0x1*/;
    // 004df78c  e84fbb0000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004df791  a380445600             -mov dword ptr [0x564480], eax
    app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */) = cpu.eax;
    // 004df796  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df797  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df798  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4df7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df7a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df7a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df7a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df7a3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df7a6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004df7a8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004df7aa  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004df7ac  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004df7b0  e8bb980100             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 004df7b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df7b7  7570                   -jne 0x4df829
    if (!cpu.flags.zf)
    {
        goto L_0x004df829;
    }
L_0x004df7b9:
    // 004df7b9  833db8f59e0000         +cmp dword ptr [0x9ef5b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df7c0  7507                   -jne 0x4df7c9
    if (!cpu.flags.zf)
    {
        goto L_0x004df7c9;
    }
    // 004df7c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df7c4  e877ffffff             -call 0x4df740
    cpu.esp -= 4;
    sub_4df740(app, cpu);
    if (cpu.terminate) return;
L_0x004df7c9:
    // 004df7c9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004df7cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df7cc  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004df7ce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004df7cf  6830f74d00             -push 0x4df730
    app->getMemory<x86::reg32>(cpu.esp-4) = 5109552 /*0x4df730*/;
    cpu.esp -= 4;
    // 004df7d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004df7d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df7d7  2eff15a4445300         -call dword ptr cs:[0x5344a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457060) /* 0x5344a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df7de  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004df7e0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004df7e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df7e4  7431                   -je 0x4df817
    if (cpu.flags.zf)
    {
        goto L_0x004df817;
    }
    // 004df7e6  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004df7ed  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004df7ef  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004df7f2  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004df7f5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004df7f8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004df7fa  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004df7fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004df7ff  e82c020000             -call 0x4dfa30
    cpu.esp -= 4;
    sub_4dfa30(app, cpu);
    if (cpu.terminate) return;
    // 004df804  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df805  2eff15bc455300         -call dword ptr cs:[0x5345bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457340) /* 0x5345bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df80c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004df80e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df810  2eff1504465300         -call dword ptr cs:[0x534604]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457412) /* 0x534604 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004df817:
    // 004df817  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004df819  7440                   -je 0x4df85b
    if (cpu.flags.zf)
    {
        goto L_0x004df85b;
    }
    // 004df81b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004df820  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df823  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df824  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df825  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df826  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004df829:
    // 004df829  ba68985400             -mov edx, 0x549868
    cpu.edx = 5544040 /*0x549868*/;
    // 004df82e  b978985400             -mov ecx, 0x549878
    cpu.ecx = 5544056 /*0x549878*/;
    // 004df833  b89f000000             -mov eax, 0x9f
    cpu.eax = 159 /*0x9f*/;
    // 004df838  6888985400             -push 0x549888
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544072 /*0x549888*/;
    cpu.esp -= 4;
    // 004df83d  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004df843  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004df849  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004df84e  e8bd17f2ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004df853  83c404                 +add esp, 4
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
    // 004df856  e95effffff             -jmp 0x4df7b9
    goto L_0x004df7b9;
L_0x004df85b:
    // 004df85b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df85d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004df860  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df861  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df862  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df863  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4df870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df871  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df872  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df873  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df875  741d                   -je 0x4df894
    if (cpu.flags.zf)
    {
        goto L_0x004df894;
    }
    // 004df877  83f8ff                 +cmp eax, -1
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
    // 004df87a  744a                   -je 0x4df8c6
    if (cpu.flags.zf)
    {
        goto L_0x004df8c6;
    }
    // 004df87c  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
L_0x004df87e:
    // 004df87e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004df880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df881  2eff1508465300         -call dword ptr cs:[0x534608]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457416) /* 0x534608 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df888  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df889  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df890  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df891  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df892  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df893  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df894:
    // 004df894  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004df895  ba68985400             -mov edx, 0x549868
    cpu.edx = 5544040 /*0x549868*/;
    // 004df89a  b9c0985400             -mov ecx, 0x5498c0
    cpu.ecx = 5544128 /*0x5498c0*/;
    // 004df89f  bedc000000             -mov esi, 0xdc
    cpu.esi = 220 /*0xdc*/;
    // 004df8a4  68d0985400             -push 0x5498d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544144 /*0x5498d0*/;
    cpu.esp -= 4;
    // 004df8a9  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004df8af  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004df8b5  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004df8bb  e85017f2ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004df8c0  83c404                 +add esp, 4
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
    // 004df8c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df8c4  ebb8                   -jmp 0x4df87e
    goto L_0x004df87e;
L_0x004df8c6:
    // 004df8c6  2eff1510455300         -call dword ptr cs:[0x534510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457168) /* 0x534510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df8cd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004df8cf  ebad                   -jmp 0x4df87e
    goto L_0x004df87e;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4df8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df8e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df8e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df8e2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004df8e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df8e5  2eff1504465300         -call dword ptr cs:[0x534604]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457412) /* 0x534604 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df8ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df8ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df8ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4df8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df8f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df8f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df8f2  8b0dd8435600           -mov ecx, dword ptr [0x5643d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004df8f8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004df8fa  7505                   -jne 0x4df901
    if (!cpu.flags.zf)
    {
        goto L_0x004df901;
    }
    // 004df8fc  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x004df901:
    // 004df901  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df903  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004df906  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004df908  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004df90b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004df90d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004df910  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df912  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004df915  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004df917  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004df919  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004df91c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004df91e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004df920  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df921  2eff1504465300         -call dword ptr cs:[0x534604]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457412) /* 0x534604 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df928  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df929  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df92a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4df930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004df931  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df932  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df933  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004df935  2eff150c455300         -call dword ptr cs:[0x53450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457164) /* 0x53450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df93c  8b0db8f59e00           -mov ecx, dword ptr [0x9ef5b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */);
    // 004df942  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df944  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004df946  7415                   -je 0x4df95d
    if (cpu.flags.zf)
    {
        goto L_0x004df95d;
    }
L_0x004df948:
    // 004df948  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004df94a  7520                   -jne 0x4df96c
    if (!cpu.flags.zf)
    {
        goto L_0x004df96c;
    }
    // 004df94c  3b15b4f59e00           +cmp edx, dword ptr [0x9ef5b4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10417588) /* 0x9ef5b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df952  7512                   -jne 0x4df966
    if (!cpu.flags.zf)
    {
        goto L_0x004df966;
    }
L_0x004df954:
    // 004df954  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004df959  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df95a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df95b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df95c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df95d:
    // 004df95d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004df95f  e8dcfdffff             -call 0x4df740
    cpu.esp -= 4;
    sub_4df740(app, cpu);
    if (cpu.terminate) return;
    // 004df964  ebe2                   -jmp 0x4df948
    goto L_0x004df948;
L_0x004df966:
    // 004df966  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df968  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df969  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df96a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df96b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df96c:
    // 004df96c  83fbff                 +cmp ebx, -1
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
    // 004df96f  74e3                   -je 0x4df954
    if (cpu.flags.zf)
    {
        goto L_0x004df954;
    }
    // 004df971  3b5310                 +cmp edx, dword ptr [ebx + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df974  74de                   -je 0x4df954
    if (cpu.flags.zf)
    {
        goto L_0x004df954;
    }
    // 004df976  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004df978  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df979  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df97a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df97b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4df980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004df980  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004df981  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004df982  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004df984  833db8f59e0000         +cmp dword ptr [0x9ef5b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df98b  742f                   -je 0x4df9bc
    if (cpu.flags.zf)
    {
        goto L_0x004df9bc;
    }
L_0x004df98d:
    // 004df98d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004df98f  7534                   -jne 0x4df9c5
    if (!cpu.flags.zf)
    {
        goto L_0x004df9c5;
    }
    // 004df991  a1b0f59e00             -mov eax, dword ptr [0x9ef5b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417584) /* 0x9ef5b0 */);
L_0x004df996:
    // 004df996  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004df997  2eff1564455300         -call dword ptr cs:[0x534564]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457252) /* 0x534564 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df99e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004df9a0  7c35                   -jl 0x4df9d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004df9d7;
    }
    // 004df9a2  0f8e5b000000           -jle 0x4dfa03
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dfa03;
    }
    // 004df9a8  83f802                 +cmp eax, 2
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
    // 004df9ab  7c4e                   -jl 0x4df9fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004df9fb;
    }
    // 004df9ad  7e44                   -jle 0x4df9f3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004df9f3;
    }
    // 004df9af  83f80f                 +cmp eax, 0xf
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
    // 004df9b2  754f                   -jne 0x4dfa03
    if (!cpu.flags.zf)
    {
        goto L_0x004dfa03;
    }
    // 004df9b4  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004df9b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df9bc:
    // 004df9bc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004df9be  e87dfdffff             -call 0x4df740
    cpu.esp -= 4;
    sub_4df740(app, cpu);
    if (cpu.terminate) return;
    // 004df9c3  ebc8                   -jmp 0x4df98d
    goto L_0x004df98d;
L_0x004df9c5:
    // 004df9c5  83faff                 +cmp edx, -1
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
    // 004df9c8  7404                   -je 0x4df9ce
    if (cpu.flags.zf)
    {
        goto L_0x004df9ce;
    }
    // 004df9ca  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004df9cc  ebc8                   -jmp 0x4df996
    goto L_0x004df996;
L_0x004df9ce:
    // 004df9ce  2eff1510455300         -call dword ptr cs:[0x534510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457168) /* 0x534510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004df9d5  ebbf                   -jmp 0x4df996
    goto L_0x004df996;
L_0x004df9d7:
    // 004df9d7  83f8fe                 +cmp eax, -2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df9da  7d0d                   -jge 0x4df9e9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004df9e9;
    }
    // 004df9dc  83f8f1                 +cmp eax, -0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-15 /*-0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004df9df  7522                   -jne 0x4dfa03
    if (!cpu.flags.zf)
    {
        goto L_0x004dfa03;
    }
    // 004df9e1  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 004df9e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df9e9:
    // 004df9e9  7f1d                   -jg 0x4dfa08
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004dfa08;
    }
    // 004df9eb  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 004df9f0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df9f3:
    // 004df9f3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004df9f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004df9fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004df9fb:
    // 004df9fb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfa00  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfa03:
    // 004dfa03  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004dfa05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa07  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfa08:
    // 004dfa08  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004dfa0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4dfa30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004dfa30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfa31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfa32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfa34  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004dfa36  833db8f59e0000         +cmp dword ptr [0x9ef5b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417592) /* 0x9ef5b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dfa3d  742a                   -je 0x4dfa69
    if (cpu.flags.zf)
    {
        goto L_0x004dfa69;
    }
L_0x004dfa3f:
    // 004dfa3f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004dfa41  752f                   -jne 0x4dfa72
    if (!cpu.flags.zf)
    {
        goto L_0x004dfa72;
    }
    // 004dfa43  8b0db0f59e00           -mov ecx, dword ptr [0x9ef5b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10417584) /* 0x9ef5b0 */);
    // 004dfa49  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004dfa4c  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dfa4f  7764                   -ja 0x4dfab5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004dfab5;
    }
    // 004dfa51  ff248510fa4d00         -jmp dword ptr [eax*4 + 0x4dfa10]
    cpu.ip = app->getMemory<x86::reg32>(5110288 + cpu.eax * 4); goto dynamic_jump;
  case 0x004dfa58:
    // 004dfa58  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
L_0x004dfa5d:
    // 004dfa5d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfa5e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfa5f  2eff15fc455300         -call dword ptr cs:[0x5345fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457404) /* 0x5345fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfa66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfa68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfa69:
    // 004dfa69  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004dfa6b  e8d0fcffff             -call 0x4df740
    cpu.esp -= 4;
    sub_4df740(app, cpu);
    if (cpu.terminate) return;
    // 004dfa70  ebcd                   -jmp 0x4dfa3f
    goto L_0x004dfa3f;
L_0x004dfa72:
    // 004dfa72  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dfa75  7411                   -je 0x4dfa88
    if (cpu.flags.zf)
    {
        goto L_0x004dfa88;
    }
    // 004dfa77  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004dfa79  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004dfa7c  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dfa7f  7734                   -ja 0x4dfab5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004dfab5;
    }
    // 004dfa81  ff248510fa4d00         -jmp dword ptr [eax*4 + 0x4dfa10]
    cpu.ip = app->getMemory<x86::reg32>(5110288 + cpu.eax * 4); goto dynamic_jump;
L_0x004dfa88:
    // 004dfa88  2eff1510455300         -call dword ptr cs:[0x534510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457168) /* 0x534510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfa8f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfa91  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004dfa94  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dfa97  771c                   -ja 0x4dfab5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004dfab5;
    }
    // 004dfa99  ff248510fa4d00         -jmp dword ptr [eax*4 + 0x4dfa10]
    cpu.ip = app->getMemory<x86::reg32>(5110288 + cpu.eax * 4); goto dynamic_jump;
  case 0x004dfaa0:
    // 004dfaa0  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004dfaa5  ebb6                   -jmp 0x4dfa5d
    goto L_0x004dfa5d;
  case 0x004dfaa7:
    // 004dfaa7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004dfaac  ebaf                   -jmp 0x4dfa5d
    goto L_0x004dfa5d;
  case 0x004dfaae:
    // 004dfaae  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfab3  eba8                   -jmp 0x4dfa5d
    goto L_0x004dfa5d;
  case 0x004dfab5:
L_0x004dfab5:
    // 004dfab5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004dfab7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfab8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfab9  2eff15fc455300         -call dword ptr cs:[0x5345fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457404) /* 0x5345fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfac0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfac1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfac2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004dfac3:
    // 004dfac3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004dfac8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfac9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfaca  2eff15fc455300         -call dword ptr cs:[0x5345fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457404) /* 0x5345fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfad1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfad2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfad3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004dfad4:
    // 004dfad4  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 004dfad9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfada  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfadb  2eff15fc455300         -call dword ptr cs:[0x5345fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457404) /* 0x5345fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfae2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfae3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfae4  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4dfaf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfaf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfaf1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfaf2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfaf4  2eff15c4445300         -call dword ptr cs:[0x5344c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457092) /* 0x5344c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfafb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfafc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfafd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dfb00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfb00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfb01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfb02  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfb04  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfb06  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfb08  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfb0a  2eff1594445300         -call dword ptr cs:[0x534494]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457044) /* 0x534494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfb11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb13  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4dfb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfb20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dfb22  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004dfb28  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004dfb2e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004dfb30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfb31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfb32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfb33  2eff15e8455300         -call dword ptr cs:[0x5345e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457384) /* 0x5345e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfb3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4dfb30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004dfb30;
    // 004dfb20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dfb22  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004dfb28  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004dfb2e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x004dfb30:
    // 004dfb30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfb31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfb32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfb33  2eff15e8455300         -call dword ptr cs:[0x5345e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457384) /* 0x5345e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfb3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfb40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfb41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfb42  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb45  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004dfb48  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfb4a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfb4f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004dfb51  e89afbffff             -call 0x4df6f0
    cpu.esp -= 4;
    sub_4df6f0(app, cpu);
    if (cpu.terminate) return;
    // 004dfb56  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004dfb59  750b                   -jne 0x4dfb66
    if (!cpu.flags.zf)
    {
        goto L_0x004dfb66;
    }
    // 004dfb5b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfb60  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfb66:
    // 004dfb66  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004dfb68  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dfb70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfb70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfb71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfb72  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb75  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004dfb78  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004dfb7d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfb7f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfb84  e867fbffff             -call 0x4df6f0
    cpu.esp -= 4;
    sub_4df6f0(app, cpu);
    if (cpu.terminate) return;
    // 004dfb89  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb8c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb8d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfb8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4dfb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfb90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfb91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfb92  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfb95  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004dfb98  8b0dd8435600           -mov ecx, dword ptr [0x5643d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004dfb9e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004dfba0  7505                   -jne 0x4dfba7
    if (!cpu.flags.zf)
    {
        goto L_0x004dfba7;
    }
    // 004dfba2  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x004dfba7:
    // 004dfba7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004dfbae  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004dfbb0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004dfbb3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004dfbb5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004dfbb8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004dfbba  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004dfbbd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004dfbbf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dfbc1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004dfbc4  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004dfbc6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfbc8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004dfbca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfbcf  e81cfbffff             -call 0x4df6f0
    cpu.esp -= 4;
    sub_4df6f0(app, cpu);
    if (cpu.terminate) return;
    // 004dfbd4  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004dfbd7  750b                   -jne 0x4dfbe4
    if (!cpu.flags.zf)
    {
        goto L_0x004dfbe4;
    }
    // 004dfbd9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfbde  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfbe1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfbe2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfbe3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfbe4:
    // 004dfbe4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004dfbe6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfbe9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfbea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfbeb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4dfbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfbf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfbf1  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004dfbf6  e8f5faffff             -call 0x4df6f0
    cpu.esp -= 4;
    sub_4df6f0(app, cpu);
    if (cpu.terminate) return;
    // 004dfbfb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfbfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfc03  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc0a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfc10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc12  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfc14  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfc16  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004dfc18  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004dfc1a  2eff1594445300         -call dword ptr cs:[0x534494]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457044) /* 0x534494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc21  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4dfc30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfc33  2eff15e8455300         -call dword ptr cs:[0x5345e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457384) /* 0x5345e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfc40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc42  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfc43  2eff15b8455300         -call dword ptr cs:[0x5345b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457336) /* 0x5345b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc4a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc52  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfc53  2eff15a4455300         -call dword ptr cs:[0x5345a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457316) /* 0x5345a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc5a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc5b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfc60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfc61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc62  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfc65  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004dfc68  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004dfc6d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfc6f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004dfc74  e877faffff             -call 0x4df6f0
    cpu.esp -= 4;
    sub_4df6f0(app, cpu);
    if (cpu.terminate) return;
    // 004dfc79  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004dfc7c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4dfc80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfc80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfc81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfc82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfc83  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004dfc85  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfc86  2eff15e8455300         -call dword ptr cs:[0x5345e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457384) /* 0x5345e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc8d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfc8e  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfc95  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfc98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4dfca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfca0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004dfca2  750b                   -jne 0x4dfcaf
    if (!cpu.flags.zf)
    {
        goto L_0x004dfcaf;
    }
    // 004dfca4  a1bcf59e00             -mov eax, dword ptr [0x9ef5bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417596) /* 0x9ef5bc */);
    // 004dfca9  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004dfcae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004dfcaf:
    // 004dfcaf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfcb0  8b15bcf59e00           -mov edx, dword ptr [0x9ef5bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10417596) /* 0x9ef5bc */);
    // 004dfcb6  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004dfcbc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfcbd  6800995400             -push 0x549900
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544192 /*0x549900*/;
    cpu.esp -= 4;
    // 004dfcc2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfcc3  e8c8f9ffff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004dfcc8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004dfccb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfccc  a1bcf59e00             -mov eax, dword ptr [0x9ef5bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417596) /* 0x9ef5bc */);
    // 004dfcd1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004dfcd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4dfce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfce0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfce1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfce2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004dfce3  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfcea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfceb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfcec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfcf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfcf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfcf1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfcf2  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfcf9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfcfa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfcfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4dfd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfd00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4dfd04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfd04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfd05  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfd06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004dfd08  ff1584445600           -call dword ptr [0x564484]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653636) /* 0x564484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfd0e  803d20649f0000         +cmp byte ptr [0x9f6420], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10445856) /* 0x9f6420 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004dfd15  750f                   -jne 0x4dfd26
    if (!cpu.flags.zf)
    {
        goto L_0x004dfd26;
    }
    // 004dfd17  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004dfd1c  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004dfd21  e846f70100             -call 0x4ff46c
    cpu.esp -= 4;
    sub_4ff46c(app, cpu);
    if (cpu.terminate) return;
L_0x004dfd26:
    // 004dfd26  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004dfd28  e803000000             -call 0x4dfd30
    cpu.esp -= 4;
    sub_4dfd30(app, cpu);
    if (cpu.terminate) return;
    // 004dfd2d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfd2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfd2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4dfd30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfd30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfd31  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004dfd33  ff1584445600           -call dword ptr [0x564484]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653636) /* 0x564484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfd39  ff1588445600           -call dword ptr [0x564488]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653640) /* 0x564488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004dfd3f  833df077560000         +cmp dword ptr [0x5677f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666800) /* 0x5677f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004dfd46  7406                   -je 0x4dfd4e
    if (cpu.flags.zf)
    {
        goto L_0x004dfd4e;
    }
    // 004dfd48  ff15f0775600           -call dword ptr [0x5677f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666800) /* 0x5677f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004dfd4e:
    // 004dfd4e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dfd50  e937f60100             -jmp 0x4ff38c
    return sub_4ff38c(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_4dfd56(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfd56  683f0c0000             -push 0xc3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 3135 /*0xc3f*/;
    cpu.esp -= 4;
    // 004dfd5b  d97c2402               -fnstcw word ptr [esp + 2]
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.fpu.control.word;
    // 004dfd5f  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004dfd62  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 004dfd64  d96c2402               -fldcw word ptr [esp + 2]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004dfd68  8d642404               -lea esp, [esp + 4]
    cpu.esp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfd6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4dfd6e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfd6e  90                     -nop 
    ;
    // 004dfd6f  90                     -nop 
    ;
    // 004dfd70  90                     -nop 
    ;
    // 004dfd71  90                     -nop 
    ;
    // 004dfd72  90                     -nop 
    ;
    // 004dfd73  90                     -nop 
    ;
    // 004dfd74  90                     -nop 
    ;
    // 004dfd75  90                     -nop 
    ;
    // 004dfd76  90                     -nop 
    ;
    // 004dfd77  90                     -nop 
    ;
    // 004dfd78  90                     -nop 
    ;
    // 004dfd79  90                     -nop 
    ;
    // 004dfd7a  90                     -nop 
    ;
    // 004dfd7b  90                     -nop 
    ;
    // 004dfd7c  90                     -nop 
    ;
    // 004dfd7d  90                     -nop 
    ;
    // 004dfd7e  90                     -nop 
    ;
    // 004dfd7f  90                     -nop 
    ;
    // 004dfd80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfd81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfd82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfd83  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfd86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfd88  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfd8c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfd8e  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004dfd92  e8d9ab0000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004dfd97  c7010000803f           -mov dword ptr [ecx], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ecx) = 1065353216 /*0x3f800000*/;
    // 004dfd9d  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004dfda4  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004dfdab  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004dfdb2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfdb6  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004dfdb9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004dfdbc  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004dfdc3  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004dfdc6  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004dfdc9  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dfdcb  d9591c                 -fstp dword ptr [ecx + 0x1c]
    app->getMemory<float>(cpu.ecx + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dfdce  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfdd2  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004dfdd5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfdd8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfdd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfdda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfddb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4dfd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004dfd80;
    // 004dfd6e  90                     -nop 
    ;
    // 004dfd6f  90                     -nop 
    ;
    // 004dfd70  90                     -nop 
    ;
    // 004dfd71  90                     -nop 
    ;
    // 004dfd72  90                     -nop 
    ;
    // 004dfd73  90                     -nop 
    ;
    // 004dfd74  90                     -nop 
    ;
    // 004dfd75  90                     -nop 
    ;
    // 004dfd76  90                     -nop 
    ;
    // 004dfd77  90                     -nop 
    ;
    // 004dfd78  90                     -nop 
    ;
    // 004dfd79  90                     -nop 
    ;
    // 004dfd7a  90                     -nop 
    ;
    // 004dfd7b  90                     -nop 
    ;
    // 004dfd7c  90                     -nop 
    ;
    // 004dfd7d  90                     -nop 
    ;
    // 004dfd7e  90                     -nop 
    ;
    // 004dfd7f  90                     -nop 
    ;
L_entry_0x004dfd80:
    // 004dfd80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfd81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfd82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfd83  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfd86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfd88  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfd8c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfd8e  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004dfd92  e8d9ab0000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004dfd97  c7010000803f           -mov dword ptr [ecx], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ecx) = 1065353216 /*0x3f800000*/;
    // 004dfd9d  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004dfda4  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004dfdab  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004dfdb2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfdb6  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004dfdb9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004dfdbc  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004dfdc3  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004dfdc6  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004dfdc9  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dfdcb  d9591c                 -fstp dword ptr [ecx + 0x1c]
    app->getMemory<float>(cpu.ecx + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dfdce  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfdd2  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004dfdd5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfdd8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfdd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfdda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfddb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dfde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfde0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfde1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfde2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfde3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfde6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfde8  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfdec  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfdee  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004dfdf2  e879ab0000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004dfdf7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfdfb  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004dfe02  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004dfe04  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004dfe07  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004dfe0e  c741100000803f         -mov dword ptr [ecx + 0x10], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = 1065353216 /*0x3f800000*/;
    // 004dfe15  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004dfe1c  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dfe1e  d95908                 -fstp dword ptr [ecx + 8]
    app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dfe21  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004dfe24  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004dfe2b  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004dfe2e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfe32  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004dfe35  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfe38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe3b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dfe40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfe40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfe41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfe42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfe43  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfe46  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfe48  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfe4c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004dfe4e  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004dfe52  e819ab0000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004dfe57  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfe5b  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004dfe5d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004dfe60  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004dfe67  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004dfe6a  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004dfe6d  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004dfe6f  d9590c                 -fstp dword ptr [ecx + 0xc]
    app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dfe72  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004dfe76  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004dfe7d  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004dfe84  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004dfe8b  c741200000803f         -mov dword ptr [ecx + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 004dfe92  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004dfe95  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004dfe98  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe99  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe9a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfe9b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4dfea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dfea0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004dfea1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dfea2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dfea3  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004dfea6  8b7c2444               -mov edi, dword ptr [esp + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004dfeaa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004dfeac  f7442440ffffff7f       +test dword ptr [esp + 0x40], 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) & 2147483647 /*0x7fffffff*/));
    // 004dfeb4  7515                   -jne 0x4dfecb
    if (!cpu.flags.zf)
    {
        goto L_0x004dfecb;
    }
    // 004dfeb6  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004dfebb  be98445600             -mov esi, 0x564498
    cpu.esi = 5653656 /*0x564498*/;
    // 004dfec0  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004dfec2  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004dfec5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfec6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfec7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfec8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004dfecb:
    // 004dfecb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004dfecc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004dfecd  8d5c2434               -lea ebx, [esp + 0x34]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004dfed1  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004dfed5  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004dfed9  e892aa0000             -call 0x4ea970
    cpu.esp -= 4;
    sub_4ea970(app, cpu);
    if (cpu.terminate) return;
    // 004dfede  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004dfee2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004dfee4  e8d7020000             -call 0x4e01c0
    cpu.esp -= 4;
    sub_4e01c0(app, cpu);
    if (cpu.terminate) return;
    // 004dfee9  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004dfeed  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004dfef1  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004dfef5  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004dfef9  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004dfefd  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004dff01  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004dff03  d8642434               -fsub dword ptr [esp + 0x34]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */));
    // 004dff07  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004dff09  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004dff0d  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004dff0f  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004dff13  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff15  d954241c               -fst dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    // 004dff19  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004dff1d  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dff1f  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004dff23  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dff25  d8442434               -fadd dword ptr [esp + 0x34]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */));
    // 004dff29  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004dff2d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff2f  d91f                   -fstp dword ptr [edi]
    app->getMemory<float>(cpu.edi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff31  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004dff35  d8c3                   -fadd st(3)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(3));
    // 004dff37  d95f04                 -fstp dword ptr [edi + 4]
    app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff3a  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004dff3e  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004dff42  d8e4                   -fsub st(4)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(4));
    // 004dff44  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004dff46  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff48  d95f08                 -fstp dword ptr [edi + 8]
    app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff4b  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004dff4f  dee3                   -fsubrp st(3)
    cpu.fpu.st(3) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(3));
    cpu.fpu.pop();
    // 004dff51  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004dff53  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004dff55  d95f0c                 -fstp dword ptr [edi + 0xc]
    app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff58  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dff5a  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004dff5e  d8442434               -fadd dword ptr [esp + 0x34]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */));
    // 004dff62  d95f10                 -fstp dword ptr [edi + 0x10]
    app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff65  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff67  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004dff6b  d8c3                   -fadd st(3)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(3));
    // 004dff6d  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004dff6f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff71  d95f14                 -fstp dword ptr [edi + 0x14]
    app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff74  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004dff78  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004dff7a  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004dff7c  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dff7e  d95f18                 -fstp dword ptr [edi + 0x18]
    app->getMemory<float>(cpu.edi + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff81  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff83  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004dff87  dee2                   -fsubrp st(2)
    cpu.fpu.st(2) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(2));
    cpu.fpu.pop();
    // 004dff89  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004dff8b  d95f1c                 -fstp dword ptr [edi + 0x1c]
    app->getMemory<float>(cpu.edi + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff8e  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004dff92  d8442434               -fadd dword ptr [esp + 0x34]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */));
    // 004dff96  d95f20                 -fstp dword ptr [edi + 0x20]
    app->getMemory<float>(cpu.edi + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dff99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dff9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dff9b  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004dff9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dff9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dffa0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dffa1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4dffb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004dffb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004dffb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004dffb2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004dffb4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004dffb6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004dffb8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004dffba  7e34                   -jle 0x4dfff0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004dfff0;
    }
L_0x004dffbc:
    // 004dffbc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004dffbe  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004dffc0  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004dffc2  d802                   -fadd dword ptr [edx]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx));
    // 004dffc4  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004dffc7  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004dffca  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004dffcd  d84208                 -fadd dword ptr [edx + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004dffd0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004dffd2  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004dffd5  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dffd7  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dffda  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004dffdd  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004dffe0  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004dffe1  75d9                   -jne 0x4dffbc
    if (!cpu.flags.zf)
    {
        goto L_0x004dffbc;
    }
    // 004dffe3  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004dffe9  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004dffef  90                     -nop 
    ;
L_0x004dfff0:
    // 004dfff0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfff1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004dfff2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e0000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0000  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0001  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0002  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e0004  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e0006  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e0008  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e000a  7e34                   -jle 0x4e0040
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e0040;
    }
L_0x004e000c:
    // 004e000c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e000e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e0010  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e0012  d822                   -fsub dword ptr [edx]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e0014  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0017  d86204                 -fsub dword ptr [edx + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e001a  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e001d  d86208                 -fsub dword ptr [edx + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0020  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0022  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e0025  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0027  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e002a  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e002d  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0030  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e0031  75d9                   -jne 0x4e000c
    if (!cpu.flags.zf)
    {
        goto L_0x004e000c;
    }
    // 004e0033  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e0039  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004e003f  90                     -nop 
    ;
L_0x004e0040:
    // 004e0040  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0041  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0042  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e0050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0050  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0051  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e0053  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e0057  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e0059  7e25                   -jle 0x4e0080
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e0080;
    }
    // 004e005b  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
L_0x004e005f:
    // 004e005f  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004e0061  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004e0063  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0065  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004e0068  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004e006a  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e006d  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004e0070  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004e0072  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0075  83c20c                 +add edx, 0xc
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0078  d958fc                 +fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e007b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e007c  75e1                   -jne 0x4e005f
    if (!cpu.flags.zf)
    {
        goto L_0x004e005f;
    }
    // 004e007e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004e0080:
    // 004e0080  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0081  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e0090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0090  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0093  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004e0095  d820                   -fsub dword ptr [eax]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax));
    // 004e0097  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e009a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004e009d  d86004                 -fsub dword ptr [eax + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 004e00a0  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00a4  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004e00a7  d86008                 -fsub dword ptr [eax + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 004e00aa  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e00ac  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00b0  e8eb050000             -call 0x4e06a0
    cpu.esp -= 4;
    sub_4e06a0(app, cpu);
    if (cpu.terminate) return;
    // 004e00b5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e00b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e00c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e00c0  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e00c2  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e00c4  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00c6  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e00c9  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e00cb  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00ce  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e00d1  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e00d3  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00d6  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004e00d9  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e00dc  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00df  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 004e00e2  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e00e5  d95b10                 -fstp dword ptr [ebx + 0x10]
    app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00e8  d94014                 -fld dword ptr [eax + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 004e00eb  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e00ee  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00f1  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 004e00f4  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e00f7  d95b18                 -fstp dword ptr [ebx + 0x18]
    app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e00fa  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004e00fd  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0100  d95b1c                 -fstp dword ptr [ebx + 0x1c]
    app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0103  d94020                 -fld dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */)));
    // 004e0106  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0109  d95b20                 -fstp dword ptr [ebx + 0x20]
    app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e010c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e0110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0110  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0111  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0114  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004e0116  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004e0118  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e011b  894a10                 -mov dword ptr [edx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004e011e  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0121  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004e0124  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004e0127  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e012a  d95a04                 -fstp dword ptr [edx + 4]
    app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e012d  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004e0130  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e0133  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 004e0136  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e0139  d95a08                 -fstp dword ptr [edx + 8]
    app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e013c  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004e013f  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e0142  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004e0145  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e0148  d95a14                 -fstp dword ptr [edx + 0x14]
    app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e014b  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e014e  894a1c                 -mov dword ptr [edx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004e0151  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0154  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0155  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0160  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0163  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0166  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e0169  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e016b  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e016d  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e0170  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0172  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e0175  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e0178  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e017a  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e017d  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0180  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e0182  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0184  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0186  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0188  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e018a  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e018d  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e018f  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0192  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0195  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4e01a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e01a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e01a1  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e01a4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004e01a6  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004e01a8  e8b3ffffff             -call 0x4e0160
    cpu.esp -= 4;
    sub_4e0160(app, cpu);
    if (cpu.terminate) return;
    // 004e01ad  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e01af  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e01b1  e80a000000             -call 0x4e01c0
    cpu.esp -= 4;
    sub_4e01c0(app, cpu);
    if (cpu.terminate) return;
    // 004e01b6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e01b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e01ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4e01c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e01c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e01c1  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e01c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e01c6  e8d5040000             -call 0x4e06a0
    cpu.esp -= 4;
    sub_4e06a0(app, cpu);
    if (cpu.terminate) return;
    // 004e01cb  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004e01cd  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004e01cf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004e01d1  def2                   -fdivrp st(2)
    cpu.fpu.st(2) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(2));
    cpu.fpu.pop();
    // 004e01d3  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004e01d5  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e01d7  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004e01da  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004e01dc  d95a04                 -fstp dword ptr [edx + 4]
    app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e01df  d84908                 -fmul dword ptr [ecx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */));
    // 004e01e2  d95a08                 -fstp dword ptr [edx + 8]
    app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e01e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e01e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e01e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e01f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e01f0  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e01f2  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e01f4  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e01f7  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e01fa  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e01fd  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0200  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0202  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0204  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0206  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4e0210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0210  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0211  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0212  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e0214  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e0216  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e0218  7e26                   -jle 0x4e0240
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e0240;
    }
L_0x004e021a:
    // 004e021a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e021c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e021e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0221  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e0223  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e0225  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0228  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e022b  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e022e  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0231  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0233  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0235  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0237  d959fc                 -fstp dword ptr [ecx - 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e023a  83c60c                 +add esi, 0xc
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e023d  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e023e  75da                   -jne 0x4e021a
    if (!cpu.flags.zf)
    {
        goto L_0x004e021a;
    }
L_0x004e0240:
    // 004e0240  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0241  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0242  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e0250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0250  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0251  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0254  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004e0256  e865ffffff             -call 0x4e01c0
    cpu.esp -= 4;
    sub_4e01c0(app, cpu);
    if (cpu.terminate) return;
    // 004e025b  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e025f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0260  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e0265  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e0269  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004e026d  e8defdffff             -call 0x4e0050
    cpu.esp -= 4;
    sub_4e0050(app, cpu);
    if (cpu.terminate) return;
    // 004e0272  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0275  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0276  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0280  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0281  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0282  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0283  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0284  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004e0287  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004e028b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004e028d  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004e0291  39d8                   +cmp eax, ebx
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
    // 004e0293  0f84fd000000           -je 0x4e0396
    if (cpu.flags.zf)
    {
        goto L_0x004e0396;
    }
L_0x004e0299:
    // 004e0299  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004e029d  39fd                   +cmp ebp, edi
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
    // 004e029f  7513                   -jne 0x4e02b4
    if (!cpu.flags.zf)
    {
        goto L_0x004e02b4;
    }
    // 004e02a1  3b7c2424               +cmp edi, dword ptr [esp + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e02a5  740b                   -je 0x4e02b2
    if (cpu.flags.zf)
    {
        goto L_0x004e02b2;
    }
    // 004e02a7  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004e02ac  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004e02ae  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004e02b0  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004e02b2:
    // 004e02b2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
L_0x004e02b4:
    // 004e02b4  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e02b7  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e02ba  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e02bc  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e02be  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02c0  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e02c3  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e02c6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02c8  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e02ca  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e02cd  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e02d0  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e02d2  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e02d5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02d7  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e02da  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e02dd  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02df  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e02e2  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e02e5  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e02e8  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e02ea  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e02ed  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02ef  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e02f2  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e02f5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e02f7  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e02fa  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 004e02fd  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e0300  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004e0303  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e0305  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0307  d94014                 -fld dword ptr [eax + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 004e030a  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e030d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e030f  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0312  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004e0315  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e0318  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 004e031b  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e031e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0320  d94014                 -fld dword ptr [eax + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 004e0323  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e0326  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0328  d95b10                 -fstp dword ptr [ebx + 0x10]
    app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e032b  d9400c                 -fld dword ptr [eax + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 004e032e  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0331  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 004e0334  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e0337  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0339  d94014                 -fld dword ptr [eax + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 004e033c  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e033f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0341  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0344  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004e0347  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e034a  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 004e034d  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e034f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0351  d94020                 -fld dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */)));
    // 004e0354  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e0357  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0359  d95b18                 -fstp dword ptr [ebx + 0x18]
    app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e035c  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 004e035f  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e0362  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004e0365  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e0368  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e036a  d94020                 -fld dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */)));
    // 004e036d  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e0370  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0372  d95b1c                 -fstp dword ptr [ebx + 0x1c]
    app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0375  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 004e0378  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e037b  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004e037e  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e0381  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0383  d94020                 -fld dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */)));
    // 004e0386  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e0389  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e038b  d95b20                 -fstp dword ptr [ebx + 0x20]
    app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e038e  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0391  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0392  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0393  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0394  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0395  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0396:
    // 004e0396  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004e039b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004e039d  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004e03a1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e03a3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e03a5  e9effeffff             -jmp 0x4e0299
    goto L_0x004e0299;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e03b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e03b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e03b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e03b2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e03b4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e03b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e03b8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e03ba  7e64                   -jle 0x4e0420
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e0420;
    }
L_0x004e03bc:
    // 004e03bc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e03be  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e03c0  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e03c2  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e03c4  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e03c6  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e03c9  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e03cb  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e03ce  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e03d0  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e03d3  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e03d6  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e03d9  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e03dc  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e03df  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e03e2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e03e4  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e03e6  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e03e8  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e03ea  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e03ed  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e03f0  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e03f3  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e03f6  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e03f9  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e03fc  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e03fe  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0400  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0402  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0404  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e0407  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0409  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e040c  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e040f  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0412  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e0413  75a7                   -jne 0x4e03bc
    if (!cpu.flags.zf)
    {
        goto L_0x004e03bc;
    }
    // 004e0415  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e041b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004e041e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
L_0x004e0420:
    // 004e0420  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0421  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0422  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e0430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0430  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0431  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0432  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0433  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0436  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e0438  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004e043a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004e043c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e043f  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004e0443  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e0445  0f8e85000000           -jle 0x4e04d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e04d0;
    }
L_0x004e044b:
    // 004e044b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e044d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e044f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e0451  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e0453  d80a                   +fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e0455  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e0457  d84a04                 +fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e045a  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e045c  d84a08                 +fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e045f  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0461  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0464  d84a0c                 +fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e0467  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e046a  d84a10                 +fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e046d  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0470  d84a14                 +fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e0473  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0475  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0477  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0479  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e047b  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e047e  d84a18                 +fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e0481  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e0484  d84a1c                 +fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e0487  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e048a  d84a20                 +fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e048d  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e048f  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0491  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0493  dec3                   +faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0495  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e0498  d91b                   +fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e049a  d95b04                 +fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e049d  d95b08                 +fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e04a0  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e04a3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e04a5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e04a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e04a9  d900                   +fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e04ab  d802                   +fadd dword ptr [edx]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx));
    // 004e04ad  d94004                 +fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e04b0  d84204                 +fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e04b3  d94008                 +fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e04b6  d84208                 +fadd dword ptr [edx + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e04b9  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e04bb  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e04be  d91b                   +fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e04c0  d95b04                 +fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e04c3  d95b08                 +fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e04c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e04c8  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e04c9  7580                   -jne 0x4e044b
    if (!cpu.flags.zf)
    {
        goto L_0x004e044b;
    }
    // 004e04cb  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e04ce  8bc9                   -mov ecx, ecx
    cpu.ecx = cpu.ecx;
L_0x004e04d0:
    // 004e04d0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e04d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e04d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e04d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e04d6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e04e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e04e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e04e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e04e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e04e3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e04e6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e04e8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004e04ea  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004e04ed  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004e04ef  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e04f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e04f5  0f8ea5000000           -jle 0x4e05a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e05a0;
    }
    // 004e04fb  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004e04ff  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004e0506  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e0508  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004e050b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004e050f:
    // 004e050f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0512  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e0514  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e0516  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e0518  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004e051a  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e051c  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e051f  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e0521  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e0524  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0526  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0529  d84a0c                 -fmul dword ptr [edx + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 004e052c  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e052f  d84a10                 -fmul dword ptr [edx + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004e0532  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0535  d84a14                 -fmul dword ptr [edx + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(20) /* 0x14 */));
    // 004e0538  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e053a  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e053c  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e053e  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0540  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e0543  d84a18                 -fmul dword ptr [edx + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004e0546  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e0549  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004e054c  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e054f  d84a20                 -fmul dword ptr [edx + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 004e0552  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e0554  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0556  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e0558  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e055a  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e055d  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e055f  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0562  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0565  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e0567  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004e0569  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e056b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e056d  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e056f  d802                   -fadd dword ptr [edx]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx));
    // 004e0571  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e0574  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004e0577  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e057a  d84208                 -fadd dword ptr [edx + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004e057d  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004e057f  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e0582  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0584  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0587  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e058a  034c2404               +add ecx, dword ptr [esp + 4]
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e058e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e058f  0f857affffff           -jne 0x4e050f
    if (!cpu.flags.zf)
    {
        goto L_0x004e050f;
    }
    // 004e0595  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e059b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004e059e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
L_0x004e05a0:
    // 004e05a0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e05a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e05a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e05a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e05a6  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e05b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e05b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e05b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e05b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e05b3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e05b5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e05b7  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004e05bc  e82f9f0000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e05c1  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004e05c6  8d5110                 -lea edx, [ecx + 0x10]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004e05c9  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004e05cc  e81f9f0000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e05d1  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004e05d6  8d5120                 -lea edx, [ecx + 0x20]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004e05d9  8d4618                 -lea eax, [esi + 0x18]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004e05dc  e80f9f0000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e05e1  c7413800000000         -mov dword ptr [ecx + 0x38], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 004e05e8  c7413c0000803f         -mov dword ptr [ecx + 0x3c], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = 1065353216 /*0x3f800000*/;
    // 004e05ef  8b4138                 -mov eax, dword ptr [ecx + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004e05f2  894134                 -mov dword ptr [ecx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004e05f5  8b4134                 -mov eax, dword ptr [ecx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 004e05f8  894130                 -mov dword ptr [ecx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004e05fb  8b4130                 -mov eax, dword ptr [ecx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 004e05fe  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004e0601  8b412c                 -mov eax, dword ptr [ecx + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 004e0604  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004e0607  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004e060a  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e060d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e060e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e060f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0610  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4e0620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0620  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0621  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e0623  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e0625  e886ffffff             -call 0x4e05b0
    cpu.esp -= 4;
    sub_4e05b0(app, cpu);
    if (cpu.terminate) return;
    // 004e062a  8d5330                 -lea edx, [ebx + 0x30]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004e062d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e062f  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004e0634  e8b79e0000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e0639  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e063a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0640  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0641  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004e0643  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e0644  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004e0646  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004e0649  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 004e064b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004e064e  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 004e0650  e86bee0100             -call 0x4ff4c0
    cpu.esp -= 4;
    sub_4ff4c0(app, cpu);
    if (cpu.terminate) return;
    // 004e0655  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0656  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0657  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e0658(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0658  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e0659(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0659  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0660  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0661  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004e0664  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e0666  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e066a  e851fbffff             -call 0x4e01c0
    cpu.esp -= 4;
    sub_4e01c0(app, cpu);
    if (cpu.terminate) return;
    // 004e066f  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004e0671  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e0673  e848fbffff             -call 0x4e01c0
    cpu.esp -= 4;
    sub_4e01c0(app, cpu);
    if (cpu.terminate) return;
    // 004e0678  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004e067a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e067e  e86dfbffff             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004e0683  e8fa8d0100             -call 0x4f9482
    cpu.esp -= 4;
    sub_4f9482(app, cpu);
    if (cpu.terminate) return;
    // 004e0688  dc0d20995400           -fmul qword ptr [0x549920]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5544224) /* 0x549920 */));
    // 004e068e  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004e0691  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0692  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e06a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e06a0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e06a3  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e06a5  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 004e06a7  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004e06aa  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 004e06ac  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004e06af  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004e06b1  d8c2                   -fadd st(2)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(2));
    // 004e06b3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004e06b5  d84808                 -fmul dword ptr [eax + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 004e06b8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004e06ba  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e06bc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004e06be  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 004e06c0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e06c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e06c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e06c4  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004e06c6  f6055878560001         +test byte ptr [0x567858], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5666904) /* 0x567858 */) & 1 /*0x1*/));
    // 004e06cd  7504                   -jne 0x4e06d3
    if (!cpu.flags.zf)
    {
        goto L_0x004e06d3;
    }
    // 004e06cf  d9f3                   +fpatan 
    cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004e06d1  eb05                   -jmp 0x4e06d8
    goto L_0x004e06d8;
L_0x004e06d3:
    // 004e06d3  e84cef0100             -call 0x4ff624
    cpu.esp -= 4;
    sub_4ff624(app, cpu);
    if (cpu.terminate) return;
L_0x004e06d8:
    // 004e06d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e06d9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e06d9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004e06db  f6055878560001         +test byte ptr [0x567858], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5666904) /* 0x567858 */) & 1 /*0x1*/));
    // 004e06e2  7504                   -jne 0x4e06e8
    if (!cpu.flags.zf)
    {
        goto L_0x004e06e8;
    }
    // 004e06e4  d9f3                   +fpatan 
    cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004e06e6  eb05                   -jmp 0x4e06ed
    goto L_0x004e06ed;
L_0x004e06e8:
    // 004e06e8  e837ef0100             -call 0x4ff624
    cpu.esp -= 4;
    sub_4ff624(app, cpu);
    if (cpu.terminate) return;
L_0x004e06ed:
    // 004e06ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e06ee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e06ee  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004e06f2  e8cdffffff             -call 0x4e06c4
    cpu.esp -= 4;
    sub_4e06c4(app, cpu);
    if (cpu.terminate) return;
    // 004e06f7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4e06fa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e06fa  dd44240c               -fld qword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004e06fe  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004e0702  e8d2ffffff             -call 0x4e06d9
    cpu.esp -= 4;
    sub_4e06d9(app, cpu);
    if (cpu.terminate) return;
    // 004e0707  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4e070c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e070c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e070d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e070f  e80d000000             -call 0x4e0721
    cpu.esp -= 4;
    sub_4e0721(app, cpu);
    if (cpu.terminate) return;
    // 004e0714  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0715  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e0716(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0716  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004e0718  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e0719  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e071b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004e071e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004e0720  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0721  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004e0726  0f85a7000000           -jne 0x4e07d3
    if (!cpu.flags.zf)
    {
        goto L_0x004e07d3;
    }
L_0x004e072c:
    // 004e072c  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e072f  7c3f                   -jl 0x4e0770
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0770;
    }
    // 004e0731  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0734  743b                   -je 0x4e0771
    if (cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e0736  38fb                   +cmp bl, bh
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0738  7537                   -jne 0x4e0771
    if (!cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e073a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004e073f  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0742  7813                   -js 0x4e0757
    if (cpu.flags.sf)
    {
        goto L_0x004e0757;
    }
L_0x004e0744:
    // 004e0744  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e0746  dd5008                 -fst qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 004e0749  dd5010                 -fst qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 004e074c  dd5018                 -fst qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 004e074f  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0752  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0755  79ed                   -jns 0x4e0744
    if (!cpu.flags.sf)
    {
        goto L_0x004e0744;
    }
L_0x004e0757:
    // 004e0757  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e075a  780a                   -js 0x4e0766
    if (cpu.flags.sf)
    {
        goto L_0x004e0766;
    }
L_0x004e075c:
    // 004e075c  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e075e  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e0761  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0764  79f6                   -jns 0x4e075c
    if (!cpu.flags.sf)
    {
        goto L_0x004e075c;
    }
L_0x004e0766:
    // 004e0766  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0768  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e076b  83c208                 +add edx, 8
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
    // 004e076e  753d                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
L_0x004e0770:
    // 004e0770  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0771:
    // 004e0771  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0774  781f                   -js 0x4e0795
    if (cpu.flags.sf)
    {
        goto L_0x004e0795;
    }
L_0x004e0776:
    // 004e0776  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e0778  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e077b  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004e077e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004e0781  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004e0784  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004e0787  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004e078a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004e078d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0790  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0793  79e1                   -jns 0x4e0776
    if (!cpu.flags.sf)
    {
        goto L_0x004e0776;
    }
L_0x004e0795:
    // 004e0795  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0798  780d                   -js 0x4e07a7
    if (cpu.flags.sf)
    {
        goto L_0x004e07a7;
    }
L_0x004e079a:
    // 004e079a  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e079c  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e079f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e07a2  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e07a5  79f3                   -jns 0x4e079a
    if (!cpu.flags.sf)
    {
        goto L_0x004e079a;
    }
L_0x004e07a7:
    // 004e07a7  83c208                 +add edx, 8
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
    // 004e07aa  7501                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
    // 004e07ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07ad:
    // 004e07ad  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 004e07b3  7405                   -je 0x4e07ba
    if (cpu.flags.zf)
    {
        goto L_0x004e07ba;
    }
    // 004e07b5  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e07b7  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004e07ba:
    // 004e07ba  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 004e07c0  7406                   -je 0x4e07c8
    if (cpu.flags.zf)
    {
        goto L_0x004e07c8;
    }
    // 004e07c2  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07c5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x004e07c8:
    // 004e07c8  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 004e07ce  7402                   -je 0x4e07d2
    if (cpu.flags.zf)
    {
        goto L_0x004e07d2;
    }
    // 004e07d0  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x004e07d2:
    // 004e07d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07d3:
    // 004e07d3  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004e07d8  740d                   -je 0x4e07e7
    if (cpu.flags.zf)
    {
        goto L_0x004e07e7;
    }
    // 004e07da  83fa01                 +cmp edx, 1
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
    // 004e07dd  7c08                   -jl 0x4e07e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07e7;
    }
    // 004e07df  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004e07e1  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e07e4  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004e07e7:
    // 004e07e7  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004e07ec  740e                   -je 0x4e07fc
    if (cpu.flags.zf)
    {
        goto L_0x004e07fc;
    }
    // 004e07ee  83fa02                 +cmp edx, 2
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
    // 004e07f1  7c09                   -jl 0x4e07fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07fc;
    }
    // 004e07f3  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07f6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004e07f9  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004e07fc:
    // 004e07fc  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004e0801  740d                   -je 0x4e0810
    if (cpu.flags.zf)
    {
        goto L_0x004e0810;
    }
    // 004e0803  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0806  7c08                   -jl 0x4e0810
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0810;
    }
    // 004e0808  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e080a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e080d  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004e0810:
    // 004e0810  e917ffffff             -jmp 0x4e072c
    goto L_0x004e072c;
}

/* align: skip  */
void Application::sub_4e0721(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004e0721;
    // 004e0716  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004e0718  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e0719  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e071b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004e071e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004e0720  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004e0721:
    // 004e0721  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004e0726  0f85a7000000           -jne 0x4e07d3
    if (!cpu.flags.zf)
    {
        goto L_0x004e07d3;
    }
L_0x004e072c:
    // 004e072c  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e072f  7c3f                   -jl 0x4e0770
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0770;
    }
    // 004e0731  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0734  743b                   -je 0x4e0771
    if (cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e0736  38fb                   +cmp bl, bh
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0738  7537                   -jne 0x4e0771
    if (!cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e073a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004e073f  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0742  7813                   -js 0x4e0757
    if (cpu.flags.sf)
    {
        goto L_0x004e0757;
    }
L_0x004e0744:
    // 004e0744  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e0746  dd5008                 -fst qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 004e0749  dd5010                 -fst qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 004e074c  dd5018                 -fst qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 004e074f  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0752  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0755  79ed                   -jns 0x4e0744
    if (!cpu.flags.sf)
    {
        goto L_0x004e0744;
    }
L_0x004e0757:
    // 004e0757  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e075a  780a                   -js 0x4e0766
    if (cpu.flags.sf)
    {
        goto L_0x004e0766;
    }
L_0x004e075c:
    // 004e075c  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e075e  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e0761  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0764  79f6                   -jns 0x4e075c
    if (!cpu.flags.sf)
    {
        goto L_0x004e075c;
    }
L_0x004e0766:
    // 004e0766  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0768  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e076b  83c208                 +add edx, 8
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
    // 004e076e  753d                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
L_0x004e0770:
    // 004e0770  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0771:
    // 004e0771  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0774  781f                   -js 0x4e0795
    if (cpu.flags.sf)
    {
        goto L_0x004e0795;
    }
L_0x004e0776:
    // 004e0776  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e0778  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e077b  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004e077e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004e0781  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004e0784  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004e0787  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004e078a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004e078d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0790  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0793  79e1                   -jns 0x4e0776
    if (!cpu.flags.sf)
    {
        goto L_0x004e0776;
    }
L_0x004e0795:
    // 004e0795  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0798  780d                   -js 0x4e07a7
    if (cpu.flags.sf)
    {
        goto L_0x004e07a7;
    }
L_0x004e079a:
    // 004e079a  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e079c  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e079f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e07a2  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e07a5  79f3                   -jns 0x4e079a
    if (!cpu.flags.sf)
    {
        goto L_0x004e079a;
    }
L_0x004e07a7:
    // 004e07a7  83c208                 +add edx, 8
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
    // 004e07aa  7501                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
    // 004e07ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07ad:
    // 004e07ad  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 004e07b3  7405                   -je 0x4e07ba
    if (cpu.flags.zf)
    {
        goto L_0x004e07ba;
    }
    // 004e07b5  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e07b7  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004e07ba:
    // 004e07ba  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 004e07c0  7406                   -je 0x4e07c8
    if (cpu.flags.zf)
    {
        goto L_0x004e07c8;
    }
    // 004e07c2  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07c5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x004e07c8:
    // 004e07c8  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 004e07ce  7402                   -je 0x4e07d2
    if (cpu.flags.zf)
    {
        goto L_0x004e07d2;
    }
    // 004e07d0  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x004e07d2:
    // 004e07d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07d3:
    // 004e07d3  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004e07d8  740d                   -je 0x4e07e7
    if (cpu.flags.zf)
    {
        goto L_0x004e07e7;
    }
    // 004e07da  83fa01                 +cmp edx, 1
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
    // 004e07dd  7c08                   -jl 0x4e07e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07e7;
    }
    // 004e07df  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004e07e1  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e07e4  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004e07e7:
    // 004e07e7  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004e07ec  740e                   -je 0x4e07fc
    if (cpu.flags.zf)
    {
        goto L_0x004e07fc;
    }
    // 004e07ee  83fa02                 +cmp edx, 2
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
    // 004e07f1  7c09                   -jl 0x4e07fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07fc;
    }
    // 004e07f3  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07f6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004e07f9  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004e07fc:
    // 004e07fc  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004e0801  740d                   -je 0x4e0810
    if (cpu.flags.zf)
    {
        goto L_0x004e0810;
    }
    // 004e0803  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0806  7c08                   -jl 0x4e0810
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0810;
    }
    // 004e0808  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e080a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e080d  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004e0810:
    // 004e0810  e917ffffff             -jmp 0x4e072c
    goto L_0x004e072c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0820  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0821  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0822  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0823  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0824  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0825  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0828  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e082a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004e082c  803a00                 +cmp byte ptr [edx], 0
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
    // 004e082f  7507                   -jne 0x4e0838
    if (!cpu.flags.zf)
    {
        goto L_0x004e0838;
    }
    // 004e0831  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0833  e9ad000000             -jmp 0x4e08e5
    goto L_0x004e08e5;
L_0x004e0838:
    // 004e0838  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 004e083c  7525                   -jne 0x4e0863
    if (!cpu.flags.zf)
    {
        goto L_0x004e0863;
    }
    // 004e083e  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
L_0x004e0840:
    // 004e0840  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e0842  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0844  7412                   -je 0x4e0858
    if (cpu.flags.zf)
    {
        goto L_0x004e0858;
    }
    // 004e0846  3c00                   +cmp al, 0
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
    // 004e0848  740c                   -je 0x4e0856
    if (cpu.flags.zf)
    {
        goto L_0x004e0856;
    }
    // 004e084a  46                     -inc esi
    (cpu.esi)++;
    // 004e084b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e084d  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e084f  7407                   -je 0x4e0858
    if (cpu.flags.zf)
    {
        goto L_0x004e0858;
    }
    // 004e0851  46                     -inc esi
    (cpu.esi)++;
    // 004e0852  3c00                   +cmp al, 0
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
    // 004e0854  75ea                   -jne 0x4e0840
    if (!cpu.flags.zf)
    {
        goto L_0x004e0840;
    }
L_0x004e0856:
    // 004e0856  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004e0858:
    // 004e0858  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e085a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e085d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e085e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e085f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0860  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0861  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0862  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0863:
    // 004e0863  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004e0868  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004e086a  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004e086c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e086d  e30b                   -jecxz 0x4e087a
    if (cpu.ecx == 0)
    {
        goto L_0x004e087a;
    }
    // 004e086f  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004e0871  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004e0873  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004e0875  7503                   -jne 0x4e087a
    if (!cpu.flags.zf)
    {
        goto L_0x004e087a;
    }
    // 004e0877  4f                     -dec edi
    (cpu.edi)--;
    // 004e0878  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x004e087c;
L_0x004e087a:
    // 004e087a  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x004e087c:
    // 004e087c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e087d  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004e0880  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e0882  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e0883  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004e0885  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004e0887  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e0889  49                     -dec ecx
    (cpu.ecx)--;
    // 004e088a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e088c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004e088e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004e0890  49                     -dec ecx
    (cpu.ecx)--;
    // 004e0891  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e0892  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
L_0x004e0894:
    // 004e0894  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0897  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004e0899  39e9                   +cmp ecx, ebp
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
    // 004e089b  7246                   -jb 0x4e08e3
    if (cpu.flags.cf)
    {
        goto L_0x004e08e3;
    }
    // 004e089d  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004e089f  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004e08a1  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e08a2  e30b                   -jecxz 0x4e08af
    if (cpu.ecx == 0)
    {
        goto L_0x004e08af;
    }
    // 004e08a4  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004e08a6  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004e08a8  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004e08aa  7503                   -jne 0x4e08af
    if (!cpu.flags.zf)
    {
        goto L_0x004e08af;
    }
    // 004e08ac  4f                     -dec edi
    (cpu.edi)--;
    // 004e08ad  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x004e08b1;
L_0x004e08af:
    // 004e08af  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x004e08b1:
    // 004e08b1  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e08b2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e08b4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e08b6  742b                   -je 0x4e08e3
    if (cpu.flags.zf)
    {
        goto L_0x004e08e3;
    }
    // 004e08b8  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004e08ba  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e08bc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e08be  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e08bf  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004e08c1  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004e08c3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e08c5  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 004e08c7  7405                   -je 0x4e08ce
    if (cpu.flags.zf)
    {
        goto L_0x004e08ce;
    }
    // 004e08c9  19c0                   +sbb eax, eax
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
    // 004e08cb  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004e08ce:
    // 004e08ce  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e08cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e08d1  750b                   -jne 0x4e08de
    if (!cpu.flags.zf)
    {
        goto L_0x004e08de;
    }
    // 004e08d3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e08d5  83c404                 +add esp, 4
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
    // 004e08d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e08de:
    // 004e08de  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004e08e1  ebb1                   -jmp 0x4e0894
    goto L_0x004e0894;
L_0x004e08e3:
    // 004e08e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e08e5:
    // 004e08e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e08e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
