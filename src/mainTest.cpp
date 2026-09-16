#include <string>
#include <vector>
#include <SDL_image.h>
#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Objet.h"

using namespace std;

const string STOP = "STOP";

int main(int, char**) // Version special du main, ne pas modifier
{
    Dictionnaire dico("assets/dictionnaire.txt");
    string nomTuile;
    Tuile tuileTrouvee;

    dico.afficher();

    while (nomTuile != STOP)
    {
        cout << "Saisissez le nom de la tuile : ";
        cin >> nomTuile;
        if (dico.recherche(nomTuile, tuileTrouvee))
        {
            cout << "Tuile trouvee : " << tuileTrouvee.getNom() << endl;
        }
        else
        {
            cout << "Tuile non trouvee." << endl;
        }
    }

    return 0;
}
