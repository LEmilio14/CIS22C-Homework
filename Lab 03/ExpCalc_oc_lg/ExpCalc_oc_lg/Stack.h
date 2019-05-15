/********************************************************************************
************************************ Stack **************************************
*********************************************************************************
* This class is an Abstract Data Structure, modeling the functionality of a stack.
* As this class is template based, it can be used with almost any type of data.
* This data structure follows a First In, Last Out pattern.
*****************
***** USAGE *****
*****************
* Declare an object of type Stack, using template initialization.
* You may then call Stack functions on the new Queue object.
*********************************************************************************/

#pragma once

#include "List.h"

template <typename T>
class Stack : public List<T>
{
public:
	void push(T&);
	void pop();
	T& peek();
	void empty();
	int count();
	bool isEmpty();
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

/**
* isEmpty
*
* @brief Returns whether the stack is empty or not.
*
* @return TRUE if the stack is empty, otherwise FALSE
*/

template<typename T>
bool Stack<T>::isEmpty()
{
	if (this->count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Counts data of stack.

@pre None.

@post Gets the count of the elements in the stack.

@return Count of elements.
*/
template <typename T>
int Stack<T>::count()
{
	return this->getCount();
}

template <typename T>
bool Stack<T>::isEmpty()
{
	if (this->count == 0) 
	{
		return true;
	}
	else
		return false;
}