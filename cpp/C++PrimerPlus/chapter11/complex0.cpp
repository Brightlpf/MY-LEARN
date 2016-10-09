#include <iostream>
#include "complex0.h"

using std::cout;
using std::cin;
using std::endl;

/*
class complex{
private:
	double real;
	double imaginary;
public:
	complex();
	complex(double r, double im);
	~complex();
	complex operator+(const complex & cpl) const;
	complex operator-(const complex & cpl) const;
	complex operator*(const complex & cpl) const;
	complex operator*(const double d) const;
	complex operator~() const;
	
	//friend
	friend complex operator*(const double d, const complex & cpl);
	friend ostream & operator<<(ostream & os, const complex & cpl); 
	friend ostream & operator>>(ostream & os, const complex & cpl);
};
*/
complex::complex()
{
	real = imaginary = 0.0;
}

complex::complex(double r, double im)
{
	real = r;
	imaginary = im;
}

complex::~complex()
{
	
}

complex complex::operator+(const complex & cpl) const
{
	return complex(real + cpl.real, imaginary + cpl.imaginary);
}

complex complex::operator-(const complex & cpl) const
{
	return complex(real - cpl.real, imaginary - cpl.imaginary);
}

complex complex::operator*(const complex & cpl) const
{
	return complex(real * cpl.real - imaginary * cpl.imaginary, real * cpl.imaginary + imaginary * cpl.real);
}

complex complex::operator*(const double d) const
{
	return complex(d * real, d * imaginary);
}

complex complex::operator~() const
{
	return complex(real, -imaginary);
}

//friend
complex operator*(const double d, const complex & cpl)
{
	return complex(d * cpl.real, d * cpl.imaginary);
}

ostream & operator<<(ostream & os, const complex & cpl)
{
	os << "(" << cpl.real << ", " << cpl.imaginary << "i)";
	return os;
}

istream & operator>>(istream & is, complex & cpl)
{
	cout << "real: ";
	is >> cpl.real;
	cout << "imaginary: ";
	is >> cpl.imaginary;
	
	return is;
}
