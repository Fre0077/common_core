/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:40:05 by fre007            #+#    #+#             */
/*   Updated: 2025/04/12 20:37:05 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char* av[])
{
	if (ac != 2)
		return (std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 0);
	Harl	harl;
	
	harl.complain(av[1]);
	return 0;
}

