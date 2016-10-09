#include <iostream>
#include <string>
#include <cstdlib>
#include "14-4.h"

using namespace std;

//Card
Card::Card()
{   
	srand(time(NULL));
	colour = rand() % 4;
	value = rand() % 15;
}

//Gunslinger
double Gunslinger::Draw() const
{
	srand(time(NULL));
	return rand()*1.0/RAND_MAX * 3;
}

void Gunslinger::Show()
{
	Person::Show();
	cout << "nicks: " << nicks << endl;
	cout << "Draw time: " << Draw() << endl;
}


//PokerPlayer
Card PokerPlayer::Draw() const
{
	Card c;
	return c;
}

//BadDude
double BadDude::Gdraw() const
{
	return Gunslinger::Draw();
}

Card BadDude::Cdraw() const
{
	return PokerPlayer::Draw();
}

void BadDude::Show()
{
	Gunslinger::Show();
	cout << "poke colour: " <<  Cdraw().Colour() << endl;
	cout << "poke value: " << Cdraw().Value() << endl;
}
