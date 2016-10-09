#include <iostream>
#include "list.h"
using namespace std;

/*
class List{
private:
	static const int MAX = 10;
	Item items[MAX];
	int index;
public:
	List();
	bool add(const Item & item);
	bool isempty() const;
	bool isfull() const;
	void visit(void (*pf)(Item &));
};

*/

List::List()
{
	index = 0;
	cout << "creat empty list success.\n";
}

bool List::add(const Item &item)
{
	if(isfull())
	{
		return false;
	}
	items[index++] = item;
	return true;
}

bool List::isempty() const
{
	return index == 0;
}

bool List::isfull() const
{
	return index == MAX;
}

void List::visit(void (*pf)(Item &))
{
	if(isempty())
	{
		cout << "list empty.\n";
		return;
	}
	for(int i = 0; i < index; )
	{
		pf(items[i]);
		if(++i%5 == 0)
			cout << '\n';
	}
	cout << endl;
}
