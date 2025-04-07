# Nombre del ejecutable
TARGET = P3_Bison

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -g

# Archivos fuente y headers
SRCS = main.c \
       avl.c \
       tabla_simbolos.c \
       errores.c \
       flex.yy.c \
       bison.tab.c \
       interprete.c \
       comandos.c \
       pila.c

HEADERS = definiciones.h \
          avl.h \
          tabla_simbolos.h \
          errores.h \
          flex.yy.h \
          bison.tab.h \
          interprete.h \
          comandos.h \
          pila.h

# Objetos generados
OBJS = $(SRCS:.c=.o)

# Regla principal
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lm

# Regla para compilar archivos .c a .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para generar go.yy.c con Flex
flex.yy.c: flex.l
	flex -o flex.yy.c flex.l

# Regla para generar bison.tab.c con Bison
bison.tab.c bison.tab.h: bison.y
	bison -d -o bison.tab.c bison.y

# Limpiar archivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

# Limpiar todo incluyendo archivos de depuración
cleanall: clean
	rm -f *~
