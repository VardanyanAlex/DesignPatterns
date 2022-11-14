
#ifndef _DESIGN_PATTERNS_FACTORY_HPP
#define _DESIGN_PATTERNS_FACTORY_HPP

#include <string>

#include "animal.h"

namespace DesignPatterns
{

class CFactory
{
public:
    Animal_UPtr CreateAnimal(std::string const& sName, std::string const& sType) const;

    static CFactory& Instance();

private:
    CFactory() =default;

};

} // namespace DesignPatterns

#endif // _DESIGN_PATTERNS_FACTORY_HPP
