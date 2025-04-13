/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:43:40 by fre007            #+#    #+#             */
/*   Updated: 2025/04/13 15:40:49 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
Point::Point() : x(Fixed(0)), y(Fixed(0))
{
	//std::cout << "created default Point" << std::endl;
}

Point::Point(float x, float y) : x(Fixed(x)), y(Fixed(y))
{
	//std::cout << "created value Point" << std::endl;
}

Point::Point(Point const& src)
{
	//std::cout << "copy Point" << std::endl;
	this->x = src.x;
	this->y = src.y;
}

Point::~Point()
{
	//std::cout << "destried Point" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Point&	Point::operator=(Point const& rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
	}
	return *this;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
Fixed	Point::getx() const
{
	//std::cout << "get x" << std::endl;
	return this->x;
}

Fixed	Point::gety() const
{
	//std::cout << "get y" << std::endl;
	return this->y;
}