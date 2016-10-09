#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
	using namespace std;
	Stack st;
	char ch;
	unsigned long po;
	cout << "Please enter A to add a purchase order, \n"
	<< "P to process a PO, or Q to quit.\n";
	
	while(cin >> ch && toupper(ch)!= 'Q')
	{
		while (cin.get()!= '\n')
			continue;
		if(!isalpha(ch))
		{
			cout << "\a input err, please input again: ";
			continue;
		}
		switch(ch)
		{
			case 'A':
			case 'a':
				cout << "Enter a PO number to add: ";
				cin >> po;
				if(st.isfull())
				{
					cout << "Stack is fulled.\n";
				}
				else
					st.push(po);
				break;
			case 'P':
			case 'p':
				if (st.isempty())
				{
					cout << "Stack is empty.\n";
				}
				else
				{
					st.pop(po);
					cout << "PO #"<< po << "popped\n";
				}
				break;
			case 'c':
			case 'C':
			{
				Stack cpst = st;
				while(!cpst.isempty())
				{
					cpst.pop(po);
					cout << "po #" << po << "popped\n";
				}
				break;
			}
			case 'e':
			case 'E':
			{
				Stack eqst;
				eqst = st;
				while(!eqst.isempty())
				{
					eqst.pop(po);
					cout << "po #" << po << "popped\n";
				}
				break;
			}
		}
		cout << "Please enter A to add a purchase order, \n"
		<< "P to process a PO to quit.\n";
	}
	cout << "Bye\n";
	return 0;
}
