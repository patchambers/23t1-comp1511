// Function to check whether has won a game of tic tac toe
// Patrick Chambers (z5264081), 12/10/22

#include <stdio.h>

#define SIZE 5

int did_player_win(char player, char board[SIZE][SIZE]);

int main(void) {
    char no_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', ' ', ' ', ' ', 'O'},
    };
    char x_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {' ', 'X', ' ', ' ', 'O'},
    };
    char o_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };

    if (did_player_win('X', x_wins_board)) {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', x_wins_board)) {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}

// Check whether the player has won the game by getting SIZE tokens in a row, 
// in any direction
// Takes a char representing a player and the 2D array representing the board
// Returns 1 if this player has won, returns 0 otherwise
int did_player_win(char player, char board[SIZE][SIZE]) {

    // Check whether player has won with a row
    // Loop through each row, check whether 5 of the player's
    // symbol exists there
    for (int row = 0; row < SIZE; row++) {
        int count = 0;
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == player) {
                count++;
            }
        }
        if (count == SIZE) {
            return 1;
        }
    }

    // Check columns in the same way as rows
    for (int col = 0; col < SIZE; col++) {
        int count = 0;
        for (int row = 0; row < SIZE; row++) {
            if (board[row][col] == player) {
                count++;
            }
        }
        if (count == SIZE) {
            return 1;
        }
    }

    // Check diagonals (main diagonal, reverse diagonal)
    int count_main = 0;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][i] == player) {
            count_main++;
        }
    }
    if (count_main == SIZE) {
        return 1;
    }

    int count_reverse = 0;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][SIZE - i - 1] == player) {
            count_reverse++;
        }
    }
    if (count_reverse == SIZE) {
        return 1;
    }
            
    // If none of the win conditions are met, return 0 to show that the player
    // has not won
    return 0;
}

