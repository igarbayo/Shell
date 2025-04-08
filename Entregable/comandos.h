//
// Created by ignacio on 24/03/25.
//

#ifndef P1_COMPGO_COMANDOS_H
#define P1_COMPGO_COMANDOS_H

/**
 * Carga un script de sentencias
 * @param archivo fuente
 * @return 0
 */
double load(char* archivo);

/**
 * Cierra el intérprete
 * @return 0
 */
double quit();

/**
 * Muestra la ayuda general o de un comando
 * @param lexema nombre del comando
 * @return 0
 */
double help(char* lexema);

/**
 * Imprime todas las variables guardadas con sus valores
 * @return 0
 */
double workspace();

/**
 * Elimina una variable guardada o todas
 * @param lexema nombre de la variable a eliminar
 * @return 0
 */
double clear(char* lexema);

/**
 * Limpia la pantalla de sentencias
 * @return 0
 */
double clean();

/**
 * Cambia o muestra el estado del echo
 * @param lexema on/off para cambiar entre estados
 * @return 0
 */
double echo(char* lexema);

/**
 * Carga una librería en el intérprete en tiempo de ejecución
 * @param libreria nombre de la librería a cargar
 * @return 0
 */
double import(char* libreria);

/**
 * Calcula el máximo de un array que termina en NAN
 * @param arr array de elementos
 * @return máximo
 */
double max(double arr[]);

/**
 * Calcula el mínimo de un array que termina en NAN
 * @param arr array de elementos
 * @return mínimo
 */
double min(double arr[]);

/**
 * Calcula la media de un array que termina en NAN
 * @param arr array de elementos
 * @return media
 */
double media(double arr[]);

/**
 * Calcula la cuasivarianza de un array que termina en NAN
 * @param arr array de elementos
 * @return cuasivarianza
 */
double var(double arr[]);

/**
 * Halla la suma de un array que termina en NAN
 * @param arr array de elementos
 * @return suma
 */
double sum(double arr[]);

/**
 * Devuelve en producto de un array que termina en NAN
 * @param arr array de elementos
 * @return producto
 */
double prod(double arr[]);

/**
 * Devuelve el argmin de un array que termina en NAN
 * @param arr array de elementos
 * @return índice con valor mínimo
 */
double argmin(double arr[]);

/**
 * Devuelve el argmax de un arrau que termina en NAN
 * @param arr array de elementos
 * @return índice con valor máximo
 */
double argmax(double arr[]);

#endif //P1_COMPGO_COMANDOS_H
