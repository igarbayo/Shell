//
// Created by ignacio on 24/03/25.
//

#include "stdio.h"
#include "interprete.h"
#include "flex.yy.h"
#include "bison.tab.h"
#include "comandos.h"
#include "pila.h"

int profundidadPila = 0;
pila pilaFicheros;

void interprete(char* arg) {
    printf(AMARILLO"\nBienvenido al intérprete. Si necesitas ayuda, teclea ? o help().\n\n"RESET);

    if (arg != NULL) {
        load(arg);
    }

    crearPila(&pilaFicheros);

    yyparse();
}

void push_wrapper(tipoelemPila E) {
    push(&pilaFicheros, E);
    profundidadPila++;
}

void pop_wrapper() {
    pop(&pilaFicheros);
    profundidadPila--;
}

unsigned esVaciaPila_wrapper() {
    return esVaciaPila(pilaFicheros);
}

tipoelemPila tope_wrapper() {
    return tope(pilaFicheros);
}

int consultar_profundidad() {
    return profundidadPila;
}
