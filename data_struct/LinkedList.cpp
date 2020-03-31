#include <stdio.h>

struct Node
{
    int data {};
    Node* next = nullptr;
};

struct LinkedList
{
    Node* first = nullptr;
    LinkedList() : first{nullptr} {}
    LinkedList(int a[], int n);
    LinkedList(int a[], int n, bool circular);
    ~LinkedList();

    void Display();
    void DisplayRecursion(Node* p);
    void DisplayCircular();
    int  Lenght();
    void Count(Node* p);
    int  CountRecursion(Node* p);
    void Sum();
    int  SumRecursion();
    void Max();
    Node* Search(int key);
    void Insert(int pos, int x);
    void InsertLast(int x); //push_back
    void InsertInSorted(int x);
    void Delete(int idx);
    bool IsSorted();
    void RemoveDuplicates();
    void Reverse();
    void ReverseRecursive(Node* q, Node* p);
    void Concatenating(Node* p, Node* s);
    void Merge(Node* p, Node* q);
    bool IsLoop();

};

LinkedList::LinkedList(int a[], int n)
{
    int i{};
    Node* t = nullptr, *last = nullptr;
    first = new Node;
    first->data = a[0];
    first->next = nullptr;
    last = first;
    for(i = 1; i < n; ++i)
    {
        t = new Node;
        t->data = a[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

LinkedList::LinkedList(int a[], int n, bool circular)
{
    int i{};
    Node* t = nullptr, *last = nullptr;
    first = new Node;
    first->data = a[0];
    first->next = first;
    last = first;
    for(i = 1; i < n; ++i)
    {
        t = new Node;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node* p = first;
    while(first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}



void LinkedList::Display()
{
    Node* p = first;
    while(p != nullptr)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void LinkedList::DisplayRecursion(Node* p)
{
    if(p != nullptr)
    {
        DisplayRecursion(p->next);
        printf("%d ", p->data); //reverse display

//        printf("%d ", p->data); //display
//        DisplayRecursion(p->next);
    }
}

void LinkedList::DisplayCircular()
{
    Node* p = first;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    }
    while(p != first);
}

int LinkedList::Lenght()
{
    Node* p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
}

void LinkedList::Count(Node* p)
{
    int c = 0;
    while(p != nullptr)
    {
        c++;
        p = p->next;
    }

    printf("count is %d \n", c);
}

int LinkedList::CountRecursion(Node *p)
{
    if(p == nullptr) {return 0;}

    return CountRecursion(p->next) + 1;
}

int LinkedList::SumRecursion()
{
    Node* p = first;
    if(p == nullptr) {return 0;}

    return CountRecursion(p->next) + p->data;
}

void LinkedList::Max()
{
    Node* p = first;
    int max = -1;
    while(p)
    {
        if(p->data > max) {max = p->data;}
        p = p->next;
    }

    printf("Max element in the linked list is %d \n", max);
}

Node* LinkedList::Search(int key)
{
    Node* p = first, *q = nullptr;
    while (p != nullptr)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;

            return p;
        }
        q = p;
        p = p->next;
    }

    return nullptr;
}

void LinkedList::Insert(int pos, int x)
{
    Node* t = nullptr, *p = nullptr;
    if(pos == 0)
    {
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(pos > 0)
    {
        p = first;
        for(int i = 0; i < pos -1 && p; ++i)
        {
            p = p->next;
        }
        if(p != nullptr)
        {
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

void LinkedList::InsertLast(int x)
{
    Node* t = new Node;
    Node* last = nullptr;
    t->data = x;
    t->next = nullptr;
    if(first == nullptr)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void LinkedList::InsertInSorted(int x)
{
    Node* p = first;
    if(p == nullptr)
    {
        first = new Node;
        first->data = x;
        first->next = nullptr;
        return;
    }

    if(x < first->data)
    {
        Node* t = new Node;
        t->data = x;
        t->next = first;
        first = t;
        return;
    }

    while(p && p->next && p->next->data < x)
    {
        p = p->next;
    }
    Node* t = new Node;
    t->data = x;
    t->next = p->next;
    p->next = t;
}

void LinkedList::Delete(int idx)
{
    Node* p = first;
    Node* q = nullptr;
    int x {0};
    if(idx < 1) return; // TODO or idx > count
    if(idx == 1)
    {
        q = first;
        x = first->data;
        first=first->next;
        delete q;
    }
    else
    {
        for(int i = 0; i < idx - 1; ++i)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        delete p;
        printf("Deleted node is with data: %d\n", x);

    }
}

bool LinkedList::IsSorted()
{
    int x = {-1};
    Node* p = first;
    while(p != nullptr)
    {
        if(p->data < x) { return false; }
        x = p->data;
        p = p->next;
    }

    return true;
}

void LinkedList::RemoveDuplicates()
{
    Node* p = first;
    Node* q = first->next;

    while(q != nullptr)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void LinkedList::Reverse()
{
    Node* p = first;
    Node* q = nullptr;
    Node* r = nullptr;
    while(p != nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first = q;
}

void LinkedList::ReverseRecursive(Node *q, Node *p)
{
    if(p != nullptr)
    {
        ReverseRecursive(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void LinkedList::Concatenating(Node* p, Node* s)
{
    p = first;
    while(p->next != nullptr)
    {
        p = p->next;
    }
    p->next = s;
}

void LinkedList::Merge(Node *p, Node *q)
{
    Node* last = nullptr;
    if(p->data < q->data)
    {
        first = last = p;
        p=p->next;
        first->next = nullptr;
    }
    else
    {
        first = last = q;
        q = q->next;
        first->next = nullptr;
    }

    while (p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = nullptr;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = nullptr;
        }
    }

    if(p) last->next = p;
    if(q) last->next = q;

}

bool LinkedList::IsLoop()
{
    Node* p = nullptr;
    Node* q = nullptr;
    p = q = first;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    }
    while(p && q && p != q);

    return (p == q) ? true : false;
}

void LinkedList::Sum()
{
    int sum {0};
    Node* p = first;
    while (p )
    {
        sum += p->data;
        p = p->next;
    }

    printf("sum of all elements is %d \n ", sum);
}


//in main
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
