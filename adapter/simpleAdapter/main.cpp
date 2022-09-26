
#include "AdapterPattern.h"

#include <iostream>
#include <memory>

int main()
{
    using namespace DesignPatterns;
    CRoundHall oMyRoundHall{ 3 };

    std::shared_ptr<CRoundPeg> oSquarePeg{ new CSquarePegToRoundPegAdapter { 3, 4 } };

    std::cout << oMyRoundHall.fit(oSquarePeg.get());
}
