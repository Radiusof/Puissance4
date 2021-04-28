#ifndef _JOUEUR_HPP
#define _JOUEUR_HPP

#include <iostream>
#include "grille.hpp"

using namespace std;


class Joueur{
    public:
        string nom;

        Jeton couleur;

        Joueur(string nom ,Jeton couleur);              // Constructeur qui initialise les 2 attributs précédents
        Joueur () = default;                // Constructeur par défaut => Permet d'utiliser le constructeur Jeu dans le fichier Jeu.cpp

        string getNom(); 

        Jeton getCouleur();
};



#endif