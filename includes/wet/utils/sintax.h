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
// *        Esse arquivo contém facilitadores gerais de sintaxe,
// *    por exemplo, tipos, convenções e etc.
// *    
// *        - GLOSSÁRIO:
// *    
// *    TODO: fazer o glossário
// *    
// *    
// * -----------------------------------------------------------------
// *

///////////////////////////////////////////////////////////////////////////////////////

#ifndef WET_SINTAX
#define WET_SINTAX

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////////////

// -------------- REDEFININDO NOMES --------------

// Signed
typedef int8_t   int8;
typedef int16_t  int16;
typedef int32_t  int32;
typedef int64_t  int64;
typedef float    float32;
typedef double   float64;

// Unsigned
typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

// -------------- SINTAXE DE COMPARADORES --------------

#define is ==
#define isnt !=
#define not !
#define and &&
#define or ||


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
