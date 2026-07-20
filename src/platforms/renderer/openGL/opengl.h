#ifndef WET_OPENGL
#define WET_OPENGL

#include "wet.h"

// Struct que cuida das variáveis do renderer openGL
typedef struct {
    uint32 default_shader_program;

    // Quad
    uint32 quad_vao;
    uint32 quad_vbo;
    uint32 quad_ebo;

    bool started;

} OpenGLRenderer;

extern OpenGLRenderer open_gl_renderer;

// -----------------------------------------------
//  Funções da vida do openGL
// -----------------------------------------------

bool opengl_init(void);
void opengl_shut(void);
bool opengl_functions_load(void);

// -----------------------------------------------
//  Funções de desenho do opengl
// -----------------------------------------------

void opengl_draw_clear(Color color);


// -----------------------------------------------
//  Shaders
// -----------------------------------------------

uint32 opengl_shader_create_program(const char* vertex_src, const char* fragment_src);

// Vertex e Fragment shader padrão
static const char* default_vertex_sh_source = "#version 330 core\nlayout (location = 0) in vec3 aPos;\nvoid main() {\n    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n}\n";
static const char* default_fragment_sh_source = "#version 330 core\nout vec4 FragColor;\nvoid main() {\n    FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n}\n";


// -----------------------------------------------
//  Quad
// -----------------------------------------------

void opengl_quad_init(void);
void opengl_quad_free(void);

#endif
