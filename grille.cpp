// Fichier comportant le code du constructeur Grille.

#include "grille.hpp"

using namespace std;

Grille::Grille(){                               //Reset la Grille
            int i =0;
            while (attribut_grille){
                if (i < 42){
                attribut_grille[i] = Vide;
                i++;
                }
                else {
                    break;
                }
            }           
        }

void Grille::put(int colonne, Jeton jeton)          //Mets le jeton passé en paramètre en haut de la colonne passé en paramètre.
        {
            attribut_grille[colonne] = jeton;
        }   

Jeton Grille::get(int pos)                          //Retourne la couleur du jeton à la position passée en paramètre.
        {
            return attribut_grille[pos];
        }    

void Grille::show(){                                         //Affiche la grille sur le Terminal
                for ( int i = 0; i <= 42; i++){
                    
                    if(i % 7 == 0){                             
                        cout <<endl << "|";
                        }
                    
                    if(attribut_grille[i] == Vide){             
                        cout << " _ |" ;
                        }
                    else if(attribut_grille[i] == Rouge){       
                        cout << " x |";   
                        }
                    else if (attribut_grille[i] == Jaune){           
                        cout << " o |";
                        }
                    if(i == 42){                
                        cout << " 0 | 1 | 2 | 3 | 4 | 5 | 6 |" << endl ;
                        break;
                        }   
                    }
            
        }


