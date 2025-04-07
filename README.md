# Intérprete shell escrito en C
Como parte de la asignatura de **Compiladores e Interprétes**, del Grado en Ingeniería Informática, 
se desarrolla un intérprete de comandos tipo _shell_, similar a las consolas de R, Python o Matlab.

## Herramientas utilizadas
El análisis léxico se realizará con Flex y el análisis sintáctico con Bison.

## Sintaxis básica
La sintaxis general de las asignaciones es `variable = expresion` y la de las llamada (comandos o funciones) es
`llamada([argumentos])`. Los comandos que no tienen argumentos pueden ser llamados como `comando()`.

## Funcionalidades
El intérprete matemático desarrollado en C incluye las siguientes funcionalidades:

1. **Variables**. El intérprete permite el uso de variables para almacenar valores numéricos.

2. **Operaciones con variables**. Se pueden realizar operaciones matemáticas con variables ya definidas.

3. **Precedencia de operaciones y ()**. El intérprete respeta la precedencia de las operaciones matemáticas
   estándar y el uso de paréntesis para agrupar expresiones.

4. **Funciones estáticas trigonométricas y exponenciales**. Se incluyen funciones trigonométricas como `sin()`,
    `cos()`, `tan()`, etc., y funciones exponenciales como `exp()` y `log()`.

5. **Constantes predefinidas**. El valor de las constantes `E` y `PI` está predefinido 
    y no puede ser reasignado.

6. **clear**. La función `clear()` elimina todas las variables almacenadas, mientras que `clear(var)` elimina 
    una variable específica.

7. **workspace**. La función `workspace()` muestra una lista de todas las variables definidas en el intérprete.

8. Las variables solo se almacenan en el espacio de trabajo si han sido definidas correctamente.

9. **quit**. La función `quit()` termina la ejecución del intérprete.

10. **help**. Los usuarios pueden obtener ayuda sobre cualquier comando usando `help()`, `help`, `?`, `?()`, o `? COMANDO`.

11. **echo(on/off)**. Se puede activar o desactivar la visualización de resultados en las sentencias de asignación
     usando `echo(on)` o `echo(off)`, así como consultar el estado del echo con `echo()` o `echo`.

12. **load desde fichero**
    - El intérprete permite cargar comandos desde un archivo utilizando la función `load()`.

13. **Error sintáctico no termina el programa**
    - Los errores sintácticos no provocan la terminación del programa, permitiendo continuar con la ejecución después de un error.

14. **Funciones con un array**. Se incluyen funciones que operan sobre arrays de argumentos:, como `max()`,
     `min()`, `media()`, `var()`, `sum()`, `prod()`, `argmin()` y `argmax()`.
    - **Nota**. Los índices devueltos por estas funciones comienzan en 0.

15. Las funciones pueden ser usadas dentro de expresiones matemáticas como cualquier otro valor.

16. **clear (probar por terminal)**. La función de limpiar la pantalla permite borrar el contenido de la terminal.

17. **ANS**. La palabra clave `ANS` puede ser utilizada para acceder al último resultado impreso por el intérprete.

18. **Loads recursivos**. El intérprete permite ejecutar scripts que incluyen cargas recursivas de otros scripts,
     utilizando una pila para gestionar las llamadas. La sintaxis es `load(RUTA)` o `load(ARCHIVO)` si el escript
     se encuentra en la carpeta del fichero ejecutable.

19. **Sentencias de verdad**. Se incluyen sentencias de comparación lógica (`<`, `>`, `<=`, `>=`, `==`, `!=`).

20. **Tolerancia con el 0**. El intérprete cuenta con una tolerancia de `1.e-6` para todas las comparaciones con
     el valor 0, que se puede consultar en la constante `TOL`.

20. **Import de librería dinámico**. Se permite importar librerías de forma dinámica para ejecutar funciones 
     sin argumentos, funciones con un argumento de tipo `double`, o funciones que toman un array que termina en
     `NAN`, devolviendo un valor de tipo `double`. La sintaxis es `import(RUTA)`. Las funciones de una librería
     `LIB` que se carga de forma dinámica son accesibles mediante la sintaxis `LIB/funcion([argumentos]`. Esto
     diferenciar posibles funciones con el mismo nombre definidas en librerías distintas.


## Compilación y ejecución

- Para compilar todo, colócate en la carpeta con los archivos y ejecuta: `make`.

- Para ejecutar sin script de entrada inicial, escribe: `P3_Bison`.

- Para ejecutar con `<nombre_fichero>`, haz: `./P3_Bison <nombre_fichero>`.

- Si quieres verificar el buen uso de memoria, ejecuta, con valgrind previamente instalado: `valgrind ./P3_Bison
   <nombre_fichero>`.

- Para borrar los archivos objeto y el ejecutable, en la misma carpeta, haz: `make clean`.
