
#include <exception>
#include <cassert>

#include "list.h"
#include <list>

namespace Data_Structure
{


// Iterator implementation //////////////////////////

template <typename T>
List<T>::Iterator::Iterator(SNode* pNode, List<T>* pList)
    : m_pNode{ pNode }
    , m_pList{ pList }
{}

template <typename T>
List<T>::Iterator::Iterator(const Iterator& oIter)
    : m_pNode{ oIter.m_pNode }
    , m_pList{ oIter.m_pList }
{}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator=(const Iterator& oIter)
{
    m_pNode = oIter.m_pNode;
    m_pList = oIter.m_pList;
    return Iterator{ m_pNode };
}

template<typename T>
typename List<T>::Iterator::reference List<T>::Iterator::operator*()
{
    return const_cast<T&>(const_cast<Iterator const*>(this)->operator*());
}

template<typename T>
typename List<T>::Iterator::const_reference List<T>::Iterator::operator*() const
{
    if(m_pNode == m_pList->end().m_pNode)
    {
        throw std::exception{};
    }

    assert(m_pNode);
    return m_pNode->value;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
    assert(m_pNode->next);
    m_pNode = m_pNode->next;
    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--()
{
    assert(m_pNode->prev);
    m_pNode = m_pNode->prev;
    return *this;
}

template<typename T>
bool List<T>::Iterator::operator==(Iterator const& oIter)
{
    return m_pNode == oIter.m_pNode;
}

template<typename T>
bool List<T>::Iterator::operator!=(Iterator const& oIter)
{
    return !this->operator==(oIter);
}
/////////////////////////////////////////////////////

// ConstIterator implementation /////////////////////
template <typename T>
List<T>::ConstIterator::ConstIterator(SNode* pNode, List<T>* pList)
    : m_pNode{ pNode }
    , m_pList{ pList }
{}

template <typename T>
List<T>::ConstIterator::ConstIterator(ConstIterator const& oIter)
    : m_pNode{ oIter.m_pNode }
    , m_pList{ oIter.m_pList }
{}

template <typename T>
List<T>::ConstIterator::ConstIterator(Iterator const& oIter)
    : m_pNode{ oIter.m_pNode }
    , m_pList{ oIter.m_pList }
{}

template <typename T>
bool List<T>::ConstIterator::operator!=(Iterator const& oIter) const
{
    return m_pNode != oIter.m_pNode;
}

template <typename T>
bool List<T>::ConstIterator::operator==(Iterator const& oIter) const
{
    return !this.operator!=(oIter);
}

template <typename T>
typename List<T>::ConstIterator::reference List<T>::ConstIterator::operator*() 
{
    return const_cast<T&>(const_cast<const ConstIterator*>(this)->operator*());
}

template <typename T>
typename List<T>::ConstIterator::const_reference List<T>::ConstIterator::operator*() const 
{
    if(m_pNode == m_pList->end().m_pNode)
    {
        throw std::exception{};
    }

    assert(m_pNode);
    return m_pNode->value;
}
/////////////////////////////////////////////////////

// ReverseIterator implementation ///////////////////
template <typename T>
List<T>::ReverseIterator::ReverseIterator(SNode* pNode, List<T>* pList)
    : m_pNode{ pNode }
    , m_pList{ pList }
{}

template <typename T>
List<T>::ReverseIterator::ReverseIterator(ReverseIterator const& oIter)
    : m_pNode{ oIter.m_pNode }
    , m_pList{ oIter.m_pList }
{}

template <typename T>
typename List<T>::ReverseIterator& List<T>::ReverseIterator::operator=(ReverseIterator const& oIter)
{
    m_pNode = oIter.m_pNode;
    m_pList = oIter.m_pList;
    return *this;
}

template <typename T>
T& List<T>::ReverseIterator::operator*() 
{
    return const_cast<T&>(const_cast<const ReverseIterator*>(this)->operator*());
}

template <typename T>
const T& List<T>::ReverseIterator::operator*() const 
{
    if(m_pNode == m_pList->end().m_pNode)
    {
        throw std::exception{};
    }

    assert(m_pNode);
    return m_pNode->value;
}

template <typename T>
typename List<T>::ReverseIterator& List<T>::ReverseIterator::operator++() 
{
    assert(m_pNode->prev);
    m_pNode = m_pNode->prev;
    return *this;
}

template <typename T>
typename List<T>::ReverseIterator& List<T>::ReverseIterator::operator--() 
{
    assert(m_pNode->next);
    m_pNode = m_pNode->next;
    return *this;
}

template <typename T>
bool List<T>::ReverseIterator::operator!=(ReverseIterator const& oIter) const
{
    return m_pNode != oIter.m_pNode;
}

template <typename T>
bool List<T>::ReverseIterator::operator==(ReverseIterator const& oIter) const
{
    return !this.operator!=(oIter);
}
/////////////////////////////////////////////////////

// List implementation //////////////////////////////
template<typename T>
List<T>::~List() {
    clear();
}
    
// reference semantics
template<typename T>
List<T>::List(List<T> const& oOther)
{
    SNode* pNode = oOther.m_pHead;
    while(pNode)
    {
        push_back(pNode->value);
        pNode = pNode->next;
    }
}

template<typename T>
List<T>& List<T>::operator=(List<T> oOther)
{
    // copy and swap idiom
    swap(*this, oOther);
    return(*this);
}
    
// move-semantics
template<typename T>
List<T>::List(List<T>&& oOther) noexcept
    : m_pHead{ oOther.m_pHead }
    , m_pTail{ oOther.m_pTail }
    , m_oSize{ oOther.m_oSize }
{
    oOther.m_pHead = oOther.m_pTail = nullptr;
    oOther.m_oSize = 0;
}

template<typename T>
List<T>& List<T>::operator=(List<T>&& oOther) noexcept
{
    // copy and swap idiom
    swap(*this, oOther);
    return(*this);
}

// Iterators
template<typename T>
typename List<T>::Iterator List<T>::begin()
{
    return Iterator{ m_pHead, this };
}

template<typename T>
typename List<T>::Iterator List<T>::end()
{
    return Iterator{ m_pDummy, this };
}

template<typename T>
typename List<T>::ConstIterator List<T>::cbegin() const
{
    return ConstIterator{ m_pHead, this };
}

template<typename T>
typename List<T>::ConstIterator List<T>::cend() const
{
    return ConstIterator{ m_pDummy, this };
}

template<typename T>
typename List<T>::ReverseIterator List<T>::rbegin()
{
    return ReverseIterator{m_pTail, this };
}

template<typename T>
typename List<T>::ReverseIterator List<T>::rend()
{
    return ReverseIterator{ m_pDummy, this };
}

// Capacity
template<typename T>
bool List<T>::empty()
{
    return m_oSize == 0;
}

template<typename T>
typename List<T>::size_type List<T>::size()
{
    return m_oSize;
}

// Modifiers
template<typename T>
void List<T>::clear()
{
    while(m_pHead)
    {
        SNode* pNode = m_pHead;
        m_pHead = m_pHead->next;
        delete pNode;

        --m_oSize;
    }

}

template<typename T>    
void List<T>::erase(Iterator cit)
{
    if(!cit.m_pNode)
        throw std::exception{};

    for(Iterator it = begin(); it != end(); ++it)
    {
        if(it == cit)
        {
            cit.m_pNode->prev->next = cit.m_pNode->next;
            cit.m_pNode->next->prev = cit.m_pNode->prev;
            delete cit.m_pNode;

            --m_oSize;
            break;
        }
    }
}

template<typename T>
typename List<T>::Iterator List<T>::insert(Iterator it, const_reference value)
{
    if(!it.m_pNode)
        throw std::exception{};

    SNode* pNewNode = new SNode{ value };
    assert(pNewNode);

    if (empty()) {
        assert(m_pHead == m_pDummy && m_pTail == m_pDummy);
        m_pHead = m_pTail = pNewNode;
        m_pHead->prev = m_pDummy;
        m_pTail->next = m_pDummy;        
    }
    else if(it == begin())
    {
        m_pHead->prev = pNewNode;
        pNewNode->next = m_pHead;
        m_pHead = m_pHead->prev;
        m_pHead->prev = m_pDummy;
    }
    else if(it == end())
    {
        pNewNode->next = m_pDummy;
        m_pDummy->prev = pNewNode;
        pNewNode->prev = m_pTail;
        m_pTail->next = pNewNode;
        m_pTail = pNewNode;
    }
    else
    {
        pNewNode->next = it.m_pNode;
        pNewNode->prev = it.m_pNode->prev;
        it.m_pNode->prev = pNewNode;
        pNewNode->prev->next = pNewNode;
    }
    
    ++m_oSize;

    return Iterator{ pNewNode, this };
}

template<typename T>
void List<T>::push_back( const_reference value )
{   
    insert(end(), value);
}

template<typename T>
void List<T>::push_back( value_type&& value )
{
    insert(end(), value);

    // SNode* pNewNode = new SNode{ value };

    // if (empty()) {
    //     assert(m_pHead == m_pDummy && m_pTail == m_pDummy);
    //     m_pHead = m_pTail = pNewNode;
    //     m_pHead->prev = m_pDummy;
    //     m_pTail->next = m_pDummy;
    //     ++m_oSize;
    //     return;
    // }
    // assert(m_pHead != m_pDummy && m_pTail != m_pDummy);
    // m_pTail->next = pNewNode;
    // pNewNode->prev = m_pTail;
    // m_pTail = m_pTail->next;
    // m_pTail->next = m_pDummy;

    // ++m_oSize;
}

template<typename T>
void List<T>::push_front( const_reference value )
{
    //push_front(std::move(value));

    insert(begin(), value);
}

template<typename T>
void List<T>::push_front( value_type&& value )
{
    insert(begin(), value);

    // SNode* pNewNode = new SNode{ value };
    // if (empty()) {
    //     assert(m_pHead == m_pDummy && m_pTail == m_pDummy);
    //     m_pHead = m_pTail = pNewNode;
    //     m_pHead->prev = m_pDummy;
    //     m_pTail->next = m_pDummy;
    //     ++m_oSize;
    //     return;
    // }
    // assert(m_pHead != m_pDummy && m_pTail != m_pDummy);
    // m_pHead->prev = pNewNode;
    // pNewNode->next = m_pHead;
    // m_pHead = m_pHead->prev;
    // m_pHead->prev = m_pDummy;
    // ++m_oSize;
}

template<typename T>
template< class... Args >
typename List<T>::Iterator List<T>::emplace( List<T>::ConstIterator itPos, Args&&... args )
{
    insert(itPos, value_type(std::forward<Args>(args)...));
}


template<typename T>
template< class... Args >
typename List<T>::reference List<T>::emplace_back( Args&&... args )
{
    push_back(value_type(std::forward<Args>(args)...));
}

template<typename T>
template< class... Args >
typename List<T>::reference List<T>::emplace_front( Args&&... args )
{
    push_front(value_type(std::forward<Args>(args)...));
}

template<typename T>
void List<T>::pop_back()
{
    m_pTail = m_pTail->prev;
    delete m_pTail->next;
    m_pTail->next = m_pDummy;

    --m_oSize;
}

template<typename T>
void List<T>::pop_front()
{
    m_pHead = m_pHead->next;
    delete m_pHead->prev;
    m_pHead->prev = m_pDummy;

    --m_oSize;
}

template<typename T>
void List<T>::swap( List& oOther ) noexcept
{
    // ADL - Argument-Dependent Lookup
    using std::swap;
    swap(m_pHead,  oOther.m_pHead);
    swap(m_pTail,  oOther.m_pTail);
    swap(m_oSize,  oOther.m_oSize);
    swap(m_pDummy, oOther.m_pDummy);
}


} // Data_Structure
