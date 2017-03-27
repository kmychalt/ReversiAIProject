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
void Board::getFitness(int* fitness) {
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
    if (color != 1 && color != 2)
      cout << "An error has occurred. The wrong integer has been passed to the fitness function." << endl;
    else 
      for (int i = 0; i < BOARD_SIZE; i++) {
	for (int j = 0; j < BOARD_SIZE; j++) {
	  if(board[i][j] == color)
	    count++;
	}
      }
    return count;
}

/* PARAMETERS: array to hold the current board peices locations
 * PURPOSE: to return the current board in the form of an array


 */
void Board::getBoardStatus(int getBoard[BOARD_SIZE][BOARD_SIZE])
{
  for(int i = 0; i < BOARD_SIZE; i++)
    {
      for(int j = 0; j < BOARD_SIZE; j++)
	{
	  getBoard[i][j] = board[i][j];
	}
	
    }
}

/* PARAMETERS: array to hold the new board to be set
 * PURPOSE: to set the value of the internal array to the value passed in

 */


void Board::setNewBoard(int setBoard[BOARD_SIZE][BOARD_SIZE])
{
  for(int i = 0; i < BOARD_SIZE; i++)
    {
      for(int j = 0; j < BOARD_SIZE; j++)
	{
	  board[i][j] = setBoard[i][j];
	}	
    }
}




/* PURPOSE: prints the board formated
 */

void Board::printBoard() {
  for(int i = 0; i < BOARD_SIZE; i++)
    {
      for(int j = 0; j < BOARD_SIZE; j++)
	{
	  if(board[i][j] == 1)
	    {
	      cout << "w|";
	    }
	  else if(board[i][j] == 2)
	    {
	      cout << "b|";
	    }
	  else
	    cout << /*board[i][j] <<*/" |";
	}
      cout << endl;
    }    
}

/* PARAMETERS: an int array to hold the corrdinates of the move to be checked, an int for the color of the peice
 * RETURN: bool, true for valid move, false for invalid
 * PURPOSE: takes a potential move, checks the board to see if it is a legitamate move
 * lots of ifs
 */
bool Board::checkMove(int coords[2],int color)
{
  if(coords[0] >= BOARD_SIZE || coords[1] >= BOARD_SIZE || coords[0] < 0 || coords[1] < 0)
    return false;
  if(board[coords[0]][coords[1]] != 0)
    return false;
  if(coords[0] == 0)
    if(coords[1] == 0)
      cout <<"tl" << endl;
    else if(coords[1] == 7)
      {
	//don't check bottom and left
      }
    else
      {
	//don't check left
      }
  if(coords[0] == 7)
    if(coords[1] == 0){
      //don't check top or right
    }
    else if(coords[1] == 7)
      {
	//don't check bottom or right
      }
    else 
      {
	//don't check right
      }
  if(coords[1] == 0)
    {
      //don't check top
    }
  if(coords[1] == 7)
    {
      //don't check bottom
    }
  //check everything
     return true; 
}
