#include <stdio.h>
#include "board.h"
#include "nextMove.h"
    
//PURPOSE: CONSTRUCTOR
Tree::Tree() {
    root = NULL;
}

//PURPOSE: DECONSTRUCTOR
Tree::~Tree() {
    destroyTree(root);
}

//PURPOSE: Create the tree for the AI, to be used for alpha-beta pruning
void Tree::createTree(Node *root) {
    insert(root, 0);
    
    
}

void Tree::createLeaves(Node *leaf, int turn, int plyNum) {
    int count = 0;
    int arr[BOARD_SIZE][BOARD_SIZE];
    
    for(int i = 0; i < BOARD_SIZE; i++) { //loop through the board of node were looking at
        for(int j = 0; j < BOARD_SIZE; j++) { 
            int coords[2] = {i, j}; //try these coordinates
            if(leaf->board.checkMove(coords, turn)) { //if they are a legal move
                Node *n = new Node;
                leaf->pointToNext[count] = n; //give node we are looking at a new child
                leaf->board.getBoardStatus(arr); //get board arr from root
                arr[i][j] = turn; //set the piece on the board
                //NEED TO HAVE LINE CHANGE
                n->board.setNewBoard(arr);
                n->board.printBoard(); //print for debugging
                
                count++;
            }
        }
    } 
    plyNum--;
}

//incomplete function, need some key value for identification
void Tree::insert(Node *leaf, int childNum) {
    //have previous node point to current node with number to indicate 
    //which child it is
    leaf->pointToNext[childNum];
}

//incomplete function, need some key value for identification
/*Node Tree::search(Node* leaf, int childNum) {
    
}*/

void Tree::destroyTree(Node* leaf) {
    if (leaf != NULL) {
        for (int i = 0; i < MAX_POSS_MOVES; i++) {
            destroyTree(leaf->pointToNext[i]);
        }
    }
    delete leaf; //delete calls de-constructor and deallocates memory
}

/*Board Tree::createMove(Board board, int currentColor) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            //if board.checkMove(coordinates, color) is true, 
            //then return new board
                return board;    
        }
    }
}*/

void Tree::alphaBeta() {
    //traverse tree, looking for alpha-beta values
}
