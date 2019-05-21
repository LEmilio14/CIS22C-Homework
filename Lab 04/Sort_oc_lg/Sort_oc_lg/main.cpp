/*
CIS 22C
Lab 04: 
Authors:
Olivier Chan Sion Moy
Luis Guerrero
*/

#include <iostream>
#include <string>
#include <fstream>

#include "Array.h"

using namespace std;

template<typename T>
void insertionSortRecursive(Array<T>&, int);

int main()
{
	constexpr int SORT_MAX_SIZE = 32;
	constexpr int TYPE_INT = 1;
	constexpr int TYPE_DOUBLE = 2;
	constexpr int TYPE_CHAR = 3;
	constexpr int TYPE_STRING = 4;
	
	int size, type, again;
	//Repeat until the user exits the program
	do
	{
		//Get the requested size of the array, must be between 0 and SORT_MAX_SIZE
		do
		{
			cout << "How many elements would you like to sort? (max elements " << SORT_MAX_SIZE << ")" << endl;
			cin >> size;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (size < 0 || size > SORT_MAX_SIZE)
			{
				cout << "Invalid size. Size must be between 0 and " << SORT_MAX_SIZE << "." << endl;
			}
			cout << endl;
		} while (size < 0 || size > SORT_MAX_SIZE);

		//Get the requested type of the array, 1 = int, 2 = double, 3 = char, 4 = string
		cout << "Choose the type of data you want to sort:" << endl;
		cout << "[" << TYPE_INT << "] Integer" << endl;
		cout << "[" << TYPE_DOUBLE << "] Double" << endl;
		cout << "[" << TYPE_CHAR << "] Char" << endl;
		cout << "[" << TYPE_STRING << "] String" << endl;
		cin >> type;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;

		switch (type)
		{
		case TYPE_INT:
		{
			//Create array of type int
			Array<int> array(size);

			//User enters array elements
			for (int i = 0; i < size; i++)
			{
				cout << "Enter element " << i << ": ";
				cin >> array[i];
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << endl;

			//Sort the array using Insertion Sort, Quick Sort, and Merge Sort
			insertionSortRecursive(array, array.getLength());
			break;
		}
		case TYPE_DOUBLE:
		{
			//Create array of type double
			Array<double> array(size);

			//User enters array elements
			for (int i = 0; i < size; i++)
			{
				cout << "Enter element " << i << ": ";
				cin >> array[i];
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << endl;

			//Sort the array using Insertion Sort, Quick Sort, and Merge Sort
			insertionSortRecursive(array, array.getLength());
			break;
		}
		case TYPE_CHAR:
		{
			//Create array of type char
			Array<char> array(size);

			//User enters array elements
			for (int i = 0; i < size; i++)
			{
				cout << "Enter element " << i << ": ";
				cin >> array[i];
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << endl;

			//Sort the array using Insertion Sort, Quick Sort, and Merge Sort
			insertionSortRecursive(array, array.getLength());
			break;
		}
		case TYPE_STRING:
		{
			//Create array of type string
			Array<string> array(size);

			//User enters array elements
			for (int i = 0; i < size; i++)
			{
				cout << "Enter element " << i << ": ";
				cin >> array[i];
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << endl;

			//Sort the array using Insertion Sort, Quick Sort, and Merge Sort
			insertionSortRecursive(array, array.getLength());
			break;
		}
		default:
			//The user didn't pick a correct type
			cout << "Invalid type. Restarting..." << endl;
			break;
		}

		cout << "Do you want to try again? [1] Yes [2] No" << endl;
		cin >> again;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
	} while (again == 1);

	system("pause");
	return 0;
}

template<typename T>
void insertionSortRecursive(Array<T>& arr, int size)
{
	if (size <= 1)
	{
		return;
	}
	else
	{
		insertionSortRecursive(arr, size - 1);
		T last = arr[size - 1];
		int j = size - 2;

		while (j >= 0 && arr[j] < last)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = last;
	}

	cout << "Insertion Sort - Depth " << size << endl;
	for (int i = 0; i < arr.getLength(); i++)
	{
		cout << "[" << i << "] = " << arr[i] << endl;
	}
	cout << endl;
}