
#include "AdapterPattern.h"

#include <cmath>
#include <iostream>

namespace DesignPatterns
{ 

CRoundHall::CRoundHall(double nRadius)
    : m_nRadius{ nRadius }
{}

double CRoundHall::getRadius() const
{
    return m_nRadius;
}

bool CRoundHall::fit(CRoundPeg const* pPeg) const
{
    return pPeg->getRadius() <= m_nRadius;
}

CRoundPeg::CRoundPeg(double nRadius)
    : m_nRadius{nRadius}
{}

double CRoundPeg::getRadius() const
{
    return m_nRadius;
}

CSquarePeg::CSquarePeg(double nWidth, double nLength)
    : m_nWidth{ nWidth },
    m_nLength{ nLength }
{}

double CSquarePeg::getSquareArea() const
{
    return m_nWidth * m_nLength;
}

CSquarePegToRoundPegAdapter::CSquarePegToRoundPegAdapter(double nWidth, double nLength)
    : m_nWidth{ nWidth },
    m_nLength{ nLength }
{}

double CSquarePegToRoundPegAdapter::getRadius() const
{
    return sqrt(m_nWidth * m_nWidth + m_nLength * m_nLength) / 2;
}

} // namespace DesignPatterns
