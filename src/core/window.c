#include "wet.h"
#include "wet/window.h"

// ----------------------------------------------------------------------
//  Declarando as funções específicas de plataforma
// ----------------------------------------------------------------------

#if defined(WET_PLATFORM_WINDOWS)
    // Funções do ciclo de vida
    bool win32_window_create(WindowConfig config);
    void win32_window_update(void);
    void win32_window_destroy(void);

    bool win32_window_should_close(void);

#elif defined(WET_PLATFORM_LINUX)
    // Funções de janela implementadas pro linux
#elif defined(WET_PLATFORM_MACOS)
    // Funções de janela implementadas pro MacOs
#endif

// ----------------------------------------------------------------------
//  Implementando as funções gerais de ponteiro
// ----------------------------------------------------------------------

// Ciclo de vida da janela
// Função que cria a janela
bool window_create(WindowConfig config)
{
    #if defined(WET_PLATFORM_WINDOWS)
        return win32_window_create(config);
    #elif defined(WET_PLATFORM_LINUX)
        // Função do Linux
    #elif defined(WET_PLATFORM_MACOS)
        // Função do MacOs
    #else
        return false;
    #endif
}


// Função que atualiza ela (eventos e afins)
void window_update(void)
{
    #if defined(WET_PLATFORM_WINDOWS)
        return win32_window_update();
    #elif defined(WET_PLATFORM_LINUX)
        // Função do Linux
    #elif defined(WET_PLATFORM_MACOS)
        // Função do MacOs
    #endif
}


// Função que destroi a janela
void window_destroy(void)
{
    #if defined(WET_PLATFORM_WINDOWS)
        return win32_window_destroy();
    #elif defined(WET_PLATFORM_LINUX)
        // Função do Linux
    #elif defined(WET_PLATFORM_MACOS)
        // Função do MacOs
    #endif
}


// Função que diz se a janela precisa fechar
bool window_should_close(void)
{
    #if defined(WET_PLATFORM_WINDOWS)
        return win32_window_should_close();
    #elif defined(WET_PLATFORM_LINUX)
        // Função do Linux
    #elif defined(WET_PLATFORM_MACOS)
        // Função do MacOs
    #else
        return true;
    #endif
}


