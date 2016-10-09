#include <iostream>
#include "workermi.h"
using namespace std;

Worker::~Worker() {}

//protected methods
void Worker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
	//cout << "Enter worker's name: ";
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while(cin.get() != '\n')
		continue;
}


//Waiter methods
Waiter::~Waiter(){}

void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "Category: waiter\n";
	Worker::Data();
	Data();
}
//protected methods
void Waiter::Data() const
{
	cout << "panache rating: " << panache << endl;
}

void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while(cin.get() != '\n')
		continue;
}

//Singer methods
char * Singer::pv[] = {"other", "alto", "contralto", 
	"soprano", "bass", "baritone", "tenor"};
	
void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Data();
	Data();
}

//protected methods
void Singer::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "Enter the vocal range: ";
	int i;
	for(i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << "	";
		if(i % 4 == 3)
			cout << endl;
	}
	if(i % 4 != 0)
		cout << '\n';
	cin >> voice;
	while(cin.get() != '\n')
		continue;
}

//SingingWaiter methods
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Singer::Get();
	Waiter::Get();
}

void SingingWaiter::Set()
{
	cout << "Enter the SingingWaiter's name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "Category: SingingWaiter\n";
	Worker::Data();
	Data();
}
