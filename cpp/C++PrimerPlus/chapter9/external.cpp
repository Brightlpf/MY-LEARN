#include <iostream>
using namespace std;

double warming = 0.3;
void update(double dt);
void local();

int main()
{
	cout << "Globle Warming is " << warming << " degree.\n";
	update(0.1);
	cout << "Globle Warming is " << warming << " degree.\n";
	local();
	cout << "Globle Warming is " << warming << " degree.\n";
	return 0;
}