#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
	using namespace std;
	Stack st;
	char ch;
	Item po;
	double sum = 0.0;
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
				cout << "Enter customer name: ";
				cin.get(po.fullname, 35);
				cout << "customer payment: ";
				cin >> po.payment;
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
					sum += po.payment;
					cout << "PO #"<< po.fullname << "popped\n";
				}
				break;
		}
		cout << "Please enter A to add a purchase order, \n"
		<< "P to process a PO to quit.\n";
	}
	cout << "today, total make money: $" <<sum << endl; 
	cout << "Bye\n";
	return 0;
}
