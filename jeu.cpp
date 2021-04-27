//Fichier comportant le code du constructeur Jeu

#include "jeu.hpp"

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
                victoire (grille.get(pos),joueurCourant->getCouleur());
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
           
            while (compteur != 42 || victoire(grille.get(pos),joueurCourant -> getCouleur()) != false);           // loop() bouclera tant que le boolean victoire retournera Faux ou que le compteur n'est pas égal à 42
            
           
            if ( compteur == 42){
                    cout << "Match Nul !"<< endl << endl << "Merci d'avoir joue !" << endl << endl;
                    cout<< "Press enter to quit" << endl ;

                system("pause");
            } 
            else if (victoire(grille.get(pos),joueurCourant -> getCouleur()) == true){                                     
               
                    cout <<" Felicitations " << joueurCourant -> getNom()  <<"! Tu as Gagné !" << endl;
                    system("pause");
                } 
}


    

        ///Ca ne poserais aucun problème, mais il faut éviter d'avoir trop de class, ça nuît à la lisibilité du code
        // Créer un constructeur victoire à part entiére pour la condition victoire, regroupant les 8 fonctions ?

int Jeu::checkRight (int pos, Jeton jeton){
        if (joueurCourant -> getCouleur() == grille.get(pos)){
            return 1 + checkRight(pos+1, jeton);               // Check si 4 pions similaires à droite
        }
        else {
            return 0;
            }
}

int Jeu::checkLeft (int pos, Jeton jeton){
        if (joueurCourant -> getCouleur() == grille.get(pos)){
            return 1 + checkLeft(pos-1, jeton);                // Check si 4 pions similaires à Gauche
            }
        else {
            return 0;
            }
}

int Jeu::checkUp (int pos, Jeton jeton){
        if (joueurCourant -> getCouleur() == grille.get(pos)){
            return 1 + checkUp(pos-7, jeton);                  // Check si 4 pions similaires en haut
            }
        else {
            return 0;
            }
}

int Jeu:: checkDown (int pos, Jeton jeton){
        if (joueurCourant -> getCouleur() == grille.get(pos)){
            return 1 + checkDown(pos+7, jeton);                // Check si 4 pions similaires en Bas
            }
        else {
            return 0;
            }
}

int Jeu::checkUpLeft (int pos, Jeton jeton){
        if (joueurCourant -> getCouleur() == grille.get(pos)){
            return 1 + checkUpLeft(pos-8, jeton);               // Check si 4 pions similaires diagonale droite gauche bas haut
        }
        else {
            return 0;
        }
}

int Jeu:: checkUpRight (int pos, Jeton jeton){
        if (joueurCourant -> getCouleur() == grille.get(pos)){
            return 1 + checkUpRight(pos-6, jeton);              // Check si 4 pions similaires diagonale gauche droite bas haut
        }
        else {
            return 0;
        }
}

int Jeu::checkDownLeft (int pos, Jeton jeton){
        if (joueurCourant -> getCouleur() == grille.get(pos)){
            return 1 + checkDownLeft(pos+6, jeton);             // Check si 4 pions similaires diagonale droite gauche haut bas
        }
        else {
            return 0;
        }
}

int Jeu ::checkDownRight (int pos, Jeton jeton){
        if (joueurCourant -> getCouleur() == grille.get(pos)){
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
            if (checkLeft(grille.get(pos),joueurCourant -> getCouleur()) >= 4){
                return true;
            }else{
                if (checkUp(grille.get(pos),joueurCourant -> getCouleur()) >= 4) {
                    return true;
                }else{
                    if (checkDown(grille.get(pos),joueurCourant -> getCouleur()) >= 4) {
                        return true;
                    }else{
                        if (checkUpLeft(grille.get(pos),joueurCourant -> getCouleur()) >= 4) {
                            return true;
                        }else{
                            if (checkUpRight(grille.get(pos),joueurCourant -> getCouleur()) >= 4){
                                return true;
                            }else{
                                if (checkDownLeft(grille.get(pos),joueurCourant -> getCouleur()) >= 4) {
                                    return true;
                                }else{
                                    if  (checkDownRight(grille.get(pos),joueurCourant -> getCouleur()) >= 4) {
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


