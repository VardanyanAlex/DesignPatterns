
#ifndef _DESIGN_PATTERNS_SUBJECT_TAWNHALL_HPP_
#define _DESIGN_PATTERNS_SUBJECT_TAWNHALL_HPP_

#include <string>
#include <vector>

#include "subjectobserver.h"

class CTownHall : public ISubject
{
public:
	void AddLaw(std::string const&);
	std::string GetLastLaw() const;

private:
	std::vector<std::string> m_aLaws;
};

#endif // _DESIGN_PATTERNS_SUBJECT_TAWNHALL_HPP_
