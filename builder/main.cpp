
#include "StadiumBuilder.hpp"

int main()
{
    using namespace Design_Patterns;

    builder::CStadiumBuilder* pLuxStadBuilder = new builder::CLuxuryStadiumBuilder;

    CDirector oBuilderDirector;
    oBuilderDirector.SetBuilder(pLuxStadBuilder);

    oBuilderDirector.Create(CStadium::EProperty::Seats);
    
    CStadium* oCampNou = oBuilderDirector.GetStadium();
    
    std::cout << oCampNou->GetTribuneSeatsCount() << std::endl;

}
