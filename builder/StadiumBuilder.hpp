
#ifndef DESIGN_PATTERNS_STADIUM_BUIDER_HPP
#define DESIGN_PATTERNS_STADIUM_BUIDER_HPP

#include <iostream>
#include <memory>

namespace Design_Patterns
{ 

class CStadium
{
public:
	enum class EProperty
	{
		Seats,
		Grass,
		Gates,
		Trees
	};
public:

	CStadium(std::string const& sName = "unnamed");

	struct SGrass
	{
		enum EQuality {
			low,
			medium,
			high
		};

		explicit SGrass(EQuality = EQuality::low, bool bNatural = false);

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

	void SetGrass(SGrass*);
	void SetGates(SGates*);
	void SetTribunes(STribunes*);
	void SetTrees(STrees*);

	size_t GetTribuneSeatsCount() const;
	size_t GetSurroundingTreesCount() const;

private:
	std::unique_ptr<SGrass> 		m_pGrass;
	std::unique_ptr<SGates>			m_pGates;
	std::unique_ptr<STribunes> 		m_pTribunes;
	std::unique_ptr<STrees>			m_pTrees;

	std::string 					m_sName;
};


namespace builder
{

class CStadiumBuilder
{
public:
	virtual void		CreateSeats() = 0;
	virtual void		CreateGrass() = 0;
	virtual void		CreateGates() = 0;
	virtual void		CreateSurroundingTrees() = 0;

	virtual CStadium* 	Stadium() const = 0;

	virtual void 		CreateSkeleton() = 0;
	
};

class CSimpleStadiumBuilder : public CStadiumBuilder
{
public:
	virtual void		CreateSeats() override;
	virtual void		CreateGrass() override;
	virtual void		CreateGates() override;
	virtual void		CreateSurroundingTrees() override;

	virtual CStadium* 	Stadium() const override;

	virtual void 		CreateSkeleton() override;

private:
	CStadium* m_pSimpleStadium = nullptr; 
};

class CLuxuryStadiumBuilder : public CStadiumBuilder
{
public:
	virtual void		CreateSeats() override;
	virtual void		CreateGrass() override;
	virtual void		CreateGates() override;
	virtual void		CreateSurroundingTrees() override;

	virtual CStadium* 	Stadium() const override;

	virtual void 		CreateSkeleton() override;

private:
	CStadium* m_pLuxStadium = nullptr; 
};

} // namespace builder

class CDirector
{
public:
	void SetBuilder(builder::CStadiumBuilder*);

	void Create(CStadium::EProperty);

	CStadium* GetStadium() const;

private:
	builder::CStadiumBuilder* m_pBuilder = nullptr; 
};

} // namespace Design_Patterns

#endif // DESIGN_PATTERNS_STADIUM_BUIDER_HPP
