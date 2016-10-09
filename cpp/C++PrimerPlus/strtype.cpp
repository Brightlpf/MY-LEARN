#include <iostream>
#include <string>
#include <cstring>

int main()
{
	using namespace std;
	
	string str1 = "Hello world!";
	string str2, str3, str4;
	
	str2 = str1;
	cout << "str2 = " << str2 << endl;
	
	str3 = str1 + str2 + "Welcom...";
	cout << "str3 = " << str3 << endl;
	
	cout << "Enter a str4" << endl;
	cin >> str4;
	str4 += " Have a good day!";
	cout << "str4 = " << str4 << endl
	
	//cout << R"( Jim "King" Tutt uses "\n" instead of endl.)" << endl;
	return 0;
}
