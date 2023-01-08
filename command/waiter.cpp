
#include "commands.h"
#include "waiter.h"

#include <stdexcept>

std::shared_ptr<ICommand> CWaiter::Work(std::string const& sUserInput)
{
	std::shared_ptr<ICommand> pCommand = nullptr;
	if (sUserInput == "make fish")
		pCommand = std::make_shared<CMakeFish>();
	else if (sUserInput == "make BBQ")
		pCommand = std::make_shared<CMakeBBQ>();
	else if (sUserInput == "make desert")
		pCommand = std::make_shared<CMakeDesert>();
	else
		throw std::logic_error{ "wrong input\n" };

	return pCommand;
}
