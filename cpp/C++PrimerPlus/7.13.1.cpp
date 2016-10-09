#include <iostream>
#include <cstdlib>

using namespace std;
double aver(double a, double b);

int main()
{
	double a, b;
	while(1)
	{
		cout << "Enter the fisrt number: ";
		cin >> a;
		while(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Please Enter a double number: ";
			cin >> a;
		}
		if(a == 0)
			break;
		cout << "Enter the second number: ";
		cin >> b;
		while(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Please Enter a double number: ";
			cin >> b;
		}
		if(a == 0)
			break;
		
		cout << "The result is : " << aver(a, b) << endl;
	}
	return 0;
}

double aver(double a, double b)
{
	return 2.0 * a * b /(a + b);
}
