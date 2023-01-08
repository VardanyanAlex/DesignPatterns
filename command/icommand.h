
#ifndef _DESIGN_PATTERNS_INTERFACE_ICOMMAND_HPP_
#define _DESIGN_PATTERNS_INTERFACE_ICOMMAND_HPP_

#include "cook.h"

#include <memory>

class ICommand 
{
public:
	virtual void Execute() = 0;
	void SetCook(std::shared_ptr<CCook>);

protected:
	ICommand() = default;

protected:
	std::shared_ptr<CCook> m_pCook = nullptr;
};

#endif // _DESIGN_PATTERNS_INTERFACE_ICOMMAND_HPP_
