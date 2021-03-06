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

/*
Puts data into stack.

@pre New data.

@post Insert the firts element.

@return N/A.
*/
template <typename T>
void Stack<T>::push(T& newData)
{
	this->insertFirst(newData);
}

/*
Removes data from the stack.

@pre None.

@post Removes the first stacked element.

@return N/A.
*/
template <typename T>
void Stack<T>::pop()
{
	this->removeFirst();
}

/*
Gets the first elemnt in the stack.

@pre None.

@post Gets the firts element.

@return First element in the stack.
*/
template <typename T>
T& Stack<T>::peek()
{
	return this->getFirstData();
}

/*
Empties out the stack.

@pre None.

@post Removes all the stack.

@return N/A.
*/
template <typename T>
void Stack<T>::empty()
{
	this->removeAll();
}

/*
Counts data of stack.

@pre None.

@post Gets the count of the elements in the stack.

@return Count of elements.
*/
template <typename T>
void Stack<T>::count()
{
	return this->count;
}