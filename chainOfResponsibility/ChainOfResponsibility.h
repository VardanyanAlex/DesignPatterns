
#include <memory>

namespace DesignPatterns
{

enum class ERequestType
{
    OnlyCheckHealth,
    Eye,
    Ear,
    Heart
};

class CDoctor;
using Doctor_Ptr = std::shared_ptr<class CDoctor>;

class CDoctor
{
public:

    // pre-condition: pDoctor mustn't be nullptr 
    Doctor_Ptr& SetNext(Doctor_Ptr const& pDoctor);

    virtual void Handle(ERequestType eRequest) const = 0;

protected:
    void SendtoNextDoctor(ERequestType eRequest) const;

protected:
    Doctor_Ptr m_pNextDoctor;
};

class CTheraphist : public CDoctor
{
public:
    void Handle(ERequestType eRequest) const override;
};

class CEyeDoctor : public CDoctor
{
public:
    void Handle(ERequestType eRequest) const override;

};

class CEarDoctor : public CDoctor
{
public:
    void Handle(ERequestType eRequest) const;

};

} // namespace DesignPatterns
