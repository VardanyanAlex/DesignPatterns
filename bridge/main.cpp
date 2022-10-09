

#include <iostream>
#include "max_heap.hpp"

int main()
{
    int size;
    std::cin >> size;
    int* p = new int[size];

    for (int i =0 ;i<size; i++)
    {
        std::cin>>p[i];
    }
    heap_sort(p, size);
    
    for (int i = 0;i<size;i++)
    {
        std::cout<<std::endl<<p[i];
    }

}

