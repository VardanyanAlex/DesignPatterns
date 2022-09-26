
#ifndef _DATA_STRUCTURES_LIST_HPP
#define _DATA_STRUCTURES_LIST_HPP

namespace Data_Structure
{

template<typename T>
class List
{
public:

    using value_type        = T;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;
    using reference         = value_type&;
    using const_reference   = T const&;
    using pointer           = value_type*;
    using const_pointer     = value_type const*;

    class Iterator
    { 
    public:
        // iterator constraints
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = const T*;
        using const_reference   = const T&;
        using reference         = T&;
        using iterator_category = std::bidirectional_iterator_tag;

        // Copyable and Assignable requirements provided
        Iterator(Iterator const&);
        Iterator& operator=(Iterator const&);

        reference operator*();
        const_reference operator*() const;

        Iterator& operator++();
        Iterator& operator--();
        
        bool operator==(Iterator const&);
        bool operator!=(Iterator const&);

    private:
        Iterator(typename List<T>::SNode*, List<T>*);

    private:
        typename List<value_type>::SNode* m_pNode{ nullptr };
        List<T>* m_pList{ nullptr };

        // only List class can access to Iterator private ctor
        friend class List;

        //  hidden friend idiom
        friend List<value_type>::Iterator operator++(Iterator& oItRHS, int)
        {
            Iterator oIt = oItRHS;
            ++oItRHS;
            return oIt;
        }

    }; // class Iterator

    class ConstIterator
    { 
    public:
        // iterator constraints
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = const T*;
        using reference         = value_type&;
        using const_reference   = T const&;
        using iterator_category = std::bidirectional_iterator_tag;

        // Copyable and Assignable requirements provided
        ConstIterator(ConstIterator const&);
        ConstIterator(Iterator const&);
        ConstIterator& operator=(ConstIterator const&);
        ConstIterator& operator=(Iterator const&);

        reference operator*();
        const_reference operator*() const;
        
        bool operator==(Iterator const&) const;
        bool operator!=(Iterator const&) const;

    private:
        ConstIterator(typename List<value_type>::SNode*, List<T>*);

    private:
        typename List<value_type>::SNode* m_pNode{ nullptr };
        List<T>* m_pList{ nullptr };

        // only List class can access to ConstIterator private ctor
        friend class List;

    }; // class ConstIterator

    class ReverseIterator
    { 
    public:
        // iterator constraints
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = const T*;
        using reference         = T&;
        using const_reference   = T const&;
        using iterator_category = std::bidirectional_iterator_tag;

        // Copyable and Assignable requirements provided
        ReverseIterator(ReverseIterator const&);
        ReverseIterator& operator=(ReverseIterator const&);

        reference operator*();
        const_reference operator*() const;

        ReverseIterator& operator++();
        ReverseIterator& operator--();
        
        bool operator==(ReverseIterator const&) const;
        bool operator!=(ReverseIterator const&) const;

    private:
        ReverseIterator(typename List<T>::SNode*, List<T>*);

    private:
        typename List<value_type>::SNode* m_pNode{ nullptr };
        List<T>* m_pList{ nullptr };

        // only List class can access to Iterator private ctor
        friend class List;

        //  hidden friend idiom
        friend List<value_type>::ReverseIterator operator++(ReverseIterator& oItRHS, int)
        {
            ReverseIterator oIt = oItRHS;
            ++oItRHS;
            return oIt;
        }

    }; // class ReverseIterator
    
    List() =default;

    /// Rule of five
    ~List() ;
    
    // reference semantics
    List(List const&); 
    List& operator=(List); 
    
    // move-semantics
    List(List&&) noexcept;
    List& operator=(List&&) noexcept;

    // Iterators
    Iterator begin();
    Iterator end();

    ConstIterator cbegin() const;
    ConstIterator cend() const;

    ReverseIterator rbegin();
    ReverseIterator rend();

    // Capacity
    bool empty();
    size_type size();

    // Modifiers
    void clear();
    
    void erase(Iterator);

    Iterator insert(Iterator, const_reference value);

    void push_back( const_reference value );
    void push_back( value_type&& value );

    void push_front( const_reference value );
    void push_front( value_type&& value );

    template< class... Args >
    Iterator emplace( ConstIterator pos, Args&&... args );

    template< class... Args >
    reference emplace_back( Args&&... args );

    template< class... Args >
    reference emplace_front( Args&&... args );

    void pop_back();
    void pop_front();

    void swap( List& other ) noexcept;

private:
    struct SNode
    {
        value_type value{};
        SNode* next{ nullptr };
        SNode* prev{ nullptr };

        SNode() =default;
        SNode(const_reference v)
            : value{ v }
        {}
    };
private:
    SNode* m_pDummy{ new SNode };
    
    SNode* m_pHead = m_pDummy;
    SNode* m_pTail = m_pDummy;

    size_type m_oSize { 0 };

}; // class List

// Convenience functions
template <typename T>
inline void swap(List<T>& l1, List<T>& l2) noexcept {
    // forwarding
    l1.swap(l2);
}

} // namespace Data_Structure

#include "list.impl.h"

#endif // _DATA_STRUCTURES_LIST_HPP
