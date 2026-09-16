#include <SDL_image.h>
#include <exception>
#include <string>
#include <stdexcept>
#include <fstream>
#include "Image.h"
#include "Moteur.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Objet.h"
#include "Niveau.h"

using namespace std;

Niveau::Niveau() {}

Niveau::Niveau(Image& img, const string& nomFic, const Dictionnaire& dico)
{
    ifstream entree(nomFic);
    if (!entree)
    {
        throw runtime_error("Impossible d'ouvrir le fichier : " + nomFic);
    }

    string nomObjet;
    int x, y, nbO;

    entree >> nbO; // Lire le nombre de objets
    for (int i = 0; i < nbO; ++i)
    {
        entree >> nomObjet >> x >> y;
        if (entree)   // Vérifier que la ligne a bien été lue
        {
            Objet o(img, nomObjet, dico, x, y);
            _objets.push_back(o); // Ajouter l'objet à la liste
            if (o.getPropiete() == "bonus")
            {
                ++_nbBonus;
            }
        }
        else
        {
            throw runtime_error("Erreur lors de la lecture des données du fichier.");
        }
    }

    entree.close();
}

void Niveau::dessiner() const
{
    for (int i = 0; i < _objets.size(); i++)
    {
        if (_objets[i].getPropiete() != "cache")
            _objets[i].dessiner();
    }
}

bool Niveau::caseEstLibre(int x, int y) const
{
    if (this->indiceObjet(x, y, "solide") != -1)
        return false;
    else
        return true;
    /*
    for (int i = 0; i < _objets.size(); ++i)
    {
        if (_objets[i].getPropiete() == "solide" && _objets[i].getX() == x && _objets[i].getY() == y)
        {
            return false;
        }
    }
    return true;
    */
}

void Niveau::testerBonusEtPrendre(int x, int y)
{
    int ind = this->indiceObjet(x, y, "bonus");
    if (ind != -1)
    {
        // Décrémenter le compteur de bonus restants
        --_nbBonus;
        // Modifier directement la propriété de l'objet pour la marquer comme "cache"
        _objets[ind].cache();
    }

    /*
    for (int i = 0; i < _objets.size(); ++i) {
        // Vérifie si l'objet est un bonus et s'il est à la position spécifiée
        if (_objets[i].getPropiete() == "bonus" && _objets[i].getX() == x && _objets[i].getY() == y) {
            // Décrémenter le compteur de bonus restants
            --_nbBonus;
            // Modifier directement la propriété de l'objet pour la marquer comme "cache"
            _objets[i].cache();
            // Retourne true pour indiquer qu'un bonus a été pris
            return true;
        }
    }
    // Retourne false si aucun bonus n'a été trouvé
    return false;
    */
}

int Niveau::indiceObjet(int x, int y, const string& propriete) const
{
    for (int i = 0; i < _objets.size(); ++i)
    {
        if (_objets[i].getPropiete() == propriete)
        {
            if (_objets[i].getX() == x && _objets[i].getY() == y)
            {
                return i;
            }
        }
    }
    return -1;
}

bool Niveau::gagne() const
{
    return _nbBonus == 0;
}
