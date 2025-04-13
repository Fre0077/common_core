/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:58 by fre007            #+#    #+#             */
/*   Updated: 2025/04/12 20:08:46 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	std::string	name;
	Zombie*		zombie;

	std::cout << "zombie name: ";
	getline(std::cin, name);
	if (std::cin.eof())
		return (0);
    std::cout << "Creating a zombie on the heap:" << std::endl;
	zombie = newZombie(name);
	zombie->announce();
    delete zombie;
    std::cout << "Creating a zombie on the stack:" << std::endl;
	randomChump(name);
	return (0);
}