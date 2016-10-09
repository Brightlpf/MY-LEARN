#include "12-1.h"
#include <iostream>

using std::cout;
using std::endl;
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
int main()
{
	cout << "********test default construct**********" << endl;
	Cow defaultcow;
	
	defaultcow.ShowCow();
	cout << "********test regular construct**********" << endl;
	Cow rCow("regular Cow", "chess", 100.0);
	rCow.ShowCow();
	
	cout << "********test copy construct***********" << endl;
	Cow cpCow = rCow;
	cpCow.ShowCow();
	
	cout << "********test operator = **********" << endl;
	Cow opCow("operator=", "xxoo", 200);
	rCow = opCow;
	rCow.ShowCow();
	
}
