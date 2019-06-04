/********************************************************************************
********************************** BST_Node *************************************
*********************************************************************************
* This class is part of a BST (binary search tree) abstract data structure.
* The purpose of this class is to act as a data-containing node in a tree structure,
* with each node having a branch to two deeper nodes.
*****************
***** USAGE *****
*****************
* This class should only be used within the BST class.
* Creating a BST_Node must be done with a reference to the contained data.
* The left and right nodes may be given as parameters or set using functions.
*********************************************************************************/

#pragma once

template <typename T>
struct BST_Node
{
public:
	T& data;
	T& secondary;
	BST_Node<T>* left;
	BST_Node<T>* right;

	BST_Node(T&, T&, BST_Node<T>* = nullptr, BST_Node<T>* = nullptr);
	virtual ~BST_Node();
};

template <typename T>
BST_Node<T>::BST_Node(T& d, T& s, BST_Node<T>* l, BST_Node<T>* r) : data(d), secondary(s), left(l), right(r)
{

}

template <typename T>
BST_Node<T>::~BST_Node()
{
	
}