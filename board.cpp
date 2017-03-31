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
  cout << "  0 1 2 3 4 5 6 7" << endl;
  for(int i = 0; i < BOARD_SIZE; i++)
    {
      cout << i << "|";
      for(int j = 0; j < BOARD_SIZE; j++)
	{
	  if(board[j][i] == 1)
	    {
	      cout << "w|";
	    }
	  else if(board[j][i] == 2)
	    {
	      cout << "b|";
	    }
	  else
	    cout << /*board[i][j] <<*/" |";
	}
      cout <<  endl;
    }    
}

/* PARAMETERS: an int array to hold the corrdinates of the move to be checked, an int for the color of the peice
 * RETURN: bool, true for valid move, false for invalid
 * PURPOSE: takes a potential move, checks the board to see if it is a legitamate move
 * lots of ifs
 */
bool Board::checkMove(int coords[2],int color)
{
  int checkColor = 0;
  int checkCoords[2];
  if(color == 1)
    checkColor = 2;
  else
    checkColor = 1;
  if(coords[0] >= BOARD_SIZE || coords[1] >= BOARD_SIZE || coords[0] < 0 || coords[1] < 0)
    return false;
  if(board[coords[0]][coords[1]] != 0)
    return false;
  if(coords[0] == 0)
    if(coords[1] == 0)
      {
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;       // check x x x for (0,0) special case
	    checkCoords[1] = coords[1];         //       x x o
	    if(checkLine(checkCoords, 3, color))//       x x x
	       return true;
	  }
	if(board[coords[0]+1][coords[1]+1] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;       // check x x x for (0,0) special case
	    checkCoords[1] = coords[1]+1;       //       x x x 
	    if(checkLine(checkCoords, 4, color))//       x x o
	       return true;
	  }
	if(board[coords[0]][coords[1]+1] == checkColor)
	  {
	    checkCoords[0] = coords[0];         // check x x x for (0,0) special case
	    checkCoords[1] = coords[1]+1;       //       x x x
	    if(checkLine(checkCoords, 5, color))//       x o x 
	      return true;
	  }
	return false;
      }
    else if(coords[1] == 7)
      {
	//don't check bottom and left

	if(board[coords[0]][coords[1]-1] == checkColor)
	  {
	    checkCoords[0] = coords[0];         // check x o x for (0,7) special case
	    checkCoords[1] = coords[1]-1;       //       x x x 
	    if(checkLine(checkCoords, 1, color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]-1] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;       // check x x o for (0,7) special case
	    checkCoords[1] = coords[1]-1;       //       x x x 
	    if(checkLine(checkCoords, 2, color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;       // check x x x for (0,7) special case
	    checkCoords[1] = coords[1];         //       x x o 
	    if(checkLine(checkCoords, 3, color))//       x x x
	      return true;
	  }
	return false;
      }
    else
      {
	//don't check left

	if(board[coords[0]][coords[1]-1] == checkColor)
	  {
	    checkCoords[0] = coords[0];         // check x o x for (0,y) special case
	    checkCoords[1] = coords[1]-1;       //       x x x 
	    if(checkLine(checkCoords, 1, color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;// check x x o for (0,y) special case
	    checkCoords[1] = coords[1]-1;//       x x x 
	    if(checkLine(checkCoords, 2, color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;// check x x x for (0,y) special case
	    checkCoords[1] = coords[1];  //       x x o 
	    if(checkLine(checkCoords, 3, color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;// check x x x for (0,y) special case
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 4, color))//       x x o
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0];  // check x x x for (0,y) special case
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 5, color))//       x o x
	      return true;
	  }
	return false;
      }
  if(coords[0] == 7)
    if(coords[1] == 0){
      //don't check top or right
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check x x x for (7,0) special case
	    checkCoords[1] = coords[1];  //       o x x 
	    if(checkLine(checkCoords, 7, color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check x x x for (7,0) special case
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 6, color))//       o x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0];  // check x x x for (7,0) special case
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 5, color))//       x o x
	      return true;
	  }
	return false;

    }
    else if(coords[1] == 7)
      {
	//don't check bottom or right
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0];  // check x o x for (7,7) special case
	    checkCoords[1] = coords[1]-1;//       x x x 
	    if(checkLine(checkCoords, 1,color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check x x x for (7,7) special case
	    checkCoords[1] = coords[1];  //       o x x 
	    if(checkLine(checkCoords, 7,color))//       x x x
	      return true;
	  }

	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check o x x for (7,7) special case
	    checkCoords[1] = coords[1]-1;//       x x x 
	    if(checkLine(checkCoords, 8,color))//       x x x
	      return true;
	  }
	return false;

      }
    else 
      {

	//don't check right
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0];  // check x o x for (7,y) special case
	    checkCoords[1] = coords[1]-1;//       x x x 
	    if(checkLine(checkCoords, 1,color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0];  // check x x x for (7,y) special case
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 5,color))//       x o x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check x x x for (7,y) special case
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 6,color))//       o x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check x x x for (7,y) special case
	    checkCoords[1] = coords[1];  //       o x x 
	    if(checkLine(checkCoords, 7,color))//       x x x
	      return true;
	  }

	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check o x x for (7,y) special case
	    checkCoords[1] = coords[1]-1;//       x x x 
	    if(checkLine(checkCoords, 8,color))//       x x x
	      return true;
	  }

	return false; 
      }
  if(coords[1] == 0)
    {
      //don't check top
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;// check x x x for (x,0) special case
	    checkCoords[1] = coords[1];  //       x x o 
	    if(checkLine(checkCoords, 3,color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;// check x x x for (x,0) special case
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 4,color))//       x x o
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0];  // check x x x for (x,0) special case
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 5,color))//       x o x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check x x x for (x,0) special case
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 6,color))//       o x x
	      return true;
	  }

	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check x x x for (x,0) special case
	    checkCoords[1] = coords[1];  //       o x x 
	    if(checkLine(checkCoords, 7,color))//       x x x
	      return true;
	  }

      return false;
    }
  if(coords[1] == 7)
    {
      //don't check bottom
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0];  // check x o x for (x,7) special case
	    checkCoords[1] = coords[1]-1;//       x x x 
	    if(checkLine(checkCoords, 1,color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;  // check x x o for (x,7) special case
	    checkCoords[1] = coords[1]-1;//       x x x 
	    if(checkLine(checkCoords, 2,color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;// check x x x for (x,7) special case
	    checkCoords[1] = coords[1];//       x x o 
	    if(checkLine(checkCoords, 3,color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check x x x for (x,7) special case
	    checkCoords[1] = coords[1];  //       o x x 
	    if(checkLine(checkCoords, 7,color))//       x x x
	      return true;
	  }

	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check o x x for (x,7) special case
	    checkCoords[1] = coords[1]-1;//       x x x 
	    if(checkLine(checkCoords, 8,color))//       x x x
	      return true;
	  }

      return false;
    }
  //check everything
  //cout << "in check everything in checkMove" << endl; //TEMPORARY REMOVE

	if(board[coords[0]][coords[1]-1] == checkColor)
	  {
	    checkCoords[0] = coords[0];         // check x o x 
	    checkCoords[1] = coords[1]-1;       //       x x x 
	    if(checkLine(checkCoords, 1, color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]-1] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;// check x x o 
	    checkCoords[1] = coords[1]-1;//       x x x 
	    if(checkLine(checkCoords, 2, color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;// check x x x 
	    checkCoords[1] = coords[1];  //       x x o 
	    if(checkLine(checkCoords, 3, color))//       x x x
	      return true;
	  }
	if(board[coords[0]+1][coords[1]+1] == checkColor)
	  {
	    checkCoords[0] = coords[0]+1;// check x x x 
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 4, color))//       x x o
	      return true;
	  }

	if(board[coords[0]][coords[1]+1] == checkColor)
	  {
	    checkCoords[0] = coords[0];  // check x x x 
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 5, color))//       x o x
	      return true;
	  }
	if(board[coords[0]-1][coords[1]+1] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check x x x 
	    checkCoords[1] = coords[1]+1;//       x x x 
	    if(checkLine(checkCoords, 6, color))//       o x x
	      return true;
	  }

	if(board[coords[0]-1][coords[1]] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check x x x 
	    checkCoords[1] = coords[1];  //       o x x 
	    if(checkLine(checkCoords, 7, color))//       x x x
	      return true;
	  }

	if(board[coords[0]-1][coords[1]-1] == checkColor)
	  {
	    checkCoords[0] = coords[0]-1;// check o x x 
	    checkCoords[1] = coords[1]-1;//       x x x 
	    if(checkLine(checkCoords, 8, color))//       x x x
	      return true;
	  }
     return false; 
}

bool Board::checkLine(int coords[2], int direction, int colorToFind)
{
  int otherColor = 0;
  if(colorToFind == 1)
    otherColor = 2;
  else
    otherColor = 1;
  if(direction == 1)//done
    {
      for(int i = coords[1]; i >= 0; i--)
	{     
	  //check up
	  if(board[coords[0]][i] == colorToFind)
	    return true;
	  else if(board[coords[0]][i] == 0)
	    return false;
	}
      return false;
    }
  if(direction == 2)
    {
      int j = coords[0];
      for(int i = coords[1]; i >= 0; i--)
	{    
	  //check up
	  if(board[j][i] == colorToFind)
	    return true;
	  else if(board[j][i] == 0)
	    return false;
	  j++;
	  if(j == 0)
	    break;
	}
      return false;
    }
  if(direction == 3)
    {
      for(int i = coords[0]; i <= 7; i++)
	{     
	  //check up
	  if(board[i][coords[1]] == colorToFind)
	    return true;
	  else if(board[i][coords[1]] == 0)
	    return false;
	}
      return false;
    }
  if(direction == 4)
    {
      int j = coords[1];
      for(int i = coords[0]; i <= 7; i++)
	{     
	  //check up
	  if(board[i][j] == colorToFind)
	    return true;
	  else if(board[i][j] == 0)
	    return false;
	  j++;
	  if(j == 8)
	    break;
	}
      return false;
    }
  if(direction == 5)
    {
      for(int i = coords[1]; i <= 7; i++)
	{     
	  //check up
	  if(board[coords[0]][i] == colorToFind)
	    return true;
	  else if(board[coords[0]][i] == 0)
	    return false;
	}
      return false;
    } 
  if(direction == 6)
    {
      int j = coords[1];
      for(int i = coords[0]; i >= 0; i--)
	{     
	  //check up
	  if(board[i][j] == colorToFind)
	    return true;
	  else if(board[i][j] == 0)
	    return false;
	  j++;
	  if(j == 8)
	    break;
	}
      return false;
    }
  if(direction == 7)
    {
      for(int i = coords[0]; i >= 0; i--)
	{     
	  //check up
	  if(board[i][coords[1]] == colorToFind)
	    return true;
	  else if(board[i][coords[1]] == 0)
	    return false;
	}
      return false;
    }
  if(direction == 8)
    {
      int j = coords[1];
      for(int i = coords[0]; i >= 0; i--)
	{     
	  //check up
	  if(board[i][j] == colorToFind)
	    return true;
	  else if(board[i][j] == 0)
	    return false;
	  j++;
	  if(j == 0)
	    break;
	}
      return false;
    }
}
