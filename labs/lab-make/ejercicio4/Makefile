# Nombre del ejecutable final
PROGRAMA = programa

# Compilador y flags
CC = gcc
CFLAGS = -Wall

# TODO 1
SRCS = main.c operaciones.c

# TODO 2
OBJS = $(SRCS:.c=.o)

# Regla principal
all: $(PROGRAMA)

# TODO 3: linkeo
$(PROGRAMA): $(OBJS)
	$(CC) $^ -o $(PROGRAMA)

# TODO 4: regla de patrón
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(PROGRAMA) $(OBJS)

# TODO 5
.PHONY: all clean