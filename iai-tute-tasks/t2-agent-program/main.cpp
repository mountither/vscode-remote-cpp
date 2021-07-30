#include "coordinates.cpp"

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;



// string next(string location, string state){

//     string actions[6] = {"LEFT", "RIGHT", "UP", "DOWN", "SUCK", "NO-OP"};
//     int randInd = rand() % 6;

//     string action;
//     action = actions[randInd];
//     return action;

// };

int main()
{

    string lLine;
    ifstream lInFile("iai-tute-tasks/t2-agent-program/FLOOR_MAP.TXT");
    
    // srand(time(NULL)); //initialize the random seed
    
    int lUserInputX, lUserInputY;
    char lCommaSep;

    // get user input location 
    cout << "Enter Location [x, y]" << endl; 
    cin >> lUserInputX >> lCommaSep >> lUserInputY;
    // cout << lUserInputX << " " << lUserInputY << endl;
    Coordinates lInitLoc = Coordinates(lUserInputX, lUserInputY);

    cout <<"X input: " << lInitLoc.getY() << endl;

    int lMapWidth, lMapHeight;
    char lXSep;

    if (lInFile.is_open())
	{

        // get dimensions of floor map
        if (getline(lInFile, lLine)){
            stringstream mapDimensionStream(lLine);
            mapDimensionStream >> lMapWidth >> lXSep >> lMapHeight;
        }

        // check if user input is within bounds of map
        if((lUserInputX > lMapWidth || lUserInputX < 0) || (lUserInputY > lMapHeight || lUserInputY < 0))
        {
            cout << "Location given is out of bounds" << endl;
        }

        // get all status in floor map, looped through on the basis of map's height 

        // allocate an identity (room - [x,y]) for each status
        // example [[CLEAN, DIRTY, CLEAN, NIL],
        //          [CLEAN, CLEAN, CLEAN, CLEAN],]
        // each room will be identified by x and y coordinate. (2d array)
        // each coordinate pair is associated with a status.

        string lRoomStatus[lMapWidth][lMapHeight]; 

        for(int i = 0; i < lMapHeight; i++)
        {
            for(int j = 0; j < lMapWidth; j++)
            {
                // The return from getline() should be checked to make sure the read was valid
                if(getline(lInFile, lLine, ' ')){
                    lRoomStatus[j][i] = lLine;
                    // cout << lRoomStatus[j][i] << "[" <<j<<"]"<<"["<<i<<"]" << endl;
                }
            }
        }

        // check if user has input a non-existent room location (NIL)
        if(lRoomStatus[lUserInputX][lUserInputY] == "NIL"){

            cout << "Room does not exist"  << endl;
        }


        lInFile.close();
    } 
    else{
        cout << "error opening file";
    }

    // while(true){

    // cout << "Enter Location" << endl;
    // cin >> perceptLocation;
    // cout << "Enter State" << endl;
    // cin >> perceptState;
    // cout << "\n" << next(perceptLocation, perceptState) << "\n" << endl;
    // }

    return 0;
}