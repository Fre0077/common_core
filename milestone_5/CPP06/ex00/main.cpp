/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:44:58 by francesco         #+#    #+#             */
/*   Updated: 2025/04/24 11:45:05 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main ( int ac , char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert [string]" << std::endl;
		return 1;
	}
	std::string str = av[1];
	ScalarConverter::convert(str);
}