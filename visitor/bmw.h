
#ifndef _DESIGN_PATTERNS_CAR_BMW_HPP_
#define _DESIGN_PATTERNS_CAR_BMW_HPP_

#include <string>

#include "car.h"

namespace Design_Patterns
{

class CBmw : public CCar
{
public:
    CBmw(std::string const& sColor);
    CBmw(CBmw const&);

    void Accept(CCarVisitor*) override;
};

} // namespace Design_Patterns

#endif // _DESIGN_PATTERNS_CAR_BMW_HPP_
