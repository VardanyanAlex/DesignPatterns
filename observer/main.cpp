
#include <iostream>

#include "ministry.h"
#include "townhall.h"

int main()
{
    CTownHall oTownHall{};
    oTownHall.AddLaw("Law No: 1");

    std::shared_ptr<CTransport> pTransportMinistry = std::make_shared<CTransport>();
    oTownHall.Attach(pTransportMinistry);

    oTownHall.AddLaw("Law No: 2");

    std::shared_ptr<CEnvironment> pEnvironmentMinistry = std::make_shared<CEnvironment>();
    oTownHall.Attach(pEnvironmentMinistry);

    oTownHall.AddLaw("Law No: 3");

    oTownHall.Detach(pTransportMinistry);

    oTownHall.AddLaw("Law No: 4");
}
