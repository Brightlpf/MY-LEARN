#include <iostream>
#include <cstdlib>
using namespace std;
#include <cstring>

struct stringy{
	char *str;
	int ct;
};
void set(stringy & str, const char * ps);
void show(const stringy & stry, int times = 1);
void show(const char * str, int times = 1);
int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	
	set(beany, testing);
	show(beany);
	show(beany, 2);
	delete [] beany.str;
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
}

void set(stringy & str, const char * ps)
{
	if( NULL == ps)
	{
		exit(1);
	}
	str.ct = strlen(ps);
	str.str = new char [str.ct+1];
	strncpy(str.str, ps, str.ct);
}

void show(const stringy & stry, int times)
{
	for(int i = 0; i < times; i++)
		cout << stry.str << endl;
}

void show(const char * str, int times)
{
	for(int i = 0; i < times; i++)
		cout << str << endl;
}
