#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <new>

using namespace std;

struct Review{
	string title;
	int rating;
	double price;
};

shared_ptr<Review> FillReview();
void ShowReview(const shared_ptr<Review> rw);
bool operator<(const shared_ptr<Review> &r1, const shared_ptr<Review>  &r2);
bool PriceSort(const shared_ptr<Review> &r1, const shared_ptr<Review>  &r2);
bool RatingSort(const shared_ptr<Review>  &r1, const shared_ptr<Review> & r2);
void ShowMenu();

int main()
{
	vector<shared_ptr<Review> > books;
	shared_ptr<Review> tempptr;
	
	while(tempptr = FillReview())
	{
		books.push_back(tempptr);
	}
	if (books.size() > 0)
	{
		int input;
		ShowMenu();
		
		while(cin >> input)
		{
			bool flag = false;
			switch(input)
			{
				case 1: 	break;
				case 2: sort(books.begin(), books.end()); 	break;
				case 3: sort(books.begin(), books.end(), RatingSort); break;
				case 4: sort(books.rbegin(), books.rend(), RatingSort); break;
				case 5: sort(books.begin(), books.end(), PriceSort); break;
				case 6: sort(books.rbegin(), books.rend(), PriceSort); break;
				case 7:
					flag = true;
					break;
				default:
					cout << " Please input 1~7 \n";
					continue;
					
			}
			if(flag)
			{
				break;
			}
			for_each(books.begin(), books.end(), ShowReview);
			cin.get();//skip '\n'
			ShowMenu();
		}
	}
	else 
	{
		cout << "No books\n";
	}
	cout << "Bye.\n";
	return 0;
}

shared_ptr<Review> FillReview()
{
	/*
	try{
		shared_ptr<Review> ptr(new Review);
		//ptr = new Review //not allowed , need expicit construct
		//ptr is valid in try only
	}
    catch(const bad_alloc & e)
	{
		return NULL;
	}
	*/
	shared_ptr<Review> ptr;
	try{
		ptr = shared_ptr<Review> (new Review);
		cout << "Enter the book title <quit to quit>: \n";
		getline(cin, ptr->title);
		if(ptr->title == "quit")
			return NULL;
		cout << "Enter the rating: ";
		cin >> ptr->rating;
		cout << "Enter the price: ";
		cin >> ptr->price;
	}
	catch(const bad_alloc & e)
	{
		cout << "allocat failed.\n";
		return NULL;
	}
	
	
	while(cin.get() != '\n')
		continue;
	
	return ptr;	
}

void ShowReview(const shared_ptr<Review> rw)
{
	cout << rw->price << "\t" <<  rw->rating << "\t" << rw->title << endl;
}

bool operator<(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
	if(r1->title < r2->title)
		return true;
	else
		return false;
}

bool PriceSort(const shared_ptr<Review> &r1, const shared_ptr<Review>  &r2)
{
	if(r1->price < r2->price)
		return true;
	else
		return false;
}

bool RatingSort(const shared_ptr<Review> & r1, const shared_ptr<Review>  &r2)
{
	if(r1->rating < r2->rating)
		return true;
	else
		return false;
}

void ShowMenu()
{
	cout << "=====================================" << endl;
	cout << "1: display by input.\t"
		 << "2: display by alphabet." << endl;
	cout << "3: display by rating up.\t"
		 << "4: display by rating down." << endl;
	cout << "5: display by price up.\t"
		 << "6: display by price down." << endl;
	cout << "7: quit.\n";
	cout << "=====================================" << endl;
}
