
#include "singleton.hpp"

namespace Design_Patterns
{

journal* journal::m_pInstance = nullptr;

journal::journal()
        : m_sName{"default Journal"} 
{}

std::mutex oLockerMutex;

journal* journal::GetInstance()
{
    if (m_pInstance == nullptr) 
    {
        std::lock_guard<std::mutex> oLocker(oLockerMutex);  
        if (m_pInstance == nullptr)     // DCLP - double checking lock principle
        {
            m_pInstance = new journal();
        }
    }

    return m_pInstance;;

}

void journal::SetName(const std::string& sJournalName)
{
    m_sName = sJournalName;
}

const std::string& journal::GetName() const
{
    return m_sName;
}

} // Design_Patterns
