#include <glad/glad.h>

#include "wet.h"
#include "opengl.h"

void opengl_draw_clear(Color color)
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
