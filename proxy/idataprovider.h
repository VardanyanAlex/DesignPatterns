
#ifndef _DESIGN_PATTERNS_IDATA_PROVIDER_HPP_
#define _DESIGN_PATTERNS_IDATA_PROVIDER_HPP_

#include <string>

namespace Design_Patterns
{

class IDataProvider
{
public:
	virtual std::string ProceedRequest(std::string const&) const = 0;
};

} // namespace Design_Patterns

#endif // _DESIGN_PATTERNS_IDATA_PROVIDER_HPP_
