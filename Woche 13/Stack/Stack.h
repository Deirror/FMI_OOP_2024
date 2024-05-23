#pragma once
#include <exception>

template <typename T, unsigned N>
class Stack
{
private:
	T data[N];
	size_t size = 0;

public:
	void push(const T& other);
	void push(T&& other);
	
	void pop();
	const T& peek() const;
	bool isEmpty() const;
};

template<typename T, unsigned N>
void Stack<T, N>::push(const T & other)
{
	if (size == N)
		throw std::exception("Full stack!");

	data[size++] = other;
}

template<typename T, unsigned N>
void Stack<T, N>::push(T && other)
{
	if (size == N)
		throw std::exception("Full stack!");

	data[size++] = std::move(other);
}

template<typename T, unsigned N>
void Stack<T, N>::pop()
{
	if (size == 0)
		throw std::exception("Empty stack!");

	size--;
}

template<typename T, unsigned N>
const T & Stack<T, N>::peek() const
{
	if(isEmpty())
		throw std::exception("Empty stack!");

	return data[size - 1];
}

template<typename T, unsigned N>
bool Stack<T, N>::isEmpty() const
{
	return (size == 0);
}
