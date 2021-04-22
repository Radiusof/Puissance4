// Puissance 4 C++
#include <iostream>
///Il faut bien faire attention au fichier que tu inclue
///On n'inclue jamais le fichier les fichier d'implémentation (.cpp)
///On inclue que les fichier qui sont utilisé, ici on utilise que la classe Jeu, donc on inclue que jeu.hpp
#include "grille.hpp"
#include "grille.cpp"
#include "joueur.hpp"
#include "joueur.cpp"
#include "jeu.hpp"
#include "jeu.cpp"
using namespace std;


int main()
{
  cout << endl << "     *****************" << endl << "     *  PUISSANCE 4  *" << endl << "     *****************" << endl << endl;

  Jeu jeu;
  jeu.loop();

  return 0;
}
