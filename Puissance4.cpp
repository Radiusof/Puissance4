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
  
  cout << endl << "     *****************" << endl << "     *  PUISSANCE 4  *" << endl << "     *****************" << endl << endl;  

  
  Jeu jeu;
  jeu.loop();

  cout << "Merci" << endl<<endl<<endl;


  return 0;

}  


