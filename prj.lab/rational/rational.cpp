#include <rational/rational.hpp>

Rational operator+(const Rational& lhs, const Rational& rhs) { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const Rational& rhs) { return Rational{ lhs } -= rhs; }
Rational operator*(const Rational& lhs, const Rational& rhs) { return Rational{ lhs } *= rhs; }
Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational{ lhs } /= rhs; }

Rational operator+(const Rational& lhs, const int64_t rhs) { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const int64_t rhs) { return Rational{ lhs } -= rhs; };
Rational operator*(const Rational& lhs, const int64_t rhs) { return Rational{ lhs } *= rhs; };
Rational operator/(const Rational& lhs, const int64_t rhs) { return Rational{ lhs } /= rhs; }

Rational operator+(const int64_t lhs, const Rational& rhs) { return operator+(rhs, lhs); }
Rational operator-(const int64_t lhs, const Rational& rhs) { return operator+(rhs, lhs); }
Rational operator*(const int64_t lhs, const Rational& rhs) { return operator+(rhs, lhs); }
Rational operator/(const int64_t lhs, const Rational& rhs) { return operator+(rhs, lhs); }

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
     return rhs.writeTo(ostrm);
     }

std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
    return rhs.readFrom(istrm);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << "{" << num << ", " << denum << "}";
    return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    int a = 0;
    char comma(0);
    int b = 0;
    char rightBrace(0);
    istrm >> leftBrace >> a >> comma >> b >> rightBrace;
    if (istrm.good()) {
        if ((Rational::leftBrace == leftBrace) && (Rational::slash == comma)
            && (Rational::rightBrace == rightBrace)) {
            num = a;
            denum = b;

        }
        else {
            istrm.setstate(std::ios_base::failbit);

        }

    }
    return istrm;
}

