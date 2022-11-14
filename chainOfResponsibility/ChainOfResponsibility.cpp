
#include "ChainOfResponsibility.h"

#include <cassert>
#include <exception>
#include <iostream>

namespace DesignPatterns
{

///////////////////////////////////////////////////////////////////
// CDoctor impl
//////////////////////////////////
Doctor_Ptr& CDoctor::SetNext(Doctor_Ptr const& pDoctor)
{
    if (pDoctor == nullptr)
    {
        assert(pDoctor != nullptr);
        throw std::exception{};
    }

    m_pNextDoctor = pDoctor;

    return m_pNextDoctor;
}

void CDoctor::SendtoNextDoctor(ERequestType eRequest) const
{
    if (m_pNextDoctor != nullptr)
        m_pNextDoctor->Handle(eRequest);
    else
        std::cout << "Gotten request wasn't handled!\n";
}

///////////////////////////////////////////////////////////////////
// CTheraphist impl
//////////////////////////////////
void CTheraphist::Handle(ERequestType eRequest) const
{
    if (eRequest == ERequestType::OnlyCheckHealth)
        std::cout << "theraphist handled\n";
    else
        SendtoNextDoctor(eRequest);
}

///////////////////////////////////////////////////////////////////
// CEyeDoctor impl
//////////////////////////////////
void CEyeDoctor::Handle(ERequestType eRequest) const
{
    if (eRequest == ERequestType::Eye)
        std::cout << "The eye's doctor handled\n";
    else
        SendtoNextDoctor(eRequest);
}

///////////////////////////////////////////////////////////////////
// CEarDoctor impl
//////////////////////////////////
void CEarDoctor::Handle(ERequestType eRequest) const
{
    if (eRequest == ERequestType::Ear)
        std::cout << "The ear's doctor handled\n";
    else
        SendtoNextDoctor(eRequest);
}

} // namespace DesignPatterns
