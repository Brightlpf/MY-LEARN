#include <stdlib.h>
#include <pthread.h>

struct job{
	struct job *j_next;
	struct job *j_prev;
	pthread_t  j_id;
	/********/
};

struct queue{
	struct job *q_head;
	struct job *q_tail;
	pthread_rwlock_t q_lock;
};

/*init a queue*/

int queue_init(struct queue *qp)
{
	int err;
	
	qp->q_head = NULL;
	qp->q_tail = NULL;
	err = pthread_rwlock_init(&qp->q_lock, NULL);
	if(err != 0)
		return err;
	return 0;
}

/*insert a job at the head of the queue*/
void job_insert(struct queue *qp, struct job *jp)
{
	pthread_rwlock_wrlock(&qp->q_lock);
	jp->j_next = qp->q_head;
	jp->j_prev = NULL;
	if(qp->head != NULL)
	{
		qp->head->j_prev = jp;
	}
	else
	{
		qp->tail = jp;
	}
	qp->q_head = jp; 
	pthread_rwlock_unlock(&qp->q_lock);
}

/*append a job on the tail of the queue*/

void job_append(struct queue *qp, struct job *jp)
{
	pthread_rwlock_wrlock(&qp->lock);
	jp->j_prev = qp->tail;
	jp->j_next = NULL;
	if(qp->q_tail != NULL)
		qp->q_tail->j_next = jp;
	else
		qp->q_head = jp;
	qp->q_tail = jp;
	pthread_rwlock_unlock(&qp->lock);
}

/*remove the given job from a queue*/
void job_remove(struct queue *qp, struct job *jp)
{
	pthread_rwlock_wrlock(&qp->q_lock);
	
	if(jp == qp->q_head)
	{
		qp->q_head = jp->j_next;
		if(qp->q_tail == jp)
		{
			qp->q_tail = NULL;
		}
		else
		{
			jp->j_next->j_prev = NULL;
		}
	}
	else if(jp == qp->q_tail)
	{
		qp->q_tail = jp->j_prev;
		
		/* becase jp != qp->q_head
		
		if(qp->q_head == jp)
		{
			qp->q_head = NULL;
		}
		else
		{
			jp->j_prev->j_next = NULL;
		}
		*/
		jp->j_prev->j_next = NULL;
	}
	else
	{
		jp->j_prev->j_next = jp->j_next;
		jp->j_next->j_prev = jp->j_prev;
	}
	pthread_rwlock_unlock(&qp->q_lock);
}

/*find a job for the given thread id*/
struct job * job_find(struct queue *qp, pthread_t id)
{
	struct job *jp;
	jp = qp->q_head;
	
	if(pthread_rwlock_rdlock(&qp->q_lock)!= 0)
		return (NULL);
	
	while((!pthread_equal(jp->j_id, id))&&(jp != NULL))
	{
		jp = jp->j_next;
	}
	pthread_rwlock_unlock(&qp->q_lock);
	
	return (jp);
}

