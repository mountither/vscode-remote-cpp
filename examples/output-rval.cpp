
#include <iostream>

using namespace std;

int lRval = 100;

// When the & operator is used in a declaration form, preceded by a type it 
// doesn't mean "the address of" but a "reference to" which is essentially an 
// automatically dereferenced pointer with disabled pointer arithmetic.
int& test() {
    return lRval;
}
int main() {

    double x = 10;

    // test() is specifing the right values (5). the return type is int& (automatically reference the given value.)
    test() = 5;

    cout << test() << endl;

    cout << "r val = " << lRval << endl;

    return 0;
}