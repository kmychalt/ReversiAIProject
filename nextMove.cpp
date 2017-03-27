#include "board.h"
#include "nextMove.h"

void createTree() {
    //insert root node
    int ply = 2;
    while (ply <= NUM_PLY) {
        //to start:
        //createSubTree(root Node)
        //ply++;
        //createSubTree(child Nodes)
        //etc.
    }
}

void createSubTree(Node* node) {
    
}

Board createMove(Board board, int currentColor) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            //if board.checkMove(coords, color) is true, 
            //then return new board
                return board;    
        }
    }
}

void insert(Node* prev, int childNum) {
    //have prev node point to current node with number to indicate 
    //which child it is
    prev->pointToNext[childNum];
}

void alphaBeta() {
    //traverse tree, looking for alpha-beta values
}
