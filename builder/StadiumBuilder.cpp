
#include "StadiumBuilder.hpp"

#include <cassert>
#include <exception>

namespace Design_Patterns
{ 

CStadium::CStadium(std::string const& sName)
    : m_sName{ sName }
{}

CStadium::SGrass::SGrass(EQuality eQuality, bool bNatural)
                        : m_eGrassQuality{eQuality},
                          m_bNatural{bNatural}
{}

CStadium::SGates::SGates(size_t nLength, size_t nHeight )
                        : m_nLength{nLength},
                          m_nHeight{nHeight}
{}

CStadium::STrees::STrees(size_t nCount)
                        : m_nCount{nCount}
{}

CStadium::STribunes::STribunes(size_t nCount)
                        : m_nCount{nCount}
{}

void CStadium::SetGrass(SGrass* pGrass)
{
    m_pGrass = std::move(std::make_unique<SGrass>(*pGrass));
}

void CStadium::SetGates(SGates* pGates)
{
    m_pGates = std::move(std::make_unique<SGates>(*pGates));
}

void CStadium::SetTribunes(STribunes* pTribunes)
{
    m_pTribunes = std::move(std::make_unique<STribunes>(*pTribunes));
}

void CStadium::SetTrees(STrees* pTrees)
{
    m_pTrees = std::move(std::make_unique<STrees>(*pTrees));
}

size_t CStadium::GetTribuneSeatsCount() const
{
    assert(m_pTribunes != nullptr);
    return m_pTribunes->m_nCount;
}

size_t CStadium::GetSurroundingTreesCount() const
{
    assert(m_pTrees != nullptr);
    return m_pTrees->m_nCount;
}

namespace builder
{

// CSimpleStadiumBuilder impl
void CSimpleStadiumBuilder::CreateSkeleton() 
{
    m_pSimpleStadium = new CStadium;
}

void CSimpleStadiumBuilder::CreateGrass()
{
    CStadium::SGrass* pSimpleGrass = new CStadium::SGrass(CStadium::SGrass::EQuality::low, false) ;
    m_pSimpleStadium->SetGrass(pSimpleGrass);
}

void CSimpleStadiumBuilder::CreateGates() 
{
    m_pSimpleStadium->SetGates(new CStadium::SGates{});
}

void CSimpleStadiumBuilder::CreateSurroundingTrees() 
{
    m_pSimpleStadium->SetTrees(new CStadium::STrees{3});
}

void CSimpleStadiumBuilder::CreateSeats() 
{
    m_pSimpleStadium->SetTribunes(new CStadium::STribunes{1});
}

CStadium* CSimpleStadiumBuilder::Stadium() const
{
    return m_pSimpleStadium;
}

// CLuxuryStadiumBuilder impl
void CLuxuryStadiumBuilder::CreateSkeleton() 
{
    m_pLuxStadium = new CStadium;
}

void CLuxuryStadiumBuilder::CreateGrass()
{
    CStadium::SGrass* oSimpleGrass = new CStadium::SGrass(CStadium::SGrass::EQuality::low, false);
    m_pLuxStadium->SetGrass(oSimpleGrass);
}

void CLuxuryStadiumBuilder::CreateGates() 
{
    assert(m_pLuxStadium != nullptr);
    m_pLuxStadium->SetGates(new CStadium::SGates{});
}

void CLuxuryStadiumBuilder::CreateSurroundingTrees() 
{
    m_pLuxStadium->SetTrees(new CStadium::STrees{3});
}

void CLuxuryStadiumBuilder::CreateSeats() 
{
    m_pLuxStadium->SetTribunes(new CStadium::STribunes{800});
}

CStadium* CLuxuryStadiumBuilder::Stadium() const
{
    return m_pLuxStadium;
}

} // namespace builder

void CDirector::SetBuilder(builder::CStadiumBuilder* pBuilder)
{
    assert(pBuilder != nullptr);
    m_pBuilder = std::move(pBuilder);
}

void CDirector::Create(CStadium::EProperty eStadiumPart)
{
    if(m_pBuilder->Stadium() == nullptr)
    {
        m_pBuilder->CreateSkeleton();
    }

    switch(eStadiumPart)
    {
        case CStadium::EProperty::Gates:
            m_pBuilder->CreateGates();
        break;
        case CStadium::EProperty::Grass:
            m_pBuilder->CreateGrass();
        break;
        case CStadium::EProperty::Seats:
            m_pBuilder->CreateSeats();
        break;
        case CStadium::EProperty::Trees:
            m_pBuilder->CreateSurroundingTrees();
        break;
        default:
        break;
    }
}

CStadium* CDirector::GetStadium() const
{
    return m_pBuilder->Stadium();
}

} // namespace Design_Patterns
