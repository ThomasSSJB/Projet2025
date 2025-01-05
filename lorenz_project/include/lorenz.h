#ifndef LORENZ_H
#define LORENZ_H

#include "dynamic_system.h"

struct LorenzParams{
    double sigma;
    double rho;
    double beta;
};


void initialise_lorenz() ;

void actualise_lorenz(void *params, double *x, double *y, double *z, double dt);

#endif
