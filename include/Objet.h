#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <SDL_image.h>
#include "Moteur.h"
#include <iostream>
#include <string>

using namespace std;

class Objet
{
    Image _image; // L'image de l'objet
    int _x, _y; // Les coordonnées (x, y) de l'objet
    string _propriete; // La propriété de l'objet
public:
    // Constructeur vide
    Objet();

    // Constructeur
    Objet(Image& img, string& nomObjet, const Dictionnaire& dico, int x, int y);

    // Dessine l'objet
    void dessiner() const;

    // Retourne la coordonnée x
    int getX() const;

    // Retourne la coordonnée y
    int getY() const;

    // Retourne la propriété
    string getPropiete() const;

    void cache();
};

#endif // OBJET_H_INCLUDED
