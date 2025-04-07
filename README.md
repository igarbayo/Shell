# Intérprete shell escrito en C
Como parte de la asignatura de **Compiladores e Interprétes**, del Grado en Ingeniería Informática, 
se desarrolla un intérprete de comandos tipo _shell_, similar a las consolas de R, Python o Matlab.

## Herramientas utilizadas
El análisis léxico se realizará con Flex y el análisis sintáctico con Bison.

## Funcionalidades
El intérprete matemático desarrollado en C incluye las siguientes funcionalidades:

1. **Variables**
    - El intérprete permite el uso de variables para almacenar valores numéricos.

2. **Operaciones con variables**
    - Se pueden realizar operaciones matemáticas con variables ya definidas.

3. **Precedencia de operaciones y ()**
    - El intérprete respeta la precedencia de las operaciones matemáticas estándar y el uso de paréntesis para agrupar expresiones.

4. **Funciones estáticas trigonométricas y exponenciales**
    - Se incluyen funciones trigonométricas como `sin()`, `cos()`, `tan()`, etc., y funciones exponenciales como `exp()` y `log()`.

5. **Constantes predefinidas E y PI sin poder reasignar**
    - El valor de las constantes `E` y `PI` está predefinido y no puede ser reasignado.

6. **clear() elimina todas y clear(var) elimina var**
    - La función `clear()` elimina todas las variables almacenadas, mientras que `clear(var)` elimina una variable específica.

7. **workspace() muestra las variables guardadas**
    - La función `workspace()` muestra una lista de todas las variables definidas en el intérprete.

8. **Solo se almacenan en el workspace las variables definidas correctamente**
    - Las variables solo se almacenan en el espacio de trabajo si han sido definidas correctamente.

9. **quit() cierra el intérprete**
    - La función `quit()` termina la ejecución del intérprete.

10. **help(), help, ?, ?() o ? COMANDO**
    - Los usuarios pueden obtener ayuda sobre cualquier comando usando `help()`, `help`, `?`, `?()`, o `? COMANDO`.

11. **echo(on/off) en sentencias de asignación**
    - Se puede activar o desactivar la visualización de resultados en las sentencias de asignación usando `echo(on)` o `echo(off)`.

12. **load desde fichero**
    - El intérprete permite cargar comandos desde un archivo utilizando la función `load()`.

13. **Error sintáctico no termina el programa**
    - Los errores sintácticos no provocan la terminación del programa, permitiendo continuar con la ejecución después de un error.

14. **Funciones con un array de argumentos (max, min, media, var, sum, prod, argmin, argmax)**
    - Se incluyen funciones que operan sobre arrays de argumentos:
        - `max()`, `min()`, `media()`, `var()`, `sum()`, `prod()`, `argmin()`, `argmax()`
    - **NOTA:** Los índices devueltos por estas funciones comienzan en 0.

15. **Las funciones se pueden usar como partes de expresiones**
    - Las funciones pueden ser usadas dentro de expresiones matemáticas como cualquier otro valor.

16. **clear de la pantalla (probar por terminal)**
    - La función de limpiar la pantalla permite borrar el contenido de la terminal.

17. **ANS para último resultado (impreso)**
    - La palabra clave `ANS` puede ser utilizada para acceder al último resultado impreso por el intérprete.

18. **script con loads recursivos, con una pila**
    - El intérprete permite ejecutar scripts que incluyen cargas recursivas de otros scripts, utilizando una pila para gestionar las llamadas.

19. **Sentencias de verdad (<, >, <=, >=, ==, !=), con tolerancia de 1.e-6 consultable como constante TOL**
    - Se incluyen sentencias de comparación lógica (`<`, `>`, `<=`, `>=`, `==`, `!=`), con una tolerancia de `1.e-6` para todas las comparaciones con el valor 0, que se puede consultar como la constante `TOL`.

20. **Import de librería dinámica, para funciones sin argumentos, 1 argumento double, o 1 array que termina en NAN, devolviendo un double**
    - Se permite importar librerías dinámicas para ejecutar funciones sin argumentos, funciones con un argumento de tipo `double`, o funciones que toman un array que termina en `NAN`, devolviendo un valor de tipo `double`.


## Versiones

### Versión básica
Inicialmente, procesará entradas matemáticas y soportará operaciones de tipo numérico. Podrá incluir 
la definición de funciones y deberá manejar el espacio de trabajo, mediante las directivas `load()`, 
`quit()`, `help()`, `workspace()`, `clear()`, `clean()` o `echo`.

### Versión _premium_
El objetivo final es incorporar a la funcionalidad anterior la capacidad de cargar librerías en el
programa de forma dinámica, utilizando `dlfcn.h`.
