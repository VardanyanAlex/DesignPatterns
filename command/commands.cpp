
#include "commands.h"

#include <stdexcept>

void CMakeFish::Execute()
{
	if (m_pCook == nullptr)
		throw std::logic_error{ "The cook is not specified!" };
	
	m_pCook->MakeFish();
}

void CMakeBBQ::Execute()
{
	if (m_pCook == nullptr)
		throw std::logic_error{ "The cook is not specified!" };

	m_pCook->MakeBBQ();
}

void CMakeDesert::Execute()
{
	if (m_pCook == nullptr)
		throw std::logic_error{ "The cook is not specified!" };

	m_pCook->MakeDessert();
}
