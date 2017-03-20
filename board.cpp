#include "board.h"

class Board {
public:
    Board();
    int getFitness(int color);
    void printBoard();
private:
    int board[BOARD_SIZE][BOARD_SIZE];
};

Board::Board() {
    board[][] = {0};
    board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1] = 1;
    board[BOARD_SIZE / 2][BOARD_SIZE / 2] = 1;
    board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2] = 2;
    board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1] = 2;
}

int Board::getFitness(int color) {
    
}

void Board::printBoard() {
    
}
