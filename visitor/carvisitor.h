
#ifndef _DESIGN_PATTERNS_CARVISITOR_HPP_
#define _DESIGN_PATTERNS_CARVISITOR_HPP_

namespace Design_Patterns
{

class CMercedes;
class CBmw;

class CCarVisitor
{
public:
    virtual void Visit(CMercedes*) = 0;
    virtual void Visit(CBmw*) = 0;

};

} // namespace Design_Patterns

#endif // _DESIGN_PATTERNS_CARVISITOR_HPP_
