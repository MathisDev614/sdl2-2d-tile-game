# 2D Grid Game — C++ & SDL2

Jeu 2D en grille développé en C++ avec la bibliothèque multimédia SDL2 (et SDL_image). Le projet propose un moteur basé sur un système de tuiles (tile-based), un chargement dynamique de niveaux depuis des fichiers textes, ainsi qu'un système d'animations par spritesheet et de détection de collisions.

---

## 🎮 Fonctionnalités du jeu

- **Déplacements sur grille :** Déplacement case par case du héros au clavier (flèches directionnelles).
- **Gestion des collisions :** Détection des obstacles solides (`solide`) et des limites de l'écran.
- **Ennemis autonomes :** Deux ennemis se déplacent de manière aléatoire sur la grille. Tout contact avec le joueur provoque un *Game Over*.
- **Système de bonus :** Récupération de l'ensemble des bonus de la carte pour débloquer l'écran de victoire.
- **Animations de sprites :** Gestion de cycles d'animation de marche (8 FPS) découpés depuis une feuille de sprites (*spritesheet*).

---

## ⚙️ Architecture technique

- **Conception Orientée Objet (C++) :**
  - `Moteur` : Wrapper autour de SDL2 (gestion de la fenêtre, boucle d'événements, rendu VSync à 60 FPS).
  - `Image` : Encapsulation de `SDL_Surface` et `SDL_Texture` avec gestion mémoire sécurisée via `std::shared_ptr` et un destructeur personnalisé (`Texture_deleter`).
  - `Dictionnaire` : Chargement et indexation des tuiles avec implémentation d'une **recherche dichotomique** en O(log n).
  - `Niveau` & `Objet` : Parsing des fichiers de données, instanciation des tuiles et gestion des états (`solide`, `bonus`, `cache`).
  - `Personnage` : Gestion de l'orientation, des déplacements sur la grille, de l'état d'animation et des collisions inter-entités.

---

## 🛠️ Prérequis

- Compilateur C++ supportant au minimum C++11 (`g++`, `clang++` ou MSVC)
- Bibliothèques de développement :
  - SDL2
  - SDL2_image

### Installation des dépendances

**Sur Ubuntu / Debian :**
```bash
sudo apt update
sudo apt install libsdl2-dev libsdl2-image-dev make

```

**Sur macOS (Homebrew) :**

```bash
brew install sdl2 sdl2_image make

```

---

## 🚀 Compilation et Exécution

### Via le Makefile (recommandé)

```bash
# Compilation
make

# Lancer le jeu
./bin/main

```

### Manuellement avec g++

```bash
# Compilation
g++ -std=c++11 -Wall -Iinclude src/*.cpp -o jeu_sdl $(sdl2-config --cflags --libs) -lSDL2_image

# Lancer le jeu
./jeu_sdl

```

---

## 📂 Organisation du dépôt

```text
├── assets/
│   ├── dictionnaire.txt   # Définition des tuiles et propriétés
│   ├── niveau1.txt        # Description de la carte du niveau
│   ├── personnages.png    # Spritesheet du joueur et des ennemis
│   ├── objets.png         # Spritesheet des tuiles et éléments de décor
│   ├── fond.png           # Image de fond
│   ├── bravo.png          # Écran de victoire
│   ├── gameover.png       # Écran de défaite
│   └── preview.png        # Capture d'écran pour la documentation
├── include/               # Fichiers d'en-tête (.h)
├── src/                   # Fichiers sources (.cpp)
├── Makefile               # Script de compilation
├── LICENSE                # Licence open-source
└── README.md              # Documentation du projet

```

---

## 📄 Licence

Ce projet est sous licence MIT. Consultez le fichier [LICENSE](https://www.google.com/search?q=LICENSE) pour plus d'informations.
