/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 07:56:35 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 10:31:36 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main ( void )
{
	Animal *animals[6];

	for (int i = 0; i < 3; i++) {
		animals[i] = new Dog();	}

	for (int i = 3; i < 6; i++) {
		animals[i] = new Cat();  }

	for (int i = 0; i < 6; i++) {
		delete animals[i];       }

	Dog Basic;

	std::cout << "Basic type: " << Basic.getType() << std::endl;
	{
		Dog tmp = Basic;
	}

	return 0;
}