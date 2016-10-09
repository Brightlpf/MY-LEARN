#include <iostream>
#include <cstring>
#include "14-4.h"
const int SIZE = 4;


int main()
{
	using namespace std;
	
	Person * lolas[SIZE];
	
	int ct;
	for(ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the Person category: \n"
			 << "g:Gunslinger "
			 << "p: PokerPlayer b: BadDude q: quit\n";
		cin >> choice;
		while(strchr("pgbq", choice) == NULL)
		{
			cout << "Please enter p g b or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch(choice)
		{
			case 'b':
			{
				Card c;
				lolas[ct] = new BadDude((string)"BadGuy", 8, 0.0, c);
				break;
			}
				
			case 'g':
				lolas[ct] = new Gunslinger((string)"Gunslinger", 10, 0.0);
				break;
			case 'p':
			{
				Card c;
				lolas[ct] = new PokerPlayer((string)"PokerPlayer", c);
				break;
			}
		}
		cin.get();
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