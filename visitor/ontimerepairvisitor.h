
#ifndef _DESIGN_PATTERNS_CARVISITOR_ONTIMEREPAIR_HPP_
#define _DESIGN_PATTERNS_CARVISITOR_ONTIMEREPAIR_HPP_

#include "carvisitor.h"

namespace Design_Patterns
{

class COnTimeCarRepairVisitor : public CCarVisitor 
{
public:
    void Visit(CMercedes*) override;
    void Visit(CBmw*) override;

};

} // namespace Design_Patterns

#endif // _DESIGN_PATTERNS_CARVISITOR_ONTIMEREPAIR_HPP_
