#include <lib/renderer.h>
#include <lib/window.h>
#include <lib/gamepad.h>
#include <lib/gl_api.h>
#include <SDL.h>
#include <vector>

namespace win32 {
static GLuint shader(GLenum type, const char* source) {
    GLuint result = glCreateShader(type);
    glShaderSource(result, 1, &source, nullptr);
    glCompileShader(result);
    GLint ok = 0;
    glGetShaderiv(result, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        char log[2048]; glGetShaderInfoLog(result, sizeof(log), nullptr, log);
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "[NFS3][VIDEO] %s", log);
        NFS2_ASSERT(ok);
    }
    return result;
}
Renderer::Renderer(WinApplication* app, Window* window)
    : m_application(app), m_window(window), m_renderer(SDL_GL_CreateContext(window->m_window)),
      m_texture(0), m_videoMemory(new MemMap(2048*1024*2*2)), m_currentBuffer(0),
      m_width(640), m_height(480), m_depth(16), m_colorPalette{} {
    if (!m_renderer) SDL_LogError(SDL_LOG_CATEGORY_RENDER, "[NFS3][VIDEO] GLES context: %s", SDL_GetError());
    NFS2_ASSERT(m_renderer);
    setCurrent();
    SDL_Log("[NFS3][VIDEO] %s / %s", glGetString(GL_RENDERER), glGetString(GL_VERSION));
    const char* vs = NFS_SHADER_VERSION
        "out vec2 uv; void main(){vec2 p=vec2((gl_VertexID<<1)&2,gl_VertexID&2);"
        "uv=vec2(p.x,1.0-p.y);gl_Position=vec4(p*2.0-1.0,0,1);}";
    const char* fs = NFS_SHADER_VERSION
        "in vec2 uv; uniform sampler2D screen; out vec4 color; void main(){color=texture(screen,uv);}";
    GLuint v = shader(GL_VERTEX_SHADER, vs), f = shader(GL_FRAGMENT_SHADER, fs);
    m_presentProgram = glCreateProgram();
    glAttachShader(m_presentProgram, v); glAttachShader(m_presentProgram, f);
    glLinkProgram(m_presentProgram);
    GLint ok = 0; glGetProgramiv(m_presentProgram, GL_LINK_STATUS, &ok); NFS2_ASSERT(ok);
    glDeleteShader(v); glDeleteShader(f);
    glGenVertexArrays(1, &m_presentVao);
    glGenTextures(1, &m_texture);
    setVideoMode(640,480,16);
    clearCurrent();
}
Renderer::~Renderer() {
    setCurrent(); glDeleteTextures(1,&m_texture); glDeleteVertexArrays(1,&m_presentVao);
    glDeleteProgram(m_presentProgram); clearCurrent(); SDL_GL_DeleteContext(m_renderer);
    delete m_videoMemory;
}
void Renderer::setCurrent(){ NFS2_ASSERT(SDL_GL_MakeCurrent(m_window->m_window,m_renderer)==0); }
void Renderer::clearCurrent(){ SDL_GL_MakeCurrent(m_window->m_window,nullptr); }
void Renderer::setVideoMode(x86::reg32 w,x86::reg32 h,x86::reg32 bpp){
    SDL_Log("[NFS3][VIDEO] Mode %ux%u depth %u", w,h,bpp);
    Window::setRenderSize(w,h);
    NFS2_ASSERT(w && h && w<=2048 && h<=1024);
    m_width=w;m_height=h;m_depth=bpp;setCurrent();glBindTexture(GL_TEXTURE_2D,m_texture);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,w,h,0,GL_RGBA,GL_UNSIGNED_BYTE,nullptr);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);clearCurrent();
}
void Renderer::updatePalette(x86::reg32 count,const x86::reg32* colors){NFS2_ASSERT(count<=256);memcpy(m_colorPalette,colors,count*4);}
x86::reg32 Renderer::getFrontBuffer()const{return m_videoMemory->getBlockStart()+m_currentBuffer*m_width*m_height*2;}
x86::reg32 Renderer::getBackBuffer()const{return m_videoMemory->getBlockStart()+(1-m_currentBuffer)*m_width*m_height*2;}
void Renderer::present(){
    Gamepad::updateKeys();int w=0,h=0;SDL_GL_GetDrawableSize(m_window->m_window,&w,&h);if(w<=0||h<=0)return;
    glBindFramebuffer(GL_FRAMEBUFFER,0);glDisable(GL_DEPTH_TEST);glDisable(GL_BLEND);glDepthMask(GL_FALSE);
    glViewport(0,0,w,h);glClearColor(0,0,0,1);glClear(GL_COLOR_BUFFER_BIT);
    float left,top,sx,sy;Window::getViewport(w,h,left,top,sx,sy);
    glViewport(int(left),int(top),int(m_width*sx+0.5f),int(m_height*sy+0.5f));
    glUseProgram(m_presentProgram);glActiveTexture(GL_TEXTURE0);glBindTexture(GL_TEXTURE_2D,m_texture);
    glBindVertexArray(m_presentVao);glDrawArrays(GL_TRIANGLES,0,3);glUseProgram(0);
#ifndef NDEBUG
    GLenum error=glGetError(); if(error!=GL_NO_ERROR) SDL_LogError(SDL_LOG_CATEGORY_RENDER,"[NFS3][VIDEO] Present error 0x%x",error);
#endif
    SDL_GL_SwapWindow(m_window->m_window);
}
void Renderer::update(){
    // Persistent staging buffer: allocating 1.2 MB per frame was a measurable cost.
    static std::vector<uint32_t> rgba;
    const size_t count=size_t(m_width)*m_height;
    if(rgba.size()<count) rgba.resize(count);
    uint32_t* out=rgba.data();
    const auto* data=&m_application->getMemory<x86::reg8>(getFrontBuffer());
    if(m_depth==16){
        const uint16_t* src=reinterpret_cast<const uint16_t*>(data);
        for(size_t i=0;i<count;++i){
            const uint32_t c=src[i];
            const uint32_t r=((c>>8)&0xf8)|(c>>13), g=((c>>3)&0xfc)|((c>>9)&3), b=((c<<3)&0xf8)|((c>>2)&7);
            out[i]=0xff000000u|(b<<16)|(g<<8)|r;
        }
    } else {
        uint32_t lut[256];
        for(int i=0;i<256;++i){const uint32_t c=m_colorPalette[i];lut[i]=0xff000000u|((c>>8)&0xff)<<16|((c>>16)&0xff)<<8|(c>>24);}
        for(size_t i=0;i<count;++i) out[i]=lut[data[i]];
    }
    glBindTexture(GL_TEXTURE_2D,m_texture);glTexSubImage2D(GL_TEXTURE_2D,0,0,0,m_width,m_height,GL_RGBA,GL_UNSIGNED_BYTE,out);present();
}
x86::reg32 Renderer::lock(x86::reg32 i){return i==0?getFrontBuffer():getBackBuffer();}
void Renderer::unlock(x86::reg32 i){if(i==0){setCurrent();update();clearCurrent();}}
void Renderer::swap(){setCurrent();setSwapInterval(1);m_currentBuffer=1-m_currentBuffer;update();clearCurrent();}
}
