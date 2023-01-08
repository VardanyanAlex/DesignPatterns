
#ifndef _DESIGN_PATTERNS_PROXY_REAL_DATA_PROVIDER_HPP_
#define _DESIGN_PATTERNS_PROXY_REAL_DATA_PROVIDER_HPP_

#include "idataprovider.h"

#include <map>

namespace Design_Patterns
{

class CProxyRealDataProvider : public IDataProvider
{
public:
	std::string ProceedRequest(std::string const&) const;

	static IDataProvider& GetInstance();

protected:
	CProxyRealDataProvider();

protected:
	IDataProvider* m_pCoreDataProvider = nullptr;

	std::pair<std::string, std::string> mutable m_pairCachedData;
};

} // namespace Design_Patterns

#endif // _DESIGN_PATTERNS_PROXY_REAL_DATA_PROVIDER_HPP_
