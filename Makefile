CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -lm
OBJ = src/main.o src/file.o
TARGET = graf.exe

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
    $(CC) -c -o $@ $< $(CFLAGS)

clean:
    del $(OBJ) $(TARGET)