
#ifndef _DESIGN_PATTERNS_CAR_MERCEDES_HPP_
#define _DESIGN_PATTERNS_CAR_MERCEDES_HPP_

#include <string>

#include "car.h"

namespace Design_Patterns
{

class CMercedes : public CCar
{
public:
    CMercedes(std::string const& sColor);
    CMercedes(CMercedes const&);

    void Accept(CCarVisitor*) override;
};

} // namespace Design_Patterns

#endif // _DESIGN_PATTERNS_CAR_MERCEDES_HPP_
