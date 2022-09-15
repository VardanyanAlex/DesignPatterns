
#include "singleton.hpp"

namespace Design_Patterns
{

CJournal::CJournal()
        : m_sName{"default CJournal"} 
{}

std::mutex oLockerMutex;

CJournal& CJournal::GetInstance() 
{   // Meyers' singleton
    static CJournal oInstance;

    return oInstance;;
}

void CJournal::SetName(const std::string& sCJournalName)
{
    m_sName = sCJournalName;
}

const std::string& CJournal::GetName() const
{
    return m_sName;
}

} // namespace Design_Patterns
