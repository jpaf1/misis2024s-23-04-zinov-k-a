#ifndef COMPLEX_COMPLEX_HPP
#define COMPLEX_COMPLEX_HPP

#include <iostream>
#include <sstream>

struct Complex {
	Complex() = default;
	~Complex() = default;
	explicit Complex(const double real) : re(real) {}
	Complex(const Complex&) = default;
	Complex(const double real, const double imaginary) : re(real), im(imaginary) {}
	Complex operator=(const double rhs) { return operator=(Complex(rhs)); }
	bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double& rhs);
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double& rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };

};

bool operator==(const double& lhs, const Complex& rhs);
bool operator==(const Complex& lhs, const double rhs);
bool operator!=(const double& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const double& rhs);
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const double& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const double& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const double& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const double& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double& rhs);
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);
inline std::istream& operator>>(std::istream& istrm, Complex& rhs);
bool testParse(const std::string& str);

#endif