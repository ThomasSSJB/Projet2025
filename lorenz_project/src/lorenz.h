#ifndef LORENZ_H
#define LORENZ_H

#include "dynamic_system.h"

typedef struct{
    double sigma;
    double rho;
    double beta;
}LorenzParams;


void initialise_lorenz(void *params);

void actualise_lorenz(void *params, double *x, double *y, double *z, double dt);

#endif