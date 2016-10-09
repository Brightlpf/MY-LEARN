#ifndef PE14_4_H_
#define PE14_4_H_
#include <string>

class Card{
private:
	int colour;
	int value;
public:
	//Card
	Card();
	int Colour() const {return colour;}
	int Value() const {return value;}
};
	
class Person
{
private:
	std::string name;
public:
	Person(std::string n = "no one") : name(n) {}
	virtual ~Person() {}
	virtual void Show() {std::cout << "name: " << name << std::endl;}
};

class Gunslinger : virtual public Person
{
private:
	int nicks;
	double shoottime;
public:
	Gunslinger(std::string nm = "no one", int n = 0, double st = 0.0) : Person(nm), nicks(n), shoottime(0.0)
	{
		shoottime = Draw();
	}
	virtual ~Gunslinger() {}
	double Draw() const;
	virtual void Show();
};

class PokerPlayer : virtual public Person
{
private:
	Card card;
public:
	PokerPlayer(std::string nm, Card c): Person(nm), card(c) {}
	virtual ~PokerPlayer() {}
	virtual Card Draw() const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
private:
public:
	BadDude(std::string nm, int n, double st, Card c) : Person(nm), Gunslinger(nm, n, st), PokerPlayer(nm, c){}
	~BadDude() {}
	double Gdraw() const;
	Card Cdraw() const;
	virtual void Show();
};

#endif