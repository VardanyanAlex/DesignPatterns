
#include <iostream>

#include "bmw.h"
#include "ontimerepairvisitor.h"
#include "mercedes.h"

namespace Design_Patterns
{

void COnTimeCarRepairVisitor::Visit(CMercedes* pCar)
{
    // if(pCar != nullptr)
    //     pCar->SetColor("Orange");
    
    std::cout << "already started repairing your mercedes\n";
}

void COnTimeCarRepairVisitor::Visit(CBmw*) 
{
    std::cout << "already started repairing your bmw\n";
}

} // namespace Design_Patterns
