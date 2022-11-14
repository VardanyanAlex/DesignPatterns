
#ifndef _DESIGN_PATTERNS_COMPOSITE_IGRAPHIC_HPP_
#define _DESIGN_PATTERNS_COMPOSITE_IGRAPHIC_HPP_

#include <memory>

namespace DesignPatterns
{

class IGraphic
{
public:
    virtual void Draw() const = 0;

};

using GraphicsPtr = std::shared_ptr<IGraphic>;

} // namespace DesignPatterns

#endif // _DESIGN_PATTERNS_COMPOSITE_IGRAPHIC_HPP_
