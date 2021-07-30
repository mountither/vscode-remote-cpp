#include "Point2DSet.h"

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool orderByCoordinates( const Point2D& aLeft, const Point2D& aRight )
{
    return aLeft < aRight;
}

bool orderByPolarAngle( const Point2D& aLHS, const Point2D& aRHS )
{
    //cout << aLHS.getX() << ' ' <<  aLHS.direction() << endl;
    if (aLHS.isCollinear(aRHS)) {
		return aLHS.magnitude() > aRHS.magnitude();
	}

    return aLHS.direction() < aRHS.direction();

}

void Point2DSet::add(const Point2D& aPoint)
{
    fPoints.push_back(aPoint);
}

void Point2DSet::add(Point2D&& aPoint)
{
    fPoints.push_back(std::move(aPoint));
}

void Point2DSet::removeLast()
{
    fPoints.pop_back();
}
// check for domain errors also. must have at least 3 elements. 
bool Point2DSet::doesNotTurnLeft( const Point2D& aPoint ) const
{
    if(size() < 2)
    {
        throw domain_error("vector must have at least 3 elements");
    }

    return fPoints[size() - 1].isClockwise(fPoints[size() - 2], aPoint);
}

void Point2DSet::populate( const std::string& aFileName )
{
    ifstream lInput(aFileName);
    int lNumberOfCoord = 0;

    if(lInput.good())
    {
        lInput >> lNumberOfCoord;

        for(int i = 0; i < lNumberOfCoord; i++)
        {
            Point2D lPntInstance;
            lInput >> lPntInstance;

            fPoints.push_back(lPntInstance);
        }

        lInput.close();
    }
}

void Point2DSet::buildConvexHull( Point2DSet& aConvexHull )
{
    // implement the scan here. a Point2DSet aconvexhall obj to be used
    // operation Top, next to top, pop, push used here
    // when finished with func. aconvex will have consist of the convex hall

    sort(orderByCoordinates);

    Point2D lTop = fPoints[0];

    for(int i = 0; i< size(); i++)
    {
        fPoints[i].setOrigin(lTop);
    }

    sort(orderByPolarAngle);

    aConvexHull.add(lTop);
    aConvexHull.add(fPoints[1]);
    aConvexHull.add(fPoints[2]);

    if(size() < 3)
    {
        return;
    }

    for(int i = 3; i < size(); i++)
    {
        while(aConvexHull.doesNotTurnLeft(fPoints[i]))
        {
            aConvexHull.removeLast();
        }
        aConvexHull.add(fPoints[i]);
    }

}

size_t Point2DSet::size() const
{
    return fPoints.size();
}

void Point2DSet::clear()
{
    fPoints.clear();
}

const Point2D& Point2DSet::operator[]( size_t aIndex ) const
{
    if(aIndex < size())
    {
        return fPoints[aIndex];
    }
    throw out_of_range("Index out of Range");
}

void Point2DSet::sort( Comparator aComparator )
{
    stable_sort(fPoints.begin(), fPoints.end(), aComparator);
}

Point2DSet::Iterator Point2DSet::begin() const
{
    return Iterator(fPoints.begin());
}

Point2DSet::Iterator Point2DSet::end() const
{
    return Iterator(fPoints.end());
}
