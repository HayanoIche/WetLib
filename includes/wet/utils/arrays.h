// *
// * -----------------------------------------------------------------
// *
// *                        - WET LIB -
// *
// *        Projeto de biblioteca de utilidades gerais em C
// *    feita por Igor Hayano, principalmente de forma recreativa,
// *    mas com o objetivo também de tornar o uso de C mais "fácil"
// *
// * -----------------------------------------------------------------
// *
// *        Esse arquivo contém uma implementação de arrays
// *    dinamicos e algumas funções pro uso deles também.
// *    
// *        - GLOSSÁRIO:
// *    
// *    STRUCTS:
// *    Numbers: array dinamico pra inteiros
// *    
// *    FUNÇÕES:
// *    Type array_init(Type): inicia todos os arrays
// *    void array_free(array): libera a memória alocada nos arrays
// *    void array_append(array, item): adiciona um item no fim do array
// *    
// *    
// * -----------------------------------------------------------------
// *

///////////////////////////////////////////////////////////////////////////////////////

#ifndef WET_ARRAYS
#define WET_ARRAYS

#include "sintax.h"

///////////////////////////////////////////////////////////////////////////////////////

typedef struct {
    int *items;
    size_t size;
    size_t capacity;
} Numbers;


#define array_init(type) ( (type) { NULL, 0, 0 } )


#define array_free(array)           \
    do {                            \
        if ((array).items) {        \
            free((array).items);    \
            (array).items = NULL;   \
        }                           \
        (array).size = 0;           \
        (array).capacity = 0;       \
    } while (0)


#define array_append(array, item)                                   \
    do {                                                            \
        if (array.size >= array.capacity)                           \
        {                                                           \
            size_t new_capacity;                                    \
                                                                    \
            if (array.capacity == 0) {                              \
                new_capacity = 32;                                  \
            } else {                                                \
                new_capacity = array.capacity * 2;                  \
            };                                                      \
                                                                    \
            void *tmp = realloc(                                    \
                array.items,                                        \
                new_capacity * sizeof(*array.items)                 \
            );                                                      \
                                                                    \
            if (tmp != NULL) {                                      \
                array.items = tmp;                                  \
                array.capacity = new_capacity;                      \
            } else {                                                \
                break;                                              \
            }                                                       \
        }                                                           \
        array.items[n.size++] = item;                               \
    } while(0)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
