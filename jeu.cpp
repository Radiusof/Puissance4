//Fichier comportant le code du constructeur Joueur

#include "jeu.hpp"
#include "joueur.hpp"
using namespace std;

Jeu::Jeu(){

    Jeton attribut_grille[42] {Vide};
    string nom;
    Jeton couleur;

    cout	<< "Nom du premier joueur?" << endl;
    Joueur joueur1 (nom, couleur);
	cin>>nom;
    couleur = Jaune;

    cout << endl << nom << " , tu auras les pions de couleur: Jaune "<< endl;

	cout<<endl<<endl <<"Nom du second joueur ?" << endl;
    Joueur joueur2 (nom, couleur);
    cin>>nom;
    couleur = Rouge;
    cout << endl << nom << " , tu auras les pions de couleur: Rouge"<< endl;

    joueurCourant = &joueur1;

    system("pause");
}