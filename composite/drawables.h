
#ifndef _DESIGN_PATTERNS_COMPOSITE_DRAWABLES_HPP_
#define _DESIGN_PATTERNS_COMPOSITE_DRAWABLES_HPP_

#include <memory>
#include <vector>

#include "graphic.h"

namespace DesignPatterns
{

class CRectangle : public IGraphic
{
public:
    explicit CRectangle(int x, int y);

    void Draw() const override;

private:
    int m_x{};
    int m_y{};
};

class CLine : public IGraphic
{
public:
    explicit CLine(int x, int y);

    void Draw() const override;

private:
    int m_x{};
    int m_y{};
};

class CPicture : public IGraphic
{
public:
    CPicture() =default;

    void Draw() const override;

    void Add(GraphicsPtr const&);

private:
    std::vector<GraphicsPtr> m_aGraphicObjects;
};
using PicturePtr = std::shared_ptr<CPicture>;

} // namespace DesignPatterns

#endif // _DESIGN_PATTERNS_COMPOSITE_DRAWABLES_HPP_
