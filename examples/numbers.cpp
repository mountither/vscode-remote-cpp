
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{

    cout << 70 + 40 << endl;
    cout << 10 % 3 << endl;

    int num = 10;
    double dnum = 10.6;
    num++;
    dnum++;
    cout << dnum << endl;

    cout << "adding num and dbl: " << num + dnum << endl;

    cout <<"with nums "<< 10 / 3 << endl;
    cout <<"with dbls "<< 10.0 / 3.0 << endl;


    // math operations

    cout << "~~~ MATH OPER ~~~" << endl;
    int power = pow(3,3);
    cout << power << endl;

    cout << sqrt(40) << endl;

    cout << ceil(4.6) << endl;
    cout << floor(4.6) << endl;

    cout << fmin(300, 1) << endl;
        
    return 0;
}