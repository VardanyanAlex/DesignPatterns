
#ifndef DESIGN_PATTERN_SINGLETON
#define DESIGN_PATTERN_SINGLETON

#include <iostream>
#include <mutex>
#include <vector>

namespace Design_Patterns
{

class journal
{
public:
    static journal* GetInstance();

    void SetName(const std::string&);

    const std::string& GetName() const;

protected:
    journal();

private:
    journal(const journal&) =delete;
    journal& operator=(const journal&) =delete;

    journal(const journal&&) =delete;
    journal& operator=(const journal&&) =delete;

private:
    std::string m_sName{};
    std::vector<std::string> m_aLogs{};

    static journal* m_pInstance;

};

} // Design_Patterns

#endif // DESIGN_PATTERN_SINGLETON
