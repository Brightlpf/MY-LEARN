#include "Queue.h"
#include <iostream>
using namespace std;

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
	bool enqueue(const Item & item);
	bool dequeue(Item & item);
	int  getitems() const {return items;}
	Queue & operator=(const Queue & q);  // operator = 
};
*/
int main()
{
	cout << "************test default construct************"<< endl;
	{
		Queue q1;
		cout << "items: " << q1.getitems() << endl;
		if(q1.isempty())
		{
			cout << "q1 is empty." << endl;
		}
		cout << "called ~Queue()." << endl;
	}
	
	cout << "************test enqueue, qsize = 3 ************"<< endl;
	{
		Queue q2(3);
		cout << "debug : line " << __LINE__ << endl;
		Item Iarr[10] = {100UL, 200UL, 300UL};
		for(int i = 0; i < 5; i++)
		{
			if(q2.enqueue(Iarr[i]))
			{
				cout << "enqueue success. items = "<< q2.getitems() << " item = " << Iarr[i]<< endl;
			}
			else
			{
				cout << "enqueue failed." ;
				if(q2.isfull())
				{
					cout << "q2 is fulled." << endl;
				}
			}
		}
				
		Item temp;
		Queue q3 = q2;
		Queue q4(3);
		q4 = q2;
		cout << "************test dequeue, qsize = 3 ************"<< endl;
		for(int i = 0; i < 5; i++)
		{
			if(q2.dequeue(temp))
			{
				cout << "q2 dequeue success. items = "<<q2.getitems() << "item = " << temp << endl; 
			}
			else
			{
				cout << "q2 dequeue failed." << endl;
				if(q2.isempty())
				{
					cout << "q2 is empty." << endl;
				}
			}
		}
	
		cout << "************test copy construct ************"<< endl;
	
		//Queue q3 = q2;
		for(int i = 0; i < 5; i++)
		{
			if(q3.dequeue(temp))
			{
				cout << "q3 dequeue success. items = "<<q3.getitems() << "item = " << temp << endl; 
			}
			else
			{
				cout << "q3 dequeue failed." << endl;
				if(q3.isempty())
				{
					cout << "q3 is empty." << endl;
				}
			}
		}
		
		//Queue q4(3);
		//q4 = q2;
		cout << "************test operator=, qsize = 3 ************"<< endl; 
		for(int i = 0; i < 5; i++)
		{
			if(q4.dequeue(temp))
			{
				cout << "q4 dequeue success. items = "<<q4.getitems() << "item = " << temp << endl; 
			}
			else
			{
				cout << "q4 dequeue failed." << endl;
				if(q4.isempty())
				{
					cout << "q4 is empty." << endl;
				}
			}
		}
	}
	
	cout << "Bye." << endl;
	return 0;
}
