// Fichier comportant le code du constructeur Grille.

#include "grille.hpp"
#include "jeu.hpp"

using namespace std;
Jeu jeu;

Grille::Grille(){                               //Reset la Grille
            int i =0;
            while (grille){
                if (i < 42){
                grille[i] = Vide;
                i++;
                }
                else {
                    break;
                }
            }           
        }


void Grille::put(int colonne, Jeton jeton) {                //Mets le jeton passé en paramètre en haut de la colonne passé en paramètre.

            for (int i = 41; i >= 0 ; i--){            // Commencer l'analyse par le bas de la ligne et remonte au fur et a mesure      
                if (grille[i] <= 41 && grille[i] >= 35 && grille[i] == Vide )
                {
                  colonne += 35;                               // +35 correspond au nombre de case à ajouter à colonne pour correspondre à la derniere ligne (exemple colonne choisie : 5 , equivalent case [i] en bas de grille => 40  )
                  grille[colonne] = jeton ;                   // permet d'afficher le jeton sur la grille
                }else{   
                    
                    i -= 7;                                     // décremente de -7 (une ligne en moins)
                    if (grille[i] <= 34 && grille[i] >= 28 && grille[i] == Vide ){              //analyse de la 5eme ligne
                        colonne += 28; 
                        grille[colonne] = jeton ;                                          
                    }else{

                        i -=7;
                        if (grille[i] <= 27 && grille[i] >= 21 && grille[i] == Vide ){          //analyse de la 4eme ligne
                            colonne += 21; 
                            grille[colonne] = jeton ;         
                        }else{
                            
                            i -=7;
                            if (grille[i] <= 20 && grille[i] >= 14 && grille[i] == Vide ){          //analyse de la 3eme ligne
                                colonne += 14; 
                                grille[colonne] = jeton ;                 
                            }else{
                                
                                i -=7;
                                if (grille[i] <= 13 && grille[i] >= 7 && grille[i] == Vide ){          //analyse de la 2eme ligne
                                    colonne += 7; 
                                    grille[colonne] = jeton ;
                                }else{

                                    i -=7;
                                    if(grille[i] <= 6 && grille[i] >= 0 && grille[i] == Vide ){          //analyse de la 1ere ligne
                                       grille[colonne] = jeton ;

                                    }else{

                                        cout<< "Impossible de placer ce jeton ici, choisis une autre colonne."<< endl;          //Colonne pleine
                                        cin.clear(); 
                                        cin >> colonne;                                 // l'utilisateur doit replacer le jeton
                                    }
                                }
                            }
                        }
                    }
                }                        
            } 
        }  
           

Jeton Grille::get(int pos)                                  //Retourne la couleur du jeton à la position passée en paramètre.
        {
            return grille[pos];
        }    

void Grille::show(){                                         //Affiche la grille sur le Terminal
                for( int i = 0; i <= 42; i++){
                    
                    if(i % 7 == 0){                             
                        cout <<endl << "|";
                        }
                    
                    if(grille[i] == Vide){             
                        cout << " _ |" ;
                        }
                    else if(grille[i] == Rouge){       
                        cout << " x |";   
                        }
                    else if (grille[i] == Jaune){           
                        cout << " o |";
                        }
                    if(i == 42){                
                        cout << " 0 | 1 | 2 | 3 | 4 | 5 | 6 |" << endl ;
                        break;
                        }   
                    }
            
        }


