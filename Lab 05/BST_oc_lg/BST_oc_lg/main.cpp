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
#include "Person.h"

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
/**
* breadthFirst
*
* @brief Prints a BST in breadth first fashion.
*
* @param The root of the BST to print.
*/
template <typename T>
void breadthFirst(BST<T>&);
template <typename T>
void breadthFirst(BST_Node<T>*);
template <typename T>
void breadthFirst(BST_Node<T>*, int);
/**
* getFileSize
*
* @brief Gets the size of a file depending on how many lines it has.
*
* @param The name of the file.
*/
int getFileSize(const std::string &fileName);

int main()
{
	int size = 0;
	
	ifstream readFile("InputData.txt");
	size = getFileSize("InputData.txt");

	string* names = new string[size / 2];
	string* bdays = new string[size / 2];
	string line;

	if (readFile.is_open())
	{
		int i = 0;
		while (!readFile.eof())
		{
			getline(readFile, line);
			names[i] = line;
			getline(readFile, line);
			bdays[i] = line;
			i++;
		}

	}
	else
	{
		cout << "File Not Open" << endl;
	}

	Person* personArray[7];
	for (int i = 0; i < size / 2; i++)
	{
		personArray[i] = new Person(names[i], bdays[i]);
	}

	BST<string> bstName = BST<string>();
	BST<string> bstBday = BST<string>();
	for (int i = 0; i < 7; i++)
	{
		bstName.insert(personArray[i]->name, personArray[i]->birthday);
		bstBday.insert(personArray[i]->birthday, personArray[i]->name);
	}
	cout << "====== Names =======" << endl;
	cout << "Preorder:" << endl;
	preorder(bstName);
	cout << endl;
	cout << "Inorder:" << endl;
	inorder(bstName);
	cout << endl;
	cout << "Postorder:" << endl;
	postorder(bstName);
	cout << endl;
	cout << "====== Birthdays =======" << endl;
	cout << "Preorder:" << endl;
	preorder(bstBday);
	cout << endl;
	cout << "Inorder:" << endl;
	inorder(bstBday);
	cout << endl;
	cout << "Postorder:" << endl;
	postorder(bstBday);
	cout << endl;

	for (int i = 0; i < size / 2; i++)
	{
		delete personArray[i];
	}

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

template <typename T>
void breadthFirst(BST<T>& bst)
{
	breadthFirst(bst.getHead(), 0);
}
template <typename T>
void breadthFirst(BST_Node<T>* root)
{
	breadthFirst(root, 0);
}
template <typename T>
void breadthFirst(BST_Node<T>* root, int level)
{
	if (root == nullptr)
	{
		return;
	}

	breadthFirst(root->left, level + 1);
	breadthFirst(root->right, level + 1);
	cout << root->data << endl;
}

int getFileSize(const std::string &fileName)
{
	ifstream file(fileName/*ifstream::in | ifstream::binary*/);

	string line;
	int fileSize = 0;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			fileSize++;
		}
		file.close();
	}
	/*
	file.seekg(0, ios::end);
	int fileSize = file.tellg();
	file.close();
	*/

	return fileSize;
}
