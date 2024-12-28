CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS =
SRC = src/main.c src/lorenz.c src/oscillator.c src/van_der_pol.c src/file_io.c
OBJ = $(SRC:.c=.o)
TARGET = lorenz


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


run: all
	./$(TARGET)


clean:
	rm -f $(OBJ) $(TARGET)