#define NUM_PLY 3 //this will change later
#define MAX_POSS_MOVES 8 //this will change later

#ifndef NEXTMOVE_H
#define	NEXTMOVE_H

struct Node {
        Board board;
        int fitWhite;
        int fitBlack;
        Node *pointToNext[MAX_POSS_MOVES];
        bool end;
};

class Tree {
public:
    Tree();
    ~Tree();
    
    void createTree(Node *root);
    void createLeaves(Node *leaf, int turn, int plyNum);
    void insert(Node *leaf, int childNum);
    Node search(Node *leaf, int childNum);
    void destroyTree(Node *leaf);
    void alphaBeta();
private:
    Node *root;
};
#endif	/* NEXTMOVE_H */

