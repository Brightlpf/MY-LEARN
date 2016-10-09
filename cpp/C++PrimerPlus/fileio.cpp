#include <iostream>
#include <cstring>
#include <fstream>  //include  file stream

using namespace std;

const char DONE[10] = "done";
int main(void)
{
	char temp[80];
	ofstream outfile;
	int age;
	char answer[10];
	
	outfile.open("outfile.txt");// relation file
	//input information
	cout << "Enter name and age, 'done' to quit." << endl;
	cout << "name: ";
	cin.getline(temp, 80);
	while(strcmp(DONE, temp) != 0)
	{
		cout << "age: ";
		
		while(!(cin >> age))
		{
			cin.clear();
			while(cin.get() != '\n')//skip \n
			continue;
			cout << "Please enter a interger: ";
		}
		while(cin.get() != '\n')//skip \n
			continue;
		
		cout << "save it (yes or no): "<< endl;
		cin >> answer;
		while(cin.get() != '\n')//skip \n
			continue;
		if(strcmp("yes", answer) == 0)
		{
			outfile << temp <<"\t"<< age << endl;
			cout << "save ok!"<< endl;
		}
		cout << "name: ";
		cin.getline(temp, 80);
	}
	outfile.close();
	return 0;
	
}
