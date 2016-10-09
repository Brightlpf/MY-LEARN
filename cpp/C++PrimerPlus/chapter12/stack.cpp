#include "stack.h"
#include <iostream>

/*
class Stack{
private:
	enum {MAX = 10};
	Item * pitems;
	int size;
	int top;
public:
	Stack(int n = MAX);
	Stack(const Stack &st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item &item);
	bool pop(Item &item);
	Stack &operator=(const Stack &st);
};

*/

Stack::Stack(int n)
{
	pitems = new Item[n]; 
	size = n;
	top = 0;
}

Stack::Stack(const Stack &st)
{
	pitems = new Item[st.size];
	size = st.size;
	top = 0;
	for(int i = 0; i < st.top; i++)
	{
		push(st.pitems[i]);
	}
}

Stack::~Stack()
{
	delete [] pitems;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == size;
}

bool Stack::push(const Item &item)
{
	if(isfull())
	{
		return false;
	}
	pitems[top++] = item;
	return true;
}

bool Stack::pop(Item &item)
{
	if(isempty())
	{
		return false;
	}
	item = pitems[--top];
	return true;
}

Stack & Stack::operator=(const Stack &st)
{
	if(&st == this)
		return *this;
	delete [] pitems;
	pitems = new Item[st.size];
	size = st.size;
	for(int i = 0; i < st.top; i++)
	{
		push(st.pitems[i]);
	}
	return *this;
}
