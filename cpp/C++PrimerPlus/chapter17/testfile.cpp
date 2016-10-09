#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
int main()
{
	struct Book{
		string title;
		double price;
		string author;
	};
	
	Book book;
	ofstream fout("book.txt");
	cout << "Enter the book title: ";
	getline(cin, book.title);
	cout << "Enter the book's price: ";
	cin >> book.price;
	cin.get();
	cout << "Enter the book's author: ";
	getline(cin, book.author);
	
	//save to book.txt
	fout << book.title << '#' << book.price << '#' << book.author << endl;
	fout.close();
	fout.clear();
	//show book.txt
	cout << "you saved infomation: \n";
	ifstream fin("book.txt");
	if(!fin.is_open())
	{
		cerr << "open file failed" << endl;
		exit(1);
	}
	char temp[20];
	double bp;
	while(fin.getline(temp, 20, '#'))
	{
		cout << temp;
		fin >> bp;
		fin.get();
		cout << " " << bp;
		fin.getline(temp, 20);
		cout << " " << temp << endl;
	}
	
	return 0;
}