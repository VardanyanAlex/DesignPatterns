
#ifndef _DESIGN_PATTERNS_CAR_HPP_
#define _DESIGN_PATTERNS_CAR_HPP_

#include <string>

#include "carvisitor.h"

namespace Design_Patterns
{

class CCar
{
public:
    virtual ~CCar() =default;
    CCar(std::string const& sColor);
    CCar(CCar const&);

    void SetColor(std::string const&);
    std::string GetColor() const;

    virtual void Accept(CCarVisitor*) = 0;

protected:
    std::string m_sColor        = "grey";
    size_t m_nFuelPercentage    = 0;

};

} // namespace Design_Patterns

#endif // _DESIGN_PATTERNS_CAR_HPP_
