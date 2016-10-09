#include <iostream>
#include <string>

using namespace std;
const char DONE[] = "done";

int main()
{
	string str;
	static int count = 0;
	
	cout << "count the word: \n\n";
	cin >> str;
	while(str != DONE)
	{
		count++;
		cin >> str;
	}
	cout << "You entered a total of " << count << " words"<< endl;
	return 0;
}
