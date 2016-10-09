#include <iostream>

extern double warming;

void update(double dt);
void local();

using std::cout;

void update(double dt)
{
	extern double warming;
	
	warming += dt;
	cout << "Updating globle warming to " << warming << " degree.\n";
	
}

void local()
{
	double warming = 0.8;
	
	cout << "Local warming is " << warming << " degree.\n";
	cout << "But the globle warming is " << ::warming << " degree.\n";
}
