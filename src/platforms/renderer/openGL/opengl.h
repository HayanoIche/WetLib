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
//  Vertex
// -----------------------------------------------

typedef struct {
    float32 Position[3];   // X, Y, Z
    float32 Color[4];      // RGBA
    float32 TexCoords[2];  // U, V
    float32 Normal[3];     // Normals para iluminação
} Vertex;

void vertex_config_attributes(void);


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

uint32 opengl_shader_create(const char* vertex_src, const char* fragment_src);

// Vertex e Fragment shader padrão
static const char* default_vertex_sh_source =
"#version 330 core\n"
"\n"
"layout (location = 0) in vec4 position;\n"
"\n"
"void main()\n"
"{\n"
"    gl_Position = position;\n"
"}\n";

static const char* default_fragment_sh_source =
"#version 330 core\n"
"\n"
"layout(location = 0) out vec4 color;\n"
"uniform vec4 u_Color;"
"\n"
"void main()\n"
"{\n"
"    color = u_Color;\n"
"}\n";


// -----------------------------------------------
//  Quad
// -----------------------------------------------

void opengl_quad_init(void);
void opengl_quad_free(void);

// -----------------------------------------------
//  Surfaces
// -----------------------------------------------

bool opengl_surface_create(const char* name, uint32 width, uint32 height);
void opengl_surface_destroy(const char* name);
void opengl_surface_destroy_all(void);
void opengl_surface_set_target(const char* name);

#endif
