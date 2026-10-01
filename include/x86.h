#ifndef X86_H_
#define X86_H_

#include    <cstdint>
#include    <cstdlib>

#ifdef __ANDROID__
#include <android/log.h>
#define NFS2_ASSERT(x) \
    do { if (!(x)) __android_log_assert(#x, "NFS3/CPU", "%s:%d: %s", __FILE__, __LINE__, #x); } while (false)
#elif defined(_MSC_VER)
# define __restrict__ __restrict
# define NFS2_ASSERT(x)         \
    if (! (x)) __debugbreak()
#else
# define NFS2_ASSERT(x)         \
    do { if (!(x)) __builtin_trap(); } while (false)
#endif
#define NFS2_USE(x)             \
    (void)x


namespace x86
{

typedef uint8_t reg8;
typedef uint16_t reg16;
typedef uint32_t reg32;
typedef uint64_t reg64;

typedef int8_t sreg8;
typedef int16_t sreg16;
typedef int32_t sreg32;
typedef int64_t sreg64;

struct CPU;
struct FPU;

}

#if defined(_MSC_VER) && !defined(__clang__)
# include <intrin.h>
static inline x86::reg32 __builtin_clz(x86::reg32 value)
{
    unsigned long result;
    _BitScanReverse(&result, value);
    return 31 - result;
}

static inline x86::reg32 __builtin_ctz(x86::reg32 value)
{
    unsigned long result;
    _BitScanForward(&result, value);
    return result;
}
#endif

#endif /* !X86_H_ */
