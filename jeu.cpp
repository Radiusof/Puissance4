//Fichier comportant le code du constructeur Jeu

#include "jeu.hpp"

using namespace std;




Jeu::Jeu(){
    ///Lorsque tu utilise le constructeur d'une fonction qui utilise d'autre objet, leurs constructeur par défaut est automatiquement appelé
    ///Donc grille est déjà initialiser
    ///De même que joueur1 et joueur2, sauf que pour ces deux la, on ne veut pas utiliser le constructeur par défaut
    ///on va donc écraser l'initialisation pas défaut avec le bon constructeur
    Jeton grille[42] {Vide};
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

            do {     

                grille.show();

                while (true){                                        // Ajout d'un code pour checker si le numéro entré par l'utilisateur est   correct


                    cout << joueurCourant -> getNom()  << ", Selectionne une colonne pour placer le jeton. " << " 0 , 1 , 2 , 3 , 4 , 5 , 6 " <<endl;

                    cin >> colonne;

                    ///Bien penser, c'est important de vérifier les inputs utilisateurs
                    if (colonne < 0  || colonne > 6 ){            // si saisie inférieur ou égal à -1 ou supérieur à 6 => erreur

                    cout << "Ce chiffre ne fonctionne pas . Selectionne une colonne pour placer le jeton. " << " 0 , 1 , 2 , 3 , 4 , 5 , 6 " << endl << endl;

                    cin.clear();                                    // On remet cin dans un état valide et vide le buffer

                    continue;

                    } else if (cin.fail()){                         // si saisie n'est pas un int => erreur

                    cerr << "Erreur, saisie incorrecte." << " Selectionne une colonne pour placer le jeton. "<< " 0 , 1 , 2 , 3 , 4 , 5 , 6 "  << endl << endl;

                    cin.clear();                                    // On remet cin dans un état valide et vide le buffer
                    cin.ignore(1,'\n');                             //Evite de boucler l'erreur, demande d'ignoner les char

                    continue;

                     } else {

                       break;                                       // sort de la boucle si saisie correcte
                     }
                }



                grille.put(colonne, joueurCourant -> getCouleur());       //Insere le résultat sur la grille

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

            

            while (victoire(grille.get(pos),joueurCourant -> getCouleur()) == false);

            cout << checkUp(grille.get(pos),joueurCourant -> getCouleur()) << endl;

            if (victoire(grille.get(pos),joueurCourant -> getCouleur()) == true){
                 if (joueurCourant == &joueur1){
                    cout <<" Felicitations " << joueurCourant-> getNom()  <<"! Tu as Gagné !" << endl;
                }
                else if (joueurCourant == &joueur2) {
                    cout <<" Felicitations " << joueurCourant-> getNom()  <<"! Tu as Gagné !" << endl;
                    } 
            }
        
            
            ///Tout ce qui est en dessous n'est pas utile, c'est exactement le même code qu'au dessus.
            ///il faut créer une boucle pour enchainer les coups.          
    }




        ///Oui pas bête
        // Ajouter un compteur pour limiter le nombre de tours ? 42 pions maxi dans la partie => Egalité "possible"

        ///Ca ne poserais aucun problème, mais il faut éviter d'avoir trop de class, ça nuît à la lisibilité du code
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

bool Jeu::victoire (int pos, Jeton jeton) {
        if (checkRight(grille.get(pos),joueurCourant->getCouleur()) >= 4) {
            return true;
        }else{
            if (checkLeft(pos,joueurCourant -> getCouleur()) >= 4){
                return true;
            }else{
                if (checkUp(pos,joueurCourant -> getCouleur()) >= 4) {
                    return true;
                }else{
                    if (checkDown(pos,joueurCourant -> getCouleur()) >= 4) {
                        return true;
                    }else{
                        if (checkUpLeft(pos,joueurCourant -> getCouleur()) >= 4) {
                            return true;
                        }else{
                            if (checkUpRight(pos,joueurCourant -> getCouleur()) >= 4){
                                return true;
                            }else{
                                if (checkDownLeft(pos,joueurCourant -> getCouleur()) >= 4) {
                                    return true;
                                }else{
                                    if  (checkDownRight(pos,joueurCourant -> getCouleur()) >= 4) {
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


