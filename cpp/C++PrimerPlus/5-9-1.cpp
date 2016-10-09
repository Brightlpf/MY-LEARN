#include <iostream>
using namespace std;

int main(void)
{
	int start;
	int end;
	int sum = 0;
	
	cout << "Enter a int: ";
	cin >> start;
	cout << "Enter another int: ";
	cin >> end;
	
	for(int i = start; i <= end; i++)
		sum += i;
	cout << "add from " << start << " to "<< end << " is : " << sum << endl;
	return 0;
}
