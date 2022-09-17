
#include "StadiumBuilder.hpp"

int main()
{
    using namespace Design_Patterns;

    builder::CLuxuryStadiumBuilder oLuxStadBuilder;

    CDirector oBuilderDirector{&oLuxStadBuilder};

    CStadium oCampNou = oBuilderDirector.GetStadium();

    std::cout << oCampNou.GetTribuneSeatsCount() << std::endl;

}
