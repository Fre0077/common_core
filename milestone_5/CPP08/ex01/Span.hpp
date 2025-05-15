/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:12:45 by fde-sant          #+#    #+#             */
/*   Updated: 2025/05/15 14:23:41 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <iostream>
# include <climits>
# include <iomanip>
# include <set>

class Span
{
private:
	unsigned int	N;
	std::vector<int> v;
	Span ();
public:
	Span(unsigned int n);
	Span(Span const& copy);
	Span& operator=(Span const& copy);
	~Span();
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			addNumber(int n);
	void			addRange(int first, int last);
	class AlreadyFull : public std::exception
	{
		virtual const char* what() const throw();
	};
	class NotEnoughNumbers : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif