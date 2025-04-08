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
        // Valor para números
        double var;
        // Puntero a función
        double (*funcptr)();
        // Puntero a la librería asignada dinámicamente
        void *libhandle;
    } valor;
} contenedor;

/**
 * Lanza el programa del intérprete
 * @param arg script de entrada opcional
 */
void interprete(char* arg);

/**
 * Wrapper del push de la pila de ficheros
 * @param E puntero a FILE
 */
void push_wrapper(tipoelemPila E);

/**
 * Wrapper de pop de la pila de ficheros
 */
void pop_wrapper();

/**
 * Wrapper de esVaciaPila de la pila de ficheros
 * @return 0 si no está vacía
 * @return 1 si está vacía
 */
unsigned esVaciaPila_wrapper();

/**
 * Wrapper de tope de la pila de ficheros
 * @return puntero a FILE con el fichero más arriba
 */
tipoelemPila tope_wrapper();

/**
 * Consulta el tamaño de la pila de ficheros
 * @return entero con la profundidad de la pila
 */
int consultar_profundidad();


#endif //P1_COMPGO_INTERPRETE_H
