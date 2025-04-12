/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:19:31 by fre007            #+#    #+#             */
/*   Updated: 2025/04/12 13:11:34 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = src.value;
}

Fixed::Fixed(int src)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = src << fractionalBit;
}

Fixed::Fixed(float src)
{
	std::cout << "Float constructor called" << std::endl;
	src = src * 256;
	this->value = (int)src;
}

Fixed&	Fixed::operator=(Fixed const& rhs)
{
	if (this != &rhs)
		this->value = rhs.value;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

int	Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (value / 256);
}

int		Fixed::toInt( void ) const
{
	return (value >> fractionalBit);
}

std::ostream& operator<<(std::ostream& out, Fixed const& rhs)
{
    out << rhs.toFloat();
    return out;
}