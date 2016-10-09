#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


//日历时间、分解时间、用户可读时间
int main(void)
{
	time_t cal_time;
	struct tm  *tm_time;
	struct tm  *utc_time;
	char buf[64];
	
	time(&cal_time);
	tm_time = localtime(&cal_time);
	utc_time = gmtime(&cal_time);
	
	strftime(buf, 64, "local time :%r, %a %b %d, %Y ", tm_time);
	puts(buf);
	
	strftime(buf, 64, "gmt time: %r, %a %b %d, %Y ", utc_time);
	puts(buf);
	exit(0);
}
