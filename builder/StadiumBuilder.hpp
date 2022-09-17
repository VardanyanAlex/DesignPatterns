
#ifndef DESIGN_PATTERNS_STADIUM_BUIDER_HPP
#define DESIGN_PATTERNS_STADIUM_BUIDER_HPP

#include <iostream>
#include <memory>

namespace Design_Patterns
{ 

class CStadium
{
public:

	struct SGrass
	{
		enum EQuality {
			low,
			medium,
			high
		};

		explicit SGrass(EQuality, bool bNatural);

		EQuality m_eGrassQuality;
		bool m_bNatural;
	};

	struct SGates
	{
		SGates(size_t nLength = 7, size_t nHeight = 2);

		size_t m_nLength;
		size_t m_nHeight;
	};

	struct STrees
	{
		STrees(size_t nCount = 0);

		size_t m_nCount;
	};

	struct STribunes
	{
		STribunes(size_t nCount = 0);

		size_t m_nCount;
	};

	void SetGrass(SGrass* = nullptr);
	void SetGates(SGates* = nullptr);
	void SetTribunes(STribunes* = nullptr);
	void SetTrees(STrees* = nullptr);

	size_t GetTribuneSeatsCount() const;
	size_t GetSurroundingTreesCount() const;

private:
	std::unique_ptr<SGrass> 	m_pGrass;
	std::unique_ptr<SGates>		m_pGates;
	std::unique_ptr<STribunes> 	m_pTribunes;
	std::unique_ptr<STrees>		m_pTrees;
};


namespace builder
{

class CStadiumBuilder
{
public:
	virtual CStadium::SGrass*		CreateGrass() = 0;
	virtual CStadium::SGates* 		CreateGates() = 0;
	virtual CStadium::STrees* 		CreateSurroundingTrees() = 0;
	virtual CStadium::STribunes*	CreateTribunes() = 0;

};

class CSimpleStadiumBuilder : public CStadiumBuilder
{
public:
	CStadium::SGrass*		CreateGrass() override;
	CStadium::SGates*		CreateGates() override;
	CStadium::STrees*		CreateSurroundingTrees() override;
	CStadium::STribunes*	CreateTribunes() override;
};

class CLuxuryStadiumBuilder : public CStadiumBuilder
{
public:
	CStadium::SGrass*		CreateGrass() override;
	CStadium::SGates*		CreateGates() override;
	CStadium::STrees*		CreateSurroundingTrees() override;
	CStadium::STribunes*	CreateTribunes() override;
};

} // namespace builder

class CDirector
{
public:
	explicit CDirector(builder::CStadiumBuilder* = nullptr);

	CStadium GetStadium();

private:
	builder::CStadiumBuilder* m_pBuilder = nullptr; 

};

} // namespace Design_Patterns

#endif // DESIGN_PATTERNS_STADIUM_BUIDER_HPP
