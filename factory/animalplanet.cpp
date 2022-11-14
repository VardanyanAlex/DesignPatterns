
#include <iostream>

#include "animalplanet.h"
#include "animalfactory.h"

void CAnimalPlanetApp::Exec()
{
    std::string sType{};
    std::string sName{};
    while(true)
    {
        std::cout << "Which animal you want to add in ANIMAL PLANET ?\n if you don't want to add an animal just type exit, please!" << std::endl;
        std::cout << "giraffe or lion ?\n";
        std::cout << " >> ";
        std::cin >> sType;
        
        if(sType == "exit")
            break;
        
        std::cout << "enter animal's name\n";
        std::cout << " >> ";
        std::cin >> sName;

        if(sName == "exit")
            break;

        Animal_UPtr pAnimal{nullptr};
        try
        {
            pAnimal = std::move(DesignPatterns::CFactory::Instance().CreateAnimal(sName, sType));
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
        
        m_aAnimals.push_back(std::move(pAnimal));
        std::cout << "\t\t\t\t WOW we have a new member. And now we are \n";
        for(auto const& pAnimal : m_aAnimals)
        {
            std::cout << pAnimal->GetName() << " " << pAnimal->GetType() << std::endl << std::endl;
        }

    }
}
