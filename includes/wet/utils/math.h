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
// *        Esse arquivo contém implementações de funções e
// *    definições relacionadas a matemática.
// *    
// *    *** IMPLEMENTAÇÃO DE FUNÇÕES NO "math.c"
// *    
// *        - GLOSSÁRIO:
// *    
// *    TODO: fazer o glossário
// *    
// *    
// * -----------------------------------------------------------------
// *

///////////////////////////////////////////////////////////////////////////////////////

#ifndef WET_MATH
#define WET_MATH

#include <math.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pi
#define PI 3.14159265358979323846

// Funções com angulos
double dcos(double angle);
double dsin(double angle);
double dtan(double angle);

float format_angle(float angle);
float rotate_towards(float angle, float target, float amount);

// Clamp
#define clamp(value, lowest, highest) (((value) < (lowest)) ? (lowest) : (((value) > (highest)) ? (highest) : (value)))


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
