/********************************************************************************
************************************ Array **************************************
*********************************************************************************
* This class is a container for an array, and should be used as an array.
* The subscript operator is overloaded to act like an array/vector.
* The array size is fixed after construction.
*****************
***** USAGE *****
*****************
* This class should be called using template initialization.
* Array size can be aquired with getLength().
* Data should be accessed using the subscript operator (ex. myArray[0]).
* Copying the object creates a new Array with duplicate data.
* The assignment operator is deleted.
* Exceptions will be thrown if:
*	Array constructed with negative size (ExceptionInvalidArraySize)
*	Attempt to access data outside the array's managed space (ExceptionInvalidArrayIndex)
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
	/**
	* getLength
	*
	* @brief Returns the size of the contained array.
	*
	* @return The size of the contained array.
	*/
	int getLength() const;
	/**
	* operator[]
	*
	* @brief Returns the data at the passed index.
	*
	* @param index The index to get the data from the contained array.
	*
	* @return The data at the passed index.
	*/
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