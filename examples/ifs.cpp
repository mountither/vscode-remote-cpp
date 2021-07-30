#include <iostream>


using namespace std;

int main()
{

    bool male = true;
    

    cout<< "are you male? "<< endl;

    cin >> male;
    
    if(male){
        cout << "you are male" << endl;
    }else{
        cout << "you are not male" << endl;
    }

    return 0;
}