
#ifndef _DESIGN_PATTERNS_INTERFACE_STATE_HPP_
#define _DESIGN_PATTERNS_INTERFACE_STATE_HPP_

#include <memory>

#include "iticket.h"

class ITicket;

class IState
{
public:
    virtual void Triaging(ITicket*) = 0;
    virtual void Backlog(ITicket*) = 0;
    virtual void InProgress(ITicket*) = 0;
    virtual void Validating(ITicket*) = 0;

};
using State_SPtr = std::shared_ptr<class IState>;

#endif // _DESIGN_PATTERNS_INTERFACE_STATE_HPP_
