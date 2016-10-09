#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void mytoupper(string & str);

int main()
{
	string str;
	cout << "Enter a string (q to quit): ";
	
	while(getline(cin, str) && str[0] != 'q')
	{
		mytoupper(str);
		cout << str << endl;
		cout << "Next string (q to quit): ";
	}
	return 0;
}

void mytoupper(string &str)
{
	for(int i = 0; str[i] != 0; i++)
	{
		str[i] = toupper(str[i]);
	}
}
