#include "vector.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
//#include <unistd.h>  //for debug

//const int DEST = 50;
const int UNIT = 2;
const double PI = 3.1415926;
int main()
{
	using namespace VECTOR;
	using namespace std;
	
	ofstream fout;
	
	fout.open("walkerstep.log");
	//if(!fout.is_ok())
	if(!fout)
	{
		cout << "open file failed!" << endl;
		exit(1);
	}
	
	int target;
	cout << "Please enter the Walker target: ";
	while(!(cin >> target))
	{
		cin.clear();
		cout << "err, input again.\n";
	}
	cout << "How many times do you want to test: ";
	int n;
	cin >> n;
	
	int count[n];
	Vector walkers[n];
	for(int i = 0; i < n; i++)
	{
		count[i] = 0;
	}
	fout << "Targe distance: " << target<< ", Step size: " << UNIT << endl;
	//Vector walker(0.0, 0.0);
	Vector move(0.0, 0.0, Vector::POL);
	//int count = 0;
	double ang = 0.0;
	//fout << count[0] << ": " << walker << endl;
	srand(time(NULL));
	//test n times
	
	for(int i = 0; i < n; i++)
	{
		while(walkers[i].magval() < target)
		{
			ang = 2*PI * rand()/RAND_MAX; //产生一个【0， 2PI】之间的随机数
			move.reset(UNIT, ang, Vector::POL);
			walkers[i]  = walkers[i] + move;
			
			//walker.polar_mode();
			//cout << walker << endl;
			//sleep(1);
			count[i]++;
			fout << count[i] << ": " << walkers[i] << endl;
		}
	}
	//find the max and the min times
	int min, max;
	int index_min = 0, index_max = 0;
	min = max = count[0];
	for(int i = 0; i < n; i++)
	{
		if(min > count[i])
		{
			min = count[i];
			index_min = i;
		}
		if(max < count[i])
		{
			max = count[i];
			index_max = i;
		}
	}
	// display result
	cout << "The max = " << max << ", location: " << walkers[index_max] << endl;
	cout << "Average outward distance per step " << target * 1.0 / max << endl;
	cout << "The min = " << min << ", location: " << walkers[index_min] << endl;
	cout << "Average outward distance per step " << target * 1.0 / min << endl;
	/*
	fout << "After " << count << "step, The walker has the following location: ";
	fout << walker << endl;
	fout << "Average outward distance per step " << target * 1.0 / count << endl;
	fout.close();
	cout << walker << endl;
	cout << "total walk " << count << " step." << endl;
	*/
	return 0;
}
