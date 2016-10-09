#include <iostream>
#include "14-3.h"

using namespace std;
int main()
{
	QueueTp<int> qt;
	
	cout << "Enqueue, enter number...q to quit.\n";
	int temp;
	
	while(cin >> temp)
	{
		qt.Enqueue(temp);
		cout << "next \n";
	}
	if(!cin)
		cin.clear();
	
	while(!qt.isEmpty())
	{
		qt.Dequeue(temp);
		cout << "temp = " << temp << endl;
	}	
	
	return 0;
	
}