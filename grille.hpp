#ifndef _GRILLE_HPP
#define _GRILLE_HPP

#include <iostream>
    


using namespace std;

enum Jeton {Vide, Jaune, Rouge};                    // Définit les 3 valeurs possibles des cases -- Vide, Jaune, Rouge
class Grille{
    public:
        Jeton grille[42] {Vide};                    //Définit la taille de la grille + initialise toutes les cases avec le paramètres Vide

        Grille();
               
        bool put(int colonne, Jeton jeton);          //Mets le jeton passé en paramètre en haut de la colonne passé en paramètre.
       
        Jeton get(int pos);                          //Retourne la couleur du jeton à la position passée en paramètre.
       
        void show();                                 //Affiche la grille sur le Terminal
        
};



#endif