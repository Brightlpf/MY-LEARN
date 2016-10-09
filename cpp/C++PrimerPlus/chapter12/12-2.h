#include <iostream>
#ifndef __String_H_
#define __String_H_
using std::ostream;
using std::istream;

class String{
private:
	char * str;
	int len;
	static int num_strings;
	static int const CINLIM = 80;
public:
	String();//default construct
	String(const char * s);//construct
	String(const String & s); //copy construct
	String & operator=(const String &s); // operator = 
	String & operator=(const char * s);
	~String();
	//add some method
	int length() const {return len;}
	friend bool operator<(const String &st1, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st1, const String &st2);
	friend istream & operator>>(istream &is, String &s);
	friend ostream & operator<<(ostream & os, const String & s);
	//12-2 add
	friend String & operator+(String &st1, const String &st2);
	friend String operator+(const char *s, const String &st2);
	void stringlow();
	void stringup();
	int has(const char c) ;
	
	char & operator[](int i);
	const char & operator[](int i) const;
	//static method
	static int HowMany() {return num_strings;}
};
#endif
