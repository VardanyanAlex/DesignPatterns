
namespace DesignPatterns
{ 

class CRoundPeg
{
public:
    CRoundPeg(double nRadius = 0);
    virtual double getRadius() const;

private:
    double m_nRadius;
};

class CRoundHall
{
public:
    CRoundHall(double const nRadius);

    double getRadius() const;

    bool fit(CRoundPeg const*) const;

private:
    double m_nRadius;
};

class CSquarePeg
{
public:
    CSquarePeg(double nWidth, double nLength);

    double getSquareArea() const;

private:
    double m_nWidth;
    double m_nLength;
};

class CSquarePegToRoundPegAdapter : public CRoundPeg
{
public:
    CSquarePegToRoundPegAdapter(double nWidth, double nLength);
    double getRadius() const override;

private:
    double m_nWidth;
    double m_nLength;
};

} // namespace DesignPatterns
