#ifndef VAN_DER_POL_H
#define VAN_DER_POL_H
#include "dynamic_system.h"

typedef struct {
    double mu;
} VanDerPolParams;

void initialise_van_der_pol(void *params);

void actualise_van_der_pol(void *params, double *x, double *y,double *z, double dt);

#endif