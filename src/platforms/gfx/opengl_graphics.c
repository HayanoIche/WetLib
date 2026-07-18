#include <glad/glad.h>

#include "wet.h"
#include "wet/log.h"

#include "opengl.h"

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

// struct do renderer
OpenGLRenderer open_gl_renderer = { 0 };
bool opengl_started = false;

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
        
        opengl_started = true;
        LOG_INFO("%d", opengl_started);
        
    #elif defined(WET_PLATFORM_LINUX)
        LOG_FATAL("CONEXÃO COM A JANELA DO LINUX AINDA NÃO IMPLEMENTADA");
        return false;
    #elif defined (WET_PLATFORM_MACOS)
        LOG_FATAL("CONEXÃO COM A JANELA DO MACOS AINDA NÃO IMPLEMENTADA");
        return false;
    #endif

    open_gl_renderer.default_shader_program = create_shader_program(default_vertex_sh_source, default_fragment_sh_source);
    LOG_INFO("[OPEN GL] Pipeline de Shaders default inicializado com sucesso! ID: %u", open_gl_renderer.default_shader_program);
    
    opengl_init_quad();
    LOG_INFO("[OPEN GL] Quad inicializado com sucesso!");
    return true;
}

void opengl_clear_screen(Color color)
{
    float32 r = (float32)color.r / 255.0f;
    float32 g = (float32)color.g / 255.0f;
    float32 b = (float32)color.b / 255.0f;
    float32 a = (float32)color.a / 255.0f;

    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glUseProgram(open_gl_renderer.default_shader_program);
    glBindVertexArray(open_gl_renderer.quad_vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void opengl_shut(void)
{
    if (open_gl_renderer.default_shader_program != 0)
    {
        glDeleteProgram(open_gl_renderer.default_shader_program);
    }
}

void opengl_on_resize(uint32 w, uint32 h)
{
    if (opengl_started)
    {
        LOG_INFO("JANELA REDIMENSIONADA");
        // a Implementar
    }
}