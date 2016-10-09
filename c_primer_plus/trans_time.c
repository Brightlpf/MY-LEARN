#include <stdio.h>
#define SEC_PER_MIN 60

int main(void)
{
	int min;
	int hour;
	int temp;
	
	printf("This program will trans minute to hours, please enter minute[-1 to quit]:\n");
	if(scanf("%d", &temp) != 1)
	{
		printf("scanf failed\n.");
		return 1;
	}
	
	while(temp >= 0)
	{
		hour = temp / SEC_PER_MIN;
		min = temp % SEC_PER_MIN;
		printf("%02d:%02d\n", hour, min);
		scanf("%d", &temp);
	}
	printf("Thanks\n");
	return 0;
}
