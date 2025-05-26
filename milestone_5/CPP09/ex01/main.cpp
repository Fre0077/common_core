/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:23:28 by fre007            #+#    #+#             */
/*   Updated: 2025/05/26 11:59:16 by fre007           ###   ########.fr       */
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
	if (std::string(av[1]) == "empty")
	{
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}
}