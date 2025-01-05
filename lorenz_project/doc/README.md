                       Comment utiliser notre application ?
                        
Ce tutoriel vous guidera sur l'utilisation de notre application lorenz_project.
                        

Attention ! : L'utilisation de notre application demande d'avoir au préalable BASH avec la version 3.2 au minimum de préférence.

Utilisation:

EQUATION DE LORENZ (3D):
1) Lancer BASH dans votre terminal 

2) Ecrivez ensuite cd lorenz_project dans votre terminal puis appuyez sur ENTRER

3) Lorsque vous avez effectué(e) les étapes précédentes, Ecrivez make run dans votre terminal appuyez sur ENTRER pour valider l'execution

4) Lorsque votre programme est executé : Choisissez les equations de Lorenz en tapant 1 dans le terminal et en appuyant sur ENTRER :
- a) Entrez les 3 paramètres de votre equation sigma,rho,béta puis appuyer sur ENTRER
- b) Entrez les trois valeur "position initiale" de votre equation de lorenz en x,y,z puis appuyer sur ENTRER
- c) Entrez votre increment de temps dt puis appuyer sur ENTRER
- d) Entrez le temps maximal t_max puis appuyer sur ENTRER

5) Après avoir fait l'étape précédente Ecrivez gnuplot dans le terminal puis appuyer sur ENTRER
6) Après que gnuplot se soit lancer taper cette commande dans le terminal : 
    set parametric
- a) Pour avoir un affichage avec des points, veuillez taper cette commande dans le terminal :
    splot "test/simulation.dat" using 2:3:4
- b) Pour avoir un affichage avec des lignes, veuillez taper cette commande dans le terminal :
    splot "test/simulation.dat" using 2:3:4 with lines

7) Pour obtenir la courbe de la vitesse de mise à jour par rapport au "speed_factor", veuillez entrez cette commande dans le terminal : 
gnuplot -e "
    set title 'Dynamique du système'
    set xlabel 'Temps (t)'
    set ylabel 'Position'
    plot 'test/simulation.dat' using 1:2 with lines title 'x', \
         'test/simulation.dat' using 1:3 with lines title 'y', \
         'test/simulation.dat' using 1:4 with lines title 'z'
"

puis appuyez sur ENTRER

8) Au choix si vous voulez :
1) la vitesse par des vecteurs :
tapez cette commande dans le terminal :
splot 'test/simulation.dat' using 2:3:4:5:6:7 with vectors title 'Vitesse'
2) Si vous voulez la vitesse par une couleur :
tapez cette commande dans le terminal :
splot 'test/simulation.dat' using 2:3:4:8 with points palette title 'Magnitude de la Vitesse'
3) Si vous voulez le temps par un changement de couleur :
Tapez cette commande dans le terminal :
splot 'test/simulation.dat' using 2:3:4:1 with points palette title 'Temps'


Puis Appuyez sur ENTRER








OSCILLATEUR ET EQUATION DE VAN DER POL (2D):
1) Lancer BASH dans votre terminal 

2) Ecrivez ensuite cd lorenz_project dans votre terminal puis appuyez sur ENTRER

3) Lorsque vous avez effectué(e) les étapes précédentes, Ecrivez make run dans votre terminal appuyez sur ENTRER pour valider l'execution

4) Lorsque votre programme est executé : Choisissez soit les equations de van der pol en tapant 2 soit les oscillations en tapant 3 :
- a) Entrez le paramètre de votre equation puis appuyer sur ENTRER
- b) Entrez les trois valeur "position initiale" de votre choix en x,y,z (avec z inactif) puis appuyer sur ENTRER
- c) Entrez votre increment de temps dt puis appuyer sur ENTRER
- d) Entrez le temps maximal t_max puis appuyer sur ENTRER

5) Après avoir fait l'étape précédente Ecrivez gnuplot dans le terminal puis appuyer sur ENTRER
6) Après que gnuplot se soit lancer taper cette commande dans le terminal : 

plot "test/simulation.dat" using 1:2 with lines

puis appuyez sur ENTRER

7) Pour obtenir la courbe de la vitesse de mise à jour par rapport au "speed_factor", veuillez entrez cette commande dans le terminal : 
gnuplot -e "
    set title 'Dynamique du système'
    set xlabel 'Temps (t)'
    set ylabel 'Position'
    plot 'test/simulation.dat' using 1:2 with lines title 'x', \
         'test/simulation.dat' using 1:3 with lines title 'y', \
         'test/simulation.dat' using 1:4 with lines title 'z'
"

puis appuyez sur ENTRER

8) Au choix si vous voulez :
1) la vitesse par des vecteurs :
tapez cette commande dans le terminal :
splot 'test/simulation.dat' using 2:3:4:5:6:7 with vectors title 'Vitesse'
2) Si vous voulez la vitesse par une couleur :
tapez cette commande dans le terminal :
splot 'test/simulation.dat' using 2:3:4:8 with points palette title 'Magnitude de la Vitesse'
3) Si vous voulez le temps par un changement de couleur :
Tapez cette commande dans le terminal :
splot 'test/simulation.dat' using 2:3:4:1 with points palette title 'Temps'

Puis Appuyez sur ENTRER



