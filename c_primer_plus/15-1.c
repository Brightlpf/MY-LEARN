#include <stdio.h>
#include <string.h>
#include <math.h>

int bintoi(const char *bin);
int bintoi2(const char *bin);

int main(void)
{
	char bin[4*8 + 1] = "01001001";
	int result1, result2;
	
	result1 = bintoi(bin);
	result2 = bintoi2(bin); 
	printf("version 1:(%s) = %d\n", bin, result1);
	printf("version 2:(%s) = %d\n", bin, result2);
	return 0;
}

int bintoi(const char *bin)
{
	int sum = 0;
	int i;
	int count = 0;
	int value;
	
	for(i = strlen(bin) - 1; i >= 0; i--)
	{
		if(bin[i] == '1')
		{
			value = 1;
		}
		else
			value = 0;
		sum += value * pow(2, count);
		count++;
	}
	return sum;
}

int bintoi2(const char *bin)
{
	int i;
	int sum = 0;
	
	for(i = 0; i < strlen(bin); i++)
	{
		sum = sum * 2 + (bin[i] - '0');
	}
	return sum;
}
