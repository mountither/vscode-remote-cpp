#include "IntVectorIterator.h"
#include "IntVector.h"
#include <iostream>

using namespace std;


IntVectorIterator::IntVectorIterator(const IntVector& aContainer, size_t aStart)
: fContainer(aContainer), fPosition(aStart)
{}

// returns the current dereferenced  value in array.
const int IntVectorIterator::operator*() const
{
    return fContainer[fPosition];
}

// prefix
//should return the address of the current iter instance, after inc
IntVectorIterator& IntVectorIterator::operator++()
{
    fPosition++;
    return *this;
}
// returns a copy of instance, while inc the orig.
IntVectorIterator IntVectorIterator::operator++(int)
{
    IntVectorIterator lCopyInstance = *this;
    ++(*this);
    return lCopyInstance;
}

// checks for equality between two iterator instances.
bool IntVectorIterator::operator==( const IntVectorIterator& aRHS ) const
{
    return (fPosition == aRHS.fPosition) && (&aRHS.fContainer == &fContainer);
}

bool IntVectorIterator::operator!=( const IntVectorIterator& aRHS ) const
{
    return !(*this==aRHS);
}
// return the iterator at begining for the given loop
IntVectorIterator IntVectorIterator::begin() const
{
    IntVectorIterator lBeginInstance = *this;
    lBeginInstance.fPosition = 0;
    return lBeginInstance;
}

// returns the last iterator instance
IntVectorIterator IntVectorIterator::end() const
{
    IntVectorIterator lEndInstance = *this;
    lEndInstance.fPosition = lEndInstance.fContainer.size();
    return lEndInstance;
}