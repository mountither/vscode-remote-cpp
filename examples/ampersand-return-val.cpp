
#include <iostream>

using namespace std;

// this computes the given x and stores the first arg into res
// the ampersand is reference to the res variable in memory addr.
// this is why when used in main the mutated value is returned. 
void power2 (double& res, double x) {
    res = x * x;
}

// this returns the reference.
double& add (double& x) {
    return ++x;
}


int main(){


    double res = 0;

    power2(res, 3);

    cout << res << endl;

    res = 0;
    
    cout << ++add(res) << endl;

    return 0;
}