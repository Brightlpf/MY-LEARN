#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define MAX 101

void slct_sort(int list[], int n);
void show_array(int list[], int n);
int main(void)
{
	int n;
	int list[MAX];
	int i;
	struct timespec ts_start, ts_end;
	
	srand(time(NULL));
	
	memset(&ts_start, 0, sizeof(ts_start));
	memset(&ts_end, 0, sizeof(ts_end));
	printf("how many number do you want to sort(< 101), -1 to quit: \n");
	scanf("%d", &n);
	while(n > 0)
	{
		if(n > 100)
		{
			printf("you put the number too big\n");
			exit(1);
		}
		
		for(i = 0; i < n; i++)
		{
			list[i] = rand() % n;
		}
		printf("Before sort: \n");
		show_array(list, n);
		clock_gettime(CLOCK_REALTIME, &ts_start);
		slct_sort(list, n);
		clock_gettime(CLOCK_REALTIME, &ts_end);
		printf("cost time: %ld ms\n", (ts_end.tv_nsec - ts_start.tv_nsec) / 1000);
		printf("After sort: \n");
		show_array(list, n);
		printf("how many number do you want to sort(< 101), -1 to quit: \n");
		scanf("%d", &n);
	}
	
	
	return 0;
}


void show_array(int list[], int n)
{
	int i;
	int count = 0;
	
	for(i = 0; i < n; i++)
	{
		printf("%d\t", list[i]);
		if(count++ % 5 == 4)
			printf("\n");
	}
	printf("\n");
}