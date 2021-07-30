
#include <iostream>


using namespace std;


class MovingObject{
    public: 
        void turnRight(){
            cout << "turning right"<< endl;
        }
        void turnLeft(){
            cout << "turning left"<< endl;
        }
        void goFoward(){
            cout << "going foward"<< endl;
        }
        void goBack(){
            cout << "going back"<< endl;
        }
};


class Plane: public MovingObject{

    public:
        void incAltitude(){
            cout << "Going up" << endl;
        }
        void descAltitude(){
            cout << "Going down" << endl;
        }

};

int main()
{
    MovingObject obj;

    obj.turnLeft();

    Plane plane01;
    plane01.incAltitude();

    return 0;
}