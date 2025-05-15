/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 07:56:35 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 09:11:53 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main ( void )
{
	Animal* j = new Cat();
	Animal* i = new Dog();

	j->makeSound();
	i->makeSound();
	delete j;
	delete i;


	Animal* meta = new Animal();
	Animal* jay = new Dog();
	Animal* ii = new Cat();
	std::cout << jay->getType() << " " << std::endl;
	std::cout << ii->getType() << " " << std::endl;
	ii->makeSound(); //will output the cat sound!
	jay->makeSound();
	meta->makeSound();

	delete meta;
	delete jay;
	delete ii;

	WrongCat* wcat = new WrongCat();
	wcat->makeSound();

	delete wcat;
	return 0;
}