#pragma once
#include"List.h"

template<typename T>
class Queue : protected List<T>
{

public:

	void enqueue(T&);
	void dequeue();
	T& front();
	T& rear();
	void emptyQueue();
	void countQueue();
	//bool queueFull();
	//bool isEmpty();
	void display1();
};


template<typename T>
void Queue<T>::enqueue(T& newData)
{
	this->insertLast(newData);
}

template<typename T>
void Queue<T>::dequeue()
{
	this->removeFirst();	
}

template<typename T>
T& Queue<T>::front()
{
	return this->getFirstData();
}

template<typename T>
T& Queue<T>::rear()
{
	return this->getLastData();
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
void Queue<T>::display1() 
{
	for (int i = 0; i < 6; i++)
	{
		std::cout << this->getData(i) << std::endl;
	}
}
