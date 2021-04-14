#ifndef _JEU_HPP
#define _JEU_HPP


#include <iostream>
#include "grille.hpp"
#include "joueur.hpp"

using namespace std;


class Jeu{
    public:
        Grille grille;

        Joueur joueur1, joueur2;

        Joueur* joueurCourant = new Joueur();

        Jeu(); // Constructeur demandant à chaque joueur leurs noms pour pouvoir initialiser les deux joueurs. On initialise aussi le pointeur joueurCourant sur le premier joueur.

        void loop(){
            grille.show();



        };   //Cette fonction va d’abord afficher la grille de jeu, demander au joueur courant dans quelle colonne il souhaite mettre sont jeton, puis changer de joueur, afficher la grille, et demander dans quelle colonne il souhaite jouer. Puis on redémarre la boucle 
            

};



#endif