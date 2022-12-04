
#include "townhall.h"

void CTownHall::AddLaw(std::string const& sLaw)
{
	m_aLaws.push_back(sLaw);

	Notify(this);
}

std::string CTownHall::GetLastLaw() const
{
	return m_aLaws.back();
}
