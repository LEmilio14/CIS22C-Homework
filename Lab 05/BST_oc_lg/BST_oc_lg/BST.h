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
#include "Queue.h"

template <typename T>
class BST
{
protected:
	int count;
	BST_Node<T>* head;

	BST_Node<T>* insert(T&, T&, BST_Node<T>*);
	BST_Node<T>* remove(T&, BST_Node<T>*);
	BST_Node<T>* findMin(BST_Node<T>*);
	BST_Node<T>* find(BST_Node<T>*, T&);
	void queueNodes(Queue<BST_Node<T>>&, BST_Node<T>*);
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
	void insert(T&, T&);
	/**
	* delete
	*
	* @brief Recursively deletes the data desired from the tree
	*
	* @param The data to insert, as a reference.
	*/
	void remove(T&);
	/**
	* find
	*
	* @brief Recursively searchs an item from a BST.
	*
	* @param The data to insert, as a reference.
	*
	* @return The found BST_Node.
	*/
	BST_Node<T>* find(T&);
	/**
	* deleteAll
	*
	* @brief Deletes all managed nodes using a queue.
	*/
	void deleteAll();
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
	deleteAll();
}

template <typename T>
BST_Node<T>* BST<T>::getHead()
{
	return head;
}
template <typename T>
void BST<T>::insert(T& d, T& s)
{
	insert(d, s, head);
}

template <typename T>
BST_Node<T>* BST<T>::insert(T& d, T& s, BST_Node<T>* root)
{
	//The BST is completely empty
	if (head == nullptr)
	{
		head = new BST_Node<T>(d, s);
		return head;
	}
	
	//If the root is non-existent, create a new node and return it - the new node will be saved in the previous call
	if (root == nullptr)
	{
		return new BST_Node<T>(d, s);
	}

	//If the new data is less than root, recur for left root
	if (d < root->data)
	{
		root->left = insert(d, s, root->left);
	}
	//If the new data is greater or equal than root, recur for right root
	else
	{
		root->right = insert(d, s, root->right);
	}

	//Return the root so previous recursion calls keep their current values for left and right
	return root;
}

template<typename T>
BST_Node<T>* BST<T>::find(T& d)
{
	return find(head, d);
}

template<typename T>
BST_Node<T>* BST<T>::find(BST_Node<T>* root, T& data)
{
	if (root == nullptr)//if the tree is empty, then return false
	{
		return nullptr;
	}
	else if (root->data == data)//if the data is found return true.
	{
		return root;
	}
	else if (data < root->data)//if data is less than root, search the data from the left.
	{
		return find(root->left, data);
	}
	else //if data is greater than root, search the data from the right.
	{
		return find(root->right, data);
	}
}

template<typename T>
BST_Node<T>* BST<T>::remove(T& d, BST_Node<T>* root)
{
	if (root == nullptr) //if tree is empty return null.
	{
		return root;
	}
	else if (d < root->data)//if data is less than root, remove the root from the left.
	{
		root->left = remove(d, root->left);
	}
	else if (d > root->data)//if data is greater than root, remove the root from the right.
	{
		root->right = remove(d, root->right);
	}
	else
	{
		//if root has no child
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr) //if root has only one right child
		{
			BST_Node<T>* temp = root->right;
			root->data = temp->data;
			root->left = temp->left;
			root->right = temp->right;
			delete temp;
			temp = nullptr;
		}
		else if (root->right == nullptr) //if root has only one left child
		{
			BST_Node<T>* temp = root->left;
			root->data = temp->data;
			root->left = temp->left;
			root->right = temp->right;
			delete temp;
			temp = nullptr;
		}
		else //if root has a left and right children.
		{
			BST_Node<T>* temp = findMin(root->right);
			root->data = temp->data;
			root->right = remove(temp->data, root->right);
		}
	}
	return root;
}

template<typename T>
void BST<T>::remove(T& d)
{
	remove(d, head);
}

template<typename T>
BST_Node<T>* BST<T>::findMin(BST_Node<T>* root)
{
	BST_Node<T>* current = root;
	while (current->left != nullptr)
	{
		current = current->left;
	}
	return current;
}

template<typename T>
void BST<T>::queueNodes(Queue<BST_Node<T>>& queue, BST_Node<T>* root)
{
	if (root == nullptr)
	{
		return;
	}

	queue.enqueue(*root);
	queueNodes(queue, root->left);
	queueNodes(queue, root->right);
}

template<typename T>
void BST<T>::deleteAll()
{
	Queue<BST_Node<T>> deleteQueue;
	queueNodes(deleteQueue, head);

	while (!deleteQueue.isEmpty())
	{
		delete &(deleteQueue.dequeue());
	}
}