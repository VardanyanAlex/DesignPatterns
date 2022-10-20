
#ifndef _DESIGN_PATTERNS_DECORATOR_HPP

namespace DesignPatterns
{

class IBus
{
public:
	virtual int GetBaggageCapacity() const = 0;
	virtual int GetPrice() const = 0;


}; // class AbsMercedesEClass

class CClassicBus : public IBus
{
public:
	explicit CClassicBus(int iPrice, int iCapacity);

	int GetBaggageCapacity() const override;
	int GetPrice() const override;

private:
	int m_iPrice;
	int m_iBaggageCapacity;
};

class CBusDecoration : public IBus
{
public:
	virtual int GetBaggageCapacity() const  = 0;
	virtual int GetPrice() const override = 0;

protected:
	CBusDecoration(IBus*);

	IBus* m_pBus = nullptr;
};

class CBusWithExtraBaggage : public CBusDecoration
{
public:
	explicit CBusWithExtraBaggage(IBus*, int iExtraBaggagePrice, int iExtraBaggageCapacity);

	int GetBaggageCapacity() const override;
	int GetPrice() const override;
private:
	int m_iExtraBaggagePrice;
	int m_iExtraBaggageCapacity;
};

class CBusWithContainer : public CBusDecoration
{
public:
	explicit CBusWithContainer(IBus*, int iContainerPrice, int iContainerCapacity);

	int GetBaggageCapacity() const override;
	int GetPrice() const override;
private:
	int m_iContainerPrice;
	int m_iContainerCapacity;
};

} // namespace DesignPatterns

#endif // _DESIGN_PATTERNS_DECORATOR_HPP
