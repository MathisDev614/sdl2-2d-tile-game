#include <SDL_image.h>
#include <exception>
#include <string>
#include "Image.h"
#include "Moteur.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include <fstream>
#include <stdexcept>

using namespace std;

Dictionnaire::Dictionnaire() {}

Dictionnaire::Dictionnaire(const string& nomFic)
{
    ifstream entree(nomFic);
    if (!entree) {
        throw runtime_error("Impossible d'ouvrir le fichier : " + nomFic);
    }

    string nom, propriete;
    int x, y, nbT;

    entree >> nbT; // Lire le nombre de tuiles
    for (int i = 0; i < nbT; ++i) {
        entree >> nom >> x >> y >> propriete;
        if (entree) { // Vérifier que la ligne a bien été lue
            Tuile t(nom, x, y, propriete);
            _tuiles.push_back(t); // Ajouter l'objet à la liste
        } else {
            throw runtime_error("Erreur lors de la lecture des données du fichier.");
        }
    }

    entree.close();
}


void Dictionnaire::afficher() const
{
    for (int i = 0; i < _tuiles.size(); i++)
        _tuiles[i].afficher();
}

bool Dictionnaire::recherche(const string& nomTuile, Tuile& tuileTrouvee) const
{
    int debut = 0;
    int fin = _tuiles.size() - 1;
    int milieu;

    while (debut <= fin)
    {
        milieu = (debut + fin) / 2;

        if (nomTuile == _tuiles[milieu].getNom())
        {
            tuileTrouvee = _tuiles[milieu]; // Renvoie l'objet trouvé
            return true;
        }
        else if (nomTuile < _tuiles[milieu].getNom())
        {
            fin = milieu - 1; // Aller "à gauche"
        }
        else
        {
            debut = milieu + 1; // Aller "à droite"
        }
    }

    return false; // L'élément n'a pas été trouvé
}
