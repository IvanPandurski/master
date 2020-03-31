#ifndef AVLTREEGENERATOR_H
#define AVLTREEGENERATOR_H

#include "Node.h"

class AVLTreeGenerator
{
    Node* root_ {nullptr};
public:
    AVLTreeGenerator() : root_{nullptr} {}

    Node* recursiveInsert(Node* p,int key);

    Node* ll_rotation(Node* p);
    Node* lr_rotation(Node* p);

    Node* rr_rotation(Node* p);
    Node* rl_rotation(Node* p);
    int nodeHeight(Node* p);
    int balanceFactor(Node* p);
    inline void set_root(Node* p ) {root_ = p;}
    inline Node* get_root() const {return  root_;}
};

#endif // AVLTREEGENERATOR_H
