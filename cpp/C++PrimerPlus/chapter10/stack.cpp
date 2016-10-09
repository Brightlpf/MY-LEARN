#include "stack.h"
#include <iostream>
/*
	private:
		enum {MAX = 10};
		int top;
		Item item[MAX];
	public:
		Stack();
		bool isempty() const;
		bool isfull() const;
		bool push(const Item & item);
		bool pop(Item & item);
*/

using namespace std;
Stack::Stack()
{
	top = 0;
	cout << "creat stack success." << endl;
}

bool Stack::isempty() const
{
	return top <= 0;
}

bool Stack::isfull() const
{
	return top >= MAX;
}

bool Stack::push(const Item &it)
{
	if(isfull())
	{
		return false;
	}
	item[top++] = it;
	return true;
}

bool Stack::pop(Item &it)
{
	if(isempty())
	{
		return false;
	}
	it = item[--top];
	return true;
}
