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

template<typename T>
void insertionSortRecursive(Array<T> arr);

template<typename T>
void swap(T *a, T *b);

template<typename T>
int partition(Array<T>& arr, int start, int end);

template<typename T>
void quickSortRecursive(Array<T>& arr, int start, int end);

template<typename T>
void quickSortRecursive(Array<T> arr);

template <typename T>
void mergeSortRecursive(Array<T>);

template <typename T>
void mergeSortRecursive(Array<T>&, int, int);

template <typename T>
void merge(Array<T>&, const int, const int, const int);

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
			insertionSortRecursive(array);

			//Quick Sort
			quickSortRecursive(array);

			//Merge Sort
			mergeSortRecursive(array);

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
			insertionSortRecursive(array);

			//Quick Sort
			quickSortRecursive(array);

			//Merge Sort
			mergeSortRecursive(array);

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
			insertionSortRecursive(array);

			//Quick Sort
			quickSortRecursive(array);

			//Merge Sort
			mergeSortRecursive(array);

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
			insertionSortRecursive(array);

			//Quick Sort
			quickSortRecursive(array);

			//Merge Sort
			mergeSortRecursive(array);

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

template<typename T>
void insertionSortRecursive(Array<T> arr)
{
	insertionSortRecursive(arr, arr.getLength());
}

template<typename T>
void swap(T *a, T *b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template<typename T>
int partition(Array<T>& arr, int start, int end)
{
	T pivot = arr[end]; //Last elemnt as a pivot point.
	int i = (start - 1); //Index of smaller element.
	for (int j = start; j <= end - 1; j++)
	{
		if (arr[j] >= pivot)
		{
			i++; //Increment the index of the smaller element.
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

template<typename T>
void quickSortRecursive(Array<T>& arr, int start, int end)
{

	if (start < end)
	{
		int part = partition(arr, start, end);
		cout << "Quick Sort - Depth " << start << " to " << end << endl;
		for (int i = 0; i < arr.getLength(); i++)
		{
			cout << "[" << i << "] = " << arr[i] << endl;
		}
		cout << endl;
		quickSortRecursive(arr, start, part - 1);
		quickSortRecursive(arr, part + 1, end);
	}
}

template<typename T>
void quickSortRecursive(Array<T> arr)
{
	quickSortRecursive(arr, 0, arr.getLength() - 1);
}

template <typename T>
void mergeSortRecursive(Array<T> arr)
{
	mergeSortRecursive(arr, 0, arr.getLength() - 1);
}

template <typename T>
void mergeSortRecursive(Array<T>& arr, int start, int end)
{	
	//Recursion case
	if (start < end)
	{
		//Split the array into 2 parts and sort them 
		int middle = (start + end) / 2;
		mergeSortRecursive(arr, start, middle);
		mergeSortRecursive(arr, middle + 1, end);

		//Merge the 2 parts together
		merge(arr, start, middle, end);

		//Print out the array
		cout << "Merge Sort - " << start << " to " << end << endl;
		for (int i = 0; i < arr.getLength(); i++)
		{
			cout << "[" << i << "] = " << arr[i] << endl;
		}
		cout << endl;
	}
}

template <typename T>
void merge(Array<T>& parentArr, const int start, const int middle, const int end)
{
	//Copy the left and right subarrays from the parent array
	const int leftSize = middle - start + 1;
	const int rightSize = end - middle;

	T* leftArr = new T[leftSize];
	T* rightArr = new T[rightSize];

	for (int i = 0; i < leftSize; i++)
	{
		leftArr[i] = parentArr[start + i];
	}
	for (int i = 0; i < rightSize; i++)
	{
		rightArr[i] = parentArr[middle + i + 1];
	}

	//Merge the two subarrays into the parent array
	int leftIndex = 0;
	int rightIndex = 0;
	int parentIndex = start;

	while (leftIndex < leftSize && rightIndex < rightSize)
	{
		if (leftArr[leftIndex] >= rightArr[rightIndex])
		{
			parentArr[parentIndex] = leftArr[leftIndex];
			leftIndex++;
		}
		else
		{
			parentArr[parentIndex] = rightArr[rightIndex];
			rightIndex++;
		}
		parentIndex++;
	}

	//Merge remaining elements
	while (leftIndex < leftSize)
	{
		parentArr[parentIndex] = leftArr[leftIndex];
		leftIndex++;
		parentIndex++;
	}
	while (rightIndex < rightSize)
	{
		parentArr[parentIndex] = rightArr[rightIndex];
		rightIndex++;
		parentIndex++;
	}

	delete[] leftArr;
	delete[] rightArr;
}