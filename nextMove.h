#define NUM_PLY 2 //this will change later
#define MAX_POSS_MOVES BOARD_SIZE*BOARD_SIZE //this will change later

#ifndef NEXTMOVE_H
#define	NEXTMOVE_H

struct Node {
        Board board;
        int fitWhite;
        int fitBlack;
        Node *pointToNext[MAX_POSS_MOVES];
        int ABvalue;
        int move[2];
        bool isLeaf;
        bool isRoot;
        bool nullTerminal;
};

class Tree {
public:
    Tree();
    ~Tree();
    void createTree(int initalBoard[BOARD_SIZE][BOARD_SIZE], int turn);
    void createLeaves(Node *leaf, int turn, int plyNum);
    void insert(Node *leaf, int childNum);
    Node search(Node *leaf, int childNum);
    void destroyTree(Node *leaf);
    void AlphaBeta(int suggestedMove[2], int turn);
    int traverseAlphaBeta(Node *leaf, int depth, int localAlpha, int localBeta, bool max, int color);
    bool checkGameOver();
private:
    Node *root;
    bool noMoves;
    bool gameOver;
};
#endif	/* NEXTMOVE_H */

