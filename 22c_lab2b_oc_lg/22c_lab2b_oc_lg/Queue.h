#pragma once
#include"List.h"

template <typename U> class Queue;
template <typename U>
std::ostream& operator<<(std::ostream& os, Queue<U> list)
{
	for (int i = 0; i < list.getCount(); i++)
	{
		os << list.getData(i) << std::endl;
	}

	return os;
}

template<typename T>
class Queue : public List<T>
{
public:
	void enqueue(T&);
	void dequeue();
	void queueFront(T&);
	void queueRear(T&);
	void emptyQueue();
	void countQueue();
	//bool queueFull();
	bool isEmpty();

};

template<typename T>
void Queue<T>::enqueue(T& newData)
{
	this->insertFirst(newData);
}

template<typename T>
void Queue<T>::dequeue()
{
	this->removeFirst(0);
}

template<typename T>
void Queue<T>::queueFront(T& newData)
{
	this->insert(newData, 0);
}

template<typename T>
void Queue<T>::queueRear(T& newData)
{
	this->insertFirst(newData, this->count);
}

template<typename T>
void Queue<T>::emptyQueue()
{
	this->removeAll();
}

template<typename T>
void Queue<T>::countQueue()
{
	return this->count;
}

/*
template<typename T>
bool Queue<T>::queueFull()
{
	
}
*/

template<typename T>
bool Queue<T>::isEmpty()
{
	if (this->count == 0)
	{
		return true;
	}
	else
		return false;
}