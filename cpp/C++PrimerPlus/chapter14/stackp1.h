#ifndef STACKTM_H_
#define STACKTM_H_

template <typename Type>
class Stack
{
private:
	enum{MAX = 10};
	int top;
	int stacksize;
	Type * items;
	
public:
	Stack(int size = MAX);
	Stack(const Stack & s);
	virtual ~Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const Type & item);
	bool pop(Type & item);
	Stack & operator=(const Stack & s);
};

template <typename Type>
Stack<Type>::Stack(int size)
{
	stacksize = size;
	items = new Type[stacksize];
	top = 0;
}
template <typename Type>
Stack<Type>::Stack(const Stack & s)
{
	stacksize =  s.stacksize;
	items = new Type[stacksize];
	top = s.top;
	
	for(int i = 0; i < top; i++)
		items[i] = s.items[i];
}

template <typename Type>
Stack<Type>::~Stack()
{
	delete [] items;
}

template <typename Type>
bool Stack<Type>::isEmpty() const
{
	return top == 0;
}

template <typename Type>
bool Stack<Type>::isFull() const
{
	return top == stacksize;
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

template <typename Type>
Stack<Type> & Stack<Type>::operator=(const Stack & s)
{
	if(&s == this)
		return *this;
	delete [] items;
	stacksize = s.stacksize;
	items = new Type[stacksize];
	top = s.top;
	
	for(int i = 0; i < top; i++)
		items[i] = s.items[i];
	return *this;
}

#endif