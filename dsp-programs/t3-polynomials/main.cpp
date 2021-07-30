
#include "Polynomial.h"

#include <iostream>

using namespace std;

Polynomial::Polynomial()
{
    fDegree = 0;

    // The coeffecients given 
    for(int i=0; i < MAX_DEGREE + 1; i++){
        fCoeffs[i] = 0.0;
    }

};

Polynomial Polynomial::operator* (const Polynomial& aRHS) const 
{
    // storing the outcome as Polynomial type.
    Polynomial lAnswer;
    // adding both LHS and RHS inputted degrees. 
    lAnswer.fDegree = fDegree + aRHS.fDegree;

    // loop through lhs degree(i) input and then rhs degree(j). 
    // example: (-0.25x^1 + 4x^0)*(-0.25x^1 + 4x^0) 
    // the first loop of LHS (-0.25x^1 - i0) will multiply with RHS (-0.25x^1 - j0 and 4x^0 - j1)
    for(int i=0; i <= fDegree; i++){
        for(int j=0; j <= aRHS.fDegree; j++){
            //lAnswer.fCoeffs[i+j] = lAnswer.fCoeffs[i+j] + fCoeffs[i] * aRHS.fCoeffs[j]
            // (-0.25x^1 + 4x^0)*(-0.25x^1 + 4x^0) 
            // iter 1 : lAnswer.fCoeffs[0] += -0.25(i0) * -0.25(j0)
            // iter2 :  lAnswer.fCoeffs[1] += -0.25(i0) * 4(j1)
            // iter3 :  lAnswer.fCoeffs[1] += 4(i1) * -0.25(j0)
            // iter4 :  lAnswer.fCoeffs[2] += 4(i1) * 4(j1)
            // Coeffs => [0.0625, 2, ...]
            // the += is important in summing like terms. 
            lAnswer.fCoeffs[i+j] += fCoeffs[i] * aRHS.fCoeffs[j];
            // cout << lAnswer.fCoeffs[i+j] << "[" << i << "]" << "[" << j << "]" << endl;

            // iterations [0][1]and[1][0] will merge, since they are like terms.
        }
    }    
    return lAnswer;
}

ostream& operator<<(ostream& aOstream,  const Polynomial& aObject)
{
    // output the result here (the pn object will the argument)
    // example A = -0.25x^1 * 4x^0
    // A = aObject.Coeff[0..N] "x^" aObject.fDegree [-1] * ... (loop thru)
    bool lPrintAddSymb = false;

    for(int i=aObject.fDegree; i >= 0; i--){
        if( aObject.fCoeffs[i] != 0.0){

            //this condition will only be true if inside the loop. 
            // the first (since init is false) and last (since the + sign is only put in front)
            if(lPrintAddSymb){
                aOstream << " + "; 
            }
            else{
                lPrintAddSymb = true;
            }

            aOstream << aObject.fCoeffs[i] << "x^" << i; 
        }

    }
    return aOstream;
};

istream& operator>>(istream& aIStream, Polynomial& aObject)
{
    // get the degree from the user  (1st input)
    int lDegreeInput;
    aIStream >> lDegreeInput;

    // check if lDegreeInput is zero or higher, else allocate it a zero.
    if(lDegreeInput >= 0){
        // the one line condition is used to filter. if lDegree is less than or equal to the 
        // assigned max_polys than assign it the max which in this case is 10 
        aObject.fDegree = lDegreeInput <= MAX_POLYNOMIAL ? lDegreeInput : MAX_POLYNOMIAL;
    }
    else{
        aObject.fDegree = 0;
    }

    // get the coeffecient from user. start with the coeff with highest degree and work down. 
    for (int i = aObject.fDegree; i >= 0; i--){
        // placing the user input coeffs in the array of doubles 
        aIStream >> aObject.fCoeffs[i];
    }

    return aIStream;
};

// this overloaded operator (method) checks whether 
bool Polynomial::operator==(const Polynomial& aRHS) const
{
    bool lEqualPoly = fDegree == aRHS.fDegree;

    for(int i = 0; lEqualPoly && i <=fDegree;i++){
        if(fCoeffs[i] != aRHS.fCoeffs[i]){
            lEqualPoly = false;
        }
    }

    return lEqualPoly;
}

int main()
{
    Polynomial A;
    cout << "enter the degree and then the coeffs " << endl;
    cin >> A;

    // mp, nothing is revealed here. checks if objects are structurely the same.
    Polynomial AA = A;

    if(AA == A){
        cout << "Comparison success" << endl;
    }
    else{
        cout << "Comparison failed" << endl;
    }
    cout << "A = " << A << endl;
    
    Polynomial B;
    cout << "enter second polynomial. " << endl;
    cin >> B;
    cout << "B = " << B << endl;

    Polynomial C = A * B;

    cout << "C = A * B = " << C << endl; 

    return 0;
}