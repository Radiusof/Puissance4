// Fichier comportant le code du constructeur Grille.

#include "grille.hpp"
#include "joueur.hpp"
#include "jeu.hpp"

using namespace std;

Joueur joueur;


Grille::Grille () {                              //Reset la Grille

    for(int i=0;i<42;i++){
        grille[i] = Vide;
    }
} 

 bool Grille::put (int colonne, Jeton jeton){
    int pos;

    bool pleine = false;                                                                 // boolean annonçant si la colonne est pleine ou non   
                                                                    
        for(int i=5;i >= 0; i--) {                                              
               while (not pleine && grille[colonne + 7*i] != Vide){                      // Loop du moment que pleine not true et que la position scanné n'est pas Vide
                   if (colonne + 7*i == colonne && grille[colonne + 7*i] != Vide) {      // Si l'analyse tombe sur le même nombre correspondant à la position sur la grille et entré par l'utilisateur (colonne) ET que cette position n'est pas Vide => Colonne pleine 
                      
                       cout << "Colonne pleine! Choisis une autre colonne" << endl;
                       cin.clear();
                        
                        while (true){                                                    // Boucle de vérification de saisie  => la fonction put étant rappellé, la vérification se fait à l'intérieur de ctte fonction.
                            cin >> colonne;                                     
                            if (colonne < 0  || colonne > 6 ){                           // si saisie inférieur ou égal à -1 ou supérieur à 6 => erreur

                            cout << "Ce chiffre ne fonctionne pas . Selectionne une colonne pour placer le jeton. " << " 0 , 1 , 2 , 3 , 4 , 5 , 6 " << endl << endl;

                            cin.clear();                                                  // On remet cin dans un état valide et vide le buffer
                            
                            continue;

                            } else if (cin.fail()){                                       // si saisie n'est pas un int => erreur

                            cerr << "Erreur, saisie incorrecte." << " Selectionne une colonne pour placer le jeton. "<< " 0 , 1 , 2 , 3 , 4 , 5 , 6 " <<  endl << endl;

                            cin.clear();                                                  // On remet cin dans un état valide et vide le buffer
                            cin.ignore(1,'\n');                                           //Evite de boucler l'erreur, demande d'ignoner les char

                            continue;

                            } else {

                            break;                                                         // sort de la boucle si saisie correcte
                            }
                        }
                    
                    return pleine = true + put (colonne, jeton);                                             // Retourne  bool pleine= true et rappelle la fonction put() => évite de boucler le message d'erreur + permet au joueur de replacer correctement son pion
                                                                              
                       
                   } else {
                     i--;                                                                  // Sinon, décrémente
                   }
                }
            if (not pleine){                                                               // Une fois sortie de la boucle, si pleine not true, place le jeton sur la grille et retourne true
                grille [colonne + 7*i] = jeton;
                return  true;
                break;
            }else {                                                                        // Sinon, retourne faux
                return false;
                break;
            }
         
        }          
    }               

int Grille::pos (int colonne){                                  // Indique la position du jeton mis par le joueur
        for(int i=0; i <= 5; i++){
            if (grille[colonne + 7*i] != Vide){
                return colonne + 7*i;
            } 
        }   
    }

Jeton Grille::get(int pos){                                  //Retourne la couleur du jeton à la position passée en paramètre.

        if (pos == Jaune){
            return grille[pos] = Jaune;
                    
        }else if (pos == Rouge){
            return grille[pos] = Rouge;  
        }
             
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


int Grille::checkRight (int pos, Jeton jeton){
    
        if (grille[pos] == jeton) {
            return 1 + checkRight( pos + 1, jeton);               // Check si 4 pions similaires à droite
        }
        else {
            return 0;
        }
       
            
}

int Grille::checkLeft (int pos, Jeton jeton){
  
        if (grille[pos] == jeton) {
            return 1 + checkLeft( pos - 1, jeton);                // Check si 4 pions similaires à Gauche
            }
        else {
            return 0;
            }
            
}

int Grille::checkUp (int pos, Jeton jeton){
     
        if (grille[pos] == jeton) {
            return 1 + checkUp( pos - 7, jeton);                  // Check si 4 pions similaires en haut
            }
        else {
            return 0;
            }
            
}

int Grille:: checkDown (int pos, Jeton jeton){
      
        if (grille[pos] == jeton) {
            return 1 + checkDown( pos + 7, jeton);                // Check si 4 pions similaires en Bas
            }
        else {
            return 0;
            }
             
}

int Grille::checkUpLeft (int pos, Jeton jeton){
    
        if (grille[pos] == jeton)  {
            return 1 + checkUpLeft( pos - 8 , jeton);               // Check si 4 pions similaires diagonale droite gauche bas haut
        }
        else {
            return 0;
        }
       
}

int Grille:: checkUpRight (int pos, Jeton jeton){
        
        if (grille[pos] == jeton)  {
            return 1 + checkUpRight( pos- 6 , jeton);              // Check si 4 pions similaires diagonale gauche droite bas haut
        }
        else {
            return 0;
        }
       
}

int Grille::checkDownLeft (int pos, Jeton jeton){
      
        if (grille[pos] == jeton) {
            return 1 + checkDownLeft( pos + 6, jeton);             // Check si 4 pions similaires diagonale droite gauche haut bas
        }
        else {
            return 0;
        }
         
}

int Grille ::checkDownRight (int pos, Jeton jeton){
      
        if (grille[pos] == jeton)  {
                return 1 + checkDownRight( pos + 8 , jeton);        // Check si 4 pions similaires diagonale gauche droite haut bas
        }
        else {
             return 0;
        }
       
}


