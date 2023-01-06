
#include <iostream>

#include "repairservicevisitor.h"

namespace Design_Patterns
{

void CRepairServiceVisitor::Visit(CMercedes*)
{
    std::cout << "transferring the mercedes to repair\n";
}

void CRepairServiceVisitor::Visit(CBmw*) 
{
    std::cout << "transferring the bmw to repair\n";
}

} // namespace Design_Patterns
