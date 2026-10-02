#pragma once
#ifdef __ANDROID__
#include <GLES3/gl3.h>
#include <SDL_video.h>
#define NFS_SHADER_VERSION "#version 300 es\nprecision highp float;\nprecision highp int;\n"
namespace win32 {
// eglSwapInterval is not free on every driver; the game asks for it every frame.
inline void setSwapInterval(int interval) {
    static int s_current = -1;
    if (interval != s_current && SDL_GL_SetSwapInterval(interval) == 0) s_current = interval;
}
}
#else
#include <SDL_opengl.h>
#define NFS_SHADER_VERSION "#version 400\n"
#endif
