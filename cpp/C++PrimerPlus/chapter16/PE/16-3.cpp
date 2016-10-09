#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;
const int NUM = 26;
void show(const string & str) { cout << str << " ";}
int main()
{
	srand(time(NULL));
	cout << "Will you play a word game<y/n> ?";
	char ch;
	
	//make sure input the right char
	cin >> ch;
	 
	ch = toupper(ch);
	while(!cin || (ch != 'Y' && ch != 'N'))
	{
		if(!cin)
			cin.clear();
		//skip '\n'
		while(cin.get() != '\n')
			continue;
		cout << "Please enter Y or N\n";
		cin >> ch;
		 
	}
	ifstream infile;
	vector<string> vsword;
	string temp;
	infile.open("16-3.txt");
	if(!infile.is_open())
	{
		cout << "open file failed.\n";
		exit(1);
	}
	while(infile >> temp)
	{
		vsword.push_back(temp);
	}
	for_each(vsword.begin(), vsword.end(), show);
	cout << endl;
	//start game
	while(toupper(ch) == 'Y')
	{
		int guess = 6;
		string target;
		target = vsword[rand() % NUM];
		int len = target.length();
		string attempt(len, '-');
		string badletters;
		cout << "Guess my secret word. It has " << len 
			<< " letters, and you guess one letter at a time\n. You get 6 wrong guess.\n";
		cout << "Your word: " << attempt << endl;
	
		 
		//guess process
		while(guess > 0 && attempt != target)
		{
			char letter;
			int loc;
			cout << "Guess a letter: ";
			cin >> letter;
			if((loc = target.find(letter)) != string::npos)
			{
				attempt[loc] = target[loc];
				while((loc = target.find(letter, loc + 1)) != string::npos)
				{
					attempt[loc] = target[loc];
				}
				cout << "Good guess!" << endl;
			}
			else
			{
				badletters += letter;
				cout << "Oh, bad guess!" << endl;
				guess--;
			}
			cout << "Your word: " << attempt << endl;
			cout << "Bad choices: " << badletters << endl;
			cout << guess << " bad guesses left" << endl;
			 
		}
		
		//result
		cout << "Your word: " << attempt << endl;
		if(guess > 0)
		{
			cout << "That's right!" << endl;
		}
		else
		{
			cout << "That's wrong! the word is " << target << endl;
		}
		cout << "Will you play another? <y/n> ";
		cin >> ch;
		 
	}
	cout << "Bye.\n";
	return 0;
}