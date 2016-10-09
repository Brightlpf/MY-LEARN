#include <iostream>
#include <cstring>
#include <string>

using namespace std;
int main()
{
	#if 0
	char a1[40];
	char a2[20];
	
	cout << "Enter your first name: ";
	cin >> a1;
	cout << "Enter your last name: " << endl;
	cin >> a2;
	strcat(a1, ", ");
	strcat(a1, a2);
	cout << "Here is the information in a single string: " << a1 << endl;
	#else 
	string str1, str2;
	cout << "Enter your first name: ";
	cin >> str1;
	cout << "Enter your last name: " << endl;
	cin >> str2;
	cout << "Here is the information in a single string: " << str1 +", " + str2 << endl;
	#endif
	return 0;
}
