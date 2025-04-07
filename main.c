#include <stdio.h>
#include "tabla_simbolos.h"
#include "interprete.h"
#include "errores.h"
#include "comandos.h"
#include <stdbool.h>


int main(int argc, char **argv) {

    // 1. Inicialización de estructuras de datos
    crear_tabla();

    // 2. Etapa de compilación (análisis léxico)
    if (argc == 1) {
        interprete(NULL);
    } else if (argc == 2) {
        interprete(argv[1]);
    } else {
        lanzar_error("Número de parámetros");
    }

    // 3. Fase de finalización
    quit();

    return 0;
}
