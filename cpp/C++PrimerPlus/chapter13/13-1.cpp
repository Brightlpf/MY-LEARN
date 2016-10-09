#include <iostream>
#include <cstring>
#include "13-1.h"


using namespace std;
/*
class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(char * s1, char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	~Cd();
	void Report() const;
	Cd & operator=(const Cd & d);
};
*/

Cd::Cd(const char * s1, const char *s2, int n, double x)
{
	strncpy(performers, s1, 49);
	performers[49] = '\0';
	strncpy(label, s2, 19);
	label[19] = '\0';
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd &d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	
}

void Cd::Report() const
{
	cout << "performers: " << performers << endl;
	cout << "label:\t" << label << endl;
	cout << "selections:\t" << selections << endl;
	cout << "playtime:\t" << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	if(&d == this)
		return *this;
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	
	return *this;
}


/*
class Classic : public Cd
{
private:
	char favourite[50];

public:
	Classic(char *s1, char *s2, int n, double x, char * s3);
	Classic(const Classic & c);
	Classic();
	//virtual ~Classic();
	virtual void Report() const;
	virtual Classic & operator=(const Classic & c);
}
*/

Classic::Classic(const char *s3, const char *s1, const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
	strncpy(favourite, s3, 49);
	favourite[49] = '\0';
}

Classic::Classic(const Classic & c) : Cd(c)
{
	strcpy(favourite, c.favourite);
}

Classic::Classic(): Cd()
{
	favourite[0] = '\0';
}

void Classic::Report() const
{
	Cd::Report();
	cout << "favourite:\t" << favourite << endl;
}

Classic & Classic::operator=(const Classic & c)
{
	if (&c == this)
		return *this;
	Cd::operator=(c);
	strcpy(favourite, c.favourite);
	
	return *this;
}
