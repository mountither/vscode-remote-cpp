/*

   Convex Hull, COS30008, 2021

*/

#include "Point2DSet.h"

#include <iostream>
#include <cmath>

//#define TestVector2D
//#define TestPoint2D
#define TestPoint2DSet

using namespace std;

int main()
{
    #ifdef TestVector2D
    Vector2D lVect;
    cout << "Enter dim " << endl;
    cin >> lVect;

    // second vect
    Vector2D lVect2;
    lVect2.setX(2);
    lVect2.setY(3);

    // test the magnitude and direction of this vector
    cout << "magnitude of this vect: " << lVect.magnitude() << endl;
    cout << "direction of this vect: " << lVect.direction() << endl;

    
    //test the addition and subtraction of two vectors
    cout << "addition of vectors (x,y): (" << (lVect + lVect2).getX() << ',' <<
    (lVect + lVect2).getY() << ')' << endl;
    cout << "subtraction of vectors (x,y): (" << (lVect - lVect2).getX() << ',' <<
    (lVect - lVect2).getY() << ')' <<  endl;

    // test dot product
    cout << "dot prod of 2 vects: " << lVect.dot(lVect2) << endl;
    // test cross product
    cout << "cross prod of 2 vects: " << lVect.cross(lVect2) << endl;

    // test angle between two vectors
    cout << "angle between 2 vects: " << lVect.angleBetween(lVect2) << endl;

    #endif

    #ifdef TestPoint2D

    Point2D lOrg = Point2D("p00", 5, 3);
    Point2D lPnt = Point2D("p01", 3, 2);
    Point2D lPnt2 = Point2D("p02", 4, 6);
    lPnt.setOrigin(lOrg);

    cout << "Enter dims for pnt3" << endl;


    // Point2D lPnt3 = Point2D(cin);

    // cout << lPnt3 << endl;

    cout << lPnt.isClockwise(lOrg,lPnt2) << endl;

    if(lPnt.isClockwise(lOrg,lPnt2))
    {
        cout << "is clockwise" << endl;
    }
    else{
        cout << "not clockwise" << endl;
    }

    cout << lPnt.isCollinear(lPnt2) << endl;

    if(lPnt.isCollinear(lPnt2))
    {
        cout << "is co linear" << endl;
    }
    else{
        cout << "not co linear" << endl;
    }

    // bool lCheckSizeCoord = lPnt < lPnt2;
    // cout << lCheckSizeCoord << endl;

    #endif

    #ifdef TestPoint2DSet
    Point2DSet lSet;

    lSet.populate( "dsp-programs/mid-term-program/points.txt" );


    cout << "Points:" << endl;

    for ( const Point2D& p : lSet )
    {
        cout << p << endl;
    }

    Point2DSet lConvexHull;

    lSet.buildConvexHull( lConvexHull );

    cout << "Convex hull:" << endl;

    size_t lSize = lConvexHull.size();

    for ( size_t i = 0; i < lSize; i++ )
    {
        cout
            << lConvexHull[i].getId()
            << " - "
            << lConvexHull[(i + 1) % lSize].getId() << endl;
    }

    #endif
    
    return 0;
}
