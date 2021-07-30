#include "Vector2D.h"

#include <iostream>

#include <cmath>

using namespace std;


Vector2D::Vector2D(double aX, double aY): fX(aX), fY(aY)
{}

void Vector2D::setX(double aX)
{
    fX = aX;
}

void Vector2D::setY(double aY)
{
    fY = aY;
}

double Vector2D::getX() const
{
    return fX;
}

double Vector2D::getY() const
{
    return fY;
}

Vector2D Vector2D::operator+(const Vector2D& aRHS ) const
{
    Vector2D lNewVect;
    lNewVect.setX(getX()+aRHS.getX());
    lNewVect.setY(getY()+aRHS.getY());

    return lNewVect;
}

Vector2D Vector2D::operator-(const Vector2D& aRHS ) const
{
    Vector2D lNewVect;
    lNewVect.setX(getX()-aRHS.getX());
    lNewVect.setY(getY()-aRHS.getY());

    return lNewVect;
}

double Vector2D::magnitude() const
{
    return sqrt(pow(getX(),2)+pow(getY(),2));
}
// return the angle
double Vector2D::direction() const
{
    return atan2(getY(),getX());
}

// ax × bx + ay × by
// for 2 vectors (vectA dot vectB = magnitude of A * B * cos the angl between them)
double Vector2D::dot(const Vector2D& aRHS) const
{
    return getX()*aRHS.getX()+getY()*aRHS.getY();
}
// x1*y2 - x2*y1
// if this is the left of aRHS, oreintation was flipped in 
double Vector2D::cross(const Vector2D& aRHS) const
{
    return getX()*aRHS.getY() - getY()*aRHS.getX();
}
// angle between 2 vectors = dot product / product of vector magnitude
double Vector2D::angleBetween(const Vector2D& aRHS) const
{
    // handle null vectors, return 90 degrees
    if(dot(aRHS) == 0)
    {
        return 1.5708;
    }

    return atan2(abs(cross(aRHS)),dot(aRHS));
}

std::ostream& operator<<( std::ostream& aOutStream, const Vector2D& aObject )
{
    aOutStream << '[' << aObject.getX() << ',' <<  aObject.getY() << ']';

    return aOutStream;
}
std::istream& operator>>( std::istream& aInStream, Vector2D& aObject )
{
    double lX, lY;

    aInStream >> lX >> lY;

    aObject.setX(lX);
    aObject.setY(lY);

    return aInStream;
}