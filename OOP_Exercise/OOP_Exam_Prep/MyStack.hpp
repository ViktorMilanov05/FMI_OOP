#include <iostream>
#include <exception>

template<class T, const unsigned S>
class MyStack {
	T arr[S];
	unsigned size = 0;
public:
	bool isEmpty() const;
	bool isFull() const;
	void push(const T& el);
	void push(T&& el);
	const T& peek() const;
	void pop();
};

template<class T, unsigned S>
bool MyStack<T, S>::isEmpty() const
{
	return !size;
}

template<class T, unsigned S>
bool MyStack<T, S>::isFull() const
{
	return size == S;
}

template<class T, unsigned S>
void MyStack<T, S>::push(const T& el)
{
	if (isFull())
		throw std::exception();
	arr[size++] = el;
}

template<class T, unsigned S>
void MyStack<T, S>::push(T&& el)
{
	if (isFull())
		throw std::exception();
	arr[size++] = std::move(el);
}

template<class T, unsigned S>
const T& MyStack<T, S>::peek() const
{
	if (isEmpty())
		throw std::exception();
	return arr[size - 1];
}

template<class T, unsigned S>
void MyStack<T, S>::pop()
{
	if (isEmpty())
		throw std::exception();
	size--;
}
