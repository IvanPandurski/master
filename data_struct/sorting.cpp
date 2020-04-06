#include "sorting.h"
#include <array>
#include <iostream>
#include <algorithm>
static constexpr size_t n = 10;
std::array<int,n> arr = {19, 8, 3, 14, 21, 2, 9, 81, 55, 13};


void sorting::print()
{
    for(const auto& i : arr)
    {
        std::cout<< i << " ";
    }
    std::cout<< "\n";
}

void sorting::bubbleSort()
{
    for(size_t i = 0; i < arr.size() - 1; i++)
    {
        int count {0}; // check if already sorted
        for(size_t j = 0; j < arr.size() - 1 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                count++;
            }
        }
        if(count == 0) {break;}
    }

}

void sorting::insertionSort()
{
    for(size_t i = 1; i < arr.size(); i++)
    {
        int j = i -1;
        int x = arr[i];
        while(j > (-1) && arr[j] > x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}

void sorting::selectionSort()
{
    for(size_t i = 0; i < arr.size() - 1; i++)
    {
        size_t k {};
        for(size_t j = k = i; j < arr.size(); j++)
        {
            if(arr[j] < arr[k])
            {
                k = j;
            }
        }
        std::swap(arr[i],arr[k]);
    }
}

void sorting::quicksort()
{
    quicksort_impl(std::begin(arr), std::end(arr));
}

template<class ForwardIt>
void sorting::quicksort_impl(ForwardIt first, ForwardIt last)
{
    if(first == last) return;
    auto pivot = *std::next(first, std::distance(first,last)/2);
    ForwardIt middle1 = std::partition(first, last,
                         [pivot](const auto& em){ return em < pivot; });
    ForwardIt middle2 = std::partition(middle1, last,
                         [pivot](const auto& em){ return !(pivot < em); });
    quicksort_impl(first, middle1);
    quicksort_impl(middle2, last);
}


//in main
//    sorting a;
//    a.print();
////    a.bubbleSort();
////    a.insertionSort();
////    a.selectionSort();
//    a.quicksort();
//    a.print();
