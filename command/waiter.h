
#ifndef _DESIGN_PATTERNS_WAITER_HPP_
#define _DESIGN_PATTERNS_WAITER_HPP_

#include "icommand.h"

#include <memory>
#include <string>

class CWaiter
{
public:
	std::shared_ptr<ICommand> Work(std::string const& sUserInput);
};

#endif // _DESIGN_PATTERNS_WAITER_HPP_
