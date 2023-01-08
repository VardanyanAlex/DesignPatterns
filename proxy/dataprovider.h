
#ifndef _DESIGN_PATTERNS_DATA_PROVIDER_HPP_
#define _DESIGN_PATTERNS_DATA_PROVIDER_HPP_

#include "idataprovider.h"

#include <map>

namespace Design_Patterns
{

class CDataProvider : public IDataProvider
{
public:
	std::string ProceedRequest(std::string const&) const;

	static IDataProvider& GetInstance();

protected:
	CDataProvider();

	std::map<std::string, std::string> m_aData;
};

} // namespace Design_Patterns

#endif // _DESIGN_PATTERNS_DATA_PROVIDER_HPP_
