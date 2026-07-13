#include "wet.h"
#include "wet/log.h"
#include "wet/window.h"
#include "wet/time.h"
#include "wet/graphics.h"

int main()
{
    WindowConfig config = {690, 690, "janela teste", false};
    if (window_create(config) == false) { LOG_ERROR("falha na janela!"); }

    time_init();
    fps_set_target(60);

    if (!graphics_init(WET_GRAPHICS_API_OPENGL)) { return -1; }

    Color bg_color = {76, 100, 140, 255};

    while (!window_should_close())
    {
        time_update();
        window_update();

        LOG_CLEAN();

        LOG_INFO(" - WETLIB - \n\n");

        LOG_INFO("delta time: %f", DELTA_TIME);
        LOG_INFO("FPS: %d", fps_get());
        LOG_INFO("FPS REAL: %d", fps_real_get());
        
        graphics_clear_screen(bg_color);
    }

    time_shut();
    graphics_shut();
    window_destroy();

    LOG_INFO("Jogo finalizado com sucesso!");
}
