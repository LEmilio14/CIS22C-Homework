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