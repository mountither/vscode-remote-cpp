#include "ofstream12.h"

#include <iostream>

using namespace std;

// initialise the data members.
void ofstream12::init()
{
    for(size_t i = 0; i < fBufferSize; i++)
    {
        fBuffer[i] = 0;
    }
    fByteIndex = 0;
    fBitIndex = 7; // first bit val in byte


}

void ofstream12::writeBit0()
{
    completeWriteBit();    
}

// write 1 (p.11)
void ofstream12::writeBit1()
{
    // set bit at fBitIndex in fBuffer
    fBuffer[fBitIndex] += 1 << fBitIndex;
    completeWriteBit();
}


// the complete write
void ofstream12::completeWriteBit()
{
    // little endian
    fBitIndex--;

    // check if fBitIndex is less than zero

    if(fBitIndex < 0)
    {
        fByteIndex++;
        fBitIndex = 7;

        if(fByteIndex == fBufferSize)
        {
            flush();
        }
    }
    
}

ofstream12::ofstream12(const char *aFileName, size_t aBufferSize)
{
    fBufferSize = aBufferSize;
    fBuffer = new byte[fBufferSize];

    init(); 
    open(aFileName);

}

ofstream12::~ofstream12()
{
    // close file and delete buffer array (byte)
    close();
    delete [] fBuffer;
}

void ofstream12::close()
{
    flush(); // flush every pending output
    fOStream.close();
}


void ofstream12::open(const char *aFileName)
{
    if(aFileName)
    {
        fOStream.open(aFileName, ofstream::binary);
    }
}

bool ofstream12::good() const
{
    return fOStream.good();
}

bool ofstream12::isOpen() const
{
    return fOStream.is_open();
}

void ofstream12::flush()
{
    // flush writes any pending output fto the underlying output stream
    fOStream.write((char*)fBuffer, fByteIndex + (fBitIndex % 7 ? 1 : 0));
}

ofstream12& ofstream12::operator<<(size_t aValue)
{
    for (size_t i = 0; i < 12; i++)
    {
        // 0x01 = 2^0 => 00000001
        // 0x08 = 2^3 => 00001000
        // 0x80 = 10000000
        // bit masking 
        // left position and right position
        if(aValue & 0x01)
        {
            writeBit1();
        }
        else
        {
            writeBit0();
        }

        aValue >>=1;
    }

    return *this;
    
}