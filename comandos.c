//
// Created by ignacio on 24/03/25.
//

#include <stdio.h>

#include "comandos.h"
#include "flex.yy.h"
#include "bison.tab.h"
#include "errores.h"
#include "tabla_simbolos.h"

double cargar(char *archivo) {
    yyin = fopen(archivo, "r");

    if (yyin == NULL) {
        lanzar_error("FICHEIRO_NON_ATOPADO");
        yyin = stdin;
    } else {
        //ejecutar_script(1);
    }

    return 0;
}