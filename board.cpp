

#define BOARD_SIZE 8

class Board {
public:
    Board();
    int getFitness(int color);
private:
    int board[BOARD_SIZE][BOARD_SIZE];
};

Board::Board() {
    board[][] = {0};
    board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1] = 1;
    board[BOARD_SIZE / 2][BOARD_SIZE / 2] = 1;
}
