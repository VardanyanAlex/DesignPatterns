
#include "bmw.h"

namespace Design_Patterns
{

CBmw::CBmw(std::string const& sColor)
    : CCar(sColor)
{}

CBmw::CBmw(CBmw const& oRHS)
    : CCar( oRHS.m_sColor )
{}

void CBmw::Accept(CCarVisitor* pVisitor) 
{
    pVisitor->Visit(this);
}

} // namespace Design_Patterns
