////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
//  Arquivo pertencente de um sub-header da WetLib
//  feito por Hayano
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef WET_GRAPHICS_H
#define WET_GRAPHICS_H

#include "wet.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
* @brief Começa o sistema de gráficos
*
* Essa função serve pra começar o sistema de gráficos
* criando automáticamente uma janelas (se preciso) e
* faz o setup da api de gráficos
*
* @return Se a função teve sucesso ao iniciar o sistema de gráficos
*
* @details
* Antes dessa função devem ser usada funções como window_set_size()
* para iniciar a janela com as configurações desejadas
*
* No final do programa deve ser chamado o graphics shut para
* terminar o que essa função começou
**/

bool graphics_init(void);


/**
* @brief Atualiza os gráficos
*
* Essa função atualiza a janela e o contexto da api de gráficos
*
* @details
* 
**/


void graphics_update(void);
void graphics_shut(void);
bool graphics_is_running(void);

bool graphics_change_api(GraphicsAPI api);


#endif
