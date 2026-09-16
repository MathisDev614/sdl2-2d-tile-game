#include <vector>
#include <SDL_image.h>
#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Objet.h"
#include "Niveau.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
    // Initialisation du jeu
    Moteur moteur("Mon super jeu vidéo");

    // TODO: charger images, creer personnages, etc.
    Image fond;
    Image personnages;
    Image objets;
    Image bravo;
    Image gameover;
    try
    {
        fond = Image(moteur, "assets/fond.png");
        personnages = Image(moteur,"assets/personnages.png");
        objets = Image(moteur,"assets/objets.png");
        bravo = Image(moteur,"assets/bravo.png");
        gameover = Image(moteur,"assets/gameover.png");
    }
    catch (const runtime_error& e)
    {
        cout << "Erreur : " << e.what() << endl;
    }

    bool quitter = false;
    int xPersonnage = TAILLE_CASE, yPersonnage = 2 * TAILLE_CASE;

    Personnage heros(xPersonnage, yPersonnage, personnages, 4, 0, "bas");
    Personnage ennemi1(5 * TAILLE_CASE, TAILLE_CASE, personnages, 10, 0, "bas");
    Personnage ennemi2(TAILLE_CASE, 5 * TAILLE_CASE, personnages, 7, 4, "gauche");

    Dictionnaire dico("assets/dictionnaire.txt");

    Niveau niveau1(objets, "assets/niveau1.txt", dico);

    // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
    // (en general, 60 fois par seconde)
    while (!quitter)
    {
        // I. Gestion des evenements
        Evenement evenement = moteur.evenementRecu();
        while (evenement != AUCUN)
        {
            switch (evenement)
            {
            // QUITTER = croix de la fenetre ou Echap
            case QUITTER_APPUYE:
                quitter = true;
                break;
            case GAUCHE_APPUYE:
                // Vérifie si la nouvelle position du coffre ne dépasse pas le bord gauche de la grille
                heros.allerGauche(niveau1);
                niveau1.testerBonusEtPrendre(heros.getX(), heros.getY());
                break;
            case DROITE_APPUYE:
                // Vérifie si la nouvelle position du coffre ne dépasse pas le bord droit de la grille
                heros.allerDroite(niveau1);
                niveau1.testerBonusEtPrendre(heros.getX(), heros.getY());
                break;
            case HAUT_APPUYE:
                // Vérifie si la nouvelle position du coffre ne dépasse pas le bord supérieur de la grille
                heros.allerHaut(niveau1);
                niveau1.testerBonusEtPrendre(heros.getX(), heros.getY());
                break;
            case BAS_APPUYE:
                // Vérifie si la nouvelle position du coffre ne dépasse pas le bord inférieur de la grille
                heros.allerBas(niveau1);
                niveau1.testerBonusEtPrendre(heros.getX(), heros.getY());
                break;
            // TODO: gerer les autres evenements
            default:
                break;
            }

            evenement = moteur.evenementRecu();
        }

        // II. Mise à jour de l'état du jeu
        if (niveau1.gagne())
        {
            bravo.dessiner(30, 10); // Dessiner l'image "bravo.png" sur l'écran
            moteur.finaliserRendu();
            moteur.attendre(2); // Pause de 2 secondes avant de quitter
            quitter = true;
        }

        if (heros.touche(ennemi1) || heros.touche(ennemi2))
        {
            gameover.dessiner(30, 10); // Dessiner l'image "gameover.png" sur l'écran
            moteur.finaliserRendu();
            moteur.attendre(2);
            quitter = true;
        }

        // TODO: faire bouger vos personnages, etc.
        if (moteur.animationsAmettreAjour())
        {
            heros.mettreAjourAnimation();
            ennemi1.avancer(niveau1);
            ennemi2.avancer(niveau1);
            ennemi1.mettreAjourAnimation();
            ennemi2.mettreAjourAnimation();
        }

        // III. Generation de l'image à afficher
        moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

        // TODO: afficher vos personnages, objets, etc.
        niveau1.dessiner();
        heros.dessiner();
        ennemi1.dessiner();
        ennemi2.dessiner();

        /*
          Affiche l'image en se cadencant sur la frequence de
          rafraichissement de l'ecran (donc va en general mettre le
          programme en pause jusqu'a ce que l'ecran soit rafraichi). En
          general, 60 images fois par seconde, mais ca peut dependre du
          materiel
        */
        moteur.finaliserRendu();
    }

    return 0;
}
