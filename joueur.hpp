#ifndef _JOUEUR_HPP
#define _JOUEUR_HPP

#include <iostream>

using namespace std;


class Joueur{
    public:
        string nom;

        Jeton  couleur;

        Joueur(string ,Jeton);              // Constructeur qui initialise les 2 attributs précédents
        Joueur () = default;                // Constructeur par défaut => Permet d'utiliser le constructeur Jeu dans le fichier Jeu.cpp

        string getNom(){                    //Donne le nom
            return this -> nom;
        }       

        Jeton getCouleur(){                 // Donne la couleur
            return this -> couleur;
        }       
};



#endif