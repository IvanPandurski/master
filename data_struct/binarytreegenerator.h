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

    // for binary search tree
    void insert(int key);
    Node* search(int key);

    void delete_key(int key);

    inline Node* get_root() {return root;}
};

#endif // BINARYTREEGENERATOR_H
