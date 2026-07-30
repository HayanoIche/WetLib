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
    
    open_gl_renderer.default_shader_program = opengl_shader_create(default_vertex_sh_source, default_fragment_sh_source);
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

    // Surfaces
    graphics_fa.surface_create = opengl_surface_create;
    graphics_fa.surface_destroy = opengl_surface_destroy;
    graphics_fa.surface_destroy_all = opengl_surface_destroy_all;
    graphics_fa.surface_set_target = opengl_surface_set_target;

    return true;
}

// -----------------------------------------------
//  Vertex
// -----------------------------------------------

void vertex_config_attributes(void)
{
    // Posição
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
    // Cor
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
    // Coordenadas
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    // Normals
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
}

