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
#include <math.h>
#include "pila.h"
#include <dlfcn.h>


bool variableEcho = true;

void _ayuda_general() {
    printf(AMARILLO"Bienvenido al intérprete de comandos tipo shell.\n\n"RESET);

    printf(AMARILLO"Este intérprete forma parte de la asignatura de Compiladores e Intérpretes en el Grado en Ingeniería Informática.\n"RESET);
    printf(AMARILLO"Proporciona un entorno interactivo similar a las consolas de R, Python o Matlab.\n\n"RESET);

    printf(AMARILLO"Para más información, consulte la documentación del proyecto.\n"RESET);
}

char* _extraer_nombre(char* ruta) {
    // Buscar el último '/'
    const char* ultimo_slash = strrchr(ruta, '/');
    // Si no se encuentra '/', usamos la cadena completa
    if (!ultimo_slash) {
        ultimo_slash = ruta;
    } else {
        ultimo_slash++;  // Avanzar un carácter para después del '/'
    }

    // Buscar la extensión ".so" en la parte después del último '/'
    const char* punto_so = strstr(ultimo_slash, ".so");
    if (!punto_so) {
        return NULL; // Si no se encuentra ".so", devolver NULL o algún valor adecuado.
    }

    // Calcular la longitud del nombre
    size_t longitud = punto_so - ultimo_slash;

    // Crear una nueva cadena con el nombre
    char* nombre = malloc(longitud + 1);
    if (nombre == NULL) {
        perror("Error al asignar memoria");
        return NULL;
    }

    // Copiar el nombre sin la extensión
    strncpy(nombre, ultimo_slash, longitud);
    nombre[longitud] = '\0';  // Asegurar que la cadena termine en '\0'

    return nombre;
}

/// FUNCIONES PÚBLICAS

double load(char *archivo) {
    yyin = fopen(archivo, "r");

    if (yyin == NULL) {
        lanzar_error("No se encuentra el fichero");
        yyin = stdin;
    } else {
        push_wrapper(yyin);
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
        int r8 = strcmp(lexema, "import");

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
        } else if (r8 == 0) {
            printf(AMARILLO"\n---------------------------------------------\n"RESET);
            printf(AMARILLO"El comando import(RUTA) carga una librería dinámica en el intérprete.\n"RESET);
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
    // Secuencia de escape ANSI para limpiar la pantalla
    printf("\033[H\033[J");
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
    contenedor c = {0, NULL, .valor.var=0};
    c.valor.libhandle = dlopen(libreria, RTLD_LAZY);
    if (c.valor.libhandle == NULL) {
        lanzar_error("Error al cargar la libreria");
        lanzar_error(dlerror());
    } else {
        c.comp_lexico = LIB;
        c.lexema = _extraer_nombre(libreria);
        insertar_elemento(c);
        printf(AMARILLO"Librería cargada correctamente"RESET"\n\n");
    }
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

double media(double arr[]) {
    if (isnan(arr[0])) return NAN; // Caso especial: array vacío

    double suma = 0.0;
    int count = 0;
    for (int i = 0; !isnan(arr[i]); i++) {
        suma += arr[i];
        count++;
    }
    return count > 0 ? suma / count : NAN;
}

double var(double arr[]) {
    if (isnan(arr[0])) return NAN; // Caso especial: array vacío

    double suma = 0.0;
    int count = 0;
    for (int i = 0; !isnan(arr[i]); i++) {
        suma += arr[i];
        count++;
    }

    if (count < 2) return NAN; // No se puede calcular cuasivarianza con menos de 2 elementos

    double media = suma / count;
    double suma_cuadrados = 0.0;
    for (int i = 0; !isnan(arr[i]); i++) {
        double diff = arr[i] - media;
        suma_cuadrados += diff * diff;
    }

    return suma_cuadrados / (count - 1);
}

double sum(double arr[]) {
    if (isnan(arr[0])) return 0.0; // Array vacío: suma = 0

    double total = 0.0;
    for (int i = 0; !isnan(arr[i]); i++) {
        total += arr[i];
    }
    return total;
}

double prod(double arr[]) {
    if (isnan(arr[0])) return 1.0; // Array vacío: producto neutro = 1

    double total = 1.0;
    for (int i = 0; !isnan(arr[i]); i++) {
        total *= arr[i];
    }
    return total;
}

double argmin(double arr[]) {
    if (isnan(arr[0])) return -1; // Array vacío: sin índice válido

    double min_val = arr[0];
    int min_index = 0;

    for (int i = 1; !isnan(arr[i]); i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_index = i;
        }
    }
    return (double) min_index;
}

double argmax(double arr[]) {
    if (isnan(arr[0])) return -1; // Array vacío: sin índice válido

    double max_val = arr[0];
    int max_index = 0;

    for (int i = 1; !isnan(arr[i]); i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_index = i;
        }
    }
    return (double) max_index;
}



