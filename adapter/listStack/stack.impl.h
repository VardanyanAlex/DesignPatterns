
#include <iostream>

#include "stack.h"

namespace Data_Structure
{

// Stack implementation //////////////////////////

template<typename T>
Stack<T>::Stack(Stack<T>::size_type nSize)
    : m_nSize{ nSize }
{}

template<typename T>
Stack<T>::Stack(Stack<T>& oOther)
    : m_nSize{ oOther.m_nSize }
    , m_iTop{ oOther.m_iTop }
    , m_aContainer{ oOther.m_aContainer }
{}

template<typename T>
bool Stack<T>::isFull()
{
    return m_nSize == m_iTop + 1;
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return m_iTop == -1;
}

template<typename T>
typename Stack<T>::size_type Stack<T>::size()
{
    return m_nSize;
}

template<typename T>
void Stack<T>::push(Stack<T>::value_type value)
{
    if (!isFull())
    {
        m_aContainer.push_back(value);
        ++m_iTop;
    }
}

template<typename T>
typename Stack<T>::value_type Stack<T>::pop()
{
    value_type oValue{};
    if (!isEmpty())
    {
        --m_iTop;
        oValue = m_aContainer.back();
        m_aContainer.pop_back();
    }

    return oValue;
}
//////////////////////////////////////////////////

} // Data_Structure
