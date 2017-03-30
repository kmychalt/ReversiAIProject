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
void Tree::createTree() {
    insert(root, 0);
    int x = 0;
    
    createSubTree(root);
    while(x < NUM_PLY) { //go down this many layers
        
        for (int i = 0; i < MAX_POSS_MOVES; i++) {
            createSubTree(root->pointToNext[i]);
        }
        x++;
    }
}

void Tree::createSubTree(Node *start) {
    int count = 0;
    int coords[2];
    
    for(int i = 0; i < BOARD_SIZE; i++) { //loop through the board of node were looking at
        for(int j = 0; j < BOARD_SIZE; j++) { 
            coords = [i, j]; //try these coordinates
            if(root->board.checkMove(coords, 2)) { //if they are a legal move
                root->pointToNext[count]->new Node; //give node we are looking at a new child
                root->pointToNext[count]->board[i][j] = 2; //set the piece on the board
                root->board.printBoard(); //print for debugging
                count++;
            }
        }
    }
}

//incomplete function, need some key value for identification
/*void Tree::insert(Node *leaf, int childNum) {
    //have previous node point to current node with number to indicate 
    //which child it is
    leaf->pointToNext[childNum];
}

//incomplete function, need some key value for identification
Node Tree::search(Node* leaf, int childNum) {
    
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
