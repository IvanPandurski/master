
#include <stdio.h>
#include <iostream>

struct Array
{
    Array() {}

    Array(std::initializer_list<int> init_list, int s, int len) : size(s), lenght(len)
    {
        int i = 0;
        for(const auto& init : init_list)
        {
            A[i] = init;
            i++;
        }
        lenght = i;
    }

    ~Array() {printf("Destructor called \n");}
    int* A;
    int size {};
    int lenght {};


    void Display();
    void Append(int x);
    void Insert(int idx, int x);
    void Delete(int idx);
    void Swap(int x, int y);
    int SearchLinear(int key);
    int SearchBinaryLoop(int key); //better choice
    int SearchBinaryRecursive(int low, int high,int key);

    int Get(int idx);
    void Set(int idx, int x);
    int Max();
    int Min();
    int Sum();
    int Avg();

    void Rearrange();
    bool IsSorted();
    void InsertSort(int x);

    void Reverse();
    void LeftShift();
    void RightShift();
    void LeftRotate();
    void RightRotate();

    Array* Merge(Array* arr1, Array* arr2);

    Array* Union(Array* arr1, Array* arr2);

    Array* Intersection(Array* arr1, Array* arr2);

    Array* Difference(Array* arr1, Array* arr2);

};

void Array::Reverse()
{
    for(int i = 0, j = lenght - 1; i<j; i++, j--)
    {
        Swap(i, j);
    }
}

void Array::LeftShift()
{
    for(int i = 0; i < lenght - 1; ++i)
    {
        A[i] = A[i+1];
    }

    A[lenght - 1] = 0;
}

void Array::RightShift()
{
    for(int i = lenght - 1; i > 0; --i)
    {
        A[i] = A[i-1];
    }

    A[0] = 0;
}

void Array::LeftRotate()
{
    int tmp = A[0];
    for(int i = 0; i < lenght - 1; ++i)
    {
        A[i] = A[i+1];
    }

    A[lenght - 1] = tmp;
}

void Array::RightRotate()
{
    int tmp = A[lenght - 1];
    for(int i = lenght - 1; i > 0; --i)
    {
        A[i] = A[i-1];
    }

    A[0] = tmp;
}

Array *Array::Merge(Array *arr1, Array *arr2)
{
    int i{}, j{}, k{};
    Array* arr3 = new Array;
    while(i < arr1->lenght && j < arr2->lenght)
    {
        if(arr1->A[i] < arr2->A[j]) {arr3->A[k++] = arr1->A[i++];}
        else                        {arr3->A[k++] = arr2->A[j++];}
    }
    for(;i < arr1->lenght; ++i) {arr3->A[k++] = arr1->A[i];}
    for(;j < arr2->lenght; ++j) {arr3->A[k++] = arr2->A[j];}
    arr3->lenght = arr1->lenght + arr2->lenght;
    arr3->size = 10;

    return arr3;
}

Array *Array::Union(Array *arr1, Array *arr2)
{
    int i{}, j{}, k{};
    Array* arr3 = new Array;
    while(i < arr1->lenght && j < arr2->lenght)
    {
        if(arr1->A[i] < arr2->A[j])       {arr3->A[k++] = arr1->A[i++];}
        else if(arr2->A[j] < arr1->A[i] ) {arr3->A[k++] = arr2->A[j++];}
        else                              {arr3->A[k++] = arr1->A[i++]; j++;}
    }

    for(;i < arr1->lenght; ++i) {arr3->A[k++] = arr1->A[i];}
    for(;j < arr2->lenght; ++j) {arr3->A[k++] = arr2->A[j];}
    arr3->lenght = k;
    arr3->size = 10;

    return arr3;
}

Array *Array::Intersection(Array *arr1, Array *arr2)
{
    int i{}, j{}, k{};
    Array* arr3 = new Array;
    while(i < arr1->lenght && j < arr2->lenght)
    {
        if(arr1->A[i] < arr2->A[j])       {i++;}
        else if(arr2->A[j] < arr1->A[i] ) {j++;}
        else if(arr1->A[i] == arr2->A[i] ){arr3->A[k++] = arr1->A[i++]; j++;}
    }

    arr3->lenght = k;
    arr3->size = 10;

    return arr3;
}

Array *Array::Difference(Array *arr1, Array *arr2)
{
    int i{}, j{}, k{};
    Array* arr3 = new Array;
    while(i < arr1->lenght && j < arr2->lenght)
    {
        if(arr1->A[i] < arr2->A[j])       {arr3->A[k++] = arr1->A[i++];}
        else if(arr2->A[j] < arr1->A[i] ) {j++;}
        else                              {i++; j++;}
    }

    for(;i < arr1->lenght; ++i) {arr3->A[k++] = arr1->A[i];}
    arr3->lenght = k;
    arr3->size = 10;

    return arr3;
}


int Array::Get(int idx)
{
    if(idx < 0 || idx >=lenght) return -1;

    return A[idx];
}

void Array::Set(int idx, int x)
{
    if(idx < 0 || idx >=lenght) return;

    A[idx] = x;
}

int Array::Max()
{
    int max = A[0];
    for(int i = 0 ; i < lenght; ++i)
    {
        if(A[i] > max) max = A[i];
    }

    return max;
}
int Array::Min()
{
    int min = A[0];
    for(int i = 0 ; i < lenght; ++i)
    {
        if(A[i] < min) min = A[i];
    }

    return min;
}

int Array::Sum()
{
    int sum {};
    for(int i = 0 ; i < lenght; ++i)
    {
        sum +=A[i];
    }

    return sum;
}

int Array::Avg()
{
    int avg {};
    for(int i = 0 ; i < lenght; ++i)
    {
        avg +=A[i];
    }

    return avg/lenght;
}

void Array::Rearrange()
{
    int i = 0;
    int j = lenght - 1;
    while(i < j)
    {
        while(A[i] < 0) {i++;}
        while(A[j] >= 0) {j--;}
        if(i < j) Swap(i, j);
    }
}

bool Array::IsSorted()
{
    for(int i = 0 ; i < lenght -1; ++i)
    {
        if(A[i] > A[i+1])
            return false;
    }
    return true;
}

void Array::InsertSort(int x)
{
    if(lenght == size) return;
    int i = lenght - 1;
    while(i>=0 && A[i] > x)
    {
        A[i+1] = A[i];
        i--;
    }

    A[i+1] = x;
    lenght++;
}


int Array::SearchBinaryLoop(int key) //better choice
{
    int low = 0 , high = lenght - 1, mid{};
    while(low <= high)
    {
        mid = (low+high)/2;
        if(key == A[mid])
        {
            return mid;
        }
        else if(key < A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int Array::SearchBinaryRecursive(int low, int high,int key)
{
    int mid {};
    if(low <= high)
    {
        mid = (low+high) / 2;

        if(key == A[mid])
        {
            return mid;
        }
        else if(key < A[mid])
        {
            return SearchBinaryRecursive(low, mid-1,key);
        }
        else
        {
            return SearchBinaryRecursive(mid+1, high, key);
        }
    }


    return -1;
}

int Array::SearchLinear(int key)
{
    for(int i = 0; i < lenght; ++i)
    {
        if(key == A[i])
        {
            Swap(A[i], A[0]);
            return i;
        }
    }

    return -1;
}

void Array::Display()
{
    printf("\nelements are\n");
    for(int i = 0; i < lenght; ++i)
    {
        printf("%d ", A[i]);
    }
}

void Array::Append(int x)
{
    if(lenght >= size ) return;

    A[lenght++] = x;
}

void Array::Insert(int idx, int x)
{
    if(idx > lenght || idx < 0) return;

    for(int i = lenght; i > idx; --i)
    {
        A[i] = A[i - 1];
    }

    A[idx] = x;
    lenght++;
}

void Array::Delete(int idx)
{
    if(idx > lenght || idx < 0) return;

    for(int i = idx; i < lenght - 1; ++i)
    {
        A[i] = A[i+1];
    }
    lenght--;
}

void Array::Swap(int x, int y)
{
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}
