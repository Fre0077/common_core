/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:12:52 by fde-sant          #+#    #+#             */
/*   Updated: 2025/05/15 14:48:33 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
Span::Span(unsigned int n) : N(n) {}

Span::Span(Span const& copy) : N(copy.N), v(copy.v) {}

Span::~Span() {}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Span& Span::operator=(Span const& copy)
{
	if (this == &copy)
	return *this;
	N = copy.N;
	v = copy.v;
	return *this;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
unsigned int Span::shortestSpan()
{
	if (v.size() < 2)
	throw Span::NotEnoughNumbers();
	unsigned int i = 0, j = 1;
	unsigned int size = v.size();
	unsigned int currentSpan = std::abs(v[j] - v[i]);
	while (j < size)
	{
		if (static_cast<unsigned int>(std::abs(v[j] - v[i])) < currentSpan)
		currentSpan = v[j] - v[i];
		i++;
		j++;
	}
	return currentSpan;
}

unsigned int Span::longestSpan()
{
	if (v.size() < 2)
	throw Span::NotEnoughNumbers();
	return v[v.size() - 1] - v[0];
}

void Span::addNumber(int n)
{
	if (v.size() >= N)
	throw Span::AlreadyFull();
	v.insert(std::lower_bound(v.begin(), v.end(), n), n);
}

void Span::addRange(int first, int last)
{
	if (first >= last)
		return;
	if (v.size() >= N)
	throw Span::AlreadyFull();
	while (first <= last)
	{
		v.insert(std::lower_bound(v.begin(), v.end(), first), first);
		first++;
		if (v.size() >= N)
		throw Span::AlreadyFull();
	}
}

const char* Span::AlreadyFull::what() const throw()
{
	return "The container is already full";
}

const char* Span::NotEnoughNumbers::what() const throw()
{
	return "Not enough numbers to compute the span";
}