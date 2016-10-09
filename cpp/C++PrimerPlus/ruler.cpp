#include <iostream>

const int Len = 66;
const int Div = 6;

void subdivide(char ar[], int low, int high, int level);
int main()
{
	char arr[Len];
	int min, max;
	
	min = 0;
	max = Len;
	arr[0] = arr[Len - 2] = '|';
	for(int i = 1; i < Len - 2; i++)
		arr[i] = ' ';
	arr[Len-1] = '\0';
	std::cout << arr << std::endl;
	
	for(int i = 1; i < Div; i++)
	{
		subdivide(arr, min, max - 2, i);
		std::cout << arr << std::endl;
		for(int j = 1; j < Len -2; j++)
		{
			arr[j] = ' ';
		}
	}
	return 0;
}

void subdivide(char ar[], int low, int high, int level)
{
	if(level <= 0)
		return;
	
	int mid = (low + high)/2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}
