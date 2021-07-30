#include "Combination.h"

using namespace std;

Combination::Combination(unsigned int aN, unsigned int aK)
{
    fN = aN;
    fK = aK;
}

unsigned int Combination::getN() const
{
    return fN;
}

unsigned int Combination::getK() const
{
    return fK;
}

unsigned long long Combination::operator()() const
{
    // numerator - n!
    // denom = k! (n - k)!
    // example; n = 6 k =2 
    // (6 * 5 * 4 * 3 * 2 * 1) / 2 * 1 * {(6-2)! => 4 * 3 * 2 * 1} 
    unsigned long long lResult = 1;

    for(unsigned long long i = 1; i <= fK; i++)
    {
        // cout << '(' << fN << '-' << '(' << i << '-' << '1' << ')' << " = " << (fN - (i - 1));
        lResult *= (fN - (i - 1));
        // cout << "/" << i << endl;
        lResult /= i;
    }

    return lResult;
}