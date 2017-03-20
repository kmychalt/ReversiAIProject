
#ifndef BOARD_H
#define	BOARD_H

#define BOARD_SIZE 8

class Board {
public:
    Board();
    int getFitness(int color);
    void printBoard();
private:
    int board[BOARD_SIZE][BOARD_SIZE];
};

#endif	

