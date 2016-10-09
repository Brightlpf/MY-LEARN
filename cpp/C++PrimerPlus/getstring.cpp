#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	
	int const SIZE = 20;
	char name[SIZE];
	char adress[SIZE];
	
	cout <<"Enter your name: " << endl;
	//cin.getline(name, SIZE);
	cin.get(name, SIZE).get();
	cout << "Enter your adress: " << endl;
	//cin.getline(adress, SIZE);
	cin.get(adress, SIZE);
	cout << "Your name is " << name << endl;
	cout << "Your adress is " << adress << endl;
	return 0;
}
