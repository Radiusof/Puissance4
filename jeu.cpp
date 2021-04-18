//Fichier comportant le code du constructeur Jeu

// erreur fichier temporaire, check les const

#include <memory>
#include "jeu.hpp"
#include "joueur.hpp"
using namespace std;

Jeu::Jeu(){

    Jeton attribut_grille[42] {Vide};
    string  nom;
    Jeton couleur;
    
    cout	<< "Nom du premier joueur?" << endl;
    
	cin>>nom;
    couleur = Jaune;

    Joueur joueur1 (nom, couleur);          
    
    cout << endl << nom << " , tu auras les jetons de couleur: Jaune [o] "<< endl<<endl;

	cout<<endl<<endl <<"Nom du second joueur ?" << endl;
    
    cin>>nom;
    couleur = Rouge;
    cout << endl << nom << " , tu auras les jetons de couleur: Rouge [x] "<< endl<<endl;

    Joueur joueur2 (nom, couleur);
    
    joueurCourant = new Joueur (joueur1);    // Initialise le pointeur joueurCourant sur le premier joueur
          

    cout<< "Le joueur demarrant la partie sera " << joueurCourant -> getNom()<< endl << endl;

    system("pause");

    
}
