
#include <iostream>

#include "animal.h"

namespace animal
{

CAnimal::CAnimal(std::string const& sName, std::string const& sType)
    : m_sName{sName}
    , m_sType{sType}
{}

std::string CAnimal::GetType() const
{
    return m_sType;
}

void CAnimal::SetName(std::string const& sName)
{
    m_sName = sName;
}

std::string CAnimal::GetName() const 
{
    return m_sName;
}

CGiraffe::CGiraffe(std::string const& sName, std::string const& sType)
    : CAnimal{sName, sType}
{}

void CGiraffe::Speak() const
{
    std::cout << "Giraffe voice...\n";
}

CLion::CLion(std::string const& sName, std::string const& sType )
    : CAnimal{sName, sType}
{}

void CLion::Speak() const
{
    std::cout << "Lion voice...\n";
}

} // namespace animal
