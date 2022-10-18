
#ifndef _DESIGNPATTERNS_BRIDGE_HPP_
#define _DESIGNPATTERNS_BRIDGE_HPP_

#include <iostream>
#include <string>

namespace DesignPatterns
{

class IInetSharingTechnology
{
public:
    virtual void provide() const = 0;
};

class CWifi : public IInetSharingTechnology
{
public:
    explicit CWifi(std::string const& sWifiStandard = "ac");

    void provide() const override;

private:
    std::string m_sWifiStandard{};
};

class CEthernet : public IInetSharingTechnology
{
public:
    CEthernet() =default;
    void provide() const override;
};

class CProviderDevice
{
public:
    CProviderDevice(IInetSharingTechnology*, int iLinkSpeed);

    virtual void provide() const = 0;

protected:
    std::unique_ptr<IInetSharingTechnology> m_pSharingTechnology;
    int m_iLinkSpeed{};
};

class CRouter : public CProviderDevice
{
public:
    explicit CRouter(IInetSharingTechnology* pTech, int iLinkSpeed = 30, int iMaxDistance = 7);

    void provide() const override;

private:
    int m_iMaxDistance{};
};

class CSwitch : public CProviderDevice
{
public:
    explicit CSwitch(IInetSharingTechnology* pTech, int iLinkSpeed = 100, int iLanPortsCount = 4);

    void provide() const override;

private:
    int m_iLanPortsCount{};
};

} // namespace DesignPatterns

#endif // _DESIGNPATTERNS_BRIDGE_HPP_
