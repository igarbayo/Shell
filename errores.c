#include <stdio.h>
#include "interprete.h"

// ERRORES LÉXICOS //////////////////////////////////

void lanzar_error(char* string) {
    printf(ROJO "\tError: %s\n" RESET, string);
}