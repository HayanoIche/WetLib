#include "wet.h"
#include "wet/log.h"
#include "wet/window.h"
#include "wet/graphics.h"

int main()
{
    LOG_INFO("Log funcionando!");

    WindowConfig config = {690, 690, "janela teste", false};

    if (window_create(config) == false)
    {
        LOG_ERROR("falha na janela!");
    }

    if (!graphics_init(WET_GRAPHICS_API_OPENGL))
    {
        return -1;
    }

    while (!window_should_close())
    {
        window_update();
        Color cor = {76, 100, 140, 255};
        //Color cor = {255, 0, 0, 255};
        graphics_clear_screen(cor);
    }

    window_destroy();
    graphics_shut();
    LOG_INFO("Jogo finalizado com sucesso!");
}
