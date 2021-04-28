#ifndef _JEU_HPP
#define _JEU_HPP


#include <iostream>
#include "joueur.hpp"
#include "grille.hpp"


using namespace std;


class Jeu{
    public:
        Grille grille;

        Joueur joueur1, joueur2;

        Joueur* joueurCourant;

        Jeu();                                       // Constructeur demandant à chaque joueur leurs noms pour pouvoir initialiser les deux joueurs.
                                                     // On initialise aussi le pointeur joueurCourant sur le premier joueur.

        void loop();                                 //Permet de lancer le jeu , loop tant que pas de victoire.

        bool victoire (int pos, Jeton couleur);         //boolean checkant la condition de victoire
        
        
    };

#endif
