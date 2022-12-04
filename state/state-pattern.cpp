
#include <iostream>
#include <memory>

// Jira ticketting

#include "state.h"
#include "ticket.h"

int main()
{
    State_SPtr pState = std::make_shared<CTriaging>();
    std::shared_ptr<ITicket> oJiraTicket = std::make_shared<CTicket>(pState);
    oJiraTicket->SendToValidating();
}
