#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED
#include <SDL_image.h>
#include "Moteur.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Niveau
{
    vector<Objet> _objets; // Les objets du niveau
    int _nbBonus = 0; // Le nombre de bonus du niveau

public:
    // Constructeur vide
    Niveau();

    // Constructeur
    Niveau(Image& img, const string& nomFic, const Dictionnaire& dico);

    // Dessine les objets du niveau
    void dessiner() const;

    // Vérifie si la case est libre
    bool caseEstLibre(int x, int y) const;

    void testerBonusEtPrendre(int x, int y);

    int indiceObjet(int x, int y, const string& propriete) const;

    bool gagne() const;
};

#endif // NIVEAU_H_INCLUDED
