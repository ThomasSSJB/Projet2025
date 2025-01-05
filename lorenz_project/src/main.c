#include <stdio.h>
#include <stdlib.h>
#include "dynamic_system.h"
#include "lorenz.h"
#include "van_der_pol.h"
#include "oscillator.h"
#include <math.h>

int main() {
    struct LorenzParams *lorenz_params = (struct LorenzParams *)malloc(sizeof(struct LorenzParams));
    struct VanDerPolParams *van_der_pol_params = (struct VanDerPolParams *)malloc(sizeof(struct VanDerPolParams));
    struct OscillatorParams *oscillator_params = (struct OscillatorParams *)malloc(sizeof(struct OscillatorParams));

    if (!lorenz_params || !van_der_pol_params || !oscillator_params) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return EXIT_FAILURE;
    }

    struct DynamicSystem *systems = (struct DynamicSystem *)malloc(3 * sizeof(struct DynamicSystem));
    if (!systems) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        free(lorenz_params);
        free(van_der_pol_params);
        free(oscillator_params);
        return EXIT_FAILURE;
    }

   
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

    int num_systems = 3;

    
    printf("Choisissez un système dynamique :\n");
    for (int i = 0; i < num_systems; i++) {
        printf("%d. %s\n", i + 1, systems[i].name);
    }

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > num_systems) {
        printf("Choix invalide.\n");
        free(lorenz_params);
        free(van_der_pol_params);
        free(oscillator_params);
        free(systems);
        return EXIT_FAILURE;
    }

    struct DynamicSystem *system = &systems[choice - 1];
    system->init_params(system->params);

    double x, y, z, dt, t_max;
    printf("Entrez la position initiale (x y z) : ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("Entrez l'incrément de temps dt : ");
    scanf("%lf", &dt);

    printf("Entrez le temps maximal t_max : ");
    scanf("%lf", &t_max);

    int steps = (int)(t_max / dt);
    FILE *data_file = fopen("test/simulation.dat", "w");

    if (!data_file) {
        fprintf(stderr, "Erreur : impossible de créer le fichier de sortie.\n");
        free(lorenz_params);
        free(van_der_pol_params);
        free(oscillator_params);
        free(systems);
        return EXIT_FAILURE;
    }

    double t = 0.0, prev_x = x, prev_y = y, prev_z = z;

    
    for (int i = 0; i <= steps; i++) {
        system->update(system->params, &x, &y, &z, dt);

       
        double dx = (x - prev_x) / dt;
        double dy = (y - prev_y) / dt;
        double dz = (z - prev_z) / dt;
        
        
        double vitesse = sqrt(dx*dx + dy*dy + dz*dz);

       
        fprintf(data_file, "%lf %lf %lf %lf %lf\n", t, x, y, z, vitesse);

        
        prev_x = x;
        prev_y = y;
        prev_z = z;
        t += dt;
    }

    fclose(data_file);
    printf("Simulation terminée. Résultats dans 'test/simulation.dat'.\n");

   
    free(lorenz_params);
    free(van_der_pol_params);
    free(oscillator_params);
    free(systems);

    return 0;
}
