#include "queue.h"
#include <iostream>

void Queue::enqueue(int x)
{
     if(rear==size-1)
        printf("Queue Full\n");

     else
     {
         rear++;
         Q[rear]=x;
     }
}
int Queue::dequeue()
{
     int x=-1;
     if(front==rear)
        printf("Queue is Empty\n");
     else
     {
         x=Q[front+1];
         front++;
     }
     return x;
}
void Queue::Display()
{
     for(int i=front+1;i<=rear;i++)
         printf("%d ",Q[i]);
         printf("\n");
}
