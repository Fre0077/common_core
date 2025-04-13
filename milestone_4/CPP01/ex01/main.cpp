/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:58 by fre007            #+#    #+#             */
/*   Updated: 2025/04/12 20:15:39 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	std::string	name;
	int			num;
	Zombie*		horde;

	std::cout << "zombie name: ";
	getline(std::cin, name);
	if (std::cin.eof())
		return (0);
	std::cout << "moar zombie: ";
	std::cin >> num;
	std::cout << "Creating a horde on the heap:" << std::endl;
	horde = zombieHorde(num, name);
	for (int i = 0; i < num; i++)
		horde[i].announce();
	delete [] horde;
		std::cout << "The horde of  zombies has been eradicated." << std::endl;
	return (0);
}