
#include <iostream>

#include "decorator.h"

int main()
{
	using namespace DesignPatterns;

	CClassicBus oBus{10000, 100};

	CBusWithContainer oBigBus{ &oBus, 300, 300 };

	std::cout << oBigBus.GetPrice();
}
