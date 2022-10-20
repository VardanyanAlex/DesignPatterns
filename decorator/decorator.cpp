
#include "decorator.h"

namespace DesignPatterns
{

CClassicBus::CClassicBus(int iPrice, int iCapacity)
	: m_iPrice{ iPrice }
	, m_iBaggageCapacity{ iCapacity }
{}

int CClassicBus::GetBaggageCapacity() const
{
	return m_iBaggageCapacity;
}

int CClassicBus::GetPrice() const
{
	return m_iPrice;
}

CBusDecoration::CBusDecoration(IBus* pBus)
	: m_pBus{ pBus }
{}

CBusWithExtraBaggage::CBusWithExtraBaggage(IBus* pBus, int iExtraBaggagePrice, int iExtraBaggageCapacity)
	: CBusDecoration( pBus )
	, m_iExtraBaggagePrice{ iExtraBaggagePrice }
	, m_iExtraBaggageCapacity{ iExtraBaggageCapacity }
{}

int CBusWithExtraBaggage::GetBaggageCapacity() const
{
	return m_iExtraBaggageCapacity + m_pBus->GetBaggageCapacity();
}

int CBusWithExtraBaggage::GetPrice() const
{
	return m_iExtraBaggagePrice + m_pBus->GetPrice();
}

CBusWithContainer::CBusWithContainer(IBus* pBus, int iExtraBaggagePrice, int iExtraBaggageCapacity)
	: CBusDecoration(pBus)
	, m_iContainerPrice{ iExtraBaggagePrice }
	, m_iContainerCapacity{ iExtraBaggageCapacity }
{}

int CBusWithContainer::GetBaggageCapacity() const
{
	return m_iContainerCapacity + m_pBus->GetBaggageCapacity();
}

int CBusWithContainer::GetPrice() const
{
	return m_iContainerPrice + m_pBus->GetPrice();
}

} // namespace DesignPatterns
