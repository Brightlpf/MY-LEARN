/*
class Person{
private:
	static const LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person(){lname = ""; fname[0] = '\0';}
	Person(const string &ln, const char * fn = "Heyyou");
	void show() const;
	void FormalShow() const;
};
*/
#include "10-2.h"
#include <cstring>
#include <iostream>
using namespace std;

Person::Person(const string &ln, const char *fn )
{
	lname = ln;
	strncpy(fname, fn, LIMIT);
}

void Person::show() const
{
	cout << fname << ", " << lname << endl;
}

void Person::FormalShow() const
{
	cout << lname << ", "<< fname << endl;
}
