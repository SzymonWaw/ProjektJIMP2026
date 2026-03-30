CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -lm
OBJ = main.o file.o alg.o
TARGET = graf.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	del $(OBJ) $(TARGET)