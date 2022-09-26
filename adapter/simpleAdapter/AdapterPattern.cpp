
#include "AdapterPattern.h"

#include <cmath>
#include <iostream>

namespace DesignPatterns
{ 

CRoundHall::CRoundHall(double fRadius)
    : m_fRadius{ fRadius }
{}

double CRoundHall::getRadius() const
{
    return m_fRadius;
}

bool CRoundHall::fit(CRoundPeg const* pPeg) const
{
    return pPeg->getRadius() <= m_fRadius;
}

CRoundPeg::CRoundPeg(double nRadius)
    : m_fRadius{nRadius}
{}

double CRoundPeg::getRadius() const
{
    return m_fRadius;
}

CSquarePeg::CSquarePeg(double fWidth, double fLength)
    : m_fWidth{ fWidth },
    m_fLength{ fLength }
{}

double CSquarePeg::getSquareArea() const
{
    return m_fWidth * m_fLength;
}

double CSquarePeg::getWidth() const
{
    return m_fWidth;
}

double CSquarePeg::getLength() const
{
    return m_fLength;
}

CSquarePegToRoundPegAdapter::CSquarePegToRoundPegAdapter(double nWidth, double nLength)
    : CRoundPeg{}
{
    m_pSquarePeg = new CSquarePeg{nWidth, nLength};
}

CSquarePegToRoundPegAdapter::~CSquarePegToRoundPegAdapter()
{
    delete m_pSquarePeg;
}

double CSquarePegToRoundPegAdapter::getRadius() const
{
    double fWidth = m_pSquarePeg->getWidth();
    double fLength = m_pSquarePeg->getLength();

    return sqrt(fWidth * fWidth + fLength * fLength) / 2;
}

} // namespace DesignPatterns
