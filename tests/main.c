#include "wet.h"
#include "wet/log.h"
#include "wet/window.h"

int main()
{
    LOG_INFO("Log funcionando!");

    WindowConfig config = {690, 690, "janela teste", false};

    if (window_create(config) == false)
    {
        LOG_ERROR("falha na janela!");
    }

    while (!window_should_close())
    {
        window_update();
    }

    window_destroy();
    LOG_INFO("Jogo finalizado com sucesso!");
}
