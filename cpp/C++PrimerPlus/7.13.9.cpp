#include <iostream>
using namespace std;
const int SLEN = 30;
struct student{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while(cin.get() != '\n')
		continue;
	
	student *ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for(int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";
	return 0;
}

int getinfo(student pa[], int n)
{
	int entered = 0;
	for(int i = 0; i < n; i++)
	{
		/************debug*************
		for(int j = 0; j < SLEN; j++)
		{
			cout << "debug: fullname[" << j << "] = " <<(int)pa[i].fullname[j] << endl;
		}
		************debug*************/
		cout << i << "#: "<< endl;
		cout << "\tname: ";
		cin.getline(pa[i].fullname, SLEN);
		/************debug*************
		for(int j = 0; j < SLEN; j++)
		{
			cout << "debug: fullname[" << j << "] = " <<(int)pa[i].fullname[j] << endl;
		}
		************debug*************/
		if(pa[i].fullname[0] == '\0')
			break;
		cout << "\thobby: ";
		cin.getline(pa[i].hobby, SLEN);
		if(pa[i].hobby[0] == '\0')
			break;
		cout << "\tlevel: ";
		cin >> pa[i].ooplevel;
		while(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "error! input again: ";
			cin >> pa[i].ooplevel;
		}
		cin.get();
		entered++;
	}
	return entered;
}

void display1(student st)
{
	cout << "name: " << st.fullname << "\t";
	cout << "hobby: "<< st.hobby << "\t";
	cout << "ooplevel: " << st.ooplevel << endl;
}

void display2(const student *ps)
{
	cout << "name: " << ps->fullname << "\t";
	cout << "hobby: "<< ps->hobby << "\t";
	cout << "ooplevel: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "student #" << i << ": " << endl;
		cout << "\tname: " << pa[i].fullname << "\t";
		cout << "\thobby: "<< pa[i].hobby << "\t";
		cout << "\tooplevel: " << pa[i].ooplevel << endl;
	}
}
