
#include <iostream>

using namespace std;


int main()
{

    // cout << "Strings ";
    // cout << "HELLO" << endl;

    // cout << "Strings2 \n";
    // cout << "HELLO2" << endl;

    string word = "how are you?";
    word[2] = 'i';
    cout << word[2] << endl;

    cout << word.find("are", 2) << endl;

    cout << word.substr(4, 3) << endl;

    string subword;
    subword = word.substr(8, 3);
    cout << subword << endl;
    


    return 0;

}