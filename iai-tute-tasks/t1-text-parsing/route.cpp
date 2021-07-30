
#include<iostream>

using namespace std;

// OUTPUT 
// "Travel from [city A] to [city B] 
//with a straight line distance of [S] and an actual distance of [D]"

class Route {

    public:
        string depart;
        string arrival;
        int actualDistance;
        int straightDistance;

        Route(string aDepart, string aArrival, int aActual, int aStraight){

            depart = aDepart;
            arrival = aArrival;
            actualDistance = aActual;
            straightDistance = aStraight;
        }

        friend ostream& operator<<(ostream& opStream, const Route& route)
        {
            if(route.actualDistance != -1){

            opStream << "Travel from "  << route.depart << " to " << route.arrival <<  
            " with a straight line distance of " << route.straightDistance << " and an actual distance of "
            << route.actualDistance << endl;
            }
            else{
                opStream << "Cannot drive from " << route.depart << " to city " << route.arrival <<
                ", however there is a straight line distance of " << route.straightDistance << endl; 
            }

            return opStream;
        }


};
