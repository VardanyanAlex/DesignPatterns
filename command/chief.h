
#ifndef _DESIGN_PATTERNS_CHIEF_COOK_HPP_
#define _DESIGN_PATTERNS_CHIEF_COOK_HPP_

#include "cook.h"
#include "icommand.h"

#include <memory>

class CChief
{
public:
	void Do(std::shared_ptr<ICommand>);
	void SetCook(std::shared_ptr<CCook>);

private:
	std::shared_ptr<CCook> m_pCook = nullptr;
};

#endif // _DESIGN_PATTERNS_CHIEF_COOK_HPP_
