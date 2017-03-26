
#ifndef BOARD_H
#define	BOARD_H

#define BOARD_SIZE 8
#define NUM_OF_COLORS 2

class Board {
public:
    Board();
    int& getFitness(int*);
    int getFitness(int color);
    void printBoard();
private:
    int board[BOARD_SIZE][BOARD_SIZE];
    int fitness[NUM_OF_COLORS];
};

#endif	

