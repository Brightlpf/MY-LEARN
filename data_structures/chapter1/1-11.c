#include <stdio.h>

void hanoi(int n, char a, char b, char c);//n 个盘子， 从A 移动到C, 借助B
char ch[3] = {'A', 'B', 'C'};

int main()
{
	int n;
	
	printf("Enter a interger: ");
	scanf("%d", &n);
	while(n > 0)
	{
		hanoi(n, ch[0], ch[1], ch[2]);
		printf("\nEnter a interger: ");
		scanf("%d", &n);
	}
	
	return 0;
}

void hanoi(int n, char a, char b, char c)
{
	if(n == 1)
	{
		printf("\t%d %c->%c\t", n, a, c);
	}
	else
	{
		hanoi(n-1, a, c, b);
		printf("\t%d %c->%c\n", n, a, c);//n 表示盘子序号， 从上到下 对于 1~n
		hanoi(n-1, b, a, c);
	}
}