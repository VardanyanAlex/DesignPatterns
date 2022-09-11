
#include <iostream>

#include "singleton.hpp"

int main()
{
    Design_Patterns::journal* pJournal = Design_Patterns::journal::GetInstance();

    std::cout << pJournal->GetName() << std::endl;

    pJournal->SetName("Marca");

    for(int i = 0; i < 10; ++i)
    {
        std::cout << Design_Patterns::journal::GetInstance()->GetName() << std::endl;
    }

}
