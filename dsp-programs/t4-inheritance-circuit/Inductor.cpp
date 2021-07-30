#include "Inductor.h"
#include <cmath>
#include <iostream>

using namespace std;


bool Inductor::mustScale(double aValue) const
{
    return aValue < 1.0;
}

const double Inductor::getMultiplier() const
{
    return 1000.0;
}

const string Inductor::getMajorUnit() const
{
    return "H";
}

const string Inductor::getMinorUnits() const
{
    return "Hmunp";
}

Inductor::Inductor(double aBaseValue) : ResistorBase(aBaseValue)
{}


double Inductor::getReactance(double aFrequency) const
{
    // 2 Pi * f * L = wL
    // Pi = 4.0 * atan( 1.0 )
    return (2.0 * 4.0 * atan(1.0) * aFrequency * getBaseValue());
}