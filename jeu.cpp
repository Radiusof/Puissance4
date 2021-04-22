//Fichier comportant le code du constructeur Jeu


#include "jeu.hpp"

using namespace std;

Grille grille;

Jeu::Jeu(){

    Jeton grille[42] {Vide};
    string  nom;
    Jeton couleur;
    
    
    cout	<< "Nom du premier joueur?" << endl;
    
	cin>>nom ;
    couleur = Jaune;


    Joueur joueur1 (nom, couleur) ;          
    
    cout << endl << nom << " , tu auras les jetons de couleur: Jaune [o] "<< endl;

	cout<<endl<<endl <<"Nom du second joueur ?" << endl;
    
    cin>>nom;
    couleur = Rouge;

    cout << endl << nom << " , tu auras les jetons de couleur: Rouge [x] "<< endl<<endl;

    Joueur joueur2 (nom, couleur);
    
    joueurCourant = new Joueur (joueur1);    // Initialise le pointeur joueurCourant sur le premier joueur
          
    
    cout<< "Le joueur demarrant la partie sera " << joueurCourant -> getNom()<< endl << endl;

    system("pause");
    
}

void Jeu::loop(){
                                                                    
                int colonne;
                int pos;

                grille.show();   
                              
                while (true){                                        // Ajout d'un code pour checker si le numéro entré par l'utilisateur est   correct
                                       
                    
                    cout << joueurCourant -> getNom()  << ", Selectionne une colonne pour placer le jeton. " << " 0 , 1 , 2 , 3 , 4 , 5 , 6 " <<endl;
                
                    cin >> colonne;

                    if (colonne < 0  || colonne > 6 ){            // si saisie inférieur ou égal à -1 ou supérieur à 6 => erreur

                    cout << "Ce chiffre ne fonctionne pas . " << endl << endl;

                    cin.clear();                                    // On remet cin dans un état valide et vide le buffer

                    continue;

                    } else if (cin.fail()){                         // si saisie n'est pas un int => erreur
                           
                    cerr << "Erreur, saisie incorrecte." << endl << endl;

                    cin.clear();                                    // On remet cin dans un état valide et vide le buffer                      
                    cin.ignore(1,'\n');                             //Evite de boucler l'erreur, demande d'ignoner les char

                    continue;

                     } else {

                       break;                                       // sort de la boucle si saisie correcte
                     }
                }

                                
                //grille.checkLigne (pos, joueurCourant -> getCouleur());
               
                grille.put(colonne, joueurCourant -> getCouleur());       //Insere le résultat sur la grille
                               
                if (joueurCourant = &joueur1){
                    joueurCourant = &joueur2;
                }
                else {
                    joueurCourant = &joueur1;
                    }
                
            grille.show();  

            while (true){
                    cout << "A ton tour, " << joueurCourant -> getNom() << ", Selectionne une colonne pour placer le jeton. " << " 0 , 1 , 2 , 3 , 4 , 5 , 6 " <<endl;

                    cin >> colonne;

                    if (colonne <= -1  || colonne > 6 ){            // si saisie inférieur ou égal à -1 ou supérieur à 6 => erreur

                        cout << "Ce chiffre ne fonctionne pas . " << endl << endl;

                        cin.clear();                                    // On remet cin dans un état valide et vide le buffer

                        continue;

                    } else if (cin.fail()){                             // si saisie n'est pas un int => erreur
                           
                        cerr << "Erreur, saisie incorrecte." << endl << endl;

                        cin.clear();                                    // On remet cin dans un état valide et vide le buffer                      
                        cin.ignore(1,'\n');                             //Evite de boucler l'erreur, demande d'ignoner les char

                        continue;

                    } else {

                        break;
                    }
            }    

            grille.put(colonne, joueurCourant -> getCouleur());       //Insere le résultat sur la grille
                               
            if (joueurCourant = &joueur1){
                    joueurCourant = new Joueur (joueur2);
                }
            else {
                joueurCourant = new Joueur (joueur1);
            }
            grille.show();
                       
}
    
        

   
        
        // Ajouter un compteur pour limiter le nombre de tours ? 42 pions maxi dans la partie => Egalité "possible"

        // Créer un constructeur victoire à part entiére pour la condition victoire, regroupant les 8 fonctions ? 




int Jeu::checkRight (int pos, Jeton jeton){      
        if (jeton == grille.get(pos)){
            return 1 + checkRight(pos+1, jeton);        // Check si 4 pions similaires à droite
        }
        else {
            return 0;
            }
}         
        
int Jeu::checkLeft (int pos, Jeton jeton){      
        if (jeton == grille.get(pos)){
            return 1 + checkLeft(pos-1, jeton);        // Check si 4 pions similaires à Gauche
            }
        else {
            return 0;
            }
}

int Jeu::checkUp (int pos, Jeton jeton){      
        if (jeton == grille.get(pos)){
            return 1 + checkUp(pos-7, jeton);         // Check si 4 pions similaires en haut
            }
        else {
            return 0;
            }
}    

int Jeu:: checkDown (int pos, Jeton jeton){      
        if (jeton == grille.get(pos)){
            return 1 + checkDown(pos+7, jeton);        // Check si 4 pions similaires en Bas
            }
        else {
            return 0;
            }
}   

int Jeu::checkUpLeft (int pos, Jeton jeton){      
        if (jeton == grille.get(pos)){
            return 1 + checkUpLeft(pos-8, jeton);        // Check si 4 pions similaires diagonale droite gauche bas haut
        }
        else {
            return 0;
        }
}

int Jeu:: checkUpRight (int pos, Jeton jeton){      
        if (jeton == grille.get(pos)){
            return 1 + checkUpRight(pos-6, jeton);        // Check si 4 pions similaires diagonale gauche droite bas haut
        }
        else {
            return 0;
        }
}

int Jeu::checkDownLeft (int pos, Jeton jeton){      
        if (jeton == grille.get(pos)){
            return 1 + checkDownLeft(pos+6, jeton);        // Check si 4 pions similaires diagonale droite gauche haut bas
        }
        else {
            return 0;
        }
} 

int Jeu ::checkDownRight (int pos, Jeton jeton){      
        if (jeton == grille.get(pos)){
                return 1 + checkDownRight(pos+8, jeton);        // Check si 4 pions similaires diagonale gauche droite haut bas
        }
        else {
             return 0;
        }
}