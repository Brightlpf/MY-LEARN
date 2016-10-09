#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Review{
	string title;
	int rating;
};

bool FillReview(Review & rw);
void ShowReview(const Review & rw);

int main()
{
	vector<Review> books;
	Review temp;
	
	while(FillReview(temp))
	{
		books.push_back(temp);
	}

	if (books.size() > 0)
	{
		cout << "book\trating\n";
		for(int i = 0; i < books.size(); i++)
			ShowReview(books[i]);
		
		cout << "Reprising: \n";
		vector<Review> oldlist(books);
		vector<Review>::iterator it;
		if(books.size() > 3)
		{
			cout << "delete  2 books: " << endl;
			oldlist.erase(oldlist.begin() + 1, oldlist.begin() + 3);
			for(it = oldlist.begin(); it != oldlist.end(); it++)
				ShowReview(*it);
		}
		cout << "Insert a book: \n";
		oldlist.insert(oldlist.begin(), books.begin() + 1, books.begin() + 2);
		for(it = oldlist.begin(); it != oldlist.end(); it++)
			ShowReview(*it);
		
		cout << "swap oldlist to book: " << endl;
		oldlist.swap(books);
		for(it = books.begin(); it != books.end(); it++)
			ShowReview(*it);
	}
	else 
	{
		cout << "No books\n";
	}
	cout << "Bye.\n";
	return 0;
}

bool FillReview(Review & rw)
{
	string title;
	
	cout << "Enter the book title <quit to quit>: \n";
	getline(cin, title);
	if(title == "quit")
		return false;
	rw.title = title;
	cout << "Enter the rating: ";
	cin >> rw.rating;
	if(!cin)
		return false;
	while(cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const Review & rw)
{
	cout << rw.title << "\t" << rw.rating << endl;
}