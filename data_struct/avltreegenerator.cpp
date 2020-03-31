#include "avltreegenerator.h"


Node *AVLTreeGenerator::recursiveInsert(Node* p, int key)
{
    Node* t = nullptr;
    if(p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = nullptr;
        return  t;
    }

    if( key < root_->data)
    {
        p->lchild = recursiveInsert(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild = recursiveInsert(p->rchild, key);
    }

    p->height = nodeHeight(p);
    if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
    {
        return ll_rotation(p);
    }
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
    {
//        return lr_rotation(p);
    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->lchild) == -1)
    {
//        return rr_rotation(p);
    }
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
    {
//        return rl_rotation(p);
    }
    return p;
}

Node *AVLTreeGenerator::ll_rotation(Node *p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if(root_ == p) {root_ = pl;}

    return pl;
}

Node *AVLTreeGenerator::lr_rotation(Node *p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if(root_ == p) {root_ = plr;}

    return plr;
}

Node *AVLTreeGenerator::rr_rotation(Node *p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    if(root_ == p) {root_ = pr;}

    return pr;
}

Node *AVLTreeGenerator::rl_rotation(Node *p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);

    if(root_ == p) {root_ = prl;}

    return prl;
}

int AVLTreeGenerator::nodeHeight(Node *p)
{
    int left_height{};
    int right_height {};

    left_height = (p != nullptr && p->lchild) ? p->lchild->height : 0;
    right_height = (p != nullptr && p->rchild) ? p->rchild->height : 0;

    return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
}

int AVLTreeGenerator::balanceFactor(Node *p)
{
    int left_height{};
    int right_height {};

    left_height = (p != nullptr && p->lchild) ? p->lchild->height : 0;
    right_height = (p != nullptr && p->rchild) ? p->rchild->height : 0;

    return left_height - right_height;
}
