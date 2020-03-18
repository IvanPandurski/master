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
