#pragma once
#include "Node.h"

template <typename T>
class List
{
private:
	int count;
	Node<T>* head;
public:
	List();
	~List();

	bool isEmpty();
	int getCount();
	void insert(T&, int); //A number outside the range 0-count will fail silently! Insertion pushes both the element in the desired position and all elements after that element to the right.
	void insertFirst(T&);
	void insertLast(T&);
	void remove(int); //A number outside the range 0-(count - 1) will fail silently!
	void removeFirst();
	void removeLast();
	void removeAll();
	T& getData(int); //An invalid index will throw an exception.
	T& getFirstData();
	T& getLastData();
	void setData(T&, int); //An invalid index will fail silently!
	void setFirstData(T&);
	void setLastData(T&);
};

template <typename T>
List<T>::List()
{
	count = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()
{
	
}

/*Checks if the link-list is empty
@pre The count of the link-list
@post None
@param None
return true if count is 0, otherwise false.
*/
template <typename T>
bool List<T>::isEmpty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Gets the count of the link-list
@pre None
@post None
@param None
return count.
*/
template <typename T>
int List<T>::getCount()
{
	return count;
}

/*Insert data into the list
@pre Position has to be less than 0 or greater than count
@post None
@param The new data
@param The position
return .
*/
template <typename T>
void List<T>::insert(T& newData, int pos)
{
	if (pos < 0 || pos > count)
	{
		return;
	}

	if (head == nullptr) //The list is empty
	{
		head = new Node<T>(newData);
	}
	else if (pos == 0) //Replacing head
	{
		Node<T>* temp = head;
		head = new Node<T>(newData, temp);
	}
	else
	{
		Node<T>* currentNode = head;
		for (int i = 0; i < pos - 1; i++)
		{
			currentNode = currentNode->next;
		}

		Node<T>* temp = currentNode->next;
		currentNode->next = new Node<T>(newData, temp);
	}

	count++;
	return;
}

/*Inserts data in the first position of the list
@pre New data that need to be inserted
@post None
@param new data
return.
*/
template <typename T>
void List<T>::insertFirst(T& newData)
{
	insert(newData, 0);
	return;
}

/*Inserts data at the last position of the list
@pre New data that needs to be added
@post None
@param new data
return.
*/
template <typename T>
void List<T>::insertLast(T& newData)
{
	insert(newData, count);
	return;
}

/*Remove data from the list
@pre Position has to be less than 0 or greater than count -1.
@post None
@param position
return.
*/
template <typename T>
void List<T>::remove(int pos)
{
	if (pos < 0 || pos > count - 1)
	{
		return;
	}

	if (head == nullptr) //The list is empty
	{
		return;
	}
	else
	{
		if (pos == 0)
		{
			Node<T>* nextNode = head->next;

			delete head;
			head = nextNode;
		}
		else
		{
			Node<T>* previousNode = nullptr;
			Node<T>* currentNode = head;
			for (int i = 0; i < pos; i++)
			{
				previousNode = currentNode;
				currentNode = currentNode->next;
			}

			if (currentNode->next != nullptr)
			{
				Node<T>* temp = currentNode->next;
				previousNode->next = temp;
			}

			delete currentNode;
		}
	}

	count--;
	return;
}

/*Removes the first element of the list
@pre Remove the first element
@post None
@param None
return.
*/
template <typename T>
void List<T>::removeFirst()
{
	remove(0);
	return;
}

/*Removes the last element
@pre Removes the last elemnt, count -1.
@post None
@param None
return.
*/
template <typename T>
void List<T>::removeLast()
{
	remove(count - 1);
	return;
}

/*Removes all the list
@pre Head pointer is null pointer
@post None
@param None
return.
*/
template <typename T>
void List<T>::removeAll()
{
	if (head == nullptr) //The list is empty
	{
		return;
	}
	else
	{
		Node<T>* previousNode = nullptr;
		Node<T>* currentNode = head;
		while (currentNode->next != nullptr)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
			delete previousNode;
		}

		delete currentNode;
	}

	count = 0;
	head = nullptr;

	return;
}

/*Gets data from the list
@pre Position less than 0 or greater than count -1 or head ptr is a null ptr
@post None
@param position
return ptr of the current data.
*/
template <typename T>
T& List<T>::getData(int pos)
{
	if (pos < 0 || pos > count - 1 || head == nullptr)
	{
		throw "Invalid index";
	}

	Node<T>* currentNode = head;
	for (int i = 0; i < pos; i++)
	{
		currentNode = currentNode->next;
	}
	
	return *(currentNode->data);
}

template <typename T>
T& List<T>::getFirstData()
{
	return getData(0);
}

template <typename T>
T& List<T>::getLastData()
{
	return getData(count - 1);
}

template <typename T>
void List<T>::setData(T& newData, int pos)
{
	if (pos < 0 || pos > count - 1 || head == nullptr)
	{
		return;
	}

	Node<T>* currentNode = head;
	for (int i = 0; i < pos; i++)
	{
		currentNode = currentNode->next;
	}

	currentNode->data = newData;
	return;
}

template <typename T>
void List<T>::setFirstData(T& newData)
{
	setData(newData, 0);
	return;
}

template <typename T>
void List<T>::setLastData(T& newData)
{
	setData(newData, count - 1);
	return;
}