# jeu-Morpion
Ce programme est une implémentation simple d'un jeu de Tic-Tac-Toe (morpion) en C++, jouable soit entre deux joueurs humains, soit contre une IA basique.

# Fonctionnalités:
 Mode Joueur contre Joueur : Deux joueurs s'affrontent en prenant tour à tour des cases sur un plateau 3x3.
 Mode Joueur contre IA : Le joueur affronte une intelligence artificielle qui joue de manière aléatoire.
 Détection automatique de la victoire, de l'égalité et affichage du plateau à chaque tour.
# Structure du code:
 ## 1. Constantes et Variables Globales:
const int SIZE = 3 : Taille du plateau (3x3 dans ce cas).
vector<vector<char>> board(SIZE, vector<char>(SIZE, ' ')) : Représente le plateau de jeu comme une matrice de caractères initialisée avec des espaces vides ' '.
 ## 2. Fonctions principales:
void displayBoard()
- Affiche l'état actuel du plateau de jeu avec un format lisible.
- Inclut des séparateurs pour rendre l'affichage esthétique.
bool checkWin(char player):
- Vérifie si un joueur a gagné.
- Implémente des vérifications pour :
* Lignes
* Colonnes
* Diagonales
- Renvoie true si le joueur spécifié (player) a trois symboles alignés.
   bool isBoardFull()
- Vérifie si le plateau est complètement rempli.
- Parcourt toutes les cases de la matrice et renvoie true si aucune n'est vide.
  void playAI()
- Implémente le tour de l'IA :
* Génère aléatoirement une position libre sur le plateau.
* Joue le symbole 'O' sur cette position.
* Utilise srand et rand pour générer des nombres aléatoires.
void playPlayer(const string& playerName, char playerSymbol)
-Gère le tour d'un joueur humain :
* Demande à l'utilisateur d'entrer une position (ligne et colonne).
* Vérifie la validité de l'entrée (indices dans les limites, case vide).
* Met à jour le plateau avec le symbole du joueur (X ou O).
 ## 3. Fonction principale main()
Affiche un message de bienvenue et demande les informations de base :
* Nom du joueur 1.
* Mode de jeu : Joueur contre joueur (1) ou Joueur contre IA (2).
Si mode joueur contre joueur, demande également le nom du joueur 2.
* Boucle principale du jeu :
    Affiche le plateau.
    Appelle la fonction appropriée pour jouer (playPlayer ou playAI).
    Vérifie la condition de victoire ou d'égalité après chaque tour.
    Change de joueur à chaque itération.
* Affiche le résultat final (victoire ou match nul) avant de terminer.
