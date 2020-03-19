#ifndef BINARYTREEGENERATOR_H
#define BINARYTREEGENERATOR_H

#include "Node.h"


class binaryTreeGenerator
{
    Node* root = nullptr;
public:
    binaryTreeGenerator() : root{nullptr} {}
    void CreateTree();
    void preorder(Node* p);
    void postorder(Node* p);
    void inorder(Node* p);
    void levelOrder(Node* p);
    int height(Node* root);

    Node* inPre(Node* p);
    Node* inSucc(Node* p);

    // for binary search tree
    void insert(int key);
    Node* recursiveInsert(Node* p,int key);
    Node* search(int key);

    void delete_key(int key);
    Node* recursiveDelete(Node* p, int key);

    inline Node* get_root() {return root;}
    inline void set_root(Node* r) {root = r;}
};

#endif // BINARYTREEGENERATOR_H
