
#include <iostream>

#include "state.h"

void CTriaging::Triaging(ITicket* pTicket)
{
    std::cout << "Your ticket is already in 'Triaging' state\n";
}

void CTriaging::Backlog(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CBacklog>();

    if (pState != nullptr)
    {
        pTicket->ChangeState(pState);
        std::cout << "changed to backlog\n";
    }
}

void CTriaging::InProgress(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CBacklog>();

    if (pState != nullptr)
        pState->InProgress(pTicket);
}

void CTriaging::Validating(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CBacklog>();

    if (pState != nullptr)
        pState->Validating(pTicket);
}

void CBacklog::Triaging(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CTriaging>();

    if (pState != nullptr)
    {
        pTicket->ChangeState(pState);
        std::cout << "changed to Triaging\n";
    }
}

void CBacklog::Backlog(ITicket* pTicket)
{
    std::cout << "Your ticket is already in 'Backlog' state\n";
}

void CBacklog::InProgress(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CInProgress>();

    if (pState != nullptr)
    {
        pTicket->ChangeState(pState);
        std::cout << "changed to in progress\n";
    }
}

void CBacklog::Validating(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CInProgress>();

    if (pState != nullptr)
        pState->Validating(pTicket);
}

void CInProgress::Triaging(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CBacklog>();

    if (pState != nullptr)
        pState->Triaging(pTicket);
}

void CInProgress::Backlog(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CBacklog>();

    if (pState != nullptr)
    {
        pTicket->ChangeState(pState);
        std::cout << "changed to backlog\n";
    }
}

void CInProgress::InProgress(ITicket* pTicket)
{
    std::cout << "Your ticket is already in 'In Progress' state\n";
}

void CInProgress::Validating(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CValidating>();

    if (pState != nullptr)
    {
        pTicket->ChangeState(pState);
        std::cout << "changed to validating\n";
    }
}

void CValidating::Triaging(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CInProgress>();

    if (pState != nullptr)
        pState->Triaging(pTicket);
}

void CValidating::Backlog(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CInProgress>();

    if (pState != nullptr)
        pState->Backlog(pTicket);
}

void CValidating::InProgress(ITicket* pTicket)
{
    State_SPtr pState = std::make_shared<CInProgress>();

    if (pState != nullptr)
    {
        pTicket->ChangeState(pState);
        std::cout << "changed to in progress\n";
    }
}

void CValidating::Validating(ITicket* pTicket)
{
    std::cout << "Your ticket is already in 'Validating' state\n";
}
