
#include <iostream>

using namespace std;


// these coordinates will initialised in main and mutated by other classes.
class Coordinates
{
    private:
        int fX;
        int fY;
    public:
        Coordinates(int aX, int aY)
        {
            fX = aX;
            fY = aY;
        }
        int getX(){
            return fX;
        }
        int getY(){
            return fY;
        }
        
        //possibly get/set location for future.
};