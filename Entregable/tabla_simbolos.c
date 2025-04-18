#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"
#include "interprete.h"
#include "avl.h"
#include "bison.tab.h"
#include <math.h>
#include <stdbool.h>
#include <dlfcn.h>
#include "comandos.h"


// Variable global
tabla_simbolos tabla;

// Funciones registradas
tipoelem funciones_registradas[] = {
        {FUNC1, "sin", .valor.funcptr=sin},
        {FUNC1, "cos", .valor.funcptr=cos},
        {FUNC1, "tan", .valor.funcptr=tan},
        {FUNC1, "asin", .valor.funcptr=asin},
        {FUNC1, "acos", .valor.funcptr=acos},
        {FUNC1, "atan", .valor.funcptr=atan},
        {FUNC1, "sinh", .valor.funcptr=sinh},
        {FUNC1, "cosh", .valor.funcptr=cosh},
        {FUNC1, "tanh", .valor.funcptr=tanh},
        {FUNC1, "exp", .valor.funcptr=exp},
        {FUNC1, "log", .valor.funcptr=log},
        {FUNC1, "abs", .valor.funcptr=fabs},
        {FUNC1, "sqrt", .valor.funcptr=sqrt},
        {FUNC2, "max", .valor.funcptr=max},
        {FUNC2, "min", .valor.funcptr=min},
        {FUNC2, "media", .valor.funcptr=media},
        {FUNC2, "var", .valor.funcptr=var},
        {FUNC2, "sum", .valor.funcptr=sum},
        {FUNC2, "prod", .valor.funcptr=prod},
        {FUNC2, "argmin", .valor.funcptr=argmin},
        {FUNC2, "argmax", .valor.funcptr=argmax},
        {-1, NULL, .valor.var=0},
};


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
        switch (e.comp_lexico) {
            case VARIABLE:
            case CONSTANTE:
                printf("<%d, \"%s\", %lf>\n", e.comp_lexico, e.lexema, e.valor.var);
                break;
            case FUNC1:
            case FUNC0:
            case COMANDO0:
            case COMANDO1:
            case FUNC2:
                printf("<%d, \"%s\", %p>\n", e.comp_lexico, e.lexema, e.valor.funcptr);
                break;
            case LIB:
                printf("<%d, \"%s\", %p>\n", e.comp_lexico, e.lexema, e.valor.libhandle);
                break;
            default:
                printf("<%d, \"%s\">\n", e.comp_lexico, e.lexema);
                break;
        }
        _inorden(der(tabla));
    }
}

/**
 * Imprime las variables en inorden
 * @param tabla a imprimir (solo las variables)
 */
void _inorden_imprimir_variables(tabla_simbolos tabla) {
    tipoelem e;
    // Recorre subárbol derecho e izquierdo de forma recursiva
    // Si es no vacío
    if (!vacia(tabla)) {
        _inorden_imprimir_variables(izq(tabla));
        leer(tabla, &e);
        if (e.comp_lexico == VARIABLE) {
            printf(AMARILLO"\t%-15s = %10.4lf\n"RESET, e.lexema, e.valor.var);
        }
        _inorden_imprimir_variables(der(tabla));
    }
}

/**
 * Imprime los comandos en inorden
 * @param tabla a imprimir (solo los comandos)
 */
void _inorden_imprimir_comandos(tabla_simbolos tabla) {
    tipoelem e;
    // Recorre subárbol derecho e izquierdo de forma recursiva
    // Si es no vacío
    if (!vacia(tabla)) {
        _inorden_imprimir_comandos(izq(tabla));
        leer(tabla, &e);
        if (e.comp_lexico == COMANDO0 || e.comp_lexico == COMANDO1) {
            printf(AMARILLO"\t%-15s = %p\n"RESET, e.lexema, e.valor.funcptr);
        }
        _inorden_imprimir_comandos(der(tabla));
    }
}

void _inorden_eliminar_variables(tabla_simbolos tablaA) {
    if (!vacia(tablaA) && tablaA != NULL) {
        // Guardar los hijos antes de potencialmente eliminar el nodo actual
        tabla_simbolos izq_sub = izq(tablaA);
        tabla_simbolos der_sub = der(tablaA);

        _inorden_eliminar_variables(izq_sub);

        tipoelem e;
        leer(tablaA, &e);

        if (e.comp_lexico == VARIABLE) {
            eliminar_variable(e.lexema);
        }

        _inorden_eliminar_variables(der_sub);
    }
}


/**
 * Registra en la TS las funciones de funciones_registradas
 */
void _registrar_funciones_basicas() {
    int i=0;
    while (funciones_registradas[i].lexema != NULL) {
        insertar_elemento(funciones_registradas[i]);
        i++;
    }
}

// FUNCIONES PÚBLICAS /////////////////////////

void crear_tabla() {

    // Creación del AVL
    crear(&tabla);

    tipoelem inicializacion[] = {
            {CONSTANTE, "PI", .valor.var=3.14159265358979323846},
            {CONSTANTE, "E", .valor.var=2.7182818284590452354},
            {CONSTANTE, "TOL", .valor.var=TOLERANCIA},
            {COMANDO0, "quit", .valor.funcptr=quit},
            {COMANDO1, "help", .valor.funcptr=help},
            {COMANDO1, "?", .valor.funcptr=help},
            {COMANDO1, "echo", .valor.funcptr=echo},
            {COMANDO0, "workspace", .valor.funcptr=workspace},
            {COMANDO0, "clean", .valor.funcptr=clean},
            {COMANDO1, "clear", .valor.funcptr=clear},
            {COMANDO1, "load", .valor.funcptr=load},
            {COMANDO1, "import", .valor.funcptr=import},
    };

    for (int i = 0; i < (int) (sizeof(inicializacion) / sizeof(tipoelem)); i++) {
        insertar_elemento(inicializacion[i]);
    }

    _registrar_funciones_basicas();

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

tipoelem buscar_funcion_lib(void* handle, char* lexema, char* lib, int numargs) {
    tipoelem e = {0, NULL, .valor.var=0};
    // Si está, se utiliza
    buscar_nodo(tabla, lexema, &e);
    // Si no está en la TS, se busca con dlsym
    if (e.lexema == NULL) {
        void (*funcion)(void);
        *(void **) (&funcion) = dlsym(handle, lexema);
        // Si la función se encuentra con dlsym, se copia al contenedor
        if (funcion) {
            switch (numargs) {
                case 0:
                    e.comp_lexico = FUNC0;
                    break;
                case 1:
                    e.comp_lexico = FUNC1;
                    break;
                default:
                    e.comp_lexico = FUNC2;
                    break;
            }
            char *libfunc = malloc(((strlen(lib) + strlen(lexema) + 2) * sizeof(char)));
            strncpy(libfunc, lib, strlen(lib));
            strncpy(libfunc + strlen(lib), "/", 2);
            strncpy(libfunc + strlen(lib) + 1, lexema, strlen(lexema));
            libfunc[strlen(lib) + strlen(lexema) + 1] = '\0';
            e.lexema = libfunc;
            e.valor.funcptr = (double (*)()) funcion;
            // Se añade a la TS
            insertar(&tabla, e);
            free(libfunc);
        }
    }
    // Si la función no está ni en la TS ni en la librería, devuelve NULL
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
    tipoelem c = {0, NULL, .valor.var=0};
    buscar_nodo(tabla, lexema, &c);
    if (c.lexema != NULL) {
        asignar_valor_nodo(&tabla, lexema, valor);
    }
}

void imprimir_variables() {
    printf(AMARILLO"------------------------------------\n"RESET);
    // Se imprime en inorden, con una función para la recursividad
    _inorden_imprimir_variables(tabla);
    printf(AMARILLO"------------------------------------\n\n"RESET);
}

void eliminar_variable(char* lexema) {
    if (lexema != NULL) {
        tipoelem e;
        if (!vacia(tabla)) {
            buscar_nodo(tabla, lexema, &e);
            if (e.comp_lexico == VARIABLE) {
                eliminar_nodo(&tabla, e);
                printf(AMARILLO"Variable eliminada."RESET"\n\n");
            }
        }
    }
}

void eliminar_todas_variables() {
    _inorden_eliminar_variables(tabla);
}
