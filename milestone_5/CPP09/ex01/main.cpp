/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:23:28 by fre007            #+#    #+#             */
/*   Updated: 2025/05/30 18:48:50 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN [filename]" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn(av[1]);
		rpn.calculate();
		std::cout << rpn.getNum() << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
	}
	return 0;
}