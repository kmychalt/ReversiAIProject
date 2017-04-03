
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
                for (int i = 0; i < BOARD_SIZE; i++) {
                    for (int j = 0; j < BOARD_SIZE; j++) {
                        coords[0] = i;
                        coords[1] = j;
                        if (b.checkMove(coords, userColor))
                            break;
                    }
                }
                //cout << "No Moves Avaliable, turn over" << endl;
                //gameOver = b.checkGameOver();
                //if (currentTurn == 1)
                //    currentTurn = 2;
                //else
                //    currentTurn = 1;
                //continue;

                cout << "Select a space to place your piece by using the "
                        "board coordinates separated by a space. " << endl;
                cin >> coords[0];
                cin >> coords[1];
                if (b.checkMove(coords, userColor)) {
                    b.updateBoardWithMove(coords, userColor);
                    gameOver = b.checkGameOver();
                    validTurn = true;
                } else
                    cout << "That was an invalid move. Try again. " << endl;
            }
            if (currentTurn == 1)
                currentTurn = 2;
            else
                currentTurn = 1;
        } else { // ****COMPUTER TURN****
            cout << "Now it's my turn. " << endl;
            b.getBoardStatus(startingBoard);
            Tree t;
            t.createTree(startingBoard, currentTurn);
            //cout << "after createTree" << endl; //TEMPORARY REMOVE
            int optimalMove[2];
            t.AlphaBeta(optimalMove, compColor);
            if (optimalMove[0] != -1) {
	      cout << "My Move: (" << optimalMove[0] << ", " << optimalMove[1] << ")"<< endl;
                b.updateBoardWithMove(optimalMove, compColor);
            }

            gameOver = b.checkGameOver();
            if (currentTurn == 1)
                currentTurn = 2;
            else
                currentTurn = 1;
        }
    }

    if(gameOver)
      {
	cout << "Thats the game!" << endl;
	cout << "Final Board:" << endl; 
	b.printBoard();
	cout << "White had " << b.getFitness(1) << " Pieces." << endl;
	cout << "Black had " << b.getFitness(2) << " Pieces." << endl;
	if(b.getFitness(1) > b.getFitness(2))
	  {
	    cout << "White Was the Winner!" << endl; 
	  }
	else
	  {
	    cout << "Black Was the Winnder!" << endl;
	  }
      }
    return 0;
}
