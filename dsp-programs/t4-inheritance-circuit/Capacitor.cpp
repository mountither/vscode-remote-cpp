#include "Capacitor.h"
#include <cmath>
#include <iostream>

using namespace std;


bool Capacitor::mustScale(double aValue) const
{
    return aValue < 1.0;
}

const double Capacitor::getMultiplier() const
{
    return 1000.0;
}

const string Capacitor::getMajorUnit() const
{
    return "F";
}

const string Capacitor::getMinorUnits() const
{
    return "Fmunp";
}

Capacitor::Capacitor(double aBaseValue) : ResistorBase(aBaseValue)
{}


double Capacitor::getReactance(double aFrequency) const
{
    // 1 / 2 Pi * f * c
    // Pi = 4.0 * atan( 1.0 )

    return 1/ (2.0 * 4.0 * atan(1.0) * aFrequency * getBaseValue());
}