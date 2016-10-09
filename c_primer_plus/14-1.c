#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define IN_MAX 20
#define MONTH 12

#define isLeapYear(year) (year % 400 == 0)||(year % 4 == 0 && year % 100 !=0)? 1:0

typedef struct
{
	char name[IN_MAX];
	char sim_name[IN_MAX/2];
	int days;
	int no;
} Month;

Month g_month[2][MONTH] =
{
	{
		{"January", "Jan", 31, 1},
		{"February", "Feb", 28, 2},
		{"March", "Mar", 31, 3},
		{"April", "Apr", 30, 4},
		{"May", "May", 31, 5},
		{"June", "Jun", 30, 6},
		{"July", "Jul", 31, 7},
		{"August", "Aug", 31, 8},
		{"September", "Sep", 30, 9},
		{"October", "Oct", 31, 10},
		{"November", "Nov", 30, 11},
		{"December", "Dec", 31, 12}
	},
	{
		{"January", "Jan", 31, 1},
		{"February", "Feb", 29, 2},
		{"March", "Mar", 31, 3},
		{"April", "Apr", 30, 4},
		{"May", "May", 31, 5},
		{"June", "Jun", 30, 6},
		{"July", "Jul", 31, 7},
		{"August", "Aug", 31, 8},
		{"September", "Sep", 30, 9},
		{"October", "Oct", 31, 10},
		{"November", "Nov", 30, 11},
		{"December", "Dec", 31, 12}
	}
};

	
int getdays(int year, int month, int day);
int parsedate(const char *date, char *year, char *month, char *day);
	
int main(void)
{
	char input[IN_MAX];
	int idays;
	int imonths;
	int iyears;
	char cday[10];
	char cmonth[10];
	char cyear[10];
	int result = 0;
	int ret;
	
	printf("input date like[2015-08-18] ,return the total days from 1970-01-01.\n");
	while(fgets(input, IN_MAX -1, stdin) != NULL)
	{
		//字符串解析，分别获得年、月、日的字符串
		ret = parsedate(input, cyear, cmonth, cday);
		if(ret != 0)
		{
			fprintf(stderr, "parse date error.\n");
			exit(EXIT_FAILURE);
		}
		
		iyears = atoi(cyear);
		imonths = atoi(cmonth);
		idays = atoi(cday);
		
		result = getdays(iyears, imonths, idays);
		printf("From 1970-01-01 to %s have %d days.\n", input, result);

	}
	puts("Done.\n");
	
	return 0;
}

int getdays(int year, int month, int day)
{
	int sum = 0;
	int i;

	if(year < 1970 || month < 1 || month > 12 ||day < 0 || day > 31)
	{
		fprintf(stderr, "date error.\n");
		return -1;
	}
	//计算年
	for(i = 1970; i < year; i++)
	{
		if(isLeapYear(i))
		{
			sum += 366;
		}
		else
		{
			sum += 365;
		}
	}
	//计算月
	for(i = 0; i < month - 1; i++)
	{
		sum += g_month[isLeapYear(year)][i].days;
	}
	//计算日
	sum += day;
	
	return sum;
}

int parsedate(const char *date, char *year, char *month, char *day)
{
	
	if(NULL == date || NULL == year || NULL == month || NULL == day )
	{
		//fprintf(stderr, "parse date error.\n");
		return -1;
	}
	//parse year
	while(*date != '-'&& *date != '\0')
	{
		if(isspace(*date))
		{
			date++;
			continue;
		}
		*year++ = *date++;
	}
	if(*date == '\0')
	{
		fprintf(stderr, "parse year error.\n");
		return -1;
	}
	*year = '\0';
	date++; //skip '-'
	
	// parse month
	while(*date != '-'&& *date != '\0')
	{
		if(isspace(*date))
		{
			date++;
			continue;
		}
		*month++ = *date++;
	}
	if(*date == '\0')
	{
		fprintf(stderr, "parse year error.\n");
		return -1;
	}
	*month = '\0';
	date++; //skip '-'
	
	//parse day
	while(*date != '\0')
	{
		if(isspace(*date))
		{
			date++;
			continue;
		}	
		*day++ = *date++;
	}
	*day = '\0';

	return 0;
}
