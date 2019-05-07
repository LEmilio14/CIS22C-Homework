#pragma once
#include"List.h"

template<typename T>
class Queue : protected List<T>
{
private:
	Node<T>* front;
	Node<T>* rear;
public:
	Queue();
	~Queue();

	void enqueue(T&);
	void dequeue();
	//T& front();
	//T& rear();
	void emptyQueue();
	void countQueue();
	//bool queueFull();
	bool isEmpty();
	void display();
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
	Node<T>* temp = front;
	front = this->insertFirst(newData);
	temp->next = nullptr;
	if (front == nullptr)
	{
		front = new Node<T>(newData);
		rear = new Node<T>(newData);
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}

template<typename T>
void Queue<T>::dequeue()
{
	if(isEmpty())
	{
		return;
	}
	else
	{
		if (front == rear) 
		{
			this->removeFirst();
			front = nullptr;
			rear = nullptr;
		}
		else
		{
			Node<T>* temp = front;
			front = front->data;
			this->removeFirst();
		}
	}
	this->removeFirst();	
}

/*
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
*/

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
	if (front == nullptr && rear == nullptr)
	{
		return true;
	}
	else
		return false;
}

template<typename T>
void Queue<T>::display() 
{
	if(isEmpty())
	{
		return;
	}
	else
	{
		Node<T>* temp = front;
		while (temp != nullptr)
		{
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
}