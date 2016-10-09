#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
	float f_sec;
	cout << "Enter a number you want to delay: ";
	cin >> f_sec;
	//cin.get();
	clock_t delay = f_sec * CLOCKS_PER_SEC;
	clock_t start = clock();
	
	while(clock() - start < delay)
		;
	cout << "Time over!" << endl;
	return 0;
}
