
#include <iostream>

using namespace std;


string getDayOfWeek(int dayNumber)
{
    string name;

    switch (dayNumber)
    {
    case 1:
        name = "Sunday";
        break;
    case 2:
        name = "Monday";
        break;
    case 3:
        name = "Tuesday";
        break;
    case 4:
        name = "Wednesday";
        break;
    case 5:
        name = "Thursday";
        break;
    case 6:
        name = "Friday";
        break;
    case 7:
        name = "Saturday";
        break;
    default:
        name = "invalid day number";
        break;
    }

    return name;
}


int main()
{
    int num;
    cout<< "enter day number" << endl;

    cin >> num;

    cout << "day name is: " << getDayOfWeek(num) << endl;


    return 0;

}