#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib> //rand()
#include <ctime> //clock_t clock()

using namespace std;

int main()
{
	srand(time(NULL));
	vector<int> vi0;
	long times;
	cout << "How many times do you want to test? ";
	while(cin >> times)
	{
		for(int i = 0; i < times; i++)
		{
			vi0.push_back(rand());
		}
		vector<int> vi(vi0.begin(), vi0.end());
		list<int> li(vi0.begin(), vi0.end());
		
		clock_t start;
		clock_t end;
		start = clock();
		sort(vi.begin(), vi.end());
		end = clock();
		
		double ti; //time for sort vector
		double tl; //time for sort list
		double tli; //time for cp->sort->cp
		ti = (double)(end - start)/CLOCKS_PER_SEC;
		start = clock();
		//sort(li.begin(), li.end());   //sort does't match list 
		li.sort();
		end = clock();
		tl = (double)(end - start)/CLOCKS_PER_SEC;
		
		copy(vi0.begin(), vi0.end(), li.begin());
		start = clock();
		copy(li.begin(), li.end(), vi.begin());
		sort(vi.begin(), vi.end());
		copy(vi.begin(), vi.end(), li.begin());
		end = clock();
		tli = (double)(end - start)/CLOCKS_PER_SEC;
		
		cout << "time for sort vector(" << times << ") : " << ti << " (s)" << endl;
		cout << "time for sort list(" << times << ") : " << tl << " (s)" << endl;
		cout << "time for sort list(copy to vector)(" << times << ") : " << tli << " (s)" << endl;
		
		cout << "How many times do you want to test? ";
	}
	
	return 0;
}