#include <stdio.h>
#include "board.h"
#include "nextMove.h"
    
Tree::Tree() {
    root = NULL;
}

Tree::~Tree() {
    destroyTree(root);
}

void Tree::createTree() {
    
}
//incomplete function, need some key value for identification
void Tree::insert(Node *leaf, int childNum) {
    //have previous node point to current node with number to indicate 
    //which child it is
    leaf->pointToNext[childNum];
}

//incomplete function, need some key value for identification
Node Tree::search(Node* leaf, int childNum) {
    
}

void Tree::destroyTree(Node* leaf) {
    if (leaf != NULL) {
        for (int i = 0; i < MAX_POSS_MOVES; i++) {
            destroyTree(leaf->pointToNext[i]);
        }
    }
    delete leaf; //delete calls de-constructor and deallocates memory
}

Board Tree::createMove(Board board, int currentColor) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            //if board.checkMove(coordinates, color) is true, 
            //then return new board
                return board;    
        }
    }
}

void Tree::alphaBeta() {
    //traverse tree, looking for alpha-beta values
}
