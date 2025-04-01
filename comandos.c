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
#include "interprete.h"


bool variableEcho = true;

void _ayuda_general() {
    printf(AMARILLO"Bienvenido al intérprete de comandos tipo shell.\n\n"RESET);

    printf(AMARILLO"Este intérprete forma parte de la asignatura de Compiladores e Intérpretes en el Grado en Ingeniería Informática.\n"RESET);
    printf(AMARILLO"Proporciona un entorno interactivo similar a las consolas de R, Python o Matlab.\n\n"RESET);

    printf(AMARILLO"Para más información, consulte la documentación del proyecto.\n"RESET);
}


/// FUNCIONES PÚBLICAS

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
    printf(AMARILLO"Saliendo del intérprete..."RESET"\n\n");
    eliminar_tabla();
    //yylex()_destroy();
    exit(EXIT_SUCCESS);
}

double help(char* lexema) {
    if (lexema == NULL) {
        printf(AMARILLO"\n---------------------------------------------\n"RESET);
        _ayuda_general();
        printf(AMARILLO"---------------------------------------------\n\n"RESET);
    } else {
        int r1 = strcmp(lexema, "load");
        int r2 = strcmp(lexema, "quit");
        int r3 = strcmp(lexema, "help");
        int r3b = strcmp(lexema, "?");
        int r4 = strcmp(lexema, "workspace");
        int r5 = strcmp(lexema, "clear");
        int r6 = strcmp(lexema, "clean");
        int r7 = strcmp(lexema, "echo");

        if (r1 == 0) {
            printf(AMARILLO"\n---------------------------------------------\n"RESET);
            printf(AMARILLO"El comando load(FILE) ejecuta un script de sentencias en el intérprete.\n"RESET);
            printf(AMARILLO"---------------------------------------------\n\n"RESET);
        } else if (r2 == 0) {
            printf(AMARILLO"\n---------------------------------------------\n"RESET);
            printf(AMARILLO"El comando quit o quit() cierra el intérprete.\n"RESET);
            printf(AMARILLO"---------------------------------------------\n\n"RESET);
        } else if (r3 == 0 || r3b == 0) {
            printf(AMARILLO"\n---------------------------------------------\n"RESET);
            printf(AMARILLO"El comando help, help() o help(COMANDO) muestra la ayuda sobre el intérprete o una de sus funcionalidades.\n"RESET);
            printf(AMARILLO"---------------------------------------------\n\n"RESET);
        } else if (r4 == 0) {
            printf(AMARILLO"\n---------------------------------------------\n"RESET);
            printf(AMARILLO"El comando workspace o workspace() muestra la lista de variables almacenadas con sus valores..\n"RESET);
            printf(AMARILLO"---------------------------------------------\n\n"RESET);
        } else if (r5 == 0) {
            printf(AMARILLO"\n---------------------------------------------\n"RESET);
            printf(AMARILLO"El comando clear, clear() o clear(VAR) borra el workspace o alguna de las variables.\n"RESET);
            printf(AMARILLO"---------------------------------------------\n\n"RESET);
        } else if (r6 == 0) {
            printf(AMARILLO"\n---------------------------------------------\n"RESET);
            printf(AMARILLO"El comando clean o clean() limpia la pantalla del intérprete.\n"RESET);
            printf(AMARILLO"---------------------------------------------\n\n"RESET);
        } else if (r7 == 0) {
            printf(AMARILLO"\n---------------------------------------------\n"RESET);
            printf(AMARILLO"El comando echo o echo() muestra la forma de impresión del autómata, a saber:\n"RESET);
            printf(AMARILLO"\t\ton: si una sentencia no acaba en ; se imprime su valor asociado.\n"RESET);
            printf(AMARILLO"\t\toff: nunca se imprime el valor asociado a una sentencia.\n"RESET);
            printf(AMARILLO"Con echo(on)/echo(off) activamos/desactivamos este comportamiento.\n"RESET);
            printf(AMARILLO"---------------------------------------------\n\n"RESET);
        } else {
            printf(AMARILLO"\n---------------------------------------------\n"RESET);
            _ayuda_general();
            printf(AMARILLO"---------------------------------------------\n\n"RESET);
        }

    }

    return 0;
}

double workspace() {
    imprimir_variables();
    return 0;
}

double clear(char* lexema) {
    if (lexema == NULL) {
        eliminar_todas_variables();
    } else {
        eliminar_variable(lexema);
    }
    return 0;
}

double clean() {
    return 0;
}

double echo(char* lexema) {
    if (lexema == NULL) {
        printf(AMARILLO"%s\n\n"RESET, variableEcho ? "on" : "off");
        return 0;
    } else {
        int r1 = strcmp(lexema, "on");
        int r2 = strcmp(lexema, "off");

        if (r1 == 0) {
            variableEcho = true;
            printf(AMARILLO"Cambiado: %s\n\n"RESET, variableEcho ? "on" : "off");
            return 1;
        } else if (r2 == 0) {
            variableEcho = false;
            printf(AMARILLO"Cambiado: %s\n\n"RESET, variableEcho ? "on" : "off");
            return 2;
        } else {
            printf(AMARILLO"%s\n\n"RESET, variableEcho ? "on" : "off");
        }
    }

    return 0;
}

double import(char* libreria) {
    return 0;
}

double max(double arr[]) {
    if (isnan(arr[0])) return -INFINITY; // Caso especial: array vacío

    double max_val = arr[0];
    for (int i = 1; !isnan(arr[i]); i++) {
        max_val = fmax(max_val, arr[i]);
    }
    return max_val;
}

double min(double arr[]) {
    if (isnan(arr[0])) return INFINITY; // Caso especial: array vacío

    double min_val = arr[0];
    for (int i = 1; !isnan(arr[i]); i++) {
        min_val = fmin(min_val, arr[i]);
    }
    return min_val;
}