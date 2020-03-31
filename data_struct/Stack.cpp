#include <stdio.h>

template <class T>
struct Node_
{
    T data {};
    Node_* next = nullptr;
};

template <class T>
struct Stack
{
    Stack() : top{nullptr} {}
    inline bool empty() const {return top == nullptr;}
    inline bool full() const  {Node_<T>* t = new Node_<T>; return t == nullptr;}
    void        push (T x);
    T           pop();
    T           peek(int pos);
    T           stackTop() {return top != nullptr ? top->data : -1;}
    void        display();
    Node_<T>*   Top() {return top;}

private:
    Node_<T>* top = nullptr;
};
template<class T>
void Stack<T>::display()
{
    Node_<T>* p = top;
    while (p != nullptr)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

template<class T>
void Stack<T>::push(T x)
{
    Node_<T>* t = new Node_<T>;
    if(t == nullptr)
    {
        printf("stack overflow");
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

template<class T>
T Stack<T>::pop()
{
    T x {};
    Node_<T>* p {nullptr};
    if(empty())
    {
        printf("stack is empty");
    }
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        delete p;
    }

    return x;
}

template<class T>
T Stack<T>::peek(int pos)
{
    Node_<T>* p = top;

    for(int i = 0; p != nullptr && i < pos-1; ++i)
    {
        p = p->next;
    }

    if(p != nullptr) {return p->data;}

    return -1;
}





/////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
struct StackArray
{
    StackArray() {size = 10; top = -1; s = new T[size];}
    StackArray(int s) {size = s; top = -1; s = new T[s];}
    int size{0};
    int top{-1};
    T* s = nullptr;

    inline bool empty()     {return top == -1;}
    inline bool full()      {return top == size-1;}
    void        push(T x);
    int         pop();
    int         peek(int pos);
    int         stackTop();
};

template <class T>
void StackArray<T>::push(T x)
{
    if(full()) {printf("stack overflow"); return;}

    top++;
    s[top] = x;
}
template <class T>
int StackArray<T>::pop()
{
    int x = -1;
    if(empty())
    {
        printf("stack is empty");
    }
    else
    {
        x = s[top];
        top--;
    }

    return x;
}
template <class T>
int StackArray<T>::peek(int pos)
{
     int x = -1;
     if(top + pos - 1 < 0)
     {
         printf("invalid position");
     }
     else
     {
        x = s[top - pos + 1];
     }

     return x;
}
template <class T>
int StackArray<T>::stackTop()
{
    return top == -1 ? -1 : s[top];
}


//in main


//    Stack<int> s;
//    s.push(20);
//    s.push(40);
//    s.push(60);
//    s.display();
//    s.pop();
//    s.display();

//     InfixToPostfix infix("2+3*4-6/2");
//     printf("%s \n", infix.toPostfix());
//     printf("%d \n", infix.Evaluate());


