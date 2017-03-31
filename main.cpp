
#include <iostream>
#include <cstdlib>
#include "board.h"
#include "nextMove.h"

using namespace std;

int main() {
    int compColor = 0;
    int userColor = 0;
    char userChoice = 'a';
    cout << "Welcome to Reversi, I'll be your opponent today." << endl;
    cout << "Would you like to be black or white? Keep in mind black always moves first." << endl;
    while (userChoice != 'b' && userChoice != 'B' && userChoice != 'w' && userChoice != 'W') {
        cout << "b/w: ";
        cin.get(userChoice);
    }
    if (userChoice == 'b' || userChoice == 'B') {
        userColor = 2;
        compColor = 1;
        cout << "Player goes first. " << endl;
    } else {
        compColor = 2;
        userColor = 1;
        cout << "Computer goes first. " << endl;
    }
    Board b;
    int startingBoard[BOARD_SIZE][BOARD_SIZE];
    b.getBoardStatus(startingBoard);
    int coords[2];
    bool validTurn = false;
    int currentTurn = 2;
    bool gameOver = false;
    //main loop
    while (gameOver == false) {
        b.printBoard();
        if (userColor == currentTurn) {
            validTurn = false;
            while (validTurn == false) {
                cout << "Select a space to place your piece by using the "
                        "board coordinates separated by a space. " << endl;
                cin >> coords[0];
                cin >> coords[1];
                if (b.checkMove(coords, userColor)) {
                    b.updateBoardWithMove(coords, userColor);
		    //gameOver = b.checkGameOver;  UNCOMMENT LATER
		    validTurn = true;
                } else
                    cout << "That was an invalid move. Try again. " << endl;
		if(currentTurn == 1)
		  currentTurn = 2;
		else 
		  currentTurn = 1;
            }

            //computers turn
        } else {
            //computers turn
            cout << "Now it's my turn. " << endl;
	    b.getBoardStatus(startingBoard);
	    Tree t;
	    t.createTree(startingBoard);
	    cout << "after createTree" << endl; //TEMPORARY REMOVE
	    int OptimalBoard[BOARD_SIZE][BOARD_SIZE];
	    int currentBoard[BOARD_SIZE][BOARD_SIZE];
	    int optimalMove[2];
	    t.AlphaBeta(OptimalBoard,compColor);
	    b.getBoardStatus(currentBoard);
	    for(int i = 0;i < BOARD_SIZE; i++)
	      {
		for(int j = 0; j < BOARD_SIZE; j++)
		  {
		    if (OptimalBoard[j][i] != currentBoard[j][i])
		      {
			optimalMove[0] = j;
			optimalMove[1] = i;
			cout << "optimalMove" << optimalMove[0] << "," << optimalMove[1] << endl;
			break; 
		      }
		  }
	      }
	    b.updateBoardWithMove(optimalMove, compColor);
	    //gameOver = b.gameOver; UNCOMMENT LATER
	    if(currentTurn == 1)
	      currentTurn = 2;
	    else
	      currentTurn = 1;
	}

         
    }
    return 0;
}

 /*int boardBits[BOARD_SIZE][BOARD_SIZE];
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
    move[0] = 0;
    move[1] = 0;
    b.getBoardStatus(boardBits);
    for(int i = 0; i < 8; i++)
      {
        for(int j = 0; j < 8; j++)
          {
            boardBits[j][i] = 2;
          }
      }

    boardBits[3][0] = 0;//start
    //possible moves
    boardBits[0][0] = 0;
    boardBits[7][0] = 1;
    boardBits[3][7] = 0;
    boardBits[0][3] = 0;
    boardBits[7][4] = 0;

    move[0] = 3;
    move[1] = 0;
    //boardBits[7][7] = 1;
    b.setNewBoard(boardBits);
    if(b.checkMove(move, 1))
      cout << "valid Move" << endl;
    else
      cout << "invalid Move" << endl;
    b.setNewBoard(boardBits);
    b.printBoard();*/

