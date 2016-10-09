#ifndef PAIR_H_
#define PAIR_H_

template <typename T1, typename T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	Pair(const T1 & t1, const T2 & t2) : a(t1), b(t2){}
	Pair() {}
	T1 & first();
	T2 & second();
	T1 first() const {return a;}
	T2 second() const {return b;}
};

template <typename T1, typename T2>
T1 & Pair<T1, T2>::first()
{
	return a;
}

template <typename T1, typename T2>
T2 & Pair<T1, T2>::second()
{
	return b;
}

#endif