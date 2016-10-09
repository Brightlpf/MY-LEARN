#include <iostream>
using namespace std;

const int MAX = 5;
int main()
{
	float score[MAX];
	float sum = 0.0;
	
	cout << "Please enter your golf scores." << endl;
	cout << "You must enter "<< MAX << " rounds."<< endl;
	
	
	for(int count = 0; count < MAX; count++)
	{
		cout << "round #"<< count + 1 << ": ";
		while(!(cin>> score[count]))
		{
			cin.clear();// clear error
			while(cin.get() != '\n')
				continue;
			cout << "Please enter a number: ";
		}
	}
	
	for(int i = 0; i < MAX; i++)
	{
		sum += score[i];
	}
	cout << sum/MAX << " = average socre "<< MAX << "rounds"<< endl;
	return 0;
	
}
