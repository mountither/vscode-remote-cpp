#include "EasterEggIterator.h"
#include "EasterEgg.h"

#include <iostream>

using namespace std;

EasterEggIterator::EasterEggIterator(const EasterEgg& aContainer, size_t aStart)
:
fContainer(aContainer), fPosition(aStart), fValueIndex(0)
{

    advance();
}

// advance is called:
//      - in body of constructor
//      - prefix operator
//      - and begin method
// 
void EasterEggIterator::advance()
{
    // fPostion=738  fValueIndex=0
    // fPostion=667 fVal ueIndex=1

    // check if postion of iter is less than size of container
    if (fPosition < fContainer.size())
    {
        // make value index (key) in container equal the current pos of iter
        fValueIndex = fPosition;
        
        // loop through the container and check if index inside container 
        // equals the current iter position
        for(size_t i = 0; i < fContainer.size(); i++)
        {
            // fIndex => 738 and fPos => 738 
            // the value that corresponds to the index in container is 
            // eqauted 
            if(fContainer[i].fIndex == fPosition){
                fValueIndex = i;
                break;
            }

        }
    }
    else
    {
        fValueIndex = 0;
    }
}

const unsigned int& EasterEggIterator::operator*() const
{
    // this will return updated fValueIndex value. (ordered)
    return fContainer[fValueIndex].fDatum;
}
// prefix
EasterEggIterator& EasterEggIterator::operator++()  
{
    fPosition++;
    
    // call advance method?
    advance();

    return *this;
}

// postfix
EasterEggIterator EasterEggIterator::operator++( int )  
{
    EasterEggIterator lTempEEI = *this;

    // brackets will prioritise * over ++
    // 1st deref and then increment
    // prefix is used to avoid recurision.
    ++(*this);
    
    return lTempEEI;
}

bool EasterEggIterator::operator==( const EasterEggIterator& aRHS ) const
{
    // comparing addresses here
    return (&fContainer == &aRHS.fContainer ) &&
            (fPosition == aRHS.fPosition);
}


bool EasterEggIterator::operator!=( const EasterEggIterator& aRHS ) const
{
    return !(*this == aRHS);
}


EasterEggIterator EasterEggIterator::begin() const 
{
    EasterEggIterator lRefEEI = *this;
    lRefEEI.fPosition = 0;

    // advance method
    lRefEEI.advance();

    return lRefEEI;

}

EasterEggIterator EasterEggIterator::end() const
{
    EasterEggIterator lRefEEI = *this;
    lRefEEI.fPosition = lRefEEI.fContainer.size();
    
    return lRefEEI;
}