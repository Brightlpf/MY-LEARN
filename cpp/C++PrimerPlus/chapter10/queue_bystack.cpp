#include <iostream>
#include "queue_bystack.h"
using namespace std;
/*
	private:
		Stack s;
		Stack stemp;
	public:
		Queue();
		bool isempty() const;
		bool isfull() const;
		bool enqueue(const Item & item);
		bool dequeue(Item & item);
*/

Queue::Queue()
{
	cout << "Creat queue success.\n";
}

bool Queue::isempty() const
{
	return s.isempty();
}

bool Queue::isfull() const
{
	return s.isfull();
}

bool Queue::enqueue(const Item & item)
{
	if(s.isfull())
	{
		return false;
	}
	s.push(item);
	return true;
}

bool Queue::dequeue(Item & item)
{
	Item temp;
	if(s.isempty())
	{
		return false;
	}
	while(s.pop(temp))
	{
		stemp.push(temp);
	}
	stemp.pop(item);
	while(stemp.pop(temp))
	{
		s.push(temp);
	}
	return true;
}
