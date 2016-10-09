#include "stack.h"

/*
	private:
		Stack s;
		Stack stemp;
	public:
		Stack();
		bool isempty() const;
		bool isfull() const;
		bool push(const Item & item);
		bool pop(Item & item);
*/

class Queue{
	private:
		Stack s;
		Stack stemp;
	public:
		Queue();
		bool isempty() const;
		bool isfull() const;
		bool enqueue(const Item & item);
		bool dequeue(Item & item);
};