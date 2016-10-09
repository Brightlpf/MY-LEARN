#include <iostream>
#include <cstring>
#include "12-2.h"
#include <cctype>

using std::ostream;
using std::cout;
using std::endl;
using std::istream;
//init static class member
int String::num_strings = 0;
/*
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
	void stringlow(String &st);
	void stringup(String &st);
	int has(const char c);
	
	char & operator[](int i);
	const char & operator[](int i) const;
	//static method
	static int HowMany();
};
*/

String::String()
{
	len = 0;
	str = new char[1];
	str = nullptr;
	++num_strings;
	//cout << num_strings << ": \" "<< str << "\" default object created.\n"; 
}

String::String(const char *s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	++num_strings;
	
	//cout << num_strings << ": \" "<< str << "\" object created.\n"; 
}

String::~String()
{
//	cout << "\"" << str << "\" object delete, ";
	--num_strings;
	//cout << num_strings << "left \n";
	delete [] str;
}

ostream & operator<<(ostream & os, const String & s)
{
	os << s.str;
	return os;
}

String::String(const String & s)
{
	++num_strings;
	len = s.len;
	str = new char[len + 1];
	std::strcpy(str, s.str);
//	cout << "copy construct called.\n";
}

String & String::operator=(const String &s)
{	
	if(&s == this)
		return *this;
	delete [] str; // delete room may be already allocate
	
	len = s.len;
	str = new char[len + 1];
	std::strcpy(str, s.str);
	
	//cout << "operator =  be called.\n";
	return *this;
}

String & String::operator=(const char * s)
{
	delete [] str;
	
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
	return st2 < st1;
}

 bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

istream & operator>>(istream &is, String &s)
{
	//is.get(s.str, s.len);// s.len is don't known
	char input[String::CINLIM];
	is.get(input, String::CINLIM);
	if(is)
	{
		s = input;  // call construct trans char * to String
	}
	//skip left
	while(is && is.get() != '\n')
		continue;
	
	return is;
}

char & String::operator[](int i)
{
	if(i <= len)
	return str[i];
}

const char & String::operator[](int i) const
{
	if(i <= len)
		return str[i];
}

String & operator+(String &st1, const String &st2)
{
	String st = st1;
	
	delete [] st1.str;
	st1.str = new char[st1.len + st2.len + 1];
	strncpy(st1.str, st.str, st1.len);
	strcpy(st1.str + st1.len, st2.str);
	st1.len += st2.len;
	
	return st1;
}

String operator+(const char *s, const String &st2)
{
	String st;
	delete [] st.str;
	st.str = new char[strlen(s) + st2.len + 1];
	strncpy(st.str, s, strlen(s));
	strcpy(st.str + strlen(s), st2.str);
	st.len = strlen(s) + st2.len;
	
	return st;
}

void String::stringlow()
{
	char * pst = str;
	while(*pst)
	{
		*pst = tolower(*pst);
		pst++;
	}
}

void String::stringup()
{
	char * pst = str;
	while(*pst)
	{
		*pst = toupper(*pst);
		pst++;
	}
}

int String::has(const char c) 
{
	int count = 0;
	char *pst = str;
	while(*pst)
	{
		if(c == *pst)
		{
			count++;
		}
		pst++;
	}
	return count;
}
