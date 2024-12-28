#include <stdio.h>
#include "file_io.h"

void gestion_ficher(FILE *file, double t, double x, double y, double z) {
    fprintf(file, "%lf %lf %lf %lf\n", t, x, y, z);
}