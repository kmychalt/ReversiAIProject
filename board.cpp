#include <iostream>
#include "board.h"

using namespace std;

/*PURPOSE: constructor, initializes pieces on the board to the starting position
 */
Board::Board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1] = 1;
    board[BOARD_SIZE / 2][BOARD_SIZE / 2] = 1;
    board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2] = 2;
    board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1] = 2;
}

/* PARAMETERS: pointer to fitness array
 * RETURN VALUE: reference to fitness array
 * PURPOSE: to return an array that contains two values: the first being the 
 * fitness value for white, and the second value being the fitness value for
 * black. In this function we are going to reuse the function that we already
 * wrote that gets fitness with one parameter
 */
int& Board::getFitness(int* fitness) {
    fitness[0] = getFitness(1);
    fitness[1] = getFitness(2);
    cout << "Fitness for white is: " << fitness[0] << endl;
    cout << "Fitness for black is: " << fitness[1] << endl;
    
}

/* PARAMETERS: integer color that corresponds to the color on the board being 
 * analyzed for fitness
 * RETURN VALUE: integer of fitness value, or number of time that color appears 
 * on the board
 * PURPOSE: To be able to easily tell how many of a specific color are 
 * on the board
 */
int Board::getFitness(int color) {
    int count = 0;
    if (color != 1 || color != 2)
        cout << "An error has occurred. The wrong integer has been passed to "
                "the fitness function." << endl;
    else 
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == color)
                    count++;
            }
        }
    return count;
}


void Board::printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
