#ifndef _MSG_H_
#define _MSG_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/msg.h>
#include <errno.h>

#define NAMESIZE 32

#define MSGTYPE 100
//定义项目名和id，用于生成key
#define PROJPATH	"/tmp/msgtest"
#define ID	123
//定义消息结构
struct msg_st{
	long m_type;
	char m_name[NAMESIZE];
	int m_math;
	int m_chinese;
};

#endif
