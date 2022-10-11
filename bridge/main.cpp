
#include "bridge.h"

int main()
{
	using namespace DesignPatterns;
	CProviderDevice* pMyDevice = new CRouter{};

	pMyDevice->provide();

	delete pMyDevice;
}
