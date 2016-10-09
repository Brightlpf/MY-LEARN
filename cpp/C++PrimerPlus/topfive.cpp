#include <iostream>
#include <string>

using namespace std;
const int SIZE = 5;
void displaylist(string list[], int size);

int main()
{
	string str[SIZE];
	
	cout << "Enter your 5 favorite astronomical sights:"<< endl;
	for(int i = 0; i < SIZE; i++)
	{
		cout << i+1 <<": ";
		getline(cin, str[i]);
	}
	cout << "Your list:"<< endl;
	displaylist(str, SIZE);
	return 0;
}

void displaylist(string list[], int size)
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << ": ";
		cout << list[i] << endl;
	}
}
