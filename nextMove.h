#define NUM_PLY 3 //this will change later
#define MAX_POSS_MOVES 8 //this will change later

#ifndef NEXTMOVE_H
#define	NEXTMOVE_H

struct Node {
        Board board;
        int fitWhite;
        int fitBlack;
        Node *pointToNext[MAX_POSS_MOVES];
};

class Tree {
public:
    Tree();
    ~Tree();
    
    void createTree();
    void insert(Node *leaf, int childNum);
    Node search(Node *leaf, int childNum);
    void destroyTree(Node *leaf);
    Board createMove(Board board, int currentColor);
    void alphaBeta();
private:
    Node *root;
};
#endif	/* NEXTMOVE_H */

