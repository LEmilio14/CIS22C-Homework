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
#include <iomanip>

#include "BST.h"
#include "Person.h"

using namespace std;
\
/**
* preorder
*
* @brief Prints a BST in preorder fashion.
*
* @param The root of the BST to print.
*/
template <typename T>
void preorder(ostream& os, BST<T>&);
template <typename T>
void preorder(ostream& os, BST_Node<T>*);
/**
* inorder
*
* @brief Prints a BST in inorder fashion.
*
* @param The root of the BST to print.
*/
template <typename T>
void inorder(ostream& os, BST<T>&);
template <typename T>
void inorder(ostream& os, BST_Node<T>*);
/**
* postorder
*
* @brief Prints a BST in postorder fashion.
*
* @param The root of the BST to print.
*/
template <typename T>
void postorder(ostream& os, BST<T>&);
template <typename T>
void postorder(ostream& os, BST_Node<T>*);
/**
* breadthFirst
*
* @brief Prints a BST in breadth first fashion.
*
* @param The root of the BST to print.
*/
template <typename T>
void breadthFirst(ostream& os, BST<T>&);
template <typename T>
void breadthFirst(ostream& os, Queue<BST_Node<T>*>&, BST_Node<T>*);
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

	ofstream outNames("NamesOutput.txt");
	outNames << "====== Names ======" << "\t" << "====== Birthdays ======" << endl;
	outNames << "\t\t***Pre-order***" << endl;
	preorder(outNames, bstName);
	outNames << "\t\t***Post-Order***" << endl;
	postorder(outNames, bstName);
	outNames.close();

	ofstream outBdays("BirthdaysOutput.txt");
	outBdays << "====== Birthdays ======" << "\t" << "====== Names ======" << endl;
	outBdays << "\t\t***In-Order***" << endl;
	inorder(outBdays, bstBday);
	outBdays << "\t\t***Breadth-First***" << endl;
	breadthFirst(outBdays, bstBday);
	outBdays.close();

	//Delete dynamic
	for (int i = 0; i < size / 2; i++)
	{
		delete personArray[i];
	}

	delete[] names;
	delete[] bdays;

	system("pause");
	return 0;
}

template <typename T>
void preorder(ostream& os, BST<T>& bst)
{
	preorder(os, bst.getHead());
}
template <typename T>
void preorder(ostream& os, BST_Node<T>* root)
{
	if (root == nullptr)
	{
		return;
	}

	os << left << setw(17) << root->key 
		<< right << setw(20) << root->data << endl;
	preorder(os, root->left);
	preorder(os, root->right);
}

template <typename T>
void inorder(ostream& os, BST<T>& bst)
{
	inorder(os, bst.getHead());
}
template <typename T>
void inorder(ostream& os, BST_Node<T>* root)
{
	if (root == nullptr)
	{
		return;
	}

	inorder(os, root->left);
	os << left << setw(28) << root->key
		<< right  << root->data << endl;
	inorder(os, root->right);
}

template <typename T>
void postorder(ostream& os, BST<T>& bst)
{
	postorder(os, bst.getHead());
}
template <typename T>
void postorder(ostream& os, BST_Node<T>* root)
{
	if (root == nullptr)
	{
		return;
	}

	postorder(os, root->left);
	postorder(os, root->right);
	os << left << setw(17) << root->key
		<< right << setw(20) << root->data << endl;
}

template <typename T>
void breadthFirst(ostream& os, BST<T>& bst)
{
	//Create empty queue
	Queue<BST_Node<T>*> breadthQueue;
	breadthFirst(os, breadthQueue, bst.getHead());
}
template <typename T>
void breadthFirst(ostream& os, Queue<BST_Node<T>*>& queue, BST_Node<T>* root)
{
	if (root == nullptr)
	{
		return;
	}
	
	//Print current node
	os << left << setw(28) << root->key
		<< right << root->data << endl;
	//Enqueue left and right
	if (root->left != nullptr)
	{
		queue.enqueue(root->left);
	}
	if (root->right != nullptr)
	{
		queue.enqueue(root->right);
	}
	//Recurse with a dequeue
	if (!queue.isEmpty())
	{
		breadthFirst(os, queue, queue.dequeue());
	}
	//The queue was empty, the traversal is complete
}

int getFileSize(const std::string &fileName)
{
	ifstream file(fileName);

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
	return fileSize;
}
