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
	
	for(vector<string>::iterator i = vs.begin(); i != vs.end(); ++i)
	{
		for(string::iterator j = (*i).begin(); j != (*i).end(); ++j)
		{
			(*j) = toupper(*j);
		}
	}
	
	for(vector<string>::iterator i = vs.begin(); i != vs.end(); ++i)
	{
		if((i - vs.begin()) % 8 == 0)
		{
			cout << endl;
		}
		cout << *i << "\t";
		
	}
	cout << endl;
	
	return 0;
}
