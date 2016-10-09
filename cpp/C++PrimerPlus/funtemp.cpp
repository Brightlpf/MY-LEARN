#include <iostream>
using namespace std;

template <typename T>
void Swap(T & a, T & b);

int main()
{
	int i = 10;
	int j = 20;
	
	double d1 = 12.6;
	double d2 = 42.8;
	
	cout << "i , j = " << i << ", " << j << endl;
	cout << "d1 , d2 = " << d1 << ", " << d2 << endl;
	Swap(i, j);
	Swap(d1, d2);
	cout << "After swap: \n";
	cout << "i , j = " << i << ", " << j << endl;
	cout << "d1 , d2 = " << d1 << ", " << d2 << endl;
	
	return 0;
}

template <typename T>
void Swap(T & a, T & b)
{
	T temp;
	
	temp = a;
	a = b;
	b = temp;
}
