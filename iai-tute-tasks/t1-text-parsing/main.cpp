#include "route.cpp"

#include<iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>

using namespace std;

int convert_str_to_int(const string& str) {
    // cout << str << endl;
    // int val;
    // stringstream intValue(str);
    // // intValue << str;
    // intValue >> val;
    // cout << val << endl;

    // return val;
    return stoi(str);
}

int main(){

    string line;
    // ifstream inFile;

    ifstream inFile("iai-tute-tasks/t1-text-parsing/text.txt");

    if (!inFile.good()) {
        cerr << "cannot open input file" << endl;
        return 2;
    }

    if (inFile.is_open())
	{
        while(getline(inFile, line))
        {

            // cout << line << endl;
            stringstream linestream(line);
            string departure, arrival, actualDistance, straightDistance;
            string x;
            // getline(linestream, departure, ' ');
            // getline(linestream, arrival, ' ');
            // getline(linestream, actualDistance, ' ');
            // getline(linestream, straightDistance, ' ');

            linestream >> departure >> arrival >> actualDistance >> straightDistance;

            int iActual = convert_str_to_int(actualDistance);
            int iStraight = convert_str_to_int(straightDistance);

            Route route(departure, arrival, iActual , iStraight);

            cout << route;
        }   

        inFile.close();
    }
    else{
        cout << "error opening file";
    }

    return 0;
}