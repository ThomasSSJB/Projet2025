#include "van_der_pol.h"
#include "stdio.h"

void initialise_van_der_pol(void *params){
    VanDerPolParams *p = (VanDerPolParams *)params;
    printf("Entrez les paramètres pour l'oscillateur de Van der Pol :\n");
    printf("μ (mu) : ");
    scanf("%lf", &p->mu);
}

void actualise_van_der_pol(void *params, double *x, double *y,double *z, double dt){
    VanDerPolParams *p = (VanDerPolParams *)params;
    double dx = *y;
    double dy = p->mu * (1 - (*x) * (*x)) * (*y) - *x;

    *x += dx * dt;
    *y += dy * dt;
}
