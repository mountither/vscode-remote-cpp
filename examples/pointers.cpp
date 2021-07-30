
#include <iostream>

using namespace std;


int main()
{
    int* ptr;
    // variables are stored in memory with unique addr.
    int age = 25;
    
    // the pointer int (ptr) is now pointing to the age address. 
    ptr = &age;
    // * is dereferenced now (value is returned)
    cout << *ptr << endl;
    // an int pointer to age value (above).
    int* pAge = &age;

    // a direct ref to age int
    int&& age01 = 10;
    cout<< age01<< endl;
    
    double gpa = 4;
    double *pGpa = &gpa;

    string name = "monti";
    string *pName = &name;
    // printing out addr of age variable
    // the output is a pointer. 
    cout <<"Pointer address to age: "<< pAge << endl;

    // derefrencing pointers (getting the stored val)
    cout << "Derefencing the pointer address: " << *pAge << endl;
    cout << "Directly deref. the pointer address of 'age': " << *&age << endl;

    // differnece between pointer and reference:
    // pointer has the freedom to move around and point to different variables
    // a ref is assigned once and is used to refer that address in memory. 
    return 0;
}