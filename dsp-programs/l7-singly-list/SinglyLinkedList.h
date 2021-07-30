#include <iostream>

#pragma once
using namespace std;

#define prnt(x) cout << x << endl

template <typename DataType>

struct SinglyLinkedList
{
    DataType fData;
    SinglyLinkedList* fNext;
    
    SinglyLinkedList( const DataType& aData, SinglyLinkedList* aNext = nullptr ) :
        fData(aData),
        fNext(aNext)
    {}
    // the r-val param aData is given here. the aNext var is a pointer to the addr of the next variable.
    // To get value of next value, you must access fData from aNext. 
    SinglyLinkedList( DataType&& aData, SinglyLinkedList* aNext = nullptr ) :
        fData(std::move(aData)),
        fNext(aNext)
    {}
};
