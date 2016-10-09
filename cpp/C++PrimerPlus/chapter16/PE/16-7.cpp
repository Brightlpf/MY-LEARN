#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Lotto(int total, int choose);
void show(int n) { cout << n << " "; }
bool win(const vector<int> & v1, const vector<int>  & v2);

int main()
{
	vector<int> mynumber(6);
	vector<int> winner;
	
	while(1)
	{
		cout << "plese choose 6 num from 0~ 50 \n";
		for(int i = 0; i < 6; i++)
			cin >> mynumber[i];
		cout << "The winning numbers is : ";
		winner = Lotto(51, 6);
		for_each(winner.begin(), winner.end(), show);
		cout << endl;
		cout << "You choose numbers is: ";
		for_each(mynumber.begin(), mynumber.end(), show);
		cout << endl;
		if(win(mynumber, winner))
			cout << "congratuations! You get it.\n";
		else
			cout << "Thanks, welcome to play again.\n";
	}
	
	
}

vector<int> Lotto(int total, int choose)
{
	vector<int> vi;
	vector<int> result(choose);
	
	for(int i = 0; i < total; i++)
		vi.push_back(i);
	for(int i = 0; i < choose; i++)
	{
		random_shuffle(vi.begin(), vi.end());
		result[i] = vi[0];
	}
	
	return result;
}

bool win(const vector<int> & v1, const vector<int>  & v2)
{
	int count = 0;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if (v1[i] == v2[j])
			{
				count++;
				break;
			}
			else 
				continue;
		}
	}
	return count >= 5;
}
