
#include <iostream>

using namespace std;

struct Vector2 
{
    float x,y;

    Vector2(float x, float y)
        : x(x), y(y) {}

    // the ampersand is memory addr of other compared with this (current obj.)
    // the const after func - Add method will not modify the non-mutable
    // member of variables of Vector2 (other)
    Vector2 Add(const Vector2& other) const
    {
        // or 
        // return *this + other;
        // or (same as above)
        // return operator+(other);
        // or  
        return Vector2(x+other.x, y+other.y);
    }

    // this will call Add() func and allow the instances in main
    // to be used directly (added)
    Vector2 operator+(const Vector2& other) const
    {
        // or 
        // return Vector2(x+other.x, y+other.y);
        return Add(other);
    }

    Vector2 Multiply(const Vector2& other) const
    {
        return Vector2(x*other.x, y*other.y);
    }

    Vector2 operator*(const Vector2& other) const
    {
        // or 
        // return Vector2(x*other.x, y*other.y);
        return Multiply(other);
    }

    friend ostream& operator<<(ostream& stream, const Vector2& other)
    {
        // stream is 
        stream << other.x << "," << other.y;
        return stream;
    }
};

// ostream is the og operator ref. 
// ref the existing stream as parameter, which is 'cout'
// can be accessed on within class since cout is defined globally and Vector2 is passed.
// ostream& operator<<(ostream& stream, const Vector2& other)
// {
//     // stream is 
//     stream << other.x << "," << other.y;
//     return stream;
// }

int main()
{
    Vector2 postion(4.0f, 4.0f);
    Vector2 speed(0.5f, 0.5f);
    Vector2 powerup(1.1f, 1.1f);

    // this gets messy. this where operator OL is used. 
    Vector2 res = postion.Add(speed.Multiply(powerup));
    // cleaner
    Vector2 res2 = postion + speed * powerup;

    // in the case of left shift oper. for cout
    //      the below output will not work, bcs theres no OL
    //cout << res2 << endl;
    // with the operator overload <<
    cout << res2 << endl;

    return 0;
}