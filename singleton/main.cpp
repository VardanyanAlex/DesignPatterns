
#include <iostream>

#include "singleton.hpp"

int main()
{
    Design_Patterns::CJournal& pCJournal = Design_Patterns::CJournal::GetInstance();

    std::cout << pCJournal.GetName() << std::endl;

    pCJournal.SetName("Marca");

    for(int i = 0; i < 10; ++i)
    {
        std::cout << Design_Patterns::CJournal::GetInstance().GetName() << std::endl;
    }

}
