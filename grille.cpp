// Fichier comportant le code du constructeur Grille.

#include "grille.hpp"
#include "jeu.hpp"

using namespace std;

///Pas utile
Jeu jeu;

Grille::Grille(){                               //Reset la Grille
            ///La boucle while est correcte, mais illisible
            ///Puisque tu connais la taille de la grille, tu peux tout simplement utiliser une boucle for :
            ///for(int i=0;i<42;i++){
            ///    grille[i] = Vide;
            ///}
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
            ///Beaucoup trop compliquer essaie de simplifier cette fonction. voici les index de la grille :
            /// 0  1  2  3  4  5  6
            /// 7  8  9  10 11 12 13
            /// 14 15 16 17 18 19 20
            /// 21 22 23 24 25 26 27
            /// 28 29 30 31 32 33 34
            /// 35 36 37 38 39 40 41
            /// Si on regarde les index de la première colonne, on a : 0 7 14 21 28 35
            /// Si on regarde les index de la deuxième colonne, on a : 1 8 15 22 29 36
            /// Si on regarde les index de la troisième colonne, on a : 2 9 16 23 30 37
            /// On peut voir que les indexe correspond a cette suite: colonne + 7*i
            /// on va utiliser cette suite pour définir le 1er emplacement vide
            /// On va démarrer par le bas de grille, on auras donc notre incrément qui va démarrer au maximum (6 colonne, donc i=5) et on va décrémenter
            /// for(int i=5;i >= 0; i--)
            /// il ne reste plus qu'à check si l'emplacement colonne + 7 * i est vide

            /// Je te conseil aussi de faire retourner un bool par la fonction en renvoyant true si c'est bon, ou false si la colonne est pleine
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
                /// Très bien !
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


