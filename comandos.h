//
// Created by ignacio on 24/03/25.
//

#ifndef P1_COMPGO_COMANDOS_H
#define P1_COMPGO_COMANDOS_H

void unload(char* archivo);

double load(char* archivo);

double quit();

double help(char* lexema);

double workspace();

double clear(char* lexema);

double clean();

double echo(char* lexema);

double import(char* libreria);

double max(double arr[]);

double min(double arr[]);

#endif //P1_COMPGO_COMANDOS_H
