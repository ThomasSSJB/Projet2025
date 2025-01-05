#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include "dynamic_system.h"

struct OscillatorParams {
    double omega;
} ;

void initialise_oscillator(void *params);


void actualise_oscillator(void *params, double *x, double *y, double *z, double dt);

#endif
