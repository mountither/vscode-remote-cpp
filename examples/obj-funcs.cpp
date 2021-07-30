
#include <iostream>


using namespace std;


class Person
{
    public:
        string name;
        string work;
        int age;

        Person(string AName, string AWork, int AAge){
            name = AName;
            work = AWork;
            age = AAge;
        };

        bool isAbove20(){
            if(age > 20){
                return true;
            }
            return false;
        }
};

int main()
{
        
    Person person01("mike", "chef", 40);
    Person person02("adam", "pilot", 50);

    cout << person01.isAbove20() << endl;


    return 0;

}