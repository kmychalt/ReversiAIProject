#define NUM_PLY 3 //this will change later
#define MAX_POSS_MOVES 8 //this will change later

#ifndef NEXTMOVE_H
#define	NEXTMOVE_H

class Tree {
public:
    struct Node {
        Board board;
        int fitWhite;
        int fitBlack;
        int *pointToNext[MAX_POSS_MOVES];
    };
    void createTree();
    void createSubTree(Node* node);
    Board createMove(Board board, int currentColor);
    void insert(Node* prev, int childNum);
    void alphaBeta();
private:
    
};
#endif	/* NEXTMOVE_H */

