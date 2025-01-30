#ifndef ARRAY_H
#define ARRAY_H

#include <exception>
#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
private:
	T* _data;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	~Array();

	Array& operator=(const Array& other);

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	unsigned int size() const;
};

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
	std::cout << "Default Constructor Called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (n > 0)
	{
		_data = new T[n];
		for (unsigned int i = 0; i < n; ++i)
			_data[i] = T();
	} else
		_data = NULL;
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	if (_size > 0)
	{
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	} else
		_data = NULL;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		if (_size > 0)
		{
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		} else
			_data = NULL;
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}


template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif