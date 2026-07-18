#ifndef WET_OPENGL
#define WET_OPENGL

#include <glad/glad.h>
#include "wet.h"

typedef struct {
    uint32 default_shader_program;

    // Quad
    uint32 quad_vao;
    uint32 quad_vbo;
    uint32 quad_ebo;
} OpenGLRenderer;

extern OpenGLRenderer open_gl_renderer;
extern bool opengl_started;

// Criar um shaders
uint32 opengl_shader_create_program(const char* vertex_src, const char* fragment_src);

// Quad
void opengl_quad_init(void);
void opengl_quad_free(void);

#endif
