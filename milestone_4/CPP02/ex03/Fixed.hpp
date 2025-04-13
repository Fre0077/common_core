/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:11:55 by fre007            #+#    #+#             */
/*   Updated: 2025/04/13 11:58:16 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
#include <cmath>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const& src);
	Fixed(int src);
	Fixed(float src);

	Fixed& operator=(Fixed const& rhs);
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	float operator+(Fixed const& rhs);
	float operator-(Fixed const& rhs);
	float operator*(Fixed const& rhs);
	float operator/(Fixed const& rhs);
	int operator>(Fixed const& rhs);
	int operator<(Fixed const& rhs);
	int operator>=(Fixed const& rhs);
	int operator<=(Fixed const& rhs);
	int operator==(Fixed const& rhs);
	int operator!=(Fixed const& rhs);
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed const& min(Fixed const& a, Fixed const& b);
	static Fixed const& max(Fixed const& a, Fixed const& b);
	static Fixed& max(Fixed& a, Fixed& b);
	int		getRawBits(void);
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					value;
	static const int	fractionalBit = 8;
};

std::ostream& operator<<(std::ostream& out, Fixed const& rhs);