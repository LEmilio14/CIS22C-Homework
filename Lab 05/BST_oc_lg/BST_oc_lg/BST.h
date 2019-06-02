/********************************************************************************
************************************ BST ****************************************
*********************************************************************************
* This class is a BST (binary search tree) ADT.
*****************
***** USAGE *****
*****************
* 
*********************************************************************************/

#pragma once

#include "BST_Node.h"

template <typename T>
class BST
{
protected:
	int count;
	BST_Node<T>* head;

	BST_Node<T>* insert(T&, BST_Node<T>*);
public:
	BST();
	virtual ~BST();
	/**
	* getHead
	*
	* @brief Returns head.
	*
	* @return head
	*/
	BST_Node<T>* getHead();
	/**
	* insert
	*
	* @brief Recursively inserts the data into a new node in the sorted tree.
	*
	* @param The data to insert, as a reference.
	*/
	void insert(T&);
};

template <typename T>
BST<T>::BST()
{
	count = 0;
	head = nullptr;
}

template <typename T>
BST<T>::~BST()
{
	if (head != nullptr)
	{
		delete head;
		head = nullptr;
	}
}

template <typename T>
BST_Node<T>* BST<T>::getHead()
{
	return head;
}
template <typename T>
void BST<T>::insert(T& d)
{
	insert(d, head);
}

template <typename T>
BST_Node<T>* BST<T>::insert(T& d, BST_Node<T>* root)
{
	//The BST is completely empty
	if (head == nullptr)
	{
		head = new BST_Node<T>(d);
		return head;
	}
	
	//If the root is non-existent, create a new node and return it - the new node will be saved in the previous call
	if (root == nullptr)
	{
		return new BST_Node<T>(d);
	}

	//If the new data is less than root, recur for left root
	if (d < root->data)
	{
		root->left = insert(d, root->left);
	}
	//If the new data is greater or equal than root, recur for right root
	else
	{
		root->right = insert(d, root->right);
	}

	//Return the root so previous recursion calls keep their current values for left and right
	return root;
}