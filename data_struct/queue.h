#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

class Queue
{
    private:
        int front;
        int rear;
        int size;
        Node **Q;
    public:
     Queue(){front=rear=-1;size=10;Q=new Node*[size];}
     Queue(int size){front=rear=-1;this->size=size;Q=new Node*[this->size];}
     void enqueue(Node* x);
     Node* dequeue();
     void Display();
     bool empty();
};
#endif // QUEUE_H
