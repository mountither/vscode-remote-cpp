
#include "Polynomial.h"
#include <cmath>

using namespace std;

double Polynomial::operator()(double ax) const 
{
    double lOutcome;
 
    for(int i = fDegree; i >= 0; i--)
    {
        lOutcome += fCoeffs[i] * pow(ax, i);
        // cout << fCoeffs[i] << "*" << ax << "^" << i << endl; 
    }
    return lOutcome;
}

Polynomial Polynomial::getDifferential() const
{
    // -0.25 x ^ 1 + 4 * x ^ 0
    // new degree = fDegree - 1
    // new Coeff = fDegree * -0.25
    Polynomial lNewDiff;

    if(fDegree == 0){
        return lNewDiff;
    }

    lNewDiff.fDegree = fDegree - 1;

    for (int i = fDegree; i > 0; i--)
    {
            lNewDiff.fCoeffs[i - 1] = i * fCoeffs[i];
            // cout << "new degree at " << i << " is " << lNewPoly.fDegree << endl;
            // cout << "new coeff at " << i << " is " << lNewPoly.fCoeffs[i - 1] << endl;
    }
    return lNewDiff;
}

Polynomial Polynomial::getIndefiniteIntegral() const 
{
    // -0.25 x ^ 1 + 4 * x ^ 0
    // new degree = fdgree + 1 (2)
    // new coeff = fCoeff (-0.25) / new degree; (-0.25/2 = -0.125)
    // + c ?
    
    Polynomial lNewIntegral;
    
    lNewIntegral.fDegree = fDegree + 1;

    for(int i = lNewIntegral.fDegree; i > 0; i--)
    {
        lNewIntegral.fCoeffs[i] = fCoeffs[i-1]/i;
        // cout << "new degree at " << i << " is " << lNewIntegral.fDegree << endl;
        // cout << "new coeff at " << i << " is " << lNewIntegral.fCoeffs[i + 1] << endl;
    }
    // + c
    lNewIntegral.fCoeffs[0] = 0;
    //e.g -0.125x^2 + 4x^1
    return lNewIntegral;
}

// computes the area under curve/line based on the x-low and x-high
double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const
{
    Polynomial lIdefiniteInteg = getIndefiniteIntegral(); 

    double lXlow = lIdefiniteInteg(aXLow);
    double lXhigh = lIdefiniteInteg(aXHigh);

    return lXhigh - lXlow;
}
