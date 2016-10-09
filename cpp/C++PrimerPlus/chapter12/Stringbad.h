#include <iostream>
#ifndef __STRINGBAD_H_
#define __STRINGBAD_H_
using std::ostream;

class Stringbad{
private:
	char * str;
	int len;
	static int num_strings;
public:
	Stringbad();//default construct
	Stringbad(const char * s);//construct
	Stringbad(const Stringbad & s); //copy construct
	Stringbad & operator=(const Stringbad &s); // operator = 
	~Stringbad();
	
	friend ostream & operator<<(ostream & os, const Stringbad & s);
};
#endif
