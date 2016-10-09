#include <stdio.h>

double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
double target1[5];
double target2[5];

void copy_arr(double target[], const double source[], int n);
void copy_ptr(double *target, const double *source, int n);
void show_arr(double arr[]);

int main(void)
{
	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	printf("arr1: \n");
	show_arr(target1);
	printf("\narr2: \n");
	show_arr(target2);
	printf("\n");
	return 0;
}

void copy_arr(double target[], const double source[], int n)
{
	int i;
	if(n > 5)
	{
		n = 5;
	}
	for(i = 0; i < n; i++)
	{
		target[i] = source[i];
	}
	return;
}

void copy_ptr(double *target, const double *source, int n)
{
	int count = 0;
	
	if(n > 5)
	{
		n = 5;
	}
	while(count < n)
	{
		*target++ = *source++;
		count++;
	}
	return;
}

void show_arr(double arr[])
{
	int i;
	int count=0;
	
	for(i = 0; i < sizeof(arr); i++)
	{
		if((++count % 8) == 0)
		{
			printf("\n");
		}
		printf("%6.1f", arr[i]);
	}
	return;
}
