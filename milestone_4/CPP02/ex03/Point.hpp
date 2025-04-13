/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:43:28 by fre007            #+#    #+#             */
/*   Updated: 2025/04/13 15:24:29 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(float x, float y);
	Point(Point const& src);
	~Point();
	Point&	operator=(Point const& rhs);
	Fixed	getx() const;
	Fixed	gety() const;

private:
	Fixed	x;
	Fixed	y;
};