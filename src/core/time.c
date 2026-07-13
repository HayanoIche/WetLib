#include "wet.h"
#include "wet/log.h"
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


// ----------------------------------------------------------------------
//  Implementação das funções de tempo
// ----------------------------------------------------------------------


// Ciclo de vida
// Iniciando o contador de tempo
void time_init(void)
{
    #if defined(WET_PLATFORM_WINDOWS)
        //
        //      Essa função do <mmsystem.h> serve pra dar mais
        //  precisão pro sleep (precisão de 1 milissegundo)
        //
        timeBeginPeriod(1);

    #endif
        time_manager.last_progress_time = get_time_in_seconds();
}


// Finalizando o contador de tempo
void time_shut(void)
{
    #if defined(WET_PLATFORM_WINDOWS)
        // Desliga aquela alta precisão do sleep ao fechar o programa
        timeEndPeriod(1);
    #endif
}


// Da o update de cada frame
void time_update(void)
{
    float64 current_time = get_time_in_seconds();

    // Processamento do frame passado
    if (time_manager.start_time != 0.0) // Pra ignorar se for o primeiro frame (n existe frame passado)
    {
        // Pegando quantos segundos a CPU e a GPU gastaram executando o frame anterior
        float64 cpu_time = current_time - time_manager.start_time;

        // Impedindo a divisão por zero se o tempo gasto for perto de 0
        if (cpu_time < 0.00001) { cpu_time = 0.00001; }

        time_manager.fps_real_sum += (1.0 / cpu_time);
        time_manager.frame_count++;

        if (cpu_time < time_manager.target_time)
        {
            float64 time_to_wait = time_manager.target_time - cpu_time;
            
            wait_time(time_to_wait);
            
            current_time = get_time_in_seconds(); 
        }
    }

    // Processamento desse frame
    time_manager.start_time = current_time;
    
    // Calculo do DELTA TIME
    if (time_manager.previous_time == 0.0)
    {
        time_manager.delta_time = 0.0;
    } else {
        time_manager.delta_time = time_manager.start_time - time_manager.previous_time;
    }

    time_manager.previous_time = time_manager.start_time;

    if (current_time - time_manager.last_progress_time >= 1.0)
    {
        time_manager.fps = time_manager.frame_count;
        time_manager.fps_real = (uint16) (time_manager.fps_real_sum / time_manager.frame_count);
        
        time_manager.frame_count = 0;
        time_manager.fps_real_sum = 0.0;
        time_manager.last_progress_time = current_time;
    }
}


// Funções pra pegar os parametros do time manager

// Função pra settar o FPS máximo que o programa pode ter (o fps alvo)
void fps_set_target(uint16 fps)
{
    if (fps <= 0)
    {
        time_manager.target_time = 0.0;
        LOG_WARN(" O fps foi settado pra 0");
    }
    else
    {
        time_manager.target_time = 1.0 / (float64)fps;
    }
}


// Função que pega qual o FPS alvo atual
uint16 fps_get_target(void) { return time_manager.target_time; }

// Função que pega qual o FPS atual do programa
uint16 fps_get(void) { return time_manager.fps; }

// Função que pega qual o FPS que a janela poderia ter sem o limitador
uint16 fps_real_get(void) { return time_manager.fps_real; }

// Função que pega o delta time
float64 delta_time_get(void) { return time_manager.delta_time; }

