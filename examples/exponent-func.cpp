
#include <iostream>

using namespace std;



int power(int baseNum, int powNum)
{
    int res = 1;

    for(int i = 0; i < powNum; i++){
        res *= baseNum;
    }

    return res;
}


int main()
{
    int base;
    int pow;

    cout << "enter base: " << endl;
    cin >> base;
    cout << "enter power: " << endl;
    cin >> pow;

    cout << "result: " << power(base, pow) << endl;
    

    return 0;
}