%{
#include <math.h>
#include "flex.yy.h"
#include "tabla_simbolos.h"
#include "errores.h"
#include <stdbool.h>

// Variables globales
contenedor c;
bool hacerEcho = true;
bool script = false;
bool error = false;

%}

%code provides {
    void yyerror(char* s);
    void cambiar_echo(int valor);
    void ejecutar_script(int valor);
}

%union {
    double numero;
    char *cadena;
}

%start entrada

%token <numero> NUM
%token <cadena> CONSTANTE VARIABLE FUNC0 FUNC1 COMANDO0 COMANDO1 ARCHIVO LIB

%type <numero> expresion asignacion comando funcion

%left '-' '+'
%left '*' '/'
%left '%'
%precedence NEG
%right '^'


%%

/* Definición de la gramática */

entrada: %empty         {
                            if (!script) {
                                printf(CYAN">"RESET" ");
                            }
                        }
        | entrada linea
;

linea:   '\n'           { printf(CYAN">"RESET" "); }
        | expresion '\n'              {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN_DETECTADO");
                                        } else if (hacerEcho) {
                                            printf(VERDE"  %lf"RESET"\n\n", $1);
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | expresion ';' '\n'          {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN_DETECTADO");
                                        } else if (hacerEcho) {
                                            printf(VERDE"  %lf"RESET"\n\n", $1);
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | asignacion '\n'     {
                            if (!error) {
                                if (isnan($1)) {
                                    lanzar_error("NAN_DETECTADO");
                                } else if (hacerEcho) {
                                    printf(VERDE"  %lf"RESET"\n\n", $1);
                                }
                            }
                            if (!script) {
                                printf(CYAN">"RESET" ");
                            }
                            error = false;
                        }
        | asignacion ';' '\n'         {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN_DETECTADO");
                                        } else if (hacerEcho) {
                                            printf(VERDE"  %lf"RESET"\n\n", $1);
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | comando '\n'         {
                                if (isnan($1) && !error) {
                                    lanzar_error("NAN_DETECTADO");
                                }
                                if (!script) {
                                    printf(CYAN">"RESET" ");
                                }
                                error = false;
                            }
        | comando ';' '\n'         {
                                    if (isnan($1) && !error) {
                                        lanzar_error("NAN_DETECTADO");
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | funcion '\n'          {
                                if (!error) {
                                    if (isnan($1)) {
                                        lanzar_error("NAN_DETECTADO");
                                    } else if (hacerEcho) {
                                        printf(VERDE"  %lf"RESET"\n\n", $1);
                                    }
                                }
                                if (!script) {
                                    printf(CYAN">"RESET" ");
                                }
                                error = false;
                            }
        | funcion ';' '\n'       {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN_DETECTADO");
                                        } else if (hacerEcho) {
                                            printf(VERDE"  %lf"RESET"\n\n", $1);
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }

;

expresion:    NUM
        | CONSTANTE         {
                            c = buscar_elemento($1);
                            $$ = c.valor.var;
                            free($1);
                        }
        | VARIABLE           {
                            if ((c = buscar_elemento($1)).lexema != NULL) {
                                $$ = c.valor.var;
                            } else {
                                lanzar_error("VARIABLE_NON_DEFINIDA");
                                error = true;
                                $$ = NAN;
                            }
                            free($1);
                        }
        | '-' expresion %prec NEG {
                                 if (!isnan($2)) {
                                     $$ = -$2;
                                 } else {
                                     $$ = NAN;
                                 }
                            }
        | expresion '+' expresion   {
                            if (!isnan($1) && !isnan($3)) {
                                $$ = $1 + $3;
                            } else {
                                $$ = NAN;
                            }
                        }
        | expresion '-' expresion   {
                            if (!isnan($1) && !isnan($3)) {
                                $$ = $1 - $3;
                            } else {
                                $$ = NAN;
                            }
                        }
        | expresion '*' expresion   {
                            if (!isnan($1) && !isnan($3)) {
                                $$ = $1 * $3;
                            } else {
                                $$ = NAN;
                            }
                        }
        | expresion '/' expresion   {
                            if ($3 == 0) {
                                lanzar_error("DIV_CERO");
                                error = true;
                                $$ = NAN;
                            } else {
                                if (!isnan($1) && !isnan($3)) {
                                    $$ = $1 / $3;
                                } else {
                                    $$ = NAN;
                                }
                            }
                        }
        | expresion '%' expresion   {
                            if ($3 == 0) {
                                lanzar_error("MOD_CERO");
                                error = true;
                                $$ = NAN;
                            } else {
                                if (!isnan($1) && !isnan($3)) {
                                    $$ = fmod($1, $3);
                                } else {
                                    $$ = NAN;
                                }
                            }
                        }
        | expresion '^' expresion   {
                            if (!isnan($1) && !isnan($3)) {
                                $$ = pow($1, $3);
                            } else {
                                $$ = NAN;
                            }
                        }
        | '(' expresion ')'   {
                             if (!isnan($2)) {
                                 $$ = $2;
                             } else {
                                 $$ = NAN;
                             }
                         }
;

asignacion:   VARIABLE '=' expresion     {
                           if (!error) {
                               if ((c = buscar_elemento($1)).lexema != NULL) {
                                   printf("1");
                                   asignar_valor($1, $3);
                               } else {
                                   printf("2");
                                   c.lexema = strdup($1);
                                   c.comp_lexico = VARIABLE;
                                   c.valor.var = $3;
                                   insertar_elemento(c);
                                   free(c.lexema);
                               }
                           }
                           $$ = $3;
                           free($1);
                        }
        | VARIABLE '=' funcion   {
                           if (!error) {
                               if ((c = buscar_elemento($1)).lexema != NULL) {
                                   asignar_valor($1, $3);
                               } else {
                                   c.lexema = strdup($1);
                                   c.comp_lexico = VARIABLE;
                                   c.valor.var = $3;
                                   insertar_elemento(c);
                                   free(c.lexema);
                               }
                           }
                           $$ = $3;
                           free($1);
                        }
        | CONSTANTE '=' expresion {
                            lanzar_error("CONSTANTE_NON_MODIFICABLE");
                            error = true;
                            $$ = NAN;
                            free($1);
                        }
        | CONSTANTE '=' funcion {
                            lanzar_error("CONSTANTE_NON_MODIFICABLE");
                            error = true;
                            $$ = NAN;
                            free($1);
                        }
;

comando:
        COMANDO0                    {
                                        c = buscar_elemento($1);
                                        free($1);
                                        (*(c.valor.funcptr))();
                                    }
        | COMANDO0 '(' ')'             {
                                        c = buscar_elemento($1);
                                        free($1);
                                        (*(c.valor.funcptr))();
                                    }
        | COMANDO1  {
                                        c = buscar_elemento($1);
                                        char str[] = "clear";
                                        int result = strcmp(c.lexema, str);
                                        if (result == 0) {
                                            printf("\nES CLEAR\n");
                                            (*(c.valor.funcptr))(NULL);
                                        } else {
                                            lanzar_error("La función tiene argumentos");
                                            error = true;
                                            $$ = NAN;
                                        }
                                        free($1);
                                    }
        | COMANDO1 '(' ')'             {
                                        c = buscar_elemento($1);
                                        char str[] = "clear";
                                        int result = strcmp(c.lexema, str);
                                        if (result == 0) {
                                            (*(c.valor.funcptr))(NULL);
                                        } else {
                                            lanzar_error("La función tiene argumentos");
                                            error = true;
                                            $$ = NAN;
                                        }
                                        free($1);
                                     }
        | COMANDO1 '(' VARIABLE ')'  {
                                         c = buscar_elemento($1);
                                         if (c.lexema != NULL && c.valor.funcptr != NULL) {
                                             $$ = (*(c.valor.funcptr))($3);
                                         } else {
                                             lanzar_error("No se encuentra el comando");
                                             error = true;
                                             $$ = NAN;
                                         }
                                         free($1);
                                      }
        | COMANDO1 ARCHIVO              {
                                        c = buscar_elemento($1);
                                        (*(c.valor.funcptr))($2);
                                        free($1);
                                        free($2);
                                     }
        | COMANDO1 '(' ARCHIVO ')'      {
                                        c = buscar_elemento($1);
                                        (*(c.valor.funcptr))($3);
                                        free($1);
                                        free($3);
                                     }
;

funcion:
        FUNC1 '(' expresion ')'  {
                                                c = buscar_elemento($1);
                                                if (c.lexema != NULL && c.valor.funcptr != NULL) {
                                                    $$ = (*(c.valor.funcptr))($3);
                                                } else {
                                                    lanzar_error("No se encuentra la función básica");
                                                    error = true;
                                                    $$ = NAN;
                                                }
                                                free($1);

                                          }
        | LIB '/' VARIABLE '(' expresion ')'  {
                                                /*
                                                c = buscar_elemento($1);

                                                char *libfunc = malloc(((strlen($1) + strlen($3) + 2) * sizeof(char)));
                                                strncpy(libfunc, $1, strlen($1));
                                                strncpy(libfunc + strlen($1), "/", 2);
                                                strncpy(libfunc + strlen($1) + 1, $3, strlen($3));
                                                libfunc[strlen($1) + strlen($3) + 1] = '\0';

                                                cLexico c_func = buscarFuncion(c.valor.libhandle, $3, libfunc);
                                                if (c_func.lexema != NULL) {
                                                    $$ = (*(c_func.valor.funcptr))($5);
                                                } else {
                                                    lanzar_error("FUNCION_NON_ATOPADA");
                                                    error = true;
                                                    $$ = NAN;
                                                }
                                                free(libfunc);
                                                free($1);
                                                free($3);
                                                */

                                            }
        | LIB '/' VARIABLE '(' expresion ',' expresion ')'   {
                                                /*
                                                c = buscar_elemento($1);

                                                char *libfunc = malloc(((strlen($1) + strlen($3) + 2) * sizeof(char)));
                                                strncpy(libfunc, $1, strlen($1));
                                                strncpy(libfunc + strlen($1), "/", 2);
                                                strncpy(libfunc + strlen($1) + 1, $3, strlen($3));
                                                libfunc[strlen($1) + strlen($3) + 1] = '\0';

                                                cLexico c_func = buscarFuncion(c.valor.libhandle, $3, libfunc);
                                                if (c_func.lexema != NULL) {
                                                    $$ = (*(c_func.valor.funcptr))($5, $7);
                                                } else {
                                                    lanzar_error("FUNCION_NON_ATOPADA");
                                                    error = true;
                                                    $$ = NAN;
                                                }
                                                free(libfunc);
                                                free($1);
                                                free($3);
                                                */
                                            }
        | LIB '/' VARIABLE '(' ')'               {
                                                /*
                                                lanzar_error("PARAMETROS_NON_INDICADOS");
                                                error = true;
                                                $$ = NAN;
                                                free($1);
                                                free($3);
                                                */
                                            }
        | expresion '(' expresion ')'                   {
                                                /*
                                                lanzar_error("LIBRERIA_NON_ATOPADA");
                                                error = true;
                                                $$ = NAN;
                                                */
                                            }
        | expresion '(' expresion ',' expresion ')'           {
                                                /*
                                                lanzar_error("LIBRERIA_NON_ATOPADA");
                                                error = true;
                                                $$ = NAN;
                                                */
                                            }
        | expresion '(' ')'                       {
                                                /*
                                                lanzar_error("LIBRERIA_NON_ATOPADA");
                                                error = true;
                                                $$ = NAN;
                                                */
                                            }
;

%%

void yyerror(char* s) {
    lanzar_error("Sintaxis no válida");
}

void cambiar_echo(int valor) {
    hacerEcho = valor;
}

void ejecutar_script(int valor) {
    script = valor;
    if (!script) {
        printf("\n"AMARILLO"Script ejecutado correctamente."RESET"\n\n"CYAN">"RESET" ");
    }
}


