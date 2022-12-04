
#include <iostream>

#include "ministry.h"
#include "townhall.h"

void CTransport::Update(ISubject* pSender)
{
	CTownHall* pTownHall = dynamic_cast<CTownHall*>(pSender);
	std::cout << "Transport ministry has gotten the law:\n\t\t" << pTownHall->GetLastLaw()
		<< "\nand now we making our employees learn the law to keep them up to date. Thank you!!!\n\n";
}

void CEnvironment::Update(ISubject* pSender)
{
	CTownHall* pTownHall = dynamic_cast<CTownHall*>(pSender);
	std::cout << "Environmental services ministry has gotten the law:\n\t\t" << pTownHall->GetLastLaw()
		<< "\nand now we making our employees learn the law to keep our city as comfortable and beautiful as possible. Thank you!!!\n\n";
}
