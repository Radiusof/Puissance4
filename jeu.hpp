#ifndef _JEU_HPP
#define _JEU_HPP

#include <cstdlib>
#include <iostream>
#include "grille.hpp"
#include "joueur.hpp"

using namespace std;


class Jeu{
    public:
        Grille grille;
               
        Joueur joueur1, joueur2;

        Joueur* joueurCourant;
        
        Jeu();  // Constructeur demandant à chaque joueur leurs noms pour pouvoir initialiser les deux joueurs. On initialise aussi le pointeur joueurCourant sur le premier joueur.

        void loop();  

        int checkRight (int pos, Jeton jeton);       // Check si 4 pions similaires à droite

        int checkLeft (int pos, Jeton jeton);        // Check si 4 pions similaires à Gauche

        int checkUp (int pos, Jeton jeton);          // Check si 4 pions similaires en haut

        int checkDown (int pos, Jeton jeton);        // Check si 4 pions similaires en Bas

        int checkUpLeft (int pos, Jeton jeton);      // Check si 4 pions similaires diagonale droite gauche bas haut

        int checkUpRight (int pos, Jeton jeton);     // Check si 4 pions similaires diagonale gauche droite bas haut

        int checkDownLeft (int pos, Jeton jeton);    // Check si 4 pions similaires diagonale droite gauche haut bas

        int checkDownRight (int pos, Jeton jeton);   // Check si 4 pions similaires diagonale gauche droite haut bas
    
    };

#endif