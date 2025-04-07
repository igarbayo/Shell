#ifndef P1_COMPGO_INTERPRETE_H
#define P1_COMPGO_INTERPRETE_H

#include <math.h>
#include "bison.tab.h"
#include "pila.h"
#include <stdbool.h>

/* Colores */
#define ROJO "\x1b[31m"
#define VERDE "\x1b[32m"
#define CYAN "\x1b[36m"
#define AMARILLO  "\x1b[33m"
#define RESET "\x1b[0m"

// Tolerancia
#define TOLERANCIA 1e-6

// Contenedor
typedef struct {
    int comp_lexico;
    char *lexema;
    union {
        double var;
        double (*funcptr)();
        double (*nueva_puntero)(double* nueva_args);
        void *libhandle;
    } valor;
} contenedor;

/**
 *
 * @param nombre
 * @return
 */
int es_funcion_registrada(char *nombre);

/**
 *
 * @param arg
 */
void interprete(char* arg);

void push_wrapper(tipoelemPila E);

void pop_wrapper();

unsigned esVaciaPila_wrapper();

tipoelemPila tope_wrapper();

int consultar_profundidad();


#endif //P1_COMPGO_INTERPRETE_H
