#include "customer.h"

typedef  Customer Item;
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
	bool enqueue(const Item & item);
	bool dequeue(Item & item);
	int  getitems() const {return items;}
	Queue & operator=(const Queue & q);  // operator = 
};
