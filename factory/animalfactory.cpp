
#include <stdexcept>

#include "animal.h"
#include "animalfactory.h"

namespace DesignPatterns
{

Animal_UPtr CFactory::CreateAnimal(std::string const& sName, std::string const& sType) const
{
    Animal_UPtr pAnimal{nullptr};

    if( sType == "lion")
        pAnimal = std::move(std::make_unique<animal::CLion>(sName, sType));
    else if( sType == "giraffe")
        pAnimal = std::move(std::make_unique<animal::CGiraffe>(sName, sType));
    else
        throw std::invalid_argument{"\t\t\t\t INVALID input detected!\n\n"};

    return std::move(pAnimal);
}

CFactory& CFactory::Instance()
{
    static CFactory oFactory;
    return oFactory;
}

} // namespace DesignPatterns
