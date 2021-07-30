
#include <iostream>


using namespace std;

double cube(double num)
{
    double res = num * num * num;
    return res;
}

int main() 
{
    double res = cube(3);
    cout << res << endl;
    return 0;
}