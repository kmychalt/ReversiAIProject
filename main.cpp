
#include <iostream>
#include <cstdlib>
#include "board.h"
#include "nextMove.h"

using namespace std;

int main(int argc, char** argv) {
    Tree t;
    Board b;
    Node n;
    int boardBits[BOARD_SIZE][BOARD_SIZE];
    b.getBoardStatus(boardBits);
    int move[2];
    move[0] = 0;
    move[1] = 0;
    int sumMoves = 0;
    for(int i = 0; i < 7; i++)
      {
	move[0] = i;
	for(int j = 0; j < 7; j++)
	  {
	    move[1] = j;
	    if(b.checkMove(move, 1))
	      {
		sumMoves++;
		boardBits[move[0]][move[1]] = 1;
	      }
	  }
	    cout << "sumMoves: " << sumMoves << endl;
      }
    b.setNewBoard(boardBits);
    b.printBoard();
    
    b.getBoardStatus(boardBits);
    for(int i = 1; i < 7; i++)
      {
	boardBits[0][i] = 2;
      }
    boardBits[0][7] = 1;
    b.setNewBoard(boardBits);
    if(b.checkMove(move, 1))
      cout << "valid Move" << endl;
    else
      cout << "invalid Move" << endl;
    boardBits[0][0] = 1;
    b.setNewBoard(boardBits);
    b.printBoard();
    return 0;
}

