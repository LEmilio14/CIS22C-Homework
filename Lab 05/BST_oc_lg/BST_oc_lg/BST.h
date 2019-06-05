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
	BST_Node<T>* remove(T, BST_Node<T>*);
	BST_Node<T>* find(T, BST_Node<T>*, bool);
	BST_Node<T>* findInorderSuccessor(BST_Node<T>*); //Pass the right child of the node to find the successor of.
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
	* @brief Recursively deletes the node with matching key from the tree.
	*
	* @param The key of the node to delete.
	*/
	void remove(T);
	/**
	* find
	*
	* @brief Recursively finds the node with the matching key from the tree.
	*
	* @param T The data to search for.
	*
	* @param bool Whether to search for matching key or matching data. True searches for matching key.
	*
	* @return The found BST_Node.
	*/
	BST_Node<T>* find(T, bool = true);
	/**
	* deleteAll
	*
	* @brief Deletes all managed nodes using a queue.
	*/
	void deleteAll();
	/**
	* modify
	*
	* @brief Modifies the requested node by searching for a matching key, then replacing either key or data with the second passed reference. Replacing key or data is determined by the bool parameter.
	*
	* @param T The key to search for.
	*
	* @param T& The new key/data to replace the old key/data.
	*
	* @param bool Whether to replace key or data. True replaces the key.
	*/
	void modify(T, T&, bool replaceKey = true);
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
void BST<T>::insert(T& k, T& d)
{
	insert(k, d, head);
}

template <typename T>
BST_Node<T>* BST<T>::insert(T& k, T& d, BST_Node<T>* root)
{
	//The BST is completely empty
	if (head == nullptr)
	{
		head = new BST_Node<T>(k, d);
		return head;
	}
	
	//If the root is non-existent, create a new node and return it - the new node will be saved in the previous call
	if (root == nullptr)
	{
		return new BST_Node<T>(k, d);
	}

	//If the new data is less than root, recur for left root
	if (k < root->key)
	{
		root->left = insert(k, d, root->left);
	}
	//If the new data is greater or equal than root, recur for right root
	else
	{
		root->right = insert(k, d, root->right);
	}

	//Return the root so previous recursion calls keep their current values for left and right
	return root;
}

template<typename T>
BST_Node<T>* BST<T>::find(T searchTerm, bool searchForKey)
{
	return find(searchTerm, head, searchForKey);
}

template<typename T>
BST_Node<T>* BST<T>::find(T searchTerm, BST_Node<T>* root, bool searchForKey)
{
	if (root == nullptr)//if the tree is empty, then return null
	{
		return nullptr;
	}
	else if (searchForKey)//Match searchterm to key
	{
		if (searchTerm == root->key)
		{
			return root;
		}
		else if (searchTerm < root->key) //if data is less than root, search the data from the left.
		{
			return find(searchTerm, root->left, searchForKey);
		}
		else if (searchTerm > root->key) //if data is greater than root, search the data from the right.
		{
			return find(searchTerm, root->right, searchForKey);
		}
	}
	else if (!searchForKey)//Match searchterm to data
	{
		if (searchTerm == root->data)
		{
			return root;
		}
		else if (searchTerm < root->data) //if data is less than root, search the data from the left.
		{
			return find(searchTerm, root->left, searchForKey);
		}
		else if (searchTerm > root->data) //if data is greater than root, search the data from the right.
		{
			return find(searchTerm, root->right, searchForKey);
		}
	}

	return nullptr;
}

template<typename T>
void BST<T>::remove(T key)
{
	remove(key, head);
}

template<typename T>
BST_Node<T>* BST<T>::remove(T key, BST_Node<T>* root)
{
	if (root == nullptr) //if tree is empty return null.
	{
		return root;
	}
	else if (key < root->key)//if data is less than root, remove the root from the left.
	{
		root->left = remove(key, root->left);
	}
	else if (key > root->key)//if data is greater than root, remove the root from the right.
	{
		root->right = remove(key, root->right);
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
			root->key = temp->key;
			root->data = temp->data;
			root->left = temp->left;
			root->right = temp->right;
			delete temp;
			temp = nullptr;
		}
		else if (root->right == nullptr) //if root has only one left child
		{
			BST_Node<T>* temp = root->left;
			root->key = temp->key;
			root->data = temp->data;
			root->left = temp->left;
			root->right = temp->right;
			delete temp;
			temp = nullptr;
		}
		else //if root has a left and right children.
		{
			BST_Node<T>* temp = findInorderSuccessor(root->right);
			root->key = temp->key;
			root->data = temp->data;
			root->right = remove(temp->key, root->right);
		}
	}
	return root;
}

template<typename T>
BST_Node<T>* BST<T>::findInorderSuccessor(BST_Node<T>* root)
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

template<typename T>
void BST<T>::modify(T searchKey, T& replacementData, bool replaceKey)
{
	//Find the node to replace, by key
	BST_Node<T>* nodeToModify = find(searchKey);

	if (nodeToModify == nullptr)
	{
		throw "Node to modify does not exist."; //TODO: replace this string exception with an exception class
	}

	//If we are replacing data, simply replace it
	if (!replaceKey)
	{
		nodeToModify->data = replacementData;
	}
	//Otherwise we need to create a new node and insert it, and delete the "modified" node.
	else
	{
		insert(replacementData, nodeToModify->data);
		remove(nodeToModify->key, nodeToModify);
	}
}