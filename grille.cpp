// Fichier comportant le code du constructeur Grille.

#include "grille.hpp"
#include "jeu.hpp"

using namespace std;


Grille::Grille(){                              //Reset la Grille
            ///La boucle while est correcte, mais illisible
            ///Puisque tu connais la taille de la grille, tu peux tout simplement utiliser une boucle for :
            ///for(int i=0;i<42;i++){
            ///    grille[i] = Vide;
            ///}
            
            /**int i =0;
            while (grille){
                if (i < 42){
                grille[i] = Vide;           Ancienne méthode
                i++;
                }
                else {
                    break;
                }
            }
        } **/

            for(int i=0;i<42;i++){
                    grille[i] = Vide;
                }
 }  

 bool Grille::put (int colonne, Jeton jeton){
    bool pleine = false;                                                            // boolean annonçant si la colonne est pleine ou non   
        for(int i=5;i >= 0; i--) {                                              
               while (not pleine && grille[colonne + 7*i] != Vide){
                   if (colonne + 7*i == colonne && grille[colonne + 7*i] != Vide) {
                      
                       cout << "Colonne pleine! Choisis une autre colonne" << endl;
                       cin.clear();

                       
                        while (true){                                      // Boucle de vérification de saisie
                            cin >> colonne;                                     
                            if (colonne < 0  || colonne > 6 ){             // si saisie inférieur ou égal à -1 ou supérieur à 6 => erreur

                            cout << "Ce chiffre ne fonctionne pas . Selectionne une colonne pour placer le jeton. " << " 0 , 1 , 2 , 3 , 4 , 5 , 6 " << endl << endl;

                            cin.clear();                                    // On remet cin dans un état valide et vide le buffer
                            
                            continue;

                            } else if (cin.fail()){                         // si saisie n'est pas un int => erreur

                            cerr << "Erreur, saisie incorrecte." << " Selectionne une colonne pour placer le jeton. "<< " 0 , 1 , 2 , 3 , 4 , 5 , 6 " <<  endl << endl;

                            cin.clear();                                    // On remet cin dans un état valide et vide le buffer
                            cin.ignore(1,'\n');                             //Evite de boucler l'erreur, demande d'ignoner les char

                            continue;

                            } else {

                            break;                                          // sort de la boucle si saisie correcte
                            }
                        }

                    return  pleine = true + put (colonne, jeton);                                              
                       
                   } else {
                     i--;  
                   }
                }
            if (not pleine){
                grille [colonne + 7*i] = jeton;
                return true;
            }else {
                return false;
            }
            }          
    }               
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
            /// On va démarrer par le bas de grille, on auras donc notre incrément qui va démarrer au maximum (6 colonne, donc i=5) et on va décrémenter    (on parle en ligne si on part du bas ? )
            /// for(int i=5;i >= 0; i--) 
            /// il ne reste plus qu'à check si l'emplacement colonne + 7 * i est vide

            /// Je te conseil aussi de faire retourner un bool par la fonction en renvoyant true si c'est bon, ou false si la colonne est pleine
           



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



