%{
#include "bison.tab.h" // Incluir los tokens generados por Bison
#include <stdio.h>
#include <stdlib.h>
#include "tabla_simbolos.h"
#include "errores.h"
#include <string.h>
#include <math.h>
#include "pila.h"
#include "interprete.h"
%}


/*
 Indícase que só se lerá un ficheiro de entrada,
 que se creará un ficheiro cabeceira chamado lex.yy.h e
 que non se creará nin a función input nin yyunput.
 Estas dúas últimas opcións son para evitar warnings de compilación.
*/
%option noyywrap header-file="flex.yy.h" noinput nounput


/* Auxiliares */
LETRA        		[a-zA-Z_]|_
IDENTIFICADOR  		{LETRA}({LETRA}|{DIGITO})*

/* Numeros */
DIGITO       		[0-9]
DIGITOS             {DIGITO}({DIGITO})*
EXPONENTE           [eE][+-]?{DIGITOS}+
ENTERO              {DIGITOS}
DECIMAL             ({DIGITOS}\.?{DIGITOS}?{EXPONENTE}?)|\.({DIGITOS}+{EXPONENTE}?)

/* Comentarios */
COMENTARIO_UNA      \/\/.*$
COMENTARIO_MULTI    \/\*(.|\n)*\*\/

/* Componentes lexicos */
TABULADO        [ \t]
SIMBOLO         [\+\-\*\/^=\(\)\{\},;\r\n]
NUM             {ENTERO}|{DECIMAL}
ARCHIVO         ({LETRA}|{DIGITO})+(\.({LETRA}|{DIGITO})+)+|(\/({LETRA}|{DIGITO})*)*\/({LETRA}|{DIGITO})+(\.({LETRA}|{DIGITO})+)+

/* Errores léxicos */
ERROR_UNDER_DIGITOS		{DIGITO}+[_]([^0-9 ,])*|{DIGITO}+[_](\.[0-9]+)|{DIGITO}+\.[_][0-9]+|({DIGITOS}\.?{DIGITOS}?[_]{EXPONENTE}?)|\.({DIGITOS}+[_]{EXPONENTE}?)
ERROR_UNDER_VARIOS		{DIGITO}+[_][_]+{DIGITO}*


%%

{TABULADO}
{COMENTARIO_UNA}
{COMENTARIO_MULTI}

{NUM}           {
                    yylval.numero = atof(yytext);
                    return NUM;
                }

{SIMBOLO}       {
                    return (int) *yytext;
                }
{ARCHIVO}       {
                    yylval.cadena = strdup(yytext);
                    return ARCHIVO;
                }

"def"    { return DEF; }
"return" { return RETURN; }

{IDENTIFICADOR} {
                    yylval.cadena = strdup(yytext);
                    contenedor c = buscar_elemento(yylval.cadena);
                    if (c.lexema != NULL) {
                        return c.comp_lexico;
                    } else {
                        return VARIABLE;
                    }
                }

\?               {
                    yylval.cadena = strdup(yytext);
                    contenedor c = buscar_elemento(yylval.cadena);
                    if (c.lexema != NULL) {
                        return c.comp_lexico;
                    } else {
                        return VARIABLE;
                    }
                }


{ERROR_UNDER_DIGITOS}	{ lanzar_error("\"_\" debe separar dos dígitos"); }
{ERROR_UNDER_VARIOS}	{ lanzar_error("no puede haber dos o más \"_\" seguidas"); }


<<EOF>>	{
                        if (yyin != stdin) {  // Si estamos leyendo desde un archivo
                            unload(tope_wrapper()); // elimina el fichero actual de la pika
                            if (!esVaciaPila_wrapper()) {   // si quedan ficheros inacabados
                                yyin = tope_wrapper();      // carga el último
                            } else {
                                yyin = stdin;       // carga la entrada estándar
                            }
                            yyrestart(yyin);   // Reinicia el analizador léxico
                            ejecutar_script(0);
                        } else {
                            return 0;  // Indica a Bison que finalice
                        }
        }
.                     { printf("UNKNOWN: %s\n", yytext); }

%%

/* Código adicional después de la sección de reglas */
void liberar_recursos() {
    yy_delete_buffer(YY_CURRENT_BUFFER);
    yylex_destroy();
}



