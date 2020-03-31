//tail recursion
#include <stdio.h>
void fun(int n)
{
//    SDL_window a;

    if(n > 0)
    {
        printf("%d ", n); //at calling time
        fun(n-1);    }
}

//head recursion
void fun1(int n)
{
    if(n > 0)
    {
        fun1(n-1);
        printf("%d ", n); //at returning time
    }
}


int fun2(int n)
{
    static int x = 0; // the same with global variable
    if(n > 0)
    {
        x++;
        return fun2(n-1) + x;
    }

    return 0;
}


void funTree(int n) //tree recursion
{
    if(n > 0)
    {
        printf("%d ",n);
        funTree(n-1);
        funTree(n-1);
    }
}


void funBIndirect(int n); //indirect recursion

void funAIndirect(int n) //indirect recursion
{
    if(n > 0)
    {
        printf("%d ", n);
        funBIndirect(n-1);
    }
}

void funBIndirect(int n)//indirect recursion
{
    if(n > 1)
    {
        printf("%d ", n);
        funAIndirect(n/2);
    }
}


int funNested(int n) //nested recursion
{
    if(n > 100)
        return n-10;
    return funNested(funNested(n + 11));
}


int sum(int n) //sum of natural number
{
    if(n == 0)
        return 0;
    else
        return sum(n-1)+n;
}

int sum2(int n) //sum of natural number
{
   return n*(n+1)/2;
}

int factorial(int n)
{
    return ( n == 0 ) ? 1 : factorial(n-1)*n;
}

int pow(int m, int n)
{
    return (n == 0) ? 1 : pow(m,n-1)*m;
}

int pow2(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }

    return (n%2 == 0) ? pow2(m*m, n/2) : m*pow2(m*m,(n-1)/2);
}


int fib(int n)
{
    return (n <= 1) ? 1 : fib(n-2) + fib(n-1);
}

int fib2(int n)
{
    if(n <= 1) return 1;

    int sum{}, f1{}, f2{1};
    for(int i = 0 ; i <= n; ++i)
    {

    }
}

int F[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int fibMemoization(int n)
{
    if(n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if(F[n-2] == -1)
        {
            F[n-2] = fibMemoization(n - 2);
        }
        if(F[n-1] == -1)
        {
            F[n-1] = fibMemoization(n - 1);
        }

        return F[n-2] + F[n-1];
    }
}


void TOH(int n, int A, int B, int C) //Tower of Hanoi
{
    if(n > 0)
    {
        TOH(n-1,A,C,B);
        printf("from %d to %d ",A,C);
        printf("\n");
        TOH(n-1,B,A,C);
    }
}


int f (int &x, int c)
{
     c = c - 1;

    if (c == 0) return 1;

    x = x + 1;

    return f(x,c) * x;
}

//#include "LinkedList.cpp"
//Node* first;
//Node* last;
//void create(int a[], int n)
//{
//    int i{};
//    Node* t = nullptr, *last = nullptr;
//    first = new Node;
//    first->data = a[0];
//    first->next = nullptr;
//    last = first;
//    for(i = 1; i < n; ++i)
//    {
//        t = new Node;
//        t->data = a[i];
//        t->next = nullptr;
//        last->next = t;
//        last = t;
//    }
//}

//void Display(Node* p)
//{
//    while(p != nullptr)
//    {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//}

//void DisplayRecursion(Node* p)
//{
//    if(p != nullptr)
//    {
//        DisplayRecursion(p->next);
//        printf("%d ", p->data); //reverse display

////        printf("%d ", p->data); //display
////        DisplayRecursion(p->next);
//    }
//}





//in main

//    int x = 3;
//    fun(x);
//    fun1(x);
//    int r = fun2(5);
//    printf("%d ", r);
//    printf("\n");

//    funTree(3);
//    printf("\n");

//    funAIndirect(20);
//    printf("\n");


//    printf("%d ", funNested(95));
//    printf("\n");

//    printf("%d ", sum(5));
//    printf("\n");

//    printf("%d ", sum2(5));
//    printf("\n");

//    printf("%d ", factorial(1));
//    printf("\n");

//    printf("%d ", pow(2,5));
//    printf("\n");

//    printf("%d ", pow2(2,5));
//    printf("\n");

//    TOH(3,1,2,3);
//    printf("\n");
