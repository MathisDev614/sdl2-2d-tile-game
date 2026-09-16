#ifndef TUILE_H_INCLUDED
#define TUILE_H_INCLUDED
#include <SDL_image.h>
#include "Moteur.h"
#include <iostream>
#include <string>

using namespace std;

class Tuile
{
    string _nom; // Le nom de la tuile
    int _skin_x, _skin_y; // Les coordonnées (x, y) du skin de la tuile
    string _propriete; // La propriété de la tuile
public:
    // Constructeur vide
    Tuile();

    // Constructeur
    Tuile(string& nom, int skin_x, int skin_y, string& propriete);

    // Affichage de la tuile
    void afficher() const;

    // Retourne le nom
    string getNom() const;

    // Retourne la coordonnée x du skin
    int getSkinX() const;

    // Retourne la coordonnée y du skin
    int getSkinY() const;

    // Retourne la propriété
    string getPropiete() const;
};

#endif // TUILE_H_INCLUDED
