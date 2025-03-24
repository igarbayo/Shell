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

void yyerror (char *s);
%}

%union {
    double numero;
    char *cadena;
}

%start entrada

%token <numero> NUM
%token <cadena> CONST VAR FUNC CMND0 CMND1 ARCHIVO LIB

%type <numero> exp asig cmnd fnc

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
        | exp '\n'              {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN_DETECTADO");
                                        } else if (hacerEcho) {
                                            printf(VERDE"%lf"RESET"\n\n", $1);
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | exp ';' '\n'          {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN_DETECTADO");
                                        } else if (hacerEcho) {
                                            printf(VERDE"%lf"RESET"\n\n", $1);
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | asig '\n'     {
                            if (!error) {
                                if (isnan($1)) {
                                    lanzar_error("NAN_DETECTADO");
                                } else if (hacerEcho) {
                                    printf(VERDE"%lf"RESET"\n\n", $1);
                                }
                            }
                            if (!script) {
                                printf(CYAN">"RESET" ");
                            }
                            error = false;
                        }
        | asig ';' '\n'         {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN_DETECTADO");
                                        } else if (hacerEcho) {
                                            printf(VERDE"%lf"RESET"\n\n", $1);
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | cmnd '\n'         {
                                if (isnan($1) && !error) {
                                    lanzar_error("NAN_DETECTADO");
                                }
                                if (!script) {
                                    printf(CYAN">"RESET" ");
                                }
                                error = false;
                            }
        | cmnd ';' '\n'         {
                                    if (isnan($1) && !error) {
                                        lanzar_error("NAN_DETECTADO");
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
        | fnc '\n'          {
                                if (!error) {
                                    if (isnan($1)) {
                                        lanzar_error("NAN_DETECTADO");
                                    } else if (hacerEcho) {
                                        printf(VERDE"%lf"RESET"\n\n", $1);
                                    }
                                }
                                if (!script) {
                                    printf(CYAN">"RESET" ");
                                }
                                error = false;
                            }
        | fnc ';' '\n'       {
                                    if (!error) {
                                        if (isnan($1)) {
                                            lanzar_error("NAN_DETECTADO");
                                        } else if (hacerEcho) {
                                            printf(VERDE"%lf"RESET"\n\n", $1);
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }

;

exp:    NUM
        | CONST         {
                            c = buscar_elemento($1);
                            $$ = c.valor.var;
                            free($1);
                        }
        | VAR           {
                            if ((c = buscar_elemento($1)).lexema != NULL) {
                                $$ = c.valor.var;
                            } else {
                                lanzar_error("VARIABLE_NON_DEFINIDA");
                                error = true;
                                $$ = NAN;
                            }
                            free($1);
                        }
        | '-' exp %prec NEG {
                                 if (!isnan($2)) {
                                     $$ = -$2;
                                 } else {
                                     $$ = NAN;
                                 }
                            }
        | exp '+' exp   {
                            if (!isnan($1) && !isnan($3)) {
                                $$ = $1 + $3;
                            } else {
                                $$ = NAN;
                            }
                        }
        | exp '-' exp   {
                            if (!isnan($1) && !isnan($3)) {
                                $$ = $1 - $3;
                            } else {
                                $$ = NAN;
                            }
                        }
        | exp '*' exp   {
                            if (!isnan($1) && !isnan($3)) {
                                $$ = $1 * $3;
                            } else {
                                $$ = NAN;
                            }
                        }
        | exp '/' exp   {
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
        | exp '%' exp   {
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
        | exp '^' exp   {
                            if (!isnan($1) && !isnan($3)) {
                                $$ = pow($1, $3);
                            } else {
                                $$ = NAN;
                            }
                        }
        | '(' exp ')'   {
                             if (!isnan($2)) {
                                 $$ = $2;
                             } else {
                                 $$ = NAN;
                             }
                         }
;

asig:   VAR '=' exp     {
                           if (!error) {
                               if ((c = buscar_elemento($1)).lexema != NULL) {
                                   //modificarValorVariable($1, $3);
                               } else {
                                   c.lexema = strdup($1);
                                   c.comp_lexico = VAR;
                                   c.valor.var = $3;
                                   insertar_elemento(c);
                                   free(c.lexema);
                               }
                           }
                           $$ = $3;
                           free($1);
                        }
        | VAR '=' fnc   {
                           if (!error) {
                               if ((c = buscar_elemento($1)).lexema != NULL) {
                                   //modificarValorVariable($1, $3);
                               } else {
                                   c.lexema = strdup($1);
                                   c.comp_lexico = VAR;
                                   c.valor.var = $3;
                                   insertar_elemento(c);
                                   free(c.lexema);
                               }
                           }
                           $$ = $3;
                           free($1);
                        }
        | CONST '=' exp {
                            lanzar_error("CONSTANTE_NON_MODIFICABLE");
                            error = true;
                            $$ = NAN;
                            free($1);
                        }
        | CONST '=' fnc {
                            lanzar_error("CONSTANTE_NON_MODIFICABLE");
                            error = true;
                            $$ = NAN;
                            free($1);
                        }
;

cmnd:   CMND0                       {
                                        c = buscar_elemento($1);
                                        free($1);
                                        (*(c.valor.funcptr))();
                                    }
        | CMND0 '(' ')'             {
                                        c = buscar_elemento($1);
                                        free($1);
                                        (*(c.valor.funcptr))();
                                    }
        | CMND1                     {
                                        lanzar_error("ARCHIVO_NON_INDICADO");
                                        error = true;
                                        $$ = NAN;
                                        free($1);
                                    }
        | CMND1 '(' ')'             {
                                        lanzar_error("ARCHIVO_NON_INDICADO");
                                        error = true;
                                        $$ = NAN;
                                        free($1);
                                    }
        | CMND1 ARCHIVO            {
                                        c = buscar_elemento($1);
                                        (*(c.valor.funcptr))($2);
                                        free($1);
                                        free($2);
                                    }
        | CMND1 '(' ARCHIVO ')'    {
                                        c = buscar_elemento($1);
                                        (*(c.valor.funcptr))($3);
                                        free($1);
                                        free($3);
                                    }
        | CMND1 exp                 {
                                        lanzar_error("ARCHIVO_MAL_FORMATO");
                                        error = true;
                                        $$ = NAN;
                                        free($1);
                                    }
;

fnc:    LIB '/' VAR '(' exp ')'             {
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
        | LIB '/' VAR '(' exp ',' exp ')'   {
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
        | LIB '/' VAR '(' ')'               {
                                                /*
                                                lanzar_error("PARAMETROS_NON_INDICADOS");
                                                error = true;
                                                $$ = NAN;
                                                free($1);
                                                free($3);
                                                */
                                            }
        | exp '(' exp ')'                   {
                                                /*
                                                lanzar_error("LIBRERIA_NON_ATOPADA");
                                                error = true;
                                                $$ = NAN;
                                                */
                                            }
        | exp '(' exp ',' exp ')'           {
                                                /*
                                                lanzar_error("LIBRERIA_NON_ATOPADA");
                                                error = true;
                                                $$ = NAN;
                                                */
                                            }
        | exp '(' ')'                       {
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
}


