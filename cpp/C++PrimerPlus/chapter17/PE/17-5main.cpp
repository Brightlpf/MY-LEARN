#include <cstdlib>
#include "17-5.h"

void showMenu();
const int MAX = 10;
const char * pdata  = "employee.dat";

int main()
{
	using namespace std;
	abstr_emp * pemp[MAX];
	
	int emptype;
	int emp_count = 0;
	ifstream fin(pdata);
	
	if(fin.is_open())
	{
		for(int i = 0; i < MAX; i++)
		{
			fin >> emptype;
			if(fin.bad())
			{
				cerr << "read file type wrong" << endl;
				exit(1);
			}
			if(!fin.eof())
			{
				/*enum emp_type{EMPLYEE, MANAGER, FINK, HIGHFINK};*/
				switch(emptype)
				{
					case EMPLYEE:
						pemp[i] = new employee;
						pemp[i]->GetAll(fin);
						break;
					case MANAGER:
						pemp[i] = new manager;
						pemp[i]->GetAll(fin);
						break;
					case FINK:
						pemp[i] = new fink;
						pemp[i]->GetAll(fin);
						break;
					case HIGHFINK:
						pemp[i] = new highfink;
						pemp[i]->GetAll(fin);
						break;
					default:
						cout << "unkonwn type." << endl;
						exit(1);
				}
				emp_count++;
			}
			else
			{
				fin.clear();
				break;
			}
		}
		for(int i = 0; i < emp_count; i++)
			pemp[i]->ShowAll();
		
		fin.close();
	}
	
	ofstream fout;
	fout.open(pdata, ios_base::out | ios_base::app);
	if(!fout.is_open())
	{
		cerr << "open file failed." << endl;
		exit(1);
	}
	
	while(emp_count != MAX)
	{
		showMenu();
		char choice;
		cin.get(choice);
		while(cin.get() != '\n')
			continue;
		switch(choice)
		{
			case 'e':
				pemp[emp_count] = new employee;
				pemp[emp_count]->SetAll();
				pemp[emp_count]->WriteAll(fout);
				emp_count++;
				break;
			case 'm':
				pemp[emp_count] = new manager;
				pemp[emp_count]->SetAll();
				pemp[emp_count]->WriteAll(fout);
				emp_count++;
				break;
			case 'f':
				pemp[emp_count] = new fink;
				pemp[emp_count]->SetAll();
				pemp[emp_count]->WriteAll(fout);
				emp_count++;
				break;
			case 'h':
				pemp[emp_count] = new highfink;
				pemp[emp_count]->SetAll();
				pemp[emp_count]->WriteAll(fout);
				emp_count++;
				break;
			case 'q':
				cout << "Bye.\n";
				return 0;
			default:
				cout << "bad choice" << endl;
				continue;
		}
		
		cout << "Now info: " << endl;
		for(int i = 0; i < emp_count; i++)
			pemp[i]->ShowAll();
	}
	
	cout << "The max number of employeeer is " << MAX << endl;
	cout << "Bye.\n";
	
	return 0;
}

void showMenu()
{
	std::cout << "*******************menu*******************" << std::endl;
	std::cout << "e: add a employee" << std::endl;
	std::cout << "f: add a fink" << std::endl;
	std::cout << "m: add a manager" << std::endl;
	std::cout << "h: add a high fink" << std::endl;
	std::cout << "q: to quit" << std::endl;
	std::cout << "*******************menu*******************" << std::endl;
	std::cout << "Please make your choice: " ;
}
