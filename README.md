# Intérprete shell escrito en C
Como parte de la asignatura de **Compiladores e Interprétes**, del Grado en Ingeniería Informática, 
se desarrolla un intérprete de comandos tipo _shell_, similar a las consolas de R, Python o Matlab.

## Herramientas utilizadas
El análisis léxico se realizará con Flex y el análisis sintáctica con Bison.

## Versiones

### Versión básica
Inicialmente, procesará entradas matemáticas y soportará operaciones de tipo numérico. Podrá incluir 
la definición de funciones y deberá manejar el espacio de trabajo, mediante las directivas `load()`, 
`quit()`, `help()`, `workspace()`, `clear()`, `clean()` o `echo`.

### Versión _premium_
El objetivo final es incorporar a la funcionalidad anterior la capacidad de cargar librerías en el
programa de forma dinámica, utilizando `dlfcn.h`.