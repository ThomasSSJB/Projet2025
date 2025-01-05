EXEC = bin/prog
SRC = src/main.c src/lorenz.c src/oscillator.c src/van_der_pol.c
OBJ = lib/main.o lib/lorenz.o lib/oscillator.o lib/van_der_pol.o
FLAGS = -Wall -ggdb -Iinclude

all: $(EXEC)

$(EXEC): $(OBJ)
	gcc $^ -o $@ $(FLAGS)
	@echo "Exécutable généré : $(EXEC)"

lib/%.o: src/%.c
	gcc -c $< -o $@ $(FLAGS)
	@echo "Compilation : $< -> $@"

run: all
	./$(EXEC)
