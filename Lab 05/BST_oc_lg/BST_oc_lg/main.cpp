﻿/*
CIS 22C
Lab 05: 
Authors:
Olivier Chan Sion Moy
Luis Guerrero
*/

#include <iostream>

#include "BST.h"

using namespace std;

/**
* preorder
*
* @brief Prints a BST in preorder fashion.
*
* @param The root of the BST to print.
*/
template <typename T>
void preorder(BST<T>&);
template <typename T>
void preorder(BST_Node<T>*);
template <typename T>
void preorder(BST_Node<T>*, int);
/**
* inorder
*
* @brief Prints a BST in inorder fashion.
*
* @param The root of the BST to print.
*/
template <typename T>
void inorder(BST<T>&);
template <typename T>
void inorder(BST_Node<T>*);
template <typename T>
void inorder(BST_Node<T>*, int);
/**
* postorder
*
* @brief Prints a BST in postorder fashion.
*
* @param The root of the BST to print.
*/
template <typename T>
void postorder(BST<T>&);
template <typename T>
void postorder(BST_Node<T>*);
template <typename T>
void postorder(BST_Node<T>*, int);

int main()
{
	//FOR TESTING
	int myArray[10] = {50, 42, 12, 99, 10, 33, 75, 30, 87, 21};
	BST<int> bst = BST<int>();
	for (int i = 0; i < 10; i++)
	{
		bst.insert(myArray[i]);
	}

	cout << "Preorder:" << endl;
	preorder(bst);
	cout << "Inorder:" << endl;
	inorder(bst);
	cout << "Postorder:" << endl;
	postorder(bst);

	system("pause");
	return 0;
}

template <typename T>
void preorder(BST<T>& bst)
{
	preorder(bst.getHead(), 0);
}
template <typename T>
void preorder(BST_Node<T>* root)
{
	preorder(root, 0);
}
template <typename T>
void preorder(BST_Node<T>* root, int level)
{
	if (root == nullptr)
	{
		return;
	}

	cout << root->data << endl;
	preorder(root->left, level + 1);
	preorder(root->right, level + 1);
}

template <typename T>
void inorder(BST<T>& bst)
{
	inorder(bst.getHead(), 0);
}
template <typename T>
void inorder(BST_Node<T>* root)
{
	inorder(root, 0);
}
template <typename T>
void inorder(BST_Node<T>* root, int level)
{
	if (root == nullptr)
	{
		return;
	}

	inorder(root->left, level + 1);
	cout << root->data << endl;
	inorder(root->right, level + 1);
}

template <typename T>
void postorder(BST<T>& bst)
{
	postorder(bst.getHead(), 0);
}
template <typename T>
void postorder(BST_Node<T>* root)
{
	postorder(root, 0);
}
template <typename T>
void postorder(BST_Node<T>* root, int level)
{
	if (root == nullptr)
	{
		return;
	}

	postorder(root->left, level + 1);
	postorder(root->right, level + 1);
	cout << root->data << endl;
}