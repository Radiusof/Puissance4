// Puissance 4 C++
#include <iostream>

#include "grille.hpp"
#include "jeu.hpp"
#include "joueur.hpp"
#include "jeu.cpp"
#include "joueur.cpp"
#include "grille.cpp"

// le compiler ne trouve que le fichier Puissance4.cpp
//Probléme à régler (check tutoriel Make ?) 
// Obliger d'inclure tout les fichiers pour que Puissance4.exe puisse être généré. (solution temporaire)

///Il faut bien faire attention au fichier que tu inclue
///On n'inclue jamais le fichier les fichier d'impl�mentation (.cpp)
///On inclue que les fichier qui sont utilis�, ici on utilise que la classe Jeu, donc on inclue que jeu.hpp

using namespace std;


int main(){
  
  cout << endl << "     *****************" << endl << "     *  PUISSANCE 4  *" << endl << "     *****************" << endl << endl;

  Jeu jeu;
  jeu.loop();

  return 0;
  }

  