#include "stdio.h"
#include "stdlib.h"
#include "dynamic_system.h"
#include "lorenz.h"
#include "van_der_pol.h"
#include "oscillator.h"


void write_coordinates(FILE *file, double t, double x, double y, double z) {
    fprintf(file, "%lf %lf %lf %lf\n", t, x, y, z);
}


int main() {
    
    LorenzParams lorenz_params;
    VanDerPolParams van_der_pol_params;
    OscillatorParams oscillator_params;

    DynamicSystem systems[] = {
        {"Équations de Lorenz", initialise_lorenz, actualise_lorenz, &lorenz_params},
        {"Van der Pol", initialise_van_der_pol, actualise_van_der_pol, &van_der_pol_params},
        {"Oscillateur Harmonique", initialise_oscillator, actualise_oscillator, &oscillator_params}
    };

    int num_systems = sizeof(systems) / sizeof(DynamicSystem);

    
    printf("Choisissez un système dynamique :\n");
    for (int i = 0; i < num_systems; i++) {
        printf("%d. %s\n", i + 1, systems[i].name);
    }

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > num_systems) {
        printf("Choix invalide.\n");
        return EXIT_FAILURE;
    }

    DynamicSystem *system = &systems[choice - 1];
    system->init_params(system->params);

   
    double x, y, z, dt, t_max;
    printf("Entrez la position initiale (x y z) : ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("Entrez l'incrément de temps dt : ");
    scanf("%lf", &dt);

    printf("Entrez le temps maximal t_max : ");
    scanf("%lf", &t_max);

    int steps = (int)(t_max / dt);
    FILE * output_file = fopen("output/simulation.dat", "w");

    if (!output_file) {
        fprintf(stderr, "Erreur dans le code ");
        return EXIT_FAILURE;
    }

    double t = 0.0;
    for (int i = 0; i <= steps; i++) {
        write_coordinates(output_file, t, x, y, z);
        system->update(system->params, &x, &y, &z, dt);
        t += dt;
    }

    fclose(output_file);
    printf("Simulation terminée. Résultats dans 'output/simulation.dat'.\n");

    return 0;
}



