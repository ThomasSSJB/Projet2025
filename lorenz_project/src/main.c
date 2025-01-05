#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dynamic_system.h"
#include "lorenz.h"
#include "van_der_pol.h"
#include "oscillator.h"

int main() {
    //étape "a" : Allocation mémoire pour les paramètres de chaque système dynamique
    struct LorenzParams *lorenz_params = (struct LorenzParams *)malloc(sizeof(struct LorenzParams));
    struct VanDerPolParams *van_der_pol_params = (struct VanDerPolParams *)malloc(sizeof(struct VanDerPolParams));
    struct OscillatorParams *oscillator_params = (struct OscillatorParams *)malloc(sizeof(struct OscillatorParams));

    // étape "b" : Vérification des erreurs d'allocation mémoire
    if (!lorenz_params || !van_der_pol_params || !oscillator_params) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return EXIT_FAILURE;
    }

    // étape "c" : Allocation mémoire pour le tableau des systèmes dynamiques
    struct DynamicSystem *systems = (struct DynamicSystem *)malloc(3 * sizeof(struct DynamicSystem));
    if (!systems) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        free(lorenz_params);
        free(van_der_pol_params);
        free(oscillator_params);
        return EXIT_FAILURE;
    }

    // étape "d" : Initialisation des systèmes dynamiques avec leurs paramètres et fonctions spécifiques
    systems[0].name = "Équations de Lorenz";
    systems[0].init_params = initialise_lorenz;
    systems[0].update = actualise_lorenz;
    systems[0].params = lorenz_params;

    systems[1].name = "Van der Pol";
    systems[1].init_params = initialise_van_der_pol;
    systems[1].update = actualise_van_der_pol;
    systems[1].params = van_der_pol_params;

    systems[2].name = "Oscillateur Harmonique";
    systems[2].init_params = initialise_oscillator;
    systems[2].update = actualise_oscillator;
    systems[2].params = oscillator_params;

    int num_systems = 3; // Nombre de systèmes dynamiques disponibles

    // étape "e" : Affichage des systèmes disponibles pour l'utilisateur
    printf("Choisissez un système dynamique :\n");
    for (int i = 0; i < num_systems; i++) {
        printf("%d. %s\n", i + 1, systems[i].name);
    }

    int choice;
    scanf("%d", &choice); // L'utilisateur choisit un système

    // étape "f" : Vérification de la validité du choix de l'utilisateur
    if (choice < 1 || choice > num_systems) {
        printf("Choix invalide.\n");
        free(lorenz_params);
        free(van_der_pol_params);
        free(oscillator_params);
        free(systems);
        return EXIT_FAILURE;
    }

    // étape "g" : Initialisation des paramètres du système choisi
    struct DynamicSystem *system = &systems[choice - 1];
    system->init_params(system->params);

    double x, y, z, dt, t_max;

    // étape "h" : Entrée des valeurs initiales par l'utilisateur (position initiale et paramètres de simulation)
    printf("Entrez la position initiale (x y z) : ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("Entrez l'incrément de temps dt : ");
    scanf("%lf", &dt);

    printf("Entrez le temps maximal t_max : ");
    scanf("%lf", &t_max);

    // étape "i" : Calcul du nombre de pas de simulation et ouverture du fichier de sortie
    int steps = (int)(t_max / dt); // Nombre d'itérations de simulation
    FILE *data_file = fopen("test/simulation.dat", "w");

    if (!data_file) {
        fprintf(stderr, "Erreur : impossible de créer le fichier de sortie.\n");
        free(lorenz_params);
        free(van_der_pol_params);
        free(oscillator_params);
        free(systems);
        return EXIT_FAILURE;
    }

    // En-tête du fichier de données (le format des résultats)
    fprintf(data_file, "# t x y z dx dy dz vitesse\n");

    
    double t = 0.0;
    double prev_x = x, prev_y = y, prev_z = z;

    // étape "j" : Simulation et écriture des résultats dans le fichier
    for (int i = 0; i <= steps; i++) {
    
        // Calcul des vitesses (dérivées) à chaque itération
        double dx = (x - prev_x) / dt;
        double dy = (y - prev_y) / dt;
        double dz = (z - prev_z) / dt;
        double vitesse = sqrt(dx * dx + dy * dy + dz * dz); // Calcul de la vitesse à partir des dérivées
        
        // Écriture des résultats dans le fichier de données
        if (fprintf(data_file, "%lf %lf %lf %lf %lf %lf %lf %lf\n", 
                    t, x, y, z, dx, dy, dz, vitesse) < 0) {
            fprintf(stderr, "Erreur d'écriture dans le fichier.\n");
            fclose(data_file);
            free(lorenz_params);
            free(van_der_pol_params);
            free(oscillator_params);
            free(systems);
            return EXIT_FAILURE;
        }

        // Mise à jour des anciennes valeurs de position pour le prochain calcul de dérivées
        prev_x = x;
        prev_y = y;
        prev_z = z;

        // Mise à jour des positions du système en fonction des équations du système choisi
        system->update(system->params, &x, &y, &z, dt);

        t += dt; // Avancer le temps
    }

    // étape "k" : Fermeture du fichier et affichage de la fin de la simulation
    fclose(data_file);
    printf("Simulation terminée. Résultats dans 'test/simulation.dat'.\n");

   
    // Libération de la mémoire allouée pour éviter les fuites de mémoire
    free(lorenz_params);
    free(van_der_pol_params);
    free(oscillator_params);
    free(systems);

    return 0;
}
