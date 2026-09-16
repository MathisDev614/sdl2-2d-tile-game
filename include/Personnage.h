#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include <SDL_image.h>
#include "Moteur.h"
#include <iostream>
#include <string>
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Objet.h"
#include "Niveau.h"

using namespace std;

class Personnage
{
    int _x, _y; // Les coordonnées (x, y) du personnage
    Image _image; // L'image du personnage
    int _skin_x, _skin_y; // Les coordonnées (x, y) du skin du personnage
    string _direction; // La direction du personnage
    int _etapeAnimation = 0; // L'étape de l'animation du personnage
public:
    // Constructeur vide
    Personnage();

    // Constructeur
    Personnage(int x, int y, const Image& image, int skin_x, int skin_y, string direction);

    // Dessine le personnage
    void dessiner() const;

    // Avance le personnage a droite
    void allerDroite(Niveau& niv);

    // Avance le personnage a gauche
    void allerGauche(Niveau& niv);

    // Avance le personnage en haut
    void allerHaut(Niveau& niv);

    // Avance le personnage en bas
    void allerBas(Niveau& niv);

    // Vérifie si le bord est atteint
    bool bordAtteint(int largeurFenetre, int hauteurFenetre);

    // Met a jour la direction du personnage
    void mettreAJourDirection();

    // Avance les ennemis aléatoirement
    void avancer(Niveau& niv);

    // Vérifie si le personnage a touché un ennemi
    bool touche(Personnage& p) const;

    // Met a jour les animations du personnage
    void mettreAjourAnimation();

    int getX() const;

    int getY() const;
};

#endif // PERSONNAGE_H_INCLUDED
