
#include "car.h"

namespace Design_Patterns
{

CCar::CCar(std::string const& sColor)
    : m_sColor{ sColor }
{
}

CCar::CCar(CCar const& oRHS)
    : m_sColor{ oRHS.m_sColor }
{
}

void CCar::SetColor(std::string const& sColor)
{
    m_sColor = sColor;
}

std::string CCar::GetColor() const
{
    return m_sColor;
}

} // namespace Design_Patterns
