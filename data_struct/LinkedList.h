#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
#endif // LINKEDLIST_H
