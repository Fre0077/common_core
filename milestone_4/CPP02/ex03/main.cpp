/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:40:05 by fre007            #+#    #+#             */
/*   Updated: 2025/04/13 15:43:23 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	{
		const Point a;
		const Point b(10, 0);
		const Point c(0, 10);
		const Point point(1, 1);

		if (bsp(a, b, c, point) == true)
			std::cout << "TRUE" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
	}
	{
		Point a(-1.5, 3);
		Point b(2.5, 2.5);
		Point c(-1, -2);
		Point point(2.45, 2.4);
		if (bsp(a, b, c, point) == true)
			std::cout << "TRUE" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
	}
	return (0);
}

