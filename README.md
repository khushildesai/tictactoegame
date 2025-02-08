# Tic-Tac-Toe Game

This is a simple Tic-Tac-Toe game implemented in C++.

## Features
- Allows a human player to play against a computer.
- Randomized computer moves.
- Displays the game board after each turn.
- Checks for a winner or a tie.

## How to Run
1. Compile the program using a C++ compiler:
   ```sh
   g++ tic_tac_toe.cpp -o tic_tac_toe
   ```
2. Run the compiled program:
   ```sh
   ./tic_tac_toe
   ```

## Game Rules
- The game board consists of 9 spaces indexed from 1 to 9.
- The player is 'X' and the computer is 'O'.
- Players take turns marking an empty space.
- The game ends when a player wins or when all spaces are filled (tie).

## Code Structure
- `drawBoard(char *spaces)`: Displays the game board.
- `playerMove(char *spaces, char player)`: Handles player's move.
- `computerMove(char *spaces, char computer)`: Generates a random move for the computer.
- `checkWinner(char *spaces, char player, char computer)`: Checks if there is a winner.
- `checkTie(char *spaces)`: Checks if the game is a tie.

## Example Output
```
Enter a position (1-9): 5
 X |   |   
---|---|---
   | X |   
---|---|---
   |   |   
```

## License
This project is open-source and free to use.
