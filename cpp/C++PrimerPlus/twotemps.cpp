#include <iostream>

using namespace std;

const int Lim = 8;
template <typename T>
void Swap(T & a, T & b);

template <typename T>
void Swap(T *a1, T * a2, int n);

void show(int a[], int n);
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
	cout << "Overload template: " << endl;
	int a1[Lim] = {1, 8, 0, 8, 1, 9, 8, 9};
	int a2[Lim] = {1, 3, 1, 0, 1, 9, 9, 2};
	cout << "a1: ";
	show(a1, Lim);
	cout << "a2: ";
	show(a2, Lim);
	cout << "After swap: \n";
	Swap(a1, a2, Lim);
	cout << "a1: ";
	show(a1, Lim);
	cout << "a2: ";
	show(a2, Lim);
	
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

template <typename T>
void Swap(T *a1, T * a2, int n)
{
	T temp;
	
	for(int i = 0; i < n; i++)
	{
		temp = a1[i];
		a1[i] = a2[i];
		a2[i] = temp;
	}

}

void show(int a[], int n)
{
	if (n > 4)
	{
		cout << a[0] << a[1] << "/";
		cout << a[2]<< a[3] << "/";
		for(int i = 4; i < n; i++)
			cout << a[i];
		cout << endl;
	}
}