
namespace DesignPatterns
{ 

class CRoundPeg
{
public:
    CRoundPeg(double nRadius = 0);
    virtual double getRadius() const;

private:
    double m_fRadius;
};

class CRoundHall
{
public:
    CRoundHall(double const nRadius);

    double getRadius() const;

    bool fit(CRoundPeg const*) const;

private:
    double m_fRadius;
};

class CSquarePeg
{
public:
    CSquarePeg(double nWidth, double nLength);

    double getSquareArea() const;

    double getWidth() const;
    double getLength() const;

private:
    double m_fWidth;
    double m_fLength;
};

class CSquarePegToRoundPegAdapter : public CRoundPeg
{
public:
    CSquarePegToRoundPegAdapter(double nWidth, double nLength);
    ~CSquarePegToRoundPegAdapter();
    double getRadius() const override;

private:
    CSquarePeg* m_pSquarePeg = nullptr;
};

} // namespace DesignPatterns
