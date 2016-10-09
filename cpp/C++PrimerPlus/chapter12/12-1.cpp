#include "12-1.h"
#include <iostream>
#include <cstring>

using namespace std;
/*
class Cow{
private:
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char *ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow &c);
	void ShowCow() const;//display all cow data
};

*/

Cow::Cow()
{
	strcpy(name, "default Cow");
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
	int len = 0;
	
	strncpy(name, nm, 20 -1);
	name[20-1] = '\0';
	len = strlen(ho);
	hobby = new char[len + 1];
	strncpy(hobby, ho, len);
	weight = wt;
}

Cow::Cow(const Cow & c)
{
	int len = 0;
	
	strcpy(name, c.name);
	len = strlen(c.hobby);
	hobby = new char[len + 1];
	strncpy(hobby, c.hobby, len);
	hobby[len] = '\0';
	weight = c.weight;
}

Cow::~Cow()
{
	delete [] hobby;
}

Cow & Cow::operator=(const Cow &c)
{
	if(&c == this)
		return *this;
	delete [] hobby;
	strcpy(name, c.name);
	int len = 0;
	len = strlen(c.hobby);
	hobby = new char [len + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
	
	return *this;
}
void Cow::ShowCow() const//display all cow data
{
	cout << "name: " << name;
	cout << "\thobby: "<< hobby;
	cout << "\tweight: "<< weight<< endl;
}
