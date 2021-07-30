#include "BernsteinBasePolynomial.h"

#include <cmath>
using namespace std;

// the constructor body is called after the compiler init the member variables.
// Combination.h lacks a default param values - user inputted values.
// other case: the parameterized constructor of the base class can only be called using Initializer List.
// refer to Initializer list and https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.2.0/com.ibm.zos.v2r2.cbclx01/cplr376.htm
BernsteinBasePolynomial::BernsteinBasePolynomial() : fFactor(0,0) 
{}

BernsteinBasePolynomial::BernsteinBasePolynomial(unsigned int aV, unsigned int aN):
fFactor(aN, aV)
{}


double BernsteinBasePolynomial::operator()(double aX) const 
{
    // unsigned long long lBinomCoeff = fFactor();
    // cout << lBinomCoeff << endl;
    // n over v * x^v * (1-x)^(n-v)
    // lBinomCoeff * aX ^ fFactor.getK() * (1 - aX)^(fFactor.getN() - fFactor.getK())

    return fFactor() * pow(aX, fFactor.getK()) * (pow((1-aX), (fFactor.getN() - fFactor.getK())));
}