//SequeStack.h
#pragma once

#include <assert.h>

template<typename ElemType>
class SequeStack
{
public:
    SequeStack(unsigned int size);
    bool Push(ElemType elem);
    bool Pop(ElemType* retElem);
    bool Empty() const;
    bool Visit(ElemType* elem, unsigned int pos) const;
    bool Full() const;
    unsigned int const& GetLength() const;
private:
    ElemType* m_array;
    unsigned int m_top;
    unsigned int m_size;
    unsigned int m_length;
};

template<typename ElemType>
unsigned int const& SequeStack<ElemType>::GetLength() const
{
    return m_top;
}

template<typename ElemType>
bool SequeStack<ElemType>::Full() const
{
    return m_top >= m_size ? true : false;
}

template<typename ElemType>
bool SequeStack<ElemType>::Visit(ElemType* elem, unsigned int pos) const
{
    if (pos >= m_size || pos < 0)
    {
        assert(false && "Error: Visit Pos is out range of array!");
        return false;
    }
    *elem = m_array[pos];
    return true;
}


template<typename ElemType>
bool SequeStack<ElemType>::Empty() const
{
    return m_top ? false : true;
}

template<typename ElemType>
bool SequeStack<ElemType>::Pop(ElemType* retElem)
{
    if (Empty())
    {
        assert(false && "Error: SequeStack is underflow!");
        return false;
    }
    else
    {
        *retElem = m_array[--m_top];
        return true;
    }
}

template<typename ElemType>
bool SequeStack<ElemType>::Push(ElemType pushElem)
{
    if (m_top == m_size)
    {
        assert(false && "Error: SequeStack is overflow!");
        return false;
    }
    else
    {
        m_array[m_top++] = pushElem;
        return true;
    }

}

template<typename ElemType>
SequeStack<ElemType>::SequeStack(unsigned int size)
    : m_array(new ElemType[size]),m_top(0),m_size(size),m_length(0)
{
    memset(m_array,0,sizeof(ElemType)*size);
}