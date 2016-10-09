#include "sort.h"

int seqSearch(Element a[], int k, int n)
{
	int i;
	
	for(i = 0; i < n && a[i].key != k; i++)
		;
	if(i < n)
		return i;
	return -1;
}

int binSearch(Element a[], int k, int n)
{
	int left = 0, right = n -1;
	int mid;
	
	while(left <= right)
	{
		mid = (left + right)/2;
		if(a[mid].key == k)
			return mid;
		else if(k > a[mid].key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid -1;
			
		}
	}
	return -1;
}

void sort(Element a[], int n)
{
	int i, j;
	Element temp;
	
	for(i = 0; i < n -1; i ++)
		for(j = n -1; j > i; j--)
		{
			if(a[j].key > a[j-1].key)
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	printf("sort ok.\n");
}
