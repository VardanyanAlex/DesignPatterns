
#include "chief.h"

#include <iostream>

void CChief::Do(std::shared_ptr<ICommand> pCommand)
{
	if (m_pCook != nullptr)
	{
		pCommand->SetCook(m_pCook);
		pCommand->Execute();
	}
	else
	{
		std::cout << "we don't have a cook!";
	}
}

void CChief::SetCook(std::shared_ptr<CCook> pCook)
{
	m_pCook = pCook;
}
