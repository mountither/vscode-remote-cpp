#include "Point2D.h"

#include <iostream>
#include <cmath>

using namespace std;


static const Point2D gCoordinateOrigin;

// current point to the target point
double Point2D::directionTo(const Point2D& aOther ) const
{
    // dir between fPosition (Vector2D) and aOther (Point2D)

    Vector2D lDirVect =  *this - aOther;

    return lDirVect.direction();

}
double Point2D::magnitudeTo(const Point2D& aOther ) const
{
    Vector2D lMagVect =  *this - aOther;
    return lMagVect.magnitude();

}

Point2D::Point2D()
{
    fId = "";
    fPosition.setX(0);
    fPosition.setY(0);

    fOrigin = &gCoordinateOrigin;
}

Point2D::Point2D(const std::string& aId, double aX, double aY)
{
    fId = aId;
    fPosition.setX(aX);
    fPosition.setY(aY);

    fOrigin = &gCoordinateOrigin;
}


Point2D::Point2D( std::istream& aIStream )
{
    string lId;
    int lX, lY;
    aIStream >> lId >> lX >> lY;

    fId = lId;
    fPosition.setX(lX);
    fPosition.setY(lY);

    fOrigin = &gCoordinateOrigin;
}

const string& Point2D::getId() const
{
    return fId;
}

void Point2D::setX(const double& aX)
{
    fPosition.setX(aX);
}

void Point2D::setY(const double& aY)
{
    fPosition.setY(aY);
}

const double Point2D::getX() const
{
    return fPosition.getX();
}

const double Point2D::getY() const
{
    return fPosition.getY();
}

void Point2D::setOrigin( const Point2D& aPoint )
{
    fOrigin = &aPoint;
}

const Point2D& Point2D::getOrigin() const
{
    return *fOrigin;
}

Vector2D Point2D::operator-(const Point2D& aRHS ) const
{
    Vector2D lNewVect;
    lNewVect.setX(getX() - aRHS.getX());
    lNewVect.setY(getY() - aRHS.getY());

    return lNewVect;    
}

double Point2D::direction() const
{
    return directionTo(*fOrigin);
}

double Point2D::magnitude() const
{
    return magnitudeTo(*fOrigin);
}

bool Point2D::isCollinear(const Point2D& aOther ) const
{
    // fPostion relative to [0,0]
    return fPosition.cross(aOther.fPosition) == 0;
}

bool Point2D::isClockwise(const Point2D& aP0, const Point2D& aP2) const
{
    // p1 -> this
    // (p2 –p0)x(p1 –p0)=(x2 –x0)(y1 –y0)–(x1 –x0)(y2 –y0)

    //p0p2.cross(p0p1)

    Vector2D lP0P2 = aP2 - aP0;
    Vector2D lP0P1 = *this - aP0;

    double lCrossProd = lP0P2.cross(lP0P1);

    return lCrossProd > 0;

}

bool Point2D::operator<(const Point2D& aRHS) const
{
    if(getY() == aRHS.getY())
    {
        return getX() < aRHS.getX();
    }
    return getY() < aRHS.getY();
}

std::ostream& operator<<( std::ostream& aOutStream, const Point2D& aObject )
{
    aOutStream << aObject.getId() << ": (" << aObject.getX() << ',' <<  aObject.getY() << ')';

    return aOutStream;
}
std::istream& operator>>( std::istream& aInStream, Point2D& aObject )
{
    string lId;
    double lX, lY;

    aInStream >> lId >> lX >> lY;

    aObject.fId = lId;
    aObject.setX(lX);
    aObject.setY(lY);

    return aInStream;
}