#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main()
{
	using namespace std;
	struct Book{
		string title;
		double price;
		string author;
	};
	
	Book book;
	ofstream fout;
	fout.open("book2.dat", ios_base::out|ios_base::trunc);
	if(!fout.is_open())
	{
		cout << "open error!";
		exit(1);
	}
	cout << "Enter the book title: ";
	getline(cin, book.title);
	cout << "Enter the book's price: $";
	cin >> book.price;
	cin.get();
	cout << "Enter the book's author: ";
	getline(cin, book.author);

	
	//save book to book2.txt
	//只是将string 指向字符串的地址保存了， 如果重新定义book 变量， 用来读取文件，
	//则在变量生命周期结束后，其中string的地址将被释放2次；
	//总之， 在保存信息时不能保存动态指针。
	fout.write((char *)&book, sizeof(Book));
	fout.close();
	
	
	//read from book2.txt
	ifstream fin("book2.dat", ios_base::in);
	fin.read((char *)&book, sizeof(Book));
	cout << "title: " << book.title << endl;
	cout << "price: $" << book.price << endl;
	cout << "author: " << book.author << endl;
	//fin.close();
	//fin.clear();
	
	return 0;
}
