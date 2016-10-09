#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isplalindrome(const string & str);

int main()
{
	string str;
	cout << "please enter a string: (quit to quit)\n";
	while(str != "quit")
	{
		getline(cin, str);
		if(isplalindrome(str))
		{
			cout << "Yes. it is plalindrome.\n";
		}
		else
		{
			cout << "No, it's not plalindrome.\n";
		}
		cout << "Next: ";
	}
	
	return 0;
}

bool isplalindrome(const string & str)
{
	if(str.size() <= 1)
		return false;
	int len = str.size();
	string temp(len, 0);
	//reserve str
	for(int i = 0; i < len; i++)
	{
			temp[i] = str[len - i - 1];
	}
	cout << "[debug]str = " << str << "str size = " << str.size() << endl;	
	cout << "[debug]temp = " << temp << "temp size = " << temp.size() << endl;
	return temp == str;
}
