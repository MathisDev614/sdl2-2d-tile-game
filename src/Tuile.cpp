#include <SDL_image.h>
#include <exception>
#include <string>
#include "Image.h"
#include "Tuile.h"
#include "Moteur.h"

using namespace std;

Tuile::Tuile() {}

Tuile::Tuile(string& nom, int skin_x, int skin_y, string& propriete)
{
    _nom = nom;
    _skin_x = skin_x;
    _skin_y = skin_y;
    _propriete = propriete;
}

void Tuile::afficher() const
{
    cout << _nom << ": x = " << _skin_x << ", y = " << _skin_y << ", objet " << _propriete << endl;
}

string Tuile::getNom() const
{
    return _nom;
}

int Tuile::getSkinX() const
{
    return _skin_x;
}

int Tuile::getSkinY() const
{
    return _skin_y;
}

string Tuile::getPropiete() const
{
    return _propriete;
}
