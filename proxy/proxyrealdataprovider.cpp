
#include "dataprovider.h"
#include "proxyrealdataprovider.h"

#include <stdexcept>

namespace Design_Patterns
{

CProxyRealDataProvider::CProxyRealDataProvider()
{
	m_pCoreDataProvider = &CDataProvider::GetInstance();
}

std::string CProxyRealDataProvider::ProceedRequest(std::string const& sQuery) const
{
	std::string sResult{};

	if (m_pairCachedData.first == sQuery)
	{
		sResult = m_pairCachedData.second;
	}
	else
	{
		if (m_pCoreDataProvider == nullptr)
			throw std::domain_error{ "Invalid Data Provider detected!\n" };

		sResult = m_pCoreDataProvider->ProceedRequest(sQuery);

		if(!sResult.empty())
			m_pairCachedData = std::pair{ sQuery, sResult };
	}

	return sResult;
}

IDataProvider& CProxyRealDataProvider::GetInstance()
{
	static CProxyRealDataProvider oDataProvider{};

	return oDataProvider;
}

} // namespace Design_Patterns
