#include <stdio.h>
#define MAX 100

/* 该函数从第i个元素开始，到第n-1个元素，递归出所有组合情况。
每个元素 0表示不选中，1表示选中， i 表示数组中第I个元素 n 表示第n个元数*/
void powerset(int arr[], int i, int n);  
char value[MAX]; //要输出的字符集
void show1(char arr[], int mask[], int n); //根据mask 数组来输出arr, mask[i] == 1时输出arr[i]
int isset(int arr[], int n); //用于统计组合个数
static int g_count = 0;//用于统计组合个数

int main()
{
	int n;
	int mask[MAX];
	int j;
	
	for(j = 0; j < MAX; j++)
	{
		mask[j] = 0;
		value[j] = 'A' + j;
	}
		
	
	printf("Enter a number : ", &n);
	scanf("%d", &n);
	
	while(n >= 0 && n <= 100)
	{
		printf("0\t");
		powerset(mask, 0, n);
		printf("\ntotal: %d\n", g_count + 1);
		g_count = 0;
		printf("Enter a number : ", &n);
		scanf("%d", &n);
	}
	
	return 0;
}

void powerset(int arr[], int i, int n)
{
	
	if(i == n )
	{
		if(isset(arr, n))
			g_count++;
		show1(value, arr, n);
	}
	else
	{
		arr[i] = 1;
		powerset(arr, i + 1, n);
		arr[i] = 0;
		powerset(arr, i + 1, n);
	}
}

void show1(char arr[], int mask[], int n)
{
	int i;
	
	for(i = 0; i < n; i++)
		if(mask[i] == 1)
		{
			printf("%c ", arr[i]);
		}			
	printf("\t");
}

int isset(int arr[], int n)
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		if(arr[i] == 1)
		{
			return 1;
		}
	}
	return 0;
}