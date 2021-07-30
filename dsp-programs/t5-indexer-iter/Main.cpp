
// COS30008, Tutorial 5, 2021

#include <iostream>

#define P1
#define P2
#define P3

#include "EasterEgg.h"

using namespace std;

int main( int argc, char* argv[] )
{
    string lFN = "dsp-programs/t5-indexer-iter/easteregg.data";

    if ( lFN == "")
    {
        cerr << "Arguments missing." << endl;
        cerr << "Usage: EasterEgg <filename>" << endl;
        
        return 1;
    }

        
#ifdef P1

    EasterEgg lEgg;
    
    if ( !lEgg.load( lFN ) )      
    {
        cerr << "Cannot load data file " << lFN << endl;
        
        return 2;
    }
    
    cout << "Data loaded." << endl;
    
#endif
    
#ifdef P2
    
    cout << "Using basic indexer: " << endl;
    
    for ( size_t i = 0; i < lEgg.size(); i++ )
    {
        cout << static_cast<char>(lEgg[i].fDatum);
    }

    cout << endl;

#endif

#ifdef P3
    
    cout << "Using iterator with mapping logic: " << endl;

    // loops through each value (asci code) in container. 
    // declaration => val 
    // expression => lEgg 
    for ( const unsigned int& val : lEgg )
    {
        cout << static_cast<char>(val);
    }

    cout << endl;

#endif
    
    return 0;
}
