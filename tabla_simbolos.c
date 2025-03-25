#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"
#include "interprete.h"
#include "avl.h"
#include "bison.tab.h"
#include <math.h>
#include "comandos.h"


// Variable global
tabla_simbolos tabla;


// FUNCIONES PRIVADAS //////////////////////

/**
 * Imprime el contenido de la tabla en inorden
 * @param tabla a imprimir
 */
void _inorden(tabla_simbolos tabla) {
    tipoelem e;
    // Recorre subárbol derecho e izquierdo de forma recursiva
    // Si es no vacío
    if (!vacia(tabla)) {
        _inorden(izq(tabla));
        leer(tabla, &e);
        printf("<%d, \"%s\">\n", e.comp_lexico, e.lexema);
        _inorden(der(tabla));
    }
}

/**
 *
 */
void _registrar_funciones_trig() {
    tipoelem trig[] = {
            {CMND1, "sin", .valor.funcptr=sin},
            {CMND1, "cos", .valor.funcptr=cos},
            {CMND1, "tan", .valor.funcptr=tan},
            {CMND1, "asin", .valor.funcptr=asin},
            {CMND1, "acos", .valor.funcptr=acos},
            {CMND1, "atan", .valor.funcptr=atan},
            {CMND1, "sinh", .valor.funcptr=sinh},
            {CMND1, "cosh", .valor.funcptr=cosh},
            {CMND1, "tanh", .valor.funcptr=tanh},
    };

    for (int i = 0; i < (sizeof(trig) / sizeof(tipoelem)); i++) {
        insertar_elemento(trig[i]);
    }
}

// FUNCIONES PÚBLICAS /////////////////////////

void crear_tabla() {
    int i=0;
    contenedor c;

    // Creación del AVL
    crear(&tabla);

    tipoelem inicializacion[] = {
            {CONSTANTE, "PI", .valor.var=3.14159265358979323846},
            {CONSTANTE, "E", .valor.var=2.7182818284590452354},
            {CMND0, "CLEAR", .valor.funcptr=clear},
            {CMND0, "QUIT", .valor.funcptr=quit},
            {CMND0, "HELP", .valor.funcptr=help},
            {CMND0, "ECHO", .valor.funcptr=echo},
            {CMND0, "WORKSPACE", .valor.funcptr=workspace},
            {CMND0, "CLEAN", .valor.funcptr=clean},
            {CMND1, "LOAD", .valor.funcptr=load},
            {CMND1, "IMPORT", .valor.funcptr=import},
    };

    for (int i = 0; i < (sizeof(inicializacion) / sizeof(tipoelem)); i++) {
        insertar_elemento(inicializacion[i]);
    }

    _registrar_funciones_trig();

}

void insertar_elemento(contenedor elemento) {
    insertar(&tabla, (tipoelem) elemento);
}

tipoelem buscar_elemento(char* clave) {
    tipoelem e;
    // Hacemos es_miembro con el AVL
    if (es_miembro_clave(tabla, clave) == 1) {
        // Buscamos en el AVL
        buscar_nodo(tabla, clave, &e);
        return e;
    }
    // Si no se encuentra
    e.comp_lexico = -1;
    e.lexema = NULL;
    return e;
}

void eliminar_tabla() {
    // Función del AVL
    destruir(&tabla);
}

void imprimir_tabla() {
    printf("----------- Tabla de símbolos -----------\n");
    // Se imprime en inorden, con una función para la recursividad
    _inorden(tabla);
    printf("-----------------------------------------\n");

}

void asignar_valor(char* lexema, double valor) {
    tipoelem c = {0, NULL};
    buscar_nodo(tabla, lexema, &c);
    if (c.lexema != NULL) {
        asignar_valor_nodo(&tabla, lexema, valor);
    }
}