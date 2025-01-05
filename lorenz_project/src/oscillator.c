#include "../include/oscillator.h"
#include <stdio.h>

void initialise_oscillator(void *params){
    struct OscillatorParams *p = (struct OscillatorParams *)params;
    printf("Entrez les paramètres pour l'oscillateur harmonique :\n");
    printf("ω (omega) : ");
    scanf("%lf", &p->omega);
}

void actualise_oscillator(void *params, double *x, double *y, double *z, double dt){
    struct OscillatorParams *p = (struct OscillatorParams *)params;
    double dx = *y;
    double dy = -p->omega * p->omega * (*x);

    *x += dx * dt;
    *y += dy * dt;
}
