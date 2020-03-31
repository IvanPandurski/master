#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node *lchild {};
    int data {};
    int height {}; // use it for AVL tree
    Node* rchild {};
};

#endif // NODE_H
