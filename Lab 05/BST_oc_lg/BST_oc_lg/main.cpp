/*
CIS 22C
Lab 05: 
Authors:
Olivier Chan Sion Moy
Luis Guerrero
*/

#include <iostream>
#include <fstream>
#include <string>

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
	string name, bday;

	BST<string> bstName = BST<string>();
	BST<string> bstBday = BST<string>();

	ifstream readFile ("InputData.txt");
	if (readFile.is_open())
	{
		while (getline(readFile, name, '\n'))
		{
			getline(readFile, bday);
			cout << name << endl;
			cout << bday << endl;
		}
	}






	//FOR TESTING
	int myArray[10] = {50, 42, 12, 99, 10, 33, 75, 30, 87, 21};
	int item1, item2;
	BST<int> bst = BST<int>();
	for (int i = 0; i < 10; i++)
	{
		bst.insert(myArray[i]);
	}

	cout << "Preorder:" << endl;
	preorder(bst);
	cout << endl;
	cout << "Inorder:" << endl;
	inorder(bst);
	cout << endl;
	cout << "Postorder:" << endl;
	postorder(bst);
	cout << endl;

	cout << "Enter the item to search" << endl;
	cin >> item1;
	if (bst.search(item1) == true)
	{
		cout << "Found" << endl;
	}
	else
	{
		cout << "Not Found" << endl;
	}
	cout << endl;

	cout << "Would you like to remove an item?" << endl;
	cin >> item2;
	bst.remove(item2);
	cout << endl;
	cout << "Inorder:" << endl;
	inorder(bst);
	cout << endl;

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