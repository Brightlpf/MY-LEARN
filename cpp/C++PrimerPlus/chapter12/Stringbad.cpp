#include <iostream>
#include <cstring>
#include "Stringbad.h"

using std::ostream;
using std::cout;
using std::endl;

//init static class member
int Stringbad::num_strings = 0;
/*
class Stringbad{
private:
	char * str;
	int len;
	static int num_strings;
public:
	Stringbad();
	Stringbad(const char * s);
	~Stringbad();
	
	friend ostream & operator<<(ostream & os, const Stringbad & s);
};
*/

Stringbad::Stringbad()
{
	len = 4;
	str = new char[len +1];
	std::strncpy(str, "C++", len);
	++num_strings;
	cout << num_strings << ": \" "<< str << "\" default object created.\n"; 
}

Stringbad::Stringbad(const char *s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	++num_strings;
	
	cout << num_strings << ": \" "<< str << "\" object created.\n"; 
}

Stringbad::~Stringbad()
{
	cout << "\"" << str << "\" object delete, ";
	--num_strings;
	cout << num_strings << "left \n";
	delete [] str;
}

ostream & operator<<(ostream & os, const Stringbad & s)
{
	os << s.str;
	return os;
}

Stringbad::Stringbad(const Stringbad & s)
{
	++num_strings;
	len = s.len;
	str = new char[len + 1];
	std::strcpy(str, s.str);
	cout << "copy construct called.\n";
}

Stringbad & Stringbad::operator=(const Stringbad &s)
{	
	if(&s == this)
		return *this;
	delete [] str; // delete room may be already allocate
	
	len = s.len;
	str = new char[len + 1];
	std::strcpy(str, s.str);
	
	cout << "operator =  be called.\n";
	return *this;
}
