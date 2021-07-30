
#include <iostream>

using namespace std;


int main()
{
    int num1, num2;
    char operat;

    cout << "enter 1st num" << endl;
    cin >> num1;
      cout << "enter operator" << endl;
    cin >> operat;
    cout << "enter 2nd num" << endl;
    cin >> num2;

    int res;

    if(operat =='+'){
        res = num1 + num2;
    }
    else if(operat == '-'){
        res = num1 - num2;
    }
    else if(operat == '/'){
        res = num1/num2;
    }
    else if(operat == '*'){
        res = num1 - num2;
    }
    
    else {
        cout << "invalid operator" << endl;
    }

    cout << res<< endl;

    return 0;
    

}