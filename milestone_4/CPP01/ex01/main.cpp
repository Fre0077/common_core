/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:58 by fre007            #+#    #+#             */
/*   Updated: 2025/04/08 11:54:16 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main ()
{
	std::string	name;
	int			num;
	Zombie*		horde;

	std::cout << "zombie name: ";
	getline(std::cin, name);
	std::cout << "moar zombie: ";
	std::cin >> num;
	std::cout << "Creating a horde on the heap:" << std::endl;
	horde = zombieHorde(num, name);
	for (int i = 0; i < num; i++)
		horde[i].announce();
	return (0);
}