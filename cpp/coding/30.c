#include <stdio.h>

int count1(int n);

int main(void)
{
	int n;
	
	printf("Please enter a integer: ");
	scanf("%d", &n);
	
	printf("Total : %d\n", count1(n));
	return 0;
}

/*
int count1(int n)
{
	int i, temp;
	int count = 0;
	
	for(i = 1; i <= n; i++)
	{
		temp = i;
		while(temp)
		{
			if(temp % 10 == 1)
				count++;
			temp /= 10;
		}	
	}
	return count;
}
*/

int count1(int n)
{
	int count = 0;
	int msd = 0;
	int temp;
	int len = 0;
	
	temp = n;
	while(temp)
	{
		len++;
		temp /= 10;
	}
	if(len == 0)
		return 0;
	else if(len == 1)
		return 1;
	else 
	{
		msd = n /pow(10, len-1);//求出最高位
		if(msd == 1)
		{
			return n%pow(10, len-1) + count1(n%pow(10, len-1)); //最高位为1， + 最高位为 0
		}
		else
		{
			return pow(10, len-1) + count1(n % pow(10, len -1)); //最高位为1， + 最高位为 0
		}
	}
}