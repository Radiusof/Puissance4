#include "functions.hpp"
using namespace std;

Grille::Grille(){                               //Reset la Grille
            int i =0;
            while (attribut_grille){
                if (i < 42){
                attribut_grille[i] = Vide;
                i++;
                }
                else {
                    break;
                }
            }           
        }



