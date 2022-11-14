
#include "ChainOfResponsibility.h"

int main()
{
    using namespace DesignPatterns;

    Doctor_Ptr pTheraphist{ new CTheraphist };
    Doctor_Ptr pEyeDoctor{ new CEyeDoctor };
    Doctor_Ptr pEarDoctor{ new CEarDoctor };

    pTheraphist->SetNext(pEarDoctor)->SetNext(pEyeDoctor);

    pTheraphist->Handle(ERequestType::Heart);
    pTheraphist->Handle(ERequestType::Ear);
    pTheraphist->Handle(ERequestType::OnlyCheckHealth);
    pTheraphist->Handle(ERequestType::Eye);

}
