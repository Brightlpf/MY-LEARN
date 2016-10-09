#include <stdio.h>

void display(int a[10]);

int main(void)
{
	int arr1[5] = {1, 2, 3, 4, 5};
	int arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr3[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	
	printf("display arr1: \n");
	display(arr1);
	
	printf("display arr2: \n");
	display(arr2);
	
	printf("display arr3: \n");
	display(arr3);
}

void display(int a[10])
{
	int i = 0;
	for(i = 0; i < 10; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
