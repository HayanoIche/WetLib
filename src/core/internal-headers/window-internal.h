
#include "wet.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// --------------------------- JANELA ---------------------------

bool window_create(void);
void window_update(void);
void window_destroy(void);

bool window_should_close(void);

#if defined(WET_PLATFORM_WINDOWS)
    bool win32_opengl_graphics_init(void);
    void* win32_opengl_get_proc_address(const char* procname);
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// --------------------------- TEMPO ---------------------------

bool time_init(void);
void time_update(void);
void time_shut(void);
