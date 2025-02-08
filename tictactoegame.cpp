#include <iostream>
#include <ctime>
#include <cstdlib>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running) {
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        if (checkTie(spaces)) {
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        if (checkTie(spaces)) {
            running = false;
            break;
        }
    }

    return 0;
}

void drawBoard(char *spaces) {
    std::cout << "\n";
    std::cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << " \n";
    std::cout << "\n";
}

void playerMove(char *spaces, char player) {
    int move;
    do {
        std::cout << "Enter a position (1-9): ";
        std::cin >> move;
        move--;
    } while (move < 0 || move > 8 || spaces[move] != ' ');

    spaces[move] = player;
}

void computerMove(char *spaces, char computer) {
    int move;
    srand(time(0));
    do {
        move = rand() % 9;
    } while (spaces[move] != ' ');

    spaces[move] = computer;
}

bool checkWinner(char *spaces, char player, char computer) {
    char winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (auto &combo : winCombos) {
        if (spaces[combo[0]] == player && spaces[combo[1]] == player && spaces[combo[2]] == player) {
            std::cout << "Player wins!\n";
            return true;
        }
        if (spaces[combo[0]] == computer && spaces[combo[1]] == computer && spaces[combo[2]] == computer) {
            std::cout << "Computer wins!\n";
            return true;
        }
    }
    return false;
}

bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    std::cout << "It's a tie!\n";
    return true;
}
