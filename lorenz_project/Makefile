# Définition des variables
EXEC = bin/prog
SRC = src/main.c src/lorenz.c src/oscillator.c src/van_der_pol.c
OBJ = lib/main.o lib/lorenz.o lib/oscillator.o lib/van_der_pol.o
FLAGS = -Wall -ggdb -Iinclude

# Règle principale
all: $(EXEC)

# Génération de l'exécutable à partir des fichiers objets
$(EXEC): $(OBJ)
	gcc $^ -o $@ $(FLAGS)
	@echo "Exécutable généré : $(EXEC)"

# Génération des fichiers objets à partir des fichiers sources
lib/%.o: src/%.c
	gcc -c $< -o $@ $(FLAGS)
	@echo "Compilation : $< -> $@"

# Lancement de l'exécutable
run: all
	./$(EXEC)
