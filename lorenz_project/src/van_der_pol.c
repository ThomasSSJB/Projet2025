#include "../include/van_der_pol.h"
#include <stdio.h>

// Fonction pour initialiser les paramètres de l'oscillateur de Van der Pol
void initialise_van_der_pol(void *params){
    // Conversion du pointeur générique 'params' en un pointeur vers 'VanDerPolParams'
    struct VanDerPolParams *p = (struct VanDerPolParams *)params;
    
    // Demande à l'utilisateur de saisir le paramètre de l'oscillateur de Van der Pol : (mu)
    printf("Entrez les paramètres pour l'oscillateur de Van der Pol :\n");
    
    // Demande à l'utilisateur de saisir la valeur de (mu)
    printf("μ (mu) : ");
    scanf("%lf", &p->mu);  // Lecture de la valeur de μ et stockage dans p->mu
}

// Fonction pour mettre à jour l'état de l'oscillateur de Van der Pol à chaque pas de temps
void actualise_van_der_pol(void *params, double *x, double *y, double *z, double dt){
    // Conversion du pointeur générique 'params' en un pointeur spécifique vers 'VanDerPolParams'
    struct VanDerPolParams *p = (struct VanDerPolParams *)params;
    
    // Calcul des dérivées des variables du système Van der Pol
    double dx = *y;  // La dérivée de x (dx/dt) est égale à y (vitesse)
    double dy = p->mu * (1 - (*x) * (*x)) * (*y) - *x;  // La dérivée de y (dy/dt) est une fonction non linéaire de x et y
    
    // Mise à jour des variables x et y en fonction des dérivées calculées
    *x += dx * dt;  // Mise à jour de la position x à partir de la vitesse dx
    *y += dy * dt;  // Mise à jour de la vitesse y à partir de l'accélération dy
    // z n'est pas utilisé dans ce modèle, mais il pourrait être utilisé dans un modèle étendu ou en 3D
}
