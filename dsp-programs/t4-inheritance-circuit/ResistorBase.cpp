#include "ResistorBase.h"

#include <iostream>

using namespace std;

ResistorBase::ResistorBase(double aBaseValue)
{
    setBaseValue(aBaseValue);
}

void ResistorBase::setBaseValue(double aBaseValue)
{
    // perform additional checks and scaling. 
    fBaseValue = aBaseValue;
}

double ResistorBase::getBaseValue() const
{
    return fBaseValue;
}

double ResistorBase::getPotentialAt(double aCurrent, double aFrequency) const
{
    // V = R * I
    return getReactance(aFrequency) * aCurrent; 
}

double ResistorBase::getCurrentAt(double aVoltage, double aFrequency) const
{
    // I = V / R
    return aVoltage/getReactance(aFrequency);
}

istream& operator>>( std::istream& aIStream, ResistorBase& aObject )
{
    double lRawValue;
    string lRawUnit;

    aIStream >> lRawValue >> lRawUnit;

    // checks 
    aObject.flatten(lRawValue, lRawUnit);

    return aIStream;

}

ostream& operator<<( std::ostream& aOStream, const ResistorBase& aObject )
{
    double lNormalisedValue;
    string lNormalisedUnit;

    aObject.normalize(lNormalisedValue, lNormalisedUnit);

    aOStream << lNormalisedValue << ' ' << lNormalisedUnit;

    return aOStream;
}