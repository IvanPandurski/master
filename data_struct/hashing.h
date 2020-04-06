#ifndef HASHING_H
#define HASHING_H
#include "LinkedList.h"
#include <vector>
class Hashing
{
public:
    Hashing();
    void insert(int key);
    void search(int key);
private:
    inline int hash(int idx) {return idx%10;}

private:
    std::vector<LinkedList> list {};
};

#endif // HASHING_H
