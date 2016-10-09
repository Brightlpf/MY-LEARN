#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;
	
	fin.open("tobuy.txt");
	if(!fin.is_open())
	{
		cout << "open tobuy.txt failed.\n";
		exit(EXIT_FAILURE);
	}
	
	int count = 0;
	string item;
	getline(fin, item, ':');
	while(fin)
	{
		cout << ++count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done\n";
	fin.close();
	
	return 0;
}