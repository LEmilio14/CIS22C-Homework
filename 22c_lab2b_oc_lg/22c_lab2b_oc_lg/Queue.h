#pragma once
#include"List.h"

template<typename T>
class Queue : protected List<T>
{
private:
	T* front;
	T* rear;

public:
	Queue();
	~Queue();

	void enqueue(T&);
	void dequeue();
	T& getFront();
	T& getRear();
	void emptyQueue();
	void countQueue();
	bool isEmpty();
	void display1();
};

template<typename T>
Queue<T>::Queue()
{
	front = nullptr;
	rear = nullptr;
}

template<typename T>
Queue<T>::~Queue()
{

}

template<typename T>
void Queue<T>::enqueue(T& newData)
{
	this->rear* = this->insertLast(newData);
}

template<typename T>
void Queue<T>::dequeue()
{
	this->removeFirst();	
}

template<typename T>
T& Queue<T>::getFront()
{
	return this->getFirstData();
}

template<typename T>
T& Queue<T>::getRear()
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

template<typename T>
bool Queue<T>::isEmpty()
{
	if (front == nullptr && rear == nullptr)
	{
		return true;
	}
	else
		return false;
}

template<typename T>
void Queue<T>::display1() 
{
	for (int i = 0; i < 6; i++)
	{
		std::cout << this->getData(i) << std::endl;
	}
}
