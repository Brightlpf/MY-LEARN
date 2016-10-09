#include  "msg.h"
#include <string.h>
#include <time.h>

int main(void)
{
	struct msg_st wbuf;
	key_t key;
	int msgid;
	
	//获取key
	if((key = ftok(PROJPATH, ID)) < 0)
	{
		perror("ftok");
		exit(1);
	}
	//获取msgid
	if((msgid = msgget(key, 0)) < 0)
	{
		perror("msgget");
		exit(1);
	}
	printf("msgid = %d\n", msgid);
	//初始化消息内容，发送消息
	srand(time(NULL));
	wbuf.m_type = MSGTYPE;
	strcpy(wbuf.m_name, "lpf");
	wbuf.m_math = rand()%100;
	wbuf.m_chinese = rand()%100;
	if(msgsnd(msgid, &wbuf, sizeof(wbuf) - sizeof(long), 0) < 0)
	{
		perror("msgsnd");
		exit(1);
	}
	printf("send msg ok\n");
	
	exit(0);
}
