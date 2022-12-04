
#ifndef _DESIGN_PATTERNS_INTERFACE_TICKET_HPP_
#define _DESIGN_PATTERNS_INTERFACE_TICKET_HPP_

#include "istate.h"

class ITicket
{
public:
    virtual void ChangeState(State_SPtr) = 0;

    virtual void SendToTriaging() = 0;
    virtual void SendToBacklog() = 0;
    virtual void SendToInProgress() = 0;
    virtual void SendToValidating() = 0;

};

#endif // _DESIGN_PATTERNS_INTERFACE_TICKET_HPP_
