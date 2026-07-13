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


