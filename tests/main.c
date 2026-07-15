#include "wet.h"
#include "wet/log.h"
#include "wet/window.h"
#include "wet/time.h"
#include "wet/graphics.h"

int main()
{
    WindowConfig config = {690, 690, "janela teste", false};
    if (window_create(config) == false) { LOG_ERROR("falha na janela!"); }

    fps_set_target(60);

    if (!graphics_init(WET_GRAPHICS_API_OPENGL)) { return -1; }

    while (!window_should_close())
    {
        window_update();
        graphics_clear_screen(make_color_rgb(0, 100, 140));
    }

    graphics_shut();
    window_destroy();

    LOG_INFO("Jogo finalizado com sucesso!");
}
