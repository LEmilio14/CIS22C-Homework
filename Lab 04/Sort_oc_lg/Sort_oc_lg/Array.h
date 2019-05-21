/********************************************************************************
************************************ Array **************************************
*********************************************************************************
* 
*****************
***** USAGE *****
*****************
* 
*********************************************************************************/

#pragma once

template <typename T>
class Array
{
private:
	int length;
	T *data;
public:
	Array();
	Array(int);
	~Array();
	int getLength();
	void insertionSortRecursive(T*, int);
	T& operator[](int);
};

template<typename T>
Array<T>::Array()
{
	length = 0;
	data = nullptr;
}

template<typename T>
Array<T>::Array(int len)
{
	length = len;
	data = new T[len];
}

template<typename T>
Array<T>::~Array()
{
	delete[] data;
}

template<typename T>
int Array<T>::getLength()
{
	return length;
}

template<typename T>
void Array<T>::insertionSortRecursive(T* arr, int size)
{
	if (size <= 1)
	{
		return;
	}
	else
	{
		insertionSortRecursive(arr, size - 1);
		int last = arr[size - 1];
		int j = size - 2;

		while (j >= 0 && arr[j] > last)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = last;
	}
}

template<typename T>
T& Array<T>::operator[](int index)
{
	return data[index];
}