
#include "wet.h"
#include "wet/log.h"

#include "opengl.h"

// ----------------------------------------------------------------------
//                              Shaders
// ----------------------------------------------------------------------

// -----------------------------------------------
//  Funções auxiliares
// -----------------------------------------------

// Essa função basicamente compila os shaders na GPU
static uint32 compile_shader(uint32 type, const char* source)
{
    uint32 id = glCreateShader(type);       // Criando ele na GPU

    // Compilando o shaders
    {
        glShaderSource(id, 1, &source, NULL);   // Embutindo a string do shaders dentro do shader da GPU
        glCompileShader(id);                    // Compila o shader em si
    }

    // Checando se ouve algum erro na compilação do shader
    {
        int32 result;

        //  nota:
        //  glGetShaderiv()
        //  
        //      Essa função funciona buscando informações internas do shader
        //  nesse caso o parametro de COMPILE STATUS responde se ele ta compilado
        //  certinho (GL_TRUE) ou não (GL_FALSE)
        //
        //  - Hayano
        //

        glGetShaderiv(id, GL_COMPILE_STATUS, &result);

        if (result==GL_FALSE)
        {
            // Pegando a mensagem de erro
            int length;
            char message[512];

            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            glGetShaderInfoLog(id, length, &length, message);

            LOG_ERROR("[OPEN GL] Falha ao compilar um shader...\n%s\n", message);

            glDeleteShader(id);
            return 0;
        }
        else
        {
            LOG_INFO("[OPEN GL] Shader compilado com sucesso!");
        }
    }

    // Retornando o shaders
    return id;
}

// Função secreta deste arquivo para linkar os shaders
static uint32 opengl_create_shader_program(const char* vertex_src, const char* fragment_src)
{
    uint32 program = glCreateProgram();
    uint32 vs = compile_shader(GL_VERTEX_SHADER, vertex_src);
    uint32 fs = compile_shader(GL_FRAGMENT_SHADER, fragment_src);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

