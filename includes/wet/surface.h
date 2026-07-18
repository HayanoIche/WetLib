
#include "wet.h"
#include "wet/log.h"

// Struct da surface
typedef struct Surface Surface;

// Funções públicas
Surface* surface_create(int32 width, int32 height);
void surface_destroy(Surface* surface);

void surface_set_target(Surface* surface);