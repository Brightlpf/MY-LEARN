#include <iostream>

using namespace std;

struct Pizza {
	char company[40];
	float dia;
	float weight;
};

int main(void)
{
	Pizza *p;
	
//alloc memory
	p = new Pizza;
//get input
	cout << "Enter pizza's dia: ";
	cin >> p->dia;
	cin.get();
	cout << "Enter pizza'a company: ";
	cin.get(p->company, 40);
	cin.get();
	cout << "Enter pizza's weight: ";
	cin >> p->weight;
//display
	cout << "company: " << p->company << endl;
	cout << "weight: " << p->weight << endl;
	cout << "dia: " << p->dia << endl;
//free memory
	delete p;
	
	return 0;
}
