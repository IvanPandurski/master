#include "sorting.h"
#include <array>
#include <iostream>
//#include <utility>
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
