
#include "mercedes.h"

namespace Design_Patterns
{

CMercedes::CMercedes(std::string const& sColor)
    : CCar(sColor)
{}

CMercedes::CMercedes(CMercedes const& oRHS)
    : CCar( oRHS.m_sColor )
{}

void CMercedes::Accept(CCarVisitor* pVisitor) 
{
    pVisitor->Visit(this);
}

} // namespace Design_Patterns
