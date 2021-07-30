#pragma once

#include "SinglyLinkedList.h"

template <typename T>
class SinglyLinkedListIterator
{
private:
    
    using ListNode = SinglyLinkedList<T>;
    
    const ListNode& fList;
    const ListNode* fIndex;
    
public:
    
    using Iterator = SinglyLinkedListIterator<T>;
    // aList is passed as a reference
    // ref data mem must be init before const body.
    // when using the ref, the fIndex must have 
    // init it with the addr of aList.
    SinglyLinkedListIterator( const ListNode& aList ) :
        fList(aList),
        fIndex(&aList)
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
    // this changes. Since we have ref of fList
    // we must compare the addr.
    // the ref is an alias to the already existing
    // variable. compare addr is suffice.
    bool operator==( const Iterator& aRHS ) const
    {
        return
            &fList == &aRHS.fList &&
            fIndex == aRHS.fIndex;
    }
        
    bool operator!=( const Iterator& aRHS ) const
    {
        return !(*this == aRHS);
    }
    // diff is that the fList is addr.    
    Iterator begin()       // for-range feature
    {
        Iterator iter = *this;
            
        iter.fIndex = &iter.fList;
            
        return iter;
    }

    Iterator end()          // for-range feature
    {
        Iterator iter = *this;
            
        iter.fIndex = nullptr;
            
        return iter;
    }
};

