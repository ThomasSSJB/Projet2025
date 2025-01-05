#include "../include/lorenz.h"
#include <stdio.h>

// Fonction pour initialiser les paramètres des équations de Lorenz
void initialise_lorenz(void *params){
    // Conversion du pointeur générique 'params' en un pointeur vers 'LorenzParams'
    struct LorenzParams *p = (struct LorenzParams *)params;
    
    // Demande à l'utilisateur de saisir les paramètres nécessaires pour les équations de Lorenz
    printf("Entrez les paramètres pour les équations de Lorenz :\n");

    // Demande à l'utilisateur de saisir la valeur de σ (sigma)
    printf("σ (sigma) : ");
    scanf("%lf", &p->sigma);  // Lecture de la valeur de sigma et stockage dans p->sigma

    // Demande à l'utilisateur de saisir la valeur de ρ (rho)
    printf("ρ (rho) : ");
    scanf("%lf", &p->rho);  // Lecture de la valeur de rho et stockage dans p->rho

    // Demande à l'utilisateur de saisir la valeur de β (beta)
    printf("β (beta) : ");
    scanf("%lf", &p->beta);  // Lecture de la valeur de beta et stockage dans p->beta
}

// Fonction pour mettre à jour les variables du système Lorenz à chaque pas de temps
void actualise_lorenz(void *params, double *x, double *y, double *z, double dt){
    // Conversion du pointeur générique 'params' en un pointeur spécifique vers 'LorenzParams'
    struct LorenzParams *p = (struct LorenzParams *)params;
    
    // Calcul des dérivées des variables du système Lorenz
    double dx = p->sigma * (*y - *x);            // dx/dt = σ * (y - x)
    double dy = *x * (p->rho - *z) - *y;         // dy/dt = x * (ρ - z) - y
    double dz = *x * *y - p->beta * *z;          // dz/dt = x * y - β * z

    // Mise à jour des variables x, y et z en fonction des dérivées calculées
    *x += dx * dt;  // Mise à jour de x en utilisant la dérivée dx/dt
    *y += dy * dt;  // Mise à jour de y en utilisant la dérivée dy/dt
    *z += dz * dt;  // Mise à jour de z en utilisant la dérivée dz/dt
}
