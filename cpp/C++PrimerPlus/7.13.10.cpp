#include <iostream>
using namespace std;
typedef double (*pfun)(double, double);
double caculate(double x, double y, pfun pf);
double add(double x, double y);
double mul(double x, double y);
double myminus(double x, double y);
int main()
{
	pfun pf[3] = {add, myminus, mul};
	double x;
	double y;
	while(1)
	{
		cout << "Enter x: ";
		cin >> x;
		cout << "Enter y: ";
		cin >> y;
		
		for(int i = 0; i < 3; i++)
		{
			cout << "result #" << i << ": " << caculate(x, y, pf[i])<< endl;
		}
	}
}

double caculate(double x, double y, pfun pf)
{
	return pf(x, y);
}
double add(double x, double y)
{
	return x + y;
}
double mul(double x, double y)
{
	return x * y;
}
double myminus(double x, double y)
{
	return x - y;
}
