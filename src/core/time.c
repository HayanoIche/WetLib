#include "wet.h"
#include "wet/time.h"

#if defined(WET_PLATFORM_WINDOWS)
    #include <windows.h>
    #include <mmsystem.h>
#else
    #include <time.h>
    #include <unistd.h>
#endif

// ----------------------------------------------------------------------
//  Time Manager
// ----------------------------------------------------------------------

typedef struct {
    float64 target_time;
    float64 start_time;
    float64 previous_time;
    float64 delta_time;

    float64 fps_real_sum;
    float64 last_progress_time;

    uint16 fps;
    uint16 fps_real;
    uint16 frame_count;
} TimeManager;

static TimeManager time_manager = { 0 };

// ----------------------------------------------------------------------
//  Funções Auxiliares
// ----------------------------------------------------------------------

//
//    Essa função retorna o tempo total de segundos
//  a partir de um momento mágico (Ex.: quando o pc ligou)
//
//      Ela serve basicamente para só medir intervalos
//  de tempo, ai ela se baseia a partir desse momento mágico
//
// - Hayano
//

static float64 get_time_in_seconds(void)
{
    #if defined(WET_PLATFORM_WINDOWS)
        static LARGE_INTEGER frequency; // Tipo da propria microsoft (mas é basicamente um int64)
        static bool has_quad = false;

        if (!has_quad) // Para só calcular a frequência uma vez
        {
            QueryPerformanceFrequency(&frequency);
            has_quad = true;
        }
        
        LARGE_INTEGER counter;
        QueryPerformanceCounter(&counter);
        return (float64)counter.QuadPart / (float64)frequency.QuadPart;

    #else // No macos ou no linux
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return (float64)ts.tv_sec + (float64)ts.tv_nsec / 1000000000.0;
        
    #endif
}

//
//      Função que serve para "dormir" o programa,
//  pra economizar os frames "a mais" que o processador
//  consegue calcular mas não precisa.
//  
//    Se deixar o programa sem limitar os frames por
//  segundo ele pega o máximo da cpu possível pra
//  rodar o máximo de loops possível
//
//  (meu pc faz um barulho estranho quando isso ocorre inclusive)
//
//  - Hayano
//

static void wait_time(double seconds)
{
    if (seconds <= 0.0) return;

    #if defined(WET_PLATFORM_WINDOWS)
        Sleep((DWORD)(seconds * 1000.0)); // Dormir no windows
    #else
        usleep((useconds_t)(seconds * 1000000.0));  // Dormir no linux/macos
    #endif
}

