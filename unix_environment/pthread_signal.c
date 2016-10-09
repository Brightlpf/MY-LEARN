
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>

/*
#include <apue.h>
#include <pthread.h>
*/
void sig_proc(int signo);
void * thr_fn(void * arg);
volatile int quitflag;
sigset_t  oldmask;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t waitc = PTHREAD_COND_INITIALIZER;

int main(void)
{
	struct sigaction act, oact;
	sigset_t newmask, zeromask;
	pthread_t tid;
	int err;
	
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	sigaddset(&newmask, SIGINT);
	sigemptyset(&zeromask);
	
	act.sa_handler = sig_proc;
	act.sa_mask = zeromask;
	act.sa_flags = 0;
	if(sigaction(SIGINT, &act, &oact)< 0)
	{
		printf("sigaction SIGINT error\n");
		exit(1);
	}
	if(sigaction(SIGQUIT, &act, &oact)< 0)
	{
		printf("sigaction SIGINT error\n");
		exit(1);
	}
	
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
	{
		printf("SIG_BLOCK error!\n");
		exit(1);
	}
	if((err = pthread_create(&tid, NULL, thr_fn, NULL)) != 0)
	{
		printf("pthread create error!\n");
		exit(1);
	}
	pthread_join(tid, NULL);
	
	quitflag = 0;
	sigprocmask(SIG_SETMASK, &oldmask, NULL);
	printf("program exit...\n");
	exit(0);
}

void * thr_fn(void* arg)
{
	if(sigprocmask(SIG_SETMASK, &oldmask, 0) !=0 )
	{
		printf("SIG_SETMASK error\n");
		exit(1);
	}

	pthread_mutex_lock(&lock);
	while(quitflag == 0)
		pthread_cond_wait(&waitc, &lock);
	pthread_mutex_unlock(&lock);
	
	pthread_exit(0);
}

void sig_proc(int signo)
{
	pthread_mutex_lock(&lock);
	if(signo == SIGQUIT)
	{
		printf("receive SIGQUIT\n");
		quitflag = 1;
	}
	else if(signo == SIGINT)
	{
		printf("interrupt\n");
	}
	pthread_mutex_unlock(&lock);
	pthread_cond_signal(&waitc);
}
