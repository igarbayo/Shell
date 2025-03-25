//
// Created by ignacio on 24/03/25.
//

#include <stdio.h>
#include <stdbool.h>
#include "comandos.h"
#include "flex.yy.h"
#include "bison.tab.h"
#include "errores.h"
#include "tabla_simbolos.h"


bool variableEcho = true;


double load(char *archivo) {
    yyin = fopen(archivo, "r");

    if (yyin == NULL) {
        lanzar_error("FICHEIRO_NON_ATOPADO");
        yyin = stdin;
    } else {
        ejecutar_script(1);
    }

    return 0;
}

double quit() {
    return 0;
}

double help() {
    return 0;
}

double workspace() {
    return 0;
}

double clear() {
    return 0;
}

double clean() {
    return 0;
}

double echo() {
    variableEcho = !variableEcho;   // ver si funciona
    // cambiar echo
    return 0;
}

double import(char* libreria) {
    return 0;
}