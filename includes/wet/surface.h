
#include "wet.h"
#include "wet/log.h"

// ** adicionar aqui no futuro comentários explicando que
// é o conceito das surfaces e cameras e como funcionam e como usar

// Funções públicas

//
//  A forma de gerenciar as surfaces basicamente é:
//  
//      Criar elas com nomes únicos e colocar em um banco
//  de dados, pra quando outras funções forem usar surfaces
//  não precisarem lidar com ponteiros de surface só precisando
//  chamar a função com o nome
//

// Cria uma surface
bool surface_create(const char* surface_name, uint32 width, uint32 height);

// Destroi uma surface específica
void surface_destroy(const char* surface_name);
// Destroi todas as surfaces
void surface_destroy_all(const char* surface_name);

// Seta a surface escolhida pra ser a surface que vai ser desenhada no momento
void surface_set_target(const char* surface_name);
