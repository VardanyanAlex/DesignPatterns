// command.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "chief.h"
#include "waiter.h"

#include <iostream>

int main()
{
    std::string sUserInput{};

    CWaiter oWaiter{};

    auto pCook = std::make_shared<CCook>();

    CChief oChief{};
    oChief.SetCook(pCook);

    while (true)
    {
        std::getline(std::cin, sUserInput);
        if (sUserInput == "exit")
            break;
        else if (sUserInput == "\n" || sUserInput == "")
            continue;

        auto pCommand = oWaiter.Work(sUserInput);

        oChief.Do(pCommand);
    }
}
