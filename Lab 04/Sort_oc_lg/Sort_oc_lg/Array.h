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
	int length;
public:
	Array(int);
	~Array();

	int getLength();
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
int Array<T>::getLength()
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