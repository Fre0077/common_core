/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:59:06 by fre007            #+#    #+#             */
/*   Updated: 2025/05/10 10:35:43 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	for(unsigned int i = 0; i < n; i++)
		_array[i] = T();
}

template <typename T>
Array<T>::Array(Array const& src) : _array(new T[src._size]), _size(src._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& src)
{
	if (this != &src) {
		delete[] _array;
		_array = new T[src._size];
		_size = src._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src._array[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw Array::OutOfBounds();
	return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}


template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return "Error: out of bounds";
}

#endif