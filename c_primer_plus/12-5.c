#include <stdio.h>
#include <stdlib.h>

int arr[100];
void sort(int arr[], int n);
void show(int arr[], int n);

int main(void)
{
	int i;
	
	srand((unsigned int)time(NULL));
	
	for(i = 0; i < 100; i++)
	{
		arr[i] = rand() % 10;
	}
	show(arr, 100);
	puts("Down sort: ");
	sort(arr, 100);
	show(arr, 100);
	
	puts("Done.");
	return 0;
}

void sort(int arr[], int n)
{
	int i,j;
	int swap;
	int temp;
	
	for(i = 0; i < n - 1; i++)
	{
		swap = 0;
		for(j = 0; j < n - i -1; j++)
		{
			if(arr[j] < arr[j+1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				swap = 1;
			}
		}
		if(swap == 0)
		{
			break;
		}
	}
		
}

void show(int arr[], int n)
{
	int i;
	int count = 0;
	
	for(i = 0; i < n; i++)
	{
		if(count++ % 10 == 0)
		{
			printf("\n");
		}
		printf("%5d", arr[i]);
	}
	printf("\n");
}
