
#ifndef BOARD_H
#define	BOARD_H

#define BOARD_SIZE 8
#define NUM_OF_COLORS 2

class Board {
public:
    Board();
    void getFitness(int*);
    int getFitness(int color);
    void printBoard();
    void getBoardStatus(int getBoard[BOARD_SIZE][BOARD_SIZE]);
    void setNewBoard(int setBoard[BOARD_SIZE][BOARD_SIZE]);
    bool checkMove(int coords[2], int color);
    void updateBoardWithMove(int coords[2], int color);
private:
    bool checkLine(int coords[2], int direction, int color);
    int fitness[NUM_OF_COLORS];
    int board[BOARD_SIZE][BOARD_SIZE];
};

#endif	

