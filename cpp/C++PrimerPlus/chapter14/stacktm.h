#ifndef STACKTM_H_
#define STACKTM_H_

template <typename Type>
class Stack
{
private:
	enum{MAX = 10};
	int top;
	Type items[MAX];
	
public:
	Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const Type & item);
	bool pop(Type & item);
};

template <typename Type>
Stack<Type>::Stack()
{
	top = 0;
}

template <typename Type>
bool Stack<Type>::isEmpty() const
{
	return top == 0;
}

template <typename Type>
bool Stack<Type>::isFull() const
{
	return top == MAX;
}

template <typename Type>
bool Stack<Type>::push(const Type & item)
{
	if(isFull())
	{
		return false;
	}
	items[top++] = item;
	return true;
}

template <typename Type>
bool Stack<Type>::pop(Type & item)
{
	if(isEmpty())
	{
		return false;
	}
	item = items[--top];
	return true;
}


#endif