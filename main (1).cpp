#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 3; // Taille du plateau
vector<vector<char>> board(SIZE, vector<char>(SIZE, ' ')); // Plateau de jeu

// Affiche le plateau
void displayBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--+---+--" << endl;
    }
    cout << endl;
}

// Vérifie si un joueur a gagné
bool checkWin(char player) {
    // Vérifie les lignes et les colonnes
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Vérifie les diagonales
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Vérifie si le plateau est plein (égalité)
bool isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// Tour de l'IA (basique)
void playAI() {
    srand(time(0)); // Initialisation de la graine pour les nombres aléatoires
    int x, y;
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while (board[x][y] != ' ');
    board[x][y] = 'O'; // L'IA joue 'O'
    cout << "L'IA joue en position (" << x + 1 << ", " << y + 1 << ")\n";
}

// Tour d'un joueur
void playPlayer(const string& playerName, char playerSymbol) {
    int x, y;
    do {
        cout << playerName << " (" << playerSymbol << "), entrez votre position (ligne et colonne entre 1 et " << SIZE << "): ";
        cin >> x >> y;
        x--; y--; // Convertir en index 0-based
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == ' ') {
            board[x][y] = playerSymbol;
            break;
        } else {
            cout << "Position invalide. Réessayez.\n";
        }
    } while (true);
}

int main() {
    string player1, player2;
    char mode;

    cout << "Bienvenue au Tic-tac-toe! 😍 \n";

    // Entrée des noms
    cout << "Entrez le nom du joueur 1 (joue avec 'X'): ";
    cin >> player1;
    cout << "Choisissez un mode : (1) Joueur contre joueur, (2) Joueur contre IA : ";
    cin >> mode;

    string currentPlayerName = player1;
    char currentPlayerSymbol = 'X';

    if (mode == '1') {
        cout << "Entrez le nom du joueur 2 (joue avec 'O'): ";
        cin >> player2;
    } else {
        player2 = "IA";
    }

    bool isAI = (mode == '2');

    while (true) {
        displayBoard();
        if (currentPlayerSymbol == 'X' || !isAI) {
            playPlayer(currentPlayerName, currentPlayerSymbol);
        } else {
            playAI();
        }

        // Vérifie la victoire ou l'égalité
        if (checkWin(currentPlayerSymbol)) {
            displayBoard();
            cout << currentPlayerName << " a gagné! 👏 🎉\n";
            break;
        } else if (isBoardFull()) {
            displayBoard();
            cout << "Match nul! ✖️ \n";
            break;
        }

        // Change de joueur
        if (currentPlayerSymbol == 'X') {
            currentPlayerSymbol = 'O';
            currentPlayerName = player2;
        } else {
            currentPlayerSymbol = 'X';
            currentPlayerName = player1;
        }
    }

    return 0;
}
