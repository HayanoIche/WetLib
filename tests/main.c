#include "wet.h"
#include "wet/log.h"
#include "wet/window.h"
#include "wet/graphics.h"

int main()
{
    window_set_caption("Jogo");
    window_set_size((Vec2){640, 480});
    fps_set_target(60);
    
    graphics_init();

    while (graphics_is_running())
    {
        graphics_update();
    }

    graphics_shut();

    /*
    WindowConfig config = {690, 690, "janela teste", false};
    if (window_create(config) == false) { LOG_ERROR("falha na janela!"); }

    fps_set_target(60);
    
    if (!renderer_init(WET_GRAPHICS_API_OPENGL)) { return -1; }

    surface_create("surface 1", 500, 500);

    while (!window_should_close())
    {
        window_update();
        surface_set_target("surface 1");
        draw_clear(make_color_rgb(200, 140, 140));
    }

    surface_destroy_all();

    renderer_shut();
    window_destroy();

    LOG_INFO("Jogo finalizado com sucesso!");
    */
}
