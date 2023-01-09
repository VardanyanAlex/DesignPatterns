
#ifndef _DESIGN_PATTERNS_OBSERVER_MINISTRIES_HPP_
#define _DESIGN_PATTERNS_OBSERVER_MINISTRIES_HPP_

#include "subjectobserver.h"

class CTransport : public IObserver
{
public:
	void Update(ISubject* pSender) override;
};

class CEnvironment : public IObserver
{
public:
	void Update(ISubject* pSender) override;
};

#endif // _DESIGN_PATTERNS_SUBJECT_TAWNHALL_HPP_
