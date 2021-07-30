#include "CocktailShakerSort.h"
#include "IntVector.h"

#include <iostream>

using namespace std;

// the address of the IntVector is sent here. 
void CocktailShakerSort::operator()( IntVector& aContainer ) const 
{
    // declare intital and end index
    size_t lInitPos = 0;
    size_t lEndPos = aContainer.size();

    // while loop - check is in bounds (init < end).
    // this loop will halt if init pos is incr and end pos
    // decr to the point of overlap. 
    while (lInitPos < lEndPos)
    {

        // for loop - loop from left to right (bubble sort)
        for(size_t i = lInitPos; i < lEndPos - 1; i++)
        {
            if(aContainer[i] > aContainer[i+1])
            {
                aContainer.swap(i, i+1);
            }
        }
        // move the end index by one, since the Nth foward pass placed in
        // correct pos
        lEndPos--;

        // 2nd for loop start backward pass (right to left)
        for(size_t i = lEndPos; i > lInitPos; i--)
        {
            if(aContainer[i] < aContainer[i-1])
            {
                aContainer.swap(i, i-1);
            }
            
        }
        // increment the init position since the backward pass placed in
        // right position.
        lInitPos++;
    }

}