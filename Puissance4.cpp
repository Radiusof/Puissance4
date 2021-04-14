// Puissance 4 C++
#include <iostream>
#include "grille.hpp"
#include "grille.cpp"
#include "joueur.hpp"
#include "joueur.cpp"
#include "jeu.hpp"
#include "jeu.cpp"
using namespace std;


int main ()
{
  //Jeton attribut_grille[42];
  cout << endl << "     *****************" << endl << "     *  PUISSANCE 4  *" << endl << "     *****************" << endl << endl;  

  Grille grille;

  grille.show();

  
  cout << endl<<endl<<endl;

  char x;
  cout << "Press any button to start a game" << endl;
  cin >> x;

  return 0;

}

