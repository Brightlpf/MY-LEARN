#include <iostream>
#include "Queue.h"
#include <cstring>
/*
class Queue{
private:
	struct Node {Item m_item; Node * next;};
	static const int QSIZE = 10;
	
	int items;  //current queue items
	const int qsize;
	Node * front;
	Node * rear;
public:
	Queue(int qs = QSIZE); //default construct
	Queue(const Queue & q); //copy construct
	~Queue();
	
	bool isempty() const;
	bool isfull() const;
	bool enqueue(const Node & node);
	bool dequeue(Node & node);
	int  getitems() const {return items;}
	Queue operator=(const Queue & q);  // operator = 
};

*/
using std::cout;
using std::endl;

Queue::Queue(int qs) : qsize(qs)
{
	items = 0;
	front = rear = NULL;
}

Queue::Queue(const Queue &q):qsize(q.qsize)
{
	Node * pq = q.front;
	
	front = rear = NULL;
	items = 0;
	while(pq)
	{	
/*   这种方法不可行， 因为重新申请空间的时候，链表就断开了
		//申请新节点空间并赋值
		current = new Node;
		//memcpy(current->m_item, pq->m_item);
		current->m_item = pq->m_item;
		current->next = NULL;
		//设置队列首节点
		if(pq == q.front)
		{
			front = current;
		}
		//设置队列尾节点
		if(pq == q.rear)
		{
			rear = current;

		}
		//移动到下一个节点
		pq = pq->next;
		current = current->next;	
*/
		enqueue(pq->m_item);
		pq = pq->next;
	}
}

Queue::~Queue()
{
	Node * current = front;
	Node * temp;
	
	while(current != NULL)
	{
		temp = current;
		delete current;
		current = temp->next;
	}
	items = 0;
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

bool Queue::enqueue(const Item & item)
{
	if(isfull())
	{
		return false;
	}
	//新建节点，赋值
	Node * current = new Node;
	current->m_item = item;
	current->next = NULL;
	//cout << "debug : line " << __LINE__ << endl;
	//如果队列为空
	if(rear == NULL)
	{
		front = rear = current;
	}
	else
	{
		rear->next = current;
		//设置尾节点
		rear = current;
	}	
	
	items++;
	
	return true;
}

bool Queue::dequeue(Item & item)
{
	if(isempty())
	{
		return false;
	}
	
	Node * current = front;
	if(current == NULL)
		cout << "current is null."<< endl;
	front = current->next;
	if(current == rear)
	{
		rear = NULL;
	}
	item = current->m_item;
	delete current;
	items--;
	return true;
}

Queue & Queue::operator=(const Queue & q)  // operator = 
{
	if(&q == this)
		return *this;
	this->~Queue(); //是否可以这样处理？
	//qsize 如何处理？
	Node * pq = q.front;
	while(pq != NULL)
	{
		enqueue(pq->m_item);
		pq = pq->next;
	}
	
	return *this;
}
