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

// -----------------------------------------------
//  Função pra criar um shaders
// -----------------------------------------------

uint32 opengl_shader_create_program(const char* vertex_src, const char* fragment_src);


// -----------------------------------------------
//  Shaders default imbutidos na biblioteca
// -----------------------------------------------

// Vertex shader padrão
static const char* default_vertex_sh_source = 
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main() {\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n";

// Fragment shader padrão
static const char* default_fragment_sh_source = 
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main() {\n"
"    FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"\
"}\n";


// -----------------------------------------------
//  Quad
// -----------------------------------------------

void opengl_quad_init(void);
void opengl_quad_free(void);

#endif
