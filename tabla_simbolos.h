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
 *
 * @param lexema
 * @return
 */
tipoelem buscar_funcion_basica(char* lexema);

/**
 *
 * @param nombre
 * @return
 */
int es_funcion_basica(char *nombre);


#endif //P1_COMPGO_TABLA_SIMBOLOS_H
