#include "msg.h"

int main(void)
{
	int msgid;
	struct msg_st rbuf;
	int ret;
	key_t key;
	
	//第一次运行创建文件
	if(access(PROJPATH, F_OK) < 0)
	{
		ret = open(PROJPATH, O_RDWR | O_CREAT, 0664);
		if(ret < 0)
		{
			perror("open PROJPATH");
			exit(1);
		}
	}
	//根据工程文件名和ID生成key
	if((key = ftok(PROJPATH, ID)) < 0)
	{
		perror("ftok");
		exit(1);
	}
	
	//创建消息队列
	if((msgid = msgget(key, IPC_CREAT | 0600)) < 0)
	{
		perror("msgget");
		exit(1);
	}
	
	//循环接收消息
	while(1)
	{
		if(msgrcv(msgid, &rbuf, sizeof(struct msg_st) - sizeof(long), 0, 0) < 0)
		{
			perror("msgrcv");
			exit(1);
		}
		//显示消息内容
		if(rbuf.m_type == MSGTYPE)
		{
			printf("name: %s\n", rbuf.m_name);
			printf("math : %d, chinese: %d\n", rbuf.m_math, rbuf.m_chinese);
		}
		printf("receive msg ok\n");
	}
	//删除消息队列
	msgctl(msgid, IPC_RMID, NULL);
	exit(0);
}
