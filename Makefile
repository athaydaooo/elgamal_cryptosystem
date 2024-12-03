# Definindo o compilador e as flags
CC = gcc
CFLAGS = -Wall -g
LIBS = -lgmp

# Diretórios de origem e inclusão
SRCDIR = src
INCDIR = include

# Arquivos objeto
OBJ = $(SRCDIR)/elgamal.o $(SRCDIR)/utils.o $(SRCDIR)/main.o

# Nome do executável
TARGET = elgamal

# Regra padrão para compilar
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

# Regras para compilar os arquivos objeto
$(SRCDIR)/elgamal.o: $(SRCDIR)/elgamal.c $(INCDIR)/elgamal.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $(SRCDIR)/elgamal.c -o $(SRCDIR)/elgamal.o

$(SRCDIR)/utils.o: $(SRCDIR)/utils.c $(INCDIR)/utils.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $(SRCDIR)/utils.c -o $(SRCDIR)/utils.o

$(SRCDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/elgamal.h $(INCDIR)/utils.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $(SRCDIR)/main.c -o $(SRCDIR)/main.o

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJ) $(TARGET)
