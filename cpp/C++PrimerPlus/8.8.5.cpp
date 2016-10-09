#include <iostream>
using namespace std;

const int MAX = 5;
template <typename T>
//T max5(const T num[]);    
T max5(const T (&num)[MAX]);  //use reference pointto array, must be set bound of array
int main()
{
	int nnum[MAX];
	double dnum[MAX];

	cout << "Enter 5 integer num: ";
	for(int i = 0; i < MAX; i++)
	{
		while(!(cin >> nnum[i]))
		{
			cin.clear();
			cout << "err, input again: " << endl;
		}
	}
	cout << "The max num is  "<< max5(nnum) << endl;
	
	cout << "Enter 5 double num: ";
	for(int i = 0; i < MAX; i++)
	{
		while(!(cin >> dnum[i]))
		{
			cin.clear();
			cout << "err, input again: " << endl;
		}
	}
	cout << "The max num is  "<< max5(dnum) << endl;
	return 0;
}

template <typename T>
T max5(const T (&num)[MAX])
{
	T max = num[0];
	for(int i = 1; i < MAX; i++)
	{
		if(num[i] > max)
		{
			max = num[i];
		}
	}
	return max;
}
