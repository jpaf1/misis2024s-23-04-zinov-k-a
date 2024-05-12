#ifndef rational_hpp
#define rational_hpp

#include <iostream>
#include <stdexcept>
#include <sstream>

class Rational {
    int64_t num = 0;
    int64_t denum = 0;

public:
    Rational() : num(0), denum(1) {}
    Rational(const int64_t a) :   num(a), denum(1) {}
    Rational(const int64_t a, const int64_t b) : num(a), denum(b) {
        if (b < 0)  {
            num = -a;
            denum = -b;
    }
        decrease();
    }

    Rational& operator=(const Rational& rhs) noexcept {
        num = rhs.num;
        denum = rhs.denum;
        return *this;
    };
    Rational& operator=(const int64_t& rhs) noexcept {
        num = rhs;
        denum = 1;
        return *this;
    };

    static const char leftBrace{ '{' };
    static const char slash{ '/' };
    static const char rightBrace{ '}' };

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    bool operator==(const Rational& rhs) const noexcept { return num*rhs.denum == denum*rhs.num; }
    bool operator!=(const Rational& rhs) const noexcept { return num*rhs.denum != denum*rhs.num; }
    bool operator<(const Rational& rhs) const noexcept { return num * rhs.denum < denum * rhs.num; }
    bool operator<=(const Rational& rhs) const noexcept { return num * rhs.denum <= denum * rhs.num; }
    bool operator>(const Rational& rhs) const noexcept { return num * rhs.denum > denum * rhs.num; }
    bool operator>=(const Rational& rhs) const noexcept { return num * rhs.denum >= denum * rhs.num; }
    
    Rational& operator-() {
        num = -num;
        return *this;
    };

    Rational& operator+=(const Rational& rhs) noexcept {
        num = rhs.num*denum + rhs.denum*num;
        denum = rhs.denum*denum;
        decrease();
        return *this;
    };
    Rational& operator-=(const Rational& rhs) noexcept {
        num = - rhs.num * denum + rhs.denum * num;
        denum = rhs.denum * denum;
        decrease();
        return *this;
    };
    Rational& operator*=(const Rational& rhs) noexcept {
        num = rhs.num * num;
        denum = rhs.denum * denum;
        decrease();
        return *this;
    };
    Rational& operator/=(const Rational& rhs) {
        num = rhs.denum * num;
        denum = rhs.num * denum;
        decrease();
        return *this;
    };
    Rational& operator+=(const int64_t rhs) noexcept { return operator+=(Rational(rhs)); };
    Rational& operator-=(const int64_t rhs) noexcept { return operator-=(Rational(rhs)); };
    Rational& operator*=(const int64_t rhs) noexcept { return operator*=(Rational(rhs)); };
    Rational& operator/=(const int64_t rhs) { return operator/=(Rational(rhs)); };


private:
    void decrease() {
        int64_t a = num;
        int64_t b = denum;
        if (a != 0 && b != 0) {
            while (a != b) {
                if (a > b) {
                    a = a - b;
                }
                else {
                    b = b - a;
                }
            }
            num = num / a;
            denum = denum / a;
        }
        else {
            throw std::overflow_error("Divide by zero exception");
        }
    }
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

Rational operator+(const Rational& lhs, const int64_t rhs);
Rational operator-(const Rational& lhs, const int64_t rhs);
Rational operator*(const Rational& lhs, const int64_t rhs);
Rational operator/(const Rational& lhs, const int64_t rhs);

Rational operator+(const int64_t lhs, const Rational& rhs);
Rational operator-(const int64_t lhs, const Rational& rhs);
Rational operator*(const int64_t lhs, const Rational& rhs);
Rational operator/(const int64_t lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);

std::istream& operator>>(std::istream& istrm, Rational& rhs);

#endif
