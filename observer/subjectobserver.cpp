
#include "subjectobserver.h"

void ISubject::Attach(IObserver_SPtr pObserver)
{
	m_aObservers.push_back(pObserver);
}

void ISubject::Detach(IObserver_SPtr pObserver)
{
	IObserver_WPtr pObs = IObserver_WPtr(pObserver);

	// comparison of weak pointers
	const auto Predicate = [&](const IObserver_WPtr& ptr1) {
		return ptr1.lock() == pObs.lock();
	};

	m_aObservers.erase(std::remove_if(m_aObservers.begin(), m_aObservers.end(), Predicate) , m_aObservers.end());
}

void ISubject::Notify(ISubject* pSender)
{
	for (auto& pObserver : m_aObservers)
	{
		if (pObserver.expired() == false)
			pObserver.lock()->Update(pSender);
	}
}