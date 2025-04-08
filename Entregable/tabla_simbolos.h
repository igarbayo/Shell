#ifndef P1_COMPGO_TABLA_SIMBOLOS_H
#define P1_COMPGO_TABLA_SIMBOLOS_H

#include "avl.h"

typedef avl tabla_simbolos;

/**
 * Crea la tabla insertando todas las palabras reservadas iniciales en definiciones.h
 */
void crear_tabla();

/**
 * Añade un elemento en la tabla
 * @param elemento a introducir en la tabla
 */
void insertar_elemento(contenedor elemento);

/**
 * Busca un elemento
 * @param clave lexema a buscar
 * @return el componente_lexico asociado al lexema clave
 * @return -1 si la clave no está en la tabla
 */
tipoelem buscar_elemento(char* clave);

/**
 * Busca una función en una librería cargada de forma dinámica
 * @param handle puntero a la librería
 * @param lexema nombre de la función
 * @param lib nombre de la librería
 * @param numargs número de argumentos de la función lexema
 * @return contenedor con la función
 * @return contenedor vacío si la función no se encuentra
 */
tipoelem buscar_funcion_lib(void* handle, char* lexema, char* lib, int numargs);

/**
 * Libera la memoria asociada a la TS
 */
void eliminar_tabla();

/**
 * Imprime el contenido de la TS
 */
void imprimir_tabla();

/**
 *
 * @param lexema
 * @param valor
 */
void asignar_valor(char* lexema, double valor);

/**
 * Imprime los valores de todas las variables de la TS
 */
void imprimir_variables();

/**
 * Elimina una variable de la TS
 */
void eliminar_variable(char* lexema);

/**
 * Elimina todas las variables de la TS
 */
void eliminar_todas_variables();

#endif //P1_COMPGO_TABLA_SIMBOLOS_H
