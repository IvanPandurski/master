#include "hashing.h"
#include <iostream>
Hashing::Hashing()
{
    list = {LinkedList(), LinkedList(), LinkedList(), LinkedList(), LinkedList(), LinkedList(),
           LinkedList(), LinkedList(), LinkedList(), LinkedList()};
}

void Hashing::insert(int key)
{
    int index=hash(key);
    list.at(index).InsertInSorted(key);
}

void Hashing::search(int key)
{
    int idx = hash(key);
    Node* p = list.at(idx).first;
    bool flag {false};
    while (p != nullptr)
    {
        if(key == p->data)
        {
            std::cout<< "the key "<< p->data<<" is found! \n";
            flag = true;
        }
        p = p->next;
    }

    if(flag == false)
     std::cout<< "the key "<<key<<" is not found! \n";
}


//in main

//    Hashing h;
//    h.insert(5);
//    h.insert(65);
//    h.insert(55);

//    h.insert(2);
//    h.search(65);
//    h.search(1);
