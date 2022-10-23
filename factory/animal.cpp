
#include "animal.h"

namespace animal
{

CAnimal::CAnimal(std::string sName, std::string sType)
    : m_sName{sName}
    , m_sType{sType}
{}

CGiraffe::CGiraffe(std::string sName, std::string sType)
    : CAnimal{sName, sType}
{}

std::string CGiraffe::GetType() const 
{
    return m_sType;
}

void CGiraffe::SetName(std::string sName)
{
    m_sName = sName;
}

std::string CGiraffe::GetName() const 
{
    return m_sName;
}

CLion::CLion(std::string sName , std::string sType )
    : CAnimal{sName, sType}
{}

std::string CLion::GetType() const 
{
    return m_sType;
}

void CLion::SetName(std::string sName)
{
    m_sName = sName;
}

std::string CLion::GetName() const 
{
    return m_sName;
}

} // namespace animal
