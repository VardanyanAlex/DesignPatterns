
#include <iostream>
#include <memory>

#include "bmw.h"
#include "mercedes.h"
#include "ontimerepairvisitor.h"
#include "repairservicevisitor.h"

int main()
{
    using namespace Design_Patterns;
 
    auto pMercedesCar = std::make_shared<CMercedes>("Black");

    std::unique_ptr<CCarVisitor> pOnTimeRepair(new COnTimeCarRepairVisitor);

    pMercedesCar->Accept(pOnTimeRepair.get());
    std::cout << pMercedesCar->GetColor() << "\n";

    auto pBmw = std::make_shared<CBmw>("Grey");

    std::unique_ptr<CCarVisitor> pRepair(new CRepairServiceVisitor);

    pBmw->Accept(pRepair.get());

    return 0;
}
