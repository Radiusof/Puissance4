#ifndef _FUNCTIONS_HPP
#define _FUNCTIONS_HPP

#include <iostream>

using namespace std;

enum Jeton {Vide, Jaune, Rouge};        // Définit les 3 valeurs possibles des cases -- Vide, Jaune, Rouge
class Grille{
    public:
        Jeton attribut_grille[42] {Vide};       //Définit la taille de la grille + initialise toutes les cases avec le paramètres Vide

        Grille();

        void put(int colonne, Jeton jeton)          //Mets le jeton passé en paramètre en haut de la colonne passé en paramètre.
        {
            attribut_grille[colonne] = jeton;
        }   

        Jeton get(int pos)                          //Retourne la couleur du jeton à la position passée en paramètre.
        {
            return attribut_grille[pos];
        }    

        void show(){                                         //Affiche la grille sur le Terminal
                for ( int i = 0; i <= 42; i++){
                    
                    if(i % 7 == 0){                             // Si modulo 7 = 0 => Retour à la ligne et |
                        cout <<endl << "|";
                        }
                    
                    if(attribut_grille[i] == Vide){             // Si index == Vide alors affiché _|
                        cout << " _ |" ;
                        }
                    else if(attribut_grille[i] == Rouge){       // Si index == Rouge alors affiché x|
                        cout << " x |";   
                        }
                    else if (attribut_grille[i] == Jaune){           // Si index == Jaune alors affiché o|
                        cout << " o |";
                        }
                    if(i == 42){                //Quand boucle atteint la limite, génére la derniere ligne représentatnt les numéros de colonnes.
                        cout << " 0 | 1 | 2 | 3 | 4 | 5 | 6 |" << endl ;
                        break;
                        }   
                    }
            
        }
        
        int checkUp (int pos, Jeton jeton);         //Retourne le nombre de jeton identique qu’il y a au-dessus de la position passée en paramètre. A coder **/

};

class Joueur{
    public:
        string nom;

        Jeton couleur;

        Joueur(string nom, Jeton couleur){              // Constructeur qui initialise les 2 attributs précédents
            this->nom = nom;
            this->couleur = couleur;
        }

        string getNom(){
            return this -> nom;
        }       

        Jeton getCouleur(){
            return this -> couleur;
        }       
};



class Jeu {
    public:
        Grille grille;

        Joueur joueur1, joueur2;

        Jeu();       // Constructeur demandant à chaque joueur leurs noms pour pouvoir initialiser les deux joueurs. On initialise aussi le pointeur joueurCourant sur le premier joueur.

        void loop();   //Cette fonction va d’abord afficher la grille de jeu, demander au joueur courant dans quelle colonne il souhaite mettre sont jeton, puis changer de joueur, afficher la grille, et demander         dans quelle colonne il souhaite jouer. Puis on redémarre la boucle 
            

};

#endif