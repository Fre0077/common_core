/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:38:02 by fre007            #+#    #+#             */
/*   Updated: 2025/05/15 14:49:49 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <climits>

int main()
{
	std::cout << "Basic tests" << std::endl;
	Span sp = Span(5);
	sp.addNumber(3);
	sp.addNumber(5);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(17);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "Test with 10000 numbers" << std::endl;

	Span sp2 = Span(10000);
	sp2.addRange(0, 9998);
	
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	std::cout << "Test with 100000 numbers" << std::endl;

	Span sp3 = Span(100000);
	sp3.addRange(0, 99998);

	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	std::cout << "Test with intmax numbers" << std::endl;

	Span sp4 = Span(1000000);
	sp4.addRange(0, 999998);

	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;
}