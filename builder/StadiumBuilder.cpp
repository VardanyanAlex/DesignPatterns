
#include "StadiumBuilder.hpp"

#include <cassert>
#include <exception>

namespace Design_Patterns
{ 

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

CDirector::CDirector(builder::CStadiumBuilder* pBuilder)
                        : m_pBuilder{pBuilder}
{
    if(m_pBuilder == nullptr)
    {
        assert(false);
        throw std::exception{};
    }
}

CStadium CDirector::GetStadium()
{
    CStadium oStadium{};

    oStadium.SetGates(std::move(m_pBuilder->CreateGates()));
    oStadium.SetGrass(std::move(m_pBuilder->CreateGrass()));
    oStadium.SetTribunes(std::move(m_pBuilder->CreateTribunes()));
    oStadium.SetTrees(std::move(m_pBuilder->CreateSurroundingTrees()));

    return oStadium;
}

void CStadium::SetGrass(SGrass* pGrass)
{
    m_pGrass.reset(pGrass);
}

void CStadium::SetGates(SGates* pGates)
{
    m_pGates.reset(pGates);
}

void CStadium::SetTribunes(STribunes* pTribunes)
{
    m_pTribunes.reset(pTribunes);
}

void CStadium::SetTrees(STrees* pTrees)
{
    m_pTrees.reset(pTrees);
}

size_t CStadium::GetTribuneSeatsCount() const
{
    return m_pTribunes->m_nCount;
}

size_t CStadium::GetSurroundingTreesCount() const
{
    return m_pTrees->m_nCount;
}

namespace builder
{

// CSimpleStadiumBuilder impl
CStadium::SGrass* CSimpleStadiumBuilder::CreateGrass()
{
    return new CStadium::SGrass{CStadium::SGrass::EQuality::low, false};
}
	
CStadium::SGates* CSimpleStadiumBuilder::CreateGates() 
{
    return new CStadium::SGates{3, 2};
}

CStadium::STrees* CSimpleStadiumBuilder::CreateSurroundingTrees() 
{
    return new CStadium::STrees{3};
}

CStadium::STribunes* CSimpleStadiumBuilder::CreateTribunes() 
{
    return new CStadium::STribunes{};
}

// CLuxuryStadiumBuilder impl
CStadium::SGrass* CLuxuryStadiumBuilder::CreateGrass()
{
    return new CStadium::SGrass{CStadium::SGrass::EQuality::high, true};
}
	
CStadium::SGates* CLuxuryStadiumBuilder::CreateGates() 
{
    return new CStadium::SGates{7, 2};
}

CStadium::STrees* CLuxuryStadiumBuilder::CreateSurroundingTrees() 
{
    return new CStadium::STrees{40};
}

CStadium::STribunes* CLuxuryStadiumBuilder::CreateTribunes() 
{
    return new CStadium::STribunes{99354};
}

} // namespace builder

} // namespace Design_Patterns
