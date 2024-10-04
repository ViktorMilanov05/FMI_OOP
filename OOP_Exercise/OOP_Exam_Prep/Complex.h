#include <iostream>
class Complex {
	double im;
	double real;

public:
	Complex() : im(0), real(0) {}
	Complex(double real, double im);
	void setReal(double newReal);
	void setIm(double newIm);
	double getReal() const;
	double getIm() const;

	Complex getComplexSpr() const;

	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator*=(const Complex& other);
	Complex& operator/=(const Complex& other);

	friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
	friend std::istream& operator>>(std::istream& is, Complex& complex);
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);