%{
#include "flex.yy.h"
#include "tabla_simbolos.h"
#include "errores.h"
#include <stdbool.h>
#include "interprete.h"
#include <dlfcn.h>

// Variables globales
contenedor c;
bool hacerEcho = true;
bool script = false;
bool error = false;
double ANS = NAN;
bool verdad = false;
%}

%code requires {
    #include <stdbool.h>
}

%code provides {
    void yyerror(char* s);
    void cambiar_echo(double valor);
    void ejecutar_script(int valor);
}

%union {
    double numero;
    char *cadena;
    double *arr;
}

%start entrada

%token <numero> NUM
%token <cadena> CONSTANTE VARIABLE FUNC0 FUNC1 FUNC2 COMANDO0 COMANDO1 ARCHIVO LIB RETURN DEF
%token GT LT EQ NE LE GE

%type <numero> expresion asignacion comando funcion
%type <arr> lista_expresiones

// Comparaciones → Menor precedencia
%left GT LT EQ NE LE GE

// Suma y resta
%left '+' '-'

// Multiplicación, división y módulo
%left '*' '/' '%'

// Operador unario negativo (como en -x)
%precedence NEG

// Potencia → más fuerte que multiplicación
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
        | expresion '\n'        {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN detectado");
                                        }
                                        if (!verdad) {
                                            printf(VERDE"  %lf"RESET"\n\n", $1);
                                        }
                                        verdad = false;
                                        ANS = $1;
                                    }
                                    if (!script && consultar_profundidad() <= 1) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | expresion ';' '\n'    {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN detectado");
                                        }
                                    }
                                    if (!script && consultar_profundidad() <= 1) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | asignacion '\n'     {
                            if (!error) {
                                if (isnan($1)) {
                                    lanzar_error("NAN detectado");
                                } else if (hacerEcho) {
                                    printf(VERDE"  %lf"RESET"\n\n", $1);
                                }
                                ANS = $1;
                            }
                            if (!script && consultar_profundidad() <= 1) {
                                printf(CYAN">"RESET" ");
                            }
                            error = false;
                        }
        | asignacion ';' '\n'         {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN detectado");
                                        }
                                    }
                                    if (!script && consultar_profundidad() <= 1) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | comando '\n'         {
                                if (isnan($1) && !error) {
                                    lanzar_error("NAN detectado");
                                }
                                if (!script && consultar_profundidad() <= 1) {
                                    printf(CYAN">"RESET" ");
                                }
                                error = false;
                            }
        | comando ';' '\n'         {
                                    if (isnan($1) && !error) {
                                        lanzar_error("NAN detectado");
                                    }
                                    if (!script && consultar_profundidad() <= 1) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | funcion '\n'          {
                                if (!error) {
                                    if (isnan($1)) {
                                        lanzar_error("NAN detectado");
                                    }
                                    printf(VERDE"  %lf"RESET"\n\n", $1);
                                    ANS = $1;
                                }
                                if (!script && consultar_profundidad() <= 1) {
                                    printf(CYAN">"RESET" ");
                                }
                                error = false;
                            }
        | funcion ';' '\n'       {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN detectado");
                                        }
                                    }
                                    if (!script && consultar_profundidad() <= 1) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | error '\n'        {
                                yyerrok;
                                if (!error) {
                                    printf(CYAN">"RESET" ");
                                }
                            }
;

lista_expresiones:
    expresion ',' expresion {
        // Crear un array con los dos primeros valores y agregar NAN al final
        $$ = malloc(3 * sizeof(double));
        $$[0] = $1;
        $$[1] = $3;
        $$[2] = NAN;  // Marcador de final
    }
    | lista_expresiones ',' expresion {
        // Obtener tamaño actual del array (contando hasta NAN)
        int len = 0;
        while (!isnan($1[len])) len++;

        // Ampliar el array para incluir una nueva expresión + NAN al final
        $$ = realloc($1, (len + 2) * sizeof(double));
        $$[len] = $3;
        $$[len + 1] = NAN;  // Mantener NAN al final
    }
;

expresion:
        NUM
        | CONSTANTE         {
                            c = buscar_elemento($1);
                            $$ = c.valor.var;
                            free($1);
                        }
        | VARIABLE           {
                            if ((c = buscar_elemento($1)).lexema != NULL) {
                                $$ = c.valor.var;
                            } else {
                                int result = strcmp($1, "ANS");
                                if (result == 0) {
                                    $$ = ANS;
                                } else {
                                    lanzar_error("Variable no definida");
                                    error = true;
                                    $$ = NAN;
                                }
                            }
                            free($1);
                        }
        | FUNC1 '(' expresion ')'  {
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
        | FUNC1 '(' ')'                   {
                                                        lanzar_error("La función tiene un argumento");
                                                        error = true;
                                                        $$ = NAN;
                                                  }
        | FUNC1 '(' lista_expresiones ')'                   {
                                                        lanzar_error("La función tiene un argumento");
                                                        error = true;
                                                        $$ = NAN;
                                                  }
        | FUNC2 '(' lista_expresiones ')' {
                                                        c = buscar_elemento($1);
                                                        if (c.lexema != NULL && c.valor.funcptr != NULL) {
                                                            $$ = (*(c.valor.funcptr))($3);
                                                        } else {
                                                            lanzar_error("No se encuentra la función básica");
                                                            error = true;
                                                            $$ = NAN;
                                                        }
                                                        free($1);
                                                        free($3);
                                                  }
        | FUNC2 '(' expresion ')'         {
                                                        double* array = (double *)malloc(2 * sizeof(double));
                                                        array[0] = $3;
                                                        array[1] = NAN;

                                                        c = buscar_elemento($1);
                                                        if (c.lexema != NULL && c.valor.funcptr != NULL) {
                                                            $$ = (*(c.valor.funcptr))(array);
                                                        } else {
                                                            lanzar_error("No se encuentra la función básica");
                                                            error = true;
                                                            $$ = NAN;
                                                        }
                                                        free($1);
                                                        free(array);

                                                  }
        | FUNC2 '(' ')'                   {
                                                        lanzar_error("La función tiene argumentos");
                                                        error = true;
                                                        $$ = NAN;
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
                            if (fabs($3) < TOLERANCIA) {
                                lanzar_error("División entre 0");
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
                            if (fabs($3) < TOLERANCIA) {
                                lanzar_error("Módulo 0");
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
        | expresion GT expresion     {
                                        if ($1 == 0) {
                                            $$ = TOLERANCIA > $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else if ($3 == 0) {
                                            $$ = $1 > TOLERANCIA; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else {
                                            $$ = $1 > $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        }
                                     }
        | expresion LT expresion     {
                                        if ($1 == 0) {
                                            $$ = TOLERANCIA < $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else if ($3 == 0) {
                                            $$ = $1 < TOLERANCIA; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else {
                                            $$ = $1 < $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        }
                                     }
        | expresion GE expresion      { if ($1 == 0) {
                                            $$ = TOLERANCIA >= $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else if ($3 == 0) {
                                            $$ = $1 >= TOLERANCIA; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else {
                                            $$ = $1 >= $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        }
                                      }
        | expresion LE expresion
                                      { if ($1 == 0) {
                                            $$ = TOLERANCIA <= $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else if ($3 == 0) {
                                            $$ = $1 <= TOLERANCIA; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else {
                                            $$ = $1 <= $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        }
                                      }
        | expresion EQ expresion
                                      { if ($1 == 0) {
                                            $$ = TOLERANCIA == $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else if ($3 == 0) {
                                            $$ = $1 == TOLERANCIA; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else {
                                            $$ = $1 == $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        }
                                      }
        | expresion NE expresion
                                      { if ($1 == 0) {
                                            $$ = TOLERANCIA != $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else if ($3 == 0) {
                                            $$ = $1 != TOLERANCIA; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        } else {
                                            $$ = $1 != $3; printf(VERDE"  %s\n\n", $$ ? "true" : "false"RESET); verdad = true;
                                        }
                                      }
;


asignacion:
        VARIABLE '=' expresion     {
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
                            lanzar_error("Las constantes no se pueden modificar");
                            error = true;
                            $$ = NAN;
                            free($1);
                        }
        | CONSTANTE '=' funcion {
                            lanzar_error("Las constantes no se pueden modificar");
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
                                        int result1 = strcmp(c.lexema, "clear");
                                        int result2 = strcmp(c.lexema, "help");
                                        int result3 = strcmp(c.lexema, "?");
                                        int result4 = strcmp(c.lexema, "echo");
                                        if (result1 == 0 || result2 == 0 || result3 == 0 || result4 == 0) {
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
                                        int result1 = strcmp(c.lexema, "clear");
                                        int result2 = strcmp(c.lexema, "help");
                                        int result3 = strcmp(c.lexema, "?");
                                        int result4 = strcmp(c.lexema, "echo");
                                        if (result1 == 0 || result2 == 0 || result3 == 0 || result4 == 0) {
                                            (*(c.valor.funcptr))(NULL);
                                        } else {
                                            lanzar_error("La función tiene argumentos");
                                            error = true;
                                            $$ = NAN;
                                        }
                                        free($1);
                                       }
        | COMANDO1 '(' COMANDO0 ')'    {
                                        c = buscar_elemento($1);
                                        int result1 = strcmp(c.lexema, "help");
                                        int result2 = strcmp(c.lexema, "?");
                                        if (result1 == 0 || result2 == 0) {
                                               (*(c.valor.funcptr))($3);
                                        } else {
                                            lanzar_error("El argumento no puede ser un comando");
                                            error = true;
                                            $$ = NAN;
                                        }
                                        free($1);
                                        free($3);
                                       }
        | COMANDO1 '(' COMANDO1 ')'    {
                                                c = buscar_elemento($1);
                                                int result1 = strcmp(c.lexema, "help");
                                                int result2 = strcmp(c.lexema, "?");
                                                if (result1 == 0 || result2 == 0) {
                                                       (*(c.valor.funcptr))($3);
                                                } else {
                                                    lanzar_error("El argumento no puede ser un comando");
                                                    error = true;
                                                    $$ = NAN;
                                                }
                                                free($1);
                                                free($3);
                                               }
        | COMANDO1 COMANDO0          {
                                        c = buscar_elemento($1);
                                        int result1 = strcmp(c.lexema, "?");
                                        if (result1 == 0) {
                                            (*(c.valor.funcptr))($2);
                                        } else {
                                            lanzar_error("Sintaxis incorrecta: faltan los paréntesis");
                                            error = true;
                                            $$ = NAN;
                                        }
                                        free($1);
                                        free($2);
                                     }
        | COMANDO1 COMANDO1          {
                                                c = buscar_elemento($1);
                                                int result1 = strcmp(c.lexema, "?");
                                                if (result1 == 0) {
                                                    (*(c.valor.funcptr))($2);
                                                } else {
                                                    lanzar_error("Sintaxis incorrecta: faltan los paréntesis");
                                                    error = true;
                                                    $$ = NAN;
                                                }
                                                free($1);
                                                free($2);
                                             }
        | COMANDO1 '(' VARIABLE ')'  {
                                         c = buscar_elemento($1);
                                         int result1 = strcmp(c.lexema, "echo");
                                         if (c.lexema != NULL && c.valor.funcptr != NULL) {
                                             if (result1 == 0) {
                                                cambiar_echo((*(c.valor.funcptr))($3));
                                             } else {
                                                $$ = (*(c.valor.funcptr))($3);
                                             }
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
        LIB '/' VARIABLE '(' expresion ')'  {
                                                // Pone c vacío
                                                c = buscar_elemento($1);
                                                if (c.lexema == NULL || c.valor.libhandle == NULL) {
                                                    lanzar_error("La librería no está importada");
                                                } else {
                                                    contenedor c_func = buscar_funcion_lib(c.valor.libhandle, $3, $1, 1);
                                                    if (c_func.lexema != NULL) {
                                                        $$ = (*(c_func.valor.funcptr))($5);
                                                    } else {
                                                        lanzar_error("FUNCION_NON_ATOPADA");
                                                        error = true;
                                                        $$ = NAN;
                                                    }
                                                }
                                                free($1);
                                                free($3);
                                            }
        | LIB '/' VARIABLE '(' lista_expresiones')'   {
                                                // Pone c vacío
                                                c = buscar_elemento($1);
                                                if (c.lexema == NULL || c.valor.libhandle == NULL) {
                                                    lanzar_error("La librería no está importada");
                                                } else {
                                                    contenedor c_func = buscar_funcion_lib(c.valor.libhandle, $3, $1, 2);
                                                    if (c_func.lexema != NULL) {
                                                        $$ = (*(c_func.valor.funcptr))($5);
                                                    } else {
                                                        lanzar_error("No se encuentra la función");
                                                        error = true;
                                                        $$ = NAN;
                                                    }
                                                }
                                                free($1);
                                                free($3);
                                            }
        | LIB '/' VARIABLE '(' ')'               {
                                                // Pone c vacío
                                                c = buscar_elemento($1);
                                                if (c.lexema == NULL || c.valor.libhandle == NULL) {
                                                    lanzar_error("La librería no está importada");
                                                } else {
                                                    contenedor c_func = buscar_funcion_lib(c.valor.libhandle, $3, $1, 0);
                                                    if (c_func.lexema != NULL) {
                                                        $$ = (*(c_func.valor.funcptr))();
                                                    } else {
                                                        lanzar_error("No se encuentra la función");
                                                        error = true;
                                                        $$ = NAN;
                                                    }
                                                }
                                                free($1);
                                                free($3);
                                            }
;


%%

void yyerror(char* s) {
    lanzar_error("Error sintáctico");
    error=false;
}

void cambiar_echo(double valor) {
    if (valor == 1) { hacerEcho = true; }
    else if (valor == 2) { hacerEcho = false; }
}

void ejecutar_script(int valor) {
    script = valor;
    if (script && hacerEcho == true) {
        printf("\n"AMARILLO"Script ejecutado correctamente."RESET"\n\n");
        if (consultar_profundidad() < 1) {
            printf(CYAN">"RESET" ");
        }
    }
}


