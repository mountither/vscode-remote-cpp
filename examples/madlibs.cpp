#include <iostream>

using namespace std;

int main()
{

    string name, age, feel;

    cout << "enter your name: " << endl;
    getline(cin, name);
    cout << "enter your age: " << endl;
    getline(cin, age);
    cout << "how do you feel? " << endl;
    getline(cin, feel);

    cout << "Hello "<< name << endl;
    cout << "you are " << age << endl;
    cout << "you are feeling "<<  feel << endl;

    return 0;
}