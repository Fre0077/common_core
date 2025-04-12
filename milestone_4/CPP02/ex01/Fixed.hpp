/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:11:55 by fre007            #+#    #+#             */
/*   Updated: 2025/04/12 13:10:59 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const& src);
	Fixed(int src);
	Fixed(float src);

	Fixed& operator=(Fixed const& rhs);
	int		getRawBits(void);
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					value;
	static const int	fractionalBit = 8;
};

std::ostream& operator<<(std::ostream& out, Fixed const& rhs);