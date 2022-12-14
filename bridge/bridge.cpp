
#include <chrono>
#include <thread>

#include "bridge.h"

namespace DesignPatterns
{

CWifi::CWifi(std::string const& sWifiStandard)
	: m_sWifiStandard{ sWifiStandard }
{}

void CWifi::provide() const
{
	while (true)
	{
		std::cout << "Sharing via wifi...\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void CEthernet::provide() const
{
	while (true)
	{
		std::cout << "Sharing via ethernet...\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

CProviderDevice::CProviderDevice(IInetSharingTechnology* pTech, int iLinkSpeed)
	: m_pSharingTechnology{ std::move(pTech) }
	, m_iLinkSpeed{ iLinkSpeed }
{}

CRouter::CRouter(IInetSharingTechnology* pTech, int iLinkSpeed, int iMaxDistance)
	: CProviderDevice{ pTech, iLinkSpeed }
	, m_iMaxDistance{ iMaxDistance }
{}

void CRouter::provide() const
{
	std::cout << "router in work\n";
	m_pSharingTechnology->provide();
}

CSwitch::CSwitch(IInetSharingTechnology* pTech, int iLinkSpeed, int iLanPortsCount)
	: CProviderDevice{ pTech, iLinkSpeed }
	, m_iLanPortsCount{ iLanPortsCount }
{}

void CSwitch::provide() const
{
	std::cout << "switch in work\n";
	m_pSharingTechnology->provide();
}

} // namespace DesignPatterns
