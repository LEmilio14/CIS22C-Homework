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

void displayDataTypes();

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
		displayDataTypes();
		cin >> type;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (type)
		{
		case TYPE_INT:
		{
			Array<int> intArray(size);

			//User enters array elements
			for (int i = 0; i < size; i++)
			{
				cout << "Enter element " << i + 1 << ": ";
				cin >> intArray[i];
				arrayInt[i] = intArray[i];
				cout << endl;
			}
			cout << endl << endl;
			for (int i = 0; i < size; i++)
			{
				cout << intArray[i] << " ";
			}
			intArray.insertionSortRecursive(arrayInt, size);
			cout << endl << endl;
			for (int j = 0; j < size; j++)
			{
				cout << intArray[j] << " ";
			}
			cout << endl;

			break;
		}
		case TYPE_DOUBLE:
		{
			Array<double> doubArray(size);
			for (int i = 0; i < size; i++)
			{
				cout << "Enter element " << i + 1 << ": ";
				cin >> doubArray[i];
				cout << endl;
			}


			break;
		}
		case TYPE_CHAR:
		{
			Array<char> strArray(size);
			for (int i = 0; i < size; i++)
			{
				cout << "Enter element " << i + 1 << ": ";
				cin >> strArray[i];
				cout << endl;
			}
			break;
		}
		case TYPE_STRING:
		{
			Array<string> chrArray(size);
			for (int i = 0; i < size; i++)
			{
				cout << "Enter element " << i + 1 << ": ";
				cin >> chrArray[i];
				cout << endl;
			}
			break;
		}
		default:
			break;
		}


		cout << "Do you want to sort something else? [1]Yes [2]No" << endl;
		cin >> again;
	} while (again == 1);

	system("pause");
	return 0;
}

void displayDataTypes()
{
	cout << "Choose the type of data you want to sort:" << endl;
	cout << "[1] Integer" << endl;
	cout << "[2] Double" << endl;
	cout << "[3] Char" << endl;
	cout << "[4] String" << endl;

	return;
}