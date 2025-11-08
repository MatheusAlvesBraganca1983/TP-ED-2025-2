# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall

# Arquivos fonte
SRCS = main.c time.c partida.c bd_times.c bd_partidas.c

# Objetos gerados
OBJS = $(SRCS:.c=.o)

# Nome do executável
TARGET = campeonato

# Targets "falsos"
.PHONY: all compile run clean

# Alvo padrão: compila e executa
all: compile run

# Compila o projeto
compile: $(TARGET)

# Executa o binário
run: $(TARGET)
	./$(TARGET)

# Limpa arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para linkar todos os objetos no executável final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)