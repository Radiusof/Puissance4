#ifndef _GRILLE_HPP
#define _GRILLE_HPP

#include <iostream>
    


using namespace std;

enum Jeton {Vide , Jaune , Rouge};                    // Définit les 3 valeurs possibles des cases -- Vide, Jaune, Rouge
class Grille{
    public:
        Jeton grille[42] {Vide};                    //Définit la taille de la grille + initialise toutes les cases avec le paramètres Vide

        Grille () ;
               
        bool put(int colonne, Jeton jeton);          //Mets le jeton passé en paramètre en haut de la colonne passé en paramètre.

        int pos (int colonne);                       // Indique la position du jeton mis par le joueur
       
        Jeton get(int pos);                          //Retourne la couleur du jeton à la position passée en paramètre.
       
        void show();                                 //Affiche la grille sur le Terminal
        
        int checkRight (int pos, Jeton jeton);       // Check si 4 pions similaires à droite

        int checkLeft (int pos, Jeton jeton);        // Check si 4 pions similaires à Gauche

        int checkUp (int pos, Jeton jeton);          // Check si 4 pions similaires en haut

        int checkDown (int pos, Jeton jeton);        // Check si 4 pions similaires en Bas

        int checkUpLeft (int pos, Jeton jeton);      // Check si 4 pions similaires diagonale droite gauche bas haut

        int checkUpRight (int pos, Jeton jeton);     // Check si 4 pions similaires diagonale gauche droite bas haut

        int checkDownLeft (int pos, Jeton jeton);    // Check si 4 pions similaires diagonale droite gauche haut bas

        int checkDownRight (int pos, Jeton jeton);   // Check si 4 pions similaires diagonale gauche droite haut bas 

        void reset ();
};




#endif