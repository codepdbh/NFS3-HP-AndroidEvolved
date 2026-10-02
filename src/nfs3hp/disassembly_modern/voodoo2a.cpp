#include "voodoo2a.h"
#include <x86.h>
#include <winapi/wrapper.h>

namespace voodoo2a
{

win32::Library s_library = win32::Library("voodoo2a.dll");
win32::Library* s_registry = &(s_library
        .registerSymbol("_THRASH_about@0", &sub_aa4c60)
        .registerSymbol("_THRASH_clearwindow@0", &sub_aa57b0)
        .registerSymbol("_THRASH_clip@16", &sub_aa58b0)
        .registerSymbol("_THRASH_drawline@8", &sub_aa7240)
        .registerSymbol("_THRASH_drawlinemesh@12", &sub_aa7350)
        .registerSymbol("_THRASH_drawlinestrip@8", &sub_aa7490)
        .registerSymbol("_THRASH_drawpoint@4", &sub_aa7650)
        .registerSymbol("_THRASH_drawpointmesh@12", &sub_aa76e0)
        .registerSymbol("_THRASH_drawpointstrip@8", &sub_aa7790)
        .registerSymbol("_THRASH_drawquad@16", &sub_aa6300)
        .registerSymbol("_THRASH_drawquadmesh@12", &sub_aa6520)
        .registerSymbol("_THRASH_drawtri@12", &sub_aa6770)
        .registerSymbol("_THRASH_drawtrifan@8", &sub_aa7000)
        .registerSymbol("_THRASH_drawtrimesh@12", &sub_aa6900)
        .registerSymbol("_THRASH_drawtristrip@8", &sub_aa6ac0)
        .registerSymbol("_THRASH_flushwindow@0", &sub_aa57d0)
        .registerSymbol("_THRASH_idle@0", &sub_aa5810)
        .registerSymbol("_THRASH_init@0", &sub_aa4f50)
        .registerSymbol("_THRASH_is@0", &sub_aa4df0)
        .registerSymbol("_THRASH_lockwindow@0", &sub_aa60f0)
        .registerSymbol("_THRASH_pageflip@0", &sub_aa57e0)
        .registerSymbol("_THRASH_readrect@20", &sub_aa6220)
        .registerSymbol("_THRASH_restore@0", &sub_aa5100)
        .registerSymbol("_THRASH_selectdisplay@4", &sub_aa4f10)
        .registerSymbol("_THRASH_setstate@8", &sub_aa5990)
        .registerSymbol("_THRASH_settexture@4", &sub_aa56d0)
        .registerSymbol("_THRASH_setvideomode@12", &sub_aa53d0)
        .registerSymbol("_THRASH_sync@4", &sub_aa5830)
        .registerSymbol("_THRASH_talloc@20", &sub_aa54b0)
        .registerSymbol("_THRASH_treset@0", &sub_aa5690)
        .registerSymbol("_THRASH_tupdate@12", &sub_aa5630)
        .registerSymbol("_THRASH_unlockwindow@4", &sub_aa61d0)
        .registerSymbol("_THRASH_window@4", &sub_aa5780)
        .registerSymbol("_THRASH_writerect@20", &sub_aa6290)

    );
}
