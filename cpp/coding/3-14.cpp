#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> vs;
	string temp;
	cout << "Please enter a text: " << endl;
	while(cin >> temp)
	{
		vs.push_back(temp);
	}
	
	for(vector<string>::size_type i = 0; i != vs.size(); ++i)
	{
		for(string::size_type j = 0; j != vs[i].size(); ++j)
		{
			vs[i][j] = toupper(vs[i][j]);
		}
	}
	
	for(vector<string>::size_type i = 0; i != vs.size(); ++i)
	{
		cout << vs[i] << "\t";
		if((i + 1) % 8 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
	
	return 0;
}
