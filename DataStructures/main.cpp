//#include "ArrayADT.cpp"
#include <stdio.h>
//#include "menudriverprogramarrays.h"
//#include "Stack.cpp"
//tail recursion
void fun(int n)
{
    if(n > 0)
    {
        printf("%d ", n); //at calling time
        fun(n-1);
    }
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

#include "LinkedList.cpp"
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

//class base1
//{
//public:
//    base1() {printf("constructor base 1\n");}
//    ~base1() {printf("destructor base 1\n");}
//};

//class base2
//{
//public:
//    base2() {printf("constructor base 2\n");}
//    ~base2() {printf("destructor base 2\n");}

//};
//class b : public base2, public base1
//{
//public:
//    b() {printf("constructor b\n");}
//    ~b() {printf("destructor b\n");}

//};

#include "InfixToPostfix.cpp"

int main(int argc, char *argv[])
{
//    b asd{};
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


//    Array arr {};
//    int n {};
//    printf("Enter size of an array ");
//    scanf("%d", &arr.size);
//    arr.A = (int*)malloc(arr.size*sizeof(int));
//    arr.lenght = 0;

//    printf("Enter number of numbers");
//    scanf("%d", &n);

//    printf("Enter all elements\n");
//    for(int i = 0 ; i < n; ++i)
//    {
//        scanf("%d", &arr.A[i]);
//    }

//    arr.lenght = n;



//    arr.Append(16);
//    arr.Insert(3,22);
//    arr.Delete(5);

//    printf("%d ", arr.SearchLinear(4));
     printf("\n");
//    printf("%d ", arr.SearchBinaryLoop(4));
//     printf("\n");
//    printf("%d ", arr.SearchBinaryRecursive(0, arr.lenght-1,5));
//     printf("\n");

//     arr.Reverse();
//     arr.LeftShift();
//     arr.RightShift();
//     printf("\n");
//     arr.Display();
//     int i = 0;
//     while(i < 20)
//     {
//         arr.RightRotate();
//         printf("\n");
//         arr.Display();
//         i++;
//     }

//    Array arr = {{2,6,10,15,25}, 10, 5};
//    arr.Display();
//    printf("\n");

//    Array arr2 = {{3,6,7,15,20}, 10, 5};
//    arr2.Display();
//    printf("\n");

//    Array* arr3 = arr.Merge(&arr, &arr2);
//    arr3->Display();
//    printf("\n");

//    Array* arr4 = arr.Union(&arr, &arr2);
//    arr4->Display();
//    printf("\n");

//    Array* arr5 = arr.Intersection(&arr, &arr2);
//    arr5->Display();
//    printf("\n");

//    Array* arr6 = arr.Difference(&arr, &arr2);
//    arr6->Display();
//    printf("\n");

//    delete arr4;
//    delete arr3;

//     MenuDriverProgramArrays menu;
//     menu();

     //ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY ARRAY

     //LINKED LIST LINKED LIST LINKED LIST LINKED LIST LINKED LIST LINKED LIST LINKED LIST LINKED LIST LINKED LIST LINKED LIST LINKED LIST LINKED LIST LINKED LIST LINKED LIST LINKED LIST
//     int A[] = {3,5,7,10,15};

//     Node::create(A,5);
//     Node::Display();

//     Node::DisplayRecursion(first);
//     printf("\n");

//    Node::Count(first);
//    printf("recursion call count %d \n", Node::CountRecursion(first));

//    Node::Sum();

//    Node::Max();

//    Node* n = Node::Search(15);

//    if(n != nullptr)
//    {
//        printf("the key is found - %d \n", n->data);
//    }

//    Node::Insert(0,22);
//   Node::InsertLast(5);
//   Node::Display();
//   Node::InsertLast(7);
//   Node::Display();
//   Node::InsertLast(9);
//   Node::Display();
//   Node::InsertInSorted(8);
//   Node::Display(first);
//   Node::InsertInSorted(2);
//   Node::Display(first);
//   Node::InsertInSorted(1);
//   Node::Display(first);
//   Node::InsertInSorted(11);
//   Node::Display(first);
//   Node::InsertInSorted(11);
//   Node::Display(first);
//   Node::Delete(2);
//   Node::Display(first);
//   printf("Is sorted: %d\n", Node::IsSorted());
//   Node::RemoveDuplicates();
//   Node::Display(first);

//   int a[] = {10,20,40,50,60};
//   int b[] = {15,18,25,30,55};

//   Node::create(a,5);
//   Node::create2(b,5);
//   Node::Display(first);
//   Node::Display(second);

//   Node::Merge(first,second);
//   Node::Display(third);


//   printf("size of Node: %d \n", sizeof (Node));

//     int a[] = {10,20,40,50,60};
//     int b[] = {15,18,25,30,55};

//     LinkedList l1{a,5};
//     LinkedList l2{b,5};
//     l1.Display();
//     l2.Display();
//     LinkedList l3;
//     l3.Merge(l1.first,l2.first);
//     l3.Display();

//     LinkedList circular{a,5,true};
//     circular.DisplayCircular();


//    Stack<int> s;
//    s.push(20);
//    s.push(40);
//    s.push(60);
//    s.display();
//    s.pop();
//    s.display();

     InfixToPostfix infix("2+3*4-6/2");
     printf("%s \n", infix.toPostfix());
     printf("%d \n", infix.Evaluate());

    return 0;
}
