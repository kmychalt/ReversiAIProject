#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "board.h"
#include "nextMove.h"

using namespace std;

//PURPOSE: CONSTRUCTOR
Tree::Tree() {
    root = new Node;
    noMoves = false;
    gameOver = false; 
}

//PURPOSE: DECONSTRUCTOR
Tree::~Tree() {
    destroyTree(root);
}

//PURPOSE: Create the tree for the AI, to be used for alpha-beta pruning
void Tree::createTree(int initalBoard[BOARD_SIZE][BOARD_SIZE]) {
  //insert(root, 0);
    root->board.setNewBoard(initalBoard);
    root->isRoot = true;
    root->isLeaf = false;
    createLeaves(root, 2, 2);
}

void Tree::createLeaves(Node *leaf, int turn, int plyNum) 
{
  int count = 0;
  int arr[BOARD_SIZE][BOARD_SIZE];
  
  cout << endl;
  cout << "creating Leaf board" << endl;
  //leaf->board.printBoard();
  
  if(leaf->isLeaf != true && plyNum != 0) 
    {
      for(int i = 0; i < BOARD_SIZE; i++) 
	{ //loop through the board of node were looking at
	  for(int j = 0; j < BOARD_SIZE; j++) 
	    { 
	      int coords[2] = {i, j}; //try these coordinates
	      if(leaf->board.checkMove(coords, turn)) 
		{ //if they are a legal move
		  Node *n = new Node;
		  leaf->pointToNext[count] = n; //give node we are looking at a new child
		  leaf->board.getBoardStatus(arr); //get board arr from root
		  arr[i][j] = turn; //set the piece on the board
		  
		  //NEED TO HAVE LINE CHANGE
		  
		  n->board.setNewBoard(arr);
		  //n->board.printBoard(); //print for debugging 
		  cout << "current count" << count << endl;
		  n->isLeaf = false;
		  n->nullTerminal = false;
		  
		  count++;
		}
	    }
	}
      Node *m = new Node;
      m -> nullTerminal = true;
      leaf->pointToNext[count+1] = m;
      if (count != 0 || plyNum > 0)
	{
	  plyNum--;
	}
      if(count == 0 || plyNum == 0)
	{
	  leaf ->isLeaf = true;
	  cout << "leaf is leaf" << endl; //TEMPORARY REMOVE
	  if (leaf == root)
	    {
	      noMoves = true;
	    }
	    return;
	}
      if (plyNum != 0)
	{
	  if (turn == 2)
	    turn = 1;
	  else 
	    turn = 2;
	  for (int k = 0; k < count; k++)
	    {
	      createLeaves(leaf->pointToNext[k], turn, plyNum);
	    }
	}
    }  
}
//incomplete function, need some key value for identification
void Tree::insert(Node *leaf, int childNum) {
    //have previous node point to current node with number to indicate 
    //which child it is
    
}

//incomplete function, need some key value for identification
/*Node Tree::search(Node* leaf, int childNum) {
    
}*/

void Tree::destroyTree(Node* leaf) {
    if (leaf->pointToNext[0] != NULL) {
        for (int i = 0; i < MAX_POSS_MOVES; i++) {
          if(leaf->pointToNext[i] == NULL)
	    break;
	  else  
	    destroyTree(leaf->pointToNext[i]);
        }
    }
    delete leaf; //delete calls de-constructor and deallocates memory
}

void Tree::AlphaBeta(int suggestedBoard[BOARD_SIZE][BOARD_SIZE], int turn) {
    //traverse tree, looking for alpha-beta values
  int traverseNum = 0;
  traverseNum = traverseAlphaBeta(root, NUM_PLY, -1, BOARD_SIZE * BOARD_SIZE + 1, true, turn);
  int i = 0;
  while(root->pointToNext[i]->nullTerminal != false)
    {
      if(root->pointToNext[i]->ABvalue == traverseNum)
	{
	  root->pointToNext[i]->board.getBoardStatus(suggestedBoard);
	  break;
	}
      i++;
    }
}

int Tree::traverseAlphaBeta(Node *leaf, int depth, int localAlpha, int localBeta, bool max, int color) {
  //if at a leaf of the tree return fitness 
  if(leaf->isLeaf == true || depth == 0)
    {
      if(color == 2)
	{
	  return leaf->board.getFitness(2);
	}
      else
	{
	  return leaf->board.getFitness(1);
	}
    }
  if(max)
    {
      leaf->ABvalue = -1;
      int i = 0;
      while(leaf->pointToNext[i]->nullTerminal != true)
	{
	  int temp = 0;
	  temp = traverseAlphaBeta(leaf->pointToNext[i], depth - 1, localAlpha, localBeta,false, color);
	  if(leaf->ABvalue < temp)
	    {
	      leaf->ABvalue = temp;
	    }
	  if(leaf->ABvalue > localAlpha)
	    {
	      localAlpha = leaf->ABvalue;
	    }
	  if(localBeta <= leaf->ABvalue)
	    break;
	  i++;
	}
      return leaf->ABvalue;
    }
  else
    {
      leaf->ABvalue = BOARD_SIZE * BOARD_SIZE + 1;
      int i = 0;
      while(leaf -> pointToNext[i]->nullTerminal != true)
	{
	  int temp = 0;
	  temp = traverseAlphaBeta(leaf->pointToNext[i], depth - 1, localAlpha, localBeta,true, color);
	  if(leaf->ABvalue > temp)
	    {
	      leaf->ABvalue = temp;
	    }
	  if(leaf->ABvalue < localBeta)
	    {
	      localBeta = leaf->ABvalue;
	    }
	  if(localBeta <= leaf-> ABvalue)
	    break;
	  i++;
	}
      return leaf->ABvalue;
    }
}

