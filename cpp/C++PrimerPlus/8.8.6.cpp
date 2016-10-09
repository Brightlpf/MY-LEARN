/*
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T maxn(T arr[], int n);

template <> const char * maxn<const char *>(const char * arr[], int n);

int main()
{
	int narr[6] = { 1, 3, 9, 51, 8 , 20};
	double darr[4] = {18.8, 2.3, 4.2, 10.8};
	
	const char * carr[5] = {
		"The Great Wall",
		"The Yellow river",
		"Zhu mu rang ma",
		"Statue of Liberty",
		"XXXXXXXXXXXXXXXXXX"
	};
	
	cout << "The max interger number : " << maxn(narr, 6) << endl;
	cout << "The max double number ：" << maxn(darr, 4) << endl;
	cout << "The longest string : " << maxn(carr, 5) << endl;
	return 0;
}

template <typename T>
T maxn(T arr[], int n)
{
	T max = arr[0];
	
	for(int i = 0; i < n; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

template <> const char * maxn<const char *>(const char * arr[], int n)
{
	const char *p = arr[0];
	
	for(int i = 0; i < n; i++)
	{
		cout << "strlen(arr[" << i << "]) = " << strlen(arr[i]) << endl;
		if(strlen(p) < strlen(arr[i]))
		{
			p = arr[i];
		}
	}
	return p;
}
*/

#include <iostream>
#include <cstring>
using namespace std;


template <typename T>
T maxn(T arr[], int n);


template <> const char * maxn(const char * arr[], int n);


int main()
{
	int narr[6] = { 1, 3, 9, 51, 8 , 20};
	double darr[4] = {18.8, 2.3, 4.2, 10.8};

	const char * carr[5] = {
	"The Great Wall",
	"The Yellow river",
	"Zhu mu rang ma",
	"Statue of Liberty",
	"XXXXXXXX"
	};

	cout << "The max interger number : " << maxn(narr, 6) << endl;
	cout << "The max double number ：" << maxn(darr, 4) << endl;
	cout << "The longest string : " << maxn(carr, 5) << endl;
	return 0;
}


template <typename T>
T maxn(T arr[], int n)
{
	T max = arr[0];

	for(int i = 0; i < n; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}


template <> const char * maxn(const char * arr[], int n)
{
	const char *p = arr[0];

	for(int i = 0; i < n; i++)
	{
		cout << "strlen(arr[" << i << "]) = " << strlen(arr[i]) << endl;
		if(strlen(p) < strlen(arr[i]))
		{
			p = arr[i];
		}
	}
	return p;
}
