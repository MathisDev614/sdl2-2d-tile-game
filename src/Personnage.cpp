#include <SDL_image.h>
#include <exception>
#include <string>
#include "Image.h"
#include "Personnage.h"
#include "Moteur.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Objet.h"
#include "Niveau.h"

using namespace std;

Personnage::Personnage() {}

Personnage::Personnage(int x, int y, const Image& image, int skin_x, int skin_y, string direction)
{
    _x = x;
    _y = y;
    _image = image;
    _skin_x = skin_x;
    _skin_y = skin_y;
    _direction = direction;
    mettreAJourDirection();
}

void Personnage::dessiner() const
{
    _image.dessiner(_x, _y);
}

bool Personnage::bordAtteint(int largeurFenetre, int hauteurFenetre)
{
    if (_direction == "bas" && _y + TAILLE_CASE >= hauteurFenetre) return true;
    if (_direction == "haut" && _y <= 0) return true;
    if (_direction == "droite" && _x + TAILLE_CASE >= largeurFenetre) return true;
    if (_direction == "gauche" && _x <= 0) return true;
    return false;
}

void Personnage::allerDroite(Niveau& niv)
{
    _direction = "droite";

    if (!bordAtteint(LARGEUR_FENETRE, HAUTEUR_FENETRE) && niv.caseEstLibre(_x + TAILLE_CASE, _y))
    {
        _x += TAILLE_CASE;
    }

    mettreAJourDirection();
}

void Personnage::allerGauche(Niveau& niv)
{
    _direction = "gauche";

    if (!bordAtteint(LARGEUR_FENETRE, HAUTEUR_FENETRE) && niv.caseEstLibre(_x - TAILLE_CASE, _y))
    {
        _x -= TAILLE_CASE;
    }

    mettreAJourDirection();
}

void Personnage::allerHaut(Niveau& niv)
{
    _direction = "haut";

    if (!bordAtteint(LARGEUR_FENETRE, HAUTEUR_FENETRE) && niv.caseEstLibre(_x, _y - TAILLE_CASE))
    {
        _y -= TAILLE_CASE;
    }

    mettreAJourDirection();
}

void Personnage::allerBas(Niveau& niv)
{
    _direction = "bas";

    if (!bordAtteint(LARGEUR_FENETRE, HAUTEUR_FENETRE) && niv.caseEstLibre(_x, _y + TAILLE_CASE))
    {
        _y += TAILLE_CASE;
    }

    mettreAJourDirection();
}

void Personnage::mettreAJourDirection()
{
    if (_direction == "droite")
        _image.selectionnerRectangle(_skin_x * TAILLE_CASE, (_skin_y + 2) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    else if (_direction == "gauche")
        _image.selectionnerRectangle(_skin_x * TAILLE_CASE, (_skin_y + 1) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    else if (_direction == "haut")
        _image.selectionnerRectangle(_skin_x * TAILLE_CASE, (_skin_y + 3) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    else if (_direction == "bas")
        _image.selectionnerRectangle(_skin_x * TAILLE_CASE, _skin_y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
}

void Personnage::avancer(Niveau& niv)
{
    int direction = rand() % 4; // Tire un nombre aléatoire entre 0 et 3
    switch (direction)
    {
        case 0:
            allerHaut(niv);
            break;
        case 1:
            allerBas(niv);
            break;
        case 2:
            allerGauche(niv);
            break;
        case 3:
            allerDroite(niv);
            break;
    }
}

bool Personnage::touche(Personnage& p) const
{
    bool touche = (_x == p._x && _y == p._y);
    return touche;
}

void Personnage::mettreAjourAnimation()
{
    _etapeAnimation = (_etapeAnimation + 1) % 4;
    int yOffset = 0;

    // Définir le décalage vertical selon la direction
    if (_direction == "haut")
        yOffset = 3;
    else if (_direction == "droite")
        yOffset = 2;
    else if (_direction == "gauche")
        yOffset = 1;

    // Calculer la position x et y pour la sélection de l'image
    int xPos = _skin_x * TAILLE_CASE;
    int yPos = (_skin_y + yOffset) * TAILLE_CASE;

    // Sélectionner le rectangle en fonction de l'étape d'animation
    if (_etapeAnimation == 0 || _etapeAnimation == 2)
        _image.selectionnerRectangle(xPos, yPos, TAILLE_CASE, TAILLE_CASE);
    else
    {
        int xOffset = (_etapeAnimation == 1) ? -1 : 1; // Déterminer si on déplace à gauche ou à droite
        _image.selectionnerRectangle((xPos + xOffset * TAILLE_CASE), yPos, TAILLE_CASE, TAILLE_CASE);
    }
}

int Personnage::getX() const {
    return _x;
}

int Personnage::getY() const {
    return _y;
}
