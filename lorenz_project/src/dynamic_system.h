#ifndef DYNAMIC_SYSTEM_H
#define DYNAMIC_SYSTEM_H

typedef struct{
    
    const char *name;

    
    void (*init_params)(void *params);

    
    void (*update)(void *params, double *x, double *y, double *z, double dt);

    
    void *params;
}DynamicSystem;

#endif
