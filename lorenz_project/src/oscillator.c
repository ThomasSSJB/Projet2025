#include "../include/oscillator.h"
#include <stdio.h>

// Fonction pour initialiser les paramètres de l'oscillateur harmonique
void initialise_oscillator(void *params){
    // Conversion du pointeur générique 'params' en un pointeur spécifique vers 'OscillatorParams'
    struct OscillatorParams *p = (struct OscillatorParams *)params;
    
    // Demande à l'utilisateur de saisir les paramètres de l'oscillateur
    printf("Entrez les paramètres pour l'oscillateur harmonique :\n");
    
    // Demande la valeur de ω (omega) qui est la fréquence angulaire de l'oscillateur
    printf("ω (omega) : ");
    scanf("%lf", &p->omega);  // Lecture de la valeur de ω et stockage dans p->omega
}

// Fonction pour mettre à jour l'état de l'oscillateur harmonique à chaque pas de temps
void actualise_oscillator(void *params, double *x, double *y, double *z, double dt){
    // Conversion du pointeur générique 'params' en un pointeur spécifique vers 'OscillatorParams'
    struct OscillatorParams *p = (struct OscillatorParams *)params;
    
    // Calcul des dérivées de l'oscillateur : dx et dy
    // dx/dt = y (vitesse)
    double dx = *y;  // La vitesse (dx/dt) est égale à la position de y
    
    
    double dy = -p->omega * p->omega * (*x);  // Calcul de l'accélération en fonction de la position x et de ω (omega)

    // Mise à jour de la position et de la vitesse en utilisant les dérivées calculées
    *x += dx * dt;  // Mise à jour de la position x à partir de la vitesse dx
    *y += dy * dt;  // Mise à jour de la vitesse y à partir de l'accélération dy
    // z n'est pas utilisé dans ce cas, il pourrait être utilisé pour d'autres systèmes dans un modèle 3D
}
