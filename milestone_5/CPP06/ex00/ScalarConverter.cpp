/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:44:12 by francesco         #+#    #+#             */
/*   Updated: 2025/04/24 12:04:40 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}


ScalarConverter::~ScalarConverter()
{
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
void ScalarConverter::convert(std::string const &str)
{
	int type = get_type(str);

	switch (type)
	{
		case -1:
			PseudoLiteral(str);
			break ;
		case 0:
			std::cerr << "Error: empty string" << std::endl;
			break ;
		case 1:
			charLiteral(str);
			break ;
		case 2:
			floatLiteral(str);
			break ;
		case 3:
			doubleLiteral(str);
			break ;
		case 4:
			intLiteral(str);
			break ;
		default:
			std::cerr << "Error: invalid string" << std::endl;
			break ;
	}
}