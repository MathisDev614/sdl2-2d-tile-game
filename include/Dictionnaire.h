#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED

#include <SDL_image.h>
#include "Moteur.h"
#include <iostream>
#include <string>
#include "Tuile.h"
#include <vector>

using namespace std;

class Dictionnaire
{
    vector<Tuile> _tuiles; // Les tuiles du dictionnaire

public:
    // Constructeur vide
    Dictionnaire();

    // Constructeur
    Dictionnaire(const string& nomFic);

    // Affichage du dictionnaire
    void afficher() const;

    // Vérifie si une tuile existe dans le dictionnaire (recherche dichotomique)
    bool recherche(const string& nomTuile, Tuile& tuileTrouvee) const;
};

#endif // DICTIONNAIRE_H_INCLUDED
