
#include <iostream>

#include "drawables.h"

namespace DesignPatterns
{

CRectangle::CRectangle(int x, int y)
    : m_x{ x }
    , m_y{ y }
{}

void CRectangle::Draw() const
{
    std::cout << "Was drawn rectangle with x = " << m_x << "(width) and y = " << m_y << "(height)" << std::endl;
}    

CLine::CLine(int x, int y)
    : m_x{ x }
    , m_y{ y }
{}

void CLine::Draw() const
{
    std::cout << "Was drawn line with coordinates (" << m_x << ";" << m_y << ") " << std::endl;
}

void CPicture::Draw() const
{
    for(auto const& oGraphicObject : m_aGraphicObjects)
    {
        oGraphicObject->Draw();
    }
}

void CPicture::Add(GraphicsPtr const& oGraphicObj)
{
    m_aGraphicObjects.push_back(oGraphicObj);
}

} // namespace DesignPatterns
