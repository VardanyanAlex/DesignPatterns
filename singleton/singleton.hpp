
#ifndef DESIGN_PATTERN_SINGLETON
#define DESIGN_PATTERN_SINGLETON

#include <iostream>
#include <vector>

namespace Design_Patterns
{

class CJournal
{   // Singleton 
public:
    static CJournal& GetInstance();

    void SetName(const std::string&);

    std::string GetName() const;

private:
    CJournal() =default;

    CJournal(const CJournal&) =delete;
    CJournal& operator=(const CJournal&) =delete;

    CJournal(const CJournal&&) =delete;
    CJournal& operator=(const CJournal&&) =delete;

private:
    std::string m_sName{"default journal"};
    std::vector<std::string> m_aLogs{};

};

} // Design_Patterns

#endif // DESIGN_PATTERN_SINGLETON
