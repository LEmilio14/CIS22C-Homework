#pragma once
#include "List.h"

template <typename T>
class Stack : protected List<T>
{
public:
	void push(T&);
	void pop();
	T& peek();
	void empty();
	void count();
};

template <typename T>
void Stack<T>::push(T& newData)
{
	this->insertFirst(newData);
}

template <typename T>
void Stack<T>::pop()
{
	this->removeFirst();
}

template <typename T>
T& Stack<T>::peek()
{
	return this->getFirstData();
}

template <typename T>
void Stack<T>::empty()
{
	this->removeAll();
}

template <typename T>
void Stack<T>::count()
{
	return this->count;
}