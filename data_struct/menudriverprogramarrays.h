#ifndef MENUDRIVERPROGRAMARRAYS_H
#define MENUDRIVERPROGRAMARRAYS_H
#include <stdio.h>
#include "ArrayADT.cpp"
class MenuDriverProgramArrays
{
public:
    MenuDriverProgramArrays() {}
    void operator()()
    {
        Array arr;
        printf("Enter Size of Array");
        scanf("%d", &arr.size);
        arr.A = new int[arr.size];
        arr.lenght = 0;
        int ch{};

        do
        {
            printf("Menu\n");
            printf("1. Insert\n");
            printf("2. Delete\n");
            printf("3. Search\n");
            printf("4. Sum\n");
            printf("5. Display\n");
            printf("6. Exit\n");

            printf("Enter your choice ");
            scanf("%d", &ch);

            int x{}, index{};
            switch (ch)
            {
                case 1: printf("Enter and element and index ");
                        scanf("%d%d",&x,&index);
                        arr.Insert(index,x);
                break;

                case 2: printf("Enter index ");
                        scanf("%d",&index);
                        arr.Delete(index);
                break;
                case 3: printf("Enter element to search ");
                        scanf("%d",&x);
                        index = arr.SearchLinear(x);
                        printf("Element index %d", index);
                break;
                case 4: printf("Sum is %d\n ", arr.Sum());
                break;
                case 5: printf("Display: ");
                        arr.Display();
                break;
            }
        }
        while(ch < 6);

    }

};

#endif // MENUDRIVERPROGRAMARRAYS_H
