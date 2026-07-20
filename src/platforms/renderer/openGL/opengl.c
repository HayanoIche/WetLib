#include <glad/glad.h>

#include "wet.h"
#include "wet/log.h"

#include "opengl.h"

#include "src/core/graphics/graphics.h"

// struct do renderer
OpenGLRenderer open_gl_renderer = { 0 };

// ----------------------------------------------------------------------
//  Declarando as funções do open GL específicas de cada plataforma
// ----------------------------------------------------------------------

#if defined(WET_PLATFORM_WINDOWS)
    bool win32_opengl_graphics_init(void);
    void* win32_opengl_get_proc_address(const char* procname);
#elif defined(WET_PLATFORM_LINUX)
    // Funções pra carregar o openGL no linux
#elif defined(WET_PLATFORM_MACOS)
    // Funções pra carregar o openGL no MacOS
#endif


// ----------------------------------------------------------------------
//  Implementando as funções do open GL
// ----------------------------------------------------------------------

// Função que inicia o openGL
bool opengl_init(void)
{
    #if defined(WET_PLATFORM_WINDOWS)
        // NO WINDOWS
        if (!win32_opengl_graphics_init())
        {
            LOG_FATAL("FALHA AO INICIALIZAR O CONTEXTO OPENGL NO WINDOWS!");
            return false;
        }

        if (!gladLoadGLLoader((GLADloadproc)win32_opengl_get_proc_address)) 
        {
            LOG_FATAL("FALHA AO CARREGAR OS PONTEIROS DO OPENGL COM O GLAD!");
            return false;
        }

        LOG_INFO("OpenGL moderno e GLAD inicializados com SUCESSO!");
        
        open_gl_renderer.started = true;
        LOG_INFO("%d", open_gl_renderer.started);
        
    #elif defined(WET_PLATFORM_LINUX)
        LOG_FATAL("CONEXÃO COM A JANELA DO LINUX AINDA NÃO IMPLEMENTADA");
        return false;
    #elif defined (WET_PLATFORM_MACOS)
        LOG_FATAL("CONEXÃO COM A JANELA DO MACOS AINDA NÃO IMPLEMENTADA");
        return false;
    #endif
    
    open_gl_renderer.default_shader_program = opengl_shader_create_program(default_vertex_sh_source, default_fragment_sh_source);
    LOG_INFO("[OPEN GL] Pipeline de Shaders default inicializado com sucesso! ID: %u", open_gl_renderer.default_shader_program);
    
    opengl_quad_init();
    LOG_INFO("[OPEN GL] Quad inicializado com sucesso!");
    return true;
}

void opengl_shut(void)
{
    opengl_quad_free();

    if (open_gl_renderer.default_shader_program != 0)
    {
        glDeleteProgram(open_gl_renderer.default_shader_program);
    }
}

bool opengl_functions_load(void)
{
    graphics_fa.draw_clear = opengl_draw_clear;

    return true;
}

