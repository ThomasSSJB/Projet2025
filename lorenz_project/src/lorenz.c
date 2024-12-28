#include "lorenz.h"
#include "stdio.h"

void initialise_lorenz(void *params){
    LorenzParams *p = (LorenzParams *)params;
     printf("Entrez les paramètres pour les équations de Lorenz :\n");
    printf("σ (sigma) : ");
    scanf("%lf", &p->sigma);

    printf("ρ (rho) : ");
    scanf("%lf", &p->rho);

    printf("β (beta) : ");
    scanf("%lf", &p->beta);
}

void actualise_lorenz(void *params, double *x, double *y, double *z, double dt){
    LorenzParams *p = (LorenzParams *)params;
    double dx = p->sigma * (*y - *x);
    double dy = *x * (p->rho - *z) - *y;
    double dz = *x * *y - p->beta * *z;

    *x += dx * dt;
    *y += dy * dt;
    *z += dz * dt;
}
