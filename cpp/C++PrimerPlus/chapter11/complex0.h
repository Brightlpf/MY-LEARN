#include <iostream>

using std::ostream;
using std::istream;

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
	friend istream & operator>>(istream & is, complex & cpl);
};
