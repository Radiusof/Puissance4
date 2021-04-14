// Fichier comportant les codes des constructeurs.

#include "joueur.hpp"
using namespace std;

Joueur::Joueur(string nom, Jeton couleur){              // Constructeur qui initialise les 2 attributs précédents
            this->nom = nom;
            this->couleur = couleur;
        }

