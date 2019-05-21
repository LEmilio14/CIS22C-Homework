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

#include "ExceptionInvalidArraySize.h"
#include "ExceptionInvalidArrayIndex.h"

template <typename T>
class Array
{
private:
	T* data;
	const int length;
public:
	Array(int);
	~Array();
	Array(const Array<T>&);

	Array& operator=(const Array) = delete;


	int getLength();
	void swap(T*, T*);
	int partition(Array<T>&, int, int);
	int getLength() const;

	T& operator[](int);
};

template<typename T>
Array<T>::Array(int len) : length(len), data(new T[len])
{
	if (len < 0)
	{
		throw ExceptionInvalidArraySize();
	}
}

template<typename T>
Array<T>::~Array()
{
	delete[] data;
}

template<typename T>
Array<T>::Array(const Array<T>& array) : length(array.getLength()), data(new T[array.getLength()])
{
	if (array.getLength() < 0)
	{
		throw ExceptionInvalidArraySize();
	}

	for (int i = 0; i < array.getLength(); i++)
	{
		data[i] = array.data[i];
	}
}

template<typename T>
int Array<T>::getLength() const
{
	return length;
}

template<typename T>
void Array<T>::swap(T *a, T *b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template<typename T>
int Array<T>::partition(Array<T>& arr, int start, int end)
{
	int pivot = arr[end];
	int i = (start - 1);
	for (int j = start; j <= end; j++)
	{
		if (arr[j] >= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[end]);
	return (i + 1);
}

template<typename T>
T& Array<T>::operator[](int index)
{
	if (index >= 0 && index <= length)
	{
		return data[index];
	}
	else
	{
		throw ExceptionInvalidArrayIndex();
	}
}