//
// Created by ignacio on 24/03/25.
//

#include "stdio.h"
#include "interprete.h"
#include "flex.yy.h"
#include "bison.tab.h"
#include "comandos.h"

void interprete(char* arg) {
    printf("Bienvenido.\n");

    if (arg != NULL) {
        load(arg);
    }

    yyparse();
}
