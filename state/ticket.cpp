
#include "ticket.h"

CTicket::CTicket(State_SPtr pState)
	: m_pState{ pState }
{}

void CTicket::ChangeState(State_SPtr pState)
{
	m_pState = pState;
}
	 
void CTicket::SendToTriaging()
{
	m_pState->Triaging(this);
}
void CTicket::SendToBacklog()
{
	m_pState->Backlog(this);
}

void CTicket::SendToInProgress()
{
	m_pState->InProgress(this);
}

void CTicket::SendToValidating()
{
	m_pState->Validating(this);
}
