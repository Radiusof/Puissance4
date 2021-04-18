#ifndef _JEU_HPP
#define _JEU_HPP

#include <cstdlib>
#include <iostream>
#include "grille.hpp"
#include "joueur.hpp"

using namespace std;


class Jeu{
    public:
        Grille grille;

        Joueur joueur1, joueur2;

        Joueur* joueurCourant;


        Jeu(); // Constructeur demandant à chaque joueur leurs noms pour pouvoir initialiser les deux joueurs. On initialise aussi le pointeur joueurCourant sur le premier joueur.

        void loop(){
            
            //while (victoire = false){   boucle tant qu'il n'y a pas de vainqueur
                
                int colonne = 0;

                grille.show();
                                
                

                 // Ajout d'un code pour checker si le numéro entré est correct
                               
                while (true){
                                       
                    
                    cout << "  "<< joueurCourant -> getNom()  << ", Selectionne une colonne pour placer le jeton. " << " 0 , 1 , 2 , 3 , 4 , 5 , 6 " <<endl;
                
                    cin >> colonne;

                    if (colonne <= -1  || colonne > 6 ){            // si saisie inférieur ou égal à -1 ou supérieur à 6 => erreur

                    cout << "Ce chiffre ne fonctionne pas . " << endl << endl;

                    cin.clear();                                    // On remet cin dans un état valide et vide le buffer

                    continue;

                    } else if (cin.fail()){                         // si saisie n'est pas un int => erreur
                           
                    cerr << "Erreur, saisie incorrecte." << endl << endl;

                    cin.clear();                                    // On remet cin dans un état valide et vide le buffer                      
                    cin.ignore(1,'\n');                             //Evite de boucler l'erreur, demande d'ignoner les char

                    continue;

                     } else {

                       break;  // sort de la boucle si saisie correcte
                     }
                }

                    


                grille.put( colonne, joueurCourant -> getCouleur());       //Insere le résultat sur la grille

                grille.show();
                                
                if (joueurCourant = &joueur1){
                        joueurCourant = &joueur2;
                }
                else {
                    joueurCourant = &joueur1;
                    }
                
            grille.show();
        // }
        }   
        
        // Ajouter un compteur pour limiter le nombre de tours ? 42 pions maxi dans la partie => Egalité "possible"

        // Créer un constructeur victoire à part entiére pour la condition victoire, regroupant les 8 fonctions ? 
       int checkRight (int pos, Jeton jeton){      
            if (jeton == grille.get(pos)){
                return 1 + checkRight(pos+1, jeton);        // Check si 4 pions similaires à droite
            }
            else {
                return 0;
            }
        }         
        
        int checkLeft (int pos, Jeton jeton){      
            if (jeton == grille.get(pos)){
                return 1 + checkLeft(pos-1, jeton);        // Check si 4 pions similaires à Gauche
            }
            else {
                return 0;
            }
        }

        int checkUp (int pos, Jeton jeton){      
            if (jeton == grille.get(pos)){
                return 1 + checkUp(pos-7, jeton);         // Check si 4 pions similaires en haut
            }
            else {
                return 0;
            }
        }    

        int checkDown (int pos, Jeton jeton){      
            if (jeton == grille.get(pos)){
                return 1 + checkDown(pos+7, jeton);        // Check si 4 pions similaires en Bas
            }
            else {
                return 0;
            }
        }   

        int checkUpLeft (int pos, Jeton jeton){      
            if (jeton == grille.get(pos)){
                return 1 + checkUpLeft(pos-8, jeton);        // Check si 4 pions similaires diagonale droite gauche bas haut
            }
            else {
                return 0;
            }
        }

        int checkUpRight (int pos, Jeton jeton){      
            if (jeton == grille.get(pos)){
                return 1 + checkUpRight(pos-6, jeton);        // Check si 4 pions similaires diagonale gauche droite bas haut
            }
            else {
                return 0;
            }
        }

        int checkDownLeft (int pos, Jeton jeton){      
            if (jeton == grille.get(pos)){
                return 1 + checkDownLeft(pos+6, jeton);        // Check si 4 pions similaires diagonale droite gauche haut bas
            }
            else {
                return 0;
            }
        } 

        int checkDownRight (int pos, Jeton jeton){      
            if (jeton == grille.get(pos)){
                return 1 + checkDownRight(pos+8, jeton);        // Check si 4 pions similaires diagonale gauche droite haut bas
            }
            else {
                return 0;
            }
        }               
};

#endif