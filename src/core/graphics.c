#include "wet.h"
#include "wet/graphics.h"
#include "wet/log.h"

// ----------------------------------------------------------------------
//  Declarando as funções específicas de plataforma
// ----------------------------------------------------------------------

#if defined(WET_PLATFORM_WINDOWS)

    //OpenGL
    {
        // Funções do ciclo de vida
        bool win32_opengl_graphics_init();
        bool win32_opengl_graphics_shut();

        // Função de carregamento das funções
        void* win32_opengl_get_proc_address(const char* procname);
    }

    // Funções do vulkan e directx

#elif defined(WET_PLATFORM_LINUX)
    // Funções de gráfico implementadas pro linux
#elif defined(WET_PLATFORM_MACOS)
    // Funções de gráfico implementadas pro MacOs
#endif


// ----------------------------------------------------------------------
//  Implementando as funções gerais de ponteiro
// ----------------------------------------------------------------------

// Funções do ciclo de vida
bool graphics_init(GraphicsAPI api)
{
    switch(api)
    {
        case WET_GRAPHICS_API_OPENGL:
            return win32_opengl_graphics_init();
            break;
        
        case WET_GRAPHICS_API_VULKAN:
            return false;
            break;

        case WET_GRAPHICS_API_DIRECTX:
            #if defined(WET_PLATFORM_WINDOWS)
                // Retornar a função do directX
                return false;
            #else
                LOG_FATAL("A API DE GRÁFICOS DIRECTX NÃO ESTÁ DISPONÍVEL NESSE SISTEMA OPERACIONAL");
            #endif
            break;
    }
}

void graphics_shut(void) {};
bool graphics_change_api(GraphicsAPI api) {return false};
