#include "coordinates.cpp"
#include <iostream>

using namespace std;

class VacuumEnv
{

    private:
        Coordinates fLocation;
        string fFloor[4][6];
    public:
        VacuumEnv(string aFloor[4][6], Coordinates aLocation){
            fLocation = aLocation;
            fFloor = aFloor;
        }

        int measurePerformance(){
            
        }

        void updateLocation(Coordinates aNewLocation){
            fLocation = aNewLocation;
        }

        Coordinates getVacuumLocation(){
            return fLocation;
        }

        string[][] getStatusAtLocation(){
            return fFloor[fLocation.getX()][fLocation.getY()];
        }

};