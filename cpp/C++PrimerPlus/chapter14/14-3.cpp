#include <iostream>
#include "14-3.h"
#include <cstring>

using namespace std;
/*
class Worker{
private:
	std::string fullname;
	long id;
public:
	Worker(): fullname("no one"), id(0){}
	Worker(const std::string f, long i) : fullname(f), id(i){}
	void Show() const;
	void Set(std::string, long i);
};
*/

void Worker::Show() const
{
	cout << "name: " << fullname << endl;
	cout << "id: " << id << endl;
}

void Worker::Set(const std::string & fn, long i)
{
	fullname = fn;
	id = i;
}

void getworker(Worker & wk);
void showworker(Worker * pwk);

int main()
{
	QueueTp<Worker *> qt;
	
	cout << "Enter worker's number: ";
	int workers;
	cin >> workers;
	
	Worker workerin[workers];
	Worker * workerout;
	char ch;
	int countin = 0;
	
	cout << "Enter e to enqueue, d to dequeue, q to quit.\n";
	while(cin >> ch && (strchr("EeDd", ch) != NULL))
	{
		while(cin.get() != '\n')
			continue;
		switch(ch)
		{
			case 'E':
			case 'e':
				if(countin == workers)
				{
					cout << "workers is full.\n";
					continue;
				}
				getworker(workerin[countin]);
				qt.Enqueue(&workerin[countin]);
				countin++;
				break;
			case 'D':
			case 'd':
				if(countin == 0)
				{
					cout << "Wokers is empty.\n";
					continue;
				}
				qt.Dequeue(workerout);
				showworker(workerout);
				countin--;
				break;
				
			default:
				break;
		}
		cout << "Enter e to enqueue, d to dequeue, q to quit.\n";
	}
	
	cout << "Bye." << endl;
	return 0;
}

void getworker(Worker & wk)
{
	string name;
	long id;
	
	cout << "Enter the worker's name: ";
	getline(cin, name);

	cout << "Enter the worker's id: ";
	cin >> id;
	wk.Set(name, id);
	
}

void showworker(Worker * pwk)
{
	pwk->Show();
}








