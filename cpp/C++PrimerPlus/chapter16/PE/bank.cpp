#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "customer.h"

using namespace std;
const int MIN_PER_HR = 60;
bool newcustomer(double x); //is there a new customer

int main()
{
	srand(time(NULL));
	
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	
	int qs;
	cin >> qs;
	queue<Customer> line;
	
	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	//simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours;
	
	cout << "Enter the average number of customers per hours: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;  // 平均循环n次 产生一个顾客
	
	Customer temp;  //new customer
	long turnaways = 0; //turned away by full queue
	long customers = 0; //joined the queue
	long served = 0; //served during the simulation
	long sum_line = 0; //cumulative line length
	int wait_time = 0; //time until autoteller is free
	long line_wait = 0; //cumulative time in line
	
	for(int cycle = 0; cycle < cyclelimit; cycle++)
	{
		//have newcomer
		if (newcustomer(min_per_cust))
		{
			if (line.size() == qs)
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);
				line.push(temp);
			}
		}
		
		//处理完成（随机1~3分钟），离开队列
		if(wait_time <= 0 && !line.empty())
		{
			temp = line.front();
			line.pop();
			//cout << "customer dequeue " << endl;
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		
		//正在处理当中。。。
		if(wait_time > 0)
		{
			//cout <<"wait time is "<< wait_time << endl;
			wait_time--;
		}	
		sum_line += line.size();
	}
	
	//reporting results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << " customers served: " << served << endl;
		cout << "	turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double ) sum_line/cyclelimit << endl;
		cout << "average wait time: "
			 << (double) line_wait / served << "minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
	
	return 0;
}

bool newcustomer(double x)
{
	return (rand() * x /RAND_MAX < 1);
}


void Customer::set(long when)
{
	arrivetime = when;
	processtime = rand() % 3 + 1;
}