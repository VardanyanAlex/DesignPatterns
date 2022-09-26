
#include <iostream>

#include "listAdapterToStack.h"

int main()
{

    using namespace Data_Structure;

    Stack<double>* aMyStack = new CListAdaptertoStack<double>;

    std::cout << "my stack size = " << aMyStack->size() << std::endl;

    std::cout << "push back 0-9 numbers" << std::endl;
    for(int i = 0; i < 10; ++i)
    {
        aMyStack->push(i);
    }

    std::cout << "is My stack full? answer: " << aMyStack->isFull() << std::endl;

    std::cout << "popped last Element and that was: " << aMyStack->pop() << std::endl;

    std::cout << "is My stack empty? answer: " << aMyStack->isEmpty() << std::endl;

    std::cout << "My stack's size now is: " << aMyStack->size() << std::endl;

    std::cout << "is My stack full? answer: " << aMyStack->isFull() << std::endl;

    // Data_Structure::List<int> aList;

    // int num1 = 8;
    // short num2 = 11;

    // for(int i = 0; i < 10; ++i)
    // {
    //     aList.push_back(i);
    // }

    // std::cout << "test: push back 0-9 numbers then print first element: " << std::endl; 
    // std::cout << "begin: " <<  *aList.begin() << std::endl;

    // std::cout << "test: print size: " << std::endl; 
    // std::cout << "size: " << aList.size() << std::endl;

    // std::cout << "test:  0-9 numbers: " << std::endl; 
    // for(Data_Structure::List<int>::Iterator it = aList.begin(); it != aList.end(); it++)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "test: third element: " <<  *(++(++aList.begin())) << std::endl;

    // aList.insert(++(++aList.begin()), 714);

    // std::cout << "test: inserted 714 in third position: " << std::endl; 
    // for(Data_Structure::List<int>::Iterator it = aList.begin(); it != aList.end(); it++)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    
    // aList.push_front(4);
    
    // std::cout << "test: push front 4: " << std::endl; 
    // for(Data_Structure::List<int>::Iterator it = aList.begin(); it != aList.end(); it++)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "test: get first elements and print plus 5: " << std::endl; 
    // std::cout << *aList.begin() + 5 << std::endl; 

    // Data_Structure::List<int> aSecondList;
    // for(int i = 5; i > 0; --i)
    // {
    //     aSecondList.push_back(i);
    // }

    // std::cout << "test: print aSecondList " << std::endl; 
    // for(Data_Structure::List<int>::Iterator it = aSecondList.begin(); it != aSecondList.end(); it++)
    // {
    //     std::cout << *it << " ";
    // }

    // swap(aList, aSecondList);
    // std::cout << "test: swapped 2 lists " << std::endl; 
    // std::cout << "test: print aList " << std::endl; 
    // for(Data_Structure::List<int>::Iterator it = aList.begin(); it != aList.end(); it++)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "test: print aSecondList " << std::endl; 
    // for(Data_Structure::List<int>::Iterator it = aSecondList.begin(); it != aSecondList.end(); it++)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "test: reverse print with rbegin and rend " << std::endl; 
    // for(Data_Structure::List<int>::ReverseIterator it = aSecondList.rbegin(); it != aSecondList.rend(); it++)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
    
    // std::cout << "test: print aSecondList " << std::endl; 
    // for(Data_Structure::List<int>::Iterator it = aSecondList.begin(); it != aSecondList.end(); it++)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
}
