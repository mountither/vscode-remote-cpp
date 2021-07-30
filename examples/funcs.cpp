#include <iostream>

using namespace std;

void sayHi(string name, int age);

int main()
{
    string name;
    int age;
    cout<< "enter name: " << endl;
    getline(cin, name);

    cout<< "enter age: " << endl;
    cin >> age;
    
    sayHi(name, age);

    return 0;
}

void sayHi(string name, int age)
{

    cout << "hello " << name << " you are " << age <<  endl;


}