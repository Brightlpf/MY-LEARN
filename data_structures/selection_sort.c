#include <stdio.h>

void slct_sort(int list[], int n)
{
	int i, j, min;
	int temp;
	int swap_count = 0;
	
	for(i = 0; i < n - 1; i++)
	{
		min = i;
		for(j = i + 1; j < n; j++)
		{
			if(list[min] > list[j])
			{
				min = j;
			}	
		}
		if(min != i)
		{
			temp = list[i];
			list[i] = list[min];
			list[min] = temp;
			swap_count++;
		}	
	}
	printf("swap times : %d\n", swap_count);
}