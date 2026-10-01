#pragma once
#ifdef __ANDROID__
#include <GLES3/gl3.h>
#define NFS_SHADER_VERSION "#version 300 es\nprecision highp float;\nprecision highp int;\n"
#else
#include <SDL_opengl.h>
#define NFS_SHADER_VERSION "#version 400\n"
#endif
