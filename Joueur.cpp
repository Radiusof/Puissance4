//Fichier comportant le code du constructeur Joueur

#include "joueur.hpp"
using namespace std;

Joueur:: Joueur(string nom, Jeton couleur){              // Constructeur qui initialise les 2 attributs précédents
            this->nom = nom;
            this->couleur = couleur;
        }

string Joueur::getNom() {                               //Donne le nom
        /// Tu peux simplement faire return nom, contrairement au contructeur où il y a une ambiguité entre la variable nom et l'attribut nom
            /**return this  **/

            return nom;
        }

Jeton Joueur::getCouleur(){                             // Donne la couleur
        /// pareil
            return couleur;
        }
