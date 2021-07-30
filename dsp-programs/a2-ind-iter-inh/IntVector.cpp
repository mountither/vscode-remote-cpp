#include "IntVector.h"

#include <iostream>

using namespace std;

IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
{
    fNumberOfElements = aNumberOfElements;
    fElements = new int[fNumberOfElements];

    for(size_t i = 0; i < fNumberOfElements; i++)
    {
        fElements[i] = aArrayOfIntegers[i];
    }
}

// must free memory. delte fElements
IntVector::~IntVector()
{
    delete [] fElements;
}

size_t IntVector::size() const
{
    return fNumberOfElements;
}

// a IntSorter is created and sent here. 
// the subtype of IntSorter is CocktailShakerSort (implements overriden methods)
void IntVector::sort(const IntSorter& aSorter)
{
    aSorter(*this);
}

// this method swaps two indices 
// checks whether they are within range
void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex )
{
    // the indexes must be within the fNumbElem number

    if((aSourceIndex >= size()) || (aTargetIndex >= size()))
    {
        throw out_of_range("illegal vector indices");
    }

    // swap operation, use temp variable 
    int lTempArr = fElements[aSourceIndex];
    fElements[aSourceIndex] = fElements[aTargetIndex];
    fElements[aTargetIndex] = lTempArr;
        
}

const int IntVector::operator[](size_t aIndex) const
{
    // throw error "Error: illegal vector indices"

    if(aIndex < size())
    {
        return fElements[aIndex];
    }

    throw out_of_range("illegal vector index");

}

// instantiate iterators here
IntVectorIterator IntVector::begin() const 
{
    return IntVectorIterator(*this);
}

IntVectorIterator IntVector::end() const 
{
    return IntVectorIterator(*this, size());
}
