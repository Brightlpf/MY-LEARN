#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
void show(const string & str);

int main()
{
	list<string> mat_friend;
	list<string> pat_friend;
	
	string tempname;
	cout << "Hello Mat, Please Enter your friend's name: quit to end\n";
	while(getline(cin, tempname) && tempname != "quit")
	{
		mat_friend.push_back(tempname);
		cout << "next: ";
	}
	cout << "your friends: \n";
	mat_friend.sort();
	for_each(mat_friend.begin(), mat_friend.end(), show);
	cout << "\nHello Pat, Please Enter your friend's name: quit to end\n";
	while(getline(cin, tempname) && tempname != "quit")
	{
		pat_friend.push_front(tempname);
		cout << "next: ";
	}
	cout << "your friends: \n";
	pat_friend.sort();
	for_each(pat_friend.begin(), pat_friend.end(), show);
	cout << endl;
	
	cout << "Merger Pat and Mat: \n";
	mat_friend.merge(pat_friend);
	mat_friend.unique();
	list<string> mat_pat(mat_friend.begin(), mat_friend.end());
	for_each(mat_pat.begin(), mat_pat.end(), show);
	cout << endl;
	
	return 0;
}

void show(const string & str)
{
	static int count = 0;
	
	cout << str << " ";
	if(++count % 5 == 0)
		cout << endl;
}