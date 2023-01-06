
#ifndef _DESIGN_PATTERNS_CARVISITOR_REPAIRSERVICE_HPP_
#define _DESIGN_PATTERNS_CARVISITOR_REPAIRSERVICE_HPP_

#include "carvisitor.h"

namespace Design_Patterns
{

class CRepairServiceVisitor : public CCarVisitor 
{
public:
    void Visit(CMercedes*) override;
    void Visit(CBmw*) override;

};

} // namespace Design_Patterns

#endif // _DESIGN_PATTERNS_CARVISITOR_REPAIRSERVICE_HPP_
