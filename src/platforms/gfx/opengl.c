#include <glad/glad.h>

#include "wet.h"
#include "wet/log.h"

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
        return true;

    #elif defined(WET_PLATFORM_LINUX)
        LOG_FATAL("CONEXÃO COM A JANELA DO LINUX AINDA NÃO IMPLEMENTADA");
        return false;
    #elif defined (WET_PLATFORM_MACOS)
        LOG_FATAL("CONEXÃO COM A JANELA DO MACOS AINDA NÃO IMPLEMENTADA");
        return false;
    #endif

    
}

void opengl_clear_screen(Color color)
{
    float32 r = (float32)color.r / 255.0f;
    float32 g = (float32)color.g / 255.0f;
    float32 b = (float32)color.b / 255.0f;
    float32 a = (float32)color.a / 255.0f;

    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


// ----------------------------------------------------------------------
//                              Shaders
// ----------------------------------------------------------------------

// -----------------------------------------------
//  OpenGL Renderer
// -----------------------------------------------

typedef struct {
    uint32 default_shader_program;
} OpenGLRenderer;

static OpenGLRenderer open_gl_renderer = { 0 };

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
//  Funções auxiliares
// -----------------------------------------------

// Essa função basicamente compila os shaders na GPU
static uint32 compile_shader(uint32 type, const char* source)
{
    // Compilando o shaders
    {
        unit32 id = glCreateShader(type);       // Criando ele na GPU
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