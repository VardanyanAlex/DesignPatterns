
#ifndef __ANIMAL_PLANET_ANIMAL_HPP_
#define __ANIMAL_PLANET_ANIMAL_HPP_

#include <memory>
#include <string>

namespace animal
{

//using AnimalPtr = std::unique_ptr<CAnimal>;
class CAnimal
{
public:
    CAnimal(std::string sName = {}, std::string sType = "");

    virtual std::string GetType() const = 0;

    virtual void SetName(std::string sName) = 0;
    virtual std::string GetName() const = 0;

protected:
    std::string m_sName{};
    std::string m_sType{};
};

class CGiraffe : public CAnimal
{
public:
    CGiraffe(std::string sName = {}, std::string sType = "giraffe");

    std::string GetType() const override;

    void SetName(std::string sName) override;
    std::string GetName() const override;

private:
    
};

class CLion : public CAnimal
{
public:
    CLion(std::string sName = {}, std::string sType = "lion");

    std::string GetType() const override;

    void SetName(std::string sName) override;
    std::string GetName() const override;
};

} // namespace animal

#endif // __ANIMAL_PLANET_ANIMAL_HPP_
