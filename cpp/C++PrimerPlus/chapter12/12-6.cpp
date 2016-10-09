#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Queue.h"

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
	Queue line(qs);
	Queue line2 = line;
	
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
	
	Item temp;  //new customer
	long turnaways = 0; //turned away by full queue
	long customers = 0; //joined the queue
	long served = 0; //served during the simulation
	long served2 = 0;
	long sum_line = 0; //cumulative line length
	long sum_line2 = 0;
	int wait_time = 0; //time until autoteller is free
	int wait_time2 = 0;
	long line_wait = 0; //cumulative time in line
	long line_wait2 = 0;
	
	for(int cycle = 0; cycle < cyclelimit; cycle++)
	{
		//have newcomer
		if (newcustomer(min_per_cust))
		{
			if (line.isfull() && line2.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);
				if(line.getitems() < line2.getitems())
					line.enqueue(temp);
				else
					line2.enqueue(temp);
			}
		}
		
		//处理完成（随机1~3分钟），离开队列
		if(wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);
			//cout << "customer dequeue " << endl;
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		
		if(wait_time2 <= 0 && !line2.isempty())
		{
			line2.dequeue(temp);
			//cout << "customer dequeue " << endl;
			wait_time2 = temp.ptime();
			line_wait2 += cycle - temp.when();
			served2++;
		}
		
		//正在处理当中。。。
		if(wait_time > 0)
		{
			//cout <<"wait time is "<< wait_time << endl;
			wait_time--;
		}

		if(wait_time2 > 0)
		{
			wait_time2--;
		}
		sum_line += line.getitems();
		sum_line2 += line2.getitems();
	}
	
	//reporting results
	cout << "line1 rest: " << line.getitems() << endl;
	cout << "line2 rest: " << line2.getitems() << endl;
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << " customers served: " << served + served2 << endl;
		cout << "	turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << ((double)sum_line/cyclelimit + (double)sum_line2/cyclelimit)/2  << endl;
		cout << "average wait time: "
			 << ((double) line_wait / served + (double) line_wait2 / served2 )/2 << "minutes\n";
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
