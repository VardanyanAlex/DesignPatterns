
#ifndef _DESIGN_PATTERNS_STATE_PATTERN_HPP_
#define _DESIGN_PATTERNS_STATE_PATTERN_HPP_

#include <memory>

#include "iticket.h"

class CTriaging : public IState
{
public:
    void Triaging(ITicket*)  override;
    void Backlog(ITicket*) override;
    void InProgress(ITicket*)  override;
    void Validating(ITicket*)  override;
};

class CBacklog : public IState
{
public:
    void Triaging(ITicket*)  override;
    void Backlog(ITicket*) override;
    void InProgress(ITicket*)  override;
    void Validating(ITicket*)  override;
};

class CInProgress : public IState
{
public:
    void Triaging(ITicket*)  override;
    void Backlog(ITicket*) override;
    void InProgress(ITicket*)  override;
    void Validating(ITicket*)  override;
};

class CValidating : public IState
{
public:
    void Triaging(ITicket*)  override;
    void Backlog(ITicket*) override;
    void InProgress(ITicket*)  override;
    void Validating(ITicket*)  override;
};

#endif // _DESIGN_PATTERNS_STATE_PATTERN_HPP_
