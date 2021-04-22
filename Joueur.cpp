//Fichier comportant le code du constructeur Joueur

#include "joueur.hpp"
using namespace std;

Joueur:: Joueur(string nom, Jeton couleur){              // Constructeur qui initialise les 2 attributs précédents
            this->nom = nom;
            this->couleur = couleur;
        }
        
string Joueur::getNom() {                               //Donne le nom
            return this -> nom;
        }      

Jeton Joueur::getCouleur(){                             // Donne la couleur
            return this -> couleur;
        }       
