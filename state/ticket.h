
#ifndef _DESIGN_PATTERNS_TICKET_HPP_
#define _DESIGN_PATTERNS_TICKET_HPP_

#include "iticket.h"

class CTicket : public ITicket
{
public:
    CTicket(State_SPtr);

    void ChangeState(State_SPtr) override;

    void SendToTriaging() override;
    void SendToBacklog() override;
    void SendToInProgress() override;
    void SendToValidating() override;

private:
    State_SPtr m_pState = nullptr;

};

#endif // _DESIGN_PATTERNS_TICKET_HPP_
