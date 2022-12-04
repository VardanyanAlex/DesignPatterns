
#ifndef _DESIGN_PATTERNS_OBSERVER_HPP_
#define _DESIGN_PATTERNS_OBSERVER_HPP_

#include <memory>
#include <vector>

class ISubject;

class IObserver
{
public:
    virtual void Update(ISubject* pSender) = 0;
};
using IObserver_WPtr = std::weak_ptr<IObserver>;
using IObserver_SPtr = std::shared_ptr<IObserver>;

class ISubject
{
public:
    virtual ~ISubject() =default;

    void Attach(IObserver_SPtr);
    void Detach(IObserver_SPtr);
    void Notify(ISubject* pSender);

private:
    std::vector<IObserver_WPtr> m_aObservers;
};

#endif // _DESIGN_PATTERNS_OBSERVER_HPP_
