CC = gcc
CFLAGS = -g -Wall -Iinclude
LDFLAGS = -lgmp
SRC = src/main.c src/encrypt.c src/decrypt.c
OBJ = $(SRC:.c=.o)
OUT = bin/program

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)