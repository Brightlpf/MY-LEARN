#include <iostream>

using namespace std;

const int Max = 10;
void getscore(double score[]);
void showscore(double score[]);
double calav(double score[]);

int main()
{
	double golfscore[Max];
	
	getscore(golfscore);
	showscore(golfscore);
	cout << "The average score is : " << calav(golfscore) << endl;
}

void getscore(double score[])
{
	int i;
	cout << "Enter the golf score, '-1' to quit: " << endl;
	for(i = 0; i < Max; i++)
	{
		cin >> score[i];
		if(score[i] == -1)
			break;
		if(i < Max)
			cout << "get it, next: ";
	}
	if(i == Max)
	{
		cout << "No more than 10!";
	}
	cout << endl;
}
void showscore(double score[])
{
	cout << "golf score: " << endl;
	for(int i = 0; score[i] != -1 && i < Max; i++)
	{
		cout << score[i] << ' ';
	}
	cout << endl;
}
double calav(double score[])
{
	double sum = 0.0;
	int i;
	for(i= 0; score[i] != -1 &&i < Max; i++)
	{
		sum += score[i];
	}
	if(i == 0)
		return 0;
	return score[i] != -1 ? sum/(i + 1): sum/i;
}
