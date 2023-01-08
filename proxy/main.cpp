
#include "proxyrealdataprovider.h"

#include <iostream>

int main()
{
    using namespace Design_Patterns;

    auto& DataProvider = CProxyRealDataProvider::GetInstance();

    std::cout << DataProvider.ProceedRequest("fb.com") << std::endl;
    std::cout << DataProvider.ProceedRequest("instagram.com") << std::endl;
    std::cout << DataProvider.ProceedRequest("list.am") << std::endl;
    std::cout << DataProvider.ProceedRequest("list.am") << std::endl;
    std::cout << DataProvider.ProceedRequest("youtube.com") << std::endl;
}
