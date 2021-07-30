#include "coordinates.cpp"

#include <iostream>

using namespace std;

// purpose of class: the agent perceives the environment (location and status). AKA Percepts
// the status and location arrives here and other classes can get the location/status (using methods)
// further, a set of VacuumCurrent instances will be pushed onto a List (Array? LinkedList?)  

class VacuumCurrent
{
    private:
        string fStatus;
        Coordinates fLocation;

    public:
        VacuumCurrent(Coordinates aLocation, string aStatus)
        {
            fLocation = aLocation;
            fStatus = aStatus;
        }
        Coordinates getLocation(){
            return fLocation; 
        };
        string getStatus(){
            return fStatus;
        };

};