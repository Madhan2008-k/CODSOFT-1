#include <iostream>
using namespace std;

char board[3][3]; // 3x3 game board

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';
    int row, col;
    char playAgain;

    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        cout << "Welcome to Tic-Tac-Toe!\n";
        displayBoard();

        while (!gameOver) {
            cout << "Player " << currentPlayer << ", enter your move (row and column: 1-3): ";
            cin >> row >> col;

            // Validate input
            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            // Update board
            board[row-1][col-1] = currentPlayer;
            displayBoard();

            // Check for win
            if (checkWin(currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            }
            // Check for draw
            else if (checkDraw()) {
                cout << "It's a draw!\n";
                gameOver = true;
            }
            // Switch players
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}