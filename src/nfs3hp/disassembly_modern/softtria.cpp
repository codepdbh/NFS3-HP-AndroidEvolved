#include "softtria.h"
#include <x86.h>
#include <winapi/wrapper.h>

namespace softtria
{

win32::Library s_library = win32::Library("softtria.dll");
win32::Library* s_registry = &(s_library
        .registerSymbol("_THRASH_about@0", &sub_a61f30)
        .registerSymbol("_THRASH_clearwindow@0", &sub_a63070)
        .registerSymbol("_THRASH_clip@16", &sub_a63090)
        .registerSymbol("_THRASH_drawline@8", &sub_a64c20)
        .registerSymbol("_THRASH_drawlinemesh@12", &sub_a64df0)
        .registerSymbol("_THRASH_drawlinestrip@8", &sub_a64e30)
        .registerSymbol("_THRASH_drawpoint@4", &sub_a64e60)
        .registerSymbol("_THRASH_drawpointmesh@12", &sub_a64eb0)
        .registerSymbol("_THRASH_drawpointstrip@8", &sub_a64ef0)
        .registerSymbol("_THRASH_drawquad@16", &sub_a64aa0)
        .registerSymbol("_THRASH_drawquadmesh@12", &sub_a64b30)
        .registerSymbol("_THRASH_drawtri@12", &sub_a649a0)
        .registerSymbol("_THRASH_drawtrifan@8", &sub_a64be0)
        .registerSymbol("_THRASH_drawtrimesh@12", &sub_a64a50)
        .registerSymbol("_THRASH_drawtristrip@8", &sub_a64b90)
        .registerSymbol("_THRASH_flushwindow@0", &sub_a63080)
        .registerSymbol("_THRASH_idle@0", &sub_a63080)
        .registerSymbol("_THRASH_init@0", &sub_a627d0)
        .registerSymbol("_THRASH_is@0", &sub_a62b50)
        .registerSymbol("_THRASH_lockwindow@0", &sub_a63130)
        .registerSymbol("_THRASH_pageflip@0", &sub_a63350)
        .registerSymbol("_THRASH_readrect@20", &sub_a62b60)
        .registerSymbol("_THRASH_restore@0", &sub_a627f0)
        .registerSymbol("_THRASH_selectdisplay@4", &sub_a62820)
        .registerSymbol("_THRASH_setstate@8", &sub_a62cc0)
        .registerSymbol("_THRASH_settexture@4", &sub_a63b30)
        .registerSymbol("_THRASH_setvideomode@12", &sub_a62880)
        .registerSymbol("_THRASH_sync@4", &sub_a63060)
        .registerSymbol("_THRASH_talloc@20", &sub_a63850)
        .registerSymbol("_THRASH_treset@0", &sub_a63c80)
        .registerSymbol("_THRASH_tupdate@12", &sub_a639c0)
        .registerSymbol("_THRASH_unlockwindow@4", &sub_a632d0)
        .registerSymbol("_THRASH_window@4", &sub_a62ff0)
        .registerSymbol("_THRASH_writerect@20", &sub_a62c00)

    );
}
