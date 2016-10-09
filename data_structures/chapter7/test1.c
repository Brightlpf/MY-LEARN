#include "sort.h"
#include <stdlib.h>
#include <time.h>
#define SIZE 10000

int main(void)
{
	//clock_t start;
	struct timespec start;
	struct timespec end;
	
	Element arr[SIZE];
	int i;
	int index, key;
	
	srand(time(NULL));
	for(i = 0; i < SIZE; i++)
		arr[i].key = rand() % SIZE;
	
	key = rand() % SIZE;
	clock_gettime(CLOCK_REALTIME, &start);
	index = seqSearch(arr, key, SIZE);
	clock_gettime(CLOCK_REALTIME, &end);
	printf("seqSearch: time = %dus\n", (end.tv_nsec - start.tv_nsec)/1000);
	if(index == -1)
	{
		printf("not found!\n");
	}
	else
		printf("find it , index = %d\n", index);
	
	sort(arr, SIZE);
	//start = clock();
	clock_gettime(CLOCK_REALTIME, &start);
	index = binSearch(arr, key, SIZE);
	clock_gettime(CLOCK_REALTIME, &end);
	printf("binSearch: time = %dus\n", (end.tv_nsec - start.tv_nsec)/1000);
	
	return 0;
}
