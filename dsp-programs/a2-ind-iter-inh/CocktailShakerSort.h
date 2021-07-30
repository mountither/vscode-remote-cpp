
#pragma once

#include "IntSorter.h"

// inherits from IntSorter class 
class CocktailShakerSort : public IntSorter
{
public:

    void operator()( IntVector& aContainer ) const override;
};
