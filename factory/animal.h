
#ifndef __ANIMAL_PLANET_ANIMAL_HPP_
#define __ANIMAL_PLANET_ANIMAL_HPP_

#include <memory>
#include <string>

namespace animal
{

class CAnimal
{
public:
    CAnimal(std::string const& sName, std::string const& sType);

    std::string GetType() const;

    void SetName(std::string const& sName);
    std::string GetName() const;

    virtual void Speak() const = 0;

protected:
    std::string m_sName;
    std::string m_sType;
};

class CGiraffe : public CAnimal
{
public:
    CGiraffe(std::string const& sName = {}, std::string const& sType = "giraffe");
    
    void Speak() const override;

private:
    size_t m_iNeckLength;
};

class CLion : public CAnimal
{
public:
    CLion(std::string const& sName = {}, std::string const& sType = "lion");

    void Speak() const override;

private:
    size_t m_iHuntingPower;
};

} // namespace animal
using Animal_UPtr = std::unique_ptr<class animal::CAnimal>;

#endif // __ANIMAL_PLANET_ANIMAL_HPP_
