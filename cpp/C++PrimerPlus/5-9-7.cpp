#include <iostream>
#include <string>
using namespace std;

struct Car {
	string maker;
	int year;
};

int main(void)
{
	int ncars;
	
	cout << "How many cars do you wish to catalog?" << endl;
	cin >> ncars;
	cin.get();
	Car *pcar = new Car [ncars];
	
	for(int i = 0; i < ncars; i++)
	{
		cout << "Car #" << i + 1 << ":"<< endl;
		cout << "Please enter the make: ";
		getline(cin, pcar[i].maker);
		cout << "Please enter the year made：";
		cin >> pcar[i].year;
		cin.get();
	}
	
	cout << "Here is your colecotion: "<< endl;
	for(int i = 0; i < ncars; i++)
	{
		cout << pcar[i].year << "\t"<< pcar[i].maker<< endl;
	}
	delete [] pcar;
	return 0;
}
