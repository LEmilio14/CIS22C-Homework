#include<iostream>
#include<string>
#include<fstream>
#include"Array.h"

using namespace std;

void displayDataTypes();

int main()
{
	int size, userChoice, again;
	do 
	{
		cout << "How many elements would you like to sort? (max elements 32)" << endl;
		cin >> size;
		while (size > 32)
		{
			cout << "The number of elemnts exceed the maximun amount, try again" << endl;
			cout << "How many elements would you like to sort? (max elements 32)" << endl;
			cin >> size;
		}
		cout << endl;
		displayDataTypes();
		cin >> userChoice;
	
		switch (userChoice)
		{
		case 1:
		{
			int *arrayInt;
			Array<int> intArray(size);
			
			for (int i = 0; i < size; i++)
			{
				cout << "Enter element "<< i + 1 << ": ";
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
		case 2:
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
		case 3:
		{
			Array<string> strArray(size);
			for (int i = 0; i < size; i++)
			{
				cout << "Enter element " << i + 1 << ": ";
				cin >> strArray[i];
				cout << endl;
			}
			break;
		}
		case 4: 
		{
			Array<char> chrArray(size);
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
	cout << "Choose the type of data you want to sort" << endl;
	cout << "[1] Integer" << endl;
	cout << "[2] Double" << endl;
	cout << "[3] String" << endl;
	cout << "[4] Char" << endl;

	return;
}