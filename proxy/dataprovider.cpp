
#include "dataprovider.h"

namespace Design_Patterns
{

CDataProvider::CDataProvider()
{
	m_aData = {
		{"fb.com",		"31.13.71.36"	},
		{"list.am",		"172.67.31.1"	},
		{"youtube.com", "216.58.212.46" },
	};
}

std::string CDataProvider::ProceedRequest(std::string const& sQuery) const
{
	std::string sResult{};

	if (m_aData.contains(sQuery))
		sResult = m_aData.find(sQuery)->second;

	return sResult;
}

IDataProvider& CDataProvider::GetInstance()
{
	static CDataProvider oDataProvider{};

	return oDataProvider;
}

} // namespace Design_Patterns
