/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:58 by fre007            #+#    #+#             */
/*   Updated: 2025/04/02 17:01:04 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main ()
{
	std::string	name;
	Zombie*		zombie;

	std::cout << "zombie name: ";
	getline(std::cin, name);
    std::cout << "Creating a zombie on the heap:" << std::endl;
	zombie = newZombie(name);
	zombie->announce();
    delete zombie;
    std::cout << "Creating a zombie on the stack:" << std::endl;
	randomChump(name);
	return (0);
}