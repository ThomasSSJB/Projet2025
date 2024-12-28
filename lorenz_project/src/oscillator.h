#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include "dynamic_system.h"

typedef struct {
    double omega;
} OscillatorParams;

void initialise_oscillator(void *params);


void actualise_oscillator(void *params, double *x, double *y, double *z, double dt);

#endif