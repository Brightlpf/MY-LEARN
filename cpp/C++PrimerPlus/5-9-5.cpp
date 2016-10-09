#include <iostream>
using namespace std;

int main(void)
{
	const int NUM = 12;
	const char * Month[NUM] = 
	{
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};
	int num[NUM] = {0};
	int temp;
	int sum = 0;
	
	for(int i = 0; i < NUM; i++)
	{
		cout << Month[i] << " saled: "; 
		cin >> temp;
		cin.get();
		cout << "本" << endl;
		sum += temp;
	}
	cout << "All year saled: " << sum << "本"<< endl;
	return 0;
}
