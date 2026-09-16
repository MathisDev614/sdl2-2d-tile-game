#include <SDL_image.h>
#include <exception>
#include <string>
#include "Image.h"
#include "Moteur.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Objet.h"
#include <fstream>
#include <stdexcept>

using namespace std;

Objet::Objet() {}

Objet::Objet(Image& img, string& nomObjet, const Dictionnaire& dico, int x, int y)
{
    Tuile tuileTrouvee;
    dico.recherche(nomObjet, tuileTrouvee);
    _image = img;
    _image.selectionnerRectangle(tuileTrouvee.getSkinX() * TAILLE_CASE, tuileTrouvee.getSkinY() * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    _propriete = tuileTrouvee.getPropiete();
    _x = x * TAILLE_CASE;
    _y = y * TAILLE_CASE;
}

void Objet::dessiner() const
{
    _image.dessiner(_x, _y);
}

int Objet::getX() const
{
    return _x;
}

int Objet::getY() const
{
    return _y;
}

string Objet::getPropiete() const
{
    return _propriete;
}

void Objet::cache() {
    _propriete = "cache";
}
