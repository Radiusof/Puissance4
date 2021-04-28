//Fichier comportant le code du constructeur Jeu

#include "jeu.hpp"
#include "joueur.hpp"
#include "grille.hpp"

using namespace std;




Jeu::Jeu(){
    ///Lorsque tu utilise le constructeur d'une fonction qui utilise d'autre objet, leurs constructeur par défaut est automatiquement appelé
    ///Donc grille est déjà initialiser
    ///De même que joueur1 et joueur2, sauf que pour ces deux la, on ne veut pas utiliser le constructeur par défaut
    ///on va donc écraser l'initialisation pas défaut avec le bon constructeur
    
    string  nom;
    Jeton couleur;


    cout	<< "Nom du premier joueur?" << endl;

	cin>>nom ;
    couleur = Jaune;

    ///Pour écraser l'ancienne initialisation pour utiliser le bon constructeur il faut faire :
    /// joueur1 = Joueur(nom, couleur);
    joueur1= Joueur(nom, couleur) ;

    cout << endl << nom << " , tu auras les jetons de couleur: Jaune [o] "<< endl;

	cout<<endl<<endl <<"Nom du second joueur ?" << endl;

    cin>>nom;
    couleur = Rouge;

    cout << endl << nom << " , tu auras les jetons de couleur: Rouge [x] "<< endl<<endl;

    ///Pareil
    joueur2= Joueur(nom, couleur);

    ///Atention, vu que tu n'a pas défini un contructeur joueur qui prend en paramètre un autre joueur, le résultat de cette ligne n'est pas forcément celui que tu crois
    ///La bonne façons de faire est de récupérer directement l'adresse de joueur1 en utilisant & :
    /// joueurCourant = &joueur1;
    joueurCourant = &joueur1;    // Initialise le pointeur joueurCourant sur le premier joueur


    cout<< "Le joueur demarrant la partie sera " << joueurCourant -> getNom()<< endl << endl;

    system("pause");

}

void Jeu::loop(){

            int colonne;
            int pos;
            int compteur = 0;                                        // Compteur initialisé à 0, +1 à chaque tour de joueur. Si arrive à 42 = Match nul

            do {                                                     // La fonction loop se trouve dans une boucle do - while (check L109)
                cout<< endl<<endl;                                   // Saute 2 lignes pour plus de lisibilité

                grille.show();

                cout << endl<< endl<<  "Tour: "<< compteur << endl<< endl;

                while (true){                                        // Ajout d'un code pour checker si le numéro entré par l'utilisateur est   correct


                    cout << joueurCourant -> getNom()  << ", Selectionne une colonne pour placer le jeton. " << " 0 , 1 , 2 , 3 , 4 , 5 , 6 " <<endl;

                    cin >> colonne;

                    
                    if (colonne < 0  || colonne > 6 ){              // si saisie inférieur à 0 ou supérieur à 6 => erreur

                    cout << "Ce chiffre ne fonctionne pas ." << endl << endl;

                    cin.clear();                                    // On remet cin dans un état valide et vide le buffer

                    continue;

                    } else if (cin.fail()){                         // si saisie n'est pas un int => erreur

                    cerr << "Erreur, saisie incorrecte." << endl << endl;

                    cin.clear();                                    // On remet cin dans un état valide et vide le buffer
                    cin.ignore(1,'\n');                             //Evite de boucler l'erreur, demande d'ignoner les char

                    continue;

                     } else {

                       break;                                       // Sort de la boucle si saisie correcte
                     }
                }



                grille.put(colonne, joueurCourant -> getCouleur()); //Insere le résultat sur la grille

                victoire(grille.get(pos),joueurCourant->getCouleur());

                compteur ++;                                        // Insere +1 au compteur      

                ///Attention = ne vérifie pas l'égalité, == oui
                ///faire joueurCourant = &joueur1 assigne la valeur de joueurCourant avec l'adresse de joueur1
                ///et si l'assignation réussi (dans tout les cas donc) ça renvoie true.
                ///Cette condition est donc toujours vrai
                
                if (joueurCourant == &joueur1){
                    joueurCourant = &joueur2;
                }
                else {
                    joueurCourant = &joueur1;
                    }
                
                
            }
           
            while ((compteur != 42) || (victoire( grille.get(pos),joueurCourant -> getCouleur()) != false));           // loop() bouclera tant que le boolean victoire retournera Faux ou que le compteur n'est pas égal à 42
            
           
            if ( compteur == 42){

                    grille.show();

                    cout << endl << endl << "Match Nul !"<< endl << endl << "Merci d'avoir joue !" << endl << endl;
                   

                    system("pause");
            } 
            else if (victoire(grille.get(pos),joueurCourant -> getCouleur()) == true){

                    grille.show();                                     
               
                    cout << endl << endl << " Felicitations " << joueurCourant -> getNom()  <<"! Tu as Gagné !" << endl;
                    system("pause");
                } 
}


    

        ///Ca ne poserais aucun problème, mais il faut éviter d'avoir trop de class, ça nuît à la lisibilité du code
        // Créer un constructeur victoire à part entiére pour la condition victoire, regroupant les 8 fonctions ?

// Ancien code
/**bool Jeu::victoire (int pos, Jeton couleur) {
        if (grille.checkRight(grille.get(pos),joueurCourant->getCouleur()) >= 4) {
            return true;
        }else{
            if (grille.checkLeft(grille.get(pos),joueurCourant -> getCouleur()) >= 4){
                return true;
            }else{
                if (grille.checkUp(grille.get(pos),joueurCourant -> getCouleur()) >= 4) {
                    return true;
                }else{
                    if (grille.checkDown(grille.get(pos),joueurCourant -> getCouleur()) >= 4) {
                        return true;
                    }else{
                        if (grille.checkUpLeft(grille.get(pos),joueurCourant -> getCouleur()) >= 4) {
                            return true;
                        }else{
                            if (grille.checkUpRight(grille.get(pos),joueurCourant -> getCouleur()) >= 4){
                                return true;
                            }else{
                                if (grille.checkDownLeft(grille.get(pos),joueurCourant -> getCouleur()) >= 4) {
                                    return true;
                                }else{
                                    if  (grille.checkDownRight(grille.get(pos),joueurCourant -> getCouleur()) >= 4) {
                                        return true;
                                    }else{
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
    }
**/

bool Jeu::victoire (int pos, Jeton couleur){  
    if (((grille.checkRight(grille.get(pos),joueurCourant->getCouleur())) + (grille.checkLeft(grille.get(pos),joueurCourant->getCouleur()))) >= 4) {              
            return true;    // Check la somme des checks Gauche et Droite, si égal ou supérieur à 4 => Victoire = true

    } else if (((grille.checkUp(grille.get(pos),joueurCourant->getCouleur())) + (grille.checkDown(grille.get(pos),joueurCourant->getCouleur()))) >= 4){
            return true;    // Check la somme des checks Haut et Bas, si égal ou supérieur à 4 => Victoire = true

    } else if (((grille.checkDownLeft(grille.get(pos),joueurCourant->getCouleur())) + (grille.checkUpRight(grille.get(pos),joueurCourant->getCouleur()))) >= 4){
            return true;    // Check la somme des checks Diagonales bas gauche et Diagones Haut Droit, si égal ou supérieur à 4 => Victoire = true

    } else if (((grille.checkUpLeft(grille.get(pos),joueurCourant->getCouleur())) + (grille.checkDownRight(grille.get(pos),joueurCourant->getCouleur()))) >= 4){
            return true;    // Check la somme des checks Diagonales Haut gauche et Diagones Bas Droit, si égal ou supérieur à 4 => Victoire = true

    } else {
            return false;
    }
}