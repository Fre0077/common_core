/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:42:58 by fre007            #+#    #+#             */
/*   Updated: 2025/05/10 10:19:05 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <algorithm>
# include <iostream>
# include <climits>
# include <iomanip>
# include <set>

template <typename T>
class Array
{
private:
	T			*_array;
	unsigned int _size;
public:
	Array();
	Array(unsigned int n);
	Array(Array const& src);
	~Array();
	Array& operator=(Array const& src);
	T& operator[](unsigned int i);
	unsigned int size() const;
	class OutOfBounds : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#include "Array.tpp"

#endif