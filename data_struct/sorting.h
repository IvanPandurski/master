#ifndef SORTING_H
#define SORTING_H
#include <array>
class sorting
{
public:
    void print();
    void bubbleSort();
    void insertionSort(); // useful for linked list, this is representation for array
    void selectionSort();

    void quicksort();
    template <class ForwardIt>
    void quicksort_impl(ForwardIt first, ForwardIt last);
};

#endif // SORTING_H
