
#ifndef __ANIMAL_PLANET_APP_HPP_
#define __ANIMAL_PLANET_APP_HPP_

#include <vector>

#include"animal.h"

class CAnimalPlanetApp
{
public:
    CAnimalPlanetApp() =default;

    CAnimalPlanetApp(CAnimalPlanetApp const&) = delete;
    CAnimalPlanetApp& operator=(CAnimalPlanetApp const&) =delete;

    void Exec();

private:
    std::vector<Animal_UPtr>m_aAnimals;

};

#endif // __ANIMAL_PLANET_APP_HPP_
