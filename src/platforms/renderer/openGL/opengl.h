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
static const char* default_vertex_sh_source = "#version 330 core\nlayout (location = 0) in vec3 aPos;\nvoid main() {\n    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n}\n";
static const char* default_fragment_sh_source = "#version 330 core\nout vec4 FragColor;\nvoid main() {\n    FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n}\n";


// -----------------------------------------------
//  Quad
// -----------------------------------------------

void opengl_quad_init(void);
void opengl_quad_free(void);

#endif
