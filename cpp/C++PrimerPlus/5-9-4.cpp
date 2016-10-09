#include <iostream>
using namespace std;

int main(void)
{
	const float sigrate = 0.1;
	const float dourate = 0.05;
	const int capital = 100;
	float total_sig = capital;
	float total_dou = capital;
	int year = 0;
	
	while(total_dou <= total_sig)
	{
		total_sig += capital * sigrate;
		total_dou += total_dou * dourate;
		++year;
		#if 1
		cout << "After " << year << "year: "<< endl;
		cout << "Daphne have " << total_sig << "$" << endl;
		cout << "cleo have "<< total_dou << "$" << endl;
		#endif
	}
	cout << "After " << year << "year: "<< endl;
	cout << "Daphne have " << total_sig << "$" << endl;
	cout << "cleo have "<< total_dou << "$" << endl;
	return 0;
	
}
