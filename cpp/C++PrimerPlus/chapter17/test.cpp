#include <iostream>
#include <string>

const std::string &shorterString(const std::string & , const std::string &);
std::string &shorterString(std::string & , std::string &);
int main()
{
	using namespace std;
	cout << "enter two strings seperated by space" << endl;
	string string1, string2;
	const string s1{"hello"}, s2{"world"};
	cout << shorterString(s1, s2) << endl;
	cin >> string1 >> string2;
	cout << shorterString(string1, string2) << endl;

	return 0;
}

const std::string &shorterString(const std::string &s1, const std::string &s2)
{
	std::cout << "const" << std::endl;
	return s1.size() < s2.size() ? s1 : s2;	
}

std::string &shorterString(std::string &s1, std::string &s2)
{
	using std::string;
	using std::cout;
	using std::endl;

	cout << "reload right!" << endl;
	auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));	
	return const_cast<string &>(r);
}
