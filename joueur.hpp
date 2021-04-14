#ifndef _JOUEUR_HPP
#define _JOUEUR_HPP

#include <iostream>

using namespace std;


class Joueur{
    public:
        string nom;

        Jeton couleur;

        Joueur(string, Jeton);              // Constructeur qui initialise les 2 attributs précédents
         
        string getNom(){
            return this -> nom;
        }       

        Jeton getCouleur(){
            return this -> couleur;
        }       
};


#endif