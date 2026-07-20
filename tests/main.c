#include "wet.h"
#include "wet/log.h"
#include "wet/window.h"
#include "wet/draw.h"
#include "wet/time.h"
#include "wet/render.h"

int main()
{
    WindowConfig config = {690, 690, "janela teste", false};
    if (window_create(config) == false) { LOG_ERROR("falha na janela!"); }

    fps_set_target(60);

    if (!renderer_init(WET_GRAPHICS_API_OPENGL)) { return -1; }

    while (!window_should_close())
    {
        window_update();
        draw_clear(make_color_rgb(200, 140, 140));
    }

    renderer_shut();
    window_destroy();

    LOG_INFO("Jogo finalizado com sucesso!");
}
