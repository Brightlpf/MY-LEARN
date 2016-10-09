/*
class Worker{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker(): fullname("no one"), id(0){}
	Worker(const std::string f, long i) : fullname(f), id(i){}
	virtual ~Worker() = 0;
	virtual void Show() const = 0;
	virtual void Set() = 0;
};
#include <iostream>
#include <cstring>
#include "14-3.h"
const int SIZE = 5;

int main()
{
	using namespace std;
	
	Worker * lolas[SIZE];
	
	int ct;
	for(ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category: \n"
			 << "W: waiter s:singer "
			 << "t: singing waiter q: quit\n";
		cin >> choice;
		while(strchr("wstq", choice) == NULL)
		{
			cout << "Please enter w s t or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch(choice)
		{
			case 'w':
				lolas[ct] = new Waiter;
				break;
			case 's':
				lolas[ct] = new Singer;
				break;
			case 't':
				lolas[ct] = new SingingWaiter;
				break;
		}
		cin.get();
		lolas[ct]->Set();
	}
	cout << "\nHere is your staff: \n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	cout << "Bye.\n";
	return 0;
}
*/

#ifndef _14_3_H_
#define _14_3_H_

#include <string>

class Worker{
private:
	std::string fullname;
	long id;
public:
	Worker(): fullname("no one"), id(0){}
	Worker(const std::string f, long i) : fullname(f), id(i){}
	void Show() const;
	void Set(const std::string & name, long i);
};

template <typename T>
class QueueTp
{
private:
	struct Node {T m_item; Node * next;};
	enum {MAX = 10};
	const int qsize;
	
	int items;
	Node * front;
	Node * rear;
	
public:
	QueueTp(int size = MAX);
	~QueueTp();
	bool isEmpty() const;
	bool isFull() const;
	bool Enqueue(const T & item);
	bool Dequeue(T & item);
};

template <typename T>
QueueTp<T>::QueueTp(int size) :qsize(size)
{
	items = 0;
	front = rear = NULL;
}

template <typename T>
QueueTp<T>::~QueueTp()
{
	Node * current;
	while(front)
	{
		current = front->next;
		delete front;
		front = current;
	}
}

template <typename T>
bool QueueTp<T>::isEmpty() const
{
	return items == 0;
} 

template <typename T>
bool QueueTp<T>::isFull() const
{
	return items == MAX;
}

template <typename T>
bool QueueTp<T>::Enqueue(const T & item)
{
	Node * current;
	if(isFull())
		return false;
	
	current = new Node;
	current->m_item = item;
	current->next = NULL;
	if(rear == NULL)
	{
		front = rear = current;
	}
	else
	{
		rear->next = current;
		rear = current;
	}
	items++;
	return true;
}

template <typename T>
bool QueueTp<T>::Dequeue(T & item)
{
	if(isEmpty())
		return false;
	
	item = front->m_item;
	items--;
	if(front->next == NULL)//ONLY ONE
	{
		rear = NULL;
	}
	else
	{
		front = front->next;
	}
	
	return true;
}

#endif
