#include <iostream>

double fuc(float longyear);

int main(void)
{
	using namespace std;
	float longyear;
	
	cout <<"Enter long year: ";
	cin >> longyear;
	cout << longyear<<" long year = "<< fuc(longyear)<<" astronomical units" <<endl;
	
	return 0;
}

double fuc(float longyear)
{
	return 63240 * longyear;
}
