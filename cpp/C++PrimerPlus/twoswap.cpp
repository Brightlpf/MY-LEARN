#include <iostream>
using namespace std;
const int MAX = 40;
struct job{
	char name[MAX];
	double salary;
	int floor;
};

void Swap(int & a, int & b);
template <typename T>
void Swap(T &a, T & b);    //只是定义模板，并不生成函数定义

template <> void Swap<job>(job &a, job &b);  //显式具体化(explict specialization)， 需要自己定义函数 
//template void Swap<job>(job &a, job &b);  //显式实例化（explict instantiation），由模板自动生成函数定义
void show(job & j);
int main()
{
	int a = 10;
	int b = 20;
	cout << "a , b = " << a << ", "<< b << endl;
	Swap(a, b); //隐式实例化， 由模板自动生成函数定义
	cout << "After Swap: "<< endl;
	cout << "a , b = " << a << ", "<< b << endl;
	
	double da = 12.56;
	double db = 34.78;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	cout << "da , db = " << da << ", "<< db << endl;
	cout << "After Swap: "<< endl;
	Swap(da, db);
	cout << "da , db = " << da << ", "<< db << endl;
	
	job ja = {"rodney", 70932, 3};
	job jb = {"smith cater", 80823, 2};
	show(ja);
	show(jb);
	cout << "After Swap: "<< endl;
	Swap(ja, jb);
	show(ja);
	show(jb);
	return 0;
}

void Swap(int & a, int & b)
{
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Swap(T &a, T & b)
{
	T temp;
	
	temp = a;
	a = b;
	b = temp;
}

template <> void Swap<job>(job &a, job & b)
{
	double dtemp;
	int ntemp;
	
	dtemp = a.salary;
	a.salary = b.salary;
	b.salary = dtemp;
	
	ntemp = a.floor;
	a.floor = b.floor;
	b.floor = ntemp;
}

void show(job & j)
{
	cout << "name : " << j.name << " salary: " << j.salary << " floor: " << j.floor << endl;
}
