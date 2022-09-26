
#ifndef _DATA_STRUCTURE_LIST_ADAPTER_HPP
#define _DATA_STRUCTURE_LIST_ADAPTER_HPP

#include "list.h"
#include "stack.h"

namespace Data_Structure
{

template<typename T>
class CListAdaptertoStack : public Stack<T>
{
public:
    using value_type = T;

    CListAdaptertoStack(size_t nStackSize = 10);
    ~CListAdaptertoStack();

    void push(value_type) override; 
    value_type pop() override; 

    bool isFull() override;
    bool isEmpty() override;

private:
    List<T>* m_paList   = nullptr;

}; // class CListAdaptertoStack

} // namespace Data_Structure

#include "listAdapterToStack.impl.h"

#endif // _DATA_STRUCTURE_LIST_ADAPTER_HPP
