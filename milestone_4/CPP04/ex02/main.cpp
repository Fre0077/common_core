/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 07:56:35 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/16 14:04:27 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main ( void )
{
	Animal *dog = new Dog();
	Animal *cat = new Cat();
	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;
	return 0;
}