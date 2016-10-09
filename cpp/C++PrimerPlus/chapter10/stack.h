#ifndef __STACK_H_
#define __STACK_H_

struct customer{
	char fullname[35];
	double payment;
};

typedef customer Item;
class Stack{
	private:
		enum {MAX = 10};
		int top;
		Item item[MAX];
	public:
		Stack();
		bool isempty() const;
		bool isfull() const;
		bool push(const Item & it);
		bool pop(Item & it);
};

#endif