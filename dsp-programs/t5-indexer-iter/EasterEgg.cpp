#include "EasterEgg.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;
 
EasterEgg::EasterEgg(): fSize(0), fData(nullptr)
{}

// a destructor (called by compiler) to free up space when done
// fData of type DataMap is deleted, Since the new Datamap was created on heap. 
EasterEgg::~EasterEgg()
{
    delete [] fData;
}

bool EasterEgg::load( const std::string& aFileName)
{
    ifstream lInput(aFileName);

    // insert the data in DataMap struct .fDatum
    if(lInput.good())
    {
        // first line - size of array
        lInput >> fSize;

        if(fSize)
        {
            fData = new DataMap[fSize];
        }
        
        for(size_t i = 0; i < fSize; i++)
        {
            // each line in file has a pair corresponding to ind (key) and datum (value).
            lInput >> fData[i].fIndex >> fData[i].fDatum;
            // >> seperates by whitespace. 

        }
        lInput.close();

        return true;
    }

    return false;
}


size_t EasterEgg::size() const
{
    return fSize;
}

// returns a reference to DataMap struct, rather than a copy. 
const DataMap& EasterEgg::operator[](size_t aIndex) const
{
    // check if the given index is less than the array size
    if(aIndex < fSize)
    {
        return fData[aIndex];
    }

    throw out_of_range("Index out of Range");
}

EasterEggIterator EasterEgg::begin() const
{
    // The current easteregg object/container pointer is sent
    // while the start ind is set to def in EEI constructor
    return EasterEggIterator(*this);
}

EasterEggIterator EasterEgg::end() const
{
    // the size of given array is sent here
    // the size() method will be associated with the current obj (assoc *this)
    return EasterEggIterator(*this, size());
}