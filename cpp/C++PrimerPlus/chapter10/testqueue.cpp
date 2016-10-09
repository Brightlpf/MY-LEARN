#include <iostream>
#include "queue_bystack.h"
#include <cctype>

/*
class Queue{
	private:
		Stack s;
		Stack stemp;
	public:
		Queue();
		bool isempty() const;
		bool isfull() const;
		bool enqueue(const Item & item);
		bool dequeue(Item & item);
};
*/
using namespace std;

int main()
{
	Queue q;
	char ch;
	unsigned long lnum;
	
	cout << "Enter 'E' to join queue, 'D' to leave queue, 'Q' to quit.\n";
	while(cin >> ch && (toupper(ch) != 'Q'))
	{
		while(cin.get() != '\n')
			continue;
		
		switch(ch)
		{
			case 'E':
			case 'e':
				cout << "please input the number (long): ";
				cin >> lnum;
				cin.get();
				if(!q.enqueue(lnum))
				{
					cout << "join queue failed, try 'E'.\n";
				}
				else 
				{
					cout << "---->" << lnum << endl;
				}
				break;
			case 'D':
			case 'd':
				if(!q.dequeue(lnum))
				{
					cout << "dequeue failed, tyr 'E'.\n";
				}
				else
				{
					cout << "----->" << lnum << endl;
				}
				break;
			case 'Q':
			case 'q':
				break;
		}
		cout << "Enter 'E' to join queue, 'D' to leave queue, 'Q' to quit.\n";
	}
	cout << "Bye.\n";
	return 0;
}
