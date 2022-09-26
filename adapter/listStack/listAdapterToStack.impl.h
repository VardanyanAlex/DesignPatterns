
#include "listAdapterToStack.h"

namespace Data_Structure
{

// CListAdaptertoStack implementation ////////////////////////////////////////////

template<typename T>
CListAdaptertoStack<T>::CListAdaptertoStack(size_t nStackSize)
    : Stack<T>(nStackSize)
{
    m_paList = new List<T>;
}

template<typename T>
CListAdaptertoStack<T>::~CListAdaptertoStack()
{
    delete m_paList;
}

template<typename T>
void CListAdaptertoStack<T>::push(typename CListAdaptertoStack<T>::value_type oValue) 
{
    assert(!isFull());

    if(!isFull())
    {
        m_paList->push_back(oValue);

        ++this->m_iTop;
    }
}

template<typename T>
typename CListAdaptertoStack<T>::value_type CListAdaptertoStack<T>::pop() 
{
    value_type oValue{};
    if (!m_paList->empty())
    {
        oValue = *(--m_paList->end());
        m_paList->pop_back();

        --this->m_iTop;
    }

    return oValue;
}

template<typename T>
bool CListAdaptertoStack<T>::isFull()
{
    return m_paList->size() == this->m_nSize;
}

template<typename T>
bool CListAdaptertoStack<T>::isEmpty()
{
    return m_paList->empty();
}
//////////////////////////////////////////////////////////////////////////////////

} // namespace Data_Structure
