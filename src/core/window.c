#include "wet.h"
#include "wet/window.h"

#if defined(WET_PLATFORM_WINDOWS)
    // ----------------------------------------------------------------------
    //      Declaração das funções específicas da plataforma
    // ----------------------------------------------------------------------

    // Ciclo de vida da janela
    bool win32_window_create(WindowConfig config);
    void win32_window_update(void);
    void win32_window_destroy(void);

    bool win32_window_should_close(void);
    
    // Posição e tamanho
    void win32_window_set_x(uint16 x);
    void win32_window_set_y(uint16 y);
    void win32_window_set_width(uint16 width);
    void win32_window_set_height(uint16 height);

    uint16 win32_window_get_x();
    uint16 win32_window_get_y();
    uint16 win32_window_get_width();
    uint16 win32_window_get_height();

    // ----------------------------------------------------------------------
    //  Implementando as funções gerais de ponteiro
    // ----------------------------------------------------------------------

    // Ciclo de vida da janela
    bool window_create(WindowConfig config) {   return win32_window_create(config); }
    void window_update(void)                {   return win32_window_update();       }
    void window_destroy(void)               {   return win32_window_destroy();      }

    bool window_should_close(void)          {   return win32_window_should_close(); }
    
    // Posição e tamanho
    void window_set_x(uint16 x)             {   return win32_window_set_x(x);       }
    void window_set_y(uint16 y)             {   return win32_window_set_y(y);       }
    void window_set_width(uint16 width)     {   return win32_window_set_width(width); }
    void window_set_height(uint16 height)   {   return win32_window_set_height(height); }

    uint16 window_get_x()                   {   return win32_window_get_x();        }
    uint16 window_get_y()                   {   return win32_window_get_y();        }
    uint16 window_get_width()               {   return win32_window_get_width();    }
    uint16 window_get_height()              {   return win32_window_get_height();   }

#elif defined(WET_PLATFORM_LINUX)

    // Funções do Linux

#elif defined(WET_PLATFORM_MACOS)

    // Funções do MacOs

#endif








