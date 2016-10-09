#include "list.h"
#include <iostream>
using namespace std;

void show(Item & item);

int main()
{
	List list;
	Item item;

	cout << "Enter a unsigned long number(q to end): ";
	while(cin >> item)
	{
		list.add(item);
		if(list.isfull())
		{
			cout << "list is full" << endl;
			break;
		}
		cout << "next；";
	}
	list.visit(show);
	return 0;
}

void show(Item & item)
{
	cout << item << '\t';
}