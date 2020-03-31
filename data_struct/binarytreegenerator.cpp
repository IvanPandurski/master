#include "binarytreegenerator.h"
#include "queue.h"
#include <iostream>

void binaryTreeGenerator::CreateTree()
{
    Node* p = nullptr;
    Node* t = nullptr;
    int x {};
    Queue q(100);

    printf("enter root value ");
    scanf("%d", &x);

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);

    while(false == q.empty())
    {
        p = q.dequeue();
        printf("enter left child of %d", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        printf("enter right child of %d", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void binaryTreeGenerator::preorder(Node *p)
{
    if(p == nullptr) return;

    printf("%d ", p->data);
    preorder(p->lchild);
    preorder(p->rchild);
}

void binaryTreeGenerator::inorder(Node *p)
{
    if(p == nullptr) {return;}

    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
}

void binaryTreeGenerator::postorder(Node *p)
{
    if(p == nullptr) {return;}

    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d ", p->data);
}

void binaryTreeGenerator::levelOrder(Node *p)
{

    Queue q(100);
    printf("%d ",root->data);
    q.enqueue(root);
    while(false == q.empty())
    {
        root=q.dequeue();
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
        }
        printf("%d ",root->rchild->data);
        q.enqueue(root->rchild);
    }
}

int binaryTreeGenerator::height(Node *root)
{

    int x=0,y=0;
    if(root==0)
        return 0;
    x=height(root->lchild); y=height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

void binaryTreeGenerator::insert(int key)
{
    Node* t = root;
    Node* r = nullptr;
    Node* p = nullptr;

    if(root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = nullptr;
        root = p;
        return;
    }

    while( t != nullptr)
    {
        r = t;
        if(key < t->data) { t = t->lchild;}
        else if(key > t->data) { t = t->rchild;}
        else {return;}
    }

    p = new Node;
    p->data = key;
    p->lchild = p->rchild = nullptr;

    if(key < r->data) {r->lchild = p;}
    else {r->rchild = p; }
}

Node *binaryTreeGenerator::recursiveInsert(Node* p, int key)
{
    Node* t = nullptr;
    if(p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        return  t;
    }

    if( key < root->data)
    {
        p->lchild = recursiveInsert(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild = recursiveInsert(p->rchild, key);
    }

    return p;
}


Node *binaryTreeGenerator::search(int key)
{
    Node* t = root;
    while(t != nullptr)
    {
        if(key == t->data) {return t;}
        else if(key < t->data) { t = t->lchild;}
        else {t = t->rchild;}
    }

    return nullptr;
}

Node *binaryTreeGenerator::recursiveDelete(Node *p, int key)
{
    Node* q = nullptr;

    if(p == nullptr)
    {
        return nullptr;
    }
    if(p->lchild == nullptr && p->rchild == nullptr)
    {
        if( p == root) {root = nullptr;}
        delete p;
        return nullptr;
    }

    if(key < p->data)
    {
        p->lchild = recursiveDelete(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild = recursiveDelete(p->rchild, key);
    }
    else
    {
        if(height(p->lchild) > height(p->rchild))
        {
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = recursiveDelete(p->lchild, q->data);
        }
        else
        {
            q = inSucc(p->lchild);
            p->data = q->data;
            p->lchild = recursiveDelete(p->lchild, q->data);
        }

    }

    return p;
}

Node *binaryTreeGenerator::inPre(struct Node *p)
{
    while(p && p->rchild!=nullptr)
        p=p->rchild;

    return p;
}
Node *binaryTreeGenerator::inSucc(struct Node *p)
{
    while(p && p->lchild!=nullptr)
        p=p->lchild;

    return p;
}



//in main



//    Tree p;
//    p.CreateTree();
//    p.preorder(p.root);

//    binaryTreeGenerator t;
////    t.CreateTree();
////    t.preorder(t.get_root());
//    t.set_root(t.recursiveInsert(t.get_root(), 5));
//    t.recursiveInsert(t.get_root(),2);
//    t.recursiveInsert(t.get_root(),15);
//    t.recursiveInsert(t.get_root(),22);
//    t.recursiveInsert(t.get_root(),1);

////    t.insert(15);
////    t.insert(22);
////    t.insert(1);

//    t.inorder(t.get_root());

//    if(t.search(22) == nullptr)
//    {
//        printf("element is not found \n");
//    }
//    else
//    {
//        printf("element is found \n");
//    }



//    t.recursiveDelete(t.get_root(), 22);

//    t.inorder(t.get_root());

//    if(t.search(22) == nullptr)
//    {
//        printf("element is not found \n");
//    }
//    else
//    {
//        printf("element is found \n");
//    }


























