
#ifndef _DATA_STRUCTURE_STACK_HPP
#define _DATA_STRUCTURE_STACK_HPP

#include <iostream>
#include <vector>

namespace Data_Structure
{

template<typename T>
class Stack
{
public:
    using value_type        = T;
    using size_type         = std::size_t;
    using reference         = value_type&;
    using const_reference   = value_type const&;

    Stack(size_type = 10);
    Stack(Stack&);

    virtual void push(value_type); 
    virtual value_type pop(); 

    virtual bool isFull();
    virtual bool isEmpty();

    virtual size_type size(); 

protected:
    int m_iTop { -1 };
    std::vector<T> m_aContainer;
    size_t m_nSize { 0 };

}; // class Stack

} // Data_Structure

#include "stack.impl.h"

#endif // _DATA_STRUCTURE_STACK_HPP
