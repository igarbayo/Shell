cmake_minimum_required(VERSION 3.30)
project(P1_CompGo C)

set(CMAKE_C_STANDARD 11)


add_executable(P1_CompGo main.c
        interprete.h
        avl.c
        avl.h
        tabla_simbolos.c
        tabla_simbolos.h
        errores.c
        errores.h
        flex.yy.c
        bison.tab.c
        bison.tab.h
        interprete.c
        comandos.h
        comandos.c
        pila.c
        pila.h
)

target_link_libraries(P1_CompGo m)
