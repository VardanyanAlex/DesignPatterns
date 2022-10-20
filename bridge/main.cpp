
#include "bridge.h"

int main()
{
	using namespace DesignPatterns;

	CWifi oWifiTechnology;
	CProviderDevice* pMyDevice = new CRouter{ &oWifiTechnology };

	pMyDevice->provide();

	delete pMyDevice;
}
