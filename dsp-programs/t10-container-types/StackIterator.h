
// COS30008, Tutorial 10, 2021

#pragma once
#include <iostream>

#include "Stack.h"
using namespace std;
template<typename T>
class StackIterator
{
private:
    Stack<T> fStack;

public:
    // the iterator copies the stack and destroys the copy while traversing thru elems.
    StackIterator( const Stack<T>& aStack ) :
        fStack(aStack)
    {}

    const T& operator*() const
    {
        return fStack.top();
    }

    StackIterator& operator++()
    {
        fStack.pop();

        return *this;
    }

    StackIterator operator++(int)
    {
        StackIterator temp = *this;

        ++(*this);

        return temp;
    }
    // have the same numb of elements in underlying stack. 
    bool operator==( const StackIterator& aOtherIter ) const
    {
        return fStack.size() == aOtherIter.fStack.size();
    }

    bool operator!=( const StackIterator& aOtherIter ) const
    {
        return !(*this == aOtherIter);
    }

    StackIterator end() const
    {
        return StackIterator( Stack<T>() );
    }
};

template<typename T>
StackIterator<T> Stack<T>::begin() const
{
    return StackIterator<T>( *this );
}

template<typename T>
StackIterator<T> Stack<T>::end() const
{
    return begin().end();
}
