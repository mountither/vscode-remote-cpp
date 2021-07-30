#include <iostream>

#pragma once

#include "SinglyLinkedList.h"
using namespace std;

template <typename T>
class SinglyLinkedListIterator
{
private:
    
    using ListNode = SinglyLinkedList<T>;
    
    const ListNode* fList;
    const ListNode* fIndex;
    
public:
    
    using Iterator = SinglyLinkedListIterator<T>;
    // pointer is passed in here. 
    // aList is variable that holds the mem addr
    // of another var addr (&One)
    // that points to that variable addr (&One)
    // to access that addr we must use *. 
    SinglyLinkedListIterator( const ListNode* aList ) :
        fList(aList),
        fIndex(aList)
    {}
    
    const T& operator*() const
    {
        return fIndex->fData;
    }

    Iterator& operator++()     // prefix
    {
        fIndex = fIndex->fNext;
        
        return *this;
    }
    
    Iterator operator++(int)   // postfix
    {
        Iterator old = *this;
        
        ++(*this);
        
        return old;
    }
    
    bool operator==( const Iterator& aRHS ) const
    {
        // fList holds the memory address.
        // cout << fList << endl;
        // dereferneces and accesses fData.
        // cout << fList->fData << endl;
        
        return
            fList == aRHS.fList &&
            fIndex == aRHS.fIndex;
    }
    
    bool operator!=( const Iterator& aRHS ) const
    {
        return !(*this == aRHS);
    }
    
    Iterator begin()       // for-range feature
    {
        Iterator iter = *this;
        
        iter.fIndex = iter.fList;
        
        return iter;
    }

    Iterator end()          // for-range feature
    {
        Iterator iter = *this;
        
        iter.fIndex = nullptr;
        
        return iter;
    }
};
