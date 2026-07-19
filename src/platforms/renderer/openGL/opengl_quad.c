
#include "wet.h"

#include "opengl.h"

// -----------------------------------------------
//  Quad
// -----------------------------------------------

// Inicializando o quad
void opengl_init_quad(void)
{
    float32 vertices[] =
    {
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    uint32 indices[] =
    {
        0, 1, 3,
        1, 2, 3
    };
    
    // Criando o VAO, VBO, e EBO na gpu
    glGenVertexArrays(1, &open_gl_renderer.quad_vao);
    glGenBuffers(1, &open_gl_renderer.quad_vbo);
    glGenBuffers(1, &open_gl_renderer.quad_ebo);

    // Conectando ao VAO
    glBindVertexArray(open_gl_renderer.quad_vao);

    // Iniciando o VAO
    {
        // Configurando o VBO
        // Basicamente enviando os vértices para a GPU
        glBindBuffer(GL_ARRAY_BUFFER, open_gl_renderer.quad_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Configurando o EBO
        // Basicamente enviando os índices de conexão dos triângulos para a GPU
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, open_gl_renderer.quad_ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // O Ponteiro de Atributos
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0); // Ativa o atributo da posição 0
    }
    
    // Desconectando do VAO
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