
#include <glad/glad.h>

#include "wet.h"
#include "opengl.h"

// -----------------------------------------------
//  Quad
// -----------------------------------------------

// Inicializando o quad
void opengl_quad_init(void)
{
    // Vertices do quad
    Vertex vertices[] =
    {
        //      POSIÇÃO       |           COR            |       UV      |      NORMAL
        {{-1.0f, -1.0f, 0.0f},  {1.0f, 1.0f, 1.0f, 1.0f},   {0.0f, 0.0f},  {0.0f, 0.0f, 1.0f}},
        {{ 1.0f, -1.0f, 0.0f},  {1.0f, 1.0f, 1.0f, 1.0f},   {1.0f, 0.0f},  {0.0f, 0.0f, 1.0f}},
        {{-1.0f,  1.0f, 0.0f},  {1.0f, 1.0f, 1.0f, 1.0f},   {0.0f, 1.0f},  {0.0f, 0.0f, 1.0f}},
        {{ 1.0f,  1.0f, 0.0f},  {1.0f, 1.0f, 1.0f, 1.0f},   {1.0f, 1.0f},  {0.0f, 0.0f, 1.0f}}
    };

    // Indices
    uint8 indices[] =
    {
        0, 1, 3,
        0, 2, 3
    }

    // Criando e dando bind no Vertex Array
    glGenVertexArrays(1, &open_gl_renderer.quad_vao);
    glBindVertexArray(open_gl_renderer.quad_vao);
    
    // Criando o Vertex Buffer na GPU
    glGenBuffers(1, &open_gl_renderer.quad_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, open_gl_renderer.quad_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Mandando os indices do Element Array Buffer pra GPU
    glGenBuffers(1, &open_gl_renderer.quad_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, open_gl_renderer.quad_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Atributos do vertex
    vertex_config_attributes(void)

    // Desconectando do Vertex Array
    glBindVertexArray(0);
}

// Liberando o quad da memória
void opengl_quad_free(void)
{
    // Deletando o Quad
    glDeleteVertexArrays(1, &open_gl_renderer.quad_vao);
    glDeleteBuffers(1, &open_gl_renderer.quad_vbo);
    glDeleteBuffers(1, &open_gl_renderer.quad_ebo);
}