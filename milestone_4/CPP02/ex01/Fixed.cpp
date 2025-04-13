/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:19:31 by fre007            #+#    #+#             */
/*   Updated: 2025/04/13 11:58:30 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
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
	src = roundf(src * (1 << fractionalBit));
	this->value = (int)src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
Fixed&	Fixed::operator=(Fixed const& rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->value = rhs.value;
	return *this;
}

Fixed&	Fixed::operator++()
{
	//std::cout << "post-incremental operator called" << std::endl;
	this->value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	//std::cout << "pre-incremental operator called" << std::endl;
	Fixed	tmp = *this;
	this->value++;
	return tmp;
}

Fixed&	Fixed::operator--()
{
	//std::cout << "post-decremental operator called" << std::endl;
	this->value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	//std::cout << "pre-decremental operator called" << std::endl;
	Fixed	tmp = *this;
	this->value--;
	return tmp;
}

float	Fixed::operator+(Fixed const& rhs)
{
	//std::cout << "aritmatic operator called" << std::endl;
	return (this->toFloat() + rhs.toFloat());
}

float	Fixed::operator-(Fixed const& rhs)
{
	//std::cout << "aritmatic operator called" << std::endl;
	return (this->toFloat() - rhs.toFloat());
}

float	Fixed::operator*(Fixed const& rhs)
{
	//std::cout << "aritmatic operator called" << std::endl;
	return (this->toFloat() * rhs.toFloat());
}

float	Fixed::operator/(Fixed const& rhs)
{
	//std::cout << "aritmatic operator called" << std::endl;
	return (this->toFloat() / rhs.toFloat());
}

int	Fixed::operator>(Fixed const& rhs)
{
	//std::cout << "comparison operator called" << std::endl;
	if (this->value > rhs.value)
		return 1;
	return 0;
}

int	Fixed::operator<(Fixed const& rhs)
{
	//std::cout << "comparison operator called" << std::endl;
	if (this->value < rhs.value)
		return 1;
	return 0;
}

int	Fixed::operator>=(Fixed const& rhs)
{
	//std::cout << "comparison operator called" << std::endl;
	if (this->value >= rhs.value)
		return 1;
	return 0;
}

int	Fixed::operator<=(Fixed const& rhs)
{
	//std::cout << "comparison operator called" << std::endl;
	if (this->value <= rhs.value)
		return 1;
	return 0;
}

int	Fixed::operator==(Fixed const& rhs)
{
	//std::cout << "comparison operator called" << std::endl;
	if (this->value == rhs.value)
		return 1;
	return 0;
}

int	Fixed::operator!=(Fixed const& rhs)
{
	//std::cout << "comparison operator called" << std::endl;
	if (this->value != rhs.value)
		return 1;
	return 0;
}

std::ostream& operator<<(std::ostream& out, Fixed const& rhs)
{
	out << rhs.toFloat();
	return out;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}
int	Fixed::getRawBits(void)
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	//std::cout << "conversion to float" << std::endl;
	return ((float)value / (float)(1 << fractionalBit));
}

int		Fixed::toInt( void ) const
{
	//std::cout << "conversione to int" << std::endl;
	return (value >> fractionalBit);
}
