#include <iostream>
#include <cstring>

using namespace std;
const char DONE[] = "done";

int main()
{
	char temp[40];
	static int count = 0;
	
	cout << "count the word: \n\n";
	cin >> temp;
	while(strcmp(DONE, temp) != 0)
	{
		count++;
		cin >> temp;
	}
	cout << "You entered a total of " << count << " words"<< endl;
	return 0;
}
