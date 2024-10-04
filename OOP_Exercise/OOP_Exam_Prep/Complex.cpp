#include "Complex.h"

Complex::Complex(double real, double im)
{
	setIm(im);
	setReal(real);
}

void Complex::setReal(double newReal)
{
	real = newReal;
}

void Complex::setIm(double newIm)
{
	im = newIm;
}

double Complex::getReal() const
{
	return real;
}

double Complex::getIm() const
{
	return im;
}

Complex Complex::getComplexSpr() const
{
	Complex result(*this);
	result.im *= -1;
	return result;
}

Complex& Complex::operator+=(const Complex& other)
{
	im += other.im;
	real += other.real;
	return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
	im -= other.im;
	real -= other.real;
	return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
	double realCopy = real;
	real = real * other.real - im * other.im;
	im = realCopy * other.im + im * other.real;
	return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
	Complex spr = other.getComplexSpr();
	Complex copy = other;
	*this *= spr;
	copy *= spr;
	if (copy.real != 0){
		im /= copy.im;
		real /= copy.real;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
	return os << complex.real << ' ' << complex.im << 'i';
}

std::istream& operator>>(std::istream& is, Complex& complex)
{
	return is >> complex.real >> complex.im;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result += rhs;
	return result;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result -= rhs;
	return result;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result *= rhs;
	return result;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result /= rhs;
	return result;
}

bool operator==(const Complex& lhs, const Complex& rhs)
{
	return lhs.getReal() == rhs.getReal() && lhs.getIm() == rhs.getIm();
}

bool operator!=(const Complex& lhs, const Complex& rhs)
{
	return !(lhs==rhs);
}
