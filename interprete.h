#ifndef P1_COMPGO_INTERPRETE_H
#define P1_COMPGO_INTERPRETE_H

/* Colores */
#define ROJO "\x1b[31m"
#define VERDE "\x1b[32m"
#define CYAN "\x1b[36m"
#define AMARILLO  "\x1b[33m"
#define RESET "\x1b[0m"

typedef struct {
    int comp_lexico;
    char *lexema;
    union {
        double var;
        double (*funcptr)();
        void *libhandle;
    } valor;
} contenedor;

/**
 *
 * @param arg
 */
void interprete(char* arg);


#endif //P1_COMPGO_INTERPRETE_H
